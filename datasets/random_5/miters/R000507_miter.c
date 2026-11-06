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
struct EventLog_R000507_713_0
{
  unsigned char severity;
  short seq;
  short facility;
  int buffer[3];
};
struct SensorNode_R000507_713_1
{
  unsigned char status;
  unsigned char threshold;
  int gain;
  int buffer[3];
};
struct CipherContext_R000507_713_2
{
  int tag;
  int nonce;
  unsigned char flags;
  int buffer[3];
};
union ColorPixel_R000507_713_0
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
void fn_R000507_713_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st_1 = {0};
  struct SensorNode_R000507_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_32_1) & 63;
  aux_2 = (aux_2 + damping_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_28_1 = local_arr_1[aux_1 % 3];
  int margin_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_28_2 * 2)) & 127;
  int offset_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_90_1 > 50)
  {
    acc_1 = ((acc_1 + (offset_90_1 * 2)) + 5) & 127;
    aux_1 ^= offset_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_90_2 > 50)
  {
    acc_2 = ((acc_2 + (offset_90_2 * 2)) + 5) & 127;
    aux_2 ^= offset_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_90_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_32_1 == damping_32_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_28_1 == margin_28_2);
  assert(offset_90_1 == offset_90_2);
}

int fn_R000507_713_0(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_32) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_28 = local_arr[aux % 3];
  acc = (acc + (margin_28 * 2)) & 127;
  int offset_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_90 > 50)
  {
    acc = ((acc + (offset_90 * 2)) + 5) & 127;
    aux ^= offset_90 & 15;
  }
  else
  {
    acc = ((acc - offset_90) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000507_713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st_1 = {0};
  struct SensorNode_R000507_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_35_1 = local_arr_1[aux_1 % 3];
  int weight_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_35_2 * 2)) & 127;
  int coefficient_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_88_1) & 63;
  aux_2 = (aux_2 + coefficient_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
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

  assert(weight_35_1 == weight_35_2);
  assert(coefficient_88_1 == coefficient_88_2);
}

int fn_R000507_713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int weight_35 = local_arr[aux % 3];
  acc = (acc + (weight_35 * 2)) & 127;
  int coefficient_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_88) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000507_713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000507_713_0 st_1 = {0};
  struct EventLog_R000507_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_70_1 > 50)
  {
    acc_1 = ((acc_1 + (scale_70_1 * 2)) + 5) & 127;
    aux_1 ^= scale_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_70_2 > 50)
  {
    acc_2 = ((acc_2 + (scale_70_2 * 2)) + 5) & 127;
    aux_2 ^= scale_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_78_1)
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

  switch (vector_78_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_70_1 == scale_70_2);
  assert(vector_78_1 == vector_78_2);
}

int fn_R000507_713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000507_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_70 > 50)
  {
    acc = ((acc + (scale_70 * 2)) + 5) & 127;
    aux ^= scale_70 & 15;
  }
  else
  {
    acc = ((acc - scale_70) + 11) & 127;
    aux += 3;
  }
  int vector_78 = (aux + st.buffer[1]) & 3;
  switch (vector_78)
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

void fn_R000507_713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st_1 = {0};
  struct SensorNode_R000507_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int checksum_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_54_1) & 63;
  aux_2 = (aux_2 + checksum_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_33_1 = local_arr_1[aux_1 % 3];
  int phase_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_33_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_54_1 == checksum_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_33_1 == phase_33_2);
}

int fn_R000507_713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int checksum_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_54) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_33 = local_arr[aux % 3];
  acc = (acc + (phase_33 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000507_713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st_1 = {0};
  struct SensorNode_R000507_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_52_1)
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

  switch (vector_52_2)
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

  int index_reg_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_48_1) & 63;
  aux_2 = (aux_2 + index_reg_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_52_1 == vector_52_2);
  assert(index_reg_48_1 == index_reg_48_2);
}

int fn_R000507_713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_52 = (aux + st.buffer[1]) & 3;
  switch (vector_52)
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

  int index_reg_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_48) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000507_713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st_1 = {0};
  struct SensorNode_R000507_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int offset_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_30_1) & 63;
  aux_2 = (aux_2 + offset_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_88_1 = local_arr_1[aux_1 % 3];
  int tracker_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_88_2 * 2)) & 127;
  int scale_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_25_1 > 15)
  {
    acc_1 = ((acc_1 + (scale_25_1 * 2)) + 5) & 127;
    aux_1 ^= scale_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_25_2 > 15)
  {
    acc_2 = ((acc_2 + (scale_25_2 * 2)) + 5) & 127;
    aux_2 ^= scale_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_25_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_30_1 == offset_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_88_1 == tracker_88_2);
  assert(scale_25_1 == scale_25_2);
}

int fn_R000507_713_5(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int offset_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_30) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_88 = local_arr[aux % 3];
  acc = (acc + (tracker_88 * 2)) & 127;
  int scale_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_25 > 15)
  {
    acc = ((acc + (scale_25 * 2)) + 5) & 127;
    aux ^= scale_25 & 15;
  }
  else
  {
    acc = ((acc - scale_25) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000507_713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st_1 = {0};
  struct SensorNode_R000507_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int residue_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_95_1)
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

  switch (residue_95_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_64_1 > 13)
  {
    acc_1 = ((acc_1 + (tracker_64_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_64_2 > 13)
  {
    acc_2 = ((acc_2 + (tracker_64_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_95_1 == residue_95_2);
  assert(tracker_64_1 == tracker_64_2);
}

int fn_R000507_713_6(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int residue_95 = (aux + st.buffer[1]) & 3;
  switch (residue_95)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_64 > 13)
  {
    acc = ((acc + (tracker_64 * 2)) + 5) & 127;
    aux ^= tracker_64 & 15;
  }
  else
  {
    acc = ((acc - tracker_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000507_713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000507_713_0 st_1 = {0};
  struct EventLog_R000507_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_78_1 = local_arr_1[aux_1 % 3];
  int parity_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_78_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_45_1 > 45)
  {
    acc_1 = ((acc_1 + (damping_45_1 * 2)) + 5) & 127;
    aux_1 ^= damping_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_45_2 > 45)
  {
    acc_2 = ((acc_2 + (damping_45_2 * 2)) + 5) & 127;
    aux_2 ^= damping_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_74_1) & 63;
  aux_2 = (aux_2 + parity_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_78_1 == parity_78_2);
  assert(damping_45_1 == damping_45_2);
  assert(parity_74_1 == parity_74_2);
}

int fn_R000507_713_7(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000507_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int parity_78 = local_arr[aux % 3];
  acc = (acc + (parity_78 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_45 > 45)
  {
    acc = ((acc + (damping_45 * 2)) + 5) & 127;
    aux ^= damping_45 & 15;
  }
  else
  {
    acc = ((acc - damping_45) + 11) & 127;
    aux += 3;
  }
  int parity_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_74) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000507_713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st_1 = {0};
  struct SensorNode_R000507_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_61_1 = local_arr_1[aux_1 % 3];
  int anchor_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_61_2 * 2)) & 127;
  int bound_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_91_1 > 41)
  {
    acc_1 = ((acc_1 + (bound_91_1 * 2)) + 5) & 127;
    aux_1 ^= bound_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_91_2 > 41)
  {
    acc_2 = ((acc_2 + (bound_91_2 * 2)) + 5) & 127;
    aux_2 ^= bound_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_16_1) & 63;
  aux_2 = (aux_2 + pivot_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
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

  assert(anchor_61_1 == anchor_61_2);
  assert(bound_91_1 == bound_91_2);
  assert(pivot_16_1 == pivot_16_2);
}

int fn_R000507_713_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int anchor_61 = local_arr[aux % 3];
  acc = (acc + (anchor_61 * 2)) & 127;
  int bound_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_91 > 41)
  {
    acc = ((acc + (bound_91 * 2)) + 5) & 127;
    aux ^= bound_91 & 15;
  }
  else
  {
    acc = ((acc - bound_91) + 11) & 127;
    aux += 3;
  }
  int pivot_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_16) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000507_713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000507_713_2 st_1 = {0};
  struct CipherContext_R000507_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int stride_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_25_1) & 63;
  aux_2 = (aux_2 + stride_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_28_1 > 34)
  {
    acc_1 = ((acc_1 + (quantum_28_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_28_2 > 34)
  {
    acc_2 = ((acc_2 + (quantum_28_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_28_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_69_1)
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

  switch (vector_69_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_25_1 == stride_25_2);
  assert(quantum_28_1 == quantum_28_2);
  assert(vector_69_1 == vector_69_2);
}

int fn_R000507_713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000507_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int stride_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_25) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_28 > 34)
  {
    acc = ((acc + (quantum_28 * 2)) + 5) & 127;
    aux ^= quantum_28 & 15;
  }
  else
  {
    acc = ((acc - quantum_28) + 11) & 127;
    aux += 3;
  }
  int vector_69 = (aux + st.buffer[1]) & 3;
  switch (vector_69)
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

void fn_R000507_713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000507_713_0 st_1 = {0};
  struct EventLog_R000507_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_31_1 = local_arr_1[aux_1 % 3];
  int phase_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_31_2 * 2)) & 127;
  int factor_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_47_1 > 19)
  {
    acc_1 = ((acc_1 + (factor_47_1 * 2)) + 5) & 127;
    aux_1 ^= factor_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_47_2 > 19)
  {
    acc_2 = ((acc_2 + (factor_47_2 * 2)) + 5) & 127;
    aux_2 ^= factor_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_47_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_31_1 == phase_31_2);
  assert(factor_47_1 == factor_47_2);
}

int fn_R000507_713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000507_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int phase_31 = local_arr[aux % 3];
  acc = (acc + (phase_31 * 2)) & 127;
  int factor_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_47 > 19)
  {
    acc = ((acc + (factor_47 * 2)) + 5) & 127;
    aux ^= factor_47 & 15;
  }
  else
  {
    acc = ((acc - factor_47) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000507_713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000507_713_0 st_1 = {0};
  struct EventLog_R000507_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_55_1 = local_arr_1[aux_1 % 3];
  int scale_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_55_2 * 2)) & 127;
  int threshold_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_63_1 > 36)
  {
    acc_1 = ((acc_1 + (threshold_63_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_63_2 > 36)
  {
    acc_2 = ((acc_2 + (threshold_63_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_63_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_55_1 == scale_55_2);
  assert(threshold_63_1 == threshold_63_2);
}

int fn_R000507_713_11(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000507_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int scale_55 = local_arr[aux % 3];
  acc = (acc + (scale_55 * 2)) & 127;
  int threshold_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_63 > 36)
  {
    acc = ((acc + (threshold_63 * 2)) + 5) & 127;
    aux ^= threshold_63 & 15;
  }
  else
  {
    acc = ((acc - threshold_63) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000507_713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st_1 = {0};
  struct SensorNode_R000507_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int accumulator_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_89_1) & 63;
  aux_2 = (aux_2 + accumulator_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_57_1 = local_arr_1[aux_1 % 3];
  int coefficient_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_57_2 * 2)) & 127;
  int delta_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_27_1)
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

  switch (delta_27_2)
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

  int scale_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_44_1 > 25)
  {
    acc_1 = ((acc_1 + (scale_44_1 * 2)) + 5) & 127;
    aux_1 ^= scale_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_44_2 > 25)
  {
    acc_2 = ((acc_2 + (scale_44_2 * 2)) + 5) & 127;
    aux_2 ^= scale_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_44_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_89_1 == accumulator_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_57_1 == coefficient_57_2);
  assert(delta_27_1 == delta_27_2);
  assert(scale_44_1 == scale_44_2);
}

int fn_R000507_713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int accumulator_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_89) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int coefficient_57 = local_arr[aux % 3];
  acc = (acc + (coefficient_57 * 2)) & 127;
  int delta_27 = (aux + st.buffer[1]) & 3;
  switch (delta_27)
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

  int scale_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_44 > 25)
  {
    acc = ((acc + (scale_44 * 2)) + 5) & 127;
    aux ^= scale_44 & 15;
  }
  else
  {
    acc = ((acc - scale_44) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000507_713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st_1 = {0};
  struct SensorNode_R000507_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int pivot_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_57_1)
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

  switch (pivot_57_2)
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

  int anchor_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_36_1) & 63;
  aux_2 = (aux_2 + anchor_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_35_1 = local_arr_1[aux_1 % 3];
  int anchor_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_35_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_57_1 == pivot_57_2);
  assert(anchor_36_1 == anchor_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_35_1 == anchor_35_2);
}

int fn_R000507_713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int pivot_57 = (aux + st.buffer[1]) & 3;
  switch (pivot_57)
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

  int anchor_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_36) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_35 = local_arr[aux % 3];
  acc = (acc + (anchor_35 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000507_713_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000507_713_0 st_1 = {0};
  struct EventLog_R000507_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int bound_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_58_1)
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

  switch (bound_58_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_66_1) & 63;
  aux_2 = (aux_2 + offset_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_75_1 = local_arr_1[aux_1 % 3];
  int offset_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_75_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_58_1 == bound_58_2);
  assert(offset_66_1 == offset_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_75_1 == offset_75_2);
}

int fn_R000507_713_14(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000507_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int bound_58 = (aux + st.buffer[1]) & 3;
  switch (bound_58)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_66) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_75 = local_arr[aux % 3];
  acc = (acc + (offset_75 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000507_713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000507_713_2 st_1 = {0};
  struct CipherContext_R000507_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int quantum_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_51_1) & 63;
  aux_2 = (aux_2 + quantum_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_19_1 = local_arr_1[aux_1 % 3];
  int anchor_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_19_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_51_1 == quantum_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_19_1 == anchor_19_2);
}

int fn_R000507_713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000507_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int quantum_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_51) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_19 = local_arr[aux % 3];
  acc = (acc + (anchor_19 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000507_713_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000507_713_2 st_1 = {0};
  struct CipherContext_R000507_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int delta_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_32_1)
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

  switch (delta_32_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_32_1 == delta_32_2);
}

int fn_R000507_713_16(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000507_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int delta_32 = (aux + st.buffer[1]) & 3;
  switch (delta_32)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000507_713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st_1 = {0};
  struct SensorNode_R000507_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int metric_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_15_1) & 63;
  aux_2 = (aux_2 + metric_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_95_1 > 44)
  {
    acc_1 = ((acc_1 + (parity_95_1 * 2)) + 5) & 127;
    aux_1 ^= parity_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_95_2 > 44)
  {
    acc_2 = ((acc_2 + (parity_95_2 * 2)) + 5) & 127;
    aux_2 ^= parity_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_95_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_15_1 == metric_15_2);
  assert(parity_95_1 == parity_95_2);
}

int fn_R000507_713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000507_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int metric_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_15) & 63;
  acc ^= aux;
  int parity_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_95 > 44)
  {
    acc = ((acc + (parity_95 * 2)) + 5) & 127;
    aux ^= parity_95 & 15;
  }
  else
  {
    acc = ((acc - parity_95) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000507_713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000507_713_2 st_1 = {0};
  struct CipherContext_R000507_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int mask_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_21_1 > 45)
  {
    acc_1 = ((acc_1 + (mask_21_1 * 2)) + 5) & 127;
    aux_1 ^= mask_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_21_2 > 45)
  {
    acc_2 = ((acc_2 + (mask_21_2 * 2)) + 5) & 127;
    aux_2 ^= mask_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_21_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_63_1 = local_arr_1[aux_1 % 3];
  int mask_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_63_2 * 2)) & 127;
  int parity_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_48_1) & 63;
  aux_2 = (aux_2 + parity_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_21_1 == mask_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_63_1 == mask_63_2);
  assert(parity_48_1 == parity_48_2);
}

int fn_R000507_713_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000507_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int mask_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_21 > 45)
  {
    acc = ((acc + (mask_21 * 2)) + 5) & 127;
    aux ^= mask_21 & 15;
  }
  else
  {
    acc = ((acc - mask_21) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_63 = local_arr[aux % 3];
  acc = (acc + (mask_63 * 2)) & 127;
  int parity_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_48) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000507_713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000507_713_0 st_1 = {0};
  struct EventLog_R000507_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_12_1 > 16)
  {
    acc_1 = ((acc_1 + (factor_12_1 * 2)) + 5) & 127;
    aux_1 ^= factor_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_12_2 > 16)
  {
    acc_2 = ((acc_2 + (factor_12_2 * 2)) + 5) & 127;
    aux_2 ^= factor_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_12_1 == factor_12_2);
}

int fn_R000507_713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000507_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_12 > 16)
  {
    acc = ((acc + (factor_12 * 2)) + 5) & 127;
    aux ^= factor_12 & 15;
  }
  else
  {
    acc = ((acc - factor_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000507_713_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000507_713_2 st_1 = {0};
  struct CipherContext_R000507_713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int residue_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_88_1) & 63;
  aux_2 = (aux_2 + residue_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_88_1 == residue_88_2);
}

int fn_R000507_713_20(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000507_713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int residue_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_88) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000507_0_1;
  int sec_r000507_0_2;
  int sec_r000507_1_1;
  int sec_r000507_1_2;
  int sec_r000507_2_1;
  int sec_r000507_2_2;
  int sec_r000507_3_1;
  int sec_r000507_3_2;
  int sec_r000507_4_1;
  int sec_r000507_4_2;
  int sec_r000507_5_1;
  int sec_r000507_5_2;
  int sec_r000507_6_1;
  int sec_r000507_6_2;
  int sec_r000507_7_1;
  int sec_r000507_7_2;
  int sec_r000507_8_1;
  int sec_r000507_8_2;
  int sec_r000507_9_1;
  int sec_r000507_9_2;
  int sec_r000507_10_1;
  int sec_r000507_10_2;
  int sec_r000507_11_1;
  int sec_r000507_11_2;
  int sec_r000507_12_1;
  int sec_r000507_12_2;
  int sec_r000507_13_1;
  int sec_r000507_13_2;
  int sec_r000507_14_1;
  int sec_r000507_14_2;
  int sec_r000507_15_1;
  int sec_r000507_15_2;
  int sec_r000507_16_1;
  int sec_r000507_16_2;
  int sec_r000507_17_1;
  int sec_r000507_17_2;
  int pub_r000507_0_1;
  int pub_r000507_0_2;
  int pub_r000507_1_1;
  int pub_r000507_1_2;
  int pub_r000507_2_1;
  int pub_r000507_2_2;
  int pub_r000507_3_1;
  int pub_r000507_3_2;
  int pub_r000507_4_1;
  int pub_r000507_4_2;
  int pub_r000507_5_1;
  int pub_r000507_5_2;
  int pub_r000507_6_1;
  int pub_r000507_6_2;
  int pub_r000507_7_1;
  int pub_r000507_7_2;
  int pub_r000507_8_1;
  int pub_r000507_8_2;
  int pub_r000507_9_1;
  int pub_r000507_9_2;
  int pub_r000507_10_1;
  int pub_r000507_10_2;
  int pub_r000507_11_1;
  int pub_r000507_11_2;
  int pub_r000507_12_1;
  int pub_r000507_12_2;
  int pub_r000507_13_1;
  int pub_r000507_13_2;
  int pub_r000507_14_1;
  int pub_r000507_14_2;
  int pub_r000507_15_1;
  int pub_r000507_15_2;
  int pub_r000507_16_1;
  int pub_r000507_16_2;
  int pub_r000507_17_1;
  int pub_r000507_17_2;
  int pub_r000507_18_1;
  int pub_r000507_18_2;
  int pub_r000507_19_1;
  int pub_r000507_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000507_0_1 >= (-100)) && (pub_r000507_0_1 <= 100));
  __CPROVER_assume((pub_r000507_0_2 >= (-100)) && (pub_r000507_0_2 <= 100));
  __CPROVER_assume((pub_r000507_1_1 >= (-100)) && (pub_r000507_1_1 <= 100));
  __CPROVER_assume((pub_r000507_1_2 >= (-100)) && (pub_r000507_1_2 <= 100));
  __CPROVER_assume((pub_r000507_2_1 >= (-100)) && (pub_r000507_2_1 <= 100));
  __CPROVER_assume((pub_r000507_2_2 >= (-100)) && (pub_r000507_2_2 <= 100));
  __CPROVER_assume((pub_r000507_3_1 >= (-100)) && (pub_r000507_3_1 <= 100));
  __CPROVER_assume((pub_r000507_3_2 >= (-100)) && (pub_r000507_3_2 <= 100));
  __CPROVER_assume((pub_r000507_4_1 >= (-100)) && (pub_r000507_4_1 <= 100));
  __CPROVER_assume((pub_r000507_4_2 >= (-100)) && (pub_r000507_4_2 <= 100));
  __CPROVER_assume((pub_r000507_5_1 >= (-100)) && (pub_r000507_5_1 <= 100));
  __CPROVER_assume((pub_r000507_5_2 >= (-100)) && (pub_r000507_5_2 <= 100));
  __CPROVER_assume((pub_r000507_6_1 >= (-100)) && (pub_r000507_6_1 <= 100));
  __CPROVER_assume((pub_r000507_6_2 >= (-100)) && (pub_r000507_6_2 <= 100));
  __CPROVER_assume((pub_r000507_7_1 >= (-100)) && (pub_r000507_7_1 <= 100));
  __CPROVER_assume((pub_r000507_7_2 >= (-100)) && (pub_r000507_7_2 <= 100));
  __CPROVER_assume((pub_r000507_8_1 >= (-100)) && (pub_r000507_8_1 <= 100));
  __CPROVER_assume((pub_r000507_8_2 >= (-100)) && (pub_r000507_8_2 <= 100));
  __CPROVER_assume((pub_r000507_9_1 >= (-100)) && (pub_r000507_9_1 <= 100));
  __CPROVER_assume((pub_r000507_9_2 >= (-100)) && (pub_r000507_9_2 <= 100));
  __CPROVER_assume((pub_r000507_10_1 >= (-100)) && (pub_r000507_10_1 <= 100));
  __CPROVER_assume((pub_r000507_10_2 >= (-100)) && (pub_r000507_10_2 <= 100));
  __CPROVER_assume((pub_r000507_11_1 >= (-100)) && (pub_r000507_11_1 <= 100));
  __CPROVER_assume((pub_r000507_11_2 >= (-100)) && (pub_r000507_11_2 <= 100));
  __CPROVER_assume((pub_r000507_12_1 >= (-100)) && (pub_r000507_12_1 <= 100));
  __CPROVER_assume((pub_r000507_12_2 >= (-100)) && (pub_r000507_12_2 <= 100));
  __CPROVER_assume((pub_r000507_13_1 >= (-100)) && (pub_r000507_13_1 <= 100));
  __CPROVER_assume((pub_r000507_13_2 >= (-100)) && (pub_r000507_13_2 <= 100));
  __CPROVER_assume((pub_r000507_14_1 >= (-100)) && (pub_r000507_14_1 <= 100));
  __CPROVER_assume((pub_r000507_14_2 >= (-100)) && (pub_r000507_14_2 <= 100));
  __CPROVER_assume((pub_r000507_15_1 >= (-100)) && (pub_r000507_15_1 <= 100));
  __CPROVER_assume((pub_r000507_15_2 >= (-100)) && (pub_r000507_15_2 <= 100));
  __CPROVER_assume((pub_r000507_16_1 >= (-100)) && (pub_r000507_16_1 <= 100));
  __CPROVER_assume((pub_r000507_16_2 >= (-100)) && (pub_r000507_16_2 <= 100));
  __CPROVER_assume((pub_r000507_17_1 >= (-100)) && (pub_r000507_17_1 <= 100));
  __CPROVER_assume((pub_r000507_17_2 >= (-100)) && (pub_r000507_17_2 <= 100));
  __CPROVER_assume((pub_r000507_18_1 >= (-100)) && (pub_r000507_18_1 <= 100));
  __CPROVER_assume((pub_r000507_18_2 >= (-100)) && (pub_r000507_18_2 <= 100));
  __CPROVER_assume((pub_r000507_19_1 >= (-100)) && (pub_r000507_19_1 <= 100));
  __CPROVER_assume((pub_r000507_19_2 >= (-100)) && (pub_r000507_19_2 <= 100));
  __CPROVER_assume((sec_r000507_0_1 >= 0) && (sec_r000507_0_1 <= 255));
  __CPROVER_assume((sec_r000507_0_2 >= 0) && (sec_r000507_0_2 <= 255));
  __CPROVER_assume((sec_r000507_1_1 >= 0) && (sec_r000507_1_1 <= 255));
  __CPROVER_assume((sec_r000507_1_2 >= 0) && (sec_r000507_1_2 <= 255));
  __CPROVER_assume((sec_r000507_2_1 >= 0) && (sec_r000507_2_1 <= 255));
  __CPROVER_assume((sec_r000507_2_2 >= 0) && (sec_r000507_2_2 <= 255));
  __CPROVER_assume((sec_r000507_3_1 >= 0) && (sec_r000507_3_1 <= 255));
  __CPROVER_assume((sec_r000507_3_2 >= 0) && (sec_r000507_3_2 <= 255));
  __CPROVER_assume((sec_r000507_4_1 >= 0) && (sec_r000507_4_1 <= 255));
  __CPROVER_assume((sec_r000507_4_2 >= 0) && (sec_r000507_4_2 <= 255));
  __CPROVER_assume((sec_r000507_5_1 >= 0) && (sec_r000507_5_1 <= 255));
  __CPROVER_assume((sec_r000507_5_2 >= 0) && (sec_r000507_5_2 <= 255));
  __CPROVER_assume((sec_r000507_6_1 >= 0) && (sec_r000507_6_1 <= 255));
  __CPROVER_assume((sec_r000507_6_2 >= 0) && (sec_r000507_6_2 <= 255));
  __CPROVER_assume((sec_r000507_7_1 >= 0) && (sec_r000507_7_1 <= 255));
  __CPROVER_assume((sec_r000507_7_2 >= 0) && (sec_r000507_7_2 <= 255));
  __CPROVER_assume((sec_r000507_8_1 >= 0) && (sec_r000507_8_1 <= 255));
  __CPROVER_assume((sec_r000507_8_2 >= 0) && (sec_r000507_8_2 <= 255));
  __CPROVER_assume((sec_r000507_9_1 >= 0) && (sec_r000507_9_1 <= 255));
  __CPROVER_assume((sec_r000507_9_2 >= 0) && (sec_r000507_9_2 <= 255));
  __CPROVER_assume((sec_r000507_10_1 >= 0) && (sec_r000507_10_1 <= 255));
  __CPROVER_assume((sec_r000507_10_2 >= 0) && (sec_r000507_10_2 <= 255));
  __CPROVER_assume((sec_r000507_11_1 >= 0) && (sec_r000507_11_1 <= 255));
  __CPROVER_assume((sec_r000507_11_2 >= 0) && (sec_r000507_11_2 <= 255));
  __CPROVER_assume((sec_r000507_12_1 >= 0) && (sec_r000507_12_1 <= 255));
  __CPROVER_assume((sec_r000507_12_2 >= 0) && (sec_r000507_12_2 <= 255));
  __CPROVER_assume((sec_r000507_13_1 >= 0) && (sec_r000507_13_1 <= 255));
  __CPROVER_assume((sec_r000507_13_2 >= 0) && (sec_r000507_13_2 <= 255));
  __CPROVER_assume((sec_r000507_14_1 >= 0) && (sec_r000507_14_1 <= 255));
  __CPROVER_assume((sec_r000507_14_2 >= 0) && (sec_r000507_14_2 <= 255));
  __CPROVER_assume((sec_r000507_15_1 >= 0) && (sec_r000507_15_1 <= 255));
  __CPROVER_assume((sec_r000507_15_2 >= 0) && (sec_r000507_15_2 <= 255));
  __CPROVER_assume((sec_r000507_16_1 >= 0) && (sec_r000507_16_1 <= 255));
  __CPROVER_assume((sec_r000507_16_2 >= 0) && (sec_r000507_16_2 <= 255));
  __CPROVER_assume((sec_r000507_17_1 >= 0) && (sec_r000507_17_1 <= 255));
  __CPROVER_assume((sec_r000507_17_2 >= 0) && (sec_r000507_17_2 <= 255));
  struct EventLog_R000507_713_0 st_var_0_1 = {0};
  struct EventLog_R000507_713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000507_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000507_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000507_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000507_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000507_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000507_0_2 + 7) & 15;
  struct SensorNode_R000507_713_1 st_var_1_1 = {0};
  struct SensorNode_R000507_713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000507_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000507_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000507_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000507_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000507_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000507_0_2 + 9) & 15;
  struct CipherContext_R000507_713_2 st_var_2_1 = {0};
  struct CipherContext_R000507_713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000507_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000507_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000507_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000507_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000507_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000507_0_2 + 11) & 15;
  union ColorPixel_R000507_713_0 u_var_1;
  union ColorPixel_R000507_713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = ((st_var_0_1.buffer[0] * 2) + 16) & 63;
  int stage_v_3_2 = ((st_var_0_2.buffer[0] * 2) + 16) & 63;
  if (stage_v_3_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_3_1) - 5) & 255;
    if (stage_v_3_1 > 39)
    {
      chk_sum_1 ^= stage_v_3_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_3_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_3_2) - 5) & 255;
    if (stage_v_3_2 > 39)
    {
      chk_sum_2 ^= stage_v_3_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_4_1 = ((st_var_1_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_1_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 37)
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
  if (stage_v_4_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 37)
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
  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_6_1 = ((stage_v_6_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_6_2 = ((stage_v_6_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  int stage_v_9_1 = table_1[1];
  int stage_v_9_2 = table_2[1];
  table_1[1] = (table_1[2] + 19) & 63;
  table_2[1] = (table_2[2] + 19) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 15) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 15) & 15;
  int stage_v_14_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_14_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= stage_v_14_1;
  chk_sum_2 ^= stage_v_14_2;
  int stage_v_15_1 = (st_var_0_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_0_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 19) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = ((st_var_1_1.buffer[1] * 2) + 64) & 63;
  int stage_v_19_2 = ((st_var_1_2.buffer[1] * 2) + 64) & 63;
  if (stage_v_19_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_19_1) - 5) & 255;
    if (stage_v_19_1 > 51)
    {
      chk_sum_1 ^= stage_v_19_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_19_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_19_2) - 5) & 255;
    if (stage_v_19_2 > 51)
    {
      chk_sum_2 ^= stage_v_19_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 21) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 21) & 15;
  int stage_v_20_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_20_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= stage_v_20_1;
  chk_sum_2 ^= stage_v_20_2;
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 23) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 23) & 15;
  int stage_v_22_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_22_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= stage_v_22_1;
  chk_sum_2 ^= stage_v_22_2;
  int stage_v_23_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (28 & 31);
  int stage_v_23_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (28 & 31);
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= (stage_v_23_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_23_2 << 1) & 127;
  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
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
  int stage_v_28_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_28_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_29_1 = (st_var_2_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_2_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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

  int stage_v_30_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_30_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_31_1 = table_1[3];
  int stage_v_31_2 = table_2[3];
  table_1[3] = (table_1[0] + 63) & 63;
  table_2[3] = (table_2[0] + 63) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((st_var_2_1.buffer[2] * 2) + 103) & 63;
  int stage_v_32_2 = ((st_var_2_2.buffer[2] * 2) + 103) & 63;
  if (stage_v_32_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_32_1) - 5) & 255;
    if (stage_v_32_1 > 43)
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
  if (stage_v_32_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_32_2) - 5) & 255;
    if (stage_v_32_2 > 43)
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
  int stage_v_33_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (38 & 31);
  int stage_v_33_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (38 & 31);
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= (stage_v_33_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_33_2 << 1) & 127;
  int stage_v_34_1 = ((st_var_1_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_1_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 29)
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
  if (stage_v_34_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 29)
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
  int stage_v_35_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (40 & 31);
  int stage_v_35_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (40 & 31);
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= (stage_v_35_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_35_2 << 1) & 127;
  int stage_v_36_1 = (st_var_0_1.buffer[0] ^ 39) & 3;
  int stage_v_36_2 = (st_var_0_2.buffer[0] ^ 39) & 3;
  switch (stage_v_36_1)
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

  switch (stage_v_36_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  int stage_v_38_1 = ((st_var_2_1.buffer[2] * 2) + 121) & 63;
  int stage_v_38_2 = ((st_var_2_2.buffer[2] * 2) + 121) & 63;
  if (stage_v_38_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_38_1) - 5) & 255;
    if (stage_v_38_1 > 47)
    {
      chk_sum_1 ^= stage_v_38_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_38_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_38_2) - 5) & 255;
    if (stage_v_38_2 > 47)
    {
      chk_sum_2 ^= stage_v_38_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_39_1 = ((st_var_0_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_0_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 28)
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
  if (stage_v_39_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 28)
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
  int stage_v_40_1 = (st_var_1_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_1_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (46 & 31);
  int stage_v_41_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (46 & 31);
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= (stage_v_41_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_41_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 43) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 43) & 15;
  int stage_v_42_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_42_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= stage_v_42_1;
  chk_sum_2 ^= stage_v_42_2;
  int stage_v_43_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (48 & 31);
  int stage_v_43_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (48 & 31);
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= (stage_v_43_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_43_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 45) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 45) & 15;
  int stage_v_44_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_44_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= stage_v_44_1;
  chk_sum_2 ^= stage_v_44_2;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_45_1 = ((stage_v_45_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
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
  int stage_v_47_1 = (st_var_2_1.buffer[0] ^ 50) & 3;
  int stage_v_47_2 = (st_var_2_2.buffer[0] ^ 50) & 3;
  switch (stage_v_47_1)
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

  switch (stage_v_47_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 49) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 49) & 15;
  int stage_v_48_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_48_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= stage_v_48_1;
  chk_sum_2 ^= stage_v_48_2;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_49_1 = ((stage_v_49_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_49_2 = ((stage_v_49_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 51) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 51) & 15;
  int stage_v_50_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_50_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= stage_v_50_1;
  chk_sum_2 ^= stage_v_50_2;
  int stage_v_51_1 = (st_var_0_1.buffer[0] ^ 54) & 3;
  int stage_v_51_2 = (st_var_0_2.buffer[0] ^ 54) & 3;
  switch (stage_v_51_1)
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

  switch (stage_v_51_2)
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

  int stage_v_52_1 = table_1[0];
  int stage_v_52_2 = table_2[0];
  table_1[0] = (table_1[1] + 105) & 63;
  table_2[0] = (table_2[1] + 105) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 54) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 54) & 15;
  int stage_v_53_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_53_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= stage_v_53_1;
  chk_sum_2 ^= stage_v_53_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 55) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 55) & 15;
  int stage_v_54_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_54_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= stage_v_54_1;
  chk_sum_2 ^= stage_v_54_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 56) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 56) & 15;
  int stage_v_55_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_55_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= stage_v_55_1;
  chk_sum_2 ^= stage_v_55_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 57) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 57) & 15;
  int stage_v_56_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_56_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= stage_v_56_1;
  chk_sum_2 ^= stage_v_56_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 58) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 58) & 15;
  int stage_v_57_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_57_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= stage_v_57_1;
  chk_sum_2 ^= stage_v_57_2;
  int stage_v_58_1 = table_1[2];
  int stage_v_58_2 = table_2[2];
  table_1[2] = (table_1[3] + 117) & 63;
  table_2[2] = (table_2[3] + 117) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_59_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_59_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_59_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_60_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (65 & 31);
  int stage_v_60_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (65 & 31);
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= (stage_v_60_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_60_2 << 1) & 127;
  int stage_v_61_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_61_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_61_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_61_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_62_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_62_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_62_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_62_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_63_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (68 & 31);
  int stage_v_63_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (68 & 31);
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= (stage_v_63_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_63_2 << 1) & 127;
  int stage_v_64_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (69 & 31);
  int stage_v_64_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (69 & 31);
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= (stage_v_64_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_64_2 << 1) & 127;
  int stage_v_65_1 = table_1[1];
  int stage_v_65_2 = table_2[1];
  table_1[1] = (table_1[2] + 131) & 63;
  table_2[1] = (table_2[2] + 131) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_66_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_66_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_66_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000507_13_1 & 1) != 0)
  {
    if ((sec_r000507_11_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000507_10_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000507_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000507_10_1 + 7) & 127;
  }
  if ((sec_r000507_13_2 & 1) != 0)
  {
    if ((sec_r000507_11_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000507_10_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000507_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000507_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000507_14_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000507_3_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000507_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000507_3_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000507_14_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000507_3_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000507_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000507_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000507_7_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000507_19_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000507_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000507_19_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000507_7_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000507_19_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000507_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000507_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000507_6_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000507_7_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000507_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000507_7_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000507_6_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000507_7_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000507_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000507_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000507_5_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000507_3_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000507_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000507_3_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000507_5_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000507_3_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000507_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000507_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000507_4_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000507_10_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000507_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000507_10_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000507_4_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000507_10_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000507_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000507_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000507_2_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000507_1_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000507_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000507_1_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000507_2_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000507_1_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000507_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000507_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((sec_r000507_17_1 & 1) != 0)
  {
    if ((sec_r000507_15_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000507_8_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000507_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000507_8_1 + 7) & 127;
  }
  if ((sec_r000507_17_2 & 1) != 0)
  {
    if ((sec_r000507_15_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000507_8_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000507_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000507_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000507_10_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000507_10_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000507_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000507_10_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000507_10_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000507_10_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000507_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000507_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000507_11_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000507_17_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000507_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000507_17_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000507_11_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000507_17_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000507_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000507_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000507_16_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000507_8_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000507_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000507_8_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000507_16_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000507_8_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000507_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000507_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000507_6_1 & 1) != 0)
  {
    if ((sec_r000507_2_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000507_19_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000507_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000507_19_1 + 7) & 127;
  }
  if ((sec_r000507_6_2 & 1) != 0)
  {
    if ((sec_r000507_2_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000507_19_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000507_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000507_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000507_8_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000507_13_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000507_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000507_13_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000507_8_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000507_13_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000507_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000507_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000507_7_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000507_19_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000507_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000507_19_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000507_7_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000507_19_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000507_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000507_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000507_14_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000507_1_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000507_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000507_1_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000507_14_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000507_1_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000507_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000507_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000507_0_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000507_11_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000507_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000507_11_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000507_0_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000507_11_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000507_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000507_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000507_8_1 & 1) != 0)
  {
    if ((sec_r000507_15_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000507_17_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000507_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000507_17_1 + 7) & 127;
  }
  if ((sec_r000507_8_2 & 1) != 0)
  {
    if ((sec_r000507_15_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000507_17_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000507_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000507_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000507_12_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000507_1_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000507_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000507_1_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000507_12_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000507_1_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000507_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000507_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000507_0_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000507_16_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000507_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000507_16_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000507_0_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000507_16_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000507_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000507_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000507_6_1 & 1) != 0)
  {
    if ((sec_r000507_0_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000507_19_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000507_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000507_19_1 + 7) & 127;
  }
  if ((sec_r000507_6_2 & 1) != 0)
  {
    if ((sec_r000507_0_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000507_19_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000507_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000507_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000507_13_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000507_16_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000507_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000507_16_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000507_13_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000507_16_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000507_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000507_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000507_13_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000507_10_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000507_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000507_10_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000507_13_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000507_10_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000507_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000507_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000507_11_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000507_5_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000507_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000507_5_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000507_11_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000507_5_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000507_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000507_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000507_9_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000507_5_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000507_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000507_5_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000507_9_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000507_5_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000507_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000507_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000507_13_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000507_10_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000507_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000507_10_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000507_13_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000507_10_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000507_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000507_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000507_10_1 & 1) != 0)
  {
    if ((sec_r000507_9_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000507_11_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000507_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000507_11_1 + 7) & 127;
  }
  if ((sec_r000507_10_2 & 1) != 0)
  {
    if ((sec_r000507_9_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000507_11_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000507_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000507_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000507_1_1 & 1) != 0)
  {
    if ((sec_r000507_12_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000507_0_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000507_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000507_0_1 + 7) & 127;
  }
  if ((sec_r000507_1_2 & 1) != 0)
  {
    if ((sec_r000507_12_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000507_0_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000507_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000507_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000507_15_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000507_1_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000507_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000507_1_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000507_15_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000507_1_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000507_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000507_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000507_16_1 & 1) != 0)
  {
    if ((sec_r000507_16_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000507_5_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000507_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000507_5_1 + 7) & 127;
  }
  if ((sec_r000507_16_2 & 1) != 0)
  {
    if ((sec_r000507_16_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000507_5_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000507_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000507_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000507_4_1 & 1) != 0)
  {
    if ((sec_r000507_6_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000507_15_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000507_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000507_15_1 + 7) & 127;
  }
  if ((sec_r000507_4_2 & 1) != 0)
  {
    if ((sec_r000507_6_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000507_15_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000507_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000507_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000507_2_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000507_0_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000507_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000507_0_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000507_2_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000507_0_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000507_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000507_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000507_12_1 & 1) != 0)
  {
    if ((sec_r000507_2_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000507_8_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000507_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000507_8_1 + 7) & 127;
  }
  if ((sec_r000507_12_2 & 1) != 0)
  {
    if ((sec_r000507_2_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000507_8_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000507_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000507_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000507_8_1 & 1) != 0)
  {
    if ((sec_r000507_5_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000507_2_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000507_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000507_2_1 + 7) & 127;
  }
  if ((sec_r000507_8_2 & 1) != 0)
  {
    if ((sec_r000507_5_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000507_2_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000507_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000507_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000507_2_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000507_9_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000507_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000507_9_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000507_2_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000507_9_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000507_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000507_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000507_0_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000507_14_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000507_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000507_14_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000507_0_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000507_14_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000507_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000507_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000507_8_1 & 1) != 0)
  {
    if ((sec_r000507_17_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000507_0_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000507_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000507_0_1 + 7) & 127;
  }
  if ((sec_r000507_8_2 & 1) != 0)
  {
    if ((sec_r000507_17_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000507_0_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000507_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000507_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000507_12_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000507_0_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000507_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000507_0_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000507_12_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000507_0_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000507_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000507_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000507_5_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000507_5_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000507_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000507_5_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000507_5_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000507_5_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000507_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000507_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000507_9_1 & 1) != 0)
  {
    if ((sec_r000507_6_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000507_8_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000507_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000507_8_1 + 7) & 127;
  }
  if ((sec_r000507_9_2 & 1) != 0)
  {
    if ((sec_r000507_6_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000507_8_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000507_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000507_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000507_14_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000507_11_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000507_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000507_11_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000507_14_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000507_11_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000507_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000507_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000507_16_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000507_4_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000507_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000507_4_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000507_16_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000507_4_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000507_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000507_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000507_2_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000507_18_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000507_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000507_18_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000507_2_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000507_18_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000507_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000507_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000507_13_1 & 1) != 0)
  {
    if ((sec_r000507_10_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000507_10_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000507_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000507_10_1 + 7) & 127;
  }
  if ((sec_r000507_13_2 & 1) != 0)
  {
    if ((sec_r000507_10_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000507_10_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000507_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000507_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000507_17_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000507_10_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000507_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000507_10_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000507_17_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000507_10_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000507_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000507_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000507_7_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000507_4_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000507_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000507_4_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000507_7_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000507_4_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000507_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000507_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000507_8_1 & 1) != 0)
  {
    if ((sec_r000507_15_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000507_19_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000507_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000507_19_1 + 7) & 127;
  }
  if ((sec_r000507_8_2 & 1) != 0)
  {
    if ((sec_r000507_15_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000507_19_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000507_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000507_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000507_3_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000507_0_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000507_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000507_0_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000507_3_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000507_0_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000507_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000507_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000507_13_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000507_3_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000507_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000507_3_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000507_13_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000507_3_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000507_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000507_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000507_8_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000507_0_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000507_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000507_0_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000507_8_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000507_0_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000507_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000507_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000507_13_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000507_10_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000507_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000507_10_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000507_13_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000507_10_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000507_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000507_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000507_15_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000507_5_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000507_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000507_5_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000507_15_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000507_5_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000507_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000507_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000507_5_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000507_4_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000507_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000507_4_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000507_5_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000507_4_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000507_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000507_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000507_7_1 & 1) != 0)
  {
    if ((sec_r000507_5_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000507_12_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000507_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000507_12_1 + 7) & 127;
  }
  if ((sec_r000507_7_2 & 1) != 0)
  {
    if ((sec_r000507_5_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000507_12_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000507_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000507_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000507_0_1 & 1) != 0)
  {
    if ((sec_r000507_12_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000507_18_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000507_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000507_18_1 + 7) & 127;
  }
  if ((sec_r000507_0_2 & 1) != 0)
  {
    if ((sec_r000507_12_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000507_18_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000507_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000507_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000507_3_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000507_2_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000507_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000507_2_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000507_3_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000507_2_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000507_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000507_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000507_1_1 & 1) != 0)
  {
    if ((sec_r000507_2_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000507_10_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000507_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000507_10_1 + 7) & 127;
  }
  if ((sec_r000507_1_2 & 1) != 0)
  {
    if ((sec_r000507_2_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000507_10_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000507_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000507_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000507_16_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000507_1_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000507_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000507_1_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000507_16_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000507_1_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000507_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000507_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000507_6_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000507_10_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000507_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000507_10_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000507_6_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000507_10_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000507_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000507_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000507_9_1 & 1) != 0)
  {
    if ((sec_r000507_1_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000507_12_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000507_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000507_12_1 + 7) & 127;
  }
  if ((sec_r000507_9_2 & 1) != 0)
  {
    if ((sec_r000507_1_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000507_12_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000507_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000507_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000507_5_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000507_19_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000507_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000507_19_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000507_5_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000507_19_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000507_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000507_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000507_13_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000507_6_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000507_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000507_6_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000507_13_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000507_6_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000507_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000507_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000507_4_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000507_4_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000507_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000507_4_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000507_4_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000507_4_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000507_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000507_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000507_11_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000507_13_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000507_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000507_13_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000507_11_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000507_13_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000507_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000507_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000507_14_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000507_9_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000507_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000507_9_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000507_14_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000507_9_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000507_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000507_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000507_12_1 & 1) != 0)
  {
    if ((sec_r000507_17_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000507_10_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000507_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000507_10_1 + 7) & 127;
  }
  if ((sec_r000507_12_2 & 1) != 0)
  {
    if ((sec_r000507_17_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000507_10_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000507_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000507_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000507_13_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000507_8_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000507_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000507_8_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000507_13_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000507_8_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000507_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000507_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000507_9_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000507_4_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000507_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000507_4_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000507_9_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000507_4_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000507_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000507_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000507_12_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000507_10_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000507_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000507_10_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000507_12_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000507_10_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000507_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000507_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000507_1_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000507_2_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000507_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000507_2_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000507_1_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000507_2_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000507_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000507_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000507_17_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000507_0_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000507_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000507_0_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000507_17_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000507_0_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000507_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000507_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((sec_r000507_9_1 & 1) != 0)
  {
    if ((sec_r000507_11_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000507_16_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000507_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000507_16_1 + 7) & 127;
  }
  if ((sec_r000507_9_2 & 1) != 0)
  {
    if ((sec_r000507_11_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000507_16_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000507_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000507_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((sec_r000507_14_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000507_12_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000507_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000507_12_1 + 7) & 127;
  }
  if ((stage_v_125_2 & 1) != 0)
  {
    if ((sec_r000507_14_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000507_12_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000507_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000507_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((sec_r000507_15_1 & 1) != 0)
  {
    if ((sec_r000507_2_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000507_8_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000507_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000507_8_1 + 7) & 127;
  }
  if ((sec_r000507_15_2 & 1) != 0)
  {
    if ((sec_r000507_2_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000507_8_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000507_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000507_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000507_5_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000507_17_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000507_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000507_17_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000507_5_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000507_17_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000507_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000507_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((sec_r000507_0_1 & 1) != 0)
  {
    if ((sec_r000507_14_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000507_9_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000507_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000507_9_1 + 7) & 127;
  }
  if ((sec_r000507_0_2 & 1) != 0)
  {
    if ((sec_r000507_14_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000507_9_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000507_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000507_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((sec_r000507_0_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000507_4_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000507_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000507_4_1 + 7) & 127;
  }
  if ((stage_v_113_2 & 1) != 0)
  {
    if ((sec_r000507_0_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000507_4_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000507_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000507_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000507_3_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000507_0_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000507_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000507_0_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000507_3_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000507_0_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000507_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000507_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((sec_r000507_12_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000507_0_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000507_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000507_0_1 + 7) & 127;
  }
  if ((stage_v_134_2 & 1) != 0)
  {
    if ((sec_r000507_12_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000507_0_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000507_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000507_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_141_1 & 1) != 0)
  {
    if ((sec_r000507_15_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000507_7_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000507_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000507_7_1 + 7) & 127;
  }
  if ((stage_v_141_2 & 1) != 0)
  {
    if ((sec_r000507_15_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000507_7_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000507_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000507_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((sec_r000507_2_1 & 1) != 0)
  {
    if ((sec_r000507_14_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000507_15_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000507_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000507_15_1 + 7) & 127;
  }
  if ((sec_r000507_2_2 & 1) != 0)
  {
    if ((sec_r000507_14_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000507_15_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000507_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000507_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((sec_r000507_8_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000507_7_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000507_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000507_7_1 + 7) & 127;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((sec_r000507_8_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000507_7_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000507_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000507_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000507_15_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000507_10_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000507_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000507_10_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000507_15_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000507_10_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000507_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000507_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((sec_r000507_13_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000507_6_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000507_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000507_6_1 + 7) & 127;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((sec_r000507_13_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000507_6_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000507_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000507_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((sec_r000507_16_1 & 1) != 0)
  {
    if ((sec_r000507_12_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000507_14_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000507_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000507_14_1 + 7) & 127;
  }
  if ((sec_r000507_16_2 & 1) != 0)
  {
    if ((sec_r000507_12_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000507_14_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000507_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000507_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((sec_r000507_14_1 & 1) != 0)
  {
    if ((sec_r000507_1_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000507_7_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000507_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000507_7_1 + 7) & 127;
  }
  if ((sec_r000507_14_2 & 1) != 0)
  {
    if ((sec_r000507_1_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000507_7_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000507_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000507_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000507_11_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000507_3_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000507_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000507_3_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000507_11_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000507_3_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000507_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000507_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000507_9_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000507_16_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000507_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000507_16_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000507_9_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000507_16_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000507_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000507_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000507_4_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000507_12_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000507_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000507_12_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000507_4_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000507_12_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000507_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000507_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((sec_r000507_15_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000507_4_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000507_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000507_4_1 + 7) & 127;
  }
  if ((stage_v_140_2 & 1) != 0)
  {
    if ((sec_r000507_15_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000507_4_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000507_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000507_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000507_10_1 != sec_r000507_10_2);
  __CPROVER_assume(pub_r000507_6_1 == pub_r000507_6_2);
  __CPROVER_assume(sec_r000507_4_1 != sec_r000507_4_2);
  __CPROVER_assume(sec_r000507_0_1 != sec_r000507_0_2);
  __CPROVER_assume(pub_r000507_9_1 == pub_r000507_9_2);
  __CPROVER_assume(pub_r000507_15_1 == pub_r000507_15_2);
  __CPROVER_assume(sec_r000507_9_1 != sec_r000507_9_2);
  __CPROVER_assume(pub_r000507_12_1 == pub_r000507_12_2);
  __CPROVER_assume(sec_r000507_7_1 != sec_r000507_7_2);
  __CPROVER_assume(pub_r000507_7_1 == pub_r000507_7_2);
  __CPROVER_assume(pub_r000507_18_1 == pub_r000507_18_2);
  __CPROVER_assume(sec_r000507_2_1 != sec_r000507_2_2);
  __CPROVER_assume(sec_r000507_1_1 != sec_r000507_1_2);
  __CPROVER_assume(sec_r000507_11_1 != sec_r000507_11_2);
  __CPROVER_assume(sec_r000507_3_1 != sec_r000507_3_2);
  __CPROVER_assume(pub_r000507_11_1 == pub_r000507_11_2);
  __CPROVER_assume(sec_r000507_17_1 != sec_r000507_17_2);
  __CPROVER_assume(sec_r000507_6_1 != sec_r000507_6_2);
  __CPROVER_assume(sec_r000507_5_1 != sec_r000507_5_2);
  __CPROVER_assume(pub_r000507_3_1 == pub_r000507_3_2);
  __CPROVER_assume(sec_r000507_13_1 != sec_r000507_13_2);
  __CPROVER_assume(pub_r000507_0_1 == pub_r000507_0_2);
  __CPROVER_assume(pub_r000507_10_1 == pub_r000507_10_2);
  __CPROVER_assume(pub_r000507_4_1 == pub_r000507_4_2);
  __CPROVER_assume(sec_r000507_14_1 != sec_r000507_14_2);
  __CPROVER_assume(sec_r000507_15_1 != sec_r000507_15_2);
  __CPROVER_assume(pub_r000507_19_1 == pub_r000507_19_2);
  __CPROVER_assume(pub_r000507_5_1 == pub_r000507_5_2);
  __CPROVER_assume(sec_r000507_8_1 != sec_r000507_8_2);
  __CPROVER_assume(sec_r000507_16_1 != sec_r000507_16_2);
  __CPROVER_assume(pub_r000507_14_1 == pub_r000507_14_2);
  __CPROVER_assume(pub_r000507_1_1 == pub_r000507_1_2);
  __CPROVER_assume(pub_r000507_16_1 == pub_r000507_16_2);
  __CPROVER_assume(sec_r000507_12_1 != sec_r000507_12_2);
  __CPROVER_assume(pub_r000507_2_1 == pub_r000507_2_2);
  __CPROVER_assume(pub_r000507_8_1 == pub_r000507_8_2);
  __CPROVER_assume(pub_r000507_17_1 == pub_r000507_17_2);
  __CPROVER_assume(pub_r000507_13_1 == pub_r000507_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.tag == st_var_2_2.tag);
  assert(st_var_2_1.nonce == st_var_2_2.nonce);
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
}


