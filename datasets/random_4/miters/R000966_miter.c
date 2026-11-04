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
struct CipherContext_R000966_6613_0
{
  int tag;
  int round_key;
  int iv;
  int flags;
  int buffer[3];
};
struct DeviceConfig_R000966_6613_1
{
  int timeout;
  unsigned char id;
  int baud_rate;
  int buffer[3];
};
union PacketPayload_R000966_6613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000966_6613_1
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
void fn_R000966_6613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st_1 = {0};
  struct DeviceConfig_R000966_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int checksum_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_65_1)
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

  switch (checksum_65_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_63_1 = local_arr_1[aux_1 % 3];
  int sample_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_63_2 * 2)) & 127;
  int sample_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_67_1) & 63;
  aux_2 = (aux_2 + sample_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_65_1 == checksum_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_63_1 == sample_63_2);
  assert(sample_67_1 == sample_67_2);
}

int fn_R000966_6613_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int checksum_65 = (aux + st.buffer[1]) & 3;
  switch (checksum_65)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_63 = local_arr[aux % 3];
  acc = (acc + (sample_63 * 2)) & 127;
  int sample_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_67) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000966_6613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st_1 = {0};
  struct CipherContext_R000966_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int quotient_53_1 = 0;
  int quotient_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_53_1 = ((quotient_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_53_2 = ((quotient_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_53_1) & 127;
    acc_2 = (acc_2 + quotient_53_2) & 127;
  }

  int vector_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_94_1 > 47)
  {
    acc_1 = ((acc_1 + (vector_94_1 * 2)) + 5) & 127;
    aux_1 ^= vector_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_94_2 > 47)
  {
    acc_2 = ((acc_2 + (vector_94_2 * 2)) + 5) & 127;
    aux_2 ^= vector_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_94_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_53_1 == quotient_53_2);
  assert(vector_94_1 == vector_94_2);
}

int fn_R000966_6613_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int quotient_53 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_53 = ((quotient_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_53) & 127;
  }

  int vector_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_94 > 47)
  {
    acc = ((acc + (vector_94 * 2)) + 5) & 127;
    aux ^= vector_94 & 15;
  }
  else
  {
    acc = ((acc - vector_94) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000966_6613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st_1 = {0};
  struct CipherContext_R000966_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_20_1 = local_arr_1[aux_1 % 3];
  int factor_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_20_2 * 2)) & 127;
  int scale_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_15_1 > 13)
  {
    acc_1 = ((acc_1 + (scale_15_1 * 2)) + 5) & 127;
    aux_1 ^= scale_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_15_2 > 13)
  {
    acc_2 = ((acc_2 + (scale_15_2 * 2)) + 5) & 127;
    aux_2 ^= scale_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_15_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_20_1)
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

  switch (vector_20_2)
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
  assert(st_1.round_key == st_2.round_key);
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

  assert(factor_20_1 == factor_20_2);
  assert(scale_15_1 == scale_15_2);
  assert(vector_20_1 == vector_20_2);
}

int fn_R000966_6613_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int factor_20 = local_arr[aux % 3];
  acc = (acc + (factor_20 * 2)) & 127;
  int scale_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_15 > 13)
  {
    acc = ((acc + (scale_15 * 2)) + 5) & 127;
    aux ^= scale_15 & 15;
  }
  else
  {
    acc = ((acc - scale_15) + 11) & 127;
    aux += 3;
  }
  int vector_20 = (aux + st.buffer[1]) & 3;
  switch (vector_20)
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

void fn_R000966_6613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st_1 = {0};
  struct DeviceConfig_R000966_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_96_1 = local_arr_1[aux_1 % 3];
  int sample_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_96_2 * 2)) & 127;
  int phase_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_62_1) & 63;
  aux_2 = (aux_2 + phase_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
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

  assert(sample_96_1 == sample_96_2);
  assert(phase_62_1 == phase_62_2);
}

int fn_R000966_6613_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int sample_96 = local_arr[aux % 3];
  acc = (acc + (sample_96 * 2)) & 127;
  int phase_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_62) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000966_6613_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st_1 = {0};
  struct DeviceConfig_R000966_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_82_1) & 63;
  aux_2 = (aux_2 + coefficient_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_72_1 > 38)
  {
    acc_1 = ((acc_1 + (accumulator_72_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_72_2 > 38)
  {
    acc_2 = ((acc_2 + (accumulator_72_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_72_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_82_1 == coefficient_82_2);
  assert(accumulator_72_1 == accumulator_72_2);
}

int fn_R000966_6613_4(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_82) & 63;
  acc ^= aux;
  int accumulator_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_72 > 38)
  {
    acc = ((acc + (accumulator_72 * 2)) + 5) & 127;
    aux ^= accumulator_72 & 15;
  }
  else
  {
    acc = ((acc - accumulator_72) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000966_6613_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st_1 = {0};
  struct CipherContext_R000966_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int stride_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_30_1 > 31)
  {
    acc_1 = ((acc_1 + (stride_30_1 * 2)) + 5) & 127;
    aux_1 ^= stride_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_30_2 > 31)
  {
    acc_2 = ((acc_2 + (stride_30_2 * 2)) + 5) & 127;
    aux_2 ^= stride_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_30_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_88_1)
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

  switch (vector_88_2)
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
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_30_1 == stride_30_2);
  assert(vector_88_1 == vector_88_2);
}

int fn_R000966_6613_5(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int stride_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_30 > 31)
  {
    acc = ((acc + (stride_30 * 2)) + 5) & 127;
    aux ^= stride_30 & 15;
  }
  else
  {
    acc = ((acc - stride_30) + 11) & 127;
    aux += 3;
  }
  int vector_88 = (aux + st.buffer[1]) & 3;
  switch (vector_88)
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

void fn_R000966_6613_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st_1 = {0};
  struct CipherContext_R000966_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int pivot_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_29_1)
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

  switch (pivot_29_2)
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

  int checksum_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_26_1) & 63;
  aux_2 = (aux_2 + checksum_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_89_1 > 28)
  {
    acc_1 = ((acc_1 + (pivot_89_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_89_2 > 28)
  {
    acc_2 = ((acc_2 + (pivot_89_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_89_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_29_1 == pivot_29_2);
  assert(checksum_26_1 == checksum_26_2);
  assert(pivot_89_1 == pivot_89_2);
}

int fn_R000966_6613_6(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int pivot_29 = (aux + st.buffer[1]) & 3;
  switch (pivot_29)
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

  int checksum_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_26) & 63;
  acc ^= aux;
  int pivot_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_89 > 28)
  {
    acc = ((acc + (pivot_89 * 2)) + 5) & 127;
    aux ^= pivot_89 & 15;
  }
  else
  {
    acc = ((acc - pivot_89) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000966_6613_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st_1 = {0};
  struct CipherContext_R000966_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int coefficient_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_18_1 > 45)
  {
    acc_1 = ((acc_1 + (coefficient_18_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_18_2 > 45)
  {
    acc_2 = ((acc_2 + (coefficient_18_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_19_1)
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

  switch (segment_19_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_18_1 == coefficient_18_2);
  assert(segment_19_1 == segment_19_2);
}

int fn_R000966_6613_7(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int coefficient_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_18 > 45)
  {
    acc = ((acc + (coefficient_18 * 2)) + 5) & 127;
    aux ^= coefficient_18 & 15;
  }
  else
  {
    acc = ((acc - coefficient_18) + 11) & 127;
    aux += 3;
  }
  int segment_19 = (aux + st.buffer[1]) & 3;
  switch (segment_19)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000966_6613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st_1 = {0};
  struct DeviceConfig_R000966_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_72_1 = local_arr_1[aux_1 % 3];
  int vector_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_72_2 * 2)) & 127;
  int mask_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_89_1)
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

  switch (mask_89_2)
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

  int index_reg_93_1 = 0;
  int index_reg_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_93_1 = ((index_reg_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_93_2 = ((index_reg_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_93_1) & 127;
    acc_2 = (acc_2 + index_reg_93_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
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

  assert(vector_72_1 == vector_72_2);
  assert(mask_89_1 == mask_89_2);
  assert(index_reg_93_1 == index_reg_93_2);
}

int fn_R000966_6613_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int vector_72 = local_arr[aux % 3];
  acc = (acc + (vector_72 * 2)) & 127;
  int mask_89 = (aux + st.buffer[1]) & 3;
  switch (mask_89)
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

  int index_reg_93 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_93 = ((index_reg_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_93) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000966_6613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st_1 = {0};
  struct DeviceConfig_R000966_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int checksum_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_66_1 > 34)
  {
    acc_1 = ((acc_1 + (checksum_66_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_66_2 > 34)
  {
    acc_2 = ((acc_2 + (checksum_66_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_66_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_29_1 = 0;
  int quantum_29_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_29_1 = ((quantum_29_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_29_2 = ((quantum_29_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_29_1) & 127;
    acc_2 = (acc_2 + quantum_29_2) & 127;
  }

  int phase_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_21_1) & 63;
  aux_2 = (aux_2 + phase_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_66_1 == checksum_66_2);
  assert(quantum_29_1 == quantum_29_2);
  assert(phase_21_1 == phase_21_2);
}

int fn_R000966_6613_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int checksum_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_66 > 34)
  {
    acc = ((acc + (checksum_66 * 2)) + 5) & 127;
    aux ^= checksum_66 & 15;
  }
  else
  {
    acc = ((acc - checksum_66) + 11) & 127;
    aux += 3;
  }
  int quantum_29 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_29 = ((quantum_29 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_29) & 127;
  }

  int phase_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_21) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000966_6613_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st_1 = {0};
  struct DeviceConfig_R000966_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int residue_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_59_1 > 13)
  {
    acc_1 = ((acc_1 + (residue_59_1 * 2)) + 5) & 127;
    aux_1 ^= residue_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_59_2 > 13)
  {
    acc_2 = ((acc_2 + (residue_59_2 * 2)) + 5) & 127;
    aux_2 ^= residue_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_59_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_96_1 = local_arr_1[aux_1 % 3];
  int parity_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_96_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_59_1 == residue_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_96_1 == parity_96_2);
}

int fn_R000966_6613_10(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int residue_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_59 > 13)
  {
    acc = ((acc + (residue_59 * 2)) + 5) & 127;
    aux ^= residue_59 & 15;
  }
  else
  {
    acc = ((acc - residue_59) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_96 = local_arr[aux % 3];
  acc = (acc + (parity_96 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000966_6613_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st_1 = {0};
  struct CipherContext_R000966_6613_0 st_2 = {0};
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
  int threshold_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_35_1)
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

  switch (threshold_35_2)
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

  int pivot_65_1 = 0;
  int pivot_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_65_1 = ((pivot_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_65_2 = ((pivot_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_65_1) & 127;
    acc_2 = (acc_2 + pivot_65_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_35_1 == threshold_35_2);
  assert(pivot_65_1 == pivot_65_2);
}

int fn_R000966_6613_11(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_35 = (aux + st.buffer[1]) & 3;
  switch (threshold_35)
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

  int pivot_65 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_65 = ((pivot_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_65) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000966_6613_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st_1 = {0};
  struct CipherContext_R000966_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int quotient_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_31_1) & 63;
  aux_2 = (aux_2 + quotient_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_76_1 = 0;
  int window_76_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_76_1 = ((window_76_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_76_2 = ((window_76_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_76_1) & 127;
    acc_2 = (acc_2 + window_76_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_31_1 == quotient_31_2);
  assert(window_76_1 == window_76_2);
}

int fn_R000966_6613_12(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int quotient_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_31) & 63;
  acc ^= aux;
  int window_76 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_76 = ((window_76 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_76) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000966_6613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st_1 = {0};
  struct CipherContext_R000966_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int quantum_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_96_1 > 26)
  {
    acc_1 = ((acc_1 + (quantum_96_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_96_2 > 26)
  {
    acc_2 = ((acc_2 + (quantum_96_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_34_1)
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

  switch (checksum_34_2)
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

  int parity_92_1 = 0;
  int parity_92_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_92_1 = ((parity_92_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_92_2 = ((parity_92_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_92_1) & 127;
    acc_2 = (acc_2 + parity_92_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_29_1 = local_arr_1[aux_1 % 3];
  int damping_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_29_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_96_1 == quantum_96_2);
  assert(checksum_34_1 == checksum_34_2);
  assert(parity_92_1 == parity_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_29_1 == damping_29_2);
}

int fn_R000966_6613_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int quantum_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_96 > 26)
  {
    acc = ((acc + (quantum_96 * 2)) + 5) & 127;
    aux ^= quantum_96 & 15;
  }
  else
  {
    acc = ((acc - quantum_96) + 11) & 127;
    aux += 3;
  }
  int checksum_34 = (aux + st.buffer[1]) & 3;
  switch (checksum_34)
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

  int parity_92 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_92 = ((parity_92 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_92) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int damping_29 = local_arr[aux % 3];
  acc = (acc + (damping_29 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000966_6613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st_1 = {0};
  struct DeviceConfig_R000966_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int quotient_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_97_1 > 50)
  {
    acc_1 = ((acc_1 + (quotient_97_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_97_2 > 50)
  {
    acc_2 = ((acc_2 + (quotient_97_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_80_1 = 0;
  int coefficient_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_80_1 = ((coefficient_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_80_2 = ((coefficient_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_80_1) & 127;
    acc_2 = (acc_2 + coefficient_80_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_21_1 = local_arr_1[aux_1 % 3];
  int sample_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_97_1 == quotient_97_2);
  assert(coefficient_80_1 == coefficient_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_21_1 == sample_21_2);
}

int fn_R000966_6613_14(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int quotient_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_97 > 50)
  {
    acc = ((acc + (quotient_97 * 2)) + 5) & 127;
    aux ^= quotient_97 & 15;
  }
  else
  {
    acc = ((acc - quotient_97) + 11) & 127;
    aux += 3;
  }
  int coefficient_80 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_80 = ((coefficient_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_80) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int sample_21 = local_arr[aux % 3];
  acc = (acc + (sample_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000966_6613_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st_1 = {0};
  struct CipherContext_R000966_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int segment_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_35_1)
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

  switch (segment_35_2)
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
  int margin_37_1 = local_arr_1[aux_1 % 3];
  int margin_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_37_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_35_1 == segment_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_37_1 == margin_37_2);
}

int fn_R000966_6613_15(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int segment_35 = (aux + st.buffer[1]) & 3;
  switch (segment_35)
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
  int margin_37 = local_arr[aux % 3];
  acc = (acc + (margin_37 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000966_6613_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st_1 = {0};
  struct CipherContext_R000966_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_26_1 = local_arr_1[aux_1 % 3];
  int tally_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_26_2 * 2)) & 127;
  int margin_87_1 = 0;
  int margin_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_87_1 = ((margin_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_87_2 = ((margin_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_87_1) & 127;
    acc_2 = (acc_2 + margin_87_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
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

  assert(tally_26_1 == tally_26_2);
  assert(margin_87_1 == margin_87_2);
}

int fn_R000966_6613_16(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int tally_26 = local_arr[aux % 3];
  acc = (acc + (tally_26 * 2)) & 127;
  int margin_87 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_87 = ((margin_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_87) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000966_6613_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st_1 = {0};
  struct DeviceConfig_R000966_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int segment_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_54_1 > 31)
  {
    acc_1 = ((acc_1 + (segment_54_1 * 2)) + 5) & 127;
    aux_1 ^= segment_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_54_2 > 31)
  {
    acc_2 = ((acc_2 + (segment_54_2 * 2)) + 5) & 127;
    aux_2 ^= segment_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_52_1 = local_arr_1[aux_1 % 3];
  int delta_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_52_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_54_1 == segment_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_52_1 == delta_52_2);
}

int fn_R000966_6613_17(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int segment_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_54 > 31)
  {
    acc = ((acc + (segment_54 * 2)) + 5) & 127;
    aux ^= segment_54 & 15;
  }
  else
  {
    acc = ((acc - segment_54) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int delta_52 = local_arr[aux % 3];
  acc = (acc + (delta_52 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000966_6613_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st_1 = {0};
  struct DeviceConfig_R000966_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int tracker_70_1 = 0;
  int tracker_70_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_70_1 = ((tracker_70_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_70_2 = ((tracker_70_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_70_1) & 127;
    acc_2 = (acc_2 + tracker_70_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_96_1 = local_arr_1[aux_1 % 3];
  int phase_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_96_2 * 2)) & 127;
  int quantum_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_92_1)
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

  switch (quantum_92_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_70_1 == tracker_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_96_1 == phase_96_2);
  assert(quantum_92_1 == quantum_92_2);
}

int fn_R000966_6613_18(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int tracker_70 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_70 = ((tracker_70 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_70) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_96 = local_arr[aux % 3];
  acc = (acc + (phase_96 * 2)) & 127;
  int quantum_92 = (aux + st.buffer[1]) & 3;
  switch (quantum_92)
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

void fn_R000966_6613_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st_1 = {0};
  struct CipherContext_R000966_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int segment_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_74_1)
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

  switch (segment_74_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_99_1) & 63;
  aux_2 = (aux_2 + segment_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_74_1 == segment_74_2);
  assert(segment_99_1 == segment_99_2);
}

int fn_R000966_6613_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int segment_74 = (aux + st.buffer[1]) & 3;
  switch (segment_74)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000966_6613_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st_1 = {0};
  struct DeviceConfig_R000966_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_17_1 = local_arr_1[aux_1 % 3];
  int cursor_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_17_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
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

  assert(cursor_17_1 == cursor_17_2);
}

int fn_R000966_6613_20(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int cursor_17 = local_arr[aux % 3];
  acc = (acc + (cursor_17 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000966_6613_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st_1 = {0};
  struct DeviceConfig_R000966_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_59_1 = local_arr_1[aux_1 % 3];
  int threshold_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_59_2 * 2)) & 127;
  int stride_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_89_1 > 37)
  {
    acc_1 = ((acc_1 + (stride_89_1 * 2)) + 5) & 127;
    aux_1 ^= stride_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_89_2 > 37)
  {
    acc_2 = ((acc_2 + (stride_89_2 * 2)) + 5) & 127;
    aux_2 ^= stride_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_89_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
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

  assert(threshold_59_1 == threshold_59_2);
  assert(stride_89_1 == stride_89_2);
}

int fn_R000966_6613_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int threshold_59 = local_arr[aux % 3];
  acc = (acc + (threshold_59 * 2)) & 127;
  int stride_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_89 > 37)
  {
    acc = ((acc + (stride_89 * 2)) + 5) & 127;
    aux ^= stride_89 & 15;
  }
  else
  {
    acc = ((acc - stride_89) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000966_6613_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st_1 = {0};
  struct CipherContext_R000966_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int accumulator_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_24_1) & 63;
  aux_2 = (aux_2 + accumulator_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_26_1)
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

  switch (offset_26_2)
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

  int sample_64_1 = 0;
  int sample_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_64_1 = ((sample_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_64_2 = ((sample_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_64_1) & 127;
    acc_2 = (acc_2 + sample_64_2) & 127;
  }

  int residue_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_99_1 > 25)
  {
    acc_1 = ((acc_1 + (residue_99_1 * 2)) + 5) & 127;
    aux_1 ^= residue_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_99_2 > 25)
  {
    acc_2 = ((acc_2 + (residue_99_2 * 2)) + 5) & 127;
    aux_2 ^= residue_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_99_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_24_1 == accumulator_24_2);
  assert(offset_26_1 == offset_26_2);
  assert(sample_64_1 == sample_64_2);
  assert(residue_99_1 == residue_99_2);
}

int fn_R000966_6613_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int accumulator_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_24) & 63;
  acc ^= aux;
  int offset_26 = (aux + st.buffer[1]) & 3;
  switch (offset_26)
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

  int sample_64 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_64 = ((sample_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_64) & 127;
  }

  int residue_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_99 > 25)
  {
    acc = ((acc + (residue_99 * 2)) + 5) & 127;
    aux ^= residue_99 & 15;
  }
  else
  {
    acc = ((acc - residue_99) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000966_6613_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st_1 = {0};
  struct DeviceConfig_R000966_6613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_77_1 = local_arr_1[aux_1 % 3];
  int cursor_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_77_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_66_1) & 63;
  aux_2 = (aux_2 + quantum_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
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

  assert(cursor_77_1 == cursor_77_2);
  assert(quantum_66_1 == quantum_66_2);
}

int fn_R000966_6613_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000966_6613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int cursor_77 = local_arr[aux % 3];
  acc = (acc + (cursor_77 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_66) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000966_6613_24_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st_1 = {0};
  struct CipherContext_R000966_6613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int weight_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_14_1 > 15)
  {
    acc_1 = ((acc_1 + (weight_14_1 * 2)) + 5) & 127;
    aux_1 ^= weight_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_14_2 > 15)
  {
    acc_2 = ((acc_2 + (weight_14_2 * 2)) + 5) & 127;
    aux_2 ^= weight_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_65_1)
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

  switch (stride_65_2)
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

  int residue_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_68_1) & 63;
  aux_2 = (aux_2 + residue_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_14_1 == weight_14_2);
  assert(stride_65_1 == stride_65_2);
  assert(residue_68_1 == residue_68_2);
}

int fn_R000966_6613_24(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000966_6613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int weight_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_14 > 15)
  {
    acc = ((acc + (weight_14 * 2)) + 5) & 127;
    aux ^= weight_14 & 15;
  }
  else
  {
    acc = ((acc - weight_14) + 11) & 127;
    aux += 3;
  }
  int stride_65 = (aux + st.buffer[1]) & 3;
  switch (stride_65)
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

  int residue_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_68) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000966_0_1;
  int sec_r000966_0_2;
  int sec_r000966_1_1;
  int sec_r000966_1_2;
  int sec_r000966_2_1;
  int sec_r000966_2_2;
  int sec_r000966_3_1;
  int sec_r000966_3_2;
  int sec_r000966_4_1;
  int sec_r000966_4_2;
  int sec_r000966_5_1;
  int sec_r000966_5_2;
  int sec_r000966_6_1;
  int sec_r000966_6_2;
  int sec_r000966_7_1;
  int sec_r000966_7_2;
  int sec_r000966_8_1;
  int sec_r000966_8_2;
  int sec_r000966_9_1;
  int sec_r000966_9_2;
  int sec_r000966_10_1;
  int sec_r000966_10_2;
  int sec_r000966_11_1;
  int sec_r000966_11_2;
  int sec_r000966_12_1;
  int sec_r000966_12_2;
  int sec_r000966_13_1;
  int sec_r000966_13_2;
  int sec_r000966_14_1;
  int sec_r000966_14_2;
  int sec_r000966_15_1;
  int sec_r000966_15_2;
  int pub_r000966_0_1;
  int pub_r000966_0_2;
  int pub_r000966_1_1;
  int pub_r000966_1_2;
  int pub_r000966_2_1;
  int pub_r000966_2_2;
  int pub_r000966_3_1;
  int pub_r000966_3_2;
  int pub_r000966_4_1;
  int pub_r000966_4_2;
  int pub_r000966_5_1;
  int pub_r000966_5_2;
  int pub_r000966_6_1;
  int pub_r000966_6_2;
  int pub_r000966_7_1;
  int pub_r000966_7_2;
  int pub_r000966_8_1;
  int pub_r000966_8_2;
  int pub_r000966_9_1;
  int pub_r000966_9_2;
  int pub_r000966_10_1;
  int pub_r000966_10_2;
  int pub_r000966_11_1;
  int pub_r000966_11_2;
  int pub_r000966_12_1;
  int pub_r000966_12_2;
  int pub_r000966_13_1;
  int pub_r000966_13_2;
  int pub_r000966_14_1;
  int pub_r000966_14_2;
  int pub_r000966_15_1;
  int pub_r000966_15_2;
  int pub_r000966_16_1;
  int pub_r000966_16_2;
  int pub_r000966_17_1;
  int pub_r000966_17_2;
  int pub_r000966_18_1;
  int pub_r000966_18_2;
  int pub_r000966_19_1;
  int pub_r000966_19_2;
  int pub_r000966_20_1;
  int pub_r000966_20_2;
  int pub_r000966_21_1;
  int pub_r000966_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000966_0_1 >= (-100)) && (pub_r000966_0_1 <= 100));
  __CPROVER_assume((pub_r000966_0_2 >= (-100)) && (pub_r000966_0_2 <= 100));
  __CPROVER_assume((pub_r000966_1_1 >= (-100)) && (pub_r000966_1_1 <= 100));
  __CPROVER_assume((pub_r000966_1_2 >= (-100)) && (pub_r000966_1_2 <= 100));
  __CPROVER_assume((pub_r000966_2_1 >= (-100)) && (pub_r000966_2_1 <= 100));
  __CPROVER_assume((pub_r000966_2_2 >= (-100)) && (pub_r000966_2_2 <= 100));
  __CPROVER_assume((pub_r000966_3_1 >= (-100)) && (pub_r000966_3_1 <= 100));
  __CPROVER_assume((pub_r000966_3_2 >= (-100)) && (pub_r000966_3_2 <= 100));
  __CPROVER_assume((pub_r000966_4_1 >= (-100)) && (pub_r000966_4_1 <= 100));
  __CPROVER_assume((pub_r000966_4_2 >= (-100)) && (pub_r000966_4_2 <= 100));
  __CPROVER_assume((pub_r000966_5_1 >= (-100)) && (pub_r000966_5_1 <= 100));
  __CPROVER_assume((pub_r000966_5_2 >= (-100)) && (pub_r000966_5_2 <= 100));
  __CPROVER_assume((pub_r000966_6_1 >= (-100)) && (pub_r000966_6_1 <= 100));
  __CPROVER_assume((pub_r000966_6_2 >= (-100)) && (pub_r000966_6_2 <= 100));
  __CPROVER_assume((pub_r000966_7_1 >= (-100)) && (pub_r000966_7_1 <= 100));
  __CPROVER_assume((pub_r000966_7_2 >= (-100)) && (pub_r000966_7_2 <= 100));
  __CPROVER_assume((pub_r000966_8_1 >= (-100)) && (pub_r000966_8_1 <= 100));
  __CPROVER_assume((pub_r000966_8_2 >= (-100)) && (pub_r000966_8_2 <= 100));
  __CPROVER_assume((pub_r000966_9_1 >= (-100)) && (pub_r000966_9_1 <= 100));
  __CPROVER_assume((pub_r000966_9_2 >= (-100)) && (pub_r000966_9_2 <= 100));
  __CPROVER_assume((pub_r000966_10_1 >= (-100)) && (pub_r000966_10_1 <= 100));
  __CPROVER_assume((pub_r000966_10_2 >= (-100)) && (pub_r000966_10_2 <= 100));
  __CPROVER_assume((pub_r000966_11_1 >= (-100)) && (pub_r000966_11_1 <= 100));
  __CPROVER_assume((pub_r000966_11_2 >= (-100)) && (pub_r000966_11_2 <= 100));
  __CPROVER_assume((pub_r000966_12_1 >= (-100)) && (pub_r000966_12_1 <= 100));
  __CPROVER_assume((pub_r000966_12_2 >= (-100)) && (pub_r000966_12_2 <= 100));
  __CPROVER_assume((pub_r000966_13_1 >= (-100)) && (pub_r000966_13_1 <= 100));
  __CPROVER_assume((pub_r000966_13_2 >= (-100)) && (pub_r000966_13_2 <= 100));
  __CPROVER_assume((pub_r000966_14_1 >= (-100)) && (pub_r000966_14_1 <= 100));
  __CPROVER_assume((pub_r000966_14_2 >= (-100)) && (pub_r000966_14_2 <= 100));
  __CPROVER_assume((pub_r000966_15_1 >= (-100)) && (pub_r000966_15_1 <= 100));
  __CPROVER_assume((pub_r000966_15_2 >= (-100)) && (pub_r000966_15_2 <= 100));
  __CPROVER_assume((pub_r000966_16_1 >= (-100)) && (pub_r000966_16_1 <= 100));
  __CPROVER_assume((pub_r000966_16_2 >= (-100)) && (pub_r000966_16_2 <= 100));
  __CPROVER_assume((pub_r000966_17_1 >= (-100)) && (pub_r000966_17_1 <= 100));
  __CPROVER_assume((pub_r000966_17_2 >= (-100)) && (pub_r000966_17_2 <= 100));
  __CPROVER_assume((pub_r000966_18_1 >= (-100)) && (pub_r000966_18_1 <= 100));
  __CPROVER_assume((pub_r000966_18_2 >= (-100)) && (pub_r000966_18_2 <= 100));
  __CPROVER_assume((pub_r000966_19_1 >= (-100)) && (pub_r000966_19_1 <= 100));
  __CPROVER_assume((pub_r000966_19_2 >= (-100)) && (pub_r000966_19_2 <= 100));
  __CPROVER_assume((pub_r000966_20_1 >= (-100)) && (pub_r000966_20_1 <= 100));
  __CPROVER_assume((pub_r000966_20_2 >= (-100)) && (pub_r000966_20_2 <= 100));
  __CPROVER_assume((pub_r000966_21_1 >= (-100)) && (pub_r000966_21_1 <= 100));
  __CPROVER_assume((pub_r000966_21_2 >= (-100)) && (pub_r000966_21_2 <= 100));
  __CPROVER_assume((sec_r000966_0_1 >= 0) && (sec_r000966_0_1 <= 255));
  __CPROVER_assume((sec_r000966_0_2 >= 0) && (sec_r000966_0_2 <= 255));
  __CPROVER_assume((sec_r000966_1_1 >= 0) && (sec_r000966_1_1 <= 255));
  __CPROVER_assume((sec_r000966_1_2 >= 0) && (sec_r000966_1_2 <= 255));
  __CPROVER_assume((sec_r000966_2_1 >= 0) && (sec_r000966_2_1 <= 255));
  __CPROVER_assume((sec_r000966_2_2 >= 0) && (sec_r000966_2_2 <= 255));
  __CPROVER_assume((sec_r000966_3_1 >= 0) && (sec_r000966_3_1 <= 255));
  __CPROVER_assume((sec_r000966_3_2 >= 0) && (sec_r000966_3_2 <= 255));
  __CPROVER_assume((sec_r000966_4_1 >= 0) && (sec_r000966_4_1 <= 255));
  __CPROVER_assume((sec_r000966_4_2 >= 0) && (sec_r000966_4_2 <= 255));
  __CPROVER_assume((sec_r000966_5_1 >= 0) && (sec_r000966_5_1 <= 255));
  __CPROVER_assume((sec_r000966_5_2 >= 0) && (sec_r000966_5_2 <= 255));
  __CPROVER_assume((sec_r000966_6_1 >= 0) && (sec_r000966_6_1 <= 255));
  __CPROVER_assume((sec_r000966_6_2 >= 0) && (sec_r000966_6_2 <= 255));
  __CPROVER_assume((sec_r000966_7_1 >= 0) && (sec_r000966_7_1 <= 255));
  __CPROVER_assume((sec_r000966_7_2 >= 0) && (sec_r000966_7_2 <= 255));
  __CPROVER_assume((sec_r000966_8_1 >= 0) && (sec_r000966_8_1 <= 255));
  __CPROVER_assume((sec_r000966_8_2 >= 0) && (sec_r000966_8_2 <= 255));
  __CPROVER_assume((sec_r000966_9_1 >= 0) && (sec_r000966_9_1 <= 255));
  __CPROVER_assume((sec_r000966_9_2 >= 0) && (sec_r000966_9_2 <= 255));
  __CPROVER_assume((sec_r000966_10_1 >= 0) && (sec_r000966_10_1 <= 255));
  __CPROVER_assume((sec_r000966_10_2 >= 0) && (sec_r000966_10_2 <= 255));
  __CPROVER_assume((sec_r000966_11_1 >= 0) && (sec_r000966_11_1 <= 255));
  __CPROVER_assume((sec_r000966_11_2 >= 0) && (sec_r000966_11_2 <= 255));
  __CPROVER_assume((sec_r000966_12_1 >= 0) && (sec_r000966_12_1 <= 255));
  __CPROVER_assume((sec_r000966_12_2 >= 0) && (sec_r000966_12_2 <= 255));
  __CPROVER_assume((sec_r000966_13_1 >= 0) && (sec_r000966_13_1 <= 255));
  __CPROVER_assume((sec_r000966_13_2 >= 0) && (sec_r000966_13_2 <= 255));
  __CPROVER_assume((sec_r000966_14_1 >= 0) && (sec_r000966_14_1 <= 255));
  __CPROVER_assume((sec_r000966_14_2 >= 0) && (sec_r000966_14_2 <= 255));
  __CPROVER_assume((sec_r000966_15_1 >= 0) && (sec_r000966_15_1 <= 255));
  __CPROVER_assume((sec_r000966_15_2 >= 0) && (sec_r000966_15_2 <= 255));
  struct CipherContext_R000966_6613_0 st_var_0_1 = {0};
  struct CipherContext_R000966_6613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000966_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000966_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000966_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000966_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000966_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000966_0_2 + 7) & 15;
  struct DeviceConfig_R000966_6613_1 st_var_1_1 = {0};
  struct DeviceConfig_R000966_6613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000966_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000966_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000966_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000966_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000966_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000966_0_2 + 9) & 15;
  union PacketPayload_R000966_6613_0 u_var_1;
  union PacketPayload_R000966_6613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 3) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  int stage_v_3_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (8 & 31);
  int stage_v_3_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (8 & 31);
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= (stage_v_3_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_3_2 << 1) & 127;
  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
  int stage_v_5_1 = ((st_var_1_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_1_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 32)
    {
      chk_sum_1 ^= stage_v_5_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_5_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 32)
    {
      chk_sum_2 ^= stage_v_5_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_6_1 = ((st_var_0_1.buffer[0] * 2) + 25) & 63;
  int stage_v_6_2 = ((st_var_0_2.buffer[0] * 2) + 25) & 63;
  if (stage_v_6_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_6_1) - 5) & 255;
    if (stage_v_6_1 > 43)
    {
      chk_sum_1 ^= stage_v_6_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_6_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_6_2) - 5) & 255;
    if (stage_v_6_2 > 43)
    {
      chk_sum_2 ^= stage_v_6_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = ((st_var_1_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_1_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 29)
    {
      chk_sum_1 ^= stage_v_9_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_9_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 29)
    {
      chk_sum_2 ^= stage_v_9_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_10_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_10_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_10_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_10_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = (st_var_0_1.buffer[0] ^ 15) & 3;
  int stage_v_12_2 = (st_var_0_2.buffer[0] ^ 15) & 3;
  switch (stage_v_12_1)
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

  switch (stage_v_12_2)
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
  int stage_v_15_1 = ((st_var_1_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_1_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 25)
    {
      chk_sum_1 ^= stage_v_15_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_15_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 25)
    {
      chk_sum_2 ^= stage_v_15_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 17) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (st_var_0_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_0_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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
  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  }

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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
  int stage_v_26_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (31 & 31);
  int stage_v_26_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (31 & 31);
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= (stage_v_26_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_26_2 << 1) & 127;
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
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_30_1 = ((stage_v_30_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (st_var_1_1.buffer[0] ^ 34) & 3;
  int stage_v_31_2 = (st_var_1_2.buffer[0] ^ 34) & 3;
  switch (stage_v_31_1)
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

  switch (stage_v_31_2)
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

  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_32_1 = ((stage_v_32_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_32_2 = ((stage_v_32_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = table_1[1];
  int stage_v_33_2 = table_2[1];
  table_1[1] = (table_1[2] + 67) & 63;
  table_2[1] = (table_2[2] + 67) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_34_1 = ((stage_v_34_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_34_2 = ((stage_v_34_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
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
  if (stage_v_37_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 26)
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
  if (stage_v_37_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 26)
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
  int stage_v_38_1 = table_1[2];
  int stage_v_38_2 = table_2[2];
  table_1[2] = (table_1[3] + 77) & 63;
  table_2[2] = (table_2[3] + 77) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (44 & 31);
  int stage_v_39_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (44 & 31);
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= (stage_v_39_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_39_2 << 1) & 127;
  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_42_1 = ((st_var_0_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_0_2.buffer[0] * 2) + 133) & 63;
  if (stage_v_42_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 44)
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
  if (stage_v_42_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 44)
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
  int stage_v_43_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (48 & 31);
  int stage_v_43_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (48 & 31);
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= (stage_v_43_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_43_2 << 1) & 127;
  int stage_v_44_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (49 & 31);
  int stage_v_44_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (49 & 31);
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= (stage_v_44_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_44_2 << 1) & 127;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_45_1 = ((stage_v_45_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 47) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 47) & 15;
  int stage_v_46_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_46_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= stage_v_46_1;
  chk_sum_2 ^= stage_v_46_2;
  int stage_v_47_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (52 & 31);
  int stage_v_47_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (52 & 31);
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= (stage_v_47_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_47_2 << 1) & 127;
  int stage_v_48_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_48_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_48_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_48_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_49_1 = ((stage_v_49_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_49_2 = ((stage_v_49_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_50_1 = ((stage_v_50_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_50_2 = ((stage_v_50_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (st_var_1_1.buffer[0] ^ 54) & 3;
  int stage_v_51_2 = (st_var_1_2.buffer[0] ^ 54) & 3;
  switch (stage_v_51_1)
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

  switch (stage_v_51_2)
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

  int stage_v_52_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_52_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_52_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_52_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_53_1 = ((st_var_1_1.buffer[2] * 2) + 166) & 63;
  int stage_v_53_2 = ((st_var_1_2.buffer[2] * 2) + 166) & 63;
  if (stage_v_53_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_53_1) - 5) & 255;
    if (stage_v_53_1 > 55)
    {
      chk_sum_1 ^= stage_v_53_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_53_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_53_2) - 5) & 255;
    if (stage_v_53_2 > 55)
    {
      chk_sum_2 ^= stage_v_53_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 55) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 55) & 15;
  int stage_v_54_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_54_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= stage_v_54_1;
  chk_sum_2 ^= stage_v_54_2;
  int stage_v_55_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (60 & 31);
  int stage_v_55_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (60 & 31);
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= (stage_v_55_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_55_2 << 1) & 127;
  int stage_v_56_1 = ((st_var_0_1.buffer[2] * 2) + 175) & 63;
  int stage_v_56_2 = ((st_var_0_2.buffer[2] * 2) + 175) & 63;
  if (stage_v_56_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_56_1) - 5) & 255;
    if (stage_v_56_1 > 43)
    {
      chk_sum_1 ^= stage_v_56_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_56_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_56_2) - 5) & 255;
    if (stage_v_56_2 > 43)
    {
      chk_sum_2 ^= stage_v_56_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_57_1 = table_1[1];
  int stage_v_57_2 = table_2[1];
  table_1[1] = (table_1[2] + 115) & 63;
  table_2[1] = (table_2[2] + 115) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 59) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 59) & 15;
  int stage_v_58_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_58_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= stage_v_58_1;
  chk_sum_2 ^= stage_v_58_2;
  int stage_v_59_1 = ((st_var_1_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_1_2.buffer[2] * 2) + 184) & 63;
  if (stage_v_59_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 28)
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
  if (stage_v_59_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 28)
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
  if (stage_v_60_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_60_1) - 5) & 255;
    if (stage_v_60_1 > 32)
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
  if (stage_v_60_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_60_2) - 5) & 255;
    if (stage_v_60_2 > 32)
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
  int stage_v_61_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_61_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_61_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_61_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_62_1 = (st_var_0_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_0_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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

  int stage_v_63_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_63_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_64_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_64_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_64_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_64_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 66) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 66) & 15;
  int stage_v_65_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_65_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= stage_v_65_1;
  chk_sum_2 ^= stage_v_65_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 67) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 67) & 15;
  int stage_v_66_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_66_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= stage_v_66_1;
  chk_sum_2 ^= stage_v_66_2;
  int stage_v_67_1 = (st_var_1_1.buffer[0] ^ 70) & 3;
  int stage_v_67_2 = (st_var_1_2.buffer[0] ^ 70) & 3;
  switch (stage_v_67_1)
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

  switch (stage_v_67_2)
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

  int stage_v_68_1 = table_1[0];
  int stage_v_68_2 = table_2[0];
  table_1[0] = (table_1[1] + 137) & 63;
  table_2[0] = (table_2[1] + 137) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (74 & 31);
  int stage_v_69_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (74 & 31);
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= (stage_v_69_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_69_2 << 1) & 127;
  int stage_v_70_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (75 & 31);
  int stage_v_70_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (75 & 31);
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  chk_sum_1 ^= (stage_v_70_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_70_2 << 1) & 127;
  int stage_v_71_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (76 & 31);
  int stage_v_71_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (76 & 31);
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= (stage_v_71_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_71_2 << 1) & 127;
  int stage_v_72_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_72_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_73_1 = table_1[1];
  int stage_v_73_2 = table_2[1];
  table_1[1] = (table_1[2] + 147) & 63;
  table_2[1] = (table_2[2] + 147) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((st_var_0_1.buffer[2] * 2) + 229) & 63;
  int stage_v_74_2 = ((st_var_0_2.buffer[2] * 2) + 229) & 63;
  if (stage_v_74_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_74_1) - 5) & 255;
    if (stage_v_74_1 > 25)
    {
      chk_sum_1 ^= stage_v_74_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_74_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_74_2) - 5) & 255;
    if (stage_v_74_2 > 25)
    {
      chk_sum_2 ^= stage_v_74_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 76) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 76) & 15;
  int stage_v_75_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_75_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  chk_sum_1 ^= stage_v_75_1;
  chk_sum_2 ^= stage_v_75_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 77) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 77) & 15;
  int stage_v_76_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_76_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= stage_v_76_1;
  chk_sum_2 ^= stage_v_76_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 78) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 78) & 15;
  int stage_v_77_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_77_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= stage_v_77_1;
  chk_sum_2 ^= stage_v_77_2;
  int stage_v_78_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (83 & 31);
  int stage_v_78_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (83 & 31);
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  chk_sum_1 ^= (stage_v_78_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_78_2 << 1) & 127;
  int stage_v_79_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_79_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_79_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_79_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_80_1 = table_1[0];
  int stage_v_80_2 = table_2[0];
  table_1[0] = (table_1[1] + 161) & 63;
  table_2[0] = (table_2[1] + 161) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((st_var_1_1.buffer[0] * 2) + 250) & 63;
  int stage_v_81_2 = ((st_var_1_2.buffer[0] * 2) + 250) & 63;
  if (stage_v_81_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_81_1) - 5) & 255;
    if (stage_v_81_1 > 55)
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
  if (stage_v_81_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_81_2) - 5) & 255;
    if (stage_v_81_2 > 55)
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
  int stage_v_82_1 = table_1[2];
  int stage_v_82_2 = table_2[2];
  table_1[2] = (table_1[3] + 165) & 63;
  table_2[2] = (table_2[3] + 165) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = table_1[3];
  int stage_v_83_2 = table_2[3];
  table_1[3] = (table_1[0] + 167) & 63;
  table_2[3] = (table_2[0] + 167) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((st_var_0_1.buffer[0] * 2) + 259) & 63;
  int stage_v_84_2 = ((st_var_0_2.buffer[0] * 2) + 259) & 63;
  if (stage_v_84_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_84_1) - 5) & 255;
    if (stage_v_84_1 > 39)
    {
      chk_sum_1 ^= stage_v_84_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_84_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_84_2) - 5) & 255;
    if (stage_v_84_2 > 39)
    {
      chk_sum_2 ^= stage_v_84_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_85_1 = table_1[1];
  int stage_v_85_2 = table_2[1];
  table_1[1] = (table_1[2] + 171) & 63;
  table_2[1] = (table_2[2] + 171) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((st_var_0_1.buffer[2] * 2) + 265) & 63;
  int stage_v_86_2 = ((st_var_0_2.buffer[2] * 2) + 265) & 63;
  if (stage_v_86_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_86_1) - 5) & 255;
    if (stage_v_86_1 > 46)
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
  if (stage_v_86_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_86_2) - 5) & 255;
    if (stage_v_86_2 > 46)
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
  int stage_v_87_1 = table_1[3];
  int stage_v_87_2 = table_2[3];
  table_1[3] = (table_1[0] + 175) & 63;
  table_2[3] = (table_2[0] + 175) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (st_var_0_1.buffer[0] ^ 91) & 3;
  int stage_v_88_2 = (st_var_0_2.buffer[0] ^ 91) & 3;
  switch (stage_v_88_1)
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

  switch (stage_v_88_2)
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

  int stage_v_89_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (94 & 31);
  int stage_v_89_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (94 & 31);
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  chk_sum_1 ^= (stage_v_89_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_89_2 << 1) & 127;
  int stage_v_90_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_90_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_90_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_90_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_91_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (96 & 31);
  int stage_v_91_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (96 & 31);
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  chk_sum_1 ^= (stage_v_91_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_91_2 << 1) & 127;
  int stage_v_92_1 = table_1[0];
  int stage_v_92_2 = table_2[0];
  table_1[0] = (table_1[1] + 185) & 63;
  table_2[0] = (table_2[1] + 185) & 63;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((st_var_1_1.buffer[0] * 2) + 286) & 63;
  int stage_v_93_2 = ((st_var_1_2.buffer[0] * 2) + 286) & 63;
  if (stage_v_93_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_93_1) - 5) & 255;
    if (stage_v_93_1 > 42)
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
  if (stage_v_93_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_93_2) - 5) & 255;
    if (stage_v_93_2 > 42)
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
  int stage_v_94_1 = (st_var_0_1.buffer[0] ^ 97) & 3;
  int stage_v_94_2 = (st_var_0_2.buffer[0] ^ 97) & 3;
  switch (stage_v_94_1)
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

  switch (stage_v_94_2)
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

  int stage_v_95_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (100 & 31);
  int stage_v_95_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (100 & 31);
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  chk_sum_1 ^= (stage_v_95_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_95_2 << 1) & 127;
  int stage_v_96_1 = ((st_var_0_1.buffer[0] * 2) + 295) & 63;
  int stage_v_96_2 = ((st_var_0_2.buffer[0] * 2) + 295) & 63;
  if (stage_v_96_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_96_1) - 5) & 255;
    if (stage_v_96_1 > 34)
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
  if (stage_v_96_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_96_2) - 5) & 255;
    if (stage_v_96_2 > 34)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 98) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 98) & 15;
  int stage_v_97_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_97_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  chk_sum_1 ^= stage_v_97_1;
  chk_sum_2 ^= stage_v_97_2;
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
  int stage_v_100_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (105 & 31);
  int stage_v_100_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (105 & 31);
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  chk_sum_1 ^= (stage_v_100_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_100_2 << 1) & 127;
  int stage_v_101_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (106 & 31);
  int stage_v_101_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (106 & 31);
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  chk_sum_1 ^= (stage_v_101_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_101_2 << 1) & 127;
  int stage_v_102_1 = (st_var_0_1.buffer[0] ^ 105) & 3;
  int stage_v_102_2 = (st_var_0_2.buffer[0] ^ 105) & 3;
  switch (stage_v_102_1)
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

  switch (stage_v_102_2)
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

  int stage_v_103_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_103_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_103_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_103_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_104_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (109 & 31);
  int stage_v_104_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (109 & 31);
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  chk_sum_1 ^= (stage_v_104_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_104_2 << 1) & 127;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
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
  int stage_v_107_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_107_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_107_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_107_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_108_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_108_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_108_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_108_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_109_1 = (st_var_1_1.buffer[0] ^ 112) & 3;
  int stage_v_109_2 = (st_var_1_2.buffer[0] ^ 112) & 3;
  switch (stage_v_109_1)
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

  switch (stage_v_109_2)
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

  int stage_v_110_1 = (st_var_0_1.buffer[0] ^ 113) & 3;
  int stage_v_110_2 = (st_var_0_2.buffer[0] ^ 113) & 3;
  switch (stage_v_110_1)
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

  switch (stage_v_110_2)
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

  int stage_v_111_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_111_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_111_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_111_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_112_1 = ((stage_v_112_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_112_2 = ((stage_v_112_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (st_var_1_1.buffer[0] ^ 116) & 3;
  int stage_v_113_2 = (st_var_1_2.buffer[0] ^ 116) & 3;
  switch (stage_v_113_1)
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

  switch (stage_v_113_2)
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

  int stage_v_114_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (119 & 31);
  int stage_v_114_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (119 & 31);
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  chk_sum_1 ^= (stage_v_114_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_114_2 << 1) & 127;
  int stage_v_115_1 = table_1[3];
  int stage_v_115_2 = table_2[3];
  table_1[3] = (table_1[0] + 231) & 63;
  table_2[3] = (table_2[0] + 231) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = table_1[0];
  int stage_v_116_2 = table_2[0];
  table_1[0] = (table_1[1] + 233) & 63;
  table_2[0] = (table_2[1] + 233) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (122 & 31);
  int stage_v_117_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (122 & 31);
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  chk_sum_1 ^= (stage_v_117_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_117_2 << 1) & 127;
  int stage_v_118_1 = table_1[2];
  int stage_v_118_2 = table_2[2];
  table_1[2] = (table_1[3] + 237) & 63;
  table_2[2] = (table_2[3] + 237) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((st_var_1_1.buffer[2] * 2) + 364) & 63;
  int stage_v_119_2 = ((st_var_1_2.buffer[2] * 2) + 364) & 63;
  if (stage_v_119_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_119_1) - 5) & 255;
    if (stage_v_119_1 > 42)
    {
      chk_sum_1 ^= stage_v_119_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_119_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_119_2) - 5) & 255;
    if (stage_v_119_2 > 42)
    {
      chk_sum_2 ^= stage_v_119_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_120_1 = (st_var_0_1.buffer[0] ^ 123) & 3;
  int stage_v_120_2 = (st_var_0_2.buffer[0] ^ 123) & 3;
  switch (stage_v_120_1)
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

  switch (stage_v_120_2)
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

  int stage_v_121_1 = (st_var_1_1.buffer[0] ^ 124) & 3;
  int stage_v_121_2 = (st_var_1_2.buffer[0] ^ 124) & 3;
  switch (stage_v_121_1)
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

  switch (stage_v_121_2)
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

  int stage_v_122_1 = table_1[2];
  int stage_v_122_2 = table_2[2];
  table_1[2] = (table_1[3] + 245) & 63;
  table_2[2] = (table_2[3] + 245) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (128 & 31);
  int stage_v_123_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (128 & 31);
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  chk_sum_1 ^= (stage_v_123_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_123_2 << 1) & 127;
  int stage_v_124_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_124_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_124_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_124_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 126) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 126) & 15;
  int stage_v_125_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_125_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  chk_sum_1 ^= stage_v_125_1;
  chk_sum_2 ^= stage_v_125_2;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_126_1 = ((stage_v_126_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_126_2 = ((stage_v_126_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 128) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 128) & 15;
  int stage_v_127_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_127_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  chk_sum_1 ^= stage_v_127_1;
  chk_sum_2 ^= stage_v_127_2;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_128_1 = ((stage_v_128_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_128_2 = ((stage_v_128_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_129_1 = ((stage_v_129_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_129_2 = ((stage_v_129_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_130_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_130_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_130_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_131_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_131_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_131_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_131_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_132_1 = table_1[0];
  int stage_v_132_2 = table_2[0];
  table_1[0] = (table_1[1] + 265) & 63;
  table_2[0] = (table_2[1] + 265) & 63;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((st_var_1_1.buffer[1] * 2) + 406) & 63;
  int stage_v_133_2 = ((st_var_1_2.buffer[1] * 2) + 406) & 63;
  if (stage_v_133_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_133_1) - 5) & 255;
    if (stage_v_133_1 > 32)
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
  if (stage_v_133_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_133_2) - 5) & 255;
    if (stage_v_133_2 > 32)
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
  int stage_v_134_1 = (st_var_0_1.buffer[0] ^ 137) & 3;
  int stage_v_134_2 = (st_var_0_2.buffer[0] ^ 137) & 3;
  switch (stage_v_134_1)
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

  switch (stage_v_134_2)
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

  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 136) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 136) & 15;
  int stage_v_135_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_135_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  chk_sum_1 ^= stage_v_135_1;
  chk_sum_2 ^= stage_v_135_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 137) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 137) & 15;
  int stage_v_136_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_136_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  chk_sum_1 ^= stage_v_136_1;
  chk_sum_2 ^= stage_v_136_2;
  int stage_v_137_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_137_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_137_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_137_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_138_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (143 & 31);
  int stage_v_138_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (143 & 31);
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  chk_sum_1 ^= (stage_v_138_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_138_2 << 1) & 127;
  int stage_v_139_1 = ((st_var_1_1.buffer[1] * 2) + 424) & 63;
  int stage_v_139_2 = ((st_var_1_2.buffer[1] * 2) + 424) & 63;
  if (stage_v_139_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_139_1) - 5) & 255;
    if (stage_v_139_1 > 55)
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
  if (stage_v_139_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_139_2) - 5) & 255;
    if (stage_v_139_2 > 55)
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
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_140_1 = ((stage_v_140_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_140_2 = ((stage_v_140_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
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
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_143_1 = ((stage_v_143_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_143_2 = ((stage_v_143_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (149 & 31);
  int stage_v_144_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (149 & 31);
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  chk_sum_1 ^= (stage_v_144_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_144_2 << 1) & 127;
  int stage_v_145_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (150 & 31);
  int stage_v_145_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (150 & 31);
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  chk_sum_1 ^= (stage_v_145_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_145_2 << 1) & 127;
  int stage_v_146_1 = ((st_var_0_1.buffer[2] * 2) + 445) & 63;
  int stage_v_146_2 = ((st_var_0_2.buffer[2] * 2) + 445) & 63;
  if (stage_v_146_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_146_1) - 5) & 255;
    if (stage_v_146_1 > 49)
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
  if (stage_v_146_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_146_2) - 5) & 255;
    if (stage_v_146_2 > 49)
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
  int stage_v_148_1 = table_1[0];
  int stage_v_148_2 = table_2[0];
  table_1[0] = (table_1[1] + 297) & 63;
  table_2[0] = (table_2[1] + 297) & 63;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 150) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 150) & 15;
  int stage_v_149_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_149_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  chk_sum_1 ^= stage_v_149_1;
  chk_sum_2 ^= stage_v_149_2;
  int stage_v_150_1 = ((st_var_0_1.buffer[0] * 2) + 457) & 63;
  int stage_v_150_2 = ((st_var_0_2.buffer[0] * 2) + 457) & 63;
  if (stage_v_150_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_150_1) - 5) & 255;
    if (stage_v_150_1 > 51)
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
  if (stage_v_150_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_150_2) - 5) & 255;
    if (stage_v_150_2 > 51)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 152) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 152) & 15;
  int stage_v_151_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_151_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  chk_sum_1 ^= stage_v_151_1;
  chk_sum_2 ^= stage_v_151_2;
  int stage_v_152_1 = ((st_var_0_1.buffer[2] * 2) + 463) & 63;
  int stage_v_152_2 = ((st_var_0_2.buffer[2] * 2) + 463) & 63;
  if (stage_v_152_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_152_1) - 5) & 255;
    if (stage_v_152_1 > 40)
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
  if (stage_v_152_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_152_2) - 5) & 255;
    if (stage_v_152_2 > 40)
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
  int stage_v_153_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_153_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_153_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_153_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_154_1 = (st_var_0_1.buffer[0] ^ 157) & 3;
  int stage_v_154_2 = (st_var_0_2.buffer[0] ^ 157) & 3;
  switch (stage_v_154_1)
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

  switch (stage_v_154_2)
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

  int stage_v_155_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (160 & 31);
  int stage_v_155_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (160 & 31);
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  chk_sum_1 ^= (stage_v_155_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_155_2 << 1) & 127;
  int stage_v_156_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_156_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_156_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_156_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_157_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (162 & 31);
  int stage_v_157_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (162 & 31);
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  chk_sum_1 ^= (stage_v_157_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_157_2 << 1) & 127;
  int stage_v_158_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_158_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_158_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_158_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_159_1 = table_1[3];
  int stage_v_159_2 = table_2[3];
  table_1[3] = (table_1[0] + 319) & 63;
  table_2[3] = (table_2[0] + 319) & 63;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
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

  switch (stage_v_161_2)
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
  int stage_v_163_1 = table_1[3];
  int stage_v_163_2 = table_2[3];
  table_1[3] = (table_1[0] + 327) & 63;
  table_2[3] = (table_2[0] + 327) & 63;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = (st_var_0_1.buffer[0] ^ 167) & 3;
  int stage_v_164_2 = (st_var_0_2.buffer[0] ^ 167) & 3;
  switch (stage_v_164_1)
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

  switch (stage_v_164_2)
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

  int m_var_1 = (sec_r000966_10_1 ^ 0x55) & 63;
  int m_var_2 = (sec_r000966_10_2 ^ 0x55) & 63;
  if (m_var_1 > 15)
  {
    out_sink_1 += ((m_var_1 * 2) + pub_r000966_4_1) & 127;
  }
  else
  {
    out_sink_1 -= (m_var_1 + 9) & 31;
  }
  if (m_var_2 > 15)
  {
    out_sink_2 += ((m_var_2 * 2) + pub_r000966_4_2) & 127;
  }
  else
  {
    out_sink_2 -= (m_var_2 + 9) & 31;
  }
  out_sink_1 ^= sec_r000966_12_1 & 15;
  out_sink_2 ^= sec_r000966_12_2 & 15;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000966_4_1 != sec_r000966_4_2);
  __CPROVER_assume(pub_r000966_12_1 == pub_r000966_12_2);
  __CPROVER_assume(pub_r000966_15_1 == pub_r000966_15_2);
  __CPROVER_assume(pub_r000966_14_1 == pub_r000966_14_2);
  __CPROVER_assume(pub_r000966_13_1 == pub_r000966_13_2);
  __CPROVER_assume(sec_r000966_9_1 != sec_r000966_9_2);
  __CPROVER_assume(sec_r000966_13_1 != sec_r000966_13_2);
  __CPROVER_assume(sec_r000966_10_1 != sec_r000966_10_2);
  __CPROVER_assume(sec_r000966_14_1 != sec_r000966_14_2);
  __CPROVER_assume(sec_r000966_5_1 != sec_r000966_5_2);
  __CPROVER_assume(pub_r000966_11_1 == pub_r000966_11_2);
  __CPROVER_assume(pub_r000966_16_1 == pub_r000966_16_2);
  __CPROVER_assume(pub_r000966_4_1 == pub_r000966_4_2);
  __CPROVER_assume(pub_r000966_6_1 == pub_r000966_6_2);
  __CPROVER_assume(sec_r000966_0_1 != sec_r000966_0_2);
  __CPROVER_assume(sec_r000966_2_1 != sec_r000966_2_2);
  __CPROVER_assume(pub_r000966_2_1 == pub_r000966_2_2);
  __CPROVER_assume(pub_r000966_9_1 == pub_r000966_9_2);
  __CPROVER_assume(pub_r000966_1_1 == pub_r000966_1_2);
  __CPROVER_assume(sec_r000966_1_1 != sec_r000966_1_2);
  __CPROVER_assume(sec_r000966_3_1 != sec_r000966_3_2);
  __CPROVER_assume(sec_r000966_11_1 != sec_r000966_11_2);
  __CPROVER_assume(sec_r000966_8_1 != sec_r000966_8_2);
  __CPROVER_assume(sec_r000966_7_1 != sec_r000966_7_2);
  __CPROVER_assume(pub_r000966_10_1 == pub_r000966_10_2);
  __CPROVER_assume(pub_r000966_0_1 == pub_r000966_0_2);
  __CPROVER_assume(pub_r000966_8_1 == pub_r000966_8_2);
  __CPROVER_assume(pub_r000966_7_1 == pub_r000966_7_2);
  __CPROVER_assume(pub_r000966_17_1 == pub_r000966_17_2);
  __CPROVER_assume(sec_r000966_12_1 != sec_r000966_12_2);
  __CPROVER_assume(pub_r000966_19_1 == pub_r000966_19_2);
  __CPROVER_assume(pub_r000966_18_1 == pub_r000966_18_2);
  __CPROVER_assume(sec_r000966_15_1 != sec_r000966_15_2);
  __CPROVER_assume(pub_r000966_5_1 == pub_r000966_5_2);
  __CPROVER_assume(sec_r000966_6_1 != sec_r000966_6_2);
  __CPROVER_assume(pub_r000966_21_1 == pub_r000966_21_2);
  __CPROVER_assume(pub_r000966_20_1 == pub_r000966_20_2);
  __CPROVER_assume(pub_r000966_3_1 == pub_r000966_3_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
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
  assert(m_var_1 == m_var_2);
}


