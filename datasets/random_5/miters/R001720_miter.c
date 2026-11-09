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
struct MatrixBlock_R001720_2013_0
{
  int density;
  int stride;
  int scale;
  unsigned char determinant;
  unsigned char trace;
  int dim;
  int buffer[3];
};
struct StreamBuffer_R001720_2013_1
{
  short watermark;
  unsigned char head;
  int checksum;
  int buffer[3];
};
struct Transaction_R001720_2013_2
{
  int rate;
  int status;
  int account_id;
  int buffer[3];
};
struct AudioFrame_R001720_2013_3
{
  unsigned char rms;
  unsigned char peak;
  short gain;
  short envelope;
  int channels;
  int sample_rate;
  int buffer[3];
};
union TelemetryField_R001720_2013_0
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
void fn_R001720_2013_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001720_2013_2 st_1 = {0};
  struct Transaction_R001720_2013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int quotient_97_1 = 0;
  int quotient_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_97_1 = ((quotient_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_97_2 = ((quotient_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_97_1) & 127;
    acc_2 = (acc_2 + quotient_97_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_49_1) & 63;
  aux_2 = (aux_2 + threshold_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_97_1 == quotient_97_2);
  assert(threshold_49_1 == threshold_49_2);
}

int fn_R001720_2013_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001720_2013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int quotient_97 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_97 = ((quotient_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_97) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_49) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001720_2013_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001720_2013_3 st_1 = {0};
  struct AudioFrame_R001720_2013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int bound_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_15_1)
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

  switch (bound_15_2)
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

  int factor_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_12_1 > 10)
  {
    acc_1 = ((acc_1 + (factor_12_1 * 2)) + 5) & 127;
    aux_1 ^= factor_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_12_2 > 10)
  {
    acc_2 = ((acc_2 + (factor_12_2 * 2)) + 5) & 127;
    aux_2 ^= factor_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_15_1 == bound_15_2);
  assert(factor_12_1 == factor_12_2);
}

int fn_R001720_2013_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001720_2013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int bound_15 = (aux + st.buffer[1]) & 3;
  switch (bound_15)
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

  int factor_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_12 > 10)
  {
    acc = ((acc + (factor_12 * 2)) + 5) & 127;
    aux ^= factor_12 & 15;
  }
  else
  {
    acc = ((acc - factor_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001720_2013_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001720_2013_1 st_1 = {0};
  struct StreamBuffer_R001720_2013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int index_reg_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_75_1) & 63;
  aux_2 = (aux_2 + index_reg_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_82_1 > 37)
  {
    acc_1 = ((acc_1 + (factor_82_1 * 2)) + 5) & 127;
    aux_1 ^= factor_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_82_2 > 37)
  {
    acc_2 = ((acc_2 + (factor_82_2 * 2)) + 5) & 127;
    aux_2 ^= factor_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_82_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_68_1 = 0;
  int window_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_68_1 = ((window_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_68_2 = ((window_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_68_1) & 127;
    acc_2 = (acc_2 + window_68_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_31_1 = local_arr_1[aux_1 % 3];
  int residue_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_31_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_75_1 == index_reg_75_2);
  assert(factor_82_1 == factor_82_2);
  assert(window_68_1 == window_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_31_1 == residue_31_2);
}

int fn_R001720_2013_2(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001720_2013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int index_reg_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_75) & 63;
  acc ^= aux;
  int factor_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_82 > 37)
  {
    acc = ((acc + (factor_82 * 2)) + 5) & 127;
    aux ^= factor_82 & 15;
  }
  else
  {
    acc = ((acc - factor_82) + 11) & 127;
    aux += 3;
  }
  int window_68 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_68 = ((window_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_68) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int residue_31 = local_arr[aux % 3];
  acc = (acc + (residue_31 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001720_2013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001720_2013_3 st_1 = {0};
  struct AudioFrame_R001720_2013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_44_1 = local_arr_1[aux_1 % 3];
  int quantum_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_44_2 * 2)) & 127;
  int metric_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_80_1) & 63;
  aux_2 = (aux_2 + metric_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_44_1 == quantum_44_2);
  assert(metric_80_1 == metric_80_2);
}

int fn_R001720_2013_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001720_2013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int quantum_44 = local_arr[aux % 3];
  acc = (acc + (quantum_44 * 2)) & 127;
  int metric_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_80) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001720_2013_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001720_2013_0 st_1 = {0};
  struct MatrixBlock_R001720_2013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int mask_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_80_1 > 49)
  {
    acc_1 = ((acc_1 + (mask_80_1 * 2)) + 5) & 127;
    aux_1 ^= mask_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_80_2 > 49)
  {
    acc_2 = ((acc_2 + (mask_80_2 * 2)) + 5) & 127;
    aux_2 ^= mask_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_80_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_12_1)
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

  switch (tracker_12_2)
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
  int factor_78_1 = local_arr_1[aux_1 % 3];
  int factor_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_78_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_80_1 == mask_80_2);
  assert(tracker_12_1 == tracker_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_78_1 == factor_78_2);
}

int fn_R001720_2013_4(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001720_2013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int mask_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_80 > 49)
  {
    acc = ((acc + (mask_80 * 2)) + 5) & 127;
    aux ^= mask_80 & 15;
  }
  else
  {
    acc = ((acc - mask_80) + 11) & 127;
    aux += 3;
  }
  int tracker_12 = (aux + st.buffer[1]) & 3;
  switch (tracker_12)
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
  int factor_78 = local_arr[aux % 3];
  acc = (acc + (factor_78 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001720_2013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001720_2013_2 st_1 = {0};
  struct Transaction_R001720_2013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int offset_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_29_1)
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

  switch (offset_29_2)
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

  int residue_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_16_1) & 63;
  aux_2 = (aux_2 + residue_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_21_1 = local_arr_1[aux_1 % 3];
  int factor_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_29_1 == offset_29_2);
  assert(residue_16_1 == residue_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_21_1 == factor_21_2);
}

int fn_R001720_2013_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001720_2013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int offset_29 = (aux + st.buffer[1]) & 3;
  switch (offset_29)
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

  int residue_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_16) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_21 = local_arr[aux % 3];
  acc = (acc + (factor_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001720_2013_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001720_2013_1 st_1 = {0};
  struct StreamBuffer_R001720_2013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int index_reg_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_80_1 > 38)
  {
    acc_1 = ((acc_1 + (index_reg_80_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_80_2 > 38)
  {
    acc_2 = ((acc_2 + (index_reg_80_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_80_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_77_1 = local_arr_1[aux_1 % 3];
  int scale_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_77_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_75_1)
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

  switch (parity_75_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_80_1 == index_reg_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_77_1 == scale_77_2);
  assert(parity_75_1 == parity_75_2);
}

int fn_R001720_2013_6(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001720_2013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int index_reg_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_80 > 38)
  {
    acc = ((acc + (index_reg_80 * 2)) + 5) & 127;
    aux ^= index_reg_80 & 15;
  }
  else
  {
    acc = ((acc - index_reg_80) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int scale_77 = local_arr[aux % 3];
  acc = (acc + (scale_77 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_75 = (aux + st.buffer[1]) & 3;
  switch (parity_75)
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

void fn_R001720_2013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001720_2013_3 st_1 = {0};
  struct AudioFrame_R001720_2013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_43_1 > 16)
  {
    acc_1 = ((acc_1 + (pivot_43_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_43_2 > 16)
  {
    acc_2 = ((acc_2 + (pivot_43_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_17_1 = 0;
  int tracker_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_17_1 = ((tracker_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_17_2 = ((tracker_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_17_1) & 127;
    acc_2 = (acc_2 + tracker_17_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_69_1 = local_arr_1[aux_1 % 3];
  int threshold_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_69_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_43_1 == pivot_43_2);
  assert(tracker_17_1 == tracker_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_69_1 == threshold_69_2);
}

int fn_R001720_2013_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001720_2013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_43 > 16)
  {
    acc = ((acc + (pivot_43 * 2)) + 5) & 127;
    aux ^= pivot_43 & 15;
  }
  else
  {
    acc = ((acc - pivot_43) + 11) & 127;
    aux += 3;
  }
  int tracker_17 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_17 = ((tracker_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_17) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int threshold_69 = local_arr[aux % 3];
  acc = (acc + (threshold_69 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001720_2013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001720_2013_0 st_1 = {0};
  struct MatrixBlock_R001720_2013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int window_80_1 = 0;
  int window_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_80_1 = ((window_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_80_2 = ((window_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_80_1) & 127;
    acc_2 = (acc_2 + window_80_2) & 127;
  }

  int factor_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_67_1 > 36)
  {
    acc_1 = ((acc_1 + (factor_67_1 * 2)) + 5) & 127;
    aux_1 ^= factor_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_67_2 > 36)
  {
    acc_2 = ((acc_2 + (factor_67_2 * 2)) + 5) & 127;
    aux_2 ^= factor_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_67_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_11_1) & 63;
  aux_2 = (aux_2 + phase_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_36_1)
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

  switch (segment_36_2)
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
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_80_1 == window_80_2);
  assert(factor_67_1 == factor_67_2);
  assert(phase_11_1 == phase_11_2);
  assert(segment_36_1 == segment_36_2);
}

int fn_R001720_2013_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001720_2013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int window_80 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_80 = ((window_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_80) & 127;
  }

  int factor_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_67 > 36)
  {
    acc = ((acc + (factor_67 * 2)) + 5) & 127;
    aux ^= factor_67 & 15;
  }
  else
  {
    acc = ((acc - factor_67) + 11) & 127;
    aux += 3;
  }
  int phase_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_11) & 63;
  acc ^= aux;
  int segment_36 = (aux + st.buffer[1]) & 3;
  switch (segment_36)
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

void fn_R001720_2013_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001720_2013_3 st_1 = {0};
  struct AudioFrame_R001720_2013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int bound_76_1 = 0;
  int bound_76_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_76_1 = ((bound_76_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_76_2 = ((bound_76_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_76_1) & 127;
    acc_2 = (acc_2 + bound_76_2) & 127;
  }

  int stride_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_76_1)
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

  switch (stride_76_2)
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
  int checksum_50_1 = local_arr_1[aux_1 % 3];
  int checksum_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_50_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_76_1 == bound_76_2);
  assert(stride_76_1 == stride_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_50_1 == checksum_50_2);
}

int fn_R001720_2013_9(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001720_2013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int bound_76 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_76 = ((bound_76 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_76) & 127;
  }

  int stride_76 = (aux + st.buffer[1]) & 3;
  switch (stride_76)
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
  int checksum_50 = local_arr[aux % 3];
  acc = (acc + (checksum_50 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001720_2013_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001720_2013_3 st_1 = {0};
  struct AudioFrame_R001720_2013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_16_1 = local_arr_1[aux_1 % 3];
  int offset_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_16_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_88_1 = 0;
  int margin_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_88_1 = ((margin_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_88_2 = ((margin_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_88_1) & 127;
    acc_2 = (acc_2 + margin_88_2) & 127;
  }

  int anchor_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_46_1) & 63;
  aux_2 = (aux_2 + anchor_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_16_1 == offset_16_2);
  assert(margin_88_1 == margin_88_2);
  assert(anchor_46_1 == anchor_46_2);
}

int fn_R001720_2013_10(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001720_2013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int offset_16 = local_arr[aux % 3];
  acc = (acc + (offset_16 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_88 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_88 = ((margin_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_88) & 127;
  }

  int anchor_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_46) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001720_2013_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001720_2013_2 st_1 = {0};
  struct Transaction_R001720_2013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_14_1 = local_arr_1[aux_1 % 3];
  int offset_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_14_2 * 2)) & 127;
  int checksum_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_32_1 > 12)
  {
    acc_1 = ((acc_1 + (checksum_32_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_32_2 > 12)
  {
    acc_2 = ((acc_2 + (checksum_32_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_32_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_28_1) & 63;
  aux_2 = (aux_2 + stride_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_14_1 == offset_14_2);
  assert(checksum_32_1 == checksum_32_2);
  assert(stride_28_1 == stride_28_2);
}

int fn_R001720_2013_11(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001720_2013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int offset_14 = local_arr[aux % 3];
  acc = (acc + (offset_14 * 2)) & 127;
  int checksum_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_32 > 12)
  {
    acc = ((acc + (checksum_32 * 2)) + 5) & 127;
    aux ^= checksum_32 & 15;
  }
  else
  {
    acc = ((acc - checksum_32) + 11) & 127;
    aux += 3;
  }
  int stride_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_28) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001720_2013_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001720_2013_1 st_1 = {0};
  struct StreamBuffer_R001720_2013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int segment_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_66_1)
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

  switch (segment_66_2)
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
  int margin_36_1 = local_arr_1[aux_1 % 3];
  int margin_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_36_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_13_1 > 38)
  {
    acc_1 = ((acc_1 + (cursor_13_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_13_2 > 38)
  {
    acc_2 = ((acc_2 + (cursor_13_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_13_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_66_1 == segment_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_36_1 == margin_36_2);
  assert(cursor_13_1 == cursor_13_2);
}

int fn_R001720_2013_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001720_2013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int segment_66 = (aux + st.buffer[1]) & 3;
  switch (segment_66)
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
  int margin_36 = local_arr[aux % 3];
  acc = (acc + (margin_36 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_13 > 38)
  {
    acc = ((acc + (cursor_13 * 2)) + 5) & 127;
    aux ^= cursor_13 & 15;
  }
  else
  {
    acc = ((acc - cursor_13) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001720_2013_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001720_2013_0 st_1 = {0};
  struct MatrixBlock_R001720_2013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int sample_69_1 = 0;
  int sample_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_69_1 = ((sample_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_69_2 = ((sample_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_69_1) & 127;
    acc_2 = (acc_2 + sample_69_2) & 127;
  }

  int parity_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_13_1)
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

  switch (parity_13_2)
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

  int damping_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_99_1) & 63;
  aux_2 = (aux_2 + damping_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_69_1 == sample_69_2);
  assert(parity_13_1 == parity_13_2);
  assert(damping_99_1 == damping_99_2);
}

int fn_R001720_2013_13(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001720_2013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int sample_69 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_69 = ((sample_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_69) & 127;
  }

  int parity_13 = (aux + st.buffer[1]) & 3;
  switch (parity_13)
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

  int damping_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001720_2013_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001720_2013_3 st_1 = {0};
  struct AudioFrame_R001720_2013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_63_1 = local_arr_1[aux_1 % 3];
  int segment_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_63_2 * 2)) & 127;
  int factor_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_70_1) & 63;
  aux_2 = (aux_2 + factor_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_92_1)
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

  switch (mask_92_2)
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_63_1 == segment_63_2);
  assert(factor_70_1 == factor_70_2);
  assert(mask_92_1 == mask_92_2);
}

int fn_R001720_2013_14(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001720_2013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int segment_63 = local_arr[aux % 3];
  acc = (acc + (segment_63 * 2)) & 127;
  int factor_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_70) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_92 = (aux + st.buffer[1]) & 3;
  switch (mask_92)
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

void fn_R001720_2013_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001720_2013_2 st_1 = {0};
  struct Transaction_R001720_2013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int phase_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_89_1) & 63;
  aux_2 = (aux_2 + phase_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_15_1 = local_arr_1[aux_1 % 3];
  int delta_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_15_2 * 2)) & 127;
  int quotient_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_98_1 > 23)
  {
    acc_1 = ((acc_1 + (quotient_98_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_98_2 > 23)
  {
    acc_2 = ((acc_2 + (quotient_98_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_98_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_89_1 == phase_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_15_1 == delta_15_2);
  assert(quotient_98_1 == quotient_98_2);
}

int fn_R001720_2013_15(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001720_2013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int phase_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_89) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int delta_15 = local_arr[aux % 3];
  acc = (acc + (delta_15 * 2)) & 127;
  int quotient_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_98 > 23)
  {
    acc = ((acc + (quotient_98 * 2)) + 5) & 127;
    aux ^= quotient_98 & 15;
  }
  else
  {
    acc = ((acc - quotient_98) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001720_2013_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001720_2013_2 st_1 = {0};
  struct Transaction_R001720_2013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_12_1 = local_arr_1[aux_1 % 3];
  int stride_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_12_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_99_1 > 24)
  {
    acc_1 = ((acc_1 + (segment_99_1 * 2)) + 5) & 127;
    aux_1 ^= segment_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_99_2 > 24)
  {
    acc_2 = ((acc_2 + (segment_99_2 * 2)) + 5) & 127;
    aux_2 ^= segment_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_32_1 = 0;
  int factor_32_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_32_1 = ((factor_32_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_32_2 = ((factor_32_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_32_1) & 127;
    acc_2 = (acc_2 + factor_32_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_12_1 == stride_12_2);
  assert(segment_99_1 == segment_99_2);
  assert(factor_32_1 == factor_32_2);
}

int fn_R001720_2013_16(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001720_2013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int stride_12 = local_arr[aux % 3];
  acc = (acc + (stride_12 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_99 > 24)
  {
    acc = ((acc + (segment_99 * 2)) + 5) & 127;
    aux ^= segment_99 & 15;
  }
  else
  {
    acc = ((acc - segment_99) + 11) & 127;
    aux += 3;
  }
  int factor_32 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_32 = ((factor_32 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_32) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001720_2013_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001720_2013_1 st_1 = {0};
  struct StreamBuffer_R001720_2013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_68_1 = local_arr_1[aux_1 % 3];
  int threshold_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_68_2 * 2)) & 127;
  int margin_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_97_1)
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

  switch (margin_97_2)
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

  int offset_72_1 = 0;
  int offset_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_72_1 = ((offset_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_72_2 = ((offset_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_72_1) & 127;
    acc_2 = (acc_2 + offset_72_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_68_1 == threshold_68_2);
  assert(margin_97_1 == margin_97_2);
  assert(offset_72_1 == offset_72_2);
}

int fn_R001720_2013_17(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001720_2013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int threshold_68 = local_arr[aux % 3];
  acc = (acc + (threshold_68 * 2)) & 127;
  int margin_97 = (aux + st.buffer[1]) & 3;
  switch (margin_97)
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

  int offset_72 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_72 = ((offset_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_72) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001720_2013_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001720_2013_1 st_1 = {0};
  struct StreamBuffer_R001720_2013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int bound_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_40_1) & 63;
  aux_2 = (aux_2 + bound_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_44_1 = local_arr_1[aux_1 % 3];
  int quotient_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_44_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_40_1 == bound_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_44_1 == quotient_44_2);
}

int fn_R001720_2013_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001720_2013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int bound_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_40) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_44 = local_arr[aux % 3];
  acc = (acc + (quotient_44 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001720_2013_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001720_2013_0 st_1 = {0};
  struct MatrixBlock_R001720_2013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int tracker_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_88_1 > 23)
  {
    acc_1 = ((acc_1 + (tracker_88_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_88_2 > 23)
  {
    acc_2 = ((acc_2 + (tracker_88_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_88_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_22_1)
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

  switch (coefficient_22_2)
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
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_88_1 == tracker_88_2);
  assert(coefficient_22_1 == coefficient_22_2);
}

int fn_R001720_2013_19(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001720_2013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int tracker_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_88 > 23)
  {
    acc = ((acc + (tracker_88 * 2)) + 5) & 127;
    aux ^= tracker_88 & 15;
  }
  else
  {
    acc = ((acc - tracker_88) + 11) & 127;
    aux += 3;
  }
  int coefficient_22 = (aux + st.buffer[1]) & 3;
  switch (coefficient_22)
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

void fn_R001720_2013_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001720_2013_0 st_1 = {0};
  struct MatrixBlock_R001720_2013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int bound_86_1 = 0;
  int bound_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_86_1 = ((bound_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_86_2 = ((bound_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_86_1) & 127;
    acc_2 = (acc_2 + bound_86_2) & 127;
  }

  int parity_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_84_1)
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

  switch (parity_84_2)
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

  int delta_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_24_1 > 12)
  {
    acc_1 = ((acc_1 + (delta_24_1 * 2)) + 5) & 127;
    aux_1 ^= delta_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_24_2 > 12)
  {
    acc_2 = ((acc_2 + (delta_24_2 * 2)) + 5) & 127;
    aux_2 ^= delta_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_24_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_86_1 == bound_86_2);
  assert(parity_84_1 == parity_84_2);
  assert(delta_24_1 == delta_24_2);
}

int fn_R001720_2013_20(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001720_2013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int bound_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_86 = ((bound_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_86) & 127;
  }

  int parity_84 = (aux + st.buffer[1]) & 3;
  switch (parity_84)
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

  int delta_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_24 > 12)
  {
    acc = ((acc + (delta_24 * 2)) + 5) & 127;
    aux ^= delta_24 & 15;
  }
  else
  {
    acc = ((acc - delta_24) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001720_0_1;
  int sec_r001720_0_2;
  int sec_r001720_1_1;
  int sec_r001720_1_2;
  int sec_r001720_2_1;
  int sec_r001720_2_2;
  int sec_r001720_3_1;
  int sec_r001720_3_2;
  int sec_r001720_4_1;
  int sec_r001720_4_2;
  int sec_r001720_5_1;
  int sec_r001720_5_2;
  int sec_r001720_6_1;
  int sec_r001720_6_2;
  int sec_r001720_7_1;
  int sec_r001720_7_2;
  int sec_r001720_8_1;
  int sec_r001720_8_2;
  int sec_r001720_9_1;
  int sec_r001720_9_2;
  int sec_r001720_10_1;
  int sec_r001720_10_2;
  int sec_r001720_11_1;
  int sec_r001720_11_2;
  int sec_r001720_12_1;
  int sec_r001720_12_2;
  int sec_r001720_13_1;
  int sec_r001720_13_2;
  int sec_r001720_14_1;
  int sec_r001720_14_2;
  int sec_r001720_15_1;
  int sec_r001720_15_2;
  int sec_r001720_16_1;
  int sec_r001720_16_2;
  int sec_r001720_17_1;
  int sec_r001720_17_2;
  int sec_r001720_18_1;
  int sec_r001720_18_2;
  int sec_r001720_19_1;
  int sec_r001720_19_2;
  int sec_r001720_20_1;
  int sec_r001720_20_2;
  int sec_r001720_21_1;
  int sec_r001720_21_2;
  int sec_r001720_22_1;
  int sec_r001720_22_2;
  int sec_r001720_23_1;
  int sec_r001720_23_2;
  int pub_r001720_0_1;
  int pub_r001720_0_2;
  int pub_r001720_1_1;
  int pub_r001720_1_2;
  int pub_r001720_2_1;
  int pub_r001720_2_2;
  int pub_r001720_3_1;
  int pub_r001720_3_2;
  int pub_r001720_4_1;
  int pub_r001720_4_2;
  int pub_r001720_5_1;
  int pub_r001720_5_2;
  int pub_r001720_6_1;
  int pub_r001720_6_2;
  int pub_r001720_7_1;
  int pub_r001720_7_2;
  int pub_r001720_8_1;
  int pub_r001720_8_2;
  int pub_r001720_9_1;
  int pub_r001720_9_2;
  int pub_r001720_10_1;
  int pub_r001720_10_2;
  int pub_r001720_11_1;
  int pub_r001720_11_2;
  int pub_r001720_12_1;
  int pub_r001720_12_2;
  int pub_r001720_13_1;
  int pub_r001720_13_2;
  int pub_r001720_14_1;
  int pub_r001720_14_2;
  int pub_r001720_15_1;
  int pub_r001720_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001720_0_1 >= (-100)) && (pub_r001720_0_1 <= 100));
  __CPROVER_assume((pub_r001720_0_2 >= (-100)) && (pub_r001720_0_2 <= 100));
  __CPROVER_assume((pub_r001720_1_1 >= (-100)) && (pub_r001720_1_1 <= 100));
  __CPROVER_assume((pub_r001720_1_2 >= (-100)) && (pub_r001720_1_2 <= 100));
  __CPROVER_assume((pub_r001720_2_1 >= (-100)) && (pub_r001720_2_1 <= 100));
  __CPROVER_assume((pub_r001720_2_2 >= (-100)) && (pub_r001720_2_2 <= 100));
  __CPROVER_assume((pub_r001720_3_1 >= (-100)) && (pub_r001720_3_1 <= 100));
  __CPROVER_assume((pub_r001720_3_2 >= (-100)) && (pub_r001720_3_2 <= 100));
  __CPROVER_assume((pub_r001720_4_1 >= (-100)) && (pub_r001720_4_1 <= 100));
  __CPROVER_assume((pub_r001720_4_2 >= (-100)) && (pub_r001720_4_2 <= 100));
  __CPROVER_assume((pub_r001720_5_1 >= (-100)) && (pub_r001720_5_1 <= 100));
  __CPROVER_assume((pub_r001720_5_2 >= (-100)) && (pub_r001720_5_2 <= 100));
  __CPROVER_assume((pub_r001720_6_1 >= (-100)) && (pub_r001720_6_1 <= 100));
  __CPROVER_assume((pub_r001720_6_2 >= (-100)) && (pub_r001720_6_2 <= 100));
  __CPROVER_assume((pub_r001720_7_1 >= (-100)) && (pub_r001720_7_1 <= 100));
  __CPROVER_assume((pub_r001720_7_2 >= (-100)) && (pub_r001720_7_2 <= 100));
  __CPROVER_assume((pub_r001720_8_1 >= (-100)) && (pub_r001720_8_1 <= 100));
  __CPROVER_assume((pub_r001720_8_2 >= (-100)) && (pub_r001720_8_2 <= 100));
  __CPROVER_assume((pub_r001720_9_1 >= (-100)) && (pub_r001720_9_1 <= 100));
  __CPROVER_assume((pub_r001720_9_2 >= (-100)) && (pub_r001720_9_2 <= 100));
  __CPROVER_assume((pub_r001720_10_1 >= (-100)) && (pub_r001720_10_1 <= 100));
  __CPROVER_assume((pub_r001720_10_2 >= (-100)) && (pub_r001720_10_2 <= 100));
  __CPROVER_assume((pub_r001720_11_1 >= (-100)) && (pub_r001720_11_1 <= 100));
  __CPROVER_assume((pub_r001720_11_2 >= (-100)) && (pub_r001720_11_2 <= 100));
  __CPROVER_assume((pub_r001720_12_1 >= (-100)) && (pub_r001720_12_1 <= 100));
  __CPROVER_assume((pub_r001720_12_2 >= (-100)) && (pub_r001720_12_2 <= 100));
  __CPROVER_assume((pub_r001720_13_1 >= (-100)) && (pub_r001720_13_1 <= 100));
  __CPROVER_assume((pub_r001720_13_2 >= (-100)) && (pub_r001720_13_2 <= 100));
  __CPROVER_assume((pub_r001720_14_1 >= (-100)) && (pub_r001720_14_1 <= 100));
  __CPROVER_assume((pub_r001720_14_2 >= (-100)) && (pub_r001720_14_2 <= 100));
  __CPROVER_assume((pub_r001720_15_1 >= (-100)) && (pub_r001720_15_1 <= 100));
  __CPROVER_assume((pub_r001720_15_2 >= (-100)) && (pub_r001720_15_2 <= 100));
  __CPROVER_assume((sec_r001720_0_1 >= 0) && (sec_r001720_0_1 <= 255));
  __CPROVER_assume((sec_r001720_0_2 >= 0) && (sec_r001720_0_2 <= 255));
  __CPROVER_assume((sec_r001720_1_1 >= 0) && (sec_r001720_1_1 <= 255));
  __CPROVER_assume((sec_r001720_1_2 >= 0) && (sec_r001720_1_2 <= 255));
  __CPROVER_assume((sec_r001720_2_1 >= 0) && (sec_r001720_2_1 <= 255));
  __CPROVER_assume((sec_r001720_2_2 >= 0) && (sec_r001720_2_2 <= 255));
  __CPROVER_assume((sec_r001720_3_1 >= 0) && (sec_r001720_3_1 <= 255));
  __CPROVER_assume((sec_r001720_3_2 >= 0) && (sec_r001720_3_2 <= 255));
  __CPROVER_assume((sec_r001720_4_1 >= 0) && (sec_r001720_4_1 <= 255));
  __CPROVER_assume((sec_r001720_4_2 >= 0) && (sec_r001720_4_2 <= 255));
  __CPROVER_assume((sec_r001720_5_1 >= 0) && (sec_r001720_5_1 <= 255));
  __CPROVER_assume((sec_r001720_5_2 >= 0) && (sec_r001720_5_2 <= 255));
  __CPROVER_assume((sec_r001720_6_1 >= 0) && (sec_r001720_6_1 <= 255));
  __CPROVER_assume((sec_r001720_6_2 >= 0) && (sec_r001720_6_2 <= 255));
  __CPROVER_assume((sec_r001720_7_1 >= 0) && (sec_r001720_7_1 <= 255));
  __CPROVER_assume((sec_r001720_7_2 >= 0) && (sec_r001720_7_2 <= 255));
  __CPROVER_assume((sec_r001720_8_1 >= 0) && (sec_r001720_8_1 <= 255));
  __CPROVER_assume((sec_r001720_8_2 >= 0) && (sec_r001720_8_2 <= 255));
  __CPROVER_assume((sec_r001720_9_1 >= 0) && (sec_r001720_9_1 <= 255));
  __CPROVER_assume((sec_r001720_9_2 >= 0) && (sec_r001720_9_2 <= 255));
  __CPROVER_assume((sec_r001720_10_1 >= 0) && (sec_r001720_10_1 <= 255));
  __CPROVER_assume((sec_r001720_10_2 >= 0) && (sec_r001720_10_2 <= 255));
  __CPROVER_assume((sec_r001720_11_1 >= 0) && (sec_r001720_11_1 <= 255));
  __CPROVER_assume((sec_r001720_11_2 >= 0) && (sec_r001720_11_2 <= 255));
  __CPROVER_assume((sec_r001720_12_1 >= 0) && (sec_r001720_12_1 <= 255));
  __CPROVER_assume((sec_r001720_12_2 >= 0) && (sec_r001720_12_2 <= 255));
  __CPROVER_assume((sec_r001720_13_1 >= 0) && (sec_r001720_13_1 <= 255));
  __CPROVER_assume((sec_r001720_13_2 >= 0) && (sec_r001720_13_2 <= 255));
  __CPROVER_assume((sec_r001720_14_1 >= 0) && (sec_r001720_14_1 <= 255));
  __CPROVER_assume((sec_r001720_14_2 >= 0) && (sec_r001720_14_2 <= 255));
  __CPROVER_assume((sec_r001720_15_1 >= 0) && (sec_r001720_15_1 <= 255));
  __CPROVER_assume((sec_r001720_15_2 >= 0) && (sec_r001720_15_2 <= 255));
  __CPROVER_assume((sec_r001720_16_1 >= 0) && (sec_r001720_16_1 <= 255));
  __CPROVER_assume((sec_r001720_16_2 >= 0) && (sec_r001720_16_2 <= 255));
  __CPROVER_assume((sec_r001720_17_1 >= 0) && (sec_r001720_17_1 <= 255));
  __CPROVER_assume((sec_r001720_17_2 >= 0) && (sec_r001720_17_2 <= 255));
  __CPROVER_assume((sec_r001720_18_1 >= 0) && (sec_r001720_18_1 <= 255));
  __CPROVER_assume((sec_r001720_18_2 >= 0) && (sec_r001720_18_2 <= 255));
  __CPROVER_assume((sec_r001720_19_1 >= 0) && (sec_r001720_19_1 <= 255));
  __CPROVER_assume((sec_r001720_19_2 >= 0) && (sec_r001720_19_2 <= 255));
  __CPROVER_assume((sec_r001720_20_1 >= 0) && (sec_r001720_20_1 <= 255));
  __CPROVER_assume((sec_r001720_20_2 >= 0) && (sec_r001720_20_2 <= 255));
  __CPROVER_assume((sec_r001720_21_1 >= 0) && (sec_r001720_21_1 <= 255));
  __CPROVER_assume((sec_r001720_21_2 >= 0) && (sec_r001720_21_2 <= 255));
  __CPROVER_assume((sec_r001720_22_1 >= 0) && (sec_r001720_22_1 <= 255));
  __CPROVER_assume((sec_r001720_22_2 >= 0) && (sec_r001720_22_2 <= 255));
  __CPROVER_assume((sec_r001720_23_1 >= 0) && (sec_r001720_23_1 <= 255));
  __CPROVER_assume((sec_r001720_23_2 >= 0) && (sec_r001720_23_2 <= 255));
  struct MatrixBlock_R001720_2013_0 st_var_0_1 = {0};
  struct MatrixBlock_R001720_2013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001720_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001720_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001720_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001720_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001720_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001720_0_2 + 7) & 15;
  struct StreamBuffer_R001720_2013_1 st_var_1_1 = {0};
  struct StreamBuffer_R001720_2013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001720_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001720_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001720_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001720_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001720_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001720_0_2 + 9) & 15;
  struct Transaction_R001720_2013_2 st_var_2_1 = {0};
  struct Transaction_R001720_2013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001720_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001720_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001720_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001720_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001720_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001720_0_2 + 11) & 15;
  struct AudioFrame_R001720_2013_3 st_var_3_1 = {0};
  struct AudioFrame_R001720_2013_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001720_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001720_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001720_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001720_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001720_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001720_0_2 + 13) & 15;
  union TelemetryField_R001720_2013_0 u_var_1;
  union TelemetryField_R001720_2013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001720_2013_0(sec_r001720_0_1, sec_r001720_1_1, pub_r001720_2_1, pub_r001720_3_1, pub_r001720_4_1);
  int helper_flow_0_2 = fn_R001720_2013_0(sec_r001720_0_2, sec_r001720_1_2, pub_r001720_2_2, pub_r001720_3_2, pub_r001720_4_2);
  fn_R001720_2013_0_2(sec_r001720_0_1, sec_r001720_1_1, pub_r001720_2_1, pub_r001720_3_1, pub_r001720_4_1, sec_r001720_0_2, sec_r001720_1_2, pub_r001720_2_2, pub_r001720_3_2, pub_r001720_4_2);
  int helper_flow_1_1 = fn_R001720_2013_1(sec_r001720_1_1, sec_r001720_2_1, pub_r001720_3_1, pub_r001720_4_1, pub_r001720_5_1);
  int helper_flow_1_2 = fn_R001720_2013_1(sec_r001720_1_2, sec_r001720_2_2, pub_r001720_3_2, pub_r001720_4_2, pub_r001720_5_2);
  fn_R001720_2013_1_2(sec_r001720_1_1, sec_r001720_2_1, pub_r001720_3_1, pub_r001720_4_1, pub_r001720_5_1, sec_r001720_1_2, sec_r001720_2_2, pub_r001720_3_2, pub_r001720_4_2, pub_r001720_5_2);
  int helper_flow_2_1 = fn_R001720_2013_2(sec_r001720_2_1, pub_r001720_3_1);
  int helper_flow_2_2 = fn_R001720_2013_2(sec_r001720_2_2, pub_r001720_3_2);
  fn_R001720_2013_2_2(sec_r001720_2_1, pub_r001720_3_1, sec_r001720_2_2, pub_r001720_3_2);
  int helper_flow_3_1 = fn_R001720_2013_3(sec_r001720_3_1, sec_r001720_4_1, pub_r001720_5_1, pub_r001720_6_1, pub_r001720_7_1);
  int helper_flow_3_2 = fn_R001720_2013_3(sec_r001720_3_2, sec_r001720_4_2, pub_r001720_5_2, pub_r001720_6_2, pub_r001720_7_2);
  fn_R001720_2013_3_2(sec_r001720_3_1, sec_r001720_4_1, pub_r001720_5_1, pub_r001720_6_1, pub_r001720_7_1, sec_r001720_3_2, sec_r001720_4_2, pub_r001720_5_2, pub_r001720_6_2, pub_r001720_7_2);
  int helper_flow_4_1 = fn_R001720_2013_4(sec_r001720_4_1, sec_r001720_5_1);
  int helper_flow_4_2 = fn_R001720_2013_4(sec_r001720_4_2, sec_r001720_5_2);
  fn_R001720_2013_4_2(sec_r001720_4_1, sec_r001720_5_1, sec_r001720_4_2, sec_r001720_5_2);
  int helper_flow_5_1 = fn_R001720_2013_5(sec_r001720_5_1, sec_r001720_6_1, pub_r001720_7_1, pub_r001720_8_1, pub_r001720_9_1);
  int helper_flow_5_2 = fn_R001720_2013_5(sec_r001720_5_2, sec_r001720_6_2, pub_r001720_7_2, pub_r001720_8_2, pub_r001720_9_2);
  fn_R001720_2013_5_2(sec_r001720_5_1, sec_r001720_6_1, pub_r001720_7_1, pub_r001720_8_1, pub_r001720_9_1, sec_r001720_5_2, sec_r001720_6_2, pub_r001720_7_2, pub_r001720_8_2, pub_r001720_9_2);
  int helper_flow_6_1 = fn_R001720_2013_6(sec_r001720_6_1, pub_r001720_7_1, pub_r001720_8_1);
  int helper_flow_6_2 = fn_R001720_2013_6(sec_r001720_6_2, pub_r001720_7_2, pub_r001720_8_2);
  fn_R001720_2013_6_2(sec_r001720_6_1, pub_r001720_7_1, pub_r001720_8_1, sec_r001720_6_2, pub_r001720_7_2, pub_r001720_8_2);
  int helper_flow_7_1 = fn_R001720_2013_7(sec_r001720_7_1, sec_r001720_8_1, pub_r001720_9_1, pub_r001720_10_1, pub_r001720_11_1);
  int helper_flow_7_2 = fn_R001720_2013_7(sec_r001720_7_2, sec_r001720_8_2, pub_r001720_9_2, pub_r001720_10_2, pub_r001720_11_2);
  fn_R001720_2013_7_2(sec_r001720_7_1, sec_r001720_8_1, pub_r001720_9_1, pub_r001720_10_1, pub_r001720_11_1, sec_r001720_7_2, sec_r001720_8_2, pub_r001720_9_2, pub_r001720_10_2, pub_r001720_11_2);
  int helper_flow_8_1 = fn_R001720_2013_8(sec_r001720_8_1, pub_r001720_9_1, pub_r001720_10_1, pub_r001720_11_1, pub_r001720_12_1);
  int helper_flow_8_2 = fn_R001720_2013_8(sec_r001720_8_2, pub_r001720_9_2, pub_r001720_10_2, pub_r001720_11_2, pub_r001720_12_2);
  fn_R001720_2013_8_2(sec_r001720_8_1, pub_r001720_9_1, pub_r001720_10_1, pub_r001720_11_1, pub_r001720_12_1, sec_r001720_8_2, pub_r001720_9_2, pub_r001720_10_2, pub_r001720_11_2, pub_r001720_12_2);
  int helper_flow_9_1 = fn_R001720_2013_9(sec_r001720_9_1, pub_r001720_10_1, pub_r001720_11_1);
  int helper_flow_9_2 = fn_R001720_2013_9(sec_r001720_9_2, pub_r001720_10_2, pub_r001720_11_2);
  fn_R001720_2013_9_2(sec_r001720_9_1, pub_r001720_10_1, pub_r001720_11_1, sec_r001720_9_2, pub_r001720_10_2, pub_r001720_11_2);
  int helper_flow_10_1 = fn_R001720_2013_10(sec_r001720_10_1, sec_r001720_11_1, pub_r001720_12_1);
  int helper_flow_10_2 = fn_R001720_2013_10(sec_r001720_10_2, sec_r001720_11_2, pub_r001720_12_2);
  fn_R001720_2013_10_2(sec_r001720_10_1, sec_r001720_11_1, pub_r001720_12_1, sec_r001720_10_2, sec_r001720_11_2, pub_r001720_12_2);
  int helper_flow_11_1 = fn_R001720_2013_11(sec_r001720_11_1, pub_r001720_12_1, pub_r001720_13_1);
  int helper_flow_11_2 = fn_R001720_2013_11(sec_r001720_11_2, pub_r001720_12_2, pub_r001720_13_2);
  fn_R001720_2013_11_2(sec_r001720_11_1, pub_r001720_12_1, pub_r001720_13_1, sec_r001720_11_2, pub_r001720_12_2, pub_r001720_13_2);
  int stage_v_0_1 = (((sec_r001720_5_1 ^ 0x2A) * 2) + pub_r001720_9_1) & 127;
  int stage_v_0_2 = (((sec_r001720_5_2 ^ 0x2A) * 2) + pub_r001720_9_2) & 127;
  if (stage_v_0_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = ((pub_r001720_2_1 * 2) + 45) & 63;
  int stage_v_1_2 = ((pub_r001720_2_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001720_9_1) & 127;
  int stage_v_2_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001720_9_2) & 127;
  if (stage_v_2_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001720_9_1) & 127;
  int stage_v_3_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001720_9_2) & 127;
  if (stage_v_3_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (((sec_r001720_17_1 ^ 0x2A) * 2) + pub_r001720_14_1) & 127;
  int stage_v_4_2 = (((sec_r001720_17_2 ^ 0x2A) * 2) + pub_r001720_14_2) & 127;
  if (stage_v_4_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (((sec_r001720_10_1 ^ 0x2A) * 2) + pub_r001720_5_1) & 127;
  int stage_v_5_2 = (((sec_r001720_10_2 ^ 0x2A) * 2) + pub_r001720_5_2) & 127;
  if (stage_v_5_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001720_9_1) & 127;
  int stage_v_6_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001720_9_2) & 127;
  if (stage_v_6_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001720_0_1) & 127;
  int stage_v_7_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001720_0_2) & 127;
  if (stage_v_7_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((sec_r001720_18_1 ^ 0x2A) * 2) + pub_r001720_8_1) & 127;
  int stage_v_8_2 = (((sec_r001720_18_2 ^ 0x2A) * 2) + pub_r001720_8_2) & 127;
  if (stage_v_8_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((sec_r001720_21_1 ^ 0x2A) * 2) + pub_r001720_4_1) & 127;
  int stage_v_9_2 = (((sec_r001720_21_2 ^ 0x2A) * 2) + pub_r001720_4_2) & 127;
  if (stage_v_9_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = ((pub_r001720_12_1 * 2) + 48) & 63;
  int stage_v_10_2 = ((pub_r001720_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001720_8_1) & 127;
  int stage_v_11_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001720_8_2) & 127;
  if (stage_v_11_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001720_15_1) & 127;
  int stage_v_12_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001720_15_2) & 127;
  if (stage_v_12_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (((sec_r001720_20_1 ^ 0x2A) * 2) + pub_r001720_5_1) & 127;
  int stage_v_13_2 = (((sec_r001720_20_2 ^ 0x2A) * 2) + pub_r001720_5_2) & 127;
  if (stage_v_13_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = ((pub_r001720_9_1 * 2) + 46) & 63;
  int stage_v_14_2 = ((pub_r001720_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (((sec_r001720_17_1 ^ 0x2A) * 2) + pub_r001720_6_1) & 127;
  int stage_v_15_2 = (((sec_r001720_17_2 ^ 0x2A) * 2) + pub_r001720_6_2) & 127;
  if (stage_v_15_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (((sec_r001720_21_1 ^ 0x2A) * 2) + pub_r001720_2_1) & 127;
  int stage_v_16_2 = (((sec_r001720_21_2 ^ 0x2A) * 2) + pub_r001720_2_2) & 127;
  if (stage_v_16_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001720_15_1) & 127;
  int stage_v_17_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001720_15_2) & 127;
  if (stage_v_17_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001720_9_1) & 127;
  int stage_v_18_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001720_9_2) & 127;
  if (stage_v_18_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001720_5_1) & 127;
  int stage_v_19_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001720_5_2) & 127;
  if (stage_v_19_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001720_0_1) & 127;
  int stage_v_20_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001720_0_2) & 127;
  if (stage_v_20_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001720_13_1) & 127;
  int stage_v_21_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001720_13_2) & 127;
  if (stage_v_21_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (((sec_r001720_22_1 ^ 0x2A) * 2) + pub_r001720_1_1) & 127;
  int stage_v_22_2 = (((sec_r001720_22_2 ^ 0x2A) * 2) + pub_r001720_1_2) & 127;
  if (stage_v_22_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001720_11_1) & 127;
  int stage_v_23_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001720_11_2) & 127;
  if (stage_v_23_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001720_7_1) & 127;
  int stage_v_24_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001720_7_2) & 127;
  if (stage_v_24_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (((sec_r001720_5_1 ^ 0x2A) * 2) + pub_r001720_9_1) & 127;
  int stage_v_25_2 = (((sec_r001720_5_2 ^ 0x2A) * 2) + pub_r001720_9_2) & 127;
  if (stage_v_25_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (((sec_r001720_7_1 ^ 0x2A) * 2) + pub_r001720_0_1) & 127;
  int stage_v_26_2 = (((sec_r001720_7_2 ^ 0x2A) * 2) + pub_r001720_0_2) & 127;
  if (stage_v_26_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001720_15_1) & 127;
  int stage_v_27_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001720_15_2) & 127;
  if (stage_v_27_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001720_8_1) & 127;
  int stage_v_28_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001720_8_2) & 127;
  if (stage_v_28_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001720_3_1) & 127;
  int stage_v_29_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001720_3_2) & 127;
  if (stage_v_29_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001720_15_1) & 127;
  int stage_v_30_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001720_15_2) & 127;
  if (stage_v_30_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001720_6_1) & 127;
  int stage_v_31_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001720_6_2) & 127;
  if (stage_v_31_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001720_3_1) & 127;
  int stage_v_32_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001720_3_2) & 127;
  if (stage_v_32_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001720_9_1) & 127;
  int stage_v_33_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001720_9_2) & 127;
  if (stage_v_33_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001720_7_1) & 127;
  int stage_v_34_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001720_7_2) & 127;
  if (stage_v_34_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((pub_r001720_4_1 * 2) + 12) & 63;
  int stage_v_35_2 = ((pub_r001720_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((sec_r001720_14_1 ^ 0x2A) * 2) + pub_r001720_13_1) & 127;
  int stage_v_36_2 = (((sec_r001720_14_2 ^ 0x2A) * 2) + pub_r001720_13_2) & 127;
  if (stage_v_36_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001720_13_1) & 127;
  int stage_v_37_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001720_13_2) & 127;
  if (stage_v_37_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001720_2_1) & 127;
  int stage_v_38_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001720_2_2) & 127;
  if (stage_v_38_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((pub_r001720_0_1 * 2) + 44) & 63;
  int stage_v_39_2 = ((pub_r001720_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001720_2_1) & 127;
  int stage_v_40_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001720_2_2) & 127;
  if (stage_v_40_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001720_14_1) & 127;
  int stage_v_41_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001720_14_2) & 127;
  if (stage_v_41_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((pub_r001720_15_1 * 2) + 36) & 63;
  int stage_v_42_2 = ((pub_r001720_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((sec_r001720_7_1 ^ 0x2A) * 2) + pub_r001720_9_1) & 127;
  int stage_v_43_2 = (((sec_r001720_7_2 ^ 0x2A) * 2) + pub_r001720_9_2) & 127;
  if (stage_v_43_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001720_6_1) & 127;
  int stage_v_44_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001720_6_2) & 127;
  if (stage_v_44_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (((sec_r001720_6_1 ^ 0x2A) * 2) + pub_r001720_12_1) & 127;
  int stage_v_45_2 = (((sec_r001720_6_2 ^ 0x2A) * 2) + pub_r001720_12_2) & 127;
  if (stage_v_45_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001720_11_1) & 127;
  int stage_v_46_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001720_11_2) & 127;
  if (stage_v_46_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (((sec_r001720_3_1 ^ 0x2A) * 2) + pub_r001720_12_1) & 127;
  int stage_v_47_2 = (((sec_r001720_3_2 ^ 0x2A) * 2) + pub_r001720_12_2) & 127;
  if (stage_v_47_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001720_13_1) & 127;
  int stage_v_48_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001720_13_2) & 127;
  if (stage_v_48_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001720_12_1) & 127;
  int stage_v_49_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001720_12_2) & 127;
  if (stage_v_49_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001720_8_1) & 127;
  int stage_v_50_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001720_8_2) & 127;
  if (stage_v_50_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((pub_r001720_3_1 * 2) + 6) & 63;
  int stage_v_51_2 = ((pub_r001720_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((sec_r001720_6_1 ^ 0x2A) * 2) + pub_r001720_11_1) & 127;
  int stage_v_52_2 = (((sec_r001720_6_2 ^ 0x2A) * 2) + pub_r001720_11_2) & 127;
  if (stage_v_52_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001720_13_1) & 127;
  int stage_v_53_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001720_13_2) & 127;
  if (stage_v_53_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001720_2_1) & 127;
  int stage_v_54_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001720_2_2) & 127;
  if (stage_v_54_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001720_5_1) & 127;
  int stage_v_55_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001720_5_2) & 127;
  if (stage_v_55_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001720_12_1) & 127;
  int stage_v_56_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001720_12_2) & 127;
  if (stage_v_56_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001720_14_1) & 127;
  int stage_v_57_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001720_14_2) & 127;
  if (stage_v_57_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((pub_r001720_7_1 * 2) + 29) & 63;
  int stage_v_58_2 = ((pub_r001720_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001720_8_1) & 127;
  int stage_v_59_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001720_8_2) & 127;
  if (stage_v_59_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001720_3_1) & 127;
  int stage_v_60_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001720_3_2) & 127;
  if (stage_v_60_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001720_0_1) & 127;
  int stage_v_61_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001720_0_2) & 127;
  if (stage_v_61_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((pub_r001720_3_1 * 2) + 9) & 63;
  int stage_v_62_2 = ((pub_r001720_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001720_7_1) & 127;
  int stage_v_63_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001720_7_2) & 127;
  if (stage_v_63_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001720_7_1) & 127;
  int stage_v_64_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001720_7_2) & 127;
  if (stage_v_64_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001720_8_1) & 127;
  int stage_v_65_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001720_8_2) & 127;
  if (stage_v_65_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((pub_r001720_0_1 * 2) + 8) & 63;
  int stage_v_66_2 = ((pub_r001720_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001720_7_1) & 127;
  int stage_v_67_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001720_7_2) & 127;
  if (stage_v_67_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001720_7_1) & 127;
  int stage_v_68_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001720_7_2) & 127;
  if (stage_v_68_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((pub_r001720_10_1 * 2) + 28) & 63;
  int stage_v_69_2 = ((pub_r001720_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001720_14_1) & 127;
  int stage_v_70_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001720_14_2) & 127;
  if (stage_v_70_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (((sec_r001720_9_1 ^ 0x2A) * 2) + pub_r001720_12_1) & 127;
  int stage_v_71_2 = (((sec_r001720_9_2 ^ 0x2A) * 2) + pub_r001720_12_2) & 127;
  if (stage_v_71_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((pub_r001720_7_1 * 2) + 35) & 63;
  int stage_v_72_2 = ((pub_r001720_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((sec_r001720_16_1 ^ 0x2A) * 2) + pub_r001720_11_1) & 127;
  int stage_v_73_2 = (((sec_r001720_16_2 ^ 0x2A) * 2) + pub_r001720_11_2) & 127;
  if (stage_v_73_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((pub_r001720_3_1 * 2) + 21) & 63;
  int stage_v_74_2 = ((pub_r001720_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001720_9_1) & 127;
  int stage_v_75_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001720_9_2) & 127;
  if (stage_v_75_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001720_10_1) & 127;
  int stage_v_76_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001720_10_2) & 127;
  if (stage_v_76_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = (((sec_r001720_13_1 ^ 0x2A) * 2) + pub_r001720_7_1) & 127;
  int stage_v_77_2 = (((sec_r001720_13_2 ^ 0x2A) * 2) + pub_r001720_7_2) & 127;
  if (stage_v_77_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((pub_r001720_10_1 * 2) + 47) & 63;
  int stage_v_78_2 = ((pub_r001720_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001720_4_1) & 127;
  int stage_v_79_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001720_4_2) & 127;
  if (stage_v_79_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001720_1_1) & 127;
  int stage_v_80_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001720_1_2) & 127;
  if (stage_v_80_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((pub_r001720_11_1 * 2) + 28) & 63;
  int stage_v_81_2 = ((pub_r001720_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001720_0_1) & 127;
  int stage_v_82_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001720_0_2) & 127;
  if (stage_v_82_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((pub_r001720_4_1 * 2) + 48) & 63;
  int stage_v_83_2 = ((pub_r001720_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001720_5_1) & 127;
  int stage_v_84_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001720_5_2) & 127;
  if (stage_v_84_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((pub_r001720_12_1 * 2) + 33) & 63;
  int stage_v_85_2 = ((pub_r001720_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001720_14_1) & 127;
  int stage_v_86_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001720_14_2) & 127;
  if (stage_v_86_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001720_15_1) & 127;
  int stage_v_87_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001720_15_2) & 127;
  if (stage_v_87_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((pub_r001720_13_1 * 2) + 16) & 63;
  int stage_v_88_2 = ((pub_r001720_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001720_11_1) & 127;
  int stage_v_89_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001720_11_2) & 127;
  if (stage_v_89_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001720_13_1) & 127;
  int stage_v_90_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001720_13_2) & 127;
  if (stage_v_90_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001720_9_1) & 127;
  int stage_v_91_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001720_9_2) & 127;
  if (stage_v_91_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001720_14_1) & 127;
  int stage_v_92_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001720_14_2) & 127;
  if (stage_v_92_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((stage_v_52_1 ^ 0x2A) * 2) + pub_r001720_2_1) & 127;
  int stage_v_93_2 = (((stage_v_52_2 ^ 0x2A) * 2) + pub_r001720_2_2) & 127;
  if (stage_v_93_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((pub_r001720_2_1 * 2) + 20) & 63;
  int stage_v_94_2 = ((pub_r001720_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001720_8_1) & 127;
  int stage_v_95_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001720_8_2) & 127;
  if (stage_v_95_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001720_1_1) & 127;
  int stage_v_96_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001720_1_2) & 127;
  if (stage_v_96_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001720_7_1) & 127;
  int stage_v_97_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001720_7_2) & 127;
  if (stage_v_97_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001720_10_1) & 127;
  int stage_v_98_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001720_10_2) & 127;
  if (stage_v_98_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001720_5_1) & 127;
  int stage_v_99_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001720_5_2) & 127;
  if (stage_v_99_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (((sec_r001720_16_1 ^ 0x2A) * 2) + pub_r001720_15_1) & 127;
  int stage_v_100_2 = (((sec_r001720_16_2 ^ 0x2A) * 2) + pub_r001720_15_2) & 127;
  if (stage_v_100_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = (((sec_r001720_6_1 ^ 0x2A) * 2) + pub_r001720_6_1) & 127;
  int stage_v_101_2 = (((sec_r001720_6_2 ^ 0x2A) * 2) + pub_r001720_6_2) & 127;
  if (stage_v_101_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = (((stage_v_91_1 ^ 0x2A) * 2) + pub_r001720_7_1) & 127;
  int stage_v_102_2 = (((stage_v_91_2 ^ 0x2A) * 2) + pub_r001720_7_2) & 127;
  if (stage_v_102_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001720_15_1) & 127;
  int stage_v_103_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001720_15_2) & 127;
  if (stage_v_103_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001720_11_1) & 127;
  int stage_v_104_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001720_11_2) & 127;
  if (stage_v_104_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((pub_r001720_6_1 * 2) + 47) & 63;
  int stage_v_105_2 = ((pub_r001720_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001720_14_1) & 127;
  int stage_v_106_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001720_14_2) & 127;
  if (stage_v_106_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = (((sec_r001720_17_1 ^ 0x2A) * 2) + pub_r001720_8_1) & 127;
  int stage_v_107_2 = (((sec_r001720_17_2 ^ 0x2A) * 2) + pub_r001720_8_2) & 127;
  if (stage_v_107_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001720_5_1) & 127;
  int stage_v_108_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001720_5_2) & 127;
  if (stage_v_108_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001720_13_1) & 127;
  int stage_v_109_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001720_13_2) & 127;
  if (stage_v_109_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((pub_r001720_7_1 * 2) + 40) & 63;
  int stage_v_110_2 = ((pub_r001720_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001720_4_1) & 127;
  int stage_v_111_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001720_4_2) & 127;
  if (stage_v_111_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001720_9_1) & 127;
  int stage_v_112_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001720_9_2) & 127;
  if (stage_v_112_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001720_15_1) & 127;
  int stage_v_113_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001720_15_2) & 127;
  if (stage_v_113_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001720_6_1) & 127;
  int stage_v_114_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001720_6_2) & 127;
  if (stage_v_114_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001720_8_1) & 127;
  int stage_v_115_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001720_8_2) & 127;
  if (stage_v_115_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001720_8_1) & 127;
  int stage_v_116_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001720_8_2) & 127;
  if (stage_v_116_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = (((sec_r001720_13_1 ^ 0x2A) * 2) + pub_r001720_4_1) & 127;
  int stage_v_117_2 = (((sec_r001720_13_2 ^ 0x2A) * 2) + pub_r001720_4_2) & 127;
  if (stage_v_117_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (((sec_r001720_10_1 ^ 0x2A) * 2) + pub_r001720_1_1) & 127;
  int stage_v_118_2 = (((sec_r001720_10_2 ^ 0x2A) * 2) + pub_r001720_1_2) & 127;
  if (stage_v_118_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001720_9_1) & 127;
  int stage_v_119_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001720_9_2) & 127;
  if (stage_v_119_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (((sec_r001720_13_1 ^ 0x2A) * 2) + pub_r001720_15_1) & 127;
  int stage_v_120_2 = (((sec_r001720_13_2 ^ 0x2A) * 2) + pub_r001720_15_2) & 127;
  if (stage_v_120_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001720_15_1) & 127;
  int stage_v_121_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001720_15_2) & 127;
  if (stage_v_121_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (((stage_v_104_1 ^ 0x2A) * 2) + pub_r001720_13_1) & 127;
  int stage_v_122_2 = (((stage_v_104_2 ^ 0x2A) * 2) + pub_r001720_13_2) & 127;
  if (stage_v_122_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001720_15_1) & 127;
  int stage_v_123_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001720_15_2) & 127;
  if (stage_v_123_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((pub_r001720_3_1 * 2) + 8) & 63;
  int stage_v_124_2 = ((pub_r001720_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001720_0_1 * 2) + 21) & 63;
  int stage_v_125_2 = ((pub_r001720_0_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((stage_v_106_1 ^ 0x2A) * 2) + pub_r001720_15_1) & 127;
  int stage_v_126_2 = (((stage_v_106_2 ^ 0x2A) * 2) + pub_r001720_15_2) & 127;
  if (stage_v_126_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001720_9_1) & 127;
  int stage_v_127_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001720_9_2) & 127;
  if (stage_v_127_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((sec_r001720_22_1 ^ 0x2A) * 2) + pub_r001720_10_1) & 127;
  int stage_v_128_2 = (((sec_r001720_22_2 ^ 0x2A) * 2) + pub_r001720_10_2) & 127;
  if (stage_v_128_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((pub_r001720_15_1 * 2) + 47) & 63;
  int stage_v_129_2 = ((pub_r001720_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001720_14_1 * 2) + 43) & 63;
  int stage_v_130_2 = ((pub_r001720_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001720_13_1) & 127;
  int stage_v_131_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001720_13_2) & 127;
  if (stage_v_131_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001720_5_1) & 127;
  int stage_v_132_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001720_5_2) & 127;
  if (stage_v_132_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001720_8_1) & 127;
  int stage_v_133_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001720_8_2) & 127;
  if (stage_v_133_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((stage_v_107_1 ^ 0x2A) * 2) + pub_r001720_13_1) & 127;
  int stage_v_134_2 = (((stage_v_107_2 ^ 0x2A) * 2) + pub_r001720_13_2) & 127;
  if (stage_v_134_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001720_2_1) & 127;
  int stage_v_135_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001720_2_2) & 127;
  if (stage_v_135_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001720_0_1) & 127;
  int stage_v_136_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001720_0_2) & 127;
  if (stage_v_136_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((pub_r001720_6_1 * 2) + 44) & 63;
  int stage_v_137_2 = ((pub_r001720_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001720_2_1) & 127;
  int stage_v_138_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001720_2_2) & 127;
  if (stage_v_138_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (((stage_v_122_1 ^ 0x2A) * 2) + pub_r001720_8_1) & 127;
  int stage_v_139_2 = (((stage_v_122_2 ^ 0x2A) * 2) + pub_r001720_8_2) & 127;
  if (stage_v_139_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001720_11_1) & 127;
  int stage_v_140_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001720_11_2) & 127;
  if (stage_v_140_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((stage_v_109_1 ^ 0x2A) * 2) + pub_r001720_15_1) & 127;
  int stage_v_141_2 = (((stage_v_109_2 ^ 0x2A) * 2) + pub_r001720_15_2) & 127;
  if (stage_v_141_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001720_15_1) & 127;
  int stage_v_142_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001720_15_2) & 127;
  if (stage_v_142_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((sec_r001720_18_1 ^ 0x2A) * 2) + pub_r001720_10_1) & 127;
  int stage_v_143_2 = (((sec_r001720_18_2 ^ 0x2A) * 2) + pub_r001720_10_2) & 127;
  if (stage_v_143_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001720_6_1) & 127;
  int stage_v_144_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001720_6_2) & 127;
  if (stage_v_144_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((pub_r001720_5_1 * 2) + 19) & 63;
  int stage_v_145_2 = ((pub_r001720_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001720_1_1) & 127;
  int stage_v_146_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001720_1_2) & 127;
  if (stage_v_146_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((pub_r001720_13_1 * 2) + 7) & 63;
  int stage_v_147_2 = ((pub_r001720_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((sec_r001720_18_1 ^ 0x2A) * 2) + pub_r001720_6_1) & 127;
  int stage_v_148_2 = (((sec_r001720_18_2 ^ 0x2A) * 2) + pub_r001720_6_2) & 127;
  if (stage_v_148_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((pub_r001720_7_1 * 2) + 45) & 63;
  int stage_v_149_2 = ((pub_r001720_7_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001720_1_1) & 127;
  int stage_v_150_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001720_1_2) & 127;
  if (stage_v_150_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = (((stage_v_95_1 ^ 0x2A) * 2) + pub_r001720_1_1) & 127;
  int stage_v_151_2 = (((stage_v_95_2 ^ 0x2A) * 2) + pub_r001720_1_2) & 127;
  if (stage_v_151_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001720_0_1) & 127;
  int stage_v_152_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001720_0_2) & 127;
  if (stage_v_152_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = (((stage_v_127_1 ^ 0x2A) * 2) + pub_r001720_7_1) & 127;
  int stage_v_153_2 = (((stage_v_127_2 ^ 0x2A) * 2) + pub_r001720_7_2) & 127;
  if (stage_v_153_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = (((sec_r001720_3_1 ^ 0x2A) * 2) + pub_r001720_10_1) & 127;
  int stage_v_154_2 = (((sec_r001720_3_2 ^ 0x2A) * 2) + pub_r001720_10_2) & 127;
  if (stage_v_154_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001720_11_1) & 127;
  int stage_v_155_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001720_11_2) & 127;
  if (stage_v_155_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001720_1_1) & 127;
  int stage_v_156_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001720_1_2) & 127;
  if (stage_v_156_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((stage_v_77_1 ^ 0x2A) * 2) + pub_r001720_13_1) & 127;
  int stage_v_157_2 = (((stage_v_77_2 ^ 0x2A) * 2) + pub_r001720_13_2) & 127;
  if (stage_v_157_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (((stage_v_91_1 ^ 0x2A) * 2) + pub_r001720_0_1) & 127;
  int stage_v_158_2 = (((stage_v_91_2 ^ 0x2A) * 2) + pub_r001720_0_2) & 127;
  if (stage_v_158_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001720_7_1) & 127;
  int stage_v_159_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001720_7_2) & 127;
  if (stage_v_159_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((pub_r001720_15_1 * 2) + 20) & 63;
  int stage_v_160_2 = ((pub_r001720_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001720_1_1 * 2) + 46) & 63;
  int stage_v_161_2 = ((pub_r001720_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001720_3_1) & 127;
  int stage_v_162_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001720_3_2) & 127;
  if (stage_v_162_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001720_6_1) & 127;
  int stage_v_163_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001720_6_2) & 127;
  if (stage_v_163_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001720_10_1) & 127;
  int stage_v_164_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001720_10_2) & 127;
  if (stage_v_164_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001720_15_1) & 127;
  int stage_v_165_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001720_15_2) & 127;
  if (stage_v_165_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (((stage_v_144_1 ^ 0x2A) * 2) + pub_r001720_10_1) & 127;
  int stage_v_166_2 = (((stage_v_144_2 ^ 0x2A) * 2) + pub_r001720_10_2) & 127;
  if (stage_v_166_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001720_5_1) & 127;
  int stage_v_167_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001720_5_2) & 127;
  if (stage_v_167_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((pub_r001720_2_1 * 2) + 27) & 63;
  int stage_v_168_2 = ((pub_r001720_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (((stage_v_100_1 ^ 0x2A) * 2) + pub_r001720_14_1) & 127;
  int stage_v_169_2 = (((stage_v_100_2 ^ 0x2A) * 2) + pub_r001720_14_2) & 127;
  if (stage_v_169_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((stage_v_52_1 ^ 0x2A) * 2) + pub_r001720_11_1) & 127;
  int stage_v_170_2 = (((stage_v_52_2 ^ 0x2A) * 2) + pub_r001720_11_2) & 127;
  if (stage_v_170_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001720_8_1) & 127;
  int stage_v_171_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001720_8_2) & 127;
  if (stage_v_171_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((pub_r001720_14_1 * 2) + 24) & 63;
  int stage_v_172_2 = ((pub_r001720_14_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001720_3_1) & 127;
  int stage_v_173_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001720_3_2) & 127;
  if (stage_v_173_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((pub_r001720_9_1 * 2) + 5) & 63;
  int stage_v_174_2 = ((pub_r001720_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((stage_v_117_1 ^ 0x2A) * 2) + pub_r001720_4_1) & 127;
  int stage_v_175_2 = (((stage_v_117_2 ^ 0x2A) * 2) + pub_r001720_4_2) & 127;
  if (stage_v_175_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = (((stage_v_63_1 ^ 0x2A) * 2) + pub_r001720_7_1) & 127;
  int stage_v_176_2 = (((stage_v_63_2 ^ 0x2A) * 2) + pub_r001720_7_2) & 127;
  if (stage_v_176_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = (((stage_v_133_1 ^ 0x2A) * 2) + pub_r001720_0_1) & 127;
  int stage_v_177_2 = (((stage_v_133_2 ^ 0x2A) * 2) + pub_r001720_0_2) & 127;
  if (stage_v_177_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001720_3_1) & 127;
  int stage_v_178_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001720_3_2) & 127;
  if (stage_v_178_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((pub_r001720_1_1 * 2) + 23) & 63;
  int stage_v_179_2 = ((pub_r001720_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((sec_r001720_17_1 ^ 0x2A) * 2) + pub_r001720_4_1) & 127;
  int stage_v_180_2 = (((sec_r001720_17_2 ^ 0x2A) * 2) + pub_r001720_4_2) & 127;
  if (stage_v_180_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001720_12_1) & 127;
  int stage_v_181_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001720_12_2) & 127;
  if (stage_v_181_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001720_14_1) & 127;
  int stage_v_182_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001720_14_2) & 127;
  if (stage_v_182_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = (((stage_v_107_1 ^ 0x2A) * 2) + pub_r001720_0_1) & 127;
  int stage_v_183_2 = (((stage_v_107_2 ^ 0x2A) * 2) + pub_r001720_0_2) & 127;
  if (stage_v_183_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((pub_r001720_10_1 * 2) + 42) & 63;
  int stage_v_184_2 = ((pub_r001720_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((stage_v_141_1 ^ 0x2A) * 2) + pub_r001720_10_1) & 127;
  int stage_v_185_2 = (((stage_v_141_2 ^ 0x2A) * 2) + pub_r001720_10_2) & 127;
  if (stage_v_185_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((pub_r001720_10_1 * 2) + 43) & 63;
  int stage_v_186_2 = ((pub_r001720_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = (((stage_v_140_1 ^ 0x2A) * 2) + pub_r001720_11_1) & 127;
  int stage_v_187_2 = (((stage_v_140_2 ^ 0x2A) * 2) + pub_r001720_11_2) & 127;
  if (stage_v_187_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001720_7_1) & 127;
  int stage_v_188_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001720_7_2) & 127;
  if (stage_v_188_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = (((stage_v_153_1 ^ 0x2A) * 2) + pub_r001720_11_1) & 127;
  int stage_v_189_2 = (((stage_v_153_2 ^ 0x2A) * 2) + pub_r001720_11_2) & 127;
  if (stage_v_189_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((pub_r001720_8_1 * 2) + 29) & 63;
  int stage_v_190_2 = ((pub_r001720_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001720_11_1) & 127;
  int stage_v_191_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001720_11_2) & 127;
  if (stage_v_191_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((stage_v_86_1 ^ 0x2A) * 2) + pub_r001720_4_1) & 127;
  int stage_v_192_2 = (((stage_v_86_2 ^ 0x2A) * 2) + pub_r001720_4_2) & 127;
  if (stage_v_192_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001720_7_1) & 127;
  int stage_v_193_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001720_7_2) & 127;
  if (stage_v_193_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001720_6_1) & 127;
  int stage_v_194_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001720_6_2) & 127;
  if (stage_v_194_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = (((stage_v_192_1 ^ 0x2A) * 2) + pub_r001720_10_1) & 127;
  int stage_v_195_2 = (((stage_v_192_2 ^ 0x2A) * 2) + pub_r001720_10_2) & 127;
  if (stage_v_195_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = (((stage_v_77_1 ^ 0x2A) * 2) + pub_r001720_7_1) & 127;
  int stage_v_196_2 = (((stage_v_77_2 ^ 0x2A) * 2) + pub_r001720_7_2) & 127;
  if (stage_v_196_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((pub_r001720_6_1 * 2) + 31) & 63;
  int stage_v_197_2 = ((pub_r001720_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001720_6_1) & 127;
  int stage_v_198_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001720_6_2) & 127;
  if (stage_v_198_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((pub_r001720_0_1 * 2) + 46) & 63;
  int stage_v_199_2 = ((pub_r001720_0_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = (((sec_r001720_3_1 ^ 0x2A) * 2) + pub_r001720_0_1) & 127;
  int stage_v_200_2 = (((sec_r001720_3_2 ^ 0x2A) * 2) + pub_r001720_0_2) & 127;
  if (stage_v_200_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((pub_r001720_15_1 * 2) + 47) & 63;
  int stage_v_201_2 = ((pub_r001720_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((stage_v_156_1 ^ 0x2A) * 2) + pub_r001720_10_1) & 127;
  int stage_v_202_2 = (((stage_v_156_2 ^ 0x2A) * 2) + pub_r001720_10_2) & 127;
  if (stage_v_202_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = (((stage_v_127_1 ^ 0x2A) * 2) + pub_r001720_14_1) & 127;
  int stage_v_203_2 = (((stage_v_127_2 ^ 0x2A) * 2) + pub_r001720_14_2) & 127;
  if (stage_v_203_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001720_0_1 != sec_r001720_0_2);
  __CPROVER_assume(sec_r001720_9_1 != sec_r001720_9_2);
  __CPROVER_assume(pub_r001720_10_1 == pub_r001720_10_2);
  __CPROVER_assume(sec_r001720_21_1 != sec_r001720_21_2);
  __CPROVER_assume(pub_r001720_5_1 == pub_r001720_5_2);
  __CPROVER_assume(sec_r001720_8_1 != sec_r001720_8_2);
  __CPROVER_assume(pub_r001720_0_1 == pub_r001720_0_2);
  __CPROVER_assume(sec_r001720_19_1 != sec_r001720_19_2);
  __CPROVER_assume(pub_r001720_2_1 == pub_r001720_2_2);
  __CPROVER_assume(sec_r001720_2_1 != sec_r001720_2_2);
  __CPROVER_assume(pub_r001720_12_1 == pub_r001720_12_2);
  __CPROVER_assume(sec_r001720_18_1 != sec_r001720_18_2);
  __CPROVER_assume(pub_r001720_6_1 == pub_r001720_6_2);
  __CPROVER_assume(pub_r001720_9_1 == pub_r001720_9_2);
  __CPROVER_assume(pub_r001720_11_1 == pub_r001720_11_2);
  __CPROVER_assume(sec_r001720_15_1 != sec_r001720_15_2);
  __CPROVER_assume(sec_r001720_22_1 != sec_r001720_22_2);
  __CPROVER_assume(sec_r001720_12_1 != sec_r001720_12_2);
  __CPROVER_assume(sec_r001720_5_1 != sec_r001720_5_2);
  __CPROVER_assume(sec_r001720_10_1 != sec_r001720_10_2);
  __CPROVER_assume(pub_r001720_1_1 == pub_r001720_1_2);
  __CPROVER_assume(sec_r001720_6_1 != sec_r001720_6_2);
  __CPROVER_assume(pub_r001720_3_1 == pub_r001720_3_2);
  __CPROVER_assume(pub_r001720_15_1 == pub_r001720_15_2);
  __CPROVER_assume(sec_r001720_20_1 != sec_r001720_20_2);
  __CPROVER_assume(sec_r001720_7_1 != sec_r001720_7_2);
  __CPROVER_assume(sec_r001720_16_1 != sec_r001720_16_2);
  __CPROVER_assume(sec_r001720_3_1 != sec_r001720_3_2);
  __CPROVER_assume(sec_r001720_11_1 != sec_r001720_11_2);
  __CPROVER_assume(pub_r001720_4_1 == pub_r001720_4_2);
  __CPROVER_assume(sec_r001720_17_1 != sec_r001720_17_2);
  __CPROVER_assume(sec_r001720_1_1 != sec_r001720_1_2);
  __CPROVER_assume(sec_r001720_13_1 != sec_r001720_13_2);
  __CPROVER_assume(pub_r001720_14_1 == pub_r001720_14_2);
  __CPROVER_assume(sec_r001720_14_1 != sec_r001720_14_2);
  __CPROVER_assume(sec_r001720_4_1 != sec_r001720_4_2);
  __CPROVER_assume(pub_r001720_7_1 == pub_r001720_7_2);
  __CPROVER_assume(pub_r001720_8_1 == pub_r001720_8_2);
  __CPROVER_assume(pub_r001720_13_1 == pub_r001720_13_2);
  __CPROVER_assume(sec_r001720_23_1 != sec_r001720_23_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.rate == st_var_2_2.rate);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.account_id == st_var_2_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.rms == st_var_3_2.rms);
  assert(st_var_3_1.peak == st_var_3_2.peak);
  assert(st_var_3_1.gain == st_var_3_2.gain);
  assert(st_var_3_1.envelope == st_var_3_2.envelope);
  assert(st_var_3_1.channels == st_var_3_2.channels);
  assert(st_var_3_1.sample_rate == st_var_3_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_3_1.buffer[i_buffer] == st_var_3_2.buffer[i_buffer]);
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
  assert(helper_flow_11_1 == helper_flow_11_2);
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


