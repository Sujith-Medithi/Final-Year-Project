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
struct CipherContext_R001408_813_0
{
  short iv;
  int flags;
  unsigned char nonce;
  short counter;
  int tag;
  int buffer[3];
};
struct EventLog_R001408_813_1
{
  unsigned char timestamp;
  int facility;
  short seq;
  short code;
  short severity;
  short signature;
  int buffer[3];
};
struct AudioFrame_R001408_813_2
{
  short channels;
  int peak;
  int gain;
  int sample_rate;
  int buffer[3];
};
struct MatrixBlock_R001408_813_3
{
  int dim;
  int trace;
  short scale;
  unsigned char density;
  int buffer[3];
};
union TelemetryField_R001408_813_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001408_813_1
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
void fn_R001408_813_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001408_813_0 st_1 = {0};
  struct CipherContext_R001408_813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int phase_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_36_1) & 63;
  aux_2 = (aux_2 + phase_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_57_1 > 15)
  {
    acc_1 = ((acc_1 + (quotient_57_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_57_2 > 15)
  {
    acc_2 = ((acc_2 + (quotient_57_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_57_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_58_1 = 0;
  int margin_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_58_1 = ((margin_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_58_2 = ((margin_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_58_1) & 127;
    acc_2 = (acc_2 + margin_58_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_36_1 == phase_36_2);
  assert(quotient_57_1 == quotient_57_2);
  assert(margin_58_1 == margin_58_2);
}

int fn_R001408_813_0(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001408_813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int phase_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_36) & 63;
  acc ^= aux;
  int quotient_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_57 > 15)
  {
    acc = ((acc + (quotient_57 * 2)) + 5) & 127;
    aux ^= quotient_57 & 15;
  }
  else
  {
    acc = ((acc - quotient_57) + 11) & 127;
    aux += 3;
  }
  int margin_58 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_58 = ((margin_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_58) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001408_813_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001408_813_3 st_1 = {0};
  struct MatrixBlock_R001408_813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_35_1) & 63;
  aux_2 = (aux_2 + pivot_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_44_1 = local_arr_1[aux_1 % 3];
  int segment_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_44_2 * 2)) & 127;
  int segment_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_43_1)
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

  switch (segment_43_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_35_1 == pivot_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_44_1 == segment_44_2);
  assert(segment_43_1 == segment_43_2);
}

int fn_R001408_813_1(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001408_813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_35) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_44 = local_arr[aux % 3];
  acc = (acc + (segment_44 * 2)) & 127;
  int segment_43 = (aux + st.buffer[1]) & 3;
  switch (segment_43)
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

void fn_R001408_813_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001408_813_3 st_1 = {0};
  struct MatrixBlock_R001408_813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int stride_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_38_1 > 42)
  {
    acc_1 = ((acc_1 + (stride_38_1 * 2)) + 5) & 127;
    aux_1 ^= stride_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_38_2 > 42)
  {
    acc_2 = ((acc_2 + (stride_38_2 * 2)) + 5) & 127;
    aux_2 ^= stride_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_76_1)
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

  switch (tracker_76_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_38_1 == stride_38_2);
  assert(tracker_76_1 == tracker_76_2);
}

int fn_R001408_813_2(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001408_813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int stride_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_38 > 42)
  {
    acc = ((acc + (stride_38 * 2)) + 5) & 127;
    aux ^= stride_38 & 15;
  }
  else
  {
    acc = ((acc - stride_38) + 11) & 127;
    aux += 3;
  }
  int tracker_76 = (aux + st.buffer[1]) & 3;
  switch (tracker_76)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001408_813_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001408_813_2 st_1 = {0};
  struct AudioFrame_R001408_813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_21_1 = local_arr_1[aux_1 % 3];
  int weight_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_21_2 * 2)) & 127;
  int tally_77_1 = 0;
  int tally_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_77_1 = ((tally_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_77_2 = ((tally_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_77_1) & 127;
    acc_2 = (acc_2 + tally_77_2) & 127;
  }

  int residue_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_18_1)
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

  switch (residue_18_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_21_1 == weight_21_2);
  assert(tally_77_1 == tally_77_2);
  assert(residue_18_1 == residue_18_2);
}

int fn_R001408_813_3(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001408_813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int weight_21 = local_arr[aux % 3];
  acc = (acc + (weight_21 * 2)) & 127;
  int tally_77 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_77 = ((tally_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_77) & 127;
  }

  int residue_18 = (aux + st.buffer[1]) & 3;
  switch (residue_18)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001408_813_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001408_813_1 st_1 = {0};
  struct EventLog_R001408_813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int offset_98_1 = 0;
  int offset_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_98_1 = ((offset_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_98_2 = ((offset_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_98_1) & 127;
    acc_2 = (acc_2 + offset_98_2) & 127;
  }

  int index_reg_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_20_1)
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

  switch (index_reg_20_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_98_1 == offset_98_2);
  assert(index_reg_20_1 == index_reg_20_2);
}

int fn_R001408_813_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001408_813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int offset_98 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_98 = ((offset_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_98) & 127;
  }

  int index_reg_20 = (aux + st.buffer[1]) & 3;
  switch (index_reg_20)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001408_813_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001408_813_2 st_1 = {0};
  struct AudioFrame_R001408_813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int window_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_81_1) & 63;
  aux_2 = (aux_2 + window_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_42_1 = 0;
  int offset_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_42_1 = ((offset_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_42_2 = ((offset_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_42_1) & 127;
    acc_2 = (acc_2 + offset_42_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_81_1 == window_81_2);
  assert(offset_42_1 == offset_42_2);
}

int fn_R001408_813_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001408_813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int window_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_81) & 63;
  acc ^= aux;
  int offset_42 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_42 = ((offset_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_42) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001408_813_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001408_813_0 st_1 = {0};
  struct CipherContext_R001408_813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int tally_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_91_1 > 45)
  {
    acc_1 = ((acc_1 + (tally_91_1 * 2)) + 5) & 127;
    aux_1 ^= tally_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_91_2 > 45)
  {
    acc_2 = ((acc_2 + (tally_91_2 * 2)) + 5) & 127;
    aux_2 ^= tally_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_46_1)
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

  switch (tally_46_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_95_1 = local_arr_1[aux_1 % 3];
  int damping_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_91_1 == tally_91_2);
  assert(tally_46_1 == tally_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_95_1 == damping_95_2);
}

int fn_R001408_813_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001408_813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int tally_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_91 > 45)
  {
    acc = ((acc + (tally_91 * 2)) + 5) & 127;
    aux ^= tally_91 & 15;
  }
  else
  {
    acc = ((acc - tally_91) + 11) & 127;
    aux += 3;
  }
  int tally_46 = (aux + st.buffer[1]) & 3;
  switch (tally_46)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int damping_95 = local_arr[aux % 3];
  acc = (acc + (damping_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001408_813_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001408_813_0 st_1 = {0};
  struct CipherContext_R001408_813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int accumulator_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_17_1) & 63;
  aux_2 = (aux_2 + accumulator_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_54_1)
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

  switch (delta_54_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_17_1 == accumulator_17_2);
  assert(delta_54_1 == delta_54_2);
}

int fn_R001408_813_7(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001408_813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int accumulator_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_17) & 63;
  acc ^= aux;
  int delta_54 = (aux + st.buffer[1]) & 3;
  switch (delta_54)
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

void fn_R001408_813_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001408_813_0 st_1 = {0};
  struct CipherContext_R001408_813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_82_1 = local_arr_1[aux_1 % 3];
  int window_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_82_2 * 2)) & 127;
  int damping_36_1 = 0;
  int damping_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_36_1 = ((damping_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_36_2 = ((damping_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_36_1) & 127;
    acc_2 = (acc_2 + damping_36_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_82_1 == window_82_2);
  assert(damping_36_1 == damping_36_2);
}

int fn_R001408_813_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001408_813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int window_82 = local_arr[aux % 3];
  acc = (acc + (window_82 * 2)) & 127;
  int damping_36 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_36 = ((damping_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_36) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001408_813_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001408_813_3 st_1 = {0};
  struct MatrixBlock_R001408_813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int phase_95_1 = 0;
  int phase_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_95_1 = ((phase_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_95_2 = ((phase_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_95_1) & 127;
    acc_2 = (acc_2 + phase_95_2) & 127;
  }

  int tracker_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_86_1 > 25)
  {
    acc_1 = ((acc_1 + (tracker_86_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_86_2 > 25)
  {
    acc_2 = ((acc_2 + (tracker_86_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_29_1) & 63;
  aux_2 = (aux_2 + stride_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_95_1 == phase_95_2);
  assert(tracker_86_1 == tracker_86_2);
  assert(stride_29_1 == stride_29_2);
}

int fn_R001408_813_9(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001408_813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int phase_95 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_95 = ((phase_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_95) & 127;
  }

  int tracker_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_86 > 25)
  {
    acc = ((acc + (tracker_86 * 2)) + 5) & 127;
    aux ^= tracker_86 & 15;
  }
  else
  {
    acc = ((acc - tracker_86) + 11) & 127;
    aux += 3;
  }
  int stride_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_29) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001408_813_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001408_813_1 st_1 = {0};
  struct EventLog_R001408_813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int sample_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_98_1) & 63;
  aux_2 = (aux_2 + sample_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_81_1 = local_arr_1[aux_1 % 3];
  int residue_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_81_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_86_1 > 19)
  {
    acc_1 = ((acc_1 + (pivot_86_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_86_2 > 19)
  {
    acc_2 = ((acc_2 + (pivot_86_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_86_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_98_1 == sample_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_81_1 == residue_81_2);
  assert(pivot_86_1 == pivot_86_2);
}

int fn_R001408_813_10(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001408_813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int sample_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_98) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int residue_81 = local_arr[aux % 3];
  acc = (acc + (residue_81 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_86 > 19)
  {
    acc = ((acc + (pivot_86 * 2)) + 5) & 127;
    aux ^= pivot_86 & 15;
  }
  else
  {
    acc = ((acc - pivot_86) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001408_813_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001408_813_2 st_1 = {0};
  struct AudioFrame_R001408_813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_97_1) & 63;
  aux_2 = (aux_2 + damping_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_88_1 = local_arr_1[aux_1 % 3];
  int bound_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_88_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_97_1 == damping_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_88_1 == bound_88_2);
}

int fn_R001408_813_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001408_813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_97) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_88 = local_arr[aux % 3];
  acc = (acc + (bound_88 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001408_813_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001408_813_0 st_1 = {0};
  struct CipherContext_R001408_813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int tracker_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_18_1 > 16)
  {
    acc_1 = ((acc_1 + (tracker_18_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_18_2 > 16)
  {
    acc_2 = ((acc_2 + (tracker_18_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_18_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_48_1) & 63;
  aux_2 = (aux_2 + margin_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_21_1 = local_arr_1[aux_1 % 3];
  int tally_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_18_1 == tracker_18_2);
  assert(margin_48_1 == margin_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_21_1 == tally_21_2);
}

int fn_R001408_813_12(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001408_813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int tracker_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_18 > 16)
  {
    acc = ((acc + (tracker_18 * 2)) + 5) & 127;
    aux ^= tracker_18 & 15;
  }
  else
  {
    acc = ((acc - tracker_18) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_48) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tally_21 = local_arr[aux % 3];
  acc = (acc + (tally_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001408_813_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001408_813_3 st_1 = {0};
  struct MatrixBlock_R001408_813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int weight_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_20_1 > 49)
  {
    acc_1 = ((acc_1 + (weight_20_1 * 2)) + 5) & 127;
    aux_1 ^= weight_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_20_2 > 49)
  {
    acc_2 = ((acc_2 + (weight_20_2 * 2)) + 5) & 127;
    aux_2 ^= weight_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_84_1 = 0;
  int pivot_84_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_84_1 = ((pivot_84_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_84_2 = ((pivot_84_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_84_1) & 127;
    acc_2 = (acc_2 + pivot_84_2) & 127;
  }

  int tracker_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_24_1)
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

  switch (tracker_24_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_20_1 == weight_20_2);
  assert(pivot_84_1 == pivot_84_2);
  assert(tracker_24_1 == tracker_24_2);
}

int fn_R001408_813_13(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001408_813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int weight_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_20 > 49)
  {
    acc = ((acc + (weight_20 * 2)) + 5) & 127;
    aux ^= weight_20 & 15;
  }
  else
  {
    acc = ((acc - weight_20) + 11) & 127;
    aux += 3;
  }
  int pivot_84 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_84 = ((pivot_84 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_84) & 127;
  }

  int tracker_24 = (aux + st.buffer[1]) & 3;
  switch (tracker_24)
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

void fn_R001408_813_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001408_813_1 st_1 = {0};
  struct EventLog_R001408_813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_59_1 = local_arr_1[aux_1 % 3];
  int coefficient_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_59_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_59_1 == coefficient_59_2);
}

int fn_R001408_813_14(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001408_813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int coefficient_59 = local_arr[aux % 3];
  acc = (acc + (coefficient_59 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001408_813_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001408_813_0 st_1 = {0};
  struct CipherContext_R001408_813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int factor_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_56_1 > 34)
  {
    acc_1 = ((acc_1 + (factor_56_1 * 2)) + 5) & 127;
    aux_1 ^= factor_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_56_2 > 34)
  {
    acc_2 = ((acc_2 + (factor_56_2 * 2)) + 5) & 127;
    aux_2 ^= factor_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_56_1)
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

  switch (checksum_56_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_56_1 == factor_56_2);
  assert(checksum_56_1 == checksum_56_2);
}

int fn_R001408_813_15(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001408_813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int factor_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_56 > 34)
  {
    acc = ((acc + (factor_56 * 2)) + 5) & 127;
    aux ^= factor_56 & 15;
  }
  else
  {
    acc = ((acc - factor_56) + 11) & 127;
    aux += 3;
  }
  int checksum_56 = (aux + st.buffer[1]) & 3;
  switch (checksum_56)
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

void fn_R001408_813_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001408_813_3 st_1 = {0};
  struct MatrixBlock_R001408_813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_75_1 = local_arr_1[aux_1 % 3];
  int checksum_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_75_2 * 2)) & 127;
  int segment_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_98_1)
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

  switch (segment_98_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_75_1 == checksum_75_2);
  assert(segment_98_1 == segment_98_2);
}

int fn_R001408_813_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001408_813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int checksum_75 = local_arr[aux % 3];
  acc = (acc + (checksum_75 * 2)) & 127;
  int segment_98 = (aux + st.buffer[1]) & 3;
  switch (segment_98)
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

void fn_R001408_813_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001408_813_2 st_1 = {0};
  struct AudioFrame_R001408_813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int segment_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_90_1)
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

  switch (segment_90_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_71_1 = 0;
  int sample_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_71_1 = ((sample_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_71_2 = ((sample_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_71_1) & 127;
    acc_2 = (acc_2 + sample_71_2) & 127;
  }

  int threshold_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_89_1) & 63;
  aux_2 = (aux_2 + threshold_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_90_1 == segment_90_2);
  assert(sample_71_1 == sample_71_2);
  assert(threshold_89_1 == threshold_89_2);
}

int fn_R001408_813_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001408_813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int segment_90 = (aux + st.buffer[1]) & 3;
  switch (segment_90)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_71 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_71 = ((sample_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_71) & 127;
  }

  int threshold_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_89) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001408_813_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001408_813_3 st_1 = {0};
  struct MatrixBlock_R001408_813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int mask_20_1 = 0;
  int mask_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_20_1 = ((mask_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_20_2 = ((mask_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_20_1) & 127;
    acc_2 = (acc_2 + mask_20_2) & 127;
  }

  int tally_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_73_1) & 63;
  aux_2 = (aux_2 + tally_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_20_1 == mask_20_2);
  assert(tally_73_1 == tally_73_2);
}

int fn_R001408_813_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001408_813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int mask_20 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_20 = ((mask_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_20) & 127;
  }

  int tally_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_73) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001408_813_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001408_813_1 st_1 = {0};
  struct EventLog_R001408_813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_47_1 = local_arr_1[aux_1 % 3];
  int factor_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_47_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_80_1) & 63;
  aux_2 = (aux_2 + tracker_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_47_1 == factor_47_2);
  assert(tracker_80_1 == tracker_80_2);
}

int fn_R001408_813_19(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001408_813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int factor_47 = local_arr[aux % 3];
  acc = (acc + (factor_47 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_80) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001408_813_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001408_813_2 st_1 = {0};
  struct AudioFrame_R001408_813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int parity_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_71_1) & 63;
  aux_2 = (aux_2 + parity_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_57_1 = 0;
  int vector_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_57_1 = ((vector_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_57_2 = ((vector_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_57_1) & 127;
    acc_2 = (acc_2 + vector_57_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_71_1 == parity_71_2);
  assert(vector_57_1 == vector_57_2);
}

int fn_R001408_813_20(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001408_813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int parity_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_71) & 63;
  acc ^= aux;
  int vector_57 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_57 = ((vector_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_57) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001408_813_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001408_813_0 st_1 = {0};
  struct CipherContext_R001408_813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_63_1 = local_arr_1[aux_1 % 3];
  int residue_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_63_2 * 2)) & 127;
  int coefficient_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_52_1)
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

  switch (coefficient_52_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_63_1 == residue_63_2);
  assert(coefficient_52_1 == coefficient_52_2);
}

int fn_R001408_813_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001408_813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int residue_63 = local_arr[aux % 3];
  acc = (acc + (residue_63 * 2)) & 127;
  int coefficient_52 = (aux + st.buffer[1]) & 3;
  switch (coefficient_52)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001408_813_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001408_813_2 st_1 = {0};
  struct AudioFrame_R001408_813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_62_1 = local_arr_1[aux_1 % 3];
  int quotient_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_62_2 * 2)) & 127;
  int scale_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_44_1)
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

  switch (scale_44_2)
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
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_62_1 == quotient_62_2);
  assert(scale_44_1 == scale_44_2);
}

int fn_R001408_813_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001408_813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int quotient_62 = local_arr[aux % 3];
  acc = (acc + (quotient_62 * 2)) & 127;
  int scale_44 = (aux + st.buffer[1]) & 3;
  switch (scale_44)
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
  int sec_r001408_0_1;
  int sec_r001408_0_2;
  int sec_r001408_1_1;
  int sec_r001408_1_2;
  int sec_r001408_2_1;
  int sec_r001408_2_2;
  int sec_r001408_3_1;
  int sec_r001408_3_2;
  int sec_r001408_4_1;
  int sec_r001408_4_2;
  int sec_r001408_5_1;
  int sec_r001408_5_2;
  int sec_r001408_6_1;
  int sec_r001408_6_2;
  int sec_r001408_7_1;
  int sec_r001408_7_2;
  int sec_r001408_8_1;
  int sec_r001408_8_2;
  int sec_r001408_9_1;
  int sec_r001408_9_2;
  int sec_r001408_10_1;
  int sec_r001408_10_2;
  int sec_r001408_11_1;
  int sec_r001408_11_2;
  int sec_r001408_12_1;
  int sec_r001408_12_2;
  int sec_r001408_13_1;
  int sec_r001408_13_2;
  int sec_r001408_14_1;
  int sec_r001408_14_2;
  int sec_r001408_15_1;
  int sec_r001408_15_2;
  int sec_r001408_16_1;
  int sec_r001408_16_2;
  int sec_r001408_17_1;
  int sec_r001408_17_2;
  int sec_r001408_18_1;
  int sec_r001408_18_2;
  int sec_r001408_19_1;
  int sec_r001408_19_2;
  int sec_r001408_20_1;
  int sec_r001408_20_2;
  int sec_r001408_21_1;
  int sec_r001408_21_2;
  int sec_r001408_22_1;
  int sec_r001408_22_2;
  int pub_r001408_0_1;
  int pub_r001408_0_2;
  int pub_r001408_1_1;
  int pub_r001408_1_2;
  int pub_r001408_2_1;
  int pub_r001408_2_2;
  int pub_r001408_3_1;
  int pub_r001408_3_2;
  int pub_r001408_4_1;
  int pub_r001408_4_2;
  int pub_r001408_5_1;
  int pub_r001408_5_2;
  int pub_r001408_6_1;
  int pub_r001408_6_2;
  int pub_r001408_7_1;
  int pub_r001408_7_2;
  int pub_r001408_8_1;
  int pub_r001408_8_2;
  int pub_r001408_9_1;
  int pub_r001408_9_2;
  int pub_r001408_10_1;
  int pub_r001408_10_2;
  int pub_r001408_11_1;
  int pub_r001408_11_2;
  int pub_r001408_12_1;
  int pub_r001408_12_2;
  int pub_r001408_13_1;
  int pub_r001408_13_2;
  int pub_r001408_14_1;
  int pub_r001408_14_2;
  int pub_r001408_15_1;
  int pub_r001408_15_2;
  int pub_r001408_16_1;
  int pub_r001408_16_2;
  int pub_r001408_17_1;
  int pub_r001408_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001408_0_1 >= (-100)) && (pub_r001408_0_1 <= 100));
  __CPROVER_assume((pub_r001408_0_2 >= (-100)) && (pub_r001408_0_2 <= 100));
  __CPROVER_assume((pub_r001408_1_1 >= (-100)) && (pub_r001408_1_1 <= 100));
  __CPROVER_assume((pub_r001408_1_2 >= (-100)) && (pub_r001408_1_2 <= 100));
  __CPROVER_assume((pub_r001408_2_1 >= (-100)) && (pub_r001408_2_1 <= 100));
  __CPROVER_assume((pub_r001408_2_2 >= (-100)) && (pub_r001408_2_2 <= 100));
  __CPROVER_assume((pub_r001408_3_1 >= (-100)) && (pub_r001408_3_1 <= 100));
  __CPROVER_assume((pub_r001408_3_2 >= (-100)) && (pub_r001408_3_2 <= 100));
  __CPROVER_assume((pub_r001408_4_1 >= (-100)) && (pub_r001408_4_1 <= 100));
  __CPROVER_assume((pub_r001408_4_2 >= (-100)) && (pub_r001408_4_2 <= 100));
  __CPROVER_assume((pub_r001408_5_1 >= (-100)) && (pub_r001408_5_1 <= 100));
  __CPROVER_assume((pub_r001408_5_2 >= (-100)) && (pub_r001408_5_2 <= 100));
  __CPROVER_assume((pub_r001408_6_1 >= (-100)) && (pub_r001408_6_1 <= 100));
  __CPROVER_assume((pub_r001408_6_2 >= (-100)) && (pub_r001408_6_2 <= 100));
  __CPROVER_assume((pub_r001408_7_1 >= (-100)) && (pub_r001408_7_1 <= 100));
  __CPROVER_assume((pub_r001408_7_2 >= (-100)) && (pub_r001408_7_2 <= 100));
  __CPROVER_assume((pub_r001408_8_1 >= (-100)) && (pub_r001408_8_1 <= 100));
  __CPROVER_assume((pub_r001408_8_2 >= (-100)) && (pub_r001408_8_2 <= 100));
  __CPROVER_assume((pub_r001408_9_1 >= (-100)) && (pub_r001408_9_1 <= 100));
  __CPROVER_assume((pub_r001408_9_2 >= (-100)) && (pub_r001408_9_2 <= 100));
  __CPROVER_assume((pub_r001408_10_1 >= (-100)) && (pub_r001408_10_1 <= 100));
  __CPROVER_assume((pub_r001408_10_2 >= (-100)) && (pub_r001408_10_2 <= 100));
  __CPROVER_assume((pub_r001408_11_1 >= (-100)) && (pub_r001408_11_1 <= 100));
  __CPROVER_assume((pub_r001408_11_2 >= (-100)) && (pub_r001408_11_2 <= 100));
  __CPROVER_assume((pub_r001408_12_1 >= (-100)) && (pub_r001408_12_1 <= 100));
  __CPROVER_assume((pub_r001408_12_2 >= (-100)) && (pub_r001408_12_2 <= 100));
  __CPROVER_assume((pub_r001408_13_1 >= (-100)) && (pub_r001408_13_1 <= 100));
  __CPROVER_assume((pub_r001408_13_2 >= (-100)) && (pub_r001408_13_2 <= 100));
  __CPROVER_assume((pub_r001408_14_1 >= (-100)) && (pub_r001408_14_1 <= 100));
  __CPROVER_assume((pub_r001408_14_2 >= (-100)) && (pub_r001408_14_2 <= 100));
  __CPROVER_assume((pub_r001408_15_1 >= (-100)) && (pub_r001408_15_1 <= 100));
  __CPROVER_assume((pub_r001408_15_2 >= (-100)) && (pub_r001408_15_2 <= 100));
  __CPROVER_assume((pub_r001408_16_1 >= (-100)) && (pub_r001408_16_1 <= 100));
  __CPROVER_assume((pub_r001408_16_2 >= (-100)) && (pub_r001408_16_2 <= 100));
  __CPROVER_assume((pub_r001408_17_1 >= (-100)) && (pub_r001408_17_1 <= 100));
  __CPROVER_assume((pub_r001408_17_2 >= (-100)) && (pub_r001408_17_2 <= 100));
  __CPROVER_assume((sec_r001408_0_1 >= 0) && (sec_r001408_0_1 <= 255));
  __CPROVER_assume((sec_r001408_0_2 >= 0) && (sec_r001408_0_2 <= 255));
  __CPROVER_assume((sec_r001408_1_1 >= 0) && (sec_r001408_1_1 <= 255));
  __CPROVER_assume((sec_r001408_1_2 >= 0) && (sec_r001408_1_2 <= 255));
  __CPROVER_assume((sec_r001408_2_1 >= 0) && (sec_r001408_2_1 <= 255));
  __CPROVER_assume((sec_r001408_2_2 >= 0) && (sec_r001408_2_2 <= 255));
  __CPROVER_assume((sec_r001408_3_1 >= 0) && (sec_r001408_3_1 <= 255));
  __CPROVER_assume((sec_r001408_3_2 >= 0) && (sec_r001408_3_2 <= 255));
  __CPROVER_assume((sec_r001408_4_1 >= 0) && (sec_r001408_4_1 <= 255));
  __CPROVER_assume((sec_r001408_4_2 >= 0) && (sec_r001408_4_2 <= 255));
  __CPROVER_assume((sec_r001408_5_1 >= 0) && (sec_r001408_5_1 <= 255));
  __CPROVER_assume((sec_r001408_5_2 >= 0) && (sec_r001408_5_2 <= 255));
  __CPROVER_assume((sec_r001408_6_1 >= 0) && (sec_r001408_6_1 <= 255));
  __CPROVER_assume((sec_r001408_6_2 >= 0) && (sec_r001408_6_2 <= 255));
  __CPROVER_assume((sec_r001408_7_1 >= 0) && (sec_r001408_7_1 <= 255));
  __CPROVER_assume((sec_r001408_7_2 >= 0) && (sec_r001408_7_2 <= 255));
  __CPROVER_assume((sec_r001408_8_1 >= 0) && (sec_r001408_8_1 <= 255));
  __CPROVER_assume((sec_r001408_8_2 >= 0) && (sec_r001408_8_2 <= 255));
  __CPROVER_assume((sec_r001408_9_1 >= 0) && (sec_r001408_9_1 <= 255));
  __CPROVER_assume((sec_r001408_9_2 >= 0) && (sec_r001408_9_2 <= 255));
  __CPROVER_assume((sec_r001408_10_1 >= 0) && (sec_r001408_10_1 <= 255));
  __CPROVER_assume((sec_r001408_10_2 >= 0) && (sec_r001408_10_2 <= 255));
  __CPROVER_assume((sec_r001408_11_1 >= 0) && (sec_r001408_11_1 <= 255));
  __CPROVER_assume((sec_r001408_11_2 >= 0) && (sec_r001408_11_2 <= 255));
  __CPROVER_assume((sec_r001408_12_1 >= 0) && (sec_r001408_12_1 <= 255));
  __CPROVER_assume((sec_r001408_12_2 >= 0) && (sec_r001408_12_2 <= 255));
  __CPROVER_assume((sec_r001408_13_1 >= 0) && (sec_r001408_13_1 <= 255));
  __CPROVER_assume((sec_r001408_13_2 >= 0) && (sec_r001408_13_2 <= 255));
  __CPROVER_assume((sec_r001408_14_1 >= 0) && (sec_r001408_14_1 <= 255));
  __CPROVER_assume((sec_r001408_14_2 >= 0) && (sec_r001408_14_2 <= 255));
  __CPROVER_assume((sec_r001408_15_1 >= 0) && (sec_r001408_15_1 <= 255));
  __CPROVER_assume((sec_r001408_15_2 >= 0) && (sec_r001408_15_2 <= 255));
  __CPROVER_assume((sec_r001408_16_1 >= 0) && (sec_r001408_16_1 <= 255));
  __CPROVER_assume((sec_r001408_16_2 >= 0) && (sec_r001408_16_2 <= 255));
  __CPROVER_assume((sec_r001408_17_1 >= 0) && (sec_r001408_17_1 <= 255));
  __CPROVER_assume((sec_r001408_17_2 >= 0) && (sec_r001408_17_2 <= 255));
  __CPROVER_assume((sec_r001408_18_1 >= 0) && (sec_r001408_18_1 <= 255));
  __CPROVER_assume((sec_r001408_18_2 >= 0) && (sec_r001408_18_2 <= 255));
  __CPROVER_assume((sec_r001408_19_1 >= 0) && (sec_r001408_19_1 <= 255));
  __CPROVER_assume((sec_r001408_19_2 >= 0) && (sec_r001408_19_2 <= 255));
  __CPROVER_assume((sec_r001408_20_1 >= 0) && (sec_r001408_20_1 <= 255));
  __CPROVER_assume((sec_r001408_20_2 >= 0) && (sec_r001408_20_2 <= 255));
  __CPROVER_assume((sec_r001408_21_1 >= 0) && (sec_r001408_21_1 <= 255));
  __CPROVER_assume((sec_r001408_21_2 >= 0) && (sec_r001408_21_2 <= 255));
  __CPROVER_assume((sec_r001408_22_1 >= 0) && (sec_r001408_22_1 <= 255));
  __CPROVER_assume((sec_r001408_22_2 >= 0) && (sec_r001408_22_2 <= 255));
  struct CipherContext_R001408_813_0 st_var_0_1 = {0};
  struct CipherContext_R001408_813_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001408_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001408_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001408_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001408_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001408_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001408_0_2 + 7) & 15;
  struct EventLog_R001408_813_1 st_var_1_1 = {0};
  struct EventLog_R001408_813_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001408_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001408_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001408_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001408_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001408_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001408_0_2 + 9) & 15;
  struct AudioFrame_R001408_813_2 st_var_2_1 = {0};
  struct AudioFrame_R001408_813_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001408_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001408_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001408_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001408_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001408_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001408_0_2 + 11) & 15;
  struct MatrixBlock_R001408_813_3 st_var_3_1 = {0};
  struct MatrixBlock_R001408_813_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001408_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001408_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001408_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001408_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001408_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001408_0_2 + 13) & 15;
  union TelemetryField_R001408_813_0 u_var_1;
  union TelemetryField_R001408_813_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001408_813_0(sec_r001408_0_1, sec_r001408_1_1);
  int helper_flow_0_2 = fn_R001408_813_0(sec_r001408_0_2, sec_r001408_1_2);
  fn_R001408_813_0_2(sec_r001408_0_1, sec_r001408_1_1, sec_r001408_0_2, sec_r001408_1_2);
  int helper_flow_1_1 = fn_R001408_813_1(sec_r001408_1_1, sec_r001408_2_1);
  int helper_flow_1_2 = fn_R001408_813_1(sec_r001408_1_2, sec_r001408_2_2);
  fn_R001408_813_1_2(sec_r001408_1_1, sec_r001408_2_1, sec_r001408_1_2, sec_r001408_2_2);
  int helper_flow_2_1 = fn_R001408_813_2(sec_r001408_2_1, pub_r001408_3_1, pub_r001408_4_1);
  int helper_flow_2_2 = fn_R001408_813_2(sec_r001408_2_2, pub_r001408_3_2, pub_r001408_4_2);
  fn_R001408_813_2_2(sec_r001408_2_1, pub_r001408_3_1, pub_r001408_4_1, sec_r001408_2_2, pub_r001408_3_2, pub_r001408_4_2);
  int helper_flow_3_1 = fn_R001408_813_3(sec_r001408_3_1, sec_r001408_4_1, pub_r001408_5_1);
  int helper_flow_3_2 = fn_R001408_813_3(sec_r001408_3_2, sec_r001408_4_2, pub_r001408_5_2);
  fn_R001408_813_3_2(sec_r001408_3_1, sec_r001408_4_1, pub_r001408_5_1, sec_r001408_3_2, sec_r001408_4_2, pub_r001408_5_2);
  int helper_flow_4_1 = fn_R001408_813_4(sec_r001408_4_1, sec_r001408_5_1, pub_r001408_6_1, pub_r001408_7_1);
  int helper_flow_4_2 = fn_R001408_813_4(sec_r001408_4_2, sec_r001408_5_2, pub_r001408_6_2, pub_r001408_7_2);
  fn_R001408_813_4_2(sec_r001408_4_1, sec_r001408_5_1, pub_r001408_6_1, pub_r001408_7_1, sec_r001408_4_2, sec_r001408_5_2, pub_r001408_6_2, pub_r001408_7_2);
  int helper_flow_5_1 = fn_R001408_813_5(sec_r001408_5_1, pub_r001408_6_1, pub_r001408_7_1, pub_r001408_8_1);
  int helper_flow_5_2 = fn_R001408_813_5(sec_r001408_5_2, pub_r001408_6_2, pub_r001408_7_2, pub_r001408_8_2);
  fn_R001408_813_5_2(sec_r001408_5_1, pub_r001408_6_1, pub_r001408_7_1, pub_r001408_8_1, sec_r001408_5_2, pub_r001408_6_2, pub_r001408_7_2, pub_r001408_8_2);
  int helper_flow_6_1 = fn_R001408_813_6(sec_r001408_6_1, sec_r001408_7_1, pub_r001408_8_1, pub_r001408_9_1);
  int helper_flow_6_2 = fn_R001408_813_6(sec_r001408_6_2, sec_r001408_7_2, pub_r001408_8_2, pub_r001408_9_2);
  fn_R001408_813_6_2(sec_r001408_6_1, sec_r001408_7_1, pub_r001408_8_1, pub_r001408_9_1, sec_r001408_6_2, sec_r001408_7_2, pub_r001408_8_2, pub_r001408_9_2);
  int helper_flow_7_1 = fn_R001408_813_7(sec_r001408_7_1, sec_r001408_8_1);
  int helper_flow_7_2 = fn_R001408_813_7(sec_r001408_7_2, sec_r001408_8_2);
  fn_R001408_813_7_2(sec_r001408_7_1, sec_r001408_8_1, sec_r001408_7_2, sec_r001408_8_2);
  int helper_flow_8_1 = fn_R001408_813_8(sec_r001408_8_1, sec_r001408_9_1, pub_r001408_10_1, pub_r001408_11_1, pub_r001408_12_1);
  int helper_flow_8_2 = fn_R001408_813_8(sec_r001408_8_2, sec_r001408_9_2, pub_r001408_10_2, pub_r001408_11_2, pub_r001408_12_2);
  fn_R001408_813_8_2(sec_r001408_8_1, sec_r001408_9_1, pub_r001408_10_1, pub_r001408_11_1, pub_r001408_12_1, sec_r001408_8_2, sec_r001408_9_2, pub_r001408_10_2, pub_r001408_11_2, pub_r001408_12_2);
  int helper_flow_9_1 = fn_R001408_813_9(sec_r001408_9_1, sec_r001408_10_1, pub_r001408_11_1);
  int helper_flow_9_2 = fn_R001408_813_9(sec_r001408_9_2, sec_r001408_10_2, pub_r001408_11_2);
  fn_R001408_813_9_2(sec_r001408_9_1, sec_r001408_10_1, pub_r001408_11_1, sec_r001408_9_2, sec_r001408_10_2, pub_r001408_11_2);
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_0_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_0_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_0_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_0_2) + 7) & 255;
    }
  }

  int stage_v_1_1 = ((pub_r001408_7_1 * 2) + 21) & 63;
  int stage_v_1_2 = ((pub_r001408_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001408_16_1 * 2) + 50) & 63;
  int stage_v_2_2 = ((pub_r001408_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = 0;
  int stage_v_3_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_3_1 = ((stage_v_3_1 + (it_1 * 3)) + (sec_r001408_8_1 & 15)) & 63;
    stage_v_3_2 = ((stage_v_3_2 + (it_2 * 3)) + (sec_r001408_8_2 & 15)) & 63;
    if ((sec_r001408_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_3_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_3_1) + 7) & 255;
    }
    if ((sec_r001408_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_3_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_3_2) + 7) & 255;
    }
  }

  int stage_v_4_1 = 0;
  int stage_v_4_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_4_1 = ((stage_v_4_1 + (it_1 * 3)) + (sec_r001408_4_1 & 15)) & 63;
    stage_v_4_2 = ((stage_v_4_2 + (it_2 * 3)) + (sec_r001408_4_2 & 15)) & 63;
    if ((sec_r001408_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_4_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_4_1) + 7) & 255;
    }
    if ((sec_r001408_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_4_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_4_2) + 7) & 255;
    }
  }

  int stage_v_5_1 = ((pub_r001408_3_1 * 2) + 10) & 63;
  int stage_v_5_2 = ((pub_r001408_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001408_12_1 * 2) + 43) & 63;
  int stage_v_6_2 = ((pub_r001408_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = 0;
  int stage_v_7_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_7_1 = ((stage_v_7_1 + (it_1 * 3)) + (sec_r001408_6_1 & 15)) & 63;
    stage_v_7_2 = ((stage_v_7_2 + (it_2 * 3)) + (sec_r001408_6_2 & 15)) & 63;
    if ((sec_r001408_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_7_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_7_1) + 7) & 255;
    }
    if ((sec_r001408_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_7_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_7_2) + 7) & 255;
    }
  }

  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (it_1 * 3)) + (sec_r001408_7_1 & 15)) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (it_2 * 3)) + (sec_r001408_7_2 & 15)) & 63;
    if ((sec_r001408_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_8_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_8_1) + 7) & 255;
    }
    if ((sec_r001408_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_8_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_8_2) + 7) & 255;
    }
  }

  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_9_1 = ((stage_v_9_1 + (it_1 * 3)) + (helper_flow_2_1 & 15)) & 63;
    stage_v_9_2 = ((stage_v_9_2 + (it_2 * 3)) + (helper_flow_2_2 & 15)) & 63;
    if ((helper_flow_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_9_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_9_1) + 7) & 255;
    }
    if ((helper_flow_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_9_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_9_2) + 7) & 255;
    }
  }

  int stage_v_10_1 = ((pub_r001408_4_1 * 2) + 39) & 63;
  int stage_v_10_2 = ((pub_r001408_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (it_1 * 3)) + (sec_r001408_4_1 & 15)) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (it_2 * 3)) + (sec_r001408_4_2 & 15)) & 63;
    if ((sec_r001408_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_11_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_11_1) + 7) & 255;
    }
    if ((sec_r001408_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_11_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_11_2) + 7) & 255;
    }
  }

  int stage_v_12_1 = ((pub_r001408_14_1 * 2) + 32) & 63;
  int stage_v_12_2 = ((pub_r001408_14_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (it_1 * 3)) + (helper_flow_2_1 & 15)) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (it_2 * 3)) + (helper_flow_2_2 & 15)) & 63;
    if ((helper_flow_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_13_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_13_1) + 7) & 255;
    }
    if ((helper_flow_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_13_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_13_2) + 7) & 255;
    }
  }

  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (it_1 * 3)) + (helper_flow_4_1 & 15)) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (it_2 * 3)) + (helper_flow_4_2 & 15)) & 63;
    if ((helper_flow_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_14_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_14_1) + 7) & 255;
    }
    if ((helper_flow_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_14_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_14_2) + 7) & 255;
    }
  }

  int stage_v_15_1 = ((pub_r001408_16_1 * 2) + 43) & 63;
  int stage_v_15_2 = ((pub_r001408_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001408_0_1 * 2) + 13) & 63;
  int stage_v_16_2 = ((pub_r001408_0_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001408_3_1 * 2) + 41) & 63;
  int stage_v_17_2 = ((pub_r001408_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001408_17_1 * 2) + 18) & 63;
  int stage_v_18_2 = ((pub_r001408_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (it_1 * 3)) + (sec_r001408_7_1 & 15)) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (it_2 * 3)) + (sec_r001408_7_2 & 15)) & 63;
    if ((sec_r001408_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_19_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_19_1) + 7) & 255;
    }
    if ((sec_r001408_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_19_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_19_2) + 7) & 255;
    }
  }

  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (it_1 * 3)) + (sec_r001408_8_1 & 15)) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (it_2 * 3)) + (sec_r001408_8_2 & 15)) & 63;
    if ((sec_r001408_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_20_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_20_1) + 7) & 255;
    }
    if ((sec_r001408_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_20_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_20_2) + 7) & 255;
    }
  }

  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_21_1 = ((stage_v_21_1 + (it_1 * 3)) + (sec_r001408_0_1 & 15)) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (it_2 * 3)) + (sec_r001408_0_2 & 15)) & 63;
    if ((sec_r001408_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_21_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_21_1) + 7) & 255;
    }
    if ((sec_r001408_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_21_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_21_2) + 7) & 255;
    }
  }

  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (it_1 * 3)) + (stage_v_3_1 & 15)) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (it_2 * 3)) + (stage_v_3_2 & 15)) & 63;
    if ((stage_v_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_22_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_22_1) + 7) & 255;
    }
    if ((stage_v_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_22_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_22_2) + 7) & 255;
    }
  }

  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (it_1 * 3)) + (sec_r001408_8_1 & 15)) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (it_2 * 3)) + (sec_r001408_8_2 & 15)) & 63;
    if ((sec_r001408_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_23_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_23_1) + 7) & 255;
    }
    if ((sec_r001408_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_23_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_23_2) + 7) & 255;
    }
  }

  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (it_1 * 3)) + (sec_r001408_12_1 & 15)) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (it_2 * 3)) + (sec_r001408_12_2 & 15)) & 63;
    if ((sec_r001408_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_24_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_24_1) + 7) & 255;
    }
    if ((sec_r001408_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_24_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_24_2) + 7) & 255;
    }
  }

  int stage_v_25_1 = ((pub_r001408_12_1 * 2) + 39) & 63;
  int stage_v_25_2 = ((pub_r001408_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001408_3_1 * 2) + 20) & 63;
  int stage_v_26_2 = ((pub_r001408_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (it_1 * 3)) + (stage_v_3_1 & 15)) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (it_2 * 3)) + (stage_v_3_2 & 15)) & 63;
    if ((stage_v_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_27_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_27_1) + 7) & 255;
    }
    if ((stage_v_3_2 & 1) != 0)
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
    stage_v_28_1 = ((stage_v_28_1 + (it_1 * 3)) + (sec_r001408_5_1 & 15)) & 63;
    stage_v_28_2 = ((stage_v_28_2 + (it_2 * 3)) + (sec_r001408_5_2 & 15)) & 63;
    if ((sec_r001408_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_28_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_28_1) + 7) & 255;
    }
    if ((sec_r001408_5_2 & 1) != 0)
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
    stage_v_29_1 = ((stage_v_29_1 + (it_1 * 3)) + (sec_r001408_12_1 & 15)) & 63;
    stage_v_29_2 = ((stage_v_29_2 + (it_2 * 3)) + (sec_r001408_12_2 & 15)) & 63;
    if ((sec_r001408_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_29_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_29_1) + 7) & 255;
    }
    if ((sec_r001408_12_2 & 1) != 0)
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
    stage_v_30_1 = ((stage_v_30_1 + (it_1 * 3)) + (stage_v_27_1 & 15)) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (it_2 * 3)) + (stage_v_27_2 & 15)) & 63;
    if ((stage_v_27_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_30_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_30_1) + 7) & 255;
    }
    if ((stage_v_27_2 & 1) != 0)
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
    stage_v_31_1 = ((stage_v_31_1 + (it_1 * 3)) + (sec_r001408_13_1 & 15)) & 63;
    stage_v_31_2 = ((stage_v_31_2 + (it_2 * 3)) + (sec_r001408_13_2 & 15)) & 63;
    if ((sec_r001408_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_31_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_31_1) + 7) & 255;
    }
    if ((sec_r001408_13_2 & 1) != 0)
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
    stage_v_32_1 = ((stage_v_32_1 + (it_1 * 3)) + (sec_r001408_16_1 & 15)) & 63;
    stage_v_32_2 = ((stage_v_32_2 + (it_2 * 3)) + (sec_r001408_16_2 & 15)) & 63;
    if ((sec_r001408_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_32_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_32_1) + 7) & 255;
    }
    if ((sec_r001408_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_32_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_32_2) + 7) & 255;
    }
  }

  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_33_1 = ((stage_v_33_1 + (it_1 * 3)) + (sec_r001408_9_1 & 15)) & 63;
    stage_v_33_2 = ((stage_v_33_2 + (it_2 * 3)) + (sec_r001408_9_2 & 15)) & 63;
    if ((sec_r001408_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_33_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_33_1) + 7) & 255;
    }
    if ((sec_r001408_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_33_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_33_2) + 7) & 255;
    }
  }

  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_34_1 = ((stage_v_34_1 + (it_1 * 3)) + (sec_r001408_17_1 & 15)) & 63;
    stage_v_34_2 = ((stage_v_34_2 + (it_2 * 3)) + (sec_r001408_17_2 & 15)) & 63;
    if ((sec_r001408_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_34_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_34_1) + 7) & 255;
    }
    if ((sec_r001408_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_34_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_34_2) + 7) & 255;
    }
  }

  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (it_1 * 3)) + (stage_v_31_1 & 15)) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (it_2 * 3)) + (stage_v_31_2 & 15)) & 63;
    if ((stage_v_31_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_35_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_35_1) + 7) & 255;
    }
    if ((stage_v_31_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_35_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_35_2) + 7) & 255;
    }
  }

  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (it_1 * 3)) + (sec_r001408_5_1 & 15)) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (it_2 * 3)) + (sec_r001408_5_2 & 15)) & 63;
    if ((sec_r001408_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_36_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_36_1) + 7) & 255;
    }
    if ((sec_r001408_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_36_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_36_2) + 7) & 255;
    }
  }

  int stage_v_37_1 = ((pub_r001408_13_1 * 2) + 43) & 63;
  int stage_v_37_2 = ((pub_r001408_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (it_1 * 3)) + (sec_r001408_0_1 & 15)) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (it_2 * 3)) + (sec_r001408_0_2 & 15)) & 63;
    if ((sec_r001408_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_38_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_38_1) + 7) & 255;
    }
    if ((sec_r001408_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_38_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_38_2) + 7) & 255;
    }
  }

  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (it_1 * 3)) + (stage_v_7_1 & 15)) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (it_2 * 3)) + (stage_v_7_2 & 15)) & 63;
    if ((stage_v_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_39_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_39_1) + 7) & 255;
    }
    if ((stage_v_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_39_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_39_2) + 7) & 255;
    }
  }

  int stage_v_40_1 = ((pub_r001408_10_1 * 2) + 28) & 63;
  int stage_v_40_2 = ((pub_r001408_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_41_1 = ((stage_v_41_1 + (it_1 * 3)) + (stage_v_24_1 & 15)) & 63;
    stage_v_41_2 = ((stage_v_41_2 + (it_2 * 3)) + (stage_v_24_2 & 15)) & 63;
    if ((stage_v_24_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_41_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_41_1) + 7) & 255;
    }
    if ((stage_v_24_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_41_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_41_2) + 7) & 255;
    }
  }

  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_42_1 = ((stage_v_42_1 + (it_1 * 3)) + (sec_r001408_9_1 & 15)) & 63;
    stage_v_42_2 = ((stage_v_42_2 + (it_2 * 3)) + (sec_r001408_9_2 & 15)) & 63;
    if ((sec_r001408_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_42_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_42_1) + 7) & 255;
    }
    if ((sec_r001408_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_42_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_42_2) + 7) & 255;
    }
  }

  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (it_1 * 3)) + (sec_r001408_4_1 & 15)) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (it_2 * 3)) + (sec_r001408_4_2 & 15)) & 63;
    if ((sec_r001408_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_43_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_43_1) + 7) & 255;
    }
    if ((sec_r001408_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_43_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_43_2) + 7) & 255;
    }
  }

  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_44_1 = ((stage_v_44_1 + (it_1 * 3)) + (stage_v_41_1 & 15)) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (it_2 * 3)) + (stage_v_41_2 & 15)) & 63;
    if ((stage_v_41_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_44_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_44_1) + 7) & 255;
    }
    if ((stage_v_41_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_44_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_44_2) + 7) & 255;
    }
  }

  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_45_1 = ((stage_v_45_1 + (it_1 * 3)) + (stage_v_41_1 & 15)) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (it_2 * 3)) + (stage_v_41_2 & 15)) & 63;
    if ((stage_v_41_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_45_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_45_1) + 7) & 255;
    }
    if ((stage_v_41_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_45_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_45_2) + 7) & 255;
    }
  }

  int stage_v_46_1 = ((pub_r001408_13_1 * 2) + 33) & 63;
  int stage_v_46_2 = ((pub_r001408_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (it_1 * 3)) + (sec_r001408_15_1 & 15)) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (it_2 * 3)) + (sec_r001408_15_2 & 15)) & 63;
    if ((sec_r001408_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_47_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_47_1) + 7) & 255;
    }
    if ((sec_r001408_15_2 & 1) != 0)
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
    stage_v_48_1 = ((stage_v_48_1 + (it_1 * 3)) + (sec_r001408_16_1 & 15)) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (it_2 * 3)) + (sec_r001408_16_2 & 15)) & 63;
    if ((sec_r001408_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_48_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_48_1) + 7) & 255;
    }
    if ((sec_r001408_16_2 & 1) != 0)
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
    stage_v_49_1 = ((stage_v_49_1 + (it_1 * 3)) + (stage_v_7_1 & 15)) & 63;
    stage_v_49_2 = ((stage_v_49_2 + (it_2 * 3)) + (stage_v_7_2 & 15)) & 63;
    if ((stage_v_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_49_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_49_1) + 7) & 255;
    }
    if ((stage_v_7_2 & 1) != 0)
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
    stage_v_50_1 = ((stage_v_50_1 + (it_1 * 3)) + (sec_r001408_12_1 & 15)) & 63;
    stage_v_50_2 = ((stage_v_50_2 + (it_2 * 3)) + (sec_r001408_12_2 & 15)) & 63;
    if ((sec_r001408_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_50_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_50_1) + 7) & 255;
    }
    if ((sec_r001408_12_2 & 1) != 0)
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
    stage_v_51_1 = ((stage_v_51_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_51_2 = ((stage_v_51_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_51_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_51_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_51_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_51_2) + 7) & 255;
    }
  }

  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_52_1 = ((stage_v_52_1 + (it_1 * 3)) + (stage_v_30_1 & 15)) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (it_2 * 3)) + (stage_v_30_2 & 15)) & 63;
    if ((stage_v_30_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_52_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_52_1) + 7) & 255;
    }
    if ((stage_v_30_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_52_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_52_2) + 7) & 255;
    }
  }

  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (it_1 * 3)) + (sec_r001408_21_1 & 15)) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (it_2 * 3)) + (sec_r001408_21_2 & 15)) & 63;
    if ((sec_r001408_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_53_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_53_1) + 7) & 255;
    }
    if ((sec_r001408_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_53_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_53_2) + 7) & 255;
    }
  }

  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_54_1 = ((stage_v_54_1 + (it_1 * 3)) + (stage_v_53_1 & 15)) & 63;
    stage_v_54_2 = ((stage_v_54_2 + (it_2 * 3)) + (stage_v_53_2 & 15)) & 63;
    if ((stage_v_53_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_54_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_54_1) + 7) & 255;
    }
    if ((stage_v_53_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_54_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_54_2) + 7) & 255;
    }
  }

  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_55_1 = ((stage_v_55_1 + (it_1 * 3)) + (stage_v_51_1 & 15)) & 63;
    stage_v_55_2 = ((stage_v_55_2 + (it_2 * 3)) + (stage_v_51_2 & 15)) & 63;
    if ((stage_v_51_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_55_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_55_1) + 7) & 255;
    }
    if ((stage_v_51_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_55_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_55_2) + 7) & 255;
    }
  }

  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_56_1 = ((stage_v_56_1 + (it_1 * 3)) + (helper_flow_3_1 & 15)) & 63;
    stage_v_56_2 = ((stage_v_56_2 + (it_2 * 3)) + (helper_flow_3_2 & 15)) & 63;
    if ((helper_flow_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_56_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_56_1) + 7) & 255;
    }
    if ((helper_flow_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_56_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_56_2) + 7) & 255;
    }
  }

  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_57_1 = ((stage_v_57_1 + (it_1 * 3)) + (sec_r001408_18_1 & 15)) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (it_2 * 3)) + (sec_r001408_18_2 & 15)) & 63;
    if ((sec_r001408_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_57_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_57_1) + 7) & 255;
    }
    if ((sec_r001408_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_57_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_57_2) + 7) & 255;
    }
  }

  int stage_v_58_1 = ((pub_r001408_11_1 * 2) + 27) & 63;
  int stage_v_58_2 = ((pub_r001408_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001408_3_1 * 2) + 49) & 63;
  int stage_v_59_2 = ((pub_r001408_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_60_1 = ((stage_v_60_1 + (it_1 * 3)) + (stage_v_51_1 & 15)) & 63;
    stage_v_60_2 = ((stage_v_60_2 + (it_2 * 3)) + (stage_v_51_2 & 15)) & 63;
    if ((stage_v_51_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_60_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_60_1) + 7) & 255;
    }
    if ((stage_v_51_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_60_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_60_2) + 7) & 255;
    }
  }

  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_61_1 = ((stage_v_61_1 + (it_1 * 3)) + (stage_v_3_1 & 15)) & 63;
    stage_v_61_2 = ((stage_v_61_2 + (it_2 * 3)) + (stage_v_3_2 & 15)) & 63;
    if ((stage_v_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_61_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_61_1) + 7) & 255;
    }
    if ((stage_v_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_61_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_61_2) + 7) & 255;
    }
  }

  int stage_v_62_1 = ((pub_r001408_16_1 * 2) + 48) & 63;
  int stage_v_62_2 = ((pub_r001408_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_63_1 = ((stage_v_63_1 + (it_1 * 3)) + (stage_v_52_1 & 15)) & 63;
    stage_v_63_2 = ((stage_v_63_2 + (it_2 * 3)) + (stage_v_52_2 & 15)) & 63;
    if ((stage_v_52_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_63_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_63_1) + 7) & 255;
    }
    if ((stage_v_52_2 & 1) != 0)
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
    stage_v_64_1 = ((stage_v_64_1 + (it_1 * 3)) + (stage_v_60_1 & 15)) & 63;
    stage_v_64_2 = ((stage_v_64_2 + (it_2 * 3)) + (stage_v_60_2 & 15)) & 63;
    if ((stage_v_60_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_64_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_64_1) + 7) & 255;
    }
    if ((stage_v_60_2 & 1) != 0)
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
    stage_v_65_1 = ((stage_v_65_1 + (it_1 * 3)) + (sec_r001408_9_1 & 15)) & 63;
    stage_v_65_2 = ((stage_v_65_2 + (it_2 * 3)) + (sec_r001408_9_2 & 15)) & 63;
    if ((sec_r001408_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_65_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_65_1) + 7) & 255;
    }
    if ((sec_r001408_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_65_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_65_2) + 7) & 255;
    }
  }

  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_66_1 = ((stage_v_66_1 + (it_1 * 3)) + (helper_flow_4_1 & 15)) & 63;
    stage_v_66_2 = ((stage_v_66_2 + (it_2 * 3)) + (helper_flow_4_2 & 15)) & 63;
    if ((helper_flow_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_66_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_66_1) + 7) & 255;
    }
    if ((helper_flow_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_66_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_66_2) + 7) & 255;
    }
  }

  int stage_v_67_1 = ((pub_r001408_1_1 * 2) + 40) & 63;
  int stage_v_67_2 = ((pub_r001408_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001408_9_1 * 2) + 26) & 63;
  int stage_v_68_2 = ((pub_r001408_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_69_1 = ((stage_v_69_1 + (it_1 * 3)) + (stage_v_21_1 & 15)) & 63;
    stage_v_69_2 = ((stage_v_69_2 + (it_2 * 3)) + (stage_v_21_2 & 15)) & 63;
    if ((stage_v_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_69_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_69_1) + 7) & 255;
    }
    if ((stage_v_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_69_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_69_2) + 7) & 255;
    }
  }

  int stage_v_70_1 = ((pub_r001408_0_1 * 2) + 10) & 63;
  int stage_v_70_2 = ((pub_r001408_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_71_1 = ((stage_v_71_1 + (it_1 * 3)) + (sec_r001408_1_1 & 15)) & 63;
    stage_v_71_2 = ((stage_v_71_2 + (it_2 * 3)) + (sec_r001408_1_2 & 15)) & 63;
    if ((sec_r001408_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_71_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_71_1) + 7) & 255;
    }
    if ((sec_r001408_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_71_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_71_2) + 7) & 255;
    }
  }

  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_72_1 = ((stage_v_72_1 + (it_1 * 3)) + (sec_r001408_14_1 & 15)) & 63;
    stage_v_72_2 = ((stage_v_72_2 + (it_2 * 3)) + (sec_r001408_14_2 & 15)) & 63;
    if ((sec_r001408_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_72_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_72_1) + 7) & 255;
    }
    if ((sec_r001408_14_2 & 1) != 0)
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
    stage_v_73_1 = ((stage_v_73_1 + (it_1 * 3)) + (sec_r001408_5_1 & 15)) & 63;
    stage_v_73_2 = ((stage_v_73_2 + (it_2 * 3)) + (sec_r001408_5_2 & 15)) & 63;
    if ((sec_r001408_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_73_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_73_1) + 7) & 255;
    }
    if ((sec_r001408_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_73_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_73_2) + 7) & 255;
    }
  }

  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_74_1 = ((stage_v_74_1 + (it_1 * 3)) + (sec_r001408_12_1 & 15)) & 63;
    stage_v_74_2 = ((stage_v_74_2 + (it_2 * 3)) + (sec_r001408_12_2 & 15)) & 63;
    if ((sec_r001408_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_74_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_74_1) + 7) & 255;
    }
    if ((sec_r001408_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_74_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_74_2) + 7) & 255;
    }
  }

  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_75_1 = ((stage_v_75_1 + (it_1 * 3)) + (stage_v_50_1 & 15)) & 63;
    stage_v_75_2 = ((stage_v_75_2 + (it_2 * 3)) + (stage_v_50_2 & 15)) & 63;
    if ((stage_v_50_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_75_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_75_1) + 7) & 255;
    }
    if ((stage_v_50_2 & 1) != 0)
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
    stage_v_76_1 = ((stage_v_76_1 + (it_1 * 3)) + (stage_v_61_1 & 15)) & 63;
    stage_v_76_2 = ((stage_v_76_2 + (it_2 * 3)) + (stage_v_61_2 & 15)) & 63;
    if ((stage_v_61_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_76_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_76_1) + 7) & 255;
    }
    if ((stage_v_61_2 & 1) != 0)
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
    stage_v_77_1 = ((stage_v_77_1 + (it_1 * 3)) + (sec_r001408_10_1 & 15)) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (it_2 * 3)) + (sec_r001408_10_2 & 15)) & 63;
    if ((sec_r001408_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_77_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_77_1) + 7) & 255;
    }
    if ((sec_r001408_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_77_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_77_2) + 7) & 255;
    }
  }

  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_78_1 = ((stage_v_78_1 + (it_1 * 3)) + (sec_r001408_2_1 & 15)) & 63;
    stage_v_78_2 = ((stage_v_78_2 + (it_2 * 3)) + (sec_r001408_2_2 & 15)) & 63;
    if ((sec_r001408_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_78_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_78_1) + 7) & 255;
    }
    if ((sec_r001408_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_78_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_78_2) + 7) & 255;
    }
  }

  int stage_v_79_1 = ((pub_r001408_2_1 * 2) + 25) & 63;
  int stage_v_79_2 = ((pub_r001408_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001408_4_1 * 2) + 23) & 63;
  int stage_v_80_2 = ((pub_r001408_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001408_4_1 * 2) + 29) & 63;
  int stage_v_81_2 = ((pub_r001408_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_82_1 = ((stage_v_82_1 + (it_1 * 3)) + (stage_v_53_1 & 15)) & 63;
    stage_v_82_2 = ((stage_v_82_2 + (it_2 * 3)) + (stage_v_53_2 & 15)) & 63;
    if ((stage_v_53_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_82_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_82_1) + 7) & 255;
    }
    if ((stage_v_53_2 & 1) != 0)
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
    stage_v_83_1 = ((stage_v_83_1 + (it_1 * 3)) + (stage_v_82_1 & 15)) & 63;
    stage_v_83_2 = ((stage_v_83_2 + (it_2 * 3)) + (stage_v_82_2 & 15)) & 63;
    if ((stage_v_82_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_83_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_83_1) + 7) & 255;
    }
    if ((stage_v_82_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_83_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_83_2) + 7) & 255;
    }
  }

  int stage_v_84_1 = ((pub_r001408_12_1 * 2) + 21) & 63;
  int stage_v_84_2 = ((pub_r001408_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001408_3_1 * 2) + 23) & 63;
  int stage_v_85_2 = ((pub_r001408_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001408_1_1 * 2) + 27) & 63;
  int stage_v_86_2 = ((pub_r001408_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_87_1 = ((stage_v_87_1 + (it_1 * 3)) + (stage_v_24_1 & 15)) & 63;
    stage_v_87_2 = ((stage_v_87_2 + (it_2 * 3)) + (stage_v_24_2 & 15)) & 63;
    if ((stage_v_24_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_87_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_87_1) + 7) & 255;
    }
    if ((stage_v_24_2 & 1) != 0)
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
    stage_v_88_1 = ((stage_v_88_1 + (it_1 * 3)) + (sec_r001408_7_1 & 15)) & 63;
    stage_v_88_2 = ((stage_v_88_2 + (it_2 * 3)) + (sec_r001408_7_2 & 15)) & 63;
    if ((sec_r001408_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_88_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_88_1) + 7) & 255;
    }
    if ((sec_r001408_7_2 & 1) != 0)
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
    stage_v_89_1 = ((stage_v_89_1 + (it_1 * 3)) + (stage_v_51_1 & 15)) & 63;
    stage_v_89_2 = ((stage_v_89_2 + (it_2 * 3)) + (stage_v_51_2 & 15)) & 63;
    if ((stage_v_51_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_89_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_89_1) + 7) & 255;
    }
    if ((stage_v_51_2 & 1) != 0)
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
    stage_v_90_1 = ((stage_v_90_1 + (it_1 * 3)) + (sec_r001408_1_1 & 15)) & 63;
    stage_v_90_2 = ((stage_v_90_2 + (it_2 * 3)) + (sec_r001408_1_2 & 15)) & 63;
    if ((sec_r001408_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_90_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_90_1) + 7) & 255;
    }
    if ((sec_r001408_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_90_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_90_2) + 7) & 255;
    }
  }

  int stage_v_91_1 = ((pub_r001408_17_1 * 2) + 6) & 63;
  int stage_v_91_2 = ((pub_r001408_17_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_92_1 = ((stage_v_92_1 + (it_1 * 3)) + (stage_v_34_1 & 15)) & 63;
    stage_v_92_2 = ((stage_v_92_2 + (it_2 * 3)) + (stage_v_34_2 & 15)) & 63;
    if ((stage_v_34_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_92_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_92_1) + 7) & 255;
    }
    if ((stage_v_34_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_92_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_92_2) + 7) & 255;
    }
  }

  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_93_1 = ((stage_v_93_1 + (it_1 * 3)) + (helper_flow_2_1 & 15)) & 63;
    stage_v_93_2 = ((stage_v_93_2 + (it_2 * 3)) + (helper_flow_2_2 & 15)) & 63;
    if ((helper_flow_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_93_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_93_1) + 7) & 255;
    }
    if ((helper_flow_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_93_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_93_2) + 7) & 255;
    }
  }

  int stage_v_94_1 = ((pub_r001408_16_1 * 2) + 11) & 63;
  int stage_v_94_2 = ((pub_r001408_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_95_1 = ((stage_v_95_1 + (it_1 * 3)) + (stage_v_78_1 & 15)) & 63;
    stage_v_95_2 = ((stage_v_95_2 + (it_2 * 3)) + (stage_v_78_2 & 15)) & 63;
    if ((stage_v_78_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_95_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_95_1) + 7) & 255;
    }
    if ((stage_v_78_2 & 1) != 0)
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
    stage_v_96_1 = ((stage_v_96_1 + (it_1 * 3)) + (stage_v_11_1 & 15)) & 63;
    stage_v_96_2 = ((stage_v_96_2 + (it_2 * 3)) + (stage_v_11_2 & 15)) & 63;
    if ((stage_v_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_96_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_96_1) + 7) & 255;
    }
    if ((stage_v_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_96_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_96_2) + 7) & 255;
    }
  }

  int stage_v_97_1 = ((pub_r001408_6_1 * 2) + 45) & 63;
  int stage_v_97_2 = ((pub_r001408_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_98_1 = ((stage_v_98_1 + (it_1 * 3)) + (stage_v_9_1 & 15)) & 63;
    stage_v_98_2 = ((stage_v_98_2 + (it_2 * 3)) + (stage_v_9_2 & 15)) & 63;
    if ((stage_v_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_98_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_98_1) + 7) & 255;
    }
    if ((stage_v_9_2 & 1) != 0)
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
    stage_v_99_1 = ((stage_v_99_1 + (it_1 * 3)) + (stage_v_96_1 & 15)) & 63;
    stage_v_99_2 = ((stage_v_99_2 + (it_2 * 3)) + (stage_v_96_2 & 15)) & 63;
    if ((stage_v_96_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_99_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_99_1) + 7) & 255;
    }
    if ((stage_v_96_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_99_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_99_2) + 7) & 255;
    }
  }

  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_100_1 = ((stage_v_100_1 + (it_1 * 3)) + (stage_v_53_1 & 15)) & 63;
    stage_v_100_2 = ((stage_v_100_2 + (it_2 * 3)) + (stage_v_53_2 & 15)) & 63;
    if ((stage_v_53_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_100_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_100_1) + 7) & 255;
    }
    if ((stage_v_53_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_100_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_100_2) + 7) & 255;
    }
  }

  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_101_1 = ((stage_v_101_1 + (it_1 * 3)) + (stage_v_75_1 & 15)) & 63;
    stage_v_101_2 = ((stage_v_101_2 + (it_2 * 3)) + (stage_v_75_2 & 15)) & 63;
    if ((stage_v_75_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_101_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_101_1) + 7) & 255;
    }
    if ((stage_v_75_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_101_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_101_2) + 7) & 255;
    }
  }

  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_102_1 = ((stage_v_102_1 + (it_1 * 3)) + (stage_v_28_1 & 15)) & 63;
    stage_v_102_2 = ((stage_v_102_2 + (it_2 * 3)) + (stage_v_28_2 & 15)) & 63;
    if ((stage_v_28_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_102_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_102_1) + 7) & 255;
    }
    if ((stage_v_28_2 & 1) != 0)
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
    stage_v_103_1 = ((stage_v_103_1 + (it_1 * 3)) + (stage_v_56_1 & 15)) & 63;
    stage_v_103_2 = ((stage_v_103_2 + (it_2 * 3)) + (stage_v_56_2 & 15)) & 63;
    if ((stage_v_56_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_103_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_103_1) + 7) & 255;
    }
    if ((stage_v_56_2 & 1) != 0)
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
    stage_v_104_1 = ((stage_v_104_1 + (it_1 * 3)) + (sec_r001408_18_1 & 15)) & 63;
    stage_v_104_2 = ((stage_v_104_2 + (it_2 * 3)) + (sec_r001408_18_2 & 15)) & 63;
    if ((sec_r001408_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_104_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_104_1) + 7) & 255;
    }
    if ((sec_r001408_18_2 & 1) != 0)
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
    stage_v_105_1 = ((stage_v_105_1 + (it_1 * 3)) + (stage_v_98_1 & 15)) & 63;
    stage_v_105_2 = ((stage_v_105_2 + (it_2 * 3)) + (stage_v_98_2 & 15)) & 63;
    if ((stage_v_98_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_105_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_105_1) + 7) & 255;
    }
    if ((stage_v_98_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_105_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_105_2) + 7) & 255;
    }
  }

  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_106_1 = ((stage_v_106_1 + (it_1 * 3)) + (stage_v_82_1 & 15)) & 63;
    stage_v_106_2 = ((stage_v_106_2 + (it_2 * 3)) + (stage_v_82_2 & 15)) & 63;
    if ((stage_v_82_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_106_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_106_1) + 7) & 255;
    }
    if ((stage_v_82_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_106_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_106_2) + 7) & 255;
    }
  }

  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_107_1 = ((stage_v_107_1 + (it_1 * 3)) + (stage_v_30_1 & 15)) & 63;
    stage_v_107_2 = ((stage_v_107_2 + (it_2 * 3)) + (stage_v_30_2 & 15)) & 63;
    if ((stage_v_30_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_107_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_107_1) + 7) & 255;
    }
    if ((stage_v_30_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_107_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_107_2) + 7) & 255;
    }
  }

  int stage_v_108_1 = ((pub_r001408_15_1 * 2) + 43) & 63;
  int stage_v_108_2 = ((pub_r001408_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_109_1 = ((stage_v_109_1 + (it_1 * 3)) + (stage_v_69_1 & 15)) & 63;
    stage_v_109_2 = ((stage_v_109_2 + (it_2 * 3)) + (stage_v_69_2 & 15)) & 63;
    if ((stage_v_69_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_109_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_109_1) + 7) & 255;
    }
    if ((stage_v_69_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_109_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_109_2) + 7) & 255;
    }
  }

  int stage_v_110_1 = ((pub_r001408_14_1 * 2) + 23) & 63;
  int stage_v_110_2 = ((pub_r001408_14_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_111_1 = ((stage_v_111_1 + (it_1 * 3)) + (stage_v_48_1 & 15)) & 63;
    stage_v_111_2 = ((stage_v_111_2 + (it_2 * 3)) + (stage_v_48_2 & 15)) & 63;
    if ((stage_v_48_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_111_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_111_1) + 7) & 255;
    }
    if ((stage_v_48_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_111_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_111_2) + 7) & 255;
    }
  }

  int stage_v_112_1 = ((pub_r001408_13_1 * 2) + 15) & 63;
  int stage_v_112_2 = ((pub_r001408_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_113_1 = ((stage_v_113_1 + (it_1 * 3)) + (sec_r001408_21_1 & 15)) & 63;
    stage_v_113_2 = ((stage_v_113_2 + (it_2 * 3)) + (sec_r001408_21_2 & 15)) & 63;
    if ((sec_r001408_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_113_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_113_1) + 7) & 255;
    }
    if ((sec_r001408_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_113_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_113_2) + 7) & 255;
    }
  }

  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_114_1 = ((stage_v_114_1 + (it_1 * 3)) + (stage_v_0_1 & 15)) & 63;
    stage_v_114_2 = ((stage_v_114_2 + (it_2 * 3)) + (stage_v_0_2 & 15)) & 63;
    if ((stage_v_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_114_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_114_1) + 7) & 255;
    }
    if ((stage_v_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_114_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_114_2) + 7) & 255;
    }
  }

  int stage_v_115_1 = ((pub_r001408_6_1 * 2) + 41) & 63;
  int stage_v_115_2 = ((pub_r001408_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_116_1 = ((stage_v_116_1 + (it_1 * 3)) + (sec_r001408_14_1 & 15)) & 63;
    stage_v_116_2 = ((stage_v_116_2 + (it_2 * 3)) + (sec_r001408_14_2 & 15)) & 63;
    if ((sec_r001408_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_116_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_116_1) + 7) & 255;
    }
    if ((sec_r001408_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_116_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_116_2) + 7) & 255;
    }
  }

  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_117_1 = ((stage_v_117_1 + (it_1 * 3)) + (sec_r001408_3_1 & 15)) & 63;
    stage_v_117_2 = ((stage_v_117_2 + (it_2 * 3)) + (sec_r001408_3_2 & 15)) & 63;
    if ((sec_r001408_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_117_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_117_1) + 7) & 255;
    }
    if ((sec_r001408_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_117_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_117_2) + 7) & 255;
    }
  }

  int stage_v_118_1 = ((pub_r001408_6_1 * 2) + 44) & 63;
  int stage_v_118_2 = ((pub_r001408_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_119_1 = ((stage_v_119_1 + (it_1 * 3)) + (sec_r001408_8_1 & 15)) & 63;
    stage_v_119_2 = ((stage_v_119_2 + (it_2 * 3)) + (sec_r001408_8_2 & 15)) & 63;
    if ((sec_r001408_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_119_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_119_1) + 7) & 255;
    }
    if ((sec_r001408_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_119_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_119_2) + 7) & 255;
    }
  }

  int stage_v_120_1 = ((pub_r001408_0_1 * 2) + 9) & 63;
  int stage_v_120_2 = ((pub_r001408_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_121_1 = ((stage_v_121_1 + (it_1 * 3)) + (sec_r001408_21_1 & 15)) & 63;
    stage_v_121_2 = ((stage_v_121_2 + (it_2 * 3)) + (sec_r001408_21_2 & 15)) & 63;
    if ((sec_r001408_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_121_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_121_1) + 7) & 255;
    }
    if ((sec_r001408_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_121_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_121_2) + 7) & 255;
    }
  }

  int stage_v_122_1 = ((pub_r001408_16_1 * 2) + 42) & 63;
  int stage_v_122_2 = ((pub_r001408_16_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_123_1 = ((stage_v_123_1 + (it_1 * 3)) + (stage_v_11_1 & 15)) & 63;
    stage_v_123_2 = ((stage_v_123_2 + (it_2 * 3)) + (stage_v_11_2 & 15)) & 63;
    if ((stage_v_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_123_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_123_1) + 7) & 255;
    }
    if ((stage_v_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_123_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_123_2) + 7) & 255;
    }
  }

  int stage_v_124_1 = ((pub_r001408_14_1 * 2) + 25) & 63;
  int stage_v_124_2 = ((pub_r001408_14_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_125_1 = ((stage_v_125_1 + (it_1 * 3)) + (stage_v_105_1 & 15)) & 63;
    stage_v_125_2 = ((stage_v_125_2 + (it_2 * 3)) + (stage_v_105_2 & 15)) & 63;
    if ((stage_v_105_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_125_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_125_1) + 7) & 255;
    }
    if ((stage_v_105_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_125_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_125_2) + 7) & 255;
    }
  }

  int stage_v_126_1 = ((pub_r001408_14_1 * 2) + 18) & 63;
  int stage_v_126_2 = ((pub_r001408_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_127_1 = ((stage_v_127_1 + (it_1 * 3)) + (stage_v_116_1 & 15)) & 63;
    stage_v_127_2 = ((stage_v_127_2 + (it_2 * 3)) + (stage_v_116_2 & 15)) & 63;
    if ((stage_v_116_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_127_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_127_1) + 7) & 255;
    }
    if ((stage_v_116_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_127_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_127_2) + 7) & 255;
    }
  }

  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_128_1 = ((stage_v_128_1 + (it_1 * 3)) + (sec_r001408_2_1 & 15)) & 63;
    stage_v_128_2 = ((stage_v_128_2 + (it_2 * 3)) + (sec_r001408_2_2 & 15)) & 63;
    if ((sec_r001408_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_128_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_128_1) + 7) & 255;
    }
    if ((sec_r001408_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_128_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_128_2) + 7) & 255;
    }
  }

  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_129_1 = ((stage_v_129_1 + (it_1 * 3)) + (stage_v_30_1 & 15)) & 63;
    stage_v_129_2 = ((stage_v_129_2 + (it_2 * 3)) + (stage_v_30_2 & 15)) & 63;
    if ((stage_v_30_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_129_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_129_1) + 7) & 255;
    }
    if ((stage_v_30_2 & 1) != 0)
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

  int stage_v_131_1 = ((pub_r001408_3_1 * 2) + 18) & 63;
  int stage_v_131_2 = ((pub_r001408_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001408_0_1 * 2) + 25) & 63;
  int stage_v_132_2 = ((pub_r001408_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_133_1 = ((stage_v_133_1 + (it_1 * 3)) + (sec_r001408_7_1 & 15)) & 63;
    stage_v_133_2 = ((stage_v_133_2 + (it_2 * 3)) + (sec_r001408_7_2 & 15)) & 63;
    if ((sec_r001408_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_133_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_133_1) + 7) & 255;
    }
    if ((sec_r001408_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_133_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_133_2) + 7) & 255;
    }
  }

  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_134_1 = ((stage_v_134_1 + (it_1 * 3)) + (stage_v_114_1 & 15)) & 63;
    stage_v_134_2 = ((stage_v_134_2 + (it_2 * 3)) + (stage_v_114_2 & 15)) & 63;
    if ((stage_v_114_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_134_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_134_1) + 7) & 255;
    }
    if ((stage_v_114_2 & 1) != 0)
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
    stage_v_135_1 = ((stage_v_135_1 + (it_1 * 3)) + (stage_v_123_1 & 15)) & 63;
    stage_v_135_2 = ((stage_v_135_2 + (it_2 * 3)) + (stage_v_123_2 & 15)) & 63;
    if ((stage_v_123_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_135_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_135_1) + 7) & 255;
    }
    if ((stage_v_123_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_135_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_135_2) + 7) & 255;
    }
  }

  int stage_v_136_1 = ((pub_r001408_4_1 * 2) + 30) & 63;
  int stage_v_136_2 = ((pub_r001408_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_137_1 = ((stage_v_137_1 + (it_1 * 3)) + (sec_r001408_6_1 & 15)) & 63;
    stage_v_137_2 = ((stage_v_137_2 + (it_2 * 3)) + (sec_r001408_6_2 & 15)) & 63;
    if ((sec_r001408_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_137_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_137_1) + 7) & 255;
    }
    if ((sec_r001408_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_137_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_137_2) + 7) & 255;
    }
  }

  int stage_v_138_1 = ((pub_r001408_11_1 * 2) + 50) & 63;
  int stage_v_138_2 = ((pub_r001408_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001408_11_1 * 2) + 12) & 63;
  int stage_v_139_2 = ((pub_r001408_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_140_1 = ((stage_v_140_1 + (it_1 * 3)) + (stage_v_49_1 & 15)) & 63;
    stage_v_140_2 = ((stage_v_140_2 + (it_2 * 3)) + (stage_v_49_2 & 15)) & 63;
    if ((stage_v_49_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_140_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_140_1) + 7) & 255;
    }
    if ((stage_v_49_2 & 1) != 0)
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
    stage_v_141_1 = ((stage_v_141_1 + (it_1 * 3)) + (stage_v_36_1 & 15)) & 63;
    stage_v_141_2 = ((stage_v_141_2 + (it_2 * 3)) + (stage_v_36_2 & 15)) & 63;
    if ((stage_v_36_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_141_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_141_1) + 7) & 255;
    }
    if ((stage_v_36_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_141_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_141_2) + 7) & 255;
    }
  }

  int stage_v_142_1 = ((pub_r001408_6_1 * 2) + 30) & 63;
  int stage_v_142_2 = ((pub_r001408_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_143_1 = ((stage_v_143_1 + (it_1 * 3)) + (stage_v_33_1 & 15)) & 63;
    stage_v_143_2 = ((stage_v_143_2 + (it_2 * 3)) + (stage_v_33_2 & 15)) & 63;
    if ((stage_v_33_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_143_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_143_1) + 7) & 255;
    }
    if ((stage_v_33_2 & 1) != 0)
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
    stage_v_144_1 = ((stage_v_144_1 + (it_1 * 3)) + (stage_v_71_1 & 15)) & 63;
    stage_v_144_2 = ((stage_v_144_2 + (it_2 * 3)) + (stage_v_71_2 & 15)) & 63;
    if ((stage_v_71_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_144_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_144_1) + 7) & 255;
    }
    if ((stage_v_71_2 & 1) != 0)
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
    stage_v_145_1 = ((stage_v_145_1 + (it_1 * 3)) + (stage_v_119_1 & 15)) & 63;
    stage_v_145_2 = ((stage_v_145_2 + (it_2 * 3)) + (stage_v_119_2 & 15)) & 63;
    if ((stage_v_119_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_145_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_145_1) + 7) & 255;
    }
    if ((stage_v_119_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_145_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_145_2) + 7) & 255;
    }
  }

  int stage_v_146_1 = ((pub_r001408_9_1 * 2) + 11) & 63;
  int stage_v_146_2 = ((pub_r001408_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_147_1 = ((stage_v_147_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_147_2 = ((stage_v_147_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_147_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_147_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_147_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_147_2) + 7) & 255;
    }
  }

  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_148_1 = ((stage_v_148_1 + (it_1 * 3)) + (stage_v_21_1 & 15)) & 63;
    stage_v_148_2 = ((stage_v_148_2 + (it_2 * 3)) + (stage_v_21_2 & 15)) & 63;
    if ((stage_v_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_148_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_148_1) + 7) & 255;
    }
    if ((stage_v_21_2 & 1) != 0)
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
    stage_v_149_1 = ((stage_v_149_1 + (it_1 * 3)) + (stage_v_145_1 & 15)) & 63;
    stage_v_149_2 = ((stage_v_149_2 + (it_2 * 3)) + (stage_v_145_2 & 15)) & 63;
    if ((stage_v_145_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_149_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_149_1) + 7) & 255;
    }
    if ((stage_v_145_2 & 1) != 0)
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
    stage_v_150_1 = ((stage_v_150_1 + (it_1 * 3)) + (stage_v_36_1 & 15)) & 63;
    stage_v_150_2 = ((stage_v_150_2 + (it_2 * 3)) + (stage_v_36_2 & 15)) & 63;
    if ((stage_v_36_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_150_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_150_1) + 7) & 255;
    }
    if ((stage_v_36_2 & 1) != 0)
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
    stage_v_151_1 = ((stage_v_151_1 + (it_1 * 3)) + (stage_v_47_1 & 15)) & 63;
    stage_v_151_2 = ((stage_v_151_2 + (it_2 * 3)) + (stage_v_47_2 & 15)) & 63;
    if ((stage_v_47_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_151_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_151_1) + 7) & 255;
    }
    if ((stage_v_47_2 & 1) != 0)
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
    stage_v_152_1 = ((stage_v_152_1 + (it_1 * 3)) + (stage_v_137_1 & 15)) & 63;
    stage_v_152_2 = ((stage_v_152_2 + (it_2 * 3)) + (stage_v_137_2 & 15)) & 63;
    if ((stage_v_137_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_152_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_152_1) + 7) & 255;
    }
    if ((stage_v_137_2 & 1) != 0)
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
    stage_v_153_1 = ((stage_v_153_1 + (it_1 * 3)) + (sec_r001408_15_1 & 15)) & 63;
    stage_v_153_2 = ((stage_v_153_2 + (it_2 * 3)) + (sec_r001408_15_2 & 15)) & 63;
    if ((sec_r001408_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_153_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_153_1) + 7) & 255;
    }
    if ((sec_r001408_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_153_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_153_2) + 7) & 255;
    }
  }

  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_154_1 = ((stage_v_154_1 + (it_1 * 3)) + (stage_v_82_1 & 15)) & 63;
    stage_v_154_2 = ((stage_v_154_2 + (it_2 * 3)) + (stage_v_82_2 & 15)) & 63;
    if ((stage_v_82_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_154_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_154_1) + 7) & 255;
    }
    if ((stage_v_82_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_154_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_154_2) + 7) & 255;
    }
  }

  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_155_1 = ((stage_v_155_1 + (it_1 * 3)) + (stage_v_129_1 & 15)) & 63;
    stage_v_155_2 = ((stage_v_155_2 + (it_2 * 3)) + (stage_v_129_2 & 15)) & 63;
    if ((stage_v_129_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_155_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_155_1) + 7) & 255;
    }
    if ((stage_v_129_2 & 1) != 0)
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
    stage_v_156_1 = ((stage_v_156_1 + (it_1 * 3)) + (sec_r001408_11_1 & 15)) & 63;
    stage_v_156_2 = ((stage_v_156_2 + (it_2 * 3)) + (sec_r001408_11_2 & 15)) & 63;
    if ((sec_r001408_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_156_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_156_1) + 7) & 255;
    }
    if ((sec_r001408_11_2 & 1) != 0)
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
    stage_v_157_1 = ((stage_v_157_1 + (it_1 * 3)) + (sec_r001408_16_1 & 15)) & 63;
    stage_v_157_2 = ((stage_v_157_2 + (it_2 * 3)) + (sec_r001408_16_2 & 15)) & 63;
    if ((sec_r001408_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_157_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_157_1) + 7) & 255;
    }
    if ((sec_r001408_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_157_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_157_2) + 7) & 255;
    }
  }

  int stage_v_158_1 = ((pub_r001408_8_1 * 2) + 40) & 63;
  int stage_v_158_2 = ((pub_r001408_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001408_7_1 * 2) + 50) & 63;
  int stage_v_159_2 = ((pub_r001408_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_160_1 = ((stage_v_160_1 + (it_1 * 3)) + (stage_v_143_1 & 15)) & 63;
    stage_v_160_2 = ((stage_v_160_2 + (it_2 * 3)) + (stage_v_143_2 & 15)) & 63;
    if ((stage_v_143_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_160_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_160_1) + 7) & 255;
    }
    if ((stage_v_143_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_160_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_160_2) + 7) & 255;
    }
  }

  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_161_1 = ((stage_v_161_1 + (it_1 * 3)) + (stage_v_27_1 & 15)) & 63;
    stage_v_161_2 = ((stage_v_161_2 + (it_2 * 3)) + (stage_v_27_2 & 15)) & 63;
    if ((stage_v_27_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_161_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_161_1) + 7) & 255;
    }
    if ((stage_v_27_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_161_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_161_2) + 7) & 255;
    }
  }

  int stage_v_162_1 = ((pub_r001408_8_1 * 2) + 7) & 63;
  int stage_v_162_2 = ((pub_r001408_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_163_1 = ((stage_v_163_1 + (it_1 * 3)) + (stage_v_106_1 & 15)) & 63;
    stage_v_163_2 = ((stage_v_163_2 + (it_2 * 3)) + (stage_v_106_2 & 15)) & 63;
    if ((stage_v_106_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_163_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_163_1) + 7) & 255;
    }
    if ((stage_v_106_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_163_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_163_2) + 7) & 255;
    }
  }

  int stage_v_164_1 = ((pub_r001408_16_1 * 2) + 15) & 63;
  int stage_v_164_2 = ((pub_r001408_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_165_1 = ((stage_v_165_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_165_2 = ((stage_v_165_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_165_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_165_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_165_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_165_2) + 7) & 255;
    }
  }

  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_166_1 = ((stage_v_166_1 + (it_1 * 3)) + (helper_flow_8_1 & 15)) & 63;
    stage_v_166_2 = ((stage_v_166_2 + (it_2 * 3)) + (helper_flow_8_2 & 15)) & 63;
    if ((helper_flow_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_166_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_166_1) + 7) & 255;
    }
    if ((helper_flow_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_166_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_166_2) + 7) & 255;
    }
  }

  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_167_1 = ((stage_v_167_1 + (it_1 * 3)) + (stage_v_165_1 & 15)) & 63;
    stage_v_167_2 = ((stage_v_167_2 + (it_2 * 3)) + (stage_v_165_2 & 15)) & 63;
    if ((stage_v_165_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_167_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_167_1) + 7) & 255;
    }
    if ((stage_v_165_2 & 1) != 0)
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
    stage_v_168_1 = ((stage_v_168_1 + (it_1 * 3)) + (stage_v_135_1 & 15)) & 63;
    stage_v_168_2 = ((stage_v_168_2 + (it_2 * 3)) + (stage_v_135_2 & 15)) & 63;
    if ((stage_v_135_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_168_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_168_1) + 7) & 255;
    }
    if ((stage_v_135_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_168_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_168_2) + 7) & 255;
    }
  }

  int stage_v_169_1 = 0;
  int stage_v_169_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_169_1 = ((stage_v_169_1 + (it_1 * 3)) + (helper_flow_1_1 & 15)) & 63;
    stage_v_169_2 = ((stage_v_169_2 + (it_2 * 3)) + (helper_flow_1_2 & 15)) & 63;
    if ((helper_flow_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_169_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_169_1) + 7) & 255;
    }
    if ((helper_flow_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_169_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_169_2) + 7) & 255;
    }
  }

  int stage_v_170_1 = ((pub_r001408_2_1 * 2) + 9) & 63;
  int stage_v_170_2 = ((pub_r001408_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001408_7_1 * 2) + 15) & 63;
  int stage_v_171_2 = ((pub_r001408_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = 0;
  int stage_v_172_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_172_1 = ((stage_v_172_1 + (it_1 * 3)) + (stage_v_167_1 & 15)) & 63;
    stage_v_172_2 = ((stage_v_172_2 + (it_2 * 3)) + (stage_v_167_2 & 15)) & 63;
    if ((stage_v_167_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_172_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_172_1) + 7) & 255;
    }
    if ((stage_v_167_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_172_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_172_2) + 7) & 255;
    }
  }

  int stage_v_173_1 = 0;
  int stage_v_173_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_173_1 = ((stage_v_173_1 + (it_1 * 3)) + (stage_v_3_1 & 15)) & 63;
    stage_v_173_2 = ((stage_v_173_2 + (it_2 * 3)) + (stage_v_3_2 & 15)) & 63;
    if ((stage_v_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_173_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_173_1) + 7) & 255;
    }
    if ((stage_v_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_173_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_173_2) + 7) & 255;
    }
  }

  int stage_v_174_1 = 0;
  int stage_v_174_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_174_1 = ((stage_v_174_1 + (it_1 * 3)) + (stage_v_121_1 & 15)) & 63;
    stage_v_174_2 = ((stage_v_174_2 + (it_2 * 3)) + (stage_v_121_2 & 15)) & 63;
    if ((stage_v_121_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_174_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_174_1) + 7) & 255;
    }
    if ((stage_v_121_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_174_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_174_2) + 7) & 255;
    }
  }

  int stage_v_175_1 = 0;
  int stage_v_175_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_175_1 = ((stage_v_175_1 + (it_1 * 3)) + (stage_v_137_1 & 15)) & 63;
    stage_v_175_2 = ((stage_v_175_2 + (it_2 * 3)) + (stage_v_137_2 & 15)) & 63;
    if ((stage_v_137_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_175_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_175_1) + 7) & 255;
    }
    if ((stage_v_137_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_175_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_175_2) + 7) & 255;
    }
  }

  int stage_v_176_1 = 0;
  int stage_v_176_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_176_1 = ((stage_v_176_1 + (it_1 * 3)) + (helper_flow_7_1 & 15)) & 63;
    stage_v_176_2 = ((stage_v_176_2 + (it_2 * 3)) + (helper_flow_7_2 & 15)) & 63;
    if ((helper_flow_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_176_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_176_1) + 7) & 255;
    }
    if ((helper_flow_7_2 & 1) != 0)
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
    stage_v_177_1 = ((stage_v_177_1 + (it_1 * 3)) + (stage_v_83_1 & 15)) & 63;
    stage_v_177_2 = ((stage_v_177_2 + (it_2 * 3)) + (stage_v_83_2 & 15)) & 63;
    if ((stage_v_83_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_177_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_177_1) + 7) & 255;
    }
    if ((stage_v_83_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_177_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_177_2) + 7) & 255;
    }
  }

  int stage_v_178_1 = ((pub_r001408_8_1 * 2) + 16) & 63;
  int stage_v_178_2 = ((pub_r001408_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = 0;
  int stage_v_179_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_179_1 = ((stage_v_179_1 + (it_1 * 3)) + (stage_v_48_1 & 15)) & 63;
    stage_v_179_2 = ((stage_v_179_2 + (it_2 * 3)) + (stage_v_48_2 & 15)) & 63;
    if ((stage_v_48_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_179_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_179_1) + 7) & 255;
    }
    if ((stage_v_48_2 & 1) != 0)
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
    stage_v_180_1 = ((stage_v_180_1 + (it_1 * 3)) + (stage_v_92_1 & 15)) & 63;
    stage_v_180_2 = ((stage_v_180_2 + (it_2 * 3)) + (stage_v_92_2 & 15)) & 63;
    if ((stage_v_92_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_180_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_180_1) + 7) & 255;
    }
    if ((stage_v_92_2 & 1) != 0)
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
    stage_v_181_1 = ((stage_v_181_1 + (it_1 * 3)) + (stage_v_107_1 & 15)) & 63;
    stage_v_181_2 = ((stage_v_181_2 + (it_2 * 3)) + (stage_v_107_2 & 15)) & 63;
    if ((stage_v_107_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_181_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_181_1) + 7) & 255;
    }
    if ((stage_v_107_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_181_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_181_2) + 7) & 255;
    }
  }

  int stage_v_182_1 = ((pub_r001408_3_1 * 2) + 30) & 63;
  int stage_v_182_2 = ((pub_r001408_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = 0;
  int stage_v_183_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_183_1 = ((stage_v_183_1 + (it_1 * 3)) + (stage_v_31_1 & 15)) & 63;
    stage_v_183_2 = ((stage_v_183_2 + (it_2 * 3)) + (stage_v_31_2 & 15)) & 63;
    if ((stage_v_31_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_183_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_183_1) + 7) & 255;
    }
    if ((stage_v_31_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_183_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_183_2) + 7) & 255;
    }
  }

  int stage_v_184_1 = ((pub_r001408_8_1 * 2) + 37) & 63;
  int stage_v_184_2 = ((pub_r001408_8_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = 0;
  int stage_v_185_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_185_1 = ((stage_v_185_1 + (it_1 * 3)) + (stage_v_128_1 & 15)) & 63;
    stage_v_185_2 = ((stage_v_185_2 + (it_2 * 3)) + (stage_v_128_2 & 15)) & 63;
    if ((stage_v_128_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_185_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_185_1) + 7) & 255;
    }
    if ((stage_v_128_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_185_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_185_2) + 7) & 255;
    }
  }

  int stage_v_186_1 = 0;
  int stage_v_186_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_186_1 = ((stage_v_186_1 + (it_1 * 3)) + (stage_v_39_1 & 15)) & 63;
    stage_v_186_2 = ((stage_v_186_2 + (it_2 * 3)) + (stage_v_39_2 & 15)) & 63;
    if ((stage_v_39_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_186_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_186_1) + 7) & 255;
    }
    if ((stage_v_39_2 & 1) != 0)
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
    stage_v_187_1 = ((stage_v_187_1 + (it_1 * 3)) + (stage_v_27_1 & 15)) & 63;
    stage_v_187_2 = ((stage_v_187_2 + (it_2 * 3)) + (stage_v_27_2 & 15)) & 63;
    if ((stage_v_27_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_187_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_187_1) + 7) & 255;
    }
    if ((stage_v_27_2 & 1) != 0)
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
    stage_v_188_1 = ((stage_v_188_1 + (it_1 * 3)) + (sec_r001408_14_1 & 15)) & 63;
    stage_v_188_2 = ((stage_v_188_2 + (it_2 * 3)) + (sec_r001408_14_2 & 15)) & 63;
    if ((sec_r001408_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_188_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_188_1) + 7) & 255;
    }
    if ((sec_r001408_14_2 & 1) != 0)
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
    stage_v_189_1 = ((stage_v_189_1 + (it_1 * 3)) + (stage_v_175_1 & 15)) & 63;
    stage_v_189_2 = ((stage_v_189_2 + (it_2 * 3)) + (stage_v_175_2 & 15)) & 63;
    if ((stage_v_175_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_189_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_189_1) + 7) & 255;
    }
    if ((stage_v_175_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_189_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_189_2) + 7) & 255;
    }
  }

  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001408_14_1 != sec_r001408_14_2);
  __CPROVER_assume(sec_r001408_9_1 != sec_r001408_9_2);
  __CPROVER_assume(sec_r001408_21_1 != sec_r001408_21_2);
  __CPROVER_assume(pub_r001408_13_1 == pub_r001408_13_2);
  __CPROVER_assume(pub_r001408_8_1 == pub_r001408_8_2);
  __CPROVER_assume(sec_r001408_19_1 != sec_r001408_19_2);
  __CPROVER_assume(pub_r001408_9_1 == pub_r001408_9_2);
  __CPROVER_assume(pub_r001408_12_1 == pub_r001408_12_2);
  __CPROVER_assume(sec_r001408_3_1 != sec_r001408_3_2);
  __CPROVER_assume(pub_r001408_0_1 == pub_r001408_0_2);
  __CPROVER_assume(pub_r001408_6_1 == pub_r001408_6_2);
  __CPROVER_assume(sec_r001408_7_1 != sec_r001408_7_2);
  __CPROVER_assume(sec_r001408_8_1 != sec_r001408_8_2);
  __CPROVER_assume(sec_r001408_1_1 != sec_r001408_1_2);
  __CPROVER_assume(sec_r001408_5_1 != sec_r001408_5_2);
  __CPROVER_assume(sec_r001408_17_1 != sec_r001408_17_2);
  __CPROVER_assume(sec_r001408_6_1 != sec_r001408_6_2);
  __CPROVER_assume(sec_r001408_10_1 != sec_r001408_10_2);
  __CPROVER_assume(pub_r001408_2_1 == pub_r001408_2_2);
  __CPROVER_assume(pub_r001408_16_1 == pub_r001408_16_2);
  __CPROVER_assume(pub_r001408_5_1 == pub_r001408_5_2);
  __CPROVER_assume(pub_r001408_1_1 == pub_r001408_1_2);
  __CPROVER_assume(sec_r001408_18_1 != sec_r001408_18_2);
  __CPROVER_assume(sec_r001408_16_1 != sec_r001408_16_2);
  __CPROVER_assume(pub_r001408_10_1 == pub_r001408_10_2);
  __CPROVER_assume(pub_r001408_17_1 == pub_r001408_17_2);
  __CPROVER_assume(pub_r001408_3_1 == pub_r001408_3_2);
  __CPROVER_assume(sec_r001408_11_1 != sec_r001408_11_2);
  __CPROVER_assume(sec_r001408_15_1 != sec_r001408_15_2);
  __CPROVER_assume(sec_r001408_20_1 != sec_r001408_20_2);
  __CPROVER_assume(sec_r001408_0_1 != sec_r001408_0_2);
  __CPROVER_assume(sec_r001408_4_1 != sec_r001408_4_2);
  __CPROVER_assume(sec_r001408_22_1 != sec_r001408_22_2);
  __CPROVER_assume(pub_r001408_11_1 == pub_r001408_11_2);
  __CPROVER_assume(sec_r001408_13_1 != sec_r001408_13_2);
  __CPROVER_assume(pub_r001408_4_1 == pub_r001408_4_2);
  __CPROVER_assume(pub_r001408_7_1 == pub_r001408_7_2);
  __CPROVER_assume(pub_r001408_15_1 == pub_r001408_15_2);
  __CPROVER_assume(pub_r001408_14_1 == pub_r001408_14_2);
  __CPROVER_assume(sec_r001408_12_1 != sec_r001408_12_2);
  __CPROVER_assume(sec_r001408_2_1 != sec_r001408_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.channels == st_var_2_2.channels);
  assert(st_var_2_1.peak == st_var_2_2.peak);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.sample_rate == st_var_2_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.dim == st_var_3_2.dim);
  assert(st_var_3_1.trace == st_var_3_2.trace);
  assert(st_var_3_1.scale == st_var_3_2.scale);
  assert(st_var_3_1.density == st_var_3_2.density);
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
}


