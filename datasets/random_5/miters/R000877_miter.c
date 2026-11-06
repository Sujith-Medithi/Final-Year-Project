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
struct SensorNode_R000877_7713_0
{
  int gain;
  int offset;
  unsigned char threshold;
  int calib;
  int buffer[3];
};
struct Transaction_R000877_7713_1
{
  int account_id;
  unsigned char fee;
  short rate;
  int buffer[3];
};
union ColorPixel_R000877_7713_0
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
void fn_R000877_7713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st_1 = {0};
  struct Transaction_R000877_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_96_1 = local_arr_1[aux_1 % 3];
  int bound_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_96_2 * 2)) & 127;
  int threshold_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_30_1 > 20)
  {
    acc_1 = ((acc_1 + (threshold_30_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_30_2 > 20)
  {
    acc_2 = ((acc_2 + (threshold_30_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_30_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_14_1) & 63;
  aux_2 = (aux_2 + segment_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_96_1 == bound_96_2);
  assert(threshold_30_1 == threshold_30_2);
  assert(segment_14_1 == segment_14_2);
}

int fn_R000877_7713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int bound_96 = local_arr[aux % 3];
  acc = (acc + (bound_96 * 2)) & 127;
  int threshold_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_30 > 20)
  {
    acc = ((acc + (threshold_30 * 2)) + 5) & 127;
    aux ^= threshold_30 & 15;
  }
  else
  {
    acc = ((acc - threshold_30) + 11) & 127;
    aux += 3;
  }
  int segment_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_14) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000877_7713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st_1 = {0};
  struct Transaction_R000877_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int segment_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_14_1)
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

  switch (segment_14_2)
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

  int mask_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_30_1) & 63;
  aux_2 = (aux_2 + mask_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_14_1 == segment_14_2);
  assert(mask_30_1 == mask_30_2);
}

int fn_R000877_7713_1(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int segment_14 = (aux + st.buffer[1]) & 3;
  switch (segment_14)
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

  int mask_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_30) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000877_7713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st_1 = {0};
  struct Transaction_R000877_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int checksum_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_89_1) & 63;
  aux_2 = (aux_2 + checksum_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_23_1 = local_arr_1[aux_1 % 3];
  int window_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_23_2 * 2)) & 127;
  int stride_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_20_1)
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

  switch (stride_20_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_89_1 == checksum_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_23_1 == window_23_2);
  assert(stride_20_1 == stride_20_2);
}

int fn_R000877_7713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int checksum_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_89) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_23 = local_arr[aux % 3];
  acc = (acc + (window_23 * 2)) & 127;
  int stride_20 = (aux + st.buffer[1]) & 3;
  switch (stride_20)
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

void fn_R000877_7713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000877_7713_0 st_1 = {0};
  struct SensorNode_R000877_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int factor_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_92_1) & 63;
  aux_2 = (aux_2 + factor_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_38_1 > 29)
  {
    acc_1 = ((acc_1 + (damping_38_1 * 2)) + 5) & 127;
    aux_1 ^= damping_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_38_2 > 29)
  {
    acc_2 = ((acc_2 + (damping_38_2 * 2)) + 5) & 127;
    aux_2 ^= damping_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_38_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_92_1 == factor_92_2);
  assert(damping_38_1 == damping_38_2);
}

int fn_R000877_7713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000877_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int factor_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_92) & 63;
  acc ^= aux;
  int damping_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_38 > 29)
  {
    acc = ((acc + (damping_38 * 2)) + 5) & 127;
    aux ^= damping_38 & 15;
  }
  else
  {
    acc = ((acc - damping_38) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000877_7713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st_1 = {0};
  struct Transaction_R000877_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_56_1) & 63;
  aux_2 = (aux_2 + weight_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_56_1 == weight_56_2);
}

int fn_R000877_7713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_56) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000877_7713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st_1 = {0};
  struct Transaction_R000877_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int window_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_86_1 > 36)
  {
    acc_1 = ((acc_1 + (window_86_1 * 2)) + 5) & 127;
    aux_1 ^= window_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_86_2 > 36)
  {
    acc_2 = ((acc_2 + (window_86_2 * 2)) + 5) & 127;
    aux_2 ^= window_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_38_1) & 63;
  aux_2 = (aux_2 + tally_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_97_1 = local_arr_1[aux_1 % 3];
  int weight_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_97_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_86_1 == window_86_2);
  assert(tally_38_1 == tally_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_97_1 == weight_97_2);
}

int fn_R000877_7713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int window_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_86 > 36)
  {
    acc = ((acc + (window_86 * 2)) + 5) & 127;
    aux ^= window_86 & 15;
  }
  else
  {
    acc = ((acc - window_86) + 11) & 127;
    aux += 3;
  }
  int tally_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_38) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int weight_97 = local_arr[aux % 3];
  acc = (acc + (weight_97 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000877_7713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000877_7713_0 st_1 = {0};
  struct SensorNode_R000877_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int weight_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_50_1)
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

  switch (weight_50_2)
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

  int window_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_72_1 > 37)
  {
    acc_1 = ((acc_1 + (window_72_1 * 2)) + 5) & 127;
    aux_1 ^= window_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_72_2 > 37)
  {
    acc_2 = ((acc_2 + (window_72_2 * 2)) + 5) & 127;
    aux_2 ^= window_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_72_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_50_1 == weight_50_2);
  assert(window_72_1 == window_72_2);
}

int fn_R000877_7713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000877_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int weight_50 = (aux + st.buffer[1]) & 3;
  switch (weight_50)
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

  int window_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_72 > 37)
  {
    acc = ((acc + (window_72 * 2)) + 5) & 127;
    aux ^= window_72 & 15;
  }
  else
  {
    acc = ((acc - window_72) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000877_7713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st_1 = {0};
  struct Transaction_R000877_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_74_1 = local_arr_1[aux_1 % 3];
  int cursor_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_74_2 * 2)) & 127;
  int sample_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_42_1) & 63;
  aux_2 = (aux_2 + sample_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_92_1 > 36)
  {
    acc_1 = ((acc_1 + (phase_92_1 * 2)) + 5) & 127;
    aux_1 ^= phase_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_92_2 > 36)
  {
    acc_2 = ((acc_2 + (phase_92_2 * 2)) + 5) & 127;
    aux_2 ^= phase_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_72_1)
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

  switch (cursor_72_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_74_1 == cursor_74_2);
  assert(sample_42_1 == sample_42_2);
  assert(phase_92_1 == phase_92_2);
  assert(cursor_72_1 == cursor_72_2);
}

int fn_R000877_7713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int cursor_74 = local_arr[aux % 3];
  acc = (acc + (cursor_74 * 2)) & 127;
  int sample_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_42) & 63;
  acc ^= aux;
  int phase_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_92 > 36)
  {
    acc = ((acc + (phase_92 * 2)) + 5) & 127;
    aux ^= phase_92 & 15;
  }
  else
  {
    acc = ((acc - phase_92) + 11) & 127;
    aux += 3;
  }
  int cursor_72 = (aux + st.buffer[1]) & 3;
  switch (cursor_72)
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

void fn_R000877_7713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000877_7713_0 st_1 = {0};
  struct SensorNode_R000877_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_32_1 = local_arr_1[aux_1 % 3];
  int damping_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_32_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_38_1 > 13)
  {
    acc_1 = ((acc_1 + (parity_38_1 * 2)) + 5) & 127;
    aux_1 ^= parity_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_38_2 > 13)
  {
    acc_2 = ((acc_2 + (parity_38_2 * 2)) + 5) & 127;
    aux_2 ^= parity_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_51_1)
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

  switch (accumulator_51_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_32_1 == damping_32_2);
  assert(parity_38_1 == parity_38_2);
  assert(accumulator_51_1 == accumulator_51_2);
}

int fn_R000877_7713_8(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000877_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int damping_32 = local_arr[aux % 3];
  acc = (acc + (damping_32 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_38 > 13)
  {
    acc = ((acc + (parity_38 * 2)) + 5) & 127;
    aux ^= parity_38 & 15;
  }
  else
  {
    acc = ((acc - parity_38) + 11) & 127;
    aux += 3;
  }
  int accumulator_51 = (aux + st.buffer[1]) & 3;
  switch (accumulator_51)
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

void fn_R000877_7713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st_1 = {0};
  struct Transaction_R000877_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_71_1 = local_arr_1[aux_1 % 3];
  int sample_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_71_2 * 2)) & 127;
  int tracker_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_16_1) & 63;
  aux_2 = (aux_2 + tracker_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_71_1 == sample_71_2);
  assert(tracker_16_1 == tracker_16_2);
}

int fn_R000877_7713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int sample_71 = local_arr[aux % 3];
  acc = (acc + (sample_71 * 2)) & 127;
  int tracker_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_16) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000877_7713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000877_7713_0 st_1 = {0};
  struct SensorNode_R000877_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int metric_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_17_1) & 63;
  aux_2 = (aux_2 + metric_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_59_1)
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

  switch (scale_59_2)
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
  int stride_61_1 = local_arr_1[aux_1 % 3];
  int stride_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_61_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_17_1 == metric_17_2);
  assert(scale_59_1 == scale_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_61_1 == stride_61_2);
}

int fn_R000877_7713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000877_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int metric_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_17) & 63;
  acc ^= aux;
  int scale_59 = (aux + st.buffer[1]) & 3;
  switch (scale_59)
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
  int stride_61 = local_arr[aux % 3];
  acc = (acc + (stride_61 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000877_7713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st_1 = {0};
  struct Transaction_R000877_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int tally_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_12_1 > 43)
  {
    acc_1 = ((acc_1 + (tally_12_1 * 2)) + 5) & 127;
    aux_1 ^= tally_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_12_2 > 43)
  {
    acc_2 = ((acc_2 + (tally_12_2 * 2)) + 5) & 127;
    aux_2 ^= tally_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_15_1)
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

  switch (anchor_15_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_58_1 = local_arr_1[aux_1 % 3];
  int quotient_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_58_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_12_1 == tally_12_2);
  assert(anchor_15_1 == anchor_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_58_1 == quotient_58_2);
}

int fn_R000877_7713_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int tally_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_12 > 43)
  {
    acc = ((acc + (tally_12 * 2)) + 5) & 127;
    aux ^= tally_12 & 15;
  }
  else
  {
    acc = ((acc - tally_12) + 11) & 127;
    aux += 3;
  }
  int anchor_15 = (aux + st.buffer[1]) & 3;
  switch (anchor_15)
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

  int local_arr[3] = {4, 9, 15};
  int quotient_58 = local_arr[aux % 3];
  acc = (acc + (quotient_58 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000877_7713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st_1 = {0};
  struct Transaction_R000877_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int mask_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_61_1) & 63;
  aux_2 = (aux_2 + mask_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_61_1 == mask_61_2);
}

int fn_R000877_7713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int mask_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_61) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000877_7713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st_1 = {0};
  struct Transaction_R000877_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int anchor_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_75_1) & 63;
  aux_2 = (aux_2 + anchor_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_24_1 > 41)
  {
    acc_1 = ((acc_1 + (margin_24_1 * 2)) + 5) & 127;
    aux_1 ^= margin_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_24_2 > 41)
  {
    acc_2 = ((acc_2 + (margin_24_2 * 2)) + 5) & 127;
    aux_2 ^= margin_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_24_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_75_1 == anchor_75_2);
  assert(margin_24_1 == margin_24_2);
}

int fn_R000877_7713_13(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int anchor_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_75) & 63;
  acc ^= aux;
  int margin_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_24 > 41)
  {
    acc = ((acc + (margin_24 * 2)) + 5) & 127;
    aux ^= margin_24 & 15;
  }
  else
  {
    acc = ((acc - margin_24) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000877_7713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000877_7713_0 st_1 = {0};
  struct SensorNode_R000877_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int checksum_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_59_1) & 63;
  aux_2 = (aux_2 + checksum_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_59_1 == checksum_59_2);
}

int fn_R000877_7713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000877_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int checksum_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_59) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000877_7713_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st_1 = {0};
  struct Transaction_R000877_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int index_reg_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_61_1)
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

  switch (index_reg_61_2)
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

  int weight_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_18_1) & 63;
  aux_2 = (aux_2 + weight_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_64_1 = local_arr_1[aux_1 % 3];
  int segment_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_64_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_61_1 == index_reg_61_2);
  assert(weight_18_1 == weight_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_64_1 == segment_64_2);
}

int fn_R000877_7713_15(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int index_reg_61 = (aux + st.buffer[1]) & 3;
  switch (index_reg_61)
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

  int weight_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_18) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_64 = local_arr[aux % 3];
  acc = (acc + (segment_64 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000877_7713_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st_1 = {0};
  struct Transaction_R000877_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int index_reg_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_56_1)
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

  switch (index_reg_56_2)
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

  int anchor_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_11_1) & 63;
  aux_2 = (aux_2 + anchor_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_56_1 = local_arr_1[aux_1 % 3];
  int margin_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_56_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_56_1 == index_reg_56_2);
  assert(anchor_11_1 == anchor_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_56_1 == margin_56_2);
}

int fn_R000877_7713_16(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int index_reg_56 = (aux + st.buffer[1]) & 3;
  switch (index_reg_56)
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

  int anchor_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_11) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_56 = local_arr[aux % 3];
  acc = (acc + (margin_56 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000877_7713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st_1 = {0};
  struct Transaction_R000877_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int residue_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_27_1 > 22)
  {
    acc_1 = ((acc_1 + (residue_27_1 * 2)) + 5) & 127;
    aux_1 ^= residue_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_27_2 > 22)
  {
    acc_2 = ((acc_2 + (residue_27_2 * 2)) + 5) & 127;
    aux_2 ^= residue_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_27_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_68_1) & 63;
  aux_2 = (aux_2 + index_reg_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_27_1 == residue_27_2);
  assert(index_reg_68_1 == index_reg_68_2);
}

int fn_R000877_7713_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int residue_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_27 > 22)
  {
    acc = ((acc + (residue_27 * 2)) + 5) & 127;
    aux ^= residue_27 & 15;
  }
  else
  {
    acc = ((acc - residue_27) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_68) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000877_7713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st_1 = {0};
  struct Transaction_R000877_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_94_1 > 15)
  {
    acc_1 = ((acc_1 + (accumulator_94_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_94_2 > 15)
  {
    acc_2 = ((acc_2 + (accumulator_94_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_45_1 = local_arr_1[aux_1 % 3];
  int checksum_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_45_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_94_1 == accumulator_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_45_1 == checksum_45_2);
}

int fn_R000877_7713_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000877_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_94 > 15)
  {
    acc = ((acc + (accumulator_94 * 2)) + 5) & 127;
    aux ^= accumulator_94 & 15;
  }
  else
  {
    acc = ((acc - accumulator_94) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_45 = local_arr[aux % 3];
  acc = (acc + (checksum_45 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000877_7713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000877_7713_0 st_1 = {0};
  struct SensorNode_R000877_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_77_1 > 18)
  {
    acc_1 = ((acc_1 + (coefficient_77_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_77_2 > 18)
  {
    acc_2 = ((acc_2 + (coefficient_77_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_90_1 = local_arr_1[aux_1 % 3];
  int coefficient_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_90_2 * 2)) & 127;
  int parity_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_34_1)
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

  switch (parity_34_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_77_1 == coefficient_77_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_90_1 == coefficient_90_2);
  assert(parity_34_1 == parity_34_2);
}

int fn_R000877_7713_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000877_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_77 > 18)
  {
    acc = ((acc + (coefficient_77 * 2)) + 5) & 127;
    aux ^= coefficient_77 & 15;
  }
  else
  {
    acc = ((acc - coefficient_77) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int coefficient_90 = local_arr[aux % 3];
  acc = (acc + (coefficient_90 * 2)) & 127;
  int parity_34 = (aux + st.buffer[1]) & 3;
  switch (parity_34)
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

void main()
{
  int sec_r000877_0_1;
  int sec_r000877_0_2;
  int sec_r000877_1_1;
  int sec_r000877_1_2;
  int sec_r000877_2_1;
  int sec_r000877_2_2;
  int sec_r000877_3_1;
  int sec_r000877_3_2;
  int sec_r000877_4_1;
  int sec_r000877_4_2;
  int sec_r000877_5_1;
  int sec_r000877_5_2;
  int sec_r000877_6_1;
  int sec_r000877_6_2;
  int sec_r000877_7_1;
  int sec_r000877_7_2;
  int sec_r000877_8_1;
  int sec_r000877_8_2;
  int sec_r000877_9_1;
  int sec_r000877_9_2;
  int sec_r000877_10_1;
  int sec_r000877_10_2;
  int sec_r000877_11_1;
  int sec_r000877_11_2;
  int sec_r000877_12_1;
  int sec_r000877_12_2;
  int sec_r000877_13_1;
  int sec_r000877_13_2;
  int sec_r000877_14_1;
  int sec_r000877_14_2;
  int sec_r000877_15_1;
  int sec_r000877_15_2;
  int sec_r000877_16_1;
  int sec_r000877_16_2;
  int sec_r000877_17_1;
  int sec_r000877_17_2;
  int sec_r000877_18_1;
  int sec_r000877_18_2;
  int pub_r000877_0_1;
  int pub_r000877_0_2;
  int pub_r000877_1_1;
  int pub_r000877_1_2;
  int pub_r000877_2_1;
  int pub_r000877_2_2;
  int pub_r000877_3_1;
  int pub_r000877_3_2;
  int pub_r000877_4_1;
  int pub_r000877_4_2;
  int pub_r000877_5_1;
  int pub_r000877_5_2;
  int pub_r000877_6_1;
  int pub_r000877_6_2;
  int pub_r000877_7_1;
  int pub_r000877_7_2;
  int pub_r000877_8_1;
  int pub_r000877_8_2;
  int pub_r000877_9_1;
  int pub_r000877_9_2;
  int pub_r000877_10_1;
  int pub_r000877_10_2;
  int pub_r000877_11_1;
  int pub_r000877_11_2;
  int pub_r000877_12_1;
  int pub_r000877_12_2;
  int pub_r000877_13_1;
  int pub_r000877_13_2;
  int pub_r000877_14_1;
  int pub_r000877_14_2;
  int pub_r000877_15_1;
  int pub_r000877_15_2;
  int pub_r000877_16_1;
  int pub_r000877_16_2;
  int pub_r000877_17_1;
  int pub_r000877_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000877_0_1 >= (-100)) && (pub_r000877_0_1 <= 100));
  __CPROVER_assume((pub_r000877_0_2 >= (-100)) && (pub_r000877_0_2 <= 100));
  __CPROVER_assume((pub_r000877_1_1 >= (-100)) && (pub_r000877_1_1 <= 100));
  __CPROVER_assume((pub_r000877_1_2 >= (-100)) && (pub_r000877_1_2 <= 100));
  __CPROVER_assume((pub_r000877_2_1 >= (-100)) && (pub_r000877_2_1 <= 100));
  __CPROVER_assume((pub_r000877_2_2 >= (-100)) && (pub_r000877_2_2 <= 100));
  __CPROVER_assume((pub_r000877_3_1 >= (-100)) && (pub_r000877_3_1 <= 100));
  __CPROVER_assume((pub_r000877_3_2 >= (-100)) && (pub_r000877_3_2 <= 100));
  __CPROVER_assume((pub_r000877_4_1 >= (-100)) && (pub_r000877_4_1 <= 100));
  __CPROVER_assume((pub_r000877_4_2 >= (-100)) && (pub_r000877_4_2 <= 100));
  __CPROVER_assume((pub_r000877_5_1 >= (-100)) && (pub_r000877_5_1 <= 100));
  __CPROVER_assume((pub_r000877_5_2 >= (-100)) && (pub_r000877_5_2 <= 100));
  __CPROVER_assume((pub_r000877_6_1 >= (-100)) && (pub_r000877_6_1 <= 100));
  __CPROVER_assume((pub_r000877_6_2 >= (-100)) && (pub_r000877_6_2 <= 100));
  __CPROVER_assume((pub_r000877_7_1 >= (-100)) && (pub_r000877_7_1 <= 100));
  __CPROVER_assume((pub_r000877_7_2 >= (-100)) && (pub_r000877_7_2 <= 100));
  __CPROVER_assume((pub_r000877_8_1 >= (-100)) && (pub_r000877_8_1 <= 100));
  __CPROVER_assume((pub_r000877_8_2 >= (-100)) && (pub_r000877_8_2 <= 100));
  __CPROVER_assume((pub_r000877_9_1 >= (-100)) && (pub_r000877_9_1 <= 100));
  __CPROVER_assume((pub_r000877_9_2 >= (-100)) && (pub_r000877_9_2 <= 100));
  __CPROVER_assume((pub_r000877_10_1 >= (-100)) && (pub_r000877_10_1 <= 100));
  __CPROVER_assume((pub_r000877_10_2 >= (-100)) && (pub_r000877_10_2 <= 100));
  __CPROVER_assume((pub_r000877_11_1 >= (-100)) && (pub_r000877_11_1 <= 100));
  __CPROVER_assume((pub_r000877_11_2 >= (-100)) && (pub_r000877_11_2 <= 100));
  __CPROVER_assume((pub_r000877_12_1 >= (-100)) && (pub_r000877_12_1 <= 100));
  __CPROVER_assume((pub_r000877_12_2 >= (-100)) && (pub_r000877_12_2 <= 100));
  __CPROVER_assume((pub_r000877_13_1 >= (-100)) && (pub_r000877_13_1 <= 100));
  __CPROVER_assume((pub_r000877_13_2 >= (-100)) && (pub_r000877_13_2 <= 100));
  __CPROVER_assume((pub_r000877_14_1 >= (-100)) && (pub_r000877_14_1 <= 100));
  __CPROVER_assume((pub_r000877_14_2 >= (-100)) && (pub_r000877_14_2 <= 100));
  __CPROVER_assume((pub_r000877_15_1 >= (-100)) && (pub_r000877_15_1 <= 100));
  __CPROVER_assume((pub_r000877_15_2 >= (-100)) && (pub_r000877_15_2 <= 100));
  __CPROVER_assume((pub_r000877_16_1 >= (-100)) && (pub_r000877_16_1 <= 100));
  __CPROVER_assume((pub_r000877_16_2 >= (-100)) && (pub_r000877_16_2 <= 100));
  __CPROVER_assume((pub_r000877_17_1 >= (-100)) && (pub_r000877_17_1 <= 100));
  __CPROVER_assume((pub_r000877_17_2 >= (-100)) && (pub_r000877_17_2 <= 100));
  __CPROVER_assume((sec_r000877_0_1 >= 0) && (sec_r000877_0_1 <= 255));
  __CPROVER_assume((sec_r000877_0_2 >= 0) && (sec_r000877_0_2 <= 255));
  __CPROVER_assume((sec_r000877_1_1 >= 0) && (sec_r000877_1_1 <= 255));
  __CPROVER_assume((sec_r000877_1_2 >= 0) && (sec_r000877_1_2 <= 255));
  __CPROVER_assume((sec_r000877_2_1 >= 0) && (sec_r000877_2_1 <= 255));
  __CPROVER_assume((sec_r000877_2_2 >= 0) && (sec_r000877_2_2 <= 255));
  __CPROVER_assume((sec_r000877_3_1 >= 0) && (sec_r000877_3_1 <= 255));
  __CPROVER_assume((sec_r000877_3_2 >= 0) && (sec_r000877_3_2 <= 255));
  __CPROVER_assume((sec_r000877_4_1 >= 0) && (sec_r000877_4_1 <= 255));
  __CPROVER_assume((sec_r000877_4_2 >= 0) && (sec_r000877_4_2 <= 255));
  __CPROVER_assume((sec_r000877_5_1 >= 0) && (sec_r000877_5_1 <= 255));
  __CPROVER_assume((sec_r000877_5_2 >= 0) && (sec_r000877_5_2 <= 255));
  __CPROVER_assume((sec_r000877_6_1 >= 0) && (sec_r000877_6_1 <= 255));
  __CPROVER_assume((sec_r000877_6_2 >= 0) && (sec_r000877_6_2 <= 255));
  __CPROVER_assume((sec_r000877_7_1 >= 0) && (sec_r000877_7_1 <= 255));
  __CPROVER_assume((sec_r000877_7_2 >= 0) && (sec_r000877_7_2 <= 255));
  __CPROVER_assume((sec_r000877_8_1 >= 0) && (sec_r000877_8_1 <= 255));
  __CPROVER_assume((sec_r000877_8_2 >= 0) && (sec_r000877_8_2 <= 255));
  __CPROVER_assume((sec_r000877_9_1 >= 0) && (sec_r000877_9_1 <= 255));
  __CPROVER_assume((sec_r000877_9_2 >= 0) && (sec_r000877_9_2 <= 255));
  __CPROVER_assume((sec_r000877_10_1 >= 0) && (sec_r000877_10_1 <= 255));
  __CPROVER_assume((sec_r000877_10_2 >= 0) && (sec_r000877_10_2 <= 255));
  __CPROVER_assume((sec_r000877_11_1 >= 0) && (sec_r000877_11_1 <= 255));
  __CPROVER_assume((sec_r000877_11_2 >= 0) && (sec_r000877_11_2 <= 255));
  __CPROVER_assume((sec_r000877_12_1 >= 0) && (sec_r000877_12_1 <= 255));
  __CPROVER_assume((sec_r000877_12_2 >= 0) && (sec_r000877_12_2 <= 255));
  __CPROVER_assume((sec_r000877_13_1 >= 0) && (sec_r000877_13_1 <= 255));
  __CPROVER_assume((sec_r000877_13_2 >= 0) && (sec_r000877_13_2 <= 255));
  __CPROVER_assume((sec_r000877_14_1 >= 0) && (sec_r000877_14_1 <= 255));
  __CPROVER_assume((sec_r000877_14_2 >= 0) && (sec_r000877_14_2 <= 255));
  __CPROVER_assume((sec_r000877_15_1 >= 0) && (sec_r000877_15_1 <= 255));
  __CPROVER_assume((sec_r000877_15_2 >= 0) && (sec_r000877_15_2 <= 255));
  __CPROVER_assume((sec_r000877_16_1 >= 0) && (sec_r000877_16_1 <= 255));
  __CPROVER_assume((sec_r000877_16_2 >= 0) && (sec_r000877_16_2 <= 255));
  __CPROVER_assume((sec_r000877_17_1 >= 0) && (sec_r000877_17_1 <= 255));
  __CPROVER_assume((sec_r000877_17_2 >= 0) && (sec_r000877_17_2 <= 255));
  __CPROVER_assume((sec_r000877_18_1 >= 0) && (sec_r000877_18_1 <= 255));
  __CPROVER_assume((sec_r000877_18_2 >= 0) && (sec_r000877_18_2 <= 255));
  struct SensorNode_R000877_7713_0 st_var_0_1 = {0};
  struct SensorNode_R000877_7713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000877_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000877_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000877_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000877_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000877_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000877_0_2 + 7) & 15;
  struct Transaction_R000877_7713_1 st_var_1_1 = {0};
  struct Transaction_R000877_7713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000877_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000877_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000877_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000877_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000877_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000877_0_2 + 9) & 15;
  union ColorPixel_R000877_7713_0 u_var_1;
  union ColorPixel_R000877_7713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (5 & 31);
  int stage_v_0_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (5 & 31);
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= (stage_v_0_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_0_2 << 1) & 127;
  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_2_1 = 0;
  int stage_v_2_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_2_1 = ((stage_v_2_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_2_2 = ((stage_v_2_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = 0;
  int stage_v_3_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_3_1 = ((stage_v_3_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_3_2 = ((stage_v_3_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 42)
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
  if (stage_v_4_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 42)
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
  int stage_v_5_1 = ((st_var_1_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_1_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 52)
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
  if (stage_v_5_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 52)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 7) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  int stage_v_10_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_10_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_10_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_10_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_11_1 = ((st_var_1_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_1_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 32)
    {
      chk_sum_1 ^= stage_v_11_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_11_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 32)
    {
      chk_sum_2 ^= stage_v_11_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 38)
    {
      chk_sum_1 ^= stage_v_12_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_12_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 38)
    {
      chk_sum_2 ^= stage_v_12_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_13_1 = table_1[1];
  int stage_v_13_2 = table_2[1];
  table_1[1] = (table_1[2] + 27) & 63;
  table_2[1] = (table_2[2] + 27) & 63;
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
  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_17_1 = ((stage_v_17_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_17_2 = ((stage_v_17_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (st_var_0_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_0_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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
  int stage_v_20_1 = (st_var_0_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_0_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_23_1 = table_1[3];
  int stage_v_23_2 = table_2[3];
  table_1[3] = (table_1[0] + 47) & 63;
  table_2[3] = (table_2[0] + 47) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_24_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
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

  switch (stage_v_25_2)
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

  int stage_v_26_1 = (st_var_0_1.buffer[0] ^ 29) & 3;
  int stage_v_26_2 = (st_var_0_2.buffer[0] ^ 29) & 3;
  switch (stage_v_26_1)
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

  switch (stage_v_26_2)
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

  int stage_v_27_1 = table_1[3];
  int stage_v_27_2 = table_2[3];
  table_1[3] = (table_1[0] + 55) & 63;
  table_2[3] = (table_2[0] + 55) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_28_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_29_1 = ((st_var_1_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_1_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 39)
    {
      chk_sum_1 ^= stage_v_29_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_29_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 39)
    {
      chk_sum_2 ^= stage_v_29_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 31) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_32_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_32_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_32_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_32_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_33_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (38 & 31);
  int stage_v_33_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (38 & 31);
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= (stage_v_33_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_33_2 << 1) & 127;
  int stage_v_34_1 = ((st_var_0_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_0_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 47)
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
  if (stage_v_34_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 47)
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
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((st_var_0_1.buffer[0] * 2) + 115) & 63;
  int stage_v_36_2 = ((st_var_0_2.buffer[0] * 2) + 115) & 63;
  if (stage_v_36_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 36)
    {
      chk_sum_1 ^= stage_v_36_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_36_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 36)
    {
      chk_sum_2 ^= stage_v_36_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_37_1 = ((stage_v_37_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_37_2 = ((stage_v_37_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (st_var_0_1.buffer[0] ^ 41) & 3;
  int stage_v_38_2 = (st_var_0_2.buffer[0] ^ 41) & 3;
  switch (stage_v_38_1)
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

  switch (stage_v_38_2)
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

  int stage_v_39_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (44 & 31);
  int stage_v_39_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (44 & 31);
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= (stage_v_39_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_39_2 << 1) & 127;
  int stage_v_40_1 = (st_var_0_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_0_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_42_1 = (st_var_0_1.buffer[0] ^ 45) & 3;
  int stage_v_42_2 = (st_var_0_2.buffer[0] ^ 45) & 3;
  switch (stage_v_42_1)
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

  switch (stage_v_42_2)
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

  int stage_v_43_1 = (st_var_1_1.buffer[0] ^ 46) & 3;
  int stage_v_43_2 = (st_var_1_2.buffer[0] ^ 46) & 3;
  switch (stage_v_43_1)
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

  switch (stage_v_43_2)
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

  int stage_v_44_1 = ((st_var_0_1.buffer[2] * 2) + 139) & 63;
  int stage_v_44_2 = ((st_var_0_2.buffer[2] * 2) + 139) & 63;
  if (stage_v_44_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_44_1) - 5) & 255;
    if (stage_v_44_1 > 32)
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
  if (stage_v_44_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_44_2) - 5) & 255;
    if (stage_v_44_2 > 32)
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
  int stage_v_45_1 = table_1[1];
  int stage_v_45_2 = table_2[1];
  table_1[1] = (table_1[2] + 91) & 63;
  table_2[1] = (table_2[2] + 91) & 63;
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
  int stage_v_47_1 = (st_var_1_1.buffer[0] ^ 50) & 3;
  int stage_v_47_2 = (st_var_1_2.buffer[0] ^ 50) & 3;
  switch (stage_v_47_1)
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

  switch (stage_v_47_2)
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

  int stage_v_48_1 = table_1[0];
  int stage_v_48_2 = table_2[0];
  table_1[0] = (table_1[1] + 97) & 63;
  table_2[0] = (table_2[1] + 97) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 51) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 51) & 15;
  int stage_v_50_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_50_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= stage_v_50_1;
  chk_sum_2 ^= stage_v_50_2;
  int stage_v_51_1 = table_1[3];
  int stage_v_51_2 = table_2[3];
  table_1[3] = (table_1[0] + 103) & 63;
  table_2[3] = (table_2[0] + 103) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_52_1 = ((stage_v_52_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = table_1[1];
  int stage_v_53_2 = table_2[1];
  table_1[1] = (table_1[2] + 107) & 63;
  table_2[1] = (table_2[2] + 107) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((st_var_0_1.buffer[0] * 2) + 169) & 63;
  int stage_v_54_2 = ((st_var_0_2.buffer[0] * 2) + 169) & 63;
  if (stage_v_54_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_54_1) - 5) & 255;
    if (stage_v_54_1 > 38)
    {
      chk_sum_1 ^= stage_v_54_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_54_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_54_2) - 5) & 255;
    if (stage_v_54_2 > 38)
    {
      chk_sum_2 ^= stage_v_54_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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

  int stage_v_57_1 = ((st_var_1_1.buffer[0] * 2) + 178) & 63;
  int stage_v_57_2 = ((st_var_1_2.buffer[0] * 2) + 178) & 63;
  if (stage_v_57_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_57_1) - 5) & 255;
    if (stage_v_57_1 > 46)
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
  if (stage_v_57_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_57_2) - 5) & 255;
    if (stage_v_57_2 > 46)
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
  int stage_v_58_1 = ((st_var_0_1.buffer[1] * 2) + 181) & 63;
  int stage_v_58_2 = ((st_var_0_2.buffer[1] * 2) + 181) & 63;
  if (stage_v_58_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_58_1) - 5) & 255;
    if (stage_v_58_1 > 40)
    {
      chk_sum_1 ^= stage_v_58_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_58_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_58_2) - 5) & 255;
    if (stage_v_58_2 > 40)
    {
      chk_sum_2 ^= stage_v_58_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_59_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (64 & 31);
  int stage_v_59_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (64 & 31);
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= (stage_v_59_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_59_2 << 1) & 127;
  int stage_v_60_1 = table_1[0];
  int stage_v_60_2 = table_2[0];
  table_1[0] = (table_1[1] + 121) & 63;
  table_2[0] = (table_2[1] + 121) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((st_var_1_1.buffer[1] * 2) + 190) & 63;
  int stage_v_61_2 = ((st_var_1_2.buffer[1] * 2) + 190) & 63;
  if (stage_v_61_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_61_1) - 5) & 255;
    if (stage_v_61_1 > 39)
    {
      chk_sum_1 ^= stage_v_61_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_61_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_61_2) - 5) & 255;
    if (stage_v_61_2 > 39)
    {
      chk_sum_2 ^= stage_v_61_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 63) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 63) & 15;
  int stage_v_62_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_62_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= stage_v_62_1;
  chk_sum_2 ^= stage_v_62_2;
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
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 66) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 66) & 15;
  int stage_v_65_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_65_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= stage_v_65_1;
  chk_sum_2 ^= stage_v_65_2;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_66_1 = ((stage_v_66_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_66_2 = ((stage_v_66_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (st_var_1_1.buffer[0] ^ 70) & 3;
  int stage_v_67_2 = (st_var_1_2.buffer[0] ^ 70) & 3;
  switch (stage_v_67_1)
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

  switch (stage_v_67_2)
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

  int stage_v_68_1 = table_1[0];
  int stage_v_68_2 = table_2[0];
  table_1[0] = (table_1[1] + 137) & 63;
  table_2[0] = (table_2[1] + 137) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((st_var_1_1.buffer[0] * 2) + 214) & 63;
  int stage_v_69_2 = ((st_var_1_2.buffer[0] * 2) + 214) & 63;
  if (stage_v_69_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_69_1) - 5) & 255;
    if (stage_v_69_1 > 29)
    {
      chk_sum_1 ^= stage_v_69_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_69_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_69_2) - 5) & 255;
    if (stage_v_69_2 > 29)
    {
      chk_sum_2 ^= stage_v_69_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_70_1 = (st_var_0_1.buffer[0] ^ 73) & 3;
  int stage_v_70_2 = (st_var_0_2.buffer[0] ^ 73) & 3;
  switch (stage_v_70_1)
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

  switch (stage_v_70_2)
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

  int stage_v_71_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_71_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_72_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (77 & 31);
  int stage_v_72_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (77 & 31);
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  chk_sum_1 ^= (stage_v_72_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_72_2 << 1) & 127;
  int stage_v_73_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_73_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_74_1 = table_1[2];
  int stage_v_74_2 = table_2[2];
  table_1[2] = (table_1[3] + 149) & 63;
  table_2[2] = (table_2[3] + 149) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((st_var_1_1.buffer[0] * 2) + 232) & 63;
  int stage_v_75_2 = ((st_var_1_2.buffer[0] * 2) + 232) & 63;
  if (stage_v_75_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_75_1) - 5) & 255;
    if (stage_v_75_1 > 43)
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
  if (stage_v_75_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_75_2) - 5) & 255;
    if (stage_v_75_2 > 43)
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

  int stage_v_77_1 = (st_var_1_1.buffer[0] ^ 80) & 3;
  int stage_v_77_2 = (st_var_1_2.buffer[0] ^ 80) & 3;
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

  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_78_1 = ((stage_v_78_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_78_2 = ((stage_v_78_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (84 & 31);
  int stage_v_79_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (84 & 31);
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  chk_sum_1 ^= (stage_v_79_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_79_2 << 1) & 127;
  int stage_v_80_1 = table_1[0];
  int stage_v_80_2 = table_2[0];
  table_1[0] = (table_1[1] + 161) & 63;
  table_2[0] = (table_2[1] + 161) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_81_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_81_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_81_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_82_1 = (st_var_0_1.buffer[0] ^ 85) & 3;
  int stage_v_82_2 = (st_var_0_2.buffer[0] ^ 85) & 3;
  switch (stage_v_82_1)
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

  switch (stage_v_82_2)
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

  int stage_v_83_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_83_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_83_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_83_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_84_1 = (st_var_0_1.buffer[0] ^ 87) & 3;
  int stage_v_84_2 = (st_var_0_2.buffer[0] ^ 87) & 3;
  switch (stage_v_84_1)
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

  switch (stage_v_84_2)
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

  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((sec_r000877_10_1 & 1) != 0)
  {
    if ((sec_r000877_12_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000877_6_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000877_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000877_6_1 + 7) & 127;
  }
  if ((sec_r000877_10_2 & 1) != 0)
  {
    if ((sec_r000877_12_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000877_6_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000877_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000877_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000877_2_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000877_2_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000877_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000877_2_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000877_2_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000877_2_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000877_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000877_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((sec_r000877_17_1 & 1) != 0)
  {
    if ((sec_r000877_16_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000877_8_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000877_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000877_8_1 + 7) & 127;
  }
  if ((sec_r000877_17_2 & 1) != 0)
  {
    if ((sec_r000877_16_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000877_8_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000877_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000877_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000877_6_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000877_8_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000877_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000877_8_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000877_6_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000877_8_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000877_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000877_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000877_16_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000877_9_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000877_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000877_9_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000877_16_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000877_9_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000877_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000877_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000877_17_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000877_0_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000877_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000877_0_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000877_17_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000877_0_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000877_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000877_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000877_12_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000877_1_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000877_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000877_1_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000877_12_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000877_1_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000877_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000877_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000877_7_1 & 1) != 0)
  {
    if ((sec_r000877_15_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000877_12_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000877_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000877_12_1 + 7) & 127;
  }
  if ((sec_r000877_7_2 & 1) != 0)
  {
    if ((sec_r000877_15_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000877_12_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000877_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000877_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000877_0_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000877_5_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000877_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000877_5_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000877_0_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000877_5_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000877_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000877_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000877_15_1 & 1) != 0)
  {
    if ((sec_r000877_8_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000877_17_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000877_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000877_17_1 + 7) & 127;
  }
  if ((sec_r000877_15_2 & 1) != 0)
  {
    if ((sec_r000877_8_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000877_17_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000877_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000877_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000877_0_1 & 1) != 0)
  {
    if ((sec_r000877_2_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000877_14_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000877_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000877_14_1 + 7) & 127;
  }
  if ((sec_r000877_0_2 & 1) != 0)
  {
    if ((sec_r000877_2_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000877_14_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000877_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000877_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000877_12_1 & 1) != 0)
  {
    if ((sec_r000877_4_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000877_12_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000877_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000877_12_1 + 7) & 127;
  }
  if ((sec_r000877_12_2 & 1) != 0)
  {
    if ((sec_r000877_4_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000877_12_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000877_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000877_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000877_3_1 & 1) != 0)
  {
    if ((sec_r000877_2_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000877_14_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000877_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000877_14_1 + 7) & 127;
  }
  if ((sec_r000877_3_2 & 1) != 0)
  {
    if ((sec_r000877_2_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000877_14_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000877_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000877_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000877_8_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000877_17_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000877_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000877_17_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000877_8_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000877_17_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000877_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000877_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000877_1_1 & 1) != 0)
  {
    if ((sec_r000877_12_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000877_3_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000877_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000877_3_1 + 7) & 127;
  }
  if ((sec_r000877_1_2 & 1) != 0)
  {
    if ((sec_r000877_12_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000877_3_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000877_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000877_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000877_6_1 & 1) != 0)
  {
    if ((sec_r000877_14_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000877_7_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000877_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000877_7_1 + 7) & 127;
  }
  if ((sec_r000877_6_2 & 1) != 0)
  {
    if ((sec_r000877_14_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000877_7_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000877_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000877_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000877_13_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000877_8_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000877_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000877_8_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000877_13_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000877_8_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000877_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000877_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000877_11_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000877_13_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000877_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000877_13_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000877_11_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000877_13_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000877_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000877_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000877_9_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000877_13_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000877_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000877_13_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000877_9_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000877_13_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000877_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000877_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000877_12_1 & 1) != 0)
  {
    if ((sec_r000877_14_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000877_11_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000877_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000877_11_1 + 7) & 127;
  }
  if ((sec_r000877_12_2 & 1) != 0)
  {
    if ((sec_r000877_14_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000877_11_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000877_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000877_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000877_17_1 & 1) != 0)
  {
    if ((sec_r000877_5_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000877_8_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000877_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000877_8_1 + 7) & 127;
  }
  if ((sec_r000877_17_2 & 1) != 0)
  {
    if ((sec_r000877_5_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000877_8_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000877_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000877_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000877_15_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000877_14_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000877_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000877_14_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000877_15_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000877_14_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000877_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000877_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000877_1_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000877_6_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000877_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000877_6_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000877_1_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000877_6_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000877_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000877_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((sec_r000877_7_1 & 1) != 0)
  {
    if ((sec_r000877_9_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000877_14_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000877_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000877_14_1 + 7) & 127;
  }
  if ((sec_r000877_7_2 & 1) != 0)
  {
    if ((sec_r000877_9_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000877_14_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000877_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000877_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((sec_r000877_17_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000877_3_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000877_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000877_3_1 + 7) & 127;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((sec_r000877_17_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000877_3_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000877_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000877_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000877_18_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000877_8_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000877_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000877_8_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000877_18_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000877_8_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000877_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000877_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000877_12_1 & 1) != 0)
  {
    if ((sec_r000877_6_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000877_12_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000877_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000877_12_1 + 7) & 127;
  }
  if ((sec_r000877_12_2 & 1) != 0)
  {
    if ((sec_r000877_6_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000877_12_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000877_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000877_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000877_2_1 & 1) != 0)
  {
    if ((sec_r000877_16_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000877_12_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000877_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000877_12_1 + 7) & 127;
  }
  if ((sec_r000877_2_2 & 1) != 0)
  {
    if ((sec_r000877_16_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000877_12_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000877_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000877_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000877_15_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000877_12_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000877_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000877_12_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000877_15_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000877_12_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000877_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000877_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000877_7_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000877_15_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000877_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000877_15_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000877_7_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000877_15_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000877_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000877_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000877_9_1 & 1) != 0)
  {
    if ((sec_r000877_16_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000877_16_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000877_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000877_16_1 + 7) & 127;
  }
  if ((sec_r000877_9_2 & 1) != 0)
  {
    if ((sec_r000877_16_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000877_16_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000877_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000877_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000877_10_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000877_8_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000877_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000877_8_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000877_10_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000877_8_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000877_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000877_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000877_7_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000877_3_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000877_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000877_3_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000877_7_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000877_3_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000877_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000877_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000877_2_1 & 1) != 0)
  {
    if ((sec_r000877_7_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000877_6_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000877_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000877_6_1 + 7) & 127;
  }
  if ((sec_r000877_2_2 & 1) != 0)
  {
    if ((sec_r000877_7_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000877_6_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000877_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000877_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000877_0_1 & 1) != 0)
  {
    if ((sec_r000877_2_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000877_11_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000877_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000877_11_1 + 7) & 127;
  }
  if ((sec_r000877_0_2 & 1) != 0)
  {
    if ((sec_r000877_2_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000877_11_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000877_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000877_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000877_3_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000877_4_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000877_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000877_4_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000877_3_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000877_4_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000877_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000877_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000877_10_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000877_0_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000877_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000877_0_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000877_10_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000877_0_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000877_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000877_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000877_11_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000877_6_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000877_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000877_6_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000877_11_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000877_6_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000877_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000877_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000877_7_1 & 1) != 0)
  {
    if ((sec_r000877_5_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000877_0_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000877_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000877_0_1 + 7) & 127;
  }
  if ((sec_r000877_7_2 & 1) != 0)
  {
    if ((sec_r000877_5_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000877_0_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000877_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000877_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000877_17_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000877_11_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000877_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000877_11_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000877_17_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000877_11_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000877_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000877_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000877_11_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000877_6_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000877_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000877_6_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000877_11_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000877_6_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000877_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000877_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000877_15_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000877_6_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000877_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000877_6_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000877_15_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000877_6_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000877_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000877_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000877_11_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000877_4_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000877_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000877_4_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000877_11_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000877_4_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000877_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000877_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((sec_r000877_13_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000877_10_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000877_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000877_10_1 + 7) & 127;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((sec_r000877_13_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000877_10_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000877_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000877_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000877_8_1 & 1) != 0)
  {
    if ((sec_r000877_9_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000877_1_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000877_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000877_1_1 + 7) & 127;
  }
  if ((sec_r000877_8_2 & 1) != 0)
  {
    if ((sec_r000877_9_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000877_1_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000877_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000877_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000877_12_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000877_7_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000877_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000877_7_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000877_12_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000877_7_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000877_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000877_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_130_1 & 1) != 0)
  {
    if ((sec_r000877_12_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000877_13_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000877_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000877_13_1 + 7) & 127;
  }
  if ((stage_v_130_2 & 1) != 0)
  {
    if ((sec_r000877_12_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000877_13_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000877_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000877_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000877_3_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000877_4_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000877_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000877_4_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000877_3_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000877_4_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000877_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000877_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000877_11_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000877_16_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000877_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000877_16_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000877_11_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000877_16_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000877_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000877_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000877_8_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000877_2_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000877_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000877_2_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000877_8_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000877_2_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000877_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000877_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000877_3_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000877_10_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000877_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000877_10_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000877_3_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000877_10_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000877_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000877_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000877_17_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000877_1_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000877_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000877_1_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000877_17_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000877_1_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000877_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000877_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((sec_r000877_0_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000877_3_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000877_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000877_3_1 + 7) & 127;
  }
  if ((stage_v_134_2 & 1) != 0)
  {
    if ((sec_r000877_0_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000877_3_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000877_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000877_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((sec_r000877_8_1 & 1) != 0)
  {
    if ((sec_r000877_1_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000877_10_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000877_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000877_10_1 + 7) & 127;
  }
  if ((sec_r000877_8_2 & 1) != 0)
  {
    if ((sec_r000877_1_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000877_10_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000877_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000877_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_129_1 & 1) != 0)
  {
    if ((sec_r000877_16_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000877_9_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000877_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000877_9_1 + 7) & 127;
  }
  if ((stage_v_129_2 & 1) != 0)
  {
    if ((sec_r000877_16_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000877_9_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000877_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000877_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000877_9_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000877_11_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000877_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000877_11_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000877_9_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000877_11_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000877_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000877_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((sec_r000877_15_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000877_7_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000877_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000877_7_1 + 7) & 127;
  }
  if ((stage_v_121_2 & 1) != 0)
  {
    if ((sec_r000877_15_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000877_7_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000877_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000877_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000877_3_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000877_16_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000877_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000877_16_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000877_3_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000877_16_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000877_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000877_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((sec_r000877_1_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000877_15_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000877_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000877_15_1 + 7) & 127;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((sec_r000877_1_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000877_15_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000877_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000877_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((sec_r000877_10_1 & 1) != 0)
  {
    if ((sec_r000877_6_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000877_13_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000877_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000877_13_1 + 7) & 127;
  }
  if ((sec_r000877_10_2 & 1) != 0)
  {
    if ((sec_r000877_6_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000877_13_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000877_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000877_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((sec_r000877_16_1 & 1) != 0)
  {
    if ((sec_r000877_12_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000877_9_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000877_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000877_9_1 + 7) & 127;
  }
  if ((sec_r000877_16_2 & 1) != 0)
  {
    if ((sec_r000877_12_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000877_9_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000877_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000877_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((sec_r000877_4_1 & 1) != 0)
  {
    if ((sec_r000877_7_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000877_1_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000877_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000877_1_1 + 7) & 127;
  }
  if ((sec_r000877_4_2 & 1) != 0)
  {
    if ((sec_r000877_7_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000877_1_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000877_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000877_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000877_4_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000877_10_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000877_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000877_10_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000877_4_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000877_10_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000877_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000877_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000877_10_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000877_5_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000877_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000877_5_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000877_10_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000877_5_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000877_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000877_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r000877_16_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000877_6_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000877_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000877_6_1 + 7) & 127;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r000877_16_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000877_6_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000877_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000877_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((sec_r000877_7_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000877_10_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000877_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000877_10_1 + 7) & 127;
  }
  if ((stage_v_140_2 & 1) != 0)
  {
    if ((sec_r000877_7_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000877_10_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000877_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000877_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((sec_r000877_0_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000877_0_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000877_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000877_0_1 + 7) & 127;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((sec_r000877_0_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000877_0_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000877_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000877_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((sec_r000877_2_1 & 1) != 0)
  {
    if ((sec_r000877_12_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000877_7_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000877_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000877_7_1 + 7) & 127;
  }
  if ((sec_r000877_2_2 & 1) != 0)
  {
    if ((sec_r000877_12_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000877_7_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000877_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000877_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_129_1 & 1) != 0)
  {
    if ((sec_r000877_17_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000877_1_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000877_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000877_1_1 + 7) & 127;
  }
  if ((stage_v_129_2 & 1) != 0)
  {
    if ((sec_r000877_17_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000877_1_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000877_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000877_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((sec_r000877_12_1 & 1) != 0)
  {
    if ((sec_r000877_16_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000877_16_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000877_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000877_16_1 + 7) & 127;
  }
  if ((sec_r000877_12_2 & 1) != 0)
  {
    if ((sec_r000877_16_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000877_16_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000877_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000877_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000877_5_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000877_13_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000877_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000877_13_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000877_5_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000877_13_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000877_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000877_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000877_3_1 & 2) != 0)
    {
      stage_v_156_1 = (pub_r000877_6_1 + 31) & 127;
    }
    else
    {
      stage_v_156_1 = (pub_r000877_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_1 = (pub_r000877_6_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000877_3_2 & 2) != 0)
    {
      stage_v_156_2 = (pub_r000877_6_2 + 31) & 127;
    }
    else
    {
      stage_v_156_2 = (pub_r000877_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_156_2 = (pub_r000877_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((sec_r000877_16_1 & 2) != 0)
    {
      stage_v_157_1 = (pub_r000877_9_1 + 31) & 127;
    }
    else
    {
      stage_v_157_1 = (pub_r000877_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_1 = (pub_r000877_9_1 + 7) & 127;
  }
  if ((stage_v_138_2 & 1) != 0)
  {
    if ((sec_r000877_16_2 & 2) != 0)
    {
      stage_v_157_2 = (pub_r000877_9_2 + 31) & 127;
    }
    else
    {
      stage_v_157_2 = (pub_r000877_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_157_2 = (pub_r000877_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  if ((sec_r000877_7_1 & 1) != 0)
  {
    if ((sec_r000877_7_1 & 2) != 0)
    {
      stage_v_158_1 = (pub_r000877_10_1 + 31) & 127;
    }
    else
    {
      stage_v_158_1 = (pub_r000877_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_1 = (pub_r000877_10_1 + 7) & 127;
  }
  if ((sec_r000877_7_2 & 1) != 0)
  {
    if ((sec_r000877_7_2 & 2) != 0)
    {
      stage_v_158_2 = (pub_r000877_10_2 + 31) & 127;
    }
    else
    {
      stage_v_158_2 = (pub_r000877_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_158_2 = (pub_r000877_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  if ((sec_r000877_0_1 & 1) != 0)
  {
    if ((sec_r000877_13_1 & 2) != 0)
    {
      stage_v_159_1 = (pub_r000877_9_1 + 31) & 127;
    }
    else
    {
      stage_v_159_1 = (pub_r000877_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_1 = (pub_r000877_9_1 + 7) & 127;
  }
  if ((sec_r000877_0_2 & 1) != 0)
  {
    if ((sec_r000877_13_2 & 2) != 0)
    {
      stage_v_159_2 = (pub_r000877_9_2 + 31) & 127;
    }
    else
    {
      stage_v_159_2 = (pub_r000877_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_159_2 = (pub_r000877_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  if ((sec_r000877_15_1 & 1) != 0)
  {
    if ((sec_r000877_0_1 & 2) != 0)
    {
      stage_v_160_1 = (pub_r000877_11_1 + 31) & 127;
    }
    else
    {
      stage_v_160_1 = (pub_r000877_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_1 = (pub_r000877_11_1 + 7) & 127;
  }
  if ((sec_r000877_15_2 & 1) != 0)
  {
    if ((sec_r000877_0_2 & 2) != 0)
    {
      stage_v_160_2 = (pub_r000877_11_2 + 31) & 127;
    }
    else
    {
      stage_v_160_2 = (pub_r000877_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_160_2 = (pub_r000877_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  if ((stage_v_141_1 & 1) != 0)
  {
    if ((sec_r000877_1_1 & 2) != 0)
    {
      stage_v_161_1 = (pub_r000877_14_1 + 31) & 127;
    }
    else
    {
      stage_v_161_1 = (pub_r000877_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_1 = (pub_r000877_14_1 + 7) & 127;
  }
  if ((stage_v_141_2 & 1) != 0)
  {
    if ((sec_r000877_1_2 & 2) != 0)
    {
      stage_v_161_2 = (pub_r000877_14_2 + 31) & 127;
    }
    else
    {
      stage_v_161_2 = (pub_r000877_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_161_2 = (pub_r000877_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((sec_r000877_0_1 & 2) != 0)
    {
      stage_v_162_1 = (pub_r000877_8_1 + 31) & 127;
    }
    else
    {
      stage_v_162_1 = (pub_r000877_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_1 = (pub_r000877_8_1 + 7) & 127;
  }
  if ((stage_v_134_2 & 1) != 0)
  {
    if ((sec_r000877_0_2 & 2) != 0)
    {
      stage_v_162_2 = (pub_r000877_8_2 + 31) & 127;
    }
    else
    {
      stage_v_162_2 = (pub_r000877_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_162_2 = (pub_r000877_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  if ((sec_r000877_4_1 & 1) != 0)
  {
    if ((sec_r000877_5_1 & 2) != 0)
    {
      stage_v_163_1 = (pub_r000877_0_1 + 31) & 127;
    }
    else
    {
      stage_v_163_1 = (pub_r000877_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_1 = (pub_r000877_0_1 + 7) & 127;
  }
  if ((sec_r000877_4_2 & 1) != 0)
  {
    if ((sec_r000877_5_2 & 2) != 0)
    {
      stage_v_163_2 = (pub_r000877_0_2 + 31) & 127;
    }
    else
    {
      stage_v_163_2 = (pub_r000877_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_163_2 = (pub_r000877_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  if ((stage_v_161_1 & 1) != 0)
  {
    if ((sec_r000877_10_1 & 2) != 0)
    {
      stage_v_164_1 = (pub_r000877_13_1 + 31) & 127;
    }
    else
    {
      stage_v_164_1 = (pub_r000877_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_1 = (pub_r000877_13_1 + 7) & 127;
  }
  if ((stage_v_161_2 & 1) != 0)
  {
    if ((sec_r000877_10_2 & 2) != 0)
    {
      stage_v_164_2 = (pub_r000877_13_2 + 31) & 127;
    }
    else
    {
      stage_v_164_2 = (pub_r000877_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_164_2 = (pub_r000877_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  if ((sec_r000877_10_1 & 1) != 0)
  {
    if ((sec_r000877_16_1 & 2) != 0)
    {
      stage_v_165_1 = (pub_r000877_14_1 + 31) & 127;
    }
    else
    {
      stage_v_165_1 = (pub_r000877_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_1 = (pub_r000877_14_1 + 7) & 127;
  }
  if ((sec_r000877_10_2 & 1) != 0)
  {
    if ((sec_r000877_16_2 & 2) != 0)
    {
      stage_v_165_2 = (pub_r000877_14_2 + 31) & 127;
    }
    else
    {
      stage_v_165_2 = (pub_r000877_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_165_2 = (pub_r000877_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000877_5_1 == pub_r000877_5_2);
  __CPROVER_assume(sec_r000877_13_1 != sec_r000877_13_2);
  __CPROVER_assume(sec_r000877_14_1 != sec_r000877_14_2);
  __CPROVER_assume(pub_r000877_1_1 == pub_r000877_1_2);
  __CPROVER_assume(sec_r000877_10_1 != sec_r000877_10_2);
  __CPROVER_assume(sec_r000877_12_1 != sec_r000877_12_2);
  __CPROVER_assume(sec_r000877_17_1 != sec_r000877_17_2);
  __CPROVER_assume(pub_r000877_9_1 == pub_r000877_9_2);
  __CPROVER_assume(sec_r000877_15_1 != sec_r000877_15_2);
  __CPROVER_assume(pub_r000877_2_1 == pub_r000877_2_2);
  __CPROVER_assume(pub_r000877_12_1 == pub_r000877_12_2);
  __CPROVER_assume(pub_r000877_13_1 == pub_r000877_13_2);
  __CPROVER_assume(sec_r000877_9_1 != sec_r000877_9_2);
  __CPROVER_assume(sec_r000877_2_1 != sec_r000877_2_2);
  __CPROVER_assume(pub_r000877_11_1 == pub_r000877_11_2);
  __CPROVER_assume(pub_r000877_7_1 == pub_r000877_7_2);
  __CPROVER_assume(pub_r000877_6_1 == pub_r000877_6_2);
  __CPROVER_assume(sec_r000877_7_1 != sec_r000877_7_2);
  __CPROVER_assume(pub_r000877_16_1 == pub_r000877_16_2);
  __CPROVER_assume(pub_r000877_8_1 == pub_r000877_8_2);
  __CPROVER_assume(sec_r000877_16_1 != sec_r000877_16_2);
  __CPROVER_assume(pub_r000877_3_1 == pub_r000877_3_2);
  __CPROVER_assume(pub_r000877_0_1 == pub_r000877_0_2);
  __CPROVER_assume(sec_r000877_5_1 != sec_r000877_5_2);
  __CPROVER_assume(sec_r000877_0_1 != sec_r000877_0_2);
  __CPROVER_assume(pub_r000877_15_1 == pub_r000877_15_2);
  __CPROVER_assume(sec_r000877_8_1 != sec_r000877_8_2);
  __CPROVER_assume(sec_r000877_11_1 != sec_r000877_11_2);
  __CPROVER_assume(pub_r000877_14_1 == pub_r000877_14_2);
  __CPROVER_assume(pub_r000877_10_1 == pub_r000877_10_2);
  __CPROVER_assume(sec_r000877_1_1 != sec_r000877_1_2);
  __CPROVER_assume(pub_r000877_17_1 == pub_r000877_17_2);
  __CPROVER_assume(pub_r000877_4_1 == pub_r000877_4_2);
  __CPROVER_assume(sec_r000877_18_1 != sec_r000877_18_2);
  __CPROVER_assume(sec_r000877_3_1 != sec_r000877_3_2);
  __CPROVER_assume(sec_r000877_6_1 != sec_r000877_6_2);
  __CPROVER_assume(sec_r000877_4_1 != sec_r000877_4_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.account_id == st_var_1_2.account_id);
  assert(st_var_1_1.fee == st_var_1_2.fee);
  assert(st_var_1_1.rate == st_var_1_2.rate);
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
  assert(stage_v_165_1 == stage_v_165_2);
}


