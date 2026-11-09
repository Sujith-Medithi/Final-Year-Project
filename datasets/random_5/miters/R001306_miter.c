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
struct MatrixBlock_R001306_613_0
{
  short stride;
  unsigned char determinant;
  int dim;
  int buffer[3];
};
struct CipherContext_R001306_613_1
{
  short nonce;
  short flags;
  unsigned char round_key;
  short iv;
  int tag;
  int buffer[3];
};
union TelemetryField_R001306_613_0
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
void fn_R001306_613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st_1 = {0};
  struct MatrixBlock_R001306_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int stride_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_25_1 > 39)
  {
    acc_1 = ((acc_1 + (stride_25_1 * 2)) + 5) & 127;
    aux_1 ^= stride_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_25_2 > 39)
  {
    acc_2 = ((acc_2 + (stride_25_2 * 2)) + 5) & 127;
    aux_2 ^= stride_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_25_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_59_1) & 63;
  aux_2 = (aux_2 + parity_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_50_1 = 0;
  int tracker_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_50_1 = ((tracker_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_50_2 = ((tracker_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_50_1) & 127;
    acc_2 = (acc_2 + tracker_50_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_25_1 == stride_25_2);
  assert(parity_59_1 == parity_59_2);
  assert(tracker_50_1 == tracker_50_2);
}

int fn_R001306_613_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int stride_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_25 > 39)
  {
    acc = ((acc + (stride_25 * 2)) + 5) & 127;
    aux ^= stride_25 & 15;
  }
  else
  {
    acc = ((acc - stride_25) + 11) & 127;
    aux += 3;
  }
  int parity_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_59) & 63;
  acc ^= aux;
  int tracker_50 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_50 = ((tracker_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_50) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001306_613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st_1 = {0};
  struct CipherContext_R001306_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_40_1 = local_arr_1[aux_1 % 3];
  int segment_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_40_2 * 2)) & 127;
  int parity_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_56_1 > 19)
  {
    acc_1 = ((acc_1 + (parity_56_1 * 2)) + 5) & 127;
    aux_1 ^= parity_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_56_2 > 19)
  {
    acc_2 = ((acc_2 + (parity_56_2 * 2)) + 5) & 127;
    aux_2 ^= parity_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_40_1 == segment_40_2);
  assert(parity_56_1 == parity_56_2);
}

int fn_R001306_613_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int segment_40 = local_arr[aux % 3];
  acc = (acc + (segment_40 * 2)) & 127;
  int parity_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_56 > 19)
  {
    acc = ((acc + (parity_56 * 2)) + 5) & 127;
    aux ^= parity_56 & 15;
  }
  else
  {
    acc = ((acc - parity_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001306_613_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st_1 = {0};
  struct CipherContext_R001306_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_32_1)
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

  switch (accumulator_32_2)
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

  int index_reg_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_31_1) & 63;
  aux_2 = (aux_2 + index_reg_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_92_1 = local_arr_1[aux_1 % 3];
  int stride_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_92_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_32_1 == accumulator_32_2);
  assert(index_reg_31_1 == index_reg_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_92_1 == stride_92_2);
}

int fn_R001306_613_2(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_32 = (aux + st.buffer[1]) & 3;
  switch (accumulator_32)
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

  int index_reg_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_31) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_92 = local_arr[aux % 3];
  acc = (acc + (stride_92 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001306_613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st_1 = {0};
  struct CipherContext_R001306_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_39_1 = local_arr_1[aux_1 % 3];
  int damping_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_39_2 * 2)) & 127;
  int offset_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_27_1) & 63;
  aux_2 = (aux_2 + offset_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_86_1 = 0;
  int tracker_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_86_1 = ((tracker_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_86_2 = ((tracker_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_86_1) & 127;
    acc_2 = (acc_2 + tracker_86_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_39_1 == damping_39_2);
  assert(offset_27_1 == offset_27_2);
  assert(tracker_86_1 == tracker_86_2);
}

int fn_R001306_613_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int damping_39 = local_arr[aux % 3];
  acc = (acc + (damping_39 * 2)) & 127;
  int offset_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_27) & 63;
  acc ^= aux;
  int tracker_86 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_86 = ((tracker_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_86) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001306_613_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st_1 = {0};
  struct MatrixBlock_R001306_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int offset_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_82_1 > 39)
  {
    acc_1 = ((acc_1 + (offset_82_1 * 2)) + 5) & 127;
    aux_1 ^= offset_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_82_2 > 39)
  {
    acc_2 = ((acc_2 + (offset_82_2 * 2)) + 5) & 127;
    aux_2 ^= offset_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_82_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_85_1 = local_arr_1[aux_1 % 3];
  int checksum_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_85_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_82_1 == offset_82_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_85_1 == checksum_85_2);
}

int fn_R001306_613_4(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int offset_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_82 > 39)
  {
    acc = ((acc + (offset_82 * 2)) + 5) & 127;
    aux ^= offset_82 & 15;
  }
  else
  {
    acc = ((acc - offset_82) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_85 = local_arr[aux % 3];
  acc = (acc + (checksum_85 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001306_613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st_1 = {0};
  struct CipherContext_R001306_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_19_1 = 0;
  int metric_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_19_1 = ((metric_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_19_2 = ((metric_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_19_1) & 127;
    acc_2 = (acc_2 + metric_19_2) & 127;
  }

  int residue_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_92_1 > 47)
  {
    acc_1 = ((acc_1 + (residue_92_1 * 2)) + 5) & 127;
    aux_1 ^= residue_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_92_2 > 47)
  {
    acc_2 = ((acc_2 + (residue_92_2 * 2)) + 5) & 127;
    aux_2 ^= residue_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_23_1) & 63;
  aux_2 = (aux_2 + phase_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_19_1 == metric_19_2);
  assert(residue_92_1 == residue_92_2);
  assert(phase_23_1 == phase_23_2);
}

int fn_R001306_613_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_19 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_19 = ((metric_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_19) & 127;
  }

  int residue_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_92 > 47)
  {
    acc = ((acc + (residue_92 * 2)) + 5) & 127;
    aux ^= residue_92 & 15;
  }
  else
  {
    acc = ((acc - residue_92) + 11) & 127;
    aux += 3;
  }
  int phase_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_23) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001306_613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st_1 = {0};
  struct MatrixBlock_R001306_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int accumulator_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_27_1 > 34)
  {
    acc_1 = ((acc_1 + (accumulator_27_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_27_2 > 34)
  {
    acc_2 = ((acc_2 + (accumulator_27_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_94_1)
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

  switch (damping_94_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_27_1 == accumulator_27_2);
  assert(damping_94_1 == damping_94_2);
}

int fn_R001306_613_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int accumulator_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_27 > 34)
  {
    acc = ((acc + (accumulator_27 * 2)) + 5) & 127;
    aux ^= accumulator_27 & 15;
  }
  else
  {
    acc = ((acc - accumulator_27) + 11) & 127;
    aux += 3;
  }
  int damping_94 = (aux + st.buffer[1]) & 3;
  switch (damping_94)
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

void fn_R001306_613_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st_1 = {0};
  struct CipherContext_R001306_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int segment_41_1 = 0;
  int segment_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_41_1 = ((segment_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_41_2 = ((segment_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_41_1) & 127;
    acc_2 = (acc_2 + segment_41_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_35_1 = local_arr_1[aux_1 % 3];
  int factor_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_35_2 * 2)) & 127;
  int damping_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_23_1) & 63;
  aux_2 = (aux_2 + damping_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_41_1 == segment_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_35_1 == factor_35_2);
  assert(damping_23_1 == damping_23_2);
}

int fn_R001306_613_7(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int segment_41 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_41 = ((segment_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_41) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int factor_35 = local_arr[aux % 3];
  acc = (acc + (factor_35 * 2)) & 127;
  int damping_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_23) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001306_613_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st_1 = {0};
  struct MatrixBlock_R001306_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_34_1 > 48)
  {
    acc_1 = ((acc_1 + (quantum_34_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_34_2 > 48)
  {
    acc_2 = ((acc_2 + (quantum_34_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_61_1) & 63;
  aux_2 = (aux_2 + residue_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_24_1 = 0;
  int vector_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_24_1 = ((vector_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_24_2 = ((vector_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_24_1) & 127;
    acc_2 = (acc_2 + vector_24_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_34_1 == quantum_34_2);
  assert(residue_61_1 == residue_61_2);
  assert(vector_24_1 == vector_24_2);
}

int fn_R001306_613_8(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_34 > 48)
  {
    acc = ((acc + (quantum_34 * 2)) + 5) & 127;
    aux ^= quantum_34 & 15;
  }
  else
  {
    acc = ((acc - quantum_34) + 11) & 127;
    aux += 3;
  }
  int residue_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_61) & 63;
  acc ^= aux;
  int vector_24 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_24 = ((vector_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_24) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001306_613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st_1 = {0};
  struct MatrixBlock_R001306_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int residue_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_65_1) & 63;
  aux_2 = (aux_2 + residue_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_97_1 = 0;
  int residue_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_97_1 = ((residue_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_97_2 = ((residue_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_97_1) & 127;
    acc_2 = (acc_2 + residue_97_2) & 127;
  }

  int quantum_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_23_1 > 43)
  {
    acc_1 = ((acc_1 + (quantum_23_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_23_2 > 43)
  {
    acc_2 = ((acc_2 + (quantum_23_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_23_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_65_1 == residue_65_2);
  assert(residue_97_1 == residue_97_2);
  assert(quantum_23_1 == quantum_23_2);
}

int fn_R001306_613_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int residue_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_65) & 63;
  acc ^= aux;
  int residue_97 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_97 = ((residue_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_97) & 127;
  }

  int quantum_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_23 > 43)
  {
    acc = ((acc + (quantum_23 * 2)) + 5) & 127;
    aux ^= quantum_23 & 15;
  }
  else
  {
    acc = ((acc - quantum_23) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001306_613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st_1 = {0};
  struct CipherContext_R001306_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_27_1 = local_arr_1[aux_1 % 3];
  int accumulator_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_27_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_50_1)
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

  switch (damping_50_2)
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

  int residue_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_80_1 > 40)
  {
    acc_1 = ((acc_1 + (residue_80_1 * 2)) + 5) & 127;
    aux_1 ^= residue_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_80_2 > 40)
  {
    acc_2 = ((acc_2 + (residue_80_2 * 2)) + 5) & 127;
    aux_2 ^= residue_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_80_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_27_1 == accumulator_27_2);
  assert(damping_50_1 == damping_50_2);
  assert(residue_80_1 == residue_80_2);
}

int fn_R001306_613_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int accumulator_27 = local_arr[aux % 3];
  acc = (acc + (accumulator_27 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_50 = (aux + st.buffer[1]) & 3;
  switch (damping_50)
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

  int residue_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_80 > 40)
  {
    acc = ((acc + (residue_80 * 2)) + 5) & 127;
    aux ^= residue_80 & 15;
  }
  else
  {
    acc = ((acc - residue_80) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001306_613_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st_1 = {0};
  struct MatrixBlock_R001306_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int scale_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_13_1 > 37)
  {
    acc_1 = ((acc_1 + (scale_13_1 * 2)) + 5) & 127;
    aux_1 ^= scale_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_13_2 > 37)
  {
    acc_2 = ((acc_2 + (scale_13_2 * 2)) + 5) & 127;
    aux_2 ^= scale_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_80_1)
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

  switch (offset_80_2)
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

  int anchor_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_22_1) & 63;
  aux_2 = (aux_2 + anchor_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_13_1 == scale_13_2);
  assert(offset_80_1 == offset_80_2);
  assert(anchor_22_1 == anchor_22_2);
}

int fn_R001306_613_11(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int scale_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_13 > 37)
  {
    acc = ((acc + (scale_13 * 2)) + 5) & 127;
    aux ^= scale_13 & 15;
  }
  else
  {
    acc = ((acc - scale_13) + 11) & 127;
    aux += 3;
  }
  int offset_80 = (aux + st.buffer[1]) & 3;
  switch (offset_80)
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

  int anchor_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_22) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001306_613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st_1 = {0};
  struct CipherContext_R001306_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int residue_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_16_1)
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

  switch (residue_16_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_26_1 > 32)
  {
    acc_1 = ((acc_1 + (checksum_26_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_26_2 > 32)
  {
    acc_2 = ((acc_2 + (checksum_26_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_72_1) & 63;
  aux_2 = (aux_2 + scale_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_16_1 == residue_16_2);
  assert(checksum_26_1 == checksum_26_2);
  assert(scale_72_1 == scale_72_2);
}

int fn_R001306_613_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int residue_16 = (aux + st.buffer[1]) & 3;
  switch (residue_16)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_26 > 32)
  {
    acc = ((acc + (checksum_26 * 2)) + 5) & 127;
    aux ^= checksum_26 & 15;
  }
  else
  {
    acc = ((acc - checksum_26) + 11) & 127;
    aux += 3;
  }
  int scale_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_72) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001306_613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st_1 = {0};
  struct MatrixBlock_R001306_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_11_1 = local_arr_1[aux_1 % 3];
  int pivot_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_11_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_18_1 = 0;
  int window_18_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_18_1 = ((window_18_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_18_2 = ((window_18_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_18_1) & 127;
    acc_2 = (acc_2 + window_18_2) & 127;
  }

  int residue_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_49_1)
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

  switch (residue_49_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_11_1 == pivot_11_2);
  assert(window_18_1 == window_18_2);
  assert(residue_49_1 == residue_49_2);
}

int fn_R001306_613_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int pivot_11 = local_arr[aux % 3];
  acc = (acc + (pivot_11 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_18 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_18 = ((window_18 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_18) & 127;
  }

  int residue_49 = (aux + st.buffer[1]) & 3;
  switch (residue_49)
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

void fn_R001306_613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st_1 = {0};
  struct CipherContext_R001306_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_47_1)
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

  switch (anchor_47_2)
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

  int weight_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_91_1) & 63;
  aux_2 = (aux_2 + weight_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_78_1 = local_arr_1[aux_1 % 3];
  int offset_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_78_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_47_1 == anchor_47_2);
  assert(weight_91_1 == weight_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_78_1 == offset_78_2);
}

int fn_R001306_613_14(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_47 = (aux + st.buffer[1]) & 3;
  switch (anchor_47)
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

  int weight_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_91) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_78 = local_arr[aux % 3];
  acc = (acc + (offset_78 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001306_613_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st_1 = {0};
  struct CipherContext_R001306_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int bound_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_10_1) & 63;
  aux_2 = (aux_2 + bound_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_41_1)
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

  switch (index_reg_41_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_10_1 == bound_10_2);
  assert(index_reg_41_1 == index_reg_41_2);
}

int fn_R001306_613_15(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int bound_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_10) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_41 = (aux + st.buffer[1]) & 3;
  switch (index_reg_41)
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

void fn_R001306_613_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st_1 = {0};
  struct CipherContext_R001306_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int vector_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_93_1)
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

  switch (vector_93_2)
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

  int margin_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_21_1 > 31)
  {
    acc_1 = ((acc_1 + (margin_21_1 * 2)) + 5) & 127;
    aux_1 ^= margin_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_21_2 > 31)
  {
    acc_2 = ((acc_2 + (margin_21_2 * 2)) + 5) & 127;
    aux_2 ^= margin_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_21_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_93_1 == vector_93_2);
  assert(margin_21_1 == margin_21_2);
}

int fn_R001306_613_16(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int vector_93 = (aux + st.buffer[1]) & 3;
  switch (vector_93)
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

  int margin_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_21 > 31)
  {
    acc = ((acc + (margin_21 * 2)) + 5) & 127;
    aux ^= margin_21 & 15;
  }
  else
  {
    acc = ((acc - margin_21) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001306_613_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st_1 = {0};
  struct MatrixBlock_R001306_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_45_1 > 37)
  {
    acc_1 = ((acc_1 + (delta_45_1 * 2)) + 5) & 127;
    aux_1 ^= delta_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_45_2 > 37)
  {
    acc_2 = ((acc_2 + (delta_45_2 * 2)) + 5) & 127;
    aux_2 ^= delta_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_32_1) & 63;
  aux_2 = (aux_2 + delta_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_74_1 = local_arr_1[aux_1 % 3];
  int anchor_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_74_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_45_1 == delta_45_2);
  assert(delta_32_1 == delta_32_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_74_1 == anchor_74_2);
}

int fn_R001306_613_17(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_45 > 37)
  {
    acc = ((acc + (delta_45 * 2)) + 5) & 127;
    aux ^= delta_45 & 15;
  }
  else
  {
    acc = ((acc - delta_45) + 11) & 127;
    aux += 3;
  }
  int delta_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_32) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_74 = local_arr[aux % 3];
  acc = (acc + (anchor_74 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001306_613_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st_1 = {0};
  struct CipherContext_R001306_613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int pivot_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_46_1)
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

  switch (pivot_46_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_95_1 > 42)
  {
    acc_1 = ((acc_1 + (threshold_95_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_95_2 > 42)
  {
    acc_2 = ((acc_2 + (threshold_95_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_83_1 = local_arr_1[aux_1 % 3];
  int parity_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_83_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_46_1 == pivot_46_2);
  assert(threshold_95_1 == threshold_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_83_1 == parity_83_2);
}

int fn_R001306_613_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001306_613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int pivot_46 = (aux + st.buffer[1]) & 3;
  switch (pivot_46)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_95 > 42)
  {
    acc = ((acc + (threshold_95 * 2)) + 5) & 127;
    aux ^= threshold_95 & 15;
  }
  else
  {
    acc = ((acc - threshold_95) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_83 = local_arr[aux % 3];
  acc = (acc + (parity_83 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001306_613_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st_1 = {0};
  struct MatrixBlock_R001306_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int offset_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_60_1)
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

  switch (offset_60_2)
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

  int damping_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_67_1) & 63;
  aux_2 = (aux_2 + damping_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_60_1 == offset_60_2);
  assert(damping_67_1 == damping_67_2);
}

int fn_R001306_613_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int offset_60 = (aux + st.buffer[1]) & 3;
  switch (offset_60)
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

  int damping_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_67) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001306_613_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st_1 = {0};
  struct MatrixBlock_R001306_613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int bound_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_56_1) & 63;
  aux_2 = (aux_2 + bound_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_51_1)
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

  switch (delta_51_2)
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

  int damping_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_32_1 > 14)
  {
    acc_1 = ((acc_1 + (damping_32_1 * 2)) + 5) & 127;
    aux_1 ^= damping_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_32_2 > 14)
  {
    acc_2 = ((acc_2 + (damping_32_2 * 2)) + 5) & 127;
    aux_2 ^= damping_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_32_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_56_1 == bound_56_2);
  assert(delta_51_1 == delta_51_2);
  assert(damping_32_1 == damping_32_2);
}

int fn_R001306_613_20(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001306_613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int bound_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_56) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_51 = (aux + st.buffer[1]) & 3;
  switch (delta_51)
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

  int damping_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_32 > 14)
  {
    acc = ((acc + (damping_32 * 2)) + 5) & 127;
    aux ^= damping_32 & 15;
  }
  else
  {
    acc = ((acc - damping_32) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001306_0_1;
  int sec_r001306_0_2;
  int sec_r001306_1_1;
  int sec_r001306_1_2;
  int sec_r001306_2_1;
  int sec_r001306_2_2;
  int sec_r001306_3_1;
  int sec_r001306_3_2;
  int sec_r001306_4_1;
  int sec_r001306_4_2;
  int sec_r001306_5_1;
  int sec_r001306_5_2;
  int sec_r001306_6_1;
  int sec_r001306_6_2;
  int sec_r001306_7_1;
  int sec_r001306_7_2;
  int sec_r001306_8_1;
  int sec_r001306_8_2;
  int sec_r001306_9_1;
  int sec_r001306_9_2;
  int sec_r001306_10_1;
  int sec_r001306_10_2;
  int sec_r001306_11_1;
  int sec_r001306_11_2;
  int sec_r001306_12_1;
  int sec_r001306_12_2;
  int sec_r001306_13_1;
  int sec_r001306_13_2;
  int sec_r001306_14_1;
  int sec_r001306_14_2;
  int sec_r001306_15_1;
  int sec_r001306_15_2;
  int sec_r001306_16_1;
  int sec_r001306_16_2;
  int sec_r001306_17_1;
  int sec_r001306_17_2;
  int sec_r001306_18_1;
  int sec_r001306_18_2;
  int sec_r001306_19_1;
  int sec_r001306_19_2;
  int sec_r001306_20_1;
  int sec_r001306_20_2;
  int sec_r001306_21_1;
  int sec_r001306_21_2;
  int pub_r001306_0_1;
  int pub_r001306_0_2;
  int pub_r001306_1_1;
  int pub_r001306_1_2;
  int pub_r001306_2_1;
  int pub_r001306_2_2;
  int pub_r001306_3_1;
  int pub_r001306_3_2;
  int pub_r001306_4_1;
  int pub_r001306_4_2;
  int pub_r001306_5_1;
  int pub_r001306_5_2;
  int pub_r001306_6_1;
  int pub_r001306_6_2;
  int pub_r001306_7_1;
  int pub_r001306_7_2;
  int pub_r001306_8_1;
  int pub_r001306_8_2;
  int pub_r001306_9_1;
  int pub_r001306_9_2;
  int pub_r001306_10_1;
  int pub_r001306_10_2;
  int pub_r001306_11_1;
  int pub_r001306_11_2;
  int pub_r001306_12_1;
  int pub_r001306_12_2;
  int pub_r001306_13_1;
  int pub_r001306_13_2;
  int pub_r001306_14_1;
  int pub_r001306_14_2;
  int pub_r001306_15_1;
  int pub_r001306_15_2;
  int pub_r001306_16_1;
  int pub_r001306_16_2;
  int pub_r001306_17_1;
  int pub_r001306_17_2;
  int pub_r001306_18_1;
  int pub_r001306_18_2;
  int pub_r001306_19_1;
  int pub_r001306_19_2;
  int pub_r001306_20_1;
  int pub_r001306_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001306_0_1 >= (-100)) && (pub_r001306_0_1 <= 100));
  __CPROVER_assume((pub_r001306_0_2 >= (-100)) && (pub_r001306_0_2 <= 100));
  __CPROVER_assume((pub_r001306_1_1 >= (-100)) && (pub_r001306_1_1 <= 100));
  __CPROVER_assume((pub_r001306_1_2 >= (-100)) && (pub_r001306_1_2 <= 100));
  __CPROVER_assume((pub_r001306_2_1 >= (-100)) && (pub_r001306_2_1 <= 100));
  __CPROVER_assume((pub_r001306_2_2 >= (-100)) && (pub_r001306_2_2 <= 100));
  __CPROVER_assume((pub_r001306_3_1 >= (-100)) && (pub_r001306_3_1 <= 100));
  __CPROVER_assume((pub_r001306_3_2 >= (-100)) && (pub_r001306_3_2 <= 100));
  __CPROVER_assume((pub_r001306_4_1 >= (-100)) && (pub_r001306_4_1 <= 100));
  __CPROVER_assume((pub_r001306_4_2 >= (-100)) && (pub_r001306_4_2 <= 100));
  __CPROVER_assume((pub_r001306_5_1 >= (-100)) && (pub_r001306_5_1 <= 100));
  __CPROVER_assume((pub_r001306_5_2 >= (-100)) && (pub_r001306_5_2 <= 100));
  __CPROVER_assume((pub_r001306_6_1 >= (-100)) && (pub_r001306_6_1 <= 100));
  __CPROVER_assume((pub_r001306_6_2 >= (-100)) && (pub_r001306_6_2 <= 100));
  __CPROVER_assume((pub_r001306_7_1 >= (-100)) && (pub_r001306_7_1 <= 100));
  __CPROVER_assume((pub_r001306_7_2 >= (-100)) && (pub_r001306_7_2 <= 100));
  __CPROVER_assume((pub_r001306_8_1 >= (-100)) && (pub_r001306_8_1 <= 100));
  __CPROVER_assume((pub_r001306_8_2 >= (-100)) && (pub_r001306_8_2 <= 100));
  __CPROVER_assume((pub_r001306_9_1 >= (-100)) && (pub_r001306_9_1 <= 100));
  __CPROVER_assume((pub_r001306_9_2 >= (-100)) && (pub_r001306_9_2 <= 100));
  __CPROVER_assume((pub_r001306_10_1 >= (-100)) && (pub_r001306_10_1 <= 100));
  __CPROVER_assume((pub_r001306_10_2 >= (-100)) && (pub_r001306_10_2 <= 100));
  __CPROVER_assume((pub_r001306_11_1 >= (-100)) && (pub_r001306_11_1 <= 100));
  __CPROVER_assume((pub_r001306_11_2 >= (-100)) && (pub_r001306_11_2 <= 100));
  __CPROVER_assume((pub_r001306_12_1 >= (-100)) && (pub_r001306_12_1 <= 100));
  __CPROVER_assume((pub_r001306_12_2 >= (-100)) && (pub_r001306_12_2 <= 100));
  __CPROVER_assume((pub_r001306_13_1 >= (-100)) && (pub_r001306_13_1 <= 100));
  __CPROVER_assume((pub_r001306_13_2 >= (-100)) && (pub_r001306_13_2 <= 100));
  __CPROVER_assume((pub_r001306_14_1 >= (-100)) && (pub_r001306_14_1 <= 100));
  __CPROVER_assume((pub_r001306_14_2 >= (-100)) && (pub_r001306_14_2 <= 100));
  __CPROVER_assume((pub_r001306_15_1 >= (-100)) && (pub_r001306_15_1 <= 100));
  __CPROVER_assume((pub_r001306_15_2 >= (-100)) && (pub_r001306_15_2 <= 100));
  __CPROVER_assume((pub_r001306_16_1 >= (-100)) && (pub_r001306_16_1 <= 100));
  __CPROVER_assume((pub_r001306_16_2 >= (-100)) && (pub_r001306_16_2 <= 100));
  __CPROVER_assume((pub_r001306_17_1 >= (-100)) && (pub_r001306_17_1 <= 100));
  __CPROVER_assume((pub_r001306_17_2 >= (-100)) && (pub_r001306_17_2 <= 100));
  __CPROVER_assume((pub_r001306_18_1 >= (-100)) && (pub_r001306_18_1 <= 100));
  __CPROVER_assume((pub_r001306_18_2 >= (-100)) && (pub_r001306_18_2 <= 100));
  __CPROVER_assume((pub_r001306_19_1 >= (-100)) && (pub_r001306_19_1 <= 100));
  __CPROVER_assume((pub_r001306_19_2 >= (-100)) && (pub_r001306_19_2 <= 100));
  __CPROVER_assume((pub_r001306_20_1 >= (-100)) && (pub_r001306_20_1 <= 100));
  __CPROVER_assume((pub_r001306_20_2 >= (-100)) && (pub_r001306_20_2 <= 100));
  __CPROVER_assume((sec_r001306_0_1 >= 0) && (sec_r001306_0_1 <= 255));
  __CPROVER_assume((sec_r001306_0_2 >= 0) && (sec_r001306_0_2 <= 255));
  __CPROVER_assume((sec_r001306_1_1 >= 0) && (sec_r001306_1_1 <= 255));
  __CPROVER_assume((sec_r001306_1_2 >= 0) && (sec_r001306_1_2 <= 255));
  __CPROVER_assume((sec_r001306_2_1 >= 0) && (sec_r001306_2_1 <= 255));
  __CPROVER_assume((sec_r001306_2_2 >= 0) && (sec_r001306_2_2 <= 255));
  __CPROVER_assume((sec_r001306_3_1 >= 0) && (sec_r001306_3_1 <= 255));
  __CPROVER_assume((sec_r001306_3_2 >= 0) && (sec_r001306_3_2 <= 255));
  __CPROVER_assume((sec_r001306_4_1 >= 0) && (sec_r001306_4_1 <= 255));
  __CPROVER_assume((sec_r001306_4_2 >= 0) && (sec_r001306_4_2 <= 255));
  __CPROVER_assume((sec_r001306_5_1 >= 0) && (sec_r001306_5_1 <= 255));
  __CPROVER_assume((sec_r001306_5_2 >= 0) && (sec_r001306_5_2 <= 255));
  __CPROVER_assume((sec_r001306_6_1 >= 0) && (sec_r001306_6_1 <= 255));
  __CPROVER_assume((sec_r001306_6_2 >= 0) && (sec_r001306_6_2 <= 255));
  __CPROVER_assume((sec_r001306_7_1 >= 0) && (sec_r001306_7_1 <= 255));
  __CPROVER_assume((sec_r001306_7_2 >= 0) && (sec_r001306_7_2 <= 255));
  __CPROVER_assume((sec_r001306_8_1 >= 0) && (sec_r001306_8_1 <= 255));
  __CPROVER_assume((sec_r001306_8_2 >= 0) && (sec_r001306_8_2 <= 255));
  __CPROVER_assume((sec_r001306_9_1 >= 0) && (sec_r001306_9_1 <= 255));
  __CPROVER_assume((sec_r001306_9_2 >= 0) && (sec_r001306_9_2 <= 255));
  __CPROVER_assume((sec_r001306_10_1 >= 0) && (sec_r001306_10_1 <= 255));
  __CPROVER_assume((sec_r001306_10_2 >= 0) && (sec_r001306_10_2 <= 255));
  __CPROVER_assume((sec_r001306_11_1 >= 0) && (sec_r001306_11_1 <= 255));
  __CPROVER_assume((sec_r001306_11_2 >= 0) && (sec_r001306_11_2 <= 255));
  __CPROVER_assume((sec_r001306_12_1 >= 0) && (sec_r001306_12_1 <= 255));
  __CPROVER_assume((sec_r001306_12_2 >= 0) && (sec_r001306_12_2 <= 255));
  __CPROVER_assume((sec_r001306_13_1 >= 0) && (sec_r001306_13_1 <= 255));
  __CPROVER_assume((sec_r001306_13_2 >= 0) && (sec_r001306_13_2 <= 255));
  __CPROVER_assume((sec_r001306_14_1 >= 0) && (sec_r001306_14_1 <= 255));
  __CPROVER_assume((sec_r001306_14_2 >= 0) && (sec_r001306_14_2 <= 255));
  __CPROVER_assume((sec_r001306_15_1 >= 0) && (sec_r001306_15_1 <= 255));
  __CPROVER_assume((sec_r001306_15_2 >= 0) && (sec_r001306_15_2 <= 255));
  __CPROVER_assume((sec_r001306_16_1 >= 0) && (sec_r001306_16_1 <= 255));
  __CPROVER_assume((sec_r001306_16_2 >= 0) && (sec_r001306_16_2 <= 255));
  __CPROVER_assume((sec_r001306_17_1 >= 0) && (sec_r001306_17_1 <= 255));
  __CPROVER_assume((sec_r001306_17_2 >= 0) && (sec_r001306_17_2 <= 255));
  __CPROVER_assume((sec_r001306_18_1 >= 0) && (sec_r001306_18_1 <= 255));
  __CPROVER_assume((sec_r001306_18_2 >= 0) && (sec_r001306_18_2 <= 255));
  __CPROVER_assume((sec_r001306_19_1 >= 0) && (sec_r001306_19_1 <= 255));
  __CPROVER_assume((sec_r001306_19_2 >= 0) && (sec_r001306_19_2 <= 255));
  __CPROVER_assume((sec_r001306_20_1 >= 0) && (sec_r001306_20_1 <= 255));
  __CPROVER_assume((sec_r001306_20_2 >= 0) && (sec_r001306_20_2 <= 255));
  __CPROVER_assume((sec_r001306_21_1 >= 0) && (sec_r001306_21_1 <= 255));
  __CPROVER_assume((sec_r001306_21_2 >= 0) && (sec_r001306_21_2 <= 255));
  struct MatrixBlock_R001306_613_0 st_var_0_1 = {0};
  struct MatrixBlock_R001306_613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001306_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001306_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001306_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001306_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001306_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001306_0_2 + 7) & 15;
  struct CipherContext_R001306_613_1 st_var_1_1 = {0};
  struct CipherContext_R001306_613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001306_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001306_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001306_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001306_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001306_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001306_0_2 + 9) & 15;
  union TelemetryField_R001306_613_0 u_var_1;
  union TelemetryField_R001306_613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001306_613_0(sec_r001306_0_1, sec_r001306_1_1, pub_r001306_2_1, pub_r001306_3_1);
  int helper_flow_0_2 = fn_R001306_613_0(sec_r001306_0_2, sec_r001306_1_2, pub_r001306_2_2, pub_r001306_3_2);
  fn_R001306_613_0_2(sec_r001306_0_1, sec_r001306_1_1, pub_r001306_2_1, pub_r001306_3_1, sec_r001306_0_2, sec_r001306_1_2, pub_r001306_2_2, pub_r001306_3_2);
  int helper_flow_1_1 = fn_R001306_613_1(sec_r001306_1_1, sec_r001306_2_1, pub_r001306_3_1, pub_r001306_4_1);
  int helper_flow_1_2 = fn_R001306_613_1(sec_r001306_1_2, sec_r001306_2_2, pub_r001306_3_2, pub_r001306_4_2);
  fn_R001306_613_1_2(sec_r001306_1_1, sec_r001306_2_1, pub_r001306_3_1, pub_r001306_4_1, sec_r001306_1_2, sec_r001306_2_2, pub_r001306_3_2, pub_r001306_4_2);
  int helper_flow_2_1 = fn_R001306_613_2(sec_r001306_2_1, sec_r001306_3_1);
  int helper_flow_2_2 = fn_R001306_613_2(sec_r001306_2_2, sec_r001306_3_2);
  fn_R001306_613_2_2(sec_r001306_2_1, sec_r001306_3_1, sec_r001306_2_2, sec_r001306_3_2);
  int helper_flow_3_1 = fn_R001306_613_3(sec_r001306_3_1, sec_r001306_4_1, pub_r001306_5_1, pub_r001306_6_1);
  int helper_flow_3_2 = fn_R001306_613_3(sec_r001306_3_2, sec_r001306_4_2, pub_r001306_5_2, pub_r001306_6_2);
  fn_R001306_613_3_2(sec_r001306_3_1, sec_r001306_4_1, pub_r001306_5_1, pub_r001306_6_1, sec_r001306_3_2, sec_r001306_4_2, pub_r001306_5_2, pub_r001306_6_2);
  int helper_flow_4_1 = fn_R001306_613_4(sec_r001306_4_1, pub_r001306_5_1);
  int helper_flow_4_2 = fn_R001306_613_4(sec_r001306_4_2, pub_r001306_5_2);
  fn_R001306_613_4_2(sec_r001306_4_1, pub_r001306_5_1, sec_r001306_4_2, pub_r001306_5_2);
  int helper_flow_5_1 = fn_R001306_613_5(sec_r001306_5_1, sec_r001306_6_1, pub_r001306_7_1, pub_r001306_8_1);
  int helper_flow_5_2 = fn_R001306_613_5(sec_r001306_5_2, sec_r001306_6_2, pub_r001306_7_2, pub_r001306_8_2);
  fn_R001306_613_5_2(sec_r001306_5_1, sec_r001306_6_1, pub_r001306_7_1, pub_r001306_8_1, sec_r001306_5_2, sec_r001306_6_2, pub_r001306_7_2, pub_r001306_8_2);
  int helper_flow_6_1 = fn_R001306_613_6(sec_r001306_6_1, sec_r001306_7_1, pub_r001306_8_1, pub_r001306_9_1, pub_r001306_10_1);
  int helper_flow_6_2 = fn_R001306_613_6(sec_r001306_6_2, sec_r001306_7_2, pub_r001306_8_2, pub_r001306_9_2, pub_r001306_10_2);
  fn_R001306_613_6_2(sec_r001306_6_1, sec_r001306_7_1, pub_r001306_8_1, pub_r001306_9_1, pub_r001306_10_1, sec_r001306_6_2, sec_r001306_7_2, pub_r001306_8_2, pub_r001306_9_2, pub_r001306_10_2);
  int helper_flow_7_1 = fn_R001306_613_7(sec_r001306_7_1, pub_r001306_8_1, pub_r001306_9_1);
  int helper_flow_7_2 = fn_R001306_613_7(sec_r001306_7_2, pub_r001306_8_2, pub_r001306_9_2);
  fn_R001306_613_7_2(sec_r001306_7_1, pub_r001306_8_1, pub_r001306_9_1, sec_r001306_7_2, pub_r001306_8_2, pub_r001306_9_2);
  int helper_flow_8_1 = fn_R001306_613_8(sec_r001306_8_1, pub_r001306_9_1);
  int helper_flow_8_2 = fn_R001306_613_8(sec_r001306_8_2, pub_r001306_9_2);
  fn_R001306_613_8_2(sec_r001306_8_1, pub_r001306_9_1, sec_r001306_8_2, pub_r001306_9_2);
  int helper_flow_9_1 = fn_R001306_613_9(sec_r001306_9_1, sec_r001306_10_1, pub_r001306_11_1, pub_r001306_12_1);
  int helper_flow_9_2 = fn_R001306_613_9(sec_r001306_9_2, sec_r001306_10_2, pub_r001306_11_2, pub_r001306_12_2);
  fn_R001306_613_9_2(sec_r001306_9_1, sec_r001306_10_1, pub_r001306_11_1, pub_r001306_12_1, sec_r001306_9_2, sec_r001306_10_2, pub_r001306_11_2, pub_r001306_12_2);
  int stage_v_0_1 = ((sec_r001306_1_1 + (pub_r001306_6_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((sec_r001306_1_2 + (pub_r001306_6_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((pub_r001306_12_1 * 2) + 37) & 63;
  int stage_v_1_2 = ((pub_r001306_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001306_17_1 * 2) + 14) & 63;
  int stage_v_2_2 = ((pub_r001306_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001306_20_1 * 2) + 32) & 63;
  int stage_v_3_2 = ((pub_r001306_20_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((helper_flow_7_1 + (pub_r001306_11_1 * 2)) + 17) & 127;
  int stage_v_4_2 = ((helper_flow_7_2 + (pub_r001306_11_2 * 2)) + 17) & 127;
  if (stage_v_4_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_4_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_4_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_4_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_5_1 = ((pub_r001306_9_1 * 2) + 42) & 63;
  int stage_v_5_2 = ((pub_r001306_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001306_5_1 * 2) + 23) & 63;
  int stage_v_6_2 = ((pub_r001306_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((helper_flow_8_1 + (pub_r001306_3_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((helper_flow_8_2 + (pub_r001306_3_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((helper_flow_9_1 + (pub_r001306_14_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((helper_flow_9_2 + (pub_r001306_14_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((pub_r001306_0_1 * 2) + 23) & 63;
  int stage_v_9_2 = ((pub_r001306_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((sec_r001306_20_1 + (pub_r001306_14_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((sec_r001306_20_2 + (pub_r001306_14_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((helper_flow_1_1 + (pub_r001306_7_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((helper_flow_1_2 + (pub_r001306_7_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((helper_flow_5_1 + (pub_r001306_7_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((helper_flow_5_2 + (pub_r001306_7_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((sec_r001306_14_1 + (pub_r001306_9_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((sec_r001306_14_2 + (pub_r001306_9_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((pub_r001306_3_1 * 2) + 39) & 63;
  int stage_v_14_2 = ((pub_r001306_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001306_4_1 * 2) + 10) & 63;
  int stage_v_15_2 = ((pub_r001306_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((sec_r001306_8_1 + (pub_r001306_18_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((sec_r001306_8_2 + (pub_r001306_18_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((sec_r001306_14_1 + (pub_r001306_9_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001306_14_2 + (pub_r001306_9_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((helper_flow_4_1 + (pub_r001306_9_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((helper_flow_4_2 + (pub_r001306_9_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((sec_r001306_8_1 + (pub_r001306_18_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((sec_r001306_8_2 + (pub_r001306_18_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((stage_v_7_1 + (pub_r001306_17_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((stage_v_7_2 + (pub_r001306_17_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((stage_v_13_1 + (pub_r001306_14_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((stage_v_13_2 + (pub_r001306_14_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((sec_r001306_16_1 + (pub_r001306_14_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((sec_r001306_16_2 + (pub_r001306_14_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((pub_r001306_14_1 * 2) + 31) & 63;
  int stage_v_23_2 = ((pub_r001306_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((sec_r001306_15_1 + (pub_r001306_17_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((sec_r001306_15_2 + (pub_r001306_17_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((pub_r001306_5_1 * 2) + 36) & 63;
  int stage_v_25_2 = ((pub_r001306_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001306_20_1 * 2) + 25) & 63;
  int stage_v_26_2 = ((pub_r001306_20_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((sec_r001306_8_1 + (pub_r001306_5_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((sec_r001306_8_2 + (pub_r001306_5_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((pub_r001306_5_1 * 2) + 38) & 63;
  int stage_v_28_2 = ((pub_r001306_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((stage_v_4_1 + (pub_r001306_19_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((stage_v_4_2 + (pub_r001306_19_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((stage_v_7_1 + (pub_r001306_9_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((stage_v_7_2 + (pub_r001306_9_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((stage_v_16_1 + (pub_r001306_15_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((stage_v_16_2 + (pub_r001306_15_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((stage_v_7_1 + (pub_r001306_9_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((stage_v_7_2 + (pub_r001306_9_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((pub_r001306_20_1 * 2) + 9) & 63;
  int stage_v_33_2 = ((pub_r001306_20_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001306_8_1 * 2) + 16) & 63;
  int stage_v_34_2 = ((pub_r001306_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((helper_flow_9_1 + (pub_r001306_10_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((helper_flow_9_2 + (pub_r001306_10_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((stage_v_18_1 + (pub_r001306_2_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((stage_v_18_2 + (pub_r001306_2_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((helper_flow_5_1 + (pub_r001306_0_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((helper_flow_5_2 + (pub_r001306_0_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((sec_r001306_14_1 + (pub_r001306_4_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((sec_r001306_14_2 + (pub_r001306_4_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((pub_r001306_14_1 * 2) + 29) & 63;
  int stage_v_39_2 = ((pub_r001306_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((stage_v_32_1 + (pub_r001306_0_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((stage_v_32_2 + (pub_r001306_0_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((sec_r001306_17_1 + (pub_r001306_18_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((sec_r001306_17_2 + (pub_r001306_18_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((sec_r001306_15_1 + (pub_r001306_15_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((sec_r001306_15_2 + (pub_r001306_15_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((sec_r001306_3_1 + (pub_r001306_20_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((sec_r001306_3_2 + (pub_r001306_20_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((pub_r001306_10_1 * 2) + 47) & 63;
  int stage_v_44_2 = ((pub_r001306_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((stage_v_0_1 + (pub_r001306_6_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((stage_v_0_2 + (pub_r001306_6_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((sec_r001306_10_1 + (pub_r001306_20_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((sec_r001306_10_2 + (pub_r001306_20_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((pub_r001306_8_1 * 2) + 31) & 63;
  int stage_v_47_2 = ((pub_r001306_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001306_11_1 * 2) + 15) & 63;
  int stage_v_48_2 = ((pub_r001306_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001306_8_1 * 2) + 29) & 63;
  int stage_v_49_2 = ((pub_r001306_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001306_20_1 * 2) + 39) & 63;
  int stage_v_50_2 = ((pub_r001306_20_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001306_3_1 * 2) + 18) & 63;
  int stage_v_51_2 = ((pub_r001306_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((stage_v_40_1 + (pub_r001306_0_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((stage_v_40_2 + (pub_r001306_0_2 * 2)) + 161) & 127;
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
  int stage_v_53_1 = ((sec_r001306_21_1 + (pub_r001306_17_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((sec_r001306_21_2 + (pub_r001306_17_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((stage_v_29_1 + (pub_r001306_19_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((stage_v_29_2 + (pub_r001306_19_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((stage_v_32_1 + (pub_r001306_14_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((stage_v_32_2 + (pub_r001306_14_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((pub_r001306_5_1 * 2) + 35) & 63;
  int stage_v_56_2 = ((pub_r001306_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((sec_r001306_3_1 + (pub_r001306_2_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((sec_r001306_3_2 + (pub_r001306_2_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((helper_flow_6_1 + (pub_r001306_5_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((helper_flow_6_2 + (pub_r001306_5_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((sec_r001306_8_1 + (pub_r001306_1_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((sec_r001306_8_2 + (pub_r001306_1_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((helper_flow_1_1 + (pub_r001306_8_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((helper_flow_1_2 + (pub_r001306_8_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((pub_r001306_9_1 * 2) + 21) & 63;
  int stage_v_61_2 = ((pub_r001306_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001306_11_1 * 2) + 19) & 63;
  int stage_v_62_2 = ((pub_r001306_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((stage_v_12_1 + (pub_r001306_6_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((stage_v_12_2 + (pub_r001306_6_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((sec_r001306_6_1 + (pub_r001306_6_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((sec_r001306_6_2 + (pub_r001306_6_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((sec_r001306_13_1 + (pub_r001306_3_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((sec_r001306_13_2 + (pub_r001306_3_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((stage_v_52_1 + (pub_r001306_16_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((stage_v_52_2 + (pub_r001306_16_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((stage_v_31_1 + (pub_r001306_11_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((stage_v_31_2 + (pub_r001306_11_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((pub_r001306_3_1 * 2) + 40) & 63;
  int stage_v_68_2 = ((pub_r001306_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001306_11_1 * 2) + 48) & 63;
  int stage_v_69_2 = ((pub_r001306_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((stage_v_10_1 + (pub_r001306_10_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((stage_v_10_2 + (pub_r001306_10_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((stage_v_13_1 + (pub_r001306_17_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_13_2 + (pub_r001306_17_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((pub_r001306_10_1 * 2) + 25) & 63;
  int stage_v_72_2 = ((pub_r001306_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001306_17_1 * 2) + 44) & 63;
  int stage_v_73_2 = ((pub_r001306_17_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((sec_r001306_13_1 + (pub_r001306_5_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((sec_r001306_13_2 + (pub_r001306_5_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((pub_r001306_14_1 * 2) + 17) & 63;
  int stage_v_75_2 = ((pub_r001306_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001306_15_1 * 2) + 32) & 63;
  int stage_v_76_2 = ((pub_r001306_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001306_1_1 * 2) + 45) & 63;
  int stage_v_77_2 = ((pub_r001306_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((stage_v_27_1 + (pub_r001306_12_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_27_2 + (pub_r001306_12_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((stage_v_18_1 + (pub_r001306_8_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((stage_v_18_2 + (pub_r001306_8_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((stage_v_30_1 + (pub_r001306_20_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((stage_v_30_2 + (pub_r001306_20_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((pub_r001306_6_1 * 2) + 42) & 63;
  int stage_v_81_2 = ((pub_r001306_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((sec_r001306_15_1 + (pub_r001306_3_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((sec_r001306_15_2 + (pub_r001306_3_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((pub_r001306_19_1 * 2) + 46) & 63;
  int stage_v_83_2 = ((pub_r001306_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001306_9_1 * 2) + 36) & 63;
  int stage_v_84_2 = ((pub_r001306_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((helper_flow_9_1 + (pub_r001306_6_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((helper_flow_9_2 + (pub_r001306_6_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((stage_v_41_1 + (pub_r001306_15_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_41_2 + (pub_r001306_15_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((helper_flow_2_1 + (pub_r001306_14_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((helper_flow_2_2 + (pub_r001306_14_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((sec_r001306_19_1 + (pub_r001306_8_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((sec_r001306_19_2 + (pub_r001306_8_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((stage_v_19_1 + (pub_r001306_5_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((stage_v_19_2 + (pub_r001306_5_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((stage_v_32_1 + (pub_r001306_1_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((stage_v_32_2 + (pub_r001306_1_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((sec_r001306_1_1 + (pub_r001306_18_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((sec_r001306_1_2 + (pub_r001306_18_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((stage_v_32_1 + (pub_r001306_9_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((stage_v_32_2 + (pub_r001306_9_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((helper_flow_5_1 + (pub_r001306_0_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((helper_flow_5_2 + (pub_r001306_0_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((stage_v_89_1 + (pub_r001306_10_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_89_2 + (pub_r001306_10_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((pub_r001306_5_1 * 2) + 15) & 63;
  int stage_v_95_2 = ((pub_r001306_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001306_11_1 * 2) + 36) & 63;
  int stage_v_96_2 = ((pub_r001306_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001306_5_1 * 2) + 34) & 63;
  int stage_v_97_2 = ((pub_r001306_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((sec_r001306_0_1 + (pub_r001306_2_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((sec_r001306_0_2 + (pub_r001306_2_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((sec_r001306_18_1 + (pub_r001306_0_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((sec_r001306_18_2 + (pub_r001306_0_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((stage_v_66_1 + (pub_r001306_0_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((stage_v_66_2 + (pub_r001306_0_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((stage_v_10_1 + (pub_r001306_14_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((stage_v_10_2 + (pub_r001306_14_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((stage_v_46_1 + (pub_r001306_13_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_46_2 + (pub_r001306_13_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((stage_v_37_1 + (pub_r001306_14_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_37_2 + (pub_r001306_14_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((pub_r001306_1_1 * 2) + 16) & 63;
  int stage_v_104_2 = ((pub_r001306_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001306_1_1 * 2) + 33) & 63;
  int stage_v_105_2 = ((pub_r001306_1_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((stage_v_12_1 + (pub_r001306_13_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_12_2 + (pub_r001306_13_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((pub_r001306_6_1 * 2) + 14) & 63;
  int stage_v_107_2 = ((pub_r001306_6_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001306_20_1 * 2) + 30) & 63;
  int stage_v_108_2 = ((pub_r001306_20_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((stage_v_79_1 + (pub_r001306_7_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_79_2 + (pub_r001306_7_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((stage_v_12_1 + (pub_r001306_20_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((stage_v_12_2 + (pub_r001306_20_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((sec_r001306_6_1 + (pub_r001306_16_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((sec_r001306_6_2 + (pub_r001306_16_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((helper_flow_5_1 + (pub_r001306_19_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((helper_flow_5_2 + (pub_r001306_19_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((pub_r001306_17_1 * 2) + 15) & 63;
  int stage_v_113_2 = ((pub_r001306_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((stage_v_110_1 + (pub_r001306_12_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((stage_v_110_2 + (pub_r001306_12_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((stage_v_4_1 + (pub_r001306_6_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_4_2 + (pub_r001306_6_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((stage_v_66_1 + (pub_r001306_2_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_66_2 + (pub_r001306_2_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((pub_r001306_0_1 * 2) + 44) & 63;
  int stage_v_117_2 = ((pub_r001306_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001306_1_1 * 2) + 20) & 63;
  int stage_v_118_2 = ((pub_r001306_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((helper_flow_6_1 + (pub_r001306_13_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((helper_flow_6_2 + (pub_r001306_13_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((stage_v_53_1 + (pub_r001306_2_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_53_2 + (pub_r001306_2_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((pub_r001306_13_1 * 2) + 18) & 63;
  int stage_v_121_2 = ((pub_r001306_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001306_0_1 * 2) + 19) & 63;
  int stage_v_122_2 = ((pub_r001306_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001306_5_1 * 2) + 49) & 63;
  int stage_v_123_2 = ((pub_r001306_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001306_19_1 * 2) + 16) & 63;
  int stage_v_124_2 = ((pub_r001306_19_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((stage_v_59_1 + (pub_r001306_1_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_59_2 + (pub_r001306_1_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((stage_v_112_1 + (pub_r001306_12_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_112_2 + (pub_r001306_12_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((stage_v_111_1 + (pub_r001306_20_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((stage_v_111_2 + (pub_r001306_20_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((sec_r001306_0_1 + (pub_r001306_2_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((sec_r001306_0_2 + (pub_r001306_2_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((stage_v_106_1 + (pub_r001306_20_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((stage_v_106_2 + (pub_r001306_20_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((sec_r001306_17_1 + (pub_r001306_10_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((sec_r001306_17_2 + (pub_r001306_10_2 * 2)) + 395) & 127;
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
  int stage_v_131_1 = ((stage_v_27_1 + (pub_r001306_7_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((stage_v_27_2 + (pub_r001306_7_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((pub_r001306_9_1 * 2) + 46) & 63;
  int stage_v_132_2 = ((pub_r001306_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((stage_v_17_1 + (pub_r001306_6_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((stage_v_17_2 + (pub_r001306_6_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((pub_r001306_12_1 * 2) + 46) & 63;
  int stage_v_134_2 = ((pub_r001306_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((stage_v_59_1 + (pub_r001306_19_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_59_2 + (pub_r001306_19_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((stage_v_36_1 + (pub_r001306_7_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_36_2 + (pub_r001306_7_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((pub_r001306_16_1 * 2) + 34) & 63;
  int stage_v_137_2 = ((pub_r001306_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((helper_flow_5_1 + (pub_r001306_2_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((helper_flow_5_2 + (pub_r001306_2_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((helper_flow_4_1 + (pub_r001306_19_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((helper_flow_4_2 + (pub_r001306_19_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((pub_r001306_8_1 * 2) + 47) & 63;
  int stage_v_140_2 = ((pub_r001306_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001306_1_1 * 2) + 37) & 63;
  int stage_v_141_2 = ((pub_r001306_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001306_0_1 * 2) + 18) & 63;
  int stage_v_142_2 = ((pub_r001306_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((stage_v_88_1 + (pub_r001306_20_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_88_2 + (pub_r001306_20_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((helper_flow_7_1 + (pub_r001306_20_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((helper_flow_7_2 + (pub_r001306_20_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((pub_r001306_7_1 * 2) + 33) & 63;
  int stage_v_145_2 = ((pub_r001306_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001306_5_1 * 2) + 17) & 63;
  int stage_v_146_2 = ((pub_r001306_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001306_10_1 * 2) + 18) & 63;
  int stage_v_147_2 = ((pub_r001306_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((stage_v_138_1 + (pub_r001306_3_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_138_2 + (pub_r001306_3_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((pub_r001306_11_1 * 2) + 11) & 63;
  int stage_v_149_2 = ((pub_r001306_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((sec_r001306_0_1 + (pub_r001306_4_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((sec_r001306_0_2 + (pub_r001306_4_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((stage_v_90_1 + (pub_r001306_7_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_90_2 + (pub_r001306_7_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((pub_r001306_19_1 * 2) + 42) & 63;
  int stage_v_152_2 = ((pub_r001306_19_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((stage_v_90_1 + (pub_r001306_2_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_90_2 + (pub_r001306_2_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((pub_r001306_19_1 * 2) + 27) & 63;
  int stage_v_154_2 = ((pub_r001306_19_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001306_8_1 * 2) + 46) & 63;
  int stage_v_155_2 = ((pub_r001306_8_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001306_1_1 * 2) + 50) & 63;
  int stage_v_156_2 = ((pub_r001306_1_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((stage_v_138_1 + (pub_r001306_14_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_138_2 + (pub_r001306_14_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((stage_v_138_1 + (pub_r001306_17_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_138_2 + (pub_r001306_17_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((pub_r001306_19_1 * 2) + 23) & 63;
  int stage_v_159_2 = ((pub_r001306_19_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001306_19_1 * 2) + 46) & 63;
  int stage_v_160_2 = ((pub_r001306_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001306_10_1 * 2) + 35) & 63;
  int stage_v_161_2 = ((pub_r001306_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001306_1_1 * 2) + 19) & 63;
  int stage_v_162_2 = ((pub_r001306_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((stage_v_36_1 + (pub_r001306_16_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_36_2 + (pub_r001306_16_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((pub_r001306_8_1 * 2) + 7) & 63;
  int stage_v_164_2 = ((pub_r001306_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((sec_r001306_11_1 + (pub_r001306_11_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((sec_r001306_11_2 + (pub_r001306_11_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((stage_v_98_1 + (pub_r001306_20_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_98_2 + (pub_r001306_20_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((stage_v_89_1 + (pub_r001306_16_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_89_2 + (pub_r001306_16_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_143_1 + (pub_r001306_17_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_143_2 + (pub_r001306_17_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((stage_v_148_1 + (pub_r001306_2_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_148_2 + (pub_r001306_2_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((stage_v_0_1 + (pub_r001306_12_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((stage_v_0_2 + (pub_r001306_12_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((stage_v_21_1 + (pub_r001306_16_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((stage_v_21_2 + (pub_r001306_16_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((pub_r001306_5_1 * 2) + 48) & 63;
  int stage_v_172_2 = ((pub_r001306_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((stage_v_94_1 + (pub_r001306_12_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_94_2 + (pub_r001306_12_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((pub_r001306_7_1 * 2) + 36) & 63;
  int stage_v_174_2 = ((pub_r001306_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((helper_flow_0_1 + (pub_r001306_6_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((helper_flow_0_2 + (pub_r001306_6_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((stage_v_91_1 + (pub_r001306_2_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((stage_v_91_2 + (pub_r001306_2_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((helper_flow_3_1 + (pub_r001306_15_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((helper_flow_3_2 + (pub_r001306_15_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((stage_v_85_1 + (pub_r001306_1_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_85_2 + (pub_r001306_1_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((pub_r001306_3_1 * 2) + 38) & 63;
  int stage_v_179_2 = ((pub_r001306_3_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((helper_flow_6_1 + (pub_r001306_6_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((helper_flow_6_2 + (pub_r001306_6_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((pub_r001306_0_1 * 2) + 17) & 63;
  int stage_v_181_2 = ((pub_r001306_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((stage_v_42_1 + (pub_r001306_1_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_42_2 + (pub_r001306_1_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((pub_r001306_9_1 * 2) + 25) & 63;
  int stage_v_183_2 = ((pub_r001306_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((helper_flow_2_1 + (pub_r001306_14_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((helper_flow_2_2 + (pub_r001306_14_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((pub_r001306_20_1 * 2) + 45) & 63;
  int stage_v_185_2 = ((pub_r001306_20_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001306_14_1 * 2) + 12) & 63;
  int stage_v_186_2 = ((pub_r001306_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((stage_v_110_1 + (pub_r001306_2_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_110_2 + (pub_r001306_2_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((pub_r001306_1_1 * 2) + 40) & 63;
  int stage_v_188_2 = ((pub_r001306_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001306_4_1 * 2) + 28) & 63;
  int stage_v_189_2 = ((pub_r001306_4_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001306_8_1 * 2) + 21) & 63;
  int stage_v_190_2 = ((pub_r001306_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((helper_flow_1_1 + (pub_r001306_13_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((helper_flow_1_2 + (pub_r001306_13_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((helper_flow_0_1 + (pub_r001306_20_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((helper_flow_0_2 + (pub_r001306_20_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((pub_r001306_13_1 * 2) + 17) & 63;
  int stage_v_193_2 = ((pub_r001306_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((sec_r001306_12_1 + (pub_r001306_10_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((sec_r001306_12_2 + (pub_r001306_10_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((stage_v_109_1 + (pub_r001306_9_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_109_2 + (pub_r001306_9_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((pub_r001306_15_1 * 2) + 17) & 63;
  int stage_v_196_2 = ((pub_r001306_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((stage_v_52_1 + (pub_r001306_4_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_52_2 + (pub_r001306_4_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((pub_r001306_6_1 * 2) + 29) & 63;
  int stage_v_198_2 = ((pub_r001306_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001306_8_1 * 2) + 19) & 63;
  int stage_v_199_2 = ((pub_r001306_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((stage_v_167_1 + (pub_r001306_3_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_167_2 + (pub_r001306_3_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((sec_r001306_12_1 + (pub_r001306_3_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((sec_r001306_12_2 + (pub_r001306_3_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((stage_v_31_1 + (pub_r001306_15_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_31_2 + (pub_r001306_15_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((pub_r001306_2_1 * 2) + 34) & 63;
  int stage_v_203_2 = ((pub_r001306_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001306_18_1 * 2) + 43) & 63;
  int stage_v_204_2 = ((pub_r001306_18_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((stage_v_114_1 + (pub_r001306_8_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_114_2 + (pub_r001306_8_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((stage_v_197_1 + (pub_r001306_20_1 * 2)) + 623) & 127;
  int stage_v_206_2 = ((stage_v_197_2 + (pub_r001306_20_2 * 2)) + 623) & 127;
  if (stage_v_206_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_206_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_206_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_206_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_207_1 = ((stage_v_205_1 + (pub_r001306_11_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((stage_v_205_2 + (pub_r001306_11_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((stage_v_176_1 + (pub_r001306_11_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_176_2 + (pub_r001306_11_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((stage_v_150_1 + (pub_r001306_13_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_150_2 + (pub_r001306_13_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((pub_r001306_15_1 * 2) + 26) & 63;
  int stage_v_210_2 = ((pub_r001306_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((stage_v_80_1 + (pub_r001306_2_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((stage_v_80_2 + (pub_r001306_2_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((pub_r001306_9_1 * 2) + 20) & 63;
  int stage_v_212_2 = ((pub_r001306_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((stage_v_22_1 + (pub_r001306_20_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((stage_v_22_2 + (pub_r001306_20_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((pub_r001306_15_1 * 2) + 29) & 63;
  int stage_v_214_2 = ((pub_r001306_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001306_15_1 * 2) + 15) & 63;
  int stage_v_215_2 = ((pub_r001306_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((stage_v_20_1 + (pub_r001306_19_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((stage_v_20_2 + (pub_r001306_19_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_217_1 = ((stage_v_173_1 + (pub_r001306_14_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((stage_v_173_2 + (pub_r001306_14_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((stage_v_53_1 + (pub_r001306_7_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_53_2 + (pub_r001306_7_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((stage_v_20_1 + (pub_r001306_18_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((stage_v_20_2 + (pub_r001306_18_2 * 2)) + 662) & 127;
  if (stage_v_219_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_219_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_219_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_219_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_220_1 = ((pub_r001306_8_1 * 2) + 41) & 63;
  int stage_v_220_2 = ((pub_r001306_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((helper_flow_1_1 + (pub_r001306_7_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((helper_flow_1_2 + (pub_r001306_7_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((stage_v_80_1 + (pub_r001306_7_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((stage_v_80_2 + (pub_r001306_7_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((stage_v_216_1 + (pub_r001306_14_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((stage_v_216_2 + (pub_r001306_14_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((stage_v_111_1 + (pub_r001306_6_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((stage_v_111_2 + (pub_r001306_6_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_225_1 = ((stage_v_20_1 + (pub_r001306_15_1 * 2)) + 680) & 127;
  int stage_v_225_2 = ((stage_v_20_2 + (pub_r001306_15_2 * 2)) + 680) & 127;
  if (stage_v_225_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_225_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_225_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_225_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_226_1 = ((stage_v_98_1 + (pub_r001306_4_1 * 2)) + 683) & 127;
  int stage_v_226_2 = ((stage_v_98_2 + (pub_r001306_4_2 * 2)) + 683) & 127;
  if (stage_v_226_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_226_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_226_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_226_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_227_1 = ((pub_r001306_5_1 * 2) + 39) & 63;
  int stage_v_227_2 = ((pub_r001306_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001306_1_1 * 2) + 34) & 63;
  int stage_v_228_2 = ((pub_r001306_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((stage_v_71_1 + (pub_r001306_1_1 * 2)) + 692) & 127;
  int stage_v_229_2 = ((stage_v_71_2 + (pub_r001306_1_2 * 2)) + 692) & 127;
  if (stage_v_229_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_229_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_229_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_229_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_230_1 = ((stage_v_222_1 + (pub_r001306_15_1 * 2)) + 695) & 127;
  int stage_v_230_2 = ((stage_v_222_2 + (pub_r001306_15_2 * 2)) + 695) & 127;
  if (stage_v_230_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_230_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_230_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_230_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_231_1 = ((stage_v_207_1 + (pub_r001306_17_1 * 2)) + 698) & 127;
  int stage_v_231_2 = ((stage_v_207_2 + (pub_r001306_17_2 * 2)) + 698) & 127;
  if (stage_v_231_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_231_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_231_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_231_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_232_1 = ((stage_v_90_1 + (pub_r001306_2_1 * 2)) + 701) & 127;
  int stage_v_232_2 = ((stage_v_90_2 + (pub_r001306_2_2 * 2)) + 701) & 127;
  if (stage_v_232_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_232_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_232_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_232_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_233_1 = ((stage_v_90_1 + (pub_r001306_16_1 * 2)) + 704) & 127;
  int stage_v_233_2 = ((stage_v_90_2 + (pub_r001306_16_2 * 2)) + 704) & 127;
  if (stage_v_233_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_233_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_233_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_233_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_234_1 = ((stage_v_192_1 + (pub_r001306_13_1 * 2)) + 707) & 127;
  int stage_v_234_2 = ((stage_v_192_2 + (pub_r001306_13_2 * 2)) + 707) & 127;
  if (stage_v_234_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_234_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_234_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_234_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_235_1 = ((stage_v_98_1 + (pub_r001306_18_1 * 2)) + 710) & 127;
  int stage_v_235_2 = ((stage_v_98_2 + (pub_r001306_18_2 * 2)) + 710) & 127;
  if (stage_v_235_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_235_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_235_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_235_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_236_1 = ((stage_v_125_1 + (pub_r001306_2_1 * 2)) + 713) & 127;
  int stage_v_236_2 = ((stage_v_125_2 + (pub_r001306_2_2 * 2)) + 713) & 127;
  if (stage_v_236_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_236_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_236_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_236_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001306_14_1 != sec_r001306_14_2);
  __CPROVER_assume(pub_r001306_5_1 == pub_r001306_5_2);
  __CPROVER_assume(pub_r001306_10_1 == pub_r001306_10_2);
  __CPROVER_assume(sec_r001306_10_1 != sec_r001306_10_2);
  __CPROVER_assume(sec_r001306_19_1 != sec_r001306_19_2);
  __CPROVER_assume(pub_r001306_15_1 == pub_r001306_15_2);
  __CPROVER_assume(pub_r001306_4_1 == pub_r001306_4_2);
  __CPROVER_assume(pub_r001306_12_1 == pub_r001306_12_2);
  __CPROVER_assume(sec_r001306_4_1 != sec_r001306_4_2);
  __CPROVER_assume(sec_r001306_7_1 != sec_r001306_7_2);
  __CPROVER_assume(sec_r001306_17_1 != sec_r001306_17_2);
  __CPROVER_assume(sec_r001306_13_1 != sec_r001306_13_2);
  __CPROVER_assume(pub_r001306_19_1 == pub_r001306_19_2);
  __CPROVER_assume(pub_r001306_9_1 == pub_r001306_9_2);
  __CPROVER_assume(pub_r001306_14_1 == pub_r001306_14_2);
  __CPROVER_assume(sec_r001306_11_1 != sec_r001306_11_2);
  __CPROVER_assume(pub_r001306_6_1 == pub_r001306_6_2);
  __CPROVER_assume(pub_r001306_0_1 == pub_r001306_0_2);
  __CPROVER_assume(sec_r001306_16_1 != sec_r001306_16_2);
  __CPROVER_assume(sec_r001306_18_1 != sec_r001306_18_2);
  __CPROVER_assume(sec_r001306_20_1 != sec_r001306_20_2);
  __CPROVER_assume(pub_r001306_13_1 == pub_r001306_13_2);
  __CPROVER_assume(pub_r001306_11_1 == pub_r001306_11_2);
  __CPROVER_assume(sec_r001306_15_1 != sec_r001306_15_2);
  __CPROVER_assume(sec_r001306_6_1 != sec_r001306_6_2);
  __CPROVER_assume(pub_r001306_2_1 == pub_r001306_2_2);
  __CPROVER_assume(pub_r001306_17_1 == pub_r001306_17_2);
  __CPROVER_assume(sec_r001306_1_1 != sec_r001306_1_2);
  __CPROVER_assume(pub_r001306_16_1 == pub_r001306_16_2);
  __CPROVER_assume(sec_r001306_5_1 != sec_r001306_5_2);
  __CPROVER_assume(pub_r001306_20_1 == pub_r001306_20_2);
  __CPROVER_assume(sec_r001306_21_1 != sec_r001306_21_2);
  __CPROVER_assume(pub_r001306_7_1 == pub_r001306_7_2);
  __CPROVER_assume(sec_r001306_0_1 != sec_r001306_0_2);
  __CPROVER_assume(pub_r001306_3_1 == pub_r001306_3_2);
  __CPROVER_assume(pub_r001306_8_1 == pub_r001306_8_2);
  __CPROVER_assume(sec_r001306_8_1 != sec_r001306_8_2);
  __CPROVER_assume(sec_r001306_9_1 != sec_r001306_9_2);
  __CPROVER_assume(sec_r001306_3_1 != sec_r001306_3_2);
  __CPROVER_assume(sec_r001306_12_1 != sec_r001306_12_2);
  __CPROVER_assume(pub_r001306_1_1 == pub_r001306_1_2);
  __CPROVER_assume(pub_r001306_18_1 == pub_r001306_18_2);
  __CPROVER_assume(sec_r001306_2_1 != sec_r001306_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.nonce == st_var_1_2.nonce);
  assert(st_var_1_1.flags == st_var_1_2.flags);
  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  assert(st_var_1_1.iv == st_var_1_2.iv);
  assert(st_var_1_1.tag == st_var_1_2.tag);
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
}


