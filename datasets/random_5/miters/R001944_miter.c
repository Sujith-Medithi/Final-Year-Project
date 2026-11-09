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
struct FilterState_R001944_4413_0
{
  short gain_db;
  short cutoff;
  short damping;
  int buffer[3];
};
struct SensorNode_R001944_4413_1
{
  short status;
  unsigned char offset;
  int calib;
  unsigned char threshold;
  int buffer[3];
};
union PacketPayload_R001944_4413_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001944_4413_1
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
void fn_R001944_4413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st_1 = {0};
  struct FilterState_R001944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_36_1 = local_arr_1[aux_1 % 3];
  int sample_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_36_2 * 2)) & 127;
  int factor_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_71_1)
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

  switch (factor_71_2)
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
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_36_1 == sample_36_2);
  assert(factor_71_1 == factor_71_2);
}

int fn_R001944_4413_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_36 = local_arr[aux % 3];
  acc = (acc + (sample_36 * 2)) & 127;
  int factor_71 = (aux + st.buffer[1]) & 3;
  switch (factor_71)
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

void fn_R001944_4413_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st_1 = {0};
  struct FilterState_R001944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int bound_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_78_1)
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

  switch (bound_78_2)
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

  int parity_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_80_1) & 63;
  aux_2 = (aux_2 + parity_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_58_1 = 0;
  int residue_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_58_1 = ((residue_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_58_2 = ((residue_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_58_1) & 127;
    acc_2 = (acc_2 + residue_58_2) & 127;
  }

  int threshold_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_24_1 > 34)
  {
    acc_1 = ((acc_1 + (threshold_24_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_24_2 > 34)
  {
    acc_2 = ((acc_2 + (threshold_24_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_24_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_78_1 == bound_78_2);
  assert(parity_80_1 == parity_80_2);
  assert(residue_58_1 == residue_58_2);
  assert(threshold_24_1 == threshold_24_2);
}

int fn_R001944_4413_1(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int bound_78 = (aux + st.buffer[1]) & 3;
  switch (bound_78)
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

  int parity_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_80) & 63;
  acc ^= aux;
  int residue_58 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_58 = ((residue_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_58) & 127;
  }

  int threshold_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_24 > 34)
  {
    acc = ((acc + (threshold_24 * 2)) + 5) & 127;
    aux ^= threshold_24 & 15;
  }
  else
  {
    acc = ((acc - threshold_24) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001944_4413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st_1 = {0};
  struct FilterState_R001944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int cursor_24_1 = 0;
  int cursor_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_24_1 = ((cursor_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_24_2 = ((cursor_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_24_1) & 127;
    acc_2 = (acc_2 + cursor_24_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_72_1 = local_arr_1[aux_1 % 3];
  int factor_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_72_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_24_1 == cursor_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_72_1 == factor_72_2);
}

int fn_R001944_4413_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int cursor_24 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_24 = ((cursor_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_24) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int factor_72 = local_arr[aux % 3];
  acc = (acc + (factor_72 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001944_4413_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st_1 = {0};
  struct SensorNode_R001944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int coefficient_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_53_1 > 35)
  {
    acc_1 = ((acc_1 + (coefficient_53_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_53_2 > 35)
  {
    acc_2 = ((acc_2 + (coefficient_53_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_53_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_75_1)
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

  switch (cursor_75_2)
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

  int scale_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_16_1) & 63;
  aux_2 = (aux_2 + scale_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_53_1 == coefficient_53_2);
  assert(cursor_75_1 == cursor_75_2);
  assert(scale_16_1 == scale_16_2);
}

int fn_R001944_4413_3(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int coefficient_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_53 > 35)
  {
    acc = ((acc + (coefficient_53 * 2)) + 5) & 127;
    aux ^= coefficient_53 & 15;
  }
  else
  {
    acc = ((acc - coefficient_53) + 11) & 127;
    aux += 3;
  }
  int cursor_75 = (aux + st.buffer[1]) & 3;
  switch (cursor_75)
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

  int scale_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_16) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001944_4413_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st_1 = {0};
  struct SensorNode_R001944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int weight_86_1 = 0;
  int weight_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_86_1 = ((weight_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_86_2 = ((weight_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_86_1) & 127;
    acc_2 = (acc_2 + weight_86_2) & 127;
  }

  int index_reg_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_34_1)
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

  switch (index_reg_34_2)
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

  int window_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_75_1 > 28)
  {
    acc_1 = ((acc_1 + (window_75_1 * 2)) + 5) & 127;
    aux_1 ^= window_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_75_2 > 28)
  {
    acc_2 = ((acc_2 + (window_75_2 * 2)) + 5) & 127;
    aux_2 ^= window_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_75_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_86_1 == weight_86_2);
  assert(index_reg_34_1 == index_reg_34_2);
  assert(window_75_1 == window_75_2);
}

int fn_R001944_4413_4(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int weight_86 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_86 = ((weight_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_86) & 127;
  }

  int index_reg_34 = (aux + st.buffer[1]) & 3;
  switch (index_reg_34)
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

  int window_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_75 > 28)
  {
    acc = ((acc + (window_75 * 2)) + 5) & 127;
    aux ^= window_75 & 15;
  }
  else
  {
    acc = ((acc - window_75) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001944_4413_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st_1 = {0};
  struct FilterState_R001944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int metric_33_1 = 0;
  int metric_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_33_1 = ((metric_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_33_2 = ((metric_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_33_1) & 127;
    acc_2 = (acc_2 + metric_33_2) & 127;
  }

  int cursor_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_55_1 > 20)
  {
    acc_1 = ((acc_1 + (cursor_55_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_55_2 > 20)
  {
    acc_2 = ((acc_2 + (cursor_55_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_55_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_33_1 == metric_33_2);
  assert(cursor_55_1 == cursor_55_2);
}

int fn_R001944_4413_5(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int metric_33 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_33 = ((metric_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_33) & 127;
  }

  int cursor_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_55 > 20)
  {
    acc = ((acc + (cursor_55 * 2)) + 5) & 127;
    aux ^= cursor_55 & 15;
  }
  else
  {
    acc = ((acc - cursor_55) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001944_4413_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st_1 = {0};
  struct SensorNode_R001944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int stride_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_14_1)
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

  switch (stride_14_2)
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

  int checksum_95_1 = 0;
  int checksum_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_95_1 = ((checksum_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_95_2 = ((checksum_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_95_1) & 127;
    acc_2 = (acc_2 + checksum_95_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_74_1 > 25)
  {
    acc_1 = ((acc_1 + (stride_74_1 * 2)) + 5) & 127;
    aux_1 ^= stride_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_74_2 > 25)
  {
    acc_2 = ((acc_2 + (stride_74_2 * 2)) + 5) & 127;
    aux_2 ^= stride_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_74_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_14_1 == stride_14_2);
  assert(checksum_95_1 == checksum_95_2);
  assert(stride_74_1 == stride_74_2);
}

int fn_R001944_4413_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int stride_14 = (aux + st.buffer[1]) & 3;
  switch (stride_14)
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

  int checksum_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_95 = ((checksum_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_95) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_74 > 25)
  {
    acc = ((acc + (stride_74 * 2)) + 5) & 127;
    aux ^= stride_74 & 15;
  }
  else
  {
    acc = ((acc - stride_74) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001944_4413_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st_1 = {0};
  struct SensorNode_R001944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_99_1 = local_arr_1[aux_1 % 3];
  int quotient_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_99_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_24_1)
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

  switch (tracker_24_2)
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

  int parity_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_74_1) & 63;
  aux_2 = (aux_2 + parity_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_99_1 == quotient_99_2);
  assert(tracker_24_1 == tracker_24_2);
  assert(parity_74_1 == parity_74_2);
}

int fn_R001944_4413_7(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int quotient_99 = local_arr[aux % 3];
  acc = (acc + (quotient_99 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_24 = (aux + st.buffer[1]) & 3;
  switch (tracker_24)
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

  int parity_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_74) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001944_4413_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st_1 = {0};
  struct FilterState_R001944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_28_1 = local_arr_1[aux_1 % 3];
  int segment_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_28_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_28_1 == segment_28_2);
}

int fn_R001944_4413_8(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int segment_28 = local_arr[aux % 3];
  acc = (acc + (segment_28 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001944_4413_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st_1 = {0};
  struct FilterState_R001944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_25_1 = local_arr_1[aux_1 % 3];
  int quantum_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_25_2 * 2)) & 127;
  int residue_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_18_1) & 63;
  aux_2 = (aux_2 + residue_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_93_1 > 50)
  {
    acc_1 = ((acc_1 + (segment_93_1 * 2)) + 5) & 127;
    aux_1 ^= segment_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_93_2 > 50)
  {
    acc_2 = ((acc_2 + (segment_93_2 * 2)) + 5) & 127;
    aux_2 ^= segment_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_93_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_25_1 == quantum_25_2);
  assert(residue_18_1 == residue_18_2);
  assert(segment_93_1 == segment_93_2);
}

int fn_R001944_4413_9(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int quantum_25 = local_arr[aux % 3];
  acc = (acc + (quantum_25 * 2)) & 127;
  int residue_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_18) & 63;
  acc ^= aux;
  int segment_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_93 > 50)
  {
    acc = ((acc + (segment_93 * 2)) + 5) & 127;
    aux ^= segment_93 & 15;
  }
  else
  {
    acc = ((acc - segment_93) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001944_4413_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st_1 = {0};
  struct FilterState_R001944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int damping_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_85_1)
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

  switch (damping_85_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_48_1 = 0;
  int tracker_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_48_1 = ((tracker_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_48_2 = ((tracker_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_48_1) & 127;
    acc_2 = (acc_2 + tracker_48_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_19_1 = local_arr_1[aux_1 % 3];
  int tracker_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_19_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_85_1 == damping_85_2);
  assert(tracker_48_1 == tracker_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_19_1 == tracker_19_2);
}

int fn_R001944_4413_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int damping_85 = (aux + st.buffer[1]) & 3;
  switch (damping_85)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_48 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_48 = ((tracker_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_48) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tracker_19 = local_arr[aux % 3];
  acc = (acc + (tracker_19 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001944_4413_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st_1 = {0};
  struct FilterState_R001944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_30_1)
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

  switch (coefficient_30_2)
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
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_30_1 == coefficient_30_2);
}

int fn_R001944_4413_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_30 = (aux + st.buffer[1]) & 3;
  switch (coefficient_30)
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

void fn_R001944_4413_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st_1 = {0};
  struct FilterState_R001944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int threshold_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_50_1 > 21)
  {
    acc_1 = ((acc_1 + (threshold_50_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_50_2 > 21)
  {
    acc_2 = ((acc_2 + (threshold_50_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_59_1 = local_arr_1[aux_1 % 3];
  int cursor_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_59_2 * 2)) & 127;
  int tally_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_65_1) & 63;
  aux_2 = (aux_2 + tally_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_85_1 = 0;
  int bound_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_85_1 = ((bound_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_85_2 = ((bound_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_85_1) & 127;
    acc_2 = (acc_2 + bound_85_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_50_1 == threshold_50_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_59_1 == cursor_59_2);
  assert(tally_65_1 == tally_65_2);
  assert(bound_85_1 == bound_85_2);
}

int fn_R001944_4413_12(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int threshold_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_50 > 21)
  {
    acc = ((acc + (threshold_50 * 2)) + 5) & 127;
    aux ^= threshold_50 & 15;
  }
  else
  {
    acc = ((acc - threshold_50) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_59 = local_arr[aux % 3];
  acc = (acc + (cursor_59 * 2)) & 127;
  int tally_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_65) & 63;
  acc ^= aux;
  int bound_85 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_85 = ((bound_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_85) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001944_4413_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st_1 = {0};
  struct SensorNode_R001944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int cursor_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_44_1 > 20)
  {
    acc_1 = ((acc_1 + (cursor_44_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_44_2 > 20)
  {
    acc_2 = ((acc_2 + (cursor_44_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_73_1)
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

  switch (margin_73_2)
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

  int scale_22_1 = 0;
  int scale_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_22_1 = ((scale_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_22_2 = ((scale_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_22_1) & 127;
    acc_2 = (acc_2 + scale_22_2) & 127;
  }

  int tally_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_59_1) & 63;
  aux_2 = (aux_2 + tally_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_44_1 == cursor_44_2);
  assert(margin_73_1 == margin_73_2);
  assert(scale_22_1 == scale_22_2);
  assert(tally_59_1 == tally_59_2);
}

int fn_R001944_4413_13(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int cursor_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_44 > 20)
  {
    acc = ((acc + (cursor_44 * 2)) + 5) & 127;
    aux ^= cursor_44 & 15;
  }
  else
  {
    acc = ((acc - cursor_44) + 11) & 127;
    aux += 3;
  }
  int margin_73 = (aux + st.buffer[1]) & 3;
  switch (margin_73)
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

  int scale_22 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_22 = ((scale_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_22) & 127;
  }

  int tally_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_59) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001944_4413_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st_1 = {0};
  struct FilterState_R001944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_95_1)
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

  switch (stride_95_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_95_1 == stride_95_2);
}

int fn_R001944_4413_14(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_95 = (aux + st.buffer[1]) & 3;
  switch (stride_95)
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

void fn_R001944_4413_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st_1 = {0};
  struct SensorNode_R001944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int bound_19_1 = 0;
  int bound_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_19_1 = ((bound_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_19_2 = ((bound_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_19_1) & 127;
    acc_2 = (acc_2 + bound_19_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_19_1 == bound_19_2);
}

int fn_R001944_4413_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int bound_19 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_19 = ((bound_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_19) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001944_4413_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st_1 = {0};
  struct SensorNode_R001944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int stride_21_1 = 0;
  int stride_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_21_1 = ((stride_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_21_2 = ((stride_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_21_1) & 127;
    acc_2 = (acc_2 + stride_21_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_43_1 = local_arr_1[aux_1 % 3];
  int tracker_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_43_2 * 2)) & 127;
  int damping_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_70_1)
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

  switch (damping_70_2)
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

  int stride_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_61_1) & 63;
  aux_2 = (aux_2 + stride_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_21_1 == stride_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_43_1 == tracker_43_2);
  assert(damping_70_1 == damping_70_2);
  assert(stride_61_1 == stride_61_2);
}

int fn_R001944_4413_16(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int stride_21 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_21 = ((stride_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_21) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tracker_43 = local_arr[aux % 3];
  acc = (acc + (tracker_43 * 2)) & 127;
  int damping_70 = (aux + st.buffer[1]) & 3;
  switch (damping_70)
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

  int stride_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_61) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001944_4413_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st_1 = {0};
  struct SensorNode_R001944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_85_1 = local_arr_1[aux_1 % 3];
  int threshold_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_85_2 * 2)) & 127;
  int tally_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_52_1) & 63;
  aux_2 = (aux_2 + tally_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_85_1 == threshold_85_2);
  assert(tally_52_1 == tally_52_2);
}

int fn_R001944_4413_17(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int threshold_85 = local_arr[aux % 3];
  acc = (acc + (threshold_85 * 2)) & 127;
  int tally_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_52) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001944_4413_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st_1 = {0};
  struct SensorNode_R001944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_32_1 = local_arr_1[aux_1 % 3];
  int segment_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_32_2 * 2)) & 127;
  int anchor_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_69_1 > 34)
  {
    acc_1 = ((acc_1 + (anchor_69_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_69_2 > 34)
  {
    acc_2 = ((acc_2 + (anchor_69_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_55_1) & 63;
  aux_2 = (aux_2 + delta_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_33_1 = 0;
  int quantum_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_33_1 = ((quantum_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_33_2 = ((quantum_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_33_1) & 127;
    acc_2 = (acc_2 + quantum_33_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_32_1 == segment_32_2);
  assert(anchor_69_1 == anchor_69_2);
  assert(delta_55_1 == delta_55_2);
  assert(quantum_33_1 == quantum_33_2);
}

int fn_R001944_4413_18(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int segment_32 = local_arr[aux % 3];
  acc = (acc + (segment_32 * 2)) & 127;
  int anchor_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_69 > 34)
  {
    acc = ((acc + (anchor_69 * 2)) + 5) & 127;
    aux ^= anchor_69 & 15;
  }
  else
  {
    acc = ((acc - anchor_69) + 11) & 127;
    aux += 3;
  }
  int delta_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_55) & 63;
  acc ^= aux;
  int quantum_33 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_33 = ((quantum_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_33) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001944_4413_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st_1 = {0};
  struct SensorNode_R001944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int quantum_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_95_1)
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

  switch (quantum_95_2)
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

  int margin_82_1 = 0;
  int margin_82_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_82_1 = ((margin_82_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_82_2 = ((margin_82_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_82_1) & 127;
    acc_2 = (acc_2 + margin_82_2) & 127;
  }

  int stride_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_35_1 > 47)
  {
    acc_1 = ((acc_1 + (stride_35_1 * 2)) + 5) & 127;
    aux_1 ^= stride_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_35_2 > 47)
  {
    acc_2 = ((acc_2 + (stride_35_2 * 2)) + 5) & 127;
    aux_2 ^= stride_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_35_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_18_1) & 63;
  aux_2 = (aux_2 + margin_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_95_1 == quantum_95_2);
  assert(margin_82_1 == margin_82_2);
  assert(stride_35_1 == stride_35_2);
  assert(margin_18_1 == margin_18_2);
}

int fn_R001944_4413_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int quantum_95 = (aux + st.buffer[1]) & 3;
  switch (quantum_95)
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

  int margin_82 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_82 = ((margin_82 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_82) & 127;
  }

  int stride_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_35 > 47)
  {
    acc = ((acc + (stride_35 * 2)) + 5) & 127;
    aux ^= stride_35 & 15;
  }
  else
  {
    acc = ((acc - stride_35) + 11) & 127;
    aux += 3;
  }
  int margin_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_18) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001944_4413_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st_1 = {0};
  struct SensorNode_R001944_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_44_1 = local_arr_1[aux_1 % 3];
  int margin_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_44_2 * 2)) & 127;
  int mask_48_1 = 0;
  int mask_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_48_1 = ((mask_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_48_2 = ((mask_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_48_1) & 127;
    acc_2 = (acc_2 + mask_48_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_44_1 == margin_44_2);
  assert(mask_48_1 == mask_48_2);
}

int fn_R001944_4413_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001944_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int margin_44 = local_arr[aux % 3];
  acc = (acc + (margin_44 * 2)) & 127;
  int mask_48 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_48 = ((mask_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_48) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001944_4413_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st_1 = {0};
  struct FilterState_R001944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int offset_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_57_1) & 63;
  aux_2 = (aux_2 + offset_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_57_1 == offset_57_2);
}

int fn_R001944_4413_21(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int offset_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_57) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001944_4413_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st_1 = {0};
  struct FilterState_R001944_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int delta_95_1 = 0;
  int delta_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_95_1 = ((delta_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_95_2 = ((delta_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_95_1) & 127;
    acc_2 = (acc_2 + delta_95_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_47_1)
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

  switch (stride_47_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.damping == st_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_95_1 == delta_95_2);
  assert(stride_47_1 == stride_47_2);
}

int fn_R001944_4413_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001944_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int delta_95 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_95 = ((delta_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_95) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_47 = (aux + st.buffer[1]) & 3;
  switch (stride_47)
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

void main()
{
  int sec_r001944_0_1;
  int sec_r001944_0_2;
  int sec_r001944_1_1;
  int sec_r001944_1_2;
  int sec_r001944_2_1;
  int sec_r001944_2_2;
  int sec_r001944_3_1;
  int sec_r001944_3_2;
  int sec_r001944_4_1;
  int sec_r001944_4_2;
  int sec_r001944_5_1;
  int sec_r001944_5_2;
  int sec_r001944_6_1;
  int sec_r001944_6_2;
  int sec_r001944_7_1;
  int sec_r001944_7_2;
  int sec_r001944_8_1;
  int sec_r001944_8_2;
  int sec_r001944_9_1;
  int sec_r001944_9_2;
  int sec_r001944_10_1;
  int sec_r001944_10_2;
  int sec_r001944_11_1;
  int sec_r001944_11_2;
  int sec_r001944_12_1;
  int sec_r001944_12_2;
  int sec_r001944_13_1;
  int sec_r001944_13_2;
  int sec_r001944_14_1;
  int sec_r001944_14_2;
  int sec_r001944_15_1;
  int sec_r001944_15_2;
  int sec_r001944_16_1;
  int sec_r001944_16_2;
  int sec_r001944_17_1;
  int sec_r001944_17_2;
  int sec_r001944_18_1;
  int sec_r001944_18_2;
  int sec_r001944_19_1;
  int sec_r001944_19_2;
  int sec_r001944_20_1;
  int sec_r001944_20_2;
  int sec_r001944_21_1;
  int sec_r001944_21_2;
  int pub_r001944_0_1;
  int pub_r001944_0_2;
  int pub_r001944_1_1;
  int pub_r001944_1_2;
  int pub_r001944_2_1;
  int pub_r001944_2_2;
  int pub_r001944_3_1;
  int pub_r001944_3_2;
  int pub_r001944_4_1;
  int pub_r001944_4_2;
  int pub_r001944_5_1;
  int pub_r001944_5_2;
  int pub_r001944_6_1;
  int pub_r001944_6_2;
  int pub_r001944_7_1;
  int pub_r001944_7_2;
  int pub_r001944_8_1;
  int pub_r001944_8_2;
  int pub_r001944_9_1;
  int pub_r001944_9_2;
  int pub_r001944_10_1;
  int pub_r001944_10_2;
  int pub_r001944_11_1;
  int pub_r001944_11_2;
  int pub_r001944_12_1;
  int pub_r001944_12_2;
  int pub_r001944_13_1;
  int pub_r001944_13_2;
  int pub_r001944_14_1;
  int pub_r001944_14_2;
  int pub_r001944_15_1;
  int pub_r001944_15_2;
  int pub_r001944_16_1;
  int pub_r001944_16_2;
  int pub_r001944_17_1;
  int pub_r001944_17_2;
  int pub_r001944_18_1;
  int pub_r001944_18_2;
  int pub_r001944_19_1;
  int pub_r001944_19_2;
  int pub_r001944_20_1;
  int pub_r001944_20_2;
  int pub_r001944_21_1;
  int pub_r001944_21_2;
  int pub_r001944_22_1;
  int pub_r001944_22_2;
  int pub_r001944_23_1;
  int pub_r001944_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001944_0_1 >= (-100)) && (pub_r001944_0_1 <= 100));
  __CPROVER_assume((pub_r001944_0_2 >= (-100)) && (pub_r001944_0_2 <= 100));
  __CPROVER_assume((pub_r001944_1_1 >= (-100)) && (pub_r001944_1_1 <= 100));
  __CPROVER_assume((pub_r001944_1_2 >= (-100)) && (pub_r001944_1_2 <= 100));
  __CPROVER_assume((pub_r001944_2_1 >= (-100)) && (pub_r001944_2_1 <= 100));
  __CPROVER_assume((pub_r001944_2_2 >= (-100)) && (pub_r001944_2_2 <= 100));
  __CPROVER_assume((pub_r001944_3_1 >= (-100)) && (pub_r001944_3_1 <= 100));
  __CPROVER_assume((pub_r001944_3_2 >= (-100)) && (pub_r001944_3_2 <= 100));
  __CPROVER_assume((pub_r001944_4_1 >= (-100)) && (pub_r001944_4_1 <= 100));
  __CPROVER_assume((pub_r001944_4_2 >= (-100)) && (pub_r001944_4_2 <= 100));
  __CPROVER_assume((pub_r001944_5_1 >= (-100)) && (pub_r001944_5_1 <= 100));
  __CPROVER_assume((pub_r001944_5_2 >= (-100)) && (pub_r001944_5_2 <= 100));
  __CPROVER_assume((pub_r001944_6_1 >= (-100)) && (pub_r001944_6_1 <= 100));
  __CPROVER_assume((pub_r001944_6_2 >= (-100)) && (pub_r001944_6_2 <= 100));
  __CPROVER_assume((pub_r001944_7_1 >= (-100)) && (pub_r001944_7_1 <= 100));
  __CPROVER_assume((pub_r001944_7_2 >= (-100)) && (pub_r001944_7_2 <= 100));
  __CPROVER_assume((pub_r001944_8_1 >= (-100)) && (pub_r001944_8_1 <= 100));
  __CPROVER_assume((pub_r001944_8_2 >= (-100)) && (pub_r001944_8_2 <= 100));
  __CPROVER_assume((pub_r001944_9_1 >= (-100)) && (pub_r001944_9_1 <= 100));
  __CPROVER_assume((pub_r001944_9_2 >= (-100)) && (pub_r001944_9_2 <= 100));
  __CPROVER_assume((pub_r001944_10_1 >= (-100)) && (pub_r001944_10_1 <= 100));
  __CPROVER_assume((pub_r001944_10_2 >= (-100)) && (pub_r001944_10_2 <= 100));
  __CPROVER_assume((pub_r001944_11_1 >= (-100)) && (pub_r001944_11_1 <= 100));
  __CPROVER_assume((pub_r001944_11_2 >= (-100)) && (pub_r001944_11_2 <= 100));
  __CPROVER_assume((pub_r001944_12_1 >= (-100)) && (pub_r001944_12_1 <= 100));
  __CPROVER_assume((pub_r001944_12_2 >= (-100)) && (pub_r001944_12_2 <= 100));
  __CPROVER_assume((pub_r001944_13_1 >= (-100)) && (pub_r001944_13_1 <= 100));
  __CPROVER_assume((pub_r001944_13_2 >= (-100)) && (pub_r001944_13_2 <= 100));
  __CPROVER_assume((pub_r001944_14_1 >= (-100)) && (pub_r001944_14_1 <= 100));
  __CPROVER_assume((pub_r001944_14_2 >= (-100)) && (pub_r001944_14_2 <= 100));
  __CPROVER_assume((pub_r001944_15_1 >= (-100)) && (pub_r001944_15_1 <= 100));
  __CPROVER_assume((pub_r001944_15_2 >= (-100)) && (pub_r001944_15_2 <= 100));
  __CPROVER_assume((pub_r001944_16_1 >= (-100)) && (pub_r001944_16_1 <= 100));
  __CPROVER_assume((pub_r001944_16_2 >= (-100)) && (pub_r001944_16_2 <= 100));
  __CPROVER_assume((pub_r001944_17_1 >= (-100)) && (pub_r001944_17_1 <= 100));
  __CPROVER_assume((pub_r001944_17_2 >= (-100)) && (pub_r001944_17_2 <= 100));
  __CPROVER_assume((pub_r001944_18_1 >= (-100)) && (pub_r001944_18_1 <= 100));
  __CPROVER_assume((pub_r001944_18_2 >= (-100)) && (pub_r001944_18_2 <= 100));
  __CPROVER_assume((pub_r001944_19_1 >= (-100)) && (pub_r001944_19_1 <= 100));
  __CPROVER_assume((pub_r001944_19_2 >= (-100)) && (pub_r001944_19_2 <= 100));
  __CPROVER_assume((pub_r001944_20_1 >= (-100)) && (pub_r001944_20_1 <= 100));
  __CPROVER_assume((pub_r001944_20_2 >= (-100)) && (pub_r001944_20_2 <= 100));
  __CPROVER_assume((pub_r001944_21_1 >= (-100)) && (pub_r001944_21_1 <= 100));
  __CPROVER_assume((pub_r001944_21_2 >= (-100)) && (pub_r001944_21_2 <= 100));
  __CPROVER_assume((pub_r001944_22_1 >= (-100)) && (pub_r001944_22_1 <= 100));
  __CPROVER_assume((pub_r001944_22_2 >= (-100)) && (pub_r001944_22_2 <= 100));
  __CPROVER_assume((pub_r001944_23_1 >= (-100)) && (pub_r001944_23_1 <= 100));
  __CPROVER_assume((pub_r001944_23_2 >= (-100)) && (pub_r001944_23_2 <= 100));
  __CPROVER_assume((sec_r001944_0_1 >= 0) && (sec_r001944_0_1 <= 255));
  __CPROVER_assume((sec_r001944_0_2 >= 0) && (sec_r001944_0_2 <= 255));
  __CPROVER_assume((sec_r001944_1_1 >= 0) && (sec_r001944_1_1 <= 255));
  __CPROVER_assume((sec_r001944_1_2 >= 0) && (sec_r001944_1_2 <= 255));
  __CPROVER_assume((sec_r001944_2_1 >= 0) && (sec_r001944_2_1 <= 255));
  __CPROVER_assume((sec_r001944_2_2 >= 0) && (sec_r001944_2_2 <= 255));
  __CPROVER_assume((sec_r001944_3_1 >= 0) && (sec_r001944_3_1 <= 255));
  __CPROVER_assume((sec_r001944_3_2 >= 0) && (sec_r001944_3_2 <= 255));
  __CPROVER_assume((sec_r001944_4_1 >= 0) && (sec_r001944_4_1 <= 255));
  __CPROVER_assume((sec_r001944_4_2 >= 0) && (sec_r001944_4_2 <= 255));
  __CPROVER_assume((sec_r001944_5_1 >= 0) && (sec_r001944_5_1 <= 255));
  __CPROVER_assume((sec_r001944_5_2 >= 0) && (sec_r001944_5_2 <= 255));
  __CPROVER_assume((sec_r001944_6_1 >= 0) && (sec_r001944_6_1 <= 255));
  __CPROVER_assume((sec_r001944_6_2 >= 0) && (sec_r001944_6_2 <= 255));
  __CPROVER_assume((sec_r001944_7_1 >= 0) && (sec_r001944_7_1 <= 255));
  __CPROVER_assume((sec_r001944_7_2 >= 0) && (sec_r001944_7_2 <= 255));
  __CPROVER_assume((sec_r001944_8_1 >= 0) && (sec_r001944_8_1 <= 255));
  __CPROVER_assume((sec_r001944_8_2 >= 0) && (sec_r001944_8_2 <= 255));
  __CPROVER_assume((sec_r001944_9_1 >= 0) && (sec_r001944_9_1 <= 255));
  __CPROVER_assume((sec_r001944_9_2 >= 0) && (sec_r001944_9_2 <= 255));
  __CPROVER_assume((sec_r001944_10_1 >= 0) && (sec_r001944_10_1 <= 255));
  __CPROVER_assume((sec_r001944_10_2 >= 0) && (sec_r001944_10_2 <= 255));
  __CPROVER_assume((sec_r001944_11_1 >= 0) && (sec_r001944_11_1 <= 255));
  __CPROVER_assume((sec_r001944_11_2 >= 0) && (sec_r001944_11_2 <= 255));
  __CPROVER_assume((sec_r001944_12_1 >= 0) && (sec_r001944_12_1 <= 255));
  __CPROVER_assume((sec_r001944_12_2 >= 0) && (sec_r001944_12_2 <= 255));
  __CPROVER_assume((sec_r001944_13_1 >= 0) && (sec_r001944_13_1 <= 255));
  __CPROVER_assume((sec_r001944_13_2 >= 0) && (sec_r001944_13_2 <= 255));
  __CPROVER_assume((sec_r001944_14_1 >= 0) && (sec_r001944_14_1 <= 255));
  __CPROVER_assume((sec_r001944_14_2 >= 0) && (sec_r001944_14_2 <= 255));
  __CPROVER_assume((sec_r001944_15_1 >= 0) && (sec_r001944_15_1 <= 255));
  __CPROVER_assume((sec_r001944_15_2 >= 0) && (sec_r001944_15_2 <= 255));
  __CPROVER_assume((sec_r001944_16_1 >= 0) && (sec_r001944_16_1 <= 255));
  __CPROVER_assume((sec_r001944_16_2 >= 0) && (sec_r001944_16_2 <= 255));
  __CPROVER_assume((sec_r001944_17_1 >= 0) && (sec_r001944_17_1 <= 255));
  __CPROVER_assume((sec_r001944_17_2 >= 0) && (sec_r001944_17_2 <= 255));
  __CPROVER_assume((sec_r001944_18_1 >= 0) && (sec_r001944_18_1 <= 255));
  __CPROVER_assume((sec_r001944_18_2 >= 0) && (sec_r001944_18_2 <= 255));
  __CPROVER_assume((sec_r001944_19_1 >= 0) && (sec_r001944_19_1 <= 255));
  __CPROVER_assume((sec_r001944_19_2 >= 0) && (sec_r001944_19_2 <= 255));
  __CPROVER_assume((sec_r001944_20_1 >= 0) && (sec_r001944_20_1 <= 255));
  __CPROVER_assume((sec_r001944_20_2 >= 0) && (sec_r001944_20_2 <= 255));
  __CPROVER_assume((sec_r001944_21_1 >= 0) && (sec_r001944_21_1 <= 255));
  __CPROVER_assume((sec_r001944_21_2 >= 0) && (sec_r001944_21_2 <= 255));
  struct FilterState_R001944_4413_0 st_var_0_1 = {0};
  struct FilterState_R001944_4413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001944_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001944_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001944_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001944_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001944_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001944_0_2 + 7) & 15;
  struct SensorNode_R001944_4413_1 st_var_1_1 = {0};
  struct SensorNode_R001944_4413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001944_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001944_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001944_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001944_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001944_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001944_0_2 + 9) & 15;
  union PacketPayload_R001944_4413_0 u_var_1;
  union PacketPayload_R001944_4413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001944_4413_0(sec_r001944_0_1, pub_r001944_1_1, pub_r001944_2_1, pub_r001944_3_1, pub_r001944_4_1);
  int helper_flow_0_2 = fn_R001944_4413_0(sec_r001944_0_2, pub_r001944_1_2, pub_r001944_2_2, pub_r001944_3_2, pub_r001944_4_2);
  fn_R001944_4413_0_2(sec_r001944_0_1, pub_r001944_1_1, pub_r001944_2_1, pub_r001944_3_1, pub_r001944_4_1, sec_r001944_0_2, pub_r001944_1_2, pub_r001944_2_2, pub_r001944_3_2, pub_r001944_4_2);
  int helper_flow_1_1 = fn_R001944_4413_1(sec_r001944_1_1, sec_r001944_2_1, pub_r001944_3_1);
  int helper_flow_1_2 = fn_R001944_4413_1(sec_r001944_1_2, sec_r001944_2_2, pub_r001944_3_2);
  fn_R001944_4413_1_2(sec_r001944_1_1, sec_r001944_2_1, pub_r001944_3_1, sec_r001944_1_2, sec_r001944_2_2, pub_r001944_3_2);
  int helper_flow_2_1 = fn_R001944_4413_2(sec_r001944_2_1, pub_r001944_3_1, pub_r001944_4_1, pub_r001944_5_1);
  int helper_flow_2_2 = fn_R001944_4413_2(sec_r001944_2_2, pub_r001944_3_2, pub_r001944_4_2, pub_r001944_5_2);
  fn_R001944_4413_2_2(sec_r001944_2_1, pub_r001944_3_1, pub_r001944_4_1, pub_r001944_5_1, sec_r001944_2_2, pub_r001944_3_2, pub_r001944_4_2, pub_r001944_5_2);
  int helper_flow_3_1 = fn_R001944_4413_3(sec_r001944_3_1, pub_r001944_4_1);
  int helper_flow_3_2 = fn_R001944_4413_3(sec_r001944_3_2, pub_r001944_4_2);
  fn_R001944_4413_3_2(sec_r001944_3_1, pub_r001944_4_1, sec_r001944_3_2, pub_r001944_4_2);
  int helper_flow_4_1 = fn_R001944_4413_4(sec_r001944_4_1, pub_r001944_5_1, pub_r001944_6_1);
  int helper_flow_4_2 = fn_R001944_4413_4(sec_r001944_4_2, pub_r001944_5_2, pub_r001944_6_2);
  fn_R001944_4413_4_2(sec_r001944_4_1, pub_r001944_5_1, pub_r001944_6_1, sec_r001944_4_2, pub_r001944_5_2, pub_r001944_6_2);
  int helper_flow_5_1 = fn_R001944_4413_5(sec_r001944_5_1, pub_r001944_6_1);
  int helper_flow_5_2 = fn_R001944_4413_5(sec_r001944_5_2, pub_r001944_6_2);
  fn_R001944_4413_5_2(sec_r001944_5_1, pub_r001944_6_1, sec_r001944_5_2, pub_r001944_6_2);
  int helper_flow_6_1 = fn_R001944_4413_6(sec_r001944_6_1, sec_r001944_7_1, pub_r001944_8_1, pub_r001944_9_1, pub_r001944_10_1);
  int helper_flow_6_2 = fn_R001944_4413_6(sec_r001944_6_2, sec_r001944_7_2, pub_r001944_8_2, pub_r001944_9_2, pub_r001944_10_2);
  fn_R001944_4413_6_2(sec_r001944_6_1, sec_r001944_7_1, pub_r001944_8_1, pub_r001944_9_1, pub_r001944_10_1, sec_r001944_6_2, sec_r001944_7_2, pub_r001944_8_2, pub_r001944_9_2, pub_r001944_10_2);
  int helper_flow_7_1 = fn_R001944_4413_7(sec_r001944_7_1, sec_r001944_8_1);
  int helper_flow_7_2 = fn_R001944_4413_7(sec_r001944_7_2, sec_r001944_8_2);
  fn_R001944_4413_7_2(sec_r001944_7_1, sec_r001944_8_1, sec_r001944_7_2, sec_r001944_8_2);
  int helper_flow_8_1 = fn_R001944_4413_8(sec_r001944_8_1, sec_r001944_9_1);
  int helper_flow_8_2 = fn_R001944_4413_8(sec_r001944_8_2, sec_r001944_9_2);
  fn_R001944_4413_8_2(sec_r001944_8_1, sec_r001944_9_1, sec_r001944_8_2, sec_r001944_9_2);
  int stage_v_0_1 = (((sec_r001944_7_1 * 3) + pub_r001944_22_1) + 43) & 127;
  int stage_v_0_2 = (((sec_r001944_7_2 * 3) + pub_r001944_22_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = (((sec_r001944_10_1 * 3) + pub_r001944_13_1) + 30) & 127;
  int stage_v_1_2 = (((sec_r001944_10_2 * 3) + pub_r001944_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = ((pub_r001944_19_1 * 2) + 37) & 63;
  int stage_v_2_2 = ((pub_r001944_19_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001944_19_1 * 2) + 6) & 63;
  int stage_v_3_2 = ((pub_r001944_19_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (((helper_flow_1_1 * 3) + pub_r001944_13_1) + 35) & 127;
  int stage_v_4_2 = (((helper_flow_1_2 * 3) + pub_r001944_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = (((sec_r001944_1_1 * 3) + pub_r001944_1_1) + 28) & 127;
  int stage_v_5_2 = (((sec_r001944_1_2 * 3) + pub_r001944_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = ((pub_r001944_18_1 * 2) + 48) & 63;
  int stage_v_6_2 = ((pub_r001944_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((helper_flow_8_1 * 3) + pub_r001944_4_1) + 38) & 127;
  int stage_v_7_2 = (((helper_flow_8_2 * 3) + pub_r001944_4_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = (((stage_v_0_1 * 3) + pub_r001944_10_1) + 16) & 127;
  int stage_v_8_2 = (((stage_v_0_2 * 3) + pub_r001944_10_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = (((sec_r001944_17_1 * 3) + pub_r001944_17_1) + 24) & 127;
  int stage_v_9_2 = (((sec_r001944_17_2 * 3) + pub_r001944_17_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = (((sec_r001944_19_1 * 3) + pub_r001944_14_1) + 32) & 127;
  int stage_v_10_2 = (((sec_r001944_19_2 * 3) + pub_r001944_14_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = (((sec_r001944_7_1 * 3) + pub_r001944_6_1) + 9) & 127;
  int stage_v_11_2 = (((sec_r001944_7_2 * 3) + pub_r001944_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = ((pub_r001944_11_1 * 2) + 36) & 63;
  int stage_v_12_2 = ((pub_r001944_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001944_13_1 * 2) + 6) & 63;
  int stage_v_13_2 = ((pub_r001944_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001944_1_1 * 2) + 46) & 63;
  int stage_v_14_2 = ((pub_r001944_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (((sec_r001944_11_1 * 3) + pub_r001944_4_1) + 29) & 127;
  int stage_v_15_2 = (((sec_r001944_11_2 * 3) + pub_r001944_4_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = (((sec_r001944_0_1 * 3) + pub_r001944_13_1) + 41) & 127;
  int stage_v_16_2 = (((sec_r001944_0_2 * 3) + pub_r001944_13_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = (((sec_r001944_14_1 * 3) + pub_r001944_17_1) + 12) & 127;
  int stage_v_17_2 = (((sec_r001944_14_2 * 3) + pub_r001944_17_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = (((sec_r001944_20_1 * 3) + pub_r001944_5_1) + 15) & 127;
  int stage_v_18_2 = (((sec_r001944_20_2 * 3) + pub_r001944_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = (((sec_r001944_16_1 * 3) + pub_r001944_4_1) + 5) & 127;
  int stage_v_19_2 = (((sec_r001944_16_2 * 3) + pub_r001944_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = ((pub_r001944_1_1 * 2) + 27) & 63;
  int stage_v_20_2 = ((pub_r001944_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (((sec_r001944_20_1 * 3) + pub_r001944_23_1) + 35) & 127;
  int stage_v_21_2 = (((sec_r001944_20_2 * 3) + pub_r001944_23_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = (((stage_v_17_1 * 3) + pub_r001944_17_1) + 39) & 127;
  int stage_v_22_2 = (((stage_v_17_2 * 3) + pub_r001944_17_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = (((stage_v_10_1 * 3) + pub_r001944_9_1) + 5) & 127;
  int stage_v_23_2 = (((stage_v_10_2 * 3) + pub_r001944_9_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((stage_v_9_1 * 3) + pub_r001944_7_1) + 3) & 127;
  int stage_v_24_2 = (((stage_v_9_2 * 3) + pub_r001944_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = (((sec_r001944_8_1 * 3) + pub_r001944_14_1) + 37) & 127;
  int stage_v_25_2 = (((sec_r001944_8_2 * 3) + pub_r001944_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = (((sec_r001944_18_1 * 3) + pub_r001944_4_1) + 34) & 127;
  int stage_v_26_2 = (((sec_r001944_18_2 * 3) + pub_r001944_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = (((stage_v_9_1 * 3) + pub_r001944_8_1) + 42) & 127;
  int stage_v_27_2 = (((stage_v_9_2 * 3) + pub_r001944_8_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_27_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_27_2 * 2)) & 255;
  int stage_v_28_1 = ((pub_r001944_6_1 * 2) + 49) & 63;
  int stage_v_28_2 = ((pub_r001944_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = (((sec_r001944_12_1 * 3) + pub_r001944_19_1) + 35) & 127;
  int stage_v_29_2 = (((sec_r001944_12_2 * 3) + pub_r001944_19_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = (((stage_v_5_1 * 3) + pub_r001944_23_1) + 8) & 127;
  int stage_v_30_2 = (((stage_v_5_2 * 3) + pub_r001944_23_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = ((pub_r001944_7_1 * 2) + 31) & 63;
  int stage_v_31_2 = ((pub_r001944_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (((stage_v_7_1 * 3) + pub_r001944_2_1) + 39) & 127;
  int stage_v_32_2 = (((stage_v_7_2 * 3) + pub_r001944_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = ((pub_r001944_1_1 * 2) + 36) & 63;
  int stage_v_33_2 = ((pub_r001944_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (((stage_v_8_1 * 3) + pub_r001944_22_1) + 21) & 127;
  int stage_v_34_2 = (((stage_v_8_2 * 3) + pub_r001944_22_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = ((pub_r001944_9_1 * 2) + 47) & 63;
  int stage_v_35_2 = ((pub_r001944_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((stage_v_30_1 * 3) + pub_r001944_6_1) + 11) & 127;
  int stage_v_36_2 = (((stage_v_30_2 * 3) + pub_r001944_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = ((pub_r001944_12_1 * 2) + 26) & 63;
  int stage_v_37_2 = ((pub_r001944_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (((sec_r001944_16_1 * 3) + pub_r001944_22_1) + 9) & 127;
  int stage_v_38_2 = (((sec_r001944_16_2 * 3) + pub_r001944_22_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = ((pub_r001944_13_1 * 2) + 6) & 63;
  int stage_v_39_2 = ((pub_r001944_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001944_7_1 * 2) + 6) & 63;
  int stage_v_40_2 = ((pub_r001944_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = (((stage_v_4_1 * 3) + pub_r001944_17_1) + 7) & 127;
  int stage_v_41_2 = (((stage_v_4_2 * 3) + pub_r001944_17_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = (((stage_v_10_1 * 3) + pub_r001944_4_1) + 8) & 127;
  int stage_v_42_2 = (((stage_v_10_2 * 3) + pub_r001944_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = ((pub_r001944_16_1 * 2) + 43) & 63;
  int stage_v_43_2 = ((pub_r001944_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001944_11_1 * 2) + 36) & 63;
  int stage_v_44_2 = ((pub_r001944_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = (((stage_v_34_1 * 3) + pub_r001944_0_1) + 45) & 127;
  int stage_v_45_2 = (((stage_v_34_2 * 3) + pub_r001944_0_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = (((stage_v_15_1 * 3) + pub_r001944_4_1) + 8) & 127;
  int stage_v_46_2 = (((stage_v_15_2 * 3) + pub_r001944_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = (((stage_v_26_1 * 3) + pub_r001944_13_1) + 24) & 127;
  int stage_v_47_2 = (((stage_v_26_2 * 3) + pub_r001944_13_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = (((stage_v_5_1 * 3) + pub_r001944_6_1) + 43) & 127;
  int stage_v_48_2 = (((stage_v_5_2 * 3) + pub_r001944_6_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = (((stage_v_21_1 * 3) + pub_r001944_15_1) + 16) & 127;
  int stage_v_49_2 = (((stage_v_21_2 * 3) + pub_r001944_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = (((helper_flow_6_1 * 3) + pub_r001944_7_1) + 36) & 127;
  int stage_v_50_2 = (((helper_flow_6_2 * 3) + pub_r001944_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = (((stage_v_10_1 * 3) + pub_r001944_23_1) + 25) & 127;
  int stage_v_51_2 = (((stage_v_10_2 * 3) + pub_r001944_23_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_51_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_51_2 * 2)) & 255;
  int stage_v_52_1 = (((stage_v_46_1 * 3) + pub_r001944_20_1) + 34) & 127;
  int stage_v_52_2 = (((stage_v_46_2 * 3) + pub_r001944_20_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = ((pub_r001944_10_1 * 2) + 13) & 63;
  int stage_v_53_2 = ((pub_r001944_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (((sec_r001944_5_1 * 3) + pub_r001944_14_1) + 14) & 127;
  int stage_v_54_2 = (((sec_r001944_5_2 * 3) + pub_r001944_14_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = (((stage_v_49_1 * 3) + pub_r001944_22_1) + 21) & 127;
  int stage_v_55_2 = (((stage_v_49_2 * 3) + pub_r001944_22_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = ((pub_r001944_9_1 * 2) + 46) & 63;
  int stage_v_56_2 = ((pub_r001944_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (((sec_r001944_5_1 * 3) + pub_r001944_2_1) + 28) & 127;
  int stage_v_57_2 = (((sec_r001944_5_2 * 3) + pub_r001944_2_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = (((stage_v_38_1 * 3) + pub_r001944_20_1) + 3) & 127;
  int stage_v_58_2 = (((stage_v_38_2 * 3) + pub_r001944_20_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = ((pub_r001944_2_1 * 2) + 37) & 63;
  int stage_v_59_2 = ((pub_r001944_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001944_3_1 * 2) + 18) & 63;
  int stage_v_60_2 = ((pub_r001944_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((sec_r001944_14_1 * 3) + pub_r001944_0_1) + 21) & 127;
  int stage_v_61_2 = (((sec_r001944_14_2 * 3) + pub_r001944_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = (((stage_v_61_1 * 3) + pub_r001944_22_1) + 18) & 127;
  int stage_v_62_2 = (((stage_v_61_2 * 3) + pub_r001944_22_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = ((pub_r001944_20_1 * 2) + 41) & 63;
  int stage_v_63_2 = ((pub_r001944_20_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (((sec_r001944_11_1 * 3) + pub_r001944_21_1) + 25) & 127;
  int stage_v_64_2 = (((sec_r001944_11_2 * 3) + pub_r001944_21_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = ((pub_r001944_8_1 * 2) + 36) & 63;
  int stage_v_65_2 = ((pub_r001944_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001944_5_1 * 2) + 25) & 63;
  int stage_v_66_2 = ((pub_r001944_5_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (((stage_v_7_1 * 3) + pub_r001944_5_1) + 33) & 127;
  int stage_v_67_2 = (((stage_v_7_2 * 3) + pub_r001944_5_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = (((sec_r001944_20_1 * 3) + pub_r001944_13_1) + 17) & 127;
  int stage_v_68_2 = (((sec_r001944_20_2 * 3) + pub_r001944_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = ((pub_r001944_7_1 * 2) + 38) & 63;
  int stage_v_69_2 = ((pub_r001944_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001944_21_1 * 2) + 13) & 63;
  int stage_v_70_2 = ((pub_r001944_21_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001944_20_1 * 2) + 15) & 63;
  int stage_v_71_2 = ((pub_r001944_20_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((stage_v_19_1 * 3) + pub_r001944_16_1) + 8) & 127;
  int stage_v_72_2 = (((stage_v_19_2 * 3) + pub_r001944_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = ((pub_r001944_17_1 * 2) + 21) & 63;
  int stage_v_73_2 = ((pub_r001944_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001944_22_1 * 2) + 10) & 63;
  int stage_v_74_2 = ((pub_r001944_22_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (((sec_r001944_1_1 * 3) + pub_r001944_13_1) + 37) & 127;
  int stage_v_75_2 = (((sec_r001944_1_2 * 3) + pub_r001944_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = (((stage_v_52_1 * 3) + pub_r001944_20_1) + 19) & 127;
  int stage_v_76_2 = (((stage_v_52_2 * 3) + pub_r001944_20_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = ((pub_r001944_21_1 * 2) + 40) & 63;
  int stage_v_77_2 = ((pub_r001944_21_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001944_6_1 * 2) + 48) & 63;
  int stage_v_78_2 = ((pub_r001944_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (((helper_flow_0_1 * 3) + pub_r001944_3_1) + 41) & 127;
  int stage_v_79_2 = (((helper_flow_0_2 * 3) + pub_r001944_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = ((pub_r001944_12_1 * 2) + 30) & 63;
  int stage_v_80_2 = ((pub_r001944_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((sec_r001944_8_1 * 3) + pub_r001944_9_1) + 34) & 127;
  int stage_v_81_2 = (((sec_r001944_8_2 * 3) + pub_r001944_9_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = ((pub_r001944_8_1 * 2) + 41) & 63;
  int stage_v_82_2 = ((pub_r001944_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (((sec_r001944_11_1 * 3) + pub_r001944_23_1) + 7) & 127;
  int stage_v_83_2 = (((sec_r001944_11_2 * 3) + pub_r001944_23_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = ((pub_r001944_5_1 * 2) + 22) & 63;
  int stage_v_84_2 = ((pub_r001944_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001944_11_1 * 2) + 30) & 63;
  int stage_v_85_2 = ((pub_r001944_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001944_4_1 * 2) + 17) & 63;
  int stage_v_86_2 = ((pub_r001944_4_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001944_7_1 * 2) + 5) & 63;
  int stage_v_87_2 = ((pub_r001944_7_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((sec_r001944_16_1 * 3) + pub_r001944_21_1) + 11) & 127;
  int stage_v_88_2 = (((sec_r001944_16_2 * 3) + pub_r001944_21_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = ((pub_r001944_15_1 * 2) + 29) & 63;
  int stage_v_89_2 = ((pub_r001944_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((stage_v_72_1 * 3) + pub_r001944_6_1) + 25) & 127;
  int stage_v_90_2 = (((stage_v_72_2 * 3) + pub_r001944_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = ((pub_r001944_21_1 * 2) + 35) & 63;
  int stage_v_91_2 = ((pub_r001944_21_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001944_13_1 * 2) + 17) & 63;
  int stage_v_92_2 = ((pub_r001944_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = (((stage_v_21_1 * 3) + pub_r001944_1_1) + 42) & 127;
  int stage_v_93_2 = (((stage_v_21_2 * 3) + pub_r001944_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = (((sec_r001944_21_1 * 3) + pub_r001944_5_1) + 32) & 127;
  int stage_v_94_2 = (((sec_r001944_21_2 * 3) + pub_r001944_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = ((pub_r001944_9_1 * 2) + 44) & 63;
  int stage_v_95_2 = ((pub_r001944_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001944_9_1 * 2) + 16) & 63;
  int stage_v_96_2 = ((pub_r001944_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((stage_v_51_1 * 3) + pub_r001944_3_1) + 41) & 127;
  int stage_v_97_2 = (((stage_v_51_2 * 3) + pub_r001944_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = ((pub_r001944_5_1 * 2) + 5) & 63;
  int stage_v_98_2 = ((pub_r001944_5_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001944_14_1 * 2) + 33) & 63;
  int stage_v_99_2 = ((pub_r001944_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (((helper_flow_0_1 * 3) + pub_r001944_4_1) + 17) & 127;
  int stage_v_100_2 = (((helper_flow_0_2 * 3) + pub_r001944_4_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_100_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_100_2 * 2)) & 255;
  int stage_v_101_1 = ((pub_r001944_6_1 * 2) + 47) & 63;
  int stage_v_101_2 = ((pub_r001944_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001944_22_1 * 2) + 22) & 63;
  int stage_v_102_2 = ((pub_r001944_22_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (((stage_v_23_1 * 3) + pub_r001944_18_1) + 8) & 127;
  int stage_v_103_2 = (((stage_v_23_2 * 3) + pub_r001944_18_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = ((pub_r001944_23_1 * 2) + 36) & 63;
  int stage_v_104_2 = ((pub_r001944_23_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((stage_v_15_1 * 3) + pub_r001944_4_1) + 26) & 127;
  int stage_v_105_2 = (((stage_v_15_2 * 3) + pub_r001944_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = (((stage_v_62_1 * 3) + pub_r001944_16_1) + 27) & 127;
  int stage_v_106_2 = (((stage_v_62_2 * 3) + pub_r001944_16_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = (((stage_v_4_1 * 3) + pub_r001944_12_1) + 21) & 127;
  int stage_v_107_2 = (((stage_v_4_2 * 3) + pub_r001944_12_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = ((pub_r001944_7_1 * 2) + 33) & 63;
  int stage_v_108_2 = ((pub_r001944_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001944_10_1 * 2) + 13) & 63;
  int stage_v_109_2 = ((pub_r001944_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001944_16_1 * 2) + 48) & 63;
  int stage_v_110_2 = ((pub_r001944_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001944_19_1 * 2) + 6) & 63;
  int stage_v_111_2 = ((pub_r001944_19_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (((stage_v_64_1 * 3) + pub_r001944_20_1) + 3) & 127;
  int stage_v_112_2 = (((stage_v_64_2 * 3) + pub_r001944_20_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = ((pub_r001944_13_1 * 2) + 21) & 63;
  int stage_v_113_2 = ((pub_r001944_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001944_19_1 * 2) + 48) & 63;
  int stage_v_114_2 = ((pub_r001944_19_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = (((sec_r001944_4_1 * 3) + pub_r001944_7_1) + 25) & 127;
  int stage_v_115_2 = (((sec_r001944_4_2 * 3) + pub_r001944_7_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = (((stage_v_21_1 * 3) + pub_r001944_13_1) + 22) & 127;
  int stage_v_116_2 = (((stage_v_21_2 * 3) + pub_r001944_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = (((sec_r001944_5_1 * 3) + pub_r001944_14_1) + 17) & 127;
  int stage_v_117_2 = (((sec_r001944_5_2 * 3) + pub_r001944_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = ((pub_r001944_12_1 * 2) + 40) & 63;
  int stage_v_118_2 = ((pub_r001944_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (((sec_r001944_9_1 * 3) + pub_r001944_0_1) + 28) & 127;
  int stage_v_119_2 = (((sec_r001944_9_2 * 3) + pub_r001944_0_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = ((pub_r001944_14_1 * 2) + 12) & 63;
  int stage_v_120_2 = ((pub_r001944_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001944_15_1 * 2) + 5) & 63;
  int stage_v_121_2 = ((pub_r001944_15_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (((stage_v_30_1 * 3) + pub_r001944_14_1) + 12) & 127;
  int stage_v_122_2 = (((stage_v_30_2 * 3) + pub_r001944_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = (((stage_v_26_1 * 3) + pub_r001944_16_1) + 5) & 127;
  int stage_v_123_2 = (((stage_v_26_2 * 3) + pub_r001944_16_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = (((helper_flow_3_1 * 3) + pub_r001944_3_1) + 9) & 127;
  int stage_v_124_2 = (((helper_flow_3_2 * 3) + pub_r001944_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = (((sec_r001944_9_1 * 3) + pub_r001944_15_1) + 7) & 127;
  int stage_v_125_2 = (((sec_r001944_9_2 * 3) + pub_r001944_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = (((sec_r001944_18_1 * 3) + pub_r001944_8_1) + 13) & 127;
  int stage_v_126_2 = (((sec_r001944_18_2 * 3) + pub_r001944_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = ((pub_r001944_21_1 * 2) + 43) & 63;
  int stage_v_127_2 = ((pub_r001944_21_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = (((stage_v_15_1 * 3) + pub_r001944_8_1) + 28) & 127;
  int stage_v_128_2 = (((stage_v_15_2 * 3) + pub_r001944_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = (((sec_r001944_6_1 * 3) + pub_r001944_15_1) + 11) & 127;
  int stage_v_129_2 = (((sec_r001944_6_2 * 3) + pub_r001944_15_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = (((stage_v_75_1 * 3) + pub_r001944_3_1) + 25) & 127;
  int stage_v_130_2 = (((stage_v_75_2 * 3) + pub_r001944_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = (((stage_v_29_1 * 3) + pub_r001944_15_1) + 33) & 127;
  int stage_v_131_2 = (((stage_v_29_2 * 3) + pub_r001944_15_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_131_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_131_2 * 2)) & 255;
  int stage_v_132_1 = (((sec_r001944_11_1 * 3) + pub_r001944_12_1) + 22) & 127;
  int stage_v_132_2 = (((sec_r001944_11_2 * 3) + pub_r001944_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = (((stage_v_131_1 * 3) + pub_r001944_18_1) + 30) & 127;
  int stage_v_133_2 = (((stage_v_131_2 * 3) + pub_r001944_18_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = ((pub_r001944_23_1 * 2) + 6) & 63;
  int stage_v_134_2 = ((pub_r001944_23_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001944_3_1 * 2) + 31) & 63;
  int stage_v_135_2 = ((pub_r001944_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001944_2_1 * 2) + 28) & 63;
  int stage_v_136_2 = ((pub_r001944_2_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001944_3_1 * 2) + 24) & 63;
  int stage_v_137_2 = ((pub_r001944_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001944_12_1 * 2) + 46) & 63;
  int stage_v_138_2 = ((pub_r001944_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = (((stage_v_93_1 * 3) + pub_r001944_14_1) + 12) & 127;
  int stage_v_139_2 = (((stage_v_93_2 * 3) + pub_r001944_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = ((pub_r001944_21_1 * 2) + 31) & 63;
  int stage_v_140_2 = ((pub_r001944_21_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001944_22_1 * 2) + 6) & 63;
  int stage_v_141_2 = ((pub_r001944_22_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001944_8_1 * 2) + 18) & 63;
  int stage_v_142_2 = ((pub_r001944_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = (((stage_v_15_1 * 3) + pub_r001944_12_1) + 5) & 127;
  int stage_v_143_2 = (((stage_v_15_2 * 3) + pub_r001944_12_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = ((pub_r001944_2_1 * 2) + 17) & 63;
  int stage_v_144_2 = ((pub_r001944_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001944_18_1 * 2) + 8) & 63;
  int stage_v_145_2 = ((pub_r001944_18_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001944_19_1 * 2) + 26) & 63;
  int stage_v_146_2 = ((pub_r001944_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((stage_v_131_1 * 3) + pub_r001944_4_1) + 11) & 127;
  int stage_v_147_2 = (((stage_v_131_2 * 3) + pub_r001944_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = (((stage_v_132_1 * 3) + pub_r001944_19_1) + 41) & 127;
  int stage_v_148_2 = (((stage_v_132_2 * 3) + pub_r001944_19_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = (((stage_v_122_1 * 3) + pub_r001944_2_1) + 41) & 127;
  int stage_v_149_2 = (((stage_v_122_2 * 3) + pub_r001944_2_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = (((stage_v_100_1 * 3) + pub_r001944_21_1) + 37) & 127;
  int stage_v_150_2 = (((stage_v_100_2 * 3) + pub_r001944_21_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = (((stage_v_23_1 * 3) + pub_r001944_1_1) + 23) & 127;
  int stage_v_151_2 = (((stage_v_23_2 * 3) + pub_r001944_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = (((stage_v_51_1 * 3) + pub_r001944_9_1) + 40) & 127;
  int stage_v_152_2 = (((stage_v_51_2 * 3) + pub_r001944_9_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = (((stage_v_133_1 * 3) + pub_r001944_20_1) + 38) & 127;
  int stage_v_153_2 = (((stage_v_133_2 * 3) + pub_r001944_20_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = ((pub_r001944_15_1 * 2) + 44) & 63;
  int stage_v_154_2 = ((pub_r001944_15_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001944_9_1 * 2) + 45) & 63;
  int stage_v_155_2 = ((pub_r001944_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (((stage_v_27_1 * 3) + pub_r001944_22_1) + 32) & 127;
  int stage_v_156_2 = (((stage_v_27_2 * 3) + pub_r001944_22_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((stage_v_149_1 * 3) + pub_r001944_1_1) + 36) & 127;
  int stage_v_157_2 = (((stage_v_149_2 * 3) + pub_r001944_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = ((pub_r001944_2_1 * 2) + 17) & 63;
  int stage_v_158_2 = ((pub_r001944_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001944_11_1 * 2) + 28) & 63;
  int stage_v_159_2 = ((pub_r001944_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = (((sec_r001944_10_1 * 3) + pub_r001944_6_1) + 20) & 127;
  int stage_v_160_2 = (((sec_r001944_10_2 * 3) + pub_r001944_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = (((stage_v_126_1 * 3) + pub_r001944_15_1) + 6) & 127;
  int stage_v_161_2 = (((stage_v_126_2 * 3) + pub_r001944_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = (((stage_v_133_1 * 3) + pub_r001944_0_1) + 44) & 127;
  int stage_v_162_2 = (((stage_v_133_2 * 3) + pub_r001944_0_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = ((pub_r001944_16_1 * 2) + 40) & 63;
  int stage_v_163_2 = ((pub_r001944_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (((helper_flow_7_1 * 3) + pub_r001944_9_1) + 23) & 127;
  int stage_v_164_2 = (((helper_flow_7_2 * 3) + pub_r001944_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = ((pub_r001944_17_1 * 2) + 44) & 63;
  int stage_v_165_2 = ((pub_r001944_17_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = (((stage_v_11_1 * 3) + pub_r001944_9_1) + 45) & 127;
  int stage_v_166_2 = (((stage_v_11_2 * 3) + pub_r001944_9_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = ((pub_r001944_15_1 * 2) + 28) & 63;
  int stage_v_167_2 = ((pub_r001944_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001944_15_1 * 2) + 40) & 63;
  int stage_v_168_2 = ((pub_r001944_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (((sec_r001944_21_1 * 3) + pub_r001944_5_1) + 36) & 127;
  int stage_v_169_2 = (((sec_r001944_21_2 * 3) + pub_r001944_5_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = (((stage_v_133_1 * 3) + pub_r001944_11_1) + 12) & 127;
  int stage_v_170_2 = (((stage_v_133_2 * 3) + pub_r001944_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = ((pub_r001944_11_1 * 2) + 11) & 63;
  int stage_v_171_2 = ((pub_r001944_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((stage_v_124_1 * 3) + pub_r001944_14_1) + 13) & 127;
  int stage_v_172_2 = (((stage_v_124_2 * 3) + pub_r001944_14_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = (((stage_v_147_1 * 3) + pub_r001944_7_1) + 39) & 127;
  int stage_v_173_2 = (((stage_v_147_2 * 3) + pub_r001944_7_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = ((pub_r001944_7_1 * 2) + 34) & 63;
  int stage_v_174_2 = ((pub_r001944_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((stage_v_9_1 * 3) + pub_r001944_15_1) + 23) & 127;
  int stage_v_175_2 = (((stage_v_9_2 * 3) + pub_r001944_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = ((pub_r001944_13_1 * 2) + 31) & 63;
  int stage_v_176_2 = ((pub_r001944_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = (((stage_v_131_1 * 3) + pub_r001944_23_1) + 39) & 127;
  int stage_v_177_2 = (((stage_v_131_2 * 3) + pub_r001944_23_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = ((pub_r001944_1_1 * 2) + 26) & 63;
  int stage_v_178_2 = ((pub_r001944_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001944_9_1 * 2) + 31) & 63;
  int stage_v_179_2 = ((pub_r001944_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((stage_v_18_1 * 3) + pub_r001944_15_1) + 14) & 127;
  int stage_v_180_2 = (((stage_v_18_2 * 3) + pub_r001944_15_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = ((pub_r001944_11_1 * 2) + 31) & 63;
  int stage_v_181_2 = ((pub_r001944_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((stage_v_24_1 * 3) + pub_r001944_19_1) + 6) & 127;
  int stage_v_182_2 = (((stage_v_24_2 * 3) + pub_r001944_19_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = (((helper_flow_8_1 * 3) + pub_r001944_1_1) + 18) & 127;
  int stage_v_183_2 = (((helper_flow_8_2 * 3) + pub_r001944_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = ((pub_r001944_11_1 * 2) + 32) & 63;
  int stage_v_184_2 = ((pub_r001944_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001944_12_1 * 2) + 36) & 63;
  int stage_v_185_2 = ((pub_r001944_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001944_15_1 * 2) + 46) & 63;
  int stage_v_186_2 = ((pub_r001944_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = (((stage_v_100_1 * 3) + pub_r001944_19_1) + 35) & 127;
  int stage_v_187_2 = (((stage_v_100_2 * 3) + pub_r001944_19_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = ((pub_r001944_22_1 * 2) + 50) & 63;
  int stage_v_188_2 = ((pub_r001944_22_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (((stage_v_76_1 * 3) + pub_r001944_13_1) + 15) & 127;
  int stage_v_189_2 = (((stage_v_76_2 * 3) + pub_r001944_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = (((sec_r001944_1_1 * 3) + pub_r001944_18_1) + 36) & 127;
  int stage_v_190_2 = (((sec_r001944_1_2 * 3) + pub_r001944_18_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = (((sec_r001944_10_1 * 3) + pub_r001944_17_1) + 43) & 127;
  int stage_v_191_2 = (((sec_r001944_10_2 * 3) + pub_r001944_17_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = ((pub_r001944_23_1 * 2) + 13) & 63;
  int stage_v_192_2 = ((pub_r001944_23_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((stage_v_25_1 * 3) + pub_r001944_11_1) + 36) & 127;
  int stage_v_193_2 = (((stage_v_25_2 * 3) + pub_r001944_11_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = (((stage_v_5_1 * 3) + pub_r001944_4_1) + 10) & 127;
  int stage_v_194_2 = (((stage_v_5_2 * 3) + pub_r001944_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = (((sec_r001944_12_1 * 3) + pub_r001944_5_1) + 11) & 127;
  int stage_v_195_2 = (((sec_r001944_12_2 * 3) + pub_r001944_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = ((pub_r001944_14_1 * 2) + 29) & 63;
  int stage_v_196_2 = ((pub_r001944_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001944_4_1 * 2) + 9) & 63;
  int stage_v_197_2 = ((pub_r001944_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((stage_v_119_1 * 3) + pub_r001944_1_1) + 18) & 127;
  int stage_v_198_2 = (((stage_v_119_2 * 3) + pub_r001944_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = (((stage_v_125_1 * 3) + pub_r001944_5_1) + 34) & 127;
  int stage_v_199_2 = (((stage_v_125_2 * 3) + pub_r001944_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = ((pub_r001944_16_1 * 2) + 20) & 63;
  int stage_v_200_2 = ((pub_r001944_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001944_20_1 * 2) + 5) & 63;
  int stage_v_201_2 = ((pub_r001944_20_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001944_3_1 * 2) + 39) & 63;
  int stage_v_202_2 = ((pub_r001944_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001944_6_1 * 2) + 33) & 63;
  int stage_v_203_2 = ((pub_r001944_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((stage_v_57_1 * 3) + pub_r001944_17_1) + 10) & 127;
  int stage_v_204_2 = (((stage_v_57_2 * 3) + pub_r001944_17_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = (((sec_r001944_21_1 * 3) + pub_r001944_19_1) + 26) & 127;
  int stage_v_205_2 = (((sec_r001944_21_2 * 3) + pub_r001944_19_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = (((stage_v_124_1 * 3) + pub_r001944_20_1) + 35) & 127;
  int stage_v_206_2 = (((stage_v_124_2 * 3) + pub_r001944_20_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = ((pub_r001944_10_1 * 2) + 10) & 63;
  int stage_v_207_2 = ((pub_r001944_10_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001944_21_1 * 2) + 48) & 63;
  int stage_v_208_2 = ((pub_r001944_21_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = (((stage_v_52_1 * 3) + pub_r001944_21_1) + 45) & 127;
  int stage_v_209_2 = (((stage_v_52_2 * 3) + pub_r001944_21_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = (((stage_v_48_1 * 3) + pub_r001944_5_1) + 45) & 127;
  int stage_v_210_2 = (((stage_v_48_2 * 3) + pub_r001944_5_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = ((pub_r001944_20_1 * 2) + 22) & 63;
  int stage_v_211_2 = ((pub_r001944_20_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((pub_r001944_9_1 * 2) + 29) & 63;
  int stage_v_212_2 = ((pub_r001944_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = (((stage_v_119_1 * 3) + pub_r001944_0_1) + 30) & 127;
  int stage_v_213_2 = (((stage_v_119_2 * 3) + pub_r001944_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = ((pub_r001944_12_1 * 2) + 47) & 63;
  int stage_v_214_2 = ((pub_r001944_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((stage_v_164_1 * 3) + pub_r001944_20_1) + 12) & 127;
  int stage_v_215_2 = (((stage_v_164_2 * 3) + pub_r001944_20_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((stage_v_122_1 * 3) + pub_r001944_22_1) + 30) & 127;
  int stage_v_216_2 = (((stage_v_122_2 * 3) + pub_r001944_22_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = ((pub_r001944_0_1 * 2) + 20) & 63;
  int stage_v_217_2 = ((pub_r001944_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001944_8_1 * 2) + 7) & 63;
  int stage_v_218_2 = ((pub_r001944_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = (((stage_v_147_1 * 3) + pub_r001944_8_1) + 21) & 127;
  int stage_v_219_2 = (((stage_v_147_2 * 3) + pub_r001944_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = (((stage_v_62_1 * 3) + pub_r001944_1_1) + 17) & 127;
  int stage_v_220_2 = (((stage_v_62_2 * 3) + pub_r001944_1_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = ((pub_r001944_21_1 * 2) + 25) & 63;
  int stage_v_221_2 = ((pub_r001944_21_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((pub_r001944_14_1 * 2) + 40) & 63;
  int stage_v_222_2 = ((pub_r001944_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = (((stage_v_27_1 * 3) + pub_r001944_18_1) + 12) & 127;
  int stage_v_223_2 = (((stage_v_27_2 * 3) + pub_r001944_18_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = (((sec_r001944_15_1 * 3) + pub_r001944_2_1) + 30) & 127;
  int stage_v_224_2 = (((sec_r001944_15_2 * 3) + pub_r001944_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = (((stage_v_54_1 * 3) + pub_r001944_2_1) + 44) & 127;
  int stage_v_225_2 = (((stage_v_54_2 * 3) + pub_r001944_2_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = (((stage_v_209_1 * 3) + pub_r001944_22_1) + 23) & 127;
  int stage_v_226_2 = (((stage_v_209_2 * 3) + pub_r001944_22_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = (((helper_flow_8_1 * 3) + pub_r001944_4_1) + 34) & 127;
  int stage_v_227_2 = (((helper_flow_8_2 * 3) + pub_r001944_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = ((pub_r001944_8_1 * 2) + 9) & 63;
  int stage_v_228_2 = ((pub_r001944_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_172_1 * 3) + pub_r001944_14_1) + 10) & 127;
  int stage_v_229_2 = (((stage_v_172_2 * 3) + pub_r001944_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = (((sec_r001944_9_1 * 3) + pub_r001944_13_1) + 18) & 127;
  int stage_v_230_2 = (((sec_r001944_9_2 * 3) + pub_r001944_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = ((pub_r001944_10_1 * 2) + 24) & 63;
  int stage_v_231_2 = ((pub_r001944_10_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001944_5_1 * 2) + 11) & 63;
  int stage_v_232_2 = ((pub_r001944_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = (((stage_v_93_1 * 3) + pub_r001944_21_1) + 11) & 127;
  int stage_v_233_2 = (((stage_v_93_2 * 3) + pub_r001944_21_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = (((stage_v_213_1 * 3) + pub_r001944_2_1) + 35) & 127;
  int stage_v_234_2 = (((stage_v_213_2 * 3) + pub_r001944_2_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = (((stage_v_119_1 * 3) + pub_r001944_14_1) + 23) & 127;
  int stage_v_235_2 = (((stage_v_119_2 * 3) + pub_r001944_14_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = (((stage_v_235_1 * 3) + pub_r001944_13_1) + 26) & 127;
  int stage_v_236_2 = (((stage_v_235_2 * 3) + pub_r001944_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = (((sec_r001944_2_1 * 3) + pub_r001944_6_1) + 37) & 127;
  int stage_v_237_2 = (((sec_r001944_2_2 * 3) + pub_r001944_6_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_237_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_237_2 * 2)) & 255;
  int stage_v_238_1 = (((stage_v_117_1 * 3) + pub_r001944_23_1) + 34) & 127;
  int stage_v_238_2 = (((stage_v_117_2 * 3) + pub_r001944_23_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = ((pub_r001944_5_1 * 2) + 41) & 63;
  int stage_v_239_2 = ((pub_r001944_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((pub_r001944_21_1 * 2) + 42) & 63;
  int stage_v_240_2 = ((pub_r001944_21_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = (((stage_v_4_1 * 3) + pub_r001944_2_1) + 38) & 127;
  int stage_v_241_2 = (((stage_v_4_2 * 3) + pub_r001944_2_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = (((stage_v_5_1 * 3) + pub_r001944_7_1) + 4) & 127;
  int stage_v_242_2 = (((stage_v_5_2 * 3) + pub_r001944_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = (((stage_v_64_1 * 3) + pub_r001944_19_1) + 20) & 127;
  int stage_v_243_2 = (((stage_v_64_2 * 3) + pub_r001944_19_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = ((pub_r001944_16_1 * 2) + 25) & 63;
  int stage_v_244_2 = ((pub_r001944_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001944_3_1 * 2) + 31) & 63;
  int stage_v_245_2 = ((pub_r001944_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001944_5_1 * 2) + 48) & 63;
  int stage_v_246_2 = ((pub_r001944_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001944_6_1 * 2) + 22) & 63;
  int stage_v_247_2 = ((pub_r001944_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001944_15_1 * 2) + 46) & 63;
  int stage_v_248_2 = ((pub_r001944_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = (((stage_v_129_1 * 3) + pub_r001944_12_1) + 14) & 127;
  int stage_v_249_2 = (((stage_v_129_2 * 3) + pub_r001944_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = (((stage_v_156_1 * 3) + pub_r001944_18_1) + 27) & 127;
  int stage_v_250_2 = (((stage_v_156_2 * 3) + pub_r001944_18_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = (((stage_v_64_1 * 3) + pub_r001944_18_1) + 23) & 127;
  int stage_v_251_2 = (((stage_v_64_2 * 3) + pub_r001944_18_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = ((pub_r001944_22_1 * 2) + 44) & 63;
  int stage_v_252_2 = ((pub_r001944_22_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = (((stage_v_191_1 * 3) + pub_r001944_20_1) + 24) & 127;
  int stage_v_253_2 = (((stage_v_191_2 * 3) + pub_r001944_20_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = ((pub_r001944_16_1 * 2) + 41) & 63;
  int stage_v_254_2 = ((pub_r001944_16_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = (((sec_r001944_3_1 * 3) + pub_r001944_23_1) + 10) & 127;
  int stage_v_255_2 = (((sec_r001944_3_2 * 3) + pub_r001944_23_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = (((sec_r001944_19_1 * 3) + pub_r001944_18_1) + 29) & 127;
  int stage_v_256_2 = (((sec_r001944_19_2 * 3) + pub_r001944_18_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = ((pub_r001944_9_1 * 2) + 20) & 63;
  int stage_v_257_2 = ((pub_r001944_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((stage_v_19_1 * 3) + pub_r001944_21_1) + 38) & 127;
  int stage_v_258_2 = (((stage_v_19_2 * 3) + pub_r001944_21_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = ((pub_r001944_6_1 * 2) + 23) & 63;
  int stage_v_259_2 = ((pub_r001944_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001944_19_1 * 2) + 22) & 63;
  int stage_v_260_2 = ((pub_r001944_19_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001944_10_1 * 2) + 41) & 63;
  int stage_v_261_2 = ((pub_r001944_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = (((stage_v_45_1 * 3) + pub_r001944_0_1) + 11) & 127;
  int stage_v_262_2 = (((stage_v_45_2 * 3) + pub_r001944_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_262_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_262_2 * 2)) & 255;
  int stage_v_263_1 = ((pub_r001944_17_1 * 2) + 35) & 63;
  int stage_v_263_2 = ((pub_r001944_17_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((pub_r001944_7_1 * 2) + 8) & 63;
  int stage_v_264_2 = ((pub_r001944_7_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = (((stage_v_216_1 * 3) + pub_r001944_6_1) + 23) & 127;
  int stage_v_265_2 = (((stage_v_216_2 * 3) + pub_r001944_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = (((sec_r001944_12_1 * 3) + pub_r001944_13_1) + 20) & 127;
  int stage_v_266_2 = (((sec_r001944_12_2 * 3) + pub_r001944_13_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = (((stage_v_226_1 * 3) + pub_r001944_20_1) + 45) & 127;
  int stage_v_267_2 = (((stage_v_226_2 * 3) + pub_r001944_20_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = ((pub_r001944_13_1 * 2) + 16) & 63;
  int stage_v_268_2 = ((pub_r001944_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001944_20_1 * 2) + 36) & 63;
  int stage_v_269_2 = ((pub_r001944_20_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001944_14_1 * 2) + 49) & 63;
  int stage_v_270_2 = ((pub_r001944_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001944_8_1 * 2) + 37) & 63;
  int stage_v_271_2 = ((pub_r001944_8_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = (((stage_v_266_1 * 3) + pub_r001944_10_1) + 40) & 127;
  int stage_v_272_2 = (((stage_v_266_2 * 3) + pub_r001944_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = (((stage_v_126_1 * 3) + pub_r001944_8_1) + 38) & 127;
  int stage_v_273_2 = (((stage_v_126_2 * 3) + pub_r001944_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = ((pub_r001944_21_1 * 2) + 22) & 63;
  int stage_v_274_2 = ((pub_r001944_21_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = (((stage_v_51_1 * 3) + pub_r001944_11_1) + 14) & 127;
  int stage_v_275_2 = (((stage_v_51_2 * 3) + pub_r001944_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = (((stage_v_210_1 * 3) + pub_r001944_5_1) + 24) & 127;
  int stage_v_276_2 = (((stage_v_210_2 * 3) + pub_r001944_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = (((stage_v_266_1 * 3) + pub_r001944_6_1) + 3) & 127;
  int stage_v_277_2 = (((stage_v_266_2 * 3) + pub_r001944_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = (((stage_v_250_1 * 3) + pub_r001944_21_1) + 42) & 127;
  int stage_v_278_2 = (((stage_v_250_2 * 3) + pub_r001944_21_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = (((stage_v_225_1 * 3) + pub_r001944_3_1) + 34) & 127;
  int stage_v_279_2 = (((stage_v_225_2 * 3) + pub_r001944_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = (((stage_v_209_1 * 3) + pub_r001944_11_1) + 23) & 127;
  int stage_v_280_2 = (((stage_v_209_2 * 3) + pub_r001944_11_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = (((stage_v_129_1 * 3) + pub_r001944_12_1) + 4) & 127;
  int stage_v_281_2 = (((stage_v_129_2 * 3) + pub_r001944_12_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = ((pub_r001944_12_1 * 2) + 48) & 63;
  int stage_v_282_2 = ((pub_r001944_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001944_1_1 * 2) + 24) & 63;
  int stage_v_283_2 = ((pub_r001944_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = (((stage_v_36_1 * 3) + pub_r001944_11_1) + 14) & 127;
  int stage_v_284_2 = (((stage_v_36_2 * 3) + pub_r001944_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = (((stage_v_190_1 * 3) + pub_r001944_11_1) + 16) & 127;
  int stage_v_285_2 = (((stage_v_190_2 * 3) + pub_r001944_11_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = ((pub_r001944_7_1 * 2) + 25) & 63;
  int stage_v_286_2 = ((pub_r001944_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((pub_r001944_23_1 * 2) + 8) & 63;
  int stage_v_287_2 = ((pub_r001944_23_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((pub_r001944_17_1 * 2) + 29) & 63;
  int stage_v_288_2 = ((pub_r001944_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = (((stage_v_191_1 * 3) + pub_r001944_20_1) + 27) & 127;
  int stage_v_289_2 = (((stage_v_191_2 * 3) + pub_r001944_20_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = (((stage_v_241_1 * 3) + pub_r001944_21_1) + 27) & 127;
  int stage_v_290_2 = (((stage_v_241_2 * 3) + pub_r001944_21_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = ((pub_r001944_17_1 * 2) + 48) & 63;
  int stage_v_291_2 = ((pub_r001944_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = (((stage_v_161_1 * 3) + pub_r001944_20_1) + 26) & 127;
  int stage_v_292_2 = (((stage_v_161_2 * 3) + pub_r001944_20_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = (((stage_v_45_1 * 3) + pub_r001944_22_1) + 29) & 127;
  int stage_v_293_2 = (((stage_v_45_2 * 3) + pub_r001944_22_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = ((pub_r001944_16_1 * 2) + 6) & 63;
  int stage_v_294_2 = ((pub_r001944_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((pub_r001944_1_1 * 2) + 31) & 63;
  int stage_v_295_2 = ((pub_r001944_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = (((stage_v_122_1 * 3) + pub_r001944_8_1) + 25) & 127;
  int stage_v_296_2 = (((stage_v_122_2 * 3) + pub_r001944_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = ((pub_r001944_7_1 * 2) + 18) & 63;
  int stage_v_297_2 = ((pub_r001944_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = (((helper_flow_5_1 * 3) + pub_r001944_17_1) + 23) & 127;
  int stage_v_298_2 = (((helper_flow_5_2 * 3) + pub_r001944_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = (((stage_v_76_1 * 3) + pub_r001944_4_1) + 3) & 127;
  int stage_v_299_2 = (((stage_v_76_2 * 3) + pub_r001944_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = (((stage_v_58_1 * 3) + pub_r001944_0_1) + 35) & 127;
  int stage_v_300_2 = (((stage_v_58_2 * 3) + pub_r001944_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = ((pub_r001944_3_1 * 2) + 17) & 63;
  int stage_v_301_2 = ((pub_r001944_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = (((stage_v_265_1 * 3) + pub_r001944_14_1) + 12) & 127;
  int stage_v_302_2 = (((stage_v_265_2 * 3) + pub_r001944_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = ((pub_r001944_14_1 * 2) + 27) & 63;
  int stage_v_303_2 = ((pub_r001944_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((pub_r001944_1_1 * 2) + 49) & 63;
  int stage_v_304_2 = ((pub_r001944_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001944_13_1 * 2) + 25) & 63;
  int stage_v_305_2 = ((pub_r001944_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001944_1_1 * 2) + 47) & 63;
  int stage_v_306_2 = ((pub_r001944_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = (((sec_r001944_21_1 * 3) + pub_r001944_2_1) + 23) & 127;
  int stage_v_307_2 = (((sec_r001944_21_2 * 3) + pub_r001944_2_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = ((pub_r001944_8_1 * 2) + 15) & 63;
  int stage_v_308_2 = ((pub_r001944_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((pub_r001944_9_1 * 2) + 39) & 63;
  int stage_v_309_2 = ((pub_r001944_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = (((stage_v_128_1 * 3) + pub_r001944_9_1) + 18) & 127;
  int stage_v_310_2 = (((stage_v_128_2 * 3) + pub_r001944_9_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = (((stage_v_139_1 * 3) + pub_r001944_18_1) + 23) & 127;
  int stage_v_311_2 = (((stage_v_139_2 * 3) + pub_r001944_18_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = (((stage_v_277_1 * 3) + pub_r001944_20_1) + 40) & 127;
  int stage_v_312_2 = (((stage_v_277_2 * 3) + pub_r001944_20_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = (((stage_v_312_1 * 3) + pub_r001944_13_1) + 33) & 127;
  int stage_v_313_2 = (((stage_v_312_2 * 3) + pub_r001944_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = ((pub_r001944_22_1 * 2) + 46) & 63;
  int stage_v_314_2 = ((pub_r001944_22_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = (((stage_v_290_1 * 3) + pub_r001944_1_1) + 40) & 127;
  int stage_v_315_2 = (((stage_v_290_2 * 3) + pub_r001944_1_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = (((stage_v_156_1 * 3) + pub_r001944_2_1) + 23) & 127;
  int stage_v_316_2 = (((stage_v_156_2 * 3) + pub_r001944_2_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = ((pub_r001944_19_1 * 2) + 49) & 63;
  int stage_v_317_2 = ((pub_r001944_19_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = (((stage_v_300_1 * 3) + pub_r001944_10_1) + 30) & 127;
  int stage_v_318_2 = (((stage_v_300_2 * 3) + pub_r001944_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = (((stage_v_25_1 * 3) + pub_r001944_16_1) + 4) & 127;
  int stage_v_319_2 = (((stage_v_25_2 * 3) + pub_r001944_16_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = (((sec_r001944_10_1 * 3) + pub_r001944_8_1) + 27) & 127;
  int stage_v_320_2 = (((sec_r001944_10_2 * 3) + pub_r001944_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = ((pub_r001944_17_1 * 2) + 20) & 63;
  int stage_v_321_2 = ((pub_r001944_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001944_21_1 * 2) + 6) & 63;
  int stage_v_322_2 = ((pub_r001944_21_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001944_17_1 * 2) + 14) & 63;
  int stage_v_323_2 = ((pub_r001944_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((pub_r001944_4_1 * 2) + 11) & 63;
  int stage_v_324_2 = ((pub_r001944_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((pub_r001944_20_1 * 2) + 43) & 63;
  int stage_v_325_2 = ((pub_r001944_20_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((pub_r001944_3_1 * 2) + 25) & 63;
  int stage_v_326_2 = ((pub_r001944_3_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001944_4_1 * 2) + 29) & 63;
  int stage_v_327_2 = ((pub_r001944_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = (((stage_v_256_1 * 3) + pub_r001944_17_1) + 38) & 127;
  int stage_v_328_2 = (((stage_v_256_2 * 3) + pub_r001944_17_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = (((sec_r001944_6_1 * 3) + pub_r001944_12_1) + 41) & 127;
  int stage_v_329_2 = (((sec_r001944_6_2 * 3) + pub_r001944_12_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = ((pub_r001944_2_1 * 2) + 15) & 63;
  int stage_v_330_2 = ((pub_r001944_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = (((stage_v_290_1 * 3) + pub_r001944_16_1) + 33) & 127;
  int stage_v_331_2 = (((stage_v_290_2 * 3) + pub_r001944_16_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_331_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_331_2 * 2)) & 255;
  int stage_v_332_1 = (((stage_v_21_1 * 3) + pub_r001944_0_1) + 18) & 127;
  int stage_v_332_2 = (((stage_v_21_2 * 3) + pub_r001944_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = (((stage_v_300_1 * 3) + pub_r001944_3_1) + 37) & 127;
  int stage_v_333_2 = (((stage_v_300_2 * 3) + pub_r001944_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = ((pub_r001944_12_1 * 2) + 33) & 63;
  int stage_v_334_2 = ((pub_r001944_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((pub_r001944_6_1 * 2) + 26) & 63;
  int stage_v_335_2 = ((pub_r001944_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((pub_r001944_4_1 * 2) + 11) & 63;
  int stage_v_336_2 = ((pub_r001944_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = (((stage_v_230_1 * 3) + pub_r001944_0_1) + 18) & 127;
  int stage_v_337_2 = (((stage_v_230_2 * 3) + pub_r001944_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = ((pub_r001944_18_1 * 2) + 8) & 63;
  int stage_v_338_2 = ((pub_r001944_18_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = (((stage_v_279_1 * 3) + pub_r001944_5_1) + 38) & 127;
  int stage_v_339_2 = (((stage_v_279_2 * 3) + pub_r001944_5_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = ((pub_r001944_11_1 * 2) + 43) & 63;
  int stage_v_340_2 = ((pub_r001944_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = (((stage_v_117_1 * 3) + pub_r001944_7_1) + 43) & 127;
  int stage_v_341_2 = (((stage_v_117_2 * 3) + pub_r001944_7_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = (((stage_v_276_1 * 3) + pub_r001944_22_1) + 3) & 127;
  int stage_v_342_2 = (((stage_v_276_2 * 3) + pub_r001944_22_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = (((stage_v_27_1 * 3) + pub_r001944_21_1) + 20) & 127;
  int stage_v_343_2 = (((stage_v_27_2 * 3) + pub_r001944_21_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = (((stage_v_190_1 * 3) + pub_r001944_10_1) + 21) & 127;
  int stage_v_344_2 = (((stage_v_190_2 * 3) + pub_r001944_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = ((pub_r001944_21_1 * 2) + 43) & 63;
  int stage_v_345_2 = ((pub_r001944_21_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((pub_r001944_4_1 * 2) + 19) & 63;
  int stage_v_346_2 = ((pub_r001944_4_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = (((sec_r001944_14_1 * 3) + pub_r001944_1_1) + 45) & 127;
  int stage_v_347_2 = (((sec_r001944_14_2 * 3) + pub_r001944_1_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = (((stage_v_190_1 * 3) + pub_r001944_15_1) + 42) & 127;
  int stage_v_348_2 = (((stage_v_190_2 * 3) + pub_r001944_15_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = (((stage_v_106_1 * 3) + pub_r001944_13_1) + 3) & 127;
  int stage_v_349_2 = (((stage_v_106_2 * 3) + pub_r001944_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = ((pub_r001944_13_1 * 2) + 12) & 63;
  int stage_v_350_2 = ((pub_r001944_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = ((pub_r001944_4_1 * 2) + 6) & 63;
  int stage_v_351_2 = ((pub_r001944_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = (((sec_r001944_3_1 * 3) + pub_r001944_5_1) + 4) & 127;
  int stage_v_352_2 = (((sec_r001944_3_2 * 3) + pub_r001944_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = (((stage_v_219_1 * 3) + pub_r001944_14_1) + 41) & 127;
  int stage_v_353_2 = (((stage_v_219_2 * 3) + pub_r001944_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = (((sec_r001944_13_1 * 3) + pub_r001944_20_1) + 8) & 127;
  int stage_v_354_2 = (((sec_r001944_13_2 * 3) + pub_r001944_20_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = (((sec_r001944_4_1 * 3) + pub_r001944_13_1) + 37) & 127;
  int stage_v_355_2 = (((sec_r001944_4_2 * 3) + pub_r001944_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = (((stage_v_313_1 * 3) + pub_r001944_4_1) + 6) & 127;
  int stage_v_356_2 = (((stage_v_313_2 * 3) + pub_r001944_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = ((pub_r001944_6_1 * 2) + 47) & 63;
  int stage_v_357_2 = ((pub_r001944_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001944_10_1 * 2) + 8) & 63;
  int stage_v_358_2 = ((pub_r001944_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001944_12_1 * 2) + 13) & 63;
  int stage_v_359_2 = ((pub_r001944_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = (((stage_v_17_1 * 3) + pub_r001944_16_1) + 10) & 127;
  int stage_v_360_2 = (((stage_v_17_2 * 3) + pub_r001944_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = ((pub_r001944_10_1 * 2) + 14) & 63;
  int stage_v_361_2 = ((pub_r001944_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001944_19_1 * 2) + 9) & 63;
  int stage_v_362_2 = ((pub_r001944_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = (((stage_v_55_1 * 3) + pub_r001944_16_1) + 41) & 127;
  int stage_v_363_2 = (((stage_v_55_2 * 3) + pub_r001944_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = ((pub_r001944_11_1 * 2) + 23) & 63;
  int stage_v_364_2 = ((pub_r001944_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = (((stage_v_299_1 * 3) + pub_r001944_16_1) + 18) & 127;
  int stage_v_365_2 = (((stage_v_299_2 * 3) + pub_r001944_16_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = (((stage_v_206_1 * 3) + pub_r001944_4_1) + 18) & 127;
  int stage_v_366_2 = (((stage_v_206_2 * 3) + pub_r001944_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = (((stage_v_51_1 * 3) + pub_r001944_8_1) + 8) & 127;
  int stage_v_367_2 = (((stage_v_51_2 * 3) + pub_r001944_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = ((pub_r001944_22_1 * 2) + 9) & 63;
  int stage_v_368_2 = ((pub_r001944_22_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = (((stage_v_41_1 * 3) + pub_r001944_0_1) + 4) & 127;
  int stage_v_369_2 = (((stage_v_41_2 * 3) + pub_r001944_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = (((stage_v_177_1 * 3) + pub_r001944_16_1) + 21) & 127;
  int stage_v_370_2 = (((stage_v_177_2 * 3) + pub_r001944_16_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = ((pub_r001944_17_1 * 2) + 35) & 63;
  int stage_v_371_2 = ((pub_r001944_17_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001944_12_1 * 2) + 49) & 63;
  int stage_v_372_2 = ((pub_r001944_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = (((stage_v_26_1 * 3) + pub_r001944_6_1) + 6) & 127;
  int stage_v_373_2 = (((stage_v_26_2 * 3) + pub_r001944_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = ((pub_r001944_17_1 * 2) + 12) & 63;
  int stage_v_374_2 = ((pub_r001944_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = (((stage_v_169_1 * 3) + pub_r001944_9_1) + 39) & 127;
  int stage_v_375_2 = (((stage_v_169_2 * 3) + pub_r001944_9_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = (((stage_v_279_1 * 3) + pub_r001944_8_1) + 34) & 127;
  int stage_v_376_2 = (((stage_v_279_2 * 3) + pub_r001944_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = (((stage_v_62_1 * 3) + pub_r001944_5_1) + 39) & 127;
  int stage_v_377_2 = (((stage_v_62_2 * 3) + pub_r001944_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = ((pub_r001944_16_1 * 2) + 12) & 63;
  int stage_v_378_2 = ((pub_r001944_16_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = (((sec_r001944_5_1 * 3) + pub_r001944_18_1) + 23) & 127;
  int stage_v_379_2 = (((sec_r001944_5_2 * 3) + pub_r001944_18_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = ((pub_r001944_0_1 * 2) + 22) & 63;
  int stage_v_380_2 = ((pub_r001944_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = (((stage_v_272_1 * 3) + pub_r001944_16_1) + 21) & 127;
  int stage_v_381_2 = (((stage_v_272_2 * 3) + pub_r001944_16_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = ((pub_r001944_0_1 * 2) + 19) & 63;
  int stage_v_382_2 = ((pub_r001944_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((pub_r001944_12_1 * 2) + 32) & 63;
  int stage_v_383_2 = ((pub_r001944_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001944_7_1 * 2) + 43) & 63;
  int stage_v_384_2 = ((pub_r001944_7_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((pub_r001944_22_1 * 2) + 38) & 63;
  int stage_v_385_2 = ((pub_r001944_22_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = (((stage_v_313_1 * 3) + pub_r001944_0_1) + 32) & 127;
  int stage_v_386_2 = (((stage_v_313_2 * 3) + pub_r001944_0_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_386_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_386_2 * 2)) & 255;
  int stage_v_387_1 = (((stage_v_299_1 * 3) + pub_r001944_7_1) + 28) & 127;
  int stage_v_387_2 = (((stage_v_299_2 * 3) + pub_r001944_7_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = ((pub_r001944_20_1 * 2) + 39) & 63;
  int stage_v_388_2 = ((pub_r001944_20_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = (((stage_v_55_1 * 3) + pub_r001944_10_1) + 35) & 127;
  int stage_v_389_2 = (((stage_v_55_2 * 3) + pub_r001944_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = (((stage_v_4_1 * 3) + pub_r001944_4_1) + 14) & 127;
  int stage_v_390_2 = (((stage_v_4_2 * 3) + pub_r001944_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = ((pub_r001944_13_1 * 2) + 33) & 63;
  int stage_v_391_2 = ((pub_r001944_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001944_11_1 * 2) + 15) & 63;
  int stage_v_392_2 = ((pub_r001944_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = (((stage_v_213_1 * 3) + pub_r001944_8_1) + 39) & 127;
  int stage_v_393_2 = (((stage_v_213_2 * 3) + pub_r001944_8_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = (((stage_v_160_1 * 3) + pub_r001944_16_1) + 40) & 127;
  int stage_v_394_2 = (((stage_v_160_2 * 3) + pub_r001944_16_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_394_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_394_2 * 2)) & 255;
  int stage_v_395_1 = ((pub_r001944_4_1 * 2) + 36) & 63;
  int stage_v_395_2 = ((pub_r001944_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = (((sec_r001944_4_1 * 3) + pub_r001944_20_1) + 29) & 127;
  int stage_v_396_2 = (((sec_r001944_4_2 * 3) + pub_r001944_20_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = (((stage_v_353_1 * 3) + pub_r001944_15_1) + 3) & 127;
  int stage_v_397_2 = (((stage_v_353_2 * 3) + pub_r001944_15_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_397_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_397_2 * 2)) & 255;
  int stage_v_398_1 = ((pub_r001944_16_1 * 2) + 32) & 63;
  int stage_v_398_2 = ((pub_r001944_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001944_3_1 * 2) + 41) & 63;
  int stage_v_399_2 = ((pub_r001944_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = (((stage_v_251_1 * 3) + pub_r001944_22_1) + 24) & 127;
  int stage_v_400_2 = (((stage_v_251_2 * 3) + pub_r001944_22_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_400_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_400_2 * 2)) & 255;
  int stage_v_401_1 = ((pub_r001944_14_1 * 2) + 23) & 63;
  int stage_v_401_2 = ((pub_r001944_14_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = ((pub_r001944_13_1 * 2) + 41) & 63;
  int stage_v_402_2 = ((pub_r001944_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = ((pub_r001944_20_1 * 2) + 26) & 63;
  int stage_v_403_2 = ((pub_r001944_20_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = (((stage_v_255_1 * 3) + pub_r001944_16_1) + 25) & 127;
  int stage_v_404_2 = (((stage_v_255_2 * 3) + pub_r001944_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = (((stage_v_125_1 * 3) + pub_r001944_7_1) + 25) & 127;
  int stage_v_405_2 = (((stage_v_125_2 * 3) + pub_r001944_7_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = (((stage_v_230_1 * 3) + pub_r001944_12_1) + 18) & 127;
  int stage_v_406_2 = (((stage_v_230_2 * 3) + pub_r001944_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_406_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_406_2 * 2)) & 255;
  int stage_v_407_1 = ((pub_r001944_17_1 * 2) + 14) & 63;
  int stage_v_407_2 = ((pub_r001944_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = (((stage_v_348_1 * 3) + pub_r001944_14_1) + 35) & 127;
  int stage_v_408_2 = (((stage_v_348_2 * 3) + pub_r001944_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = ((pub_r001944_21_1 * 2) + 15) & 63;
  int stage_v_409_2 = ((pub_r001944_21_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = (((stage_v_243_1 * 3) + pub_r001944_10_1) + 17) & 127;
  int stage_v_410_2 = (((stage_v_243_2 * 3) + pub_r001944_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_410_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_410_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_410_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_410_2 * 2)) & 255;
  int stage_v_411_1 = ((pub_r001944_1_1 * 2) + 47) & 63;
  int stage_v_411_2 = ((pub_r001944_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = (((stage_v_299_1 * 3) + pub_r001944_2_1) + 43) & 127;
  int stage_v_412_2 = (((stage_v_299_2 * 3) + pub_r001944_2_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_412_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_412_2 * 2)) & 255;
  int stage_v_413_1 = (((stage_v_408_1 * 3) + pub_r001944_22_1) + 33) & 127;
  int stage_v_413_2 = (((stage_v_408_2 * 3) + pub_r001944_22_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_413_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_413_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_413_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_413_2 * 2)) & 255;
  int stage_v_414_1 = (((helper_flow_2_1 * 3) + pub_r001944_19_1) + 30) & 127;
  int stage_v_414_2 = (((helper_flow_2_2 * 3) + pub_r001944_19_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_414_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_414_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_414_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_414_2 * 2)) & 255;
  int stage_v_415_1 = ((pub_r001944_17_1 * 2) + 20) & 63;
  int stage_v_415_2 = ((pub_r001944_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = ((pub_r001944_14_1 * 2) + 43) & 63;
  int stage_v_416_2 = ((pub_r001944_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = (((stage_v_258_1 * 3) + pub_r001944_23_1) + 28) & 127;
  int stage_v_417_2 = (((stage_v_258_2 * 3) + pub_r001944_23_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = (((stage_v_293_1 * 3) + pub_r001944_5_1) + 12) & 127;
  int stage_v_418_2 = (((stage_v_293_2 * 3) + pub_r001944_5_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_418_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_418_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_418_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_418_2 * 2)) & 255;
  int stage_v_419_1 = (((stage_v_253_1 * 3) + pub_r001944_15_1) + 32) & 127;
  int stage_v_419_2 = (((stage_v_253_2 * 3) + pub_r001944_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_419_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_419_2 * 2)) & 255;
  int stage_v_420_1 = ((pub_r001944_13_1 * 2) + 48) & 63;
  int stage_v_420_2 = ((pub_r001944_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = (((stage_v_57_1 * 3) + pub_r001944_4_1) + 13) & 127;
  int stage_v_421_2 = (((stage_v_57_2 * 3) + pub_r001944_4_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_421_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_421_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_421_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_421_2 * 2)) & 255;
  int stage_v_422_1 = ((pub_r001944_0_1 * 2) + 8) & 63;
  int stage_v_422_2 = ((pub_r001944_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = ((pub_r001944_5_1 * 2) + 36) & 63;
  int stage_v_423_2 = ((pub_r001944_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = (((stage_v_75_1 * 3) + pub_r001944_3_1) + 4) & 127;
  int stage_v_424_2 = (((stage_v_75_2 * 3) + pub_r001944_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_424_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_424_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_424_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_424_2 * 2)) & 255;
  int stage_v_425_1 = (((sec_r001944_13_1 * 3) + pub_r001944_15_1) + 12) & 127;
  int stage_v_425_2 = (((sec_r001944_13_2 * 3) + pub_r001944_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_425_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_425_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_425_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_425_2 * 2)) & 255;
  int stage_v_426_1 = ((pub_r001944_19_1 * 2) + 7) & 63;
  int stage_v_426_2 = ((pub_r001944_19_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = ((pub_r001944_2_1 * 2) + 6) & 63;
  int stage_v_427_2 = ((pub_r001944_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = ((pub_r001944_0_1 * 2) + 22) & 63;
  int stage_v_428_2 = ((pub_r001944_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = (((stage_v_394_1 * 3) + pub_r001944_15_1) + 21) & 127;
  int stage_v_429_2 = (((stage_v_394_2 * 3) + pub_r001944_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_429_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_429_2 * 2)) & 255;
  int stage_v_430_1 = ((pub_r001944_14_1 * 2) + 21) & 63;
  int stage_v_430_2 = ((pub_r001944_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_430_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_430_2) & 127;
  int stage_v_431_1 = (((stage_v_128_1 * 3) + pub_r001944_8_1) + 34) & 127;
  int stage_v_431_2 = (((stage_v_128_2 * 3) + pub_r001944_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_431_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_431_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_431_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_431_2 * 2)) & 255;
  int stage_v_432_1 = (((stage_v_209_1 * 3) + pub_r001944_20_1) + 13) & 127;
  int stage_v_432_2 = (((stage_v_209_2 * 3) + pub_r001944_20_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_432_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_432_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_432_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_432_2 * 2)) & 255;
  int stage_v_433_1 = (((stage_v_365_1 * 3) + pub_r001944_11_1) + 7) & 127;
  int stage_v_433_2 = (((stage_v_365_2 * 3) + pub_r001944_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_433_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_433_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_433_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_433_2 * 2)) & 255;
  int stage_v_434_1 = (((stage_v_386_1 * 3) + pub_r001944_12_1) + 24) & 127;
  int stage_v_434_2 = (((stage_v_386_2 * 3) + pub_r001944_12_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_434_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_434_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_434_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_434_2 * 2)) & 255;
  int stage_v_435_1 = ((pub_r001944_19_1 * 2) + 30) & 63;
  int stage_v_435_2 = ((pub_r001944_19_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = (((sec_r001944_8_1 * 3) + pub_r001944_22_1) + 14) & 127;
  int stage_v_436_2 = (((sec_r001944_8_2 * 3) + pub_r001944_22_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_436_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_436_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_436_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_436_2 * 2)) & 255;
  int stage_v_437_1 = (((stage_v_41_1 * 3) + pub_r001944_4_1) + 19) & 127;
  int stage_v_437_2 = (((stage_v_41_2 * 3) + pub_r001944_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_437_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_437_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_437_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_437_2 * 2)) & 255;
  int stage_v_438_1 = ((pub_r001944_9_1 * 2) + 9) & 63;
  int stage_v_438_2 = ((pub_r001944_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = ((pub_r001944_10_1 * 2) + 40) & 63;
  int stage_v_439_2 = ((pub_r001944_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = ((pub_r001944_19_1 * 2) + 33) & 63;
  int stage_v_440_2 = ((pub_r001944_19_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((pub_r001944_16_1 * 2) + 41) & 63;
  int stage_v_441_2 = ((pub_r001944_16_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = (((stage_v_125_1 * 3) + pub_r001944_15_1) + 10) & 127;
  int stage_v_442_2 = (((stage_v_125_2 * 3) + pub_r001944_15_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_442_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_442_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_442_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_442_2 * 2)) & 255;
  int stage_v_443_1 = ((pub_r001944_0_1 * 2) + 20) & 63;
  int stage_v_443_2 = ((pub_r001944_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((pub_r001944_6_1 * 2) + 28) & 63;
  int stage_v_444_2 = ((pub_r001944_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = (((stage_v_123_1 * 3) + pub_r001944_13_1) + 22) & 127;
  int stage_v_445_2 = (((stage_v_123_2 * 3) + pub_r001944_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_445_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_445_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_445_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_445_2 * 2)) & 255;
  int stage_v_446_1 = ((pub_r001944_11_1 * 2) + 23) & 63;
  int stage_v_446_2 = ((pub_r001944_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_446_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_446_2) & 127;
  int stage_v_447_1 = ((pub_r001944_10_1 * 2) + 6) & 63;
  int stage_v_447_2 = ((pub_r001944_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_447_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_447_2) & 127;
  int stage_v_448_1 = (((stage_v_206_1 * 3) + pub_r001944_18_1) + 5) & 127;
  int stage_v_448_2 = (((stage_v_206_2 * 3) + pub_r001944_18_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_448_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_448_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_448_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_448_2 * 2)) & 255;
  int stage_v_449_1 = (((stage_v_379_1 * 3) + pub_r001944_5_1) + 27) & 127;
  int stage_v_449_2 = (((stage_v_379_2 * 3) + pub_r001944_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_449_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_449_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_449_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_449_2 * 2)) & 255;
  int stage_v_450_1 = (((stage_v_292_1 * 3) + pub_r001944_19_1) + 11) & 127;
  int stage_v_450_2 = (((stage_v_292_2 * 3) + pub_r001944_19_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_450_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_450_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_450_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_450_2 * 2)) & 255;
  int stage_v_451_1 = (((stage_v_379_1 * 3) + pub_r001944_9_1) + 36) & 127;
  int stage_v_451_2 = (((stage_v_379_2 * 3) + pub_r001944_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_451_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_451_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_451_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_451_2 * 2)) & 255;
  int stage_v_452_1 = (((stage_v_292_1 * 3) + pub_r001944_1_1) + 19) & 127;
  int stage_v_452_2 = (((stage_v_292_2 * 3) + pub_r001944_1_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_452_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_452_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_452_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_452_2 * 2)) & 255;
  int stage_v_453_1 = (((stage_v_193_1 * 3) + pub_r001944_23_1) + 10) & 127;
  int stage_v_453_2 = (((stage_v_193_2 * 3) + pub_r001944_23_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_453_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_453_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_453_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_453_2 * 2)) & 255;
  int stage_v_454_1 = ((pub_r001944_16_1 * 2) + 24) & 63;
  int stage_v_454_2 = ((pub_r001944_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_454_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_454_2) & 127;
  int stage_v_455_1 = (((stage_v_47_1 * 3) + pub_r001944_22_1) + 14) & 127;
  int stage_v_455_2 = (((stage_v_47_2 * 3) + pub_r001944_22_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_455_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_455_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_455_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_455_2 * 2)) & 255;
  int stage_v_456_1 = (((helper_flow_3_1 * 3) + pub_r001944_12_1) + 4) & 127;
  int stage_v_456_2 = (((helper_flow_3_2 * 3) + pub_r001944_12_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_456_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_456_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_456_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_456_2 * 2)) & 255;
  int stage_v_457_1 = (((stage_v_117_1 * 3) + pub_r001944_23_1) + 7) & 127;
  int stage_v_457_2 = (((stage_v_117_2 * 3) + pub_r001944_23_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_457_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_457_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_457_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_457_2 * 2)) & 255;
  int stage_v_458_1 = ((pub_r001944_22_1 * 2) + 33) & 63;
  int stage_v_458_2 = ((pub_r001944_22_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_458_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_458_2) & 127;
  int stage_v_459_1 = ((pub_r001944_19_1 * 2) + 40) & 63;
  int stage_v_459_2 = ((pub_r001944_19_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_459_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_459_2) & 127;
  int stage_v_460_1 = ((pub_r001944_14_1 * 2) + 23) & 63;
  int stage_v_460_2 = ((pub_r001944_14_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_460_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_460_2) & 127;
  int stage_v_461_1 = ((pub_r001944_13_1 * 2) + 21) & 63;
  int stage_v_461_2 = ((pub_r001944_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = (((stage_v_242_1 * 3) + pub_r001944_22_1) + 28) & 127;
  int stage_v_462_2 = (((stage_v_242_2 * 3) + pub_r001944_22_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_462_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_462_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_462_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_462_2 * 2)) & 255;
  int stage_v_463_1 = ((pub_r001944_1_1 * 2) + 39) & 63;
  int stage_v_463_2 = ((pub_r001944_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_463_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_463_2) & 127;
  int stage_v_464_1 = ((pub_r001944_6_1 * 2) + 46) & 63;
  int stage_v_464_2 = ((pub_r001944_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_464_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_464_2) & 127;
  int stage_v_465_1 = (((stage_v_36_1 * 3) + pub_r001944_9_1) + 37) & 127;
  int stage_v_465_2 = (((stage_v_36_2 * 3) + pub_r001944_9_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_465_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_465_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_465_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_465_2 * 2)) & 255;
  int stage_v_466_1 = (((stage_v_349_1 * 3) + pub_r001944_8_1) + 30) & 127;
  int stage_v_466_2 = (((stage_v_349_2 * 3) + pub_r001944_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_466_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_466_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_466_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_466_2 * 2)) & 255;
  int stage_v_467_1 = ((pub_r001944_18_1 * 2) + 44) & 63;
  int stage_v_467_2 = ((pub_r001944_18_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_467_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_467_2) & 127;
  int stage_v_468_1 = (((stage_v_406_1 * 3) + pub_r001944_11_1) + 33) & 127;
  int stage_v_468_2 = (((stage_v_406_2 * 3) + pub_r001944_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_468_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_468_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_468_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_468_2 * 2)) & 255;
  int stage_v_469_1 = (((stage_v_302_1 * 3) + pub_r001944_5_1) + 4) & 127;
  int stage_v_469_2 = (((stage_v_302_2 * 3) + pub_r001944_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_469_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_469_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_469_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_469_2 * 2)) & 255;
  int stage_v_470_1 = (((stage_v_390_1 * 3) + pub_r001944_3_1) + 25) & 127;
  int stage_v_470_2 = (((stage_v_390_2 * 3) + pub_r001944_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_470_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_470_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_470_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_470_2 * 2)) & 255;
  int stage_v_471_1 = (((stage_v_429_1 * 3) + pub_r001944_0_1) + 7) & 127;
  int stage_v_471_2 = (((stage_v_429_2 * 3) + pub_r001944_0_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_471_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_471_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_471_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_471_2 * 2)) & 255;
  int stage_v_472_1 = ((pub_r001944_0_1 * 2) + 36) & 63;
  int stage_v_472_2 = ((pub_r001944_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_472_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_472_2) & 127;
  int stage_v_473_1 = ((pub_r001944_22_1 * 2) + 12) & 63;
  int stage_v_473_2 = ((pub_r001944_22_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_473_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_473_2) & 127;
  int stage_v_474_1 = ((pub_r001944_1_1 * 2) + 22) & 63;
  int stage_v_474_2 = ((pub_r001944_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_474_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_474_2) & 127;
  int stage_v_475_1 = ((pub_r001944_21_1 * 2) + 28) & 63;
  int stage_v_475_2 = ((pub_r001944_21_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_475_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_475_2) & 127;
  int stage_v_476_1 = (((stage_v_153_1 * 3) + pub_r001944_4_1) + 44) & 127;
  int stage_v_476_2 = (((stage_v_153_2 * 3) + pub_r001944_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_476_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_476_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_476_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_476_2 * 2)) & 255;
  int stage_v_477_1 = (((stage_v_265_1 * 3) + pub_r001944_3_1) + 31) & 127;
  int stage_v_477_2 = (((stage_v_265_2 * 3) + pub_r001944_3_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_477_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_477_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_477_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_477_2 * 2)) & 255;
  int stage_v_478_1 = (((stage_v_410_1 * 3) + pub_r001944_8_1) + 43) & 127;
  int stage_v_478_2 = (((stage_v_410_2 * 3) + pub_r001944_8_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_478_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_478_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_478_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_478_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001944_19_1 == pub_r001944_19_2);
  __CPROVER_assume(pub_r001944_1_1 == pub_r001944_1_2);
  __CPROVER_assume(sec_r001944_17_1 != sec_r001944_17_2);
  __CPROVER_assume(sec_r001944_14_1 != sec_r001944_14_2);
  __CPROVER_assume(sec_r001944_21_1 != sec_r001944_21_2);
  __CPROVER_assume(sec_r001944_18_1 != sec_r001944_18_2);
  __CPROVER_assume(pub_r001944_8_1 == pub_r001944_8_2);
  __CPROVER_assume(sec_r001944_11_1 != sec_r001944_11_2);
  __CPROVER_assume(sec_r001944_13_1 != sec_r001944_13_2);
  __CPROVER_assume(pub_r001944_20_1 == pub_r001944_20_2);
  __CPROVER_assume(sec_r001944_9_1 != sec_r001944_9_2);
  __CPROVER_assume(sec_r001944_7_1 != sec_r001944_7_2);
  __CPROVER_assume(sec_r001944_1_1 != sec_r001944_1_2);
  __CPROVER_assume(sec_r001944_5_1 != sec_r001944_5_2);
  __CPROVER_assume(pub_r001944_16_1 == pub_r001944_16_2);
  __CPROVER_assume(pub_r001944_9_1 == pub_r001944_9_2);
  __CPROVER_assume(sec_r001944_3_1 != sec_r001944_3_2);
  __CPROVER_assume(pub_r001944_6_1 == pub_r001944_6_2);
  __CPROVER_assume(pub_r001944_22_1 == pub_r001944_22_2);
  __CPROVER_assume(pub_r001944_2_1 == pub_r001944_2_2);
  __CPROVER_assume(sec_r001944_8_1 != sec_r001944_8_2);
  __CPROVER_assume(pub_r001944_10_1 == pub_r001944_10_2);
  __CPROVER_assume(sec_r001944_6_1 != sec_r001944_6_2);
  __CPROVER_assume(pub_r001944_18_1 == pub_r001944_18_2);
  __CPROVER_assume(pub_r001944_17_1 == pub_r001944_17_2);
  __CPROVER_assume(pub_r001944_23_1 == pub_r001944_23_2);
  __CPROVER_assume(sec_r001944_4_1 != sec_r001944_4_2);
  __CPROVER_assume(sec_r001944_20_1 != sec_r001944_20_2);
  __CPROVER_assume(pub_r001944_4_1 == pub_r001944_4_2);
  __CPROVER_assume(pub_r001944_14_1 == pub_r001944_14_2);
  __CPROVER_assume(pub_r001944_12_1 == pub_r001944_12_2);
  __CPROVER_assume(sec_r001944_2_1 != sec_r001944_2_2);
  __CPROVER_assume(pub_r001944_21_1 == pub_r001944_21_2);
  __CPROVER_assume(sec_r001944_12_1 != sec_r001944_12_2);
  __CPROVER_assume(sec_r001944_10_1 != sec_r001944_10_2);
  __CPROVER_assume(sec_r001944_15_1 != sec_r001944_15_2);
  __CPROVER_assume(pub_r001944_15_1 == pub_r001944_15_2);
  __CPROVER_assume(pub_r001944_13_1 == pub_r001944_13_2);
  __CPROVER_assume(pub_r001944_7_1 == pub_r001944_7_2);
  __CPROVER_assume(pub_r001944_5_1 == pub_r001944_5_2);
  __CPROVER_assume(sec_r001944_16_1 != sec_r001944_16_2);
  __CPROVER_assume(sec_r001944_19_1 != sec_r001944_19_2);
  __CPROVER_assume(pub_r001944_3_1 == pub_r001944_3_2);
  __CPROVER_assume(sec_r001944_0_1 != sec_r001944_0_2);
  __CPROVER_assume(pub_r001944_0_1 == pub_r001944_0_2);
  __CPROVER_assume(pub_r001944_11_1 == pub_r001944_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
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
  assert(helper_flow_3_1 == helper_flow_3_2);
  assert(helper_flow_4_1 == helper_flow_4_2);
  assert(helper_flow_5_1 == helper_flow_5_2);
  assert(helper_flow_6_1 == helper_flow_6_2);
  assert(helper_flow_7_1 == helper_flow_7_2);
  assert(helper_flow_8_1 == helper_flow_8_2);
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
  assert(stage_v_470_1 == stage_v_470_2);
  assert(stage_v_471_1 == stage_v_471_2);
  assert(stage_v_472_1 == stage_v_472_2);
  assert(stage_v_473_1 == stage_v_473_2);
  assert(stage_v_474_1 == stage_v_474_2);
  assert(stage_v_475_1 == stage_v_475_2);
  assert(stage_v_476_1 == stage_v_476_2);
  assert(stage_v_477_1 == stage_v_477_2);
  assert(stage_v_478_1 == stage_v_478_2);
}


