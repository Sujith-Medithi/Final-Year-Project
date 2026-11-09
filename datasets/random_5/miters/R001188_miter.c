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
struct MatrixBlock_R001188_8813_0
{
  unsigned char stride;
  int trace;
  unsigned char determinant;
  int dim;
  short density;
  int buffer[3];
};
struct SensorNode_R001188_8813_1
{
  int threshold;
  short status;
  unsigned char reading;
  int gain;
  int offset;
  int buffer[3];
};
union RegisterBank_R001188_8813_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R001188_8813_1
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
void fn_R001188_8813_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st_1 = {0};
  struct MatrixBlock_R001188_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int threshold_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_20_1 > 23)
  {
    acc_1 = ((acc_1 + (threshold_20_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_20_2 > 23)
  {
    acc_2 = ((acc_2 + (threshold_20_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_43_1 = local_arr_1[aux_1 % 3];
  int window_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_43_2 * 2)) & 127;
  int margin_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_45_1) & 63;
  aux_2 = (aux_2 + margin_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_20_1 == threshold_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_43_1 == window_43_2);
  assert(margin_45_1 == margin_45_2);
}

int fn_R001188_8813_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int threshold_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_20 > 23)
  {
    acc = ((acc + (threshold_20 * 2)) + 5) & 127;
    aux ^= threshold_20 & 15;
  }
  else
  {
    acc = ((acc - threshold_20) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_43 = local_arr[aux % 3];
  acc = (acc + (window_43 * 2)) & 127;
  int margin_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_45) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001188_8813_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st_1 = {0};
  struct MatrixBlock_R001188_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int factor_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_57_1) & 63;
  aux_2 = (aux_2 + factor_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
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
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_57_1 == factor_57_2);
}

int fn_R001188_8813_1(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int factor_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_57) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001188_8813_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st_1 = {0};
  struct SensorNode_R001188_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int tracker_34_1 = 0;
  int tracker_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_34_1 = ((tracker_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_34_2 = ((tracker_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_34_1) & 127;
    acc_2 = (acc_2 + tracker_34_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_87_1 = local_arr_1[aux_1 % 3];
  int damping_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_87_2 * 2)) & 127;
  int window_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_35_1)
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

  switch (window_35_2)
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

  int anchor_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_54_1) & 63;
  aux_2 = (aux_2 + anchor_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_34_1 == tracker_34_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_87_1 == damping_87_2);
  assert(window_35_1 == window_35_2);
  assert(anchor_54_1 == anchor_54_2);
}

int fn_R001188_8813_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int tracker_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_34 = ((tracker_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_34) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int damping_87 = local_arr[aux % 3];
  acc = (acc + (damping_87 * 2)) & 127;
  int window_35 = (aux + st.buffer[1]) & 3;
  switch (window_35)
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

  int anchor_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_54) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001188_8813_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st_1 = {0};
  struct MatrixBlock_R001188_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int residue_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_87_1) & 63;
  aux_2 = (aux_2 + residue_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_83_1 = local_arr_1[aux_1 % 3];
  int residue_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_83_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_79_1)
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

  switch (phase_79_2)
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
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_87_1 == residue_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_83_1 == residue_83_2);
  assert(phase_79_1 == phase_79_2);
}

int fn_R001188_8813_3(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int residue_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_87) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int residue_83 = local_arr[aux % 3];
  acc = (acc + (residue_83 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_79 = (aux + st.buffer[1]) & 3;
  switch (phase_79)
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

void fn_R001188_8813_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st_1 = {0};
  struct MatrixBlock_R001188_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int threshold_69_1 = 0;
  int threshold_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_69_1 = ((threshold_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_69_2 = ((threshold_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_69_1) & 127;
    acc_2 = (acc_2 + threshold_69_2) & 127;
  }

  int threshold_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_59_1) & 63;
  aux_2 = (aux_2 + threshold_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_38_1 > 49)
  {
    acc_1 = ((acc_1 + (mask_38_1 * 2)) + 5) & 127;
    aux_1 ^= mask_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_38_2 > 49)
  {
    acc_2 = ((acc_2 + (mask_38_2 * 2)) + 5) & 127;
    aux_2 ^= mask_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_38_2) + 11) & 127;
    aux_2 += 3;
  }
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
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_69_1 == threshold_69_2);
  assert(threshold_59_1 == threshold_59_2);
  assert(mask_38_1 == mask_38_2);
}

int fn_R001188_8813_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int threshold_69 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_69 = ((threshold_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_69) & 127;
  }

  int threshold_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_59) & 63;
  acc ^= aux;
  int mask_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_38 > 49)
  {
    acc = ((acc + (mask_38 * 2)) + 5) & 127;
    aux ^= mask_38 & 15;
  }
  else
  {
    acc = ((acc - mask_38) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001188_8813_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st_1 = {0};
  struct SensorNode_R001188_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int checksum_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_10_1) & 63;
  aux_2 = (aux_2 + checksum_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_94_1 > 32)
  {
    acc_1 = ((acc_1 + (offset_94_1 * 2)) + 5) & 127;
    aux_1 ^= offset_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_94_2 > 32)
  {
    acc_2 = ((acc_2 + (offset_94_2 * 2)) + 5) & 127;
    aux_2 ^= offset_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_94_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_10_1 == checksum_10_2);
  assert(offset_94_1 == offset_94_2);
}

int fn_R001188_8813_5(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int checksum_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_10) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_94 > 32)
  {
    acc = ((acc + (offset_94 * 2)) + 5) & 127;
    aux ^= offset_94 & 15;
  }
  else
  {
    acc = ((acc - offset_94) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001188_8813_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st_1 = {0};
  struct SensorNode_R001188_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int segment_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_86_1) & 63;
  aux_2 = (aux_2 + segment_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_68_1 = local_arr_1[aux_1 % 3];
  int cursor_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_86_1 == segment_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_68_1 == cursor_68_2);
}

int fn_R001188_8813_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int segment_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_86) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_68 = local_arr[aux % 3];
  acc = (acc + (cursor_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001188_8813_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st_1 = {0};
  struct SensorNode_R001188_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int sample_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_49_1) & 63;
  aux_2 = (aux_2 + sample_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_98_1 > 50)
  {
    acc_1 = ((acc_1 + (metric_98_1 * 2)) + 5) & 127;
    aux_1 ^= metric_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_98_2 > 50)
  {
    acc_2 = ((acc_2 + (metric_98_2 * 2)) + 5) & 127;
    aux_2 ^= metric_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_98_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_74_1 = local_arr_1[aux_1 % 3];
  int threshold_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_74_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_49_1 == sample_49_2);
  assert(metric_98_1 == metric_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_74_1 == threshold_74_2);
}

int fn_R001188_8813_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int sample_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_49) & 63;
  acc ^= aux;
  int metric_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_98 > 50)
  {
    acc = ((acc + (metric_98 * 2)) + 5) & 127;
    aux ^= metric_98 & 15;
  }
  else
  {
    acc = ((acc - metric_98) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int threshold_74 = local_arr[aux % 3];
  acc = (acc + (threshold_74 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001188_8813_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st_1 = {0};
  struct SensorNode_R001188_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int quantum_30_1 = 0;
  int quantum_30_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_30_1 = ((quantum_30_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_30_2 = ((quantum_30_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_30_1) & 127;
    acc_2 = (acc_2 + quantum_30_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_47_1 = local_arr_1[aux_1 % 3];
  int tracker_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_47_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_30_1 == quantum_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_47_1 == tracker_47_2);
}

int fn_R001188_8813_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int quantum_30 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_30 = ((quantum_30 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_30) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tracker_47 = local_arr[aux % 3];
  acc = (acc + (tracker_47 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001188_8813_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st_1 = {0};
  struct SensorNode_R001188_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int accumulator_77_1 = 0;
  int accumulator_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_77_1 = ((accumulator_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_77_2 = ((accumulator_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_77_1) & 127;
    acc_2 = (acc_2 + accumulator_77_2) & 127;
  }

  int tracker_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_59_1 > 18)
  {
    acc_1 = ((acc_1 + (tracker_59_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_59_2 > 18)
  {
    acc_2 = ((acc_2 + (tracker_59_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_77_1 == accumulator_77_2);
  assert(tracker_59_1 == tracker_59_2);
}

int fn_R001188_8813_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int accumulator_77 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_77 = ((accumulator_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_77) & 127;
  }

  int tracker_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_59 > 18)
  {
    acc = ((acc + (tracker_59 * 2)) + 5) & 127;
    aux ^= tracker_59 & 15;
  }
  else
  {
    acc = ((acc - tracker_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001188_8813_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st_1 = {0};
  struct SensorNode_R001188_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int quantum_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_16_1) & 63;
  aux_2 = (aux_2 + quantum_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_45_1)
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

  switch (offset_45_2)
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

  int damping_57_1 = 0;
  int damping_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_57_1 = ((damping_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_57_2 = ((damping_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_57_1) & 127;
    acc_2 = (acc_2 + damping_57_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_16_1 == quantum_16_2);
  assert(offset_45_1 == offset_45_2);
  assert(damping_57_1 == damping_57_2);
}

int fn_R001188_8813_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int quantum_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_16) & 63;
  acc ^= aux;
  int offset_45 = (aux + st.buffer[1]) & 3;
  switch (offset_45)
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

  int damping_57 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_57 = ((damping_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_57) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001188_8813_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st_1 = {0};
  struct SensorNode_R001188_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_81_1 > 15)
  {
    acc_1 = ((acc_1 + (checksum_81_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_81_2 > 15)
  {
    acc_2 = ((acc_2 + (checksum_81_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_81_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_33_1) & 63;
  aux_2 = (aux_2 + vector_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_11_1 = 0;
  int residue_11_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_11_1 = ((residue_11_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_11_2 = ((residue_11_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_11_1) & 127;
    acc_2 = (acc_2 + residue_11_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_81_1 == checksum_81_2);
  assert(vector_33_1 == vector_33_2);
  assert(residue_11_1 == residue_11_2);
}

int fn_R001188_8813_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_81 > 15)
  {
    acc = ((acc + (checksum_81 * 2)) + 5) & 127;
    aux ^= checksum_81 & 15;
  }
  else
  {
    acc = ((acc - checksum_81) + 11) & 127;
    aux += 3;
  }
  int vector_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_33) & 63;
  acc ^= aux;
  int residue_11 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_11 = ((residue_11 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_11) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001188_8813_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st_1 = {0};
  struct SensorNode_R001188_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int phase_56_1 = 0;
  int phase_56_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_56_1 = ((phase_56_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_56_2 = ((phase_56_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_56_1) & 127;
    acc_2 = (acc_2 + phase_56_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_56_1 == phase_56_2);
}

int fn_R001188_8813_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int phase_56 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_56 = ((phase_56 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_56) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001188_8813_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st_1 = {0};
  struct MatrixBlock_R001188_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int damping_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_76_1 > 41)
  {
    acc_1 = ((acc_1 + (damping_76_1 * 2)) + 5) & 127;
    aux_1 ^= damping_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_76_2 > 41)
  {
    acc_2 = ((acc_2 + (damping_76_2 * 2)) + 5) & 127;
    aux_2 ^= damping_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_55_1)
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

  switch (scale_55_2)
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
  int offset_22_1 = local_arr_1[aux_1 % 3];
  int offset_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_22_2 * 2)) & 127;
  int margin_26_1 = 0;
  int margin_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_26_1 = ((margin_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_26_2 = ((margin_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_26_1) & 127;
    acc_2 = (acc_2 + margin_26_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_76_1 == damping_76_2);
  assert(scale_55_1 == scale_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_22_1 == offset_22_2);
  assert(margin_26_1 == margin_26_2);
}

int fn_R001188_8813_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int damping_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_76 > 41)
  {
    acc = ((acc + (damping_76 * 2)) + 5) & 127;
    aux ^= damping_76 & 15;
  }
  else
  {
    acc = ((acc - damping_76) + 11) & 127;
    aux += 3;
  }
  int scale_55 = (aux + st.buffer[1]) & 3;
  switch (scale_55)
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
  int offset_22 = local_arr[aux % 3];
  acc = (acc + (offset_22 * 2)) & 127;
  int margin_26 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_26 = ((margin_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_26) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001188_8813_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st_1 = {0};
  struct MatrixBlock_R001188_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int accumulator_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_41_1)
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

  switch (accumulator_41_2)
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

  int tally_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_32_1 > 47)
  {
    acc_1 = ((acc_1 + (tally_32_1 * 2)) + 5) & 127;
    aux_1 ^= tally_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_32_2 > 47)
  {
    acc_2 = ((acc_2 + (tally_32_2 * 2)) + 5) & 127;
    aux_2 ^= tally_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_32_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_41_1 == accumulator_41_2);
  assert(tally_32_1 == tally_32_2);
}

int fn_R001188_8813_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int accumulator_41 = (aux + st.buffer[1]) & 3;
  switch (accumulator_41)
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

  int tally_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_32 > 47)
  {
    acc = ((acc + (tally_32 * 2)) + 5) & 127;
    aux ^= tally_32 & 15;
  }
  else
  {
    acc = ((acc - tally_32) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001188_8813_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st_1 = {0};
  struct MatrixBlock_R001188_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int checksum_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_40_1 > 23)
  {
    acc_1 = ((acc_1 + (checksum_40_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_40_2 > 23)
  {
    acc_2 = ((acc_2 + (checksum_40_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_52_1)
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

  switch (index_reg_52_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_40_1 == checksum_40_2);
  assert(index_reg_52_1 == index_reg_52_2);
}

int fn_R001188_8813_15(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int checksum_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_40 > 23)
  {
    acc = ((acc + (checksum_40 * 2)) + 5) & 127;
    aux ^= checksum_40 & 15;
  }
  else
  {
    acc = ((acc - checksum_40) + 11) & 127;
    aux += 3;
  }
  int index_reg_52 = (aux + st.buffer[1]) & 3;
  switch (index_reg_52)
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

void fn_R001188_8813_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st_1 = {0};
  struct SensorNode_R001188_8813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_42_1 = local_arr_1[aux_1 % 3];
  int segment_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_42_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_18_1 > 38)
  {
    acc_1 = ((acc_1 + (pivot_18_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_18_2 > 38)
  {
    acc_2 = ((acc_2 + (pivot_18_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_29_1)
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

  switch (coefficient_29_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_42_1 == segment_42_2);
  assert(pivot_18_1 == pivot_18_2);
  assert(coefficient_29_1 == coefficient_29_2);
}

int fn_R001188_8813_16(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001188_8813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int segment_42 = local_arr[aux % 3];
  acc = (acc + (segment_42 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_18 > 38)
  {
    acc = ((acc + (pivot_18 * 2)) + 5) & 127;
    aux ^= pivot_18 & 15;
  }
  else
  {
    acc = ((acc - pivot_18) + 11) & 127;
    aux += 3;
  }
  int coefficient_29 = (aux + st.buffer[1]) & 3;
  switch (coefficient_29)
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

void fn_R001188_8813_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st_1 = {0};
  struct MatrixBlock_R001188_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_23_1 = local_arr_1[aux_1 % 3];
  int residue_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_23_2 * 2)) & 127;
  int weight_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_98_1) & 63;
  aux_2 = (aux_2 + weight_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_23_1 == residue_23_2);
  assert(weight_98_1 == weight_98_2);
}

int fn_R001188_8813_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_23 = local_arr[aux % 3];
  acc = (acc + (residue_23 * 2)) & 127;
  int weight_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_98) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001188_8813_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st_1 = {0};
  struct MatrixBlock_R001188_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_89_1 = local_arr_1[aux_1 % 3];
  int metric_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_89_2 * 2)) & 127;
  int phase_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_52_1 > 45)
  {
    acc_1 = ((acc_1 + (phase_52_1 * 2)) + 5) & 127;
    aux_1 ^= phase_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_52_2 > 45)
  {
    acc_2 = ((acc_2 + (phase_52_2 * 2)) + 5) & 127;
    aux_2 ^= phase_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_52_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_89_1 == metric_89_2);
  assert(phase_52_1 == phase_52_2);
}

int fn_R001188_8813_18(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_89 = local_arr[aux % 3];
  acc = (acc + (metric_89 * 2)) & 127;
  int phase_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_52 > 45)
  {
    acc = ((acc + (phase_52 * 2)) + 5) & 127;
    aux ^= phase_52 & 15;
  }
  else
  {
    acc = ((acc - phase_52) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001188_8813_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st_1 = {0};
  struct MatrixBlock_R001188_8813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int weight_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_34_1)
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

  switch (weight_34_2)
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

  int window_21_1 = 0;
  int window_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_21_1 = ((window_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_21_2 = ((window_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_21_1) & 127;
    acc_2 = (acc_2 + window_21_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_34_1 == weight_34_2);
  assert(window_21_1 == window_21_2);
}

int fn_R001188_8813_19(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001188_8813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int weight_34 = (aux + st.buffer[1]) & 3;
  switch (weight_34)
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

  int window_21 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_21 = ((window_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_21) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001188_0_1;
  int sec_r001188_0_2;
  int sec_r001188_1_1;
  int sec_r001188_1_2;
  int sec_r001188_2_1;
  int sec_r001188_2_2;
  int sec_r001188_3_1;
  int sec_r001188_3_2;
  int sec_r001188_4_1;
  int sec_r001188_4_2;
  int sec_r001188_5_1;
  int sec_r001188_5_2;
  int sec_r001188_6_1;
  int sec_r001188_6_2;
  int sec_r001188_7_1;
  int sec_r001188_7_2;
  int sec_r001188_8_1;
  int sec_r001188_8_2;
  int sec_r001188_9_1;
  int sec_r001188_9_2;
  int sec_r001188_10_1;
  int sec_r001188_10_2;
  int sec_r001188_11_1;
  int sec_r001188_11_2;
  int sec_r001188_12_1;
  int sec_r001188_12_2;
  int sec_r001188_13_1;
  int sec_r001188_13_2;
  int sec_r001188_14_1;
  int sec_r001188_14_2;
  int sec_r001188_15_1;
  int sec_r001188_15_2;
  int sec_r001188_16_1;
  int sec_r001188_16_2;
  int sec_r001188_17_1;
  int sec_r001188_17_2;
  int sec_r001188_18_1;
  int sec_r001188_18_2;
  int sec_r001188_19_1;
  int sec_r001188_19_2;
  int sec_r001188_20_1;
  int sec_r001188_20_2;
  int pub_r001188_0_1;
  int pub_r001188_0_2;
  int pub_r001188_1_1;
  int pub_r001188_1_2;
  int pub_r001188_2_1;
  int pub_r001188_2_2;
  int pub_r001188_3_1;
  int pub_r001188_3_2;
  int pub_r001188_4_1;
  int pub_r001188_4_2;
  int pub_r001188_5_1;
  int pub_r001188_5_2;
  int pub_r001188_6_1;
  int pub_r001188_6_2;
  int pub_r001188_7_1;
  int pub_r001188_7_2;
  int pub_r001188_8_1;
  int pub_r001188_8_2;
  int pub_r001188_9_1;
  int pub_r001188_9_2;
  int pub_r001188_10_1;
  int pub_r001188_10_2;
  int pub_r001188_11_1;
  int pub_r001188_11_2;
  int pub_r001188_12_1;
  int pub_r001188_12_2;
  int pub_r001188_13_1;
  int pub_r001188_13_2;
  int pub_r001188_14_1;
  int pub_r001188_14_2;
  int pub_r001188_15_1;
  int pub_r001188_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001188_0_1 >= (-100)) && (pub_r001188_0_1 <= 100));
  __CPROVER_assume((pub_r001188_0_2 >= (-100)) && (pub_r001188_0_2 <= 100));
  __CPROVER_assume((pub_r001188_1_1 >= (-100)) && (pub_r001188_1_1 <= 100));
  __CPROVER_assume((pub_r001188_1_2 >= (-100)) && (pub_r001188_1_2 <= 100));
  __CPROVER_assume((pub_r001188_2_1 >= (-100)) && (pub_r001188_2_1 <= 100));
  __CPROVER_assume((pub_r001188_2_2 >= (-100)) && (pub_r001188_2_2 <= 100));
  __CPROVER_assume((pub_r001188_3_1 >= (-100)) && (pub_r001188_3_1 <= 100));
  __CPROVER_assume((pub_r001188_3_2 >= (-100)) && (pub_r001188_3_2 <= 100));
  __CPROVER_assume((pub_r001188_4_1 >= (-100)) && (pub_r001188_4_1 <= 100));
  __CPROVER_assume((pub_r001188_4_2 >= (-100)) && (pub_r001188_4_2 <= 100));
  __CPROVER_assume((pub_r001188_5_1 >= (-100)) && (pub_r001188_5_1 <= 100));
  __CPROVER_assume((pub_r001188_5_2 >= (-100)) && (pub_r001188_5_2 <= 100));
  __CPROVER_assume((pub_r001188_6_1 >= (-100)) && (pub_r001188_6_1 <= 100));
  __CPROVER_assume((pub_r001188_6_2 >= (-100)) && (pub_r001188_6_2 <= 100));
  __CPROVER_assume((pub_r001188_7_1 >= (-100)) && (pub_r001188_7_1 <= 100));
  __CPROVER_assume((pub_r001188_7_2 >= (-100)) && (pub_r001188_7_2 <= 100));
  __CPROVER_assume((pub_r001188_8_1 >= (-100)) && (pub_r001188_8_1 <= 100));
  __CPROVER_assume((pub_r001188_8_2 >= (-100)) && (pub_r001188_8_2 <= 100));
  __CPROVER_assume((pub_r001188_9_1 >= (-100)) && (pub_r001188_9_1 <= 100));
  __CPROVER_assume((pub_r001188_9_2 >= (-100)) && (pub_r001188_9_2 <= 100));
  __CPROVER_assume((pub_r001188_10_1 >= (-100)) && (pub_r001188_10_1 <= 100));
  __CPROVER_assume((pub_r001188_10_2 >= (-100)) && (pub_r001188_10_2 <= 100));
  __CPROVER_assume((pub_r001188_11_1 >= (-100)) && (pub_r001188_11_1 <= 100));
  __CPROVER_assume((pub_r001188_11_2 >= (-100)) && (pub_r001188_11_2 <= 100));
  __CPROVER_assume((pub_r001188_12_1 >= (-100)) && (pub_r001188_12_1 <= 100));
  __CPROVER_assume((pub_r001188_12_2 >= (-100)) && (pub_r001188_12_2 <= 100));
  __CPROVER_assume((pub_r001188_13_1 >= (-100)) && (pub_r001188_13_1 <= 100));
  __CPROVER_assume((pub_r001188_13_2 >= (-100)) && (pub_r001188_13_2 <= 100));
  __CPROVER_assume((pub_r001188_14_1 >= (-100)) && (pub_r001188_14_1 <= 100));
  __CPROVER_assume((pub_r001188_14_2 >= (-100)) && (pub_r001188_14_2 <= 100));
  __CPROVER_assume((pub_r001188_15_1 >= (-100)) && (pub_r001188_15_1 <= 100));
  __CPROVER_assume((pub_r001188_15_2 >= (-100)) && (pub_r001188_15_2 <= 100));
  __CPROVER_assume((sec_r001188_0_1 >= 0) && (sec_r001188_0_1 <= 255));
  __CPROVER_assume((sec_r001188_0_2 >= 0) && (sec_r001188_0_2 <= 255));
  __CPROVER_assume((sec_r001188_1_1 >= 0) && (sec_r001188_1_1 <= 255));
  __CPROVER_assume((sec_r001188_1_2 >= 0) && (sec_r001188_1_2 <= 255));
  __CPROVER_assume((sec_r001188_2_1 >= 0) && (sec_r001188_2_1 <= 255));
  __CPROVER_assume((sec_r001188_2_2 >= 0) && (sec_r001188_2_2 <= 255));
  __CPROVER_assume((sec_r001188_3_1 >= 0) && (sec_r001188_3_1 <= 255));
  __CPROVER_assume((sec_r001188_3_2 >= 0) && (sec_r001188_3_2 <= 255));
  __CPROVER_assume((sec_r001188_4_1 >= 0) && (sec_r001188_4_1 <= 255));
  __CPROVER_assume((sec_r001188_4_2 >= 0) && (sec_r001188_4_2 <= 255));
  __CPROVER_assume((sec_r001188_5_1 >= 0) && (sec_r001188_5_1 <= 255));
  __CPROVER_assume((sec_r001188_5_2 >= 0) && (sec_r001188_5_2 <= 255));
  __CPROVER_assume((sec_r001188_6_1 >= 0) && (sec_r001188_6_1 <= 255));
  __CPROVER_assume((sec_r001188_6_2 >= 0) && (sec_r001188_6_2 <= 255));
  __CPROVER_assume((sec_r001188_7_1 >= 0) && (sec_r001188_7_1 <= 255));
  __CPROVER_assume((sec_r001188_7_2 >= 0) && (sec_r001188_7_2 <= 255));
  __CPROVER_assume((sec_r001188_8_1 >= 0) && (sec_r001188_8_1 <= 255));
  __CPROVER_assume((sec_r001188_8_2 >= 0) && (sec_r001188_8_2 <= 255));
  __CPROVER_assume((sec_r001188_9_1 >= 0) && (sec_r001188_9_1 <= 255));
  __CPROVER_assume((sec_r001188_9_2 >= 0) && (sec_r001188_9_2 <= 255));
  __CPROVER_assume((sec_r001188_10_1 >= 0) && (sec_r001188_10_1 <= 255));
  __CPROVER_assume((sec_r001188_10_2 >= 0) && (sec_r001188_10_2 <= 255));
  __CPROVER_assume((sec_r001188_11_1 >= 0) && (sec_r001188_11_1 <= 255));
  __CPROVER_assume((sec_r001188_11_2 >= 0) && (sec_r001188_11_2 <= 255));
  __CPROVER_assume((sec_r001188_12_1 >= 0) && (sec_r001188_12_1 <= 255));
  __CPROVER_assume((sec_r001188_12_2 >= 0) && (sec_r001188_12_2 <= 255));
  __CPROVER_assume((sec_r001188_13_1 >= 0) && (sec_r001188_13_1 <= 255));
  __CPROVER_assume((sec_r001188_13_2 >= 0) && (sec_r001188_13_2 <= 255));
  __CPROVER_assume((sec_r001188_14_1 >= 0) && (sec_r001188_14_1 <= 255));
  __CPROVER_assume((sec_r001188_14_2 >= 0) && (sec_r001188_14_2 <= 255));
  __CPROVER_assume((sec_r001188_15_1 >= 0) && (sec_r001188_15_1 <= 255));
  __CPROVER_assume((sec_r001188_15_2 >= 0) && (sec_r001188_15_2 <= 255));
  __CPROVER_assume((sec_r001188_16_1 >= 0) && (sec_r001188_16_1 <= 255));
  __CPROVER_assume((sec_r001188_16_2 >= 0) && (sec_r001188_16_2 <= 255));
  __CPROVER_assume((sec_r001188_17_1 >= 0) && (sec_r001188_17_1 <= 255));
  __CPROVER_assume((sec_r001188_17_2 >= 0) && (sec_r001188_17_2 <= 255));
  __CPROVER_assume((sec_r001188_18_1 >= 0) && (sec_r001188_18_1 <= 255));
  __CPROVER_assume((sec_r001188_18_2 >= 0) && (sec_r001188_18_2 <= 255));
  __CPROVER_assume((sec_r001188_19_1 >= 0) && (sec_r001188_19_1 <= 255));
  __CPROVER_assume((sec_r001188_19_2 >= 0) && (sec_r001188_19_2 <= 255));
  __CPROVER_assume((sec_r001188_20_1 >= 0) && (sec_r001188_20_1 <= 255));
  __CPROVER_assume((sec_r001188_20_2 >= 0) && (sec_r001188_20_2 <= 255));
  struct MatrixBlock_R001188_8813_0 st_var_0_1 = {0};
  struct MatrixBlock_R001188_8813_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001188_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001188_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001188_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001188_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001188_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001188_0_2 + 7) & 15;
  struct SensorNode_R001188_8813_1 st_var_1_1 = {0};
  struct SensorNode_R001188_8813_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001188_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001188_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001188_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001188_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001188_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001188_0_2 + 9) & 15;
  union RegisterBank_R001188_8813_0 u_var_1;
  union RegisterBank_R001188_8813_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001188_8813_0(sec_r001188_0_1, sec_r001188_1_1, pub_r001188_2_1, pub_r001188_3_1);
  int helper_flow_0_2 = fn_R001188_8813_0(sec_r001188_0_2, sec_r001188_1_2, pub_r001188_2_2, pub_r001188_3_2);
  fn_R001188_8813_0_2(sec_r001188_0_1, sec_r001188_1_1, pub_r001188_2_1, pub_r001188_3_1, sec_r001188_0_2, sec_r001188_1_2, pub_r001188_2_2, pub_r001188_3_2);
  int helper_flow_1_1 = fn_R001188_8813_1(sec_r001188_1_1, pub_r001188_2_1);
  int helper_flow_1_2 = fn_R001188_8813_1(sec_r001188_1_2, pub_r001188_2_2);
  fn_R001188_8813_1_2(sec_r001188_1_1, pub_r001188_2_1, sec_r001188_1_2, pub_r001188_2_2);
  int helper_flow_2_1 = fn_R001188_8813_2(sec_r001188_2_1, pub_r001188_3_1, pub_r001188_4_1, pub_r001188_5_1);
  int helper_flow_2_2 = fn_R001188_8813_2(sec_r001188_2_2, pub_r001188_3_2, pub_r001188_4_2, pub_r001188_5_2);
  fn_R001188_8813_2_2(sec_r001188_2_1, pub_r001188_3_1, pub_r001188_4_1, pub_r001188_5_1, sec_r001188_2_2, pub_r001188_3_2, pub_r001188_4_2, pub_r001188_5_2);
  int helper_flow_3_1 = fn_R001188_8813_3(sec_r001188_3_1, sec_r001188_4_1, pub_r001188_5_1);
  int helper_flow_3_2 = fn_R001188_8813_3(sec_r001188_3_2, sec_r001188_4_2, pub_r001188_5_2);
  fn_R001188_8813_3_2(sec_r001188_3_1, sec_r001188_4_1, pub_r001188_5_1, sec_r001188_3_2, sec_r001188_4_2, pub_r001188_5_2);
  int helper_flow_4_1 = fn_R001188_8813_4(sec_r001188_4_1, pub_r001188_5_1, pub_r001188_6_1, pub_r001188_7_1);
  int helper_flow_4_2 = fn_R001188_8813_4(sec_r001188_4_2, pub_r001188_5_2, pub_r001188_6_2, pub_r001188_7_2);
  fn_R001188_8813_4_2(sec_r001188_4_1, pub_r001188_5_1, pub_r001188_6_1, pub_r001188_7_1, sec_r001188_4_2, pub_r001188_5_2, pub_r001188_6_2, pub_r001188_7_2);
  int helper_flow_5_1 = fn_R001188_8813_5(sec_r001188_5_1, pub_r001188_6_1);
  int helper_flow_5_2 = fn_R001188_8813_5(sec_r001188_5_2, pub_r001188_6_2);
  fn_R001188_8813_5_2(sec_r001188_5_1, pub_r001188_6_1, sec_r001188_5_2, pub_r001188_6_2);
  int helper_flow_6_1 = fn_R001188_8813_6(sec_r001188_6_1, pub_r001188_7_1, pub_r001188_8_1, pub_r001188_9_1, pub_r001188_10_1);
  int helper_flow_6_2 = fn_R001188_8813_6(sec_r001188_6_2, pub_r001188_7_2, pub_r001188_8_2, pub_r001188_9_2, pub_r001188_10_2);
  fn_R001188_8813_6_2(sec_r001188_6_1, pub_r001188_7_1, pub_r001188_8_1, pub_r001188_9_1, pub_r001188_10_1, sec_r001188_6_2, pub_r001188_7_2, pub_r001188_8_2, pub_r001188_9_2, pub_r001188_10_2);
  int helper_flow_7_1 = fn_R001188_8813_7(sec_r001188_7_1, pub_r001188_8_1, pub_r001188_9_1, pub_r001188_10_1, pub_r001188_11_1);
  int helper_flow_7_2 = fn_R001188_8813_7(sec_r001188_7_2, pub_r001188_8_2, pub_r001188_9_2, pub_r001188_10_2, pub_r001188_11_2);
  fn_R001188_8813_7_2(sec_r001188_7_1, pub_r001188_8_1, pub_r001188_9_1, pub_r001188_10_1, pub_r001188_11_1, sec_r001188_7_2, pub_r001188_8_2, pub_r001188_9_2, pub_r001188_10_2, pub_r001188_11_2);
  int helper_flow_8_1 = fn_R001188_8813_8(sec_r001188_8_1, sec_r001188_9_1, pub_r001188_10_1, pub_r001188_11_1);
  int helper_flow_8_2 = fn_R001188_8813_8(sec_r001188_8_2, sec_r001188_9_2, pub_r001188_10_2, pub_r001188_11_2);
  fn_R001188_8813_8_2(sec_r001188_8_1, sec_r001188_9_1, pub_r001188_10_1, pub_r001188_11_1, sec_r001188_8_2, sec_r001188_9_2, pub_r001188_10_2, pub_r001188_11_2);
  int helper_flow_9_1 = fn_R001188_8813_9(sec_r001188_9_1, sec_r001188_10_1, pub_r001188_11_1, pub_r001188_12_1);
  int helper_flow_9_2 = fn_R001188_8813_9(sec_r001188_9_2, sec_r001188_10_2, pub_r001188_11_2, pub_r001188_12_2);
  fn_R001188_8813_9_2(sec_r001188_9_1, sec_r001188_10_1, pub_r001188_11_1, pub_r001188_12_1, sec_r001188_9_2, sec_r001188_10_2, pub_r001188_11_2, pub_r001188_12_2);
  int helper_flow_10_1 = fn_R001188_8813_10(sec_r001188_10_1, sec_r001188_11_1, pub_r001188_12_1, pub_r001188_13_1, pub_r001188_14_1);
  int helper_flow_10_2 = fn_R001188_8813_10(sec_r001188_10_2, sec_r001188_11_2, pub_r001188_12_2, pub_r001188_13_2, pub_r001188_14_2);
  fn_R001188_8813_10_2(sec_r001188_10_1, sec_r001188_11_1, pub_r001188_12_1, pub_r001188_13_1, pub_r001188_14_1, sec_r001188_10_2, sec_r001188_11_2, pub_r001188_12_2, pub_r001188_13_2, pub_r001188_14_2);
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (it_1 * 3)) + (sec_r001188_15_1 & 15)) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (it_2 * 3)) + (sec_r001188_15_2 & 15)) & 63;
    if ((sec_r001188_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_0_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_0_1) + 7) & 255;
    }
    if ((sec_r001188_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_0_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_0_2) + 7) & 255;
    }
  }

  int stage_v_1_1 = 0;
  int stage_v_1_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_1_1 = ((stage_v_1_1 + (it_1 * 3)) + (sec_r001188_5_1 & 15)) & 63;
    stage_v_1_2 = ((stage_v_1_2 + (it_2 * 3)) + (sec_r001188_5_2 & 15)) & 63;
    if ((sec_r001188_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_1_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_1_1) + 7) & 255;
    }
    if ((sec_r001188_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_1_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_1_2) + 7) & 255;
    }
  }

  int stage_v_2_1 = 0;
  int stage_v_2_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_2_1 = ((stage_v_2_1 + (it_1 * 3)) + (sec_r001188_5_1 & 15)) & 63;
    stage_v_2_2 = ((stage_v_2_2 + (it_2 * 3)) + (sec_r001188_5_2 & 15)) & 63;
    if ((sec_r001188_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_2_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_2_1) + 7) & 255;
    }
    if ((sec_r001188_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_2_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_2_2) + 7) & 255;
    }
  }

  int stage_v_3_1 = 0;
  int stage_v_3_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_3_1 = ((stage_v_3_1 + (it_1 * 3)) + (sec_r001188_15_1 & 15)) & 63;
    stage_v_3_2 = ((stage_v_3_2 + (it_2 * 3)) + (sec_r001188_15_2 & 15)) & 63;
    if ((sec_r001188_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_3_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_3_1) + 7) & 255;
    }
    if ((sec_r001188_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_3_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_3_2) + 7) & 255;
    }
  }

  int stage_v_4_1 = ((pub_r001188_14_1 * 2) + 6) & 63;
  int stage_v_4_2 = ((pub_r001188_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001188_5_1 * 2) + 40) & 63;
  int stage_v_5_2 = ((pub_r001188_5_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_6_1 = ((stage_v_6_1 + (it_1 * 3)) + (sec_r001188_8_1 & 15)) & 63;
    stage_v_6_2 = ((stage_v_6_2 + (it_2 * 3)) + (sec_r001188_8_2 & 15)) & 63;
    if ((sec_r001188_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_6_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_6_1) + 7) & 255;
    }
    if ((sec_r001188_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_6_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_6_2) + 7) & 255;
    }
  }

  int stage_v_7_1 = ((pub_r001188_11_1 * 2) + 49) & 63;
  int stage_v_7_2 = ((pub_r001188_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001188_8_1 * 2) + 16) & 63;
  int stage_v_8_2 = ((pub_r001188_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_9_1 = ((stage_v_9_1 + (it_1 * 3)) + (stage_v_3_1 & 15)) & 63;
    stage_v_9_2 = ((stage_v_9_2 + (it_2 * 3)) + (stage_v_3_2 & 15)) & 63;
    if ((stage_v_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_9_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_9_1) + 7) & 255;
    }
    if ((stage_v_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_9_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_9_2) + 7) & 255;
    }
  }

  int stage_v_10_1 = ((pub_r001188_7_1 * 2) + 39) & 63;
  int stage_v_10_2 = ((pub_r001188_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (it_1 * 3)) + (sec_r001188_20_1 & 15)) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (it_2 * 3)) + (sec_r001188_20_2 & 15)) & 63;
    if ((sec_r001188_20_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_11_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_11_1) + 7) & 255;
    }
    if ((sec_r001188_20_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_11_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_11_2) + 7) & 255;
    }
  }

  int stage_v_12_1 = ((pub_r001188_3_1 * 2) + 20) & 63;
  int stage_v_12_2 = ((pub_r001188_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (it_1 * 3)) + (sec_r001188_14_1 & 15)) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (it_2 * 3)) + (sec_r001188_14_2 & 15)) & 63;
    if ((sec_r001188_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_13_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_13_1) + 7) & 255;
    }
    if ((sec_r001188_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_13_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_13_2) + 7) & 255;
    }
  }

  int stage_v_14_1 = ((pub_r001188_5_1 * 2) + 25) & 63;
  int stage_v_14_2 = ((pub_r001188_5_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (it_1 * 3)) + (helper_flow_8_1 & 15)) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (it_2 * 3)) + (helper_flow_8_2 & 15)) & 63;
    if ((helper_flow_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_15_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_15_1) + 7) & 255;
    }
    if ((helper_flow_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_15_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_15_2) + 7) & 255;
    }
  }

  int stage_v_16_1 = ((pub_r001188_0_1 * 2) + 9) & 63;
  int stage_v_16_2 = ((pub_r001188_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001188_2_1 * 2) + 6) & 63;
  int stage_v_17_2 = ((pub_r001188_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_18_1 = ((stage_v_18_1 + (it_1 * 3)) + (stage_v_13_1 & 15)) & 63;
    stage_v_18_2 = ((stage_v_18_2 + (it_2 * 3)) + (stage_v_13_2 & 15)) & 63;
    if ((stage_v_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_18_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_18_1) + 7) & 255;
    }
    if ((stage_v_13_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_18_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_18_2) + 7) & 255;
    }
  }

  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (it_1 * 3)) + (sec_r001188_12_1 & 15)) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (it_2 * 3)) + (sec_r001188_12_2 & 15)) & 63;
    if ((sec_r001188_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_19_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_19_1) + 7) & 255;
    }
    if ((sec_r001188_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_19_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_19_2) + 7) & 255;
    }
  }

  int stage_v_20_1 = ((pub_r001188_11_1 * 2) + 49) & 63;
  int stage_v_20_2 = ((pub_r001188_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_21_1 = ((stage_v_21_1 + (it_1 * 3)) + (sec_r001188_19_1 & 15)) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (it_2 * 3)) + (sec_r001188_19_2 & 15)) & 63;
    if ((sec_r001188_19_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_21_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_21_1) + 7) & 255;
    }
    if ((sec_r001188_19_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_21_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_21_2) + 7) & 255;
    }
  }

  int stage_v_22_1 = ((pub_r001188_3_1 * 2) + 47) & 63;
  int stage_v_22_2 = ((pub_r001188_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (it_1 * 3)) + (sec_r001188_0_1 & 15)) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (it_2 * 3)) + (sec_r001188_0_2 & 15)) & 63;
    if ((sec_r001188_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_23_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_23_1) + 7) & 255;
    }
    if ((sec_r001188_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_23_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_23_2) + 7) & 255;
    }
  }

  int stage_v_24_1 = ((pub_r001188_14_1 * 2) + 36) & 63;
  int stage_v_24_2 = ((pub_r001188_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001188_4_1 * 2) + 22) & 63;
  int stage_v_25_2 = ((pub_r001188_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (it_1 * 3)) + (helper_flow_5_1 & 15)) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (it_2 * 3)) + (helper_flow_5_2 & 15)) & 63;
    if ((helper_flow_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_26_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_26_1) + 7) & 255;
    }
    if ((helper_flow_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_26_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_26_2) + 7) & 255;
    }
  }

  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (it_1 * 3)) + (sec_r001188_2_1 & 15)) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (it_2 * 3)) + (sec_r001188_2_2 & 15)) & 63;
    if ((sec_r001188_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_27_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_27_1) + 7) & 255;
    }
    if ((sec_r001188_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_27_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_27_2) + 7) & 255;
    }
  }

  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_28_1 = ((stage_v_28_1 + (it_1 * 3)) + (sec_r001188_18_1 & 15)) & 63;
    stage_v_28_2 = ((stage_v_28_2 + (it_2 * 3)) + (sec_r001188_18_2 & 15)) & 63;
    if ((sec_r001188_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_28_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_28_1) + 7) & 255;
    }
    if ((sec_r001188_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_28_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_28_2) + 7) & 255;
    }
  }

  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_29_1 = ((stage_v_29_1 + (it_1 * 3)) + (stage_v_0_1 & 15)) & 63;
    stage_v_29_2 = ((stage_v_29_2 + (it_2 * 3)) + (stage_v_0_2 & 15)) & 63;
    if ((stage_v_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_29_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_29_1) + 7) & 255;
    }
    if ((stage_v_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_29_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_29_2) + 7) & 255;
    }
  }

  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_30_1 = ((stage_v_30_1 + (it_1 * 3)) + (stage_v_2_1 & 15)) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (it_2 * 3)) + (stage_v_2_2 & 15)) & 63;
    if ((stage_v_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_30_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_30_1) + 7) & 255;
    }
    if ((stage_v_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_30_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_30_2) + 7) & 255;
    }
  }

  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_31_1 = ((stage_v_31_1 + (it_1 * 3)) + (sec_r001188_15_1 & 15)) & 63;
    stage_v_31_2 = ((stage_v_31_2 + (it_2 * 3)) + (sec_r001188_15_2 & 15)) & 63;
    if ((sec_r001188_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_31_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_31_1) + 7) & 255;
    }
    if ((sec_r001188_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_31_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_31_2) + 7) & 255;
    }
  }

  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_32_1 = ((stage_v_32_1 + (it_1 * 3)) + (stage_v_13_1 & 15)) & 63;
    stage_v_32_2 = ((stage_v_32_2 + (it_2 * 3)) + (stage_v_13_2 & 15)) & 63;
    if ((stage_v_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_32_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_32_1) + 7) & 255;
    }
    if ((stage_v_13_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_32_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_32_2) + 7) & 255;
    }
  }

  int stage_v_33_1 = ((pub_r001188_8_1 * 2) + 8) & 63;
  int stage_v_33_2 = ((pub_r001188_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_34_1 = ((stage_v_34_1 + (it_1 * 3)) + (helper_flow_10_1 & 15)) & 63;
    stage_v_34_2 = ((stage_v_34_2 + (it_2 * 3)) + (helper_flow_10_2 & 15)) & 63;
    if ((helper_flow_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_34_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_34_1) + 7) & 255;
    }
    if ((helper_flow_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_34_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_34_2) + 7) & 255;
    }
  }

  int stage_v_35_1 = ((pub_r001188_2_1 * 2) + 46) & 63;
  int stage_v_35_2 = ((pub_r001188_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (it_1 * 3)) + (sec_r001188_4_1 & 15)) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (it_2 * 3)) + (sec_r001188_4_2 & 15)) & 63;
    if ((sec_r001188_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_36_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_36_1) + 7) & 255;
    }
    if ((sec_r001188_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_36_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_36_2) + 7) & 255;
    }
  }

  int stage_v_37_1 = ((pub_r001188_12_1 * 2) + 49) & 63;
  int stage_v_37_2 = ((pub_r001188_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (it_1 * 3)) + (stage_v_27_1 & 15)) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (it_2 * 3)) + (stage_v_27_2 & 15)) & 63;
    if ((stage_v_27_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_38_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_38_1) + 7) & 255;
    }
    if ((stage_v_27_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_38_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_38_2) + 7) & 255;
    }
  }

  int stage_v_39_1 = ((pub_r001188_10_1 * 2) + 8) & 63;
  int stage_v_39_2 = ((pub_r001188_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_40_1 = ((stage_v_40_1 + (it_1 * 3)) + (stage_v_2_1 & 15)) & 63;
    stage_v_40_2 = ((stage_v_40_2 + (it_2 * 3)) + (stage_v_2_2 & 15)) & 63;
    if ((stage_v_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_40_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_40_1) + 7) & 255;
    }
    if ((stage_v_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_40_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_40_2) + 7) & 255;
    }
  }

  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_41_1 = ((stage_v_41_1 + (it_1 * 3)) + (stage_v_11_1 & 15)) & 63;
    stage_v_41_2 = ((stage_v_41_2 + (it_2 * 3)) + (stage_v_11_2 & 15)) & 63;
    if ((stage_v_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_41_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_41_1) + 7) & 255;
    }
    if ((stage_v_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_41_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_41_2) + 7) & 255;
    }
  }

  int stage_v_42_1 = ((pub_r001188_12_1 * 2) + 21) & 63;
  int stage_v_42_2 = ((pub_r001188_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001188_10_1 * 2) + 49) & 63;
  int stage_v_43_2 = ((pub_r001188_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001188_1_1 * 2) + 49) & 63;
  int stage_v_44_2 = ((pub_r001188_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_45_1 = ((stage_v_45_1 + (it_1 * 3)) + (sec_r001188_2_1 & 15)) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (it_2 * 3)) + (sec_r001188_2_2 & 15)) & 63;
    if ((sec_r001188_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_45_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_45_1) + 7) & 255;
    }
    if ((sec_r001188_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_45_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_45_2) + 7) & 255;
    }
  }

  int stage_v_46_1 = ((pub_r001188_3_1 * 2) + 5) & 63;
  int stage_v_46_2 = ((pub_r001188_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (it_1 * 3)) + (sec_r001188_16_1 & 15)) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (it_2 * 3)) + (sec_r001188_16_2 & 15)) & 63;
    if ((sec_r001188_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_47_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_47_1) + 7) & 255;
    }
    if ((sec_r001188_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_47_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_47_2) + 7) & 255;
    }
  }

  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (it_1 * 3)) + (sec_r001188_14_1 & 15)) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (it_2 * 3)) + (sec_r001188_14_2 & 15)) & 63;
    if ((sec_r001188_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_48_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_48_1) + 7) & 255;
    }
    if ((sec_r001188_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_48_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_48_2) + 7) & 255;
    }
  }

  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_49_1 = ((stage_v_49_1 + (it_1 * 3)) + (stage_v_27_1 & 15)) & 63;
    stage_v_49_2 = ((stage_v_49_2 + (it_2 * 3)) + (stage_v_27_2 & 15)) & 63;
    if ((stage_v_27_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_49_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_49_1) + 7) & 255;
    }
    if ((stage_v_27_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_49_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_49_2) + 7) & 255;
    }
  }

  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_50_1 = ((stage_v_50_1 + (it_1 * 3)) + (stage_v_2_1 & 15)) & 63;
    stage_v_50_2 = ((stage_v_50_2 + (it_2 * 3)) + (stage_v_2_2 & 15)) & 63;
    if ((stage_v_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_50_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_50_1) + 7) & 255;
    }
    if ((stage_v_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_50_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_50_2) + 7) & 255;
    }
  }

  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_51_1 = ((stage_v_51_1 + (it_1 * 3)) + (helper_flow_1_1 & 15)) & 63;
    stage_v_51_2 = ((stage_v_51_2 + (it_2 * 3)) + (helper_flow_1_2 & 15)) & 63;
    if ((helper_flow_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_51_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_51_1) + 7) & 255;
    }
    if ((helper_flow_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_51_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_51_2) + 7) & 255;
    }
  }

  int stage_v_52_1 = ((pub_r001188_0_1 * 2) + 5) & 63;
  int stage_v_52_2 = ((pub_r001188_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (it_1 * 3)) + (stage_v_21_1 & 15)) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (it_2 * 3)) + (stage_v_21_2 & 15)) & 63;
    if ((stage_v_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_53_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_53_1) + 7) & 255;
    }
    if ((stage_v_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_53_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_53_2) + 7) & 255;
    }
  }

  int stage_v_54_1 = ((pub_r001188_2_1 * 2) + 36) & 63;
  int stage_v_54_2 = ((pub_r001188_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_55_1 = ((stage_v_55_1 + (it_1 * 3)) + (sec_r001188_17_1 & 15)) & 63;
    stage_v_55_2 = ((stage_v_55_2 + (it_2 * 3)) + (sec_r001188_17_2 & 15)) & 63;
    if ((sec_r001188_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_55_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_55_1) + 7) & 255;
    }
    if ((sec_r001188_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_55_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_55_2) + 7) & 255;
    }
  }

  int stage_v_56_1 = ((pub_r001188_6_1 * 2) + 17) & 63;
  int stage_v_56_2 = ((pub_r001188_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001188_4_1 * 2) + 48) & 63;
  int stage_v_57_2 = ((pub_r001188_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001188_4_1 * 2) + 49) & 63;
  int stage_v_58_2 = ((pub_r001188_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001188_10_1 * 2) + 41) & 63;
  int stage_v_59_2 = ((pub_r001188_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_60_1 = ((stage_v_60_1 + (it_1 * 3)) + (stage_v_30_1 & 15)) & 63;
    stage_v_60_2 = ((stage_v_60_2 + (it_2 * 3)) + (stage_v_30_2 & 15)) & 63;
    if ((stage_v_30_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_60_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_60_1) + 7) & 255;
    }
    if ((stage_v_30_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_60_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_60_2) + 7) & 255;
    }
  }

  int stage_v_61_1 = ((pub_r001188_13_1 * 2) + 45) & 63;
  int stage_v_61_2 = ((pub_r001188_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_62_1 = ((stage_v_62_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_62_2 = ((stage_v_62_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_62_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_62_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_62_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_62_2) + 7) & 255;
    }
  }

  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_63_1 = ((stage_v_63_1 + (it_1 * 3)) + (helper_flow_0_1 & 15)) & 63;
    stage_v_63_2 = ((stage_v_63_2 + (it_2 * 3)) + (helper_flow_0_2 & 15)) & 63;
    if ((helper_flow_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_63_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_63_1) + 7) & 255;
    }
    if ((helper_flow_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_63_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_63_2) + 7) & 255;
    }
  }

  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_64_1 = ((stage_v_64_1 + (it_1 * 3)) + (stage_v_40_1 & 15)) & 63;
    stage_v_64_2 = ((stage_v_64_2 + (it_2 * 3)) + (stage_v_40_2 & 15)) & 63;
    if ((stage_v_40_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_64_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_64_1) + 7) & 255;
    }
    if ((stage_v_40_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_64_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_64_2) + 7) & 255;
    }
  }

  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_65_1 = ((stage_v_65_1 + (it_1 * 3)) + (stage_v_28_1 & 15)) & 63;
    stage_v_65_2 = ((stage_v_65_2 + (it_2 * 3)) + (stage_v_28_2 & 15)) & 63;
    if ((stage_v_28_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_65_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_65_1) + 7) & 255;
    }
    if ((stage_v_28_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_65_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_65_2) + 7) & 255;
    }
  }

  int stage_v_66_1 = ((pub_r001188_14_1 * 2) + 21) & 63;
  int stage_v_66_2 = ((pub_r001188_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_67_1 = ((stage_v_67_1 + (it_1 * 3)) + (sec_r001188_5_1 & 15)) & 63;
    stage_v_67_2 = ((stage_v_67_2 + (it_2 * 3)) + (sec_r001188_5_2 & 15)) & 63;
    if ((sec_r001188_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_67_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_67_1) + 7) & 255;
    }
    if ((sec_r001188_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_67_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_67_2) + 7) & 255;
    }
  }

  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (it_1 * 3)) + (sec_r001188_10_1 & 15)) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (it_2 * 3)) + (sec_r001188_10_2 & 15)) & 63;
    if ((sec_r001188_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_68_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_68_1) + 7) & 255;
    }
    if ((sec_r001188_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_68_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_68_2) + 7) & 255;
    }
  }

  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_69_1 = ((stage_v_69_1 + (it_1 * 3)) + (helper_flow_10_1 & 15)) & 63;
    stage_v_69_2 = ((stage_v_69_2 + (it_2 * 3)) + (helper_flow_10_2 & 15)) & 63;
    if ((helper_flow_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_69_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_69_1) + 7) & 255;
    }
    if ((helper_flow_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_69_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_69_2) + 7) & 255;
    }
  }

  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_70_1 = ((stage_v_70_1 + (it_1 * 3)) + (stage_v_34_1 & 15)) & 63;
    stage_v_70_2 = ((stage_v_70_2 + (it_2 * 3)) + (stage_v_34_2 & 15)) & 63;
    if ((stage_v_34_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_70_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_70_1) + 7) & 255;
    }
    if ((stage_v_34_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_70_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_70_2) + 7) & 255;
    }
  }

  int stage_v_71_1 = ((pub_r001188_9_1 * 2) + 34) & 63;
  int stage_v_71_2 = ((pub_r001188_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_72_1 = ((stage_v_72_1 + (it_1 * 3)) + (helper_flow_9_1 & 15)) & 63;
    stage_v_72_2 = ((stage_v_72_2 + (it_2 * 3)) + (helper_flow_9_2 & 15)) & 63;
    if ((helper_flow_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_72_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_72_1) + 7) & 255;
    }
    if ((helper_flow_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_72_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_72_2) + 7) & 255;
    }
  }

  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_73_1 = ((stage_v_73_1 + (it_1 * 3)) + (sec_r001188_5_1 & 15)) & 63;
    stage_v_73_2 = ((stage_v_73_2 + (it_2 * 3)) + (sec_r001188_5_2 & 15)) & 63;
    if ((sec_r001188_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_73_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_73_1) + 7) & 255;
    }
    if ((sec_r001188_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_73_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_73_2) + 7) & 255;
    }
  }

  int stage_v_74_1 = ((pub_r001188_14_1 * 2) + 27) & 63;
  int stage_v_74_2 = ((pub_r001188_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_75_1 = ((stage_v_75_1 + (it_1 * 3)) + (stage_v_41_1 & 15)) & 63;
    stage_v_75_2 = ((stage_v_75_2 + (it_2 * 3)) + (stage_v_41_2 & 15)) & 63;
    if ((stage_v_41_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_75_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_75_1) + 7) & 255;
    }
    if ((stage_v_41_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_75_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_75_2) + 7) & 255;
    }
  }

  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_76_1 = ((stage_v_76_1 + (it_1 * 3)) + (sec_r001188_15_1 & 15)) & 63;
    stage_v_76_2 = ((stage_v_76_2 + (it_2 * 3)) + (sec_r001188_15_2 & 15)) & 63;
    if ((sec_r001188_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_76_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_76_1) + 7) & 255;
    }
    if ((sec_r001188_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_76_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_76_2) + 7) & 255;
    }
  }

  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_77_1 = ((stage_v_77_1 + (it_1 * 3)) + (helper_flow_10_1 & 15)) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (it_2 * 3)) + (helper_flow_10_2 & 15)) & 63;
    if ((helper_flow_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_77_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_77_1) + 7) & 255;
    }
    if ((helper_flow_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_77_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_77_2) + 7) & 255;
    }
  }

  int stage_v_78_1 = ((pub_r001188_15_1 * 2) + 50) & 63;
  int stage_v_78_2 = ((pub_r001188_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_79_1 = ((stage_v_79_1 + (it_1 * 3)) + (helper_flow_9_1 & 15)) & 63;
    stage_v_79_2 = ((stage_v_79_2 + (it_2 * 3)) + (helper_flow_9_2 & 15)) & 63;
    if ((helper_flow_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_79_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_79_1) + 7) & 255;
    }
    if ((helper_flow_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_79_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_79_2) + 7) & 255;
    }
  }

  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_80_1 = ((stage_v_80_1 + (it_1 * 3)) + (sec_r001188_10_1 & 15)) & 63;
    stage_v_80_2 = ((stage_v_80_2 + (it_2 * 3)) + (sec_r001188_10_2 & 15)) & 63;
    if ((sec_r001188_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_80_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_80_1) + 7) & 255;
    }
    if ((sec_r001188_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_80_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_80_2) + 7) & 255;
    }
  }

  int stage_v_81_1 = ((pub_r001188_7_1 * 2) + 41) & 63;
  int stage_v_81_2 = ((pub_r001188_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_82_1 = ((stage_v_82_1 + (it_1 * 3)) + (sec_r001188_4_1 & 15)) & 63;
    stage_v_82_2 = ((stage_v_82_2 + (it_2 * 3)) + (sec_r001188_4_2 & 15)) & 63;
    if ((sec_r001188_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_82_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_82_1) + 7) & 255;
    }
    if ((sec_r001188_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_82_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_82_2) + 7) & 255;
    }
  }

  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_83_1 = ((stage_v_83_1 + (it_1 * 3)) + (stage_v_62_1 & 15)) & 63;
    stage_v_83_2 = ((stage_v_83_2 + (it_2 * 3)) + (stage_v_62_2 & 15)) & 63;
    if ((stage_v_62_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_83_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_83_1) + 7) & 255;
    }
    if ((stage_v_62_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_83_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_83_2) + 7) & 255;
    }
  }

  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_84_1 = ((stage_v_84_1 + (it_1 * 3)) + (stage_v_21_1 & 15)) & 63;
    stage_v_84_2 = ((stage_v_84_2 + (it_2 * 3)) + (stage_v_21_2 & 15)) & 63;
    if ((stage_v_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_84_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_84_1) + 7) & 255;
    }
    if ((stage_v_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_84_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_84_2) + 7) & 255;
    }
  }

  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_85_1 = ((stage_v_85_1 + (it_1 * 3)) + (sec_r001188_14_1 & 15)) & 63;
    stage_v_85_2 = ((stage_v_85_2 + (it_2 * 3)) + (sec_r001188_14_2 & 15)) & 63;
    if ((sec_r001188_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_85_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_85_1) + 7) & 255;
    }
    if ((sec_r001188_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_85_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_85_2) + 7) & 255;
    }
  }

  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_86_1 = ((stage_v_86_1 + (it_1 * 3)) + (stage_v_65_1 & 15)) & 63;
    stage_v_86_2 = ((stage_v_86_2 + (it_2 * 3)) + (stage_v_65_2 & 15)) & 63;
    if ((stage_v_65_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_86_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_86_1) + 7) & 255;
    }
    if ((stage_v_65_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_86_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_86_2) + 7) & 255;
    }
  }

  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_87_1 = ((stage_v_87_1 + (it_1 * 3)) + (stage_v_83_1 & 15)) & 63;
    stage_v_87_2 = ((stage_v_87_2 + (it_2 * 3)) + (stage_v_83_2 & 15)) & 63;
    if ((stage_v_83_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_87_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_87_1) + 7) & 255;
    }
    if ((stage_v_83_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_87_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_87_2) + 7) & 255;
    }
  }

  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_88_1 = ((stage_v_88_1 + (it_1 * 3)) + (stage_v_86_1 & 15)) & 63;
    stage_v_88_2 = ((stage_v_88_2 + (it_2 * 3)) + (stage_v_86_2 & 15)) & 63;
    if ((stage_v_86_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_88_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_88_1) + 7) & 255;
    }
    if ((stage_v_86_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_88_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_88_2) + 7) & 255;
    }
  }

  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_89_1 = ((stage_v_89_1 + (it_1 * 3)) + (helper_flow_8_1 & 15)) & 63;
    stage_v_89_2 = ((stage_v_89_2 + (it_2 * 3)) + (helper_flow_8_2 & 15)) & 63;
    if ((helper_flow_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_89_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_89_1) + 7) & 255;
    }
    if ((helper_flow_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_89_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_89_2) + 7) & 255;
    }
  }

  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_90_1 = ((stage_v_90_1 + (it_1 * 3)) + (stage_v_27_1 & 15)) & 63;
    stage_v_90_2 = ((stage_v_90_2 + (it_2 * 3)) + (stage_v_27_2 & 15)) & 63;
    if ((stage_v_27_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_90_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_90_1) + 7) & 255;
    }
    if ((stage_v_27_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_90_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_90_2) + 7) & 255;
    }
  }

  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_91_1 = ((stage_v_91_1 + (it_1 * 3)) + (stage_v_82_1 & 15)) & 63;
    stage_v_91_2 = ((stage_v_91_2 + (it_2 * 3)) + (stage_v_82_2 & 15)) & 63;
    if ((stage_v_82_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_91_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_91_1) + 7) & 255;
    }
    if ((stage_v_82_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_91_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_91_2) + 7) & 255;
    }
  }

  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_92_1 = ((stage_v_92_1 + (it_1 * 3)) + (sec_r001188_18_1 & 15)) & 63;
    stage_v_92_2 = ((stage_v_92_2 + (it_2 * 3)) + (sec_r001188_18_2 & 15)) & 63;
    if ((sec_r001188_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_92_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_92_1) + 7) & 255;
    }
    if ((sec_r001188_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_92_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_92_2) + 7) & 255;
    }
  }

  int stage_v_93_1 = ((pub_r001188_11_1 * 2) + 42) & 63;
  int stage_v_93_2 = ((pub_r001188_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_94_1 = ((stage_v_94_1 + (it_1 * 3)) + (stage_v_69_1 & 15)) & 63;
    stage_v_94_2 = ((stage_v_94_2 + (it_2 * 3)) + (stage_v_69_2 & 15)) & 63;
    if ((stage_v_69_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_94_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_94_1) + 7) & 255;
    }
    if ((stage_v_69_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_94_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_94_2) + 7) & 255;
    }
  }

  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_95_1 = ((stage_v_95_1 + (it_1 * 3)) + (helper_flow_8_1 & 15)) & 63;
    stage_v_95_2 = ((stage_v_95_2 + (it_2 * 3)) + (helper_flow_8_2 & 15)) & 63;
    if ((helper_flow_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_95_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_95_1) + 7) & 255;
    }
    if ((helper_flow_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_95_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_95_2) + 7) & 255;
    }
  }

  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_96_1 = ((stage_v_96_1 + (it_1 * 3)) + (stage_v_65_1 & 15)) & 63;
    stage_v_96_2 = ((stage_v_96_2 + (it_2 * 3)) + (stage_v_65_2 & 15)) & 63;
    if ((stage_v_65_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_96_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_96_1) + 7) & 255;
    }
    if ((stage_v_65_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_96_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_96_2) + 7) & 255;
    }
  }

  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_97_1 = ((stage_v_97_1 + (it_1 * 3)) + (sec_r001188_9_1 & 15)) & 63;
    stage_v_97_2 = ((stage_v_97_2 + (it_2 * 3)) + (sec_r001188_9_2 & 15)) & 63;
    if ((sec_r001188_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_97_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_97_1) + 7) & 255;
    }
    if ((sec_r001188_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_97_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_97_2) + 7) & 255;
    }
  }

  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_98_1 = ((stage_v_98_1 + (it_1 * 3)) + (stage_v_63_1 & 15)) & 63;
    stage_v_98_2 = ((stage_v_98_2 + (it_2 * 3)) + (stage_v_63_2 & 15)) & 63;
    if ((stage_v_63_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_98_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_98_1) + 7) & 255;
    }
    if ((stage_v_63_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_98_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_98_2) + 7) & 255;
    }
  }

  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_99_1 = ((stage_v_99_1 + (it_1 * 3)) + (helper_flow_3_1 & 15)) & 63;
    stage_v_99_2 = ((stage_v_99_2 + (it_2 * 3)) + (helper_flow_3_2 & 15)) & 63;
    if ((helper_flow_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_99_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_99_1) + 7) & 255;
    }
    if ((helper_flow_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_99_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_99_2) + 7) & 255;
    }
  }

  int stage_v_100_1 = ((pub_r001188_7_1 * 2) + 38) & 63;
  int stage_v_100_2 = ((pub_r001188_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001188_15_1 * 2) + 17) & 63;
  int stage_v_101_2 = ((pub_r001188_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_102_1 = ((stage_v_102_1 + (it_1 * 3)) + (stage_v_50_1 & 15)) & 63;
    stage_v_102_2 = ((stage_v_102_2 + (it_2 * 3)) + (stage_v_50_2 & 15)) & 63;
    if ((stage_v_50_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_102_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_102_1) + 7) & 255;
    }
    if ((stage_v_50_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_102_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_102_2) + 7) & 255;
    }
  }

  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_103_1 = ((stage_v_103_1 + (it_1 * 3)) + (stage_v_79_1 & 15)) & 63;
    stage_v_103_2 = ((stage_v_103_2 + (it_2 * 3)) + (stage_v_79_2 & 15)) & 63;
    if ((stage_v_79_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_103_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_103_1) + 7) & 255;
    }
    if ((stage_v_79_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_103_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_103_2) + 7) & 255;
    }
  }

  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_104_1 = ((stage_v_104_1 + (it_1 * 3)) + (stage_v_51_1 & 15)) & 63;
    stage_v_104_2 = ((stage_v_104_2 + (it_2 * 3)) + (stage_v_51_2 & 15)) & 63;
    if ((stage_v_51_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_104_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_104_1) + 7) & 255;
    }
    if ((stage_v_51_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_104_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_104_2) + 7) & 255;
    }
  }

  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_105_1 = ((stage_v_105_1 + (it_1 * 3)) + (stage_v_34_1 & 15)) & 63;
    stage_v_105_2 = ((stage_v_105_2 + (it_2 * 3)) + (stage_v_34_2 & 15)) & 63;
    if ((stage_v_34_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_105_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_105_1) + 7) & 255;
    }
    if ((stage_v_34_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_105_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_105_2) + 7) & 255;
    }
  }

  int stage_v_106_1 = ((pub_r001188_5_1 * 2) + 7) & 63;
  int stage_v_106_2 = ((pub_r001188_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001188_5_1 * 2) + 41) & 63;
  int stage_v_107_2 = ((pub_r001188_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001188_10_1 * 2) + 27) & 63;
  int stage_v_108_2 = ((pub_r001188_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_109_1 = ((stage_v_109_1 + (it_1 * 3)) + (stage_v_32_1 & 15)) & 63;
    stage_v_109_2 = ((stage_v_109_2 + (it_2 * 3)) + (stage_v_32_2 & 15)) & 63;
    if ((stage_v_32_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_109_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_109_1) + 7) & 255;
    }
    if ((stage_v_32_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_109_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_109_2) + 7) & 255;
    }
  }

  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_110_1 = ((stage_v_110_1 + (it_1 * 3)) + (helper_flow_10_1 & 15)) & 63;
    stage_v_110_2 = ((stage_v_110_2 + (it_2 * 3)) + (helper_flow_10_2 & 15)) & 63;
    if ((helper_flow_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_110_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_110_1) + 7) & 255;
    }
    if ((helper_flow_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_110_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_110_2) + 7) & 255;
    }
  }

  int stage_v_111_1 = ((pub_r001188_12_1 * 2) + 49) & 63;
  int stage_v_111_2 = ((pub_r001188_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001188_14_1 * 2) + 47) & 63;
  int stage_v_112_2 = ((pub_r001188_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_113_1 = ((stage_v_113_1 + (it_1 * 3)) + (stage_v_99_1 & 15)) & 63;
    stage_v_113_2 = ((stage_v_113_2 + (it_2 * 3)) + (stage_v_99_2 & 15)) & 63;
    if ((stage_v_99_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_113_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_113_1) + 7) & 255;
    }
    if ((stage_v_99_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_113_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_113_2) + 7) & 255;
    }
  }

  int stage_v_114_1 = ((pub_r001188_0_1 * 2) + 15) & 63;
  int stage_v_114_2 = ((pub_r001188_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001188_5_1 * 2) + 11) & 63;
  int stage_v_115_2 = ((pub_r001188_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001188_14_1 * 2) + 17) & 63;
  int stage_v_116_2 = ((pub_r001188_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_117_1 = ((stage_v_117_1 + (it_1 * 3)) + (stage_v_87_1 & 15)) & 63;
    stage_v_117_2 = ((stage_v_117_2 + (it_2 * 3)) + (stage_v_87_2 & 15)) & 63;
    if ((stage_v_87_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_117_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_117_1) + 7) & 255;
    }
    if ((stage_v_87_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_117_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_117_2) + 7) & 255;
    }
  }

  int stage_v_118_1 = ((pub_r001188_6_1 * 2) + 38) & 63;
  int stage_v_118_2 = ((pub_r001188_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001188_12_1 * 2) + 27) & 63;
  int stage_v_119_2 = ((pub_r001188_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001188_2_1 * 2) + 32) & 63;
  int stage_v_120_2 = ((pub_r001188_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_121_1 = ((stage_v_121_1 + (it_1 * 3)) + (stage_v_27_1 & 15)) & 63;
    stage_v_121_2 = ((stage_v_121_2 + (it_2 * 3)) + (stage_v_27_2 & 15)) & 63;
    if ((stage_v_27_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_121_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_121_1) + 7) & 255;
    }
    if ((stage_v_27_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_121_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_121_2) + 7) & 255;
    }
  }

  int stage_v_122_1 = ((pub_r001188_4_1 * 2) + 13) & 63;
  int stage_v_122_2 = ((pub_r001188_4_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_123_1 = ((stage_v_123_1 + (it_1 * 3)) + (stage_v_27_1 & 15)) & 63;
    stage_v_123_2 = ((stage_v_123_2 + (it_2 * 3)) + (stage_v_27_2 & 15)) & 63;
    if ((stage_v_27_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_123_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_123_1) + 7) & 255;
    }
    if ((stage_v_27_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_123_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_123_2) + 7) & 255;
    }
  }

  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_124_1 = ((stage_v_124_1 + (it_1 * 3)) + (stage_v_82_1 & 15)) & 63;
    stage_v_124_2 = ((stage_v_124_2 + (it_2 * 3)) + (stage_v_82_2 & 15)) & 63;
    if ((stage_v_82_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_124_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_124_1) + 7) & 255;
    }
    if ((stage_v_82_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_124_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_124_2) + 7) & 255;
    }
  }

  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_125_1 = ((stage_v_125_1 + (it_1 * 3)) + (sec_r001188_2_1 & 15)) & 63;
    stage_v_125_2 = ((stage_v_125_2 + (it_2 * 3)) + (sec_r001188_2_2 & 15)) & 63;
    if ((sec_r001188_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_125_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_125_1) + 7) & 255;
    }
    if ((sec_r001188_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_125_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_125_2) + 7) & 255;
    }
  }

  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_126_1 = ((stage_v_126_1 + (it_1 * 3)) + (sec_r001188_12_1 & 15)) & 63;
    stage_v_126_2 = ((stage_v_126_2 + (it_2 * 3)) + (sec_r001188_12_2 & 15)) & 63;
    if ((sec_r001188_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_126_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_126_1) + 7) & 255;
    }
    if ((sec_r001188_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_126_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_126_2) + 7) & 255;
    }
  }

  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_127_1 = ((stage_v_127_1 + (it_1 * 3)) + (stage_v_86_1 & 15)) & 63;
    stage_v_127_2 = ((stage_v_127_2 + (it_2 * 3)) + (stage_v_86_2 & 15)) & 63;
    if ((stage_v_86_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_127_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_127_1) + 7) & 255;
    }
    if ((stage_v_86_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_127_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_127_2) + 7) & 255;
    }
  }

  int stage_v_128_1 = ((pub_r001188_3_1 * 2) + 26) & 63;
  int stage_v_128_2 = ((pub_r001188_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_129_1 = ((stage_v_129_1 + (it_1 * 3)) + (stage_v_51_1 & 15)) & 63;
    stage_v_129_2 = ((stage_v_129_2 + (it_2 * 3)) + (stage_v_51_2 & 15)) & 63;
    if ((stage_v_51_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_129_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_129_1) + 7) & 255;
    }
    if ((stage_v_51_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_129_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_129_2) + 7) & 255;
    }
  }

  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_130_1 = ((stage_v_130_1 + (it_1 * 3)) + (stage_v_47_1 & 15)) & 63;
    stage_v_130_2 = ((stage_v_130_2 + (it_2 * 3)) + (stage_v_47_2 & 15)) & 63;
    if ((stage_v_47_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_130_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_130_1) + 7) & 255;
    }
    if ((stage_v_47_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_130_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_130_2) + 7) & 255;
    }
  }

  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_131_1 = ((stage_v_131_1 + (it_1 * 3)) + (sec_r001188_4_1 & 15)) & 63;
    stage_v_131_2 = ((stage_v_131_2 + (it_2 * 3)) + (sec_r001188_4_2 & 15)) & 63;
    if ((sec_r001188_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_131_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_131_1) + 7) & 255;
    }
    if ((sec_r001188_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_131_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_131_2) + 7) & 255;
    }
  }

  int stage_v_132_1 = ((pub_r001188_5_1 * 2) + 44) & 63;
  int stage_v_132_2 = ((pub_r001188_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001188_4_1 * 2) + 38) & 63;
  int stage_v_133_2 = ((pub_r001188_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_134_1 = ((stage_v_134_1 + (it_1 * 3)) + (stage_v_26_1 & 15)) & 63;
    stage_v_134_2 = ((stage_v_134_2 + (it_2 * 3)) + (stage_v_26_2 & 15)) & 63;
    if ((stage_v_26_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_134_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_134_1) + 7) & 255;
    }
    if ((stage_v_26_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_134_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_134_2) + 7) & 255;
    }
  }

  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_135_1 = ((stage_v_135_1 + (it_1 * 3)) + (stage_v_23_1 & 15)) & 63;
    stage_v_135_2 = ((stage_v_135_2 + (it_2 * 3)) + (stage_v_23_2 & 15)) & 63;
    if ((stage_v_23_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_135_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_135_1) + 7) & 255;
    }
    if ((stage_v_23_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_135_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_135_2) + 7) & 255;
    }
  }

  int stage_v_136_1 = ((pub_r001188_8_1 * 2) + 16) & 63;
  int stage_v_136_2 = ((pub_r001188_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_137_1 = ((stage_v_137_1 + (it_1 * 3)) + (stage_v_103_1 & 15)) & 63;
    stage_v_137_2 = ((stage_v_137_2 + (it_2 * 3)) + (stage_v_103_2 & 15)) & 63;
    if ((stage_v_103_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_137_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_137_1) + 7) & 255;
    }
    if ((stage_v_103_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_137_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_137_2) + 7) & 255;
    }
  }

  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_138_1 = ((stage_v_138_1 + (it_1 * 3)) + (stage_v_49_1 & 15)) & 63;
    stage_v_138_2 = ((stage_v_138_2 + (it_2 * 3)) + (stage_v_49_2 & 15)) & 63;
    if ((stage_v_49_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_138_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_138_1) + 7) & 255;
    }
    if ((stage_v_49_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_138_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_138_2) + 7) & 255;
    }
  }

  int stage_v_139_1 = ((pub_r001188_0_1 * 2) + 32) & 63;
  int stage_v_139_2 = ((pub_r001188_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_140_1 = ((stage_v_140_1 + (it_1 * 3)) + (stage_v_125_1 & 15)) & 63;
    stage_v_140_2 = ((stage_v_140_2 + (it_2 * 3)) + (stage_v_125_2 & 15)) & 63;
    if ((stage_v_125_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_140_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_140_1) + 7) & 255;
    }
    if ((stage_v_125_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_140_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_140_2) + 7) & 255;
    }
  }

  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_141_1 = ((stage_v_141_1 + (it_1 * 3)) + (stage_v_79_1 & 15)) & 63;
    stage_v_141_2 = ((stage_v_141_2 + (it_2 * 3)) + (stage_v_79_2 & 15)) & 63;
    if ((stage_v_79_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_141_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_141_1) + 7) & 255;
    }
    if ((stage_v_79_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_141_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_141_2) + 7) & 255;
    }
  }

  int stage_v_142_1 = ((pub_r001188_11_1 * 2) + 49) & 63;
  int stage_v_142_2 = ((pub_r001188_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_143_1 = ((stage_v_143_1 + (it_1 * 3)) + (sec_r001188_10_1 & 15)) & 63;
    stage_v_143_2 = ((stage_v_143_2 + (it_2 * 3)) + (sec_r001188_10_2 & 15)) & 63;
    if ((sec_r001188_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_143_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_143_1) + 7) & 255;
    }
    if ((sec_r001188_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_143_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_143_2) + 7) & 255;
    }
  }

  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_144_1 = ((stage_v_144_1 + (it_1 * 3)) + (stage_v_92_1 & 15)) & 63;
    stage_v_144_2 = ((stage_v_144_2 + (it_2 * 3)) + (stage_v_92_2 & 15)) & 63;
    if ((stage_v_92_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_144_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_144_1) + 7) & 255;
    }
    if ((stage_v_92_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_144_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_144_2) + 7) & 255;
    }
  }

  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_145_1 = ((stage_v_145_1 + (it_1 * 3)) + (stage_v_30_1 & 15)) & 63;
    stage_v_145_2 = ((stage_v_145_2 + (it_2 * 3)) + (stage_v_30_2 & 15)) & 63;
    if ((stage_v_30_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_145_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_145_1) + 7) & 255;
    }
    if ((stage_v_30_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_145_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_145_2) + 7) & 255;
    }
  }

  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_146_1 = ((stage_v_146_1 + (it_1 * 3)) + (stage_v_13_1 & 15)) & 63;
    stage_v_146_2 = ((stage_v_146_2 + (it_2 * 3)) + (stage_v_13_2 & 15)) & 63;
    if ((stage_v_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_146_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_146_1) + 7) & 255;
    }
    if ((stage_v_13_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_146_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_146_2) + 7) & 255;
    }
  }

  int stage_v_147_1 = ((pub_r001188_7_1 * 2) + 24) & 63;
  int stage_v_147_2 = ((pub_r001188_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_148_1 = ((stage_v_148_1 + (it_1 * 3)) + (stage_v_87_1 & 15)) & 63;
    stage_v_148_2 = ((stage_v_148_2 + (it_2 * 3)) + (stage_v_87_2 & 15)) & 63;
    if ((stage_v_87_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_148_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_148_1) + 7) & 255;
    }
    if ((stage_v_87_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_148_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_148_2) + 7) & 255;
    }
  }

  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_149_1 = ((stage_v_149_1 + (it_1 * 3)) + (sec_r001188_17_1 & 15)) & 63;
    stage_v_149_2 = ((stage_v_149_2 + (it_2 * 3)) + (sec_r001188_17_2 & 15)) & 63;
    if ((sec_r001188_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_149_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_149_1) + 7) & 255;
    }
    if ((sec_r001188_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_149_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_149_2) + 7) & 255;
    }
  }

  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_150_1 = ((stage_v_150_1 + (it_1 * 3)) + (stage_v_50_1 & 15)) & 63;
    stage_v_150_2 = ((stage_v_150_2 + (it_2 * 3)) + (stage_v_50_2 & 15)) & 63;
    if ((stage_v_50_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_150_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_150_1) + 7) & 255;
    }
    if ((stage_v_50_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_150_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_150_2) + 7) & 255;
    }
  }

  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_151_1 = ((stage_v_151_1 + (it_1 * 3)) + (stage_v_0_1 & 15)) & 63;
    stage_v_151_2 = ((stage_v_151_2 + (it_2 * 3)) + (stage_v_0_2 & 15)) & 63;
    if ((stage_v_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_151_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_151_1) + 7) & 255;
    }
    if ((stage_v_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_151_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_151_2) + 7) & 255;
    }
  }

  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_152_1 = ((stage_v_152_1 + (it_1 * 3)) + (stage_v_51_1 & 15)) & 63;
    stage_v_152_2 = ((stage_v_152_2 + (it_2 * 3)) + (stage_v_51_2 & 15)) & 63;
    if ((stage_v_51_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_152_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_152_1) + 7) & 255;
    }
    if ((stage_v_51_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_152_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_152_2) + 7) & 255;
    }
  }

  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_153_1 = ((stage_v_153_1 + (it_1 * 3)) + (stage_v_63_1 & 15)) & 63;
    stage_v_153_2 = ((stage_v_153_2 + (it_2 * 3)) + (stage_v_63_2 & 15)) & 63;
    if ((stage_v_63_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_153_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_153_1) + 7) & 255;
    }
    if ((stage_v_63_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_153_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_153_2) + 7) & 255;
    }
  }

  int stage_v_154_1 = ((pub_r001188_7_1 * 2) + 23) & 63;
  int stage_v_154_2 = ((pub_r001188_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_155_1 = ((stage_v_155_1 + (it_1 * 3)) + (stage_v_23_1 & 15)) & 63;
    stage_v_155_2 = ((stage_v_155_2 + (it_2 * 3)) + (stage_v_23_2 & 15)) & 63;
    if ((stage_v_23_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_155_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_155_1) + 7) & 255;
    }
    if ((stage_v_23_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_155_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_155_2) + 7) & 255;
    }
  }

  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_156_1 = ((stage_v_156_1 + (it_1 * 3)) + (stage_v_95_1 & 15)) & 63;
    stage_v_156_2 = ((stage_v_156_2 + (it_2 * 3)) + (stage_v_95_2 & 15)) & 63;
    if ((stage_v_95_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_156_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_156_1) + 7) & 255;
    }
    if ((stage_v_95_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_156_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_156_2) + 7) & 255;
    }
  }

  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_157_1 = ((stage_v_157_1 + (it_1 * 3)) + (stage_v_11_1 & 15)) & 63;
    stage_v_157_2 = ((stage_v_157_2 + (it_2 * 3)) + (stage_v_11_2 & 15)) & 63;
    if ((stage_v_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_157_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_157_1) + 7) & 255;
    }
    if ((stage_v_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_157_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_157_2) + 7) & 255;
    }
  }

  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_158_1 = ((stage_v_158_1 + (it_1 * 3)) + (stage_v_96_1 & 15)) & 63;
    stage_v_158_2 = ((stage_v_158_2 + (it_2 * 3)) + (stage_v_96_2 & 15)) & 63;
    if ((stage_v_96_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_158_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_158_1) + 7) & 255;
    }
    if ((stage_v_96_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_158_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_158_2) + 7) & 255;
    }
  }

  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_159_1 = ((stage_v_159_1 + (it_1 * 3)) + (sec_r001188_15_1 & 15)) & 63;
    stage_v_159_2 = ((stage_v_159_2 + (it_2 * 3)) + (sec_r001188_15_2 & 15)) & 63;
    if ((sec_r001188_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_159_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_159_1) + 7) & 255;
    }
    if ((sec_r001188_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_159_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_159_2) + 7) & 255;
    }
  }

  int stage_v_160_1 = ((pub_r001188_0_1 * 2) + 49) & 63;
  int stage_v_160_2 = ((pub_r001188_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001188_7_1 * 2) + 44) & 63;
  int stage_v_161_2 = ((pub_r001188_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_162_1 = ((stage_v_162_1 + (it_1 * 3)) + (stage_v_96_1 & 15)) & 63;
    stage_v_162_2 = ((stage_v_162_2 + (it_2 * 3)) + (stage_v_96_2 & 15)) & 63;
    if ((stage_v_96_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_162_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_162_1) + 7) & 255;
    }
    if ((stage_v_96_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_162_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_162_2) + 7) & 255;
    }
  }

  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_163_1 = ((stage_v_163_1 + (it_1 * 3)) + (stage_v_15_1 & 15)) & 63;
    stage_v_163_2 = ((stage_v_163_2 + (it_2 * 3)) + (stage_v_15_2 & 15)) & 63;
    if ((stage_v_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_163_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_163_1) + 7) & 255;
    }
    if ((stage_v_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_163_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_163_2) + 7) & 255;
    }
  }

  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_164_1 = ((stage_v_164_1 + (it_1 * 3)) + (stage_v_6_1 & 15)) & 63;
    stage_v_164_2 = ((stage_v_164_2 + (it_2 * 3)) + (stage_v_6_2 & 15)) & 63;
    if ((stage_v_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_164_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_164_1) + 7) & 255;
    }
    if ((stage_v_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_164_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_164_2) + 7) & 255;
    }
  }

  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_165_1 = ((stage_v_165_1 + (it_1 * 3)) + (stage_v_89_1 & 15)) & 63;
    stage_v_165_2 = ((stage_v_165_2 + (it_2 * 3)) + (stage_v_89_2 & 15)) & 63;
    if ((stage_v_89_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_165_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_165_1) + 7) & 255;
    }
    if ((stage_v_89_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_165_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_165_2) + 7) & 255;
    }
  }

  int stage_v_166_1 = ((pub_r001188_5_1 * 2) + 28) & 63;
  int stage_v_166_2 = ((pub_r001188_5_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_167_1 = ((stage_v_167_1 + (it_1 * 3)) + (stage_v_129_1 & 15)) & 63;
    stage_v_167_2 = ((stage_v_167_2 + (it_2 * 3)) + (stage_v_129_2 & 15)) & 63;
    if ((stage_v_129_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_167_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_167_1) + 7) & 255;
    }
    if ((stage_v_129_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_167_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_167_2) + 7) & 255;
    }
  }

  int stage_v_168_1 = 0;
  int stage_v_168_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_168_1 = ((stage_v_168_1 + (it_1 * 3)) + (stage_v_53_1 & 15)) & 63;
    stage_v_168_2 = ((stage_v_168_2 + (it_2 * 3)) + (stage_v_53_2 & 15)) & 63;
    if ((stage_v_53_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_168_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_168_1) + 7) & 255;
    }
    if ((stage_v_53_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_168_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_168_2) + 7) & 255;
    }
  }

  int stage_v_169_1 = ((pub_r001188_3_1 * 2) + 30) & 63;
  int stage_v_169_2 = ((pub_r001188_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = 0;
  int stage_v_170_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_170_1 = ((stage_v_170_1 + (it_1 * 3)) + (stage_v_9_1 & 15)) & 63;
    stage_v_170_2 = ((stage_v_170_2 + (it_2 * 3)) + (stage_v_9_2 & 15)) & 63;
    if ((stage_v_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_170_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_170_1) + 7) & 255;
    }
    if ((stage_v_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_170_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_170_2) + 7) & 255;
    }
  }

  int stage_v_171_1 = 0;
  int stage_v_171_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_171_1 = ((stage_v_171_1 + (it_1 * 3)) + (stage_v_1_1 & 15)) & 63;
    stage_v_171_2 = ((stage_v_171_2 + (it_2 * 3)) + (stage_v_1_2 & 15)) & 63;
    if ((stage_v_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_171_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_171_1) + 7) & 255;
    }
    if ((stage_v_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_171_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_171_2) + 7) & 255;
    }
  }

  int stage_v_172_1 = 0;
  int stage_v_172_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_172_1 = ((stage_v_172_1 + (it_1 * 3)) + (stage_v_170_1 & 15)) & 63;
    stage_v_172_2 = ((stage_v_172_2 + (it_2 * 3)) + (stage_v_170_2 & 15)) & 63;
    if ((stage_v_170_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_172_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_172_1) + 7) & 255;
    }
    if ((stage_v_170_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_172_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_172_2) + 7) & 255;
    }
  }

  int stage_v_173_1 = ((pub_r001188_1_1 * 2) + 44) & 63;
  int stage_v_173_2 = ((pub_r001188_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = 0;
  int stage_v_174_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_174_1 = ((stage_v_174_1 + (it_1 * 3)) + (stage_v_144_1 & 15)) & 63;
    stage_v_174_2 = ((stage_v_174_2 + (it_2 * 3)) + (stage_v_144_2 & 15)) & 63;
    if ((stage_v_144_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_174_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_174_1) + 7) & 255;
    }
    if ((stage_v_144_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_174_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_174_2) + 7) & 255;
    }
  }

  int stage_v_175_1 = ((pub_r001188_10_1 * 2) + 7) & 63;
  int stage_v_175_2 = ((pub_r001188_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = 0;
  int stage_v_176_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_176_1 = ((stage_v_176_1 + (it_1 * 3)) + (stage_v_53_1 & 15)) & 63;
    stage_v_176_2 = ((stage_v_176_2 + (it_2 * 3)) + (stage_v_53_2 & 15)) & 63;
    if ((stage_v_53_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_176_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_176_1) + 7) & 255;
    }
    if ((stage_v_53_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_176_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_176_2) + 7) & 255;
    }
  }

  int stage_v_177_1 = 0;
  int stage_v_177_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_177_1 = ((stage_v_177_1 + (it_1 * 3)) + (stage_v_164_1 & 15)) & 63;
    stage_v_177_2 = ((stage_v_177_2 + (it_2 * 3)) + (stage_v_164_2 & 15)) & 63;
    if ((stage_v_164_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_177_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_177_1) + 7) & 255;
    }
    if ((stage_v_164_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_177_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_177_2) + 7) & 255;
    }
  }

  int stage_v_178_1 = 0;
  int stage_v_178_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_178_1 = ((stage_v_178_1 + (it_1 * 3)) + (stage_v_86_1 & 15)) & 63;
    stage_v_178_2 = ((stage_v_178_2 + (it_2 * 3)) + (stage_v_86_2 & 15)) & 63;
    if ((stage_v_86_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_178_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_178_1) + 7) & 255;
    }
    if ((stage_v_86_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_178_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_178_2) + 7) & 255;
    }
  }

  int stage_v_179_1 = 0;
  int stage_v_179_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_179_1 = ((stage_v_179_1 + (it_1 * 3)) + (sec_r001188_18_1 & 15)) & 63;
    stage_v_179_2 = ((stage_v_179_2 + (it_2 * 3)) + (sec_r001188_18_2 & 15)) & 63;
    if ((sec_r001188_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_179_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_179_1) + 7) & 255;
    }
    if ((sec_r001188_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_179_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_179_2) + 7) & 255;
    }
  }

  int stage_v_180_1 = 0;
  int stage_v_180_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_180_1 = ((stage_v_180_1 + (it_1 * 3)) + (sec_r001188_16_1 & 15)) & 63;
    stage_v_180_2 = ((stage_v_180_2 + (it_2 * 3)) + (sec_r001188_16_2 & 15)) & 63;
    if ((sec_r001188_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_180_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_180_1) + 7) & 255;
    }
    if ((sec_r001188_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_180_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_180_2) + 7) & 255;
    }
  }

  int stage_v_181_1 = 0;
  int stage_v_181_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_181_1 = ((stage_v_181_1 + (it_1 * 3)) + (stage_v_64_1 & 15)) & 63;
    stage_v_181_2 = ((stage_v_181_2 + (it_2 * 3)) + (stage_v_64_2 & 15)) & 63;
    if ((stage_v_64_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_181_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_181_1) + 7) & 255;
    }
    if ((stage_v_64_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_181_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_181_2) + 7) & 255;
    }
  }

  int stage_v_182_1 = ((pub_r001188_7_1 * 2) + 24) & 63;
  int stage_v_182_2 = ((pub_r001188_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = 0;
  int stage_v_183_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_183_1 = ((stage_v_183_1 + (it_1 * 3)) + (stage_v_29_1 & 15)) & 63;
    stage_v_183_2 = ((stage_v_183_2 + (it_2 * 3)) + (stage_v_29_2 & 15)) & 63;
    if ((stage_v_29_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_183_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_183_1) + 7) & 255;
    }
    if ((stage_v_29_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_183_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_183_2) + 7) & 255;
    }
  }

  int stage_v_184_1 = 0;
  int stage_v_184_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_184_1 = ((stage_v_184_1 + (it_1 * 3)) + (stage_v_129_1 & 15)) & 63;
    stage_v_184_2 = ((stage_v_184_2 + (it_2 * 3)) + (stage_v_129_2 & 15)) & 63;
    if ((stage_v_129_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_184_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_184_1) + 7) & 255;
    }
    if ((stage_v_129_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_184_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_184_2) + 7) & 255;
    }
  }

  int stage_v_185_1 = ((pub_r001188_11_1 * 2) + 33) & 63;
  int stage_v_185_2 = ((pub_r001188_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = 0;
  int stage_v_186_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_186_1 = ((stage_v_186_1 + (it_1 * 3)) + (stage_v_62_1 & 15)) & 63;
    stage_v_186_2 = ((stage_v_186_2 + (it_2 * 3)) + (stage_v_62_2 & 15)) & 63;
    if ((stage_v_62_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_186_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_186_1) + 7) & 255;
    }
    if ((stage_v_62_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_186_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_186_2) + 7) & 255;
    }
  }

  int stage_v_187_1 = 0;
  int stage_v_187_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_187_1 = ((stage_v_187_1 + (it_1 * 3)) + (stage_v_79_1 & 15)) & 63;
    stage_v_187_2 = ((stage_v_187_2 + (it_2 * 3)) + (stage_v_79_2 & 15)) & 63;
    if ((stage_v_79_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_187_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_187_1) + 7) & 255;
    }
    if ((stage_v_79_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_187_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_187_2) + 7) & 255;
    }
  }

  int stage_v_188_1 = 0;
  int stage_v_188_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_188_1 = ((stage_v_188_1 + (it_1 * 3)) + (sec_r001188_11_1 & 15)) & 63;
    stage_v_188_2 = ((stage_v_188_2 + (it_2 * 3)) + (sec_r001188_11_2 & 15)) & 63;
    if ((sec_r001188_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_188_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_188_1) + 7) & 255;
    }
    if ((sec_r001188_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_188_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_188_2) + 7) & 255;
    }
  }

  int stage_v_189_1 = 0;
  int stage_v_189_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_189_1 = ((stage_v_189_1 + (it_1 * 3)) + (sec_r001188_8_1 & 15)) & 63;
    stage_v_189_2 = ((stage_v_189_2 + (it_2 * 3)) + (sec_r001188_8_2 & 15)) & 63;
    if ((sec_r001188_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_189_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_189_1) + 7) & 255;
    }
    if ((sec_r001188_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_189_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_189_2) + 7) & 255;
    }
  }

  int stage_v_190_1 = 0;
  int stage_v_190_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_190_1 = ((stage_v_190_1 + (it_1 * 3)) + (stage_v_23_1 & 15)) & 63;
    stage_v_190_2 = ((stage_v_190_2 + (it_2 * 3)) + (stage_v_23_2 & 15)) & 63;
    if ((stage_v_23_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_190_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_190_1) + 7) & 255;
    }
    if ((stage_v_23_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_190_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_190_2) + 7) & 255;
    }
  }

  int stage_v_191_1 = ((pub_r001188_15_1 * 2) + 34) & 63;
  int stage_v_191_2 = ((pub_r001188_15_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = 0;
  int stage_v_192_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_192_1 = ((stage_v_192_1 + (it_1 * 3)) + (stage_v_157_1 & 15)) & 63;
    stage_v_192_2 = ((stage_v_192_2 + (it_2 * 3)) + (stage_v_157_2 & 15)) & 63;
    if ((stage_v_157_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_192_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_192_1) + 7) & 255;
    }
    if ((stage_v_157_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_192_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_192_2) + 7) & 255;
    }
  }

  int stage_v_193_1 = 0;
  int stage_v_193_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_193_1 = ((stage_v_193_1 + (it_1 * 3)) + (stage_v_9_1 & 15)) & 63;
    stage_v_193_2 = ((stage_v_193_2 + (it_2 * 3)) + (stage_v_9_2 & 15)) & 63;
    if ((stage_v_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_193_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_193_1) + 7) & 255;
    }
    if ((stage_v_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_193_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_193_2) + 7) & 255;
    }
  }

  int stage_v_194_1 = 0;
  int stage_v_194_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_194_1 = ((stage_v_194_1 + (it_1 * 3)) + (stage_v_80_1 & 15)) & 63;
    stage_v_194_2 = ((stage_v_194_2 + (it_2 * 3)) + (stage_v_80_2 & 15)) & 63;
    if ((stage_v_80_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_194_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_194_1) + 7) & 255;
    }
    if ((stage_v_80_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_194_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_194_2) + 7) & 255;
    }
  }

  int stage_v_195_1 = 0;
  int stage_v_195_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_195_1 = ((stage_v_195_1 + (it_1 * 3)) + (stage_v_13_1 & 15)) & 63;
    stage_v_195_2 = ((stage_v_195_2 + (it_2 * 3)) + (stage_v_13_2 & 15)) & 63;
    if ((stage_v_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_195_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_195_1) + 7) & 255;
    }
    if ((stage_v_13_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_195_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_195_2) + 7) & 255;
    }
  }

  int stage_v_196_1 = ((pub_r001188_6_1 * 2) + 23) & 63;
  int stage_v_196_2 = ((pub_r001188_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = 0;
  int stage_v_197_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_197_1 = ((stage_v_197_1 + (it_1 * 3)) + (stage_v_174_1 & 15)) & 63;
    stage_v_197_2 = ((stage_v_197_2 + (it_2 * 3)) + (stage_v_174_2 & 15)) & 63;
    if ((stage_v_174_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_197_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_197_1) + 7) & 255;
    }
    if ((stage_v_174_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_197_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_197_2) + 7) & 255;
    }
  }

  int stage_v_198_1 = 0;
  int stage_v_198_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_198_1 = ((stage_v_198_1 + (it_1 * 3)) + (stage_v_110_1 & 15)) & 63;
    stage_v_198_2 = ((stage_v_198_2 + (it_2 * 3)) + (stage_v_110_2 & 15)) & 63;
    if ((stage_v_110_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_198_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_198_1) + 7) & 255;
    }
    if ((stage_v_110_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_198_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_198_2) + 7) & 255;
    }
  }

  int stage_v_199_1 = 0;
  int stage_v_199_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_199_1 = ((stage_v_199_1 + (it_1 * 3)) + (stage_v_163_1 & 15)) & 63;
    stage_v_199_2 = ((stage_v_199_2 + (it_2 * 3)) + (stage_v_163_2 & 15)) & 63;
    if ((stage_v_163_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_199_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_199_1) + 7) & 255;
    }
    if ((stage_v_163_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_199_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_199_2) + 7) & 255;
    }
  }

  int stage_v_200_1 = ((pub_r001188_10_1 * 2) + 23) & 63;
  int stage_v_200_2 = ((pub_r001188_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = 0;
  int stage_v_201_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_201_1 = ((stage_v_201_1 + (it_1 * 3)) + (stage_v_97_1 & 15)) & 63;
    stage_v_201_2 = ((stage_v_201_2 + (it_2 * 3)) + (stage_v_97_2 & 15)) & 63;
    if ((stage_v_97_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_201_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_201_1) + 7) & 255;
    }
    if ((stage_v_97_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_201_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_201_2) + 7) & 255;
    }
  }

  int stage_v_202_1 = 0;
  int stage_v_202_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_202_1 = ((stage_v_202_1 + (it_1 * 3)) + (helper_flow_0_1 & 15)) & 63;
    stage_v_202_2 = ((stage_v_202_2 + (it_2 * 3)) + (helper_flow_0_2 & 15)) & 63;
    if ((helper_flow_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_202_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_202_1) + 7) & 255;
    }
    if ((helper_flow_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_202_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_202_2) + 7) & 255;
    }
  }

  int stage_v_203_1 = 0;
  int stage_v_203_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_203_1 = ((stage_v_203_1 + (it_1 * 3)) + (stage_v_91_1 & 15)) & 63;
    stage_v_203_2 = ((stage_v_203_2 + (it_2 * 3)) + (stage_v_91_2 & 15)) & 63;
    if ((stage_v_91_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_203_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_203_1) + 7) & 255;
    }
    if ((stage_v_91_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_203_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_203_2) + 7) & 255;
    }
  }

  int stage_v_204_1 = 0;
  int stage_v_204_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_204_1 = ((stage_v_204_1 + (it_1 * 3)) + (stage_v_193_1 & 15)) & 63;
    stage_v_204_2 = ((stage_v_204_2 + (it_2 * 3)) + (stage_v_193_2 & 15)) & 63;
    if ((stage_v_193_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_204_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_204_1) + 7) & 255;
    }
    if ((stage_v_193_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_204_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_204_2) + 7) & 255;
    }
  }

  int stage_v_205_1 = 0;
  int stage_v_205_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_205_1 = ((stage_v_205_1 + (it_1 * 3)) + (stage_v_63_1 & 15)) & 63;
    stage_v_205_2 = ((stage_v_205_2 + (it_2 * 3)) + (stage_v_63_2 & 15)) & 63;
    if ((stage_v_63_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_205_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_205_1) + 7) & 255;
    }
    if ((stage_v_63_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_205_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_205_2) + 7) & 255;
    }
  }

  int stage_v_206_1 = 0;
  int stage_v_206_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_206_1 = ((stage_v_206_1 + (it_1 * 3)) + (stage_v_197_1 & 15)) & 63;
    stage_v_206_2 = ((stage_v_206_2 + (it_2 * 3)) + (stage_v_197_2 & 15)) & 63;
    if ((stage_v_197_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_206_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_206_1) + 7) & 255;
    }
    if ((stage_v_197_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_206_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_206_2) + 7) & 255;
    }
  }

  int stage_v_207_1 = ((pub_r001188_0_1 * 2) + 48) & 63;
  int stage_v_207_2 = ((pub_r001188_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = 0;
  int stage_v_208_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_208_1 = ((stage_v_208_1 + (it_1 * 3)) + (stage_v_92_1 & 15)) & 63;
    stage_v_208_2 = ((stage_v_208_2 + (it_2 * 3)) + (stage_v_92_2 & 15)) & 63;
    if ((stage_v_92_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_208_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_208_1) + 7) & 255;
    }
    if ((stage_v_92_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_208_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_208_2) + 7) & 255;
    }
  }

  int stage_v_209_1 = ((pub_r001188_6_1 * 2) + 22) & 63;
  int stage_v_209_2 = ((pub_r001188_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = 0;
  int stage_v_210_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_210_1 = ((stage_v_210_1 + (it_1 * 3)) + (stage_v_153_1 & 15)) & 63;
    stage_v_210_2 = ((stage_v_210_2 + (it_2 * 3)) + (stage_v_153_2 & 15)) & 63;
    if ((stage_v_153_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_210_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_210_1) + 7) & 255;
    }
    if ((stage_v_153_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_210_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_210_2) + 7) & 255;
    }
  }

  int stage_v_211_1 = ((pub_r001188_2_1 * 2) + 37) & 63;
  int stage_v_211_2 = ((pub_r001188_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((pub_r001188_8_1 * 2) + 48) & 63;
  int stage_v_212_2 = ((pub_r001188_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = 0;
  int stage_v_213_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_213_1 = ((stage_v_213_1 + (it_1 * 3)) + (stage_v_23_1 & 15)) & 63;
    stage_v_213_2 = ((stage_v_213_2 + (it_2 * 3)) + (stage_v_23_2 & 15)) & 63;
    if ((stage_v_23_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_213_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_213_1) + 7) & 255;
    }
    if ((stage_v_23_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_213_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_213_2) + 7) & 255;
    }
  }

  int stage_v_214_1 = ((pub_r001188_8_1 * 2) + 50) & 63;
  int stage_v_214_2 = ((pub_r001188_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = 0;
  int stage_v_215_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_215_1 = ((stage_v_215_1 + (it_1 * 3)) + (stage_v_64_1 & 15)) & 63;
    stage_v_215_2 = ((stage_v_215_2 + (it_2 * 3)) + (stage_v_64_2 & 15)) & 63;
    if ((stage_v_64_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_215_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_215_1) + 7) & 255;
    }
    if ((stage_v_64_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_215_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_215_2) + 7) & 255;
    }
  }

  int stage_v_216_1 = 0;
  int stage_v_216_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_216_1 = ((stage_v_216_1 + (it_1 * 3)) + (stage_v_34_1 & 15)) & 63;
    stage_v_216_2 = ((stage_v_216_2 + (it_2 * 3)) + (stage_v_34_2 & 15)) & 63;
    if ((stage_v_34_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_216_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_216_1) + 7) & 255;
    }
    if ((stage_v_34_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_216_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_216_2) + 7) & 255;
    }
  }

  int stage_v_217_1 = 0;
  int stage_v_217_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_217_1 = ((stage_v_217_1 + (it_1 * 3)) + (stage_v_62_1 & 15)) & 63;
    stage_v_217_2 = ((stage_v_217_2 + (it_2 * 3)) + (stage_v_62_2 & 15)) & 63;
    if ((stage_v_62_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_217_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_217_1) + 7) & 255;
    }
    if ((stage_v_62_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_217_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_217_2) + 7) & 255;
    }
  }

  int stage_v_218_1 = 0;
  int stage_v_218_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_218_1 = ((stage_v_218_1 + (it_1 * 3)) + (stage_v_47_1 & 15)) & 63;
    stage_v_218_2 = ((stage_v_218_2 + (it_2 * 3)) + (stage_v_47_2 & 15)) & 63;
    if ((stage_v_47_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_218_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_218_1) + 7) & 255;
    }
    if ((stage_v_47_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_218_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_218_2) + 7) & 255;
    }
  }

  int stage_v_219_1 = 0;
  int stage_v_219_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_219_1 = ((stage_v_219_1 + (it_1 * 3)) + (stage_v_105_1 & 15)) & 63;
    stage_v_219_2 = ((stage_v_219_2 + (it_2 * 3)) + (stage_v_105_2 & 15)) & 63;
    if ((stage_v_105_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_219_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_219_1) + 7) & 255;
    }
    if ((stage_v_105_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_219_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_219_2) + 7) & 255;
    }
  }

  int stage_v_220_1 = 0;
  int stage_v_220_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_220_1 = ((stage_v_220_1 + (it_1 * 3)) + (stage_v_157_1 & 15)) & 63;
    stage_v_220_2 = ((stage_v_220_2 + (it_2 * 3)) + (stage_v_157_2 & 15)) & 63;
    if ((stage_v_157_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_220_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_220_1) + 7) & 255;
    }
    if ((stage_v_157_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_220_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_220_2) + 7) & 255;
    }
  }

  int stage_v_221_1 = 0;
  int stage_v_221_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_221_1 = ((stage_v_221_1 + (it_1 * 3)) + (stage_v_64_1 & 15)) & 63;
    stage_v_221_2 = ((stage_v_221_2 + (it_2 * 3)) + (stage_v_64_2 & 15)) & 63;
    if ((stage_v_64_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_221_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_221_1) + 7) & 255;
    }
    if ((stage_v_64_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_221_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_221_2) + 7) & 255;
    }
  }

  int stage_v_222_1 = 0;
  int stage_v_222_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_222_1 = ((stage_v_222_1 + (it_1 * 3)) + (stage_v_124_1 & 15)) & 63;
    stage_v_222_2 = ((stage_v_222_2 + (it_2 * 3)) + (stage_v_124_2 & 15)) & 63;
    if ((stage_v_124_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_222_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_222_1) + 7) & 255;
    }
    if ((stage_v_124_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_222_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_222_2) + 7) & 255;
    }
  }

  int stage_v_223_1 = ((pub_r001188_11_1 * 2) + 30) & 63;
  int stage_v_223_2 = ((pub_r001188_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = 0;
  int stage_v_224_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_224_1 = ((stage_v_224_1 + (it_1 * 3)) + (stage_v_97_1 & 15)) & 63;
    stage_v_224_2 = ((stage_v_224_2 + (it_2 * 3)) + (stage_v_97_2 & 15)) & 63;
    if ((stage_v_97_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_224_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_224_1) + 7) & 255;
    }
    if ((stage_v_97_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_224_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_224_2) + 7) & 255;
    }
  }

  int stage_v_225_1 = ((pub_r001188_6_1 * 2) + 37) & 63;
  int stage_v_225_2 = ((pub_r001188_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = 0;
  int stage_v_226_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_226_1 = ((stage_v_226_1 + (it_1 * 3)) + (stage_v_125_1 & 15)) & 63;
    stage_v_226_2 = ((stage_v_226_2 + (it_2 * 3)) + (stage_v_125_2 & 15)) & 63;
    if ((stage_v_125_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_226_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_226_1) + 7) & 255;
    }
    if ((stage_v_125_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_226_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_226_2) + 7) & 255;
    }
  }

  int stage_v_227_1 = ((pub_r001188_9_1 * 2) + 37) & 63;
  int stage_v_227_2 = ((pub_r001188_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001188_6_1 * 2) + 35) & 63;
  int stage_v_228_2 = ((pub_r001188_6_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = 0;
  int stage_v_229_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_229_1 = ((stage_v_229_1 + (it_1 * 3)) + (sec_r001188_16_1 & 15)) & 63;
    stage_v_229_2 = ((stage_v_229_2 + (it_2 * 3)) + (sec_r001188_16_2 & 15)) & 63;
    if ((sec_r001188_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_229_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_229_1) + 7) & 255;
    }
    if ((sec_r001188_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_229_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_229_2) + 7) & 255;
    }
  }

  int stage_v_230_1 = 0;
  int stage_v_230_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_230_1 = ((stage_v_230_1 + (it_1 * 3)) + (stage_v_193_1 & 15)) & 63;
    stage_v_230_2 = ((stage_v_230_2 + (it_2 * 3)) + (stage_v_193_2 & 15)) & 63;
    if ((stage_v_193_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_230_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_230_1) + 7) & 255;
    }
    if ((stage_v_193_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_230_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_230_2) + 7) & 255;
    }
  }

  int stage_v_231_1 = ((pub_r001188_11_1 * 2) + 33) & 63;
  int stage_v_231_2 = ((pub_r001188_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = 0;
  int stage_v_232_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_232_1 = ((stage_v_232_1 + (it_1 * 3)) + (stage_v_67_1 & 15)) & 63;
    stage_v_232_2 = ((stage_v_232_2 + (it_2 * 3)) + (stage_v_67_2 & 15)) & 63;
    if ((stage_v_67_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_232_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_232_1) + 7) & 255;
    }
    if ((stage_v_67_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_232_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_232_2) + 7) & 255;
    }
  }

  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001188_6_1 != sec_r001188_6_2);
  __CPROVER_assume(sec_r001188_1_1 != sec_r001188_1_2);
  __CPROVER_assume(sec_r001188_19_1 != sec_r001188_19_2);
  __CPROVER_assume(pub_r001188_1_1 == pub_r001188_1_2);
  __CPROVER_assume(sec_r001188_10_1 != sec_r001188_10_2);
  __CPROVER_assume(pub_r001188_11_1 == pub_r001188_11_2);
  __CPROVER_assume(sec_r001188_20_1 != sec_r001188_20_2);
  __CPROVER_assume(sec_r001188_4_1 != sec_r001188_4_2);
  __CPROVER_assume(sec_r001188_13_1 != sec_r001188_13_2);
  __CPROVER_assume(pub_r001188_8_1 == pub_r001188_8_2);
  __CPROVER_assume(sec_r001188_17_1 != sec_r001188_17_2);
  __CPROVER_assume(pub_r001188_10_1 == pub_r001188_10_2);
  __CPROVER_assume(pub_r001188_14_1 == pub_r001188_14_2);
  __CPROVER_assume(sec_r001188_14_1 != sec_r001188_14_2);
  __CPROVER_assume(sec_r001188_2_1 != sec_r001188_2_2);
  __CPROVER_assume(pub_r001188_15_1 == pub_r001188_15_2);
  __CPROVER_assume(sec_r001188_9_1 != sec_r001188_9_2);
  __CPROVER_assume(sec_r001188_15_1 != sec_r001188_15_2);
  __CPROVER_assume(sec_r001188_3_1 != sec_r001188_3_2);
  __CPROVER_assume(pub_r001188_7_1 == pub_r001188_7_2);
  __CPROVER_assume(pub_r001188_3_1 == pub_r001188_3_2);
  __CPROVER_assume(sec_r001188_7_1 != sec_r001188_7_2);
  __CPROVER_assume(sec_r001188_11_1 != sec_r001188_11_2);
  __CPROVER_assume(sec_r001188_5_1 != sec_r001188_5_2);
  __CPROVER_assume(pub_r001188_13_1 == pub_r001188_13_2);
  __CPROVER_assume(pub_r001188_4_1 == pub_r001188_4_2);
  __CPROVER_assume(sec_r001188_12_1 != sec_r001188_12_2);
  __CPROVER_assume(sec_r001188_0_1 != sec_r001188_0_2);
  __CPROVER_assume(pub_r001188_9_1 == pub_r001188_9_2);
  __CPROVER_assume(sec_r001188_8_1 != sec_r001188_8_2);
  __CPROVER_assume(sec_r001188_16_1 != sec_r001188_16_2);
  __CPROVER_assume(pub_r001188_6_1 == pub_r001188_6_2);
  __CPROVER_assume(pub_r001188_5_1 == pub_r001188_5_2);
  __CPROVER_assume(sec_r001188_18_1 != sec_r001188_18_2);
  __CPROVER_assume(pub_r001188_2_1 == pub_r001188_2_2);
  __CPROVER_assume(pub_r001188_12_1 == pub_r001188_12_2);
  __CPROVER_assume(pub_r001188_0_1 == pub_r001188_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.density == st_var_0_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.offset == st_var_1_2.offset);
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
}


