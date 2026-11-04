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
struct AudioFrame_R000354_5413_0
{
  int peak;
  int channels;
  unsigned char gain;
  int sample_rate;
  short envelope;
  int buffer[3];
};
struct CipherContext_R000354_5413_1
{
  int tag;
  short counter;
  int flags;
  int nonce;
  int iv;
  unsigned char round_key;
  int buffer[3];
};
struct MatrixBlock_R000354_5413_2
{
  int dim;
  short density;
  int stride;
  short determinant;
  int buffer[3];
};
struct FilterState_R000354_5413_3
{
  int damping;
  unsigned char prev_in;
  int gain_db;
  int cutoff;
  unsigned char mode;
  unsigned char prev_out;
  int buffer[3];
};
union ColorPixel_R000354_5413_0
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
void fn_R000354_5413_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000354_5413_0 st_1 = {0};
  struct AudioFrame_R000354_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_71_1 = local_arr_1[aux_1 % 3];
  int index_reg_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_71_2 * 2)) & 127;
  int phase_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_18_1)
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

  switch (phase_18_2)
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

  int sample_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_36_1) & 63;
  aux_2 = (aux_2 + sample_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_69_1 = 0;
  int quantum_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_69_1 = ((quantum_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_69_2 = ((quantum_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_69_1) & 127;
    acc_2 = (acc_2 + quantum_69_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_71_1 == index_reg_71_2);
  assert(phase_18_1 == phase_18_2);
  assert(sample_36_1 == sample_36_2);
  assert(quantum_69_1 == quantum_69_2);
}

int fn_R000354_5413_0(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000354_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int index_reg_71 = local_arr[aux % 3];
  acc = (acc + (index_reg_71 * 2)) & 127;
  int phase_18 = (aux + st.buffer[1]) & 3;
  switch (phase_18)
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

  int sample_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_36) & 63;
  acc ^= aux;
  int quantum_69 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_69 = ((quantum_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_69) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000354_5413_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000354_5413_2 st_1 = {0};
  struct MatrixBlock_R000354_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_32_1)
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

  switch (bound_32_2)
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

  int quotient_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_95_1 > 31)
  {
    acc_1 = ((acc_1 + (quotient_95_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_95_2 > 31)
  {
    acc_2 = ((acc_2 + (quotient_95_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_54_1) & 63;
  aux_2 = (aux_2 + coefficient_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_32_1 == bound_32_2);
  assert(quotient_95_1 == quotient_95_2);
  assert(coefficient_54_1 == coefficient_54_2);
}

int fn_R000354_5413_1(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000354_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_32 = (aux + st.buffer[1]) & 3;
  switch (bound_32)
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

  int quotient_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_95 > 31)
  {
    acc = ((acc + (quotient_95 * 2)) + 5) & 127;
    aux ^= quotient_95 & 15;
  }
  else
  {
    acc = ((acc - quotient_95) + 11) & 127;
    aux += 3;
  }
  int coefficient_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_54) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000354_5413_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000354_5413_2 st_1 = {0};
  struct MatrixBlock_R000354_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int mask_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_21_1)
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

  switch (mask_21_2)
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
  int segment_88_1 = local_arr_1[aux_1 % 3];
  int segment_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_88_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_21_1 == mask_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_88_1 == segment_88_2);
}

int fn_R000354_5413_2(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000354_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int mask_21 = (aux + st.buffer[1]) & 3;
  switch (mask_21)
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
  int segment_88 = local_arr[aux % 3];
  acc = (acc + (segment_88 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000354_5413_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000354_5413_3 st_1 = {0};
  struct FilterState_R000354_5413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_32_1) & 63;
  aux_2 = (aux_2 + quotient_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_32_1 == quotient_32_2);
}

int fn_R000354_5413_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000354_5413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_32) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000354_5413_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000354_5413_1 st_1 = {0};
  struct CipherContext_R000354_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int parity_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_16_1 > 45)
  {
    acc_1 = ((acc_1 + (parity_16_1 * 2)) + 5) & 127;
    aux_1 ^= parity_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_16_2 > 45)
  {
    acc_2 = ((acc_2 + (parity_16_2 * 2)) + 5) & 127;
    aux_2 ^= parity_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_16_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_97_1 = local_arr_1[aux_1 % 3];
  int quantum_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_97_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_16_1 == parity_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_97_1 == quantum_97_2);
}

int fn_R000354_5413_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000354_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int parity_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_16 > 45)
  {
    acc = ((acc + (parity_16 * 2)) + 5) & 127;
    aux ^= parity_16 & 15;
  }
  else
  {
    acc = ((acc - parity_16) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_97 = local_arr[aux % 3];
  acc = (acc + (quantum_97 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000354_5413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000354_5413_3 st_1 = {0};
  struct FilterState_R000354_5413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int bound_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_16_1)
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

  switch (bound_16_2)
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

  int quotient_48_1 = 0;
  int quotient_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_48_1 = ((quotient_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_48_2 = ((quotient_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_48_1) & 127;
    acc_2 = (acc_2 + quotient_48_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_16_1 == bound_16_2);
  assert(quotient_48_1 == quotient_48_2);
}

int fn_R000354_5413_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000354_5413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int bound_16 = (aux + st.buffer[1]) & 3;
  switch (bound_16)
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

  int quotient_48 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_48 = ((quotient_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_48) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000354_5413_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000354_5413_1 st_1 = {0};
  struct CipherContext_R000354_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int damping_21_1 = 0;
  int damping_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_21_1 = ((damping_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_21_2 = ((damping_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_21_1) & 127;
    acc_2 = (acc_2 + damping_21_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_10_1 = local_arr_1[aux_1 % 3];
  int scale_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_10_2 * 2)) & 127;
  int damping_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_85_1 > 18)
  {
    acc_1 = ((acc_1 + (damping_85_1 * 2)) + 5) & 127;
    aux_1 ^= damping_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_85_2 > 18)
  {
    acc_2 = ((acc_2 + (damping_85_2 * 2)) + 5) & 127;
    aux_2 ^= damping_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_73_1)
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

  switch (metric_73_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_21_1 == damping_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_10_1 == scale_10_2);
  assert(damping_85_1 == damping_85_2);
  assert(metric_73_1 == metric_73_2);
}

int fn_R000354_5413_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000354_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int damping_21 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_21 = ((damping_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_21) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int scale_10 = local_arr[aux % 3];
  acc = (acc + (scale_10 * 2)) & 127;
  int damping_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_85 > 18)
  {
    acc = ((acc + (damping_85 * 2)) + 5) & 127;
    aux ^= damping_85 & 15;
  }
  else
  {
    acc = ((acc - damping_85) + 11) & 127;
    aux += 3;
  }
  int metric_73 = (aux + st.buffer[1]) & 3;
  switch (metric_73)
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

void fn_R000354_5413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000354_5413_1 st_1 = {0};
  struct CipherContext_R000354_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int metric_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_20_1) & 63;
  aux_2 = (aux_2 + metric_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_86_1 = 0;
  int checksum_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_86_1 = ((checksum_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_86_2 = ((checksum_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_86_1) & 127;
    acc_2 = (acc_2 + checksum_86_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_20_1 == metric_20_2);
  assert(checksum_86_1 == checksum_86_2);
}

int fn_R000354_5413_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000354_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int metric_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_20) & 63;
  acc ^= aux;
  int checksum_86 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_86 = ((checksum_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_86) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000354_5413_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000354_5413_2 st_1 = {0};
  struct MatrixBlock_R000354_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int offset_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_43_1 > 39)
  {
    acc_1 = ((acc_1 + (offset_43_1 * 2)) + 5) & 127;
    aux_1 ^= offset_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_43_2 > 39)
  {
    acc_2 = ((acc_2 + (offset_43_2 * 2)) + 5) & 127;
    aux_2 ^= offset_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_50_1)
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

  switch (window_50_2)
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

  int phase_97_1 = 0;
  int phase_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_97_1 = ((phase_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_97_2 = ((phase_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_97_1) & 127;
    acc_2 = (acc_2 + phase_97_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_43_1 == offset_43_2);
  assert(window_50_1 == window_50_2);
  assert(phase_97_1 == phase_97_2);
}

int fn_R000354_5413_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000354_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int offset_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_43 > 39)
  {
    acc = ((acc + (offset_43 * 2)) + 5) & 127;
    aux ^= offset_43 & 15;
  }
  else
  {
    acc = ((acc - offset_43) + 11) & 127;
    aux += 3;
  }
  int window_50 = (aux + st.buffer[1]) & 3;
  switch (window_50)
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

  int phase_97 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_97 = ((phase_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_97) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000354_5413_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000354_5413_2 st_1 = {0};
  struct MatrixBlock_R000354_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_97_1) & 63;
  aux_2 = (aux_2 + scale_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_97_1 = local_arr_1[aux_1 % 3];
  int mask_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_97_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_97_1 == scale_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_97_1 == mask_97_2);
}

int fn_R000354_5413_9(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000354_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_97) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int mask_97 = local_arr[aux % 3];
  acc = (acc + (mask_97 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000354_5413_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000354_5413_3 st_1 = {0};
  struct FilterState_R000354_5413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_46_1 = local_arr_1[aux_1 % 3];
  int coefficient_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_46_2 * 2)) & 127;
  int anchor_54_1 = 0;
  int anchor_54_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_54_1 = ((anchor_54_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_54_2 = ((anchor_54_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_54_1) & 127;
    acc_2 = (acc_2 + anchor_54_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_46_1 == coefficient_46_2);
  assert(anchor_54_1 == anchor_54_2);
}

int fn_R000354_5413_10(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000354_5413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int coefficient_46 = local_arr[aux % 3];
  acc = (acc + (coefficient_46 * 2)) & 127;
  int anchor_54 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_54 = ((anchor_54 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_54) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000354_5413_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000354_5413_1 st_1 = {0};
  struct CipherContext_R000354_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int bound_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_80_1) & 63;
  aux_2 = (aux_2 + bound_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_93_1)
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

  switch (residue_93_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_80_1 == bound_80_2);
  assert(residue_93_1 == residue_93_2);
}

int fn_R000354_5413_11(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000354_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int bound_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_80) & 63;
  acc ^= aux;
  int residue_93 = (aux + st.buffer[1]) & 3;
  switch (residue_93)
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

void fn_R000354_5413_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000354_5413_0 st_1 = {0};
  struct AudioFrame_R000354_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_54_1 = local_arr_1[aux_1 % 3];
  int checksum_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_54_2 * 2)) & 127;
  int window_61_1 = 0;
  int window_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_61_1 = ((window_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_61_2 = ((window_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_61_1) & 127;
    acc_2 = (acc_2 + window_61_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_54_1 == checksum_54_2);
  assert(window_61_1 == window_61_2);
}

int fn_R000354_5413_12(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000354_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_54 = local_arr[aux % 3];
  acc = (acc + (checksum_54 * 2)) & 127;
  int window_61 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_61 = ((window_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_61) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000354_5413_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000354_5413_0 st_1 = {0};
  struct AudioFrame_R000354_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int offset_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_92_1 > 46)
  {
    acc_1 = ((acc_1 + (offset_92_1 * 2)) + 5) & 127;
    aux_1 ^= offset_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_92_2 > 46)
  {
    acc_2 = ((acc_2 + (offset_92_2 * 2)) + 5) & 127;
    aux_2 ^= offset_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_86_1) & 63;
  aux_2 = (aux_2 + segment_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_92_1 == offset_92_2);
  assert(segment_86_1 == segment_86_2);
}

int fn_R000354_5413_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000354_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int offset_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_92 > 46)
  {
    acc = ((acc + (offset_92 * 2)) + 5) & 127;
    aux ^= offset_92 & 15;
  }
  else
  {
    acc = ((acc - offset_92) + 11) & 127;
    aux += 3;
  }
  int segment_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_86) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000354_5413_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000354_5413_2 st_1 = {0};
  struct MatrixBlock_R000354_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_98_1 = local_arr_1[aux_1 % 3];
  int metric_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_98_2 * 2)) & 127;
  int factor_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_97_1 > 14)
  {
    acc_1 = ((acc_1 + (factor_97_1 * 2)) + 5) & 127;
    aux_1 ^= factor_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_97_2 > 14)
  {
    acc_2 = ((acc_2 + (factor_97_2 * 2)) + 5) & 127;
    aux_2 ^= factor_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_98_1 == metric_98_2);
  assert(factor_97_1 == factor_97_2);
}

int fn_R000354_5413_14(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000354_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int metric_98 = local_arr[aux % 3];
  acc = (acc + (metric_98 * 2)) & 127;
  int factor_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_97 > 14)
  {
    acc = ((acc + (factor_97 * 2)) + 5) & 127;
    aux ^= factor_97 & 15;
  }
  else
  {
    acc = ((acc - factor_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000354_5413_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000354_5413_0 st_1 = {0};
  struct AudioFrame_R000354_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_25_1 = local_arr_1[aux_1 % 3];
  int sample_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_25_2 * 2)) & 127;
  int phase_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_27_1)
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

  switch (phase_27_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_25_1 == sample_25_2);
  assert(phase_27_1 == phase_27_2);
}

int fn_R000354_5413_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000354_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int sample_25 = local_arr[aux % 3];
  acc = (acc + (sample_25 * 2)) & 127;
  int phase_27 = (aux + st.buffer[1]) & 3;
  switch (phase_27)
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

void fn_R000354_5413_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000354_5413_2 st_1 = {0};
  struct MatrixBlock_R000354_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_23_1 = local_arr_1[aux_1 % 3];
  int damping_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_23_2 * 2)) & 127;
  int segment_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_86_1 > 29)
  {
    acc_1 = ((acc_1 + (segment_86_1 * 2)) + 5) & 127;
    aux_1 ^= segment_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_86_2 > 29)
  {
    acc_2 = ((acc_2 + (segment_86_2 * 2)) + 5) & 127;
    aux_2 ^= segment_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_86_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_23_1 == damping_23_2);
  assert(segment_86_1 == segment_86_2);
}

int fn_R000354_5413_16(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000354_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int damping_23 = local_arr[aux % 3];
  acc = (acc + (damping_23 * 2)) & 127;
  int segment_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_86 > 29)
  {
    acc = ((acc + (segment_86 * 2)) + 5) & 127;
    aux ^= segment_86 & 15;
  }
  else
  {
    acc = ((acc - segment_86) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000354_5413_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000354_5413_2 st_1 = {0};
  struct MatrixBlock_R000354_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_98_1 = local_arr_1[aux_1 % 3];
  int scale_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_98_2 * 2)) & 127;
  int mask_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_78_1 > 14)
  {
    acc_1 = ((acc_1 + (mask_78_1 * 2)) + 5) & 127;
    aux_1 ^= mask_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_78_2 > 14)
  {
    acc_2 = ((acc_2 + (mask_78_2 * 2)) + 5) & 127;
    aux_2 ^= mask_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_78_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_98_1 == scale_98_2);
  assert(mask_78_1 == mask_78_2);
}

int fn_R000354_5413_17(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000354_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int scale_98 = local_arr[aux % 3];
  acc = (acc + (scale_98 * 2)) & 127;
  int mask_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_78 > 14)
  {
    acc = ((acc + (mask_78 * 2)) + 5) & 127;
    aux ^= mask_78 & 15;
  }
  else
  {
    acc = ((acc - mask_78) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000354_5413_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000354_5413_0 st_1 = {0};
  struct AudioFrame_R000354_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int margin_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_85_1) & 63;
  aux_2 = (aux_2 + margin_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_18_1 > 44)
  {
    acc_1 = ((acc_1 + (coefficient_18_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_18_2 > 44)
  {
    acc_2 = ((acc_2 + (coefficient_18_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_26_1)
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

  switch (segment_26_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_85_1 == margin_85_2);
  assert(coefficient_18_1 == coefficient_18_2);
  assert(segment_26_1 == segment_26_2);
}

int fn_R000354_5413_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000354_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int margin_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_85) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_18 > 44)
  {
    acc = ((acc + (coefficient_18 * 2)) + 5) & 127;
    aux ^= coefficient_18 & 15;
  }
  else
  {
    acc = ((acc - coefficient_18) + 11) & 127;
    aux += 3;
  }
  int segment_26 = (aux + st.buffer[1]) & 3;
  switch (segment_26)
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

void fn_R000354_5413_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000354_5413_1 st_1 = {0};
  struct CipherContext_R000354_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int threshold_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_25_1)
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

  switch (threshold_25_2)
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

  int metric_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_45_1 > 30)
  {
    acc_1 = ((acc_1 + (metric_45_1 * 2)) + 5) & 127;
    aux_1 ^= metric_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_45_2 > 30)
  {
    acc_2 = ((acc_2 + (metric_45_2 * 2)) + 5) & 127;
    aux_2 ^= metric_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_45_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_25_1 == threshold_25_2);
  assert(metric_45_1 == metric_45_2);
}

int fn_R000354_5413_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000354_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int threshold_25 = (aux + st.buffer[1]) & 3;
  switch (threshold_25)
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

  int metric_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_45 > 30)
  {
    acc = ((acc + (metric_45 * 2)) + 5) & 127;
    aux ^= metric_45 & 15;
  }
  else
  {
    acc = ((acc - metric_45) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000354_5413_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000354_5413_0 st_1 = {0};
  struct AudioFrame_R000354_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int cursor_40_1 = 0;
  int cursor_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_40_1 = ((cursor_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_40_2 = ((cursor_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_40_1) & 127;
    acc_2 = (acc_2 + cursor_40_2) & 127;
  }

  int quantum_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_63_1) & 63;
  aux_2 = (aux_2 + quantum_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_25_1 > 30)
  {
    acc_1 = ((acc_1 + (scale_25_1 * 2)) + 5) & 127;
    aux_1 ^= scale_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_25_2 > 30)
  {
    acc_2 = ((acc_2 + (scale_25_2 * 2)) + 5) & 127;
    aux_2 ^= scale_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_25_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_83_1)
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

  switch (residue_83_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_40_1 == cursor_40_2);
  assert(quantum_63_1 == quantum_63_2);
  assert(scale_25_1 == scale_25_2);
  assert(residue_83_1 == residue_83_2);
}

int fn_R000354_5413_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000354_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int cursor_40 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_40 = ((cursor_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_40) & 127;
  }

  int quantum_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_63) & 63;
  acc ^= aux;
  int scale_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_25 > 30)
  {
    acc = ((acc + (scale_25 * 2)) + 5) & 127;
    aux ^= scale_25 & 15;
  }
  else
  {
    acc = ((acc - scale_25) + 11) & 127;
    aux += 3;
  }
  int residue_83 = (aux + st.buffer[1]) & 3;
  switch (residue_83)
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

void fn_R000354_5413_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000354_5413_2 st_1 = {0};
  struct MatrixBlock_R000354_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int window_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_97_1 > 48)
  {
    acc_1 = ((acc_1 + (window_97_1 * 2)) + 5) & 127;
    aux_1 ^= window_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_97_2 > 48)
  {
    acc_2 = ((acc_2 + (window_97_2 * 2)) + 5) & 127;
    aux_2 ^= window_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_97_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_79_1 = 0;
  int window_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_79_1 = ((window_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_79_2 = ((window_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_79_1) & 127;
    acc_2 = (acc_2 + window_79_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_29_1 = local_arr_1[aux_1 % 3];
  int pivot_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_29_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_97_1 == window_97_2);
  assert(window_79_1 == window_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_29_1 == pivot_29_2);
}

int fn_R000354_5413_21(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000354_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int window_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_97 > 48)
  {
    acc = ((acc + (window_97 * 2)) + 5) & 127;
    aux ^= window_97 & 15;
  }
  else
  {
    acc = ((acc - window_97) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_79 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_79 = ((window_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_79) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int pivot_29 = local_arr[aux % 3];
  acc = (acc + (pivot_29 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000354_5413_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000354_5413_3 st_1 = {0};
  struct FilterState_R000354_5413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int tally_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_68_1)
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

  switch (tally_68_2)
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
  int anchor_31_1 = local_arr_1[aux_1 % 3];
  int anchor_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_31_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_68_1 == tally_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_31_1 == anchor_31_2);
}

int fn_R000354_5413_22(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000354_5413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int tally_68 = (aux + st.buffer[1]) & 3;
  switch (tally_68)
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
  int anchor_31 = local_arr[aux % 3];
  acc = (acc + (anchor_31 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000354_5413_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000354_5413_1 st_1 = {0};
  struct CipherContext_R000354_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int vector_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_27_1) & 63;
  aux_2 = (aux_2 + vector_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_44_1 = local_arr_1[aux_1 % 3];
  int phase_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_44_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_27_1 == vector_27_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_44_1 == phase_44_2);
}

int fn_R000354_5413_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000354_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int vector_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_27) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int phase_44 = local_arr[aux % 3];
  acc = (acc + (phase_44 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000354_0_1;
  int sec_r000354_0_2;
  int sec_r000354_1_1;
  int sec_r000354_1_2;
  int sec_r000354_2_1;
  int sec_r000354_2_2;
  int sec_r000354_3_1;
  int sec_r000354_3_2;
  int sec_r000354_4_1;
  int sec_r000354_4_2;
  int sec_r000354_5_1;
  int sec_r000354_5_2;
  int sec_r000354_6_1;
  int sec_r000354_6_2;
  int sec_r000354_7_1;
  int sec_r000354_7_2;
  int sec_r000354_8_1;
  int sec_r000354_8_2;
  int sec_r000354_9_1;
  int sec_r000354_9_2;
  int sec_r000354_10_1;
  int sec_r000354_10_2;
  int sec_r000354_11_1;
  int sec_r000354_11_2;
  int sec_r000354_12_1;
  int sec_r000354_12_2;
  int sec_r000354_13_1;
  int sec_r000354_13_2;
  int sec_r000354_14_1;
  int sec_r000354_14_2;
  int sec_r000354_15_1;
  int sec_r000354_15_2;
  int sec_r000354_16_1;
  int sec_r000354_16_2;
  int pub_r000354_0_1;
  int pub_r000354_0_2;
  int pub_r000354_1_1;
  int pub_r000354_1_2;
  int pub_r000354_2_1;
  int pub_r000354_2_2;
  int pub_r000354_3_1;
  int pub_r000354_3_2;
  int pub_r000354_4_1;
  int pub_r000354_4_2;
  int pub_r000354_5_1;
  int pub_r000354_5_2;
  int pub_r000354_6_1;
  int pub_r000354_6_2;
  int pub_r000354_7_1;
  int pub_r000354_7_2;
  int pub_r000354_8_1;
  int pub_r000354_8_2;
  int pub_r000354_9_1;
  int pub_r000354_9_2;
  int pub_r000354_10_1;
  int pub_r000354_10_2;
  int pub_r000354_11_1;
  int pub_r000354_11_2;
  int pub_r000354_12_1;
  int pub_r000354_12_2;
  int pub_r000354_13_1;
  int pub_r000354_13_2;
  int pub_r000354_14_1;
  int pub_r000354_14_2;
  int pub_r000354_15_1;
  int pub_r000354_15_2;
  int pub_r000354_16_1;
  int pub_r000354_16_2;
  int pub_r000354_17_1;
  int pub_r000354_17_2;
  int pub_r000354_18_1;
  int pub_r000354_18_2;
  int pub_r000354_19_1;
  int pub_r000354_19_2;
  int pub_r000354_20_1;
  int pub_r000354_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000354_0_1 >= (-100)) && (pub_r000354_0_1 <= 100));
  __CPROVER_assume((pub_r000354_0_2 >= (-100)) && (pub_r000354_0_2 <= 100));
  __CPROVER_assume((pub_r000354_1_1 >= (-100)) && (pub_r000354_1_1 <= 100));
  __CPROVER_assume((pub_r000354_1_2 >= (-100)) && (pub_r000354_1_2 <= 100));
  __CPROVER_assume((pub_r000354_2_1 >= (-100)) && (pub_r000354_2_1 <= 100));
  __CPROVER_assume((pub_r000354_2_2 >= (-100)) && (pub_r000354_2_2 <= 100));
  __CPROVER_assume((pub_r000354_3_1 >= (-100)) && (pub_r000354_3_1 <= 100));
  __CPROVER_assume((pub_r000354_3_2 >= (-100)) && (pub_r000354_3_2 <= 100));
  __CPROVER_assume((pub_r000354_4_1 >= (-100)) && (pub_r000354_4_1 <= 100));
  __CPROVER_assume((pub_r000354_4_2 >= (-100)) && (pub_r000354_4_2 <= 100));
  __CPROVER_assume((pub_r000354_5_1 >= (-100)) && (pub_r000354_5_1 <= 100));
  __CPROVER_assume((pub_r000354_5_2 >= (-100)) && (pub_r000354_5_2 <= 100));
  __CPROVER_assume((pub_r000354_6_1 >= (-100)) && (pub_r000354_6_1 <= 100));
  __CPROVER_assume((pub_r000354_6_2 >= (-100)) && (pub_r000354_6_2 <= 100));
  __CPROVER_assume((pub_r000354_7_1 >= (-100)) && (pub_r000354_7_1 <= 100));
  __CPROVER_assume((pub_r000354_7_2 >= (-100)) && (pub_r000354_7_2 <= 100));
  __CPROVER_assume((pub_r000354_8_1 >= (-100)) && (pub_r000354_8_1 <= 100));
  __CPROVER_assume((pub_r000354_8_2 >= (-100)) && (pub_r000354_8_2 <= 100));
  __CPROVER_assume((pub_r000354_9_1 >= (-100)) && (pub_r000354_9_1 <= 100));
  __CPROVER_assume((pub_r000354_9_2 >= (-100)) && (pub_r000354_9_2 <= 100));
  __CPROVER_assume((pub_r000354_10_1 >= (-100)) && (pub_r000354_10_1 <= 100));
  __CPROVER_assume((pub_r000354_10_2 >= (-100)) && (pub_r000354_10_2 <= 100));
  __CPROVER_assume((pub_r000354_11_1 >= (-100)) && (pub_r000354_11_1 <= 100));
  __CPROVER_assume((pub_r000354_11_2 >= (-100)) && (pub_r000354_11_2 <= 100));
  __CPROVER_assume((pub_r000354_12_1 >= (-100)) && (pub_r000354_12_1 <= 100));
  __CPROVER_assume((pub_r000354_12_2 >= (-100)) && (pub_r000354_12_2 <= 100));
  __CPROVER_assume((pub_r000354_13_1 >= (-100)) && (pub_r000354_13_1 <= 100));
  __CPROVER_assume((pub_r000354_13_2 >= (-100)) && (pub_r000354_13_2 <= 100));
  __CPROVER_assume((pub_r000354_14_1 >= (-100)) && (pub_r000354_14_1 <= 100));
  __CPROVER_assume((pub_r000354_14_2 >= (-100)) && (pub_r000354_14_2 <= 100));
  __CPROVER_assume((pub_r000354_15_1 >= (-100)) && (pub_r000354_15_1 <= 100));
  __CPROVER_assume((pub_r000354_15_2 >= (-100)) && (pub_r000354_15_2 <= 100));
  __CPROVER_assume((pub_r000354_16_1 >= (-100)) && (pub_r000354_16_1 <= 100));
  __CPROVER_assume((pub_r000354_16_2 >= (-100)) && (pub_r000354_16_2 <= 100));
  __CPROVER_assume((pub_r000354_17_1 >= (-100)) && (pub_r000354_17_1 <= 100));
  __CPROVER_assume((pub_r000354_17_2 >= (-100)) && (pub_r000354_17_2 <= 100));
  __CPROVER_assume((pub_r000354_18_1 >= (-100)) && (pub_r000354_18_1 <= 100));
  __CPROVER_assume((pub_r000354_18_2 >= (-100)) && (pub_r000354_18_2 <= 100));
  __CPROVER_assume((pub_r000354_19_1 >= (-100)) && (pub_r000354_19_1 <= 100));
  __CPROVER_assume((pub_r000354_19_2 >= (-100)) && (pub_r000354_19_2 <= 100));
  __CPROVER_assume((pub_r000354_20_1 >= (-100)) && (pub_r000354_20_1 <= 100));
  __CPROVER_assume((pub_r000354_20_2 >= (-100)) && (pub_r000354_20_2 <= 100));
  __CPROVER_assume((sec_r000354_0_1 >= 0) && (sec_r000354_0_1 <= 255));
  __CPROVER_assume((sec_r000354_0_2 >= 0) && (sec_r000354_0_2 <= 255));
  __CPROVER_assume((sec_r000354_1_1 >= 0) && (sec_r000354_1_1 <= 255));
  __CPROVER_assume((sec_r000354_1_2 >= 0) && (sec_r000354_1_2 <= 255));
  __CPROVER_assume((sec_r000354_2_1 >= 0) && (sec_r000354_2_1 <= 255));
  __CPROVER_assume((sec_r000354_2_2 >= 0) && (sec_r000354_2_2 <= 255));
  __CPROVER_assume((sec_r000354_3_1 >= 0) && (sec_r000354_3_1 <= 255));
  __CPROVER_assume((sec_r000354_3_2 >= 0) && (sec_r000354_3_2 <= 255));
  __CPROVER_assume((sec_r000354_4_1 >= 0) && (sec_r000354_4_1 <= 255));
  __CPROVER_assume((sec_r000354_4_2 >= 0) && (sec_r000354_4_2 <= 255));
  __CPROVER_assume((sec_r000354_5_1 >= 0) && (sec_r000354_5_1 <= 255));
  __CPROVER_assume((sec_r000354_5_2 >= 0) && (sec_r000354_5_2 <= 255));
  __CPROVER_assume((sec_r000354_6_1 >= 0) && (sec_r000354_6_1 <= 255));
  __CPROVER_assume((sec_r000354_6_2 >= 0) && (sec_r000354_6_2 <= 255));
  __CPROVER_assume((sec_r000354_7_1 >= 0) && (sec_r000354_7_1 <= 255));
  __CPROVER_assume((sec_r000354_7_2 >= 0) && (sec_r000354_7_2 <= 255));
  __CPROVER_assume((sec_r000354_8_1 >= 0) && (sec_r000354_8_1 <= 255));
  __CPROVER_assume((sec_r000354_8_2 >= 0) && (sec_r000354_8_2 <= 255));
  __CPROVER_assume((sec_r000354_9_1 >= 0) && (sec_r000354_9_1 <= 255));
  __CPROVER_assume((sec_r000354_9_2 >= 0) && (sec_r000354_9_2 <= 255));
  __CPROVER_assume((sec_r000354_10_1 >= 0) && (sec_r000354_10_1 <= 255));
  __CPROVER_assume((sec_r000354_10_2 >= 0) && (sec_r000354_10_2 <= 255));
  __CPROVER_assume((sec_r000354_11_1 >= 0) && (sec_r000354_11_1 <= 255));
  __CPROVER_assume((sec_r000354_11_2 >= 0) && (sec_r000354_11_2 <= 255));
  __CPROVER_assume((sec_r000354_12_1 >= 0) && (sec_r000354_12_1 <= 255));
  __CPROVER_assume((sec_r000354_12_2 >= 0) && (sec_r000354_12_2 <= 255));
  __CPROVER_assume((sec_r000354_13_1 >= 0) && (sec_r000354_13_1 <= 255));
  __CPROVER_assume((sec_r000354_13_2 >= 0) && (sec_r000354_13_2 <= 255));
  __CPROVER_assume((sec_r000354_14_1 >= 0) && (sec_r000354_14_1 <= 255));
  __CPROVER_assume((sec_r000354_14_2 >= 0) && (sec_r000354_14_2 <= 255));
  __CPROVER_assume((sec_r000354_15_1 >= 0) && (sec_r000354_15_1 <= 255));
  __CPROVER_assume((sec_r000354_15_2 >= 0) && (sec_r000354_15_2 <= 255));
  __CPROVER_assume((sec_r000354_16_1 >= 0) && (sec_r000354_16_1 <= 255));
  __CPROVER_assume((sec_r000354_16_2 >= 0) && (sec_r000354_16_2 <= 255));
  struct AudioFrame_R000354_5413_0 st_var_0_1 = {0};
  struct AudioFrame_R000354_5413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000354_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000354_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000354_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000354_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000354_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000354_0_2 + 7) & 15;
  struct CipherContext_R000354_5413_1 st_var_1_1 = {0};
  struct CipherContext_R000354_5413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000354_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000354_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000354_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000354_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000354_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000354_0_2 + 9) & 15;
  struct MatrixBlock_R000354_5413_2 st_var_2_1 = {0};
  struct MatrixBlock_R000354_5413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000354_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000354_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000354_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000354_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000354_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000354_0_2 + 11) & 15;
  struct FilterState_R000354_5413_3 st_var_3_1 = {0};
  struct FilterState_R000354_5413_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000354_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000354_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000354_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000354_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000354_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000354_0_2 + 13) & 15;
  union ColorPixel_R000354_5413_0 u_var_1;
  union ColorPixel_R000354_5413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_0_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_0_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_0_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 7) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_2_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 7) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_3_1 = ((st_var_3_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_3_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 26)
    {
      chk_sum_1 ^= stage_v_3_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_3_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 26)
    {
      chk_sum_2 ^= stage_v_3_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (st_var_1_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_1_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_5_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_6_1 = (st_var_2_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_2_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 7) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_6_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 7) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_7_1 = ((st_var_3_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_3_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 51)
    {
      chk_sum_1 ^= stage_v_7_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_7_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 51)
    {
      chk_sum_2 ^= stage_v_7_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  int stage_v_9_1 = ((st_var_1_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_1_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 49)
    {
      chk_sum_1 ^= stage_v_9_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_9_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 49)
    {
      chk_sum_2 ^= stage_v_9_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 11) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 31)
    {
      chk_sum_1 ^= stage_v_12_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_12_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 31)
    {
      chk_sum_2 ^= stage_v_12_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 14) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 14) & 15;
  int stage_v_13_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_13_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= stage_v_13_1;
  chk_sum_2 ^= stage_v_13_2;
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((st_var_3_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_3_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 47)
    {
      chk_sum_1 ^= stage_v_15_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_15_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 47)
    {
      chk_sum_2 ^= stage_v_15_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_16_1 = ((st_var_0_1.buffer[1] * 2) + 55) & 63;
  int stage_v_16_2 = ((st_var_0_2.buffer[1] * 2) + 55) & 63;
  if (stage_v_16_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_16_1) - 5) & 255;
    if (stage_v_16_1 > 53)
    {
      chk_sum_1 ^= stage_v_16_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_16_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_16_2) - 5) & 255;
    if (stage_v_16_2 > 53)
    {
      chk_sum_2 ^= stage_v_16_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 19) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 22) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 22) & 15;
  int stage_v_21_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_21_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= stage_v_21_1;
  chk_sum_2 ^= stage_v_21_2;
  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 24) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_24_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 9) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_25_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 9) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_26_1 = (st_var_2_1.buffer[0] ^ 29) & 3;
  int stage_v_26_2 = (st_var_2_2.buffer[0] ^ 29) & 3;
  switch (stage_v_26_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 8) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_26_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 8) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_27_1 = (st_var_3_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_3_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 7) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_27_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 7) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_28_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (33 & 31);
  int stage_v_28_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (33 & 31);
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= (stage_v_28_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_28_2 << 1) & 127;
  int stage_v_29_1 = table_1[1];
  int stage_v_29_2 = table_2[1];
  table_1[1] = (table_1[2] + 59) & 63;
  table_2[1] = (table_2[2] + 59) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
  int stage_v_31_1 = (st_var_3_1.buffer[0] ^ 34) & 3;
  int stage_v_31_2 = (st_var_3_2.buffer[0] ^ 34) & 3;
  switch (stage_v_31_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_31_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_32_1 = (st_var_0_1.buffer[0] ^ 35) & 3;
  int stage_v_32_2 = (st_var_0_2.buffer[0] ^ 35) & 3;
  switch (stage_v_32_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_32_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_33_1 = ((stage_v_33_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_33_2 = ((stage_v_33_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = table_1[2];
  int stage_v_34_2 = table_2[2];
  table_1[2] = (table_1[3] + 69) & 63;
  table_2[2] = (table_2[3] + 69) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 36) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 36) & 15;
  int stage_v_35_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_35_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= stage_v_35_1;
  chk_sum_2 ^= stage_v_35_2;
  int stage_v_36_1 = ((st_var_0_1.buffer[0] * 2) + 115) & 63;
  int stage_v_36_2 = ((st_var_0_2.buffer[0] * 2) + 115) & 63;
  if (stage_v_36_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 33)
    {
      chk_sum_1 ^= stage_v_36_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_36_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 33)
    {
      chk_sum_2 ^= stage_v_36_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_37_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_37_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_38_1 = table_1[2];
  int stage_v_38_2 = table_2[2];
  table_1[2] = (table_1[3] + 77) & 63;
  table_2[2] = (table_2[3] + 77) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (44 & 31);
  int stage_v_39_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (44 & 31);
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= (stage_v_39_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_39_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 41) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = table_1[1];
  int stage_v_41_2 = table_2[1];
  table_1[1] = (table_1[2] + 83) & 63;
  table_2[1] = (table_2[2] + 83) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = table_1[2];
  int stage_v_42_2 = table_2[2];
  table_1[2] = (table_1[3] + 85) & 63;
  table_2[2] = (table_2[3] + 85) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 44) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 44) & 15;
  int stage_v_43_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_43_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= stage_v_43_1;
  chk_sum_2 ^= stage_v_43_2;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_44_1 = ((stage_v_44_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((st_var_1_1.buffer[0] * 2) + 142) & 63;
  int stage_v_45_2 = ((st_var_1_2.buffer[0] * 2) + 142) & 63;
  if (stage_v_45_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_45_1) - 5) & 255;
    if (stage_v_45_1 > 39)
    {
      chk_sum_1 ^= stage_v_45_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_45_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_45_2) - 5) & 255;
    if (stage_v_45_2 > 39)
    {
      chk_sum_2 ^= stage_v_45_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 47) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 47) & 15;
  int stage_v_46_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_46_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= stage_v_46_1;
  chk_sum_2 ^= stage_v_46_2;
  int stage_v_47_1 = (st_var_3_1.buffer[0] ^ 50) & 3;
  int stage_v_47_2 = (st_var_3_2.buffer[0] ^ 50) & 3;
  switch (stage_v_47_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 2) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_47_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 2) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 49) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 49) & 15;
  int stage_v_48_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_48_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= stage_v_48_1;
  chk_sum_2 ^= stage_v_48_2;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_49_1 = ((stage_v_49_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_49_2 = ((stage_v_49_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (55 & 31);
  int stage_v_50_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (55 & 31);
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= (stage_v_50_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_50_2 << 1) & 127;
  int stage_v_51_1 = ((st_var_3_1.buffer[0] * 2) + 160) & 63;
  int stage_v_51_2 = ((st_var_3_2.buffer[0] * 2) + 160) & 63;
  if (stage_v_51_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_51_1) - 5) & 255;
    if (stage_v_51_1 > 54)
    {
      chk_sum_1 ^= stage_v_51_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_51_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_51_2) - 5) & 255;
    if (stage_v_51_2 > 54)
    {
      chk_sum_2 ^= stage_v_51_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_52_1 = ((stage_v_52_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 54) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 54) & 15;
  int stage_v_53_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_53_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= stage_v_53_1;
  chk_sum_2 ^= stage_v_53_2;
  int stage_v_54_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (59 & 31);
  int stage_v_54_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (59 & 31);
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= (stage_v_54_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_54_2 << 1) & 127;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_55_1 = ((stage_v_55_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_55_2 = ((stage_v_55_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = table_1[0];
  int stage_v_56_2 = table_2[0];
  table_1[0] = (table_1[1] + 113) & 63;
  table_2[0] = (table_2[1] + 113) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (62 & 31);
  int stage_v_57_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (62 & 31);
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= (stage_v_57_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_57_2 << 1) & 127;
  int stage_v_58_1 = ((st_var_2_1.buffer[1] * 2) + 181) & 63;
  int stage_v_58_2 = ((st_var_2_2.buffer[1] * 2) + 181) & 63;
  if (stage_v_58_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_58_1) - 5) & 255;
    if (stage_v_58_1 > 34)
    {
      chk_sum_1 ^= stage_v_58_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_58_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_58_2) - 5) & 255;
    if (stage_v_58_2 > 34)
    {
      chk_sum_2 ^= stage_v_58_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_59_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_59_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_59_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_59_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_60_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (65 & 31);
  int stage_v_60_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (65 & 31);
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= (stage_v_60_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_60_2 << 1) & 127;
  int stage_v_61_1 = (st_var_1_1.buffer[0] ^ 64) & 3;
  int stage_v_61_2 = (st_var_1_2.buffer[0] ^ 64) & 3;
  switch (stage_v_61_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 4) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_61_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 4) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_62_1 = table_1[2];
  int stage_v_62_2 = table_2[2];
  table_1[2] = (table_1[3] + 125) & 63;
  table_2[2] = (table_2[3] + 125) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((st_var_3_1.buffer[0] * 2) + 196) & 63;
  int stage_v_63_2 = ((st_var_3_2.buffer[0] * 2) + 196) & 63;
  if (stage_v_63_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_63_1) - 5) & 255;
    if (stage_v_63_1 > 30)
    {
      chk_sum_1 ^= stage_v_63_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_63_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_63_2) - 5) & 255;
    if (stage_v_63_2 > 30)
    {
      chk_sum_2 ^= stage_v_63_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 65) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 65) & 15;
  int stage_v_64_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_64_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= stage_v_64_1;
  chk_sum_2 ^= stage_v_64_2;
  int stage_v_65_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (70 & 31);
  int stage_v_65_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (70 & 31);
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= (stage_v_65_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_65_2 << 1) & 127;
  int stage_v_66_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_66_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_66_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_66_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_67_1 = table_1[3];
  int stage_v_67_2 = table_2[3];
  table_1[3] = (table_1[0] + 135) & 63;
  table_2[3] = (table_2[0] + 135) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = table_1[0];
  int stage_v_68_2 = table_2[0];
  table_1[0] = (table_1[1] + 137) & 63;
  table_2[0] = (table_2[1] + 137) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((st_var_1_1.buffer[0] * 2) + 214) & 63;
  int stage_v_69_2 = ((st_var_1_2.buffer[0] * 2) + 214) & 63;
  if (stage_v_69_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_69_1) - 5) & 255;
    if (stage_v_69_1 > 25)
    {
      chk_sum_1 ^= stage_v_69_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_69_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_69_2) - 5) & 255;
    if (stage_v_69_2 > 25)
    {
      chk_sum_2 ^= stage_v_69_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_70_1 = table_1[2];
  int stage_v_70_2 = table_2[2];
  table_1[2] = (table_1[3] + 141) & 63;
  table_2[2] = (table_2[3] + 141) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((st_var_3_1.buffer[2] * 2) + 220) & 63;
  int stage_v_71_2 = ((st_var_3_2.buffer[2] * 2) + 220) & 63;
  if (stage_v_71_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_71_1) - 5) & 255;
    if (stage_v_71_1 > 27)
    {
      chk_sum_1 ^= stage_v_71_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_71_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_71_2) - 5) & 255;
    if (stage_v_71_2 > 27)
    {
      chk_sum_2 ^= stage_v_71_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_72_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_72_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_73_1 = table_1[1];
  int stage_v_73_2 = table_2[1];
  table_1[1] = (table_1[2] + 147) & 63;
  table_2[1] = (table_2[2] + 147) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = table_1[2];
  int stage_v_74_2 = table_2[2];
  table_1[2] = (table_1[3] + 149) & 63;
  table_2[2] = (table_2[3] + 149) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = table_1[3];
  int stage_v_75_2 = table_2[3];
  table_1[3] = (table_1[0] + 151) & 63;
  table_2[3] = (table_2[0] + 151) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 77) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 77) & 15;
  int stage_v_76_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_76_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= stage_v_76_1;
  chk_sum_2 ^= stage_v_76_2;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_77_1 = ((stage_v_77_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((st_var_2_1.buffer[0] * 2) + 241) & 63;
  int stage_v_78_2 = ((st_var_2_2.buffer[0] * 2) + 241) & 63;
  if (stage_v_78_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_78_1) - 5) & 255;
    if (stage_v_78_1 > 48)
    {
      chk_sum_1 ^= stage_v_78_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_78_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_78_2) - 5) & 255;
    if (stage_v_78_2 > 48)
    {
      chk_sum_2 ^= stage_v_78_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_79_1 = ((stage_v_79_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_79_2 = ((stage_v_79_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_80_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_80_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_80_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_81_1 = ((stage_v_81_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_81_2 = ((stage_v_81_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((st_var_2_1.buffer[1] * 2) + 253) & 63;
  int stage_v_82_2 = ((st_var_2_2.buffer[1] * 2) + 253) & 63;
  if (stage_v_82_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_82_1) - 5) & 255;
    if (stage_v_82_1 > 39)
    {
      chk_sum_1 ^= stage_v_82_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_82_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_82_2) - 5) & 255;
    if (stage_v_82_2 > 39)
    {
      chk_sum_2 ^= stage_v_82_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_83_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (88 & 31);
  int stage_v_83_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (88 & 31);
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= (stage_v_83_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_83_2 << 1) & 127;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_84_1 = ((stage_v_84_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_84_2 = ((stage_v_84_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = table_1[1];
  int stage_v_85_2 = table_2[1];
  table_1[1] = (table_1[2] + 171) & 63;
  table_2[1] = (table_2[2] + 171) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((st_var_2_1.buffer[2] * 2) + 265) & 63;
  int stage_v_86_2 = ((st_var_2_2.buffer[2] * 2) + 265) & 63;
  if (stage_v_86_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_86_1) - 5) & 255;
    if (stage_v_86_1 > 46)
    {
      chk_sum_1 ^= stage_v_86_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_86_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_86_2) - 5) & 255;
    if (stage_v_86_2 > 46)
    {
      chk_sum_2 ^= stage_v_86_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_87_1 = ((stage_v_87_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_87_2 = ((stage_v_87_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_88_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_88_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_88_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_89_1 = (st_var_1_1.buffer[0] ^ 92) & 3;
  int stage_v_89_2 = (st_var_1_2.buffer[0] ^ 92) & 3;
  switch (stage_v_89_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 8) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_89_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 8) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 91) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 91) & 15;
  int stage_v_90_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_90_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  chk_sum_1 ^= stage_v_90_1;
  chk_sum_2 ^= stage_v_90_2;
  int stage_v_91_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (96 & 31);
  int stage_v_91_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (96 & 31);
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  chk_sum_1 ^= (stage_v_91_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_91_2 << 1) & 127;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_92_1 = ((stage_v_92_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_92_2 = ((stage_v_92_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((st_var_1_1.buffer[0] * 2) + 286) & 63;
  int stage_v_93_2 = ((st_var_1_2.buffer[0] * 2) + 286) & 63;
  if (stage_v_93_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_93_1) - 5) & 255;
    if (stage_v_93_1 > 48)
    {
      chk_sum_1 ^= stage_v_93_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_93_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_93_2) - 5) & 255;
    if (stage_v_93_2 > 48)
    {
      chk_sum_2 ^= stage_v_93_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 95) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 95) & 15;
  int stage_v_94_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_94_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  chk_sum_1 ^= stage_v_94_1;
  chk_sum_2 ^= stage_v_94_2;
  int stage_v_95_1 = ((st_var_3_1.buffer[2] * 2) + 292) & 63;
  int stage_v_95_2 = ((st_var_3_2.buffer[2] * 2) + 292) & 63;
  if (stage_v_95_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_95_1) - 5) & 255;
    if (stage_v_95_1 > 44)
    {
      chk_sum_1 ^= stage_v_95_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_95_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_95_2) - 5) & 255;
    if (stage_v_95_2 > 44)
    {
      chk_sum_2 ^= stage_v_95_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_96_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (101 & 31);
  int stage_v_96_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (101 & 31);
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  chk_sum_1 ^= (stage_v_96_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_96_2 << 1) & 127;
  int stage_v_97_1 = (st_var_1_1.buffer[0] ^ 100) & 3;
  int stage_v_97_2 = (st_var_1_2.buffer[0] ^ 100) & 3;
  switch (stage_v_97_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_97_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_98_1 = ((stage_v_98_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_98_2 = ((stage_v_98_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((st_var_3_1.buffer[0] * 2) + 304) & 63;
  int stage_v_99_2 = ((st_var_3_2.buffer[0] * 2) + 304) & 63;
  if (stage_v_99_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_99_1) - 5) & 255;
    if (stage_v_99_1 > 37)
    {
      chk_sum_1 ^= stage_v_99_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_99_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_99_2) - 5) & 255;
    if (stage_v_99_2 > 37)
    {
      chk_sum_2 ^= stage_v_99_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_100_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_100_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_100_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_100_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_101_1 = (st_var_1_1.buffer[0] ^ 104) & 3;
  int stage_v_101_2 = (st_var_1_2.buffer[0] ^ 104) & 3;
  switch (stage_v_101_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 7) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_101_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 7) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_102_1 = ((st_var_2_1.buffer[0] * 2) + 313) & 63;
  int stage_v_102_2 = ((st_var_2_2.buffer[0] * 2) + 313) & 63;
  if (stage_v_102_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_102_1) - 5) & 255;
    if (stage_v_102_1 > 27)
    {
      chk_sum_1 ^= stage_v_102_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_102_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_102_2) - 5) & 255;
    if (stage_v_102_2 > 27)
    {
      chk_sum_2 ^= stage_v_102_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_103_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_103_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_103_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_103_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 105) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 105) & 15;
  int stage_v_104_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_104_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  chk_sum_1 ^= stage_v_104_1;
  chk_sum_2 ^= stage_v_104_2;
  int stage_v_105_1 = (st_var_1_1.buffer[0] ^ 108) & 3;
  int stage_v_105_2 = (st_var_1_2.buffer[0] ^ 108) & 3;
  switch (stage_v_105_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 9) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_105_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 9) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_106_1 = ((st_var_2_1.buffer[1] * 2) + 325) & 63;
  int stage_v_106_2 = ((st_var_2_2.buffer[1] * 2) + 325) & 63;
  if (stage_v_106_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_106_1) - 5) & 255;
    if (stage_v_106_1 > 49)
    {
      chk_sum_1 ^= stage_v_106_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_106_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_106_2) - 5) & 255;
    if (stage_v_106_2 > 49)
    {
      chk_sum_2 ^= stage_v_106_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_107_1 = ((stage_v_107_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_107_2 = ((stage_v_107_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((st_var_0_1.buffer[0] * 2) + 331) & 63;
  int stage_v_108_2 = ((st_var_0_2.buffer[0] * 2) + 331) & 63;
  if (stage_v_108_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_108_1) - 5) & 255;
    if (stage_v_108_1 > 53)
    {
      chk_sum_1 ^= stage_v_108_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_108_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_108_2) - 5) & 255;
    if (stage_v_108_2 > 53)
    {
      chk_sum_2 ^= stage_v_108_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 110) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 110) & 15;
  int stage_v_109_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_109_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  chk_sum_1 ^= stage_v_109_1;
  chk_sum_2 ^= stage_v_109_2;
  int stage_v_110_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (115 & 31);
  int stage_v_110_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (115 & 31);
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  chk_sum_1 ^= (stage_v_110_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_110_2 << 1) & 127;
  int stage_v_111_1 = (st_var_3_1.buffer[0] ^ 114) & 3;
  int stage_v_111_2 = (st_var_3_2.buffer[0] ^ 114) & 3;
  switch (stage_v_111_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 7) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_111_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 7) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_112_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (117 & 31);
  int stage_v_112_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (117 & 31);
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  chk_sum_1 ^= (stage_v_112_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_112_2 << 1) & 127;
  int stage_v_113_1 = (st_var_1_1.buffer[0] ^ 116) & 3;
  int stage_v_113_2 = (st_var_1_2.buffer[0] ^ 116) & 3;
  switch (stage_v_113_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_113_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_114_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_114_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_114_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_114_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_115_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (120 & 31);
  int stage_v_115_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (120 & 31);
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  chk_sum_1 ^= (stage_v_115_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_115_2 << 1) & 127;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_116_1 = ((stage_v_116_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_116_2 = ((stage_v_116_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = table_1[1];
  int stage_v_117_2 = table_2[1];
  table_1[1] = (table_1[2] + 235) & 63;
  table_2[1] = (table_2[2] + 235) & 63;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_118_1 = ((stage_v_118_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_118_2 = ((stage_v_118_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = table_1[3];
  int stage_v_119_2 = table_2[3];
  table_1[3] = (table_1[0] + 239) & 63;
  table_2[3] = (table_2[0] + 239) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((st_var_0_1.buffer[0] * 2) + 367) & 63;
  int stage_v_120_2 = ((st_var_0_2.buffer[0] * 2) + 367) & 63;
  if (stage_v_120_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_120_1) - 5) & 255;
    if (stage_v_120_1 > 32)
    {
      chk_sum_1 ^= stage_v_120_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_120_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_120_2) - 5) & 255;
    if (stage_v_120_2 > 32)
    {
      chk_sum_2 ^= stage_v_120_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_121_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_121_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_121_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_121_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_122_1 = ((st_var_2_1.buffer[2] * 2) + 373) & 63;
  int stage_v_122_2 = ((st_var_2_2.buffer[2] * 2) + 373) & 63;
  if (stage_v_122_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_122_1) - 5) & 255;
    if (stage_v_122_1 > 38)
    {
      chk_sum_1 ^= stage_v_122_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_122_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_122_2) - 5) & 255;
    if (stage_v_122_2 > 38)
    {
      chk_sum_2 ^= stage_v_122_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 124) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 124) & 15;
  int stage_v_123_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_123_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  chk_sum_1 ^= stage_v_123_1;
  chk_sum_2 ^= stage_v_123_2;
  int stage_v_124_1 = ((st_var_0_1.buffer[1] * 2) + 379) & 63;
  int stage_v_124_2 = ((st_var_0_2.buffer[1] * 2) + 379) & 63;
  if (stage_v_124_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_124_1) - 5) & 255;
    if (stage_v_124_1 > 51)
    {
      chk_sum_1 ^= stage_v_124_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_124_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_124_2) - 5) & 255;
    if (stage_v_124_2 > 51)
    {
      chk_sum_2 ^= stage_v_124_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_125_1 = table_1[1];
  int stage_v_125_2 = table_2[1];
  table_1[1] = (table_1[2] + 251) & 63;
  table_2[1] = (table_2[2] + 251) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_126_1 = ((stage_v_126_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_126_2 = ((stage_v_126_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((st_var_3_1.buffer[1] * 2) + 388) & 63;
  int stage_v_127_2 = ((st_var_3_2.buffer[1] * 2) + 388) & 63;
  if (stage_v_127_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_127_1) - 5) & 255;
    if (stage_v_127_1 > 41)
    {
      chk_sum_1 ^= stage_v_127_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_127_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_127_2) - 5) & 255;
    if (stage_v_127_2 > 41)
    {
      chk_sum_2 ^= stage_v_127_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 129) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 129) & 15;
  int stage_v_128_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_128_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  chk_sum_1 ^= stage_v_128_1;
  chk_sum_2 ^= stage_v_128_2;
  int stage_v_129_1 = (st_var_1_1.buffer[0] ^ 132) & 3;
  int stage_v_129_2 = (st_var_1_2.buffer[0] ^ 132) & 3;
  switch (stage_v_129_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 9) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_129_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 9) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_130_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (135 & 31);
  int stage_v_130_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (135 & 31);
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  chk_sum_1 ^= (stage_v_130_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_130_2 << 1) & 127;
  int stage_v_131_1 = (st_var_3_1.buffer[0] ^ 134) & 3;
  int stage_v_131_2 = (st_var_3_2.buffer[0] ^ 134) & 3;
  switch (stage_v_131_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 7) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_131_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 7) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_132_1 = ((stage_v_132_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_132_2 = ((stage_v_132_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((st_var_1_1.buffer[1] * 2) + 406) & 63;
  int stage_v_133_2 = ((st_var_1_2.buffer[1] * 2) + 406) & 63;
  if (stage_v_133_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_133_1) - 5) & 255;
    if (stage_v_133_1 > 43)
    {
      chk_sum_1 ^= stage_v_133_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_133_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_133_2) - 5) & 255;
    if (stage_v_133_2 > 43)
    {
      chk_sum_2 ^= stage_v_133_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 135) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 135) & 15;
  int stage_v_134_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_134_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  chk_sum_1 ^= stage_v_134_1;
  chk_sum_2 ^= stage_v_134_2;
  int stage_v_135_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_135_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_135_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_135_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_136_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (141 & 31);
  int stage_v_136_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (141 & 31);
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  chk_sum_1 ^= (stage_v_136_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_136_2 << 1) & 127;
  int stage_v_137_1 = (st_var_1_1.buffer[0] ^ 140) & 3;
  int stage_v_137_2 = (st_var_1_2.buffer[0] ^ 140) & 3;
  switch (stage_v_137_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 5) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_137_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 5) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_138_1 = ((stage_v_138_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_138_2 = ((stage_v_138_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((st_var_3_1.buffer[1] * 2) + 424) & 63;
  int stage_v_139_2 = ((st_var_3_2.buffer[1] * 2) + 424) & 63;
  if (stage_v_139_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_139_1) - 5) & 255;
    if (stage_v_139_1 > 36)
    {
      chk_sum_1 ^= stage_v_139_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_139_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_139_2) - 5) & 255;
    if (stage_v_139_2 > 36)
    {
      chk_sum_2 ^= stage_v_139_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_140_1 = (st_var_0_1.buffer[0] ^ 143) & 3;
  int stage_v_140_2 = (st_var_0_2.buffer[0] ^ 143) & 3;
  switch (stage_v_140_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 5) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_140_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 5) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_141_1 = table_1[1];
  int stage_v_141_2 = table_2[1];
  table_1[1] = (table_1[2] + 283) & 63;
  table_2[1] = (table_2[2] + 283) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 143) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 143) & 15;
  int stage_v_142_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_142_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  chk_sum_1 ^= stage_v_142_1;
  chk_sum_2 ^= stage_v_142_2;
  int stage_v_143_1 = table_1[3];
  int stage_v_143_2 = table_2[3];
  table_1[3] = (table_1[0] + 287) & 63;
  table_2[3] = (table_2[0] + 287) & 63;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_144_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_144_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_144_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 146) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 146) & 15;
  int stage_v_145_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_145_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  chk_sum_1 ^= stage_v_145_1;
  chk_sum_2 ^= stage_v_145_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 147) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 147) & 15;
  int stage_v_146_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_146_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  chk_sum_1 ^= stage_v_146_1;
  chk_sum_2 ^= stage_v_146_2;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 148) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 148) & 15;
  int stage_v_147_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_147_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  chk_sum_1 ^= stage_v_147_1;
  chk_sum_2 ^= stage_v_147_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 149) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 149) & 15;
  int stage_v_148_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_148_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  chk_sum_1 ^= stage_v_148_1;
  chk_sum_2 ^= stage_v_148_2;
  int stage_v_149_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (154 & 31);
  int stage_v_149_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (154 & 31);
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  chk_sum_1 ^= (stage_v_149_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_149_2 << 1) & 127;
  int stage_v_150_1 = (st_var_2_1.buffer[0] ^ 153) & 3;
  int stage_v_150_2 = (st_var_2_2.buffer[0] ^ 153) & 3;
  switch (stage_v_150_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 7) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_150_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 7) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_151_1 = ((st_var_3_1.buffer[1] * 2) + 460) & 63;
  int stage_v_151_2 = ((st_var_3_2.buffer[1] * 2) + 460) & 63;
  if (stage_v_151_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_151_1) - 5) & 255;
    if (stage_v_151_1 > 36)
    {
      chk_sum_1 ^= stage_v_151_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_151_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_151_2) - 5) & 255;
    if (stage_v_151_2 > 36)
    {
      chk_sum_2 ^= stage_v_151_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_152_1 = table_1[0];
  int stage_v_152_2 = table_2[0];
  table_1[0] = (table_1[1] + 305) & 63;
  table_2[0] = (table_2[1] + 305) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (158 & 31);
  int stage_v_153_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (158 & 31);
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  chk_sum_1 ^= (stage_v_153_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_153_2 << 1) & 127;
  int stage_v_154_1 = table_1[2];
  int stage_v_154_2 = table_2[2];
  table_1[2] = (table_1[3] + 309) & 63;
  table_2[2] = (table_2[3] + 309) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (st_var_3_1.buffer[0] ^ 158) & 3;
  int stage_v_155_2 = (st_var_3_2.buffer[0] ^ 158) & 3;
  switch (stage_v_155_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 7) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_155_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 7) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_156_1 = ((st_var_0_1.buffer[0] * 2) + 475) & 63;
  int stage_v_156_2 = ((st_var_0_2.buffer[0] * 2) + 475) & 63;
  if (stage_v_156_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_156_1) - 5) & 255;
    if (stage_v_156_1 > 46)
    {
      chk_sum_1 ^= stage_v_156_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_156_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_156_2) - 5) & 255;
    if (stage_v_156_2 > 46)
    {
      chk_sum_2 ^= stage_v_156_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_157_1 = table_1[1];
  int stage_v_157_2 = table_2[1];
  table_1[1] = (table_1[2] + 315) & 63;
  table_2[1] = (table_2[2] + 315) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (st_var_2_1.buffer[0] ^ 161) & 3;
  int stage_v_158_2 = (st_var_2_2.buffer[0] ^ 161) & 3;
  switch (stage_v_158_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 8) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_158_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 8) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_159_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_159_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_159_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_159_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_160_1 = ((stage_v_160_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_160_2 = ((stage_v_160_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = (st_var_1_1.buffer[0] ^ 164) & 3;
  int stage_v_161_2 = (st_var_1_2.buffer[0] ^ 164) & 3;
  switch (stage_v_161_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 9) & 255;
      break;

    case 1:
      chk_sum_1 ^= 0x3F;
      break;

    case 2:
      out_sink_1 = (out_sink_1 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_1 = (chk_sum_1 + 7) & 127;
      break;

  }

  switch (stage_v_161_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 9) & 255;
      break;

    case 1:
      chk_sum_2 ^= 0x3F;
      break;

    case 2:
      out_sink_2 = (out_sink_2 ^ 0x2A) & 255;
      break;

    default:
      chk_sum_2 = (chk_sum_2 + 7) & 127;
      break;

  }

  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_162_1 = ((stage_v_162_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_162_2 = ((stage_v_162_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((st_var_3_1.buffer[1] * 2) + 496) & 63;
  int stage_v_163_2 = ((st_var_3_2.buffer[1] * 2) + 496) & 63;
  if (stage_v_163_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_163_1) - 5) & 255;
    if (stage_v_163_1 > 55)
    {
      chk_sum_1 ^= stage_v_163_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_163_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_163_2) - 5) & 255;
    if (stage_v_163_2 > 55)
    {
      chk_sum_2 ^= stage_v_163_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_164_1 = table_1[0];
  int stage_v_164_2 = table_2[0];
  table_1[0] = (table_1[1] + 329) & 63;
  table_2[0] = (table_2[1] + 329) & 63;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int arith_v_0_1 = ((sec_r000354_4_1 * 3) + pub_r000354_17_1) & 127;
  int arith_v_0_2 = ((sec_r000354_4_2 * 3) + pub_r000354_17_2) & 127;
  int arith_v_1_1 = (arith_v_0_1 ^ (sec_r000354_7_1 * 2)) & 127;
  int arith_v_1_2 = (arith_v_0_2 ^ (sec_r000354_7_2 * 2)) & 127;
  int arith_v_2_1 = (arith_v_1_1 + (sec_r000354_6_1 * 2)) & 127;
  int arith_v_2_2 = (arith_v_1_2 + (sec_r000354_6_2 * 2)) & 127;
  int arith_v_3_1 = (arith_v_2_1 ^ (sec_r000354_8_1 * 2)) & 127;
  int arith_v_3_2 = (arith_v_2_2 ^ (sec_r000354_8_2 * 2)) & 127;
  out_sink_1 += arith_v_3_1 & 255;
  out_sink_2 += arith_v_3_2 & 255;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000354_9_1 == pub_r000354_9_2);
  __CPROVER_assume(pub_r000354_10_1 == pub_r000354_10_2);
  __CPROVER_assume(sec_r000354_9_1 != sec_r000354_9_2);
  __CPROVER_assume(pub_r000354_11_1 == pub_r000354_11_2);
  __CPROVER_assume(pub_r000354_19_1 == pub_r000354_19_2);
  __CPROVER_assume(pub_r000354_7_1 == pub_r000354_7_2);
  __CPROVER_assume(pub_r000354_13_1 == pub_r000354_13_2);
  __CPROVER_assume(sec_r000354_15_1 != sec_r000354_15_2);
  __CPROVER_assume(pub_r000354_5_1 == pub_r000354_5_2);
  __CPROVER_assume(sec_r000354_4_1 != sec_r000354_4_2);
  __CPROVER_assume(sec_r000354_7_1 != sec_r000354_7_2);
  __CPROVER_assume(sec_r000354_2_1 != sec_r000354_2_2);
  __CPROVER_assume(sec_r000354_14_1 != sec_r000354_14_2);
  __CPROVER_assume(pub_r000354_6_1 == pub_r000354_6_2);
  __CPROVER_assume(sec_r000354_5_1 != sec_r000354_5_2);
  __CPROVER_assume(sec_r000354_1_1 != sec_r000354_1_2);
  __CPROVER_assume(pub_r000354_18_1 == pub_r000354_18_2);
  __CPROVER_assume(pub_r000354_16_1 == pub_r000354_16_2);
  __CPROVER_assume(pub_r000354_12_1 == pub_r000354_12_2);
  __CPROVER_assume(pub_r000354_0_1 == pub_r000354_0_2);
  __CPROVER_assume(sec_r000354_16_1 != sec_r000354_16_2);
  __CPROVER_assume(sec_r000354_11_1 != sec_r000354_11_2);
  __CPROVER_assume(pub_r000354_1_1 == pub_r000354_1_2);
  __CPROVER_assume(pub_r000354_15_1 == pub_r000354_15_2);
  __CPROVER_assume(sec_r000354_10_1 != sec_r000354_10_2);
  __CPROVER_assume(sec_r000354_8_1 != sec_r000354_8_2);
  __CPROVER_assume(sec_r000354_13_1 != sec_r000354_13_2);
  __CPROVER_assume(pub_r000354_14_1 == pub_r000354_14_2);
  __CPROVER_assume(sec_r000354_3_1 != sec_r000354_3_2);
  __CPROVER_assume(pub_r000354_3_1 == pub_r000354_3_2);
  __CPROVER_assume(pub_r000354_20_1 == pub_r000354_20_2);
  __CPROVER_assume(sec_r000354_6_1 != sec_r000354_6_2);
  __CPROVER_assume(sec_r000354_0_1 != sec_r000354_0_2);
  __CPROVER_assume(sec_r000354_12_1 != sec_r000354_12_2);
  __CPROVER_assume(pub_r000354_8_1 == pub_r000354_8_2);
  __CPROVER_assume(pub_r000354_17_1 == pub_r000354_17_2);
  __CPROVER_assume(pub_r000354_4_1 == pub_r000354_4_2);
  __CPROVER_assume(pub_r000354_2_1 == pub_r000354_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.tag == st_var_1_2.tag);
  assert(st_var_1_1.counter == st_var_1_2.counter);
  assert(st_var_1_1.flags == st_var_1_2.flags);
  assert(st_var_1_1.nonce == st_var_1_2.nonce);
  assert(st_var_1_1.iv == st_var_1_2.iv);
  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.dim == st_var_2_2.dim);
  assert(st_var_2_1.density == st_var_2_2.density);
  assert(st_var_2_1.stride == st_var_2_2.stride);
  assert(st_var_2_1.determinant == st_var_2_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.damping == st_var_3_2.damping);
  assert(st_var_3_1.prev_in == st_var_3_2.prev_in);
  assert(st_var_3_1.gain_db == st_var_3_2.gain_db);
  assert(st_var_3_1.cutoff == st_var_3_2.cutoff);
  assert(st_var_3_1.mode == st_var_3_2.mode);
  assert(st_var_3_1.prev_out == st_var_3_2.prev_out);
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
  assert(arith_v_0_1 == arith_v_0_2);
  assert(arith_v_1_1 == arith_v_1_2);
  assert(arith_v_2_1 == arith_v_2_2);
  assert(arith_v_3_1 == arith_v_3_2);
}


