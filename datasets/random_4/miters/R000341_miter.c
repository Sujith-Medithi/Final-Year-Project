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
struct AudioFrame_R000341_4113_0
{
  unsigned char channels;
  int gain;
  short rms;
  short sample_rate;
  int envelope;
  int peak;
  int buffer[3];
};
struct CipherContext_R000341_4113_1
{
  unsigned char tag;
  int nonce;
  short round_key;
  int flags;
  unsigned char counter;
  int buffer[3];
};
struct FilterState_R000341_4113_2
{
  short cutoff;
  short prev_out;
  int gain_db;
  int mode;
  int prev_in;
  int buffer[3];
};
struct SensorNode_R000341_4113_3
{
  int status;
  int calib;
  short threshold;
  short gain;
  int buffer[3];
};
union TelemetryField_R000341_4113_0
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
void fn_R000341_4113_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000341_4113_3 st_1 = {0};
  struct SensorNode_R000341_4113_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_69_1 = local_arr_1[aux_1 % 3];
  int weight_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_69_2 * 2)) & 127;
  int accumulator_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_27_1 > 15)
  {
    acc_1 = ((acc_1 + (accumulator_27_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_27_2 > 15)
  {
    acc_2 = ((acc_2 + (accumulator_27_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_27_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_69_1 == weight_69_2);
  assert(accumulator_27_1 == accumulator_27_2);
}

int fn_R000341_4113_0(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000341_4113_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int weight_69 = local_arr[aux % 3];
  acc = (acc + (weight_69 * 2)) & 127;
  int accumulator_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_27 > 15)
  {
    acc = ((acc + (accumulator_27 * 2)) + 5) & 127;
    aux ^= accumulator_27 & 15;
  }
  else
  {
    acc = ((acc - accumulator_27) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000341_4113_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000341_4113_2 st_1 = {0};
  struct FilterState_R000341_4113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int quotient_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_40_1)
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

  switch (quotient_40_2)
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
  int window_67_1 = local_arr_1[aux_1 % 3];
  int window_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_67_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_40_1 == quotient_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_67_1 == window_67_2);
}

int fn_R000341_4113_1(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000341_4113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int quotient_40 = (aux + st.buffer[1]) & 3;
  switch (quotient_40)
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
  int window_67 = local_arr[aux % 3];
  acc = (acc + (window_67 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000341_4113_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000341_4113_0 st_1 = {0};
  struct AudioFrame_R000341_4113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int metric_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_93_1)
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

  switch (metric_93_2)
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

  int threshold_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_76_1 > 15)
  {
    acc_1 = ((acc_1 + (threshold_76_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_76_2 > 15)
  {
    acc_2 = ((acc_2 + (threshold_76_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_30_1 = local_arr_1[aux_1 % 3];
  int window_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_30_2 * 2)) & 127;
  int tally_56_1 = 0;
  int tally_56_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_56_1 = ((tally_56_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_56_2 = ((tally_56_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_56_1) & 127;
    acc_2 = (acc_2 + tally_56_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_93_1 == metric_93_2);
  assert(threshold_76_1 == threshold_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_30_1 == window_30_2);
  assert(tally_56_1 == tally_56_2);
}

int fn_R000341_4113_2(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000341_4113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int metric_93 = (aux + st.buffer[1]) & 3;
  switch (metric_93)
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

  int threshold_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_76 > 15)
  {
    acc = ((acc + (threshold_76 * 2)) + 5) & 127;
    aux ^= threshold_76 & 15;
  }
  else
  {
    acc = ((acc - threshold_76) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_30 = local_arr[aux % 3];
  acc = (acc + (window_30 * 2)) & 127;
  int tally_56 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_56 = ((tally_56 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_56) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000341_4113_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000341_4113_0 st_1 = {0};
  struct AudioFrame_R000341_4113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_85_1) & 63;
  aux_2 = (aux_2 + coefficient_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_90_1 = 0;
  int mask_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_90_1 = ((mask_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_90_2 = ((mask_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_90_1) & 127;
    acc_2 = (acc_2 + mask_90_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_85_1 == coefficient_85_2);
  assert(mask_90_1 == mask_90_2);
}

int fn_R000341_4113_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000341_4113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_85) & 63;
  acc ^= aux;
  int mask_90 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_90 = ((mask_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_90) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000341_4113_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000341_4113_2 st_1 = {0};
  struct FilterState_R000341_4113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int weight_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_82_1 > 26)
  {
    acc_1 = ((acc_1 + (weight_82_1 * 2)) + 5) & 127;
    aux_1 ^= weight_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_82_2 > 26)
  {
    acc_2 = ((acc_2 + (weight_82_2 * 2)) + 5) & 127;
    aux_2 ^= weight_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_82_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_65_1 = 0;
  int residue_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_65_1 = ((residue_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_65_2 = ((residue_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_65_1) & 127;
    acc_2 = (acc_2 + residue_65_2) & 127;
  }

  int accumulator_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_93_1)
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

  switch (accumulator_93_2)
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
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_82_1 == weight_82_2);
  assert(residue_65_1 == residue_65_2);
  assert(accumulator_93_1 == accumulator_93_2);
}

int fn_R000341_4113_4(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000341_4113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int weight_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_82 > 26)
  {
    acc = ((acc + (weight_82 * 2)) + 5) & 127;
    aux ^= weight_82 & 15;
  }
  else
  {
    acc = ((acc - weight_82) + 11) & 127;
    aux += 3;
  }
  int residue_65 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_65 = ((residue_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_65) & 127;
  }

  int accumulator_93 = (aux + st.buffer[1]) & 3;
  switch (accumulator_93)
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

void fn_R000341_4113_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000341_4113_0 st_1 = {0};
  struct AudioFrame_R000341_4113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_46_1 = local_arr_1[aux_1 % 3];
  int stride_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_46_2 * 2)) & 127;
  int mask_93_1 = 0;
  int mask_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_93_1 = ((mask_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_93_2 = ((mask_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_93_1) & 127;
    acc_2 = (acc_2 + mask_93_2) & 127;
  }

  int cursor_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_16_1) & 63;
  aux_2 = (aux_2 + cursor_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_46_1 == stride_46_2);
  assert(mask_93_1 == mask_93_2);
  assert(cursor_16_1 == cursor_16_2);
}

int fn_R000341_4113_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000341_4113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int stride_46 = local_arr[aux % 3];
  acc = (acc + (stride_46 * 2)) & 127;
  int mask_93 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_93 = ((mask_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_93) & 127;
  }

  int cursor_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_16) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000341_4113_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000341_4113_3 st_1 = {0};
  struct SensorNode_R000341_4113_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_62_1 = local_arr_1[aux_1 % 3];
  int tracker_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_62_2 * 2)) & 127;
  int factor_21_1 = 0;
  int factor_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_21_1 = ((factor_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_21_2 = ((factor_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_21_1) & 127;
    acc_2 = (acc_2 + factor_21_2) & 127;
  }

  int sample_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_22_1) & 63;
  aux_2 = (aux_2 + sample_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_62_1 == tracker_62_2);
  assert(factor_21_1 == factor_21_2);
  assert(sample_22_1 == sample_22_2);
}

int fn_R000341_4113_6(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000341_4113_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int tracker_62 = local_arr[aux % 3];
  acc = (acc + (tracker_62 * 2)) & 127;
  int factor_21 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_21 = ((factor_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_21) & 127;
  }

  int sample_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_22) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000341_4113_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000341_4113_1 st_1 = {0};
  struct CipherContext_R000341_4113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int checksum_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_36_1)
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

  switch (checksum_36_2)
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

  int parity_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_97_1) & 63;
  aux_2 = (aux_2 + parity_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_36_1 == checksum_36_2);
  assert(parity_97_1 == parity_97_2);
}

int fn_R000341_4113_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000341_4113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int checksum_36 = (aux + st.buffer[1]) & 3;
  switch (checksum_36)
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

  int parity_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000341_4113_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000341_4113_2 st_1 = {0};
  struct FilterState_R000341_4113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_82_1 = local_arr_1[aux_1 % 3];
  int window_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_82_2 * 2)) & 127;
  int bound_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_62_1)
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

  switch (bound_62_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_82_1 == window_82_2);
  assert(bound_62_1 == bound_62_2);
}

int fn_R000341_4113_8(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000341_4113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int window_82 = local_arr[aux % 3];
  acc = (acc + (window_82 * 2)) & 127;
  int bound_62 = (aux + st.buffer[1]) & 3;
  switch (bound_62)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000341_4113_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000341_4113_0 st_1 = {0};
  struct AudioFrame_R000341_4113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int stride_90_1 = 0;
  int stride_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_90_1 = ((stride_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_90_2 = ((stride_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_90_1) & 127;
    acc_2 = (acc_2 + stride_90_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_26_1) & 63;
  aux_2 = (aux_2 + residue_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_63_1 = local_arr_1[aux_1 % 3];
  int quotient_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_63_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_90_1 == stride_90_2);
  assert(residue_26_1 == residue_26_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_63_1 == quotient_63_2);
}

int fn_R000341_4113_9(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000341_4113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int stride_90 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_90 = ((stride_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_90) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_26) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_63 = local_arr[aux % 3];
  acc = (acc + (quotient_63 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000341_4113_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000341_4113_3 st_1 = {0};
  struct SensorNode_R000341_4113_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int weight_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_56_1 > 11)
  {
    acc_1 = ((acc_1 + (weight_56_1 * 2)) + 5) & 127;
    aux_1 ^= weight_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_56_2 > 11)
  {
    acc_2 = ((acc_2 + (weight_56_2 * 2)) + 5) & 127;
    aux_2 ^= weight_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_56_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_15_1)
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

  switch (weight_15_2)
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

  int window_17_1 = 0;
  int window_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_17_1 = ((window_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_17_2 = ((window_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_17_1) & 127;
    acc_2 = (acc_2 + window_17_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_56_1 == weight_56_2);
  assert(weight_15_1 == weight_15_2);
  assert(window_17_1 == window_17_2);
}

int fn_R000341_4113_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000341_4113_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int weight_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_56 > 11)
  {
    acc = ((acc + (weight_56 * 2)) + 5) & 127;
    aux ^= weight_56 & 15;
  }
  else
  {
    acc = ((acc - weight_56) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_15 = (aux + st.buffer[1]) & 3;
  switch (weight_15)
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

  int window_17 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_17 = ((window_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_17) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000341_4113_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000341_4113_1 st_1 = {0};
  struct CipherContext_R000341_4113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int sample_86_1 = 0;
  int sample_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_86_1 = ((sample_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_86_2 = ((sample_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_86_1) & 127;
    acc_2 = (acc_2 + sample_86_2) & 127;
  }

  int tally_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_85_1)
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

  switch (tally_85_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_86_1 == sample_86_2);
  assert(tally_85_1 == tally_85_2);
}

int fn_R000341_4113_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000341_4113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int sample_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_86 = ((sample_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_86) & 127;
  }

  int tally_85 = (aux + st.buffer[1]) & 3;
  switch (tally_85)
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

void fn_R000341_4113_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000341_4113_0 st_1 = {0};
  struct AudioFrame_R000341_4113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_56_1 = local_arr_1[aux_1 % 3];
  int offset_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_56_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_56_1 == offset_56_2);
}

int fn_R000341_4113_12(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000341_4113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int offset_56 = local_arr[aux % 3];
  acc = (acc + (offset_56 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000341_4113_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000341_4113_3 st_1 = {0};
  struct SensorNode_R000341_4113_3 st_2 = {0};
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
  int sample_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_70_1)
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

  switch (sample_70_2)
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

  int vector_46_1 = 0;
  int vector_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_46_1 = ((vector_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_46_2 = ((vector_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_46_1) & 127;
    acc_2 = (acc_2 + vector_46_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_70_1 == sample_70_2);
  assert(vector_46_1 == vector_46_2);
}

int fn_R000341_4113_13(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000341_4113_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_70 = (aux + st.buffer[1]) & 3;
  switch (sample_70)
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

  int vector_46 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_46 = ((vector_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_46) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000341_4113_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000341_4113_1 st_1 = {0};
  struct CipherContext_R000341_4113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int checksum_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_91_1) & 63;
  aux_2 = (aux_2 + checksum_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_32_1 > 32)
  {
    acc_1 = ((acc_1 + (stride_32_1 * 2)) + 5) & 127;
    aux_1 ^= stride_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_32_2 > 32)
  {
    acc_2 = ((acc_2 + (stride_32_2 * 2)) + 5) & 127;
    aux_2 ^= stride_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_32_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_91_1 == checksum_91_2);
  assert(stride_32_1 == stride_32_2);
}

int fn_R000341_4113_14(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000341_4113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int checksum_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_91) & 63;
  acc ^= aux;
  int stride_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_32 > 32)
  {
    acc = ((acc + (stride_32 * 2)) + 5) & 127;
    aux ^= stride_32 & 15;
  }
  else
  {
    acc = ((acc - stride_32) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000341_4113_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000341_4113_2 st_1 = {0};
  struct FilterState_R000341_4113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int segment_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_66_1)
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

  switch (segment_66_2)
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

  int damping_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_15_1) & 63;
  aux_2 = (aux_2 + damping_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_66_1 == segment_66_2);
  assert(damping_15_1 == damping_15_2);
}

int fn_R000341_4113_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000341_4113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int segment_66 = (aux + st.buffer[1]) & 3;
  switch (segment_66)
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

  int damping_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_15) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000341_4113_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000341_4113_1 st_1 = {0};
  struct CipherContext_R000341_4113_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int phase_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_18_1 > 15)
  {
    acc_1 = ((acc_1 + (phase_18_1 * 2)) + 5) & 127;
    aux_1 ^= phase_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_18_2 > 15)
  {
    acc_2 = ((acc_2 + (phase_18_2 * 2)) + 5) & 127;
    aux_2 ^= phase_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_98_1 = local_arr_1[aux_1 % 3];
  int window_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_98_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_18_1 == phase_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_98_1 == window_98_2);
}

int fn_R000341_4113_16(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000341_4113_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int phase_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_18 > 15)
  {
    acc = ((acc + (phase_18 * 2)) + 5) & 127;
    aux ^= phase_18 & 15;
  }
  else
  {
    acc = ((acc - phase_18) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_98 = local_arr[aux % 3];
  acc = (acc + (window_98 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000341_4113_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000341_4113_2 st_1 = {0};
  struct FilterState_R000341_4113_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_47_1 = local_arr_1[aux_1 % 3];
  int damping_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_47_2 * 2)) & 127;
  int window_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_48_1)
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

  switch (window_48_2)
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

  int offset_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_56_1) & 63;
  aux_2 = (aux_2 + offset_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_47_1 == damping_47_2);
  assert(window_48_1 == window_48_2);
  assert(offset_56_1 == offset_56_2);
}

int fn_R000341_4113_17(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000341_4113_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int damping_47 = local_arr[aux % 3];
  acc = (acc + (damping_47 * 2)) & 127;
  int window_48 = (aux + st.buffer[1]) & 3;
  switch (window_48)
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

  int offset_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_56) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000341_4113_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000341_4113_0 st_1 = {0};
  struct AudioFrame_R000341_4113_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int offset_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_82_1 > 20)
  {
    acc_1 = ((acc_1 + (offset_82_1 * 2)) + 5) & 127;
    aux_1 ^= offset_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_82_2 > 20)
  {
    acc_2 = ((acc_2 + (offset_82_2 * 2)) + 5) & 127;
    aux_2 ^= offset_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_82_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_82_1 == offset_82_2);
}

int fn_R000341_4113_18(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000341_4113_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int offset_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_82 > 20)
  {
    acc = ((acc + (offset_82 * 2)) + 5) & 127;
    aux ^= offset_82 & 15;
  }
  else
  {
    acc = ((acc - offset_82) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000341_4113_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000341_4113_3 st_1 = {0};
  struct SensorNode_R000341_4113_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int coefficient_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_87_1) & 63;
  aux_2 = (aux_2 + coefficient_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_87_1 == coefficient_87_2);
}

int fn_R000341_4113_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000341_4113_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int coefficient_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_87) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000341_0_1;
  int sec_r000341_0_2;
  int sec_r000341_1_1;
  int sec_r000341_1_2;
  int sec_r000341_2_1;
  int sec_r000341_2_2;
  int sec_r000341_3_1;
  int sec_r000341_3_2;
  int sec_r000341_4_1;
  int sec_r000341_4_2;
  int sec_r000341_5_1;
  int sec_r000341_5_2;
  int sec_r000341_6_1;
  int sec_r000341_6_2;
  int sec_r000341_7_1;
  int sec_r000341_7_2;
  int sec_r000341_8_1;
  int sec_r000341_8_2;
  int sec_r000341_9_1;
  int sec_r000341_9_2;
  int sec_r000341_10_1;
  int sec_r000341_10_2;
  int sec_r000341_11_1;
  int sec_r000341_11_2;
  int sec_r000341_12_1;
  int sec_r000341_12_2;
  int sec_r000341_13_1;
  int sec_r000341_13_2;
  int sec_r000341_14_1;
  int sec_r000341_14_2;
  int sec_r000341_15_1;
  int sec_r000341_15_2;
  int sec_r000341_16_1;
  int sec_r000341_16_2;
  int sec_r000341_17_1;
  int sec_r000341_17_2;
  int sec_r000341_18_1;
  int sec_r000341_18_2;
  int sec_r000341_19_1;
  int sec_r000341_19_2;
  int sec_r000341_20_1;
  int sec_r000341_20_2;
  int sec_r000341_21_1;
  int sec_r000341_21_2;
  int pub_r000341_0_1;
  int pub_r000341_0_2;
  int pub_r000341_1_1;
  int pub_r000341_1_2;
  int pub_r000341_2_1;
  int pub_r000341_2_2;
  int pub_r000341_3_1;
  int pub_r000341_3_2;
  int pub_r000341_4_1;
  int pub_r000341_4_2;
  int pub_r000341_5_1;
  int pub_r000341_5_2;
  int pub_r000341_6_1;
  int pub_r000341_6_2;
  int pub_r000341_7_1;
  int pub_r000341_7_2;
  int pub_r000341_8_1;
  int pub_r000341_8_2;
  int pub_r000341_9_1;
  int pub_r000341_9_2;
  int pub_r000341_10_1;
  int pub_r000341_10_2;
  int pub_r000341_11_1;
  int pub_r000341_11_2;
  int pub_r000341_12_1;
  int pub_r000341_12_2;
  int pub_r000341_13_1;
  int pub_r000341_13_2;
  int pub_r000341_14_1;
  int pub_r000341_14_2;
  int pub_r000341_15_1;
  int pub_r000341_15_2;
  int pub_r000341_16_1;
  int pub_r000341_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000341_0_1 >= (-100)) && (pub_r000341_0_1 <= 100));
  __CPROVER_assume((pub_r000341_0_2 >= (-100)) && (pub_r000341_0_2 <= 100));
  __CPROVER_assume((pub_r000341_1_1 >= (-100)) && (pub_r000341_1_1 <= 100));
  __CPROVER_assume((pub_r000341_1_2 >= (-100)) && (pub_r000341_1_2 <= 100));
  __CPROVER_assume((pub_r000341_2_1 >= (-100)) && (pub_r000341_2_1 <= 100));
  __CPROVER_assume((pub_r000341_2_2 >= (-100)) && (pub_r000341_2_2 <= 100));
  __CPROVER_assume((pub_r000341_3_1 >= (-100)) && (pub_r000341_3_1 <= 100));
  __CPROVER_assume((pub_r000341_3_2 >= (-100)) && (pub_r000341_3_2 <= 100));
  __CPROVER_assume((pub_r000341_4_1 >= (-100)) && (pub_r000341_4_1 <= 100));
  __CPROVER_assume((pub_r000341_4_2 >= (-100)) && (pub_r000341_4_2 <= 100));
  __CPROVER_assume((pub_r000341_5_1 >= (-100)) && (pub_r000341_5_1 <= 100));
  __CPROVER_assume((pub_r000341_5_2 >= (-100)) && (pub_r000341_5_2 <= 100));
  __CPROVER_assume((pub_r000341_6_1 >= (-100)) && (pub_r000341_6_1 <= 100));
  __CPROVER_assume((pub_r000341_6_2 >= (-100)) && (pub_r000341_6_2 <= 100));
  __CPROVER_assume((pub_r000341_7_1 >= (-100)) && (pub_r000341_7_1 <= 100));
  __CPROVER_assume((pub_r000341_7_2 >= (-100)) && (pub_r000341_7_2 <= 100));
  __CPROVER_assume((pub_r000341_8_1 >= (-100)) && (pub_r000341_8_1 <= 100));
  __CPROVER_assume((pub_r000341_8_2 >= (-100)) && (pub_r000341_8_2 <= 100));
  __CPROVER_assume((pub_r000341_9_1 >= (-100)) && (pub_r000341_9_1 <= 100));
  __CPROVER_assume((pub_r000341_9_2 >= (-100)) && (pub_r000341_9_2 <= 100));
  __CPROVER_assume((pub_r000341_10_1 >= (-100)) && (pub_r000341_10_1 <= 100));
  __CPROVER_assume((pub_r000341_10_2 >= (-100)) && (pub_r000341_10_2 <= 100));
  __CPROVER_assume((pub_r000341_11_1 >= (-100)) && (pub_r000341_11_1 <= 100));
  __CPROVER_assume((pub_r000341_11_2 >= (-100)) && (pub_r000341_11_2 <= 100));
  __CPROVER_assume((pub_r000341_12_1 >= (-100)) && (pub_r000341_12_1 <= 100));
  __CPROVER_assume((pub_r000341_12_2 >= (-100)) && (pub_r000341_12_2 <= 100));
  __CPROVER_assume((pub_r000341_13_1 >= (-100)) && (pub_r000341_13_1 <= 100));
  __CPROVER_assume((pub_r000341_13_2 >= (-100)) && (pub_r000341_13_2 <= 100));
  __CPROVER_assume((pub_r000341_14_1 >= (-100)) && (pub_r000341_14_1 <= 100));
  __CPROVER_assume((pub_r000341_14_2 >= (-100)) && (pub_r000341_14_2 <= 100));
  __CPROVER_assume((pub_r000341_15_1 >= (-100)) && (pub_r000341_15_1 <= 100));
  __CPROVER_assume((pub_r000341_15_2 >= (-100)) && (pub_r000341_15_2 <= 100));
  __CPROVER_assume((pub_r000341_16_1 >= (-100)) && (pub_r000341_16_1 <= 100));
  __CPROVER_assume((pub_r000341_16_2 >= (-100)) && (pub_r000341_16_2 <= 100));
  __CPROVER_assume((sec_r000341_0_1 >= 0) && (sec_r000341_0_1 <= 255));
  __CPROVER_assume((sec_r000341_0_2 >= 0) && (sec_r000341_0_2 <= 255));
  __CPROVER_assume((sec_r000341_1_1 >= 0) && (sec_r000341_1_1 <= 255));
  __CPROVER_assume((sec_r000341_1_2 >= 0) && (sec_r000341_1_2 <= 255));
  __CPROVER_assume((sec_r000341_2_1 >= 0) && (sec_r000341_2_1 <= 255));
  __CPROVER_assume((sec_r000341_2_2 >= 0) && (sec_r000341_2_2 <= 255));
  __CPROVER_assume((sec_r000341_3_1 >= 0) && (sec_r000341_3_1 <= 255));
  __CPROVER_assume((sec_r000341_3_2 >= 0) && (sec_r000341_3_2 <= 255));
  __CPROVER_assume((sec_r000341_4_1 >= 0) && (sec_r000341_4_1 <= 255));
  __CPROVER_assume((sec_r000341_4_2 >= 0) && (sec_r000341_4_2 <= 255));
  __CPROVER_assume((sec_r000341_5_1 >= 0) && (sec_r000341_5_1 <= 255));
  __CPROVER_assume((sec_r000341_5_2 >= 0) && (sec_r000341_5_2 <= 255));
  __CPROVER_assume((sec_r000341_6_1 >= 0) && (sec_r000341_6_1 <= 255));
  __CPROVER_assume((sec_r000341_6_2 >= 0) && (sec_r000341_6_2 <= 255));
  __CPROVER_assume((sec_r000341_7_1 >= 0) && (sec_r000341_7_1 <= 255));
  __CPROVER_assume((sec_r000341_7_2 >= 0) && (sec_r000341_7_2 <= 255));
  __CPROVER_assume((sec_r000341_8_1 >= 0) && (sec_r000341_8_1 <= 255));
  __CPROVER_assume((sec_r000341_8_2 >= 0) && (sec_r000341_8_2 <= 255));
  __CPROVER_assume((sec_r000341_9_1 >= 0) && (sec_r000341_9_1 <= 255));
  __CPROVER_assume((sec_r000341_9_2 >= 0) && (sec_r000341_9_2 <= 255));
  __CPROVER_assume((sec_r000341_10_1 >= 0) && (sec_r000341_10_1 <= 255));
  __CPROVER_assume((sec_r000341_10_2 >= 0) && (sec_r000341_10_2 <= 255));
  __CPROVER_assume((sec_r000341_11_1 >= 0) && (sec_r000341_11_1 <= 255));
  __CPROVER_assume((sec_r000341_11_2 >= 0) && (sec_r000341_11_2 <= 255));
  __CPROVER_assume((sec_r000341_12_1 >= 0) && (sec_r000341_12_1 <= 255));
  __CPROVER_assume((sec_r000341_12_2 >= 0) && (sec_r000341_12_2 <= 255));
  __CPROVER_assume((sec_r000341_13_1 >= 0) && (sec_r000341_13_1 <= 255));
  __CPROVER_assume((sec_r000341_13_2 >= 0) && (sec_r000341_13_2 <= 255));
  __CPROVER_assume((sec_r000341_14_1 >= 0) && (sec_r000341_14_1 <= 255));
  __CPROVER_assume((sec_r000341_14_2 >= 0) && (sec_r000341_14_2 <= 255));
  __CPROVER_assume((sec_r000341_15_1 >= 0) && (sec_r000341_15_1 <= 255));
  __CPROVER_assume((sec_r000341_15_2 >= 0) && (sec_r000341_15_2 <= 255));
  __CPROVER_assume((sec_r000341_16_1 >= 0) && (sec_r000341_16_1 <= 255));
  __CPROVER_assume((sec_r000341_16_2 >= 0) && (sec_r000341_16_2 <= 255));
  __CPROVER_assume((sec_r000341_17_1 >= 0) && (sec_r000341_17_1 <= 255));
  __CPROVER_assume((sec_r000341_17_2 >= 0) && (sec_r000341_17_2 <= 255));
  __CPROVER_assume((sec_r000341_18_1 >= 0) && (sec_r000341_18_1 <= 255));
  __CPROVER_assume((sec_r000341_18_2 >= 0) && (sec_r000341_18_2 <= 255));
  __CPROVER_assume((sec_r000341_19_1 >= 0) && (sec_r000341_19_1 <= 255));
  __CPROVER_assume((sec_r000341_19_2 >= 0) && (sec_r000341_19_2 <= 255));
  __CPROVER_assume((sec_r000341_20_1 >= 0) && (sec_r000341_20_1 <= 255));
  __CPROVER_assume((sec_r000341_20_2 >= 0) && (sec_r000341_20_2 <= 255));
  __CPROVER_assume((sec_r000341_21_1 >= 0) && (sec_r000341_21_1 <= 255));
  __CPROVER_assume((sec_r000341_21_2 >= 0) && (sec_r000341_21_2 <= 255));
  struct AudioFrame_R000341_4113_0 st_var_0_1 = {0};
  struct AudioFrame_R000341_4113_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000341_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000341_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000341_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000341_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000341_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000341_0_2 + 7) & 15;
  struct CipherContext_R000341_4113_1 st_var_1_1 = {0};
  struct CipherContext_R000341_4113_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000341_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000341_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000341_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000341_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000341_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000341_0_2 + 9) & 15;
  struct FilterState_R000341_4113_2 st_var_2_1 = {0};
  struct FilterState_R000341_4113_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000341_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000341_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000341_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000341_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000341_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000341_0_2 + 11) & 15;
  struct SensorNode_R000341_4113_3 st_var_3_1 = {0};
  struct SensorNode_R000341_4113_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000341_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000341_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000341_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000341_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000341_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000341_0_2 + 13) & 15;
  union TelemetryField_R000341_4113_0 u_var_1;
  union TelemetryField_R000341_4113_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (5 & 31);
  int stage_v_0_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (5 & 31);
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= (stage_v_0_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_0_2 << 1) & 127;
  int stage_v_1_1 = 0;
  int stage_v_1_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_1_1 = ((stage_v_1_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_1_2 = ((stage_v_1_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (8 & 31);
  int stage_v_3_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (8 & 31);
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= (stage_v_3_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_3_2 << 1) & 127;
  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 7) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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
  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_9_1 = ((stage_v_9_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_9_2 = ((stage_v_9_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  int stage_v_11_1 = ((st_var_3_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_3_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 41)
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
  if (stage_v_11_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 41)
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
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
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

  switch (stage_v_13_2)
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

  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (22 & 31);
  int stage_v_17_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (22 & 31);
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= (stage_v_17_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_17_2 << 1) & 127;
  int stage_v_18_1 = (st_var_2_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_2_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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

  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_21_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_22_1 = (st_var_2_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_2_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  int stage_v_23_1 = table_1[3];
  int stage_v_23_2 = table_2[3];
  table_1[3] = (table_1[0] + 47) & 63;
  table_2[3] = (table_2[0] + 47) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (30 & 31);
  int stage_v_25_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (30 & 31);
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= (stage_v_25_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_25_2 << 1) & 127;
  int stage_v_26_1 = (st_var_2_1.buffer[0] ^ 29) & 3;
  int stage_v_26_2 = (st_var_2_2.buffer[0] ^ 29) & 3;
  switch (stage_v_26_1)
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

  switch (stage_v_26_2)
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

  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_28_1 = ((stage_v_28_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_28_2 = ((stage_v_28_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_29_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_29_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_29_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
  int stage_v_31_1 = table_1[3];
  int stage_v_31_2 = table_2[3];
  table_1[3] = (table_1[0] + 63) & 63;
  table_2[3] = (table_2[0] + 63) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  int stage_v_33_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_33_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_33_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_33_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_34_1 = (st_var_2_1.buffer[0] ^ 37) & 3;
  int stage_v_34_2 = (st_var_2_2.buffer[0] ^ 37) & 3;
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

  int stage_v_35_1 = (st_var_3_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_3_2.buffer[0] ^ 38) & 3;
  switch (stage_v_35_1)
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

  switch (stage_v_35_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 37) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 37) & 15;
  int stage_v_36_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_36_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= stage_v_36_1;
  chk_sum_2 ^= stage_v_36_2;
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 36)
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
  if (stage_v_37_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 36)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 39) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 39) & 15;
  int stage_v_38_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_38_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= stage_v_38_1;
  chk_sum_2 ^= stage_v_38_2;
  int stage_v_39_1 = ((st_var_3_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_3_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 45)
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
  if (stage_v_39_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 45)
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
  int stage_v_40_1 = ((st_var_0_1.buffer[1] * 2) + 127) & 63;
  int stage_v_40_2 = ((st_var_0_2.buffer[1] * 2) + 127) & 63;
  if (stage_v_40_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_40_1) - 5) & 255;
    if (stage_v_40_1 > 42)
    {
      chk_sum_1 ^= stage_v_40_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_40_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_40_2) - 5) & 255;
    if (stage_v_40_2 > 42)
    {
      chk_sum_2 ^= stage_v_40_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_41_1 = ((st_var_1_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_1_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 36)
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
  if (stage_v_41_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 36)
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
  int stage_v_42_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (47 & 31);
  int stage_v_42_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (47 & 31);
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= (stage_v_42_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_42_2 << 1) & 127;
  int stage_v_43_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (48 & 31);
  int stage_v_43_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (48 & 31);
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= (stage_v_43_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_43_2 << 1) & 127;
  int stage_v_44_1 = (st_var_0_1.buffer[0] ^ 47) & 3;
  int stage_v_44_2 = (st_var_0_2.buffer[0] ^ 47) & 3;
  switch (stage_v_44_1)
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

  switch (stage_v_44_2)
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

  int stage_v_45_1 = table_1[1];
  int stage_v_45_2 = table_2[1];
  table_1[1] = (table_1[2] + 91) & 63;
  table_2[1] = (table_2[2] + 91) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
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

  switch (stage_v_47_2)
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

  int stage_v_48_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_48_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_48_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_48_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_49_1 = ((st_var_1_1.buffer[1] * 2) + 154) & 63;
  int stage_v_49_2 = ((st_var_1_2.buffer[1] * 2) + 154) & 63;
  if (stage_v_49_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 39)
    {
      chk_sum_1 ^= stage_v_49_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_49_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 39)
    {
      chk_sum_2 ^= stage_v_49_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_50_1 = ((st_var_2_1.buffer[2] * 2) + 157) & 63;
  int stage_v_50_2 = ((st_var_2_2.buffer[2] * 2) + 157) & 63;
  if (stage_v_50_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_50_1) - 5) & 255;
    if (stage_v_50_1 > 55)
    {
      chk_sum_1 ^= stage_v_50_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_50_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_50_2) - 5) & 255;
    if (stage_v_50_2 > 55)
    {
      chk_sum_2 ^= stage_v_50_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 52) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 52) & 15;
  int stage_v_51_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_51_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= stage_v_51_1;
  chk_sum_2 ^= stage_v_51_2;
  int stage_v_52_1 = ((st_var_0_1.buffer[1] * 2) + 163) & 63;
  int stage_v_52_2 = ((st_var_0_2.buffer[1] * 2) + 163) & 63;
  if (stage_v_52_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_52_1) - 5) & 255;
    if (stage_v_52_1 > 44)
    {
      chk_sum_1 ^= stage_v_52_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_52_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_52_2) - 5) & 255;
    if (stage_v_52_2 > 44)
    {
      chk_sum_2 ^= stage_v_52_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_53_1 = table_1[1];
  int stage_v_53_2 = table_2[1];
  table_1[1] = (table_1[2] + 107) & 63;
  table_2[1] = (table_2[2] + 107) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_54_1 = ((stage_v_54_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_54_2 = ((stage_v_54_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((st_var_3_1.buffer[1] * 2) + 172) & 63;
  int stage_v_55_2 = ((st_var_3_2.buffer[1] * 2) + 172) & 63;
  if (stage_v_55_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_55_1) - 5) & 255;
    if (stage_v_55_1 > 49)
    {
      chk_sum_1 ^= stage_v_55_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_55_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_55_2) - 5) & 255;
    if (stage_v_55_2 > 49)
    {
      chk_sum_2 ^= stage_v_55_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_56_1 = ((stage_v_56_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_56_2 = ((stage_v_56_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = table_1[1];
  int stage_v_57_2 = table_2[1];
  table_1[1] = (table_1[2] + 115) & 63;
  table_2[1] = (table_2[2] + 115) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((st_var_2_1.buffer[1] * 2) + 181) & 63;
  int stage_v_58_2 = ((st_var_2_2.buffer[1] * 2) + 181) & 63;
  if (stage_v_58_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_58_1) - 5) & 255;
    if (stage_v_58_1 > 47)
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
  if (stage_v_58_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_58_2) - 5) & 255;
    if (stage_v_58_2 > 47)
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
  int stage_v_59_1 = ((st_var_3_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_3_2.buffer[2] * 2) + 184) & 63;
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
  int stage_v_60_1 = ((st_var_0_1.buffer[0] * 2) + 187) & 63;
  int stage_v_60_2 = ((st_var_0_2.buffer[0] * 2) + 187) & 63;
  if (stage_v_60_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_60_1) - 5) & 255;
    if (stage_v_60_1 > 27)
    {
      chk_sum_1 ^= stage_v_60_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_60_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_60_2) - 5) & 255;
    if (stage_v_60_2 > 27)
    {
      chk_sum_2 ^= stage_v_60_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 62) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 62) & 15;
  int stage_v_61_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_61_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= stage_v_61_1;
  chk_sum_2 ^= stage_v_61_2;
  int stage_v_62_1 = (st_var_2_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_2_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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

  int stage_v_63_1 = (st_var_3_1.buffer[0] ^ 66) & 3;
  int stage_v_63_2 = (st_var_3_2.buffer[0] ^ 66) & 3;
  switch (stage_v_63_1)
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

  switch (stage_v_63_2)
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

  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_64_1 = ((stage_v_64_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_64_2 = ((stage_v_64_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_65_1 = ((stage_v_65_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_65_2 = ((stage_v_65_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_66_1 = ((stage_v_66_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_66_2 = ((stage_v_66_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = table_1[3];
  int stage_v_67_2 = table_2[3];
  table_1[3] = (table_1[0] + 135) & 63;
  table_2[3] = (table_2[0] + 135) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((st_var_0_1.buffer[2] * 2) + 211) & 63;
  int stage_v_68_2 = ((st_var_0_2.buffer[2] * 2) + 211) & 63;
  if (stage_v_68_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_68_1) - 5) & 255;
    if (stage_v_68_1 > 55)
    {
      chk_sum_1 ^= stage_v_68_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_68_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_68_2) - 5) & 255;
    if (stage_v_68_2 > 55)
    {
      chk_sum_2 ^= stage_v_68_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_69_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_69_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_69_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_69_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_70_1 = table_1[2];
  int stage_v_70_2 = table_2[2];
  table_1[2] = (table_1[3] + 141) & 63;
  table_2[2] = (table_2[3] + 141) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_71_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_72_1 = ((st_var_0_1.buffer[0] * 2) + 223) & 63;
  int stage_v_72_2 = ((st_var_0_2.buffer[0] * 2) + 223) & 63;
  if (stage_v_72_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_72_1) - 5) & 255;
    if (stage_v_72_1 > 36)
    {
      chk_sum_1 ^= stage_v_72_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_72_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_72_2) - 5) & 255;
    if (stage_v_72_2 > 36)
    {
      chk_sum_2 ^= stage_v_72_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_73_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (78 & 31);
  int stage_v_73_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (78 & 31);
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= (stage_v_73_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_73_2 << 1) & 127;
  int stage_v_74_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (79 & 31);
  int stage_v_74_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (79 & 31);
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  chk_sum_1 ^= (stage_v_74_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_74_2 << 1) & 127;
  int stage_v_75_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (80 & 31);
  int stage_v_75_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (80 & 31);
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  chk_sum_1 ^= (stage_v_75_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_75_2 << 1) & 127;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_76_1 = ((stage_v_76_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_76_2 = ((stage_v_76_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((st_var_1_1.buffer[2] * 2) + 238) & 63;
  int stage_v_77_2 = ((st_var_1_2.buffer[2] * 2) + 238) & 63;
  if (stage_v_77_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_77_1) - 5) & 255;
    if (stage_v_77_1 > 30)
    {
      chk_sum_1 ^= stage_v_77_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_77_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_77_2) - 5) & 255;
    if (stage_v_77_2 > 30)
    {
      chk_sum_2 ^= stage_v_77_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_78_1 = ((st_var_2_1.buffer[0] * 2) + 241) & 63;
  int stage_v_78_2 = ((st_var_2_2.buffer[0] * 2) + 241) & 63;
  if (stage_v_78_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_78_1) - 5) & 255;
    if (stage_v_78_1 > 25)
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
  if (stage_v_78_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_78_2) - 5) & 255;
    if (stage_v_78_2 > 25)
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
  int stage_v_79_1 = ((st_var_3_1.buffer[1] * 2) + 244) & 63;
  int stage_v_79_2 = ((st_var_3_2.buffer[1] * 2) + 244) & 63;
  if (stage_v_79_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_79_1) - 5) & 255;
    if (stage_v_79_1 > 38)
    {
      chk_sum_1 ^= stage_v_79_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_79_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_79_2) - 5) & 255;
    if (stage_v_79_2 > 38)
    {
      chk_sum_2 ^= stage_v_79_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_80_1 = ((stage_v_80_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_80_2 = ((stage_v_80_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = table_1[1];
  int stage_v_81_2 = table_2[1];
  table_1[1] = (table_1[2] + 163) & 63;
  table_2[1] = (table_2[2] + 163) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_82_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_82_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_82_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_83_1 = (st_var_3_1.buffer[0] ^ 86) & 3;
  int stage_v_83_2 = (st_var_3_2.buffer[0] ^ 86) & 3;
  switch (stage_v_83_1)
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

  switch (stage_v_83_2)
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
  int stage_v_85_1 = ((st_var_1_1.buffer[1] * 2) + 262) & 63;
  int stage_v_85_2 = ((st_var_1_2.buffer[1] * 2) + 262) & 63;
  if (stage_v_85_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_85_1) - 5) & 255;
    if (stage_v_85_1 > 37)
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
  if (stage_v_85_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_85_2) - 5) & 255;
    if (stage_v_85_2 > 37)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 87) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 87) & 15;
  int stage_v_86_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_86_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  chk_sum_1 ^= stage_v_86_1;
  chk_sum_2 ^= stage_v_86_2;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 88) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 88) & 15;
  int stage_v_87_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_87_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  chk_sum_1 ^= stage_v_87_1;
  chk_sum_2 ^= stage_v_87_2;
  int stage_v_88_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (93 & 31);
  int stage_v_88_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (93 & 31);
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= (stage_v_88_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_88_2 << 1) & 127;
  int stage_v_89_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_89_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_89_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_89_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_90_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_90_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_90_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_90_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_91_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_91_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_91_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_91_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_92_1 = (st_var_0_1.buffer[0] ^ 95) & 3;
  int stage_v_92_2 = (st_var_0_2.buffer[0] ^ 95) & 3;
  switch (stage_v_92_1)
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

  switch (stage_v_92_2)
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

  int stage_v_93_1 = ((st_var_1_1.buffer[0] * 2) + 286) & 63;
  int stage_v_93_2 = ((st_var_1_2.buffer[0] * 2) + 286) & 63;
  if (stage_v_93_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_93_1) - 5) & 255;
    if (stage_v_93_1 > 30)
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
  if (stage_v_93_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_93_2) - 5) & 255;
    if (stage_v_93_2 > 30)
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
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_95_1 = ((stage_v_95_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_95_2 = ((stage_v_95_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_96_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_96_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_96_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_97_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (102 & 31);
  int stage_v_97_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (102 & 31);
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  chk_sum_1 ^= (stage_v_97_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_97_2 << 1) & 127;
  int stage_v_98_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_98_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_98_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_98_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_99_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (104 & 31);
  int stage_v_99_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (104 & 31);
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  chk_sum_1 ^= (stage_v_99_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_99_2 << 1) & 127;
  int stage_v_100_1 = table_1[0];
  int stage_v_100_2 = table_2[0];
  table_1[0] = (table_1[1] + 201) & 63;
  table_2[0] = (table_2[1] + 201) & 63;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (106 & 31);
  int stage_v_101_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (106 & 31);
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  chk_sum_1 ^= (stage_v_101_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_101_2 << 1) & 127;
  int stage_v_102_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (107 & 31);
  int stage_v_102_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (107 & 31);
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  chk_sum_1 ^= (stage_v_102_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_102_2 << 1) & 127;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_103_1 = ((stage_v_103_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_103_2 = ((stage_v_103_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = table_1[0];
  int stage_v_104_2 = table_2[0];
  table_1[0] = (table_1[1] + 209) & 63;
  table_2[0] = (table_2[1] + 209) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_105_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_105_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_105_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 107) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 107) & 15;
  int stage_v_106_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_106_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  chk_sum_1 ^= stage_v_106_1;
  chk_sum_2 ^= stage_v_106_2;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_107_1 = ((stage_v_107_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_107_2 = ((stage_v_107_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_108_1 = ((stage_v_108_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_108_2 = ((stage_v_108_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_109_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_109_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_109_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 111) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 111) & 15;
  int stage_v_110_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_110_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  chk_sum_1 ^= stage_v_110_1;
  chk_sum_2 ^= stage_v_110_2;
  int stage_v_111_1 = ((st_var_3_1.buffer[0] * 2) + 340) & 63;
  int stage_v_111_2 = ((st_var_3_2.buffer[0] * 2) + 340) & 63;
  if (stage_v_111_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_111_1) - 5) & 255;
    if (stage_v_111_1 > 51)
    {
      chk_sum_1 ^= stage_v_111_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_111_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_111_2) - 5) & 255;
    if (stage_v_111_2 > 51)
    {
      chk_sum_2 ^= stage_v_111_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_112_1 = ((stage_v_112_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_112_2 = ((stage_v_112_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((st_var_1_1.buffer[2] * 2) + 346) & 63;
  int stage_v_113_2 = ((st_var_1_2.buffer[2] * 2) + 346) & 63;
  if (stage_v_113_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_113_1) - 5) & 255;
    if (stage_v_113_1 > 42)
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
  if (stage_v_113_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_113_2) - 5) & 255;
    if (stage_v_113_2 > 42)
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
  int stage_v_114_1 = ((st_var_2_1.buffer[0] * 2) + 349) & 63;
  int stage_v_114_2 = ((st_var_2_2.buffer[0] * 2) + 349) & 63;
  if (stage_v_114_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_114_1) - 5) & 255;
    if (stage_v_114_1 > 46)
    {
      chk_sum_1 ^= stage_v_114_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_114_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_114_2) - 5) & 255;
    if (stage_v_114_2 > 46)
    {
      chk_sum_2 ^= stage_v_114_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_115_1 = ((stage_v_115_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_115_2 = ((stage_v_115_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (st_var_0_1.buffer[0] ^ 119) & 3;
  int stage_v_116_2 = (st_var_0_2.buffer[0] ^ 119) & 3;
  switch (stage_v_116_1)
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

  switch (stage_v_116_2)
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

  int stage_v_117_1 = (st_var_1_1.buffer[0] ^ 120) & 3;
  int stage_v_117_2 = (st_var_1_2.buffer[0] ^ 120) & 3;
  switch (stage_v_117_1)
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

  switch (stage_v_117_2)
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

  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 119) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 119) & 15;
  int stage_v_118_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_118_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  chk_sum_1 ^= stage_v_118_1;
  chk_sum_2 ^= stage_v_118_2;
  int stage_v_119_1 = (st_var_3_1.buffer[0] ^ 122) & 3;
  int stage_v_119_2 = (st_var_3_2.buffer[0] ^ 122) & 3;
  switch (stage_v_119_1)
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

  switch (stage_v_119_2)
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

  int stage_v_120_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (125 & 31);
  int stage_v_120_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (125 & 31);
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  chk_sum_1 ^= (stage_v_120_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_120_2 << 1) & 127;
  int stage_v_121_1 = table_1[1];
  int stage_v_121_2 = table_2[1];
  table_1[1] = (table_1[2] + 243) & 63;
  table_2[1] = (table_2[2] + 243) & 63;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (st_var_2_1.buffer[0] ^ 125) & 3;
  int stage_v_122_2 = (st_var_2_2.buffer[0] ^ 125) & 3;
  switch (stage_v_122_1)
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

  switch (stage_v_122_2)
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

  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_123_1 = ((stage_v_123_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_123_2 = ((stage_v_123_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_124_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_124_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_124_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_125_1 = ((stage_v_125_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_125_2 = ((stage_v_125_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = table_1[2];
  int stage_v_126_2 = table_2[2];
  table_1[2] = (table_1[3] + 253) & 63;
  table_2[2] = (table_2[3] + 253) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((st_var_3_1.buffer[1] * 2) + 388) & 63;
  int stage_v_127_2 = ((st_var_3_2.buffer[1] * 2) + 388) & 63;
  if (stage_v_127_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_127_1) - 5) & 255;
    if (stage_v_127_1 > 48)
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
  if (stage_v_127_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_127_2) - 5) & 255;
    if (stage_v_127_2 > 48)
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
  int stage_v_128_1 = (st_var_0_1.buffer[0] ^ 131) & 3;
  int stage_v_128_2 = (st_var_0_2.buffer[0] ^ 131) & 3;
  switch (stage_v_128_1)
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

  switch (stage_v_128_2)
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

  int stage_v_129_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_129_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_129_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_129_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_130_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (135 & 31);
  int stage_v_130_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (135 & 31);
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  chk_sum_1 ^= (stage_v_130_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_130_2 << 1) & 127;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_131_1 = ((stage_v_131_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_131_2 = ((stage_v_131_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (st_var_0_1.buffer[0] ^ 135) & 3;
  int stage_v_132_2 = (st_var_0_2.buffer[0] ^ 135) & 3;
  switch (stage_v_132_1)
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

  switch (stage_v_132_2)
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

  int stage_v_133_1 = ((st_var_1_1.buffer[1] * 2) + 406) & 63;
  int stage_v_133_2 = ((st_var_1_2.buffer[1] * 2) + 406) & 63;
  if (stage_v_133_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_133_1) - 5) & 255;
    if (stage_v_133_1 > 26)
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
  if (stage_v_133_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_133_2) - 5) & 255;
    if (stage_v_133_2 > 26)
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
  int stage_v_134_1 = table_1[2];
  int stage_v_134_2 = table_2[2];
  table_1[2] = (table_1[3] + 269) & 63;
  table_2[2] = (table_2[3] + 269) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_135_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_135_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_135_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_136_1 = table_1[0];
  int stage_v_136_2 = table_2[0];
  table_1[0] = (table_1[1] + 273) & 63;
  table_2[0] = (table_2[1] + 273) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = table_1[1];
  int stage_v_137_2 = table_2[1];
  table_1[1] = (table_1[2] + 275) & 63;
  table_2[1] = (table_2[2] + 275) & 63;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = (st_var_2_1.buffer[0] ^ 141) & 3;
  int stage_v_138_2 = (st_var_2_2.buffer[0] ^ 141) & 3;
  switch (stage_v_138_1)
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

  switch (stage_v_138_2)
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

  int stage_v_139_1 = ((st_var_3_1.buffer[1] * 2) + 424) & 63;
  int stage_v_139_2 = ((st_var_3_2.buffer[1] * 2) + 424) & 63;
  if (stage_v_139_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_139_1) - 5) & 255;
    if (stage_v_139_1 > 49)
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
  if (stage_v_139_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_139_2) - 5) & 255;
    if (stage_v_139_2 > 49)
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
  int stage_v_140_1 = ((st_var_0_1.buffer[2] * 2) + 427) & 63;
  int stage_v_140_2 = ((st_var_0_2.buffer[2] * 2) + 427) & 63;
  if (stage_v_140_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_140_1) - 5) & 255;
    if (stage_v_140_1 > 31)
    {
      chk_sum_1 ^= stage_v_140_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_140_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_140_2) - 5) & 255;
    if (stage_v_140_2 > 31)
    {
      chk_sum_2 ^= stage_v_140_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_141_1 = ((st_var_1_1.buffer[0] * 2) + 430) & 63;
  int stage_v_141_2 = ((st_var_1_2.buffer[0] * 2) + 430) & 63;
  if (stage_v_141_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_141_1) - 5) & 255;
    if (stage_v_141_1 > 54)
    {
      chk_sum_1 ^= stage_v_141_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_141_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_141_2) - 5) & 255;
    if (stage_v_141_2 > 54)
    {
      chk_sum_2 ^= stage_v_141_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_142_1 = ((st_var_2_1.buffer[1] * 2) + 433) & 63;
  int stage_v_142_2 = ((st_var_2_2.buffer[1] * 2) + 433) & 63;
  if (stage_v_142_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_142_1) - 5) & 255;
    if (stage_v_142_1 > 27)
    {
      chk_sum_1 ^= stage_v_142_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_142_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_142_2) - 5) & 255;
    if (stage_v_142_2 > 27)
    {
      chk_sum_2 ^= stage_v_142_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_143_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_143_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_143_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_143_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_144_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (149 & 31);
  int stage_v_144_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (149 & 31);
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  chk_sum_1 ^= (stage_v_144_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_144_2 << 1) & 127;
  int stage_v_145_1 = (st_var_1_1.buffer[0] ^ 148) & 3;
  int stage_v_145_2 = (st_var_1_2.buffer[0] ^ 148) & 3;
  switch (stage_v_145_1)
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

  switch (stage_v_145_2)
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

  int stage_v_146_1 = (st_var_2_1.buffer[0] ^ 149) & 3;
  int stage_v_146_2 = (st_var_2_2.buffer[0] ^ 149) & 3;
  switch (stage_v_146_1)
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

  switch (stage_v_146_2)
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

  int stage_v_147_1 = (st_var_3_1.buffer[0] ^ 150) & 3;
  int stage_v_147_2 = (st_var_3_2.buffer[0] ^ 150) & 3;
  switch (stage_v_147_1)
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

  switch (stage_v_147_2)
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

  int stage_v_148_1 = ((st_var_0_1.buffer[1] * 2) + 451) & 63;
  int stage_v_148_2 = ((st_var_0_2.buffer[1] * 2) + 451) & 63;
  if (stage_v_148_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_148_1) - 5) & 255;
    if (stage_v_148_1 > 46)
    {
      chk_sum_1 ^= stage_v_148_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_148_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_148_2) - 5) & 255;
    if (stage_v_148_2 > 46)
    {
      chk_sum_2 ^= stage_v_148_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_149_1 = (st_var_1_1.buffer[0] ^ 152) & 3;
  int stage_v_149_2 = (st_var_1_2.buffer[0] ^ 152) & 3;
  switch (stage_v_149_1)
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

  switch (stage_v_149_2)
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

  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 151) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 151) & 15;
  int stage_v_150_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_150_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  chk_sum_1 ^= stage_v_150_1;
  chk_sum_2 ^= stage_v_150_2;
  int stage_v_151_1 = table_1[3];
  int stage_v_151_2 = table_2[3];
  table_1[3] = (table_1[0] + 303) & 63;
  table_2[3] = (table_2[0] + 303) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 153) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 153) & 15;
  int stage_v_152_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_152_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  chk_sum_1 ^= stage_v_152_1;
  chk_sum_2 ^= stage_v_152_2;
  int stage_v_153_1 = table_1[1];
  int stage_v_153_2 = table_2[1];
  table_1[1] = (table_1[2] + 307) & 63;
  table_2[1] = (table_2[2] + 307) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = table_1[2];
  int stage_v_154_2 = table_2[2];
  table_1[2] = (table_1[3] + 309) & 63;
  table_2[2] = (table_2[3] + 309) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = table_1[3];
  int stage_v_155_2 = table_2[3];
  table_1[3] = (table_1[0] + 311) & 63;
  table_2[3] = (table_2[0] + 311) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((st_var_0_1.buffer[0] * 2) + 475) & 63;
  int stage_v_156_2 = ((st_var_0_2.buffer[0] * 2) + 475) & 63;
  if (stage_v_156_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_156_1) - 5) & 255;
    if (stage_v_156_1 > 31)
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
  if (stage_v_156_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_156_2) - 5) & 255;
    if (stage_v_156_2 > 31)
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
  int stage_v_157_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_157_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_157_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_157_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_158_1 = ((stage_v_158_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_158_2 = ((stage_v_158_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = table_1[3];
  int stage_v_159_2 = table_2[3];
  table_1[3] = (table_1[0] + 319) & 63;
  table_2[3] = (table_2[0] + 319) & 63;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = table_1[0];
  int stage_v_160_2 = table_2[0];
  table_1[0] = (table_1[1] + 321) & 63;
  table_2[0] = (table_2[1] + 321) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (166 & 31);
  int stage_v_161_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (166 & 31);
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  chk_sum_1 ^= (stage_v_161_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_161_2 << 1) & 127;
  int stage_v_162_1 = table_1[2];
  int stage_v_162_2 = table_2[2];
  table_1[2] = (table_1[3] + 325) & 63;
  table_2[2] = (table_2[3] + 325) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (168 & 31);
  int stage_v_163_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (168 & 31);
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  chk_sum_1 ^= (stage_v_163_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_163_2 << 1) & 127;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_164_1 = ((stage_v_164_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_164_2 = ((stage_v_164_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 166) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 166) & 15;
  int stage_v_165_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_165_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  chk_sum_1 ^= stage_v_165_1;
  chk_sum_2 ^= stage_v_165_2;
  int stage_v_166_1 = (st_var_2_1.buffer[0] ^ 169) & 3;
  int stage_v_166_2 = (st_var_2_2.buffer[0] ^ 169) & 3;
  switch (stage_v_166_1)
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

  switch (stage_v_166_2)
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

  int stage_v_167_1 = ((st_var_3_1.buffer[2] * 2) + 508) & 63;
  int stage_v_167_2 = ((st_var_3_2.buffer[2] * 2) + 508) & 63;
  if (stage_v_167_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_167_1) - 5) & 255;
    if (stage_v_167_1 > 25)
    {
      chk_sum_1 ^= stage_v_167_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_167_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_167_2) - 5) & 255;
    if (stage_v_167_2 > 25)
    {
      chk_sum_2 ^= stage_v_167_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 170) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 170) & 15;
  int stage_v_169_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_169_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  chk_sum_1 ^= stage_v_169_1;
  chk_sum_2 ^= stage_v_169_2;
  int stage_v_170_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (175 & 31);
  int stage_v_170_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (175 & 31);
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  chk_sum_1 ^= (stage_v_170_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_170_2 << 1) & 127;
  int stage_v_171_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (176 & 31);
  int stage_v_171_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (176 & 31);
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  chk_sum_1 ^= (stage_v_171_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_171_2 << 1) & 127;
  int stage_v_172_1 = 0;
  int stage_v_172_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_172_1 = ((stage_v_172_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_172_2 = ((stage_v_172_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 174) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 174) & 15;
  int stage_v_173_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_173_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  chk_sum_1 ^= stage_v_173_1;
  chk_sum_2 ^= stage_v_173_2;
  int stage_v_174_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (179 & 31);
  int stage_v_174_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (179 & 31);
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  chk_sum_1 ^= (stage_v_174_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_174_2 << 1) & 127;
  int stage_v_175_1 = (st_var_3_1.buffer[0] ^ 178) & 3;
  int stage_v_175_2 = (st_var_3_2.buffer[0] ^ 178) & 3;
  switch (stage_v_175_1)
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

  switch (stage_v_175_2)
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

  int stage_v_176_1 = 0;
  int stage_v_176_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_176_1 = ((stage_v_176_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_176_2 = ((stage_v_176_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((st_var_1_1.buffer[0] * 2) + 538) & 63;
  int stage_v_177_2 = ((st_var_1_2.buffer[0] * 2) + 538) & 63;
  if (stage_v_177_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_177_1) - 5) & 255;
    if (stage_v_177_1 > 45)
    {
      chk_sum_1 ^= stage_v_177_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_177_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_177_2) - 5) & 255;
    if (stage_v_177_2 > 45)
    {
      chk_sum_2 ^= stage_v_177_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_178_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (183 & 31);
  int stage_v_178_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (183 & 31);
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  chk_sum_1 ^= (stage_v_178_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_178_2 << 1) & 127;
  int stage_v_179_1 = table_1[3];
  int stage_v_179_2 = table_2[3];
  table_1[3] = (table_1[0] + 359) & 63;
  table_2[3] = (table_2[0] + 359) & 63;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = (st_var_0_1.buffer[0] ^ 183) & 3;
  int stage_v_180_2 = (st_var_0_2.buffer[0] ^ 183) & 3;
  switch (stage_v_180_1)
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

  switch (stage_v_180_2)
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

  int stage_v_181_1 = ((st_var_1_1.buffer[1] * 2) + 550) & 63;
  int stage_v_181_2 = ((st_var_1_2.buffer[1] * 2) + 550) & 63;
  if (stage_v_181_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_181_1) - 5) & 255;
    if (stage_v_181_1 > 48)
    {
      chk_sum_1 ^= stage_v_181_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_181_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_181_2) - 5) & 255;
    if (stage_v_181_2 > 48)
    {
      chk_sum_2 ^= stage_v_181_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 183) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 183) & 15;
  int stage_v_182_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_182_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  chk_sum_1 ^= stage_v_182_1;
  chk_sum_2 ^= stage_v_182_2;
  int stage_v_183_1 = 0;
  int stage_v_183_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_183_1 = ((stage_v_183_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_183_2 = ((stage_v_183_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_184_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_184_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_184_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_185_1 = table_1[1];
  int stage_v_185_2 = table_2[1];
  table_1[1] = (table_1[2] + 371) & 63;
  table_2[1] = (table_2[2] + 371) & 63;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_186_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_186_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_186_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_187_1 = 0;
  int stage_v_187_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_187_1 = ((stage_v_187_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_187_2 = ((stage_v_187_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = (st_var_0_1.buffer[0] ^ 191) & 3;
  int stage_v_188_2 = (st_var_0_2.buffer[0] ^ 191) & 3;
  switch (stage_v_188_1)
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

  switch (stage_v_188_2)
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

  int stage_v_189_1 = (st_var_1_1.buffer[0] ^ 192) & 3;
  int stage_v_189_2 = (st_var_1_2.buffer[0] ^ 192) & 3;
  switch (stage_v_189_1)
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

  switch (stage_v_189_2)
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

  int stage_v_190_1 = 0;
  int stage_v_190_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_190_1 = ((stage_v_190_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_190_2 = ((stage_v_190_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (196 & 31);
  int stage_v_191_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (196 & 31);
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  chk_sum_1 ^= (stage_v_191_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_191_2 << 1) & 127;
  int stage_v_192_1 = (st_var_0_1.buffer[0] ^ 195) & 3;
  int stage_v_192_2 = (st_var_0_2.buffer[0] ^ 195) & 3;
  switch (stage_v_192_1)
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

  switch (stage_v_192_2)
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

  int stage_v_193_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (198 & 31);
  int stage_v_193_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (198 & 31);
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  chk_sum_1 ^= (stage_v_193_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_193_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 195) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 195) & 15;
  int stage_v_194_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_194_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  chk_sum_1 ^= stage_v_194_1;
  chk_sum_2 ^= stage_v_194_2;
  int stage_v_195_1 = table_1[3];
  int stage_v_195_2 = table_2[3];
  table_1[3] = (table_1[0] + 391) & 63;
  table_2[3] = (table_2[0] + 391) & 63;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (201 & 31);
  int stage_v_196_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (201 & 31);
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  chk_sum_1 ^= (stage_v_196_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_196_2 << 1) & 127;
  int stage_v_197_1 = ((st_var_1_1.buffer[2] * 2) + 598) & 63;
  int stage_v_197_2 = ((st_var_1_2.buffer[2] * 2) + 598) & 63;
  if (stage_v_197_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_197_1) - 5) & 255;
    if (stage_v_197_1 > 44)
    {
      chk_sum_1 ^= stage_v_197_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_197_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_197_2) - 5) & 255;
    if (stage_v_197_2 > 44)
    {
      chk_sum_2 ^= stage_v_197_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int arith_v_0_1 = ((sec_r000341_21_1 * 3) + pub_r000341_13_1) & 127;
  int arith_v_0_2 = ((sec_r000341_21_2 * 3) + pub_r000341_13_2) & 127;
  int arith_v_1_1 = (arith_v_0_1 + (sec_r000341_17_1 * 2)) & 127;
  int arith_v_1_2 = (arith_v_0_2 + (sec_r000341_17_2 * 2)) & 127;
  int arith_v_2_1 = (arith_v_1_1 + (sec_r000341_19_1 * 2)) & 127;
  int arith_v_2_2 = (arith_v_1_2 + (sec_r000341_19_2 * 2)) & 127;
  int arith_v_3_1 = (arith_v_2_1 ^ (sec_r000341_21_1 * 2)) & 127;
  int arith_v_3_2 = (arith_v_2_2 ^ (sec_r000341_21_2 * 2)) & 127;
  out_sink_1 += arith_v_3_1 & 255;
  out_sink_2 += arith_v_3_2 & 255;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000341_20_1 != sec_r000341_20_2);
  __CPROVER_assume(sec_r000341_4_1 != sec_r000341_4_2);
  __CPROVER_assume(pub_r000341_9_1 == pub_r000341_9_2);
  __CPROVER_assume(sec_r000341_11_1 != sec_r000341_11_2);
  __CPROVER_assume(pub_r000341_11_1 == pub_r000341_11_2);
  __CPROVER_assume(pub_r000341_15_1 == pub_r000341_15_2);
  __CPROVER_assume(sec_r000341_12_1 != sec_r000341_12_2);
  __CPROVER_assume(sec_r000341_3_1 != sec_r000341_3_2);
  __CPROVER_assume(sec_r000341_8_1 != sec_r000341_8_2);
  __CPROVER_assume(sec_r000341_21_1 != sec_r000341_21_2);
  __CPROVER_assume(sec_r000341_16_1 != sec_r000341_16_2);
  __CPROVER_assume(pub_r000341_10_1 == pub_r000341_10_2);
  __CPROVER_assume(pub_r000341_4_1 == pub_r000341_4_2);
  __CPROVER_assume(sec_r000341_6_1 != sec_r000341_6_2);
  __CPROVER_assume(sec_r000341_9_1 != sec_r000341_9_2);
  __CPROVER_assume(sec_r000341_10_1 != sec_r000341_10_2);
  __CPROVER_assume(pub_r000341_16_1 == pub_r000341_16_2);
  __CPROVER_assume(pub_r000341_2_1 == pub_r000341_2_2);
  __CPROVER_assume(pub_r000341_6_1 == pub_r000341_6_2);
  __CPROVER_assume(sec_r000341_2_1 != sec_r000341_2_2);
  __CPROVER_assume(sec_r000341_7_1 != sec_r000341_7_2);
  __CPROVER_assume(pub_r000341_3_1 == pub_r000341_3_2);
  __CPROVER_assume(sec_r000341_14_1 != sec_r000341_14_2);
  __CPROVER_assume(pub_r000341_1_1 == pub_r000341_1_2);
  __CPROVER_assume(pub_r000341_5_1 == pub_r000341_5_2);
  __CPROVER_assume(sec_r000341_19_1 != sec_r000341_19_2);
  __CPROVER_assume(pub_r000341_0_1 == pub_r000341_0_2);
  __CPROVER_assume(pub_r000341_8_1 == pub_r000341_8_2);
  __CPROVER_assume(pub_r000341_7_1 == pub_r000341_7_2);
  __CPROVER_assume(sec_r000341_17_1 != sec_r000341_17_2);
  __CPROVER_assume(sec_r000341_0_1 != sec_r000341_0_2);
  __CPROVER_assume(pub_r000341_12_1 == pub_r000341_12_2);
  __CPROVER_assume(sec_r000341_13_1 != sec_r000341_13_2);
  __CPROVER_assume(sec_r000341_15_1 != sec_r000341_15_2);
  __CPROVER_assume(pub_r000341_14_1 == pub_r000341_14_2);
  __CPROVER_assume(sec_r000341_5_1 != sec_r000341_5_2);
  __CPROVER_assume(pub_r000341_13_1 == pub_r000341_13_2);
  __CPROVER_assume(sec_r000341_18_1 != sec_r000341_18_2);
  __CPROVER_assume(sec_r000341_1_1 != sec_r000341_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.tag == st_var_1_2.tag);
  assert(st_var_1_1.nonce == st_var_1_2.nonce);
  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  assert(st_var_1_1.flags == st_var_1_2.flags);
  assert(st_var_1_1.counter == st_var_1_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.cutoff == st_var_2_2.cutoff);
  assert(st_var_2_1.prev_out == st_var_2_2.prev_out);
  assert(st_var_2_1.gain_db == st_var_2_2.gain_db);
  assert(st_var_2_1.mode == st_var_2_2.mode);
  assert(st_var_2_1.prev_in == st_var_2_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.status == st_var_3_2.status);
  assert(st_var_3_1.calib == st_var_3_2.calib);
  assert(st_var_3_1.threshold == st_var_3_2.threshold);
  assert(st_var_3_1.gain == st_var_3_2.gain);
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
  assert(arith_v_0_1 == arith_v_0_2);
  assert(arith_v_1_1 == arith_v_1_2);
  assert(arith_v_2_1 == arith_v_2_2);
  assert(arith_v_3_1 == arith_v_3_2);
}


