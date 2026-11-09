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
struct EventLog_R001027_2713_0
{
  unsigned char facility;
  int signature;
  short code;
  short seq;
  int timestamp;
  short severity;
  int buffer[3];
};
struct AudioFrame_R001027_2713_1
{
  int rms;
  unsigned char peak;
  unsigned char channels;
  int sample_rate;
  short envelope;
  int buffer[3];
};
struct CipherContext_R001027_2713_2
{
  short iv;
  short counter;
  short flags;
  short round_key;
  short tag;
  int nonce;
  int buffer[3];
};
union ColorPixel_R001027_2713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R001027_2713_1
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
void fn_R001027_2713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001027_2713_2 st_1 = {0};
  struct CipherContext_R001027_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_77_1)
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

  switch (index_reg_77_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_44_1 = local_arr_1[aux_1 % 3];
  int delta_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_44_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_77_1 == index_reg_77_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_44_1 == delta_44_2);
}

int fn_R001027_2713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001027_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_77 = (aux + st.buffer[1]) & 3;
  switch (index_reg_77)
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

  int local_arr[3] = {4, 9, 15};
  int delta_44 = local_arr[aux % 3];
  acc = (acc + (delta_44 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001027_2713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001027_2713_1 st_1 = {0};
  struct AudioFrame_R001027_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int index_reg_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_77_1) & 63;
  aux_2 = (aux_2 + index_reg_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_17_1)
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

  switch (mask_17_2)
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_77_1 == index_reg_77_2);
  assert(mask_17_1 == mask_17_2);
}

int fn_R001027_2713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001027_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int index_reg_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_77) & 63;
  acc ^= aux;
  int mask_17 = (aux + st.buffer[1]) & 3;
  switch (mask_17)
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

void fn_R001027_2713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001027_2713_2 st_1 = {0};
  struct CipherContext_R001027_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int phase_58_1 = 0;
  int phase_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_58_1 = ((phase_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_58_2 = ((phase_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_58_1) & 127;
    acc_2 = (acc_2 + phase_58_2) & 127;
  }

  int mask_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_33_1) & 63;
  aux_2 = (aux_2 + mask_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_90_1 > 34)
  {
    acc_1 = ((acc_1 + (mask_90_1 * 2)) + 5) & 127;
    aux_1 ^= mask_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_90_2 > 34)
  {
    acc_2 = ((acc_2 + (mask_90_2 * 2)) + 5) & 127;
    aux_2 ^= mask_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_90_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_58_1 == phase_58_2);
  assert(mask_33_1 == mask_33_2);
  assert(mask_90_1 == mask_90_2);
}

int fn_R001027_2713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001027_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int phase_58 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_58 = ((phase_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_58) & 127;
  }

  int mask_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_33) & 63;
  acc ^= aux;
  int mask_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_90 > 34)
  {
    acc = ((acc + (mask_90 * 2)) + 5) & 127;
    aux ^= mask_90 & 15;
  }
  else
  {
    acc = ((acc - mask_90) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001027_2713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001027_2713_0 st_1 = {0};
  struct EventLog_R001027_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_96_1 > 13)
  {
    acc_1 = ((acc_1 + (stride_96_1 * 2)) + 5) & 127;
    aux_1 ^= stride_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_96_2 > 13)
  {
    acc_2 = ((acc_2 + (stride_96_2 * 2)) + 5) & 127;
    aux_2 ^= stride_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_94_1 = 0;
  int accumulator_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_94_1 = ((accumulator_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_94_2 = ((accumulator_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_94_1) & 127;
    acc_2 = (acc_2 + accumulator_94_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_91_1 = local_arr_1[aux_1 % 3];
  int scale_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_91_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_96_1 == stride_96_2);
  assert(accumulator_94_1 == accumulator_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_91_1 == scale_91_2);
}

int fn_R001027_2713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001027_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_96 > 13)
  {
    acc = ((acc + (stride_96 * 2)) + 5) & 127;
    aux ^= stride_96 & 15;
  }
  else
  {
    acc = ((acc - stride_96) + 11) & 127;
    aux += 3;
  }
  int accumulator_94 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_94 = ((accumulator_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_94) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int scale_91 = local_arr[aux % 3];
  acc = (acc + (scale_91 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001027_2713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001027_2713_0 st_1 = {0};
  struct EventLog_R001027_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_29_1) & 63;
  aux_2 = (aux_2 + threshold_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_37_1 = local_arr_1[aux_1 % 3];
  int window_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_37_2 * 2)) & 127;
  int tally_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_71_1 > 23)
  {
    acc_1 = ((acc_1 + (tally_71_1 * 2)) + 5) & 127;
    aux_1 ^= tally_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_71_2 > 23)
  {
    acc_2 = ((acc_2 + (tally_71_2 * 2)) + 5) & 127;
    aux_2 ^= tally_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_71_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_29_1 == threshold_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_37_1 == window_37_2);
  assert(tally_71_1 == tally_71_2);
}

int fn_R001027_2713_4(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001027_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_29) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_37 = local_arr[aux % 3];
  acc = (acc + (window_37 * 2)) & 127;
  int tally_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_71 > 23)
  {
    acc = ((acc + (tally_71 * 2)) + 5) & 127;
    aux ^= tally_71 & 15;
  }
  else
  {
    acc = ((acc - tally_71) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001027_2713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001027_2713_2 st_1 = {0};
  struct CipherContext_R001027_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int checksum_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_84_1) & 63;
  aux_2 = (aux_2 + checksum_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_41_1)
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

  switch (mask_41_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_76_1 = local_arr_1[aux_1 % 3];
  int metric_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_76_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_84_1 == checksum_84_2);
  assert(mask_41_1 == mask_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_76_1 == metric_76_2);
}

int fn_R001027_2713_5(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001027_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int checksum_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_84) & 63;
  acc ^= aux;
  int mask_41 = (aux + st.buffer[1]) & 3;
  switch (mask_41)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_76 = local_arr[aux % 3];
  acc = (acc + (metric_76 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001027_2713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001027_2713_1 st_1 = {0};
  struct AudioFrame_R001027_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int index_reg_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_20_1) & 63;
  aux_2 = (aux_2 + index_reg_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_50_1 > 23)
  {
    acc_1 = ((acc_1 + (vector_50_1 * 2)) + 5) & 127;
    aux_1 ^= vector_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_50_2 > 23)
  {
    acc_2 = ((acc_2 + (vector_50_2 * 2)) + 5) & 127;
    aux_2 ^= vector_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_53_1 = 0;
  int damping_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_53_1 = ((damping_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_53_2 = ((damping_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_53_1) & 127;
    acc_2 = (acc_2 + damping_53_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_20_1 == index_reg_20_2);
  assert(vector_50_1 == vector_50_2);
  assert(damping_53_1 == damping_53_2);
}

int fn_R001027_2713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001027_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int index_reg_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_20) & 63;
  acc ^= aux;
  int vector_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_50 > 23)
  {
    acc = ((acc + (vector_50 * 2)) + 5) & 127;
    aux ^= vector_50 & 15;
  }
  else
  {
    acc = ((acc - vector_50) + 11) & 127;
    aux += 3;
  }
  int damping_53 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_53 = ((damping_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_53) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001027_2713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001027_2713_1 st_1 = {0};
  struct AudioFrame_R001027_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int delta_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_89_1 > 44)
  {
    acc_1 = ((acc_1 + (delta_89_1 * 2)) + 5) & 127;
    aux_1 ^= delta_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_89_2 > 44)
  {
    acc_2 = ((acc_2 + (delta_89_2 * 2)) + 5) & 127;
    aux_2 ^= delta_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_89_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_47_1)
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

  switch (parity_47_2)
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

  int stride_23_1 = 0;
  int stride_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_23_1 = ((stride_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_23_2 = ((stride_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_23_1) & 127;
    acc_2 = (acc_2 + stride_23_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_89_1 == delta_89_2);
  assert(parity_47_1 == parity_47_2);
  assert(stride_23_1 == stride_23_2);
}

int fn_R001027_2713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001027_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int delta_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_89 > 44)
  {
    acc = ((acc + (delta_89 * 2)) + 5) & 127;
    aux ^= delta_89 & 15;
  }
  else
  {
    acc = ((acc - delta_89) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_47 = (aux + st.buffer[1]) & 3;
  switch (parity_47)
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

  int stride_23 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_23 = ((stride_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_23) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001027_2713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001027_2713_2 st_1 = {0};
  struct CipherContext_R001027_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int segment_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_83_1)
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

  switch (segment_83_2)
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

  int metric_11_1 = 0;
  int metric_11_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_11_1 = ((metric_11_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_11_2 = ((metric_11_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_11_1) & 127;
    acc_2 = (acc_2 + metric_11_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_83_1 == segment_83_2);
  assert(metric_11_1 == metric_11_2);
}

int fn_R001027_2713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001027_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int segment_83 = (aux + st.buffer[1]) & 3;
  switch (segment_83)
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

  int metric_11 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_11 = ((metric_11 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_11) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001027_2713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001027_2713_2 st_1 = {0};
  struct CipherContext_R001027_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_15_1 = 0;
  int accumulator_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_15_1 = ((accumulator_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_15_2 = ((accumulator_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_15_1) & 127;
    acc_2 = (acc_2 + accumulator_15_2) & 127;
  }

  int anchor_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_63_1 > 27)
  {
    acc_1 = ((acc_1 + (anchor_63_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_63_2 > 27)
  {
    acc_2 = ((acc_2 + (anchor_63_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_22_1) & 63;
  aux_2 = (aux_2 + accumulator_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_15_1 == accumulator_15_2);
  assert(anchor_63_1 == anchor_63_2);
  assert(accumulator_22_1 == accumulator_22_2);
}

int fn_R001027_2713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001027_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_15 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_15 = ((accumulator_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_15) & 127;
  }

  int anchor_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_63 > 27)
  {
    acc = ((acc + (anchor_63 * 2)) + 5) & 127;
    aux ^= anchor_63 & 15;
  }
  else
  {
    acc = ((acc - anchor_63) + 11) & 127;
    aux += 3;
  }
  int accumulator_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_22) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001027_2713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001027_2713_0 st_1 = {0};
  struct EventLog_R001027_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int vector_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_73_1)
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

  switch (vector_73_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_43_1) & 63;
  aux_2 = (aux_2 + offset_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_91_1 > 32)
  {
    acc_1 = ((acc_1 + (anchor_91_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_91_2 > 32)
  {
    acc_2 = ((acc_2 + (anchor_91_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_91_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_73_1 == vector_73_2);
  assert(offset_43_1 == offset_43_2);
  assert(anchor_91_1 == anchor_91_2);
}

int fn_R001027_2713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001027_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int vector_73 = (aux + st.buffer[1]) & 3;
  switch (vector_73)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_43) & 63;
  acc ^= aux;
  int anchor_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_91 > 32)
  {
    acc = ((acc + (anchor_91 * 2)) + 5) & 127;
    aux ^= anchor_91 & 15;
  }
  else
  {
    acc = ((acc - anchor_91) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001027_2713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001027_2713_2 st_1 = {0};
  struct CipherContext_R001027_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int segment_59_1 = 0;
  int segment_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_59_1 = ((segment_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_59_2 = ((segment_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_59_1) & 127;
    acc_2 = (acc_2 + segment_59_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_24_1) & 63;
  aux_2 = (aux_2 + phase_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_59_1 == segment_59_2);
  assert(phase_24_1 == phase_24_2);
}

int fn_R001027_2713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001027_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int segment_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_59 = ((segment_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_59) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_24) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001027_2713_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001027_2713_0 st_1 = {0};
  struct EventLog_R001027_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int segment_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_77_1 > 34)
  {
    acc_1 = ((acc_1 + (segment_77_1 * 2)) + 5) & 127;
    aux_1 ^= segment_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_77_2 > 34)
  {
    acc_2 = ((acc_2 + (segment_77_2 * 2)) + 5) & 127;
    aux_2 ^= segment_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_62_1) & 63;
  aux_2 = (aux_2 + tally_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_77_1 == segment_77_2);
  assert(tally_62_1 == tally_62_2);
}

int fn_R001027_2713_12(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001027_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int segment_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_77 > 34)
  {
    acc = ((acc + (segment_77 * 2)) + 5) & 127;
    aux ^= segment_77 & 15;
  }
  else
  {
    acc = ((acc - segment_77) + 11) & 127;
    aux += 3;
  }
  int tally_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_62) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001027_2713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001027_2713_1 st_1 = {0};
  struct AudioFrame_R001027_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int offset_81_1 = 0;
  int offset_81_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_81_1 = ((offset_81_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_81_2 = ((offset_81_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_81_1) & 127;
    acc_2 = (acc_2 + offset_81_2) & 127;
  }

  int sample_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_32_1) & 63;
  aux_2 = (aux_2 + sample_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_58_1 > 29)
  {
    acc_1 = ((acc_1 + (bound_58_1 * 2)) + 5) & 127;
    aux_1 ^= bound_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_58_2 > 29)
  {
    acc_2 = ((acc_2 + (bound_58_2 * 2)) + 5) & 127;
    aux_2 ^= bound_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_58_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_81_1 == offset_81_2);
  assert(sample_32_1 == sample_32_2);
  assert(bound_58_1 == bound_58_2);
}

int fn_R001027_2713_13(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001027_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int offset_81 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_81 = ((offset_81 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_81) & 127;
  }

  int sample_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_32) & 63;
  acc ^= aux;
  int bound_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_58 > 29)
  {
    acc = ((acc + (bound_58 * 2)) + 5) & 127;
    aux ^= bound_58 & 15;
  }
  else
  {
    acc = ((acc - bound_58) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001027_0_1;
  int sec_r001027_0_2;
  int sec_r001027_1_1;
  int sec_r001027_1_2;
  int sec_r001027_2_1;
  int sec_r001027_2_2;
  int sec_r001027_3_1;
  int sec_r001027_3_2;
  int sec_r001027_4_1;
  int sec_r001027_4_2;
  int sec_r001027_5_1;
  int sec_r001027_5_2;
  int sec_r001027_6_1;
  int sec_r001027_6_2;
  int sec_r001027_7_1;
  int sec_r001027_7_2;
  int sec_r001027_8_1;
  int sec_r001027_8_2;
  int sec_r001027_9_1;
  int sec_r001027_9_2;
  int sec_r001027_10_1;
  int sec_r001027_10_2;
  int sec_r001027_11_1;
  int sec_r001027_11_2;
  int sec_r001027_12_1;
  int sec_r001027_12_2;
  int sec_r001027_13_1;
  int sec_r001027_13_2;
  int sec_r001027_14_1;
  int sec_r001027_14_2;
  int sec_r001027_15_1;
  int sec_r001027_15_2;
  int sec_r001027_16_1;
  int sec_r001027_16_2;
  int pub_r001027_0_1;
  int pub_r001027_0_2;
  int pub_r001027_1_1;
  int pub_r001027_1_2;
  int pub_r001027_2_1;
  int pub_r001027_2_2;
  int pub_r001027_3_1;
  int pub_r001027_3_2;
  int pub_r001027_4_1;
  int pub_r001027_4_2;
  int pub_r001027_5_1;
  int pub_r001027_5_2;
  int pub_r001027_6_1;
  int pub_r001027_6_2;
  int pub_r001027_7_1;
  int pub_r001027_7_2;
  int pub_r001027_8_1;
  int pub_r001027_8_2;
  int pub_r001027_9_1;
  int pub_r001027_9_2;
  int pub_r001027_10_1;
  int pub_r001027_10_2;
  int pub_r001027_11_1;
  int pub_r001027_11_2;
  int pub_r001027_12_1;
  int pub_r001027_12_2;
  int pub_r001027_13_1;
  int pub_r001027_13_2;
  int pub_r001027_14_1;
  int pub_r001027_14_2;
  int pub_r001027_15_1;
  int pub_r001027_15_2;
  int pub_r001027_16_1;
  int pub_r001027_16_2;
  int pub_r001027_17_1;
  int pub_r001027_17_2;
  int pub_r001027_18_1;
  int pub_r001027_18_2;
  int pub_r001027_19_1;
  int pub_r001027_19_2;
  int pub_r001027_20_1;
  int pub_r001027_20_2;
  int pub_r001027_21_1;
  int pub_r001027_21_2;
  int pub_r001027_22_1;
  int pub_r001027_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001027_0_1 >= (-100)) && (pub_r001027_0_1 <= 100));
  __CPROVER_assume((pub_r001027_0_2 >= (-100)) && (pub_r001027_0_2 <= 100));
  __CPROVER_assume((pub_r001027_1_1 >= (-100)) && (pub_r001027_1_1 <= 100));
  __CPROVER_assume((pub_r001027_1_2 >= (-100)) && (pub_r001027_1_2 <= 100));
  __CPROVER_assume((pub_r001027_2_1 >= (-100)) && (pub_r001027_2_1 <= 100));
  __CPROVER_assume((pub_r001027_2_2 >= (-100)) && (pub_r001027_2_2 <= 100));
  __CPROVER_assume((pub_r001027_3_1 >= (-100)) && (pub_r001027_3_1 <= 100));
  __CPROVER_assume((pub_r001027_3_2 >= (-100)) && (pub_r001027_3_2 <= 100));
  __CPROVER_assume((pub_r001027_4_1 >= (-100)) && (pub_r001027_4_1 <= 100));
  __CPROVER_assume((pub_r001027_4_2 >= (-100)) && (pub_r001027_4_2 <= 100));
  __CPROVER_assume((pub_r001027_5_1 >= (-100)) && (pub_r001027_5_1 <= 100));
  __CPROVER_assume((pub_r001027_5_2 >= (-100)) && (pub_r001027_5_2 <= 100));
  __CPROVER_assume((pub_r001027_6_1 >= (-100)) && (pub_r001027_6_1 <= 100));
  __CPROVER_assume((pub_r001027_6_2 >= (-100)) && (pub_r001027_6_2 <= 100));
  __CPROVER_assume((pub_r001027_7_1 >= (-100)) && (pub_r001027_7_1 <= 100));
  __CPROVER_assume((pub_r001027_7_2 >= (-100)) && (pub_r001027_7_2 <= 100));
  __CPROVER_assume((pub_r001027_8_1 >= (-100)) && (pub_r001027_8_1 <= 100));
  __CPROVER_assume((pub_r001027_8_2 >= (-100)) && (pub_r001027_8_2 <= 100));
  __CPROVER_assume((pub_r001027_9_1 >= (-100)) && (pub_r001027_9_1 <= 100));
  __CPROVER_assume((pub_r001027_9_2 >= (-100)) && (pub_r001027_9_2 <= 100));
  __CPROVER_assume((pub_r001027_10_1 >= (-100)) && (pub_r001027_10_1 <= 100));
  __CPROVER_assume((pub_r001027_10_2 >= (-100)) && (pub_r001027_10_2 <= 100));
  __CPROVER_assume((pub_r001027_11_1 >= (-100)) && (pub_r001027_11_1 <= 100));
  __CPROVER_assume((pub_r001027_11_2 >= (-100)) && (pub_r001027_11_2 <= 100));
  __CPROVER_assume((pub_r001027_12_1 >= (-100)) && (pub_r001027_12_1 <= 100));
  __CPROVER_assume((pub_r001027_12_2 >= (-100)) && (pub_r001027_12_2 <= 100));
  __CPROVER_assume((pub_r001027_13_1 >= (-100)) && (pub_r001027_13_1 <= 100));
  __CPROVER_assume((pub_r001027_13_2 >= (-100)) && (pub_r001027_13_2 <= 100));
  __CPROVER_assume((pub_r001027_14_1 >= (-100)) && (pub_r001027_14_1 <= 100));
  __CPROVER_assume((pub_r001027_14_2 >= (-100)) && (pub_r001027_14_2 <= 100));
  __CPROVER_assume((pub_r001027_15_1 >= (-100)) && (pub_r001027_15_1 <= 100));
  __CPROVER_assume((pub_r001027_15_2 >= (-100)) && (pub_r001027_15_2 <= 100));
  __CPROVER_assume((pub_r001027_16_1 >= (-100)) && (pub_r001027_16_1 <= 100));
  __CPROVER_assume((pub_r001027_16_2 >= (-100)) && (pub_r001027_16_2 <= 100));
  __CPROVER_assume((pub_r001027_17_1 >= (-100)) && (pub_r001027_17_1 <= 100));
  __CPROVER_assume((pub_r001027_17_2 >= (-100)) && (pub_r001027_17_2 <= 100));
  __CPROVER_assume((pub_r001027_18_1 >= (-100)) && (pub_r001027_18_1 <= 100));
  __CPROVER_assume((pub_r001027_18_2 >= (-100)) && (pub_r001027_18_2 <= 100));
  __CPROVER_assume((pub_r001027_19_1 >= (-100)) && (pub_r001027_19_1 <= 100));
  __CPROVER_assume((pub_r001027_19_2 >= (-100)) && (pub_r001027_19_2 <= 100));
  __CPROVER_assume((pub_r001027_20_1 >= (-100)) && (pub_r001027_20_1 <= 100));
  __CPROVER_assume((pub_r001027_20_2 >= (-100)) && (pub_r001027_20_2 <= 100));
  __CPROVER_assume((pub_r001027_21_1 >= (-100)) && (pub_r001027_21_1 <= 100));
  __CPROVER_assume((pub_r001027_21_2 >= (-100)) && (pub_r001027_21_2 <= 100));
  __CPROVER_assume((pub_r001027_22_1 >= (-100)) && (pub_r001027_22_1 <= 100));
  __CPROVER_assume((pub_r001027_22_2 >= (-100)) && (pub_r001027_22_2 <= 100));
  __CPROVER_assume((sec_r001027_0_1 >= 0) && (sec_r001027_0_1 <= 255));
  __CPROVER_assume((sec_r001027_0_2 >= 0) && (sec_r001027_0_2 <= 255));
  __CPROVER_assume((sec_r001027_1_1 >= 0) && (sec_r001027_1_1 <= 255));
  __CPROVER_assume((sec_r001027_1_2 >= 0) && (sec_r001027_1_2 <= 255));
  __CPROVER_assume((sec_r001027_2_1 >= 0) && (sec_r001027_2_1 <= 255));
  __CPROVER_assume((sec_r001027_2_2 >= 0) && (sec_r001027_2_2 <= 255));
  __CPROVER_assume((sec_r001027_3_1 >= 0) && (sec_r001027_3_1 <= 255));
  __CPROVER_assume((sec_r001027_3_2 >= 0) && (sec_r001027_3_2 <= 255));
  __CPROVER_assume((sec_r001027_4_1 >= 0) && (sec_r001027_4_1 <= 255));
  __CPROVER_assume((sec_r001027_4_2 >= 0) && (sec_r001027_4_2 <= 255));
  __CPROVER_assume((sec_r001027_5_1 >= 0) && (sec_r001027_5_1 <= 255));
  __CPROVER_assume((sec_r001027_5_2 >= 0) && (sec_r001027_5_2 <= 255));
  __CPROVER_assume((sec_r001027_6_1 >= 0) && (sec_r001027_6_1 <= 255));
  __CPROVER_assume((sec_r001027_6_2 >= 0) && (sec_r001027_6_2 <= 255));
  __CPROVER_assume((sec_r001027_7_1 >= 0) && (sec_r001027_7_1 <= 255));
  __CPROVER_assume((sec_r001027_7_2 >= 0) && (sec_r001027_7_2 <= 255));
  __CPROVER_assume((sec_r001027_8_1 >= 0) && (sec_r001027_8_1 <= 255));
  __CPROVER_assume((sec_r001027_8_2 >= 0) && (sec_r001027_8_2 <= 255));
  __CPROVER_assume((sec_r001027_9_1 >= 0) && (sec_r001027_9_1 <= 255));
  __CPROVER_assume((sec_r001027_9_2 >= 0) && (sec_r001027_9_2 <= 255));
  __CPROVER_assume((sec_r001027_10_1 >= 0) && (sec_r001027_10_1 <= 255));
  __CPROVER_assume((sec_r001027_10_2 >= 0) && (sec_r001027_10_2 <= 255));
  __CPROVER_assume((sec_r001027_11_1 >= 0) && (sec_r001027_11_1 <= 255));
  __CPROVER_assume((sec_r001027_11_2 >= 0) && (sec_r001027_11_2 <= 255));
  __CPROVER_assume((sec_r001027_12_1 >= 0) && (sec_r001027_12_1 <= 255));
  __CPROVER_assume((sec_r001027_12_2 >= 0) && (sec_r001027_12_2 <= 255));
  __CPROVER_assume((sec_r001027_13_1 >= 0) && (sec_r001027_13_1 <= 255));
  __CPROVER_assume((sec_r001027_13_2 >= 0) && (sec_r001027_13_2 <= 255));
  __CPROVER_assume((sec_r001027_14_1 >= 0) && (sec_r001027_14_1 <= 255));
  __CPROVER_assume((sec_r001027_14_2 >= 0) && (sec_r001027_14_2 <= 255));
  __CPROVER_assume((sec_r001027_15_1 >= 0) && (sec_r001027_15_1 <= 255));
  __CPROVER_assume((sec_r001027_15_2 >= 0) && (sec_r001027_15_2 <= 255));
  __CPROVER_assume((sec_r001027_16_1 >= 0) && (sec_r001027_16_1 <= 255));
  __CPROVER_assume((sec_r001027_16_2 >= 0) && (sec_r001027_16_2 <= 255));
  struct EventLog_R001027_2713_0 st_var_0_1 = {0};
  struct EventLog_R001027_2713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001027_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001027_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001027_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001027_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001027_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001027_0_2 + 7) & 15;
  struct AudioFrame_R001027_2713_1 st_var_1_1 = {0};
  struct AudioFrame_R001027_2713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001027_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001027_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001027_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001027_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001027_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001027_0_2 + 9) & 15;
  struct CipherContext_R001027_2713_2 st_var_2_1 = {0};
  struct CipherContext_R001027_2713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001027_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001027_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001027_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001027_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001027_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001027_0_2 + 11) & 15;
  union ColorPixel_R001027_2713_0 u_var_1;
  union ColorPixel_R001027_2713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001027_2713_0(sec_r001027_0_1, pub_r001027_1_1, pub_r001027_2_1, pub_r001027_3_1);
  int helper_flow_0_2 = fn_R001027_2713_0(sec_r001027_0_2, pub_r001027_1_2, pub_r001027_2_2, pub_r001027_3_2);
  fn_R001027_2713_0_2(sec_r001027_0_1, pub_r001027_1_1, pub_r001027_2_1, pub_r001027_3_1, sec_r001027_0_2, pub_r001027_1_2, pub_r001027_2_2, pub_r001027_3_2);
  int helper_flow_1_1 = fn_R001027_2713_1(sec_r001027_1_1, pub_r001027_2_1, pub_r001027_3_1);
  int helper_flow_1_2 = fn_R001027_2713_1(sec_r001027_1_2, pub_r001027_2_2, pub_r001027_3_2);
  fn_R001027_2713_1_2(sec_r001027_1_1, pub_r001027_2_1, pub_r001027_3_1, sec_r001027_1_2, pub_r001027_2_2, pub_r001027_3_2);
  int helper_flow_2_1 = fn_R001027_2713_2(sec_r001027_2_1, pub_r001027_3_1, pub_r001027_4_1);
  int helper_flow_2_2 = fn_R001027_2713_2(sec_r001027_2_2, pub_r001027_3_2, pub_r001027_4_2);
  fn_R001027_2713_2_2(sec_r001027_2_1, pub_r001027_3_1, pub_r001027_4_1, sec_r001027_2_2, pub_r001027_3_2, pub_r001027_4_2);
  int helper_flow_3_1 = fn_R001027_2713_3(sec_r001027_3_1, sec_r001027_4_1, pub_r001027_5_1);
  int helper_flow_3_2 = fn_R001027_2713_3(sec_r001027_3_2, sec_r001027_4_2, pub_r001027_5_2);
  fn_R001027_2713_3_2(sec_r001027_3_1, sec_r001027_4_1, pub_r001027_5_1, sec_r001027_3_2, sec_r001027_4_2, pub_r001027_5_2);
  int helper_flow_4_1 = fn_R001027_2713_4(sec_r001027_4_1, sec_r001027_5_1);
  int helper_flow_4_2 = fn_R001027_2713_4(sec_r001027_4_2, sec_r001027_5_2);
  fn_R001027_2713_4_2(sec_r001027_4_1, sec_r001027_5_1, sec_r001027_4_2, sec_r001027_5_2);
  int helper_flow_5_1 = fn_R001027_2713_5(sec_r001027_5_1, pub_r001027_6_1);
  int helper_flow_5_2 = fn_R001027_2713_5(sec_r001027_5_2, pub_r001027_6_2);
  fn_R001027_2713_5_2(sec_r001027_5_1, pub_r001027_6_1, sec_r001027_5_2, pub_r001027_6_2);
  int helper_flow_6_1 = fn_R001027_2713_6(sec_r001027_6_1, sec_r001027_7_1, pub_r001027_8_1, pub_r001027_9_1);
  int helper_flow_6_2 = fn_R001027_2713_6(sec_r001027_6_2, sec_r001027_7_2, pub_r001027_8_2, pub_r001027_9_2);
  fn_R001027_2713_6_2(sec_r001027_6_1, sec_r001027_7_1, pub_r001027_8_1, pub_r001027_9_1, sec_r001027_6_2, sec_r001027_7_2, pub_r001027_8_2, pub_r001027_9_2);
  int helper_flow_7_1 = fn_R001027_2713_7(sec_r001027_7_1, pub_r001027_8_1, pub_r001027_9_1, pub_r001027_10_1, pub_r001027_11_1);
  int helper_flow_7_2 = fn_R001027_2713_7(sec_r001027_7_2, pub_r001027_8_2, pub_r001027_9_2, pub_r001027_10_2, pub_r001027_11_2);
  fn_R001027_2713_7_2(sec_r001027_7_1, pub_r001027_8_1, pub_r001027_9_1, pub_r001027_10_1, pub_r001027_11_1, sec_r001027_7_2, pub_r001027_8_2, pub_r001027_9_2, pub_r001027_10_2, pub_r001027_11_2);
  int helper_flow_8_1 = fn_R001027_2713_8(sec_r001027_8_1, pub_r001027_9_1, pub_r001027_10_1, pub_r001027_11_1, pub_r001027_12_1);
  int helper_flow_8_2 = fn_R001027_2713_8(sec_r001027_8_2, pub_r001027_9_2, pub_r001027_10_2, pub_r001027_11_2, pub_r001027_12_2);
  fn_R001027_2713_8_2(sec_r001027_8_1, pub_r001027_9_1, pub_r001027_10_1, pub_r001027_11_1, pub_r001027_12_1, sec_r001027_8_2, pub_r001027_9_2, pub_r001027_10_2, pub_r001027_11_2, pub_r001027_12_2);
  int helper_flow_9_1 = fn_R001027_2713_9(sec_r001027_9_1, sec_r001027_10_1, pub_r001027_11_1, pub_r001027_12_1, pub_r001027_13_1);
  int helper_flow_9_2 = fn_R001027_2713_9(sec_r001027_9_2, sec_r001027_10_2, pub_r001027_11_2, pub_r001027_12_2, pub_r001027_13_2);
  fn_R001027_2713_9_2(sec_r001027_9_1, sec_r001027_10_1, pub_r001027_11_1, pub_r001027_12_1, pub_r001027_13_1, sec_r001027_9_2, sec_r001027_10_2, pub_r001027_11_2, pub_r001027_12_2, pub_r001027_13_2);
  int stage_v_0_1 = (sec_r001027_6_1 ^ pub_r001027_6_1) & 63;
  int stage_v_0_2 = (sec_r001027_6_2 ^ pub_r001027_6_2) & 63;
  if ((stage_v_0_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_0_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_0_1 * 2)) & 255;
  }
  if ((stage_v_0_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_0_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_0_2 * 2)) & 255;
  }
  int stage_v_1_1 = (helper_flow_8_1 ^ pub_r001027_5_1) & 63;
  int stage_v_1_2 = (helper_flow_8_2 ^ pub_r001027_5_2) & 63;
  if ((stage_v_1_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_1_1 * 2)) & 255;
  }
  if ((stage_v_1_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_1_2 * 2)) & 255;
  }
  int stage_v_2_1 = (sec_r001027_7_1 ^ pub_r001027_20_1) & 63;
  int stage_v_2_2 = (sec_r001027_7_2 ^ pub_r001027_20_2) & 63;
  if ((stage_v_2_1 & 1) != 0)
  {
    if ((helper_flow_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_2_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_2_1 * 2)) & 255;
  }
  if ((stage_v_2_2 & 1) != 0)
  {
    if ((helper_flow_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_2_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_2_2 * 2)) & 255;
  }
  int stage_v_3_1 = (helper_flow_0_1 ^ pub_r001027_11_1) & 63;
  int stage_v_3_2 = (helper_flow_0_2 ^ pub_r001027_11_2) & 63;
  if ((stage_v_3_1 & 1) != 0)
  {
    if ((stage_v_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_3_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_3_1 * 2)) & 255;
  }
  if ((stage_v_3_2 & 1) != 0)
  {
    if ((stage_v_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_3_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_3_2 * 2)) & 255;
  }
  int stage_v_4_1 = (sec_r001027_3_1 ^ pub_r001027_1_1) & 63;
  int stage_v_4_2 = (sec_r001027_3_2 ^ pub_r001027_1_2) & 63;
  if ((stage_v_4_1 & 1) != 0)
  {
    if ((sec_r001027_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_4_1 * 2)) & 255;
  }
  if ((stage_v_4_2 & 1) != 0)
  {
    if ((sec_r001027_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_4_2 * 2)) & 255;
  }
  int stage_v_5_1 = (stage_v_4_1 ^ pub_r001027_1_1) & 63;
  int stage_v_5_2 = (stage_v_4_2 ^ pub_r001027_1_2) & 63;
  if ((stage_v_5_1 & 1) != 0)
  {
    if ((helper_flow_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_5_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_5_1 * 2)) & 255;
  }
  if ((stage_v_5_2 & 1) != 0)
  {
    if ((helper_flow_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_5_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_5_2 * 2)) & 255;
  }
  int stage_v_6_1 = ((pub_r001027_13_1 * 2) + 7) & 63;
  int stage_v_6_2 = ((pub_r001027_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (sec_r001027_12_1 ^ pub_r001027_22_1) & 63;
  int stage_v_7_2 = (sec_r001027_12_2 ^ pub_r001027_22_2) & 63;
  if ((stage_v_7_1 & 1) != 0)
  {
    if ((sec_r001027_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_7_1 * 2)) & 255;
  }
  if ((stage_v_7_2 & 1) != 0)
  {
    if ((sec_r001027_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_7_2 * 2)) & 255;
  }
  int stage_v_8_1 = ((pub_r001027_14_1 * 2) + 30) & 63;
  int stage_v_8_2 = ((pub_r001027_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (sec_r001027_16_1 ^ pub_r001027_16_1) & 63;
  int stage_v_9_2 = (sec_r001027_16_2 ^ pub_r001027_16_2) & 63;
  if ((stage_v_9_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_9_1 * 2)) & 255;
  }
  if ((stage_v_9_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_9_2 * 2)) & 255;
  }
  int stage_v_10_1 = ((pub_r001027_1_1 * 2) + 20) & 63;
  int stage_v_10_2 = ((pub_r001027_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (helper_flow_0_1 ^ pub_r001027_15_1) & 63;
  int stage_v_11_2 = (helper_flow_0_2 ^ pub_r001027_15_2) & 63;
  if ((stage_v_11_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_11_1 * 2)) & 255;
  }
  if ((stage_v_11_2 & 1) != 0)
  {
    if ((helper_flow_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_11_2 * 2)) & 255;
  }
  int stage_v_12_1 = ((pub_r001027_11_1 * 2) + 36) & 63;
  int stage_v_12_2 = ((pub_r001027_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001027_17_1 * 2) + 17) & 63;
  int stage_v_13_2 = ((pub_r001027_17_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001027_7_1 * 2) + 48) & 63;
  int stage_v_14_2 = ((pub_r001027_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001027_6_1 * 2) + 33) & 63;
  int stage_v_15_2 = ((pub_r001027_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (sec_r001027_14_1 ^ pub_r001027_9_1) & 63;
  int stage_v_16_2 = (sec_r001027_14_2 ^ pub_r001027_9_2) & 63;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((sec_r001027_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_16_1 * 2)) & 255;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((sec_r001027_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_16_2 * 2)) & 255;
  }
  int stage_v_17_1 = (helper_flow_1_1 ^ pub_r001027_5_1) & 63;
  int stage_v_17_2 = (helper_flow_1_2 ^ pub_r001027_5_2) & 63;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((stage_v_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_17_1 * 2)) & 255;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((stage_v_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_17_2 * 2)) & 255;
  }
  int stage_v_18_1 = (sec_r001027_5_1 ^ pub_r001027_10_1) & 63;
  int stage_v_18_2 = (sec_r001027_5_2 ^ pub_r001027_10_2) & 63;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((stage_v_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_18_1 * 2)) & 255;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((stage_v_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_18_2 * 2)) & 255;
  }
  int stage_v_19_1 = (helper_flow_4_1 ^ pub_r001027_15_1) & 63;
  int stage_v_19_2 = (helper_flow_4_2 ^ pub_r001027_15_2) & 63;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r001027_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_19_1 * 2)) & 255;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r001027_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_19_2 * 2)) & 255;
  }
  int stage_v_20_1 = (sec_r001027_11_1 ^ pub_r001027_3_1) & 63;
  int stage_v_20_2 = (sec_r001027_11_2 ^ pub_r001027_3_2) & 63;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r001027_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_20_1 * 2)) & 255;
  }
  if ((stage_v_20_2 & 1) != 0)
  {
    if ((sec_r001027_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_20_2 * 2)) & 255;
  }
  int stage_v_21_1 = (sec_r001027_10_1 ^ pub_r001027_8_1) & 63;
  int stage_v_21_2 = (sec_r001027_10_2 ^ pub_r001027_8_2) & 63;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((sec_r001027_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_21_1 * 2)) & 255;
  }
  if ((stage_v_21_2 & 1) != 0)
  {
    if ((sec_r001027_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_21_2 * 2)) & 255;
  }
  int stage_v_22_1 = (sec_r001027_6_1 ^ pub_r001027_2_1) & 63;
  int stage_v_22_2 = (sec_r001027_6_2 ^ pub_r001027_2_2) & 63;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_22_1 * 2)) & 255;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((stage_v_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_22_2 * 2)) & 255;
  }
  int stage_v_23_1 = (stage_v_4_1 ^ pub_r001027_19_1) & 63;
  int stage_v_23_2 = (stage_v_4_2 ^ pub_r001027_19_2) & 63;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r001027_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_23_1 * 2)) & 255;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r001027_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_23_2 * 2)) & 255;
  }
  int stage_v_24_1 = ((pub_r001027_15_1 * 2) + 45) & 63;
  int stage_v_24_2 = ((pub_r001027_15_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001027_18_1 * 2) + 14) & 63;
  int stage_v_25_2 = ((pub_r001027_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (stage_v_5_1 ^ pub_r001027_22_1) & 63;
  int stage_v_26_2 = (stage_v_5_2 ^ pub_r001027_22_2) & 63;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((stage_v_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_26_1 * 2)) & 255;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((stage_v_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_26_2 * 2)) & 255;
  }
  int stage_v_27_1 = (sec_r001027_1_1 ^ pub_r001027_20_1) & 63;
  int stage_v_27_2 = (sec_r001027_1_2 ^ pub_r001027_20_2) & 63;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_27_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_27_1 * 2)) & 255;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((helper_flow_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_27_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_27_2 * 2)) & 255;
  }
  int stage_v_28_1 = (sec_r001027_8_1 ^ pub_r001027_0_1) & 63;
  int stage_v_28_2 = (sec_r001027_8_2 ^ pub_r001027_0_2) & 63;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r001027_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_28_1 * 2)) & 255;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r001027_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_28_2 * 2)) & 255;
  }
  int stage_v_29_1 = ((pub_r001027_9_1 * 2) + 38) & 63;
  int stage_v_29_2 = ((pub_r001027_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (sec_r001027_6_1 ^ pub_r001027_17_1) & 63;
  int stage_v_30_2 = (sec_r001027_6_2 ^ pub_r001027_17_2) & 63;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r001027_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_30_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_30_1 * 2)) & 255;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r001027_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_30_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_30_2 * 2)) & 255;
  }
  int stage_v_31_1 = (sec_r001027_13_1 ^ pub_r001027_0_1) & 63;
  int stage_v_31_2 = (sec_r001027_13_2 ^ pub_r001027_0_2) & 63;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r001027_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_31_1 * 2)) & 255;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r001027_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_31_2 * 2)) & 255;
  }
  int stage_v_32_1 = ((pub_r001027_1_1 * 2) + 11) & 63;
  int stage_v_32_2 = ((pub_r001027_1_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (stage_v_19_1 ^ pub_r001027_17_1) & 63;
  int stage_v_33_2 = (stage_v_19_2 ^ pub_r001027_17_2) & 63;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r001027_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_33_1 * 2)) & 255;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r001027_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_33_2 * 2)) & 255;
  }
  int stage_v_34_1 = ((pub_r001027_18_1 * 2) + 9) & 63;
  int stage_v_34_2 = ((pub_r001027_18_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = (sec_r001027_4_1 ^ pub_r001027_20_1) & 63;
  int stage_v_35_2 = (sec_r001027_4_2 ^ pub_r001027_20_2) & 63;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r001027_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_35_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_35_1 * 2)) & 255;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r001027_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_35_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_35_2 * 2)) & 255;
  }
  int stage_v_36_1 = (stage_v_4_1 ^ pub_r001027_21_1) & 63;
  int stage_v_36_2 = (stage_v_4_2 ^ pub_r001027_21_2) & 63;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r001027_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_36_1 * 2)) & 255;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r001027_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_36_2 * 2)) & 255;
  }
  int stage_v_37_1 = (stage_v_3_1 ^ pub_r001027_2_1) & 63;
  int stage_v_37_2 = (stage_v_3_2 ^ pub_r001027_2_2) & 63;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r001027_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_37_1 * 2)) & 255;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r001027_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_37_2 * 2)) & 255;
  }
  int stage_v_38_1 = (stage_v_11_1 ^ pub_r001027_4_1) & 63;
  int stage_v_38_2 = (stage_v_11_2 ^ pub_r001027_4_2) & 63;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_38_1 * 2)) & 255;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((stage_v_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_38_2 * 2)) & 255;
  }
  int stage_v_39_1 = ((pub_r001027_14_1 * 2) + 15) & 63;
  int stage_v_39_2 = ((pub_r001027_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (helper_flow_7_1 ^ pub_r001027_9_1) & 63;
  int stage_v_40_2 = (helper_flow_7_2 ^ pub_r001027_9_2) & 63;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_40_1 * 2)) & 255;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((helper_flow_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_40_2 * 2)) & 255;
  }
  int stage_v_41_1 = (sec_r001027_16_1 ^ pub_r001027_21_1) & 63;
  int stage_v_41_2 = (sec_r001027_16_2 ^ pub_r001027_21_2) & 63;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_41_1 * 2)) & 255;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((helper_flow_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_41_2 * 2)) & 255;
  }
  int stage_v_42_1 = (stage_v_16_1 ^ pub_r001027_19_1) & 63;
  int stage_v_42_2 = (stage_v_16_2 ^ pub_r001027_19_2) & 63;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_42_1 * 2)) & 255;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((stage_v_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_42_2 * 2)) & 255;
  }
  int stage_v_43_1 = ((pub_r001027_20_1 * 2) + 8) & 63;
  int stage_v_43_2 = ((pub_r001027_20_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (sec_r001027_12_1 ^ pub_r001027_0_1) & 63;
  int stage_v_44_2 = (sec_r001027_12_2 ^ pub_r001027_0_2) & 63;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((stage_v_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_44_1 * 2)) & 255;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((stage_v_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_44_2 * 2)) & 255;
  }
  int stage_v_45_1 = (helper_flow_4_1 ^ pub_r001027_5_1) & 63;
  int stage_v_45_2 = (helper_flow_4_2 ^ pub_r001027_5_2) & 63;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((stage_v_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_45_1 * 2)) & 255;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((stage_v_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_45_2 * 2)) & 255;
  }
  int stage_v_46_1 = (stage_v_5_1 ^ pub_r001027_2_1) & 63;
  int stage_v_46_2 = (stage_v_5_2 ^ pub_r001027_2_2) & 63;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((stage_v_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_46_1 * 2)) & 255;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((stage_v_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_46_2 * 2)) & 255;
  }
  int stage_v_47_1 = (sec_r001027_10_1 ^ pub_r001027_3_1) & 63;
  int stage_v_47_2 = (sec_r001027_10_2 ^ pub_r001027_3_2) & 63;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_47_1 * 2)) & 255;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((stage_v_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_47_2 * 2)) & 255;
  }
  int stage_v_48_1 = ((pub_r001027_21_1 * 2) + 36) & 63;
  int stage_v_48_2 = ((pub_r001027_21_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (sec_r001027_6_1 ^ pub_r001027_12_1) & 63;
  int stage_v_49_2 = (sec_r001027_6_2 ^ pub_r001027_12_2) & 63;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r001027_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_49_1 * 2)) & 255;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r001027_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_49_2 * 2)) & 255;
  }
  int stage_v_50_1 = ((pub_r001027_20_1 * 2) + 26) & 63;
  int stage_v_50_2 = ((pub_r001027_20_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (stage_v_5_1 ^ pub_r001027_7_1) & 63;
  int stage_v_51_2 = (stage_v_5_2 ^ pub_r001027_7_2) & 63;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r001027_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_51_1 * 2)) & 255;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r001027_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_51_2 * 2)) & 255;
  }
  int stage_v_52_1 = (stage_v_19_1 ^ pub_r001027_20_1) & 63;
  int stage_v_52_2 = (stage_v_19_2 ^ pub_r001027_20_2) & 63;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_52_1 * 2)) & 255;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_52_2 * 2)) & 255;
  }
  int stage_v_53_1 = ((pub_r001027_3_1 * 2) + 27) & 63;
  int stage_v_53_2 = ((pub_r001027_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (sec_r001027_2_1 ^ pub_r001027_19_1) & 63;
  int stage_v_54_2 = (sec_r001027_2_2 ^ pub_r001027_19_2) & 63;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_54_1 * 2)) & 255;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_54_2 * 2)) & 255;
  }
  int stage_v_55_1 = ((pub_r001027_12_1 * 2) + 38) & 63;
  int stage_v_55_2 = ((pub_r001027_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001027_8_1 * 2) + 11) & 63;
  int stage_v_56_2 = ((pub_r001027_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (sec_r001027_5_1 ^ pub_r001027_2_1) & 63;
  int stage_v_57_2 = (sec_r001027_5_2 ^ pub_r001027_2_2) & 63;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((stage_v_46_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_57_1 * 2)) & 255;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((stage_v_46_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_57_2 * 2)) & 255;
  }
  int stage_v_58_1 = (stage_v_0_1 ^ pub_r001027_8_1) & 63;
  int stage_v_58_2 = (stage_v_0_2 ^ pub_r001027_8_2) & 63;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_58_1 * 2)) & 255;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_58_2 * 2)) & 255;
  }
  int stage_v_59_1 = (sec_r001027_9_1 ^ pub_r001027_17_1) & 63;
  int stage_v_59_2 = (sec_r001027_9_2 ^ pub_r001027_17_2) & 63;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((stage_v_37_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_59_1 * 2)) & 255;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((stage_v_37_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_59_2 * 2)) & 255;
  }
  int stage_v_60_1 = (stage_v_19_1 ^ pub_r001027_19_1) & 63;
  int stage_v_60_2 = (stage_v_19_2 ^ pub_r001027_19_2) & 63;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_60_1 * 2)) & 255;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((stage_v_30_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_60_2 * 2)) & 255;
  }
  int stage_v_61_1 = ((pub_r001027_12_1 * 2) + 37) & 63;
  int stage_v_61_2 = ((pub_r001027_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001027_13_1 * 2) + 34) & 63;
  int stage_v_62_2 = ((pub_r001027_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (helper_flow_3_1 ^ pub_r001027_3_1) & 63;
  int stage_v_63_2 = (helper_flow_3_2 ^ pub_r001027_3_2) & 63;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r001027_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_63_1 * 2)) & 255;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r001027_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_63_2 * 2)) & 255;
  }
  int stage_v_64_1 = ((pub_r001027_1_1 * 2) + 43) & 63;
  int stage_v_64_2 = ((pub_r001027_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001027_10_1 * 2) + 40) & 63;
  int stage_v_65_2 = ((pub_r001027_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001027_6_1 * 2) + 13) & 63;
  int stage_v_66_2 = ((pub_r001027_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (helper_flow_0_1 ^ pub_r001027_1_1) & 63;
  int stage_v_67_2 = (helper_flow_0_2 ^ pub_r001027_1_2) & 63;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((stage_v_58_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_67_1 * 2)) & 255;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((stage_v_58_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_67_2 * 2)) & 255;
  }
  int stage_v_68_1 = (stage_v_49_1 ^ pub_r001027_8_1) & 63;
  int stage_v_68_2 = (stage_v_49_2 ^ pub_r001027_8_2) & 63;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((stage_v_37_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_68_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_68_1 * 2)) & 255;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((stage_v_37_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_68_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_68_2 * 2)) & 255;
  }
  int stage_v_69_1 = (stage_v_23_1 ^ pub_r001027_0_1) & 63;
  int stage_v_69_2 = (stage_v_23_2 ^ pub_r001027_0_2) & 63;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r001027_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_69_1 * 2)) & 255;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r001027_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_69_2 * 2)) & 255;
  }
  int stage_v_70_1 = (stage_v_45_1 ^ pub_r001027_19_1) & 63;
  int stage_v_70_2 = (stage_v_45_2 ^ pub_r001027_19_2) & 63;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((stage_v_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_70_1 * 2)) & 255;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((stage_v_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_70_2 * 2)) & 255;
  }
  int stage_v_71_1 = (sec_r001027_5_1 ^ pub_r001027_11_1) & 63;
  int stage_v_71_2 = (sec_r001027_5_2 ^ pub_r001027_11_2) & 63;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r001027_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_71_1 * 2)) & 255;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r001027_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_71_2 * 2)) & 255;
  }
  int stage_v_72_1 = (sec_r001027_0_1 ^ pub_r001027_8_1) & 63;
  int stage_v_72_2 = (sec_r001027_0_2 ^ pub_r001027_8_2) & 63;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((stage_v_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_72_1 * 2)) & 255;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((stage_v_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_72_2 * 2)) & 255;
  }
  int stage_v_73_1 = (sec_r001027_0_1 ^ pub_r001027_12_1) & 63;
  int stage_v_73_2 = (sec_r001027_0_2 ^ pub_r001027_12_2) & 63;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((stage_v_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_73_1 * 2)) & 255;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((stage_v_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_73_2 * 2)) & 255;
  }
  int stage_v_74_1 = ((pub_r001027_19_1 * 2) + 44) & 63;
  int stage_v_74_2 = ((pub_r001027_19_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001027_6_1 * 2) + 17) & 63;
  int stage_v_75_2 = ((pub_r001027_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = (sec_r001027_6_1 ^ pub_r001027_19_1) & 63;
  int stage_v_76_2 = (sec_r001027_6_2 ^ pub_r001027_19_2) & 63;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((stage_v_47_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_76_1 * 2)) & 255;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((stage_v_47_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_76_2 * 2)) & 255;
  }
  int stage_v_77_1 = ((pub_r001027_0_1 * 2) + 6) & 63;
  int stage_v_77_2 = ((pub_r001027_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001027_6_1 * 2) + 35) & 63;
  int stage_v_78_2 = ((pub_r001027_6_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (stage_v_4_1 ^ pub_r001027_17_1) & 63;
  int stage_v_79_2 = (stage_v_4_2 ^ pub_r001027_17_2) & 63;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((stage_v_69_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_79_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_79_1 * 2)) & 255;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((stage_v_69_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_79_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_79_2 * 2)) & 255;
  }
  int stage_v_80_1 = (stage_v_18_1 ^ pub_r001027_6_1) & 63;
  int stage_v_80_2 = (stage_v_18_2 ^ pub_r001027_6_2) & 63;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_80_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_80_1 * 2)) & 255;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((stage_v_40_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_80_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_80_2 * 2)) & 255;
  }
  int stage_v_81_1 = (stage_v_76_1 ^ pub_r001027_12_1) & 63;
  int stage_v_81_2 = (stage_v_76_2 ^ pub_r001027_12_2) & 63;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((stage_v_71_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_81_1 * 2)) & 255;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((stage_v_71_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_81_2 * 2)) & 255;
  }
  int stage_v_82_1 = (stage_v_19_1 ^ pub_r001027_0_1) & 63;
  int stage_v_82_2 = (stage_v_19_2 ^ pub_r001027_0_2) & 63;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_82_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_82_1 * 2)) & 255;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((stage_v_80_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_82_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_82_2 * 2)) & 255;
  }
  int stage_v_83_1 = ((pub_r001027_4_1 * 2) + 8) & 63;
  int stage_v_83_2 = ((pub_r001027_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (sec_r001027_1_1 ^ pub_r001027_6_1) & 63;
  int stage_v_84_2 = (sec_r001027_1_2 ^ pub_r001027_6_2) & 63;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r001027_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_84_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r001027_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_84_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  }
  int stage_v_85_1 = (stage_v_41_1 ^ pub_r001027_21_1) & 63;
  int stage_v_85_2 = (stage_v_41_2 ^ pub_r001027_21_2) & 63;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r001027_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_85_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r001027_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_85_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  }
  int stage_v_86_1 = ((pub_r001027_6_1 * 2) + 49) & 63;
  int stage_v_86_2 = ((pub_r001027_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (sec_r001027_6_1 ^ pub_r001027_10_1) & 63;
  int stage_v_87_2 = (sec_r001027_6_2 ^ pub_r001027_10_2) & 63;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((stage_v_84_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((stage_v_84_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  }
  int stage_v_88_1 = (sec_r001027_5_1 ^ pub_r001027_8_1) & 63;
  int stage_v_88_2 = (sec_r001027_5_2 ^ pub_r001027_8_2) & 63;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((stage_v_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_88_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((stage_v_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_88_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  }
  int stage_v_89_1 = ((pub_r001027_20_1 * 2) + 36) & 63;
  int stage_v_89_2 = ((pub_r001027_20_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (stage_v_45_1 ^ pub_r001027_3_1) & 63;
  int stage_v_90_2 = (stage_v_45_2 ^ pub_r001027_3_2) & 63;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((stage_v_73_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_90_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((stage_v_73_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_90_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  }
  int stage_v_91_1 = (stage_v_49_1 ^ pub_r001027_14_1) & 63;
  int stage_v_91_2 = (stage_v_49_2 ^ pub_r001027_14_2) & 63;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_91_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_91_1 * 2)) & 255;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((stage_v_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_91_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_91_2 * 2)) & 255;
  }
  int stage_v_92_1 = ((pub_r001027_2_1 * 2) + 30) & 63;
  int stage_v_92_2 = ((pub_r001027_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = (sec_r001027_4_1 ^ pub_r001027_4_1) & 63;
  int stage_v_93_2 = (sec_r001027_4_2 ^ pub_r001027_4_2) & 63;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r001027_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_93_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_93_1 * 2)) & 255;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r001027_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_93_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_93_2 * 2)) & 255;
  }
  int stage_v_94_1 = (stage_v_51_1 ^ pub_r001027_3_1) & 63;
  int stage_v_94_2 = (stage_v_51_2 ^ pub_r001027_3_2) & 63;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r001027_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_94_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_94_1 * 2)) & 255;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r001027_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_94_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_94_2 * 2)) & 255;
  }
  int stage_v_95_1 = ((pub_r001027_11_1 * 2) + 46) & 63;
  int stage_v_95_2 = ((pub_r001027_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (stage_v_71_1 ^ pub_r001027_8_1) & 63;
  int stage_v_96_2 = (stage_v_71_2 ^ pub_r001027_8_2) & 63;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((helper_flow_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  }
  int stage_v_97_1 = (sec_r001027_7_1 ^ pub_r001027_13_1) & 63;
  int stage_v_97_2 = (sec_r001027_7_2 ^ pub_r001027_13_2) & 63;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((stage_v_87_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_97_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_97_1 * 2)) & 255;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((stage_v_87_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_97_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_97_2 * 2)) & 255;
  }
  int stage_v_98_1 = (stage_v_49_1 ^ pub_r001027_3_1) & 63;
  int stage_v_98_2 = (stage_v_49_2 ^ pub_r001027_3_2) & 63;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((stage_v_36_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((stage_v_36_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  }
  int stage_v_99_1 = (sec_r001027_11_1 ^ pub_r001027_13_1) & 63;
  int stage_v_99_2 = (sec_r001027_11_2 ^ pub_r001027_13_2) & 63;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((stage_v_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_99_1 * 2)) & 255;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((stage_v_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_99_2 * 2)) & 255;
  }
  int stage_v_100_1 = ((pub_r001027_21_1 * 2) + 45) & 63;
  int stage_v_100_2 = ((pub_r001027_21_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001027_10_1 * 2) + 22) & 63;
  int stage_v_101_2 = ((pub_r001027_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (stage_v_38_1 ^ pub_r001027_15_1) & 63;
  int stage_v_102_2 = (stage_v_38_2 ^ pub_r001027_15_2) & 63;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((stage_v_85_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((stage_v_85_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  }
  int stage_v_103_1 = ((pub_r001027_20_1 * 2) + 23) & 63;
  int stage_v_103_2 = ((pub_r001027_20_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (stage_v_93_1 ^ pub_r001027_12_1) & 63;
  int stage_v_104_2 = (stage_v_93_2 ^ pub_r001027_12_2) & 63;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((stage_v_49_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((stage_v_49_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  }
  int stage_v_105_1 = ((pub_r001027_7_1 * 2) + 11) & 63;
  int stage_v_105_2 = ((pub_r001027_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (stage_v_72_1 ^ pub_r001027_13_1) & 63;
  int stage_v_106_2 = (stage_v_72_2 ^ pub_r001027_13_2) & 63;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_106_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((stage_v_80_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_106_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  }
  int stage_v_107_1 = ((pub_r001027_13_1 * 2) + 42) & 63;
  int stage_v_107_2 = ((pub_r001027_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (stage_v_57_1 ^ pub_r001027_11_1) & 63;
  int stage_v_108_2 = (stage_v_57_2 ^ pub_r001027_11_2) & 63;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r001027_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r001027_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  }
  int stage_v_109_1 = ((pub_r001027_12_1 * 2) + 42) & 63;
  int stage_v_109_2 = ((pub_r001027_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (helper_flow_5_1 ^ pub_r001027_2_1) & 63;
  int stage_v_110_2 = (helper_flow_5_2 ^ pub_r001027_2_2) & 63;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((stage_v_46_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_110_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_110_1 * 2)) & 255;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((stage_v_46_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_110_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_110_2 * 2)) & 255;
  }
  int stage_v_111_1 = ((pub_r001027_14_1 * 2) + 16) & 63;
  int stage_v_111_2 = ((pub_r001027_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (stage_v_0_1 ^ pub_r001027_1_1) & 63;
  int stage_v_112_2 = (stage_v_0_2 ^ pub_r001027_1_2) & 63;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((stage_v_106_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_112_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((stage_v_106_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_112_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  }
  int stage_v_113_1 = (stage_v_19_1 ^ pub_r001027_14_1) & 63;
  int stage_v_113_2 = (stage_v_19_2 ^ pub_r001027_14_2) & 63;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((stage_v_46_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((stage_v_46_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  }
  int stage_v_114_1 = ((pub_r001027_22_1 * 2) + 49) & 63;
  int stage_v_114_2 = ((pub_r001027_22_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = (stage_v_41_1 ^ pub_r001027_21_1) & 63;
  int stage_v_115_2 = (stage_v_41_2 ^ pub_r001027_21_2) & 63;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((stage_v_69_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_115_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((stage_v_69_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_115_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  }
  int stage_v_116_1 = ((pub_r001027_3_1 * 2) + 9) & 63;
  int stage_v_116_2 = ((pub_r001027_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (stage_v_0_1 ^ pub_r001027_7_1) & 63;
  int stage_v_117_2 = (stage_v_0_2 ^ pub_r001027_7_2) & 63;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_117_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((stage_v_40_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_117_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  }
  int stage_v_118_1 = (stage_v_19_1 ^ pub_r001027_2_1) & 63;
  int stage_v_118_2 = (stage_v_19_2 ^ pub_r001027_2_2) & 63;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((stage_v_113_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_118_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((stage_v_113_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_118_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  }
  int stage_v_119_1 = ((pub_r001027_1_1 * 2) + 40) & 63;
  int stage_v_119_2 = ((pub_r001027_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001027_4_1 * 2) + 45) & 63;
  int stage_v_120_2 = ((pub_r001027_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001027_6_1 * 2) + 40) & 63;
  int stage_v_121_2 = ((pub_r001027_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001027_0_1 * 2) + 14) & 63;
  int stage_v_122_2 = ((pub_r001027_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001027_11_1 * 2) + 49) & 63;
  int stage_v_123_2 = ((pub_r001027_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (stage_v_45_1 ^ pub_r001027_0_1) & 63;
  int stage_v_124_2 = (stage_v_45_2 ^ pub_r001027_0_2) & 63;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r001027_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((sec_r001027_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  }
  int stage_v_125_1 = (sec_r001027_10_1 ^ pub_r001027_3_1) & 63;
  int stage_v_125_2 = (sec_r001027_10_2 ^ pub_r001027_3_2) & 63;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((stage_v_97_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_125_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  }
  if ((stage_v_125_2 & 1) != 0)
  {
    if ((stage_v_97_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_125_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  }
  int stage_v_126_1 = (stage_v_33_1 ^ pub_r001027_1_1) & 63;
  int stage_v_126_2 = (stage_v_33_2 ^ pub_r001027_1_2) & 63;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((stage_v_33_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_126_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  }
  if ((stage_v_126_2 & 1) != 0)
  {
    if ((stage_v_33_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_126_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  }
  int stage_v_127_1 = ((pub_r001027_6_1 * 2) + 46) & 63;
  int stage_v_127_2 = ((pub_r001027_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = (stage_v_58_1 ^ pub_r001027_15_1) & 63;
  int stage_v_128_2 = (stage_v_58_2 ^ pub_r001027_15_2) & 63;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_128_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  }
  if ((stage_v_128_2 & 1) != 0)
  {
    if ((helper_flow_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_128_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  }
  int stage_v_129_1 = (stage_v_54_1 ^ pub_r001027_16_1) & 63;
  int stage_v_129_2 = (stage_v_54_2 ^ pub_r001027_16_2) & 63;
  if ((stage_v_129_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  }
  if ((stage_v_129_2 & 1) != 0)
  {
    if ((stage_v_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  }
  int stage_v_130_1 = ((pub_r001027_12_1 * 2) + 29) & 63;
  int stage_v_130_2 = ((pub_r001027_12_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (stage_v_44_1 ^ pub_r001027_1_1) & 63;
  int stage_v_131_2 = (stage_v_44_2 ^ pub_r001027_1_2) & 63;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((stage_v_60_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_131_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_131_1 * 2)) & 255;
  }
  if ((stage_v_131_2 & 1) != 0)
  {
    if ((stage_v_60_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_131_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_131_2 * 2)) & 255;
  }
  int stage_v_132_1 = (stage_v_44_1 ^ pub_r001027_14_1) & 63;
  int stage_v_132_2 = (stage_v_44_2 ^ pub_r001027_14_2) & 63;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((stage_v_112_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  }
  if ((stage_v_132_2 & 1) != 0)
  {
    if ((stage_v_112_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  }
  int stage_v_133_1 = (stage_v_87_1 ^ pub_r001027_3_1) & 63;
  int stage_v_133_2 = (stage_v_87_2 ^ pub_r001027_3_2) & 63;
  if ((stage_v_133_1 & 1) != 0)
  {
    if ((stage_v_79_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  }
  if ((stage_v_133_2 & 1) != 0)
  {
    if ((stage_v_79_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  }
  int stage_v_134_1 = ((pub_r001027_8_1 * 2) + 26) & 63;
  int stage_v_134_2 = ((pub_r001027_8_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (stage_v_79_1 ^ pub_r001027_13_1) & 63;
  int stage_v_135_2 = (stage_v_79_2 ^ pub_r001027_13_2) & 63;
  if ((stage_v_135_1 & 1) != 0)
  {
    if ((stage_v_72_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_135_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_135_1 * 2)) & 255;
  }
  if ((stage_v_135_2 & 1) != 0)
  {
    if ((stage_v_72_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_135_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_135_2 * 2)) & 255;
  }
  int stage_v_136_1 = (stage_v_131_1 ^ pub_r001027_14_1) & 63;
  int stage_v_136_2 = (stage_v_131_2 ^ pub_r001027_14_2) & 63;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((stage_v_79_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((stage_v_79_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  }
  int stage_v_137_1 = ((pub_r001027_7_1 * 2) + 43) & 63;
  int stage_v_137_2 = ((pub_r001027_7_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (stage_v_117_1 ^ pub_r001027_5_1) & 63;
  int stage_v_138_2 = (stage_v_117_2 ^ pub_r001027_5_2) & 63;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((stage_v_110_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  }
  if ((stage_v_138_2 & 1) != 0)
  {
    if ((stage_v_110_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  }
  int stage_v_139_1 = ((pub_r001027_20_1 * 2) + 18) & 63;
  int stage_v_139_2 = ((pub_r001027_20_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (stage_v_18_1 ^ pub_r001027_17_1) & 63;
  int stage_v_140_2 = (stage_v_18_2 ^ pub_r001027_17_2) & 63;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  }
  if ((stage_v_140_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  }
  int stage_v_141_1 = ((pub_r001027_18_1 * 2) + 17) & 63;
  int stage_v_141_2 = ((pub_r001027_18_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (stage_v_57_1 ^ pub_r001027_2_1) & 63;
  int stage_v_142_2 = (stage_v_57_2 ^ pub_r001027_2_2) & 63;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((stage_v_94_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_142_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  }
  if ((stage_v_142_2 & 1) != 0)
  {
    if ((stage_v_94_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_142_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  }
  int stage_v_143_1 = ((pub_r001027_22_1 * 2) + 26) & 63;
  int stage_v_143_2 = ((pub_r001027_22_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (sec_r001027_4_1 ^ pub_r001027_19_1) & 63;
  int stage_v_144_2 = (sec_r001027_4_2 ^ pub_r001027_19_2) & 63;
  if ((stage_v_144_1 & 1) != 0)
  {
    if ((stage_v_142_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  }
  if ((stage_v_144_2 & 1) != 0)
  {
    if ((stage_v_142_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  }
  int stage_v_145_1 = ((pub_r001027_7_1 * 2) + 27) & 63;
  int stage_v_145_2 = ((pub_r001027_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = (stage_v_132_1 ^ pub_r001027_1_1) & 63;
  int stage_v_146_2 = (stage_v_132_2 ^ pub_r001027_1_2) & 63;
  if ((stage_v_146_1 & 1) != 0)
  {
    if ((stage_v_26_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_146_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  }
  if ((stage_v_146_2 & 1) != 0)
  {
    if ((stage_v_26_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_146_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  }
  int stage_v_147_1 = (stage_v_68_1 ^ pub_r001027_22_1) & 63;
  int stage_v_147_2 = (stage_v_68_2 ^ pub_r001027_22_2) & 63;
  if ((stage_v_147_1 & 1) != 0)
  {
    if ((stage_v_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_147_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  }
  if ((stage_v_147_2 & 1) != 0)
  {
    if ((stage_v_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_147_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  }
  int stage_v_148_1 = ((pub_r001027_11_1 * 2) + 9) & 63;
  int stage_v_148_2 = ((pub_r001027_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = (stage_v_21_1 ^ pub_r001027_2_1) & 63;
  int stage_v_149_2 = (stage_v_21_2 ^ pub_r001027_2_2) & 63;
  if ((stage_v_149_1 & 1) != 0)
  {
    if ((sec_r001027_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  }
  if ((stage_v_149_2 & 1) != 0)
  {
    if ((sec_r001027_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  }
  int stage_v_150_1 = (stage_v_63_1 ^ pub_r001027_18_1) & 63;
  int stage_v_150_2 = (stage_v_63_2 ^ pub_r001027_18_2) & 63;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((stage_v_69_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  }
  if ((stage_v_150_2 & 1) != 0)
  {
    if ((stage_v_69_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  }
  int stage_v_151_1 = ((pub_r001027_14_1 * 2) + 8) & 63;
  int stage_v_151_2 = ((pub_r001027_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (stage_v_88_1 ^ pub_r001027_1_1) & 63;
  int stage_v_152_2 = (stage_v_88_2 ^ pub_r001027_1_2) & 63;
  if ((stage_v_152_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_152_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  }
  if ((stage_v_152_2 & 1) != 0)
  {
    if ((helper_flow_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_152_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  }
  int stage_v_153_1 = ((pub_r001027_15_1 * 2) + 28) & 63;
  int stage_v_153_2 = ((pub_r001027_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (stage_v_49_1 ^ pub_r001027_20_1) & 63;
  int stage_v_154_2 = (stage_v_49_2 ^ pub_r001027_20_2) & 63;
  if ((stage_v_154_1 & 1) != 0)
  {
    if ((stage_v_87_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_154_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  }
  if ((stage_v_154_2 & 1) != 0)
  {
    if ((stage_v_87_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_154_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  }
  int stage_v_155_1 = ((pub_r001027_15_1 * 2) + 21) & 63;
  int stage_v_155_2 = ((pub_r001027_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (stage_v_54_1 ^ pub_r001027_12_1) & 63;
  int stage_v_156_2 = (stage_v_54_2 ^ pub_r001027_12_2) & 63;
  if ((stage_v_156_1 & 1) != 0)
  {
    if ((stage_v_135_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_156_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_156_1 * 2)) & 255;
  }
  if ((stage_v_156_2 & 1) != 0)
  {
    if ((stage_v_135_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_156_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_156_2 * 2)) & 255;
  }
  int stage_v_157_1 = (stage_v_3_1 ^ pub_r001027_4_1) & 63;
  int stage_v_157_2 = (stage_v_3_2 ^ pub_r001027_4_2) & 63;
  if ((stage_v_157_1 & 1) != 0)
  {
    if ((stage_v_73_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_157_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  }
  if ((stage_v_157_2 & 1) != 0)
  {
    if ((stage_v_73_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_157_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  }
  int stage_v_158_1 = (stage_v_71_1 ^ pub_r001027_5_1) & 63;
  int stage_v_158_2 = (stage_v_71_2 ^ pub_r001027_5_2) & 63;
  if ((stage_v_158_1 & 1) != 0)
  {
    if ((stage_v_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_158_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  }
  if ((stage_v_158_2 & 1) != 0)
  {
    if ((stage_v_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_158_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  }
  int stage_v_159_1 = (stage_v_149_1 ^ pub_r001027_11_1) & 63;
  int stage_v_159_2 = (stage_v_149_2 ^ pub_r001027_11_2) & 63;
  if ((stage_v_159_1 & 1) != 0)
  {
    if ((stage_v_47_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_159_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  }
  if ((stage_v_159_2 & 1) != 0)
  {
    if ((stage_v_47_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_159_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  }
  int stage_v_160_1 = ((pub_r001027_22_1 * 2) + 10) & 63;
  int stage_v_160_2 = ((pub_r001027_22_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (stage_v_131_1 ^ pub_r001027_5_1) & 63;
  int stage_v_161_2 = (stage_v_131_2 ^ pub_r001027_5_2) & 63;
  if ((stage_v_161_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_161_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  }
  if ((stage_v_161_2 & 1) != 0)
  {
    if ((stage_v_80_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_161_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  }
  int stage_v_162_1 = (stage_v_90_1 ^ pub_r001027_2_1) & 63;
  int stage_v_162_2 = (stage_v_90_2 ^ pub_r001027_2_2) & 63;
  if ((stage_v_162_1 & 1) != 0)
  {
    if ((sec_r001027_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_162_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  }
  if ((stage_v_162_2 & 1) != 0)
  {
    if ((sec_r001027_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_162_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  }
  int stage_v_163_1 = (stage_v_79_1 ^ pub_r001027_18_1) & 63;
  int stage_v_163_2 = (stage_v_79_2 ^ pub_r001027_18_2) & 63;
  if ((stage_v_163_1 & 1) != 0)
  {
    if ((stage_v_60_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_163_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  }
  if ((stage_v_163_2 & 1) != 0)
  {
    if ((stage_v_60_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_163_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  }
  int stage_v_164_1 = (stage_v_35_1 ^ pub_r001027_18_1) & 63;
  int stage_v_164_2 = (stage_v_35_2 ^ pub_r001027_18_2) & 63;
  if ((stage_v_164_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_164_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  }
  if ((stage_v_164_2 & 1) != 0)
  {
    if ((stage_v_23_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_164_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  }
  int stage_v_165_1 = (stage_v_118_1 ^ pub_r001027_22_1) & 63;
  int stage_v_165_2 = (stage_v_118_2 ^ pub_r001027_22_2) & 63;
  if ((stage_v_165_1 & 1) != 0)
  {
    if ((stage_v_164_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_165_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  }
  if ((stage_v_165_2 & 1) != 0)
  {
    if ((stage_v_164_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_165_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  }
  int stage_v_166_1 = (sec_r001027_11_1 ^ pub_r001027_9_1) & 63;
  int stage_v_166_2 = (sec_r001027_11_2 ^ pub_r001027_9_2) & 63;
  if ((stage_v_166_1 & 1) != 0)
  {
    if ((stage_v_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_166_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  }
  if ((stage_v_166_2 & 1) != 0)
  {
    if ((stage_v_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_166_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  }
  int stage_v_167_1 = (stage_v_41_1 ^ pub_r001027_14_1) & 63;
  int stage_v_167_2 = (stage_v_41_2 ^ pub_r001027_14_2) & 63;
  if ((stage_v_167_1 & 1) != 0)
  {
    if ((sec_r001027_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_167_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  }
  if ((stage_v_167_2 & 1) != 0)
  {
    if ((sec_r001027_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_167_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  }
  int stage_v_168_1 = (stage_v_162_1 ^ pub_r001027_16_1) & 63;
  int stage_v_168_2 = (stage_v_162_2 ^ pub_r001027_16_2) & 63;
  if ((stage_v_168_1 & 1) != 0)
  {
    if ((stage_v_157_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_168_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  }
  if ((stage_v_168_2 & 1) != 0)
  {
    if ((stage_v_157_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_168_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  }
  int stage_v_169_1 = (stage_v_72_1 ^ pub_r001027_4_1) & 63;
  int stage_v_169_2 = (stage_v_72_2 ^ pub_r001027_4_2) & 63;
  if ((stage_v_169_1 & 1) != 0)
  {
    if ((sec_r001027_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_169_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  }
  if ((stage_v_169_2 & 1) != 0)
  {
    if ((sec_r001027_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_169_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  }
  int stage_v_170_1 = ((pub_r001027_7_1 * 2) + 22) & 63;
  int stage_v_170_2 = ((pub_r001027_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = (helper_flow_4_1 ^ pub_r001027_15_1) & 63;
  int stage_v_171_2 = (helper_flow_4_2 ^ pub_r001027_15_2) & 63;
  if ((stage_v_171_1 & 1) != 0)
  {
    if ((stage_v_113_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_171_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  }
  if ((stage_v_171_2 & 1) != 0)
  {
    if ((stage_v_113_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_171_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  }
  int stage_v_172_1 = (stage_v_99_1 ^ pub_r001027_20_1) & 63;
  int stage_v_172_2 = (stage_v_99_2 ^ pub_r001027_20_2) & 63;
  if ((stage_v_172_1 & 1) != 0)
  {
    if ((stage_v_157_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_172_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  }
  if ((stage_v_172_2 & 1) != 0)
  {
    if ((stage_v_157_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_172_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  }
  int stage_v_173_1 = ((pub_r001027_3_1 * 2) + 23) & 63;
  int stage_v_173_2 = ((pub_r001027_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001027_8_1 * 2) + 29) & 63;
  int stage_v_174_2 = ((pub_r001027_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001027_17_1 * 2) + 22) & 63;
  int stage_v_175_2 = ((pub_r001027_17_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001027_4_1 * 2) + 50) & 63;
  int stage_v_176_2 = ((pub_r001027_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001027_21_1 * 2) + 45) & 63;
  int stage_v_177_2 = ((pub_r001027_21_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (stage_v_140_1 ^ pub_r001027_15_1) & 63;
  int stage_v_178_2 = (stage_v_140_2 ^ pub_r001027_15_2) & 63;
  if ((stage_v_178_1 & 1) != 0)
  {
    if ((sec_r001027_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_178_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_178_1 * 2)) & 255;
  }
  if ((stage_v_178_2 & 1) != 0)
  {
    if ((sec_r001027_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_178_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_178_2 * 2)) & 255;
  }
  int stage_v_179_1 = (helper_flow_0_1 ^ pub_r001027_1_1) & 63;
  int stage_v_179_2 = (helper_flow_0_2 ^ pub_r001027_1_2) & 63;
  if ((stage_v_179_1 & 1) != 0)
  {
    if ((stage_v_60_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_179_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  }
  if ((stage_v_179_2 & 1) != 0)
  {
    if ((stage_v_60_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_179_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  }
  int stage_v_180_1 = ((pub_r001027_19_1 * 2) + 47) & 63;
  int stage_v_180_2 = ((pub_r001027_19_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001027_16_1 * 2) + 35) & 63;
  int stage_v_181_2 = ((pub_r001027_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001027_17_1 * 2) + 47) & 63;
  int stage_v_182_2 = ((pub_r001027_17_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001027_9_1 * 2) + 14) & 63;
  int stage_v_183_2 = ((pub_r001027_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (stage_v_159_1 ^ pub_r001027_11_1) & 63;
  int stage_v_184_2 = (stage_v_159_2 ^ pub_r001027_11_2) & 63;
  if ((stage_v_184_1 & 1) != 0)
  {
    if ((stage_v_156_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_184_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_184_1 * 2)) & 255;
  }
  if ((stage_v_184_2 & 1) != 0)
  {
    if ((stage_v_156_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_184_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_184_2 * 2)) & 255;
  }
  int stage_v_185_1 = (stage_v_161_1 ^ pub_r001027_19_1) & 63;
  int stage_v_185_2 = (stage_v_161_2 ^ pub_r001027_19_2) & 63;
  if ((stage_v_185_1 & 1) != 0)
  {
    if ((stage_v_135_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_185_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_185_1 * 2)) & 255;
  }
  if ((stage_v_185_2 & 1) != 0)
  {
    if ((stage_v_135_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_185_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_185_2 * 2)) & 255;
  }
  int stage_v_186_1 = (stage_v_131_1 ^ pub_r001027_21_1) & 63;
  int stage_v_186_2 = (stage_v_131_2 ^ pub_r001027_21_2) & 63;
  if ((stage_v_186_1 & 1) != 0)
  {
    if ((stage_v_28_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_186_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_186_1 * 2)) & 255;
  }
  if ((stage_v_186_2 & 1) != 0)
  {
    if ((stage_v_28_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_186_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_186_2 * 2)) & 255;
  }
  int stage_v_187_1 = (stage_v_140_1 ^ pub_r001027_7_1) & 63;
  int stage_v_187_2 = (stage_v_140_2 ^ pub_r001027_7_2) & 63;
  if ((stage_v_187_1 & 1) != 0)
  {
    if ((stage_v_185_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_187_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_187_1 * 2)) & 255;
  }
  if ((stage_v_187_2 & 1) != 0)
  {
    if ((stage_v_185_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_187_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_187_2 * 2)) & 255;
  }
  int stage_v_188_1 = (stage_v_113_1 ^ pub_r001027_5_1) & 63;
  int stage_v_188_2 = (stage_v_113_2 ^ pub_r001027_5_2) & 63;
  if ((stage_v_188_1 & 1) != 0)
  {
    if ((stage_v_117_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_188_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_188_1 * 2)) & 255;
  }
  if ((stage_v_188_2 & 1) != 0)
  {
    if ((stage_v_117_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_188_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_188_2 * 2)) & 255;
  }
  int stage_v_189_1 = ((pub_r001027_2_1 * 2) + 20) & 63;
  int stage_v_189_2 = ((pub_r001027_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001027_9_1 * 2) + 23) & 63;
  int stage_v_190_2 = ((pub_r001027_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (stage_v_140_1 ^ pub_r001027_19_1) & 63;
  int stage_v_191_2 = (stage_v_140_2 ^ pub_r001027_19_2) & 63;
  if ((stage_v_191_1 & 1) != 0)
  {
    if ((stage_v_158_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_191_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  }
  if ((stage_v_191_2 & 1) != 0)
  {
    if ((stage_v_158_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_191_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  }
  int stage_v_192_1 = ((pub_r001027_2_1 * 2) + 17) & 63;
  int stage_v_192_2 = ((pub_r001027_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (stage_v_67_1 ^ pub_r001027_4_1) & 63;
  int stage_v_193_2 = (stage_v_67_2 ^ pub_r001027_4_2) & 63;
  if ((stage_v_193_1 & 1) != 0)
  {
    if ((stage_v_144_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_193_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_193_1 * 2)) & 255;
  }
  if ((stage_v_193_2 & 1) != 0)
  {
    if ((stage_v_144_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_193_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_193_2 * 2)) & 255;
  }
  int stage_v_194_1 = (stage_v_9_1 ^ pub_r001027_22_1) & 63;
  int stage_v_194_2 = (stage_v_9_2 ^ pub_r001027_22_2) & 63;
  if ((stage_v_194_1 & 1) != 0)
  {
    if ((stage_v_113_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_194_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_194_1 * 2)) & 255;
  }
  if ((stage_v_194_2 & 1) != 0)
  {
    if ((stage_v_113_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_194_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_194_2 * 2)) & 255;
  }
  int stage_v_195_1 = (stage_v_71_1 ^ pub_r001027_20_1) & 63;
  int stage_v_195_2 = (stage_v_71_2 ^ pub_r001027_20_2) & 63;
  if ((stage_v_195_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_195_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_195_1 * 2)) & 255;
  }
  if ((stage_v_195_2 & 1) != 0)
  {
    if ((stage_v_30_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_195_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_195_2 * 2)) & 255;
  }
  int stage_v_196_1 = (stage_v_5_1 ^ pub_r001027_4_1) & 63;
  int stage_v_196_2 = (stage_v_5_2 ^ pub_r001027_4_2) & 63;
  if ((stage_v_196_1 & 1) != 0)
  {
    if ((stage_v_35_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_196_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_196_1 * 2)) & 255;
  }
  if ((stage_v_196_2 & 1) != 0)
  {
    if ((stage_v_35_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_196_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_196_2 * 2)) & 255;
  }
  int stage_v_197_1 = (stage_v_110_1 ^ pub_r001027_8_1) & 63;
  int stage_v_197_2 = (stage_v_110_2 ^ pub_r001027_8_2) & 63;
  if ((stage_v_197_1 & 1) != 0)
  {
    if ((stage_v_52_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_197_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_197_1 * 2)) & 255;
  }
  if ((stage_v_197_2 & 1) != 0)
  {
    if ((stage_v_52_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_197_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_197_2 * 2)) & 255;
  }
  int stage_v_198_1 = ((pub_r001027_16_1 * 2) + 23) & 63;
  int stage_v_198_2 = ((pub_r001027_16_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (stage_v_149_1 ^ pub_r001027_21_1) & 63;
  int stage_v_199_2 = (stage_v_149_2 ^ pub_r001027_21_2) & 63;
  if ((stage_v_199_1 & 1) != 0)
  {
    if ((stage_v_113_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_199_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_199_1 * 2)) & 255;
  }
  if ((stage_v_199_2 & 1) != 0)
  {
    if ((stage_v_113_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_199_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_199_2 * 2)) & 255;
  }
  int stage_v_200_1 = (stage_v_157_1 ^ pub_r001027_22_1) & 63;
  int stage_v_200_2 = (stage_v_157_2 ^ pub_r001027_22_2) & 63;
  if ((stage_v_200_1 & 1) != 0)
  {
    if ((sec_r001027_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_200_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_200_1 * 2)) & 255;
  }
  if ((stage_v_200_2 & 1) != 0)
  {
    if ((sec_r001027_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_200_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_200_2 * 2)) & 255;
  }
  int stage_v_201_1 = (stage_v_161_1 ^ pub_r001027_16_1) & 63;
  int stage_v_201_2 = (stage_v_161_2 ^ pub_r001027_16_2) & 63;
  if ((stage_v_201_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_201_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_201_1 * 2)) & 255;
  }
  if ((stage_v_201_2 & 1) != 0)
  {
    if ((stage_v_40_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_201_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_201_2 * 2)) & 255;
  }
  int stage_v_202_1 = ((pub_r001027_14_1 * 2) + 36) & 63;
  int stage_v_202_2 = ((pub_r001027_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (stage_v_201_1 ^ pub_r001027_11_1) & 63;
  int stage_v_203_2 = (stage_v_201_2 ^ pub_r001027_11_2) & 63;
  if ((stage_v_203_1 & 1) != 0)
  {
    if ((stage_v_193_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_203_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_203_1 * 2)) & 255;
  }
  if ((stage_v_203_2 & 1) != 0)
  {
    if ((stage_v_193_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_203_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_203_2 * 2)) & 255;
  }
  int stage_v_204_1 = (stage_v_168_1 ^ pub_r001027_9_1) & 63;
  int stage_v_204_2 = (stage_v_168_2 ^ pub_r001027_9_2) & 63;
  if ((stage_v_204_1 & 1) != 0)
  {
    if ((stage_v_125_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_204_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_204_1 * 2)) & 255;
  }
  if ((stage_v_204_2 & 1) != 0)
  {
    if ((stage_v_125_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_204_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_204_2 * 2)) & 255;
  }
  int stage_v_205_1 = ((pub_r001027_18_1 * 2) + 38) & 63;
  int stage_v_205_2 = ((pub_r001027_18_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001027_14_1 * 2) + 27) & 63;
  int stage_v_206_2 = ((pub_r001027_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (stage_v_106_1 ^ pub_r001027_3_1) & 63;
  int stage_v_207_2 = (stage_v_106_2 ^ pub_r001027_3_2) & 63;
  if ((stage_v_207_1 & 1) != 0)
  {
    if ((stage_v_154_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_207_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_207_1 * 2)) & 255;
  }
  if ((stage_v_207_2 & 1) != 0)
  {
    if ((stage_v_154_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_207_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_207_2 * 2)) & 255;
  }
  int stage_v_208_1 = (stage_v_110_1 ^ pub_r001027_0_1) & 63;
  int stage_v_208_2 = (stage_v_110_2 ^ pub_r001027_0_2) & 63;
  if ((stage_v_208_1 & 1) != 0)
  {
    if ((stage_v_204_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_208_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_208_1 * 2)) & 255;
  }
  if ((stage_v_208_2 & 1) != 0)
  {
    if ((stage_v_204_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_208_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_208_2 * 2)) & 255;
  }
  int stage_v_209_1 = (stage_v_197_1 ^ pub_r001027_3_1) & 63;
  int stage_v_209_2 = (stage_v_197_2 ^ pub_r001027_3_2) & 63;
  if ((stage_v_209_1 & 1) != 0)
  {
    if ((stage_v_135_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_209_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_209_1 * 2)) & 255;
  }
  if ((stage_v_209_2 & 1) != 0)
  {
    if ((stage_v_135_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_209_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_209_2 * 2)) & 255;
  }
  int stage_v_210_1 = (stage_v_2_1 ^ pub_r001027_5_1) & 63;
  int stage_v_210_2 = (stage_v_2_2 ^ pub_r001027_5_2) & 63;
  if ((stage_v_210_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_210_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_210_1 * 2)) & 255;
  }
  if ((stage_v_210_2 & 1) != 0)
  {
    if ((stage_v_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_210_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_210_2 * 2)) & 255;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001027_11_1 == pub_r001027_11_2);
  __CPROVER_assume(pub_r001027_17_1 == pub_r001027_17_2);
  __CPROVER_assume(sec_r001027_1_1 != sec_r001027_1_2);
  __CPROVER_assume(sec_r001027_16_1 != sec_r001027_16_2);
  __CPROVER_assume(pub_r001027_16_1 == pub_r001027_16_2);
  __CPROVER_assume(pub_r001027_9_1 == pub_r001027_9_2);
  __CPROVER_assume(sec_r001027_0_1 != sec_r001027_0_2);
  __CPROVER_assume(pub_r001027_7_1 == pub_r001027_7_2);
  __CPROVER_assume(sec_r001027_15_1 != sec_r001027_15_2);
  __CPROVER_assume(sec_r001027_13_1 != sec_r001027_13_2);
  __CPROVER_assume(pub_r001027_10_1 == pub_r001027_10_2);
  __CPROVER_assume(sec_r001027_14_1 != sec_r001027_14_2);
  __CPROVER_assume(sec_r001027_10_1 != sec_r001027_10_2);
  __CPROVER_assume(pub_r001027_4_1 == pub_r001027_4_2);
  __CPROVER_assume(pub_r001027_15_1 == pub_r001027_15_2);
  __CPROVER_assume(pub_r001027_8_1 == pub_r001027_8_2);
  __CPROVER_assume(pub_r001027_18_1 == pub_r001027_18_2);
  __CPROVER_assume(pub_r001027_0_1 == pub_r001027_0_2);
  __CPROVER_assume(pub_r001027_1_1 == pub_r001027_1_2);
  __CPROVER_assume(sec_r001027_4_1 != sec_r001027_4_2);
  __CPROVER_assume(pub_r001027_3_1 == pub_r001027_3_2);
  __CPROVER_assume(pub_r001027_22_1 == pub_r001027_22_2);
  __CPROVER_assume(pub_r001027_21_1 == pub_r001027_21_2);
  __CPROVER_assume(sec_r001027_9_1 != sec_r001027_9_2);
  __CPROVER_assume(pub_r001027_20_1 == pub_r001027_20_2);
  __CPROVER_assume(pub_r001027_6_1 == pub_r001027_6_2);
  __CPROVER_assume(sec_r001027_11_1 != sec_r001027_11_2);
  __CPROVER_assume(pub_r001027_2_1 == pub_r001027_2_2);
  __CPROVER_assume(pub_r001027_5_1 == pub_r001027_5_2);
  __CPROVER_assume(pub_r001027_13_1 == pub_r001027_13_2);
  __CPROVER_assume(pub_r001027_14_1 == pub_r001027_14_2);
  __CPROVER_assume(sec_r001027_3_1 != sec_r001027_3_2);
  __CPROVER_assume(sec_r001027_7_1 != sec_r001027_7_2);
  __CPROVER_assume(sec_r001027_6_1 != sec_r001027_6_2);
  __CPROVER_assume(sec_r001027_2_1 != sec_r001027_2_2);
  __CPROVER_assume(pub_r001027_12_1 == pub_r001027_12_2);
  __CPROVER_assume(pub_r001027_19_1 == pub_r001027_19_2);
  __CPROVER_assume(sec_r001027_5_1 != sec_r001027_5_2);
  __CPROVER_assume(sec_r001027_8_1 != sec_r001027_8_2);
  __CPROVER_assume(sec_r001027_12_1 != sec_r001027_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.iv == st_var_2_2.iv);
  assert(st_var_2_1.counter == st_var_2_2.counter);
  assert(st_var_2_1.flags == st_var_2_2.flags);
  assert(st_var_2_1.round_key == st_var_2_2.round_key);
  assert(st_var_2_1.tag == st_var_2_2.tag);
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
}


