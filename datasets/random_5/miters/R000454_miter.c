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
struct SensorNode_R000454_5413_0
{
  int status;
  short calib;
  unsigned char offset;
  int buffer[3];
};
struct CipherContext_R000454_5413_1
{
  int iv;
  int round_key;
  short flags;
  int counter;
  int nonce;
  int buffer[3];
};
struct DeviceConfig_R000454_5413_2
{
  int stop_bits;
  int timeout;
  int port;
  unsigned char id;
  int buffer[3];
};
union PacketPayload_R000454_5413_0
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
void fn_R000454_5413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000454_5413_1 st_1 = {0};
  struct CipherContext_R000454_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_95_1 > 17)
  {
    acc_1 = ((acc_1 + (coefficient_95_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_95_2 > 17)
  {
    acc_2 = ((acc_2 + (coefficient_95_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_84_1)
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

  switch (tally_84_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_66_1 = local_arr_1[aux_1 % 3];
  int quotient_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_66_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_95_1 == coefficient_95_2);
  assert(tally_84_1 == tally_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_66_1 == quotient_66_2);
}

int fn_R000454_5413_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000454_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_95 > 17)
  {
    acc = ((acc + (coefficient_95 * 2)) + 5) & 127;
    aux ^= coefficient_95 & 15;
  }
  else
  {
    acc = ((acc - coefficient_95) + 11) & 127;
    aux += 3;
  }
  int tally_84 = (aux + st.buffer[1]) & 3;
  switch (tally_84)
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

  int local_arr[3] = {4, 9, 15};
  int quotient_66 = local_arr[aux % 3];
  acc = (acc + (quotient_66 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000454_5413_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000454_5413_2 st_1 = {0};
  struct DeviceConfig_R000454_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_79_1 = local_arr_1[aux_1 % 3];
  int delta_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_79_2 * 2)) & 127;
  int phase_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_58_1 > 45)
  {
    acc_1 = ((acc_1 + (phase_58_1 * 2)) + 5) & 127;
    aux_1 ^= phase_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_58_2 > 45)
  {
    acc_2 = ((acc_2 + (phase_58_2 * 2)) + 5) & 127;
    aux_2 ^= phase_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_58_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_82_1) & 63;
  aux_2 = (aux_2 + margin_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_79_1 == delta_79_2);
  assert(phase_58_1 == phase_58_2);
  assert(margin_82_1 == margin_82_2);
}

int fn_R000454_5413_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000454_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int delta_79 = local_arr[aux % 3];
  acc = (acc + (delta_79 * 2)) & 127;
  int phase_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_58 > 45)
  {
    acc = ((acc + (phase_58 * 2)) + 5) & 127;
    aux ^= phase_58 & 15;
  }
  else
  {
    acc = ((acc - phase_58) + 11) & 127;
    aux += 3;
  }
  int margin_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_82) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000454_5413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000454_5413_0 st_1 = {0};
  struct SensorNode_R000454_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_41_1 = local_arr_1[aux_1 % 3];
  int coefficient_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_41_2 * 2)) & 127;
  int cursor_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_31_1) & 63;
  aux_2 = (aux_2 + cursor_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_41_1 == coefficient_41_2);
  assert(cursor_31_1 == cursor_31_2);
}

int fn_R000454_5413_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000454_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int coefficient_41 = local_arr[aux % 3];
  acc = (acc + (coefficient_41 * 2)) & 127;
  int cursor_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000454_5413_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000454_5413_2 st_1 = {0};
  struct DeviceConfig_R000454_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_98_1) & 63;
  aux_2 = (aux_2 + phase_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_98_1 == phase_98_2);
}

int fn_R000454_5413_3(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000454_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_98) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000454_5413_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000454_5413_1 st_1 = {0};
  struct CipherContext_R000454_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int stride_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_13_1 > 21)
  {
    acc_1 = ((acc_1 + (stride_13_1 * 2)) + 5) & 127;
    aux_1 ^= stride_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_13_2 > 21)
  {
    acc_2 = ((acc_2 + (stride_13_2 * 2)) + 5) & 127;
    aux_2 ^= stride_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_78_1 = local_arr_1[aux_1 % 3];
  int margin_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_78_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_13_1 == stride_13_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_78_1 == margin_78_2);
}

int fn_R000454_5413_4(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000454_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int stride_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_13 > 21)
  {
    acc = ((acc + (stride_13 * 2)) + 5) & 127;
    aux ^= stride_13 & 15;
  }
  else
  {
    acc = ((acc - stride_13) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int margin_78 = local_arr[aux % 3];
  acc = (acc + (margin_78 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000454_5413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000454_5413_0 st_1 = {0};
  struct SensorNode_R000454_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int bound_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_60_1 > 43)
  {
    acc_1 = ((acc_1 + (bound_60_1 * 2)) + 5) & 127;
    aux_1 ^= bound_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_60_2 > 43)
  {
    acc_2 = ((acc_2 + (bound_60_2 * 2)) + 5) & 127;
    aux_2 ^= bound_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_44_1) & 63;
  aux_2 = (aux_2 + metric_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_95_1)
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

  switch (margin_95_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_60_1 == bound_60_2);
  assert(metric_44_1 == metric_44_2);
  assert(margin_95_1 == margin_95_2);
}

int fn_R000454_5413_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000454_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int bound_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_60 > 43)
  {
    acc = ((acc + (bound_60 * 2)) + 5) & 127;
    aux ^= bound_60 & 15;
  }
  else
  {
    acc = ((acc - bound_60) + 11) & 127;
    aux += 3;
  }
  int metric_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_44) & 63;
  acc ^= aux;
  int margin_95 = (aux + st.buffer[1]) & 3;
  switch (margin_95)
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

void fn_R000454_5413_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000454_5413_2 st_1 = {0};
  struct DeviceConfig_R000454_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_35_1 = local_arr_1[aux_1 % 3];
  int tracker_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_35_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_37_1) & 63;
  aux_2 = (aux_2 + factor_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_35_1 == tracker_35_2);
  assert(factor_37_1 == factor_37_2);
}

int fn_R000454_5413_6(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000454_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int tracker_35 = local_arr[aux % 3];
  acc = (acc + (tracker_35 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_37) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000454_5413_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000454_5413_1 st_1 = {0};
  struct CipherContext_R000454_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_93_1 = local_arr_1[aux_1 % 3];
  int accumulator_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_93_2 * 2)) & 127;
  int metric_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_45_1 > 13)
  {
    acc_1 = ((acc_1 + (metric_45_1 * 2)) + 5) & 127;
    aux_1 ^= metric_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_45_2 > 13)
  {
    acc_2 = ((acc_2 + (metric_45_2 * 2)) + 5) & 127;
    aux_2 ^= metric_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_90_1) & 63;
  aux_2 = (aux_2 + metric_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_93_1 == accumulator_93_2);
  assert(metric_45_1 == metric_45_2);
  assert(metric_90_1 == metric_90_2);
}

int fn_R000454_5413_7(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000454_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int accumulator_93 = local_arr[aux % 3];
  acc = (acc + (accumulator_93 * 2)) & 127;
  int metric_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_45 > 13)
  {
    acc = ((acc + (metric_45 * 2)) + 5) & 127;
    aux ^= metric_45 & 15;
  }
  else
  {
    acc = ((acc - metric_45) + 11) & 127;
    aux += 3;
  }
  int metric_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_90) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000454_5413_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000454_5413_0 st_1 = {0};
  struct SensorNode_R000454_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int bound_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_10_1 > 45)
  {
    acc_1 = ((acc_1 + (bound_10_1 * 2)) + 5) & 127;
    aux_1 ^= bound_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_10_2 > 45)
  {
    acc_2 = ((acc_2 + (bound_10_2 * 2)) + 5) & 127;
    aux_2 ^= bound_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_91_1) & 63;
  aux_2 = (aux_2 + margin_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_58_1)
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

  switch (quotient_58_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_10_1 == bound_10_2);
  assert(margin_91_1 == margin_91_2);
  assert(quotient_58_1 == quotient_58_2);
}

int fn_R000454_5413_8(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000454_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int bound_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_10 > 45)
  {
    acc = ((acc + (bound_10 * 2)) + 5) & 127;
    aux ^= bound_10 & 15;
  }
  else
  {
    acc = ((acc - bound_10) + 11) & 127;
    aux += 3;
  }
  int margin_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_91) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_58 = (aux + st.buffer[1]) & 3;
  switch (quotient_58)
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

void fn_R000454_5413_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000454_5413_2 st_1 = {0};
  struct DeviceConfig_R000454_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int coefficient_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_54_1)
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

  switch (coefficient_54_2)
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

  int bound_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_42_1 > 12)
  {
    acc_1 = ((acc_1 + (bound_42_1 * 2)) + 5) & 127;
    aux_1 ^= bound_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_42_2 > 12)
  {
    acc_2 = ((acc_2 + (bound_42_2 * 2)) + 5) & 127;
    aux_2 ^= bound_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_42_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_54_1 == coefficient_54_2);
  assert(bound_42_1 == bound_42_2);
}

int fn_R000454_5413_9(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000454_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int coefficient_54 = (aux + st.buffer[1]) & 3;
  switch (coefficient_54)
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

  int bound_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_42 > 12)
  {
    acc = ((acc + (bound_42 * 2)) + 5) & 127;
    aux ^= bound_42 & 15;
  }
  else
  {
    acc = ((acc - bound_42) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000454_5413_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000454_5413_0 st_1 = {0};
  struct SensorNode_R000454_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_90_1 = local_arr_1[aux_1 % 3];
  int cursor_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_90_2 * 2)) & 127;
  int phase_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_67_1)
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

  switch (phase_67_2)
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

  int pivot_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_47_1 > 42)
  {
    acc_1 = ((acc_1 + (pivot_47_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_47_2 > 42)
  {
    acc_2 = ((acc_2 + (pivot_47_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_47_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_90_1 == cursor_90_2);
  assert(phase_67_1 == phase_67_2);
  assert(pivot_47_1 == pivot_47_2);
}

int fn_R000454_5413_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000454_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int cursor_90 = local_arr[aux % 3];
  acc = (acc + (cursor_90 * 2)) & 127;
  int phase_67 = (aux + st.buffer[1]) & 3;
  switch (phase_67)
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

  int pivot_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_47 > 42)
  {
    acc = ((acc + (pivot_47 * 2)) + 5) & 127;
    aux ^= pivot_47 & 15;
  }
  else
  {
    acc = ((acc - pivot_47) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000454_5413_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000454_5413_0 st_1 = {0};
  struct SensorNode_R000454_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int scale_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_34_1 > 25)
  {
    acc_1 = ((acc_1 + (scale_34_1 * 2)) + 5) & 127;
    aux_1 ^= scale_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_34_2 > 25)
  {
    acc_2 = ((acc_2 + (scale_34_2 * 2)) + 5) & 127;
    aux_2 ^= scale_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_77_1) & 63;
  aux_2 = (aux_2 + factor_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_67_1)
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

  switch (coefficient_67_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_34_1 == scale_34_2);
  assert(factor_77_1 == factor_77_2);
  assert(coefficient_67_1 == coefficient_67_2);
}

int fn_R000454_5413_11(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000454_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int scale_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_34 > 25)
  {
    acc = ((acc + (scale_34 * 2)) + 5) & 127;
    aux ^= scale_34 & 15;
  }
  else
  {
    acc = ((acc - scale_34) + 11) & 127;
    aux += 3;
  }
  int factor_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_77) & 63;
  acc ^= aux;
  int coefficient_67 = (aux + st.buffer[1]) & 3;
  switch (coefficient_67)
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

void fn_R000454_5413_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000454_5413_0 st_1 = {0};
  struct SensorNode_R000454_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_90_1 > 26)
  {
    acc_1 = ((acc_1 + (coefficient_90_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_90_2 > 26)
  {
    acc_2 = ((acc_2 + (coefficient_90_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_90_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_46_1) & 63;
  aux_2 = (aux_2 + parity_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_89_1)
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

  switch (metric_89_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_90_1 == coefficient_90_2);
  assert(parity_46_1 == parity_46_2);
  assert(metric_89_1 == metric_89_2);
}

int fn_R000454_5413_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000454_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_90 > 26)
  {
    acc = ((acc + (coefficient_90 * 2)) + 5) & 127;
    aux ^= coefficient_90 & 15;
  }
  else
  {
    acc = ((acc - coefficient_90) + 11) & 127;
    aux += 3;
  }
  int parity_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_46) & 63;
  acc ^= aux;
  int metric_89 = (aux + st.buffer[1]) & 3;
  switch (metric_89)
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

void fn_R000454_5413_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000454_5413_2 st_1 = {0};
  struct DeviceConfig_R000454_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_59_1 > 31)
  {
    acc_1 = ((acc_1 + (threshold_59_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_59_2 > 31)
  {
    acc_2 = ((acc_2 + (threshold_59_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_59_1 == threshold_59_2);
}

int fn_R000454_5413_13(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000454_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_59 > 31)
  {
    acc = ((acc + (threshold_59 * 2)) + 5) & 127;
    aux ^= threshold_59 & 15;
  }
  else
  {
    acc = ((acc - threshold_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000454_5413_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000454_5413_1 st_1 = {0};
  struct CipherContext_R000454_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int residue_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_71_1 > 16)
  {
    acc_1 = ((acc_1 + (residue_71_1 * 2)) + 5) & 127;
    aux_1 ^= residue_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_71_2 > 16)
  {
    acc_2 = ((acc_2 + (residue_71_2 * 2)) + 5) & 127;
    aux_2 ^= residue_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_78_1 = local_arr_1[aux_1 % 3];
  int vector_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_78_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_71_1 == residue_71_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_78_1 == vector_78_2);
}

int fn_R000454_5413_14(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000454_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int residue_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_71 > 16)
  {
    acc = ((acc + (residue_71 * 2)) + 5) & 127;
    aux ^= residue_71 & 15;
  }
  else
  {
    acc = ((acc - residue_71) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_78 = local_arr[aux % 3];
  acc = (acc + (vector_78 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000454_5413_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000454_5413_0 st_1 = {0};
  struct SensorNode_R000454_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_85_1) & 63;
  aux_2 = (aux_2 + anchor_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_85_1 == anchor_85_2);
}

int fn_R000454_5413_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000454_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_85) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000454_5413_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000454_5413_2 st_1 = {0};
  struct DeviceConfig_R000454_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_75_1 = local_arr_1[aux_1 % 3];
  int anchor_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_75_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_75_1 == anchor_75_2);
}

int fn_R000454_5413_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000454_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int anchor_75 = local_arr[aux % 3];
  acc = (acc + (anchor_75 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000454_5413_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000454_5413_1 st_1 = {0};
  struct CipherContext_R000454_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int threshold_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_90_1)
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

  switch (threshold_90_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_90_1 == threshold_90_2);
}

int fn_R000454_5413_17(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000454_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int threshold_90 = (aux + st.buffer[1]) & 3;
  switch (threshold_90)
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
  return (acc + aux) & 255;
}

void fn_R000454_5413_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000454_5413_1 st_1 = {0};
  struct CipherContext_R000454_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_62_1 = local_arr_1[aux_1 % 3];
  int threshold_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_62_2 * 2)) & 127;
  int offset_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_78_1) & 63;
  aux_2 = (aux_2 + offset_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_62_1 == threshold_62_2);
  assert(offset_78_1 == offset_78_2);
}

int fn_R000454_5413_18(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000454_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int threshold_62 = local_arr[aux % 3];
  acc = (acc + (threshold_62 * 2)) & 127;
  int offset_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_78) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000454_0_1;
  int sec_r000454_0_2;
  int sec_r000454_1_1;
  int sec_r000454_1_2;
  int sec_r000454_2_1;
  int sec_r000454_2_2;
  int sec_r000454_3_1;
  int sec_r000454_3_2;
  int sec_r000454_4_1;
  int sec_r000454_4_2;
  int sec_r000454_5_1;
  int sec_r000454_5_2;
  int sec_r000454_6_1;
  int sec_r000454_6_2;
  int sec_r000454_7_1;
  int sec_r000454_7_2;
  int sec_r000454_8_1;
  int sec_r000454_8_2;
  int sec_r000454_9_1;
  int sec_r000454_9_2;
  int sec_r000454_10_1;
  int sec_r000454_10_2;
  int sec_r000454_11_1;
  int sec_r000454_11_2;
  int sec_r000454_12_1;
  int sec_r000454_12_2;
  int sec_r000454_13_1;
  int sec_r000454_13_2;
  int sec_r000454_14_1;
  int sec_r000454_14_2;
  int sec_r000454_15_1;
  int sec_r000454_15_2;
  int sec_r000454_16_1;
  int sec_r000454_16_2;
  int pub_r000454_0_1;
  int pub_r000454_0_2;
  int pub_r000454_1_1;
  int pub_r000454_1_2;
  int pub_r000454_2_1;
  int pub_r000454_2_2;
  int pub_r000454_3_1;
  int pub_r000454_3_2;
  int pub_r000454_4_1;
  int pub_r000454_4_2;
  int pub_r000454_5_1;
  int pub_r000454_5_2;
  int pub_r000454_6_1;
  int pub_r000454_6_2;
  int pub_r000454_7_1;
  int pub_r000454_7_2;
  int pub_r000454_8_1;
  int pub_r000454_8_2;
  int pub_r000454_9_1;
  int pub_r000454_9_2;
  int pub_r000454_10_1;
  int pub_r000454_10_2;
  int pub_r000454_11_1;
  int pub_r000454_11_2;
  int pub_r000454_12_1;
  int pub_r000454_12_2;
  int pub_r000454_13_1;
  int pub_r000454_13_2;
  int pub_r000454_14_1;
  int pub_r000454_14_2;
  int pub_r000454_15_1;
  int pub_r000454_15_2;
  int pub_r000454_16_1;
  int pub_r000454_16_2;
  int pub_r000454_17_1;
  int pub_r000454_17_2;
  int pub_r000454_18_1;
  int pub_r000454_18_2;
  int pub_r000454_19_1;
  int pub_r000454_19_2;
  int pub_r000454_20_1;
  int pub_r000454_20_2;
  int pub_r000454_21_1;
  int pub_r000454_21_2;
  int pub_r000454_22_1;
  int pub_r000454_22_2;
  int pub_r000454_23_1;
  int pub_r000454_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000454_0_1 >= (-100)) && (pub_r000454_0_1 <= 100));
  __CPROVER_assume((pub_r000454_0_2 >= (-100)) && (pub_r000454_0_2 <= 100));
  __CPROVER_assume((pub_r000454_1_1 >= (-100)) && (pub_r000454_1_1 <= 100));
  __CPROVER_assume((pub_r000454_1_2 >= (-100)) && (pub_r000454_1_2 <= 100));
  __CPROVER_assume((pub_r000454_2_1 >= (-100)) && (pub_r000454_2_1 <= 100));
  __CPROVER_assume((pub_r000454_2_2 >= (-100)) && (pub_r000454_2_2 <= 100));
  __CPROVER_assume((pub_r000454_3_1 >= (-100)) && (pub_r000454_3_1 <= 100));
  __CPROVER_assume((pub_r000454_3_2 >= (-100)) && (pub_r000454_3_2 <= 100));
  __CPROVER_assume((pub_r000454_4_1 >= (-100)) && (pub_r000454_4_1 <= 100));
  __CPROVER_assume((pub_r000454_4_2 >= (-100)) && (pub_r000454_4_2 <= 100));
  __CPROVER_assume((pub_r000454_5_1 >= (-100)) && (pub_r000454_5_1 <= 100));
  __CPROVER_assume((pub_r000454_5_2 >= (-100)) && (pub_r000454_5_2 <= 100));
  __CPROVER_assume((pub_r000454_6_1 >= (-100)) && (pub_r000454_6_1 <= 100));
  __CPROVER_assume((pub_r000454_6_2 >= (-100)) && (pub_r000454_6_2 <= 100));
  __CPROVER_assume((pub_r000454_7_1 >= (-100)) && (pub_r000454_7_1 <= 100));
  __CPROVER_assume((pub_r000454_7_2 >= (-100)) && (pub_r000454_7_2 <= 100));
  __CPROVER_assume((pub_r000454_8_1 >= (-100)) && (pub_r000454_8_1 <= 100));
  __CPROVER_assume((pub_r000454_8_2 >= (-100)) && (pub_r000454_8_2 <= 100));
  __CPROVER_assume((pub_r000454_9_1 >= (-100)) && (pub_r000454_9_1 <= 100));
  __CPROVER_assume((pub_r000454_9_2 >= (-100)) && (pub_r000454_9_2 <= 100));
  __CPROVER_assume((pub_r000454_10_1 >= (-100)) && (pub_r000454_10_1 <= 100));
  __CPROVER_assume((pub_r000454_10_2 >= (-100)) && (pub_r000454_10_2 <= 100));
  __CPROVER_assume((pub_r000454_11_1 >= (-100)) && (pub_r000454_11_1 <= 100));
  __CPROVER_assume((pub_r000454_11_2 >= (-100)) && (pub_r000454_11_2 <= 100));
  __CPROVER_assume((pub_r000454_12_1 >= (-100)) && (pub_r000454_12_1 <= 100));
  __CPROVER_assume((pub_r000454_12_2 >= (-100)) && (pub_r000454_12_2 <= 100));
  __CPROVER_assume((pub_r000454_13_1 >= (-100)) && (pub_r000454_13_1 <= 100));
  __CPROVER_assume((pub_r000454_13_2 >= (-100)) && (pub_r000454_13_2 <= 100));
  __CPROVER_assume((pub_r000454_14_1 >= (-100)) && (pub_r000454_14_1 <= 100));
  __CPROVER_assume((pub_r000454_14_2 >= (-100)) && (pub_r000454_14_2 <= 100));
  __CPROVER_assume((pub_r000454_15_1 >= (-100)) && (pub_r000454_15_1 <= 100));
  __CPROVER_assume((pub_r000454_15_2 >= (-100)) && (pub_r000454_15_2 <= 100));
  __CPROVER_assume((pub_r000454_16_1 >= (-100)) && (pub_r000454_16_1 <= 100));
  __CPROVER_assume((pub_r000454_16_2 >= (-100)) && (pub_r000454_16_2 <= 100));
  __CPROVER_assume((pub_r000454_17_1 >= (-100)) && (pub_r000454_17_1 <= 100));
  __CPROVER_assume((pub_r000454_17_2 >= (-100)) && (pub_r000454_17_2 <= 100));
  __CPROVER_assume((pub_r000454_18_1 >= (-100)) && (pub_r000454_18_1 <= 100));
  __CPROVER_assume((pub_r000454_18_2 >= (-100)) && (pub_r000454_18_2 <= 100));
  __CPROVER_assume((pub_r000454_19_1 >= (-100)) && (pub_r000454_19_1 <= 100));
  __CPROVER_assume((pub_r000454_19_2 >= (-100)) && (pub_r000454_19_2 <= 100));
  __CPROVER_assume((pub_r000454_20_1 >= (-100)) && (pub_r000454_20_1 <= 100));
  __CPROVER_assume((pub_r000454_20_2 >= (-100)) && (pub_r000454_20_2 <= 100));
  __CPROVER_assume((pub_r000454_21_1 >= (-100)) && (pub_r000454_21_1 <= 100));
  __CPROVER_assume((pub_r000454_21_2 >= (-100)) && (pub_r000454_21_2 <= 100));
  __CPROVER_assume((pub_r000454_22_1 >= (-100)) && (pub_r000454_22_1 <= 100));
  __CPROVER_assume((pub_r000454_22_2 >= (-100)) && (pub_r000454_22_2 <= 100));
  __CPROVER_assume((pub_r000454_23_1 >= (-100)) && (pub_r000454_23_1 <= 100));
  __CPROVER_assume((pub_r000454_23_2 >= (-100)) && (pub_r000454_23_2 <= 100));
  __CPROVER_assume((sec_r000454_0_1 >= 0) && (sec_r000454_0_1 <= 255));
  __CPROVER_assume((sec_r000454_0_2 >= 0) && (sec_r000454_0_2 <= 255));
  __CPROVER_assume((sec_r000454_1_1 >= 0) && (sec_r000454_1_1 <= 255));
  __CPROVER_assume((sec_r000454_1_2 >= 0) && (sec_r000454_1_2 <= 255));
  __CPROVER_assume((sec_r000454_2_1 >= 0) && (sec_r000454_2_1 <= 255));
  __CPROVER_assume((sec_r000454_2_2 >= 0) && (sec_r000454_2_2 <= 255));
  __CPROVER_assume((sec_r000454_3_1 >= 0) && (sec_r000454_3_1 <= 255));
  __CPROVER_assume((sec_r000454_3_2 >= 0) && (sec_r000454_3_2 <= 255));
  __CPROVER_assume((sec_r000454_4_1 >= 0) && (sec_r000454_4_1 <= 255));
  __CPROVER_assume((sec_r000454_4_2 >= 0) && (sec_r000454_4_2 <= 255));
  __CPROVER_assume((sec_r000454_5_1 >= 0) && (sec_r000454_5_1 <= 255));
  __CPROVER_assume((sec_r000454_5_2 >= 0) && (sec_r000454_5_2 <= 255));
  __CPROVER_assume((sec_r000454_6_1 >= 0) && (sec_r000454_6_1 <= 255));
  __CPROVER_assume((sec_r000454_6_2 >= 0) && (sec_r000454_6_2 <= 255));
  __CPROVER_assume((sec_r000454_7_1 >= 0) && (sec_r000454_7_1 <= 255));
  __CPROVER_assume((sec_r000454_7_2 >= 0) && (sec_r000454_7_2 <= 255));
  __CPROVER_assume((sec_r000454_8_1 >= 0) && (sec_r000454_8_1 <= 255));
  __CPROVER_assume((sec_r000454_8_2 >= 0) && (sec_r000454_8_2 <= 255));
  __CPROVER_assume((sec_r000454_9_1 >= 0) && (sec_r000454_9_1 <= 255));
  __CPROVER_assume((sec_r000454_9_2 >= 0) && (sec_r000454_9_2 <= 255));
  __CPROVER_assume((sec_r000454_10_1 >= 0) && (sec_r000454_10_1 <= 255));
  __CPROVER_assume((sec_r000454_10_2 >= 0) && (sec_r000454_10_2 <= 255));
  __CPROVER_assume((sec_r000454_11_1 >= 0) && (sec_r000454_11_1 <= 255));
  __CPROVER_assume((sec_r000454_11_2 >= 0) && (sec_r000454_11_2 <= 255));
  __CPROVER_assume((sec_r000454_12_1 >= 0) && (sec_r000454_12_1 <= 255));
  __CPROVER_assume((sec_r000454_12_2 >= 0) && (sec_r000454_12_2 <= 255));
  __CPROVER_assume((sec_r000454_13_1 >= 0) && (sec_r000454_13_1 <= 255));
  __CPROVER_assume((sec_r000454_13_2 >= 0) && (sec_r000454_13_2 <= 255));
  __CPROVER_assume((sec_r000454_14_1 >= 0) && (sec_r000454_14_1 <= 255));
  __CPROVER_assume((sec_r000454_14_2 >= 0) && (sec_r000454_14_2 <= 255));
  __CPROVER_assume((sec_r000454_15_1 >= 0) && (sec_r000454_15_1 <= 255));
  __CPROVER_assume((sec_r000454_15_2 >= 0) && (sec_r000454_15_2 <= 255));
  __CPROVER_assume((sec_r000454_16_1 >= 0) && (sec_r000454_16_1 <= 255));
  __CPROVER_assume((sec_r000454_16_2 >= 0) && (sec_r000454_16_2 <= 255));
  struct SensorNode_R000454_5413_0 st_var_0_1 = {0};
  struct SensorNode_R000454_5413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000454_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000454_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000454_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000454_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000454_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000454_0_2 + 7) & 15;
  struct CipherContext_R000454_5413_1 st_var_1_1 = {0};
  struct CipherContext_R000454_5413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000454_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000454_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000454_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000454_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000454_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000454_0_2 + 9) & 15;
  struct DeviceConfig_R000454_5413_2 st_var_2_1 = {0};
  struct DeviceConfig_R000454_5413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000454_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000454_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000454_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000454_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000454_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000454_0_2 + 11) & 15;
  union PacketPayload_R000454_5413_0 u_var_1;
  union PacketPayload_R000454_5413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_0_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_0_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_0_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_2_1 = ((st_var_2_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_2_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 48)
    {
      chk_sum_1 ^= stage_v_2_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_2_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 48)
    {
      chk_sum_2 ^= stage_v_2_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_3_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (8 & 31);
  int stage_v_3_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (8 & 31);
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= (stage_v_3_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_3_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 5) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (10 & 31);
  int stage_v_5_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (10 & 31);
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= (stage_v_5_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_5_2 << 1) & 127;
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
  if (stage_v_7_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 49)
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
  if (stage_v_7_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 49)
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
  int stage_v_8_1 = ((st_var_2_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_2_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 43)
    {
      chk_sum_1 ^= stage_v_8_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_8_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 43)
    {
      chk_sum_2 ^= stage_v_8_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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

  switch (stage_v_12_2)
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

  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_14_1 = table_1[2];
  int stage_v_14_2 = table_2[2];
  table_1[2] = (table_1[3] + 29) & 63;
  table_2[2] = (table_2[3] + 29) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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
  int stage_v_18_1 = (st_var_0_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_0_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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

  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  }

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

  switch (stage_v_25_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 27) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = ((st_var_0_1.buffer[0] * 2) + 88) & 63;
  int stage_v_27_2 = ((st_var_0_2.buffer[0] * 2) + 88) & 63;
  if (stage_v_27_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_27_1) - 5) & 255;
    if (stage_v_27_1 > 44)
    {
      chk_sum_1 ^= stage_v_27_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_27_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_27_2) - 5) & 255;
    if (stage_v_27_2 > 44)
    {
      chk_sum_2 ^= stage_v_27_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_28_1 = ((st_var_1_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_1_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 46)
    {
      chk_sum_1 ^= stage_v_28_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_28_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 46)
    {
      chk_sum_2 ^= stage_v_28_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 32) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 32) & 15;
  int stage_v_31_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_31_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= stage_v_31_1;
  chk_sum_2 ^= stage_v_31_2;
  int stage_v_32_1 = (st_var_2_1.buffer[0] ^ 35) & 3;
  int stage_v_32_2 = (st_var_2_2.buffer[0] ^ 35) & 3;
  switch (stage_v_32_1)
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

  switch (stage_v_32_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 34) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_34_1 = ((stage_v_34_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_34_2 = ((stage_v_34_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
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
  if (stage_v_36_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 43)
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
  if (stage_v_36_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 43)
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
  int stage_v_38_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_38_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_39_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (44 & 31);
  int stage_v_39_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (44 & 31);
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= (stage_v_39_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_39_2 << 1) & 127;
  int stage_v_40_1 = (st_var_1_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_1_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 42) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 42) & 15;
  int stage_v_41_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_41_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= stage_v_41_1;
  chk_sum_2 ^= stage_v_41_2;
  int stage_v_42_1 = table_1[2];
  int stage_v_42_2 = table_2[2];
  table_1[2] = (table_1[3] + 85) & 63;
  table_2[2] = (table_2[3] + 85) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (st_var_2_1.buffer[0] ^ 47) & 3;
  int stage_v_44_2 = (st_var_2_2.buffer[0] ^ 47) & 3;
  switch (stage_v_44_1)
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

  switch (stage_v_44_2)
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

  int stage_v_45_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_45_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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

  switch (stage_v_48_2)
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

  int stage_v_49_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (54 & 31);
  int stage_v_49_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (54 & 31);
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= (stage_v_49_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_49_2 << 1) & 127;
  int stage_v_50_1 = (st_var_2_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_2_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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

  int stage_v_51_1 = ((st_var_0_1.buffer[0] * 2) + 160) & 63;
  int stage_v_51_2 = ((st_var_0_2.buffer[0] * 2) + 160) & 63;
  if (stage_v_51_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_51_1) - 5) & 255;
    if (stage_v_51_1 > 50)
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
  if (stage_v_51_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_51_2) - 5) & 255;
    if (stage_v_51_2 > 50)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 53) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 53) & 15;
  int stage_v_52_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_52_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= stage_v_52_1;
  chk_sum_2 ^= stage_v_52_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 54) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 54) & 15;
  int stage_v_53_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_53_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= stage_v_53_1;
  chk_sum_2 ^= stage_v_53_2;
  int stage_v_54_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_54_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_54_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_54_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_55_1 = ((stage_v_55_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_55_2 = ((stage_v_55_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((st_var_2_1.buffer[2] * 2) + 175) & 63;
  int stage_v_56_2 = ((st_var_2_2.buffer[2] * 2) + 175) & 63;
  if (stage_v_56_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_56_1) - 5) & 255;
    if (stage_v_56_1 > 33)
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
  if (stage_v_56_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_56_2) - 5) & 255;
    if (stage_v_56_2 > 33)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 59) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 59) & 15;
  int stage_v_58_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_58_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= stage_v_58_1;
  chk_sum_2 ^= stage_v_58_2;
  int stage_v_59_1 = ((((sec_r000454_5_1 * 3) + (sec_r000454_5_1 * 2)) - pub_r000454_14_1) + 28) & 127;
  int stage_v_59_2 = ((((sec_r000454_5_2 * 3) + (sec_r000454_5_2 * 2)) - pub_r000454_14_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_59_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_59_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((((sec_r000454_7_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_4_1) + 23) & 127;
  int stage_v_60_2 = ((((sec_r000454_7_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_60_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_60_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((((stage_v_59_1 * 3) + (sec_r000454_5_1 * 2)) - pub_r000454_16_1) + 26) & 127;
  int stage_v_61_2 = ((((stage_v_59_2 * 3) + (sec_r000454_5_2 * 2)) - pub_r000454_16_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_61_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_61_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((((stage_v_60_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_21_1) + 34) & 127;
  int stage_v_62_2 = ((((stage_v_60_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_21_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_62_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_62_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((((sec_r000454_13_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_11_1) + 27) & 127;
  int stage_v_63_2 = ((((sec_r000454_13_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_63_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_63_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((((stage_v_63_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_23_1) + 25) & 127;
  int stage_v_64_2 = ((((stage_v_63_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_23_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_64_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_64_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((((stage_v_59_1 * 3) + (sec_r000454_9_1 * 2)) - pub_r000454_6_1) + 6) & 127;
  int stage_v_65_2 = ((((stage_v_59_2 * 3) + (sec_r000454_9_2 * 2)) - pub_r000454_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_65_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_65_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((((sec_r000454_8_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_16_1) + 30) & 127;
  int stage_v_66_2 = ((((sec_r000454_8_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_16_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_66_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_66_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((((sec_r000454_15_1 * 3) + (sec_r000454_15_1 * 2)) - pub_r000454_16_1) + 12) & 127;
  int stage_v_67_2 = ((((sec_r000454_15_2 * 3) + (sec_r000454_15_2 * 2)) - pub_r000454_16_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_67_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_67_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((((stage_v_64_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_18_1) + 13) & 127;
  int stage_v_68_2 = ((((stage_v_64_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_18_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_68_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_68_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((((sec_r000454_8_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_3_1) + 26) & 127;
  int stage_v_69_2 = ((((sec_r000454_8_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_69_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_69_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((((stage_v_60_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_6_1) + 35) & 127;
  int stage_v_70_2 = ((((stage_v_60_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_6_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_70_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_70_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((((stage_v_64_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_9_1) + 29) & 127;
  int stage_v_71_2 = ((((stage_v_64_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_9_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_71_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_71_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((((stage_v_71_1 * 3) + (sec_r000454_11_1 * 2)) - pub_r000454_10_1) + 22) & 127;
  int stage_v_72_2 = ((((stage_v_71_2 * 3) + (sec_r000454_11_2 * 2)) - pub_r000454_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_72_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_72_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((((stage_v_71_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_11_1) + 20) & 127;
  int stage_v_73_2 = ((((stage_v_71_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_73_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_73_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((((stage_v_65_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_0_1) + 14) & 127;
  int stage_v_74_2 = ((((stage_v_65_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_74_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_74_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((((sec_r000454_5_1 * 3) + (sec_r000454_5_1 * 2)) - pub_r000454_15_1) + 16) & 127;
  int stage_v_75_2 = ((((sec_r000454_5_2 * 3) + (sec_r000454_5_2 * 2)) - pub_r000454_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_75_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_75_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((((sec_r000454_15_1 * 3) + (sec_r000454_15_1 * 2)) - pub_r000454_10_1) + 20) & 127;
  int stage_v_76_2 = ((((sec_r000454_15_2 * 3) + (sec_r000454_15_2 * 2)) - pub_r000454_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_76_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_76_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((((sec_r000454_6_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_11_1) + 17) & 127;
  int stage_v_77_2 = ((((sec_r000454_6_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_77_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_77_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((((sec_r000454_13_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_7_1) + 5) & 127;
  int stage_v_78_2 = ((((sec_r000454_13_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_78_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_78_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((((stage_v_75_1 * 3) + (sec_r000454_3_1 * 2)) - pub_r000454_13_1) + 33) & 127;
  int stage_v_79_2 = ((((stage_v_75_2 * 3) + (sec_r000454_3_2 * 2)) - pub_r000454_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_79_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_79_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((((sec_r000454_4_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_7_1) + 12) & 127;
  int stage_v_80_2 = ((((sec_r000454_4_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_80_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_80_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((((sec_r000454_10_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_18_1) + 18) & 127;
  int stage_v_81_2 = ((((sec_r000454_10_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_18_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_81_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_81_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((((stage_v_64_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_12_1) + 10) & 127;
  int stage_v_82_2 = ((((stage_v_64_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_12_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_82_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_82_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((((sec_r000454_8_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_9_1) + 28) & 127;
  int stage_v_83_2 = ((((sec_r000454_8_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((((sec_r000454_5_1 * 3) + (sec_r000454_5_1 * 2)) - pub_r000454_21_1) + 4) & 127;
  int stage_v_84_2 = ((((sec_r000454_5_2 * 3) + (sec_r000454_5_2 * 2)) - pub_r000454_21_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((((stage_v_83_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_13_1) + 29) & 127;
  int stage_v_85_2 = ((((stage_v_83_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_13_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((((sec_r000454_9_1 * 3) + (sec_r000454_9_1 * 2)) - pub_r000454_20_1) + 21) & 127;
  int stage_v_86_2 = ((((sec_r000454_9_2 * 3) + (sec_r000454_9_2 * 2)) - pub_r000454_20_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_86_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_86_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((((stage_v_85_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_15_1) + 30) & 127;
  int stage_v_87_2 = ((((stage_v_85_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((((stage_v_67_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_4_1) + 17) & 127;
  int stage_v_88_2 = ((((stage_v_67_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_4_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((((stage_v_65_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_2_1) + 15) & 127;
  int stage_v_89_2 = ((((stage_v_65_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((((stage_v_67_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_1_1) + 9) & 127;
  int stage_v_90_2 = ((((stage_v_67_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((((stage_v_70_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_12_1) + 11) & 127;
  int stage_v_91_2 = ((((stage_v_70_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_91_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_91_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((((stage_v_80_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_10_1) + 24) & 127;
  int stage_v_92_2 = ((((stage_v_80_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_92_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_92_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((((stage_v_85_1 * 3) + (sec_r000454_3_1 * 2)) - pub_r000454_18_1) + 20) & 127;
  int stage_v_93_2 = ((((stage_v_85_2 * 3) + (sec_r000454_3_2 * 2)) - pub_r000454_18_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_93_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_93_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((((stage_v_76_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_23_1) + 33) & 127;
  int stage_v_94_2 = ((((stage_v_76_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_23_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_94_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_94_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((((stage_v_90_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_6_1) + 11) & 127;
  int stage_v_95_2 = ((((stage_v_90_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((((sec_r000454_4_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_3_1) + 34) & 127;
  int stage_v_96_2 = ((((sec_r000454_4_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((((sec_r000454_16_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_22_1) + 19) & 127;
  int stage_v_97_2 = ((((sec_r000454_16_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_22_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_97_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_97_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((((stage_v_75_1 * 3) + (sec_r000454_9_1 * 2)) - pub_r000454_17_1) + 37) & 127;
  int stage_v_98_2 = ((((stage_v_75_2 * 3) + (sec_r000454_9_2 * 2)) - pub_r000454_17_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((((stage_v_65_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_4_1) + 15) & 127;
  int stage_v_99_2 = ((((stage_v_65_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_4_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_99_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_99_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((((stage_v_82_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_2_1) + 32) & 127;
  int stage_v_100_2 = ((((stage_v_82_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_100_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_100_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((((stage_v_95_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_6_1) + 27) & 127;
  int stage_v_101_2 = ((((stage_v_95_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_101_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_101_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((((sec_r000454_12_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_15_1) + 16) & 127;
  int stage_v_102_2 = ((((sec_r000454_12_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((((sec_r000454_9_1 * 3) + (sec_r000454_9_1 * 2)) - pub_r000454_1_1) + 36) & 127;
  int stage_v_103_2 = ((((sec_r000454_9_2 * 3) + (sec_r000454_9_2 * 2)) - pub_r000454_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_103_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_103_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((((stage_v_85_1 * 3) + (sec_r000454_5_1 * 2)) - pub_r000454_7_1) + 34) & 127;
  int stage_v_104_2 = ((((stage_v_85_2 * 3) + (sec_r000454_5_2 * 2)) - pub_r000454_7_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((((stage_v_65_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_13_1) + 3) & 127;
  int stage_v_105_2 = ((((stage_v_65_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_105_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_105_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((((sec_r000454_0_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_15_1) + 24) & 127;
  int stage_v_106_2 = ((((sec_r000454_0_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((((sec_r000454_16_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_17_1) + 17) & 127;
  int stage_v_107_2 = ((((sec_r000454_16_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_17_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_107_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_107_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((((stage_v_107_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_16_1) + 12) & 127;
  int stage_v_108_2 = ((((stage_v_107_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_16_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((((stage_v_83_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_19_1) + 15) & 127;
  int stage_v_109_2 = ((((stage_v_83_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_19_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((((sec_r000454_10_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_8_1) + 33) & 127;
  int stage_v_110_2 = ((((sec_r000454_10_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_110_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_110_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((((stage_v_91_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_22_1) + 10) & 127;
  int stage_v_111_2 = ((((stage_v_91_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_22_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((((stage_v_86_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_4_1) + 25) & 127;
  int stage_v_112_2 = ((((stage_v_86_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((((stage_v_107_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_5_1) + 36) & 127;
  int stage_v_113_2 = ((((stage_v_107_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_5_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((((stage_v_73_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_19_1) + 14) & 127;
  int stage_v_114_2 = ((((stage_v_73_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_19_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((((stage_v_60_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_5_1) + 20) & 127;
  int stage_v_115_2 = ((((stage_v_60_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_5_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((((stage_v_70_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_20_1) + 22) & 127;
  int stage_v_116_2 = ((((stage_v_70_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_20_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((((sec_r000454_16_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_14_1) + 5) & 127;
  int stage_v_117_2 = ((((sec_r000454_16_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((((sec_r000454_7_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_20_1) + 36) & 127;
  int stage_v_118_2 = ((((sec_r000454_7_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_20_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((((stage_v_88_1 * 3) + (sec_r000454_1_1 * 2)) - pub_r000454_11_1) + 31) & 127;
  int stage_v_119_2 = ((((stage_v_88_2 * 3) + (sec_r000454_1_2 * 2)) - pub_r000454_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((((stage_v_80_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_6_1) + 27) & 127;
  int stage_v_120_2 = ((((stage_v_80_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((((sec_r000454_7_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_3_1) + 13) & 127;
  int stage_v_121_2 = ((((sec_r000454_7_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((((stage_v_116_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_5_1) + 28) & 127;
  int stage_v_122_2 = ((((stage_v_116_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_5_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((((sec_r000454_2_1 * 3) + (sec_r000454_2_1 * 2)) - pub_r000454_7_1) + 13) & 127;
  int stage_v_123_2 = ((((sec_r000454_2_2 * 3) + (sec_r000454_2_2 * 2)) - pub_r000454_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((((stage_v_64_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_16_1) + 5) & 127;
  int stage_v_124_2 = ((((stage_v_64_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_16_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((((stage_v_67_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_2_1) + 6) & 127;
  int stage_v_125_2 = ((((stage_v_67_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((((sec_r000454_5_1 * 3) + (sec_r000454_5_1 * 2)) - pub_r000454_22_1) + 14) & 127;
  int stage_v_126_2 = ((((sec_r000454_5_2 * 3) + (sec_r000454_5_2 * 2)) - pub_r000454_22_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((((sec_r000454_11_1 * 3) + (sec_r000454_11_1 * 2)) - pub_r000454_1_1) + 36) & 127;
  int stage_v_127_2 = ((((sec_r000454_11_2 * 3) + (sec_r000454_11_2 * 2)) - pub_r000454_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((((stage_v_83_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_22_1) + 35) & 127;
  int stage_v_128_2 = ((((stage_v_83_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_22_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((((stage_v_84_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_23_1) + 11) & 127;
  int stage_v_129_2 = ((((stage_v_84_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_23_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((((sec_r000454_6_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_8_1) + 5) & 127;
  int stage_v_130_2 = ((((sec_r000454_6_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((((stage_v_90_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_3_1) + 35) & 127;
  int stage_v_131_2 = ((((stage_v_90_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_131_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_131_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((((sec_r000454_7_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_13_1) + 21) & 127;
  int stage_v_132_2 = ((((sec_r000454_7_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_13_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((((stage_v_74_1 * 3) + (sec_r000454_9_1 * 2)) - pub_r000454_1_1) + 11) & 127;
  int stage_v_133_2 = ((((stage_v_74_2 * 3) + (sec_r000454_9_2 * 2)) - pub_r000454_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((((sec_r000454_5_1 * 3) + (sec_r000454_5_1 * 2)) - pub_r000454_6_1) + 24) & 127;
  int stage_v_134_2 = ((((sec_r000454_5_2 * 3) + (sec_r000454_5_2 * 2)) - pub_r000454_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_134_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_134_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((((sec_r000454_0_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_22_1) + 25) & 127;
  int stage_v_135_2 = ((((sec_r000454_0_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_22_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_135_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_135_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((((sec_r000454_16_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_13_1) + 6) & 127;
  int stage_v_136_2 = ((((sec_r000454_16_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((((sec_r000454_10_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_10_1) + 19) & 127;
  int stage_v_137_2 = ((((sec_r000454_10_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_10_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((((stage_v_137_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_6_1) + 15) & 127;
  int stage_v_138_2 = ((((stage_v_137_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((((sec_r000454_10_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_14_1) + 20) & 127;
  int stage_v_139_2 = ((((sec_r000454_10_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_14_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((((sec_r000454_4_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_17_1) + 29) & 127;
  int stage_v_140_2 = ((((sec_r000454_4_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_17_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((((stage_v_113_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_19_1) + 11) & 127;
  int stage_v_141_2 = ((((stage_v_113_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_19_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((((sec_r000454_9_1 * 3) + (sec_r000454_9_1 * 2)) - pub_r000454_1_1) + 23) & 127;
  int stage_v_142_2 = ((((sec_r000454_9_2 * 3) + (sec_r000454_9_2 * 2)) - pub_r000454_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((((sec_r000454_8_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_19_1) + 21) & 127;
  int stage_v_143_2 = ((((sec_r000454_8_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_19_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((((stage_v_105_1 * 3) + (sec_r000454_1_1 * 2)) - pub_r000454_22_1) + 11) & 127;
  int stage_v_144_2 = ((((stage_v_105_2 * 3) + (sec_r000454_1_2 * 2)) - pub_r000454_22_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((((sec_r000454_8_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_18_1) + 21) & 127;
  int stage_v_145_2 = ((((sec_r000454_8_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_18_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((((stage_v_62_1 * 3) + (sec_r000454_2_1 * 2)) - pub_r000454_11_1) + 34) & 127;
  int stage_v_146_2 = ((((stage_v_62_2 * 3) + (sec_r000454_2_2 * 2)) - pub_r000454_11_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((((stage_v_70_1 * 3) + (sec_r000454_2_1 * 2)) - pub_r000454_16_1) + 15) & 127;
  int stage_v_147_2 = ((((stage_v_70_2 * 3) + (sec_r000454_2_2 * 2)) - pub_r000454_16_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((((sec_r000454_0_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_17_1) + 5) & 127;
  int stage_v_148_2 = ((((sec_r000454_0_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_17_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((((stage_v_135_1 * 3) + (sec_r000454_2_1 * 2)) - pub_r000454_12_1) + 8) & 127;
  int stage_v_149_2 = ((((stage_v_135_2 * 3) + (sec_r000454_2_2 * 2)) - pub_r000454_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((((sec_r000454_7_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_14_1) + 14) & 127;
  int stage_v_150_2 = ((((sec_r000454_7_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_14_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((((sec_r000454_4_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_12_1) + 25) & 127;
  int stage_v_151_2 = ((((sec_r000454_4_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((((stage_v_61_1 * 3) + (sec_r000454_5_1 * 2)) - pub_r000454_13_1) + 32) & 127;
  int stage_v_152_2 = ((((stage_v_61_2 * 3) + (sec_r000454_5_2 * 2)) - pub_r000454_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((((sec_r000454_6_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_20_1) + 14) & 127;
  int stage_v_153_2 = ((((sec_r000454_6_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_20_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((((stage_v_84_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_4_1) + 35) & 127;
  int stage_v_154_2 = ((((stage_v_84_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((((sec_r000454_14_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_21_1) + 14) & 127;
  int stage_v_155_2 = ((((sec_r000454_14_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_21_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((((sec_r000454_10_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_2_1) + 25) & 127;
  int stage_v_156_2 = ((((sec_r000454_10_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_2_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_156_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_156_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((((stage_v_135_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_8_1) + 30) & 127;
  int stage_v_157_2 = ((((stage_v_135_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((((stage_v_105_1 * 3) + (sec_r000454_3_1 * 2)) - pub_r000454_8_1) + 22) & 127;
  int stage_v_158_2 = ((((stage_v_105_2 * 3) + (sec_r000454_3_2 * 2)) - pub_r000454_8_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((((stage_v_72_1 * 3) + (sec_r000454_5_1 * 2)) - pub_r000454_4_1) + 35) & 127;
  int stage_v_159_2 = ((((stage_v_72_2 * 3) + (sec_r000454_5_2 * 2)) - pub_r000454_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((((stage_v_105_1 * 3) + (sec_r000454_11_1 * 2)) - pub_r000454_15_1) + 9) & 127;
  int stage_v_160_2 = ((((stage_v_105_2 * 3) + (sec_r000454_11_2 * 2)) - pub_r000454_15_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_160_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_160_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((((stage_v_139_1 * 3) + (sec_r000454_1_1 * 2)) - pub_r000454_0_1) + 12) & 127;
  int stage_v_161_2 = ((((stage_v_139_2 * 3) + (sec_r000454_1_2 * 2)) - pub_r000454_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((((stage_v_161_1 * 3) + (sec_r000454_11_1 * 2)) - pub_r000454_23_1) + 37) & 127;
  int stage_v_162_2 = ((((stage_v_161_2 * 3) + (sec_r000454_11_2 * 2)) - pub_r000454_23_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((((sec_r000454_0_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_13_1) + 9) & 127;
  int stage_v_163_2 = ((((sec_r000454_0_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((((sec_r000454_6_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_18_1) + 31) & 127;
  int stage_v_164_2 = ((((sec_r000454_6_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_18_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((((sec_r000454_6_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_7_1) + 32) & 127;
  int stage_v_165_2 = ((((sec_r000454_6_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((((stage_v_140_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_14_1) + 19) & 127;
  int stage_v_166_2 = ((((stage_v_140_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((((sec_r000454_8_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_15_1) + 12) & 127;
  int stage_v_167_2 = ((((sec_r000454_8_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((((stage_v_81_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_18_1) + 14) & 127;
  int stage_v_168_2 = ((((stage_v_81_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_18_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((((sec_r000454_8_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_6_1) + 12) & 127;
  int stage_v_169_2 = ((((sec_r000454_8_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((((sec_r000454_11_1 * 3) + (sec_r000454_11_1 * 2)) - pub_r000454_10_1) + 19) & 127;
  int stage_v_170_2 = ((((sec_r000454_11_2 * 3) + (sec_r000454_11_2 * 2)) - pub_r000454_10_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((((sec_r000454_0_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_0_1) + 25) & 127;
  int stage_v_171_2 = ((((sec_r000454_0_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((((sec_r000454_2_1 * 3) + (sec_r000454_2_1 * 2)) - pub_r000454_12_1) + 37) & 127;
  int stage_v_172_2 = ((((sec_r000454_2_2 * 3) + (sec_r000454_2_2 * 2)) - pub_r000454_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((((stage_v_97_1 * 3) + (sec_r000454_15_1 * 2)) - pub_r000454_16_1) + 19) & 127;
  int stage_v_173_2 = ((((stage_v_97_2 * 3) + (sec_r000454_15_2 * 2)) - pub_r000454_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((((sec_r000454_0_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_15_1) + 25) & 127;
  int stage_v_174_2 = ((((sec_r000454_0_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_174_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_174_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((((stage_v_78_1 * 3) + (sec_r000454_11_1 * 2)) - pub_r000454_10_1) + 11) & 127;
  int stage_v_175_2 = ((((stage_v_78_2 * 3) + (sec_r000454_11_2 * 2)) - pub_r000454_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_175_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_175_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((((stage_v_134_1 * 3) + (sec_r000454_1_1 * 2)) - pub_r000454_17_1) + 12) & 127;
  int stage_v_176_2 = ((((stage_v_134_2 * 3) + (sec_r000454_1_2 * 2)) - pub_r000454_17_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_176_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_176_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((((stage_v_77_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_2_1) + 27) & 127;
  int stage_v_177_2 = ((((stage_v_77_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_177_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_177_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((((stage_v_122_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_14_1) + 29) & 127;
  int stage_v_178_2 = ((((stage_v_122_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_178_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_178_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((((stage_v_104_1 * 3) + (sec_r000454_3_1 * 2)) - pub_r000454_16_1) + 33) & 127;
  int stage_v_179_2 = ((((stage_v_104_2 * 3) + (sec_r000454_3_2 * 2)) - pub_r000454_16_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((((sec_r000454_15_1 * 3) + (sec_r000454_15_1 * 2)) - pub_r000454_11_1) + 37) & 127;
  int stage_v_180_2 = ((((sec_r000454_15_2 * 3) + (sec_r000454_15_2 * 2)) - pub_r000454_11_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_180_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_180_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((((stage_v_164_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_4_1) + 34) & 127;
  int stage_v_181_2 = ((((stage_v_164_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_181_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_181_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((((stage_v_90_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_0_1) + 4) & 127;
  int stage_v_182_2 = ((((stage_v_90_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_182_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_182_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((((stage_v_112_1 * 3) + (sec_r000454_5_1 * 2)) - pub_r000454_19_1) + 18) & 127;
  int stage_v_183_2 = ((((stage_v_112_2 * 3) + (sec_r000454_5_2 * 2)) - pub_r000454_19_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((((stage_v_135_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_4_1) + 31) & 127;
  int stage_v_184_2 = ((((stage_v_135_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_184_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_184_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((((stage_v_158_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_5_1) + 35) & 127;
  int stage_v_185_2 = ((((stage_v_158_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_185_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_185_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((((stage_v_135_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_6_1) + 26) & 127;
  int stage_v_186_2 = ((((stage_v_135_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_186_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_186_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((((stage_v_169_1 * 3) + (sec_r000454_3_1 * 2)) - pub_r000454_18_1) + 12) & 127;
  int stage_v_187_2 = ((((stage_v_169_2 * 3) + (sec_r000454_3_2 * 2)) - pub_r000454_18_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_187_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_187_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((((sec_r000454_16_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_13_1) + 12) & 127;
  int stage_v_188_2 = ((((sec_r000454_16_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_188_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_188_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((((stage_v_81_1 * 3) + (sec_r000454_5_1 * 2)) - pub_r000454_18_1) + 17) & 127;
  int stage_v_189_2 = ((((stage_v_81_2 * 3) + (sec_r000454_5_2 * 2)) - pub_r000454_18_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_189_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_189_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((((sec_r000454_2_1 * 3) + (sec_r000454_2_1 * 2)) - pub_r000454_3_1) + 34) & 127;
  int stage_v_190_2 = ((((sec_r000454_2_2 * 3) + (sec_r000454_2_2 * 2)) - pub_r000454_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_190_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_190_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((((sec_r000454_8_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_22_1) + 36) & 127;
  int stage_v_191_2 = ((((sec_r000454_8_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_22_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((((stage_v_140_1 * 3) + (sec_r000454_1_1 * 2)) - pub_r000454_11_1) + 15) & 127;
  int stage_v_192_2 = ((((stage_v_140_2 * 3) + (sec_r000454_1_2 * 2)) - pub_r000454_11_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_192_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_192_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((((sec_r000454_11_1 * 3) + (sec_r000454_11_1 * 2)) - pub_r000454_6_1) + 5) & 127;
  int stage_v_193_2 = ((((sec_r000454_11_2 * 3) + (sec_r000454_11_2 * 2)) - pub_r000454_6_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_193_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_193_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((((stage_v_180_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_3_1) + 25) & 127;
  int stage_v_194_2 = ((((stage_v_180_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_194_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_194_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((((sec_r000454_2_1 * 3) + (sec_r000454_2_1 * 2)) - pub_r000454_14_1) + 35) & 127;
  int stage_v_195_2 = ((((sec_r000454_2_2 * 3) + (sec_r000454_2_2 * 2)) - pub_r000454_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_195_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_195_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((((stage_v_185_1 * 3) + (sec_r000454_9_1 * 2)) - pub_r000454_13_1) + 31) & 127;
  int stage_v_196_2 = ((((stage_v_185_2 * 3) + (sec_r000454_9_2 * 2)) - pub_r000454_13_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_196_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_196_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((((stage_v_119_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_11_1) + 5) & 127;
  int stage_v_197_2 = ((((stage_v_119_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_11_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_197_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_197_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((((stage_v_132_1 * 3) + (sec_r000454_2_1 * 2)) - pub_r000454_22_1) + 16) & 127;
  int stage_v_198_2 = ((((stage_v_132_2 * 3) + (sec_r000454_2_2 * 2)) - pub_r000454_22_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_198_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_198_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((((sec_r000454_1_1 * 3) + (sec_r000454_1_1 * 2)) - pub_r000454_17_1) + 11) & 127;
  int stage_v_199_2 = ((((sec_r000454_1_2 * 3) + (sec_r000454_1_2 * 2)) - pub_r000454_17_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_199_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_199_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((((stage_v_70_1 * 3) + (sec_r000454_15_1 * 2)) - pub_r000454_7_1) + 32) & 127;
  int stage_v_200_2 = ((((stage_v_70_2 * 3) + (sec_r000454_15_2 * 2)) - pub_r000454_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_200_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_200_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((((stage_v_86_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_20_1) + 21) & 127;
  int stage_v_201_2 = ((((stage_v_86_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_20_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_201_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_201_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((((stage_v_91_1 * 3) + (sec_r000454_3_1 * 2)) - pub_r000454_14_1) + 26) & 127;
  int stage_v_202_2 = ((((stage_v_91_2 * 3) + (sec_r000454_3_2 * 2)) - pub_r000454_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_202_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_202_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((((sec_r000454_15_1 * 3) + (sec_r000454_15_1 * 2)) - pub_r000454_4_1) + 11) & 127;
  int stage_v_203_2 = ((((sec_r000454_15_2 * 3) + (sec_r000454_15_2 * 2)) - pub_r000454_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_203_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_203_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((((stage_v_120_1 * 3) + (sec_r000454_1_1 * 2)) - pub_r000454_9_1) + 10) & 127;
  int stage_v_204_2 = ((((stage_v_120_2 * 3) + (sec_r000454_1_2 * 2)) - pub_r000454_9_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_204_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_204_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((((sec_r000454_0_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_4_1) + 16) & 127;
  int stage_v_205_2 = ((((sec_r000454_0_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_205_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_205_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((((stage_v_59_1 * 3) + (sec_r000454_15_1 * 2)) - pub_r000454_16_1) + 37) & 127;
  int stage_v_206_2 = ((((stage_v_59_2 * 3) + (sec_r000454_15_2 * 2)) - pub_r000454_16_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_206_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_206_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((((stage_v_195_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_14_1) + 19) & 127;
  int stage_v_207_2 = ((((stage_v_195_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_207_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_207_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((((stage_v_62_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_22_1) + 20) & 127;
  int stage_v_208_2 = ((((stage_v_62_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_22_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_208_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_208_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((((stage_v_160_1 * 3) + (sec_r000454_11_1 * 2)) - pub_r000454_5_1) + 37) & 127;
  int stage_v_209_2 = ((((stage_v_160_2 * 3) + (sec_r000454_11_2 * 2)) - pub_r000454_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_209_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_209_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((((sec_r000454_4_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_0_1) + 24) & 127;
  int stage_v_210_2 = ((((sec_r000454_4_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_0_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_210_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_210_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((((stage_v_131_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_5_1) + 25) & 127;
  int stage_v_211_2 = ((((stage_v_131_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_5_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_211_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_211_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((((stage_v_83_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_18_1) + 6) & 127;
  int stage_v_212_2 = ((((stage_v_83_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_18_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_212_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_212_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((((sec_r000454_7_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_23_1) + 6) & 127;
  int stage_v_213_2 = ((((sec_r000454_7_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_23_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_213_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_213_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((((stage_v_169_1 * 3) + (sec_r000454_11_1 * 2)) - pub_r000454_11_1) + 4) & 127;
  int stage_v_214_2 = ((((stage_v_169_2 * 3) + (sec_r000454_11_2 * 2)) - pub_r000454_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_214_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_214_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((((stage_v_156_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_9_1) + 13) & 127;
  int stage_v_215_2 = ((((stage_v_156_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_9_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_215_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_215_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((((stage_v_182_1 * 3) + (sec_r000454_5_1 * 2)) - pub_r000454_16_1) + 4) & 127;
  int stage_v_216_2 = ((((stage_v_182_2 * 3) + (sec_r000454_5_2 * 2)) - pub_r000454_16_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_216_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_216_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((((sec_r000454_6_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_11_1) + 11) & 127;
  int stage_v_217_2 = ((((sec_r000454_6_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_217_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_217_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((((sec_r000454_10_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_8_1) + 30) & 127;
  int stage_v_218_2 = ((((sec_r000454_10_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_218_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_218_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((((stage_v_74_1 * 3) + (sec_r000454_3_1 * 2)) - pub_r000454_13_1) + 35) & 127;
  int stage_v_219_2 = ((((stage_v_74_2 * 3) + (sec_r000454_3_2 * 2)) - pub_r000454_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_219_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_219_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((((sec_r000454_13_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_2_1) + 5) & 127;
  int stage_v_220_2 = ((((sec_r000454_13_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_220_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_220_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((((stage_v_206_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_10_1) + 5) & 127;
  int stage_v_221_2 = ((((stage_v_206_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_221_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_221_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((((stage_v_90_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_21_1) + 6) & 127;
  int stage_v_222_2 = ((((stage_v_90_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_21_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_222_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_222_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((((stage_v_136_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_17_1) + 10) & 127;
  int stage_v_223_2 = ((((stage_v_136_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_17_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_223_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_223_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((((sec_r000454_2_1 * 3) + (sec_r000454_2_1 * 2)) - pub_r000454_7_1) + 5) & 127;
  int stage_v_224_2 = ((((sec_r000454_2_2 * 3) + (sec_r000454_2_2 * 2)) - pub_r000454_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_224_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_224_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((((sec_r000454_9_1 * 3) + (sec_r000454_9_1 * 2)) - pub_r000454_19_1) + 33) & 127;
  int stage_v_225_2 = ((((sec_r000454_9_2 * 3) + (sec_r000454_9_2 * 2)) - pub_r000454_19_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_225_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_225_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((((sec_r000454_5_1 * 3) + (sec_r000454_5_1 * 2)) - pub_r000454_20_1) + 12) & 127;
  int stage_v_226_2 = ((((sec_r000454_5_2 * 3) + (sec_r000454_5_2 * 2)) - pub_r000454_20_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_226_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_226_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((((stage_v_154_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_1_1) + 25) & 127;
  int stage_v_227_2 = ((((stage_v_154_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_1_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_227_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_227_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((((sec_r000454_14_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_6_1) + 12) & 127;
  int stage_v_228_2 = ((((sec_r000454_14_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_228_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_228_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((((stage_v_209_1 * 3) + (sec_r000454_3_1 * 2)) - pub_r000454_18_1) + 14) & 127;
  int stage_v_229_2 = ((((stage_v_209_2 * 3) + (sec_r000454_3_2 * 2)) - pub_r000454_18_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_229_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_229_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((((stage_v_192_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_4_1) + 17) & 127;
  int stage_v_230_2 = ((((stage_v_192_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_4_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_230_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_230_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((((sec_r000454_11_1 * 3) + (sec_r000454_11_1 * 2)) - pub_r000454_16_1) + 12) & 127;
  int stage_v_231_2 = ((((sec_r000454_11_2 * 3) + (sec_r000454_11_2 * 2)) - pub_r000454_16_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_231_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_231_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((((stage_v_229_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_23_1) + 31) & 127;
  int stage_v_232_2 = ((((stage_v_229_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_23_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_232_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_232_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((((stage_v_195_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_8_1) + 35) & 127;
  int stage_v_233_2 = ((((stage_v_195_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_233_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_233_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((((stage_v_227_1 * 3) + (sec_r000454_2_1 * 2)) - pub_r000454_23_1) + 32) & 127;
  int stage_v_234_2 = ((((stage_v_227_2 * 3) + (sec_r000454_2_2 * 2)) - pub_r000454_23_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_234_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_234_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((((stage_v_190_1 * 3) + (sec_r000454_3_1 * 2)) - pub_r000454_23_1) + 29) & 127;
  int stage_v_235_2 = ((((stage_v_190_2 * 3) + (sec_r000454_3_2 * 2)) - pub_r000454_23_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_235_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_235_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((((sec_r000454_10_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_23_1) + 20) & 127;
  int stage_v_236_2 = ((((sec_r000454_10_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_23_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_236_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_236_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((((stage_v_113_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_15_1) + 37) & 127;
  int stage_v_237_2 = ((((stage_v_113_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_237_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_237_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((((sec_r000454_16_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_11_1) + 16) & 127;
  int stage_v_238_2 = ((((sec_r000454_16_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_11_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_238_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_238_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((((stage_v_169_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_5_1) + 17) & 127;
  int stage_v_239_2 = ((((stage_v_169_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_239_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_239_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((((sec_r000454_12_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_16_1) + 8) & 127;
  int stage_v_240_2 = ((((sec_r000454_12_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_240_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_240_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((((stage_v_211_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_23_1) + 25) & 127;
  int stage_v_241_2 = ((((stage_v_211_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_23_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_241_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_241_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((((sec_r000454_8_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_11_1) + 37) & 127;
  int stage_v_242_2 = ((((sec_r000454_8_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_11_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_242_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_242_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((((stage_v_220_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_23_1) + 5) & 127;
  int stage_v_243_2 = ((((stage_v_220_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_23_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_243_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_243_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((((stage_v_200_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_19_1) + 25) & 127;
  int stage_v_244_2 = ((((stage_v_200_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_19_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_244_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_244_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((((stage_v_150_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_17_1) + 22) & 127;
  int stage_v_245_2 = ((((stage_v_150_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_17_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_245_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_245_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((((stage_v_150_1 * 3) + (sec_r000454_15_1 * 2)) - pub_r000454_0_1) + 12) & 127;
  int stage_v_246_2 = ((((stage_v_150_2 * 3) + (sec_r000454_15_2 * 2)) - pub_r000454_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_246_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_246_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((((stage_v_80_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_5_1) + 36) & 127;
  int stage_v_247_2 = ((((stage_v_80_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_5_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_247_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_247_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((((stage_v_173_1 * 3) + (sec_r000454_15_1 * 2)) - pub_r000454_11_1) + 12) & 127;
  int stage_v_248_2 = ((((stage_v_173_2 * 3) + (sec_r000454_15_2 * 2)) - pub_r000454_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_248_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_248_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((((stage_v_64_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_7_1) + 10) & 127;
  int stage_v_249_2 = ((((stage_v_64_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_7_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_249_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_249_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((((stage_v_61_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_7_1) + 29) & 127;
  int stage_v_250_2 = ((((stage_v_61_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_7_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_250_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_250_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((((stage_v_182_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_12_1) + 7) & 127;
  int stage_v_251_2 = ((((stage_v_182_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_251_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_251_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((((stage_v_130_1 * 3) + (sec_r000454_1_1 * 2)) - pub_r000454_23_1) + 32) & 127;
  int stage_v_252_2 = ((((stage_v_130_2 * 3) + (sec_r000454_1_2 * 2)) - pub_r000454_23_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_252_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_252_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((((stage_v_131_1 * 3) + (sec_r000454_1_1 * 2)) - pub_r000454_23_1) + 7) & 127;
  int stage_v_253_2 = ((((stage_v_131_2 * 3) + (sec_r000454_1_2 * 2)) - pub_r000454_23_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_253_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_253_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((((stage_v_219_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_19_1) + 27) & 127;
  int stage_v_254_2 = ((((stage_v_219_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_19_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_254_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_254_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((((stage_v_116_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_7_1) + 8) & 127;
  int stage_v_255_2 = ((((stage_v_116_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_255_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_255_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((((stage_v_83_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_14_1) + 4) & 127;
  int stage_v_256_2 = ((((stage_v_83_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_256_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_256_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((((sec_r000454_13_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_10_1) + 8) & 127;
  int stage_v_257_2 = ((((sec_r000454_13_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_10_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_257_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_257_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((((stage_v_71_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_23_1) + 15) & 127;
  int stage_v_258_2 = ((((stage_v_71_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_23_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_258_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_258_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((((stage_v_134_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_19_1) + 19) & 127;
  int stage_v_259_2 = ((((stage_v_134_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_19_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_259_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_259_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((((stage_v_116_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_3_1) + 17) & 127;
  int stage_v_260_2 = ((((stage_v_116_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_260_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_260_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((((sec_r000454_16_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_13_1) + 11) & 127;
  int stage_v_261_2 = ((((sec_r000454_16_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_261_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_261_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((((stage_v_167_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_22_1) + 24) & 127;
  int stage_v_262_2 = ((((stage_v_167_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_22_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_262_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_262_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((((sec_r000454_12_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_19_1) + 31) & 127;
  int stage_v_263_2 = ((((sec_r000454_12_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_19_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_263_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_263_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((((stage_v_184_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_12_1) + 35) & 127;
  int stage_v_264_2 = ((((stage_v_184_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_12_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_264_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_264_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((((stage_v_165_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_16_1) + 36) & 127;
  int stage_v_265_2 = ((((stage_v_165_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_16_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_265_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_265_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((((sec_r000454_6_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_0_1) + 9) & 127;
  int stage_v_266_2 = ((((sec_r000454_6_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_0_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_266_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_266_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((((sec_r000454_9_1 * 3) + (sec_r000454_9_1 * 2)) - pub_r000454_3_1) + 22) & 127;
  int stage_v_267_2 = ((((sec_r000454_9_2 * 3) + (sec_r000454_9_2 * 2)) - pub_r000454_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_267_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_267_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((((stage_v_165_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_18_1) + 31) & 127;
  int stage_v_268_2 = ((((stage_v_165_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_18_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_268_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_268_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((((stage_v_97_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_14_1) + 30) & 127;
  int stage_v_269_2 = ((((stage_v_97_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_269_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_269_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((((stage_v_101_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_6_1) + 36) & 127;
  int stage_v_270_2 = ((((stage_v_101_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_270_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_270_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((((stage_v_259_1 * 3) + (sec_r000454_3_1 * 2)) - pub_r000454_15_1) + 28) & 127;
  int stage_v_271_2 = ((((stage_v_259_2 * 3) + (sec_r000454_3_2 * 2)) - pub_r000454_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_271_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_271_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((((stage_v_181_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_18_1) + 13) & 127;
  int stage_v_272_2 = ((((stage_v_181_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_18_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_272_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_272_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((((sec_r000454_2_1 * 3) + (sec_r000454_2_1 * 2)) - pub_r000454_19_1) + 17) & 127;
  int stage_v_273_2 = ((((sec_r000454_2_2 * 3) + (sec_r000454_2_2 * 2)) - pub_r000454_19_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_273_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_273_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((((sec_r000454_5_1 * 3) + (sec_r000454_5_1 * 2)) - pub_r000454_20_1) + 9) & 127;
  int stage_v_274_2 = ((((sec_r000454_5_2 * 3) + (sec_r000454_5_2 * 2)) - pub_r000454_20_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_274_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_274_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((((stage_v_165_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_2_1) + 7) & 127;
  int stage_v_275_2 = ((((stage_v_165_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_2_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_275_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_275_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((((stage_v_68_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_14_1) + 30) & 127;
  int stage_v_276_2 = ((((stage_v_68_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_276_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_276_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((((stage_v_236_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_8_1) + 9) & 127;
  int stage_v_277_2 = ((((stage_v_236_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_8_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_277_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_277_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((((sec_r000454_6_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_14_1) + 36) & 127;
  int stage_v_278_2 = ((((sec_r000454_6_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_278_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_278_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((((stage_v_69_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_15_1) + 35) & 127;
  int stage_v_279_2 = ((((stage_v_69_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_279_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_279_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((((stage_v_114_1 * 3) + (sec_r000454_3_1 * 2)) - pub_r000454_13_1) + 14) & 127;
  int stage_v_280_2 = ((((stage_v_114_2 * 3) + (sec_r000454_3_2 * 2)) - pub_r000454_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_280_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_280_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((((stage_v_65_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_2_1) + 12) & 127;
  int stage_v_281_2 = ((((stage_v_65_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_2_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_281_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_281_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((((sec_r000454_13_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_2_1) + 6) & 127;
  int stage_v_282_2 = ((((sec_r000454_13_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_282_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_282_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((((stage_v_121_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_1_1) + 11) & 127;
  int stage_v_283_2 = ((((stage_v_121_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_283_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_283_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((((stage_v_115_1 * 3) + (sec_r000454_9_1 * 2)) - pub_r000454_12_1) + 33) & 127;
  int stage_v_284_2 = ((((stage_v_115_2 * 3) + (sec_r000454_9_2 * 2)) - pub_r000454_12_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_284_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_284_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((((sec_r000454_10_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_9_1) + 11) & 127;
  int stage_v_285_2 = ((((sec_r000454_10_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_285_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_285_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((((stage_v_221_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_22_1) + 35) & 127;
  int stage_v_286_2 = ((((stage_v_221_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_22_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_286_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_286_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((((stage_v_272_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_2_1) + 29) & 127;
  int stage_v_287_2 = ((((stage_v_272_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_2_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_287_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_287_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((((stage_v_157_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_11_1) + 10) & 127;
  int stage_v_288_2 = ((((stage_v_157_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_288_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_288_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((((stage_v_143_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_16_1) + 22) & 127;
  int stage_v_289_2 = ((((stage_v_143_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_289_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_289_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((((stage_v_289_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_22_1) + 20) & 127;
  int stage_v_290_2 = ((((stage_v_289_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_22_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_290_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_290_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((((stage_v_215_1 * 3) + (sec_r000454_9_1 * 2)) - pub_r000454_17_1) + 19) & 127;
  int stage_v_291_2 = ((((stage_v_215_2 * 3) + (sec_r000454_9_2 * 2)) - pub_r000454_17_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_291_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_291_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((((stage_v_122_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_21_1) + 16) & 127;
  int stage_v_292_2 = ((((stage_v_122_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_21_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_292_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_292_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((((stage_v_225_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_23_1) + 21) & 127;
  int stage_v_293_2 = ((((stage_v_225_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_23_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_293_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_293_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((((sec_r000454_4_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_10_1) + 29) & 127;
  int stage_v_294_2 = ((((sec_r000454_4_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_10_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_294_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_294_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((((sec_r000454_7_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_22_1) + 27) & 127;
  int stage_v_295_2 = ((((sec_r000454_7_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_22_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_295_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_295_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((((stage_v_69_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_16_1) + 6) & 127;
  int stage_v_296_2 = ((((stage_v_69_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_296_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_296_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((((sec_r000454_4_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_5_1) + 4) & 127;
  int stage_v_297_2 = ((((sec_r000454_4_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_297_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_297_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int stage_v_298_1 = ((((stage_v_246_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_23_1) + 30) & 127;
  int stage_v_298_2 = ((((stage_v_246_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_23_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_298_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_298_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int stage_v_299_1 = ((((stage_v_87_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_22_1) + 4) & 127;
  int stage_v_299_2 = ((((stage_v_87_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_22_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_299_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_299_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int stage_v_300_1 = ((((stage_v_91_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_22_1) + 29) & 127;
  int stage_v_300_2 = ((((stage_v_91_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_22_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_300_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_300_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int stage_v_301_1 = ((((stage_v_59_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_15_1) + 8) & 127;
  int stage_v_301_2 = ((((stage_v_59_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_301_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_301_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int stage_v_302_1 = ((((stage_v_257_1 * 3) + (sec_r000454_9_1 * 2)) - pub_r000454_15_1) + 34) & 127;
  int stage_v_302_2 = ((((stage_v_257_2 * 3) + (sec_r000454_9_2 * 2)) - pub_r000454_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_302_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_302_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int stage_v_303_1 = ((((stage_v_158_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_8_1) + 30) & 127;
  int stage_v_303_2 = ((((stage_v_158_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_303_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_303_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int stage_v_304_1 = ((((sec_r000454_12_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_2_1) + 25) & 127;
  int stage_v_304_2 = ((((sec_r000454_12_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_2_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_304_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_304_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int stage_v_305_1 = ((((stage_v_260_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_6_1) + 34) & 127;
  int stage_v_305_2 = ((((stage_v_260_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_305_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_305_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  int stage_v_306_1 = ((((stage_v_221_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_20_1) + 17) & 127;
  int stage_v_306_2 = ((((stage_v_221_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_20_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_306_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_306_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_306_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_306_2) & 255;
  int stage_v_307_1 = ((((sec_r000454_0_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_6_1) + 19) & 127;
  int stage_v_307_2 = ((((sec_r000454_0_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_307_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_307_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_307_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_307_2) & 255;
  int stage_v_308_1 = ((((stage_v_118_1 * 3) + (sec_r000454_11_1 * 2)) - pub_r000454_22_1) + 8) & 127;
  int stage_v_308_2 = ((((stage_v_118_2 * 3) + (sec_r000454_11_2 * 2)) - pub_r000454_22_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_308_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_308_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_308_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_308_2) & 255;
  int stage_v_309_1 = ((((sec_r000454_10_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_13_1) + 34) & 127;
  int stage_v_309_2 = ((((sec_r000454_10_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_309_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_309_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_309_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_309_2) & 255;
  int stage_v_310_1 = ((((stage_v_185_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_23_1) + 21) & 127;
  int stage_v_310_2 = ((((stage_v_185_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_23_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_310_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_310_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_310_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_310_2) & 255;
  int stage_v_311_1 = ((((stage_v_224_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_9_1) + 4) & 127;
  int stage_v_311_2 = ((((stage_v_224_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_9_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_311_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_311_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_311_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_311_2) & 255;
  int stage_v_312_1 = ((((stage_v_101_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_12_1) + 7) & 127;
  int stage_v_312_2 = ((((stage_v_101_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_312_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_312_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_312_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_312_2) & 255;
  int stage_v_313_1 = ((((sec_r000454_3_1 * 3) + (sec_r000454_3_1 * 2)) - pub_r000454_5_1) + 18) & 127;
  int stage_v_313_2 = ((((sec_r000454_3_2 * 3) + (sec_r000454_3_2 * 2)) - pub_r000454_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_313_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_313_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_313_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_313_2) & 255;
  int stage_v_314_1 = ((((sec_r000454_0_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_4_1) + 21) & 127;
  int stage_v_314_2 = ((((sec_r000454_0_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_314_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_314_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_314_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_314_2) & 255;
  int stage_v_315_1 = ((((stage_v_295_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_23_1) + 17) & 127;
  int stage_v_315_2 = ((((stage_v_295_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_23_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_315_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_315_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_315_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_315_2) & 255;
  int stage_v_316_1 = ((((stage_v_113_1 * 3) + (sec_r000454_11_1 * 2)) - pub_r000454_13_1) + 35) & 127;
  int stage_v_316_2 = ((((stage_v_113_2 * 3) + (sec_r000454_11_2 * 2)) - pub_r000454_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_316_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_316_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_316_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_316_2) & 255;
  int stage_v_317_1 = ((((stage_v_120_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_17_1) + 36) & 127;
  int stage_v_317_2 = ((((stage_v_120_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_17_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_317_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_317_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_317_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_317_2) & 255;
  int stage_v_318_1 = ((((sec_r000454_7_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_21_1) + 28) & 127;
  int stage_v_318_2 = ((((sec_r000454_7_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_21_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_318_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_318_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_318_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_318_2) & 255;
  int stage_v_319_1 = ((((stage_v_304_1 * 3) + (sec_r000454_3_1 * 2)) - pub_r000454_15_1) + 16) & 127;
  int stage_v_319_2 = ((((stage_v_304_2 * 3) + (sec_r000454_3_2 * 2)) - pub_r000454_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_319_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_319_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_319_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_319_2) & 255;
  int stage_v_320_1 = ((((stage_v_182_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_18_1) + 21) & 127;
  int stage_v_320_2 = ((((stage_v_182_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_18_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_320_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_320_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_320_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_320_2) & 255;
  int stage_v_321_1 = ((((stage_v_195_1 * 3) + (sec_r000454_3_1 * 2)) - pub_r000454_9_1) + 13) & 127;
  int stage_v_321_2 = ((((stage_v_195_2 * 3) + (sec_r000454_3_2 * 2)) - pub_r000454_9_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_321_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_321_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_321_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_321_2) & 255;
  int stage_v_322_1 = ((((sec_r000454_10_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_12_1) + 31) & 127;
  int stage_v_322_2 = ((((sec_r000454_10_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_322_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_322_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_322_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_322_2) & 255;
  int stage_v_323_1 = ((((sec_r000454_2_1 * 3) + (sec_r000454_2_1 * 2)) - pub_r000454_11_1) + 13) & 127;
  int stage_v_323_2 = ((((sec_r000454_2_2 * 3) + (sec_r000454_2_2 * 2)) - pub_r000454_11_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_323_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_323_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_323_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_323_2) & 255;
  int stage_v_324_1 = ((((stage_v_299_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_10_1) + 5) & 127;
  int stage_v_324_2 = ((((stage_v_299_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_324_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_324_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_324_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_324_2) & 255;
  int stage_v_325_1 = ((((stage_v_78_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_13_1) + 36) & 127;
  int stage_v_325_2 = ((((stage_v_78_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_325_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_325_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_325_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_325_2) & 255;
  int stage_v_326_1 = ((((stage_v_205_1 * 3) + (sec_r000454_1_1 * 2)) - pub_r000454_16_1) + 16) & 127;
  int stage_v_326_2 = ((((stage_v_205_2 * 3) + (sec_r000454_1_2 * 2)) - pub_r000454_16_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_326_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_326_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_326_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_326_2) & 255;
  int stage_v_327_1 = ((((stage_v_113_1 * 3) + (sec_r000454_11_1 * 2)) - pub_r000454_2_1) + 3) & 127;
  int stage_v_327_2 = ((((stage_v_113_2 * 3) + (sec_r000454_11_2 * 2)) - pub_r000454_2_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_327_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_327_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_327_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_327_2) & 255;
  int stage_v_328_1 = ((((stage_v_288_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_10_1) + 24) & 127;
  int stage_v_328_2 = ((((stage_v_288_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_328_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_328_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_328_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_328_2) & 255;
  int stage_v_329_1 = ((((stage_v_104_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_9_1) + 13) & 127;
  int stage_v_329_2 = ((((stage_v_104_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_9_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_329_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_329_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_329_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_329_2) & 255;
  int stage_v_330_1 = ((((sec_r000454_14_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_0_1) + 4) & 127;
  int stage_v_330_2 = ((((sec_r000454_14_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_330_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_330_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_330_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_330_2) & 255;
  int stage_v_331_1 = ((((stage_v_73_1 * 3) + (sec_r000454_1_1 * 2)) - pub_r000454_17_1) + 35) & 127;
  int stage_v_331_2 = ((((stage_v_73_2 * 3) + (sec_r000454_1_2 * 2)) - pub_r000454_17_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_331_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_331_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_331_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_331_2) & 255;
  int stage_v_332_1 = ((((stage_v_71_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_1_1) + 15) & 127;
  int stage_v_332_2 = ((((stage_v_71_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_332_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_332_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_332_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_332_2) & 255;
  int stage_v_333_1 = ((((sec_r000454_16_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_21_1) + 12) & 127;
  int stage_v_333_2 = ((((sec_r000454_16_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_21_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_333_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_333_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_333_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_333_2) & 255;
  int stage_v_334_1 = ((((stage_v_158_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_6_1) + 22) & 127;
  int stage_v_334_2 = ((((stage_v_158_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_6_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_334_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_334_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_334_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_334_2) & 255;
  int stage_v_335_1 = ((((stage_v_188_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_21_1) + 12) & 127;
  int stage_v_335_2 = ((((stage_v_188_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_21_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_335_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_335_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_335_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_335_2) & 255;
  int stage_v_336_1 = ((((stage_v_297_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_7_1) + 5) & 127;
  int stage_v_336_2 = ((((stage_v_297_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_336_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_336_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_336_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_336_2) & 255;
  int stage_v_337_1 = ((((sec_r000454_9_1 * 3) + (sec_r000454_9_1 * 2)) - pub_r000454_17_1) + 14) & 127;
  int stage_v_337_2 = ((((sec_r000454_9_2 * 3) + (sec_r000454_9_2 * 2)) - pub_r000454_17_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_337_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_337_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_337_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_337_2) & 255;
  int stage_v_338_1 = ((((stage_v_80_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_14_1) + 11) & 127;
  int stage_v_338_2 = ((((stage_v_80_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_338_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_338_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_338_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_338_2) & 255;
  int stage_v_339_1 = ((((sec_r000454_10_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_3_1) + 3) & 127;
  int stage_v_339_2 = ((((sec_r000454_10_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_339_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_339_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_339_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_339_2) & 255;
  int stage_v_340_1 = ((((stage_v_273_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_5_1) + 5) & 127;
  int stage_v_340_2 = ((((stage_v_273_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_5_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_340_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_340_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_340_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_340_2) & 255;
  int stage_v_341_1 = ((((stage_v_324_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_10_1) + 29) & 127;
  int stage_v_341_2 = ((((stage_v_324_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_10_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_341_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_341_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_341_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_341_2) & 255;
  int stage_v_342_1 = ((((stage_v_298_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_0_1) + 37) & 127;
  int stage_v_342_2 = ((((stage_v_298_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_342_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_342_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_342_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_342_2) & 255;
  int stage_v_343_1 = ((((sec_r000454_16_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_2_1) + 25) & 127;
  int stage_v_343_2 = ((((sec_r000454_16_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_2_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_343_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_343_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_343_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_343_2) & 255;
  int stage_v_344_1 = ((((stage_v_103_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_4_1) + 18) & 127;
  int stage_v_344_2 = ((((stage_v_103_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_344_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_344_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_344_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_344_2) & 255;
  int stage_v_345_1 = ((((sec_r000454_12_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_7_1) + 19) & 127;
  int stage_v_345_2 = ((((sec_r000454_12_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_345_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_345_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_345_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_345_2) & 255;
  int stage_v_346_1 = ((((stage_v_133_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_6_1) + 9) & 127;
  int stage_v_346_2 = ((((stage_v_133_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_346_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_346_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_346_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_346_2) & 255;
  int stage_v_347_1 = ((((sec_r000454_3_1 * 3) + (sec_r000454_3_1 * 2)) - pub_r000454_13_1) + 11) & 127;
  int stage_v_347_2 = ((((sec_r000454_3_2 * 3) + (sec_r000454_3_2 * 2)) - pub_r000454_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_347_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_347_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_347_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_347_2) & 255;
  int stage_v_348_1 = ((((stage_v_155_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_16_1) + 26) & 127;
  int stage_v_348_2 = ((((stage_v_155_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_16_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_348_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_348_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_348_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_348_2) & 255;
  int stage_v_349_1 = ((((sec_r000454_12_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_11_1) + 9) & 127;
  int stage_v_349_2 = ((((sec_r000454_12_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_349_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_349_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_349_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_349_2) & 255;
  int stage_v_350_1 = ((((stage_v_205_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_15_1) + 5) & 127;
  int stage_v_350_2 = ((((stage_v_205_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_350_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_350_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_350_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_350_2) & 255;
  int stage_v_351_1 = ((((stage_v_185_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_5_1) + 13) & 127;
  int stage_v_351_2 = ((((stage_v_185_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_351_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_351_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_351_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_351_2) & 255;
  int stage_v_352_1 = ((((sec_r000454_3_1 * 3) + (sec_r000454_3_1 * 2)) - pub_r000454_15_1) + 29) & 127;
  int stage_v_352_2 = ((((sec_r000454_3_2 * 3) + (sec_r000454_3_2 * 2)) - pub_r000454_15_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_352_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_352_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_352_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_352_2) & 255;
  int stage_v_353_1 = ((((sec_r000454_14_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_5_1) + 10) & 127;
  int stage_v_353_2 = ((((sec_r000454_14_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_5_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_353_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_353_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_353_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_353_2) & 255;
  int stage_v_354_1 = ((((stage_v_128_1 * 3) + (sec_r000454_9_1 * 2)) - pub_r000454_5_1) + 33) & 127;
  int stage_v_354_2 = ((((stage_v_128_2 * 3) + (sec_r000454_9_2 * 2)) - pub_r000454_5_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_354_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_354_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_354_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_354_2) & 255;
  int stage_v_355_1 = ((((sec_r000454_7_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_2_1) + 10) & 127;
  int stage_v_355_2 = ((((sec_r000454_7_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_2_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_355_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_355_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_355_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_355_2) & 255;
  int stage_v_356_1 = ((((sec_r000454_8_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_8_1) + 32) & 127;
  int stage_v_356_2 = ((((sec_r000454_8_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_356_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_356_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_356_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_356_2) & 255;
  int stage_v_357_1 = ((((stage_v_347_1 * 3) + (sec_r000454_8_1 * 2)) - pub_r000454_6_1) + 34) & 127;
  int stage_v_357_2 = ((((stage_v_347_2 * 3) + (sec_r000454_8_2 * 2)) - pub_r000454_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_357_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_357_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_357_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_357_2) & 255;
  int stage_v_358_1 = ((((sec_r000454_6_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_21_1) + 30) & 127;
  int stage_v_358_2 = ((((sec_r000454_6_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_21_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_358_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_358_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_358_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_358_2) & 255;
  int stage_v_359_1 = ((((sec_r000454_1_1 * 3) + (sec_r000454_1_1 * 2)) - pub_r000454_7_1) + 4) & 127;
  int stage_v_359_2 = ((((sec_r000454_1_2 * 3) + (sec_r000454_1_2 * 2)) - pub_r000454_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_359_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_359_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_359_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_359_2) & 255;
  int stage_v_360_1 = ((((sec_r000454_7_1 * 3) + (sec_r000454_7_1 * 2)) - pub_r000454_1_1) + 26) & 127;
  int stage_v_360_2 = ((((sec_r000454_7_2 * 3) + (sec_r000454_7_2 * 2)) - pub_r000454_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_360_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_360_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_360_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_360_2) & 255;
  int stage_v_361_1 = ((((stage_v_341_1 * 3) + (sec_r000454_1_1 * 2)) - pub_r000454_6_1) + 20) & 127;
  int stage_v_361_2 = ((((stage_v_341_2 * 3) + (sec_r000454_1_2 * 2)) - pub_r000454_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_361_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_361_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_361_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_361_2) & 255;
  int stage_v_362_1 = ((((stage_v_318_1 * 3) + (sec_r000454_2_1 * 2)) - pub_r000454_1_1) + 11) & 127;
  int stage_v_362_2 = ((((stage_v_318_2 * 3) + (sec_r000454_2_2 * 2)) - pub_r000454_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_362_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_362_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_362_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_362_2) & 255;
  int stage_v_363_1 = ((((sec_r000454_14_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_15_1) + 18) & 127;
  int stage_v_363_2 = ((((sec_r000454_14_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_15_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_363_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_363_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_363_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_363_2) & 255;
  int stage_v_364_1 = ((((sec_r000454_10_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_22_1) + 33) & 127;
  int stage_v_364_2 = ((((sec_r000454_10_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_22_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_364_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_364_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_364_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_364_2) & 255;
  int stage_v_365_1 = ((((stage_v_236_1 * 3) + (sec_r000454_11_1 * 2)) - pub_r000454_8_1) + 28) & 127;
  int stage_v_365_2 = ((((stage_v_236_2 * 3) + (sec_r000454_11_2 * 2)) - pub_r000454_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_365_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_365_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_365_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_365_2) & 255;
  int stage_v_366_1 = ((((stage_v_314_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_4_1) + 36) & 127;
  int stage_v_366_2 = ((((stage_v_314_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_366_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_366_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_366_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_366_2) & 255;
  int stage_v_367_1 = ((((stage_v_170_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_21_1) + 26) & 127;
  int stage_v_367_2 = ((((stage_v_170_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_21_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_367_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_367_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_367_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_367_2) & 255;
  int stage_v_368_1 = ((((stage_v_327_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_3_1) + 8) & 127;
  int stage_v_368_2 = ((((stage_v_327_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_368_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_368_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_368_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_368_2) & 255;
  int stage_v_369_1 = ((((stage_v_80_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_18_1) + 27) & 127;
  int stage_v_369_2 = ((((stage_v_80_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_18_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_369_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_369_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_369_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_369_2) & 255;
  int stage_v_370_1 = ((((stage_v_181_1 * 3) + (sec_r000454_3_1 * 2)) - pub_r000454_15_1) + 35) & 127;
  int stage_v_370_2 = ((((stage_v_181_2 * 3) + (sec_r000454_3_2 * 2)) - pub_r000454_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_370_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_370_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_370_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_370_2) & 255;
  int stage_v_371_1 = ((((sec_r000454_5_1 * 3) + (sec_r000454_5_1 * 2)) - pub_r000454_6_1) + 18) & 127;
  int stage_v_371_2 = ((((sec_r000454_5_2 * 3) + (sec_r000454_5_2 * 2)) - pub_r000454_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_371_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_371_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_371_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_371_2) & 255;
  int stage_v_372_1 = ((((stage_v_310_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_22_1) + 17) & 127;
  int stage_v_372_2 = ((((stage_v_310_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_22_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_372_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_372_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_372_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_372_2) & 255;
  int stage_v_373_1 = ((((stage_v_171_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_19_1) + 8) & 127;
  int stage_v_373_2 = ((((stage_v_171_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_19_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_373_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_373_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_373_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_373_2) & 255;
  int stage_v_374_1 = ((((sec_r000454_9_1 * 3) + (sec_r000454_9_1 * 2)) - pub_r000454_6_1) + 17) & 127;
  int stage_v_374_2 = ((((sec_r000454_9_2 * 3) + (sec_r000454_9_2 * 2)) - pub_r000454_6_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_374_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_374_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_374_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_374_2) & 255;
  int stage_v_375_1 = ((((stage_v_75_1 * 3) + (sec_r000454_2_1 * 2)) - pub_r000454_6_1) + 8) & 127;
  int stage_v_375_2 = ((((stage_v_75_2 * 3) + (sec_r000454_2_2 * 2)) - pub_r000454_6_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_375_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_375_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_375_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_375_2) & 255;
  int stage_v_376_1 = ((((stage_v_319_1 * 3) + (sec_r000454_15_1 * 2)) - pub_r000454_10_1) + 17) & 127;
  int stage_v_376_2 = ((((stage_v_319_2 * 3) + (sec_r000454_15_2 * 2)) - pub_r000454_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_376_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_376_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_376_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_376_2) & 255;
  int stage_v_377_1 = ((((sec_r000454_2_1 * 3) + (sec_r000454_2_1 * 2)) - pub_r000454_1_1) + 6) & 127;
  int stage_v_377_2 = ((((sec_r000454_2_2 * 3) + (sec_r000454_2_2 * 2)) - pub_r000454_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_377_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_377_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_377_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_377_2) & 255;
  int stage_v_378_1 = ((((stage_v_133_1 * 3) + (sec_r000454_3_1 * 2)) - pub_r000454_11_1) + 3) & 127;
  int stage_v_378_2 = ((((stage_v_133_2 * 3) + (sec_r000454_3_2 * 2)) - pub_r000454_11_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_378_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_378_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_378_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_378_2) & 255;
  int stage_v_379_1 = ((((sec_r000454_13_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_12_1) + 11) & 127;
  int stage_v_379_2 = ((((sec_r000454_13_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_379_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_379_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_379_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_379_2) & 255;
  int stage_v_380_1 = ((((stage_v_218_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_3_1) + 6) & 127;
  int stage_v_380_2 = ((((stage_v_218_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_380_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_380_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_380_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_380_2) & 255;
  int stage_v_381_1 = ((((stage_v_109_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_10_1) + 36) & 127;
  int stage_v_381_2 = ((((stage_v_109_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_381_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_381_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_381_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_381_2) & 255;
  int stage_v_382_1 = ((((stage_v_374_1 * 3) + (sec_r000454_11_1 * 2)) - pub_r000454_13_1) + 8) & 127;
  int stage_v_382_2 = ((((stage_v_374_2 * 3) + (sec_r000454_11_2 * 2)) - pub_r000454_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_382_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_382_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_382_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_382_2) & 255;
  int stage_v_383_1 = ((((stage_v_364_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_6_1) + 12) & 127;
  int stage_v_383_2 = ((((stage_v_364_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_383_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_383_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_383_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_383_2) & 255;
  int stage_v_384_1 = ((((sec_r000454_14_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_0_1) + 6) & 127;
  int stage_v_384_2 = ((((sec_r000454_14_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_0_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_384_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_384_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_384_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_384_2) & 255;
  int stage_v_385_1 = ((((stage_v_214_1 * 3) + (sec_r000454_16_1 * 2)) - pub_r000454_10_1) + 24) & 127;
  int stage_v_385_2 = ((((stage_v_214_2 * 3) + (sec_r000454_16_2 * 2)) - pub_r000454_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_385_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_385_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_385_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_385_2) & 255;
  int stage_v_386_1 = ((((stage_v_379_1 * 3) + (sec_r000454_14_1 * 2)) - pub_r000454_9_1) + 19) & 127;
  int stage_v_386_2 = ((((stage_v_379_2 * 3) + (sec_r000454_14_2 * 2)) - pub_r000454_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_386_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_386_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_386_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_386_2) & 255;
  int stage_v_387_1 = ((((stage_v_194_1 * 3) + (sec_r000454_1_1 * 2)) - pub_r000454_19_1) + 33) & 127;
  int stage_v_387_2 = ((((stage_v_194_2 * 3) + (sec_r000454_1_2 * 2)) - pub_r000454_19_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_387_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_387_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_387_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_387_2) & 255;
  int stage_v_388_1 = ((((stage_v_294_1 * 3) + (sec_r000454_15_1 * 2)) - pub_r000454_7_1) + 32) & 127;
  int stage_v_388_2 = ((((stage_v_294_2 * 3) + (sec_r000454_15_2 * 2)) - pub_r000454_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_388_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_388_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_388_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_388_2) & 255;
  int stage_v_389_1 = ((((stage_v_247_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_13_1) + 27) & 127;
  int stage_v_389_2 = ((((stage_v_247_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_389_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_389_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_389_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_389_2) & 255;
  int stage_v_390_1 = ((((sec_r000454_1_1 * 3) + (sec_r000454_1_1 * 2)) - pub_r000454_15_1) + 5) & 127;
  int stage_v_390_2 = ((((sec_r000454_1_2 * 3) + (sec_r000454_1_2 * 2)) - pub_r000454_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_390_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_390_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_390_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_390_2) & 255;
  int stage_v_391_1 = ((((sec_r000454_4_1 * 3) + (sec_r000454_4_1 * 2)) - pub_r000454_9_1) + 7) & 127;
  int stage_v_391_2 = ((((sec_r000454_4_2 * 3) + (sec_r000454_4_2 * 2)) - pub_r000454_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_391_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_391_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_391_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_391_2) & 255;
  int stage_v_392_1 = ((((stage_v_356_1 * 3) + (sec_r000454_0_1 * 2)) - pub_r000454_15_1) + 22) & 127;
  int stage_v_392_2 = ((((stage_v_356_2 * 3) + (sec_r000454_0_2 * 2)) - pub_r000454_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_392_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_392_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_392_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_392_2) & 255;
  int stage_v_393_1 = ((((stage_v_392_1 * 3) + (sec_r000454_9_1 * 2)) - pub_r000454_2_1) + 16) & 127;
  int stage_v_393_2 = ((((stage_v_392_2 * 3) + (sec_r000454_9_2 * 2)) - pub_r000454_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_393_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_393_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_393_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_393_2) & 255;
  int stage_v_394_1 = ((((stage_v_162_1 * 3) + (sec_r000454_2_1 * 2)) - pub_r000454_4_1) + 11) & 127;
  int stage_v_394_2 = ((((stage_v_162_2 * 3) + (sec_r000454_2_2 * 2)) - pub_r000454_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_394_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_394_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_394_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_394_2) & 255;
  int stage_v_395_1 = ((((stage_v_59_1 * 3) + (sec_r000454_12_1 * 2)) - pub_r000454_11_1) + 11) & 127;
  int stage_v_395_2 = ((((stage_v_59_2 * 3) + (sec_r000454_12_2 * 2)) - pub_r000454_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_395_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_395_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_395_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_395_2) & 255;
  int stage_v_396_1 = ((((stage_v_309_1 * 3) + (sec_r000454_5_1 * 2)) - pub_r000454_14_1) + 24) & 127;
  int stage_v_396_2 = ((((stage_v_309_2 * 3) + (sec_r000454_5_2 * 2)) - pub_r000454_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_396_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_396_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_396_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_396_2) & 255;
  int stage_v_397_1 = ((((stage_v_148_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_7_1) + 33) & 127;
  int stage_v_397_2 = ((((stage_v_148_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_7_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_397_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_397_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_397_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_397_2) & 255;
  int stage_v_398_1 = ((((stage_v_67_1 * 3) + (sec_r000454_2_1 * 2)) - pub_r000454_13_1) + 36) & 127;
  int stage_v_398_2 = ((((stage_v_67_2 * 3) + (sec_r000454_2_2 * 2)) - pub_r000454_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_398_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_398_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_398_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_398_2) & 255;
  int stage_v_399_1 = ((((stage_v_120_1 * 3) + (sec_r000454_9_1 * 2)) - pub_r000454_15_1) + 5) & 127;
  int stage_v_399_2 = ((((stage_v_120_2 * 3) + (sec_r000454_9_2 * 2)) - pub_r000454_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_399_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_399_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_399_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_399_2) & 255;
  int stage_v_400_1 = ((((sec_r000454_13_1 * 3) + (sec_r000454_13_1 * 2)) - pub_r000454_13_1) + 33) & 127;
  int stage_v_400_2 = ((((sec_r000454_13_2 * 3) + (sec_r000454_13_2 * 2)) - pub_r000454_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_400_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_400_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_400_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_400_2) & 255;
  int stage_v_401_1 = ((((stage_v_178_1 * 3) + (sec_r000454_6_1 * 2)) - pub_r000454_13_1) + 12) & 127;
  int stage_v_401_2 = ((((stage_v_178_2 * 3) + (sec_r000454_6_2 * 2)) - pub_r000454_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_401_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_401_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_401_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_401_2) & 255;
  int stage_v_402_1 = ((((sec_r000454_5_1 * 3) + (sec_r000454_5_1 * 2)) - pub_r000454_8_1) + 26) & 127;
  int stage_v_402_2 = ((((sec_r000454_5_2 * 3) + (sec_r000454_5_2 * 2)) - pub_r000454_8_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_402_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_402_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_402_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_402_2) & 255;
  int stage_v_403_1 = ((((sec_r000454_9_1 * 3) + (sec_r000454_9_1 * 2)) - pub_r000454_5_1) + 15) & 127;
  int stage_v_403_2 = ((((sec_r000454_9_2 * 3) + (sec_r000454_9_2 * 2)) - pub_r000454_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_403_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_403_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_403_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_403_2) & 255;
  int stage_v_404_1 = ((((sec_r000454_10_1 * 3) + (sec_r000454_10_1 * 2)) - pub_r000454_21_1) + 36) & 127;
  int stage_v_404_2 = ((((sec_r000454_10_2 * 3) + (sec_r000454_10_2 * 2)) - pub_r000454_21_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_404_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_404_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_404_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_404_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000454_16_1 != sec_r000454_16_2);
  __CPROVER_assume(sec_r000454_6_1 != sec_r000454_6_2);
  __CPROVER_assume(sec_r000454_5_1 != sec_r000454_5_2);
  __CPROVER_assume(pub_r000454_7_1 == pub_r000454_7_2);
  __CPROVER_assume(sec_r000454_11_1 != sec_r000454_11_2);
  __CPROVER_assume(sec_r000454_0_1 != sec_r000454_0_2);
  __CPROVER_assume(sec_r000454_13_1 != sec_r000454_13_2);
  __CPROVER_assume(pub_r000454_14_1 == pub_r000454_14_2);
  __CPROVER_assume(pub_r000454_12_1 == pub_r000454_12_2);
  __CPROVER_assume(pub_r000454_23_1 == pub_r000454_23_2);
  __CPROVER_assume(pub_r000454_2_1 == pub_r000454_2_2);
  __CPROVER_assume(pub_r000454_8_1 == pub_r000454_8_2);
  __CPROVER_assume(pub_r000454_9_1 == pub_r000454_9_2);
  __CPROVER_assume(sec_r000454_10_1 != sec_r000454_10_2);
  __CPROVER_assume(pub_r000454_19_1 == pub_r000454_19_2);
  __CPROVER_assume(sec_r000454_14_1 != sec_r000454_14_2);
  __CPROVER_assume(sec_r000454_8_1 != sec_r000454_8_2);
  __CPROVER_assume(sec_r000454_2_1 != sec_r000454_2_2);
  __CPROVER_assume(pub_r000454_5_1 == pub_r000454_5_2);
  __CPROVER_assume(pub_r000454_13_1 == pub_r000454_13_2);
  __CPROVER_assume(sec_r000454_12_1 != sec_r000454_12_2);
  __CPROVER_assume(pub_r000454_20_1 == pub_r000454_20_2);
  __CPROVER_assume(sec_r000454_15_1 != sec_r000454_15_2);
  __CPROVER_assume(pub_r000454_10_1 == pub_r000454_10_2);
  __CPROVER_assume(pub_r000454_22_1 == pub_r000454_22_2);
  __CPROVER_assume(sec_r000454_4_1 != sec_r000454_4_2);
  __CPROVER_assume(pub_r000454_21_1 == pub_r000454_21_2);
  __CPROVER_assume(pub_r000454_4_1 == pub_r000454_4_2);
  __CPROVER_assume(pub_r000454_6_1 == pub_r000454_6_2);
  __CPROVER_assume(pub_r000454_15_1 == pub_r000454_15_2);
  __CPROVER_assume(sec_r000454_3_1 != sec_r000454_3_2);
  __CPROVER_assume(pub_r000454_11_1 == pub_r000454_11_2);
  __CPROVER_assume(sec_r000454_1_1 != sec_r000454_1_2);
  __CPROVER_assume(pub_r000454_18_1 == pub_r000454_18_2);
  __CPROVER_assume(sec_r000454_9_1 != sec_r000454_9_2);
  __CPROVER_assume(pub_r000454_16_1 == pub_r000454_16_2);
  __CPROVER_assume(pub_r000454_1_1 == pub_r000454_1_2);
  __CPROVER_assume(pub_r000454_3_1 == pub_r000454_3_2);
  __CPROVER_assume(sec_r000454_7_1 != sec_r000454_7_2);
  __CPROVER_assume(pub_r000454_17_1 == pub_r000454_17_2);
  __CPROVER_assume(pub_r000454_0_1 == pub_r000454_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.iv == st_var_1_2.iv);
  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  assert(st_var_1_1.flags == st_var_1_2.flags);
  assert(st_var_1_1.counter == st_var_1_2.counter);
  assert(st_var_1_1.nonce == st_var_1_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.stop_bits == st_var_2_2.stop_bits);
  assert(st_var_2_1.timeout == st_var_2_2.timeout);
  assert(st_var_2_1.port == st_var_2_2.port);
  assert(st_var_2_1.id == st_var_2_2.id);
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


