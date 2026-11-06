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
struct SensorNode_R000910_1013_0
{
  unsigned char status;
  short gain;
  int calib;
  unsigned char offset;
  unsigned char threshold;
  int buffer[3];
};
struct DeviceConfig_R000910_1013_1
{
  short baud_rate;
  unsigned char port;
  int timeout;
  unsigned char parity;
  short stop_bits;
  int buffer[3];
};
struct CipherContext_R000910_1013_2
{
  short iv;
  unsigned char round_key;
  int nonce;
  unsigned char flags;
  int buffer[3];
};
union TelemetryField_R000910_1013_0
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
void fn_R000910_1013_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000910_1013_1 st_1 = {0};
  struct DeviceConfig_R000910_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int pivot_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_81_1 > 33)
  {
    acc_1 = ((acc_1 + (pivot_81_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_81_2 > 33)
  {
    acc_2 = ((acc_2 + (pivot_81_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_81_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_65_1) & 63;
  aux_2 = (aux_2 + accumulator_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_81_1 == pivot_81_2);
  assert(accumulator_65_1 == accumulator_65_2);
}

int fn_R000910_1013_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000910_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int pivot_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_81 > 33)
  {
    acc = ((acc + (pivot_81 * 2)) + 5) & 127;
    aux ^= pivot_81 & 15;
  }
  else
  {
    acc = ((acc - pivot_81) + 11) & 127;
    aux += 3;
  }
  int accumulator_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_65) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000910_1013_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000910_1013_1 st_1 = {0};
  struct DeviceConfig_R000910_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int pivot_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_73_1) & 63;
  aux_2 = (aux_2 + pivot_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_73_1 == pivot_73_2);
}

int fn_R000910_1013_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000910_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int pivot_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_73) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000910_1013_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000910_1013_2 st_1 = {0};
  struct CipherContext_R000910_1013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int anchor_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_40_1 > 48)
  {
    acc_1 = ((acc_1 + (anchor_40_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_40_2 > 48)
  {
    acc_2 = ((acc_2 + (anchor_40_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_79_1) & 63;
  aux_2 = (aux_2 + bound_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_40_1 == anchor_40_2);
  assert(bound_79_1 == bound_79_2);
}

int fn_R000910_1013_2(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000910_1013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int anchor_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_40 > 48)
  {
    acc = ((acc + (anchor_40 * 2)) + 5) & 127;
    aux ^= anchor_40 & 15;
  }
  else
  {
    acc = ((acc - anchor_40) + 11) & 127;
    aux += 3;
  }
  int bound_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_79) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000910_1013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000910_1013_0 st_1 = {0};
  struct SensorNode_R000910_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int pivot_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_59_1)
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

  switch (pivot_59_2)
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

  int segment_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_46_1) & 63;
  aux_2 = (aux_2 + segment_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_63_1 > 27)
  {
    acc_1 = ((acc_1 + (margin_63_1 * 2)) + 5) & 127;
    aux_1 ^= margin_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_63_2 > 27)
  {
    acc_2 = ((acc_2 + (margin_63_2 * 2)) + 5) & 127;
    aux_2 ^= margin_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_63_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_59_1 == pivot_59_2);
  assert(segment_46_1 == segment_46_2);
  assert(margin_63_1 == margin_63_2);
}

int fn_R000910_1013_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000910_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int pivot_59 = (aux + st.buffer[1]) & 3;
  switch (pivot_59)
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

  int segment_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_46) & 63;
  acc ^= aux;
  int margin_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_63 > 27)
  {
    acc = ((acc + (margin_63 * 2)) + 5) & 127;
    aux ^= margin_63 & 15;
  }
  else
  {
    acc = ((acc - margin_63) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000910_1013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000910_1013_2 st_1 = {0};
  struct CipherContext_R000910_1013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int mask_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_75_1)
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

  switch (mask_75_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_75_1 == mask_75_2);
}

int fn_R000910_1013_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000910_1013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int mask_75 = (aux + st.buffer[1]) & 3;
  switch (mask_75)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000910_1013_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000910_1013_0 st_1 = {0};
  struct SensorNode_R000910_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_84_1 = local_arr_1[aux_1 % 3];
  int delta_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_84_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_84_1 == delta_84_2);
}

int fn_R000910_1013_5(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000910_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_84 = local_arr[aux % 3];
  acc = (acc + (delta_84 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000910_1013_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000910_1013_1 st_1 = {0};
  struct DeviceConfig_R000910_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_87_1) & 63;
  aux_2 = (aux_2 + parity_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_38_1 > 44)
  {
    acc_1 = ((acc_1 + (sample_38_1 * 2)) + 5) & 127;
    aux_1 ^= sample_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_38_2 > 44)
  {
    acc_2 = ((acc_2 + (sample_38_2 * 2)) + 5) & 127;
    aux_2 ^= sample_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_38_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_87_1 == parity_87_2);
  assert(sample_38_1 == sample_38_2);
}

int fn_R000910_1013_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000910_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_87) & 63;
  acc ^= aux;
  int sample_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_38 > 44)
  {
    acc = ((acc + (sample_38 * 2)) + 5) & 127;
    aux ^= sample_38 & 15;
  }
  else
  {
    acc = ((acc - sample_38) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000910_1013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000910_1013_2 st_1 = {0};
  struct CipherContext_R000910_1013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int anchor_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_16_1)
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

  switch (anchor_16_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_12_1 = local_arr_1[aux_1 % 3];
  int anchor_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_12_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_16_1 == anchor_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_12_1 == anchor_12_2);
}

int fn_R000910_1013_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000910_1013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int anchor_16 = (aux + st.buffer[1]) & 3;
  switch (anchor_16)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int anchor_12 = local_arr[aux % 3];
  acc = (acc + (anchor_12 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000910_1013_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000910_1013_1 st_1 = {0};
  struct DeviceConfig_R000910_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int accumulator_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_91_1)
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

  switch (accumulator_91_2)
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

  int segment_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_31_1) & 63;
  aux_2 = (aux_2 + segment_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_91_1 == accumulator_91_2);
  assert(segment_31_1 == segment_31_2);
}

int fn_R000910_1013_8(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000910_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int accumulator_91 = (aux + st.buffer[1]) & 3;
  switch (accumulator_91)
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

  int segment_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_31) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000910_1013_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000910_1013_2 st_1 = {0};
  struct CipherContext_R000910_1013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_46_1 = local_arr_1[aux_1 % 3];
  int phase_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_46_2 * 2)) & 127;
  int margin_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_85_1) & 63;
  aux_2 = (aux_2 + margin_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_26_1 > 43)
  {
    acc_1 = ((acc_1 + (index_reg_26_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_26_2 > 43)
  {
    acc_2 = ((acc_2 + (index_reg_26_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_22_1)
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

  switch (margin_22_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_46_1 == phase_46_2);
  assert(margin_85_1 == margin_85_2);
  assert(index_reg_26_1 == index_reg_26_2);
  assert(margin_22_1 == margin_22_2);
}

int fn_R000910_1013_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000910_1013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int phase_46 = local_arr[aux % 3];
  acc = (acc + (phase_46 * 2)) & 127;
  int margin_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_85) & 63;
  acc ^= aux;
  int index_reg_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_26 > 43)
  {
    acc = ((acc + (index_reg_26 * 2)) + 5) & 127;
    aux ^= index_reg_26 & 15;
  }
  else
  {
    acc = ((acc - index_reg_26) + 11) & 127;
    aux += 3;
  }
  int margin_22 = (aux + st.buffer[1]) & 3;
  switch (margin_22)
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

void fn_R000910_1013_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000910_1013_2 st_1 = {0};
  struct CipherContext_R000910_1013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int weight_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_58_1) & 63;
  aux_2 = (aux_2 + weight_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_55_1)
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

  switch (metric_55_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_58_1 == weight_58_2);
  assert(metric_55_1 == metric_55_2);
}

int fn_R000910_1013_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000910_1013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int weight_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_58) & 63;
  acc ^= aux;
  int metric_55 = (aux + st.buffer[1]) & 3;
  switch (metric_55)
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

void fn_R000910_1013_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000910_1013_1 st_1 = {0};
  struct DeviceConfig_R000910_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int coefficient_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_96_1 > 24)
  {
    acc_1 = ((acc_1 + (coefficient_96_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_96_2 > 24)
  {
    acc_2 = ((acc_2 + (coefficient_96_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_96_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_14_1)
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

  switch (sample_14_2)
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

  int threshold_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_66_1) & 63;
  aux_2 = (aux_2 + threshold_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_96_1 == coefficient_96_2);
  assert(sample_14_1 == sample_14_2);
  assert(threshold_66_1 == threshold_66_2);
}

int fn_R000910_1013_11(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000910_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int coefficient_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_96 > 24)
  {
    acc = ((acc + (coefficient_96 * 2)) + 5) & 127;
    aux ^= coefficient_96 & 15;
  }
  else
  {
    acc = ((acc - coefficient_96) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_14 = (aux + st.buffer[1]) & 3;
  switch (sample_14)
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

  int threshold_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_66) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000910_1013_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000910_1013_0 st_1 = {0};
  struct SensorNode_R000910_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_94_1 = local_arr_1[aux_1 % 3];
  int quotient_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_94_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_94_1 == quotient_94_2);
}

int fn_R000910_1013_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000910_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quotient_94 = local_arr[aux % 3];
  acc = (acc + (quotient_94 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000910_1013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000910_1013_1 st_1 = {0};
  struct DeviceConfig_R000910_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_44_1 = local_arr_1[aux_1 % 3];
  int stride_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_44_2 * 2)) & 127;
  int scale_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_48_1) & 63;
  aux_2 = (aux_2 + scale_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_60_1 > 14)
  {
    acc_1 = ((acc_1 + (cursor_60_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_60_2 > 14)
  {
    acc_2 = ((acc_2 + (cursor_60_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_23_1)
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

  switch (coefficient_23_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_44_1 == stride_44_2);
  assert(scale_48_1 == scale_48_2);
  assert(cursor_60_1 == cursor_60_2);
  assert(coefficient_23_1 == coefficient_23_2);
}

int fn_R000910_1013_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000910_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int stride_44 = local_arr[aux % 3];
  acc = (acc + (stride_44 * 2)) & 127;
  int scale_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_48) & 63;
  acc ^= aux;
  int cursor_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_60 > 14)
  {
    acc = ((acc + (cursor_60 * 2)) + 5) & 127;
    aux ^= cursor_60 & 15;
  }
  else
  {
    acc = ((acc - cursor_60) + 11) & 127;
    aux += 3;
  }
  int coefficient_23 = (aux + st.buffer[1]) & 3;
  switch (coefficient_23)
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

void fn_R000910_1013_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000910_1013_2 st_1 = {0};
  struct CipherContext_R000910_1013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_75_1 = local_arr_1[aux_1 % 3];
  int accumulator_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_75_2 * 2)) & 127;
  int segment_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_71_1)
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

  switch (segment_71_2)
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

  int window_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_66_1 > 10)
  {
    acc_1 = ((acc_1 + (window_66_1 * 2)) + 5) & 127;
    aux_1 ^= window_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_66_2 > 10)
  {
    acc_2 = ((acc_2 + (window_66_2 * 2)) + 5) & 127;
    aux_2 ^= window_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_66_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_75_1 == accumulator_75_2);
  assert(segment_71_1 == segment_71_2);
  assert(window_66_1 == window_66_2);
}

int fn_R000910_1013_14(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000910_1013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int accumulator_75 = local_arr[aux % 3];
  acc = (acc + (accumulator_75 * 2)) & 127;
  int segment_71 = (aux + st.buffer[1]) & 3;
  switch (segment_71)
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

  int window_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_66 > 10)
  {
    acc = ((acc + (window_66 * 2)) + 5) & 127;
    aux ^= window_66 & 15;
  }
  else
  {
    acc = ((acc - window_66) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000910_1013_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000910_1013_0 st_1 = {0};
  struct SensorNode_R000910_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int residue_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_60_1 > 40)
  {
    acc_1 = ((acc_1 + (residue_60_1 * 2)) + 5) & 127;
    aux_1 ^= residue_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_60_2 > 40)
  {
    acc_2 = ((acc_2 + (residue_60_2 * 2)) + 5) & 127;
    aux_2 ^= residue_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_66_1)
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

  switch (threshold_66_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_60_1 == residue_60_2);
  assert(threshold_66_1 == threshold_66_2);
}

int fn_R000910_1013_15(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000910_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int residue_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_60 > 40)
  {
    acc = ((acc + (residue_60 * 2)) + 5) & 127;
    aux ^= residue_60 & 15;
  }
  else
  {
    acc = ((acc - residue_60) + 11) & 127;
    aux += 3;
  }
  int threshold_66 = (aux + st.buffer[1]) & 3;
  switch (threshold_66)
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

void fn_R000910_1013_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000910_1013_0 st_1 = {0};
  struct SensorNode_R000910_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int index_reg_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_19_1 > 39)
  {
    acc_1 = ((acc_1 + (index_reg_19_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_19_2 > 39)
  {
    acc_2 = ((acc_2 + (index_reg_19_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_11_1) & 63;
  aux_2 = (aux_2 + coefficient_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_23_1)
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

  switch (factor_23_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_19_1 == index_reg_19_2);
  assert(coefficient_11_1 == coefficient_11_2);
  assert(factor_23_1 == factor_23_2);
}

int fn_R000910_1013_16(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000910_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int index_reg_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_19 > 39)
  {
    acc = ((acc + (index_reg_19 * 2)) + 5) & 127;
    aux ^= index_reg_19 & 15;
  }
  else
  {
    acc = ((acc - index_reg_19) + 11) & 127;
    aux += 3;
  }
  int coefficient_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_11) & 63;
  acc ^= aux;
  int factor_23 = (aux + st.buffer[1]) & 3;
  switch (factor_23)
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

void fn_R000910_1013_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000910_1013_1 st_1 = {0};
  struct DeviceConfig_R000910_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_28_1 = local_arr_1[aux_1 % 3];
  int sample_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_28_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_28_1 == sample_28_2);
}

int fn_R000910_1013_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000910_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int sample_28 = local_arr[aux % 3];
  acc = (acc + (sample_28 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000910_1013_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000910_1013_1 st_1 = {0};
  struct DeviceConfig_R000910_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int vector_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_81_1) & 63;
  aux_2 = (aux_2 + vector_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_16_1)
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

  switch (anchor_16_2)
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

  int index_reg_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_50_1 > 24)
  {
    acc_1 = ((acc_1 + (index_reg_50_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_50_2 > 24)
  {
    acc_2 = ((acc_2 + (index_reg_50_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_50_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_81_1 == vector_81_2);
  assert(anchor_16_1 == anchor_16_2);
  assert(index_reg_50_1 == index_reg_50_2);
}

int fn_R000910_1013_18(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000910_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int vector_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_81) & 63;
  acc ^= aux;
  int anchor_16 = (aux + st.buffer[1]) & 3;
  switch (anchor_16)
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

  int index_reg_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_50 > 24)
  {
    acc = ((acc + (index_reg_50 * 2)) + 5) & 127;
    aux ^= index_reg_50 & 15;
  }
  else
  {
    acc = ((acc - index_reg_50) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000910_1013_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000910_1013_1 st_1 = {0};
  struct DeviceConfig_R000910_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int coefficient_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_56_1)
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

  switch (coefficient_56_2)
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
  int factor_82_1 = local_arr_1[aux_1 % 3];
  int factor_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_82_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_56_1 == coefficient_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_82_1 == factor_82_2);
}

int fn_R000910_1013_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000910_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int coefficient_56 = (aux + st.buffer[1]) & 3;
  switch (coefficient_56)
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
  int factor_82 = local_arr[aux % 3];
  acc = (acc + (factor_82 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000910_1013_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000910_1013_0 st_1 = {0};
  struct SensorNode_R000910_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_63_1 = local_arr_1[aux_1 % 3];
  int bound_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_63_2 * 2)) & 127;
  int stride_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_17_1 > 39)
  {
    acc_1 = ((acc_1 + (stride_17_1 * 2)) + 5) & 127;
    aux_1 ^= stride_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_17_2 > 39)
  {
    acc_2 = ((acc_2 + (stride_17_2 * 2)) + 5) & 127;
    aux_2 ^= stride_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_17_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_88_1) & 63;
  aux_2 = (aux_2 + margin_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_63_1 == bound_63_2);
  assert(stride_17_1 == stride_17_2);
  assert(margin_88_1 == margin_88_2);
}

int fn_R000910_1013_20(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000910_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int bound_63 = local_arr[aux % 3];
  acc = (acc + (bound_63 * 2)) & 127;
  int stride_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_17 > 39)
  {
    acc = ((acc + (stride_17 * 2)) + 5) & 127;
    aux ^= stride_17 & 15;
  }
  else
  {
    acc = ((acc - stride_17) + 11) & 127;
    aux += 3;
  }
  int margin_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_88) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000910_0_1;
  int sec_r000910_0_2;
  int sec_r000910_1_1;
  int sec_r000910_1_2;
  int sec_r000910_2_1;
  int sec_r000910_2_2;
  int sec_r000910_3_1;
  int sec_r000910_3_2;
  int sec_r000910_4_1;
  int sec_r000910_4_2;
  int sec_r000910_5_1;
  int sec_r000910_5_2;
  int sec_r000910_6_1;
  int sec_r000910_6_2;
  int sec_r000910_7_1;
  int sec_r000910_7_2;
  int sec_r000910_8_1;
  int sec_r000910_8_2;
  int sec_r000910_9_1;
  int sec_r000910_9_2;
  int sec_r000910_10_1;
  int sec_r000910_10_2;
  int sec_r000910_11_1;
  int sec_r000910_11_2;
  int sec_r000910_12_1;
  int sec_r000910_12_2;
  int sec_r000910_13_1;
  int sec_r000910_13_2;
  int sec_r000910_14_1;
  int sec_r000910_14_2;
  int sec_r000910_15_1;
  int sec_r000910_15_2;
  int pub_r000910_0_1;
  int pub_r000910_0_2;
  int pub_r000910_1_1;
  int pub_r000910_1_2;
  int pub_r000910_2_1;
  int pub_r000910_2_2;
  int pub_r000910_3_1;
  int pub_r000910_3_2;
  int pub_r000910_4_1;
  int pub_r000910_4_2;
  int pub_r000910_5_1;
  int pub_r000910_5_2;
  int pub_r000910_6_1;
  int pub_r000910_6_2;
  int pub_r000910_7_1;
  int pub_r000910_7_2;
  int pub_r000910_8_1;
  int pub_r000910_8_2;
  int pub_r000910_9_1;
  int pub_r000910_9_2;
  int pub_r000910_10_1;
  int pub_r000910_10_2;
  int pub_r000910_11_1;
  int pub_r000910_11_2;
  int pub_r000910_12_1;
  int pub_r000910_12_2;
  int pub_r000910_13_1;
  int pub_r000910_13_2;
  int pub_r000910_14_1;
  int pub_r000910_14_2;
  int pub_r000910_15_1;
  int pub_r000910_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000910_0_1 >= (-100)) && (pub_r000910_0_1 <= 100));
  __CPROVER_assume((pub_r000910_0_2 >= (-100)) && (pub_r000910_0_2 <= 100));
  __CPROVER_assume((pub_r000910_1_1 >= (-100)) && (pub_r000910_1_1 <= 100));
  __CPROVER_assume((pub_r000910_1_2 >= (-100)) && (pub_r000910_1_2 <= 100));
  __CPROVER_assume((pub_r000910_2_1 >= (-100)) && (pub_r000910_2_1 <= 100));
  __CPROVER_assume((pub_r000910_2_2 >= (-100)) && (pub_r000910_2_2 <= 100));
  __CPROVER_assume((pub_r000910_3_1 >= (-100)) && (pub_r000910_3_1 <= 100));
  __CPROVER_assume((pub_r000910_3_2 >= (-100)) && (pub_r000910_3_2 <= 100));
  __CPROVER_assume((pub_r000910_4_1 >= (-100)) && (pub_r000910_4_1 <= 100));
  __CPROVER_assume((pub_r000910_4_2 >= (-100)) && (pub_r000910_4_2 <= 100));
  __CPROVER_assume((pub_r000910_5_1 >= (-100)) && (pub_r000910_5_1 <= 100));
  __CPROVER_assume((pub_r000910_5_2 >= (-100)) && (pub_r000910_5_2 <= 100));
  __CPROVER_assume((pub_r000910_6_1 >= (-100)) && (pub_r000910_6_1 <= 100));
  __CPROVER_assume((pub_r000910_6_2 >= (-100)) && (pub_r000910_6_2 <= 100));
  __CPROVER_assume((pub_r000910_7_1 >= (-100)) && (pub_r000910_7_1 <= 100));
  __CPROVER_assume((pub_r000910_7_2 >= (-100)) && (pub_r000910_7_2 <= 100));
  __CPROVER_assume((pub_r000910_8_1 >= (-100)) && (pub_r000910_8_1 <= 100));
  __CPROVER_assume((pub_r000910_8_2 >= (-100)) && (pub_r000910_8_2 <= 100));
  __CPROVER_assume((pub_r000910_9_1 >= (-100)) && (pub_r000910_9_1 <= 100));
  __CPROVER_assume((pub_r000910_9_2 >= (-100)) && (pub_r000910_9_2 <= 100));
  __CPROVER_assume((pub_r000910_10_1 >= (-100)) && (pub_r000910_10_1 <= 100));
  __CPROVER_assume((pub_r000910_10_2 >= (-100)) && (pub_r000910_10_2 <= 100));
  __CPROVER_assume((pub_r000910_11_1 >= (-100)) && (pub_r000910_11_1 <= 100));
  __CPROVER_assume((pub_r000910_11_2 >= (-100)) && (pub_r000910_11_2 <= 100));
  __CPROVER_assume((pub_r000910_12_1 >= (-100)) && (pub_r000910_12_1 <= 100));
  __CPROVER_assume((pub_r000910_12_2 >= (-100)) && (pub_r000910_12_2 <= 100));
  __CPROVER_assume((pub_r000910_13_1 >= (-100)) && (pub_r000910_13_1 <= 100));
  __CPROVER_assume((pub_r000910_13_2 >= (-100)) && (pub_r000910_13_2 <= 100));
  __CPROVER_assume((pub_r000910_14_1 >= (-100)) && (pub_r000910_14_1 <= 100));
  __CPROVER_assume((pub_r000910_14_2 >= (-100)) && (pub_r000910_14_2 <= 100));
  __CPROVER_assume((pub_r000910_15_1 >= (-100)) && (pub_r000910_15_1 <= 100));
  __CPROVER_assume((pub_r000910_15_2 >= (-100)) && (pub_r000910_15_2 <= 100));
  __CPROVER_assume((sec_r000910_0_1 >= 0) && (sec_r000910_0_1 <= 255));
  __CPROVER_assume((sec_r000910_0_2 >= 0) && (sec_r000910_0_2 <= 255));
  __CPROVER_assume((sec_r000910_1_1 >= 0) && (sec_r000910_1_1 <= 255));
  __CPROVER_assume((sec_r000910_1_2 >= 0) && (sec_r000910_1_2 <= 255));
  __CPROVER_assume((sec_r000910_2_1 >= 0) && (sec_r000910_2_1 <= 255));
  __CPROVER_assume((sec_r000910_2_2 >= 0) && (sec_r000910_2_2 <= 255));
  __CPROVER_assume((sec_r000910_3_1 >= 0) && (sec_r000910_3_1 <= 255));
  __CPROVER_assume((sec_r000910_3_2 >= 0) && (sec_r000910_3_2 <= 255));
  __CPROVER_assume((sec_r000910_4_1 >= 0) && (sec_r000910_4_1 <= 255));
  __CPROVER_assume((sec_r000910_4_2 >= 0) && (sec_r000910_4_2 <= 255));
  __CPROVER_assume((sec_r000910_5_1 >= 0) && (sec_r000910_5_1 <= 255));
  __CPROVER_assume((sec_r000910_5_2 >= 0) && (sec_r000910_5_2 <= 255));
  __CPROVER_assume((sec_r000910_6_1 >= 0) && (sec_r000910_6_1 <= 255));
  __CPROVER_assume((sec_r000910_6_2 >= 0) && (sec_r000910_6_2 <= 255));
  __CPROVER_assume((sec_r000910_7_1 >= 0) && (sec_r000910_7_1 <= 255));
  __CPROVER_assume((sec_r000910_7_2 >= 0) && (sec_r000910_7_2 <= 255));
  __CPROVER_assume((sec_r000910_8_1 >= 0) && (sec_r000910_8_1 <= 255));
  __CPROVER_assume((sec_r000910_8_2 >= 0) && (sec_r000910_8_2 <= 255));
  __CPROVER_assume((sec_r000910_9_1 >= 0) && (sec_r000910_9_1 <= 255));
  __CPROVER_assume((sec_r000910_9_2 >= 0) && (sec_r000910_9_2 <= 255));
  __CPROVER_assume((sec_r000910_10_1 >= 0) && (sec_r000910_10_1 <= 255));
  __CPROVER_assume((sec_r000910_10_2 >= 0) && (sec_r000910_10_2 <= 255));
  __CPROVER_assume((sec_r000910_11_1 >= 0) && (sec_r000910_11_1 <= 255));
  __CPROVER_assume((sec_r000910_11_2 >= 0) && (sec_r000910_11_2 <= 255));
  __CPROVER_assume((sec_r000910_12_1 >= 0) && (sec_r000910_12_1 <= 255));
  __CPROVER_assume((sec_r000910_12_2 >= 0) && (sec_r000910_12_2 <= 255));
  __CPROVER_assume((sec_r000910_13_1 >= 0) && (sec_r000910_13_1 <= 255));
  __CPROVER_assume((sec_r000910_13_2 >= 0) && (sec_r000910_13_2 <= 255));
  __CPROVER_assume((sec_r000910_14_1 >= 0) && (sec_r000910_14_1 <= 255));
  __CPROVER_assume((sec_r000910_14_2 >= 0) && (sec_r000910_14_2 <= 255));
  __CPROVER_assume((sec_r000910_15_1 >= 0) && (sec_r000910_15_1 <= 255));
  __CPROVER_assume((sec_r000910_15_2 >= 0) && (sec_r000910_15_2 <= 255));
  struct SensorNode_R000910_1013_0 st_var_0_1 = {0};
  struct SensorNode_R000910_1013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000910_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000910_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000910_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000910_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000910_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000910_0_2 + 7) & 15;
  struct DeviceConfig_R000910_1013_1 st_var_1_1 = {0};
  struct DeviceConfig_R000910_1013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000910_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000910_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000910_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000910_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000910_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000910_0_2 + 9) & 15;
  struct CipherContext_R000910_1013_2 st_var_2_1 = {0};
  struct CipherContext_R000910_1013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000910_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000910_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000910_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000910_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000910_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000910_0_2 + 11) & 15;
  union TelemetryField_R000910_1013_0 u_var_1;
  union TelemetryField_R000910_1013_0 u_var_2;
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
  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
  int stage_v_2_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (7 & 31);
  int stage_v_2_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (7 & 31);
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= (stage_v_2_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_2_2 << 1) & 127;
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
  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 6) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_6_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_6_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_6_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 15) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 15) & 15;
  int stage_v_14_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_14_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= stage_v_14_1;
  chk_sum_2 ^= stage_v_14_2;
  int stage_v_15_1 = ((st_var_0_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_0_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 42)
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
  if (stage_v_15_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 42)
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
  int stage_v_16_1 = ((st_var_1_1.buffer[1] * 2) + 55) & 63;
  int stage_v_16_2 = ((st_var_1_2.buffer[1] * 2) + 55) & 63;
  if (stage_v_16_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_16_1) - 5) & 255;
    if (stage_v_16_1 > 41)
    {
      chk_sum_1 ^= stage_v_16_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_16_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_16_2) - 5) & 255;
    if (stage_v_16_2 > 41)
    {
      chk_sum_2 ^= stage_v_16_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_17_1 = ((st_var_2_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_2_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 30)
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
  if (stage_v_17_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 30)
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
  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  int stage_v_21_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_21_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  int stage_v_23_1 = (st_var_2_1.buffer[0] ^ 26) & 3;
  int stage_v_23_2 = (st_var_2_2.buffer[0] ^ 26) & 3;
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

  int stage_v_24_1 = ((st_var_0_1.buffer[0] * 2) + 79) & 63;
  int stage_v_24_2 = ((st_var_0_2.buffer[0] * 2) + 79) & 63;
  if (stage_v_24_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_24_1) - 5) & 255;
    if (stage_v_24_1 > 45)
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
  if (stage_v_24_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_24_2) - 5) & 255;
    if (stage_v_24_2 > 45)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 26) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 26) & 15;
  int stage_v_25_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_25_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= stage_v_25_1;
  chk_sum_2 ^= stage_v_25_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 27) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = ((sec_r000910_13_1 ^ 0x2A) + pub_r000910_0_1) & 127;
  int stage_v_27_2 = ((sec_r000910_13_2 ^ 0x2A) + pub_r000910_0_2) & 127;
  if (stage_v_27_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((stage_v_27_1 ^ 0x2A) + pub_r000910_7_1) & 127;
  int stage_v_28_2 = ((stage_v_27_2 ^ 0x2A) + pub_r000910_7_2) & 127;
  if (stage_v_28_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((stage_v_28_1 ^ 0x2A) + pub_r000910_15_1) & 127;
  int stage_v_29_2 = ((stage_v_28_2 ^ 0x2A) + pub_r000910_15_2) & 127;
  if (stage_v_29_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = ((stage_v_29_1 ^ 0x2A) + pub_r000910_8_1) & 127;
  int stage_v_30_2 = ((stage_v_29_2 ^ 0x2A) + pub_r000910_8_2) & 127;
  if (stage_v_30_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((stage_v_28_1 ^ 0x2A) + pub_r000910_8_1) & 127;
  int stage_v_31_2 = ((stage_v_28_2 ^ 0x2A) + pub_r000910_8_2) & 127;
  if (stage_v_31_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((sec_r000910_13_1 ^ 0x2A) + pub_r000910_9_1) & 127;
  int stage_v_32_2 = ((sec_r000910_13_2 ^ 0x2A) + pub_r000910_9_2) & 127;
  if (stage_v_32_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((sec_r000910_2_1 ^ 0x2A) + pub_r000910_2_1) & 127;
  int stage_v_33_2 = ((sec_r000910_2_2 ^ 0x2A) + pub_r000910_2_2) & 127;
  if (stage_v_33_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = ((sec_r000910_13_1 ^ 0x2A) + pub_r000910_11_1) & 127;
  int stage_v_34_2 = ((sec_r000910_13_2 ^ 0x2A) + pub_r000910_11_2) & 127;
  if (stage_v_34_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((sec_r000910_2_1 ^ 0x2A) + pub_r000910_9_1) & 127;
  int stage_v_35_2 = ((sec_r000910_2_2 ^ 0x2A) + pub_r000910_9_2) & 127;
  if (stage_v_35_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((stage_v_35_1 ^ 0x2A) + pub_r000910_3_1) & 127;
  int stage_v_36_2 = ((stage_v_35_2 ^ 0x2A) + pub_r000910_3_2) & 127;
  if (stage_v_36_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((stage_v_36_1 ^ 0x2A) + pub_r000910_1_1) & 127;
  int stage_v_37_2 = ((stage_v_36_2 ^ 0x2A) + pub_r000910_1_2) & 127;
  if (stage_v_37_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((stage_v_31_1 ^ 0x2A) + pub_r000910_4_1) & 127;
  int stage_v_38_2 = ((stage_v_31_2 ^ 0x2A) + pub_r000910_4_2) & 127;
  if (stage_v_38_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((sec_r000910_10_1 ^ 0x2A) + pub_r000910_13_1) & 127;
  int stage_v_39_2 = ((sec_r000910_10_2 ^ 0x2A) + pub_r000910_13_2) & 127;
  if (stage_v_39_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((sec_r000910_10_1 ^ 0x2A) + pub_r000910_5_1) & 127;
  int stage_v_40_2 = ((sec_r000910_10_2 ^ 0x2A) + pub_r000910_5_2) & 127;
  if (stage_v_40_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((stage_v_29_1 ^ 0x2A) + pub_r000910_2_1) & 127;
  int stage_v_41_2 = ((stage_v_29_2 ^ 0x2A) + pub_r000910_2_2) & 127;
  if (stage_v_41_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((stage_v_34_1 ^ 0x2A) + pub_r000910_8_1) & 127;
  int stage_v_42_2 = ((stage_v_34_2 ^ 0x2A) + pub_r000910_8_2) & 127;
  if (stage_v_42_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((sec_r000910_10_1 ^ 0x2A) + pub_r000910_4_1) & 127;
  int stage_v_43_2 = ((sec_r000910_10_2 ^ 0x2A) + pub_r000910_4_2) & 127;
  if (stage_v_43_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((sec_r000910_9_1 ^ 0x2A) + pub_r000910_4_1) & 127;
  int stage_v_44_2 = ((sec_r000910_9_2 ^ 0x2A) + pub_r000910_4_2) & 127;
  if (stage_v_44_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((sec_r000910_5_1 ^ 0x2A) + pub_r000910_15_1) & 127;
  int stage_v_45_2 = ((sec_r000910_5_2 ^ 0x2A) + pub_r000910_15_2) & 127;
  if (stage_v_45_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((stage_v_34_1 ^ 0x2A) + pub_r000910_2_1) & 127;
  int stage_v_46_2 = ((stage_v_34_2 ^ 0x2A) + pub_r000910_2_2) & 127;
  if (stage_v_46_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((stage_v_42_1 ^ 0x2A) + pub_r000910_15_1) & 127;
  int stage_v_47_2 = ((stage_v_42_2 ^ 0x2A) + pub_r000910_15_2) & 127;
  if (stage_v_47_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((stage_v_30_1 ^ 0x2A) + pub_r000910_8_1) & 127;
  int stage_v_48_2 = ((stage_v_30_2 ^ 0x2A) + pub_r000910_8_2) & 127;
  if (stage_v_48_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((stage_v_30_1 ^ 0x2A) + pub_r000910_3_1) & 127;
  int stage_v_49_2 = ((stage_v_30_2 ^ 0x2A) + pub_r000910_3_2) & 127;
  if (stage_v_49_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((stage_v_39_1 ^ 0x2A) + pub_r000910_5_1) & 127;
  int stage_v_50_2 = ((stage_v_39_2 ^ 0x2A) + pub_r000910_5_2) & 127;
  if (stage_v_50_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((stage_v_30_1 ^ 0x2A) + pub_r000910_10_1) & 127;
  int stage_v_51_2 = ((stage_v_30_2 ^ 0x2A) + pub_r000910_10_2) & 127;
  if (stage_v_51_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((sec_r000910_15_1 ^ 0x2A) + pub_r000910_5_1) & 127;
  int stage_v_52_2 = ((sec_r000910_15_2 ^ 0x2A) + pub_r000910_5_2) & 127;
  if (stage_v_52_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((stage_v_49_1 ^ 0x2A) + pub_r000910_6_1) & 127;
  int stage_v_53_2 = ((stage_v_49_2 ^ 0x2A) + pub_r000910_6_2) & 127;
  if (stage_v_53_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((stage_v_50_1 ^ 0x2A) + pub_r000910_4_1) & 127;
  int stage_v_54_2 = ((stage_v_50_2 ^ 0x2A) + pub_r000910_4_2) & 127;
  if (stage_v_54_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((stage_v_44_1 ^ 0x2A) + pub_r000910_4_1) & 127;
  int stage_v_55_2 = ((stage_v_44_2 ^ 0x2A) + pub_r000910_4_2) & 127;
  if (stage_v_55_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((sec_r000910_6_1 ^ 0x2A) + pub_r000910_9_1) & 127;
  int stage_v_56_2 = ((sec_r000910_6_2 ^ 0x2A) + pub_r000910_9_2) & 127;
  if (stage_v_56_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((stage_v_34_1 ^ 0x2A) + pub_r000910_4_1) & 127;
  int stage_v_57_2 = ((stage_v_34_2 ^ 0x2A) + pub_r000910_4_2) & 127;
  if (stage_v_57_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((stage_v_32_1 ^ 0x2A) + pub_r000910_9_1) & 127;
  int stage_v_58_2 = ((stage_v_32_2 ^ 0x2A) + pub_r000910_9_2) & 127;
  if (stage_v_58_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((sec_r000910_13_1 ^ 0x2A) + pub_r000910_10_1) & 127;
  int stage_v_59_2 = ((sec_r000910_13_2 ^ 0x2A) + pub_r000910_10_2) & 127;
  if (stage_v_59_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((sec_r000910_5_1 ^ 0x2A) + pub_r000910_9_1) & 127;
  int stage_v_60_2 = ((sec_r000910_5_2 ^ 0x2A) + pub_r000910_9_2) & 127;
  if (stage_v_60_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((sec_r000910_11_1 ^ 0x2A) + pub_r000910_4_1) & 127;
  int stage_v_61_2 = ((sec_r000910_11_2 ^ 0x2A) + pub_r000910_4_2) & 127;
  if (stage_v_61_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((stage_v_41_1 ^ 0x2A) + pub_r000910_10_1) & 127;
  int stage_v_62_2 = ((stage_v_41_2 ^ 0x2A) + pub_r000910_10_2) & 127;
  if (stage_v_62_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((sec_r000910_0_1 ^ 0x2A) + pub_r000910_5_1) & 127;
  int stage_v_63_2 = ((sec_r000910_0_2 ^ 0x2A) + pub_r000910_5_2) & 127;
  if (stage_v_63_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((sec_r000910_14_1 ^ 0x2A) + pub_r000910_14_1) & 127;
  int stage_v_64_2 = ((sec_r000910_14_2 ^ 0x2A) + pub_r000910_14_2) & 127;
  if (stage_v_64_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((stage_v_55_1 ^ 0x2A) + pub_r000910_5_1) & 127;
  int stage_v_65_2 = ((stage_v_55_2 ^ 0x2A) + pub_r000910_5_2) & 127;
  if (stage_v_65_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((stage_v_39_1 ^ 0x2A) + pub_r000910_0_1) & 127;
  int stage_v_66_2 = ((stage_v_39_2 ^ 0x2A) + pub_r000910_0_2) & 127;
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
  int stage_v_67_1 = ((sec_r000910_3_1 ^ 0x2A) + pub_r000910_3_1) & 127;
  int stage_v_67_2 = ((sec_r000910_3_2 ^ 0x2A) + pub_r000910_3_2) & 127;
  if (stage_v_67_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((sec_r000910_4_1 ^ 0x2A) + pub_r000910_10_1) & 127;
  int stage_v_68_2 = ((sec_r000910_4_2 ^ 0x2A) + pub_r000910_10_2) & 127;
  if (stage_v_68_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((sec_r000910_4_1 ^ 0x2A) + pub_r000910_6_1) & 127;
  int stage_v_69_2 = ((sec_r000910_4_2 ^ 0x2A) + pub_r000910_6_2) & 127;
  if (stage_v_69_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((sec_r000910_12_1 ^ 0x2A) + pub_r000910_7_1) & 127;
  int stage_v_70_2 = ((sec_r000910_12_2 ^ 0x2A) + pub_r000910_7_2) & 127;
  if (stage_v_70_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((stage_v_64_1 ^ 0x2A) + pub_r000910_15_1) & 127;
  int stage_v_71_2 = ((stage_v_64_2 ^ 0x2A) + pub_r000910_15_2) & 127;
  if (stage_v_71_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((stage_v_52_1 ^ 0x2A) + pub_r000910_8_1) & 127;
  int stage_v_72_2 = ((stage_v_52_2 ^ 0x2A) + pub_r000910_8_2) & 127;
  if (stage_v_72_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((stage_v_47_1 ^ 0x2A) + pub_r000910_6_1) & 127;
  int stage_v_73_2 = ((stage_v_47_2 ^ 0x2A) + pub_r000910_6_2) & 127;
  if (stage_v_73_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((stage_v_29_1 ^ 0x2A) + pub_r000910_1_1) & 127;
  int stage_v_74_2 = ((stage_v_29_2 ^ 0x2A) + pub_r000910_1_2) & 127;
  if (stage_v_74_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((stage_v_62_1 ^ 0x2A) + pub_r000910_2_1) & 127;
  int stage_v_75_2 = ((stage_v_62_2 ^ 0x2A) + pub_r000910_2_2) & 127;
  if (stage_v_75_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((sec_r000910_1_1 ^ 0x2A) + pub_r000910_3_1) & 127;
  int stage_v_76_2 = ((sec_r000910_1_2 ^ 0x2A) + pub_r000910_3_2) & 127;
  if (stage_v_76_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((stage_v_68_1 ^ 0x2A) + pub_r000910_1_1) & 127;
  int stage_v_77_2 = ((stage_v_68_2 ^ 0x2A) + pub_r000910_1_2) & 127;
  if (stage_v_77_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((sec_r000910_12_1 ^ 0x2A) + pub_r000910_10_1) & 127;
  int stage_v_78_2 = ((sec_r000910_12_2 ^ 0x2A) + pub_r000910_10_2) & 127;
  if (stage_v_78_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((stage_v_68_1 ^ 0x2A) + pub_r000910_11_1) & 127;
  int stage_v_79_2 = ((stage_v_68_2 ^ 0x2A) + pub_r000910_11_2) & 127;
  if (stage_v_79_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((sec_r000910_8_1 ^ 0x2A) + pub_r000910_7_1) & 127;
  int stage_v_80_2 = ((sec_r000910_8_2 ^ 0x2A) + pub_r000910_7_2) & 127;
  if (stage_v_80_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((sec_r000910_11_1 ^ 0x2A) + pub_r000910_7_1) & 127;
  int stage_v_81_2 = ((sec_r000910_11_2 ^ 0x2A) + pub_r000910_7_2) & 127;
  if (stage_v_81_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((sec_r000910_0_1 ^ 0x2A) + pub_r000910_1_1) & 127;
  int stage_v_82_2 = ((sec_r000910_0_2 ^ 0x2A) + pub_r000910_1_2) & 127;
  if (stage_v_82_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((stage_v_60_1 ^ 0x2A) + pub_r000910_13_1) & 127;
  int stage_v_83_2 = ((stage_v_60_2 ^ 0x2A) + pub_r000910_13_2) & 127;
  if (stage_v_83_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((stage_v_71_1 ^ 0x2A) + pub_r000910_8_1) & 127;
  int stage_v_84_2 = ((stage_v_71_2 ^ 0x2A) + pub_r000910_8_2) & 127;
  if (stage_v_84_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((sec_r000910_1_1 ^ 0x2A) + pub_r000910_11_1) & 127;
  int stage_v_85_2 = ((sec_r000910_1_2 ^ 0x2A) + pub_r000910_11_2) & 127;
  if (stage_v_85_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((stage_v_68_1 ^ 0x2A) + pub_r000910_2_1) & 127;
  int stage_v_86_2 = ((stage_v_68_2 ^ 0x2A) + pub_r000910_2_2) & 127;
  if (stage_v_86_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((stage_v_48_1 ^ 0x2A) + pub_r000910_11_1) & 127;
  int stage_v_87_2 = ((stage_v_48_2 ^ 0x2A) + pub_r000910_11_2) & 127;
  if (stage_v_87_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((sec_r000910_2_1 ^ 0x2A) + pub_r000910_13_1) & 127;
  int stage_v_88_2 = ((sec_r000910_2_2 ^ 0x2A) + pub_r000910_13_2) & 127;
  if (stage_v_88_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((sec_r000910_3_1 ^ 0x2A) + pub_r000910_4_1) & 127;
  int stage_v_89_2 = ((sec_r000910_3_2 ^ 0x2A) + pub_r000910_4_2) & 127;
  if (stage_v_89_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((sec_r000910_14_1 ^ 0x2A) + pub_r000910_3_1) & 127;
  int stage_v_90_2 = ((sec_r000910_14_2 ^ 0x2A) + pub_r000910_3_2) & 127;
  if (stage_v_90_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((stage_v_34_1 ^ 0x2A) + pub_r000910_4_1) & 127;
  int stage_v_91_2 = ((stage_v_34_2 ^ 0x2A) + pub_r000910_4_2) & 127;
  if (stage_v_91_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((stage_v_71_1 ^ 0x2A) + pub_r000910_12_1) & 127;
  int stage_v_92_2 = ((stage_v_71_2 ^ 0x2A) + pub_r000910_12_2) & 127;
  if (stage_v_92_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((stage_v_46_1 ^ 0x2A) + pub_r000910_2_1) & 127;
  int stage_v_93_2 = ((stage_v_46_2 ^ 0x2A) + pub_r000910_2_2) & 127;
  if (stage_v_93_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((sec_r000910_4_1 ^ 0x2A) + pub_r000910_6_1) & 127;
  int stage_v_94_2 = ((sec_r000910_4_2 ^ 0x2A) + pub_r000910_6_2) & 127;
  if (stage_v_94_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((stage_v_60_1 ^ 0x2A) + pub_r000910_10_1) & 127;
  int stage_v_95_2 = ((stage_v_60_2 ^ 0x2A) + pub_r000910_10_2) & 127;
  if (stage_v_95_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((sec_r000910_8_1 ^ 0x2A) + pub_r000910_5_1) & 127;
  int stage_v_96_2 = ((sec_r000910_8_2 ^ 0x2A) + pub_r000910_5_2) & 127;
  if (stage_v_96_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((sec_r000910_15_1 ^ 0x2A) + pub_r000910_1_1) & 127;
  int stage_v_97_2 = ((sec_r000910_15_2 ^ 0x2A) + pub_r000910_1_2) & 127;
  if (stage_v_97_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((stage_v_62_1 ^ 0x2A) + pub_r000910_4_1) & 127;
  int stage_v_98_2 = ((stage_v_62_2 ^ 0x2A) + pub_r000910_4_2) & 127;
  if (stage_v_98_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((stage_v_92_1 ^ 0x2A) + pub_r000910_7_1) & 127;
  int stage_v_99_2 = ((stage_v_92_2 ^ 0x2A) + pub_r000910_7_2) & 127;
  if (stage_v_99_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((stage_v_44_1 ^ 0x2A) + pub_r000910_0_1) & 127;
  int stage_v_100_2 = ((stage_v_44_2 ^ 0x2A) + pub_r000910_0_2) & 127;
  if (stage_v_100_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((stage_v_67_1 ^ 0x2A) + pub_r000910_4_1) & 127;
  int stage_v_101_2 = ((stage_v_67_2 ^ 0x2A) + pub_r000910_4_2) & 127;
  if (stage_v_101_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((stage_v_33_1 ^ 0x2A) + pub_r000910_12_1) & 127;
  int stage_v_102_2 = ((stage_v_33_2 ^ 0x2A) + pub_r000910_12_2) & 127;
  if (stage_v_102_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((stage_v_39_1 ^ 0x2A) + pub_r000910_15_1) & 127;
  int stage_v_103_2 = ((stage_v_39_2 ^ 0x2A) + pub_r000910_15_2) & 127;
  if (stage_v_103_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((stage_v_57_1 ^ 0x2A) + pub_r000910_14_1) & 127;
  int stage_v_104_2 = ((stage_v_57_2 ^ 0x2A) + pub_r000910_14_2) & 127;
  if (stage_v_104_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((stage_v_69_1 ^ 0x2A) + pub_r000910_0_1) & 127;
  int stage_v_105_2 = ((stage_v_69_2 ^ 0x2A) + pub_r000910_0_2) & 127;
  if (stage_v_105_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((stage_v_103_1 ^ 0x2A) + pub_r000910_12_1) & 127;
  int stage_v_106_2 = ((stage_v_103_2 ^ 0x2A) + pub_r000910_12_2) & 127;
  if (stage_v_106_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((stage_v_44_1 ^ 0x2A) + pub_r000910_12_1) & 127;
  int stage_v_107_2 = ((stage_v_44_2 ^ 0x2A) + pub_r000910_12_2) & 127;
  if (stage_v_107_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((stage_v_75_1 ^ 0x2A) + pub_r000910_6_1) & 127;
  int stage_v_108_2 = ((stage_v_75_2 ^ 0x2A) + pub_r000910_6_2) & 127;
  if (stage_v_108_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((sec_r000910_8_1 ^ 0x2A) + pub_r000910_1_1) & 127;
  int stage_v_109_2 = ((sec_r000910_8_2 ^ 0x2A) + pub_r000910_1_2) & 127;
  if (stage_v_109_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((sec_r000910_1_1 ^ 0x2A) + pub_r000910_0_1) & 127;
  int stage_v_110_2 = ((sec_r000910_1_2 ^ 0x2A) + pub_r000910_0_2) & 127;
  if (stage_v_110_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((stage_v_73_1 ^ 0x2A) + pub_r000910_9_1) & 127;
  int stage_v_111_2 = ((stage_v_73_2 ^ 0x2A) + pub_r000910_9_2) & 127;
  if (stage_v_111_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((stage_v_41_1 ^ 0x2A) + pub_r000910_14_1) & 127;
  int stage_v_112_2 = ((stage_v_41_2 ^ 0x2A) + pub_r000910_14_2) & 127;
  if (stage_v_112_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((stage_v_66_1 ^ 0x2A) + pub_r000910_7_1) & 127;
  int stage_v_113_2 = ((stage_v_66_2 ^ 0x2A) + pub_r000910_7_2) & 127;
  if (stage_v_113_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((stage_v_36_1 ^ 0x2A) + pub_r000910_7_1) & 127;
  int stage_v_114_2 = ((stage_v_36_2 ^ 0x2A) + pub_r000910_7_2) & 127;
  if (stage_v_114_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((stage_v_87_1 ^ 0x2A) + pub_r000910_11_1) & 127;
  int stage_v_115_2 = ((stage_v_87_2 ^ 0x2A) + pub_r000910_11_2) & 127;
  if (stage_v_115_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((sec_r000910_6_1 ^ 0x2A) + pub_r000910_8_1) & 127;
  int stage_v_116_2 = ((sec_r000910_6_2 ^ 0x2A) + pub_r000910_8_2) & 127;
  if (stage_v_116_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((stage_v_38_1 ^ 0x2A) + pub_r000910_14_1) & 127;
  int stage_v_117_2 = ((stage_v_38_2 ^ 0x2A) + pub_r000910_14_2) & 127;
  if (stage_v_117_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((stage_v_45_1 ^ 0x2A) + pub_r000910_11_1) & 127;
  int stage_v_118_2 = ((stage_v_45_2 ^ 0x2A) + pub_r000910_11_2) & 127;
  if (stage_v_118_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((stage_v_82_1 ^ 0x2A) + pub_r000910_5_1) & 127;
  int stage_v_119_2 = ((stage_v_82_2 ^ 0x2A) + pub_r000910_5_2) & 127;
  if (stage_v_119_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((stage_v_28_1 ^ 0x2A) + pub_r000910_14_1) & 127;
  int stage_v_120_2 = ((stage_v_28_2 ^ 0x2A) + pub_r000910_14_2) & 127;
  if (stage_v_120_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((sec_r000910_10_1 ^ 0x2A) + pub_r000910_3_1) & 127;
  int stage_v_121_2 = ((sec_r000910_10_2 ^ 0x2A) + pub_r000910_3_2) & 127;
  if (stage_v_121_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((sec_r000910_8_1 ^ 0x2A) + pub_r000910_13_1) & 127;
  int stage_v_122_2 = ((sec_r000910_8_2 ^ 0x2A) + pub_r000910_13_2) & 127;
  if (stage_v_122_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((stage_v_63_1 ^ 0x2A) + pub_r000910_8_1) & 127;
  int stage_v_123_2 = ((stage_v_63_2 ^ 0x2A) + pub_r000910_8_2) & 127;
  if (stage_v_123_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((stage_v_66_1 ^ 0x2A) + pub_r000910_11_1) & 127;
  int stage_v_124_2 = ((stage_v_66_2 ^ 0x2A) + pub_r000910_11_2) & 127;
  if (stage_v_124_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((stage_v_58_1 ^ 0x2A) + pub_r000910_5_1) & 127;
  int stage_v_125_2 = ((stage_v_58_2 ^ 0x2A) + pub_r000910_5_2) & 127;
  if (stage_v_125_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((sec_r000910_12_1 ^ 0x2A) + pub_r000910_5_1) & 127;
  int stage_v_126_2 = ((sec_r000910_12_2 ^ 0x2A) + pub_r000910_5_2) & 127;
  if (stage_v_126_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((stage_v_100_1 ^ 0x2A) + pub_r000910_15_1) & 127;
  int stage_v_127_2 = ((stage_v_100_2 ^ 0x2A) + pub_r000910_15_2) & 127;
  if (stage_v_127_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((stage_v_28_1 ^ 0x2A) + pub_r000910_8_1) & 127;
  int stage_v_128_2 = ((stage_v_28_2 ^ 0x2A) + pub_r000910_8_2) & 127;
  if (stage_v_128_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((stage_v_76_1 ^ 0x2A) + pub_r000910_11_1) & 127;
  int stage_v_129_2 = ((stage_v_76_2 ^ 0x2A) + pub_r000910_11_2) & 127;
  if (stage_v_129_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((stage_v_61_1 ^ 0x2A) + pub_r000910_11_1) & 127;
  int stage_v_130_2 = ((stage_v_61_2 ^ 0x2A) + pub_r000910_11_2) & 127;
  if (stage_v_130_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((stage_v_62_1 ^ 0x2A) + pub_r000910_3_1) & 127;
  int stage_v_131_2 = ((stage_v_62_2 ^ 0x2A) + pub_r000910_3_2) & 127;
  if (stage_v_131_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((stage_v_41_1 ^ 0x2A) + pub_r000910_13_1) & 127;
  int stage_v_132_2 = ((stage_v_41_2 ^ 0x2A) + pub_r000910_13_2) & 127;
  if (stage_v_132_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((stage_v_63_1 ^ 0x2A) + pub_r000910_8_1) & 127;
  int stage_v_133_2 = ((stage_v_63_2 ^ 0x2A) + pub_r000910_8_2) & 127;
  if (stage_v_133_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((stage_v_94_1 ^ 0x2A) + pub_r000910_8_1) & 127;
  int stage_v_134_2 = ((stage_v_94_2 ^ 0x2A) + pub_r000910_8_2) & 127;
  if (stage_v_134_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((sec_r000910_0_1 ^ 0x2A) + pub_r000910_11_1) & 127;
  int stage_v_135_2 = ((sec_r000910_0_2 ^ 0x2A) + pub_r000910_11_2) & 127;
  if (stage_v_135_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((sec_r000910_8_1 ^ 0x2A) + pub_r000910_7_1) & 127;
  int stage_v_136_2 = ((sec_r000910_8_2 ^ 0x2A) + pub_r000910_7_2) & 127;
  if (stage_v_136_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((stage_v_64_1 ^ 0x2A) + pub_r000910_2_1) & 127;
  int stage_v_137_2 = ((stage_v_64_2 ^ 0x2A) + pub_r000910_2_2) & 127;
  if (stage_v_137_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((sec_r000910_6_1 ^ 0x2A) + pub_r000910_14_1) & 127;
  int stage_v_138_2 = ((sec_r000910_6_2 ^ 0x2A) + pub_r000910_14_2) & 127;
  if (stage_v_138_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((sec_r000910_15_1 ^ 0x2A) + pub_r000910_10_1) & 127;
  int stage_v_139_2 = ((sec_r000910_15_2 ^ 0x2A) + pub_r000910_10_2) & 127;
  if (stage_v_139_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((stage_v_75_1 ^ 0x2A) + pub_r000910_2_1) & 127;
  int stage_v_140_2 = ((stage_v_75_2 ^ 0x2A) + pub_r000910_2_2) & 127;
  if (stage_v_140_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((sec_r000910_6_1 ^ 0x2A) + pub_r000910_5_1) & 127;
  int stage_v_141_2 = ((sec_r000910_6_2 ^ 0x2A) + pub_r000910_5_2) & 127;
  if (stage_v_141_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((sec_r000910_4_1 ^ 0x2A) + pub_r000910_2_1) & 127;
  int stage_v_142_2 = ((sec_r000910_4_2 ^ 0x2A) + pub_r000910_2_2) & 127;
  if (stage_v_142_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((stage_v_54_1 ^ 0x2A) + pub_r000910_14_1) & 127;
  int stage_v_143_2 = ((stage_v_54_2 ^ 0x2A) + pub_r000910_14_2) & 127;
  if (stage_v_143_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((stage_v_85_1 ^ 0x2A) + pub_r000910_11_1) & 127;
  int stage_v_144_2 = ((stage_v_85_2 ^ 0x2A) + pub_r000910_11_2) & 127;
  if (stage_v_144_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((stage_v_36_1 ^ 0x2A) + pub_r000910_14_1) & 127;
  int stage_v_145_2 = ((stage_v_36_2 ^ 0x2A) + pub_r000910_14_2) & 127;
  if (stage_v_145_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((stage_v_90_1 ^ 0x2A) + pub_r000910_3_1) & 127;
  int stage_v_146_2 = ((stage_v_90_2 ^ 0x2A) + pub_r000910_3_2) & 127;
  if (stage_v_146_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((stage_v_61_1 ^ 0x2A) + pub_r000910_9_1) & 127;
  int stage_v_147_2 = ((stage_v_61_2 ^ 0x2A) + pub_r000910_9_2) & 127;
  if (stage_v_147_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((sec_r000910_10_1 ^ 0x2A) + pub_r000910_11_1) & 127;
  int stage_v_148_2 = ((sec_r000910_10_2 ^ 0x2A) + pub_r000910_11_2) & 127;
  if (stage_v_148_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((sec_r000910_1_1 ^ 0x2A) + pub_r000910_14_1) & 127;
  int stage_v_149_2 = ((sec_r000910_1_2 ^ 0x2A) + pub_r000910_14_2) & 127;
  if (stage_v_149_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((sec_r000910_13_1 ^ 0x2A) + pub_r000910_14_1) & 127;
  int stage_v_150_2 = ((sec_r000910_13_2 ^ 0x2A) + pub_r000910_14_2) & 127;
  if (stage_v_150_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((sec_r000910_13_1 ^ 0x2A) + pub_r000910_12_1) & 127;
  int stage_v_151_2 = ((sec_r000910_13_2 ^ 0x2A) + pub_r000910_12_2) & 127;
  if (stage_v_151_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((stage_v_71_1 ^ 0x2A) + pub_r000910_11_1) & 127;
  int stage_v_152_2 = ((stage_v_71_2 ^ 0x2A) + pub_r000910_11_2) & 127;
  if (stage_v_152_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((sec_r000910_9_1 ^ 0x2A) + pub_r000910_3_1) & 127;
  int stage_v_153_2 = ((sec_r000910_9_2 ^ 0x2A) + pub_r000910_3_2) & 127;
  if (stage_v_153_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((sec_r000910_10_1 ^ 0x2A) + pub_r000910_1_1) & 127;
  int stage_v_154_2 = ((sec_r000910_10_2 ^ 0x2A) + pub_r000910_1_2) & 127;
  if (stage_v_154_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((stage_v_67_1 ^ 0x2A) + pub_r000910_8_1) & 127;
  int stage_v_155_2 = ((stage_v_67_2 ^ 0x2A) + pub_r000910_8_2) & 127;
  if (stage_v_155_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((stage_v_59_1 ^ 0x2A) + pub_r000910_14_1) & 127;
  int stage_v_156_2 = ((stage_v_59_2 ^ 0x2A) + pub_r000910_14_2) & 127;
  if (stage_v_156_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((sec_r000910_4_1 ^ 0x2A) + pub_r000910_15_1) & 127;
  int stage_v_157_2 = ((sec_r000910_4_2 ^ 0x2A) + pub_r000910_15_2) & 127;
  if (stage_v_157_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((stage_v_111_1 ^ 0x2A) + pub_r000910_11_1) & 127;
  int stage_v_158_2 = ((stage_v_111_2 ^ 0x2A) + pub_r000910_11_2) & 127;
  if (stage_v_158_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((sec_r000910_14_1 ^ 0x2A) + pub_r000910_1_1) & 127;
  int stage_v_159_2 = ((sec_r000910_14_2 ^ 0x2A) + pub_r000910_1_2) & 127;
  if (stage_v_159_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((stage_v_145_1 ^ 0x2A) + pub_r000910_12_1) & 127;
  int stage_v_160_2 = ((stage_v_145_2 ^ 0x2A) + pub_r000910_12_2) & 127;
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
  int stage_v_161_1 = ((stage_v_116_1 ^ 0x2A) + pub_r000910_7_1) & 127;
  int stage_v_161_2 = ((stage_v_116_2 ^ 0x2A) + pub_r000910_7_2) & 127;
  if (stage_v_161_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((stage_v_120_1 ^ 0x2A) + pub_r000910_13_1) & 127;
  int stage_v_162_2 = ((stage_v_120_2 ^ 0x2A) + pub_r000910_13_2) & 127;
  if (stage_v_162_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((sec_r000910_9_1 ^ 0x2A) + pub_r000910_13_1) & 127;
  int stage_v_163_2 = ((sec_r000910_9_2 ^ 0x2A) + pub_r000910_13_2) & 127;
  if (stage_v_163_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((stage_v_108_1 ^ 0x2A) + pub_r000910_11_1) & 127;
  int stage_v_164_2 = ((stage_v_108_2 ^ 0x2A) + pub_r000910_11_2) & 127;
  if (stage_v_164_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((sec_r000910_10_1 ^ 0x2A) + pub_r000910_2_1) & 127;
  int stage_v_165_2 = ((sec_r000910_10_2 ^ 0x2A) + pub_r000910_2_2) & 127;
  if (stage_v_165_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((stage_v_102_1 ^ 0x2A) + pub_r000910_14_1) & 127;
  int stage_v_166_2 = ((stage_v_102_2 ^ 0x2A) + pub_r000910_14_2) & 127;
  if (stage_v_166_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((stage_v_67_1 ^ 0x2A) + pub_r000910_2_1) & 127;
  int stage_v_167_2 = ((stage_v_67_2 ^ 0x2A) + pub_r000910_2_2) & 127;
  if (stage_v_167_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((sec_r000910_7_1 ^ 0x2A) + pub_r000910_4_1) & 127;
  int stage_v_168_2 = ((sec_r000910_7_2 ^ 0x2A) + pub_r000910_4_2) & 127;
  if (stage_v_168_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((sec_r000910_12_1 ^ 0x2A) + pub_r000910_2_1) & 127;
  int stage_v_169_2 = ((sec_r000910_12_2 ^ 0x2A) + pub_r000910_2_2) & 127;
  if (stage_v_169_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((stage_v_53_1 ^ 0x2A) + pub_r000910_1_1) & 127;
  int stage_v_170_2 = ((stage_v_53_2 ^ 0x2A) + pub_r000910_1_2) & 127;
  if (stage_v_170_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((stage_v_129_1 ^ 0x2A) + pub_r000910_13_1) & 127;
  int stage_v_171_2 = ((stage_v_129_2 ^ 0x2A) + pub_r000910_13_2) & 127;
  if (stage_v_171_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((stage_v_124_1 ^ 0x2A) + pub_r000910_6_1) & 127;
  int stage_v_172_2 = ((stage_v_124_2 ^ 0x2A) + pub_r000910_6_2) & 127;
  if (stage_v_172_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((stage_v_65_1 ^ 0x2A) + pub_r000910_7_1) & 127;
  int stage_v_173_2 = ((stage_v_65_2 ^ 0x2A) + pub_r000910_7_2) & 127;
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
  int stage_v_174_1 = ((stage_v_57_1 ^ 0x2A) + pub_r000910_13_1) & 127;
  int stage_v_174_2 = ((stage_v_57_2 ^ 0x2A) + pub_r000910_13_2) & 127;
  if (stage_v_174_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((stage_v_42_1 ^ 0x2A) + pub_r000910_7_1) & 127;
  int stage_v_175_2 = ((stage_v_42_2 ^ 0x2A) + pub_r000910_7_2) & 127;
  if (stage_v_175_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((sec_r000910_6_1 ^ 0x2A) + pub_r000910_2_1) & 127;
  int stage_v_176_2 = ((sec_r000910_6_2 ^ 0x2A) + pub_r000910_2_2) & 127;
  if (stage_v_176_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((sec_r000910_4_1 ^ 0x2A) + pub_r000910_6_1) & 127;
  int stage_v_177_2 = ((sec_r000910_4_2 ^ 0x2A) + pub_r000910_6_2) & 127;
  if (stage_v_177_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((sec_r000910_9_1 ^ 0x2A) + pub_r000910_13_1) & 127;
  int stage_v_178_2 = ((sec_r000910_9_2 ^ 0x2A) + pub_r000910_13_2) & 127;
  if (stage_v_178_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((stage_v_127_1 ^ 0x2A) + pub_r000910_2_1) & 127;
  int stage_v_179_2 = ((stage_v_127_2 ^ 0x2A) + pub_r000910_2_2) & 127;
  if (stage_v_179_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((sec_r000910_14_1 ^ 0x2A) + pub_r000910_5_1) & 127;
  int stage_v_180_2 = ((sec_r000910_14_2 ^ 0x2A) + pub_r000910_5_2) & 127;
  if (stage_v_180_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((sec_r000910_5_1 ^ 0x2A) + pub_r000910_0_1) & 127;
  int stage_v_181_2 = ((sec_r000910_5_2 ^ 0x2A) + pub_r000910_0_2) & 127;
  if (stage_v_181_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((sec_r000910_9_1 ^ 0x2A) + pub_r000910_8_1) & 127;
  int stage_v_182_2 = ((sec_r000910_9_2 ^ 0x2A) + pub_r000910_8_2) & 127;
  if (stage_v_182_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((stage_v_60_1 ^ 0x2A) + pub_r000910_12_1) & 127;
  int stage_v_183_2 = ((stage_v_60_2 ^ 0x2A) + pub_r000910_12_2) & 127;
  if (stage_v_183_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((sec_r000910_5_1 ^ 0x2A) + pub_r000910_12_1) & 127;
  int stage_v_184_2 = ((sec_r000910_5_2 ^ 0x2A) + pub_r000910_12_2) & 127;
  if (stage_v_184_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000910_9_1 != sec_r000910_9_2);
  __CPROVER_assume(sec_r000910_10_1 != sec_r000910_10_2);
  __CPROVER_assume(sec_r000910_11_1 != sec_r000910_11_2);
  __CPROVER_assume(pub_r000910_3_1 == pub_r000910_3_2);
  __CPROVER_assume(pub_r000910_6_1 == pub_r000910_6_2);
  __CPROVER_assume(pub_r000910_5_1 == pub_r000910_5_2);
  __CPROVER_assume(sec_r000910_5_1 != sec_r000910_5_2);
  __CPROVER_assume(pub_r000910_8_1 == pub_r000910_8_2);
  __CPROVER_assume(sec_r000910_2_1 != sec_r000910_2_2);
  __CPROVER_assume(sec_r000910_14_1 != sec_r000910_14_2);
  __CPROVER_assume(sec_r000910_13_1 != sec_r000910_13_2);
  __CPROVER_assume(pub_r000910_11_1 == pub_r000910_11_2);
  __CPROVER_assume(sec_r000910_12_1 != sec_r000910_12_2);
  __CPROVER_assume(sec_r000910_3_1 != sec_r000910_3_2);
  __CPROVER_assume(pub_r000910_2_1 == pub_r000910_2_2);
  __CPROVER_assume(pub_r000910_9_1 == pub_r000910_9_2);
  __CPROVER_assume(pub_r000910_15_1 == pub_r000910_15_2);
  __CPROVER_assume(pub_r000910_0_1 == pub_r000910_0_2);
  __CPROVER_assume(sec_r000910_8_1 != sec_r000910_8_2);
  __CPROVER_assume(sec_r000910_4_1 != sec_r000910_4_2);
  __CPROVER_assume(pub_r000910_4_1 == pub_r000910_4_2);
  __CPROVER_assume(pub_r000910_10_1 == pub_r000910_10_2);
  __CPROVER_assume(pub_r000910_14_1 == pub_r000910_14_2);
  __CPROVER_assume(sec_r000910_6_1 != sec_r000910_6_2);
  __CPROVER_assume(sec_r000910_15_1 != sec_r000910_15_2);
  __CPROVER_assume(sec_r000910_0_1 != sec_r000910_0_2);
  __CPROVER_assume(pub_r000910_7_1 == pub_r000910_7_2);
  __CPROVER_assume(sec_r000910_7_1 != sec_r000910_7_2);
  __CPROVER_assume(pub_r000910_1_1 == pub_r000910_1_2);
  __CPROVER_assume(sec_r000910_1_1 != sec_r000910_1_2);
  __CPROVER_assume(pub_r000910_13_1 == pub_r000910_13_2);
  __CPROVER_assume(pub_r000910_12_1 == pub_r000910_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.iv == st_var_2_2.iv);
  assert(st_var_2_1.round_key == st_var_2_2.round_key);
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
}


