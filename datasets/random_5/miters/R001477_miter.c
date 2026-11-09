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
struct SensorNode_R001477_7713_0
{
  int threshold;
  int status;
  short offset;
  int buffer[3];
};
struct CipherContext_R001477_7713_1
{
  short nonce;
  int iv;
  short flags;
  int buffer[3];
};
union ColorPixel_R001477_7713_0
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
void fn_R001477_7713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st_1 = {0};
  struct CipherContext_R001477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int offset_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_60_1 > 13)
  {
    acc_1 = ((acc_1 + (offset_60_1 * 2)) + 5) & 127;
    aux_1 ^= offset_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_60_2 > 13)
  {
    acc_2 = ((acc_2 + (offset_60_2 * 2)) + 5) & 127;
    aux_2 ^= offset_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_37_1)
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

  switch (parity_37_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_60_1 == offset_60_2);
  assert(parity_37_1 == parity_37_2);
}

int fn_R001477_7713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int offset_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_60 > 13)
  {
    acc = ((acc + (offset_60 * 2)) + 5) & 127;
    aux ^= offset_60 & 15;
  }
  else
  {
    acc = ((acc - offset_60) + 11) & 127;
    aux += 3;
  }
  int parity_37 = (aux + st.buffer[1]) & 3;
  switch (parity_37)
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

void fn_R001477_7713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st_1 = {0};
  struct SensorNode_R001477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int quotient_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_31_1) & 63;
  aux_2 = (aux_2 + quotient_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_10_1 = local_arr_1[aux_1 % 3];
  int stride_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_10_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_31_1 == quotient_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_10_1 == stride_10_2);
}

int fn_R001477_7713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int quotient_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_31) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_10 = local_arr[aux % 3];
  acc = (acc + (stride_10 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001477_7713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st_1 = {0};
  struct SensorNode_R001477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int offset_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_96_1 > 34)
  {
    acc_1 = ((acc_1 + (offset_96_1 * 2)) + 5) & 127;
    aux_1 ^= offset_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_96_2 > 34)
  {
    acc_2 = ((acc_2 + (offset_96_2 * 2)) + 5) & 127;
    aux_2 ^= offset_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_45_1 = 0;
  int metric_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_45_1 = ((metric_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_45_2 = ((metric_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_45_1) & 127;
    acc_2 = (acc_2 + metric_45_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_71_1 = local_arr_1[aux_1 % 3];
  int metric_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_71_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_96_1 == offset_96_2);
  assert(metric_45_1 == metric_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_71_1 == metric_71_2);
}

int fn_R001477_7713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int offset_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_96 > 34)
  {
    acc = ((acc + (offset_96 * 2)) + 5) & 127;
    aux ^= offset_96 & 15;
  }
  else
  {
    acc = ((acc - offset_96) + 11) & 127;
    aux += 3;
  }
  int metric_45 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_45 = ((metric_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_45) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int metric_71 = local_arr[aux % 3];
  acc = (acc + (metric_71 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001477_7713_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st_1 = {0};
  struct SensorNode_R001477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int anchor_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_86_1) & 63;
  aux_2 = (aux_2 + anchor_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_66_1 > 37)
  {
    acc_1 = ((acc_1 + (weight_66_1 * 2)) + 5) & 127;
    aux_1 ^= weight_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_66_2 > 37)
  {
    acc_2 = ((acc_2 + (weight_66_2 * 2)) + 5) & 127;
    aux_2 ^= weight_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_66_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_86_1 == anchor_86_2);
  assert(weight_66_1 == weight_66_2);
}

int fn_R001477_7713_3(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int anchor_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_86) & 63;
  acc ^= aux;
  int weight_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_66 > 37)
  {
    acc = ((acc + (weight_66 * 2)) + 5) & 127;
    aux ^= weight_66 & 15;
  }
  else
  {
    acc = ((acc - weight_66) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001477_7713_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st_1 = {0};
  struct CipherContext_R001477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_24_1 = local_arr_1[aux_1 % 3];
  int metric_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_24_2 * 2)) & 127;
  int tracker_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_70_1 > 14)
  {
    acc_1 = ((acc_1 + (tracker_70_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_70_2 > 14)
  {
    acc_2 = ((acc_2 + (tracker_70_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_70_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
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

  assert(metric_24_1 == metric_24_2);
  assert(tracker_70_1 == tracker_70_2);
}

int fn_R001477_7713_4(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int metric_24 = local_arr[aux % 3];
  acc = (acc + (metric_24 * 2)) & 127;
  int tracker_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_70 > 14)
  {
    acc = ((acc + (tracker_70 * 2)) + 5) & 127;
    aux ^= tracker_70 & 15;
  }
  else
  {
    acc = ((acc - tracker_70) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001477_7713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st_1 = {0};
  struct SensorNode_R001477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int mask_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_89_1)
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

  switch (mask_89_2)
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

  int pivot_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_26_1) & 63;
  aux_2 = (aux_2 + pivot_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_89_1 == mask_89_2);
  assert(pivot_26_1 == pivot_26_2);
}

int fn_R001477_7713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int mask_89 = (aux + st.buffer[1]) & 3;
  switch (mask_89)
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

  int pivot_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_26) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001477_7713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st_1 = {0};
  struct CipherContext_R001477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_34_1 = 0;
  int mask_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_34_1 = ((mask_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_34_2 = ((mask_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_34_1) & 127;
    acc_2 = (acc_2 + mask_34_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_34_1 == mask_34_2);
}

int fn_R001477_7713_6(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_34 = ((mask_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_34) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001477_7713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st_1 = {0};
  struct SensorNode_R001477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int window_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_32_1) & 63;
  aux_2 = (aux_2 + window_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_62_1 = 0;
  int coefficient_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_62_1 = ((coefficient_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_62_2 = ((coefficient_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_62_1) & 127;
    acc_2 = (acc_2 + coefficient_62_2) & 127;
  }

  int scale_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_73_1 > 37)
  {
    acc_1 = ((acc_1 + (scale_73_1 * 2)) + 5) & 127;
    aux_1 ^= scale_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_73_2 > 37)
  {
    acc_2 = ((acc_2 + (scale_73_2 * 2)) + 5) & 127;
    aux_2 ^= scale_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_73_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_32_1 == window_32_2);
  assert(coefficient_62_1 == coefficient_62_2);
  assert(scale_73_1 == scale_73_2);
}

int fn_R001477_7713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int window_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_32) & 63;
  acc ^= aux;
  int coefficient_62 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_62 = ((coefficient_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_62) & 127;
  }

  int scale_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_73 > 37)
  {
    acc = ((acc + (scale_73 * 2)) + 5) & 127;
    aux ^= scale_73 & 15;
  }
  else
  {
    acc = ((acc - scale_73) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001477_7713_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st_1 = {0};
  struct CipherContext_R001477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_79_1 = local_arr_1[aux_1 % 3];
  int accumulator_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_79_2 * 2)) & 127;
  int vector_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_61_1 > 13)
  {
    acc_1 = ((acc_1 + (vector_61_1 * 2)) + 5) & 127;
    aux_1 ^= vector_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_61_2 > 13)
  {
    acc_2 = ((acc_2 + (vector_61_2 * 2)) + 5) & 127;
    aux_2 ^= vector_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_93_1)
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

  switch (anchor_93_2)
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
  assert(st_1.nonce == st_2.nonce);
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

  assert(accumulator_79_1 == accumulator_79_2);
  assert(vector_61_1 == vector_61_2);
  assert(anchor_93_1 == anchor_93_2);
}

int fn_R001477_7713_8(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int accumulator_79 = local_arr[aux % 3];
  acc = (acc + (accumulator_79 * 2)) & 127;
  int vector_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_61 > 13)
  {
    acc = ((acc + (vector_61 * 2)) + 5) & 127;
    aux ^= vector_61 & 15;
  }
  else
  {
    acc = ((acc - vector_61) + 11) & 127;
    aux += 3;
  }
  int anchor_93 = (aux + st.buffer[1]) & 3;
  switch (anchor_93)
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

void fn_R001477_7713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st_1 = {0};
  struct SensorNode_R001477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int coefficient_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_25_1) & 63;
  aux_2 = (aux_2 + coefficient_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_42_1 = 0;
  int metric_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_42_1 = ((metric_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_42_2 = ((metric_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_42_1) & 127;
    acc_2 = (acc_2 + metric_42_2) & 127;
  }

  int coefficient_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_37_1)
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

  switch (coefficient_37_2)
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

  int accumulator_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_85_1 > 12)
  {
    acc_1 = ((acc_1 + (accumulator_85_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_85_2 > 12)
  {
    acc_2 = ((acc_2 + (accumulator_85_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_85_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_25_1 == coefficient_25_2);
  assert(metric_42_1 == metric_42_2);
  assert(coefficient_37_1 == coefficient_37_2);
  assert(accumulator_85_1 == accumulator_85_2);
}

int fn_R001477_7713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int coefficient_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_25) & 63;
  acc ^= aux;
  int metric_42 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_42 = ((metric_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_42) & 127;
  }

  int coefficient_37 = (aux + st.buffer[1]) & 3;
  switch (coefficient_37)
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

  int accumulator_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_85 > 12)
  {
    acc = ((acc + (accumulator_85 * 2)) + 5) & 127;
    aux ^= accumulator_85 & 15;
  }
  else
  {
    acc = ((acc - accumulator_85) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001477_7713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st_1 = {0};
  struct CipherContext_R001477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int checksum_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_70_1) & 63;
  aux_2 = (aux_2 + checksum_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_57_1)
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

  switch (accumulator_57_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_70_1 == checksum_70_2);
  assert(accumulator_57_1 == accumulator_57_2);
}

int fn_R001477_7713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int checksum_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_70) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_57 = (aux + st.buffer[1]) & 3;
  switch (accumulator_57)
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

void fn_R001477_7713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st_1 = {0};
  struct CipherContext_R001477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int index_reg_37_1 = 0;
  int index_reg_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_37_1 = ((index_reg_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_37_2 = ((index_reg_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_37_1) & 127;
    acc_2 = (acc_2 + index_reg_37_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_94_1 = local_arr_1[aux_1 % 3];
  int stride_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_94_2 * 2)) & 127;
  int threshold_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_16_1)
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

  switch (threshold_16_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_37_1 == index_reg_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_94_1 == stride_94_2);
  assert(threshold_16_1 == threshold_16_2);
}

int fn_R001477_7713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int index_reg_37 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_37 = ((index_reg_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_37) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int stride_94 = local_arr[aux % 3];
  acc = (acc + (stride_94 * 2)) & 127;
  int threshold_16 = (aux + st.buffer[1]) & 3;
  switch (threshold_16)
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

void fn_R001477_7713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st_1 = {0};
  struct CipherContext_R001477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int phase_42_1 = 0;
  int phase_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_42_1 = ((phase_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_42_2 = ((phase_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_42_1) & 127;
    acc_2 = (acc_2 + phase_42_2) & 127;
  }

  int threshold_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_89_1)
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

  switch (threshold_89_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_42_1 == phase_42_2);
  assert(threshold_89_1 == threshold_89_2);
}

int fn_R001477_7713_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int phase_42 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_42 = ((phase_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_42) & 127;
  }

  int threshold_89 = (aux + st.buffer[1]) & 3;
  switch (threshold_89)
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

void fn_R001477_7713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st_1 = {0};
  struct SensorNode_R001477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int pivot_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_21_1)
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

  switch (pivot_21_2)
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
  int residue_70_1 = local_arr_1[aux_1 % 3];
  int residue_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_70_2 * 2)) & 127;
  int sample_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_48_1) & 63;
  aux_2 = (aux_2 + sample_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_21_1 == pivot_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_70_1 == residue_70_2);
  assert(sample_48_1 == sample_48_2);
}

int fn_R001477_7713_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int pivot_21 = (aux + st.buffer[1]) & 3;
  switch (pivot_21)
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
  int residue_70 = local_arr[aux % 3];
  acc = (acc + (residue_70 * 2)) & 127;
  int sample_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_48) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001477_7713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st_1 = {0};
  struct SensorNode_R001477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int cursor_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_68_1) & 63;
  aux_2 = (aux_2 + cursor_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_52_1)
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

  switch (vector_52_2)
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

  int scale_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_18_1 > 43)
  {
    acc_1 = ((acc_1 + (scale_18_1 * 2)) + 5) & 127;
    aux_1 ^= scale_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_18_2 > 43)
  {
    acc_2 = ((acc_2 + (scale_18_2 * 2)) + 5) & 127;
    aux_2 ^= scale_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_18_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_68_1 == cursor_68_2);
  assert(vector_52_1 == vector_52_2);
  assert(scale_18_1 == scale_18_2);
}

int fn_R001477_7713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int cursor_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_68) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_52 = (aux + st.buffer[1]) & 3;
  switch (vector_52)
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

  int scale_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_18 > 43)
  {
    acc = ((acc + (scale_18 * 2)) + 5) & 127;
    aux ^= scale_18 & 15;
  }
  else
  {
    acc = ((acc - scale_18) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001477_7713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st_1 = {0};
  struct SensorNode_R001477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int offset_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_45_1) & 63;
  aux_2 = (aux_2 + offset_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_86_1 = 0;
  int stride_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_86_1 = ((stride_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_86_2 = ((stride_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_86_1) & 127;
    acc_2 = (acc_2 + stride_86_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_45_1 == offset_45_2);
  assert(stride_86_1 == stride_86_2);
}

int fn_R001477_7713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int offset_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_45) & 63;
  acc ^= aux;
  int stride_86 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_86 = ((stride_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_86) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001477_7713_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st_1 = {0};
  struct SensorNode_R001477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int stride_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_90_1)
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

  switch (stride_90_2)
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

  int margin_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_96_1) & 63;
  aux_2 = (aux_2 + margin_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_90_1 == stride_90_2);
  assert(margin_96_1 == margin_96_2);
}

int fn_R001477_7713_16(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int stride_90 = (aux + st.buffer[1]) & 3;
  switch (stride_90)
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

  int margin_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001477_7713_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st_1 = {0};
  struct CipherContext_R001477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int offset_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_60_1 > 26)
  {
    acc_1 = ((acc_1 + (offset_60_1 * 2)) + 5) & 127;
    aux_1 ^= offset_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_60_2 > 26)
  {
    acc_2 = ((acc_2 + (offset_60_2 * 2)) + 5) & 127;
    aux_2 ^= offset_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_60_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_60_1 == offset_60_2);
}

int fn_R001477_7713_17(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int offset_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_60 > 26)
  {
    acc = ((acc + (offset_60 * 2)) + 5) & 127;
    aux ^= offset_60 & 15;
  }
  else
  {
    acc = ((acc - offset_60) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001477_7713_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st_1 = {0};
  struct CipherContext_R001477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int mask_24_1 = 0;
  int mask_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_24_1 = ((mask_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_24_2 = ((mask_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_24_1) & 127;
    acc_2 = (acc_2 + mask_24_2) & 127;
  }

  int threshold_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_87_1) & 63;
  aux_2 = (aux_2 + threshold_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_11_1 > 27)
  {
    acc_1 = ((acc_1 + (tally_11_1 * 2)) + 5) & 127;
    aux_1 ^= tally_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_11_2 > 27)
  {
    acc_2 = ((acc_2 + (tally_11_2 * 2)) + 5) & 127;
    aux_2 ^= tally_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_11_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_24_1 == mask_24_2);
  assert(threshold_87_1 == threshold_87_2);
  assert(tally_11_1 == tally_11_2);
}

int fn_R001477_7713_18(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int mask_24 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_24 = ((mask_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_24) & 127;
  }

  int threshold_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_87) & 63;
  acc ^= aux;
  int tally_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_11 > 27)
  {
    acc = ((acc + (tally_11 * 2)) + 5) & 127;
    aux ^= tally_11 & 15;
  }
  else
  {
    acc = ((acc - tally_11) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001477_7713_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st_1 = {0};
  struct SensorNode_R001477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int anchor_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_44_1 > 16)
  {
    acc_1 = ((acc_1 + (anchor_44_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_44_2 > 16)
  {
    acc_2 = ((acc_2 + (anchor_44_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_21_1 = 0;
  int damping_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_21_1 = ((damping_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_21_2 = ((damping_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_21_1) & 127;
    acc_2 = (acc_2 + damping_21_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_44_1 == anchor_44_2);
  assert(damping_21_1 == damping_21_2);
}

int fn_R001477_7713_19(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int anchor_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_44 > 16)
  {
    acc = ((acc + (anchor_44 * 2)) + 5) & 127;
    aux ^= anchor_44 & 15;
  }
  else
  {
    acc = ((acc - anchor_44) + 11) & 127;
    aux += 3;
  }
  int damping_21 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_21 = ((damping_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_21) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001477_7713_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st_1 = {0};
  struct CipherContext_R001477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int accumulator_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_75_1) & 63;
  aux_2 = (aux_2 + accumulator_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_66_1 = 0;
  int weight_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_66_1 = ((weight_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_66_2 = ((weight_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_66_1) & 127;
    acc_2 = (acc_2 + weight_66_2) & 127;
  }

  int coefficient_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_90_1 > 28)
  {
    acc_1 = ((acc_1 + (coefficient_90_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_90_2 > 28)
  {
    acc_2 = ((acc_2 + (coefficient_90_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_90_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_75_1 == accumulator_75_2);
  assert(weight_66_1 == weight_66_2);
  assert(coefficient_90_1 == coefficient_90_2);
}

int fn_R001477_7713_20(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int accumulator_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_75) & 63;
  acc ^= aux;
  int weight_66 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_66 = ((weight_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_66) & 127;
  }

  int coefficient_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_90 > 28)
  {
    acc = ((acc + (coefficient_90 * 2)) + 5) & 127;
    aux ^= coefficient_90 & 15;
  }
  else
  {
    acc = ((acc - coefficient_90) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001477_7713_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st_1 = {0};
  struct CipherContext_R001477_7713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int factor_20_1 = 0;
  int factor_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_20_1 = ((factor_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_20_2 = ((factor_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_20_1) & 127;
    acc_2 = (acc_2 + factor_20_2) & 127;
  }

  int quotient_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_64_1)
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

  switch (quotient_64_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_20_1 == factor_20_2);
  assert(quotient_64_1 == quotient_64_2);
}

int fn_R001477_7713_21(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001477_7713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int factor_20 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_20 = ((factor_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_20) & 127;
  }

  int quotient_64 = (aux + st.buffer[1]) & 3;
  switch (quotient_64)
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

void fn_R001477_7713_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st_1 = {0};
  struct SensorNode_R001477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_60_1 = local_arr_1[aux_1 % 3];
  int accumulator_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_60_2 * 2)) & 127;
  int threshold_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_34_1) & 63;
  aux_2 = (aux_2 + threshold_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_60_1 == accumulator_60_2);
  assert(threshold_34_1 == threshold_34_2);
}

int fn_R001477_7713_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int accumulator_60 = local_arr[aux % 3];
  acc = (acc + (accumulator_60 * 2)) & 127;
  int threshold_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_34) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001477_7713_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st_1 = {0};
  struct SensorNode_R001477_7713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int factor_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_31_1) & 63;
  aux_2 = (aux_2 + factor_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_35_1 = 0;
  int accumulator_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_35_1 = ((accumulator_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_35_2 = ((accumulator_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_35_1) & 127;
    acc_2 = (acc_2 + accumulator_35_2) & 127;
  }

  int quantum_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_96_1 > 42)
  {
    acc_1 = ((acc_1 + (quantum_96_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_96_2 > 42)
  {
    acc_2 = ((acc_2 + (quantum_96_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_96_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_31_1 == factor_31_2);
  assert(accumulator_35_1 == accumulator_35_2);
  assert(quantum_96_1 == quantum_96_2);
}

int fn_R001477_7713_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001477_7713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int factor_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_31) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_35 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_35 = ((accumulator_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_35) & 127;
  }

  int quantum_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_96 > 42)
  {
    acc = ((acc + (quantum_96 * 2)) + 5) & 127;
    aux ^= quantum_96 & 15;
  }
  else
  {
    acc = ((acc - quantum_96) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001477_0_1;
  int sec_r001477_0_2;
  int sec_r001477_1_1;
  int sec_r001477_1_2;
  int sec_r001477_2_1;
  int sec_r001477_2_2;
  int sec_r001477_3_1;
  int sec_r001477_3_2;
  int sec_r001477_4_1;
  int sec_r001477_4_2;
  int sec_r001477_5_1;
  int sec_r001477_5_2;
  int sec_r001477_6_1;
  int sec_r001477_6_2;
  int sec_r001477_7_1;
  int sec_r001477_7_2;
  int sec_r001477_8_1;
  int sec_r001477_8_2;
  int sec_r001477_9_1;
  int sec_r001477_9_2;
  int sec_r001477_10_1;
  int sec_r001477_10_2;
  int sec_r001477_11_1;
  int sec_r001477_11_2;
  int sec_r001477_12_1;
  int sec_r001477_12_2;
  int sec_r001477_13_1;
  int sec_r001477_13_2;
  int sec_r001477_14_1;
  int sec_r001477_14_2;
  int sec_r001477_15_1;
  int sec_r001477_15_2;
  int sec_r001477_16_1;
  int sec_r001477_16_2;
  int sec_r001477_17_1;
  int sec_r001477_17_2;
  int pub_r001477_0_1;
  int pub_r001477_0_2;
  int pub_r001477_1_1;
  int pub_r001477_1_2;
  int pub_r001477_2_1;
  int pub_r001477_2_2;
  int pub_r001477_3_1;
  int pub_r001477_3_2;
  int pub_r001477_4_1;
  int pub_r001477_4_2;
  int pub_r001477_5_1;
  int pub_r001477_5_2;
  int pub_r001477_6_1;
  int pub_r001477_6_2;
  int pub_r001477_7_1;
  int pub_r001477_7_2;
  int pub_r001477_8_1;
  int pub_r001477_8_2;
  int pub_r001477_9_1;
  int pub_r001477_9_2;
  int pub_r001477_10_1;
  int pub_r001477_10_2;
  int pub_r001477_11_1;
  int pub_r001477_11_2;
  int pub_r001477_12_1;
  int pub_r001477_12_2;
  int pub_r001477_13_1;
  int pub_r001477_13_2;
  int pub_r001477_14_1;
  int pub_r001477_14_2;
  int pub_r001477_15_1;
  int pub_r001477_15_2;
  int pub_r001477_16_1;
  int pub_r001477_16_2;
  int pub_r001477_17_1;
  int pub_r001477_17_2;
  int pub_r001477_18_1;
  int pub_r001477_18_2;
  int pub_r001477_19_1;
  int pub_r001477_19_2;
  int pub_r001477_20_1;
  int pub_r001477_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001477_0_1 >= (-100)) && (pub_r001477_0_1 <= 100));
  __CPROVER_assume((pub_r001477_0_2 >= (-100)) && (pub_r001477_0_2 <= 100));
  __CPROVER_assume((pub_r001477_1_1 >= (-100)) && (pub_r001477_1_1 <= 100));
  __CPROVER_assume((pub_r001477_1_2 >= (-100)) && (pub_r001477_1_2 <= 100));
  __CPROVER_assume((pub_r001477_2_1 >= (-100)) && (pub_r001477_2_1 <= 100));
  __CPROVER_assume((pub_r001477_2_2 >= (-100)) && (pub_r001477_2_2 <= 100));
  __CPROVER_assume((pub_r001477_3_1 >= (-100)) && (pub_r001477_3_1 <= 100));
  __CPROVER_assume((pub_r001477_3_2 >= (-100)) && (pub_r001477_3_2 <= 100));
  __CPROVER_assume((pub_r001477_4_1 >= (-100)) && (pub_r001477_4_1 <= 100));
  __CPROVER_assume((pub_r001477_4_2 >= (-100)) && (pub_r001477_4_2 <= 100));
  __CPROVER_assume((pub_r001477_5_1 >= (-100)) && (pub_r001477_5_1 <= 100));
  __CPROVER_assume((pub_r001477_5_2 >= (-100)) && (pub_r001477_5_2 <= 100));
  __CPROVER_assume((pub_r001477_6_1 >= (-100)) && (pub_r001477_6_1 <= 100));
  __CPROVER_assume((pub_r001477_6_2 >= (-100)) && (pub_r001477_6_2 <= 100));
  __CPROVER_assume((pub_r001477_7_1 >= (-100)) && (pub_r001477_7_1 <= 100));
  __CPROVER_assume((pub_r001477_7_2 >= (-100)) && (pub_r001477_7_2 <= 100));
  __CPROVER_assume((pub_r001477_8_1 >= (-100)) && (pub_r001477_8_1 <= 100));
  __CPROVER_assume((pub_r001477_8_2 >= (-100)) && (pub_r001477_8_2 <= 100));
  __CPROVER_assume((pub_r001477_9_1 >= (-100)) && (pub_r001477_9_1 <= 100));
  __CPROVER_assume((pub_r001477_9_2 >= (-100)) && (pub_r001477_9_2 <= 100));
  __CPROVER_assume((pub_r001477_10_1 >= (-100)) && (pub_r001477_10_1 <= 100));
  __CPROVER_assume((pub_r001477_10_2 >= (-100)) && (pub_r001477_10_2 <= 100));
  __CPROVER_assume((pub_r001477_11_1 >= (-100)) && (pub_r001477_11_1 <= 100));
  __CPROVER_assume((pub_r001477_11_2 >= (-100)) && (pub_r001477_11_2 <= 100));
  __CPROVER_assume((pub_r001477_12_1 >= (-100)) && (pub_r001477_12_1 <= 100));
  __CPROVER_assume((pub_r001477_12_2 >= (-100)) && (pub_r001477_12_2 <= 100));
  __CPROVER_assume((pub_r001477_13_1 >= (-100)) && (pub_r001477_13_1 <= 100));
  __CPROVER_assume((pub_r001477_13_2 >= (-100)) && (pub_r001477_13_2 <= 100));
  __CPROVER_assume((pub_r001477_14_1 >= (-100)) && (pub_r001477_14_1 <= 100));
  __CPROVER_assume((pub_r001477_14_2 >= (-100)) && (pub_r001477_14_2 <= 100));
  __CPROVER_assume((pub_r001477_15_1 >= (-100)) && (pub_r001477_15_1 <= 100));
  __CPROVER_assume((pub_r001477_15_2 >= (-100)) && (pub_r001477_15_2 <= 100));
  __CPROVER_assume((pub_r001477_16_1 >= (-100)) && (pub_r001477_16_1 <= 100));
  __CPROVER_assume((pub_r001477_16_2 >= (-100)) && (pub_r001477_16_2 <= 100));
  __CPROVER_assume((pub_r001477_17_1 >= (-100)) && (pub_r001477_17_1 <= 100));
  __CPROVER_assume((pub_r001477_17_2 >= (-100)) && (pub_r001477_17_2 <= 100));
  __CPROVER_assume((pub_r001477_18_1 >= (-100)) && (pub_r001477_18_1 <= 100));
  __CPROVER_assume((pub_r001477_18_2 >= (-100)) && (pub_r001477_18_2 <= 100));
  __CPROVER_assume((pub_r001477_19_1 >= (-100)) && (pub_r001477_19_1 <= 100));
  __CPROVER_assume((pub_r001477_19_2 >= (-100)) && (pub_r001477_19_2 <= 100));
  __CPROVER_assume((pub_r001477_20_1 >= (-100)) && (pub_r001477_20_1 <= 100));
  __CPROVER_assume((pub_r001477_20_2 >= (-100)) && (pub_r001477_20_2 <= 100));
  __CPROVER_assume((sec_r001477_0_1 >= 0) && (sec_r001477_0_1 <= 255));
  __CPROVER_assume((sec_r001477_0_2 >= 0) && (sec_r001477_0_2 <= 255));
  __CPROVER_assume((sec_r001477_1_1 >= 0) && (sec_r001477_1_1 <= 255));
  __CPROVER_assume((sec_r001477_1_2 >= 0) && (sec_r001477_1_2 <= 255));
  __CPROVER_assume((sec_r001477_2_1 >= 0) && (sec_r001477_2_1 <= 255));
  __CPROVER_assume((sec_r001477_2_2 >= 0) && (sec_r001477_2_2 <= 255));
  __CPROVER_assume((sec_r001477_3_1 >= 0) && (sec_r001477_3_1 <= 255));
  __CPROVER_assume((sec_r001477_3_2 >= 0) && (sec_r001477_3_2 <= 255));
  __CPROVER_assume((sec_r001477_4_1 >= 0) && (sec_r001477_4_1 <= 255));
  __CPROVER_assume((sec_r001477_4_2 >= 0) && (sec_r001477_4_2 <= 255));
  __CPROVER_assume((sec_r001477_5_1 >= 0) && (sec_r001477_5_1 <= 255));
  __CPROVER_assume((sec_r001477_5_2 >= 0) && (sec_r001477_5_2 <= 255));
  __CPROVER_assume((sec_r001477_6_1 >= 0) && (sec_r001477_6_1 <= 255));
  __CPROVER_assume((sec_r001477_6_2 >= 0) && (sec_r001477_6_2 <= 255));
  __CPROVER_assume((sec_r001477_7_1 >= 0) && (sec_r001477_7_1 <= 255));
  __CPROVER_assume((sec_r001477_7_2 >= 0) && (sec_r001477_7_2 <= 255));
  __CPROVER_assume((sec_r001477_8_1 >= 0) && (sec_r001477_8_1 <= 255));
  __CPROVER_assume((sec_r001477_8_2 >= 0) && (sec_r001477_8_2 <= 255));
  __CPROVER_assume((sec_r001477_9_1 >= 0) && (sec_r001477_9_1 <= 255));
  __CPROVER_assume((sec_r001477_9_2 >= 0) && (sec_r001477_9_2 <= 255));
  __CPROVER_assume((sec_r001477_10_1 >= 0) && (sec_r001477_10_1 <= 255));
  __CPROVER_assume((sec_r001477_10_2 >= 0) && (sec_r001477_10_2 <= 255));
  __CPROVER_assume((sec_r001477_11_1 >= 0) && (sec_r001477_11_1 <= 255));
  __CPROVER_assume((sec_r001477_11_2 >= 0) && (sec_r001477_11_2 <= 255));
  __CPROVER_assume((sec_r001477_12_1 >= 0) && (sec_r001477_12_1 <= 255));
  __CPROVER_assume((sec_r001477_12_2 >= 0) && (sec_r001477_12_2 <= 255));
  __CPROVER_assume((sec_r001477_13_1 >= 0) && (sec_r001477_13_1 <= 255));
  __CPROVER_assume((sec_r001477_13_2 >= 0) && (sec_r001477_13_2 <= 255));
  __CPROVER_assume((sec_r001477_14_1 >= 0) && (sec_r001477_14_1 <= 255));
  __CPROVER_assume((sec_r001477_14_2 >= 0) && (sec_r001477_14_2 <= 255));
  __CPROVER_assume((sec_r001477_15_1 >= 0) && (sec_r001477_15_1 <= 255));
  __CPROVER_assume((sec_r001477_15_2 >= 0) && (sec_r001477_15_2 <= 255));
  __CPROVER_assume((sec_r001477_16_1 >= 0) && (sec_r001477_16_1 <= 255));
  __CPROVER_assume((sec_r001477_16_2 >= 0) && (sec_r001477_16_2 <= 255));
  __CPROVER_assume((sec_r001477_17_1 >= 0) && (sec_r001477_17_1 <= 255));
  __CPROVER_assume((sec_r001477_17_2 >= 0) && (sec_r001477_17_2 <= 255));
  struct SensorNode_R001477_7713_0 st_var_0_1 = {0};
  struct SensorNode_R001477_7713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001477_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001477_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001477_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001477_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001477_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001477_0_2 + 7) & 15;
  struct CipherContext_R001477_7713_1 st_var_1_1 = {0};
  struct CipherContext_R001477_7713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001477_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001477_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001477_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001477_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001477_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001477_0_2 + 9) & 15;
  union ColorPixel_R001477_7713_0 u_var_1;
  union ColorPixel_R001477_7713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001477_7713_0(sec_r001477_0_1, sec_r001477_1_1, pub_r001477_2_1);
  int helper_flow_0_2 = fn_R001477_7713_0(sec_r001477_0_2, sec_r001477_1_2, pub_r001477_2_2);
  fn_R001477_7713_0_2(sec_r001477_0_1, sec_r001477_1_1, pub_r001477_2_1, sec_r001477_0_2, sec_r001477_1_2, pub_r001477_2_2);
  int helper_flow_1_1 = fn_R001477_7713_1(sec_r001477_1_1, pub_r001477_2_1, pub_r001477_3_1, pub_r001477_4_1, pub_r001477_5_1);
  int helper_flow_1_2 = fn_R001477_7713_1(sec_r001477_1_2, pub_r001477_2_2, pub_r001477_3_2, pub_r001477_4_2, pub_r001477_5_2);
  fn_R001477_7713_1_2(sec_r001477_1_1, pub_r001477_2_1, pub_r001477_3_1, pub_r001477_4_1, pub_r001477_5_1, sec_r001477_1_2, pub_r001477_2_2, pub_r001477_3_2, pub_r001477_4_2, pub_r001477_5_2);
  int helper_flow_2_1 = fn_R001477_7713_2(sec_r001477_2_1, pub_r001477_3_1, pub_r001477_4_1, pub_r001477_5_1, pub_r001477_6_1);
  int helper_flow_2_2 = fn_R001477_7713_2(sec_r001477_2_2, pub_r001477_3_2, pub_r001477_4_2, pub_r001477_5_2, pub_r001477_6_2);
  fn_R001477_7713_2_2(sec_r001477_2_1, pub_r001477_3_1, pub_r001477_4_1, pub_r001477_5_1, pub_r001477_6_1, sec_r001477_2_2, pub_r001477_3_2, pub_r001477_4_2, pub_r001477_5_2, pub_r001477_6_2);
  int helper_flow_3_1 = fn_R001477_7713_3(sec_r001477_3_1, sec_r001477_4_1);
  int helper_flow_3_2 = fn_R001477_7713_3(sec_r001477_3_2, sec_r001477_4_2);
  fn_R001477_7713_3_2(sec_r001477_3_1, sec_r001477_4_1, sec_r001477_3_2, sec_r001477_4_2);
  int helper_flow_4_1 = fn_R001477_7713_4(sec_r001477_4_1, pub_r001477_5_1);
  int helper_flow_4_2 = fn_R001477_7713_4(sec_r001477_4_2, pub_r001477_5_2);
  fn_R001477_7713_4_2(sec_r001477_4_1, pub_r001477_5_1, sec_r001477_4_2, pub_r001477_5_2);
  int helper_flow_5_1 = fn_R001477_7713_5(sec_r001477_5_1, pub_r001477_6_1, pub_r001477_7_1, pub_r001477_8_1);
  int helper_flow_5_2 = fn_R001477_7713_5(sec_r001477_5_2, pub_r001477_6_2, pub_r001477_7_2, pub_r001477_8_2);
  fn_R001477_7713_5_2(sec_r001477_5_1, pub_r001477_6_1, pub_r001477_7_1, pub_r001477_8_1, sec_r001477_5_2, pub_r001477_6_2, pub_r001477_7_2, pub_r001477_8_2);
  int helper_flow_6_1 = fn_R001477_7713_6(sec_r001477_6_1, pub_r001477_7_1);
  int helper_flow_6_2 = fn_R001477_7713_6(sec_r001477_6_2, pub_r001477_7_2);
  fn_R001477_7713_6_2(sec_r001477_6_1, pub_r001477_7_1, sec_r001477_6_2, pub_r001477_7_2);
  int stage_v_0_1 = (sec_r001477_9_1 ^ pub_r001477_7_1) & 63;
  int stage_v_0_2 = (sec_r001477_9_2 ^ pub_r001477_7_2) & 63;
  if ((stage_v_0_1 & 1) != 0)
  {
    if ((sec_r001477_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_0_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_0_1 * 2)) & 255;
  }
  if ((stage_v_0_2 & 1) != 0)
  {
    if ((sec_r001477_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_0_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_0_2 * 2)) & 255;
  }
  int stage_v_1_1 = (sec_r001477_16_1 ^ pub_r001477_8_1) & 63;
  int stage_v_1_2 = (sec_r001477_16_2 ^ pub_r001477_8_2) & 63;
  if ((stage_v_1_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
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
    if ((helper_flow_1_2 & 2) != 0)
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
  int stage_v_2_1 = (sec_r001477_0_1 ^ pub_r001477_4_1) & 63;
  int stage_v_2_2 = (sec_r001477_0_2 ^ pub_r001477_4_2) & 63;
  if ((stage_v_2_1 & 1) != 0)
  {
    if ((sec_r001477_6_1 & 2) != 0)
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
    if ((sec_r001477_6_2 & 2) != 0)
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
  int stage_v_3_1 = (sec_r001477_16_1 ^ pub_r001477_19_1) & 63;
  int stage_v_3_2 = (sec_r001477_16_2 ^ pub_r001477_19_2) & 63;
  if ((stage_v_3_1 & 1) != 0)
  {
    if ((sec_r001477_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_3_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_3_1 * 2)) & 255;
  }
  if ((stage_v_3_2 & 1) != 0)
  {
    if ((sec_r001477_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_3_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_3_2 * 2)) & 255;
  }
  int stage_v_4_1 = (sec_r001477_9_1 ^ pub_r001477_2_1) & 63;
  int stage_v_4_2 = (sec_r001477_9_2 ^ pub_r001477_2_2) & 63;
  if ((stage_v_4_1 & 1) != 0)
  {
    if ((sec_r001477_6_1 & 2) != 0)
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
    if ((sec_r001477_6_2 & 2) != 0)
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
  int stage_v_5_1 = ((pub_r001477_3_1 * 2) + 33) & 63;
  int stage_v_5_2 = ((pub_r001477_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001477_4_1 * 2) + 8) & 63;
  int stage_v_6_2 = ((pub_r001477_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001477_2_1 * 2) + 38) & 63;
  int stage_v_7_2 = ((pub_r001477_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001477_0_1 * 2) + 14) & 63;
  int stage_v_8_2 = ((pub_r001477_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (sec_r001477_7_1 ^ pub_r001477_6_1) & 63;
  int stage_v_9_2 = (sec_r001477_7_2 ^ pub_r001477_6_2) & 63;
  if ((stage_v_9_1 & 1) != 0)
  {
    if ((sec_r001477_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_9_1 * 2)) & 255;
  }
  if ((stage_v_9_2 & 1) != 0)
  {
    if ((sec_r001477_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_9_2 * 2)) & 255;
  }
  int stage_v_10_1 = (helper_flow_3_1 ^ pub_r001477_4_1) & 63;
  int stage_v_10_2 = (helper_flow_3_2 ^ pub_r001477_4_2) & 63;
  if ((stage_v_10_1 & 1) != 0)
  {
    if ((sec_r001477_16_1 & 2) != 0)
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
    if ((sec_r001477_16_2 & 2) != 0)
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
  int stage_v_11_1 = (sec_r001477_5_1 ^ pub_r001477_20_1) & 63;
  int stage_v_11_2 = (sec_r001477_5_2 ^ pub_r001477_20_2) & 63;
  if ((stage_v_11_1 & 1) != 0)
  {
    if ((sec_r001477_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_11_1 * 2)) & 255;
  }
  if ((stage_v_11_2 & 1) != 0)
  {
    if ((sec_r001477_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_11_2 * 2)) & 255;
  }
  int stage_v_12_1 = ((pub_r001477_15_1 * 2) + 35) & 63;
  int stage_v_12_2 = ((pub_r001477_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (stage_v_4_1 ^ pub_r001477_14_1) & 63;
  int stage_v_13_2 = (stage_v_4_2 ^ pub_r001477_14_2) & 63;
  if ((stage_v_13_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
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
    if ((helper_flow_6_2 & 2) != 0)
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
  int stage_v_14_1 = (sec_r001477_9_1 ^ pub_r001477_1_1) & 63;
  int stage_v_14_2 = (sec_r001477_9_2 ^ pub_r001477_1_2) & 63;
  if ((stage_v_14_1 & 1) != 0)
  {
    if ((sec_r001477_8_1 & 2) != 0)
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
    if ((sec_r001477_8_2 & 2) != 0)
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
  int stage_v_15_1 = ((pub_r001477_20_1 * 2) + 27) & 63;
  int stage_v_15_2 = ((pub_r001477_20_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001477_0_1 * 2) + 48) & 63;
  int stage_v_16_2 = ((pub_r001477_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001477_18_1 * 2) + 13) & 63;
  int stage_v_17_2 = ((pub_r001477_18_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = (sec_r001477_8_1 ^ pub_r001477_12_1) & 63;
  int stage_v_18_2 = (sec_r001477_8_2 ^ pub_r001477_12_2) & 63;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r001477_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_18_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_18_1 * 2)) & 255;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((sec_r001477_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_18_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_18_2 * 2)) & 255;
  }
  int stage_v_19_1 = (helper_flow_3_1 ^ pub_r001477_10_1) & 63;
  int stage_v_19_2 = (helper_flow_3_2 ^ pub_r001477_10_2) & 63;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r001477_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_19_1 * 2)) & 255;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r001477_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_19_2 * 2)) & 255;
  }
  int stage_v_20_1 = (helper_flow_4_1 ^ pub_r001477_7_1) & 63;
  int stage_v_20_2 = (helper_flow_4_2 ^ pub_r001477_7_2) & 63;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r001477_14_1 & 2) != 0)
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
    if ((sec_r001477_14_2 & 2) != 0)
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
  int stage_v_21_1 = (stage_v_3_1 ^ pub_r001477_3_1) & 63;
  int stage_v_21_2 = (stage_v_3_2 ^ pub_r001477_3_2) & 63;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((sec_r001477_5_1 & 2) != 0)
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
    if ((sec_r001477_5_2 & 2) != 0)
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
  int stage_v_22_1 = ((pub_r001477_5_1 * 2) + 28) & 63;
  int stage_v_22_2 = ((pub_r001477_5_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (sec_r001477_4_1 ^ pub_r001477_12_1) & 63;
  int stage_v_23_2 = (sec_r001477_4_2 ^ pub_r001477_12_2) & 63;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((stage_v_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_23_1 * 2)) & 255;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((stage_v_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_23_2 * 2)) & 255;
  }
  int stage_v_24_1 = (stage_v_23_1 ^ pub_r001477_14_1) & 63;
  int stage_v_24_2 = (stage_v_23_2 ^ pub_r001477_14_2) & 63;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r001477_5_1 & 2) != 0)
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
    if ((sec_r001477_5_2 & 2) != 0)
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
  int stage_v_25_1 = (sec_r001477_10_1 ^ pub_r001477_20_1) & 63;
  int stage_v_25_2 = (sec_r001477_10_2 ^ pub_r001477_20_2) & 63;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
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
    if ((helper_flow_3_2 & 2) != 0)
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
  int stage_v_26_1 = (sec_r001477_14_1 ^ pub_r001477_16_1) & 63;
  int stage_v_26_2 = (sec_r001477_14_2 ^ pub_r001477_16_2) & 63;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r001477_8_1 & 2) != 0)
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
    if ((sec_r001477_8_2 & 2) != 0)
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
  int stage_v_27_1 = ((pub_r001477_0_1 * 2) + 48) & 63;
  int stage_v_27_2 = ((pub_r001477_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (sec_r001477_11_1 ^ pub_r001477_19_1) & 63;
  int stage_v_28_2 = (sec_r001477_11_2 ^ pub_r001477_19_2) & 63;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r001477_4_1 & 2) != 0)
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
    if ((sec_r001477_4_2 & 2) != 0)
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
  int stage_v_29_1 = (stage_v_14_1 ^ pub_r001477_8_1) & 63;
  int stage_v_29_2 = (stage_v_14_2 ^ pub_r001477_8_2) & 63;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((stage_v_19_1 & 2) != 0)
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
    if ((stage_v_19_2 & 2) != 0)
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
  int stage_v_30_1 = (stage_v_9_1 ^ pub_r001477_5_1) & 63;
  int stage_v_30_2 = (stage_v_9_2 ^ pub_r001477_5_2) & 63;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
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
    if ((stage_v_21_2 & 2) != 0)
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
  int stage_v_31_1 = (stage_v_26_1 ^ pub_r001477_2_1) & 63;
  int stage_v_31_2 = (stage_v_26_2 ^ pub_r001477_2_2) & 63;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r001477_6_1 & 2) != 0)
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
    if ((sec_r001477_6_2 & 2) != 0)
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
  int stage_v_32_1 = ((pub_r001477_15_1 * 2) + 47) & 63;
  int stage_v_32_2 = ((pub_r001477_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001477_10_1 * 2) + 8) & 63;
  int stage_v_33_2 = ((pub_r001477_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001477_20_1 * 2) + 23) & 63;
  int stage_v_34_2 = ((pub_r001477_20_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001477_19_1 * 2) + 7) & 63;
  int stage_v_35_2 = ((pub_r001477_19_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (sec_r001477_7_1 ^ pub_r001477_5_1) & 63;
  int stage_v_36_2 = (sec_r001477_7_2 ^ pub_r001477_5_2) & 63;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r001477_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_36_1 * 2)) & 255;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r001477_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_36_2 * 2)) & 255;
  }
  int stage_v_37_1 = (sec_r001477_16_1 ^ pub_r001477_9_1) & 63;
  int stage_v_37_2 = (sec_r001477_16_2 ^ pub_r001477_9_2) & 63;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r001477_11_1 & 2) != 0)
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
    if ((sec_r001477_11_2 & 2) != 0)
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
  int stage_v_38_1 = (stage_v_10_1 ^ pub_r001477_1_1) & 63;
  int stage_v_38_2 = (stage_v_10_2 ^ pub_r001477_1_2) & 63;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((stage_v_14_1 & 2) != 0)
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
    if ((stage_v_14_2 & 2) != 0)
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
  int stage_v_39_1 = ((pub_r001477_1_1 * 2) + 45) & 63;
  int stage_v_39_2 = ((pub_r001477_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (helper_flow_1_1 ^ pub_r001477_19_1) & 63;
  int stage_v_40_2 = (helper_flow_1_2 ^ pub_r001477_19_2) & 63;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r001477_17_1 & 2) != 0)
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
    if ((sec_r001477_17_2 & 2) != 0)
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
  int stage_v_41_1 = (helper_flow_1_1 ^ pub_r001477_13_1) & 63;
  int stage_v_41_2 = (helper_flow_1_2 ^ pub_r001477_13_2) & 63;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r001477_13_1 & 2) != 0)
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
    if ((sec_r001477_13_2 & 2) != 0)
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
  int stage_v_42_1 = (stage_v_4_1 ^ pub_r001477_5_1) & 63;
  int stage_v_42_2 = (stage_v_4_2 ^ pub_r001477_5_2) & 63;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((stage_v_14_1 & 2) != 0)
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
    if ((stage_v_14_2 & 2) != 0)
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
  int stage_v_43_1 = ((pub_r001477_6_1 * 2) + 6) & 63;
  int stage_v_43_2 = ((pub_r001477_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (stage_v_28_1 ^ pub_r001477_10_1) & 63;
  int stage_v_44_2 = (stage_v_28_2 ^ pub_r001477_10_2) & 63;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((stage_v_42_1 & 2) != 0)
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
    if ((stage_v_42_2 & 2) != 0)
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
  int stage_v_45_1 = ((pub_r001477_18_1 * 2) + 48) & 63;
  int stage_v_45_2 = ((pub_r001477_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (helper_flow_0_1 ^ pub_r001477_7_1) & 63;
  int stage_v_46_2 = (helper_flow_0_2 ^ pub_r001477_7_2) & 63;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((stage_v_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_46_1 * 2)) & 255;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((stage_v_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_46_2 * 2)) & 255;
  }
  int stage_v_47_1 = ((pub_r001477_12_1 * 2) + 48) & 63;
  int stage_v_47_2 = ((pub_r001477_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (stage_v_19_1 ^ pub_r001477_18_1) & 63;
  int stage_v_48_2 = (stage_v_19_2 ^ pub_r001477_18_2) & 63;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r001477_1_1 & 2) != 0)
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
    if ((sec_r001477_1_2 & 2) != 0)
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
  int stage_v_49_1 = (stage_v_37_1 ^ pub_r001477_3_1) & 63;
  int stage_v_49_2 = (stage_v_37_2 ^ pub_r001477_3_2) & 63;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r001477_2_1 & 2) != 0)
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
    if ((sec_r001477_2_2 & 2) != 0)
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
  int stage_v_50_1 = (sec_r001477_17_1 ^ pub_r001477_10_1) & 63;
  int stage_v_50_2 = (sec_r001477_17_2 ^ pub_r001477_10_2) & 63;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((stage_v_28_1 & 2) != 0)
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
    if ((stage_v_28_2 & 2) != 0)
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
  int stage_v_51_1 = (stage_v_29_1 ^ pub_r001477_18_1) & 63;
  int stage_v_51_2 = (stage_v_29_2 ^ pub_r001477_18_2) & 63;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((stage_v_19_1 & 2) != 0)
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
    if ((stage_v_19_2 & 2) != 0)
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
  int stage_v_52_1 = ((pub_r001477_1_1 * 2) + 30) & 63;
  int stage_v_52_2 = ((pub_r001477_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001477_16_1 * 2) + 26) & 63;
  int stage_v_53_2 = ((pub_r001477_16_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (stage_v_19_1 ^ pub_r001477_10_1) & 63;
  int stage_v_54_2 = (stage_v_19_2 ^ pub_r001477_10_2) & 63;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r001477_0_1 & 2) != 0)
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
    if ((sec_r001477_0_2 & 2) != 0)
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
  int stage_v_55_1 = (stage_v_31_1 ^ pub_r001477_5_1) & 63;
  int stage_v_55_2 = (stage_v_31_2 ^ pub_r001477_5_2) & 63;
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
  int stage_v_56_1 = ((pub_r001477_16_1 * 2) + 28) & 63;
  int stage_v_56_2 = ((pub_r001477_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (stage_v_1_1 ^ pub_r001477_10_1) & 63;
  int stage_v_57_2 = (stage_v_1_2 ^ pub_r001477_10_2) & 63;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((stage_v_29_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_57_1 * 2)) & 255;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((stage_v_29_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_57_2 * 2)) & 255;
  }
  int stage_v_58_1 = ((pub_r001477_16_1 * 2) + 20) & 63;
  int stage_v_58_2 = ((pub_r001477_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (stage_v_49_1 ^ pub_r001477_2_1) & 63;
  int stage_v_59_2 = (stage_v_49_2 ^ pub_r001477_2_2) & 63;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((stage_v_23_1 & 2) != 0)
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
    if ((stage_v_23_2 & 2) != 0)
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
  int stage_v_60_1 = ((pub_r001477_20_1 * 2) + 38) & 63;
  int stage_v_60_2 = ((pub_r001477_20_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001477_5_1 * 2) + 9) & 63;
  int stage_v_61_2 = ((pub_r001477_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = (stage_v_41_1 ^ pub_r001477_4_1) & 63;
  int stage_v_62_2 = (stage_v_41_2 ^ pub_r001477_4_2) & 63;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((stage_v_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_62_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_62_1 * 2)) & 255;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((stage_v_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_62_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_62_2 * 2)) & 255;
  }
  int stage_v_63_1 = ((pub_r001477_15_1 * 2) + 33) & 63;
  int stage_v_63_2 = ((pub_r001477_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (stage_v_26_1 ^ pub_r001477_17_1) & 63;
  int stage_v_64_2 = (stage_v_26_2 ^ pub_r001477_17_2) & 63;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_64_1 * 2)) & 255;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((stage_v_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_64_2 * 2)) & 255;
  }
  int stage_v_65_1 = (stage_v_23_1 ^ pub_r001477_9_1) & 63;
  int stage_v_65_2 = (stage_v_23_2 ^ pub_r001477_9_2) & 63;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_65_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_65_1 * 2)) & 255;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((stage_v_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_65_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_65_2 * 2)) & 255;
  }
  int stage_v_66_1 = (stage_v_23_1 ^ pub_r001477_18_1) & 63;
  int stage_v_66_2 = (stage_v_23_2 ^ pub_r001477_18_2) & 63;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r001477_11_1 & 2) != 0)
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
    if ((sec_r001477_11_2 & 2) != 0)
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
  int stage_v_67_1 = (stage_v_66_1 ^ pub_r001477_18_1) & 63;
  int stage_v_67_2 = (stage_v_66_2 ^ pub_r001477_18_2) & 63;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((stage_v_51_1 & 2) != 0)
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
    if ((stage_v_51_2 & 2) != 0)
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
  int stage_v_68_1 = ((pub_r001477_12_1 * 2) + 5) & 63;
  int stage_v_68_2 = ((pub_r001477_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001477_7_1 * 2) + 22) & 63;
  int stage_v_69_2 = ((pub_r001477_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (sec_r001477_5_1 ^ pub_r001477_17_1) & 63;
  int stage_v_70_2 = (sec_r001477_5_2 ^ pub_r001477_17_2) & 63;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r001477_13_1 & 2) != 0)
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
    if ((sec_r001477_13_2 & 2) != 0)
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
  int stage_v_71_1 = (stage_v_28_1 ^ pub_r001477_4_1) & 63;
  int stage_v_71_2 = (stage_v_28_2 ^ pub_r001477_4_2) & 63;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((stage_v_66_1 & 2) != 0)
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
    if ((stage_v_66_2 & 2) != 0)
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
  int stage_v_72_1 = (stage_v_2_1 ^ pub_r001477_4_1) & 63;
  int stage_v_72_2 = (stage_v_2_2 ^ pub_r001477_4_2) & 63;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((stage_v_64_1 & 2) != 0)
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
    if ((stage_v_64_2 & 2) != 0)
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
  int stage_v_73_1 = (helper_flow_6_1 ^ pub_r001477_12_1) & 63;
  int stage_v_73_2 = (helper_flow_6_2 ^ pub_r001477_12_2) & 63;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r001477_9_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_73_1 * 2)) & 255;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r001477_9_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_73_2 * 2)) & 255;
  }
  int stage_v_74_1 = (sec_r001477_1_1 ^ pub_r001477_10_1) & 63;
  int stage_v_74_2 = (sec_r001477_1_2 ^ pub_r001477_10_2) & 63;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((stage_v_30_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_74_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_74_1 * 2)) & 255;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((stage_v_30_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_74_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_74_2 * 2)) & 255;
  }
  int stage_v_75_1 = (stage_v_36_1 ^ pub_r001477_20_1) & 63;
  int stage_v_75_2 = (stage_v_36_2 ^ pub_r001477_20_2) & 63;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((stage_v_59_1 & 2) != 0)
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
    if ((stage_v_59_2 & 2) != 0)
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
  int stage_v_76_1 = (stage_v_59_1 ^ pub_r001477_19_1) & 63;
  int stage_v_76_2 = (stage_v_59_2 ^ pub_r001477_19_2) & 63;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((stage_v_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_76_1 * 2)) & 255;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((stage_v_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_76_2 * 2)) & 255;
  }
  int stage_v_77_1 = (stage_v_54_1 ^ pub_r001477_0_1) & 63;
  int stage_v_77_2 = (stage_v_54_2 ^ pub_r001477_0_2) & 63;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_77_1 * 2)) & 255;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_77_2 * 2)) & 255;
  }
  int stage_v_78_1 = (stage_v_41_1 ^ pub_r001477_6_1) & 63;
  int stage_v_78_2 = (stage_v_41_2 ^ pub_r001477_6_2) & 63;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
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
    if ((stage_v_40_2 & 2) != 0)
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
  int stage_v_79_1 = (stage_v_73_1 ^ pub_r001477_7_1) & 63;
  int stage_v_79_2 = (stage_v_73_2 ^ pub_r001477_7_2) & 63;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((stage_v_70_1 & 2) != 0)
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
    if ((stage_v_70_2 & 2) != 0)
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
  int stage_v_80_1 = (stage_v_51_1 ^ pub_r001477_8_1) & 63;
  int stage_v_80_2 = (stage_v_51_2 ^ pub_r001477_8_2) & 63;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((stage_v_77_1 & 2) != 0)
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
    if ((stage_v_77_2 & 2) != 0)
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
  int stage_v_81_1 = (stage_v_25_1 ^ pub_r001477_9_1) & 63;
  int stage_v_81_2 = (stage_v_25_2 ^ pub_r001477_9_2) & 63;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((stage_v_2_1 & 2) != 0)
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
    if ((stage_v_2_2 & 2) != 0)
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
  int stage_v_82_1 = (sec_r001477_16_1 ^ pub_r001477_16_1) & 63;
  int stage_v_82_2 = (sec_r001477_16_2 ^ pub_r001477_16_2) & 63;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r001477_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_82_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_82_1 * 2)) & 255;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r001477_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_82_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_82_2 * 2)) & 255;
  }
  int stage_v_83_1 = (stage_v_21_1 ^ pub_r001477_7_1) & 63;
  int stage_v_83_2 = (stage_v_21_2 ^ pub_r001477_7_2) & 63;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r001477_8_1 & 2) != 0)
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
    if ((sec_r001477_8_2 & 2) != 0)
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
  int stage_v_84_1 = ((pub_r001477_2_1 * 2) + 39) & 63;
  int stage_v_84_2 = ((pub_r001477_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = (stage_v_10_1 ^ pub_r001477_18_1) & 63;
  int stage_v_85_2 = (stage_v_10_2 ^ pub_r001477_18_2) & 63;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r001477_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_85_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r001477_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_85_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  }
  int stage_v_86_1 = ((pub_r001477_19_1 * 2) + 42) & 63;
  int stage_v_86_2 = ((pub_r001477_19_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (stage_v_2_1 ^ pub_r001477_13_1) & 63;
  int stage_v_87_2 = (stage_v_2_2 ^ pub_r001477_13_2) & 63;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r001477_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r001477_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  }
  int stage_v_88_1 = ((pub_r001477_8_1 * 2) + 44) & 63;
  int stage_v_88_2 = ((pub_r001477_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (stage_v_36_1 ^ pub_r001477_18_1) & 63;
  int stage_v_89_2 = (stage_v_36_2 ^ pub_r001477_18_2) & 63;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((stage_v_37_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_89_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((stage_v_37_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_89_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  }
  int stage_v_90_1 = (helper_flow_5_1 ^ pub_r001477_17_1) & 63;
  int stage_v_90_2 = (helper_flow_5_2 ^ pub_r001477_17_2) & 63;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((stage_v_66_1 & 2) != 0)
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
    if ((stage_v_66_2 & 2) != 0)
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
  int stage_v_91_1 = (stage_v_65_1 ^ pub_r001477_4_1) & 63;
  int stage_v_91_2 = (stage_v_65_2 ^ pub_r001477_4_2) & 63;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((stage_v_75_1 & 2) != 0)
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
    if ((stage_v_75_2 & 2) != 0)
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
  int stage_v_92_1 = (stage_v_3_1 ^ pub_r001477_19_1) & 63;
  int stage_v_92_2 = (stage_v_3_2 ^ pub_r001477_19_2) & 63;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((stage_v_74_1 & 2) != 0)
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
    if ((stage_v_74_2 & 2) != 0)
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
  int stage_v_93_1 = ((pub_r001477_17_1 * 2) + 17) & 63;
  int stage_v_93_2 = ((pub_r001477_17_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (helper_flow_5_1 ^ pub_r001477_16_1) & 63;
  int stage_v_94_2 = (helper_flow_5_2 ^ pub_r001477_16_2) & 63;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((stage_v_82_1 & 2) != 0)
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
    if ((stage_v_82_2 & 2) != 0)
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
  int stage_v_95_1 = ((pub_r001477_7_1 * 2) + 6) & 63;
  int stage_v_95_2 = ((pub_r001477_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (sec_r001477_6_1 ^ pub_r001477_12_1) & 63;
  int stage_v_96_2 = (sec_r001477_6_2 ^ pub_r001477_12_2) & 63;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((stage_v_72_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((stage_v_72_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  }
  int stage_v_97_1 = (helper_flow_1_1 ^ pub_r001477_13_1) & 63;
  int stage_v_97_2 = (helper_flow_1_2 ^ pub_r001477_13_2) & 63;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
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
    if ((helper_flow_4_2 & 2) != 0)
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
  int stage_v_98_1 = ((pub_r001477_1_1 * 2) + 13) & 63;
  int stage_v_98_2 = ((pub_r001477_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001477_0_1 * 2) + 10) & 63;
  int stage_v_99_2 = ((pub_r001477_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (stage_v_40_1 ^ pub_r001477_6_1) & 63;
  int stage_v_100_2 = (stage_v_40_2 ^ pub_r001477_6_2) & 63;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((stage_v_42_1 & 2) != 0)
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
    if ((stage_v_42_2 & 2) != 0)
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
  int stage_v_101_1 = (sec_r001477_5_1 ^ pub_r001477_6_1) & 63;
  int stage_v_101_2 = (sec_r001477_5_2 ^ pub_r001477_6_2) & 63;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((stage_v_78_1 & 2) != 0)
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
    if ((stage_v_78_2 & 2) != 0)
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
  int stage_v_102_1 = ((pub_r001477_9_1 * 2) + 27) & 63;
  int stage_v_102_2 = ((pub_r001477_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (helper_flow_6_1 ^ pub_r001477_18_1) & 63;
  int stage_v_103_2 = (helper_flow_6_2 ^ pub_r001477_18_2) & 63;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((stage_v_77_1 & 2) != 0)
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
    if ((stage_v_77_2 & 2) != 0)
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
  int stage_v_104_1 = (sec_r001477_0_1 ^ pub_r001477_13_1) & 63;
  int stage_v_104_2 = (sec_r001477_0_2 ^ pub_r001477_13_2) & 63;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((stage_v_87_1 & 2) != 0)
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
    if ((stage_v_87_2 & 2) != 0)
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
  int stage_v_105_1 = (sec_r001477_4_1 ^ pub_r001477_9_1) & 63;
  int stage_v_105_2 = (sec_r001477_4_2 ^ pub_r001477_9_2) & 63;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r001477_12_1 & 2) != 0)
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
    if ((sec_r001477_12_2 & 2) != 0)
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
  int stage_v_106_1 = ((pub_r001477_4_1 * 2) + 6) & 63;
  int stage_v_106_2 = ((pub_r001477_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001477_2_1 * 2) + 24) & 63;
  int stage_v_107_2 = ((pub_r001477_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (stage_v_29_1 ^ pub_r001477_3_1) & 63;
  int stage_v_108_2 = (stage_v_29_2 ^ pub_r001477_3_2) & 63;
  if ((stage_v_108_1 & 1) != 0)
  {
    if ((stage_v_51_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  }
  if ((stage_v_108_2 & 1) != 0)
  {
    if ((stage_v_51_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  }
  int stage_v_109_1 = (helper_flow_3_1 ^ pub_r001477_16_1) & 63;
  int stage_v_109_2 = (helper_flow_3_2 ^ pub_r001477_16_2) & 63;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((stage_v_82_1 & 2) != 0)
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
    if ((stage_v_82_2 & 2) != 0)
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
  int stage_v_110_1 = (stage_v_73_1 ^ pub_r001477_0_1) & 63;
  int stage_v_110_2 = (stage_v_73_2 ^ pub_r001477_0_2) & 63;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((stage_v_38_1 & 2) != 0)
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
    if ((stage_v_38_2 & 2) != 0)
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
  int stage_v_111_1 = ((pub_r001477_5_1 * 2) + 13) & 63;
  int stage_v_111_2 = ((pub_r001477_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001477_3_1 * 2) + 36) & 63;
  int stage_v_112_2 = ((pub_r001477_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (stage_v_76_1 ^ pub_r001477_19_1) & 63;
  int stage_v_113_2 = (stage_v_76_2 ^ pub_r001477_19_2) & 63;
  if ((stage_v_113_1 & 1) != 0)
  {
    if ((stage_v_48_1 & 2) != 0)
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
    if ((stage_v_48_2 & 2) != 0)
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
  int stage_v_114_1 = (sec_r001477_0_1 ^ pub_r001477_10_1) & 63;
  int stage_v_114_2 = (sec_r001477_0_2 ^ pub_r001477_10_2) & 63;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r001477_10_1 & 2) != 0)
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
    if ((sec_r001477_10_2 & 2) != 0)
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
  int stage_v_115_1 = (stage_v_62_1 ^ pub_r001477_4_1) & 63;
  int stage_v_115_2 = (stage_v_62_2 ^ pub_r001477_4_2) & 63;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((stage_v_114_1 & 2) != 0)
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
    if ((stage_v_114_2 & 2) != 0)
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
  int stage_v_116_1 = (sec_r001477_2_1 ^ pub_r001477_11_1) & 63;
  int stage_v_116_2 = (sec_r001477_2_2 ^ pub_r001477_11_2) & 63;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((stage_v_85_1 & 2) != 0)
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
    if ((stage_v_85_2 & 2) != 0)
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
  int stage_v_117_1 = (stage_v_26_1 ^ pub_r001477_2_1) & 63;
  int stage_v_117_2 = (stage_v_26_2 ^ pub_r001477_2_2) & 63;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((stage_v_79_1 & 2) != 0)
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
    if ((stage_v_79_2 & 2) != 0)
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
  int stage_v_118_1 = (stage_v_9_1 ^ pub_r001477_15_1) & 63;
  int stage_v_118_2 = (stage_v_9_2 ^ pub_r001477_15_2) & 63;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((stage_v_74_1 & 2) != 0)
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
    if ((stage_v_74_2 & 2) != 0)
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
  int stage_v_119_1 = ((pub_r001477_4_1 * 2) + 20) & 63;
  int stage_v_119_2 = ((pub_r001477_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001477_19_1 * 2) + 27) & 63;
  int stage_v_120_2 = ((pub_r001477_19_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = (stage_v_110_1 ^ pub_r001477_5_1) & 63;
  int stage_v_121_2 = (stage_v_110_2 ^ pub_r001477_5_2) & 63;
  if ((stage_v_121_1 & 1) != 0)
  {
    if ((stage_v_105_1 & 2) != 0)
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
    if ((stage_v_105_2 & 2) != 0)
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
  int stage_v_122_1 = (stage_v_105_1 ^ pub_r001477_3_1) & 63;
  int stage_v_122_2 = (stage_v_105_2 ^ pub_r001477_3_2) & 63;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((stage_v_83_1 & 2) != 0)
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
    if ((stage_v_83_2 & 2) != 0)
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
  int stage_v_123_1 = ((pub_r001477_4_1 * 2) + 26) & 63;
  int stage_v_123_2 = ((pub_r001477_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (stage_v_87_1 ^ pub_r001477_9_1) & 63;
  int stage_v_124_2 = (stage_v_87_2 ^ pub_r001477_9_2) & 63;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((stage_v_118_1 & 2) != 0)
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
    if ((stage_v_118_2 & 2) != 0)
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
  int stage_v_125_1 = (stage_v_28_1 ^ pub_r001477_20_1) & 63;
  int stage_v_125_2 = (stage_v_28_2 ^ pub_r001477_20_2) & 63;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((stage_v_24_1 & 2) != 0)
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
    if ((stage_v_24_2 & 2) != 0)
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
  int stage_v_126_1 = ((pub_r001477_10_1 * 2) + 28) & 63;
  int stage_v_126_2 = ((pub_r001477_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = (stage_v_31_1 ^ pub_r001477_13_1) & 63;
  int stage_v_127_2 = (stage_v_31_2 ^ pub_r001477_13_2) & 63;
  if ((stage_v_127_1 & 1) != 0)
  {
    if ((sec_r001477_17_1 & 2) != 0)
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
    if ((sec_r001477_17_2 & 2) != 0)
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
  int stage_v_128_1 = (stage_v_72_1 ^ pub_r001477_7_1) & 63;
  int stage_v_128_2 = (stage_v_72_2 ^ pub_r001477_7_2) & 63;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((helper_flow_6_1 & 2) != 0)
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
    if ((helper_flow_6_2 & 2) != 0)
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
  int stage_v_129_1 = (stage_v_114_1 ^ pub_r001477_9_1) & 63;
  int stage_v_129_2 = (stage_v_114_2 ^ pub_r001477_9_2) & 63;
  if ((stage_v_129_1 & 1) != 0)
  {
    if ((stage_v_121_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  }
  if ((stage_v_129_2 & 1) != 0)
  {
    if ((stage_v_121_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  }
  int stage_v_130_1 = ((pub_r001477_14_1 * 2) + 32) & 63;
  int stage_v_130_2 = ((pub_r001477_14_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (stage_v_71_1 ^ pub_r001477_5_1) & 63;
  int stage_v_131_2 = (stage_v_71_2 ^ pub_r001477_5_2) & 63;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((stage_v_83_1 & 2) != 0)
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
    if ((stage_v_83_2 & 2) != 0)
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
  int stage_v_132_1 = (stage_v_13_1 ^ pub_r001477_19_1) & 63;
  int stage_v_132_2 = (stage_v_13_2 ^ pub_r001477_19_2) & 63;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((helper_flow_5_1 & 2) != 0)
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
    if ((helper_flow_5_2 & 2) != 0)
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
  int stage_v_133_1 = ((pub_r001477_11_1 * 2) + 20) & 63;
  int stage_v_133_2 = ((pub_r001477_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = (stage_v_75_1 ^ pub_r001477_0_1) & 63;
  int stage_v_134_2 = (stage_v_75_2 ^ pub_r001477_0_2) & 63;
  if ((stage_v_134_1 & 1) != 0)
  {
    if ((stage_v_25_1 & 2) != 0)
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
    if ((stage_v_25_2 & 2) != 0)
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
  int stage_v_135_1 = (stage_v_87_1 ^ pub_r001477_7_1) & 63;
  int stage_v_135_2 = (stage_v_87_2 ^ pub_r001477_7_2) & 63;
  if ((stage_v_135_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
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
    if ((stage_v_3_2 & 2) != 0)
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
  int stage_v_136_1 = (stage_v_115_1 ^ pub_r001477_17_1) & 63;
  int stage_v_136_2 = (stage_v_115_2 ^ pub_r001477_17_2) & 63;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((stage_v_79_1 & 2) != 0)
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
    if ((stage_v_79_2 & 2) != 0)
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
  int stage_v_137_1 = ((pub_r001477_13_1 * 2) + 46) & 63;
  int stage_v_137_2 = ((pub_r001477_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (stage_v_96_1 ^ pub_r001477_10_1) & 63;
  int stage_v_138_2 = (stage_v_96_2 ^ pub_r001477_10_2) & 63;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  }
  if ((stage_v_138_2 & 1) != 0)
  {
    if ((helper_flow_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  }
  int stage_v_139_1 = (stage_v_0_1 ^ pub_r001477_7_1) & 63;
  int stage_v_139_2 = (stage_v_0_2 ^ pub_r001477_7_2) & 63;
  if ((stage_v_139_1 & 1) != 0)
  {
    if ((sec_r001477_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  }
  if ((stage_v_139_2 & 1) != 0)
  {
    if ((sec_r001477_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  }
  int stage_v_140_1 = (stage_v_132_1 ^ pub_r001477_5_1) & 63;
  int stage_v_140_2 = (stage_v_132_2 ^ pub_r001477_5_2) & 63;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((stage_v_92_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  }
  if ((stage_v_140_2 & 1) != 0)
  {
    if ((stage_v_92_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  }
  int stage_v_141_1 = ((pub_r001477_3_1 * 2) + 10) & 63;
  int stage_v_141_2 = ((pub_r001477_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001477_0_1 * 2) + 16) & 63;
  int stage_v_142_2 = ((pub_r001477_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = (stage_v_46_1 ^ pub_r001477_2_1) & 63;
  int stage_v_143_2 = (stage_v_46_2 ^ pub_r001477_2_2) & 63;
  if ((stage_v_143_1 & 1) != 0)
  {
    if ((stage_v_77_1 & 2) != 0)
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
    if ((stage_v_77_2 & 2) != 0)
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
  int stage_v_144_1 = (stage_v_100_1 ^ pub_r001477_12_1) & 63;
  int stage_v_144_2 = (stage_v_100_2 ^ pub_r001477_12_2) & 63;
  if ((stage_v_144_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  }
  if ((stage_v_144_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  }
  int stage_v_145_1 = (stage_v_29_1 ^ pub_r001477_14_1) & 63;
  int stage_v_145_2 = (stage_v_29_2 ^ pub_r001477_14_2) & 63;
  if ((stage_v_145_1 & 1) != 0)
  {
    if ((stage_v_101_1 & 2) != 0)
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
    if ((stage_v_101_2 & 2) != 0)
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
  int stage_v_146_1 = ((pub_r001477_0_1 * 2) + 18) & 63;
  int stage_v_146_2 = ((pub_r001477_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001477_15_1 * 2) + 38) & 63;
  int stage_v_147_2 = ((pub_r001477_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (stage_v_40_1 ^ pub_r001477_12_1) & 63;
  int stage_v_148_2 = (stage_v_40_2 ^ pub_r001477_12_2) & 63;
  if ((stage_v_148_1 & 1) != 0)
  {
    if ((stage_v_103_1 & 2) != 0)
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
    if ((stage_v_103_2 & 2) != 0)
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
  int stage_v_149_1 = (stage_v_132_1 ^ pub_r001477_0_1) & 63;
  int stage_v_149_2 = (stage_v_132_2 ^ pub_r001477_0_2) & 63;
  if ((stage_v_149_1 & 1) != 0)
  {
    if ((stage_v_55_1 & 2) != 0)
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
    if ((stage_v_55_2 & 2) != 0)
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
  int stage_v_150_1 = (stage_v_100_1 ^ pub_r001477_5_1) & 63;
  int stage_v_150_2 = (stage_v_100_2 ^ pub_r001477_5_2) & 63;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((stage_v_62_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  }
  if ((stage_v_150_2 & 1) != 0)
  {
    if ((stage_v_62_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  }
  int stage_v_151_1 = (stage_v_31_1 ^ pub_r001477_8_1) & 63;
  int stage_v_151_2 = (stage_v_31_2 ^ pub_r001477_8_2) & 63;
  if ((stage_v_151_1 & 1) != 0)
  {
    if ((stage_v_110_1 & 2) != 0)
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
    if ((stage_v_110_2 & 2) != 0)
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
  int stage_v_152_1 = (stage_v_76_1 ^ pub_r001477_19_1) & 63;
  int stage_v_152_2 = (stage_v_76_2 ^ pub_r001477_19_2) & 63;
  if ((stage_v_152_1 & 1) != 0)
  {
    if ((stage_v_62_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_152_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  }
  if ((stage_v_152_2 & 1) != 0)
  {
    if ((stage_v_62_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_152_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  }
  int stage_v_153_1 = (stage_v_28_1 ^ pub_r001477_0_1) & 63;
  int stage_v_153_2 = (stage_v_28_2 ^ pub_r001477_0_2) & 63;
  if ((stage_v_153_1 & 1) != 0)
  {
    if ((stage_v_67_1 & 2) != 0)
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
    if ((stage_v_67_2 & 2) != 0)
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
  int stage_v_154_1 = (sec_r001477_3_1 ^ pub_r001477_1_1) & 63;
  int stage_v_154_2 = (sec_r001477_3_2 ^ pub_r001477_1_2) & 63;
  if ((stage_v_154_1 & 1) != 0)
  {
    if ((stage_v_91_1 & 2) != 0)
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
    if ((stage_v_91_2 & 2) != 0)
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
  int stage_v_155_1 = ((pub_r001477_2_1 * 2) + 29) & 63;
  int stage_v_155_2 = ((pub_r001477_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (stage_v_70_1 ^ pub_r001477_5_1) & 63;
  int stage_v_156_2 = (stage_v_70_2 ^ pub_r001477_5_2) & 63;
  if ((stage_v_156_1 & 1) != 0)
  {
    if ((stage_v_92_1 & 2) != 0)
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
    if ((stage_v_92_2 & 2) != 0)
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
  int stage_v_157_1 = (sec_r001477_17_1 ^ pub_r001477_8_1) & 63;
  int stage_v_157_2 = (sec_r001477_17_2 ^ pub_r001477_8_2) & 63;
  if ((stage_v_157_1 & 1) != 0)
  {
    if ((sec_r001477_17_1 & 2) != 0)
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
    if ((sec_r001477_17_2 & 2) != 0)
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
  int stage_v_158_1 = (stage_v_25_1 ^ pub_r001477_7_1) & 63;
  int stage_v_158_2 = (stage_v_25_2 ^ pub_r001477_7_2) & 63;
  if ((stage_v_158_1 & 1) != 0)
  {
    if ((stage_v_80_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_158_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  }
  if ((stage_v_158_2 & 1) != 0)
  {
    if ((stage_v_80_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_158_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  }
  int stage_v_159_1 = (stage_v_82_1 ^ pub_r001477_0_1) & 63;
  int stage_v_159_2 = (stage_v_82_2 ^ pub_r001477_0_2) & 63;
  if ((stage_v_159_1 & 1) != 0)
  {
    if ((stage_v_124_1 & 2) != 0)
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
    if ((stage_v_124_2 & 2) != 0)
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
  int stage_v_160_1 = (stage_v_109_1 ^ pub_r001477_19_1) & 63;
  int stage_v_160_2 = (stage_v_109_2 ^ pub_r001477_19_2) & 63;
  if ((stage_v_160_1 & 1) != 0)
  {
    if ((stage_v_132_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_160_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_160_1 * 2)) & 255;
  }
  if ((stage_v_160_2 & 1) != 0)
  {
    if ((stage_v_132_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_160_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_160_2 * 2)) & 255;
  }
  int stage_v_161_1 = ((pub_r001477_6_1 * 2) + 20) & 63;
  int stage_v_161_2 = ((pub_r001477_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (stage_v_90_1 ^ pub_r001477_11_1) & 63;
  int stage_v_162_2 = (stage_v_90_2 ^ pub_r001477_11_2) & 63;
  if ((stage_v_162_1 & 1) != 0)
  {
    if ((stage_v_101_1 & 2) != 0)
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
    if ((stage_v_101_2 & 2) != 0)
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
  int stage_v_163_1 = ((pub_r001477_8_1 * 2) + 45) & 63;
  int stage_v_163_2 = ((pub_r001477_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001477_13_1 * 2) + 38) & 63;
  int stage_v_164_2 = ((pub_r001477_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (helper_flow_4_1 ^ pub_r001477_18_1) & 63;
  int stage_v_165_2 = (helper_flow_4_2 ^ pub_r001477_18_2) & 63;
  if ((stage_v_165_1 & 1) != 0)
  {
    if ((stage_v_72_1 & 2) != 0)
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
    if ((stage_v_72_2 & 2) != 0)
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
  int stage_v_166_1 = (stage_v_96_1 ^ pub_r001477_7_1) & 63;
  int stage_v_166_2 = (stage_v_96_2 ^ pub_r001477_7_2) & 63;
  if ((stage_v_166_1 & 1) != 0)
  {
    if ((sec_r001477_1_1 & 2) != 0)
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
    if ((sec_r001477_1_2 & 2) != 0)
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
  int stage_v_167_1 = ((pub_r001477_0_1 * 2) + 21) & 63;
  int stage_v_167_2 = ((pub_r001477_0_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001477_13_1 * 2) + 5) & 63;
  int stage_v_168_2 = ((pub_r001477_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001477_5_1 * 2) + 26) & 63;
  int stage_v_169_2 = ((pub_r001477_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001477_17_1 * 2) + 46) & 63;
  int stage_v_170_2 = ((pub_r001477_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = (stage_v_156_1 ^ pub_r001477_7_1) & 63;
  int stage_v_171_2 = (stage_v_156_2 ^ pub_r001477_7_2) & 63;
  if ((stage_v_171_1 & 1) != 0)
  {
    if ((stage_v_18_1 & 2) != 0)
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
    if ((stage_v_18_2 & 2) != 0)
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
  int stage_v_172_1 = ((pub_r001477_8_1 * 2) + 40) & 63;
  int stage_v_172_2 = ((pub_r001477_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (stage_v_144_1 ^ pub_r001477_8_1) & 63;
  int stage_v_173_2 = (stage_v_144_2 ^ pub_r001477_8_2) & 63;
  if ((stage_v_173_1 & 1) != 0)
  {
    if ((sec_r001477_1_1 & 2) != 0)
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
    if ((sec_r001477_1_2 & 2) != 0)
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
  int stage_v_174_1 = (stage_v_78_1 ^ pub_r001477_13_1) & 63;
  int stage_v_174_2 = (stage_v_78_2 ^ pub_r001477_13_2) & 63;
  if ((stage_v_174_1 & 1) != 0)
  {
    if ((stage_v_67_1 & 2) != 0)
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
    if ((stage_v_67_2 & 2) != 0)
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
  int stage_v_175_1 = (stage_v_78_1 ^ pub_r001477_8_1) & 63;
  int stage_v_175_2 = (stage_v_78_2 ^ pub_r001477_8_2) & 63;
  if ((stage_v_175_1 & 1) != 0)
  {
    if ((stage_v_91_1 & 2) != 0)
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
    if ((stage_v_91_2 & 2) != 0)
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
  int stage_v_176_1 = (stage_v_23_1 ^ pub_r001477_1_1) & 63;
  int stage_v_176_2 = (stage_v_23_2 ^ pub_r001477_1_2) & 63;
  if ((stage_v_176_1 & 1) != 0)
  {
    if ((stage_v_28_1 & 2) != 0)
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
    if ((stage_v_28_2 & 2) != 0)
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
  int stage_v_177_1 = ((pub_r001477_12_1 * 2) + 37) & 63;
  int stage_v_177_2 = ((pub_r001477_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (stage_v_154_1 ^ pub_r001477_11_1) & 63;
  int stage_v_178_2 = (stage_v_154_2 ^ pub_r001477_11_2) & 63;
  if ((stage_v_178_1 & 1) != 0)
  {
    if ((stage_v_62_1 & 2) != 0)
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
    if ((stage_v_62_2 & 2) != 0)
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
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001477_13_1 == pub_r001477_13_2);
  __CPROVER_assume(pub_r001477_14_1 == pub_r001477_14_2);
  __CPROVER_assume(pub_r001477_4_1 == pub_r001477_4_2);
  __CPROVER_assume(pub_r001477_11_1 == pub_r001477_11_2);
  __CPROVER_assume(sec_r001477_2_1 != sec_r001477_2_2);
  __CPROVER_assume(pub_r001477_8_1 == pub_r001477_8_2);
  __CPROVER_assume(pub_r001477_10_1 == pub_r001477_10_2);
  __CPROVER_assume(sec_r001477_0_1 != sec_r001477_0_2);
  __CPROVER_assume(pub_r001477_7_1 == pub_r001477_7_2);
  __CPROVER_assume(pub_r001477_0_1 == pub_r001477_0_2);
  __CPROVER_assume(pub_r001477_18_1 == pub_r001477_18_2);
  __CPROVER_assume(sec_r001477_15_1 != sec_r001477_15_2);
  __CPROVER_assume(sec_r001477_17_1 != sec_r001477_17_2);
  __CPROVER_assume(pub_r001477_9_1 == pub_r001477_9_2);
  __CPROVER_assume(pub_r001477_16_1 == pub_r001477_16_2);
  __CPROVER_assume(pub_r001477_3_1 == pub_r001477_3_2);
  __CPROVER_assume(sec_r001477_13_1 != sec_r001477_13_2);
  __CPROVER_assume(sec_r001477_14_1 != sec_r001477_14_2);
  __CPROVER_assume(pub_r001477_17_1 == pub_r001477_17_2);
  __CPROVER_assume(pub_r001477_20_1 == pub_r001477_20_2);
  __CPROVER_assume(sec_r001477_4_1 != sec_r001477_4_2);
  __CPROVER_assume(pub_r001477_1_1 == pub_r001477_1_2);
  __CPROVER_assume(sec_r001477_12_1 != sec_r001477_12_2);
  __CPROVER_assume(sec_r001477_11_1 != sec_r001477_11_2);
  __CPROVER_assume(sec_r001477_7_1 != sec_r001477_7_2);
  __CPROVER_assume(sec_r001477_1_1 != sec_r001477_1_2);
  __CPROVER_assume(sec_r001477_5_1 != sec_r001477_5_2);
  __CPROVER_assume(pub_r001477_19_1 == pub_r001477_19_2);
  __CPROVER_assume(pub_r001477_6_1 == pub_r001477_6_2);
  __CPROVER_assume(pub_r001477_15_1 == pub_r001477_15_2);
  __CPROVER_assume(sec_r001477_16_1 != sec_r001477_16_2);
  __CPROVER_assume(pub_r001477_12_1 == pub_r001477_12_2);
  __CPROVER_assume(pub_r001477_5_1 == pub_r001477_5_2);
  __CPROVER_assume(sec_r001477_9_1 != sec_r001477_9_2);
  __CPROVER_assume(pub_r001477_2_1 == pub_r001477_2_2);
  __CPROVER_assume(sec_r001477_6_1 != sec_r001477_6_2);
  __CPROVER_assume(sec_r001477_3_1 != sec_r001477_3_2);
  __CPROVER_assume(sec_r001477_10_1 != sec_r001477_10_2);
  __CPROVER_assume(sec_r001477_8_1 != sec_r001477_8_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.nonce == st_var_1_2.nonce);
  assert(st_var_1_1.iv == st_var_1_2.iv);
  assert(st_var_1_1.flags == st_var_1_2.flags);
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
}


