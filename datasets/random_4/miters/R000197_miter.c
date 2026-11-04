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
struct AudioFrame_R000197_713_0
{
  unsigned char gain;
  int channels;
  short sample_rate;
  int buffer[3];
};
struct FilterState_R000197_713_1
{
  int mode;
  unsigned char gain_db;
  short prev_in;
  int cutoff;
  int damping;
  int prev_out;
  int buffer[3];
};
union TelemetryField_R000197_713_0
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
void fn_R000197_713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000197_713_1 st_1 = {0};
  struct FilterState_R000197_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_38_1 > 33)
  {
    acc_1 = ((acc_1 + (threshold_38_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_38_2 > 33)
  {
    acc_2 = ((acc_2 + (threshold_38_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_65_1 = 0;
  int phase_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_65_1 = ((phase_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_65_2 = ((phase_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_65_1) & 127;
    acc_2 = (acc_2 + phase_65_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_38_1 == threshold_38_2);
  assert(phase_65_1 == phase_65_2);
}

int fn_R000197_713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000197_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_38 > 33)
  {
    acc = ((acc + (threshold_38 * 2)) + 5) & 127;
    aux ^= threshold_38 & 15;
  }
  else
  {
    acc = ((acc - threshold_38) + 11) & 127;
    aux += 3;
  }
  int phase_65 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_65 = ((phase_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_65) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000197_713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000197_713_0 st_1 = {0};
  struct AudioFrame_R000197_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int tracker_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_38_1 > 49)
  {
    acc_1 = ((acc_1 + (tracker_38_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_38_2 > 49)
  {
    acc_2 = ((acc_2 + (tracker_38_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_38_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_22_1)
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

  switch (metric_22_2)
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

  int accumulator_73_1 = 0;
  int accumulator_73_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_73_1 = ((accumulator_73_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_73_2 = ((accumulator_73_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_73_1) & 127;
    acc_2 = (acc_2 + accumulator_73_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_38_1 == tracker_38_2);
  assert(metric_22_1 == metric_22_2);
  assert(accumulator_73_1 == accumulator_73_2);
}

int fn_R000197_713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000197_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int tracker_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_38 > 49)
  {
    acc = ((acc + (tracker_38 * 2)) + 5) & 127;
    aux ^= tracker_38 & 15;
  }
  else
  {
    acc = ((acc - tracker_38) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_22 = (aux + st.buffer[1]) & 3;
  switch (metric_22)
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

  int accumulator_73 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_73 = ((accumulator_73 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_73) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000197_713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000197_713_1 st_1 = {0};
  struct FilterState_R000197_713_1 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_34_1 = local_arr_1[aux_1 % 3];
  int quotient_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_34_2 * 2)) & 127;
  int accumulator_44_1 = 0;
  int accumulator_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_44_1 = ((accumulator_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_44_2 = ((accumulator_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_44_1) & 127;
    acc_2 = (acc_2 + accumulator_44_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_34_1 == quotient_34_2);
  assert(accumulator_44_1 == accumulator_44_2);
}

int fn_R000197_713_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000197_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quotient_34 = local_arr[aux % 3];
  acc = (acc + (quotient_34 * 2)) & 127;
  int accumulator_44 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_44 = ((accumulator_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_44) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000197_713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000197_713_0 st_1 = {0};
  struct AudioFrame_R000197_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_14_1)
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

  switch (threshold_14_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_14_1 == threshold_14_2);
}

int fn_R000197_713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000197_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_14 = (aux + st.buffer[1]) & 3;
  switch (threshold_14)
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

void fn_R000197_713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000197_713_1 st_1 = {0};
  struct FilterState_R000197_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int tracker_40_1 = 0;
  int tracker_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_40_1 = ((tracker_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_40_2 = ((tracker_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_40_1) & 127;
    acc_2 = (acc_2 + tracker_40_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_40_1 == tracker_40_2);
}

int fn_R000197_713_4(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000197_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int tracker_40 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_40 = ((tracker_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_40) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000197_713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000197_713_0 st_1 = {0};
  struct AudioFrame_R000197_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int tracker_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_57_1)
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

  switch (tracker_57_2)
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

  int accumulator_38_1 = 0;
  int accumulator_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_38_1 = ((accumulator_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_38_2 = ((accumulator_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_38_1) & 127;
    acc_2 = (acc_2 + accumulator_38_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_57_1 == tracker_57_2);
  assert(accumulator_38_1 == accumulator_38_2);
}

int fn_R000197_713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000197_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int tracker_57 = (aux + st.buffer[1]) & 3;
  switch (tracker_57)
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

  int accumulator_38 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_38 = ((accumulator_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_38) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000197_713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000197_713_1 st_1 = {0};
  struct FilterState_R000197_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_21_1 = local_arr_1[aux_1 % 3];
  int segment_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_21_2 * 2)) & 127;
  int mask_48_1 = 0;
  int mask_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_48_1 = ((mask_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_48_2 = ((mask_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_48_1) & 127;
    acc_2 = (acc_2 + mask_48_2) & 127;
  }

  int phase_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_54_1) & 63;
  aux_2 = (aux_2 + phase_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_21_1 == segment_21_2);
  assert(mask_48_1 == mask_48_2);
  assert(phase_54_1 == phase_54_2);
}

int fn_R000197_713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000197_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int segment_21 = local_arr[aux % 3];
  acc = (acc + (segment_21 * 2)) & 127;
  int mask_48 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_48 = ((mask_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_48) & 127;
  }

  int phase_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_54) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000197_713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000197_713_0 st_1 = {0};
  struct AudioFrame_R000197_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int residue_52_1 = 0;
  int residue_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_52_1 = ((residue_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_52_2 = ((residue_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_52_1) & 127;
    acc_2 = (acc_2 + residue_52_2) & 127;
  }

  int checksum_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_13_1) & 63;
  aux_2 = (aux_2 + checksum_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_52_1 == residue_52_2);
  assert(checksum_13_1 == checksum_13_2);
}

int fn_R000197_713_7(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000197_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int residue_52 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_52 = ((residue_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_52) & 127;
  }

  int checksum_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_13) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000197_713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000197_713_0 st_1 = {0};
  struct AudioFrame_R000197_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int damping_16_1 = 0;
  int damping_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_16_1 = ((damping_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_16_2 = ((damping_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_16_1) & 127;
    acc_2 = (acc_2 + damping_16_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_11_1) & 63;
  aux_2 = (aux_2 + stride_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_21_1 = local_arr_1[aux_1 % 3];
  int tracker_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_16_1 == damping_16_2);
  assert(stride_11_1 == stride_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_21_1 == tracker_21_2);
}

int fn_R000197_713_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000197_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int damping_16 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_16 = ((damping_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_16) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_11) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_21 = local_arr[aux % 3];
  acc = (acc + (tracker_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000197_713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000197_713_1 st_1 = {0};
  struct FilterState_R000197_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int checksum_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_46_1) & 63;
  aux_2 = (aux_2 + checksum_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_95_1)
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

  switch (margin_95_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_46_1 == checksum_46_2);
  assert(margin_95_1 == margin_95_2);
}

int fn_R000197_713_9(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000197_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int checksum_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_46) & 63;
  acc ^= aux;
  int margin_95 = (aux + st.buffer[1]) & 3;
  switch (margin_95)
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

void fn_R000197_713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000197_713_1 st_1 = {0};
  struct FilterState_R000197_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_59_1 = local_arr_1[aux_1 % 3];
  int accumulator_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_59_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_59_1 == accumulator_59_2);
}

int fn_R000197_713_10(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000197_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_59 = local_arr[aux % 3];
  acc = (acc + (accumulator_59 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000197_713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000197_713_0 st_1 = {0};
  struct AudioFrame_R000197_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int cursor_57_1 = 0;
  int cursor_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_57_1 = ((cursor_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_57_2 = ((cursor_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_57_1) & 127;
    acc_2 = (acc_2 + cursor_57_2) & 127;
  }

  int phase_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_41_1 > 25)
  {
    acc_1 = ((acc_1 + (phase_41_1 * 2)) + 5) & 127;
    aux_1 ^= phase_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_41_2 > 25)
  {
    acc_2 = ((acc_2 + (phase_41_2 * 2)) + 5) & 127;
    aux_2 ^= phase_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_21_1)
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

  switch (tally_21_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_57_1 == cursor_57_2);
  assert(phase_41_1 == phase_41_2);
  assert(tally_21_1 == tally_21_2);
}

int fn_R000197_713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000197_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int cursor_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_57 = ((cursor_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_57) & 127;
  }

  int phase_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_41 > 25)
  {
    acc = ((acc + (phase_41 * 2)) + 5) & 127;
    aux ^= phase_41 & 15;
  }
  else
  {
    acc = ((acc - phase_41) + 11) & 127;
    aux += 3;
  }
  int tally_21 = (aux + st.buffer[1]) & 3;
  switch (tally_21)
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

void fn_R000197_713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000197_713_1 st_1 = {0};
  struct FilterState_R000197_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int residue_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_89_1)
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

  switch (residue_89_2)
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

  int accumulator_57_1 = 0;
  int accumulator_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_57_1 = ((accumulator_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_57_2 = ((accumulator_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_57_1) & 127;
    acc_2 = (acc_2 + accumulator_57_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_89_1 == residue_89_2);
  assert(accumulator_57_1 == accumulator_57_2);
}

int fn_R000197_713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000197_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int residue_89 = (aux + st.buffer[1]) & 3;
  switch (residue_89)
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

  int accumulator_57 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_57 = ((accumulator_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_57) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000197_713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000197_713_1 st_1 = {0};
  struct FilterState_R000197_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int threshold_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_93_1)
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

  switch (threshold_93_2)
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
  int sample_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_58_1 > 23)
  {
    acc_1 = ((acc_1 + (sample_58_1 * 2)) + 5) & 127;
    aux_1 ^= sample_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_58_2 > 23)
  {
    acc_2 = ((acc_2 + (sample_58_2 * 2)) + 5) & 127;
    aux_2 ^= sample_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_93_1 == threshold_93_2);
  assert(sample_58_1 == sample_58_2);
}

int fn_R000197_713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000197_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int threshold_93 = (aux + st.buffer[1]) & 3;
  switch (threshold_93)
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
  int sample_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_58 > 23)
  {
    acc = ((acc + (sample_58 * 2)) + 5) & 127;
    aux ^= sample_58 & 15;
  }
  else
  {
    acc = ((acc - sample_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000197_0_1;
  int sec_r000197_0_2;
  int sec_r000197_1_1;
  int sec_r000197_1_2;
  int sec_r000197_2_1;
  int sec_r000197_2_2;
  int sec_r000197_3_1;
  int sec_r000197_3_2;
  int sec_r000197_4_1;
  int sec_r000197_4_2;
  int sec_r000197_5_1;
  int sec_r000197_5_2;
  int sec_r000197_6_1;
  int sec_r000197_6_2;
  int sec_r000197_7_1;
  int sec_r000197_7_2;
  int sec_r000197_8_1;
  int sec_r000197_8_2;
  int sec_r000197_9_1;
  int sec_r000197_9_2;
  int sec_r000197_10_1;
  int sec_r000197_10_2;
  int sec_r000197_11_1;
  int sec_r000197_11_2;
  int sec_r000197_12_1;
  int sec_r000197_12_2;
  int sec_r000197_13_1;
  int sec_r000197_13_2;
  int sec_r000197_14_1;
  int sec_r000197_14_2;
  int sec_r000197_15_1;
  int sec_r000197_15_2;
  int sec_r000197_16_1;
  int sec_r000197_16_2;
  int pub_r000197_0_1;
  int pub_r000197_0_2;
  int pub_r000197_1_1;
  int pub_r000197_1_2;
  int pub_r000197_2_1;
  int pub_r000197_2_2;
  int pub_r000197_3_1;
  int pub_r000197_3_2;
  int pub_r000197_4_1;
  int pub_r000197_4_2;
  int pub_r000197_5_1;
  int pub_r000197_5_2;
  int pub_r000197_6_1;
  int pub_r000197_6_2;
  int pub_r000197_7_1;
  int pub_r000197_7_2;
  int pub_r000197_8_1;
  int pub_r000197_8_2;
  int pub_r000197_9_1;
  int pub_r000197_9_2;
  int pub_r000197_10_1;
  int pub_r000197_10_2;
  int pub_r000197_11_1;
  int pub_r000197_11_2;
  int pub_r000197_12_1;
  int pub_r000197_12_2;
  int pub_r000197_13_1;
  int pub_r000197_13_2;
  int pub_r000197_14_1;
  int pub_r000197_14_2;
  int pub_r000197_15_1;
  int pub_r000197_15_2;
  int pub_r000197_16_1;
  int pub_r000197_16_2;
  int pub_r000197_17_1;
  int pub_r000197_17_2;
  int pub_r000197_18_1;
  int pub_r000197_18_2;
  int pub_r000197_19_1;
  int pub_r000197_19_2;
  int pub_r000197_20_1;
  int pub_r000197_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000197_0_1 >= (-100)) && (pub_r000197_0_1 <= 100));
  __CPROVER_assume((pub_r000197_0_2 >= (-100)) && (pub_r000197_0_2 <= 100));
  __CPROVER_assume((pub_r000197_1_1 >= (-100)) && (pub_r000197_1_1 <= 100));
  __CPROVER_assume((pub_r000197_1_2 >= (-100)) && (pub_r000197_1_2 <= 100));
  __CPROVER_assume((pub_r000197_2_1 >= (-100)) && (pub_r000197_2_1 <= 100));
  __CPROVER_assume((pub_r000197_2_2 >= (-100)) && (pub_r000197_2_2 <= 100));
  __CPROVER_assume((pub_r000197_3_1 >= (-100)) && (pub_r000197_3_1 <= 100));
  __CPROVER_assume((pub_r000197_3_2 >= (-100)) && (pub_r000197_3_2 <= 100));
  __CPROVER_assume((pub_r000197_4_1 >= (-100)) && (pub_r000197_4_1 <= 100));
  __CPROVER_assume((pub_r000197_4_2 >= (-100)) && (pub_r000197_4_2 <= 100));
  __CPROVER_assume((pub_r000197_5_1 >= (-100)) && (pub_r000197_5_1 <= 100));
  __CPROVER_assume((pub_r000197_5_2 >= (-100)) && (pub_r000197_5_2 <= 100));
  __CPROVER_assume((pub_r000197_6_1 >= (-100)) && (pub_r000197_6_1 <= 100));
  __CPROVER_assume((pub_r000197_6_2 >= (-100)) && (pub_r000197_6_2 <= 100));
  __CPROVER_assume((pub_r000197_7_1 >= (-100)) && (pub_r000197_7_1 <= 100));
  __CPROVER_assume((pub_r000197_7_2 >= (-100)) && (pub_r000197_7_2 <= 100));
  __CPROVER_assume((pub_r000197_8_1 >= (-100)) && (pub_r000197_8_1 <= 100));
  __CPROVER_assume((pub_r000197_8_2 >= (-100)) && (pub_r000197_8_2 <= 100));
  __CPROVER_assume((pub_r000197_9_1 >= (-100)) && (pub_r000197_9_1 <= 100));
  __CPROVER_assume((pub_r000197_9_2 >= (-100)) && (pub_r000197_9_2 <= 100));
  __CPROVER_assume((pub_r000197_10_1 >= (-100)) && (pub_r000197_10_1 <= 100));
  __CPROVER_assume((pub_r000197_10_2 >= (-100)) && (pub_r000197_10_2 <= 100));
  __CPROVER_assume((pub_r000197_11_1 >= (-100)) && (pub_r000197_11_1 <= 100));
  __CPROVER_assume((pub_r000197_11_2 >= (-100)) && (pub_r000197_11_2 <= 100));
  __CPROVER_assume((pub_r000197_12_1 >= (-100)) && (pub_r000197_12_1 <= 100));
  __CPROVER_assume((pub_r000197_12_2 >= (-100)) && (pub_r000197_12_2 <= 100));
  __CPROVER_assume((pub_r000197_13_1 >= (-100)) && (pub_r000197_13_1 <= 100));
  __CPROVER_assume((pub_r000197_13_2 >= (-100)) && (pub_r000197_13_2 <= 100));
  __CPROVER_assume((pub_r000197_14_1 >= (-100)) && (pub_r000197_14_1 <= 100));
  __CPROVER_assume((pub_r000197_14_2 >= (-100)) && (pub_r000197_14_2 <= 100));
  __CPROVER_assume((pub_r000197_15_1 >= (-100)) && (pub_r000197_15_1 <= 100));
  __CPROVER_assume((pub_r000197_15_2 >= (-100)) && (pub_r000197_15_2 <= 100));
  __CPROVER_assume((pub_r000197_16_1 >= (-100)) && (pub_r000197_16_1 <= 100));
  __CPROVER_assume((pub_r000197_16_2 >= (-100)) && (pub_r000197_16_2 <= 100));
  __CPROVER_assume((pub_r000197_17_1 >= (-100)) && (pub_r000197_17_1 <= 100));
  __CPROVER_assume((pub_r000197_17_2 >= (-100)) && (pub_r000197_17_2 <= 100));
  __CPROVER_assume((pub_r000197_18_1 >= (-100)) && (pub_r000197_18_1 <= 100));
  __CPROVER_assume((pub_r000197_18_2 >= (-100)) && (pub_r000197_18_2 <= 100));
  __CPROVER_assume((pub_r000197_19_1 >= (-100)) && (pub_r000197_19_1 <= 100));
  __CPROVER_assume((pub_r000197_19_2 >= (-100)) && (pub_r000197_19_2 <= 100));
  __CPROVER_assume((pub_r000197_20_1 >= (-100)) && (pub_r000197_20_1 <= 100));
  __CPROVER_assume((pub_r000197_20_2 >= (-100)) && (pub_r000197_20_2 <= 100));
  __CPROVER_assume((sec_r000197_0_1 >= 0) && (sec_r000197_0_1 <= 255));
  __CPROVER_assume((sec_r000197_0_2 >= 0) && (sec_r000197_0_2 <= 255));
  __CPROVER_assume((sec_r000197_1_1 >= 0) && (sec_r000197_1_1 <= 255));
  __CPROVER_assume((sec_r000197_1_2 >= 0) && (sec_r000197_1_2 <= 255));
  __CPROVER_assume((sec_r000197_2_1 >= 0) && (sec_r000197_2_1 <= 255));
  __CPROVER_assume((sec_r000197_2_2 >= 0) && (sec_r000197_2_2 <= 255));
  __CPROVER_assume((sec_r000197_3_1 >= 0) && (sec_r000197_3_1 <= 255));
  __CPROVER_assume((sec_r000197_3_2 >= 0) && (sec_r000197_3_2 <= 255));
  __CPROVER_assume((sec_r000197_4_1 >= 0) && (sec_r000197_4_1 <= 255));
  __CPROVER_assume((sec_r000197_4_2 >= 0) && (sec_r000197_4_2 <= 255));
  __CPROVER_assume((sec_r000197_5_1 >= 0) && (sec_r000197_5_1 <= 255));
  __CPROVER_assume((sec_r000197_5_2 >= 0) && (sec_r000197_5_2 <= 255));
  __CPROVER_assume((sec_r000197_6_1 >= 0) && (sec_r000197_6_1 <= 255));
  __CPROVER_assume((sec_r000197_6_2 >= 0) && (sec_r000197_6_2 <= 255));
  __CPROVER_assume((sec_r000197_7_1 >= 0) && (sec_r000197_7_1 <= 255));
  __CPROVER_assume((sec_r000197_7_2 >= 0) && (sec_r000197_7_2 <= 255));
  __CPROVER_assume((sec_r000197_8_1 >= 0) && (sec_r000197_8_1 <= 255));
  __CPROVER_assume((sec_r000197_8_2 >= 0) && (sec_r000197_8_2 <= 255));
  __CPROVER_assume((sec_r000197_9_1 >= 0) && (sec_r000197_9_1 <= 255));
  __CPROVER_assume((sec_r000197_9_2 >= 0) && (sec_r000197_9_2 <= 255));
  __CPROVER_assume((sec_r000197_10_1 >= 0) && (sec_r000197_10_1 <= 255));
  __CPROVER_assume((sec_r000197_10_2 >= 0) && (sec_r000197_10_2 <= 255));
  __CPROVER_assume((sec_r000197_11_1 >= 0) && (sec_r000197_11_1 <= 255));
  __CPROVER_assume((sec_r000197_11_2 >= 0) && (sec_r000197_11_2 <= 255));
  __CPROVER_assume((sec_r000197_12_1 >= 0) && (sec_r000197_12_1 <= 255));
  __CPROVER_assume((sec_r000197_12_2 >= 0) && (sec_r000197_12_2 <= 255));
  __CPROVER_assume((sec_r000197_13_1 >= 0) && (sec_r000197_13_1 <= 255));
  __CPROVER_assume((sec_r000197_13_2 >= 0) && (sec_r000197_13_2 <= 255));
  __CPROVER_assume((sec_r000197_14_1 >= 0) && (sec_r000197_14_1 <= 255));
  __CPROVER_assume((sec_r000197_14_2 >= 0) && (sec_r000197_14_2 <= 255));
  __CPROVER_assume((sec_r000197_15_1 >= 0) && (sec_r000197_15_1 <= 255));
  __CPROVER_assume((sec_r000197_15_2 >= 0) && (sec_r000197_15_2 <= 255));
  __CPROVER_assume((sec_r000197_16_1 >= 0) && (sec_r000197_16_1 <= 255));
  __CPROVER_assume((sec_r000197_16_2 >= 0) && (sec_r000197_16_2 <= 255));
  struct AudioFrame_R000197_713_0 st_var_0_1 = {0};
  struct AudioFrame_R000197_713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000197_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000197_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000197_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000197_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000197_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000197_0_2 + 7) & 15;
  struct FilterState_R000197_713_1 st_var_1_1 = {0};
  struct FilterState_R000197_713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000197_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000197_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000197_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000197_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000197_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000197_0_2 + 9) & 15;
  union TelemetryField_R000197_713_0 u_var_1;
  union TelemetryField_R000197_713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 32)
    {
      chk_sum_1 ^= stage_v_1_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_1_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 32)
    {
      chk_sum_2 ^= stage_v_1_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 47)
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
  if (stage_v_4_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 47)
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
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_6_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_6_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_6_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_7_1 = 0;
  int stage_v_7_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_7_1 = ((stage_v_7_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_7_2 = ((stage_v_7_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (st_var_0_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_0_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_9_1 = ((stage_v_9_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_9_2 = ((stage_v_9_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (st_var_0_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_0_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  int stage_v_11_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_11_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_11_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_11_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 13) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 13) & 15;
  int stage_v_12_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_12_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= stage_v_12_1;
  chk_sum_2 ^= stage_v_12_2;
  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
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

  switch (stage_v_13_2)
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

  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_15_1 = (st_var_1_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_1_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  int stage_v_16_1 = (st_var_0_1.buffer[0] ^ 19) & 3;
  int stage_v_16_2 = (st_var_0_2.buffer[0] ^ 19) & 3;
  switch (stage_v_16_1)
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

  switch (stage_v_16_2)
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

  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 19) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
  int stage_v_22_1 = table_1[2];
  int stage_v_22_2 = table_2[2];
  table_1[2] = (table_1[3] + 45) & 63;
  table_2[2] = (table_2[3] + 45) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = ((st_var_1_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_1_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 45)
    {
      chk_sum_1 ^= stage_v_23_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_23_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 45)
    {
      chk_sum_2 ^= stage_v_23_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_24_1 = ((st_var_0_1.buffer[0] * 2) + 79) & 63;
  int stage_v_24_2 = ((st_var_0_2.buffer[0] * 2) + 79) & 63;
  if (stage_v_24_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_24_1) - 5) & 255;
    if (stage_v_24_1 > 42)
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
  if (stage_v_24_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_24_2) - 5) & 255;
    if (stage_v_24_2 > 42)
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
  int stage_v_25_1 = table_1[1];
  int stage_v_25_2 = table_2[1];
  table_1[1] = (table_1[2] + 51) & 63;
  table_2[1] = (table_2[2] + 51) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_28_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
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
  int stage_v_34_1 = ((st_var_0_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_0_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 43)
    {
      chk_sum_1 ^= stage_v_34_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_34_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 43)
    {
      chk_sum_2 ^= stage_v_34_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = table_1[0];
  int stage_v_36_2 = table_2[0];
  table_1[0] = (table_1[1] + 73) & 63;
  table_2[0] = (table_2[1] + 73) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 45)
    {
      chk_sum_1 ^= stage_v_37_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_37_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 45)
    {
      chk_sum_2 ^= stage_v_37_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((st_var_1_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_1_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 30)
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
  if (stage_v_39_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 30)
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
  int stage_v_40_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (45 & 31);
  int stage_v_40_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (45 & 31);
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= (stage_v_40_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_40_2 << 1) & 127;
  int stage_v_41_1 = ((st_var_1_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_1_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 34)
    {
      chk_sum_1 ^= stage_v_41_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_41_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 34)
    {
      chk_sum_2 ^= stage_v_41_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_42_1 = ((st_var_0_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_0_2.buffer[0] * 2) + 133) & 63;
  if (stage_v_42_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 49)
    {
      chk_sum_1 ^= stage_v_42_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_42_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 49)
    {
      chk_sum_2 ^= stage_v_42_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 44) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 44) & 15;
  int stage_v_43_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_43_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= stage_v_43_1;
  chk_sum_2 ^= stage_v_43_2;
  int stage_v_44_1 = ((st_var_0_1.buffer[2] * 2) + 139) & 63;
  int stage_v_44_2 = ((st_var_0_2.buffer[2] * 2) + 139) & 63;
  if (stage_v_44_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_44_1) - 5) & 255;
    if (stage_v_44_1 > 29)
    {
      chk_sum_1 ^= stage_v_44_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_44_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_44_2) - 5) & 255;
    if (stage_v_44_2 > 29)
    {
      chk_sum_2 ^= stage_v_44_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_45_1 = (st_var_1_1.buffer[0] ^ 48) & 3;
  int stage_v_45_2 = (st_var_1_2.buffer[0] ^ 48) & 3;
  switch (stage_v_45_1)
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

  switch (stage_v_45_2)
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

  int stage_v_46_1 = (st_var_0_1.buffer[0] ^ 49) & 3;
  int stage_v_46_2 = (st_var_0_2.buffer[0] ^ 49) & 3;
  switch (stage_v_46_1)
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

  switch (stage_v_46_2)
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

  int stage_v_47_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (52 & 31);
  int stage_v_47_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (52 & 31);
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= (stage_v_47_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_47_2 << 1) & 127;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (st_var_1_1.buffer[0] ^ 52) & 3;
  int stage_v_49_2 = (st_var_1_2.buffer[0] ^ 52) & 3;
  switch (stage_v_49_1)
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

  switch (stage_v_49_2)
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

  int stage_v_50_1 = table_1[2];
  int stage_v_50_2 = table_2[2];
  table_1[2] = (table_1[3] + 101) & 63;
  table_2[2] = (table_2[3] + 101) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 52) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 52) & 15;
  int stage_v_51_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_51_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= stage_v_51_1;
  chk_sum_2 ^= stage_v_51_2;
  int stage_v_52_1 = (st_var_0_1.buffer[0] ^ 55) & 3;
  int stage_v_52_2 = (st_var_0_2.buffer[0] ^ 55) & 3;
  switch (stage_v_52_1)
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

  switch (stage_v_52_2)
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
  int stage_v_55_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_55_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_56_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (61 & 31);
  int stage_v_56_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (61 & 31);
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= (stage_v_56_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_56_2 << 1) & 127;
  int stage_v_57_1 = table_1[1];
  int stage_v_57_2 = table_2[1];
  table_1[1] = (table_1[2] + 115) & 63;
  table_2[1] = (table_2[2] + 115) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_58_1 = ((stage_v_58_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_58_2 = ((stage_v_58_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((st_var_1_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_1_2.buffer[2] * 2) + 184) & 63;
  if (stage_v_59_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 45)
    {
      chk_sum_1 ^= stage_v_59_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_59_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 45)
    {
      chk_sum_2 ^= stage_v_59_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_60_1 = ((stage_v_60_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_60_2 = ((stage_v_60_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = table_1[1];
  int stage_v_61_2 = table_2[1];
  table_1[1] = (table_1[2] + 123) & 63;
  table_2[1] = (table_2[2] + 123) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 63) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 63) & 15;
  int stage_v_62_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_62_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= stage_v_62_1;
  chk_sum_2 ^= stage_v_62_2;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_63_1 = ((stage_v_63_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_63_2 = ((stage_v_63_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_64_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_64_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_64_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_65_1 = table_1[1];
  int stage_v_65_2 = table_2[1];
  table_1[1] = (table_1[2] + 131) & 63;
  table_2[1] = (table_2[2] + 131) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = table_1[2];
  int stage_v_66_2 = table_2[2];
  table_1[2] = (table_1[3] + 133) & 63;
  table_2[2] = (table_2[3] + 133) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (72 & 31);
  int stage_v_67_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (72 & 31);
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= (stage_v_67_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_67_2 << 1) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 69) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 69) & 15;
  int stage_v_68_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_68_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= stage_v_68_1;
  chk_sum_2 ^= stage_v_68_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 70) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 70) & 15;
  int stage_v_69_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_69_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= stage_v_69_1;
  chk_sum_2 ^= stage_v_69_2;
  int stage_v_70_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_70_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_70_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_70_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_71_1 = (st_var_1_1.buffer[0] ^ 74) & 3;
  int stage_v_71_2 = (st_var_1_2.buffer[0] ^ 74) & 3;
  switch (stage_v_71_1)
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

  switch (stage_v_71_2)
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

  int stage_v_72_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_72_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_73_1 = ((stage_v_73_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_73_2 = ((stage_v_73_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (st_var_0_1.buffer[0] ^ 77) & 3;
  int stage_v_74_2 = (st_var_0_2.buffer[0] ^ 77) & 3;
  switch (stage_v_74_1)
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

  switch (stage_v_74_2)
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

  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_75_1 = ((stage_v_75_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_75_2 = ((stage_v_75_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_76_1 = ((stage_v_76_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_76_2 = ((stage_v_76_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
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
  int stage_v_78_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (83 & 31);
  int stage_v_78_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (83 & 31);
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  chk_sum_1 ^= (stage_v_78_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_78_2 << 1) & 127;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_79_1 = ((stage_v_79_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_79_2 = ((stage_v_79_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = table_1[0];
  int stage_v_80_2 = table_2[0];
  table_1[0] = (table_1[1] + 161) & 63;
  table_2[0] = (table_2[1] + 161) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((st_var_1_1.buffer[0] * 2) + 250) & 63;
  int stage_v_81_2 = ((st_var_1_2.buffer[0] * 2) + 250) & 63;
  if (stage_v_81_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_81_1) - 5) & 255;
    if (stage_v_81_1 > 41)
    {
      chk_sum_1 ^= stage_v_81_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_81_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_81_2) - 5) & 255;
    if (stage_v_81_2 > 41)
    {
      chk_sum_2 ^= stage_v_81_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_82_1 = ((st_var_0_1.buffer[1] * 2) + 253) & 63;
  int stage_v_82_2 = ((st_var_0_2.buffer[1] * 2) + 253) & 63;
  if (stage_v_82_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_82_1) - 5) & 255;
    if (stage_v_82_1 > 47)
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
  if (stage_v_82_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_82_2) - 5) & 255;
    if (stage_v_82_2 > 47)
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
  int stage_v_83_1 = ((st_var_1_1.buffer[2] * 2) + 256) & 63;
  int stage_v_83_2 = ((st_var_1_2.buffer[2] * 2) + 256) & 63;
  if (stage_v_83_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_83_1) - 5) & 255;
    if (stage_v_83_1 > 29)
    {
      chk_sum_1 ^= stage_v_83_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_83_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_83_2) - 5) & 255;
    if (stage_v_83_2 > 29)
    {
      chk_sum_2 ^= stage_v_83_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_84_1 = table_1[0];
  int stage_v_84_2 = table_2[0];
  table_1[0] = (table_1[1] + 169) & 63;
  table_2[0] = (table_2[1] + 169) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((st_var_1_1.buffer[1] * 2) + 262) & 63;
  int stage_v_85_2 = ((st_var_1_2.buffer[1] * 2) + 262) & 63;
  if (stage_v_85_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_85_1) - 5) & 255;
    if (stage_v_85_1 > 44)
    {
      chk_sum_1 ^= stage_v_85_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_85_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_85_2) - 5) & 255;
    if (stage_v_85_2 > 44)
    {
      chk_sum_2 ^= stage_v_85_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_86_1 = ((st_var_0_1.buffer[2] * 2) + 265) & 63;
  int stage_v_86_2 = ((st_var_0_2.buffer[2] * 2) + 265) & 63;
  if (stage_v_86_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_86_1) - 5) & 255;
    if (stage_v_86_1 > 45)
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
  if (stage_v_86_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_86_2) - 5) & 255;
    if (stage_v_86_2 > 45)
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
  int stage_v_87_1 = ((st_var_1_1.buffer[0] * 2) + 268) & 63;
  int stage_v_87_2 = ((st_var_1_2.buffer[0] * 2) + 268) & 63;
  if (stage_v_87_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_87_1) - 5) & 255;
    if (stage_v_87_1 > 43)
    {
      chk_sum_1 ^= stage_v_87_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_87_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_87_2) - 5) & 255;
    if (stage_v_87_2 > 43)
    {
      chk_sum_2 ^= stage_v_87_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_88_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (93 & 31);
  int stage_v_88_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (93 & 31);
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= (stage_v_88_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_88_2 << 1) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 90) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 90) & 15;
  int stage_v_89_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_89_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  chk_sum_1 ^= stage_v_89_1;
  chk_sum_2 ^= stage_v_89_2;
  int stage_v_90_1 = table_1[2];
  int stage_v_90_2 = table_2[2];
  table_1[2] = (table_1[3] + 181) & 63;
  table_2[2] = (table_2[3] + 181) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((st_var_1_1.buffer[1] * 2) + 280) & 63;
  int stage_v_91_2 = ((st_var_1_2.buffer[1] * 2) + 280) & 63;
  if (stage_v_91_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_91_1) - 5) & 255;
    if (stage_v_91_1 > 29)
    {
      chk_sum_1 ^= stage_v_91_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_91_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_91_2) - 5) & 255;
    if (stage_v_91_2 > 29)
    {
      chk_sum_2 ^= stage_v_91_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_92_1 = table_1[0];
  int stage_v_92_2 = table_2[0];
  table_1[0] = (table_1[1] + 185) & 63;
  table_2[0] = (table_2[1] + 185) & 63;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_93_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_93_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_93_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_94_1 = ((stage_v_94_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_94_2 = ((stage_v_94_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (100 & 31);
  int stage_v_95_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (100 & 31);
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  chk_sum_1 ^= (stage_v_95_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_95_2 << 1) & 127;
  int stage_v_96_1 = table_1[0];
  int stage_v_96_2 = table_2[0];
  table_1[0] = (table_1[1] + 193) & 63;
  table_2[0] = (table_2[1] + 193) & 63;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (102 & 31);
  int stage_v_97_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (102 & 31);
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  chk_sum_1 ^= (stage_v_97_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_97_2 << 1) & 127;
  int stage_v_98_1 = ((st_var_0_1.buffer[2] * 2) + 301) & 63;
  int stage_v_98_2 = ((st_var_0_2.buffer[2] * 2) + 301) & 63;
  if (stage_v_98_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_98_1) - 5) & 255;
    if (stage_v_98_1 > 47)
    {
      chk_sum_1 ^= stage_v_98_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_98_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_98_2) - 5) & 255;
    if (stage_v_98_2 > 47)
    {
      chk_sum_2 ^= stage_v_98_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_99_1 = (st_var_1_1.buffer[0] ^ 102) & 3;
  int stage_v_99_2 = (st_var_1_2.buffer[0] ^ 102) & 3;
  switch (stage_v_99_1)
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

  switch (stage_v_99_2)
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

  int stage_v_100_1 = ((st_var_0_1.buffer[1] * 2) + 307) & 63;
  int stage_v_100_2 = ((st_var_0_2.buffer[1] * 2) + 307) & 63;
  if (stage_v_100_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_100_1) - 5) & 255;
    if (stage_v_100_1 > 32)
    {
      chk_sum_1 ^= stage_v_100_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_100_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_100_2) - 5) & 255;
    if (stage_v_100_2 > 32)
    {
      chk_sum_2 ^= stage_v_100_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_101_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_101_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_101_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_101_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_102_1 = table_1[2];
  int stage_v_102_2 = table_2[2];
  table_1[2] = (table_1[3] + 205) & 63;
  table_2[2] = (table_2[3] + 205) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (108 & 31);
  int stage_v_103_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (108 & 31);
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  chk_sum_1 ^= (stage_v_103_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_103_2 << 1) & 127;
  int stage_v_104_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_104_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_104_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_104_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_105_1 = ((st_var_1_1.buffer[0] * 2) + 322) & 63;
  int stage_v_105_2 = ((st_var_1_2.buffer[0] * 2) + 322) & 63;
  if (stage_v_105_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_105_1) - 5) & 255;
    if (stage_v_105_1 > 51)
    {
      chk_sum_1 ^= stage_v_105_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_105_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_105_2) - 5) & 255;
    if (stage_v_105_2 > 51)
    {
      chk_sum_2 ^= stage_v_105_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_106_1 = ((stage_v_106_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_106_2 = ((stage_v_106_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_107_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_107_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_107_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_108_1 = (st_var_0_1.buffer[0] ^ 111) & 3;
  int stage_v_108_2 = (st_var_0_2.buffer[0] ^ 111) & 3;
  switch (stage_v_108_1)
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

  switch (stage_v_108_2)
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

  int stage_v_109_1 = (st_var_1_1.buffer[0] ^ 112) & 3;
  int stage_v_109_2 = (st_var_1_2.buffer[0] ^ 112) & 3;
  switch (stage_v_109_1)
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

  switch (stage_v_109_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 111) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 111) & 15;
  int stage_v_110_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_110_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  chk_sum_1 ^= stage_v_110_1;
  chk_sum_2 ^= stage_v_110_2;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_111_1 = ((stage_v_111_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_111_2 = ((stage_v_111_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 113) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 113) & 15;
  int stage_v_112_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_112_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  chk_sum_1 ^= stage_v_112_1;
  chk_sum_2 ^= stage_v_112_2;
  int stage_v_113_1 = ((st_var_1_1.buffer[2] * 2) + 346) & 63;
  int stage_v_113_2 = ((st_var_1_2.buffer[2] * 2) + 346) & 63;
  if (stage_v_113_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_113_1) - 5) & 255;
    if (stage_v_113_1 > 44)
    {
      chk_sum_1 ^= stage_v_113_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_113_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_113_2) - 5) & 255;
    if (stage_v_113_2 > 44)
    {
      chk_sum_2 ^= stage_v_113_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 115) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 115) & 15;
  int stage_v_114_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_114_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  chk_sum_1 ^= stage_v_114_1;
  chk_sum_2 ^= stage_v_114_2;
  int stage_v_115_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (120 & 31);
  int stage_v_115_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (120 & 31);
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  chk_sum_1 ^= (stage_v_115_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_115_2 << 1) & 127;
  int stage_v_116_1 = (st_var_0_1.buffer[0] ^ 119) & 3;
  int stage_v_116_2 = (st_var_0_2.buffer[0] ^ 119) & 3;
  switch (stage_v_116_1)
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

  switch (stage_v_116_2)
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

  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 118) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 118) & 15;
  int stage_v_117_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_117_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  chk_sum_1 ^= stage_v_117_1;
  chk_sum_2 ^= stage_v_117_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 119) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 119) & 15;
  int stage_v_118_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_118_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  chk_sum_1 ^= stage_v_118_1;
  chk_sum_2 ^= stage_v_118_2;
  int stage_v_119_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (124 & 31);
  int stage_v_119_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (124 & 31);
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  chk_sum_1 ^= (stage_v_119_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_119_2 << 1) & 127;
  int stage_v_120_1 = ((st_var_0_1.buffer[0] * 2) + 367) & 63;
  int stage_v_120_2 = ((st_var_0_2.buffer[0] * 2) + 367) & 63;
  if (stage_v_120_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_120_1) - 5) & 255;
    if (stage_v_120_1 > 41)
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
  if (stage_v_120_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_120_2) - 5) & 255;
    if (stage_v_120_2 > 41)
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
  int stage_v_122_1 = ((st_var_0_1.buffer[2] * 2) + 373) & 63;
  int stage_v_122_2 = ((st_var_0_2.buffer[2] * 2) + 373) & 63;
  if (stage_v_122_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_122_1) - 5) & 255;
    if (stage_v_122_1 > 36)
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
  if (stage_v_122_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_122_2) - 5) & 255;
    if (stage_v_122_2 > 36)
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
  int stage_v_123_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (128 & 31);
  int stage_v_123_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (128 & 31);
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  chk_sum_1 ^= (stage_v_123_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_123_2 << 1) & 127;
  int stage_v_124_1 = (st_var_0_1.buffer[0] ^ 127) & 3;
  int stage_v_124_2 = (st_var_0_2.buffer[0] ^ 127) & 3;
  switch (stage_v_124_1)
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

  switch (stage_v_124_2)
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

  int stage_v_125_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_125_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_125_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_125_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_126_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (131 & 31);
  int stage_v_126_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (131 & 31);
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  chk_sum_1 ^= (stage_v_126_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_126_2 << 1) & 127;
  int stage_v_127_1 = table_1[3];
  int stage_v_127_2 = table_2[3];
  table_1[3] = (table_1[0] + 255) & 63;
  table_2[3] = (table_2[0] + 255) & 63;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = table_1[0];
  int stage_v_128_2 = table_2[0];
  table_1[0] = (table_1[1] + 257) & 63;
  table_2[0] = (table_2[1] + 257) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (134 & 31);
  int stage_v_129_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (134 & 31);
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  chk_sum_1 ^= (stage_v_129_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_129_2 << 1) & 127;
  int stage_v_130_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (135 & 31);
  int stage_v_130_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (135 & 31);
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  chk_sum_1 ^= (stage_v_130_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_130_2 << 1) & 127;
  int stage_v_131_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_131_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_131_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_131_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_132_1 = (st_var_0_1.buffer[0] ^ 135) & 3;
  int stage_v_132_2 = (st_var_0_2.buffer[0] ^ 135) & 3;
  switch (stage_v_132_1)
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

  switch (stage_v_132_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 134) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 134) & 15;
  int stage_v_133_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_133_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  chk_sum_1 ^= stage_v_133_1;
  chk_sum_2 ^= stage_v_133_2;
  int stage_v_134_1 = ((st_var_0_1.buffer[2] * 2) + 409) & 63;
  int stage_v_134_2 = ((st_var_0_2.buffer[2] * 2) + 409) & 63;
  if (stage_v_134_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_134_1) - 5) & 255;
    if (stage_v_134_1 > 30)
    {
      chk_sum_1 ^= stage_v_134_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_134_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_134_2) - 5) & 255;
    if (stage_v_134_2 > 30)
    {
      chk_sum_2 ^= stage_v_134_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_135_1 = ((st_var_1_1.buffer[0] * 2) + 412) & 63;
  int stage_v_135_2 = ((st_var_1_2.buffer[0] * 2) + 412) & 63;
  if (stage_v_135_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_135_1) - 5) & 255;
    if (stage_v_135_1 > 25)
    {
      chk_sum_1 ^= stage_v_135_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_135_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_135_2) - 5) & 255;
    if (stage_v_135_2 > 25)
    {
      chk_sum_2 ^= stage_v_135_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_136_1 = (st_var_0_1.buffer[0] ^ 139) & 3;
  int stage_v_136_2 = (st_var_0_2.buffer[0] ^ 139) & 3;
  switch (stage_v_136_1)
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

  switch (stage_v_136_2)
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

  int stage_v_137_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_137_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_137_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_137_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_138_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_138_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_138_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_138_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_139_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_139_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_139_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_139_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_140_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_140_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_140_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_140_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_141_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (146 & 31);
  int stage_v_141_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (146 & 31);
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  chk_sum_1 ^= (stage_v_141_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_141_2 << 1) & 127;
  int stage_v_142_1 = table_1[2];
  int stage_v_142_2 = table_2[2];
  table_1[2] = (table_1[3] + 285) & 63;
  table_2[2] = (table_2[3] + 285) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((st_var_1_1.buffer[2] * 2) + 436) & 63;
  int stage_v_143_2 = ((st_var_1_2.buffer[2] * 2) + 436) & 63;
  if (stage_v_143_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_143_1) - 5) & 255;
    if (stage_v_143_1 > 34)
    {
      chk_sum_1 ^= stage_v_143_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_143_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_143_2) - 5) & 255;
    if (stage_v_143_2 > 34)
    {
      chk_sum_2 ^= stage_v_143_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_144_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_144_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_144_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_144_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_145_1 = table_1[1];
  int stage_v_145_2 = table_2[1];
  table_1[1] = (table_1[2] + 291) & 63;
  table_2[1] = (table_2[2] + 291) & 63;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((st_var_0_1.buffer[2] * 2) + 445) & 63;
  int stage_v_146_2 = ((st_var_0_2.buffer[2] * 2) + 445) & 63;
  if (stage_v_146_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_146_1) - 5) & 255;
    if (stage_v_146_1 > 43)
    {
      chk_sum_1 ^= stage_v_146_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_146_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_146_2) - 5) & 255;
    if (stage_v_146_2 > 43)
    {
      chk_sum_2 ^= stage_v_146_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_147_1 = table_1[3];
  int stage_v_147_2 = table_2[3];
  table_1[3] = (table_1[0] + 295) & 63;
  table_2[3] = (table_2[0] + 295) & 63;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 149) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 149) & 15;
  int stage_v_148_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_148_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  chk_sum_1 ^= stage_v_148_1;
  chk_sum_2 ^= stage_v_148_2;
  int stage_v_149_1 = ((st_var_1_1.buffer[2] * 2) + 454) & 63;
  int stage_v_149_2 = ((st_var_1_2.buffer[2] * 2) + 454) & 63;
  if (stage_v_149_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_149_1) - 5) & 255;
    if (stage_v_149_1 > 43)
    {
      chk_sum_1 ^= stage_v_149_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_149_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_149_2) - 5) & 255;
    if (stage_v_149_2 > 43)
    {
      chk_sum_2 ^= stage_v_149_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_150_1 = ((st_var_0_1.buffer[0] * 2) + 457) & 63;
  int stage_v_150_2 = ((st_var_0_2.buffer[0] * 2) + 457) & 63;
  if (stage_v_150_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_150_1) - 5) & 255;
    if (stage_v_150_1 > 25)
    {
      chk_sum_1 ^= stage_v_150_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_150_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_150_2) - 5) & 255;
    if (stage_v_150_2 > 25)
    {
      chk_sum_2 ^= stage_v_150_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_151_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (156 & 31);
  int stage_v_151_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (156 & 31);
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  chk_sum_1 ^= (stage_v_151_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_151_2 << 1) & 127;
  int stage_v_152_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_152_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_152_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_152_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_153_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (158 & 31);
  int stage_v_153_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (158 & 31);
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  chk_sum_1 ^= (stage_v_153_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_153_2 << 1) & 127;
  int stage_v_154_1 = ((st_var_0_1.buffer[1] * 2) + 469) & 63;
  int stage_v_154_2 = ((st_var_0_2.buffer[1] * 2) + 469) & 63;
  if (stage_v_154_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_154_1) - 5) & 255;
    if (stage_v_154_1 > 28)
    {
      chk_sum_1 ^= stage_v_154_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_154_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_154_2) - 5) & 255;
    if (stage_v_154_2 > 28)
    {
      chk_sum_2 ^= stage_v_154_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_155_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_155_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_155_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_155_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_156_1 = ((stage_v_156_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_156_2 = ((stage_v_156_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_157_1 = ((stage_v_157_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_157_2 = ((stage_v_157_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_158_1 = ((stage_v_158_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_158_2 = ((stage_v_158_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((st_var_1_1.buffer[0] * 2) + 484) & 63;
  int stage_v_159_2 = ((st_var_1_2.buffer[0] * 2) + 484) & 63;
  if (stage_v_159_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_159_1) - 5) & 255;
    if (stage_v_159_1 > 45)
    {
      chk_sum_1 ^= stage_v_159_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_159_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_159_2) - 5) & 255;
    if (stage_v_159_2 > 45)
    {
      chk_sum_2 ^= stage_v_159_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 161) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 161) & 15;
  int stage_v_160_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_160_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  chk_sum_1 ^= stage_v_160_1;
  chk_sum_2 ^= stage_v_160_2;
  int stage_v_161_1 = (st_var_1_1.buffer[0] ^ 164) & 3;
  int stage_v_161_2 = (st_var_1_2.buffer[0] ^ 164) & 3;
  switch (stage_v_161_1)
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

  switch (stage_v_161_2)
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
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_163_1 = ((stage_v_163_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_163_2 = ((stage_v_163_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_164_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_164_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_164_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_165_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_165_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_165_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_165_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_166_1 = (st_var_0_1.buffer[0] ^ 169) & 3;
  int stage_v_166_2 = (st_var_0_2.buffer[0] ^ 169) & 3;
  switch (stage_v_166_1)
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

  switch (stage_v_166_2)
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

  int stage_v_167_1 = (st_var_1_1.buffer[0] ^ 170) & 3;
  int stage_v_167_2 = (st_var_1_2.buffer[0] ^ 170) & 3;
  switch (stage_v_167_1)
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

  switch (stage_v_167_2)
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

  int stage_v_168_1 = 0;
  int stage_v_168_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_168_1 = ((stage_v_168_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_168_2 = ((stage_v_168_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((st_var_1_1.buffer[1] * 2) + 514) & 63;
  int stage_v_169_2 = ((st_var_1_2.buffer[1] * 2) + 514) & 63;
  if (stage_v_169_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_169_1) - 5) & 255;
    if (stage_v_169_1 > 45)
    {
      chk_sum_1 ^= stage_v_169_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_169_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_169_2) - 5) & 255;
    if (stage_v_169_2 > 45)
    {
      chk_sum_2 ^= stage_v_169_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 171) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 171) & 15;
  int stage_v_170_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_170_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  chk_sum_1 ^= stage_v_170_1;
  chk_sum_2 ^= stage_v_170_2;
  int stage_v_171_1 = (st_var_1_1.buffer[0] ^ 174) & 3;
  int stage_v_171_2 = (st_var_1_2.buffer[0] ^ 174) & 3;
  switch (stage_v_171_1)
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

  switch (stage_v_171_2)
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

  int stage_v_172_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_172_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_172_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_172_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_173_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (178 & 31);
  int stage_v_173_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (178 & 31);
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  chk_sum_1 ^= (stage_v_173_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_173_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 175) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 175) & 15;
  int stage_v_174_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_174_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  chk_sum_1 ^= stage_v_174_1;
  chk_sum_2 ^= stage_v_174_2;
  int stage_v_175_1 = table_1[3];
  int stage_v_175_2 = table_2[3];
  table_1[3] = (table_1[0] + 351) & 63;
  table_2[3] = (table_2[0] + 351) & 63;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 177) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 177) & 15;
  int stage_v_176_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_176_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  chk_sum_1 ^= stage_v_176_1;
  chk_sum_2 ^= stage_v_176_2;
  int stage_v_177_1 = 0;
  int stage_v_177_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_177_1 = ((stage_v_177_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_177_2 = ((stage_v_177_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (183 & 31);
  int stage_v_178_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (183 & 31);
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  chk_sum_1 ^= (stage_v_178_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_178_2 << 1) & 127;
  int stage_v_179_1 = 0;
  int stage_v_179_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_179_1 = ((stage_v_179_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_179_2 = ((stage_v_179_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = (st_var_0_1.buffer[0] ^ 183) & 3;
  int stage_v_180_2 = (st_var_0_2.buffer[0] ^ 183) & 3;
  switch (stage_v_180_1)
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

  switch (stage_v_180_2)
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

  int stage_v_181_1 = 0;
  int stage_v_181_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_181_1 = ((stage_v_181_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_181_2 = ((stage_v_181_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = 0;
  int stage_v_182_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_182_1 = ((stage_v_182_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_182_2 = ((stage_v_182_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (188 & 31);
  int stage_v_183_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (188 & 31);
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  chk_sum_1 ^= (stage_v_183_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_183_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 185) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 185) & 15;
  int stage_v_184_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_184_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  chk_sum_1 ^= stage_v_184_1;
  chk_sum_2 ^= stage_v_184_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 186) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 186) & 15;
  int stage_v_185_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_185_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  chk_sum_1 ^= stage_v_185_1;
  chk_sum_2 ^= stage_v_185_2;
  int stage_v_186_1 = ((st_var_0_1.buffer[0] * 2) + 565) & 63;
  int stage_v_186_2 = ((st_var_0_2.buffer[0] * 2) + 565) & 63;
  if (stage_v_186_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_186_1) - 5) & 255;
    if (stage_v_186_1 > 48)
    {
      chk_sum_1 ^= stage_v_186_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_186_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_186_2) - 5) & 255;
    if (stage_v_186_2 > 48)
    {
      chk_sum_2 ^= stage_v_186_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_187_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_187_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_187_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_187_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_188_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_188_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_188_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_188_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_189_1 = 0;
  int stage_v_189_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_189_1 = ((stage_v_189_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_189_2 = ((stage_v_189_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_190_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_190_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_190_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_191_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_191_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_191_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_191_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_192_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_192_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_192_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_192_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 194) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 194) & 15;
  int stage_v_193_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_193_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  chk_sum_1 ^= stage_v_193_1;
  chk_sum_2 ^= stage_v_193_2;
  int stage_v_194_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (199 & 31);
  int stage_v_194_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (199 & 31);
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  chk_sum_1 ^= (stage_v_194_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_194_2 << 1) & 127;
  int stage_v_195_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_195_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_195_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_195_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 197) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 197) & 15;
  int stage_v_196_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_196_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  chk_sum_1 ^= stage_v_196_1;
  chk_sum_2 ^= stage_v_196_2;
  int stage_v_197_1 = (st_var_1_1.buffer[0] ^ 200) & 3;
  int stage_v_197_2 = (st_var_1_2.buffer[0] ^ 200) & 3;
  switch (stage_v_197_1)
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

  switch (stage_v_197_2)
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

  int stage_v_198_1 = 0;
  int stage_v_198_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_198_1 = ((stage_v_198_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_198_2 = ((stage_v_198_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = 0;
  int stage_v_199_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_199_1 = ((stage_v_199_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_199_2 = ((stage_v_199_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = 0;
  int stage_v_200_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_200_1 = ((stage_v_200_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_200_2 = ((stage_v_200_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 202) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 202) & 15;
  int stage_v_201_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_201_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  chk_sum_1 ^= stage_v_201_1;
  chk_sum_2 ^= stage_v_201_2;
  int stage_v_202_1 = (st_var_0_1.buffer[0] ^ 205) & 3;
  int stage_v_202_2 = (st_var_0_2.buffer[0] ^ 205) & 3;
  switch (stage_v_202_1)
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

  switch (stage_v_202_2)
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

  int stage_v_203_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (208 & 31);
  int stage_v_203_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (208 & 31);
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  chk_sum_1 ^= (stage_v_203_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_203_2 << 1) & 127;
  int stage_v_204_1 = ((st_var_0_1.buffer[0] * 2) + 619) & 63;
  int stage_v_204_2 = ((st_var_0_2.buffer[0] * 2) + 619) & 63;
  if (stage_v_204_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_204_1) - 5) & 255;
    if (stage_v_204_1 > 47)
    {
      chk_sum_1 ^= stage_v_204_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_204_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_204_2) - 5) & 255;
    if (stage_v_204_2 > 47)
    {
      chk_sum_2 ^= stage_v_204_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 206) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 206) & 15;
  int stage_v_205_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_205_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  chk_sum_1 ^= stage_v_205_1;
  chk_sum_2 ^= stage_v_205_2;
  out_sink_1 += ((sec_r000197_2_1 * 3) + (sec_r000197_3_1 * 2)) & 255;
  out_sink_2 += ((sec_r000197_2_2 * 3) + (sec_r000197_3_2 * 2)) & 255;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000197_16_1 != sec_r000197_16_2);
  __CPROVER_assume(sec_r000197_7_1 != sec_r000197_7_2);
  __CPROVER_assume(sec_r000197_15_1 != sec_r000197_15_2);
  __CPROVER_assume(pub_r000197_8_1 == pub_r000197_8_2);
  __CPROVER_assume(pub_r000197_6_1 == pub_r000197_6_2);
  __CPROVER_assume(sec_r000197_0_1 != sec_r000197_0_2);
  __CPROVER_assume(pub_r000197_5_1 == pub_r000197_5_2);
  __CPROVER_assume(sec_r000197_4_1 != sec_r000197_4_2);
  __CPROVER_assume(pub_r000197_14_1 == pub_r000197_14_2);
  __CPROVER_assume(pub_r000197_17_1 == pub_r000197_17_2);
  __CPROVER_assume(pub_r000197_19_1 == pub_r000197_19_2);
  __CPROVER_assume(sec_r000197_5_1 != sec_r000197_5_2);
  __CPROVER_assume(sec_r000197_3_1 != sec_r000197_3_2);
  __CPROVER_assume(sec_r000197_9_1 != sec_r000197_9_2);
  __CPROVER_assume(pub_r000197_16_1 == pub_r000197_16_2);
  __CPROVER_assume(pub_r000197_0_1 == pub_r000197_0_2);
  __CPROVER_assume(sec_r000197_2_1 != sec_r000197_2_2);
  __CPROVER_assume(sec_r000197_11_1 != sec_r000197_11_2);
  __CPROVER_assume(sec_r000197_13_1 != sec_r000197_13_2);
  __CPROVER_assume(pub_r000197_20_1 == pub_r000197_20_2);
  __CPROVER_assume(pub_r000197_15_1 == pub_r000197_15_2);
  __CPROVER_assume(sec_r000197_14_1 != sec_r000197_14_2);
  __CPROVER_assume(pub_r000197_18_1 == pub_r000197_18_2);
  __CPROVER_assume(sec_r000197_1_1 != sec_r000197_1_2);
  __CPROVER_assume(pub_r000197_12_1 == pub_r000197_12_2);
  __CPROVER_assume(pub_r000197_10_1 == pub_r000197_10_2);
  __CPROVER_assume(sec_r000197_6_1 != sec_r000197_6_2);
  __CPROVER_assume(sec_r000197_10_1 != sec_r000197_10_2);
  __CPROVER_assume(pub_r000197_9_1 == pub_r000197_9_2);
  __CPROVER_assume(pub_r000197_7_1 == pub_r000197_7_2);
  __CPROVER_assume(pub_r000197_11_1 == pub_r000197_11_2);
  __CPROVER_assume(pub_r000197_13_1 == pub_r000197_13_2);
  __CPROVER_assume(sec_r000197_8_1 != sec_r000197_8_2);
  __CPROVER_assume(pub_r000197_3_1 == pub_r000197_3_2);
  __CPROVER_assume(pub_r000197_4_1 == pub_r000197_4_2);
  __CPROVER_assume(sec_r000197_12_1 != sec_r000197_12_2);
  __CPROVER_assume(pub_r000197_2_1 == pub_r000197_2_2);
  __CPROVER_assume(pub_r000197_1_1 == pub_r000197_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.mode == st_var_1_2.mode);
  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
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
}


