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
struct CipherContext_R001002_213_0
{
  short round_key;
  int tag;
  unsigned char flags;
  int buffer[3];
};
struct FilterState_R001002_213_1
{
  int prev_out;
  short mode;
  short prev_in;
  unsigned char cutoff;
  int buffer[3];
};
struct MatrixBlock_R001002_213_2
{
  short determinant;
  int scale;
  int density;
  short stride;
  short trace;
  int buffer[3];
};
struct EventLog_R001002_213_3
{
  short timestamp;
  int facility;
  unsigned char severity;
  int buffer[3];
};
union TelemetryField_R001002_213_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001002_213_1
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
void fn_R001002_213_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001002_213_1 st_1 = {0};
  struct FilterState_R001002_213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int quantum_59_1 = 0;
  int quantum_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_59_1 = ((quantum_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_59_2 = ((quantum_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_59_1) & 127;
    acc_2 = (acc_2 + quantum_59_2) & 127;
  }

  int threshold_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_82_1) & 63;
  aux_2 = (aux_2 + threshold_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_88_1 > 30)
  {
    acc_1 = ((acc_1 + (window_88_1 * 2)) + 5) & 127;
    aux_1 ^= window_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_88_2 > 30)
  {
    acc_2 = ((acc_2 + (window_88_2 * 2)) + 5) & 127;
    aux_2 ^= window_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_88_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_60_1)
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

  switch (phase_60_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_59_1 == quantum_59_2);
  assert(threshold_82_1 == threshold_82_2);
  assert(window_88_1 == window_88_2);
  assert(phase_60_1 == phase_60_2);
}

int fn_R001002_213_0(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001002_213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int quantum_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_59 = ((quantum_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_59) & 127;
  }

  int threshold_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_82) & 63;
  acc ^= aux;
  int window_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_88 > 30)
  {
    acc = ((acc + (window_88 * 2)) + 5) & 127;
    aux ^= window_88 & 15;
  }
  else
  {
    acc = ((acc - window_88) + 11) & 127;
    aux += 3;
  }
  int phase_60 = (aux + st.buffer[1]) & 3;
  switch (phase_60)
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

void fn_R001002_213_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001002_213_2 st_1 = {0};
  struct MatrixBlock_R001002_213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_99_1 = local_arr_1[aux_1 % 3];
  int window_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_99_2 * 2)) & 127;
  int accumulator_57_1 = 0;
  int accumulator_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_57_1 = ((accumulator_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_57_2 = ((accumulator_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_57_1) & 127;
    acc_2 = (acc_2 + accumulator_57_2) & 127;
  }

  int parity_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_87_1)
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

  switch (parity_87_2)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_99_1 == window_99_2);
  assert(accumulator_57_1 == accumulator_57_2);
  assert(parity_87_1 == parity_87_2);
}

int fn_R001002_213_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001002_213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int window_99 = local_arr[aux % 3];
  acc = (acc + (window_99 * 2)) & 127;
  int accumulator_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_57 = ((accumulator_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_57) & 127;
  }

  int parity_87 = (aux + st.buffer[1]) & 3;
  switch (parity_87)
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

void fn_R001002_213_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001002_213_0 st_1 = {0};
  struct CipherContext_R001002_213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int scale_49_1 = 0;
  int scale_49_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_49_1 = ((scale_49_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_49_2 = ((scale_49_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_49_1) & 127;
    acc_2 = (acc_2 + scale_49_2) & 127;
  }

  int tally_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_41_1) & 63;
  aux_2 = (aux_2 + tally_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_49_1 == scale_49_2);
  assert(tally_41_1 == tally_41_2);
}

int fn_R001002_213_2(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001002_213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int scale_49 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_49 = ((scale_49 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_49) & 127;
  }

  int tally_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_41) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001002_213_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001002_213_0 st_1 = {0};
  struct CipherContext_R001002_213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int parity_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_87_1)
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

  switch (parity_87_2)
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

  int window_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_28_1) & 63;
  aux_2 = (aux_2 + window_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_12_1 > 37)
  {
    acc_1 = ((acc_1 + (coefficient_12_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_12_2 > 37)
  {
    acc_2 = ((acc_2 + (coefficient_12_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_78_1 = 0;
  int phase_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_78_1 = ((phase_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_78_2 = ((phase_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_78_1) & 127;
    acc_2 = (acc_2 + phase_78_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_87_1 == parity_87_2);
  assert(window_28_1 == window_28_2);
  assert(coefficient_12_1 == coefficient_12_2);
  assert(phase_78_1 == phase_78_2);
}

int fn_R001002_213_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001002_213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int parity_87 = (aux + st.buffer[1]) & 3;
  switch (parity_87)
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

  int window_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_28) & 63;
  acc ^= aux;
  int coefficient_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_12 > 37)
  {
    acc = ((acc + (coefficient_12 * 2)) + 5) & 127;
    aux ^= coefficient_12 & 15;
  }
  else
  {
    acc = ((acc - coefficient_12) + 11) & 127;
    aux += 3;
  }
  int phase_78 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_78 = ((phase_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_78) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001002_213_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001002_213_1 st_1 = {0};
  struct FilterState_R001002_213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int vector_85_1 = 0;
  int vector_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_85_1 = ((vector_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_85_2 = ((vector_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_85_1) & 127;
    acc_2 = (acc_2 + vector_85_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_52_1 = local_arr_1[aux_1 % 3];
  int vector_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_52_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_85_1 == vector_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_52_1 == vector_52_2);
}

int fn_R001002_213_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001002_213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int vector_85 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_85 = ((vector_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_85) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int vector_52 = local_arr[aux % 3];
  acc = (acc + (vector_52 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001002_213_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001002_213_2 st_1 = {0};
  struct MatrixBlock_R001002_213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int quotient_14_1 = 0;
  int quotient_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_14_1 = ((quotient_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_14_2 = ((quotient_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_14_1) & 127;
    acc_2 = (acc_2 + quotient_14_2) & 127;
  }

  int mask_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_82_1)
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

  switch (mask_82_2)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_14_1 == quotient_14_2);
  assert(mask_82_1 == mask_82_2);
}

int fn_R001002_213_5(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001002_213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int quotient_14 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_14 = ((quotient_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_14) & 127;
  }

  int mask_82 = (aux + st.buffer[1]) & 3;
  switch (mask_82)
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

void fn_R001002_213_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001002_213_1 st_1 = {0};
  struct FilterState_R001002_213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int factor_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_84_1 > 19)
  {
    acc_1 = ((acc_1 + (factor_84_1 * 2)) + 5) & 127;
    aux_1 ^= factor_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_84_2 > 19)
  {
    acc_2 = ((acc_2 + (factor_84_2 * 2)) + 5) & 127;
    aux_2 ^= factor_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_21_1 = 0;
  int checksum_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_21_1 = ((checksum_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_21_2 = ((checksum_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_21_1) & 127;
    acc_2 = (acc_2 + checksum_21_2) & 127;
  }

  int margin_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_93_1)
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

  switch (margin_93_2)
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
  int factor_81_1 = local_arr_1[aux_1 % 3];
  int factor_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_81_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_84_1 == factor_84_2);
  assert(checksum_21_1 == checksum_21_2);
  assert(margin_93_1 == margin_93_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_81_1 == factor_81_2);
}

int fn_R001002_213_6(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001002_213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int factor_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_84 > 19)
  {
    acc = ((acc + (factor_84 * 2)) + 5) & 127;
    aux ^= factor_84 & 15;
  }
  else
  {
    acc = ((acc - factor_84) + 11) & 127;
    aux += 3;
  }
  int checksum_21 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_21 = ((checksum_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_21) & 127;
  }

  int margin_93 = (aux + st.buffer[1]) & 3;
  switch (margin_93)
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
  int factor_81 = local_arr[aux % 3];
  acc = (acc + (factor_81 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001002_213_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001002_213_3 st_1 = {0};
  struct EventLog_R001002_213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_62_1) & 63;
  aux_2 = (aux_2 + cursor_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_16_1 > 38)
  {
    acc_1 = ((acc_1 + (window_16_1 * 2)) + 5) & 127;
    aux_1 ^= window_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_16_2 > 38)
  {
    acc_2 = ((acc_2 + (window_16_2 * 2)) + 5) & 127;
    aux_2 ^= window_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_16_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_21_1)
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

  switch (mask_21_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_62_1 == cursor_62_2);
  assert(window_16_1 == window_16_2);
  assert(mask_21_1 == mask_21_2);
}

int fn_R001002_213_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001002_213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_62) & 63;
  acc ^= aux;
  int window_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_16 > 38)
  {
    acc = ((acc + (window_16 * 2)) + 5) & 127;
    aux ^= window_16 & 15;
  }
  else
  {
    acc = ((acc - window_16) + 11) & 127;
    aux += 3;
  }
  int mask_21 = (aux + st.buffer[1]) & 3;
  switch (mask_21)
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

void fn_R001002_213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001002_213_3 st_1 = {0};
  struct EventLog_R001002_213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int segment_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_92_1)
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

  switch (segment_92_2)
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
  int parity_12_1 = local_arr_1[aux_1 % 3];
  int parity_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_12_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_92_1 == segment_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_12_1 == parity_12_2);
}

int fn_R001002_213_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001002_213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int segment_92 = (aux + st.buffer[1]) & 3;
  switch (segment_92)
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
  int parity_12 = local_arr[aux % 3];
  acc = (acc + (parity_12 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001002_213_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001002_213_2 st_1 = {0};
  struct MatrixBlock_R001002_213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int tally_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_87_1 > 32)
  {
    acc_1 = ((acc_1 + (tally_87_1 * 2)) + 5) & 127;
    aux_1 ^= tally_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_87_2 > 32)
  {
    acc_2 = ((acc_2 + (tally_87_2 * 2)) + 5) & 127;
    aux_2 ^= tally_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_87_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_34_1) & 63;
  aux_2 = (aux_2 + scale_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_87_1 == tally_87_2);
  assert(scale_34_1 == scale_34_2);
}

int fn_R001002_213_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001002_213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int tally_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_87 > 32)
  {
    acc = ((acc + (tally_87 * 2)) + 5) & 127;
    aux ^= tally_87 & 15;
  }
  else
  {
    acc = ((acc - tally_87) + 11) & 127;
    aux += 3;
  }
  int scale_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_34) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001002_213_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001002_213_2 st_1 = {0};
  struct MatrixBlock_R001002_213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_54_1 = local_arr_1[aux_1 % 3];
  int phase_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_54_2 * 2)) & 127;
  int stride_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_43_1)
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

  switch (stride_43_2)
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
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_54_1 == phase_54_2);
  assert(stride_43_1 == stride_43_2);
}

int fn_R001002_213_10(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001002_213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int phase_54 = local_arr[aux % 3];
  acc = (acc + (phase_54 * 2)) & 127;
  int stride_43 = (aux + st.buffer[1]) & 3;
  switch (stride_43)
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

void fn_R001002_213_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001002_213_3 st_1 = {0};
  struct EventLog_R001002_213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int factor_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_74_1)
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

  switch (factor_74_2)
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
  int tally_34_1 = local_arr_1[aux_1 % 3];
  int tally_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_34_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_74_1 == factor_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_34_1 == tally_34_2);
}

int fn_R001002_213_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001002_213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int factor_74 = (aux + st.buffer[1]) & 3;
  switch (factor_74)
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
  int tally_34 = local_arr[aux % 3];
  acc = (acc + (tally_34 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001002_213_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001002_213_1 st_1 = {0};
  struct FilterState_R001002_213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int residue_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_99_1 > 17)
  {
    acc_1 = ((acc_1 + (residue_99_1 * 2)) + 5) & 127;
    aux_1 ^= residue_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_99_2 > 17)
  {
    acc_2 = ((acc_2 + (residue_99_2 * 2)) + 5) & 127;
    aux_2 ^= residue_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_15_1 = 0;
  int metric_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_15_1 = ((metric_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_15_2 = ((metric_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_15_1) & 127;
    acc_2 = (acc_2 + metric_15_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_74_1 = local_arr_1[aux_1 % 3];
  int cursor_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_74_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_99_1 == residue_99_2);
  assert(metric_15_1 == metric_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_74_1 == cursor_74_2);
}

int fn_R001002_213_12(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001002_213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int residue_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_99 > 17)
  {
    acc = ((acc + (residue_99 * 2)) + 5) & 127;
    aux ^= residue_99 & 15;
  }
  else
  {
    acc = ((acc - residue_99) + 11) & 127;
    aux += 3;
  }
  int metric_15 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_15 = ((metric_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_15) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int cursor_74 = local_arr[aux % 3];
  acc = (acc + (cursor_74 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001002_213_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001002_213_3 st_1 = {0};
  struct EventLog_R001002_213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_27_1 = local_arr_1[aux_1 % 3];
  int anchor_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_27_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_27_1 == anchor_27_2);
}

int fn_R001002_213_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001002_213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int anchor_27 = local_arr[aux % 3];
  acc = (acc + (anchor_27 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001002_213_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001002_213_0 st_1 = {0};
  struct CipherContext_R001002_213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_41_1 = 0;
  int phase_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_41_1 = ((phase_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_41_2 = ((phase_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_41_1) & 127;
    acc_2 = (acc_2 + phase_41_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_56_1 = local_arr_1[aux_1 % 3];
  int residue_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_56_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_41_1 == phase_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_56_1 == residue_56_2);
}

int fn_R001002_213_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001002_213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_41 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_41 = ((phase_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_41) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int residue_56 = local_arr[aux % 3];
  acc = (acc + (residue_56 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001002_213_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001002_213_2 st_1 = {0};
  struct MatrixBlock_R001002_213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int offset_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_56_1)
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

  switch (offset_56_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_56_1 == offset_56_2);
}

int fn_R001002_213_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001002_213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int offset_56 = (aux + st.buffer[1]) & 3;
  switch (offset_56)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001002_213_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001002_213_1 st_1 = {0};
  struct FilterState_R001002_213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int cursor_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_22_1 > 12)
  {
    acc_1 = ((acc_1 + (cursor_22_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_22_2 > 12)
  {
    acc_2 = ((acc_2 + (cursor_22_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_22_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_83_1) & 63;
  aux_2 = (aux_2 + metric_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_16_1 = 0;
  int damping_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_16_1 = ((damping_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_16_2 = ((damping_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_16_1) & 127;
    acc_2 = (acc_2 + damping_16_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_22_1 == cursor_22_2);
  assert(metric_83_1 == metric_83_2);
  assert(damping_16_1 == damping_16_2);
}

int fn_R001002_213_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001002_213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int cursor_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_22 > 12)
  {
    acc = ((acc + (cursor_22 * 2)) + 5) & 127;
    aux ^= cursor_22 & 15;
  }
  else
  {
    acc = ((acc - cursor_22) + 11) & 127;
    aux += 3;
  }
  int metric_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_83) & 63;
  acc ^= aux;
  int damping_16 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_16 = ((damping_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_16) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001002_213_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001002_213_1 st_1 = {0};
  struct FilterState_R001002_213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_40_1 = local_arr_1[aux_1 % 3];
  int sample_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_40_2 * 2)) & 127;
  int cursor_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_31_1)
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

  switch (cursor_31_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_53_1 > 13)
  {
    acc_1 = ((acc_1 + (accumulator_53_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_53_2 > 13)
  {
    acc_2 = ((acc_2 + (accumulator_53_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_53_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_40_1 == sample_40_2);
  assert(cursor_31_1 == cursor_31_2);
  assert(accumulator_53_1 == accumulator_53_2);
}

int fn_R001002_213_17(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001002_213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int sample_40 = local_arr[aux % 3];
  acc = (acc + (sample_40 * 2)) & 127;
  int cursor_31 = (aux + st.buffer[1]) & 3;
  switch (cursor_31)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_53 > 13)
  {
    acc = ((acc + (accumulator_53 * 2)) + 5) & 127;
    aux ^= accumulator_53 & 15;
  }
  else
  {
    acc = ((acc - accumulator_53) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001002_213_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001002_213_0 st_1 = {0};
  struct CipherContext_R001002_213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int window_27_1 = 0;
  int window_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_27_1 = ((window_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_27_2 = ((window_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_27_1) & 127;
    acc_2 = (acc_2 + window_27_2) & 127;
  }

  int pivot_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_65_1 > 22)
  {
    acc_1 = ((acc_1 + (pivot_65_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_65_2 > 22)
  {
    acc_2 = ((acc_2 + (pivot_65_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_65_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_27_1 == window_27_2);
  assert(pivot_65_1 == pivot_65_2);
}

int fn_R001002_213_18(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001002_213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int window_27 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_27 = ((window_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_27) & 127;
  }

  int pivot_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_65 > 22)
  {
    acc = ((acc + (pivot_65 * 2)) + 5) & 127;
    aux ^= pivot_65 & 15;
  }
  else
  {
    acc = ((acc - pivot_65) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001002_213_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001002_213_3 st_1 = {0};
  struct EventLog_R001002_213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int coefficient_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_50_1 > 32)
  {
    acc_1 = ((acc_1 + (coefficient_50_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_50_2 > 32)
  {
    acc_2 = ((acc_2 + (coefficient_50_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_85_1 = 0;
  int metric_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_85_1 = ((metric_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_85_2 = ((metric_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_85_1) & 127;
    acc_2 = (acc_2 + metric_85_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_50_1 == coefficient_50_2);
  assert(metric_85_1 == metric_85_2);
}

int fn_R001002_213_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001002_213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int coefficient_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_50 > 32)
  {
    acc = ((acc + (coefficient_50 * 2)) + 5) & 127;
    aux ^= coefficient_50 & 15;
  }
  else
  {
    acc = ((acc - coefficient_50) + 11) & 127;
    aux += 3;
  }
  int metric_85 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_85 = ((metric_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_85) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001002_213_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001002_213_1 st_1 = {0};
  struct FilterState_R001002_213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int vector_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_67_1 > 36)
  {
    acc_1 = ((acc_1 + (vector_67_1 * 2)) + 5) & 127;
    aux_1 ^= vector_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_67_2 > 36)
  {
    acc_2 = ((acc_2 + (vector_67_2 * 2)) + 5) & 127;
    aux_2 ^= vector_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_67_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_44_1 = 0;
  int offset_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_44_1 = ((offset_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_44_2 = ((offset_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_44_1) & 127;
    acc_2 = (acc_2 + offset_44_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_67_1 == vector_67_2);
  assert(offset_44_1 == offset_44_2);
}

int fn_R001002_213_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001002_213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int vector_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_67 > 36)
  {
    acc = ((acc + (vector_67 * 2)) + 5) & 127;
    aux ^= vector_67 & 15;
  }
  else
  {
    acc = ((acc - vector_67) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_44 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_44 = ((offset_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_44) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001002_213_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001002_213_1 st_1 = {0};
  struct FilterState_R001002_213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_23_1 = local_arr_1[aux_1 % 3];
  int accumulator_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_23_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_79_1 = 0;
  int quotient_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_79_1 = ((quotient_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_79_2 = ((quotient_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_79_1) & 127;
    acc_2 = (acc_2 + quotient_79_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_23_1 == accumulator_23_2);
  assert(quotient_79_1 == quotient_79_2);
}

int fn_R001002_213_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001002_213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int accumulator_23 = local_arr[aux % 3];
  acc = (acc + (accumulator_23 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_79 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_79 = ((quotient_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_79) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001002_0_1;
  int sec_r001002_0_2;
  int sec_r001002_1_1;
  int sec_r001002_1_2;
  int sec_r001002_2_1;
  int sec_r001002_2_2;
  int sec_r001002_3_1;
  int sec_r001002_3_2;
  int sec_r001002_4_1;
  int sec_r001002_4_2;
  int sec_r001002_5_1;
  int sec_r001002_5_2;
  int sec_r001002_6_1;
  int sec_r001002_6_2;
  int sec_r001002_7_1;
  int sec_r001002_7_2;
  int sec_r001002_8_1;
  int sec_r001002_8_2;
  int sec_r001002_9_1;
  int sec_r001002_9_2;
  int sec_r001002_10_1;
  int sec_r001002_10_2;
  int sec_r001002_11_1;
  int sec_r001002_11_2;
  int sec_r001002_12_1;
  int sec_r001002_12_2;
  int sec_r001002_13_1;
  int sec_r001002_13_2;
  int sec_r001002_14_1;
  int sec_r001002_14_2;
  int sec_r001002_15_1;
  int sec_r001002_15_2;
  int sec_r001002_16_1;
  int sec_r001002_16_2;
  int sec_r001002_17_1;
  int sec_r001002_17_2;
  int sec_r001002_18_1;
  int sec_r001002_18_2;
  int sec_r001002_19_1;
  int sec_r001002_19_2;
  int pub_r001002_0_1;
  int pub_r001002_0_2;
  int pub_r001002_1_1;
  int pub_r001002_1_2;
  int pub_r001002_2_1;
  int pub_r001002_2_2;
  int pub_r001002_3_1;
  int pub_r001002_3_2;
  int pub_r001002_4_1;
  int pub_r001002_4_2;
  int pub_r001002_5_1;
  int pub_r001002_5_2;
  int pub_r001002_6_1;
  int pub_r001002_6_2;
  int pub_r001002_7_1;
  int pub_r001002_7_2;
  int pub_r001002_8_1;
  int pub_r001002_8_2;
  int pub_r001002_9_1;
  int pub_r001002_9_2;
  int pub_r001002_10_1;
  int pub_r001002_10_2;
  int pub_r001002_11_1;
  int pub_r001002_11_2;
  int pub_r001002_12_1;
  int pub_r001002_12_2;
  int pub_r001002_13_1;
  int pub_r001002_13_2;
  int pub_r001002_14_1;
  int pub_r001002_14_2;
  int pub_r001002_15_1;
  int pub_r001002_15_2;
  int pub_r001002_16_1;
  int pub_r001002_16_2;
  int pub_r001002_17_1;
  int pub_r001002_17_2;
  int pub_r001002_18_1;
  int pub_r001002_18_2;
  int pub_r001002_19_1;
  int pub_r001002_19_2;
  int pub_r001002_20_1;
  int pub_r001002_20_2;
  int pub_r001002_21_1;
  int pub_r001002_21_2;
  int pub_r001002_22_1;
  int pub_r001002_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001002_0_1 >= (-100)) && (pub_r001002_0_1 <= 100));
  __CPROVER_assume((pub_r001002_0_2 >= (-100)) && (pub_r001002_0_2 <= 100));
  __CPROVER_assume((pub_r001002_1_1 >= (-100)) && (pub_r001002_1_1 <= 100));
  __CPROVER_assume((pub_r001002_1_2 >= (-100)) && (pub_r001002_1_2 <= 100));
  __CPROVER_assume((pub_r001002_2_1 >= (-100)) && (pub_r001002_2_1 <= 100));
  __CPROVER_assume((pub_r001002_2_2 >= (-100)) && (pub_r001002_2_2 <= 100));
  __CPROVER_assume((pub_r001002_3_1 >= (-100)) && (pub_r001002_3_1 <= 100));
  __CPROVER_assume((pub_r001002_3_2 >= (-100)) && (pub_r001002_3_2 <= 100));
  __CPROVER_assume((pub_r001002_4_1 >= (-100)) && (pub_r001002_4_1 <= 100));
  __CPROVER_assume((pub_r001002_4_2 >= (-100)) && (pub_r001002_4_2 <= 100));
  __CPROVER_assume((pub_r001002_5_1 >= (-100)) && (pub_r001002_5_1 <= 100));
  __CPROVER_assume((pub_r001002_5_2 >= (-100)) && (pub_r001002_5_2 <= 100));
  __CPROVER_assume((pub_r001002_6_1 >= (-100)) && (pub_r001002_6_1 <= 100));
  __CPROVER_assume((pub_r001002_6_2 >= (-100)) && (pub_r001002_6_2 <= 100));
  __CPROVER_assume((pub_r001002_7_1 >= (-100)) && (pub_r001002_7_1 <= 100));
  __CPROVER_assume((pub_r001002_7_2 >= (-100)) && (pub_r001002_7_2 <= 100));
  __CPROVER_assume((pub_r001002_8_1 >= (-100)) && (pub_r001002_8_1 <= 100));
  __CPROVER_assume((pub_r001002_8_2 >= (-100)) && (pub_r001002_8_2 <= 100));
  __CPROVER_assume((pub_r001002_9_1 >= (-100)) && (pub_r001002_9_1 <= 100));
  __CPROVER_assume((pub_r001002_9_2 >= (-100)) && (pub_r001002_9_2 <= 100));
  __CPROVER_assume((pub_r001002_10_1 >= (-100)) && (pub_r001002_10_1 <= 100));
  __CPROVER_assume((pub_r001002_10_2 >= (-100)) && (pub_r001002_10_2 <= 100));
  __CPROVER_assume((pub_r001002_11_1 >= (-100)) && (pub_r001002_11_1 <= 100));
  __CPROVER_assume((pub_r001002_11_2 >= (-100)) && (pub_r001002_11_2 <= 100));
  __CPROVER_assume((pub_r001002_12_1 >= (-100)) && (pub_r001002_12_1 <= 100));
  __CPROVER_assume((pub_r001002_12_2 >= (-100)) && (pub_r001002_12_2 <= 100));
  __CPROVER_assume((pub_r001002_13_1 >= (-100)) && (pub_r001002_13_1 <= 100));
  __CPROVER_assume((pub_r001002_13_2 >= (-100)) && (pub_r001002_13_2 <= 100));
  __CPROVER_assume((pub_r001002_14_1 >= (-100)) && (pub_r001002_14_1 <= 100));
  __CPROVER_assume((pub_r001002_14_2 >= (-100)) && (pub_r001002_14_2 <= 100));
  __CPROVER_assume((pub_r001002_15_1 >= (-100)) && (pub_r001002_15_1 <= 100));
  __CPROVER_assume((pub_r001002_15_2 >= (-100)) && (pub_r001002_15_2 <= 100));
  __CPROVER_assume((pub_r001002_16_1 >= (-100)) && (pub_r001002_16_1 <= 100));
  __CPROVER_assume((pub_r001002_16_2 >= (-100)) && (pub_r001002_16_2 <= 100));
  __CPROVER_assume((pub_r001002_17_1 >= (-100)) && (pub_r001002_17_1 <= 100));
  __CPROVER_assume((pub_r001002_17_2 >= (-100)) && (pub_r001002_17_2 <= 100));
  __CPROVER_assume((pub_r001002_18_1 >= (-100)) && (pub_r001002_18_1 <= 100));
  __CPROVER_assume((pub_r001002_18_2 >= (-100)) && (pub_r001002_18_2 <= 100));
  __CPROVER_assume((pub_r001002_19_1 >= (-100)) && (pub_r001002_19_1 <= 100));
  __CPROVER_assume((pub_r001002_19_2 >= (-100)) && (pub_r001002_19_2 <= 100));
  __CPROVER_assume((pub_r001002_20_1 >= (-100)) && (pub_r001002_20_1 <= 100));
  __CPROVER_assume((pub_r001002_20_2 >= (-100)) && (pub_r001002_20_2 <= 100));
  __CPROVER_assume((pub_r001002_21_1 >= (-100)) && (pub_r001002_21_1 <= 100));
  __CPROVER_assume((pub_r001002_21_2 >= (-100)) && (pub_r001002_21_2 <= 100));
  __CPROVER_assume((pub_r001002_22_1 >= (-100)) && (pub_r001002_22_1 <= 100));
  __CPROVER_assume((pub_r001002_22_2 >= (-100)) && (pub_r001002_22_2 <= 100));
  __CPROVER_assume((sec_r001002_0_1 >= 0) && (sec_r001002_0_1 <= 255));
  __CPROVER_assume((sec_r001002_0_2 >= 0) && (sec_r001002_0_2 <= 255));
  __CPROVER_assume((sec_r001002_1_1 >= 0) && (sec_r001002_1_1 <= 255));
  __CPROVER_assume((sec_r001002_1_2 >= 0) && (sec_r001002_1_2 <= 255));
  __CPROVER_assume((sec_r001002_2_1 >= 0) && (sec_r001002_2_1 <= 255));
  __CPROVER_assume((sec_r001002_2_2 >= 0) && (sec_r001002_2_2 <= 255));
  __CPROVER_assume((sec_r001002_3_1 >= 0) && (sec_r001002_3_1 <= 255));
  __CPROVER_assume((sec_r001002_3_2 >= 0) && (sec_r001002_3_2 <= 255));
  __CPROVER_assume((sec_r001002_4_1 >= 0) && (sec_r001002_4_1 <= 255));
  __CPROVER_assume((sec_r001002_4_2 >= 0) && (sec_r001002_4_2 <= 255));
  __CPROVER_assume((sec_r001002_5_1 >= 0) && (sec_r001002_5_1 <= 255));
  __CPROVER_assume((sec_r001002_5_2 >= 0) && (sec_r001002_5_2 <= 255));
  __CPROVER_assume((sec_r001002_6_1 >= 0) && (sec_r001002_6_1 <= 255));
  __CPROVER_assume((sec_r001002_6_2 >= 0) && (sec_r001002_6_2 <= 255));
  __CPROVER_assume((sec_r001002_7_1 >= 0) && (sec_r001002_7_1 <= 255));
  __CPROVER_assume((sec_r001002_7_2 >= 0) && (sec_r001002_7_2 <= 255));
  __CPROVER_assume((sec_r001002_8_1 >= 0) && (sec_r001002_8_1 <= 255));
  __CPROVER_assume((sec_r001002_8_2 >= 0) && (sec_r001002_8_2 <= 255));
  __CPROVER_assume((sec_r001002_9_1 >= 0) && (sec_r001002_9_1 <= 255));
  __CPROVER_assume((sec_r001002_9_2 >= 0) && (sec_r001002_9_2 <= 255));
  __CPROVER_assume((sec_r001002_10_1 >= 0) && (sec_r001002_10_1 <= 255));
  __CPROVER_assume((sec_r001002_10_2 >= 0) && (sec_r001002_10_2 <= 255));
  __CPROVER_assume((sec_r001002_11_1 >= 0) && (sec_r001002_11_1 <= 255));
  __CPROVER_assume((sec_r001002_11_2 >= 0) && (sec_r001002_11_2 <= 255));
  __CPROVER_assume((sec_r001002_12_1 >= 0) && (sec_r001002_12_1 <= 255));
  __CPROVER_assume((sec_r001002_12_2 >= 0) && (sec_r001002_12_2 <= 255));
  __CPROVER_assume((sec_r001002_13_1 >= 0) && (sec_r001002_13_1 <= 255));
  __CPROVER_assume((sec_r001002_13_2 >= 0) && (sec_r001002_13_2 <= 255));
  __CPROVER_assume((sec_r001002_14_1 >= 0) && (sec_r001002_14_1 <= 255));
  __CPROVER_assume((sec_r001002_14_2 >= 0) && (sec_r001002_14_2 <= 255));
  __CPROVER_assume((sec_r001002_15_1 >= 0) && (sec_r001002_15_1 <= 255));
  __CPROVER_assume((sec_r001002_15_2 >= 0) && (sec_r001002_15_2 <= 255));
  __CPROVER_assume((sec_r001002_16_1 >= 0) && (sec_r001002_16_1 <= 255));
  __CPROVER_assume((sec_r001002_16_2 >= 0) && (sec_r001002_16_2 <= 255));
  __CPROVER_assume((sec_r001002_17_1 >= 0) && (sec_r001002_17_1 <= 255));
  __CPROVER_assume((sec_r001002_17_2 >= 0) && (sec_r001002_17_2 <= 255));
  __CPROVER_assume((sec_r001002_18_1 >= 0) && (sec_r001002_18_1 <= 255));
  __CPROVER_assume((sec_r001002_18_2 >= 0) && (sec_r001002_18_2 <= 255));
  __CPROVER_assume((sec_r001002_19_1 >= 0) && (sec_r001002_19_1 <= 255));
  __CPROVER_assume((sec_r001002_19_2 >= 0) && (sec_r001002_19_2 <= 255));
  struct CipherContext_R001002_213_0 st_var_0_1 = {0};
  struct CipherContext_R001002_213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001002_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001002_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001002_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001002_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001002_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001002_0_2 + 7) & 15;
  struct FilterState_R001002_213_1 st_var_1_1 = {0};
  struct FilterState_R001002_213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001002_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001002_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001002_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001002_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001002_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001002_0_2 + 9) & 15;
  struct MatrixBlock_R001002_213_2 st_var_2_1 = {0};
  struct MatrixBlock_R001002_213_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001002_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001002_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001002_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001002_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001002_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001002_0_2 + 11) & 15;
  struct EventLog_R001002_213_3 st_var_3_1 = {0};
  struct EventLog_R001002_213_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001002_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001002_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001002_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001002_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001002_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001002_0_2 + 13) & 15;
  union TelemetryField_R001002_213_0 u_var_1;
  union TelemetryField_R001002_213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001002_213_0(sec_r001002_0_1, pub_r001002_1_1);
  int helper_flow_0_2 = fn_R001002_213_0(sec_r001002_0_2, pub_r001002_1_2);
  fn_R001002_213_0_2(sec_r001002_0_1, pub_r001002_1_1, sec_r001002_0_2, pub_r001002_1_2);
  int helper_flow_1_1 = fn_R001002_213_1(sec_r001002_1_1, pub_r001002_2_1, pub_r001002_3_1, pub_r001002_4_1, pub_r001002_5_1);
  int helper_flow_1_2 = fn_R001002_213_1(sec_r001002_1_2, pub_r001002_2_2, pub_r001002_3_2, pub_r001002_4_2, pub_r001002_5_2);
  fn_R001002_213_1_2(sec_r001002_1_1, pub_r001002_2_1, pub_r001002_3_1, pub_r001002_4_1, pub_r001002_5_1, sec_r001002_1_2, pub_r001002_2_2, pub_r001002_3_2, pub_r001002_4_2, pub_r001002_5_2);
  int helper_flow_2_1 = fn_R001002_213_2(sec_r001002_2_1, sec_r001002_3_1);
  int helper_flow_2_2 = fn_R001002_213_2(sec_r001002_2_2, sec_r001002_3_2);
  fn_R001002_213_2_2(sec_r001002_2_1, sec_r001002_3_1, sec_r001002_2_2, sec_r001002_3_2);
  int helper_flow_3_1 = fn_R001002_213_3(sec_r001002_3_1, sec_r001002_4_1, pub_r001002_5_1, pub_r001002_6_1, pub_r001002_7_1);
  int helper_flow_3_2 = fn_R001002_213_3(sec_r001002_3_2, sec_r001002_4_2, pub_r001002_5_2, pub_r001002_6_2, pub_r001002_7_2);
  fn_R001002_213_3_2(sec_r001002_3_1, sec_r001002_4_1, pub_r001002_5_1, pub_r001002_6_1, pub_r001002_7_1, sec_r001002_3_2, sec_r001002_4_2, pub_r001002_5_2, pub_r001002_6_2, pub_r001002_7_2);
  int stage_v_0_1 = ((pub_r001002_18_1 * 2) + 34) & 63;
  int stage_v_0_2 = ((pub_r001002_18_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001002_16_1 * 2) + 50) & 63;
  int stage_v_1_2 = ((pub_r001002_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001002_21_1 * 2) + 35) & 63;
  int stage_v_2_2 = ((pub_r001002_21_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (((sec_r001002_19_1 * 3) + pub_r001002_13_1) + 19) & 127;
  int stage_v_3_2 = (((sec_r001002_19_2 * 3) + pub_r001002_13_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = ((pub_r001002_5_1 * 2) + 26) & 63;
  int stage_v_4_2 = ((pub_r001002_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001002_13_1 * 2) + 45) & 63;
  int stage_v_5_2 = ((pub_r001002_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001002_7_1 * 2) + 39) & 63;
  int stage_v_6_2 = ((pub_r001002_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001002_5_1 * 2) + 19) & 63;
  int stage_v_7_2 = ((pub_r001002_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001002_5_1 * 2) + 26) & 63;
  int stage_v_8_2 = ((pub_r001002_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (((sec_r001002_6_1 * 3) + pub_r001002_21_1) + 3) & 127;
  int stage_v_9_2 = (((sec_r001002_6_2 * 3) + pub_r001002_21_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = ((pub_r001002_6_1 * 2) + 41) & 63;
  int stage_v_10_2 = ((pub_r001002_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001002_21_1 * 2) + 5) & 63;
  int stage_v_11_2 = ((pub_r001002_21_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001002_12_1 * 2) + 24) & 63;
  int stage_v_12_2 = ((pub_r001002_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (((stage_v_3_1 * 3) + pub_r001002_3_1) + 32) & 127;
  int stage_v_13_2 = (((stage_v_3_2 * 3) + pub_r001002_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = (((sec_r001002_18_1 * 3) + pub_r001002_17_1) + 6) & 127;
  int stage_v_14_2 = (((sec_r001002_18_2 * 3) + pub_r001002_17_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = ((pub_r001002_5_1 * 2) + 17) & 63;
  int stage_v_15_2 = ((pub_r001002_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001002_18_1 * 2) + 18) & 63;
  int stage_v_16_2 = ((pub_r001002_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001002_14_1 * 2) + 40) & 63;
  int stage_v_17_2 = ((pub_r001002_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001002_7_1 * 2) + 39) & 63;
  int stage_v_18_2 = ((pub_r001002_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (((sec_r001002_4_1 * 3) + pub_r001002_7_1) + 36) & 127;
  int stage_v_19_2 = (((sec_r001002_4_2 * 3) + pub_r001002_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = ((pub_r001002_6_1 * 2) + 50) & 63;
  int stage_v_20_2 = ((pub_r001002_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (((stage_v_9_1 * 3) + pub_r001002_3_1) + 19) & 127;
  int stage_v_21_2 = (((stage_v_9_2 * 3) + pub_r001002_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = ((pub_r001002_21_1 * 2) + 45) & 63;
  int stage_v_22_2 = ((pub_r001002_21_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001002_4_1 * 2) + 34) & 63;
  int stage_v_23_2 = ((pub_r001002_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001002_21_1 * 2) + 48) & 63;
  int stage_v_24_2 = ((pub_r001002_21_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001002_4_1 * 2) + 7) & 63;
  int stage_v_25_2 = ((pub_r001002_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001002_1_1 * 2) + 21) & 63;
  int stage_v_26_2 = ((pub_r001002_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001002_13_1 * 2) + 39) & 63;
  int stage_v_27_2 = ((pub_r001002_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((sec_r001002_6_1 * 3) + pub_r001002_1_1) + 18) & 127;
  int stage_v_28_2 = (((sec_r001002_6_2 * 3) + pub_r001002_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = (((sec_r001002_9_1 * 3) + pub_r001002_7_1) + 41) & 127;
  int stage_v_29_2 = (((sec_r001002_9_2 * 3) + pub_r001002_7_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = ((pub_r001002_21_1 * 2) + 21) & 63;
  int stage_v_30_2 = ((pub_r001002_21_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001002_4_1 * 2) + 37) & 63;
  int stage_v_31_2 = ((pub_r001002_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001002_3_1 * 2) + 19) & 63;
  int stage_v_32_2 = ((pub_r001002_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001002_0_1 * 2) + 35) & 63;
  int stage_v_33_2 = ((pub_r001002_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001002_14_1 * 2) + 19) & 63;
  int stage_v_34_2 = ((pub_r001002_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001002_8_1 * 2) + 10) & 63;
  int stage_v_35_2 = ((pub_r001002_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001002_2_1 * 2) + 24) & 63;
  int stage_v_36_2 = ((pub_r001002_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (((sec_r001002_2_1 * 3) + pub_r001002_21_1) + 27) & 127;
  int stage_v_37_2 = (((sec_r001002_2_2 * 3) + pub_r001002_21_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = (((sec_r001002_16_1 * 3) + pub_r001002_8_1) + 39) & 127;
  int stage_v_38_2 = (((sec_r001002_16_2 * 3) + pub_r001002_8_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = (((stage_v_13_1 * 3) + pub_r001002_12_1) + 11) & 127;
  int stage_v_39_2 = (((stage_v_13_2 * 3) + pub_r001002_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = ((pub_r001002_12_1 * 2) + 10) & 63;
  int stage_v_40_2 = ((pub_r001002_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = (((sec_r001002_1_1 * 3) + pub_r001002_19_1) + 6) & 127;
  int stage_v_41_2 = (((sec_r001002_1_2 * 3) + pub_r001002_19_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = ((pub_r001002_19_1 * 2) + 16) & 63;
  int stage_v_42_2 = ((pub_r001002_19_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001002_0_1 * 2) + 32) & 63;
  int stage_v_43_2 = ((pub_r001002_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (((sec_r001002_0_1 * 3) + pub_r001002_12_1) + 42) & 127;
  int stage_v_44_2 = (((sec_r001002_0_2 * 3) + pub_r001002_12_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = ((pub_r001002_6_1 * 2) + 37) & 63;
  int stage_v_45_2 = ((pub_r001002_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((stage_v_13_1 * 3) + pub_r001002_17_1) + 6) & 127;
  int stage_v_46_2 = (((stage_v_13_2 * 3) + pub_r001002_17_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = (((sec_r001002_6_1 * 3) + pub_r001002_3_1) + 18) & 127;
  int stage_v_47_2 = (((sec_r001002_6_2 * 3) + pub_r001002_3_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = ((pub_r001002_2_1 * 2) + 14) & 63;
  int stage_v_48_2 = ((pub_r001002_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((helper_flow_2_1 * 3) + pub_r001002_13_1) + 9) & 127;
  int stage_v_49_2 = (((helper_flow_2_2 * 3) + pub_r001002_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = ((pub_r001002_10_1 * 2) + 9) & 63;
  int stage_v_50_2 = ((pub_r001002_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001002_0_1 * 2) + 38) & 63;
  int stage_v_51_2 = ((pub_r001002_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((stage_v_14_1 * 3) + pub_r001002_8_1) + 41) & 127;
  int stage_v_52_2 = (((stage_v_14_2 * 3) + pub_r001002_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = ((pub_r001002_12_1 * 2) + 6) & 63;
  int stage_v_53_2 = ((pub_r001002_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (((sec_r001002_16_1 * 3) + pub_r001002_2_1) + 22) & 127;
  int stage_v_54_2 = (((sec_r001002_16_2 * 3) + pub_r001002_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = (((stage_v_44_1 * 3) + pub_r001002_9_1) + 26) & 127;
  int stage_v_55_2 = (((stage_v_44_2 * 3) + pub_r001002_9_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = ((pub_r001002_3_1 * 2) + 12) & 63;
  int stage_v_56_2 = ((pub_r001002_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (((stage_v_49_1 * 3) + pub_r001002_22_1) + 29) & 127;
  int stage_v_57_2 = (((stage_v_49_2 * 3) + pub_r001002_22_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = (((sec_r001002_3_1 * 3) + pub_r001002_5_1) + 19) & 127;
  int stage_v_58_2 = (((sec_r001002_3_2 * 3) + pub_r001002_5_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = ((pub_r001002_9_1 * 2) + 10) & 63;
  int stage_v_59_2 = ((pub_r001002_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((sec_r001002_3_1 * 3) + pub_r001002_2_1) + 13) & 127;
  int stage_v_60_2 = (((sec_r001002_3_2 * 3) + pub_r001002_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = (((sec_r001002_16_1 * 3) + pub_r001002_16_1) + 25) & 127;
  int stage_v_61_2 = (((sec_r001002_16_2 * 3) + pub_r001002_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001002_8_1 * 2) + 6) & 63;
  int stage_v_62_2 = ((pub_r001002_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001002_15_1 * 2) + 35) & 63;
  int stage_v_63_2 = ((pub_r001002_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001002_8_1 * 2) + 34) & 63;
  int stage_v_64_2 = ((pub_r001002_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001002_6_1 * 2) + 18) & 63;
  int stage_v_65_2 = ((pub_r001002_6_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((sec_r001002_13_1 * 3) + pub_r001002_10_1) + 43) & 127;
  int stage_v_66_2 = (((sec_r001002_13_2 * 3) + pub_r001002_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = (((stage_v_41_1 * 3) + pub_r001002_1_1) + 42) & 127;
  int stage_v_67_2 = (((stage_v_41_2 * 3) + pub_r001002_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = ((pub_r001002_8_1 * 2) + 16) & 63;
  int stage_v_68_2 = ((pub_r001002_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001002_20_1 * 2) + 9) & 63;
  int stage_v_69_2 = ((pub_r001002_20_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((helper_flow_2_1 * 3) + pub_r001002_21_1) + 19) & 127;
  int stage_v_70_2 = (((helper_flow_2_2 * 3) + pub_r001002_21_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = ((pub_r001002_22_1 * 2) + 14) & 63;
  int stage_v_71_2 = ((pub_r001002_22_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001002_14_1 * 2) + 10) & 63;
  int stage_v_72_2 = ((pub_r001002_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((stage_v_3_1 * 3) + pub_r001002_21_1) + 21) & 127;
  int stage_v_73_2 = (((stage_v_3_2 * 3) + pub_r001002_21_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = ((pub_r001002_14_1 * 2) + 29) & 63;
  int stage_v_74_2 = ((pub_r001002_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (((sec_r001002_11_1 * 3) + pub_r001002_9_1) + 40) & 127;
  int stage_v_75_2 = (((sec_r001002_11_2 * 3) + pub_r001002_9_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = ((pub_r001002_16_1 * 2) + 41) & 63;
  int stage_v_76_2 = ((pub_r001002_16_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((sec_r001002_4_1 * 3) + pub_r001002_5_1) + 30) & 127;
  int stage_v_77_2 = (((sec_r001002_4_2 * 3) + pub_r001002_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = (((sec_r001002_14_1 * 3) + pub_r001002_8_1) + 36) & 127;
  int stage_v_78_2 = (((sec_r001002_14_2 * 3) + pub_r001002_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = ((pub_r001002_11_1 * 2) + 38) & 63;
  int stage_v_79_2 = ((pub_r001002_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (((sec_r001002_8_1 * 3) + pub_r001002_20_1) + 32) & 127;
  int stage_v_80_2 = (((sec_r001002_8_2 * 3) + pub_r001002_20_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_80_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_80_2 * 2)) & 255;
  int stage_v_81_1 = ((pub_r001002_21_1 * 2) + 17) & 63;
  int stage_v_81_2 = ((pub_r001002_21_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001002_13_1 * 2) + 40) & 63;
  int stage_v_82_2 = ((pub_r001002_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001002_9_1 * 2) + 27) & 63;
  int stage_v_83_2 = ((pub_r001002_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001002_18_1 * 2) + 5) & 63;
  int stage_v_84_2 = ((pub_r001002_18_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001002_9_1 * 2) + 17) & 63;
  int stage_v_85_2 = ((pub_r001002_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001002_0_1 * 2) + 38) & 63;
  int stage_v_86_2 = ((pub_r001002_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001002_10_1 * 2) + 29) & 63;
  int stage_v_87_2 = ((pub_r001002_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001002_10_1 * 2) + 19) & 63;
  int stage_v_88_2 = ((pub_r001002_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (((stage_v_9_1 * 3) + pub_r001002_18_1) + 10) & 127;
  int stage_v_89_2 = (((stage_v_9_2 * 3) + pub_r001002_18_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = ((pub_r001002_19_1 * 2) + 38) & 63;
  int stage_v_90_2 = ((pub_r001002_19_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001002_19_1 * 2) + 9) & 63;
  int stage_v_91_2 = ((pub_r001002_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001002_6_1 * 2) + 22) & 63;
  int stage_v_92_2 = ((pub_r001002_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = (((stage_v_67_1 * 3) + pub_r001002_15_1) + 6) & 127;
  int stage_v_93_2 = (((stage_v_67_2 * 3) + pub_r001002_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = ((pub_r001002_18_1 * 2) + 25) & 63;
  int stage_v_94_2 = ((pub_r001002_18_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001002_13_1 * 2) + 8) & 63;
  int stage_v_95_2 = ((pub_r001002_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((sec_r001002_2_1 * 3) + pub_r001002_13_1) + 43) & 127;
  int stage_v_96_2 = (((sec_r001002_2_2 * 3) + pub_r001002_13_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = ((pub_r001002_18_1 * 2) + 34) & 63;
  int stage_v_97_2 = ((pub_r001002_18_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001002_18_1 * 2) + 8) & 63;
  int stage_v_98_2 = ((pub_r001002_18_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001002_18_1 * 2) + 48) & 63;
  int stage_v_99_2 = ((pub_r001002_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (((stage_v_66_1 * 3) + pub_r001002_0_1) + 22) & 127;
  int stage_v_100_2 = (((stage_v_66_2 * 3) + pub_r001002_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_100_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_100_2 * 2)) & 255;
  int stage_v_101_1 = ((pub_r001002_4_1 * 2) + 31) & 63;
  int stage_v_101_2 = ((pub_r001002_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((sec_r001002_18_1 * 3) + pub_r001002_3_1) + 8) & 127;
  int stage_v_102_2 = (((sec_r001002_18_2 * 3) + pub_r001002_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = (((sec_r001002_0_1 * 3) + pub_r001002_19_1) + 42) & 127;
  int stage_v_103_2 = (((sec_r001002_0_2 * 3) + pub_r001002_19_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = (((stage_v_47_1 * 3) + pub_r001002_11_1) + 45) & 127;
  int stage_v_104_2 = (((stage_v_47_2 * 3) + pub_r001002_11_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = (((sec_r001002_3_1 * 3) + pub_r001002_18_1) + 25) & 127;
  int stage_v_105_2 = (((sec_r001002_3_2 * 3) + pub_r001002_18_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = ((pub_r001002_1_1 * 2) + 29) & 63;
  int stage_v_106_2 = ((pub_r001002_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001002_13_1 * 2) + 45) & 63;
  int stage_v_107_2 = ((pub_r001002_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (((sec_r001002_8_1 * 3) + pub_r001002_5_1) + 40) & 127;
  int stage_v_108_2 = (((sec_r001002_8_2 * 3) + pub_r001002_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = (((stage_v_3_1 * 3) + pub_r001002_19_1) + 35) & 127;
  int stage_v_109_2 = (((stage_v_3_2 * 3) + pub_r001002_19_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = ((pub_r001002_20_1 * 2) + 9) & 63;
  int stage_v_110_2 = ((pub_r001002_20_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (((stage_v_102_1 * 3) + pub_r001002_17_1) + 23) & 127;
  int stage_v_111_2 = (((stage_v_102_2 * 3) + pub_r001002_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = (((sec_r001002_15_1 * 3) + pub_r001002_5_1) + 31) & 127;
  int stage_v_112_2 = (((sec_r001002_15_2 * 3) + pub_r001002_5_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = (((stage_v_73_1 * 3) + pub_r001002_11_1) + 11) & 127;
  int stage_v_113_2 = (((stage_v_73_2 * 3) + pub_r001002_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = ((pub_r001002_0_1 * 2) + 32) & 63;
  int stage_v_114_2 = ((pub_r001002_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001002_13_1 * 2) + 10) & 63;
  int stage_v_115_2 = ((pub_r001002_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001002_14_1 * 2) + 36) & 63;
  int stage_v_116_2 = ((pub_r001002_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001002_5_1 * 2) + 18) & 63;
  int stage_v_117_2 = ((pub_r001002_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001002_11_1 * 2) + 9) & 63;
  int stage_v_118_2 = ((pub_r001002_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001002_1_1 * 2) + 26) & 63;
  int stage_v_119_2 = ((pub_r001002_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001002_20_1 * 2) + 42) & 63;
  int stage_v_120_2 = ((pub_r001002_20_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001002_10_1 * 2) + 40) & 63;
  int stage_v_121_2 = ((pub_r001002_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (((stage_v_109_1 * 3) + pub_r001002_0_1) + 40) & 127;
  int stage_v_122_2 = (((stage_v_109_2 * 3) + pub_r001002_0_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = ((pub_r001002_12_1 * 2) + 40) & 63;
  int stage_v_123_2 = ((pub_r001002_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001002_6_1 * 2) + 49) & 63;
  int stage_v_124_2 = ((pub_r001002_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001002_2_1 * 2) + 39) & 63;
  int stage_v_125_2 = ((pub_r001002_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((sec_r001002_14_1 * 3) + pub_r001002_6_1) + 15) & 127;
  int stage_v_126_2 = (((sec_r001002_14_2 * 3) + pub_r001002_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = (((stage_v_103_1 * 3) + pub_r001002_8_1) + 40) & 127;
  int stage_v_127_2 = (((stage_v_103_2 * 3) + pub_r001002_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = (((stage_v_89_1 * 3) + pub_r001002_18_1) + 23) & 127;
  int stage_v_128_2 = (((stage_v_89_2 * 3) + pub_r001002_18_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = (((stage_v_39_1 * 3) + pub_r001002_14_1) + 16) & 127;
  int stage_v_129_2 = (((stage_v_39_2 * 3) + pub_r001002_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = (((sec_r001002_14_1 * 3) + pub_r001002_5_1) + 17) & 127;
  int stage_v_130_2 = (((sec_r001002_14_2 * 3) + pub_r001002_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = ((pub_r001002_9_1 * 2) + 22) & 63;
  int stage_v_131_2 = ((pub_r001002_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001002_15_1 * 2) + 15) & 63;
  int stage_v_132_2 = ((pub_r001002_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((stage_v_39_1 * 3) + pub_r001002_20_1) + 6) & 127;
  int stage_v_133_2 = (((stage_v_39_2 * 3) + pub_r001002_20_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((sec_r001002_3_1 * 3) + pub_r001002_5_1) + 12) & 127;
  int stage_v_134_2 = (((sec_r001002_3_2 * 3) + pub_r001002_5_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = (((helper_flow_0_1 * 3) + pub_r001002_0_1) + 32) & 127;
  int stage_v_135_2 = (((helper_flow_0_2 * 3) + pub_r001002_0_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = ((pub_r001002_5_1 * 2) + 30) & 63;
  int stage_v_136_2 = ((pub_r001002_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001002_11_1 * 2) + 34) & 63;
  int stage_v_137_2 = ((pub_r001002_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001002_13_1 * 2) + 13) & 63;
  int stage_v_138_2 = ((pub_r001002_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001002_13_1 * 2) + 11) & 63;
  int stage_v_139_2 = ((pub_r001002_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (((sec_r001002_2_1 * 3) + pub_r001002_14_1) + 45) & 127;
  int stage_v_140_2 = (((sec_r001002_2_2 * 3) + pub_r001002_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = ((pub_r001002_0_1 * 2) + 25) & 63;
  int stage_v_141_2 = ((pub_r001002_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (((stage_v_122_1 * 3) + pub_r001002_22_1) + 28) & 127;
  int stage_v_142_2 = (((stage_v_122_2 * 3) + pub_r001002_22_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = ((pub_r001002_5_1 * 2) + 45) & 63;
  int stage_v_143_2 = ((pub_r001002_5_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (((sec_r001002_6_1 * 3) + pub_r001002_16_1) + 14) & 127;
  int stage_v_144_2 = (((sec_r001002_6_2 * 3) + pub_r001002_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = (((sec_r001002_16_1 * 3) + pub_r001002_6_1) + 16) & 127;
  int stage_v_145_2 = (((sec_r001002_16_2 * 3) + pub_r001002_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = (((stage_v_113_1 * 3) + pub_r001002_15_1) + 5) & 127;
  int stage_v_146_2 = (((stage_v_113_2 * 3) + pub_r001002_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_146_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_146_2 * 2)) & 255;
  int stage_v_147_1 = ((pub_r001002_17_1 * 2) + 41) & 63;
  int stage_v_147_2 = ((pub_r001002_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001002_8_1 * 2) + 6) & 63;
  int stage_v_148_2 = ((pub_r001002_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001002_18_1 * 2) + 36) & 63;
  int stage_v_149_2 = ((pub_r001002_18_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (((stage_v_102_1 * 3) + pub_r001002_11_1) + 10) & 127;
  int stage_v_150_2 = (((stage_v_102_2 * 3) + pub_r001002_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = (((sec_r001002_1_1 * 3) + pub_r001002_8_1) + 21) & 127;
  int stage_v_151_2 = (((sec_r001002_1_2 * 3) + pub_r001002_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = (((stage_v_19_1 * 3) + pub_r001002_7_1) + 5) & 127;
  int stage_v_152_2 = (((stage_v_19_2 * 3) + pub_r001002_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = (((stage_v_38_1 * 3) + pub_r001002_11_1) + 29) & 127;
  int stage_v_153_2 = (((stage_v_38_2 * 3) + pub_r001002_11_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = (((stage_v_67_1 * 3) + pub_r001002_9_1) + 27) & 127;
  int stage_v_154_2 = (((stage_v_67_2 * 3) + pub_r001002_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = ((pub_r001002_14_1 * 2) + 21) & 63;
  int stage_v_155_2 = ((pub_r001002_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001002_2_1 * 2) + 17) & 63;
  int stage_v_156_2 = ((pub_r001002_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001002_18_1 * 2) + 24) & 63;
  int stage_v_157_2 = ((pub_r001002_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001002_18_1 * 2) + 34) & 63;
  int stage_v_158_2 = ((pub_r001002_18_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001002_15_1 * 2) + 5) & 63;
  int stage_v_159_2 = ((pub_r001002_15_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = (((stage_v_47_1 * 3) + pub_r001002_11_1) + 35) & 127;
  int stage_v_160_2 = (((stage_v_47_2 * 3) + pub_r001002_11_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = (((stage_v_70_1 * 3) + pub_r001002_12_1) + 30) & 127;
  int stage_v_161_2 = (((stage_v_70_2 * 3) + pub_r001002_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = ((pub_r001002_8_1 * 2) + 20) & 63;
  int stage_v_162_2 = ((pub_r001002_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001002_10_1 * 2) + 8) & 63;
  int stage_v_163_2 = ((pub_r001002_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001002_14_1 * 2) + 39) & 63;
  int stage_v_164_2 = ((pub_r001002_14_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001002_12_1 * 2) + 17) & 63;
  int stage_v_165_2 = ((pub_r001002_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001002_21_1 * 2) + 50) & 63;
  int stage_v_166_2 = ((pub_r001002_21_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001002_2_1 * 2) + 48) & 63;
  int stage_v_167_2 = ((pub_r001002_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = (((stage_v_70_1 * 3) + pub_r001002_10_1) + 18) & 127;
  int stage_v_168_2 = (((stage_v_70_2 * 3) + pub_r001002_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = ((pub_r001002_18_1 * 2) + 6) & 63;
  int stage_v_169_2 = ((pub_r001002_18_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (((stage_v_39_1 * 3) + pub_r001002_0_1) + 34) & 127;
  int stage_v_170_2 = (((stage_v_39_2 * 3) + pub_r001002_0_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = ((pub_r001002_14_1 * 2) + 30) & 63;
  int stage_v_171_2 = ((pub_r001002_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((sec_r001002_2_1 * 3) + pub_r001002_10_1) + 37) & 127;
  int stage_v_172_2 = (((sec_r001002_2_2 * 3) + pub_r001002_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = ((pub_r001002_10_1 * 2) + 24) & 63;
  int stage_v_173_2 = ((pub_r001002_10_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (((stage_v_38_1 * 3) + pub_r001002_20_1) + 33) & 127;
  int stage_v_174_2 = (((stage_v_38_2 * 3) + pub_r001002_20_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = ((pub_r001002_0_1 * 2) + 7) & 63;
  int stage_v_175_2 = ((pub_r001002_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001002_7_1 * 2) + 23) & 63;
  int stage_v_176_2 = ((pub_r001002_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001002_19_1 * 2) + 42) & 63;
  int stage_v_177_2 = ((pub_r001002_19_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001002_19_1 * 2) + 43) & 63;
  int stage_v_178_2 = ((pub_r001002_19_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001002_3_1 * 2) + 24) & 63;
  int stage_v_179_2 = ((pub_r001002_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((stage_v_58_1 * 3) + pub_r001002_3_1) + 18) & 127;
  int stage_v_180_2 = (((stage_v_58_2 * 3) + pub_r001002_3_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = ((pub_r001002_12_1 * 2) + 8) & 63;
  int stage_v_181_2 = ((pub_r001002_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001002_15_1 * 2) + 9) & 63;
  int stage_v_182_2 = ((pub_r001002_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001002_2_1 * 2) + 33) & 63;
  int stage_v_183_2 = ((pub_r001002_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001002_17_1 * 2) + 9) & 63;
  int stage_v_184_2 = ((pub_r001002_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001002_7_1 * 2) + 39) & 63;
  int stage_v_185_2 = ((pub_r001002_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001002_15_1 * 2) + 8) & 63;
  int stage_v_186_2 = ((pub_r001002_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001002_6_1 * 2) + 7) & 63;
  int stage_v_187_2 = ((pub_r001002_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001002_5_1 * 2) + 26) & 63;
  int stage_v_188_2 = ((pub_r001002_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001002_22_1 * 2) + 32) & 63;
  int stage_v_189_2 = ((pub_r001002_22_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((stage_v_49_1 * 3) + pub_r001002_13_1) + 25) & 127;
  int stage_v_190_2 = (((stage_v_49_2 * 3) + pub_r001002_13_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = ((pub_r001002_20_1 * 2) + 38) & 63;
  int stage_v_191_2 = ((pub_r001002_20_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001002_18_1 * 2) + 28) & 63;
  int stage_v_192_2 = ((pub_r001002_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001002_17_1 * 2) + 32) & 63;
  int stage_v_193_2 = ((pub_r001002_17_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((pub_r001002_11_1 * 2) + 49) & 63;
  int stage_v_194_2 = ((pub_r001002_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001002_10_1 * 2) + 42) & 63;
  int stage_v_195_2 = ((pub_r001002_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001002_3_1 * 2) + 5) & 63;
  int stage_v_196_2 = ((pub_r001002_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001002_3_1 * 2) + 19) & 63;
  int stage_v_197_2 = ((pub_r001002_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001002_5_1 * 2) + 17) & 63;
  int stage_v_198_2 = ((pub_r001002_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001002_12_1 * 2) + 5) & 63;
  int stage_v_199_2 = ((pub_r001002_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001002_9_1 * 2) + 24) & 63;
  int stage_v_200_2 = ((pub_r001002_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001002_3_1 * 2) + 6) & 63;
  int stage_v_201_2 = ((pub_r001002_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001002_22_1 * 2) + 24) & 63;
  int stage_v_202_2 = ((pub_r001002_22_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001002_2_1 * 2) + 42) & 63;
  int stage_v_203_2 = ((pub_r001002_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001002_18_1 * 2) + 9) & 63;
  int stage_v_204_2 = ((pub_r001002_18_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = (((stage_v_102_1 * 3) + pub_r001002_15_1) + 14) & 127;
  int stage_v_205_2 = (((stage_v_102_2 * 3) + pub_r001002_15_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = (((helper_flow_3_1 * 3) + pub_r001002_12_1) + 38) & 127;
  int stage_v_206_2 = (((helper_flow_3_2 * 3) + pub_r001002_12_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = (((stage_v_111_1 * 3) + pub_r001002_3_1) + 24) & 127;
  int stage_v_207_2 = (((stage_v_111_2 * 3) + pub_r001002_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = ((pub_r001002_13_1 * 2) + 20) & 63;
  int stage_v_208_2 = ((pub_r001002_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = (((stage_v_112_1 * 3) + pub_r001002_16_1) + 43) & 127;
  int stage_v_209_2 = (((stage_v_112_2 * 3) + pub_r001002_16_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = ((pub_r001002_3_1 * 2) + 13) & 63;
  int stage_v_210_2 = ((pub_r001002_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((stage_v_55_1 * 3) + pub_r001002_2_1) + 4) & 127;
  int stage_v_211_2 = (((stage_v_55_2 * 3) + pub_r001002_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = (((stage_v_190_1 * 3) + pub_r001002_10_1) + 38) & 127;
  int stage_v_212_2 = (((stage_v_190_2 * 3) + pub_r001002_10_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = (((stage_v_170_1 * 3) + pub_r001002_11_1) + 3) & 127;
  int stage_v_213_2 = (((stage_v_170_2 * 3) + pub_r001002_11_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = ((pub_r001002_2_1 * 2) + 32) & 63;
  int stage_v_214_2 = ((pub_r001002_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((stage_v_29_1 * 3) + pub_r001002_3_1) + 7) & 127;
  int stage_v_215_2 = (((stage_v_29_2 * 3) + pub_r001002_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((stage_v_38_1 * 3) + pub_r001002_14_1) + 19) & 127;
  int stage_v_216_2 = (((stage_v_38_2 * 3) + pub_r001002_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = (((stage_v_190_1 * 3) + pub_r001002_6_1) + 33) & 127;
  int stage_v_217_2 = (((stage_v_190_2 * 3) + pub_r001002_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = ((pub_r001002_13_1 * 2) + 7) & 63;
  int stage_v_218_2 = ((pub_r001002_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001002_21_1 * 2) + 23) & 63;
  int stage_v_219_2 = ((pub_r001002_21_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((pub_r001002_18_1 * 2) + 30) & 63;
  int stage_v_220_2 = ((pub_r001002_18_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001002_5_1 * 2) + 47) & 63;
  int stage_v_221_2 = ((pub_r001002_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((pub_r001002_13_1 * 2) + 28) & 63;
  int stage_v_222_2 = ((pub_r001002_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((pub_r001002_17_1 * 2) + 19) & 63;
  int stage_v_223_2 = ((pub_r001002_17_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001002_12_1 * 2) + 26) & 63;
  int stage_v_224_2 = ((pub_r001002_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = (((stage_v_70_1 * 3) + pub_r001002_22_1) + 24) & 127;
  int stage_v_225_2 = (((stage_v_70_2 * 3) + pub_r001002_22_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = (((stage_v_128_1 * 3) + pub_r001002_2_1) + 44) & 127;
  int stage_v_226_2 = (((stage_v_128_2 * 3) + pub_r001002_2_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = ((pub_r001002_18_1 * 2) + 13) & 63;
  int stage_v_227_2 = ((pub_r001002_18_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = (((sec_r001002_8_1 * 3) + pub_r001002_15_1) + 41) & 127;
  int stage_v_228_2 = (((sec_r001002_8_2 * 3) + pub_r001002_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = (((sec_r001002_9_1 * 3) + pub_r001002_0_1) + 30) & 127;
  int stage_v_229_2 = (((sec_r001002_9_2 * 3) + pub_r001002_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = (((sec_r001002_18_1 * 3) + pub_r001002_8_1) + 34) & 127;
  int stage_v_230_2 = (((sec_r001002_18_2 * 3) + pub_r001002_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = (((stage_v_19_1 * 3) + pub_r001002_20_1) + 44) & 127;
  int stage_v_231_2 = (((stage_v_19_2 * 3) + pub_r001002_20_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = (((stage_v_190_1 * 3) + pub_r001002_13_1) + 25) & 127;
  int stage_v_232_2 = (((stage_v_190_2 * 3) + pub_r001002_13_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = ((pub_r001002_18_1 * 2) + 41) & 63;
  int stage_v_233_2 = ((pub_r001002_18_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001002_2_1 * 2) + 49) & 63;
  int stage_v_234_2 = ((pub_r001002_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001002_7_1 * 2) + 49) & 63;
  int stage_v_235_2 = ((pub_r001002_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001002_22_1 * 2) + 20) & 63;
  int stage_v_236_2 = ((pub_r001002_22_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001002_19_1 * 2) + 29) & 63;
  int stage_v_237_2 = ((pub_r001002_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = (((sec_r001002_13_1 * 3) + pub_r001002_8_1) + 5) & 127;
  int stage_v_238_2 = (((sec_r001002_13_2 * 3) + pub_r001002_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = ((pub_r001002_18_1 * 2) + 23) & 63;
  int stage_v_239_2 = ((pub_r001002_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((pub_r001002_22_1 * 2) + 32) & 63;
  int stage_v_240_2 = ((pub_r001002_22_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = ((pub_r001002_0_1 * 2) + 30) & 63;
  int stage_v_241_2 = ((pub_r001002_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = (((sec_r001002_9_1 * 3) + pub_r001002_11_1) + 4) & 127;
  int stage_v_242_2 = (((sec_r001002_9_2 * 3) + pub_r001002_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = ((pub_r001002_18_1 * 2) + 20) & 63;
  int stage_v_243_2 = ((pub_r001002_18_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = (((sec_r001002_6_1 * 3) + pub_r001002_4_1) + 26) & 127;
  int stage_v_244_2 = (((sec_r001002_6_2 * 3) + pub_r001002_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = (((stage_v_217_1 * 3) + pub_r001002_15_1) + 33) & 127;
  int stage_v_245_2 = (((stage_v_217_2 * 3) + pub_r001002_15_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = ((pub_r001002_5_1 * 2) + 14) & 63;
  int stage_v_246_2 = ((pub_r001002_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = (((sec_r001002_17_1 * 3) + pub_r001002_8_1) + 4) & 127;
  int stage_v_247_2 = (((sec_r001002_17_2 * 3) + pub_r001002_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = ((pub_r001002_16_1 * 2) + 45) & 63;
  int stage_v_248_2 = ((pub_r001002_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((pub_r001002_5_1 * 2) + 15) & 63;
  int stage_v_249_2 = ((pub_r001002_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001002_5_1 * 2) + 36) & 63;
  int stage_v_250_2 = ((pub_r001002_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001002_11_1 * 2) + 39) & 63;
  int stage_v_251_2 = ((pub_r001002_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = (((stage_v_61_1 * 3) + pub_r001002_4_1) + 27) & 127;
  int stage_v_252_2 = (((stage_v_61_2 * 3) + pub_r001002_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = (((stage_v_67_1 * 3) + pub_r001002_5_1) + 9) & 127;
  int stage_v_253_2 = (((stage_v_67_2 * 3) + pub_r001002_5_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = ((pub_r001002_22_1 * 2) + 14) & 63;
  int stage_v_254_2 = ((pub_r001002_22_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = (((stage_v_38_1 * 3) + pub_r001002_13_1) + 32) & 127;
  int stage_v_255_2 = (((stage_v_38_2 * 3) + pub_r001002_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = ((pub_r001002_20_1 * 2) + 38) & 63;
  int stage_v_256_2 = ((pub_r001002_20_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001002_10_1 * 2) + 9) & 63;
  int stage_v_257_2 = ((pub_r001002_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((pub_r001002_21_1 * 2) + 28) & 63;
  int stage_v_258_2 = ((pub_r001002_21_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = (((stage_v_104_1 * 3) + pub_r001002_13_1) + 7) & 127;
  int stage_v_259_2 = (((stage_v_104_2 * 3) + pub_r001002_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = ((pub_r001002_6_1 * 2) + 45) & 63;
  int stage_v_260_2 = ((pub_r001002_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001002_11_1 * 2) + 5) & 63;
  int stage_v_261_2 = ((pub_r001002_11_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001002_0_1 * 2) + 27) & 63;
  int stage_v_262_2 = ((pub_r001002_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001002_7_1 * 2) + 13) & 63;
  int stage_v_263_2 = ((pub_r001002_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = (((stage_v_215_1 * 3) + pub_r001002_3_1) + 21) & 127;
  int stage_v_264_2 = (((stage_v_215_2 * 3) + pub_r001002_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = ((pub_r001002_1_1 * 2) + 45) & 63;
  int stage_v_265_2 = ((pub_r001002_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = (((stage_v_55_1 * 3) + pub_r001002_2_1) + 22) & 127;
  int stage_v_266_2 = (((stage_v_55_2 * 3) + pub_r001002_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = ((pub_r001002_13_1 * 2) + 32) & 63;
  int stage_v_267_2 = ((pub_r001002_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((pub_r001002_11_1 * 2) + 8) & 63;
  int stage_v_268_2 = ((pub_r001002_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001002_19_1 * 2) + 8) & 63;
  int stage_v_269_2 = ((pub_r001002_19_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = (((stage_v_103_1 * 3) + pub_r001002_19_1) + 32) & 127;
  int stage_v_270_2 = (((stage_v_103_2 * 3) + pub_r001002_19_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = (((stage_v_70_1 * 3) + pub_r001002_10_1) + 4) & 127;
  int stage_v_271_2 = (((stage_v_70_2 * 3) + pub_r001002_10_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = ((pub_r001002_8_1 * 2) + 42) & 63;
  int stage_v_272_2 = ((pub_r001002_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = (((sec_r001002_9_1 * 3) + pub_r001002_1_1) + 5) & 127;
  int stage_v_273_2 = (((sec_r001002_9_2 * 3) + pub_r001002_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = ((pub_r001002_18_1 * 2) + 23) & 63;
  int stage_v_274_2 = ((pub_r001002_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((pub_r001002_4_1 * 2) + 46) & 63;
  int stage_v_275_2 = ((pub_r001002_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = (((stage_v_133_1 * 3) + pub_r001002_0_1) + 3) & 127;
  int stage_v_276_2 = (((stage_v_133_2 * 3) + pub_r001002_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = ((pub_r001002_17_1 * 2) + 17) & 63;
  int stage_v_277_2 = ((pub_r001002_17_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = (((helper_flow_0_1 * 3) + pub_r001002_12_1) + 25) & 127;
  int stage_v_278_2 = (((helper_flow_0_2 * 3) + pub_r001002_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = ((pub_r001002_18_1 * 2) + 23) & 63;
  int stage_v_279_2 = ((pub_r001002_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = (((stage_v_70_1 * 3) + pub_r001002_18_1) + 42) & 127;
  int stage_v_280_2 = (((stage_v_70_2 * 3) + pub_r001002_18_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = ((pub_r001002_2_1 * 2) + 38) & 63;
  int stage_v_281_2 = ((pub_r001002_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((pub_r001002_19_1 * 2) + 11) & 63;
  int stage_v_282_2 = ((pub_r001002_19_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001002_7_1 * 2) + 5) & 63;
  int stage_v_283_2 = ((pub_r001002_7_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001002_1_1 * 2) + 9) & 63;
  int stage_v_284_2 = ((pub_r001002_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001002_21_1 * 2) + 33) & 63;
  int stage_v_285_2 = ((pub_r001002_21_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001002_6_1 * 2) + 42) & 63;
  int stage_v_286_2 = ((pub_r001002_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((pub_r001002_9_1 * 2) + 35) & 63;
  int stage_v_287_2 = ((pub_r001002_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((pub_r001002_6_1 * 2) + 30) & 63;
  int stage_v_288_2 = ((pub_r001002_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = (((stage_v_145_1 * 3) + pub_r001002_1_1) + 24) & 127;
  int stage_v_289_2 = (((stage_v_145_2 * 3) + pub_r001002_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = (((stage_v_80_1 * 3) + pub_r001002_6_1) + 28) & 127;
  int stage_v_290_2 = (((stage_v_80_2 * 3) + pub_r001002_6_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = ((pub_r001002_5_1 * 2) + 43) & 63;
  int stage_v_291_2 = ((pub_r001002_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((pub_r001002_5_1 * 2) + 34) & 63;
  int stage_v_292_2 = ((pub_r001002_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001002_13_1 * 2) + 45) & 63;
  int stage_v_293_2 = ((pub_r001002_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = (((stage_v_217_1 * 3) + pub_r001002_14_1) + 37) & 127;
  int stage_v_294_2 = (((stage_v_217_2 * 3) + pub_r001002_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = (((stage_v_209_1 * 3) + pub_r001002_20_1) + 45) & 127;
  int stage_v_295_2 = (((stage_v_209_2 * 3) + pub_r001002_20_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = ((pub_r001002_3_1 * 2) + 31) & 63;
  int stage_v_296_2 = ((pub_r001002_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = (((stage_v_130_1 * 3) + pub_r001002_13_1) + 21) & 127;
  int stage_v_297_2 = (((stage_v_130_2 * 3) + pub_r001002_13_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = ((pub_r001002_22_1 * 2) + 28) & 63;
  int stage_v_298_2 = ((pub_r001002_22_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = (((sec_r001002_17_1 * 3) + pub_r001002_0_1) + 31) & 127;
  int stage_v_299_2 = (((sec_r001002_17_2 * 3) + pub_r001002_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = ((pub_r001002_11_1 * 2) + 7) & 63;
  int stage_v_300_2 = ((pub_r001002_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001002_5_1 * 2) + 48) & 63;
  int stage_v_301_2 = ((pub_r001002_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001002_22_1 * 2) + 36) & 63;
  int stage_v_302_2 = ((pub_r001002_22_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001002_9_1 * 2) + 28) & 63;
  int stage_v_303_2 = ((pub_r001002_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((pub_r001002_3_1 * 2) + 23) & 63;
  int stage_v_304_2 = ((pub_r001002_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001002_19_1 * 2) + 22) & 63;
  int stage_v_305_2 = ((pub_r001002_19_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001002_0_1 * 2) + 6) & 63;
  int stage_v_306_2 = ((pub_r001002_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = (((stage_v_67_1 * 3) + pub_r001002_13_1) + 41) & 127;
  int stage_v_307_2 = (((stage_v_67_2 * 3) + pub_r001002_13_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = ((pub_r001002_5_1 * 2) + 18) & 63;
  int stage_v_308_2 = ((pub_r001002_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = (((stage_v_67_1 * 3) + pub_r001002_2_1) + 8) & 127;
  int stage_v_309_2 = (((stage_v_67_2 * 3) + pub_r001002_2_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = (((stage_v_111_1 * 3) + pub_r001002_9_1) + 23) & 127;
  int stage_v_310_2 = (((stage_v_111_2 * 3) + pub_r001002_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = (((stage_v_172_1 * 3) + pub_r001002_5_1) + 35) & 127;
  int stage_v_311_2 = (((stage_v_172_2 * 3) + pub_r001002_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = ((pub_r001002_0_1 * 2) + 16) & 63;
  int stage_v_312_2 = ((pub_r001002_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = ((pub_r001002_0_1 * 2) + 22) & 63;
  int stage_v_313_2 = ((pub_r001002_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = (((stage_v_253_1 * 3) + pub_r001002_0_1) + 26) & 127;
  int stage_v_314_2 = (((stage_v_253_2 * 3) + pub_r001002_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = (((stage_v_252_1 * 3) + pub_r001002_14_1) + 33) & 127;
  int stage_v_315_2 = (((stage_v_252_2 * 3) + pub_r001002_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = (((stage_v_280_1 * 3) + pub_r001002_18_1) + 33) & 127;
  int stage_v_316_2 = (((stage_v_280_2 * 3) + pub_r001002_18_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = ((pub_r001002_4_1 * 2) + 29) & 63;
  int stage_v_317_2 = ((pub_r001002_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = (((sec_r001002_4_1 * 3) + pub_r001002_12_1) + 43) & 127;
  int stage_v_318_2 = (((sec_r001002_4_2 * 3) + pub_r001002_12_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = (((stage_v_309_1 * 3) + pub_r001002_19_1) + 39) & 127;
  int stage_v_319_2 = (((stage_v_309_2 * 3) + pub_r001002_19_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = ((pub_r001002_11_1 * 2) + 13) & 63;
  int stage_v_320_2 = ((pub_r001002_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = (((stage_v_152_1 * 3) + pub_r001002_10_1) + 33) & 127;
  int stage_v_321_2 = (((stage_v_152_2 * 3) + pub_r001002_10_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = ((pub_r001002_13_1 * 2) + 36) & 63;
  int stage_v_322_2 = ((pub_r001002_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001002_17_1 * 2) + 12) & 63;
  int stage_v_323_2 = ((pub_r001002_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((pub_r001002_2_1 * 2) + 8) & 63;
  int stage_v_324_2 = ((pub_r001002_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((pub_r001002_19_1 * 2) + 27) & 63;
  int stage_v_325_2 = ((pub_r001002_19_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((pub_r001002_6_1 * 2) + 34) & 63;
  int stage_v_326_2 = ((pub_r001002_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001002_15_1 * 2) + 21) & 63;
  int stage_v_327_2 = ((pub_r001002_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((pub_r001002_18_1 * 2) + 41) & 63;
  int stage_v_328_2 = ((pub_r001002_18_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001002_12_1 * 2) + 15) & 63;
  int stage_v_329_2 = ((pub_r001002_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001002_20_1 * 2) + 40) & 63;
  int stage_v_330_2 = ((pub_r001002_20_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001002_22_1 * 2) + 29) & 63;
  int stage_v_331_2 = ((pub_r001002_22_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001002_8_1 * 2) + 35) & 63;
  int stage_v_332_2 = ((pub_r001002_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001002_17_1 * 2) + 49) & 63;
  int stage_v_333_2 = ((pub_r001002_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((pub_r001002_0_1 * 2) + 50) & 63;
  int stage_v_334_2 = ((pub_r001002_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = (((sec_r001002_13_1 * 3) + pub_r001002_2_1) + 36) & 127;
  int stage_v_335_2 = (((sec_r001002_13_2 * 3) + pub_r001002_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = ((pub_r001002_7_1 * 2) + 16) & 63;
  int stage_v_336_2 = ((pub_r001002_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((pub_r001002_13_1 * 2) + 15) & 63;
  int stage_v_337_2 = ((pub_r001002_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((pub_r001002_5_1 * 2) + 31) & 63;
  int stage_v_338_2 = ((pub_r001002_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = (((stage_v_253_1 * 3) + pub_r001002_6_1) + 10) & 127;
  int stage_v_339_2 = (((stage_v_253_2 * 3) + pub_r001002_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = ((pub_r001002_6_1 * 2) + 35) & 63;
  int stage_v_340_2 = ((pub_r001002_6_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = (((stage_v_60_1 * 3) + pub_r001002_3_1) + 29) & 127;
  int stage_v_341_2 = (((stage_v_60_2 * 3) + pub_r001002_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = ((pub_r001002_9_1 * 2) + 35) & 63;
  int stage_v_342_2 = ((pub_r001002_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((pub_r001002_18_1 * 2) + 45) & 63;
  int stage_v_343_2 = ((pub_r001002_18_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = (((stage_v_229_1 * 3) + pub_r001002_1_1) + 30) & 127;
  int stage_v_344_2 = (((stage_v_229_2 * 3) + pub_r001002_1_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = (((stage_v_70_1 * 3) + pub_r001002_7_1) + 34) & 127;
  int stage_v_345_2 = (((stage_v_70_2 * 3) + pub_r001002_7_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = ((pub_r001002_8_1 * 2) + 38) & 63;
  int stage_v_346_2 = ((pub_r001002_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((pub_r001002_13_1 * 2) + 38) & 63;
  int stage_v_347_2 = ((pub_r001002_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((pub_r001002_16_1 * 2) + 30) & 63;
  int stage_v_348_2 = ((pub_r001002_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = ((pub_r001002_18_1 * 2) + 45) & 63;
  int stage_v_349_2 = ((pub_r001002_18_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = (((stage_v_128_1 * 3) + pub_r001002_2_1) + 36) & 127;
  int stage_v_350_2 = (((stage_v_128_2 * 3) + pub_r001002_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = (((sec_r001002_11_1 * 3) + pub_r001002_0_1) + 44) & 127;
  int stage_v_351_2 = (((sec_r001002_11_2 * 3) + pub_r001002_0_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = ((pub_r001002_22_1 * 2) + 49) & 63;
  int stage_v_352_2 = ((pub_r001002_22_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((pub_r001002_16_1 * 2) + 47) & 63;
  int stage_v_353_2 = ((pub_r001002_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((pub_r001002_18_1 * 2) + 28) & 63;
  int stage_v_354_2 = ((pub_r001002_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = (((stage_v_89_1 * 3) + pub_r001002_15_1) + 18) & 127;
  int stage_v_355_2 = (((stage_v_89_2 * 3) + pub_r001002_15_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = ((pub_r001002_9_1 * 2) + 14) & 63;
  int stage_v_356_2 = ((pub_r001002_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((pub_r001002_9_1 * 2) + 44) & 63;
  int stage_v_357_2 = ((pub_r001002_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001002_11_1 * 2) + 33) & 63;
  int stage_v_358_2 = ((pub_r001002_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = (((stage_v_161_1 * 3) + pub_r001002_22_1) + 3) & 127;
  int stage_v_359_2 = (((stage_v_161_2 * 3) + pub_r001002_22_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = (((stage_v_229_1 * 3) + pub_r001002_22_1) + 14) & 127;
  int stage_v_360_2 = (((stage_v_229_2 * 3) + pub_r001002_22_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = ((pub_r001002_9_1 * 2) + 15) & 63;
  int stage_v_361_2 = ((pub_r001002_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001002_1_1 * 2) + 31) & 63;
  int stage_v_362_2 = ((pub_r001002_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001002_20_1 * 2) + 50) & 63;
  int stage_v_363_2 = ((pub_r001002_20_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((pub_r001002_0_1 * 2) + 11) & 63;
  int stage_v_364_2 = ((pub_r001002_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001002_6_1 * 2) + 42) & 63;
  int stage_v_365_2 = ((pub_r001002_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((pub_r001002_17_1 * 2) + 14) & 63;
  int stage_v_366_2 = ((pub_r001002_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = ((pub_r001002_22_1 * 2) + 19) & 63;
  int stage_v_367_2 = ((pub_r001002_22_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = (((stage_v_350_1 * 3) + pub_r001002_9_1) + 25) & 127;
  int stage_v_368_2 = (((stage_v_350_2 * 3) + pub_r001002_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = ((pub_r001002_21_1 * 2) + 15) & 63;
  int stage_v_369_2 = ((pub_r001002_21_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001002_17_1 * 2) + 19) & 63;
  int stage_v_370_2 = ((pub_r001002_17_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((pub_r001002_9_1 * 2) + 25) & 63;
  int stage_v_371_2 = ((pub_r001002_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001002_12_1 * 2) + 28) & 63;
  int stage_v_372_2 = ((pub_r001002_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001002_13_1 * 2) + 49) & 63;
  int stage_v_373_2 = ((pub_r001002_13_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((pub_r001002_18_1 * 2) + 14) & 63;
  int stage_v_374_2 = ((pub_r001002_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = (((sec_r001002_7_1 * 3) + pub_r001002_7_1) + 45) & 127;
  int stage_v_375_2 = (((sec_r001002_7_2 * 3) + pub_r001002_7_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = ((pub_r001002_18_1 * 2) + 27) & 63;
  int stage_v_376_2 = ((pub_r001002_18_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((pub_r001002_2_1 * 2) + 47) & 63;
  int stage_v_377_2 = ((pub_r001002_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = ((pub_r001002_1_1 * 2) + 45) & 63;
  int stage_v_378_2 = ((pub_r001002_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = ((pub_r001002_0_1 * 2) + 50) & 63;
  int stage_v_379_2 = ((pub_r001002_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = ((pub_r001002_10_1 * 2) + 43) & 63;
  int stage_v_380_2 = ((pub_r001002_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = ((pub_r001002_9_1 * 2) + 41) & 63;
  int stage_v_381_2 = ((pub_r001002_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = ((pub_r001002_9_1 * 2) + 36) & 63;
  int stage_v_382_2 = ((pub_r001002_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((pub_r001002_2_1 * 2) + 33) & 63;
  int stage_v_383_2 = ((pub_r001002_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = (((stage_v_211_1 * 3) + pub_r001002_3_1) + 17) & 127;
  int stage_v_384_2 = (((stage_v_211_2 * 3) + pub_r001002_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = (((stage_v_351_1 * 3) + pub_r001002_18_1) + 17) & 127;
  int stage_v_385_2 = (((stage_v_351_2 * 3) + pub_r001002_18_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = (((stage_v_14_1 * 3) + pub_r001002_13_1) + 16) & 127;
  int stage_v_386_2 = (((stage_v_14_2 * 3) + pub_r001002_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_386_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_386_2 * 2)) & 255;
  int stage_v_387_1 = (((stage_v_41_1 * 3) + pub_r001002_4_1) + 26) & 127;
  int stage_v_387_2 = (((stage_v_41_2 * 3) + pub_r001002_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = (((stage_v_28_1 * 3) + pub_r001002_21_1) + 34) & 127;
  int stage_v_388_2 = (((stage_v_28_2 * 3) + pub_r001002_21_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_388_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_388_2 * 2)) & 255;
  int stage_v_389_1 = ((pub_r001002_1_1 * 2) + 37) & 63;
  int stage_v_389_2 = ((pub_r001002_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = ((pub_r001002_0_1 * 2) + 39) & 63;
  int stage_v_390_2 = ((pub_r001002_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((pub_r001002_11_1 * 2) + 42) & 63;
  int stage_v_391_2 = ((pub_r001002_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001002_21_1 * 2) + 48) & 63;
  int stage_v_392_2 = ((pub_r001002_21_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((pub_r001002_14_1 * 2) + 35) & 63;
  int stage_v_393_2 = ((pub_r001002_14_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((pub_r001002_14_1 * 2) + 22) & 63;
  int stage_v_394_2 = ((pub_r001002_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = (((stage_v_93_1 * 3) + pub_r001002_7_1) + 16) & 127;
  int stage_v_395_2 = (((stage_v_93_2 * 3) + pub_r001002_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_395_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_395_2 * 2)) & 255;
  int stage_v_396_1 = ((pub_r001002_21_1 * 2) + 48) & 63;
  int stage_v_396_2 = ((pub_r001002_21_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = ((pub_r001002_14_1 * 2) + 35) & 63;
  int stage_v_397_2 = ((pub_r001002_14_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((pub_r001002_0_1 * 2) + 14) & 63;
  int stage_v_398_2 = ((pub_r001002_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = (((stage_v_75_1 * 3) + pub_r001002_8_1) + 4) & 127;
  int stage_v_399_2 = (((stage_v_75_2 * 3) + pub_r001002_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_399_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_399_2 * 2)) & 255;
  int stage_v_400_1 = ((pub_r001002_4_1 * 2) + 11) & 63;
  int stage_v_400_2 = ((pub_r001002_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((pub_r001002_2_1 * 2) + 37) & 63;
  int stage_v_401_2 = ((pub_r001002_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = ((pub_r001002_2_1 * 2) + 38) & 63;
  int stage_v_402_2 = ((pub_r001002_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = ((pub_r001002_2_1 * 2) + 11) & 63;
  int stage_v_403_2 = ((pub_r001002_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = ((pub_r001002_6_1 * 2) + 19) & 63;
  int stage_v_404_2 = ((pub_r001002_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = (((stage_v_395_1 * 3) + pub_r001002_2_1) + 28) & 127;
  int stage_v_405_2 = (((stage_v_395_2 * 3) + pub_r001002_2_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = ((pub_r001002_12_1 * 2) + 13) & 63;
  int stage_v_406_2 = ((pub_r001002_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = ((pub_r001002_12_1 * 2) + 22) & 63;
  int stage_v_407_2 = ((pub_r001002_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = (((stage_v_52_1 * 3) + pub_r001002_0_1) + 33) & 127;
  int stage_v_408_2 = (((stage_v_52_2 * 3) + pub_r001002_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = ((pub_r001002_6_1 * 2) + 21) & 63;
  int stage_v_409_2 = ((pub_r001002_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = ((pub_r001002_22_1 * 2) + 24) & 63;
  int stage_v_410_2 = ((pub_r001002_22_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = (((stage_v_388_1 * 3) + pub_r001002_11_1) + 43) & 127;
  int stage_v_411_2 = (((stage_v_388_2 * 3) + pub_r001002_11_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_411_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_411_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_411_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_411_2 * 2)) & 255;
  int stage_v_412_1 = ((pub_r001002_11_1 * 2) + 23) & 63;
  int stage_v_412_2 = ((pub_r001002_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = (((stage_v_28_1 * 3) + pub_r001002_21_1) + 4) & 127;
  int stage_v_413_2 = (((stage_v_28_2 * 3) + pub_r001002_21_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_413_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_413_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_413_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_413_2 * 2)) & 255;
  int stage_v_414_1 = ((pub_r001002_7_1 * 2) + 12) & 63;
  int stage_v_414_2 = ((pub_r001002_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = (((stage_v_47_1 * 3) + pub_r001002_17_1) + 28) & 127;
  int stage_v_415_2 = (((stage_v_47_2 * 3) + pub_r001002_17_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_415_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_415_2 * 2)) & 255;
  int stage_v_416_1 = ((pub_r001002_10_1 * 2) + 44) & 63;
  int stage_v_416_2 = ((pub_r001002_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = ((pub_r001002_18_1 * 2) + 41) & 63;
  int stage_v_417_2 = ((pub_r001002_18_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((pub_r001002_15_1 * 2) + 22) & 63;
  int stage_v_418_2 = ((pub_r001002_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = ((pub_r001002_12_1 * 2) + 7) & 63;
  int stage_v_419_2 = ((pub_r001002_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = ((pub_r001002_17_1 * 2) + 27) & 63;
  int stage_v_420_2 = ((pub_r001002_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = ((pub_r001002_0_1 * 2) + 9) & 63;
  int stage_v_421_2 = ((pub_r001002_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = ((pub_r001002_6_1 * 2) + 13) & 63;
  int stage_v_422_2 = ((pub_r001002_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = ((pub_r001002_15_1 * 2) + 30) & 63;
  int stage_v_423_2 = ((pub_r001002_15_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001002_9_1 * 2) + 9) & 63;
  int stage_v_424_2 = ((pub_r001002_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((pub_r001002_22_1 * 2) + 38) & 63;
  int stage_v_425_2 = ((pub_r001002_22_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = (((stage_v_413_1 * 3) + pub_r001002_4_1) + 26) & 127;
  int stage_v_426_2 = (((stage_v_413_2 * 3) + pub_r001002_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_426_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_426_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_426_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_426_2 * 2)) & 255;
  int stage_v_427_1 = ((pub_r001002_7_1 * 2) + 17) & 63;
  int stage_v_427_2 = ((pub_r001002_7_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = ((pub_r001002_2_1 * 2) + 27) & 63;
  int stage_v_428_2 = ((pub_r001002_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = ((pub_r001002_8_1 * 2) + 49) & 63;
  int stage_v_429_2 = ((pub_r001002_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_429_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_429_2) & 127;
  int stage_v_430_1 = ((pub_r001002_11_1 * 2) + 49) & 63;
  int stage_v_430_2 = ((pub_r001002_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_430_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_430_2) & 127;
  int stage_v_431_1 = ((pub_r001002_4_1 * 2) + 34) & 63;
  int stage_v_431_2 = ((pub_r001002_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = (((stage_v_316_1 * 3) + pub_r001002_13_1) + 33) & 127;
  int stage_v_432_2 = (((stage_v_316_2 * 3) + pub_r001002_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_432_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_432_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_432_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_432_2 * 2)) & 255;
  int stage_v_433_1 = ((pub_r001002_10_1 * 2) + 5) & 63;
  int stage_v_433_2 = ((pub_r001002_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = (((sec_r001002_7_1 * 3) + pub_r001002_7_1) + 19) & 127;
  int stage_v_434_2 = (((sec_r001002_7_2 * 3) + pub_r001002_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_434_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_434_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_434_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_434_2 * 2)) & 255;
  int stage_v_435_1 = (((sec_r001002_18_1 * 3) + pub_r001002_7_1) + 12) & 127;
  int stage_v_435_2 = (((sec_r001002_18_2 * 3) + pub_r001002_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_435_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_435_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_435_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_435_2 * 2)) & 255;
  int stage_v_436_1 = ((pub_r001002_11_1 * 2) + 43) & 63;
  int stage_v_436_2 = ((pub_r001002_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = ((pub_r001002_22_1 * 2) + 36) & 63;
  int stage_v_437_2 = ((pub_r001002_22_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_437_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_437_2) & 127;
  int stage_v_438_1 = ((pub_r001002_6_1 * 2) + 13) & 63;
  int stage_v_438_2 = ((pub_r001002_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = ((pub_r001002_2_1 * 2) + 6) & 63;
  int stage_v_439_2 = ((pub_r001002_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = (((stage_v_150_1 * 3) + pub_r001002_10_1) + 15) & 127;
  int stage_v_440_2 = (((stage_v_150_2 * 3) + pub_r001002_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_440_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_440_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_440_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_440_2 * 2)) & 255;
  int stage_v_441_1 = ((pub_r001002_16_1 * 2) + 40) & 63;
  int stage_v_441_2 = ((pub_r001002_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = (((stage_v_386_1 * 3) + pub_r001002_16_1) + 28) & 127;
  int stage_v_442_2 = (((stage_v_386_2 * 3) + pub_r001002_16_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_442_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_442_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_442_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_442_2 * 2)) & 255;
  int stage_v_443_1 = ((pub_r001002_18_1 * 2) + 40) & 63;
  int stage_v_443_2 = ((pub_r001002_18_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((pub_r001002_6_1 * 2) + 23) & 63;
  int stage_v_444_2 = ((pub_r001002_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = (((stage_v_44_1 * 3) + pub_r001002_1_1) + 33) & 127;
  int stage_v_445_2 = (((stage_v_44_2 * 3) + pub_r001002_1_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_445_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_445_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_445_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_445_2 * 2)) & 255;
  int stage_v_446_1 = (((stage_v_13_1 * 3) + pub_r001002_12_1) + 22) & 127;
  int stage_v_446_2 = (((stage_v_13_2 * 3) + pub_r001002_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_446_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_446_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_446_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_446_2 * 2)) & 255;
  int stage_v_447_1 = ((pub_r001002_13_1 * 2) + 43) & 63;
  int stage_v_447_2 = ((pub_r001002_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_447_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_447_2) & 127;
  int stage_v_448_1 = ((pub_r001002_18_1 * 2) + 7) & 63;
  int stage_v_448_2 = ((pub_r001002_18_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = ((pub_r001002_10_1 * 2) + 22) & 63;
  int stage_v_449_2 = ((pub_r001002_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_449_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_449_2) & 127;
  int stage_v_450_1 = ((pub_r001002_7_1 * 2) + 40) & 63;
  int stage_v_450_2 = ((pub_r001002_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_450_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_450_2) & 127;
  int stage_v_451_1 = (((stage_v_58_1 * 3) + pub_r001002_17_1) + 16) & 127;
  int stage_v_451_2 = (((stage_v_58_2 * 3) + pub_r001002_17_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_451_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_451_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_451_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_451_2 * 2)) & 255;
  int stage_v_452_1 = ((pub_r001002_9_1 * 2) + 22) & 63;
  int stage_v_452_2 = ((pub_r001002_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = ((pub_r001002_12_1 * 2) + 39) & 63;
  int stage_v_453_2 = ((pub_r001002_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = ((pub_r001002_12_1 * 2) + 18) & 63;
  int stage_v_454_2 = ((pub_r001002_12_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_454_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_454_2) & 127;
  int stage_v_455_1 = ((pub_r001002_14_1 * 2) + 48) & 63;
  int stage_v_455_2 = ((pub_r001002_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_455_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_455_2) & 127;
  int stage_v_456_1 = ((pub_r001002_1_1 * 2) + 10) & 63;
  int stage_v_456_2 = ((pub_r001002_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_456_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_456_2) & 127;
  int stage_v_457_1 = ((pub_r001002_13_1 * 2) + 44) & 63;
  int stage_v_457_2 = ((pub_r001002_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_457_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_457_2) & 127;
  int stage_v_458_1 = ((pub_r001002_1_1 * 2) + 13) & 63;
  int stage_v_458_2 = ((pub_r001002_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_458_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_458_2) & 127;
  int stage_v_459_1 = ((pub_r001002_13_1 * 2) + 6) & 63;
  int stage_v_459_2 = ((pub_r001002_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_459_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_459_2) & 127;
  int stage_v_460_1 = (((stage_v_150_1 * 3) + pub_r001002_1_1) + 9) & 127;
  int stage_v_460_2 = (((stage_v_150_2 * 3) + pub_r001002_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_460_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_460_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_460_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_460_2 * 2)) & 255;
  int stage_v_461_1 = (((stage_v_19_1 * 3) + pub_r001002_15_1) + 44) & 127;
  int stage_v_461_2 = (((stage_v_19_2 * 3) + pub_r001002_15_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_461_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_461_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_461_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_461_2 * 2)) & 255;
  int stage_v_462_1 = ((pub_r001002_19_1 * 2) + 6) & 63;
  int stage_v_462_2 = ((pub_r001002_19_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_462_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_462_2) & 127;
  int stage_v_463_1 = ((pub_r001002_20_1 * 2) + 38) & 63;
  int stage_v_463_2 = ((pub_r001002_20_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_463_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_463_2) & 127;
  int stage_v_464_1 = ((pub_r001002_5_1 * 2) + 35) & 63;
  int stage_v_464_2 = ((pub_r001002_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_464_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_464_2) & 127;
  int stage_v_465_1 = ((pub_r001002_11_1 * 2) + 21) & 63;
  int stage_v_465_2 = ((pub_r001002_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_465_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_465_2) & 127;
  int stage_v_466_1 = ((pub_r001002_17_1 * 2) + 45) & 63;
  int stage_v_466_2 = ((pub_r001002_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_466_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_466_2) & 127;
  int stage_v_467_1 = (((stage_v_386_1 * 3) + pub_r001002_14_1) + 7) & 127;
  int stage_v_467_2 = (((stage_v_386_2 * 3) + pub_r001002_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_467_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_467_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_467_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_467_2 * 2)) & 255;
  int stage_v_468_1 = ((pub_r001002_13_1 * 2) + 40) & 63;
  int stage_v_468_2 = ((pub_r001002_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_468_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_468_2) & 127;
  int stage_v_469_1 = ((pub_r001002_9_1 * 2) + 49) & 63;
  int stage_v_469_2 = ((pub_r001002_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_469_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_469_2) & 127;
  int stage_v_470_1 = (((stage_v_41_1 * 3) + pub_r001002_7_1) + 13) & 127;
  int stage_v_470_2 = (((stage_v_41_2 * 3) + pub_r001002_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_470_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_470_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_470_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_470_2 * 2)) & 255;
  int stage_v_471_1 = ((pub_r001002_16_1 * 2) + 24) & 63;
  int stage_v_471_2 = ((pub_r001002_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_471_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_471_2) & 127;
  int stage_v_472_1 = ((pub_r001002_4_1 * 2) + 26) & 63;
  int stage_v_472_2 = ((pub_r001002_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_472_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_472_2) & 127;
  int stage_v_473_1 = ((pub_r001002_21_1 * 2) + 6) & 63;
  int stage_v_473_2 = ((pub_r001002_21_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_473_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_473_2) & 127;
  int stage_v_474_1 = ((pub_r001002_16_1 * 2) + 39) & 63;
  int stage_v_474_2 = ((pub_r001002_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_474_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_474_2) & 127;
  int stage_v_475_1 = ((pub_r001002_0_1 * 2) + 36) & 63;
  int stage_v_475_2 = ((pub_r001002_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_475_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_475_2) & 127;
  int stage_v_476_1 = (((stage_v_122_1 * 3) + pub_r001002_12_1) + 32) & 127;
  int stage_v_476_2 = (((stage_v_122_2 * 3) + pub_r001002_12_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_476_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_476_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_476_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_476_2 * 2)) & 255;
  int stage_v_477_1 = (((stage_v_113_1 * 3) + pub_r001002_22_1) + 31) & 127;
  int stage_v_477_2 = (((stage_v_113_2 * 3) + pub_r001002_22_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_477_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_477_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_477_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_477_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001002_9_1 != sec_r001002_9_2);
  __CPROVER_assume(pub_r001002_8_1 == pub_r001002_8_2);
  __CPROVER_assume(pub_r001002_22_1 == pub_r001002_22_2);
  __CPROVER_assume(pub_r001002_2_1 == pub_r001002_2_2);
  __CPROVER_assume(pub_r001002_13_1 == pub_r001002_13_2);
  __CPROVER_assume(pub_r001002_15_1 == pub_r001002_15_2);
  __CPROVER_assume(sec_r001002_3_1 != sec_r001002_3_2);
  __CPROVER_assume(sec_r001002_16_1 != sec_r001002_16_2);
  __CPROVER_assume(pub_r001002_5_1 == pub_r001002_5_2);
  __CPROVER_assume(sec_r001002_15_1 != sec_r001002_15_2);
  __CPROVER_assume(sec_r001002_0_1 != sec_r001002_0_2);
  __CPROVER_assume(sec_r001002_12_1 != sec_r001002_12_2);
  __CPROVER_assume(sec_r001002_7_1 != sec_r001002_7_2);
  __CPROVER_assume(sec_r001002_1_1 != sec_r001002_1_2);
  __CPROVER_assume(sec_r001002_8_1 != sec_r001002_8_2);
  __CPROVER_assume(pub_r001002_1_1 == pub_r001002_1_2);
  __CPROVER_assume(pub_r001002_9_1 == pub_r001002_9_2);
  __CPROVER_assume(pub_r001002_10_1 == pub_r001002_10_2);
  __CPROVER_assume(pub_r001002_21_1 == pub_r001002_21_2);
  __CPROVER_assume(sec_r001002_17_1 != sec_r001002_17_2);
  __CPROVER_assume(sec_r001002_18_1 != sec_r001002_18_2);
  __CPROVER_assume(pub_r001002_7_1 == pub_r001002_7_2);
  __CPROVER_assume(sec_r001002_5_1 != sec_r001002_5_2);
  __CPROVER_assume(pub_r001002_0_1 == pub_r001002_0_2);
  __CPROVER_assume(pub_r001002_12_1 == pub_r001002_12_2);
  __CPROVER_assume(pub_r001002_18_1 == pub_r001002_18_2);
  __CPROVER_assume(sec_r001002_14_1 != sec_r001002_14_2);
  __CPROVER_assume(pub_r001002_11_1 == pub_r001002_11_2);
  __CPROVER_assume(pub_r001002_6_1 == pub_r001002_6_2);
  __CPROVER_assume(pub_r001002_20_1 == pub_r001002_20_2);
  __CPROVER_assume(sec_r001002_2_1 != sec_r001002_2_2);
  __CPROVER_assume(sec_r001002_6_1 != sec_r001002_6_2);
  __CPROVER_assume(pub_r001002_14_1 == pub_r001002_14_2);
  __CPROVER_assume(sec_r001002_19_1 != sec_r001002_19_2);
  __CPROVER_assume(sec_r001002_13_1 != sec_r001002_13_2);
  __CPROVER_assume(pub_r001002_19_1 == pub_r001002_19_2);
  __CPROVER_assume(pub_r001002_3_1 == pub_r001002_3_2);
  __CPROVER_assume(pub_r001002_17_1 == pub_r001002_17_2);
  __CPROVER_assume(pub_r001002_16_1 == pub_r001002_16_2);
  __CPROVER_assume(sec_r001002_4_1 != sec_r001002_4_2);
  __CPROVER_assume(sec_r001002_10_1 != sec_r001002_10_2);
  __CPROVER_assume(sec_r001002_11_1 != sec_r001002_11_2);
  __CPROVER_assume(pub_r001002_4_1 == pub_r001002_4_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.mode == st_var_1_2.mode);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.determinant == st_var_2_2.determinant);
  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.density == st_var_2_2.density);
  assert(st_var_2_1.stride == st_var_2_2.stride);
  assert(st_var_2_1.trace == st_var_2_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.timestamp == st_var_3_2.timestamp);
  assert(st_var_3_1.facility == st_var_3_2.facility);
  assert(st_var_3_1.severity == st_var_3_2.severity);
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
}


