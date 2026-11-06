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
struct DeviceConfig_R000027_2713_0
{
  short timeout;
  unsigned char id;
  int parity;
  int buffer[3];
};
struct CipherContext_R000027_2713_1
{
  short round_key;
  int tag;
  unsigned char nonce;
  int buffer[3];
};
struct FilterState_R000027_2713_2
{
  int damping;
  int prev_in;
  int cutoff;
  unsigned char mode;
  int prev_out;
  int buffer[3];
};
struct EventLog_R000027_2713_3
{
  short facility;
  unsigned char timestamp;
  int signature;
  unsigned char code;
  int seq;
  int buffer[3];
};
union RegisterBank_R000027_2713_0
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
void fn_R000027_2713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000027_2713_3 st_1 = {0};
  struct EventLog_R000027_2713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_92_1 = local_arr_1[aux_1 % 3];
  int parity_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_92_2 * 2)) & 127;
  int parity_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_47_1 > 23)
  {
    acc_1 = ((acc_1 + (parity_47_1 * 2)) + 5) & 127;
    aux_1 ^= parity_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_47_2 > 23)
  {
    acc_2 = ((acc_2 + (parity_47_2 * 2)) + 5) & 127;
    aux_2 ^= parity_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_47_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_73_1)
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

  switch (parity_73_2)
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
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_92_1 == parity_92_2);
  assert(parity_47_1 == parity_47_2);
  assert(parity_73_1 == parity_73_2);
}

int fn_R000027_2713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000027_2713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int parity_92 = local_arr[aux % 3];
  acc = (acc + (parity_92 * 2)) & 127;
  int parity_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_47 > 23)
  {
    acc = ((acc + (parity_47 * 2)) + 5) & 127;
    aux ^= parity_47 & 15;
  }
  else
  {
    acc = ((acc - parity_47) + 11) & 127;
    aux += 3;
  }
  int parity_73 = (aux + st.buffer[1]) & 3;
  switch (parity_73)
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

void fn_R000027_2713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000027_2713_0 st_1 = {0};
  struct DeviceConfig_R000027_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int factor_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_96_1 > 28)
  {
    acc_1 = ((acc_1 + (factor_96_1 * 2)) + 5) & 127;
    aux_1 ^= factor_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_96_2 > 28)
  {
    acc_2 = ((acc_2 + (factor_96_2 * 2)) + 5) & 127;
    aux_2 ^= factor_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_96_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_18_1 = local_arr_1[aux_1 % 3];
  int quotient_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_18_2 * 2)) & 127;
  int damping_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_96_1) & 63;
  aux_2 = (aux_2 + damping_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_96_1 == factor_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_18_1 == quotient_18_2);
  assert(damping_96_1 == damping_96_2);
}

int fn_R000027_2713_1(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000027_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int factor_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_96 > 28)
  {
    acc = ((acc + (factor_96 * 2)) + 5) & 127;
    aux ^= factor_96 & 15;
  }
  else
  {
    acc = ((acc - factor_96) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quotient_18 = local_arr[aux % 3];
  acc = (acc + (quotient_18 * 2)) & 127;
  int damping_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000027_2713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000027_2713_3 st_1 = {0};
  struct EventLog_R000027_2713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_42_1)
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

  switch (sample_42_2)
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
  int coefficient_78_1 = local_arr_1[aux_1 % 3];
  int coefficient_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_78_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_42_1 == sample_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_78_1 == coefficient_78_2);
}

int fn_R000027_2713_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000027_2713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_42 = (aux + st.buffer[1]) & 3;
  switch (sample_42)
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
  int coefficient_78 = local_arr[aux % 3];
  acc = (acc + (coefficient_78 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000027_2713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000027_2713_1 st_1 = {0};
  struct CipherContext_R000027_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_65_1)
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

  switch (threshold_65_2)
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
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_65_1 == threshold_65_2);
}

int fn_R000027_2713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000027_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_65 = (aux + st.buffer[1]) & 3;
  switch (threshold_65)
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

void fn_R000027_2713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000027_2713_0 st_1 = {0};
  struct DeviceConfig_R000027_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int delta_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_63_1) & 63;
  aux_2 = (aux_2 + delta_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_75_1)
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

  switch (threshold_75_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_63_1 == delta_63_2);
  assert(threshold_75_1 == threshold_75_2);
}

int fn_R000027_2713_4(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000027_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int delta_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_63) & 63;
  acc ^= aux;
  int threshold_75 = (aux + st.buffer[1]) & 3;
  switch (threshold_75)
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

void fn_R000027_2713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000027_2713_1 st_1 = {0};
  struct CipherContext_R000027_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int accumulator_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_95_1 > 44)
  {
    acc_1 = ((acc_1 + (accumulator_95_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_95_2 > 44)
  {
    acc_2 = ((acc_2 + (accumulator_95_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_92_1 = local_arr_1[aux_1 % 3];
  int accumulator_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_92_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_95_1 == accumulator_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_92_1 == accumulator_92_2);
}

int fn_R000027_2713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000027_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int accumulator_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_95 > 44)
  {
    acc = ((acc + (accumulator_95 * 2)) + 5) & 127;
    aux ^= accumulator_95 & 15;
  }
  else
  {
    acc = ((acc - accumulator_95) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_92 = local_arr[aux % 3];
  acc = (acc + (accumulator_92 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000027_2713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000027_2713_0 st_1 = {0};
  struct DeviceConfig_R000027_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_36_1 > 14)
  {
    acc_1 = ((acc_1 + (pivot_36_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_36_2 > 14)
  {
    acc_2 = ((acc_2 + (pivot_36_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_59_1) & 63;
  aux_2 = (aux_2 + tracker_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_36_1 == pivot_36_2);
  assert(tracker_59_1 == tracker_59_2);
}

int fn_R000027_2713_6(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000027_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_36 > 14)
  {
    acc = ((acc + (pivot_36 * 2)) + 5) & 127;
    aux ^= pivot_36 & 15;
  }
  else
  {
    acc = ((acc - pivot_36) + 11) & 127;
    aux += 3;
  }
  int tracker_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_59) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000027_2713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000027_2713_2 st_1 = {0};
  struct FilterState_R000027_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int phase_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_75_1 > 10)
  {
    acc_1 = ((acc_1 + (phase_75_1 * 2)) + 5) & 127;
    aux_1 ^= phase_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_75_2 > 10)
  {
    acc_2 = ((acc_2 + (phase_75_2 * 2)) + 5) & 127;
    aux_2 ^= phase_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_72_1) & 63;
  aux_2 = (aux_2 + mask_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_75_1)
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

  switch (tally_75_2)
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
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_75_1 == phase_75_2);
  assert(mask_72_1 == mask_72_2);
  assert(tally_75_1 == tally_75_2);
}

int fn_R000027_2713_7(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000027_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int phase_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_75 > 10)
  {
    acc = ((acc + (phase_75 * 2)) + 5) & 127;
    aux ^= phase_75 & 15;
  }
  else
  {
    acc = ((acc - phase_75) + 11) & 127;
    aux += 3;
  }
  int mask_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_72) & 63;
  acc ^= aux;
  int tally_75 = (aux + st.buffer[1]) & 3;
  switch (tally_75)
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

void fn_R000027_2713_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000027_2713_2 st_1 = {0};
  struct FilterState_R000027_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int tracker_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_46_1) & 63;
  aux_2 = (aux_2 + tracker_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_49_1)
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

  switch (anchor_49_2)
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
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_46_1 == tracker_46_2);
  assert(anchor_49_1 == anchor_49_2);
}

int fn_R000027_2713_8(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000027_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int tracker_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_46) & 63;
  acc ^= aux;
  int anchor_49 = (aux + st.buffer[1]) & 3;
  switch (anchor_49)
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

void fn_R000027_2713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000027_2713_0 st_1 = {0};
  struct DeviceConfig_R000027_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_10_1 = local_arr_1[aux_1 % 3];
  int bound_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_10_2 * 2)) & 127;
  int phase_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_81_1) & 63;
  aux_2 = (aux_2 + phase_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_87_1 > 20)
  {
    acc_1 = ((acc_1 + (tracker_87_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_87_2 > 20)
  {
    acc_2 = ((acc_2 + (tracker_87_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_87_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_10_1 == bound_10_2);
  assert(phase_81_1 == phase_81_2);
  assert(tracker_87_1 == tracker_87_2);
}

int fn_R000027_2713_9(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000027_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int bound_10 = local_arr[aux % 3];
  acc = (acc + (bound_10 * 2)) & 127;
  int phase_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_81) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_87 > 20)
  {
    acc = ((acc + (tracker_87 * 2)) + 5) & 127;
    aux ^= tracker_87 & 15;
  }
  else
  {
    acc = ((acc - tracker_87) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000027_2713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000027_2713_2 st_1 = {0};
  struct FilterState_R000027_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_99_1 > 21)
  {
    acc_1 = ((acc_1 + (damping_99_1 * 2)) + 5) & 127;
    aux_1 ^= damping_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_99_2 > 21)
  {
    acc_2 = ((acc_2 + (damping_99_2 * 2)) + 5) & 127;
    aux_2 ^= damping_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_99_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_99_1 == damping_99_2);
}

int fn_R000027_2713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000027_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_99 > 21)
  {
    acc = ((acc + (damping_99 * 2)) + 5) & 127;
    aux ^= damping_99 & 15;
  }
  else
  {
    acc = ((acc - damping_99) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000027_2713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000027_2713_3 st_1 = {0};
  struct EventLog_R000027_2713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int parity_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_58_1)
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

  switch (parity_58_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_72_1 = local_arr_1[aux_1 % 3];
  int delta_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_72_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_58_1 == parity_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_72_1 == delta_72_2);
}

int fn_R000027_2713_11(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000027_2713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int parity_58 = (aux + st.buffer[1]) & 3;
  switch (parity_58)
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

  int local_arr[3] = {4, 9, 15};
  int delta_72 = local_arr[aux % 3];
  acc = (acc + (delta_72 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000027_2713_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000027_2713_1 st_1 = {0};
  struct CipherContext_R000027_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int vector_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_66_1 > 23)
  {
    acc_1 = ((acc_1 + (vector_66_1 * 2)) + 5) & 127;
    aux_1 ^= vector_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_66_2 > 23)
  {
    acc_2 = ((acc_2 + (vector_66_2 * 2)) + 5) & 127;
    aux_2 ^= vector_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_66_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_91_1) & 63;
  aux_2 = (aux_2 + window_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_22_1 = local_arr_1[aux_1 % 3];
  int vector_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_22_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_66_1 == vector_66_2);
  assert(window_91_1 == window_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_22_1 == vector_22_2);
}

int fn_R000027_2713_12(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000027_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int vector_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_66 > 23)
  {
    acc = ((acc + (vector_66 * 2)) + 5) & 127;
    aux ^= vector_66 & 15;
  }
  else
  {
    acc = ((acc - vector_66) + 11) & 127;
    aux += 3;
  }
  int window_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_91) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int vector_22 = local_arr[aux % 3];
  acc = (acc + (vector_22 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000027_2713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000027_2713_3 st_1 = {0};
  struct EventLog_R000027_2713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_75_1 = local_arr_1[aux_1 % 3];
  int sample_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_75_2 * 2)) & 127;
  int threshold_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_45_1) & 63;
  aux_2 = (aux_2 + threshold_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_80_1)
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

  switch (delta_80_2)
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
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_75_1 == sample_75_2);
  assert(threshold_45_1 == threshold_45_2);
  assert(delta_80_1 == delta_80_2);
}

int fn_R000027_2713_13(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000027_2713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int sample_75 = local_arr[aux % 3];
  acc = (acc + (sample_75 * 2)) & 127;
  int threshold_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_45) & 63;
  acc ^= aux;
  int delta_80 = (aux + st.buffer[1]) & 3;
  switch (delta_80)
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

void fn_R000027_2713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000027_2713_1 st_1 = {0};
  struct CipherContext_R000027_2713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int index_reg_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_61_1)
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

  switch (index_reg_61_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_77_1 = local_arr_1[aux_1 % 3];
  int segment_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_77_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_61_1 == index_reg_61_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_77_1 == segment_77_2);
}

int fn_R000027_2713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000027_2713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int index_reg_61 = (aux + st.buffer[1]) & 3;
  switch (index_reg_61)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int segment_77 = local_arr[aux % 3];
  acc = (acc + (segment_77 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000027_2713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000027_2713_3 st_1 = {0};
  struct EventLog_R000027_2713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int delta_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_54_1 > 30)
  {
    acc_1 = ((acc_1 + (delta_54_1 * 2)) + 5) & 127;
    aux_1 ^= delta_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_54_2 > 30)
  {
    acc_2 = ((acc_2 + (delta_54_2 * 2)) + 5) & 127;
    aux_2 ^= delta_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_44_1) & 63;
  aux_2 = (aux_2 + threshold_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_54_1 == delta_54_2);
  assert(threshold_44_1 == threshold_44_2);
}

int fn_R000027_2713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000027_2713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int delta_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_54 > 30)
  {
    acc = ((acc + (delta_54 * 2)) + 5) & 127;
    aux ^= delta_54 & 15;
  }
  else
  {
    acc = ((acc - delta_54) + 11) & 127;
    aux += 3;
  }
  int threshold_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_44) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000027_2713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000027_2713_0 st_1 = {0};
  struct DeviceConfig_R000027_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int bound_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_33_1 > 18)
  {
    acc_1 = ((acc_1 + (bound_33_1 * 2)) + 5) & 127;
    aux_1 ^= bound_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_33_2 > 18)
  {
    acc_2 = ((acc_2 + (bound_33_2 * 2)) + 5) & 127;
    aux_2 ^= bound_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_89_1)
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

  switch (checksum_89_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_33_1 == bound_33_2);
  assert(checksum_89_1 == checksum_89_2);
}

int fn_R000027_2713_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000027_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int bound_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_33 > 18)
  {
    acc = ((acc + (bound_33 * 2)) + 5) & 127;
    aux ^= bound_33 & 15;
  }
  else
  {
    acc = ((acc - bound_33) + 11) & 127;
    aux += 3;
  }
  int checksum_89 = (aux + st.buffer[1]) & 3;
  switch (checksum_89)
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

void fn_R000027_2713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000027_2713_2 st_1 = {0};
  struct FilterState_R000027_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int damping_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_91_1 > 12)
  {
    acc_1 = ((acc_1 + (damping_91_1 * 2)) + 5) & 127;
    aux_1 ^= damping_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_91_2 > 12)
  {
    acc_2 = ((acc_2 + (damping_91_2 * 2)) + 5) & 127;
    aux_2 ^= damping_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_42_1)
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

  switch (window_42_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_74_1 = local_arr_1[aux_1 % 3];
  int residue_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_74_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_91_1 == damping_91_2);
  assert(window_42_1 == window_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_74_1 == residue_74_2);
}

int fn_R000027_2713_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000027_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int damping_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_91 > 12)
  {
    acc = ((acc + (damping_91 * 2)) + 5) & 127;
    aux ^= damping_91 & 15;
  }
  else
  {
    acc = ((acc - damping_91) + 11) & 127;
    aux += 3;
  }
  int window_42 = (aux + st.buffer[1]) & 3;
  switch (window_42)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int residue_74 = local_arr[aux % 3];
  acc = (acc + (residue_74 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000027_2713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000027_2713_0 st_1 = {0};
  struct DeviceConfig_R000027_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int vector_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_73_1)
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

  switch (vector_73_2)
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
  int quantum_50_1 = local_arr_1[aux_1 % 3];
  int quantum_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_50_2 * 2)) & 127;
  int offset_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_97_1) & 63;
  aux_2 = (aux_2 + offset_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_73_1 == vector_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_50_1 == quantum_50_2);
  assert(offset_97_1 == offset_97_2);
}

int fn_R000027_2713_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000027_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int vector_73 = (aux + st.buffer[1]) & 3;
  switch (vector_73)
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
  int quantum_50 = local_arr[aux % 3];
  acc = (acc + (quantum_50 * 2)) & 127;
  int offset_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000027_2713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000027_2713_0 st_1 = {0};
  struct DeviceConfig_R000027_2713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int scale_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_14_1) & 63;
  aux_2 = (aux_2 + scale_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_89_1)
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

  switch (coefficient_89_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_14_1 == scale_14_2);
  assert(coefficient_89_1 == coefficient_89_2);
}

int fn_R000027_2713_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000027_2713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int scale_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_14) & 63;
  acc ^= aux;
  int coefficient_89 = (aux + st.buffer[1]) & 3;
  switch (coefficient_89)
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

void fn_R000027_2713_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000027_2713_2 st_1 = {0};
  struct FilterState_R000027_2713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int window_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_71_1 > 14)
  {
    acc_1 = ((acc_1 + (window_71_1 * 2)) + 5) & 127;
    aux_1 ^= window_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_71_2 > 14)
  {
    acc_2 = ((acc_2 + (window_71_2 * 2)) + 5) & 127;
    aux_2 ^= window_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_66_1)
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

  switch (threshold_66_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_56_1 = local_arr_1[aux_1 % 3];
  int coefficient_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_56_2 * 2)) & 127;
  int cursor_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_51_1) & 63;
  aux_2 = (aux_2 + cursor_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_71_1 == window_71_2);
  assert(threshold_66_1 == threshold_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_56_1 == coefficient_56_2);
  assert(cursor_51_1 == cursor_51_2);
}

int fn_R000027_2713_20(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000027_2713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int window_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_71 > 14)
  {
    acc = ((acc + (window_71 * 2)) + 5) & 127;
    aux ^= window_71 & 15;
  }
  else
  {
    acc = ((acc - window_71) + 11) & 127;
    aux += 3;
  }
  int threshold_66 = (aux + st.buffer[1]) & 3;
  switch (threshold_66)
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

  int local_arr[3] = {4, 9, 15};
  int coefficient_56 = local_arr[aux % 3];
  acc = (acc + (coefficient_56 * 2)) & 127;
  int cursor_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_51) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000027_0_1;
  int sec_r000027_0_2;
  int sec_r000027_1_1;
  int sec_r000027_1_2;
  int sec_r000027_2_1;
  int sec_r000027_2_2;
  int sec_r000027_3_1;
  int sec_r000027_3_2;
  int sec_r000027_4_1;
  int sec_r000027_4_2;
  int sec_r000027_5_1;
  int sec_r000027_5_2;
  int sec_r000027_6_1;
  int sec_r000027_6_2;
  int sec_r000027_7_1;
  int sec_r000027_7_2;
  int sec_r000027_8_1;
  int sec_r000027_8_2;
  int sec_r000027_9_1;
  int sec_r000027_9_2;
  int sec_r000027_10_1;
  int sec_r000027_10_2;
  int sec_r000027_11_1;
  int sec_r000027_11_2;
  int sec_r000027_12_1;
  int sec_r000027_12_2;
  int sec_r000027_13_1;
  int sec_r000027_13_2;
  int sec_r000027_14_1;
  int sec_r000027_14_2;
  int sec_r000027_15_1;
  int sec_r000027_15_2;
  int sec_r000027_16_1;
  int sec_r000027_16_2;
  int sec_r000027_17_1;
  int sec_r000027_17_2;
  int sec_r000027_18_1;
  int sec_r000027_18_2;
  int sec_r000027_19_1;
  int sec_r000027_19_2;
  int pub_r000027_0_1;
  int pub_r000027_0_2;
  int pub_r000027_1_1;
  int pub_r000027_1_2;
  int pub_r000027_2_1;
  int pub_r000027_2_2;
  int pub_r000027_3_1;
  int pub_r000027_3_2;
  int pub_r000027_4_1;
  int pub_r000027_4_2;
  int pub_r000027_5_1;
  int pub_r000027_5_2;
  int pub_r000027_6_1;
  int pub_r000027_6_2;
  int pub_r000027_7_1;
  int pub_r000027_7_2;
  int pub_r000027_8_1;
  int pub_r000027_8_2;
  int pub_r000027_9_1;
  int pub_r000027_9_2;
  int pub_r000027_10_1;
  int pub_r000027_10_2;
  int pub_r000027_11_1;
  int pub_r000027_11_2;
  int pub_r000027_12_1;
  int pub_r000027_12_2;
  int pub_r000027_13_1;
  int pub_r000027_13_2;
  int pub_r000027_14_1;
  int pub_r000027_14_2;
  int pub_r000027_15_1;
  int pub_r000027_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000027_0_1 >= (-100)) && (pub_r000027_0_1 <= 100));
  __CPROVER_assume((pub_r000027_0_2 >= (-100)) && (pub_r000027_0_2 <= 100));
  __CPROVER_assume((pub_r000027_1_1 >= (-100)) && (pub_r000027_1_1 <= 100));
  __CPROVER_assume((pub_r000027_1_2 >= (-100)) && (pub_r000027_1_2 <= 100));
  __CPROVER_assume((pub_r000027_2_1 >= (-100)) && (pub_r000027_2_1 <= 100));
  __CPROVER_assume((pub_r000027_2_2 >= (-100)) && (pub_r000027_2_2 <= 100));
  __CPROVER_assume((pub_r000027_3_1 >= (-100)) && (pub_r000027_3_1 <= 100));
  __CPROVER_assume((pub_r000027_3_2 >= (-100)) && (pub_r000027_3_2 <= 100));
  __CPROVER_assume((pub_r000027_4_1 >= (-100)) && (pub_r000027_4_1 <= 100));
  __CPROVER_assume((pub_r000027_4_2 >= (-100)) && (pub_r000027_4_2 <= 100));
  __CPROVER_assume((pub_r000027_5_1 >= (-100)) && (pub_r000027_5_1 <= 100));
  __CPROVER_assume((pub_r000027_5_2 >= (-100)) && (pub_r000027_5_2 <= 100));
  __CPROVER_assume((pub_r000027_6_1 >= (-100)) && (pub_r000027_6_1 <= 100));
  __CPROVER_assume((pub_r000027_6_2 >= (-100)) && (pub_r000027_6_2 <= 100));
  __CPROVER_assume((pub_r000027_7_1 >= (-100)) && (pub_r000027_7_1 <= 100));
  __CPROVER_assume((pub_r000027_7_2 >= (-100)) && (pub_r000027_7_2 <= 100));
  __CPROVER_assume((pub_r000027_8_1 >= (-100)) && (pub_r000027_8_1 <= 100));
  __CPROVER_assume((pub_r000027_8_2 >= (-100)) && (pub_r000027_8_2 <= 100));
  __CPROVER_assume((pub_r000027_9_1 >= (-100)) && (pub_r000027_9_1 <= 100));
  __CPROVER_assume((pub_r000027_9_2 >= (-100)) && (pub_r000027_9_2 <= 100));
  __CPROVER_assume((pub_r000027_10_1 >= (-100)) && (pub_r000027_10_1 <= 100));
  __CPROVER_assume((pub_r000027_10_2 >= (-100)) && (pub_r000027_10_2 <= 100));
  __CPROVER_assume((pub_r000027_11_1 >= (-100)) && (pub_r000027_11_1 <= 100));
  __CPROVER_assume((pub_r000027_11_2 >= (-100)) && (pub_r000027_11_2 <= 100));
  __CPROVER_assume((pub_r000027_12_1 >= (-100)) && (pub_r000027_12_1 <= 100));
  __CPROVER_assume((pub_r000027_12_2 >= (-100)) && (pub_r000027_12_2 <= 100));
  __CPROVER_assume((pub_r000027_13_1 >= (-100)) && (pub_r000027_13_1 <= 100));
  __CPROVER_assume((pub_r000027_13_2 >= (-100)) && (pub_r000027_13_2 <= 100));
  __CPROVER_assume((pub_r000027_14_1 >= (-100)) && (pub_r000027_14_1 <= 100));
  __CPROVER_assume((pub_r000027_14_2 >= (-100)) && (pub_r000027_14_2 <= 100));
  __CPROVER_assume((pub_r000027_15_1 >= (-100)) && (pub_r000027_15_1 <= 100));
  __CPROVER_assume((pub_r000027_15_2 >= (-100)) && (pub_r000027_15_2 <= 100));
  __CPROVER_assume((sec_r000027_0_1 >= 0) && (sec_r000027_0_1 <= 255));
  __CPROVER_assume((sec_r000027_0_2 >= 0) && (sec_r000027_0_2 <= 255));
  __CPROVER_assume((sec_r000027_1_1 >= 0) && (sec_r000027_1_1 <= 255));
  __CPROVER_assume((sec_r000027_1_2 >= 0) && (sec_r000027_1_2 <= 255));
  __CPROVER_assume((sec_r000027_2_1 >= 0) && (sec_r000027_2_1 <= 255));
  __CPROVER_assume((sec_r000027_2_2 >= 0) && (sec_r000027_2_2 <= 255));
  __CPROVER_assume((sec_r000027_3_1 >= 0) && (sec_r000027_3_1 <= 255));
  __CPROVER_assume((sec_r000027_3_2 >= 0) && (sec_r000027_3_2 <= 255));
  __CPROVER_assume((sec_r000027_4_1 >= 0) && (sec_r000027_4_1 <= 255));
  __CPROVER_assume((sec_r000027_4_2 >= 0) && (sec_r000027_4_2 <= 255));
  __CPROVER_assume((sec_r000027_5_1 >= 0) && (sec_r000027_5_1 <= 255));
  __CPROVER_assume((sec_r000027_5_2 >= 0) && (sec_r000027_5_2 <= 255));
  __CPROVER_assume((sec_r000027_6_1 >= 0) && (sec_r000027_6_1 <= 255));
  __CPROVER_assume((sec_r000027_6_2 >= 0) && (sec_r000027_6_2 <= 255));
  __CPROVER_assume((sec_r000027_7_1 >= 0) && (sec_r000027_7_1 <= 255));
  __CPROVER_assume((sec_r000027_7_2 >= 0) && (sec_r000027_7_2 <= 255));
  __CPROVER_assume((sec_r000027_8_1 >= 0) && (sec_r000027_8_1 <= 255));
  __CPROVER_assume((sec_r000027_8_2 >= 0) && (sec_r000027_8_2 <= 255));
  __CPROVER_assume((sec_r000027_9_1 >= 0) && (sec_r000027_9_1 <= 255));
  __CPROVER_assume((sec_r000027_9_2 >= 0) && (sec_r000027_9_2 <= 255));
  __CPROVER_assume((sec_r000027_10_1 >= 0) && (sec_r000027_10_1 <= 255));
  __CPROVER_assume((sec_r000027_10_2 >= 0) && (sec_r000027_10_2 <= 255));
  __CPROVER_assume((sec_r000027_11_1 >= 0) && (sec_r000027_11_1 <= 255));
  __CPROVER_assume((sec_r000027_11_2 >= 0) && (sec_r000027_11_2 <= 255));
  __CPROVER_assume((sec_r000027_12_1 >= 0) && (sec_r000027_12_1 <= 255));
  __CPROVER_assume((sec_r000027_12_2 >= 0) && (sec_r000027_12_2 <= 255));
  __CPROVER_assume((sec_r000027_13_1 >= 0) && (sec_r000027_13_1 <= 255));
  __CPROVER_assume((sec_r000027_13_2 >= 0) && (sec_r000027_13_2 <= 255));
  __CPROVER_assume((sec_r000027_14_1 >= 0) && (sec_r000027_14_1 <= 255));
  __CPROVER_assume((sec_r000027_14_2 >= 0) && (sec_r000027_14_2 <= 255));
  __CPROVER_assume((sec_r000027_15_1 >= 0) && (sec_r000027_15_1 <= 255));
  __CPROVER_assume((sec_r000027_15_2 >= 0) && (sec_r000027_15_2 <= 255));
  __CPROVER_assume((sec_r000027_16_1 >= 0) && (sec_r000027_16_1 <= 255));
  __CPROVER_assume((sec_r000027_16_2 >= 0) && (sec_r000027_16_2 <= 255));
  __CPROVER_assume((sec_r000027_17_1 >= 0) && (sec_r000027_17_1 <= 255));
  __CPROVER_assume((sec_r000027_17_2 >= 0) && (sec_r000027_17_2 <= 255));
  __CPROVER_assume((sec_r000027_18_1 >= 0) && (sec_r000027_18_1 <= 255));
  __CPROVER_assume((sec_r000027_18_2 >= 0) && (sec_r000027_18_2 <= 255));
  __CPROVER_assume((sec_r000027_19_1 >= 0) && (sec_r000027_19_1 <= 255));
  __CPROVER_assume((sec_r000027_19_2 >= 0) && (sec_r000027_19_2 <= 255));
  struct DeviceConfig_R000027_2713_0 st_var_0_1 = {0};
  struct DeviceConfig_R000027_2713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000027_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000027_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000027_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000027_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000027_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000027_0_2 + 7) & 15;
  struct CipherContext_R000027_2713_1 st_var_1_1 = {0};
  struct CipherContext_R000027_2713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000027_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000027_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000027_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000027_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000027_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000027_0_2 + 9) & 15;
  struct FilterState_R000027_2713_2 st_var_2_1 = {0};
  struct FilterState_R000027_2713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000027_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000027_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000027_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000027_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000027_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000027_0_2 + 11) & 15;
  struct EventLog_R000027_2713_3 st_var_3_1 = {0};
  struct EventLog_R000027_2713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000027_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000027_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000027_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000027_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000027_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000027_0_2 + 13) & 15;
  union RegisterBank_R000027_2713_0 u_var_1;
  union RegisterBank_R000027_2713_0 u_var_2;
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
  int stage_v_1_1 = 0;
  int stage_v_1_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_1_1 = ((stage_v_1_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_1_2 = ((stage_v_1_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 5) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = (st_var_1_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_1_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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

  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = 0;
  int stage_v_7_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_7_1 = ((stage_v_7_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_7_2 = ((stage_v_7_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = ((st_var_0_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_0_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 46)
    {
      chk_sum_1 ^= stage_v_8_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_8_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 46)
    {
      chk_sum_2 ^= stage_v_8_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_9_1 = table_1[1];
  int stage_v_9_2 = table_2[1];
  table_1[1] = (table_1[2] + 19) & 63;
  table_2[1] = (table_2[2] + 19) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 11) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
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
  int stage_v_14_1 = ((st_var_2_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_2_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 47)
    {
      chk_sum_1 ^= stage_v_14_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_14_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 47)
    {
      chk_sum_2 ^= stage_v_14_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_15_1 = (st_var_3_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_3_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
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
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
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
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_21_1 = ((stage_v_21_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 23) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 23) & 15;
  int stage_v_22_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_22_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= stage_v_22_1;
  chk_sum_2 ^= stage_v_22_2;
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 25) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 25) & 15;
  int stage_v_24_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_24_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= stage_v_24_1;
  chk_sum_2 ^= stage_v_24_2;
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
  int stage_v_27_1 = (st_var_3_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_3_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
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

  switch (stage_v_27_2)
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

  int stage_v_28_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (33 & 31);
  int stage_v_28_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (33 & 31);
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= (stage_v_28_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_28_2 << 1) & 127;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_29_1 = ((stage_v_29_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_29_2 = ((stage_v_29_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 31) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  int stage_v_31_1 = ((st_var_3_1.buffer[1] * 2) + 100) & 63;
  int stage_v_31_2 = ((st_var_3_2.buffer[1] * 2) + 100) & 63;
  if (stage_v_31_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_31_1) - 5) & 255;
    if (stage_v_31_1 > 29)
    {
      chk_sum_1 ^= stage_v_31_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_31_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_31_2) - 5) & 255;
    if (stage_v_31_2 > 29)
    {
      chk_sum_2 ^= stage_v_31_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_32_1 = ((st_var_0_1.buffer[2] * 2) + 103) & 63;
  int stage_v_32_2 = ((st_var_0_2.buffer[2] * 2) + 103) & 63;
  if (stage_v_32_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_32_1) - 5) & 255;
    if (stage_v_32_1 > 52)
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
  if (stage_v_32_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_32_2) - 5) & 255;
    if (stage_v_32_2 > 52)
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
  int stage_v_33_1 = table_1[1];
  int stage_v_33_2 = table_2[1];
  table_1[1] = (table_1[2] + 67) & 63;
  table_2[1] = (table_2[2] + 67) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 35) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_36_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (41 & 31);
  int stage_v_36_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (41 & 31);
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= (stage_v_36_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_36_2 << 1) & 127;
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 48)
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
  if (stage_v_37_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 48)
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
  int stage_v_38_1 = (st_var_2_1.buffer[0] ^ 41) & 3;
  int stage_v_38_2 = (st_var_2_2.buffer[0] ^ 41) & 3;
  switch (stage_v_38_1)
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

  switch (stage_v_38_2)
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

  int stage_v_39_1 = table_1[3];
  int stage_v_39_2 = table_2[3];
  table_1[3] = (table_1[0] + 79) & 63;
  table_2[3] = (table_2[0] + 79) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 41) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = ((st_var_1_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_1_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 46)
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
  if (stage_v_41_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 46)
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
  int stage_v_42_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_42_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_43_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_43_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_43_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_43_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_45_1 = (st_var_1_1.buffer[0] ^ 48) & 3;
  int stage_v_45_2 = (st_var_1_2.buffer[0] ^ 48) & 3;
  switch (stage_v_45_1)
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

  switch (stage_v_45_2)
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

  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_46_1 = ((stage_v_46_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_46_2 = ((stage_v_46_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = table_1[3];
  int stage_v_47_2 = table_2[3];
  table_1[3] = (table_1[0] + 95) & 63;
  table_2[3] = (table_2[0] + 95) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((st_var_0_1.buffer[0] * 2) + 151) & 63;
  int stage_v_48_2 = ((st_var_0_2.buffer[0] * 2) + 151) & 63;
  if (stage_v_48_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_48_1) - 5) & 255;
    if (stage_v_48_1 > 52)
    {
      chk_sum_1 ^= stage_v_48_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_48_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_48_2) - 5) & 255;
    if (stage_v_48_2 > 52)
    {
      chk_sum_2 ^= stage_v_48_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_49_1 = table_1[1];
  int stage_v_49_2 = table_2[1];
  table_1[1] = (table_1[2] + 99) & 63;
  table_2[1] = (table_2[2] + 99) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_50_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_50_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_50_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_51_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (56 & 31);
  int stage_v_51_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (56 & 31);
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= (stage_v_51_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_51_2 << 1) & 127;
  int stage_v_52_1 = ((st_var_0_1.buffer[1] * 2) + 163) & 63;
  int stage_v_52_2 = ((st_var_0_2.buffer[1] * 2) + 163) & 63;
  if (stage_v_52_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_52_1) - 5) & 255;
    if (stage_v_52_1 > 42)
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
  if (stage_v_52_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_52_2) - 5) & 255;
    if (stage_v_52_2 > 42)
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
  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  int stage_v_54_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (59 & 31);
  int stage_v_54_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (59 & 31);
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= (stage_v_54_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_54_2 << 1) & 127;
  int stage_v_55_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (60 & 31);
  int stage_v_55_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (60 & 31);
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= (stage_v_55_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_55_2 << 1) & 127;
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
  int stage_v_57_1 = ((st_var_1_1.buffer[0] * 2) + 178) & 63;
  int stage_v_57_2 = ((st_var_1_2.buffer[0] * 2) + 178) & 63;
  if (stage_v_57_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_57_1) - 5) & 255;
    if (stage_v_57_1 > 27)
    {
      chk_sum_1 ^= stage_v_57_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_57_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_57_2) - 5) & 255;
    if (stage_v_57_2 > 27)
    {
      chk_sum_2 ^= stage_v_57_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_58_1 = table_1[2];
  int stage_v_58_2 = table_2[2];
  table_1[2] = (table_1[3] + 117) & 63;
  table_2[2] = (table_2[3] + 117) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((st_var_3_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_3_2.buffer[2] * 2) + 184) & 63;
  if (stage_v_59_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 33)
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
  if (stage_v_59_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 33)
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
  int stage_v_60_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_60_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_60_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_60_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_61_1 = ((stage_v_61_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_61_2 = ((stage_v_61_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (67 & 31);
  int stage_v_62_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (67 & 31);
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= (stage_v_62_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_62_2 << 1) & 127;
  int stage_v_63_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (68 & 31);
  int stage_v_63_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (68 & 31);
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= (stage_v_63_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_63_2 << 1) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 65) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 65) & 15;
  int stage_v_64_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_64_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= stage_v_64_1;
  chk_sum_2 ^= stage_v_64_2;
  int stage_v_65_1 = table_1[1];
  int stage_v_65_2 = table_2[1];
  table_1[1] = (table_1[2] + 131) & 63;
  table_2[1] = (table_2[2] + 131) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (71 & 31);
  int stage_v_66_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (71 & 31);
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= (stage_v_66_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_66_2 << 1) & 127;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_67_1 = ((stage_v_67_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_67_2 = ((stage_v_67_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = table_1[0];
  int stage_v_68_2 = table_2[0];
  table_1[0] = (table_1[1] + 137) & 63;
  table_2[0] = (table_2[1] + 137) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (st_var_1_1.buffer[0] ^ 72) & 3;
  int stage_v_69_2 = (st_var_1_2.buffer[0] ^ 72) & 3;
  switch (stage_v_69_1)
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

  switch (stage_v_69_2)
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

  int stage_v_70_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_70_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_70_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_70_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 72) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 72) & 15;
  int stage_v_71_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_71_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= stage_v_71_1;
  chk_sum_2 ^= stage_v_71_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 73) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 73) & 15;
  int stage_v_72_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_72_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  chk_sum_1 ^= stage_v_72_1;
  chk_sum_2 ^= stage_v_72_2;
  int stage_v_73_1 = (st_var_1_1.buffer[0] ^ 76) & 3;
  int stage_v_73_2 = (st_var_1_2.buffer[0] ^ 76) & 3;
  switch (stage_v_73_1)
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

  switch (stage_v_73_2)
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

  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_74_1 = ((stage_v_74_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_74_2 = ((stage_v_74_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = table_1[3];
  int stage_v_75_2 = table_2[3];
  table_1[3] = (table_1[0] + 151) & 63;
  table_2[3] = (table_2[0] + 151) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
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
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((sec_r000027_5_1 & 1) != 0)
  {
    if ((sec_r000027_19_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000027_2_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000027_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000027_2_1 + 7) & 127;
  }
  if ((sec_r000027_5_2 & 1) != 0)
  {
    if ((sec_r000027_19_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000027_2_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000027_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000027_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000027_12_1 & 1) != 0)
  {
    if ((sec_r000027_0_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000027_13_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000027_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000027_13_1 + 7) & 127;
  }
  if ((sec_r000027_12_2 & 1) != 0)
  {
    if ((sec_r000027_0_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000027_13_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000027_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000027_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000027_18_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000027_5_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000027_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000027_5_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000027_18_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000027_5_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000027_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000027_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000027_11_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000027_1_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000027_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000027_1_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000027_11_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000027_1_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000027_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000027_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((sec_r000027_5_1 & 1) != 0)
  {
    if ((sec_r000027_6_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000027_5_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000027_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000027_5_1 + 7) & 127;
  }
  if ((sec_r000027_5_2 & 1) != 0)
  {
    if ((sec_r000027_6_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000027_5_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000027_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000027_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000027_10_1 & 1) != 0)
  {
    if ((sec_r000027_8_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000027_2_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000027_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000027_2_1 + 7) & 127;
  }
  if ((sec_r000027_10_2 & 1) != 0)
  {
    if ((sec_r000027_8_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000027_2_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000027_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000027_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000027_19_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000027_4_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000027_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000027_4_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000027_19_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000027_4_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000027_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000027_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000027_17_1 & 1) != 0)
  {
    if ((sec_r000027_17_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000027_10_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000027_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000027_10_1 + 7) & 127;
  }
  if ((sec_r000027_17_2 & 1) != 0)
  {
    if ((sec_r000027_17_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000027_10_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000027_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000027_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000027_12_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000027_9_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000027_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000027_9_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000027_12_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000027_9_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000027_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000027_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000027_10_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000027_10_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000027_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000027_10_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000027_10_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000027_10_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000027_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000027_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((sec_r000027_6_1 & 1) != 0)
  {
    if ((sec_r000027_14_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000027_7_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000027_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000027_7_1 + 7) & 127;
  }
  if ((sec_r000027_6_2 & 1) != 0)
  {
    if ((sec_r000027_14_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000027_7_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000027_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000027_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000027_13_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000027_3_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000027_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000027_3_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000027_13_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000027_3_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000027_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000027_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000027_3_1 & 1) != 0)
  {
    if ((sec_r000027_16_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000027_12_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000027_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000027_12_1 + 7) & 127;
  }
  if ((sec_r000027_3_2 & 1) != 0)
  {
    if ((sec_r000027_16_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000027_12_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000027_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000027_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000027_19_1 & 1) != 0)
  {
    if ((sec_r000027_15_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000027_3_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000027_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000027_3_1 + 7) & 127;
  }
  if ((sec_r000027_19_2 & 1) != 0)
  {
    if ((sec_r000027_15_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000027_3_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000027_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000027_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000027_8_1 & 1) != 0)
  {
    if ((sec_r000027_16_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000027_15_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000027_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000027_15_1 + 7) & 127;
  }
  if ((sec_r000027_8_2 & 1) != 0)
  {
    if ((sec_r000027_16_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000027_15_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000027_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000027_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000027_19_1 & 1) != 0)
  {
    if ((sec_r000027_4_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000027_1_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000027_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000027_1_1 + 7) & 127;
  }
  if ((sec_r000027_19_2 & 1) != 0)
  {
    if ((sec_r000027_4_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000027_1_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000027_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000027_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000027_18_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000027_2_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000027_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000027_2_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000027_18_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000027_2_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000027_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000027_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000027_16_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000027_10_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000027_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000027_10_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000027_16_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000027_10_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000027_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000027_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000027_16_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000027_14_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000027_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000027_14_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000027_16_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000027_14_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000027_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000027_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000027_3_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000027_4_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000027_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000027_4_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000027_3_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000027_4_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000027_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000027_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000027_16_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000027_0_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000027_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000027_0_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000027_16_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000027_0_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000027_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000027_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000027_4_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000027_15_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000027_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000027_15_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000027_4_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000027_15_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000027_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000027_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000027_16_1 & 1) != 0)
  {
    if ((sec_r000027_1_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000027_15_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000027_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000027_15_1 + 7) & 127;
  }
  if ((sec_r000027_16_2 & 1) != 0)
  {
    if ((sec_r000027_1_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000027_15_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000027_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000027_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000027_15_1 & 1) != 0)
  {
    if ((sec_r000027_8_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000027_11_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000027_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000027_11_1 + 7) & 127;
  }
  if ((sec_r000027_15_2 & 1) != 0)
  {
    if ((sec_r000027_8_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000027_11_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000027_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000027_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000027_9_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000027_14_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000027_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000027_14_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000027_9_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000027_14_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000027_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000027_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000027_1_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000027_12_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000027_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000027_12_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000027_1_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000027_12_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000027_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000027_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000027_8_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000027_6_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000027_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000027_6_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000027_8_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000027_6_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000027_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000027_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000027_19_1 & 1) != 0)
  {
    if ((sec_r000027_13_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000027_2_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000027_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000027_2_1 + 7) & 127;
  }
  if ((sec_r000027_19_2 & 1) != 0)
  {
    if ((sec_r000027_13_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000027_2_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000027_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000027_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000027_12_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000027_13_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000027_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000027_13_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000027_12_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000027_13_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000027_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000027_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000027_8_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000027_8_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000027_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000027_8_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000027_8_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000027_8_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000027_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000027_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000027_0_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000027_10_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000027_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000027_10_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000027_0_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000027_10_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000027_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000027_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000027_18_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000027_4_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000027_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000027_4_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000027_18_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000027_4_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000027_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000027_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000027_0_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000027_15_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000027_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000027_15_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000027_0_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000027_15_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000027_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000027_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000027_6_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000027_13_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000027_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000027_13_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000027_6_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000027_13_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000027_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000027_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000027_6_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000027_12_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000027_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000027_12_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000027_6_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000027_12_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000027_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000027_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000027_14_1 & 1) != 0)
  {
    if ((sec_r000027_13_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000027_8_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000027_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000027_8_1 + 7) & 127;
  }
  if ((sec_r000027_14_2 & 1) != 0)
  {
    if ((sec_r000027_13_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000027_8_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000027_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000027_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000027_3_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000027_9_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000027_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000027_9_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000027_3_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000027_9_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000027_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000027_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000027_12_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000027_12_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000027_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000027_12_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000027_12_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000027_12_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000027_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000027_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000027_18_1 & 1) != 0)
  {
    if ((sec_r000027_14_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000027_10_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000027_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000027_10_1 + 7) & 127;
  }
  if ((sec_r000027_18_2 & 1) != 0)
  {
    if ((sec_r000027_14_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000027_10_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000027_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000027_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000027_3_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000027_9_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000027_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000027_9_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000027_3_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000027_9_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000027_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000027_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000027_7_1 & 1) != 0)
  {
    if ((sec_r000027_3_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000027_11_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000027_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000027_11_1 + 7) & 127;
  }
  if ((sec_r000027_7_2 & 1) != 0)
  {
    if ((sec_r000027_3_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000027_11_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000027_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000027_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000027_1_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000027_6_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000027_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000027_6_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000027_1_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000027_6_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000027_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000027_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000027_2_1 & 1) != 0)
  {
    if ((sec_r000027_14_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000027_8_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000027_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000027_8_1 + 7) & 127;
  }
  if ((sec_r000027_2_2 & 1) != 0)
  {
    if ((sec_r000027_14_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000027_8_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000027_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000027_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000027_7_1 & 1) != 0)
  {
    if ((sec_r000027_7_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000027_4_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000027_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000027_4_1 + 7) & 127;
  }
  if ((sec_r000027_7_2 & 1) != 0)
  {
    if ((sec_r000027_7_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000027_4_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000027_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000027_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000027_16_1 & 1) != 0)
  {
    if ((sec_r000027_3_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000027_2_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000027_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000027_2_1 + 7) & 127;
  }
  if ((sec_r000027_16_2 & 1) != 0)
  {
    if ((sec_r000027_3_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000027_2_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000027_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000027_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000027_5_1 & 1) != 0)
  {
    if ((sec_r000027_16_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000027_12_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000027_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000027_12_1 + 7) & 127;
  }
  if ((sec_r000027_5_2 & 1) != 0)
  {
    if ((sec_r000027_16_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000027_12_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000027_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000027_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000027_7_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000027_10_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000027_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000027_10_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000027_7_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000027_10_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000027_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000027_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000027_13_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000027_3_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000027_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000027_3_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000027_13_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000027_3_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000027_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000027_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((sec_r000027_4_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000027_15_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000027_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000027_15_1 + 7) & 127;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((sec_r000027_4_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000027_15_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000027_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000027_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((sec_r000027_3_1 & 1) != 0)
  {
    if ((sec_r000027_17_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000027_5_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000027_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000027_5_1 + 7) & 127;
  }
  if ((sec_r000027_3_2 & 1) != 0)
  {
    if ((sec_r000027_17_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000027_5_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000027_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000027_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((sec_r000027_7_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000027_4_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000027_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000027_4_1 + 7) & 127;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((sec_r000027_7_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000027_4_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000027_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000027_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000027_15_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000027_9_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000027_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000027_9_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000027_15_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000027_9_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000027_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000027_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000027_7_1 & 1) != 0)
  {
    if ((sec_r000027_4_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000027_5_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000027_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000027_5_1 + 7) & 127;
  }
  if ((sec_r000027_7_2 & 1) != 0)
  {
    if ((sec_r000027_4_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000027_5_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000027_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000027_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_127_1 & 1) != 0)
  {
    if ((sec_r000027_11_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000027_10_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000027_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000027_10_1 + 7) & 127;
  }
  if ((stage_v_127_2 & 1) != 0)
  {
    if ((sec_r000027_11_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000027_10_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000027_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000027_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000027_9_1 & 1) != 0)
  {
    if ((sec_r000027_14_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000027_3_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000027_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000027_3_1 + 7) & 127;
  }
  if ((sec_r000027_9_2 & 1) != 0)
  {
    if ((sec_r000027_14_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000027_3_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000027_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000027_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((sec_r000027_6_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000027_4_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000027_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000027_4_1 + 7) & 127;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((sec_r000027_6_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000027_4_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000027_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000027_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000027_11_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000027_3_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000027_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000027_3_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000027_11_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000027_3_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000027_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000027_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000027_13_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000027_7_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000027_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000027_7_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000027_13_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000027_7_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000027_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000027_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r000027_16_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000027_14_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000027_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000027_14_1 + 7) & 127;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((sec_r000027_16_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000027_14_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000027_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000027_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000027_17_1 & 1) != 0)
  {
    if ((sec_r000027_14_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000027_7_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000027_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000027_7_1 + 7) & 127;
  }
  if ((sec_r000027_17_2 & 1) != 0)
  {
    if ((sec_r000027_14_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000027_7_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000027_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000027_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((sec_r000027_5_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000027_2_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000027_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000027_2_1 + 7) & 127;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((sec_r000027_5_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000027_2_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000027_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000027_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((sec_r000027_11_1 & 1) != 0)
  {
    if ((sec_r000027_2_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000027_1_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000027_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000027_1_1 + 7) & 127;
  }
  if ((sec_r000027_11_2 & 1) != 0)
  {
    if ((sec_r000027_2_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000027_1_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000027_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000027_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000027_5_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000027_5_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000027_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000027_5_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000027_5_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000027_5_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000027_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000027_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((sec_r000027_0_1 & 1) != 0)
  {
    if ((sec_r000027_6_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000027_0_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000027_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000027_0_1 + 7) & 127;
  }
  if ((sec_r000027_0_2 & 1) != 0)
  {
    if ((sec_r000027_6_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000027_0_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000027_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000027_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000027_4_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000027_3_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000027_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000027_3_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000027_4_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000027_3_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000027_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000027_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000027_14_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000027_5_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000027_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000027_5_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000027_14_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000027_5_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000027_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000027_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((sec_r000027_17_1 & 1) != 0)
  {
    if ((sec_r000027_19_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000027_7_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000027_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000027_7_1 + 7) & 127;
  }
  if ((sec_r000027_17_2 & 1) != 0)
  {
    if ((sec_r000027_19_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000027_7_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000027_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000027_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000027_11_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000027_4_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000027_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000027_4_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000027_11_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000027_4_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000027_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000027_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((sec_r000027_7_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000027_7_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000027_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000027_7_1 + 7) & 127;
  }
  if ((stage_v_131_2 & 1) != 0)
  {
    if ((sec_r000027_7_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000027_7_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000027_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000027_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000027_17_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000027_12_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000027_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000027_12_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000027_17_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000027_12_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000027_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000027_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((sec_r000027_11_1 & 1) != 0)
  {
    if ((sec_r000027_18_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000027_7_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000027_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000027_7_1 + 7) & 127;
  }
  if ((sec_r000027_11_2 & 1) != 0)
  {
    if ((sec_r000027_18_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000027_7_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000027_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000027_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((sec_r000027_0_1 & 1) != 0)
  {
    if ((sec_r000027_0_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000027_4_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000027_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000027_4_1 + 7) & 127;
  }
  if ((sec_r000027_0_2 & 1) != 0)
  {
    if ((sec_r000027_0_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000027_4_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000027_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000027_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000027_12_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000027_11_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000027_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000027_11_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000027_12_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000027_11_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000027_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000027_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((sec_r000027_11_1 & 1) != 0)
  {
    if ((sec_r000027_5_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000027_13_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000027_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000027_13_1 + 7) & 127;
  }
  if ((sec_r000027_11_2 & 1) != 0)
  {
    if ((sec_r000027_5_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000027_13_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000027_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000027_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((sec_r000027_17_1 & 1) != 0)
  {
    if ((sec_r000027_3_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000027_5_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000027_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000027_5_1 + 7) & 127;
  }
  if ((sec_r000027_17_2 & 1) != 0)
  {
    if ((sec_r000027_3_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000027_5_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000027_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000027_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((sec_r000027_12_1 & 1) != 0)
  {
    if ((sec_r000027_4_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000027_4_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000027_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000027_4_1 + 7) & 127;
  }
  if ((sec_r000027_12_2 & 1) != 0)
  {
    if ((sec_r000027_4_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000027_4_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000027_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000027_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000027_13_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000027_14_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000027_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000027_14_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000027_13_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000027_14_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000027_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000027_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000027_4_1 == pub_r000027_4_2);
  __CPROVER_assume(sec_r000027_14_1 != sec_r000027_14_2);
  __CPROVER_assume(pub_r000027_3_1 == pub_r000027_3_2);
  __CPROVER_assume(sec_r000027_12_1 != sec_r000027_12_2);
  __CPROVER_assume(sec_r000027_15_1 != sec_r000027_15_2);
  __CPROVER_assume(pub_r000027_8_1 == pub_r000027_8_2);
  __CPROVER_assume(sec_r000027_5_1 != sec_r000027_5_2);
  __CPROVER_assume(pub_r000027_10_1 == pub_r000027_10_2);
  __CPROVER_assume(sec_r000027_10_1 != sec_r000027_10_2);
  __CPROVER_assume(pub_r000027_13_1 == pub_r000027_13_2);
  __CPROVER_assume(pub_r000027_14_1 == pub_r000027_14_2);
  __CPROVER_assume(sec_r000027_4_1 != sec_r000027_4_2);
  __CPROVER_assume(sec_r000027_3_1 != sec_r000027_3_2);
  __CPROVER_assume(pub_r000027_6_1 == pub_r000027_6_2);
  __CPROVER_assume(pub_r000027_1_1 == pub_r000027_1_2);
  __CPROVER_assume(sec_r000027_0_1 != sec_r000027_0_2);
  __CPROVER_assume(sec_r000027_19_1 != sec_r000027_19_2);
  __CPROVER_assume(sec_r000027_1_1 != sec_r000027_1_2);
  __CPROVER_assume(pub_r000027_0_1 == pub_r000027_0_2);
  __CPROVER_assume(sec_r000027_16_1 != sec_r000027_16_2);
  __CPROVER_assume(sec_r000027_9_1 != sec_r000027_9_2);
  __CPROVER_assume(sec_r000027_2_1 != sec_r000027_2_2);
  __CPROVER_assume(pub_r000027_15_1 == pub_r000027_15_2);
  __CPROVER_assume(pub_r000027_11_1 == pub_r000027_11_2);
  __CPROVER_assume(pub_r000027_9_1 == pub_r000027_9_2);
  __CPROVER_assume(sec_r000027_6_1 != sec_r000027_6_2);
  __CPROVER_assume(pub_r000027_12_1 == pub_r000027_12_2);
  __CPROVER_assume(pub_r000027_7_1 == pub_r000027_7_2);
  __CPROVER_assume(sec_r000027_7_1 != sec_r000027_7_2);
  __CPROVER_assume(sec_r000027_11_1 != sec_r000027_11_2);
  __CPROVER_assume(pub_r000027_5_1 == pub_r000027_5_2);
  __CPROVER_assume(sec_r000027_18_1 != sec_r000027_18_2);
  __CPROVER_assume(sec_r000027_13_1 != sec_r000027_13_2);
  __CPROVER_assume(sec_r000027_8_1 != sec_r000027_8_2);
  __CPROVER_assume(sec_r000027_17_1 != sec_r000027_17_2);
  __CPROVER_assume(pub_r000027_2_1 == pub_r000027_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  assert(st_var_1_1.tag == st_var_1_2.tag);
  assert(st_var_1_1.nonce == st_var_1_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.damping == st_var_2_2.damping);
  assert(st_var_2_1.prev_in == st_var_2_2.prev_in);
  assert(st_var_2_1.cutoff == st_var_2_2.cutoff);
  assert(st_var_2_1.mode == st_var_2_2.mode);
  assert(st_var_2_1.prev_out == st_var_2_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.facility == st_var_3_2.facility);
  assert(st_var_3_1.timestamp == st_var_3_2.timestamp);
  assert(st_var_3_1.signature == st_var_3_2.signature);
  assert(st_var_3_1.code == st_var_3_2.code);
  assert(st_var_3_1.seq == st_var_3_2.seq);
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
}


