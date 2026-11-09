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
struct DeviceConfig_R001015_1513_0
{
  int timeout;
  unsigned char port;
  unsigned char baud_rate;
  short id;
  int stop_bits;
  int buffer[3];
};
struct SensorNode_R001015_1513_1
{
  short reading;
  short status;
  unsigned char threshold;
  int offset;
  int buffer[3];
};
struct MatrixBlock_R001015_1513_2
{
  int stride;
  unsigned char trace;
  int dim;
  unsigned char density;
  unsigned char scale;
  short determinant;
  int buffer[3];
};
union ColorPixel_R001015_1513_0
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
void fn_R001015_1513_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001015_1513_2 st_1 = {0};
  struct MatrixBlock_R001015_1513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_64_1 = local_arr_1[aux_1 % 3];
  int tally_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_64_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_70_1) & 63;
  aux_2 = (aux_2 + tracker_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
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

  assert(tally_64_1 == tally_64_2);
  assert(tracker_70_1 == tracker_70_2);
}

int fn_R001015_1513_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001015_1513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int tally_64 = local_arr[aux % 3];
  acc = (acc + (tally_64 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_70) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001015_1513_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001015_1513_2 st_1 = {0};
  struct MatrixBlock_R001015_1513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int sample_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_53_1 > 21)
  {
    acc_1 = ((acc_1 + (sample_53_1 * 2)) + 5) & 127;
    aux_1 ^= sample_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_53_2 > 21)
  {
    acc_2 = ((acc_2 + (sample_53_2 * 2)) + 5) & 127;
    aux_2 ^= sample_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_53_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_99_1 = 0;
  int coefficient_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_99_1 = ((coefficient_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_99_2 = ((coefficient_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_99_1) & 127;
    acc_2 = (acc_2 + coefficient_99_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_27_1) & 63;
  aux_2 = (aux_2 + stride_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_53_1 == sample_53_2);
  assert(coefficient_99_1 == coefficient_99_2);
  assert(stride_27_1 == stride_27_2);
}

int fn_R001015_1513_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001015_1513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int sample_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_53 > 21)
  {
    acc = ((acc + (sample_53 * 2)) + 5) & 127;
    aux ^= sample_53 & 15;
  }
  else
  {
    acc = ((acc - sample_53) + 11) & 127;
    aux += 3;
  }
  int coefficient_99 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_99 = ((coefficient_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_99) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_27) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001015_1513_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001015_1513_0 st_1 = {0};
  struct DeviceConfig_R001015_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int weight_70_1 = 0;
  int weight_70_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_70_1 = ((weight_70_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_70_2 = ((weight_70_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_70_1) & 127;
    acc_2 = (acc_2 + weight_70_2) & 127;
  }

  int tally_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_25_1)
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

  switch (tally_25_2)
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

  int pivot_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_99_1) & 63;
  aux_2 = (aux_2 + pivot_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_70_1 == weight_70_2);
  assert(tally_25_1 == tally_25_2);
  assert(pivot_99_1 == pivot_99_2);
}

int fn_R001015_1513_2(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001015_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int weight_70 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_70 = ((weight_70 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_70) & 127;
  }

  int tally_25 = (aux + st.buffer[1]) & 3;
  switch (tally_25)
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

  int pivot_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_99) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001015_1513_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001015_1513_0 st_1 = {0};
  struct DeviceConfig_R001015_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int cursor_34_1 = 0;
  int cursor_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_34_1 = ((cursor_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_34_2 = ((cursor_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_34_1) & 127;
    acc_2 = (acc_2 + cursor_34_2) & 127;
  }

  int accumulator_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_93_1)
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

  switch (accumulator_93_2)
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

  int margin_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_98_1 > 34)
  {
    acc_1 = ((acc_1 + (margin_98_1 * 2)) + 5) & 127;
    aux_1 ^= margin_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_98_2 > 34)
  {
    acc_2 = ((acc_2 + (margin_98_2 * 2)) + 5) & 127;
    aux_2 ^= margin_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_98_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_34_1 == cursor_34_2);
  assert(accumulator_93_1 == accumulator_93_2);
  assert(margin_98_1 == margin_98_2);
}

int fn_R001015_1513_3(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001015_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int cursor_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_34 = ((cursor_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_34) & 127;
  }

  int accumulator_93 = (aux + st.buffer[1]) & 3;
  switch (accumulator_93)
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

  int margin_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_98 > 34)
  {
    acc = ((acc + (margin_98 * 2)) + 5) & 127;
    aux ^= margin_98 & 15;
  }
  else
  {
    acc = ((acc - margin_98) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001015_1513_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001015_1513_0 st_1 = {0};
  struct DeviceConfig_R001015_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int quantum_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_10_1) & 63;
  aux_2 = (aux_2 + quantum_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_66_1 > 12)
  {
    acc_1 = ((acc_1 + (parity_66_1 * 2)) + 5) & 127;
    aux_1 ^= parity_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_66_2 > 12)
  {
    acc_2 = ((acc_2 + (parity_66_2 * 2)) + 5) & 127;
    aux_2 ^= parity_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_66_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_34_1)
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

  switch (pivot_34_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_10_1 == quantum_10_2);
  assert(parity_66_1 == parity_66_2);
  assert(pivot_34_1 == pivot_34_2);
}

int fn_R001015_1513_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001015_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int quantum_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_10) & 63;
  acc ^= aux;
  int parity_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_66 > 12)
  {
    acc = ((acc + (parity_66 * 2)) + 5) & 127;
    aux ^= parity_66 & 15;
  }
  else
  {
    acc = ((acc - parity_66) + 11) & 127;
    aux += 3;
  }
  int pivot_34 = (aux + st.buffer[1]) & 3;
  switch (pivot_34)
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

void fn_R001015_1513_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001015_1513_1 st_1 = {0};
  struct SensorNode_R001015_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_81_1 = local_arr_1[aux_1 % 3];
  int quantum_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_81_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_24_1 = 0;
  int segment_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_24_1 = ((segment_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_24_2 = ((segment_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_24_1) & 127;
    acc_2 = (acc_2 + segment_24_2) & 127;
  }

  int margin_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_40_1)
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

  switch (margin_40_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_81_1 == quantum_81_2);
  assert(segment_24_1 == segment_24_2);
  assert(margin_40_1 == margin_40_2);
}

int fn_R001015_1513_5(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001015_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int quantum_81 = local_arr[aux % 3];
  acc = (acc + (quantum_81 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_24 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_24 = ((segment_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_24) & 127;
  }

  int margin_40 = (aux + st.buffer[1]) & 3;
  switch (margin_40)
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

void fn_R001015_1513_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001015_1513_1 st_1 = {0};
  struct SensorNode_R001015_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int mask_65_1 = 0;
  int mask_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_65_1 = ((mask_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_65_2 = ((mask_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_65_1) & 127;
    acc_2 = (acc_2 + mask_65_2) & 127;
  }

  int accumulator_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_70_1) & 63;
  aux_2 = (aux_2 + accumulator_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_15_1)
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

  switch (stride_15_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_65_1 == mask_65_2);
  assert(accumulator_70_1 == accumulator_70_2);
  assert(stride_15_1 == stride_15_2);
}

int fn_R001015_1513_6(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001015_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int mask_65 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_65 = ((mask_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_65) & 127;
  }

  int accumulator_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_70) & 63;
  acc ^= aux;
  int stride_15 = (aux + st.buffer[1]) & 3;
  switch (stride_15)
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

void fn_R001015_1513_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001015_1513_1 st_1 = {0};
  struct SensorNode_R001015_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int coefficient_44_1 = 0;
  int coefficient_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_44_1 = ((coefficient_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_44_2 = ((coefficient_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_44_1) & 127;
    acc_2 = (acc_2 + coefficient_44_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_30_1 = local_arr_1[aux_1 % 3];
  int cursor_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_30_2 * 2)) & 127;
  int checksum_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_67_1)
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

  switch (checksum_67_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_44_1 == coefficient_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_30_1 == cursor_30_2);
  assert(checksum_67_1 == checksum_67_2);
}

int fn_R001015_1513_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001015_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int coefficient_44 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_44 = ((coefficient_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_44) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int cursor_30 = local_arr[aux % 3];
  acc = (acc + (cursor_30 * 2)) & 127;
  int checksum_67 = (aux + st.buffer[1]) & 3;
  switch (checksum_67)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001015_1513_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001015_1513_1 st_1 = {0};
  struct SensorNode_R001015_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int window_92_1 = 0;
  int window_92_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_92_1 = ((window_92_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_92_2 = ((window_92_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_92_1) & 127;
    acc_2 = (acc_2 + window_92_2) & 127;
  }

  int phase_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_94_1 > 41)
  {
    acc_1 = ((acc_1 + (phase_94_1 * 2)) + 5) & 127;
    aux_1 ^= phase_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_94_2 > 41)
  {
    acc_2 = ((acc_2 + (phase_94_2 * 2)) + 5) & 127;
    aux_2 ^= phase_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_48_1) & 63;
  aux_2 = (aux_2 + index_reg_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_92_1 == window_92_2);
  assert(phase_94_1 == phase_94_2);
  assert(index_reg_48_1 == index_reg_48_2);
}

int fn_R001015_1513_8(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001015_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int window_92 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_92 = ((window_92 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_92) & 127;
  }

  int phase_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_94 > 41)
  {
    acc = ((acc + (phase_94 * 2)) + 5) & 127;
    aux ^= phase_94 & 15;
  }
  else
  {
    acc = ((acc - phase_94) + 11) & 127;
    aux += 3;
  }
  int index_reg_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_48) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001015_1513_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001015_1513_0 st_1 = {0};
  struct DeviceConfig_R001015_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int window_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_91_1 > 41)
  {
    acc_1 = ((acc_1 + (window_91_1 * 2)) + 5) & 127;
    aux_1 ^= window_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_91_2 > 41)
  {
    acc_2 = ((acc_2 + (window_91_2 * 2)) + 5) & 127;
    aux_2 ^= window_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_57_1)
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

  switch (tally_57_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_91_1 == window_91_2);
  assert(tally_57_1 == tally_57_2);
}

int fn_R001015_1513_9(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001015_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int window_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_91 > 41)
  {
    acc = ((acc + (window_91 * 2)) + 5) & 127;
    aux ^= window_91 & 15;
  }
  else
  {
    acc = ((acc - window_91) + 11) & 127;
    aux += 3;
  }
  int tally_57 = (aux + st.buffer[1]) & 3;
  switch (tally_57)
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

void fn_R001015_1513_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001015_1513_1 st_1 = {0};
  struct SensorNode_R001015_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int weight_72_1 = 0;
  int weight_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_72_1 = ((weight_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_72_2 = ((weight_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_72_1) & 127;
    acc_2 = (acc_2 + weight_72_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_72_1 == weight_72_2);
}

int fn_R001015_1513_10(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001015_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int weight_72 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_72 = ((weight_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_72) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001015_1513_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001015_1513_0 st_1 = {0};
  struct DeviceConfig_R001015_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int cursor_90_1 = 0;
  int cursor_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_90_1 = ((cursor_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_90_2 = ((cursor_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_90_1) & 127;
    acc_2 = (acc_2 + cursor_90_2) & 127;
  }

  int bound_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_45_1)
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

  switch (bound_45_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_90_1 == cursor_90_2);
  assert(bound_45_1 == bound_45_2);
}

int fn_R001015_1513_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001015_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int cursor_90 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_90 = ((cursor_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_90) & 127;
  }

  int bound_45 = (aux + st.buffer[1]) & 3;
  switch (bound_45)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001015_1513_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001015_1513_2 st_1 = {0};
  struct MatrixBlock_R001015_1513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_81_1 = local_arr_1[aux_1 % 3];
  int phase_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_81_2 * 2)) & 127;
  int stride_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_18_1) & 63;
  aux_2 = (aux_2 + stride_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_94_1 > 46)
  {
    acc_1 = ((acc_1 + (phase_94_1 * 2)) + 5) & 127;
    aux_1 ^= phase_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_94_2 > 46)
  {
    acc_2 = ((acc_2 + (phase_94_2 * 2)) + 5) & 127;
    aux_2 ^= phase_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_94_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
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

  assert(phase_81_1 == phase_81_2);
  assert(stride_18_1 == stride_18_2);
  assert(phase_94_1 == phase_94_2);
}

int fn_R001015_1513_12(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001015_1513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int phase_81 = local_arr[aux % 3];
  acc = (acc + (phase_81 * 2)) & 127;
  int stride_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_18) & 63;
  acc ^= aux;
  int phase_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_94 > 46)
  {
    acc = ((acc + (phase_94 * 2)) + 5) & 127;
    aux ^= phase_94 & 15;
  }
  else
  {
    acc = ((acc - phase_94) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001015_1513_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001015_1513_2 st_1 = {0};
  struct MatrixBlock_R001015_1513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int offset_86_1 = 0;
  int offset_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_86_1 = ((offset_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_86_2 = ((offset_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_86_1) & 127;
    acc_2 = (acc_2 + offset_86_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_19_1 = local_arr_1[aux_1 % 3];
  int damping_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_19_2 * 2)) & 127;
  int segment_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_78_1 > 26)
  {
    acc_1 = ((acc_1 + (segment_78_1 * 2)) + 5) & 127;
    aux_1 ^= segment_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_78_2 > 26)
  {
    acc_2 = ((acc_2 + (segment_78_2 * 2)) + 5) & 127;
    aux_2 ^= segment_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_78_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_86_1 == offset_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_19_1 == damping_19_2);
  assert(segment_78_1 == segment_78_2);
}

int fn_R001015_1513_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001015_1513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int offset_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_86 = ((offset_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_86) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int damping_19 = local_arr[aux % 3];
  acc = (acc + (damping_19 * 2)) & 127;
  int segment_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_78 > 26)
  {
    acc = ((acc + (segment_78 * 2)) + 5) & 127;
    aux ^= segment_78 & 15;
  }
  else
  {
    acc = ((acc - segment_78) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001015_1513_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001015_1513_0 st_1 = {0};
  struct DeviceConfig_R001015_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_90_1 = local_arr_1[aux_1 % 3];
  int index_reg_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_90_1 == index_reg_90_2);
}

int fn_R001015_1513_14(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001015_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int index_reg_90 = local_arr[aux % 3];
  acc = (acc + (index_reg_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001015_1513_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001015_1513_1 st_1 = {0};
  struct SensorNode_R001015_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int mask_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_18_1 > 30)
  {
    acc_1 = ((acc_1 + (mask_18_1 * 2)) + 5) & 127;
    aux_1 ^= mask_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_18_2 > 30)
  {
    acc_2 = ((acc_2 + (mask_18_2 * 2)) + 5) & 127;
    aux_2 ^= mask_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_19_1 = local_arr_1[aux_1 % 3];
  int checksum_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_19_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_18_1 == mask_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_19_1 == checksum_19_2);
}

int fn_R001015_1513_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001015_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int mask_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_18 > 30)
  {
    acc = ((acc + (mask_18 * 2)) + 5) & 127;
    aux ^= mask_18 & 15;
  }
  else
  {
    acc = ((acc - mask_18) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_19 = local_arr[aux % 3];
  acc = (acc + (checksum_19 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001015_1513_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001015_1513_0 st_1 = {0};
  struct DeviceConfig_R001015_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int mask_99_1 = 0;
  int mask_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_99_1 = ((mask_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_99_2 = ((mask_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_99_1) & 127;
    acc_2 = (acc_2 + mask_99_2) & 127;
  }

  int quantum_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_46_1)
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

  switch (quantum_46_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_99_1 == mask_99_2);
  assert(quantum_46_1 == quantum_46_2);
}

int fn_R001015_1513_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001015_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int mask_99 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_99 = ((mask_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_99) & 127;
  }

  int quantum_46 = (aux + st.buffer[1]) & 3;
  switch (quantum_46)
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

void fn_R001015_1513_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001015_1513_2 st_1 = {0};
  struct MatrixBlock_R001015_1513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int phase_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_68_1)
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

  switch (phase_68_2)
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

  int segment_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_41_1) & 63;
  aux_2 = (aux_2 + segment_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_71_1 = local_arr_1[aux_1 % 3];
  int delta_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_71_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_68_1 == phase_68_2);
  assert(segment_41_1 == segment_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_71_1 == delta_71_2);
}

int fn_R001015_1513_17(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001015_1513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int phase_68 = (aux + st.buffer[1]) & 3;
  switch (phase_68)
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

  int segment_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_41) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int delta_71 = local_arr[aux % 3];
  acc = (acc + (delta_71 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001015_1513_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001015_1513_1 st_1 = {0};
  struct SensorNode_R001015_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_76_1 = local_arr_1[aux_1 % 3];
  int metric_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_76_2 * 2)) & 127;
  int mask_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_48_1) & 63;
  aux_2 = (aux_2 + mask_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_76_1 == metric_76_2);
  assert(mask_48_1 == mask_48_2);
}

int fn_R001015_1513_18(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001015_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int metric_76 = local_arr[aux % 3];
  acc = (acc + (metric_76 * 2)) & 127;
  int mask_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_48) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001015_1513_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001015_1513_0 st_1 = {0};
  struct DeviceConfig_R001015_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int index_reg_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_80_1) & 63;
  aux_2 = (aux_2 + index_reg_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_38_1 > 23)
  {
    acc_1 = ((acc_1 + (margin_38_1 * 2)) + 5) & 127;
    aux_1 ^= margin_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_38_2 > 23)
  {
    acc_2 = ((acc_2 + (margin_38_2 * 2)) + 5) & 127;
    aux_2 ^= margin_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_38_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_80_1 == index_reg_80_2);
  assert(margin_38_1 == margin_38_2);
}

int fn_R001015_1513_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001015_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int index_reg_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_80) & 63;
  acc ^= aux;
  int margin_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_38 > 23)
  {
    acc = ((acc + (margin_38 * 2)) + 5) & 127;
    aux ^= margin_38 & 15;
  }
  else
  {
    acc = ((acc - margin_38) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001015_0_1;
  int sec_r001015_0_2;
  int sec_r001015_1_1;
  int sec_r001015_1_2;
  int sec_r001015_2_1;
  int sec_r001015_2_2;
  int sec_r001015_3_1;
  int sec_r001015_3_2;
  int sec_r001015_4_1;
  int sec_r001015_4_2;
  int sec_r001015_5_1;
  int sec_r001015_5_2;
  int sec_r001015_6_1;
  int sec_r001015_6_2;
  int sec_r001015_7_1;
  int sec_r001015_7_2;
  int sec_r001015_8_1;
  int sec_r001015_8_2;
  int sec_r001015_9_1;
  int sec_r001015_9_2;
  int sec_r001015_10_1;
  int sec_r001015_10_2;
  int sec_r001015_11_1;
  int sec_r001015_11_2;
  int sec_r001015_12_1;
  int sec_r001015_12_2;
  int sec_r001015_13_1;
  int sec_r001015_13_2;
  int sec_r001015_14_1;
  int sec_r001015_14_2;
  int sec_r001015_15_1;
  int sec_r001015_15_2;
  int sec_r001015_16_1;
  int sec_r001015_16_2;
  int sec_r001015_17_1;
  int sec_r001015_17_2;
  int sec_r001015_18_1;
  int sec_r001015_18_2;
  int sec_r001015_19_1;
  int sec_r001015_19_2;
  int pub_r001015_0_1;
  int pub_r001015_0_2;
  int pub_r001015_1_1;
  int pub_r001015_1_2;
  int pub_r001015_2_1;
  int pub_r001015_2_2;
  int pub_r001015_3_1;
  int pub_r001015_3_2;
  int pub_r001015_4_1;
  int pub_r001015_4_2;
  int pub_r001015_5_1;
  int pub_r001015_5_2;
  int pub_r001015_6_1;
  int pub_r001015_6_2;
  int pub_r001015_7_1;
  int pub_r001015_7_2;
  int pub_r001015_8_1;
  int pub_r001015_8_2;
  int pub_r001015_9_1;
  int pub_r001015_9_2;
  int pub_r001015_10_1;
  int pub_r001015_10_2;
  int pub_r001015_11_1;
  int pub_r001015_11_2;
  int pub_r001015_12_1;
  int pub_r001015_12_2;
  int pub_r001015_13_1;
  int pub_r001015_13_2;
  int pub_r001015_14_1;
  int pub_r001015_14_2;
  int pub_r001015_15_1;
  int pub_r001015_15_2;
  int pub_r001015_16_1;
  int pub_r001015_16_2;
  int pub_r001015_17_1;
  int pub_r001015_17_2;
  int pub_r001015_18_1;
  int pub_r001015_18_2;
  int pub_r001015_19_1;
  int pub_r001015_19_2;
  int pub_r001015_20_1;
  int pub_r001015_20_2;
  int pub_r001015_21_1;
  int pub_r001015_21_2;
  int pub_r001015_22_1;
  int pub_r001015_22_2;
  int pub_r001015_23_1;
  int pub_r001015_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001015_0_1 >= (-100)) && (pub_r001015_0_1 <= 100));
  __CPROVER_assume((pub_r001015_0_2 >= (-100)) && (pub_r001015_0_2 <= 100));
  __CPROVER_assume((pub_r001015_1_1 >= (-100)) && (pub_r001015_1_1 <= 100));
  __CPROVER_assume((pub_r001015_1_2 >= (-100)) && (pub_r001015_1_2 <= 100));
  __CPROVER_assume((pub_r001015_2_1 >= (-100)) && (pub_r001015_2_1 <= 100));
  __CPROVER_assume((pub_r001015_2_2 >= (-100)) && (pub_r001015_2_2 <= 100));
  __CPROVER_assume((pub_r001015_3_1 >= (-100)) && (pub_r001015_3_1 <= 100));
  __CPROVER_assume((pub_r001015_3_2 >= (-100)) && (pub_r001015_3_2 <= 100));
  __CPROVER_assume((pub_r001015_4_1 >= (-100)) && (pub_r001015_4_1 <= 100));
  __CPROVER_assume((pub_r001015_4_2 >= (-100)) && (pub_r001015_4_2 <= 100));
  __CPROVER_assume((pub_r001015_5_1 >= (-100)) && (pub_r001015_5_1 <= 100));
  __CPROVER_assume((pub_r001015_5_2 >= (-100)) && (pub_r001015_5_2 <= 100));
  __CPROVER_assume((pub_r001015_6_1 >= (-100)) && (pub_r001015_6_1 <= 100));
  __CPROVER_assume((pub_r001015_6_2 >= (-100)) && (pub_r001015_6_2 <= 100));
  __CPROVER_assume((pub_r001015_7_1 >= (-100)) && (pub_r001015_7_1 <= 100));
  __CPROVER_assume((pub_r001015_7_2 >= (-100)) && (pub_r001015_7_2 <= 100));
  __CPROVER_assume((pub_r001015_8_1 >= (-100)) && (pub_r001015_8_1 <= 100));
  __CPROVER_assume((pub_r001015_8_2 >= (-100)) && (pub_r001015_8_2 <= 100));
  __CPROVER_assume((pub_r001015_9_1 >= (-100)) && (pub_r001015_9_1 <= 100));
  __CPROVER_assume((pub_r001015_9_2 >= (-100)) && (pub_r001015_9_2 <= 100));
  __CPROVER_assume((pub_r001015_10_1 >= (-100)) && (pub_r001015_10_1 <= 100));
  __CPROVER_assume((pub_r001015_10_2 >= (-100)) && (pub_r001015_10_2 <= 100));
  __CPROVER_assume((pub_r001015_11_1 >= (-100)) && (pub_r001015_11_1 <= 100));
  __CPROVER_assume((pub_r001015_11_2 >= (-100)) && (pub_r001015_11_2 <= 100));
  __CPROVER_assume((pub_r001015_12_1 >= (-100)) && (pub_r001015_12_1 <= 100));
  __CPROVER_assume((pub_r001015_12_2 >= (-100)) && (pub_r001015_12_2 <= 100));
  __CPROVER_assume((pub_r001015_13_1 >= (-100)) && (pub_r001015_13_1 <= 100));
  __CPROVER_assume((pub_r001015_13_2 >= (-100)) && (pub_r001015_13_2 <= 100));
  __CPROVER_assume((pub_r001015_14_1 >= (-100)) && (pub_r001015_14_1 <= 100));
  __CPROVER_assume((pub_r001015_14_2 >= (-100)) && (pub_r001015_14_2 <= 100));
  __CPROVER_assume((pub_r001015_15_1 >= (-100)) && (pub_r001015_15_1 <= 100));
  __CPROVER_assume((pub_r001015_15_2 >= (-100)) && (pub_r001015_15_2 <= 100));
  __CPROVER_assume((pub_r001015_16_1 >= (-100)) && (pub_r001015_16_1 <= 100));
  __CPROVER_assume((pub_r001015_16_2 >= (-100)) && (pub_r001015_16_2 <= 100));
  __CPROVER_assume((pub_r001015_17_1 >= (-100)) && (pub_r001015_17_1 <= 100));
  __CPROVER_assume((pub_r001015_17_2 >= (-100)) && (pub_r001015_17_2 <= 100));
  __CPROVER_assume((pub_r001015_18_1 >= (-100)) && (pub_r001015_18_1 <= 100));
  __CPROVER_assume((pub_r001015_18_2 >= (-100)) && (pub_r001015_18_2 <= 100));
  __CPROVER_assume((pub_r001015_19_1 >= (-100)) && (pub_r001015_19_1 <= 100));
  __CPROVER_assume((pub_r001015_19_2 >= (-100)) && (pub_r001015_19_2 <= 100));
  __CPROVER_assume((pub_r001015_20_1 >= (-100)) && (pub_r001015_20_1 <= 100));
  __CPROVER_assume((pub_r001015_20_2 >= (-100)) && (pub_r001015_20_2 <= 100));
  __CPROVER_assume((pub_r001015_21_1 >= (-100)) && (pub_r001015_21_1 <= 100));
  __CPROVER_assume((pub_r001015_21_2 >= (-100)) && (pub_r001015_21_2 <= 100));
  __CPROVER_assume((pub_r001015_22_1 >= (-100)) && (pub_r001015_22_1 <= 100));
  __CPROVER_assume((pub_r001015_22_2 >= (-100)) && (pub_r001015_22_2 <= 100));
  __CPROVER_assume((pub_r001015_23_1 >= (-100)) && (pub_r001015_23_1 <= 100));
  __CPROVER_assume((pub_r001015_23_2 >= (-100)) && (pub_r001015_23_2 <= 100));
  __CPROVER_assume((sec_r001015_0_1 >= 0) && (sec_r001015_0_1 <= 255));
  __CPROVER_assume((sec_r001015_0_2 >= 0) && (sec_r001015_0_2 <= 255));
  __CPROVER_assume((sec_r001015_1_1 >= 0) && (sec_r001015_1_1 <= 255));
  __CPROVER_assume((sec_r001015_1_2 >= 0) && (sec_r001015_1_2 <= 255));
  __CPROVER_assume((sec_r001015_2_1 >= 0) && (sec_r001015_2_1 <= 255));
  __CPROVER_assume((sec_r001015_2_2 >= 0) && (sec_r001015_2_2 <= 255));
  __CPROVER_assume((sec_r001015_3_1 >= 0) && (sec_r001015_3_1 <= 255));
  __CPROVER_assume((sec_r001015_3_2 >= 0) && (sec_r001015_3_2 <= 255));
  __CPROVER_assume((sec_r001015_4_1 >= 0) && (sec_r001015_4_1 <= 255));
  __CPROVER_assume((sec_r001015_4_2 >= 0) && (sec_r001015_4_2 <= 255));
  __CPROVER_assume((sec_r001015_5_1 >= 0) && (sec_r001015_5_1 <= 255));
  __CPROVER_assume((sec_r001015_5_2 >= 0) && (sec_r001015_5_2 <= 255));
  __CPROVER_assume((sec_r001015_6_1 >= 0) && (sec_r001015_6_1 <= 255));
  __CPROVER_assume((sec_r001015_6_2 >= 0) && (sec_r001015_6_2 <= 255));
  __CPROVER_assume((sec_r001015_7_1 >= 0) && (sec_r001015_7_1 <= 255));
  __CPROVER_assume((sec_r001015_7_2 >= 0) && (sec_r001015_7_2 <= 255));
  __CPROVER_assume((sec_r001015_8_1 >= 0) && (sec_r001015_8_1 <= 255));
  __CPROVER_assume((sec_r001015_8_2 >= 0) && (sec_r001015_8_2 <= 255));
  __CPROVER_assume((sec_r001015_9_1 >= 0) && (sec_r001015_9_1 <= 255));
  __CPROVER_assume((sec_r001015_9_2 >= 0) && (sec_r001015_9_2 <= 255));
  __CPROVER_assume((sec_r001015_10_1 >= 0) && (sec_r001015_10_1 <= 255));
  __CPROVER_assume((sec_r001015_10_2 >= 0) && (sec_r001015_10_2 <= 255));
  __CPROVER_assume((sec_r001015_11_1 >= 0) && (sec_r001015_11_1 <= 255));
  __CPROVER_assume((sec_r001015_11_2 >= 0) && (sec_r001015_11_2 <= 255));
  __CPROVER_assume((sec_r001015_12_1 >= 0) && (sec_r001015_12_1 <= 255));
  __CPROVER_assume((sec_r001015_12_2 >= 0) && (sec_r001015_12_2 <= 255));
  __CPROVER_assume((sec_r001015_13_1 >= 0) && (sec_r001015_13_1 <= 255));
  __CPROVER_assume((sec_r001015_13_2 >= 0) && (sec_r001015_13_2 <= 255));
  __CPROVER_assume((sec_r001015_14_1 >= 0) && (sec_r001015_14_1 <= 255));
  __CPROVER_assume((sec_r001015_14_2 >= 0) && (sec_r001015_14_2 <= 255));
  __CPROVER_assume((sec_r001015_15_1 >= 0) && (sec_r001015_15_1 <= 255));
  __CPROVER_assume((sec_r001015_15_2 >= 0) && (sec_r001015_15_2 <= 255));
  __CPROVER_assume((sec_r001015_16_1 >= 0) && (sec_r001015_16_1 <= 255));
  __CPROVER_assume((sec_r001015_16_2 >= 0) && (sec_r001015_16_2 <= 255));
  __CPROVER_assume((sec_r001015_17_1 >= 0) && (sec_r001015_17_1 <= 255));
  __CPROVER_assume((sec_r001015_17_2 >= 0) && (sec_r001015_17_2 <= 255));
  __CPROVER_assume((sec_r001015_18_1 >= 0) && (sec_r001015_18_1 <= 255));
  __CPROVER_assume((sec_r001015_18_2 >= 0) && (sec_r001015_18_2 <= 255));
  __CPROVER_assume((sec_r001015_19_1 >= 0) && (sec_r001015_19_1 <= 255));
  __CPROVER_assume((sec_r001015_19_2 >= 0) && (sec_r001015_19_2 <= 255));
  struct DeviceConfig_R001015_1513_0 st_var_0_1 = {0};
  struct DeviceConfig_R001015_1513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001015_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001015_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001015_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001015_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001015_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001015_0_2 + 7) & 15;
  struct SensorNode_R001015_1513_1 st_var_1_1 = {0};
  struct SensorNode_R001015_1513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001015_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001015_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001015_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001015_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001015_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001015_0_2 + 9) & 15;
  struct MatrixBlock_R001015_1513_2 st_var_2_1 = {0};
  struct MatrixBlock_R001015_1513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001015_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001015_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001015_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001015_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001015_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001015_0_2 + 11) & 15;
  union ColorPixel_R001015_1513_0 u_var_1;
  union ColorPixel_R001015_1513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001015_1513_0(sec_r001015_0_1, pub_r001015_1_1, pub_r001015_2_1, pub_r001015_3_1, pub_r001015_4_1);
  int helper_flow_0_2 = fn_R001015_1513_0(sec_r001015_0_2, pub_r001015_1_2, pub_r001015_2_2, pub_r001015_3_2, pub_r001015_4_2);
  fn_R001015_1513_0_2(sec_r001015_0_1, pub_r001015_1_1, pub_r001015_2_1, pub_r001015_3_1, pub_r001015_4_1, sec_r001015_0_2, pub_r001015_1_2, pub_r001015_2_2, pub_r001015_3_2, pub_r001015_4_2);
  int helper_flow_1_1 = fn_R001015_1513_1(sec_r001015_1_1, sec_r001015_2_1, pub_r001015_3_1, pub_r001015_4_1);
  int helper_flow_1_2 = fn_R001015_1513_1(sec_r001015_1_2, sec_r001015_2_2, pub_r001015_3_2, pub_r001015_4_2);
  fn_R001015_1513_1_2(sec_r001015_1_1, sec_r001015_2_1, pub_r001015_3_1, pub_r001015_4_1, sec_r001015_1_2, sec_r001015_2_2, pub_r001015_3_2, pub_r001015_4_2);
  int helper_flow_2_1 = fn_R001015_1513_2(sec_r001015_2_1, sec_r001015_3_1, pub_r001015_4_1);
  int helper_flow_2_2 = fn_R001015_1513_2(sec_r001015_2_2, sec_r001015_3_2, pub_r001015_4_2);
  fn_R001015_1513_2_2(sec_r001015_2_1, sec_r001015_3_1, pub_r001015_4_1, sec_r001015_2_2, sec_r001015_3_2, pub_r001015_4_2);
  int helper_flow_3_1 = fn_R001015_1513_3(sec_r001015_3_1, sec_r001015_4_1);
  int helper_flow_3_2 = fn_R001015_1513_3(sec_r001015_3_2, sec_r001015_4_2);
  fn_R001015_1513_3_2(sec_r001015_3_1, sec_r001015_4_1, sec_r001015_3_2, sec_r001015_4_2);
  int helper_flow_4_1 = fn_R001015_1513_4(sec_r001015_4_1, sec_r001015_5_1, pub_r001015_6_1, pub_r001015_7_1, pub_r001015_8_1);
  int helper_flow_4_2 = fn_R001015_1513_4(sec_r001015_4_2, sec_r001015_5_2, pub_r001015_6_2, pub_r001015_7_2, pub_r001015_8_2);
  fn_R001015_1513_4_2(sec_r001015_4_1, sec_r001015_5_1, pub_r001015_6_1, pub_r001015_7_1, pub_r001015_8_1, sec_r001015_4_2, sec_r001015_5_2, pub_r001015_6_2, pub_r001015_7_2, pub_r001015_8_2);
  int helper_flow_5_1 = fn_R001015_1513_5(sec_r001015_5_1, sec_r001015_6_1, pub_r001015_7_1);
  int helper_flow_5_2 = fn_R001015_1513_5(sec_r001015_5_2, sec_r001015_6_2, pub_r001015_7_2);
  fn_R001015_1513_5_2(sec_r001015_5_1, sec_r001015_6_1, pub_r001015_7_1, sec_r001015_5_2, sec_r001015_6_2, pub_r001015_7_2);
  int helper_flow_6_1 = fn_R001015_1513_6(sec_r001015_6_1, sec_r001015_7_1, pub_r001015_8_1);
  int helper_flow_6_2 = fn_R001015_1513_6(sec_r001015_6_2, sec_r001015_7_2, pub_r001015_8_2);
  fn_R001015_1513_6_2(sec_r001015_6_1, sec_r001015_7_1, pub_r001015_8_1, sec_r001015_6_2, sec_r001015_7_2, pub_r001015_8_2);
  int helper_flow_7_1 = fn_R001015_1513_7(sec_r001015_7_1, sec_r001015_8_1, pub_r001015_9_1, pub_r001015_10_1);
  int helper_flow_7_2 = fn_R001015_1513_7(sec_r001015_7_2, sec_r001015_8_2, pub_r001015_9_2, pub_r001015_10_2);
  fn_R001015_1513_7_2(sec_r001015_7_1, sec_r001015_8_1, pub_r001015_9_1, pub_r001015_10_1, sec_r001015_7_2, sec_r001015_8_2, pub_r001015_9_2, pub_r001015_10_2);
  int stage_v_0_1 = ((sec_r001015_6_1 << 1) ^ (pub_r001015_22_1 >> 1)) & 127;
  int stage_v_0_2 = ((sec_r001015_6_2 << 1) ^ (pub_r001015_22_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_0_2 + 1) & 15;
  out_sink_1 ^= stage_v_0_1 & 63;
  out_sink_2 ^= stage_v_0_2 & 63;
  int stage_v_1_1 = ((sec_r001015_10_1 << 1) ^ (pub_r001015_18_1 >> 1)) & 127;
  int stage_v_1_2 = ((sec_r001015_10_2 << 1) ^ (pub_r001015_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_1_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_1_2 + 1) & 15;
  out_sink_1 ^= stage_v_1_1 & 63;
  out_sink_2 ^= stage_v_1_2 & 63;
  int stage_v_2_1 = ((pub_r001015_0_1 * 2) + 8) & 63;
  int stage_v_2_2 = ((pub_r001015_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((sec_r001015_9_1 << 1) ^ (pub_r001015_22_1 >> 1)) & 127;
  int stage_v_3_2 = ((sec_r001015_9_2 << 1) ^ (pub_r001015_22_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_3_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_3_2 + 1) & 15;
  out_sink_1 ^= stage_v_3_1 & 63;
  out_sink_2 ^= stage_v_3_2 & 63;
  int stage_v_4_1 = ((helper_flow_3_1 << 1) ^ (pub_r001015_1_1 >> 1)) & 127;
  int stage_v_4_2 = ((helper_flow_3_2 << 1) ^ (pub_r001015_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_4_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_4_2 + 1) & 15;
  out_sink_1 ^= stage_v_4_1 & 63;
  out_sink_2 ^= stage_v_4_2 & 63;
  int stage_v_5_1 = ((stage_v_0_1 << 1) ^ (pub_r001015_11_1 >> 1)) & 127;
  int stage_v_5_2 = ((stage_v_0_2 << 1) ^ (pub_r001015_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_5_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_5_2 + 1) & 15;
  out_sink_1 ^= stage_v_5_1 & 63;
  out_sink_2 ^= stage_v_5_2 & 63;
  int stage_v_6_1 = ((pub_r001015_1_1 * 2) + 28) & 63;
  int stage_v_6_2 = ((pub_r001015_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001015_2_1 * 2) + 25) & 63;
  int stage_v_7_2 = ((pub_r001015_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001015_4_1 * 2) + 39) & 63;
  int stage_v_8_2 = ((pub_r001015_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001015_17_1 * 2) + 9) & 63;
  int stage_v_9_2 = ((pub_r001015_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((sec_r001015_0_1 << 1) ^ (pub_r001015_14_1 >> 1)) & 127;
  int stage_v_10_2 = ((sec_r001015_0_2 << 1) ^ (pub_r001015_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_10_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_10_2 + 1) & 15;
  out_sink_1 ^= stage_v_10_1 & 63;
  out_sink_2 ^= stage_v_10_2 & 63;
  int stage_v_11_1 = ((pub_r001015_10_1 * 2) + 41) & 63;
  int stage_v_11_2 = ((pub_r001015_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((helper_flow_7_1 << 1) ^ (pub_r001015_2_1 >> 1)) & 127;
  int stage_v_12_2 = ((helper_flow_7_2 << 1) ^ (pub_r001015_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_12_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_12_2 + 1) & 15;
  out_sink_1 ^= stage_v_12_1 & 63;
  out_sink_2 ^= stage_v_12_2 & 63;
  int stage_v_13_1 = ((pub_r001015_4_1 * 2) + 24) & 63;
  int stage_v_13_2 = ((pub_r001015_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001015_8_1 * 2) + 44) & 63;
  int stage_v_14_2 = ((pub_r001015_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001015_15_1 * 2) + 45) & 63;
  int stage_v_15_2 = ((pub_r001015_15_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((helper_flow_6_1 << 1) ^ (pub_r001015_22_1 >> 1)) & 127;
  int stage_v_16_2 = ((helper_flow_6_2 << 1) ^ (pub_r001015_22_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_16_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_16_2 + 1) & 15;
  out_sink_1 ^= stage_v_16_1 & 63;
  out_sink_2 ^= stage_v_16_2 & 63;
  int stage_v_17_1 = ((stage_v_12_1 << 1) ^ (pub_r001015_23_1 >> 1)) & 127;
  int stage_v_17_2 = ((stage_v_12_2 << 1) ^ (pub_r001015_23_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_17_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_17_2 + 1) & 15;
  out_sink_1 ^= stage_v_17_1 & 63;
  out_sink_2 ^= stage_v_17_2 & 63;
  int stage_v_18_1 = ((pub_r001015_19_1 * 2) + 44) & 63;
  int stage_v_18_2 = ((pub_r001015_19_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((stage_v_4_1 << 1) ^ (pub_r001015_9_1 >> 1)) & 127;
  int stage_v_19_2 = ((stage_v_4_2 << 1) ^ (pub_r001015_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_19_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_19_2 + 1) & 15;
  out_sink_1 ^= stage_v_19_1 & 63;
  out_sink_2 ^= stage_v_19_2 & 63;
  int stage_v_20_1 = ((sec_r001015_9_1 << 1) ^ (pub_r001015_6_1 >> 1)) & 127;
  int stage_v_20_2 = ((sec_r001015_9_2 << 1) ^ (pub_r001015_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_20_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_20_2 + 1) & 15;
  out_sink_1 ^= stage_v_20_1 & 63;
  out_sink_2 ^= stage_v_20_2 & 63;
  int stage_v_21_1 = ((pub_r001015_16_1 * 2) + 7) & 63;
  int stage_v_21_2 = ((pub_r001015_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001015_13_1 * 2) + 21) & 63;
  int stage_v_22_2 = ((pub_r001015_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((stage_v_5_1 << 1) ^ (pub_r001015_23_1 >> 1)) & 127;
  int stage_v_23_2 = ((stage_v_5_2 << 1) ^ (pub_r001015_23_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_23_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_23_2 + 1) & 15;
  out_sink_1 ^= stage_v_23_1 & 63;
  out_sink_2 ^= stage_v_23_2 & 63;
  int stage_v_24_1 = ((pub_r001015_9_1 * 2) + 14) & 63;
  int stage_v_24_2 = ((pub_r001015_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((sec_r001015_2_1 << 1) ^ (pub_r001015_7_1 >> 1)) & 127;
  int stage_v_25_2 = ((sec_r001015_2_2 << 1) ^ (pub_r001015_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_25_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_25_2 + 1) & 15;
  out_sink_1 ^= stage_v_25_1 & 63;
  out_sink_2 ^= stage_v_25_2 & 63;
  int stage_v_26_1 = ((pub_r001015_19_1 * 2) + 6) & 63;
  int stage_v_26_2 = ((pub_r001015_19_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((sec_r001015_1_1 << 1) ^ (pub_r001015_16_1 >> 1)) & 127;
  int stage_v_27_2 = ((sec_r001015_1_2 << 1) ^ (pub_r001015_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_27_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_27_2 + 1) & 15;
  out_sink_1 ^= stage_v_27_1 & 63;
  out_sink_2 ^= stage_v_27_2 & 63;
  int stage_v_28_1 = ((pub_r001015_1_1 * 2) + 23) & 63;
  int stage_v_28_2 = ((pub_r001015_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((sec_r001015_13_1 << 1) ^ (pub_r001015_10_1 >> 1)) & 127;
  int stage_v_29_2 = ((sec_r001015_13_2 << 1) ^ (pub_r001015_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_29_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_29_2 + 1) & 15;
  out_sink_1 ^= stage_v_29_1 & 63;
  out_sink_2 ^= stage_v_29_2 & 63;
  int stage_v_30_1 = ((pub_r001015_21_1 * 2) + 22) & 63;
  int stage_v_30_2 = ((pub_r001015_21_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((sec_r001015_10_1 << 1) ^ (pub_r001015_23_1 >> 1)) & 127;
  int stage_v_31_2 = ((sec_r001015_10_2 << 1) ^ (pub_r001015_23_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_31_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_31_2 + 1) & 15;
  out_sink_1 ^= stage_v_31_1 & 63;
  out_sink_2 ^= stage_v_31_2 & 63;
  int stage_v_32_1 = ((pub_r001015_21_1 * 2) + 39) & 63;
  int stage_v_32_2 = ((pub_r001015_21_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((sec_r001015_9_1 << 1) ^ (pub_r001015_19_1 >> 1)) & 127;
  int stage_v_33_2 = ((sec_r001015_9_2 << 1) ^ (pub_r001015_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_33_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_33_2 + 1) & 15;
  out_sink_1 ^= stage_v_33_1 & 63;
  out_sink_2 ^= stage_v_33_2 & 63;
  int stage_v_34_1 = ((pub_r001015_6_1 * 2) + 36) & 63;
  int stage_v_34_2 = ((pub_r001015_6_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001015_9_1 * 2) + 50) & 63;
  int stage_v_35_2 = ((pub_r001015_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((sec_r001015_12_1 << 1) ^ (pub_r001015_16_1 >> 1)) & 127;
  int stage_v_36_2 = ((sec_r001015_12_2 << 1) ^ (pub_r001015_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_36_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_36_2 + 1) & 15;
  out_sink_1 ^= stage_v_36_1 & 63;
  out_sink_2 ^= stage_v_36_2 & 63;
  int stage_v_37_1 = ((pub_r001015_18_1 * 2) + 13) & 63;
  int stage_v_37_2 = ((pub_r001015_18_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((stage_v_25_1 << 1) ^ (pub_r001015_15_1 >> 1)) & 127;
  int stage_v_38_2 = ((stage_v_25_2 << 1) ^ (pub_r001015_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_38_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_38_2 + 1) & 15;
  out_sink_1 ^= stage_v_38_1 & 63;
  out_sink_2 ^= stage_v_38_2 & 63;
  int stage_v_39_1 = ((stage_v_16_1 << 1) ^ (pub_r001015_0_1 >> 1)) & 127;
  int stage_v_39_2 = ((stage_v_16_2 << 1) ^ (pub_r001015_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_39_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_39_2 + 1) & 15;
  out_sink_1 ^= stage_v_39_1 & 63;
  out_sink_2 ^= stage_v_39_2 & 63;
  int stage_v_40_1 = ((helper_flow_0_1 << 1) ^ (pub_r001015_16_1 >> 1)) & 127;
  int stage_v_40_2 = ((helper_flow_0_2 << 1) ^ (pub_r001015_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_40_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_40_2 + 1) & 15;
  out_sink_1 ^= stage_v_40_1 & 63;
  out_sink_2 ^= stage_v_40_2 & 63;
  int stage_v_41_1 = ((sec_r001015_19_1 << 1) ^ (pub_r001015_19_1 >> 1)) & 127;
  int stage_v_41_2 = ((sec_r001015_19_2 << 1) ^ (pub_r001015_19_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_41_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_41_2 + 1) & 15;
  out_sink_1 ^= stage_v_41_1 & 63;
  out_sink_2 ^= stage_v_41_2 & 63;
  int stage_v_42_1 = ((stage_v_4_1 << 1) ^ (pub_r001015_13_1 >> 1)) & 127;
  int stage_v_42_2 = ((stage_v_4_2 << 1) ^ (pub_r001015_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_42_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_42_2 + 1) & 15;
  out_sink_1 ^= stage_v_42_1 & 63;
  out_sink_2 ^= stage_v_42_2 & 63;
  int stage_v_43_1 = ((helper_flow_7_1 << 1) ^ (pub_r001015_6_1 >> 1)) & 127;
  int stage_v_43_2 = ((helper_flow_7_2 << 1) ^ (pub_r001015_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_43_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_43_2 + 1) & 15;
  out_sink_1 ^= stage_v_43_1 & 63;
  out_sink_2 ^= stage_v_43_2 & 63;
  int stage_v_44_1 = ((helper_flow_4_1 << 1) ^ (pub_r001015_20_1 >> 1)) & 127;
  int stage_v_44_2 = ((helper_flow_4_2 << 1) ^ (pub_r001015_20_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_44_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_44_2 + 1) & 15;
  out_sink_1 ^= stage_v_44_1 & 63;
  out_sink_2 ^= stage_v_44_2 & 63;
  int stage_v_45_1 = ((pub_r001015_10_1 * 2) + 38) & 63;
  int stage_v_45_2 = ((pub_r001015_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001015_3_1 * 2) + 7) & 63;
  int stage_v_46_2 = ((pub_r001015_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001015_14_1 * 2) + 18) & 63;
  int stage_v_47_2 = ((pub_r001015_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001015_3_1 * 2) + 33) & 63;
  int stage_v_48_2 = ((pub_r001015_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001015_13_1 * 2) + 30) & 63;
  int stage_v_49_2 = ((pub_r001015_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001015_8_1 * 2) + 14) & 63;
  int stage_v_50_2 = ((pub_r001015_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001015_23_1 * 2) + 10) & 63;
  int stage_v_51_2 = ((pub_r001015_23_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((helper_flow_6_1 << 1) ^ (pub_r001015_7_1 >> 1)) & 127;
  int stage_v_52_2 = ((helper_flow_6_2 << 1) ^ (pub_r001015_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_52_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_52_2 + 1) & 15;
  out_sink_1 ^= stage_v_52_1 & 63;
  out_sink_2 ^= stage_v_52_2 & 63;
  int stage_v_53_1 = ((pub_r001015_21_1 * 2) + 36) & 63;
  int stage_v_53_2 = ((pub_r001015_21_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((helper_flow_7_1 << 1) ^ (pub_r001015_1_1 >> 1)) & 127;
  int stage_v_54_2 = ((helper_flow_7_2 << 1) ^ (pub_r001015_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_54_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_54_2 + 1) & 15;
  out_sink_1 ^= stage_v_54_1 & 63;
  out_sink_2 ^= stage_v_54_2 & 63;
  int stage_v_55_1 = ((stage_v_12_1 << 1) ^ (pub_r001015_10_1 >> 1)) & 127;
  int stage_v_55_2 = ((stage_v_12_2 << 1) ^ (pub_r001015_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_55_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_55_2 + 1) & 15;
  out_sink_1 ^= stage_v_55_1 & 63;
  out_sink_2 ^= stage_v_55_2 & 63;
  int stage_v_56_1 = ((stage_v_29_1 << 1) ^ (pub_r001015_15_1 >> 1)) & 127;
  int stage_v_56_2 = ((stage_v_29_2 << 1) ^ (pub_r001015_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_56_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_56_2 + 1) & 15;
  out_sink_1 ^= stage_v_56_1 & 63;
  out_sink_2 ^= stage_v_56_2 & 63;
  int stage_v_57_1 = ((helper_flow_6_1 << 1) ^ (pub_r001015_14_1 >> 1)) & 127;
  int stage_v_57_2 = ((helper_flow_6_2 << 1) ^ (pub_r001015_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_57_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_57_2 + 1) & 15;
  out_sink_1 ^= stage_v_57_1 & 63;
  out_sink_2 ^= stage_v_57_2 & 63;
  int stage_v_58_1 = ((pub_r001015_6_1 * 2) + 7) & 63;
  int stage_v_58_2 = ((pub_r001015_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001015_3_1 * 2) + 40) & 63;
  int stage_v_59_2 = ((pub_r001015_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((stage_v_39_1 << 1) ^ (pub_r001015_13_1 >> 1)) & 127;
  int stage_v_60_2 = ((stage_v_39_2 << 1) ^ (pub_r001015_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_60_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_60_2 + 1) & 15;
  out_sink_1 ^= stage_v_60_1 & 63;
  out_sink_2 ^= stage_v_60_2 & 63;
  int stage_v_61_1 = ((stage_v_57_1 << 1) ^ (pub_r001015_10_1 >> 1)) & 127;
  int stage_v_61_2 = ((stage_v_57_2 << 1) ^ (pub_r001015_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_61_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_61_2 + 1) & 15;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = ((helper_flow_1_1 << 1) ^ (pub_r001015_19_1 >> 1)) & 127;
  int stage_v_62_2 = ((helper_flow_1_2 << 1) ^ (pub_r001015_19_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_62_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_62_2 + 1) & 15;
  out_sink_1 ^= stage_v_62_1 & 63;
  out_sink_2 ^= stage_v_62_2 & 63;
  int stage_v_63_1 = ((sec_r001015_14_1 << 1) ^ (pub_r001015_4_1 >> 1)) & 127;
  int stage_v_63_2 = ((sec_r001015_14_2 << 1) ^ (pub_r001015_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_63_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_63_2 + 1) & 15;
  out_sink_1 ^= stage_v_63_1 & 63;
  out_sink_2 ^= stage_v_63_2 & 63;
  int stage_v_64_1 = ((sec_r001015_4_1 << 1) ^ (pub_r001015_10_1 >> 1)) & 127;
  int stage_v_64_2 = ((sec_r001015_4_2 << 1) ^ (pub_r001015_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_64_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_64_2 + 1) & 15;
  out_sink_1 ^= stage_v_64_1 & 63;
  out_sink_2 ^= stage_v_64_2 & 63;
  int stage_v_65_1 = ((pub_r001015_13_1 * 2) + 18) & 63;
  int stage_v_65_2 = ((pub_r001015_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((sec_r001015_12_1 << 1) ^ (pub_r001015_7_1 >> 1)) & 127;
  int stage_v_66_2 = ((sec_r001015_12_2 << 1) ^ (pub_r001015_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_66_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_66_2 + 1) & 15;
  out_sink_1 ^= stage_v_66_1 & 63;
  out_sink_2 ^= stage_v_66_2 & 63;
  int stage_v_67_1 = ((sec_r001015_5_1 << 1) ^ (pub_r001015_22_1 >> 1)) & 127;
  int stage_v_67_2 = ((sec_r001015_5_2 << 1) ^ (pub_r001015_22_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_67_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_67_2 + 1) & 15;
  out_sink_1 ^= stage_v_67_1 & 63;
  out_sink_2 ^= stage_v_67_2 & 63;
  int stage_v_68_1 = ((pub_r001015_22_1 * 2) + 15) & 63;
  int stage_v_68_2 = ((pub_r001015_22_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001015_2_1 * 2) + 40) & 63;
  int stage_v_69_2 = ((pub_r001015_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((sec_r001015_1_1 << 1) ^ (pub_r001015_13_1 >> 1)) & 127;
  int stage_v_70_2 = ((sec_r001015_1_2 << 1) ^ (pub_r001015_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_70_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_70_2 + 1) & 15;
  out_sink_1 ^= stage_v_70_1 & 63;
  out_sink_2 ^= stage_v_70_2 & 63;
  int stage_v_71_1 = ((pub_r001015_23_1 * 2) + 37) & 63;
  int stage_v_71_2 = ((pub_r001015_23_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001015_0_1 * 2) + 11) & 63;
  int stage_v_72_2 = ((pub_r001015_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((stage_v_56_1 << 1) ^ (pub_r001015_19_1 >> 1)) & 127;
  int stage_v_73_2 = ((stage_v_56_2 << 1) ^ (pub_r001015_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_73_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_73_2 + 1) & 15;
  out_sink_1 ^= stage_v_73_1 & 63;
  out_sink_2 ^= stage_v_73_2 & 63;
  int stage_v_74_1 = ((pub_r001015_12_1 * 2) + 10) & 63;
  int stage_v_74_2 = ((pub_r001015_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((stage_v_4_1 << 1) ^ (pub_r001015_2_1 >> 1)) & 127;
  int stage_v_75_2 = ((stage_v_4_2 << 1) ^ (pub_r001015_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_75_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_75_2 + 1) & 15;
  out_sink_1 ^= stage_v_75_1 & 63;
  out_sink_2 ^= stage_v_75_2 & 63;
  int stage_v_76_1 = ((stage_v_0_1 << 1) ^ (pub_r001015_3_1 >> 1)) & 127;
  int stage_v_76_2 = ((stage_v_0_2 << 1) ^ (pub_r001015_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_76_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_76_2 + 1) & 15;
  out_sink_1 ^= stage_v_76_1 & 63;
  out_sink_2 ^= stage_v_76_2 & 63;
  int stage_v_77_1 = ((pub_r001015_5_1 * 2) + 23) & 63;
  int stage_v_77_2 = ((pub_r001015_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001015_0_1 * 2) + 15) & 63;
  int stage_v_78_2 = ((pub_r001015_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001015_7_1 * 2) + 46) & 63;
  int stage_v_79_2 = ((pub_r001015_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001015_16_1 * 2) + 25) & 63;
  int stage_v_80_2 = ((pub_r001015_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((stage_v_54_1 << 1) ^ (pub_r001015_1_1 >> 1)) & 127;
  int stage_v_81_2 = ((stage_v_54_2 << 1) ^ (pub_r001015_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_81_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_81_2 + 1) & 15;
  out_sink_1 ^= stage_v_81_1 & 63;
  out_sink_2 ^= stage_v_81_2 & 63;
  int stage_v_82_1 = ((helper_flow_0_1 << 1) ^ (pub_r001015_16_1 >> 1)) & 127;
  int stage_v_82_2 = ((helper_flow_0_2 << 1) ^ (pub_r001015_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_82_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_82_2 + 1) & 15;
  out_sink_1 ^= stage_v_82_1 & 63;
  out_sink_2 ^= stage_v_82_2 & 63;
  int stage_v_83_1 = ((pub_r001015_1_1 * 2) + 30) & 63;
  int stage_v_83_2 = ((pub_r001015_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001015_10_1 * 2) + 20) & 63;
  int stage_v_84_2 = ((pub_r001015_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001015_22_1 * 2) + 29) & 63;
  int stage_v_85_2 = ((pub_r001015_22_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((helper_flow_5_1 << 1) ^ (pub_r001015_11_1 >> 1)) & 127;
  int stage_v_86_2 = ((helper_flow_5_2 << 1) ^ (pub_r001015_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_86_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_86_2 + 1) & 15;
  out_sink_1 ^= stage_v_86_1 & 63;
  out_sink_2 ^= stage_v_86_2 & 63;
  int stage_v_87_1 = ((stage_v_17_1 << 1) ^ (pub_r001015_4_1 >> 1)) & 127;
  int stage_v_87_2 = ((stage_v_17_2 << 1) ^ (pub_r001015_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_87_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_87_2 + 1) & 15;
  out_sink_1 ^= stage_v_87_1 & 63;
  out_sink_2 ^= stage_v_87_2 & 63;
  int stage_v_88_1 = ((pub_r001015_4_1 * 2) + 34) & 63;
  int stage_v_88_2 = ((pub_r001015_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((sec_r001015_4_1 << 1) ^ (pub_r001015_17_1 >> 1)) & 127;
  int stage_v_89_2 = ((sec_r001015_4_2 << 1) ^ (pub_r001015_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_89_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_89_2 + 1) & 15;
  out_sink_1 ^= stage_v_89_1 & 63;
  out_sink_2 ^= stage_v_89_2 & 63;
  int stage_v_90_1 = ((pub_r001015_14_1 * 2) + 9) & 63;
  int stage_v_90_2 = ((pub_r001015_14_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001015_18_1 * 2) + 9) & 63;
  int stage_v_91_2 = ((pub_r001015_18_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((stage_v_41_1 << 1) ^ (pub_r001015_4_1 >> 1)) & 127;
  int stage_v_92_2 = ((stage_v_41_2 << 1) ^ (pub_r001015_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_92_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_92_2 + 1) & 15;
  out_sink_1 ^= stage_v_92_1 & 63;
  out_sink_2 ^= stage_v_92_2 & 63;
  int stage_v_93_1 = ((stage_v_36_1 << 1) ^ (pub_r001015_19_1 >> 1)) & 127;
  int stage_v_93_2 = ((stage_v_36_2 << 1) ^ (pub_r001015_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_93_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_93_2 + 1) & 15;
  out_sink_1 ^= stage_v_93_1 & 63;
  out_sink_2 ^= stage_v_93_2 & 63;
  int stage_v_94_1 = ((sec_r001015_1_1 << 1) ^ (pub_r001015_21_1 >> 1)) & 127;
  int stage_v_94_2 = ((sec_r001015_1_2 << 1) ^ (pub_r001015_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_94_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_94_2 + 1) & 15;
  out_sink_1 ^= stage_v_94_1 & 63;
  out_sink_2 ^= stage_v_94_2 & 63;
  int stage_v_95_1 = ((pub_r001015_0_1 * 2) + 15) & 63;
  int stage_v_95_2 = ((pub_r001015_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((stage_v_52_1 << 1) ^ (pub_r001015_13_1 >> 1)) & 127;
  int stage_v_96_2 = ((stage_v_52_2 << 1) ^ (pub_r001015_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_96_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_96_2 + 1) & 15;
  out_sink_1 ^= stage_v_96_1 & 63;
  out_sink_2 ^= stage_v_96_2 & 63;
  int stage_v_97_1 = ((stage_v_63_1 << 1) ^ (pub_r001015_7_1 >> 1)) & 127;
  int stage_v_97_2 = ((stage_v_63_2 << 1) ^ (pub_r001015_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_97_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_97_2 + 1) & 15;
  out_sink_1 ^= stage_v_97_1 & 63;
  out_sink_2 ^= stage_v_97_2 & 63;
  int stage_v_98_1 = ((pub_r001015_11_1 * 2) + 24) & 63;
  int stage_v_98_2 = ((pub_r001015_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((stage_v_57_1 << 1) ^ (pub_r001015_15_1 >> 1)) & 127;
  int stage_v_99_2 = ((stage_v_57_2 << 1) ^ (pub_r001015_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_99_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_99_2 + 1) & 15;
  out_sink_1 ^= stage_v_99_1 & 63;
  out_sink_2 ^= stage_v_99_2 & 63;
  int stage_v_100_1 = ((helper_flow_0_1 << 1) ^ (pub_r001015_1_1 >> 1)) & 127;
  int stage_v_100_2 = ((helper_flow_0_2 << 1) ^ (pub_r001015_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_100_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_100_2 + 1) & 15;
  out_sink_1 ^= stage_v_100_1 & 63;
  out_sink_2 ^= stage_v_100_2 & 63;
  int stage_v_101_1 = ((pub_r001015_21_1 * 2) + 14) & 63;
  int stage_v_101_2 = ((pub_r001015_21_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((stage_v_1_1 << 1) ^ (pub_r001015_9_1 >> 1)) & 127;
  int stage_v_102_2 = ((stage_v_1_2 << 1) ^ (pub_r001015_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_102_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_102_2 + 1) & 15;
  out_sink_1 ^= stage_v_102_1 & 63;
  out_sink_2 ^= stage_v_102_2 & 63;
  int stage_v_103_1 = ((pub_r001015_22_1 * 2) + 14) & 63;
  int stage_v_103_2 = ((pub_r001015_22_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((pub_r001015_7_1 * 2) + 18) & 63;
  int stage_v_104_2 = ((pub_r001015_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001015_7_1 * 2) + 22) & 63;
  int stage_v_105_2 = ((pub_r001015_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001015_13_1 * 2) + 27) & 63;
  int stage_v_106_2 = ((pub_r001015_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((stage_v_73_1 << 1) ^ (pub_r001015_17_1 >> 1)) & 127;
  int stage_v_107_2 = ((stage_v_73_2 << 1) ^ (pub_r001015_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_107_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_107_2 + 1) & 15;
  out_sink_1 ^= stage_v_107_1 & 63;
  out_sink_2 ^= stage_v_107_2 & 63;
  int stage_v_108_1 = ((pub_r001015_13_1 * 2) + 42) & 63;
  int stage_v_108_2 = ((pub_r001015_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001015_2_1 * 2) + 14) & 63;
  int stage_v_109_2 = ((pub_r001015_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001015_4_1 * 2) + 49) & 63;
  int stage_v_110_2 = ((pub_r001015_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((stage_v_76_1 << 1) ^ (pub_r001015_7_1 >> 1)) & 127;
  int stage_v_111_2 = ((stage_v_76_2 << 1) ^ (pub_r001015_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_111_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_111_2 + 1) & 15;
  out_sink_1 ^= stage_v_111_1 & 63;
  out_sink_2 ^= stage_v_111_2 & 63;
  int stage_v_112_1 = ((sec_r001015_14_1 << 1) ^ (pub_r001015_15_1 >> 1)) & 127;
  int stage_v_112_2 = ((sec_r001015_14_2 << 1) ^ (pub_r001015_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_112_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_112_2 + 1) & 15;
  out_sink_1 ^= stage_v_112_1 & 63;
  out_sink_2 ^= stage_v_112_2 & 63;
  int stage_v_113_1 = ((stage_v_61_1 << 1) ^ (pub_r001015_1_1 >> 1)) & 127;
  int stage_v_113_2 = ((stage_v_61_2 << 1) ^ (pub_r001015_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_113_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_113_2 + 1) & 15;
  out_sink_1 ^= stage_v_113_1 & 63;
  out_sink_2 ^= stage_v_113_2 & 63;
  int stage_v_114_1 = ((helper_flow_0_1 << 1) ^ (pub_r001015_9_1 >> 1)) & 127;
  int stage_v_114_2 = ((helper_flow_0_2 << 1) ^ (pub_r001015_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_114_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_114_2 + 1) & 15;
  out_sink_1 ^= stage_v_114_1 & 63;
  out_sink_2 ^= stage_v_114_2 & 63;
  int stage_v_115_1 = ((stage_v_54_1 << 1) ^ (pub_r001015_23_1 >> 1)) & 127;
  int stage_v_115_2 = ((stage_v_54_2 << 1) ^ (pub_r001015_23_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_115_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_115_2 + 1) & 15;
  out_sink_1 ^= stage_v_115_1 & 63;
  out_sink_2 ^= stage_v_115_2 & 63;
  int stage_v_116_1 = ((stage_v_70_1 << 1) ^ (pub_r001015_4_1 >> 1)) & 127;
  int stage_v_116_2 = ((stage_v_70_2 << 1) ^ (pub_r001015_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_116_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_116_2 + 1) & 15;
  out_sink_1 ^= stage_v_116_1 & 63;
  out_sink_2 ^= stage_v_116_2 & 63;
  int stage_v_117_1 = ((pub_r001015_13_1 * 2) + 30) & 63;
  int stage_v_117_2 = ((pub_r001015_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001015_20_1 * 2) + 9) & 63;
  int stage_v_118_2 = ((pub_r001015_20_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((sec_r001015_2_1 << 1) ^ (pub_r001015_15_1 >> 1)) & 127;
  int stage_v_119_2 = ((sec_r001015_2_2 << 1) ^ (pub_r001015_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_119_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_119_2 + 1) & 15;
  out_sink_1 ^= stage_v_119_1 & 63;
  out_sink_2 ^= stage_v_119_2 & 63;
  int stage_v_120_1 = ((pub_r001015_14_1 * 2) + 47) & 63;
  int stage_v_120_2 = ((pub_r001015_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((stage_v_40_1 << 1) ^ (pub_r001015_16_1 >> 1)) & 127;
  int stage_v_121_2 = ((stage_v_40_2 << 1) ^ (pub_r001015_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_121_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_121_2 + 1) & 15;
  out_sink_1 ^= stage_v_121_1 & 63;
  out_sink_2 ^= stage_v_121_2 & 63;
  int stage_v_122_1 = ((stage_v_39_1 << 1) ^ (pub_r001015_17_1 >> 1)) & 127;
  int stage_v_122_2 = ((stage_v_39_2 << 1) ^ (pub_r001015_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_122_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_122_2 + 1) & 15;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = ((stage_v_75_1 << 1) ^ (pub_r001015_1_1 >> 1)) & 127;
  int stage_v_123_2 = ((stage_v_75_2 << 1) ^ (pub_r001015_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_123_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_123_2 + 1) & 15;
  out_sink_1 ^= stage_v_123_1 & 63;
  out_sink_2 ^= stage_v_123_2 & 63;
  int stage_v_124_1 = ((stage_v_20_1 << 1) ^ (pub_r001015_3_1 >> 1)) & 127;
  int stage_v_124_2 = ((stage_v_20_2 << 1) ^ (pub_r001015_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_124_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_124_2 + 1) & 15;
  out_sink_1 ^= stage_v_124_1 & 63;
  out_sink_2 ^= stage_v_124_2 & 63;
  int stage_v_125_1 = ((sec_r001015_10_1 << 1) ^ (pub_r001015_13_1 >> 1)) & 127;
  int stage_v_125_2 = ((sec_r001015_10_2 << 1) ^ (pub_r001015_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_125_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_125_2 + 1) & 15;
  out_sink_1 ^= stage_v_125_1 & 63;
  out_sink_2 ^= stage_v_125_2 & 63;
  int stage_v_126_1 = ((pub_r001015_18_1 * 2) + 44) & 63;
  int stage_v_126_2 = ((pub_r001015_18_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((stage_v_86_1 << 1) ^ (pub_r001015_14_1 >> 1)) & 127;
  int stage_v_127_2 = ((stage_v_86_2 << 1) ^ (pub_r001015_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_127_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_127_2 + 1) & 15;
  out_sink_1 ^= stage_v_127_1 & 63;
  out_sink_2 ^= stage_v_127_2 & 63;
  int stage_v_128_1 = ((sec_r001015_16_1 << 1) ^ (pub_r001015_0_1 >> 1)) & 127;
  int stage_v_128_2 = ((sec_r001015_16_2 << 1) ^ (pub_r001015_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_128_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_128_2 + 1) & 15;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = ((stage_v_40_1 << 1) ^ (pub_r001015_4_1 >> 1)) & 127;
  int stage_v_129_2 = ((stage_v_40_2 << 1) ^ (pub_r001015_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_129_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_129_2 + 1) & 15;
  out_sink_1 ^= stage_v_129_1 & 63;
  out_sink_2 ^= stage_v_129_2 & 63;
  int stage_v_130_1 = ((pub_r001015_4_1 * 2) + 38) & 63;
  int stage_v_130_2 = ((pub_r001015_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((stage_v_127_1 << 1) ^ (pub_r001015_23_1 >> 1)) & 127;
  int stage_v_131_2 = ((stage_v_127_2 << 1) ^ (pub_r001015_23_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_131_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_131_2 + 1) & 15;
  out_sink_1 ^= stage_v_131_1 & 63;
  out_sink_2 ^= stage_v_131_2 & 63;
  int stage_v_132_1 = ((stage_v_31_1 << 1) ^ (pub_r001015_21_1 >> 1)) & 127;
  int stage_v_132_2 = ((stage_v_31_2 << 1) ^ (pub_r001015_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_132_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_132_2 + 1) & 15;
  out_sink_1 ^= stage_v_132_1 & 63;
  out_sink_2 ^= stage_v_132_2 & 63;
  int stage_v_133_1 = ((pub_r001015_3_1 * 2) + 15) & 63;
  int stage_v_133_2 = ((pub_r001015_3_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001015_21_1 * 2) + 5) & 63;
  int stage_v_134_2 = ((pub_r001015_21_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((sec_r001015_8_1 << 1) ^ (pub_r001015_9_1 >> 1)) & 127;
  int stage_v_135_2 = ((sec_r001015_8_2 << 1) ^ (pub_r001015_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_135_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_135_2 + 1) & 15;
  out_sink_1 ^= stage_v_135_1 & 63;
  out_sink_2 ^= stage_v_135_2 & 63;
  int stage_v_136_1 = ((pub_r001015_17_1 * 2) + 25) & 63;
  int stage_v_136_2 = ((pub_r001015_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001015_19_1 * 2) + 35) & 63;
  int stage_v_137_2 = ((pub_r001015_19_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001015_5_1 * 2) + 49) & 63;
  int stage_v_138_2 = ((pub_r001015_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((stage_v_89_1 << 1) ^ (pub_r001015_13_1 >> 1)) & 127;
  int stage_v_139_2 = ((stage_v_89_2 << 1) ^ (pub_r001015_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_139_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_139_2 + 1) & 15;
  out_sink_1 ^= stage_v_139_1 & 63;
  out_sink_2 ^= stage_v_139_2 & 63;
  int stage_v_140_1 = ((stage_v_64_1 << 1) ^ (pub_r001015_14_1 >> 1)) & 127;
  int stage_v_140_2 = ((stage_v_64_2 << 1) ^ (pub_r001015_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_140_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_140_2 + 1) & 15;
  out_sink_1 ^= stage_v_140_1 & 63;
  out_sink_2 ^= stage_v_140_2 & 63;
  int stage_v_141_1 = ((helper_flow_5_1 << 1) ^ (pub_r001015_2_1 >> 1)) & 127;
  int stage_v_141_2 = ((helper_flow_5_2 << 1) ^ (pub_r001015_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_141_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_141_2 + 1) & 15;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = ((stage_v_131_1 << 1) ^ (pub_r001015_13_1 >> 1)) & 127;
  int stage_v_142_2 = ((stage_v_131_2 << 1) ^ (pub_r001015_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_142_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_142_2 + 1) & 15;
  out_sink_1 ^= stage_v_142_1 & 63;
  out_sink_2 ^= stage_v_142_2 & 63;
  int stage_v_143_1 = ((pub_r001015_7_1 * 2) + 25) & 63;
  int stage_v_143_2 = ((pub_r001015_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((stage_v_20_1 << 1) ^ (pub_r001015_10_1 >> 1)) & 127;
  int stage_v_144_2 = ((stage_v_20_2 << 1) ^ (pub_r001015_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_144_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_144_2 + 1) & 15;
  out_sink_1 ^= stage_v_144_1 & 63;
  out_sink_2 ^= stage_v_144_2 & 63;
  int stage_v_145_1 = ((pub_r001015_13_1 * 2) + 21) & 63;
  int stage_v_145_2 = ((pub_r001015_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((stage_v_31_1 << 1) ^ (pub_r001015_6_1 >> 1)) & 127;
  int stage_v_146_2 = ((stage_v_31_2 << 1) ^ (pub_r001015_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_146_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_146_2 + 1) & 15;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = ((stage_v_29_1 << 1) ^ (pub_r001015_6_1 >> 1)) & 127;
  int stage_v_147_2 = ((stage_v_29_2 << 1) ^ (pub_r001015_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_147_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_147_2 + 1) & 15;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = ((pub_r001015_19_1 * 2) + 8) & 63;
  int stage_v_148_2 = ((pub_r001015_19_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((stage_v_31_1 << 1) ^ (pub_r001015_3_1 >> 1)) & 127;
  int stage_v_149_2 = ((stage_v_31_2 << 1) ^ (pub_r001015_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_149_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_149_2 + 1) & 15;
  out_sink_1 ^= stage_v_149_1 & 63;
  out_sink_2 ^= stage_v_149_2 & 63;
  int stage_v_150_1 = ((pub_r001015_23_1 * 2) + 19) & 63;
  int stage_v_150_2 = ((pub_r001015_23_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((stage_v_12_1 << 1) ^ (pub_r001015_12_1 >> 1)) & 127;
  int stage_v_151_2 = ((stage_v_12_2 << 1) ^ (pub_r001015_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_151_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_151_2 + 1) & 15;
  out_sink_1 ^= stage_v_151_1 & 63;
  out_sink_2 ^= stage_v_151_2 & 63;
  int stage_v_152_1 = ((pub_r001015_2_1 * 2) + 27) & 63;
  int stage_v_152_2 = ((pub_r001015_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((stage_v_146_1 << 1) ^ (pub_r001015_23_1 >> 1)) & 127;
  int stage_v_153_2 = ((stage_v_146_2 << 1) ^ (pub_r001015_23_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_153_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_153_2 + 1) & 15;
  out_sink_1 ^= stage_v_153_1 & 63;
  out_sink_2 ^= stage_v_153_2 & 63;
  int stage_v_154_1 = ((pub_r001015_7_1 * 2) + 28) & 63;
  int stage_v_154_2 = ((pub_r001015_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((stage_v_128_1 << 1) ^ (pub_r001015_8_1 >> 1)) & 127;
  int stage_v_155_2 = ((stage_v_128_2 << 1) ^ (pub_r001015_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_155_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_155_2 + 1) & 15;
  out_sink_1 ^= stage_v_155_1 & 63;
  out_sink_2 ^= stage_v_155_2 & 63;
  int stage_v_156_1 = ((stage_v_57_1 << 1) ^ (pub_r001015_7_1 >> 1)) & 127;
  int stage_v_156_2 = ((stage_v_57_2 << 1) ^ (pub_r001015_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_156_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_156_2 + 1) & 15;
  out_sink_1 ^= stage_v_156_1 & 63;
  out_sink_2 ^= stage_v_156_2 & 63;
  int stage_v_157_1 = ((stage_v_66_1 << 1) ^ (pub_r001015_4_1 >> 1)) & 127;
  int stage_v_157_2 = ((stage_v_66_2 << 1) ^ (pub_r001015_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_157_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_157_2 + 1) & 15;
  out_sink_1 ^= stage_v_157_1 & 63;
  out_sink_2 ^= stage_v_157_2 & 63;
  int stage_v_158_1 = ((stage_v_52_1 << 1) ^ (pub_r001015_16_1 >> 1)) & 127;
  int stage_v_158_2 = ((stage_v_52_2 << 1) ^ (pub_r001015_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_158_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_158_2 + 1) & 15;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = ((stage_v_131_1 << 1) ^ (pub_r001015_14_1 >> 1)) & 127;
  int stage_v_159_2 = ((stage_v_131_2 << 1) ^ (pub_r001015_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_159_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_159_2 + 1) & 15;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = ((pub_r001015_22_1 * 2) + 26) & 63;
  int stage_v_160_2 = ((pub_r001015_22_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001015_3_1 * 2) + 47) & 63;
  int stage_v_161_2 = ((pub_r001015_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((stage_v_155_1 << 1) ^ (pub_r001015_11_1 >> 1)) & 127;
  int stage_v_162_2 = ((stage_v_155_2 << 1) ^ (pub_r001015_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_162_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_162_2 + 1) & 15;
  out_sink_1 ^= stage_v_162_1 & 63;
  out_sink_2 ^= stage_v_162_2 & 63;
  int stage_v_163_1 = ((pub_r001015_0_1 * 2) + 36) & 63;
  int stage_v_163_2 = ((pub_r001015_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((stage_v_63_1 << 1) ^ (pub_r001015_14_1 >> 1)) & 127;
  int stage_v_164_2 = ((stage_v_63_2 << 1) ^ (pub_r001015_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_164_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_164_2 + 1) & 15;
  out_sink_1 ^= stage_v_164_1 & 63;
  out_sink_2 ^= stage_v_164_2 & 63;
  int stage_v_165_1 = ((stage_v_1_1 << 1) ^ (pub_r001015_0_1 >> 1)) & 127;
  int stage_v_165_2 = ((stage_v_1_2 << 1) ^ (pub_r001015_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_165_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_165_2 + 1) & 15;
  out_sink_1 ^= stage_v_165_1 & 63;
  out_sink_2 ^= stage_v_165_2 & 63;
  int stage_v_166_1 = ((stage_v_16_1 << 1) ^ (pub_r001015_23_1 >> 1)) & 127;
  int stage_v_166_2 = ((stage_v_16_2 << 1) ^ (pub_r001015_23_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_166_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_166_2 + 1) & 15;
  out_sink_1 ^= stage_v_166_1 & 63;
  out_sink_2 ^= stage_v_166_2 & 63;
  int stage_v_167_1 = ((pub_r001015_20_1 * 2) + 41) & 63;
  int stage_v_167_2 = ((pub_r001015_20_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001015_19_1 * 2) + 8) & 63;
  int stage_v_168_2 = ((pub_r001015_19_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((sec_r001015_19_1 << 1) ^ (pub_r001015_21_1 >> 1)) & 127;
  int stage_v_169_2 = ((sec_r001015_19_2 << 1) ^ (pub_r001015_21_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_169_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_169_2 + 1) & 15;
  out_sink_1 ^= stage_v_169_1 & 63;
  out_sink_2 ^= stage_v_169_2 & 63;
  int stage_v_170_1 = ((stage_v_115_1 << 1) ^ (pub_r001015_7_1 >> 1)) & 127;
  int stage_v_170_2 = ((stage_v_115_2 << 1) ^ (pub_r001015_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_170_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_170_2 + 1) & 15;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = ((stage_v_27_1 << 1) ^ (pub_r001015_18_1 >> 1)) & 127;
  int stage_v_171_2 = ((stage_v_27_2 << 1) ^ (pub_r001015_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_171_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_171_2 + 1) & 15;
  out_sink_1 ^= stage_v_171_1 & 63;
  out_sink_2 ^= stage_v_171_2 & 63;
  int stage_v_172_1 = ((pub_r001015_2_1 * 2) + 21) & 63;
  int stage_v_172_2 = ((pub_r001015_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001015_5_1 * 2) + 7) & 63;
  int stage_v_173_2 = ((pub_r001015_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((sec_r001015_17_1 << 1) ^ (pub_r001015_19_1 >> 1)) & 127;
  int stage_v_174_2 = ((sec_r001015_17_2 << 1) ^ (pub_r001015_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_174_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_174_2 + 1) & 15;
  out_sink_1 ^= stage_v_174_1 & 63;
  out_sink_2 ^= stage_v_174_2 & 63;
  int stage_v_175_1 = ((pub_r001015_20_1 * 2) + 41) & 63;
  int stage_v_175_2 = ((pub_r001015_20_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001015_19_1 * 2) + 50) & 63;
  int stage_v_176_2 = ((pub_r001015_19_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((helper_flow_4_1 << 1) ^ (pub_r001015_21_1 >> 1)) & 127;
  int stage_v_177_2 = ((helper_flow_4_2 << 1) ^ (pub_r001015_21_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_177_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_177_2 + 1) & 15;
  out_sink_1 ^= stage_v_177_1 & 63;
  out_sink_2 ^= stage_v_177_2 & 63;
  int stage_v_178_1 = ((pub_r001015_11_1 * 2) + 33) & 63;
  int stage_v_178_2 = ((pub_r001015_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001015_19_1 * 2) + 14) & 63;
  int stage_v_179_2 = ((pub_r001015_19_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((stage_v_127_1 << 1) ^ (pub_r001015_1_1 >> 1)) & 127;
  int stage_v_180_2 = ((stage_v_127_2 << 1) ^ (pub_r001015_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_180_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_180_2 + 1) & 15;
  out_sink_1 ^= stage_v_180_1 & 63;
  out_sink_2 ^= stage_v_180_2 & 63;
  int stage_v_181_1 = ((pub_r001015_23_1 * 2) + 24) & 63;
  int stage_v_181_2 = ((pub_r001015_23_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001015_12_1 * 2) + 25) & 63;
  int stage_v_182_2 = ((pub_r001015_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((stage_v_147_1 << 1) ^ (pub_r001015_23_1 >> 1)) & 127;
  int stage_v_183_2 = ((stage_v_147_2 << 1) ^ (pub_r001015_23_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_183_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_183_2 + 1) & 15;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = ((stage_v_63_1 << 1) ^ (pub_r001015_15_1 >> 1)) & 127;
  int stage_v_184_2 = ((stage_v_63_2 << 1) ^ (pub_r001015_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_184_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_184_2 + 1) & 15;
  out_sink_1 ^= stage_v_184_1 & 63;
  out_sink_2 ^= stage_v_184_2 & 63;
  int stage_v_185_1 = ((pub_r001015_6_1 * 2) + 41) & 63;
  int stage_v_185_2 = ((pub_r001015_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001015_22_1 * 2) + 21) & 63;
  int stage_v_186_2 = ((pub_r001015_22_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((stage_v_184_1 << 1) ^ (pub_r001015_0_1 >> 1)) & 127;
  int stage_v_187_2 = ((stage_v_184_2 << 1) ^ (pub_r001015_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_187_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_187_2 + 1) & 15;
  out_sink_1 ^= stage_v_187_1 & 63;
  out_sink_2 ^= stage_v_187_2 & 63;
  int stage_v_188_1 = ((pub_r001015_5_1 * 2) + 38) & 63;
  int stage_v_188_2 = ((pub_r001015_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001015_6_1 * 2) + 20) & 63;
  int stage_v_189_2 = ((pub_r001015_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((sec_r001015_0_1 << 1) ^ (pub_r001015_8_1 >> 1)) & 127;
  int stage_v_190_2 = ((sec_r001015_0_2 << 1) ^ (pub_r001015_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_190_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_190_2 + 1) & 15;
  out_sink_1 ^= stage_v_190_1 & 63;
  out_sink_2 ^= stage_v_190_2 & 63;
  int stage_v_191_1 = ((stage_v_187_1 << 1) ^ (pub_r001015_22_1 >> 1)) & 127;
  int stage_v_191_2 = ((stage_v_187_2 << 1) ^ (pub_r001015_22_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_191_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_191_2 + 1) & 15;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = ((stage_v_151_1 << 1) ^ (pub_r001015_14_1 >> 1)) & 127;
  int stage_v_192_2 = ((stage_v_151_2 << 1) ^ (pub_r001015_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_192_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_192_2 + 1) & 15;
  out_sink_1 ^= stage_v_192_1 & 63;
  out_sink_2 ^= stage_v_192_2 & 63;
  int stage_v_193_1 = ((stage_v_42_1 << 1) ^ (pub_r001015_13_1 >> 1)) & 127;
  int stage_v_193_2 = ((stage_v_42_2 << 1) ^ (pub_r001015_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_193_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_193_2 + 1) & 15;
  out_sink_1 ^= stage_v_193_1 & 63;
  out_sink_2 ^= stage_v_193_2 & 63;
  int stage_v_194_1 = ((pub_r001015_3_1 * 2) + 46) & 63;
  int stage_v_194_2 = ((pub_r001015_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001015_14_1 * 2) + 19) & 63;
  int stage_v_195_2 = ((pub_r001015_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001015_17_1 * 2) + 25) & 63;
  int stage_v_196_2 = ((pub_r001015_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((stage_v_144_1 << 1) ^ (pub_r001015_12_1 >> 1)) & 127;
  int stage_v_197_2 = ((stage_v_144_2 << 1) ^ (pub_r001015_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_197_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_197_2 + 1) & 15;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = ((stage_v_124_1 << 1) ^ (pub_r001015_5_1 >> 1)) & 127;
  int stage_v_198_2 = ((stage_v_124_2 << 1) ^ (pub_r001015_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_198_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_198_2 + 1) & 15;
  out_sink_1 ^= stage_v_198_1 & 63;
  out_sink_2 ^= stage_v_198_2 & 63;
  int stage_v_199_1 = ((stage_v_127_1 << 1) ^ (pub_r001015_23_1 >> 1)) & 127;
  int stage_v_199_2 = ((stage_v_127_2 << 1) ^ (pub_r001015_23_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_199_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_199_2 + 1) & 15;
  out_sink_1 ^= stage_v_199_1 & 63;
  out_sink_2 ^= stage_v_199_2 & 63;
  int stage_v_200_1 = ((pub_r001015_11_1 * 2) + 26) & 63;
  int stage_v_200_2 = ((pub_r001015_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((stage_v_119_1 << 1) ^ (pub_r001015_18_1 >> 1)) & 127;
  int stage_v_201_2 = ((stage_v_119_2 << 1) ^ (pub_r001015_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_201_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_201_2 + 1) & 15;
  out_sink_1 ^= stage_v_201_1 & 63;
  out_sink_2 ^= stage_v_201_2 & 63;
  int stage_v_202_1 = ((sec_r001015_9_1 << 1) ^ (pub_r001015_3_1 >> 1)) & 127;
  int stage_v_202_2 = ((sec_r001015_9_2 << 1) ^ (pub_r001015_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_202_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_202_2 + 1) & 15;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = ((pub_r001015_16_1 * 2) + 5) & 63;
  int stage_v_203_2 = ((pub_r001015_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001015_16_1 * 2) + 37) & 63;
  int stage_v_204_2 = ((pub_r001015_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((stage_v_39_1 << 1) ^ (pub_r001015_11_1 >> 1)) & 127;
  int stage_v_205_2 = ((stage_v_39_2 << 1) ^ (pub_r001015_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_205_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_205_2 + 1) & 15;
  out_sink_1 ^= stage_v_205_1 & 63;
  out_sink_2 ^= stage_v_205_2 & 63;
  int stage_v_206_1 = ((pub_r001015_18_1 * 2) + 42) & 63;
  int stage_v_206_2 = ((pub_r001015_18_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001015_1_1 * 2) + 38) & 63;
  int stage_v_207_2 = ((pub_r001015_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((stage_v_56_1 << 1) ^ (pub_r001015_9_1 >> 1)) & 127;
  int stage_v_208_2 = ((stage_v_56_2 << 1) ^ (pub_r001015_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_208_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_208_2 + 1) & 15;
  out_sink_1 ^= stage_v_208_1 & 63;
  out_sink_2 ^= stage_v_208_2 & 63;
  int stage_v_209_1 = ((stage_v_135_1 << 1) ^ (pub_r001015_23_1 >> 1)) & 127;
  int stage_v_209_2 = ((stage_v_135_2 << 1) ^ (pub_r001015_23_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_209_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_209_2 + 1) & 15;
  out_sink_1 ^= stage_v_209_1 & 63;
  out_sink_2 ^= stage_v_209_2 & 63;
  int stage_v_210_1 = ((pub_r001015_15_1 * 2) + 23) & 63;
  int stage_v_210_2 = ((pub_r001015_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((stage_v_124_1 << 1) ^ (pub_r001015_14_1 >> 1)) & 127;
  int stage_v_211_2 = ((stage_v_124_2 << 1) ^ (pub_r001015_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_211_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_211_2 + 1) & 15;
  out_sink_1 ^= stage_v_211_1 & 63;
  out_sink_2 ^= stage_v_211_2 & 63;
  int stage_v_212_1 = ((pub_r001015_22_1 * 2) + 17) & 63;
  int stage_v_212_2 = ((pub_r001015_22_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001015_22_1 * 2) + 42) & 63;
  int stage_v_213_2 = ((pub_r001015_22_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((stage_v_29_1 << 1) ^ (pub_r001015_9_1 >> 1)) & 127;
  int stage_v_214_2 = ((stage_v_29_2 << 1) ^ (pub_r001015_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_214_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_214_2 + 1) & 15;
  out_sink_1 ^= stage_v_214_1 & 63;
  out_sink_2 ^= stage_v_214_2 & 63;
  int stage_v_215_1 = ((stage_v_17_1 << 1) ^ (pub_r001015_18_1 >> 1)) & 127;
  int stage_v_215_2 = ((stage_v_17_2 << 1) ^ (pub_r001015_18_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_215_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_215_2 + 1) & 15;
  out_sink_1 ^= stage_v_215_1 & 63;
  out_sink_2 ^= stage_v_215_2 & 63;
  int stage_v_216_1 = ((stage_v_56_1 << 1) ^ (pub_r001015_10_1 >> 1)) & 127;
  int stage_v_216_2 = ((stage_v_56_2 << 1) ^ (pub_r001015_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_216_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_216_2 + 1) & 15;
  out_sink_1 ^= stage_v_216_1 & 63;
  out_sink_2 ^= stage_v_216_2 & 63;
  int stage_v_217_1 = ((stage_v_208_1 << 1) ^ (pub_r001015_23_1 >> 1)) & 127;
  int stage_v_217_2 = ((stage_v_208_2 << 1) ^ (pub_r001015_23_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_217_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_217_2 + 1) & 15;
  out_sink_1 ^= stage_v_217_1 & 63;
  out_sink_2 ^= stage_v_217_2 & 63;
  int stage_v_218_1 = ((stage_v_119_1 << 1) ^ (pub_r001015_9_1 >> 1)) & 127;
  int stage_v_218_2 = ((stage_v_119_2 << 1) ^ (pub_r001015_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_218_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_218_2 + 1) & 15;
  out_sink_1 ^= stage_v_218_1 & 63;
  out_sink_2 ^= stage_v_218_2 & 63;
  int stage_v_219_1 = ((pub_r001015_19_1 * 2) + 28) & 63;
  int stage_v_219_2 = ((pub_r001015_19_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((stage_v_93_1 << 1) ^ (pub_r001015_1_1 >> 1)) & 127;
  int stage_v_220_2 = ((stage_v_93_2 << 1) ^ (pub_r001015_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_220_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_220_2 + 1) & 15;
  out_sink_1 ^= stage_v_220_1 & 63;
  out_sink_2 ^= stage_v_220_2 & 63;
  int stage_v_221_1 = ((pub_r001015_18_1 * 2) + 43) & 63;
  int stage_v_221_2 = ((pub_r001015_18_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((stage_v_147_1 << 1) ^ (pub_r001015_12_1 >> 1)) & 127;
  int stage_v_222_2 = ((stage_v_147_2 << 1) ^ (pub_r001015_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_222_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_222_2 + 1) & 15;
  out_sink_1 ^= stage_v_222_1 & 63;
  out_sink_2 ^= stage_v_222_2 & 63;
  int stage_v_223_1 = ((stage_v_42_1 << 1) ^ (pub_r001015_9_1 >> 1)) & 127;
  int stage_v_223_2 = ((stage_v_42_2 << 1) ^ (pub_r001015_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_223_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_223_2 + 1) & 15;
  out_sink_1 ^= stage_v_223_1 & 63;
  out_sink_2 ^= stage_v_223_2 & 63;
  int stage_v_224_1 = ((pub_r001015_23_1 * 2) + 47) & 63;
  int stage_v_224_2 = ((pub_r001015_23_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((stage_v_57_1 << 1) ^ (pub_r001015_11_1 >> 1)) & 127;
  int stage_v_225_2 = ((stage_v_57_2 << 1) ^ (pub_r001015_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_225_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_225_2 + 1) & 15;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = ((stage_v_115_1 << 1) ^ (pub_r001015_8_1 >> 1)) & 127;
  int stage_v_226_2 = ((stage_v_115_2 << 1) ^ (pub_r001015_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_226_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_226_2 + 1) & 15;
  out_sink_1 ^= stage_v_226_1 & 63;
  out_sink_2 ^= stage_v_226_2 & 63;
  int stage_v_227_1 = ((stage_v_70_1 << 1) ^ (pub_r001015_19_1 >> 1)) & 127;
  int stage_v_227_2 = ((stage_v_70_2 << 1) ^ (pub_r001015_19_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_227_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_227_2 + 1) & 15;
  out_sink_1 ^= stage_v_227_1 & 63;
  out_sink_2 ^= stage_v_227_2 & 63;
  int stage_v_228_1 = ((stage_v_116_1 << 1) ^ (pub_r001015_13_1 >> 1)) & 127;
  int stage_v_228_2 = ((stage_v_116_2 << 1) ^ (pub_r001015_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_228_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_228_2 + 1) & 15;
  out_sink_1 ^= stage_v_228_1 & 63;
  out_sink_2 ^= stage_v_228_2 & 63;
  int stage_v_229_1 = ((stage_v_171_1 << 1) ^ (pub_r001015_5_1 >> 1)) & 127;
  int stage_v_229_2 = ((stage_v_171_2 << 1) ^ (pub_r001015_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_229_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_229_2 + 1) & 15;
  out_sink_1 ^= stage_v_229_1 & 63;
  out_sink_2 ^= stage_v_229_2 & 63;
  int stage_v_230_1 = ((sec_r001015_4_1 << 1) ^ (pub_r001015_16_1 >> 1)) & 127;
  int stage_v_230_2 = ((sec_r001015_4_2 << 1) ^ (pub_r001015_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_230_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_230_2 + 1) & 15;
  out_sink_1 ^= stage_v_230_1 & 63;
  out_sink_2 ^= stage_v_230_2 & 63;
  int stage_v_231_1 = ((stage_v_111_1 << 1) ^ (pub_r001015_0_1 >> 1)) & 127;
  int stage_v_231_2 = ((stage_v_111_2 << 1) ^ (pub_r001015_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_231_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_231_2 + 1) & 15;
  out_sink_1 ^= stage_v_231_1 & 63;
  out_sink_2 ^= stage_v_231_2 & 63;
  int stage_v_232_1 = ((pub_r001015_19_1 * 2) + 26) & 63;
  int stage_v_232_2 = ((pub_r001015_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001015_13_1 * 2) + 27) & 63;
  int stage_v_233_2 = ((pub_r001015_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((stage_v_146_1 << 1) ^ (pub_r001015_10_1 >> 1)) & 127;
  int stage_v_234_2 = ((stage_v_146_2 << 1) ^ (pub_r001015_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_234_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_234_2 + 1) & 15;
  out_sink_1 ^= stage_v_234_1 & 63;
  out_sink_2 ^= stage_v_234_2 & 63;
  int stage_v_235_1 = ((pub_r001015_3_1 * 2) + 45) & 63;
  int stage_v_235_2 = ((pub_r001015_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((stage_v_66_1 << 1) ^ (pub_r001015_4_1 >> 1)) & 127;
  int stage_v_236_2 = ((stage_v_66_2 << 1) ^ (pub_r001015_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_236_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_236_2 + 1) & 15;
  out_sink_1 ^= stage_v_236_1 & 63;
  out_sink_2 ^= stage_v_236_2 & 63;
  int stage_v_237_1 = ((pub_r001015_10_1 * 2) + 47) & 63;
  int stage_v_237_2 = ((pub_r001015_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((stage_v_41_1 << 1) ^ (pub_r001015_1_1 >> 1)) & 127;
  int stage_v_238_2 = ((stage_v_41_2 << 1) ^ (pub_r001015_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_238_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_238_2 + 1) & 15;
  out_sink_1 ^= stage_v_238_1 & 63;
  out_sink_2 ^= stage_v_238_2 & 63;
  int stage_v_239_1 = ((stage_v_157_1 << 1) ^ (pub_r001015_15_1 >> 1)) & 127;
  int stage_v_239_2 = ((stage_v_157_2 << 1) ^ (pub_r001015_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_239_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_239_2 + 1) & 15;
  out_sink_1 ^= stage_v_239_1 & 63;
  out_sink_2 ^= stage_v_239_2 & 63;
  int stage_v_240_1 = ((stage_v_38_1 << 1) ^ (pub_r001015_8_1 >> 1)) & 127;
  int stage_v_240_2 = ((stage_v_38_2 << 1) ^ (pub_r001015_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_240_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_240_2 + 1) & 15;
  out_sink_1 ^= stage_v_240_1 & 63;
  out_sink_2 ^= stage_v_240_2 & 63;
  int stage_v_241_1 = ((pub_r001015_2_1 * 2) + 41) & 63;
  int stage_v_241_2 = ((pub_r001015_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((stage_v_112_1 << 1) ^ (pub_r001015_13_1 >> 1)) & 127;
  int stage_v_242_2 = ((stage_v_112_2 << 1) ^ (pub_r001015_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_242_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_242_2 + 1) & 15;
  out_sink_1 ^= stage_v_242_1 & 63;
  out_sink_2 ^= stage_v_242_2 & 63;
  int stage_v_243_1 = ((stage_v_60_1 << 1) ^ (pub_r001015_9_1 >> 1)) & 127;
  int stage_v_243_2 = ((stage_v_60_2 << 1) ^ (pub_r001015_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_243_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_243_2 + 1) & 15;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = ((stage_v_111_1 << 1) ^ (pub_r001015_0_1 >> 1)) & 127;
  int stage_v_244_2 = ((stage_v_111_2 << 1) ^ (pub_r001015_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_244_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_244_2 + 1) & 15;
  out_sink_1 ^= stage_v_244_1 & 63;
  out_sink_2 ^= stage_v_244_2 & 63;
  int stage_v_245_1 = ((sec_r001015_13_1 << 1) ^ (pub_r001015_1_1 >> 1)) & 127;
  int stage_v_245_2 = ((sec_r001015_13_2 << 1) ^ (pub_r001015_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_245_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_245_2 + 1) & 15;
  out_sink_1 ^= stage_v_245_1 & 63;
  out_sink_2 ^= stage_v_245_2 & 63;
  int stage_v_246_1 = ((pub_r001015_3_1 * 2) + 33) & 63;
  int stage_v_246_2 = ((pub_r001015_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((stage_v_153_1 << 1) ^ (pub_r001015_14_1 >> 1)) & 127;
  int stage_v_247_2 = ((stage_v_153_2 << 1) ^ (pub_r001015_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_247_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_247_2 + 1) & 15;
  out_sink_1 ^= stage_v_247_1 & 63;
  out_sink_2 ^= stage_v_247_2 & 63;
  int stage_v_248_1 = ((pub_r001015_15_1 * 2) + 16) & 63;
  int stage_v_248_2 = ((pub_r001015_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((stage_v_29_1 << 1) ^ (pub_r001015_11_1 >> 1)) & 127;
  int stage_v_249_2 = ((stage_v_29_2 << 1) ^ (pub_r001015_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_249_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_249_2 + 1) & 15;
  out_sink_1 ^= stage_v_249_1 & 63;
  out_sink_2 ^= stage_v_249_2 & 63;
  int stage_v_250_1 = ((pub_r001015_6_1 * 2) + 36) & 63;
  int stage_v_250_2 = ((pub_r001015_6_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((sec_r001015_16_1 << 1) ^ (pub_r001015_3_1 >> 1)) & 127;
  int stage_v_251_2 = ((sec_r001015_16_2 << 1) ^ (pub_r001015_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_251_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_251_2 + 1) & 15;
  out_sink_1 ^= stage_v_251_1 & 63;
  out_sink_2 ^= stage_v_251_2 & 63;
  int stage_v_252_1 = ((stage_v_156_1 << 1) ^ (pub_r001015_7_1 >> 1)) & 127;
  int stage_v_252_2 = ((stage_v_156_2 << 1) ^ (pub_r001015_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_252_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_252_2 + 1) & 15;
  out_sink_1 ^= stage_v_252_1 & 63;
  out_sink_2 ^= stage_v_252_2 & 63;
  int stage_v_253_1 = ((helper_flow_6_1 << 1) ^ (pub_r001015_10_1 >> 1)) & 127;
  int stage_v_253_2 = ((helper_flow_6_2 << 1) ^ (pub_r001015_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_253_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_253_2 + 1) & 15;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = ((pub_r001015_1_1 * 2) + 42) & 63;
  int stage_v_254_2 = ((pub_r001015_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((stage_v_10_1 << 1) ^ (pub_r001015_7_1 >> 1)) & 127;
  int stage_v_255_2 = ((stage_v_10_2 << 1) ^ (pub_r001015_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_255_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_255_2 + 1) & 15;
  out_sink_1 ^= stage_v_255_1 & 63;
  out_sink_2 ^= stage_v_255_2 & 63;
  int stage_v_256_1 = ((stage_v_76_1 << 1) ^ (pub_r001015_2_1 >> 1)) & 127;
  int stage_v_256_2 = ((stage_v_76_2 << 1) ^ (pub_r001015_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_256_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_256_2 + 1) & 15;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = ((pub_r001015_11_1 * 2) + 20) & 63;
  int stage_v_257_2 = ((pub_r001015_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((pub_r001015_6_1 * 2) + 13) & 63;
  int stage_v_258_2 = ((pub_r001015_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((pub_r001015_2_1 * 2) + 40) & 63;
  int stage_v_259_2 = ((pub_r001015_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((stage_v_3_1 << 1) ^ (pub_r001015_13_1 >> 1)) & 127;
  int stage_v_260_2 = ((stage_v_3_2 << 1) ^ (pub_r001015_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_260_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_260_2 + 1) & 15;
  out_sink_1 ^= stage_v_260_1 & 63;
  out_sink_2 ^= stage_v_260_2 & 63;
  int stage_v_261_1 = ((stage_v_249_1 << 1) ^ (pub_r001015_20_1 >> 1)) & 127;
  int stage_v_261_2 = ((stage_v_249_2 << 1) ^ (pub_r001015_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_261_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_261_2 + 1) & 15;
  out_sink_1 ^= stage_v_261_1 & 63;
  out_sink_2 ^= stage_v_261_2 & 63;
  int stage_v_262_1 = ((pub_r001015_15_1 * 2) + 11) & 63;
  int stage_v_262_2 = ((pub_r001015_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((stage_v_228_1 << 1) ^ (pub_r001015_19_1 >> 1)) & 127;
  int stage_v_263_2 = ((stage_v_228_2 << 1) ^ (pub_r001015_19_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_263_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_263_2 + 1) & 15;
  out_sink_1 ^= stage_v_263_1 & 63;
  out_sink_2 ^= stage_v_263_2 & 63;
  int stage_v_264_1 = ((stage_v_240_1 << 1) ^ (pub_r001015_1_1 >> 1)) & 127;
  int stage_v_264_2 = ((stage_v_240_2 << 1) ^ (pub_r001015_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_264_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_264_2 + 1) & 15;
  out_sink_1 ^= stage_v_264_1 & 63;
  out_sink_2 ^= stage_v_264_2 & 63;
  int stage_v_265_1 = ((stage_v_31_1 << 1) ^ (pub_r001015_16_1 >> 1)) & 127;
  int stage_v_265_2 = ((stage_v_31_2 << 1) ^ (pub_r001015_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_265_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_265_2 + 1) & 15;
  out_sink_1 ^= stage_v_265_1 & 63;
  out_sink_2 ^= stage_v_265_2 & 63;
  int stage_v_266_1 = ((pub_r001015_16_1 * 2) + 25) & 63;
  int stage_v_266_2 = ((pub_r001015_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((stage_v_41_1 << 1) ^ (pub_r001015_23_1 >> 1)) & 127;
  int stage_v_267_2 = ((stage_v_41_2 << 1) ^ (pub_r001015_23_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_267_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_267_2 + 1) & 15;
  out_sink_1 ^= stage_v_267_1 & 63;
  out_sink_2 ^= stage_v_267_2 & 63;
  int stage_v_268_1 = ((pub_r001015_11_1 * 2) + 25) & 63;
  int stage_v_268_2 = ((pub_r001015_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001015_10_1 * 2) + 44) & 63;
  int stage_v_269_2 = ((pub_r001015_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((stage_v_214_1 << 1) ^ (pub_r001015_23_1 >> 1)) & 127;
  int stage_v_270_2 = ((stage_v_214_2 << 1) ^ (pub_r001015_23_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_270_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_270_2 + 1) & 15;
  out_sink_1 ^= stage_v_270_1 & 63;
  out_sink_2 ^= stage_v_270_2 & 63;
  int stage_v_271_1 = ((pub_r001015_16_1 * 2) + 21) & 63;
  int stage_v_271_2 = ((pub_r001015_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((stage_v_86_1 << 1) ^ (pub_r001015_23_1 >> 1)) & 127;
  int stage_v_272_2 = ((stage_v_86_2 << 1) ^ (pub_r001015_23_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_272_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_272_2 + 1) & 15;
  out_sink_1 ^= stage_v_272_1 & 63;
  out_sink_2 ^= stage_v_272_2 & 63;
  int stage_v_273_1 = ((helper_flow_6_1 << 1) ^ (pub_r001015_10_1 >> 1)) & 127;
  int stage_v_273_2 = ((helper_flow_6_2 << 1) ^ (pub_r001015_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_273_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_273_2 + 1) & 15;
  out_sink_1 ^= stage_v_273_1 & 63;
  out_sink_2 ^= stage_v_273_2 & 63;
  int stage_v_274_1 = ((pub_r001015_13_1 * 2) + 37) & 63;
  int stage_v_274_2 = ((pub_r001015_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((stage_v_107_1 << 1) ^ (pub_r001015_5_1 >> 1)) & 127;
  int stage_v_275_2 = ((stage_v_107_2 << 1) ^ (pub_r001015_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_275_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_275_2 + 1) & 15;
  out_sink_1 ^= stage_v_275_1 & 63;
  out_sink_2 ^= stage_v_275_2 & 63;
  int stage_v_276_1 = ((pub_r001015_7_1 * 2) + 42) & 63;
  int stage_v_276_2 = ((pub_r001015_7_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = ((stage_v_131_1 << 1) ^ (pub_r001015_11_1 >> 1)) & 127;
  int stage_v_277_2 = ((stage_v_131_2 << 1) ^ (pub_r001015_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_277_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_277_2 + 1) & 15;
  out_sink_1 ^= stage_v_277_1 & 63;
  out_sink_2 ^= stage_v_277_2 & 63;
  int stage_v_278_1 = ((pub_r001015_6_1 * 2) + 48) & 63;
  int stage_v_278_2 = ((pub_r001015_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((sec_r001015_14_1 << 1) ^ (pub_r001015_19_1 >> 1)) & 127;
  int stage_v_279_2 = ((sec_r001015_14_2 << 1) ^ (pub_r001015_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_279_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_279_2 + 1) & 15;
  out_sink_1 ^= stage_v_279_1 & 63;
  out_sink_2 ^= stage_v_279_2 & 63;
  int stage_v_280_1 = ((pub_r001015_7_1 * 2) + 48) & 63;
  int stage_v_280_2 = ((pub_r001015_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((stage_v_131_1 << 1) ^ (pub_r001015_9_1 >> 1)) & 127;
  int stage_v_281_2 = ((stage_v_131_2 << 1) ^ (pub_r001015_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_281_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_281_2 + 1) & 15;
  out_sink_1 ^= stage_v_281_1 & 63;
  out_sink_2 ^= stage_v_281_2 & 63;
  int stage_v_282_1 = ((stage_v_144_1 << 1) ^ (pub_r001015_12_1 >> 1)) & 127;
  int stage_v_282_2 = ((stage_v_144_2 << 1) ^ (pub_r001015_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_282_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_282_2 + 1) & 15;
  out_sink_1 ^= stage_v_282_1 & 63;
  out_sink_2 ^= stage_v_282_2 & 63;
  int stage_v_283_1 = ((stage_v_256_1 << 1) ^ (pub_r001015_19_1 >> 1)) & 127;
  int stage_v_283_2 = ((stage_v_256_2 << 1) ^ (pub_r001015_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_283_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_283_2 + 1) & 15;
  out_sink_1 ^= stage_v_283_1 & 63;
  out_sink_2 ^= stage_v_283_2 & 63;
  int stage_v_284_1 = ((pub_r001015_14_1 * 2) + 7) & 63;
  int stage_v_284_2 = ((pub_r001015_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((stage_v_265_1 << 1) ^ (pub_r001015_16_1 >> 1)) & 127;
  int stage_v_285_2 = ((stage_v_265_2 << 1) ^ (pub_r001015_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_285_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_285_2 + 1) & 15;
  out_sink_1 ^= stage_v_285_1 & 63;
  out_sink_2 ^= stage_v_285_2 & 63;
  int stage_v_286_1 = ((pub_r001015_0_1 * 2) + 36) & 63;
  int stage_v_286_2 = ((pub_r001015_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((pub_r001015_9_1 * 2) + 37) & 63;
  int stage_v_287_2 = ((pub_r001015_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((pub_r001015_4_1 * 2) + 24) & 63;
  int stage_v_288_2 = ((pub_r001015_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((pub_r001015_1_1 * 2) + 12) & 63;
  int stage_v_289_2 = ((pub_r001015_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((pub_r001015_20_1 * 2) + 9) & 63;
  int stage_v_290_2 = ((pub_r001015_20_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = ((stage_v_123_1 << 1) ^ (pub_r001015_14_1 >> 1)) & 127;
  int stage_v_291_2 = ((stage_v_123_2 << 1) ^ (pub_r001015_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_291_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_291_2 + 1) & 15;
  out_sink_1 ^= stage_v_291_1 & 63;
  out_sink_2 ^= stage_v_291_2 & 63;
  int stage_v_292_1 = ((sec_r001015_15_1 << 1) ^ (pub_r001015_23_1 >> 1)) & 127;
  int stage_v_292_2 = ((sec_r001015_15_2 << 1) ^ (pub_r001015_23_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_292_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_292_2 + 1) & 15;
  out_sink_1 ^= stage_v_292_1 & 63;
  out_sink_2 ^= stage_v_292_2 & 63;
  int stage_v_293_1 = ((pub_r001015_23_1 * 2) + 19) & 63;
  int stage_v_293_2 = ((pub_r001015_23_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((stage_v_153_1 << 1) ^ (pub_r001015_4_1 >> 1)) & 127;
  int stage_v_294_2 = ((stage_v_153_2 << 1) ^ (pub_r001015_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_294_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_294_2 + 1) & 15;
  out_sink_1 ^= stage_v_294_1 & 63;
  out_sink_2 ^= stage_v_294_2 & 63;
  int stage_v_295_1 = ((stage_v_170_1 << 1) ^ (pub_r001015_5_1 >> 1)) & 127;
  int stage_v_295_2 = ((stage_v_170_2 << 1) ^ (pub_r001015_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_295_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_295_2 + 1) & 15;
  out_sink_1 ^= stage_v_295_1 & 63;
  out_sink_2 ^= stage_v_295_2 & 63;
  int stage_v_296_1 = ((pub_r001015_20_1 * 2) + 39) & 63;
  int stage_v_296_2 = ((pub_r001015_20_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((stage_v_202_1 << 1) ^ (pub_r001015_16_1 >> 1)) & 127;
  int stage_v_297_2 = ((stage_v_202_2 << 1) ^ (pub_r001015_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_297_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_297_2 + 1) & 15;
  out_sink_1 ^= stage_v_297_1 & 63;
  out_sink_2 ^= stage_v_297_2 & 63;
  int stage_v_298_1 = ((stage_v_55_1 << 1) ^ (pub_r001015_10_1 >> 1)) & 127;
  int stage_v_298_2 = ((stage_v_55_2 << 1) ^ (pub_r001015_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_298_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_298_2 + 1) & 15;
  out_sink_1 ^= stage_v_298_1 & 63;
  out_sink_2 ^= stage_v_298_2 & 63;
  int stage_v_299_1 = ((pub_r001015_10_1 * 2) + 29) & 63;
  int stage_v_299_2 = ((pub_r001015_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((stage_v_61_1 << 1) ^ (pub_r001015_5_1 >> 1)) & 127;
  int stage_v_300_2 = ((stage_v_61_2 << 1) ^ (pub_r001015_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_300_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_300_2 + 1) & 15;
  out_sink_1 ^= stage_v_300_1 & 63;
  out_sink_2 ^= stage_v_300_2 & 63;
  int stage_v_301_1 = ((pub_r001015_0_1 * 2) + 19) & 63;
  int stage_v_301_2 = ((pub_r001015_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001015_4_1 * 2) + 18) & 63;
  int stage_v_302_2 = ((pub_r001015_4_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((stage_v_218_1 << 1) ^ (pub_r001015_3_1 >> 1)) & 127;
  int stage_v_303_2 = ((stage_v_218_2 << 1) ^ (pub_r001015_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_303_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_303_2 + 1) & 15;
  out_sink_1 ^= stage_v_303_1 & 63;
  out_sink_2 ^= stage_v_303_2 & 63;
  int stage_v_304_1 = ((pub_r001015_14_1 * 2) + 25) & 63;
  int stage_v_304_2 = ((pub_r001015_14_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((sec_r001015_0_1 << 1) ^ (pub_r001015_6_1 >> 1)) & 127;
  int stage_v_305_2 = ((sec_r001015_0_2 << 1) ^ (pub_r001015_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_305_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_305_2 + 1) & 15;
  out_sink_1 ^= stage_v_305_1 & 63;
  out_sink_2 ^= stage_v_305_2 & 63;
  int stage_v_306_1 = ((stage_v_174_1 << 1) ^ (pub_r001015_14_1 >> 1)) & 127;
  int stage_v_306_2 = ((stage_v_174_2 << 1) ^ (pub_r001015_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_306_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_306_2 + 1) & 15;
  out_sink_1 ^= stage_v_306_1 & 63;
  out_sink_2 ^= stage_v_306_2 & 63;
  int stage_v_307_1 = ((pub_r001015_9_1 * 2) + 24) & 63;
  int stage_v_307_2 = ((pub_r001015_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((stage_v_180_1 << 1) ^ (pub_r001015_9_1 >> 1)) & 127;
  int stage_v_308_2 = ((stage_v_180_2 << 1) ^ (pub_r001015_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_308_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_308_2 + 1) & 15;
  out_sink_1 ^= stage_v_308_1 & 63;
  out_sink_2 ^= stage_v_308_2 & 63;
  int stage_v_309_1 = ((helper_flow_2_1 << 1) ^ (pub_r001015_19_1 >> 1)) & 127;
  int stage_v_309_2 = ((helper_flow_2_2 << 1) ^ (pub_r001015_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_309_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_309_2 + 1) & 15;
  out_sink_1 ^= stage_v_309_1 & 63;
  out_sink_2 ^= stage_v_309_2 & 63;
  int stage_v_310_1 = ((pub_r001015_9_1 * 2) + 21) & 63;
  int stage_v_310_2 = ((pub_r001015_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((pub_r001015_7_1 * 2) + 7) & 63;
  int stage_v_311_2 = ((pub_r001015_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = ((sec_r001015_1_1 << 1) ^ (pub_r001015_16_1 >> 1)) & 127;
  int stage_v_312_2 = ((sec_r001015_1_2 << 1) ^ (pub_r001015_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_312_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_312_2 + 1) & 15;
  out_sink_1 ^= stage_v_312_1 & 63;
  out_sink_2 ^= stage_v_312_2 & 63;
  int stage_v_313_1 = ((pub_r001015_10_1 * 2) + 21) & 63;
  int stage_v_313_2 = ((pub_r001015_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = ((pub_r001015_8_1 * 2) + 24) & 63;
  int stage_v_314_2 = ((pub_r001015_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001015_7_1 * 2) + 18) & 63;
  int stage_v_315_2 = ((pub_r001015_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((pub_r001015_17_1 * 2) + 26) & 63;
  int stage_v_316_2 = ((pub_r001015_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((stage_v_25_1 << 1) ^ (pub_r001015_0_1 >> 1)) & 127;
  int stage_v_317_2 = ((stage_v_25_2 << 1) ^ (pub_r001015_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_317_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_317_2 + 1) & 15;
  out_sink_1 ^= stage_v_317_1 & 63;
  out_sink_2 ^= stage_v_317_2 & 63;
  int stage_v_318_1 = ((stage_v_184_1 << 1) ^ (pub_r001015_17_1 >> 1)) & 127;
  int stage_v_318_2 = ((stage_v_184_2 << 1) ^ (pub_r001015_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_318_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_318_2 + 1) & 15;
  out_sink_1 ^= stage_v_318_1 & 63;
  out_sink_2 ^= stage_v_318_2 & 63;
  int stage_v_319_1 = ((helper_flow_5_1 << 1) ^ (pub_r001015_10_1 >> 1)) & 127;
  int stage_v_319_2 = ((helper_flow_5_2 << 1) ^ (pub_r001015_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_319_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_319_2 + 1) & 15;
  out_sink_1 ^= stage_v_319_1 & 63;
  out_sink_2 ^= stage_v_319_2 & 63;
  int stage_v_320_1 = ((stage_v_198_1 << 1) ^ (pub_r001015_10_1 >> 1)) & 127;
  int stage_v_320_2 = ((stage_v_198_2 << 1) ^ (pub_r001015_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_320_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_320_2 + 1) & 15;
  out_sink_1 ^= stage_v_320_1 & 63;
  out_sink_2 ^= stage_v_320_2 & 63;
  int stage_v_321_1 = ((stage_v_272_1 << 1) ^ (pub_r001015_20_1 >> 1)) & 127;
  int stage_v_321_2 = ((stage_v_272_2 << 1) ^ (pub_r001015_20_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_321_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_321_2 + 1) & 15;
  out_sink_1 ^= stage_v_321_1 & 63;
  out_sink_2 ^= stage_v_321_2 & 63;
  int stage_v_322_1 = ((sec_r001015_2_1 << 1) ^ (pub_r001015_23_1 >> 1)) & 127;
  int stage_v_322_2 = ((sec_r001015_2_2 << 1) ^ (pub_r001015_23_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_322_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_322_2 + 1) & 15;
  out_sink_1 ^= stage_v_322_1 & 63;
  out_sink_2 ^= stage_v_322_2 & 63;
  int stage_v_323_1 = ((pub_r001015_20_1 * 2) + 35) & 63;
  int stage_v_323_2 = ((pub_r001015_20_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((stage_v_86_1 << 1) ^ (pub_r001015_18_1 >> 1)) & 127;
  int stage_v_324_2 = ((stage_v_86_2 << 1) ^ (pub_r001015_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_324_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_324_2 + 1) & 15;
  out_sink_1 ^= stage_v_324_1 & 63;
  out_sink_2 ^= stage_v_324_2 & 63;
  int stage_v_325_1 = ((stage_v_223_1 << 1) ^ (pub_r001015_9_1 >> 1)) & 127;
  int stage_v_325_2 = ((stage_v_223_2 << 1) ^ (pub_r001015_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_325_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_325_2 + 1) & 15;
  out_sink_1 ^= stage_v_325_1 & 63;
  out_sink_2 ^= stage_v_325_2 & 63;
  int stage_v_326_1 = ((stage_v_292_1 << 1) ^ (pub_r001015_2_1 >> 1)) & 127;
  int stage_v_326_2 = ((stage_v_292_2 << 1) ^ (pub_r001015_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_326_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_326_2 + 1) & 15;
  out_sink_1 ^= stage_v_326_1 & 63;
  out_sink_2 ^= stage_v_326_2 & 63;
  int stage_v_327_1 = ((pub_r001015_13_1 * 2) + 15) & 63;
  int stage_v_327_2 = ((pub_r001015_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((pub_r001015_15_1 * 2) + 46) & 63;
  int stage_v_328_2 = ((pub_r001015_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001015_1_1 * 2) + 17) & 63;
  int stage_v_329_2 = ((pub_r001015_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((stage_v_92_1 << 1) ^ (pub_r001015_18_1 >> 1)) & 127;
  int stage_v_330_2 = ((stage_v_92_2 << 1) ^ (pub_r001015_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_330_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_330_2 + 1) & 15;
  out_sink_1 ^= stage_v_330_1 & 63;
  out_sink_2 ^= stage_v_330_2 & 63;
  int stage_v_331_1 = ((stage_v_242_1 << 1) ^ (pub_r001015_4_1 >> 1)) & 127;
  int stage_v_331_2 = ((stage_v_242_2 << 1) ^ (pub_r001015_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_331_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_331_2 + 1) & 15;
  out_sink_1 ^= stage_v_331_1 & 63;
  out_sink_2 ^= stage_v_331_2 & 63;
  int stage_v_332_1 = ((stage_v_312_1 << 1) ^ (pub_r001015_18_1 >> 1)) & 127;
  int stage_v_332_2 = ((stage_v_312_2 << 1) ^ (pub_r001015_18_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_332_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_332_2 + 1) & 15;
  out_sink_1 ^= stage_v_332_1 & 63;
  out_sink_2 ^= stage_v_332_2 & 63;
  int stage_v_333_1 = ((pub_r001015_19_1 * 2) + 47) & 63;
  int stage_v_333_2 = ((pub_r001015_19_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((pub_r001015_2_1 * 2) + 38) & 63;
  int stage_v_334_2 = ((pub_r001015_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((stage_v_317_1 << 1) ^ (pub_r001015_23_1 >> 1)) & 127;
  int stage_v_335_2 = ((stage_v_317_2 << 1) ^ (pub_r001015_23_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_335_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_335_2 + 1) & 15;
  out_sink_1 ^= stage_v_335_1 & 63;
  out_sink_2 ^= stage_v_335_2 & 63;
  int stage_v_336_1 = ((sec_r001015_4_1 << 1) ^ (pub_r001015_14_1 >> 1)) & 127;
  int stage_v_336_2 = ((sec_r001015_4_2 << 1) ^ (pub_r001015_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_336_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_336_2 + 1) & 15;
  out_sink_1 ^= stage_v_336_1 & 63;
  out_sink_2 ^= stage_v_336_2 & 63;
  int stage_v_337_1 = ((stage_v_140_1 << 1) ^ (pub_r001015_11_1 >> 1)) & 127;
  int stage_v_337_2 = ((stage_v_140_2 << 1) ^ (pub_r001015_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_337_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_337_2 + 1) & 15;
  out_sink_1 ^= stage_v_337_1 & 63;
  out_sink_2 ^= stage_v_337_2 & 63;
  int stage_v_338_1 = ((stage_v_54_1 << 1) ^ (pub_r001015_23_1 >> 1)) & 127;
  int stage_v_338_2 = ((stage_v_54_2 << 1) ^ (pub_r001015_23_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_338_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_338_2 + 1) & 15;
  out_sink_1 ^= stage_v_338_1 & 63;
  out_sink_2 ^= stage_v_338_2 & 63;
  int stage_v_339_1 = ((pub_r001015_10_1 * 2) + 8) & 63;
  int stage_v_339_2 = ((pub_r001015_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((stage_v_29_1 << 1) ^ (pub_r001015_15_1 >> 1)) & 127;
  int stage_v_340_2 = ((stage_v_29_2 << 1) ^ (pub_r001015_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_340_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_340_2 + 1) & 15;
  out_sink_1 ^= stage_v_340_1 & 63;
  out_sink_2 ^= stage_v_340_2 & 63;
  int stage_v_341_1 = ((pub_r001015_15_1 * 2) + 23) & 63;
  int stage_v_341_2 = ((pub_r001015_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((stage_v_174_1 << 1) ^ (pub_r001015_15_1 >> 1)) & 127;
  int stage_v_342_2 = ((stage_v_174_2 << 1) ^ (pub_r001015_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_342_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_342_2 + 1) & 15;
  out_sink_1 ^= stage_v_342_1 & 63;
  out_sink_2 ^= stage_v_342_2 & 63;
  int stage_v_343_1 = ((sec_r001015_15_1 << 1) ^ (pub_r001015_17_1 >> 1)) & 127;
  int stage_v_343_2 = ((sec_r001015_15_2 << 1) ^ (pub_r001015_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_343_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_343_2 + 1) & 15;
  out_sink_1 ^= stage_v_343_1 & 63;
  out_sink_2 ^= stage_v_343_2 & 63;
  int stage_v_344_1 = ((stage_v_142_1 << 1) ^ (pub_r001015_3_1 >> 1)) & 127;
  int stage_v_344_2 = ((stage_v_142_2 << 1) ^ (pub_r001015_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_344_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_344_2 + 1) & 15;
  out_sink_1 ^= stage_v_344_1 & 63;
  out_sink_2 ^= stage_v_344_2 & 63;
  int stage_v_345_1 = ((stage_v_62_1 << 1) ^ (pub_r001015_4_1 >> 1)) & 127;
  int stage_v_345_2 = ((stage_v_62_2 << 1) ^ (pub_r001015_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_345_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_345_2 + 1) & 15;
  out_sink_1 ^= stage_v_345_1 & 63;
  out_sink_2 ^= stage_v_345_2 & 63;
  int stage_v_346_1 = ((stage_v_263_1 << 1) ^ (pub_r001015_20_1 >> 1)) & 127;
  int stage_v_346_2 = ((stage_v_263_2 << 1) ^ (pub_r001015_20_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_346_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_346_2 + 1) & 15;
  out_sink_1 ^= stage_v_346_1 & 63;
  out_sink_2 ^= stage_v_346_2 & 63;
  int stage_v_347_1 = ((pub_r001015_20_1 * 2) + 23) & 63;
  int stage_v_347_2 = ((pub_r001015_20_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((stage_v_121_1 << 1) ^ (pub_r001015_8_1 >> 1)) & 127;
  int stage_v_348_2 = ((stage_v_121_2 << 1) ^ (pub_r001015_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_348_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_348_2 + 1) & 15;
  out_sink_1 ^= stage_v_348_1 & 63;
  out_sink_2 ^= stage_v_348_2 & 63;
  int stage_v_349_1 = ((pub_r001015_21_1 * 2) + 24) & 63;
  int stage_v_349_2 = ((pub_r001015_21_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = ((stage_v_116_1 << 1) ^ (pub_r001015_10_1 >> 1)) & 127;
  int stage_v_350_2 = ((stage_v_116_2 << 1) ^ (pub_r001015_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_350_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_350_2 + 1) & 15;
  out_sink_1 ^= stage_v_350_1 & 63;
  out_sink_2 ^= stage_v_350_2 & 63;
  int stage_v_351_1 = ((stage_v_325_1 << 1) ^ (pub_r001015_7_1 >> 1)) & 127;
  int stage_v_351_2 = ((stage_v_325_2 << 1) ^ (pub_r001015_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_351_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_351_2 + 1) & 15;
  out_sink_1 ^= stage_v_351_1 & 63;
  out_sink_2 ^= stage_v_351_2 & 63;
  int stage_v_352_1 = ((stage_v_272_1 << 1) ^ (pub_r001015_22_1 >> 1)) & 127;
  int stage_v_352_2 = ((stage_v_272_2 << 1) ^ (pub_r001015_22_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_352_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_352_2 + 1) & 15;
  out_sink_1 ^= stage_v_352_1 & 63;
  out_sink_2 ^= stage_v_352_2 & 63;
  int stage_v_353_1 = ((stage_v_267_1 << 1) ^ (pub_r001015_11_1 >> 1)) & 127;
  int stage_v_353_2 = ((stage_v_267_2 << 1) ^ (pub_r001015_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_353_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_353_2 + 1) & 15;
  out_sink_1 ^= stage_v_353_1 & 63;
  out_sink_2 ^= stage_v_353_2 & 63;
  int stage_v_354_1 = ((pub_r001015_21_1 * 2) + 33) & 63;
  int stage_v_354_2 = ((pub_r001015_21_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((pub_r001015_5_1 * 2) + 37) & 63;
  int stage_v_355_2 = ((pub_r001015_5_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((stage_v_123_1 << 1) ^ (pub_r001015_11_1 >> 1)) & 127;
  int stage_v_356_2 = ((stage_v_123_2 << 1) ^ (pub_r001015_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_356_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_356_2 + 1) & 15;
  out_sink_1 ^= stage_v_356_1 & 63;
  out_sink_2 ^= stage_v_356_2 & 63;
  int stage_v_357_1 = ((stage_v_208_1 << 1) ^ (pub_r001015_3_1 >> 1)) & 127;
  int stage_v_357_2 = ((stage_v_208_2 << 1) ^ (pub_r001015_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_357_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_357_2 + 1) & 15;
  out_sink_1 ^= stage_v_357_1 & 63;
  out_sink_2 ^= stage_v_357_2 & 63;
  int stage_v_358_1 = ((pub_r001015_20_1 * 2) + 40) & 63;
  int stage_v_358_2 = ((pub_r001015_20_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001015_11_1 * 2) + 20) & 63;
  int stage_v_359_2 = ((pub_r001015_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((pub_r001015_19_1 * 2) + 19) & 63;
  int stage_v_360_2 = ((pub_r001015_19_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = ((pub_r001015_19_1 * 2) + 38) & 63;
  int stage_v_361_2 = ((pub_r001015_19_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001015_15_1 * 2) + 8) & 63;
  int stage_v_362_2 = ((pub_r001015_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001015_5_1 * 2) + 16) & 63;
  int stage_v_363_2 = ((pub_r001015_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((pub_r001015_8_1 * 2) + 17) & 63;
  int stage_v_364_2 = ((pub_r001015_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((stage_v_63_1 << 1) ^ (pub_r001015_5_1 >> 1)) & 127;
  int stage_v_365_2 = ((stage_v_63_2 << 1) ^ (pub_r001015_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_365_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_365_2 + 1) & 15;
  out_sink_1 ^= stage_v_365_1 & 63;
  out_sink_2 ^= stage_v_365_2 & 63;
  int stage_v_366_1 = ((pub_r001015_20_1 * 2) + 11) & 63;
  int stage_v_366_2 = ((pub_r001015_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = ((stage_v_214_1 << 1) ^ (pub_r001015_10_1 >> 1)) & 127;
  int stage_v_367_2 = ((stage_v_214_2 << 1) ^ (pub_r001015_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_367_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_367_2 + 1) & 15;
  out_sink_1 ^= stage_v_367_1 & 63;
  out_sink_2 ^= stage_v_367_2 & 63;
  int stage_v_368_1 = ((pub_r001015_3_1 * 2) + 27) & 63;
  int stage_v_368_2 = ((pub_r001015_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((stage_v_99_1 << 1) ^ (pub_r001015_17_1 >> 1)) & 127;
  int stage_v_369_2 = ((stage_v_99_2 << 1) ^ (pub_r001015_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_369_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_369_2 + 1) & 15;
  out_sink_1 ^= stage_v_369_1 & 63;
  out_sink_2 ^= stage_v_369_2 & 63;
  int stage_v_370_1 = ((pub_r001015_21_1 * 2) + 9) & 63;
  int stage_v_370_2 = ((pub_r001015_21_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((sec_r001015_15_1 << 1) ^ (pub_r001015_19_1 >> 1)) & 127;
  int stage_v_371_2 = ((sec_r001015_15_2 << 1) ^ (pub_r001015_19_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_371_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_371_2 + 1) & 15;
  out_sink_1 ^= stage_v_371_1 & 63;
  out_sink_2 ^= stage_v_371_2 & 63;
  int stage_v_372_1 = ((stage_v_27_1 << 1) ^ (pub_r001015_16_1 >> 1)) & 127;
  int stage_v_372_2 = ((stage_v_27_2 << 1) ^ (pub_r001015_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_372_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_372_2 + 1) & 15;
  out_sink_1 ^= stage_v_372_1 & 63;
  out_sink_2 ^= stage_v_372_2 & 63;
  int stage_v_373_1 = ((pub_r001015_19_1 * 2) + 39) & 63;
  int stage_v_373_2 = ((pub_r001015_19_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((pub_r001015_20_1 * 2) + 35) & 63;
  int stage_v_374_2 = ((pub_r001015_20_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = ((pub_r001015_1_1 * 2) + 37) & 63;
  int stage_v_375_2 = ((pub_r001015_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((pub_r001015_18_1 * 2) + 24) & 63;
  int stage_v_376_2 = ((pub_r001015_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((pub_r001015_0_1 * 2) + 37) & 63;
  int stage_v_377_2 = ((pub_r001015_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = ((stage_v_16_1 << 1) ^ (pub_r001015_7_1 >> 1)) & 127;
  int stage_v_378_2 = ((stage_v_16_2 << 1) ^ (pub_r001015_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_378_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_378_2 + 1) & 15;
  out_sink_1 ^= stage_v_378_1 & 63;
  out_sink_2 ^= stage_v_378_2 & 63;
  int stage_v_379_1 = ((stage_v_322_1 << 1) ^ (pub_r001015_8_1 >> 1)) & 127;
  int stage_v_379_2 = ((stage_v_322_2 << 1) ^ (pub_r001015_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_379_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_379_2 + 1) & 15;
  out_sink_1 ^= stage_v_379_1 & 63;
  out_sink_2 ^= stage_v_379_2 & 63;
  int stage_v_380_1 = ((pub_r001015_4_1 * 2) + 50) & 63;
  int stage_v_380_2 = ((pub_r001015_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = ((stage_v_208_1 << 1) ^ (pub_r001015_1_1 >> 1)) & 127;
  int stage_v_381_2 = ((stage_v_208_2 << 1) ^ (pub_r001015_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_381_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_381_2 + 1) & 15;
  out_sink_1 ^= stage_v_381_1 & 63;
  out_sink_2 ^= stage_v_381_2 & 63;
  int stage_v_382_1 = ((stage_v_52_1 << 1) ^ (pub_r001015_12_1 >> 1)) & 127;
  int stage_v_382_2 = ((stage_v_52_2 << 1) ^ (pub_r001015_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_382_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_382_2 + 1) & 15;
  out_sink_1 ^= stage_v_382_1 & 63;
  out_sink_2 ^= stage_v_382_2 & 63;
  int stage_v_383_1 = ((pub_r001015_0_1 * 2) + 30) & 63;
  int stage_v_383_2 = ((pub_r001015_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((stage_v_40_1 << 1) ^ (pub_r001015_6_1 >> 1)) & 127;
  int stage_v_384_2 = ((stage_v_40_2 << 1) ^ (pub_r001015_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_384_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_384_2 + 1) & 15;
  out_sink_1 ^= stage_v_384_1 & 63;
  out_sink_2 ^= stage_v_384_2 & 63;
  int stage_v_385_1 = ((pub_r001015_23_1 * 2) + 39) & 63;
  int stage_v_385_2 = ((pub_r001015_23_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001015_12_1 * 2) + 46) & 63;
  int stage_v_386_2 = ((pub_r001015_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((stage_v_345_1 << 1) ^ (pub_r001015_1_1 >> 1)) & 127;
  int stage_v_387_2 = ((stage_v_345_2 << 1) ^ (pub_r001015_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_387_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_387_2 + 1) & 15;
  out_sink_1 ^= stage_v_387_1 & 63;
  out_sink_2 ^= stage_v_387_2 & 63;
  int stage_v_388_1 = ((stage_v_102_1 << 1) ^ (pub_r001015_5_1 >> 1)) & 127;
  int stage_v_388_2 = ((stage_v_102_2 << 1) ^ (pub_r001015_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_388_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_388_2 + 1) & 15;
  out_sink_1 ^= stage_v_388_1 & 63;
  out_sink_2 ^= stage_v_388_2 & 63;
  int stage_v_389_1 = ((stage_v_197_1 << 1) ^ (pub_r001015_21_1 >> 1)) & 127;
  int stage_v_389_2 = ((stage_v_197_2 << 1) ^ (pub_r001015_21_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_389_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_389_2 + 1) & 15;
  out_sink_1 ^= stage_v_389_1 & 63;
  out_sink_2 ^= stage_v_389_2 & 63;
  int stage_v_390_1 = ((pub_r001015_20_1 * 2) + 5) & 63;
  int stage_v_390_2 = ((pub_r001015_20_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((pub_r001015_3_1 * 2) + 13) & 63;
  int stage_v_391_2 = ((pub_r001015_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001015_10_1 * 2) + 7) & 63;
  int stage_v_392_2 = ((pub_r001015_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((stage_v_267_1 << 1) ^ (pub_r001015_5_1 >> 1)) & 127;
  int stage_v_393_2 = ((stage_v_267_2 << 1) ^ (pub_r001015_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_393_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_393_2 + 1) & 15;
  out_sink_1 ^= stage_v_393_1 & 63;
  out_sink_2 ^= stage_v_393_2 & 63;
  int stage_v_394_1 = ((pub_r001015_17_1 * 2) + 16) & 63;
  int stage_v_394_2 = ((pub_r001015_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((pub_r001015_19_1 * 2) + 48) & 63;
  int stage_v_395_2 = ((pub_r001015_19_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((stage_v_351_1 << 1) ^ (pub_r001015_17_1 >> 1)) & 127;
  int stage_v_396_2 = ((stage_v_351_2 << 1) ^ (pub_r001015_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_396_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_396_2 + 1) & 15;
  out_sink_1 ^= stage_v_396_1 & 63;
  out_sink_2 ^= stage_v_396_2 & 63;
  int stage_v_397_1 = ((pub_r001015_0_1 * 2) + 10) & 63;
  int stage_v_397_2 = ((pub_r001015_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((pub_r001015_5_1 * 2) + 21) & 63;
  int stage_v_398_2 = ((pub_r001015_5_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001015_9_1 * 2) + 34) & 63;
  int stage_v_399_2 = ((pub_r001015_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((stage_v_285_1 << 1) ^ (pub_r001015_10_1 >> 1)) & 127;
  int stage_v_400_2 = ((stage_v_285_2 << 1) ^ (pub_r001015_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_400_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_400_2 + 1) & 15;
  out_sink_1 ^= stage_v_400_1 & 63;
  out_sink_2 ^= stage_v_400_2 & 63;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001015_0_1 != sec_r001015_0_2);
  __CPROVER_assume(pub_r001015_10_1 == pub_r001015_10_2);
  __CPROVER_assume(sec_r001015_19_1 != sec_r001015_19_2);
  __CPROVER_assume(sec_r001015_4_1 != sec_r001015_4_2);
  __CPROVER_assume(pub_r001015_1_1 == pub_r001015_1_2);
  __CPROVER_assume(sec_r001015_8_1 != sec_r001015_8_2);
  __CPROVER_assume(sec_r001015_5_1 != sec_r001015_5_2);
  __CPROVER_assume(sec_r001015_1_1 != sec_r001015_1_2);
  __CPROVER_assume(sec_r001015_10_1 != sec_r001015_10_2);
  __CPROVER_assume(pub_r001015_0_1 == pub_r001015_0_2);
  __CPROVER_assume(pub_r001015_14_1 == pub_r001015_14_2);
  __CPROVER_assume(pub_r001015_17_1 == pub_r001015_17_2);
  __CPROVER_assume(pub_r001015_15_1 == pub_r001015_15_2);
  __CPROVER_assume(pub_r001015_3_1 == pub_r001015_3_2);
  __CPROVER_assume(pub_r001015_13_1 == pub_r001015_13_2);
  __CPROVER_assume(pub_r001015_16_1 == pub_r001015_16_2);
  __CPROVER_assume(sec_r001015_9_1 != sec_r001015_9_2);
  __CPROVER_assume(pub_r001015_5_1 == pub_r001015_5_2);
  __CPROVER_assume(pub_r001015_20_1 == pub_r001015_20_2);
  __CPROVER_assume(pub_r001015_6_1 == pub_r001015_6_2);
  __CPROVER_assume(sec_r001015_3_1 != sec_r001015_3_2);
  __CPROVER_assume(sec_r001015_17_1 != sec_r001015_17_2);
  __CPROVER_assume(pub_r001015_9_1 == pub_r001015_9_2);
  __CPROVER_assume(pub_r001015_22_1 == pub_r001015_22_2);
  __CPROVER_assume(pub_r001015_19_1 == pub_r001015_19_2);
  __CPROVER_assume(sec_r001015_7_1 != sec_r001015_7_2);
  __CPROVER_assume(sec_r001015_2_1 != sec_r001015_2_2);
  __CPROVER_assume(sec_r001015_12_1 != sec_r001015_12_2);
  __CPROVER_assume(pub_r001015_23_1 == pub_r001015_23_2);
  __CPROVER_assume(sec_r001015_18_1 != sec_r001015_18_2);
  __CPROVER_assume(sec_r001015_6_1 != sec_r001015_6_2);
  __CPROVER_assume(pub_r001015_2_1 == pub_r001015_2_2);
  __CPROVER_assume(pub_r001015_21_1 == pub_r001015_21_2);
  __CPROVER_assume(pub_r001015_11_1 == pub_r001015_11_2);
  __CPROVER_assume(sec_r001015_15_1 != sec_r001015_15_2);
  __CPROVER_assume(sec_r001015_14_1 != sec_r001015_14_2);
  __CPROVER_assume(pub_r001015_18_1 == pub_r001015_18_2);
  __CPROVER_assume(pub_r001015_7_1 == pub_r001015_7_2);
  __CPROVER_assume(pub_r001015_4_1 == pub_r001015_4_2);
  __CPROVER_assume(pub_r001015_8_1 == pub_r001015_8_2);
  __CPROVER_assume(sec_r001015_13_1 != sec_r001015_13_2);
  __CPROVER_assume(sec_r001015_16_1 != sec_r001015_16_2);
  __CPROVER_assume(sec_r001015_11_1 != sec_r001015_11_2);
  __CPROVER_assume(pub_r001015_12_1 == pub_r001015_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  assert(st_var_1_1.offset == st_var_1_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.stride == st_var_2_2.stride);
  assert(st_var_2_1.trace == st_var_2_2.trace);
  assert(st_var_2_1.dim == st_var_2_2.dim);
  assert(st_var_2_1.density == st_var_2_2.density);
  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.determinant == st_var_2_2.determinant);
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
  assert(helper_flow_7_1 == helper_flow_7_2);
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


