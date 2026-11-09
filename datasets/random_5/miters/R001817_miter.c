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
struct EventLog_R001817_1713_0
{
  short code;
  short severity;
  unsigned char seq;
  int timestamp;
  unsigned char signature;
  int facility;
  int buffer[3];
};
struct FilterState_R001817_1713_1
{
  unsigned char cutoff;
  int damping;
  unsigned char mode;
  int prev_in;
  int buffer[3];
};
struct CipherContext_R001817_1713_2
{
  int tag;
  unsigned char round_key;
  short nonce;
  short counter;
  int iv;
  int flags;
  int buffer[3];
};
union TelemetryField_R001817_1713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001817_1713_1
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
void fn_R001817_1713_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001817_1713_2 st_1 = {0};
  struct CipherContext_R001817_1713_2 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_17_1 = local_arr_1[aux_1 % 3];
  int bound_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_17_2 * 2)) & 127;
  int phase_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_82_1 > 42)
  {
    acc_1 = ((acc_1 + (phase_82_1 * 2)) + 5) & 127;
    aux_1 ^= phase_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_82_2 > 42)
  {
    acc_2 = ((acc_2 + (phase_82_2 * 2)) + 5) & 127;
    aux_2 ^= phase_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_82_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_17_1 == bound_17_2);
  assert(phase_82_1 == phase_82_2);
}

int fn_R001817_1713_0(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001817_1713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int bound_17 = local_arr[aux % 3];
  acc = (acc + (bound_17 * 2)) & 127;
  int phase_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_82 > 42)
  {
    acc = ((acc + (phase_82 * 2)) + 5) & 127;
    aux ^= phase_82 & 15;
  }
  else
  {
    acc = ((acc - phase_82) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001817_1713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st_1 = {0};
  struct EventLog_R001817_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int accumulator_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_16_1) & 63;
  aux_2 = (aux_2 + accumulator_16_2) & 63;
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
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_16_1 == accumulator_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_17_1 == mask_17_2);
}

int fn_R001817_1713_1(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int accumulator_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_16) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int mask_17 = local_arr[aux % 3];
  acc = (acc + (mask_17 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001817_1713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001817_1713_2 st_1 = {0};
  struct CipherContext_R001817_1713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int accumulator_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_16_1 > 21)
  {
    acc_1 = ((acc_1 + (accumulator_16_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_16_2 > 21)
  {
    acc_2 = ((acc_2 + (accumulator_16_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_16_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_52_1) & 63;
  aux_2 = (aux_2 + offset_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_99_1 = local_arr_1[aux_1 % 3];
  int phase_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_99_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_16_1 == accumulator_16_2);
  assert(offset_52_1 == offset_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_99_1 == phase_99_2);
}

int fn_R001817_1713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001817_1713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int accumulator_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_16 > 21)
  {
    acc = ((acc + (accumulator_16 * 2)) + 5) & 127;
    aux ^= accumulator_16 & 15;
  }
  else
  {
    acc = ((acc - accumulator_16) + 11) & 127;
    aux += 3;
  }
  int offset_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_52) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_99 = local_arr[aux % 3];
  acc = (acc + (phase_99 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001817_1713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001817_1713_1 st_1 = {0};
  struct FilterState_R001817_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int segment_21_1 = 0;
  int segment_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_21_1 = ((segment_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_21_2 = ((segment_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_21_1) & 127;
    acc_2 = (acc_2 + segment_21_2) & 127;
  }

  int delta_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_72_1 > 26)
  {
    acc_1 = ((acc_1 + (delta_72_1 * 2)) + 5) & 127;
    aux_1 ^= delta_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_72_2 > 26)
  {
    acc_2 = ((acc_2 + (delta_72_2 * 2)) + 5) & 127;
    aux_2 ^= delta_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_67_1)
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

  switch (margin_67_2)
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
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_21_1 == segment_21_2);
  assert(delta_72_1 == delta_72_2);
  assert(margin_67_1 == margin_67_2);
}

int fn_R001817_1713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001817_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int segment_21 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_21 = ((segment_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_21) & 127;
  }

  int delta_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_72 > 26)
  {
    acc = ((acc + (delta_72 * 2)) + 5) & 127;
    aux ^= delta_72 & 15;
  }
  else
  {
    acc = ((acc - delta_72) + 11) & 127;
    aux += 3;
  }
  int margin_67 = (aux + st.buffer[1]) & 3;
  switch (margin_67)
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

void fn_R001817_1713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st_1 = {0};
  struct EventLog_R001817_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_14_1 = local_arr_1[aux_1 % 3];
  int stride_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_14_2 * 2)) & 127;
  int mask_14_1 = 0;
  int mask_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_14_1 = ((mask_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_14_2 = ((mask_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_14_1) & 127;
    acc_2 = (acc_2 + mask_14_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_14_1 == stride_14_2);
  assert(mask_14_1 == mask_14_2);
}

int fn_R001817_1713_4(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int stride_14 = local_arr[aux % 3];
  acc = (acc + (stride_14 * 2)) & 127;
  int mask_14 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_14 = ((mask_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_14) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001817_1713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001817_1713_1 st_1 = {0};
  struct FilterState_R001817_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int threshold_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_45_1 > 14)
  {
    acc_1 = ((acc_1 + (threshold_45_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_45_2 > 14)
  {
    acc_2 = ((acc_2 + (threshold_45_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_98_1) & 63;
  aux_2 = (aux_2 + residue_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_12_1)
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

  switch (quotient_12_2)
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
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_45_1 == threshold_45_2);
  assert(residue_98_1 == residue_98_2);
  assert(quotient_12_1 == quotient_12_2);
}

int fn_R001817_1713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001817_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int threshold_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_45 > 14)
  {
    acc = ((acc + (threshold_45 * 2)) + 5) & 127;
    aux ^= threshold_45 & 15;
  }
  else
  {
    acc = ((acc - threshold_45) + 11) & 127;
    aux += 3;
  }
  int residue_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_98) & 63;
  acc ^= aux;
  int quotient_12 = (aux + st.buffer[1]) & 3;
  switch (quotient_12)
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

void fn_R001817_1713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001817_1713_1 st_1 = {0};
  struct FilterState_R001817_1713_1 st_2 = {0};
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
  int index_reg_14_1 = 0;
  int index_reg_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_14_1 = ((index_reg_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_14_2 = ((index_reg_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_14_1) & 127;
    acc_2 = (acc_2 + index_reg_14_2) & 127;
  }

  int coefficient_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_33_1 > 21)
  {
    acc_1 = ((acc_1 + (coefficient_33_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_33_2 > 21)
  {
    acc_2 = ((acc_2 + (coefficient_33_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_33_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_14_1 == index_reg_14_2);
  assert(coefficient_33_1 == coefficient_33_2);
}

int fn_R001817_1713_6(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001817_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_14 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_14 = ((index_reg_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_14) & 127;
  }

  int coefficient_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_33 > 21)
  {
    acc = ((acc + (coefficient_33 * 2)) + 5) & 127;
    aux ^= coefficient_33 & 15;
  }
  else
  {
    acc = ((acc - coefficient_33) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001817_1713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st_1 = {0};
  struct EventLog_R001817_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_17_1 = 0;
  int tally_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_17_1 = ((tally_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_17_2 = ((tally_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_17_1) & 127;
    acc_2 = (acc_2 + tally_17_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_76_1 = local_arr_1[aux_1 % 3];
  int scale_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_76_2 * 2)) & 127;
  int factor_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_12_1) & 63;
  aux_2 = (aux_2 + factor_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_17_1 == tally_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_76_1 == scale_76_2);
  assert(factor_12_1 == factor_12_2);
}

int fn_R001817_1713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_17 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_17 = ((tally_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_17) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int scale_76 = local_arr[aux % 3];
  acc = (acc + (scale_76 * 2)) & 127;
  int factor_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_12) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001817_1713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st_1 = {0};
  struct EventLog_R001817_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int segment_95_1 = 0;
  int segment_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_95_1 = ((segment_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_95_2 = ((segment_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_95_1) & 127;
    acc_2 = (acc_2 + segment_95_2) & 127;
  }

  int vector_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_31_1) & 63;
  aux_2 = (aux_2 + vector_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_95_1 == segment_95_2);
  assert(vector_31_1 == vector_31_2);
}

int fn_R001817_1713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int segment_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_95 = ((segment_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_95) & 127;
  }

  int vector_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001817_1713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001817_1713_1 st_1 = {0};
  struct FilterState_R001817_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int window_31_1 = 0;
  int window_31_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_31_1 = ((window_31_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_31_2 = ((window_31_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_31_1) & 127;
    acc_2 = (acc_2 + window_31_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_43_1 = local_arr_1[aux_1 % 3];
  int anchor_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_43_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_31_1 == window_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_43_1 == anchor_43_2);
}

int fn_R001817_1713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001817_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int window_31 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_31 = ((window_31 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_31) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int anchor_43 = local_arr[aux % 3];
  acc = (acc + (anchor_43 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001817_1713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st_1 = {0};
  struct EventLog_R001817_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int tracker_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_83_1)
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

  switch (tracker_83_2)
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

  int factor_88_1 = 0;
  int factor_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_88_1 = ((factor_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_88_2 = ((factor_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_88_1) & 127;
    acc_2 = (acc_2 + factor_88_2) & 127;
  }

  int coefficient_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_70_1) & 63;
  aux_2 = (aux_2 + coefficient_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_71_1 > 49)
  {
    acc_1 = ((acc_1 + (anchor_71_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_71_2 > 49)
  {
    acc_2 = ((acc_2 + (anchor_71_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_71_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_83_1 == tracker_83_2);
  assert(factor_88_1 == factor_88_2);
  assert(coefficient_70_1 == coefficient_70_2);
  assert(anchor_71_1 == anchor_71_2);
}

int fn_R001817_1713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int tracker_83 = (aux + st.buffer[1]) & 3;
  switch (tracker_83)
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

  int factor_88 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_88 = ((factor_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_88) & 127;
  }

  int coefficient_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_70) & 63;
  acc ^= aux;
  int anchor_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_71 > 49)
  {
    acc = ((acc + (anchor_71 * 2)) + 5) & 127;
    aux ^= anchor_71 & 15;
  }
  else
  {
    acc = ((acc - anchor_71) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001817_1713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st_1 = {0};
  struct EventLog_R001817_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int segment_91_1 = 0;
  int segment_91_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_91_1 = ((segment_91_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_91_2 = ((segment_91_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_91_1) & 127;
    acc_2 = (acc_2 + segment_91_2) & 127;
  }

  int phase_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_89_1)
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

  switch (phase_89_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_91_1 == segment_91_2);
  assert(phase_89_1 == phase_89_2);
}

int fn_R001817_1713_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int segment_91 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_91 = ((segment_91 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_91) & 127;
  }

  int phase_89 = (aux + st.buffer[1]) & 3;
  switch (phase_89)
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
  return (acc + aux) & 255;
}

void fn_R001817_1713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st_1 = {0};
  struct EventLog_R001817_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int metric_51_1 = 0;
  int metric_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_51_1 = ((metric_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_51_2 = ((metric_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_51_1) & 127;
    acc_2 = (acc_2 + metric_51_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_83_1 > 41)
  {
    acc_1 = ((acc_1 + (anchor_83_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_83_2 > 41)
  {
    acc_2 = ((acc_2 + (anchor_83_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_83_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_51_1 == metric_51_2);
  assert(anchor_83_1 == anchor_83_2);
}

int fn_R001817_1713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int metric_51 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_51 = ((metric_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_51) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_83 > 41)
  {
    acc = ((acc + (anchor_83 * 2)) + 5) & 127;
    aux ^= anchor_83 & 15;
  }
  else
  {
    acc = ((acc - anchor_83) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001817_1713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st_1 = {0};
  struct EventLog_R001817_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_90_1 = local_arr_1[aux_1 % 3];
  int index_reg_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_90_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_90_1 == index_reg_90_2);
}

int fn_R001817_1713_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int index_reg_90 = local_arr[aux % 3];
  acc = (acc + (index_reg_90 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001817_1713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st_1 = {0};
  struct EventLog_R001817_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int metric_82_1 = 0;
  int metric_82_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_82_1 = ((metric_82_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_82_2 = ((metric_82_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_82_1) & 127;
    acc_2 = (acc_2 + metric_82_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_79_1 = local_arr_1[aux_1 % 3];
  int mask_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_79_2 * 2)) & 127;
  int threshold_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_58_1 > 24)
  {
    acc_1 = ((acc_1 + (threshold_58_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_58_2 > 24)
  {
    acc_2 = ((acc_2 + (threshold_58_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_82_1 == metric_82_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_79_1 == mask_79_2);
  assert(threshold_58_1 == threshold_58_2);
}

int fn_R001817_1713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int metric_82 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_82 = ((metric_82 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_82) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_79 = local_arr[aux % 3];
  acc = (acc + (mask_79 * 2)) & 127;
  int threshold_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_58 > 24)
  {
    acc = ((acc + (threshold_58 * 2)) + 5) & 127;
    aux ^= threshold_58 & 15;
  }
  else
  {
    acc = ((acc - threshold_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001817_1713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st_1 = {0};
  struct EventLog_R001817_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int coefficient_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_73_1) & 63;
  aux_2 = (aux_2 + coefficient_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_23_1 > 26)
  {
    acc_1 = ((acc_1 + (margin_23_1 * 2)) + 5) & 127;
    aux_1 ^= margin_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_23_2 > 26)
  {
    acc_2 = ((acc_2 + (margin_23_2 * 2)) + 5) & 127;
    aux_2 ^= margin_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_23_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_50_1 = local_arr_1[aux_1 % 3];
  int scale_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_50_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_73_1 == coefficient_73_2);
  assert(margin_23_1 == margin_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_50_1 == scale_50_2);
}

int fn_R001817_1713_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int coefficient_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_73) & 63;
  acc ^= aux;
  int margin_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_23 > 26)
  {
    acc = ((acc + (margin_23 * 2)) + 5) & 127;
    aux ^= margin_23 & 15;
  }
  else
  {
    acc = ((acc - margin_23) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_50 = local_arr[aux % 3];
  acc = (acc + (scale_50 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001817_1713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st_1 = {0};
  struct EventLog_R001817_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int threshold_52_1 = 0;
  int threshold_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_52_1 = ((threshold_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_52_2 = ((threshold_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_52_1) & 127;
    acc_2 = (acc_2 + threshold_52_2) & 127;
  }

  int parity_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_50_1) & 63;
  aux_2 = (aux_2 + parity_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_52_1 == threshold_52_2);
  assert(parity_50_1 == parity_50_2);
}

int fn_R001817_1713_16(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int threshold_52 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_52 = ((threshold_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_52) & 127;
  }

  int parity_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_50) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001817_1713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001817_1713_2 st_1 = {0};
  struct CipherContext_R001817_1713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int tracker_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_87_1)
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

  switch (tracker_87_2)
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

  int scale_46_1 = 0;
  int scale_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_46_1 = ((scale_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_46_2 = ((scale_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_46_1) & 127;
    acc_2 = (acc_2 + scale_46_2) & 127;
  }

  int sample_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_43_1) & 63;
  aux_2 = (aux_2 + sample_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_87_1 == tracker_87_2);
  assert(scale_46_1 == scale_46_2);
  assert(sample_43_1 == sample_43_2);
}

int fn_R001817_1713_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001817_1713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int tracker_87 = (aux + st.buffer[1]) & 3;
  switch (tracker_87)
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

  int scale_46 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_46 = ((scale_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_46) & 127;
  }

  int sample_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_43) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001817_1713_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001817_1713_1 st_1 = {0};
  struct FilterState_R001817_1713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int checksum_21_1 = 0;
  int checksum_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_21_1 = ((checksum_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_21_2 = ((checksum_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_21_1) & 127;
    acc_2 = (acc_2 + checksum_21_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_64_1 > 39)
  {
    acc_1 = ((acc_1 + (weight_64_1 * 2)) + 5) & 127;
    aux_1 ^= weight_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_64_2 > 39)
  {
    acc_2 = ((acc_2 + (weight_64_2 * 2)) + 5) & 127;
    aux_2 ^= weight_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_64_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_74_1) & 63;
  aux_2 = (aux_2 + quantum_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_21_1 == checksum_21_2);
  assert(weight_64_1 == weight_64_2);
  assert(quantum_74_1 == quantum_74_2);
}

int fn_R001817_1713_18(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001817_1713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int checksum_21 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_21 = ((checksum_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_21) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_64 > 39)
  {
    acc = ((acc + (weight_64 * 2)) + 5) & 127;
    aux ^= weight_64 & 15;
  }
  else
  {
    acc = ((acc - weight_64) + 11) & 127;
    aux += 3;
  }
  int quantum_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_74) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001817_1713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st_1 = {0};
  struct EventLog_R001817_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int mask_98_1 = 0;
  int mask_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_98_1 = ((mask_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_98_2 = ((mask_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_98_1) & 127;
    acc_2 = (acc_2 + mask_98_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_98_1 == mask_98_2);
}

int fn_R001817_1713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int mask_98 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_98 = ((mask_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_98) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001817_1713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st_1 = {0};
  struct EventLog_R001817_1713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int phase_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_31_1 > 26)
  {
    acc_1 = ((acc_1 + (phase_31_1 * 2)) + 5) & 127;
    aux_1 ^= phase_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_31_2 > 26)
  {
    acc_2 = ((acc_2 + (phase_31_2 * 2)) + 5) & 127;
    aux_2 ^= phase_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_15_1) & 63;
  aux_2 = (aux_2 + window_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_76_1 = 0;
  int sample_76_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_76_1 = ((sample_76_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_76_2 = ((sample_76_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_76_1) & 127;
    acc_2 = (acc_2 + sample_76_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_31_1 == phase_31_2);
  assert(window_15_1 == window_15_2);
  assert(sample_76_1 == sample_76_2);
}

int fn_R001817_1713_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001817_1713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int phase_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_31 > 26)
  {
    acc = ((acc + (phase_31 * 2)) + 5) & 127;
    aux ^= phase_31 & 15;
  }
  else
  {
    acc = ((acc - phase_31) + 11) & 127;
    aux += 3;
  }
  int window_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_15) & 63;
  acc ^= aux;
  int sample_76 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_76 = ((sample_76 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_76) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001817_0_1;
  int sec_r001817_0_2;
  int sec_r001817_1_1;
  int sec_r001817_1_2;
  int sec_r001817_2_1;
  int sec_r001817_2_2;
  int sec_r001817_3_1;
  int sec_r001817_3_2;
  int sec_r001817_4_1;
  int sec_r001817_4_2;
  int sec_r001817_5_1;
  int sec_r001817_5_2;
  int sec_r001817_6_1;
  int sec_r001817_6_2;
  int sec_r001817_7_1;
  int sec_r001817_7_2;
  int sec_r001817_8_1;
  int sec_r001817_8_2;
  int sec_r001817_9_1;
  int sec_r001817_9_2;
  int sec_r001817_10_1;
  int sec_r001817_10_2;
  int sec_r001817_11_1;
  int sec_r001817_11_2;
  int sec_r001817_12_1;
  int sec_r001817_12_2;
  int sec_r001817_13_1;
  int sec_r001817_13_2;
  int sec_r001817_14_1;
  int sec_r001817_14_2;
  int sec_r001817_15_1;
  int sec_r001817_15_2;
  int sec_r001817_16_1;
  int sec_r001817_16_2;
  int sec_r001817_17_1;
  int sec_r001817_17_2;
  int sec_r001817_18_1;
  int sec_r001817_18_2;
  int sec_r001817_19_1;
  int sec_r001817_19_2;
  int pub_r001817_0_1;
  int pub_r001817_0_2;
  int pub_r001817_1_1;
  int pub_r001817_1_2;
  int pub_r001817_2_1;
  int pub_r001817_2_2;
  int pub_r001817_3_1;
  int pub_r001817_3_2;
  int pub_r001817_4_1;
  int pub_r001817_4_2;
  int pub_r001817_5_1;
  int pub_r001817_5_2;
  int pub_r001817_6_1;
  int pub_r001817_6_2;
  int pub_r001817_7_1;
  int pub_r001817_7_2;
  int pub_r001817_8_1;
  int pub_r001817_8_2;
  int pub_r001817_9_1;
  int pub_r001817_9_2;
  int pub_r001817_10_1;
  int pub_r001817_10_2;
  int pub_r001817_11_1;
  int pub_r001817_11_2;
  int pub_r001817_12_1;
  int pub_r001817_12_2;
  int pub_r001817_13_1;
  int pub_r001817_13_2;
  int pub_r001817_14_1;
  int pub_r001817_14_2;
  int pub_r001817_15_1;
  int pub_r001817_15_2;
  int pub_r001817_16_1;
  int pub_r001817_16_2;
  int pub_r001817_17_1;
  int pub_r001817_17_2;
  int pub_r001817_18_1;
  int pub_r001817_18_2;
  int pub_r001817_19_1;
  int pub_r001817_19_2;
  int pub_r001817_20_1;
  int pub_r001817_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001817_0_1 >= (-100)) && (pub_r001817_0_1 <= 100));
  __CPROVER_assume((pub_r001817_0_2 >= (-100)) && (pub_r001817_0_2 <= 100));
  __CPROVER_assume((pub_r001817_1_1 >= (-100)) && (pub_r001817_1_1 <= 100));
  __CPROVER_assume((pub_r001817_1_2 >= (-100)) && (pub_r001817_1_2 <= 100));
  __CPROVER_assume((pub_r001817_2_1 >= (-100)) && (pub_r001817_2_1 <= 100));
  __CPROVER_assume((pub_r001817_2_2 >= (-100)) && (pub_r001817_2_2 <= 100));
  __CPROVER_assume((pub_r001817_3_1 >= (-100)) && (pub_r001817_3_1 <= 100));
  __CPROVER_assume((pub_r001817_3_2 >= (-100)) && (pub_r001817_3_2 <= 100));
  __CPROVER_assume((pub_r001817_4_1 >= (-100)) && (pub_r001817_4_1 <= 100));
  __CPROVER_assume((pub_r001817_4_2 >= (-100)) && (pub_r001817_4_2 <= 100));
  __CPROVER_assume((pub_r001817_5_1 >= (-100)) && (pub_r001817_5_1 <= 100));
  __CPROVER_assume((pub_r001817_5_2 >= (-100)) && (pub_r001817_5_2 <= 100));
  __CPROVER_assume((pub_r001817_6_1 >= (-100)) && (pub_r001817_6_1 <= 100));
  __CPROVER_assume((pub_r001817_6_2 >= (-100)) && (pub_r001817_6_2 <= 100));
  __CPROVER_assume((pub_r001817_7_1 >= (-100)) && (pub_r001817_7_1 <= 100));
  __CPROVER_assume((pub_r001817_7_2 >= (-100)) && (pub_r001817_7_2 <= 100));
  __CPROVER_assume((pub_r001817_8_1 >= (-100)) && (pub_r001817_8_1 <= 100));
  __CPROVER_assume((pub_r001817_8_2 >= (-100)) && (pub_r001817_8_2 <= 100));
  __CPROVER_assume((pub_r001817_9_1 >= (-100)) && (pub_r001817_9_1 <= 100));
  __CPROVER_assume((pub_r001817_9_2 >= (-100)) && (pub_r001817_9_2 <= 100));
  __CPROVER_assume((pub_r001817_10_1 >= (-100)) && (pub_r001817_10_1 <= 100));
  __CPROVER_assume((pub_r001817_10_2 >= (-100)) && (pub_r001817_10_2 <= 100));
  __CPROVER_assume((pub_r001817_11_1 >= (-100)) && (pub_r001817_11_1 <= 100));
  __CPROVER_assume((pub_r001817_11_2 >= (-100)) && (pub_r001817_11_2 <= 100));
  __CPROVER_assume((pub_r001817_12_1 >= (-100)) && (pub_r001817_12_1 <= 100));
  __CPROVER_assume((pub_r001817_12_2 >= (-100)) && (pub_r001817_12_2 <= 100));
  __CPROVER_assume((pub_r001817_13_1 >= (-100)) && (pub_r001817_13_1 <= 100));
  __CPROVER_assume((pub_r001817_13_2 >= (-100)) && (pub_r001817_13_2 <= 100));
  __CPROVER_assume((pub_r001817_14_1 >= (-100)) && (pub_r001817_14_1 <= 100));
  __CPROVER_assume((pub_r001817_14_2 >= (-100)) && (pub_r001817_14_2 <= 100));
  __CPROVER_assume((pub_r001817_15_1 >= (-100)) && (pub_r001817_15_1 <= 100));
  __CPROVER_assume((pub_r001817_15_2 >= (-100)) && (pub_r001817_15_2 <= 100));
  __CPROVER_assume((pub_r001817_16_1 >= (-100)) && (pub_r001817_16_1 <= 100));
  __CPROVER_assume((pub_r001817_16_2 >= (-100)) && (pub_r001817_16_2 <= 100));
  __CPROVER_assume((pub_r001817_17_1 >= (-100)) && (pub_r001817_17_1 <= 100));
  __CPROVER_assume((pub_r001817_17_2 >= (-100)) && (pub_r001817_17_2 <= 100));
  __CPROVER_assume((pub_r001817_18_1 >= (-100)) && (pub_r001817_18_1 <= 100));
  __CPROVER_assume((pub_r001817_18_2 >= (-100)) && (pub_r001817_18_2 <= 100));
  __CPROVER_assume((pub_r001817_19_1 >= (-100)) && (pub_r001817_19_1 <= 100));
  __CPROVER_assume((pub_r001817_19_2 >= (-100)) && (pub_r001817_19_2 <= 100));
  __CPROVER_assume((pub_r001817_20_1 >= (-100)) && (pub_r001817_20_1 <= 100));
  __CPROVER_assume((pub_r001817_20_2 >= (-100)) && (pub_r001817_20_2 <= 100));
  __CPROVER_assume((sec_r001817_0_1 >= 0) && (sec_r001817_0_1 <= 255));
  __CPROVER_assume((sec_r001817_0_2 >= 0) && (sec_r001817_0_2 <= 255));
  __CPROVER_assume((sec_r001817_1_1 >= 0) && (sec_r001817_1_1 <= 255));
  __CPROVER_assume((sec_r001817_1_2 >= 0) && (sec_r001817_1_2 <= 255));
  __CPROVER_assume((sec_r001817_2_1 >= 0) && (sec_r001817_2_1 <= 255));
  __CPROVER_assume((sec_r001817_2_2 >= 0) && (sec_r001817_2_2 <= 255));
  __CPROVER_assume((sec_r001817_3_1 >= 0) && (sec_r001817_3_1 <= 255));
  __CPROVER_assume((sec_r001817_3_2 >= 0) && (sec_r001817_3_2 <= 255));
  __CPROVER_assume((sec_r001817_4_1 >= 0) && (sec_r001817_4_1 <= 255));
  __CPROVER_assume((sec_r001817_4_2 >= 0) && (sec_r001817_4_2 <= 255));
  __CPROVER_assume((sec_r001817_5_1 >= 0) && (sec_r001817_5_1 <= 255));
  __CPROVER_assume((sec_r001817_5_2 >= 0) && (sec_r001817_5_2 <= 255));
  __CPROVER_assume((sec_r001817_6_1 >= 0) && (sec_r001817_6_1 <= 255));
  __CPROVER_assume((sec_r001817_6_2 >= 0) && (sec_r001817_6_2 <= 255));
  __CPROVER_assume((sec_r001817_7_1 >= 0) && (sec_r001817_7_1 <= 255));
  __CPROVER_assume((sec_r001817_7_2 >= 0) && (sec_r001817_7_2 <= 255));
  __CPROVER_assume((sec_r001817_8_1 >= 0) && (sec_r001817_8_1 <= 255));
  __CPROVER_assume((sec_r001817_8_2 >= 0) && (sec_r001817_8_2 <= 255));
  __CPROVER_assume((sec_r001817_9_1 >= 0) && (sec_r001817_9_1 <= 255));
  __CPROVER_assume((sec_r001817_9_2 >= 0) && (sec_r001817_9_2 <= 255));
  __CPROVER_assume((sec_r001817_10_1 >= 0) && (sec_r001817_10_1 <= 255));
  __CPROVER_assume((sec_r001817_10_2 >= 0) && (sec_r001817_10_2 <= 255));
  __CPROVER_assume((sec_r001817_11_1 >= 0) && (sec_r001817_11_1 <= 255));
  __CPROVER_assume((sec_r001817_11_2 >= 0) && (sec_r001817_11_2 <= 255));
  __CPROVER_assume((sec_r001817_12_1 >= 0) && (sec_r001817_12_1 <= 255));
  __CPROVER_assume((sec_r001817_12_2 >= 0) && (sec_r001817_12_2 <= 255));
  __CPROVER_assume((sec_r001817_13_1 >= 0) && (sec_r001817_13_1 <= 255));
  __CPROVER_assume((sec_r001817_13_2 >= 0) && (sec_r001817_13_2 <= 255));
  __CPROVER_assume((sec_r001817_14_1 >= 0) && (sec_r001817_14_1 <= 255));
  __CPROVER_assume((sec_r001817_14_2 >= 0) && (sec_r001817_14_2 <= 255));
  __CPROVER_assume((sec_r001817_15_1 >= 0) && (sec_r001817_15_1 <= 255));
  __CPROVER_assume((sec_r001817_15_2 >= 0) && (sec_r001817_15_2 <= 255));
  __CPROVER_assume((sec_r001817_16_1 >= 0) && (sec_r001817_16_1 <= 255));
  __CPROVER_assume((sec_r001817_16_2 >= 0) && (sec_r001817_16_2 <= 255));
  __CPROVER_assume((sec_r001817_17_1 >= 0) && (sec_r001817_17_1 <= 255));
  __CPROVER_assume((sec_r001817_17_2 >= 0) && (sec_r001817_17_2 <= 255));
  __CPROVER_assume((sec_r001817_18_1 >= 0) && (sec_r001817_18_1 <= 255));
  __CPROVER_assume((sec_r001817_18_2 >= 0) && (sec_r001817_18_2 <= 255));
  __CPROVER_assume((sec_r001817_19_1 >= 0) && (sec_r001817_19_1 <= 255));
  __CPROVER_assume((sec_r001817_19_2 >= 0) && (sec_r001817_19_2 <= 255));
  struct EventLog_R001817_1713_0 st_var_0_1 = {0};
  struct EventLog_R001817_1713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001817_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001817_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001817_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001817_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001817_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001817_0_2 + 7) & 15;
  struct FilterState_R001817_1713_1 st_var_1_1 = {0};
  struct FilterState_R001817_1713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001817_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001817_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001817_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001817_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001817_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001817_0_2 + 9) & 15;
  struct CipherContext_R001817_1713_2 st_var_2_1 = {0};
  struct CipherContext_R001817_1713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001817_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001817_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001817_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001817_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001817_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001817_0_2 + 11) & 15;
  union TelemetryField_R001817_1713_0 u_var_1;
  union TelemetryField_R001817_1713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001817_1713_0(sec_r001817_0_1, sec_r001817_1_1);
  int helper_flow_0_2 = fn_R001817_1713_0(sec_r001817_0_2, sec_r001817_1_2);
  fn_R001817_1713_0_2(sec_r001817_0_1, sec_r001817_1_1, sec_r001817_0_2, sec_r001817_1_2);
  int helper_flow_1_1 = fn_R001817_1713_1(sec_r001817_1_1, sec_r001817_2_1);
  int helper_flow_1_2 = fn_R001817_1713_1(sec_r001817_1_2, sec_r001817_2_2);
  fn_R001817_1713_1_2(sec_r001817_1_1, sec_r001817_2_1, sec_r001817_1_2, sec_r001817_2_2);
  int helper_flow_2_1 = fn_R001817_1713_2(sec_r001817_2_1, sec_r001817_3_1, pub_r001817_4_1, pub_r001817_5_1, pub_r001817_6_1);
  int helper_flow_2_2 = fn_R001817_1713_2(sec_r001817_2_2, sec_r001817_3_2, pub_r001817_4_2, pub_r001817_5_2, pub_r001817_6_2);
  fn_R001817_1713_2_2(sec_r001817_2_1, sec_r001817_3_1, pub_r001817_4_1, pub_r001817_5_1, pub_r001817_6_1, sec_r001817_2_2, sec_r001817_3_2, pub_r001817_4_2, pub_r001817_5_2, pub_r001817_6_2);
  int helper_flow_3_1 = fn_R001817_1713_3(sec_r001817_3_1, pub_r001817_4_1, pub_r001817_5_1, pub_r001817_6_1);
  int helper_flow_3_2 = fn_R001817_1713_3(sec_r001817_3_2, pub_r001817_4_2, pub_r001817_5_2, pub_r001817_6_2);
  fn_R001817_1713_3_2(sec_r001817_3_1, pub_r001817_4_1, pub_r001817_5_1, pub_r001817_6_1, sec_r001817_3_2, pub_r001817_4_2, pub_r001817_5_2, pub_r001817_6_2);
  int helper_flow_4_1 = fn_R001817_1713_4(sec_r001817_4_1, sec_r001817_5_1);
  int helper_flow_4_2 = fn_R001817_1713_4(sec_r001817_4_2, sec_r001817_5_2);
  fn_R001817_1713_4_2(sec_r001817_4_1, sec_r001817_5_1, sec_r001817_4_2, sec_r001817_5_2);
  int helper_flow_5_1 = fn_R001817_1713_5(sec_r001817_5_1, sec_r001817_6_1, pub_r001817_7_1, pub_r001817_8_1);
  int helper_flow_5_2 = fn_R001817_1713_5(sec_r001817_5_2, sec_r001817_6_2, pub_r001817_7_2, pub_r001817_8_2);
  fn_R001817_1713_5_2(sec_r001817_5_1, sec_r001817_6_1, pub_r001817_7_1, pub_r001817_8_1, sec_r001817_5_2, sec_r001817_6_2, pub_r001817_7_2, pub_r001817_8_2);
  int helper_flow_6_1 = fn_R001817_1713_6(sec_r001817_6_1, pub_r001817_7_1);
  int helper_flow_6_2 = fn_R001817_1713_6(sec_r001817_6_2, pub_r001817_7_2);
  fn_R001817_1713_6_2(sec_r001817_6_1, pub_r001817_7_1, sec_r001817_6_2, pub_r001817_7_2);
  int helper_flow_7_1 = fn_R001817_1713_7(sec_r001817_7_1, pub_r001817_8_1, pub_r001817_9_1);
  int helper_flow_7_2 = fn_R001817_1713_7(sec_r001817_7_2, pub_r001817_8_2, pub_r001817_9_2);
  fn_R001817_1713_7_2(sec_r001817_7_1, pub_r001817_8_1, pub_r001817_9_1, sec_r001817_7_2, pub_r001817_8_2, pub_r001817_9_2);
  int stage_v_0_1 = ((pub_r001817_11_1 * 2) + 28) & 63;
  int stage_v_0_2 = ((pub_r001817_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (sec_r001817_19_1 ^ pub_r001817_11_1) & 63;
  int stage_v_1_2 = (sec_r001817_19_2 ^ pub_r001817_11_2) & 63;
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
  int stage_v_2_1 = (sec_r001817_19_1 ^ pub_r001817_4_1) & 63;
  int stage_v_2_2 = (sec_r001817_19_2 ^ pub_r001817_4_2) & 63;
  if ((stage_v_2_1 & 1) != 0)
  {
    if ((sec_r001817_3_1 & 2) != 0)
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
    if ((sec_r001817_3_2 & 2) != 0)
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
  int stage_v_3_1 = ((pub_r001817_7_1 * 2) + 30) & 63;
  int stage_v_3_2 = ((pub_r001817_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (sec_r001817_12_1 ^ pub_r001817_18_1) & 63;
  int stage_v_4_2 = (sec_r001817_12_2 ^ pub_r001817_18_2) & 63;
  if ((stage_v_4_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
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
    if ((helper_flow_2_2 & 2) != 0)
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
  int stage_v_5_1 = (stage_v_2_1 ^ pub_r001817_8_1) & 63;
  int stage_v_5_2 = (stage_v_2_2 ^ pub_r001817_8_2) & 63;
  if ((stage_v_5_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
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
    if ((helper_flow_5_2 & 2) != 0)
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
  int stage_v_6_1 = (stage_v_5_1 ^ pub_r001817_6_1) & 63;
  int stage_v_6_2 = (stage_v_5_2 ^ pub_r001817_6_2) & 63;
  if ((stage_v_6_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_6_1 * 2)) & 255;
  }
  if ((stage_v_6_2 & 1) != 0)
  {
    if ((helper_flow_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_6_2 * 2)) & 255;
  }
  int stage_v_7_1 = ((pub_r001817_18_1 * 2) + 16) & 63;
  int stage_v_7_2 = ((pub_r001817_18_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (helper_flow_7_1 ^ pub_r001817_18_1) & 63;
  int stage_v_8_2 = (helper_flow_7_2 ^ pub_r001817_18_2) & 63;
  if ((stage_v_8_1 & 1) != 0)
  {
    if ((sec_r001817_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_8_1 * 2)) & 255;
  }
  if ((stage_v_8_2 & 1) != 0)
  {
    if ((sec_r001817_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_8_2 * 2)) & 255;
  }
  int stage_v_9_1 = ((pub_r001817_12_1 * 2) + 32) & 63;
  int stage_v_9_2 = ((pub_r001817_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (stage_v_8_1 ^ pub_r001817_14_1) & 63;
  int stage_v_10_2 = (stage_v_8_2 ^ pub_r001817_14_2) & 63;
  if ((stage_v_10_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_10_1 * 2)) & 255;
  }
  if ((stage_v_10_2 & 1) != 0)
  {
    if ((helper_flow_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_10_2 * 2)) & 255;
  }
  int stage_v_11_1 = ((pub_r001817_18_1 * 2) + 31) & 63;
  int stage_v_11_2 = ((pub_r001817_18_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (sec_r001817_19_1 ^ pub_r001817_4_1) & 63;
  int stage_v_12_2 = (sec_r001817_19_2 ^ pub_r001817_4_2) & 63;
  if ((stage_v_12_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_12_1 * 2)) & 255;
  }
  if ((stage_v_12_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_12_2 * 2)) & 255;
  }
  int stage_v_13_1 = (sec_r001817_18_1 ^ pub_r001817_2_1) & 63;
  int stage_v_13_2 = (sec_r001817_18_2 ^ pub_r001817_2_2) & 63;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_13_1 * 2)) & 255;
  }
  if ((stage_v_13_2 & 1) != 0)
  {
    if ((stage_v_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_13_2 * 2)) & 255;
  }
  int stage_v_14_1 = (helper_flow_1_1 ^ pub_r001817_5_1) & 63;
  int stage_v_14_2 = (helper_flow_1_2 ^ pub_r001817_5_2) & 63;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((sec_r001817_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_14_1 * 2)) & 255;
  }
  if ((stage_v_14_2 & 1) != 0)
  {
    if ((sec_r001817_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_14_2 * 2)) & 255;
  }
  int stage_v_15_1 = (sec_r001817_16_1 ^ pub_r001817_13_1) & 63;
  int stage_v_15_2 = (sec_r001817_16_2 ^ pub_r001817_13_2) & 63;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((stage_v_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_15_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_15_1 * 2)) & 255;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((stage_v_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_15_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_15_2 * 2)) & 255;
  }
  int stage_v_16_1 = ((pub_r001817_8_1 * 2) + 20) & 63;
  int stage_v_16_2 = ((pub_r001817_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001817_16_1 * 2) + 41) & 63;
  int stage_v_17_2 = ((pub_r001817_16_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001817_14_1 * 2) + 7) & 63;
  int stage_v_18_2 = ((pub_r001817_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001817_19_1 * 2) + 37) & 63;
  int stage_v_19_2 = ((pub_r001817_19_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (sec_r001817_11_1 ^ pub_r001817_2_1) & 63;
  int stage_v_20_2 = (sec_r001817_11_2 ^ pub_r001817_2_2) & 63;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r001817_8_1 & 2) != 0)
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
    if ((sec_r001817_8_2 & 2) != 0)
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
  int stage_v_21_1 = (sec_r001817_17_1 ^ pub_r001817_14_1) & 63;
  int stage_v_21_2 = (sec_r001817_17_2 ^ pub_r001817_14_2) & 63;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((sec_r001817_3_1 & 2) != 0)
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
    if ((sec_r001817_3_2 & 2) != 0)
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
  int stage_v_22_1 = (stage_v_13_1 ^ pub_r001817_14_1) & 63;
  int stage_v_22_2 = (stage_v_13_2 ^ pub_r001817_14_2) & 63;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((stage_v_4_1 & 2) != 0)
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
    if ((stage_v_4_2 & 2) != 0)
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
  int stage_v_23_1 = ((pub_r001817_12_1 * 2) + 40) & 63;
  int stage_v_23_2 = ((pub_r001817_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (sec_r001817_13_1 ^ pub_r001817_2_1) & 63;
  int stage_v_24_2 = (sec_r001817_13_2 ^ pub_r001817_2_2) & 63;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((stage_v_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_24_1 * 2)) & 255;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((stage_v_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_24_2 * 2)) & 255;
  }
  int stage_v_25_1 = (stage_v_24_1 ^ pub_r001817_20_1) & 63;
  int stage_v_25_2 = (stage_v_24_2 ^ pub_r001817_20_2) & 63;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((stage_v_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_25_1 * 2)) & 255;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((stage_v_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_25_2 * 2)) & 255;
  }
  int stage_v_26_1 = (helper_flow_6_1 ^ pub_r001817_13_1) & 63;
  int stage_v_26_2 = (helper_flow_6_2 ^ pub_r001817_13_2) & 63;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
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
    if ((helper_flow_4_2 & 2) != 0)
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
  int stage_v_27_1 = ((pub_r001817_13_1 * 2) + 47) & 63;
  int stage_v_27_2 = ((pub_r001817_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (stage_v_24_1 ^ pub_r001817_6_1) & 63;
  int stage_v_28_2 = (stage_v_24_2 ^ pub_r001817_6_2) & 63;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r001817_18_1 & 2) != 0)
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
    if ((sec_r001817_18_2 & 2) != 0)
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
  int stage_v_29_1 = (stage_v_8_1 ^ pub_r001817_18_1) & 63;
  int stage_v_29_2 = (stage_v_8_2 ^ pub_r001817_18_2) & 63;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_29_1 * 2)) & 255;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((helper_flow_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_29_2 * 2)) & 255;
  }
  int stage_v_30_1 = (sec_r001817_10_1 ^ pub_r001817_10_1) & 63;
  int stage_v_30_2 = (sec_r001817_10_2 ^ pub_r001817_10_2) & 63;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
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
    if ((helper_flow_1_2 & 2) != 0)
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
  int stage_v_31_1 = (helper_flow_6_1 ^ pub_r001817_11_1) & 63;
  int stage_v_31_2 = (helper_flow_6_2 ^ pub_r001817_11_2) & 63;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r001817_9_1 & 2) != 0)
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
    if ((sec_r001817_9_2 & 2) != 0)
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
  int stage_v_32_1 = (stage_v_31_1 ^ pub_r001817_16_1) & 63;
  int stage_v_32_2 = (stage_v_31_2 ^ pub_r001817_16_2) & 63;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((stage_v_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_32_1 * 2)) & 255;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((stage_v_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_32_2 * 2)) & 255;
  }
  int stage_v_33_1 = (sec_r001817_3_1 ^ pub_r001817_6_1) & 63;
  int stage_v_33_2 = (sec_r001817_3_2 ^ pub_r001817_6_2) & 63;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((stage_v_31_1 & 2) != 0)
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
    if ((stage_v_31_2 & 2) != 0)
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
  int stage_v_34_1 = (sec_r001817_17_1 ^ pub_r001817_6_1) & 63;
  int stage_v_34_2 = (sec_r001817_17_2 ^ pub_r001817_6_2) & 63;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r001817_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_34_1 * 2)) & 255;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r001817_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_34_2 * 2)) & 255;
  }
  int stage_v_35_1 = ((pub_r001817_2_1 * 2) + 22) & 63;
  int stage_v_35_2 = ((pub_r001817_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001817_8_1 * 2) + 6) & 63;
  int stage_v_36_2 = ((pub_r001817_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (sec_r001817_14_1 ^ pub_r001817_8_1) & 63;
  int stage_v_37_2 = (sec_r001817_14_2 ^ pub_r001817_8_2) & 63;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r001817_10_1 & 2) != 0)
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
    if ((sec_r001817_10_2 & 2) != 0)
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
  int stage_v_38_1 = (stage_v_10_1 ^ pub_r001817_10_1) & 63;
  int stage_v_38_2 = (stage_v_10_2 ^ pub_r001817_10_2) & 63;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
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
    if ((stage_v_21_2 & 2) != 0)
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
  int stage_v_39_1 = ((pub_r001817_9_1 * 2) + 15) & 63;
  int stage_v_39_2 = ((pub_r001817_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (helper_flow_5_1 ^ pub_r001817_3_1) & 63;
  int stage_v_40_2 = (helper_flow_5_2 ^ pub_r001817_3_2) & 63;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((stage_v_14_1 & 2) != 0)
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
    if ((stage_v_14_2 & 2) != 0)
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
  int stage_v_41_1 = (stage_v_2_1 ^ pub_r001817_19_1) & 63;
  int stage_v_41_2 = (stage_v_2_2 ^ pub_r001817_19_2) & 63;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((stage_v_25_1 & 2) != 0)
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
    if ((stage_v_25_2 & 2) != 0)
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
  int stage_v_42_1 = (stage_v_28_1 ^ pub_r001817_17_1) & 63;
  int stage_v_42_2 = (stage_v_28_2 ^ pub_r001817_17_2) & 63;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
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
    if ((helper_flow_5_2 & 2) != 0)
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
  int stage_v_43_1 = ((pub_r001817_17_1 * 2) + 20) & 63;
  int stage_v_43_2 = ((pub_r001817_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (sec_r001817_7_1 ^ pub_r001817_16_1) & 63;
  int stage_v_44_2 = (sec_r001817_7_2 ^ pub_r001817_16_2) & 63;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((stage_v_22_1 & 2) != 0)
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
    if ((stage_v_22_2 & 2) != 0)
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
  int stage_v_45_1 = (sec_r001817_9_1 ^ pub_r001817_0_1) & 63;
  int stage_v_45_2 = (sec_r001817_9_2 ^ pub_r001817_0_2) & 63;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
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
    if ((helper_flow_2_2 & 2) != 0)
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
  int stage_v_46_1 = ((pub_r001817_5_1 * 2) + 26) & 63;
  int stage_v_46_2 = ((pub_r001817_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (stage_v_31_1 ^ pub_r001817_16_1) & 63;
  int stage_v_47_2 = (stage_v_31_2 ^ pub_r001817_16_2) & 63;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r001817_17_1 & 2) != 0)
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
    if ((sec_r001817_17_2 & 2) != 0)
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
  int stage_v_48_1 = (sec_r001817_4_1 ^ pub_r001817_3_1) & 63;
  int stage_v_48_2 = (sec_r001817_4_2 ^ pub_r001817_3_2) & 63;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_48_1 * 2)) & 255;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_48_2 * 2)) & 255;
  }
  int stage_v_49_1 = (stage_v_34_1 ^ pub_r001817_0_1) & 63;
  int stage_v_49_2 = (stage_v_34_2 ^ pub_r001817_0_2) & 63;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
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
    if ((stage_v_40_2 & 2) != 0)
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
  int stage_v_50_1 = (helper_flow_1_1 ^ pub_r001817_1_1) & 63;
  int stage_v_50_2 = (helper_flow_1_2 ^ pub_r001817_1_2) & 63;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r001817_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_50_1 * 2)) & 255;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r001817_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_50_2 * 2)) & 255;
  }
  int stage_v_51_1 = (sec_r001817_19_1 ^ pub_r001817_19_1) & 63;
  int stage_v_51_2 = (sec_r001817_19_2 ^ pub_r001817_19_2) & 63;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((stage_v_28_1 & 2) != 0)
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
    if ((stage_v_28_2 & 2) != 0)
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
  int stage_v_52_1 = (sec_r001817_1_1 ^ pub_r001817_20_1) & 63;
  int stage_v_52_2 = (sec_r001817_1_2 ^ pub_r001817_20_2) & 63;
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
  int stage_v_53_1 = (sec_r001817_2_1 ^ pub_r001817_5_1) & 63;
  int stage_v_53_2 = (sec_r001817_2_2 ^ pub_r001817_5_2) & 63;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_53_1 * 2)) & 255;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_53_2 * 2)) & 255;
  }
  int stage_v_54_1 = (stage_v_6_1 ^ pub_r001817_3_1) & 63;
  int stage_v_54_2 = (stage_v_6_2 ^ pub_r001817_3_2) & 63;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((stage_v_45_1 & 2) != 0)
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
    if ((stage_v_45_2 & 2) != 0)
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
  int stage_v_55_1 = (stage_v_1_1 ^ pub_r001817_1_1) & 63;
  int stage_v_55_2 = (stage_v_1_2 ^ pub_r001817_1_2) & 63;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((stage_v_31_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_55_1 * 2)) & 255;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((stage_v_31_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_55_2 * 2)) & 255;
  }
  int stage_v_56_1 = (helper_flow_6_1 ^ pub_r001817_11_1) & 63;
  int stage_v_56_2 = (helper_flow_6_2 ^ pub_r001817_11_2) & 63;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((stage_v_28_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_56_1 * 2)) & 255;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((stage_v_28_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_56_2 * 2)) & 255;
  }
  int stage_v_57_1 = ((pub_r001817_16_1 * 2) + 16) & 63;
  int stage_v_57_2 = ((pub_r001817_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = (stage_v_13_1 ^ pub_r001817_12_1) & 63;
  int stage_v_58_2 = (stage_v_13_2 ^ pub_r001817_12_2) & 63;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r001817_14_1 & 2) != 0)
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
    if ((sec_r001817_14_2 & 2) != 0)
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
  int stage_v_59_1 = (helper_flow_0_1 ^ pub_r001817_18_1) & 63;
  int stage_v_59_2 = (helper_flow_0_2 ^ pub_r001817_18_2) & 63;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((helper_flow_2_1 & 2) != 0)
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
    if ((helper_flow_2_2 & 2) != 0)
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
  int stage_v_60_1 = (stage_v_37_1 ^ pub_r001817_1_1) & 63;
  int stage_v_60_2 = (stage_v_37_2 ^ pub_r001817_1_2) & 63;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
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
    if ((stage_v_21_2 & 2) != 0)
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
  int stage_v_61_1 = (sec_r001817_2_1 ^ pub_r001817_15_1) & 63;
  int stage_v_61_2 = (sec_r001817_2_2 ^ pub_r001817_15_2) & 63;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r001817_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_61_1 * 2)) & 255;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r001817_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_61_2 * 2)) & 255;
  }
  int stage_v_62_1 = ((pub_r001817_16_1 * 2) + 27) & 63;
  int stage_v_62_2 = ((pub_r001817_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (sec_r001817_9_1 ^ pub_r001817_5_1) & 63;
  int stage_v_63_2 = (sec_r001817_9_2 ^ pub_r001817_5_2) & 63;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
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
    if ((stage_v_30_2 & 2) != 0)
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
  int stage_v_64_1 = ((pub_r001817_18_1 * 2) + 50) & 63;
  int stage_v_64_2 = ((pub_r001817_18_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001817_1_1 * 2) + 25) & 63;
  int stage_v_65_2 = ((pub_r001817_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (stage_v_54_1 ^ pub_r001817_13_1) & 63;
  int stage_v_66_2 = (stage_v_54_2 ^ pub_r001817_13_2) & 63;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r001817_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_66_1 * 2)) & 255;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r001817_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_66_2 * 2)) & 255;
  }
  int stage_v_67_1 = (sec_r001817_17_1 ^ pub_r001817_11_1) & 63;
  int stage_v_67_2 = (sec_r001817_17_2 ^ pub_r001817_11_2) & 63;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((stage_v_38_1 & 2) != 0)
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
    if ((stage_v_38_2 & 2) != 0)
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
  int stage_v_68_1 = (stage_v_40_1 ^ pub_r001817_6_1) & 63;
  int stage_v_68_2 = (stage_v_40_2 ^ pub_r001817_6_2) & 63;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
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
    if ((stage_v_34_2 & 2) != 0)
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
  int stage_v_69_1 = (stage_v_31_1 ^ pub_r001817_16_1) & 63;
  int stage_v_69_2 = (stage_v_31_2 ^ pub_r001817_16_2) & 63;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((stage_v_56_1 & 2) != 0)
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
    if ((stage_v_56_2 & 2) != 0)
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
  int stage_v_70_1 = (stage_v_47_1 ^ pub_r001817_12_1) & 63;
  int stage_v_70_2 = (stage_v_47_2 ^ pub_r001817_12_2) & 63;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
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
    if ((helper_flow_0_2 & 2) != 0)
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
  int stage_v_71_1 = (stage_v_59_1 ^ pub_r001817_20_1) & 63;
  int stage_v_71_2 = (stage_v_59_2 ^ pub_r001817_20_2) & 63;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((stage_v_58_1 & 2) != 0)
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
    if ((stage_v_58_2 & 2) != 0)
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
  int stage_v_72_1 = (stage_v_14_1 ^ pub_r001817_5_1) & 63;
  int stage_v_72_2 = (stage_v_14_2 ^ pub_r001817_5_2) & 63;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((stage_v_24_1 & 2) != 0)
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
    if ((stage_v_24_2 & 2) != 0)
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
  int stage_v_73_1 = ((pub_r001817_6_1 * 2) + 16) & 63;
  int stage_v_73_2 = ((pub_r001817_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001817_4_1 * 2) + 45) & 63;
  int stage_v_74_2 = ((pub_r001817_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (stage_v_67_1 ^ pub_r001817_0_1) & 63;
  int stage_v_75_2 = (stage_v_67_2 ^ pub_r001817_0_2) & 63;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((stage_v_24_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_75_1 * 2)) & 255;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((stage_v_24_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_75_2 * 2)) & 255;
  }
  int stage_v_76_1 = ((pub_r001817_20_1 * 2) + 26) & 63;
  int stage_v_76_2 = ((pub_r001817_20_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001817_4_1 * 2) + 34) & 63;
  int stage_v_77_2 = ((pub_r001817_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = (stage_v_34_1 ^ pub_r001817_2_1) & 63;
  int stage_v_78_2 = (stage_v_34_2 ^ pub_r001817_2_2) & 63;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((stage_v_33_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_78_1 * 2)) & 255;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((stage_v_33_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_78_2 * 2)) & 255;
  }
  int stage_v_79_1 = (stage_v_72_1 ^ pub_r001817_17_1) & 63;
  int stage_v_79_2 = (stage_v_72_2 ^ pub_r001817_17_2) & 63;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((stage_v_29_1 & 2) != 0)
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
    if ((stage_v_29_2 & 2) != 0)
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
  int stage_v_80_1 = (sec_r001817_6_1 ^ pub_r001817_20_1) & 63;
  int stage_v_80_2 = (sec_r001817_6_2 ^ pub_r001817_20_2) & 63;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
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
    if ((stage_v_34_2 & 2) != 0)
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
  int stage_v_81_1 = (stage_v_33_1 ^ pub_r001817_14_1) & 63;
  int stage_v_81_2 = (stage_v_33_2 ^ pub_r001817_14_2) & 63;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((stage_v_79_1 & 2) != 0)
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
    if ((stage_v_79_2 & 2) != 0)
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
  int stage_v_82_1 = ((pub_r001817_5_1 * 2) + 45) & 63;
  int stage_v_82_2 = ((pub_r001817_5_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (stage_v_29_1 ^ pub_r001817_5_1) & 63;
  int stage_v_83_2 = (stage_v_29_2 ^ pub_r001817_5_2) & 63;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r001817_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r001817_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  }
  int stage_v_84_1 = (stage_v_1_1 ^ pub_r001817_20_1) & 63;
  int stage_v_84_2 = (stage_v_1_2 ^ pub_r001817_20_2) & 63;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
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
    if ((stage_v_1_2 & 2) != 0)
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
  int stage_v_85_1 = ((pub_r001817_18_1 * 2) + 50) & 63;
  int stage_v_85_2 = ((pub_r001817_18_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001817_4_1 * 2) + 33) & 63;
  int stage_v_86_2 = ((pub_r001817_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001817_18_1 * 2) + 7) & 63;
  int stage_v_87_2 = ((pub_r001817_18_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (sec_r001817_16_1 ^ pub_r001817_9_1) & 63;
  int stage_v_88_2 = (sec_r001817_16_2 ^ pub_r001817_9_2) & 63;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((stage_v_72_1 & 2) != 0)
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
    if ((stage_v_72_2 & 2) != 0)
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
  int stage_v_89_1 = ((pub_r001817_10_1 * 2) + 36) & 63;
  int stage_v_89_2 = ((pub_r001817_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (sec_r001817_13_1 ^ pub_r001817_9_1) & 63;
  int stage_v_90_2 = (sec_r001817_13_2 ^ pub_r001817_9_2) & 63;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((stage_v_54_1 & 2) != 0)
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
    if ((stage_v_54_2 & 2) != 0)
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
  int stage_v_91_1 = (sec_r001817_9_1 ^ pub_r001817_16_1) & 63;
  int stage_v_91_2 = (sec_r001817_9_2 ^ pub_r001817_16_2) & 63;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r001817_18_1 & 2) != 0)
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
    if ((sec_r001817_18_2 & 2) != 0)
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
  int stage_v_92_1 = (stage_v_2_1 ^ pub_r001817_5_1) & 63;
  int stage_v_92_2 = (stage_v_2_2 ^ pub_r001817_5_2) & 63;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r001817_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_92_1 * 2)) & 255;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r001817_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_92_2 * 2)) & 255;
  }
  int stage_v_93_1 = (stage_v_42_1 ^ pub_r001817_6_1) & 63;
  int stage_v_93_2 = (stage_v_42_2 ^ pub_r001817_6_2) & 63;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((stage_v_48_1 & 2) != 0)
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
    if ((stage_v_48_2 & 2) != 0)
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
  int stage_v_94_1 = (helper_flow_6_1 ^ pub_r001817_5_1) & 63;
  int stage_v_94_2 = (helper_flow_6_2 ^ pub_r001817_5_2) & 63;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r001817_15_1 & 2) != 0)
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
    if ((sec_r001817_15_2 & 2) != 0)
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
  int stage_v_95_1 = ((pub_r001817_15_1 * 2) + 38) & 63;
  int stage_v_95_2 = ((pub_r001817_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001817_4_1 * 2) + 38) & 63;
  int stage_v_96_2 = ((pub_r001817_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (stage_v_91_1 ^ pub_r001817_8_1) & 63;
  int stage_v_97_2 = (stage_v_91_2 ^ pub_r001817_8_2) & 63;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r001817_15_1 & 2) != 0)
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
    if ((sec_r001817_15_2 & 2) != 0)
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
  int stage_v_98_1 = (stage_v_59_1 ^ pub_r001817_9_1) & 63;
  int stage_v_98_2 = (stage_v_59_2 ^ pub_r001817_9_2) & 63;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((stage_v_88_1 & 2) != 0)
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
    if ((stage_v_88_2 & 2) != 0)
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
  int stage_v_99_1 = ((pub_r001817_4_1 * 2) + 39) & 63;
  int stage_v_99_2 = ((pub_r001817_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (stage_v_98_1 ^ pub_r001817_6_1) & 63;
  int stage_v_100_2 = (stage_v_98_2 ^ pub_r001817_6_2) & 63;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((stage_v_67_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_100_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_100_1 * 2)) & 255;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((stage_v_67_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_100_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_100_2 * 2)) & 255;
  }
  int stage_v_101_1 = (stage_v_13_1 ^ pub_r001817_7_1) & 63;
  int stage_v_101_2 = (stage_v_13_2 ^ pub_r001817_7_2) & 63;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((stage_v_56_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_101_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_101_1 * 2)) & 255;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((stage_v_56_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_101_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_101_2 * 2)) & 255;
  }
  int stage_v_102_1 = (stage_v_38_1 ^ pub_r001817_7_1) & 63;
  int stage_v_102_2 = (stage_v_38_2 ^ pub_r001817_7_2) & 63;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
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
    if ((stage_v_44_2 & 2) != 0)
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
  int stage_v_103_1 = (stage_v_60_1 ^ pub_r001817_20_1) & 63;
  int stage_v_103_2 = (stage_v_60_2 ^ pub_r001817_20_2) & 63;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r001817_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_103_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_103_1 * 2)) & 255;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r001817_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_103_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_103_2 * 2)) & 255;
  }
  int stage_v_104_1 = (sec_r001817_5_1 ^ pub_r001817_16_1) & 63;
  int stage_v_104_2 = (sec_r001817_5_2 ^ pub_r001817_16_2) & 63;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((stage_v_51_1 & 2) != 0)
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
    if ((stage_v_51_2 & 2) != 0)
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
  int stage_v_105_1 = (stage_v_59_1 ^ pub_r001817_9_1) & 63;
  int stage_v_105_2 = (stage_v_59_2 ^ pub_r001817_9_2) & 63;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r001817_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_105_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_105_1 * 2)) & 255;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r001817_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_105_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_105_2 * 2)) & 255;
  }
  int stage_v_106_1 = (sec_r001817_9_1 ^ pub_r001817_10_1) & 63;
  int stage_v_106_2 = (sec_r001817_9_2 ^ pub_r001817_10_2) & 63;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((stage_v_20_1 & 2) != 0)
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
    if ((stage_v_20_2 & 2) != 0)
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
  int stage_v_107_1 = ((pub_r001817_17_1 * 2) + 9) & 63;
  int stage_v_107_2 = ((pub_r001817_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001817_2_1 * 2) + 23) & 63;
  int stage_v_108_2 = ((pub_r001817_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (stage_v_92_1 ^ pub_r001817_15_1) & 63;
  int stage_v_109_2 = (stage_v_92_2 ^ pub_r001817_15_2) & 63;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((stage_v_83_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_109_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((stage_v_83_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_109_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  }
  int stage_v_110_1 = (stage_v_59_1 ^ pub_r001817_18_1) & 63;
  int stage_v_110_2 = (stage_v_59_2 ^ pub_r001817_18_2) & 63;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((stage_v_88_1 & 2) != 0)
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
    if ((stage_v_88_2 & 2) != 0)
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
  int stage_v_111_1 = (stage_v_53_1 ^ pub_r001817_13_1) & 63;
  int stage_v_111_2 = (stage_v_53_2 ^ pub_r001817_13_2) & 63;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((stage_v_60_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_111_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((stage_v_60_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_111_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  }
  int stage_v_112_1 = ((pub_r001817_1_1 * 2) + 50) & 63;
  int stage_v_112_2 = ((pub_r001817_1_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (sec_r001817_3_1 ^ pub_r001817_6_1) & 63;
  int stage_v_113_2 = (sec_r001817_3_2 ^ pub_r001817_6_2) & 63;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((stage_v_66_1 & 2) != 0)
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
    if ((stage_v_66_2 & 2) != 0)
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
  int stage_v_114_1 = (stage_v_8_1 ^ pub_r001817_6_1) & 63;
  int stage_v_114_2 = (stage_v_8_2 ^ pub_r001817_6_2) & 63;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((stage_v_63_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_114_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((stage_v_63_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_114_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  }
  int stage_v_115_1 = (sec_r001817_7_1 ^ pub_r001817_17_1) & 63;
  int stage_v_115_2 = (sec_r001817_7_2 ^ pub_r001817_17_2) & 63;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((stage_v_45_1 & 2) != 0)
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
    if ((stage_v_45_2 & 2) != 0)
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
  int stage_v_116_1 = (stage_v_50_1 ^ pub_r001817_3_1) & 63;
  int stage_v_116_2 = (stage_v_50_2 ^ pub_r001817_3_2) & 63;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((stage_v_32_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_116_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((stage_v_32_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_116_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  }
  int stage_v_117_1 = (stage_v_94_1 ^ pub_r001817_12_1) & 63;
  int stage_v_117_2 = (stage_v_94_2 ^ pub_r001817_12_2) & 63;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((stage_v_26_1 & 2) != 0)
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
    if ((stage_v_26_2 & 2) != 0)
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
  int stage_v_118_1 = (stage_v_109_1 ^ pub_r001817_4_1) & 63;
  int stage_v_118_2 = (stage_v_109_2 ^ pub_r001817_4_2) & 63;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((stage_v_47_1 & 2) != 0)
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
    if ((stage_v_47_2 & 2) != 0)
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
  int stage_v_119_1 = (stage_v_60_1 ^ pub_r001817_15_1) & 63;
  int stage_v_119_2 = (stage_v_60_2 ^ pub_r001817_15_2) & 63;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((stage_v_26_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((stage_v_26_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  }
  int stage_v_120_1 = (stage_v_104_1 ^ pub_r001817_5_1) & 63;
  int stage_v_120_2 = (stage_v_104_2 ^ pub_r001817_5_2) & 63;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((stage_v_66_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((stage_v_66_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  }
  int stage_v_121_1 = (stage_v_63_1 ^ pub_r001817_8_1) & 63;
  int stage_v_121_2 = (stage_v_63_2 ^ pub_r001817_8_2) & 63;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((sec_r001817_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_121_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((sec_r001817_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_121_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  }
  int stage_v_122_1 = (stage_v_47_1 ^ pub_r001817_3_1) & 63;
  int stage_v_122_2 = (stage_v_47_2 ^ pub_r001817_3_2) & 63;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((stage_v_24_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((stage_v_24_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  }
  int stage_v_123_1 = (stage_v_100_1 ^ pub_r001817_5_1) & 63;
  int stage_v_123_2 = (stage_v_100_2 ^ pub_r001817_5_2) & 63;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((stage_v_88_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((stage_v_88_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  }
  int stage_v_124_1 = (stage_v_42_1 ^ pub_r001817_17_1) & 63;
  int stage_v_124_2 = (stage_v_42_2 ^ pub_r001817_17_2) & 63;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
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
    if ((helper_flow_6_2 & 2) != 0)
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
  int stage_v_125_1 = (stage_v_88_1 ^ pub_r001817_5_1) & 63;
  int stage_v_125_2 = (stage_v_88_2 ^ pub_r001817_5_2) & 63;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((stage_v_37_1 & 2) != 0)
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
    if ((stage_v_37_2 & 2) != 0)
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
  int stage_v_126_1 = (stage_v_101_1 ^ pub_r001817_7_1) & 63;
  int stage_v_126_2 = (stage_v_101_2 ^ pub_r001817_7_2) & 63;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((sec_r001817_14_1 & 2) != 0)
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
    if ((sec_r001817_14_2 & 2) != 0)
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
  int stage_v_127_1 = (stage_v_104_1 ^ pub_r001817_18_1) & 63;
  int stage_v_127_2 = (stage_v_104_2 ^ pub_r001817_18_2) & 63;
  if ((stage_v_127_1 & 1) != 0)
  {
    if ((stage_v_98_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_127_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  }
  if ((stage_v_127_2 & 1) != 0)
  {
    if ((stage_v_98_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_127_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  }
  int stage_v_128_1 = (stage_v_127_1 ^ pub_r001817_13_1) & 63;
  int stage_v_128_2 = (stage_v_127_2 ^ pub_r001817_13_2) & 63;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((sec_r001817_15_1 & 2) != 0)
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
    if ((sec_r001817_15_2 & 2) != 0)
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
  int stage_v_129_1 = ((pub_r001817_19_1 * 2) + 36) & 63;
  int stage_v_129_2 = ((pub_r001817_19_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = (stage_v_20_1 ^ pub_r001817_7_1) & 63;
  int stage_v_130_2 = (stage_v_20_2 ^ pub_r001817_7_2) & 63;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((stage_v_91_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_130_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((stage_v_91_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_130_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  }
  int stage_v_131_1 = (stage_v_37_1 ^ pub_r001817_15_1) & 63;
  int stage_v_131_2 = (stage_v_37_2 ^ pub_r001817_15_2) & 63;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((sec_r001817_5_1 & 2) != 0)
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
    if ((sec_r001817_5_2 & 2) != 0)
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
  int stage_v_132_1 = (stage_v_80_1 ^ pub_r001817_18_1) & 63;
  int stage_v_132_2 = (stage_v_80_2 ^ pub_r001817_18_2) & 63;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((stage_v_32_1 & 2) != 0)
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
    if ((stage_v_32_2 & 2) != 0)
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
  int stage_v_133_1 = ((pub_r001817_13_1 * 2) + 32) & 63;
  int stage_v_133_2 = ((pub_r001817_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = (sec_r001817_13_1 ^ pub_r001817_13_1) & 63;
  int stage_v_134_2 = (sec_r001817_13_2 ^ pub_r001817_13_2) & 63;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_134_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_134_1 * 2)) & 255;
  }
  if ((stage_v_134_2 & 1) != 0)
  {
    if ((helper_flow_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_134_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_134_2 * 2)) & 255;
  }
  int stage_v_135_1 = (sec_r001817_9_1 ^ pub_r001817_15_1) & 63;
  int stage_v_135_2 = (sec_r001817_9_2 ^ pub_r001817_15_2) & 63;
  if ((stage_v_135_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
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
    if ((stage_v_30_2 & 2) != 0)
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
  int stage_v_136_1 = (stage_v_118_1 ^ pub_r001817_15_1) & 63;
  int stage_v_136_2 = (stage_v_118_2 ^ pub_r001817_15_2) & 63;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((stage_v_115_1 & 2) != 0)
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
    if ((stage_v_115_2 & 2) != 0)
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
  int stage_v_137_1 = ((pub_r001817_17_1 * 2) + 10) & 63;
  int stage_v_137_2 = ((pub_r001817_17_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001817_3_1 * 2) + 48) & 63;
  int stage_v_138_2 = ((pub_r001817_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001817_20_1 * 2) + 30) & 63;
  int stage_v_139_2 = ((pub_r001817_20_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001817_6_1 * 2) + 17) & 63;
  int stage_v_140_2 = ((pub_r001817_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = (stage_v_51_1 ^ pub_r001817_15_1) & 63;
  int stage_v_141_2 = (stage_v_51_2 ^ pub_r001817_15_2) & 63;
  if ((stage_v_141_1 & 1) != 0)
  {
    if ((sec_r001817_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_141_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  }
  if ((stage_v_141_2 & 1) != 0)
  {
    if ((sec_r001817_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_141_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  }
  int stage_v_142_1 = ((pub_r001817_16_1 * 2) + 40) & 63;
  int stage_v_142_2 = ((pub_r001817_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = (stage_v_30_1 ^ pub_r001817_10_1) & 63;
  int stage_v_143_2 = (stage_v_30_2 ^ pub_r001817_10_2) & 63;
  if ((stage_v_143_1 & 1) != 0)
  {
    if ((stage_v_136_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_143_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  }
  if ((stage_v_143_2 & 1) != 0)
  {
    if ((stage_v_136_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_143_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  }
  int stage_v_144_1 = ((pub_r001817_17_1 * 2) + 36) & 63;
  int stage_v_144_2 = ((pub_r001817_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = (stage_v_78_1 ^ pub_r001817_6_1) & 63;
  int stage_v_145_2 = (stage_v_78_2 ^ pub_r001817_6_2) & 63;
  if ((stage_v_145_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  }
  if ((stage_v_145_2 & 1) != 0)
  {
    if ((stage_v_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  }
  int stage_v_146_1 = (stage_v_2_1 ^ pub_r001817_1_1) & 63;
  int stage_v_146_2 = (stage_v_2_2 ^ pub_r001817_1_2) & 63;
  if ((stage_v_146_1 & 1) != 0)
  {
    if ((stage_v_52_1 & 2) != 0)
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
    if ((stage_v_52_2 & 2) != 0)
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
  int stage_v_147_1 = (stage_v_66_1 ^ pub_r001817_20_1) & 63;
  int stage_v_147_2 = (stage_v_66_2 ^ pub_r001817_20_2) & 63;
  if ((stage_v_147_1 & 1) != 0)
  {
    if ((sec_r001817_6_1 & 2) != 0)
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
    if ((sec_r001817_6_2 & 2) != 0)
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
  int stage_v_148_1 = (stage_v_47_1 ^ pub_r001817_13_1) & 63;
  int stage_v_148_2 = (stage_v_47_2 ^ pub_r001817_13_2) & 63;
  if ((stage_v_148_1 & 1) != 0)
  {
    if ((sec_r001817_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_148_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  }
  if ((stage_v_148_2 & 1) != 0)
  {
    if ((sec_r001817_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_148_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  }
  int stage_v_149_1 = (stage_v_124_1 ^ pub_r001817_11_1) & 63;
  int stage_v_149_2 = (stage_v_124_2 ^ pub_r001817_11_2) & 63;
  if ((stage_v_149_1 & 1) != 0)
  {
    if ((stage_v_122_1 & 2) != 0)
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
    if ((stage_v_122_2 & 2) != 0)
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
  int stage_v_150_1 = ((pub_r001817_14_1 * 2) + 21) & 63;
  int stage_v_150_2 = ((pub_r001817_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = (stage_v_115_1 ^ pub_r001817_3_1) & 63;
  int stage_v_151_2 = (stage_v_115_2 ^ pub_r001817_3_2) & 63;
  if ((stage_v_151_1 & 1) != 0)
  {
    if ((stage_v_135_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_151_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  }
  if ((stage_v_151_2 & 1) != 0)
  {
    if ((stage_v_135_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_151_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  }
  int stage_v_152_1 = ((pub_r001817_12_1 * 2) + 32) & 63;
  int stage_v_152_2 = ((pub_r001817_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (helper_flow_2_1 ^ pub_r001817_8_1) & 63;
  int stage_v_153_2 = (helper_flow_2_2 ^ pub_r001817_8_2) & 63;
  if ((stage_v_153_1 & 1) != 0)
  {
    if ((stage_v_120_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_153_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  }
  if ((stage_v_153_2 & 1) != 0)
  {
    if ((stage_v_120_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_153_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  }
  int stage_v_154_1 = (stage_v_42_1 ^ pub_r001817_19_1) & 63;
  int stage_v_154_2 = (stage_v_42_2 ^ pub_r001817_19_2) & 63;
  if ((stage_v_154_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
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
    if ((stage_v_1_2 & 2) != 0)
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
  int stage_v_155_1 = (sec_r001817_9_1 ^ pub_r001817_11_1) & 63;
  int stage_v_155_2 = (sec_r001817_9_2 ^ pub_r001817_11_2) & 63;
  if ((stage_v_155_1 & 1) != 0)
  {
    if ((stage_v_90_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_155_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  }
  if ((stage_v_155_2 & 1) != 0)
  {
    if ((stage_v_90_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_155_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  }
  int stage_v_156_1 = (stage_v_25_1 ^ pub_r001817_20_1) & 63;
  int stage_v_156_2 = (stage_v_25_2 ^ pub_r001817_20_2) & 63;
  if ((stage_v_156_1 & 1) != 0)
  {
    if ((stage_v_47_1 & 2) != 0)
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
    if ((stage_v_47_2 & 2) != 0)
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
  int stage_v_157_1 = (stage_v_55_1 ^ pub_r001817_9_1) & 63;
  int stage_v_157_2 = (stage_v_55_2 ^ pub_r001817_9_2) & 63;
  if ((stage_v_157_1 & 1) != 0)
  {
    if ((stage_v_14_1 & 2) != 0)
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
    if ((stage_v_14_2 & 2) != 0)
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
  int stage_v_158_1 = ((pub_r001817_0_1 * 2) + 10) & 63;
  int stage_v_158_2 = ((pub_r001817_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (stage_v_70_1 ^ pub_r001817_9_1) & 63;
  int stage_v_159_2 = (stage_v_70_2 ^ pub_r001817_9_2) & 63;
  if ((stage_v_159_1 & 1) != 0)
  {
    if ((stage_v_105_1 & 2) != 0)
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
    if ((stage_v_105_2 & 2) != 0)
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
  int stage_v_160_1 = ((pub_r001817_9_1 * 2) + 18) & 63;
  int stage_v_160_2 = ((pub_r001817_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (sec_r001817_19_1 ^ pub_r001817_14_1) & 63;
  int stage_v_161_2 = (sec_r001817_19_2 ^ pub_r001817_14_2) & 63;
  if ((stage_v_161_1 & 1) != 0)
  {
    if ((stage_v_2_1 & 2) != 0)
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
    if ((stage_v_2_2 & 2) != 0)
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
  int stage_v_162_1 = (stage_v_91_1 ^ pub_r001817_5_1) & 63;
  int stage_v_162_2 = (stage_v_91_2 ^ pub_r001817_5_2) & 63;
  if ((stage_v_162_1 & 1) != 0)
  {
    if ((stage_v_32_1 & 2) != 0)
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
    if ((stage_v_32_2 & 2) != 0)
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
  int stage_v_163_1 = ((pub_r001817_15_1 * 2) + 50) & 63;
  int stage_v_163_2 = ((pub_r001817_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001817_16_1 * 2) + 46) & 63;
  int stage_v_164_2 = ((pub_r001817_16_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (stage_v_151_1 ^ pub_r001817_5_1) & 63;
  int stage_v_165_2 = (stage_v_151_2 ^ pub_r001817_5_2) & 63;
  if ((stage_v_165_1 & 1) != 0)
  {
    if ((stage_v_20_1 & 2) != 0)
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
    if ((stage_v_20_2 & 2) != 0)
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
  int stage_v_166_1 = (stage_v_106_1 ^ pub_r001817_1_1) & 63;
  int stage_v_166_2 = (stage_v_106_2 ^ pub_r001817_1_2) & 63;
  if ((stage_v_166_1 & 1) != 0)
  {
    if ((stage_v_60_1 & 2) != 0)
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
    if ((stage_v_60_2 & 2) != 0)
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
  int stage_v_167_1 = (sec_r001817_2_1 ^ pub_r001817_3_1) & 63;
  int stage_v_167_2 = (sec_r001817_2_2 ^ pub_r001817_3_2) & 63;
  if ((stage_v_167_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
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
    if ((stage_v_30_2 & 2) != 0)
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
  int stage_v_168_1 = ((pub_r001817_19_1 * 2) + 12) & 63;
  int stage_v_168_2 = ((pub_r001817_19_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (stage_v_51_1 ^ pub_r001817_8_1) & 63;
  int stage_v_169_2 = (stage_v_51_2 ^ pub_r001817_8_2) & 63;
  if ((stage_v_169_1 & 1) != 0)
  {
    if ((stage_v_2_1 & 2) != 0)
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
    if ((stage_v_2_2 & 2) != 0)
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
  int stage_v_170_1 = (stage_v_42_1 ^ pub_r001817_3_1) & 63;
  int stage_v_170_2 = (stage_v_42_2 ^ pub_r001817_3_2) & 63;
  if ((stage_v_170_1 & 1) != 0)
  {
    if ((stage_v_153_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_170_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  }
  if ((stage_v_170_2 & 1) != 0)
  {
    if ((stage_v_153_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_170_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  }
  int stage_v_171_1 = (stage_v_37_1 ^ pub_r001817_17_1) & 63;
  int stage_v_171_2 = (stage_v_37_2 ^ pub_r001817_17_2) & 63;
  if ((stage_v_171_1 & 1) != 0)
  {
    if ((sec_r001817_13_1 & 2) != 0)
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
    if ((sec_r001817_13_2 & 2) != 0)
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
  int stage_v_172_1 = ((pub_r001817_9_1 * 2) + 42) & 63;
  int stage_v_172_2 = ((pub_r001817_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (stage_v_28_1 ^ pub_r001817_5_1) & 63;
  int stage_v_173_2 = (stage_v_28_2 ^ pub_r001817_5_2) & 63;
  if ((stage_v_173_1 & 1) != 0)
  {
    if ((stage_v_148_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_173_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  }
  if ((stage_v_173_2 & 1) != 0)
  {
    if ((stage_v_148_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_173_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  }
  int stage_v_174_1 = (stage_v_104_1 ^ pub_r001817_19_1) & 63;
  int stage_v_174_2 = (stage_v_104_2 ^ pub_r001817_19_2) & 63;
  if ((stage_v_174_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_174_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_174_1 * 2)) & 255;
  }
  if ((stage_v_174_2 & 1) != 0)
  {
    if ((stage_v_30_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_174_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_174_2 * 2)) & 255;
  }
  int stage_v_175_1 = (stage_v_32_1 ^ pub_r001817_3_1) & 63;
  int stage_v_175_2 = (stage_v_32_2 ^ pub_r001817_3_2) & 63;
  if ((stage_v_175_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_175_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_175_1 * 2)) & 255;
  }
  if ((stage_v_175_2 & 1) != 0)
  {
    if ((helper_flow_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_175_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_175_2 * 2)) & 255;
  }
  int stage_v_176_1 = (stage_v_109_1 ^ pub_r001817_18_1) & 63;
  int stage_v_176_2 = (stage_v_109_2 ^ pub_r001817_18_2) & 63;
  if ((stage_v_176_1 & 1) != 0)
  {
    if ((stage_v_124_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_176_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_176_1 * 2)) & 255;
  }
  if ((stage_v_176_2 & 1) != 0)
  {
    if ((stage_v_124_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_176_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_176_2 * 2)) & 255;
  }
  int stage_v_177_1 = (sec_r001817_8_1 ^ pub_r001817_14_1) & 63;
  int stage_v_177_2 = (sec_r001817_8_2 ^ pub_r001817_14_2) & 63;
  if ((stage_v_177_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_177_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_177_1 * 2)) & 255;
  }
  if ((stage_v_177_2 & 1) != 0)
  {
    if ((stage_v_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_177_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_177_2 * 2)) & 255;
  }
  int stage_v_178_1 = (stage_v_141_1 ^ pub_r001817_18_1) & 63;
  int stage_v_178_2 = (stage_v_141_2 ^ pub_r001817_18_2) & 63;
  if ((stage_v_178_1 & 1) != 0)
  {
    if ((stage_v_13_1 & 2) != 0)
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
    if ((stage_v_13_2 & 2) != 0)
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
  int stage_v_179_1 = ((pub_r001817_15_1 * 2) + 14) & 63;
  int stage_v_179_2 = ((pub_r001817_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (stage_v_47_1 ^ pub_r001817_8_1) & 63;
  int stage_v_180_2 = (stage_v_47_2 ^ pub_r001817_8_2) & 63;
  if ((stage_v_180_1 & 1) != 0)
  {
    if ((sec_r001817_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_180_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_180_1 * 2)) & 255;
  }
  if ((stage_v_180_2 & 1) != 0)
  {
    if ((sec_r001817_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_180_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_180_2 * 2)) & 255;
  }
  int stage_v_181_1 = (stage_v_106_1 ^ pub_r001817_10_1) & 63;
  int stage_v_181_2 = (stage_v_106_2 ^ pub_r001817_10_2) & 63;
  if ((stage_v_181_1 & 1) != 0)
  {
    if ((stage_v_78_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_181_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_181_1 * 2)) & 255;
  }
  if ((stage_v_181_2 & 1) != 0)
  {
    if ((stage_v_78_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_181_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_181_2 * 2)) & 255;
  }
  int stage_v_182_1 = (helper_flow_5_1 ^ pub_r001817_3_1) & 63;
  int stage_v_182_2 = (helper_flow_5_2 ^ pub_r001817_3_2) & 63;
  if ((stage_v_182_1 & 1) != 0)
  {
    if ((stage_v_114_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_182_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_182_1 * 2)) & 255;
  }
  if ((stage_v_182_2 & 1) != 0)
  {
    if ((stage_v_114_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_182_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_182_2 * 2)) & 255;
  }
  int stage_v_183_1 = (stage_v_60_1 ^ pub_r001817_10_1) & 63;
  int stage_v_183_2 = (stage_v_60_2 ^ pub_r001817_10_2) & 63;
  if ((stage_v_183_1 & 1) != 0)
  {
    if ((stage_v_151_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_183_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  }
  if ((stage_v_183_2 & 1) != 0)
  {
    if ((stage_v_151_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_183_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  }
  int stage_v_184_1 = ((pub_r001817_11_1 * 2) + 39) & 63;
  int stage_v_184_2 = ((pub_r001817_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (stage_v_55_1 ^ pub_r001817_6_1) & 63;
  int stage_v_185_2 = (stage_v_55_2 ^ pub_r001817_6_2) & 63;
  if ((stage_v_185_1 & 1) != 0)
  {
    if ((sec_r001817_4_1 & 2) != 0)
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
    if ((sec_r001817_4_2 & 2) != 0)
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
  int stage_v_186_1 = ((pub_r001817_7_1 * 2) + 42) & 63;
  int stage_v_186_2 = ((pub_r001817_7_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001817_8_1 * 2) + 9) & 63;
  int stage_v_187_2 = ((pub_r001817_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001817_19_1 * 2) + 26) & 63;
  int stage_v_188_2 = ((pub_r001817_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001817_9_1 * 2) + 47) & 63;
  int stage_v_189_2 = ((pub_r001817_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001817_13_1 * 2) + 16) & 63;
  int stage_v_190_2 = ((pub_r001817_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (stage_v_122_1 ^ pub_r001817_11_1) & 63;
  int stage_v_191_2 = (stage_v_122_2 ^ pub_r001817_11_2) & 63;
  if ((stage_v_191_1 & 1) != 0)
  {
    if ((sec_r001817_10_1 & 2) != 0)
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
    if ((sec_r001817_10_2 & 2) != 0)
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
  int stage_v_192_1 = (stage_v_20_1 ^ pub_r001817_15_1) & 63;
  int stage_v_192_2 = (stage_v_20_2 ^ pub_r001817_15_2) & 63;
  if ((stage_v_192_1 & 1) != 0)
  {
    if ((stage_v_104_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_192_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_192_1 * 2)) & 255;
  }
  if ((stage_v_192_2 & 1) != 0)
  {
    if ((stage_v_104_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_192_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_192_2 * 2)) & 255;
  }
  int stage_v_193_1 = ((pub_r001817_2_1 * 2) + 24) & 63;
  int stage_v_193_2 = ((pub_r001817_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((pub_r001817_13_1 * 2) + 32) & 63;
  int stage_v_194_2 = ((pub_r001817_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = (stage_v_8_1 ^ pub_r001817_14_1) & 63;
  int stage_v_195_2 = (stage_v_8_2 ^ pub_r001817_14_2) & 63;
  if ((stage_v_195_1 & 1) != 0)
  {
    if ((sec_r001817_5_1 & 2) != 0)
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
    if ((sec_r001817_5_2 & 2) != 0)
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
  int stage_v_196_1 = ((pub_r001817_11_1 * 2) + 49) & 63;
  int stage_v_196_2 = ((pub_r001817_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001817_2_1 * 2) + 9) & 63;
  int stage_v_197_2 = ((pub_r001817_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (stage_v_167_1 ^ pub_r001817_12_1) & 63;
  int stage_v_198_2 = (stage_v_167_2 ^ pub_r001817_12_2) & 63;
  if ((stage_v_198_1 & 1) != 0)
  {
    if ((stage_v_109_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_198_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_198_1 * 2)) & 255;
  }
  if ((stage_v_198_2 & 1) != 0)
  {
    if ((stage_v_109_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_198_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_198_2 * 2)) & 255;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001817_5_1 != sec_r001817_5_2);
  __CPROVER_assume(sec_r001817_8_1 != sec_r001817_8_2);
  __CPROVER_assume(sec_r001817_13_1 != sec_r001817_13_2);
  __CPROVER_assume(sec_r001817_4_1 != sec_r001817_4_2);
  __CPROVER_assume(pub_r001817_0_1 == pub_r001817_0_2);
  __CPROVER_assume(sec_r001817_10_1 != sec_r001817_10_2);
  __CPROVER_assume(pub_r001817_18_1 == pub_r001817_18_2);
  __CPROVER_assume(pub_r001817_7_1 == pub_r001817_7_2);
  __CPROVER_assume(sec_r001817_11_1 != sec_r001817_11_2);
  __CPROVER_assume(sec_r001817_7_1 != sec_r001817_7_2);
  __CPROVER_assume(pub_r001817_5_1 == pub_r001817_5_2);
  __CPROVER_assume(pub_r001817_9_1 == pub_r001817_9_2);
  __CPROVER_assume(pub_r001817_8_1 == pub_r001817_8_2);
  __CPROVER_assume(pub_r001817_11_1 == pub_r001817_11_2);
  __CPROVER_assume(pub_r001817_16_1 == pub_r001817_16_2);
  __CPROVER_assume(pub_r001817_3_1 == pub_r001817_3_2);
  __CPROVER_assume(pub_r001817_13_1 == pub_r001817_13_2);
  __CPROVER_assume(sec_r001817_0_1 != sec_r001817_0_2);
  __CPROVER_assume(pub_r001817_17_1 == pub_r001817_17_2);
  __CPROVER_assume(sec_r001817_18_1 != sec_r001817_18_2);
  __CPROVER_assume(pub_r001817_12_1 == pub_r001817_12_2);
  __CPROVER_assume(sec_r001817_6_1 != sec_r001817_6_2);
  __CPROVER_assume(sec_r001817_15_1 != sec_r001817_15_2);
  __CPROVER_assume(sec_r001817_14_1 != sec_r001817_14_2);
  __CPROVER_assume(pub_r001817_20_1 == pub_r001817_20_2);
  __CPROVER_assume(pub_r001817_15_1 == pub_r001817_15_2);
  __CPROVER_assume(sec_r001817_17_1 != sec_r001817_17_2);
  __CPROVER_assume(sec_r001817_19_1 != sec_r001817_19_2);
  __CPROVER_assume(pub_r001817_1_1 == pub_r001817_1_2);
  __CPROVER_assume(sec_r001817_3_1 != sec_r001817_3_2);
  __CPROVER_assume(sec_r001817_1_1 != sec_r001817_1_2);
  __CPROVER_assume(pub_r001817_10_1 == pub_r001817_10_2);
  __CPROVER_assume(pub_r001817_2_1 == pub_r001817_2_2);
  __CPROVER_assume(sec_r001817_2_1 != sec_r001817_2_2);
  __CPROVER_assume(sec_r001817_9_1 != sec_r001817_9_2);
  __CPROVER_assume(pub_r001817_4_1 == pub_r001817_4_2);
  __CPROVER_assume(pub_r001817_6_1 == pub_r001817_6_2);
  __CPROVER_assume(pub_r001817_19_1 == pub_r001817_19_2);
  __CPROVER_assume(sec_r001817_12_1 != sec_r001817_12_2);
  __CPROVER_assume(sec_r001817_16_1 != sec_r001817_16_2);
  __CPROVER_assume(pub_r001817_14_1 == pub_r001817_14_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.mode == st_var_1_2.mode);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.tag == st_var_2_2.tag);
  assert(st_var_2_1.round_key == st_var_2_2.round_key);
  assert(st_var_2_1.nonce == st_var_2_2.nonce);
  assert(st_var_2_1.counter == st_var_2_2.counter);
  assert(st_var_2_1.iv == st_var_2_2.iv);
  assert(st_var_2_1.flags == st_var_2_2.flags);
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
}


