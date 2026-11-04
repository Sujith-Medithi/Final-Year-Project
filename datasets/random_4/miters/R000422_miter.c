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
struct CipherContext_R000422_2213_0
{
  int flags;
  short round_key;
  int iv;
  short nonce;
  unsigned char counter;
  int tag;
  int buffer[3];
};
struct Vector3D_R000422_2213_1
{
  int coord_y;
  int coord_z;
  unsigned char pitch;
  int norm_sq;
  int buffer[3];
};
struct AudioFrame_R000422_2213_2
{
  short sample_rate;
  int rms;
  int channels;
  short envelope;
  int gain;
  int peak;
  int buffer[3];
};
union ColorPixel_R000422_2213_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000422_2213_1
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
void fn_R000422_2213_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000422_2213_0 st_1 = {0};
  struct CipherContext_R000422_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_98_1)
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

  switch (factor_98_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_16_1 = local_arr_1[aux_1 % 3];
  int metric_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_16_2 * 2)) & 127;
  int coefficient_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_38_1) & 63;
  aux_2 = (aux_2 + coefficient_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_98_1 == factor_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_16_1 == metric_16_2);
  assert(coefficient_38_1 == coefficient_38_2);
}

int fn_R000422_2213_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000422_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_98 = (aux + st.buffer[1]) & 3;
  switch (factor_98)
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

  int local_arr[3] = {4, 9, 15};
  int metric_16 = local_arr[aux % 3];
  acc = (acc + (metric_16 * 2)) & 127;
  int coefficient_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_38) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000422_2213_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000422_2213_1 st_1 = {0};
  struct Vector3D_R000422_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int window_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_26_1) & 63;
  aux_2 = (aux_2 + window_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_62_1 = 0;
  int metric_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_62_1 = ((metric_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_62_2 = ((metric_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_62_1) & 127;
    acc_2 = (acc_2 + metric_62_2) & 127;
  }

  int window_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_64_1)
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

  switch (window_64_2)
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
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_26_1 == window_26_2);
  assert(metric_62_1 == metric_62_2);
  assert(window_64_1 == window_64_2);
}

int fn_R000422_2213_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000422_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int window_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_26) & 63;
  acc ^= aux;
  int metric_62 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_62 = ((metric_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_62) & 127;
  }

  int window_64 = (aux + st.buffer[1]) & 3;
  switch (window_64)
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

void fn_R000422_2213_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000422_2213_0 st_1 = {0};
  struct CipherContext_R000422_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int index_reg_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_91_1)
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

  switch (index_reg_91_2)
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

  int weight_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_78_1) & 63;
  aux_2 = (aux_2 + weight_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_96_1 = local_arr_1[aux_1 % 3];
  int pivot_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_96_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_91_1 == index_reg_91_2);
  assert(weight_78_1 == weight_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_96_1 == pivot_96_2);
}

int fn_R000422_2213_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000422_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int index_reg_91 = (aux + st.buffer[1]) & 3;
  switch (index_reg_91)
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

  int weight_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_78) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_96 = local_arr[aux % 3];
  acc = (acc + (pivot_96 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000422_2213_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000422_2213_1 st_1 = {0};
  struct Vector3D_R000422_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int cursor_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_38_1) & 63;
  aux_2 = (aux_2 + cursor_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_57_1 = local_arr_1[aux_1 % 3];
  int phase_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_57_2 * 2)) & 127;
  int threshold_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_92_1 > 30)
  {
    acc_1 = ((acc_1 + (threshold_92_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_92_2 > 30)
  {
    acc_2 = ((acc_2 + (threshold_92_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_92_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_38_1 == cursor_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_57_1 == phase_57_2);
  assert(threshold_92_1 == threshold_92_2);
}

int fn_R000422_2213_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000422_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int cursor_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_38) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int phase_57 = local_arr[aux % 3];
  acc = (acc + (phase_57 * 2)) & 127;
  int threshold_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_92 > 30)
  {
    acc = ((acc + (threshold_92 * 2)) + 5) & 127;
    aux ^= threshold_92 & 15;
  }
  else
  {
    acc = ((acc - threshold_92) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000422_2213_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000422_2213_2 st_1 = {0};
  struct AudioFrame_R000422_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int cursor_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_90_1)
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

  switch (cursor_90_2)
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

  int quantum_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_74_1) & 63;
  aux_2 = (aux_2 + quantum_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_90_1 == cursor_90_2);
  assert(quantum_74_1 == quantum_74_2);
}

int fn_R000422_2213_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000422_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int cursor_90 = (aux + st.buffer[1]) & 3;
  switch (cursor_90)
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

  int quantum_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_74) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000422_2213_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000422_2213_0 st_1 = {0};
  struct CipherContext_R000422_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int accumulator_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_94_1)
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

  switch (accumulator_94_2)
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

  int residue_38_1 = 0;
  int residue_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_38_1 = ((residue_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_38_2 = ((residue_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_38_1) & 127;
    acc_2 = (acc_2 + residue_38_2) & 127;
  }

  int stride_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_39_1) & 63;
  aux_2 = (aux_2 + stride_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_94_1 == accumulator_94_2);
  assert(residue_38_1 == residue_38_2);
  assert(stride_39_1 == stride_39_2);
}

int fn_R000422_2213_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000422_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int accumulator_94 = (aux + st.buffer[1]) & 3;
  switch (accumulator_94)
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

  int residue_38 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_38 = ((residue_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_38) & 127;
  }

  int stride_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_39) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000422_2213_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000422_2213_1 st_1 = {0};
  struct Vector3D_R000422_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int tally_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_92_1)
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

  switch (tally_92_2)
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
  int residue_95_1 = local_arr_1[aux_1 % 3];
  int residue_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_95_2 * 2)) & 127;
  int tally_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_70_1 > 42)
  {
    acc_1 = ((acc_1 + (tally_70_1 * 2)) + 5) & 127;
    aux_1 ^= tally_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_70_2 > 42)
  {
    acc_2 = ((acc_2 + (tally_70_2 * 2)) + 5) & 127;
    aux_2 ^= tally_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_70_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_92_1 == tally_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_95_1 == residue_95_2);
  assert(tally_70_1 == tally_70_2);
}

int fn_R000422_2213_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000422_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int tally_92 = (aux + st.buffer[1]) & 3;
  switch (tally_92)
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
  int residue_95 = local_arr[aux % 3];
  acc = (acc + (residue_95 * 2)) & 127;
  int tally_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_70 > 42)
  {
    acc = ((acc + (tally_70 * 2)) + 5) & 127;
    aux ^= tally_70 & 15;
  }
  else
  {
    acc = ((acc - tally_70) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000422_2213_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000422_2213_1 st_1 = {0};
  struct Vector3D_R000422_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int parity_16_1 = 0;
  int parity_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_16_1 = ((parity_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_16_2 = ((parity_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_16_1) & 127;
    acc_2 = (acc_2 + parity_16_2) & 127;
  }

  int coefficient_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_97_1)
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

  switch (coefficient_97_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_91_1 = local_arr_1[aux_1 % 3];
  int metric_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_91_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_16_1 == parity_16_2);
  assert(coefficient_97_1 == coefficient_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_91_1 == metric_91_2);
}

int fn_R000422_2213_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000422_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int parity_16 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_16 = ((parity_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_16) & 127;
  }

  int coefficient_97 = (aux + st.buffer[1]) & 3;
  switch (coefficient_97)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_91 = local_arr[aux % 3];
  acc = (acc + (metric_91 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000422_2213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000422_2213_0 st_1 = {0};
  struct CipherContext_R000422_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int mask_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_73_1)
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

  switch (mask_73_2)
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

  int cursor_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_27_1) & 63;
  aux_2 = (aux_2 + cursor_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_98_1 > 28)
  {
    acc_1 = ((acc_1 + (bound_98_1 * 2)) + 5) & 127;
    aux_1 ^= bound_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_98_2 > 28)
  {
    acc_2 = ((acc_2 + (bound_98_2 * 2)) + 5) & 127;
    aux_2 ^= bound_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_50_1 = 0;
  int weight_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_50_1 = ((weight_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_50_2 = ((weight_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_50_1) & 127;
    acc_2 = (acc_2 + weight_50_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_73_1 == mask_73_2);
  assert(cursor_27_1 == cursor_27_2);
  assert(bound_98_1 == bound_98_2);
  assert(weight_50_1 == weight_50_2);
}

int fn_R000422_2213_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000422_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int mask_73 = (aux + st.buffer[1]) & 3;
  switch (mask_73)
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

  int cursor_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_27) & 63;
  acc ^= aux;
  int bound_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_98 > 28)
  {
    acc = ((acc + (bound_98 * 2)) + 5) & 127;
    aux ^= bound_98 & 15;
  }
  else
  {
    acc = ((acc - bound_98) + 11) & 127;
    aux += 3;
  }
  int weight_50 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_50 = ((weight_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_50) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000422_2213_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000422_2213_0 st_1 = {0};
  struct CipherContext_R000422_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int sample_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_34_1 > 27)
  {
    acc_1 = ((acc_1 + (sample_34_1 * 2)) + 5) & 127;
    aux_1 ^= sample_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_34_2 > 27)
  {
    acc_2 = ((acc_2 + (sample_34_2 * 2)) + 5) & 127;
    aux_2 ^= sample_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_61_1 = local_arr_1[aux_1 % 3];
  int mask_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_61_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_34_1 == sample_34_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_61_1 == mask_61_2);
}

int fn_R000422_2213_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000422_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int sample_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_34 > 27)
  {
    acc = ((acc + (sample_34 * 2)) + 5) & 127;
    aux ^= sample_34 & 15;
  }
  else
  {
    acc = ((acc - sample_34) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_61 = local_arr[aux % 3];
  acc = (acc + (mask_61 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000422_2213_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000422_2213_1 st_1 = {0};
  struct Vector3D_R000422_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int mask_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_48_1) & 63;
  aux_2 = (aux_2 + mask_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_43_1 = local_arr_1[aux_1 % 3];
  int index_reg_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_43_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_54_1)
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

  switch (quantum_54_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_48_1 == mask_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_43_1 == index_reg_43_2);
  assert(quantum_54_1 == quantum_54_2);
}

int fn_R000422_2213_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000422_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int mask_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_48) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_43 = local_arr[aux % 3];
  acc = (acc + (index_reg_43 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_54 = (aux + st.buffer[1]) & 3;
  switch (quantum_54)
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

  return (acc + aux) & 255;
}

void fn_R000422_2213_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000422_2213_0 st_1 = {0};
  struct CipherContext_R000422_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_18_1 = local_arr_1[aux_1 % 3];
  int quotient_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_18_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_96_1 > 28)
  {
    acc_1 = ((acc_1 + (anchor_96_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_96_2 > 28)
  {
    acc_2 = ((acc_2 + (anchor_96_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_96_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_18_1 == quotient_18_2);
  assert(anchor_96_1 == anchor_96_2);
}

int fn_R000422_2213_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000422_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int quotient_18 = local_arr[aux % 3];
  acc = (acc + (quotient_18 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_96 > 28)
  {
    acc = ((acc + (anchor_96 * 2)) + 5) & 127;
    aux ^= anchor_96 & 15;
  }
  else
  {
    acc = ((acc - anchor_96) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000422_2213_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000422_2213_1 st_1 = {0};
  struct Vector3D_R000422_2213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int segment_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_99_1)
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

  switch (segment_99_2)
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

  int vector_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_55_1 > 24)
  {
    acc_1 = ((acc_1 + (vector_55_1 * 2)) + 5) & 127;
    aux_1 ^= vector_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_55_2 > 24)
  {
    acc_2 = ((acc_2 + (vector_55_2 * 2)) + 5) & 127;
    aux_2 ^= vector_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_55_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_99_1 == segment_99_2);
  assert(vector_55_1 == vector_55_2);
}

int fn_R000422_2213_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000422_2213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int segment_99 = (aux + st.buffer[1]) & 3;
  switch (segment_99)
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

  int vector_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_55 > 24)
  {
    acc = ((acc + (vector_55 * 2)) + 5) & 127;
    aux ^= vector_55 & 15;
  }
  else
  {
    acc = ((acc - vector_55) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000422_2213_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000422_2213_2 st_1 = {0};
  struct AudioFrame_R000422_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int checksum_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_57_1)
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

  switch (checksum_57_2)
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

  int phase_53_1 = 0;
  int phase_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_53_1 = ((phase_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_53_2 = ((phase_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_53_1) & 127;
    acc_2 = (acc_2 + phase_53_2) & 127;
  }

  int factor_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_38_1 > 46)
  {
    acc_1 = ((acc_1 + (factor_38_1 * 2)) + 5) & 127;
    aux_1 ^= factor_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_38_2 > 46)
  {
    acc_2 = ((acc_2 + (factor_38_2 * 2)) + 5) & 127;
    aux_2 ^= factor_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_38_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_57_1 == checksum_57_2);
  assert(phase_53_1 == phase_53_2);
  assert(factor_38_1 == factor_38_2);
}

int fn_R000422_2213_13(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000422_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int checksum_57 = (aux + st.buffer[1]) & 3;
  switch (checksum_57)
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

  int phase_53 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_53 = ((phase_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_53) & 127;
  }

  int factor_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_38 > 46)
  {
    acc = ((acc + (factor_38 * 2)) + 5) & 127;
    aux ^= factor_38 & 15;
  }
  else
  {
    acc = ((acc - factor_38) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000422_2213_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000422_2213_0 st_1 = {0};
  struct CipherContext_R000422_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int metric_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_35_1) & 63;
  aux_2 = (aux_2 + metric_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_74_1 > 20)
  {
    acc_1 = ((acc_1 + (bound_74_1 * 2)) + 5) & 127;
    aux_1 ^= bound_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_74_2 > 20)
  {
    acc_2 = ((acc_2 + (bound_74_2 * 2)) + 5) & 127;
    aux_2 ^= bound_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_74_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_72_1 = local_arr_1[aux_1 % 3];
  int checksum_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_72_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_35_1 == metric_35_2);
  assert(bound_74_1 == bound_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_72_1 == checksum_72_2);
}

int fn_R000422_2213_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000422_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int metric_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_35) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_74 > 20)
  {
    acc = ((acc + (bound_74 * 2)) + 5) & 127;
    aux ^= bound_74 & 15;
  }
  else
  {
    acc = ((acc - bound_74) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_72 = local_arr[aux % 3];
  acc = (acc + (checksum_72 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000422_2213_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000422_2213_0 st_1 = {0};
  struct CipherContext_R000422_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int index_reg_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_60_1)
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

  switch (index_reg_60_2)
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

  int quantum_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_35_1) & 63;
  aux_2 = (aux_2 + quantum_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_60_1 == index_reg_60_2);
  assert(quantum_35_1 == quantum_35_2);
}

int fn_R000422_2213_15(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000422_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int index_reg_60 = (aux + st.buffer[1]) & 3;
  switch (index_reg_60)
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

  int quantum_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_35) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000422_2213_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000422_2213_2 st_1 = {0};
  struct AudioFrame_R000422_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int threshold_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_63_1 > 15)
  {
    acc_1 = ((acc_1 + (threshold_63_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_63_2 > 15)
  {
    acc_2 = ((acc_2 + (threshold_63_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_92_1)
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

  switch (quotient_92_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_63_1 == threshold_63_2);
  assert(quotient_92_1 == quotient_92_2);
}

int fn_R000422_2213_16(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000422_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int threshold_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_63 > 15)
  {
    acc = ((acc + (threshold_63 * 2)) + 5) & 127;
    aux ^= threshold_63 & 15;
  }
  else
  {
    acc = ((acc - threshold_63) + 11) & 127;
    aux += 3;
  }
  int quotient_92 = (aux + st.buffer[1]) & 3;
  switch (quotient_92)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000422_2213_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000422_2213_2 st_1 = {0};
  struct AudioFrame_R000422_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int factor_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_79_1 > 15)
  {
    acc_1 = ((acc_1 + (factor_79_1 * 2)) + 5) & 127;
    aux_1 ^= factor_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_79_2 > 15)
  {
    acc_2 = ((acc_2 + (factor_79_2 * 2)) + 5) & 127;
    aux_2 ^= factor_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_25_1 = local_arr_1[aux_1 % 3];
  int bound_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_25_2 * 2)) & 127;
  int tracker_36_1 = 0;
  int tracker_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_36_1 = ((tracker_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_36_2 = ((tracker_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_36_1) & 127;
    acc_2 = (acc_2 + tracker_36_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_79_1 == factor_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_25_1 == bound_25_2);
  assert(tracker_36_1 == tracker_36_2);
}

int fn_R000422_2213_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000422_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int factor_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_79 > 15)
  {
    acc = ((acc + (factor_79 * 2)) + 5) & 127;
    aux ^= factor_79 & 15;
  }
  else
  {
    acc = ((acc - factor_79) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_25 = local_arr[aux % 3];
  acc = (acc + (bound_25 * 2)) & 127;
  int tracker_36 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_36 = ((tracker_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_36) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000422_2213_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000422_2213_0 st_1 = {0};
  struct CipherContext_R000422_2213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_25_1)
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

  switch (bound_25_2)
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

  int stride_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_50_1 > 13)
  {
    acc_1 = ((acc_1 + (stride_50_1 * 2)) + 5) & 127;
    aux_1 ^= stride_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_50_2 > 13)
  {
    acc_2 = ((acc_2 + (stride_50_2 * 2)) + 5) & 127;
    aux_2 ^= stride_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_23_1) & 63;
  aux_2 = (aux_2 + margin_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.flags == st_2.flags);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_25_1 == bound_25_2);
  assert(stride_50_1 == stride_50_2);
  assert(margin_23_1 == margin_23_2);
}

int fn_R000422_2213_18(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000422_2213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_25 = (aux + st.buffer[1]) & 3;
  switch (bound_25)
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

  int stride_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_50 > 13)
  {
    acc = ((acc + (stride_50 * 2)) + 5) & 127;
    aux ^= stride_50 & 15;
  }
  else
  {
    acc = ((acc - stride_50) + 11) & 127;
    aux += 3;
  }
  int margin_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_23) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000422_2213_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000422_2213_2 st_1 = {0};
  struct AudioFrame_R000422_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_27_1 = local_arr_1[aux_1 % 3];
  int checksum_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_27_2 * 2)) & 127;
  int delta_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_80_1) & 63;
  aux_2 = (aux_2 + delta_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_27_1 == checksum_27_2);
  assert(delta_80_1 == delta_80_2);
}

int fn_R000422_2213_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000422_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_27 = local_arr[aux % 3];
  acc = (acc + (checksum_27 * 2)) & 127;
  int delta_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_80) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000422_2213_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000422_2213_2 st_1 = {0};
  struct AudioFrame_R000422_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_76_1 > 29)
  {
    acc_1 = ((acc_1 + (parity_76_1 * 2)) + 5) & 127;
    aux_1 ^= parity_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_76_2 > 29)
  {
    acc_2 = ((acc_2 + (parity_76_2 * 2)) + 5) & 127;
    aux_2 ^= parity_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_82_1) & 63;
  aux_2 = (aux_2 + offset_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_76_1 == parity_76_2);
  assert(offset_82_1 == offset_82_2);
}

int fn_R000422_2213_20(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000422_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_76 > 29)
  {
    acc = ((acc + (parity_76 * 2)) + 5) & 127;
    aux ^= parity_76 & 15;
  }
  else
  {
    acc = ((acc - parity_76) + 11) & 127;
    aux += 3;
  }
  int offset_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_82) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000422_2213_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000422_2213_2 st_1 = {0};
  struct AudioFrame_R000422_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int stride_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_28_1 > 14)
  {
    acc_1 = ((acc_1 + (stride_28_1 * 2)) + 5) & 127;
    aux_1 ^= stride_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_28_2 > 14)
  {
    acc_2 = ((acc_2 + (stride_28_2 * 2)) + 5) & 127;
    aux_2 ^= stride_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_28_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_70_1) & 63;
  aux_2 = (aux_2 + cursor_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_28_1 == stride_28_2);
  assert(cursor_70_1 == cursor_70_2);
}

int fn_R000422_2213_21(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000422_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int stride_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_28 > 14)
  {
    acc = ((acc + (stride_28 * 2)) + 5) & 127;
    aux ^= stride_28 & 15;
  }
  else
  {
    acc = ((acc - stride_28) + 11) & 127;
    aux += 3;
  }
  int cursor_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_70) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000422_2213_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000422_2213_2 st_1 = {0};
  struct AudioFrame_R000422_2213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_66_1 = 0;
  int accumulator_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_66_1 = ((accumulator_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_66_2 = ((accumulator_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_66_1) & 127;
    acc_2 = (acc_2 + accumulator_66_2) & 127;
  }

  int phase_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_70_1) & 63;
  aux_2 = (aux_2 + phase_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_27_1 = local_arr_1[aux_1 % 3];
  int factor_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_27_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_66_1 == accumulator_66_2);
  assert(phase_70_1 == phase_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_27_1 == factor_27_2);
}

int fn_R000422_2213_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000422_2213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_66 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_66 = ((accumulator_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_66) & 127;
  }

  int phase_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_70) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_27 = local_arr[aux % 3];
  acc = (acc + (factor_27 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000422_0_1;
  int sec_r000422_0_2;
  int sec_r000422_1_1;
  int sec_r000422_1_2;
  int sec_r000422_2_1;
  int sec_r000422_2_2;
  int sec_r000422_3_1;
  int sec_r000422_3_2;
  int sec_r000422_4_1;
  int sec_r000422_4_2;
  int sec_r000422_5_1;
  int sec_r000422_5_2;
  int sec_r000422_6_1;
  int sec_r000422_6_2;
  int sec_r000422_7_1;
  int sec_r000422_7_2;
  int sec_r000422_8_1;
  int sec_r000422_8_2;
  int sec_r000422_9_1;
  int sec_r000422_9_2;
  int sec_r000422_10_1;
  int sec_r000422_10_2;
  int sec_r000422_11_1;
  int sec_r000422_11_2;
  int sec_r000422_12_1;
  int sec_r000422_12_2;
  int sec_r000422_13_1;
  int sec_r000422_13_2;
  int sec_r000422_14_1;
  int sec_r000422_14_2;
  int sec_r000422_15_1;
  int sec_r000422_15_2;
  int sec_r000422_16_1;
  int sec_r000422_16_2;
  int sec_r000422_17_1;
  int sec_r000422_17_2;
  int pub_r000422_0_1;
  int pub_r000422_0_2;
  int pub_r000422_1_1;
  int pub_r000422_1_2;
  int pub_r000422_2_1;
  int pub_r000422_2_2;
  int pub_r000422_3_1;
  int pub_r000422_3_2;
  int pub_r000422_4_1;
  int pub_r000422_4_2;
  int pub_r000422_5_1;
  int pub_r000422_5_2;
  int pub_r000422_6_1;
  int pub_r000422_6_2;
  int pub_r000422_7_1;
  int pub_r000422_7_2;
  int pub_r000422_8_1;
  int pub_r000422_8_2;
  int pub_r000422_9_1;
  int pub_r000422_9_2;
  int pub_r000422_10_1;
  int pub_r000422_10_2;
  int pub_r000422_11_1;
  int pub_r000422_11_2;
  int pub_r000422_12_1;
  int pub_r000422_12_2;
  int pub_r000422_13_1;
  int pub_r000422_13_2;
  int pub_r000422_14_1;
  int pub_r000422_14_2;
  int pub_r000422_15_1;
  int pub_r000422_15_2;
  int pub_r000422_16_1;
  int pub_r000422_16_2;
  int pub_r000422_17_1;
  int pub_r000422_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000422_0_1 >= (-100)) && (pub_r000422_0_1 <= 100));
  __CPROVER_assume((pub_r000422_0_2 >= (-100)) && (pub_r000422_0_2 <= 100));
  __CPROVER_assume((pub_r000422_1_1 >= (-100)) && (pub_r000422_1_1 <= 100));
  __CPROVER_assume((pub_r000422_1_2 >= (-100)) && (pub_r000422_1_2 <= 100));
  __CPROVER_assume((pub_r000422_2_1 >= (-100)) && (pub_r000422_2_1 <= 100));
  __CPROVER_assume((pub_r000422_2_2 >= (-100)) && (pub_r000422_2_2 <= 100));
  __CPROVER_assume((pub_r000422_3_1 >= (-100)) && (pub_r000422_3_1 <= 100));
  __CPROVER_assume((pub_r000422_3_2 >= (-100)) && (pub_r000422_3_2 <= 100));
  __CPROVER_assume((pub_r000422_4_1 >= (-100)) && (pub_r000422_4_1 <= 100));
  __CPROVER_assume((pub_r000422_4_2 >= (-100)) && (pub_r000422_4_2 <= 100));
  __CPROVER_assume((pub_r000422_5_1 >= (-100)) && (pub_r000422_5_1 <= 100));
  __CPROVER_assume((pub_r000422_5_2 >= (-100)) && (pub_r000422_5_2 <= 100));
  __CPROVER_assume((pub_r000422_6_1 >= (-100)) && (pub_r000422_6_1 <= 100));
  __CPROVER_assume((pub_r000422_6_2 >= (-100)) && (pub_r000422_6_2 <= 100));
  __CPROVER_assume((pub_r000422_7_1 >= (-100)) && (pub_r000422_7_1 <= 100));
  __CPROVER_assume((pub_r000422_7_2 >= (-100)) && (pub_r000422_7_2 <= 100));
  __CPROVER_assume((pub_r000422_8_1 >= (-100)) && (pub_r000422_8_1 <= 100));
  __CPROVER_assume((pub_r000422_8_2 >= (-100)) && (pub_r000422_8_2 <= 100));
  __CPROVER_assume((pub_r000422_9_1 >= (-100)) && (pub_r000422_9_1 <= 100));
  __CPROVER_assume((pub_r000422_9_2 >= (-100)) && (pub_r000422_9_2 <= 100));
  __CPROVER_assume((pub_r000422_10_1 >= (-100)) && (pub_r000422_10_1 <= 100));
  __CPROVER_assume((pub_r000422_10_2 >= (-100)) && (pub_r000422_10_2 <= 100));
  __CPROVER_assume((pub_r000422_11_1 >= (-100)) && (pub_r000422_11_1 <= 100));
  __CPROVER_assume((pub_r000422_11_2 >= (-100)) && (pub_r000422_11_2 <= 100));
  __CPROVER_assume((pub_r000422_12_1 >= (-100)) && (pub_r000422_12_1 <= 100));
  __CPROVER_assume((pub_r000422_12_2 >= (-100)) && (pub_r000422_12_2 <= 100));
  __CPROVER_assume((pub_r000422_13_1 >= (-100)) && (pub_r000422_13_1 <= 100));
  __CPROVER_assume((pub_r000422_13_2 >= (-100)) && (pub_r000422_13_2 <= 100));
  __CPROVER_assume((pub_r000422_14_1 >= (-100)) && (pub_r000422_14_1 <= 100));
  __CPROVER_assume((pub_r000422_14_2 >= (-100)) && (pub_r000422_14_2 <= 100));
  __CPROVER_assume((pub_r000422_15_1 >= (-100)) && (pub_r000422_15_1 <= 100));
  __CPROVER_assume((pub_r000422_15_2 >= (-100)) && (pub_r000422_15_2 <= 100));
  __CPROVER_assume((pub_r000422_16_1 >= (-100)) && (pub_r000422_16_1 <= 100));
  __CPROVER_assume((pub_r000422_16_2 >= (-100)) && (pub_r000422_16_2 <= 100));
  __CPROVER_assume((pub_r000422_17_1 >= (-100)) && (pub_r000422_17_1 <= 100));
  __CPROVER_assume((pub_r000422_17_2 >= (-100)) && (pub_r000422_17_2 <= 100));
  __CPROVER_assume((sec_r000422_0_1 >= 0) && (sec_r000422_0_1 <= 255));
  __CPROVER_assume((sec_r000422_0_2 >= 0) && (sec_r000422_0_2 <= 255));
  __CPROVER_assume((sec_r000422_1_1 >= 0) && (sec_r000422_1_1 <= 255));
  __CPROVER_assume((sec_r000422_1_2 >= 0) && (sec_r000422_1_2 <= 255));
  __CPROVER_assume((sec_r000422_2_1 >= 0) && (sec_r000422_2_1 <= 255));
  __CPROVER_assume((sec_r000422_2_2 >= 0) && (sec_r000422_2_2 <= 255));
  __CPROVER_assume((sec_r000422_3_1 >= 0) && (sec_r000422_3_1 <= 255));
  __CPROVER_assume((sec_r000422_3_2 >= 0) && (sec_r000422_3_2 <= 255));
  __CPROVER_assume((sec_r000422_4_1 >= 0) && (sec_r000422_4_1 <= 255));
  __CPROVER_assume((sec_r000422_4_2 >= 0) && (sec_r000422_4_2 <= 255));
  __CPROVER_assume((sec_r000422_5_1 >= 0) && (sec_r000422_5_1 <= 255));
  __CPROVER_assume((sec_r000422_5_2 >= 0) && (sec_r000422_5_2 <= 255));
  __CPROVER_assume((sec_r000422_6_1 >= 0) && (sec_r000422_6_1 <= 255));
  __CPROVER_assume((sec_r000422_6_2 >= 0) && (sec_r000422_6_2 <= 255));
  __CPROVER_assume((sec_r000422_7_1 >= 0) && (sec_r000422_7_1 <= 255));
  __CPROVER_assume((sec_r000422_7_2 >= 0) && (sec_r000422_7_2 <= 255));
  __CPROVER_assume((sec_r000422_8_1 >= 0) && (sec_r000422_8_1 <= 255));
  __CPROVER_assume((sec_r000422_8_2 >= 0) && (sec_r000422_8_2 <= 255));
  __CPROVER_assume((sec_r000422_9_1 >= 0) && (sec_r000422_9_1 <= 255));
  __CPROVER_assume((sec_r000422_9_2 >= 0) && (sec_r000422_9_2 <= 255));
  __CPROVER_assume((sec_r000422_10_1 >= 0) && (sec_r000422_10_1 <= 255));
  __CPROVER_assume((sec_r000422_10_2 >= 0) && (sec_r000422_10_2 <= 255));
  __CPROVER_assume((sec_r000422_11_1 >= 0) && (sec_r000422_11_1 <= 255));
  __CPROVER_assume((sec_r000422_11_2 >= 0) && (sec_r000422_11_2 <= 255));
  __CPROVER_assume((sec_r000422_12_1 >= 0) && (sec_r000422_12_1 <= 255));
  __CPROVER_assume((sec_r000422_12_2 >= 0) && (sec_r000422_12_2 <= 255));
  __CPROVER_assume((sec_r000422_13_1 >= 0) && (sec_r000422_13_1 <= 255));
  __CPROVER_assume((sec_r000422_13_2 >= 0) && (sec_r000422_13_2 <= 255));
  __CPROVER_assume((sec_r000422_14_1 >= 0) && (sec_r000422_14_1 <= 255));
  __CPROVER_assume((sec_r000422_14_2 >= 0) && (sec_r000422_14_2 <= 255));
  __CPROVER_assume((sec_r000422_15_1 >= 0) && (sec_r000422_15_1 <= 255));
  __CPROVER_assume((sec_r000422_15_2 >= 0) && (sec_r000422_15_2 <= 255));
  __CPROVER_assume((sec_r000422_16_1 >= 0) && (sec_r000422_16_1 <= 255));
  __CPROVER_assume((sec_r000422_16_2 >= 0) && (sec_r000422_16_2 <= 255));
  __CPROVER_assume((sec_r000422_17_1 >= 0) && (sec_r000422_17_1 <= 255));
  __CPROVER_assume((sec_r000422_17_2 >= 0) && (sec_r000422_17_2 <= 255));
  struct CipherContext_R000422_2213_0 st_var_0_1 = {0};
  struct CipherContext_R000422_2213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000422_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000422_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000422_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000422_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000422_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000422_0_2 + 7) & 15;
  struct Vector3D_R000422_2213_1 st_var_1_1 = {0};
  struct Vector3D_R000422_2213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000422_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000422_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000422_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000422_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000422_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000422_0_2 + 9) & 15;
  struct AudioFrame_R000422_2213_2 st_var_2_1 = {0};
  struct AudioFrame_R000422_2213_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000422_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000422_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000422_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000422_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000422_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000422_0_2 + 11) & 15;
  union ColorPixel_R000422_2213_0 u_var_1;
  union ColorPixel_R000422_2213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 3) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = 0;
  int stage_v_4_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_4_1 = ((stage_v_4_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_4_2 = ((stage_v_4_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = ((st_var_2_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_2_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 51)
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
  if (stage_v_5_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 51)
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
  int stage_v_7_1 = ((st_var_1_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_1_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 29)
    {
      chk_sum_1 ^= stage_v_7_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_7_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 29)
    {
      chk_sum_2 ^= stage_v_7_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_10_1 = (st_var_1_1.buffer[0] ^ 13) & 3;
  int stage_v_10_2 = (st_var_1_2.buffer[0] ^ 13) & 3;
  switch (stage_v_10_1)
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

  switch (stage_v_10_2)
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

  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (st_var_0_1.buffer[0] ^ 15) & 3;
  int stage_v_12_2 = (st_var_0_2.buffer[0] ^ 15) & 3;
  switch (stage_v_12_1)
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

  switch (stage_v_12_2)
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

  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = table_1[0];
  int stage_v_16_2 = table_2[0];
  table_1[0] = (table_1[1] + 33) & 63;
  table_2[0] = (table_2[1] + 33) & 63;
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 20) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 20) & 15;
  int stage_v_19_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_19_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= stage_v_19_1;
  chk_sum_2 ^= stage_v_19_2;
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
  int stage_v_21_1 = ((st_var_0_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_0_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 45)
    {
      chk_sum_1 ^= stage_v_21_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_21_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 45)
    {
      chk_sum_2 ^= stage_v_21_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 24) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_25_1 = ((stage_v_25_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_25_2 = ((stage_v_25_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = ((st_var_2_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_2_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 44)
    {
      chk_sum_1 ^= stage_v_26_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_26_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 44)
    {
      chk_sum_2 ^= stage_v_26_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_27_1 = (st_var_0_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_0_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
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

  switch (stage_v_27_2)
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

  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
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
  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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
  int stage_v_35_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (40 & 31);
  int stage_v_35_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (40 & 31);
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= (stage_v_35_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_35_2 << 1) & 127;
  int stage_v_36_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (41 & 31);
  int stage_v_36_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (41 & 31);
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= (stage_v_36_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_36_2 << 1) & 127;
  int stage_v_37_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (42 & 31);
  int stage_v_37_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (42 & 31);
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= (stage_v_37_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_37_2 << 1) & 127;
  int stage_v_38_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_38_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (45 & 31);
  int stage_v_40_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (45 & 31);
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= (stage_v_40_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_40_2 << 1) & 127;
  int stage_v_41_1 = table_1[1];
  int stage_v_41_2 = table_2[1];
  table_1[1] = (table_1[2] + 83) & 63;
  table_2[1] = (table_2[2] + 83) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_42_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_43_1 = table_1[3];
  int stage_v_43_2 = table_2[3];
  table_1[3] = (table_1[0] + 87) & 63;
  table_2[3] = (table_2[0] + 87) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (st_var_2_1.buffer[0] ^ 47) & 3;
  int stage_v_44_2 = (st_var_2_2.buffer[0] ^ 47) & 3;
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 46) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_46_1 = ((stage_v_46_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_46_2 = ((stage_v_46_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((st_var_2_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_2_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 32)
    {
      chk_sum_1 ^= stage_v_47_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_47_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 32)
    {
      chk_sum_2 ^= stage_v_47_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_48_1 = (st_var_0_1.buffer[0] ^ 51) & 3;
  int stage_v_48_2 = (st_var_0_2.buffer[0] ^ 51) & 3;
  switch (stage_v_48_1)
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

  switch (stage_v_48_2)
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

  int stage_v_50_1 = (st_var_2_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_2_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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

  int stage_v_51_1 = ((st_var_0_1.buffer[0] * 2) + 160) & 63;
  int stage_v_51_2 = ((st_var_0_2.buffer[0] * 2) + 160) & 63;
  if (stage_v_51_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_51_1) - 5) & 255;
    if (stage_v_51_1 > 32)
    {
      chk_sum_1 ^= stage_v_51_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_51_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_51_2) - 5) & 255;
    if (stage_v_51_2 > 32)
    {
      chk_sum_2 ^= stage_v_51_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_52_1 = table_1[0];
  int stage_v_52_2 = table_2[0];
  table_1[0] = (table_1[1] + 105) & 63;
  table_2[0] = (table_2[1] + 105) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_53_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_53_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_53_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_54_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (59 & 31);
  int stage_v_54_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (59 & 31);
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= (stage_v_54_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_54_2 << 1) & 127;
  int stage_v_55_1 = (st_var_1_1.buffer[0] ^ 58) & 3;
  int stage_v_55_2 = (st_var_1_2.buffer[0] ^ 58) & 3;
  switch (stage_v_55_1)
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

  switch (stage_v_55_2)
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

  int stage_v_56_1 = ((st_var_2_1.buffer[2] * 2) + 175) & 63;
  int stage_v_56_2 = ((st_var_2_2.buffer[2] * 2) + 175) & 63;
  if (stage_v_56_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_56_1) - 5) & 255;
    if (stage_v_56_1 > 44)
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
  if (stage_v_56_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_56_2) - 5) & 255;
    if (stage_v_56_2 > 44)
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
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_57_1 = ((stage_v_57_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_59_1 = ((st_var_2_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_2_2.buffer[2] * 2) + 184) & 63;
  if (stage_v_59_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 35)
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
  if (stage_v_59_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 35)
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
  int stage_v_61_1 = (st_var_1_1.buffer[0] ^ 64) & 3;
  int stage_v_61_2 = (st_var_1_2.buffer[0] ^ 64) & 3;
  switch (stage_v_61_1)
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

  switch (stage_v_61_2)
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

  int stage_v_62_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_62_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_62_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_62_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 64) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 64) & 15;
  int stage_v_63_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_63_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= stage_v_63_1;
  chk_sum_2 ^= stage_v_63_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 65) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 65) & 15;
  int stage_v_64_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_64_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= stage_v_64_1;
  chk_sum_2 ^= stage_v_64_2;
  int stage_v_65_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_65_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_65_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_65_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_66_1 = ((stage_v_66_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_66_2 = ((stage_v_66_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 68) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 68) & 15;
  int stage_v_67_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_67_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= stage_v_67_1;
  chk_sum_2 ^= stage_v_67_2;
  int stage_v_68_1 = ((st_var_2_1.buffer[2] * 2) + 211) & 63;
  int stage_v_68_2 = ((st_var_2_2.buffer[2] * 2) + 211) & 63;
  if (stage_v_68_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_68_1) - 5) & 255;
    if (stage_v_68_1 > 28)
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
  if (stage_v_68_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_68_2) - 5) & 255;
    if (stage_v_68_2 > 28)
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
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_69_1 = ((stage_v_69_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_69_2 = ((stage_v_69_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((st_var_1_1.buffer[1] * 2) + 217) & 63;
  int stage_v_70_2 = ((st_var_1_2.buffer[1] * 2) + 217) & 63;
  if (stage_v_70_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_70_1) - 5) & 255;
    if (stage_v_70_1 > 33)
    {
      chk_sum_1 ^= stage_v_70_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_70_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_70_2) - 5) & 255;
    if (stage_v_70_2 > 33)
    {
      chk_sum_2 ^= stage_v_70_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_71_1 = table_1[3];
  int stage_v_71_2 = table_2[3];
  table_1[3] = (table_1[0] + 143) & 63;
  table_2[3] = (table_2[0] + 143) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((st_var_0_1.buffer[0] * 2) + 223) & 63;
  int stage_v_72_2 = ((st_var_0_2.buffer[0] * 2) + 223) & 63;
  if (stage_v_72_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_72_1) - 5) & 255;
    if (stage_v_72_1 > 41)
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
  if (stage_v_72_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_72_2) - 5) & 255;
    if (stage_v_72_2 > 41)
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
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_74_1 = ((stage_v_74_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_74_2 = ((stage_v_74_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (80 & 31);
  int stage_v_75_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (80 & 31);
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  chk_sum_1 ^= (stage_v_75_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_75_2 << 1) & 127;
  int stage_v_76_1 = (st_var_1_1.buffer[0] ^ 79) & 3;
  int stage_v_76_2 = (st_var_1_2.buffer[0] ^ 79) & 3;
  switch (stage_v_76_1)
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

  switch (stage_v_76_2)
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

  int stage_v_77_1 = (st_var_2_1.buffer[0] ^ 80) & 3;
  int stage_v_77_2 = (st_var_2_2.buffer[0] ^ 80) & 3;
  switch (stage_v_77_1)
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

  switch (stage_v_77_2)
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

  int stage_v_78_1 = ((st_var_0_1.buffer[0] * 2) + 241) & 63;
  int stage_v_78_2 = ((st_var_0_2.buffer[0] * 2) + 241) & 63;
  if (stage_v_78_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_78_1) - 5) & 255;
    if (stage_v_78_1 > 54)
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
  if (stage_v_78_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_78_2) - 5) & 255;
    if (stage_v_78_2 > 54)
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
  int stage_v_79_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_79_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_79_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_79_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_80_1 = (st_var_2_1.buffer[0] ^ 83) & 3;
  int stage_v_80_2 = (st_var_2_2.buffer[0] ^ 83) & 3;
  switch (stage_v_80_1)
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

  switch (stage_v_80_2)
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

  int stage_v_81_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (86 & 31);
  int stage_v_81_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (86 & 31);
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  chk_sum_1 ^= (stage_v_81_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_81_2 << 1) & 127;
  int stage_v_82_1 = ((st_var_1_1.buffer[1] * 2) + 253) & 63;
  int stage_v_82_2 = ((st_var_1_2.buffer[1] * 2) + 253) & 63;
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 84) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 84) & 15;
  int stage_v_83_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_83_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= stage_v_83_1;
  chk_sum_2 ^= stage_v_83_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 85) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 85) & 15;
  int stage_v_84_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_84_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  chk_sum_1 ^= stage_v_84_1;
  chk_sum_2 ^= stage_v_84_2;
  int stage_v_85_1 = ((st_var_1_1.buffer[1] * 2) + 262) & 63;
  int stage_v_85_2 = ((st_var_1_2.buffer[1] * 2) + 262) & 63;
  if (stage_v_85_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_85_1) - 5) & 255;
    if (stage_v_85_1 > 35)
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
  if (stage_v_85_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_85_2) - 5) & 255;
    if (stage_v_85_2 > 35)
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
  int stage_v_86_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (91 & 31);
  int stage_v_86_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (91 & 31);
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  chk_sum_1 ^= (stage_v_86_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_86_2 << 1) & 127;
  int stage_v_87_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_87_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_87_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_87_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_88_1 = ((stage_v_88_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_88_2 = ((stage_v_88_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 90) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 90) & 15;
  int stage_v_89_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_89_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  chk_sum_1 ^= stage_v_89_1;
  chk_sum_2 ^= stage_v_89_2;
  int stage_v_90_1 = ((st_var_0_1.buffer[0] * 2) + 277) & 63;
  int stage_v_90_2 = ((st_var_0_2.buffer[0] * 2) + 277) & 63;
  if (stage_v_90_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_90_1) - 5) & 255;
    if (stage_v_90_1 > 40)
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
  if (stage_v_90_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_90_2) - 5) & 255;
    if (stage_v_90_2 > 40)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 93) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 93) & 15;
  int stage_v_92_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_92_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  chk_sum_1 ^= stage_v_92_1;
  chk_sum_2 ^= stage_v_92_2;
  int stage_v_93_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (98 & 31);
  int stage_v_93_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (98 & 31);
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  chk_sum_1 ^= (stage_v_93_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_93_2 << 1) & 127;
  int stage_v_94_1 = table_1[2];
  int stage_v_94_2 = table_2[2];
  table_1[2] = (table_1[3] + 189) & 63;
  table_2[2] = (table_2[3] + 189) & 63;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((st_var_2_1.buffer[2] * 2) + 292) & 63;
  int stage_v_95_2 = ((st_var_2_2.buffer[2] * 2) + 292) & 63;
  if (stage_v_95_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_95_1) - 5) & 255;
    if (stage_v_95_1 > 40)
    {
      chk_sum_1 ^= stage_v_95_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_95_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_95_2) - 5) & 255;
    if (stage_v_95_2 > 40)
    {
      chk_sum_2 ^= stage_v_95_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_96_1 = (st_var_0_1.buffer[0] ^ 99) & 3;
  int stage_v_96_2 = (st_var_0_2.buffer[0] ^ 99) & 3;
  switch (stage_v_96_1)
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

  switch (stage_v_96_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 98) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 98) & 15;
  int stage_v_97_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_97_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  chk_sum_1 ^= stage_v_97_1;
  chk_sum_2 ^= stage_v_97_2;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_98_1 = ((stage_v_98_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_98_2 = ((stage_v_98_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
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
  int stage_v_101_1 = table_1[1];
  int stage_v_101_2 = table_2[1];
  table_1[1] = (table_1[2] + 203) & 63;
  table_2[1] = (table_2[2] + 203) & 63;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 103) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 103) & 15;
  int stage_v_102_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_102_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  chk_sum_1 ^= stage_v_102_1;
  chk_sum_2 ^= stage_v_102_2;
  int stage_v_103_1 = (st_var_1_1.buffer[0] ^ 106) & 3;
  int stage_v_103_2 = (st_var_1_2.buffer[0] ^ 106) & 3;
  switch (stage_v_103_1)
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

  switch (stage_v_103_2)
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

  int stage_v_104_1 = table_1[0];
  int stage_v_104_2 = table_2[0];
  table_1[0] = (table_1[1] + 209) & 63;
  table_2[0] = (table_2[1] + 209) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 106) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 106) & 15;
  int stage_v_105_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_105_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  chk_sum_1 ^= stage_v_105_1;
  chk_sum_2 ^= stage_v_105_2;
  int stage_v_106_1 = table_1[2];
  int stage_v_106_2 = table_2[2];
  table_1[2] = (table_1[3] + 213) & 63;
  table_2[2] = (table_2[3] + 213) & 63;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
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
  int stage_v_108_1 = ((st_var_0_1.buffer[0] * 2) + 331) & 63;
  int stage_v_108_2 = ((st_var_0_2.buffer[0] * 2) + 331) & 63;
  if (stage_v_108_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_108_1) - 5) & 255;
    if (stage_v_108_1 > 52)
    {
      chk_sum_1 ^= stage_v_108_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_108_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_108_2) - 5) & 255;
    if (stage_v_108_2 > 52)
    {
      chk_sum_2 ^= stage_v_108_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_109_1 = table_1[1];
  int stage_v_109_2 = table_2[1];
  table_1[1] = (table_1[2] + 219) & 63;
  table_2[1] = (table_2[2] + 219) & 63;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = table_1[2];
  int stage_v_110_2 = table_2[2];
  table_1[2] = (table_1[3] + 221) & 63;
  table_2[2] = (table_2[3] + 221) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (116 & 31);
  int stage_v_111_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (116 & 31);
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  chk_sum_1 ^= (stage_v_111_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_111_2 << 1) & 127;
  int stage_v_112_1 = table_1[0];
  int stage_v_112_2 = table_2[0];
  table_1[0] = (table_1[1] + 225) & 63;
  table_2[0] = (table_2[1] + 225) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = table_1[1];
  int stage_v_113_2 = table_2[1];
  table_1[1] = (table_1[2] + 227) & 63;
  table_2[1] = (table_2[2] + 227) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 116) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 116) & 15;
  int stage_v_115_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_115_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  chk_sum_1 ^= stage_v_115_1;
  chk_sum_2 ^= stage_v_115_2;
  int stage_v_116_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (121 & 31);
  int stage_v_116_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (121 & 31);
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  chk_sum_1 ^= (stage_v_116_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_116_2 << 1) & 127;
  int stage_v_117_1 = ((st_var_0_1.buffer[0] * 2) + 358) & 63;
  int stage_v_117_2 = ((st_var_0_2.buffer[0] * 2) + 358) & 63;
  if (stage_v_117_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_117_1) - 5) & 255;
    if (stage_v_117_1 > 25)
    {
      chk_sum_1 ^= stage_v_117_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_117_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_117_2) - 5) & 255;
    if (stage_v_117_2 > 25)
    {
      chk_sum_2 ^= stage_v_117_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_118_1 = table_1[2];
  int stage_v_118_2 = table_2[2];
  table_1[2] = (table_1[3] + 237) & 63;
  table_2[2] = (table_2[3] + 237) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((st_var_2_1.buffer[2] * 2) + 364) & 63;
  int stage_v_119_2 = ((st_var_2_2.buffer[2] * 2) + 364) & 63;
  if (stage_v_119_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_119_1) - 5) & 255;
    if (stage_v_119_1 > 47)
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
  if (stage_v_119_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_119_2) - 5) & 255;
    if (stage_v_119_2 > 47)
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
  int stage_v_120_1 = ((st_var_0_1.buffer[0] * 2) + 367) & 63;
  int stage_v_120_2 = ((st_var_0_2.buffer[0] * 2) + 367) & 63;
  if (stage_v_120_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_120_1) - 5) & 255;
    if (stage_v_120_1 > 31)
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
  if (stage_v_120_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_120_2) - 5) & 255;
    if (stage_v_120_2 > 31)
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
  int stage_v_121_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_121_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_121_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_121_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_122_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_122_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_122_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_122_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_123_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_123_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_123_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_123_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_124_1 = ((st_var_1_1.buffer[1] * 2) + 379) & 63;
  int stage_v_124_2 = ((st_var_1_2.buffer[1] * 2) + 379) & 63;
  if (stage_v_124_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_124_1) - 5) & 255;
    if (stage_v_124_1 > 25)
    {
      chk_sum_1 ^= stage_v_124_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_124_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_124_2) - 5) & 255;
    if (stage_v_124_2 > 25)
    {
      chk_sum_2 ^= stage_v_124_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 126) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 126) & 15;
  int stage_v_125_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_125_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  chk_sum_1 ^= stage_v_125_1;
  chk_sum_2 ^= stage_v_125_2;
  int stage_v_126_1 = (st_var_0_1.buffer[0] ^ 129) & 3;
  int stage_v_126_2 = (st_var_0_2.buffer[0] ^ 129) & 3;
  switch (stage_v_126_1)
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

  switch (stage_v_126_2)
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

  int stage_v_127_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (132 & 31);
  int stage_v_127_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (132 & 31);
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  chk_sum_1 ^= (stage_v_127_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_127_2 << 1) & 127;
  int stage_v_128_1 = table_1[0];
  int stage_v_128_2 = table_2[0];
  table_1[0] = (table_1[1] + 257) & 63;
  table_2[0] = (table_2[1] + 257) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = table_1[1];
  int stage_v_129_2 = table_2[1];
  table_1[1] = (table_1[2] + 259) & 63;
  table_2[1] = (table_2[2] + 259) & 63;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((st_var_1_1.buffer[1] * 2) + 397) & 63;
  int stage_v_130_2 = ((st_var_1_2.buffer[1] * 2) + 397) & 63;
  if (stage_v_130_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_130_1) - 5) & 255;
    if (stage_v_130_1 > 48)
    {
      chk_sum_1 ^= stage_v_130_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_130_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_130_2) - 5) & 255;
    if (stage_v_130_2 > 48)
    {
      chk_sum_2 ^= stage_v_130_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_131_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_131_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_131_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_131_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_132_1 = ((stage_v_132_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_132_2 = ((stage_v_132_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_133_1 = ((stage_v_133_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_133_2 = ((stage_v_133_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
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
  int stage_v_135_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (140 & 31);
  int stage_v_135_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (140 & 31);
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  chk_sum_1 ^= (stage_v_135_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_135_2 << 1) & 127;
  int stage_v_136_1 = ((st_var_1_1.buffer[1] * 2) + 415) & 63;
  int stage_v_136_2 = ((st_var_1_2.buffer[1] * 2) + 415) & 63;
  if (stage_v_136_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_136_1) - 5) & 255;
    if (stage_v_136_1 > 49)
    {
      chk_sum_1 ^= stage_v_136_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_136_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_136_2) - 5) & 255;
    if (stage_v_136_2 > 49)
    {
      chk_sum_2 ^= stage_v_136_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_137_1 = ((st_var_2_1.buffer[2] * 2) + 418) & 63;
  int stage_v_137_2 = ((st_var_2_2.buffer[2] * 2) + 418) & 63;
  if (stage_v_137_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_137_1) - 5) & 255;
    if (stage_v_137_1 > 29)
    {
      chk_sum_1 ^= stage_v_137_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_137_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_137_2) - 5) & 255;
    if (stage_v_137_2 > 29)
    {
      chk_sum_2 ^= stage_v_137_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_140_1 = table_1[0];
  int stage_v_140_2 = table_2[0];
  table_1[0] = (table_1[1] + 281) & 63;
  table_2[0] = (table_2[1] + 281) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 143) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 143) & 15;
  int stage_v_142_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_142_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  chk_sum_1 ^= stage_v_142_1;
  chk_sum_2 ^= stage_v_142_2;
  int stage_v_143_1 = ((st_var_2_1.buffer[2] * 2) + 436) & 63;
  int stage_v_143_2 = ((st_var_2_2.buffer[2] * 2) + 436) & 63;
  if (stage_v_143_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_143_1) - 5) & 255;
    if (stage_v_143_1 > 27)
    {
      chk_sum_1 ^= stage_v_143_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_143_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_143_2) - 5) & 255;
    if (stage_v_143_2 > 27)
    {
      chk_sum_2 ^= stage_v_143_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_144_1 = table_1[0];
  int stage_v_144_2 = table_2[0];
  table_1[0] = (table_1[1] + 289) & 63;
  table_2[0] = (table_2[1] + 289) & 63;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = table_1[1];
  int stage_v_145_2 = table_2[1];
  table_1[1] = (table_1[2] + 291) & 63;
  table_2[1] = (table_2[2] + 291) & 63;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_146_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_146_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_146_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
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
  int stage_v_148_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (153 & 31);
  int stage_v_148_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (153 & 31);
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  chk_sum_1 ^= (stage_v_148_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_148_2 << 1) & 127;
  int stage_v_149_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (154 & 31);
  int stage_v_149_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (154 & 31);
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  chk_sum_1 ^= (stage_v_149_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_149_2 << 1) & 127;
  int stage_v_150_1 = ((st_var_0_1.buffer[0] * 2) + 457) & 63;
  int stage_v_150_2 = ((st_var_0_2.buffer[0] * 2) + 457) & 63;
  if (stage_v_150_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_150_1) - 5) & 255;
    if (stage_v_150_1 > 45)
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
  if (stage_v_150_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_150_2) - 5) & 255;
    if (stage_v_150_2 > 45)
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
  int stage_v_151_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (156 & 31);
  int stage_v_151_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (156 & 31);
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  chk_sum_1 ^= (stage_v_151_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_151_2 << 1) & 127;
  int stage_v_152_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_152_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_152_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_152_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_153_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_153_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_153_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_153_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_154_1 = (st_var_1_1.buffer[0] ^ 157) & 3;
  int stage_v_154_2 = (st_var_1_2.buffer[0] ^ 157) & 3;
  switch (stage_v_154_1)
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

  switch (stage_v_154_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 156) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 156) & 15;
  int stage_v_155_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_155_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  chk_sum_1 ^= stage_v_155_1;
  chk_sum_2 ^= stage_v_155_2;
  int stage_v_156_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_156_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_156_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_156_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_157_1 = (st_var_1_1.buffer[0] ^ 160) & 3;
  int stage_v_157_2 = (st_var_1_2.buffer[0] ^ 160) & 3;
  switch (stage_v_157_1)
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

  switch (stage_v_157_2)
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

  int stage_v_158_1 = ((st_var_2_1.buffer[2] * 2) + 481) & 63;
  int stage_v_158_2 = ((st_var_2_2.buffer[2] * 2) + 481) & 63;
  if (stage_v_158_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_158_1) - 5) & 255;
    if (stage_v_158_1 > 27)
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
  if (stage_v_158_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_158_2) - 5) & 255;
    if (stage_v_158_2 > 27)
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
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_159_1 = ((stage_v_159_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_159_2 = ((stage_v_159_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_160_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_160_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_160_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_161_1 = ((st_var_2_1.buffer[2] * 2) + 490) & 63;
  int stage_v_161_2 = ((st_var_2_2.buffer[2] * 2) + 490) & 63;
  if (stage_v_161_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_161_1) - 5) & 255;
    if (stage_v_161_1 > 41)
    {
      chk_sum_1 ^= stage_v_161_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_161_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_161_2) - 5) & 255;
    if (stage_v_161_2 > 41)
    {
      chk_sum_2 ^= stage_v_161_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_162_1 = ((st_var_0_1.buffer[0] * 2) + 493) & 63;
  int stage_v_162_2 = ((st_var_0_2.buffer[0] * 2) + 493) & 63;
  if (stage_v_162_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_162_1) - 5) & 255;
    if (stage_v_162_1 > 49)
    {
      chk_sum_1 ^= stage_v_162_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_162_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_162_2) - 5) & 255;
    if (stage_v_162_2 > 49)
    {
      chk_sum_2 ^= stage_v_162_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_163_1 = (st_var_1_1.buffer[0] ^ 166) & 3;
  int stage_v_163_2 = (st_var_1_2.buffer[0] ^ 166) & 3;
  switch (stage_v_163_1)
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

  switch (stage_v_163_2)
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

  int stage_v_164_1 = table_1[0];
  int stage_v_164_2 = table_2[0];
  table_1[0] = (table_1[1] + 329) & 63;
  table_2[0] = (table_2[1] + 329) & 63;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_165_1 = ((stage_v_165_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_165_2 = ((stage_v_165_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (st_var_1_1.buffer[0] ^ 169) & 3;
  int stage_v_166_2 = (st_var_1_2.buffer[0] ^ 169) & 3;
  switch (stage_v_166_1)
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

  switch (stage_v_166_2)
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

  int stage_v_167_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (172 & 31);
  int stage_v_167_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (172 & 31);
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  chk_sum_1 ^= (stage_v_167_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_167_2 << 1) & 127;
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
  int stage_v_169_1 = table_1[1];
  int stage_v_169_2 = table_2[1];
  table_1[1] = (table_1[2] + 339) & 63;
  table_2[1] = (table_2[2] + 339) & 63;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (st_var_2_1.buffer[0] ^ 173) & 3;
  int stage_v_170_2 = (st_var_2_2.buffer[0] ^ 173) & 3;
  switch (stage_v_170_1)
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

  switch (stage_v_170_2)
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

  int stage_v_171_1 = (st_var_0_1.buffer[0] ^ 174) & 3;
  int stage_v_171_2 = (st_var_0_2.buffer[0] ^ 174) & 3;
  switch (stage_v_171_1)
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

  switch (stage_v_171_2)
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

  int b_w0_1 = (sec_r000422_3_1 ^ 0x5A) & 63;
  int b_w0_2 = (sec_r000422_3_2 ^ 0x5A) & 63;
  int b_w1_1 = ((b_w0_1 << 1) | (sec_r000422_15_1 >> 1)) & 63;
  int b_w1_2 = ((b_w0_2 << 1) | (sec_r000422_15_2 >> 1)) & 63;
  int b_w2_1 = ((b_w1_1 << 2) | (sec_r000422_12_1 >> 2)) & 63;
  int b_w2_2 = ((b_w1_2 << 2) | (sec_r000422_12_2 >> 2)) & 63;
  int b_w3_1 = ((b_w2_1 << 2) & (sec_r000422_0_1 >> 2)) & 63;
  int b_w3_2 = ((b_w2_2 << 2) & (sec_r000422_0_2 >> 2)) & 63;
  int b_w4_1 = ((b_w3_1 << 1) & (sec_r000422_17_1 >> 1)) & 63;
  int b_w4_2 = ((b_w3_2 << 1) & (sec_r000422_17_2 >> 1)) & 63;
  int b_w5_1 = ((b_w4_1 << 2) & (sec_r000422_3_1 >> 2)) & 63;
  int b_w5_2 = ((b_w4_2 << 2) & (sec_r000422_3_2 >> 2)) & 63;
  out_sink_1 += b_w5_1 & 63;
  out_sink_2 += b_w5_2 & 63;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000422_4_1 == pub_r000422_4_2);
  __CPROVER_assume(sec_r000422_7_1 != sec_r000422_7_2);
  __CPROVER_assume(sec_r000422_1_1 != sec_r000422_1_2);
  __CPROVER_assume(sec_r000422_8_1 != sec_r000422_8_2);
  __CPROVER_assume(sec_r000422_11_1 != sec_r000422_11_2);
  __CPROVER_assume(pub_r000422_2_1 == pub_r000422_2_2);
  __CPROVER_assume(pub_r000422_11_1 == pub_r000422_11_2);
  __CPROVER_assume(pub_r000422_7_1 == pub_r000422_7_2);
  __CPROVER_assume(sec_r000422_6_1 != sec_r000422_6_2);
  __CPROVER_assume(pub_r000422_0_1 == pub_r000422_0_2);
  __CPROVER_assume(sec_r000422_13_1 != sec_r000422_13_2);
  __CPROVER_assume(sec_r000422_14_1 != sec_r000422_14_2);
  __CPROVER_assume(sec_r000422_10_1 != sec_r000422_10_2);
  __CPROVER_assume(pub_r000422_1_1 == pub_r000422_1_2);
  __CPROVER_assume(pub_r000422_16_1 == pub_r000422_16_2);
  __CPROVER_assume(pub_r000422_10_1 == pub_r000422_10_2);
  __CPROVER_assume(sec_r000422_15_1 != sec_r000422_15_2);
  __CPROVER_assume(sec_r000422_3_1 != sec_r000422_3_2);
  __CPROVER_assume(sec_r000422_0_1 != sec_r000422_0_2);
  __CPROVER_assume(pub_r000422_12_1 == pub_r000422_12_2);
  __CPROVER_assume(pub_r000422_13_1 == pub_r000422_13_2);
  __CPROVER_assume(sec_r000422_2_1 != sec_r000422_2_2);
  __CPROVER_assume(pub_r000422_6_1 == pub_r000422_6_2);
  __CPROVER_assume(sec_r000422_12_1 != sec_r000422_12_2);
  __CPROVER_assume(sec_r000422_17_1 != sec_r000422_17_2);
  __CPROVER_assume(pub_r000422_3_1 == pub_r000422_3_2);
  __CPROVER_assume(pub_r000422_15_1 == pub_r000422_15_2);
  __CPROVER_assume(pub_r000422_14_1 == pub_r000422_14_2);
  __CPROVER_assume(pub_r000422_9_1 == pub_r000422_9_2);
  __CPROVER_assume(pub_r000422_5_1 == pub_r000422_5_2);
  __CPROVER_assume(sec_r000422_4_1 != sec_r000422_4_2);
  __CPROVER_assume(pub_r000422_8_1 == pub_r000422_8_2);
  __CPROVER_assume(pub_r000422_17_1 == pub_r000422_17_2);
  __CPROVER_assume(sec_r000422_5_1 != sec_r000422_5_2);
  __CPROVER_assume(sec_r000422_9_1 != sec_r000422_9_2);
  __CPROVER_assume(sec_r000422_16_1 != sec_r000422_16_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.sample_rate == st_var_2_2.sample_rate);
  assert(st_var_2_1.rms == st_var_2_2.rms);
  assert(st_var_2_1.channels == st_var_2_2.channels);
  assert(st_var_2_1.envelope == st_var_2_2.envelope);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.peak == st_var_2_2.peak);
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
  assert(b_w0_1 == b_w0_2);
  assert(b_w1_1 == b_w1_2);
  assert(b_w2_1 == b_w2_2);
  assert(b_w3_1 == b_w3_2);
  assert(b_w4_1 == b_w4_2);
  assert(b_w5_1 == b_w5_2);
}


