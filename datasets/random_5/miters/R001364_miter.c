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
struct DeviceConfig_R001364_6413_0
{
  short baud_rate;
  int parity;
  int stop_bits;
  unsigned char id;
  int port;
  int buffer[3];
};
struct FilterState_R001364_6413_1
{
  int damping;
  short prev_out;
  int prev_in;
  int buffer[3];
};
struct CipherContext_R001364_6413_2
{
  int counter;
  short iv;
  int nonce;
  int round_key;
  int flags;
  int buffer[3];
};
struct MatrixBlock_R001364_6413_3
{
  short scale;
  int determinant;
  unsigned char dim;
  int stride;
  int buffer[3];
};
union RegisterBank_R001364_6413_0
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
void fn_R001364_6413_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001364_6413_3 st_1 = {0};
  struct MatrixBlock_R001364_6413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int coefficient_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_99_1 > 26)
  {
    acc_1 = ((acc_1 + (coefficient_99_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_99_2 > 26)
  {
    acc_2 = ((acc_2 + (coefficient_99_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_68_1 = local_arr_1[aux_1 % 3];
  int pivot_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_68_2 * 2)) & 127;
  int phase_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_28_1) & 63;
  aux_2 = (aux_2 + phase_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_71_1 = 0;
  int checksum_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_71_1 = ((checksum_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_71_2 = ((checksum_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_71_1) & 127;
    acc_2 = (acc_2 + checksum_71_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_99_1 == coefficient_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_68_1 == pivot_68_2);
  assert(phase_28_1 == phase_28_2);
  assert(checksum_71_1 == checksum_71_2);
}

int fn_R001364_6413_0(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001364_6413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int coefficient_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_99 > 26)
  {
    acc = ((acc + (coefficient_99 * 2)) + 5) & 127;
    aux ^= coefficient_99 & 15;
  }
  else
  {
    acc = ((acc - coefficient_99) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int pivot_68 = local_arr[aux % 3];
  acc = (acc + (pivot_68 * 2)) & 127;
  int phase_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_28) & 63;
  acc ^= aux;
  int checksum_71 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_71 = ((checksum_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_71) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001364_6413_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001364_6413_2 st_1 = {0};
  struct CipherContext_R001364_6413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int vector_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_88_1)
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

  switch (vector_88_2)
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

  int tracker_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_13_1 > 45)
  {
    acc_1 = ((acc_1 + (tracker_13_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_13_2 > 45)
  {
    acc_2 = ((acc_2 + (tracker_13_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_47_1 = local_arr_1[aux_1 % 3];
  int pivot_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_47_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_88_1 == vector_88_2);
  assert(tracker_13_1 == tracker_13_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_47_1 == pivot_47_2);
}

int fn_R001364_6413_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001364_6413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int vector_88 = (aux + st.buffer[1]) & 3;
  switch (vector_88)
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

  int tracker_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_13 > 45)
  {
    acc = ((acc + (tracker_13 * 2)) + 5) & 127;
    aux ^= tracker_13 & 15;
  }
  else
  {
    acc = ((acc - tracker_13) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int pivot_47 = local_arr[aux % 3];
  acc = (acc + (pivot_47 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001364_6413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001364_6413_2 st_1 = {0};
  struct CipherContext_R001364_6413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_72_1)
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

  switch (checksum_72_2)
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

  int window_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_86_1 > 20)
  {
    acc_1 = ((acc_1 + (window_86_1 * 2)) + 5) & 127;
    aux_1 ^= window_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_86_2 > 20)
  {
    acc_2 = ((acc_2 + (window_86_2 * 2)) + 5) & 127;
    aux_2 ^= window_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_86_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_72_1 == checksum_72_2);
  assert(window_86_1 == window_86_2);
}

int fn_R001364_6413_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001364_6413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_72 = (aux + st.buffer[1]) & 3;
  switch (checksum_72)
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

  int window_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_86 > 20)
  {
    acc = ((acc + (window_86 * 2)) + 5) & 127;
    aux ^= window_86 & 15;
  }
  else
  {
    acc = ((acc - window_86) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001364_6413_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001364_6413_1 st_1 = {0};
  struct FilterState_R001364_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int parity_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_46_1) & 63;
  aux_2 = (aux_2 + parity_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_53_1 = local_arr_1[aux_1 % 3];
  int segment_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_53_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_73_1 = 0;
  int checksum_73_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_73_1 = ((checksum_73_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_73_2 = ((checksum_73_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_73_1) & 127;
    acc_2 = (acc_2 + checksum_73_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_46_1 == parity_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_53_1 == segment_53_2);
  assert(checksum_73_1 == checksum_73_2);
}

int fn_R001364_6413_3(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001364_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int parity_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_46) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_53 = local_arr[aux % 3];
  acc = (acc + (segment_53 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_73 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_73 = ((checksum_73 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_73) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001364_6413_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001364_6413_0 st_1 = {0};
  struct DeviceConfig_R001364_6413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_49_1 = local_arr_1[aux_1 % 3];
  int accumulator_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_49_2 * 2)) & 127;
  int checksum_16_1 = 0;
  int checksum_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_16_1 = ((checksum_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_16_2 = ((checksum_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_16_1) & 127;
    acc_2 = (acc_2 + checksum_16_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_49_1 == accumulator_49_2);
  assert(checksum_16_1 == checksum_16_2);
}

int fn_R001364_6413_4(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001364_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_49 = local_arr[aux % 3];
  acc = (acc + (accumulator_49 * 2)) & 127;
  int checksum_16 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_16 = ((checksum_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_16) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001364_6413_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001364_6413_0 st_1 = {0};
  struct DeviceConfig_R001364_6413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int sample_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_93_1 > 47)
  {
    acc_1 = ((acc_1 + (sample_93_1 * 2)) + 5) & 127;
    aux_1 ^= sample_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_93_2 > 47)
  {
    acc_2 = ((acc_2 + (sample_93_2 * 2)) + 5) & 127;
    aux_2 ^= sample_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_93_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_64_1)
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

  switch (stride_64_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_93_1 == sample_93_2);
  assert(stride_64_1 == stride_64_2);
}

int fn_R001364_6413_5(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001364_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int sample_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_93 > 47)
  {
    acc = ((acc + (sample_93 * 2)) + 5) & 127;
    aux ^= sample_93 & 15;
  }
  else
  {
    acc = ((acc - sample_93) + 11) & 127;
    aux += 3;
  }
  int stride_64 = (aux + st.buffer[1]) & 3;
  switch (stride_64)
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

void fn_R001364_6413_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001364_6413_2 st_1 = {0};
  struct CipherContext_R001364_6413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int coefficient_87_1 = 0;
  int coefficient_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_87_1 = ((coefficient_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_87_2 = ((coefficient_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_87_1) & 127;
    acc_2 = (acc_2 + coefficient_87_2) & 127;
  }

  int margin_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_48_1)
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

  switch (margin_48_2)
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

  int stride_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_79_1) & 63;
  aux_2 = (aux_2 + stride_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_87_1 == coefficient_87_2);
  assert(margin_48_1 == margin_48_2);
  assert(stride_79_1 == stride_79_2);
}

int fn_R001364_6413_6(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001364_6413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int coefficient_87 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_87 = ((coefficient_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_87) & 127;
  }

  int margin_48 = (aux + st.buffer[1]) & 3;
  switch (margin_48)
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

  int stride_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_79) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001364_6413_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001364_6413_1 st_1 = {0};
  struct FilterState_R001364_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int tracker_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_33_1) & 63;
  aux_2 = (aux_2 + tracker_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_42_1 = local_arr_1[aux_1 % 3];
  int offset_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_42_2 * 2)) & 127;
  int coefficient_66_1 = 0;
  int coefficient_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_66_1 = ((coefficient_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_66_2 = ((coefficient_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_66_1) & 127;
    acc_2 = (acc_2 + coefficient_66_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_33_1 == tracker_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_42_1 == offset_42_2);
  assert(coefficient_66_1 == coefficient_66_2);
}

int fn_R001364_6413_7(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001364_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int tracker_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_33) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_42 = local_arr[aux % 3];
  acc = (acc + (offset_42 * 2)) & 127;
  int coefficient_66 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_66 = ((coefficient_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_66) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001364_6413_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001364_6413_3 st_1 = {0};
  struct MatrixBlock_R001364_6413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_69_1)
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

  switch (metric_69_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_69_1 == metric_69_2);
}

int fn_R001364_6413_8(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001364_6413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_69 = (aux + st.buffer[1]) & 3;
  switch (metric_69)
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

void fn_R001364_6413_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001364_6413_3 st_1 = {0};
  struct MatrixBlock_R001364_6413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int anchor_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_89_1) & 63;
  aux_2 = (aux_2 + anchor_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_57_1)
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

  switch (segment_57_2)
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

  int scale_39_1 = 0;
  int scale_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_39_1 = ((scale_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_39_2 = ((scale_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_39_1) & 127;
    acc_2 = (acc_2 + scale_39_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_89_1 == anchor_89_2);
  assert(segment_57_1 == segment_57_2);
  assert(scale_39_1 == scale_39_2);
}

int fn_R001364_6413_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001364_6413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int anchor_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_89) & 63;
  acc ^= aux;
  int segment_57 = (aux + st.buffer[1]) & 3;
  switch (segment_57)
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

  int scale_39 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_39 = ((scale_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_39) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001364_6413_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001364_6413_0 st_1 = {0};
  struct DeviceConfig_R001364_6413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_87_1 = 0;
  int threshold_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_87_1 = ((threshold_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_87_2 = ((threshold_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_87_1) & 127;
    acc_2 = (acc_2 + threshold_87_2) & 127;
  }

  int checksum_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_44_1 > 17)
  {
    acc_1 = ((acc_1 + (checksum_44_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_44_2 > 17)
  {
    acc_2 = ((acc_2 + (checksum_44_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_87_1 = local_arr_1[aux_1 % 3];
  int margin_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_87_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_87_1 == threshold_87_2);
  assert(checksum_44_1 == checksum_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_87_1 == margin_87_2);
}

int fn_R001364_6413_10(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001364_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_87 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_87 = ((threshold_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_87) & 127;
  }

  int checksum_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_44 > 17)
  {
    acc = ((acc + (checksum_44 * 2)) + 5) & 127;
    aux ^= checksum_44 & 15;
  }
  else
  {
    acc = ((acc - checksum_44) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int margin_87 = local_arr[aux % 3];
  acc = (acc + (margin_87 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001364_6413_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001364_6413_3 st_1 = {0};
  struct MatrixBlock_R001364_6413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_66_1 = 0;
  int anchor_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_66_1 = ((anchor_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_66_2 = ((anchor_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_66_1) & 127;
    acc_2 = (acc_2 + anchor_66_2) & 127;
  }

  int vector_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_56_1)
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

  switch (vector_56_2)
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
  int phase_39_1 = local_arr_1[aux_1 % 3];
  int phase_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_39_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_66_1 == anchor_66_2);
  assert(vector_56_1 == vector_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_39_1 == phase_39_2);
}

int fn_R001364_6413_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001364_6413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_66 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_66 = ((anchor_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_66) & 127;
  }

  int vector_56 = (aux + st.buffer[1]) & 3;
  switch (vector_56)
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
  int phase_39 = local_arr[aux % 3];
  acc = (acc + (phase_39 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001364_6413_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001364_6413_1 st_1 = {0};
  struct FilterState_R001364_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_97_1 = 0;
  int quotient_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_97_1 = ((quotient_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_97_2 = ((quotient_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_97_1) & 127;
    acc_2 = (acc_2 + quotient_97_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_97_1 == quotient_97_2);
}

int fn_R001364_6413_12(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001364_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_97 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_97 = ((quotient_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_97) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001364_6413_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001364_6413_2 st_1 = {0};
  struct CipherContext_R001364_6413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int tally_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_17_1) & 63;
  aux_2 = (aux_2 + tally_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_71_1 = 0;
  int quotient_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_71_1 = ((quotient_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_71_2 = ((quotient_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_71_1) & 127;
    acc_2 = (acc_2 + quotient_71_2) & 127;
  }

  int weight_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_76_1 > 12)
  {
    acc_1 = ((acc_1 + (weight_76_1 * 2)) + 5) & 127;
    aux_1 ^= weight_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_76_2 > 12)
  {
    acc_2 = ((acc_2 + (weight_76_2 * 2)) + 5) & 127;
    aux_2 ^= weight_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_34_1)
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

  switch (cursor_34_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_17_1 == tally_17_2);
  assert(quotient_71_1 == quotient_71_2);
  assert(weight_76_1 == weight_76_2);
  assert(cursor_34_1 == cursor_34_2);
}

int fn_R001364_6413_13(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001364_6413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int tally_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_17) & 63;
  acc ^= aux;
  int quotient_71 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_71 = ((quotient_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_71) & 127;
  }

  int weight_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_76 > 12)
  {
    acc = ((acc + (weight_76 * 2)) + 5) & 127;
    aux ^= weight_76 & 15;
  }
  else
  {
    acc = ((acc - weight_76) + 11) & 127;
    aux += 3;
  }
  int cursor_34 = (aux + st.buffer[1]) & 3;
  switch (cursor_34)
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

void fn_R001364_6413_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001364_6413_1 st_1 = {0};
  struct FilterState_R001364_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_53_1 = local_arr_1[aux_1 % 3];
  int checksum_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_53_2 * 2)) & 127;
  int coefficient_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_62_1)
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

  switch (coefficient_62_2)
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

  int quantum_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_22_1 > 48)
  {
    acc_1 = ((acc_1 + (quantum_22_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_22_2 > 48)
  {
    acc_2 = ((acc_2 + (quantum_22_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_22_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_53_1 == checksum_53_2);
  assert(coefficient_62_1 == coefficient_62_2);
  assert(quantum_22_1 == quantum_22_2);
}

int fn_R001364_6413_14(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001364_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_53 = local_arr[aux % 3];
  acc = (acc + (checksum_53 * 2)) & 127;
  int coefficient_62 = (aux + st.buffer[1]) & 3;
  switch (coefficient_62)
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

  int quantum_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_22 > 48)
  {
    acc = ((acc + (quantum_22 * 2)) + 5) & 127;
    aux ^= quantum_22 & 15;
  }
  else
  {
    acc = ((acc - quantum_22) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001364_6413_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001364_6413_2 st_1 = {0};
  struct CipherContext_R001364_6413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int quantum_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_96_1)
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

  switch (quantum_96_2)
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
  int anchor_90_1 = 0;
  int anchor_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_90_1 = ((anchor_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_90_2 = ((anchor_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_90_1) & 127;
    acc_2 = (acc_2 + anchor_90_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_96_1 == quantum_96_2);
  assert(anchor_90_1 == anchor_90_2);
}

int fn_R001364_6413_15(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001364_6413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int quantum_96 = (aux + st.buffer[1]) & 3;
  switch (quantum_96)
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
  int anchor_90 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_90 = ((anchor_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_90) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001364_6413_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001364_6413_3 st_1 = {0};
  struct MatrixBlock_R001364_6413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int pivot_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_35_1)
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

  switch (pivot_35_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_32_1 = local_arr_1[aux_1 % 3];
  int threshold_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_35_1 == pivot_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_32_1 == threshold_32_2);
}

int fn_R001364_6413_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001364_6413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int pivot_35 = (aux + st.buffer[1]) & 3;
  switch (pivot_35)
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

  int local_arr[3] = {4, 9, 15};
  int threshold_32 = local_arr[aux % 3];
  acc = (acc + (threshold_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001364_0_1;
  int sec_r001364_0_2;
  int sec_r001364_1_1;
  int sec_r001364_1_2;
  int sec_r001364_2_1;
  int sec_r001364_2_2;
  int sec_r001364_3_1;
  int sec_r001364_3_2;
  int sec_r001364_4_1;
  int sec_r001364_4_2;
  int sec_r001364_5_1;
  int sec_r001364_5_2;
  int sec_r001364_6_1;
  int sec_r001364_6_2;
  int sec_r001364_7_1;
  int sec_r001364_7_2;
  int sec_r001364_8_1;
  int sec_r001364_8_2;
  int sec_r001364_9_1;
  int sec_r001364_9_2;
  int sec_r001364_10_1;
  int sec_r001364_10_2;
  int sec_r001364_11_1;
  int sec_r001364_11_2;
  int sec_r001364_12_1;
  int sec_r001364_12_2;
  int sec_r001364_13_1;
  int sec_r001364_13_2;
  int sec_r001364_14_1;
  int sec_r001364_14_2;
  int sec_r001364_15_1;
  int sec_r001364_15_2;
  int sec_r001364_16_1;
  int sec_r001364_16_2;
  int sec_r001364_17_1;
  int sec_r001364_17_2;
  int sec_r001364_18_1;
  int sec_r001364_18_2;
  int sec_r001364_19_1;
  int sec_r001364_19_2;
  int sec_r001364_20_1;
  int sec_r001364_20_2;
  int pub_r001364_0_1;
  int pub_r001364_0_2;
  int pub_r001364_1_1;
  int pub_r001364_1_2;
  int pub_r001364_2_1;
  int pub_r001364_2_2;
  int pub_r001364_3_1;
  int pub_r001364_3_2;
  int pub_r001364_4_1;
  int pub_r001364_4_2;
  int pub_r001364_5_1;
  int pub_r001364_5_2;
  int pub_r001364_6_1;
  int pub_r001364_6_2;
  int pub_r001364_7_1;
  int pub_r001364_7_2;
  int pub_r001364_8_1;
  int pub_r001364_8_2;
  int pub_r001364_9_1;
  int pub_r001364_9_2;
  int pub_r001364_10_1;
  int pub_r001364_10_2;
  int pub_r001364_11_1;
  int pub_r001364_11_2;
  int pub_r001364_12_1;
  int pub_r001364_12_2;
  int pub_r001364_13_1;
  int pub_r001364_13_2;
  int pub_r001364_14_1;
  int pub_r001364_14_2;
  int pub_r001364_15_1;
  int pub_r001364_15_2;
  int pub_r001364_16_1;
  int pub_r001364_16_2;
  int pub_r001364_17_1;
  int pub_r001364_17_2;
  int pub_r001364_18_1;
  int pub_r001364_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001364_0_1 >= (-100)) && (pub_r001364_0_1 <= 100));
  __CPROVER_assume((pub_r001364_0_2 >= (-100)) && (pub_r001364_0_2 <= 100));
  __CPROVER_assume((pub_r001364_1_1 >= (-100)) && (pub_r001364_1_1 <= 100));
  __CPROVER_assume((pub_r001364_1_2 >= (-100)) && (pub_r001364_1_2 <= 100));
  __CPROVER_assume((pub_r001364_2_1 >= (-100)) && (pub_r001364_2_1 <= 100));
  __CPROVER_assume((pub_r001364_2_2 >= (-100)) && (pub_r001364_2_2 <= 100));
  __CPROVER_assume((pub_r001364_3_1 >= (-100)) && (pub_r001364_3_1 <= 100));
  __CPROVER_assume((pub_r001364_3_2 >= (-100)) && (pub_r001364_3_2 <= 100));
  __CPROVER_assume((pub_r001364_4_1 >= (-100)) && (pub_r001364_4_1 <= 100));
  __CPROVER_assume((pub_r001364_4_2 >= (-100)) && (pub_r001364_4_2 <= 100));
  __CPROVER_assume((pub_r001364_5_1 >= (-100)) && (pub_r001364_5_1 <= 100));
  __CPROVER_assume((pub_r001364_5_2 >= (-100)) && (pub_r001364_5_2 <= 100));
  __CPROVER_assume((pub_r001364_6_1 >= (-100)) && (pub_r001364_6_1 <= 100));
  __CPROVER_assume((pub_r001364_6_2 >= (-100)) && (pub_r001364_6_2 <= 100));
  __CPROVER_assume((pub_r001364_7_1 >= (-100)) && (pub_r001364_7_1 <= 100));
  __CPROVER_assume((pub_r001364_7_2 >= (-100)) && (pub_r001364_7_2 <= 100));
  __CPROVER_assume((pub_r001364_8_1 >= (-100)) && (pub_r001364_8_1 <= 100));
  __CPROVER_assume((pub_r001364_8_2 >= (-100)) && (pub_r001364_8_2 <= 100));
  __CPROVER_assume((pub_r001364_9_1 >= (-100)) && (pub_r001364_9_1 <= 100));
  __CPROVER_assume((pub_r001364_9_2 >= (-100)) && (pub_r001364_9_2 <= 100));
  __CPROVER_assume((pub_r001364_10_1 >= (-100)) && (pub_r001364_10_1 <= 100));
  __CPROVER_assume((pub_r001364_10_2 >= (-100)) && (pub_r001364_10_2 <= 100));
  __CPROVER_assume((pub_r001364_11_1 >= (-100)) && (pub_r001364_11_1 <= 100));
  __CPROVER_assume((pub_r001364_11_2 >= (-100)) && (pub_r001364_11_2 <= 100));
  __CPROVER_assume((pub_r001364_12_1 >= (-100)) && (pub_r001364_12_1 <= 100));
  __CPROVER_assume((pub_r001364_12_2 >= (-100)) && (pub_r001364_12_2 <= 100));
  __CPROVER_assume((pub_r001364_13_1 >= (-100)) && (pub_r001364_13_1 <= 100));
  __CPROVER_assume((pub_r001364_13_2 >= (-100)) && (pub_r001364_13_2 <= 100));
  __CPROVER_assume((pub_r001364_14_1 >= (-100)) && (pub_r001364_14_1 <= 100));
  __CPROVER_assume((pub_r001364_14_2 >= (-100)) && (pub_r001364_14_2 <= 100));
  __CPROVER_assume((pub_r001364_15_1 >= (-100)) && (pub_r001364_15_1 <= 100));
  __CPROVER_assume((pub_r001364_15_2 >= (-100)) && (pub_r001364_15_2 <= 100));
  __CPROVER_assume((pub_r001364_16_1 >= (-100)) && (pub_r001364_16_1 <= 100));
  __CPROVER_assume((pub_r001364_16_2 >= (-100)) && (pub_r001364_16_2 <= 100));
  __CPROVER_assume((pub_r001364_17_1 >= (-100)) && (pub_r001364_17_1 <= 100));
  __CPROVER_assume((pub_r001364_17_2 >= (-100)) && (pub_r001364_17_2 <= 100));
  __CPROVER_assume((pub_r001364_18_1 >= (-100)) && (pub_r001364_18_1 <= 100));
  __CPROVER_assume((pub_r001364_18_2 >= (-100)) && (pub_r001364_18_2 <= 100));
  __CPROVER_assume((sec_r001364_0_1 >= 0) && (sec_r001364_0_1 <= 255));
  __CPROVER_assume((sec_r001364_0_2 >= 0) && (sec_r001364_0_2 <= 255));
  __CPROVER_assume((sec_r001364_1_1 >= 0) && (sec_r001364_1_1 <= 255));
  __CPROVER_assume((sec_r001364_1_2 >= 0) && (sec_r001364_1_2 <= 255));
  __CPROVER_assume((sec_r001364_2_1 >= 0) && (sec_r001364_2_1 <= 255));
  __CPROVER_assume((sec_r001364_2_2 >= 0) && (sec_r001364_2_2 <= 255));
  __CPROVER_assume((sec_r001364_3_1 >= 0) && (sec_r001364_3_1 <= 255));
  __CPROVER_assume((sec_r001364_3_2 >= 0) && (sec_r001364_3_2 <= 255));
  __CPROVER_assume((sec_r001364_4_1 >= 0) && (sec_r001364_4_1 <= 255));
  __CPROVER_assume((sec_r001364_4_2 >= 0) && (sec_r001364_4_2 <= 255));
  __CPROVER_assume((sec_r001364_5_1 >= 0) && (sec_r001364_5_1 <= 255));
  __CPROVER_assume((sec_r001364_5_2 >= 0) && (sec_r001364_5_2 <= 255));
  __CPROVER_assume((sec_r001364_6_1 >= 0) && (sec_r001364_6_1 <= 255));
  __CPROVER_assume((sec_r001364_6_2 >= 0) && (sec_r001364_6_2 <= 255));
  __CPROVER_assume((sec_r001364_7_1 >= 0) && (sec_r001364_7_1 <= 255));
  __CPROVER_assume((sec_r001364_7_2 >= 0) && (sec_r001364_7_2 <= 255));
  __CPROVER_assume((sec_r001364_8_1 >= 0) && (sec_r001364_8_1 <= 255));
  __CPROVER_assume((sec_r001364_8_2 >= 0) && (sec_r001364_8_2 <= 255));
  __CPROVER_assume((sec_r001364_9_1 >= 0) && (sec_r001364_9_1 <= 255));
  __CPROVER_assume((sec_r001364_9_2 >= 0) && (sec_r001364_9_2 <= 255));
  __CPROVER_assume((sec_r001364_10_1 >= 0) && (sec_r001364_10_1 <= 255));
  __CPROVER_assume((sec_r001364_10_2 >= 0) && (sec_r001364_10_2 <= 255));
  __CPROVER_assume((sec_r001364_11_1 >= 0) && (sec_r001364_11_1 <= 255));
  __CPROVER_assume((sec_r001364_11_2 >= 0) && (sec_r001364_11_2 <= 255));
  __CPROVER_assume((sec_r001364_12_1 >= 0) && (sec_r001364_12_1 <= 255));
  __CPROVER_assume((sec_r001364_12_2 >= 0) && (sec_r001364_12_2 <= 255));
  __CPROVER_assume((sec_r001364_13_1 >= 0) && (sec_r001364_13_1 <= 255));
  __CPROVER_assume((sec_r001364_13_2 >= 0) && (sec_r001364_13_2 <= 255));
  __CPROVER_assume((sec_r001364_14_1 >= 0) && (sec_r001364_14_1 <= 255));
  __CPROVER_assume((sec_r001364_14_2 >= 0) && (sec_r001364_14_2 <= 255));
  __CPROVER_assume((sec_r001364_15_1 >= 0) && (sec_r001364_15_1 <= 255));
  __CPROVER_assume((sec_r001364_15_2 >= 0) && (sec_r001364_15_2 <= 255));
  __CPROVER_assume((sec_r001364_16_1 >= 0) && (sec_r001364_16_1 <= 255));
  __CPROVER_assume((sec_r001364_16_2 >= 0) && (sec_r001364_16_2 <= 255));
  __CPROVER_assume((sec_r001364_17_1 >= 0) && (sec_r001364_17_1 <= 255));
  __CPROVER_assume((sec_r001364_17_2 >= 0) && (sec_r001364_17_2 <= 255));
  __CPROVER_assume((sec_r001364_18_1 >= 0) && (sec_r001364_18_1 <= 255));
  __CPROVER_assume((sec_r001364_18_2 >= 0) && (sec_r001364_18_2 <= 255));
  __CPROVER_assume((sec_r001364_19_1 >= 0) && (sec_r001364_19_1 <= 255));
  __CPROVER_assume((sec_r001364_19_2 >= 0) && (sec_r001364_19_2 <= 255));
  __CPROVER_assume((sec_r001364_20_1 >= 0) && (sec_r001364_20_1 <= 255));
  __CPROVER_assume((sec_r001364_20_2 >= 0) && (sec_r001364_20_2 <= 255));
  struct DeviceConfig_R001364_6413_0 st_var_0_1 = {0};
  struct DeviceConfig_R001364_6413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001364_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001364_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001364_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001364_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001364_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001364_0_2 + 7) & 15;
  struct FilterState_R001364_6413_1 st_var_1_1 = {0};
  struct FilterState_R001364_6413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001364_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001364_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001364_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001364_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001364_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001364_0_2 + 9) & 15;
  struct CipherContext_R001364_6413_2 st_var_2_1 = {0};
  struct CipherContext_R001364_6413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001364_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001364_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001364_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001364_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001364_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001364_0_2 + 11) & 15;
  struct MatrixBlock_R001364_6413_3 st_var_3_1 = {0};
  struct MatrixBlock_R001364_6413_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001364_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001364_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001364_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001364_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001364_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001364_0_2 + 13) & 15;
  union RegisterBank_R001364_6413_0 u_var_1;
  union RegisterBank_R001364_6413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001364_6413_0(sec_r001364_0_1, pub_r001364_1_1, pub_r001364_2_1);
  int helper_flow_0_2 = fn_R001364_6413_0(sec_r001364_0_2, pub_r001364_1_2, pub_r001364_2_2);
  fn_R001364_6413_0_2(sec_r001364_0_1, pub_r001364_1_1, pub_r001364_2_1, sec_r001364_0_2, pub_r001364_1_2, pub_r001364_2_2);
  int helper_flow_1_1 = fn_R001364_6413_1(sec_r001364_1_1, sec_r001364_2_1, pub_r001364_3_1, pub_r001364_4_1);
  int helper_flow_1_2 = fn_R001364_6413_1(sec_r001364_1_2, sec_r001364_2_2, pub_r001364_3_2, pub_r001364_4_2);
  fn_R001364_6413_1_2(sec_r001364_1_1, sec_r001364_2_1, pub_r001364_3_1, pub_r001364_4_1, sec_r001364_1_2, sec_r001364_2_2, pub_r001364_3_2, pub_r001364_4_2);
  int helper_flow_2_1 = fn_R001364_6413_2(sec_r001364_2_1, sec_r001364_3_1, pub_r001364_4_1, pub_r001364_5_1);
  int helper_flow_2_2 = fn_R001364_6413_2(sec_r001364_2_2, sec_r001364_3_2, pub_r001364_4_2, pub_r001364_5_2);
  fn_R001364_6413_2_2(sec_r001364_2_1, sec_r001364_3_1, pub_r001364_4_1, pub_r001364_5_1, sec_r001364_2_2, sec_r001364_3_2, pub_r001364_4_2, pub_r001364_5_2);
  int helper_flow_3_1 = fn_R001364_6413_3(sec_r001364_3_1, sec_r001364_4_1);
  int helper_flow_3_2 = fn_R001364_6413_3(sec_r001364_3_2, sec_r001364_4_2);
  fn_R001364_6413_3_2(sec_r001364_3_1, sec_r001364_4_1, sec_r001364_3_2, sec_r001364_4_2);
  int helper_flow_4_1 = fn_R001364_6413_4(sec_r001364_4_1, sec_r001364_5_1, pub_r001364_6_1);
  int helper_flow_4_2 = fn_R001364_6413_4(sec_r001364_4_2, sec_r001364_5_2, pub_r001364_6_2);
  fn_R001364_6413_4_2(sec_r001364_4_1, sec_r001364_5_1, pub_r001364_6_1, sec_r001364_4_2, sec_r001364_5_2, pub_r001364_6_2);
  int stage_v_0_1 = ((pub_r001364_7_1 * 2) + 6) & 63;
  int stage_v_0_2 = ((pub_r001364_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001364_18_1 * 2) + 21) & 63;
  int stage_v_1_2 = ((pub_r001364_18_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((sec_r001364_20_1 * 3) + pub_r001364_10_1) + 40) & 127;
  int stage_v_2_2 = (((sec_r001364_20_2 * 3) + pub_r001364_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = ((pub_r001364_10_1 * 2) + 13) & 63;
  int stage_v_3_2 = ((pub_r001364_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (((helper_flow_3_1 * 3) + pub_r001364_3_1) + 8) & 127;
  int stage_v_4_2 = (((helper_flow_3_2 * 3) + pub_r001364_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = ((pub_r001364_0_1 * 2) + 16) & 63;
  int stage_v_5_2 = ((pub_r001364_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001364_18_1 * 2) + 46) & 63;
  int stage_v_6_2 = ((pub_r001364_18_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001364_1_1 * 2) + 26) & 63;
  int stage_v_7_2 = ((pub_r001364_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001364_14_1 * 2) + 38) & 63;
  int stage_v_8_2 = ((pub_r001364_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001364_0_1 * 2) + 26) & 63;
  int stage_v_9_2 = ((pub_r001364_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((stage_v_4_1 * 3) + pub_r001364_16_1) + 13) & 127;
  int stage_v_10_2 = (((stage_v_4_2 * 3) + pub_r001364_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = ((pub_r001364_4_1 * 2) + 37) & 63;
  int stage_v_11_2 = ((pub_r001364_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001364_1_1 * 2) + 15) & 63;
  int stage_v_12_2 = ((pub_r001364_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001364_4_1 * 2) + 7) & 63;
  int stage_v_13_2 = ((pub_r001364_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((sec_r001364_11_1 * 3) + pub_r001364_17_1) + 14) & 127;
  int stage_v_14_2 = (((sec_r001364_11_2 * 3) + pub_r001364_17_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = ((pub_r001364_2_1 * 2) + 50) & 63;
  int stage_v_15_2 = ((pub_r001364_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((sec_r001364_2_1 * 3) + pub_r001364_14_1) + 43) & 127;
  int stage_v_16_2 = (((sec_r001364_2_2 * 3) + pub_r001364_14_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = ((pub_r001364_4_1 * 2) + 26) & 63;
  int stage_v_17_2 = ((pub_r001364_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001364_12_1 * 2) + 23) & 63;
  int stage_v_18_2 = ((pub_r001364_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (((sec_r001364_14_1 * 3) + pub_r001364_5_1) + 42) & 127;
  int stage_v_19_2 = (((sec_r001364_14_2 * 3) + pub_r001364_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = (((helper_flow_3_1 * 3) + pub_r001364_2_1) + 27) & 127;
  int stage_v_20_2 = (((helper_flow_3_2 * 3) + pub_r001364_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = ((pub_r001364_9_1 * 2) + 17) & 63;
  int stage_v_21_2 = ((pub_r001364_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = (((sec_r001364_8_1 * 3) + pub_r001364_13_1) + 30) & 127;
  int stage_v_22_2 = (((sec_r001364_8_2 * 3) + pub_r001364_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = (((sec_r001364_10_1 * 3) + pub_r001364_2_1) + 6) & 127;
  int stage_v_23_2 = (((sec_r001364_10_2 * 3) + pub_r001364_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((sec_r001364_12_1 * 3) + pub_r001364_8_1) + 8) & 127;
  int stage_v_24_2 = (((sec_r001364_12_2 * 3) + pub_r001364_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = (((helper_flow_1_1 * 3) + pub_r001364_11_1) + 32) & 127;
  int stage_v_25_2 = (((helper_flow_1_2 * 3) + pub_r001364_11_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = (((helper_flow_0_1 * 3) + pub_r001364_16_1) + 41) & 127;
  int stage_v_26_2 = (((helper_flow_0_2 * 3) + pub_r001364_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = ((pub_r001364_16_1 * 2) + 47) & 63;
  int stage_v_27_2 = ((pub_r001364_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001364_1_1 * 2) + 29) & 63;
  int stage_v_28_2 = ((pub_r001364_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001364_8_1 * 2) + 8) & 63;
  int stage_v_29_2 = ((pub_r001364_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001364_17_1 * 2) + 30) & 63;
  int stage_v_30_2 = ((pub_r001364_17_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = (((sec_r001364_9_1 * 3) + pub_r001364_12_1) + 39) & 127;
  int stage_v_31_2 = (((sec_r001364_9_2 * 3) + pub_r001364_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = (((sec_r001364_2_1 * 3) + pub_r001364_11_1) + 27) & 127;
  int stage_v_32_2 = (((sec_r001364_2_2 * 3) + pub_r001364_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = ((pub_r001364_9_1 * 2) + 31) & 63;
  int stage_v_33_2 = ((pub_r001364_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001364_10_1 * 2) + 39) & 63;
  int stage_v_34_2 = ((pub_r001364_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001364_2_1 * 2) + 39) & 63;
  int stage_v_35_2 = ((pub_r001364_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001364_18_1 * 2) + 16) & 63;
  int stage_v_36_2 = ((pub_r001364_18_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (((sec_r001364_2_1 * 3) + pub_r001364_18_1) + 10) & 127;
  int stage_v_37_2 = (((sec_r001364_2_2 * 3) + pub_r001364_18_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = (((stage_v_37_1 * 3) + pub_r001364_9_1) + 13) & 127;
  int stage_v_38_2 = (((stage_v_37_2 * 3) + pub_r001364_9_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = (((sec_r001364_19_1 * 3) + pub_r001364_13_1) + 40) & 127;
  int stage_v_39_2 = (((sec_r001364_19_2 * 3) + pub_r001364_13_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = (((sec_r001364_16_1 * 3) + pub_r001364_13_1) + 35) & 127;
  int stage_v_40_2 = (((sec_r001364_16_2 * 3) + pub_r001364_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = (((sec_r001364_12_1 * 3) + pub_r001364_16_1) + 14) & 127;
  int stage_v_41_2 = (((sec_r001364_12_2 * 3) + pub_r001364_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = (((stage_v_31_1 * 3) + pub_r001364_4_1) + 38) & 127;
  int stage_v_42_2 = (((stage_v_31_2 * 3) + pub_r001364_4_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = ((pub_r001364_6_1 * 2) + 30) & 63;
  int stage_v_43_2 = ((pub_r001364_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (((stage_v_41_1 * 3) + pub_r001364_2_1) + 42) & 127;
  int stage_v_44_2 = (((stage_v_41_2 * 3) + pub_r001364_2_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = ((pub_r001364_12_1 * 2) + 17) & 63;
  int stage_v_45_2 = ((pub_r001364_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((stage_v_2_1 * 3) + pub_r001364_0_1) + 9) & 127;
  int stage_v_46_2 = (((stage_v_2_2 * 3) + pub_r001364_0_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001364_14_1 * 2) + 49) & 63;
  int stage_v_47_2 = ((pub_r001364_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (((helper_flow_0_1 * 3) + pub_r001364_17_1) + 19) & 127;
  int stage_v_48_2 = (((helper_flow_0_2 * 3) + pub_r001364_17_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = (((stage_v_42_1 * 3) + pub_r001364_15_1) + 31) & 127;
  int stage_v_49_2 = (((stage_v_42_2 * 3) + pub_r001364_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = (((stage_v_32_1 * 3) + pub_r001364_10_1) + 13) & 127;
  int stage_v_50_2 = (((stage_v_32_2 * 3) + pub_r001364_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = ((pub_r001364_5_1 * 2) + 32) & 63;
  int stage_v_51_2 = ((pub_r001364_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((stage_v_42_1 * 3) + pub_r001364_11_1) + 13) & 127;
  int stage_v_52_2 = (((stage_v_42_2 * 3) + pub_r001364_11_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = (((sec_r001364_15_1 * 3) + pub_r001364_8_1) + 28) & 127;
  int stage_v_53_2 = (((sec_r001364_15_2 * 3) + pub_r001364_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = ((pub_r001364_14_1 * 2) + 15) & 63;
  int stage_v_54_2 = ((pub_r001364_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001364_1_1 * 2) + 49) & 63;
  int stage_v_55_2 = ((pub_r001364_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = (((stage_v_22_1 * 3) + pub_r001364_11_1) + 14) & 127;
  int stage_v_56_2 = (((stage_v_22_2 * 3) + pub_r001364_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = ((pub_r001364_13_1 * 2) + 35) & 63;
  int stage_v_57_2 = ((pub_r001364_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001364_12_1 * 2) + 10) & 63;
  int stage_v_58_2 = ((pub_r001364_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001364_18_1 * 2) + 43) & 63;
  int stage_v_59_2 = ((pub_r001364_18_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001364_4_1 * 2) + 10) & 63;
  int stage_v_60_2 = ((pub_r001364_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((stage_v_22_1 * 3) + pub_r001364_14_1) + 34) & 127;
  int stage_v_61_2 = (((stage_v_22_2 * 3) + pub_r001364_14_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001364_12_1 * 2) + 43) & 63;
  int stage_v_62_2 = ((pub_r001364_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001364_6_1 * 2) + 30) & 63;
  int stage_v_63_2 = ((pub_r001364_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (((sec_r001364_6_1 * 3) + pub_r001364_2_1) + 10) & 127;
  int stage_v_64_2 = (((sec_r001364_6_2 * 3) + pub_r001364_2_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = (((stage_v_61_1 * 3) + pub_r001364_11_1) + 44) & 127;
  int stage_v_65_2 = (((stage_v_61_2 * 3) + pub_r001364_11_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = ((pub_r001364_13_1 * 2) + 12) & 63;
  int stage_v_66_2 = ((pub_r001364_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (((helper_flow_2_1 * 3) + pub_r001364_9_1) + 23) & 127;
  int stage_v_67_2 = (((helper_flow_2_2 * 3) + pub_r001364_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = (((sec_r001364_5_1 * 3) + pub_r001364_5_1) + 32) & 127;
  int stage_v_68_2 = (((sec_r001364_5_2 * 3) + pub_r001364_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = ((pub_r001364_18_1 * 2) + 36) & 63;
  int stage_v_69_2 = ((pub_r001364_18_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001364_6_1 * 2) + 45) & 63;
  int stage_v_70_2 = ((pub_r001364_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = (((sec_r001364_12_1 * 3) + pub_r001364_7_1) + 37) & 127;
  int stage_v_71_2 = (((sec_r001364_12_2 * 3) + pub_r001364_7_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = ((pub_r001364_9_1 * 2) + 6) & 63;
  int stage_v_72_2 = ((pub_r001364_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((sec_r001364_18_1 * 3) + pub_r001364_5_1) + 41) & 127;
  int stage_v_73_2 = (((sec_r001364_18_2 * 3) + pub_r001364_5_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = (((sec_r001364_17_1 * 3) + pub_r001364_4_1) + 4) & 127;
  int stage_v_74_2 = (((sec_r001364_17_2 * 3) + pub_r001364_4_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = (((stage_v_14_1 * 3) + pub_r001364_14_1) + 19) & 127;
  int stage_v_75_2 = (((stage_v_14_2 * 3) + pub_r001364_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = (((stage_v_23_1 * 3) + pub_r001364_7_1) + 39) & 127;
  int stage_v_76_2 = (((stage_v_23_2 * 3) + pub_r001364_7_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = (((helper_flow_3_1 * 3) + pub_r001364_1_1) + 41) & 127;
  int stage_v_77_2 = (((helper_flow_3_2 * 3) + pub_r001364_1_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = ((pub_r001364_18_1 * 2) + 21) & 63;
  int stage_v_78_2 = ((pub_r001364_18_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001364_6_1 * 2) + 34) & 63;
  int stage_v_79_2 = ((pub_r001364_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (((stage_v_76_1 * 3) + pub_r001364_16_1) + 37) & 127;
  int stage_v_80_2 = (((stage_v_76_2 * 3) + pub_r001364_16_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_80_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_80_2 * 2)) & 255;
  int stage_v_81_1 = ((pub_r001364_4_1 * 2) + 15) & 63;
  int stage_v_81_2 = ((pub_r001364_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001364_17_1 * 2) + 25) & 63;
  int stage_v_82_2 = ((pub_r001364_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (((helper_flow_4_1 * 3) + pub_r001364_4_1) + 8) & 127;
  int stage_v_83_2 = (((helper_flow_4_2 * 3) + pub_r001364_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = ((pub_r001364_10_1 * 2) + 47) & 63;
  int stage_v_84_2 = ((pub_r001364_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = (((stage_v_40_1 * 3) + pub_r001364_1_1) + 4) & 127;
  int stage_v_85_2 = (((stage_v_40_2 * 3) + pub_r001364_1_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = ((pub_r001364_6_1 * 2) + 28) & 63;
  int stage_v_86_2 = ((pub_r001364_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((stage_v_20_1 * 3) + pub_r001364_18_1) + 25) & 127;
  int stage_v_87_2 = (((stage_v_20_2 * 3) + pub_r001364_18_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = ((pub_r001364_17_1 * 2) + 46) & 63;
  int stage_v_88_2 = ((pub_r001364_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (((sec_r001364_6_1 * 3) + pub_r001364_8_1) + 4) & 127;
  int stage_v_89_2 = (((sec_r001364_6_2 * 3) + pub_r001364_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = (((stage_v_19_1 * 3) + pub_r001364_4_1) + 7) & 127;
  int stage_v_90_2 = (((stage_v_19_2 * 3) + pub_r001364_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = (((stage_v_44_1 * 3) + pub_r001364_7_1) + 38) & 127;
  int stage_v_91_2 = (((stage_v_44_2 * 3) + pub_r001364_7_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = ((pub_r001364_7_1 * 2) + 37) & 63;
  int stage_v_92_2 = ((pub_r001364_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001364_18_1 * 2) + 30) & 63;
  int stage_v_93_2 = ((pub_r001364_18_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (((sec_r001364_14_1 * 3) + pub_r001364_1_1) + 7) & 127;
  int stage_v_94_2 = (((sec_r001364_14_2 * 3) + pub_r001364_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = (((stage_v_83_1 * 3) + pub_r001364_7_1) + 9) & 127;
  int stage_v_95_2 = (((stage_v_83_2 * 3) + pub_r001364_7_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = (((sec_r001364_18_1 * 3) + pub_r001364_12_1) + 42) & 127;
  int stage_v_96_2 = (((sec_r001364_18_2 * 3) + pub_r001364_12_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = ((pub_r001364_12_1 * 2) + 7) & 63;
  int stage_v_97_2 = ((pub_r001364_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001364_10_1 * 2) + 23) & 63;
  int stage_v_98_2 = ((pub_r001364_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = (((sec_r001364_18_1 * 3) + pub_r001364_3_1) + 10) & 127;
  int stage_v_99_2 = (((sec_r001364_18_2 * 3) + pub_r001364_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = (((helper_flow_3_1 * 3) + pub_r001364_13_1) + 27) & 127;
  int stage_v_100_2 = (((helper_flow_3_2 * 3) + pub_r001364_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_100_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_100_2 * 2)) & 255;
  int stage_v_101_1 = ((pub_r001364_3_1 * 2) + 45) & 63;
  int stage_v_101_2 = ((pub_r001364_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001364_17_1 * 2) + 30) & 63;
  int stage_v_102_2 = ((pub_r001364_17_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001364_4_1 * 2) + 6) & 63;
  int stage_v_103_2 = ((pub_r001364_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((sec_r001364_1_1 * 3) + pub_r001364_13_1) + 27) & 127;
  int stage_v_104_2 = (((sec_r001364_1_2 * 3) + pub_r001364_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = (((stage_v_91_1 * 3) + pub_r001364_10_1) + 10) & 127;
  int stage_v_105_2 = (((stage_v_91_2 * 3) + pub_r001364_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = ((pub_r001364_15_1 * 2) + 12) & 63;
  int stage_v_106_2 = ((pub_r001364_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001364_4_1 * 2) + 50) & 63;
  int stage_v_107_2 = ((pub_r001364_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (((stage_v_95_1 * 3) + pub_r001364_1_1) + 44) & 127;
  int stage_v_108_2 = (((stage_v_95_2 * 3) + pub_r001364_1_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = ((pub_r001364_7_1 * 2) + 41) & 63;
  int stage_v_109_2 = ((pub_r001364_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (((sec_r001364_4_1 * 3) + pub_r001364_2_1) + 22) & 127;
  int stage_v_110_2 = (((sec_r001364_4_2 * 3) + pub_r001364_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = ((pub_r001364_8_1 * 2) + 43) & 63;
  int stage_v_111_2 = ((pub_r001364_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (((stage_v_110_1 * 3) + pub_r001364_0_1) + 12) & 127;
  int stage_v_112_2 = (((stage_v_110_2 * 3) + pub_r001364_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = ((pub_r001364_4_1 * 2) + 42) & 63;
  int stage_v_113_2 = ((pub_r001364_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (((stage_v_52_1 * 3) + pub_r001364_12_1) + 16) & 127;
  int stage_v_114_2 = (((stage_v_52_2 * 3) + pub_r001364_12_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = (((sec_r001364_8_1 * 3) + pub_r001364_7_1) + 7) & 127;
  int stage_v_115_2 = (((sec_r001364_8_2 * 3) + pub_r001364_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = (((stage_v_19_1 * 3) + pub_r001364_13_1) + 8) & 127;
  int stage_v_116_2 = (((stage_v_19_2 * 3) + pub_r001364_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = ((pub_r001364_4_1 * 2) + 44) & 63;
  int stage_v_117_2 = ((pub_r001364_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((sec_r001364_13_1 * 3) + pub_r001364_7_1) + 18) & 127;
  int stage_v_118_2 = (((sec_r001364_13_2 * 3) + pub_r001364_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = (((stage_v_32_1 * 3) + pub_r001364_4_1) + 42) & 127;
  int stage_v_119_2 = (((stage_v_32_2 * 3) + pub_r001364_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = ((pub_r001364_18_1 * 2) + 43) & 63;
  int stage_v_120_2 = ((pub_r001364_18_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001364_1_1 * 2) + 8) & 63;
  int stage_v_121_2 = ((pub_r001364_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001364_1_1 * 2) + 42) & 63;
  int stage_v_122_2 = ((pub_r001364_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (((stage_v_53_1 * 3) + pub_r001364_18_1) + 13) & 127;
  int stage_v_123_2 = (((stage_v_53_2 * 3) + pub_r001364_18_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = ((pub_r001364_18_1 * 2) + 23) & 63;
  int stage_v_124_2 = ((pub_r001364_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001364_8_1 * 2) + 19) & 63;
  int stage_v_125_2 = ((pub_r001364_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((stage_v_49_1 * 3) + pub_r001364_5_1) + 9) & 127;
  int stage_v_126_2 = (((stage_v_49_2 * 3) + pub_r001364_5_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = ((pub_r001364_9_1 * 2) + 47) & 63;
  int stage_v_127_2 = ((pub_r001364_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001364_4_1 * 2) + 6) & 63;
  int stage_v_128_2 = ((pub_r001364_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((stage_v_76_1 * 3) + pub_r001364_18_1) + 8) & 127;
  int stage_v_129_2 = (((stage_v_76_2 * 3) + pub_r001364_18_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = ((pub_r001364_0_1 * 2) + 36) & 63;
  int stage_v_130_2 = ((pub_r001364_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001364_9_1 * 2) + 33) & 63;
  int stage_v_131_2 = ((pub_r001364_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001364_3_1 * 2) + 42) & 63;
  int stage_v_132_2 = ((pub_r001364_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((stage_v_73_1 * 3) + pub_r001364_0_1) + 45) & 127;
  int stage_v_133_2 = (((stage_v_73_2 * 3) + pub_r001364_0_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((stage_v_80_1 * 3) + pub_r001364_8_1) + 10) & 127;
  int stage_v_134_2 = (((stage_v_80_2 * 3) + pub_r001364_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = (((stage_v_115_1 * 3) + pub_r001364_16_1) + 32) & 127;
  int stage_v_135_2 = (((stage_v_115_2 * 3) + pub_r001364_16_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = (((stage_v_61_1 * 3) + pub_r001364_12_1) + 28) & 127;
  int stage_v_136_2 = (((stage_v_61_2 * 3) + pub_r001364_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = ((pub_r001364_6_1 * 2) + 34) & 63;
  int stage_v_137_2 = ((pub_r001364_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((stage_v_104_1 * 3) + pub_r001364_6_1) + 4) & 127;
  int stage_v_138_2 = (((stage_v_104_2 * 3) + pub_r001364_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = (((stage_v_112_1 * 3) + pub_r001364_12_1) + 16) & 127;
  int stage_v_139_2 = (((stage_v_112_2 * 3) + pub_r001364_12_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = ((pub_r001364_16_1 * 2) + 20) & 63;
  int stage_v_140_2 = ((pub_r001364_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001364_4_1 * 2) + 28) & 63;
  int stage_v_141_2 = ((pub_r001364_4_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001364_9_1 * 2) + 43) & 63;
  int stage_v_142_2 = ((pub_r001364_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001364_16_1 * 2) + 5) & 63;
  int stage_v_143_2 = ((pub_r001364_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (((stage_v_83_1 * 3) + pub_r001364_6_1) + 18) & 127;
  int stage_v_144_2 = (((stage_v_83_2 * 3) + pub_r001364_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = (((stage_v_24_1 * 3) + pub_r001364_15_1) + 39) & 127;
  int stage_v_145_2 = (((stage_v_24_2 * 3) + pub_r001364_15_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = ((pub_r001364_8_1 * 2) + 10) & 63;
  int stage_v_146_2 = ((pub_r001364_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001364_1_1 * 2) + 15) & 63;
  int stage_v_147_2 = ((pub_r001364_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_14_1 * 3) + pub_r001364_11_1) + 29) & 127;
  int stage_v_148_2 = (((stage_v_14_2 * 3) + pub_r001364_11_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = (((stage_v_24_1 * 3) + pub_r001364_5_1) + 37) & 127;
  int stage_v_149_2 = (((stage_v_24_2 * 3) + pub_r001364_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = (((sec_r001364_4_1 * 3) + pub_r001364_8_1) + 33) & 127;
  int stage_v_150_2 = (((sec_r001364_4_2 * 3) + pub_r001364_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = (((stage_v_123_1 * 3) + pub_r001364_15_1) + 11) & 127;
  int stage_v_151_2 = (((stage_v_123_2 * 3) + pub_r001364_15_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = (((sec_r001364_11_1 * 3) + pub_r001364_4_1) + 27) & 127;
  int stage_v_152_2 = (((sec_r001364_11_2 * 3) + pub_r001364_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = ((pub_r001364_1_1 * 2) + 41) & 63;
  int stage_v_153_2 = ((pub_r001364_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((stage_v_115_1 * 3) + pub_r001364_2_1) + 8) & 127;
  int stage_v_154_2 = (((stage_v_115_2 * 3) + pub_r001364_2_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = (((helper_flow_2_1 * 3) + pub_r001364_8_1) + 16) & 127;
  int stage_v_155_2 = (((helper_flow_2_2 * 3) + pub_r001364_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = (((stage_v_85_1 * 3) + pub_r001364_17_1) + 44) & 127;
  int stage_v_156_2 = (((stage_v_85_2 * 3) + pub_r001364_17_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((stage_v_20_1 * 3) + pub_r001364_6_1) + 4) & 127;
  int stage_v_157_2 = (((stage_v_20_2 * 3) + pub_r001364_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = (((sec_r001364_17_1 * 3) + pub_r001364_14_1) + 30) & 127;
  int stage_v_158_2 = (((sec_r001364_17_2 * 3) + pub_r001364_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = (((sec_r001364_19_1 * 3) + pub_r001364_7_1) + 13) & 127;
  int stage_v_159_2 = (((sec_r001364_19_2 * 3) + pub_r001364_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = ((pub_r001364_6_1 * 2) + 38) & 63;
  int stage_v_160_2 = ((pub_r001364_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((stage_v_139_1 * 3) + pub_r001364_18_1) + 43) & 127;
  int stage_v_161_2 = (((stage_v_139_2 * 3) + pub_r001364_18_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = ((pub_r001364_2_1 * 2) + 32) & 63;
  int stage_v_162_2 = ((pub_r001364_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (((stage_v_112_1 * 3) + pub_r001364_16_1) + 19) & 127;
  int stage_v_163_2 = (((stage_v_112_2 * 3) + pub_r001364_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = (((stage_v_94_1 * 3) + pub_r001364_11_1) + 12) & 127;
  int stage_v_164_2 = (((stage_v_94_2 * 3) + pub_r001364_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = (((stage_v_99_1 * 3) + pub_r001364_6_1) + 33) & 127;
  int stage_v_165_2 = (((stage_v_99_2 * 3) + pub_r001364_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = ((pub_r001364_11_1 * 2) + 9) & 63;
  int stage_v_166_2 = ((pub_r001364_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((stage_v_37_1 * 3) + pub_r001364_0_1) + 44) & 127;
  int stage_v_167_2 = (((stage_v_37_2 * 3) + pub_r001364_0_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = ((pub_r001364_15_1 * 2) + 31) & 63;
  int stage_v_168_2 = ((pub_r001364_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001364_15_1 * 2) + 13) & 63;
  int stage_v_169_2 = ((pub_r001364_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (((stage_v_119_1 * 3) + pub_r001364_13_1) + 13) & 127;
  int stage_v_170_2 = (((stage_v_119_2 * 3) + pub_r001364_13_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = (((stage_v_104_1 * 3) + pub_r001364_13_1) + 16) & 127;
  int stage_v_171_2 = (((stage_v_104_2 * 3) + pub_r001364_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = (((stage_v_67_1 * 3) + pub_r001364_18_1) + 9) & 127;
  int stage_v_172_2 = (((stage_v_67_2 * 3) + pub_r001364_18_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = ((pub_r001364_9_1 * 2) + 9) & 63;
  int stage_v_173_2 = ((pub_r001364_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (((stage_v_96_1 * 3) + pub_r001364_15_1) + 16) & 127;
  int stage_v_174_2 = (((stage_v_96_2 * 3) + pub_r001364_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = (((sec_r001364_14_1 * 3) + pub_r001364_16_1) + 11) & 127;
  int stage_v_175_2 = (((sec_r001364_14_2 * 3) + pub_r001364_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = (((stage_v_161_1 * 3) + pub_r001364_15_1) + 45) & 127;
  int stage_v_176_2 = (((stage_v_161_2 * 3) + pub_r001364_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = ((pub_r001364_4_1 * 2) + 41) & 63;
  int stage_v_177_2 = ((pub_r001364_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001364_1_1 * 2) + 18) & 63;
  int stage_v_178_2 = ((pub_r001364_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001364_12_1 * 2) + 24) & 63;
  int stage_v_179_2 = ((pub_r001364_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((stage_v_19_1 * 3) + pub_r001364_16_1) + 12) & 127;
  int stage_v_180_2 = (((stage_v_19_2 * 3) + pub_r001364_16_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = (((sec_r001364_20_1 * 3) + pub_r001364_17_1) + 36) & 127;
  int stage_v_181_2 = (((sec_r001364_20_2 * 3) + pub_r001364_17_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = (((stage_v_174_1 * 3) + pub_r001364_11_1) + 12) & 127;
  int stage_v_182_2 = (((stage_v_174_2 * 3) + pub_r001364_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = (((stage_v_167_1 * 3) + pub_r001364_10_1) + 9) & 127;
  int stage_v_183_2 = (((stage_v_167_2 * 3) + pub_r001364_10_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = ((pub_r001364_14_1 * 2) + 43) & 63;
  int stage_v_184_2 = ((pub_r001364_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((stage_v_4_1 * 3) + pub_r001364_3_1) + 25) & 127;
  int stage_v_185_2 = (((stage_v_4_2 * 3) + pub_r001364_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = ((pub_r001364_17_1 * 2) + 31) & 63;
  int stage_v_186_2 = ((pub_r001364_17_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001364_15_1 * 2) + 29) & 63;
  int stage_v_187_2 = ((pub_r001364_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001364_8_1 * 2) + 10) & 63;
  int stage_v_188_2 = ((pub_r001364_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (((sec_r001364_19_1 * 3) + pub_r001364_5_1) + 11) & 127;
  int stage_v_189_2 = (((sec_r001364_19_2 * 3) + pub_r001364_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = ((pub_r001364_0_1 * 2) + 35) & 63;
  int stage_v_190_2 = ((pub_r001364_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (((stage_v_76_1 * 3) + pub_r001364_9_1) + 20) & 127;
  int stage_v_191_2 = (((stage_v_76_2 * 3) + pub_r001364_9_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = ((pub_r001364_17_1 * 2) + 21) & 63;
  int stage_v_192_2 = ((pub_r001364_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((stage_v_136_1 * 3) + pub_r001364_11_1) + 33) & 127;
  int stage_v_193_2 = (((stage_v_136_2 * 3) + pub_r001364_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = (((stage_v_112_1 * 3) + pub_r001364_10_1) + 20) & 127;
  int stage_v_194_2 = (((stage_v_112_2 * 3) + pub_r001364_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = (((stage_v_49_1 * 3) + pub_r001364_3_1) + 9) & 127;
  int stage_v_195_2 = (((stage_v_49_2 * 3) + pub_r001364_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = (((stage_v_170_1 * 3) + pub_r001364_4_1) + 42) & 127;
  int stage_v_196_2 = (((stage_v_170_2 * 3) + pub_r001364_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = ((pub_r001364_1_1 * 2) + 10) & 63;
  int stage_v_197_2 = ((pub_r001364_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((sec_r001364_2_1 * 3) + pub_r001364_0_1) + 23) & 127;
  int stage_v_198_2 = (((sec_r001364_2_2 * 3) + pub_r001364_0_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = (((stage_v_151_1 * 3) + pub_r001364_18_1) + 33) & 127;
  int stage_v_199_2 = (((stage_v_151_2 * 3) + pub_r001364_18_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = ((pub_r001364_15_1 * 2) + 28) & 63;
  int stage_v_200_2 = ((pub_r001364_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001364_18_1 * 2) + 15) & 63;
  int stage_v_201_2 = ((pub_r001364_18_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((stage_v_118_1 * 3) + pub_r001364_11_1) + 4) & 127;
  int stage_v_202_2 = (((stage_v_118_2 * 3) + pub_r001364_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = ((pub_r001364_8_1 * 2) + 16) & 63;
  int stage_v_203_2 = ((pub_r001364_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001364_1_1 * 2) + 12) & 63;
  int stage_v_204_2 = ((pub_r001364_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((pub_r001364_13_1 * 2) + 28) & 63;
  int stage_v_205_2 = ((pub_r001364_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = (((stage_v_152_1 * 3) + pub_r001364_18_1) + 24) & 127;
  int stage_v_206_2 = (((stage_v_152_2 * 3) + pub_r001364_18_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = ((pub_r001364_2_1 * 2) + 23) & 63;
  int stage_v_207_2 = ((pub_r001364_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001364_17_1 * 2) + 41) & 63;
  int stage_v_208_2 = ((pub_r001364_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001364_6_1 * 2) + 25) & 63;
  int stage_v_209_2 = ((pub_r001364_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = (((stage_v_152_1 * 3) + pub_r001364_18_1) + 13) & 127;
  int stage_v_210_2 = (((stage_v_152_2 * 3) + pub_r001364_18_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = (((stage_v_74_1 * 3) + pub_r001364_16_1) + 31) & 127;
  int stage_v_211_2 = (((stage_v_74_2 * 3) + pub_r001364_16_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = ((pub_r001364_17_1 * 2) + 48) & 63;
  int stage_v_212_2 = ((pub_r001364_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001364_12_1 * 2) + 27) & 63;
  int stage_v_213_2 = ((pub_r001364_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001364_8_1 * 2) + 13) & 63;
  int stage_v_214_2 = ((pub_r001364_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((stage_v_194_1 * 3) + pub_r001364_0_1) + 29) & 127;
  int stage_v_215_2 = (((stage_v_194_2 * 3) + pub_r001364_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = ((pub_r001364_4_1 * 2) + 12) & 63;
  int stage_v_216_2 = ((pub_r001364_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((stage_v_32_1 * 3) + pub_r001364_14_1) + 9) & 127;
  int stage_v_217_2 = (((stage_v_32_2 * 3) + pub_r001364_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = (((stage_v_91_1 * 3) + pub_r001364_13_1) + 37) & 127;
  int stage_v_218_2 = (((stage_v_91_2 * 3) + pub_r001364_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = ((pub_r001364_17_1 * 2) + 19) & 63;
  int stage_v_219_2 = ((pub_r001364_17_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = (((stage_v_22_1 * 3) + pub_r001364_8_1) + 15) & 127;
  int stage_v_220_2 = (((stage_v_22_2 * 3) + pub_r001364_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = (((stage_v_87_1 * 3) + pub_r001364_18_1) + 6) & 127;
  int stage_v_221_2 = (((stage_v_87_2 * 3) + pub_r001364_18_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = ((pub_r001364_15_1 * 2) + 28) & 63;
  int stage_v_222_2 = ((pub_r001364_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((pub_r001364_6_1 * 2) + 41) & 63;
  int stage_v_223_2 = ((pub_r001364_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = (((stage_v_144_1 * 3) + pub_r001364_18_1) + 43) & 127;
  int stage_v_224_2 = (((stage_v_144_2 * 3) + pub_r001364_18_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = (((helper_flow_3_1 * 3) + pub_r001364_2_1) + 16) & 127;
  int stage_v_225_2 = (((helper_flow_3_2 * 3) + pub_r001364_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = ((pub_r001364_10_1 * 2) + 23) & 63;
  int stage_v_226_2 = ((pub_r001364_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((pub_r001364_7_1 * 2) + 18) & 63;
  int stage_v_227_2 = ((pub_r001364_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001364_6_1 * 2) + 5) & 63;
  int stage_v_228_2 = ((pub_r001364_6_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001364_3_1 * 2) + 15) & 63;
  int stage_v_229_2 = ((pub_r001364_3_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = (((helper_flow_3_1 * 3) + pub_r001364_6_1) + 11) & 127;
  int stage_v_230_2 = (((helper_flow_3_2 * 3) + pub_r001364_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = (((stage_v_154_1 * 3) + pub_r001364_5_1) + 19) & 127;
  int stage_v_231_2 = (((stage_v_154_2 * 3) + pub_r001364_5_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = ((pub_r001364_13_1 * 2) + 30) & 63;
  int stage_v_232_2 = ((pub_r001364_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = (((sec_r001364_9_1 * 3) + pub_r001364_3_1) + 6) & 127;
  int stage_v_233_2 = (((sec_r001364_9_2 * 3) + pub_r001364_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = (((stage_v_150_1 * 3) + pub_r001364_9_1) + 19) & 127;
  int stage_v_234_2 = (((stage_v_150_2 * 3) + pub_r001364_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = (((stage_v_38_1 * 3) + pub_r001364_3_1) + 11) & 127;
  int stage_v_235_2 = (((stage_v_38_2 * 3) + pub_r001364_3_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = ((pub_r001364_4_1 * 2) + 34) & 63;
  int stage_v_236_2 = ((pub_r001364_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001364_12_1 * 2) + 33) & 63;
  int stage_v_237_2 = ((pub_r001364_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001364_0_1 * 2) + 48) & 63;
  int stage_v_238_2 = ((pub_r001364_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = (((helper_flow_3_1 * 3) + pub_r001364_13_1) + 18) & 127;
  int stage_v_239_2 = (((helper_flow_3_2 * 3) + pub_r001364_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = (((stage_v_64_1 * 3) + pub_r001364_8_1) + 9) & 127;
  int stage_v_240_2 = (((stage_v_64_2 * 3) + pub_r001364_8_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = (((sec_r001364_12_1 * 3) + pub_r001364_14_1) + 6) & 127;
  int stage_v_241_2 = (((sec_r001364_12_2 * 3) + pub_r001364_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = (((stage_v_71_1 * 3) + pub_r001364_13_1) + 41) & 127;
  int stage_v_242_2 = (((stage_v_71_2 * 3) + pub_r001364_13_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = ((pub_r001364_6_1 * 2) + 50) & 63;
  int stage_v_243_2 = ((pub_r001364_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = (((stage_v_191_1 * 3) + pub_r001364_11_1) + 43) & 127;
  int stage_v_244_2 = (((stage_v_191_2 * 3) + pub_r001364_11_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = ((pub_r001364_1_1 * 2) + 42) & 63;
  int stage_v_245_2 = ((pub_r001364_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = (((stage_v_2_1 * 3) + pub_r001364_17_1) + 11) & 127;
  int stage_v_246_2 = (((stage_v_2_2 * 3) + pub_r001364_17_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = ((pub_r001364_9_1 * 2) + 40) & 63;
  int stage_v_247_2 = ((pub_r001364_9_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = (((stage_v_135_1 * 3) + pub_r001364_16_1) + 38) & 127;
  int stage_v_248_2 = (((stage_v_135_2 * 3) + pub_r001364_16_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = (((stage_v_114_1 * 3) + pub_r001364_0_1) + 30) & 127;
  int stage_v_249_2 = (((stage_v_114_2 * 3) + pub_r001364_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = (((stage_v_119_1 * 3) + pub_r001364_8_1) + 45) & 127;
  int stage_v_250_2 = (((stage_v_119_2 * 3) + pub_r001364_8_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = (((stage_v_105_1 * 3) + pub_r001364_17_1) + 30) & 127;
  int stage_v_251_2 = (((stage_v_105_2 * 3) + pub_r001364_17_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = (((stage_v_211_1 * 3) + pub_r001364_5_1) + 32) & 127;
  int stage_v_252_2 = (((stage_v_211_2 * 3) + pub_r001364_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = (((sec_r001364_17_1 * 3) + pub_r001364_10_1) + 37) & 127;
  int stage_v_253_2 = (((sec_r001364_17_2 * 3) + pub_r001364_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = (((stage_v_170_1 * 3) + pub_r001364_13_1) + 20) & 127;
  int stage_v_254_2 = (((stage_v_170_2 * 3) + pub_r001364_13_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = ((pub_r001364_8_1 * 2) + 21) & 63;
  int stage_v_255_2 = ((pub_r001364_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = (((stage_v_230_1 * 3) + pub_r001364_12_1) + 40) & 127;
  int stage_v_256_2 = (((stage_v_230_2 * 3) + pub_r001364_12_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = (((stage_v_42_1 * 3) + pub_r001364_1_1) + 26) & 127;
  int stage_v_257_2 = (((stage_v_42_2 * 3) + pub_r001364_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = ((pub_r001364_13_1 * 2) + 22) & 63;
  int stage_v_258_2 = ((pub_r001364_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((pub_r001364_12_1 * 2) + 29) & 63;
  int stage_v_259_2 = ((pub_r001364_12_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = (((stage_v_183_1 * 3) + pub_r001364_4_1) + 41) & 127;
  int stage_v_260_2 = (((stage_v_183_2 * 3) + pub_r001364_4_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = (((stage_v_126_1 * 3) + pub_r001364_4_1) + 11) & 127;
  int stage_v_261_2 = (((stage_v_126_2 * 3) + pub_r001364_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = ((pub_r001364_15_1 * 2) + 29) & 63;
  int stage_v_262_2 = ((pub_r001364_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = (((stage_v_206_1 * 3) + pub_r001364_0_1) + 15) & 127;
  int stage_v_263_2 = (((stage_v_206_2 * 3) + pub_r001364_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = ((pub_r001364_12_1 * 2) + 40) & 63;
  int stage_v_264_2 = ((pub_r001364_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = (((stage_v_198_1 * 3) + pub_r001364_5_1) + 11) & 127;
  int stage_v_265_2 = (((stage_v_198_2 * 3) + pub_r001364_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = (((stage_v_175_1 * 3) + pub_r001364_7_1) + 3) & 127;
  int stage_v_266_2 = (((stage_v_175_2 * 3) + pub_r001364_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = ((pub_r001364_13_1 * 2) + 26) & 63;
  int stage_v_267_2 = ((pub_r001364_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = (((stage_v_254_1 * 3) + pub_r001364_8_1) + 34) & 127;
  int stage_v_268_2 = (((stage_v_254_2 * 3) + pub_r001364_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = ((pub_r001364_18_1 * 2) + 9) & 63;
  int stage_v_269_2 = ((pub_r001364_18_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001364_16_1 * 2) + 6) & 63;
  int stage_v_270_2 = ((pub_r001364_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001364_12_1 * 2) + 44) & 63;
  int stage_v_271_2 = ((pub_r001364_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = (((stage_v_104_1 * 3) + pub_r001364_4_1) + 12) & 127;
  int stage_v_272_2 = (((stage_v_104_2 * 3) + pub_r001364_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = ((pub_r001364_5_1 * 2) + 34) & 63;
  int stage_v_273_2 = ((pub_r001364_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = (((stage_v_183_1 * 3) + pub_r001364_18_1) + 43) & 127;
  int stage_v_274_2 = (((stage_v_183_2 * 3) + pub_r001364_18_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = (((stage_v_215_1 * 3) + pub_r001364_5_1) + 35) & 127;
  int stage_v_275_2 = (((stage_v_215_2 * 3) + pub_r001364_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = (((stage_v_260_1 * 3) + pub_r001364_18_1) + 26) & 127;
  int stage_v_276_2 = (((stage_v_260_2 * 3) + pub_r001364_18_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = (((stage_v_91_1 * 3) + pub_r001364_6_1) + 7) & 127;
  int stage_v_277_2 = (((stage_v_91_2 * 3) + pub_r001364_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = (((stage_v_31_1 * 3) + pub_r001364_16_1) + 11) & 127;
  int stage_v_278_2 = (((stage_v_31_2 * 3) + pub_r001364_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = (((stage_v_10_1 * 3) + pub_r001364_18_1) + 23) & 127;
  int stage_v_279_2 = (((stage_v_10_2 * 3) + pub_r001364_18_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = (((stage_v_50_1 * 3) + pub_r001364_1_1) + 15) & 127;
  int stage_v_280_2 = (((stage_v_50_2 * 3) + pub_r001364_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = ((pub_r001364_12_1 * 2) + 30) & 63;
  int stage_v_281_2 = ((pub_r001364_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = (((stage_v_48_1 * 3) + pub_r001364_11_1) + 6) & 127;
  int stage_v_282_2 = (((stage_v_48_2 * 3) + pub_r001364_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = (((stage_v_235_1 * 3) + pub_r001364_16_1) + 23) & 127;
  int stage_v_283_2 = (((stage_v_235_2 * 3) + pub_r001364_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = (((stage_v_210_1 * 3) + pub_r001364_15_1) + 16) & 127;
  int stage_v_284_2 = (((stage_v_210_2 * 3) + pub_r001364_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = (((stage_v_87_1 * 3) + pub_r001364_15_1) + 21) & 127;
  int stage_v_285_2 = (((stage_v_87_2 * 3) + pub_r001364_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = (((stage_v_10_1 * 3) + pub_r001364_1_1) + 45) & 127;
  int stage_v_286_2 = (((stage_v_10_2 * 3) + pub_r001364_1_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = ((pub_r001364_4_1 * 2) + 5) & 63;
  int stage_v_287_2 = ((pub_r001364_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((pub_r001364_1_1 * 2) + 30) & 63;
  int stage_v_288_2 = ((pub_r001364_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = (((stage_v_261_1 * 3) + pub_r001364_2_1) + 27) & 127;
  int stage_v_289_2 = (((stage_v_261_2 * 3) + pub_r001364_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = (((stage_v_235_1 * 3) + pub_r001364_1_1) + 34) & 127;
  int stage_v_290_2 = (((stage_v_235_2 * 3) + pub_r001364_1_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = ((pub_r001364_0_1 * 2) + 6) & 63;
  int stage_v_291_2 = ((pub_r001364_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = (((sec_r001364_0_1 * 3) + pub_r001364_14_1) + 38) & 127;
  int stage_v_292_2 = (((sec_r001364_0_2 * 3) + pub_r001364_14_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = (((stage_v_22_1 * 3) + pub_r001364_0_1) + 22) & 127;
  int stage_v_293_2 = (((stage_v_22_2 * 3) + pub_r001364_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = (((stage_v_221_1 * 3) + pub_r001364_18_1) + 20) & 127;
  int stage_v_294_2 = (((stage_v_221_2 * 3) + pub_r001364_18_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = ((pub_r001364_11_1 * 2) + 9) & 63;
  int stage_v_295_2 = ((pub_r001364_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = (((stage_v_104_1 * 3) + pub_r001364_1_1) + 8) & 127;
  int stage_v_296_2 = (((stage_v_104_2 * 3) + pub_r001364_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = ((pub_r001364_6_1 * 2) + 13) & 63;
  int stage_v_297_2 = ((pub_r001364_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = (((stage_v_289_1 * 3) + pub_r001364_16_1) + 30) & 127;
  int stage_v_298_2 = (((stage_v_289_2 * 3) + pub_r001364_16_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = ((pub_r001364_7_1 * 2) + 6) & 63;
  int stage_v_299_2 = ((pub_r001364_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = (((stage_v_156_1 * 3) + pub_r001364_0_1) + 32) & 127;
  int stage_v_300_2 = (((stage_v_156_2 * 3) + pub_r001364_0_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = ((pub_r001364_5_1 * 2) + 48) & 63;
  int stage_v_301_2 = ((pub_r001364_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001364_17_1 * 2) + 21) & 63;
  int stage_v_302_2 = ((pub_r001364_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = (((stage_v_257_1 * 3) + pub_r001364_1_1) + 24) & 127;
  int stage_v_303_2 = (((stage_v_257_2 * 3) + pub_r001364_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = ((pub_r001364_9_1 * 2) + 18) & 63;
  int stage_v_304_2 = ((pub_r001364_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001364_16_1 * 2) + 17) & 63;
  int stage_v_305_2 = ((pub_r001364_16_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001364_3_1 * 2) + 31) & 63;
  int stage_v_306_2 = ((pub_r001364_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = (((stage_v_23_1 * 3) + pub_r001364_6_1) + 45) & 127;
  int stage_v_307_2 = (((stage_v_23_2 * 3) + pub_r001364_6_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = ((pub_r001364_12_1 * 2) + 45) & 63;
  int stage_v_308_2 = ((pub_r001364_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = (((stage_v_189_1 * 3) + pub_r001364_0_1) + 41) & 127;
  int stage_v_309_2 = (((stage_v_189_2 * 3) + pub_r001364_0_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = ((pub_r001364_13_1 * 2) + 17) & 63;
  int stage_v_310_2 = ((pub_r001364_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = (((stage_v_126_1 * 3) + pub_r001364_8_1) + 18) & 127;
  int stage_v_311_2 = (((stage_v_126_2 * 3) + pub_r001364_8_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = ((pub_r001364_18_1 * 2) + 50) & 63;
  int stage_v_312_2 = ((pub_r001364_18_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = (((helper_flow_2_1 * 3) + pub_r001364_10_1) + 38) & 127;
  int stage_v_313_2 = (((helper_flow_2_2 * 3) + pub_r001364_10_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = ((pub_r001364_12_1 * 2) + 8) & 63;
  int stage_v_314_2 = ((pub_r001364_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001364_9_1 * 2) + 17) & 63;
  int stage_v_315_2 = ((pub_r001364_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = (((stage_v_19_1 * 3) + pub_r001364_15_1) + 37) & 127;
  int stage_v_316_2 = (((stage_v_19_2 * 3) + pub_r001364_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = (((sec_r001364_0_1 * 3) + pub_r001364_5_1) + 32) & 127;
  int stage_v_317_2 = (((sec_r001364_0_2 * 3) + pub_r001364_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = (((stage_v_181_1 * 3) + pub_r001364_9_1) + 32) & 127;
  int stage_v_318_2 = (((stage_v_181_2 * 3) + pub_r001364_9_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = (((stage_v_138_1 * 3) + pub_r001364_9_1) + 17) & 127;
  int stage_v_319_2 = (((stage_v_138_2 * 3) + pub_r001364_9_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = ((pub_r001364_1_1 * 2) + 47) & 63;
  int stage_v_320_2 = ((pub_r001364_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = ((pub_r001364_4_1 * 2) + 22) & 63;
  int stage_v_321_2 = ((pub_r001364_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = (((stage_v_249_1 * 3) + pub_r001364_8_1) + 21) & 127;
  int stage_v_322_2 = (((stage_v_249_2 * 3) + pub_r001364_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = (((stage_v_19_1 * 3) + pub_r001364_16_1) + 5) & 127;
  int stage_v_323_2 = (((stage_v_19_2 * 3) + pub_r001364_16_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_323_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_323_2 * 2)) & 255;
  int stage_v_324_1 = ((pub_r001364_8_1 * 2) + 47) & 63;
  int stage_v_324_2 = ((pub_r001364_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((pub_r001364_11_1 * 2) + 44) & 63;
  int stage_v_325_2 = ((pub_r001364_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((pub_r001364_11_1 * 2) + 31) & 63;
  int stage_v_326_2 = ((pub_r001364_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001364_1_1 * 2) + 50) & 63;
  int stage_v_327_2 = ((pub_r001364_1_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = (((stage_v_150_1 * 3) + pub_r001364_4_1) + 27) & 127;
  int stage_v_328_2 = (((stage_v_150_2 * 3) + pub_r001364_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = ((pub_r001364_3_1 * 2) + 13) & 63;
  int stage_v_329_2 = ((pub_r001364_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001364_3_1 * 2) + 34) & 63;
  int stage_v_330_2 = ((pub_r001364_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001364_10_1 * 2) + 47) & 63;
  int stage_v_331_2 = ((pub_r001364_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = (((sec_r001364_7_1 * 3) + pub_r001364_9_1) + 3) & 127;
  int stage_v_332_2 = (((sec_r001364_7_2 * 3) + pub_r001364_9_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = ((pub_r001364_18_1 * 2) + 18) & 63;
  int stage_v_333_2 = ((pub_r001364_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((pub_r001364_18_1 * 2) + 28) & 63;
  int stage_v_334_2 = ((pub_r001364_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((pub_r001364_0_1 * 2) + 17) & 63;
  int stage_v_335_2 = ((pub_r001364_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((pub_r001364_15_1 * 2) + 11) & 63;
  int stage_v_336_2 = ((pub_r001364_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((pub_r001364_17_1 * 2) + 42) & 63;
  int stage_v_337_2 = ((pub_r001364_17_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = (((stage_v_91_1 * 3) + pub_r001364_17_1) + 11) & 127;
  int stage_v_338_2 = (((stage_v_91_2 * 3) + pub_r001364_17_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = (((stage_v_150_1 * 3) + pub_r001364_3_1) + 27) & 127;
  int stage_v_339_2 = (((stage_v_150_2 * 3) + pub_r001364_3_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = (((stage_v_115_1 * 3) + pub_r001364_5_1) + 7) & 127;
  int stage_v_340_2 = (((stage_v_115_2 * 3) + pub_r001364_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = ((pub_r001364_5_1 * 2) + 18) & 63;
  int stage_v_341_2 = ((pub_r001364_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((pub_r001364_4_1 * 2) + 33) & 63;
  int stage_v_342_2 = ((pub_r001364_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = (((stage_v_323_1 * 3) + pub_r001364_8_1) + 35) & 127;
  int stage_v_343_2 = (((stage_v_323_2 * 3) + pub_r001364_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = (((stage_v_14_1 * 3) + pub_r001364_18_1) + 5) & 127;
  int stage_v_344_2 = (((stage_v_14_2 * 3) + pub_r001364_18_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = ((pub_r001364_3_1 * 2) + 6) & 63;
  int stage_v_345_2 = ((pub_r001364_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((pub_r001364_3_1 * 2) + 27) & 63;
  int stage_v_346_2 = ((pub_r001364_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = (((stage_v_150_1 * 3) + pub_r001364_0_1) + 21) & 127;
  int stage_v_347_2 = (((stage_v_150_2 * 3) + pub_r001364_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = (((stage_v_159_1 * 3) + pub_r001364_18_1) + 23) & 127;
  int stage_v_348_2 = (((stage_v_159_2 * 3) + pub_r001364_18_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = ((pub_r001364_17_1 * 2) + 34) & 63;
  int stage_v_349_2 = ((pub_r001364_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = (((stage_v_195_1 * 3) + pub_r001364_10_1) + 10) & 127;
  int stage_v_350_2 = (((stage_v_195_2 * 3) + pub_r001364_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = (((sec_r001364_1_1 * 3) + pub_r001364_17_1) + 17) & 127;
  int stage_v_351_2 = (((sec_r001364_1_2 * 3) + pub_r001364_17_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = (((stage_v_24_1 * 3) + pub_r001364_9_1) + 34) & 127;
  int stage_v_352_2 = (((stage_v_24_2 * 3) + pub_r001364_9_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = ((pub_r001364_3_1 * 2) + 24) & 63;
  int stage_v_353_2 = ((pub_r001364_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = (((stage_v_328_1 * 3) + pub_r001364_1_1) + 8) & 127;
  int stage_v_354_2 = (((stage_v_328_2 * 3) + pub_r001364_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = (((stage_v_338_1 * 3) + pub_r001364_14_1) + 27) & 127;
  int stage_v_355_2 = (((stage_v_338_2 * 3) + pub_r001364_14_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = ((pub_r001364_12_1 * 2) + 35) & 63;
  int stage_v_356_2 = ((pub_r001364_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((pub_r001364_6_1 * 2) + 21) & 63;
  int stage_v_357_2 = ((pub_r001364_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = (((stage_v_108_1 * 3) + pub_r001364_3_1) + 28) & 127;
  int stage_v_358_2 = (((stage_v_108_2 * 3) + pub_r001364_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = ((pub_r001364_17_1 * 2) + 49) & 63;
  int stage_v_359_2 = ((pub_r001364_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = (((stage_v_220_1 * 3) + pub_r001364_16_1) + 13) & 127;
  int stage_v_360_2 = (((stage_v_220_2 * 3) + pub_r001364_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = ((pub_r001364_0_1 * 2) + 17) & 63;
  int stage_v_361_2 = ((pub_r001364_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001364_2_1 * 2) + 7) & 63;
  int stage_v_362_2 = ((pub_r001364_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001364_2_1 * 2) + 22) & 63;
  int stage_v_363_2 = ((pub_r001364_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((pub_r001364_8_1 * 2) + 23) & 63;
  int stage_v_364_2 = ((pub_r001364_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001364_18_1 * 2) + 23) & 63;
  int stage_v_365_2 = ((pub_r001364_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((pub_r001364_11_1 * 2) + 38) & 63;
  int stage_v_366_2 = ((pub_r001364_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = (((stage_v_351_1 * 3) + pub_r001364_10_1) + 39) & 127;
  int stage_v_367_2 = (((stage_v_351_2 * 3) + pub_r001364_10_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = ((pub_r001364_2_1 * 2) + 21) & 63;
  int stage_v_368_2 = ((pub_r001364_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001364_5_1 * 2) + 11) & 63;
  int stage_v_369_2 = ((pub_r001364_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = (((helper_flow_1_1 * 3) + pub_r001364_1_1) + 23) & 127;
  int stage_v_370_2 = (((helper_flow_1_2 * 3) + pub_r001364_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = ((pub_r001364_10_1 * 2) + 22) & 63;
  int stage_v_371_2 = ((pub_r001364_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = (((stage_v_355_1 * 3) + pub_r001364_17_1) + 40) & 127;
  int stage_v_372_2 = (((stage_v_355_2 * 3) + pub_r001364_17_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_372_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_372_2 * 2)) & 255;
  int stage_v_373_1 = (((stage_v_279_1 * 3) + pub_r001364_10_1) + 12) & 127;
  int stage_v_373_2 = (((stage_v_279_2 * 3) + pub_r001364_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = (((helper_flow_3_1 * 3) + pub_r001364_3_1) + 39) & 127;
  int stage_v_374_2 = (((helper_flow_3_2 * 3) + pub_r001364_3_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_52_1 * 3) + pub_r001364_1_1) + 29) & 127;
  int stage_v_375_2 = (((stage_v_52_2 * 3) + pub_r001364_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = ((pub_r001364_6_1 * 2) + 10) & 63;
  int stage_v_376_2 = ((pub_r001364_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = (((stage_v_126_1 * 3) + pub_r001364_14_1) + 12) & 127;
  int stage_v_377_2 = (((stage_v_126_2 * 3) + pub_r001364_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = (((stage_v_279_1 * 3) + pub_r001364_18_1) + 21) & 127;
  int stage_v_378_2 = (((stage_v_279_2 * 3) + pub_r001364_18_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = (((stage_v_135_1 * 3) + pub_r001364_4_1) + 25) & 127;
  int stage_v_379_2 = (((stage_v_135_2 * 3) + pub_r001364_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = ((pub_r001364_9_1 * 2) + 16) & 63;
  int stage_v_380_2 = ((pub_r001364_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = ((pub_r001364_15_1 * 2) + 24) & 63;
  int stage_v_381_2 = ((pub_r001364_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = (((stage_v_231_1 * 3) + pub_r001364_13_1) + 18) & 127;
  int stage_v_382_2 = (((stage_v_231_2 * 3) + pub_r001364_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = (((stage_v_133_1 * 3) + pub_r001364_9_1) + 29) & 127;
  int stage_v_383_2 = (((stage_v_133_2 * 3) + pub_r001364_9_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = ((pub_r001364_1_1 * 2) + 23) & 63;
  int stage_v_384_2 = ((pub_r001364_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = (((stage_v_104_1 * 3) + pub_r001364_7_1) + 13) & 127;
  int stage_v_385_2 = (((stage_v_104_2 * 3) + pub_r001364_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = ((pub_r001364_7_1 * 2) + 36) & 63;
  int stage_v_386_2 = ((pub_r001364_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((pub_r001364_2_1 * 2) + 15) & 63;
  int stage_v_387_2 = ((pub_r001364_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = ((pub_r001364_9_1 * 2) + 31) & 63;
  int stage_v_388_2 = ((pub_r001364_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((pub_r001364_18_1 * 2) + 32) & 63;
  int stage_v_389_2 = ((pub_r001364_18_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = ((pub_r001364_5_1 * 2) + 46) & 63;
  int stage_v_390_2 = ((pub_r001364_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = (((stage_v_338_1 * 3) + pub_r001364_16_1) + 34) & 127;
  int stage_v_391_2 = (((stage_v_338_2 * 3) + pub_r001364_16_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = (((stage_v_115_1 * 3) + pub_r001364_5_1) + 43) & 127;
  int stage_v_392_2 = (((stage_v_115_2 * 3) + pub_r001364_5_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = ((pub_r001364_17_1 * 2) + 32) & 63;
  int stage_v_393_2 = ((pub_r001364_17_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((pub_r001364_7_1 * 2) + 33) & 63;
  int stage_v_394_2 = ((pub_r001364_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = (((helper_flow_2_1 * 3) + pub_r001364_2_1) + 23) & 127;
  int stage_v_395_2 = (((helper_flow_2_2 * 3) + pub_r001364_2_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_395_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_395_2 * 2)) & 255;
  int stage_v_396_1 = ((pub_r001364_1_1 * 2) + 20) & 63;
  int stage_v_396_2 = ((pub_r001364_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = ((pub_r001364_11_1 * 2) + 17) & 63;
  int stage_v_397_2 = ((pub_r001364_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = (((stage_v_39_1 * 3) + pub_r001364_3_1) + 6) & 127;
  int stage_v_398_2 = (((stage_v_39_2 * 3) + pub_r001364_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = ((pub_r001364_10_1 * 2) + 30) & 63;
  int stage_v_399_2 = ((pub_r001364_10_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = (((stage_v_251_1 * 3) + pub_r001364_0_1) + 43) & 127;
  int stage_v_400_2 = (((stage_v_251_2 * 3) + pub_r001364_0_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_400_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_400_2 * 2)) & 255;
  int stage_v_401_1 = ((pub_r001364_4_1 * 2) + 16) & 63;
  int stage_v_401_2 = ((pub_r001364_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = ((pub_r001364_17_1 * 2) + 27) & 63;
  int stage_v_402_2 = ((pub_r001364_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = (((stage_v_155_1 * 3) + pub_r001364_3_1) + 32) & 127;
  int stage_v_403_2 = (((stage_v_155_2 * 3) + pub_r001364_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_403_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_403_2 * 2)) & 255;
  int stage_v_404_1 = ((pub_r001364_13_1 * 2) + 32) & 63;
  int stage_v_404_2 = ((pub_r001364_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = ((pub_r001364_1_1 * 2) + 47) & 63;
  int stage_v_405_2 = ((pub_r001364_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = (((stage_v_194_1 * 3) + pub_r001364_15_1) + 38) & 127;
  int stage_v_406_2 = (((stage_v_194_2 * 3) + pub_r001364_15_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_406_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_406_2 * 2)) & 255;
  int stage_v_407_1 = (((stage_v_360_1 * 3) + pub_r001364_8_1) + 41) & 127;
  int stage_v_407_2 = (((stage_v_360_2 * 3) + pub_r001364_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_407_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_407_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_407_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_407_2 * 2)) & 255;
  int stage_v_408_1 = ((pub_r001364_1_1 * 2) + 41) & 63;
  int stage_v_408_2 = ((pub_r001364_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = (((stage_v_344_1 * 3) + pub_r001364_9_1) + 41) & 127;
  int stage_v_409_2 = (((stage_v_344_2 * 3) + pub_r001364_9_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_409_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_409_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_409_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_409_2 * 2)) & 255;
  int stage_v_410_1 = ((pub_r001364_15_1 * 2) + 46) & 63;
  int stage_v_410_2 = ((pub_r001364_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = (((stage_v_211_1 * 3) + pub_r001364_13_1) + 27) & 127;
  int stage_v_411_2 = (((stage_v_211_2 * 3) + pub_r001364_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_411_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_411_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_411_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_411_2 * 2)) & 255;
  int stage_v_412_1 = ((pub_r001364_13_1 * 2) + 17) & 63;
  int stage_v_412_2 = ((pub_r001364_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = ((pub_r001364_15_1 * 2) + 34) & 63;
  int stage_v_413_2 = ((pub_r001364_15_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((pub_r001364_11_1 * 2) + 26) & 63;
  int stage_v_414_2 = ((pub_r001364_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = ((pub_r001364_16_1 * 2) + 35) & 63;
  int stage_v_415_2 = ((pub_r001364_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = (((stage_v_354_1 * 3) + pub_r001364_2_1) + 18) & 127;
  int stage_v_416_2 = (((stage_v_354_2 * 3) + pub_r001364_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_416_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_416_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_416_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_416_2 * 2)) & 255;
  int stage_v_417_1 = (((stage_v_235_1 * 3) + pub_r001364_15_1) + 4) & 127;
  int stage_v_417_2 = (((stage_v_235_2 * 3) + pub_r001364_15_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = ((pub_r001364_6_1 * 2) + 39) & 63;
  int stage_v_418_2 = ((pub_r001364_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = (((stage_v_340_1 * 3) + pub_r001364_6_1) + 43) & 127;
  int stage_v_419_2 = (((stage_v_340_2 * 3) + pub_r001364_6_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_419_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_419_2 * 2)) & 255;
  int stage_v_420_1 = (((stage_v_354_1 * 3) + pub_r001364_5_1) + 23) & 127;
  int stage_v_420_2 = (((stage_v_354_2 * 3) + pub_r001364_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_420_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_420_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_420_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_420_2 * 2)) & 255;
  int stage_v_421_1 = (((stage_v_185_1 * 3) + pub_r001364_9_1) + 45) & 127;
  int stage_v_421_2 = (((stage_v_185_2 * 3) + pub_r001364_9_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_421_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_421_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_421_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_421_2 * 2)) & 255;
  int stage_v_422_1 = (((stage_v_265_1 * 3) + pub_r001364_11_1) + 9) & 127;
  int stage_v_422_2 = (((stage_v_265_2 * 3) + pub_r001364_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_422_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_422_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_422_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_422_2 * 2)) & 255;
  int stage_v_423_1 = ((pub_r001364_0_1 * 2) + 47) & 63;
  int stage_v_423_2 = ((pub_r001364_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = (((stage_v_139_1 * 3) + pub_r001364_12_1) + 40) & 127;
  int stage_v_424_2 = (((stage_v_139_2 * 3) + pub_r001364_12_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_424_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_424_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_424_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_424_2 * 2)) & 255;
  int stage_v_425_1 = ((pub_r001364_11_1 * 2) + 42) & 63;
  int stage_v_425_2 = ((pub_r001364_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = (((stage_v_300_1 * 3) + pub_r001364_17_1) + 33) & 127;
  int stage_v_426_2 = (((stage_v_300_2 * 3) + pub_r001364_17_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_426_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_426_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_426_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_426_2 * 2)) & 255;
  int stage_v_427_1 = (((stage_v_344_1 * 3) + pub_r001364_15_1) + 19) & 127;
  int stage_v_427_2 = (((stage_v_344_2 * 3) + pub_r001364_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_427_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_427_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_427_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_427_2 * 2)) & 255;
  int stage_v_428_1 = (((stage_v_420_1 * 3) + pub_r001364_16_1) + 22) & 127;
  int stage_v_428_2 = (((stage_v_420_2 * 3) + pub_r001364_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_428_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_428_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_428_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_428_2 * 2)) & 255;
  int stage_v_429_1 = (((stage_v_123_1 * 3) + pub_r001364_4_1) + 13) & 127;
  int stage_v_429_2 = (((stage_v_123_2 * 3) + pub_r001364_4_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_429_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_429_2 * 2)) & 255;
  int stage_v_430_1 = (((stage_v_4_1 * 3) + pub_r001364_3_1) + 36) & 127;
  int stage_v_430_2 = (((stage_v_4_2 * 3) + pub_r001364_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_430_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_430_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_430_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_430_2 * 2)) & 255;
  int stage_v_431_1 = ((pub_r001364_13_1 * 2) + 22) & 63;
  int stage_v_431_2 = ((pub_r001364_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = (((sec_r001364_14_1 * 3) + pub_r001364_8_1) + 37) & 127;
  int stage_v_432_2 = (((sec_r001364_14_2 * 3) + pub_r001364_8_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_432_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_432_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_432_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_432_2 * 2)) & 255;
  int stage_v_433_1 = (((stage_v_268_1 * 3) + pub_r001364_11_1) + 10) & 127;
  int stage_v_433_2 = (((stage_v_268_2 * 3) + pub_r001364_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_433_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_433_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_433_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_433_2 * 2)) & 255;
  int stage_v_434_1 = (((stage_v_157_1 * 3) + pub_r001364_7_1) + 39) & 127;
  int stage_v_434_2 = (((stage_v_157_2 * 3) + pub_r001364_7_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_434_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_434_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_434_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_434_2 * 2)) & 255;
  int stage_v_435_1 = ((pub_r001364_1_1 * 2) + 12) & 63;
  int stage_v_435_2 = ((pub_r001364_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = ((pub_r001364_17_1 * 2) + 13) & 63;
  int stage_v_436_2 = ((pub_r001364_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = (((stage_v_289_1 * 3) + pub_r001364_12_1) + 40) & 127;
  int stage_v_437_2 = (((stage_v_289_2 * 3) + pub_r001364_12_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_437_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_437_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_437_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_437_2 * 2)) & 255;
  int stage_v_438_1 = ((pub_r001364_17_1 * 2) + 21) & 63;
  int stage_v_438_2 = ((pub_r001364_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = ((pub_r001364_14_1 * 2) + 13) & 63;
  int stage_v_439_2 = ((pub_r001364_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = ((pub_r001364_14_1 * 2) + 19) & 63;
  int stage_v_440_2 = ((pub_r001364_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((pub_r001364_13_1 * 2) + 49) & 63;
  int stage_v_441_2 = ((pub_r001364_13_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = ((pub_r001364_5_1 * 2) + 39) & 63;
  int stage_v_442_2 = ((pub_r001364_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = (((sec_r001364_10_1 * 3) + pub_r001364_16_1) + 6) & 127;
  int stage_v_443_2 = (((sec_r001364_10_2 * 3) + pub_r001364_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_443_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_443_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_443_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_443_2 * 2)) & 255;
  int stage_v_444_1 = (((stage_v_278_1 * 3) + pub_r001364_17_1) + 16) & 127;
  int stage_v_444_2 = (((stage_v_278_2 * 3) + pub_r001364_17_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_444_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_444_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_444_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_444_2 * 2)) & 255;
  int stage_v_445_1 = (((stage_v_443_1 * 3) + pub_r001364_4_1) + 8) & 127;
  int stage_v_445_2 = (((stage_v_443_2 * 3) + pub_r001364_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_445_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_445_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_445_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_445_2 * 2)) & 255;
  int stage_v_446_1 = (((sec_r001364_11_1 * 3) + pub_r001364_7_1) + 3) & 127;
  int stage_v_446_2 = (((sec_r001364_11_2 * 3) + pub_r001364_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_446_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_446_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_446_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_446_2 * 2)) & 255;
  int stage_v_447_1 = ((pub_r001364_2_1 * 2) + 6) & 63;
  int stage_v_447_2 = ((pub_r001364_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_447_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_447_2) & 127;
  int stage_v_448_1 = ((pub_r001364_2_1 * 2) + 28) & 63;
  int stage_v_448_2 = ((pub_r001364_2_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = ((pub_r001364_14_1 * 2) + 38) & 63;
  int stage_v_449_2 = ((pub_r001364_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_449_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_449_2) & 127;
  int stage_v_450_1 = ((pub_r001364_1_1 * 2) + 10) & 63;
  int stage_v_450_2 = ((pub_r001364_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_450_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_450_2) & 127;
  int stage_v_451_1 = ((pub_r001364_12_1 * 2) + 6) & 63;
  int stage_v_451_2 = ((pub_r001364_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_451_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_451_2) & 127;
  int stage_v_452_1 = (((stage_v_318_1 * 3) + pub_r001364_15_1) + 28) & 127;
  int stage_v_452_2 = (((stage_v_318_2 * 3) + pub_r001364_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_452_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_452_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_452_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_452_2 * 2)) & 255;
  int stage_v_453_1 = ((pub_r001364_13_1 * 2) + 40) & 63;
  int stage_v_453_2 = ((pub_r001364_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = (((stage_v_221_1 * 3) + pub_r001364_3_1) + 30) & 127;
  int stage_v_454_2 = (((stage_v_221_2 * 3) + pub_r001364_3_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_454_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_454_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_454_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_454_2 * 2)) & 255;
  int stage_v_455_1 = (((stage_v_235_1 * 3) + pub_r001364_4_1) + 28) & 127;
  int stage_v_455_2 = (((stage_v_235_2 * 3) + pub_r001364_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_455_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_455_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_455_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_455_2 * 2)) & 255;
  int stage_v_456_1 = ((pub_r001364_8_1 * 2) + 48) & 63;
  int stage_v_456_2 = ((pub_r001364_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_456_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_456_2) & 127;
  int stage_v_457_1 = (((stage_v_210_1 * 3) + pub_r001364_8_1) + 25) & 127;
  int stage_v_457_2 = (((stage_v_210_2 * 3) + pub_r001364_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_457_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_457_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_457_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_457_2 * 2)) & 255;
  int stage_v_458_1 = (((stage_v_328_1 * 3) + pub_r001364_9_1) + 13) & 127;
  int stage_v_458_2 = (((stage_v_328_2 * 3) + pub_r001364_9_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_458_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_458_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_458_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_458_2 * 2)) & 255;
  int stage_v_459_1 = (((stage_v_430_1 * 3) + pub_r001364_11_1) + 36) & 127;
  int stage_v_459_2 = (((stage_v_430_2 * 3) + pub_r001364_11_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_459_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_459_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_459_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_459_2 * 2)) & 255;
  int stage_v_460_1 = (((stage_v_234_1 * 3) + pub_r001364_9_1) + 30) & 127;
  int stage_v_460_2 = (((stage_v_234_2 * 3) + pub_r001364_9_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_460_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_460_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_460_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_460_2 * 2)) & 255;
  int stage_v_461_1 = ((pub_r001364_1_1 * 2) + 34) & 63;
  int stage_v_461_2 = ((pub_r001364_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = (((stage_v_136_1 * 3) + pub_r001364_4_1) + 40) & 127;
  int stage_v_462_2 = (((stage_v_136_2 * 3) + pub_r001364_4_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_462_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_462_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_462_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_462_2 * 2)) & 255;
  int stage_v_463_1 = ((pub_r001364_9_1 * 2) + 15) & 63;
  int stage_v_463_2 = ((pub_r001364_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_463_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_463_2) & 127;
  int stage_v_464_1 = ((pub_r001364_13_1 * 2) + 33) & 63;
  int stage_v_464_2 = ((pub_r001364_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_464_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_464_2) & 127;
  int stage_v_465_1 = ((pub_r001364_17_1 * 2) + 27) & 63;
  int stage_v_465_2 = ((pub_r001364_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_465_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_465_2) & 127;
  int stage_v_466_1 = (((stage_v_318_1 * 3) + pub_r001364_1_1) + 5) & 127;
  int stage_v_466_2 = (((stage_v_318_2 * 3) + pub_r001364_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_466_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_466_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_466_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_466_2 * 2)) & 255;
  int stage_v_467_1 = ((pub_r001364_11_1 * 2) + 43) & 63;
  int stage_v_467_2 = ((pub_r001364_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_467_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_467_2) & 127;
  int stage_v_468_1 = (((stage_v_279_1 * 3) + pub_r001364_15_1) + 37) & 127;
  int stage_v_468_2 = (((stage_v_279_2 * 3) + pub_r001364_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_468_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_468_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_468_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_468_2 * 2)) & 255;
  int stage_v_469_1 = (((stage_v_25_1 * 3) + pub_r001364_4_1) + 33) & 127;
  int stage_v_469_2 = (((stage_v_25_2 * 3) + pub_r001364_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_469_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_469_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_469_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_469_2 * 2)) & 255;
  int stage_v_470_1 = (((stage_v_422_1 * 3) + pub_r001364_11_1) + 25) & 127;
  int stage_v_470_2 = (((stage_v_422_2 * 3) + pub_r001364_11_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_470_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_470_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_470_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_470_2 * 2)) & 255;
  int stage_v_471_1 = (((sec_r001364_13_1 * 3) + pub_r001364_2_1) + 21) & 127;
  int stage_v_471_2 = (((sec_r001364_13_2 * 3) + pub_r001364_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_471_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_471_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_471_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_471_2 * 2)) & 255;
  int stage_v_472_1 = (((stage_v_375_1 * 3) + pub_r001364_3_1) + 45) & 127;
  int stage_v_472_2 = (((stage_v_375_2 * 3) + pub_r001364_3_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_472_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_472_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_472_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_472_2 * 2)) & 255;
  int stage_v_473_1 = ((pub_r001364_15_1 * 2) + 41) & 63;
  int stage_v_473_2 = ((pub_r001364_15_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_473_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_473_2) & 127;
  int stage_v_474_1 = (((stage_v_457_1 * 3) + pub_r001364_3_1) + 35) & 127;
  int stage_v_474_2 = (((stage_v_457_2 * 3) + pub_r001364_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_474_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_474_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_474_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_474_2 * 2)) & 255;
  int stage_v_475_1 = (((helper_flow_2_1 * 3) + pub_r001364_14_1) + 16) & 127;
  int stage_v_475_2 = (((helper_flow_2_2 * 3) + pub_r001364_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_475_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_475_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_475_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_475_2 * 2)) & 255;
  int stage_v_476_1 = (((stage_v_347_1 * 3) + pub_r001364_17_1) + 31) & 127;
  int stage_v_476_2 = (((stage_v_347_2 * 3) + pub_r001364_17_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_476_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_476_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_476_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_476_2 * 2)) & 255;
  int stage_v_477_1 = (((stage_v_193_1 * 3) + pub_r001364_6_1) + 3) & 127;
  int stage_v_477_2 = (((stage_v_193_2 * 3) + pub_r001364_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_477_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_477_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_477_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_477_2 * 2)) & 255;
  int stage_v_478_1 = ((pub_r001364_13_1 * 2) + 8) & 63;
  int stage_v_478_2 = ((pub_r001364_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_478_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_478_2) & 127;
  int stage_v_479_1 = ((pub_r001364_15_1 * 2) + 23) & 63;
  int stage_v_479_2 = ((pub_r001364_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_479_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_479_2) & 127;
  int stage_v_480_1 = ((pub_r001364_16_1 * 2) + 6) & 63;
  int stage_v_480_2 = ((pub_r001364_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_480_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_480_2) & 127;
  int stage_v_481_1 = ((pub_r001364_17_1 * 2) + 8) & 63;
  int stage_v_481_2 = ((pub_r001364_17_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_481_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_481_2) & 127;
  int stage_v_482_1 = ((pub_r001364_14_1 * 2) + 26) & 63;
  int stage_v_482_2 = ((pub_r001364_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_482_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_482_2) & 127;
  int stage_v_483_1 = ((pub_r001364_18_1 * 2) + 24) & 63;
  int stage_v_483_2 = ((pub_r001364_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_483_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_483_2) & 127;
  int stage_v_484_1 = ((pub_r001364_17_1 * 2) + 11) & 63;
  int stage_v_484_2 = ((pub_r001364_17_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_484_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_484_2) & 127;
  int stage_v_485_1 = (((stage_v_87_1 * 3) + pub_r001364_5_1) + 19) & 127;
  int stage_v_485_2 = (((stage_v_87_2 * 3) + pub_r001364_5_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_485_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_485_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_485_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_485_2 * 2)) & 255;
  int stage_v_486_1 = (((stage_v_298_1 * 3) + pub_r001364_1_1) + 33) & 127;
  int stage_v_486_2 = (((stage_v_298_2 * 3) + pub_r001364_1_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_486_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_486_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_486_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_486_2 * 2)) & 255;
  int stage_v_487_1 = (((stage_v_323_1 * 3) + pub_r001364_6_1) + 11) & 127;
  int stage_v_487_2 = (((stage_v_323_2 * 3) + pub_r001364_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_487_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_487_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_487_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_487_2 * 2)) & 255;
  int stage_v_488_1 = (((stage_v_61_1 * 3) + pub_r001364_2_1) + 37) & 127;
  int stage_v_488_2 = (((stage_v_61_2 * 3) + pub_r001364_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_488_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_488_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_488_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_488_2 * 2)) & 255;
  int stage_v_489_1 = (((stage_v_182_1 * 3) + pub_r001364_4_1) + 43) & 127;
  int stage_v_489_2 = (((stage_v_182_2 * 3) + pub_r001364_4_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_489_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_489_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_489_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_489_2 * 2)) & 255;
  int stage_v_490_1 = ((pub_r001364_16_1 * 2) + 16) & 63;
  int stage_v_490_2 = ((pub_r001364_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_490_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_490_2) & 127;
  int stage_v_491_1 = ((pub_r001364_1_1 * 2) + 37) & 63;
  int stage_v_491_2 = ((pub_r001364_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_491_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_491_2) & 127;
  int stage_v_492_1 = (((stage_v_274_1 * 3) + pub_r001364_2_1) + 12) & 127;
  int stage_v_492_2 = (((stage_v_274_2 * 3) + pub_r001364_2_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_492_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_492_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_492_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_492_2 * 2)) & 255;
  int stage_v_493_1 = ((pub_r001364_12_1 * 2) + 7) & 63;
  int stage_v_493_2 = ((pub_r001364_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_493_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_493_2) & 127;
  int stage_v_494_1 = (((stage_v_400_1 * 3) + pub_r001364_5_1) + 24) & 127;
  int stage_v_494_2 = (((stage_v_400_2 * 3) + pub_r001364_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_494_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_494_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_494_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_494_2 * 2)) & 255;
  int stage_v_495_1 = (((stage_v_419_1 * 3) + pub_r001364_11_1) + 30) & 127;
  int stage_v_495_2 = (((stage_v_419_2 * 3) + pub_r001364_11_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_495_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_495_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_495_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_495_2 * 2)) & 255;
  int stage_v_496_1 = (((stage_v_53_1 * 3) + pub_r001364_4_1) + 29) & 127;
  int stage_v_496_2 = (((stage_v_53_2 * 3) + pub_r001364_4_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_496_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_496_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_496_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_496_2 * 2)) & 255;
  int stage_v_497_1 = ((pub_r001364_1_1 * 2) + 32) & 63;
  int stage_v_497_2 = ((pub_r001364_1_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_497_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_497_2) & 127;
  int stage_v_498_1 = (((sec_r001364_0_1 * 3) + pub_r001364_4_1) + 22) & 127;
  int stage_v_498_2 = (((sec_r001364_0_2 * 3) + pub_r001364_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_498_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_498_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_498_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_498_2 * 2)) & 255;
  int stage_v_499_1 = (((stage_v_230_1 * 3) + pub_r001364_12_1) + 26) & 127;
  int stage_v_499_2 = (((stage_v_230_2 * 3) + pub_r001364_12_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_499_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_499_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_499_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_499_2 * 2)) & 255;
  int stage_v_500_1 = (((stage_v_171_1 * 3) + pub_r001364_2_1) + 21) & 127;
  int stage_v_500_2 = (((stage_v_171_2 * 3) + pub_r001364_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_500_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_500_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_500_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_500_2 * 2)) & 255;
  int stage_v_501_1 = (((stage_v_424_1 * 3) + pub_r001364_14_1) + 44) & 127;
  int stage_v_501_2 = (((stage_v_424_2 * 3) + pub_r001364_14_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_501_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_501_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_501_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_501_2 * 2)) & 255;
  int stage_v_502_1 = (((stage_v_452_1 * 3) + pub_r001364_6_1) + 11) & 127;
  int stage_v_502_2 = (((stage_v_452_2 * 3) + pub_r001364_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_502_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_502_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_502_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_502_2 * 2)) & 255;
  int stage_v_503_1 = (((stage_v_351_1 * 3) + pub_r001364_2_1) + 34) & 127;
  int stage_v_503_2 = (((stage_v_351_2 * 3) + pub_r001364_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_503_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_503_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_503_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_503_2 * 2)) & 255;
  int stage_v_504_1 = ((pub_r001364_7_1 * 2) + 19) & 63;
  int stage_v_504_2 = ((pub_r001364_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_504_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_504_2) & 127;
  int stage_v_505_1 = (((stage_v_174_1 * 3) + pub_r001364_2_1) + 7) & 127;
  int stage_v_505_2 = (((stage_v_174_2 * 3) + pub_r001364_2_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_505_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_505_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_505_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_505_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001364_15_1 == pub_r001364_15_2);
  __CPROVER_assume(sec_r001364_11_1 != sec_r001364_11_2);
  __CPROVER_assume(sec_r001364_3_1 != sec_r001364_3_2);
  __CPROVER_assume(pub_r001364_7_1 == pub_r001364_7_2);
  __CPROVER_assume(pub_r001364_11_1 == pub_r001364_11_2);
  __CPROVER_assume(sec_r001364_10_1 != sec_r001364_10_2);
  __CPROVER_assume(pub_r001364_12_1 == pub_r001364_12_2);
  __CPROVER_assume(sec_r001364_8_1 != sec_r001364_8_2);
  __CPROVER_assume(sec_r001364_18_1 != sec_r001364_18_2);
  __CPROVER_assume(pub_r001364_0_1 == pub_r001364_0_2);
  __CPROVER_assume(pub_r001364_5_1 == pub_r001364_5_2);
  __CPROVER_assume(sec_r001364_17_1 != sec_r001364_17_2);
  __CPROVER_assume(sec_r001364_14_1 != sec_r001364_14_2);
  __CPROVER_assume(pub_r001364_6_1 == pub_r001364_6_2);
  __CPROVER_assume(sec_r001364_9_1 != sec_r001364_9_2);
  __CPROVER_assume(sec_r001364_15_1 != sec_r001364_15_2);
  __CPROVER_assume(pub_r001364_8_1 == pub_r001364_8_2);
  __CPROVER_assume(sec_r001364_5_1 != sec_r001364_5_2);
  __CPROVER_assume(sec_r001364_6_1 != sec_r001364_6_2);
  __CPROVER_assume(sec_r001364_20_1 != sec_r001364_20_2);
  __CPROVER_assume(pub_r001364_4_1 == pub_r001364_4_2);
  __CPROVER_assume(pub_r001364_10_1 == pub_r001364_10_2);
  __CPROVER_assume(pub_r001364_3_1 == pub_r001364_3_2);
  __CPROVER_assume(pub_r001364_9_1 == pub_r001364_9_2);
  __CPROVER_assume(pub_r001364_13_1 == pub_r001364_13_2);
  __CPROVER_assume(sec_r001364_19_1 != sec_r001364_19_2);
  __CPROVER_assume(sec_r001364_0_1 != sec_r001364_0_2);
  __CPROVER_assume(pub_r001364_14_1 == pub_r001364_14_2);
  __CPROVER_assume(pub_r001364_18_1 == pub_r001364_18_2);
  __CPROVER_assume(sec_r001364_13_1 != sec_r001364_13_2);
  __CPROVER_assume(sec_r001364_4_1 != sec_r001364_4_2);
  __CPROVER_assume(pub_r001364_16_1 == pub_r001364_16_2);
  __CPROVER_assume(sec_r001364_7_1 != sec_r001364_7_2);
  __CPROVER_assume(sec_r001364_16_1 != sec_r001364_16_2);
  __CPROVER_assume(pub_r001364_2_1 == pub_r001364_2_2);
  __CPROVER_assume(pub_r001364_17_1 == pub_r001364_17_2);
  __CPROVER_assume(sec_r001364_2_1 != sec_r001364_2_2);
  __CPROVER_assume(sec_r001364_1_1 != sec_r001364_1_2);
  __CPROVER_assume(pub_r001364_1_1 == pub_r001364_1_2);
  __CPROVER_assume(sec_r001364_12_1 != sec_r001364_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.port == st_var_0_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.counter == st_var_2_2.counter);
  assert(st_var_2_1.iv == st_var_2_2.iv);
  assert(st_var_2_1.nonce == st_var_2_2.nonce);
  assert(st_var_2_1.round_key == st_var_2_2.round_key);
  assert(st_var_2_1.flags == st_var_2_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.scale == st_var_3_2.scale);
  assert(st_var_3_1.determinant == st_var_3_2.determinant);
  assert(st_var_3_1.dim == st_var_3_2.dim);
  assert(st_var_3_1.stride == st_var_3_2.stride);
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
  assert(stage_v_418_1 == stage_v_418_2);
  assert(stage_v_419_1 == stage_v_419_2);
  assert(stage_v_420_1 == stage_v_420_2);
  assert(stage_v_421_1 == stage_v_421_2);
  assert(stage_v_422_1 == stage_v_422_2);
  assert(stage_v_423_1 == stage_v_423_2);
  assert(stage_v_424_1 == stage_v_424_2);
  assert(stage_v_425_1 == stage_v_425_2);
  assert(stage_v_426_1 == stage_v_426_2);
  assert(stage_v_427_1 == stage_v_427_2);
  assert(stage_v_428_1 == stage_v_428_2);
  assert(stage_v_429_1 == stage_v_429_2);
  assert(stage_v_430_1 == stage_v_430_2);
  assert(stage_v_431_1 == stage_v_431_2);
  assert(stage_v_432_1 == stage_v_432_2);
  assert(stage_v_433_1 == stage_v_433_2);
  assert(stage_v_434_1 == stage_v_434_2);
  assert(stage_v_435_1 == stage_v_435_2);
  assert(stage_v_436_1 == stage_v_436_2);
  assert(stage_v_437_1 == stage_v_437_2);
  assert(stage_v_438_1 == stage_v_438_2);
  assert(stage_v_439_1 == stage_v_439_2);
  assert(stage_v_440_1 == stage_v_440_2);
  assert(stage_v_441_1 == stage_v_441_2);
  assert(stage_v_442_1 == stage_v_442_2);
  assert(stage_v_443_1 == stage_v_443_2);
  assert(stage_v_444_1 == stage_v_444_2);
  assert(stage_v_445_1 == stage_v_445_2);
  assert(stage_v_446_1 == stage_v_446_2);
  assert(stage_v_447_1 == stage_v_447_2);
  assert(stage_v_448_1 == stage_v_448_2);
  assert(stage_v_449_1 == stage_v_449_2);
  assert(stage_v_450_1 == stage_v_450_2);
  assert(stage_v_451_1 == stage_v_451_2);
  assert(stage_v_452_1 == stage_v_452_2);
  assert(stage_v_453_1 == stage_v_453_2);
  assert(stage_v_454_1 == stage_v_454_2);
  assert(stage_v_455_1 == stage_v_455_2);
  assert(stage_v_456_1 == stage_v_456_2);
  assert(stage_v_457_1 == stage_v_457_2);
  assert(stage_v_458_1 == stage_v_458_2);
  assert(stage_v_459_1 == stage_v_459_2);
  assert(stage_v_460_1 == stage_v_460_2);
  assert(stage_v_461_1 == stage_v_461_2);
  assert(stage_v_462_1 == stage_v_462_2);
  assert(stage_v_463_1 == stage_v_463_2);
  assert(stage_v_464_1 == stage_v_464_2);
  assert(stage_v_465_1 == stage_v_465_2);
  assert(stage_v_466_1 == stage_v_466_2);
  assert(stage_v_467_1 == stage_v_467_2);
  assert(stage_v_468_1 == stage_v_468_2);
  assert(stage_v_469_1 == stage_v_469_2);
  assert(stage_v_470_1 == stage_v_470_2);
  assert(stage_v_471_1 == stage_v_471_2);
  assert(stage_v_472_1 == stage_v_472_2);
  assert(stage_v_473_1 == stage_v_473_2);
  assert(stage_v_474_1 == stage_v_474_2);
  assert(stage_v_475_1 == stage_v_475_2);
  assert(stage_v_476_1 == stage_v_476_2);
  assert(stage_v_477_1 == stage_v_477_2);
  assert(stage_v_478_1 == stage_v_478_2);
  assert(stage_v_479_1 == stage_v_479_2);
  assert(stage_v_480_1 == stage_v_480_2);
  assert(stage_v_481_1 == stage_v_481_2);
  assert(stage_v_482_1 == stage_v_482_2);
  assert(stage_v_483_1 == stage_v_483_2);
  assert(stage_v_484_1 == stage_v_484_2);
  assert(stage_v_485_1 == stage_v_485_2);
  assert(stage_v_486_1 == stage_v_486_2);
  assert(stage_v_487_1 == stage_v_487_2);
  assert(stage_v_488_1 == stage_v_488_2);
  assert(stage_v_489_1 == stage_v_489_2);
  assert(stage_v_490_1 == stage_v_490_2);
  assert(stage_v_491_1 == stage_v_491_2);
  assert(stage_v_492_1 == stage_v_492_2);
  assert(stage_v_493_1 == stage_v_493_2);
  assert(stage_v_494_1 == stage_v_494_2);
  assert(stage_v_495_1 == stage_v_495_2);
  assert(stage_v_496_1 == stage_v_496_2);
  assert(stage_v_497_1 == stage_v_497_2);
  assert(stage_v_498_1 == stage_v_498_2);
  assert(stage_v_499_1 == stage_v_499_2);
  assert(stage_v_500_1 == stage_v_500_2);
  assert(stage_v_501_1 == stage_v_501_2);
  assert(stage_v_502_1 == stage_v_502_2);
  assert(stage_v_503_1 == stage_v_503_2);
  assert(stage_v_504_1 == stage_v_504_2);
  assert(stage_v_505_1 == stage_v_505_2);
}


