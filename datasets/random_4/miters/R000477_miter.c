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
struct DeviceConfig_R000477_7713_0
{
  unsigned char port;
  unsigned char timeout;
  short parity;
  short stop_bits;
  int baud_rate;
  int id;
  int buffer[3];
};
struct EventLog_R000477_7713_1
{
  int signature;
  int seq;
  short facility;
  int timestamp;
  short severity;
  int code;
  int buffer[3];
};
struct CipherContext_R000477_7713_2
{
  unsigned char iv;
  int counter;
  unsigned char round_key;
  int buffer[3];
};
struct Vector3D_R000477_7713_3
{
  short coord_x;
  unsigned char heading;
  short pitch;
  unsigned char coord_y;
  int coord_z;
  int norm_sq;
  int buffer[3];
};
union RegisterBank_R000477_7713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000477_7713_1
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
void fn_R000477_7713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000477_7713_2 st_1 = {0};
  struct CipherContext_R000477_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int metric_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_27_1) & 63;
  aux_2 = (aux_2 + metric_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_10_1 = 0;
  int factor_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_10_1 = ((factor_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_10_2 = ((factor_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_10_1) & 127;
    acc_2 = (acc_2 + factor_10_2) & 127;
  }

  int weight_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_80_1)
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

  switch (weight_80_2)
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

  int coefficient_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_89_1 > 44)
  {
    acc_1 = ((acc_1 + (coefficient_89_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_89_2 > 44)
  {
    acc_2 = ((acc_2 + (coefficient_89_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_89_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_27_1 == metric_27_2);
  assert(factor_10_1 == factor_10_2);
  assert(weight_80_1 == weight_80_2);
  assert(coefficient_89_1 == coefficient_89_2);
}

int fn_R000477_7713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000477_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int metric_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_27) & 63;
  acc ^= aux;
  int factor_10 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_10 = ((factor_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_10) & 127;
  }

  int weight_80 = (aux + st.buffer[1]) & 3;
  switch (weight_80)
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

  int coefficient_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_89 > 44)
  {
    acc = ((acc + (coefficient_89 * 2)) + 5) & 127;
    aux ^= coefficient_89 & 15;
  }
  else
  {
    acc = ((acc - coefficient_89) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000477_7713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000477_7713_3 st_1 = {0};
  struct Vector3D_R000477_7713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int metric_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_91_1)
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

  switch (metric_91_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_25_1 = local_arr_1[aux_1 % 3];
  int vector_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_25_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_91_1 == metric_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_25_1 == vector_25_2);
}

int fn_R000477_7713_1(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000477_7713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int metric_91 = (aux + st.buffer[1]) & 3;
  switch (metric_91)
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

  int local_arr[3] = {4, 9, 15};
  int vector_25 = local_arr[aux % 3];
  acc = (acc + (vector_25 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000477_7713_3 st_1 = {0};
  struct Vector3D_R000477_7713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_51_1 = 0;
  int index_reg_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_51_1 = ((index_reg_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_51_2 = ((index_reg_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_51_1) & 127;
    acc_2 = (acc_2 + index_reg_51_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_70_1 = local_arr_1[aux_1 % 3];
  int tally_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_70_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_51_1 == index_reg_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_70_1 == tally_70_2);
}

int fn_R000477_7713_2(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000477_7713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_51 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_51 = ((index_reg_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_51) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tally_70 = local_arr[aux % 3];
  acc = (acc + (tally_70 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st_1 = {0};
  struct EventLog_R000477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int threshold_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_60_1)
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

  switch (threshold_60_2)
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

  int metric_57_1 = 0;
  int metric_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_57_1 = ((metric_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_57_2 = ((metric_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_57_1) & 127;
    acc_2 = (acc_2 + metric_57_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_60_1 == threshold_60_2);
  assert(metric_57_1 == metric_57_2);
}

int fn_R000477_7713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int threshold_60 = (aux + st.buffer[1]) & 3;
  switch (threshold_60)
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

  int metric_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_57 = ((metric_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_57) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000477_7713_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000477_7713_0 st_1 = {0};
  struct DeviceConfig_R000477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int pivot_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_38_1) & 63;
  aux_2 = (aux_2 + pivot_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_68_1 > 22)
  {
    acc_1 = ((acc_1 + (margin_68_1 * 2)) + 5) & 127;
    aux_1 ^= margin_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_68_2 > 22)
  {
    acc_2 = ((acc_2 + (margin_68_2 * 2)) + 5) & 127;
    aux_2 ^= margin_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_68_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_38_1 == pivot_38_2);
  assert(margin_68_1 == margin_68_2);
}

int fn_R000477_7713_4(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int pivot_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_38) & 63;
  acc ^= aux;
  int margin_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_68 > 22)
  {
    acc = ((acc + (margin_68 * 2)) + 5) & 127;
    aux ^= margin_68 & 15;
  }
  else
  {
    acc = ((acc - margin_68) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000477_7713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st_1 = {0};
  struct EventLog_R000477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_94_1) & 63;
  aux_2 = (aux_2 + weight_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_94_1 == weight_94_2);
}

int fn_R000477_7713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_94) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000477_7713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000477_7713_0 st_1 = {0};
  struct DeviceConfig_R000477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_50_1 = local_arr_1[aux_1 % 3];
  int factor_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_50_2 * 2)) & 127;
  int mask_85_1 = 0;
  int mask_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_85_1 = ((mask_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_85_2 = ((mask_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_85_1) & 127;
    acc_2 = (acc_2 + mask_85_2) & 127;
  }

  int stride_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_55_1)
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

  switch (stride_55_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_50_1 == factor_50_2);
  assert(mask_85_1 == mask_85_2);
  assert(stride_55_1 == stride_55_2);
}

int fn_R000477_7713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int factor_50 = local_arr[aux % 3];
  acc = (acc + (factor_50 * 2)) & 127;
  int mask_85 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_85 = ((mask_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_85) & 127;
  }

  int stride_55 = (aux + st.buffer[1]) & 3;
  switch (stride_55)
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

void fn_R000477_7713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st_1 = {0};
  struct EventLog_R000477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int tally_66_1 = 0;
  int tally_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_66_1 = ((tally_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_66_2 = ((tally_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_66_1) & 127;
    acc_2 = (acc_2 + tally_66_2) & 127;
  }

  int mask_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_30_1 > 20)
  {
    acc_1 = ((acc_1 + (mask_30_1 * 2)) + 5) & 127;
    aux_1 ^= mask_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_30_2 > 20)
  {
    acc_2 = ((acc_2 + (mask_30_2 * 2)) + 5) & 127;
    aux_2 ^= mask_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_30_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_70_1)
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

  switch (metric_70_2)
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
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_66_1 == tally_66_2);
  assert(mask_30_1 == mask_30_2);
  assert(metric_70_1 == metric_70_2);
}

int fn_R000477_7713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int tally_66 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_66 = ((tally_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_66) & 127;
  }

  int mask_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_30 > 20)
  {
    acc = ((acc + (mask_30 * 2)) + 5) & 127;
    aux ^= mask_30 & 15;
  }
  else
  {
    acc = ((acc - mask_30) + 11) & 127;
    aux += 3;
  }
  int metric_70 = (aux + st.buffer[1]) & 3;
  switch (metric_70)
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

void fn_R000477_7713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st_1 = {0};
  struct EventLog_R000477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int tracker_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_13_1 > 29)
  {
    acc_1 = ((acc_1 + (tracker_13_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_13_2 > 29)
  {
    acc_2 = ((acc_2 + (tracker_13_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_81_1 = local_arr_1[aux_1 % 3];
  int sample_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_81_2 * 2)) & 127;
  int accumulator_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_66_1)
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

  switch (accumulator_66_2)
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
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_13_1 == tracker_13_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_81_1 == sample_81_2);
  assert(accumulator_66_1 == accumulator_66_2);
}

int fn_R000477_7713_8(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int tracker_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_13 > 29)
  {
    acc = ((acc + (tracker_13 * 2)) + 5) & 127;
    aux ^= tracker_13 & 15;
  }
  else
  {
    acc = ((acc - tracker_13) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int sample_81 = local_arr[aux % 3];
  acc = (acc + (sample_81 * 2)) & 127;
  int accumulator_66 = (aux + st.buffer[1]) & 3;
  switch (accumulator_66)
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

void fn_R000477_7713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000477_7713_2 st_1 = {0};
  struct CipherContext_R000477_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int sample_65_1 = 0;
  int sample_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_65_1 = ((sample_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_65_2 = ((sample_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_65_1) & 127;
    acc_2 = (acc_2 + sample_65_2) & 127;
  }

  int threshold_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_34_1 > 42)
  {
    acc_1 = ((acc_1 + (threshold_34_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_34_2 > 42)
  {
    acc_2 = ((acc_2 + (threshold_34_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_34_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_65_1 == sample_65_2);
  assert(threshold_34_1 == threshold_34_2);
}

int fn_R000477_7713_9(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000477_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int sample_65 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_65 = ((sample_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_65) & 127;
  }

  int threshold_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_34 > 42)
  {
    acc = ((acc + (threshold_34 * 2)) + 5) & 127;
    aux ^= threshold_34 & 15;
  }
  else
  {
    acc = ((acc - threshold_34) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000477_7713_0 st_1 = {0};
  struct DeviceConfig_R000477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int residue_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_99_1)
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

  switch (residue_99_2)
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

  int tally_96_1 = 0;
  int tally_96_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_96_1 = ((tally_96_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_96_2 = ((tally_96_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_96_1) & 127;
    acc_2 = (acc_2 + tally_96_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_99_1 == residue_99_2);
  assert(tally_96_1 == tally_96_2);
}

int fn_R000477_7713_10(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int residue_99 = (aux + st.buffer[1]) & 3;
  switch (residue_99)
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

  int tally_96 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_96 = ((tally_96 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_96) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000477_7713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000477_7713_0 st_1 = {0};
  struct DeviceConfig_R000477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_90_1)
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

  switch (scale_90_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_90_1 == scale_90_2);
}

int fn_R000477_7713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_90 = (aux + st.buffer[1]) & 3;
  switch (scale_90)
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

void fn_R000477_7713_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000477_7713_0 st_1 = {0};
  struct DeviceConfig_R000477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int bound_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_76_1) & 63;
  aux_2 = (aux_2 + bound_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_23_1 = local_arr_1[aux_1 % 3];
  int tally_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_23_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_69_1)
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

  switch (delta_69_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_76_1 == bound_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_23_1 == tally_23_2);
  assert(delta_69_1 == delta_69_2);
}

int fn_R000477_7713_12(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int bound_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_76) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tally_23 = local_arr[aux % 3];
  acc = (acc + (tally_23 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_69 = (aux + st.buffer[1]) & 3;
  switch (delta_69)
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

void fn_R000477_7713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000477_7713_2 st_1 = {0};
  struct CipherContext_R000477_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_69_1 = 0;
  int factor_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_69_1 = ((factor_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_69_2 = ((factor_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_69_1) & 127;
    acc_2 = (acc_2 + factor_69_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_69_1 == factor_69_2);
}

int fn_R000477_7713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000477_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_69 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_69 = ((factor_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_69) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000477_7713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000477_7713_3 st_1 = {0};
  struct Vector3D_R000477_7713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int cursor_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_34_1) & 63;
  aux_2 = (aux_2 + cursor_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_32_1)
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

  switch (sample_32_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_34_1 == cursor_34_2);
  assert(sample_32_1 == sample_32_2);
}

int fn_R000477_7713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000477_7713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int cursor_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_34) & 63;
  acc ^= aux;
  int sample_32 = (aux + st.buffer[1]) & 3;
  switch (sample_32)
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

  return (acc + aux) & 255;
}

void fn_R000477_7713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000477_7713_3 st_1 = {0};
  struct Vector3D_R000477_7713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int vector_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_40_1 > 19)
  {
    acc_1 = ((acc_1 + (vector_40_1 * 2)) + 5) & 127;
    aux_1 ^= vector_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_40_2 > 19)
  {
    acc_2 = ((acc_2 + (vector_40_2 * 2)) + 5) & 127;
    aux_2 ^= vector_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_59_1)
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

  switch (coefficient_59_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_40_1 == vector_40_2);
  assert(coefficient_59_1 == coefficient_59_2);
}

int fn_R000477_7713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000477_7713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int vector_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_40 > 19)
  {
    acc = ((acc + (vector_40 * 2)) + 5) & 127;
    aux ^= vector_40 & 15;
  }
  else
  {
    acc = ((acc - vector_40) + 11) & 127;
    aux += 3;
  }
  int coefficient_59 = (aux + st.buffer[1]) & 3;
  switch (coefficient_59)
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

void fn_R000477_7713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st_1 = {0};
  struct EventLog_R000477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int bound_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_56_1 > 29)
  {
    acc_1 = ((acc_1 + (bound_56_1 * 2)) + 5) & 127;
    aux_1 ^= bound_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_56_2 > 29)
  {
    acc_2 = ((acc_2 + (bound_56_2 * 2)) + 5) & 127;
    aux_2 ^= bound_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_56_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_56_1 == bound_56_2);
}

int fn_R000477_7713_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int bound_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_56 > 29)
  {
    acc = ((acc + (bound_56 * 2)) + 5) & 127;
    aux ^= bound_56 & 15;
  }
  else
  {
    acc = ((acc - bound_56) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st_1 = {0};
  struct EventLog_R000477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_87_1 = 0;
  int index_reg_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_87_1 = ((index_reg_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_87_2 = ((index_reg_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_87_1) & 127;
    acc_2 = (acc_2 + index_reg_87_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_87_1 == index_reg_87_2);
}

int fn_R000477_7713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_87 = ((index_reg_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_87) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000477_7713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000477_7713_3 st_1 = {0};
  struct Vector3D_R000477_7713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int damping_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_66_1) & 63;
  aux_2 = (aux_2 + damping_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_19_1 = local_arr_1[aux_1 % 3];
  int accumulator_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_19_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_66_1 == damping_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_19_1 == accumulator_19_2);
}

int fn_R000477_7713_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000477_7713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int damping_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_66) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int accumulator_19 = local_arr[aux % 3];
  acc = (acc + (accumulator_19 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000477_7713_2 st_1 = {0};
  struct CipherContext_R000477_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_13_1) & 63;
  aux_2 = (aux_2 + weight_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_59_1 > 42)
  {
    acc_1 = ((acc_1 + (parity_59_1 * 2)) + 5) & 127;
    aux_1 ^= parity_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_59_2 > 42)
  {
    acc_2 = ((acc_2 + (parity_59_2 * 2)) + 5) & 127;
    aux_2 ^= parity_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_13_1 == weight_13_2);
  assert(parity_59_1 == parity_59_2);
}

int fn_R000477_7713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000477_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_13) & 63;
  acc ^= aux;
  int parity_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_59 > 42)
  {
    acc = ((acc + (parity_59 * 2)) + 5) & 127;
    aux ^= parity_59 & 15;
  }
  else
  {
    acc = ((acc - parity_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000477_7713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st_1 = {0};
  struct EventLog_R000477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int anchor_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_43_1) & 63;
  aux_2 = (aux_2 + anchor_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_25_1 > 31)
  {
    acc_1 = ((acc_1 + (stride_25_1 * 2)) + 5) & 127;
    aux_1 ^= stride_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_25_2 > 31)
  {
    acc_2 = ((acc_2 + (stride_25_2 * 2)) + 5) & 127;
    aux_2 ^= stride_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_25_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_43_1 == anchor_43_2);
  assert(stride_25_1 == stride_25_2);
}

int fn_R000477_7713_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int anchor_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_43) & 63;
  acc ^= aux;
  int stride_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_25 > 31)
  {
    acc = ((acc + (stride_25 * 2)) + 5) & 127;
    aux ^= stride_25 & 15;
  }
  else
  {
    acc = ((acc - stride_25) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000477_7713_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st_1 = {0};
  struct EventLog_R000477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int window_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_28_1) & 63;
  aux_2 = (aux_2 + window_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_30_1 = local_arr_1[aux_1 % 3];
  int quantum_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_30_2 * 2)) & 127;
  int phase_85_1 = 0;
  int phase_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_85_1 = ((phase_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_85_2 = ((phase_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_85_1) & 127;
    acc_2 = (acc_2 + phase_85_2) & 127;
  }

  int delta_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_10_1)
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

  switch (delta_10_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_28_1 == window_28_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_30_1 == quantum_30_2);
  assert(phase_85_1 == phase_85_2);
  assert(delta_10_1 == delta_10_2);
}

int fn_R000477_7713_21(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int window_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_28) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quantum_30 = local_arr[aux % 3];
  acc = (acc + (quantum_30 * 2)) & 127;
  int phase_85 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_85 = ((phase_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_85) & 127;
  }

  int delta_10 = (aux + st.buffer[1]) & 3;
  switch (delta_10)
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

  return (acc + aux) & 255;
}

void fn_R000477_7713_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st_1 = {0};
  struct EventLog_R000477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_86_1) & 63;
  aux_2 = (aux_2 + cursor_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_87_1 = local_arr_1[aux_1 % 3];
  int index_reg_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_87_2 * 2)) & 127;
  int vector_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_40_1)
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

  switch (vector_40_2)
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
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_86_1 == cursor_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_87_1 == index_reg_87_2);
  assert(vector_40_1 == vector_40_2);
}

int fn_R000477_7713_22(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_86) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_87 = local_arr[aux % 3];
  acc = (acc + (index_reg_87 * 2)) & 127;
  int vector_40 = (aux + st.buffer[1]) & 3;
  switch (vector_40)
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

void fn_R000477_7713_23_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000477_7713_2 st_1 = {0};
  struct CipherContext_R000477_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_74_1 = local_arr_1[aux_1 % 3];
  int metric_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_74_2 * 2)) & 127;
  int offset_19_1 = 0;
  int offset_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_19_1 = ((offset_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_19_2 = ((offset_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_19_1) & 127;
    acc_2 = (acc_2 + offset_19_2) & 127;
  }

  int damping_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_75_1) & 63;
  aux_2 = (aux_2 + damping_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_74_1 == metric_74_2);
  assert(offset_19_1 == offset_19_2);
  assert(damping_75_1 == damping_75_2);
}

int fn_R000477_7713_23(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000477_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int metric_74 = local_arr[aux % 3];
  acc = (acc + (metric_74 * 2)) & 127;
  int offset_19 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_19 = ((offset_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_19) & 127;
  }

  int damping_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_75) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000477_7713_24_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st_1 = {0};
  struct EventLog_R000477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int scale_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_19_1 > 16)
  {
    acc_1 = ((acc_1 + (scale_19_1 * 2)) + 5) & 127;
    aux_1 ^= scale_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_19_2 > 16)
  {
    acc_2 = ((acc_2 + (scale_19_2 * 2)) + 5) & 127;
    aux_2 ^= scale_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_73_1 = 0;
  int cursor_73_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_73_1 = ((cursor_73_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_73_2 = ((cursor_73_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_73_1) & 127;
    acc_2 = (acc_2 + cursor_73_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_29_1 = local_arr_1[aux_1 % 3];
  int quantum_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_29_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_19_1 == scale_19_2);
  assert(cursor_73_1 == cursor_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_29_1 == quantum_29_2);
}

int fn_R000477_7713_24(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int scale_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_19 > 16)
  {
    acc = ((acc + (scale_19 * 2)) + 5) & 127;
    aux ^= scale_19 & 15;
  }
  else
  {
    acc = ((acc - scale_19) + 11) & 127;
    aux += 3;
  }
  int cursor_73 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_73 = ((cursor_73 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_73) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int quantum_29 = local_arr[aux % 3];
  acc = (acc + (quantum_29 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000477_7713_25_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000477_7713_2 st_1 = {0};
  struct CipherContext_R000477_7713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int parity_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_55_1) & 63;
  aux_2 = (aux_2 + parity_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_60_1)
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

  switch (segment_60_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_60_1 = 0;
  int sample_60_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_60_1 = ((sample_60_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_60_2 = ((sample_60_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_60_1) & 127;
    acc_2 = (acc_2 + sample_60_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.counter == st_2.counter);
  assert(st_1.round_key == st_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_55_1 == parity_55_2);
  assert(segment_60_1 == segment_60_2);
  assert(sample_60_1 == sample_60_2);
}

int fn_R000477_7713_25(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000477_7713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int parity_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_55) & 63;
  acc ^= aux;
  int segment_60 = (aux + st.buffer[1]) & 3;
  switch (segment_60)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_60 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_60 = ((sample_60 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_60) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r000477_0_1;
  int sec_r000477_0_2;
  int sec_r000477_1_1;
  int sec_r000477_1_2;
  int sec_r000477_2_1;
  int sec_r000477_2_2;
  int sec_r000477_3_1;
  int sec_r000477_3_2;
  int sec_r000477_4_1;
  int sec_r000477_4_2;
  int sec_r000477_5_1;
  int sec_r000477_5_2;
  int sec_r000477_6_1;
  int sec_r000477_6_2;
  int sec_r000477_7_1;
  int sec_r000477_7_2;
  int sec_r000477_8_1;
  int sec_r000477_8_2;
  int sec_r000477_9_1;
  int sec_r000477_9_2;
  int sec_r000477_10_1;
  int sec_r000477_10_2;
  int sec_r000477_11_1;
  int sec_r000477_11_2;
  int sec_r000477_12_1;
  int sec_r000477_12_2;
  int sec_r000477_13_1;
  int sec_r000477_13_2;
  int sec_r000477_14_1;
  int sec_r000477_14_2;
  int sec_r000477_15_1;
  int sec_r000477_15_2;
  int sec_r000477_16_1;
  int sec_r000477_16_2;
  int sec_r000477_17_1;
  int sec_r000477_17_2;
  int sec_r000477_18_1;
  int sec_r000477_18_2;
  int pub_r000477_0_1;
  int pub_r000477_0_2;
  int pub_r000477_1_1;
  int pub_r000477_1_2;
  int pub_r000477_2_1;
  int pub_r000477_2_2;
  int pub_r000477_3_1;
  int pub_r000477_3_2;
  int pub_r000477_4_1;
  int pub_r000477_4_2;
  int pub_r000477_5_1;
  int pub_r000477_5_2;
  int pub_r000477_6_1;
  int pub_r000477_6_2;
  int pub_r000477_7_1;
  int pub_r000477_7_2;
  int pub_r000477_8_1;
  int pub_r000477_8_2;
  int pub_r000477_9_1;
  int pub_r000477_9_2;
  int pub_r000477_10_1;
  int pub_r000477_10_2;
  int pub_r000477_11_1;
  int pub_r000477_11_2;
  int pub_r000477_12_1;
  int pub_r000477_12_2;
  int pub_r000477_13_1;
  int pub_r000477_13_2;
  int pub_r000477_14_1;
  int pub_r000477_14_2;
  int pub_r000477_15_1;
  int pub_r000477_15_2;
  int pub_r000477_16_1;
  int pub_r000477_16_2;
  int pub_r000477_17_1;
  int pub_r000477_17_2;
  int pub_r000477_18_1;
  int pub_r000477_18_2;
  int pub_r000477_19_1;
  int pub_r000477_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000477_0_1 >= (-100)) && (pub_r000477_0_1 <= 100));
  __CPROVER_assume((pub_r000477_0_2 >= (-100)) && (pub_r000477_0_2 <= 100));
  __CPROVER_assume((pub_r000477_1_1 >= (-100)) && (pub_r000477_1_1 <= 100));
  __CPROVER_assume((pub_r000477_1_2 >= (-100)) && (pub_r000477_1_2 <= 100));
  __CPROVER_assume((pub_r000477_2_1 >= (-100)) && (pub_r000477_2_1 <= 100));
  __CPROVER_assume((pub_r000477_2_2 >= (-100)) && (pub_r000477_2_2 <= 100));
  __CPROVER_assume((pub_r000477_3_1 >= (-100)) && (pub_r000477_3_1 <= 100));
  __CPROVER_assume((pub_r000477_3_2 >= (-100)) && (pub_r000477_3_2 <= 100));
  __CPROVER_assume((pub_r000477_4_1 >= (-100)) && (pub_r000477_4_1 <= 100));
  __CPROVER_assume((pub_r000477_4_2 >= (-100)) && (pub_r000477_4_2 <= 100));
  __CPROVER_assume((pub_r000477_5_1 >= (-100)) && (pub_r000477_5_1 <= 100));
  __CPROVER_assume((pub_r000477_5_2 >= (-100)) && (pub_r000477_5_2 <= 100));
  __CPROVER_assume((pub_r000477_6_1 >= (-100)) && (pub_r000477_6_1 <= 100));
  __CPROVER_assume((pub_r000477_6_2 >= (-100)) && (pub_r000477_6_2 <= 100));
  __CPROVER_assume((pub_r000477_7_1 >= (-100)) && (pub_r000477_7_1 <= 100));
  __CPROVER_assume((pub_r000477_7_2 >= (-100)) && (pub_r000477_7_2 <= 100));
  __CPROVER_assume((pub_r000477_8_1 >= (-100)) && (pub_r000477_8_1 <= 100));
  __CPROVER_assume((pub_r000477_8_2 >= (-100)) && (pub_r000477_8_2 <= 100));
  __CPROVER_assume((pub_r000477_9_1 >= (-100)) && (pub_r000477_9_1 <= 100));
  __CPROVER_assume((pub_r000477_9_2 >= (-100)) && (pub_r000477_9_2 <= 100));
  __CPROVER_assume((pub_r000477_10_1 >= (-100)) && (pub_r000477_10_1 <= 100));
  __CPROVER_assume((pub_r000477_10_2 >= (-100)) && (pub_r000477_10_2 <= 100));
  __CPROVER_assume((pub_r000477_11_1 >= (-100)) && (pub_r000477_11_1 <= 100));
  __CPROVER_assume((pub_r000477_11_2 >= (-100)) && (pub_r000477_11_2 <= 100));
  __CPROVER_assume((pub_r000477_12_1 >= (-100)) && (pub_r000477_12_1 <= 100));
  __CPROVER_assume((pub_r000477_12_2 >= (-100)) && (pub_r000477_12_2 <= 100));
  __CPROVER_assume((pub_r000477_13_1 >= (-100)) && (pub_r000477_13_1 <= 100));
  __CPROVER_assume((pub_r000477_13_2 >= (-100)) && (pub_r000477_13_2 <= 100));
  __CPROVER_assume((pub_r000477_14_1 >= (-100)) && (pub_r000477_14_1 <= 100));
  __CPROVER_assume((pub_r000477_14_2 >= (-100)) && (pub_r000477_14_2 <= 100));
  __CPROVER_assume((pub_r000477_15_1 >= (-100)) && (pub_r000477_15_1 <= 100));
  __CPROVER_assume((pub_r000477_15_2 >= (-100)) && (pub_r000477_15_2 <= 100));
  __CPROVER_assume((pub_r000477_16_1 >= (-100)) && (pub_r000477_16_1 <= 100));
  __CPROVER_assume((pub_r000477_16_2 >= (-100)) && (pub_r000477_16_2 <= 100));
  __CPROVER_assume((pub_r000477_17_1 >= (-100)) && (pub_r000477_17_1 <= 100));
  __CPROVER_assume((pub_r000477_17_2 >= (-100)) && (pub_r000477_17_2 <= 100));
  __CPROVER_assume((pub_r000477_18_1 >= (-100)) && (pub_r000477_18_1 <= 100));
  __CPROVER_assume((pub_r000477_18_2 >= (-100)) && (pub_r000477_18_2 <= 100));
  __CPROVER_assume((pub_r000477_19_1 >= (-100)) && (pub_r000477_19_1 <= 100));
  __CPROVER_assume((pub_r000477_19_2 >= (-100)) && (pub_r000477_19_2 <= 100));
  __CPROVER_assume((sec_r000477_0_1 >= 0) && (sec_r000477_0_1 <= 255));
  __CPROVER_assume((sec_r000477_0_2 >= 0) && (sec_r000477_0_2 <= 255));
  __CPROVER_assume((sec_r000477_1_1 >= 0) && (sec_r000477_1_1 <= 255));
  __CPROVER_assume((sec_r000477_1_2 >= 0) && (sec_r000477_1_2 <= 255));
  __CPROVER_assume((sec_r000477_2_1 >= 0) && (sec_r000477_2_1 <= 255));
  __CPROVER_assume((sec_r000477_2_2 >= 0) && (sec_r000477_2_2 <= 255));
  __CPROVER_assume((sec_r000477_3_1 >= 0) && (sec_r000477_3_1 <= 255));
  __CPROVER_assume((sec_r000477_3_2 >= 0) && (sec_r000477_3_2 <= 255));
  __CPROVER_assume((sec_r000477_4_1 >= 0) && (sec_r000477_4_1 <= 255));
  __CPROVER_assume((sec_r000477_4_2 >= 0) && (sec_r000477_4_2 <= 255));
  __CPROVER_assume((sec_r000477_5_1 >= 0) && (sec_r000477_5_1 <= 255));
  __CPROVER_assume((sec_r000477_5_2 >= 0) && (sec_r000477_5_2 <= 255));
  __CPROVER_assume((sec_r000477_6_1 >= 0) && (sec_r000477_6_1 <= 255));
  __CPROVER_assume((sec_r000477_6_2 >= 0) && (sec_r000477_6_2 <= 255));
  __CPROVER_assume((sec_r000477_7_1 >= 0) && (sec_r000477_7_1 <= 255));
  __CPROVER_assume((sec_r000477_7_2 >= 0) && (sec_r000477_7_2 <= 255));
  __CPROVER_assume((sec_r000477_8_1 >= 0) && (sec_r000477_8_1 <= 255));
  __CPROVER_assume((sec_r000477_8_2 >= 0) && (sec_r000477_8_2 <= 255));
  __CPROVER_assume((sec_r000477_9_1 >= 0) && (sec_r000477_9_1 <= 255));
  __CPROVER_assume((sec_r000477_9_2 >= 0) && (sec_r000477_9_2 <= 255));
  __CPROVER_assume((sec_r000477_10_1 >= 0) && (sec_r000477_10_1 <= 255));
  __CPROVER_assume((sec_r000477_10_2 >= 0) && (sec_r000477_10_2 <= 255));
  __CPROVER_assume((sec_r000477_11_1 >= 0) && (sec_r000477_11_1 <= 255));
  __CPROVER_assume((sec_r000477_11_2 >= 0) && (sec_r000477_11_2 <= 255));
  __CPROVER_assume((sec_r000477_12_1 >= 0) && (sec_r000477_12_1 <= 255));
  __CPROVER_assume((sec_r000477_12_2 >= 0) && (sec_r000477_12_2 <= 255));
  __CPROVER_assume((sec_r000477_13_1 >= 0) && (sec_r000477_13_1 <= 255));
  __CPROVER_assume((sec_r000477_13_2 >= 0) && (sec_r000477_13_2 <= 255));
  __CPROVER_assume((sec_r000477_14_1 >= 0) && (sec_r000477_14_1 <= 255));
  __CPROVER_assume((sec_r000477_14_2 >= 0) && (sec_r000477_14_2 <= 255));
  __CPROVER_assume((sec_r000477_15_1 >= 0) && (sec_r000477_15_1 <= 255));
  __CPROVER_assume((sec_r000477_15_2 >= 0) && (sec_r000477_15_2 <= 255));
  __CPROVER_assume((sec_r000477_16_1 >= 0) && (sec_r000477_16_1 <= 255));
  __CPROVER_assume((sec_r000477_16_2 >= 0) && (sec_r000477_16_2 <= 255));
  __CPROVER_assume((sec_r000477_17_1 >= 0) && (sec_r000477_17_1 <= 255));
  __CPROVER_assume((sec_r000477_17_2 >= 0) && (sec_r000477_17_2 <= 255));
  __CPROVER_assume((sec_r000477_18_1 >= 0) && (sec_r000477_18_1 <= 255));
  __CPROVER_assume((sec_r000477_18_2 >= 0) && (sec_r000477_18_2 <= 255));
  struct DeviceConfig_R000477_7713_0 st_var_0_1 = {0};
  struct DeviceConfig_R000477_7713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000477_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000477_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000477_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000477_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000477_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000477_0_2 + 7) & 15;
  struct EventLog_R000477_7713_1 st_var_1_1 = {0};
  struct EventLog_R000477_7713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000477_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000477_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000477_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000477_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000477_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000477_0_2 + 9) & 15;
  struct CipherContext_R000477_7713_2 st_var_2_1 = {0};
  struct CipherContext_R000477_7713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000477_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000477_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000477_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000477_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000477_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000477_0_2 + 11) & 15;
  struct Vector3D_R000477_7713_3 st_var_3_1 = {0};
  struct Vector3D_R000477_7713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000477_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000477_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000477_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000477_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000477_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000477_0_2 + 13) & 15;
  union RegisterBank_R000477_7713_0 u_var_1;
  union RegisterBank_R000477_7713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 1) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 1) & 15;
  int stage_v_0_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_0_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= stage_v_0_1;
  chk_sum_2 ^= stage_v_0_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 2) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 2) & 15;
  int stage_v_1_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_1_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= stage_v_1_1;
  chk_sum_2 ^= stage_v_1_2;
  int stage_v_2_1 = 0;
  int stage_v_2_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_2_1 = ((stage_v_2_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_2_2 = ((stage_v_2_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (st_var_3_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_3_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = (st_var_0_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_0_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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

  int stage_v_5_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (10 & 31);
  int stage_v_5_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (10 & 31);
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= (stage_v_5_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_5_2 << 1) & 127;
  int stage_v_6_1 = (st_var_2_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_2_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 8) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = table_1[0];
  int stage_v_8_2 = table_2[0];
  table_1[0] = (table_1[1] + 17) & 63;
  table_2[0] = (table_2[1] + 17) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (14 & 31);
  int stage_v_9_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (14 & 31);
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= (stage_v_9_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_9_2 << 1) & 127;
  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  int stage_v_11_1 = (st_var_3_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_3_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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

  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
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
  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 16) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  int stage_v_16_1 = table_1[0];
  int stage_v_16_2 = table_2[0];
  table_1[0] = (table_1[1] + 33) & 63;
  table_2[0] = (table_2[1] + 33) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = ((st_var_1_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_1_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 38)
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
  if (stage_v_17_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 38)
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
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 19) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = ((st_var_2_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_2_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 36)
    {
      chk_sum_1 ^= stage_v_22_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_22_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 36)
    {
      chk_sum_2 ^= stage_v_22_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_23_1 = (st_var_3_1.buffer[0] ^ 26) & 3;
  int stage_v_23_2 = (st_var_3_2.buffer[0] ^ 26) & 3;
  switch (stage_v_23_1)
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

  switch (stage_v_23_2)
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

  int stage_v_24_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_24_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_25_1 = ((st_var_1_1.buffer[1] * 2) + 82) & 63;
  int stage_v_25_2 = ((st_var_1_2.buffer[1] * 2) + 82) & 63;
  if (stage_v_25_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_25_1) - 5) & 255;
    if (stage_v_25_1 > 53)
    {
      chk_sum_1 ^= stage_v_25_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_25_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_25_2) - 5) & 255;
    if (stage_v_25_2 > 53)
    {
      chk_sum_2 ^= stage_v_25_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_28_1 = (st_var_0_1.buffer[0] ^ 31) & 3;
  int stage_v_28_2 = (st_var_0_2.buffer[0] ^ 31) & 3;
  switch (stage_v_28_1)
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

  switch (stage_v_28_2)
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

  int stage_v_29_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_29_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_29_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_29_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_30_1 = (st_var_2_1.buffer[0] ^ 33) & 3;
  int stage_v_30_2 = (st_var_2_2.buffer[0] ^ 33) & 3;
  switch (stage_v_30_1)
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

  switch (stage_v_30_2)
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

  int stage_v_31_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (36 & 31);
  int stage_v_31_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (36 & 31);
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= (stage_v_31_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_31_2 << 1) & 127;
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
  int stage_v_34_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (39 & 31);
  int stage_v_34_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (39 & 31);
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= (stage_v_34_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_34_2 << 1) & 127;
  int stage_v_35_1 = table_1[3];
  int stage_v_35_2 = table_2[3];
  table_1[3] = (table_1[0] + 71) & 63;
  table_2[3] = (table_2[0] + 71) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (st_var_0_1.buffer[0] ^ 39) & 3;
  int stage_v_36_2 = (st_var_0_2.buffer[0] ^ 39) & 3;
  switch (stage_v_36_1)
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

  switch (stage_v_36_2)
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

  int stage_v_37_1 = (st_var_1_1.buffer[0] ^ 40) & 3;
  int stage_v_37_2 = (st_var_1_2.buffer[0] ^ 40) & 3;
  switch (stage_v_37_1)
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

  switch (stage_v_37_2)
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

  int stage_v_38_1 = table_1[2];
  int stage_v_38_2 = table_2[2];
  table_1[2] = (table_1[3] + 77) & 63;
  table_2[2] = (table_2[3] + 77) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = table_1[3];
  int stage_v_39_2 = table_2[3];
  table_1[3] = (table_1[0] + 79) & 63;
  table_2[3] = (table_2[0] + 79) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (45 & 31);
  int stage_v_40_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (45 & 31);
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= (stage_v_40_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_40_2 << 1) & 127;
  int stage_v_41_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (46 & 31);
  int stage_v_41_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (46 & 31);
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= (stage_v_41_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_41_2 << 1) & 127;
  int stage_v_42_1 = ((st_var_2_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_2_2.buffer[0] * 2) + 133) & 63;
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

  switch (stage_v_44_2)
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

  int stage_v_45_1 = ((st_var_1_1.buffer[0] * 2) + 142) & 63;
  int stage_v_45_2 = ((st_var_1_2.buffer[0] * 2) + 142) & 63;
  if (stage_v_45_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_45_1) - 5) & 255;
    if (stage_v_45_1 > 32)
    {
      chk_sum_1 ^= stage_v_45_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_45_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_45_2) - 5) & 255;
    if (stage_v_45_2 > 32)
    {
      chk_sum_2 ^= stage_v_45_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_46_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_46_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_47_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (52 & 31);
  int stage_v_47_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (52 & 31);
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= (stage_v_47_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_47_2 << 1) & 127;
  int stage_v_48_1 = (st_var_0_1.buffer[0] ^ 51) & 3;
  int stage_v_48_2 = (st_var_0_2.buffer[0] ^ 51) & 3;
  switch (stage_v_48_1)
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

  switch (stage_v_48_2)
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

  int stage_v_49_1 = (st_var_1_1.buffer[0] ^ 52) & 3;
  int stage_v_49_2 = (st_var_1_2.buffer[0] ^ 52) & 3;
  switch (stage_v_49_1)
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

  switch (stage_v_49_2)
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

  int stage_v_50_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (55 & 31);
  int stage_v_50_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (55 & 31);
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= (stage_v_50_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_50_2 << 1) & 127;
  int stage_v_51_1 = table_1[3];
  int stage_v_51_2 = table_2[3];
  table_1[3] = (table_1[0] + 103) & 63;
  table_2[3] = (table_2[0] + 103) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (57 & 31);
  int stage_v_52_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (57 & 31);
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= (stage_v_52_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_52_2 << 1) & 127;
  int stage_v_53_1 = ((st_var_1_1.buffer[2] * 2) + 166) & 63;
  int stage_v_53_2 = ((st_var_1_2.buffer[2] * 2) + 166) & 63;
  if (stage_v_53_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_53_1) - 5) & 255;
    if (stage_v_53_1 > 29)
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
  if (stage_v_53_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_53_2) - 5) & 255;
    if (stage_v_53_2 > 29)
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
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 56) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 56) & 15;
  int stage_v_55_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_55_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= stage_v_55_1;
  chk_sum_2 ^= stage_v_55_2;
  int stage_v_56_1 = (st_var_0_1.buffer[0] ^ 59) & 3;
  int stage_v_56_2 = (st_var_0_2.buffer[0] ^ 59) & 3;
  switch (stage_v_56_1)
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

  switch (stage_v_56_2)
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

  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_57_1 = ((stage_v_57_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 59) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 59) & 15;
  int stage_v_58_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_58_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= stage_v_58_1;
  chk_sum_2 ^= stage_v_58_2;
  int stage_v_59_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (64 & 31);
  int stage_v_59_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (64 & 31);
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= (stage_v_59_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_59_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 61) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 61) & 15;
  int stage_v_60_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_60_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= stage_v_60_1;
  chk_sum_2 ^= stage_v_60_2;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
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
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_63_1 = ((stage_v_63_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_63_2 = ((stage_v_63_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (st_var_0_1.buffer[0] ^ 67) & 3;
  int stage_v_64_2 = (st_var_0_2.buffer[0] ^ 67) & 3;
  switch (stage_v_64_1)
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

  switch (stage_v_64_2)
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

  int stage_v_65_1 = table_1[1];
  int stage_v_65_2 = table_2[1];
  table_1[1] = (table_1[2] + 131) & 63;
  table_2[1] = (table_2[2] + 131) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 67) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 67) & 15;
  int stage_v_66_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_66_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= stage_v_66_1;
  chk_sum_2 ^= stage_v_66_2;
  int stage_v_67_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (72 & 31);
  int stage_v_67_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (72 & 31);
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= (stage_v_67_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_67_2 << 1) & 127;
  int stage_v_68_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_68_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_68_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_68_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_71_1 = ((st_var_3_1.buffer[2] * 2) + 220) & 63;
  int stage_v_71_2 = ((st_var_3_2.buffer[2] * 2) + 220) & 63;
  if (stage_v_71_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_71_1) - 5) & 255;
    if (stage_v_71_1 > 32)
    {
      chk_sum_1 ^= stage_v_71_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_71_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_71_2) - 5) & 255;
    if (stage_v_71_2 > 32)
    {
      chk_sum_2 ^= stage_v_71_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 73) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 73) & 15;
  int stage_v_72_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_72_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  chk_sum_1 ^= stage_v_72_1;
  chk_sum_2 ^= stage_v_72_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 74) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 74) & 15;
  int stage_v_73_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_73_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= stage_v_73_1;
  chk_sum_2 ^= stage_v_73_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 75) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 75) & 15;
  int stage_v_74_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_74_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  chk_sum_1 ^= stage_v_74_1;
  chk_sum_2 ^= stage_v_74_2;
  int stage_v_75_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_75_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_76_1 = (st_var_0_1.buffer[0] ^ 79) & 3;
  int stage_v_76_2 = (st_var_0_2.buffer[0] ^ 79) & 3;
  switch (stage_v_76_1)
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

  switch (stage_v_76_2)
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
  int stage_v_78_1 = ((st_var_2_1.buffer[0] * 2) + 241) & 63;
  int stage_v_78_2 = ((st_var_2_2.buffer[0] * 2) + 241) & 63;
  if (stage_v_78_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_78_1) - 5) & 255;
    if (stage_v_78_1 > 46)
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
  if (stage_v_78_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_78_2) - 5) & 255;
    if (stage_v_78_2 > 46)
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
  int stage_v_79_1 = (st_var_3_1.buffer[0] ^ 82) & 3;
  int stage_v_79_2 = (st_var_3_2.buffer[0] ^ 82) & 3;
  switch (stage_v_79_1)
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

  switch (stage_v_79_2)
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

  int stage_v_80_1 = table_1[0];
  int stage_v_80_2 = table_2[0];
  table_1[0] = (table_1[1] + 161) & 63;
  table_2[0] = (table_2[1] + 161) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = table_1[1];
  int stage_v_81_2 = table_2[1];
  table_1[1] = (table_1[2] + 163) & 63;
  table_2[1] = (table_2[2] + 163) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((st_var_2_1.buffer[1] * 2) + 253) & 63;
  int stage_v_82_2 = ((st_var_2_2.buffer[1] * 2) + 253) & 63;
  if (stage_v_82_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_82_1) - 5) & 255;
    if (stage_v_82_1 > 28)
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
  if (stage_v_82_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_82_2) - 5) & 255;
    if (stage_v_82_2 > 28)
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
  int stage_v_83_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (88 & 31);
  int stage_v_83_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (88 & 31);
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= (stage_v_83_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_83_2 << 1) & 127;
  int stage_v_84_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (89 & 31);
  int stage_v_84_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (89 & 31);
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  chk_sum_1 ^= (stage_v_84_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_84_2 << 1) & 127;
  int stage_v_85_1 = ((st_var_1_1.buffer[1] * 2) + 262) & 63;
  int stage_v_85_2 = ((st_var_1_2.buffer[1] * 2) + 262) & 63;
  if (stage_v_85_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_85_1) - 5) & 255;
    if (stage_v_85_1 > 50)
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
  if (stage_v_85_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_85_2) - 5) & 255;
    if (stage_v_85_2 > 50)
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
  int stage_v_86_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_86_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_86_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_86_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_87_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_87_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_87_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_87_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_88_1 = ((stage_v_88_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_88_2 = ((stage_v_88_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_89_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_89_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_89_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 91) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 91) & 15;
  int stage_v_90_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_90_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  chk_sum_1 ^= stage_v_90_1;
  chk_sum_2 ^= stage_v_90_2;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_91_1 = ((stage_v_91_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_91_2 = ((stage_v_91_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = table_1[0];
  int stage_v_92_2 = table_2[0];
  table_1[0] = (table_1[1] + 185) & 63;
  table_2[0] = (table_2[1] + 185) & 63;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (st_var_1_1.buffer[0] ^ 96) & 3;
  int stage_v_93_2 = (st_var_1_2.buffer[0] ^ 96) & 3;
  switch (stage_v_93_1)
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

  switch (stage_v_93_2)
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

  int stage_v_94_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_94_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_94_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_94_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_95_1 = table_1[3];
  int stage_v_95_2 = table_2[3];
  table_1[3] = (table_1[0] + 191) & 63;
  table_2[3] = (table_2[0] + 191) & 63;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 97) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 97) & 15;
  int stage_v_96_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_96_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  chk_sum_1 ^= stage_v_96_1;
  chk_sum_2 ^= stage_v_96_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 98) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 98) & 15;
  int stage_v_97_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_97_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  chk_sum_1 ^= stage_v_97_1;
  chk_sum_2 ^= stage_v_97_2;
  int stage_v_98_1 = table_1[2];
  int stage_v_98_2 = table_2[2];
  table_1[2] = (table_1[3] + 197) & 63;
  table_2[2] = (table_2[3] + 197) & 63;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (st_var_3_1.buffer[0] ^ 102) & 3;
  int stage_v_99_2 = (st_var_3_2.buffer[0] ^ 102) & 3;
  switch (stage_v_99_1)
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

  switch (stage_v_99_2)
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

  int stage_v_100_1 = (st_var_0_1.buffer[0] ^ 103) & 3;
  int stage_v_100_2 = (st_var_0_2.buffer[0] ^ 103) & 3;
  switch (stage_v_100_1)
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

  switch (stage_v_100_2)
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

  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 102) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 102) & 15;
  int stage_v_101_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_101_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  chk_sum_1 ^= stage_v_101_1;
  chk_sum_2 ^= stage_v_101_2;
  int stage_v_102_1 = table_1[2];
  int stage_v_102_2 = table_2[2];
  table_1[2] = (table_1[3] + 205) & 63;
  table_2[2] = (table_2[3] + 205) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (st_var_3_1.buffer[0] ^ 106) & 3;
  int stage_v_103_2 = (st_var_3_2.buffer[0] ^ 106) & 3;
  switch (stage_v_103_1)
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

  switch (stage_v_103_2)
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

  int stage_v_104_1 = ((st_var_0_1.buffer[2] * 2) + 319) & 63;
  int stage_v_104_2 = ((st_var_0_2.buffer[2] * 2) + 319) & 63;
  if (stage_v_104_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_104_1) - 5) & 255;
    if (stage_v_104_1 > 54)
    {
      chk_sum_1 ^= stage_v_104_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_104_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_104_2) - 5) & 255;
    if (stage_v_104_2 > 54)
    {
      chk_sum_2 ^= stage_v_104_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_105_1 = (st_var_1_1.buffer[0] ^ 108) & 3;
  int stage_v_105_2 = (st_var_1_2.buffer[0] ^ 108) & 3;
  switch (stage_v_105_1)
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

  switch (stage_v_105_2)
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

  int stage_v_106_1 = (st_var_2_1.buffer[0] ^ 109) & 3;
  int stage_v_106_2 = (st_var_2_2.buffer[0] ^ 109) & 3;
  switch (stage_v_106_1)
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

  switch (stage_v_106_2)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 109) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 109) & 15;
  int stage_v_108_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_108_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  chk_sum_1 ^= stage_v_108_1;
  chk_sum_2 ^= stage_v_108_2;
  int stage_v_109_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (114 & 31);
  int stage_v_109_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (114 & 31);
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  chk_sum_1 ^= (stage_v_109_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_109_2 << 1) & 127;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_110_1 = ((stage_v_110_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_110_2 = ((stage_v_110_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 112) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 112) & 15;
  int stage_v_111_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_111_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  chk_sum_1 ^= stage_v_111_1;
  chk_sum_2 ^= stage_v_111_2;
  int stage_v_112_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_112_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_112_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_112_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_113_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (118 & 31);
  int stage_v_113_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (118 & 31);
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  chk_sum_1 ^= (stage_v_113_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_113_2 << 1) & 127;
  int stage_v_114_1 = ((st_var_2_1.buffer[0] * 2) + 349) & 63;
  int stage_v_114_2 = ((st_var_2_2.buffer[0] * 2) + 349) & 63;
  if (stage_v_114_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_114_1) - 5) & 255;
    if (stage_v_114_1 > 49)
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
  if (stage_v_114_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_114_2) - 5) & 255;
    if (stage_v_114_2 > 49)
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
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_115_1 = ((stage_v_115_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_115_2 = ((stage_v_115_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = table_1[0];
  int stage_v_116_2 = table_2[0];
  table_1[0] = (table_1[1] + 233) & 63;
  table_2[0] = (table_2[1] + 233) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = (st_var_1_1.buffer[0] ^ 120) & 3;
  int stage_v_117_2 = (st_var_1_2.buffer[0] ^ 120) & 3;
  switch (stage_v_117_1)
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

  switch (stage_v_117_2)
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

  int stage_v_118_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_118_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_118_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_118_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 120) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 120) & 15;
  int stage_v_119_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_119_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  chk_sum_1 ^= stage_v_119_1;
  chk_sum_2 ^= stage_v_119_2;
  int stage_v_120_1 = ((st_var_0_1.buffer[0] * 2) + 367) & 63;
  int stage_v_120_2 = ((st_var_0_2.buffer[0] * 2) + 367) & 63;
  if (stage_v_120_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_120_1) - 5) & 255;
    if (stage_v_120_1 > 29)
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
  if (stage_v_120_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_120_2) - 5) & 255;
    if (stage_v_120_2 > 29)
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
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_121_1 = ((stage_v_121_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_121_2 = ((stage_v_121_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 123) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 123) & 15;
  int stage_v_122_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_122_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  chk_sum_1 ^= stage_v_122_1;
  chk_sum_2 ^= stage_v_122_2;
  int stage_v_123_1 = ((st_var_3_1.buffer[0] * 2) + 376) & 63;
  int stage_v_123_2 = ((st_var_3_2.buffer[0] * 2) + 376) & 63;
  if (stage_v_123_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_123_1) - 5) & 255;
    if (stage_v_123_1 > 31)
    {
      chk_sum_1 ^= stage_v_123_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_123_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_123_2) - 5) & 255;
    if (stage_v_123_2 > 31)
    {
      chk_sum_2 ^= stage_v_123_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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

  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 126) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 126) & 15;
  int stage_v_125_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_125_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  chk_sum_1 ^= stage_v_125_1;
  chk_sum_2 ^= stage_v_125_2;
  int stage_v_126_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_126_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_126_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_126_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_127_1 = (st_var_3_1.buffer[0] ^ 130) & 3;
  int stage_v_127_2 = (st_var_3_2.buffer[0] ^ 130) & 3;
  switch (stage_v_127_1)
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

  switch (stage_v_127_2)
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

  int stage_v_128_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (133 & 31);
  int stage_v_128_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (133 & 31);
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  chk_sum_1 ^= (stage_v_128_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_128_2 << 1) & 127;
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
  int stage_v_130_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (135 & 31);
  int stage_v_130_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (135 & 31);
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  chk_sum_1 ^= (stage_v_130_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_130_2 << 1) & 127;
  int stage_v_131_1 = table_1[3];
  int stage_v_131_2 = table_2[3];
  table_1[3] = (table_1[0] + 263) & 63;
  table_2[3] = (table_2[0] + 263) & 63;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (137 & 31);
  int stage_v_132_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (137 & 31);
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  chk_sum_1 ^= (stage_v_132_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_132_2 << 1) & 127;
  int stage_v_133_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (138 & 31);
  int stage_v_133_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (138 & 31);
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  chk_sum_1 ^= (stage_v_133_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_133_2 << 1) & 127;
  int stage_v_134_1 = ((st_var_2_1.buffer[2] * 2) + 409) & 63;
  int stage_v_134_2 = ((st_var_2_2.buffer[2] * 2) + 409) & 63;
  if (stage_v_134_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_134_1) - 5) & 255;
    if (stage_v_134_1 > 48)
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
  if (stage_v_134_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_134_2) - 5) & 255;
    if (stage_v_134_2 > 48)
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
  int stage_v_135_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_135_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_135_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_135_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_136_1 = (st_var_0_1.buffer[0] ^ 139) & 3;
  int stage_v_136_2 = (st_var_0_2.buffer[0] ^ 139) & 3;
  switch (stage_v_136_1)
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

  switch (stage_v_136_2)
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

  int stage_v_137_1 = table_1[1];
  int stage_v_137_2 = table_2[1];
  table_1[1] = (table_1[2] + 275) & 63;
  table_2[1] = (table_2[2] + 275) & 63;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_138_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_138_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_138_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_139_1 = table_1[3];
  int stage_v_139_2 = table_2[3];
  table_1[3] = (table_1[0] + 279) & 63;
  table_2[3] = (table_2[0] + 279) & 63;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_140_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_140_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_140_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_141_1 = ((stage_v_141_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_141_2 = ((stage_v_141_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_142_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_142_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_142_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_143_1 = ((stage_v_143_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_143_2 = ((stage_v_143_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_144_1 = ((stage_v_144_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_144_2 = ((stage_v_144_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((st_var_1_1.buffer[1] * 2) + 442) & 63;
  int stage_v_145_2 = ((st_var_1_2.buffer[1] * 2) + 442) & 63;
  if (stage_v_145_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_145_1) - 5) & 255;
    if (stage_v_145_1 > 51)
    {
      chk_sum_1 ^= stage_v_145_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_145_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_145_2) - 5) & 255;
    if (stage_v_145_2 > 51)
    {
      chk_sum_2 ^= stage_v_145_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_146_1 = ((stage_v_146_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_146_2 = ((stage_v_146_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
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
  int stage_v_148_1 = ((st_var_0_1.buffer[1] * 2) + 451) & 63;
  int stage_v_148_2 = ((st_var_0_2.buffer[1] * 2) + 451) & 63;
  if (stage_v_148_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_148_1) - 5) & 255;
    if (stage_v_148_1 > 32)
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
  if (stage_v_148_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_148_2) - 5) & 255;
    if (stage_v_148_2 > 32)
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
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 150) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 150) & 15;
  int stage_v_149_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_149_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  chk_sum_1 ^= stage_v_149_1;
  chk_sum_2 ^= stage_v_149_2;
  int stage_v_150_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (155 & 31);
  int stage_v_150_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (155 & 31);
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  chk_sum_1 ^= (stage_v_150_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_150_2 << 1) & 127;
  int stage_v_151_1 = ((st_var_3_1.buffer[1] * 2) + 460) & 63;
  int stage_v_151_2 = ((st_var_3_2.buffer[1] * 2) + 460) & 63;
  if (stage_v_151_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_151_1) - 5) & 255;
    if (stage_v_151_1 > 40)
    {
      chk_sum_1 ^= stage_v_151_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_151_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_151_2) - 5) & 255;
    if (stage_v_151_2 > 40)
    {
      chk_sum_2 ^= stage_v_151_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_152_1 = ((st_var_0_1.buffer[2] * 2) + 463) & 63;
  int stage_v_152_2 = ((st_var_0_2.buffer[2] * 2) + 463) & 63;
  if (stage_v_152_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_152_1) - 5) & 255;
    if (stage_v_152_1 > 48)
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
  if (stage_v_152_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_152_2) - 5) & 255;
    if (stage_v_152_2 > 48)
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
  int stage_v_154_1 = table_1[2];
  int stage_v_154_2 = table_2[2];
  table_1[2] = (table_1[3] + 309) & 63;
  table_2[2] = (table_2[3] + 309) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((st_var_3_1.buffer[2] * 2) + 472) & 63;
  int stage_v_155_2 = ((st_var_3_2.buffer[2] * 2) + 472) & 63;
  if (stage_v_155_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_155_1) - 5) & 255;
    if (stage_v_155_1 > 26)
    {
      chk_sum_1 ^= stage_v_155_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_155_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_155_2) - 5) & 255;
    if (stage_v_155_2 > 26)
    {
      chk_sum_2 ^= stage_v_155_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_156_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (161 & 31);
  int stage_v_156_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (161 & 31);
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  chk_sum_1 ^= (stage_v_156_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_156_2 << 1) & 127;
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
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 160) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 160) & 15;
  int stage_v_159_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_159_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  chk_sum_1 ^= stage_v_159_1;
  chk_sum_2 ^= stage_v_159_2;
  int stage_v_160_1 = ((st_var_0_1.buffer[1] * 2) + 487) & 63;
  int stage_v_160_2 = ((st_var_0_2.buffer[1] * 2) + 487) & 63;
  if (stage_v_160_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_160_1) - 5) & 255;
    if (stage_v_160_1 > 29)
    {
      chk_sum_1 ^= stage_v_160_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_160_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_160_2) - 5) & 255;
    if (stage_v_160_2 > 29)
    {
      chk_sum_2 ^= stage_v_160_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int b_w0_1 = (sec_r000477_0_1 ^ 0x5A) & 63;
  int b_w0_2 = (sec_r000477_0_2 ^ 0x5A) & 63;
  int b_w1_1 = ((b_w0_1 << 2) | (sec_r000477_5_1 >> 2)) & 63;
  int b_w1_2 = ((b_w0_2 << 2) | (sec_r000477_5_2 >> 2)) & 63;
  int b_w2_1 = ((b_w1_1 << 1) | (sec_r000477_0_1 >> 1)) & 63;
  int b_w2_2 = ((b_w1_2 << 1) | (sec_r000477_0_2 >> 1)) & 63;
  int b_w3_1 = ((b_w2_1 << 1) & (sec_r000477_5_1 >> 1)) & 63;
  int b_w3_2 = ((b_w2_2 << 1) & (sec_r000477_5_2 >> 1)) & 63;
  int b_w4_1 = ((b_w3_1 << 2) & (sec_r000477_0_1 >> 2)) & 63;
  int b_w4_2 = ((b_w3_2 << 2) & (sec_r000477_0_2 >> 2)) & 63;
  out_sink_1 += b_w4_1 & 63;
  out_sink_2 += b_w4_2 & 63;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000477_9_1 != sec_r000477_9_2);
  __CPROVER_assume(sec_r000477_16_1 != sec_r000477_16_2);
  __CPROVER_assume(sec_r000477_15_1 != sec_r000477_15_2);
  __CPROVER_assume(pub_r000477_13_1 == pub_r000477_13_2);
  __CPROVER_assume(sec_r000477_2_1 != sec_r000477_2_2);
  __CPROVER_assume(pub_r000477_6_1 == pub_r000477_6_2);
  __CPROVER_assume(sec_r000477_7_1 != sec_r000477_7_2);
  __CPROVER_assume(sec_r000477_13_1 != sec_r000477_13_2);
  __CPROVER_assume(pub_r000477_12_1 == pub_r000477_12_2);
  __CPROVER_assume(pub_r000477_4_1 == pub_r000477_4_2);
  __CPROVER_assume(pub_r000477_16_1 == pub_r000477_16_2);
  __CPROVER_assume(pub_r000477_5_1 == pub_r000477_5_2);
  __CPROVER_assume(pub_r000477_7_1 == pub_r000477_7_2);
  __CPROVER_assume(sec_r000477_6_1 != sec_r000477_6_2);
  __CPROVER_assume(sec_r000477_10_1 != sec_r000477_10_2);
  __CPROVER_assume(sec_r000477_3_1 != sec_r000477_3_2);
  __CPROVER_assume(sec_r000477_0_1 != sec_r000477_0_2);
  __CPROVER_assume(sec_r000477_12_1 != sec_r000477_12_2);
  __CPROVER_assume(pub_r000477_10_1 == pub_r000477_10_2);
  __CPROVER_assume(pub_r000477_14_1 == pub_r000477_14_2);
  __CPROVER_assume(sec_r000477_11_1 != sec_r000477_11_2);
  __CPROVER_assume(sec_r000477_17_1 != sec_r000477_17_2);
  __CPROVER_assume(pub_r000477_1_1 == pub_r000477_1_2);
  __CPROVER_assume(sec_r000477_5_1 != sec_r000477_5_2);
  __CPROVER_assume(pub_r000477_8_1 == pub_r000477_8_2);
  __CPROVER_assume(pub_r000477_11_1 == pub_r000477_11_2);
  __CPROVER_assume(sec_r000477_18_1 != sec_r000477_18_2);
  __CPROVER_assume(pub_r000477_0_1 == pub_r000477_0_2);
  __CPROVER_assume(pub_r000477_15_1 == pub_r000477_15_2);
  __CPROVER_assume(pub_r000477_17_1 == pub_r000477_17_2);
  __CPROVER_assume(sec_r000477_4_1 != sec_r000477_4_2);
  __CPROVER_assume(sec_r000477_1_1 != sec_r000477_1_2);
  __CPROVER_assume(pub_r000477_3_1 == pub_r000477_3_2);
  __CPROVER_assume(pub_r000477_9_1 == pub_r000477_9_2);
  __CPROVER_assume(sec_r000477_8_1 != sec_r000477_8_2);
  __CPROVER_assume(pub_r000477_19_1 == pub_r000477_19_2);
  __CPROVER_assume(pub_r000477_2_1 == pub_r000477_2_2);
  __CPROVER_assume(sec_r000477_14_1 != sec_r000477_14_2);
  __CPROVER_assume(pub_r000477_18_1 == pub_r000477_18_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.id == st_var_0_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.code == st_var_1_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.iv == st_var_2_2.iv);
  assert(st_var_2_1.counter == st_var_2_2.counter);
  assert(st_var_2_1.round_key == st_var_2_2.round_key);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.coord_x == st_var_3_2.coord_x);
  assert(st_var_3_1.heading == st_var_3_2.heading);
  assert(st_var_3_1.pitch == st_var_3_2.pitch);
  assert(st_var_3_1.coord_y == st_var_3_2.coord_y);
  assert(st_var_3_1.coord_z == st_var_3_2.coord_z);
  assert(st_var_3_1.norm_sq == st_var_3_2.norm_sq);
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
  assert(b_w0_1 == b_w0_2);
  assert(b_w1_1 == b_w1_2);
  assert(b_w2_1 == b_w2_2);
  assert(b_w3_1 == b_w3_2);
  assert(b_w4_1 == b_w4_2);
}


