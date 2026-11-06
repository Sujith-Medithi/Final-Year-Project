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
struct FilterState_R000367_6713_0
{
  unsigned char gain_db;
  unsigned char prev_out;
  int damping;
  short prev_in;
  int mode;
  int cutoff;
  int buffer[3];
};
struct MatrixBlock_R000367_6713_1
{
  unsigned char stride;
  short trace;
  unsigned char determinant;
  int density;
  unsigned char scale;
  int buffer[3];
};
struct AudioFrame_R000367_6713_2
{
  int peak;
  short gain;
  unsigned char sample_rate;
  short channels;
  int rms;
  int buffer[3];
};
union ColorPixel_R000367_6713_0
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
void fn_R000367_6713_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000367_6713_1 st_1 = {0};
  struct MatrixBlock_R000367_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int phase_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_47_1) & 63;
  aux_2 = (aux_2 + phase_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_99_1)
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

  switch (segment_99_2)
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
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_47_1 == phase_47_2);
  assert(segment_99_1 == segment_99_2);
}

int fn_R000367_6713_0(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000367_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int phase_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_47) & 63;
  acc ^= aux;
  int segment_99 = (aux + st.buffer[1]) & 3;
  switch (segment_99)
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

void fn_R000367_6713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000367_6713_2 st_1 = {0};
  struct AudioFrame_R000367_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_27_1 = local_arr_1[aux_1 % 3];
  int tally_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_27_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_15_1) & 63;
  aux_2 = (aux_2 + phase_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_26_1)
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

  switch (mask_26_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_27_1 == tally_27_2);
  assert(phase_15_1 == phase_15_2);
  assert(mask_26_1 == mask_26_2);
}

int fn_R000367_6713_1(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000367_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int tally_27 = local_arr[aux % 3];
  acc = (acc + (tally_27 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_15) & 63;
  acc ^= aux;
  int mask_26 = (aux + st.buffer[1]) & 3;
  switch (mask_26)
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

void fn_R000367_6713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st_1 = {0};
  struct FilterState_R000367_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int phase_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_32_1) & 63;
  aux_2 = (aux_2 + phase_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_64_1)
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

  switch (metric_64_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_32_1 == phase_32_2);
  assert(metric_64_1 == metric_64_2);
}

int fn_R000367_6713_2(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int phase_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_32) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_64 = (aux + st.buffer[1]) & 3;
  switch (metric_64)
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

void fn_R000367_6713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000367_6713_1 st_1 = {0};
  struct MatrixBlock_R000367_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int threshold_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_29_1 > 31)
  {
    acc_1 = ((acc_1 + (threshold_29_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_29_2 > 31)
  {
    acc_2 = ((acc_2 + (threshold_29_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_53_1 = local_arr_1[aux_1 % 3];
  int checksum_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_53_2 * 2)) & 127;
  int coefficient_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_90_1) & 63;
  aux_2 = (aux_2 + coefficient_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_29_1 == threshold_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_53_1 == checksum_53_2);
  assert(coefficient_90_1 == coefficient_90_2);
}

int fn_R000367_6713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000367_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int threshold_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_29 > 31)
  {
    acc = ((acc + (threshold_29 * 2)) + 5) & 127;
    aux ^= threshold_29 & 15;
  }
  else
  {
    acc = ((acc - threshold_29) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_53 = local_arr[aux % 3];
  acc = (acc + (checksum_53 * 2)) & 127;
  int coefficient_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_90) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000367_6713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st_1 = {0};
  struct FilterState_R000367_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_74_1 = local_arr_1[aux_1 % 3];
  int delta_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_74_2 * 2)) & 127;
  int cursor_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_68_1 > 27)
  {
    acc_1 = ((acc_1 + (cursor_68_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_68_2 > 27)
  {
    acc_2 = ((acc_2 + (cursor_68_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_68_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_74_1 == delta_74_2);
  assert(cursor_68_1 == cursor_68_2);
}

int fn_R000367_6713_4(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int delta_74 = local_arr[aux % 3];
  acc = (acc + (delta_74 * 2)) & 127;
  int cursor_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_68 > 27)
  {
    acc = ((acc + (cursor_68 * 2)) + 5) & 127;
    aux ^= cursor_68 & 15;
  }
  else
  {
    acc = ((acc - cursor_68) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000367_6713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st_1 = {0};
  struct FilterState_R000367_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int bound_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_88_1) & 63;
  aux_2 = (aux_2 + bound_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_62_1 > 40)
  {
    acc_1 = ((acc_1 + (phase_62_1 * 2)) + 5) & 127;
    aux_1 ^= phase_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_62_2 > 40)
  {
    acc_2 = ((acc_2 + (phase_62_2 * 2)) + 5) & 127;
    aux_2 ^= phase_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_62_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_88_1 == bound_88_2);
  assert(phase_62_1 == phase_62_2);
}

int fn_R000367_6713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int bound_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_88) & 63;
  acc ^= aux;
  int phase_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_62 > 40)
  {
    acc = ((acc + (phase_62 * 2)) + 5) & 127;
    aux ^= phase_62 & 15;
  }
  else
  {
    acc = ((acc - phase_62) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000367_6713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000367_6713_1 st_1 = {0};
  struct MatrixBlock_R000367_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int window_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_19_1)
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

  switch (window_19_2)
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
  int bound_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_81_1 > 39)
  {
    acc_1 = ((acc_1 + (bound_81_1 * 2)) + 5) & 127;
    aux_1 ^= bound_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_81_2 > 39)
  {
    acc_2 = ((acc_2 + (bound_81_2 * 2)) + 5) & 127;
    aux_2 ^= bound_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_81_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_44_1 = local_arr_1[aux_1 % 3];
  int checksum_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_44_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_19_1 == window_19_2);
  assert(bound_81_1 == bound_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_44_1 == checksum_44_2);
}

int fn_R000367_6713_6(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000367_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int window_19 = (aux + st.buffer[1]) & 3;
  switch (window_19)
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
  int bound_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_81 > 39)
  {
    acc = ((acc + (bound_81 * 2)) + 5) & 127;
    aux ^= bound_81 & 15;
  }
  else
  {
    acc = ((acc - bound_81) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_44 = local_arr[aux % 3];
  acc = (acc + (checksum_44 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000367_6713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000367_6713_1 st_1 = {0};
  struct MatrixBlock_R000367_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int factor_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_61_1 > 44)
  {
    acc_1 = ((acc_1 + (factor_61_1 * 2)) + 5) & 127;
    aux_1 ^= factor_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_61_2 > 44)
  {
    acc_2 = ((acc_2 + (factor_61_2 * 2)) + 5) & 127;
    aux_2 ^= factor_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_32_1)
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

  switch (index_reg_32_2)
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

  int tally_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_54_1) & 63;
  aux_2 = (aux_2 + tally_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_61_1 == factor_61_2);
  assert(index_reg_32_1 == index_reg_32_2);
  assert(tally_54_1 == tally_54_2);
}

int fn_R000367_6713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000367_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int factor_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_61 > 44)
  {
    acc = ((acc + (factor_61 * 2)) + 5) & 127;
    aux ^= factor_61 & 15;
  }
  else
  {
    acc = ((acc - factor_61) + 11) & 127;
    aux += 3;
  }
  int index_reg_32 = (aux + st.buffer[1]) & 3;
  switch (index_reg_32)
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

  int tally_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_54) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000367_6713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000367_6713_1 st_1 = {0};
  struct MatrixBlock_R000367_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_32_1 = local_arr_1[aux_1 % 3];
  int tracker_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_32_2 * 2)) & 127;
  int sample_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_16_1) & 63;
  aux_2 = (aux_2 + sample_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_32_1 == tracker_32_2);
  assert(sample_16_1 == sample_16_2);
}

int fn_R000367_6713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000367_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int tracker_32 = local_arr[aux % 3];
  acc = (acc + (tracker_32 * 2)) & 127;
  int sample_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_16) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000367_6713_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st_1 = {0};
  struct FilterState_R000367_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int factor_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_62_1) & 63;
  aux_2 = (aux_2 + factor_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
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

  int parity_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_46_1 > 39)
  {
    acc_1 = ((acc_1 + (parity_46_1 * 2)) + 5) & 127;
    aux_1 ^= parity_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_46_2 > 39)
  {
    acc_2 = ((acc_2 + (parity_46_2 * 2)) + 5) & 127;
    aux_2 ^= parity_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_36_1 = local_arr_1[aux_1 % 3];
  int coefficient_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_36_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_62_1 == factor_62_2);
  assert(tally_46_1 == tally_46_2);
  assert(parity_46_1 == parity_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_36_1 == coefficient_36_2);
}

int fn_R000367_6713_9(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int factor_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_62) & 63;
  acc ^= aux;
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

  int parity_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_46 > 39)
  {
    acc = ((acc + (parity_46 * 2)) + 5) & 127;
    aux ^= parity_46 & 15;
  }
  else
  {
    acc = ((acc - parity_46) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int coefficient_36 = local_arr[aux % 3];
  acc = (acc + (coefficient_36 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000367_6713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st_1 = {0};
  struct FilterState_R000367_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_61_1 = local_arr_1[aux_1 % 3];
  int quotient_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_61_2 * 2)) & 127;
  int damping_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_63_1)
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

  switch (damping_63_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_61_1 == quotient_61_2);
  assert(damping_63_1 == damping_63_2);
}

int fn_R000367_6713_10(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int quotient_61 = local_arr[aux % 3];
  acc = (acc + (quotient_61 * 2)) & 127;
  int damping_63 = (aux + st.buffer[1]) & 3;
  switch (damping_63)
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

void fn_R000367_6713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000367_6713_1 st_1 = {0};
  struct MatrixBlock_R000367_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int offset_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_34_1) & 63;
  aux_2 = (aux_2 + offset_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_82_1)
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

  switch (metric_82_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_34_1 == offset_34_2);
  assert(metric_82_1 == metric_82_2);
}

int fn_R000367_6713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000367_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int offset_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_34) & 63;
  acc ^= aux;
  int metric_82 = (aux + st.buffer[1]) & 3;
  switch (metric_82)
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

void fn_R000367_6713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000367_6713_2 st_1 = {0};
  struct AudioFrame_R000367_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_77_1 > 44)
  {
    acc_1 = ((acc_1 + (residue_77_1 * 2)) + 5) & 127;
    aux_1 ^= residue_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_77_2 > 44)
  {
    acc_2 = ((acc_2 + (residue_77_2 * 2)) + 5) & 127;
    aux_2 ^= residue_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_50_1)
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

  switch (threshold_50_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_77_1 == residue_77_2);
  assert(threshold_50_1 == threshold_50_2);
}

int fn_R000367_6713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000367_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_77 > 44)
  {
    acc = ((acc + (residue_77 * 2)) + 5) & 127;
    aux ^= residue_77 & 15;
  }
  else
  {
    acc = ((acc - residue_77) + 11) & 127;
    aux += 3;
  }
  int threshold_50 = (aux + st.buffer[1]) & 3;
  switch (threshold_50)
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

void fn_R000367_6713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000367_6713_2 st_1 = {0};
  struct AudioFrame_R000367_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_44_1 = local_arr_1[aux_1 % 3];
  int anchor_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_44_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_29_1) & 63;
  aux_2 = (aux_2 + damping_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_86_1)
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

  switch (offset_86_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_44_1 == anchor_44_2);
  assert(damping_29_1 == damping_29_2);
  assert(offset_86_1 == offset_86_2);
}

int fn_R000367_6713_13(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000367_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int anchor_44 = local_arr[aux % 3];
  acc = (acc + (anchor_44 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_29) & 63;
  acc ^= aux;
  int offset_86 = (aux + st.buffer[1]) & 3;
  switch (offset_86)
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

void fn_R000367_6713_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st_1 = {0};
  struct FilterState_R000367_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int scale_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_74_1) & 63;
  aux_2 = (aux_2 + scale_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_98_1)
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

  switch (damping_98_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_74_1 == scale_74_2);
  assert(damping_98_1 == damping_98_2);
}

int fn_R000367_6713_14(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int scale_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_74) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_98 = (aux + st.buffer[1]) & 3;
  switch (damping_98)
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

void fn_R000367_6713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000367_6713_1 st_1 = {0};
  struct MatrixBlock_R000367_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int bound_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_39_1 > 28)
  {
    acc_1 = ((acc_1 + (bound_39_1 * 2)) + 5) & 127;
    aux_1 ^= bound_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_39_2 > 28)
  {
    acc_2 = ((acc_2 + (bound_39_2 * 2)) + 5) & 127;
    aux_2 ^= bound_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_39_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_86_1) & 63;
  aux_2 = (aux_2 + metric_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_39_1 == bound_39_2);
  assert(metric_86_1 == metric_86_2);
}

int fn_R000367_6713_15(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000367_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int bound_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_39 > 28)
  {
    acc = ((acc + (bound_39 * 2)) + 5) & 127;
    aux ^= bound_39 & 15;
  }
  else
  {
    acc = ((acc - bound_39) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_86) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000367_6713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000367_6713_2 st_1 = {0};
  struct AudioFrame_R000367_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int coefficient_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_92_1)
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

  switch (coefficient_92_2)
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
  int quantum_37_1 = local_arr_1[aux_1 % 3];
  int quantum_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_37_2 * 2)) & 127;
  int mask_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_70_1) & 63;
  aux_2 = (aux_2 + mask_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_92_1 == coefficient_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_37_1 == quantum_37_2);
  assert(mask_70_1 == mask_70_2);
}

int fn_R000367_6713_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000367_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int coefficient_92 = (aux + st.buffer[1]) & 3;
  switch (coefficient_92)
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
  int quantum_37 = local_arr[aux % 3];
  acc = (acc + (quantum_37 * 2)) & 127;
  int mask_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_70) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000367_6713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st_1 = {0};
  struct FilterState_R000367_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int tracker_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_34_1 > 37)
  {
    acc_1 = ((acc_1 + (tracker_34_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_34_2 > 37)
  {
    acc_2 = ((acc_2 + (tracker_34_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_69_1)
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

  switch (cursor_69_2)
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

  int delta_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_46_1) & 63;
  aux_2 = (aux_2 + delta_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_34_1 == tracker_34_2);
  assert(cursor_69_1 == cursor_69_2);
  assert(delta_46_1 == delta_46_2);
}

int fn_R000367_6713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int tracker_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_34 > 37)
  {
    acc = ((acc + (tracker_34 * 2)) + 5) & 127;
    aux ^= tracker_34 & 15;
  }
  else
  {
    acc = ((acc - tracker_34) + 11) & 127;
    aux += 3;
  }
  int cursor_69 = (aux + st.buffer[1]) & 3;
  switch (cursor_69)
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

  int delta_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_46) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000367_6713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000367_6713_1 st_1 = {0};
  struct MatrixBlock_R000367_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_11_1)
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

  switch (window_11_2)
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

  int stride_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_98_1 > 12)
  {
    acc_1 = ((acc_1 + (stride_98_1 * 2)) + 5) & 127;
    aux_1 ^= stride_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_98_2 > 12)
  {
    acc_2 = ((acc_2 + (stride_98_2 * 2)) + 5) & 127;
    aux_2 ^= stride_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_98_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_11_1 == window_11_2);
  assert(stride_98_1 == stride_98_2);
}

int fn_R000367_6713_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000367_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_11 = (aux + st.buffer[1]) & 3;
  switch (window_11)
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

  int stride_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_98 > 12)
  {
    acc = ((acc + (stride_98 * 2)) + 5) & 127;
    aux ^= stride_98 & 15;
  }
  else
  {
    acc = ((acc - stride_98) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000367_6713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st_1 = {0};
  struct FilterState_R000367_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int phase_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_78_1 > 29)
  {
    acc_1 = ((acc_1 + (phase_78_1 * 2)) + 5) & 127;
    aux_1 ^= phase_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_78_2 > 29)
  {
    acc_2 = ((acc_2 + (phase_78_2 * 2)) + 5) & 127;
    aux_2 ^= phase_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_66_1 = local_arr_1[aux_1 % 3];
  int cursor_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_66_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_78_1 == phase_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_66_1 == cursor_66_2);
}

int fn_R000367_6713_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int phase_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_78 > 29)
  {
    acc = ((acc + (phase_78 * 2)) + 5) & 127;
    aux ^= phase_78 & 15;
  }
  else
  {
    acc = ((acc - phase_78) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_66 = local_arr[aux % 3];
  acc = (acc + (cursor_66 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000367_6713_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st_1 = {0};
  struct FilterState_R000367_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int anchor_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_19_1)
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

  switch (anchor_19_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_41_1 > 16)
  {
    acc_1 = ((acc_1 + (accumulator_41_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_41_2 > 16)
  {
    acc_2 = ((acc_2 + (accumulator_41_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_41_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_19_1 == anchor_19_2);
  assert(accumulator_41_1 == accumulator_41_2);
}

int fn_R000367_6713_20(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int anchor_19 = (aux + st.buffer[1]) & 3;
  switch (anchor_19)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_41 > 16)
  {
    acc = ((acc + (accumulator_41 * 2)) + 5) & 127;
    aux ^= accumulator_41 & 15;
  }
  else
  {
    acc = ((acc - accumulator_41) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000367_6713_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st_1 = {0};
  struct FilterState_R000367_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_77_1 = local_arr_1[aux_1 % 3];
  int pivot_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_77_2 * 2)) & 127;
  int cursor_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_68_1) & 63;
  aux_2 = (aux_2 + cursor_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_77_1 == pivot_77_2);
  assert(cursor_68_1 == cursor_68_2);
}

int fn_R000367_6713_21(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int pivot_77 = local_arr[aux % 3];
  acc = (acc + (pivot_77 * 2)) & 127;
  int cursor_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_68) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000367_6713_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st_1 = {0};
  struct FilterState_R000367_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int damping_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_72_1) & 63;
  aux_2 = (aux_2 + damping_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_72_1 == damping_72_2);
}

int fn_R000367_6713_22(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000367_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int damping_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_72) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000367_6713_23_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000367_6713_1 st_1 = {0};
  struct MatrixBlock_R000367_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_46_1)
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

  switch (offset_46_2)
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
  int margin_95_1 = local_arr_1[aux_1 % 3];
  int margin_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_46_1 == offset_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_95_1 == margin_95_2);
}

int fn_R000367_6713_23(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000367_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_46 = (aux + st.buffer[1]) & 3;
  switch (offset_46)
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
  int margin_95 = local_arr[aux % 3];
  acc = (acc + (margin_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000367_0_1;
  int sec_r000367_0_2;
  int sec_r000367_1_1;
  int sec_r000367_1_2;
  int sec_r000367_2_1;
  int sec_r000367_2_2;
  int sec_r000367_3_1;
  int sec_r000367_3_2;
  int sec_r000367_4_1;
  int sec_r000367_4_2;
  int sec_r000367_5_1;
  int sec_r000367_5_2;
  int sec_r000367_6_1;
  int sec_r000367_6_2;
  int sec_r000367_7_1;
  int sec_r000367_7_2;
  int sec_r000367_8_1;
  int sec_r000367_8_2;
  int sec_r000367_9_1;
  int sec_r000367_9_2;
  int sec_r000367_10_1;
  int sec_r000367_10_2;
  int sec_r000367_11_1;
  int sec_r000367_11_2;
  int sec_r000367_12_1;
  int sec_r000367_12_2;
  int sec_r000367_13_1;
  int sec_r000367_13_2;
  int sec_r000367_14_1;
  int sec_r000367_14_2;
  int sec_r000367_15_1;
  int sec_r000367_15_2;
  int sec_r000367_16_1;
  int sec_r000367_16_2;
  int sec_r000367_17_1;
  int sec_r000367_17_2;
  int sec_r000367_18_1;
  int sec_r000367_18_2;
  int sec_r000367_19_1;
  int sec_r000367_19_2;
  int sec_r000367_20_1;
  int sec_r000367_20_2;
  int sec_r000367_21_1;
  int sec_r000367_21_2;
  int pub_r000367_0_1;
  int pub_r000367_0_2;
  int pub_r000367_1_1;
  int pub_r000367_1_2;
  int pub_r000367_2_1;
  int pub_r000367_2_2;
  int pub_r000367_3_1;
  int pub_r000367_3_2;
  int pub_r000367_4_1;
  int pub_r000367_4_2;
  int pub_r000367_5_1;
  int pub_r000367_5_2;
  int pub_r000367_6_1;
  int pub_r000367_6_2;
  int pub_r000367_7_1;
  int pub_r000367_7_2;
  int pub_r000367_8_1;
  int pub_r000367_8_2;
  int pub_r000367_9_1;
  int pub_r000367_9_2;
  int pub_r000367_10_1;
  int pub_r000367_10_2;
  int pub_r000367_11_1;
  int pub_r000367_11_2;
  int pub_r000367_12_1;
  int pub_r000367_12_2;
  int pub_r000367_13_1;
  int pub_r000367_13_2;
  int pub_r000367_14_1;
  int pub_r000367_14_2;
  int pub_r000367_15_1;
  int pub_r000367_15_2;
  int pub_r000367_16_1;
  int pub_r000367_16_2;
  int pub_r000367_17_1;
  int pub_r000367_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000367_0_1 >= (-100)) && (pub_r000367_0_1 <= 100));
  __CPROVER_assume((pub_r000367_0_2 >= (-100)) && (pub_r000367_0_2 <= 100));
  __CPROVER_assume((pub_r000367_1_1 >= (-100)) && (pub_r000367_1_1 <= 100));
  __CPROVER_assume((pub_r000367_1_2 >= (-100)) && (pub_r000367_1_2 <= 100));
  __CPROVER_assume((pub_r000367_2_1 >= (-100)) && (pub_r000367_2_1 <= 100));
  __CPROVER_assume((pub_r000367_2_2 >= (-100)) && (pub_r000367_2_2 <= 100));
  __CPROVER_assume((pub_r000367_3_1 >= (-100)) && (pub_r000367_3_1 <= 100));
  __CPROVER_assume((pub_r000367_3_2 >= (-100)) && (pub_r000367_3_2 <= 100));
  __CPROVER_assume((pub_r000367_4_1 >= (-100)) && (pub_r000367_4_1 <= 100));
  __CPROVER_assume((pub_r000367_4_2 >= (-100)) && (pub_r000367_4_2 <= 100));
  __CPROVER_assume((pub_r000367_5_1 >= (-100)) && (pub_r000367_5_1 <= 100));
  __CPROVER_assume((pub_r000367_5_2 >= (-100)) && (pub_r000367_5_2 <= 100));
  __CPROVER_assume((pub_r000367_6_1 >= (-100)) && (pub_r000367_6_1 <= 100));
  __CPROVER_assume((pub_r000367_6_2 >= (-100)) && (pub_r000367_6_2 <= 100));
  __CPROVER_assume((pub_r000367_7_1 >= (-100)) && (pub_r000367_7_1 <= 100));
  __CPROVER_assume((pub_r000367_7_2 >= (-100)) && (pub_r000367_7_2 <= 100));
  __CPROVER_assume((pub_r000367_8_1 >= (-100)) && (pub_r000367_8_1 <= 100));
  __CPROVER_assume((pub_r000367_8_2 >= (-100)) && (pub_r000367_8_2 <= 100));
  __CPROVER_assume((pub_r000367_9_1 >= (-100)) && (pub_r000367_9_1 <= 100));
  __CPROVER_assume((pub_r000367_9_2 >= (-100)) && (pub_r000367_9_2 <= 100));
  __CPROVER_assume((pub_r000367_10_1 >= (-100)) && (pub_r000367_10_1 <= 100));
  __CPROVER_assume((pub_r000367_10_2 >= (-100)) && (pub_r000367_10_2 <= 100));
  __CPROVER_assume((pub_r000367_11_1 >= (-100)) && (pub_r000367_11_1 <= 100));
  __CPROVER_assume((pub_r000367_11_2 >= (-100)) && (pub_r000367_11_2 <= 100));
  __CPROVER_assume((pub_r000367_12_1 >= (-100)) && (pub_r000367_12_1 <= 100));
  __CPROVER_assume((pub_r000367_12_2 >= (-100)) && (pub_r000367_12_2 <= 100));
  __CPROVER_assume((pub_r000367_13_1 >= (-100)) && (pub_r000367_13_1 <= 100));
  __CPROVER_assume((pub_r000367_13_2 >= (-100)) && (pub_r000367_13_2 <= 100));
  __CPROVER_assume((pub_r000367_14_1 >= (-100)) && (pub_r000367_14_1 <= 100));
  __CPROVER_assume((pub_r000367_14_2 >= (-100)) && (pub_r000367_14_2 <= 100));
  __CPROVER_assume((pub_r000367_15_1 >= (-100)) && (pub_r000367_15_1 <= 100));
  __CPROVER_assume((pub_r000367_15_2 >= (-100)) && (pub_r000367_15_2 <= 100));
  __CPROVER_assume((pub_r000367_16_1 >= (-100)) && (pub_r000367_16_1 <= 100));
  __CPROVER_assume((pub_r000367_16_2 >= (-100)) && (pub_r000367_16_2 <= 100));
  __CPROVER_assume((pub_r000367_17_1 >= (-100)) && (pub_r000367_17_1 <= 100));
  __CPROVER_assume((pub_r000367_17_2 >= (-100)) && (pub_r000367_17_2 <= 100));
  __CPROVER_assume((sec_r000367_0_1 >= 0) && (sec_r000367_0_1 <= 255));
  __CPROVER_assume((sec_r000367_0_2 >= 0) && (sec_r000367_0_2 <= 255));
  __CPROVER_assume((sec_r000367_1_1 >= 0) && (sec_r000367_1_1 <= 255));
  __CPROVER_assume((sec_r000367_1_2 >= 0) && (sec_r000367_1_2 <= 255));
  __CPROVER_assume((sec_r000367_2_1 >= 0) && (sec_r000367_2_1 <= 255));
  __CPROVER_assume((sec_r000367_2_2 >= 0) && (sec_r000367_2_2 <= 255));
  __CPROVER_assume((sec_r000367_3_1 >= 0) && (sec_r000367_3_1 <= 255));
  __CPROVER_assume((sec_r000367_3_2 >= 0) && (sec_r000367_3_2 <= 255));
  __CPROVER_assume((sec_r000367_4_1 >= 0) && (sec_r000367_4_1 <= 255));
  __CPROVER_assume((sec_r000367_4_2 >= 0) && (sec_r000367_4_2 <= 255));
  __CPROVER_assume((sec_r000367_5_1 >= 0) && (sec_r000367_5_1 <= 255));
  __CPROVER_assume((sec_r000367_5_2 >= 0) && (sec_r000367_5_2 <= 255));
  __CPROVER_assume((sec_r000367_6_1 >= 0) && (sec_r000367_6_1 <= 255));
  __CPROVER_assume((sec_r000367_6_2 >= 0) && (sec_r000367_6_2 <= 255));
  __CPROVER_assume((sec_r000367_7_1 >= 0) && (sec_r000367_7_1 <= 255));
  __CPROVER_assume((sec_r000367_7_2 >= 0) && (sec_r000367_7_2 <= 255));
  __CPROVER_assume((sec_r000367_8_1 >= 0) && (sec_r000367_8_1 <= 255));
  __CPROVER_assume((sec_r000367_8_2 >= 0) && (sec_r000367_8_2 <= 255));
  __CPROVER_assume((sec_r000367_9_1 >= 0) && (sec_r000367_9_1 <= 255));
  __CPROVER_assume((sec_r000367_9_2 >= 0) && (sec_r000367_9_2 <= 255));
  __CPROVER_assume((sec_r000367_10_1 >= 0) && (sec_r000367_10_1 <= 255));
  __CPROVER_assume((sec_r000367_10_2 >= 0) && (sec_r000367_10_2 <= 255));
  __CPROVER_assume((sec_r000367_11_1 >= 0) && (sec_r000367_11_1 <= 255));
  __CPROVER_assume((sec_r000367_11_2 >= 0) && (sec_r000367_11_2 <= 255));
  __CPROVER_assume((sec_r000367_12_1 >= 0) && (sec_r000367_12_1 <= 255));
  __CPROVER_assume((sec_r000367_12_2 >= 0) && (sec_r000367_12_2 <= 255));
  __CPROVER_assume((sec_r000367_13_1 >= 0) && (sec_r000367_13_1 <= 255));
  __CPROVER_assume((sec_r000367_13_2 >= 0) && (sec_r000367_13_2 <= 255));
  __CPROVER_assume((sec_r000367_14_1 >= 0) && (sec_r000367_14_1 <= 255));
  __CPROVER_assume((sec_r000367_14_2 >= 0) && (sec_r000367_14_2 <= 255));
  __CPROVER_assume((sec_r000367_15_1 >= 0) && (sec_r000367_15_1 <= 255));
  __CPROVER_assume((sec_r000367_15_2 >= 0) && (sec_r000367_15_2 <= 255));
  __CPROVER_assume((sec_r000367_16_1 >= 0) && (sec_r000367_16_1 <= 255));
  __CPROVER_assume((sec_r000367_16_2 >= 0) && (sec_r000367_16_2 <= 255));
  __CPROVER_assume((sec_r000367_17_1 >= 0) && (sec_r000367_17_1 <= 255));
  __CPROVER_assume((sec_r000367_17_2 >= 0) && (sec_r000367_17_2 <= 255));
  __CPROVER_assume((sec_r000367_18_1 >= 0) && (sec_r000367_18_1 <= 255));
  __CPROVER_assume((sec_r000367_18_2 >= 0) && (sec_r000367_18_2 <= 255));
  __CPROVER_assume((sec_r000367_19_1 >= 0) && (sec_r000367_19_1 <= 255));
  __CPROVER_assume((sec_r000367_19_2 >= 0) && (sec_r000367_19_2 <= 255));
  __CPROVER_assume((sec_r000367_20_1 >= 0) && (sec_r000367_20_1 <= 255));
  __CPROVER_assume((sec_r000367_20_2 >= 0) && (sec_r000367_20_2 <= 255));
  __CPROVER_assume((sec_r000367_21_1 >= 0) && (sec_r000367_21_1 <= 255));
  __CPROVER_assume((sec_r000367_21_2 >= 0) && (sec_r000367_21_2 <= 255));
  struct FilterState_R000367_6713_0 st_var_0_1 = {0};
  struct FilterState_R000367_6713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000367_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000367_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000367_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000367_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000367_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000367_0_2 + 7) & 15;
  struct MatrixBlock_R000367_6713_1 st_var_1_1 = {0};
  struct MatrixBlock_R000367_6713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000367_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000367_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000367_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000367_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000367_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000367_0_2 + 9) & 15;
  struct AudioFrame_R000367_6713_2 st_var_2_1 = {0};
  struct AudioFrame_R000367_6713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000367_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000367_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000367_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000367_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000367_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000367_0_2 + 11) & 15;
  union ColorPixel_R000367_6713_0 u_var_1;
  union ColorPixel_R000367_6713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 1) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 1) & 15;
  int stage_v_0_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_0_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= stage_v_0_1;
  chk_sum_2 ^= stage_v_0_2;
  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_2_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (7 & 31);
  int stage_v_2_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (7 & 31);
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= (stage_v_2_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_2_2 << 1) & 127;
  int stage_v_3_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (8 & 31);
  int stage_v_3_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (8 & 31);
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= (stage_v_3_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_3_2 << 1) & 127;
  int stage_v_4_1 = ((st_var_1_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_1_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 37)
    {
      chk_sum_1 ^= stage_v_4_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_4_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 37)
    {
      chk_sum_2 ^= stage_v_4_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_5_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_5_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_5_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_5_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_6_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (11 & 31);
  int stage_v_6_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (11 & 31);
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= (stage_v_6_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_6_2 << 1) & 127;
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (st_var_2_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_2_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 10) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = ((st_var_2_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_2_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 42)
    {
      chk_sum_1 ^= stage_v_11_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_11_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 42)
    {
      chk_sum_2 ^= stage_v_11_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = ((st_var_2_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_2_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 36)
    {
      chk_sum_1 ^= stage_v_17_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_17_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 36)
    {
      chk_sum_2 ^= stage_v_17_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = table_1[2];
  int stage_v_22_2 = table_2[2];
  table_1[2] = (table_1[3] + 45) & 63;
  table_2[2] = (table_2[3] + 45) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (st_var_2_1.buffer[0] ^ 26) & 3;
  int stage_v_23_2 = (st_var_2_2.buffer[0] ^ 26) & 3;
  switch (stage_v_23_1)
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

  switch (stage_v_23_2)
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

  int stage_v_24_1 = ((st_var_0_1.buffer[0] * 2) + 79) & 63;
  int stage_v_24_2 = ((st_var_0_2.buffer[0] * 2) + 79) & 63;
  if (stage_v_24_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_24_1) - 5) & 255;
    if (stage_v_24_1 > 46)
    {
      chk_sum_1 ^= stage_v_24_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_24_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_24_2) - 5) & 255;
    if (stage_v_24_2 > 46)
    {
      chk_sum_2 ^= stage_v_24_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
  int stage_v_26_1 = ((st_var_2_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_2_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 30)
    {
      chk_sum_1 ^= stage_v_26_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_26_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 30)
    {
      chk_sum_2 ^= stage_v_26_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_28_1 = ((stage_v_28_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_28_2 = ((stage_v_28_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (st_var_2_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_2_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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

  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 32) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 32) & 15;
  int stage_v_31_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_31_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= stage_v_31_1;
  chk_sum_2 ^= stage_v_31_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 33) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 33) & 15;
  int stage_v_32_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_32_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= stage_v_32_1;
  chk_sum_2 ^= stage_v_32_2;
  int stage_v_33_1 = (st_var_0_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_0_2.buffer[0] ^ 36) & 3;
  switch (stage_v_33_1)
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

  switch (stage_v_33_2)
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

  int stage_v_34_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_34_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_35_1 = table_1[3];
  int stage_v_35_2 = table_2[3];
  table_1[3] = (table_1[0] + 71) & 63;
  table_2[3] = (table_2[0] + 71) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  int stage_v_38_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_38_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_39_1 = ((st_var_0_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_0_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 36)
    {
      chk_sum_1 ^= stage_v_39_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_39_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 36)
    {
      chk_sum_2 ^= stage_v_39_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_40_1 = (st_var_1_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_1_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_41_1 = ((stage_v_41_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_41_2 = ((stage_v_41_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_42_1 = ((stage_v_42_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_42_2 = ((stage_v_42_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (48 & 31);
  int stage_v_43_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (48 & 31);
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= (stage_v_43_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_43_2 << 1) & 127;
  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_45_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_45_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_46_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_46_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_47_1 = ((st_var_2_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_2_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 53)
    {
      chk_sum_1 ^= stage_v_47_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_47_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 53)
    {
      chk_sum_2 ^= stage_v_47_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 50) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 50) & 15;
  int stage_v_49_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_49_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= stage_v_49_1;
  chk_sum_2 ^= stage_v_49_2;
  int stage_v_50_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_50_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_50_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_50_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 52) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 52) & 15;
  int stage_v_51_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_51_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= stage_v_51_1;
  chk_sum_2 ^= stage_v_51_2;
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
  int stage_v_53_1 = table_1[1];
  int stage_v_53_2 = table_2[1];
  table_1[1] = (table_1[2] + 107) & 63;
  table_2[1] = (table_2[2] + 107) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_54_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_54_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_54_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_55_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (60 & 31);
  int stage_v_55_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (60 & 31);
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= (stage_v_55_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_55_2 << 1) & 127;
  int stage_v_56_1 = table_1[0];
  int stage_v_56_2 = table_2[0];
  table_1[0] = (table_1[1] + 113) & 63;
  table_2[0] = (table_2[1] + 113) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_57_1 = ((stage_v_57_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (63 & 31);
  int stage_v_58_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (63 & 31);
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= (stage_v_58_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_58_2 << 1) & 127;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_59_1 = ((stage_v_59_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_59_2 = ((stage_v_59_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000367_11_1 & 1) != 0)
  {
    if ((sec_r000367_14_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000367_17_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000367_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000367_17_1 + 7) & 127;
  }
  if ((sec_r000367_11_2 & 1) != 0)
  {
    if ((sec_r000367_14_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000367_17_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000367_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000367_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000367_5_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000367_13_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000367_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000367_13_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000367_5_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000367_13_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000367_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000367_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000367_13_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000367_15_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000367_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000367_15_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000367_13_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000367_15_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000367_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000367_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((sec_r000367_6_1 & 1) != 0)
  {
    if ((sec_r000367_14_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000367_0_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000367_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000367_0_1 + 7) & 127;
  }
  if ((sec_r000367_6_2 & 1) != 0)
  {
    if ((sec_r000367_14_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000367_0_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000367_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000367_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000367_4_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000367_13_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000367_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000367_13_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000367_4_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000367_13_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000367_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000367_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((sec_r000367_10_1 & 1) != 0)
  {
    if ((sec_r000367_12_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000367_2_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000367_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000367_2_1 + 7) & 127;
  }
  if ((sec_r000367_10_2 & 1) != 0)
  {
    if ((sec_r000367_12_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000367_2_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000367_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000367_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000367_12_1 & 1) != 0)
  {
    if ((sec_r000367_19_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000367_16_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000367_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000367_16_1 + 7) & 127;
  }
  if ((sec_r000367_12_2 & 1) != 0)
  {
    if ((sec_r000367_19_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000367_16_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000367_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000367_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000367_4_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000367_7_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000367_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000367_7_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000367_4_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000367_7_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000367_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000367_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((sec_r000367_21_1 & 1) != 0)
  {
    if ((sec_r000367_16_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000367_16_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000367_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000367_16_1 + 7) & 127;
  }
  if ((sec_r000367_21_2 & 1) != 0)
  {
    if ((sec_r000367_16_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000367_16_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000367_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000367_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000367_13_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000367_3_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000367_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000367_3_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000367_13_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000367_3_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000367_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000367_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000367_1_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000367_6_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000367_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000367_6_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000367_1_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000367_6_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000367_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000367_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000367_7_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000367_8_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000367_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000367_8_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000367_7_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000367_8_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000367_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000367_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000367_6_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000367_5_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000367_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000367_5_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000367_6_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000367_5_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000367_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000367_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000367_18_1 & 1) != 0)
  {
    if ((sec_r000367_1_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000367_3_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000367_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000367_3_1 + 7) & 127;
  }
  if ((sec_r000367_18_2 & 1) != 0)
  {
    if ((sec_r000367_1_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000367_3_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000367_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000367_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000367_21_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000367_10_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000367_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000367_10_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000367_21_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000367_10_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000367_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000367_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000367_14_1 & 1) != 0)
  {
    if ((sec_r000367_2_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000367_1_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000367_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000367_1_1 + 7) & 127;
  }
  if ((sec_r000367_14_2 & 1) != 0)
  {
    if ((sec_r000367_2_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000367_1_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000367_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000367_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000367_12_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000367_8_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000367_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000367_8_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000367_12_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000367_8_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000367_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000367_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000367_11_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000367_8_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000367_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000367_8_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000367_11_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000367_8_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000367_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000367_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000367_4_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000367_11_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000367_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000367_11_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000367_4_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000367_11_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000367_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000367_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000367_1_1 & 1) != 0)
  {
    if ((sec_r000367_16_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000367_1_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000367_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000367_1_1 + 7) & 127;
  }
  if ((sec_r000367_1_2 & 1) != 0)
  {
    if ((sec_r000367_16_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000367_1_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000367_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000367_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000367_7_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000367_1_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000367_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000367_1_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000367_7_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000367_1_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000367_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000367_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000367_11_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000367_11_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000367_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000367_11_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000367_11_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000367_11_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000367_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000367_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000367_1_1 & 1) != 0)
  {
    if ((sec_r000367_7_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000367_15_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000367_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000367_15_1 + 7) & 127;
  }
  if ((sec_r000367_1_2 & 1) != 0)
  {
    if ((sec_r000367_7_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000367_15_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000367_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000367_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000367_12_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000367_17_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000367_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000367_17_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000367_12_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000367_17_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000367_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000367_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000367_21_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000367_16_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000367_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000367_16_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000367_21_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000367_16_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000367_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000367_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000367_21_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000367_7_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000367_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000367_7_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000367_21_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000367_7_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000367_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000367_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000367_3_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000367_1_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000367_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000367_1_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000367_3_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000367_1_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000367_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000367_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((sec_r000367_9_1 & 1) != 0)
  {
    if ((sec_r000367_18_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000367_7_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000367_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000367_7_1 + 7) & 127;
  }
  if ((sec_r000367_9_2 & 1) != 0)
  {
    if ((sec_r000367_18_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000367_7_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000367_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000367_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000367_3_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000367_6_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000367_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000367_6_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000367_3_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000367_6_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000367_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000367_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000367_5_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000367_3_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000367_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000367_3_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000367_5_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000367_3_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000367_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000367_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000367_18_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000367_14_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000367_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000367_14_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000367_18_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000367_14_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000367_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000367_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000367_17_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000367_10_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000367_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000367_10_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000367_17_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000367_10_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000367_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000367_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000367_13_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000367_5_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000367_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000367_5_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000367_13_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000367_5_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000367_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000367_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000367_5_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000367_10_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000367_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000367_10_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000367_5_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000367_10_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000367_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000367_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000367_6_1 & 1) != 0)
  {
    if ((sec_r000367_9_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000367_13_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000367_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000367_13_1 + 7) & 127;
  }
  if ((sec_r000367_6_2 & 1) != 0)
  {
    if ((sec_r000367_9_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000367_13_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000367_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000367_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000367_10_1 & 1) != 0)
  {
    if ((sec_r000367_2_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000367_4_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000367_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000367_4_1 + 7) & 127;
  }
  if ((sec_r000367_10_2 & 1) != 0)
  {
    if ((sec_r000367_2_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000367_4_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000367_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000367_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000367_6_1 & 1) != 0)
  {
    if ((sec_r000367_4_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000367_8_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000367_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000367_8_1 + 7) & 127;
  }
  if ((sec_r000367_6_2 & 1) != 0)
  {
    if ((sec_r000367_4_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000367_8_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000367_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000367_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000367_12_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000367_14_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000367_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000367_14_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000367_12_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000367_14_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000367_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000367_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000367_16_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000367_9_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000367_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000367_9_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000367_16_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000367_9_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000367_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000367_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000367_21_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000367_11_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000367_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000367_11_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000367_21_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000367_11_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000367_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000367_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000367_9_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000367_12_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000367_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000367_12_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000367_9_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000367_12_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000367_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000367_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000367_5_1 & 1) != 0)
  {
    if ((sec_r000367_9_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000367_5_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000367_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000367_5_1 + 7) & 127;
  }
  if ((sec_r000367_5_2 & 1) != 0)
  {
    if ((sec_r000367_9_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000367_5_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000367_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000367_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000367_20_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000367_16_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000367_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000367_16_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000367_20_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000367_16_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000367_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000367_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000367_14_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000367_4_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000367_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000367_4_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000367_14_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000367_4_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000367_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000367_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000367_1_1 & 1) != 0)
  {
    if ((sec_r000367_5_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000367_8_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000367_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000367_8_1 + 7) & 127;
  }
  if ((sec_r000367_1_2 & 1) != 0)
  {
    if ((sec_r000367_5_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000367_8_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000367_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000367_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000367_21_1 & 1) != 0)
  {
    if ((sec_r000367_2_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000367_15_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000367_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000367_15_1 + 7) & 127;
  }
  if ((sec_r000367_21_2 & 1) != 0)
  {
    if ((sec_r000367_2_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000367_15_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000367_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000367_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000367_7_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000367_5_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000367_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000367_5_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000367_7_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000367_5_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000367_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000367_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000367_9_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000367_11_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000367_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000367_11_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000367_9_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000367_11_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000367_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000367_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000367_8_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000367_14_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000367_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000367_14_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000367_8_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000367_14_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000367_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000367_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000367_9_1 & 1) != 0)
  {
    if ((sec_r000367_5_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000367_10_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000367_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000367_10_1 + 7) & 127;
  }
  if ((sec_r000367_9_2 & 1) != 0)
  {
    if ((sec_r000367_5_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000367_10_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000367_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000367_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000367_5_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000367_14_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000367_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000367_14_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000367_5_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000367_14_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000367_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000367_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000367_15_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000367_1_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000367_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000367_1_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000367_15_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000367_1_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000367_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000367_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000367_17_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000367_17_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000367_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000367_17_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000367_17_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000367_17_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000367_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000367_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000367_10_1 & 1) != 0)
  {
    if ((sec_r000367_14_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000367_12_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000367_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000367_12_1 + 7) & 127;
  }
  if ((sec_r000367_10_2 & 1) != 0)
  {
    if ((sec_r000367_14_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000367_12_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000367_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000367_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000367_10_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000367_17_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000367_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000367_17_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000367_10_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000367_17_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000367_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000367_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000367_20_1 & 1) != 0)
  {
    if ((sec_r000367_8_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000367_1_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000367_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000367_1_1 + 7) & 127;
  }
  if ((sec_r000367_20_2 & 1) != 0)
  {
    if ((sec_r000367_8_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000367_1_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000367_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000367_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000367_14_1 & 1) != 0)
  {
    if ((sec_r000367_21_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000367_2_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000367_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000367_2_1 + 7) & 127;
  }
  if ((sec_r000367_14_2 & 1) != 0)
  {
    if ((sec_r000367_21_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000367_2_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000367_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000367_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000367_16_1 & 1) != 0)
  {
    if ((sec_r000367_2_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000367_2_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000367_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000367_2_1 + 7) & 127;
  }
  if ((sec_r000367_16_2 & 1) != 0)
  {
    if ((sec_r000367_2_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000367_2_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000367_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000367_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000367_4_1 & 1) != 0)
  {
    if ((sec_r000367_2_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000367_0_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000367_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000367_0_1 + 7) & 127;
  }
  if ((sec_r000367_4_2 & 1) != 0)
  {
    if ((sec_r000367_2_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000367_0_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000367_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000367_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000367_16_1 & 1) != 0)
  {
    if ((sec_r000367_4_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000367_4_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000367_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000367_4_1 + 7) & 127;
  }
  if ((sec_r000367_16_2 & 1) != 0)
  {
    if ((sec_r000367_4_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000367_4_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000367_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000367_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000367_20_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000367_10_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000367_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000367_10_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000367_20_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000367_10_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000367_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000367_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000367_6_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000367_15_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000367_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000367_15_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000367_6_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000367_15_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000367_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000367_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000367_9_1 & 1) != 0)
  {
    if ((sec_r000367_5_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000367_11_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000367_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000367_11_1 + 7) & 127;
  }
  if ((sec_r000367_9_2 & 1) != 0)
  {
    if ((sec_r000367_5_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000367_11_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000367_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000367_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000367_0_1 & 1) != 0)
  {
    if ((sec_r000367_13_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000367_1_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000367_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000367_1_1 + 7) & 127;
  }
  if ((sec_r000367_0_2 & 1) != 0)
  {
    if ((sec_r000367_13_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000367_1_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000367_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000367_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000367_1_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000367_11_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000367_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000367_11_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000367_1_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000367_11_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000367_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000367_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((sec_r000367_9_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000367_11_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000367_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000367_11_1 + 7) & 127;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((sec_r000367_9_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000367_11_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000367_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000367_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000367_1_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000367_11_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000367_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000367_11_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000367_1_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000367_11_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000367_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000367_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000367_4_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000367_13_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000367_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000367_13_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000367_4_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000367_13_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000367_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000367_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000367_20_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000367_13_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000367_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000367_13_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000367_20_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000367_13_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000367_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000367_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000367_11_1 & 1) != 0)
  {
    if ((sec_r000367_16_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000367_8_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000367_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000367_8_1 + 7) & 127;
  }
  if ((sec_r000367_11_2 & 1) != 0)
  {
    if ((sec_r000367_16_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000367_8_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000367_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000367_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000367_9_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000367_14_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000367_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000367_14_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000367_9_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000367_14_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000367_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000367_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000367_1_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000367_6_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000367_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000367_6_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000367_1_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000367_6_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000367_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000367_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000367_4_1 & 1) != 0)
  {
    if ((sec_r000367_20_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000367_3_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000367_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000367_3_1 + 7) & 127;
  }
  if ((sec_r000367_4_2 & 1) != 0)
  {
    if ((sec_r000367_20_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000367_3_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000367_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000367_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000367_14_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000367_2_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000367_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000367_2_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000367_14_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000367_2_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000367_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000367_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000367_18_1 & 1) != 0)
  {
    if ((sec_r000367_17_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000367_7_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000367_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000367_7_1 + 7) & 127;
  }
  if ((sec_r000367_18_2 & 1) != 0)
  {
    if ((sec_r000367_17_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000367_7_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000367_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000367_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000367_6_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000367_11_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000367_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000367_11_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000367_6_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000367_11_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000367_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000367_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000367_8_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000367_1_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000367_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000367_1_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000367_8_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000367_1_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000367_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000367_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000367_20_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000367_2_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000367_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000367_2_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000367_20_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000367_2_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000367_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000367_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((sec_r000367_14_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000367_0_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000367_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000367_0_1 + 7) & 127;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((sec_r000367_14_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000367_0_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000367_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000367_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000367_3_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000367_3_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000367_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000367_3_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000367_3_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000367_3_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000367_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000367_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000367_6_1 != sec_r000367_6_2);
  __CPROVER_assume(pub_r000367_10_1 == pub_r000367_10_2);
  __CPROVER_assume(sec_r000367_4_1 != sec_r000367_4_2);
  __CPROVER_assume(sec_r000367_18_1 != sec_r000367_18_2);
  __CPROVER_assume(sec_r000367_8_1 != sec_r000367_8_2);
  __CPROVER_assume(sec_r000367_13_1 != sec_r000367_13_2);
  __CPROVER_assume(sec_r000367_21_1 != sec_r000367_21_2);
  __CPROVER_assume(sec_r000367_14_1 != sec_r000367_14_2);
  __CPROVER_assume(pub_r000367_0_1 == pub_r000367_0_2);
  __CPROVER_assume(sec_r000367_0_1 != sec_r000367_0_2);
  __CPROVER_assume(sec_r000367_2_1 != sec_r000367_2_2);
  __CPROVER_assume(sec_r000367_3_1 != sec_r000367_3_2);
  __CPROVER_assume(pub_r000367_15_1 == pub_r000367_15_2);
  __CPROVER_assume(pub_r000367_2_1 == pub_r000367_2_2);
  __CPROVER_assume(sec_r000367_7_1 != sec_r000367_7_2);
  __CPROVER_assume(sec_r000367_11_1 != sec_r000367_11_2);
  __CPROVER_assume(pub_r000367_8_1 == pub_r000367_8_2);
  __CPROVER_assume(pub_r000367_16_1 == pub_r000367_16_2);
  __CPROVER_assume(sec_r000367_10_1 != sec_r000367_10_2);
  __CPROVER_assume(pub_r000367_17_1 == pub_r000367_17_2);
  __CPROVER_assume(pub_r000367_4_1 == pub_r000367_4_2);
  __CPROVER_assume(pub_r000367_13_1 == pub_r000367_13_2);
  __CPROVER_assume(pub_r000367_6_1 == pub_r000367_6_2);
  __CPROVER_assume(sec_r000367_17_1 != sec_r000367_17_2);
  __CPROVER_assume(pub_r000367_7_1 == pub_r000367_7_2);
  __CPROVER_assume(pub_r000367_14_1 == pub_r000367_14_2);
  __CPROVER_assume(pub_r000367_11_1 == pub_r000367_11_2);
  __CPROVER_assume(pub_r000367_5_1 == pub_r000367_5_2);
  __CPROVER_assume(sec_r000367_9_1 != sec_r000367_9_2);
  __CPROVER_assume(pub_r000367_12_1 == pub_r000367_12_2);
  __CPROVER_assume(sec_r000367_1_1 != sec_r000367_1_2);
  __CPROVER_assume(sec_r000367_16_1 != sec_r000367_16_2);
  __CPROVER_assume(sec_r000367_19_1 != sec_r000367_19_2);
  __CPROVER_assume(pub_r000367_9_1 == pub_r000367_9_2);
  __CPROVER_assume(sec_r000367_15_1 != sec_r000367_15_2);
  __CPROVER_assume(sec_r000367_5_1 != sec_r000367_5_2);
  __CPROVER_assume(sec_r000367_12_1 != sec_r000367_12_2);
  __CPROVER_assume(pub_r000367_1_1 == pub_r000367_1_2);
  __CPROVER_assume(pub_r000367_3_1 == pub_r000367_3_2);
  __CPROVER_assume(sec_r000367_20_1 != sec_r000367_20_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.stride == st_var_1_2.stride);
  assert(st_var_1_1.trace == st_var_1_2.trace);
  assert(st_var_1_1.determinant == st_var_1_2.determinant);
  assert(st_var_1_1.density == st_var_1_2.density);
  assert(st_var_1_1.scale == st_var_1_2.scale);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.peak == st_var_2_2.peak);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.sample_rate == st_var_2_2.sample_rate);
  assert(st_var_2_1.channels == st_var_2_2.channels);
  assert(st_var_2_1.rms == st_var_2_2.rms);
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
}


