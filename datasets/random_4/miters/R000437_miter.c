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
struct FilterState_R000437_3713_0
{
  int prev_in;
  unsigned char gain_db;
  unsigned char prev_out;
  int cutoff;
  int buffer[3];
};
struct DeviceConfig_R000437_3713_1
{
  int stop_bits;
  int id;
  int baud_rate;
  int buffer[3];
};
struct CipherContext_R000437_3713_2
{
  unsigned char tag;
  unsigned char iv;
  short nonce;
  int buffer[3];
};
union PacketPayload_R000437_3713_0
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
void fn_R000437_3713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000437_3713_0 st_1 = {0};
  struct FilterState_R000437_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int weight_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_88_1) & 63;
  aux_2 = (aux_2 + weight_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_98_1 = 0;
  int metric_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_98_1 = ((metric_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_98_2 = ((metric_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_98_1) & 127;
    acc_2 = (acc_2 + metric_98_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_88_1 == weight_88_2);
  assert(metric_98_1 == metric_98_2);
}

int fn_R000437_3713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000437_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int weight_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_88) & 63;
  acc ^= aux;
  int metric_98 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_98 = ((metric_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_98) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000437_3713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000437_3713_1 st_1 = {0};
  struct DeviceConfig_R000437_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_22_1 = local_arr_1[aux_1 % 3];
  int checksum_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_22_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_22_1 == checksum_22_2);
}

int fn_R000437_3713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000437_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_22 = local_arr[aux % 3];
  acc = (acc + (checksum_22 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000437_3713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000437_3713_1 st_1 = {0};
  struct DeviceConfig_R000437_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int tally_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_43_1)
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

  switch (tally_43_2)
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

  int sample_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_89_1 > 39)
  {
    acc_1 = ((acc_1 + (sample_89_1 * 2)) + 5) & 127;
    aux_1 ^= sample_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_89_2 > 39)
  {
    acc_2 = ((acc_2 + (sample_89_2 * 2)) + 5) & 127;
    aux_2 ^= sample_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_21_1 = 0;
  int metric_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_21_1 = ((metric_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_21_2 = ((metric_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_21_1) & 127;
    acc_2 = (acc_2 + metric_21_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_43_1 == tally_43_2);
  assert(sample_89_1 == sample_89_2);
  assert(metric_21_1 == metric_21_2);
}

int fn_R000437_3713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000437_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int tally_43 = (aux + st.buffer[1]) & 3;
  switch (tally_43)
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

  int sample_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_89 > 39)
  {
    acc = ((acc + (sample_89 * 2)) + 5) & 127;
    aux ^= sample_89 & 15;
  }
  else
  {
    acc = ((acc - sample_89) + 11) & 127;
    aux += 3;
  }
  int metric_21 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_21 = ((metric_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_21) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000437_3713_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000437_3713_0 st_1 = {0};
  struct FilterState_R000437_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int coefficient_12_1 = 0;
  int coefficient_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_12_1 = ((coefficient_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_12_2 = ((coefficient_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_12_1) & 127;
    acc_2 = (acc_2 + coefficient_12_2) & 127;
  }

  int scale_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_88_1)
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

  switch (scale_88_2)
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
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_12_1 == coefficient_12_2);
  assert(scale_88_1 == scale_88_2);
}

int fn_R000437_3713_3(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000437_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int coefficient_12 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_12 = ((coefficient_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_12) & 127;
  }

  int scale_88 = (aux + st.buffer[1]) & 3;
  switch (scale_88)
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

void fn_R000437_3713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000437_3713_0 st_1 = {0};
  struct FilterState_R000437_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int threshold_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_44_1) & 63;
  aux_2 = (aux_2 + threshold_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_49_1 = local_arr_1[aux_1 % 3];
  int tally_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_49_2 * 2)) & 127;
  int bound_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_39_1)
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

  switch (bound_39_2)
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
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_44_1 == threshold_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_49_1 == tally_49_2);
  assert(bound_39_1 == bound_39_2);
}

int fn_R000437_3713_4(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000437_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int threshold_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_44) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tally_49 = local_arr[aux % 3];
  acc = (acc + (tally_49 * 2)) & 127;
  int bound_39 = (aux + st.buffer[1]) & 3;
  switch (bound_39)
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

void fn_R000437_3713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000437_3713_0 st_1 = {0};
  struct FilterState_R000437_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int stride_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_97_1)
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

  switch (stride_97_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_97_1 == stride_97_2);
}

int fn_R000437_3713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000437_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int stride_97 = (aux + st.buffer[1]) & 3;
  switch (stride_97)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000437_3713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000437_3713_0 st_1 = {0};
  struct FilterState_R000437_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int parity_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_28_1)
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

  switch (parity_28_2)
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

  int cursor_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_62_1 > 35)
  {
    acc_1 = ((acc_1 + (cursor_62_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_62_2 > 35)
  {
    acc_2 = ((acc_2 + (cursor_62_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_62_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_28_1 == parity_28_2);
  assert(cursor_62_1 == cursor_62_2);
}

int fn_R000437_3713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000437_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int parity_28 = (aux + st.buffer[1]) & 3;
  switch (parity_28)
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

  int cursor_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_62 > 35)
  {
    acc = ((acc + (cursor_62 * 2)) + 5) & 127;
    aux ^= cursor_62 & 15;
  }
  else
  {
    acc = ((acc - cursor_62) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000437_3713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000437_3713_1 st_1 = {0};
  struct DeviceConfig_R000437_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int checksum_20_1 = 0;
  int checksum_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_20_1 = ((checksum_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_20_2 = ((checksum_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_20_1) & 127;
    acc_2 = (acc_2 + checksum_20_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_52_1 = local_arr_1[aux_1 % 3];
  int threshold_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_52_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_20_1 == checksum_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_52_1 == threshold_52_2);
}

int fn_R000437_3713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000437_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int checksum_20 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_20 = ((checksum_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_20) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int threshold_52 = local_arr[aux % 3];
  acc = (acc + (threshold_52 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000437_3713_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000437_3713_1 st_1 = {0};
  struct DeviceConfig_R000437_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int accumulator_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_22_1)
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

  switch (accumulator_22_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_40_1) & 63;
  aux_2 = (aux_2 + factor_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_22_1 == accumulator_22_2);
  assert(factor_40_1 == factor_40_2);
}

int fn_R000437_3713_8(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000437_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int accumulator_22 = (aux + st.buffer[1]) & 3;
  switch (accumulator_22)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_40) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000437_3713_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000437_3713_2 st_1 = {0};
  struct CipherContext_R000437_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_25_1 = local_arr_1[aux_1 % 3];
  int metric_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_25_2 * 2)) & 127;
  int offset_17_1 = 0;
  int offset_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_17_1 = ((offset_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_17_2 = ((offset_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_17_1) & 127;
    acc_2 = (acc_2 + offset_17_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_25_1 == metric_25_2);
  assert(offset_17_1 == offset_17_2);
}

int fn_R000437_3713_9(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000437_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int metric_25 = local_arr[aux % 3];
  acc = (acc + (metric_25 * 2)) & 127;
  int offset_17 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_17 = ((offset_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_17) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000437_3713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000437_3713_0 st_1 = {0};
  struct FilterState_R000437_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int bound_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_48_1 > 25)
  {
    acc_1 = ((acc_1 + (bound_48_1 * 2)) + 5) & 127;
    aux_1 ^= bound_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_48_2 > 25)
  {
    acc_2 = ((acc_2 + (bound_48_2 * 2)) + 5) & 127;
    aux_2 ^= bound_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_48_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_36_1 = 0;
  int delta_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_36_1 = ((delta_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_36_2 = ((delta_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_36_1) & 127;
    acc_2 = (acc_2 + delta_36_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_48_1 == bound_48_2);
  assert(delta_36_1 == delta_36_2);
}

int fn_R000437_3713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000437_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int bound_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_48 > 25)
  {
    acc = ((acc + (bound_48 * 2)) + 5) & 127;
    aux ^= bound_48 & 15;
  }
  else
  {
    acc = ((acc - bound_48) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_36 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_36 = ((delta_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_36) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000437_3713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000437_3713_2 st_1 = {0};
  struct CipherContext_R000437_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int threshold_49_1 = 0;
  int threshold_49_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_49_1 = ((threshold_49_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_49_2 = ((threshold_49_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_49_1) & 127;
    acc_2 = (acc_2 + threshold_49_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_40_1 = local_arr_1[aux_1 % 3];
  int offset_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_40_2 * 2)) & 127;
  int coefficient_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_85_1)
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

  switch (coefficient_85_2)
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
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_49_1 == threshold_49_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_40_1 == offset_40_2);
  assert(coefficient_85_1 == coefficient_85_2);
}

int fn_R000437_3713_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000437_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int threshold_49 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_49 = ((threshold_49 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_49) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int offset_40 = local_arr[aux % 3];
  acc = (acc + (offset_40 * 2)) & 127;
  int coefficient_85 = (aux + st.buffer[1]) & 3;
  switch (coefficient_85)
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

void fn_R000437_3713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000437_3713_1 st_1 = {0};
  struct DeviceConfig_R000437_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_94_1 > 38)
  {
    acc_1 = ((acc_1 + (index_reg_94_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_94_2 > 38)
  {
    acc_2 = ((acc_2 + (index_reg_94_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_92_1)
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

  switch (mask_92_2)
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

  int bound_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_98_1) & 63;
  aux_2 = (aux_2 + bound_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_94_1 == index_reg_94_2);
  assert(mask_92_1 == mask_92_2);
  assert(bound_98_1 == bound_98_2);
}

int fn_R000437_3713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000437_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_94 > 38)
  {
    acc = ((acc + (index_reg_94 * 2)) + 5) & 127;
    aux ^= index_reg_94 & 15;
  }
  else
  {
    acc = ((acc - index_reg_94) + 11) & 127;
    aux += 3;
  }
  int mask_92 = (aux + st.buffer[1]) & 3;
  switch (mask_92)
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

  int bound_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_98) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000437_3713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000437_3713_2 st_1 = {0};
  struct CipherContext_R000437_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_24_1) & 63;
  aux_2 = (aux_2 + mask_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_32_1 = local_arr_1[aux_1 % 3];
  int scale_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_24_1 == mask_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_32_1 == scale_32_2);
}

int fn_R000437_3713_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000437_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_24) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_32 = local_arr[aux % 3];
  acc = (acc + (scale_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000437_3713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000437_3713_2 st_1 = {0};
  struct CipherContext_R000437_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int threshold_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_38_1)
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

  switch (threshold_38_2)
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

  int margin_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_49_1) & 63;
  aux_2 = (aux_2 + margin_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_58_1 > 36)
  {
    acc_1 = ((acc_1 + (damping_58_1 * 2)) + 5) & 127;
    aux_1 ^= damping_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_58_2 > 36)
  {
    acc_2 = ((acc_2 + (damping_58_2 * 2)) + 5) & 127;
    aux_2 ^= damping_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_38_1 == threshold_38_2);
  assert(margin_49_1 == margin_49_2);
  assert(damping_58_1 == damping_58_2);
}

int fn_R000437_3713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000437_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int threshold_38 = (aux + st.buffer[1]) & 3;
  switch (threshold_38)
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

  int margin_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_49) & 63;
  acc ^= aux;
  int damping_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_58 > 36)
  {
    acc = ((acc + (damping_58 * 2)) + 5) & 127;
    aux ^= damping_58 & 15;
  }
  else
  {
    acc = ((acc - damping_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000437_3713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000437_3713_2 st_1 = {0};
  struct CipherContext_R000437_3713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int accumulator_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_14_1) & 63;
  aux_2 = (aux_2 + accumulator_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_86_1 = 0;
  int factor_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_86_1 = ((factor_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_86_2 = ((factor_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_86_1) & 127;
    acc_2 = (acc_2 + factor_86_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_83_1)
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

  switch (accumulator_83_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_14_1 == accumulator_14_2);
  assert(factor_86_1 == factor_86_2);
  assert(accumulator_83_1 == accumulator_83_2);
}

int fn_R000437_3713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000437_3713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int accumulator_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_14) & 63;
  acc ^= aux;
  int factor_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_86 = ((factor_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_86) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_83 = (aux + st.buffer[1]) & 3;
  switch (accumulator_83)
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

void fn_R000437_3713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000437_3713_0 st_1 = {0};
  struct FilterState_R000437_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_59_1 = local_arr_1[aux_1 % 3];
  int checksum_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_59_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_75_1 > 50)
  {
    acc_1 = ((acc_1 + (mask_75_1 * 2)) + 5) & 127;
    aux_1 ^= mask_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_75_2 > 50)
  {
    acc_2 = ((acc_2 + (mask_75_2 * 2)) + 5) & 127;
    aux_2 ^= mask_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_75_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_59_1 == checksum_59_2);
  assert(mask_75_1 == mask_75_2);
}

int fn_R000437_3713_16(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000437_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int checksum_59 = local_arr[aux % 3];
  acc = (acc + (checksum_59 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_75 > 50)
  {
    acc = ((acc + (mask_75 * 2)) + 5) & 127;
    aux ^= mask_75 & 15;
  }
  else
  {
    acc = ((acc - mask_75) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000437_3713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000437_3713_1 st_1 = {0};
  struct DeviceConfig_R000437_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_57_1 = local_arr_1[aux_1 % 3];
  int quotient_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_57_2 * 2)) & 127;
  int index_reg_93_1 = 0;
  int index_reg_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_93_1 = ((index_reg_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_93_2 = ((index_reg_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_93_1) & 127;
    acc_2 = (acc_2 + index_reg_93_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_57_1 == quotient_57_2);
  assert(index_reg_93_1 == index_reg_93_2);
}

int fn_R000437_3713_17(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000437_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int quotient_57 = local_arr[aux % 3];
  acc = (acc + (quotient_57 * 2)) & 127;
  int index_reg_93 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_93 = ((index_reg_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_93) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000437_3713_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000437_3713_1 st_1 = {0};
  struct DeviceConfig_R000437_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int accumulator_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_82_1 > 37)
  {
    acc_1 = ((acc_1 + (accumulator_82_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_82_2 > 37)
  {
    acc_2 = ((acc_2 + (accumulator_82_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_82_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_31_1 = local_arr_1[aux_1 % 3];
  int accumulator_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_31_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_51_1) & 63;
  aux_2 = (aux_2 + checksum_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_82_1 == accumulator_82_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_31_1 == accumulator_31_2);
  assert(checksum_51_1 == checksum_51_2);
}

int fn_R000437_3713_18(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000437_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int accumulator_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_82 > 37)
  {
    acc = ((acc + (accumulator_82 * 2)) + 5) & 127;
    aux ^= accumulator_82 & 15;
  }
  else
  {
    acc = ((acc - accumulator_82) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_31 = local_arr[aux % 3];
  acc = (acc + (accumulator_31 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_51) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000437_3713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000437_3713_0 st_1 = {0};
  struct FilterState_R000437_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int anchor_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_32_1) & 63;
  aux_2 = (aux_2 + anchor_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_43_1)
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

  switch (anchor_43_2)
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
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_32_1 == anchor_32_2);
  assert(anchor_43_1 == anchor_43_2);
}

int fn_R000437_3713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000437_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int anchor_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_32) & 63;
  acc ^= aux;
  int anchor_43 = (aux + st.buffer[1]) & 3;
  switch (anchor_43)
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

void fn_R000437_3713_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000437_3713_0 st_1 = {0};
  struct FilterState_R000437_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_57_1 = local_arr_1[aux_1 % 3];
  int bound_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_57_2 * 2)) & 127;
  int margin_57_1 = 0;
  int margin_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_57_1 = ((margin_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_57_2 = ((margin_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_57_1) & 127;
    acc_2 = (acc_2 + margin_57_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_57_1 == bound_57_2);
  assert(margin_57_1 == margin_57_2);
}

int fn_R000437_3713_20(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000437_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int bound_57 = local_arr[aux % 3];
  acc = (acc + (bound_57 * 2)) & 127;
  int margin_57 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_57 = ((margin_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_57) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000437_3713_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000437_3713_1 st_1 = {0};
  struct DeviceConfig_R000437_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int vector_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_64_1) & 63;
  aux_2 = (aux_2 + vector_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_70_1 = local_arr_1[aux_1 % 3];
  int vector_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_70_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_64_1 == vector_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_70_1 == vector_70_2);
}

int fn_R000437_3713_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000437_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int vector_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_64) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_70 = local_arr[aux % 3];
  acc = (acc + (vector_70 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000437_0_1;
  int sec_r000437_0_2;
  int sec_r000437_1_1;
  int sec_r000437_1_2;
  int sec_r000437_2_1;
  int sec_r000437_2_2;
  int sec_r000437_3_1;
  int sec_r000437_3_2;
  int sec_r000437_4_1;
  int sec_r000437_4_2;
  int sec_r000437_5_1;
  int sec_r000437_5_2;
  int sec_r000437_6_1;
  int sec_r000437_6_2;
  int sec_r000437_7_1;
  int sec_r000437_7_2;
  int sec_r000437_8_1;
  int sec_r000437_8_2;
  int sec_r000437_9_1;
  int sec_r000437_9_2;
  int sec_r000437_10_1;
  int sec_r000437_10_2;
  int sec_r000437_11_1;
  int sec_r000437_11_2;
  int sec_r000437_12_1;
  int sec_r000437_12_2;
  int sec_r000437_13_1;
  int sec_r000437_13_2;
  int sec_r000437_14_1;
  int sec_r000437_14_2;
  int sec_r000437_15_1;
  int sec_r000437_15_2;
  int sec_r000437_16_1;
  int sec_r000437_16_2;
  int sec_r000437_17_1;
  int sec_r000437_17_2;
  int sec_r000437_18_1;
  int sec_r000437_18_2;
  int sec_r000437_19_1;
  int sec_r000437_19_2;
  int sec_r000437_20_1;
  int sec_r000437_20_2;
  int sec_r000437_21_1;
  int sec_r000437_21_2;
  int pub_r000437_0_1;
  int pub_r000437_0_2;
  int pub_r000437_1_1;
  int pub_r000437_1_2;
  int pub_r000437_2_1;
  int pub_r000437_2_2;
  int pub_r000437_3_1;
  int pub_r000437_3_2;
  int pub_r000437_4_1;
  int pub_r000437_4_2;
  int pub_r000437_5_1;
  int pub_r000437_5_2;
  int pub_r000437_6_1;
  int pub_r000437_6_2;
  int pub_r000437_7_1;
  int pub_r000437_7_2;
  int pub_r000437_8_1;
  int pub_r000437_8_2;
  int pub_r000437_9_1;
  int pub_r000437_9_2;
  int pub_r000437_10_1;
  int pub_r000437_10_2;
  int pub_r000437_11_1;
  int pub_r000437_11_2;
  int pub_r000437_12_1;
  int pub_r000437_12_2;
  int pub_r000437_13_1;
  int pub_r000437_13_2;
  int pub_r000437_14_1;
  int pub_r000437_14_2;
  int pub_r000437_15_1;
  int pub_r000437_15_2;
  int pub_r000437_16_1;
  int pub_r000437_16_2;
  int pub_r000437_17_1;
  int pub_r000437_17_2;
  int pub_r000437_18_1;
  int pub_r000437_18_2;
  int pub_r000437_19_1;
  int pub_r000437_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000437_0_1 >= (-100)) && (pub_r000437_0_1 <= 100));
  __CPROVER_assume((pub_r000437_0_2 >= (-100)) && (pub_r000437_0_2 <= 100));
  __CPROVER_assume((pub_r000437_1_1 >= (-100)) && (pub_r000437_1_1 <= 100));
  __CPROVER_assume((pub_r000437_1_2 >= (-100)) && (pub_r000437_1_2 <= 100));
  __CPROVER_assume((pub_r000437_2_1 >= (-100)) && (pub_r000437_2_1 <= 100));
  __CPROVER_assume((pub_r000437_2_2 >= (-100)) && (pub_r000437_2_2 <= 100));
  __CPROVER_assume((pub_r000437_3_1 >= (-100)) && (pub_r000437_3_1 <= 100));
  __CPROVER_assume((pub_r000437_3_2 >= (-100)) && (pub_r000437_3_2 <= 100));
  __CPROVER_assume((pub_r000437_4_1 >= (-100)) && (pub_r000437_4_1 <= 100));
  __CPROVER_assume((pub_r000437_4_2 >= (-100)) && (pub_r000437_4_2 <= 100));
  __CPROVER_assume((pub_r000437_5_1 >= (-100)) && (pub_r000437_5_1 <= 100));
  __CPROVER_assume((pub_r000437_5_2 >= (-100)) && (pub_r000437_5_2 <= 100));
  __CPROVER_assume((pub_r000437_6_1 >= (-100)) && (pub_r000437_6_1 <= 100));
  __CPROVER_assume((pub_r000437_6_2 >= (-100)) && (pub_r000437_6_2 <= 100));
  __CPROVER_assume((pub_r000437_7_1 >= (-100)) && (pub_r000437_7_1 <= 100));
  __CPROVER_assume((pub_r000437_7_2 >= (-100)) && (pub_r000437_7_2 <= 100));
  __CPROVER_assume((pub_r000437_8_1 >= (-100)) && (pub_r000437_8_1 <= 100));
  __CPROVER_assume((pub_r000437_8_2 >= (-100)) && (pub_r000437_8_2 <= 100));
  __CPROVER_assume((pub_r000437_9_1 >= (-100)) && (pub_r000437_9_1 <= 100));
  __CPROVER_assume((pub_r000437_9_2 >= (-100)) && (pub_r000437_9_2 <= 100));
  __CPROVER_assume((pub_r000437_10_1 >= (-100)) && (pub_r000437_10_1 <= 100));
  __CPROVER_assume((pub_r000437_10_2 >= (-100)) && (pub_r000437_10_2 <= 100));
  __CPROVER_assume((pub_r000437_11_1 >= (-100)) && (pub_r000437_11_1 <= 100));
  __CPROVER_assume((pub_r000437_11_2 >= (-100)) && (pub_r000437_11_2 <= 100));
  __CPROVER_assume((pub_r000437_12_1 >= (-100)) && (pub_r000437_12_1 <= 100));
  __CPROVER_assume((pub_r000437_12_2 >= (-100)) && (pub_r000437_12_2 <= 100));
  __CPROVER_assume((pub_r000437_13_1 >= (-100)) && (pub_r000437_13_1 <= 100));
  __CPROVER_assume((pub_r000437_13_2 >= (-100)) && (pub_r000437_13_2 <= 100));
  __CPROVER_assume((pub_r000437_14_1 >= (-100)) && (pub_r000437_14_1 <= 100));
  __CPROVER_assume((pub_r000437_14_2 >= (-100)) && (pub_r000437_14_2 <= 100));
  __CPROVER_assume((pub_r000437_15_1 >= (-100)) && (pub_r000437_15_1 <= 100));
  __CPROVER_assume((pub_r000437_15_2 >= (-100)) && (pub_r000437_15_2 <= 100));
  __CPROVER_assume((pub_r000437_16_1 >= (-100)) && (pub_r000437_16_1 <= 100));
  __CPROVER_assume((pub_r000437_16_2 >= (-100)) && (pub_r000437_16_2 <= 100));
  __CPROVER_assume((pub_r000437_17_1 >= (-100)) && (pub_r000437_17_1 <= 100));
  __CPROVER_assume((pub_r000437_17_2 >= (-100)) && (pub_r000437_17_2 <= 100));
  __CPROVER_assume((pub_r000437_18_1 >= (-100)) && (pub_r000437_18_1 <= 100));
  __CPROVER_assume((pub_r000437_18_2 >= (-100)) && (pub_r000437_18_2 <= 100));
  __CPROVER_assume((pub_r000437_19_1 >= (-100)) && (pub_r000437_19_1 <= 100));
  __CPROVER_assume((pub_r000437_19_2 >= (-100)) && (pub_r000437_19_2 <= 100));
  __CPROVER_assume((sec_r000437_0_1 >= 0) && (sec_r000437_0_1 <= 255));
  __CPROVER_assume((sec_r000437_0_2 >= 0) && (sec_r000437_0_2 <= 255));
  __CPROVER_assume((sec_r000437_1_1 >= 0) && (sec_r000437_1_1 <= 255));
  __CPROVER_assume((sec_r000437_1_2 >= 0) && (sec_r000437_1_2 <= 255));
  __CPROVER_assume((sec_r000437_2_1 >= 0) && (sec_r000437_2_1 <= 255));
  __CPROVER_assume((sec_r000437_2_2 >= 0) && (sec_r000437_2_2 <= 255));
  __CPROVER_assume((sec_r000437_3_1 >= 0) && (sec_r000437_3_1 <= 255));
  __CPROVER_assume((sec_r000437_3_2 >= 0) && (sec_r000437_3_2 <= 255));
  __CPROVER_assume((sec_r000437_4_1 >= 0) && (sec_r000437_4_1 <= 255));
  __CPROVER_assume((sec_r000437_4_2 >= 0) && (sec_r000437_4_2 <= 255));
  __CPROVER_assume((sec_r000437_5_1 >= 0) && (sec_r000437_5_1 <= 255));
  __CPROVER_assume((sec_r000437_5_2 >= 0) && (sec_r000437_5_2 <= 255));
  __CPROVER_assume((sec_r000437_6_1 >= 0) && (sec_r000437_6_1 <= 255));
  __CPROVER_assume((sec_r000437_6_2 >= 0) && (sec_r000437_6_2 <= 255));
  __CPROVER_assume((sec_r000437_7_1 >= 0) && (sec_r000437_7_1 <= 255));
  __CPROVER_assume((sec_r000437_7_2 >= 0) && (sec_r000437_7_2 <= 255));
  __CPROVER_assume((sec_r000437_8_1 >= 0) && (sec_r000437_8_1 <= 255));
  __CPROVER_assume((sec_r000437_8_2 >= 0) && (sec_r000437_8_2 <= 255));
  __CPROVER_assume((sec_r000437_9_1 >= 0) && (sec_r000437_9_1 <= 255));
  __CPROVER_assume((sec_r000437_9_2 >= 0) && (sec_r000437_9_2 <= 255));
  __CPROVER_assume((sec_r000437_10_1 >= 0) && (sec_r000437_10_1 <= 255));
  __CPROVER_assume((sec_r000437_10_2 >= 0) && (sec_r000437_10_2 <= 255));
  __CPROVER_assume((sec_r000437_11_1 >= 0) && (sec_r000437_11_1 <= 255));
  __CPROVER_assume((sec_r000437_11_2 >= 0) && (sec_r000437_11_2 <= 255));
  __CPROVER_assume((sec_r000437_12_1 >= 0) && (sec_r000437_12_1 <= 255));
  __CPROVER_assume((sec_r000437_12_2 >= 0) && (sec_r000437_12_2 <= 255));
  __CPROVER_assume((sec_r000437_13_1 >= 0) && (sec_r000437_13_1 <= 255));
  __CPROVER_assume((sec_r000437_13_2 >= 0) && (sec_r000437_13_2 <= 255));
  __CPROVER_assume((sec_r000437_14_1 >= 0) && (sec_r000437_14_1 <= 255));
  __CPROVER_assume((sec_r000437_14_2 >= 0) && (sec_r000437_14_2 <= 255));
  __CPROVER_assume((sec_r000437_15_1 >= 0) && (sec_r000437_15_1 <= 255));
  __CPROVER_assume((sec_r000437_15_2 >= 0) && (sec_r000437_15_2 <= 255));
  __CPROVER_assume((sec_r000437_16_1 >= 0) && (sec_r000437_16_1 <= 255));
  __CPROVER_assume((sec_r000437_16_2 >= 0) && (sec_r000437_16_2 <= 255));
  __CPROVER_assume((sec_r000437_17_1 >= 0) && (sec_r000437_17_1 <= 255));
  __CPROVER_assume((sec_r000437_17_2 >= 0) && (sec_r000437_17_2 <= 255));
  __CPROVER_assume((sec_r000437_18_1 >= 0) && (sec_r000437_18_1 <= 255));
  __CPROVER_assume((sec_r000437_18_2 >= 0) && (sec_r000437_18_2 <= 255));
  __CPROVER_assume((sec_r000437_19_1 >= 0) && (sec_r000437_19_1 <= 255));
  __CPROVER_assume((sec_r000437_19_2 >= 0) && (sec_r000437_19_2 <= 255));
  __CPROVER_assume((sec_r000437_20_1 >= 0) && (sec_r000437_20_1 <= 255));
  __CPROVER_assume((sec_r000437_20_2 >= 0) && (sec_r000437_20_2 <= 255));
  __CPROVER_assume((sec_r000437_21_1 >= 0) && (sec_r000437_21_1 <= 255));
  __CPROVER_assume((sec_r000437_21_2 >= 0) && (sec_r000437_21_2 <= 255));
  struct FilterState_R000437_3713_0 st_var_0_1 = {0};
  struct FilterState_R000437_3713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000437_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000437_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000437_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000437_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000437_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000437_0_2 + 7) & 15;
  struct DeviceConfig_R000437_3713_1 st_var_1_1 = {0};
  struct DeviceConfig_R000437_3713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000437_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000437_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000437_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000437_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000437_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000437_0_2 + 9) & 15;
  struct CipherContext_R000437_3713_2 st_var_2_1 = {0};
  struct CipherContext_R000437_3713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000437_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000437_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000437_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000437_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000437_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000437_0_2 + 11) & 15;
  union PacketPayload_R000437_3713_0 u_var_1;
  union PacketPayload_R000437_3713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = table_1[0];
  int stage_v_0_2 = table_2[0];
  table_1[0] = (table_1[1] + 1) & 63;
  table_2[0] = (table_2[1] + 1) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = (st_var_0_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_0_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = 0;
  int stage_v_4_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_4_1 = ((stage_v_4_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_4_2 = ((stage_v_4_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (12 & 31);
  int stage_v_7_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (12 & 31);
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= (stage_v_7_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_7_2 << 1) & 127;
  int stage_v_8_1 = (st_var_2_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_2_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 10) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 11) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (st_var_1_1.buffer[0] ^ 19) & 3;
  int stage_v_16_2 = (st_var_1_2.buffer[0] ^ 19) & 3;
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

  int stage_v_17_1 = ((st_var_2_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_2_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 28)
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
  if (stage_v_17_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 28)
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
  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
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
  int stage_v_21_1 = (st_var_0_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_0_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 24) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = ((st_var_0_1.buffer[0] * 2) + 79) & 63;
  int stage_v_24_2 = ((st_var_0_2.buffer[0] * 2) + 79) & 63;
  if (stage_v_24_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_24_1) - 5) & 255;
    if (stage_v_24_1 > 29)
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
  if (stage_v_24_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_24_2) - 5) & 255;
    if (stage_v_24_2 > 29)
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
  int stage_v_25_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (30 & 31);
  int stage_v_25_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (30 & 31);
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= (stage_v_25_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_25_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 27) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_28_1 = (st_var_1_1.buffer[0] ^ 31) & 3;
  int stage_v_28_2 = (st_var_1_2.buffer[0] ^ 31) & 3;
  switch (stage_v_28_1)
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

  switch (stage_v_28_2)
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

  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_29_1 = ((stage_v_29_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_29_2 = ((stage_v_29_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_30_1 = ((stage_v_30_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  }

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
  int stage_v_32_1 = ((st_var_2_1.buffer[2] * 2) + 103) & 63;
  int stage_v_32_2 = ((st_var_2_2.buffer[2] * 2) + 103) & 63;
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
  int stage_v_34_1 = ((st_var_1_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_1_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 38)
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
  if (stage_v_34_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 38)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 36) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 36) & 15;
  int stage_v_35_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_35_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= stage_v_35_1;
  chk_sum_2 ^= stage_v_35_2;
  int stage_v_36_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_36_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_37_1 = table_1[1];
  int stage_v_37_2 = table_2[1];
  table_1[1] = (table_1[2] + 75) & 63;
  table_2[1] = (table_2[2] + 75) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (st_var_2_1.buffer[0] ^ 41) & 3;
  int stage_v_38_2 = (st_var_2_2.buffer[0] ^ 41) & 3;
  switch (stage_v_38_1)
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

  switch (stage_v_38_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 40) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  int stage_v_40_1 = ((st_var_1_1.buffer[1] * 2) + 127) & 63;
  int stage_v_40_2 = ((st_var_1_2.buffer[1] * 2) + 127) & 63;
  if (stage_v_40_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_40_1) - 5) & 255;
    if (stage_v_40_1 > 34)
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
  if (stage_v_40_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_40_2) - 5) & 255;
    if (stage_v_40_2 > 34)
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
  int stage_v_42_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (47 & 31);
  int stage_v_42_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (47 & 31);
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= (stage_v_42_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_42_2 << 1) & 127;
  int stage_v_43_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_43_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_43_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_43_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_44_1 = ((st_var_2_1.buffer[2] * 2) + 139) & 63;
  int stage_v_44_2 = ((st_var_2_2.buffer[2] * 2) + 139) & 63;
  if (stage_v_44_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_44_1) - 5) & 255;
    if (stage_v_44_1 > 42)
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
  if (stage_v_44_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_44_2) - 5) & 255;
    if (stage_v_44_2 > 42)
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
  int stage_v_45_1 = (st_var_0_1.buffer[0] ^ 48) & 3;
  int stage_v_45_2 = (st_var_0_2.buffer[0] ^ 48) & 3;
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

  int stage_v_46_1 = table_1[2];
  int stage_v_46_2 = table_2[2];
  table_1[2] = (table_1[3] + 93) & 63;
  table_2[2] = (table_2[3] + 93) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_47_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_47_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_47_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  int stage_v_49_1 = (st_var_1_1.buffer[0] ^ 52) & 3;
  int stage_v_49_2 = (st_var_1_2.buffer[0] ^ 52) & 3;
  switch (stage_v_49_1)
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

  switch (stage_v_49_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 51) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 51) & 15;
  int stage_v_50_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_50_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= stage_v_50_1;
  chk_sum_2 ^= stage_v_50_2;
  int stage_v_51_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_51_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_51_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_51_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_52_1 = table_1[0];
  int stage_v_52_2 = table_2[0];
  table_1[0] = (table_1[1] + 105) & 63;
  table_2[0] = (table_2[1] + 105) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  }

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
  int stage_v_55_1 = ((st_var_1_1.buffer[1] * 2) + 172) & 63;
  int stage_v_55_2 = ((st_var_1_2.buffer[1] * 2) + 172) & 63;
  if (stage_v_55_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_55_1) - 5) & 255;
    if (stage_v_55_1 > 42)
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
  if (stage_v_55_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_55_2) - 5) & 255;
    if (stage_v_55_2 > 42)
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
  int stage_v_56_1 = (st_var_2_1.buffer[0] ^ 59) & 3;
  int stage_v_56_2 = (st_var_2_2.buffer[0] ^ 59) & 3;
  switch (stage_v_56_1)
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

  switch (stage_v_56_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 58) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 58) & 15;
  int stage_v_57_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_57_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= stage_v_57_1;
  chk_sum_2 ^= stage_v_57_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 59) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 59) & 15;
  int stage_v_58_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_58_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= stage_v_58_1;
  chk_sum_2 ^= stage_v_58_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 60) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 60) & 15;
  int stage_v_59_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_59_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= stage_v_59_1;
  chk_sum_2 ^= stage_v_59_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 61) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 61) & 15;
  int stage_v_60_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_60_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= stage_v_60_1;
  chk_sum_2 ^= stage_v_60_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 62) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 62) & 15;
  int stage_v_61_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_61_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= stage_v_61_1;
  chk_sum_2 ^= stage_v_61_2;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_62_1 = ((stage_v_62_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_62_2 = ((stage_v_62_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (68 & 31);
  int stage_v_63_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (68 & 31);
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= (stage_v_63_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_63_2 << 1) & 127;
  int stage_v_64_1 = (st_var_1_1.buffer[0] ^ 67) & 3;
  int stage_v_64_2 = (st_var_1_2.buffer[0] ^ 67) & 3;
  switch (stage_v_64_1)
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

  switch (stage_v_64_2)
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

  int stage_v_65_1 = (st_var_2_1.buffer[0] ^ 68) & 3;
  int stage_v_65_2 = (st_var_2_2.buffer[0] ^ 68) & 3;
  switch (stage_v_65_1)
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

  switch (stage_v_65_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 67) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 67) & 15;
  int stage_v_66_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_66_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= stage_v_66_1;
  chk_sum_2 ^= stage_v_66_2;
  int stage_v_67_1 = ((st_var_1_1.buffer[1] * 2) + 208) & 63;
  int stage_v_67_2 = ((st_var_1_2.buffer[1] * 2) + 208) & 63;
  if (stage_v_67_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_67_1) - 5) & 255;
    if (stage_v_67_1 > 26)
    {
      chk_sum_1 ^= stage_v_67_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_67_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_67_2) - 5) & 255;
    if (stage_v_67_2 > 26)
    {
      chk_sum_2 ^= stage_v_67_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_68_1 = (st_var_2_1.buffer[0] ^ 71) & 3;
  int stage_v_68_2 = (st_var_2_2.buffer[0] ^ 71) & 3;
  switch (stage_v_68_1)
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

  switch (stage_v_68_2)
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

  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_69_1 = ((stage_v_69_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_69_2 = ((stage_v_69_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_70_1 = ((stage_v_70_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_70_2 = ((stage_v_70_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (76 & 31);
  int stage_v_71_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (76 & 31);
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= (stage_v_71_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_71_2 << 1) & 127;
  int stage_v_72_1 = ((st_var_0_1.buffer[0] * 2) + 223) & 63;
  int stage_v_72_2 = ((st_var_0_2.buffer[0] * 2) + 223) & 63;
  if (stage_v_72_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_72_1) - 5) & 255;
    if (stage_v_72_1 > 40)
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
  if (stage_v_72_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_72_2) - 5) & 255;
    if (stage_v_72_2 > 40)
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
  int stage_v_73_1 = table_1[1];
  int stage_v_73_2 = table_2[1];
  table_1[1] = (table_1[2] + 147) & 63;
  table_2[1] = (table_2[2] + 147) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_74_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_74_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_74_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_75_1 = ((st_var_0_1.buffer[0] * 2) + 232) & 63;
  int stage_v_75_2 = ((st_var_0_2.buffer[0] * 2) + 232) & 63;
  if (stage_v_75_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_75_1) - 5) & 255;
    if (stage_v_75_1 > 25)
    {
      chk_sum_1 ^= stage_v_75_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_75_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_75_2) - 5) & 255;
    if (stage_v_75_2 > 25)
    {
      chk_sum_2 ^= stage_v_75_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_76_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_76_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_76_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_76_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_77_1 = ((st_var_2_1.buffer[2] * 2) + 238) & 63;
  int stage_v_77_2 = ((st_var_2_2.buffer[2] * 2) + 238) & 63;
  if (stage_v_77_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_77_1) - 5) & 255;
    if (stage_v_77_1 > 46)
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
  if (stage_v_77_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_77_2) - 5) & 255;
    if (stage_v_77_2 > 46)
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
  int stage_v_78_1 = (st_var_0_1.buffer[0] ^ 81) & 3;
  int stage_v_78_2 = (st_var_0_2.buffer[0] ^ 81) & 3;
  switch (stage_v_78_1)
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

  switch (stage_v_78_2)
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

  int stage_v_79_1 = table_1[3];
  int stage_v_79_2 = table_2[3];
  table_1[3] = (table_1[0] + 159) & 63;
  table_2[3] = (table_2[0] + 159) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
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
  int stage_v_81_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (86 & 31);
  int stage_v_81_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (86 & 31);
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  chk_sum_1 ^= (stage_v_81_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_81_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 83) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 83) & 15;
  int stage_v_82_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_82_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  chk_sum_1 ^= stage_v_82_1;
  chk_sum_2 ^= stage_v_82_2;
  int stage_v_83_1 = (st_var_2_1.buffer[0] ^ 86) & 3;
  int stage_v_83_2 = (st_var_2_2.buffer[0] ^ 86) & 3;
  switch (stage_v_83_1)
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

  switch (stage_v_83_2)
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

  int stage_v_84_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_84_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_85_1 = table_1[1];
  int stage_v_85_2 = table_2[1];
  table_1[1] = (table_1[2] + 171) & 63;
  table_2[1] = (table_2[2] + 171) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = table_1[2];
  int stage_v_86_2 = table_2[2];
  table_1[2] = (table_1[3] + 173) & 63;
  table_2[2] = (table_2[3] + 173) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_87_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_87_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_87_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_88_1 = ((st_var_1_1.buffer[1] * 2) + 271) & 63;
  int stage_v_88_2 = ((st_var_1_2.buffer[1] * 2) + 271) & 63;
  if (stage_v_88_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_88_1) - 5) & 255;
    if (stage_v_88_1 > 42)
    {
      chk_sum_1 ^= stage_v_88_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_88_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_88_2) - 5) & 255;
    if (stage_v_88_2 > 42)
    {
      chk_sum_2 ^= stage_v_88_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_89_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (94 & 31);
  int stage_v_89_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (94 & 31);
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  chk_sum_1 ^= (stage_v_89_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_89_2 << 1) & 127;
  int stage_v_90_1 = ((st_var_0_1.buffer[0] * 2) + 277) & 63;
  int stage_v_90_2 = ((st_var_0_2.buffer[0] * 2) + 277) & 63;
  if (stage_v_90_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_90_1) - 5) & 255;
    if (stage_v_90_1 > 42)
    {
      chk_sum_1 ^= stage_v_90_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_90_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_90_2) - 5) & 255;
    if (stage_v_90_2 > 42)
    {
      chk_sum_2 ^= stage_v_90_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 92) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 92) & 15;
  int stage_v_91_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_91_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  chk_sum_1 ^= stage_v_91_1;
  chk_sum_2 ^= stage_v_91_2;
  int stage_v_92_1 = ((st_var_2_1.buffer[2] * 2) + 283) & 63;
  int stage_v_92_2 = ((st_var_2_2.buffer[2] * 2) + 283) & 63;
  if (stage_v_92_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_92_1) - 5) & 255;
    if (stage_v_92_1 > 54)
    {
      chk_sum_1 ^= stage_v_92_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_92_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_92_2) - 5) & 255;
    if (stage_v_92_2 > 54)
    {
      chk_sum_2 ^= stage_v_92_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_93_1 = ((stage_v_93_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_93_2 = ((stage_v_93_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_94_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_94_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_94_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 96) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 96) & 15;
  int stage_v_95_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_95_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  chk_sum_1 ^= stage_v_95_1;
  chk_sum_2 ^= stage_v_95_2;
  int stage_v_96_1 = ((st_var_0_1.buffer[0] * 2) + 295) & 63;
  int stage_v_96_2 = ((st_var_0_2.buffer[0] * 2) + 295) & 63;
  if (stage_v_96_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_96_1) - 5) & 255;
    if (stage_v_96_1 > 44)
    {
      chk_sum_1 ^= stage_v_96_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_96_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_96_2) - 5) & 255;
    if (stage_v_96_2 > 44)
    {
      chk_sum_2 ^= stage_v_96_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_97_1 = ((stage_v_97_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_97_2 = ((stage_v_97_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_98_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_98_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_98_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_99_1 = ((stage_v_99_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_99_2 = ((stage_v_99_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (st_var_1_1.buffer[0] ^ 103) & 3;
  int stage_v_100_2 = (st_var_1_2.buffer[0] ^ 103) & 3;
  switch (stage_v_100_1)
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

  switch (stage_v_100_2)
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

  int stage_v_101_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (106 & 31);
  int stage_v_101_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (106 & 31);
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  chk_sum_1 ^= (stage_v_101_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_101_2 << 1) & 127;
  int stage_v_102_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_102_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_102_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_102_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_103_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (108 & 31);
  int stage_v_103_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (108 & 31);
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  chk_sum_1 ^= (stage_v_103_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_103_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 105) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 105) & 15;
  int stage_v_104_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_104_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  chk_sum_1 ^= stage_v_104_1;
  chk_sum_2 ^= stage_v_104_2;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_105_1 = ((stage_v_105_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_105_2 = ((stage_v_105_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_106_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_106_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_106_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_107_1 = ((stage_v_107_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_107_2 = ((stage_v_107_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (st_var_0_1.buffer[0] ^ 111) & 3;
  int stage_v_108_2 = (st_var_0_2.buffer[0] ^ 111) & 3;
  switch (stage_v_108_1)
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

  switch (stage_v_108_2)
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

  int stage_v_109_1 = ((st_var_1_1.buffer[1] * 2) + 334) & 63;
  int stage_v_109_2 = ((st_var_1_2.buffer[1] * 2) + 334) & 63;
  if (stage_v_109_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_109_1) - 5) & 255;
    if (stage_v_109_1 > 38)
    {
      chk_sum_1 ^= stage_v_109_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_109_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_109_2) - 5) & 255;
    if (stage_v_109_2 > 38)
    {
      chk_sum_2 ^= stage_v_109_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_110_1 = ((stage_v_110_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_110_2 = ((stage_v_110_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (116 & 31);
  int stage_v_111_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (116 & 31);
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  chk_sum_1 ^= (stage_v_111_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_111_2 << 1) & 127;
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
  int stage_v_113_1 = (st_var_2_1.buffer[0] ^ 116) & 3;
  int stage_v_113_2 = (st_var_2_2.buffer[0] ^ 116) & 3;
  switch (stage_v_113_1)
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

  switch (stage_v_113_2)
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

  int stage_v_114_1 = (st_var_0_1.buffer[0] ^ 117) & 3;
  int stage_v_114_2 = (st_var_0_2.buffer[0] ^ 117) & 3;
  switch (stage_v_114_1)
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

  switch (stage_v_114_2)
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

  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_115_1 = ((stage_v_115_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_115_2 = ((stage_v_115_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 117) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 117) & 15;
  int stage_v_116_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_116_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  chk_sum_1 ^= stage_v_116_1;
  chk_sum_2 ^= stage_v_116_2;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_117_1 = ((stage_v_117_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_117_2 = ((stage_v_117_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_118_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_118_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_118_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_119_1 = ((stage_v_119_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_119_2 = ((stage_v_119_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_120_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_120_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_120_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_121_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_121_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_121_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_121_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_122_1 = ((st_var_2_1.buffer[2] * 2) + 373) & 63;
  int stage_v_122_2 = ((st_var_2_2.buffer[2] * 2) + 373) & 63;
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
  int stage_v_124_1 = (st_var_1_1.buffer[0] ^ 127) & 3;
  int stage_v_124_2 = (st_var_1_2.buffer[0] ^ 127) & 3;
  switch (stage_v_124_1)
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

  switch (stage_v_124_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 126) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 126) & 15;
  int stage_v_125_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_125_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  chk_sum_1 ^= stage_v_125_1;
  chk_sum_2 ^= stage_v_125_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 127) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 127) & 15;
  int stage_v_126_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_126_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  chk_sum_1 ^= stage_v_126_1;
  chk_sum_2 ^= stage_v_126_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 128) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 128) & 15;
  int stage_v_127_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_127_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  chk_sum_1 ^= stage_v_127_1;
  chk_sum_2 ^= stage_v_127_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 129) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 129) & 15;
  int stage_v_128_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_128_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  chk_sum_1 ^= stage_v_128_1;
  chk_sum_2 ^= stage_v_128_2;
  int stage_v_129_1 = ((st_var_0_1.buffer[0] * 2) + 394) & 63;
  int stage_v_129_2 = ((st_var_0_2.buffer[0] * 2) + 394) & 63;
  if (stage_v_129_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_129_1) - 5) & 255;
    if (stage_v_129_1 > 34)
    {
      chk_sum_1 ^= stage_v_129_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_129_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_129_2) - 5) & 255;
    if (stage_v_129_2 > 34)
    {
      chk_sum_2 ^= stage_v_129_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_130_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (135 & 31);
  int stage_v_130_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (135 & 31);
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  chk_sum_1 ^= (stage_v_130_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_130_2 << 1) & 127;
  int stage_v_131_1 = (st_var_2_1.buffer[0] ^ 134) & 3;
  int stage_v_131_2 = (st_var_2_2.buffer[0] ^ 134) & 3;
  switch (stage_v_131_1)
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

  switch (stage_v_131_2)
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

  int stage_v_133_1 = table_1[1];
  int stage_v_133_2 = table_2[1];
  table_1[1] = (table_1[2] + 267) & 63;
  table_2[1] = (table_2[2] + 267) & 63;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 135) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 135) & 15;
  int stage_v_134_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_134_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  chk_sum_1 ^= stage_v_134_1;
  chk_sum_2 ^= stage_v_134_2;
  int stage_v_135_1 = ((st_var_0_1.buffer[0] * 2) + 412) & 63;
  int stage_v_135_2 = ((st_var_0_2.buffer[0] * 2) + 412) & 63;
  if (stage_v_135_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_135_1) - 5) & 255;
    if (stage_v_135_1 > 38)
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
  if (stage_v_135_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_135_2) - 5) & 255;
    if (stage_v_135_2 > 38)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 137) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 137) & 15;
  int stage_v_136_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_136_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  chk_sum_1 ^= stage_v_136_1;
  chk_sum_2 ^= stage_v_136_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 138) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 138) & 15;
  int stage_v_137_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_137_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  chk_sum_1 ^= stage_v_137_1;
  chk_sum_2 ^= stage_v_137_2;
  int stage_v_138_1 = (st_var_0_1.buffer[0] ^ 141) & 3;
  int stage_v_138_2 = (st_var_0_2.buffer[0] ^ 141) & 3;
  switch (stage_v_138_1)
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

  switch (stage_v_138_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 140) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 140) & 15;
  int stage_v_139_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_139_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  chk_sum_1 ^= stage_v_139_1;
  chk_sum_2 ^= stage_v_139_2;
  int stage_v_140_1 = (st_var_2_1.buffer[0] ^ 143) & 3;
  int stage_v_140_2 = (st_var_2_2.buffer[0] ^ 143) & 3;
  switch (stage_v_140_1)
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

  switch (stage_v_140_2)
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

  int stage_v_141_1 = ((st_var_0_1.buffer[0] * 2) + 430) & 63;
  int stage_v_141_2 = ((st_var_0_2.buffer[0] * 2) + 430) & 63;
  if (stage_v_141_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_141_1) - 5) & 255;
    if (stage_v_141_1 > 46)
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
  if (stage_v_141_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_141_2) - 5) & 255;
    if (stage_v_141_2 > 46)
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
  int stage_v_142_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (147 & 31);
  int stage_v_142_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (147 & 31);
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  chk_sum_1 ^= (stage_v_142_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_142_2 << 1) & 127;
  int stage_v_143_1 = table_1[3];
  int stage_v_143_2 = table_2[3];
  table_1[3] = (table_1[0] + 287) & 63;
  table_2[3] = (table_2[0] + 287) & 63;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 145) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 145) & 15;
  int stage_v_144_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_144_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  chk_sum_1 ^= stage_v_144_1;
  chk_sum_2 ^= stage_v_144_2;
  int stage_v_145_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_145_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_145_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_145_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_146_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (151 & 31);
  int stage_v_146_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (151 & 31);
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  chk_sum_1 ^= (stage_v_146_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_146_2 << 1) & 127;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_147_1 = ((stage_v_147_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_147_2 = ((stage_v_147_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_148_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_148_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_148_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_149_1 = ((st_var_2_1.buffer[2] * 2) + 454) & 63;
  int stage_v_149_2 = ((st_var_2_2.buffer[2] * 2) + 454) & 63;
  if (stage_v_149_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_149_1) - 5) & 255;
    if (stage_v_149_1 > 53)
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
  if (stage_v_149_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_149_2) - 5) & 255;
    if (stage_v_149_2 > 53)
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
  int stage_v_150_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_150_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_150_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_150_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_151_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_151_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_151_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_151_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_152_1 = ((st_var_2_1.buffer[2] * 2) + 463) & 63;
  int stage_v_152_2 = ((st_var_2_2.buffer[2] * 2) + 463) & 63;
  if (stage_v_152_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_152_1) - 5) & 255;
    if (stage_v_152_1 > 29)
    {
      chk_sum_1 ^= stage_v_152_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_152_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_152_2) - 5) & 255;
    if (stage_v_152_2 > 29)
    {
      chk_sum_2 ^= stage_v_152_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_153_1 = (st_var_0_1.buffer[0] ^ 156) & 3;
  int stage_v_153_2 = (st_var_0_2.buffer[0] ^ 156) & 3;
  switch (stage_v_153_1)
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

  switch (stage_v_153_2)
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

  int stage_v_154_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (159 & 31);
  int stage_v_154_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (159 & 31);
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  chk_sum_1 ^= (stage_v_154_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_154_2 << 1) & 127;
  int stage_v_155_1 = (st_var_2_1.buffer[0] ^ 158) & 3;
  int stage_v_155_2 = (st_var_2_2.buffer[0] ^ 158) & 3;
  switch (stage_v_155_1)
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

  switch (stage_v_155_2)
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

  int stage_v_156_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (161 & 31);
  int stage_v_156_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (161 & 31);
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  chk_sum_1 ^= (stage_v_156_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_156_2 << 1) & 127;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_157_1 = ((stage_v_157_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_157_2 = ((stage_v_157_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((st_var_2_1.buffer[2] * 2) + 481) & 63;
  int stage_v_158_2 = ((st_var_2_2.buffer[2] * 2) + 481) & 63;
  if (stage_v_158_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_158_1) - 5) & 255;
    if (stage_v_158_1 > 39)
    {
      chk_sum_1 ^= stage_v_158_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_158_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_158_2) - 5) & 255;
    if (stage_v_158_2 > 39)
    {
      chk_sum_2 ^= stage_v_158_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_159_1 = (st_var_0_1.buffer[0] ^ 162) & 3;
  int stage_v_159_2 = (st_var_0_2.buffer[0] ^ 162) & 3;
  switch (stage_v_159_1)
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

  switch (stage_v_159_2)
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

  int stage_v_160_1 = (st_var_1_1.buffer[0] ^ 163) & 3;
  int stage_v_160_2 = (st_var_1_2.buffer[0] ^ 163) & 3;
  switch (stage_v_160_1)
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

  switch (stage_v_160_2)
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

  int stage_v_161_1 = table_1[1];
  int stage_v_161_2 = table_2[1];
  table_1[1] = (table_1[2] + 323) & 63;
  table_2[1] = (table_2[2] + 323) & 63;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 163) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 163) & 15;
  int stage_v_162_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_162_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  chk_sum_1 ^= stage_v_162_1;
  chk_sum_2 ^= stage_v_162_2;
  int stage_v_163_1 = table_1[3];
  int stage_v_163_2 = table_2[3];
  table_1[3] = (table_1[0] + 327) & 63;
  table_2[3] = (table_2[0] + 327) & 63;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((st_var_2_1.buffer[2] * 2) + 499) & 63;
  int stage_v_164_2 = ((st_var_2_2.buffer[2] * 2) + 499) & 63;
  if (stage_v_164_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_164_1) - 5) & 255;
    if (stage_v_164_1 > 54)
    {
      chk_sum_1 ^= stage_v_164_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_164_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_164_2) - 5) & 255;
    if (stage_v_164_2 > 54)
    {
      chk_sum_2 ^= stage_v_164_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_165_1 = (st_var_0_1.buffer[0] ^ 168) & 3;
  int stage_v_165_2 = (st_var_0_2.buffer[0] ^ 168) & 3;
  switch (stage_v_165_1)
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

  switch (stage_v_165_2)
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

  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_166_1 = ((stage_v_166_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_166_2 = ((stage_v_166_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_167_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_167_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_167_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_168_1 = table_1[0];
  int stage_v_168_2 = table_2[0];
  table_1[0] = (table_1[1] + 337) & 63;
  table_2[0] = (table_2[1] + 337) & 63;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (st_var_1_1.buffer[0] ^ 172) & 3;
  int stage_v_169_2 = (st_var_1_2.buffer[0] ^ 172) & 3;
  switch (stage_v_169_1)
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

  switch (stage_v_169_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 171) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 171) & 15;
  int stage_v_170_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_170_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  chk_sum_1 ^= stage_v_170_1;
  chk_sum_2 ^= stage_v_170_2;
  int stage_v_171_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_171_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_171_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_171_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_172_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_172_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_172_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_172_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_173_1 = 0;
  int stage_v_173_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_173_1 = ((stage_v_173_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_173_2 = ((stage_v_173_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((st_var_0_1.buffer[0] * 2) + 529) & 63;
  int stage_v_174_2 = ((st_var_0_2.buffer[0] * 2) + 529) & 63;
  if (stage_v_174_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_174_1) - 5) & 255;
    if (stage_v_174_1 > 37)
    {
      chk_sum_1 ^= stage_v_174_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_174_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_174_2) - 5) & 255;
    if (stage_v_174_2 > 37)
    {
      chk_sum_2 ^= stage_v_174_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_175_1 = 0;
  int stage_v_175_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_175_1 = ((stage_v_175_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_175_2 = ((stage_v_175_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = 0;
  int stage_v_176_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_176_1 = ((stage_v_176_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_176_2 = ((stage_v_176_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = table_1[1];
  int stage_v_177_2 = table_2[1];
  table_1[1] = (table_1[2] + 355) & 63;
  table_2[1] = (table_2[2] + 355) & 63;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 179) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 179) & 15;
  int stage_v_178_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_178_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  chk_sum_1 ^= stage_v_178_1;
  chk_sum_2 ^= stage_v_178_2;
  int stage_v_179_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (184 & 31);
  int stage_v_179_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (184 & 31);
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  chk_sum_1 ^= (stage_v_179_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_179_2 << 1) & 127;
  int stage_v_180_1 = ((st_var_0_1.buffer[0] * 2) + 547) & 63;
  int stage_v_180_2 = ((st_var_0_2.buffer[0] * 2) + 547) & 63;
  if (stage_v_180_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_180_1) - 5) & 255;
    if (stage_v_180_1 > 29)
    {
      chk_sum_1 ^= stage_v_180_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_180_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_180_2) - 5) & 255;
    if (stage_v_180_2 > 29)
    {
      chk_sum_2 ^= stage_v_180_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_181_1 = ((st_var_1_1.buffer[1] * 2) + 550) & 63;
  int stage_v_181_2 = ((st_var_1_2.buffer[1] * 2) + 550) & 63;
  if (stage_v_181_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_181_1) - 5) & 255;
    if (stage_v_181_1 > 40)
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
  if (stage_v_181_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_181_2) - 5) & 255;
    if (stage_v_181_2 > 40)
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
  int b_w0_1 = (sec_r000437_8_1 ^ 0x5A) & 63;
  int b_w0_2 = (sec_r000437_8_2 ^ 0x5A) & 63;
  int b_w1_1 = ((b_w0_1 << 1) & (sec_r000437_14_1 >> 1)) & 63;
  int b_w1_2 = ((b_w0_2 << 1) & (sec_r000437_14_2 >> 1)) & 63;
  int b_w2_1 = ((b_w1_1 << 2) ^ (sec_r000437_7_1 >> 2)) & 63;
  int b_w2_2 = ((b_w1_2 << 2) ^ (sec_r000437_7_2 >> 2)) & 63;
  int b_w3_1 = ((b_w2_1 << 2) | (sec_r000437_15_1 >> 2)) & 63;
  int b_w3_2 = ((b_w2_2 << 2) | (sec_r000437_15_2 >> 2)) & 63;
  int b_w4_1 = ((b_w3_1 << 2) ^ (sec_r000437_8_1 >> 2)) & 63;
  int b_w4_2 = ((b_w3_2 << 2) ^ (sec_r000437_8_2 >> 2)) & 63;
  int b_w5_1 = ((b_w4_1 << 2) ^ (sec_r000437_14_1 >> 2)) & 63;
  int b_w5_2 = ((b_w4_2 << 2) ^ (sec_r000437_14_2 >> 2)) & 63;
  out_sink_1 += b_w5_1 & 63;
  out_sink_2 += b_w5_2 & 63;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000437_4_1 == pub_r000437_4_2);
  __CPROVER_assume(sec_r000437_10_1 != sec_r000437_10_2);
  __CPROVER_assume(pub_r000437_9_1 == pub_r000437_9_2);
  __CPROVER_assume(pub_r000437_6_1 == pub_r000437_6_2);
  __CPROVER_assume(sec_r000437_6_1 != sec_r000437_6_2);
  __CPROVER_assume(pub_r000437_14_1 == pub_r000437_14_2);
  __CPROVER_assume(sec_r000437_16_1 != sec_r000437_16_2);
  __CPROVER_assume(sec_r000437_20_1 != sec_r000437_20_2);
  __CPROVER_assume(pub_r000437_2_1 == pub_r000437_2_2);
  __CPROVER_assume(sec_r000437_9_1 != sec_r000437_9_2);
  __CPROVER_assume(sec_r000437_3_1 != sec_r000437_3_2);
  __CPROVER_assume(pub_r000437_5_1 == pub_r000437_5_2);
  __CPROVER_assume(sec_r000437_2_1 != sec_r000437_2_2);
  __CPROVER_assume(pub_r000437_11_1 == pub_r000437_11_2);
  __CPROVER_assume(pub_r000437_15_1 == pub_r000437_15_2);
  __CPROVER_assume(sec_r000437_0_1 != sec_r000437_0_2);
  __CPROVER_assume(pub_r000437_0_1 == pub_r000437_0_2);
  __CPROVER_assume(sec_r000437_13_1 != sec_r000437_13_2);
  __CPROVER_assume(pub_r000437_12_1 == pub_r000437_12_2);
  __CPROVER_assume(sec_r000437_17_1 != sec_r000437_17_2);
  __CPROVER_assume(sec_r000437_1_1 != sec_r000437_1_2);
  __CPROVER_assume(sec_r000437_18_1 != sec_r000437_18_2);
  __CPROVER_assume(pub_r000437_13_1 == pub_r000437_13_2);
  __CPROVER_assume(pub_r000437_8_1 == pub_r000437_8_2);
  __CPROVER_assume(sec_r000437_12_1 != sec_r000437_12_2);
  __CPROVER_assume(sec_r000437_5_1 != sec_r000437_5_2);
  __CPROVER_assume(sec_r000437_15_1 != sec_r000437_15_2);
  __CPROVER_assume(sec_r000437_8_1 != sec_r000437_8_2);
  __CPROVER_assume(sec_r000437_7_1 != sec_r000437_7_2);
  __CPROVER_assume(pub_r000437_10_1 == pub_r000437_10_2);
  __CPROVER_assume(pub_r000437_17_1 == pub_r000437_17_2);
  __CPROVER_assume(pub_r000437_18_1 == pub_r000437_18_2);
  __CPROVER_assume(pub_r000437_16_1 == pub_r000437_16_2);
  __CPROVER_assume(sec_r000437_14_1 != sec_r000437_14_2);
  __CPROVER_assume(sec_r000437_19_1 != sec_r000437_19_2);
  __CPROVER_assume(sec_r000437_21_1 != sec_r000437_21_2);
  __CPROVER_assume(pub_r000437_3_1 == pub_r000437_3_2);
  __CPROVER_assume(pub_r000437_19_1 == pub_r000437_19_2);
  __CPROVER_assume(pub_r000437_7_1 == pub_r000437_7_2);
  __CPROVER_assume(sec_r000437_4_1 != sec_r000437_4_2);
  __CPROVER_assume(sec_r000437_11_1 != sec_r000437_11_2);
  __CPROVER_assume(pub_r000437_1_1 == pub_r000437_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.tag == st_var_2_2.tag);
  assert(st_var_2_1.iv == st_var_2_2.iv);
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
  assert(b_w0_1 == b_w0_2);
  assert(b_w1_1 == b_w1_2);
  assert(b_w2_1 == b_w2_2);
  assert(b_w3_1 == b_w3_2);
  assert(b_w4_1 == b_w4_2);
  assert(b_w5_1 == b_w5_2);
}


