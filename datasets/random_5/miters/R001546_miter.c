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
struct MatrixBlock_R001546_4613_0
{
  unsigned char determinant;
  int dim;
  short stride;
  int scale;
  int density;
  short trace;
  int buffer[3];
};
struct CipherContext_R001546_4613_1
{
  short flags;
  short nonce;
  int tag;
  int counter;
  int buffer[3];
};
struct SensorNode_R001546_4613_2
{
  int calib;
  int status;
  int offset;
  int buffer[3];
};
union TelemetryField_R001546_4613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001546_4613_1
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
void fn_R001546_4613_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st_1 = {0};
  struct CipherContext_R001546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int weight_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_84_1)
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

  switch (weight_84_2)
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

  int phase_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_33_1 > 16)
  {
    acc_1 = ((acc_1 + (phase_33_1 * 2)) + 5) & 127;
    aux_1 ^= phase_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_33_2 > 16)
  {
    acc_2 = ((acc_2 + (phase_33_2 * 2)) + 5) & 127;
    aux_2 ^= phase_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_30_1) & 63;
  aux_2 = (aux_2 + index_reg_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_84_1 == weight_84_2);
  assert(phase_33_1 == phase_33_2);
  assert(index_reg_30_1 == index_reg_30_2);
}

int fn_R001546_4613_0(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int weight_84 = (aux + st.buffer[1]) & 3;
  switch (weight_84)
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

  int phase_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_33 > 16)
  {
    acc = ((acc + (phase_33 * 2)) + 5) & 127;
    aux ^= phase_33 & 15;
  }
  else
  {
    acc = ((acc - phase_33) + 11) & 127;
    aux += 3;
  }
  int index_reg_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_30) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001546_4613_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st_1 = {0};
  struct CipherContext_R001546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int mask_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_19_1)
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

  switch (mask_19_2)
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

  int checksum_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_71_1 > 32)
  {
    acc_1 = ((acc_1 + (checksum_71_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_71_2 > 32)
  {
    acc_2 = ((acc_2 + (checksum_71_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_71_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_32_1 = local_arr_1[aux_1 % 3];
  int residue_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_19_1 == mask_19_2);
  assert(checksum_71_1 == checksum_71_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_32_1 == residue_32_2);
}

int fn_R001546_4613_1(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int mask_19 = (aux + st.buffer[1]) & 3;
  switch (mask_19)
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

  int checksum_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_71 > 32)
  {
    acc = ((acc + (checksum_71 * 2)) + 5) & 127;
    aux ^= checksum_71 & 15;
  }
  else
  {
    acc = ((acc - checksum_71) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_32 = local_arr[aux % 3];
  acc = (acc + (residue_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001546_4613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001546_4613_0 st_1 = {0};
  struct MatrixBlock_R001546_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int index_reg_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_99_1) & 63;
  aux_2 = (aux_2 + index_reg_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_26_1 > 42)
  {
    acc_1 = ((acc_1 + (metric_26_1 * 2)) + 5) & 127;
    aux_1 ^= metric_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_26_2 > 42)
  {
    acc_2 = ((acc_2 + (metric_26_2 * 2)) + 5) & 127;
    aux_2 ^= metric_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_47_1)
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

  switch (checksum_47_2)
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

  int mask_75_1 = 0;
  int mask_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_75_1 = ((mask_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_75_2 = ((mask_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_75_1) & 127;
    acc_2 = (acc_2 + mask_75_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_99_1 == index_reg_99_2);
  assert(metric_26_1 == metric_26_2);
  assert(checksum_47_1 == checksum_47_2);
  assert(mask_75_1 == mask_75_2);
}

int fn_R001546_4613_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001546_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int index_reg_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_99) & 63;
  acc ^= aux;
  int metric_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_26 > 42)
  {
    acc = ((acc + (metric_26 * 2)) + 5) & 127;
    aux ^= metric_26 & 15;
  }
  else
  {
    acc = ((acc - metric_26) + 11) & 127;
    aux += 3;
  }
  int checksum_47 = (aux + st.buffer[1]) & 3;
  switch (checksum_47)
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

  int mask_75 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_75 = ((mask_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_75) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001546_4613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st_1 = {0};
  struct CipherContext_R001546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_81_1 = local_arr_1[aux_1 % 3];
  int weight_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_81_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_87_1)
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

  switch (offset_87_2)
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

  int segment_86_1 = 0;
  int segment_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_86_1 = ((segment_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_86_2 = ((segment_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_86_1) & 127;
    acc_2 = (acc_2 + segment_86_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_81_1 == weight_81_2);
  assert(offset_87_1 == offset_87_2);
  assert(segment_86_1 == segment_86_2);
}

int fn_R001546_4613_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int weight_81 = local_arr[aux % 3];
  acc = (acc + (weight_81 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_87 = (aux + st.buffer[1]) & 3;
  switch (offset_87)
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

  int segment_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_86 = ((segment_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_86) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001546_4613_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001546_4613_2 st_1 = {0};
  struct SensorNode_R001546_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_78_1 = 0;
  int delta_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_78_1 = ((delta_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_78_2 = ((delta_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_78_1) & 127;
    acc_2 = (acc_2 + delta_78_2) & 127;
  }

  int cursor_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_42_1) & 63;
  aux_2 = (aux_2 + cursor_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_78_1 == delta_78_2);
  assert(cursor_42_1 == cursor_42_2);
}

int fn_R001546_4613_4(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001546_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_78 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_78 = ((delta_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_78) & 127;
  }

  int cursor_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_42) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001546_4613_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001546_4613_2 st_1 = {0};
  struct SensorNode_R001546_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int tracker_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_54_1 > 29)
  {
    acc_1 = ((acc_1 + (tracker_54_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_54_2 > 29)
  {
    acc_2 = ((acc_2 + (tracker_54_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_83_1) & 63;
  aux_2 = (aux_2 + weight_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_54_1 == tracker_54_2);
  assert(weight_83_1 == weight_83_2);
}

int fn_R001546_4613_5(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001546_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int tracker_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_54 > 29)
  {
    acc = ((acc + (tracker_54 * 2)) + 5) & 127;
    aux ^= tracker_54 & 15;
  }
  else
  {
    acc = ((acc - tracker_54) + 11) & 127;
    aux += 3;
  }
  int weight_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_83) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001546_4613_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st_1 = {0};
  struct CipherContext_R001546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_46_1 > 10)
  {
    acc_1 = ((acc_1 + (segment_46_1 * 2)) + 5) & 127;
    aux_1 ^= segment_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_46_2 > 10)
  {
    acc_2 = ((acc_2 + (segment_46_2 * 2)) + 5) & 127;
    aux_2 ^= segment_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_87_1) & 63;
  aux_2 = (aux_2 + quotient_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_60_1 = local_arr_1[aux_1 % 3];
  int tally_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_60_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_46_1 == segment_46_2);
  assert(quotient_87_1 == quotient_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_60_1 == tally_60_2);
}

int fn_R001546_4613_6(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_46 > 10)
  {
    acc = ((acc + (segment_46 * 2)) + 5) & 127;
    aux ^= segment_46 & 15;
  }
  else
  {
    acc = ((acc - segment_46) + 11) & 127;
    aux += 3;
  }
  int quotient_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_87) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tally_60 = local_arr[aux % 3];
  acc = (acc + (tally_60 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001546_4613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001546_4613_0 st_1 = {0};
  struct MatrixBlock_R001546_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int scale_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_31_1 > 44)
  {
    acc_1 = ((acc_1 + (scale_31_1 * 2)) + 5) & 127;
    aux_1 ^= scale_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_31_2 > 44)
  {
    acc_2 = ((acc_2 + (scale_31_2 * 2)) + 5) & 127;
    aux_2 ^= scale_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_28_1) & 63;
  aux_2 = (aux_2 + window_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_10_1 = local_arr_1[aux_1 % 3];
  int mask_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_10_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_31_1 == scale_31_2);
  assert(window_28_1 == window_28_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_10_1 == mask_10_2);
}

int fn_R001546_4613_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001546_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int scale_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_31 > 44)
  {
    acc = ((acc + (scale_31 * 2)) + 5) & 127;
    aux ^= scale_31 & 15;
  }
  else
  {
    acc = ((acc - scale_31) + 11) & 127;
    aux += 3;
  }
  int window_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_28) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_10 = local_arr[aux % 3];
  acc = (acc + (mask_10 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001546_4613_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st_1 = {0};
  struct CipherContext_R001546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int pivot_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_83_1)
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

  switch (pivot_83_2)
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

  int delta_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_47_1 > 32)
  {
    acc_1 = ((acc_1 + (delta_47_1 * 2)) + 5) & 127;
    aux_1 ^= delta_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_47_2 > 32)
  {
    acc_2 = ((acc_2 + (delta_47_2 * 2)) + 5) & 127;
    aux_2 ^= delta_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_47_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_83_1 == pivot_83_2);
  assert(delta_47_1 == delta_47_2);
}

int fn_R001546_4613_8(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int pivot_83 = (aux + st.buffer[1]) & 3;
  switch (pivot_83)
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

  int delta_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_47 > 32)
  {
    acc = ((acc + (delta_47 * 2)) + 5) & 127;
    aux ^= delta_47 & 15;
  }
  else
  {
    acc = ((acc - delta_47) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001546_4613_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001546_4613_2 st_1 = {0};
  struct SensorNode_R001546_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int sample_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_37_1)
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

  switch (sample_37_2)
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

  int checksum_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_94_1 > 40)
  {
    acc_1 = ((acc_1 + (checksum_94_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_94_2 > 40)
  {
    acc_2 = ((acc_2 + (checksum_94_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_77_1 = 0;
  int checksum_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_77_1 = ((checksum_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_77_2 = ((checksum_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_77_1) & 127;
    acc_2 = (acc_2 + checksum_77_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_37_1 == sample_37_2);
  assert(checksum_94_1 == checksum_94_2);
  assert(checksum_77_1 == checksum_77_2);
}

int fn_R001546_4613_9(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001546_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int sample_37 = (aux + st.buffer[1]) & 3;
  switch (sample_37)
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

  int checksum_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_94 > 40)
  {
    acc = ((acc + (checksum_94 * 2)) + 5) & 127;
    aux ^= checksum_94 & 15;
  }
  else
  {
    acc = ((acc - checksum_94) + 11) & 127;
    aux += 3;
  }
  int checksum_77 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_77 = ((checksum_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_77) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001546_4613_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001546_4613_0 st_1 = {0};
  struct MatrixBlock_R001546_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int scale_91_1 = 0;
  int scale_91_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_91_1 = ((scale_91_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_91_2 = ((scale_91_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_91_1) & 127;
    acc_2 = (acc_2 + scale_91_2) & 127;
  }

  int segment_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_54_1)
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

  switch (segment_54_2)
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
  int offset_21_1 = local_arr_1[aux_1 % 3];
  int offset_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_91_1 == scale_91_2);
  assert(segment_54_1 == segment_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_21_1 == offset_21_2);
}

int fn_R001546_4613_10(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001546_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int scale_91 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_91 = ((scale_91 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_91) & 127;
  }

  int segment_54 = (aux + st.buffer[1]) & 3;
  switch (segment_54)
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
  int offset_21 = local_arr[aux % 3];
  acc = (acc + (offset_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001546_4613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st_1 = {0};
  struct CipherContext_R001546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int tally_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_94_1 > 50)
  {
    acc_1 = ((acc_1 + (tally_94_1 * 2)) + 5) & 127;
    aux_1 ^= tally_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_94_2 > 50)
  {
    acc_2 = ((acc_2 + (tally_94_2 * 2)) + 5) & 127;
    aux_2 ^= tally_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_94_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_48_1)
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

  switch (weight_48_2)
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

  int accumulator_91_1 = 0;
  int accumulator_91_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_91_1 = ((accumulator_91_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_91_2 = ((accumulator_91_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_91_1) & 127;
    acc_2 = (acc_2 + accumulator_91_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_94_1 == tally_94_2);
  assert(weight_48_1 == weight_48_2);
  assert(accumulator_91_1 == accumulator_91_2);
}

int fn_R001546_4613_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int tally_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_94 > 50)
  {
    acc = ((acc + (tally_94 * 2)) + 5) & 127;
    aux ^= tally_94 & 15;
  }
  else
  {
    acc = ((acc - tally_94) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_48 = (aux + st.buffer[1]) & 3;
  switch (weight_48)
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

  int accumulator_91 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_91 = ((accumulator_91 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_91) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001546_4613_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st_1 = {0};
  struct CipherContext_R001546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int window_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_94_1 > 12)
  {
    acc_1 = ((acc_1 + (window_94_1 * 2)) + 5) & 127;
    aux_1 ^= window_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_94_2 > 12)
  {
    acc_2 = ((acc_2 + (window_94_2 * 2)) + 5) & 127;
    aux_2 ^= window_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_62_1) & 63;
  aux_2 = (aux_2 + sample_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_87_1 = 0;
  int pivot_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_87_1 = ((pivot_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_87_2 = ((pivot_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_87_1) & 127;
    acc_2 = (acc_2 + pivot_87_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_94_1 == window_94_2);
  assert(sample_62_1 == sample_62_2);
  assert(pivot_87_1 == pivot_87_2);
}

int fn_R001546_4613_12(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int window_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_94 > 12)
  {
    acc = ((acc + (window_94 * 2)) + 5) & 127;
    aux ^= window_94 & 15;
  }
  else
  {
    acc = ((acc - window_94) + 11) & 127;
    aux += 3;
  }
  int sample_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_62) & 63;
  acc ^= aux;
  int pivot_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_87 = ((pivot_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_87) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001546_4613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001546_4613_0 st_1 = {0};
  struct MatrixBlock_R001546_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_66_1 = local_arr_1[aux_1 % 3];
  int accumulator_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_66_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_66_1 == accumulator_66_2);
}

int fn_R001546_4613_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001546_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_66 = local_arr[aux % 3];
  acc = (acc + (accumulator_66 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001546_4613_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st_1 = {0};
  struct CipherContext_R001546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int sample_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_36_1) & 63;
  aux_2 = (aux_2 + sample_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_14_1 = local_arr_1[aux_1 % 3];
  int vector_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_14_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_36_1 == sample_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_14_1 == vector_14_2);
}

int fn_R001546_4613_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int sample_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_36) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int vector_14 = local_arr[aux % 3];
  acc = (acc + (vector_14 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001546_4613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st_1 = {0};
  struct CipherContext_R001546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int pivot_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_34_1 > 28)
  {
    acc_1 = ((acc_1 + (pivot_34_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_34_2 > 28)
  {
    acc_2 = ((acc_2 + (pivot_34_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_38_1)
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

  switch (segment_38_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_34_1 == pivot_34_2);
  assert(segment_38_1 == segment_38_2);
}

int fn_R001546_4613_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int pivot_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_34 > 28)
  {
    acc = ((acc + (pivot_34 * 2)) + 5) & 127;
    aux ^= pivot_34 & 15;
  }
  else
  {
    acc = ((acc - pivot_34) + 11) & 127;
    aux += 3;
  }
  int segment_38 = (aux + st.buffer[1]) & 3;
  switch (segment_38)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001546_4613_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st_1 = {0};
  struct CipherContext_R001546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_79_1 = local_arr_1[aux_1 % 3];
  int accumulator_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_79_2 * 2)) & 127;
  int cursor_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_17_1 > 10)
  {
    acc_1 = ((acc_1 + (cursor_17_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_17_2 > 10)
  {
    acc_2 = ((acc_2 + (cursor_17_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_17_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_79_1 == accumulator_79_2);
  assert(cursor_17_1 == cursor_17_2);
}

int fn_R001546_4613_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int accumulator_79 = local_arr[aux % 3];
  acc = (acc + (accumulator_79 * 2)) & 127;
  int cursor_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_17 > 10)
  {
    acc = ((acc + (cursor_17 * 2)) + 5) & 127;
    aux ^= cursor_17 & 15;
  }
  else
  {
    acc = ((acc - cursor_17) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001546_4613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st_1 = {0};
  struct CipherContext_R001546_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int delta_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_40_1 > 10)
  {
    acc_1 = ((acc_1 + (delta_40_1 * 2)) + 5) & 127;
    aux_1 ^= delta_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_40_2 > 10)
  {
    acc_2 = ((acc_2 + (delta_40_2 * 2)) + 5) & 127;
    aux_2 ^= delta_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_45_1) & 63;
  aux_2 = (aux_2 + pivot_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_50_1 = local_arr_1[aux_1 % 3];
  int accumulator_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_50_2 * 2)) & 127;
  int window_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_47_1)
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

  switch (window_47_2)
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
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_40_1 == delta_40_2);
  assert(pivot_45_1 == pivot_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_50_1 == accumulator_50_2);
  assert(window_47_1 == window_47_2);
}

int fn_R001546_4613_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001546_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int delta_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_40 > 10)
  {
    acc = ((acc + (delta_40 * 2)) + 5) & 127;
    aux ^= delta_40 & 15;
  }
  else
  {
    acc = ((acc - delta_40) + 11) & 127;
    aux += 3;
  }
  int pivot_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_45) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int accumulator_50 = local_arr[aux % 3];
  acc = (acc + (accumulator_50 * 2)) & 127;
  int window_47 = (aux + st.buffer[1]) & 3;
  switch (window_47)
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

void fn_R001546_4613_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001546_4613_2 st_1 = {0};
  struct SensorNode_R001546_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int phase_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_44_1) & 63;
  aux_2 = (aux_2 + phase_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_20_1 > 47)
  {
    acc_1 = ((acc_1 + (factor_20_1 * 2)) + 5) & 127;
    aux_1 ^= factor_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_20_2 > 47)
  {
    acc_2 = ((acc_2 + (factor_20_2 * 2)) + 5) & 127;
    aux_2 ^= factor_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_58_1 = local_arr_1[aux_1 % 3];
  int phase_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_58_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_44_1 == phase_44_2);
  assert(factor_20_1 == factor_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_58_1 == phase_58_2);
}

int fn_R001546_4613_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001546_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int phase_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_44) & 63;
  acc ^= aux;
  int factor_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_20 > 47)
  {
    acc = ((acc + (factor_20 * 2)) + 5) & 127;
    aux ^= factor_20 & 15;
  }
  else
  {
    acc = ((acc - factor_20) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int phase_58 = local_arr[aux % 3];
  acc = (acc + (phase_58 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001546_0_1;
  int sec_r001546_0_2;
  int sec_r001546_1_1;
  int sec_r001546_1_2;
  int sec_r001546_2_1;
  int sec_r001546_2_2;
  int sec_r001546_3_1;
  int sec_r001546_3_2;
  int sec_r001546_4_1;
  int sec_r001546_4_2;
  int sec_r001546_5_1;
  int sec_r001546_5_2;
  int sec_r001546_6_1;
  int sec_r001546_6_2;
  int sec_r001546_7_1;
  int sec_r001546_7_2;
  int sec_r001546_8_1;
  int sec_r001546_8_2;
  int sec_r001546_9_1;
  int sec_r001546_9_2;
  int sec_r001546_10_1;
  int sec_r001546_10_2;
  int sec_r001546_11_1;
  int sec_r001546_11_2;
  int sec_r001546_12_1;
  int sec_r001546_12_2;
  int sec_r001546_13_1;
  int sec_r001546_13_2;
  int sec_r001546_14_1;
  int sec_r001546_14_2;
  int sec_r001546_15_1;
  int sec_r001546_15_2;
  int sec_r001546_16_1;
  int sec_r001546_16_2;
  int sec_r001546_17_1;
  int sec_r001546_17_2;
  int sec_r001546_18_1;
  int sec_r001546_18_2;
  int sec_r001546_19_1;
  int sec_r001546_19_2;
  int sec_r001546_20_1;
  int sec_r001546_20_2;
  int sec_r001546_21_1;
  int sec_r001546_21_2;
  int sec_r001546_22_1;
  int sec_r001546_22_2;
  int sec_r001546_23_1;
  int sec_r001546_23_2;
  int pub_r001546_0_1;
  int pub_r001546_0_2;
  int pub_r001546_1_1;
  int pub_r001546_1_2;
  int pub_r001546_2_1;
  int pub_r001546_2_2;
  int pub_r001546_3_1;
  int pub_r001546_3_2;
  int pub_r001546_4_1;
  int pub_r001546_4_2;
  int pub_r001546_5_1;
  int pub_r001546_5_2;
  int pub_r001546_6_1;
  int pub_r001546_6_2;
  int pub_r001546_7_1;
  int pub_r001546_7_2;
  int pub_r001546_8_1;
  int pub_r001546_8_2;
  int pub_r001546_9_1;
  int pub_r001546_9_2;
  int pub_r001546_10_1;
  int pub_r001546_10_2;
  int pub_r001546_11_1;
  int pub_r001546_11_2;
  int pub_r001546_12_1;
  int pub_r001546_12_2;
  int pub_r001546_13_1;
  int pub_r001546_13_2;
  int pub_r001546_14_1;
  int pub_r001546_14_2;
  int pub_r001546_15_1;
  int pub_r001546_15_2;
  int pub_r001546_16_1;
  int pub_r001546_16_2;
  int pub_r001546_17_1;
  int pub_r001546_17_2;
  int pub_r001546_18_1;
  int pub_r001546_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001546_0_1 >= (-100)) && (pub_r001546_0_1 <= 100));
  __CPROVER_assume((pub_r001546_0_2 >= (-100)) && (pub_r001546_0_2 <= 100));
  __CPROVER_assume((pub_r001546_1_1 >= (-100)) && (pub_r001546_1_1 <= 100));
  __CPROVER_assume((pub_r001546_1_2 >= (-100)) && (pub_r001546_1_2 <= 100));
  __CPROVER_assume((pub_r001546_2_1 >= (-100)) && (pub_r001546_2_1 <= 100));
  __CPROVER_assume((pub_r001546_2_2 >= (-100)) && (pub_r001546_2_2 <= 100));
  __CPROVER_assume((pub_r001546_3_1 >= (-100)) && (pub_r001546_3_1 <= 100));
  __CPROVER_assume((pub_r001546_3_2 >= (-100)) && (pub_r001546_3_2 <= 100));
  __CPROVER_assume((pub_r001546_4_1 >= (-100)) && (pub_r001546_4_1 <= 100));
  __CPROVER_assume((pub_r001546_4_2 >= (-100)) && (pub_r001546_4_2 <= 100));
  __CPROVER_assume((pub_r001546_5_1 >= (-100)) && (pub_r001546_5_1 <= 100));
  __CPROVER_assume((pub_r001546_5_2 >= (-100)) && (pub_r001546_5_2 <= 100));
  __CPROVER_assume((pub_r001546_6_1 >= (-100)) && (pub_r001546_6_1 <= 100));
  __CPROVER_assume((pub_r001546_6_2 >= (-100)) && (pub_r001546_6_2 <= 100));
  __CPROVER_assume((pub_r001546_7_1 >= (-100)) && (pub_r001546_7_1 <= 100));
  __CPROVER_assume((pub_r001546_7_2 >= (-100)) && (pub_r001546_7_2 <= 100));
  __CPROVER_assume((pub_r001546_8_1 >= (-100)) && (pub_r001546_8_1 <= 100));
  __CPROVER_assume((pub_r001546_8_2 >= (-100)) && (pub_r001546_8_2 <= 100));
  __CPROVER_assume((pub_r001546_9_1 >= (-100)) && (pub_r001546_9_1 <= 100));
  __CPROVER_assume((pub_r001546_9_2 >= (-100)) && (pub_r001546_9_2 <= 100));
  __CPROVER_assume((pub_r001546_10_1 >= (-100)) && (pub_r001546_10_1 <= 100));
  __CPROVER_assume((pub_r001546_10_2 >= (-100)) && (pub_r001546_10_2 <= 100));
  __CPROVER_assume((pub_r001546_11_1 >= (-100)) && (pub_r001546_11_1 <= 100));
  __CPROVER_assume((pub_r001546_11_2 >= (-100)) && (pub_r001546_11_2 <= 100));
  __CPROVER_assume((pub_r001546_12_1 >= (-100)) && (pub_r001546_12_1 <= 100));
  __CPROVER_assume((pub_r001546_12_2 >= (-100)) && (pub_r001546_12_2 <= 100));
  __CPROVER_assume((pub_r001546_13_1 >= (-100)) && (pub_r001546_13_1 <= 100));
  __CPROVER_assume((pub_r001546_13_2 >= (-100)) && (pub_r001546_13_2 <= 100));
  __CPROVER_assume((pub_r001546_14_1 >= (-100)) && (pub_r001546_14_1 <= 100));
  __CPROVER_assume((pub_r001546_14_2 >= (-100)) && (pub_r001546_14_2 <= 100));
  __CPROVER_assume((pub_r001546_15_1 >= (-100)) && (pub_r001546_15_1 <= 100));
  __CPROVER_assume((pub_r001546_15_2 >= (-100)) && (pub_r001546_15_2 <= 100));
  __CPROVER_assume((pub_r001546_16_1 >= (-100)) && (pub_r001546_16_1 <= 100));
  __CPROVER_assume((pub_r001546_16_2 >= (-100)) && (pub_r001546_16_2 <= 100));
  __CPROVER_assume((pub_r001546_17_1 >= (-100)) && (pub_r001546_17_1 <= 100));
  __CPROVER_assume((pub_r001546_17_2 >= (-100)) && (pub_r001546_17_2 <= 100));
  __CPROVER_assume((pub_r001546_18_1 >= (-100)) && (pub_r001546_18_1 <= 100));
  __CPROVER_assume((pub_r001546_18_2 >= (-100)) && (pub_r001546_18_2 <= 100));
  __CPROVER_assume((sec_r001546_0_1 >= 0) && (sec_r001546_0_1 <= 255));
  __CPROVER_assume((sec_r001546_0_2 >= 0) && (sec_r001546_0_2 <= 255));
  __CPROVER_assume((sec_r001546_1_1 >= 0) && (sec_r001546_1_1 <= 255));
  __CPROVER_assume((sec_r001546_1_2 >= 0) && (sec_r001546_1_2 <= 255));
  __CPROVER_assume((sec_r001546_2_1 >= 0) && (sec_r001546_2_1 <= 255));
  __CPROVER_assume((sec_r001546_2_2 >= 0) && (sec_r001546_2_2 <= 255));
  __CPROVER_assume((sec_r001546_3_1 >= 0) && (sec_r001546_3_1 <= 255));
  __CPROVER_assume((sec_r001546_3_2 >= 0) && (sec_r001546_3_2 <= 255));
  __CPROVER_assume((sec_r001546_4_1 >= 0) && (sec_r001546_4_1 <= 255));
  __CPROVER_assume((sec_r001546_4_2 >= 0) && (sec_r001546_4_2 <= 255));
  __CPROVER_assume((sec_r001546_5_1 >= 0) && (sec_r001546_5_1 <= 255));
  __CPROVER_assume((sec_r001546_5_2 >= 0) && (sec_r001546_5_2 <= 255));
  __CPROVER_assume((sec_r001546_6_1 >= 0) && (sec_r001546_6_1 <= 255));
  __CPROVER_assume((sec_r001546_6_2 >= 0) && (sec_r001546_6_2 <= 255));
  __CPROVER_assume((sec_r001546_7_1 >= 0) && (sec_r001546_7_1 <= 255));
  __CPROVER_assume((sec_r001546_7_2 >= 0) && (sec_r001546_7_2 <= 255));
  __CPROVER_assume((sec_r001546_8_1 >= 0) && (sec_r001546_8_1 <= 255));
  __CPROVER_assume((sec_r001546_8_2 >= 0) && (sec_r001546_8_2 <= 255));
  __CPROVER_assume((sec_r001546_9_1 >= 0) && (sec_r001546_9_1 <= 255));
  __CPROVER_assume((sec_r001546_9_2 >= 0) && (sec_r001546_9_2 <= 255));
  __CPROVER_assume((sec_r001546_10_1 >= 0) && (sec_r001546_10_1 <= 255));
  __CPROVER_assume((sec_r001546_10_2 >= 0) && (sec_r001546_10_2 <= 255));
  __CPROVER_assume((sec_r001546_11_1 >= 0) && (sec_r001546_11_1 <= 255));
  __CPROVER_assume((sec_r001546_11_2 >= 0) && (sec_r001546_11_2 <= 255));
  __CPROVER_assume((sec_r001546_12_1 >= 0) && (sec_r001546_12_1 <= 255));
  __CPROVER_assume((sec_r001546_12_2 >= 0) && (sec_r001546_12_2 <= 255));
  __CPROVER_assume((sec_r001546_13_1 >= 0) && (sec_r001546_13_1 <= 255));
  __CPROVER_assume((sec_r001546_13_2 >= 0) && (sec_r001546_13_2 <= 255));
  __CPROVER_assume((sec_r001546_14_1 >= 0) && (sec_r001546_14_1 <= 255));
  __CPROVER_assume((sec_r001546_14_2 >= 0) && (sec_r001546_14_2 <= 255));
  __CPROVER_assume((sec_r001546_15_1 >= 0) && (sec_r001546_15_1 <= 255));
  __CPROVER_assume((sec_r001546_15_2 >= 0) && (sec_r001546_15_2 <= 255));
  __CPROVER_assume((sec_r001546_16_1 >= 0) && (sec_r001546_16_1 <= 255));
  __CPROVER_assume((sec_r001546_16_2 >= 0) && (sec_r001546_16_2 <= 255));
  __CPROVER_assume((sec_r001546_17_1 >= 0) && (sec_r001546_17_1 <= 255));
  __CPROVER_assume((sec_r001546_17_2 >= 0) && (sec_r001546_17_2 <= 255));
  __CPROVER_assume((sec_r001546_18_1 >= 0) && (sec_r001546_18_1 <= 255));
  __CPROVER_assume((sec_r001546_18_2 >= 0) && (sec_r001546_18_2 <= 255));
  __CPROVER_assume((sec_r001546_19_1 >= 0) && (sec_r001546_19_1 <= 255));
  __CPROVER_assume((sec_r001546_19_2 >= 0) && (sec_r001546_19_2 <= 255));
  __CPROVER_assume((sec_r001546_20_1 >= 0) && (sec_r001546_20_1 <= 255));
  __CPROVER_assume((sec_r001546_20_2 >= 0) && (sec_r001546_20_2 <= 255));
  __CPROVER_assume((sec_r001546_21_1 >= 0) && (sec_r001546_21_1 <= 255));
  __CPROVER_assume((sec_r001546_21_2 >= 0) && (sec_r001546_21_2 <= 255));
  __CPROVER_assume((sec_r001546_22_1 >= 0) && (sec_r001546_22_1 <= 255));
  __CPROVER_assume((sec_r001546_22_2 >= 0) && (sec_r001546_22_2 <= 255));
  __CPROVER_assume((sec_r001546_23_1 >= 0) && (sec_r001546_23_1 <= 255));
  __CPROVER_assume((sec_r001546_23_2 >= 0) && (sec_r001546_23_2 <= 255));
  struct MatrixBlock_R001546_4613_0 st_var_0_1 = {0};
  struct MatrixBlock_R001546_4613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001546_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001546_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001546_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001546_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001546_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001546_0_2 + 7) & 15;
  struct CipherContext_R001546_4613_1 st_var_1_1 = {0};
  struct CipherContext_R001546_4613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001546_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001546_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001546_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001546_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001546_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001546_0_2 + 9) & 15;
  struct SensorNode_R001546_4613_2 st_var_2_1 = {0};
  struct SensorNode_R001546_4613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001546_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001546_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001546_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001546_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001546_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001546_0_2 + 11) & 15;
  union TelemetryField_R001546_4613_0 u_var_1;
  union TelemetryField_R001546_4613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001546_4613_0(sec_r001546_0_1, pub_r001546_1_1);
  int helper_flow_0_2 = fn_R001546_4613_0(sec_r001546_0_2, pub_r001546_1_2);
  fn_R001546_4613_0_2(sec_r001546_0_1, pub_r001546_1_1, sec_r001546_0_2, pub_r001546_1_2);
  int helper_flow_1_1 = fn_R001546_4613_1(sec_r001546_1_1, pub_r001546_2_1, pub_r001546_3_1);
  int helper_flow_1_2 = fn_R001546_4613_1(sec_r001546_1_2, pub_r001546_2_2, pub_r001546_3_2);
  fn_R001546_4613_1_2(sec_r001546_1_1, pub_r001546_2_1, pub_r001546_3_1, sec_r001546_1_2, pub_r001546_2_2, pub_r001546_3_2);
  int helper_flow_2_1 = fn_R001546_4613_2(sec_r001546_2_1, sec_r001546_3_1, pub_r001546_4_1, pub_r001546_5_1, pub_r001546_6_1);
  int helper_flow_2_2 = fn_R001546_4613_2(sec_r001546_2_2, sec_r001546_3_2, pub_r001546_4_2, pub_r001546_5_2, pub_r001546_6_2);
  fn_R001546_4613_2_2(sec_r001546_2_1, sec_r001546_3_1, pub_r001546_4_1, pub_r001546_5_1, pub_r001546_6_1, sec_r001546_2_2, sec_r001546_3_2, pub_r001546_4_2, pub_r001546_5_2, pub_r001546_6_2);
  int helper_flow_3_1 = fn_R001546_4613_3(sec_r001546_3_1, pub_r001546_4_1, pub_r001546_5_1, pub_r001546_6_1, pub_r001546_7_1);
  int helper_flow_3_2 = fn_R001546_4613_3(sec_r001546_3_2, pub_r001546_4_2, pub_r001546_5_2, pub_r001546_6_2, pub_r001546_7_2);
  fn_R001546_4613_3_2(sec_r001546_3_1, pub_r001546_4_1, pub_r001546_5_1, pub_r001546_6_1, pub_r001546_7_1, sec_r001546_3_2, pub_r001546_4_2, pub_r001546_5_2, pub_r001546_6_2, pub_r001546_7_2);
  int helper_flow_4_1 = fn_R001546_4613_4(sec_r001546_4_1, sec_r001546_5_1);
  int helper_flow_4_2 = fn_R001546_4613_4(sec_r001546_4_2, sec_r001546_5_2);
  fn_R001546_4613_4_2(sec_r001546_4_1, sec_r001546_5_1, sec_r001546_4_2, sec_r001546_5_2);
  int helper_flow_5_1 = fn_R001546_4613_5(sec_r001546_5_1, pub_r001546_6_1);
  int helper_flow_5_2 = fn_R001546_4613_5(sec_r001546_5_2, pub_r001546_6_2);
  fn_R001546_4613_5_2(sec_r001546_5_1, pub_r001546_6_1, sec_r001546_5_2, pub_r001546_6_2);
  int helper_flow_6_1 = fn_R001546_4613_6(sec_r001546_6_1, sec_r001546_7_1, pub_r001546_8_1);
  int helper_flow_6_2 = fn_R001546_4613_6(sec_r001546_6_2, sec_r001546_7_2, pub_r001546_8_2);
  fn_R001546_4613_6_2(sec_r001546_6_1, sec_r001546_7_1, pub_r001546_8_1, sec_r001546_6_2, sec_r001546_7_2, pub_r001546_8_2);
  int stage_v_0_1 = ((sec_r001546_10_1 + (pub_r001546_11_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((sec_r001546_10_2 + (pub_r001546_11_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((sec_r001546_21_1 + (pub_r001546_3_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((sec_r001546_21_2 + (pub_r001546_3_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((sec_r001546_20_1 + (pub_r001546_11_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((sec_r001546_20_2 + (pub_r001546_11_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((pub_r001546_18_1 * 2) + 38) & 63;
  int stage_v_3_2 = ((pub_r001546_18_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001546_14_1 * 2) + 8) & 63;
  int stage_v_4_2 = ((pub_r001546_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((sec_r001546_5_1 + (pub_r001546_6_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((sec_r001546_5_2 + (pub_r001546_6_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((sec_r001546_11_1 + (pub_r001546_11_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((sec_r001546_11_2 + (pub_r001546_11_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((pub_r001546_4_1 * 2) + 12) & 63;
  int stage_v_7_2 = ((pub_r001546_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((sec_r001546_11_1 + (pub_r001546_7_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((sec_r001546_11_2 + (pub_r001546_7_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((sec_r001546_5_1 + (pub_r001546_16_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((sec_r001546_5_2 + (pub_r001546_16_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((sec_r001546_18_1 + (pub_r001546_16_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((sec_r001546_18_2 + (pub_r001546_16_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((pub_r001546_10_1 * 2) + 12) & 63;
  int stage_v_11_2 = ((pub_r001546_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((sec_r001546_21_1 + (pub_r001546_1_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((sec_r001546_21_2 + (pub_r001546_1_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((sec_r001546_17_1 + (pub_r001546_1_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((sec_r001546_17_2 + (pub_r001546_1_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((sec_r001546_4_1 + (pub_r001546_18_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((sec_r001546_4_2 + (pub_r001546_18_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((stage_v_5_1 + (pub_r001546_13_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((stage_v_5_2 + (pub_r001546_13_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((stage_v_2_1 + (pub_r001546_11_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((stage_v_2_2 + (pub_r001546_11_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((sec_r001546_13_1 + (pub_r001546_18_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001546_13_2 + (pub_r001546_18_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((pub_r001546_14_1 * 2) + 8) & 63;
  int stage_v_18_2 = ((pub_r001546_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((stage_v_12_1 + (pub_r001546_12_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((stage_v_12_2 + (pub_r001546_12_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((stage_v_17_1 + (pub_r001546_13_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((stage_v_17_2 + (pub_r001546_13_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((stage_v_1_1 + (pub_r001546_10_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((stage_v_1_2 + (pub_r001546_10_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((stage_v_12_1 + (pub_r001546_2_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((stage_v_12_2 + (pub_r001546_2_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((pub_r001546_3_1 * 2) + 20) & 63;
  int stage_v_23_2 = ((pub_r001546_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((sec_r001546_21_1 + (pub_r001546_5_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((sec_r001546_21_2 + (pub_r001546_5_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((stage_v_20_1 + (pub_r001546_14_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((stage_v_20_2 + (pub_r001546_14_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((helper_flow_2_1 + (pub_r001546_7_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((helper_flow_2_2 + (pub_r001546_7_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((sec_r001546_8_1 + (pub_r001546_7_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((sec_r001546_8_2 + (pub_r001546_7_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((stage_v_12_1 + (pub_r001546_3_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((stage_v_12_2 + (pub_r001546_3_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((pub_r001546_13_1 * 2) + 35) & 63;
  int stage_v_29_2 = ((pub_r001546_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((sec_r001546_15_1 + (pub_r001546_17_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((sec_r001546_15_2 + (pub_r001546_17_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((sec_r001546_6_1 + (pub_r001546_14_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((sec_r001546_6_2 + (pub_r001546_14_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((sec_r001546_23_1 + (pub_r001546_5_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((sec_r001546_23_2 + (pub_r001546_5_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((sec_r001546_17_1 + (pub_r001546_0_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((sec_r001546_17_2 + (pub_r001546_0_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((pub_r001546_0_1 * 2) + 21) & 63;
  int stage_v_34_2 = ((pub_r001546_0_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001546_11_1 * 2) + 8) & 63;
  int stage_v_35_2 = ((pub_r001546_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001546_4_1 * 2) + 48) & 63;
  int stage_v_36_2 = ((pub_r001546_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001546_13_1 * 2) + 12) & 63;
  int stage_v_37_2 = ((pub_r001546_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001546_2_1 * 2) + 23) & 63;
  int stage_v_38_2 = ((pub_r001546_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((sec_r001546_1_1 + (pub_r001546_15_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((sec_r001546_1_2 + (pub_r001546_15_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((stage_v_6_1 + (pub_r001546_1_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((stage_v_6_2 + (pub_r001546_1_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((sec_r001546_7_1 + (pub_r001546_16_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((sec_r001546_7_2 + (pub_r001546_16_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((pub_r001546_8_1 * 2) + 35) & 63;
  int stage_v_42_2 = ((pub_r001546_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001546_0_1 * 2) + 36) & 63;
  int stage_v_43_2 = ((pub_r001546_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((stage_v_26_1 + (pub_r001546_10_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((stage_v_26_2 + (pub_r001546_10_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((sec_r001546_1_1 + (pub_r001546_5_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((sec_r001546_1_2 + (pub_r001546_5_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((stage_v_16_1 + (pub_r001546_3_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((stage_v_16_2 + (pub_r001546_3_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((stage_v_10_1 + (pub_r001546_12_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((stage_v_10_2 + (pub_r001546_12_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((sec_r001546_7_1 + (pub_r001546_9_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((sec_r001546_7_2 + (pub_r001546_9_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((stage_v_33_1 + (pub_r001546_3_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((stage_v_33_2 + (pub_r001546_3_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((sec_r001546_8_1 + (pub_r001546_11_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((sec_r001546_8_2 + (pub_r001546_11_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((helper_flow_6_1 + (pub_r001546_18_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((helper_flow_6_2 + (pub_r001546_18_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((sec_r001546_9_1 + (pub_r001546_3_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((sec_r001546_9_2 + (pub_r001546_3_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((pub_r001546_8_1 * 2) + 39) & 63;
  int stage_v_53_2 = ((pub_r001546_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((stage_v_47_1 + (pub_r001546_7_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((stage_v_47_2 + (pub_r001546_7_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((sec_r001546_17_1 + (pub_r001546_10_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((sec_r001546_17_2 + (pub_r001546_10_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((pub_r001546_2_1 * 2) + 43) & 63;
  int stage_v_56_2 = ((pub_r001546_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((stage_v_17_1 + (pub_r001546_0_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((stage_v_17_2 + (pub_r001546_0_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((stage_v_0_1 + (pub_r001546_18_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((stage_v_0_2 + (pub_r001546_18_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((stage_v_58_1 + (pub_r001546_17_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((stage_v_58_2 + (pub_r001546_17_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((pub_r001546_4_1 * 2) + 14) & 63;
  int stage_v_60_2 = ((pub_r001546_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001546_5_1 * 2) + 27) & 63;
  int stage_v_61_2 = ((pub_r001546_5_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((stage_v_12_1 + (pub_r001546_4_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((stage_v_12_2 + (pub_r001546_4_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((stage_v_0_1 + (pub_r001546_15_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((stage_v_0_2 + (pub_r001546_15_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((helper_flow_2_1 + (pub_r001546_9_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((helper_flow_2_2 + (pub_r001546_9_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((stage_v_49_1 + (pub_r001546_2_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_49_2 + (pub_r001546_2_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((pub_r001546_0_1 * 2) + 38) & 63;
  int stage_v_66_2 = ((pub_r001546_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((stage_v_25_1 + (pub_r001546_3_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((stage_v_25_2 + (pub_r001546_3_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((pub_r001546_9_1 * 2) + 32) & 63;
  int stage_v_68_2 = ((pub_r001546_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001546_3_1 * 2) + 33) & 63;
  int stage_v_69_2 = ((pub_r001546_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001546_2_1 * 2) + 35) & 63;
  int stage_v_70_2 = ((pub_r001546_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((stage_v_13_1 + (pub_r001546_11_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_13_2 + (pub_r001546_11_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((sec_r001546_4_1 + (pub_r001546_12_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((sec_r001546_4_2 + (pub_r001546_12_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((stage_v_26_1 + (pub_r001546_5_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_26_2 + (pub_r001546_5_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((stage_v_64_1 + (pub_r001546_1_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((stage_v_64_2 + (pub_r001546_1_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((pub_r001546_7_1 * 2) + 28) & 63;
  int stage_v_75_2 = ((pub_r001546_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001546_7_1 * 2) + 8) & 63;
  int stage_v_76_2 = ((pub_r001546_7_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((sec_r001546_3_1 + (pub_r001546_14_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((sec_r001546_3_2 + (pub_r001546_14_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((stage_v_57_1 + (pub_r001546_6_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_57_2 + (pub_r001546_6_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((stage_v_39_1 + (pub_r001546_12_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((stage_v_39_2 + (pub_r001546_12_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((sec_r001546_8_1 + (pub_r001546_14_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((sec_r001546_8_2 + (pub_r001546_14_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((stage_v_15_1 + (pub_r001546_11_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((stage_v_15_2 + (pub_r001546_11_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((stage_v_8_1 + (pub_r001546_7_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((stage_v_8_2 + (pub_r001546_7_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((sec_r001546_9_1 + (pub_r001546_2_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((sec_r001546_9_2 + (pub_r001546_2_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((stage_v_1_1 + (pub_r001546_13_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((stage_v_1_2 + (pub_r001546_13_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((sec_r001546_17_1 + (pub_r001546_5_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((sec_r001546_17_2 + (pub_r001546_5_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((pub_r001546_18_1 * 2) + 32) & 63;
  int stage_v_86_2 = ((pub_r001546_18_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((stage_v_26_1 + (pub_r001546_10_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_26_2 + (pub_r001546_10_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((pub_r001546_18_1 * 2) + 32) & 63;
  int stage_v_88_2 = ((pub_r001546_18_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((stage_v_45_1 + (pub_r001546_6_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((stage_v_45_2 + (pub_r001546_6_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((pub_r001546_14_1 * 2) + 31) & 63;
  int stage_v_90_2 = ((pub_r001546_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001546_0_1 * 2) + 50) & 63;
  int stage_v_91_2 = ((pub_r001546_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001546_8_1 * 2) + 15) & 63;
  int stage_v_92_2 = ((pub_r001546_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001546_11_1 * 2) + 46) & 63;
  int stage_v_93_2 = ((pub_r001546_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((sec_r001546_18_1 + (pub_r001546_4_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((sec_r001546_18_2 + (pub_r001546_4_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((stage_v_45_1 + (pub_r001546_14_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_45_2 + (pub_r001546_14_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((sec_r001546_19_1 + (pub_r001546_0_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((sec_r001546_19_2 + (pub_r001546_0_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((stage_v_46_1 + (pub_r001546_2_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((stage_v_46_2 + (pub_r001546_2_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((stage_v_50_1 + (pub_r001546_1_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_50_2 + (pub_r001546_1_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((stage_v_45_1 + (pub_r001546_5_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_45_2 + (pub_r001546_5_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((stage_v_6_1 + (pub_r001546_8_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((stage_v_6_2 + (pub_r001546_8_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((stage_v_40_1 + (pub_r001546_0_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((stage_v_40_2 + (pub_r001546_0_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((pub_r001546_2_1 * 2) + 17) & 63;
  int stage_v_102_2 = ((pub_r001546_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001546_17_1 * 2) + 49) & 63;
  int stage_v_103_2 = ((pub_r001546_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((helper_flow_6_1 + (pub_r001546_6_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((helper_flow_6_2 + (pub_r001546_6_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((pub_r001546_6_1 * 2) + 43) & 63;
  int stage_v_105_2 = ((pub_r001546_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((stage_v_47_1 + (pub_r001546_12_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_47_2 + (pub_r001546_12_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((helper_flow_6_1 + (pub_r001546_17_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((helper_flow_6_2 + (pub_r001546_17_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((sec_r001546_2_1 + (pub_r001546_7_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((sec_r001546_2_2 + (pub_r001546_7_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((pub_r001546_2_1 * 2) + 39) & 63;
  int stage_v_109_2 = ((pub_r001546_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001546_8_1 * 2) + 10) & 63;
  int stage_v_110_2 = ((pub_r001546_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((sec_r001546_18_1 + (pub_r001546_1_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((sec_r001546_18_2 + (pub_r001546_1_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((pub_r001546_12_1 * 2) + 21) & 63;
  int stage_v_112_2 = ((pub_r001546_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((sec_r001546_17_1 + (pub_r001546_9_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((sec_r001546_17_2 + (pub_r001546_9_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((sec_r001546_10_1 + (pub_r001546_3_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((sec_r001546_10_2 + (pub_r001546_3_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((stage_v_40_1 + (pub_r001546_0_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_40_2 + (pub_r001546_0_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((stage_v_83_1 + (pub_r001546_14_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_83_2 + (pub_r001546_14_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((stage_v_114_1 + (pub_r001546_8_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((stage_v_114_2 + (pub_r001546_8_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((sec_r001546_11_1 + (pub_r001546_9_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((sec_r001546_11_2 + (pub_r001546_9_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((sec_r001546_5_1 + (pub_r001546_15_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((sec_r001546_5_2 + (pub_r001546_15_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((stage_v_77_1 + (pub_r001546_17_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_77_2 + (pub_r001546_17_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((stage_v_16_1 + (pub_r001546_1_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_16_2 + (pub_r001546_1_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((stage_v_51_1 + (pub_r001546_10_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_51_2 + (pub_r001546_10_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((sec_r001546_4_1 + (pub_r001546_14_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((sec_r001546_4_2 + (pub_r001546_14_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((pub_r001546_7_1 * 2) + 16) & 63;
  int stage_v_124_2 = ((pub_r001546_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((sec_r001546_11_1 + (pub_r001546_17_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((sec_r001546_11_2 + (pub_r001546_17_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((stage_v_2_1 + (pub_r001546_10_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_2_2 + (pub_r001546_10_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((pub_r001546_11_1 * 2) + 44) & 63;
  int stage_v_127_2 = ((pub_r001546_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((stage_v_46_1 + (pub_r001546_11_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((stage_v_46_2 + (pub_r001546_11_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((pub_r001546_18_1 * 2) + 32) & 63;
  int stage_v_129_2 = ((pub_r001546_18_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((sec_r001546_16_1 + (pub_r001546_11_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((sec_r001546_16_2 + (pub_r001546_11_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((stage_v_120_1 + (pub_r001546_17_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((stage_v_120_2 + (pub_r001546_17_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((stage_v_114_1 + (pub_r001546_7_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_114_2 + (pub_r001546_7_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((stage_v_81_1 + (pub_r001546_13_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((stage_v_81_2 + (pub_r001546_13_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((stage_v_95_1 + (pub_r001546_5_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_95_2 + (pub_r001546_5_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((stage_v_96_1 + (pub_r001546_12_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_96_2 + (pub_r001546_12_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((pub_r001546_9_1 * 2) + 35) & 63;
  int stage_v_136_2 = ((pub_r001546_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((stage_v_14_1 + (pub_r001546_2_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_14_2 + (pub_r001546_2_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((stage_v_130_1 + (pub_r001546_17_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((stage_v_130_2 + (pub_r001546_17_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((pub_r001546_17_1 * 2) + 45) & 63;
  int stage_v_139_2 = ((pub_r001546_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((stage_v_128_1 + (pub_r001546_13_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_128_2 + (pub_r001546_13_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((stage_v_104_1 + (pub_r001546_18_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((stage_v_104_2 + (pub_r001546_18_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((pub_r001546_15_1 * 2) + 46) & 63;
  int stage_v_142_2 = ((pub_r001546_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((sec_r001546_9_1 + (pub_r001546_9_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((sec_r001546_9_2 + (pub_r001546_9_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((stage_v_130_1 + (pub_r001546_16_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((stage_v_130_2 + (pub_r001546_16_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((pub_r001546_9_1 * 2) + 25) & 63;
  int stage_v_145_2 = ((pub_r001546_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((stage_v_123_1 + (pub_r001546_9_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_123_2 + (pub_r001546_9_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((pub_r001546_15_1 * 2) + 40) & 63;
  int stage_v_147_2 = ((pub_r001546_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001546_8_1 * 2) + 46) & 63;
  int stage_v_148_2 = ((pub_r001546_8_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001546_5_1 * 2) + 48) & 63;
  int stage_v_149_2 = ((pub_r001546_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((stage_v_108_1 + (pub_r001546_18_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_108_2 + (pub_r001546_18_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((stage_v_135_1 + (pub_r001546_11_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_135_2 + (pub_r001546_11_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((pub_r001546_13_1 * 2) + 18) & 63;
  int stage_v_152_2 = ((pub_r001546_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((stage_v_89_1 + (pub_r001546_6_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_89_2 + (pub_r001546_6_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((stage_v_122_1 + (pub_r001546_15_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((stage_v_122_2 + (pub_r001546_15_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((helper_flow_3_1 + (pub_r001546_17_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((helper_flow_3_2 + (pub_r001546_17_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((stage_v_9_1 + (pub_r001546_7_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((stage_v_9_2 + (pub_r001546_7_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((pub_r001546_7_1 * 2) + 30) & 63;
  int stage_v_157_2 = ((pub_r001546_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((sec_r001546_13_1 + (pub_r001546_12_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((sec_r001546_13_2 + (pub_r001546_12_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((sec_r001546_16_1 + (pub_r001546_8_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((sec_r001546_16_2 + (pub_r001546_8_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((stage_v_21_1 + (pub_r001546_4_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_21_2 + (pub_r001546_4_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((stage_v_121_1 + (pub_r001546_6_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_121_2 + (pub_r001546_6_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((pub_r001546_17_1 * 2) + 29) & 63;
  int stage_v_162_2 = ((pub_r001546_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((stage_v_82_1 + (pub_r001546_14_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_82_2 + (pub_r001546_14_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((stage_v_125_1 + (pub_r001546_18_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_125_2 + (pub_r001546_18_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((pub_r001546_5_1 * 2) + 49) & 63;
  int stage_v_165_2 = ((pub_r001546_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001546_8_1 * 2) + 7) & 63;
  int stage_v_166_2 = ((pub_r001546_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((stage_v_57_1 + (pub_r001546_7_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_57_2 + (pub_r001546_7_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_150_1 + (pub_r001546_14_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_150_2 + (pub_r001546_14_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((stage_v_62_1 + (pub_r001546_4_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_62_2 + (pub_r001546_4_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((helper_flow_3_1 + (pub_r001546_18_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((helper_flow_3_2 + (pub_r001546_18_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((pub_r001546_4_1 * 2) + 43) & 63;
  int stage_v_171_2 = ((pub_r001546_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((stage_v_89_1 + (pub_r001546_14_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_89_2 + (pub_r001546_14_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((helper_flow_0_1 + (pub_r001546_1_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((helper_flow_0_2 + (pub_r001546_1_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((stage_v_100_1 + (pub_r001546_17_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_100_2 + (pub_r001546_17_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((stage_v_150_1 + (pub_r001546_5_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_150_2 + (pub_r001546_5_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((sec_r001546_9_1 + (pub_r001546_12_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((sec_r001546_9_2 + (pub_r001546_12_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((pub_r001546_9_1 * 2) + 41) & 63;
  int stage_v_177_2 = ((pub_r001546_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((stage_v_89_1 + (pub_r001546_2_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_89_2 + (pub_r001546_2_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((pub_r001546_10_1 * 2) + 39) & 63;
  int stage_v_179_2 = ((pub_r001546_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((stage_v_118_1 + (pub_r001546_9_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_118_2 + (pub_r001546_9_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((pub_r001546_17_1 * 2) + 46) & 63;
  int stage_v_181_2 = ((pub_r001546_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((stage_v_119_1 + (pub_r001546_2_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_119_2 + (pub_r001546_2_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((stage_v_172_1 + (pub_r001546_12_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_172_2 + (pub_r001546_12_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((pub_r001546_17_1 * 2) + 44) & 63;
  int stage_v_184_2 = ((pub_r001546_17_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001546_13_1 * 2) + 24) & 63;
  int stage_v_185_2 = ((pub_r001546_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001546_12_1 * 2) + 48) & 63;
  int stage_v_186_2 = ((pub_r001546_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((stage_v_72_1 + (pub_r001546_0_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_72_2 + (pub_r001546_0_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((pub_r001546_4_1 * 2) + 22) & 63;
  int stage_v_188_2 = ((pub_r001546_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001546_15_1 * 2) + 14) & 63;
  int stage_v_189_2 = ((pub_r001546_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001546_0_1 * 2) + 44) & 63;
  int stage_v_190_2 = ((pub_r001546_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((stage_v_160_1 + (pub_r001546_14_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((stage_v_160_2 + (pub_r001546_14_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((stage_v_40_1 + (pub_r001546_0_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_40_2 + (pub_r001546_0_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((pub_r001546_7_1 * 2) + 18) & 63;
  int stage_v_193_2 = ((pub_r001546_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((stage_v_104_1 + (pub_r001546_1_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_104_2 + (pub_r001546_1_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((stage_v_94_1 + (pub_r001546_8_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_94_2 + (pub_r001546_8_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((stage_v_48_1 + (pub_r001546_6_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((stage_v_48_2 + (pub_r001546_6_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((stage_v_116_1 + (pub_r001546_7_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_116_2 + (pub_r001546_7_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((stage_v_192_1 + (pub_r001546_10_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((stage_v_192_2 + (pub_r001546_10_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((stage_v_160_1 + (pub_r001546_9_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_160_2 + (pub_r001546_9_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((pub_r001546_1_1 * 2) + 14) & 63;
  int stage_v_200_2 = ((pub_r001546_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001546_12_1 * 2) + 35) & 63;
  int stage_v_201_2 = ((pub_r001546_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((stage_v_15_1 + (pub_r001546_8_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_15_2 + (pub_r001546_8_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((pub_r001546_11_1 * 2) + 30) & 63;
  int stage_v_203_2 = ((pub_r001546_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001546_0_1 * 2) + 48) & 63;
  int stage_v_204_2 = ((pub_r001546_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((pub_r001546_17_1 * 2) + 27) & 63;
  int stage_v_205_2 = ((pub_r001546_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001546_18_1 * 2) + 42) & 63;
  int stage_v_206_2 = ((pub_r001546_18_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((stage_v_52_1 + (pub_r001546_17_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((stage_v_52_2 + (pub_r001546_17_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((stage_v_150_1 + (pub_r001546_1_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_150_2 + (pub_r001546_1_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((pub_r001546_0_1 * 2) + 35) & 63;
  int stage_v_209_2 = ((pub_r001546_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((stage_v_140_1 + (pub_r001546_9_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((stage_v_140_2 + (pub_r001546_9_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((sec_r001546_7_1 + (pub_r001546_18_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((sec_r001546_7_2 + (pub_r001546_18_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((stage_v_144_1 + (pub_r001546_3_1 * 2)) + 641) & 127;
  int stage_v_212_2 = ((stage_v_144_2 + (pub_r001546_3_2 * 2)) + 641) & 127;
  if (stage_v_212_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_212_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_212_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_212_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_213_1 = ((pub_r001546_11_1 * 2) + 25) & 63;
  int stage_v_213_2 = ((pub_r001546_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((sec_r001546_12_1 + (pub_r001546_9_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((sec_r001546_12_2 + (pub_r001546_9_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((pub_r001546_9_1 * 2) + 5) & 63;
  int stage_v_215_2 = ((pub_r001546_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((sec_r001546_22_1 + (pub_r001546_16_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((sec_r001546_22_2 + (pub_r001546_16_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_217_1 = ((stage_v_64_1 + (pub_r001546_2_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((stage_v_64_2 + (pub_r001546_2_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((stage_v_81_1 + (pub_r001546_13_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_81_2 + (pub_r001546_13_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((pub_r001546_12_1 * 2) + 16) & 63;
  int stage_v_219_2 = ((pub_r001546_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((stage_v_31_1 + (pub_r001546_6_1 * 2)) + 665) & 127;
  int stage_v_220_2 = ((stage_v_31_2 + (pub_r001546_6_2 * 2)) + 665) & 127;
  if (stage_v_220_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_220_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_220_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_220_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001546_15_1 == pub_r001546_15_2);
  __CPROVER_assume(pub_r001546_0_1 == pub_r001546_0_2);
  __CPROVER_assume(sec_r001546_14_1 != sec_r001546_14_2);
  __CPROVER_assume(pub_r001546_12_1 == pub_r001546_12_2);
  __CPROVER_assume(sec_r001546_12_1 != sec_r001546_12_2);
  __CPROVER_assume(sec_r001546_16_1 != sec_r001546_16_2);
  __CPROVER_assume(pub_r001546_8_1 == pub_r001546_8_2);
  __CPROVER_assume(sec_r001546_21_1 != sec_r001546_21_2);
  __CPROVER_assume(sec_r001546_15_1 != sec_r001546_15_2);
  __CPROVER_assume(pub_r001546_10_1 == pub_r001546_10_2);
  __CPROVER_assume(pub_r001546_6_1 == pub_r001546_6_2);
  __CPROVER_assume(pub_r001546_17_1 == pub_r001546_17_2);
  __CPROVER_assume(sec_r001546_17_1 != sec_r001546_17_2);
  __CPROVER_assume(pub_r001546_9_1 == pub_r001546_9_2);
  __CPROVER_assume(pub_r001546_13_1 == pub_r001546_13_2);
  __CPROVER_assume(pub_r001546_14_1 == pub_r001546_14_2);
  __CPROVER_assume(pub_r001546_16_1 == pub_r001546_16_2);
  __CPROVER_assume(sec_r001546_18_1 != sec_r001546_18_2);
  __CPROVER_assume(sec_r001546_6_1 != sec_r001546_6_2);
  __CPROVER_assume(sec_r001546_11_1 != sec_r001546_11_2);
  __CPROVER_assume(pub_r001546_4_1 == pub_r001546_4_2);
  __CPROVER_assume(sec_r001546_5_1 != sec_r001546_5_2);
  __CPROVER_assume(sec_r001546_23_1 != sec_r001546_23_2);
  __CPROVER_assume(sec_r001546_22_1 != sec_r001546_22_2);
  __CPROVER_assume(sec_r001546_8_1 != sec_r001546_8_2);
  __CPROVER_assume(pub_r001546_1_1 == pub_r001546_1_2);
  __CPROVER_assume(sec_r001546_13_1 != sec_r001546_13_2);
  __CPROVER_assume(sec_r001546_2_1 != sec_r001546_2_2);
  __CPROVER_assume(sec_r001546_19_1 != sec_r001546_19_2);
  __CPROVER_assume(sec_r001546_10_1 != sec_r001546_10_2);
  __CPROVER_assume(sec_r001546_4_1 != sec_r001546_4_2);
  __CPROVER_assume(sec_r001546_20_1 != sec_r001546_20_2);
  __CPROVER_assume(sec_r001546_3_1 != sec_r001546_3_2);
  __CPROVER_assume(sec_r001546_7_1 != sec_r001546_7_2);
  __CPROVER_assume(pub_r001546_7_1 == pub_r001546_7_2);
  __CPROVER_assume(pub_r001546_2_1 == pub_r001546_2_2);
  __CPROVER_assume(pub_r001546_3_1 == pub_r001546_3_2);
  __CPROVER_assume(pub_r001546_5_1 == pub_r001546_5_2);
  __CPROVER_assume(pub_r001546_18_1 == pub_r001546_18_2);
  __CPROVER_assume(sec_r001546_9_1 != sec_r001546_9_2);
  __CPROVER_assume(pub_r001546_11_1 == pub_r001546_11_2);
  __CPROVER_assume(sec_r001546_1_1 != sec_r001546_1_2);
  __CPROVER_assume(sec_r001546_0_1 != sec_r001546_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.flags == st_var_1_2.flags);
  assert(st_var_1_1.nonce == st_var_1_2.nonce);
  assert(st_var_1_1.tag == st_var_1_2.tag);
  assert(st_var_1_1.counter == st_var_1_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.calib == st_var_2_2.calib);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.offset == st_var_2_2.offset);
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
}


