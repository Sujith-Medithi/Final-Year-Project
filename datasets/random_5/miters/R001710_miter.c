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
struct AudioFrame_R001710_1013_0
{
  int channels;
  unsigned char envelope;
  short rms;
  int sample_rate;
  unsigned char gain;
  int peak;
  int buffer[3];
};
struct MatrixBlock_R001710_1013_1
{
  int determinant;
  short trace;
  short stride;
  int density;
  short dim;
  int buffer[3];
};
struct EventLog_R001710_1013_2
{
  unsigned char timestamp;
  int seq;
  int severity;
  int signature;
  int buffer[3];
};
union PacketPayload_R001710_1013_0
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
void fn_R001710_1013_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001710_1013_2 st_1 = {0};
  struct EventLog_R001710_1013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int delta_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_81_1)
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

  switch (delta_81_2)
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

  int stride_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_76_1) & 63;
  aux_2 = (aux_2 + stride_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_71_1 > 31)
  {
    acc_1 = ((acc_1 + (tally_71_1 * 2)) + 5) & 127;
    aux_1 ^= tally_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_71_2 > 31)
  {
    acc_2 = ((acc_2 + (tally_71_2 * 2)) + 5) & 127;
    aux_2 ^= tally_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_71_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_81_1 == delta_81_2);
  assert(stride_76_1 == stride_76_2);
  assert(tally_71_1 == tally_71_2);
}

int fn_R001710_1013_0(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001710_1013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int delta_81 = (aux + st.buffer[1]) & 3;
  switch (delta_81)
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

  int stride_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_76) & 63;
  acc ^= aux;
  int tally_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_71 > 31)
  {
    acc = ((acc + (tally_71 * 2)) + 5) & 127;
    aux ^= tally_71 & 15;
  }
  else
  {
    acc = ((acc - tally_71) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001710_1013_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st_1 = {0};
  struct MatrixBlock_R001710_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int pivot_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_38_1)
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

  switch (pivot_38_2)
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

  int offset_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_43_1) & 63;
  aux_2 = (aux_2 + offset_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_12_1 > 35)
  {
    acc_1 = ((acc_1 + (index_reg_12_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_12_2 > 35)
  {
    acc_2 = ((acc_2 + (index_reg_12_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_38_1 == pivot_38_2);
  assert(offset_43_1 == offset_43_2);
  assert(index_reg_12_1 == index_reg_12_2);
}

int fn_R001710_1013_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int pivot_38 = (aux + st.buffer[1]) & 3;
  switch (pivot_38)
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

  int offset_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_43) & 63;
  acc ^= aux;
  int index_reg_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_12 > 35)
  {
    acc = ((acc + (index_reg_12 * 2)) + 5) & 127;
    aux ^= index_reg_12 & 15;
  }
  else
  {
    acc = ((acc - index_reg_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001710_1013_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001710_1013_2 st_1 = {0};
  struct EventLog_R001710_1013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_58_1 = local_arr_1[aux_1 % 3];
  int mask_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_58_2 * 2)) & 127;
  int vector_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_56_1) & 63;
  aux_2 = (aux_2 + vector_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_44_1 = 0;
  int factor_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_44_1 = ((factor_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_44_2 = ((factor_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_44_1) & 127;
    acc_2 = (acc_2 + factor_44_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
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

  assert(mask_58_1 == mask_58_2);
  assert(vector_56_1 == vector_56_2);
  assert(factor_44_1 == factor_44_2);
}

int fn_R001710_1013_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001710_1013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int mask_58 = local_arr[aux % 3];
  acc = (acc + (mask_58 * 2)) & 127;
  int vector_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_56) & 63;
  acc ^= aux;
  int factor_44 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_44 = ((factor_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_44) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001710_1013_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001710_1013_2 st_1 = {0};
  struct EventLog_R001710_1013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_13_1 = local_arr_1[aux_1 % 3];
  int scale_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_13_2 * 2)) & 127;
  int stride_92_1 = 0;
  int stride_92_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_92_1 = ((stride_92_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_92_2 = ((stride_92_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_92_1) & 127;
    acc_2 = (acc_2 + stride_92_2) & 127;
  }

  int residue_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_61_1) & 63;
  aux_2 = (aux_2 + residue_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
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

  assert(scale_13_1 == scale_13_2);
  assert(stride_92_1 == stride_92_2);
  assert(residue_61_1 == residue_61_2);
}

int fn_R001710_1013_3(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001710_1013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_13 = local_arr[aux % 3];
  acc = (acc + (scale_13 * 2)) & 127;
  int stride_92 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_92 = ((stride_92 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_92) & 127;
  }

  int residue_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_61) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001710_1013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001710_1013_0 st_1 = {0};
  struct AudioFrame_R001710_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int checksum_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_78_1) & 63;
  aux_2 = (aux_2 + checksum_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_30_1 = 0;
  int cursor_30_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_30_1 = ((cursor_30_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_30_2 = ((cursor_30_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_30_1) & 127;
    acc_2 = (acc_2 + cursor_30_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_78_1 == checksum_78_2);
  assert(cursor_30_1 == cursor_30_2);
}

int fn_R001710_1013_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001710_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int checksum_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_78) & 63;
  acc ^= aux;
  int cursor_30 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_30 = ((cursor_30 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_30) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001710_1013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st_1 = {0};
  struct MatrixBlock_R001710_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int bound_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_47_1)
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

  switch (bound_47_2)
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
  int quotient_94_1 = local_arr_1[aux_1 % 3];
  int quotient_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_94_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_47_1 == bound_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_94_1 == quotient_94_2);
}

int fn_R001710_1013_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int bound_47 = (aux + st.buffer[1]) & 3;
  switch (bound_47)
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
  int quotient_94 = local_arr[aux % 3];
  acc = (acc + (quotient_94 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001710_1013_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st_1 = {0};
  struct MatrixBlock_R001710_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_73_1 = local_arr_1[aux_1 % 3];
  int vector_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_73_2 * 2)) & 127;
  int damping_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_55_1) & 63;
  aux_2 = (aux_2 + damping_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_96_1)
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

  switch (pivot_96_2)
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

  int quantum_72_1 = 0;
  int quantum_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_72_1 = ((quantum_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_72_2 = ((quantum_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_72_1) & 127;
    acc_2 = (acc_2 + quantum_72_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_73_1 == vector_73_2);
  assert(damping_55_1 == damping_55_2);
  assert(pivot_96_1 == pivot_96_2);
  assert(quantum_72_1 == quantum_72_2);
}

int fn_R001710_1013_6(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int vector_73 = local_arr[aux % 3];
  acc = (acc + (vector_73 * 2)) & 127;
  int damping_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_55) & 63;
  acc ^= aux;
  int pivot_96 = (aux + st.buffer[1]) & 3;
  switch (pivot_96)
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

  int quantum_72 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_72 = ((quantum_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_72) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001710_1013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001710_1013_2 st_1 = {0};
  struct EventLog_R001710_1013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int tracker_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_39_1)
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

  switch (tracker_39_2)
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

  int phase_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_93_1) & 63;
  aux_2 = (aux_2 + phase_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_39_1 == tracker_39_2);
  assert(phase_93_1 == phase_93_2);
}

int fn_R001710_1013_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001710_1013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int tracker_39 = (aux + st.buffer[1]) & 3;
  switch (tracker_39)
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

  int phase_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_93) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001710_1013_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001710_1013_0 st_1 = {0};
  struct AudioFrame_R001710_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int accumulator_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_26_1 > 21)
  {
    acc_1 = ((acc_1 + (accumulator_26_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_26_2 > 21)
  {
    acc_2 = ((acc_2 + (accumulator_26_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_32_1) & 63;
  aux_2 = (aux_2 + factor_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_58_1 = 0;
  int index_reg_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_58_1 = ((index_reg_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_58_2 = ((index_reg_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_58_1) & 127;
    acc_2 = (acc_2 + index_reg_58_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_26_1 == accumulator_26_2);
  assert(factor_32_1 == factor_32_2);
  assert(index_reg_58_1 == index_reg_58_2);
}

int fn_R001710_1013_8(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001710_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int accumulator_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_26 > 21)
  {
    acc = ((acc + (accumulator_26 * 2)) + 5) & 127;
    aux ^= accumulator_26 & 15;
  }
  else
  {
    acc = ((acc - accumulator_26) + 11) & 127;
    aux += 3;
  }
  int factor_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_32) & 63;
  acc ^= aux;
  int index_reg_58 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_58 = ((index_reg_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_58) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001710_1013_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001710_1013_2 st_1 = {0};
  struct EventLog_R001710_1013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int bound_95_1 = 0;
  int bound_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_95_1 = ((bound_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_95_2 = ((bound_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_95_1) & 127;
    acc_2 = (acc_2 + bound_95_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_68_1 = local_arr_1[aux_1 % 3];
  int quantum_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_95_1 == bound_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_68_1 == quantum_68_2);
}

int fn_R001710_1013_9(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001710_1013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int bound_95 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_95 = ((bound_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_95) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int quantum_68 = local_arr[aux % 3];
  acc = (acc + (quantum_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001710_1013_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001710_1013_2 st_1 = {0};
  struct EventLog_R001710_1013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_73_1) & 63;
  aux_2 = (aux_2 + scale_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_73_1 == scale_73_2);
}

int fn_R001710_1013_10(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001710_1013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_73) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001710_1013_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st_1 = {0};
  struct MatrixBlock_R001710_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int phase_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_73_1)
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

  switch (phase_73_2)
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

  int scale_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_27_1 > 50)
  {
    acc_1 = ((acc_1 + (scale_27_1 * 2)) + 5) & 127;
    aux_1 ^= scale_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_27_2 > 50)
  {
    acc_2 = ((acc_2 + (scale_27_2 * 2)) + 5) & 127;
    aux_2 ^= scale_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_21_1 = 0;
  int quantum_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_21_1 = ((quantum_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_21_2 = ((quantum_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_21_1) & 127;
    acc_2 = (acc_2 + quantum_21_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_73_1 == phase_73_2);
  assert(scale_27_1 == scale_27_2);
  assert(quantum_21_1 == quantum_21_2);
}

int fn_R001710_1013_11(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int phase_73 = (aux + st.buffer[1]) & 3;
  switch (phase_73)
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

  int scale_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_27 > 50)
  {
    acc = ((acc + (scale_27 * 2)) + 5) & 127;
    aux ^= scale_27 & 15;
  }
  else
  {
    acc = ((acc - scale_27) + 11) & 127;
    aux += 3;
  }
  int quantum_21 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_21 = ((quantum_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_21) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001710_1013_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st_1 = {0};
  struct MatrixBlock_R001710_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_96_1 = local_arr_1[aux_1 % 3];
  int delta_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_96_2 * 2)) & 127;
  int phase_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_98_1 > 34)
  {
    acc_1 = ((acc_1 + (phase_98_1 * 2)) + 5) & 127;
    aux_1 ^= phase_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_98_2 > 34)
  {
    acc_2 = ((acc_2 + (phase_98_2 * 2)) + 5) & 127;
    aux_2 ^= phase_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_24_1)
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

  switch (index_reg_24_2)
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

  int stride_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_56_1) & 63;
  aux_2 = (aux_2 + stride_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_96_1 == delta_96_2);
  assert(phase_98_1 == phase_98_2);
  assert(index_reg_24_1 == index_reg_24_2);
  assert(stride_56_1 == stride_56_2);
}

int fn_R001710_1013_12(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int delta_96 = local_arr[aux % 3];
  acc = (acc + (delta_96 * 2)) & 127;
  int phase_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_98 > 34)
  {
    acc = ((acc + (phase_98 * 2)) + 5) & 127;
    aux ^= phase_98 & 15;
  }
  else
  {
    acc = ((acc - phase_98) + 11) & 127;
    aux += 3;
  }
  int index_reg_24 = (aux + st.buffer[1]) & 3;
  switch (index_reg_24)
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

  int stride_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_56) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001710_1013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001710_1013_0 st_1 = {0};
  struct AudioFrame_R001710_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int checksum_97_1 = 0;
  int checksum_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_97_1 = ((checksum_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_97_2 = ((checksum_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_97_1) & 127;
    acc_2 = (acc_2 + checksum_97_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_46_1 = local_arr_1[aux_1 % 3];
  int tracker_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_46_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_97_1 == checksum_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_46_1 == tracker_46_2);
}

int fn_R001710_1013_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001710_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int checksum_97 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_97 = ((checksum_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_97) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tracker_46 = local_arr[aux % 3];
  acc = (acc + (tracker_46 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001710_1013_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st_1 = {0};
  struct MatrixBlock_R001710_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int delta_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_44_1) & 63;
  aux_2 = (aux_2 + delta_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_98_1)
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

  switch (threshold_98_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_44_1 == delta_44_2);
  assert(threshold_98_1 == threshold_98_2);
}

int fn_R001710_1013_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int delta_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_44) & 63;
  acc ^= aux;
  int threshold_98 = (aux + st.buffer[1]) & 3;
  switch (threshold_98)
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

  return (acc + aux) & 255;
}

void fn_R001710_1013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001710_1013_2 st_1 = {0};
  struct EventLog_R001710_1013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int margin_75_1 = 0;
  int margin_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_75_1 = ((margin_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_75_2 = ((margin_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_75_1) & 127;
    acc_2 = (acc_2 + margin_75_2) & 127;
  }

  int pivot_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_54_1 > 20)
  {
    acc_1 = ((acc_1 + (pivot_54_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_54_2 > 20)
  {
    acc_2 = ((acc_2 + (pivot_54_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_54_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_30_1)
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

  switch (residue_30_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_75_1 == margin_75_2);
  assert(pivot_54_1 == pivot_54_2);
  assert(residue_30_1 == residue_30_2);
}

int fn_R001710_1013_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001710_1013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int margin_75 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_75 = ((margin_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_75) & 127;
  }

  int pivot_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_54 > 20)
  {
    acc = ((acc + (pivot_54 * 2)) + 5) & 127;
    aux ^= pivot_54 & 15;
  }
  else
  {
    acc = ((acc - pivot_54) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_30 = (aux + st.buffer[1]) & 3;
  switch (residue_30)
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

void fn_R001710_1013_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st_1 = {0};
  struct MatrixBlock_R001710_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int anchor_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_76_1)
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

  switch (anchor_76_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_51_1 = local_arr_1[aux_1 % 3];
  int checksum_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_76_1 == anchor_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_51_1 == checksum_51_2);
}

int fn_R001710_1013_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int anchor_76 = (aux + st.buffer[1]) & 3;
  switch (anchor_76)
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

  int local_arr[3] = {4, 9, 15};
  int checksum_51 = local_arr[aux % 3];
  acc = (acc + (checksum_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001710_1013_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001710_1013_0 st_1 = {0};
  struct AudioFrame_R001710_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_48_1 = local_arr_1[aux_1 % 3];
  int vector_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_48_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_48_1 == vector_48_2);
}

int fn_R001710_1013_17(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001710_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_48 = local_arr[aux % 3];
  acc = (acc + (vector_48 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001710_1013_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st_1 = {0};
  struct MatrixBlock_R001710_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int threshold_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_10_1) & 63;
  aux_2 = (aux_2 + threshold_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_15_1 = 0;
  int tracker_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_15_1 = ((tracker_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_15_2 = ((tracker_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_15_1) & 127;
    acc_2 = (acc_2 + tracker_15_2) & 127;
  }

  int pivot_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_23_1)
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

  switch (pivot_23_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_10_1 == threshold_10_2);
  assert(tracker_15_1 == tracker_15_2);
  assert(pivot_23_1 == pivot_23_2);
}

int fn_R001710_1013_18(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int threshold_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_10) & 63;
  acc ^= aux;
  int tracker_15 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_15 = ((tracker_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_15) & 127;
  }

  int pivot_23 = (aux + st.buffer[1]) & 3;
  switch (pivot_23)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001710_1013_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001710_1013_0 st_1 = {0};
  struct AudioFrame_R001710_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int pivot_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_46_1)
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

  switch (pivot_46_2)
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

  int anchor_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_44_1) & 63;
  aux_2 = (aux_2 + anchor_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_84_1 > 38)
  {
    acc_1 = ((acc_1 + (cursor_84_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_84_2 > 38)
  {
    acc_2 = ((acc_2 + (cursor_84_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_84_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_46_1 == pivot_46_2);
  assert(anchor_44_1 == anchor_44_2);
  assert(cursor_84_1 == cursor_84_2);
}

int fn_R001710_1013_19(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001710_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int pivot_46 = (aux + st.buffer[1]) & 3;
  switch (pivot_46)
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

  int anchor_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_44) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_84 > 38)
  {
    acc = ((acc + (cursor_84 * 2)) + 5) & 127;
    aux ^= cursor_84 & 15;
  }
  else
  {
    acc = ((acc - cursor_84) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001710_1013_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st_1 = {0};
  struct MatrixBlock_R001710_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int vector_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_74_1) & 63;
  aux_2 = (aux_2 + vector_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_61_1 = 0;
  int quotient_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_61_1 = ((quotient_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_61_2 = ((quotient_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_61_1) & 127;
    acc_2 = (acc_2 + quotient_61_2) & 127;
  }

  int scale_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_92_1)
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

  switch (scale_92_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_74_1 == vector_74_2);
  assert(quotient_61_1 == quotient_61_2);
  assert(scale_92_1 == scale_92_2);
}

int fn_R001710_1013_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int vector_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_74) & 63;
  acc ^= aux;
  int quotient_61 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_61 = ((quotient_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_61) & 127;
  }

  int scale_92 = (aux + st.buffer[1]) & 3;
  switch (scale_92)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001710_1013_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st_1 = {0};
  struct MatrixBlock_R001710_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int coefficient_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_85_1 > 34)
  {
    acc_1 = ((acc_1 + (coefficient_85_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_85_2 > 34)
  {
    acc_2 = ((acc_2 + (coefficient_85_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_99_1 = 0;
  int tracker_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_99_1 = ((tracker_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_99_2 = ((tracker_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_99_1) & 127;
    acc_2 = (acc_2 + tracker_99_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_85_1 == coefficient_85_2);
  assert(tracker_99_1 == tracker_99_2);
}

int fn_R001710_1013_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int coefficient_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_85 > 34)
  {
    acc = ((acc + (coefficient_85 * 2)) + 5) & 127;
    aux ^= coefficient_85 & 15;
  }
  else
  {
    acc = ((acc - coefficient_85) + 11) & 127;
    aux += 3;
  }
  int tracker_99 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_99 = ((tracker_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_99) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001710_1013_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st_1 = {0};
  struct MatrixBlock_R001710_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_26_1 = local_arr_1[aux_1 % 3];
  int scale_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_26_2 * 2)) & 127;
  int threshold_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_38_1)
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

  switch (threshold_38_2)
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

  int scale_59_1 = 0;
  int scale_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_59_1 = ((scale_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_59_2 = ((scale_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_59_1) & 127;
    acc_2 = (acc_2 + scale_59_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_26_1 == scale_26_2);
  assert(threshold_38_1 == threshold_38_2);
  assert(scale_59_1 == scale_59_2);
}

int fn_R001710_1013_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001710_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int scale_26 = local_arr[aux % 3];
  acc = (acc + (scale_26 * 2)) & 127;
  int threshold_38 = (aux + st.buffer[1]) & 3;
  switch (threshold_38)
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

  int scale_59 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_59 = ((scale_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_59) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001710_1013_23_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001710_1013_0 st_1 = {0};
  struct AudioFrame_R001710_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int offset_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_95_1)
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

  switch (offset_95_2)
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

  int sample_23_1 = 0;
  int sample_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_23_1 = ((sample_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_23_2 = ((sample_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_23_1) & 127;
    acc_2 = (acc_2 + sample_23_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_95_1 == offset_95_2);
  assert(sample_23_1 == sample_23_2);
}

int fn_R001710_1013_23(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001710_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int offset_95 = (aux + st.buffer[1]) & 3;
  switch (offset_95)
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

  int sample_23 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_23 = ((sample_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_23) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001710_0_1;
  int sec_r001710_0_2;
  int sec_r001710_1_1;
  int sec_r001710_1_2;
  int sec_r001710_2_1;
  int sec_r001710_2_2;
  int sec_r001710_3_1;
  int sec_r001710_3_2;
  int sec_r001710_4_1;
  int sec_r001710_4_2;
  int sec_r001710_5_1;
  int sec_r001710_5_2;
  int sec_r001710_6_1;
  int sec_r001710_6_2;
  int sec_r001710_7_1;
  int sec_r001710_7_2;
  int sec_r001710_8_1;
  int sec_r001710_8_2;
  int sec_r001710_9_1;
  int sec_r001710_9_2;
  int sec_r001710_10_1;
  int sec_r001710_10_2;
  int sec_r001710_11_1;
  int sec_r001710_11_2;
  int sec_r001710_12_1;
  int sec_r001710_12_2;
  int sec_r001710_13_1;
  int sec_r001710_13_2;
  int sec_r001710_14_1;
  int sec_r001710_14_2;
  int sec_r001710_15_1;
  int sec_r001710_15_2;
  int sec_r001710_16_1;
  int sec_r001710_16_2;
  int sec_r001710_17_1;
  int sec_r001710_17_2;
  int pub_r001710_0_1;
  int pub_r001710_0_2;
  int pub_r001710_1_1;
  int pub_r001710_1_2;
  int pub_r001710_2_1;
  int pub_r001710_2_2;
  int pub_r001710_3_1;
  int pub_r001710_3_2;
  int pub_r001710_4_1;
  int pub_r001710_4_2;
  int pub_r001710_5_1;
  int pub_r001710_5_2;
  int pub_r001710_6_1;
  int pub_r001710_6_2;
  int pub_r001710_7_1;
  int pub_r001710_7_2;
  int pub_r001710_8_1;
  int pub_r001710_8_2;
  int pub_r001710_9_1;
  int pub_r001710_9_2;
  int pub_r001710_10_1;
  int pub_r001710_10_2;
  int pub_r001710_11_1;
  int pub_r001710_11_2;
  int pub_r001710_12_1;
  int pub_r001710_12_2;
  int pub_r001710_13_1;
  int pub_r001710_13_2;
  int pub_r001710_14_1;
  int pub_r001710_14_2;
  int pub_r001710_15_1;
  int pub_r001710_15_2;
  int pub_r001710_16_1;
  int pub_r001710_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001710_0_1 >= (-100)) && (pub_r001710_0_1 <= 100));
  __CPROVER_assume((pub_r001710_0_2 >= (-100)) && (pub_r001710_0_2 <= 100));
  __CPROVER_assume((pub_r001710_1_1 >= (-100)) && (pub_r001710_1_1 <= 100));
  __CPROVER_assume((pub_r001710_1_2 >= (-100)) && (pub_r001710_1_2 <= 100));
  __CPROVER_assume((pub_r001710_2_1 >= (-100)) && (pub_r001710_2_1 <= 100));
  __CPROVER_assume((pub_r001710_2_2 >= (-100)) && (pub_r001710_2_2 <= 100));
  __CPROVER_assume((pub_r001710_3_1 >= (-100)) && (pub_r001710_3_1 <= 100));
  __CPROVER_assume((pub_r001710_3_2 >= (-100)) && (pub_r001710_3_2 <= 100));
  __CPROVER_assume((pub_r001710_4_1 >= (-100)) && (pub_r001710_4_1 <= 100));
  __CPROVER_assume((pub_r001710_4_2 >= (-100)) && (pub_r001710_4_2 <= 100));
  __CPROVER_assume((pub_r001710_5_1 >= (-100)) && (pub_r001710_5_1 <= 100));
  __CPROVER_assume((pub_r001710_5_2 >= (-100)) && (pub_r001710_5_2 <= 100));
  __CPROVER_assume((pub_r001710_6_1 >= (-100)) && (pub_r001710_6_1 <= 100));
  __CPROVER_assume((pub_r001710_6_2 >= (-100)) && (pub_r001710_6_2 <= 100));
  __CPROVER_assume((pub_r001710_7_1 >= (-100)) && (pub_r001710_7_1 <= 100));
  __CPROVER_assume((pub_r001710_7_2 >= (-100)) && (pub_r001710_7_2 <= 100));
  __CPROVER_assume((pub_r001710_8_1 >= (-100)) && (pub_r001710_8_1 <= 100));
  __CPROVER_assume((pub_r001710_8_2 >= (-100)) && (pub_r001710_8_2 <= 100));
  __CPROVER_assume((pub_r001710_9_1 >= (-100)) && (pub_r001710_9_1 <= 100));
  __CPROVER_assume((pub_r001710_9_2 >= (-100)) && (pub_r001710_9_2 <= 100));
  __CPROVER_assume((pub_r001710_10_1 >= (-100)) && (pub_r001710_10_1 <= 100));
  __CPROVER_assume((pub_r001710_10_2 >= (-100)) && (pub_r001710_10_2 <= 100));
  __CPROVER_assume((pub_r001710_11_1 >= (-100)) && (pub_r001710_11_1 <= 100));
  __CPROVER_assume((pub_r001710_11_2 >= (-100)) && (pub_r001710_11_2 <= 100));
  __CPROVER_assume((pub_r001710_12_1 >= (-100)) && (pub_r001710_12_1 <= 100));
  __CPROVER_assume((pub_r001710_12_2 >= (-100)) && (pub_r001710_12_2 <= 100));
  __CPROVER_assume((pub_r001710_13_1 >= (-100)) && (pub_r001710_13_1 <= 100));
  __CPROVER_assume((pub_r001710_13_2 >= (-100)) && (pub_r001710_13_2 <= 100));
  __CPROVER_assume((pub_r001710_14_1 >= (-100)) && (pub_r001710_14_1 <= 100));
  __CPROVER_assume((pub_r001710_14_2 >= (-100)) && (pub_r001710_14_2 <= 100));
  __CPROVER_assume((pub_r001710_15_1 >= (-100)) && (pub_r001710_15_1 <= 100));
  __CPROVER_assume((pub_r001710_15_2 >= (-100)) && (pub_r001710_15_2 <= 100));
  __CPROVER_assume((pub_r001710_16_1 >= (-100)) && (pub_r001710_16_1 <= 100));
  __CPROVER_assume((pub_r001710_16_2 >= (-100)) && (pub_r001710_16_2 <= 100));
  __CPROVER_assume((sec_r001710_0_1 >= 0) && (sec_r001710_0_1 <= 255));
  __CPROVER_assume((sec_r001710_0_2 >= 0) && (sec_r001710_0_2 <= 255));
  __CPROVER_assume((sec_r001710_1_1 >= 0) && (sec_r001710_1_1 <= 255));
  __CPROVER_assume((sec_r001710_1_2 >= 0) && (sec_r001710_1_2 <= 255));
  __CPROVER_assume((sec_r001710_2_1 >= 0) && (sec_r001710_2_1 <= 255));
  __CPROVER_assume((sec_r001710_2_2 >= 0) && (sec_r001710_2_2 <= 255));
  __CPROVER_assume((sec_r001710_3_1 >= 0) && (sec_r001710_3_1 <= 255));
  __CPROVER_assume((sec_r001710_3_2 >= 0) && (sec_r001710_3_2 <= 255));
  __CPROVER_assume((sec_r001710_4_1 >= 0) && (sec_r001710_4_1 <= 255));
  __CPROVER_assume((sec_r001710_4_2 >= 0) && (sec_r001710_4_2 <= 255));
  __CPROVER_assume((sec_r001710_5_1 >= 0) && (sec_r001710_5_1 <= 255));
  __CPROVER_assume((sec_r001710_5_2 >= 0) && (sec_r001710_5_2 <= 255));
  __CPROVER_assume((sec_r001710_6_1 >= 0) && (sec_r001710_6_1 <= 255));
  __CPROVER_assume((sec_r001710_6_2 >= 0) && (sec_r001710_6_2 <= 255));
  __CPROVER_assume((sec_r001710_7_1 >= 0) && (sec_r001710_7_1 <= 255));
  __CPROVER_assume((sec_r001710_7_2 >= 0) && (sec_r001710_7_2 <= 255));
  __CPROVER_assume((sec_r001710_8_1 >= 0) && (sec_r001710_8_1 <= 255));
  __CPROVER_assume((sec_r001710_8_2 >= 0) && (sec_r001710_8_2 <= 255));
  __CPROVER_assume((sec_r001710_9_1 >= 0) && (sec_r001710_9_1 <= 255));
  __CPROVER_assume((sec_r001710_9_2 >= 0) && (sec_r001710_9_2 <= 255));
  __CPROVER_assume((sec_r001710_10_1 >= 0) && (sec_r001710_10_1 <= 255));
  __CPROVER_assume((sec_r001710_10_2 >= 0) && (sec_r001710_10_2 <= 255));
  __CPROVER_assume((sec_r001710_11_1 >= 0) && (sec_r001710_11_1 <= 255));
  __CPROVER_assume((sec_r001710_11_2 >= 0) && (sec_r001710_11_2 <= 255));
  __CPROVER_assume((sec_r001710_12_1 >= 0) && (sec_r001710_12_1 <= 255));
  __CPROVER_assume((sec_r001710_12_2 >= 0) && (sec_r001710_12_2 <= 255));
  __CPROVER_assume((sec_r001710_13_1 >= 0) && (sec_r001710_13_1 <= 255));
  __CPROVER_assume((sec_r001710_13_2 >= 0) && (sec_r001710_13_2 <= 255));
  __CPROVER_assume((sec_r001710_14_1 >= 0) && (sec_r001710_14_1 <= 255));
  __CPROVER_assume((sec_r001710_14_2 >= 0) && (sec_r001710_14_2 <= 255));
  __CPROVER_assume((sec_r001710_15_1 >= 0) && (sec_r001710_15_1 <= 255));
  __CPROVER_assume((sec_r001710_15_2 >= 0) && (sec_r001710_15_2 <= 255));
  __CPROVER_assume((sec_r001710_16_1 >= 0) && (sec_r001710_16_1 <= 255));
  __CPROVER_assume((sec_r001710_16_2 >= 0) && (sec_r001710_16_2 <= 255));
  __CPROVER_assume((sec_r001710_17_1 >= 0) && (sec_r001710_17_1 <= 255));
  __CPROVER_assume((sec_r001710_17_2 >= 0) && (sec_r001710_17_2 <= 255));
  struct AudioFrame_R001710_1013_0 st_var_0_1 = {0};
  struct AudioFrame_R001710_1013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001710_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001710_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001710_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001710_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001710_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001710_0_2 + 7) & 15;
  struct MatrixBlock_R001710_1013_1 st_var_1_1 = {0};
  struct MatrixBlock_R001710_1013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001710_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001710_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001710_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001710_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001710_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001710_0_2 + 9) & 15;
  struct EventLog_R001710_1013_2 st_var_2_1 = {0};
  struct EventLog_R001710_1013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001710_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001710_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001710_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001710_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001710_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001710_0_2 + 11) & 15;
  union PacketPayload_R001710_1013_0 u_var_1;
  union PacketPayload_R001710_1013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001710_1013_0(sec_r001710_0_1, sec_r001710_1_1);
  int helper_flow_0_2 = fn_R001710_1013_0(sec_r001710_0_2, sec_r001710_1_2);
  fn_R001710_1013_0_2(sec_r001710_0_1, sec_r001710_1_1, sec_r001710_0_2, sec_r001710_1_2);
  int helper_flow_1_1 = fn_R001710_1013_1(sec_r001710_1_1, sec_r001710_2_1, pub_r001710_3_1, pub_r001710_4_1, pub_r001710_5_1);
  int helper_flow_1_2 = fn_R001710_1013_1(sec_r001710_1_2, sec_r001710_2_2, pub_r001710_3_2, pub_r001710_4_2, pub_r001710_5_2);
  fn_R001710_1013_1_2(sec_r001710_1_1, sec_r001710_2_1, pub_r001710_3_1, pub_r001710_4_1, pub_r001710_5_1, sec_r001710_1_2, sec_r001710_2_2, pub_r001710_3_2, pub_r001710_4_2, pub_r001710_5_2);
  int helper_flow_2_1 = fn_R001710_1013_2(sec_r001710_2_1, sec_r001710_3_1, pub_r001710_4_1, pub_r001710_5_1, pub_r001710_6_1);
  int helper_flow_2_2 = fn_R001710_1013_2(sec_r001710_2_2, sec_r001710_3_2, pub_r001710_4_2, pub_r001710_5_2, pub_r001710_6_2);
  fn_R001710_1013_2_2(sec_r001710_2_1, sec_r001710_3_1, pub_r001710_4_1, pub_r001710_5_1, pub_r001710_6_1, sec_r001710_2_2, sec_r001710_3_2, pub_r001710_4_2, pub_r001710_5_2, pub_r001710_6_2);
  int helper_flow_3_1 = fn_R001710_1013_3(sec_r001710_3_1, sec_r001710_4_1, pub_r001710_5_1);
  int helper_flow_3_2 = fn_R001710_1013_3(sec_r001710_3_2, sec_r001710_4_2, pub_r001710_5_2);
  fn_R001710_1013_3_2(sec_r001710_3_1, sec_r001710_4_1, pub_r001710_5_1, sec_r001710_3_2, sec_r001710_4_2, pub_r001710_5_2);
  int helper_flow_4_1 = fn_R001710_1013_4(sec_r001710_4_1, pub_r001710_5_1, pub_r001710_6_1, pub_r001710_7_1, pub_r001710_8_1);
  int helper_flow_4_2 = fn_R001710_1013_4(sec_r001710_4_2, pub_r001710_5_2, pub_r001710_6_2, pub_r001710_7_2, pub_r001710_8_2);
  fn_R001710_1013_4_2(sec_r001710_4_1, pub_r001710_5_1, pub_r001710_6_1, pub_r001710_7_1, pub_r001710_8_1, sec_r001710_4_2, pub_r001710_5_2, pub_r001710_6_2, pub_r001710_7_2, pub_r001710_8_2);
  int helper_flow_5_1 = fn_R001710_1013_5(sec_r001710_5_1, pub_r001710_6_1, pub_r001710_7_1, pub_r001710_8_1);
  int helper_flow_5_2 = fn_R001710_1013_5(sec_r001710_5_2, pub_r001710_6_2, pub_r001710_7_2, pub_r001710_8_2);
  fn_R001710_1013_5_2(sec_r001710_5_1, pub_r001710_6_1, pub_r001710_7_1, pub_r001710_8_1, sec_r001710_5_2, pub_r001710_6_2, pub_r001710_7_2, pub_r001710_8_2);
  int helper_flow_6_1 = fn_R001710_1013_6(sec_r001710_6_1, sec_r001710_7_1);
  int helper_flow_6_2 = fn_R001710_1013_6(sec_r001710_6_2, sec_r001710_7_2);
  fn_R001710_1013_6_2(sec_r001710_6_1, sec_r001710_7_1, sec_r001710_6_2, sec_r001710_7_2);
  int helper_flow_7_1 = fn_R001710_1013_7(sec_r001710_7_1, pub_r001710_8_1, pub_r001710_9_1, pub_r001710_10_1);
  int helper_flow_7_2 = fn_R001710_1013_7(sec_r001710_7_2, pub_r001710_8_2, pub_r001710_9_2, pub_r001710_10_2);
  fn_R001710_1013_7_2(sec_r001710_7_1, pub_r001710_8_1, pub_r001710_9_1, pub_r001710_10_1, sec_r001710_7_2, pub_r001710_8_2, pub_r001710_9_2, pub_r001710_10_2);
  int helper_flow_8_1 = fn_R001710_1013_8(sec_r001710_8_1, sec_r001710_9_1, pub_r001710_10_1);
  int helper_flow_8_2 = fn_R001710_1013_8(sec_r001710_8_2, sec_r001710_9_2, pub_r001710_10_2);
  fn_R001710_1013_8_2(sec_r001710_8_1, sec_r001710_9_1, pub_r001710_10_1, sec_r001710_8_2, sec_r001710_9_2, pub_r001710_10_2);
  int helper_flow_9_1 = fn_R001710_1013_9(sec_r001710_9_1, sec_r001710_10_1, pub_r001710_11_1);
  int helper_flow_9_2 = fn_R001710_1013_9(sec_r001710_9_2, sec_r001710_10_2, pub_r001710_11_2);
  fn_R001710_1013_9_2(sec_r001710_9_1, sec_r001710_10_1, pub_r001710_11_1, sec_r001710_9_2, sec_r001710_10_2, pub_r001710_11_2);
  int helper_flow_10_1 = fn_R001710_1013_10(sec_r001710_10_1, pub_r001710_11_1);
  int helper_flow_10_2 = fn_R001710_1013_10(sec_r001710_10_2, pub_r001710_11_2);
  fn_R001710_1013_10_2(sec_r001710_10_1, pub_r001710_11_1, sec_r001710_10_2, pub_r001710_11_2);
  int helper_flow_11_1 = fn_R001710_1013_11(sec_r001710_11_1, sec_r001710_12_1, pub_r001710_13_1);
  int helper_flow_11_2 = fn_R001710_1013_11(sec_r001710_11_2, sec_r001710_12_2, pub_r001710_13_2);
  fn_R001710_1013_11_2(sec_r001710_11_1, sec_r001710_12_1, pub_r001710_13_1, sec_r001710_11_2, sec_r001710_12_2, pub_r001710_13_2);
  int helper_flow_12_1 = fn_R001710_1013_12(sec_r001710_12_1, sec_r001710_13_1, pub_r001710_14_1);
  int helper_flow_12_2 = fn_R001710_1013_12(sec_r001710_12_2, sec_r001710_13_2, pub_r001710_14_2);
  fn_R001710_1013_12_2(sec_r001710_12_1, sec_r001710_13_1, pub_r001710_14_1, sec_r001710_12_2, sec_r001710_13_2, pub_r001710_14_2);
  int stage_v_0_1 = (((sec_r001710_11_1 ^ 0x2A) * 2) + pub_r001710_2_1) & 127;
  int stage_v_0_2 = (((sec_r001710_11_2 ^ 0x2A) * 2) + pub_r001710_2_2) & 127;
  if (stage_v_0_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (((sec_r001710_10_1 ^ 0x2A) * 2) + pub_r001710_9_1) & 127;
  int stage_v_1_2 = (((sec_r001710_10_2 ^ 0x2A) * 2) + pub_r001710_9_2) & 127;
  if (stage_v_1_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (((helper_flow_12_1 ^ 0x2A) * 2) + pub_r001710_12_1) & 127;
  int stage_v_2_2 = (((helper_flow_12_2 ^ 0x2A) * 2) + pub_r001710_12_2) & 127;
  if (stage_v_2_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001710_13_1) & 127;
  int stage_v_3_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001710_13_2) & 127;
  if (stage_v_3_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (((sec_r001710_8_1 ^ 0x2A) * 2) + pub_r001710_8_1) & 127;
  int stage_v_4_2 = (((sec_r001710_8_2 ^ 0x2A) * 2) + pub_r001710_8_2) & 127;
  if (stage_v_4_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001710_15_1) & 127;
  int stage_v_5_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001710_15_2) & 127;
  if (stage_v_5_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = ((pub_r001710_14_1 * 2) + 17) & 63;
  int stage_v_6_2 = ((pub_r001710_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001710_12_1 * 2) + 38) & 63;
  int stage_v_7_2 = ((pub_r001710_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (((sec_r001710_14_1 ^ 0x2A) * 2) + pub_r001710_9_1) & 127;
  int stage_v_8_2 = (((sec_r001710_14_2 ^ 0x2A) * 2) + pub_r001710_9_2) & 127;
  if (stage_v_8_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((sec_r001710_14_1 ^ 0x2A) * 2) + pub_r001710_0_1) & 127;
  int stage_v_9_2 = (((sec_r001710_14_2 ^ 0x2A) * 2) + pub_r001710_0_2) & 127;
  if (stage_v_9_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001710_0_1) & 127;
  int stage_v_10_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001710_0_2) & 127;
  if (stage_v_10_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (((sec_r001710_0_1 ^ 0x2A) * 2) + pub_r001710_4_1) & 127;
  int stage_v_11_2 = (((sec_r001710_0_2 ^ 0x2A) * 2) + pub_r001710_4_2) & 127;
  if (stage_v_11_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (((sec_r001710_8_1 ^ 0x2A) * 2) + pub_r001710_0_1) & 127;
  int stage_v_12_2 = (((sec_r001710_8_2 ^ 0x2A) * 2) + pub_r001710_0_2) & 127;
  if (stage_v_12_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001710_7_1) & 127;
  int stage_v_13_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001710_7_2) & 127;
  if (stage_v_13_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = ((pub_r001710_3_1 * 2) + 35) & 63;
  int stage_v_14_2 = ((pub_r001710_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (((sec_r001710_1_1 ^ 0x2A) * 2) + pub_r001710_6_1) & 127;
  int stage_v_15_2 = (((sec_r001710_1_2 ^ 0x2A) * 2) + pub_r001710_6_2) & 127;
  if (stage_v_15_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (((sec_r001710_10_1 ^ 0x2A) * 2) + pub_r001710_2_1) & 127;
  int stage_v_16_2 = (((sec_r001710_10_2 ^ 0x2A) * 2) + pub_r001710_2_2) & 127;
  if (stage_v_16_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((sec_r001710_4_1 ^ 0x2A) * 2) + pub_r001710_2_1) & 127;
  int stage_v_17_2 = (((sec_r001710_4_2 ^ 0x2A) * 2) + pub_r001710_2_2) & 127;
  if (stage_v_17_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001710_1_1) & 127;
  int stage_v_18_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001710_1_2) & 127;
  if (stage_v_18_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((sec_r001710_5_1 ^ 0x2A) * 2) + pub_r001710_2_1) & 127;
  int stage_v_19_2 = (((sec_r001710_5_2 ^ 0x2A) * 2) + pub_r001710_2_2) & 127;
  if (stage_v_19_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001710_0_1) & 127;
  int stage_v_20_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001710_0_2) & 127;
  if (stage_v_20_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((sec_r001710_9_1 ^ 0x2A) * 2) + pub_r001710_10_1) & 127;
  int stage_v_21_2 = (((sec_r001710_9_2 ^ 0x2A) * 2) + pub_r001710_10_2) & 127;
  if (stage_v_21_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (((sec_r001710_8_1 ^ 0x2A) * 2) + pub_r001710_15_1) & 127;
  int stage_v_22_2 = (((sec_r001710_8_2 ^ 0x2A) * 2) + pub_r001710_15_2) & 127;
  if (stage_v_22_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (((sec_r001710_8_1 ^ 0x2A) * 2) + pub_r001710_8_1) & 127;
  int stage_v_23_2 = (((sec_r001710_8_2 ^ 0x2A) * 2) + pub_r001710_8_2) & 127;
  if (stage_v_23_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((sec_r001710_5_1 ^ 0x2A) * 2) + pub_r001710_8_1) & 127;
  int stage_v_24_2 = (((sec_r001710_5_2 ^ 0x2A) * 2) + pub_r001710_8_2) & 127;
  if (stage_v_24_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((pub_r001710_13_1 * 2) + 9) & 63;
  int stage_v_25_2 = ((pub_r001710_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001710_12_1) & 127;
  int stage_v_26_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001710_12_2) & 127;
  if (stage_v_26_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((pub_r001710_9_1 * 2) + 19) & 63;
  int stage_v_27_2 = ((pub_r001710_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001710_8_1) & 127;
  int stage_v_28_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001710_8_2) & 127;
  if (stage_v_28_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((pub_r001710_7_1 * 2) + 8) & 63;
  int stage_v_29_2 = ((pub_r001710_7_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001710_8_1) & 127;
  int stage_v_30_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001710_8_2) & 127;
  if (stage_v_30_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001710_5_1) & 127;
  int stage_v_31_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001710_5_2) & 127;
  if (stage_v_31_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (((sec_r001710_3_1 ^ 0x2A) * 2) + pub_r001710_10_1) & 127;
  int stage_v_32_2 = (((sec_r001710_3_2 ^ 0x2A) * 2) + pub_r001710_10_2) & 127;
  if (stage_v_32_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001710_14_1) & 127;
  int stage_v_33_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001710_14_2) & 127;
  if (stage_v_33_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = ((pub_r001710_12_1 * 2) + 20) & 63;
  int stage_v_34_2 = ((pub_r001710_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001710_6_1) & 127;
  int stage_v_35_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001710_6_2) & 127;
  if (stage_v_35_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (((sec_r001710_15_1 ^ 0x2A) * 2) + pub_r001710_5_1) & 127;
  int stage_v_36_2 = (((sec_r001710_15_2 ^ 0x2A) * 2) + pub_r001710_5_2) & 127;
  if (stage_v_36_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((pub_r001710_7_1 * 2) + 20) & 63;
  int stage_v_37_2 = ((pub_r001710_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001710_13_1) & 127;
  int stage_v_38_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001710_13_2) & 127;
  if (stage_v_38_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (((sec_r001710_11_1 ^ 0x2A) * 2) + pub_r001710_14_1) & 127;
  int stage_v_39_2 = (((sec_r001710_11_2 ^ 0x2A) * 2) + pub_r001710_14_2) & 127;
  if (stage_v_39_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001710_0_1) & 127;
  int stage_v_40_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001710_0_2) & 127;
  if (stage_v_40_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (((sec_r001710_2_1 ^ 0x2A) * 2) + pub_r001710_8_1) & 127;
  int stage_v_41_2 = (((sec_r001710_2_2 ^ 0x2A) * 2) + pub_r001710_8_2) & 127;
  if (stage_v_41_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001710_0_1) & 127;
  int stage_v_42_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001710_0_2) & 127;
  if (stage_v_42_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001710_5_1) & 127;
  int stage_v_43_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001710_5_2) & 127;
  if (stage_v_43_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((pub_r001710_5_1 * 2) + 41) & 63;
  int stage_v_44_2 = ((pub_r001710_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001710_3_1 * 2) + 26) & 63;
  int stage_v_45_2 = ((pub_r001710_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001710_5_1) & 127;
  int stage_v_46_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001710_5_2) & 127;
  if (stage_v_46_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001710_5_1) & 127;
  int stage_v_47_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001710_5_2) & 127;
  if (stage_v_47_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((pub_r001710_8_1 * 2) + 50) & 63;
  int stage_v_48_2 = ((pub_r001710_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001710_4_1) & 127;
  int stage_v_49_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001710_4_2) & 127;
  if (stage_v_49_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001710_1_1) & 127;
  int stage_v_50_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001710_1_2) & 127;
  if (stage_v_50_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001710_12_1) & 127;
  int stage_v_51_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001710_12_2) & 127;
  if (stage_v_51_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((pub_r001710_13_1 * 2) + 8) & 63;
  int stage_v_52_2 = ((pub_r001710_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (((sec_r001710_15_1 ^ 0x2A) * 2) + pub_r001710_11_1) & 127;
  int stage_v_53_2 = (((sec_r001710_15_2 ^ 0x2A) * 2) + pub_r001710_11_2) & 127;
  if (stage_v_53_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001710_14_1) & 127;
  int stage_v_54_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001710_14_2) & 127;
  if (stage_v_54_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001710_2_1) & 127;
  int stage_v_55_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001710_2_2) & 127;
  if (stage_v_55_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001710_11_1) & 127;
  int stage_v_56_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001710_11_2) & 127;
  if (stage_v_56_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001710_14_1) & 127;
  int stage_v_57_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001710_14_2) & 127;
  if (stage_v_57_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((pub_r001710_2_1 * 2) + 24) & 63;
  int stage_v_58_2 = ((pub_r001710_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001710_7_1) & 127;
  int stage_v_59_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001710_7_2) & 127;
  if (stage_v_59_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001710_14_1) & 127;
  int stage_v_60_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001710_14_2) & 127;
  if (stage_v_60_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (((sec_r001710_2_1 ^ 0x2A) * 2) + pub_r001710_9_1) & 127;
  int stage_v_61_2 = (((sec_r001710_2_2 ^ 0x2A) * 2) + pub_r001710_9_2) & 127;
  if (stage_v_61_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001710_9_1) & 127;
  int stage_v_62_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001710_9_2) & 127;
  if (stage_v_62_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = (((sec_r001710_6_1 ^ 0x2A) * 2) + pub_r001710_14_1) & 127;
  int stage_v_63_2 = (((sec_r001710_6_2 ^ 0x2A) * 2) + pub_r001710_14_2) & 127;
  if (stage_v_63_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001710_15_1) & 127;
  int stage_v_64_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001710_15_2) & 127;
  if (stage_v_64_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((pub_r001710_9_1 * 2) + 12) & 63;
  int stage_v_65_2 = ((pub_r001710_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001710_11_1) & 127;
  int stage_v_66_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001710_11_2) & 127;
  if (stage_v_66_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001710_8_1) & 127;
  int stage_v_67_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001710_8_2) & 127;
  if (stage_v_67_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (((sec_r001710_6_1 ^ 0x2A) * 2) + pub_r001710_5_1) & 127;
  int stage_v_68_2 = (((sec_r001710_6_2 ^ 0x2A) * 2) + pub_r001710_5_2) & 127;
  if (stage_v_68_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001710_6_1) & 127;
  int stage_v_69_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001710_6_2) & 127;
  if (stage_v_69_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001710_7_1) & 127;
  int stage_v_70_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001710_7_2) & 127;
  if (stage_v_70_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (((stage_v_67_1 ^ 0x2A) * 2) + pub_r001710_5_1) & 127;
  int stage_v_71_2 = (((stage_v_67_2 ^ 0x2A) * 2) + pub_r001710_5_2) & 127;
  if (stage_v_71_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((pub_r001710_10_1 * 2) + 43) & 63;
  int stage_v_72_2 = ((pub_r001710_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001710_7_1 * 2) + 24) & 63;
  int stage_v_73_2 = ((pub_r001710_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001710_5_1) & 127;
  int stage_v_74_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001710_5_2) & 127;
  if (stage_v_74_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((pub_r001710_13_1 * 2) + 27) & 63;
  int stage_v_75_2 = ((pub_r001710_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001710_12_1 * 2) + 11) & 63;
  int stage_v_76_2 = ((pub_r001710_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((stage_v_33_1 ^ 0x2A) * 2) + pub_r001710_1_1) & 127;
  int stage_v_77_2 = (((stage_v_33_2 ^ 0x2A) * 2) + pub_r001710_1_2) & 127;
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
  int stage_v_78_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001710_2_1) & 127;
  int stage_v_78_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001710_2_2) & 127;
  if (stage_v_78_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001710_0_1) & 127;
  int stage_v_79_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001710_0_2) & 127;
  if (stage_v_79_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001710_1_1) & 127;
  int stage_v_80_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001710_1_2) & 127;
  if (stage_v_80_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001710_16_1) & 127;
  int stage_v_81_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001710_16_2) & 127;
  if (stage_v_81_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((pub_r001710_5_1 * 2) + 16) & 63;
  int stage_v_82_2 = ((pub_r001710_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001710_3_1 * 2) + 14) & 63;
  int stage_v_83_2 = ((pub_r001710_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001710_0_1) & 127;
  int stage_v_84_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001710_0_2) & 127;
  if (stage_v_84_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001710_6_1) & 127;
  int stage_v_85_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001710_6_2) & 127;
  if (stage_v_85_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001710_5_1) & 127;
  int stage_v_86_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001710_5_2) & 127;
  if (stage_v_86_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001710_2_1) & 127;
  int stage_v_87_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001710_2_2) & 127;
  if (stage_v_87_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((pub_r001710_16_1 * 2) + 24) & 63;
  int stage_v_88_2 = ((pub_r001710_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001710_10_1) & 127;
  int stage_v_89_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001710_10_2) & 127;
  if (stage_v_89_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001710_4_1) & 127;
  int stage_v_90_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001710_4_2) & 127;
  if (stage_v_90_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (((sec_r001710_3_1 ^ 0x2A) * 2) + pub_r001710_15_1) & 127;
  int stage_v_91_2 = (((sec_r001710_3_2 ^ 0x2A) * 2) + pub_r001710_15_2) & 127;
  if (stage_v_91_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001710_8_1) & 127;
  int stage_v_92_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001710_8_2) & 127;
  if (stage_v_92_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((pub_r001710_13_1 * 2) + 30) & 63;
  int stage_v_93_2 = ((pub_r001710_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001710_9_1) & 127;
  int stage_v_94_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001710_9_2) & 127;
  if (stage_v_94_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001710_1_1) & 127;
  int stage_v_95_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001710_1_2) & 127;
  if (stage_v_95_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001710_2_1) & 127;
  int stage_v_96_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001710_2_2) & 127;
  if (stage_v_96_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (((sec_r001710_13_1 ^ 0x2A) * 2) + pub_r001710_13_1) & 127;
  int stage_v_97_2 = (((sec_r001710_13_2 ^ 0x2A) * 2) + pub_r001710_13_2) & 127;
  if (stage_v_97_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((pub_r001710_2_1 * 2) + 50) & 63;
  int stage_v_98_2 = ((pub_r001710_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001710_0_1) & 127;
  int stage_v_99_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001710_0_2) & 127;
  if (stage_v_99_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((pub_r001710_14_1 * 2) + 10) & 63;
  int stage_v_100_2 = ((pub_r001710_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001710_15_1) & 127;
  int stage_v_101_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001710_15_2) & 127;
  if (stage_v_101_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = (((stage_v_81_1 ^ 0x2A) * 2) + pub_r001710_14_1) & 127;
  int stage_v_102_2 = (((stage_v_81_2 ^ 0x2A) * 2) + pub_r001710_14_2) & 127;
  if (stage_v_102_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001710_2_1) & 127;
  int stage_v_103_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001710_2_2) & 127;
  if (stage_v_103_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001710_0_1) & 127;
  int stage_v_104_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001710_0_2) & 127;
  if (stage_v_104_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = (((stage_v_38_1 ^ 0x2A) * 2) + pub_r001710_8_1) & 127;
  int stage_v_105_2 = (((stage_v_38_2 ^ 0x2A) * 2) + pub_r001710_8_2) & 127;
  if (stage_v_105_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001710_2_1) & 127;
  int stage_v_106_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001710_2_2) & 127;
  if (stage_v_106_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001710_10_1) & 127;
  int stage_v_107_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001710_10_2) & 127;
  if (stage_v_107_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (((stage_v_68_1 ^ 0x2A) * 2) + pub_r001710_5_1) & 127;
  int stage_v_108_2 = (((stage_v_68_2 ^ 0x2A) * 2) + pub_r001710_5_2) & 127;
  if (stage_v_108_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((pub_r001710_13_1 * 2) + 5) & 63;
  int stage_v_109_2 = ((pub_r001710_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001710_9_1) & 127;
  int stage_v_110_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001710_9_2) & 127;
  if (stage_v_110_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001710_5_1) & 127;
  int stage_v_111_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001710_5_2) & 127;
  if (stage_v_111_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = (((sec_r001710_11_1 ^ 0x2A) * 2) + pub_r001710_5_1) & 127;
  int stage_v_112_2 = (((sec_r001710_11_2 ^ 0x2A) * 2) + pub_r001710_5_2) & 127;
  if (stage_v_112_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (((sec_r001710_1_1 ^ 0x2A) * 2) + pub_r001710_7_1) & 127;
  int stage_v_113_2 = (((sec_r001710_1_2 ^ 0x2A) * 2) + pub_r001710_7_2) & 127;
  if (stage_v_113_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001710_12_1) & 127;
  int stage_v_114_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001710_12_2) & 127;
  if (stage_v_114_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((pub_r001710_16_1 * 2) + 32) & 63;
  int stage_v_115_2 = ((pub_r001710_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001710_14_1) & 127;
  int stage_v_116_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001710_14_2) & 127;
  if (stage_v_116_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001710_16_1) & 127;
  int stage_v_117_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001710_16_2) & 127;
  if (stage_v_117_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001710_15_1) & 127;
  int stage_v_118_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001710_15_2) & 127;
  if (stage_v_118_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001710_7_1) & 127;
  int stage_v_119_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001710_7_2) & 127;
  if (stage_v_119_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (((sec_r001710_17_1 ^ 0x2A) * 2) + pub_r001710_10_1) & 127;
  int stage_v_120_2 = (((sec_r001710_17_2 ^ 0x2A) * 2) + pub_r001710_10_2) & 127;
  if (stage_v_120_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((pub_r001710_14_1 * 2) + 44) & 63;
  int stage_v_121_2 = ((pub_r001710_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001710_3_1) & 127;
  int stage_v_122_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001710_3_2) & 127;
  if (stage_v_122_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((stage_v_79_1 ^ 0x2A) * 2) + pub_r001710_4_1) & 127;
  int stage_v_123_2 = (((stage_v_79_2 ^ 0x2A) * 2) + pub_r001710_4_2) & 127;
  if (stage_v_123_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001710_10_1) & 127;
  int stage_v_124_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001710_10_2) & 127;
  if (stage_v_124_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((pub_r001710_14_1 * 2) + 49) & 63;
  int stage_v_125_2 = ((pub_r001710_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001710_15_1 * 2) + 50) & 63;
  int stage_v_126_2 = ((pub_r001710_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = (((stage_v_116_1 ^ 0x2A) * 2) + pub_r001710_11_1) & 127;
  int stage_v_127_2 = (((stage_v_116_2 ^ 0x2A) * 2) + pub_r001710_11_2) & 127;
  if (stage_v_127_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((stage_v_101_1 ^ 0x2A) * 2) + pub_r001710_7_1) & 127;
  int stage_v_128_2 = (((stage_v_101_2 ^ 0x2A) * 2) + pub_r001710_7_2) & 127;
  if (stage_v_128_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((pub_r001710_1_1 * 2) + 8) & 63;
  int stage_v_129_2 = ((pub_r001710_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001710_2_1) & 127;
  int stage_v_130_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001710_2_2) & 127;
  if (stage_v_130_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001710_6_1) & 127;
  int stage_v_131_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001710_6_2) & 127;
  if (stage_v_131_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001710_15_1) & 127;
  int stage_v_132_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001710_15_2) & 127;
  if (stage_v_132_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (((sec_r001710_16_1 ^ 0x2A) * 2) + pub_r001710_14_1) & 127;
  int stage_v_133_2 = (((sec_r001710_16_2 ^ 0x2A) * 2) + pub_r001710_14_2) & 127;
  if (stage_v_133_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001710_11_1) & 127;
  int stage_v_134_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001710_11_2) & 127;
  if (stage_v_134_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = (((stage_v_131_1 ^ 0x2A) * 2) + pub_r001710_13_1) & 127;
  int stage_v_135_2 = (((stage_v_131_2 ^ 0x2A) * 2) + pub_r001710_13_2) & 127;
  if (stage_v_135_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001710_1_1) & 127;
  int stage_v_136_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001710_1_2) & 127;
  if (stage_v_136_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((pub_r001710_1_1 * 2) + 14) & 63;
  int stage_v_137_2 = ((pub_r001710_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001710_4_1 * 2) + 50) & 63;
  int stage_v_138_2 = ((pub_r001710_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = (((sec_r001710_6_1 ^ 0x2A) * 2) + pub_r001710_3_1) & 127;
  int stage_v_139_2 = (((sec_r001710_6_2 ^ 0x2A) * 2) + pub_r001710_3_2) & 127;
  if (stage_v_139_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((sec_r001710_0_1 ^ 0x2A) * 2) + pub_r001710_11_1) & 127;
  int stage_v_140_2 = (((sec_r001710_0_2 ^ 0x2A) * 2) + pub_r001710_11_2) & 127;
  if (stage_v_140_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((pub_r001710_12_1 * 2) + 28) & 63;
  int stage_v_141_2 = ((pub_r001710_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (((sec_r001710_12_1 ^ 0x2A) * 2) + pub_r001710_12_1) & 127;
  int stage_v_142_2 = (((sec_r001710_12_2 ^ 0x2A) * 2) + pub_r001710_12_2) & 127;
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
  int stage_v_143_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001710_16_1) & 127;
  int stage_v_143_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001710_16_2) & 127;
  if (stage_v_143_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001710_9_1) & 127;
  int stage_v_144_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001710_9_2) & 127;
  if (stage_v_144_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (((stage_v_127_1 ^ 0x2A) * 2) + pub_r001710_15_1) & 127;
  int stage_v_145_2 = (((stage_v_127_2 ^ 0x2A) * 2) + pub_r001710_15_2) & 127;
  if (stage_v_145_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((pub_r001710_0_1 * 2) + 33) & 63;
  int stage_v_146_2 = ((pub_r001710_0_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001710_13_1) & 127;
  int stage_v_147_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001710_13_2) & 127;
  if (stage_v_147_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = (((stage_v_130_1 ^ 0x2A) * 2) + pub_r001710_16_1) & 127;
  int stage_v_148_2 = (((stage_v_130_2 ^ 0x2A) * 2) + pub_r001710_16_2) & 127;
  if (stage_v_148_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = (((stage_v_106_1 ^ 0x2A) * 2) + pub_r001710_15_1) & 127;
  int stage_v_149_2 = (((stage_v_106_2 ^ 0x2A) * 2) + pub_r001710_15_2) & 127;
  if (stage_v_149_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (((stage_v_117_1 ^ 0x2A) * 2) + pub_r001710_7_1) & 127;
  int stage_v_150_2 = (((stage_v_117_2 ^ 0x2A) * 2) + pub_r001710_7_2) & 127;
  if (stage_v_150_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((pub_r001710_7_1 * 2) + 22) & 63;
  int stage_v_151_2 = ((pub_r001710_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001710_13_1) & 127;
  int stage_v_152_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001710_13_2) & 127;
  if (stage_v_152_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((pub_r001710_11_1 * 2) + 23) & 63;
  int stage_v_153_2 = ((pub_r001710_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001710_4_1 * 2) + 16) & 63;
  int stage_v_154_2 = ((pub_r001710_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001710_4_1) & 127;
  int stage_v_155_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001710_4_2) & 127;
  if (stage_v_155_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001710_1_1) & 127;
  int stage_v_156_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001710_1_2) & 127;
  if (stage_v_156_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001710_14_1) & 127;
  int stage_v_157_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001710_14_2) & 127;
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
  int stage_v_158_1 = (((sec_r001710_8_1 ^ 0x2A) * 2) + pub_r001710_1_1) & 127;
  int stage_v_158_2 = (((sec_r001710_8_2 ^ 0x2A) * 2) + pub_r001710_1_2) & 127;
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
  int stage_v_159_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001710_15_1) & 127;
  int stage_v_159_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001710_15_2) & 127;
  if (stage_v_159_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = (((sec_r001710_15_1 ^ 0x2A) * 2) + pub_r001710_5_1) & 127;
  int stage_v_160_2 = (((sec_r001710_15_2 ^ 0x2A) * 2) + pub_r001710_5_2) & 127;
  if (stage_v_160_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((pub_r001710_10_1 * 2) + 9) & 63;
  int stage_v_161_2 = ((pub_r001710_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (((stage_v_127_1 ^ 0x2A) * 2) + pub_r001710_11_1) & 127;
  int stage_v_162_2 = (((stage_v_127_2 ^ 0x2A) * 2) + pub_r001710_11_2) & 127;
  if (stage_v_162_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (((stage_v_80_1 ^ 0x2A) * 2) + pub_r001710_4_1) & 127;
  int stage_v_163_2 = (((stage_v_80_2 ^ 0x2A) * 2) + pub_r001710_4_2) & 127;
  if (stage_v_163_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((pub_r001710_11_1 * 2) + 26) & 63;
  int stage_v_164_2 = ((pub_r001710_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (((helper_flow_12_1 ^ 0x2A) * 2) + pub_r001710_8_1) & 127;
  int stage_v_165_2 = (((helper_flow_12_2 ^ 0x2A) * 2) + pub_r001710_8_2) & 127;
  if (stage_v_165_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001710_16_1) & 127;
  int stage_v_166_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001710_16_2) & 127;
  if (stage_v_166_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001710_5_1) & 127;
  int stage_v_167_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001710_5_2) & 127;
  if (stage_v_167_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((pub_r001710_3_1 * 2) + 16) & 63;
  int stage_v_168_2 = ((pub_r001710_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001710_12_1 * 2) + 13) & 63;
  int stage_v_169_2 = ((pub_r001710_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001710_9_1) & 127;
  int stage_v_170_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001710_9_2) & 127;
  if (stage_v_170_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (((sec_r001710_6_1 ^ 0x2A) * 2) + pub_r001710_8_1) & 127;
  int stage_v_171_2 = (((sec_r001710_6_2 ^ 0x2A) * 2) + pub_r001710_8_2) & 127;
  if (stage_v_171_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((pub_r001710_12_1 * 2) + 47) & 63;
  int stage_v_172_2 = ((pub_r001710_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (((stage_v_107_1 ^ 0x2A) * 2) + pub_r001710_4_1) & 127;
  int stage_v_173_2 = (((stage_v_107_2 ^ 0x2A) * 2) + pub_r001710_4_2) & 127;
  if (stage_v_173_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = (((stage_v_77_1 ^ 0x2A) * 2) + pub_r001710_16_1) & 127;
  int stage_v_174_2 = (((stage_v_77_2 ^ 0x2A) * 2) + pub_r001710_16_2) & 127;
  if (stage_v_174_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = (((stage_v_112_1 ^ 0x2A) * 2) + pub_r001710_1_1) & 127;
  int stage_v_175_2 = (((stage_v_112_2 ^ 0x2A) * 2) + pub_r001710_1_2) & 127;
  if (stage_v_175_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001710_7_1) & 127;
  int stage_v_176_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001710_7_2) & 127;
  if (stage_v_176_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001710_3_1) & 127;
  int stage_v_177_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001710_3_2) & 127;
  if (stage_v_177_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (((stage_v_42_1 ^ 0x2A) * 2) + pub_r001710_15_1) & 127;
  int stage_v_178_2 = (((stage_v_42_2 ^ 0x2A) * 2) + pub_r001710_15_2) & 127;
  if (stage_v_178_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001710_3_1) & 127;
  int stage_v_179_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001710_3_2) & 127;
  if (stage_v_179_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((pub_r001710_15_1 * 2) + 12) & 63;
  int stage_v_180_2 = ((pub_r001710_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (((stage_v_148_1 ^ 0x2A) * 2) + pub_r001710_16_1) & 127;
  int stage_v_181_2 = (((stage_v_148_2 ^ 0x2A) * 2) + pub_r001710_16_2) & 127;
  if (stage_v_181_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = (((stage_v_140_1 ^ 0x2A) * 2) + pub_r001710_6_1) & 127;
  int stage_v_182_2 = (((stage_v_140_2 ^ 0x2A) * 2) + pub_r001710_6_2) & 127;
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
  int stage_v_183_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001710_13_1) & 127;
  int stage_v_183_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001710_13_2) & 127;
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
  int stage_v_184_1 = ((pub_r001710_7_1 * 2) + 16) & 63;
  int stage_v_184_2 = ((pub_r001710_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((stage_v_123_1 ^ 0x2A) * 2) + pub_r001710_8_1) & 127;
  int stage_v_185_2 = (((stage_v_123_2 ^ 0x2A) * 2) + pub_r001710_8_2) & 127;
  if (stage_v_185_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = (((stage_v_128_1 ^ 0x2A) * 2) + pub_r001710_13_1) & 127;
  int stage_v_186_2 = (((stage_v_128_2 ^ 0x2A) * 2) + pub_r001710_13_2) & 127;
  if (stage_v_186_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = (((stage_v_63_1 ^ 0x2A) * 2) + pub_r001710_1_1) & 127;
  int stage_v_187_2 = (((stage_v_63_2 ^ 0x2A) * 2) + pub_r001710_1_2) & 127;
  if (stage_v_187_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((pub_r001710_13_1 * 2) + 41) & 63;
  int stage_v_188_2 = ((pub_r001710_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001710_5_1) & 127;
  int stage_v_189_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001710_5_2) & 127;
  if (stage_v_189_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((stage_v_185_1 ^ 0x2A) * 2) + pub_r001710_13_1) & 127;
  int stage_v_190_2 = (((stage_v_185_2 ^ 0x2A) * 2) + pub_r001710_13_2) & 127;
  if (stage_v_190_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = (((stage_v_86_1 ^ 0x2A) * 2) + pub_r001710_4_1) & 127;
  int stage_v_191_2 = (((stage_v_86_2 ^ 0x2A) * 2) + pub_r001710_4_2) & 127;
  if (stage_v_191_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001710_11_1) & 127;
  int stage_v_192_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001710_11_2) & 127;
  if (stage_v_192_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((pub_r001710_12_1 * 2) + 26) & 63;
  int stage_v_193_2 = ((pub_r001710_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = (((stage_v_86_1 ^ 0x2A) * 2) + pub_r001710_3_1) & 127;
  int stage_v_194_2 = (((stage_v_86_2 ^ 0x2A) * 2) + pub_r001710_3_2) & 127;
  if (stage_v_194_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((pub_r001710_5_1 * 2) + 39) & 63;
  int stage_v_195_2 = ((pub_r001710_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((stage_v_179_1 ^ 0x2A) * 2) + pub_r001710_11_1) & 127;
  int stage_v_196_2 = (((stage_v_179_2 ^ 0x2A) * 2) + pub_r001710_11_2) & 127;
  if (stage_v_196_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = (((stage_v_139_1 ^ 0x2A) * 2) + pub_r001710_12_1) & 127;
  int stage_v_197_2 = (((stage_v_139_2 ^ 0x2A) * 2) + pub_r001710_12_2) & 127;
  if (stage_v_197_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = (((stage_v_119_1 ^ 0x2A) * 2) + pub_r001710_16_1) & 127;
  int stage_v_198_2 = (((stage_v_119_2 ^ 0x2A) * 2) + pub_r001710_16_2) & 127;
  if (stage_v_198_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((pub_r001710_2_1 * 2) + 37) & 63;
  int stage_v_199_2 = ((pub_r001710_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = (((stage_v_111_1 ^ 0x2A) * 2) + pub_r001710_9_1) & 127;
  int stage_v_200_2 = (((stage_v_111_2 ^ 0x2A) * 2) + pub_r001710_9_2) & 127;
  if (stage_v_200_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001710_7_1) & 127;
  int stage_v_201_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001710_7_2) & 127;
  if (stage_v_201_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((pub_r001710_4_1 * 2) + 16) & 63;
  int stage_v_202_2 = ((pub_r001710_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001710_2_1) & 127;
  int stage_v_203_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001710_2_2) & 127;
  if (stage_v_203_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001710_14_1) & 127;
  int stage_v_204_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001710_14_2) & 127;
  if (stage_v_204_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = (((stage_v_163_1 ^ 0x2A) * 2) + pub_r001710_6_1) & 127;
  int stage_v_205_2 = (((stage_v_163_2 ^ 0x2A) * 2) + pub_r001710_6_2) & 127;
  if (stage_v_205_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((pub_r001710_15_1 * 2) + 24) & 63;
  int stage_v_206_2 = ((pub_r001710_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001710_0_1 * 2) + 48) & 63;
  int stage_v_207_2 = ((pub_r001710_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001710_9_1 * 2) + 5) & 63;
  int stage_v_208_2 = ((pub_r001710_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001710_0_1 * 2) + 25) & 63;
  int stage_v_209_2 = ((pub_r001710_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = (((stage_v_112_1 ^ 0x2A) * 2) + pub_r001710_2_1) & 127;
  int stage_v_210_2 = (((stage_v_112_2 ^ 0x2A) * 2) + pub_r001710_2_2) & 127;
  if (stage_v_210_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
  }
  if (stage_v_210_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = (((sec_r001710_10_1 ^ 0x2A) * 2) + pub_r001710_4_1) & 127;
  int stage_v_211_2 = (((sec_r001710_10_2 ^ 0x2A) * 2) + pub_r001710_4_2) & 127;
  if (stage_v_211_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = (((stage_v_182_1 ^ 0x2A) * 2) + pub_r001710_6_1) & 127;
  int stage_v_212_2 = (((stage_v_182_2 ^ 0x2A) * 2) + pub_r001710_6_2) & 127;
  if (stage_v_212_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
  }
  if (stage_v_212_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001710_8_1) & 127;
  int stage_v_213_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001710_8_2) & 127;
  if (stage_v_213_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((pub_r001710_13_1 * 2) + 50) & 63;
  int stage_v_214_2 = ((pub_r001710_13_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001710_13_1 * 2) + 50) & 63;
  int stage_v_215_2 = ((pub_r001710_13_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001710_13_1 * 2) + 17) & 63;
  int stage_v_216_2 = ((pub_r001710_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((stage_v_212_1 ^ 0x2A) * 2) + pub_r001710_15_1) & 127;
  int stage_v_217_2 = (((stage_v_212_2 ^ 0x2A) * 2) + pub_r001710_15_2) & 127;
  if (stage_v_217_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (((sec_r001710_17_1 ^ 0x2A) * 2) + pub_r001710_4_1) & 127;
  int stage_v_218_2 = (((sec_r001710_17_2 ^ 0x2A) * 2) + pub_r001710_4_2) & 127;
  if (stage_v_218_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = (((stage_v_187_1 ^ 0x2A) * 2) + pub_r001710_15_1) & 127;
  int stage_v_219_2 = (((stage_v_187_2 ^ 0x2A) * 2) + pub_r001710_15_2) & 127;
  if (stage_v_219_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = (((stage_v_182_1 ^ 0x2A) * 2) + pub_r001710_12_1) & 127;
  int stage_v_220_2 = (((stage_v_182_2 ^ 0x2A) * 2) + pub_r001710_12_2) & 127;
  if (stage_v_220_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
  }
  if (stage_v_220_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = (((stage_v_173_1 ^ 0x2A) * 2) + pub_r001710_11_1) & 127;
  int stage_v_221_2 = (((stage_v_173_2 ^ 0x2A) * 2) + pub_r001710_11_2) & 127;
  if (stage_v_221_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((pub_r001710_11_1 * 2) + 22) & 63;
  int stage_v_222_2 = ((pub_r001710_11_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = (((stage_v_77_1 ^ 0x2A) * 2) + pub_r001710_2_1) & 127;
  int stage_v_223_2 = (((stage_v_77_2 ^ 0x2A) * 2) + pub_r001710_2_2) & 127;
  if (stage_v_223_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((pub_r001710_4_1 * 2) + 11) & 63;
  int stage_v_224_2 = ((pub_r001710_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001710_15_1 * 2) + 43) & 63;
  int stage_v_225_2 = ((pub_r001710_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001710_3_1 * 2) + 5) & 63;
  int stage_v_226_2 = ((pub_r001710_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = (((stage_v_105_1 ^ 0x2A) * 2) + pub_r001710_10_1) & 127;
  int stage_v_227_2 = (((stage_v_105_2 ^ 0x2A) * 2) + pub_r001710_10_2) & 127;
  if (stage_v_227_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
  }
  if (stage_v_227_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = (((stage_v_127_1 ^ 0x2A) * 2) + pub_r001710_2_1) & 127;
  int stage_v_228_2 = (((stage_v_127_2 ^ 0x2A) * 2) + pub_r001710_2_2) & 127;
  if (stage_v_228_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
  }
  if (stage_v_228_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = (((stage_v_205_1 ^ 0x2A) * 2) + pub_r001710_4_1) & 127;
  int stage_v_229_2 = (((stage_v_205_2 ^ 0x2A) * 2) + pub_r001710_4_2) & 127;
  if (stage_v_229_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
  }
  if (stage_v_229_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = (((stage_v_220_1 ^ 0x2A) * 2) + pub_r001710_14_1) & 127;
  int stage_v_230_2 = (((stage_v_220_2 ^ 0x2A) * 2) + pub_r001710_14_2) & 127;
  if (stage_v_230_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
  }
  if (stage_v_230_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001710_5_1) & 127;
  int stage_v_231_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001710_5_2) & 127;
  if (stage_v_231_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
  }
  if (stage_v_231_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = (((sec_r001710_12_1 ^ 0x2A) * 2) + pub_r001710_11_1) & 127;
  int stage_v_232_2 = (((sec_r001710_12_2 ^ 0x2A) * 2) + pub_r001710_11_2) & 127;
  if (stage_v_232_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
  }
  if (stage_v_232_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001710_1_1) & 127;
  int stage_v_233_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001710_1_2) & 127;
  if (stage_v_233_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
  }
  if (stage_v_233_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((pub_r001710_16_1 * 2) + 24) & 63;
  int stage_v_234_2 = ((pub_r001710_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001710_0_1) & 127;
  int stage_v_235_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001710_0_2) & 127;
  if (stage_v_235_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
  }
  if (stage_v_235_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001710_17_1 != sec_r001710_17_2);
  __CPROVER_assume(pub_r001710_10_1 == pub_r001710_10_2);
  __CPROVER_assume(sec_r001710_12_1 != sec_r001710_12_2);
  __CPROVER_assume(sec_r001710_2_1 != sec_r001710_2_2);
  __CPROVER_assume(pub_r001710_5_1 == pub_r001710_5_2);
  __CPROVER_assume(sec_r001710_4_1 != sec_r001710_4_2);
  __CPROVER_assume(sec_r001710_0_1 != sec_r001710_0_2);
  __CPROVER_assume(sec_r001710_9_1 != sec_r001710_9_2);
  __CPROVER_assume(sec_r001710_6_1 != sec_r001710_6_2);
  __CPROVER_assume(pub_r001710_2_1 == pub_r001710_2_2);
  __CPROVER_assume(pub_r001710_16_1 == pub_r001710_16_2);
  __CPROVER_assume(pub_r001710_8_1 == pub_r001710_8_2);
  __CPROVER_assume(sec_r001710_16_1 != sec_r001710_16_2);
  __CPROVER_assume(sec_r001710_10_1 != sec_r001710_10_2);
  __CPROVER_assume(sec_r001710_14_1 != sec_r001710_14_2);
  __CPROVER_assume(pub_r001710_14_1 == pub_r001710_14_2);
  __CPROVER_assume(pub_r001710_6_1 == pub_r001710_6_2);
  __CPROVER_assume(pub_r001710_13_1 == pub_r001710_13_2);
  __CPROVER_assume(pub_r001710_9_1 == pub_r001710_9_2);
  __CPROVER_assume(pub_r001710_15_1 == pub_r001710_15_2);
  __CPROVER_assume(sec_r001710_7_1 != sec_r001710_7_2);
  __CPROVER_assume(sec_r001710_15_1 != sec_r001710_15_2);
  __CPROVER_assume(sec_r001710_5_1 != sec_r001710_5_2);
  __CPROVER_assume(pub_r001710_12_1 == pub_r001710_12_2);
  __CPROVER_assume(pub_r001710_1_1 == pub_r001710_1_2);
  __CPROVER_assume(sec_r001710_8_1 != sec_r001710_8_2);
  __CPROVER_assume(pub_r001710_4_1 == pub_r001710_4_2);
  __CPROVER_assume(sec_r001710_11_1 != sec_r001710_11_2);
  __CPROVER_assume(pub_r001710_3_1 == pub_r001710_3_2);
  __CPROVER_assume(sec_r001710_1_1 != sec_r001710_1_2);
  __CPROVER_assume(pub_r001710_11_1 == pub_r001710_11_2);
  __CPROVER_assume(sec_r001710_3_1 != sec_r001710_3_2);
  __CPROVER_assume(pub_r001710_0_1 == pub_r001710_0_2);
  __CPROVER_assume(pub_r001710_7_1 == pub_r001710_7_2);
  __CPROVER_assume(sec_r001710_13_1 != sec_r001710_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.determinant == st_var_1_2.determinant);
  assert(st_var_1_1.trace == st_var_1_2.trace);
  assert(st_var_1_1.stride == st_var_1_2.stride);
  assert(st_var_1_1.density == st_var_1_2.density);
  assert(st_var_1_1.dim == st_var_1_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.timestamp == st_var_2_2.timestamp);
  assert(st_var_2_1.seq == st_var_2_2.seq);
  assert(st_var_2_1.severity == st_var_2_2.severity);
  assert(st_var_2_1.signature == st_var_2_2.signature);
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
  assert(helper_flow_8_1 == helper_flow_8_2);
  assert(helper_flow_9_1 == helper_flow_9_2);
  assert(helper_flow_10_1 == helper_flow_10_2);
  assert(helper_flow_11_1 == helper_flow_11_2);
  assert(helper_flow_12_1 == helper_flow_12_2);
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
}


