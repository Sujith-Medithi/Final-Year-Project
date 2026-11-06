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
struct FilterState_R000479_7913_0
{
  int gain_db;
  unsigned char prev_in;
  int cutoff;
  int prev_out;
  int damping;
  int mode;
  int buffer[3];
};
struct AudioFrame_R000479_7913_1
{
  int peak;
  int channels;
  int sample_rate;
  unsigned char envelope;
  int buffer[3];
};
struct CipherContext_R000479_7913_2
{
  unsigned char tag;
  int iv;
  int counter;
  int nonce;
  int buffer[3];
};
union ColorPixel_R000479_7913_0
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
void fn_R000479_7913_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000479_7913_0 st_1 = {0};
  struct FilterState_R000479_7913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int scale_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_40_1 > 38)
  {
    acc_1 = ((acc_1 + (scale_40_1 * 2)) + 5) & 127;
    aux_1 ^= scale_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_40_2 > 38)
  {
    acc_2 = ((acc_2 + (scale_40_2 * 2)) + 5) & 127;
    aux_2 ^= scale_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_75_1) & 63;
  aux_2 = (aux_2 + bound_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_40_1 == scale_40_2);
  assert(bound_75_1 == bound_75_2);
}

int fn_R000479_7913_0(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000479_7913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int scale_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_40 > 38)
  {
    acc = ((acc + (scale_40 * 2)) + 5) & 127;
    aux ^= scale_40 & 15;
  }
  else
  {
    acc = ((acc - scale_40) + 11) & 127;
    aux += 3;
  }
  int bound_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_75) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000479_7913_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000479_7913_1 st_1 = {0};
  struct AudioFrame_R000479_7913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int offset_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_57_1)
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

  switch (offset_57_2)
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_75_1 = local_arr_1[aux_1 % 3];
  int accumulator_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_75_2 * 2)) & 127;
  int tracker_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_53_1 > 50)
  {
    acc_1 = ((acc_1 + (tracker_53_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_53_2 > 50)
  {
    acc_2 = ((acc_2 + (tracker_53_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_53_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_57_1 == offset_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_75_1 == accumulator_75_2);
  assert(tracker_53_1 == tracker_53_2);
}

int fn_R000479_7913_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000479_7913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int offset_57 = (aux + st.buffer[1]) & 3;
  switch (offset_57)
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
  int local_arr[3] = {4, 9, 15};
  int accumulator_75 = local_arr[aux % 3];
  acc = (acc + (accumulator_75 * 2)) & 127;
  int tracker_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_53 > 50)
  {
    acc = ((acc + (tracker_53 * 2)) + 5) & 127;
    aux ^= tracker_53 & 15;
  }
  else
  {
    acc = ((acc - tracker_53) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000479_7913_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000479_7913_1 st_1 = {0};
  struct AudioFrame_R000479_7913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int metric_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_99_1)
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

  switch (metric_99_2)
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
  int window_51_1 = local_arr_1[aux_1 % 3];
  int window_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_51_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_99_1 == metric_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_51_1 == window_51_2);
}

int fn_R000479_7913_2(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000479_7913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int metric_99 = (aux + st.buffer[1]) & 3;
  switch (metric_99)
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
  int window_51 = local_arr[aux % 3];
  acc = (acc + (window_51 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000479_7913_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000479_7913_0 st_1 = {0};
  struct FilterState_R000479_7913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_47_1 = local_arr_1[aux_1 % 3];
  int threshold_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_47_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_74_1 > 26)
  {
    acc_1 = ((acc_1 + (threshold_74_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_74_2 > 26)
  {
    acc_2 = ((acc_2 + (threshold_74_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_74_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_47_1 == threshold_47_2);
  assert(threshold_74_1 == threshold_74_2);
}

int fn_R000479_7913_3(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000479_7913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int threshold_47 = local_arr[aux % 3];
  acc = (acc + (threshold_47 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_74 > 26)
  {
    acc = ((acc + (threshold_74 * 2)) + 5) & 127;
    aux ^= threshold_74 & 15;
  }
  else
  {
    acc = ((acc - threshold_74) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000479_7913_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000479_7913_2 st_1 = {0};
  struct CipherContext_R000479_7913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_78_1) & 63;
  aux_2 = (aux_2 + window_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_78_1 == window_78_2);
}

int fn_R000479_7913_4(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000479_7913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_78) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000479_7913_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000479_7913_0 st_1 = {0};
  struct FilterState_R000479_7913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_52_1 = local_arr_1[aux_1 % 3];
  int segment_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_52_2 * 2)) & 127;
  int quantum_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_14_1) & 63;
  aux_2 = (aux_2 + quantum_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_74_1)
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

  switch (segment_74_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_52_1 == segment_52_2);
  assert(quantum_14_1 == quantum_14_2);
  assert(segment_74_1 == segment_74_2);
}

int fn_R000479_7913_5(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000479_7913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int segment_52 = local_arr[aux % 3];
  acc = (acc + (segment_52 * 2)) & 127;
  int quantum_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_14) & 63;
  acc ^= aux;
  int segment_74 = (aux + st.buffer[1]) & 3;
  switch (segment_74)
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

void fn_R000479_7913_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000479_7913_1 st_1 = {0};
  struct AudioFrame_R000479_7913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_57_1)
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

  switch (sample_57_2)
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
  int parity_82_1 = local_arr_1[aux_1 % 3];
  int parity_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_82_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_57_1 == sample_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_82_1 == parity_82_2);
}

int fn_R000479_7913_6(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000479_7913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_57 = (aux + st.buffer[1]) & 3;
  switch (sample_57)
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
  int parity_82 = local_arr[aux % 3];
  acc = (acc + (parity_82 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000479_7913_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000479_7913_1 st_1 = {0};
  struct AudioFrame_R000479_7913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_88_1 > 20)
  {
    acc_1 = ((acc_1 + (stride_88_1 * 2)) + 5) & 127;
    aux_1 ^= stride_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_88_2 > 20)
  {
    acc_2 = ((acc_2 + (stride_88_2 * 2)) + 5) & 127;
    aux_2 ^= stride_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_88_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_67_1)
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

  switch (checksum_67_2)
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

  int phase_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_42_1) & 63;
  aux_2 = (aux_2 + phase_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_88_1 == stride_88_2);
  assert(checksum_67_1 == checksum_67_2);
  assert(phase_42_1 == phase_42_2);
}

int fn_R000479_7913_7(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000479_7913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_88 > 20)
  {
    acc = ((acc + (stride_88 * 2)) + 5) & 127;
    aux ^= stride_88 & 15;
  }
  else
  {
    acc = ((acc - stride_88) + 11) & 127;
    aux += 3;
  }
  int checksum_67 = (aux + st.buffer[1]) & 3;
  switch (checksum_67)
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

  int phase_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_42) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000479_7913_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000479_7913_1 st_1 = {0};
  struct AudioFrame_R000479_7913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_35_1) & 63;
  aux_2 = (aux_2 + vector_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_43_1 > 16)
  {
    acc_1 = ((acc_1 + (stride_43_1 * 2)) + 5) & 127;
    aux_1 ^= stride_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_43_2 > 16)
  {
    acc_2 = ((acc_2 + (stride_43_2 * 2)) + 5) & 127;
    aux_2 ^= stride_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_43_1 = local_arr_1[aux_1 % 3];
  int bound_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_43_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_35_1 == vector_35_2);
  assert(stride_43_1 == stride_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_43_1 == bound_43_2);
}

int fn_R000479_7913_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000479_7913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_35) & 63;
  acc ^= aux;
  int stride_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_43 > 16)
  {
    acc = ((acc + (stride_43 * 2)) + 5) & 127;
    aux ^= stride_43 & 15;
  }
  else
  {
    acc = ((acc - stride_43) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_43 = local_arr[aux % 3];
  acc = (acc + (bound_43 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000479_7913_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000479_7913_1 st_1 = {0};
  struct AudioFrame_R000479_7913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_18_1 = local_arr_1[aux_1 % 3];
  int parity_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_18_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
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

  assert(parity_18_1 == parity_18_2);
}

int fn_R000479_7913_9(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000479_7913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int parity_18 = local_arr[aux % 3];
  acc = (acc + (parity_18 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000479_7913_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000479_7913_2 st_1 = {0};
  struct CipherContext_R000479_7913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int scale_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_81_1) & 63;
  aux_2 = (aux_2 + scale_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_15_1 = local_arr_1[aux_1 % 3];
  int parity_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_15_2 * 2)) & 127;
  int bound_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_62_1)
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

  switch (bound_62_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_81_1 == scale_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_15_1 == parity_15_2);
  assert(bound_62_1 == bound_62_2);
}

int fn_R000479_7913_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000479_7913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int scale_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_81) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_15 = local_arr[aux % 3];
  acc = (acc + (parity_15 * 2)) & 127;
  int bound_62 = (aux + st.buffer[1]) & 3;
  switch (bound_62)
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

void fn_R000479_7913_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000479_7913_0 st_1 = {0};
  struct FilterState_R000479_7913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_56_1 = local_arr_1[aux_1 % 3];
  int phase_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_56_2 * 2)) & 127;
  int window_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_81_1)
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

  switch (window_81_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_30_1) & 63;
  aux_2 = (aux_2 + residue_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_56_1 == phase_56_2);
  assert(window_81_1 == window_81_2);
  assert(residue_30_1 == residue_30_2);
}

int fn_R000479_7913_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000479_7913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int phase_56 = local_arr[aux % 3];
  acc = (acc + (phase_56 * 2)) & 127;
  int window_81 = (aux + st.buffer[1]) & 3;
  switch (window_81)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_30) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000479_7913_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000479_7913_1 st_1 = {0};
  struct AudioFrame_R000479_7913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int metric_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_29_1)
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

  switch (metric_29_2)
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
  int weight_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_68_1) & 63;
  aux_2 = (aux_2 + weight_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_29_1 == metric_29_2);
  assert(weight_68_1 == weight_68_2);
}

int fn_R000479_7913_12(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000479_7913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int metric_29 = (aux + st.buffer[1]) & 3;
  switch (metric_29)
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
  int weight_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_68) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000479_7913_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000479_7913_0 st_1 = {0};
  struct FilterState_R000479_7913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int tally_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_52_1)
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

  switch (tally_52_2)
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

  int stride_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_39_1) & 63;
  aux_2 = (aux_2 + stride_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_52_1 == tally_52_2);
  assert(stride_39_1 == stride_39_2);
}

int fn_R000479_7913_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000479_7913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int tally_52 = (aux + st.buffer[1]) & 3;
  switch (tally_52)
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

  int stride_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_39) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000479_7913_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000479_7913_0 st_1 = {0};
  struct FilterState_R000479_7913_0 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_22_1 = local_arr_1[aux_1 % 3];
  int mask_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_22_2 * 2)) & 127;
  int tally_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_29_1)
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

  switch (tally_29_2)
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

  int window_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_26_1 > 48)
  {
    acc_1 = ((acc_1 + (window_26_1 * 2)) + 5) & 127;
    aux_1 ^= window_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_26_2 > 48)
  {
    acc_2 = ((acc_2 + (window_26_2 * 2)) + 5) & 127;
    aux_2 ^= window_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_26_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_22_1 == mask_22_2);
  assert(tally_29_1 == tally_29_2);
  assert(window_26_1 == window_26_2);
}

int fn_R000479_7913_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000479_7913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_22 = local_arr[aux % 3];
  acc = (acc + (mask_22 * 2)) & 127;
  int tally_29 = (aux + st.buffer[1]) & 3;
  switch (tally_29)
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

  int window_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_26 > 48)
  {
    acc = ((acc + (window_26 * 2)) + 5) & 127;
    aux ^= window_26 & 15;
  }
  else
  {
    acc = ((acc - window_26) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000479_7913_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000479_7913_0 st_1 = {0};
  struct FilterState_R000479_7913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int sample_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_71_1) & 63;
  aux_2 = (aux_2 + sample_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_86_1 > 11)
  {
    acc_1 = ((acc_1 + (delta_86_1 * 2)) + 5) & 127;
    aux_1 ^= delta_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_86_2 > 11)
  {
    acc_2 = ((acc_2 + (delta_86_2 * 2)) + 5) & 127;
    aux_2 ^= delta_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_90_1 = local_arr_1[aux_1 % 3];
  int parity_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_71_1 == sample_71_2);
  assert(delta_86_1 == delta_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_90_1 == parity_90_2);
}

int fn_R000479_7913_15(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000479_7913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int sample_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_71) & 63;
  acc ^= aux;
  int delta_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_86 > 11)
  {
    acc = ((acc + (delta_86 * 2)) + 5) & 127;
    aux ^= delta_86 & 15;
  }
  else
  {
    acc = ((acc - delta_86) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_90 = local_arr[aux % 3];
  acc = (acc + (parity_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000479_7913_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000479_7913_0 st_1 = {0};
  struct FilterState_R000479_7913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int bound_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_44_1) & 63;
  aux_2 = (aux_2 + bound_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_23_1)
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

  switch (tally_23_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_44_1 == bound_44_2);
  assert(tally_23_1 == tally_23_2);
}

int fn_R000479_7913_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000479_7913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int bound_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_44) & 63;
  acc ^= aux;
  int tally_23 = (aux + st.buffer[1]) & 3;
  switch (tally_23)
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

void fn_R000479_7913_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000479_7913_1 st_1 = {0};
  struct AudioFrame_R000479_7913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_51_1 = local_arr_1[aux_1 % 3];
  int checksum_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_51_2 * 2)) & 127;
  int quotient_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_81_1) & 63;
  aux_2 = (aux_2 + quotient_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
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

  assert(checksum_51_1 == checksum_51_2);
  assert(quotient_81_1 == quotient_81_2);
}

int fn_R000479_7913_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000479_7913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int checksum_51 = local_arr[aux % 3];
  acc = (acc + (checksum_51 * 2)) & 127;
  int quotient_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_81) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000479_7913_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000479_7913_2 st_1 = {0};
  struct CipherContext_R000479_7913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int phase_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_44_1 > 13)
  {
    acc_1 = ((acc_1 + (phase_44_1 * 2)) + 5) & 127;
    aux_1 ^= phase_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_44_2 > 13)
  {
    acc_2 = ((acc_2 + (phase_44_2 * 2)) + 5) & 127;
    aux_2 ^= phase_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_97_1)
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

  switch (mask_97_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_44_1 == phase_44_2);
  assert(mask_97_1 == mask_97_2);
}

int fn_R000479_7913_18(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000479_7913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int phase_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_44 > 13)
  {
    acc = ((acc + (phase_44 * 2)) + 5) & 127;
    aux ^= phase_44 & 15;
  }
  else
  {
    acc = ((acc - phase_44) + 11) & 127;
    aux += 3;
  }
  int mask_97 = (aux + st.buffer[1]) & 3;
  switch (mask_97)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000479_0_1;
  int sec_r000479_0_2;
  int sec_r000479_1_1;
  int sec_r000479_1_2;
  int sec_r000479_2_1;
  int sec_r000479_2_2;
  int sec_r000479_3_1;
  int sec_r000479_3_2;
  int sec_r000479_4_1;
  int sec_r000479_4_2;
  int sec_r000479_5_1;
  int sec_r000479_5_2;
  int sec_r000479_6_1;
  int sec_r000479_6_2;
  int sec_r000479_7_1;
  int sec_r000479_7_2;
  int sec_r000479_8_1;
  int sec_r000479_8_2;
  int sec_r000479_9_1;
  int sec_r000479_9_2;
  int sec_r000479_10_1;
  int sec_r000479_10_2;
  int sec_r000479_11_1;
  int sec_r000479_11_2;
  int sec_r000479_12_1;
  int sec_r000479_12_2;
  int sec_r000479_13_1;
  int sec_r000479_13_2;
  int sec_r000479_14_1;
  int sec_r000479_14_2;
  int sec_r000479_15_1;
  int sec_r000479_15_2;
  int sec_r000479_16_1;
  int sec_r000479_16_2;
  int sec_r000479_17_1;
  int sec_r000479_17_2;
  int pub_r000479_0_1;
  int pub_r000479_0_2;
  int pub_r000479_1_1;
  int pub_r000479_1_2;
  int pub_r000479_2_1;
  int pub_r000479_2_2;
  int pub_r000479_3_1;
  int pub_r000479_3_2;
  int pub_r000479_4_1;
  int pub_r000479_4_2;
  int pub_r000479_5_1;
  int pub_r000479_5_2;
  int pub_r000479_6_1;
  int pub_r000479_6_2;
  int pub_r000479_7_1;
  int pub_r000479_7_2;
  int pub_r000479_8_1;
  int pub_r000479_8_2;
  int pub_r000479_9_1;
  int pub_r000479_9_2;
  int pub_r000479_10_1;
  int pub_r000479_10_2;
  int pub_r000479_11_1;
  int pub_r000479_11_2;
  int pub_r000479_12_1;
  int pub_r000479_12_2;
  int pub_r000479_13_1;
  int pub_r000479_13_2;
  int pub_r000479_14_1;
  int pub_r000479_14_2;
  int pub_r000479_15_1;
  int pub_r000479_15_2;
  int pub_r000479_16_1;
  int pub_r000479_16_2;
  int pub_r000479_17_1;
  int pub_r000479_17_2;
  int pub_r000479_18_1;
  int pub_r000479_18_2;
  int pub_r000479_19_1;
  int pub_r000479_19_2;
  int pub_r000479_20_1;
  int pub_r000479_20_2;
  int pub_r000479_21_1;
  int pub_r000479_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000479_0_1 >= (-100)) && (pub_r000479_0_1 <= 100));
  __CPROVER_assume((pub_r000479_0_2 >= (-100)) && (pub_r000479_0_2 <= 100));
  __CPROVER_assume((pub_r000479_1_1 >= (-100)) && (pub_r000479_1_1 <= 100));
  __CPROVER_assume((pub_r000479_1_2 >= (-100)) && (pub_r000479_1_2 <= 100));
  __CPROVER_assume((pub_r000479_2_1 >= (-100)) && (pub_r000479_2_1 <= 100));
  __CPROVER_assume((pub_r000479_2_2 >= (-100)) && (pub_r000479_2_2 <= 100));
  __CPROVER_assume((pub_r000479_3_1 >= (-100)) && (pub_r000479_3_1 <= 100));
  __CPROVER_assume((pub_r000479_3_2 >= (-100)) && (pub_r000479_3_2 <= 100));
  __CPROVER_assume((pub_r000479_4_1 >= (-100)) && (pub_r000479_4_1 <= 100));
  __CPROVER_assume((pub_r000479_4_2 >= (-100)) && (pub_r000479_4_2 <= 100));
  __CPROVER_assume((pub_r000479_5_1 >= (-100)) && (pub_r000479_5_1 <= 100));
  __CPROVER_assume((pub_r000479_5_2 >= (-100)) && (pub_r000479_5_2 <= 100));
  __CPROVER_assume((pub_r000479_6_1 >= (-100)) && (pub_r000479_6_1 <= 100));
  __CPROVER_assume((pub_r000479_6_2 >= (-100)) && (pub_r000479_6_2 <= 100));
  __CPROVER_assume((pub_r000479_7_1 >= (-100)) && (pub_r000479_7_1 <= 100));
  __CPROVER_assume((pub_r000479_7_2 >= (-100)) && (pub_r000479_7_2 <= 100));
  __CPROVER_assume((pub_r000479_8_1 >= (-100)) && (pub_r000479_8_1 <= 100));
  __CPROVER_assume((pub_r000479_8_2 >= (-100)) && (pub_r000479_8_2 <= 100));
  __CPROVER_assume((pub_r000479_9_1 >= (-100)) && (pub_r000479_9_1 <= 100));
  __CPROVER_assume((pub_r000479_9_2 >= (-100)) && (pub_r000479_9_2 <= 100));
  __CPROVER_assume((pub_r000479_10_1 >= (-100)) && (pub_r000479_10_1 <= 100));
  __CPROVER_assume((pub_r000479_10_2 >= (-100)) && (pub_r000479_10_2 <= 100));
  __CPROVER_assume((pub_r000479_11_1 >= (-100)) && (pub_r000479_11_1 <= 100));
  __CPROVER_assume((pub_r000479_11_2 >= (-100)) && (pub_r000479_11_2 <= 100));
  __CPROVER_assume((pub_r000479_12_1 >= (-100)) && (pub_r000479_12_1 <= 100));
  __CPROVER_assume((pub_r000479_12_2 >= (-100)) && (pub_r000479_12_2 <= 100));
  __CPROVER_assume((pub_r000479_13_1 >= (-100)) && (pub_r000479_13_1 <= 100));
  __CPROVER_assume((pub_r000479_13_2 >= (-100)) && (pub_r000479_13_2 <= 100));
  __CPROVER_assume((pub_r000479_14_1 >= (-100)) && (pub_r000479_14_1 <= 100));
  __CPROVER_assume((pub_r000479_14_2 >= (-100)) && (pub_r000479_14_2 <= 100));
  __CPROVER_assume((pub_r000479_15_1 >= (-100)) && (pub_r000479_15_1 <= 100));
  __CPROVER_assume((pub_r000479_15_2 >= (-100)) && (pub_r000479_15_2 <= 100));
  __CPROVER_assume((pub_r000479_16_1 >= (-100)) && (pub_r000479_16_1 <= 100));
  __CPROVER_assume((pub_r000479_16_2 >= (-100)) && (pub_r000479_16_2 <= 100));
  __CPROVER_assume((pub_r000479_17_1 >= (-100)) && (pub_r000479_17_1 <= 100));
  __CPROVER_assume((pub_r000479_17_2 >= (-100)) && (pub_r000479_17_2 <= 100));
  __CPROVER_assume((pub_r000479_18_1 >= (-100)) && (pub_r000479_18_1 <= 100));
  __CPROVER_assume((pub_r000479_18_2 >= (-100)) && (pub_r000479_18_2 <= 100));
  __CPROVER_assume((pub_r000479_19_1 >= (-100)) && (pub_r000479_19_1 <= 100));
  __CPROVER_assume((pub_r000479_19_2 >= (-100)) && (pub_r000479_19_2 <= 100));
  __CPROVER_assume((pub_r000479_20_1 >= (-100)) && (pub_r000479_20_1 <= 100));
  __CPROVER_assume((pub_r000479_20_2 >= (-100)) && (pub_r000479_20_2 <= 100));
  __CPROVER_assume((pub_r000479_21_1 >= (-100)) && (pub_r000479_21_1 <= 100));
  __CPROVER_assume((pub_r000479_21_2 >= (-100)) && (pub_r000479_21_2 <= 100));
  __CPROVER_assume((sec_r000479_0_1 >= 0) && (sec_r000479_0_1 <= 255));
  __CPROVER_assume((sec_r000479_0_2 >= 0) && (sec_r000479_0_2 <= 255));
  __CPROVER_assume((sec_r000479_1_1 >= 0) && (sec_r000479_1_1 <= 255));
  __CPROVER_assume((sec_r000479_1_2 >= 0) && (sec_r000479_1_2 <= 255));
  __CPROVER_assume((sec_r000479_2_1 >= 0) && (sec_r000479_2_1 <= 255));
  __CPROVER_assume((sec_r000479_2_2 >= 0) && (sec_r000479_2_2 <= 255));
  __CPROVER_assume((sec_r000479_3_1 >= 0) && (sec_r000479_3_1 <= 255));
  __CPROVER_assume((sec_r000479_3_2 >= 0) && (sec_r000479_3_2 <= 255));
  __CPROVER_assume((sec_r000479_4_1 >= 0) && (sec_r000479_4_1 <= 255));
  __CPROVER_assume((sec_r000479_4_2 >= 0) && (sec_r000479_4_2 <= 255));
  __CPROVER_assume((sec_r000479_5_1 >= 0) && (sec_r000479_5_1 <= 255));
  __CPROVER_assume((sec_r000479_5_2 >= 0) && (sec_r000479_5_2 <= 255));
  __CPROVER_assume((sec_r000479_6_1 >= 0) && (sec_r000479_6_1 <= 255));
  __CPROVER_assume((sec_r000479_6_2 >= 0) && (sec_r000479_6_2 <= 255));
  __CPROVER_assume((sec_r000479_7_1 >= 0) && (sec_r000479_7_1 <= 255));
  __CPROVER_assume((sec_r000479_7_2 >= 0) && (sec_r000479_7_2 <= 255));
  __CPROVER_assume((sec_r000479_8_1 >= 0) && (sec_r000479_8_1 <= 255));
  __CPROVER_assume((sec_r000479_8_2 >= 0) && (sec_r000479_8_2 <= 255));
  __CPROVER_assume((sec_r000479_9_1 >= 0) && (sec_r000479_9_1 <= 255));
  __CPROVER_assume((sec_r000479_9_2 >= 0) && (sec_r000479_9_2 <= 255));
  __CPROVER_assume((sec_r000479_10_1 >= 0) && (sec_r000479_10_1 <= 255));
  __CPROVER_assume((sec_r000479_10_2 >= 0) && (sec_r000479_10_2 <= 255));
  __CPROVER_assume((sec_r000479_11_1 >= 0) && (sec_r000479_11_1 <= 255));
  __CPROVER_assume((sec_r000479_11_2 >= 0) && (sec_r000479_11_2 <= 255));
  __CPROVER_assume((sec_r000479_12_1 >= 0) && (sec_r000479_12_1 <= 255));
  __CPROVER_assume((sec_r000479_12_2 >= 0) && (sec_r000479_12_2 <= 255));
  __CPROVER_assume((sec_r000479_13_1 >= 0) && (sec_r000479_13_1 <= 255));
  __CPROVER_assume((sec_r000479_13_2 >= 0) && (sec_r000479_13_2 <= 255));
  __CPROVER_assume((sec_r000479_14_1 >= 0) && (sec_r000479_14_1 <= 255));
  __CPROVER_assume((sec_r000479_14_2 >= 0) && (sec_r000479_14_2 <= 255));
  __CPROVER_assume((sec_r000479_15_1 >= 0) && (sec_r000479_15_1 <= 255));
  __CPROVER_assume((sec_r000479_15_2 >= 0) && (sec_r000479_15_2 <= 255));
  __CPROVER_assume((sec_r000479_16_1 >= 0) && (sec_r000479_16_1 <= 255));
  __CPROVER_assume((sec_r000479_16_2 >= 0) && (sec_r000479_16_2 <= 255));
  __CPROVER_assume((sec_r000479_17_1 >= 0) && (sec_r000479_17_1 <= 255));
  __CPROVER_assume((sec_r000479_17_2 >= 0) && (sec_r000479_17_2 <= 255));
  struct FilterState_R000479_7913_0 st_var_0_1 = {0};
  struct FilterState_R000479_7913_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000479_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000479_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000479_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000479_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000479_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000479_0_2 + 7) & 15;
  struct AudioFrame_R000479_7913_1 st_var_1_1 = {0};
  struct AudioFrame_R000479_7913_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000479_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000479_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000479_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000479_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000479_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000479_0_2 + 9) & 15;
  struct CipherContext_R000479_7913_2 st_var_2_1 = {0};
  struct CipherContext_R000479_7913_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000479_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000479_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000479_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000479_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000479_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000479_0_2 + 11) & 15;
  union ColorPixel_R000479_7913_0 u_var_1;
  union ColorPixel_R000479_7913_0 u_var_2;
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
  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = table_1[2];
  int stage_v_2_2 = table_2[2];
  table_1[2] = (table_1[3] + 5) & 63;
  table_2[2] = (table_2[3] + 5) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (st_var_0_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_0_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 3) & 255;
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

  switch (stage_v_3_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 3) & 255;
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 5) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (11 & 31);
  int stage_v_6_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (11 & 31);
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= (stage_v_6_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_6_2 << 1) & 127;
  int stage_v_7_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (12 & 31);
  int stage_v_7_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (12 & 31);
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= (stage_v_7_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_7_2 << 1) & 127;
  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = table_1[1];
  int stage_v_9_2 = table_2[1];
  table_1[1] = (table_1[2] + 19) & 63;
  table_2[1] = (table_2[2] + 19) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 12) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= stage_v_11_1;
  chk_sum_2 ^= stage_v_11_2;
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 14) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 14) & 15;
  int stage_v_13_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_13_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= stage_v_13_1;
  chk_sum_2 ^= stage_v_13_2;
  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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
  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
  int stage_v_17_1 = ((st_var_2_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_2_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 50)
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
  if (stage_v_17_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 50)
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
  int stage_v_18_1 = ((st_var_0_1.buffer[0] * 2) + 61) & 63;
  int stage_v_18_2 = ((st_var_0_2.buffer[0] * 2) + 61) & 63;
  if (stage_v_18_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_18_1) - 5) & 255;
    if (stage_v_18_1 > 35)
    {
      chk_sum_1 ^= stage_v_18_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_18_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_18_2) - 5) & 255;
    if (stage_v_18_2 > 35)
    {
      chk_sum_2 ^= stage_v_18_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (29 & 31);
  int stage_v_24_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (29 & 31);
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= (stage_v_24_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_24_2 << 1) & 127;
  int stage_v_25_1 = table_1[1];
  int stage_v_25_2 = table_2[1];
  table_1[1] = (table_1[2] + 51) & 63;
  table_2[1] = (table_2[2] + 51) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (st_var_0_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_0_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
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

  switch (stage_v_27_2)
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

  int stage_v_28_1 = ((st_var_1_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_1_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 38)
    {
      chk_sum_1 ^= stage_v_28_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_28_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 38)
    {
      chk_sum_2 ^= stage_v_28_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_29_1 = table_1[1];
  int stage_v_29_2 = table_2[1];
  table_1[1] = (table_1[2] + 59) & 63;
  table_2[1] = (table_2[2] + 59) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (st_var_0_1.buffer[0] ^ 33) & 3;
  int stage_v_30_2 = (st_var_0_2.buffer[0] ^ 33) & 3;
  switch (stage_v_30_1)
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

  switch (stage_v_30_2)
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

  int stage_v_31_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (36 & 31);
  int stage_v_31_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (36 & 31);
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= (stage_v_31_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_31_2 << 1) & 127;
  int stage_v_32_1 = ((st_var_2_1.buffer[2] * 2) + 103) & 63;
  int stage_v_32_2 = ((st_var_2_2.buffer[2] * 2) + 103) & 63;
  if (stage_v_32_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_32_1) - 5) & 255;
    if (stage_v_32_1 > 40)
    {
      chk_sum_1 ^= stage_v_32_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_32_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_32_2) - 5) & 255;
    if (stage_v_32_2 > 40)
    {
      chk_sum_2 ^= stage_v_32_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 34) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  int stage_v_34_1 = (st_var_1_1.buffer[0] ^ 37) & 3;
  int stage_v_34_2 = (st_var_1_2.buffer[0] ^ 37) & 3;
  switch (stage_v_34_1)
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

  switch (stage_v_34_2)
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

  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (st_var_0_1.buffer[0] ^ 39) & 3;
  int stage_v_36_2 = (st_var_0_2.buffer[0] ^ 39) & 3;
  switch (stage_v_36_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 3) & 255;
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

  switch (stage_v_36_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 3) & 255;
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

  int stage_v_37_1 = (st_var_1_1.buffer[0] ^ 40) & 3;
  int stage_v_37_2 = (st_var_1_2.buffer[0] ^ 40) & 3;
  switch (stage_v_37_1)
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

  switch (stage_v_37_2)
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

  int stage_v_38_1 = (st_var_2_1.buffer[0] ^ 41) & 3;
  int stage_v_38_2 = (st_var_2_2.buffer[0] ^ 41) & 3;
  switch (stage_v_38_1)
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

  switch (stage_v_38_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 40) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  int stage_v_40_1 = (st_var_1_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_1_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  int stage_v_44_1 = (st_var_2_1.buffer[0] ^ 47) & 3;
  int stage_v_44_2 = (st_var_2_2.buffer[0] ^ 47) & 3;
  switch (stage_v_44_1)
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

  switch (stage_v_44_2)
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

  int stage_v_45_1 = (st_var_0_1.buffer[0] ^ 48) & 3;
  int stage_v_45_2 = (st_var_0_2.buffer[0] ^ 48) & 3;
  switch (stage_v_45_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 3) & 255;
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

  switch (stage_v_45_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 3) & 255;
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

  int s_idx_46_1 = sec_r000479_12_1 & 3;
  int s_idx_46_2 = sec_r000479_12_2 & 3;
  int stage_v_46_1 = (table_1[s_idx_46_1] + pub_r000479_21_1) & 127;
  int stage_v_46_2 = (table_2[s_idx_46_2] + pub_r000479_21_2) & 127;
  table_1[s_idx_46_1] = (stage_v_46_1 + 7) & 63;
  table_2[s_idx_46_2] = (stage_v_46_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int s_idx_47_1 = sec_r000479_5_1 & 3;
  int s_idx_47_2 = sec_r000479_5_2 & 3;
  int stage_v_47_1 = (table_1[s_idx_47_1] + pub_r000479_20_1) & 127;
  int stage_v_47_2 = (table_2[s_idx_47_2] + pub_r000479_20_2) & 127;
  table_1[s_idx_47_1] = (stage_v_47_1 + 7) & 63;
  table_2[s_idx_47_2] = (stage_v_47_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int s_idx_48_1 = stage_v_47_1 & 3;
  int s_idx_48_2 = stage_v_47_2 & 3;
  int stage_v_48_1 = (table_1[s_idx_48_1] + pub_r000479_19_1) & 127;
  int stage_v_48_2 = (table_2[s_idx_48_2] + pub_r000479_19_2) & 127;
  table_1[s_idx_48_1] = (stage_v_48_1 + 7) & 63;
  table_2[s_idx_48_2] = (stage_v_48_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int s_idx_49_1 = sec_r000479_2_1 & 3;
  int s_idx_49_2 = sec_r000479_2_2 & 3;
  int stage_v_49_1 = (table_1[s_idx_49_1] + pub_r000479_14_1) & 127;
  int stage_v_49_2 = (table_2[s_idx_49_2] + pub_r000479_14_2) & 127;
  table_1[s_idx_49_1] = (stage_v_49_1 + 7) & 63;
  table_2[s_idx_49_2] = (stage_v_49_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int s_idx_50_1 = sec_r000479_4_1 & 3;
  int s_idx_50_2 = sec_r000479_4_2 & 3;
  int stage_v_50_1 = (table_1[s_idx_50_1] + pub_r000479_15_1) & 127;
  int stage_v_50_2 = (table_2[s_idx_50_2] + pub_r000479_15_2) & 127;
  table_1[s_idx_50_1] = (stage_v_50_1 + 7) & 63;
  table_2[s_idx_50_2] = (stage_v_50_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int s_idx_51_1 = stage_v_47_1 & 3;
  int s_idx_51_2 = stage_v_47_2 & 3;
  int stage_v_51_1 = (table_1[s_idx_51_1] + pub_r000479_19_1) & 127;
  int stage_v_51_2 = (table_2[s_idx_51_2] + pub_r000479_19_2) & 127;
  table_1[s_idx_51_1] = (stage_v_51_1 + 7) & 63;
  table_2[s_idx_51_2] = (stage_v_51_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int s_idx_52_1 = stage_v_49_1 & 3;
  int s_idx_52_2 = stage_v_49_2 & 3;
  int stage_v_52_1 = (table_1[s_idx_52_1] + pub_r000479_19_1) & 127;
  int stage_v_52_2 = (table_2[s_idx_52_2] + pub_r000479_19_2) & 127;
  table_1[s_idx_52_1] = (stage_v_52_1 + 7) & 63;
  table_2[s_idx_52_2] = (stage_v_52_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int s_idx_53_1 = stage_v_47_1 & 3;
  int s_idx_53_2 = stage_v_47_2 & 3;
  int stage_v_53_1 = (table_1[s_idx_53_1] + pub_r000479_7_1) & 127;
  int stage_v_53_2 = (table_2[s_idx_53_2] + pub_r000479_7_2) & 127;
  table_1[s_idx_53_1] = (stage_v_53_1 + 7) & 63;
  table_2[s_idx_53_2] = (stage_v_53_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int s_idx_54_1 = stage_v_47_1 & 3;
  int s_idx_54_2 = stage_v_47_2 & 3;
  int stage_v_54_1 = (table_1[s_idx_54_1] + pub_r000479_16_1) & 127;
  int stage_v_54_2 = (table_2[s_idx_54_2] + pub_r000479_16_2) & 127;
  table_1[s_idx_54_1] = (stage_v_54_1 + 7) & 63;
  table_2[s_idx_54_2] = (stage_v_54_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int s_idx_55_1 = stage_v_47_1 & 3;
  int s_idx_55_2 = stage_v_47_2 & 3;
  int stage_v_55_1 = (table_1[s_idx_55_1] + pub_r000479_21_1) & 127;
  int stage_v_55_2 = (table_2[s_idx_55_2] + pub_r000479_21_2) & 127;
  table_1[s_idx_55_1] = (stage_v_55_1 + 7) & 63;
  table_2[s_idx_55_2] = (stage_v_55_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int s_idx_56_1 = stage_v_52_1 & 3;
  int s_idx_56_2 = stage_v_52_2 & 3;
  int stage_v_56_1 = (table_1[s_idx_56_1] + pub_r000479_19_1) & 127;
  int stage_v_56_2 = (table_2[s_idx_56_2] + pub_r000479_19_2) & 127;
  table_1[s_idx_56_1] = (stage_v_56_1 + 7) & 63;
  table_2[s_idx_56_2] = (stage_v_56_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int s_idx_57_1 = stage_v_50_1 & 3;
  int s_idx_57_2 = stage_v_50_2 & 3;
  int stage_v_57_1 = (table_1[s_idx_57_1] + pub_r000479_4_1) & 127;
  int stage_v_57_2 = (table_2[s_idx_57_2] + pub_r000479_4_2) & 127;
  table_1[s_idx_57_1] = (stage_v_57_1 + 7) & 63;
  table_2[s_idx_57_2] = (stage_v_57_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int s_idx_58_1 = stage_v_53_1 & 3;
  int s_idx_58_2 = stage_v_53_2 & 3;
  int stage_v_58_1 = (table_1[s_idx_58_1] + pub_r000479_2_1) & 127;
  int stage_v_58_2 = (table_2[s_idx_58_2] + pub_r000479_2_2) & 127;
  table_1[s_idx_58_1] = (stage_v_58_1 + 7) & 63;
  table_2[s_idx_58_2] = (stage_v_58_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int s_idx_59_1 = sec_r000479_2_1 & 3;
  int s_idx_59_2 = sec_r000479_2_2 & 3;
  int stage_v_59_1 = (table_1[s_idx_59_1] + pub_r000479_15_1) & 127;
  int stage_v_59_2 = (table_2[s_idx_59_2] + pub_r000479_15_2) & 127;
  table_1[s_idx_59_1] = (stage_v_59_1 + 7) & 63;
  table_2[s_idx_59_2] = (stage_v_59_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int s_idx_60_1 = sec_r000479_14_1 & 3;
  int s_idx_60_2 = sec_r000479_14_2 & 3;
  int stage_v_60_1 = (table_1[s_idx_60_1] + pub_r000479_9_1) & 127;
  int stage_v_60_2 = (table_2[s_idx_60_2] + pub_r000479_9_2) & 127;
  table_1[s_idx_60_1] = (stage_v_60_1 + 7) & 63;
  table_2[s_idx_60_2] = (stage_v_60_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int s_idx_61_1 = sec_r000479_16_1 & 3;
  int s_idx_61_2 = sec_r000479_16_2 & 3;
  int stage_v_61_1 = (table_1[s_idx_61_1] + pub_r000479_16_1) & 127;
  int stage_v_61_2 = (table_2[s_idx_61_2] + pub_r000479_16_2) & 127;
  table_1[s_idx_61_1] = (stage_v_61_1 + 7) & 63;
  table_2[s_idx_61_2] = (stage_v_61_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int s_idx_62_1 = stage_v_58_1 & 3;
  int s_idx_62_2 = stage_v_58_2 & 3;
  int stage_v_62_1 = (table_1[s_idx_62_1] + pub_r000479_6_1) & 127;
  int stage_v_62_2 = (table_2[s_idx_62_2] + pub_r000479_6_2) & 127;
  table_1[s_idx_62_1] = (stage_v_62_1 + 7) & 63;
  table_2[s_idx_62_2] = (stage_v_62_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int s_idx_63_1 = sec_r000479_4_1 & 3;
  int s_idx_63_2 = sec_r000479_4_2 & 3;
  int stage_v_63_1 = (table_1[s_idx_63_1] + pub_r000479_14_1) & 127;
  int stage_v_63_2 = (table_2[s_idx_63_2] + pub_r000479_14_2) & 127;
  table_1[s_idx_63_1] = (stage_v_63_1 + 7) & 63;
  table_2[s_idx_63_2] = (stage_v_63_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int s_idx_64_1 = sec_r000479_1_1 & 3;
  int s_idx_64_2 = sec_r000479_1_2 & 3;
  int stage_v_64_1 = (table_1[s_idx_64_1] + pub_r000479_6_1) & 127;
  int stage_v_64_2 = (table_2[s_idx_64_2] + pub_r000479_6_2) & 127;
  table_1[s_idx_64_1] = (stage_v_64_1 + 7) & 63;
  table_2[s_idx_64_2] = (stage_v_64_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int s_idx_65_1 = stage_v_50_1 & 3;
  int s_idx_65_2 = stage_v_50_2 & 3;
  int stage_v_65_1 = (table_1[s_idx_65_1] + pub_r000479_16_1) & 127;
  int stage_v_65_2 = (table_2[s_idx_65_2] + pub_r000479_16_2) & 127;
  table_1[s_idx_65_1] = (stage_v_65_1 + 7) & 63;
  table_2[s_idx_65_2] = (stage_v_65_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int s_idx_66_1 = stage_v_50_1 & 3;
  int s_idx_66_2 = stage_v_50_2 & 3;
  int stage_v_66_1 = (table_1[s_idx_66_1] + pub_r000479_16_1) & 127;
  int stage_v_66_2 = (table_2[s_idx_66_2] + pub_r000479_16_2) & 127;
  table_1[s_idx_66_1] = (stage_v_66_1 + 7) & 63;
  table_2[s_idx_66_2] = (stage_v_66_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int s_idx_67_1 = stage_v_60_1 & 3;
  int s_idx_67_2 = stage_v_60_2 & 3;
  int stage_v_67_1 = (table_1[s_idx_67_1] + pub_r000479_14_1) & 127;
  int stage_v_67_2 = (table_2[s_idx_67_2] + pub_r000479_14_2) & 127;
  table_1[s_idx_67_1] = (stage_v_67_1 + 7) & 63;
  table_2[s_idx_67_2] = (stage_v_67_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int s_idx_68_1 = stage_v_50_1 & 3;
  int s_idx_68_2 = stage_v_50_2 & 3;
  int stage_v_68_1 = (table_1[s_idx_68_1] + pub_r000479_5_1) & 127;
  int stage_v_68_2 = (table_2[s_idx_68_2] + pub_r000479_5_2) & 127;
  table_1[s_idx_68_1] = (stage_v_68_1 + 7) & 63;
  table_2[s_idx_68_2] = (stage_v_68_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int s_idx_69_1 = sec_r000479_13_1 & 3;
  int s_idx_69_2 = sec_r000479_13_2 & 3;
  int stage_v_69_1 = (table_1[s_idx_69_1] + pub_r000479_9_1) & 127;
  int stage_v_69_2 = (table_2[s_idx_69_2] + pub_r000479_9_2) & 127;
  table_1[s_idx_69_1] = (stage_v_69_1 + 7) & 63;
  table_2[s_idx_69_2] = (stage_v_69_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int s_idx_70_1 = sec_r000479_11_1 & 3;
  int s_idx_70_2 = sec_r000479_11_2 & 3;
  int stage_v_70_1 = (table_1[s_idx_70_1] + pub_r000479_15_1) & 127;
  int stage_v_70_2 = (table_2[s_idx_70_2] + pub_r000479_15_2) & 127;
  table_1[s_idx_70_1] = (stage_v_70_1 + 7) & 63;
  table_2[s_idx_70_2] = (stage_v_70_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int s_idx_71_1 = stage_v_65_1 & 3;
  int s_idx_71_2 = stage_v_65_2 & 3;
  int stage_v_71_1 = (table_1[s_idx_71_1] + pub_r000479_20_1) & 127;
  int stage_v_71_2 = (table_2[s_idx_71_2] + pub_r000479_20_2) & 127;
  table_1[s_idx_71_1] = (stage_v_71_1 + 7) & 63;
  table_2[s_idx_71_2] = (stage_v_71_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int s_idx_72_1 = stage_v_53_1 & 3;
  int s_idx_72_2 = stage_v_53_2 & 3;
  int stage_v_72_1 = (table_1[s_idx_72_1] + pub_r000479_2_1) & 127;
  int stage_v_72_2 = (table_2[s_idx_72_2] + pub_r000479_2_2) & 127;
  table_1[s_idx_72_1] = (stage_v_72_1 + 7) & 63;
  table_2[s_idx_72_2] = (stage_v_72_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int s_idx_73_1 = sec_r000479_3_1 & 3;
  int s_idx_73_2 = sec_r000479_3_2 & 3;
  int stage_v_73_1 = (table_1[s_idx_73_1] + pub_r000479_8_1) & 127;
  int stage_v_73_2 = (table_2[s_idx_73_2] + pub_r000479_8_2) & 127;
  table_1[s_idx_73_1] = (stage_v_73_1 + 7) & 63;
  table_2[s_idx_73_2] = (stage_v_73_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int s_idx_74_1 = stage_v_66_1 & 3;
  int s_idx_74_2 = stage_v_66_2 & 3;
  int stage_v_74_1 = (table_1[s_idx_74_1] + pub_r000479_14_1) & 127;
  int stage_v_74_2 = (table_2[s_idx_74_2] + pub_r000479_14_2) & 127;
  table_1[s_idx_74_1] = (stage_v_74_1 + 7) & 63;
  table_2[s_idx_74_2] = (stage_v_74_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int s_idx_75_1 = sec_r000479_16_1 & 3;
  int s_idx_75_2 = sec_r000479_16_2 & 3;
  int stage_v_75_1 = (table_1[s_idx_75_1] + pub_r000479_9_1) & 127;
  int stage_v_75_2 = (table_2[s_idx_75_2] + pub_r000479_9_2) & 127;
  table_1[s_idx_75_1] = (stage_v_75_1 + 7) & 63;
  table_2[s_idx_75_2] = (stage_v_75_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int s_idx_76_1 = stage_v_63_1 & 3;
  int s_idx_76_2 = stage_v_63_2 & 3;
  int stage_v_76_1 = (table_1[s_idx_76_1] + pub_r000479_13_1) & 127;
  int stage_v_76_2 = (table_2[s_idx_76_2] + pub_r000479_13_2) & 127;
  table_1[s_idx_76_1] = (stage_v_76_1 + 7) & 63;
  table_2[s_idx_76_2] = (stage_v_76_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int s_idx_77_1 = stage_v_63_1 & 3;
  int s_idx_77_2 = stage_v_63_2 & 3;
  int stage_v_77_1 = (table_1[s_idx_77_1] + pub_r000479_4_1) & 127;
  int stage_v_77_2 = (table_2[s_idx_77_2] + pub_r000479_4_2) & 127;
  table_1[s_idx_77_1] = (stage_v_77_1 + 7) & 63;
  table_2[s_idx_77_2] = (stage_v_77_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int s_idx_78_1 = sec_r000479_6_1 & 3;
  int s_idx_78_2 = sec_r000479_6_2 & 3;
  int stage_v_78_1 = (table_1[s_idx_78_1] + pub_r000479_20_1) & 127;
  int stage_v_78_2 = (table_2[s_idx_78_2] + pub_r000479_20_2) & 127;
  table_1[s_idx_78_1] = (stage_v_78_1 + 7) & 63;
  table_2[s_idx_78_2] = (stage_v_78_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int s_idx_79_1 = stage_v_75_1 & 3;
  int s_idx_79_2 = stage_v_75_2 & 3;
  int stage_v_79_1 = (table_1[s_idx_79_1] + pub_r000479_10_1) & 127;
  int stage_v_79_2 = (table_2[s_idx_79_2] + pub_r000479_10_2) & 127;
  table_1[s_idx_79_1] = (stage_v_79_1 + 7) & 63;
  table_2[s_idx_79_2] = (stage_v_79_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int s_idx_80_1 = stage_v_61_1 & 3;
  int s_idx_80_2 = stage_v_61_2 & 3;
  int stage_v_80_1 = (table_1[s_idx_80_1] + pub_r000479_9_1) & 127;
  int stage_v_80_2 = (table_2[s_idx_80_2] + pub_r000479_9_2) & 127;
  table_1[s_idx_80_1] = (stage_v_80_1 + 7) & 63;
  table_2[s_idx_80_2] = (stage_v_80_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int s_idx_81_1 = stage_v_59_1 & 3;
  int s_idx_81_2 = stage_v_59_2 & 3;
  int stage_v_81_1 = (table_1[s_idx_81_1] + pub_r000479_8_1) & 127;
  int stage_v_81_2 = (table_2[s_idx_81_2] + pub_r000479_8_2) & 127;
  table_1[s_idx_81_1] = (stage_v_81_1 + 7) & 63;
  table_2[s_idx_81_2] = (stage_v_81_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int s_idx_82_1 = sec_r000479_0_1 & 3;
  int s_idx_82_2 = sec_r000479_0_2 & 3;
  int stage_v_82_1 = (table_1[s_idx_82_1] + pub_r000479_4_1) & 127;
  int stage_v_82_2 = (table_2[s_idx_82_2] + pub_r000479_4_2) & 127;
  table_1[s_idx_82_1] = (stage_v_82_1 + 7) & 63;
  table_2[s_idx_82_2] = (stage_v_82_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int s_idx_83_1 = sec_r000479_5_1 & 3;
  int s_idx_83_2 = sec_r000479_5_2 & 3;
  int stage_v_83_1 = (table_1[s_idx_83_1] + pub_r000479_8_1) & 127;
  int stage_v_83_2 = (table_2[s_idx_83_2] + pub_r000479_8_2) & 127;
  table_1[s_idx_83_1] = (stage_v_83_1 + 7) & 63;
  table_2[s_idx_83_2] = (stage_v_83_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int s_idx_84_1 = sec_r000479_8_1 & 3;
  int s_idx_84_2 = sec_r000479_8_2 & 3;
  int stage_v_84_1 = (table_1[s_idx_84_1] + pub_r000479_10_1) & 127;
  int stage_v_84_2 = (table_2[s_idx_84_2] + pub_r000479_10_2) & 127;
  table_1[s_idx_84_1] = (stage_v_84_1 + 7) & 63;
  table_2[s_idx_84_2] = (stage_v_84_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int s_idx_85_1 = sec_r000479_8_1 & 3;
  int s_idx_85_2 = sec_r000479_8_2 & 3;
  int stage_v_85_1 = (table_1[s_idx_85_1] + pub_r000479_10_1) & 127;
  int stage_v_85_2 = (table_2[s_idx_85_2] + pub_r000479_10_2) & 127;
  table_1[s_idx_85_1] = (stage_v_85_1 + 7) & 63;
  table_2[s_idx_85_2] = (stage_v_85_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int s_idx_86_1 = stage_v_46_1 & 3;
  int s_idx_86_2 = stage_v_46_2 & 3;
  int stage_v_86_1 = (table_1[s_idx_86_1] + pub_r000479_10_1) & 127;
  int stage_v_86_2 = (table_2[s_idx_86_2] + pub_r000479_10_2) & 127;
  table_1[s_idx_86_1] = (stage_v_86_1 + 7) & 63;
  table_2[s_idx_86_2] = (stage_v_86_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int s_idx_87_1 = stage_v_56_1 & 3;
  int s_idx_87_2 = stage_v_56_2 & 3;
  int stage_v_87_1 = (table_1[s_idx_87_1] + pub_r000479_15_1) & 127;
  int stage_v_87_2 = (table_2[s_idx_87_2] + pub_r000479_15_2) & 127;
  table_1[s_idx_87_1] = (stage_v_87_1 + 7) & 63;
  table_2[s_idx_87_2] = (stage_v_87_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int s_idx_88_1 = stage_v_75_1 & 3;
  int s_idx_88_2 = stage_v_75_2 & 3;
  int stage_v_88_1 = (table_1[s_idx_88_1] + pub_r000479_0_1) & 127;
  int stage_v_88_2 = (table_2[s_idx_88_2] + pub_r000479_0_2) & 127;
  table_1[s_idx_88_1] = (stage_v_88_1 + 7) & 63;
  table_2[s_idx_88_2] = (stage_v_88_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int s_idx_89_1 = stage_v_53_1 & 3;
  int s_idx_89_2 = stage_v_53_2 & 3;
  int stage_v_89_1 = (table_1[s_idx_89_1] + pub_r000479_21_1) & 127;
  int stage_v_89_2 = (table_2[s_idx_89_2] + pub_r000479_21_2) & 127;
  table_1[s_idx_89_1] = (stage_v_89_1 + 7) & 63;
  table_2[s_idx_89_2] = (stage_v_89_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int s_idx_90_1 = sec_r000479_15_1 & 3;
  int s_idx_90_2 = sec_r000479_15_2 & 3;
  int stage_v_90_1 = (table_1[s_idx_90_1] + pub_r000479_0_1) & 127;
  int stage_v_90_2 = (table_2[s_idx_90_2] + pub_r000479_0_2) & 127;
  table_1[s_idx_90_1] = (stage_v_90_1 + 7) & 63;
  table_2[s_idx_90_2] = (stage_v_90_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int s_idx_91_1 = sec_r000479_4_1 & 3;
  int s_idx_91_2 = sec_r000479_4_2 & 3;
  int stage_v_91_1 = (table_1[s_idx_91_1] + pub_r000479_4_1) & 127;
  int stage_v_91_2 = (table_2[s_idx_91_2] + pub_r000479_4_2) & 127;
  table_1[s_idx_91_1] = (stage_v_91_1 + 7) & 63;
  table_2[s_idx_91_2] = (stage_v_91_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int s_idx_92_1 = stage_v_88_1 & 3;
  int s_idx_92_2 = stage_v_88_2 & 3;
  int stage_v_92_1 = (table_1[s_idx_92_1] + pub_r000479_11_1) & 127;
  int stage_v_92_2 = (table_2[s_idx_92_2] + pub_r000479_11_2) & 127;
  table_1[s_idx_92_1] = (stage_v_92_1 + 7) & 63;
  table_2[s_idx_92_2] = (stage_v_92_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int s_idx_93_1 = stage_v_72_1 & 3;
  int s_idx_93_2 = stage_v_72_2 & 3;
  int stage_v_93_1 = (table_1[s_idx_93_1] + pub_r000479_0_1) & 127;
  int stage_v_93_2 = (table_2[s_idx_93_2] + pub_r000479_0_2) & 127;
  table_1[s_idx_93_1] = (stage_v_93_1 + 7) & 63;
  table_2[s_idx_93_2] = (stage_v_93_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int s_idx_94_1 = stage_v_56_1 & 3;
  int s_idx_94_2 = stage_v_56_2 & 3;
  int stage_v_94_1 = (table_1[s_idx_94_1] + pub_r000479_11_1) & 127;
  int stage_v_94_2 = (table_2[s_idx_94_2] + pub_r000479_11_2) & 127;
  table_1[s_idx_94_1] = (stage_v_94_1 + 7) & 63;
  table_2[s_idx_94_2] = (stage_v_94_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int s_idx_95_1 = stage_v_70_1 & 3;
  int s_idx_95_2 = stage_v_70_2 & 3;
  int stage_v_95_1 = (table_1[s_idx_95_1] + pub_r000479_17_1) & 127;
  int stage_v_95_2 = (table_2[s_idx_95_2] + pub_r000479_17_2) & 127;
  table_1[s_idx_95_1] = (stage_v_95_1 + 7) & 63;
  table_2[s_idx_95_2] = (stage_v_95_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int s_idx_96_1 = stage_v_77_1 & 3;
  int s_idx_96_2 = stage_v_77_2 & 3;
  int stage_v_96_1 = (table_1[s_idx_96_1] + pub_r000479_19_1) & 127;
  int stage_v_96_2 = (table_2[s_idx_96_2] + pub_r000479_19_2) & 127;
  table_1[s_idx_96_1] = (stage_v_96_1 + 7) & 63;
  table_2[s_idx_96_2] = (stage_v_96_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int s_idx_97_1 = stage_v_94_1 & 3;
  int s_idx_97_2 = stage_v_94_2 & 3;
  int stage_v_97_1 = (table_1[s_idx_97_1] + pub_r000479_3_1) & 127;
  int stage_v_97_2 = (table_2[s_idx_97_2] + pub_r000479_3_2) & 127;
  table_1[s_idx_97_1] = (stage_v_97_1 + 7) & 63;
  table_2[s_idx_97_2] = (stage_v_97_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int s_idx_98_1 = stage_v_54_1 & 3;
  int s_idx_98_2 = stage_v_54_2 & 3;
  int stage_v_98_1 = (table_1[s_idx_98_1] + pub_r000479_9_1) & 127;
  int stage_v_98_2 = (table_2[s_idx_98_2] + pub_r000479_9_2) & 127;
  table_1[s_idx_98_1] = (stage_v_98_1 + 7) & 63;
  table_2[s_idx_98_2] = (stage_v_98_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int s_idx_99_1 = stage_v_80_1 & 3;
  int s_idx_99_2 = stage_v_80_2 & 3;
  int stage_v_99_1 = (table_1[s_idx_99_1] + pub_r000479_21_1) & 127;
  int stage_v_99_2 = (table_2[s_idx_99_2] + pub_r000479_21_2) & 127;
  table_1[s_idx_99_1] = (stage_v_99_1 + 7) & 63;
  table_2[s_idx_99_2] = (stage_v_99_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int s_idx_100_1 = stage_v_46_1 & 3;
  int s_idx_100_2 = stage_v_46_2 & 3;
  int stage_v_100_1 = (table_1[s_idx_100_1] + pub_r000479_4_1) & 127;
  int stage_v_100_2 = (table_2[s_idx_100_2] + pub_r000479_4_2) & 127;
  table_1[s_idx_100_1] = (stage_v_100_1 + 7) & 63;
  table_2[s_idx_100_2] = (stage_v_100_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int s_idx_101_1 = stage_v_58_1 & 3;
  int s_idx_101_2 = stage_v_58_2 & 3;
  int stage_v_101_1 = (table_1[s_idx_101_1] + pub_r000479_20_1) & 127;
  int stage_v_101_2 = (table_2[s_idx_101_2] + pub_r000479_20_2) & 127;
  table_1[s_idx_101_1] = (stage_v_101_1 + 7) & 63;
  table_2[s_idx_101_2] = (stage_v_101_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int s_idx_102_1 = stage_v_82_1 & 3;
  int s_idx_102_2 = stage_v_82_2 & 3;
  int stage_v_102_1 = (table_1[s_idx_102_1] + pub_r000479_20_1) & 127;
  int stage_v_102_2 = (table_2[s_idx_102_2] + pub_r000479_20_2) & 127;
  table_1[s_idx_102_1] = (stage_v_102_1 + 7) & 63;
  table_2[s_idx_102_2] = (stage_v_102_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int s_idx_103_1 = sec_r000479_7_1 & 3;
  int s_idx_103_2 = sec_r000479_7_2 & 3;
  int stage_v_103_1 = (table_1[s_idx_103_1] + pub_r000479_13_1) & 127;
  int stage_v_103_2 = (table_2[s_idx_103_2] + pub_r000479_13_2) & 127;
  table_1[s_idx_103_1] = (stage_v_103_1 + 7) & 63;
  table_2[s_idx_103_2] = (stage_v_103_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int s_idx_104_1 = stage_v_73_1 & 3;
  int s_idx_104_2 = stage_v_73_2 & 3;
  int stage_v_104_1 = (table_1[s_idx_104_1] + pub_r000479_2_1) & 127;
  int stage_v_104_2 = (table_2[s_idx_104_2] + pub_r000479_2_2) & 127;
  table_1[s_idx_104_1] = (stage_v_104_1 + 7) & 63;
  table_2[s_idx_104_2] = (stage_v_104_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int s_idx_105_1 = sec_r000479_6_1 & 3;
  int s_idx_105_2 = sec_r000479_6_2 & 3;
  int stage_v_105_1 = (table_1[s_idx_105_1] + pub_r000479_12_1) & 127;
  int stage_v_105_2 = (table_2[s_idx_105_2] + pub_r000479_12_2) & 127;
  table_1[s_idx_105_1] = (stage_v_105_1 + 7) & 63;
  table_2[s_idx_105_2] = (stage_v_105_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int s_idx_106_1 = stage_v_82_1 & 3;
  int s_idx_106_2 = stage_v_82_2 & 3;
  int stage_v_106_1 = (table_1[s_idx_106_1] + pub_r000479_16_1) & 127;
  int stage_v_106_2 = (table_2[s_idx_106_2] + pub_r000479_16_2) & 127;
  table_1[s_idx_106_1] = (stage_v_106_1 + 7) & 63;
  table_2[s_idx_106_2] = (stage_v_106_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int s_idx_107_1 = sec_r000479_1_1 & 3;
  int s_idx_107_2 = sec_r000479_1_2 & 3;
  int stage_v_107_1 = (table_1[s_idx_107_1] + pub_r000479_3_1) & 127;
  int stage_v_107_2 = (table_2[s_idx_107_2] + pub_r000479_3_2) & 127;
  table_1[s_idx_107_1] = (stage_v_107_1 + 7) & 63;
  table_2[s_idx_107_2] = (stage_v_107_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int s_idx_108_1 = sec_r000479_12_1 & 3;
  int s_idx_108_2 = sec_r000479_12_2 & 3;
  int stage_v_108_1 = (table_1[s_idx_108_1] + pub_r000479_0_1) & 127;
  int stage_v_108_2 = (table_2[s_idx_108_2] + pub_r000479_0_2) & 127;
  table_1[s_idx_108_1] = (stage_v_108_1 + 7) & 63;
  table_2[s_idx_108_2] = (stage_v_108_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int s_idx_109_1 = stage_v_74_1 & 3;
  int s_idx_109_2 = stage_v_74_2 & 3;
  int stage_v_109_1 = (table_1[s_idx_109_1] + pub_r000479_14_1) & 127;
  int stage_v_109_2 = (table_2[s_idx_109_2] + pub_r000479_14_2) & 127;
  table_1[s_idx_109_1] = (stage_v_109_1 + 7) & 63;
  table_2[s_idx_109_2] = (stage_v_109_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int s_idx_110_1 = stage_v_62_1 & 3;
  int s_idx_110_2 = stage_v_62_2 & 3;
  int stage_v_110_1 = (table_1[s_idx_110_1] + pub_r000479_3_1) & 127;
  int stage_v_110_2 = (table_2[s_idx_110_2] + pub_r000479_3_2) & 127;
  table_1[s_idx_110_1] = (stage_v_110_1 + 7) & 63;
  table_2[s_idx_110_2] = (stage_v_110_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int s_idx_111_1 = stage_v_69_1 & 3;
  int s_idx_111_2 = stage_v_69_2 & 3;
  int stage_v_111_1 = (table_1[s_idx_111_1] + pub_r000479_21_1) & 127;
  int stage_v_111_2 = (table_2[s_idx_111_2] + pub_r000479_21_2) & 127;
  table_1[s_idx_111_1] = (stage_v_111_1 + 7) & 63;
  table_2[s_idx_111_2] = (stage_v_111_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int s_idx_112_1 = sec_r000479_11_1 & 3;
  int s_idx_112_2 = sec_r000479_11_2 & 3;
  int stage_v_112_1 = (table_1[s_idx_112_1] + pub_r000479_19_1) & 127;
  int stage_v_112_2 = (table_2[s_idx_112_2] + pub_r000479_19_2) & 127;
  table_1[s_idx_112_1] = (stage_v_112_1 + 7) & 63;
  table_2[s_idx_112_2] = (stage_v_112_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int s_idx_113_1 = stage_v_100_1 & 3;
  int s_idx_113_2 = stage_v_100_2 & 3;
  int stage_v_113_1 = (table_1[s_idx_113_1] + pub_r000479_19_1) & 127;
  int stage_v_113_2 = (table_2[s_idx_113_2] + pub_r000479_19_2) & 127;
  table_1[s_idx_113_1] = (stage_v_113_1 + 7) & 63;
  table_2[s_idx_113_2] = (stage_v_113_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int s_idx_114_1 = stage_v_71_1 & 3;
  int s_idx_114_2 = stage_v_71_2 & 3;
  int stage_v_114_1 = (table_1[s_idx_114_1] + pub_r000479_0_1) & 127;
  int stage_v_114_2 = (table_2[s_idx_114_2] + pub_r000479_0_2) & 127;
  table_1[s_idx_114_1] = (stage_v_114_1 + 7) & 63;
  table_2[s_idx_114_2] = (stage_v_114_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int s_idx_115_1 = sec_r000479_3_1 & 3;
  int s_idx_115_2 = sec_r000479_3_2 & 3;
  int stage_v_115_1 = (table_1[s_idx_115_1] + pub_r000479_14_1) & 127;
  int stage_v_115_2 = (table_2[s_idx_115_2] + pub_r000479_14_2) & 127;
  table_1[s_idx_115_1] = (stage_v_115_1 + 7) & 63;
  table_2[s_idx_115_2] = (stage_v_115_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int s_idx_116_1 = sec_r000479_8_1 & 3;
  int s_idx_116_2 = sec_r000479_8_2 & 3;
  int stage_v_116_1 = (table_1[s_idx_116_1] + pub_r000479_1_1) & 127;
  int stage_v_116_2 = (table_2[s_idx_116_2] + pub_r000479_1_2) & 127;
  table_1[s_idx_116_1] = (stage_v_116_1 + 7) & 63;
  table_2[s_idx_116_2] = (stage_v_116_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int s_idx_117_1 = sec_r000479_16_1 & 3;
  int s_idx_117_2 = sec_r000479_16_2 & 3;
  int stage_v_117_1 = (table_1[s_idx_117_1] + pub_r000479_5_1) & 127;
  int stage_v_117_2 = (table_2[s_idx_117_2] + pub_r000479_5_2) & 127;
  table_1[s_idx_117_1] = (stage_v_117_1 + 7) & 63;
  table_2[s_idx_117_2] = (stage_v_117_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int s_idx_118_1 = sec_r000479_0_1 & 3;
  int s_idx_118_2 = sec_r000479_0_2 & 3;
  int stage_v_118_1 = (table_1[s_idx_118_1] + pub_r000479_9_1) & 127;
  int stage_v_118_2 = (table_2[s_idx_118_2] + pub_r000479_9_2) & 127;
  table_1[s_idx_118_1] = (stage_v_118_1 + 7) & 63;
  table_2[s_idx_118_2] = (stage_v_118_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int s_idx_119_1 = stage_v_86_1 & 3;
  int s_idx_119_2 = stage_v_86_2 & 3;
  int stage_v_119_1 = (table_1[s_idx_119_1] + pub_r000479_21_1) & 127;
  int stage_v_119_2 = (table_2[s_idx_119_2] + pub_r000479_21_2) & 127;
  table_1[s_idx_119_1] = (stage_v_119_1 + 7) & 63;
  table_2[s_idx_119_2] = (stage_v_119_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int s_idx_120_1 = stage_v_103_1 & 3;
  int s_idx_120_2 = stage_v_103_2 & 3;
  int stage_v_120_1 = (table_1[s_idx_120_1] + pub_r000479_12_1) & 127;
  int stage_v_120_2 = (table_2[s_idx_120_2] + pub_r000479_12_2) & 127;
  table_1[s_idx_120_1] = (stage_v_120_1 + 7) & 63;
  table_2[s_idx_120_2] = (stage_v_120_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int s_idx_121_1 = stage_v_61_1 & 3;
  int s_idx_121_2 = stage_v_61_2 & 3;
  int stage_v_121_1 = (table_1[s_idx_121_1] + pub_r000479_1_1) & 127;
  int stage_v_121_2 = (table_2[s_idx_121_2] + pub_r000479_1_2) & 127;
  table_1[s_idx_121_1] = (stage_v_121_1 + 7) & 63;
  table_2[s_idx_121_2] = (stage_v_121_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int s_idx_122_1 = sec_r000479_5_1 & 3;
  int s_idx_122_2 = sec_r000479_5_2 & 3;
  int stage_v_122_1 = (table_1[s_idx_122_1] + pub_r000479_6_1) & 127;
  int stage_v_122_2 = (table_2[s_idx_122_2] + pub_r000479_6_2) & 127;
  table_1[s_idx_122_1] = (stage_v_122_1 + 7) & 63;
  table_2[s_idx_122_2] = (stage_v_122_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int s_idx_123_1 = stage_v_113_1 & 3;
  int s_idx_123_2 = stage_v_113_2 & 3;
  int stage_v_123_1 = (table_1[s_idx_123_1] + pub_r000479_20_1) & 127;
  int stage_v_123_2 = (table_2[s_idx_123_2] + pub_r000479_20_2) & 127;
  table_1[s_idx_123_1] = (stage_v_123_1 + 7) & 63;
  table_2[s_idx_123_2] = (stage_v_123_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int s_idx_124_1 = stage_v_115_1 & 3;
  int s_idx_124_2 = stage_v_115_2 & 3;
  int stage_v_124_1 = (table_1[s_idx_124_1] + pub_r000479_21_1) & 127;
  int stage_v_124_2 = (table_2[s_idx_124_2] + pub_r000479_21_2) & 127;
  table_1[s_idx_124_1] = (stage_v_124_1 + 7) & 63;
  table_2[s_idx_124_2] = (stage_v_124_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int s_idx_125_1 = stage_v_93_1 & 3;
  int s_idx_125_2 = stage_v_93_2 & 3;
  int stage_v_125_1 = (table_1[s_idx_125_1] + pub_r000479_5_1) & 127;
  int stage_v_125_2 = (table_2[s_idx_125_2] + pub_r000479_5_2) & 127;
  table_1[s_idx_125_1] = (stage_v_125_1 + 7) & 63;
  table_2[s_idx_125_2] = (stage_v_125_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int s_idx_126_1 = sec_r000479_7_1 & 3;
  int s_idx_126_2 = sec_r000479_7_2 & 3;
  int stage_v_126_1 = (table_1[s_idx_126_1] + pub_r000479_10_1) & 127;
  int stage_v_126_2 = (table_2[s_idx_126_2] + pub_r000479_10_2) & 127;
  table_1[s_idx_126_1] = (stage_v_126_1 + 7) & 63;
  table_2[s_idx_126_2] = (stage_v_126_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int s_idx_127_1 = sec_r000479_11_1 & 3;
  int s_idx_127_2 = sec_r000479_11_2 & 3;
  int stage_v_127_1 = (table_1[s_idx_127_1] + pub_r000479_21_1) & 127;
  int stage_v_127_2 = (table_2[s_idx_127_2] + pub_r000479_21_2) & 127;
  table_1[s_idx_127_1] = (stage_v_127_1 + 7) & 63;
  table_2[s_idx_127_2] = (stage_v_127_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int s_idx_128_1 = stage_v_90_1 & 3;
  int s_idx_128_2 = stage_v_90_2 & 3;
  int stage_v_128_1 = (table_1[s_idx_128_1] + pub_r000479_1_1) & 127;
  int stage_v_128_2 = (table_2[s_idx_128_2] + pub_r000479_1_2) & 127;
  table_1[s_idx_128_1] = (stage_v_128_1 + 7) & 63;
  table_2[s_idx_128_2] = (stage_v_128_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int s_idx_129_1 = stage_v_91_1 & 3;
  int s_idx_129_2 = stage_v_91_2 & 3;
  int stage_v_129_1 = (table_1[s_idx_129_1] + pub_r000479_6_1) & 127;
  int stage_v_129_2 = (table_2[s_idx_129_2] + pub_r000479_6_2) & 127;
  table_1[s_idx_129_1] = (stage_v_129_1 + 7) & 63;
  table_2[s_idx_129_2] = (stage_v_129_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int s_idx_130_1 = sec_r000479_8_1 & 3;
  int s_idx_130_2 = sec_r000479_8_2 & 3;
  int stage_v_130_1 = (table_1[s_idx_130_1] + pub_r000479_16_1) & 127;
  int stage_v_130_2 = (table_2[s_idx_130_2] + pub_r000479_16_2) & 127;
  table_1[s_idx_130_1] = (stage_v_130_1 + 7) & 63;
  table_2[s_idx_130_2] = (stage_v_130_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int s_idx_131_1 = stage_v_104_1 & 3;
  int s_idx_131_2 = stage_v_104_2 & 3;
  int stage_v_131_1 = (table_1[s_idx_131_1] + pub_r000479_3_1) & 127;
  int stage_v_131_2 = (table_2[s_idx_131_2] + pub_r000479_3_2) & 127;
  table_1[s_idx_131_1] = (stage_v_131_1 + 7) & 63;
  table_2[s_idx_131_2] = (stage_v_131_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int s_idx_132_1 = stage_v_56_1 & 3;
  int s_idx_132_2 = stage_v_56_2 & 3;
  int stage_v_132_1 = (table_1[s_idx_132_1] + pub_r000479_1_1) & 127;
  int stage_v_132_2 = (table_2[s_idx_132_2] + pub_r000479_1_2) & 127;
  table_1[s_idx_132_1] = (stage_v_132_1 + 7) & 63;
  table_2[s_idx_132_2] = (stage_v_132_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int s_idx_133_1 = sec_r000479_4_1 & 3;
  int s_idx_133_2 = sec_r000479_4_2 & 3;
  int stage_v_133_1 = (table_1[s_idx_133_1] + pub_r000479_21_1) & 127;
  int stage_v_133_2 = (table_2[s_idx_133_2] + pub_r000479_21_2) & 127;
  table_1[s_idx_133_1] = (stage_v_133_1 + 7) & 63;
  table_2[s_idx_133_2] = (stage_v_133_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int s_idx_134_1 = sec_r000479_6_1 & 3;
  int s_idx_134_2 = sec_r000479_6_2 & 3;
  int stage_v_134_1 = (table_1[s_idx_134_1] + pub_r000479_18_1) & 127;
  int stage_v_134_2 = (table_2[s_idx_134_2] + pub_r000479_18_2) & 127;
  table_1[s_idx_134_1] = (stage_v_134_1 + 7) & 63;
  table_2[s_idx_134_2] = (stage_v_134_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int s_idx_135_1 = stage_v_67_1 & 3;
  int s_idx_135_2 = stage_v_67_2 & 3;
  int stage_v_135_1 = (table_1[s_idx_135_1] + pub_r000479_15_1) & 127;
  int stage_v_135_2 = (table_2[s_idx_135_2] + pub_r000479_15_2) & 127;
  table_1[s_idx_135_1] = (stage_v_135_1 + 7) & 63;
  table_2[s_idx_135_2] = (stage_v_135_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int s_idx_136_1 = stage_v_129_1 & 3;
  int s_idx_136_2 = stage_v_129_2 & 3;
  int stage_v_136_1 = (table_1[s_idx_136_1] + pub_r000479_21_1) & 127;
  int stage_v_136_2 = (table_2[s_idx_136_2] + pub_r000479_21_2) & 127;
  table_1[s_idx_136_1] = (stage_v_136_1 + 7) & 63;
  table_2[s_idx_136_2] = (stage_v_136_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int s_idx_137_1 = stage_v_74_1 & 3;
  int s_idx_137_2 = stage_v_74_2 & 3;
  int stage_v_137_1 = (table_1[s_idx_137_1] + pub_r000479_5_1) & 127;
  int stage_v_137_2 = (table_2[s_idx_137_2] + pub_r000479_5_2) & 127;
  table_1[s_idx_137_1] = (stage_v_137_1 + 7) & 63;
  table_2[s_idx_137_2] = (stage_v_137_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int s_idx_138_1 = stage_v_68_1 & 3;
  int s_idx_138_2 = stage_v_68_2 & 3;
  int stage_v_138_1 = (table_1[s_idx_138_1] + pub_r000479_11_1) & 127;
  int stage_v_138_2 = (table_2[s_idx_138_2] + pub_r000479_11_2) & 127;
  table_1[s_idx_138_1] = (stage_v_138_1 + 7) & 63;
  table_2[s_idx_138_2] = (stage_v_138_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int s_idx_139_1 = sec_r000479_11_1 & 3;
  int s_idx_139_2 = sec_r000479_11_2 & 3;
  int stage_v_139_1 = (table_1[s_idx_139_1] + pub_r000479_16_1) & 127;
  int stage_v_139_2 = (table_2[s_idx_139_2] + pub_r000479_16_2) & 127;
  table_1[s_idx_139_1] = (stage_v_139_1 + 7) & 63;
  table_2[s_idx_139_2] = (stage_v_139_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int s_idx_140_1 = sec_r000479_1_1 & 3;
  int s_idx_140_2 = sec_r000479_1_2 & 3;
  int stage_v_140_1 = (table_1[s_idx_140_1] + pub_r000479_21_1) & 127;
  int stage_v_140_2 = (table_2[s_idx_140_2] + pub_r000479_21_2) & 127;
  table_1[s_idx_140_1] = (stage_v_140_1 + 7) & 63;
  table_2[s_idx_140_2] = (stage_v_140_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int s_idx_141_1 = stage_v_69_1 & 3;
  int s_idx_141_2 = stage_v_69_2 & 3;
  int stage_v_141_1 = (table_1[s_idx_141_1] + pub_r000479_17_1) & 127;
  int stage_v_141_2 = (table_2[s_idx_141_2] + pub_r000479_17_2) & 127;
  table_1[s_idx_141_1] = (stage_v_141_1 + 7) & 63;
  table_2[s_idx_141_2] = (stage_v_141_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int s_idx_142_1 = sec_r000479_0_1 & 3;
  int s_idx_142_2 = sec_r000479_0_2 & 3;
  int stage_v_142_1 = (table_1[s_idx_142_1] + pub_r000479_20_1) & 127;
  int stage_v_142_2 = (table_2[s_idx_142_2] + pub_r000479_20_2) & 127;
  table_1[s_idx_142_1] = (stage_v_142_1 + 7) & 63;
  table_2[s_idx_142_2] = (stage_v_142_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int s_idx_143_1 = stage_v_66_1 & 3;
  int s_idx_143_2 = stage_v_66_2 & 3;
  int stage_v_143_1 = (table_1[s_idx_143_1] + pub_r000479_8_1) & 127;
  int stage_v_143_2 = (table_2[s_idx_143_2] + pub_r000479_8_2) & 127;
  table_1[s_idx_143_1] = (stage_v_143_1 + 7) & 63;
  table_2[s_idx_143_2] = (stage_v_143_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int s_idx_144_1 = stage_v_129_1 & 3;
  int s_idx_144_2 = stage_v_129_2 & 3;
  int stage_v_144_1 = (table_1[s_idx_144_1] + pub_r000479_15_1) & 127;
  int stage_v_144_2 = (table_2[s_idx_144_2] + pub_r000479_15_2) & 127;
  table_1[s_idx_144_1] = (stage_v_144_1 + 7) & 63;
  table_2[s_idx_144_2] = (stage_v_144_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int s_idx_145_1 = stage_v_129_1 & 3;
  int s_idx_145_2 = stage_v_129_2 & 3;
  int stage_v_145_1 = (table_1[s_idx_145_1] + pub_r000479_9_1) & 127;
  int stage_v_145_2 = (table_2[s_idx_145_2] + pub_r000479_9_2) & 127;
  table_1[s_idx_145_1] = (stage_v_145_1 + 7) & 63;
  table_2[s_idx_145_2] = (stage_v_145_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int s_idx_146_1 = stage_v_98_1 & 3;
  int s_idx_146_2 = stage_v_98_2 & 3;
  int stage_v_146_1 = (table_1[s_idx_146_1] + pub_r000479_2_1) & 127;
  int stage_v_146_2 = (table_2[s_idx_146_2] + pub_r000479_2_2) & 127;
  table_1[s_idx_146_1] = (stage_v_146_1 + 7) & 63;
  table_2[s_idx_146_2] = (stage_v_146_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int s_idx_147_1 = stage_v_65_1 & 3;
  int s_idx_147_2 = stage_v_65_2 & 3;
  int stage_v_147_1 = (table_1[s_idx_147_1] + pub_r000479_2_1) & 127;
  int stage_v_147_2 = (table_2[s_idx_147_2] + pub_r000479_2_2) & 127;
  table_1[s_idx_147_1] = (stage_v_147_1 + 7) & 63;
  table_2[s_idx_147_2] = (stage_v_147_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int s_idx_148_1 = stage_v_93_1 & 3;
  int s_idx_148_2 = stage_v_93_2 & 3;
  int stage_v_148_1 = (table_1[s_idx_148_1] + pub_r000479_11_1) & 127;
  int stage_v_148_2 = (table_2[s_idx_148_2] + pub_r000479_11_2) & 127;
  table_1[s_idx_148_1] = (stage_v_148_1 + 7) & 63;
  table_2[s_idx_148_2] = (stage_v_148_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int s_idx_149_1 = stage_v_71_1 & 3;
  int s_idx_149_2 = stage_v_71_2 & 3;
  int stage_v_149_1 = (table_1[s_idx_149_1] + pub_r000479_13_1) & 127;
  int stage_v_149_2 = (table_2[s_idx_149_2] + pub_r000479_13_2) & 127;
  table_1[s_idx_149_1] = (stage_v_149_1 + 7) & 63;
  table_2[s_idx_149_2] = (stage_v_149_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int s_idx_150_1 = stage_v_80_1 & 3;
  int s_idx_150_2 = stage_v_80_2 & 3;
  int stage_v_150_1 = (table_1[s_idx_150_1] + pub_r000479_1_1) & 127;
  int stage_v_150_2 = (table_2[s_idx_150_2] + pub_r000479_1_2) & 127;
  table_1[s_idx_150_1] = (stage_v_150_1 + 7) & 63;
  table_2[s_idx_150_2] = (stage_v_150_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int s_idx_151_1 = sec_r000479_15_1 & 3;
  int s_idx_151_2 = sec_r000479_15_2 & 3;
  int stage_v_151_1 = (table_1[s_idx_151_1] + pub_r000479_5_1) & 127;
  int stage_v_151_2 = (table_2[s_idx_151_2] + pub_r000479_5_2) & 127;
  table_1[s_idx_151_1] = (stage_v_151_1 + 7) & 63;
  table_2[s_idx_151_2] = (stage_v_151_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int s_idx_152_1 = sec_r000479_8_1 & 3;
  int s_idx_152_2 = sec_r000479_8_2 & 3;
  int stage_v_152_1 = (table_1[s_idx_152_1] + pub_r000479_18_1) & 127;
  int stage_v_152_2 = (table_2[s_idx_152_2] + pub_r000479_18_2) & 127;
  table_1[s_idx_152_1] = (stage_v_152_1 + 7) & 63;
  table_2[s_idx_152_2] = (stage_v_152_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int s_idx_153_1 = stage_v_72_1 & 3;
  int s_idx_153_2 = stage_v_72_2 & 3;
  int stage_v_153_1 = (table_1[s_idx_153_1] + pub_r000479_13_1) & 127;
  int stage_v_153_2 = (table_2[s_idx_153_2] + pub_r000479_13_2) & 127;
  table_1[s_idx_153_1] = (stage_v_153_1 + 7) & 63;
  table_2[s_idx_153_2] = (stage_v_153_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int s_idx_154_1 = stage_v_124_1 & 3;
  int s_idx_154_2 = stage_v_124_2 & 3;
  int stage_v_154_1 = (table_1[s_idx_154_1] + pub_r000479_13_1) & 127;
  int stage_v_154_2 = (table_2[s_idx_154_2] + pub_r000479_13_2) & 127;
  table_1[s_idx_154_1] = (stage_v_154_1 + 7) & 63;
  table_2[s_idx_154_2] = (stage_v_154_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int s_idx_155_1 = sec_r000479_1_1 & 3;
  int s_idx_155_2 = sec_r000479_1_2 & 3;
  int stage_v_155_1 = (table_1[s_idx_155_1] + pub_r000479_10_1) & 127;
  int stage_v_155_2 = (table_2[s_idx_155_2] + pub_r000479_10_2) & 127;
  table_1[s_idx_155_1] = (stage_v_155_1 + 7) & 63;
  table_2[s_idx_155_2] = (stage_v_155_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int s_idx_156_1 = stage_v_58_1 & 3;
  int s_idx_156_2 = stage_v_58_2 & 3;
  int stage_v_156_1 = (table_1[s_idx_156_1] + pub_r000479_8_1) & 127;
  int stage_v_156_2 = (table_2[s_idx_156_2] + pub_r000479_8_2) & 127;
  table_1[s_idx_156_1] = (stage_v_156_1 + 7) & 63;
  table_2[s_idx_156_2] = (stage_v_156_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int s_idx_157_1 = sec_r000479_5_1 & 3;
  int s_idx_157_2 = sec_r000479_5_2 & 3;
  int stage_v_157_1 = (table_1[s_idx_157_1] + pub_r000479_4_1) & 127;
  int stage_v_157_2 = (table_2[s_idx_157_2] + pub_r000479_4_2) & 127;
  table_1[s_idx_157_1] = (stage_v_157_1 + 7) & 63;
  table_2[s_idx_157_2] = (stage_v_157_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int s_idx_158_1 = sec_r000479_8_1 & 3;
  int s_idx_158_2 = sec_r000479_8_2 & 3;
  int stage_v_158_1 = (table_1[s_idx_158_1] + pub_r000479_14_1) & 127;
  int stage_v_158_2 = (table_2[s_idx_158_2] + pub_r000479_14_2) & 127;
  table_1[s_idx_158_1] = (stage_v_158_1 + 7) & 63;
  table_2[s_idx_158_2] = (stage_v_158_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int s_idx_159_1 = sec_r000479_11_1 & 3;
  int s_idx_159_2 = sec_r000479_11_2 & 3;
  int stage_v_159_1 = (table_1[s_idx_159_1] + pub_r000479_21_1) & 127;
  int stage_v_159_2 = (table_2[s_idx_159_2] + pub_r000479_21_2) & 127;
  table_1[s_idx_159_1] = (stage_v_159_1 + 7) & 63;
  table_2[s_idx_159_2] = (stage_v_159_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int s_idx_160_1 = stage_v_61_1 & 3;
  int s_idx_160_2 = stage_v_61_2 & 3;
  int stage_v_160_1 = (table_1[s_idx_160_1] + pub_r000479_20_1) & 127;
  int stage_v_160_2 = (table_2[s_idx_160_2] + pub_r000479_20_2) & 127;
  table_1[s_idx_160_1] = (stage_v_160_1 + 7) & 63;
  table_2[s_idx_160_2] = (stage_v_160_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int s_idx_161_1 = sec_r000479_6_1 & 3;
  int s_idx_161_2 = sec_r000479_6_2 & 3;
  int stage_v_161_1 = (table_1[s_idx_161_1] + pub_r000479_6_1) & 127;
  int stage_v_161_2 = (table_2[s_idx_161_2] + pub_r000479_6_2) & 127;
  table_1[s_idx_161_1] = (stage_v_161_1 + 7) & 63;
  table_2[s_idx_161_2] = (stage_v_161_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int s_idx_162_1 = stage_v_97_1 & 3;
  int s_idx_162_2 = stage_v_97_2 & 3;
  int stage_v_162_1 = (table_1[s_idx_162_1] + pub_r000479_7_1) & 127;
  int stage_v_162_2 = (table_2[s_idx_162_2] + pub_r000479_7_2) & 127;
  table_1[s_idx_162_1] = (stage_v_162_1 + 7) & 63;
  table_2[s_idx_162_2] = (stage_v_162_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int s_idx_163_1 = stage_v_96_1 & 3;
  int s_idx_163_2 = stage_v_96_2 & 3;
  int stage_v_163_1 = (table_1[s_idx_163_1] + pub_r000479_18_1) & 127;
  int stage_v_163_2 = (table_2[s_idx_163_2] + pub_r000479_18_2) & 127;
  table_1[s_idx_163_1] = (stage_v_163_1 + 7) & 63;
  table_2[s_idx_163_2] = (stage_v_163_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int s_idx_164_1 = stage_v_125_1 & 3;
  int s_idx_164_2 = stage_v_125_2 & 3;
  int stage_v_164_1 = (table_1[s_idx_164_1] + pub_r000479_11_1) & 127;
  int stage_v_164_2 = (table_2[s_idx_164_2] + pub_r000479_11_2) & 127;
  table_1[s_idx_164_1] = (stage_v_164_1 + 7) & 63;
  table_2[s_idx_164_2] = (stage_v_164_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int s_idx_165_1 = stage_v_80_1 & 3;
  int s_idx_165_2 = stage_v_80_2 & 3;
  int stage_v_165_1 = (table_1[s_idx_165_1] + pub_r000479_0_1) & 127;
  int stage_v_165_2 = (table_2[s_idx_165_2] + pub_r000479_0_2) & 127;
  table_1[s_idx_165_1] = (stage_v_165_1 + 7) & 63;
  table_2[s_idx_165_2] = (stage_v_165_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int s_idx_166_1 = stage_v_126_1 & 3;
  int s_idx_166_2 = stage_v_126_2 & 3;
  int stage_v_166_1 = (table_1[s_idx_166_1] + pub_r000479_7_1) & 127;
  int stage_v_166_2 = (table_2[s_idx_166_2] + pub_r000479_7_2) & 127;
  table_1[s_idx_166_1] = (stage_v_166_1 + 7) & 63;
  table_2[s_idx_166_2] = (stage_v_166_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int s_idx_167_1 = sec_r000479_12_1 & 3;
  int s_idx_167_2 = sec_r000479_12_2 & 3;
  int stage_v_167_1 = (table_1[s_idx_167_1] + pub_r000479_19_1) & 127;
  int stage_v_167_2 = (table_2[s_idx_167_2] + pub_r000479_19_2) & 127;
  table_1[s_idx_167_1] = (stage_v_167_1 + 7) & 63;
  table_2[s_idx_167_2] = (stage_v_167_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int s_idx_168_1 = stage_v_135_1 & 3;
  int s_idx_168_2 = stage_v_135_2 & 3;
  int stage_v_168_1 = (table_1[s_idx_168_1] + pub_r000479_19_1) & 127;
  int stage_v_168_2 = (table_2[s_idx_168_2] + pub_r000479_19_2) & 127;
  table_1[s_idx_168_1] = (stage_v_168_1 + 7) & 63;
  table_2[s_idx_168_2] = (stage_v_168_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int s_idx_169_1 = sec_r000479_17_1 & 3;
  int s_idx_169_2 = sec_r000479_17_2 & 3;
  int stage_v_169_1 = (table_1[s_idx_169_1] + pub_r000479_16_1) & 127;
  int stage_v_169_2 = (table_2[s_idx_169_2] + pub_r000479_16_2) & 127;
  table_1[s_idx_169_1] = (stage_v_169_1 + 7) & 63;
  table_2[s_idx_169_2] = (stage_v_169_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int s_idx_170_1 = sec_r000479_1_1 & 3;
  int s_idx_170_2 = sec_r000479_1_2 & 3;
  int stage_v_170_1 = (table_1[s_idx_170_1] + pub_r000479_20_1) & 127;
  int stage_v_170_2 = (table_2[s_idx_170_2] + pub_r000479_20_2) & 127;
  table_1[s_idx_170_1] = (stage_v_170_1 + 7) & 63;
  table_2[s_idx_170_2] = (stage_v_170_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int s_idx_171_1 = stage_v_136_1 & 3;
  int s_idx_171_2 = stage_v_136_2 & 3;
  int stage_v_171_1 = (table_1[s_idx_171_1] + pub_r000479_16_1) & 127;
  int stage_v_171_2 = (table_2[s_idx_171_2] + pub_r000479_16_2) & 127;
  table_1[s_idx_171_1] = (stage_v_171_1 + 7) & 63;
  table_2[s_idx_171_2] = (stage_v_171_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int s_idx_172_1 = sec_r000479_0_1 & 3;
  int s_idx_172_2 = sec_r000479_0_2 & 3;
  int stage_v_172_1 = (table_1[s_idx_172_1] + pub_r000479_21_1) & 127;
  int stage_v_172_2 = (table_2[s_idx_172_2] + pub_r000479_21_2) & 127;
  table_1[s_idx_172_1] = (stage_v_172_1 + 7) & 63;
  table_2[s_idx_172_2] = (stage_v_172_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int s_idx_173_1 = stage_v_104_1 & 3;
  int s_idx_173_2 = stage_v_104_2 & 3;
  int stage_v_173_1 = (table_1[s_idx_173_1] + pub_r000479_4_1) & 127;
  int stage_v_173_2 = (table_2[s_idx_173_2] + pub_r000479_4_2) & 127;
  table_1[s_idx_173_1] = (stage_v_173_1 + 7) & 63;
  table_2[s_idx_173_2] = (stage_v_173_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int s_idx_174_1 = stage_v_122_1 & 3;
  int s_idx_174_2 = stage_v_122_2 & 3;
  int stage_v_174_1 = (table_1[s_idx_174_1] + pub_r000479_18_1) & 127;
  int stage_v_174_2 = (table_2[s_idx_174_2] + pub_r000479_18_2) & 127;
  table_1[s_idx_174_1] = (stage_v_174_1 + 7) & 63;
  table_2[s_idx_174_2] = (stage_v_174_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int s_idx_175_1 = stage_v_153_1 & 3;
  int s_idx_175_2 = stage_v_153_2 & 3;
  int stage_v_175_1 = (table_1[s_idx_175_1] + pub_r000479_5_1) & 127;
  int stage_v_175_2 = (table_2[s_idx_175_2] + pub_r000479_5_2) & 127;
  table_1[s_idx_175_1] = (stage_v_175_1 + 7) & 63;
  table_2[s_idx_175_2] = (stage_v_175_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int s_idx_176_1 = stage_v_113_1 & 3;
  int s_idx_176_2 = stage_v_113_2 & 3;
  int stage_v_176_1 = (table_1[s_idx_176_1] + pub_r000479_5_1) & 127;
  int stage_v_176_2 = (table_2[s_idx_176_2] + pub_r000479_5_2) & 127;
  table_1[s_idx_176_1] = (stage_v_176_1 + 7) & 63;
  table_2[s_idx_176_2] = (stage_v_176_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int s_idx_177_1 = stage_v_160_1 & 3;
  int s_idx_177_2 = stage_v_160_2 & 3;
  int stage_v_177_1 = (table_1[s_idx_177_1] + pub_r000479_8_1) & 127;
  int stage_v_177_2 = (table_2[s_idx_177_2] + pub_r000479_8_2) & 127;
  table_1[s_idx_177_1] = (stage_v_177_1 + 7) & 63;
  table_2[s_idx_177_2] = (stage_v_177_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int s_idx_178_1 = stage_v_81_1 & 3;
  int s_idx_178_2 = stage_v_81_2 & 3;
  int stage_v_178_1 = (table_1[s_idx_178_1] + pub_r000479_18_1) & 127;
  int stage_v_178_2 = (table_2[s_idx_178_2] + pub_r000479_18_2) & 127;
  table_1[s_idx_178_1] = (stage_v_178_1 + 7) & 63;
  table_2[s_idx_178_2] = (stage_v_178_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int s_idx_179_1 = stage_v_76_1 & 3;
  int s_idx_179_2 = stage_v_76_2 & 3;
  int stage_v_179_1 = (table_1[s_idx_179_1] + pub_r000479_16_1) & 127;
  int stage_v_179_2 = (table_2[s_idx_179_2] + pub_r000479_16_2) & 127;
  table_1[s_idx_179_1] = (stage_v_179_1 + 7) & 63;
  table_2[s_idx_179_2] = (stage_v_179_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int s_idx_180_1 = stage_v_148_1 & 3;
  int s_idx_180_2 = stage_v_148_2 & 3;
  int stage_v_180_1 = (table_1[s_idx_180_1] + pub_r000479_0_1) & 127;
  int stage_v_180_2 = (table_2[s_idx_180_2] + pub_r000479_0_2) & 127;
  table_1[s_idx_180_1] = (stage_v_180_1 + 7) & 63;
  table_2[s_idx_180_2] = (stage_v_180_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int s_idx_181_1 = sec_r000479_12_1 & 3;
  int s_idx_181_2 = sec_r000479_12_2 & 3;
  int stage_v_181_1 = (table_1[s_idx_181_1] + pub_r000479_6_1) & 127;
  int stage_v_181_2 = (table_2[s_idx_181_2] + pub_r000479_6_2) & 127;
  table_1[s_idx_181_1] = (stage_v_181_1 + 7) & 63;
  table_2[s_idx_181_2] = (stage_v_181_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int s_idx_182_1 = sec_r000479_4_1 & 3;
  int s_idx_182_2 = sec_r000479_4_2 & 3;
  int stage_v_182_1 = (table_1[s_idx_182_1] + pub_r000479_20_1) & 127;
  int stage_v_182_2 = (table_2[s_idx_182_2] + pub_r000479_20_2) & 127;
  table_1[s_idx_182_1] = (stage_v_182_1 + 7) & 63;
  table_2[s_idx_182_2] = (stage_v_182_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int s_idx_183_1 = stage_v_162_1 & 3;
  int s_idx_183_2 = stage_v_162_2 & 3;
  int stage_v_183_1 = (table_1[s_idx_183_1] + pub_r000479_19_1) & 127;
  int stage_v_183_2 = (table_2[s_idx_183_2] + pub_r000479_19_2) & 127;
  table_1[s_idx_183_1] = (stage_v_183_1 + 7) & 63;
  table_2[s_idx_183_2] = (stage_v_183_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int s_idx_184_1 = stage_v_87_1 & 3;
  int s_idx_184_2 = stage_v_87_2 & 3;
  int stage_v_184_1 = (table_1[s_idx_184_1] + pub_r000479_18_1) & 127;
  int stage_v_184_2 = (table_2[s_idx_184_2] + pub_r000479_18_2) & 127;
  table_1[s_idx_184_1] = (stage_v_184_1 + 7) & 63;
  table_2[s_idx_184_2] = (stage_v_184_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int s_idx_185_1 = stage_v_93_1 & 3;
  int s_idx_185_2 = stage_v_93_2 & 3;
  int stage_v_185_1 = (table_1[s_idx_185_1] + pub_r000479_8_1) & 127;
  int stage_v_185_2 = (table_2[s_idx_185_2] + pub_r000479_8_2) & 127;
  table_1[s_idx_185_1] = (stage_v_185_1 + 7) & 63;
  table_2[s_idx_185_2] = (stage_v_185_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int s_idx_186_1 = stage_v_171_1 & 3;
  int s_idx_186_2 = stage_v_171_2 & 3;
  int stage_v_186_1 = (table_1[s_idx_186_1] + pub_r000479_8_1) & 127;
  int stage_v_186_2 = (table_2[s_idx_186_2] + pub_r000479_8_2) & 127;
  table_1[s_idx_186_1] = (stage_v_186_1 + 7) & 63;
  table_2[s_idx_186_2] = (stage_v_186_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int s_idx_187_1 = stage_v_166_1 & 3;
  int s_idx_187_2 = stage_v_166_2 & 3;
  int stage_v_187_1 = (table_1[s_idx_187_1] + pub_r000479_4_1) & 127;
  int stage_v_187_2 = (table_2[s_idx_187_2] + pub_r000479_4_2) & 127;
  table_1[s_idx_187_1] = (stage_v_187_1 + 7) & 63;
  table_2[s_idx_187_2] = (stage_v_187_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int s_idx_188_1 = stage_v_118_1 & 3;
  int s_idx_188_2 = stage_v_118_2 & 3;
  int stage_v_188_1 = (table_1[s_idx_188_1] + pub_r000479_14_1) & 127;
  int stage_v_188_2 = (table_2[s_idx_188_2] + pub_r000479_14_2) & 127;
  table_1[s_idx_188_1] = (stage_v_188_1 + 7) & 63;
  table_2[s_idx_188_2] = (stage_v_188_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int s_idx_189_1 = stage_v_53_1 & 3;
  int s_idx_189_2 = stage_v_53_2 & 3;
  int stage_v_189_1 = (table_1[s_idx_189_1] + pub_r000479_16_1) & 127;
  int stage_v_189_2 = (table_2[s_idx_189_2] + pub_r000479_16_2) & 127;
  table_1[s_idx_189_1] = (stage_v_189_1 + 7) & 63;
  table_2[s_idx_189_2] = (stage_v_189_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int s_idx_190_1 = stage_v_189_1 & 3;
  int s_idx_190_2 = stage_v_189_2 & 3;
  int stage_v_190_1 = (table_1[s_idx_190_1] + pub_r000479_20_1) & 127;
  int stage_v_190_2 = (table_2[s_idx_190_2] + pub_r000479_20_2) & 127;
  table_1[s_idx_190_1] = (stage_v_190_1 + 7) & 63;
  table_2[s_idx_190_2] = (stage_v_190_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int s_idx_191_1 = stage_v_161_1 & 3;
  int s_idx_191_2 = stage_v_161_2 & 3;
  int stage_v_191_1 = (table_1[s_idx_191_1] + pub_r000479_10_1) & 127;
  int stage_v_191_2 = (table_2[s_idx_191_2] + pub_r000479_10_2) & 127;
  table_1[s_idx_191_1] = (stage_v_191_1 + 7) & 63;
  table_2[s_idx_191_2] = (stage_v_191_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int s_idx_192_1 = stage_v_108_1 & 3;
  int s_idx_192_2 = stage_v_108_2 & 3;
  int stage_v_192_1 = (table_1[s_idx_192_1] + pub_r000479_19_1) & 127;
  int stage_v_192_2 = (table_2[s_idx_192_2] + pub_r000479_19_2) & 127;
  table_1[s_idx_192_1] = (stage_v_192_1 + 7) & 63;
  table_2[s_idx_192_2] = (stage_v_192_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int s_idx_193_1 = stage_v_132_1 & 3;
  int s_idx_193_2 = stage_v_132_2 & 3;
  int stage_v_193_1 = (table_1[s_idx_193_1] + pub_r000479_0_1) & 127;
  int stage_v_193_2 = (table_2[s_idx_193_2] + pub_r000479_0_2) & 127;
  table_1[s_idx_193_1] = (stage_v_193_1 + 7) & 63;
  table_2[s_idx_193_2] = (stage_v_193_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int s_idx_194_1 = stage_v_186_1 & 3;
  int s_idx_194_2 = stage_v_186_2 & 3;
  int stage_v_194_1 = (table_1[s_idx_194_1] + pub_r000479_21_1) & 127;
  int stage_v_194_2 = (table_2[s_idx_194_2] + pub_r000479_21_2) & 127;
  table_1[s_idx_194_1] = (stage_v_194_1 + 7) & 63;
  table_2[s_idx_194_2] = (stage_v_194_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int s_idx_195_1 = stage_v_161_1 & 3;
  int s_idx_195_2 = stage_v_161_2 & 3;
  int stage_v_195_1 = (table_1[s_idx_195_1] + pub_r000479_21_1) & 127;
  int stage_v_195_2 = (table_2[s_idx_195_2] + pub_r000479_21_2) & 127;
  table_1[s_idx_195_1] = (stage_v_195_1 + 7) & 63;
  table_2[s_idx_195_2] = (stage_v_195_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int s_idx_196_1 = stage_v_97_1 & 3;
  int s_idx_196_2 = stage_v_97_2 & 3;
  int stage_v_196_1 = (table_1[s_idx_196_1] + pub_r000479_0_1) & 127;
  int stage_v_196_2 = (table_2[s_idx_196_2] + pub_r000479_0_2) & 127;
  table_1[s_idx_196_1] = (stage_v_196_1 + 7) & 63;
  table_2[s_idx_196_2] = (stage_v_196_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int s_idx_197_1 = stage_v_50_1 & 3;
  int s_idx_197_2 = stage_v_50_2 & 3;
  int stage_v_197_1 = (table_1[s_idx_197_1] + pub_r000479_3_1) & 127;
  int stage_v_197_2 = (table_2[s_idx_197_2] + pub_r000479_3_2) & 127;
  table_1[s_idx_197_1] = (stage_v_197_1 + 7) & 63;
  table_2[s_idx_197_2] = (stage_v_197_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int s_idx_198_1 = stage_v_64_1 & 3;
  int s_idx_198_2 = stage_v_64_2 & 3;
  int stage_v_198_1 = (table_1[s_idx_198_1] + pub_r000479_14_1) & 127;
  int stage_v_198_2 = (table_2[s_idx_198_2] + pub_r000479_14_2) & 127;
  table_1[s_idx_198_1] = (stage_v_198_1 + 7) & 63;
  table_2[s_idx_198_2] = (stage_v_198_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int s_idx_199_1 = stage_v_76_1 & 3;
  int s_idx_199_2 = stage_v_76_2 & 3;
  int stage_v_199_1 = (table_1[s_idx_199_1] + pub_r000479_17_1) & 127;
  int stage_v_199_2 = (table_2[s_idx_199_2] + pub_r000479_17_2) & 127;
  table_1[s_idx_199_1] = (stage_v_199_1 + 7) & 63;
  table_2[s_idx_199_2] = (stage_v_199_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int s_idx_200_1 = stage_v_181_1 & 3;
  int s_idx_200_2 = stage_v_181_2 & 3;
  int stage_v_200_1 = (table_1[s_idx_200_1] + pub_r000479_4_1) & 127;
  int stage_v_200_2 = (table_2[s_idx_200_2] + pub_r000479_4_2) & 127;
  table_1[s_idx_200_1] = (stage_v_200_1 + 7) & 63;
  table_2[s_idx_200_2] = (stage_v_200_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int s_idx_201_1 = stage_v_147_1 & 3;
  int s_idx_201_2 = stage_v_147_2 & 3;
  int stage_v_201_1 = (table_1[s_idx_201_1] + pub_r000479_21_1) & 127;
  int stage_v_201_2 = (table_2[s_idx_201_2] + pub_r000479_21_2) & 127;
  table_1[s_idx_201_1] = (stage_v_201_1 + 7) & 63;
  table_2[s_idx_201_2] = (stage_v_201_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int s_idx_202_1 = sec_r000479_5_1 & 3;
  int s_idx_202_2 = sec_r000479_5_2 & 3;
  int stage_v_202_1 = (table_1[s_idx_202_1] + pub_r000479_12_1) & 127;
  int stage_v_202_2 = (table_2[s_idx_202_2] + pub_r000479_12_2) & 127;
  table_1[s_idx_202_1] = (stage_v_202_1 + 7) & 63;
  table_2[s_idx_202_2] = (stage_v_202_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int s_idx_203_1 = stage_v_166_1 & 3;
  int s_idx_203_2 = stage_v_166_2 & 3;
  int stage_v_203_1 = (table_1[s_idx_203_1] + pub_r000479_7_1) & 127;
  int stage_v_203_2 = (table_2[s_idx_203_2] + pub_r000479_7_2) & 127;
  table_1[s_idx_203_1] = (stage_v_203_1 + 7) & 63;
  table_2[s_idx_203_2] = (stage_v_203_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int s_idx_204_1 = sec_r000479_10_1 & 3;
  int s_idx_204_2 = sec_r000479_10_2 & 3;
  int stage_v_204_1 = (table_1[s_idx_204_1] + pub_r000479_7_1) & 127;
  int stage_v_204_2 = (table_2[s_idx_204_2] + pub_r000479_7_2) & 127;
  table_1[s_idx_204_1] = (stage_v_204_1 + 7) & 63;
  table_2[s_idx_204_2] = (stage_v_204_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int s_idx_205_1 = stage_v_181_1 & 3;
  int s_idx_205_2 = stage_v_181_2 & 3;
  int stage_v_205_1 = (table_1[s_idx_205_1] + pub_r000479_9_1) & 127;
  int stage_v_205_2 = (table_2[s_idx_205_2] + pub_r000479_9_2) & 127;
  table_1[s_idx_205_1] = (stage_v_205_1 + 7) & 63;
  table_2[s_idx_205_2] = (stage_v_205_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int s_idx_206_1 = stage_v_119_1 & 3;
  int s_idx_206_2 = stage_v_119_2 & 3;
  int stage_v_206_1 = (table_1[s_idx_206_1] + pub_r000479_10_1) & 127;
  int stage_v_206_2 = (table_2[s_idx_206_2] + pub_r000479_10_2) & 127;
  table_1[s_idx_206_1] = (stage_v_206_1 + 7) & 63;
  table_2[s_idx_206_2] = (stage_v_206_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int s_idx_207_1 = sec_r000479_11_1 & 3;
  int s_idx_207_2 = sec_r000479_11_2 & 3;
  int stage_v_207_1 = (table_1[s_idx_207_1] + pub_r000479_18_1) & 127;
  int stage_v_207_2 = (table_2[s_idx_207_2] + pub_r000479_18_2) & 127;
  table_1[s_idx_207_1] = (stage_v_207_1 + 7) & 63;
  table_2[s_idx_207_2] = (stage_v_207_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int s_idx_208_1 = stage_v_116_1 & 3;
  int s_idx_208_2 = stage_v_116_2 & 3;
  int stage_v_208_1 = (table_1[s_idx_208_1] + pub_r000479_19_1) & 127;
  int stage_v_208_2 = (table_2[s_idx_208_2] + pub_r000479_19_2) & 127;
  table_1[s_idx_208_1] = (stage_v_208_1 + 7) & 63;
  table_2[s_idx_208_2] = (stage_v_208_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int s_idx_209_1 = stage_v_58_1 & 3;
  int s_idx_209_2 = stage_v_58_2 & 3;
  int stage_v_209_1 = (table_1[s_idx_209_1] + pub_r000479_16_1) & 127;
  int stage_v_209_2 = (table_2[s_idx_209_2] + pub_r000479_16_2) & 127;
  table_1[s_idx_209_1] = (stage_v_209_1 + 7) & 63;
  table_2[s_idx_209_2] = (stage_v_209_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int s_idx_210_1 = stage_v_46_1 & 3;
  int s_idx_210_2 = stage_v_46_2 & 3;
  int stage_v_210_1 = (table_1[s_idx_210_1] + pub_r000479_3_1) & 127;
  int stage_v_210_2 = (table_2[s_idx_210_2] + pub_r000479_3_2) & 127;
  table_1[s_idx_210_1] = (stage_v_210_1 + 7) & 63;
  table_2[s_idx_210_2] = (stage_v_210_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int s_idx_211_1 = stage_v_169_1 & 3;
  int s_idx_211_2 = stage_v_169_2 & 3;
  int stage_v_211_1 = (table_1[s_idx_211_1] + pub_r000479_5_1) & 127;
  int stage_v_211_2 = (table_2[s_idx_211_2] + pub_r000479_5_2) & 127;
  table_1[s_idx_211_1] = (stage_v_211_1 + 7) & 63;
  table_2[s_idx_211_2] = (stage_v_211_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int s_idx_212_1 = stage_v_137_1 & 3;
  int s_idx_212_2 = stage_v_137_2 & 3;
  int stage_v_212_1 = (table_1[s_idx_212_1] + pub_r000479_6_1) & 127;
  int stage_v_212_2 = (table_2[s_idx_212_2] + pub_r000479_6_2) & 127;
  table_1[s_idx_212_1] = (stage_v_212_1 + 7) & 63;
  table_2[s_idx_212_2] = (stage_v_212_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int s_idx_213_1 = sec_r000479_11_1 & 3;
  int s_idx_213_2 = sec_r000479_11_2 & 3;
  int stage_v_213_1 = (table_1[s_idx_213_1] + pub_r000479_7_1) & 127;
  int stage_v_213_2 = (table_2[s_idx_213_2] + pub_r000479_7_2) & 127;
  table_1[s_idx_213_1] = (stage_v_213_1 + 7) & 63;
  table_2[s_idx_213_2] = (stage_v_213_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int s_idx_214_1 = sec_r000479_0_1 & 3;
  int s_idx_214_2 = sec_r000479_0_2 & 3;
  int stage_v_214_1 = (table_1[s_idx_214_1] + pub_r000479_4_1) & 127;
  int stage_v_214_2 = (table_2[s_idx_214_2] + pub_r000479_4_2) & 127;
  table_1[s_idx_214_1] = (stage_v_214_1 + 7) & 63;
  table_2[s_idx_214_2] = (stage_v_214_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int s_idx_215_1 = sec_r000479_0_1 & 3;
  int s_idx_215_2 = sec_r000479_0_2 & 3;
  int stage_v_215_1 = (table_1[s_idx_215_1] + pub_r000479_1_1) & 127;
  int stage_v_215_2 = (table_2[s_idx_215_2] + pub_r000479_1_2) & 127;
  table_1[s_idx_215_1] = (stage_v_215_1 + 7) & 63;
  table_2[s_idx_215_2] = (stage_v_215_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int s_idx_216_1 = stage_v_136_1 & 3;
  int s_idx_216_2 = stage_v_136_2 & 3;
  int stage_v_216_1 = (table_1[s_idx_216_1] + pub_r000479_10_1) & 127;
  int stage_v_216_2 = (table_2[s_idx_216_2] + pub_r000479_10_2) & 127;
  table_1[s_idx_216_1] = (stage_v_216_1 + 7) & 63;
  table_2[s_idx_216_2] = (stage_v_216_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int s_idx_217_1 = stage_v_156_1 & 3;
  int s_idx_217_2 = stage_v_156_2 & 3;
  int stage_v_217_1 = (table_1[s_idx_217_1] + pub_r000479_1_1) & 127;
  int stage_v_217_2 = (table_2[s_idx_217_2] + pub_r000479_1_2) & 127;
  table_1[s_idx_217_1] = (stage_v_217_1 + 7) & 63;
  table_2[s_idx_217_2] = (stage_v_217_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int s_idx_218_1 = sec_r000479_13_1 & 3;
  int s_idx_218_2 = sec_r000479_13_2 & 3;
  int stage_v_218_1 = (table_1[s_idx_218_1] + pub_r000479_15_1) & 127;
  int stage_v_218_2 = (table_2[s_idx_218_2] + pub_r000479_15_2) & 127;
  table_1[s_idx_218_1] = (stage_v_218_1 + 7) & 63;
  table_2[s_idx_218_2] = (stage_v_218_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int s_idx_219_1 = stage_v_194_1 & 3;
  int s_idx_219_2 = stage_v_194_2 & 3;
  int stage_v_219_1 = (table_1[s_idx_219_1] + pub_r000479_10_1) & 127;
  int stage_v_219_2 = (table_2[s_idx_219_2] + pub_r000479_10_2) & 127;
  table_1[s_idx_219_1] = (stage_v_219_1 + 7) & 63;
  table_2[s_idx_219_2] = (stage_v_219_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int s_idx_220_1 = sec_r000479_13_1 & 3;
  int s_idx_220_2 = sec_r000479_13_2 & 3;
  int stage_v_220_1 = (table_1[s_idx_220_1] + pub_r000479_20_1) & 127;
  int stage_v_220_2 = (table_2[s_idx_220_2] + pub_r000479_20_2) & 127;
  table_1[s_idx_220_1] = (stage_v_220_1 + 7) & 63;
  table_2[s_idx_220_2] = (stage_v_220_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int s_idx_221_1 = stage_v_49_1 & 3;
  int s_idx_221_2 = stage_v_49_2 & 3;
  int stage_v_221_1 = (table_1[s_idx_221_1] + pub_r000479_3_1) & 127;
  int stage_v_221_2 = (table_2[s_idx_221_2] + pub_r000479_3_2) & 127;
  table_1[s_idx_221_1] = (stage_v_221_1 + 7) & 63;
  table_2[s_idx_221_2] = (stage_v_221_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int s_idx_222_1 = stage_v_170_1 & 3;
  int s_idx_222_2 = stage_v_170_2 & 3;
  int stage_v_222_1 = (table_1[s_idx_222_1] + pub_r000479_14_1) & 127;
  int stage_v_222_2 = (table_2[s_idx_222_2] + pub_r000479_14_2) & 127;
  table_1[s_idx_222_1] = (stage_v_222_1 + 7) & 63;
  table_2[s_idx_222_2] = (stage_v_222_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int s_idx_223_1 = sec_r000479_6_1 & 3;
  int s_idx_223_2 = sec_r000479_6_2 & 3;
  int stage_v_223_1 = (table_1[s_idx_223_1] + pub_r000479_1_1) & 127;
  int stage_v_223_2 = (table_2[s_idx_223_2] + pub_r000479_1_2) & 127;
  table_1[s_idx_223_1] = (stage_v_223_1 + 7) & 63;
  table_2[s_idx_223_2] = (stage_v_223_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int s_idx_224_1 = sec_r000479_4_1 & 3;
  int s_idx_224_2 = sec_r000479_4_2 & 3;
  int stage_v_224_1 = (table_1[s_idx_224_1] + pub_r000479_3_1) & 127;
  int stage_v_224_2 = (table_2[s_idx_224_2] + pub_r000479_3_2) & 127;
  table_1[s_idx_224_1] = (stage_v_224_1 + 7) & 63;
  table_2[s_idx_224_2] = (stage_v_224_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int s_idx_225_1 = sec_r000479_17_1 & 3;
  int s_idx_225_2 = sec_r000479_17_2 & 3;
  int stage_v_225_1 = (table_1[s_idx_225_1] + pub_r000479_19_1) & 127;
  int stage_v_225_2 = (table_2[s_idx_225_2] + pub_r000479_19_2) & 127;
  table_1[s_idx_225_1] = (stage_v_225_1 + 7) & 63;
  table_2[s_idx_225_2] = (stage_v_225_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  int s_idx_226_1 = stage_v_88_1 & 3;
  int s_idx_226_2 = stage_v_88_2 & 3;
  int stage_v_226_1 = (table_1[s_idx_226_1] + pub_r000479_15_1) & 127;
  int stage_v_226_2 = (table_2[s_idx_226_2] + pub_r000479_15_2) & 127;
  table_1[s_idx_226_1] = (stage_v_226_1 + 7) & 63;
  table_2[s_idx_226_2] = (stage_v_226_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int s_idx_227_1 = sec_r000479_11_1 & 3;
  int s_idx_227_2 = sec_r000479_11_2 & 3;
  int stage_v_227_1 = (table_1[s_idx_227_1] + pub_r000479_17_1) & 127;
  int stage_v_227_2 = (table_2[s_idx_227_2] + pub_r000479_17_2) & 127;
  table_1[s_idx_227_1] = (stage_v_227_1 + 7) & 63;
  table_2[s_idx_227_2] = (stage_v_227_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int s_idx_228_1 = sec_r000479_13_1 & 3;
  int s_idx_228_2 = sec_r000479_13_2 & 3;
  int stage_v_228_1 = (table_1[s_idx_228_1] + pub_r000479_14_1) & 127;
  int stage_v_228_2 = (table_2[s_idx_228_2] + pub_r000479_14_2) & 127;
  table_1[s_idx_228_1] = (stage_v_228_1 + 7) & 63;
  table_2[s_idx_228_2] = (stage_v_228_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int s_idx_229_1 = sec_r000479_9_1 & 3;
  int s_idx_229_2 = sec_r000479_9_2 & 3;
  int stage_v_229_1 = (table_1[s_idx_229_1] + pub_r000479_9_1) & 127;
  int stage_v_229_2 = (table_2[s_idx_229_2] + pub_r000479_9_2) & 127;
  table_1[s_idx_229_1] = (stage_v_229_1 + 7) & 63;
  table_2[s_idx_229_2] = (stage_v_229_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  int s_idx_230_1 = sec_r000479_0_1 & 3;
  int s_idx_230_2 = sec_r000479_0_2 & 3;
  int stage_v_230_1 = (table_1[s_idx_230_1] + pub_r000479_19_1) & 127;
  int stage_v_230_2 = (table_2[s_idx_230_2] + pub_r000479_19_2) & 127;
  table_1[s_idx_230_1] = (stage_v_230_1 + 7) & 63;
  table_2[s_idx_230_2] = (stage_v_230_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int s_idx_231_1 = sec_r000479_2_1 & 3;
  int s_idx_231_2 = sec_r000479_2_2 & 3;
  int stage_v_231_1 = (table_1[s_idx_231_1] + pub_r000479_19_1) & 127;
  int stage_v_231_2 = (table_2[s_idx_231_2] + pub_r000479_19_2) & 127;
  table_1[s_idx_231_1] = (stage_v_231_1 + 7) & 63;
  table_2[s_idx_231_2] = (stage_v_231_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  int s_idx_232_1 = stage_v_166_1 & 3;
  int s_idx_232_2 = stage_v_166_2 & 3;
  int stage_v_232_1 = (table_1[s_idx_232_1] + pub_r000479_5_1) & 127;
  int stage_v_232_2 = (table_2[s_idx_232_2] + pub_r000479_5_2) & 127;
  table_1[s_idx_232_1] = (stage_v_232_1 + 7) & 63;
  table_2[s_idx_232_2] = (stage_v_232_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000479_12_1 == pub_r000479_12_2);
  __CPROVER_assume(sec_r000479_0_1 != sec_r000479_0_2);
  __CPROVER_assume(sec_r000479_12_1 != sec_r000479_12_2);
  __CPROVER_assume(sec_r000479_9_1 != sec_r000479_9_2);
  __CPROVER_assume(pub_r000479_19_1 == pub_r000479_19_2);
  __CPROVER_assume(pub_r000479_8_1 == pub_r000479_8_2);
  __CPROVER_assume(pub_r000479_11_1 == pub_r000479_11_2);
  __CPROVER_assume(sec_r000479_11_1 != sec_r000479_11_2);
  __CPROVER_assume(sec_r000479_13_1 != sec_r000479_13_2);
  __CPROVER_assume(pub_r000479_2_1 == pub_r000479_2_2);
  __CPROVER_assume(pub_r000479_16_1 == pub_r000479_16_2);
  __CPROVER_assume(sec_r000479_14_1 != sec_r000479_14_2);
  __CPROVER_assume(sec_r000479_7_1 != sec_r000479_7_2);
  __CPROVER_assume(pub_r000479_4_1 == pub_r000479_4_2);
  __CPROVER_assume(pub_r000479_10_1 == pub_r000479_10_2);
  __CPROVER_assume(pub_r000479_15_1 == pub_r000479_15_2);
  __CPROVER_assume(sec_r000479_2_1 != sec_r000479_2_2);
  __CPROVER_assume(pub_r000479_7_1 == pub_r000479_7_2);
  __CPROVER_assume(pub_r000479_9_1 == pub_r000479_9_2);
  __CPROVER_assume(pub_r000479_21_1 == pub_r000479_21_2);
  __CPROVER_assume(pub_r000479_6_1 == pub_r000479_6_2);
  __CPROVER_assume(sec_r000479_5_1 != sec_r000479_5_2);
  __CPROVER_assume(pub_r000479_17_1 == pub_r000479_17_2);
  __CPROVER_assume(sec_r000479_1_1 != sec_r000479_1_2);
  __CPROVER_assume(pub_r000479_14_1 == pub_r000479_14_2);
  __CPROVER_assume(pub_r000479_1_1 == pub_r000479_1_2);
  __CPROVER_assume(sec_r000479_16_1 != sec_r000479_16_2);
  __CPROVER_assume(sec_r000479_3_1 != sec_r000479_3_2);
  __CPROVER_assume(sec_r000479_10_1 != sec_r000479_10_2);
  __CPROVER_assume(sec_r000479_8_1 != sec_r000479_8_2);
  __CPROVER_assume(pub_r000479_18_1 == pub_r000479_18_2);
  __CPROVER_assume(pub_r000479_0_1 == pub_r000479_0_2);
  __CPROVER_assume(sec_r000479_4_1 != sec_r000479_4_2);
  __CPROVER_assume(pub_r000479_20_1 == pub_r000479_20_2);
  __CPROVER_assume(sec_r000479_17_1 != sec_r000479_17_2);
  __CPROVER_assume(sec_r000479_6_1 != sec_r000479_6_2);
  __CPROVER_assume(sec_r000479_15_1 != sec_r000479_15_2);
  __CPROVER_assume(pub_r000479_13_1 == pub_r000479_13_2);
  __CPROVER_assume(pub_r000479_3_1 == pub_r000479_3_2);
  __CPROVER_assume(pub_r000479_5_1 == pub_r000479_5_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.tag == st_var_2_2.tag);
  assert(st_var_2_1.iv == st_var_2_2.iv);
  assert(st_var_2_1.counter == st_var_2_2.counter);
  assert(st_var_2_1.nonce == st_var_2_2.nonce);
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
  assert(s_idx_46_1 == s_idx_46_2);
  assert(stage_v_46_1 == stage_v_46_2);
  assert(s_idx_47_1 == s_idx_47_2);
  assert(stage_v_47_1 == stage_v_47_2);
  assert(s_idx_48_1 == s_idx_48_2);
  assert(stage_v_48_1 == stage_v_48_2);
  assert(s_idx_49_1 == s_idx_49_2);
  assert(stage_v_49_1 == stage_v_49_2);
  assert(s_idx_50_1 == s_idx_50_2);
  assert(stage_v_50_1 == stage_v_50_2);
  assert(s_idx_51_1 == s_idx_51_2);
  assert(stage_v_51_1 == stage_v_51_2);
  assert(s_idx_52_1 == s_idx_52_2);
  assert(stage_v_52_1 == stage_v_52_2);
  assert(s_idx_53_1 == s_idx_53_2);
  assert(stage_v_53_1 == stage_v_53_2);
  assert(s_idx_54_1 == s_idx_54_2);
  assert(stage_v_54_1 == stage_v_54_2);
  assert(s_idx_55_1 == s_idx_55_2);
  assert(stage_v_55_1 == stage_v_55_2);
  assert(s_idx_56_1 == s_idx_56_2);
  assert(stage_v_56_1 == stage_v_56_2);
  assert(s_idx_57_1 == s_idx_57_2);
  assert(stage_v_57_1 == stage_v_57_2);
  assert(s_idx_58_1 == s_idx_58_2);
  assert(stage_v_58_1 == stage_v_58_2);
  assert(s_idx_59_1 == s_idx_59_2);
  assert(stage_v_59_1 == stage_v_59_2);
  assert(s_idx_60_1 == s_idx_60_2);
  assert(stage_v_60_1 == stage_v_60_2);
  assert(s_idx_61_1 == s_idx_61_2);
  assert(stage_v_61_1 == stage_v_61_2);
  assert(s_idx_62_1 == s_idx_62_2);
  assert(stage_v_62_1 == stage_v_62_2);
  assert(s_idx_63_1 == s_idx_63_2);
  assert(stage_v_63_1 == stage_v_63_2);
  assert(s_idx_64_1 == s_idx_64_2);
  assert(stage_v_64_1 == stage_v_64_2);
  assert(s_idx_65_1 == s_idx_65_2);
  assert(stage_v_65_1 == stage_v_65_2);
  assert(s_idx_66_1 == s_idx_66_2);
  assert(stage_v_66_1 == stage_v_66_2);
  assert(s_idx_67_1 == s_idx_67_2);
  assert(stage_v_67_1 == stage_v_67_2);
  assert(s_idx_68_1 == s_idx_68_2);
  assert(stage_v_68_1 == stage_v_68_2);
  assert(s_idx_69_1 == s_idx_69_2);
  assert(stage_v_69_1 == stage_v_69_2);
  assert(s_idx_70_1 == s_idx_70_2);
  assert(stage_v_70_1 == stage_v_70_2);
  assert(s_idx_71_1 == s_idx_71_2);
  assert(stage_v_71_1 == stage_v_71_2);
  assert(s_idx_72_1 == s_idx_72_2);
  assert(stage_v_72_1 == stage_v_72_2);
  assert(s_idx_73_1 == s_idx_73_2);
  assert(stage_v_73_1 == stage_v_73_2);
  assert(s_idx_74_1 == s_idx_74_2);
  assert(stage_v_74_1 == stage_v_74_2);
  assert(s_idx_75_1 == s_idx_75_2);
  assert(stage_v_75_1 == stage_v_75_2);
  assert(s_idx_76_1 == s_idx_76_2);
  assert(stage_v_76_1 == stage_v_76_2);
  assert(s_idx_77_1 == s_idx_77_2);
  assert(stage_v_77_1 == stage_v_77_2);
  assert(s_idx_78_1 == s_idx_78_2);
  assert(stage_v_78_1 == stage_v_78_2);
  assert(s_idx_79_1 == s_idx_79_2);
  assert(stage_v_79_1 == stage_v_79_2);
  assert(s_idx_80_1 == s_idx_80_2);
  assert(stage_v_80_1 == stage_v_80_2);
  assert(s_idx_81_1 == s_idx_81_2);
  assert(stage_v_81_1 == stage_v_81_2);
  assert(s_idx_82_1 == s_idx_82_2);
  assert(stage_v_82_1 == stage_v_82_2);
  assert(s_idx_83_1 == s_idx_83_2);
  assert(stage_v_83_1 == stage_v_83_2);
  assert(s_idx_84_1 == s_idx_84_2);
  assert(stage_v_84_1 == stage_v_84_2);
  assert(s_idx_85_1 == s_idx_85_2);
  assert(stage_v_85_1 == stage_v_85_2);
  assert(s_idx_86_1 == s_idx_86_2);
  assert(stage_v_86_1 == stage_v_86_2);
  assert(s_idx_87_1 == s_idx_87_2);
  assert(stage_v_87_1 == stage_v_87_2);
  assert(s_idx_88_1 == s_idx_88_2);
  assert(stage_v_88_1 == stage_v_88_2);
  assert(s_idx_89_1 == s_idx_89_2);
  assert(stage_v_89_1 == stage_v_89_2);
  assert(s_idx_90_1 == s_idx_90_2);
  assert(stage_v_90_1 == stage_v_90_2);
  assert(s_idx_91_1 == s_idx_91_2);
  assert(stage_v_91_1 == stage_v_91_2);
  assert(s_idx_92_1 == s_idx_92_2);
  assert(stage_v_92_1 == stage_v_92_2);
  assert(s_idx_93_1 == s_idx_93_2);
  assert(stage_v_93_1 == stage_v_93_2);
  assert(s_idx_94_1 == s_idx_94_2);
  assert(stage_v_94_1 == stage_v_94_2);
  assert(s_idx_95_1 == s_idx_95_2);
  assert(stage_v_95_1 == stage_v_95_2);
  assert(s_idx_96_1 == s_idx_96_2);
  assert(stage_v_96_1 == stage_v_96_2);
  assert(s_idx_97_1 == s_idx_97_2);
  assert(stage_v_97_1 == stage_v_97_2);
  assert(s_idx_98_1 == s_idx_98_2);
  assert(stage_v_98_1 == stage_v_98_2);
  assert(s_idx_99_1 == s_idx_99_2);
  assert(stage_v_99_1 == stage_v_99_2);
  assert(s_idx_100_1 == s_idx_100_2);
  assert(stage_v_100_1 == stage_v_100_2);
  assert(s_idx_101_1 == s_idx_101_2);
  assert(stage_v_101_1 == stage_v_101_2);
  assert(s_idx_102_1 == s_idx_102_2);
  assert(stage_v_102_1 == stage_v_102_2);
  assert(s_idx_103_1 == s_idx_103_2);
  assert(stage_v_103_1 == stage_v_103_2);
  assert(s_idx_104_1 == s_idx_104_2);
  assert(stage_v_104_1 == stage_v_104_2);
  assert(s_idx_105_1 == s_idx_105_2);
  assert(stage_v_105_1 == stage_v_105_2);
  assert(s_idx_106_1 == s_idx_106_2);
  assert(stage_v_106_1 == stage_v_106_2);
  assert(s_idx_107_1 == s_idx_107_2);
  assert(stage_v_107_1 == stage_v_107_2);
  assert(s_idx_108_1 == s_idx_108_2);
  assert(stage_v_108_1 == stage_v_108_2);
  assert(s_idx_109_1 == s_idx_109_2);
  assert(stage_v_109_1 == stage_v_109_2);
  assert(s_idx_110_1 == s_idx_110_2);
  assert(stage_v_110_1 == stage_v_110_2);
  assert(s_idx_111_1 == s_idx_111_2);
  assert(stage_v_111_1 == stage_v_111_2);
  assert(s_idx_112_1 == s_idx_112_2);
  assert(stage_v_112_1 == stage_v_112_2);
  assert(s_idx_113_1 == s_idx_113_2);
  assert(stage_v_113_1 == stage_v_113_2);
  assert(s_idx_114_1 == s_idx_114_2);
  assert(stage_v_114_1 == stage_v_114_2);
  assert(s_idx_115_1 == s_idx_115_2);
  assert(stage_v_115_1 == stage_v_115_2);
  assert(s_idx_116_1 == s_idx_116_2);
  assert(stage_v_116_1 == stage_v_116_2);
  assert(s_idx_117_1 == s_idx_117_2);
  assert(stage_v_117_1 == stage_v_117_2);
  assert(s_idx_118_1 == s_idx_118_2);
  assert(stage_v_118_1 == stage_v_118_2);
  assert(s_idx_119_1 == s_idx_119_2);
  assert(stage_v_119_1 == stage_v_119_2);
  assert(s_idx_120_1 == s_idx_120_2);
  assert(stage_v_120_1 == stage_v_120_2);
  assert(s_idx_121_1 == s_idx_121_2);
  assert(stage_v_121_1 == stage_v_121_2);
  assert(s_idx_122_1 == s_idx_122_2);
  assert(stage_v_122_1 == stage_v_122_2);
  assert(s_idx_123_1 == s_idx_123_2);
  assert(stage_v_123_1 == stage_v_123_2);
  assert(s_idx_124_1 == s_idx_124_2);
  assert(stage_v_124_1 == stage_v_124_2);
  assert(s_idx_125_1 == s_idx_125_2);
  assert(stage_v_125_1 == stage_v_125_2);
  assert(s_idx_126_1 == s_idx_126_2);
  assert(stage_v_126_1 == stage_v_126_2);
  assert(s_idx_127_1 == s_idx_127_2);
  assert(stage_v_127_1 == stage_v_127_2);
  assert(s_idx_128_1 == s_idx_128_2);
  assert(stage_v_128_1 == stage_v_128_2);
  assert(s_idx_129_1 == s_idx_129_2);
  assert(stage_v_129_1 == stage_v_129_2);
  assert(s_idx_130_1 == s_idx_130_2);
  assert(stage_v_130_1 == stage_v_130_2);
  assert(s_idx_131_1 == s_idx_131_2);
  assert(stage_v_131_1 == stage_v_131_2);
  assert(s_idx_132_1 == s_idx_132_2);
  assert(stage_v_132_1 == stage_v_132_2);
  assert(s_idx_133_1 == s_idx_133_2);
  assert(stage_v_133_1 == stage_v_133_2);
  assert(s_idx_134_1 == s_idx_134_2);
  assert(stage_v_134_1 == stage_v_134_2);
  assert(s_idx_135_1 == s_idx_135_2);
  assert(stage_v_135_1 == stage_v_135_2);
  assert(s_idx_136_1 == s_idx_136_2);
  assert(stage_v_136_1 == stage_v_136_2);
  assert(s_idx_137_1 == s_idx_137_2);
  assert(stage_v_137_1 == stage_v_137_2);
  assert(s_idx_138_1 == s_idx_138_2);
  assert(stage_v_138_1 == stage_v_138_2);
  assert(s_idx_139_1 == s_idx_139_2);
  assert(stage_v_139_1 == stage_v_139_2);
  assert(s_idx_140_1 == s_idx_140_2);
  assert(stage_v_140_1 == stage_v_140_2);
  assert(s_idx_141_1 == s_idx_141_2);
  assert(stage_v_141_1 == stage_v_141_2);
  assert(s_idx_142_1 == s_idx_142_2);
  assert(stage_v_142_1 == stage_v_142_2);
  assert(s_idx_143_1 == s_idx_143_2);
  assert(stage_v_143_1 == stage_v_143_2);
  assert(s_idx_144_1 == s_idx_144_2);
  assert(stage_v_144_1 == stage_v_144_2);
  assert(s_idx_145_1 == s_idx_145_2);
  assert(stage_v_145_1 == stage_v_145_2);
  assert(s_idx_146_1 == s_idx_146_2);
  assert(stage_v_146_1 == stage_v_146_2);
  assert(s_idx_147_1 == s_idx_147_2);
  assert(stage_v_147_1 == stage_v_147_2);
  assert(s_idx_148_1 == s_idx_148_2);
  assert(stage_v_148_1 == stage_v_148_2);
  assert(s_idx_149_1 == s_idx_149_2);
  assert(stage_v_149_1 == stage_v_149_2);
  assert(s_idx_150_1 == s_idx_150_2);
  assert(stage_v_150_1 == stage_v_150_2);
  assert(s_idx_151_1 == s_idx_151_2);
  assert(stage_v_151_1 == stage_v_151_2);
  assert(s_idx_152_1 == s_idx_152_2);
  assert(stage_v_152_1 == stage_v_152_2);
  assert(s_idx_153_1 == s_idx_153_2);
  assert(stage_v_153_1 == stage_v_153_2);
  assert(s_idx_154_1 == s_idx_154_2);
  assert(stage_v_154_1 == stage_v_154_2);
  assert(s_idx_155_1 == s_idx_155_2);
  assert(stage_v_155_1 == stage_v_155_2);
  assert(s_idx_156_1 == s_idx_156_2);
  assert(stage_v_156_1 == stage_v_156_2);
  assert(s_idx_157_1 == s_idx_157_2);
  assert(stage_v_157_1 == stage_v_157_2);
  assert(s_idx_158_1 == s_idx_158_2);
  assert(stage_v_158_1 == stage_v_158_2);
  assert(s_idx_159_1 == s_idx_159_2);
  assert(stage_v_159_1 == stage_v_159_2);
  assert(s_idx_160_1 == s_idx_160_2);
  assert(stage_v_160_1 == stage_v_160_2);
  assert(s_idx_161_1 == s_idx_161_2);
  assert(stage_v_161_1 == stage_v_161_2);
  assert(s_idx_162_1 == s_idx_162_2);
  assert(stage_v_162_1 == stage_v_162_2);
  assert(s_idx_163_1 == s_idx_163_2);
  assert(stage_v_163_1 == stage_v_163_2);
  assert(s_idx_164_1 == s_idx_164_2);
  assert(stage_v_164_1 == stage_v_164_2);
  assert(s_idx_165_1 == s_idx_165_2);
  assert(stage_v_165_1 == stage_v_165_2);
  assert(s_idx_166_1 == s_idx_166_2);
  assert(stage_v_166_1 == stage_v_166_2);
  assert(s_idx_167_1 == s_idx_167_2);
  assert(stage_v_167_1 == stage_v_167_2);
  assert(s_idx_168_1 == s_idx_168_2);
  assert(stage_v_168_1 == stage_v_168_2);
  assert(s_idx_169_1 == s_idx_169_2);
  assert(stage_v_169_1 == stage_v_169_2);
  assert(s_idx_170_1 == s_idx_170_2);
  assert(stage_v_170_1 == stage_v_170_2);
  assert(s_idx_171_1 == s_idx_171_2);
  assert(stage_v_171_1 == stage_v_171_2);
  assert(s_idx_172_1 == s_idx_172_2);
  assert(stage_v_172_1 == stage_v_172_2);
  assert(s_idx_173_1 == s_idx_173_2);
  assert(stage_v_173_1 == stage_v_173_2);
  assert(s_idx_174_1 == s_idx_174_2);
  assert(stage_v_174_1 == stage_v_174_2);
  assert(s_idx_175_1 == s_idx_175_2);
  assert(stage_v_175_1 == stage_v_175_2);
  assert(s_idx_176_1 == s_idx_176_2);
  assert(stage_v_176_1 == stage_v_176_2);
  assert(s_idx_177_1 == s_idx_177_2);
  assert(stage_v_177_1 == stage_v_177_2);
  assert(s_idx_178_1 == s_idx_178_2);
  assert(stage_v_178_1 == stage_v_178_2);
  assert(s_idx_179_1 == s_idx_179_2);
  assert(stage_v_179_1 == stage_v_179_2);
  assert(s_idx_180_1 == s_idx_180_2);
  assert(stage_v_180_1 == stage_v_180_2);
  assert(s_idx_181_1 == s_idx_181_2);
  assert(stage_v_181_1 == stage_v_181_2);
  assert(s_idx_182_1 == s_idx_182_2);
  assert(stage_v_182_1 == stage_v_182_2);
  assert(s_idx_183_1 == s_idx_183_2);
  assert(stage_v_183_1 == stage_v_183_2);
  assert(s_idx_184_1 == s_idx_184_2);
  assert(stage_v_184_1 == stage_v_184_2);
  assert(s_idx_185_1 == s_idx_185_2);
  assert(stage_v_185_1 == stage_v_185_2);
  assert(s_idx_186_1 == s_idx_186_2);
  assert(stage_v_186_1 == stage_v_186_2);
  assert(s_idx_187_1 == s_idx_187_2);
  assert(stage_v_187_1 == stage_v_187_2);
  assert(s_idx_188_1 == s_idx_188_2);
  assert(stage_v_188_1 == stage_v_188_2);
  assert(s_idx_189_1 == s_idx_189_2);
  assert(stage_v_189_1 == stage_v_189_2);
  assert(s_idx_190_1 == s_idx_190_2);
  assert(stage_v_190_1 == stage_v_190_2);
  assert(s_idx_191_1 == s_idx_191_2);
  assert(stage_v_191_1 == stage_v_191_2);
  assert(s_idx_192_1 == s_idx_192_2);
  assert(stage_v_192_1 == stage_v_192_2);
  assert(s_idx_193_1 == s_idx_193_2);
  assert(stage_v_193_1 == stage_v_193_2);
  assert(s_idx_194_1 == s_idx_194_2);
  assert(stage_v_194_1 == stage_v_194_2);
  assert(s_idx_195_1 == s_idx_195_2);
  assert(stage_v_195_1 == stage_v_195_2);
  assert(s_idx_196_1 == s_idx_196_2);
  assert(stage_v_196_1 == stage_v_196_2);
  assert(s_idx_197_1 == s_idx_197_2);
  assert(stage_v_197_1 == stage_v_197_2);
  assert(s_idx_198_1 == s_idx_198_2);
  assert(stage_v_198_1 == stage_v_198_2);
  assert(s_idx_199_1 == s_idx_199_2);
  assert(stage_v_199_1 == stage_v_199_2);
  assert(s_idx_200_1 == s_idx_200_2);
  assert(stage_v_200_1 == stage_v_200_2);
  assert(s_idx_201_1 == s_idx_201_2);
  assert(stage_v_201_1 == stage_v_201_2);
  assert(s_idx_202_1 == s_idx_202_2);
  assert(stage_v_202_1 == stage_v_202_2);
  assert(s_idx_203_1 == s_idx_203_2);
  assert(stage_v_203_1 == stage_v_203_2);
  assert(s_idx_204_1 == s_idx_204_2);
  assert(stage_v_204_1 == stage_v_204_2);
  assert(s_idx_205_1 == s_idx_205_2);
  assert(stage_v_205_1 == stage_v_205_2);
  assert(s_idx_206_1 == s_idx_206_2);
  assert(stage_v_206_1 == stage_v_206_2);
  assert(s_idx_207_1 == s_idx_207_2);
  assert(stage_v_207_1 == stage_v_207_2);
  assert(s_idx_208_1 == s_idx_208_2);
  assert(stage_v_208_1 == stage_v_208_2);
  assert(s_idx_209_1 == s_idx_209_2);
  assert(stage_v_209_1 == stage_v_209_2);
  assert(s_idx_210_1 == s_idx_210_2);
  assert(stage_v_210_1 == stage_v_210_2);
  assert(s_idx_211_1 == s_idx_211_2);
  assert(stage_v_211_1 == stage_v_211_2);
  assert(s_idx_212_1 == s_idx_212_2);
  assert(stage_v_212_1 == stage_v_212_2);
  assert(s_idx_213_1 == s_idx_213_2);
  assert(stage_v_213_1 == stage_v_213_2);
  assert(s_idx_214_1 == s_idx_214_2);
  assert(stage_v_214_1 == stage_v_214_2);
  assert(s_idx_215_1 == s_idx_215_2);
  assert(stage_v_215_1 == stage_v_215_2);
  assert(s_idx_216_1 == s_idx_216_2);
  assert(stage_v_216_1 == stage_v_216_2);
  assert(s_idx_217_1 == s_idx_217_2);
  assert(stage_v_217_1 == stage_v_217_2);
  assert(s_idx_218_1 == s_idx_218_2);
  assert(stage_v_218_1 == stage_v_218_2);
  assert(s_idx_219_1 == s_idx_219_2);
  assert(stage_v_219_1 == stage_v_219_2);
  assert(s_idx_220_1 == s_idx_220_2);
  assert(stage_v_220_1 == stage_v_220_2);
  assert(s_idx_221_1 == s_idx_221_2);
  assert(stage_v_221_1 == stage_v_221_2);
  assert(s_idx_222_1 == s_idx_222_2);
  assert(stage_v_222_1 == stage_v_222_2);
  assert(s_idx_223_1 == s_idx_223_2);
  assert(stage_v_223_1 == stage_v_223_2);
  assert(s_idx_224_1 == s_idx_224_2);
  assert(stage_v_224_1 == stage_v_224_2);
  assert(s_idx_225_1 == s_idx_225_2);
  assert(stage_v_225_1 == stage_v_225_2);
  assert(s_idx_226_1 == s_idx_226_2);
  assert(stage_v_226_1 == stage_v_226_2);
  assert(s_idx_227_1 == s_idx_227_2);
  assert(stage_v_227_1 == stage_v_227_2);
  assert(s_idx_228_1 == s_idx_228_2);
  assert(stage_v_228_1 == stage_v_228_2);
  assert(s_idx_229_1 == s_idx_229_2);
  assert(stage_v_229_1 == stage_v_229_2);
  assert(s_idx_230_1 == s_idx_230_2);
  assert(stage_v_230_1 == stage_v_230_2);
  assert(s_idx_231_1 == s_idx_231_2);
  assert(stage_v_231_1 == stage_v_231_2);
  assert(s_idx_232_1 == s_idx_232_2);
  assert(stage_v_232_1 == stage_v_232_2);
}


