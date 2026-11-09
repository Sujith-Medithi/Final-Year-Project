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
struct EventLog_R001682_8213_0
{
  short code;
  int seq;
  int timestamp;
  unsigned char signature;
  unsigned char severity;
  int facility;
  int buffer[3];
};
struct CipherContext_R001682_8213_1
{
  int round_key;
  unsigned char flags;
  int tag;
  unsigned char iv;
  unsigned char counter;
  int nonce;
  int buffer[3];
};
union RegisterBank_R001682_8213_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001682_8213_1
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
void fn_R001682_8213_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st_1 = {0};
  struct CipherContext_R001682_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int phase_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_80_1 > 18)
  {
    acc_1 = ((acc_1 + (phase_80_1 * 2)) + 5) & 127;
    aux_1 ^= phase_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_80_2 > 18)
  {
    acc_2 = ((acc_2 + (phase_80_2 * 2)) + 5) & 127;
    aux_2 ^= phase_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_80_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_80_1 == phase_80_2);
}

int fn_R001682_8213_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int phase_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_80 > 18)
  {
    acc = ((acc + (phase_80 * 2)) + 5) & 127;
    aux ^= phase_80 & 15;
  }
  else
  {
    acc = ((acc - phase_80) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001682_8213_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001682_8213_0 st_1 = {0};
  struct EventLog_R001682_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int index_reg_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_90_1) & 63;
  aux_2 = (aux_2 + index_reg_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_63_1 = 0;
  int quotient_63_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_63_1 = ((quotient_63_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_63_2 = ((quotient_63_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_63_1) & 127;
    acc_2 = (acc_2 + quotient_63_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_98_1 = local_arr_1[aux_1 % 3];
  int checksum_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_98_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_90_1 == index_reg_90_2);
  assert(quotient_63_1 == quotient_63_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_98_1 == checksum_98_2);
}

int fn_R001682_8213_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001682_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int index_reg_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_90) & 63;
  acc ^= aux;
  int quotient_63 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_63 = ((quotient_63 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_63) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int checksum_98 = local_arr[aux % 3];
  acc = (acc + (checksum_98 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001682_8213_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001682_8213_0 st_1 = {0};
  struct EventLog_R001682_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int metric_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_26_1 > 23)
  {
    acc_1 = ((acc_1 + (metric_26_1 * 2)) + 5) & 127;
    aux_1 ^= metric_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_26_2 > 23)
  {
    acc_2 = ((acc_2 + (metric_26_2 * 2)) + 5) & 127;
    aux_2 ^= metric_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_84_1 = local_arr_1[aux_1 % 3];
  int sample_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_84_2 * 2)) & 127;
  int vector_24_1 = 0;
  int vector_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_24_1 = ((vector_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_24_2 = ((vector_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_24_1) & 127;
    acc_2 = (acc_2 + vector_24_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_26_1 == metric_26_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_84_1 == sample_84_2);
  assert(vector_24_1 == vector_24_2);
}

int fn_R001682_8213_2(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001682_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int metric_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_26 > 23)
  {
    acc = ((acc + (metric_26 * 2)) + 5) & 127;
    aux ^= metric_26 & 15;
  }
  else
  {
    acc = ((acc - metric_26) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int sample_84 = local_arr[aux % 3];
  acc = (acc + (sample_84 * 2)) & 127;
  int vector_24 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_24 = ((vector_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_24) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001682_8213_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st_1 = {0};
  struct CipherContext_R001682_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int window_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_27_1) & 63;
  aux_2 = (aux_2 + window_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_46_1 > 37)
  {
    acc_1 = ((acc_1 + (index_reg_46_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_46_2 > 37)
  {
    acc_2 = ((acc_2 + (index_reg_46_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_53_1 = 0;
  int tally_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_53_1 = ((tally_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_53_2 = ((tally_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_53_1) & 127;
    acc_2 = (acc_2 + tally_53_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_27_1 == window_27_2);
  assert(index_reg_46_1 == index_reg_46_2);
  assert(tally_53_1 == tally_53_2);
}

int fn_R001682_8213_3(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int window_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_27) & 63;
  acc ^= aux;
  int index_reg_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_46 > 37)
  {
    acc = ((acc + (index_reg_46 * 2)) + 5) & 127;
    aux ^= index_reg_46 & 15;
  }
  else
  {
    acc = ((acc - index_reg_46) + 11) & 127;
    aux += 3;
  }
  int tally_53 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_53 = ((tally_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_53) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001682_8213_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st_1 = {0};
  struct CipherContext_R001682_8213_1 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_18_1 = local_arr_1[aux_1 % 3];
  int parity_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_18_2 * 2)) & 127;
  int scale_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_29_1)
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

  switch (scale_29_2)
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
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_18_1 == parity_18_2);
  assert(scale_29_1 == scale_29_2);
}

int fn_R001682_8213_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_18 = local_arr[aux % 3];
  acc = (acc + (parity_18 * 2)) & 127;
  int scale_29 = (aux + st.buffer[1]) & 3;
  switch (scale_29)
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

void fn_R001682_8213_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st_1 = {0};
  struct CipherContext_R001682_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int factor_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_88_1 > 13)
  {
    acc_1 = ((acc_1 + (factor_88_1 * 2)) + 5) & 127;
    aux_1 ^= factor_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_88_2 > 13)
  {
    acc_2 = ((acc_2 + (factor_88_2 * 2)) + 5) & 127;
    aux_2 ^= factor_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_88_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_43_1 = local_arr_1[aux_1 % 3];
  int cursor_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_43_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_88_1 == factor_88_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_43_1 == cursor_43_2);
}

int fn_R001682_8213_5(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int factor_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_88 > 13)
  {
    acc = ((acc + (factor_88 * 2)) + 5) & 127;
    aux ^= factor_88 & 15;
  }
  else
  {
    acc = ((acc - factor_88) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_43 = local_arr[aux % 3];
  acc = (acc + (cursor_43 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001682_8213_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001682_8213_0 st_1 = {0};
  struct EventLog_R001682_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int quotient_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_67_1)
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

  switch (quotient_67_2)
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

  int phase_94_1 = 0;
  int phase_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_94_1 = ((phase_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_94_2 = ((phase_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_94_1) & 127;
    acc_2 = (acc_2 + phase_94_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_21_1) & 63;
  aux_2 = (aux_2 + offset_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_67_1 == quotient_67_2);
  assert(phase_94_1 == phase_94_2);
  assert(offset_21_1 == offset_21_2);
}

int fn_R001682_8213_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001682_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int quotient_67 = (aux + st.buffer[1]) & 3;
  switch (quotient_67)
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

  int phase_94 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_94 = ((phase_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_94) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_21) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001682_8213_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001682_8213_0 st_1 = {0};
  struct EventLog_R001682_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_54_1 = local_arr_1[aux_1 % 3];
  int offset_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_54_2 * 2)) & 127;
  int parity_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_19_1)
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

  switch (parity_19_2)
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

  int margin_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_80_1) & 63;
  aux_2 = (aux_2 + margin_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_54_1 == offset_54_2);
  assert(parity_19_1 == parity_19_2);
  assert(margin_80_1 == margin_80_2);
}

int fn_R001682_8213_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001682_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int offset_54 = local_arr[aux % 3];
  acc = (acc + (offset_54 * 2)) & 127;
  int parity_19 = (aux + st.buffer[1]) & 3;
  switch (parity_19)
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

  int margin_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_80) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001682_8213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st_1 = {0};
  struct CipherContext_R001682_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int stride_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_20_1) & 63;
  aux_2 = (aux_2 + stride_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_69_1)
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

  switch (residue_69_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_67_1 > 49)
  {
    acc_1 = ((acc_1 + (tracker_67_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_67_2 > 49)
  {
    acc_2 = ((acc_2 + (tracker_67_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_67_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_20_1 == stride_20_2);
  assert(residue_69_1 == residue_69_2);
  assert(tracker_67_1 == tracker_67_2);
}

int fn_R001682_8213_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int stride_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_20) & 63;
  acc ^= aux;
  int residue_69 = (aux + st.buffer[1]) & 3;
  switch (residue_69)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_67 > 49)
  {
    acc = ((acc + (tracker_67 * 2)) + 5) & 127;
    aux ^= tracker_67 & 15;
  }
  else
  {
    acc = ((acc - tracker_67) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001682_8213_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001682_8213_0 st_1 = {0};
  struct EventLog_R001682_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_16_1 = local_arr_1[aux_1 % 3];
  int threshold_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_16_2 * 2)) & 127;
  int delta_90_1 = 0;
  int delta_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_90_1 = ((delta_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_90_2 = ((delta_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_90_1) & 127;
    acc_2 = (acc_2 + delta_90_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_16_1 == threshold_16_2);
  assert(delta_90_1 == delta_90_2);
}

int fn_R001682_8213_9(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001682_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int threshold_16 = local_arr[aux % 3];
  acc = (acc + (threshold_16 * 2)) & 127;
  int delta_90 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_90 = ((delta_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_90) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001682_8213_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st_1 = {0};
  struct CipherContext_R001682_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int pivot_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_77_1 > 47)
  {
    acc_1 = ((acc_1 + (pivot_77_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_77_2 > 47)
  {
    acc_2 = ((acc_2 + (pivot_77_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_77_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_77_1 == pivot_77_2);
}

int fn_R001682_8213_10(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int pivot_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_77 > 47)
  {
    acc = ((acc + (pivot_77 * 2)) + 5) & 127;
    aux ^= pivot_77 & 15;
  }
  else
  {
    acc = ((acc - pivot_77) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001682_8213_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st_1 = {0};
  struct CipherContext_R001682_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int quantum_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_31_1) & 63;
  aux_2 = (aux_2 + quantum_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_22_1 > 22)
  {
    acc_1 = ((acc_1 + (coefficient_22_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_22_2 > 22)
  {
    acc_2 = ((acc_2 + (coefficient_22_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_22_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_31_1 == quantum_31_2);
  assert(coefficient_22_1 == coefficient_22_2);
}

int fn_R001682_8213_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int quantum_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_31) & 63;
  acc ^= aux;
  int coefficient_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_22 > 22)
  {
    acc = ((acc + (coefficient_22 * 2)) + 5) & 127;
    aux ^= coefficient_22 & 15;
  }
  else
  {
    acc = ((acc - coefficient_22) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001682_8213_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st_1 = {0};
  struct CipherContext_R001682_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int scale_55_1 = 0;
  int scale_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_55_1 = ((scale_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_55_2 = ((scale_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_55_1) & 127;
    acc_2 = (acc_2 + scale_55_2) & 127;
  }

  int threshold_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_29_1) & 63;
  aux_2 = (aux_2 + threshold_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_39_1)
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

  switch (factor_39_2)
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

  int tracker_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_33_1 > 20)
  {
    acc_1 = ((acc_1 + (tracker_33_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_33_2 > 20)
  {
    acc_2 = ((acc_2 + (tracker_33_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_33_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_55_1 == scale_55_2);
  assert(threshold_29_1 == threshold_29_2);
  assert(factor_39_1 == factor_39_2);
  assert(tracker_33_1 == tracker_33_2);
}

int fn_R001682_8213_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int scale_55 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_55 = ((scale_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_55) & 127;
  }

  int threshold_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_29) & 63;
  acc ^= aux;
  int factor_39 = (aux + st.buffer[1]) & 3;
  switch (factor_39)
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

  int tracker_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_33 > 20)
  {
    acc = ((acc + (tracker_33 * 2)) + 5) & 127;
    aux ^= tracker_33 & 15;
  }
  else
  {
    acc = ((acc - tracker_33) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001682_8213_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001682_8213_0 st_1 = {0};
  struct EventLog_R001682_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int delta_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_36_1)
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

  switch (delta_36_2)
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

  int weight_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_58_1) & 63;
  aux_2 = (aux_2 + weight_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_25_1 = local_arr_1[aux_1 % 3];
  int stride_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_25_2 * 2)) & 127;
  int pivot_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_71_1 > 20)
  {
    acc_1 = ((acc_1 + (pivot_71_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_71_2 > 20)
  {
    acc_2 = ((acc_2 + (pivot_71_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_71_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_36_1 == delta_36_2);
  assert(weight_58_1 == weight_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_25_1 == stride_25_2);
  assert(pivot_71_1 == pivot_71_2);
}

int fn_R001682_8213_13(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001682_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int delta_36 = (aux + st.buffer[1]) & 3;
  switch (delta_36)
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

  int weight_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_58) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_25 = local_arr[aux % 3];
  acc = (acc + (stride_25 * 2)) & 127;
  int pivot_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_71 > 20)
  {
    acc = ((acc + (pivot_71 * 2)) + 5) & 127;
    aux ^= pivot_71 & 15;
  }
  else
  {
    acc = ((acc - pivot_71) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001682_8213_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st_1 = {0};
  struct CipherContext_R001682_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int coefficient_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_91_1)
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

  switch (coefficient_91_2)
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

  int quotient_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_25_1) & 63;
  aux_2 = (aux_2 + quotient_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_80_1 = 0;
  int tally_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_80_1 = ((tally_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_80_2 = ((tally_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_80_1) & 127;
    acc_2 = (acc_2 + tally_80_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_91_1 == coefficient_91_2);
  assert(quotient_25_1 == quotient_25_2);
  assert(tally_80_1 == tally_80_2);
}

int fn_R001682_8213_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int coefficient_91 = (aux + st.buffer[1]) & 3;
  switch (coefficient_91)
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

  int quotient_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_25) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_80 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_80 = ((tally_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_80) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001682_8213_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st_1 = {0};
  struct CipherContext_R001682_8213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_24_1) & 63;
  aux_2 = (aux_2 + margin_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_18_1 = 0;
  int damping_18_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_18_1 = ((damping_18_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_18_2 = ((damping_18_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_18_1) & 127;
    acc_2 = (acc_2 + damping_18_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_24_1 == margin_24_2);
  assert(damping_18_1 == damping_18_2);
}

int fn_R001682_8213_15(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001682_8213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_24) & 63;
  acc ^= aux;
  int damping_18 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_18 = ((damping_18 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_18) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001682_8213_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001682_8213_0 st_1 = {0};
  struct EventLog_R001682_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int damping_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_10_1)
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

  switch (damping_10_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_10_1 == damping_10_2);
}

int fn_R001682_8213_16(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001682_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int damping_10 = (aux + st.buffer[1]) & 3;
  switch (damping_10)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001682_8213_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001682_8213_0 st_1 = {0};
  struct EventLog_R001682_8213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_19_1) & 63;
  aux_2 = (aux_2 + cursor_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_52_1 = 0;
  int tracker_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_52_1 = ((tracker_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_52_2 = ((tracker_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_52_1) & 127;
    acc_2 = (acc_2 + tracker_52_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_19_1 == cursor_19_2);
  assert(tracker_52_1 == tracker_52_2);
}

int fn_R001682_8213_17(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001682_8213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_19) & 63;
  acc ^= aux;
  int tracker_52 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_52 = ((tracker_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_52) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001682_0_1;
  int sec_r001682_0_2;
  int sec_r001682_1_1;
  int sec_r001682_1_2;
  int sec_r001682_2_1;
  int sec_r001682_2_2;
  int sec_r001682_3_1;
  int sec_r001682_3_2;
  int sec_r001682_4_1;
  int sec_r001682_4_2;
  int sec_r001682_5_1;
  int sec_r001682_5_2;
  int sec_r001682_6_1;
  int sec_r001682_6_2;
  int sec_r001682_7_1;
  int sec_r001682_7_2;
  int sec_r001682_8_1;
  int sec_r001682_8_2;
  int sec_r001682_9_1;
  int sec_r001682_9_2;
  int sec_r001682_10_1;
  int sec_r001682_10_2;
  int sec_r001682_11_1;
  int sec_r001682_11_2;
  int sec_r001682_12_1;
  int sec_r001682_12_2;
  int sec_r001682_13_1;
  int sec_r001682_13_2;
  int sec_r001682_14_1;
  int sec_r001682_14_2;
  int sec_r001682_15_1;
  int sec_r001682_15_2;
  int sec_r001682_16_1;
  int sec_r001682_16_2;
  int sec_r001682_17_1;
  int sec_r001682_17_2;
  int pub_r001682_0_1;
  int pub_r001682_0_2;
  int pub_r001682_1_1;
  int pub_r001682_1_2;
  int pub_r001682_2_1;
  int pub_r001682_2_2;
  int pub_r001682_3_1;
  int pub_r001682_3_2;
  int pub_r001682_4_1;
  int pub_r001682_4_2;
  int pub_r001682_5_1;
  int pub_r001682_5_2;
  int pub_r001682_6_1;
  int pub_r001682_6_2;
  int pub_r001682_7_1;
  int pub_r001682_7_2;
  int pub_r001682_8_1;
  int pub_r001682_8_2;
  int pub_r001682_9_1;
  int pub_r001682_9_2;
  int pub_r001682_10_1;
  int pub_r001682_10_2;
  int pub_r001682_11_1;
  int pub_r001682_11_2;
  int pub_r001682_12_1;
  int pub_r001682_12_2;
  int pub_r001682_13_1;
  int pub_r001682_13_2;
  int pub_r001682_14_1;
  int pub_r001682_14_2;
  int pub_r001682_15_1;
  int pub_r001682_15_2;
  int pub_r001682_16_1;
  int pub_r001682_16_2;
  int pub_r001682_17_1;
  int pub_r001682_17_2;
  int pub_r001682_18_1;
  int pub_r001682_18_2;
  int pub_r001682_19_1;
  int pub_r001682_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001682_0_1 >= (-100)) && (pub_r001682_0_1 <= 100));
  __CPROVER_assume((pub_r001682_0_2 >= (-100)) && (pub_r001682_0_2 <= 100));
  __CPROVER_assume((pub_r001682_1_1 >= (-100)) && (pub_r001682_1_1 <= 100));
  __CPROVER_assume((pub_r001682_1_2 >= (-100)) && (pub_r001682_1_2 <= 100));
  __CPROVER_assume((pub_r001682_2_1 >= (-100)) && (pub_r001682_2_1 <= 100));
  __CPROVER_assume((pub_r001682_2_2 >= (-100)) && (pub_r001682_2_2 <= 100));
  __CPROVER_assume((pub_r001682_3_1 >= (-100)) && (pub_r001682_3_1 <= 100));
  __CPROVER_assume((pub_r001682_3_2 >= (-100)) && (pub_r001682_3_2 <= 100));
  __CPROVER_assume((pub_r001682_4_1 >= (-100)) && (pub_r001682_4_1 <= 100));
  __CPROVER_assume((pub_r001682_4_2 >= (-100)) && (pub_r001682_4_2 <= 100));
  __CPROVER_assume((pub_r001682_5_1 >= (-100)) && (pub_r001682_5_1 <= 100));
  __CPROVER_assume((pub_r001682_5_2 >= (-100)) && (pub_r001682_5_2 <= 100));
  __CPROVER_assume((pub_r001682_6_1 >= (-100)) && (pub_r001682_6_1 <= 100));
  __CPROVER_assume((pub_r001682_6_2 >= (-100)) && (pub_r001682_6_2 <= 100));
  __CPROVER_assume((pub_r001682_7_1 >= (-100)) && (pub_r001682_7_1 <= 100));
  __CPROVER_assume((pub_r001682_7_2 >= (-100)) && (pub_r001682_7_2 <= 100));
  __CPROVER_assume((pub_r001682_8_1 >= (-100)) && (pub_r001682_8_1 <= 100));
  __CPROVER_assume((pub_r001682_8_2 >= (-100)) && (pub_r001682_8_2 <= 100));
  __CPROVER_assume((pub_r001682_9_1 >= (-100)) && (pub_r001682_9_1 <= 100));
  __CPROVER_assume((pub_r001682_9_2 >= (-100)) && (pub_r001682_9_2 <= 100));
  __CPROVER_assume((pub_r001682_10_1 >= (-100)) && (pub_r001682_10_1 <= 100));
  __CPROVER_assume((pub_r001682_10_2 >= (-100)) && (pub_r001682_10_2 <= 100));
  __CPROVER_assume((pub_r001682_11_1 >= (-100)) && (pub_r001682_11_1 <= 100));
  __CPROVER_assume((pub_r001682_11_2 >= (-100)) && (pub_r001682_11_2 <= 100));
  __CPROVER_assume((pub_r001682_12_1 >= (-100)) && (pub_r001682_12_1 <= 100));
  __CPROVER_assume((pub_r001682_12_2 >= (-100)) && (pub_r001682_12_2 <= 100));
  __CPROVER_assume((pub_r001682_13_1 >= (-100)) && (pub_r001682_13_1 <= 100));
  __CPROVER_assume((pub_r001682_13_2 >= (-100)) && (pub_r001682_13_2 <= 100));
  __CPROVER_assume((pub_r001682_14_1 >= (-100)) && (pub_r001682_14_1 <= 100));
  __CPROVER_assume((pub_r001682_14_2 >= (-100)) && (pub_r001682_14_2 <= 100));
  __CPROVER_assume((pub_r001682_15_1 >= (-100)) && (pub_r001682_15_1 <= 100));
  __CPROVER_assume((pub_r001682_15_2 >= (-100)) && (pub_r001682_15_2 <= 100));
  __CPROVER_assume((pub_r001682_16_1 >= (-100)) && (pub_r001682_16_1 <= 100));
  __CPROVER_assume((pub_r001682_16_2 >= (-100)) && (pub_r001682_16_2 <= 100));
  __CPROVER_assume((pub_r001682_17_1 >= (-100)) && (pub_r001682_17_1 <= 100));
  __CPROVER_assume((pub_r001682_17_2 >= (-100)) && (pub_r001682_17_2 <= 100));
  __CPROVER_assume((pub_r001682_18_1 >= (-100)) && (pub_r001682_18_1 <= 100));
  __CPROVER_assume((pub_r001682_18_2 >= (-100)) && (pub_r001682_18_2 <= 100));
  __CPROVER_assume((pub_r001682_19_1 >= (-100)) && (pub_r001682_19_1 <= 100));
  __CPROVER_assume((pub_r001682_19_2 >= (-100)) && (pub_r001682_19_2 <= 100));
  __CPROVER_assume((sec_r001682_0_1 >= 0) && (sec_r001682_0_1 <= 255));
  __CPROVER_assume((sec_r001682_0_2 >= 0) && (sec_r001682_0_2 <= 255));
  __CPROVER_assume((sec_r001682_1_1 >= 0) && (sec_r001682_1_1 <= 255));
  __CPROVER_assume((sec_r001682_1_2 >= 0) && (sec_r001682_1_2 <= 255));
  __CPROVER_assume((sec_r001682_2_1 >= 0) && (sec_r001682_2_1 <= 255));
  __CPROVER_assume((sec_r001682_2_2 >= 0) && (sec_r001682_2_2 <= 255));
  __CPROVER_assume((sec_r001682_3_1 >= 0) && (sec_r001682_3_1 <= 255));
  __CPROVER_assume((sec_r001682_3_2 >= 0) && (sec_r001682_3_2 <= 255));
  __CPROVER_assume((sec_r001682_4_1 >= 0) && (sec_r001682_4_1 <= 255));
  __CPROVER_assume((sec_r001682_4_2 >= 0) && (sec_r001682_4_2 <= 255));
  __CPROVER_assume((sec_r001682_5_1 >= 0) && (sec_r001682_5_1 <= 255));
  __CPROVER_assume((sec_r001682_5_2 >= 0) && (sec_r001682_5_2 <= 255));
  __CPROVER_assume((sec_r001682_6_1 >= 0) && (sec_r001682_6_1 <= 255));
  __CPROVER_assume((sec_r001682_6_2 >= 0) && (sec_r001682_6_2 <= 255));
  __CPROVER_assume((sec_r001682_7_1 >= 0) && (sec_r001682_7_1 <= 255));
  __CPROVER_assume((sec_r001682_7_2 >= 0) && (sec_r001682_7_2 <= 255));
  __CPROVER_assume((sec_r001682_8_1 >= 0) && (sec_r001682_8_1 <= 255));
  __CPROVER_assume((sec_r001682_8_2 >= 0) && (sec_r001682_8_2 <= 255));
  __CPROVER_assume((sec_r001682_9_1 >= 0) && (sec_r001682_9_1 <= 255));
  __CPROVER_assume((sec_r001682_9_2 >= 0) && (sec_r001682_9_2 <= 255));
  __CPROVER_assume((sec_r001682_10_1 >= 0) && (sec_r001682_10_1 <= 255));
  __CPROVER_assume((sec_r001682_10_2 >= 0) && (sec_r001682_10_2 <= 255));
  __CPROVER_assume((sec_r001682_11_1 >= 0) && (sec_r001682_11_1 <= 255));
  __CPROVER_assume((sec_r001682_11_2 >= 0) && (sec_r001682_11_2 <= 255));
  __CPROVER_assume((sec_r001682_12_1 >= 0) && (sec_r001682_12_1 <= 255));
  __CPROVER_assume((sec_r001682_12_2 >= 0) && (sec_r001682_12_2 <= 255));
  __CPROVER_assume((sec_r001682_13_1 >= 0) && (sec_r001682_13_1 <= 255));
  __CPROVER_assume((sec_r001682_13_2 >= 0) && (sec_r001682_13_2 <= 255));
  __CPROVER_assume((sec_r001682_14_1 >= 0) && (sec_r001682_14_1 <= 255));
  __CPROVER_assume((sec_r001682_14_2 >= 0) && (sec_r001682_14_2 <= 255));
  __CPROVER_assume((sec_r001682_15_1 >= 0) && (sec_r001682_15_1 <= 255));
  __CPROVER_assume((sec_r001682_15_2 >= 0) && (sec_r001682_15_2 <= 255));
  __CPROVER_assume((sec_r001682_16_1 >= 0) && (sec_r001682_16_1 <= 255));
  __CPROVER_assume((sec_r001682_16_2 >= 0) && (sec_r001682_16_2 <= 255));
  __CPROVER_assume((sec_r001682_17_1 >= 0) && (sec_r001682_17_1 <= 255));
  __CPROVER_assume((sec_r001682_17_2 >= 0) && (sec_r001682_17_2 <= 255));
  struct EventLog_R001682_8213_0 st_var_0_1 = {0};
  struct EventLog_R001682_8213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001682_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001682_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001682_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001682_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001682_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001682_0_2 + 7) & 15;
  struct CipherContext_R001682_8213_1 st_var_1_1 = {0};
  struct CipherContext_R001682_8213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001682_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001682_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001682_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001682_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001682_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001682_0_2 + 9) & 15;
  union RegisterBank_R001682_8213_0 u_var_1;
  union RegisterBank_R001682_8213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001682_8213_0(sec_r001682_0_1, sec_r001682_1_1, pub_r001682_2_1, pub_r001682_3_1, pub_r001682_4_1);
  int helper_flow_0_2 = fn_R001682_8213_0(sec_r001682_0_2, sec_r001682_1_2, pub_r001682_2_2, pub_r001682_3_2, pub_r001682_4_2);
  fn_R001682_8213_0_2(sec_r001682_0_1, sec_r001682_1_1, pub_r001682_2_1, pub_r001682_3_1, pub_r001682_4_1, sec_r001682_0_2, sec_r001682_1_2, pub_r001682_2_2, pub_r001682_3_2, pub_r001682_4_2);
  int helper_flow_1_1 = fn_R001682_8213_1(sec_r001682_1_1, pub_r001682_2_1, pub_r001682_3_1, pub_r001682_4_1, pub_r001682_5_1);
  int helper_flow_1_2 = fn_R001682_8213_1(sec_r001682_1_2, pub_r001682_2_2, pub_r001682_3_2, pub_r001682_4_2, pub_r001682_5_2);
  fn_R001682_8213_1_2(sec_r001682_1_1, pub_r001682_2_1, pub_r001682_3_1, pub_r001682_4_1, pub_r001682_5_1, sec_r001682_1_2, pub_r001682_2_2, pub_r001682_3_2, pub_r001682_4_2, pub_r001682_5_2);
  int helper_flow_2_1 = fn_R001682_8213_2(sec_r001682_2_1, sec_r001682_3_1, pub_r001682_4_1);
  int helper_flow_2_2 = fn_R001682_8213_2(sec_r001682_2_2, sec_r001682_3_2, pub_r001682_4_2);
  fn_R001682_8213_2_2(sec_r001682_2_1, sec_r001682_3_1, pub_r001682_4_1, sec_r001682_2_2, sec_r001682_3_2, pub_r001682_4_2);
  int stage_v_0_1 = (((sec_r001682_5_1 * 3) + pub_r001682_0_1) + 21) & 127;
  int stage_v_0_2 = (((sec_r001682_5_2 * 3) + pub_r001682_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = (((sec_r001682_7_1 * 3) + pub_r001682_16_1) + 27) & 127;
  int stage_v_1_2 = (((sec_r001682_7_2 * 3) + pub_r001682_16_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = ((pub_r001682_4_1 * 2) + 21) & 63;
  int stage_v_2_2 = ((pub_r001682_4_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001682_0_1 * 2) + 23) & 63;
  int stage_v_3_2 = ((pub_r001682_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001682_17_1 * 2) + 9) & 63;
  int stage_v_4_2 = ((pub_r001682_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001682_9_1 * 2) + 23) & 63;
  int stage_v_5_2 = ((pub_r001682_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001682_12_1 * 2) + 11) & 63;
  int stage_v_6_2 = ((pub_r001682_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((sec_r001682_3_1 * 3) + pub_r001682_4_1) + 42) & 127;
  int stage_v_7_2 = (((sec_r001682_3_2 * 3) + pub_r001682_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001682_3_1 * 2) + 48) & 63;
  int stage_v_8_2 = ((pub_r001682_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001682_2_1 * 2) + 32) & 63;
  int stage_v_9_2 = ((pub_r001682_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001682_3_1 * 2) + 47) & 63;
  int stage_v_10_2 = ((pub_r001682_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (((sec_r001682_2_1 * 3) + pub_r001682_9_1) + 24) & 127;
  int stage_v_11_2 = (((sec_r001682_2_2 * 3) + pub_r001682_9_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = ((pub_r001682_12_1 * 2) + 23) & 63;
  int stage_v_12_2 = ((pub_r001682_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001682_12_1 * 2) + 28) & 63;
  int stage_v_13_2 = ((pub_r001682_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001682_5_1 * 2) + 36) & 63;
  int stage_v_14_2 = ((pub_r001682_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (((sec_r001682_6_1 * 3) + pub_r001682_0_1) + 15) & 127;
  int stage_v_15_2 = (((sec_r001682_6_2 * 3) + pub_r001682_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = ((pub_r001682_16_1 * 2) + 41) & 63;
  int stage_v_16_2 = ((pub_r001682_16_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001682_19_1 * 2) + 38) & 63;
  int stage_v_17_2 = ((pub_r001682_19_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = (((stage_v_7_1 * 3) + pub_r001682_6_1) + 39) & 127;
  int stage_v_18_2 = (((stage_v_7_2 * 3) + pub_r001682_6_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = ((pub_r001682_0_1 * 2) + 26) & 63;
  int stage_v_19_2 = ((pub_r001682_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001682_6_1 * 2) + 30) & 63;
  int stage_v_20_2 = ((pub_r001682_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001682_4_1 * 2) + 5) & 63;
  int stage_v_21_2 = ((pub_r001682_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001682_5_1 * 2) + 35) & 63;
  int stage_v_22_2 = ((pub_r001682_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((sec_r001682_1_1 * 3) + pub_r001682_18_1) + 43) & 127;
  int stage_v_23_2 = (((sec_r001682_1_2 * 3) + pub_r001682_18_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((stage_v_11_1 * 3) + pub_r001682_15_1) + 16) & 127;
  int stage_v_24_2 = (((stage_v_11_2 * 3) + pub_r001682_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = ((pub_r001682_12_1 * 2) + 9) & 63;
  int stage_v_25_2 = ((pub_r001682_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001682_12_1 * 2) + 34) & 63;
  int stage_v_26_2 = ((pub_r001682_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001682_6_1 * 2) + 27) & 63;
  int stage_v_27_2 = ((pub_r001682_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001682_17_1 * 2) + 50) & 63;
  int stage_v_28_2 = ((pub_r001682_17_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001682_5_1 * 2) + 14) & 63;
  int stage_v_29_2 = ((pub_r001682_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001682_12_1 * 2) + 29) & 63;
  int stage_v_30_2 = ((pub_r001682_12_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001682_13_1 * 2) + 46) & 63;
  int stage_v_31_2 = ((pub_r001682_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001682_3_1 * 2) + 21) & 63;
  int stage_v_32_2 = ((pub_r001682_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001682_15_1 * 2) + 33) & 63;
  int stage_v_33_2 = ((pub_r001682_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001682_8_1 * 2) + 26) & 63;
  int stage_v_34_2 = ((pub_r001682_8_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001682_12_1 * 2) + 6) & 63;
  int stage_v_35_2 = ((pub_r001682_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001682_8_1 * 2) + 39) & 63;
  int stage_v_36_2 = ((pub_r001682_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001682_8_1 * 2) + 44) & 63;
  int stage_v_37_2 = ((pub_r001682_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001682_1_1 * 2) + 5) & 63;
  int stage_v_38_2 = ((pub_r001682_1_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001682_17_1 * 2) + 29) & 63;
  int stage_v_39_2 = ((pub_r001682_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((stage_v_1_1 * 3) + pub_r001682_1_1) + 6) & 127;
  int stage_v_40_2 = (((stage_v_1_2 * 3) + pub_r001682_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = ((pub_r001682_0_1 * 2) + 19) & 63;
  int stage_v_41_2 = ((pub_r001682_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001682_11_1 * 2) + 22) & 63;
  int stage_v_42_2 = ((pub_r001682_11_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001682_11_1 * 2) + 13) & 63;
  int stage_v_43_2 = ((pub_r001682_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001682_5_1 * 2) + 20) & 63;
  int stage_v_44_2 = ((pub_r001682_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = (((sec_r001682_9_1 * 3) + pub_r001682_13_1) + 5) & 127;
  int stage_v_45_2 = (((sec_r001682_9_2 * 3) + pub_r001682_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = ((pub_r001682_12_1 * 2) + 32) & 63;
  int stage_v_46_2 = ((pub_r001682_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (((sec_r001682_10_1 * 3) + pub_r001682_7_1) + 31) & 127;
  int stage_v_47_2 = (((sec_r001682_10_2 * 3) + pub_r001682_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = (((sec_r001682_9_1 * 3) + pub_r001682_8_1) + 7) & 127;
  int stage_v_48_2 = (((sec_r001682_9_2 * 3) + pub_r001682_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = ((pub_r001682_1_1 * 2) + 5) & 63;
  int stage_v_49_2 = ((pub_r001682_1_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001682_2_1 * 2) + 40) & 63;
  int stage_v_50_2 = ((pub_r001682_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001682_16_1 * 2) + 42) & 63;
  int stage_v_51_2 = ((pub_r001682_16_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001682_10_1 * 2) + 25) & 63;
  int stage_v_52_2 = ((pub_r001682_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (((sec_r001682_0_1 * 3) + pub_r001682_17_1) + 45) & 127;
  int stage_v_53_2 = (((sec_r001682_0_2 * 3) + pub_r001682_17_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = ((pub_r001682_12_1 * 2) + 30) & 63;
  int stage_v_54_2 = ((pub_r001682_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (((sec_r001682_12_1 * 3) + pub_r001682_9_1) + 27) & 127;
  int stage_v_55_2 = (((sec_r001682_12_2 * 3) + pub_r001682_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = ((pub_r001682_6_1 * 2) + 24) & 63;
  int stage_v_56_2 = ((pub_r001682_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001682_11_1 * 2) + 22) & 63;
  int stage_v_57_2 = ((pub_r001682_11_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001682_14_1 * 2) + 45) & 63;
  int stage_v_58_2 = ((pub_r001682_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (((sec_r001682_7_1 * 3) + pub_r001682_13_1) + 22) & 127;
  int stage_v_59_2 = (((sec_r001682_7_2 * 3) + pub_r001682_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = ((pub_r001682_10_1 * 2) + 19) & 63;
  int stage_v_60_2 = ((pub_r001682_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001682_4_1 * 2) + 18) & 63;
  int stage_v_61_2 = ((pub_r001682_4_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = (((sec_r001682_16_1 * 3) + pub_r001682_3_1) + 25) & 127;
  int stage_v_62_2 = (((sec_r001682_16_2 * 3) + pub_r001682_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = (((helper_flow_1_1 * 3) + pub_r001682_4_1) + 13) & 127;
  int stage_v_63_2 = (((helper_flow_1_2 * 3) + pub_r001682_4_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((sec_r001682_5_1 * 3) + pub_r001682_0_1) + 21) & 127;
  int stage_v_64_2 = (((sec_r001682_5_2 * 3) + pub_r001682_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = ((pub_r001682_4_1 * 2) + 33) & 63;
  int stage_v_65_2 = ((pub_r001682_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001682_0_1 * 2) + 48) & 63;
  int stage_v_66_2 = ((pub_r001682_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001682_17_1 * 2) + 21) & 63;
  int stage_v_67_2 = ((pub_r001682_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001682_2_1 * 2) + 7) & 63;
  int stage_v_68_2 = ((pub_r001682_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = (((stage_v_55_1 * 3) + pub_r001682_10_1) + 8) & 127;
  int stage_v_69_2 = (((stage_v_55_2 * 3) + pub_r001682_10_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = (((sec_r001682_12_1 * 3) + pub_r001682_8_1) + 3) & 127;
  int stage_v_70_2 = (((sec_r001682_12_2 * 3) + pub_r001682_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = ((pub_r001682_7_1 * 2) + 49) & 63;
  int stage_v_71_2 = ((pub_r001682_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((sec_r001682_3_1 * 3) + pub_r001682_4_1) + 32) & 127;
  int stage_v_72_2 = (((sec_r001682_3_2 * 3) + pub_r001682_4_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = (((sec_r001682_12_1 * 3) + pub_r001682_8_1) + 6) & 127;
  int stage_v_73_2 = (((sec_r001682_12_2 * 3) + pub_r001682_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = ((pub_r001682_18_1 * 2) + 44) & 63;
  int stage_v_74_2 = ((pub_r001682_18_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (((stage_v_45_1 * 3) + pub_r001682_12_1) + 41) & 127;
  int stage_v_75_2 = (((stage_v_45_2 * 3) + pub_r001682_12_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = (((sec_r001682_3_1 * 3) + pub_r001682_14_1) + 12) & 127;
  int stage_v_76_2 = (((sec_r001682_3_2 * 3) + pub_r001682_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = ((pub_r001682_15_1 * 2) + 28) & 63;
  int stage_v_77_2 = ((pub_r001682_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = (((sec_r001682_15_1 * 3) + pub_r001682_6_1) + 29) & 127;
  int stage_v_78_2 = (((sec_r001682_15_2 * 3) + pub_r001682_6_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = ((pub_r001682_6_1 * 2) + 9) & 63;
  int stage_v_79_2 = ((pub_r001682_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001682_15_1 * 2) + 6) & 63;
  int stage_v_80_2 = ((pub_r001682_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((sec_r001682_7_1 * 3) + pub_r001682_4_1) + 41) & 127;
  int stage_v_81_2 = (((sec_r001682_7_2 * 3) + pub_r001682_4_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = (((stage_v_62_1 * 3) + pub_r001682_17_1) + 31) & 127;
  int stage_v_82_2 = (((stage_v_62_2 * 3) + pub_r001682_17_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = ((pub_r001682_10_1 * 2) + 25) & 63;
  int stage_v_83_2 = ((pub_r001682_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((sec_r001682_4_1 * 3) + pub_r001682_3_1) + 20) & 127;
  int stage_v_84_2 = (((sec_r001682_4_2 * 3) + pub_r001682_3_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = ((pub_r001682_14_1 * 2) + 34) & 63;
  int stage_v_85_2 = ((pub_r001682_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (((stage_v_69_1 * 3) + pub_r001682_19_1) + 43) & 127;
  int stage_v_86_2 = (((stage_v_69_2 * 3) + pub_r001682_19_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = ((pub_r001682_8_1 * 2) + 16) & 63;
  int stage_v_87_2 = ((pub_r001682_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((sec_r001682_17_1 * 3) + pub_r001682_8_1) + 16) & 127;
  int stage_v_88_2 = (((sec_r001682_17_2 * 3) + pub_r001682_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = ((pub_r001682_17_1 * 2) + 44) & 63;
  int stage_v_89_2 = ((pub_r001682_17_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((stage_v_62_1 * 3) + pub_r001682_14_1) + 20) & 127;
  int stage_v_90_2 = (((stage_v_62_2 * 3) + pub_r001682_14_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = (((stage_v_48_1 * 3) + pub_r001682_4_1) + 25) & 127;
  int stage_v_91_2 = (((stage_v_48_2 * 3) + pub_r001682_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = ((pub_r001682_12_1 * 2) + 27) & 63;
  int stage_v_92_2 = ((pub_r001682_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = (((stage_v_84_1 * 3) + pub_r001682_0_1) + 16) & 127;
  int stage_v_93_2 = (((stage_v_84_2 * 3) + pub_r001682_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = (((stage_v_75_1 * 3) + pub_r001682_8_1) + 10) & 127;
  int stage_v_94_2 = (((stage_v_75_2 * 3) + pub_r001682_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = ((pub_r001682_19_1 * 2) + 40) & 63;
  int stage_v_95_2 = ((pub_r001682_19_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001682_13_1 * 2) + 46) & 63;
  int stage_v_96_2 = ((pub_r001682_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001682_14_1 * 2) + 42) & 63;
  int stage_v_97_2 = ((pub_r001682_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001682_5_1 * 2) + 13) & 63;
  int stage_v_98_2 = ((pub_r001682_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001682_12_1 * 2) + 32) & 63;
  int stage_v_99_2 = ((pub_r001682_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (((sec_r001682_7_1 * 3) + pub_r001682_3_1) + 44) & 127;
  int stage_v_100_2 = (((sec_r001682_7_2 * 3) + pub_r001682_3_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_100_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_100_2 * 2)) & 255;
  int stage_v_101_1 = (((stage_v_23_1 * 3) + pub_r001682_6_1) + 10) & 127;
  int stage_v_101_2 = (((stage_v_23_2 * 3) + pub_r001682_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = ((pub_r001682_8_1 * 2) + 48) & 63;
  int stage_v_102_2 = ((pub_r001682_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (((helper_flow_0_1 * 3) + pub_r001682_2_1) + 29) & 127;
  int stage_v_103_2 = (((helper_flow_0_2 * 3) + pub_r001682_2_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = ((pub_r001682_8_1 * 2) + 10) & 63;
  int stage_v_104_2 = ((pub_r001682_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((stage_v_18_1 * 3) + pub_r001682_15_1) + 28) & 127;
  int stage_v_105_2 = (((stage_v_18_2 * 3) + pub_r001682_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = ((pub_r001682_10_1 * 2) + 7) & 63;
  int stage_v_106_2 = ((pub_r001682_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001682_19_1 * 2) + 13) & 63;
  int stage_v_107_2 = ((pub_r001682_19_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001682_17_1 * 2) + 26) & 63;
  int stage_v_108_2 = ((pub_r001682_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (((stage_v_81_1 * 3) + pub_r001682_5_1) + 37) & 127;
  int stage_v_109_2 = (((stage_v_81_2 * 3) + pub_r001682_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = ((pub_r001682_15_1 * 2) + 25) & 63;
  int stage_v_110_2 = ((pub_r001682_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001682_8_1 * 2) + 33) & 63;
  int stage_v_111_2 = ((pub_r001682_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001682_9_1 * 2) + 32) & 63;
  int stage_v_112_2 = ((pub_r001682_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001682_3_1 * 2) + 13) & 63;
  int stage_v_113_2 = ((pub_r001682_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001682_0_1 * 2) + 47) & 63;
  int stage_v_114_2 = ((pub_r001682_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001682_16_1 * 2) + 21) & 63;
  int stage_v_115_2 = ((pub_r001682_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001682_13_1 * 2) + 17) & 63;
  int stage_v_116_2 = ((pub_r001682_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001682_7_1 * 2) + 27) & 63;
  int stage_v_117_2 = ((pub_r001682_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001682_7_1 * 2) + 32) & 63;
  int stage_v_118_2 = ((pub_r001682_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001682_11_1 * 2) + 41) & 63;
  int stage_v_119_2 = ((pub_r001682_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001682_4_1 * 2) + 38) & 63;
  int stage_v_120_2 = ((pub_r001682_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = (((sec_r001682_17_1 * 3) + pub_r001682_11_1) + 20) & 127;
  int stage_v_121_2 = (((sec_r001682_17_2 * 3) + pub_r001682_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = (((sec_r001682_14_1 * 3) + pub_r001682_9_1) + 38) & 127;
  int stage_v_122_2 = (((sec_r001682_14_2 * 3) + pub_r001682_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = (((sec_r001682_13_1 * 3) + pub_r001682_12_1) + 35) & 127;
  int stage_v_123_2 = (((sec_r001682_13_2 * 3) + pub_r001682_12_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = (((stage_v_82_1 * 3) + pub_r001682_18_1) + 10) & 127;
  int stage_v_124_2 = (((stage_v_82_2 * 3) + pub_r001682_18_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = ((pub_r001682_13_1 * 2) + 47) & 63;
  int stage_v_125_2 = ((pub_r001682_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((sec_r001682_2_1 * 3) + pub_r001682_9_1) + 5) & 127;
  int stage_v_126_2 = (((sec_r001682_2_2 * 3) + pub_r001682_9_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = ((pub_r001682_13_1 * 2) + 35) & 63;
  int stage_v_127_2 = ((pub_r001682_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001682_19_1 * 2) + 41) & 63;
  int stage_v_128_2 = ((pub_r001682_19_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((stage_v_69_1 * 3) + pub_r001682_18_1) + 35) & 127;
  int stage_v_129_2 = (((stage_v_69_2 * 3) + pub_r001682_18_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = ((pub_r001682_16_1 * 2) + 30) & 63;
  int stage_v_130_2 = ((pub_r001682_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (((sec_r001682_14_1 * 3) + pub_r001682_18_1) + 4) & 127;
  int stage_v_131_2 = (((sec_r001682_14_2 * 3) + pub_r001682_18_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_131_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_131_2 * 2)) & 255;
  int stage_v_132_1 = ((pub_r001682_2_1 * 2) + 40) & 63;
  int stage_v_132_2 = ((pub_r001682_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001682_6_1 * 2) + 43) & 63;
  int stage_v_133_2 = ((pub_r001682_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = (((stage_v_94_1 * 3) + pub_r001682_8_1) + 16) & 127;
  int stage_v_134_2 = (((stage_v_94_2 * 3) + pub_r001682_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = (((stage_v_45_1 * 3) + pub_r001682_10_1) + 36) & 127;
  int stage_v_135_2 = (((stage_v_45_2 * 3) + pub_r001682_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = (((stage_v_0_1 * 3) + pub_r001682_7_1) + 11) & 127;
  int stage_v_136_2 = (((stage_v_0_2 * 3) + pub_r001682_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = ((pub_r001682_0_1 * 2) + 39) & 63;
  int stage_v_137_2 = ((pub_r001682_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((sec_r001682_0_1 * 3) + pub_r001682_2_1) + 13) & 127;
  int stage_v_138_2 = (((sec_r001682_0_2 * 3) + pub_r001682_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = ((pub_r001682_1_1 * 2) + 17) & 63;
  int stage_v_139_2 = ((pub_r001682_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001682_2_1 * 2) + 43) & 63;
  int stage_v_140_2 = ((pub_r001682_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001682_0_1 * 2) + 24) & 63;
  int stage_v_141_2 = ((pub_r001682_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001682_6_1 * 2) + 31) & 63;
  int stage_v_142_2 = ((pub_r001682_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001682_4_1 * 2) + 29) & 63;
  int stage_v_143_2 = ((pub_r001682_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001682_8_1 * 2) + 11) & 63;
  int stage_v_144_2 = ((pub_r001682_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001682_3_1 * 2) + 5) & 63;
  int stage_v_145_2 = ((pub_r001682_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001682_5_1 * 2) + 32) & 63;
  int stage_v_146_2 = ((pub_r001682_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((sec_r001682_7_1 * 3) + pub_r001682_13_1) + 11) & 127;
  int stage_v_147_2 = (((sec_r001682_7_2 * 3) + pub_r001682_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = (((stage_v_123_1 * 3) + pub_r001682_5_1) + 9) & 127;
  int stage_v_148_2 = (((stage_v_123_2 * 3) + pub_r001682_5_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = ((pub_r001682_18_1 * 2) + 33) & 63;
  int stage_v_149_2 = ((pub_r001682_18_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001682_11_1 * 2) + 29) & 63;
  int stage_v_150_2 = ((pub_r001682_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001682_4_1 * 2) + 45) & 63;
  int stage_v_151_2 = ((pub_r001682_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (((helper_flow_1_1 * 3) + pub_r001682_6_1) + 3) & 127;
  int stage_v_152_2 = (((helper_flow_1_2 * 3) + pub_r001682_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = ((pub_r001682_1_1 * 2) + 30) & 63;
  int stage_v_153_2 = ((pub_r001682_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((stage_v_90_1 * 3) + pub_r001682_13_1) + 34) & 127;
  int stage_v_154_2 = (((stage_v_90_2 * 3) + pub_r001682_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = ((pub_r001682_19_1 * 2) + 9) & 63;
  int stage_v_155_2 = ((pub_r001682_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001682_2_1 * 2) + 37) & 63;
  int stage_v_156_2 = ((pub_r001682_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001682_10_1 * 2) + 12) & 63;
  int stage_v_157_2 = ((pub_r001682_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = (((stage_v_91_1 * 3) + pub_r001682_7_1) + 21) & 127;
  int stage_v_158_2 = (((stage_v_91_2 * 3) + pub_r001682_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = ((pub_r001682_12_1 * 2) + 12) & 63;
  int stage_v_159_2 = ((pub_r001682_12_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001682_15_1 * 2) + 24) & 63;
  int stage_v_160_2 = ((pub_r001682_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001682_6_1 * 2) + 44) & 63;
  int stage_v_161_2 = ((pub_r001682_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001682_4_1 * 2) + 18) & 63;
  int stage_v_162_2 = ((pub_r001682_4_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (((stage_v_23_1 * 3) + pub_r001682_7_1) + 42) & 127;
  int stage_v_163_2 = (((stage_v_23_2 * 3) + pub_r001682_7_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = (((sec_r001682_14_1 * 3) + pub_r001682_17_1) + 16) & 127;
  int stage_v_164_2 = (((sec_r001682_14_2 * 3) + pub_r001682_17_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = ((pub_r001682_9_1 * 2) + 18) & 63;
  int stage_v_165_2 = ((pub_r001682_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001682_0_1 * 2) + 25) & 63;
  int stage_v_166_2 = ((pub_r001682_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((stage_v_138_1 * 3) + pub_r001682_2_1) + 36) & 127;
  int stage_v_167_2 = (((stage_v_138_2 * 3) + pub_r001682_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = ((pub_r001682_17_1 * 2) + 28) & 63;
  int stage_v_168_2 = ((pub_r001682_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (((stage_v_63_1 * 3) + pub_r001682_1_1) + 42) & 127;
  int stage_v_169_2 = (((stage_v_63_2 * 3) + pub_r001682_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = (((stage_v_134_1 * 3) + pub_r001682_1_1) + 42) & 127;
  int stage_v_170_2 = (((stage_v_134_2 * 3) + pub_r001682_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = ((pub_r001682_18_1 * 2) + 29) & 63;
  int stage_v_171_2 = ((pub_r001682_18_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((stage_v_129_1 * 3) + pub_r001682_10_1) + 27) & 127;
  int stage_v_172_2 = (((stage_v_129_2 * 3) + pub_r001682_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = (((stage_v_163_1 * 3) + pub_r001682_17_1) + 37) & 127;
  int stage_v_173_2 = (((stage_v_163_2 * 3) + pub_r001682_17_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = ((pub_r001682_6_1 * 2) + 45) & 63;
  int stage_v_174_2 = ((pub_r001682_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((stage_v_173_1 * 3) + pub_r001682_1_1) + 12) & 127;
  int stage_v_175_2 = (((stage_v_173_2 * 3) + pub_r001682_1_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = ((pub_r001682_9_1 * 2) + 26) & 63;
  int stage_v_176_2 = ((pub_r001682_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001682_7_1 * 2) + 40) & 63;
  int stage_v_177_2 = ((pub_r001682_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001682_13_1 * 2) + 16) & 63;
  int stage_v_178_2 = ((pub_r001682_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001682_14_1 * 2) + 12) & 63;
  int stage_v_179_2 = ((pub_r001682_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001682_19_1 * 2) + 25) & 63;
  int stage_v_180_2 = ((pub_r001682_19_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001682_3_1 * 2) + 43) & 63;
  int stage_v_181_2 = ((pub_r001682_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001682_4_1 * 2) + 31) & 63;
  int stage_v_182_2 = ((pub_r001682_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001682_3_1 * 2) + 44) & 63;
  int stage_v_183_2 = ((pub_r001682_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001682_12_1 * 2) + 16) & 63;
  int stage_v_184_2 = ((pub_r001682_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001682_17_1 * 2) + 16) & 63;
  int stage_v_185_2 = ((pub_r001682_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001682_11_1 * 2) + 43) & 63;
  int stage_v_186_2 = ((pub_r001682_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = (((stage_v_148_1 * 3) + pub_r001682_8_1) + 21) & 127;
  int stage_v_187_2 = (((stage_v_148_2 * 3) + pub_r001682_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = (((sec_r001682_15_1 * 3) + pub_r001682_10_1) + 45) & 127;
  int stage_v_188_2 = (((sec_r001682_15_2 * 3) + pub_r001682_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = ((pub_r001682_5_1 * 2) + 28) & 63;
  int stage_v_189_2 = ((pub_r001682_5_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001682_6_1 * 2) + 32) & 63;
  int stage_v_190_2 = ((pub_r001682_6_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (((stage_v_158_1 * 3) + pub_r001682_17_1) + 30) & 127;
  int stage_v_191_2 = (((stage_v_158_2 * 3) + pub_r001682_17_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = ((pub_r001682_8_1 * 2) + 11) & 63;
  int stage_v_192_2 = ((pub_r001682_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001682_13_1 * 2) + 38) & 63;
  int stage_v_193_2 = ((pub_r001682_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((pub_r001682_4_1 * 2) + 35) & 63;
  int stage_v_194_2 = ((pub_r001682_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001682_16_1 * 2) + 31) & 63;
  int stage_v_195_2 = ((pub_r001682_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((stage_v_188_1 * 3) + pub_r001682_17_1) + 28) & 127;
  int stage_v_196_2 = (((stage_v_188_2 * 3) + pub_r001682_17_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = ((pub_r001682_2_1 * 2) + 24) & 63;
  int stage_v_197_2 = ((pub_r001682_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((stage_v_124_1 * 3) + pub_r001682_1_1) + 43) & 127;
  int stage_v_198_2 = (((stage_v_124_2 * 3) + pub_r001682_1_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = ((pub_r001682_13_1 * 2) + 31) & 63;
  int stage_v_199_2 = ((pub_r001682_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001682_12_1 * 2) + 24) & 63;
  int stage_v_200_2 = ((pub_r001682_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = (((stage_v_152_1 * 3) + pub_r001682_2_1) + 35) & 127;
  int stage_v_201_2 = (((stage_v_152_2 * 3) + pub_r001682_2_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = ((pub_r001682_10_1 * 2) + 40) & 63;
  int stage_v_202_2 = ((pub_r001682_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (((sec_r001682_3_1 * 3) + pub_r001682_9_1) + 28) & 127;
  int stage_v_203_2 = (((sec_r001682_3_2 * 3) + pub_r001682_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = ((pub_r001682_10_1 * 2) + 29) & 63;
  int stage_v_204_2 = ((pub_r001682_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = (((stage_v_24_1 * 3) + pub_r001682_9_1) + 25) & 127;
  int stage_v_205_2 = (((stage_v_24_2 * 3) + pub_r001682_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = ((pub_r001682_12_1 * 2) + 33) & 63;
  int stage_v_206_2 = ((pub_r001682_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001682_9_1 * 2) + 38) & 63;
  int stage_v_207_2 = ((pub_r001682_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001682_13_1 * 2) + 25) & 63;
  int stage_v_208_2 = ((pub_r001682_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001682_6_1 * 2) + 22) & 63;
  int stage_v_209_2 = ((pub_r001682_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = (((stage_v_100_1 * 3) + pub_r001682_2_1) + 40) & 127;
  int stage_v_210_2 = (((stage_v_100_2 * 3) + pub_r001682_2_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = (((stage_v_173_1 * 3) + pub_r001682_0_1) + 18) & 127;
  int stage_v_211_2 = (((stage_v_173_2 * 3) + pub_r001682_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = ((pub_r001682_16_1 * 2) + 14) & 63;
  int stage_v_212_2 = ((pub_r001682_16_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001682_4_1 * 2) + 43) & 63;
  int stage_v_213_2 = ((pub_r001682_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001682_8_1 * 2) + 37) & 63;
  int stage_v_214_2 = ((pub_r001682_8_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001682_1_1 * 2) + 6) & 63;
  int stage_v_215_2 = ((pub_r001682_1_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001682_18_1 * 2) + 38) & 63;
  int stage_v_216_2 = ((pub_r001682_18_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((stage_v_64_1 * 3) + pub_r001682_15_1) + 22) & 127;
  int stage_v_217_2 = (((stage_v_64_2 * 3) + pub_r001682_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = ((pub_r001682_19_1 * 2) + 34) & 63;
  int stage_v_218_2 = ((pub_r001682_19_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001682_19_1 * 2) + 21) & 63;
  int stage_v_219_2 = ((pub_r001682_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((pub_r001682_12_1 * 2) + 35) & 63;
  int stage_v_220_2 = ((pub_r001682_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = (((stage_v_167_1 * 3) + pub_r001682_18_1) + 42) & 127;
  int stage_v_221_2 = (((stage_v_167_2 * 3) + pub_r001682_18_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = (((stage_v_81_1 * 3) + pub_r001682_8_1) + 15) & 127;
  int stage_v_222_2 = (((stage_v_81_2 * 3) + pub_r001682_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = (((stage_v_81_1 * 3) + pub_r001682_10_1) + 26) & 127;
  int stage_v_223_2 = (((stage_v_81_2 * 3) + pub_r001682_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = (((stage_v_187_1 * 3) + pub_r001682_16_1) + 20) & 127;
  int stage_v_224_2 = (((stage_v_187_2 * 3) + pub_r001682_16_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = ((pub_r001682_13_1 * 2) + 16) & 63;
  int stage_v_225_2 = ((pub_r001682_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001682_9_1 * 2) + 43) & 63;
  int stage_v_226_2 = ((pub_r001682_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((pub_r001682_9_1 * 2) + 50) & 63;
  int stage_v_227_2 = ((pub_r001682_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001682_3_1 * 2) + 43) & 63;
  int stage_v_228_2 = ((pub_r001682_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001682_3_1 * 2) + 13) & 63;
  int stage_v_229_2 = ((pub_r001682_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001682_8_1 * 2) + 34) & 63;
  int stage_v_230_2 = ((pub_r001682_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001682_3_1 * 2) + 50) & 63;
  int stage_v_231_2 = ((pub_r001682_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = (((stage_v_101_1 * 3) + pub_r001682_13_1) + 45) & 127;
  int stage_v_232_2 = (((stage_v_101_2 * 3) + pub_r001682_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = (((sec_r001682_15_1 * 3) + pub_r001682_3_1) + 31) & 127;
  int stage_v_233_2 = (((sec_r001682_15_2 * 3) + pub_r001682_3_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = ((pub_r001682_3_1 * 2) + 34) & 63;
  int stage_v_234_2 = ((pub_r001682_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001682_1_1 * 2) + 9) & 63;
  int stage_v_235_2 = ((pub_r001682_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001682_1_1 * 2) + 36) & 63;
  int stage_v_236_2 = ((pub_r001682_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = (((stage_v_135_1 * 3) + pub_r001682_18_1) + 29) & 127;
  int stage_v_237_2 = (((stage_v_135_2 * 3) + pub_r001682_18_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_237_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_237_2 * 2)) & 255;
  int stage_v_238_1 = ((pub_r001682_0_1 * 2) + 9) & 63;
  int stage_v_238_2 = ((pub_r001682_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001682_7_1 * 2) + 25) & 63;
  int stage_v_239_2 = ((pub_r001682_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((pub_r001682_10_1 * 2) + 33) & 63;
  int stage_v_240_2 = ((pub_r001682_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = (((stage_v_73_1 * 3) + pub_r001682_15_1) + 39) & 127;
  int stage_v_241_2 = (((stage_v_73_2 * 3) + pub_r001682_15_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = ((pub_r001682_14_1 * 2) + 21) & 63;
  int stage_v_242_2 = ((pub_r001682_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = (((stage_v_69_1 * 3) + pub_r001682_6_1) + 20) & 127;
  int stage_v_243_2 = (((stage_v_69_2 * 3) + pub_r001682_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = (((stage_v_73_1 * 3) + pub_r001682_8_1) + 27) & 127;
  int stage_v_244_2 = (((stage_v_73_2 * 3) + pub_r001682_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = ((pub_r001682_11_1 * 2) + 12) & 63;
  int stage_v_245_2 = ((pub_r001682_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001682_1_1 * 2) + 38) & 63;
  int stage_v_246_2 = ((pub_r001682_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001682_6_1 * 2) + 35) & 63;
  int stage_v_247_2 = ((pub_r001682_6_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = (((stage_v_72_1 * 3) + pub_r001682_6_1) + 7) & 127;
  int stage_v_248_2 = (((stage_v_72_2 * 3) + pub_r001682_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = (((sec_r001682_13_1 * 3) + pub_r001682_16_1) + 37) & 127;
  int stage_v_249_2 = (((sec_r001682_13_2 * 3) + pub_r001682_16_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = ((pub_r001682_11_1 * 2) + 37) & 63;
  int stage_v_250_2 = ((pub_r001682_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = (((stage_v_124_1 * 3) + pub_r001682_1_1) + 42) & 127;
  int stage_v_251_2 = (((stage_v_124_2 * 3) + pub_r001682_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = (((stage_v_223_1 * 3) + pub_r001682_15_1) + 28) & 127;
  int stage_v_252_2 = (((stage_v_223_2 * 3) + pub_r001682_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = ((pub_r001682_19_1 * 2) + 15) & 63;
  int stage_v_253_2 = ((pub_r001682_19_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = ((pub_r001682_1_1 * 2) + 40) & 63;
  int stage_v_254_2 = ((pub_r001682_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((pub_r001682_14_1 * 2) + 19) & 63;
  int stage_v_255_2 = ((pub_r001682_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001682_17_1 * 2) + 20) & 63;
  int stage_v_256_2 = ((pub_r001682_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001682_14_1 * 2) + 11) & 63;
  int stage_v_257_2 = ((pub_r001682_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((helper_flow_2_1 * 3) + pub_r001682_16_1) + 11) & 127;
  int stage_v_258_2 = (((helper_flow_2_2 * 3) + pub_r001682_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = ((pub_r001682_3_1 * 2) + 10) & 63;
  int stage_v_259_2 = ((pub_r001682_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001682_7_1 * 2) + 35) & 63;
  int stage_v_260_2 = ((pub_r001682_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001682_2_1 * 2) + 30) & 63;
  int stage_v_261_2 = ((pub_r001682_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001682_9_1 * 2) + 8) & 63;
  int stage_v_262_2 = ((pub_r001682_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001682_12_1 * 2) + 32) & 63;
  int stage_v_263_2 = ((pub_r001682_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((pub_r001682_8_1 * 2) + 15) & 63;
  int stage_v_264_2 = ((pub_r001682_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((pub_r001682_16_1 * 2) + 16) & 63;
  int stage_v_265_2 = ((pub_r001682_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = ((pub_r001682_1_1 * 2) + 20) & 63;
  int stage_v_266_2 = ((pub_r001682_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((pub_r001682_3_1 * 2) + 41) & 63;
  int stage_v_267_2 = ((pub_r001682_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((pub_r001682_16_1 * 2) + 21) & 63;
  int stage_v_268_2 = ((pub_r001682_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001682_13_1 * 2) + 50) & 63;
  int stage_v_269_2 = ((pub_r001682_13_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = (((stage_v_59_1 * 3) + pub_r001682_16_1) + 22) & 127;
  int stage_v_270_2 = (((stage_v_59_2 * 3) + pub_r001682_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = (((sec_r001682_1_1 * 3) + pub_r001682_8_1) + 36) & 127;
  int stage_v_271_2 = (((sec_r001682_1_2 * 3) + pub_r001682_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = ((pub_r001682_14_1 * 2) + 32) & 63;
  int stage_v_272_2 = ((pub_r001682_14_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = ((pub_r001682_19_1 * 2) + 13) & 63;
  int stage_v_273_2 = ((pub_r001682_19_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = (((stage_v_81_1 * 3) + pub_r001682_9_1) + 32) & 127;
  int stage_v_274_2 = (((stage_v_81_2 * 3) + pub_r001682_9_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = (((stage_v_251_1 * 3) + pub_r001682_7_1) + 36) & 127;
  int stage_v_275_2 = (((stage_v_251_2 * 3) + pub_r001682_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = ((pub_r001682_18_1 * 2) + 17) & 63;
  int stage_v_276_2 = ((pub_r001682_18_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = (((stage_v_241_1 * 3) + pub_r001682_9_1) + 12) & 127;
  int stage_v_277_2 = (((stage_v_241_2 * 3) + pub_r001682_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = (((sec_r001682_13_1 * 3) + pub_r001682_5_1) + 45) & 127;
  int stage_v_278_2 = (((sec_r001682_13_2 * 3) + pub_r001682_5_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = ((pub_r001682_3_1 * 2) + 16) & 63;
  int stage_v_279_2 = ((pub_r001682_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001682_18_1 * 2) + 39) & 63;
  int stage_v_280_2 = ((pub_r001682_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((pub_r001682_18_1 * 2) + 8) & 63;
  int stage_v_281_2 = ((pub_r001682_18_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((pub_r001682_11_1 * 2) + 6) & 63;
  int stage_v_282_2 = ((pub_r001682_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001682_17_1 * 2) + 12) & 63;
  int stage_v_283_2 = ((pub_r001682_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001682_17_1 * 2) + 32) & 63;
  int stage_v_284_2 = ((pub_r001682_17_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001682_14_1 * 2) + 37) & 63;
  int stage_v_285_2 = ((pub_r001682_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001682_17_1 * 2) + 35) & 63;
  int stage_v_286_2 = ((pub_r001682_17_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = (((stage_v_172_1 * 3) + pub_r001682_16_1) + 14) & 127;
  int stage_v_287_2 = (((stage_v_172_2 * 3) + pub_r001682_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = (((stage_v_53_1 * 3) + pub_r001682_12_1) + 14) & 127;
  int stage_v_288_2 = (((stage_v_53_2 * 3) + pub_r001682_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = (((sec_r001682_14_1 * 3) + pub_r001682_18_1) + 9) & 127;
  int stage_v_289_2 = (((sec_r001682_14_2 * 3) + pub_r001682_18_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = ((pub_r001682_13_1 * 2) + 13) & 63;
  int stage_v_290_2 = ((pub_r001682_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = ((pub_r001682_19_1 * 2) + 16) & 63;
  int stage_v_291_2 = ((pub_r001682_19_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((pub_r001682_2_1 * 2) + 38) & 63;
  int stage_v_292_2 = ((pub_r001682_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001682_15_1 * 2) + 46) & 63;
  int stage_v_293_2 = ((pub_r001682_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = (((stage_v_252_1 * 3) + pub_r001682_15_1) + 22) & 127;
  int stage_v_294_2 = (((stage_v_252_2 * 3) + pub_r001682_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = ((pub_r001682_9_1 * 2) + 27) & 63;
  int stage_v_295_2 = ((pub_r001682_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = ((pub_r001682_10_1 * 2) + 9) & 63;
  int stage_v_296_2 = ((pub_r001682_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = (((stage_v_169_1 * 3) + pub_r001682_0_1) + 13) & 127;
  int stage_v_297_2 = (((stage_v_169_2 * 3) + pub_r001682_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = ((pub_r001682_5_1 * 2) + 26) & 63;
  int stage_v_298_2 = ((pub_r001682_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((pub_r001682_0_1 * 2) + 27) & 63;
  int stage_v_299_2 = ((pub_r001682_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = (((stage_v_47_1 * 3) + pub_r001682_7_1) + 37) & 127;
  int stage_v_300_2 = (((stage_v_47_2 * 3) + pub_r001682_7_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = (((stage_v_147_1 * 3) + pub_r001682_12_1) + 22) & 127;
  int stage_v_301_2 = (((stage_v_147_2 * 3) + pub_r001682_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = ((pub_r001682_5_1 * 2) + 19) & 63;
  int stage_v_302_2 = ((pub_r001682_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001682_17_1 * 2) + 9) & 63;
  int stage_v_303_2 = ((pub_r001682_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((pub_r001682_0_1 * 2) + 47) & 63;
  int stage_v_304_2 = ((pub_r001682_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = (((sec_r001682_2_1 * 3) + pub_r001682_7_1) + 16) & 127;
  int stage_v_305_2 = (((sec_r001682_2_2 * 3) + pub_r001682_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_305_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_305_2 * 2)) & 255;
  int stage_v_306_1 = (((stage_v_55_1 * 3) + pub_r001682_18_1) + 21) & 127;
  int stage_v_306_2 = (((stage_v_55_2 * 3) + pub_r001682_18_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = (((stage_v_55_1 * 3) + pub_r001682_1_1) + 35) & 127;
  int stage_v_307_2 = (((stage_v_55_2 * 3) + pub_r001682_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = ((pub_r001682_1_1 * 2) + 7) & 63;
  int stage_v_308_2 = ((pub_r001682_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((pub_r001682_10_1 * 2) + 5) & 63;
  int stage_v_309_2 = ((pub_r001682_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = (((stage_v_103_1 * 3) + pub_r001682_17_1) + 40) & 127;
  int stage_v_310_2 = (((stage_v_103_2 * 3) + pub_r001682_17_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = ((pub_r001682_9_1 * 2) + 38) & 63;
  int stage_v_311_2 = ((pub_r001682_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = ((pub_r001682_10_1 * 2) + 43) & 63;
  int stage_v_312_2 = ((pub_r001682_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = ((pub_r001682_10_1 * 2) + 8) & 63;
  int stage_v_313_2 = ((pub_r001682_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = (((stage_v_64_1 * 3) + pub_r001682_9_1) + 22) & 127;
  int stage_v_314_2 = (((stage_v_64_2 * 3) + pub_r001682_9_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = ((pub_r001682_12_1 * 2) + 9) & 63;
  int stage_v_315_2 = ((pub_r001682_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = (((stage_v_301_1 * 3) + pub_r001682_11_1) + 43) & 127;
  int stage_v_316_2 = (((stage_v_301_2 * 3) + pub_r001682_11_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = ((pub_r001682_9_1 * 2) + 46) & 63;
  int stage_v_317_2 = ((pub_r001682_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((pub_r001682_5_1 * 2) + 16) & 63;
  int stage_v_318_2 = ((pub_r001682_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((pub_r001682_17_1 * 2) + 50) & 63;
  int stage_v_319_2 = ((pub_r001682_17_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((pub_r001682_7_1 * 2) + 18) & 63;
  int stage_v_320_2 = ((pub_r001682_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = (((stage_v_277_1 * 3) + pub_r001682_0_1) + 27) & 127;
  int stage_v_321_2 = (((stage_v_277_2 * 3) + pub_r001682_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = (((stage_v_300_1 * 3) + pub_r001682_2_1) + 27) & 127;
  int stage_v_322_2 = (((stage_v_300_2 * 3) + pub_r001682_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = ((pub_r001682_0_1 * 2) + 14) & 63;
  int stage_v_323_2 = ((pub_r001682_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((pub_r001682_2_1 * 2) + 22) & 63;
  int stage_v_324_2 = ((pub_r001682_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((pub_r001682_12_1 * 2) + 6) & 63;
  int stage_v_325_2 = ((pub_r001682_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((pub_r001682_2_1 * 2) + 35) & 63;
  int stage_v_326_2 = ((pub_r001682_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001682_0_1 * 2) + 20) & 63;
  int stage_v_327_2 = ((pub_r001682_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((pub_r001682_19_1 * 2) + 6) & 63;
  int stage_v_328_2 = ((pub_r001682_19_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = (((sec_r001682_11_1 * 3) + pub_r001682_2_1) + 29) & 127;
  int stage_v_329_2 = (((sec_r001682_11_2 * 3) + pub_r001682_2_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = (((stage_v_316_1 * 3) + pub_r001682_13_1) + 28) & 127;
  int stage_v_330_2 = (((stage_v_316_2 * 3) + pub_r001682_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = ((pub_r001682_9_1 * 2) + 29) & 63;
  int stage_v_331_2 = ((pub_r001682_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001682_7_1 * 2) + 24) & 63;
  int stage_v_332_2 = ((pub_r001682_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001682_5_1 * 2) + 49) & 63;
  int stage_v_333_2 = ((pub_r001682_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = (((sec_r001682_15_1 * 3) + pub_r001682_17_1) + 42) & 127;
  int stage_v_334_2 = (((sec_r001682_15_2 * 3) + pub_r001682_17_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = ((pub_r001682_18_1 * 2) + 33) & 63;
  int stage_v_335_2 = ((pub_r001682_18_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((pub_r001682_16_1 * 2) + 9) & 63;
  int stage_v_336_2 = ((pub_r001682_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = (((stage_v_1_1 * 3) + pub_r001682_6_1) + 32) & 127;
  int stage_v_337_2 = (((stage_v_1_2 * 3) + pub_r001682_6_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = (((stage_v_152_1 * 3) + pub_r001682_17_1) + 35) & 127;
  int stage_v_338_2 = (((stage_v_152_2 * 3) + pub_r001682_17_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = (((stage_v_288_1 * 3) + pub_r001682_11_1) + 19) & 127;
  int stage_v_339_2 = (((stage_v_288_2 * 3) + pub_r001682_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = ((pub_r001682_14_1 * 2) + 39) & 63;
  int stage_v_340_2 = ((pub_r001682_14_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((pub_r001682_2_1 * 2) + 40) & 63;
  int stage_v_341_2 = ((pub_r001682_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = (((helper_flow_1_1 * 3) + pub_r001682_16_1) + 28) & 127;
  int stage_v_342_2 = (((helper_flow_1_2 * 3) + pub_r001682_16_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = ((pub_r001682_5_1 * 2) + 8) & 63;
  int stage_v_343_2 = ((pub_r001682_5_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = (((stage_v_310_1 * 3) + pub_r001682_3_1) + 21) & 127;
  int stage_v_344_2 = (((stage_v_310_2 * 3) + pub_r001682_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = ((pub_r001682_16_1 * 2) + 30) & 63;
  int stage_v_345_2 = ((pub_r001682_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((pub_r001682_10_1 * 2) + 44) & 63;
  int stage_v_346_2 = ((pub_r001682_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = (((stage_v_300_1 * 3) + pub_r001682_11_1) + 24) & 127;
  int stage_v_347_2 = (((stage_v_300_2 * 3) + pub_r001682_11_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = ((pub_r001682_2_1 * 2) + 31) & 63;
  int stage_v_348_2 = ((pub_r001682_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = (((stage_v_316_1 * 3) + pub_r001682_17_1) + 45) & 127;
  int stage_v_349_2 = (((stage_v_316_2 * 3) + pub_r001682_17_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = ((pub_r001682_4_1 * 2) + 36) & 63;
  int stage_v_350_2 = ((pub_r001682_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = ((pub_r001682_16_1 * 2) + 46) & 63;
  int stage_v_351_2 = ((pub_r001682_16_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((pub_r001682_8_1 * 2) + 5) & 63;
  int stage_v_352_2 = ((pub_r001682_8_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((pub_r001682_13_1 * 2) + 14) & 63;
  int stage_v_353_2 = ((pub_r001682_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((pub_r001682_10_1 * 2) + 25) & 63;
  int stage_v_354_2 = ((pub_r001682_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = (((stage_v_203_1 * 3) + pub_r001682_1_1) + 24) & 127;
  int stage_v_355_2 = (((stage_v_203_2 * 3) + pub_r001682_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = (((stage_v_134_1 * 3) + pub_r001682_6_1) + 33) & 127;
  int stage_v_356_2 = (((stage_v_134_2 * 3) + pub_r001682_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = ((pub_r001682_11_1 * 2) + 7) & 63;
  int stage_v_357_2 = ((pub_r001682_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = (((sec_r001682_16_1 * 3) + pub_r001682_17_1) + 22) & 127;
  int stage_v_358_2 = (((sec_r001682_16_2 * 3) + pub_r001682_17_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = ((pub_r001682_2_1 * 2) + 48) & 63;
  int stage_v_359_2 = ((pub_r001682_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((pub_r001682_14_1 * 2) + 27) & 63;
  int stage_v_360_2 = ((pub_r001682_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = ((pub_r001682_8_1 * 2) + 33) & 63;
  int stage_v_361_2 = ((pub_r001682_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001682_9_1 * 2) + 35) & 63;
  int stage_v_362_2 = ((pub_r001682_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001682_12_1 * 2) + 8) & 63;
  int stage_v_363_2 = ((pub_r001682_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((pub_r001682_11_1 * 2) + 45) & 63;
  int stage_v_364_2 = ((pub_r001682_11_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = (((stage_v_203_1 * 3) + pub_r001682_19_1) + 42) & 127;
  int stage_v_365_2 = (((stage_v_203_2 * 3) + pub_r001682_19_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = ((pub_r001682_9_1 * 2) + 50) & 63;
  int stage_v_366_2 = ((pub_r001682_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = ((pub_r001682_14_1 * 2) + 37) & 63;
  int stage_v_367_2 = ((pub_r001682_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((pub_r001682_16_1 * 2) + 34) & 63;
  int stage_v_368_2 = ((pub_r001682_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = (((stage_v_23_1 * 3) + pub_r001682_0_1) + 29) & 127;
  int stage_v_369_2 = (((stage_v_23_2 * 3) + pub_r001682_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = ((pub_r001682_2_1 * 2) + 42) & 63;
  int stage_v_370_2 = ((pub_r001682_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((pub_r001682_10_1 * 2) + 7) & 63;
  int stage_v_371_2 = ((pub_r001682_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001682_4_1 * 2) + 22) & 63;
  int stage_v_372_2 = ((pub_r001682_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001682_16_1 * 2) + 31) & 63;
  int stage_v_373_2 = ((pub_r001682_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = (((sec_r001682_4_1 * 3) + pub_r001682_13_1) + 40) & 127;
  int stage_v_374_2 = (((sec_r001682_4_2 * 3) + pub_r001682_13_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_11_1 * 3) + pub_r001682_17_1) + 40) & 127;
  int stage_v_375_2 = (((stage_v_11_2 * 3) + pub_r001682_17_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = ((pub_r001682_6_1 * 2) + 18) & 63;
  int stage_v_376_2 = ((pub_r001682_6_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = (((stage_v_287_1 * 3) + pub_r001682_15_1) + 15) & 127;
  int stage_v_377_2 = (((stage_v_287_2 * 3) + pub_r001682_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = ((pub_r001682_11_1 * 2) + 38) & 63;
  int stage_v_378_2 = ((pub_r001682_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = ((pub_r001682_12_1 * 2) + 38) & 63;
  int stage_v_379_2 = ((pub_r001682_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = (((sec_r001682_13_1 * 3) + pub_r001682_16_1) + 42) & 127;
  int stage_v_380_2 = (((sec_r001682_13_2 * 3) + pub_r001682_16_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = ((pub_r001682_12_1 * 2) + 33) & 63;
  int stage_v_381_2 = ((pub_r001682_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = ((pub_r001682_12_1 * 2) + 5) & 63;
  int stage_v_382_2 = ((pub_r001682_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((pub_r001682_18_1 * 2) + 34) & 63;
  int stage_v_383_2 = ((pub_r001682_18_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001682_3_1 * 2) + 42) & 63;
  int stage_v_384_2 = ((pub_r001682_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((pub_r001682_12_1 * 2) + 25) & 63;
  int stage_v_385_2 = ((pub_r001682_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = (((stage_v_243_1 * 3) + pub_r001682_11_1) + 38) & 127;
  int stage_v_386_2 = (((stage_v_243_2 * 3) + pub_r001682_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_386_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_386_2 * 2)) & 255;
  int stage_v_387_1 = ((pub_r001682_14_1 * 2) + 34) & 63;
  int stage_v_387_2 = ((pub_r001682_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = (((stage_v_221_1 * 3) + pub_r001682_16_1) + 22) & 127;
  int stage_v_388_2 = (((stage_v_221_2 * 3) + pub_r001682_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_388_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_388_2 * 2)) & 255;
  int stage_v_389_1 = (((stage_v_75_1 * 3) + pub_r001682_5_1) + 25) & 127;
  int stage_v_389_2 = (((stage_v_75_2 * 3) + pub_r001682_5_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = ((pub_r001682_3_1 * 2) + 39) & 63;
  int stage_v_390_2 = ((pub_r001682_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((pub_r001682_4_1 * 2) + 38) & 63;
  int stage_v_391_2 = ((pub_r001682_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = (((stage_v_121_1 * 3) + pub_r001682_19_1) + 40) & 127;
  int stage_v_392_2 = (((stage_v_121_2 * 3) + pub_r001682_19_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = (((stage_v_76_1 * 3) + pub_r001682_14_1) + 10) & 127;
  int stage_v_393_2 = (((stage_v_76_2 * 3) + pub_r001682_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = ((pub_r001682_17_1 * 2) + 45) & 63;
  int stage_v_394_2 = ((pub_r001682_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = (((stage_v_232_1 * 3) + pub_r001682_16_1) + 7) & 127;
  int stage_v_395_2 = (((stage_v_232_2 * 3) + pub_r001682_16_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_395_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_395_2 * 2)) & 255;
  int stage_v_396_1 = ((pub_r001682_4_1 * 2) + 42) & 63;
  int stage_v_396_2 = ((pub_r001682_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = ((pub_r001682_10_1 * 2) + 27) & 63;
  int stage_v_397_2 = ((pub_r001682_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((pub_r001682_15_1 * 2) + 11) & 63;
  int stage_v_398_2 = ((pub_r001682_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001682_1_1 * 2) + 32) & 63;
  int stage_v_399_2 = ((pub_r001682_1_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = (((stage_v_124_1 * 3) + pub_r001682_12_1) + 11) & 127;
  int stage_v_400_2 = (((stage_v_124_2 * 3) + pub_r001682_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_400_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_400_2 * 2)) & 255;
  int stage_v_401_1 = ((pub_r001682_2_1 * 2) + 10) & 63;
  int stage_v_401_2 = ((pub_r001682_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = ((pub_r001682_10_1 * 2) + 39) & 63;
  int stage_v_402_2 = ((pub_r001682_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = (((stage_v_1_1 * 3) + pub_r001682_4_1) + 38) & 127;
  int stage_v_403_2 = (((stage_v_1_2 * 3) + pub_r001682_4_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_403_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_403_2 * 2)) & 255;
  int stage_v_404_1 = (((stage_v_90_1 * 3) + pub_r001682_0_1) + 27) & 127;
  int stage_v_404_2 = (((stage_v_90_2 * 3) + pub_r001682_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = ((pub_r001682_5_1 * 2) + 39) & 63;
  int stage_v_405_2 = ((pub_r001682_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = ((pub_r001682_11_1 * 2) + 30) & 63;
  int stage_v_406_2 = ((pub_r001682_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = ((pub_r001682_13_1 * 2) + 44) & 63;
  int stage_v_407_2 = ((pub_r001682_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = (((stage_v_338_1 * 3) + pub_r001682_8_1) + 8) & 127;
  int stage_v_408_2 = (((stage_v_338_2 * 3) + pub_r001682_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = ((pub_r001682_13_1 * 2) + 44) & 63;
  int stage_v_409_2 = ((pub_r001682_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = ((pub_r001682_13_1 * 2) + 13) & 63;
  int stage_v_410_2 = ((pub_r001682_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = (((stage_v_62_1 * 3) + pub_r001682_15_1) + 21) & 127;
  int stage_v_411_2 = (((stage_v_62_2 * 3) + pub_r001682_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_411_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_411_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_411_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_411_2 * 2)) & 255;
  int stage_v_412_1 = ((pub_r001682_14_1 * 2) + 13) & 63;
  int stage_v_412_2 = ((pub_r001682_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = ((pub_r001682_5_1 * 2) + 34) & 63;
  int stage_v_413_2 = ((pub_r001682_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((pub_r001682_15_1 * 2) + 26) & 63;
  int stage_v_414_2 = ((pub_r001682_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = ((pub_r001682_12_1 * 2) + 17) & 63;
  int stage_v_415_2 = ((pub_r001682_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = (((stage_v_11_1 * 3) + pub_r001682_8_1) + 44) & 127;
  int stage_v_416_2 = (((stage_v_11_2 * 3) + pub_r001682_8_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_416_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_416_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_416_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_416_2 * 2)) & 255;
  int stage_v_417_1 = ((pub_r001682_10_1 * 2) + 29) & 63;
  int stage_v_417_2 = ((pub_r001682_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((pub_r001682_4_1 * 2) + 31) & 63;
  int stage_v_418_2 = ((pub_r001682_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = ((pub_r001682_2_1 * 2) + 7) & 63;
  int stage_v_419_2 = ((pub_r001682_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = ((pub_r001682_8_1 * 2) + 16) & 63;
  int stage_v_420_2 = ((pub_r001682_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = ((pub_r001682_11_1 * 2) + 36) & 63;
  int stage_v_421_2 = ((pub_r001682_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = (((stage_v_164_1 * 3) + pub_r001682_9_1) + 44) & 127;
  int stage_v_422_2 = (((stage_v_164_2 * 3) + pub_r001682_9_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_422_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_422_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_422_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_422_2 * 2)) & 255;
  int stage_v_423_1 = ((pub_r001682_0_1 * 2) + 48) & 63;
  int stage_v_423_2 = ((pub_r001682_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001682_9_1 * 2) + 41) & 63;
  int stage_v_424_2 = ((pub_r001682_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = (((stage_v_81_1 * 3) + pub_r001682_11_1) + 36) & 127;
  int stage_v_425_2 = (((stage_v_81_2 * 3) + pub_r001682_11_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_425_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_425_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_425_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_425_2 * 2)) & 255;
  int stage_v_426_1 = ((pub_r001682_10_1 * 2) + 23) & 63;
  int stage_v_426_2 = ((pub_r001682_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = ((pub_r001682_12_1 * 2) + 39) & 63;
  int stage_v_427_2 = ((pub_r001682_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = (((stage_v_103_1 * 3) + pub_r001682_18_1) + 32) & 127;
  int stage_v_428_2 = (((stage_v_103_2 * 3) + pub_r001682_18_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_428_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_428_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_428_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_428_2 * 2)) & 255;
  int stage_v_429_1 = ((pub_r001682_10_1 * 2) + 43) & 63;
  int stage_v_429_2 = ((pub_r001682_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_429_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_429_2) & 127;
  int stage_v_430_1 = (((stage_v_129_1 * 3) + pub_r001682_6_1) + 20) & 127;
  int stage_v_430_2 = (((stage_v_129_2 * 3) + pub_r001682_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_430_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_430_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_430_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_430_2 * 2)) & 255;
  int stage_v_431_1 = (((stage_v_1_1 * 3) + pub_r001682_16_1) + 15) & 127;
  int stage_v_431_2 = (((stage_v_1_2 * 3) + pub_r001682_16_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_431_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_431_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_431_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_431_2 * 2)) & 255;
  int stage_v_432_1 = (((stage_v_305_1 * 3) + pub_r001682_8_1) + 34) & 127;
  int stage_v_432_2 = (((stage_v_305_2 * 3) + pub_r001682_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_432_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_432_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_432_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_432_2 * 2)) & 255;
  int stage_v_433_1 = (((stage_v_358_1 * 3) + pub_r001682_7_1) + 31) & 127;
  int stage_v_433_2 = (((stage_v_358_2 * 3) + pub_r001682_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_433_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_433_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_433_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_433_2 * 2)) & 255;
  int stage_v_434_1 = ((pub_r001682_6_1 * 2) + 16) & 63;
  int stage_v_434_2 = ((pub_r001682_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = (((helper_flow_0_1 * 3) + pub_r001682_10_1) + 31) & 127;
  int stage_v_435_2 = (((helper_flow_0_2 * 3) + pub_r001682_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_435_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_435_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_435_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_435_2 * 2)) & 255;
  int stage_v_436_1 = ((pub_r001682_9_1 * 2) + 15) & 63;
  int stage_v_436_2 = ((pub_r001682_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = ((pub_r001682_18_1 * 2) + 5) & 63;
  int stage_v_437_2 = ((pub_r001682_18_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_437_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_437_2) & 127;
  int stage_v_438_1 = (((stage_v_217_1 * 3) + pub_r001682_18_1) + 28) & 127;
  int stage_v_438_2 = (((stage_v_217_2 * 3) + pub_r001682_18_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_438_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_438_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_438_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_438_2 * 2)) & 255;
  int stage_v_439_1 = ((pub_r001682_10_1 * 2) + 21) & 63;
  int stage_v_439_2 = ((pub_r001682_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = ((pub_r001682_14_1 * 2) + 40) & 63;
  int stage_v_440_2 = ((pub_r001682_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((pub_r001682_11_1 * 2) + 28) & 63;
  int stage_v_441_2 = ((pub_r001682_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = ((pub_r001682_2_1 * 2) + 18) & 63;
  int stage_v_442_2 = ((pub_r001682_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = (((stage_v_338_1 * 3) + pub_r001682_18_1) + 8) & 127;
  int stage_v_443_2 = (((stage_v_338_2 * 3) + pub_r001682_18_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_443_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_443_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_443_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_443_2 * 2)) & 255;
  int stage_v_444_1 = (((stage_v_163_1 * 3) + pub_r001682_14_1) + 39) & 127;
  int stage_v_444_2 = (((stage_v_163_2 * 3) + pub_r001682_14_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_444_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_444_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_444_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_444_2 * 2)) & 255;
  int stage_v_445_1 = (((stage_v_288_1 * 3) + pub_r001682_6_1) + 44) & 127;
  int stage_v_445_2 = (((stage_v_288_2 * 3) + pub_r001682_6_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_445_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_445_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_445_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_445_2 * 2)) & 255;
  int stage_v_446_1 = ((pub_r001682_7_1 * 2) + 37) & 63;
  int stage_v_446_2 = ((pub_r001682_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_446_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_446_2) & 127;
  int stage_v_447_1 = (((stage_v_164_1 * 3) + pub_r001682_12_1) + 42) & 127;
  int stage_v_447_2 = (((stage_v_164_2 * 3) + pub_r001682_12_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_447_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_447_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_447_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_447_2 * 2)) & 255;
  int stage_v_448_1 = ((pub_r001682_2_1 * 2) + 49) & 63;
  int stage_v_448_2 = ((pub_r001682_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = ((pub_r001682_2_1 * 2) + 6) & 63;
  int stage_v_449_2 = ((pub_r001682_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_449_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_449_2) & 127;
  int stage_v_450_1 = (((stage_v_198_1 * 3) + pub_r001682_8_1) + 20) & 127;
  int stage_v_450_2 = (((stage_v_198_2 * 3) + pub_r001682_8_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_450_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_450_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_450_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_450_2 * 2)) & 255;
  int stage_v_451_1 = (((stage_v_55_1 * 3) + pub_r001682_2_1) + 4) & 127;
  int stage_v_451_2 = (((stage_v_55_2 * 3) + pub_r001682_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_451_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_451_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_451_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_451_2 * 2)) & 255;
  int stage_v_452_1 = ((pub_r001682_2_1 * 2) + 24) & 63;
  int stage_v_452_2 = ((pub_r001682_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = (((stage_v_347_1 * 3) + pub_r001682_17_1) + 25) & 127;
  int stage_v_453_2 = (((stage_v_347_2 * 3) + pub_r001682_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_453_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_453_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_453_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_453_2 * 2)) & 255;
  int stage_v_454_1 = ((pub_r001682_13_1 * 2) + 42) & 63;
  int stage_v_454_2 = ((pub_r001682_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_454_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_454_2) & 127;
  int stage_v_455_1 = ((pub_r001682_14_1 * 2) + 42) & 63;
  int stage_v_455_2 = ((pub_r001682_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_455_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_455_2) & 127;
  int stage_v_456_1 = ((pub_r001682_8_1 * 2) + 47) & 63;
  int stage_v_456_2 = ((pub_r001682_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_456_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_456_2) & 127;
  int stage_v_457_1 = ((pub_r001682_9_1 * 2) + 28) & 63;
  int stage_v_457_2 = ((pub_r001682_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_457_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_457_2) & 127;
  int stage_v_458_1 = (((stage_v_196_1 * 3) + pub_r001682_14_1) + 41) & 127;
  int stage_v_458_2 = (((stage_v_196_2 * 3) + pub_r001682_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_458_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_458_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_458_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_458_2 * 2)) & 255;
  int stage_v_459_1 = ((pub_r001682_11_1 * 2) + 34) & 63;
  int stage_v_459_2 = ((pub_r001682_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_459_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_459_2) & 127;
  int stage_v_460_1 = (((stage_v_196_1 * 3) + pub_r001682_18_1) + 31) & 127;
  int stage_v_460_2 = (((stage_v_196_2 * 3) + pub_r001682_18_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_460_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_460_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_460_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_460_2 * 2)) & 255;
  int stage_v_461_1 = (((stage_v_76_1 * 3) + pub_r001682_15_1) + 25) & 127;
  int stage_v_461_2 = (((stage_v_76_2 * 3) + pub_r001682_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_461_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_461_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_461_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_461_2 * 2)) & 255;
  int stage_v_462_1 = ((pub_r001682_14_1 * 2) + 28) & 63;
  int stage_v_462_2 = ((pub_r001682_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_462_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_462_2) & 127;
  int stage_v_463_1 = (((stage_v_232_1 * 3) + pub_r001682_7_1) + 27) & 127;
  int stage_v_463_2 = (((stage_v_232_2 * 3) + pub_r001682_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_463_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_463_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_463_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_463_2 * 2)) & 255;
  int stage_v_464_1 = ((pub_r001682_6_1 * 2) + 25) & 63;
  int stage_v_464_2 = ((pub_r001682_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_464_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_464_2) & 127;
  int stage_v_465_1 = ((pub_r001682_12_1 * 2) + 45) & 63;
  int stage_v_465_2 = ((pub_r001682_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_465_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_465_2) & 127;
  int stage_v_466_1 = (((stage_v_122_1 * 3) + pub_r001682_15_1) + 29) & 127;
  int stage_v_466_2 = (((stage_v_122_2 * 3) + pub_r001682_15_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_466_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_466_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_466_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_466_2 * 2)) & 255;
  int stage_v_467_1 = ((pub_r001682_18_1 * 2) + 9) & 63;
  int stage_v_467_2 = ((pub_r001682_18_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_467_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_467_2) & 127;
  int stage_v_468_1 = (((stage_v_395_1 * 3) + pub_r001682_6_1) + 39) & 127;
  int stage_v_468_2 = (((stage_v_395_2 * 3) + pub_r001682_6_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_468_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_468_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_468_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_468_2 * 2)) & 255;
  int stage_v_469_1 = (((stage_v_81_1 * 3) + pub_r001682_19_1) + 41) & 127;
  int stage_v_469_2 = (((stage_v_81_2 * 3) + pub_r001682_19_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_469_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_469_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_469_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_469_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001682_2_1 != sec_r001682_2_2);
  __CPROVER_assume(sec_r001682_15_1 != sec_r001682_15_2);
  __CPROVER_assume(pub_r001682_12_1 == pub_r001682_12_2);
  __CPROVER_assume(sec_r001682_9_1 != sec_r001682_9_2);
  __CPROVER_assume(pub_r001682_9_1 == pub_r001682_9_2);
  __CPROVER_assume(pub_r001682_19_1 == pub_r001682_19_2);
  __CPROVER_assume(sec_r001682_5_1 != sec_r001682_5_2);
  __CPROVER_assume(pub_r001682_18_1 == pub_r001682_18_2);
  __CPROVER_assume(pub_r001682_5_1 == pub_r001682_5_2);
  __CPROVER_assume(sec_r001682_10_1 != sec_r001682_10_2);
  __CPROVER_assume(sec_r001682_13_1 != sec_r001682_13_2);
  __CPROVER_assume(pub_r001682_2_1 == pub_r001682_2_2);
  __CPROVER_assume(pub_r001682_3_1 == pub_r001682_3_2);
  __CPROVER_assume(pub_r001682_0_1 == pub_r001682_0_2);
  __CPROVER_assume(sec_r001682_1_1 != sec_r001682_1_2);
  __CPROVER_assume(pub_r001682_7_1 == pub_r001682_7_2);
  __CPROVER_assume(sec_r001682_3_1 != sec_r001682_3_2);
  __CPROVER_assume(pub_r001682_1_1 == pub_r001682_1_2);
  __CPROVER_assume(sec_r001682_14_1 != sec_r001682_14_2);
  __CPROVER_assume(sec_r001682_16_1 != sec_r001682_16_2);
  __CPROVER_assume(sec_r001682_7_1 != sec_r001682_7_2);
  __CPROVER_assume(pub_r001682_14_1 == pub_r001682_14_2);
  __CPROVER_assume(pub_r001682_13_1 == pub_r001682_13_2);
  __CPROVER_assume(sec_r001682_6_1 != sec_r001682_6_2);
  __CPROVER_assume(pub_r001682_17_1 == pub_r001682_17_2);
  __CPROVER_assume(pub_r001682_10_1 == pub_r001682_10_2);
  __CPROVER_assume(sec_r001682_11_1 != sec_r001682_11_2);
  __CPROVER_assume(pub_r001682_4_1 == pub_r001682_4_2);
  __CPROVER_assume(pub_r001682_8_1 == pub_r001682_8_2);
  __CPROVER_assume(pub_r001682_15_1 == pub_r001682_15_2);
  __CPROVER_assume(sec_r001682_12_1 != sec_r001682_12_2);
  __CPROVER_assume(pub_r001682_6_1 == pub_r001682_6_2);
  __CPROVER_assume(pub_r001682_11_1 == pub_r001682_11_2);
  __CPROVER_assume(sec_r001682_8_1 != sec_r001682_8_2);
  __CPROVER_assume(sec_r001682_0_1 != sec_r001682_0_2);
  __CPROVER_assume(sec_r001682_17_1 != sec_r001682_17_2);
  __CPROVER_assume(sec_r001682_4_1 != sec_r001682_4_2);
  __CPROVER_assume(pub_r001682_16_1 == pub_r001682_16_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  assert(st_var_1_1.flags == st_var_1_2.flags);
  assert(st_var_1_1.tag == st_var_1_2.tag);
  assert(st_var_1_1.iv == st_var_1_2.iv);
  assert(st_var_1_1.counter == st_var_1_2.counter);
  assert(st_var_1_1.nonce == st_var_1_2.nonce);
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

  assert(helper_flow_0_1 == helper_flow_0_2);
  assert(helper_flow_1_1 == helper_flow_1_2);
  assert(helper_flow_2_1 == helper_flow_2_2);
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
}


