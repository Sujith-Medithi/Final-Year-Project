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
struct CipherContext_R001540_4013_0
{
  short tag;
  short nonce;
  short round_key;
  unsigned char flags;
  short counter;
  unsigned char iv;
  int buffer[3];
};
struct EventLog_R001540_4013_1
{
  short seq;
  int signature;
  short code;
  int buffer[3];
};
struct Transaction_R001540_4013_2
{
  int balance;
  unsigned char status;
  unsigned char auth_code;
  unsigned char rate;
  int fee;
  int buffer[3];
};
struct DeviceConfig_R001540_4013_3
{
  unsigned char parity;
  int port;
  unsigned char timeout;
  short stop_bits;
  int buffer[3];
};
union TelemetryField_R001540_4013_0
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
void fn_R001540_4013_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001540_4013_2 st_1 = {0};
  struct Transaction_R001540_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int parity_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_10_1) & 63;
  aux_2 = (aux_2 + parity_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_11_1)
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

  switch (offset_11_2)
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

  int checksum_16_1 = 0;
  int checksum_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_16_1 = ((checksum_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_16_2 = ((checksum_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_16_1) & 127;
    acc_2 = (acc_2 + checksum_16_2) & 127;
  }

  int margin_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_83_1 > 12)
  {
    acc_1 = ((acc_1 + (margin_83_1 * 2)) + 5) & 127;
    aux_1 ^= margin_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_83_2 > 12)
  {
    acc_2 = ((acc_2 + (margin_83_2 * 2)) + 5) & 127;
    aux_2 ^= margin_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_83_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_10_1 == parity_10_2);
  assert(offset_11_1 == offset_11_2);
  assert(checksum_16_1 == checksum_16_2);
  assert(margin_83_1 == margin_83_2);
}

int fn_R001540_4013_0(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001540_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int parity_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_10) & 63;
  acc ^= aux;
  int offset_11 = (aux + st.buffer[1]) & 3;
  switch (offset_11)
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

  int checksum_16 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_16 = ((checksum_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_16) & 127;
  }

  int margin_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_83 > 12)
  {
    acc = ((acc + (margin_83 * 2)) + 5) & 127;
    aux ^= margin_83 & 15;
  }
  else
  {
    acc = ((acc - margin_83) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001540_4013_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001540_4013_3 st_1 = {0};
  struct DeviceConfig_R001540_4013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int sample_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_14_1 > 33)
  {
    acc_1 = ((acc_1 + (sample_14_1 * 2)) + 5) & 127;
    aux_1 ^= sample_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_14_2 > 33)
  {
    acc_2 = ((acc_2 + (sample_14_2 * 2)) + 5) & 127;
    aux_2 ^= sample_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_69_1) & 63;
  aux_2 = (aux_2 + tracker_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_14_1 == sample_14_2);
  assert(tracker_69_1 == tracker_69_2);
}

int fn_R001540_4013_1(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001540_4013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int sample_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_14 > 33)
  {
    acc = ((acc + (sample_14 * 2)) + 5) & 127;
    aux ^= sample_14 & 15;
  }
  else
  {
    acc = ((acc - sample_14) + 11) & 127;
    aux += 3;
  }
  int tracker_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_69) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001540_4013_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001540_4013_3 st_1 = {0};
  struct DeviceConfig_R001540_4013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int scale_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_87_1) & 63;
  aux_2 = (aux_2 + scale_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_87_1 == scale_87_2);
}

int fn_R001540_4013_2(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001540_4013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int scale_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_87) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001540_4013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001540_4013_2 st_1 = {0};
  struct Transaction_R001540_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int cursor_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_83_1) & 63;
  aux_2 = (aux_2 + cursor_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_38_1 > 34)
  {
    acc_1 = ((acc_1 + (scale_38_1 * 2)) + 5) & 127;
    aux_1 ^= scale_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_38_2 > 34)
  {
    acc_2 = ((acc_2 + (scale_38_2 * 2)) + 5) & 127;
    aux_2 ^= scale_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_67_1 = local_arr_1[aux_1 % 3];
  int bound_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_67_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_83_1 == cursor_83_2);
  assert(scale_38_1 == scale_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_67_1 == bound_67_2);
}

int fn_R001540_4013_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001540_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int cursor_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_83) & 63;
  acc ^= aux;
  int scale_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_38 > 34)
  {
    acc = ((acc + (scale_38 * 2)) + 5) & 127;
    aux ^= scale_38 & 15;
  }
  else
  {
    acc = ((acc - scale_38) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_67 = local_arr[aux % 3];
  acc = (acc + (bound_67 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001540_4013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001540_4013_1 st_1 = {0};
  struct EventLog_R001540_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_85_1)
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

  switch (accumulator_85_2)
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
  int threshold_77_1 = local_arr_1[aux_1 % 3];
  int threshold_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_77_2 * 2)) & 127;
  int threshold_26_1 = 0;
  int threshold_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_26_1 = ((threshold_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_26_2 = ((threshold_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_26_1) & 127;
    acc_2 = (acc_2 + threshold_26_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_85_1 == accumulator_85_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_77_1 == threshold_77_2);
  assert(threshold_26_1 == threshold_26_2);
}

int fn_R001540_4013_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001540_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_85 = (aux + st.buffer[1]) & 3;
  switch (accumulator_85)
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
  int threshold_77 = local_arr[aux % 3];
  acc = (acc + (threshold_77 * 2)) & 127;
  int threshold_26 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_26 = ((threshold_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_26) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001540_4013_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001540_4013_0 st_1 = {0};
  struct CipherContext_R001540_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_97_1 = 0;
  int index_reg_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_97_1 = ((index_reg_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_97_2 = ((index_reg_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_97_1) & 127;
    acc_2 = (acc_2 + index_reg_97_2) & 127;
  }

  int quantum_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_91_1 > 45)
  {
    acc_1 = ((acc_1 + (quantum_91_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_91_2 > 45)
  {
    acc_2 = ((acc_2 + (quantum_91_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_90_1 = local_arr_1[aux_1 % 3];
  int checksum_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_97_1 == index_reg_97_2);
  assert(quantum_91_1 == quantum_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_90_1 == checksum_90_2);
}

int fn_R001540_4013_5(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001540_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_97 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_97 = ((index_reg_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_97) & 127;
  }

  int quantum_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_91 > 45)
  {
    acc = ((acc + (quantum_91 * 2)) + 5) & 127;
    aux ^= quantum_91 & 15;
  }
  else
  {
    acc = ((acc - quantum_91) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_90 = local_arr[aux % 3];
  acc = (acc + (checksum_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001540_4013_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001540_4013_1 st_1 = {0};
  struct EventLog_R001540_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_81_1 = local_arr_1[aux_1 % 3];
  int stride_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_81_2 * 2)) & 127;
  int offset_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_12_1 > 19)
  {
    acc_1 = ((acc_1 + (offset_12_1 * 2)) + 5) & 127;
    aux_1 ^= offset_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_12_2 > 19)
  {
    acc_2 = ((acc_2 + (offset_12_2 * 2)) + 5) & 127;
    aux_2 ^= offset_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_66_1 = 0;
  int tally_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_66_1 = ((tally_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_66_2 = ((tally_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_66_1) & 127;
    acc_2 = (acc_2 + tally_66_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_81_1 == stride_81_2);
  assert(offset_12_1 == offset_12_2);
  assert(tally_66_1 == tally_66_2);
}

int fn_R001540_4013_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001540_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int stride_81 = local_arr[aux % 3];
  acc = (acc + (stride_81 * 2)) & 127;
  int offset_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_12 > 19)
  {
    acc = ((acc + (offset_12 * 2)) + 5) & 127;
    aux ^= offset_12 & 15;
  }
  else
  {
    acc = ((acc - offset_12) + 11) & 127;
    aux += 3;
  }
  int tally_66 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_66 = ((tally_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_66) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001540_4013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001540_4013_3 st_1 = {0};
  struct DeviceConfig_R001540_4013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_51_1 > 21)
  {
    acc_1 = ((acc_1 + (checksum_51_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_51_2 > 21)
  {
    acc_2 = ((acc_2 + (checksum_51_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_44_1) & 63;
  aux_2 = (aux_2 + mask_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_93_1 = local_arr_1[aux_1 % 3];
  int anchor_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_93_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_51_1 == checksum_51_2);
  assert(mask_44_1 == mask_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_93_1 == anchor_93_2);
}

int fn_R001540_4013_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001540_4013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_51 > 21)
  {
    acc = ((acc + (checksum_51 * 2)) + 5) & 127;
    aux ^= checksum_51 & 15;
  }
  else
  {
    acc = ((acc - checksum_51) + 11) & 127;
    aux += 3;
  }
  int mask_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_44) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_93 = local_arr[aux % 3];
  acc = (acc + (anchor_93 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001540_4013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001540_4013_0 st_1 = {0};
  struct CipherContext_R001540_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int sample_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_27_1 > 34)
  {
    acc_1 = ((acc_1 + (sample_27_1 * 2)) + 5) & 127;
    aux_1 ^= sample_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_27_2 > 34)
  {
    acc_2 = ((acc_2 + (sample_27_2 * 2)) + 5) & 127;
    aux_2 ^= sample_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_85_1 = 0;
  int sample_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_85_1 = ((sample_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_85_2 = ((sample_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_85_1) & 127;
    acc_2 = (acc_2 + sample_85_2) & 127;
  }

  int quotient_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_82_1) & 63;
  aux_2 = (aux_2 + quotient_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_27_1 == sample_27_2);
  assert(sample_85_1 == sample_85_2);
  assert(quotient_82_1 == quotient_82_2);
}

int fn_R001540_4013_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001540_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int sample_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_27 > 34)
  {
    acc = ((acc + (sample_27 * 2)) + 5) & 127;
    aux ^= sample_27 & 15;
  }
  else
  {
    acc = ((acc - sample_27) + 11) & 127;
    aux += 3;
  }
  int sample_85 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_85 = ((sample_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_85) & 127;
  }

  int quotient_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_82) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001540_4013_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001540_4013_1 st_1 = {0};
  struct EventLog_R001540_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int pivot_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_50_1 > 37)
  {
    acc_1 = ((acc_1 + (pivot_50_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_50_2 > 37)
  {
    acc_2 = ((acc_2 + (pivot_50_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_87_1 = 0;
  int offset_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_87_1 = ((offset_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_87_2 = ((offset_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_87_1) & 127;
    acc_2 = (acc_2 + offset_87_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_50_1 == pivot_50_2);
  assert(offset_87_1 == offset_87_2);
}

int fn_R001540_4013_9(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001540_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int pivot_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_50 > 37)
  {
    acc = ((acc + (pivot_50 * 2)) + 5) & 127;
    aux ^= pivot_50 & 15;
  }
  else
  {
    acc = ((acc - pivot_50) + 11) & 127;
    aux += 3;
  }
  int offset_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_87 = ((offset_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_87) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001540_4013_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001540_4013_0 st_1 = {0};
  struct CipherContext_R001540_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_37_1 = local_arr_1[aux_1 % 3];
  int delta_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_37_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_37_1 == delta_37_2);
}

int fn_R001540_4013_10(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001540_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_37 = local_arr[aux % 3];
  acc = (acc + (delta_37 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001540_4013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001540_4013_0 st_1 = {0};
  struct CipherContext_R001540_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int phase_68_1 = 0;
  int phase_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_68_1 = ((phase_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_68_2 = ((phase_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_68_1) & 127;
    acc_2 = (acc_2 + phase_68_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_91_1 = local_arr_1[aux_1 % 3];
  int window_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_91_2 * 2)) & 127;
  int parity_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_68_1)
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

  switch (parity_68_2)
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
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_68_1 == phase_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_91_1 == window_91_2);
  assert(parity_68_1 == parity_68_2);
}

int fn_R001540_4013_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001540_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int phase_68 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_68 = ((phase_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_68) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int window_91 = local_arr[aux % 3];
  acc = (acc + (window_91 * 2)) & 127;
  int parity_68 = (aux + st.buffer[1]) & 3;
  switch (parity_68)
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

void fn_R001540_4013_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001540_4013_2 st_1 = {0};
  struct Transaction_R001540_4013_2 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_88_1 = local_arr_1[aux_1 % 3];
  int metric_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_88_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_88_1 == metric_88_2);
}

int fn_R001540_4013_12(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001540_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_88 = local_arr[aux % 3];
  acc = (acc + (metric_88 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001540_4013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001540_4013_2 st_1 = {0};
  struct Transaction_R001540_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int bound_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_11_1 > 45)
  {
    acc_1 = ((acc_1 + (bound_11_1 * 2)) + 5) & 127;
    aux_1 ^= bound_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_11_2 > 45)
  {
    acc_2 = ((acc_2 + (bound_11_2 * 2)) + 5) & 127;
    aux_2 ^= bound_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_32_1) & 63;
  aux_2 = (aux_2 + accumulator_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_11_1 == bound_11_2);
  assert(accumulator_32_1 == accumulator_32_2);
}

int fn_R001540_4013_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001540_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int bound_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_11 > 45)
  {
    acc = ((acc + (bound_11 * 2)) + 5) & 127;
    aux ^= bound_11 & 15;
  }
  else
  {
    acc = ((acc - bound_11) + 11) & 127;
    aux += 3;
  }
  int accumulator_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_32) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001540_4013_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001540_4013_1 st_1 = {0};
  struct EventLog_R001540_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int metric_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_78_1 > 11)
  {
    acc_1 = ((acc_1 + (metric_78_1 * 2)) + 5) & 127;
    aux_1 ^= metric_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_78_2 > 11)
  {
    acc_2 = ((acc_2 + (metric_78_2 * 2)) + 5) & 127;
    aux_2 ^= metric_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_24_1)
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

  switch (coefficient_24_2)
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
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_78_1 == metric_78_2);
  assert(coefficient_24_1 == coefficient_24_2);
}

int fn_R001540_4013_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001540_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int metric_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_78 > 11)
  {
    acc = ((acc + (metric_78 * 2)) + 5) & 127;
    aux ^= metric_78 & 15;
  }
  else
  {
    acc = ((acc - metric_78) + 11) & 127;
    aux += 3;
  }
  int coefficient_24 = (aux + st.buffer[1]) & 3;
  switch (coefficient_24)
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

void fn_R001540_4013_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001540_4013_1 st_1 = {0};
  struct EventLog_R001540_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_63_1 = local_arr_1[aux_1 % 3];
  int threshold_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_63_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_42_1 = 0;
  int quotient_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_42_1 = ((quotient_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_42_2 = ((quotient_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_42_1) & 127;
    acc_2 = (acc_2 + quotient_42_2) & 127;
  }

  int phase_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_12_1 > 40)
  {
    acc_1 = ((acc_1 + (phase_12_1 * 2)) + 5) & 127;
    aux_1 ^= phase_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_12_2 > 40)
  {
    acc_2 = ((acc_2 + (phase_12_2 * 2)) + 5) & 127;
    aux_2 ^= phase_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_63_1 == threshold_63_2);
  assert(quotient_42_1 == quotient_42_2);
  assert(phase_12_1 == phase_12_2);
}

int fn_R001540_4013_15(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001540_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int threshold_63 = local_arr[aux % 3];
  acc = (acc + (threshold_63 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_42 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_42 = ((quotient_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_42) & 127;
  }

  int phase_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_12 > 40)
  {
    acc = ((acc + (phase_12 * 2)) + 5) & 127;
    aux ^= phase_12 & 15;
  }
  else
  {
    acc = ((acc - phase_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001540_4013_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001540_4013_3 st_1 = {0};
  struct DeviceConfig_R001540_4013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_62_1 = local_arr_1[aux_1 % 3];
  int offset_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_62_2 * 2)) & 127;
  int mask_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_74_1)
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

  switch (mask_74_2)
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

  int tally_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_15_1 > 44)
  {
    acc_1 = ((acc_1 + (tally_15_1 * 2)) + 5) & 127;
    aux_1 ^= tally_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_15_2 > 44)
  {
    acc_2 = ((acc_2 + (tally_15_2 * 2)) + 5) & 127;
    aux_2 ^= tally_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_15_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_62_1 == offset_62_2);
  assert(mask_74_1 == mask_74_2);
  assert(tally_15_1 == tally_15_2);
}

int fn_R001540_4013_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001540_4013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int offset_62 = local_arr[aux % 3];
  acc = (acc + (offset_62 * 2)) & 127;
  int mask_74 = (aux + st.buffer[1]) & 3;
  switch (mask_74)
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

  int tally_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_15 > 44)
  {
    acc = ((acc + (tally_15 * 2)) + 5) & 127;
    aux ^= tally_15 & 15;
  }
  else
  {
    acc = ((acc - tally_15) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001540_4013_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001540_4013_1 st_1 = {0};
  struct EventLog_R001540_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_60_1 = local_arr_1[aux_1 % 3];
  int metric_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_60_2 * 2)) & 127;
  int coefficient_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_20_1 > 27)
  {
    acc_1 = ((acc_1 + (coefficient_20_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_20_2 > 27)
  {
    acc_2 = ((acc_2 + (coefficient_20_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_20_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_60_1 == metric_60_2);
  assert(coefficient_20_1 == coefficient_20_2);
}

int fn_R001540_4013_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001540_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int metric_60 = local_arr[aux % 3];
  acc = (acc + (metric_60 * 2)) & 127;
  int coefficient_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_20 > 27)
  {
    acc = ((acc + (coefficient_20 * 2)) + 5) & 127;
    aux ^= coefficient_20 & 15;
  }
  else
  {
    acc = ((acc - coefficient_20) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001540_4013_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001540_4013_0 st_1 = {0};
  struct CipherContext_R001540_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int tracker_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_77_1) & 63;
  aux_2 = (aux_2 + tracker_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_13_1 = local_arr_1[aux_1 % 3];
  int cursor_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_13_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_77_1 == tracker_77_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_13_1 == cursor_13_2);
}

int fn_R001540_4013_18(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001540_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int tracker_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_77) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_13 = local_arr[aux % 3];
  acc = (acc + (cursor_13 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001540_4013_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001540_4013_2 st_1 = {0};
  struct Transaction_R001540_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int anchor_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_24_1)
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

  switch (anchor_24_2)
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

  int window_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_79_1 > 48)
  {
    acc_1 = ((acc_1 + (window_79_1 * 2)) + 5) & 127;
    aux_1 ^= window_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_79_2 > 48)
  {
    acc_2 = ((acc_2 + (window_79_2 * 2)) + 5) & 127;
    aux_2 ^= window_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_86_1 = 0;
  int tally_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_86_1 = ((tally_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_86_2 = ((tally_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_86_1) & 127;
    acc_2 = (acc_2 + tally_86_2) & 127;
  }

  int damping_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_81_1) & 63;
  aux_2 = (aux_2 + damping_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_24_1 == anchor_24_2);
  assert(window_79_1 == window_79_2);
  assert(tally_86_1 == tally_86_2);
  assert(damping_81_1 == damping_81_2);
}

int fn_R001540_4013_19(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001540_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int anchor_24 = (aux + st.buffer[1]) & 3;
  switch (anchor_24)
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

  int window_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_79 > 48)
  {
    acc = ((acc + (window_79 * 2)) + 5) & 127;
    aux ^= window_79 & 15;
  }
  else
  {
    acc = ((acc - window_79) + 11) & 127;
    aux += 3;
  }
  int tally_86 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_86 = ((tally_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_86) & 127;
  }

  int damping_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_81) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001540_4013_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001540_4013_2 st_1 = {0};
  struct Transaction_R001540_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int quotient_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_64_1)
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

  switch (quotient_64_2)
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
  int coefficient_62_1 = local_arr_1[aux_1 % 3];
  int coefficient_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_62_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_64_1 == quotient_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_62_1 == coefficient_62_2);
}

int fn_R001540_4013_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001540_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int quotient_64 = (aux + st.buffer[1]) & 3;
  switch (quotient_64)
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
  int coefficient_62 = local_arr[aux % 3];
  acc = (acc + (coefficient_62 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001540_4013_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001540_4013_3 st_1 = {0};
  struct DeviceConfig_R001540_4013_3 st_2 = {0};
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
  int metric_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_13_1)
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

  switch (metric_13_2)
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
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_13_1 == metric_13_2);
}

int fn_R001540_4013_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001540_4013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_13 = (aux + st.buffer[1]) & 3;
  switch (metric_13)
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

void main()
{
  int sec_r001540_0_1;
  int sec_r001540_0_2;
  int sec_r001540_1_1;
  int sec_r001540_1_2;
  int sec_r001540_2_1;
  int sec_r001540_2_2;
  int sec_r001540_3_1;
  int sec_r001540_3_2;
  int sec_r001540_4_1;
  int sec_r001540_4_2;
  int sec_r001540_5_1;
  int sec_r001540_5_2;
  int sec_r001540_6_1;
  int sec_r001540_6_2;
  int sec_r001540_7_1;
  int sec_r001540_7_2;
  int sec_r001540_8_1;
  int sec_r001540_8_2;
  int sec_r001540_9_1;
  int sec_r001540_9_2;
  int sec_r001540_10_1;
  int sec_r001540_10_2;
  int sec_r001540_11_1;
  int sec_r001540_11_2;
  int sec_r001540_12_1;
  int sec_r001540_12_2;
  int sec_r001540_13_1;
  int sec_r001540_13_2;
  int sec_r001540_14_1;
  int sec_r001540_14_2;
  int sec_r001540_15_1;
  int sec_r001540_15_2;
  int sec_r001540_16_1;
  int sec_r001540_16_2;
  int pub_r001540_0_1;
  int pub_r001540_0_2;
  int pub_r001540_1_1;
  int pub_r001540_1_2;
  int pub_r001540_2_1;
  int pub_r001540_2_2;
  int pub_r001540_3_1;
  int pub_r001540_3_2;
  int pub_r001540_4_1;
  int pub_r001540_4_2;
  int pub_r001540_5_1;
  int pub_r001540_5_2;
  int pub_r001540_6_1;
  int pub_r001540_6_2;
  int pub_r001540_7_1;
  int pub_r001540_7_2;
  int pub_r001540_8_1;
  int pub_r001540_8_2;
  int pub_r001540_9_1;
  int pub_r001540_9_2;
  int pub_r001540_10_1;
  int pub_r001540_10_2;
  int pub_r001540_11_1;
  int pub_r001540_11_2;
  int pub_r001540_12_1;
  int pub_r001540_12_2;
  int pub_r001540_13_1;
  int pub_r001540_13_2;
  int pub_r001540_14_1;
  int pub_r001540_14_2;
  int pub_r001540_15_1;
  int pub_r001540_15_2;
  int pub_r001540_16_1;
  int pub_r001540_16_2;
  int pub_r001540_17_1;
  int pub_r001540_17_2;
  int pub_r001540_18_1;
  int pub_r001540_18_2;
  int pub_r001540_19_1;
  int pub_r001540_19_2;
  int pub_r001540_20_1;
  int pub_r001540_20_2;
  int pub_r001540_21_1;
  int pub_r001540_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001540_0_1 >= (-100)) && (pub_r001540_0_1 <= 100));
  __CPROVER_assume((pub_r001540_0_2 >= (-100)) && (pub_r001540_0_2 <= 100));
  __CPROVER_assume((pub_r001540_1_1 >= (-100)) && (pub_r001540_1_1 <= 100));
  __CPROVER_assume((pub_r001540_1_2 >= (-100)) && (pub_r001540_1_2 <= 100));
  __CPROVER_assume((pub_r001540_2_1 >= (-100)) && (pub_r001540_2_1 <= 100));
  __CPROVER_assume((pub_r001540_2_2 >= (-100)) && (pub_r001540_2_2 <= 100));
  __CPROVER_assume((pub_r001540_3_1 >= (-100)) && (pub_r001540_3_1 <= 100));
  __CPROVER_assume((pub_r001540_3_2 >= (-100)) && (pub_r001540_3_2 <= 100));
  __CPROVER_assume((pub_r001540_4_1 >= (-100)) && (pub_r001540_4_1 <= 100));
  __CPROVER_assume((pub_r001540_4_2 >= (-100)) && (pub_r001540_4_2 <= 100));
  __CPROVER_assume((pub_r001540_5_1 >= (-100)) && (pub_r001540_5_1 <= 100));
  __CPROVER_assume((pub_r001540_5_2 >= (-100)) && (pub_r001540_5_2 <= 100));
  __CPROVER_assume((pub_r001540_6_1 >= (-100)) && (pub_r001540_6_1 <= 100));
  __CPROVER_assume((pub_r001540_6_2 >= (-100)) && (pub_r001540_6_2 <= 100));
  __CPROVER_assume((pub_r001540_7_1 >= (-100)) && (pub_r001540_7_1 <= 100));
  __CPROVER_assume((pub_r001540_7_2 >= (-100)) && (pub_r001540_7_2 <= 100));
  __CPROVER_assume((pub_r001540_8_1 >= (-100)) && (pub_r001540_8_1 <= 100));
  __CPROVER_assume((pub_r001540_8_2 >= (-100)) && (pub_r001540_8_2 <= 100));
  __CPROVER_assume((pub_r001540_9_1 >= (-100)) && (pub_r001540_9_1 <= 100));
  __CPROVER_assume((pub_r001540_9_2 >= (-100)) && (pub_r001540_9_2 <= 100));
  __CPROVER_assume((pub_r001540_10_1 >= (-100)) && (pub_r001540_10_1 <= 100));
  __CPROVER_assume((pub_r001540_10_2 >= (-100)) && (pub_r001540_10_2 <= 100));
  __CPROVER_assume((pub_r001540_11_1 >= (-100)) && (pub_r001540_11_1 <= 100));
  __CPROVER_assume((pub_r001540_11_2 >= (-100)) && (pub_r001540_11_2 <= 100));
  __CPROVER_assume((pub_r001540_12_1 >= (-100)) && (pub_r001540_12_1 <= 100));
  __CPROVER_assume((pub_r001540_12_2 >= (-100)) && (pub_r001540_12_2 <= 100));
  __CPROVER_assume((pub_r001540_13_1 >= (-100)) && (pub_r001540_13_1 <= 100));
  __CPROVER_assume((pub_r001540_13_2 >= (-100)) && (pub_r001540_13_2 <= 100));
  __CPROVER_assume((pub_r001540_14_1 >= (-100)) && (pub_r001540_14_1 <= 100));
  __CPROVER_assume((pub_r001540_14_2 >= (-100)) && (pub_r001540_14_2 <= 100));
  __CPROVER_assume((pub_r001540_15_1 >= (-100)) && (pub_r001540_15_1 <= 100));
  __CPROVER_assume((pub_r001540_15_2 >= (-100)) && (pub_r001540_15_2 <= 100));
  __CPROVER_assume((pub_r001540_16_1 >= (-100)) && (pub_r001540_16_1 <= 100));
  __CPROVER_assume((pub_r001540_16_2 >= (-100)) && (pub_r001540_16_2 <= 100));
  __CPROVER_assume((pub_r001540_17_1 >= (-100)) && (pub_r001540_17_1 <= 100));
  __CPROVER_assume((pub_r001540_17_2 >= (-100)) && (pub_r001540_17_2 <= 100));
  __CPROVER_assume((pub_r001540_18_1 >= (-100)) && (pub_r001540_18_1 <= 100));
  __CPROVER_assume((pub_r001540_18_2 >= (-100)) && (pub_r001540_18_2 <= 100));
  __CPROVER_assume((pub_r001540_19_1 >= (-100)) && (pub_r001540_19_1 <= 100));
  __CPROVER_assume((pub_r001540_19_2 >= (-100)) && (pub_r001540_19_2 <= 100));
  __CPROVER_assume((pub_r001540_20_1 >= (-100)) && (pub_r001540_20_1 <= 100));
  __CPROVER_assume((pub_r001540_20_2 >= (-100)) && (pub_r001540_20_2 <= 100));
  __CPROVER_assume((pub_r001540_21_1 >= (-100)) && (pub_r001540_21_1 <= 100));
  __CPROVER_assume((pub_r001540_21_2 >= (-100)) && (pub_r001540_21_2 <= 100));
  __CPROVER_assume((sec_r001540_0_1 >= 0) && (sec_r001540_0_1 <= 255));
  __CPROVER_assume((sec_r001540_0_2 >= 0) && (sec_r001540_0_2 <= 255));
  __CPROVER_assume((sec_r001540_1_1 >= 0) && (sec_r001540_1_1 <= 255));
  __CPROVER_assume((sec_r001540_1_2 >= 0) && (sec_r001540_1_2 <= 255));
  __CPROVER_assume((sec_r001540_2_1 >= 0) && (sec_r001540_2_1 <= 255));
  __CPROVER_assume((sec_r001540_2_2 >= 0) && (sec_r001540_2_2 <= 255));
  __CPROVER_assume((sec_r001540_3_1 >= 0) && (sec_r001540_3_1 <= 255));
  __CPROVER_assume((sec_r001540_3_2 >= 0) && (sec_r001540_3_2 <= 255));
  __CPROVER_assume((sec_r001540_4_1 >= 0) && (sec_r001540_4_1 <= 255));
  __CPROVER_assume((sec_r001540_4_2 >= 0) && (sec_r001540_4_2 <= 255));
  __CPROVER_assume((sec_r001540_5_1 >= 0) && (sec_r001540_5_1 <= 255));
  __CPROVER_assume((sec_r001540_5_2 >= 0) && (sec_r001540_5_2 <= 255));
  __CPROVER_assume((sec_r001540_6_1 >= 0) && (sec_r001540_6_1 <= 255));
  __CPROVER_assume((sec_r001540_6_2 >= 0) && (sec_r001540_6_2 <= 255));
  __CPROVER_assume((sec_r001540_7_1 >= 0) && (sec_r001540_7_1 <= 255));
  __CPROVER_assume((sec_r001540_7_2 >= 0) && (sec_r001540_7_2 <= 255));
  __CPROVER_assume((sec_r001540_8_1 >= 0) && (sec_r001540_8_1 <= 255));
  __CPROVER_assume((sec_r001540_8_2 >= 0) && (sec_r001540_8_2 <= 255));
  __CPROVER_assume((sec_r001540_9_1 >= 0) && (sec_r001540_9_1 <= 255));
  __CPROVER_assume((sec_r001540_9_2 >= 0) && (sec_r001540_9_2 <= 255));
  __CPROVER_assume((sec_r001540_10_1 >= 0) && (sec_r001540_10_1 <= 255));
  __CPROVER_assume((sec_r001540_10_2 >= 0) && (sec_r001540_10_2 <= 255));
  __CPROVER_assume((sec_r001540_11_1 >= 0) && (sec_r001540_11_1 <= 255));
  __CPROVER_assume((sec_r001540_11_2 >= 0) && (sec_r001540_11_2 <= 255));
  __CPROVER_assume((sec_r001540_12_1 >= 0) && (sec_r001540_12_1 <= 255));
  __CPROVER_assume((sec_r001540_12_2 >= 0) && (sec_r001540_12_2 <= 255));
  __CPROVER_assume((sec_r001540_13_1 >= 0) && (sec_r001540_13_1 <= 255));
  __CPROVER_assume((sec_r001540_13_2 >= 0) && (sec_r001540_13_2 <= 255));
  __CPROVER_assume((sec_r001540_14_1 >= 0) && (sec_r001540_14_1 <= 255));
  __CPROVER_assume((sec_r001540_14_2 >= 0) && (sec_r001540_14_2 <= 255));
  __CPROVER_assume((sec_r001540_15_1 >= 0) && (sec_r001540_15_1 <= 255));
  __CPROVER_assume((sec_r001540_15_2 >= 0) && (sec_r001540_15_2 <= 255));
  __CPROVER_assume((sec_r001540_16_1 >= 0) && (sec_r001540_16_1 <= 255));
  __CPROVER_assume((sec_r001540_16_2 >= 0) && (sec_r001540_16_2 <= 255));
  struct CipherContext_R001540_4013_0 st_var_0_1 = {0};
  struct CipherContext_R001540_4013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001540_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001540_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001540_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001540_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001540_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001540_0_2 + 7) & 15;
  struct EventLog_R001540_4013_1 st_var_1_1 = {0};
  struct EventLog_R001540_4013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001540_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001540_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001540_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001540_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001540_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001540_0_2 + 9) & 15;
  struct Transaction_R001540_4013_2 st_var_2_1 = {0};
  struct Transaction_R001540_4013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001540_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001540_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001540_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001540_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001540_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001540_0_2 + 11) & 15;
  struct DeviceConfig_R001540_4013_3 st_var_3_1 = {0};
  struct DeviceConfig_R001540_4013_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001540_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001540_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001540_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001540_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001540_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001540_0_2 + 13) & 15;
  union TelemetryField_R001540_4013_0 u_var_1;
  union TelemetryField_R001540_4013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001540_4013_0(sec_r001540_0_1, pub_r001540_1_1);
  int helper_flow_0_2 = fn_R001540_4013_0(sec_r001540_0_2, pub_r001540_1_2);
  fn_R001540_4013_0_2(sec_r001540_0_1, pub_r001540_1_1, sec_r001540_0_2, pub_r001540_1_2);
  int helper_flow_1_1 = fn_R001540_4013_1(sec_r001540_1_1, sec_r001540_2_1, pub_r001540_3_1);
  int helper_flow_1_2 = fn_R001540_4013_1(sec_r001540_1_2, sec_r001540_2_2, pub_r001540_3_2);
  fn_R001540_4013_1_2(sec_r001540_1_1, sec_r001540_2_1, pub_r001540_3_1, sec_r001540_1_2, sec_r001540_2_2, pub_r001540_3_2);
  int helper_flow_2_1 = fn_R001540_4013_2(sec_r001540_2_1, sec_r001540_3_1);
  int helper_flow_2_2 = fn_R001540_4013_2(sec_r001540_2_2, sec_r001540_3_2);
  fn_R001540_4013_2_2(sec_r001540_2_1, sec_r001540_3_1, sec_r001540_2_2, sec_r001540_3_2);
  int helper_flow_3_1 = fn_R001540_4013_3(sec_r001540_3_1, sec_r001540_4_1, pub_r001540_5_1, pub_r001540_6_1, pub_r001540_7_1);
  int helper_flow_3_2 = fn_R001540_4013_3(sec_r001540_3_2, sec_r001540_4_2, pub_r001540_5_2, pub_r001540_6_2, pub_r001540_7_2);
  fn_R001540_4013_3_2(sec_r001540_3_1, sec_r001540_4_1, pub_r001540_5_1, pub_r001540_6_1, pub_r001540_7_1, sec_r001540_3_2, sec_r001540_4_2, pub_r001540_5_2, pub_r001540_6_2, pub_r001540_7_2);
  int helper_flow_4_1 = fn_R001540_4013_4(sec_r001540_4_1, pub_r001540_5_1, pub_r001540_6_1, pub_r001540_7_1);
  int helper_flow_4_2 = fn_R001540_4013_4(sec_r001540_4_2, pub_r001540_5_2, pub_r001540_6_2, pub_r001540_7_2);
  fn_R001540_4013_4_2(sec_r001540_4_1, pub_r001540_5_1, pub_r001540_6_1, pub_r001540_7_1, sec_r001540_4_2, pub_r001540_5_2, pub_r001540_6_2, pub_r001540_7_2);
  int helper_flow_5_1 = fn_R001540_4013_5(sec_r001540_5_1, sec_r001540_6_1);
  int helper_flow_5_2 = fn_R001540_4013_5(sec_r001540_5_2, sec_r001540_6_2);
  fn_R001540_4013_5_2(sec_r001540_5_1, sec_r001540_6_1, sec_r001540_5_2, sec_r001540_6_2);
  int helper_flow_6_1 = fn_R001540_4013_6(sec_r001540_6_1, pub_r001540_7_1, pub_r001540_8_1, pub_r001540_9_1);
  int helper_flow_6_2 = fn_R001540_4013_6(sec_r001540_6_2, pub_r001540_7_2, pub_r001540_8_2, pub_r001540_9_2);
  fn_R001540_4013_6_2(sec_r001540_6_1, pub_r001540_7_1, pub_r001540_8_1, pub_r001540_9_1, sec_r001540_6_2, pub_r001540_7_2, pub_r001540_8_2, pub_r001540_9_2);
  int helper_flow_7_1 = fn_R001540_4013_7(sec_r001540_7_1, sec_r001540_8_1, pub_r001540_9_1, pub_r001540_10_1);
  int helper_flow_7_2 = fn_R001540_4013_7(sec_r001540_7_2, sec_r001540_8_2, pub_r001540_9_2, pub_r001540_10_2);
  fn_R001540_4013_7_2(sec_r001540_7_1, sec_r001540_8_1, pub_r001540_9_1, pub_r001540_10_1, sec_r001540_7_2, sec_r001540_8_2, pub_r001540_9_2, pub_r001540_10_2);
  int helper_flow_8_1 = fn_R001540_4013_8(sec_r001540_8_1, pub_r001540_9_1, pub_r001540_10_1, pub_r001540_11_1, pub_r001540_12_1);
  int helper_flow_8_2 = fn_R001540_4013_8(sec_r001540_8_2, pub_r001540_9_2, pub_r001540_10_2, pub_r001540_11_2, pub_r001540_12_2);
  fn_R001540_4013_8_2(sec_r001540_8_1, pub_r001540_9_1, pub_r001540_10_1, pub_r001540_11_1, pub_r001540_12_1, sec_r001540_8_2, pub_r001540_9_2, pub_r001540_10_2, pub_r001540_11_2, pub_r001540_12_2);
  int helper_flow_9_1 = fn_R001540_4013_9(sec_r001540_9_1, sec_r001540_10_1);
  int helper_flow_9_2 = fn_R001540_4013_9(sec_r001540_9_2, sec_r001540_10_2);
  fn_R001540_4013_9_2(sec_r001540_9_1, sec_r001540_10_1, sec_r001540_9_2, sec_r001540_10_2);
  int helper_flow_10_1 = fn_R001540_4013_10(sec_r001540_10_1, sec_r001540_11_1);
  int helper_flow_10_2 = fn_R001540_4013_10(sec_r001540_10_2, sec_r001540_11_2);
  fn_R001540_4013_10_2(sec_r001540_10_1, sec_r001540_11_1, sec_r001540_10_2, sec_r001540_11_2);
  int stage_v_0_1 = ((pub_r001540_3_1 * 2) + 23) & 63;
  int stage_v_0_2 = ((pub_r001540_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001540_5_1 * 2) + 35) & 63;
  int stage_v_1_2 = ((pub_r001540_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001540_13_1) & 127;
  int stage_v_2_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001540_13_2) & 127;
  if (stage_v_2_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001540_13_1) & 127;
  int stage_v_3_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001540_13_2) & 127;
  if (stage_v_3_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001540_15_1) & 127;
  int stage_v_4_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001540_15_2) & 127;
  if (stage_v_4_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (((sec_r001540_13_1 ^ 0x2A) * 2) + pub_r001540_5_1) & 127;
  int stage_v_5_2 = (((sec_r001540_13_2 ^ 0x2A) * 2) + pub_r001540_5_2) & 127;
  if (stage_v_5_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (((sec_r001540_6_1 ^ 0x2A) * 2) + pub_r001540_14_1) & 127;
  int stage_v_6_2 = (((sec_r001540_6_2 ^ 0x2A) * 2) + pub_r001540_14_2) & 127;
  if (stage_v_6_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001540_18_1) & 127;
  int stage_v_7_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001540_18_2) & 127;
  if (stage_v_7_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((sec_r001540_8_1 ^ 0x2A) * 2) + pub_r001540_21_1) & 127;
  int stage_v_8_2 = (((sec_r001540_8_2 ^ 0x2A) * 2) + pub_r001540_21_2) & 127;
  if (stage_v_8_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001540_18_1) & 127;
  int stage_v_9_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001540_18_2) & 127;
  if (stage_v_9_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001540_16_1) & 127;
  int stage_v_10_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001540_16_2) & 127;
  if (stage_v_10_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001540_3_1) & 127;
  int stage_v_11_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001540_3_2) & 127;
  if (stage_v_11_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (((sec_r001540_3_1 ^ 0x2A) * 2) + pub_r001540_5_1) & 127;
  int stage_v_12_2 = (((sec_r001540_3_2 ^ 0x2A) * 2) + pub_r001540_5_2) & 127;
  if (stage_v_12_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001540_2_1) & 127;
  int stage_v_13_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001540_2_2) & 127;
  if (stage_v_13_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001540_17_1) & 127;
  int stage_v_14_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001540_17_2) & 127;
  if (stage_v_14_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001540_6_1) & 127;
  int stage_v_15_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001540_6_2) & 127;
  if (stage_v_15_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (((sec_r001540_4_1 ^ 0x2A) * 2) + pub_r001540_4_1) & 127;
  int stage_v_16_2 = (((sec_r001540_4_2 ^ 0x2A) * 2) + pub_r001540_4_2) & 127;
  if (stage_v_16_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001540_2_1) & 127;
  int stage_v_17_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001540_2_2) & 127;
  if (stage_v_17_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001540_1_1) & 127;
  int stage_v_18_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001540_1_2) & 127;
  if (stage_v_18_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = ((pub_r001540_14_1 * 2) + 41) & 63;
  int stage_v_19_2 = ((pub_r001540_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001540_7_1) & 127;
  int stage_v_20_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001540_7_2) & 127;
  if (stage_v_20_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((sec_r001540_9_1 ^ 0x2A) * 2) + pub_r001540_4_1) & 127;
  int stage_v_21_2 = (((sec_r001540_9_2 ^ 0x2A) * 2) + pub_r001540_4_2) & 127;
  if (stage_v_21_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001540_19_1) & 127;
  int stage_v_22_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001540_19_2) & 127;
  if (stage_v_22_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = ((pub_r001540_14_1 * 2) + 49) & 63;
  int stage_v_23_2 = ((pub_r001540_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001540_21_1) & 127;
  int stage_v_24_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001540_21_2) & 127;
  if (stage_v_24_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (((sec_r001540_2_1 ^ 0x2A) * 2) + pub_r001540_12_1) & 127;
  int stage_v_25_2 = (((sec_r001540_2_2 ^ 0x2A) * 2) + pub_r001540_12_2) & 127;
  if (stage_v_25_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (((sec_r001540_11_1 ^ 0x2A) * 2) + pub_r001540_4_1) & 127;
  int stage_v_26_2 = (((sec_r001540_11_2 ^ 0x2A) * 2) + pub_r001540_4_2) & 127;
  if (stage_v_26_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001540_9_1) & 127;
  int stage_v_27_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001540_9_2) & 127;
  if (stage_v_27_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (((sec_r001540_13_1 ^ 0x2A) * 2) + pub_r001540_12_1) & 127;
  int stage_v_28_2 = (((sec_r001540_13_2 ^ 0x2A) * 2) + pub_r001540_12_2) & 127;
  if (stage_v_28_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (((sec_r001540_5_1 ^ 0x2A) * 2) + pub_r001540_10_1) & 127;
  int stage_v_29_2 = (((sec_r001540_5_2 ^ 0x2A) * 2) + pub_r001540_10_2) & 127;
  if (stage_v_29_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = ((pub_r001540_19_1 * 2) + 22) & 63;
  int stage_v_30_2 = ((pub_r001540_19_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001540_8_1) & 127;
  int stage_v_31_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001540_8_2) & 127;
  if (stage_v_31_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001540_7_1) & 127;
  int stage_v_32_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001540_7_2) & 127;
  if (stage_v_32_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001540_19_1) & 127;
  int stage_v_33_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001540_19_2) & 127;
  if (stage_v_33_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001540_18_1) & 127;
  int stage_v_34_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001540_18_2) & 127;
  if (stage_v_34_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((pub_r001540_14_1 * 2) + 40) & 63;
  int stage_v_35_2 = ((pub_r001540_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((sec_r001540_12_1 ^ 0x2A) * 2) + pub_r001540_19_1) & 127;
  int stage_v_36_2 = (((sec_r001540_12_2 ^ 0x2A) * 2) + pub_r001540_19_2) & 127;
  if (stage_v_36_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001540_12_1) & 127;
  int stage_v_37_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001540_12_2) & 127;
  if (stage_v_37_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((pub_r001540_12_1 * 2) + 10) & 63;
  int stage_v_38_2 = ((pub_r001540_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = (((sec_r001540_4_1 ^ 0x2A) * 2) + pub_r001540_1_1) & 127;
  int stage_v_39_2 = (((sec_r001540_4_2 ^ 0x2A) * 2) + pub_r001540_1_2) & 127;
  if (stage_v_39_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (((sec_r001540_11_1 ^ 0x2A) * 2) + pub_r001540_13_1) & 127;
  int stage_v_40_2 = (((sec_r001540_11_2 ^ 0x2A) * 2) + pub_r001540_13_2) & 127;
  if (stage_v_40_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001540_2_1) & 127;
  int stage_v_41_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001540_2_2) & 127;
  if (stage_v_41_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001540_4_1) & 127;
  int stage_v_42_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001540_4_2) & 127;
  if (stage_v_42_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (((sec_r001540_8_1 ^ 0x2A) * 2) + pub_r001540_16_1) & 127;
  int stage_v_43_2 = (((sec_r001540_8_2 ^ 0x2A) * 2) + pub_r001540_16_2) & 127;
  if (stage_v_43_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (((sec_r001540_7_1 ^ 0x2A) * 2) + pub_r001540_5_1) & 127;
  int stage_v_44_2 = (((sec_r001540_7_2 ^ 0x2A) * 2) + pub_r001540_5_2) & 127;
  if (stage_v_44_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((pub_r001540_17_1 * 2) + 26) & 63;
  int stage_v_45_2 = ((pub_r001540_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((sec_r001540_10_1 ^ 0x2A) * 2) + pub_r001540_4_1) & 127;
  int stage_v_46_2 = (((sec_r001540_10_2 ^ 0x2A) * 2) + pub_r001540_4_2) & 127;
  if (stage_v_46_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((pub_r001540_1_1 * 2) + 19) & 63;
  int stage_v_47_2 = ((pub_r001540_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001540_8_1) & 127;
  int stage_v_48_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001540_8_2) & 127;
  if (stage_v_48_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((pub_r001540_14_1 * 2) + 24) & 63;
  int stage_v_49_2 = ((pub_r001540_14_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (((sec_r001540_4_1 ^ 0x2A) * 2) + pub_r001540_0_1) & 127;
  int stage_v_50_2 = (((sec_r001540_4_2 ^ 0x2A) * 2) + pub_r001540_0_2) & 127;
  if (stage_v_50_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((pub_r001540_17_1 * 2) + 23) & 63;
  int stage_v_51_2 = ((pub_r001540_17_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001540_7_1) & 127;
  int stage_v_52_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001540_7_2) & 127;
  if (stage_v_52_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (((sec_r001540_0_1 ^ 0x2A) * 2) + pub_r001540_14_1) & 127;
  int stage_v_53_2 = (((sec_r001540_0_2 ^ 0x2A) * 2) + pub_r001540_14_2) & 127;
  if (stage_v_53_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001540_1_1) & 127;
  int stage_v_54_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001540_1_2) & 127;
  if (stage_v_54_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001540_8_1) & 127;
  int stage_v_55_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001540_8_2) & 127;
  if (stage_v_55_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001540_8_1) & 127;
  int stage_v_56_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001540_8_2) & 127;
  if (stage_v_56_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((sec_r001540_12_1 ^ 0x2A) * 2) + pub_r001540_21_1) & 127;
  int stage_v_57_2 = (((sec_r001540_12_2 ^ 0x2A) * 2) + pub_r001540_21_2) & 127;
  if (stage_v_57_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((pub_r001540_17_1 * 2) + 25) & 63;
  int stage_v_58_2 = ((pub_r001540_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (((sec_r001540_16_1 ^ 0x2A) * 2) + pub_r001540_6_1) & 127;
  int stage_v_59_2 = (((sec_r001540_16_2 ^ 0x2A) * 2) + pub_r001540_6_2) & 127;
  if (stage_v_59_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((pub_r001540_5_1 * 2) + 25) & 63;
  int stage_v_60_2 = ((pub_r001540_5_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001540_16_1) & 127;
  int stage_v_61_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001540_16_2) & 127;
  if (stage_v_61_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((pub_r001540_20_1 * 2) + 16) & 63;
  int stage_v_62_2 = ((pub_r001540_20_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001540_18_1 * 2) + 27) & 63;
  int stage_v_63_2 = ((pub_r001540_18_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001540_16_1 * 2) + 20) & 63;
  int stage_v_64_2 = ((pub_r001540_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = (((sec_r001540_12_1 ^ 0x2A) * 2) + pub_r001540_7_1) & 127;
  int stage_v_65_2 = (((sec_r001540_12_2 ^ 0x2A) * 2) + pub_r001540_7_2) & 127;
  if (stage_v_65_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (((sec_r001540_3_1 ^ 0x2A) * 2) + pub_r001540_17_1) & 127;
  int stage_v_66_2 = (((sec_r001540_3_2 ^ 0x2A) * 2) + pub_r001540_17_2) & 127;
  if (stage_v_66_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001540_14_1) & 127;
  int stage_v_67_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001540_14_2) & 127;
  if (stage_v_67_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001540_8_1) & 127;
  int stage_v_68_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001540_8_2) & 127;
  if (stage_v_68_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001540_17_1) & 127;
  int stage_v_69_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001540_17_2) & 127;
  if (stage_v_69_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001540_16_1) & 127;
  int stage_v_70_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001540_16_2) & 127;
  if (stage_v_70_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (((sec_r001540_6_1 ^ 0x2A) * 2) + pub_r001540_11_1) & 127;
  int stage_v_71_2 = (((sec_r001540_6_2 ^ 0x2A) * 2) + pub_r001540_11_2) & 127;
  if (stage_v_71_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001540_7_1) & 127;
  int stage_v_72_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001540_7_2) & 127;
  if (stage_v_72_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = (((sec_r001540_11_1 ^ 0x2A) * 2) + pub_r001540_14_1) & 127;
  int stage_v_73_2 = (((sec_r001540_11_2 ^ 0x2A) * 2) + pub_r001540_14_2) & 127;
  if (stage_v_73_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001540_15_1) & 127;
  int stage_v_74_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001540_15_2) & 127;
  if (stage_v_74_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001540_1_1) & 127;
  int stage_v_75_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001540_1_2) & 127;
  if (stage_v_75_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001540_20_1) & 127;
  int stage_v_76_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001540_20_2) & 127;
  if (stage_v_76_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((pub_r001540_5_1 * 2) + 42) & 63;
  int stage_v_77_2 = ((pub_r001540_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001540_0_1) & 127;
  int stage_v_78_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001540_0_2) & 127;
  if (stage_v_78_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001540_1_1) & 127;
  int stage_v_79_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001540_1_2) & 127;
  if (stage_v_79_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((stage_v_68_1 ^ 0x2A) * 2) + pub_r001540_19_1) & 127;
  int stage_v_80_2 = (((stage_v_68_2 ^ 0x2A) * 2) + pub_r001540_19_2) & 127;
  if (stage_v_80_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((pub_r001540_11_1 * 2) + 15) & 63;
  int stage_v_81_2 = ((pub_r001540_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001540_2_1) & 127;
  int stage_v_82_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001540_2_2) & 127;
  if (stage_v_82_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((pub_r001540_17_1 * 2) + 35) & 63;
  int stage_v_83_2 = ((pub_r001540_17_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001540_11_1) & 127;
  int stage_v_84_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001540_11_2) & 127;
  if (stage_v_84_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (((stage_v_33_1 ^ 0x2A) * 2) + pub_r001540_2_1) & 127;
  int stage_v_85_2 = (((stage_v_33_2 ^ 0x2A) * 2) + pub_r001540_2_2) & 127;
  if (stage_v_85_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((pub_r001540_9_1 * 2) + 29) & 63;
  int stage_v_86_2 = ((pub_r001540_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001540_11_1) & 127;
  int stage_v_87_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001540_11_2) & 127;
  if (stage_v_87_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001540_13_1) & 127;
  int stage_v_88_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001540_13_2) & 127;
  if (stage_v_88_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (((stage_v_88_1 ^ 0x2A) * 2) + pub_r001540_12_1) & 127;
  int stage_v_89_2 = (((stage_v_88_2 ^ 0x2A) * 2) + pub_r001540_12_2) & 127;
  if (stage_v_89_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((pub_r001540_10_1 * 2) + 50) & 63;
  int stage_v_90_2 = ((pub_r001540_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001540_4_1) & 127;
  int stage_v_91_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001540_4_2) & 127;
  if (stage_v_91_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = (((sec_r001540_14_1 ^ 0x2A) * 2) + pub_r001540_12_1) & 127;
  int stage_v_92_2 = (((sec_r001540_14_2 ^ 0x2A) * 2) + pub_r001540_12_2) & 127;
  if (stage_v_92_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001540_17_1) & 127;
  int stage_v_93_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001540_17_2) & 127;
  if (stage_v_93_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001540_5_1) & 127;
  int stage_v_94_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001540_5_2) & 127;
  if (stage_v_94_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((pub_r001540_5_1 * 2) + 32) & 63;
  int stage_v_95_2 = ((pub_r001540_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001540_20_1 * 2) + 31) & 63;
  int stage_v_96_2 = ((pub_r001540_20_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001540_18_1) & 127;
  int stage_v_97_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001540_18_2) & 127;
  if (stage_v_97_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001540_16_1) & 127;
  int stage_v_98_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001540_16_2) & 127;
  if (stage_v_98_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((pub_r001540_14_1 * 2) + 43) & 63;
  int stage_v_99_2 = ((pub_r001540_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001540_19_1) & 127;
  int stage_v_100_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001540_19_2) & 127;
  if (stage_v_100_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001540_13_1) & 127;
  int stage_v_101_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001540_13_2) & 127;
  if (stage_v_101_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((pub_r001540_0_1 * 2) + 6) & 63;
  int stage_v_102_2 = ((pub_r001540_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001540_20_1) & 127;
  int stage_v_103_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001540_20_2) & 127;
  if (stage_v_103_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001540_8_1) & 127;
  int stage_v_104_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001540_8_2) & 127;
  if (stage_v_104_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001540_3_1) & 127;
  int stage_v_105_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001540_3_2) & 127;
  if (stage_v_105_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001540_0_1) & 127;
  int stage_v_106_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001540_0_2) & 127;
  if (stage_v_106_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((pub_r001540_20_1 * 2) + 23) & 63;
  int stage_v_107_2 = ((pub_r001540_20_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001540_1_1 * 2) + 27) & 63;
  int stage_v_108_2 = ((pub_r001540_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (((stage_v_100_1 ^ 0x2A) * 2) + pub_r001540_1_1) & 127;
  int stage_v_109_2 = (((stage_v_100_2 ^ 0x2A) * 2) + pub_r001540_1_2) & 127;
  if (stage_v_109_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001540_19_1) & 127;
  int stage_v_110_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001540_19_2) & 127;
  if (stage_v_110_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (((sec_r001540_2_1 ^ 0x2A) * 2) + pub_r001540_10_1) & 127;
  int stage_v_111_2 = (((sec_r001540_2_2 ^ 0x2A) * 2) + pub_r001540_10_2) & 127;
  if (stage_v_111_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = (((sec_r001540_4_1 ^ 0x2A) * 2) + pub_r001540_0_1) & 127;
  int stage_v_112_2 = (((sec_r001540_4_2 ^ 0x2A) * 2) + pub_r001540_0_2) & 127;
  if (stage_v_112_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001540_4_1) & 127;
  int stage_v_113_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001540_4_2) & 127;
  if (stage_v_113_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((pub_r001540_8_1 * 2) + 35) & 63;
  int stage_v_114_2 = ((pub_r001540_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001540_2_1 * 2) + 50) & 63;
  int stage_v_115_2 = ((pub_r001540_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001540_7_1) & 127;
  int stage_v_116_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001540_7_2) & 127;
  if (stage_v_116_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((pub_r001540_14_1 * 2) + 22) & 63;
  int stage_v_117_2 = ((pub_r001540_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((stage_v_72_1 ^ 0x2A) * 2) + pub_r001540_8_1) & 127;
  int stage_v_118_2 = (((stage_v_72_2 ^ 0x2A) * 2) + pub_r001540_8_2) & 127;
  if (stage_v_118_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001540_5_1) & 127;
  int stage_v_119_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001540_5_2) & 127;
  if (stage_v_119_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (((sec_r001540_9_1 ^ 0x2A) * 2) + pub_r001540_9_1) & 127;
  int stage_v_120_2 = (((sec_r001540_9_2 ^ 0x2A) * 2) + pub_r001540_9_2) & 127;
  if (stage_v_120_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001540_11_1) & 127;
  int stage_v_121_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001540_11_2) & 127;
  if (stage_v_121_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((pub_r001540_18_1 * 2) + 27) & 63;
  int stage_v_122_2 = ((pub_r001540_18_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001540_8_1) & 127;
  int stage_v_123_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001540_8_2) & 127;
  if (stage_v_123_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001540_19_1) & 127;
  int stage_v_124_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001540_19_2) & 127;
  if (stage_v_124_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((pub_r001540_15_1 * 2) + 9) & 63;
  int stage_v_125_2 = ((pub_r001540_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((sec_r001540_15_1 ^ 0x2A) * 2) + pub_r001540_16_1) & 127;
  int stage_v_126_2 = (((sec_r001540_15_2 ^ 0x2A) * 2) + pub_r001540_16_2) & 127;
  if (stage_v_126_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((stage_v_50_1 ^ 0x2A) * 2) + pub_r001540_2_1) & 127;
  int stage_v_127_2 = (((stage_v_50_2 ^ 0x2A) * 2) + pub_r001540_2_2) & 127;
  if (stage_v_127_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001540_14_1) & 127;
  int stage_v_128_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001540_14_2) & 127;
  if (stage_v_128_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((pub_r001540_9_1 * 2) + 38) & 63;
  int stage_v_129_2 = ((pub_r001540_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001540_21_1 * 2) + 6) & 63;
  int stage_v_130_2 = ((pub_r001540_21_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001540_3_1) & 127;
  int stage_v_131_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001540_3_2) & 127;
  if (stage_v_131_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001540_2_1) & 127;
  int stage_v_132_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001540_2_2) & 127;
  if (stage_v_132_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (((stage_v_105_1 ^ 0x2A) * 2) + pub_r001540_13_1) & 127;
  int stage_v_133_2 = (((stage_v_105_2 ^ 0x2A) * 2) + pub_r001540_13_2) & 127;
  if (stage_v_133_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001540_5_1) & 127;
  int stage_v_134_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001540_5_2) & 127;
  if (stage_v_134_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = (((stage_v_104_1 ^ 0x2A) * 2) + pub_r001540_16_1) & 127;
  int stage_v_135_2 = (((stage_v_104_2 ^ 0x2A) * 2) + pub_r001540_16_2) & 127;
  if (stage_v_135_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001540_10_1) & 127;
  int stage_v_136_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001540_10_2) & 127;
  if (stage_v_136_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = (((stage_v_105_1 ^ 0x2A) * 2) + pub_r001540_9_1) & 127;
  int stage_v_137_2 = (((stage_v_105_2 ^ 0x2A) * 2) + pub_r001540_9_2) & 127;
  if (stage_v_137_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001540_3_1) & 127;
  int stage_v_138_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001540_3_2) & 127;
  if (stage_v_138_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001540_18_1) & 127;
  int stage_v_139_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001540_18_2) & 127;
  if (stage_v_139_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001540_5_1) & 127;
  int stage_v_140_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001540_5_2) & 127;
  if (stage_v_140_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001540_19_1) & 127;
  int stage_v_141_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001540_19_2) & 127;
  if (stage_v_141_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001540_0_1) & 127;
  int stage_v_142_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001540_0_2) & 127;
  if (stage_v_142_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((pub_r001540_19_1 * 2) + 31) & 63;
  int stage_v_143_2 = ((pub_r001540_19_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (((sec_r001540_10_1 ^ 0x2A) * 2) + pub_r001540_18_1) & 127;
  int stage_v_144_2 = (((sec_r001540_10_2 ^ 0x2A) * 2) + pub_r001540_18_2) & 127;
  if (stage_v_144_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001540_20_1) & 127;
  int stage_v_145_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001540_20_2) & 127;
  if (stage_v_145_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001540_14_1) & 127;
  int stage_v_146_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001540_14_2) & 127;
  if (stage_v_146_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((pub_r001540_15_1 * 2) + 45) & 63;
  int stage_v_147_2 = ((pub_r001540_15_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001540_8_1) & 127;
  int stage_v_148_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001540_8_2) & 127;
  if (stage_v_148_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001540_8_1) & 127;
  int stage_v_149_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001540_8_2) & 127;
  if (stage_v_149_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001540_6_1) & 127;
  int stage_v_150_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001540_6_2) & 127;
  if (stage_v_150_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = (((stage_v_124_1 ^ 0x2A) * 2) + pub_r001540_17_1) & 127;
  int stage_v_151_2 = (((stage_v_124_2 ^ 0x2A) * 2) + pub_r001540_17_2) & 127;
  if (stage_v_151_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((pub_r001540_2_1 * 2) + 34) & 63;
  int stage_v_152_2 = ((pub_r001540_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001540_16_1) & 127;
  int stage_v_153_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001540_16_2) & 127;
  if (stage_v_153_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((pub_r001540_9_1 * 2) + 33) & 63;
  int stage_v_154_2 = ((pub_r001540_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001540_6_1) & 127;
  int stage_v_155_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001540_6_2) & 127;
  if (stage_v_155_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((pub_r001540_10_1 * 2) + 44) & 63;
  int stage_v_156_2 = ((pub_r001540_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001540_21_1 * 2) + 22) & 63;
  int stage_v_157_2 = ((pub_r001540_21_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = (((stage_v_132_1 ^ 0x2A) * 2) + pub_r001540_11_1) & 127;
  int stage_v_158_2 = (((stage_v_132_2 ^ 0x2A) * 2) + pub_r001540_11_2) & 127;
  if (stage_v_158_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001540_4_1) & 127;
  int stage_v_159_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001540_4_2) & 127;
  if (stage_v_159_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001540_11_1) & 127;
  int stage_v_160_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001540_11_2) & 127;
  if (stage_v_160_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001540_4_1) & 127;
  int stage_v_161_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001540_4_2) & 127;
  if (stage_v_161_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (((stage_v_151_1 ^ 0x2A) * 2) + pub_r001540_1_1) & 127;
  int stage_v_162_2 = (((stage_v_151_2 ^ 0x2A) * 2) + pub_r001540_1_2) & 127;
  if (stage_v_162_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (((stage_v_50_1 ^ 0x2A) * 2) + pub_r001540_9_1) & 127;
  int stage_v_163_2 = (((stage_v_50_2 ^ 0x2A) * 2) + pub_r001540_9_2) & 127;
  if (stage_v_163_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((pub_r001540_17_1 * 2) + 12) & 63;
  int stage_v_164_2 = ((pub_r001540_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001540_16_1) & 127;
  int stage_v_165_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001540_16_2) & 127;
  if (stage_v_165_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (((sec_r001540_8_1 ^ 0x2A) * 2) + pub_r001540_8_1) & 127;
  int stage_v_166_2 = (((sec_r001540_8_2 ^ 0x2A) * 2) + pub_r001540_8_2) & 127;
  if (stage_v_166_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((pub_r001540_21_1 * 2) + 19) & 63;
  int stage_v_167_2 = ((pub_r001540_21_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001540_19_1 * 2) + 15) & 63;
  int stage_v_168_2 = ((pub_r001540_19_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (((stage_v_136_1 ^ 0x2A) * 2) + pub_r001540_10_1) & 127;
  int stage_v_169_2 = (((stage_v_136_2 ^ 0x2A) * 2) + pub_r001540_10_2) & 127;
  if (stage_v_169_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((stage_v_155_1 ^ 0x2A) * 2) + pub_r001540_2_1) & 127;
  int stage_v_170_2 = (((stage_v_155_2 ^ 0x2A) * 2) + pub_r001540_2_2) & 127;
  if (stage_v_170_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((pub_r001540_8_1 * 2) + 36) & 63;
  int stage_v_171_2 = ((pub_r001540_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((stage_v_138_1 ^ 0x2A) * 2) + pub_r001540_1_1) & 127;
  int stage_v_172_2 = (((stage_v_138_2 ^ 0x2A) * 2) + pub_r001540_1_2) & 127;
  if (stage_v_172_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001540_11_1) & 127;
  int stage_v_173_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001540_11_2) & 127;
  if (stage_v_173_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = (((stage_v_132_1 ^ 0x2A) * 2) + pub_r001540_18_1) & 127;
  int stage_v_174_2 = (((stage_v_132_2 ^ 0x2A) * 2) + pub_r001540_18_2) & 127;
  if (stage_v_174_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001540_0_1) & 127;
  int stage_v_175_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001540_0_2) & 127;
  if (stage_v_175_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001540_16_1) & 127;
  int stage_v_176_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001540_16_2) & 127;
  if (stage_v_176_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((pub_r001540_3_1 * 2) + 6) & 63;
  int stage_v_177_2 = ((pub_r001540_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001540_3_1) & 127;
  int stage_v_178_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001540_3_2) & 127;
  if (stage_v_178_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((pub_r001540_16_1 * 2) + 27) & 63;
  int stage_v_179_2 = ((pub_r001540_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001540_1_1) & 127;
  int stage_v_180_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001540_1_2) & 127;
  if (stage_v_180_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = (((stage_v_165_1 ^ 0x2A) * 2) + pub_r001540_2_1) & 127;
  int stage_v_181_2 = (((stage_v_165_2 ^ 0x2A) * 2) + pub_r001540_2_2) & 127;
  if (stage_v_181_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = (((sec_r001540_4_1 ^ 0x2A) * 2) + pub_r001540_8_1) & 127;
  int stage_v_182_2 = (((sec_r001540_4_2 ^ 0x2A) * 2) + pub_r001540_8_2) & 127;
  if (stage_v_182_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001540_21_1) & 127;
  int stage_v_183_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001540_21_2) & 127;
  if (stage_v_183_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = (((stage_v_155_1 ^ 0x2A) * 2) + pub_r001540_10_1) & 127;
  int stage_v_184_2 = (((stage_v_155_2 ^ 0x2A) * 2) + pub_r001540_10_2) & 127;
  if (stage_v_184_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001540_3_1) & 127;
  int stage_v_185_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001540_3_2) & 127;
  if (stage_v_185_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = (((stage_v_135_1 ^ 0x2A) * 2) + pub_r001540_15_1) & 127;
  int stage_v_186_2 = (((stage_v_135_2 ^ 0x2A) * 2) + pub_r001540_15_2) & 127;
  if (stage_v_186_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((pub_r001540_2_1 * 2) + 13) & 63;
  int stage_v_187_2 = ((pub_r001540_2_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((stage_v_140_1 ^ 0x2A) * 2) + pub_r001540_17_1) & 127;
  int stage_v_188_2 = (((stage_v_140_2 ^ 0x2A) * 2) + pub_r001540_17_2) & 127;
  if (stage_v_188_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = (((stage_v_79_1 ^ 0x2A) * 2) + pub_r001540_17_1) & 127;
  int stage_v_189_2 = (((stage_v_79_2 ^ 0x2A) * 2) + pub_r001540_17_2) & 127;
  if (stage_v_189_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((stage_v_150_1 ^ 0x2A) * 2) + pub_r001540_8_1) & 127;
  int stage_v_190_2 = (((stage_v_150_2 ^ 0x2A) * 2) + pub_r001540_8_2) & 127;
  if (stage_v_190_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((pub_r001540_15_1 * 2) + 26) & 63;
  int stage_v_191_2 = ((pub_r001540_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = (((sec_r001540_9_1 ^ 0x2A) * 2) + pub_r001540_1_1) & 127;
  int stage_v_192_2 = (((sec_r001540_9_2 ^ 0x2A) * 2) + pub_r001540_1_2) & 127;
  if (stage_v_192_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((stage_v_145_1 ^ 0x2A) * 2) + pub_r001540_16_1) & 127;
  int stage_v_193_2 = (((stage_v_145_2 ^ 0x2A) * 2) + pub_r001540_16_2) & 127;
  if (stage_v_193_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001540_17_1) & 127;
  int stage_v_194_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001540_17_2) & 127;
  if (stage_v_194_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((pub_r001540_5_1 * 2) + 9) & 63;
  int stage_v_195_2 = ((pub_r001540_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001540_12_1) & 127;
  int stage_v_196_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001540_12_2) & 127;
  if (stage_v_196_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001540_8_1) & 127;
  int stage_v_197_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001540_8_2) & 127;
  if (stage_v_197_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001540_2_1) & 127;
  int stage_v_198_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001540_2_2) & 127;
  if (stage_v_198_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = (((stage_v_142_1 ^ 0x2A) * 2) + pub_r001540_2_1) & 127;
  int stage_v_199_2 = (((stage_v_142_2 ^ 0x2A) * 2) + pub_r001540_2_2) & 127;
  if (stage_v_199_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((pub_r001540_18_1 * 2) + 46) & 63;
  int stage_v_200_2 = ((pub_r001540_18_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = (((sec_r001540_16_1 ^ 0x2A) * 2) + pub_r001540_13_1) & 127;
  int stage_v_201_2 = (((sec_r001540_16_2 ^ 0x2A) * 2) + pub_r001540_13_2) & 127;
  if (stage_v_201_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = (((stage_v_131_1 ^ 0x2A) * 2) + pub_r001540_5_1) & 127;
  int stage_v_202_2 = (((stage_v_131_2 ^ 0x2A) * 2) + pub_r001540_5_2) & 127;
  if (stage_v_202_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001540_2_1) & 127;
  int stage_v_203_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001540_2_2) & 127;
  if (stage_v_203_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((pub_r001540_17_1 * 2) + 33) & 63;
  int stage_v_204_2 = ((pub_r001540_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((pub_r001540_21_1 * 2) + 47) & 63;
  int stage_v_205_2 = ((pub_r001540_21_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001540_11_1 * 2) + 47) & 63;
  int stage_v_206_2 = ((pub_r001540_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001540_3_1) & 127;
  int stage_v_207_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001540_3_2) & 127;
  if (stage_v_207_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001540_9_1) & 127;
  int stage_v_208_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001540_9_2) & 127;
  if (stage_v_208_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = (((stage_v_68_1 ^ 0x2A) * 2) + pub_r001540_8_1) & 127;
  int stage_v_209_2 = (((stage_v_68_2 ^ 0x2A) * 2) + pub_r001540_8_2) & 127;
  if (stage_v_209_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001540_13_1) & 127;
  int stage_v_210_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001540_13_2) & 127;
  if (stage_v_210_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
  }
  if (stage_v_210_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = (((stage_v_176_1 ^ 0x2A) * 2) + pub_r001540_0_1) & 127;
  int stage_v_211_2 = (((stage_v_176_2 ^ 0x2A) * 2) + pub_r001540_0_2) & 127;
  if (stage_v_211_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((pub_r001540_17_1 * 2) + 23) & 63;
  int stage_v_212_2 = ((pub_r001540_17_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = (((stage_v_52_1 ^ 0x2A) * 2) + pub_r001540_8_1) & 127;
  int stage_v_213_2 = (((stage_v_52_2 ^ 0x2A) * 2) + pub_r001540_8_2) & 127;
  if (stage_v_213_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((pub_r001540_1_1 * 2) + 39) & 63;
  int stage_v_214_2 = ((pub_r001540_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((stage_v_153_1 ^ 0x2A) * 2) + pub_r001540_10_1) & 127;
  int stage_v_215_2 = (((stage_v_153_2 ^ 0x2A) * 2) + pub_r001540_10_2) & 127;
  if (stage_v_215_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
  }
  if (stage_v_215_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001540_11_1) & 127;
  int stage_v_216_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001540_11_2) & 127;
  if (stage_v_216_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
  }
  if (stage_v_216_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001540_0_1) & 127;
  int stage_v_217_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001540_0_2) & 127;
  if (stage_v_217_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001540_21_1) & 127;
  int stage_v_218_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001540_21_2) & 127;
  if (stage_v_218_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001540_17_1) & 127;
  int stage_v_219_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001540_17_2) & 127;
  if (stage_v_219_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001540_0_1) & 127;
  int stage_v_220_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001540_0_2) & 127;
  if (stage_v_220_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
  }
  if (stage_v_220_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = (((stage_v_128_1 ^ 0x2A) * 2) + pub_r001540_14_1) & 127;
  int stage_v_221_2 = (((stage_v_128_2 ^ 0x2A) * 2) + pub_r001540_14_2) & 127;
  if (stage_v_221_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001540_0_1 != sec_r001540_0_2);
  __CPROVER_assume(pub_r001540_4_1 == pub_r001540_4_2);
  __CPROVER_assume(pub_r001540_6_1 == pub_r001540_6_2);
  __CPROVER_assume(pub_r001540_8_1 == pub_r001540_8_2);
  __CPROVER_assume(sec_r001540_6_1 != sec_r001540_6_2);
  __CPROVER_assume(pub_r001540_15_1 == pub_r001540_15_2);
  __CPROVER_assume(sec_r001540_14_1 != sec_r001540_14_2);
  __CPROVER_assume(pub_r001540_2_1 == pub_r001540_2_2);
  __CPROVER_assume(pub_r001540_21_1 == pub_r001540_21_2);
  __CPROVER_assume(sec_r001540_15_1 != sec_r001540_15_2);
  __CPROVER_assume(sec_r001540_16_1 != sec_r001540_16_2);
  __CPROVER_assume(sec_r001540_13_1 != sec_r001540_13_2);
  __CPROVER_assume(pub_r001540_5_1 == pub_r001540_5_2);
  __CPROVER_assume(sec_r001540_11_1 != sec_r001540_11_2);
  __CPROVER_assume(sec_r001540_4_1 != sec_r001540_4_2);
  __CPROVER_assume(pub_r001540_3_1 == pub_r001540_3_2);
  __CPROVER_assume(sec_r001540_12_1 != sec_r001540_12_2);
  __CPROVER_assume(sec_r001540_2_1 != sec_r001540_2_2);
  __CPROVER_assume(pub_r001540_7_1 == pub_r001540_7_2);
  __CPROVER_assume(sec_r001540_5_1 != sec_r001540_5_2);
  __CPROVER_assume(pub_r001540_1_1 == pub_r001540_1_2);
  __CPROVER_assume(pub_r001540_16_1 == pub_r001540_16_2);
  __CPROVER_assume(pub_r001540_11_1 == pub_r001540_11_2);
  __CPROVER_assume(pub_r001540_13_1 == pub_r001540_13_2);
  __CPROVER_assume(sec_r001540_10_1 != sec_r001540_10_2);
  __CPROVER_assume(pub_r001540_20_1 == pub_r001540_20_2);
  __CPROVER_assume(pub_r001540_17_1 == pub_r001540_17_2);
  __CPROVER_assume(pub_r001540_14_1 == pub_r001540_14_2);
  __CPROVER_assume(pub_r001540_18_1 == pub_r001540_18_2);
  __CPROVER_assume(pub_r001540_9_1 == pub_r001540_9_2);
  __CPROVER_assume(sec_r001540_3_1 != sec_r001540_3_2);
  __CPROVER_assume(pub_r001540_19_1 == pub_r001540_19_2);
  __CPROVER_assume(pub_r001540_12_1 == pub_r001540_12_2);
  __CPROVER_assume(sec_r001540_8_1 != sec_r001540_8_2);
  __CPROVER_assume(sec_r001540_9_1 != sec_r001540_9_2);
  __CPROVER_assume(sec_r001540_1_1 != sec_r001540_1_2);
  __CPROVER_assume(pub_r001540_10_1 == pub_r001540_10_2);
  __CPROVER_assume(pub_r001540_0_1 == pub_r001540_0_2);
  __CPROVER_assume(sec_r001540_7_1 != sec_r001540_7_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.code == st_var_1_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.balance == st_var_2_2.balance);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.auth_code == st_var_2_2.auth_code);
  assert(st_var_2_1.rate == st_var_2_2.rate);
  assert(st_var_2_1.fee == st_var_2_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.parity == st_var_3_2.parity);
  assert(st_var_3_1.port == st_var_3_2.port);
  assert(st_var_3_1.timeout == st_var_3_2.timeout);
  assert(st_var_3_1.stop_bits == st_var_3_2.stop_bits);
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

  assert(helper_flow_0_1 == helper_flow_0_2);
  assert(helper_flow_1_1 == helper_flow_1_2);
  assert(helper_flow_2_1 == helper_flow_2_2);
  assert(helper_flow_3_1 == helper_flow_3_2);
  assert(helper_flow_4_1 == helper_flow_4_2);
  assert(helper_flow_5_1 == helper_flow_5_2);
  assert(helper_flow_6_1 == helper_flow_6_2);
  assert(helper_flow_7_1 == helper_flow_7_2);
  assert(helper_flow_8_1 == helper_flow_8_2);
  assert(helper_flow_9_1 == helper_flow_9_2);
  assert(helper_flow_10_1 == helper_flow_10_2);
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
}


