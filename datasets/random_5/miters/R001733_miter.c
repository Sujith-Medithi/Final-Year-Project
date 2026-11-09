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
struct DeviceConfig_R001733_3313_0
{
  unsigned char parity;
  short id;
  int timeout;
  unsigned char baud_rate;
  unsigned char port;
  int buffer[3];
};
struct FilterState_R001733_3313_1
{
  short cutoff;
  int mode;
  int prev_in;
  int buffer[3];
};
struct EventLog_R001733_3313_2
{
  unsigned char signature;
  int timestamp;
  short code;
  int buffer[3];
};
union ColorPixel_R001733_3313_0
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
void fn_R001733_3313_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001733_3313_2 st_1 = {0};
  struct EventLog_R001733_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int tally_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_66_1)
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

  switch (tally_66_2)
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

  int index_reg_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_64_1) & 63;
  aux_2 = (aux_2 + index_reg_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_14_1 = 0;
  int stride_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_14_1 = ((stride_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_14_2 = ((stride_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_14_1) & 127;
    acc_2 = (acc_2 + stride_14_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_66_1 == tally_66_2);
  assert(index_reg_64_1 == index_reg_64_2);
  assert(stride_14_1 == stride_14_2);
}

int fn_R001733_3313_0(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001733_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int tally_66 = (aux + st.buffer[1]) & 3;
  switch (tally_66)
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

  int index_reg_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_64) & 63;
  acc ^= aux;
  int stride_14 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_14 = ((stride_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_14) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001733_3313_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001733_3313_1 st_1 = {0};
  struct FilterState_R001733_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int threshold_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_38_1) & 63;
  aux_2 = (aux_2 + threshold_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_74_1 = local_arr_1[aux_1 % 3];
  int scale_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_74_2 * 2)) & 127;
  int tally_88_1 = 0;
  int tally_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_88_1 = ((tally_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_88_2 = ((tally_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_88_1) & 127;
    acc_2 = (acc_2 + tally_88_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_38_1 == threshold_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_74_1 == scale_74_2);
  assert(tally_88_1 == tally_88_2);
}

int fn_R001733_3313_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001733_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int threshold_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_38) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_74 = local_arr[aux % 3];
  acc = (acc + (scale_74 * 2)) & 127;
  int tally_88 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_88 = ((tally_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_88) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001733_3313_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001733_3313_1 st_1 = {0};
  struct FilterState_R001733_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int anchor_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_52_1 > 22)
  {
    acc_1 = ((acc_1 + (anchor_52_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_52_2 > 22)
  {
    acc_2 = ((acc_2 + (anchor_52_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_52_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_22_1 = 0;
  int bound_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_22_1 = ((bound_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_22_2 = ((bound_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_22_1) & 127;
    acc_2 = (acc_2 + bound_22_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_52_1 == anchor_52_2);
  assert(bound_22_1 == bound_22_2);
}

int fn_R001733_3313_2(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001733_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int anchor_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_52 > 22)
  {
    acc = ((acc + (anchor_52 * 2)) + 5) & 127;
    aux ^= anchor_52 & 15;
  }
  else
  {
    acc = ((acc - anchor_52) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_22 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_22 = ((bound_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_22) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001733_3313_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001733_3313_2 st_1 = {0};
  struct EventLog_R001733_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int damping_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_84_1 > 36)
  {
    acc_1 = ((acc_1 + (damping_84_1 * 2)) + 5) & 127;
    aux_1 ^= damping_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_84_2 > 36)
  {
    acc_2 = ((acc_2 + (damping_84_2 * 2)) + 5) & 127;
    aux_2 ^= damping_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_73_1 = local_arr_1[aux_1 % 3];
  int factor_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_73_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_84_1 == damping_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_73_1 == factor_73_2);
}

int fn_R001733_3313_3(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001733_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int damping_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_84 > 36)
  {
    acc = ((acc + (damping_84 * 2)) + 5) & 127;
    aux ^= damping_84 & 15;
  }
  else
  {
    acc = ((acc - damping_84) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int factor_73 = local_arr[aux % 3];
  acc = (acc + (factor_73 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001733_3313_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001733_3313_2 st_1 = {0};
  struct EventLog_R001733_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int weight_12_1 = 0;
  int weight_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_12_1 = ((weight_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_12_2 = ((weight_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_12_1) & 127;
    acc_2 = (acc_2 + weight_12_2) & 127;
  }

  int offset_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_67_1) & 63;
  aux_2 = (aux_2 + offset_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_55_1 > 13)
  {
    acc_1 = ((acc_1 + (stride_55_1 * 2)) + 5) & 127;
    aux_1 ^= stride_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_55_2 > 13)
  {
    acc_2 = ((acc_2 + (stride_55_2 * 2)) + 5) & 127;
    aux_2 ^= stride_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_55_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_12_1 == weight_12_2);
  assert(offset_67_1 == offset_67_2);
  assert(stride_55_1 == stride_55_2);
}

int fn_R001733_3313_4(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001733_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int weight_12 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_12 = ((weight_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_12) & 127;
  }

  int offset_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_67) & 63;
  acc ^= aux;
  int stride_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_55 > 13)
  {
    acc = ((acc + (stride_55 * 2)) + 5) & 127;
    aux ^= stride_55 & 15;
  }
  else
  {
    acc = ((acc - stride_55) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001733_3313_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001733_3313_0 st_1 = {0};
  struct DeviceConfig_R001733_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int tracker_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_14_1) & 63;
  aux_2 = (aux_2 + tracker_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_78_1 = local_arr_1[aux_1 % 3];
  int sample_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_78_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_14_1 == tracker_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_78_1 == sample_78_2);
}

int fn_R001733_3313_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001733_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int tracker_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_14) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_78 = local_arr[aux % 3];
  acc = (acc + (sample_78 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001733_3313_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001733_3313_0 st_1 = {0};
  struct DeviceConfig_R001733_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int sample_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_14_1) & 63;
  aux_2 = (aux_2 + sample_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_92_1)
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

  switch (cursor_92_2)
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

  int tracker_57_1 = 0;
  int tracker_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_57_1 = ((tracker_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_57_2 = ((tracker_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_57_1) & 127;
    acc_2 = (acc_2 + tracker_57_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_15_1 = local_arr_1[aux_1 % 3];
  int delta_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_15_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_14_1 == sample_14_2);
  assert(cursor_92_1 == cursor_92_2);
  assert(tracker_57_1 == tracker_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_15_1 == delta_15_2);
}

int fn_R001733_3313_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001733_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int sample_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_14) & 63;
  acc ^= aux;
  int cursor_92 = (aux + st.buffer[1]) & 3;
  switch (cursor_92)
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

  int tracker_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_57 = ((tracker_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_57) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int delta_15 = local_arr[aux % 3];
  acc = (acc + (delta_15 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001733_3313_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001733_3313_1 st_1 = {0};
  struct FilterState_R001733_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int window_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_21_1) & 63;
  aux_2 = (aux_2 + window_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_78_1)
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

  switch (damping_78_2)
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
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_21_1 == window_21_2);
  assert(damping_78_1 == damping_78_2);
}

int fn_R001733_3313_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001733_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int window_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_21) & 63;
  acc ^= aux;
  int damping_78 = (aux + st.buffer[1]) & 3;
  switch (damping_78)
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

void fn_R001733_3313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001733_3313_1 st_1 = {0};
  struct FilterState_R001733_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int accumulator_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_73_1)
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

  switch (accumulator_73_2)
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

  int damping_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_90_1 > 21)
  {
    acc_1 = ((acc_1 + (damping_90_1 * 2)) + 5) & 127;
    aux_1 ^= damping_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_90_2 > 21)
  {
    acc_2 = ((acc_2 + (damping_90_2 * 2)) + 5) & 127;
    aux_2 ^= damping_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_90_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_74_1) & 63;
  aux_2 = (aux_2 + window_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_15_1 = 0;
  int quotient_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_15_1 = ((quotient_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_15_2 = ((quotient_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_15_1) & 127;
    acc_2 = (acc_2 + quotient_15_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_73_1 == accumulator_73_2);
  assert(damping_90_1 == damping_90_2);
  assert(window_74_1 == window_74_2);
  assert(quotient_15_1 == quotient_15_2);
}

int fn_R001733_3313_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001733_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int accumulator_73 = (aux + st.buffer[1]) & 3;
  switch (accumulator_73)
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

  int damping_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_90 > 21)
  {
    acc = ((acc + (damping_90 * 2)) + 5) & 127;
    aux ^= damping_90 & 15;
  }
  else
  {
    acc = ((acc - damping_90) + 11) & 127;
    aux += 3;
  }
  int window_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_74) & 63;
  acc ^= aux;
  int quotient_15 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_15 = ((quotient_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_15) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001733_3313_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001733_3313_1 st_1 = {0};
  struct FilterState_R001733_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int delta_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_89_1)
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

  switch (delta_89_2)
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

  int tally_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_20_1 > 40)
  {
    acc_1 = ((acc_1 + (tally_20_1 * 2)) + 5) & 127;
    aux_1 ^= tally_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_20_2 > 40)
  {
    acc_2 = ((acc_2 + (tally_20_2 * 2)) + 5) & 127;
    aux_2 ^= tally_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_55_1 = 0;
  int mask_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_55_1 = ((mask_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_55_2 = ((mask_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_55_1) & 127;
    acc_2 = (acc_2 + mask_55_2) & 127;
  }

  int residue_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_21_1) & 63;
  aux_2 = (aux_2 + residue_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_89_1 == delta_89_2);
  assert(tally_20_1 == tally_20_2);
  assert(mask_55_1 == mask_55_2);
  assert(residue_21_1 == residue_21_2);
}

int fn_R001733_3313_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001733_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int delta_89 = (aux + st.buffer[1]) & 3;
  switch (delta_89)
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

  int tally_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_20 > 40)
  {
    acc = ((acc + (tally_20 * 2)) + 5) & 127;
    aux ^= tally_20 & 15;
  }
  else
  {
    acc = ((acc - tally_20) + 11) & 127;
    aux += 3;
  }
  int mask_55 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_55 = ((mask_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_55) & 127;
  }

  int residue_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_21) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001733_3313_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001733_3313_2 st_1 = {0};
  struct EventLog_R001733_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int segment_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_58_1)
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

  switch (segment_58_2)
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

  int sample_69_1 = 0;
  int sample_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_69_1 = ((sample_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_69_2 = ((sample_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_69_1) & 127;
    acc_2 = (acc_2 + sample_69_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_58_1 == segment_58_2);
  assert(sample_69_1 == sample_69_2);
}

int fn_R001733_3313_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001733_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int segment_58 = (aux + st.buffer[1]) & 3;
  switch (segment_58)
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

  int sample_69 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_69 = ((sample_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_69) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001733_3313_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001733_3313_0 st_1 = {0};
  struct DeviceConfig_R001733_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int delta_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_18_1) & 63;
  aux_2 = (aux_2 + delta_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_35_1 > 30)
  {
    acc_1 = ((acc_1 + (residue_35_1 * 2)) + 5) & 127;
    aux_1 ^= residue_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_35_2 > 30)
  {
    acc_2 = ((acc_2 + (residue_35_2 * 2)) + 5) & 127;
    aux_2 ^= residue_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_35_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_12_1)
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

  switch (window_12_2)
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

  int segment_27_1 = 0;
  int segment_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_27_1 = ((segment_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_27_2 = ((segment_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_27_1) & 127;
    acc_2 = (acc_2 + segment_27_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_18_1 == delta_18_2);
  assert(residue_35_1 == residue_35_2);
  assert(window_12_1 == window_12_2);
  assert(segment_27_1 == segment_27_2);
}

int fn_R001733_3313_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001733_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int delta_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_18) & 63;
  acc ^= aux;
  int residue_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_35 > 30)
  {
    acc = ((acc + (residue_35 * 2)) + 5) & 127;
    aux ^= residue_35 & 15;
  }
  else
  {
    acc = ((acc - residue_35) + 11) & 127;
    aux += 3;
  }
  int window_12 = (aux + st.buffer[1]) & 3;
  switch (window_12)
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

  int segment_27 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_27 = ((segment_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_27) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001733_3313_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001733_3313_0 st_1 = {0};
  struct DeviceConfig_R001733_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_60_1 = local_arr_1[aux_1 % 3];
  int damping_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_60_2 * 2)) & 127;
  int cursor_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_77_1 > 12)
  {
    acc_1 = ((acc_1 + (cursor_77_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_77_2 > 12)
  {
    acc_2 = ((acc_2 + (cursor_77_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_77_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_60_1 == damping_60_2);
  assert(cursor_77_1 == cursor_77_2);
}

int fn_R001733_3313_12(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001733_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int damping_60 = local_arr[aux % 3];
  acc = (acc + (damping_60 * 2)) & 127;
  int cursor_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_77 > 12)
  {
    acc = ((acc + (cursor_77 * 2)) + 5) & 127;
    aux ^= cursor_77 & 15;
  }
  else
  {
    acc = ((acc - cursor_77) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001733_3313_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001733_3313_2 st_1 = {0};
  struct EventLog_R001733_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_88_1 = local_arr_1[aux_1 % 3];
  int mask_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_88_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_87_1) & 63;
  aux_2 = (aux_2 + damping_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_88_1 == mask_88_2);
  assert(damping_87_1 == damping_87_2);
}

int fn_R001733_3313_13(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001733_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int mask_88 = local_arr[aux % 3];
  acc = (acc + (mask_88 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_87) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001733_3313_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001733_3313_2 st_1 = {0};
  struct EventLog_R001733_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int anchor_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_11_1) & 63;
  aux_2 = (aux_2 + anchor_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_95_1)
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

  switch (anchor_95_2)
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

  int damping_24_1 = 0;
  int damping_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_24_1 = ((damping_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_24_2 = ((damping_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_24_1) & 127;
    acc_2 = (acc_2 + damping_24_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_11_1 == anchor_11_2);
  assert(anchor_95_1 == anchor_95_2);
  assert(damping_24_1 == damping_24_2);
}

int fn_R001733_3313_14(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001733_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int anchor_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_11) & 63;
  acc ^= aux;
  int anchor_95 = (aux + st.buffer[1]) & 3;
  switch (anchor_95)
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

  int damping_24 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_24 = ((damping_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_24) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001733_3313_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001733_3313_1 st_1 = {0};
  struct FilterState_R001733_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int bound_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_90_1 > 26)
  {
    acc_1 = ((acc_1 + (bound_90_1 * 2)) + 5) & 127;
    aux_1 ^= bound_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_90_2 > 26)
  {
    acc_2 = ((acc_2 + (bound_90_2 * 2)) + 5) & 127;
    aux_2 ^= bound_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_90_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_20_1 = 0;
  int cursor_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_20_1 = ((cursor_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_20_2 = ((cursor_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_20_1) & 127;
    acc_2 = (acc_2 + cursor_20_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_16_1 = local_arr_1[aux_1 % 3];
  int factor_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_16_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_90_1 == bound_90_2);
  assert(cursor_20_1 == cursor_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_16_1 == factor_16_2);
}

int fn_R001733_3313_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001733_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int bound_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_90 > 26)
  {
    acc = ((acc + (bound_90 * 2)) + 5) & 127;
    aux ^= bound_90 & 15;
  }
  else
  {
    acc = ((acc - bound_90) + 11) & 127;
    aux += 3;
  }
  int cursor_20 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_20 = ((cursor_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_20) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int factor_16 = local_arr[aux % 3];
  acc = (acc + (factor_16 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001733_3313_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001733_3313_2 st_1 = {0};
  struct EventLog_R001733_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int offset_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_81_1)
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

  switch (offset_81_2)
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

  int damping_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_46_1 > 45)
  {
    acc_1 = ((acc_1 + (damping_46_1 * 2)) + 5) & 127;
    aux_1 ^= damping_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_46_2 > 45)
  {
    acc_2 = ((acc_2 + (damping_46_2 * 2)) + 5) & 127;
    aux_2 ^= damping_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_46_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_81_1 == offset_81_2);
  assert(damping_46_1 == damping_46_2);
}

int fn_R001733_3313_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001733_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int offset_81 = (aux + st.buffer[1]) & 3;
  switch (offset_81)
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

  int damping_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_46 > 45)
  {
    acc = ((acc + (damping_46 * 2)) + 5) & 127;
    aux ^= damping_46 & 15;
  }
  else
  {
    acc = ((acc - damping_46) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001733_3313_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001733_3313_0 st_1 = {0};
  struct DeviceConfig_R001733_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int threshold_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_10_1)
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

  switch (threshold_10_2)
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

  int accumulator_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_45_1 > 25)
  {
    acc_1 = ((acc_1 + (accumulator_45_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_45_2 > 25)
  {
    acc_2 = ((acc_2 + (accumulator_45_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_51_1 = 0;
  int metric_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_51_1 = ((metric_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_51_2 = ((metric_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_51_1) & 127;
    acc_2 = (acc_2 + metric_51_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_10_1 == threshold_10_2);
  assert(accumulator_45_1 == accumulator_45_2);
  assert(metric_51_1 == metric_51_2);
}

int fn_R001733_3313_17(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001733_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int threshold_10 = (aux + st.buffer[1]) & 3;
  switch (threshold_10)
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

  int accumulator_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_45 > 25)
  {
    acc = ((acc + (accumulator_45 * 2)) + 5) & 127;
    aux ^= accumulator_45 & 15;
  }
  else
  {
    acc = ((acc - accumulator_45) + 11) & 127;
    aux += 3;
  }
  int metric_51 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_51 = ((metric_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_51) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001733_3313_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001733_3313_1 st_1 = {0};
  struct FilterState_R001733_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int anchor_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_36_1 > 36)
  {
    acc_1 = ((acc_1 + (anchor_36_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_36_2 > 36)
  {
    acc_2 = ((acc_2 + (anchor_36_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_46_1 = local_arr_1[aux_1 % 3];
  int threshold_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_46_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_36_1 == anchor_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_46_1 == threshold_46_2);
}

int fn_R001733_3313_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001733_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int anchor_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_36 > 36)
  {
    acc = ((acc + (anchor_36 * 2)) + 5) & 127;
    aux ^= anchor_36 & 15;
  }
  else
  {
    acc = ((acc - anchor_36) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_46 = local_arr[aux % 3];
  acc = (acc + (threshold_46 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001733_3313_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001733_3313_2 st_1 = {0};
  struct EventLog_R001733_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int accumulator_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_63_1) & 63;
  aux_2 = (aux_2 + accumulator_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_74_1 = 0;
  int index_reg_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_74_1 = ((index_reg_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_74_2 = ((index_reg_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_74_1) & 127;
    acc_2 = (acc_2 + index_reg_74_2) & 127;
  }

  int coefficient_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_78_1)
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

  switch (coefficient_78_2)
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
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_63_1 == accumulator_63_2);
  assert(index_reg_74_1 == index_reg_74_2);
  assert(coefficient_78_1 == coefficient_78_2);
}

int fn_R001733_3313_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001733_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int accumulator_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_63) & 63;
  acc ^= aux;
  int index_reg_74 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_74 = ((index_reg_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_74) & 127;
  }

  int coefficient_78 = (aux + st.buffer[1]) & 3;
  switch (coefficient_78)
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

void main()
{
  int sec_r001733_0_1;
  int sec_r001733_0_2;
  int sec_r001733_1_1;
  int sec_r001733_1_2;
  int sec_r001733_2_1;
  int sec_r001733_2_2;
  int sec_r001733_3_1;
  int sec_r001733_3_2;
  int sec_r001733_4_1;
  int sec_r001733_4_2;
  int sec_r001733_5_1;
  int sec_r001733_5_2;
  int sec_r001733_6_1;
  int sec_r001733_6_2;
  int sec_r001733_7_1;
  int sec_r001733_7_2;
  int sec_r001733_8_1;
  int sec_r001733_8_2;
  int sec_r001733_9_1;
  int sec_r001733_9_2;
  int sec_r001733_10_1;
  int sec_r001733_10_2;
  int sec_r001733_11_1;
  int sec_r001733_11_2;
  int sec_r001733_12_1;
  int sec_r001733_12_2;
  int sec_r001733_13_1;
  int sec_r001733_13_2;
  int sec_r001733_14_1;
  int sec_r001733_14_2;
  int sec_r001733_15_1;
  int sec_r001733_15_2;
  int sec_r001733_16_1;
  int sec_r001733_16_2;
  int sec_r001733_17_1;
  int sec_r001733_17_2;
  int pub_r001733_0_1;
  int pub_r001733_0_2;
  int pub_r001733_1_1;
  int pub_r001733_1_2;
  int pub_r001733_2_1;
  int pub_r001733_2_2;
  int pub_r001733_3_1;
  int pub_r001733_3_2;
  int pub_r001733_4_1;
  int pub_r001733_4_2;
  int pub_r001733_5_1;
  int pub_r001733_5_2;
  int pub_r001733_6_1;
  int pub_r001733_6_2;
  int pub_r001733_7_1;
  int pub_r001733_7_2;
  int pub_r001733_8_1;
  int pub_r001733_8_2;
  int pub_r001733_9_1;
  int pub_r001733_9_2;
  int pub_r001733_10_1;
  int pub_r001733_10_2;
  int pub_r001733_11_1;
  int pub_r001733_11_2;
  int pub_r001733_12_1;
  int pub_r001733_12_2;
  int pub_r001733_13_1;
  int pub_r001733_13_2;
  int pub_r001733_14_1;
  int pub_r001733_14_2;
  int pub_r001733_15_1;
  int pub_r001733_15_2;
  int pub_r001733_16_1;
  int pub_r001733_16_2;
  int pub_r001733_17_1;
  int pub_r001733_17_2;
  int pub_r001733_18_1;
  int pub_r001733_18_2;
  int pub_r001733_19_1;
  int pub_r001733_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001733_0_1 >= (-100)) && (pub_r001733_0_1 <= 100));
  __CPROVER_assume((pub_r001733_0_2 >= (-100)) && (pub_r001733_0_2 <= 100));
  __CPROVER_assume((pub_r001733_1_1 >= (-100)) && (pub_r001733_1_1 <= 100));
  __CPROVER_assume((pub_r001733_1_2 >= (-100)) && (pub_r001733_1_2 <= 100));
  __CPROVER_assume((pub_r001733_2_1 >= (-100)) && (pub_r001733_2_1 <= 100));
  __CPROVER_assume((pub_r001733_2_2 >= (-100)) && (pub_r001733_2_2 <= 100));
  __CPROVER_assume((pub_r001733_3_1 >= (-100)) && (pub_r001733_3_1 <= 100));
  __CPROVER_assume((pub_r001733_3_2 >= (-100)) && (pub_r001733_3_2 <= 100));
  __CPROVER_assume((pub_r001733_4_1 >= (-100)) && (pub_r001733_4_1 <= 100));
  __CPROVER_assume((pub_r001733_4_2 >= (-100)) && (pub_r001733_4_2 <= 100));
  __CPROVER_assume((pub_r001733_5_1 >= (-100)) && (pub_r001733_5_1 <= 100));
  __CPROVER_assume((pub_r001733_5_2 >= (-100)) && (pub_r001733_5_2 <= 100));
  __CPROVER_assume((pub_r001733_6_1 >= (-100)) && (pub_r001733_6_1 <= 100));
  __CPROVER_assume((pub_r001733_6_2 >= (-100)) && (pub_r001733_6_2 <= 100));
  __CPROVER_assume((pub_r001733_7_1 >= (-100)) && (pub_r001733_7_1 <= 100));
  __CPROVER_assume((pub_r001733_7_2 >= (-100)) && (pub_r001733_7_2 <= 100));
  __CPROVER_assume((pub_r001733_8_1 >= (-100)) && (pub_r001733_8_1 <= 100));
  __CPROVER_assume((pub_r001733_8_2 >= (-100)) && (pub_r001733_8_2 <= 100));
  __CPROVER_assume((pub_r001733_9_1 >= (-100)) && (pub_r001733_9_1 <= 100));
  __CPROVER_assume((pub_r001733_9_2 >= (-100)) && (pub_r001733_9_2 <= 100));
  __CPROVER_assume((pub_r001733_10_1 >= (-100)) && (pub_r001733_10_1 <= 100));
  __CPROVER_assume((pub_r001733_10_2 >= (-100)) && (pub_r001733_10_2 <= 100));
  __CPROVER_assume((pub_r001733_11_1 >= (-100)) && (pub_r001733_11_1 <= 100));
  __CPROVER_assume((pub_r001733_11_2 >= (-100)) && (pub_r001733_11_2 <= 100));
  __CPROVER_assume((pub_r001733_12_1 >= (-100)) && (pub_r001733_12_1 <= 100));
  __CPROVER_assume((pub_r001733_12_2 >= (-100)) && (pub_r001733_12_2 <= 100));
  __CPROVER_assume((pub_r001733_13_1 >= (-100)) && (pub_r001733_13_1 <= 100));
  __CPROVER_assume((pub_r001733_13_2 >= (-100)) && (pub_r001733_13_2 <= 100));
  __CPROVER_assume((pub_r001733_14_1 >= (-100)) && (pub_r001733_14_1 <= 100));
  __CPROVER_assume((pub_r001733_14_2 >= (-100)) && (pub_r001733_14_2 <= 100));
  __CPROVER_assume((pub_r001733_15_1 >= (-100)) && (pub_r001733_15_1 <= 100));
  __CPROVER_assume((pub_r001733_15_2 >= (-100)) && (pub_r001733_15_2 <= 100));
  __CPROVER_assume((pub_r001733_16_1 >= (-100)) && (pub_r001733_16_1 <= 100));
  __CPROVER_assume((pub_r001733_16_2 >= (-100)) && (pub_r001733_16_2 <= 100));
  __CPROVER_assume((pub_r001733_17_1 >= (-100)) && (pub_r001733_17_1 <= 100));
  __CPROVER_assume((pub_r001733_17_2 >= (-100)) && (pub_r001733_17_2 <= 100));
  __CPROVER_assume((pub_r001733_18_1 >= (-100)) && (pub_r001733_18_1 <= 100));
  __CPROVER_assume((pub_r001733_18_2 >= (-100)) && (pub_r001733_18_2 <= 100));
  __CPROVER_assume((pub_r001733_19_1 >= (-100)) && (pub_r001733_19_1 <= 100));
  __CPROVER_assume((pub_r001733_19_2 >= (-100)) && (pub_r001733_19_2 <= 100));
  __CPROVER_assume((sec_r001733_0_1 >= 0) && (sec_r001733_0_1 <= 255));
  __CPROVER_assume((sec_r001733_0_2 >= 0) && (sec_r001733_0_2 <= 255));
  __CPROVER_assume((sec_r001733_1_1 >= 0) && (sec_r001733_1_1 <= 255));
  __CPROVER_assume((sec_r001733_1_2 >= 0) && (sec_r001733_1_2 <= 255));
  __CPROVER_assume((sec_r001733_2_1 >= 0) && (sec_r001733_2_1 <= 255));
  __CPROVER_assume((sec_r001733_2_2 >= 0) && (sec_r001733_2_2 <= 255));
  __CPROVER_assume((sec_r001733_3_1 >= 0) && (sec_r001733_3_1 <= 255));
  __CPROVER_assume((sec_r001733_3_2 >= 0) && (sec_r001733_3_2 <= 255));
  __CPROVER_assume((sec_r001733_4_1 >= 0) && (sec_r001733_4_1 <= 255));
  __CPROVER_assume((sec_r001733_4_2 >= 0) && (sec_r001733_4_2 <= 255));
  __CPROVER_assume((sec_r001733_5_1 >= 0) && (sec_r001733_5_1 <= 255));
  __CPROVER_assume((sec_r001733_5_2 >= 0) && (sec_r001733_5_2 <= 255));
  __CPROVER_assume((sec_r001733_6_1 >= 0) && (sec_r001733_6_1 <= 255));
  __CPROVER_assume((sec_r001733_6_2 >= 0) && (sec_r001733_6_2 <= 255));
  __CPROVER_assume((sec_r001733_7_1 >= 0) && (sec_r001733_7_1 <= 255));
  __CPROVER_assume((sec_r001733_7_2 >= 0) && (sec_r001733_7_2 <= 255));
  __CPROVER_assume((sec_r001733_8_1 >= 0) && (sec_r001733_8_1 <= 255));
  __CPROVER_assume((sec_r001733_8_2 >= 0) && (sec_r001733_8_2 <= 255));
  __CPROVER_assume((sec_r001733_9_1 >= 0) && (sec_r001733_9_1 <= 255));
  __CPROVER_assume((sec_r001733_9_2 >= 0) && (sec_r001733_9_2 <= 255));
  __CPROVER_assume((sec_r001733_10_1 >= 0) && (sec_r001733_10_1 <= 255));
  __CPROVER_assume((sec_r001733_10_2 >= 0) && (sec_r001733_10_2 <= 255));
  __CPROVER_assume((sec_r001733_11_1 >= 0) && (sec_r001733_11_1 <= 255));
  __CPROVER_assume((sec_r001733_11_2 >= 0) && (sec_r001733_11_2 <= 255));
  __CPROVER_assume((sec_r001733_12_1 >= 0) && (sec_r001733_12_1 <= 255));
  __CPROVER_assume((sec_r001733_12_2 >= 0) && (sec_r001733_12_2 <= 255));
  __CPROVER_assume((sec_r001733_13_1 >= 0) && (sec_r001733_13_1 <= 255));
  __CPROVER_assume((sec_r001733_13_2 >= 0) && (sec_r001733_13_2 <= 255));
  __CPROVER_assume((sec_r001733_14_1 >= 0) && (sec_r001733_14_1 <= 255));
  __CPROVER_assume((sec_r001733_14_2 >= 0) && (sec_r001733_14_2 <= 255));
  __CPROVER_assume((sec_r001733_15_1 >= 0) && (sec_r001733_15_1 <= 255));
  __CPROVER_assume((sec_r001733_15_2 >= 0) && (sec_r001733_15_2 <= 255));
  __CPROVER_assume((sec_r001733_16_1 >= 0) && (sec_r001733_16_1 <= 255));
  __CPROVER_assume((sec_r001733_16_2 >= 0) && (sec_r001733_16_2 <= 255));
  __CPROVER_assume((sec_r001733_17_1 >= 0) && (sec_r001733_17_1 <= 255));
  __CPROVER_assume((sec_r001733_17_2 >= 0) && (sec_r001733_17_2 <= 255));
  struct DeviceConfig_R001733_3313_0 st_var_0_1 = {0};
  struct DeviceConfig_R001733_3313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001733_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001733_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001733_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001733_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001733_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001733_0_2 + 7) & 15;
  struct FilterState_R001733_3313_1 st_var_1_1 = {0};
  struct FilterState_R001733_3313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001733_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001733_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001733_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001733_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001733_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001733_0_2 + 9) & 15;
  struct EventLog_R001733_3313_2 st_var_2_1 = {0};
  struct EventLog_R001733_3313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001733_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001733_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001733_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001733_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001733_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001733_0_2 + 11) & 15;
  union ColorPixel_R001733_3313_0 u_var_1;
  union ColorPixel_R001733_3313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001733_3313_0(sec_r001733_0_1, sec_r001733_1_1, pub_r001733_2_1);
  int helper_flow_0_2 = fn_R001733_3313_0(sec_r001733_0_2, sec_r001733_1_2, pub_r001733_2_2);
  fn_R001733_3313_0_2(sec_r001733_0_1, sec_r001733_1_1, pub_r001733_2_1, sec_r001733_0_2, sec_r001733_1_2, pub_r001733_2_2);
  int helper_flow_1_1 = fn_R001733_3313_1(sec_r001733_1_1, sec_r001733_2_1, pub_r001733_3_1, pub_r001733_4_1);
  int helper_flow_1_2 = fn_R001733_3313_1(sec_r001733_1_2, sec_r001733_2_2, pub_r001733_3_2, pub_r001733_4_2);
  fn_R001733_3313_1_2(sec_r001733_1_1, sec_r001733_2_1, pub_r001733_3_1, pub_r001733_4_1, sec_r001733_1_2, sec_r001733_2_2, pub_r001733_3_2, pub_r001733_4_2);
  int helper_flow_2_1 = fn_R001733_3313_2(sec_r001733_2_1, pub_r001733_3_1);
  int helper_flow_2_2 = fn_R001733_3313_2(sec_r001733_2_2, pub_r001733_3_2);
  fn_R001733_3313_2_2(sec_r001733_2_1, pub_r001733_3_1, sec_r001733_2_2, pub_r001733_3_2);
  int helper_flow_3_1 = fn_R001733_3313_3(sec_r001733_3_1, sec_r001733_4_1, pub_r001733_5_1);
  int helper_flow_3_2 = fn_R001733_3313_3(sec_r001733_3_2, sec_r001733_4_2, pub_r001733_5_2);
  fn_R001733_3313_3_2(sec_r001733_3_1, sec_r001733_4_1, pub_r001733_5_1, sec_r001733_3_2, sec_r001733_4_2, pub_r001733_5_2);
  int helper_flow_4_1 = fn_R001733_3313_4(sec_r001733_4_1, pub_r001733_5_1);
  int helper_flow_4_2 = fn_R001733_3313_4(sec_r001733_4_2, pub_r001733_5_2);
  fn_R001733_3313_4_2(sec_r001733_4_1, pub_r001733_5_1, sec_r001733_4_2, pub_r001733_5_2);
  int helper_flow_5_1 = fn_R001733_3313_5(sec_r001733_5_1, pub_r001733_6_1, pub_r001733_7_1, pub_r001733_8_1, pub_r001733_9_1);
  int helper_flow_5_2 = fn_R001733_3313_5(sec_r001733_5_2, pub_r001733_6_2, pub_r001733_7_2, pub_r001733_8_2, pub_r001733_9_2);
  fn_R001733_3313_5_2(sec_r001733_5_1, pub_r001733_6_1, pub_r001733_7_1, pub_r001733_8_1, pub_r001733_9_1, sec_r001733_5_2, pub_r001733_6_2, pub_r001733_7_2, pub_r001733_8_2, pub_r001733_9_2);
  int helper_flow_6_1 = fn_R001733_3313_6(sec_r001733_6_1, sec_r001733_7_1, pub_r001733_8_1, pub_r001733_9_1, pub_r001733_10_1);
  int helper_flow_6_2 = fn_R001733_3313_6(sec_r001733_6_2, sec_r001733_7_2, pub_r001733_8_2, pub_r001733_9_2, pub_r001733_10_2);
  fn_R001733_3313_6_2(sec_r001733_6_1, sec_r001733_7_1, pub_r001733_8_1, pub_r001733_9_1, pub_r001733_10_1, sec_r001733_6_2, sec_r001733_7_2, pub_r001733_8_2, pub_r001733_9_2, pub_r001733_10_2);
  int helper_flow_7_1 = fn_R001733_3313_7(sec_r001733_7_1, sec_r001733_8_1, pub_r001733_9_1, pub_r001733_10_1);
  int helper_flow_7_2 = fn_R001733_3313_7(sec_r001733_7_2, sec_r001733_8_2, pub_r001733_9_2, pub_r001733_10_2);
  fn_R001733_3313_7_2(sec_r001733_7_1, sec_r001733_8_1, pub_r001733_9_1, pub_r001733_10_1, sec_r001733_7_2, sec_r001733_8_2, pub_r001733_9_2, pub_r001733_10_2);
  int stage_v_0_1 = (((helper_flow_3_1 * 3) + pub_r001733_0_1) + 31) & 127;
  int stage_v_0_2 = (((helper_flow_3_2 * 3) + pub_r001733_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = ((pub_r001733_7_1 * 2) + 16) & 63;
  int stage_v_1_2 = ((pub_r001733_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((sec_r001733_1_1 * 3) + pub_r001733_11_1) + 15) & 127;
  int stage_v_2_2 = (((sec_r001733_1_2 * 3) + pub_r001733_11_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = ((pub_r001733_4_1 * 2) + 39) & 63;
  int stage_v_3_2 = ((pub_r001733_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (((helper_flow_5_1 * 3) + pub_r001733_6_1) + 20) & 127;
  int stage_v_4_2 = (((helper_flow_5_2 * 3) + pub_r001733_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = ((pub_r001733_11_1 * 2) + 35) & 63;
  int stage_v_5_2 = ((pub_r001733_11_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001733_16_1 * 2) + 32) & 63;
  int stage_v_6_2 = ((pub_r001733_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001733_17_1 * 2) + 7) & 63;
  int stage_v_7_2 = ((pub_r001733_17_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (((sec_r001733_10_1 * 3) + pub_r001733_9_1) + 35) & 127;
  int stage_v_8_2 = (((sec_r001733_10_2 * 3) + pub_r001733_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = (((sec_r001733_13_1 * 3) + pub_r001733_18_1) + 28) & 127;
  int stage_v_9_2 = (((sec_r001733_13_2 * 3) + pub_r001733_18_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = ((pub_r001733_0_1 * 2) + 48) & 63;
  int stage_v_10_2 = ((pub_r001733_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (((helper_flow_6_1 * 3) + pub_r001733_8_1) + 25) & 127;
  int stage_v_11_2 = (((helper_flow_6_2 * 3) + pub_r001733_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = (((sec_r001733_8_1 * 3) + pub_r001733_14_1) + 33) & 127;
  int stage_v_12_2 = (((sec_r001733_8_2 * 3) + pub_r001733_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = (((stage_v_8_1 * 3) + pub_r001733_5_1) + 20) & 127;
  int stage_v_13_2 = (((stage_v_8_2 * 3) + pub_r001733_5_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = (((stage_v_8_1 * 3) + pub_r001733_9_1) + 33) & 127;
  int stage_v_14_2 = (((stage_v_8_2 * 3) + pub_r001733_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = (((sec_r001733_11_1 * 3) + pub_r001733_8_1) + 28) & 127;
  int stage_v_15_2 = (((sec_r001733_11_2 * 3) + pub_r001733_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = ((pub_r001733_2_1 * 2) + 39) & 63;
  int stage_v_16_2 = ((pub_r001733_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (((stage_v_4_1 * 3) + pub_r001733_12_1) + 43) & 127;
  int stage_v_17_2 = (((stage_v_4_2 * 3) + pub_r001733_12_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = (((stage_v_0_1 * 3) + pub_r001733_2_1) + 32) & 127;
  int stage_v_18_2 = (((stage_v_0_2 * 3) + pub_r001733_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = (((stage_v_9_1 * 3) + pub_r001733_17_1) + 8) & 127;
  int stage_v_19_2 = (((stage_v_9_2 * 3) + pub_r001733_17_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = (((sec_r001733_4_1 * 3) + pub_r001733_14_1) + 38) & 127;
  int stage_v_20_2 = (((sec_r001733_4_2 * 3) + pub_r001733_14_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = (((sec_r001733_15_1 * 3) + pub_r001733_7_1) + 8) & 127;
  int stage_v_21_2 = (((sec_r001733_15_2 * 3) + pub_r001733_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = (((stage_v_11_1 * 3) + pub_r001733_19_1) + 39) & 127;
  int stage_v_22_2 = (((stage_v_11_2 * 3) + pub_r001733_19_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = (((stage_v_4_1 * 3) + pub_r001733_15_1) + 33) & 127;
  int stage_v_23_2 = (((stage_v_4_2 * 3) + pub_r001733_15_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = ((pub_r001733_11_1 * 2) + 36) & 63;
  int stage_v_24_2 = ((pub_r001733_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001733_8_1 * 2) + 23) & 63;
  int stage_v_25_2 = ((pub_r001733_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001733_16_1 * 2) + 19) & 63;
  int stage_v_26_2 = ((pub_r001733_16_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001733_7_1 * 2) + 35) & 63;
  int stage_v_27_2 = ((pub_r001733_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((sec_r001733_9_1 * 3) + pub_r001733_1_1) + 18) & 127;
  int stage_v_28_2 = (((sec_r001733_9_2 * 3) + pub_r001733_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = (((helper_flow_2_1 * 3) + pub_r001733_2_1) + 36) & 127;
  int stage_v_29_2 = (((helper_flow_2_2 * 3) + pub_r001733_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = (((stage_v_4_1 * 3) + pub_r001733_1_1) + 13) & 127;
  int stage_v_30_2 = (((stage_v_4_2 * 3) + pub_r001733_1_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = ((pub_r001733_6_1 * 2) + 6) & 63;
  int stage_v_31_2 = ((pub_r001733_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001733_2_1 * 2) + 41) & 63;
  int stage_v_32_2 = ((pub_r001733_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001733_6_1 * 2) + 25) & 63;
  int stage_v_33_2 = ((pub_r001733_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (((helper_flow_0_1 * 3) + pub_r001733_17_1) + 36) & 127;
  int stage_v_34_2 = (((helper_flow_0_2 * 3) + pub_r001733_17_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = ((pub_r001733_3_1 * 2) + 45) & 63;
  int stage_v_35_2 = ((pub_r001733_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001733_3_1 * 2) + 13) & 63;
  int stage_v_36_2 = ((pub_r001733_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (((sec_r001733_6_1 * 3) + pub_r001733_2_1) + 24) & 127;
  int stage_v_37_2 = (((sec_r001733_6_2 * 3) + pub_r001733_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = (((stage_v_14_1 * 3) + pub_r001733_7_1) + 15) & 127;
  int stage_v_38_2 = (((stage_v_14_2 * 3) + pub_r001733_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = ((pub_r001733_15_1 * 2) + 43) & 63;
  int stage_v_39_2 = ((pub_r001733_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((stage_v_18_1 * 3) + pub_r001733_4_1) + 32) & 127;
  int stage_v_40_2 = (((stage_v_18_2 * 3) + pub_r001733_4_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = (((sec_r001733_6_1 * 3) + pub_r001733_6_1) + 13) & 127;
  int stage_v_41_2 = (((sec_r001733_6_2 * 3) + pub_r001733_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = ((pub_r001733_2_1 * 2) + 44) & 63;
  int stage_v_42_2 = ((pub_r001733_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((helper_flow_1_1 * 3) + pub_r001733_15_1) + 24) & 127;
  int stage_v_43_2 = (((helper_flow_1_2 * 3) + pub_r001733_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = (((helper_flow_6_1 * 3) + pub_r001733_11_1) + 14) & 127;
  int stage_v_44_2 = (((helper_flow_6_2 * 3) + pub_r001733_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = (((stage_v_0_1 * 3) + pub_r001733_6_1) + 38) & 127;
  int stage_v_45_2 = (((stage_v_0_2 * 3) + pub_r001733_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = (((stage_v_40_1 * 3) + pub_r001733_7_1) + 34) & 127;
  int stage_v_46_2 = (((stage_v_40_2 * 3) + pub_r001733_7_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = (((sec_r001733_17_1 * 3) + pub_r001733_10_1) + 41) & 127;
  int stage_v_47_2 = (((sec_r001733_17_2 * 3) + pub_r001733_10_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = (((stage_v_17_1 * 3) + pub_r001733_1_1) + 22) & 127;
  int stage_v_48_2 = (((stage_v_17_2 * 3) + pub_r001733_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = ((pub_r001733_4_1 * 2) + 13) & 63;
  int stage_v_49_2 = ((pub_r001733_4_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001733_4_1 * 2) + 8) & 63;
  int stage_v_50_2 = ((pub_r001733_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001733_11_1 * 2) + 45) & 63;
  int stage_v_51_2 = ((pub_r001733_11_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001733_12_1 * 2) + 7) & 63;
  int stage_v_52_2 = ((pub_r001733_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001733_18_1 * 2) + 19) & 63;
  int stage_v_53_2 = ((pub_r001733_18_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001733_0_1 * 2) + 13) & 63;
  int stage_v_54_2 = ((pub_r001733_0_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001733_11_1 * 2) + 50) & 63;
  int stage_v_55_2 = ((pub_r001733_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = (((stage_v_37_1 * 3) + pub_r001733_12_1) + 44) & 127;
  int stage_v_56_2 = (((stage_v_37_2 * 3) + pub_r001733_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = ((pub_r001733_7_1 * 2) + 12) & 63;
  int stage_v_57_2 = ((pub_r001733_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = (((stage_v_19_1 * 3) + pub_r001733_7_1) + 5) & 127;
  int stage_v_58_2 = (((stage_v_19_2 * 3) + pub_r001733_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = (((stage_v_48_1 * 3) + pub_r001733_18_1) + 20) & 127;
  int stage_v_59_2 = (((stage_v_48_2 * 3) + pub_r001733_18_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = ((pub_r001733_2_1 * 2) + 33) & 63;
  int stage_v_60_2 = ((pub_r001733_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((stage_v_59_1 * 3) + pub_r001733_5_1) + 21) & 127;
  int stage_v_61_2 = (((stage_v_59_2 * 3) + pub_r001733_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001733_13_1 * 2) + 6) & 63;
  int stage_v_62_2 = ((pub_r001733_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001733_15_1 * 2) + 27) & 63;
  int stage_v_63_2 = ((pub_r001733_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (((stage_v_45_1 * 3) + pub_r001733_5_1) + 41) & 127;
  int stage_v_64_2 = (((stage_v_45_2 * 3) + pub_r001733_5_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = (((sec_r001733_6_1 * 3) + pub_r001733_18_1) + 38) & 127;
  int stage_v_65_2 = (((sec_r001733_6_2 * 3) + pub_r001733_18_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = (((stage_v_61_1 * 3) + pub_r001733_4_1) + 5) & 127;
  int stage_v_66_2 = (((stage_v_61_2 * 3) + pub_r001733_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = (((stage_v_58_1 * 3) + pub_r001733_10_1) + 33) & 127;
  int stage_v_67_2 = (((stage_v_58_2 * 3) + pub_r001733_10_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = ((pub_r001733_8_1 * 2) + 47) & 63;
  int stage_v_68_2 = ((pub_r001733_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = (((helper_flow_5_1 * 3) + pub_r001733_13_1) + 23) & 127;
  int stage_v_69_2 = (((helper_flow_5_2 * 3) + pub_r001733_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = (((sec_r001733_3_1 * 3) + pub_r001733_10_1) + 20) & 127;
  int stage_v_70_2 = (((sec_r001733_3_2 * 3) + pub_r001733_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = (((sec_r001733_17_1 * 3) + pub_r001733_17_1) + 26) & 127;
  int stage_v_71_2 = (((sec_r001733_17_2 * 3) + pub_r001733_17_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = ((pub_r001733_7_1 * 2) + 47) & 63;
  int stage_v_72_2 = ((pub_r001733_7_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((helper_flow_6_1 * 3) + pub_r001733_0_1) + 19) & 127;
  int stage_v_73_2 = (((helper_flow_6_2 * 3) + pub_r001733_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = ((pub_r001733_9_1 * 2) + 43) & 63;
  int stage_v_74_2 = ((pub_r001733_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (((stage_v_65_1 * 3) + pub_r001733_19_1) + 34) & 127;
  int stage_v_75_2 = (((stage_v_65_2 * 3) + pub_r001733_19_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = ((pub_r001733_7_1 * 2) + 29) & 63;
  int stage_v_76_2 = ((pub_r001733_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((stage_v_44_1 * 3) + pub_r001733_8_1) + 11) & 127;
  int stage_v_77_2 = (((stage_v_44_2 * 3) + pub_r001733_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = (((sec_r001733_0_1 * 3) + pub_r001733_15_1) + 20) & 127;
  int stage_v_78_2 = (((sec_r001733_0_2 * 3) + pub_r001733_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = ((pub_r001733_16_1 * 2) + 11) & 63;
  int stage_v_79_2 = ((pub_r001733_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (((stage_v_37_1 * 3) + pub_r001733_16_1) + 15) & 127;
  int stage_v_80_2 = (((stage_v_37_2 * 3) + pub_r001733_16_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_80_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_80_2 * 2)) & 255;
  int stage_v_81_1 = (((stage_v_38_1 * 3) + pub_r001733_10_1) + 38) & 127;
  int stage_v_81_2 = (((stage_v_38_2 * 3) + pub_r001733_10_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = ((pub_r001733_9_1 * 2) + 41) & 63;
  int stage_v_82_2 = ((pub_r001733_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (((sec_r001733_0_1 * 3) + pub_r001733_5_1) + 32) & 127;
  int stage_v_83_2 = (((sec_r001733_0_2 * 3) + pub_r001733_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = (((sec_r001733_14_1 * 3) + pub_r001733_1_1) + 21) & 127;
  int stage_v_84_2 = (((sec_r001733_14_2 * 3) + pub_r001733_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = ((pub_r001733_18_1 * 2) + 46) & 63;
  int stage_v_85_2 = ((pub_r001733_18_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001733_15_1 * 2) + 49) & 63;
  int stage_v_86_2 = ((pub_r001733_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001733_1_1 * 2) + 10) & 63;
  int stage_v_87_2 = ((pub_r001733_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((sec_r001733_9_1 * 3) + pub_r001733_8_1) + 3) & 127;
  int stage_v_88_2 = (((sec_r001733_9_2 * 3) + pub_r001733_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = (((helper_flow_5_1 * 3) + pub_r001733_14_1) + 11) & 127;
  int stage_v_89_2 = (((helper_flow_5_2 * 3) + pub_r001733_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = (((sec_r001733_17_1 * 3) + pub_r001733_9_1) + 7) & 127;
  int stage_v_90_2 = (((sec_r001733_17_2 * 3) + pub_r001733_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = (((sec_r001733_13_1 * 3) + pub_r001733_5_1) + 4) & 127;
  int stage_v_91_2 = (((sec_r001733_13_2 * 3) + pub_r001733_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = (((stage_v_78_1 * 3) + pub_r001733_13_1) + 18) & 127;
  int stage_v_92_2 = (((stage_v_78_2 * 3) + pub_r001733_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = ((pub_r001733_11_1 * 2) + 21) & 63;
  int stage_v_93_2 = ((pub_r001733_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001733_15_1 * 2) + 42) & 63;
  int stage_v_94_2 = ((pub_r001733_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (((stage_v_48_1 * 3) + pub_r001733_16_1) + 34) & 127;
  int stage_v_95_2 = (((stage_v_48_2 * 3) + pub_r001733_16_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = ((pub_r001733_12_1 * 2) + 44) & 63;
  int stage_v_96_2 = ((pub_r001733_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((stage_v_17_1 * 3) + pub_r001733_18_1) + 3) & 127;
  int stage_v_97_2 = (((stage_v_17_2 * 3) + pub_r001733_18_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = (((sec_r001733_9_1 * 3) + pub_r001733_16_1) + 7) & 127;
  int stage_v_98_2 = (((sec_r001733_9_2 * 3) + pub_r001733_16_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = (((stage_v_90_1 * 3) + pub_r001733_12_1) + 24) & 127;
  int stage_v_99_2 = (((stage_v_90_2 * 3) + pub_r001733_12_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = ((pub_r001733_2_1 * 2) + 42) & 63;
  int stage_v_100_2 = ((pub_r001733_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001733_13_1 * 2) + 18) & 63;
  int stage_v_101_2 = ((pub_r001733_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((stage_v_83_1 * 3) + pub_r001733_1_1) + 31) & 127;
  int stage_v_102_2 = (((stage_v_83_2 * 3) + pub_r001733_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = ((pub_r001733_10_1 * 2) + 45) & 63;
  int stage_v_103_2 = ((pub_r001733_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((stage_v_48_1 * 3) + pub_r001733_13_1) + 14) & 127;
  int stage_v_104_2 = (((stage_v_48_2 * 3) + pub_r001733_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = ((pub_r001733_8_1 * 2) + 43) & 63;
  int stage_v_105_2 = ((pub_r001733_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (((sec_r001733_16_1 * 3) + pub_r001733_5_1) + 44) & 127;
  int stage_v_106_2 = (((sec_r001733_16_2 * 3) + pub_r001733_5_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = (((stage_v_0_1 * 3) + pub_r001733_11_1) + 15) & 127;
  int stage_v_107_2 = (((stage_v_0_2 * 3) + pub_r001733_11_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = (((stage_v_104_1 * 3) + pub_r001733_19_1) + 29) & 127;
  int stage_v_108_2 = (((stage_v_104_2 * 3) + pub_r001733_19_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = ((pub_r001733_8_1 * 2) + 44) & 63;
  int stage_v_109_2 = ((pub_r001733_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001733_3_1 * 2) + 46) & 63;
  int stage_v_110_2 = ((pub_r001733_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (((helper_flow_5_1 * 3) + pub_r001733_18_1) + 14) & 127;
  int stage_v_111_2 = (((helper_flow_5_2 * 3) + pub_r001733_18_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = ((pub_r001733_15_1 * 2) + 27) & 63;
  int stage_v_112_2 = ((pub_r001733_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((stage_v_90_1 * 3) + pub_r001733_12_1) + 20) & 127;
  int stage_v_113_2 = (((stage_v_90_2 * 3) + pub_r001733_12_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = ((pub_r001733_6_1 * 2) + 48) & 63;
  int stage_v_114_2 = ((pub_r001733_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001733_10_1 * 2) + 41) & 63;
  int stage_v_115_2 = ((pub_r001733_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001733_13_1 * 2) + 30) & 63;
  int stage_v_116_2 = ((pub_r001733_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001733_2_1 * 2) + 40) & 63;
  int stage_v_117_2 = ((pub_r001733_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001733_16_1 * 2) + 12) & 63;
  int stage_v_118_2 = ((pub_r001733_16_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (((stage_v_90_1 * 3) + pub_r001733_10_1) + 17) & 127;
  int stage_v_119_2 = (((stage_v_90_2 * 3) + pub_r001733_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = (((stage_v_70_1 * 3) + pub_r001733_15_1) + 32) & 127;
  int stage_v_120_2 = (((stage_v_70_2 * 3) + pub_r001733_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = (((stage_v_108_1 * 3) + pub_r001733_8_1) + 40) & 127;
  int stage_v_121_2 = (((stage_v_108_2 * 3) + pub_r001733_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = ((pub_r001733_2_1 * 2) + 8) & 63;
  int stage_v_122_2 = ((pub_r001733_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (((stage_v_13_1 * 3) + pub_r001733_2_1) + 15) & 127;
  int stage_v_123_2 = (((stage_v_13_2 * 3) + pub_r001733_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = (((stage_v_106_1 * 3) + pub_r001733_7_1) + 13) & 127;
  int stage_v_124_2 = (((stage_v_106_2 * 3) + pub_r001733_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = (((stage_v_18_1 * 3) + pub_r001733_17_1) + 40) & 127;
  int stage_v_125_2 = (((stage_v_18_2 * 3) + pub_r001733_17_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = (((stage_v_61_1 * 3) + pub_r001733_10_1) + 38) & 127;
  int stage_v_126_2 = (((stage_v_61_2 * 3) + pub_r001733_10_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = (((sec_r001733_9_1 * 3) + pub_r001733_18_1) + 36) & 127;
  int stage_v_127_2 = (((sec_r001733_9_2 * 3) + pub_r001733_18_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = (((stage_v_99_1 * 3) + pub_r001733_8_1) + 17) & 127;
  int stage_v_128_2 = (((stage_v_99_2 * 3) + pub_r001733_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = (((stage_v_61_1 * 3) + pub_r001733_13_1) + 9) & 127;
  int stage_v_129_2 = (((stage_v_61_2 * 3) + pub_r001733_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = ((pub_r001733_2_1 * 2) + 43) & 63;
  int stage_v_130_2 = ((pub_r001733_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001733_9_1 * 2) + 7) & 63;
  int stage_v_131_2 = ((pub_r001733_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001733_10_1 * 2) + 43) & 63;
  int stage_v_132_2 = ((pub_r001733_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((stage_v_71_1 * 3) + pub_r001733_15_1) + 22) & 127;
  int stage_v_133_2 = (((stage_v_71_2 * 3) + pub_r001733_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((stage_v_19_1 * 3) + pub_r001733_13_1) + 40) & 127;
  int stage_v_134_2 = (((stage_v_19_2 * 3) + pub_r001733_13_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = (((stage_v_15_1 * 3) + pub_r001733_10_1) + 38) & 127;
  int stage_v_135_2 = (((stage_v_15_2 * 3) + pub_r001733_10_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = (((stage_v_15_1 * 3) + pub_r001733_6_1) + 45) & 127;
  int stage_v_136_2 = (((stage_v_15_2 * 3) + pub_r001733_6_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = ((pub_r001733_10_1 * 2) + 36) & 63;
  int stage_v_137_2 = ((pub_r001733_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((helper_flow_1_1 * 3) + pub_r001733_7_1) + 27) & 127;
  int stage_v_138_2 = (((helper_flow_1_2 * 3) + pub_r001733_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = (((stage_v_69_1 * 3) + pub_r001733_5_1) + 16) & 127;
  int stage_v_139_2 = (((stage_v_69_2 * 3) + pub_r001733_5_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = ((pub_r001733_11_1 * 2) + 41) & 63;
  int stage_v_140_2 = ((pub_r001733_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = (((stage_v_136_1 * 3) + pub_r001733_9_1) + 26) & 127;
  int stage_v_141_2 = (((stage_v_136_2 * 3) + pub_r001733_9_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = ((pub_r001733_3_1 * 2) + 40) & 63;
  int stage_v_142_2 = ((pub_r001733_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = (((sec_r001733_8_1 * 3) + pub_r001733_14_1) + 45) & 127;
  int stage_v_143_2 = (((sec_r001733_8_2 * 3) + pub_r001733_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = ((pub_r001733_6_1 * 2) + 8) & 63;
  int stage_v_144_2 = ((pub_r001733_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001733_9_1 * 2) + 30) & 63;
  int stage_v_145_2 = ((pub_r001733_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001733_7_1 * 2) + 23) & 63;
  int stage_v_146_2 = ((pub_r001733_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((helper_flow_4_1 * 3) + pub_r001733_18_1) + 6) & 127;
  int stage_v_147_2 = (((helper_flow_4_2 * 3) + pub_r001733_18_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = (((sec_r001733_8_1 * 3) + pub_r001733_2_1) + 19) & 127;
  int stage_v_148_2 = (((sec_r001733_8_2 * 3) + pub_r001733_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = (((stage_v_23_1 * 3) + pub_r001733_17_1) + 10) & 127;
  int stage_v_149_2 = (((stage_v_23_2 * 3) + pub_r001733_17_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = (((stage_v_125_1 * 3) + pub_r001733_9_1) + 9) & 127;
  int stage_v_150_2 = (((stage_v_125_2 * 3) + pub_r001733_9_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = (((sec_r001733_10_1 * 3) + pub_r001733_9_1) + 31) & 127;
  int stage_v_151_2 = (((sec_r001733_10_2 * 3) + pub_r001733_9_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = (((stage_v_37_1 * 3) + pub_r001733_9_1) + 29) & 127;
  int stage_v_152_2 = (((stage_v_37_2 * 3) + pub_r001733_9_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = ((pub_r001733_2_1 * 2) + 19) & 63;
  int stage_v_153_2 = ((pub_r001733_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((stage_v_59_1 * 3) + pub_r001733_17_1) + 41) & 127;
  int stage_v_154_2 = (((stage_v_59_2 * 3) + pub_r001733_17_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = ((pub_r001733_16_1 * 2) + 6) & 63;
  int stage_v_155_2 = ((pub_r001733_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (((stage_v_128_1 * 3) + pub_r001733_16_1) + 22) & 127;
  int stage_v_156_2 = (((stage_v_128_2 * 3) + pub_r001733_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = ((pub_r001733_19_1 * 2) + 19) & 63;
  int stage_v_157_2 = ((pub_r001733_19_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = (((stage_v_138_1 * 3) + pub_r001733_13_1) + 24) & 127;
  int stage_v_158_2 = (((stage_v_138_2 * 3) + pub_r001733_13_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = (((stage_v_121_1 * 3) + pub_r001733_0_1) + 5) & 127;
  int stage_v_159_2 = (((stage_v_121_2 * 3) + pub_r001733_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = (((stage_v_138_1 * 3) + pub_r001733_13_1) + 33) & 127;
  int stage_v_160_2 = (((stage_v_138_2 * 3) + pub_r001733_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = ((pub_r001733_14_1 * 2) + 43) & 63;
  int stage_v_161_2 = ((pub_r001733_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (((sec_r001733_14_1 * 3) + pub_r001733_17_1) + 45) & 127;
  int stage_v_162_2 = (((sec_r001733_14_2 * 3) + pub_r001733_17_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = ((pub_r001733_10_1 * 2) + 50) & 63;
  int stage_v_163_2 = ((pub_r001733_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001733_4_1 * 2) + 19) & 63;
  int stage_v_164_2 = ((pub_r001733_4_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (((stage_v_44_1 * 3) + pub_r001733_8_1) + 36) & 127;
  int stage_v_165_2 = (((stage_v_44_2 * 3) + pub_r001733_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = (((stage_v_99_1 * 3) + pub_r001733_3_1) + 12) & 127;
  int stage_v_166_2 = (((stage_v_99_2 * 3) + pub_r001733_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = (((stage_v_34_1 * 3) + pub_r001733_4_1) + 4) & 127;
  int stage_v_167_2 = (((stage_v_34_2 * 3) + pub_r001733_4_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = ((pub_r001733_16_1 * 2) + 49) & 63;
  int stage_v_168_2 = ((pub_r001733_16_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001733_10_1 * 2) + 8) & 63;
  int stage_v_169_2 = ((pub_r001733_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001733_19_1 * 2) + 47) & 63;
  int stage_v_170_2 = ((pub_r001733_19_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001733_17_1 * 2) + 6) & 63;
  int stage_v_171_2 = ((pub_r001733_17_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((stage_v_95_1 * 3) + pub_r001733_1_1) + 3) & 127;
  int stage_v_172_2 = (((stage_v_95_2 * 3) + pub_r001733_1_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = ((pub_r001733_3_1 * 2) + 12) & 63;
  int stage_v_173_2 = ((pub_r001733_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001733_10_1 * 2) + 34) & 63;
  int stage_v_174_2 = ((pub_r001733_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((stage_v_107_1 * 3) + pub_r001733_8_1) + 25) & 127;
  int stage_v_175_2 = (((stage_v_107_2 * 3) + pub_r001733_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = ((pub_r001733_9_1 * 2) + 19) & 63;
  int stage_v_176_2 = ((pub_r001733_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = (((sec_r001733_6_1 * 3) + pub_r001733_6_1) + 18) & 127;
  int stage_v_177_2 = (((sec_r001733_6_2 * 3) + pub_r001733_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = ((pub_r001733_9_1 * 2) + 12) & 63;
  int stage_v_178_2 = ((pub_r001733_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001733_4_1 * 2) + 28) & 63;
  int stage_v_179_2 = ((pub_r001733_4_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((helper_flow_6_1 * 3) + pub_r001733_17_1) + 27) & 127;
  int stage_v_180_2 = (((helper_flow_6_2 * 3) + pub_r001733_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = ((pub_r001733_13_1 * 2) + 17) & 63;
  int stage_v_181_2 = ((pub_r001733_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((stage_v_73_1 * 3) + pub_r001733_10_1) + 21) & 127;
  int stage_v_182_2 = (((stage_v_73_2 * 3) + pub_r001733_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = (((stage_v_23_1 * 3) + pub_r001733_4_1) + 19) & 127;
  int stage_v_183_2 = (((stage_v_23_2 * 3) + pub_r001733_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = ((pub_r001733_10_1 * 2) + 25) & 63;
  int stage_v_184_2 = ((pub_r001733_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001733_8_1 * 2) + 15) & 63;
  int stage_v_185_2 = ((pub_r001733_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001733_6_1 * 2) + 12) & 63;
  int stage_v_186_2 = ((pub_r001733_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = (((stage_v_148_1 * 3) + pub_r001733_8_1) + 3) & 127;
  int stage_v_187_2 = (((stage_v_148_2 * 3) + pub_r001733_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = ((pub_r001733_18_1 * 2) + 5) & 63;
  int stage_v_188_2 = ((pub_r001733_18_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (((stage_v_124_1 * 3) + pub_r001733_4_1) + 25) & 127;
  int stage_v_189_2 = (((stage_v_124_2 * 3) + pub_r001733_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = ((pub_r001733_9_1 * 2) + 25) & 63;
  int stage_v_190_2 = ((pub_r001733_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (((stage_v_129_1 * 3) + pub_r001733_12_1) + 32) & 127;
  int stage_v_191_2 = (((stage_v_129_2 * 3) + pub_r001733_12_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = ((pub_r001733_8_1 * 2) + 10) & 63;
  int stage_v_192_2 = ((pub_r001733_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((stage_v_34_1 * 3) + pub_r001733_4_1) + 6) & 127;
  int stage_v_193_2 = (((stage_v_34_2 * 3) + pub_r001733_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = ((pub_r001733_13_1 * 2) + 20) & 63;
  int stage_v_194_2 = ((pub_r001733_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = (((helper_flow_0_1 * 3) + pub_r001733_17_1) + 22) & 127;
  int stage_v_195_2 = (((helper_flow_0_2 * 3) + pub_r001733_17_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = ((pub_r001733_17_1 * 2) + 21) & 63;
  int stage_v_196_2 = ((pub_r001733_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001733_1_1 * 2) + 21) & 63;
  int stage_v_197_2 = ((pub_r001733_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001733_3_1 * 2) + 36) & 63;
  int stage_v_198_2 = ((pub_r001733_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001733_11_1 * 2) + 13) & 63;
  int stage_v_199_2 = ((pub_r001733_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001733_4_1 * 2) + 12) & 63;
  int stage_v_200_2 = ((pub_r001733_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001733_2_1 * 2) + 22) & 63;
  int stage_v_201_2 = ((pub_r001733_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001733_8_1 * 2) + 18) & 63;
  int stage_v_202_2 = ((pub_r001733_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (((sec_r001733_13_1 * 3) + pub_r001733_13_1) + 42) & 127;
  int stage_v_203_2 = (((sec_r001733_13_2 * 3) + pub_r001733_13_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = (((sec_r001733_10_1 * 3) + pub_r001733_15_1) + 7) & 127;
  int stage_v_204_2 = (((sec_r001733_10_2 * 3) + pub_r001733_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = ((pub_r001733_16_1 * 2) + 5) & 63;
  int stage_v_205_2 = ((pub_r001733_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = (((sec_r001733_2_1 * 3) + pub_r001733_16_1) + 22) & 127;
  int stage_v_206_2 = (((sec_r001733_2_2 * 3) + pub_r001733_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = (((stage_v_9_1 * 3) + pub_r001733_1_1) + 11) & 127;
  int stage_v_207_2 = (((stage_v_9_2 * 3) + pub_r001733_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = (((stage_v_193_1 * 3) + pub_r001733_15_1) + 8) & 127;
  int stage_v_208_2 = (((stage_v_193_2 * 3) + pub_r001733_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_208_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_208_2 * 2)) & 255;
  int stage_v_209_1 = ((pub_r001733_19_1 * 2) + 28) & 63;
  int stage_v_209_2 = ((pub_r001733_19_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = (((sec_r001733_0_1 * 3) + pub_r001733_19_1) + 24) & 127;
  int stage_v_210_2 = (((sec_r001733_0_2 * 3) + pub_r001733_19_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = (((stage_v_111_1 * 3) + pub_r001733_17_1) + 27) & 127;
  int stage_v_211_2 = (((stage_v_111_2 * 3) + pub_r001733_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = (((helper_flow_2_1 * 3) + pub_r001733_7_1) + 36) & 127;
  int stage_v_212_2 = (((helper_flow_2_2 * 3) + pub_r001733_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = (((stage_v_45_1 * 3) + pub_r001733_9_1) + 33) & 127;
  int stage_v_213_2 = (((stage_v_45_2 * 3) + pub_r001733_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = ((pub_r001733_12_1 * 2) + 48) & 63;
  int stage_v_214_2 = ((pub_r001733_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001733_15_1 * 2) + 15) & 63;
  int stage_v_215_2 = ((pub_r001733_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001733_18_1 * 2) + 25) & 63;
  int stage_v_216_2 = ((pub_r001733_18_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((stage_v_38_1 * 3) + pub_r001733_3_1) + 19) & 127;
  int stage_v_217_2 = (((stage_v_38_2 * 3) + pub_r001733_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = ((pub_r001733_12_1 * 2) + 47) & 63;
  int stage_v_218_2 = ((pub_r001733_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001733_8_1 * 2) + 50) & 63;
  int stage_v_219_2 = ((pub_r001733_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((pub_r001733_4_1 * 2) + 36) & 63;
  int stage_v_220_2 = ((pub_r001733_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001733_7_1 * 2) + 49) & 63;
  int stage_v_221_2 = ((pub_r001733_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = (((stage_v_121_1 * 3) + pub_r001733_2_1) + 36) & 127;
  int stage_v_222_2 = (((stage_v_121_2 * 3) + pub_r001733_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = ((pub_r001733_15_1 * 2) + 49) & 63;
  int stage_v_223_2 = ((pub_r001733_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = (((stage_v_159_1 * 3) + pub_r001733_7_1) + 38) & 127;
  int stage_v_224_2 = (((stage_v_159_2 * 3) + pub_r001733_7_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = ((pub_r001733_15_1 * 2) + 12) & 63;
  int stage_v_225_2 = ((pub_r001733_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = (((sec_r001733_12_1 * 3) + pub_r001733_7_1) + 28) & 127;
  int stage_v_226_2 = (((sec_r001733_12_2 * 3) + pub_r001733_7_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = (((stage_v_138_1 * 3) + pub_r001733_6_1) + 13) & 127;
  int stage_v_227_2 = (((stage_v_138_2 * 3) + pub_r001733_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = (((stage_v_12_1 * 3) + pub_r001733_19_1) + 32) & 127;
  int stage_v_228_2 = (((stage_v_12_2 * 3) + pub_r001733_19_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = ((pub_r001733_15_1 * 2) + 40) & 63;
  int stage_v_229_2 = ((pub_r001733_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001733_0_1 * 2) + 19) & 63;
  int stage_v_230_2 = ((pub_r001733_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = (((stage_v_162_1 * 3) + pub_r001733_9_1) + 30) & 127;
  int stage_v_231_2 = (((stage_v_162_2 * 3) + pub_r001733_9_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = (((stage_v_156_1 * 3) + pub_r001733_11_1) + 31) & 127;
  int stage_v_232_2 = (((stage_v_156_2 * 3) + pub_r001733_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = ((pub_r001733_6_1 * 2) + 48) & 63;
  int stage_v_233_2 = ((pub_r001733_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001733_11_1 * 2) + 47) & 63;
  int stage_v_234_2 = ((pub_r001733_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = (((stage_v_40_1 * 3) + pub_r001733_15_1) + 31) & 127;
  int stage_v_235_2 = (((stage_v_40_2 * 3) + pub_r001733_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = ((pub_r001733_11_1 * 2) + 18) & 63;
  int stage_v_236_2 = ((pub_r001733_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001733_7_1 * 2) + 49) & 63;
  int stage_v_237_2 = ((pub_r001733_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = (((stage_v_147_1 * 3) + pub_r001733_3_1) + 10) & 127;
  int stage_v_238_2 = (((stage_v_147_2 * 3) + pub_r001733_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = ((pub_r001733_18_1 * 2) + 42) & 63;
  int stage_v_239_2 = ((pub_r001733_18_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((pub_r001733_1_1 * 2) + 33) & 63;
  int stage_v_240_2 = ((pub_r001733_1_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = ((pub_r001733_8_1 * 2) + 13) & 63;
  int stage_v_241_2 = ((pub_r001733_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = (((stage_v_133_1 * 3) + pub_r001733_12_1) + 38) & 127;
  int stage_v_242_2 = (((stage_v_133_2 * 3) + pub_r001733_12_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = ((pub_r001733_12_1 * 2) + 7) & 63;
  int stage_v_243_2 = ((pub_r001733_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((pub_r001733_7_1 * 2) + 33) & 63;
  int stage_v_244_2 = ((pub_r001733_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001733_0_1 * 2) + 9) & 63;
  int stage_v_245_2 = ((pub_r001733_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = (((sec_r001733_5_1 * 3) + pub_r001733_9_1) + 8) & 127;
  int stage_v_246_2 = (((sec_r001733_5_2 * 3) + pub_r001733_9_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = (((stage_v_147_1 * 3) + pub_r001733_10_1) + 45) & 127;
  int stage_v_247_2 = (((stage_v_147_2 * 3) + pub_r001733_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = ((pub_r001733_18_1 * 2) + 14) & 63;
  int stage_v_248_2 = ((pub_r001733_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((pub_r001733_19_1 * 2) + 6) & 63;
  int stage_v_249_2 = ((pub_r001733_19_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001733_6_1 * 2) + 17) & 63;
  int stage_v_250_2 = ((pub_r001733_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001733_0_1 * 2) + 10) & 63;
  int stage_v_251_2 = ((pub_r001733_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((pub_r001733_5_1 * 2) + 20) & 63;
  int stage_v_252_2 = ((pub_r001733_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((pub_r001733_18_1 * 2) + 31) & 63;
  int stage_v_253_2 = ((pub_r001733_18_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = (((stage_v_80_1 * 3) + pub_r001733_18_1) + 15) & 127;
  int stage_v_254_2 = (((stage_v_80_2 * 3) + pub_r001733_18_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = (((stage_v_108_1 * 3) + pub_r001733_12_1) + 10) & 127;
  int stage_v_255_2 = (((stage_v_108_2 * 3) + pub_r001733_12_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = ((pub_r001733_16_1 * 2) + 35) & 63;
  int stage_v_256_2 = ((pub_r001733_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001733_15_1 * 2) + 45) & 63;
  int stage_v_257_2 = ((pub_r001733_15_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((pub_r001733_6_1 * 2) + 32) & 63;
  int stage_v_258_2 = ((pub_r001733_6_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = (((stage_v_154_1 * 3) + pub_r001733_0_1) + 25) & 127;
  int stage_v_259_2 = (((stage_v_154_2 * 3) + pub_r001733_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = ((pub_r001733_16_1 * 2) + 47) & 63;
  int stage_v_260_2 = ((pub_r001733_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001733_1_1 * 2) + 36) & 63;
  int stage_v_261_2 = ((pub_r001733_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001733_13_1 * 2) + 7) & 63;
  int stage_v_262_2 = ((pub_r001733_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = (((helper_flow_1_1 * 3) + pub_r001733_12_1) + 38) & 127;
  int stage_v_263_2 = (((helper_flow_1_2 * 3) + pub_r001733_12_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = (((stage_v_22_1 * 3) + pub_r001733_18_1) + 41) & 127;
  int stage_v_264_2 = (((stage_v_22_2 * 3) + pub_r001733_18_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = (((stage_v_13_1 * 3) + pub_r001733_6_1) + 41) & 127;
  int stage_v_265_2 = (((stage_v_13_2 * 3) + pub_r001733_6_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = ((pub_r001733_5_1 * 2) + 9) & 63;
  int stage_v_266_2 = ((pub_r001733_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = (((stage_v_34_1 * 3) + pub_r001733_6_1) + 9) & 127;
  int stage_v_267_2 = (((stage_v_34_2 * 3) + pub_r001733_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = ((pub_r001733_14_1 * 2) + 35) & 63;
  int stage_v_268_2 = ((pub_r001733_14_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = (((stage_v_133_1 * 3) + pub_r001733_2_1) + 31) & 127;
  int stage_v_269_2 = (((stage_v_133_2 * 3) + pub_r001733_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = (((sec_r001733_0_1 * 3) + pub_r001733_2_1) + 29) & 127;
  int stage_v_270_2 = (((sec_r001733_0_2 * 3) + pub_r001733_2_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = (((stage_v_267_1 * 3) + pub_r001733_9_1) + 42) & 127;
  int stage_v_271_2 = (((stage_v_267_2 * 3) + pub_r001733_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = (((stage_v_30_1 * 3) + pub_r001733_0_1) + 31) & 127;
  int stage_v_272_2 = (((stage_v_30_2 * 3) + pub_r001733_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = (((stage_v_175_1 * 3) + pub_r001733_19_1) + 18) & 127;
  int stage_v_273_2 = (((stage_v_175_2 * 3) + pub_r001733_19_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = ((pub_r001733_3_1 * 2) + 48) & 63;
  int stage_v_274_2 = ((pub_r001733_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = (((stage_v_177_1 * 3) + pub_r001733_17_1) + 14) & 127;
  int stage_v_275_2 = (((stage_v_177_2 * 3) + pub_r001733_17_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = (((stage_v_45_1 * 3) + pub_r001733_10_1) + 26) & 127;
  int stage_v_276_2 = (((stage_v_45_2 * 3) + pub_r001733_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = (((stage_v_44_1 * 3) + pub_r001733_18_1) + 28) & 127;
  int stage_v_277_2 = (((stage_v_44_2 * 3) + pub_r001733_18_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = (((stage_v_207_1 * 3) + pub_r001733_12_1) + 34) & 127;
  int stage_v_278_2 = (((stage_v_207_2 * 3) + pub_r001733_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = (((stage_v_156_1 * 3) + pub_r001733_1_1) + 17) & 127;
  int stage_v_279_2 = (((stage_v_156_2 * 3) + pub_r001733_1_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = (((stage_v_91_1 * 3) + pub_r001733_10_1) + 45) & 127;
  int stage_v_280_2 = (((stage_v_91_2 * 3) + pub_r001733_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = (((stage_v_69_1 * 3) + pub_r001733_15_1) + 23) & 127;
  int stage_v_281_2 = (((stage_v_69_2 * 3) + pub_r001733_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = (((stage_v_148_1 * 3) + pub_r001733_11_1) + 30) & 127;
  int stage_v_282_2 = (((stage_v_148_2 * 3) + pub_r001733_11_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = (((stage_v_106_1 * 3) + pub_r001733_7_1) + 8) & 127;
  int stage_v_283_2 = (((stage_v_106_2 * 3) + pub_r001733_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = (((stage_v_77_1 * 3) + pub_r001733_13_1) + 31) & 127;
  int stage_v_284_2 = (((stage_v_77_2 * 3) + pub_r001733_13_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = ((pub_r001733_2_1 * 2) + 28) & 63;
  int stage_v_285_2 = ((pub_r001733_2_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001733_1_1 * 2) + 19) & 63;
  int stage_v_286_2 = ((pub_r001733_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = (((stage_v_162_1 * 3) + pub_r001733_6_1) + 8) & 127;
  int stage_v_287_2 = (((stage_v_162_2 * 3) + pub_r001733_6_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = ((pub_r001733_1_1 * 2) + 16) & 63;
  int stage_v_288_2 = ((pub_r001733_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((pub_r001733_1_1 * 2) + 24) & 63;
  int stage_v_289_2 = ((pub_r001733_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = (((stage_v_84_1 * 3) + pub_r001733_19_1) + 5) & 127;
  int stage_v_290_2 = (((stage_v_84_2 * 3) + pub_r001733_19_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = ((pub_r001733_4_1 * 2) + 47) & 63;
  int stage_v_291_2 = ((pub_r001733_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = (((helper_flow_2_1 * 3) + pub_r001733_14_1) + 9) & 127;
  int stage_v_292_2 = (((helper_flow_2_2 * 3) + pub_r001733_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = ((pub_r001733_4_1 * 2) + 6) & 63;
  int stage_v_293_2 = ((pub_r001733_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001733_14_1 * 2) + 46) & 63;
  int stage_v_294_2 = ((pub_r001733_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = (((stage_v_99_1 * 3) + pub_r001733_6_1) + 18) & 127;
  int stage_v_295_2 = (((stage_v_99_2 * 3) + pub_r001733_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = (((sec_r001733_2_1 * 3) + pub_r001733_6_1) + 41) & 127;
  int stage_v_296_2 = (((sec_r001733_2_2 * 3) + pub_r001733_6_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = (((stage_v_43_1 * 3) + pub_r001733_6_1) + 12) & 127;
  int stage_v_297_2 = (((stage_v_43_2 * 3) + pub_r001733_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = ((pub_r001733_1_1 * 2) + 30) & 63;
  int stage_v_298_2 = ((pub_r001733_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = (((stage_v_271_1 * 3) + pub_r001733_11_1) + 43) & 127;
  int stage_v_299_2 = (((stage_v_271_2 * 3) + pub_r001733_11_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = (((stage_v_56_1 * 3) + pub_r001733_15_1) + 3) & 127;
  int stage_v_300_2 = (((stage_v_56_2 * 3) + pub_r001733_15_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = ((pub_r001733_15_1 * 2) + 32) & 63;
  int stage_v_301_2 = ((pub_r001733_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001733_8_1 * 2) + 6) & 63;
  int stage_v_302_2 = ((pub_r001733_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = (((stage_v_277_1 * 3) + pub_r001733_5_1) + 17) & 127;
  int stage_v_303_2 = (((stage_v_277_2 * 3) + pub_r001733_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = ((pub_r001733_13_1 * 2) + 41) & 63;
  int stage_v_304_2 = ((pub_r001733_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = (((stage_v_15_1 * 3) + pub_r001733_10_1) + 5) & 127;
  int stage_v_305_2 = (((stage_v_15_2 * 3) + pub_r001733_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_305_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_305_2 * 2)) & 255;
  int stage_v_306_1 = (((stage_v_70_1 * 3) + pub_r001733_16_1) + 32) & 127;
  int stage_v_306_2 = (((stage_v_70_2 * 3) + pub_r001733_16_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = ((pub_r001733_6_1 * 2) + 15) & 63;
  int stage_v_307_2 = ((pub_r001733_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = (((stage_v_11_1 * 3) + pub_r001733_13_1) + 12) & 127;
  int stage_v_308_2 = (((stage_v_11_2 * 3) + pub_r001733_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = (((stage_v_203_1 * 3) + pub_r001733_1_1) + 25) & 127;
  int stage_v_309_2 = (((stage_v_203_2 * 3) + pub_r001733_1_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = ((pub_r001733_0_1 * 2) + 16) & 63;
  int stage_v_310_2 = ((pub_r001733_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = (((stage_v_303_1 * 3) + pub_r001733_10_1) + 27) & 127;
  int stage_v_311_2 = (((stage_v_303_2 * 3) + pub_r001733_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = (((stage_v_17_1 * 3) + pub_r001733_5_1) + 35) & 127;
  int stage_v_312_2 = (((stage_v_17_2 * 3) + pub_r001733_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = ((pub_r001733_13_1 * 2) + 16) & 63;
  int stage_v_313_2 = ((pub_r001733_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = (((stage_v_128_1 * 3) + pub_r001733_0_1) + 27) & 127;
  int stage_v_314_2 = (((stage_v_128_2 * 3) + pub_r001733_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = (((stage_v_187_1 * 3) + pub_r001733_2_1) + 22) & 127;
  int stage_v_315_2 = (((stage_v_187_2 * 3) + pub_r001733_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = (((sec_r001733_2_1 * 3) + pub_r001733_16_1) + 39) & 127;
  int stage_v_316_2 = (((sec_r001733_2_2 * 3) + pub_r001733_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = (((stage_v_311_1 * 3) + pub_r001733_14_1) + 37) & 127;
  int stage_v_317_2 = (((stage_v_311_2 * 3) + pub_r001733_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = ((pub_r001733_4_1 * 2) + 45) & 63;
  int stage_v_318_2 = ((pub_r001733_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = (((stage_v_269_1 * 3) + pub_r001733_6_1) + 40) & 127;
  int stage_v_319_2 = (((stage_v_269_2 * 3) + pub_r001733_6_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = ((pub_r001733_18_1 * 2) + 11) & 63;
  int stage_v_320_2 = ((pub_r001733_18_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = (((helper_flow_1_1 * 3) + pub_r001733_0_1) + 19) & 127;
  int stage_v_321_2 = (((helper_flow_1_2 * 3) + pub_r001733_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = ((pub_r001733_7_1 * 2) + 32) & 63;
  int stage_v_322_2 = ((pub_r001733_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001733_1_1 * 2) + 40) & 63;
  int stage_v_323_2 = ((pub_r001733_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((pub_r001733_9_1 * 2) + 17) & 63;
  int stage_v_324_2 = ((pub_r001733_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = (((stage_v_224_1 * 3) + pub_r001733_6_1) + 37) & 127;
  int stage_v_325_2 = (((stage_v_224_2 * 3) + pub_r001733_6_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = ((pub_r001733_16_1 * 2) + 38) & 63;
  int stage_v_326_2 = ((pub_r001733_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001733_4_1 * 2) + 18) & 63;
  int stage_v_327_2 = ((pub_r001733_4_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = (((stage_v_48_1 * 3) + pub_r001733_15_1) + 5) & 127;
  int stage_v_328_2 = (((stage_v_48_2 * 3) + pub_r001733_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = (((stage_v_263_1 * 3) + pub_r001733_9_1) + 18) & 127;
  int stage_v_329_2 = (((stage_v_263_2 * 3) + pub_r001733_9_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = (((stage_v_297_1 * 3) + pub_r001733_7_1) + 23) & 127;
  int stage_v_330_2 = (((stage_v_297_2 * 3) + pub_r001733_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = ((pub_r001733_12_1 * 2) + 49) & 63;
  int stage_v_331_2 = ((pub_r001733_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = (((stage_v_238_1 * 3) + pub_r001733_12_1) + 9) & 127;
  int stage_v_332_2 = (((stage_v_238_2 * 3) + pub_r001733_12_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = (((stage_v_78_1 * 3) + pub_r001733_15_1) + 41) & 127;
  int stage_v_333_2 = (((stage_v_78_2 * 3) + pub_r001733_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = (((stage_v_231_1 * 3) + pub_r001733_1_1) + 18) & 127;
  int stage_v_334_2 = (((stage_v_231_2 * 3) + pub_r001733_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = (((stage_v_232_1 * 3) + pub_r001733_13_1) + 40) & 127;
  int stage_v_335_2 = (((stage_v_232_2 * 3) + pub_r001733_13_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = (((stage_v_147_1 * 3) + pub_r001733_12_1) + 36) & 127;
  int stage_v_336_2 = (((stage_v_147_2 * 3) + pub_r001733_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = (((stage_v_17_1 * 3) + pub_r001733_15_1) + 26) & 127;
  int stage_v_337_2 = (((stage_v_17_2 * 3) + pub_r001733_15_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = ((pub_r001733_2_1 * 2) + 23) & 63;
  int stage_v_338_2 = ((pub_r001733_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = (((stage_v_160_1 * 3) + pub_r001733_17_1) + 6) & 127;
  int stage_v_339_2 = (((stage_v_160_2 * 3) + pub_r001733_17_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = (((stage_v_81_1 * 3) + pub_r001733_16_1) + 32) & 127;
  int stage_v_340_2 = (((stage_v_81_2 * 3) + pub_r001733_16_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = ((pub_r001733_17_1 * 2) + 44) & 63;
  int stage_v_341_2 = ((pub_r001733_17_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((pub_r001733_18_1 * 2) + 13) & 63;
  int stage_v_342_2 = ((pub_r001733_18_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = (((stage_v_204_1 * 3) + pub_r001733_14_1) + 26) & 127;
  int stage_v_343_2 = (((stage_v_204_2 * 3) + pub_r001733_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = (((stage_v_99_1 * 3) + pub_r001733_14_1) + 45) & 127;
  int stage_v_344_2 = (((stage_v_99_2 * 3) + pub_r001733_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = (((stage_v_95_1 * 3) + pub_r001733_10_1) + 4) & 127;
  int stage_v_345_2 = (((stage_v_95_2 * 3) + pub_r001733_10_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = ((pub_r001733_14_1 * 2) + 8) & 63;
  int stage_v_346_2 = ((pub_r001733_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((pub_r001733_14_1 * 2) + 9) & 63;
  int stage_v_347_2 = ((pub_r001733_14_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = (((stage_v_119_1 * 3) + pub_r001733_6_1) + 16) & 127;
  int stage_v_348_2 = (((stage_v_119_2 * 3) + pub_r001733_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = (((stage_v_81_1 * 3) + pub_r001733_16_1) + 14) & 127;
  int stage_v_349_2 = (((stage_v_81_2 * 3) + pub_r001733_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = ((pub_r001733_16_1 * 2) + 29) & 63;
  int stage_v_350_2 = ((pub_r001733_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = ((pub_r001733_16_1 * 2) + 20) & 63;
  int stage_v_351_2 = ((pub_r001733_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((pub_r001733_5_1 * 2) + 36) & 63;
  int stage_v_352_2 = ((pub_r001733_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = (((sec_r001733_4_1 * 3) + pub_r001733_19_1) + 28) & 127;
  int stage_v_353_2 = (((sec_r001733_4_2 * 3) + pub_r001733_19_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = (((sec_r001733_12_1 * 3) + pub_r001733_12_1) + 28) & 127;
  int stage_v_354_2 = (((sec_r001733_12_2 * 3) + pub_r001733_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = ((pub_r001733_10_1 * 2) + 25) & 63;
  int stage_v_355_2 = ((pub_r001733_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((pub_r001733_10_1 * 2) + 40) & 63;
  int stage_v_356_2 = ((pub_r001733_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((pub_r001733_11_1 * 2) + 44) & 63;
  int stage_v_357_2 = ((pub_r001733_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001733_5_1 * 2) + 39) & 63;
  int stage_v_358_2 = ((pub_r001733_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = (((stage_v_284_1 * 3) + pub_r001733_2_1) + 36) & 127;
  int stage_v_359_2 = (((stage_v_284_2 * 3) + pub_r001733_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = (((stage_v_232_1 * 3) + pub_r001733_19_1) + 32) & 127;
  int stage_v_360_2 = (((stage_v_232_2 * 3) + pub_r001733_19_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = (((stage_v_22_1 * 3) + pub_r001733_14_1) + 22) & 127;
  int stage_v_361_2 = (((stage_v_22_2 * 3) + pub_r001733_14_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = ((pub_r001733_6_1 * 2) + 47) & 63;
  int stage_v_362_2 = ((pub_r001733_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001733_7_1 * 2) + 48) & 63;
  int stage_v_363_2 = ((pub_r001733_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = (((stage_v_280_1 * 3) + pub_r001733_12_1) + 11) & 127;
  int stage_v_364_2 = (((stage_v_280_2 * 3) + pub_r001733_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = ((pub_r001733_6_1 * 2) + 31) & 63;
  int stage_v_365_2 = ((pub_r001733_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((pub_r001733_11_1 * 2) + 44) & 63;
  int stage_v_366_2 = ((pub_r001733_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = ((pub_r001733_1_1 * 2) + 47) & 63;
  int stage_v_367_2 = ((pub_r001733_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = (((stage_v_38_1 * 3) + pub_r001733_10_1) + 3) & 127;
  int stage_v_368_2 = (((stage_v_38_2 * 3) + pub_r001733_10_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = (((stage_v_143_1 * 3) + pub_r001733_12_1) + 40) & 127;
  int stage_v_369_2 = (((stage_v_143_2 * 3) + pub_r001733_12_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = (((helper_flow_0_1 * 3) + pub_r001733_9_1) + 10) & 127;
  int stage_v_370_2 = (((helper_flow_0_2 * 3) + pub_r001733_9_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = (((stage_v_270_1 * 3) + pub_r001733_3_1) + 10) & 127;
  int stage_v_371_2 = (((stage_v_270_2 * 3) + pub_r001733_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = (((stage_v_88_1 * 3) + pub_r001733_10_1) + 30) & 127;
  int stage_v_372_2 = (((stage_v_88_2 * 3) + pub_r001733_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_372_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_372_2 * 2)) & 255;
  int stage_v_373_1 = (((stage_v_353_1 * 3) + pub_r001733_14_1) + 11) & 127;
  int stage_v_373_2 = (((stage_v_353_2 * 3) + pub_r001733_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = (((stage_v_364_1 * 3) + pub_r001733_7_1) + 14) & 127;
  int stage_v_374_2 = (((stage_v_364_2 * 3) + pub_r001733_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_348_1 * 3) + pub_r001733_19_1) + 13) & 127;
  int stage_v_375_2 = (((stage_v_348_2 * 3) + pub_r001733_19_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = ((pub_r001733_15_1 * 2) + 41) & 63;
  int stage_v_376_2 = ((pub_r001733_15_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((pub_r001733_0_1 * 2) + 26) & 63;
  int stage_v_377_2 = ((pub_r001733_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = ((pub_r001733_6_1 * 2) + 43) & 63;
  int stage_v_378_2 = ((pub_r001733_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = ((pub_r001733_6_1 * 2) + 17) & 63;
  int stage_v_379_2 = ((pub_r001733_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = (((stage_v_56_1 * 3) + pub_r001733_1_1) + 30) & 127;
  int stage_v_380_2 = (((stage_v_56_2 * 3) + pub_r001733_1_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = (((stage_v_20_1 * 3) + pub_r001733_18_1) + 5) & 127;
  int stage_v_381_2 = (((stage_v_20_2 * 3) + pub_r001733_18_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = ((pub_r001733_7_1 * 2) + 21) & 63;
  int stage_v_382_2 = ((pub_r001733_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((pub_r001733_0_1 * 2) + 20) & 63;
  int stage_v_383_2 = ((pub_r001733_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = (((stage_v_227_1 * 3) + pub_r001733_0_1) + 36) & 127;
  int stage_v_384_2 = (((stage_v_227_2 * 3) + pub_r001733_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = (((stage_v_133_1 * 3) + pub_r001733_13_1) + 34) & 127;
  int stage_v_385_2 = (((stage_v_133_2 * 3) + pub_r001733_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = (((sec_r001733_10_1 * 3) + pub_r001733_14_1) + 20) & 127;
  int stage_v_386_2 = (((sec_r001733_10_2 * 3) + pub_r001733_14_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_386_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_386_2 * 2)) & 255;
  int stage_v_387_1 = (((stage_v_208_1 * 3) + pub_r001733_14_1) + 11) & 127;
  int stage_v_387_2 = (((stage_v_208_2 * 3) + pub_r001733_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = ((pub_r001733_10_1 * 2) + 34) & 63;
  int stage_v_388_2 = ((pub_r001733_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = (((stage_v_162_1 * 3) + pub_r001733_18_1) + 34) & 127;
  int stage_v_389_2 = (((stage_v_162_2 * 3) + pub_r001733_18_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = (((stage_v_187_1 * 3) + pub_r001733_2_1) + 24) & 127;
  int stage_v_390_2 = (((stage_v_187_2 * 3) + pub_r001733_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = ((pub_r001733_4_1 * 2) + 35) & 63;
  int stage_v_391_2 = ((pub_r001733_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001733_7_1 * 2) + 49) & 63;
  int stage_v_392_2 = ((pub_r001733_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((pub_r001733_7_1 * 2) + 31) & 63;
  int stage_v_393_2 = ((pub_r001733_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = (((stage_v_369_1 * 3) + pub_r001733_12_1) + 12) & 127;
  int stage_v_394_2 = (((stage_v_369_2 * 3) + pub_r001733_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_394_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_394_2 * 2)) & 255;
  int stage_v_395_1 = (((stage_v_159_1 * 3) + pub_r001733_16_1) + 41) & 127;
  int stage_v_395_2 = (((stage_v_159_2 * 3) + pub_r001733_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_395_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_395_2 * 2)) & 255;
  int stage_v_396_1 = (((stage_v_21_1 * 3) + pub_r001733_18_1) + 41) & 127;
  int stage_v_396_2 = (((stage_v_21_2 * 3) + pub_r001733_18_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = ((pub_r001733_16_1 * 2) + 36) & 63;
  int stage_v_397_2 = ((pub_r001733_16_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = (((stage_v_88_1 * 3) + pub_r001733_8_1) + 14) & 127;
  int stage_v_398_2 = (((stage_v_88_2 * 3) + pub_r001733_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = (((stage_v_139_1 * 3) + pub_r001733_0_1) + 34) & 127;
  int stage_v_399_2 = (((stage_v_139_2 * 3) + pub_r001733_0_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_399_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_399_2 * 2)) & 255;
  int stage_v_400_1 = ((pub_r001733_9_1 * 2) + 14) & 63;
  int stage_v_400_2 = ((pub_r001733_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = (((stage_v_235_1 * 3) + pub_r001733_18_1) + 3) & 127;
  int stage_v_401_2 = (((stage_v_235_2 * 3) + pub_r001733_18_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_401_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_401_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_401_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_401_2 * 2)) & 255;
  int stage_v_402_1 = (((stage_v_297_1 * 3) + pub_r001733_17_1) + 11) & 127;
  int stage_v_402_2 = (((stage_v_297_2 * 3) + pub_r001733_17_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_402_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_402_2 * 2)) & 255;
  int stage_v_403_1 = (((stage_v_162_1 * 3) + pub_r001733_13_1) + 41) & 127;
  int stage_v_403_2 = (((stage_v_162_2 * 3) + pub_r001733_13_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_403_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_403_2 * 2)) & 255;
  int stage_v_404_1 = (((stage_v_147_1 * 3) + pub_r001733_9_1) + 3) & 127;
  int stage_v_404_2 = (((stage_v_147_2 * 3) + pub_r001733_9_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001733_15_1 == pub_r001733_15_2);
  __CPROVER_assume(sec_r001733_6_1 != sec_r001733_6_2);
  __CPROVER_assume(pub_r001733_19_1 == pub_r001733_19_2);
  __CPROVER_assume(sec_r001733_14_1 != sec_r001733_14_2);
  __CPROVER_assume(sec_r001733_4_1 != sec_r001733_4_2);
  __CPROVER_assume(sec_r001733_7_1 != sec_r001733_7_2);
  __CPROVER_assume(sec_r001733_5_1 != sec_r001733_5_2);
  __CPROVER_assume(sec_r001733_0_1 != sec_r001733_0_2);
  __CPROVER_assume(pub_r001733_9_1 == pub_r001733_9_2);
  __CPROVER_assume(pub_r001733_7_1 == pub_r001733_7_2);
  __CPROVER_assume(pub_r001733_4_1 == pub_r001733_4_2);
  __CPROVER_assume(pub_r001733_0_1 == pub_r001733_0_2);
  __CPROVER_assume(pub_r001733_10_1 == pub_r001733_10_2);
  __CPROVER_assume(sec_r001733_11_1 != sec_r001733_11_2);
  __CPROVER_assume(sec_r001733_12_1 != sec_r001733_12_2);
  __CPROVER_assume(pub_r001733_1_1 == pub_r001733_1_2);
  __CPROVER_assume(pub_r001733_13_1 == pub_r001733_13_2);
  __CPROVER_assume(pub_r001733_18_1 == pub_r001733_18_2);
  __CPROVER_assume(sec_r001733_2_1 != sec_r001733_2_2);
  __CPROVER_assume(sec_r001733_16_1 != sec_r001733_16_2);
  __CPROVER_assume(pub_r001733_17_1 == pub_r001733_17_2);
  __CPROVER_assume(sec_r001733_1_1 != sec_r001733_1_2);
  __CPROVER_assume(sec_r001733_13_1 != sec_r001733_13_2);
  __CPROVER_assume(pub_r001733_6_1 == pub_r001733_6_2);
  __CPROVER_assume(pub_r001733_16_1 == pub_r001733_16_2);
  __CPROVER_assume(pub_r001733_5_1 == pub_r001733_5_2);
  __CPROVER_assume(sec_r001733_15_1 != sec_r001733_15_2);
  __CPROVER_assume(sec_r001733_17_1 != sec_r001733_17_2);
  __CPROVER_assume(sec_r001733_9_1 != sec_r001733_9_2);
  __CPROVER_assume(sec_r001733_3_1 != sec_r001733_3_2);
  __CPROVER_assume(pub_r001733_8_1 == pub_r001733_8_2);
  __CPROVER_assume(sec_r001733_10_1 != sec_r001733_10_2);
  __CPROVER_assume(pub_r001733_2_1 == pub_r001733_2_2);
  __CPROVER_assume(pub_r001733_14_1 == pub_r001733_14_2);
  __CPROVER_assume(pub_r001733_3_1 == pub_r001733_3_2);
  __CPROVER_assume(pub_r001733_12_1 == pub_r001733_12_2);
  __CPROVER_assume(sec_r001733_8_1 != sec_r001733_8_2);
  __CPROVER_assume(pub_r001733_11_1 == pub_r001733_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.port == st_var_0_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.mode == st_var_1_2.mode);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.signature == st_var_2_2.signature);
  assert(st_var_2_1.timestamp == st_var_2_2.timestamp);
  assert(st_var_2_1.code == st_var_2_2.code);
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

  assert(helper_flow_0_1 == helper_flow_0_2);
  assert(helper_flow_1_1 == helper_flow_1_2);
  assert(helper_flow_2_1 == helper_flow_2_2);
  assert(helper_flow_3_1 == helper_flow_3_2);
  assert(helper_flow_4_1 == helper_flow_4_2);
  assert(helper_flow_5_1 == helper_flow_5_2);
  assert(helper_flow_6_1 == helper_flow_6_2);
  assert(helper_flow_7_1 == helper_flow_7_2);
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
}


