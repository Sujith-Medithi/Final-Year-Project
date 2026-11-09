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
struct AudioFrame_R001124_2413_0
{
  short sample_rate;
  int rms;
  short channels;
  int peak;
  int buffer[3];
};
struct FilterState_R001124_2413_1
{
  int cutoff;
  int prev_in;
  unsigned char prev_out;
  int mode;
  short gain_db;
  int buffer[3];
};
struct MatrixBlock_R001124_2413_2
{
  short density;
  short scale;
  short stride;
  int dim;
  int buffer[3];
};
union RegisterBank_R001124_2413_0
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
void fn_R001124_2413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st_1 = {0};
  struct AudioFrame_R001124_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int cursor_73_1 = 0;
  int cursor_73_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_73_1 = ((cursor_73_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_73_2 = ((cursor_73_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_73_1) & 127;
    acc_2 = (acc_2 + cursor_73_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_83_1 = local_arr_1[aux_1 % 3];
  int segment_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_83_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_73_1 == cursor_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_83_1 == segment_83_2);
}

int fn_R001124_2413_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int cursor_73 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_73 = ((cursor_73 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_73) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int segment_83 = local_arr[aux % 3];
  acc = (acc + (segment_83 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001124_2413_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st_1 = {0};
  struct AudioFrame_R001124_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int pivot_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_10_1)
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

  switch (pivot_10_2)
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
  int sample_15_1 = local_arr_1[aux_1 % 3];
  int sample_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_15_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_10_1 == pivot_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_15_1 == sample_15_2);
}

int fn_R001124_2413_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int pivot_10 = (aux + st.buffer[1]) & 3;
  switch (pivot_10)
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
  int sample_15 = local_arr[aux % 3];
  acc = (acc + (sample_15 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001124_2413_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001124_2413_1 st_1 = {0};
  struct FilterState_R001124_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int tracker_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_78_1) & 63;
  aux_2 = (aux_2 + tracker_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_20_1)
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

  switch (quantum_20_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_71_1 > 12)
  {
    acc_1 = ((acc_1 + (tracker_71_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_71_2 > 12)
  {
    acc_2 = ((acc_2 + (tracker_71_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_71_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_78_1 == tracker_78_2);
  assert(quantum_20_1 == quantum_20_2);
  assert(tracker_71_1 == tracker_71_2);
}

int fn_R001124_2413_2(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001124_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int tracker_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_78) & 63;
  acc ^= aux;
  int quantum_20 = (aux + st.buffer[1]) & 3;
  switch (quantum_20)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_71 > 12)
  {
    acc = ((acc + (tracker_71 * 2)) + 5) & 127;
    aux ^= tracker_71 & 15;
  }
  else
  {
    acc = ((acc - tracker_71) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001124_2413_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st_1 = {0};
  struct AudioFrame_R001124_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_57_1) & 63;
  aux_2 = (aux_2 + window_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_57_1 == window_57_2);
}

int fn_R001124_2413_3(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_57) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001124_2413_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st_1 = {0};
  struct AudioFrame_R001124_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_51_1 = local_arr_1[aux_1 % 3];
  int threshold_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_51_2 * 2)) & 127;
  int mask_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_14_1) & 63;
  aux_2 = (aux_2 + mask_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_49_1 > 50)
  {
    acc_1 = ((acc_1 + (sample_49_1 * 2)) + 5) & 127;
    aux_1 ^= sample_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_49_2 > 50)
  {
    acc_2 = ((acc_2 + (sample_49_2 * 2)) + 5) & 127;
    aux_2 ^= sample_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_49_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_51_1 == threshold_51_2);
  assert(mask_14_1 == mask_14_2);
  assert(sample_49_1 == sample_49_2);
}

int fn_R001124_2413_4(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int threshold_51 = local_arr[aux % 3];
  acc = (acc + (threshold_51 * 2)) & 127;
  int mask_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_14) & 63;
  acc ^= aux;
  int sample_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_49 > 50)
  {
    acc = ((acc + (sample_49 * 2)) + 5) & 127;
    aux ^= sample_49 & 15;
  }
  else
  {
    acc = ((acc - sample_49) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001124_2413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st_1 = {0};
  struct AudioFrame_R001124_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_45_1 > 47)
  {
    acc_1 = ((acc_1 + (accumulator_45_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_45_2 > 47)
  {
    acc_2 = ((acc_2 + (accumulator_45_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_11_1 = 0;
  int parity_11_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_11_1 = ((parity_11_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_11_2 = ((parity_11_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_11_1) & 127;
    acc_2 = (acc_2 + parity_11_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_73_1 = local_arr_1[aux_1 % 3];
  int mask_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_73_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_45_1 == accumulator_45_2);
  assert(parity_11_1 == parity_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_73_1 == mask_73_2);
}

int fn_R001124_2413_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_45 > 47)
  {
    acc = ((acc + (accumulator_45 * 2)) + 5) & 127;
    aux ^= accumulator_45 & 15;
  }
  else
  {
    acc = ((acc - accumulator_45) + 11) & 127;
    aux += 3;
  }
  int parity_11 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_11 = ((parity_11 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_11) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int mask_73 = local_arr[aux % 3];
  acc = (acc + (mask_73 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001124_2413_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001124_2413_1 st_1 = {0};
  struct FilterState_R001124_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_38_1 > 12)
  {
    acc_1 = ((acc_1 + (segment_38_1 * 2)) + 5) & 127;
    aux_1 ^= segment_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_38_2 > 12)
  {
    acc_2 = ((acc_2 + (segment_38_2 * 2)) + 5) & 127;
    aux_2 ^= segment_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_38_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_38_1 == segment_38_2);
}

int fn_R001124_2413_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001124_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_38 > 12)
  {
    acc = ((acc + (segment_38 * 2)) + 5) & 127;
    aux ^= segment_38 & 15;
  }
  else
  {
    acc = ((acc - segment_38) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001124_2413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st_1 = {0};
  struct AudioFrame_R001124_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int residue_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_30_1 > 13)
  {
    acc_1 = ((acc_1 + (residue_30_1 * 2)) + 5) & 127;
    aux_1 ^= residue_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_30_2 > 13)
  {
    acc_2 = ((acc_2 + (residue_30_2 * 2)) + 5) & 127;
    aux_2 ^= residue_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_30_2) + 11) & 127;
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_30_1 == residue_30_2);
  assert(metric_15_1 == metric_15_2);
}

int fn_R001124_2413_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int residue_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_30 > 13)
  {
    acc = ((acc + (residue_30 * 2)) + 5) & 127;
    aux ^= residue_30 & 15;
  }
  else
  {
    acc = ((acc - residue_30) + 11) & 127;
    aux += 3;
  }
  int metric_15 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_15 = ((metric_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_15) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001124_2413_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001124_2413_1 st_1 = {0};
  struct FilterState_R001124_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int threshold_52_1 = 0;
  int threshold_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_52_1 = ((threshold_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_52_2 = ((threshold_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_52_1) & 127;
    acc_2 = (acc_2 + threshold_52_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_60_1 = local_arr_1[aux_1 % 3];
  int metric_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_60_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_23_1)
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

  switch (pivot_23_2)
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
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_52_1 == threshold_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_60_1 == metric_60_2);
  assert(pivot_23_1 == pivot_23_2);
}

int fn_R001124_2413_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001124_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int threshold_52 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_52 = ((threshold_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_52) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int metric_60 = local_arr[aux % 3];
  acc = (acc + (metric_60 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_23 = (aux + st.buffer[1]) & 3;
  switch (pivot_23)
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

void fn_R001124_2413_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001124_2413_1 st_1 = {0};
  struct FilterState_R001124_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int delta_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_19_1 > 22)
  {
    acc_1 = ((acc_1 + (delta_19_1 * 2)) + 5) & 127;
    aux_1 ^= delta_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_19_2 > 22)
  {
    acc_2 = ((acc_2 + (delta_19_2 * 2)) + 5) & 127;
    aux_2 ^= delta_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_43_1)
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

  switch (pivot_43_2)
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
  int coefficient_88_1 = local_arr_1[aux_1 % 3];
  int coefficient_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_88_2 * 2)) & 127;
  int metric_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_63_1) & 63;
  aux_2 = (aux_2 + metric_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_19_1 == delta_19_2);
  assert(pivot_43_1 == pivot_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_88_1 == coefficient_88_2);
  assert(metric_63_1 == metric_63_2);
}

int fn_R001124_2413_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001124_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int delta_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_19 > 22)
  {
    acc = ((acc + (delta_19 * 2)) + 5) & 127;
    aux ^= delta_19 & 15;
  }
  else
  {
    acc = ((acc - delta_19) + 11) & 127;
    aux += 3;
  }
  int pivot_43 = (aux + st.buffer[1]) & 3;
  switch (pivot_43)
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
  int coefficient_88 = local_arr[aux % 3];
  acc = (acc + (coefficient_88 * 2)) & 127;
  int metric_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_63) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001124_2413_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001124_2413_2 st_1 = {0};
  struct MatrixBlock_R001124_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_94_1 = local_arr_1[aux_1 % 3];
  int offset_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_94_2 * 2)) & 127;
  int delta_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_77_1)
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

  switch (delta_77_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_94_1 == offset_94_2);
  assert(delta_77_1 == delta_77_2);
}

int fn_R001124_2413_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001124_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int offset_94 = local_arr[aux % 3];
  acc = (acc + (offset_94 * 2)) & 127;
  int delta_77 = (aux + st.buffer[1]) & 3;
  switch (delta_77)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001124_2413_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001124_2413_2 st_1 = {0};
  struct MatrixBlock_R001124_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int weight_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_76_1 > 25)
  {
    acc_1 = ((acc_1 + (weight_76_1 * 2)) + 5) & 127;
    aux_1 ^= weight_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_76_2 > 25)
  {
    acc_2 = ((acc_2 + (weight_76_2 * 2)) + 5) & 127;
    aux_2 ^= weight_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_45_1 = local_arr_1[aux_1 % 3];
  int parity_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_45_2 * 2)) & 127;
  int delta_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_54_1) & 63;
  aux_2 = (aux_2 + delta_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_76_1 == weight_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_45_1 == parity_45_2);
  assert(delta_54_1 == delta_54_2);
}

int fn_R001124_2413_11(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001124_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int weight_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_76 > 25)
  {
    acc = ((acc + (weight_76 * 2)) + 5) & 127;
    aux ^= weight_76 & 15;
  }
  else
  {
    acc = ((acc - weight_76) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_45 = local_arr[aux % 3];
  acc = (acc + (parity_45 * 2)) & 127;
  int delta_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_54) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001124_2413_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st_1 = {0};
  struct AudioFrame_R001124_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_93_1)
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

  switch (scale_93_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_93_1 == scale_93_2);
}

int fn_R001124_2413_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_93 = (aux + st.buffer[1]) & 3;
  switch (scale_93)
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

void fn_R001124_2413_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001124_2413_2 st_1 = {0};
  struct MatrixBlock_R001124_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_35_1 = 0;
  int residue_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_35_1 = ((residue_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_35_2 = ((residue_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_35_1) & 127;
    acc_2 = (acc_2 + residue_35_2) & 127;
  }

  int tracker_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_28_1) & 63;
  aux_2 = (aux_2 + tracker_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_92_1 > 50)
  {
    acc_1 = ((acc_1 + (index_reg_92_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_92_2 > 50)
  {
    acc_2 = ((acc_2 + (index_reg_92_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_92_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_35_1 == residue_35_2);
  assert(tracker_28_1 == tracker_28_2);
  assert(index_reg_92_1 == index_reg_92_2);
}

int fn_R001124_2413_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001124_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_35 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_35 = ((residue_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_35) & 127;
  }

  int tracker_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_28) & 63;
  acc ^= aux;
  int index_reg_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_92 > 50)
  {
    acc = ((acc + (index_reg_92 * 2)) + 5) & 127;
    aux ^= index_reg_92 & 15;
  }
  else
  {
    acc = ((acc - index_reg_92) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001124_2413_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st_1 = {0};
  struct AudioFrame_R001124_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int scale_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_68_1 > 22)
  {
    acc_1 = ((acc_1 + (scale_68_1 * 2)) + 5) & 127;
    aux_1 ^= scale_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_68_2 > 22)
  {
    acc_2 = ((acc_2 + (scale_68_2 * 2)) + 5) & 127;
    aux_2 ^= scale_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_37_1 = 0;
  int checksum_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_37_1 = ((checksum_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_37_2 = ((checksum_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_37_1) & 127;
    acc_2 = (acc_2 + checksum_37_2) & 127;
  }

  int damping_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_55_1) & 63;
  aux_2 = (aux_2 + damping_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_17_1 = local_arr_1[aux_1 % 3];
  int mask_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_17_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_68_1 == scale_68_2);
  assert(checksum_37_1 == checksum_37_2);
  assert(damping_55_1 == damping_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_17_1 == mask_17_2);
}

int fn_R001124_2413_14(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int scale_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_68 > 22)
  {
    acc = ((acc + (scale_68 * 2)) + 5) & 127;
    aux ^= scale_68 & 15;
  }
  else
  {
    acc = ((acc - scale_68) + 11) & 127;
    aux += 3;
  }
  int checksum_37 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_37 = ((checksum_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_37) & 127;
  }

  int damping_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_55) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int mask_17 = local_arr[aux % 3];
  acc = (acc + (mask_17 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001124_2413_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001124_2413_1 st_1 = {0};
  struct FilterState_R001124_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_59_1 = local_arr_1[aux_1 % 3];
  int parity_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_59_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_22_1)
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

  switch (sample_22_2)
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

  int threshold_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_69_1 > 25)
  {
    acc_1 = ((acc_1 + (threshold_69_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_69_2 > 25)
  {
    acc_2 = ((acc_2 + (threshold_69_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_69_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_59_1 == parity_59_2);
  assert(sample_22_1 == sample_22_2);
  assert(threshold_69_1 == threshold_69_2);
}

int fn_R001124_2413_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001124_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int parity_59 = local_arr[aux % 3];
  acc = (acc + (parity_59 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_22 = (aux + st.buffer[1]) & 3;
  switch (sample_22)
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

  int threshold_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_69 > 25)
  {
    acc = ((acc + (threshold_69 * 2)) + 5) & 127;
    aux ^= threshold_69 & 15;
  }
  else
  {
    acc = ((acc - threshold_69) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001124_2413_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001124_2413_2 st_1 = {0};
  struct MatrixBlock_R001124_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int margin_86_1 = 0;
  int margin_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_86_1 = ((margin_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_86_2 = ((margin_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_86_1) & 127;
    acc_2 = (acc_2 + margin_86_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_35_1 = local_arr_1[aux_1 % 3];
  int scale_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_35_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_86_1 == margin_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_35_1 == scale_35_2);
}

int fn_R001124_2413_16(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001124_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int margin_86 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_86 = ((margin_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_86) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int scale_35 = local_arr[aux % 3];
  acc = (acc + (scale_35 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001124_2413_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st_1 = {0};
  struct AudioFrame_R001124_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int mask_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_50_1 > 22)
  {
    acc_1 = ((acc_1 + (mask_50_1 * 2)) + 5) & 127;
    aux_1 ^= mask_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_50_2 > 22)
  {
    acc_2 = ((acc_2 + (mask_50_2 * 2)) + 5) & 127;
    aux_2 ^= mask_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_67_1) & 63;
  aux_2 = (aux_2 + anchor_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_52_1 = local_arr_1[aux_1 % 3];
  int coefficient_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_52_2 * 2)) & 127;
  int vector_50_1 = 0;
  int vector_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_50_1 = ((vector_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_50_2 = ((vector_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_50_1) & 127;
    acc_2 = (acc_2 + vector_50_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_50_1 == mask_50_2);
  assert(anchor_67_1 == anchor_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_52_1 == coefficient_52_2);
  assert(vector_50_1 == vector_50_2);
}

int fn_R001124_2413_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int mask_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_50 > 22)
  {
    acc = ((acc + (mask_50 * 2)) + 5) & 127;
    aux ^= mask_50 & 15;
  }
  else
  {
    acc = ((acc - mask_50) + 11) & 127;
    aux += 3;
  }
  int anchor_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_67) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int coefficient_52 = local_arr[aux % 3];
  acc = (acc + (coefficient_52 * 2)) & 127;
  int vector_50 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_50 = ((vector_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_50) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001124_2413_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001124_2413_1 st_1 = {0};
  struct FilterState_R001124_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int metric_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_72_1 > 34)
  {
    acc_1 = ((acc_1 + (metric_72_1 * 2)) + 5) & 127;
    aux_1 ^= metric_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_72_2 > 34)
  {
    acc_2 = ((acc_2 + (metric_72_2 * 2)) + 5) & 127;
    aux_2 ^= metric_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_72_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_79_1) & 63;
  aux_2 = (aux_2 + scale_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_86_1 = local_arr_1[aux_1 % 3];
  int quantum_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_86_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_72_1 == metric_72_2);
  assert(scale_79_1 == scale_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_86_1 == quantum_86_2);
}

int fn_R001124_2413_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001124_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int metric_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_72 > 34)
  {
    acc = ((acc + (metric_72 * 2)) + 5) & 127;
    aux ^= metric_72 & 15;
  }
  else
  {
    acc = ((acc - metric_72) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_79) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quantum_86 = local_arr[aux % 3];
  acc = (acc + (quantum_86 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001124_2413_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001124_2413_1 st_1 = {0};
  struct FilterState_R001124_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_15_1 = 0;
  int bound_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_15_1 = ((bound_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_15_2 = ((bound_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_15_1) & 127;
    acc_2 = (acc_2 + bound_15_2) & 127;
  }

  int window_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_36_1 > 39)
  {
    acc_1 = ((acc_1 + (window_36_1 * 2)) + 5) & 127;
    aux_1 ^= window_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_36_2 > 39)
  {
    acc_2 = ((acc_2 + (window_36_2 * 2)) + 5) & 127;
    aux_2 ^= window_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_43_1) & 63;
  aux_2 = (aux_2 + delta_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_15_1 == bound_15_2);
  assert(window_36_1 == window_36_2);
  assert(delta_43_1 == delta_43_2);
}

int fn_R001124_2413_19(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001124_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_15 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_15 = ((bound_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_15) & 127;
  }

  int window_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_36 > 39)
  {
    acc = ((acc + (window_36 * 2)) + 5) & 127;
    aux ^= window_36 & 15;
  }
  else
  {
    acc = ((acc - window_36) + 11) & 127;
    aux += 3;
  }
  int delta_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_43) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001124_2413_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001124_2413_2 st_1 = {0};
  struct MatrixBlock_R001124_2413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int mask_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_92_1)
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

  switch (mask_92_2)
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

  int offset_47_1 = 0;
  int offset_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_47_1 = ((offset_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_47_2 = ((offset_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_47_1) & 127;
    acc_2 = (acc_2 + offset_47_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_19_1 = local_arr_1[aux_1 % 3];
  int window_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_19_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.dim == st_2.dim);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_92_1 == mask_92_2);
  assert(offset_47_1 == offset_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_19_1 == window_19_2);
}

int fn_R001124_2413_20(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001124_2413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int mask_92 = (aux + st.buffer[1]) & 3;
  switch (mask_92)
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

  int offset_47 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_47 = ((offset_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_47) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int window_19 = local_arr[aux % 3];
  acc = (acc + (window_19 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001124_2413_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st_1 = {0};
  struct AudioFrame_R001124_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_81_1 = local_arr_1[aux_1 % 3];
  int pivot_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_81_2 * 2)) & 127;
  int damping_45_1 = 0;
  int damping_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_45_1 = ((damping_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_45_2 = ((damping_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_45_1) & 127;
    acc_2 = (acc_2 + damping_45_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_46_1) & 63;
  aux_2 = (aux_2 + parity_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_81_1 == pivot_81_2);
  assert(damping_45_1 == damping_45_2);
  assert(parity_46_1 == parity_46_2);
}

int fn_R001124_2413_21(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001124_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int pivot_81 = local_arr[aux % 3];
  acc = (acc + (pivot_81 * 2)) & 127;
  int damping_45 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_45 = ((damping_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_45) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_46) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001124_2413_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001124_2413_1 st_1 = {0};
  struct FilterState_R001124_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_28_1 = local_arr_1[aux_1 % 3];
  int quotient_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_28_2 * 2)) & 127;
  int quantum_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_27_1)
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

  switch (quantum_27_2)
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

  int index_reg_77_1 = 0;
  int index_reg_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_77_1 = ((index_reg_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_77_2 = ((index_reg_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_77_1) & 127;
    acc_2 = (acc_2 + index_reg_77_2) & 127;
  }

  int quantum_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_60_1 > 35)
  {
    acc_1 = ((acc_1 + (quantum_60_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_60_2 > 35)
  {
    acc_2 = ((acc_2 + (quantum_60_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_60_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_28_1 == quotient_28_2);
  assert(quantum_27_1 == quantum_27_2);
  assert(index_reg_77_1 == index_reg_77_2);
  assert(quantum_60_1 == quantum_60_2);
}

int fn_R001124_2413_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001124_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int quotient_28 = local_arr[aux % 3];
  acc = (acc + (quotient_28 * 2)) & 127;
  int quantum_27 = (aux + st.buffer[1]) & 3;
  switch (quantum_27)
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

  int index_reg_77 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_77 = ((index_reg_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_77) & 127;
  }

  int quantum_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_60 > 35)
  {
    acc = ((acc + (quantum_60 * 2)) + 5) & 127;
    aux ^= quantum_60 & 15;
  }
  else
  {
    acc = ((acc - quantum_60) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001124_0_1;
  int sec_r001124_0_2;
  int sec_r001124_1_1;
  int sec_r001124_1_2;
  int sec_r001124_2_1;
  int sec_r001124_2_2;
  int sec_r001124_3_1;
  int sec_r001124_3_2;
  int sec_r001124_4_1;
  int sec_r001124_4_2;
  int sec_r001124_5_1;
  int sec_r001124_5_2;
  int sec_r001124_6_1;
  int sec_r001124_6_2;
  int sec_r001124_7_1;
  int sec_r001124_7_2;
  int sec_r001124_8_1;
  int sec_r001124_8_2;
  int sec_r001124_9_1;
  int sec_r001124_9_2;
  int sec_r001124_10_1;
  int sec_r001124_10_2;
  int sec_r001124_11_1;
  int sec_r001124_11_2;
  int sec_r001124_12_1;
  int sec_r001124_12_2;
  int sec_r001124_13_1;
  int sec_r001124_13_2;
  int sec_r001124_14_1;
  int sec_r001124_14_2;
  int sec_r001124_15_1;
  int sec_r001124_15_2;
  int sec_r001124_16_1;
  int sec_r001124_16_2;
  int sec_r001124_17_1;
  int sec_r001124_17_2;
  int sec_r001124_18_1;
  int sec_r001124_18_2;
  int sec_r001124_19_1;
  int sec_r001124_19_2;
  int sec_r001124_20_1;
  int sec_r001124_20_2;
  int sec_r001124_21_1;
  int sec_r001124_21_2;
  int sec_r001124_22_1;
  int sec_r001124_22_2;
  int pub_r001124_0_1;
  int pub_r001124_0_2;
  int pub_r001124_1_1;
  int pub_r001124_1_2;
  int pub_r001124_2_1;
  int pub_r001124_2_2;
  int pub_r001124_3_1;
  int pub_r001124_3_2;
  int pub_r001124_4_1;
  int pub_r001124_4_2;
  int pub_r001124_5_1;
  int pub_r001124_5_2;
  int pub_r001124_6_1;
  int pub_r001124_6_2;
  int pub_r001124_7_1;
  int pub_r001124_7_2;
  int pub_r001124_8_1;
  int pub_r001124_8_2;
  int pub_r001124_9_1;
  int pub_r001124_9_2;
  int pub_r001124_10_1;
  int pub_r001124_10_2;
  int pub_r001124_11_1;
  int pub_r001124_11_2;
  int pub_r001124_12_1;
  int pub_r001124_12_2;
  int pub_r001124_13_1;
  int pub_r001124_13_2;
  int pub_r001124_14_1;
  int pub_r001124_14_2;
  int pub_r001124_15_1;
  int pub_r001124_15_2;
  int pub_r001124_16_1;
  int pub_r001124_16_2;
  int pub_r001124_17_1;
  int pub_r001124_17_2;
  int pub_r001124_18_1;
  int pub_r001124_18_2;
  int pub_r001124_19_1;
  int pub_r001124_19_2;
  int pub_r001124_20_1;
  int pub_r001124_20_2;
  int pub_r001124_21_1;
  int pub_r001124_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001124_0_1 >= (-100)) && (pub_r001124_0_1 <= 100));
  __CPROVER_assume((pub_r001124_0_2 >= (-100)) && (pub_r001124_0_2 <= 100));
  __CPROVER_assume((pub_r001124_1_1 >= (-100)) && (pub_r001124_1_1 <= 100));
  __CPROVER_assume((pub_r001124_1_2 >= (-100)) && (pub_r001124_1_2 <= 100));
  __CPROVER_assume((pub_r001124_2_1 >= (-100)) && (pub_r001124_2_1 <= 100));
  __CPROVER_assume((pub_r001124_2_2 >= (-100)) && (pub_r001124_2_2 <= 100));
  __CPROVER_assume((pub_r001124_3_1 >= (-100)) && (pub_r001124_3_1 <= 100));
  __CPROVER_assume((pub_r001124_3_2 >= (-100)) && (pub_r001124_3_2 <= 100));
  __CPROVER_assume((pub_r001124_4_1 >= (-100)) && (pub_r001124_4_1 <= 100));
  __CPROVER_assume((pub_r001124_4_2 >= (-100)) && (pub_r001124_4_2 <= 100));
  __CPROVER_assume((pub_r001124_5_1 >= (-100)) && (pub_r001124_5_1 <= 100));
  __CPROVER_assume((pub_r001124_5_2 >= (-100)) && (pub_r001124_5_2 <= 100));
  __CPROVER_assume((pub_r001124_6_1 >= (-100)) && (pub_r001124_6_1 <= 100));
  __CPROVER_assume((pub_r001124_6_2 >= (-100)) && (pub_r001124_6_2 <= 100));
  __CPROVER_assume((pub_r001124_7_1 >= (-100)) && (pub_r001124_7_1 <= 100));
  __CPROVER_assume((pub_r001124_7_2 >= (-100)) && (pub_r001124_7_2 <= 100));
  __CPROVER_assume((pub_r001124_8_1 >= (-100)) && (pub_r001124_8_1 <= 100));
  __CPROVER_assume((pub_r001124_8_2 >= (-100)) && (pub_r001124_8_2 <= 100));
  __CPROVER_assume((pub_r001124_9_1 >= (-100)) && (pub_r001124_9_1 <= 100));
  __CPROVER_assume((pub_r001124_9_2 >= (-100)) && (pub_r001124_9_2 <= 100));
  __CPROVER_assume((pub_r001124_10_1 >= (-100)) && (pub_r001124_10_1 <= 100));
  __CPROVER_assume((pub_r001124_10_2 >= (-100)) && (pub_r001124_10_2 <= 100));
  __CPROVER_assume((pub_r001124_11_1 >= (-100)) && (pub_r001124_11_1 <= 100));
  __CPROVER_assume((pub_r001124_11_2 >= (-100)) && (pub_r001124_11_2 <= 100));
  __CPROVER_assume((pub_r001124_12_1 >= (-100)) && (pub_r001124_12_1 <= 100));
  __CPROVER_assume((pub_r001124_12_2 >= (-100)) && (pub_r001124_12_2 <= 100));
  __CPROVER_assume((pub_r001124_13_1 >= (-100)) && (pub_r001124_13_1 <= 100));
  __CPROVER_assume((pub_r001124_13_2 >= (-100)) && (pub_r001124_13_2 <= 100));
  __CPROVER_assume((pub_r001124_14_1 >= (-100)) && (pub_r001124_14_1 <= 100));
  __CPROVER_assume((pub_r001124_14_2 >= (-100)) && (pub_r001124_14_2 <= 100));
  __CPROVER_assume((pub_r001124_15_1 >= (-100)) && (pub_r001124_15_1 <= 100));
  __CPROVER_assume((pub_r001124_15_2 >= (-100)) && (pub_r001124_15_2 <= 100));
  __CPROVER_assume((pub_r001124_16_1 >= (-100)) && (pub_r001124_16_1 <= 100));
  __CPROVER_assume((pub_r001124_16_2 >= (-100)) && (pub_r001124_16_2 <= 100));
  __CPROVER_assume((pub_r001124_17_1 >= (-100)) && (pub_r001124_17_1 <= 100));
  __CPROVER_assume((pub_r001124_17_2 >= (-100)) && (pub_r001124_17_2 <= 100));
  __CPROVER_assume((pub_r001124_18_1 >= (-100)) && (pub_r001124_18_1 <= 100));
  __CPROVER_assume((pub_r001124_18_2 >= (-100)) && (pub_r001124_18_2 <= 100));
  __CPROVER_assume((pub_r001124_19_1 >= (-100)) && (pub_r001124_19_1 <= 100));
  __CPROVER_assume((pub_r001124_19_2 >= (-100)) && (pub_r001124_19_2 <= 100));
  __CPROVER_assume((pub_r001124_20_1 >= (-100)) && (pub_r001124_20_1 <= 100));
  __CPROVER_assume((pub_r001124_20_2 >= (-100)) && (pub_r001124_20_2 <= 100));
  __CPROVER_assume((pub_r001124_21_1 >= (-100)) && (pub_r001124_21_1 <= 100));
  __CPROVER_assume((pub_r001124_21_2 >= (-100)) && (pub_r001124_21_2 <= 100));
  __CPROVER_assume((sec_r001124_0_1 >= 0) && (sec_r001124_0_1 <= 255));
  __CPROVER_assume((sec_r001124_0_2 >= 0) && (sec_r001124_0_2 <= 255));
  __CPROVER_assume((sec_r001124_1_1 >= 0) && (sec_r001124_1_1 <= 255));
  __CPROVER_assume((sec_r001124_1_2 >= 0) && (sec_r001124_1_2 <= 255));
  __CPROVER_assume((sec_r001124_2_1 >= 0) && (sec_r001124_2_1 <= 255));
  __CPROVER_assume((sec_r001124_2_2 >= 0) && (sec_r001124_2_2 <= 255));
  __CPROVER_assume((sec_r001124_3_1 >= 0) && (sec_r001124_3_1 <= 255));
  __CPROVER_assume((sec_r001124_3_2 >= 0) && (sec_r001124_3_2 <= 255));
  __CPROVER_assume((sec_r001124_4_1 >= 0) && (sec_r001124_4_1 <= 255));
  __CPROVER_assume((sec_r001124_4_2 >= 0) && (sec_r001124_4_2 <= 255));
  __CPROVER_assume((sec_r001124_5_1 >= 0) && (sec_r001124_5_1 <= 255));
  __CPROVER_assume((sec_r001124_5_2 >= 0) && (sec_r001124_5_2 <= 255));
  __CPROVER_assume((sec_r001124_6_1 >= 0) && (sec_r001124_6_1 <= 255));
  __CPROVER_assume((sec_r001124_6_2 >= 0) && (sec_r001124_6_2 <= 255));
  __CPROVER_assume((sec_r001124_7_1 >= 0) && (sec_r001124_7_1 <= 255));
  __CPROVER_assume((sec_r001124_7_2 >= 0) && (sec_r001124_7_2 <= 255));
  __CPROVER_assume((sec_r001124_8_1 >= 0) && (sec_r001124_8_1 <= 255));
  __CPROVER_assume((sec_r001124_8_2 >= 0) && (sec_r001124_8_2 <= 255));
  __CPROVER_assume((sec_r001124_9_1 >= 0) && (sec_r001124_9_1 <= 255));
  __CPROVER_assume((sec_r001124_9_2 >= 0) && (sec_r001124_9_2 <= 255));
  __CPROVER_assume((sec_r001124_10_1 >= 0) && (sec_r001124_10_1 <= 255));
  __CPROVER_assume((sec_r001124_10_2 >= 0) && (sec_r001124_10_2 <= 255));
  __CPROVER_assume((sec_r001124_11_1 >= 0) && (sec_r001124_11_1 <= 255));
  __CPROVER_assume((sec_r001124_11_2 >= 0) && (sec_r001124_11_2 <= 255));
  __CPROVER_assume((sec_r001124_12_1 >= 0) && (sec_r001124_12_1 <= 255));
  __CPROVER_assume((sec_r001124_12_2 >= 0) && (sec_r001124_12_2 <= 255));
  __CPROVER_assume((sec_r001124_13_1 >= 0) && (sec_r001124_13_1 <= 255));
  __CPROVER_assume((sec_r001124_13_2 >= 0) && (sec_r001124_13_2 <= 255));
  __CPROVER_assume((sec_r001124_14_1 >= 0) && (sec_r001124_14_1 <= 255));
  __CPROVER_assume((sec_r001124_14_2 >= 0) && (sec_r001124_14_2 <= 255));
  __CPROVER_assume((sec_r001124_15_1 >= 0) && (sec_r001124_15_1 <= 255));
  __CPROVER_assume((sec_r001124_15_2 >= 0) && (sec_r001124_15_2 <= 255));
  __CPROVER_assume((sec_r001124_16_1 >= 0) && (sec_r001124_16_1 <= 255));
  __CPROVER_assume((sec_r001124_16_2 >= 0) && (sec_r001124_16_2 <= 255));
  __CPROVER_assume((sec_r001124_17_1 >= 0) && (sec_r001124_17_1 <= 255));
  __CPROVER_assume((sec_r001124_17_2 >= 0) && (sec_r001124_17_2 <= 255));
  __CPROVER_assume((sec_r001124_18_1 >= 0) && (sec_r001124_18_1 <= 255));
  __CPROVER_assume((sec_r001124_18_2 >= 0) && (sec_r001124_18_2 <= 255));
  __CPROVER_assume((sec_r001124_19_1 >= 0) && (sec_r001124_19_1 <= 255));
  __CPROVER_assume((sec_r001124_19_2 >= 0) && (sec_r001124_19_2 <= 255));
  __CPROVER_assume((sec_r001124_20_1 >= 0) && (sec_r001124_20_1 <= 255));
  __CPROVER_assume((sec_r001124_20_2 >= 0) && (sec_r001124_20_2 <= 255));
  __CPROVER_assume((sec_r001124_21_1 >= 0) && (sec_r001124_21_1 <= 255));
  __CPROVER_assume((sec_r001124_21_2 >= 0) && (sec_r001124_21_2 <= 255));
  __CPROVER_assume((sec_r001124_22_1 >= 0) && (sec_r001124_22_1 <= 255));
  __CPROVER_assume((sec_r001124_22_2 >= 0) && (sec_r001124_22_2 <= 255));
  struct AudioFrame_R001124_2413_0 st_var_0_1 = {0};
  struct AudioFrame_R001124_2413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001124_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001124_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001124_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001124_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001124_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001124_0_2 + 7) & 15;
  struct FilterState_R001124_2413_1 st_var_1_1 = {0};
  struct FilterState_R001124_2413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001124_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001124_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001124_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001124_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001124_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001124_0_2 + 9) & 15;
  struct MatrixBlock_R001124_2413_2 st_var_2_1 = {0};
  struct MatrixBlock_R001124_2413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001124_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001124_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001124_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001124_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001124_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001124_0_2 + 11) & 15;
  union RegisterBank_R001124_2413_0 u_var_1;
  union RegisterBank_R001124_2413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001124_2413_0(sec_r001124_0_1, sec_r001124_1_1, pub_r001124_2_1, pub_r001124_3_1, pub_r001124_4_1);
  int helper_flow_0_2 = fn_R001124_2413_0(sec_r001124_0_2, sec_r001124_1_2, pub_r001124_2_2, pub_r001124_3_2, pub_r001124_4_2);
  fn_R001124_2413_0_2(sec_r001124_0_1, sec_r001124_1_1, pub_r001124_2_1, pub_r001124_3_1, pub_r001124_4_1, sec_r001124_0_2, sec_r001124_1_2, pub_r001124_2_2, pub_r001124_3_2, pub_r001124_4_2);
  int helper_flow_1_1 = fn_R001124_2413_1(sec_r001124_1_1, pub_r001124_2_1, pub_r001124_3_1, pub_r001124_4_1);
  int helper_flow_1_2 = fn_R001124_2413_1(sec_r001124_1_2, pub_r001124_2_2, pub_r001124_3_2, pub_r001124_4_2);
  fn_R001124_2413_1_2(sec_r001124_1_1, pub_r001124_2_1, pub_r001124_3_1, pub_r001124_4_1, sec_r001124_1_2, pub_r001124_2_2, pub_r001124_3_2, pub_r001124_4_2);
  int helper_flow_2_1 = fn_R001124_2413_2(sec_r001124_2_1, pub_r001124_3_1, pub_r001124_4_1);
  int helper_flow_2_2 = fn_R001124_2413_2(sec_r001124_2_2, pub_r001124_3_2, pub_r001124_4_2);
  fn_R001124_2413_2_2(sec_r001124_2_1, pub_r001124_3_1, pub_r001124_4_1, sec_r001124_2_2, pub_r001124_3_2, pub_r001124_4_2);
  int helper_flow_3_1 = fn_R001124_2413_3(sec_r001124_3_1, sec_r001124_4_1, pub_r001124_5_1);
  int helper_flow_3_2 = fn_R001124_2413_3(sec_r001124_3_2, sec_r001124_4_2, pub_r001124_5_2);
  fn_R001124_2413_3_2(sec_r001124_3_1, sec_r001124_4_1, pub_r001124_5_1, sec_r001124_3_2, sec_r001124_4_2, pub_r001124_5_2);
  int helper_flow_4_1 = fn_R001124_2413_4(sec_r001124_4_1, sec_r001124_5_1);
  int helper_flow_4_2 = fn_R001124_2413_4(sec_r001124_4_2, sec_r001124_5_2);
  fn_R001124_2413_4_2(sec_r001124_4_1, sec_r001124_5_1, sec_r001124_4_2, sec_r001124_5_2);
  int helper_flow_5_1 = fn_R001124_2413_5(sec_r001124_5_1, pub_r001124_6_1, pub_r001124_7_1, pub_r001124_8_1);
  int helper_flow_5_2 = fn_R001124_2413_5(sec_r001124_5_2, pub_r001124_6_2, pub_r001124_7_2, pub_r001124_8_2);
  fn_R001124_2413_5_2(sec_r001124_5_1, pub_r001124_6_1, pub_r001124_7_1, pub_r001124_8_1, sec_r001124_5_2, pub_r001124_6_2, pub_r001124_7_2, pub_r001124_8_2);
  int helper_flow_6_1 = fn_R001124_2413_6(sec_r001124_6_1, pub_r001124_7_1, pub_r001124_8_1, pub_r001124_9_1);
  int helper_flow_6_2 = fn_R001124_2413_6(sec_r001124_6_2, pub_r001124_7_2, pub_r001124_8_2, pub_r001124_9_2);
  fn_R001124_2413_6_2(sec_r001124_6_1, pub_r001124_7_1, pub_r001124_8_1, pub_r001124_9_1, sec_r001124_6_2, pub_r001124_7_2, pub_r001124_8_2, pub_r001124_9_2);
  int stage_v_0_1 = ((pub_r001124_2_1 * 2) + 14) & 63;
  int stage_v_0_2 = ((pub_r001124_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (((sec_r001124_2_1 * 3) + pub_r001124_10_1) + 19) & 127;
  int stage_v_1_2 = (((sec_r001124_2_2 * 3) + pub_r001124_10_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = ((pub_r001124_3_1 * 2) + 8) & 63;
  int stage_v_2_2 = ((pub_r001124_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001124_18_1 * 2) + 15) & 63;
  int stage_v_3_2 = ((pub_r001124_18_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001124_14_1 * 2) + 34) & 63;
  int stage_v_4_2 = ((pub_r001124_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (((sec_r001124_17_1 * 3) + pub_r001124_0_1) + 38) & 127;
  int stage_v_5_2 = (((sec_r001124_17_2 * 3) + pub_r001124_0_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = ((pub_r001124_21_1 * 2) + 42) & 63;
  int stage_v_6_2 = ((pub_r001124_21_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001124_0_1 * 2) + 31) & 63;
  int stage_v_7_2 = ((pub_r001124_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001124_5_1 * 2) + 47) & 63;
  int stage_v_8_2 = ((pub_r001124_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (((helper_flow_3_1 * 3) + pub_r001124_13_1) + 14) & 127;
  int stage_v_9_2 = (((helper_flow_3_2 * 3) + pub_r001124_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = (((sec_r001124_16_1 * 3) + pub_r001124_0_1) + 35) & 127;
  int stage_v_10_2 = (((sec_r001124_16_2 * 3) + pub_r001124_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = ((pub_r001124_21_1 * 2) + 13) & 63;
  int stage_v_11_2 = ((pub_r001124_21_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (((sec_r001124_2_1 * 3) + pub_r001124_17_1) + 12) & 127;
  int stage_v_12_2 = (((sec_r001124_2_2 * 3) + pub_r001124_17_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = ((pub_r001124_13_1 * 2) + 37) & 63;
  int stage_v_13_2 = ((pub_r001124_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((sec_r001124_15_1 * 3) + pub_r001124_10_1) + 26) & 127;
  int stage_v_14_2 = (((sec_r001124_15_2 * 3) + pub_r001124_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = (((stage_v_14_1 * 3) + pub_r001124_12_1) + 32) & 127;
  int stage_v_15_2 = (((stage_v_14_2 * 3) + pub_r001124_12_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = (((helper_flow_2_1 * 3) + pub_r001124_17_1) + 24) & 127;
  int stage_v_16_2 = (((helper_flow_2_2 * 3) + pub_r001124_17_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = (((sec_r001124_10_1 * 3) + pub_r001124_20_1) + 8) & 127;
  int stage_v_17_2 = (((sec_r001124_10_2 * 3) + pub_r001124_20_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = (((helper_flow_6_1 * 3) + pub_r001124_13_1) + 40) & 127;
  int stage_v_18_2 = (((helper_flow_6_2 * 3) + pub_r001124_13_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = (((helper_flow_6_1 * 3) + pub_r001124_11_1) + 34) & 127;
  int stage_v_19_2 = (((helper_flow_6_2 * 3) + pub_r001124_11_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = (((sec_r001124_15_1 * 3) + pub_r001124_5_1) + 39) & 127;
  int stage_v_20_2 = (((sec_r001124_15_2 * 3) + pub_r001124_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = (((sec_r001124_7_1 * 3) + pub_r001124_9_1) + 13) & 127;
  int stage_v_21_2 = (((sec_r001124_7_2 * 3) + pub_r001124_9_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = ((pub_r001124_9_1 * 2) + 13) & 63;
  int stage_v_22_2 = ((pub_r001124_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((sec_r001124_15_1 * 3) + pub_r001124_21_1) + 35) & 127;
  int stage_v_23_2 = (((sec_r001124_15_2 * 3) + pub_r001124_21_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((sec_r001124_9_1 * 3) + pub_r001124_19_1) + 41) & 127;
  int stage_v_24_2 = (((sec_r001124_9_2 * 3) + pub_r001124_19_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = ((pub_r001124_10_1 * 2) + 47) & 63;
  int stage_v_25_2 = ((pub_r001124_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (((stage_v_17_1 * 3) + pub_r001124_5_1) + 43) & 127;
  int stage_v_26_2 = (((stage_v_17_2 * 3) + pub_r001124_5_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = (((stage_v_9_1 * 3) + pub_r001124_5_1) + 45) & 127;
  int stage_v_27_2 = (((stage_v_9_2 * 3) + pub_r001124_5_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_27_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_27_2 * 2)) & 255;
  int stage_v_28_1 = ((pub_r001124_14_1 * 2) + 29) & 63;
  int stage_v_28_2 = ((pub_r001124_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001124_9_1 * 2) + 24) & 63;
  int stage_v_29_2 = ((pub_r001124_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001124_2_1 * 2) + 19) & 63;
  int stage_v_30_2 = ((pub_r001124_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = (((sec_r001124_17_1 * 3) + pub_r001124_21_1) + 12) & 127;
  int stage_v_31_2 = (((sec_r001124_17_2 * 3) + pub_r001124_21_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = ((pub_r001124_8_1 * 2) + 5) & 63;
  int stage_v_32_2 = ((pub_r001124_8_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (((sec_r001124_1_1 * 3) + pub_r001124_2_1) + 16) & 127;
  int stage_v_33_2 = (((sec_r001124_1_2 * 3) + pub_r001124_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = (((sec_r001124_10_1 * 3) + pub_r001124_2_1) + 31) & 127;
  int stage_v_34_2 = (((sec_r001124_10_2 * 3) + pub_r001124_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = ((pub_r001124_16_1 * 2) + 34) & 63;
  int stage_v_35_2 = ((pub_r001124_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((sec_r001124_5_1 * 3) + pub_r001124_10_1) + 45) & 127;
  int stage_v_36_2 = (((sec_r001124_5_2 * 3) + pub_r001124_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = (((helper_flow_5_1 * 3) + pub_r001124_18_1) + 35) & 127;
  int stage_v_37_2 = (((helper_flow_5_2 * 3) + pub_r001124_18_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = ((pub_r001124_17_1 * 2) + 32) & 63;
  int stage_v_38_2 = ((pub_r001124_17_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001124_17_1 * 2) + 12) & 63;
  int stage_v_39_2 = ((pub_r001124_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((helper_flow_5_1 * 3) + pub_r001124_3_1) + 28) & 127;
  int stage_v_40_2 = (((helper_flow_5_2 * 3) + pub_r001124_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = ((pub_r001124_21_1 * 2) + 39) & 63;
  int stage_v_41_2 = ((pub_r001124_21_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (((sec_r001124_9_1 * 3) + pub_r001124_11_1) + 11) & 127;
  int stage_v_42_2 = (((sec_r001124_9_2 * 3) + pub_r001124_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = ((pub_r001124_10_1 * 2) + 50) & 63;
  int stage_v_43_2 = ((pub_r001124_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (((stage_v_27_1 * 3) + pub_r001124_8_1) + 30) & 127;
  int stage_v_44_2 = (((stage_v_27_2 * 3) + pub_r001124_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = ((pub_r001124_20_1 * 2) + 10) & 63;
  int stage_v_45_2 = ((pub_r001124_20_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((stage_v_17_1 * 3) + pub_r001124_16_1) + 42) & 127;
  int stage_v_46_2 = (((stage_v_17_2 * 3) + pub_r001124_16_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = (((sec_r001124_17_1 * 3) + pub_r001124_21_1) + 19) & 127;
  int stage_v_47_2 = (((sec_r001124_17_2 * 3) + pub_r001124_21_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = (((sec_r001124_21_1 * 3) + pub_r001124_8_1) + 24) & 127;
  int stage_v_48_2 = (((sec_r001124_21_2 * 3) + pub_r001124_8_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = ((pub_r001124_9_1 * 2) + 43) & 63;
  int stage_v_49_2 = ((pub_r001124_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (((sec_r001124_0_1 * 3) + pub_r001124_0_1) + 14) & 127;
  int stage_v_50_2 = (((sec_r001124_0_2 * 3) + pub_r001124_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = (((stage_v_23_1 * 3) + pub_r001124_11_1) + 28) & 127;
  int stage_v_51_2 = (((stage_v_23_2 * 3) + pub_r001124_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_51_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_51_2 * 2)) & 255;
  int stage_v_52_1 = (((helper_flow_3_1 * 3) + pub_r001124_13_1) + 28) & 127;
  int stage_v_52_2 = (((helper_flow_3_2 * 3) + pub_r001124_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = (((sec_r001124_12_1 * 3) + pub_r001124_3_1) + 23) & 127;
  int stage_v_53_2 = (((sec_r001124_12_2 * 3) + pub_r001124_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = (((stage_v_12_1 * 3) + pub_r001124_8_1) + 43) & 127;
  int stage_v_54_2 = (((stage_v_12_2 * 3) + pub_r001124_8_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = ((pub_r001124_12_1 * 2) + 23) & 63;
  int stage_v_55_2 = ((pub_r001124_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001124_20_1 * 2) + 25) & 63;
  int stage_v_56_2 = ((pub_r001124_20_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (((stage_v_19_1 * 3) + pub_r001124_20_1) + 22) & 127;
  int stage_v_57_2 = (((stage_v_19_2 * 3) + pub_r001124_20_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = (((stage_v_48_1 * 3) + pub_r001124_19_1) + 33) & 127;
  int stage_v_58_2 = (((stage_v_48_2 * 3) + pub_r001124_19_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = (((sec_r001124_22_1 * 3) + pub_r001124_20_1) + 36) & 127;
  int stage_v_59_2 = (((sec_r001124_22_2 * 3) + pub_r001124_20_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = (((sec_r001124_1_1 * 3) + pub_r001124_8_1) + 29) & 127;
  int stage_v_60_2 = (((sec_r001124_1_2 * 3) + pub_r001124_8_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = (((stage_v_20_1 * 3) + pub_r001124_15_1) + 11) & 127;
  int stage_v_61_2 = (((stage_v_20_2 * 3) + pub_r001124_15_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = (((sec_r001124_11_1 * 3) + pub_r001124_14_1) + 23) & 127;
  int stage_v_62_2 = (((sec_r001124_11_2 * 3) + pub_r001124_14_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = (((stage_v_51_1 * 3) + pub_r001124_16_1) + 24) & 127;
  int stage_v_63_2 = (((stage_v_51_2 * 3) + pub_r001124_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = ((pub_r001124_12_1 * 2) + 49) & 63;
  int stage_v_64_2 = ((pub_r001124_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001124_12_1 * 2) + 41) & 63;
  int stage_v_65_2 = ((pub_r001124_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((sec_r001124_0_1 * 3) + pub_r001124_11_1) + 25) & 127;
  int stage_v_66_2 = (((sec_r001124_0_2 * 3) + pub_r001124_11_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = (((sec_r001124_7_1 * 3) + pub_r001124_21_1) + 3) & 127;
  int stage_v_67_2 = (((sec_r001124_7_2 * 3) + pub_r001124_21_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = (((sec_r001124_4_1 * 3) + pub_r001124_16_1) + 36) & 127;
  int stage_v_68_2 = (((sec_r001124_4_2 * 3) + pub_r001124_16_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = ((pub_r001124_13_1 * 2) + 24) & 63;
  int stage_v_69_2 = ((pub_r001124_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((sec_r001124_1_1 * 3) + pub_r001124_9_1) + 40) & 127;
  int stage_v_70_2 = (((sec_r001124_1_2 * 3) + pub_r001124_9_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = ((pub_r001124_4_1 * 2) + 22) & 63;
  int stage_v_71_2 = ((pub_r001124_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((sec_r001124_0_1 * 3) + pub_r001124_19_1) + 4) & 127;
  int stage_v_72_2 = (((sec_r001124_0_2 * 3) + pub_r001124_19_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = ((pub_r001124_14_1 * 2) + 36) & 63;
  int stage_v_73_2 = ((pub_r001124_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001124_9_1 * 2) + 26) & 63;
  int stage_v_74_2 = ((pub_r001124_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001124_6_1 * 2) + 22) & 63;
  int stage_v_75_2 = ((pub_r001124_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = (((stage_v_15_1 * 3) + pub_r001124_5_1) + 44) & 127;
  int stage_v_76_2 = (((stage_v_15_2 * 3) + pub_r001124_5_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = (((stage_v_31_1 * 3) + pub_r001124_18_1) + 30) & 127;
  int stage_v_77_2 = (((stage_v_31_2 * 3) + pub_r001124_18_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = (((stage_v_61_1 * 3) + pub_r001124_10_1) + 7) & 127;
  int stage_v_78_2 = (((stage_v_61_2 * 3) + pub_r001124_10_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = (((stage_v_78_1 * 3) + pub_r001124_3_1) + 8) & 127;
  int stage_v_79_2 = (((stage_v_78_2 * 3) + pub_r001124_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = (((sec_r001124_0_1 * 3) + pub_r001124_1_1) + 10) & 127;
  int stage_v_80_2 = (((sec_r001124_0_2 * 3) + pub_r001124_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_80_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_80_2 * 2)) & 255;
  int stage_v_81_1 = (((sec_r001124_14_1 * 3) + pub_r001124_3_1) + 13) & 127;
  int stage_v_81_2 = (((sec_r001124_14_2 * 3) + pub_r001124_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = (((stage_v_23_1 * 3) + pub_r001124_11_1) + 7) & 127;
  int stage_v_82_2 = (((stage_v_23_2 * 3) + pub_r001124_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = ((pub_r001124_20_1 * 2) + 32) & 63;
  int stage_v_83_2 = ((pub_r001124_20_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001124_15_1 * 2) + 35) & 63;
  int stage_v_84_2 = ((pub_r001124_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = (((stage_v_44_1 * 3) + pub_r001124_2_1) + 34) & 127;
  int stage_v_85_2 = (((stage_v_44_2 * 3) + pub_r001124_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = ((pub_r001124_8_1 * 2) + 46) & 63;
  int stage_v_86_2 = ((pub_r001124_8_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((sec_r001124_13_1 * 3) + pub_r001124_8_1) + 30) & 127;
  int stage_v_87_2 = (((sec_r001124_13_2 * 3) + pub_r001124_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = (((stage_v_50_1 * 3) + pub_r001124_21_1) + 24) & 127;
  int stage_v_88_2 = (((stage_v_50_2 * 3) + pub_r001124_21_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = (((helper_flow_6_1 * 3) + pub_r001124_6_1) + 17) & 127;
  int stage_v_89_2 = (((helper_flow_6_2 * 3) + pub_r001124_6_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = (((stage_v_31_1 * 3) + pub_r001124_15_1) + 32) & 127;
  int stage_v_90_2 = (((stage_v_31_2 * 3) + pub_r001124_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = ((pub_r001124_11_1 * 2) + 30) & 63;
  int stage_v_91_2 = ((pub_r001124_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_79_1 * 3) + pub_r001124_3_1) + 15) & 127;
  int stage_v_92_2 = (((stage_v_79_2 * 3) + pub_r001124_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = ((pub_r001124_14_1 * 2) + 26) & 63;
  int stage_v_93_2 = ((pub_r001124_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001124_2_1 * 2) + 11) & 63;
  int stage_v_94_2 = ((pub_r001124_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001124_10_1 * 2) + 14) & 63;
  int stage_v_95_2 = ((pub_r001124_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001124_9_1 * 2) + 19) & 63;
  int stage_v_96_2 = ((pub_r001124_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001124_12_1 * 2) + 6) & 63;
  int stage_v_97_2 = ((pub_r001124_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((stage_v_66_1 * 3) + pub_r001124_19_1) + 26) & 127;
  int stage_v_98_2 = (((stage_v_66_2 * 3) + pub_r001124_19_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = (((stage_v_59_1 * 3) + pub_r001124_4_1) + 38) & 127;
  int stage_v_99_2 = (((stage_v_59_2 * 3) + pub_r001124_4_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = (((stage_v_19_1 * 3) + pub_r001124_0_1) + 5) & 127;
  int stage_v_100_2 = (((stage_v_19_2 * 3) + pub_r001124_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_100_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_100_2 * 2)) & 255;
  int stage_v_101_1 = ((pub_r001124_17_1 * 2) + 11) & 63;
  int stage_v_101_2 = ((pub_r001124_17_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((stage_v_99_1 * 3) + pub_r001124_11_1) + 8) & 127;
  int stage_v_102_2 = (((stage_v_99_2 * 3) + pub_r001124_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = ((pub_r001124_19_1 * 2) + 34) & 63;
  int stage_v_103_2 = ((pub_r001124_19_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((helper_flow_3_1 * 3) + pub_r001124_10_1) + 25) & 127;
  int stage_v_104_2 = (((helper_flow_3_2 * 3) + pub_r001124_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = (((sec_r001124_16_1 * 3) + pub_r001124_12_1) + 10) & 127;
  int stage_v_105_2 = (((sec_r001124_16_2 * 3) + pub_r001124_12_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = (((stage_v_70_1 * 3) + pub_r001124_18_1) + 38) & 127;
  int stage_v_106_2 = (((stage_v_70_2 * 3) + pub_r001124_18_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = (((stage_v_105_1 * 3) + pub_r001124_6_1) + 25) & 127;
  int stage_v_107_2 = (((stage_v_105_2 * 3) + pub_r001124_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = ((pub_r001124_15_1 * 2) + 50) & 63;
  int stage_v_108_2 = ((pub_r001124_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (((stage_v_40_1 * 3) + pub_r001124_11_1) + 41) & 127;
  int stage_v_109_2 = (((stage_v_40_2 * 3) + pub_r001124_11_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = (((stage_v_58_1 * 3) + pub_r001124_21_1) + 11) & 127;
  int stage_v_110_2 = (((stage_v_58_2 * 3) + pub_r001124_21_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = ((pub_r001124_10_1 * 2) + 7) & 63;
  int stage_v_111_2 = ((pub_r001124_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (((sec_r001124_14_1 * 3) + pub_r001124_14_1) + 5) & 127;
  int stage_v_112_2 = (((sec_r001124_14_2 * 3) + pub_r001124_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = (((sec_r001124_8_1 * 3) + pub_r001124_18_1) + 5) & 127;
  int stage_v_113_2 = (((sec_r001124_8_2 * 3) + pub_r001124_18_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = ((pub_r001124_2_1 * 2) + 29) & 63;
  int stage_v_114_2 = ((pub_r001124_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = (((helper_flow_4_1 * 3) + pub_r001124_19_1) + 7) & 127;
  int stage_v_115_2 = (((helper_flow_4_2 * 3) + pub_r001124_19_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = (((stage_v_72_1 * 3) + pub_r001124_18_1) + 36) & 127;
  int stage_v_116_2 = (((stage_v_72_2 * 3) + pub_r001124_18_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = (((sec_r001124_13_1 * 3) + pub_r001124_10_1) + 3) & 127;
  int stage_v_117_2 = (((sec_r001124_13_2 * 3) + pub_r001124_10_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = (((stage_v_107_1 * 3) + pub_r001124_14_1) + 16) & 127;
  int stage_v_118_2 = (((stage_v_107_2 * 3) + pub_r001124_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = (((stage_v_109_1 * 3) + pub_r001124_9_1) + 26) & 127;
  int stage_v_119_2 = (((stage_v_109_2 * 3) + pub_r001124_9_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = ((pub_r001124_18_1 * 2) + 5) & 63;
  int stage_v_120_2 = ((pub_r001124_18_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = (((helper_flow_3_1 * 3) + pub_r001124_17_1) + 12) & 127;
  int stage_v_121_2 = (((helper_flow_3_2 * 3) + pub_r001124_17_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = ((pub_r001124_8_1 * 2) + 32) & 63;
  int stage_v_122_2 = ((pub_r001124_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (((stage_v_10_1 * 3) + pub_r001124_3_1) + 8) & 127;
  int stage_v_123_2 = (((stage_v_10_2 * 3) + pub_r001124_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = (((helper_flow_0_1 * 3) + pub_r001124_10_1) + 20) & 127;
  int stage_v_124_2 = (((helper_flow_0_2 * 3) + pub_r001124_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = ((pub_r001124_1_1 * 2) + 23) & 63;
  int stage_v_125_2 = ((pub_r001124_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001124_1_1 * 2) + 8) & 63;
  int stage_v_126_2 = ((pub_r001124_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = (((stage_v_42_1 * 3) + pub_r001124_11_1) + 14) & 127;
  int stage_v_127_2 = (((stage_v_42_2 * 3) + pub_r001124_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = ((pub_r001124_10_1 * 2) + 43) & 63;
  int stage_v_128_2 = ((pub_r001124_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001124_12_1 * 2) + 38) & 63;
  int stage_v_129_2 = ((pub_r001124_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001124_10_1 * 2) + 39) & 63;
  int stage_v_130_2 = ((pub_r001124_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001124_10_1 * 2) + 32) & 63;
  int stage_v_131_2 = ((pub_r001124_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001124_8_1 * 2) + 12) & 63;
  int stage_v_132_2 = ((pub_r001124_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((stage_v_67_1 * 3) + pub_r001124_10_1) + 40) & 127;
  int stage_v_133_2 = (((stage_v_67_2 * 3) + pub_r001124_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = ((pub_r001124_17_1 * 2) + 30) & 63;
  int stage_v_134_2 = ((pub_r001124_17_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (((helper_flow_2_1 * 3) + pub_r001124_19_1) + 31) & 127;
  int stage_v_135_2 = (((helper_flow_2_2 * 3) + pub_r001124_19_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = (((sec_r001124_14_1 * 3) + pub_r001124_3_1) + 13) & 127;
  int stage_v_136_2 = (((sec_r001124_14_2 * 3) + pub_r001124_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = (((stage_v_52_1 * 3) + pub_r001124_9_1) + 29) & 127;
  int stage_v_137_2 = (((stage_v_52_2 * 3) + pub_r001124_9_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = (((sec_r001124_15_1 * 3) + pub_r001124_12_1) + 5) & 127;
  int stage_v_138_2 = (((sec_r001124_15_2 * 3) + pub_r001124_12_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = ((pub_r001124_3_1 * 2) + 36) & 63;
  int stage_v_139_2 = ((pub_r001124_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (((stage_v_57_1 * 3) + pub_r001124_10_1) + 29) & 127;
  int stage_v_140_2 = (((stage_v_57_2 * 3) + pub_r001124_10_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = ((pub_r001124_20_1 * 2) + 22) & 63;
  int stage_v_141_2 = ((pub_r001124_20_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (((stage_v_112_1 * 3) + pub_r001124_4_1) + 28) & 127;
  int stage_v_142_2 = (((stage_v_112_2 * 3) + pub_r001124_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = (((stage_v_15_1 * 3) + pub_r001124_20_1) + 5) & 127;
  int stage_v_143_2 = (((stage_v_15_2 * 3) + pub_r001124_20_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = (((sec_r001124_4_1 * 3) + pub_r001124_20_1) + 17) & 127;
  int stage_v_144_2 = (((sec_r001124_4_2 * 3) + pub_r001124_20_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = (((stage_v_1_1 * 3) + pub_r001124_21_1) + 42) & 127;
  int stage_v_145_2 = (((stage_v_1_2 * 3) + pub_r001124_21_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = ((pub_r001124_4_1 * 2) + 38) & 63;
  int stage_v_146_2 = ((pub_r001124_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((stage_v_51_1 * 3) + pub_r001124_16_1) + 23) & 127;
  int stage_v_147_2 = (((stage_v_51_2 * 3) + pub_r001124_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = ((pub_r001124_19_1 * 2) + 22) & 63;
  int stage_v_148_2 = ((pub_r001124_19_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001124_4_1 * 2) + 24) & 63;
  int stage_v_149_2 = ((pub_r001124_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001124_9_1 * 2) + 29) & 63;
  int stage_v_150_2 = ((pub_r001124_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001124_17_1 * 2) + 25) & 63;
  int stage_v_151_2 = ((pub_r001124_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001124_15_1 * 2) + 23) & 63;
  int stage_v_152_2 = ((pub_r001124_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (((stage_v_54_1 * 3) + pub_r001124_14_1) + 8) & 127;
  int stage_v_153_2 = (((stage_v_54_2 * 3) + pub_r001124_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = (((stage_v_90_1 * 3) + pub_r001124_11_1) + 33) & 127;
  int stage_v_154_2 = (((stage_v_90_2 * 3) + pub_r001124_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = (((stage_v_34_1 * 3) + pub_r001124_18_1) + 24) & 127;
  int stage_v_155_2 = (((stage_v_34_2 * 3) + pub_r001124_18_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = (((sec_r001124_19_1 * 3) + pub_r001124_3_1) + 16) & 127;
  int stage_v_156_2 = (((sec_r001124_19_2 * 3) + pub_r001124_3_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((sec_r001124_15_1 * 3) + pub_r001124_17_1) + 25) & 127;
  int stage_v_157_2 = (((sec_r001124_15_2 * 3) + pub_r001124_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = (((stage_v_76_1 * 3) + pub_r001124_15_1) + 10) & 127;
  int stage_v_158_2 = (((stage_v_76_2 * 3) + pub_r001124_15_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = (((stage_v_60_1 * 3) + pub_r001124_21_1) + 8) & 127;
  int stage_v_159_2 = (((stage_v_60_2 * 3) + pub_r001124_21_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = (((stage_v_110_1 * 3) + pub_r001124_13_1) + 23) & 127;
  int stage_v_160_2 = (((stage_v_110_2 * 3) + pub_r001124_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = (((stage_v_53_1 * 3) + pub_r001124_19_1) + 29) & 127;
  int stage_v_161_2 = (((stage_v_53_2 * 3) + pub_r001124_19_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = (((stage_v_33_1 * 3) + pub_r001124_9_1) + 42) & 127;
  int stage_v_162_2 = (((stage_v_33_2 * 3) + pub_r001124_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = (((sec_r001124_1_1 * 3) + pub_r001124_0_1) + 40) & 127;
  int stage_v_163_2 = (((sec_r001124_1_2 * 3) + pub_r001124_0_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = (((stage_v_66_1 * 3) + pub_r001124_3_1) + 25) & 127;
  int stage_v_164_2 = (((stage_v_66_2 * 3) + pub_r001124_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = (((stage_v_153_1 * 3) + pub_r001124_17_1) + 10) & 127;
  int stage_v_165_2 = (((stage_v_153_2 * 3) + pub_r001124_17_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = ((pub_r001124_16_1 * 2) + 37) & 63;
  int stage_v_166_2 = ((pub_r001124_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((stage_v_105_1 * 3) + pub_r001124_11_1) + 39) & 127;
  int stage_v_167_2 = (((stage_v_105_2 * 3) + pub_r001124_11_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = (((stage_v_116_1 * 3) + pub_r001124_6_1) + 39) & 127;
  int stage_v_168_2 = (((stage_v_116_2 * 3) + pub_r001124_6_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = ((pub_r001124_10_1 * 2) + 6) & 63;
  int stage_v_169_2 = ((pub_r001124_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (((helper_flow_4_1 * 3) + pub_r001124_19_1) + 7) & 127;
  int stage_v_170_2 = (((helper_flow_4_2 * 3) + pub_r001124_19_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = ((pub_r001124_4_1 * 2) + 32) & 63;
  int stage_v_171_2 = ((pub_r001124_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((stage_v_63_1 * 3) + pub_r001124_8_1) + 39) & 127;
  int stage_v_172_2 = (((stage_v_63_2 * 3) + pub_r001124_8_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = (((stage_v_19_1 * 3) + pub_r001124_18_1) + 5) & 127;
  int stage_v_173_2 = (((stage_v_19_2 * 3) + pub_r001124_18_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = ((pub_r001124_5_1 * 2) + 9) & 63;
  int stage_v_174_2 = ((pub_r001124_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001124_6_1 * 2) + 22) & 63;
  int stage_v_175_2 = ((pub_r001124_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_60_1 * 3) + pub_r001124_17_1) + 40) & 127;
  int stage_v_176_2 = (((stage_v_60_2 * 3) + pub_r001124_17_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = ((pub_r001124_17_1 * 2) + 23) & 63;
  int stage_v_177_2 = ((pub_r001124_17_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (((stage_v_106_1 * 3) + pub_r001124_17_1) + 10) & 127;
  int stage_v_178_2 = (((stage_v_106_2 * 3) + pub_r001124_17_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = (((stage_v_117_1 * 3) + pub_r001124_0_1) + 24) & 127;
  int stage_v_179_2 = (((stage_v_117_2 * 3) + pub_r001124_0_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = ((pub_r001124_20_1 * 2) + 50) & 63;
  int stage_v_180_2 = ((pub_r001124_20_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (((stage_v_23_1 * 3) + pub_r001124_4_1) + 16) & 127;
  int stage_v_181_2 = (((stage_v_23_2 * 3) + pub_r001124_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = (((stage_v_42_1 * 3) + pub_r001124_20_1) + 33) & 127;
  int stage_v_182_2 = (((stage_v_42_2 * 3) + pub_r001124_20_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = (((sec_r001124_22_1 * 3) + pub_r001124_1_1) + 7) & 127;
  int stage_v_183_2 = (((sec_r001124_22_2 * 3) + pub_r001124_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = ((pub_r001124_2_1 * 2) + 50) & 63;
  int stage_v_184_2 = ((pub_r001124_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001124_20_1 * 2) + 17) & 63;
  int stage_v_185_2 = ((pub_r001124_20_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_163_1 * 3) + pub_r001124_15_1) + 12) & 127;
  int stage_v_186_2 = (((stage_v_163_2 * 3) + pub_r001124_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = (((stage_v_178_1 * 3) + pub_r001124_8_1) + 16) & 127;
  int stage_v_187_2 = (((stage_v_178_2 * 3) + pub_r001124_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = (((stage_v_90_1 * 3) + pub_r001124_2_1) + 44) & 127;
  int stage_v_188_2 = (((stage_v_90_2 * 3) + pub_r001124_2_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = (((stage_v_23_1 * 3) + pub_r001124_17_1) + 23) & 127;
  int stage_v_189_2 = (((stage_v_23_2 * 3) + pub_r001124_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = (((stage_v_164_1 * 3) + pub_r001124_2_1) + 37) & 127;
  int stage_v_190_2 = (((stage_v_164_2 * 3) + pub_r001124_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = (((stage_v_19_1 * 3) + pub_r001124_21_1) + 18) & 127;
  int stage_v_191_2 = (((stage_v_19_2 * 3) + pub_r001124_21_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = (((stage_v_116_1 * 3) + pub_r001124_20_1) + 6) & 127;
  int stage_v_192_2 = (((stage_v_116_2 * 3) + pub_r001124_20_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = (((stage_v_80_1 * 3) + pub_r001124_0_1) + 43) & 127;
  int stage_v_193_2 = (((stage_v_80_2 * 3) + pub_r001124_0_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = (((stage_v_113_1 * 3) + pub_r001124_18_1) + 15) & 127;
  int stage_v_194_2 = (((stage_v_113_2 * 3) + pub_r001124_18_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = ((pub_r001124_9_1 * 2) + 37) & 63;
  int stage_v_195_2 = ((pub_r001124_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((sec_r001124_17_1 * 3) + pub_r001124_2_1) + 25) & 127;
  int stage_v_196_2 = (((sec_r001124_17_2 * 3) + pub_r001124_2_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = (((stage_v_189_1 * 3) + pub_r001124_6_1) + 42) & 127;
  int stage_v_197_2 = (((stage_v_189_2 * 3) + pub_r001124_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = (((stage_v_24_1 * 3) + pub_r001124_4_1) + 11) & 127;
  int stage_v_198_2 = (((stage_v_24_2 * 3) + pub_r001124_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = (((sec_r001124_12_1 * 3) + pub_r001124_9_1) + 45) & 127;
  int stage_v_199_2 = (((sec_r001124_12_2 * 3) + pub_r001124_9_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = (((stage_v_107_1 * 3) + pub_r001124_10_1) + 35) & 127;
  int stage_v_200_2 = (((stage_v_107_2 * 3) + pub_r001124_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = (((stage_v_183_1 * 3) + pub_r001124_2_1) + 32) & 127;
  int stage_v_201_2 = (((stage_v_183_2 * 3) + pub_r001124_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = ((pub_r001124_11_1 * 2) + 48) & 63;
  int stage_v_202_2 = ((pub_r001124_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (((stage_v_87_1 * 3) + pub_r001124_13_1) + 36) & 127;
  int stage_v_203_2 = (((stage_v_87_2 * 3) + pub_r001124_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = ((pub_r001124_10_1 * 2) + 22) & 63;
  int stage_v_204_2 = ((pub_r001124_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = (((sec_r001124_7_1 * 3) + pub_r001124_19_1) + 26) & 127;
  int stage_v_205_2 = (((sec_r001124_7_2 * 3) + pub_r001124_19_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = (((stage_v_46_1 * 3) + pub_r001124_12_1) + 17) & 127;
  int stage_v_206_2 = (((stage_v_46_2 * 3) + pub_r001124_12_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = (((sec_r001124_6_1 * 3) + pub_r001124_2_1) + 14) & 127;
  int stage_v_207_2 = (((sec_r001124_6_2 * 3) + pub_r001124_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = (((stage_v_112_1 * 3) + pub_r001124_2_1) + 34) & 127;
  int stage_v_208_2 = (((stage_v_112_2 * 3) + pub_r001124_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_208_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_208_2 * 2)) & 255;
  int stage_v_209_1 = (((stage_v_67_1 * 3) + pub_r001124_16_1) + 34) & 127;
  int stage_v_209_2 = (((stage_v_67_2 * 3) + pub_r001124_16_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = (((stage_v_155_1 * 3) + pub_r001124_19_1) + 17) & 127;
  int stage_v_210_2 = (((stage_v_155_2 * 3) + pub_r001124_19_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = (((stage_v_135_1 * 3) + pub_r001124_19_1) + 15) & 127;
  int stage_v_211_2 = (((stage_v_135_2 * 3) + pub_r001124_19_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = ((pub_r001124_15_1 * 2) + 45) & 63;
  int stage_v_212_2 = ((pub_r001124_15_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = (((stage_v_143_1 * 3) + pub_r001124_12_1) + 44) & 127;
  int stage_v_213_2 = (((stage_v_143_2 * 3) + pub_r001124_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = (((helper_flow_6_1 * 3) + pub_r001124_11_1) + 7) & 127;
  int stage_v_214_2 = (((helper_flow_6_2 * 3) + pub_r001124_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_214_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_214_2 * 2)) & 255;
  int stage_v_215_1 = (((stage_v_119_1 * 3) + pub_r001124_21_1) + 6) & 127;
  int stage_v_215_2 = (((stage_v_119_2 * 3) + pub_r001124_21_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = ((pub_r001124_16_1 * 2) + 9) & 63;
  int stage_v_216_2 = ((pub_r001124_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((stage_v_42_1 * 3) + pub_r001124_20_1) + 5) & 127;
  int stage_v_217_2 = (((stage_v_42_2 * 3) + pub_r001124_20_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = (((stage_v_203_1 * 3) + pub_r001124_18_1) + 30) & 127;
  int stage_v_218_2 = (((stage_v_203_2 * 3) + pub_r001124_18_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = (((stage_v_153_1 * 3) + pub_r001124_4_1) + 27) & 127;
  int stage_v_219_2 = (((stage_v_153_2 * 3) + pub_r001124_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = (((stage_v_20_1 * 3) + pub_r001124_4_1) + 5) & 127;
  int stage_v_220_2 = (((stage_v_20_2 * 3) + pub_r001124_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = ((pub_r001124_13_1 * 2) + 41) & 63;
  int stage_v_221_2 = ((pub_r001124_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((pub_r001124_21_1 * 2) + 6) & 63;
  int stage_v_222_2 = ((pub_r001124_21_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((pub_r001124_3_1 * 2) + 40) & 63;
  int stage_v_223_2 = ((pub_r001124_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = (((stage_v_144_1 * 3) + pub_r001124_0_1) + 14) & 127;
  int stage_v_224_2 = (((stage_v_144_2 * 3) + pub_r001124_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = (((stage_v_60_1 * 3) + pub_r001124_8_1) + 28) & 127;
  int stage_v_225_2 = (((stage_v_60_2 * 3) + pub_r001124_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = ((pub_r001124_2_1 * 2) + 38) & 63;
  int stage_v_226_2 = ((pub_r001124_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = (((sec_r001124_9_1 * 3) + pub_r001124_20_1) + 45) & 127;
  int stage_v_227_2 = (((sec_r001124_9_2 * 3) + pub_r001124_20_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = (((stage_v_50_1 * 3) + pub_r001124_20_1) + 31) & 127;
  int stage_v_228_2 = (((stage_v_50_2 * 3) + pub_r001124_20_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = (((stage_v_217_1 * 3) + pub_r001124_7_1) + 12) & 127;
  int stage_v_229_2 = (((stage_v_217_2 * 3) + pub_r001124_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = (((stage_v_144_1 * 3) + pub_r001124_0_1) + 12) & 127;
  int stage_v_230_2 = (((stage_v_144_2 * 3) + pub_r001124_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = (((stage_v_165_1 * 3) + pub_r001124_2_1) + 39) & 127;
  int stage_v_231_2 = (((stage_v_165_2 * 3) + pub_r001124_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = (((sec_r001124_0_1 * 3) + pub_r001124_0_1) + 30) & 127;
  int stage_v_232_2 = (((sec_r001124_0_2 * 3) + pub_r001124_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = (((stage_v_1_1 * 3) + pub_r001124_20_1) + 18) & 127;
  int stage_v_233_2 = (((stage_v_1_2 * 3) + pub_r001124_20_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = ((pub_r001124_19_1 * 2) + 34) & 63;
  int stage_v_234_2 = ((pub_r001124_19_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = (((stage_v_15_1 * 3) + pub_r001124_2_1) + 26) & 127;
  int stage_v_235_2 = (((stage_v_15_2 * 3) + pub_r001124_2_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = (((stage_v_99_1 * 3) + pub_r001124_1_1) + 5) & 127;
  int stage_v_236_2 = (((stage_v_99_2 * 3) + pub_r001124_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = (((sec_r001124_16_1 * 3) + pub_r001124_14_1) + 19) & 127;
  int stage_v_237_2 = (((sec_r001124_16_2 * 3) + pub_r001124_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_237_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_237_2 * 2)) & 255;
  int stage_v_238_1 = (((stage_v_182_1 * 3) + pub_r001124_17_1) + 30) & 127;
  int stage_v_238_2 = (((stage_v_182_2 * 3) + pub_r001124_17_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = ((pub_r001124_2_1 * 2) + 42) & 63;
  int stage_v_239_2 = ((pub_r001124_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = (((stage_v_116_1 * 3) + pub_r001124_21_1) + 44) & 127;
  int stage_v_240_2 = (((stage_v_116_2 * 3) + pub_r001124_21_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = ((pub_r001124_21_1 * 2) + 15) & 63;
  int stage_v_241_2 = ((pub_r001124_21_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((pub_r001124_16_1 * 2) + 7) & 63;
  int stage_v_242_2 = ((pub_r001124_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((pub_r001124_2_1 * 2) + 36) & 63;
  int stage_v_243_2 = ((pub_r001124_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = (((stage_v_206_1 * 3) + pub_r001124_8_1) + 34) & 127;
  int stage_v_244_2 = (((stage_v_206_2 * 3) + pub_r001124_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = (((stage_v_117_1 * 3) + pub_r001124_3_1) + 40) & 127;
  int stage_v_245_2 = (((stage_v_117_2 * 3) + pub_r001124_3_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = (((stage_v_168_1 * 3) + pub_r001124_6_1) + 40) & 127;
  int stage_v_246_2 = (((stage_v_168_2 * 3) + pub_r001124_6_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = ((pub_r001124_20_1 * 2) + 36) & 63;
  int stage_v_247_2 = ((pub_r001124_20_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001124_14_1 * 2) + 6) & 63;
  int stage_v_248_2 = ((pub_r001124_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((pub_r001124_11_1 * 2) + 32) & 63;
  int stage_v_249_2 = ((pub_r001124_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001124_1_1 * 2) + 40) & 63;
  int stage_v_250_2 = ((pub_r001124_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = (((stage_v_60_1 * 3) + pub_r001124_7_1) + 18) & 127;
  int stage_v_251_2 = (((stage_v_60_2 * 3) + pub_r001124_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = ((pub_r001124_21_1 * 2) + 9) & 63;
  int stage_v_252_2 = ((pub_r001124_21_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = (((stage_v_82_1 * 3) + pub_r001124_9_1) + 31) & 127;
  int stage_v_253_2 = (((stage_v_82_2 * 3) + pub_r001124_9_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = ((pub_r001124_0_1 * 2) + 30) & 63;
  int stage_v_254_2 = ((pub_r001124_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((pub_r001124_15_1 * 2) + 14) & 63;
  int stage_v_255_2 = ((pub_r001124_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001124_3_1 * 2) + 39) & 63;
  int stage_v_256_2 = ((pub_r001124_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001124_3_1 * 2) + 50) & 63;
  int stage_v_257_2 = ((pub_r001124_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((stage_v_160_1 * 3) + pub_r001124_12_1) + 40) & 127;
  int stage_v_258_2 = (((stage_v_160_2 * 3) + pub_r001124_12_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = ((pub_r001124_17_1 * 2) + 13) & 63;
  int stage_v_259_2 = ((pub_r001124_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = (((stage_v_85_1 * 3) + pub_r001124_0_1) + 14) & 127;
  int stage_v_260_2 = (((stage_v_85_2 * 3) + pub_r001124_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = (((stage_v_170_1 * 3) + pub_r001124_14_1) + 29) & 127;
  int stage_v_261_2 = (((stage_v_170_2 * 3) + pub_r001124_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = (((stage_v_261_1 * 3) + pub_r001124_7_1) + 5) & 127;
  int stage_v_262_2 = (((stage_v_261_2 * 3) + pub_r001124_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_262_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_262_2 * 2)) & 255;
  int stage_v_263_1 = ((pub_r001124_6_1 * 2) + 27) & 63;
  int stage_v_263_2 = ((pub_r001124_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = (((stage_v_16_1 * 3) + pub_r001124_5_1) + 23) & 127;
  int stage_v_264_2 = (((stage_v_16_2 * 3) + pub_r001124_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = ((pub_r001124_19_1 * 2) + 21) & 63;
  int stage_v_265_2 = ((pub_r001124_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = (((stage_v_107_1 * 3) + pub_r001124_17_1) + 25) & 127;
  int stage_v_266_2 = (((stage_v_107_2 * 3) + pub_r001124_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = (((stage_v_70_1 * 3) + pub_r001124_0_1) + 35) & 127;
  int stage_v_267_2 = (((stage_v_70_2 * 3) + pub_r001124_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = ((pub_r001124_12_1 * 2) + 37) & 63;
  int stage_v_268_2 = ((pub_r001124_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001124_14_1 * 2) + 17) & 63;
  int stage_v_269_2 = ((pub_r001124_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001124_2_1 * 2) + 31) & 63;
  int stage_v_270_2 = ((pub_r001124_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = (((stage_v_235_1 * 3) + pub_r001124_21_1) + 11) & 127;
  int stage_v_271_2 = (((stage_v_235_2 * 3) + pub_r001124_21_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = (((stage_v_205_1 * 3) + pub_r001124_15_1) + 27) & 127;
  int stage_v_272_2 = (((stage_v_205_2 * 3) + pub_r001124_15_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = ((pub_r001124_8_1 * 2) + 44) & 63;
  int stage_v_273_2 = ((pub_r001124_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = (((stage_v_172_1 * 3) + pub_r001124_16_1) + 30) & 127;
  int stage_v_274_2 = (((stage_v_172_2 * 3) + pub_r001124_16_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = ((pub_r001124_13_1 * 2) + 48) & 63;
  int stage_v_275_2 = ((pub_r001124_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((pub_r001124_16_1 * 2) + 25) & 63;
  int stage_v_276_2 = ((pub_r001124_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = (((stage_v_23_1 * 3) + pub_r001124_17_1) + 33) & 127;
  int stage_v_277_2 = (((stage_v_23_2 * 3) + pub_r001124_17_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = (((stage_v_206_1 * 3) + pub_r001124_20_1) + 15) & 127;
  int stage_v_278_2 = (((stage_v_206_2 * 3) + pub_r001124_20_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = (((stage_v_156_1 * 3) + pub_r001124_3_1) + 21) & 127;
  int stage_v_279_2 = (((stage_v_156_2 * 3) + pub_r001124_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = ((pub_r001124_20_1 * 2) + 18) & 63;
  int stage_v_280_2 = ((pub_r001124_20_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((pub_r001124_2_1 * 2) + 50) & 63;
  int stage_v_281_2 = ((pub_r001124_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((pub_r001124_4_1 * 2) + 49) & 63;
  int stage_v_282_2 = ((pub_r001124_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = (((stage_v_109_1 * 3) + pub_r001124_8_1) + 28) & 127;
  int stage_v_283_2 = (((stage_v_109_2 * 3) + pub_r001124_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = (((stage_v_232_1 * 3) + pub_r001124_10_1) + 22) & 127;
  int stage_v_284_2 = (((stage_v_232_2 * 3) + pub_r001124_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = ((pub_r001124_19_1 * 2) + 28) & 63;
  int stage_v_285_2 = ((pub_r001124_19_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = (((stage_v_116_1 * 3) + pub_r001124_20_1) + 26) & 127;
  int stage_v_286_2 = (((stage_v_116_2 * 3) + pub_r001124_20_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = (((sec_r001124_0_1 * 3) + pub_r001124_4_1) + 32) & 127;
  int stage_v_287_2 = (((sec_r001124_0_2 * 3) + pub_r001124_4_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = (((stage_v_267_1 * 3) + pub_r001124_0_1) + 8) & 127;
  int stage_v_288_2 = (((stage_v_267_2 * 3) + pub_r001124_0_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = (((helper_flow_1_1 * 3) + pub_r001124_7_1) + 41) & 127;
  int stage_v_289_2 = (((helper_flow_1_2 * 3) + pub_r001124_7_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = (((stage_v_51_1 * 3) + pub_r001124_2_1) + 27) & 127;
  int stage_v_290_2 = (((stage_v_51_2 * 3) + pub_r001124_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = ((pub_r001124_12_1 * 2) + 5) & 63;
  int stage_v_291_2 = ((pub_r001124_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((pub_r001124_6_1 * 2) + 46) & 63;
  int stage_v_292_2 = ((pub_r001124_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = (((stage_v_158_1 * 3) + pub_r001124_5_1) + 40) & 127;
  int stage_v_293_2 = (((stage_v_158_2 * 3) + pub_r001124_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = (((stage_v_228_1 * 3) + pub_r001124_19_1) + 10) & 127;
  int stage_v_294_2 = (((stage_v_228_2 * 3) + pub_r001124_19_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = ((pub_r001124_13_1 * 2) + 34) & 63;
  int stage_v_295_2 = ((pub_r001124_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = (((helper_flow_4_1 * 3) + pub_r001124_5_1) + 25) & 127;
  int stage_v_296_2 = (((helper_flow_4_2 * 3) + pub_r001124_5_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = ((pub_r001124_20_1 * 2) + 24) & 63;
  int stage_v_297_2 = ((pub_r001124_20_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = (((sec_r001124_0_1 * 3) + pub_r001124_6_1) + 20) & 127;
  int stage_v_298_2 = (((sec_r001124_0_2 * 3) + pub_r001124_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = ((pub_r001124_17_1 * 2) + 23) & 63;
  int stage_v_299_2 = ((pub_r001124_17_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((pub_r001124_14_1 * 2) + 19) & 63;
  int stage_v_300_2 = ((pub_r001124_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = (((stage_v_105_1 * 3) + pub_r001124_3_1) + 22) & 127;
  int stage_v_301_2 = (((stage_v_105_2 * 3) + pub_r001124_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = ((pub_r001124_9_1 * 2) + 26) & 63;
  int stage_v_302_2 = ((pub_r001124_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = (((stage_v_173_1 * 3) + pub_r001124_5_1) + 8) & 127;
  int stage_v_303_2 = (((stage_v_173_2 * 3) + pub_r001124_5_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = (((stage_v_162_1 * 3) + pub_r001124_16_1) + 13) & 127;
  int stage_v_304_2 = (((stage_v_162_2 * 3) + pub_r001124_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = (((stage_v_88_1 * 3) + pub_r001124_7_1) + 27) & 127;
  int stage_v_305_2 = (((stage_v_88_2 * 3) + pub_r001124_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_305_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_305_2 * 2)) & 255;
  int stage_v_306_1 = (((stage_v_161_1 * 3) + pub_r001124_0_1) + 13) & 127;
  int stage_v_306_2 = (((stage_v_161_2 * 3) + pub_r001124_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = ((pub_r001124_9_1 * 2) + 49) & 63;
  int stage_v_307_2 = ((pub_r001124_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001124_19_1 * 2) + 32) & 63;
  int stage_v_308_2 = ((pub_r001124_19_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((pub_r001124_9_1 * 2) + 22) & 63;
  int stage_v_309_2 = ((pub_r001124_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001124_9_1 * 2) + 21) & 63;
  int stage_v_310_2 = ((pub_r001124_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((pub_r001124_20_1 * 2) + 8) & 63;
  int stage_v_311_2 = ((pub_r001124_20_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = ((pub_r001124_2_1 * 2) + 16) & 63;
  int stage_v_312_2 = ((pub_r001124_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = (((stage_v_124_1 * 3) + pub_r001124_21_1) + 10) & 127;
  int stage_v_313_2 = (((stage_v_124_2 * 3) + pub_r001124_21_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = ((pub_r001124_17_1 * 2) + 32) & 63;
  int stage_v_314_2 = ((pub_r001124_17_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001124_1_1 * 2) + 24) & 63;
  int stage_v_315_2 = ((pub_r001124_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((pub_r001124_8_1 * 2) + 9) & 63;
  int stage_v_316_2 = ((pub_r001124_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = (((stage_v_59_1 * 3) + pub_r001124_6_1) + 35) & 127;
  int stage_v_317_2 = (((stage_v_59_2 * 3) + pub_r001124_6_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = ((pub_r001124_9_1 * 2) + 39) & 63;
  int stage_v_318_2 = ((pub_r001124_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = (((stage_v_235_1 * 3) + pub_r001124_21_1) + 28) & 127;
  int stage_v_319_2 = (((stage_v_235_2 * 3) + pub_r001124_21_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = ((pub_r001124_0_1 * 2) + 47) & 63;
  int stage_v_320_2 = ((pub_r001124_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = (((stage_v_225_1 * 3) + pub_r001124_2_1) + 37) & 127;
  int stage_v_321_2 = (((stage_v_225_2 * 3) + pub_r001124_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = ((pub_r001124_13_1 * 2) + 41) & 63;
  int stage_v_322_2 = ((pub_r001124_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001124_20_1 * 2) + 34) & 63;
  int stage_v_323_2 = ((pub_r001124_20_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = (((stage_v_109_1 * 3) + pub_r001124_0_1) + 27) & 127;
  int stage_v_324_2 = (((stage_v_109_2 * 3) + pub_r001124_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = ((pub_r001124_20_1 * 2) + 46) & 63;
  int stage_v_325_2 = ((pub_r001124_20_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((pub_r001124_4_1 * 2) + 27) & 63;
  int stage_v_326_2 = ((pub_r001124_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = (((stage_v_213_1 * 3) + pub_r001124_3_1) + 10) & 127;
  int stage_v_327_2 = (((stage_v_213_2 * 3) + pub_r001124_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = ((pub_r001124_8_1 * 2) + 8) & 63;
  int stage_v_328_2 = ((pub_r001124_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001124_21_1 * 2) + 20) & 63;
  int stage_v_329_2 = ((pub_r001124_21_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = (((stage_v_189_1 * 3) + pub_r001124_18_1) + 28) & 127;
  int stage_v_330_2 = (((stage_v_189_2 * 3) + pub_r001124_18_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = (((stage_v_54_1 * 3) + pub_r001124_19_1) + 6) & 127;
  int stage_v_331_2 = (((stage_v_54_2 * 3) + pub_r001124_19_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_331_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_331_2 * 2)) & 255;
  int stage_v_332_1 = (((stage_v_59_1 * 3) + pub_r001124_2_1) + 36) & 127;
  int stage_v_332_2 = (((stage_v_59_2 * 3) + pub_r001124_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = (((stage_v_156_1 * 3) + pub_r001124_9_1) + 19) & 127;
  int stage_v_333_2 = (((stage_v_156_2 * 3) + pub_r001124_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = ((pub_r001124_14_1 * 2) + 18) & 63;
  int stage_v_334_2 = ((pub_r001124_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = (((sec_r001124_14_1 * 3) + pub_r001124_17_1) + 21) & 127;
  int stage_v_335_2 = (((sec_r001124_14_2 * 3) + pub_r001124_17_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = (((sec_r001124_8_1 * 3) + pub_r001124_1_1) + 23) & 127;
  int stage_v_336_2 = (((sec_r001124_8_2 * 3) + pub_r001124_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = ((pub_r001124_7_1 * 2) + 8) & 63;
  int stage_v_337_2 = ((pub_r001124_7_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = (((sec_r001124_9_1 * 3) + pub_r001124_5_1) + 22) & 127;
  int stage_v_338_2 = (((sec_r001124_9_2 * 3) + pub_r001124_5_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = (((stage_v_267_1 * 3) + pub_r001124_20_1) + 5) & 127;
  int stage_v_339_2 = (((stage_v_267_2 * 3) + pub_r001124_20_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = (((stage_v_89_1 * 3) + pub_r001124_8_1) + 20) & 127;
  int stage_v_340_2 = (((stage_v_89_2 * 3) + pub_r001124_8_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = (((stage_v_137_1 * 3) + pub_r001124_19_1) + 18) & 127;
  int stage_v_341_2 = (((stage_v_137_2 * 3) + pub_r001124_19_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = (((sec_r001124_16_1 * 3) + pub_r001124_0_1) + 4) & 127;
  int stage_v_342_2 = (((sec_r001124_16_2 * 3) + pub_r001124_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = (((sec_r001124_14_1 * 3) + pub_r001124_16_1) + 26) & 127;
  int stage_v_343_2 = (((sec_r001124_14_2 * 3) + pub_r001124_16_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = ((pub_r001124_9_1 * 2) + 35) & 63;
  int stage_v_344_2 = ((pub_r001124_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = ((pub_r001124_8_1 * 2) + 18) & 63;
  int stage_v_345_2 = ((pub_r001124_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = (((stage_v_80_1 * 3) + pub_r001124_14_1) + 4) & 127;
  int stage_v_346_2 = (((stage_v_80_2 * 3) + pub_r001124_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = (((stage_v_172_1 * 3) + pub_r001124_12_1) + 32) & 127;
  int stage_v_347_2 = (((stage_v_172_2 * 3) + pub_r001124_12_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = (((stage_v_283_1 * 3) + pub_r001124_19_1) + 35) & 127;
  int stage_v_348_2 = (((stage_v_283_2 * 3) + pub_r001124_19_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = (((sec_r001124_4_1 * 3) + pub_r001124_7_1) + 11) & 127;
  int stage_v_349_2 = (((sec_r001124_4_2 * 3) + pub_r001124_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = ((pub_r001124_15_1 * 2) + 50) & 63;
  int stage_v_350_2 = ((pub_r001124_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = ((pub_r001124_20_1 * 2) + 31) & 63;
  int stage_v_351_2 = ((pub_r001124_20_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = (((stage_v_36_1 * 3) + pub_r001124_11_1) + 5) & 127;
  int stage_v_352_2 = (((stage_v_36_2 * 3) + pub_r001124_11_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = ((pub_r001124_1_1 * 2) + 20) & 63;
  int stage_v_353_2 = ((pub_r001124_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = (((stage_v_190_1 * 3) + pub_r001124_18_1) + 42) & 127;
  int stage_v_354_2 = (((stage_v_190_2 * 3) + pub_r001124_18_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = ((pub_r001124_18_1 * 2) + 44) & 63;
  int stage_v_355_2 = ((pub_r001124_18_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = (((stage_v_109_1 * 3) + pub_r001124_5_1) + 6) & 127;
  int stage_v_356_2 = (((stage_v_109_2 * 3) + pub_r001124_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = (((stage_v_155_1 * 3) + pub_r001124_13_1) + 28) & 127;
  int stage_v_357_2 = (((stage_v_155_2 * 3) + pub_r001124_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = (((stage_v_258_1 * 3) + pub_r001124_18_1) + 12) & 127;
  int stage_v_358_2 = (((stage_v_258_2 * 3) + pub_r001124_18_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = ((pub_r001124_4_1 * 2) + 42) & 63;
  int stage_v_359_2 = ((pub_r001124_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = (((helper_flow_1_1 * 3) + pub_r001124_19_1) + 31) & 127;
  int stage_v_360_2 = (((helper_flow_1_2 * 3) + pub_r001124_19_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = (((stage_v_112_1 * 3) + pub_r001124_18_1) + 41) & 127;
  int stage_v_361_2 = (((stage_v_112_2 * 3) + pub_r001124_18_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = ((pub_r001124_6_1 * 2) + 7) & 63;
  int stage_v_362_2 = ((pub_r001124_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = (((stage_v_81_1 * 3) + pub_r001124_11_1) + 8) & 127;
  int stage_v_363_2 = (((stage_v_81_2 * 3) + pub_r001124_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = (((stage_v_361_1 * 3) + pub_r001124_16_1) + 17) & 127;
  int stage_v_364_2 = (((stage_v_361_2 * 3) + pub_r001124_16_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = (((stage_v_59_1 * 3) + pub_r001124_16_1) + 39) & 127;
  int stage_v_365_2 = (((stage_v_59_2 * 3) + pub_r001124_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = ((pub_r001124_2_1 * 2) + 42) & 63;
  int stage_v_366_2 = ((pub_r001124_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = ((pub_r001124_15_1 * 2) + 29) & 63;
  int stage_v_367_2 = ((pub_r001124_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = (((stage_v_61_1 * 3) + pub_r001124_3_1) + 39) & 127;
  int stage_v_368_2 = (((stage_v_61_2 * 3) + pub_r001124_3_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = (((stage_v_244_1 * 3) + pub_r001124_6_1) + 39) & 127;
  int stage_v_369_2 = (((stage_v_244_2 * 3) + pub_r001124_6_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = (((stage_v_293_1 * 3) + pub_r001124_16_1) + 12) & 127;
  int stage_v_370_2 = (((stage_v_293_2 * 3) + pub_r001124_16_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = (((stage_v_89_1 * 3) + pub_r001124_12_1) + 41) & 127;
  int stage_v_371_2 = (((stage_v_89_2 * 3) + pub_r001124_12_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = ((pub_r001124_17_1 * 2) + 30) & 63;
  int stage_v_372_2 = ((pub_r001124_17_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001124_12_1 * 2) + 11) & 63;
  int stage_v_373_2 = ((pub_r001124_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((pub_r001124_2_1 * 2) + 9) & 63;
  int stage_v_374_2 = ((pub_r001124_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = (((stage_v_305_1 * 3) + pub_r001124_17_1) + 42) & 127;
  int stage_v_375_2 = (((stage_v_305_2 * 3) + pub_r001124_17_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001124_10_1 != sec_r001124_10_2);
  __CPROVER_assume(sec_r001124_21_1 != sec_r001124_21_2);
  __CPROVER_assume(pub_r001124_2_1 == pub_r001124_2_2);
  __CPROVER_assume(sec_r001124_1_1 != sec_r001124_1_2);
  __CPROVER_assume(pub_r001124_3_1 == pub_r001124_3_2);
  __CPROVER_assume(pub_r001124_10_1 == pub_r001124_10_2);
  __CPROVER_assume(pub_r001124_0_1 == pub_r001124_0_2);
  __CPROVER_assume(sec_r001124_11_1 != sec_r001124_11_2);
  __CPROVER_assume(pub_r001124_20_1 == pub_r001124_20_2);
  __CPROVER_assume(pub_r001124_1_1 == pub_r001124_1_2);
  __CPROVER_assume(pub_r001124_7_1 == pub_r001124_7_2);
  __CPROVER_assume(sec_r001124_5_1 != sec_r001124_5_2);
  __CPROVER_assume(sec_r001124_6_1 != sec_r001124_6_2);
  __CPROVER_assume(sec_r001124_4_1 != sec_r001124_4_2);
  __CPROVER_assume(pub_r001124_11_1 == pub_r001124_11_2);
  __CPROVER_assume(pub_r001124_19_1 == pub_r001124_19_2);
  __CPROVER_assume(pub_r001124_15_1 == pub_r001124_15_2);
  __CPROVER_assume(sec_r001124_22_1 != sec_r001124_22_2);
  __CPROVER_assume(sec_r001124_15_1 != sec_r001124_15_2);
  __CPROVER_assume(sec_r001124_3_1 != sec_r001124_3_2);
  __CPROVER_assume(sec_r001124_8_1 != sec_r001124_8_2);
  __CPROVER_assume(sec_r001124_0_1 != sec_r001124_0_2);
  __CPROVER_assume(pub_r001124_6_1 == pub_r001124_6_2);
  __CPROVER_assume(pub_r001124_17_1 == pub_r001124_17_2);
  __CPROVER_assume(sec_r001124_18_1 != sec_r001124_18_2);
  __CPROVER_assume(sec_r001124_14_1 != sec_r001124_14_2);
  __CPROVER_assume(sec_r001124_19_1 != sec_r001124_19_2);
  __CPROVER_assume(sec_r001124_7_1 != sec_r001124_7_2);
  __CPROVER_assume(sec_r001124_9_1 != sec_r001124_9_2);
  __CPROVER_assume(pub_r001124_18_1 == pub_r001124_18_2);
  __CPROVER_assume(sec_r001124_16_1 != sec_r001124_16_2);
  __CPROVER_assume(sec_r001124_20_1 != sec_r001124_20_2);
  __CPROVER_assume(pub_r001124_4_1 == pub_r001124_4_2);
  __CPROVER_assume(pub_r001124_5_1 == pub_r001124_5_2);
  __CPROVER_assume(pub_r001124_12_1 == pub_r001124_12_2);
  __CPROVER_assume(pub_r001124_14_1 == pub_r001124_14_2);
  __CPROVER_assume(sec_r001124_13_1 != sec_r001124_13_2);
  __CPROVER_assume(pub_r001124_9_1 == pub_r001124_9_2);
  __CPROVER_assume(pub_r001124_21_1 == pub_r001124_21_2);
  __CPROVER_assume(pub_r001124_16_1 == pub_r001124_16_2);
  __CPROVER_assume(sec_r001124_17_1 != sec_r001124_17_2);
  __CPROVER_assume(sec_r001124_12_1 != sec_r001124_12_2);
  __CPROVER_assume(pub_r001124_13_1 == pub_r001124_13_2);
  __CPROVER_assume(pub_r001124_8_1 == pub_r001124_8_2);
  __CPROVER_assume(sec_r001124_2_1 != sec_r001124_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.mode == st_var_1_2.mode);
  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.density == st_var_2_2.density);
  assert(st_var_2_1.scale == st_var_2_2.scale);
  assert(st_var_2_1.stride == st_var_2_2.stride);
  assert(st_var_2_1.dim == st_var_2_2.dim);
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
}


