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
struct Transaction_R000444_4413_0
{
  int account_id;
  int rate;
  int status;
  int fee;
  int buffer[3];
};
struct DeviceConfig_R000444_4413_1
{
  short port;
  int timeout;
  short id;
  int parity;
  int baud_rate;
  int buffer[3];
};
union ColorPixel_R000444_4413_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000444_4413_1
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
void fn_R000444_4413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st_1 = {0};
  struct DeviceConfig_R000444_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int factor_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_74_1)
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

  switch (factor_74_2)
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

  int pivot_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_28_1) & 63;
  aux_2 = (aux_2 + pivot_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_95_1 = local_arr_1[aux_1 % 3];
  int bound_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_74_1 == factor_74_2);
  assert(pivot_28_1 == pivot_28_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_95_1 == bound_95_2);
}

int fn_R000444_4413_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int factor_74 = (aux + st.buffer[1]) & 3;
  switch (factor_74)
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

  int pivot_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_28) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_95 = local_arr[aux % 3];
  acc = (acc + (bound_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000444_4413_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st_1 = {0};
  struct DeviceConfig_R000444_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_90_1 = local_arr_1[aux_1 % 3];
  int delta_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_90_2 * 2)) & 127;
  int cursor_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_37_1)
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

  switch (cursor_37_2)
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

  int tracker_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_29_1) & 63;
  aux_2 = (aux_2 + tracker_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_90_1 == delta_90_2);
  assert(cursor_37_1 == cursor_37_2);
  assert(tracker_29_1 == tracker_29_2);
}

int fn_R000444_4413_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_90 = local_arr[aux % 3];
  acc = (acc + (delta_90 * 2)) & 127;
  int cursor_37 = (aux + st.buffer[1]) & 3;
  switch (cursor_37)
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

  int tracker_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_29) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000444_4413_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st_1 = {0};
  struct Transaction_R000444_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int delta_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_99_1 > 48)
  {
    acc_1 = ((acc_1 + (delta_99_1 * 2)) + 5) & 127;
    aux_1 ^= delta_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_99_2 > 48)
  {
    acc_2 = ((acc_2 + (delta_99_2 * 2)) + 5) & 127;
    aux_2 ^= delta_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_99_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_92_1) & 63;
  aux_2 = (aux_2 + phase_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_33_1)
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

  switch (tally_33_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_99_1 == delta_99_2);
  assert(phase_92_1 == phase_92_2);
  assert(tally_33_1 == tally_33_2);
}

int fn_R000444_4413_2(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int delta_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_99 > 48)
  {
    acc = ((acc + (delta_99 * 2)) + 5) & 127;
    aux ^= delta_99 & 15;
  }
  else
  {
    acc = ((acc - delta_99) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_92) & 63;
  acc ^= aux;
  int tally_33 = (aux + st.buffer[1]) & 3;
  switch (tally_33)
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

void fn_R000444_4413_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st_1 = {0};
  struct Transaction_R000444_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_52_1 = local_arr_1[aux_1 % 3];
  int quantum_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_52_2 * 2)) & 127;
  int mask_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_87_1 > 33)
  {
    acc_1 = ((acc_1 + (mask_87_1 * 2)) + 5) & 127;
    aux_1 ^= mask_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_87_2 > 33)
  {
    acc_2 = ((acc_2 + (mask_87_2 * 2)) + 5) & 127;
    aux_2 ^= mask_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_87_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_67_1)
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

  switch (cursor_67_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_52_1 == quantum_52_2);
  assert(mask_87_1 == mask_87_2);
  assert(cursor_67_1 == cursor_67_2);
}

int fn_R000444_4413_3(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int quantum_52 = local_arr[aux % 3];
  acc = (acc + (quantum_52 * 2)) & 127;
  int mask_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_87 > 33)
  {
    acc = ((acc + (mask_87 * 2)) + 5) & 127;
    aux ^= mask_87 & 15;
  }
  else
  {
    acc = ((acc - mask_87) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_67 = (aux + st.buffer[1]) & 3;
  switch (cursor_67)
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

void fn_R000444_4413_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st_1 = {0};
  struct DeviceConfig_R000444_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int coefficient_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_24_1 > 41)
  {
    acc_1 = ((acc_1 + (coefficient_24_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_24_2 > 41)
  {
    acc_2 = ((acc_2 + (coefficient_24_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_23_1)
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

  switch (damping_23_2)
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
  int metric_56_1 = local_arr_1[aux_1 % 3];
  int metric_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_56_2 * 2)) & 127;
  int phase_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_53_1) & 63;
  aux_2 = (aux_2 + phase_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_24_1 == coefficient_24_2);
  assert(damping_23_1 == damping_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_56_1 == metric_56_2);
  assert(phase_53_1 == phase_53_2);
}

int fn_R000444_4413_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int coefficient_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_24 > 41)
  {
    acc = ((acc + (coefficient_24 * 2)) + 5) & 127;
    aux ^= coefficient_24 & 15;
  }
  else
  {
    acc = ((acc - coefficient_24) + 11) & 127;
    aux += 3;
  }
  int damping_23 = (aux + st.buffer[1]) & 3;
  switch (damping_23)
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
  int metric_56 = local_arr[aux % 3];
  acc = (acc + (metric_56 * 2)) & 127;
  int phase_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_53) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000444_4413_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st_1 = {0};
  struct DeviceConfig_R000444_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quotient_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_74_1 > 43)
  {
    acc_1 = ((acc_1 + (quotient_74_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_74_2 > 43)
  {
    acc_2 = ((acc_2 + (quotient_74_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_74_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_18_1 = local_arr_1[aux_1 % 3];
  int accumulator_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_18_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_37_1) & 63;
  aux_2 = (aux_2 + tally_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_74_1 == quotient_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_18_1 == accumulator_18_2);
  assert(tally_37_1 == tally_37_2);
}

int fn_R000444_4413_5(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quotient_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_74 > 43)
  {
    acc = ((acc + (quotient_74 * 2)) + 5) & 127;
    aux ^= quotient_74 & 15;
  }
  else
  {
    acc = ((acc - quotient_74) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_18 = local_arr[aux % 3];
  acc = (acc + (accumulator_18 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_37) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000444_4413_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st_1 = {0};
  struct Transaction_R000444_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int pivot_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_72_1)
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

  switch (pivot_72_2)
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

  int bound_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_57_1) & 63;
  aux_2 = (aux_2 + bound_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_72_1 == pivot_72_2);
  assert(bound_57_1 == bound_57_2);
}

int fn_R000444_4413_6(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int pivot_72 = (aux + st.buffer[1]) & 3;
  switch (pivot_72)
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

  int bound_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_57) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000444_4413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st_1 = {0};
  struct Transaction_R000444_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int quotient_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_51_1) & 63;
  aux_2 = (aux_2 + quotient_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_84_1)
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

  switch (residue_84_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_51_1 == quotient_51_2);
  assert(residue_84_1 == residue_84_2);
}

int fn_R000444_4413_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int quotient_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_51) & 63;
  acc ^= aux;
  int residue_84 = (aux + st.buffer[1]) & 3;
  switch (residue_84)
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

void fn_R000444_4413_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st_1 = {0};
  struct Transaction_R000444_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_19_1)
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

  switch (delta_19_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_19_1 == delta_19_2);
}

int fn_R000444_4413_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_19 = (aux + st.buffer[1]) & 3;
  switch (delta_19)
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

void fn_R000444_4413_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st_1 = {0};
  struct DeviceConfig_R000444_4413_1 st_2 = {0};
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
  int damping_33_1 = local_arr_1[aux_1 % 3];
  int damping_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_33_2 * 2)) & 127;
  int scale_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_50_1)
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

  switch (scale_50_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_33_1 == damping_33_2);
  assert(scale_50_1 == scale_50_2);
}

int fn_R000444_4413_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int damping_33 = local_arr[aux % 3];
  acc = (acc + (damping_33 * 2)) & 127;
  int scale_50 = (aux + st.buffer[1]) & 3;
  switch (scale_50)
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

void fn_R000444_4413_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st_1 = {0};
  struct DeviceConfig_R000444_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int anchor_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_49_1 > 26)
  {
    acc_1 = ((acc_1 + (anchor_49_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_49_2 > 26)
  {
    acc_2 = ((acc_2 + (anchor_49_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_49_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_21_1)
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

  switch (cursor_21_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_49_1 == anchor_49_2);
  assert(cursor_21_1 == cursor_21_2);
}

int fn_R000444_4413_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int anchor_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_49 > 26)
  {
    acc = ((acc + (anchor_49 * 2)) + 5) & 127;
    aux ^= anchor_49 & 15;
  }
  else
  {
    acc = ((acc - anchor_49) + 11) & 127;
    aux += 3;
  }
  int cursor_21 = (aux + st.buffer[1]) & 3;
  switch (cursor_21)
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

void fn_R000444_4413_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st_1 = {0};
  struct Transaction_R000444_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int scale_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_52_1)
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

  switch (scale_52_2)
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

  int tally_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_39_1) & 63;
  aux_2 = (aux_2 + tally_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_40_1 = local_arr_1[aux_1 % 3];
  int stride_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_40_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_52_1 == scale_52_2);
  assert(tally_39_1 == tally_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_40_1 == stride_40_2);
}

int fn_R000444_4413_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int scale_52 = (aux + st.buffer[1]) & 3;
  switch (scale_52)
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

  int tally_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_39) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int stride_40 = local_arr[aux % 3];
  acc = (acc + (stride_40 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000444_4413_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st_1 = {0};
  struct Transaction_R000444_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int offset_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_19_1)
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

  switch (offset_19_2)
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

  int vector_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_99_1) & 63;
  aux_2 = (aux_2 + vector_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_20_1 = local_arr_1[aux_1 % 3];
  int parity_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_20_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_19_1 == offset_19_2);
  assert(vector_99_1 == vector_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_20_1 == parity_20_2);
}

int fn_R000444_4413_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int offset_19 = (aux + st.buffer[1]) & 3;
  switch (offset_19)
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

  int vector_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_99) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int parity_20 = local_arr[aux % 3];
  acc = (acc + (parity_20 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000444_4413_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st_1 = {0};
  struct DeviceConfig_R000444_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int quantum_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_33_1)
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

  switch (quantum_33_2)
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

  int index_reg_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_17_1 > 16)
  {
    acc_1 = ((acc_1 + (index_reg_17_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_17_2 > 16)
  {
    acc_2 = ((acc_2 + (index_reg_17_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_17_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_33_1 == quantum_33_2);
  assert(index_reg_17_1 == index_reg_17_2);
}

int fn_R000444_4413_13(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int quantum_33 = (aux + st.buffer[1]) & 3;
  switch (quantum_33)
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

  int index_reg_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_17 > 16)
  {
    acc = ((acc + (index_reg_17 * 2)) + 5) & 127;
    aux ^= index_reg_17 & 15;
  }
  else
  {
    acc = ((acc - index_reg_17) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000444_4413_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st_1 = {0};
  struct Transaction_R000444_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int pivot_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_19_1 > 22)
  {
    acc_1 = ((acc_1 + (pivot_19_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_19_2 > 22)
  {
    acc_2 = ((acc_2 + (pivot_19_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_19_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_42_1)
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

  switch (factor_42_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_19_1 == pivot_19_2);
  assert(factor_42_1 == factor_42_2);
}

int fn_R000444_4413_14(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int pivot_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_19 > 22)
  {
    acc = ((acc + (pivot_19 * 2)) + 5) & 127;
    aux ^= pivot_19 & 15;
  }
  else
  {
    acc = ((acc - pivot_19) + 11) & 127;
    aux += 3;
  }
  int factor_42 = (aux + st.buffer[1]) & 3;
  switch (factor_42)
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

void fn_R000444_4413_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st_1 = {0};
  struct Transaction_R000444_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int quotient_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_56_1)
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

  switch (quotient_56_2)
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

  int sample_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_20_1 > 16)
  {
    acc_1 = ((acc_1 + (sample_20_1 * 2)) + 5) & 127;
    aux_1 ^= sample_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_20_2 > 16)
  {
    acc_2 = ((acc_2 + (sample_20_2 * 2)) + 5) & 127;
    aux_2 ^= sample_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_20_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_56_1 == quotient_56_2);
  assert(sample_20_1 == sample_20_2);
}

int fn_R000444_4413_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int quotient_56 = (aux + st.buffer[1]) & 3;
  switch (quotient_56)
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

  int sample_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_20 > 16)
  {
    acc = ((acc + (sample_20 * 2)) + 5) & 127;
    aux ^= sample_20 & 15;
  }
  else
  {
    acc = ((acc - sample_20) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000444_4413_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st_1 = {0};
  struct Transaction_R000444_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_68_1) & 63;
  aux_2 = (aux_2 + mask_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_26_1 = local_arr_1[aux_1 % 3];
  int residue_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_26_2 * 2)) & 127;
  int window_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_49_1 > 11)
  {
    acc_1 = ((acc_1 + (window_49_1 * 2)) + 5) & 127;
    aux_1 ^= window_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_49_2 > 11)
  {
    acc_2 = ((acc_2 + (window_49_2 * 2)) + 5) & 127;
    aux_2 ^= window_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_49_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_68_1 == mask_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_26_1 == residue_26_2);
  assert(window_49_1 == window_49_2);
}

int fn_R000444_4413_16(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_68) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int residue_26 = local_arr[aux % 3];
  acc = (acc + (residue_26 * 2)) & 127;
  int window_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_49 > 11)
  {
    acc = ((acc + (window_49 * 2)) + 5) & 127;
    aux ^= window_49 & 15;
  }
  else
  {
    acc = ((acc - window_49) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000444_4413_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st_1 = {0};
  struct DeviceConfig_R000444_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int factor_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_98_1 > 12)
  {
    acc_1 = ((acc_1 + (factor_98_1 * 2)) + 5) & 127;
    aux_1 ^= factor_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_98_2 > 12)
  {
    acc_2 = ((acc_2 + (factor_98_2 * 2)) + 5) & 127;
    aux_2 ^= factor_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_75_1)
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

  switch (threshold_75_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_98_1 == factor_98_2);
  assert(threshold_75_1 == threshold_75_2);
}

int fn_R000444_4413_17(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int factor_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_98 > 12)
  {
    acc = ((acc + (factor_98 * 2)) + 5) & 127;
    aux ^= factor_98 & 15;
  }
  else
  {
    acc = ((acc - factor_98) + 11) & 127;
    aux += 3;
  }
  int threshold_75 = (aux + st.buffer[1]) & 3;
  switch (threshold_75)
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

void fn_R000444_4413_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st_1 = {0};
  struct DeviceConfig_R000444_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int metric_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_17_1)
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

  switch (metric_17_2)
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

  int phase_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_12_1 > 12)
  {
    acc_1 = ((acc_1 + (phase_12_1 * 2)) + 5) & 127;
    aux_1 ^= phase_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_12_2 > 12)
  {
    acc_2 = ((acc_2 + (phase_12_2 * 2)) + 5) & 127;
    aux_2 ^= phase_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_12_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_17_1 == metric_17_2);
  assert(phase_12_1 == phase_12_2);
}

int fn_R000444_4413_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int metric_17 = (aux + st.buffer[1]) & 3;
  switch (metric_17)
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

  int phase_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_12 > 12)
  {
    acc = ((acc + (phase_12 * 2)) + 5) & 127;
    aux ^= phase_12 & 15;
  }
  else
  {
    acc = ((acc - phase_12) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000444_4413_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st_1 = {0};
  struct DeviceConfig_R000444_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_74_1)
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

  switch (residue_74_2)
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

  int offset_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_52_1) & 63;
  aux_2 = (aux_2 + offset_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_12_1 > 38)
  {
    acc_1 = ((acc_1 + (window_12_1 * 2)) + 5) & 127;
    aux_1 ^= window_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_12_2 > 38)
  {
    acc_2 = ((acc_2 + (window_12_2 * 2)) + 5) & 127;
    aux_2 ^= window_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_74_1 == residue_74_2);
  assert(offset_52_1 == offset_52_2);
  assert(window_12_1 == window_12_2);
}

int fn_R000444_4413_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_74 = (aux + st.buffer[1]) & 3;
  switch (residue_74)
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

  int offset_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_52) & 63;
  acc ^= aux;
  int window_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_12 > 38)
  {
    acc = ((acc + (window_12 * 2)) + 5) & 127;
    aux ^= window_12 & 15;
  }
  else
  {
    acc = ((acc - window_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000444_4413_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st_1 = {0};
  struct Transaction_R000444_4413_0 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_74_1 = local_arr_1[aux_1 % 3];
  int stride_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_74_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_74_1 == stride_74_2);
}

int fn_R000444_4413_20(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int stride_74 = local_arr[aux % 3];
  acc = (acc + (stride_74 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000444_4413_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st_1 = {0};
  struct DeviceConfig_R000444_4413_1 st_2 = {0};
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
  int checksum_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_32_1 > 49)
  {
    acc_1 = ((acc_1 + (checksum_32_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_32_2 > 49)
  {
    acc_2 = ((acc_2 + (checksum_32_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_32_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_63_1) & 63;
  aux_2 = (aux_2 + quotient_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_52_1)
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

  switch (sample_52_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_32_1 == checksum_32_2);
  assert(quotient_63_1 == quotient_63_2);
  assert(sample_52_1 == sample_52_2);
}

int fn_R000444_4413_21(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_32 > 49)
  {
    acc = ((acc + (checksum_32 * 2)) + 5) & 127;
    aux ^= checksum_32 & 15;
  }
  else
  {
    acc = ((acc - checksum_32) + 11) & 127;
    aux += 3;
  }
  int quotient_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_63) & 63;
  acc ^= aux;
  int sample_52 = (aux + st.buffer[1]) & 3;
  switch (sample_52)
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

void fn_R000444_4413_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st_1 = {0};
  struct Transaction_R000444_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int residue_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_21_1)
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

  switch (residue_21_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_60_1 > 26)
  {
    acc_1 = ((acc_1 + (quantum_60_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_60_2 > 26)
  {
    acc_2 = ((acc_2 + (quantum_60_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_60_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_21_1 == residue_21_2);
  assert(quantum_60_1 == quantum_60_2);
}

int fn_R000444_4413_22(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000444_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int residue_21 = (aux + st.buffer[1]) & 3;
  switch (residue_21)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_60 > 26)
  {
    acc = ((acc + (quantum_60 * 2)) + 5) & 127;
    aux ^= quantum_60 & 15;
  }
  else
  {
    acc = ((acc - quantum_60) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000444_4413_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st_1 = {0};
  struct DeviceConfig_R000444_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_98_1 = local_arr_1[aux_1 % 3];
  int quantum_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_98_2 * 2)) & 127;
  int parity_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_57_1)
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

  switch (parity_57_2)
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

  int pivot_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_24_1 > 29)
  {
    acc_1 = ((acc_1 + (pivot_24_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_24_2 > 29)
  {
    acc_2 = ((acc_2 + (pivot_24_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_24_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_98_1 == quantum_98_2);
  assert(parity_57_1 == parity_57_2);
  assert(pivot_24_1 == pivot_24_2);
}

int fn_R000444_4413_23(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000444_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int quantum_98 = local_arr[aux % 3];
  acc = (acc + (quantum_98 * 2)) & 127;
  int parity_57 = (aux + st.buffer[1]) & 3;
  switch (parity_57)
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

  int pivot_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_24 > 29)
  {
    acc = ((acc + (pivot_24 * 2)) + 5) & 127;
    aux ^= pivot_24 & 15;
  }
  else
  {
    acc = ((acc - pivot_24) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000444_0_1;
  int sec_r000444_0_2;
  int sec_r000444_1_1;
  int sec_r000444_1_2;
  int sec_r000444_2_1;
  int sec_r000444_2_2;
  int sec_r000444_3_1;
  int sec_r000444_3_2;
  int sec_r000444_4_1;
  int sec_r000444_4_2;
  int sec_r000444_5_1;
  int sec_r000444_5_2;
  int sec_r000444_6_1;
  int sec_r000444_6_2;
  int sec_r000444_7_1;
  int sec_r000444_7_2;
  int sec_r000444_8_1;
  int sec_r000444_8_2;
  int sec_r000444_9_1;
  int sec_r000444_9_2;
  int sec_r000444_10_1;
  int sec_r000444_10_2;
  int sec_r000444_11_1;
  int sec_r000444_11_2;
  int sec_r000444_12_1;
  int sec_r000444_12_2;
  int sec_r000444_13_1;
  int sec_r000444_13_2;
  int sec_r000444_14_1;
  int sec_r000444_14_2;
  int sec_r000444_15_1;
  int sec_r000444_15_2;
  int sec_r000444_16_1;
  int sec_r000444_16_2;
  int sec_r000444_17_1;
  int sec_r000444_17_2;
  int sec_r000444_18_1;
  int sec_r000444_18_2;
  int pub_r000444_0_1;
  int pub_r000444_0_2;
  int pub_r000444_1_1;
  int pub_r000444_1_2;
  int pub_r000444_2_1;
  int pub_r000444_2_2;
  int pub_r000444_3_1;
  int pub_r000444_3_2;
  int pub_r000444_4_1;
  int pub_r000444_4_2;
  int pub_r000444_5_1;
  int pub_r000444_5_2;
  int pub_r000444_6_1;
  int pub_r000444_6_2;
  int pub_r000444_7_1;
  int pub_r000444_7_2;
  int pub_r000444_8_1;
  int pub_r000444_8_2;
  int pub_r000444_9_1;
  int pub_r000444_9_2;
  int pub_r000444_10_1;
  int pub_r000444_10_2;
  int pub_r000444_11_1;
  int pub_r000444_11_2;
  int pub_r000444_12_1;
  int pub_r000444_12_2;
  int pub_r000444_13_1;
  int pub_r000444_13_2;
  int pub_r000444_14_1;
  int pub_r000444_14_2;
  int pub_r000444_15_1;
  int pub_r000444_15_2;
  int pub_r000444_16_1;
  int pub_r000444_16_2;
  int pub_r000444_17_1;
  int pub_r000444_17_2;
  int pub_r000444_18_1;
  int pub_r000444_18_2;
  int pub_r000444_19_1;
  int pub_r000444_19_2;
  int pub_r000444_20_1;
  int pub_r000444_20_2;
  int pub_r000444_21_1;
  int pub_r000444_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000444_0_1 >= (-100)) && (pub_r000444_0_1 <= 100));
  __CPROVER_assume((pub_r000444_0_2 >= (-100)) && (pub_r000444_0_2 <= 100));
  __CPROVER_assume((pub_r000444_1_1 >= (-100)) && (pub_r000444_1_1 <= 100));
  __CPROVER_assume((pub_r000444_1_2 >= (-100)) && (pub_r000444_1_2 <= 100));
  __CPROVER_assume((pub_r000444_2_1 >= (-100)) && (pub_r000444_2_1 <= 100));
  __CPROVER_assume((pub_r000444_2_2 >= (-100)) && (pub_r000444_2_2 <= 100));
  __CPROVER_assume((pub_r000444_3_1 >= (-100)) && (pub_r000444_3_1 <= 100));
  __CPROVER_assume((pub_r000444_3_2 >= (-100)) && (pub_r000444_3_2 <= 100));
  __CPROVER_assume((pub_r000444_4_1 >= (-100)) && (pub_r000444_4_1 <= 100));
  __CPROVER_assume((pub_r000444_4_2 >= (-100)) && (pub_r000444_4_2 <= 100));
  __CPROVER_assume((pub_r000444_5_1 >= (-100)) && (pub_r000444_5_1 <= 100));
  __CPROVER_assume((pub_r000444_5_2 >= (-100)) && (pub_r000444_5_2 <= 100));
  __CPROVER_assume((pub_r000444_6_1 >= (-100)) && (pub_r000444_6_1 <= 100));
  __CPROVER_assume((pub_r000444_6_2 >= (-100)) && (pub_r000444_6_2 <= 100));
  __CPROVER_assume((pub_r000444_7_1 >= (-100)) && (pub_r000444_7_1 <= 100));
  __CPROVER_assume((pub_r000444_7_2 >= (-100)) && (pub_r000444_7_2 <= 100));
  __CPROVER_assume((pub_r000444_8_1 >= (-100)) && (pub_r000444_8_1 <= 100));
  __CPROVER_assume((pub_r000444_8_2 >= (-100)) && (pub_r000444_8_2 <= 100));
  __CPROVER_assume((pub_r000444_9_1 >= (-100)) && (pub_r000444_9_1 <= 100));
  __CPROVER_assume((pub_r000444_9_2 >= (-100)) && (pub_r000444_9_2 <= 100));
  __CPROVER_assume((pub_r000444_10_1 >= (-100)) && (pub_r000444_10_1 <= 100));
  __CPROVER_assume((pub_r000444_10_2 >= (-100)) && (pub_r000444_10_2 <= 100));
  __CPROVER_assume((pub_r000444_11_1 >= (-100)) && (pub_r000444_11_1 <= 100));
  __CPROVER_assume((pub_r000444_11_2 >= (-100)) && (pub_r000444_11_2 <= 100));
  __CPROVER_assume((pub_r000444_12_1 >= (-100)) && (pub_r000444_12_1 <= 100));
  __CPROVER_assume((pub_r000444_12_2 >= (-100)) && (pub_r000444_12_2 <= 100));
  __CPROVER_assume((pub_r000444_13_1 >= (-100)) && (pub_r000444_13_1 <= 100));
  __CPROVER_assume((pub_r000444_13_2 >= (-100)) && (pub_r000444_13_2 <= 100));
  __CPROVER_assume((pub_r000444_14_1 >= (-100)) && (pub_r000444_14_1 <= 100));
  __CPROVER_assume((pub_r000444_14_2 >= (-100)) && (pub_r000444_14_2 <= 100));
  __CPROVER_assume((pub_r000444_15_1 >= (-100)) && (pub_r000444_15_1 <= 100));
  __CPROVER_assume((pub_r000444_15_2 >= (-100)) && (pub_r000444_15_2 <= 100));
  __CPROVER_assume((pub_r000444_16_1 >= (-100)) && (pub_r000444_16_1 <= 100));
  __CPROVER_assume((pub_r000444_16_2 >= (-100)) && (pub_r000444_16_2 <= 100));
  __CPROVER_assume((pub_r000444_17_1 >= (-100)) && (pub_r000444_17_1 <= 100));
  __CPROVER_assume((pub_r000444_17_2 >= (-100)) && (pub_r000444_17_2 <= 100));
  __CPROVER_assume((pub_r000444_18_1 >= (-100)) && (pub_r000444_18_1 <= 100));
  __CPROVER_assume((pub_r000444_18_2 >= (-100)) && (pub_r000444_18_2 <= 100));
  __CPROVER_assume((pub_r000444_19_1 >= (-100)) && (pub_r000444_19_1 <= 100));
  __CPROVER_assume((pub_r000444_19_2 >= (-100)) && (pub_r000444_19_2 <= 100));
  __CPROVER_assume((pub_r000444_20_1 >= (-100)) && (pub_r000444_20_1 <= 100));
  __CPROVER_assume((pub_r000444_20_2 >= (-100)) && (pub_r000444_20_2 <= 100));
  __CPROVER_assume((pub_r000444_21_1 >= (-100)) && (pub_r000444_21_1 <= 100));
  __CPROVER_assume((pub_r000444_21_2 >= (-100)) && (pub_r000444_21_2 <= 100));
  __CPROVER_assume((sec_r000444_0_1 >= 0) && (sec_r000444_0_1 <= 255));
  __CPROVER_assume((sec_r000444_0_2 >= 0) && (sec_r000444_0_2 <= 255));
  __CPROVER_assume((sec_r000444_1_1 >= 0) && (sec_r000444_1_1 <= 255));
  __CPROVER_assume((sec_r000444_1_2 >= 0) && (sec_r000444_1_2 <= 255));
  __CPROVER_assume((sec_r000444_2_1 >= 0) && (sec_r000444_2_1 <= 255));
  __CPROVER_assume((sec_r000444_2_2 >= 0) && (sec_r000444_2_2 <= 255));
  __CPROVER_assume((sec_r000444_3_1 >= 0) && (sec_r000444_3_1 <= 255));
  __CPROVER_assume((sec_r000444_3_2 >= 0) && (sec_r000444_3_2 <= 255));
  __CPROVER_assume((sec_r000444_4_1 >= 0) && (sec_r000444_4_1 <= 255));
  __CPROVER_assume((sec_r000444_4_2 >= 0) && (sec_r000444_4_2 <= 255));
  __CPROVER_assume((sec_r000444_5_1 >= 0) && (sec_r000444_5_1 <= 255));
  __CPROVER_assume((sec_r000444_5_2 >= 0) && (sec_r000444_5_2 <= 255));
  __CPROVER_assume((sec_r000444_6_1 >= 0) && (sec_r000444_6_1 <= 255));
  __CPROVER_assume((sec_r000444_6_2 >= 0) && (sec_r000444_6_2 <= 255));
  __CPROVER_assume((sec_r000444_7_1 >= 0) && (sec_r000444_7_1 <= 255));
  __CPROVER_assume((sec_r000444_7_2 >= 0) && (sec_r000444_7_2 <= 255));
  __CPROVER_assume((sec_r000444_8_1 >= 0) && (sec_r000444_8_1 <= 255));
  __CPROVER_assume((sec_r000444_8_2 >= 0) && (sec_r000444_8_2 <= 255));
  __CPROVER_assume((sec_r000444_9_1 >= 0) && (sec_r000444_9_1 <= 255));
  __CPROVER_assume((sec_r000444_9_2 >= 0) && (sec_r000444_9_2 <= 255));
  __CPROVER_assume((sec_r000444_10_1 >= 0) && (sec_r000444_10_1 <= 255));
  __CPROVER_assume((sec_r000444_10_2 >= 0) && (sec_r000444_10_2 <= 255));
  __CPROVER_assume((sec_r000444_11_1 >= 0) && (sec_r000444_11_1 <= 255));
  __CPROVER_assume((sec_r000444_11_2 >= 0) && (sec_r000444_11_2 <= 255));
  __CPROVER_assume((sec_r000444_12_1 >= 0) && (sec_r000444_12_1 <= 255));
  __CPROVER_assume((sec_r000444_12_2 >= 0) && (sec_r000444_12_2 <= 255));
  __CPROVER_assume((sec_r000444_13_1 >= 0) && (sec_r000444_13_1 <= 255));
  __CPROVER_assume((sec_r000444_13_2 >= 0) && (sec_r000444_13_2 <= 255));
  __CPROVER_assume((sec_r000444_14_1 >= 0) && (sec_r000444_14_1 <= 255));
  __CPROVER_assume((sec_r000444_14_2 >= 0) && (sec_r000444_14_2 <= 255));
  __CPROVER_assume((sec_r000444_15_1 >= 0) && (sec_r000444_15_1 <= 255));
  __CPROVER_assume((sec_r000444_15_2 >= 0) && (sec_r000444_15_2 <= 255));
  __CPROVER_assume((sec_r000444_16_1 >= 0) && (sec_r000444_16_1 <= 255));
  __CPROVER_assume((sec_r000444_16_2 >= 0) && (sec_r000444_16_2 <= 255));
  __CPROVER_assume((sec_r000444_17_1 >= 0) && (sec_r000444_17_1 <= 255));
  __CPROVER_assume((sec_r000444_17_2 >= 0) && (sec_r000444_17_2 <= 255));
  __CPROVER_assume((sec_r000444_18_1 >= 0) && (sec_r000444_18_1 <= 255));
  __CPROVER_assume((sec_r000444_18_2 >= 0) && (sec_r000444_18_2 <= 255));
  struct Transaction_R000444_4413_0 st_var_0_1 = {0};
  struct Transaction_R000444_4413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000444_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000444_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000444_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000444_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000444_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000444_0_2 + 7) & 15;
  struct DeviceConfig_R000444_4413_1 st_var_1_1 = {0};
  struct DeviceConfig_R000444_4413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000444_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000444_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000444_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000444_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000444_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000444_0_2 + 9) & 15;
  union ColorPixel_R000444_4413_0 u_var_1;
  union ColorPixel_R000444_4413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 2) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 2) & 15;
  int stage_v_1_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_1_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= stage_v_1_1;
  chk_sum_2 ^= stage_v_1_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 3) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 4) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
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
  int stage_v_8_1 = ((st_var_0_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_0_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 45)
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
  if (stage_v_8_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 45)
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
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 10) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
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
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 47)
    {
      chk_sum_1 ^= stage_v_13_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_13_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 47)
    {
      chk_sum_2 ^= stage_v_13_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_14_1 = table_1[2];
  int stage_v_14_2 = table_2[2];
  table_1[2] = (table_1[3] + 29) & 63;
  table_2[2] = (table_2[3] + 29) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((st_var_1_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_1_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 40)
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
  if (stage_v_15_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 40)
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
  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
  int stage_v_17_1 = (st_var_1_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_1_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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

  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 20) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 20) & 15;
  int stage_v_19_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_19_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= stage_v_19_1;
  chk_sum_2 ^= stage_v_19_2;
  int stage_v_20_1 = ((st_var_0_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_0_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 30)
    {
      chk_sum_1 ^= stage_v_20_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_20_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 30)
    {
      chk_sum_2 ^= stage_v_20_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
  int stage_v_22_1 = table_1[2];
  int stage_v_22_2 = table_2[2];
  table_1[2] = (table_1[3] + 45) & 63;
  table_2[2] = (table_2[3] + 45) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 24) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = ((st_var_0_1.buffer[0] * 2) + 79) & 63;
  int stage_v_24_2 = ((st_var_0_2.buffer[0] * 2) + 79) & 63;
  if (stage_v_24_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_24_1) - 5) & 255;
    if (stage_v_24_1 > 29)
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
  if (stage_v_24_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_24_2) - 5) & 255;
    if (stage_v_24_2 > 29)
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
  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
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

  switch (stage_v_25_2)
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

  int stage_v_26_1 = ((st_var_0_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_0_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 52)
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
  if (stage_v_26_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 52)
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

  int stage_v_29_1 = table_1[1];
  int stage_v_29_2 = table_2[1];
  table_1[1] = (table_1[2] + 59) & 63;
  table_2[1] = (table_2[2] + 59) & 63;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_31_1 = ((stage_v_31_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_31_2 = ((stage_v_31_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_32_1 = ((stage_v_32_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_32_2 = ((stage_v_32_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = table_1[1];
  int stage_v_33_2 = table_2[1];
  table_1[1] = (table_1[2] + 67) & 63;
  table_2[1] = (table_2[2] + 67) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
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
  int stage_v_35_1 = (st_var_1_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_1_2.buffer[0] ^ 38) & 3;
  switch (stage_v_35_1)
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

  switch (stage_v_35_2)
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

  int stage_v_36_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_36_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_37_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (42 & 31);
  int stage_v_37_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (42 & 31);
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= (stage_v_37_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_37_2 << 1) & 127;
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
  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (st_var_1_1.buffer[0] ^ 44) & 3;
  int stage_v_41_2 = (st_var_1_2.buffer[0] ^ 44) & 3;
  switch (stage_v_41_1)
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

  switch (stage_v_41_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 43) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 43) & 15;
  int stage_v_42_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_42_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= stage_v_42_1;
  chk_sum_2 ^= stage_v_42_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 44) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 44) & 15;
  int stage_v_43_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_43_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= stage_v_43_1;
  chk_sum_2 ^= stage_v_43_2;
  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_45_1 = ((st_var_1_1.buffer[0] * 2) + 142) & 63;
  int stage_v_45_2 = ((st_var_1_2.buffer[0] * 2) + 142) & 63;
  if (stage_v_45_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_45_1) - 5) & 255;
    if (stage_v_45_1 > 33)
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
  if (stage_v_45_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_45_2) - 5) & 255;
    if (stage_v_45_2 > 33)
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
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 47) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 47) & 15;
  int stage_v_46_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_46_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= stage_v_46_1;
  chk_sum_2 ^= stage_v_46_2;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  int stage_v_49_1 = ((st_var_1_1.buffer[1] * 2) + 154) & 63;
  int stage_v_49_2 = ((st_var_1_2.buffer[1] * 2) + 154) & 63;
  if (stage_v_49_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 48)
    {
      chk_sum_1 ^= stage_v_49_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_49_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 48)
    {
      chk_sum_2 ^= stage_v_49_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_50_1 = (st_var_0_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_0_2.buffer[0] ^ 53) & 3;
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

  int stage_v_51_1 = (st_var_1_1.buffer[0] ^ 54) & 3;
  int stage_v_51_2 = (st_var_1_2.buffer[0] ^ 54) & 3;
  switch (stage_v_51_1)
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

  switch (stage_v_51_2)
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

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 53) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 53) & 15;
  int stage_v_52_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_52_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= stage_v_52_1;
  chk_sum_2 ^= stage_v_52_2;
  int stage_v_53_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_53_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_53_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_53_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_56_1 = ((stage_v_56_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_56_2 = ((stage_v_56_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 58) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 58) & 15;
  int stage_v_57_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_57_2 = (st_var_1_2.buffer[0] * 3) & 63;
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
  int stage_v_61_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (66 & 31);
  int stage_v_61_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (66 & 31);
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= (stage_v_61_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_61_2 << 1) & 127;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_62_1 = ((stage_v_62_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_62_2 = ((stage_v_62_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (68 & 31);
  int stage_v_63_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (68 & 31);
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= (stage_v_63_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_63_2 << 1) & 127;
  int stage_v_64_1 = table_1[0];
  int stage_v_64_2 = table_2[0];
  table_1[0] = (table_1[1] + 129) & 63;
  table_2[0] = (table_2[1] + 129) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (70 & 31);
  int stage_v_65_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (70 & 31);
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= (stage_v_65_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_65_2 << 1) & 127;
  int stage_v_66_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (71 & 31);
  int stage_v_66_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (71 & 31);
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= (stage_v_66_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_66_2 << 1) & 127;
  int stage_v_67_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_67_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_67_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_67_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_69_1 = ((stage_v_69_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_69_2 = ((stage_v_69_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 71) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 71) & 15;
  int stage_v_70_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_70_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  chk_sum_1 ^= stage_v_70_1;
  chk_sum_2 ^= stage_v_70_2;
  int stage_v_71_1 = (st_var_1_1.buffer[0] ^ 74) & 3;
  int stage_v_71_2 = (st_var_1_2.buffer[0] ^ 74) & 3;
  switch (stage_v_71_1)
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

  switch (stage_v_71_2)
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

  int stage_v_72_1 = ((st_var_0_1.buffer[0] * 2) + 223) & 63;
  int stage_v_72_2 = ((st_var_0_2.buffer[0] * 2) + 223) & 63;
  if (stage_v_72_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_72_1) - 5) & 255;
    if (stage_v_72_1 > 45)
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
  if (stage_v_72_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_72_2) - 5) & 255;
    if (stage_v_72_2 > 45)
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
  int stage_v_73_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_73_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_74_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (79 & 31);
  int stage_v_74_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (79 & 31);
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  chk_sum_1 ^= (stage_v_74_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_74_2 << 1) & 127;
  int stage_v_75_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_75_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 77) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 77) & 15;
  int stage_v_76_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_76_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  chk_sum_1 ^= stage_v_76_1;
  chk_sum_2 ^= stage_v_76_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 78) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 78) & 15;
  int stage_v_77_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_77_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= stage_v_77_1;
  chk_sum_2 ^= stage_v_77_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 79) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 79) & 15;
  int stage_v_78_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_78_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  chk_sum_1 ^= stage_v_78_1;
  chk_sum_2 ^= stage_v_78_2;
  int stage_v_79_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_79_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_79_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_79_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_80_1 = ((stage_v_80_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_80_2 = ((stage_v_80_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_81_1 = ((stage_v_81_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_81_2 = ((stage_v_81_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (87 & 31);
  int stage_v_82_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (87 & 31);
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  chk_sum_1 ^= (stage_v_82_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_82_2 << 1) & 127;
  int stage_v_83_1 = (st_var_1_1.buffer[0] ^ 86) & 3;
  int stage_v_83_2 = (st_var_1_2.buffer[0] ^ 86) & 3;
  switch (stage_v_83_1)
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

  switch (stage_v_83_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 85) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 85) & 15;
  int stage_v_84_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_84_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  chk_sum_1 ^= stage_v_84_1;
  chk_sum_2 ^= stage_v_84_2;
  int stage_v_85_1 = (st_var_1_1.buffer[0] ^ 88) & 3;
  int stage_v_85_2 = (st_var_1_2.buffer[0] ^ 88) & 3;
  switch (stage_v_85_1)
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

  switch (stage_v_85_2)
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

  int stage_v_86_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_86_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_86_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_86_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_87_1 = ((stage_v_87_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_87_2 = ((stage_v_87_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = table_1[0];
  int stage_v_88_2 = table_2[0];
  table_1[0] = (table_1[1] + 177) & 63;
  table_2[0] = (table_2[1] + 177) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_89_1 = ((stage_v_89_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_89_2 = ((stage_v_89_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_90_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_90_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_90_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_91_1 = (st_var_1_1.buffer[0] ^ 94) & 3;
  int stage_v_91_2 = (st_var_1_2.buffer[0] ^ 94) & 3;
  switch (stage_v_91_1)
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

  switch (stage_v_91_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 93) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 93) & 15;
  int stage_v_92_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_92_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  chk_sum_1 ^= stage_v_92_1;
  chk_sum_2 ^= stage_v_92_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 94) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 94) & 15;
  int stage_v_93_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_93_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  chk_sum_1 ^= stage_v_93_1;
  chk_sum_2 ^= stage_v_93_2;
  int stage_v_94_1 = ((((sec_r000444_6_1 * 3) + (sec_r000444_6_1 * 2)) - pub_r000444_3_1) + 13) & 127;
  int stage_v_94_2 = ((((sec_r000444_6_2 * 3) + (sec_r000444_6_2 * 2)) - pub_r000444_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_94_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_94_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((((stage_v_94_1 * 3) + (sec_r000444_8_1 * 2)) - pub_r000444_4_1) + 25) & 127;
  int stage_v_95_2 = ((((stage_v_94_2 * 3) + (sec_r000444_8_2 * 2)) - pub_r000444_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((((stage_v_94_1 * 3) + (sec_r000444_9_1 * 2)) - pub_r000444_20_1) + 26) & 127;
  int stage_v_96_2 = ((((stage_v_94_2 * 3) + (sec_r000444_9_2 * 2)) - pub_r000444_20_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((((stage_v_94_1 * 3) + (sec_r000444_9_1 * 2)) - pub_r000444_0_1) + 29) & 127;
  int stage_v_97_2 = ((((stage_v_94_2 * 3) + (sec_r000444_9_2 * 2)) - pub_r000444_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_97_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_97_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((((sec_r000444_11_1 * 3) + (sec_r000444_11_1 * 2)) - pub_r000444_11_1) + 15) & 127;
  int stage_v_98_2 = ((((sec_r000444_11_2 * 3) + (sec_r000444_11_2 * 2)) - pub_r000444_11_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((((stage_v_96_1 * 3) + (sec_r000444_0_1 * 2)) - pub_r000444_4_1) + 14) & 127;
  int stage_v_99_2 = ((((stage_v_96_2 * 3) + (sec_r000444_0_2 * 2)) - pub_r000444_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_99_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_99_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((((stage_v_96_1 * 3) + (sec_r000444_18_1 * 2)) - pub_r000444_16_1) + 24) & 127;
  int stage_v_100_2 = ((((stage_v_96_2 * 3) + (sec_r000444_18_2 * 2)) - pub_r000444_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_100_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_100_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((((stage_v_94_1 * 3) + (sec_r000444_1_1 * 2)) - pub_r000444_17_1) + 9) & 127;
  int stage_v_101_2 = ((((stage_v_94_2 * 3) + (sec_r000444_1_2 * 2)) - pub_r000444_17_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_101_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_101_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((((stage_v_98_1 * 3) + (sec_r000444_13_1 * 2)) - pub_r000444_9_1) + 30) & 127;
  int stage_v_102_2 = ((((stage_v_98_2 * 3) + (sec_r000444_13_2 * 2)) - pub_r000444_9_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((((stage_v_98_1 * 3) + (sec_r000444_15_1 * 2)) - pub_r000444_17_1) + 4) & 127;
  int stage_v_103_2 = ((((stage_v_98_2 * 3) + (sec_r000444_15_2 * 2)) - pub_r000444_17_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_103_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_103_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((((sec_r000444_7_1 * 3) + (sec_r000444_7_1 * 2)) - pub_r000444_21_1) + 16) & 127;
  int stage_v_104_2 = ((((sec_r000444_7_2 * 3) + (sec_r000444_7_2 * 2)) - pub_r000444_21_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((((stage_v_97_1 * 3) + (sec_r000444_15_1 * 2)) - pub_r000444_20_1) + 11) & 127;
  int stage_v_105_2 = ((((stage_v_97_2 * 3) + (sec_r000444_15_2 * 2)) - pub_r000444_20_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_105_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_105_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((((sec_r000444_9_1 * 3) + (sec_r000444_9_1 * 2)) - pub_r000444_16_1) + 30) & 127;
  int stage_v_106_2 = ((((sec_r000444_9_2 * 3) + (sec_r000444_9_2 * 2)) - pub_r000444_16_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((((sec_r000444_17_1 * 3) + (sec_r000444_17_1 * 2)) - pub_r000444_6_1) + 14) & 127;
  int stage_v_107_2 = ((((sec_r000444_17_2 * 3) + (sec_r000444_17_2 * 2)) - pub_r000444_6_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_107_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_107_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((((sec_r000444_5_1 * 3) + (sec_r000444_5_1 * 2)) - pub_r000444_8_1) + 21) & 127;
  int stage_v_108_2 = ((((sec_r000444_5_2 * 3) + (sec_r000444_5_2 * 2)) - pub_r000444_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((((sec_r000444_7_1 * 3) + (sec_r000444_7_1 * 2)) - pub_r000444_10_1) + 13) & 127;
  int stage_v_109_2 = ((((sec_r000444_7_2 * 3) + (sec_r000444_7_2 * 2)) - pub_r000444_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((((stage_v_97_1 * 3) + (sec_r000444_3_1 * 2)) - pub_r000444_20_1) + 5) & 127;
  int stage_v_110_2 = ((((stage_v_97_2 * 3) + (sec_r000444_3_2 * 2)) - pub_r000444_20_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_110_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_110_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((((sec_r000444_15_1 * 3) + (sec_r000444_15_1 * 2)) - pub_r000444_14_1) + 13) & 127;
  int stage_v_111_2 = ((((sec_r000444_15_2 * 3) + (sec_r000444_15_2 * 2)) - pub_r000444_14_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((((stage_v_107_1 * 3) + (sec_r000444_17_1 * 2)) - pub_r000444_14_1) + 26) & 127;
  int stage_v_112_2 = ((((stage_v_107_2 * 3) + (sec_r000444_17_2 * 2)) - pub_r000444_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((((stage_v_105_1 * 3) + (sec_r000444_4_1 * 2)) - pub_r000444_6_1) + 5) & 127;
  int stage_v_113_2 = ((((stage_v_105_2 * 3) + (sec_r000444_4_2 * 2)) - pub_r000444_6_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((((stage_v_94_1 * 3) + (sec_r000444_14_1 * 2)) - pub_r000444_17_1) + 27) & 127;
  int stage_v_114_2 = ((((stage_v_94_2 * 3) + (sec_r000444_14_2 * 2)) - pub_r000444_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((((stage_v_113_1 * 3) + (sec_r000444_12_1 * 2)) - pub_r000444_10_1) + 29) & 127;
  int stage_v_115_2 = ((((stage_v_113_2 * 3) + (sec_r000444_12_2 * 2)) - pub_r000444_10_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((((sec_r000444_7_1 * 3) + (sec_r000444_7_1 * 2)) - pub_r000444_12_1) + 3) & 127;
  int stage_v_116_2 = ((((sec_r000444_7_2 * 3) + (sec_r000444_7_2 * 2)) - pub_r000444_12_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((((stage_v_107_1 * 3) + (sec_r000444_18_1 * 2)) - pub_r000444_18_1) + 16) & 127;
  int stage_v_117_2 = ((((stage_v_107_2 * 3) + (sec_r000444_18_2 * 2)) - pub_r000444_18_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((((stage_v_117_1 * 3) + (sec_r000444_7_1 * 2)) - pub_r000444_0_1) + 33) & 127;
  int stage_v_118_2 = ((((stage_v_117_2 * 3) + (sec_r000444_7_2 * 2)) - pub_r000444_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((((stage_v_101_1 * 3) + (sec_r000444_12_1 * 2)) - pub_r000444_20_1) + 25) & 127;
  int stage_v_119_2 = ((((stage_v_101_2 * 3) + (sec_r000444_12_2 * 2)) - pub_r000444_20_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((((sec_r000444_3_1 * 3) + (sec_r000444_3_1 * 2)) - pub_r000444_14_1) + 33) & 127;
  int stage_v_120_2 = ((((sec_r000444_3_2 * 3) + (sec_r000444_3_2 * 2)) - pub_r000444_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((((stage_v_102_1 * 3) + (sec_r000444_8_1 * 2)) - pub_r000444_3_1) + 11) & 127;
  int stage_v_121_2 = ((((stage_v_102_2 * 3) + (sec_r000444_8_2 * 2)) - pub_r000444_3_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((((stage_v_100_1 * 3) + (sec_r000444_10_1 * 2)) - pub_r000444_16_1) + 18) & 127;
  int stage_v_122_2 = ((((stage_v_100_2 * 3) + (sec_r000444_10_2 * 2)) - pub_r000444_16_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((((stage_v_95_1 * 3) + (sec_r000444_12_1 * 2)) - pub_r000444_2_1) + 31) & 127;
  int stage_v_123_2 = ((((stage_v_95_2 * 3) + (sec_r000444_12_2 * 2)) - pub_r000444_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((((sec_r000444_17_1 * 3) + (sec_r000444_17_1 * 2)) - pub_r000444_15_1) + 19) & 127;
  int stage_v_124_2 = ((((sec_r000444_17_2 * 3) + (sec_r000444_17_2 * 2)) - pub_r000444_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((((stage_v_107_1 * 3) + (sec_r000444_18_1 * 2)) - pub_r000444_13_1) + 37) & 127;
  int stage_v_125_2 = ((((stage_v_107_2 * 3) + (sec_r000444_18_2 * 2)) - pub_r000444_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((((sec_r000444_16_1 * 3) + (sec_r000444_16_1 * 2)) - pub_r000444_2_1) + 4) & 127;
  int stage_v_126_2 = ((((sec_r000444_16_2 * 3) + (sec_r000444_16_2 * 2)) - pub_r000444_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((((stage_v_101_1 * 3) + (sec_r000444_17_1 * 2)) - pub_r000444_16_1) + 34) & 127;
  int stage_v_127_2 = ((((stage_v_101_2 * 3) + (sec_r000444_17_2 * 2)) - pub_r000444_16_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((((sec_r000444_10_1 * 3) + (sec_r000444_10_1 * 2)) - pub_r000444_18_1) + 21) & 127;
  int stage_v_128_2 = ((((sec_r000444_10_2 * 3) + (sec_r000444_10_2 * 2)) - pub_r000444_18_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((((stage_v_117_1 * 3) + (sec_r000444_13_1 * 2)) - pub_r000444_11_1) + 34) & 127;
  int stage_v_129_2 = ((((stage_v_117_2 * 3) + (sec_r000444_13_2 * 2)) - pub_r000444_11_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((((stage_v_102_1 * 3) + (sec_r000444_10_1 * 2)) - pub_r000444_10_1) + 6) & 127;
  int stage_v_130_2 = ((((stage_v_102_2 * 3) + (sec_r000444_10_2 * 2)) - pub_r000444_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((((sec_r000444_7_1 * 3) + (sec_r000444_7_1 * 2)) - pub_r000444_13_1) + 27) & 127;
  int stage_v_131_2 = ((((sec_r000444_7_2 * 3) + (sec_r000444_7_2 * 2)) - pub_r000444_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_131_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_131_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((((sec_r000444_7_1 * 3) + (sec_r000444_7_1 * 2)) - pub_r000444_17_1) + 33) & 127;
  int stage_v_132_2 = ((((sec_r000444_7_2 * 3) + (sec_r000444_7_2 * 2)) - pub_r000444_17_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((((sec_r000444_13_1 * 3) + (sec_r000444_13_1 * 2)) - pub_r000444_3_1) + 26) & 127;
  int stage_v_133_2 = ((((sec_r000444_13_2 * 3) + (sec_r000444_13_2 * 2)) - pub_r000444_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((((stage_v_133_1 * 3) + (sec_r000444_1_1 * 2)) - pub_r000444_0_1) + 14) & 127;
  int stage_v_134_2 = ((((stage_v_133_2 * 3) + (sec_r000444_1_2 * 2)) - pub_r000444_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_134_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_134_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((((stage_v_125_1 * 3) + (sec_r000444_4_1 * 2)) - pub_r000444_3_1) + 37) & 127;
  int stage_v_135_2 = ((((stage_v_125_2 * 3) + (sec_r000444_4_2 * 2)) - pub_r000444_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_135_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_135_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((((stage_v_130_1 * 3) + (sec_r000444_18_1 * 2)) - pub_r000444_4_1) + 35) & 127;
  int stage_v_136_2 = ((((stage_v_130_2 * 3) + (sec_r000444_18_2 * 2)) - pub_r000444_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((((stage_v_121_1 * 3) + (sec_r000444_13_1 * 2)) - pub_r000444_6_1) + 15) & 127;
  int stage_v_137_2 = ((((stage_v_121_2 * 3) + (sec_r000444_13_2 * 2)) - pub_r000444_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((((stage_v_100_1 * 3) + (sec_r000444_0_1 * 2)) - pub_r000444_6_1) + 25) & 127;
  int stage_v_138_2 = ((((stage_v_100_2 * 3) + (sec_r000444_0_2 * 2)) - pub_r000444_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((((stage_v_135_1 * 3) + (sec_r000444_10_1 * 2)) - pub_r000444_16_1) + 34) & 127;
  int stage_v_139_2 = ((((stage_v_135_2 * 3) + (sec_r000444_10_2 * 2)) - pub_r000444_16_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((((stage_v_119_1 * 3) + (sec_r000444_13_1 * 2)) - pub_r000444_18_1) + 36) & 127;
  int stage_v_140_2 = ((((stage_v_119_2 * 3) + (sec_r000444_13_2 * 2)) - pub_r000444_18_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((((stage_v_113_1 * 3) + (sec_r000444_5_1 * 2)) - pub_r000444_5_1) + 13) & 127;
  int stage_v_141_2 = ((((stage_v_113_2 * 3) + (sec_r000444_5_2 * 2)) - pub_r000444_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((((stage_v_141_1 * 3) + (sec_r000444_2_1 * 2)) - pub_r000444_15_1) + 6) & 127;
  int stage_v_142_2 = ((((stage_v_141_2 * 3) + (sec_r000444_2_2 * 2)) - pub_r000444_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((((stage_v_107_1 * 3) + (sec_r000444_1_1 * 2)) - pub_r000444_17_1) + 24) & 127;
  int stage_v_143_2 = ((((stage_v_107_2 * 3) + (sec_r000444_1_2 * 2)) - pub_r000444_17_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((((sec_r000444_17_1 * 3) + (sec_r000444_17_1 * 2)) - pub_r000444_2_1) + 25) & 127;
  int stage_v_144_2 = ((((sec_r000444_17_2 * 3) + (sec_r000444_17_2 * 2)) - pub_r000444_2_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((((stage_v_140_1 * 3) + (sec_r000444_15_1 * 2)) - pub_r000444_21_1) + 30) & 127;
  int stage_v_145_2 = ((((stage_v_140_2 * 3) + (sec_r000444_15_2 * 2)) - pub_r000444_21_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((((stage_v_105_1 * 3) + (sec_r000444_17_1 * 2)) - pub_r000444_5_1) + 19) & 127;
  int stage_v_146_2 = ((((stage_v_105_2 * 3) + (sec_r000444_17_2 * 2)) - pub_r000444_5_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((((sec_r000444_9_1 * 3) + (sec_r000444_9_1 * 2)) - pub_r000444_7_1) + 7) & 127;
  int stage_v_147_2 = ((((sec_r000444_9_2 * 3) + (sec_r000444_9_2 * 2)) - pub_r000444_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((((stage_v_140_1 * 3) + (sec_r000444_0_1 * 2)) - pub_r000444_16_1) + 16) & 127;
  int stage_v_148_2 = ((((stage_v_140_2 * 3) + (sec_r000444_0_2 * 2)) - pub_r000444_16_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((((stage_v_97_1 * 3) + (sec_r000444_0_1 * 2)) - pub_r000444_9_1) + 36) & 127;
  int stage_v_149_2 = ((((stage_v_97_2 * 3) + (sec_r000444_0_2 * 2)) - pub_r000444_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((((stage_v_116_1 * 3) + (sec_r000444_11_1 * 2)) - pub_r000444_12_1) + 23) & 127;
  int stage_v_150_2 = ((((stage_v_116_2 * 3) + (sec_r000444_11_2 * 2)) - pub_r000444_12_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((((stage_v_139_1 * 3) + (sec_r000444_8_1 * 2)) - pub_r000444_19_1) + 6) & 127;
  int stage_v_151_2 = ((((stage_v_139_2 * 3) + (sec_r000444_8_2 * 2)) - pub_r000444_19_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((((stage_v_124_1 * 3) + (sec_r000444_9_1 * 2)) - pub_r000444_7_1) + 15) & 127;
  int stage_v_152_2 = ((((stage_v_124_2 * 3) + (sec_r000444_9_2 * 2)) - pub_r000444_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((((stage_v_100_1 * 3) + (sec_r000444_6_1 * 2)) - pub_r000444_2_1) + 36) & 127;
  int stage_v_153_2 = ((((stage_v_100_2 * 3) + (sec_r000444_6_2 * 2)) - pub_r000444_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((((sec_r000444_5_1 * 3) + (sec_r000444_5_1 * 2)) - pub_r000444_20_1) + 31) & 127;
  int stage_v_154_2 = ((((sec_r000444_5_2 * 3) + (sec_r000444_5_2 * 2)) - pub_r000444_20_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((((stage_v_96_1 * 3) + (sec_r000444_4_1 * 2)) - pub_r000444_19_1) + 4) & 127;
  int stage_v_155_2 = ((((stage_v_96_2 * 3) + (sec_r000444_4_2 * 2)) - pub_r000444_19_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((((stage_v_127_1 * 3) + (sec_r000444_11_1 * 2)) - pub_r000444_2_1) + 24) & 127;
  int stage_v_156_2 = ((((stage_v_127_2 * 3) + (sec_r000444_11_2 * 2)) - pub_r000444_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_156_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_156_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((((stage_v_99_1 * 3) + (sec_r000444_15_1 * 2)) - pub_r000444_16_1) + 3) & 127;
  int stage_v_157_2 = ((((stage_v_99_2 * 3) + (sec_r000444_15_2 * 2)) - pub_r000444_16_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((((sec_r000444_16_1 * 3) + (sec_r000444_16_1 * 2)) - pub_r000444_4_1) + 4) & 127;
  int stage_v_158_2 = ((((sec_r000444_16_2 * 3) + (sec_r000444_16_2 * 2)) - pub_r000444_4_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((((stage_v_153_1 * 3) + (sec_r000444_0_1 * 2)) - pub_r000444_12_1) + 15) & 127;
  int stage_v_159_2 = ((((stage_v_153_2 * 3) + (sec_r000444_0_2 * 2)) - pub_r000444_12_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((((stage_v_131_1 * 3) + (sec_r000444_9_1 * 2)) - pub_r000444_1_1) + 8) & 127;
  int stage_v_160_2 = ((((stage_v_131_2 * 3) + (sec_r000444_9_2 * 2)) - pub_r000444_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_160_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_160_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((((stage_v_110_1 * 3) + (sec_r000444_8_1 * 2)) - pub_r000444_6_1) + 17) & 127;
  int stage_v_161_2 = ((((stage_v_110_2 * 3) + (sec_r000444_8_2 * 2)) - pub_r000444_6_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((((stage_v_161_1 * 3) + (sec_r000444_3_1 * 2)) - pub_r000444_2_1) + 8) & 127;
  int stage_v_162_2 = ((((stage_v_161_2 * 3) + (sec_r000444_3_2 * 2)) - pub_r000444_2_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((((stage_v_115_1 * 3) + (sec_r000444_11_1 * 2)) - pub_r000444_6_1) + 23) & 127;
  int stage_v_163_2 = ((((stage_v_115_2 * 3) + (sec_r000444_11_2 * 2)) - pub_r000444_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((((stage_v_96_1 * 3) + (sec_r000444_3_1 * 2)) - pub_r000444_4_1) + 3) & 127;
  int stage_v_164_2 = ((((stage_v_96_2 * 3) + (sec_r000444_3_2 * 2)) - pub_r000444_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((((sec_r000444_18_1 * 3) + (sec_r000444_18_1 * 2)) - pub_r000444_2_1) + 31) & 127;
  int stage_v_165_2 = ((((sec_r000444_18_2 * 3) + (sec_r000444_18_2 * 2)) - pub_r000444_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((((stage_v_134_1 * 3) + (sec_r000444_17_1 * 2)) - pub_r000444_3_1) + 34) & 127;
  int stage_v_166_2 = ((((stage_v_134_2 * 3) + (sec_r000444_17_2 * 2)) - pub_r000444_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((((stage_v_116_1 * 3) + (sec_r000444_15_1 * 2)) - pub_r000444_20_1) + 25) & 127;
  int stage_v_167_2 = ((((stage_v_116_2 * 3) + (sec_r000444_15_2 * 2)) - pub_r000444_20_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((((sec_r000444_0_1 * 3) + (sec_r000444_0_1 * 2)) - pub_r000444_18_1) + 13) & 127;
  int stage_v_168_2 = ((((sec_r000444_0_2 * 3) + (sec_r000444_0_2 * 2)) - pub_r000444_18_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((((sec_r000444_6_1 * 3) + (sec_r000444_6_1 * 2)) - pub_r000444_20_1) + 23) & 127;
  int stage_v_169_2 = ((((sec_r000444_6_2 * 3) + (sec_r000444_6_2 * 2)) - pub_r000444_20_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((((stage_v_132_1 * 3) + (sec_r000444_5_1 * 2)) - pub_r000444_11_1) + 16) & 127;
  int stage_v_170_2 = ((((stage_v_132_2 * 3) + (sec_r000444_5_2 * 2)) - pub_r000444_11_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((((sec_r000444_12_1 * 3) + (sec_r000444_12_1 * 2)) - pub_r000444_9_1) + 36) & 127;
  int stage_v_171_2 = ((((sec_r000444_12_2 * 3) + (sec_r000444_12_2 * 2)) - pub_r000444_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((((stage_v_142_1 * 3) + (sec_r000444_9_1 * 2)) - pub_r000444_21_1) + 3) & 127;
  int stage_v_172_2 = ((((stage_v_142_2 * 3) + (sec_r000444_9_2 * 2)) - pub_r000444_21_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((((stage_v_108_1 * 3) + (sec_r000444_5_1 * 2)) - pub_r000444_19_1) + 16) & 127;
  int stage_v_173_2 = ((((stage_v_108_2 * 3) + (sec_r000444_5_2 * 2)) - pub_r000444_19_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((((sec_r000444_6_1 * 3) + (sec_r000444_6_1 * 2)) - pub_r000444_20_1) + 13) & 127;
  int stage_v_174_2 = ((((sec_r000444_6_2 * 3) + (sec_r000444_6_2 * 2)) - pub_r000444_20_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_174_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_174_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((((stage_v_105_1 * 3) + (sec_r000444_17_1 * 2)) - pub_r000444_18_1) + 17) & 127;
  int stage_v_175_2 = ((((stage_v_105_2 * 3) + (sec_r000444_17_2 * 2)) - pub_r000444_18_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_175_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_175_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((((stage_v_113_1 * 3) + (sec_r000444_14_1 * 2)) - pub_r000444_6_1) + 9) & 127;
  int stage_v_176_2 = ((((stage_v_113_2 * 3) + (sec_r000444_14_2 * 2)) - pub_r000444_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_176_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_176_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((((stage_v_96_1 * 3) + (sec_r000444_12_1 * 2)) - pub_r000444_21_1) + 19) & 127;
  int stage_v_177_2 = ((((stage_v_96_2 * 3) + (sec_r000444_12_2 * 2)) - pub_r000444_21_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_177_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_177_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((((stage_v_106_1 * 3) + (sec_r000444_15_1 * 2)) - pub_r000444_10_1) + 37) & 127;
  int stage_v_178_2 = ((((stage_v_106_2 * 3) + (sec_r000444_15_2 * 2)) - pub_r000444_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_178_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_178_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((((sec_r000444_9_1 * 3) + (sec_r000444_9_1 * 2)) - pub_r000444_9_1) + 29) & 127;
  int stage_v_179_2 = ((((sec_r000444_9_2 * 3) + (sec_r000444_9_2 * 2)) - pub_r000444_9_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((((stage_v_130_1 * 3) + (sec_r000444_10_1 * 2)) - pub_r000444_15_1) + 12) & 127;
  int stage_v_180_2 = ((((stage_v_130_2 * 3) + (sec_r000444_10_2 * 2)) - pub_r000444_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_180_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_180_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((((stage_v_112_1 * 3) + (sec_r000444_11_1 * 2)) - pub_r000444_17_1) + 3) & 127;
  int stage_v_181_2 = ((((stage_v_112_2 * 3) + (sec_r000444_11_2 * 2)) - pub_r000444_17_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_181_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_181_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((((stage_v_107_1 * 3) + (sec_r000444_17_1 * 2)) - pub_r000444_11_1) + 19) & 127;
  int stage_v_182_2 = ((((stage_v_107_2 * 3) + (sec_r000444_17_2 * 2)) - pub_r000444_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_182_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_182_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((((stage_v_120_1 * 3) + (sec_r000444_14_1 * 2)) - pub_r000444_5_1) + 34) & 127;
  int stage_v_183_2 = ((((stage_v_120_2 * 3) + (sec_r000444_14_2 * 2)) - pub_r000444_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((((sec_r000444_9_1 * 3) + (sec_r000444_9_1 * 2)) - pub_r000444_2_1) + 35) & 127;
  int stage_v_184_2 = ((((sec_r000444_9_2 * 3) + (sec_r000444_9_2 * 2)) - pub_r000444_2_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_184_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_184_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((((sec_r000444_2_1 * 3) + (sec_r000444_2_1 * 2)) - pub_r000444_0_1) + 6) & 127;
  int stage_v_185_2 = ((((sec_r000444_2_2 * 3) + (sec_r000444_2_2 * 2)) - pub_r000444_0_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_185_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_185_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((((sec_r000444_3_1 * 3) + (sec_r000444_3_1 * 2)) - pub_r000444_1_1) + 36) & 127;
  int stage_v_186_2 = ((((sec_r000444_3_2 * 3) + (sec_r000444_3_2 * 2)) - pub_r000444_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_186_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_186_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((((stage_v_127_1 * 3) + (sec_r000444_9_1 * 2)) - pub_r000444_4_1) + 12) & 127;
  int stage_v_187_2 = ((((stage_v_127_2 * 3) + (sec_r000444_9_2 * 2)) - pub_r000444_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_187_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_187_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((((sec_r000444_5_1 * 3) + (sec_r000444_5_1 * 2)) - pub_r000444_1_1) + 20) & 127;
  int stage_v_188_2 = ((((sec_r000444_5_2 * 3) + (sec_r000444_5_2 * 2)) - pub_r000444_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_188_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_188_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((((stage_v_132_1 * 3) + (sec_r000444_8_1 * 2)) - pub_r000444_8_1) + 15) & 127;
  int stage_v_189_2 = ((((stage_v_132_2 * 3) + (sec_r000444_8_2 * 2)) - pub_r000444_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_189_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_189_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((((stage_v_108_1 * 3) + (sec_r000444_6_1 * 2)) - pub_r000444_7_1) + 15) & 127;
  int stage_v_190_2 = ((((stage_v_108_2 * 3) + (sec_r000444_6_2 * 2)) - pub_r000444_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_190_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_190_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((((stage_v_150_1 * 3) + (sec_r000444_16_1 * 2)) - pub_r000444_9_1) + 28) & 127;
  int stage_v_191_2 = ((((stage_v_150_2 * 3) + (sec_r000444_16_2 * 2)) - pub_r000444_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((((stage_v_150_1 * 3) + (sec_r000444_9_1 * 2)) - pub_r000444_2_1) + 16) & 127;
  int stage_v_192_2 = ((((stage_v_150_2 * 3) + (sec_r000444_9_2 * 2)) - pub_r000444_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_192_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_192_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((((sec_r000444_6_1 * 3) + (sec_r000444_6_1 * 2)) - pub_r000444_1_1) + 13) & 127;
  int stage_v_193_2 = ((((sec_r000444_6_2 * 3) + (sec_r000444_6_2 * 2)) - pub_r000444_1_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_193_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_193_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((((stage_v_154_1 * 3) + (sec_r000444_8_1 * 2)) - pub_r000444_2_1) + 32) & 127;
  int stage_v_194_2 = ((((stage_v_154_2 * 3) + (sec_r000444_8_2 * 2)) - pub_r000444_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_194_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_194_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((((sec_r000444_5_1 * 3) + (sec_r000444_5_1 * 2)) - pub_r000444_5_1) + 21) & 127;
  int stage_v_195_2 = ((((sec_r000444_5_2 * 3) + (sec_r000444_5_2 * 2)) - pub_r000444_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_195_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_195_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((((stage_v_114_1 * 3) + (sec_r000444_18_1 * 2)) - pub_r000444_12_1) + 18) & 127;
  int stage_v_196_2 = ((((stage_v_114_2 * 3) + (sec_r000444_18_2 * 2)) - pub_r000444_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_196_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_196_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((((stage_v_96_1 * 3) + (sec_r000444_8_1 * 2)) - pub_r000444_14_1) + 21) & 127;
  int stage_v_197_2 = ((((stage_v_96_2 * 3) + (sec_r000444_8_2 * 2)) - pub_r000444_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_197_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_197_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((((stage_v_101_1 * 3) + (sec_r000444_16_1 * 2)) - pub_r000444_7_1) + 25) & 127;
  int stage_v_198_2 = ((((stage_v_101_2 * 3) + (sec_r000444_16_2 * 2)) - pub_r000444_7_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_198_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_198_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((((stage_v_183_1 * 3) + (sec_r000444_2_1 * 2)) - pub_r000444_1_1) + 11) & 127;
  int stage_v_199_2 = ((((stage_v_183_2 * 3) + (sec_r000444_2_2 * 2)) - pub_r000444_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_199_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_199_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((((sec_r000444_17_1 * 3) + (sec_r000444_17_1 * 2)) - pub_r000444_12_1) + 37) & 127;
  int stage_v_200_2 = ((((sec_r000444_17_2 * 3) + (sec_r000444_17_2 * 2)) - pub_r000444_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_200_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_200_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((((stage_v_126_1 * 3) + (sec_r000444_15_1 * 2)) - pub_r000444_5_1) + 4) & 127;
  int stage_v_201_2 = ((((stage_v_126_2 * 3) + (sec_r000444_15_2 * 2)) - pub_r000444_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_201_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_201_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((((sec_r000444_16_1 * 3) + (sec_r000444_16_1 * 2)) - pub_r000444_18_1) + 14) & 127;
  int stage_v_202_2 = ((((sec_r000444_16_2 * 3) + (sec_r000444_16_2 * 2)) - pub_r000444_18_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_202_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_202_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((((stage_v_136_1 * 3) + (sec_r000444_6_1 * 2)) - pub_r000444_16_1) + 25) & 127;
  int stage_v_203_2 = ((((stage_v_136_2 * 3) + (sec_r000444_6_2 * 2)) - pub_r000444_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_203_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_203_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((((stage_v_109_1 * 3) + (sec_r000444_4_1 * 2)) - pub_r000444_7_1) + 34) & 127;
  int stage_v_204_2 = ((((stage_v_109_2 * 3) + (sec_r000444_4_2 * 2)) - pub_r000444_7_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_204_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_204_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((((stage_v_104_1 * 3) + (sec_r000444_14_1 * 2)) - pub_r000444_20_1) + 31) & 127;
  int stage_v_205_2 = ((((stage_v_104_2 * 3) + (sec_r000444_14_2 * 2)) - pub_r000444_20_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_205_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_205_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((((stage_v_155_1 * 3) + (sec_r000444_2_1 * 2)) - pub_r000444_5_1) + 4) & 127;
  int stage_v_206_2 = ((((stage_v_155_2 * 3) + (sec_r000444_2_2 * 2)) - pub_r000444_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_206_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_206_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((((stage_v_204_1 * 3) + (sec_r000444_18_1 * 2)) - pub_r000444_18_1) + 25) & 127;
  int stage_v_207_2 = ((((stage_v_204_2 * 3) + (sec_r000444_18_2 * 2)) - pub_r000444_18_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_207_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_207_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((((stage_v_113_1 * 3) + (sec_r000444_7_1 * 2)) - pub_r000444_4_1) + 35) & 127;
  int stage_v_208_2 = ((((stage_v_113_2 * 3) + (sec_r000444_7_2 * 2)) - pub_r000444_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_208_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_208_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((((stage_v_157_1 * 3) + (sec_r000444_7_1 * 2)) - pub_r000444_13_1) + 29) & 127;
  int stage_v_209_2 = ((((stage_v_157_2 * 3) + (sec_r000444_7_2 * 2)) - pub_r000444_13_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_209_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_209_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((((stage_v_196_1 * 3) + (sec_r000444_11_1 * 2)) - pub_r000444_19_1) + 3) & 127;
  int stage_v_210_2 = ((((stage_v_196_2 * 3) + (sec_r000444_11_2 * 2)) - pub_r000444_19_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_210_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_210_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((((stage_v_201_1 * 3) + (sec_r000444_7_1 * 2)) - pub_r000444_15_1) + 34) & 127;
  int stage_v_211_2 = ((((stage_v_201_2 * 3) + (sec_r000444_7_2 * 2)) - pub_r000444_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_211_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_211_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((((stage_v_174_1 * 3) + (sec_r000444_9_1 * 2)) - pub_r000444_18_1) + 21) & 127;
  int stage_v_212_2 = ((((stage_v_174_2 * 3) + (sec_r000444_9_2 * 2)) - pub_r000444_18_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_212_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_212_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((((sec_r000444_13_1 * 3) + (sec_r000444_13_1 * 2)) - pub_r000444_3_1) + 35) & 127;
  int stage_v_213_2 = ((((sec_r000444_13_2 * 3) + (sec_r000444_13_2 * 2)) - pub_r000444_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_213_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_213_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((((sec_r000444_7_1 * 3) + (sec_r000444_7_1 * 2)) - pub_r000444_8_1) + 31) & 127;
  int stage_v_214_2 = ((((sec_r000444_7_2 * 3) + (sec_r000444_7_2 * 2)) - pub_r000444_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_214_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_214_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((((stage_v_122_1 * 3) + (sec_r000444_6_1 * 2)) - pub_r000444_18_1) + 15) & 127;
  int stage_v_215_2 = ((((stage_v_122_2 * 3) + (sec_r000444_6_2 * 2)) - pub_r000444_18_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_215_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_215_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((((stage_v_200_1 * 3) + (sec_r000444_8_1 * 2)) - pub_r000444_10_1) + 36) & 127;
  int stage_v_216_2 = ((((stage_v_200_2 * 3) + (sec_r000444_8_2 * 2)) - pub_r000444_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_216_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_216_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((((sec_r000444_1_1 * 3) + (sec_r000444_1_1 * 2)) - pub_r000444_1_1) + 36) & 127;
  int stage_v_217_2 = ((((sec_r000444_1_2 * 3) + (sec_r000444_1_2 * 2)) - pub_r000444_1_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_217_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_217_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((((sec_r000444_1_1 * 3) + (sec_r000444_1_1 * 2)) - pub_r000444_9_1) + 37) & 127;
  int stage_v_218_2 = ((((sec_r000444_1_2 * 3) + (sec_r000444_1_2 * 2)) - pub_r000444_9_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_218_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_218_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((((sec_r000444_17_1 * 3) + (sec_r000444_17_1 * 2)) - pub_r000444_15_1) + 8) & 127;
  int stage_v_219_2 = ((((sec_r000444_17_2 * 3) + (sec_r000444_17_2 * 2)) - pub_r000444_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_219_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_219_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((((stage_v_215_1 * 3) + (sec_r000444_8_1 * 2)) - pub_r000444_10_1) + 23) & 127;
  int stage_v_220_2 = ((((stage_v_215_2 * 3) + (sec_r000444_8_2 * 2)) - pub_r000444_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_220_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_220_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((((stage_v_165_1 * 3) + (sec_r000444_14_1 * 2)) - pub_r000444_5_1) + 28) & 127;
  int stage_v_221_2 = ((((stage_v_165_2 * 3) + (sec_r000444_14_2 * 2)) - pub_r000444_5_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_221_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_221_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((((stage_v_113_1 * 3) + (sec_r000444_16_1 * 2)) - pub_r000444_5_1) + 21) & 127;
  int stage_v_222_2 = ((((stage_v_113_2 * 3) + (sec_r000444_16_2 * 2)) - pub_r000444_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_222_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_222_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((((stage_v_138_1 * 3) + (sec_r000444_9_1 * 2)) - pub_r000444_3_1) + 11) & 127;
  int stage_v_223_2 = ((((stage_v_138_2 * 3) + (sec_r000444_9_2 * 2)) - pub_r000444_3_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_223_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_223_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((((sec_r000444_13_1 * 3) + (sec_r000444_13_1 * 2)) - pub_r000444_11_1) + 20) & 127;
  int stage_v_224_2 = ((((sec_r000444_13_2 * 3) + (sec_r000444_13_2 * 2)) - pub_r000444_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_224_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_224_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((((sec_r000444_1_1 * 3) + (sec_r000444_1_1 * 2)) - pub_r000444_10_1) + 27) & 127;
  int stage_v_225_2 = ((((sec_r000444_1_2 * 3) + (sec_r000444_1_2 * 2)) - pub_r000444_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_225_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_225_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((((sec_r000444_16_1 * 3) + (sec_r000444_16_1 * 2)) - pub_r000444_11_1) + 34) & 127;
  int stage_v_226_2 = ((((sec_r000444_16_2 * 3) + (sec_r000444_16_2 * 2)) - pub_r000444_11_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_226_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_226_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((((stage_v_171_1 * 3) + (sec_r000444_15_1 * 2)) - pub_r000444_2_1) + 21) & 127;
  int stage_v_227_2 = ((((stage_v_171_2 * 3) + (sec_r000444_15_2 * 2)) - pub_r000444_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_227_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_227_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((((sec_r000444_10_1 * 3) + (sec_r000444_10_1 * 2)) - pub_r000444_16_1) + 11) & 127;
  int stage_v_228_2 = ((((sec_r000444_10_2 * 3) + (sec_r000444_10_2 * 2)) - pub_r000444_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_228_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_228_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((((stage_v_138_1 * 3) + (sec_r000444_10_1 * 2)) - pub_r000444_7_1) + 25) & 127;
  int stage_v_229_2 = ((((stage_v_138_2 * 3) + (sec_r000444_10_2 * 2)) - pub_r000444_7_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_229_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_229_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((((stage_v_188_1 * 3) + (sec_r000444_14_1 * 2)) - pub_r000444_4_1) + 22) & 127;
  int stage_v_230_2 = ((((stage_v_188_2 * 3) + (sec_r000444_14_2 * 2)) - pub_r000444_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_230_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_230_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((((stage_v_196_1 * 3) + (sec_r000444_4_1 * 2)) - pub_r000444_18_1) + 30) & 127;
  int stage_v_231_2 = ((((stage_v_196_2 * 3) + (sec_r000444_4_2 * 2)) - pub_r000444_18_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_231_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_231_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((((stage_v_173_1 * 3) + (sec_r000444_12_1 * 2)) - pub_r000444_16_1) + 9) & 127;
  int stage_v_232_2 = ((((stage_v_173_2 * 3) + (sec_r000444_12_2 * 2)) - pub_r000444_16_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_232_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_232_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((((stage_v_133_1 * 3) + (sec_r000444_9_1 * 2)) - pub_r000444_11_1) + 30) & 127;
  int stage_v_233_2 = ((((stage_v_133_2 * 3) + (sec_r000444_9_2 * 2)) - pub_r000444_11_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_233_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_233_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((((sec_r000444_4_1 * 3) + (sec_r000444_4_1 * 2)) - pub_r000444_2_1) + 17) & 127;
  int stage_v_234_2 = ((((sec_r000444_4_2 * 3) + (sec_r000444_4_2 * 2)) - pub_r000444_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_234_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_234_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((((stage_v_226_1 * 3) + (sec_r000444_17_1 * 2)) - pub_r000444_18_1) + 24) & 127;
  int stage_v_235_2 = ((((stage_v_226_2 * 3) + (sec_r000444_17_2 * 2)) - pub_r000444_18_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_235_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_235_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((((stage_v_173_1 * 3) + (sec_r000444_6_1 * 2)) - pub_r000444_16_1) + 11) & 127;
  int stage_v_236_2 = ((((stage_v_173_2 * 3) + (sec_r000444_6_2 * 2)) - pub_r000444_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_236_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_236_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((((stage_v_116_1 * 3) + (sec_r000444_1_1 * 2)) - pub_r000444_16_1) + 6) & 127;
  int stage_v_237_2 = ((((stage_v_116_2 * 3) + (sec_r000444_1_2 * 2)) - pub_r000444_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_237_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_237_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((((sec_r000444_14_1 * 3) + (sec_r000444_14_1 * 2)) - pub_r000444_9_1) + 21) & 127;
  int stage_v_238_2 = ((((sec_r000444_14_2 * 3) + (sec_r000444_14_2 * 2)) - pub_r000444_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_238_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_238_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((((sec_r000444_11_1 * 3) + (sec_r000444_11_1 * 2)) - pub_r000444_14_1) + 11) & 127;
  int stage_v_239_2 = ((((sec_r000444_11_2 * 3) + (sec_r000444_11_2 * 2)) - pub_r000444_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_239_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_239_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((((stage_v_174_1 * 3) + (sec_r000444_6_1 * 2)) - pub_r000444_2_1) + 32) & 127;
  int stage_v_240_2 = ((((stage_v_174_2 * 3) + (sec_r000444_6_2 * 2)) - pub_r000444_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_240_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_240_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((((stage_v_172_1 * 3) + (sec_r000444_0_1 * 2)) - pub_r000444_10_1) + 37) & 127;
  int stage_v_241_2 = ((((stage_v_172_2 * 3) + (sec_r000444_0_2 * 2)) - pub_r000444_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_241_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_241_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((((stage_v_104_1 * 3) + (sec_r000444_16_1 * 2)) - pub_r000444_15_1) + 9) & 127;
  int stage_v_242_2 = ((((stage_v_104_2 * 3) + (sec_r000444_16_2 * 2)) - pub_r000444_15_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_242_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_242_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((((stage_v_216_1 * 3) + (sec_r000444_2_1 * 2)) - pub_r000444_19_1) + 22) & 127;
  int stage_v_243_2 = ((((stage_v_216_2 * 3) + (sec_r000444_2_2 * 2)) - pub_r000444_19_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_243_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_243_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((((stage_v_131_1 * 3) + (sec_r000444_8_1 * 2)) - pub_r000444_12_1) + 37) & 127;
  int stage_v_244_2 = ((((stage_v_131_2 * 3) + (sec_r000444_8_2 * 2)) - pub_r000444_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_244_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_244_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((((stage_v_196_1 * 3) + (sec_r000444_15_1 * 2)) - pub_r000444_3_1) + 29) & 127;
  int stage_v_245_2 = ((((stage_v_196_2 * 3) + (sec_r000444_15_2 * 2)) - pub_r000444_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_245_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_245_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((((stage_v_231_1 * 3) + (sec_r000444_6_1 * 2)) - pub_r000444_17_1) + 23) & 127;
  int stage_v_246_2 = ((((stage_v_231_2 * 3) + (sec_r000444_6_2 * 2)) - pub_r000444_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_246_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_246_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((((stage_v_178_1 * 3) + (sec_r000444_18_1 * 2)) - pub_r000444_12_1) + 24) & 127;
  int stage_v_247_2 = ((((stage_v_178_2 * 3) + (sec_r000444_18_2 * 2)) - pub_r000444_12_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_247_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_247_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((((stage_v_162_1 * 3) + (sec_r000444_16_1 * 2)) - pub_r000444_17_1) + 4) & 127;
  int stage_v_248_2 = ((((stage_v_162_2 * 3) + (sec_r000444_16_2 * 2)) - pub_r000444_17_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_248_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_248_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((((stage_v_213_1 * 3) + (sec_r000444_7_1 * 2)) - pub_r000444_13_1) + 34) & 127;
  int stage_v_249_2 = ((((stage_v_213_2 * 3) + (sec_r000444_7_2 * 2)) - pub_r000444_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_249_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_249_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((((stage_v_233_1 * 3) + (sec_r000444_10_1 * 2)) - pub_r000444_12_1) + 15) & 127;
  int stage_v_250_2 = ((((stage_v_233_2 * 3) + (sec_r000444_10_2 * 2)) - pub_r000444_12_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_250_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_250_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((((stage_v_180_1 * 3) + (sec_r000444_0_1 * 2)) - pub_r000444_6_1) + 11) & 127;
  int stage_v_251_2 = ((((stage_v_180_2 * 3) + (sec_r000444_0_2 * 2)) - pub_r000444_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_251_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_251_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((((stage_v_211_1 * 3) + (sec_r000444_4_1 * 2)) - pub_r000444_11_1) + 9) & 127;
  int stage_v_252_2 = ((((stage_v_211_2 * 3) + (sec_r000444_4_2 * 2)) - pub_r000444_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_252_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_252_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((((sec_r000444_14_1 * 3) + (sec_r000444_14_1 * 2)) - pub_r000444_6_1) + 19) & 127;
  int stage_v_253_2 = ((((sec_r000444_14_2 * 3) + (sec_r000444_14_2 * 2)) - pub_r000444_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_253_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_253_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((((sec_r000444_15_1 * 3) + (sec_r000444_15_1 * 2)) - pub_r000444_3_1) + 19) & 127;
  int stage_v_254_2 = ((((sec_r000444_15_2 * 3) + (sec_r000444_15_2 * 2)) - pub_r000444_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_254_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_254_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((((sec_r000444_3_1 * 3) + (sec_r000444_3_1 * 2)) - pub_r000444_9_1) + 21) & 127;
  int stage_v_255_2 = ((((sec_r000444_3_2 * 3) + (sec_r000444_3_2 * 2)) - pub_r000444_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_255_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_255_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((((stage_v_143_1 * 3) + (sec_r000444_8_1 * 2)) - pub_r000444_20_1) + 29) & 127;
  int stage_v_256_2 = ((((stage_v_143_2 * 3) + (sec_r000444_8_2 * 2)) - pub_r000444_20_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_256_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_256_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((((sec_r000444_15_1 * 3) + (sec_r000444_15_1 * 2)) - pub_r000444_15_1) + 4) & 127;
  int stage_v_257_2 = ((((sec_r000444_15_2 * 3) + (sec_r000444_15_2 * 2)) - pub_r000444_15_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_257_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_257_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((((stage_v_231_1 * 3) + (sec_r000444_0_1 * 2)) - pub_r000444_2_1) + 14) & 127;
  int stage_v_258_2 = ((((stage_v_231_2 * 3) + (sec_r000444_0_2 * 2)) - pub_r000444_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_258_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_258_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((((stage_v_238_1 * 3) + (sec_r000444_18_1 * 2)) - pub_r000444_7_1) + 36) & 127;
  int stage_v_259_2 = ((((stage_v_238_2 * 3) + (sec_r000444_18_2 * 2)) - pub_r000444_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_259_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_259_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((((stage_v_162_1 * 3) + (sec_r000444_1_1 * 2)) - pub_r000444_14_1) + 17) & 127;
  int stage_v_260_2 = ((((stage_v_162_2 * 3) + (sec_r000444_1_2 * 2)) - pub_r000444_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_260_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_260_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((((sec_r000444_17_1 * 3) + (sec_r000444_17_1 * 2)) - pub_r000444_5_1) + 30) & 127;
  int stage_v_261_2 = ((((sec_r000444_17_2 * 3) + (sec_r000444_17_2 * 2)) - pub_r000444_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_261_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_261_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((((stage_v_120_1 * 3) + (sec_r000444_12_1 * 2)) - pub_r000444_8_1) + 33) & 127;
  int stage_v_262_2 = ((((stage_v_120_2 * 3) + (sec_r000444_12_2 * 2)) - pub_r000444_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_262_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_262_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((((stage_v_257_1 * 3) + (sec_r000444_18_1 * 2)) - pub_r000444_19_1) + 20) & 127;
  int stage_v_263_2 = ((((stage_v_257_2 * 3) + (sec_r000444_18_2 * 2)) - pub_r000444_19_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_263_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_263_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((((sec_r000444_15_1 * 3) + (sec_r000444_15_1 * 2)) - pub_r000444_1_1) + 19) & 127;
  int stage_v_264_2 = ((((sec_r000444_15_2 * 3) + (sec_r000444_15_2 * 2)) - pub_r000444_1_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_264_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_264_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((((sec_r000444_0_1 * 3) + (sec_r000444_0_1 * 2)) - pub_r000444_3_1) + 16) & 127;
  int stage_v_265_2 = ((((sec_r000444_0_2 * 3) + (sec_r000444_0_2 * 2)) - pub_r000444_3_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_265_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_265_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((((sec_r000444_14_1 * 3) + (sec_r000444_14_1 * 2)) - pub_r000444_6_1) + 13) & 127;
  int stage_v_266_2 = ((((sec_r000444_14_2 * 3) + (sec_r000444_14_2 * 2)) - pub_r000444_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_266_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_266_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((((sec_r000444_9_1 * 3) + (sec_r000444_9_1 * 2)) - pub_r000444_13_1) + 13) & 127;
  int stage_v_267_2 = ((((sec_r000444_9_2 * 3) + (sec_r000444_9_2 * 2)) - pub_r000444_13_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_267_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_267_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((((stage_v_237_1 * 3) + (sec_r000444_5_1 * 2)) - pub_r000444_14_1) + 31) & 127;
  int stage_v_268_2 = ((((stage_v_237_2 * 3) + (sec_r000444_5_2 * 2)) - pub_r000444_14_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_268_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_268_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((((stage_v_205_1 * 3) + (sec_r000444_7_1 * 2)) - pub_r000444_11_1) + 9) & 127;
  int stage_v_269_2 = ((((stage_v_205_2 * 3) + (sec_r000444_7_2 * 2)) - pub_r000444_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_269_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_269_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((((stage_v_135_1 * 3) + (sec_r000444_4_1 * 2)) - pub_r000444_12_1) + 28) & 127;
  int stage_v_270_2 = ((((stage_v_135_2 * 3) + (sec_r000444_4_2 * 2)) - pub_r000444_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_270_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_270_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((((stage_v_182_1 * 3) + (sec_r000444_16_1 * 2)) - pub_r000444_3_1) + 36) & 127;
  int stage_v_271_2 = ((((stage_v_182_2 * 3) + (sec_r000444_16_2 * 2)) - pub_r000444_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_271_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_271_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((((stage_v_163_1 * 3) + (sec_r000444_14_1 * 2)) - pub_r000444_21_1) + 21) & 127;
  int stage_v_272_2 = ((((stage_v_163_2 * 3) + (sec_r000444_14_2 * 2)) - pub_r000444_21_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_272_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_272_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((((stage_v_135_1 * 3) + (sec_r000444_7_1 * 2)) - pub_r000444_6_1) + 26) & 127;
  int stage_v_273_2 = ((((stage_v_135_2 * 3) + (sec_r000444_7_2 * 2)) - pub_r000444_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_273_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_273_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((((stage_v_188_1 * 3) + (sec_r000444_12_1 * 2)) - pub_r000444_14_1) + 30) & 127;
  int stage_v_274_2 = ((((stage_v_188_2 * 3) + (sec_r000444_12_2 * 2)) - pub_r000444_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_274_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_274_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((((stage_v_103_1 * 3) + (sec_r000444_10_1 * 2)) - pub_r000444_0_1) + 13) & 127;
  int stage_v_275_2 = ((((stage_v_103_2 * 3) + (sec_r000444_10_2 * 2)) - pub_r000444_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_275_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_275_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((((sec_r000444_14_1 * 3) + (sec_r000444_14_1 * 2)) - pub_r000444_17_1) + 25) & 127;
  int stage_v_276_2 = ((((sec_r000444_14_2 * 3) + (sec_r000444_14_2 * 2)) - pub_r000444_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_276_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_276_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((((sec_r000444_16_1 * 3) + (sec_r000444_16_1 * 2)) - pub_r000444_7_1) + 25) & 127;
  int stage_v_277_2 = ((((sec_r000444_16_2 * 3) + (sec_r000444_16_2 * 2)) - pub_r000444_7_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_277_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_277_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((((sec_r000444_1_1 * 3) + (sec_r000444_1_1 * 2)) - pub_r000444_14_1) + 14) & 127;
  int stage_v_278_2 = ((((sec_r000444_1_2 * 3) + (sec_r000444_1_2 * 2)) - pub_r000444_14_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_278_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_278_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((((stage_v_174_1 * 3) + (sec_r000444_18_1 * 2)) - pub_r000444_20_1) + 34) & 127;
  int stage_v_279_2 = ((((stage_v_174_2 * 3) + (sec_r000444_18_2 * 2)) - pub_r000444_20_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_279_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_279_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((((sec_r000444_9_1 * 3) + (sec_r000444_9_1 * 2)) - pub_r000444_20_1) + 9) & 127;
  int stage_v_280_2 = ((((sec_r000444_9_2 * 3) + (sec_r000444_9_2 * 2)) - pub_r000444_20_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_280_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_280_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((((stage_v_98_1 * 3) + (sec_r000444_7_1 * 2)) - pub_r000444_16_1) + 22) & 127;
  int stage_v_281_2 = ((((stage_v_98_2 * 3) + (sec_r000444_7_2 * 2)) - pub_r000444_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_281_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_281_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((((stage_v_135_1 * 3) + (sec_r000444_1_1 * 2)) - pub_r000444_15_1) + 20) & 127;
  int stage_v_282_2 = ((((stage_v_135_2 * 3) + (sec_r000444_1_2 * 2)) - pub_r000444_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_282_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_282_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((((sec_r000444_18_1 * 3) + (sec_r000444_18_1 * 2)) - pub_r000444_15_1) + 16) & 127;
  int stage_v_283_2 = ((((sec_r000444_18_2 * 3) + (sec_r000444_18_2 * 2)) - pub_r000444_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_283_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_283_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((((stage_v_103_1 * 3) + (sec_r000444_0_1 * 2)) - pub_r000444_6_1) + 23) & 127;
  int stage_v_284_2 = ((((stage_v_103_2 * 3) + (sec_r000444_0_2 * 2)) - pub_r000444_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_284_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_284_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((((sec_r000444_15_1 * 3) + (sec_r000444_15_1 * 2)) - pub_r000444_0_1) + 22) & 127;
  int stage_v_285_2 = ((((sec_r000444_15_2 * 3) + (sec_r000444_15_2 * 2)) - pub_r000444_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_285_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_285_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((((stage_v_217_1 * 3) + (sec_r000444_1_1 * 2)) - pub_r000444_12_1) + 32) & 127;
  int stage_v_286_2 = ((((stage_v_217_2 * 3) + (sec_r000444_1_2 * 2)) - pub_r000444_12_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_286_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_286_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((((stage_v_173_1 * 3) + (sec_r000444_5_1 * 2)) - pub_r000444_20_1) + 26) & 127;
  int stage_v_287_2 = ((((stage_v_173_2 * 3) + (sec_r000444_5_2 * 2)) - pub_r000444_20_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_287_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_287_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((((stage_v_220_1 * 3) + (sec_r000444_15_1 * 2)) - pub_r000444_21_1) + 3) & 127;
  int stage_v_288_2 = ((((stage_v_220_2 * 3) + (sec_r000444_15_2 * 2)) - pub_r000444_21_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_288_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_288_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((((stage_v_190_1 * 3) + (sec_r000444_14_1 * 2)) - pub_r000444_20_1) + 36) & 127;
  int stage_v_289_2 = ((((stage_v_190_2 * 3) + (sec_r000444_14_2 * 2)) - pub_r000444_20_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_289_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_289_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((((sec_r000444_3_1 * 3) + (sec_r000444_3_1 * 2)) - pub_r000444_20_1) + 22) & 127;
  int stage_v_290_2 = ((((sec_r000444_3_2 * 3) + (sec_r000444_3_2 * 2)) - pub_r000444_20_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_290_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_290_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((((stage_v_241_1 * 3) + (sec_r000444_15_1 * 2)) - pub_r000444_11_1) + 9) & 127;
  int stage_v_291_2 = ((((stage_v_241_2 * 3) + (sec_r000444_15_2 * 2)) - pub_r000444_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_291_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_291_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((((stage_v_268_1 * 3) + (sec_r000444_18_1 * 2)) - pub_r000444_9_1) + 23) & 127;
  int stage_v_292_2 = ((((stage_v_268_2 * 3) + (sec_r000444_18_2 * 2)) - pub_r000444_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_292_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_292_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((((sec_r000444_16_1 * 3) + (sec_r000444_16_1 * 2)) - pub_r000444_19_1) + 18) & 127;
  int stage_v_293_2 = ((((sec_r000444_16_2 * 3) + (sec_r000444_16_2 * 2)) - pub_r000444_19_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_293_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_293_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((((sec_r000444_8_1 * 3) + (sec_r000444_8_1 * 2)) - pub_r000444_15_1) + 36) & 127;
  int stage_v_294_2 = ((((sec_r000444_8_2 * 3) + (sec_r000444_8_2 * 2)) - pub_r000444_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_294_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_294_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((((sec_r000444_16_1 * 3) + (sec_r000444_16_1 * 2)) - pub_r000444_5_1) + 7) & 127;
  int stage_v_295_2 = ((((sec_r000444_16_2 * 3) + (sec_r000444_16_2 * 2)) - pub_r000444_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_295_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_295_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((((stage_v_215_1 * 3) + (sec_r000444_2_1 * 2)) - pub_r000444_2_1) + 16) & 127;
  int stage_v_296_2 = ((((stage_v_215_2 * 3) + (sec_r000444_2_2 * 2)) - pub_r000444_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_296_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_296_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((((stage_v_263_1 * 3) + (sec_r000444_7_1 * 2)) - pub_r000444_11_1) + 6) & 127;
  int stage_v_297_2 = ((((stage_v_263_2 * 3) + (sec_r000444_7_2 * 2)) - pub_r000444_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_297_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_297_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int stage_v_298_1 = ((((stage_v_172_1 * 3) + (sec_r000444_3_1 * 2)) - pub_r000444_9_1) + 34) & 127;
  int stage_v_298_2 = ((((stage_v_172_2 * 3) + (sec_r000444_3_2 * 2)) - pub_r000444_9_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_298_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_298_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int stage_v_299_1 = ((((stage_v_266_1 * 3) + (sec_r000444_15_1 * 2)) - pub_r000444_8_1) + 19) & 127;
  int stage_v_299_2 = ((((stage_v_266_2 * 3) + (sec_r000444_15_2 * 2)) - pub_r000444_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_299_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_299_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int stage_v_300_1 = ((((sec_r000444_7_1 * 3) + (sec_r000444_7_1 * 2)) - pub_r000444_16_1) + 20) & 127;
  int stage_v_300_2 = ((((sec_r000444_7_2 * 3) + (sec_r000444_7_2 * 2)) - pub_r000444_16_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_300_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_300_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int stage_v_301_1 = ((((stage_v_283_1 * 3) + (sec_r000444_1_1 * 2)) - pub_r000444_6_1) + 3) & 127;
  int stage_v_301_2 = ((((stage_v_283_2 * 3) + (sec_r000444_1_2 * 2)) - pub_r000444_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_301_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_301_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int stage_v_302_1 = ((((sec_r000444_6_1 * 3) + (sec_r000444_6_1 * 2)) - pub_r000444_2_1) + 5) & 127;
  int stage_v_302_2 = ((((sec_r000444_6_2 * 3) + (sec_r000444_6_2 * 2)) - pub_r000444_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_302_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_302_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int stage_v_303_1 = ((((stage_v_295_1 * 3) + (sec_r000444_3_1 * 2)) - pub_r000444_0_1) + 30) & 127;
  int stage_v_303_2 = ((((stage_v_295_2 * 3) + (sec_r000444_3_2 * 2)) - pub_r000444_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_303_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_303_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int stage_v_304_1 = ((((stage_v_254_1 * 3) + (sec_r000444_10_1 * 2)) - pub_r000444_13_1) + 37) & 127;
  int stage_v_304_2 = ((((stage_v_254_2 * 3) + (sec_r000444_10_2 * 2)) - pub_r000444_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_304_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_304_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int stage_v_305_1 = ((((stage_v_255_1 * 3) + (sec_r000444_4_1 * 2)) - pub_r000444_20_1) + 32) & 127;
  int stage_v_305_2 = ((((stage_v_255_2 * 3) + (sec_r000444_4_2 * 2)) - pub_r000444_20_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_305_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_305_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  int stage_v_306_1 = ((((stage_v_216_1 * 3) + (sec_r000444_16_1 * 2)) - pub_r000444_12_1) + 26) & 127;
  int stage_v_306_2 = ((((stage_v_216_2 * 3) + (sec_r000444_16_2 * 2)) - pub_r000444_12_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_306_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_306_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_306_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_306_2) & 255;
  int stage_v_307_1 = ((((sec_r000444_18_1 * 3) + (sec_r000444_18_1 * 2)) - pub_r000444_18_1) + 6) & 127;
  int stage_v_307_2 = ((((sec_r000444_18_2 * 3) + (sec_r000444_18_2 * 2)) - pub_r000444_18_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_307_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_307_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_307_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_307_2) & 255;
  int stage_v_308_1 = ((((stage_v_156_1 * 3) + (sec_r000444_13_1 * 2)) - pub_r000444_10_1) + 32) & 127;
  int stage_v_308_2 = ((((stage_v_156_2 * 3) + (sec_r000444_13_2 * 2)) - pub_r000444_10_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_308_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_308_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_308_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_308_2) & 255;
  int stage_v_309_1 = ((((sec_r000444_12_1 * 3) + (sec_r000444_12_1 * 2)) - pub_r000444_9_1) + 29) & 127;
  int stage_v_309_2 = ((((sec_r000444_12_2 * 3) + (sec_r000444_12_2 * 2)) - pub_r000444_9_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_309_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_309_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_309_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_309_2) & 255;
  int stage_v_310_1 = ((((sec_r000444_4_1 * 3) + (sec_r000444_4_1 * 2)) - pub_r000444_7_1) + 20) & 127;
  int stage_v_310_2 = ((((sec_r000444_4_2 * 3) + (sec_r000444_4_2 * 2)) - pub_r000444_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_310_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_310_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_310_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_310_2) & 255;
  int stage_v_311_1 = ((((sec_r000444_9_1 * 3) + (sec_r000444_9_1 * 2)) - pub_r000444_8_1) + 12) & 127;
  int stage_v_311_2 = ((((sec_r000444_9_2 * 3) + (sec_r000444_9_2 * 2)) - pub_r000444_8_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_311_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_311_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_311_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_311_2) & 255;
  int stage_v_312_1 = ((((stage_v_202_1 * 3) + (sec_r000444_5_1 * 2)) - pub_r000444_19_1) + 24) & 127;
  int stage_v_312_2 = ((((stage_v_202_2 * 3) + (sec_r000444_5_2 * 2)) - pub_r000444_19_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_312_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_312_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_312_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_312_2) & 255;
  int stage_v_313_1 = ((((stage_v_192_1 * 3) + (sec_r000444_16_1 * 2)) - pub_r000444_13_1) + 25) & 127;
  int stage_v_313_2 = ((((stage_v_192_2 * 3) + (sec_r000444_16_2 * 2)) - pub_r000444_13_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_313_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_313_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_313_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_313_2) & 255;
  int stage_v_314_1 = ((((stage_v_270_1 * 3) + (sec_r000444_9_1 * 2)) - pub_r000444_6_1) + 17) & 127;
  int stage_v_314_2 = ((((stage_v_270_2 * 3) + (sec_r000444_9_2 * 2)) - pub_r000444_6_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_314_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_314_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_314_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_314_2) & 255;
  int stage_v_315_1 = ((((sec_r000444_18_1 * 3) + (sec_r000444_18_1 * 2)) - pub_r000444_17_1) + 7) & 127;
  int stage_v_315_2 = ((((sec_r000444_18_2 * 3) + (sec_r000444_18_2 * 2)) - pub_r000444_17_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_315_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_315_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_315_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_315_2) & 255;
  int stage_v_316_1 = ((((sec_r000444_4_1 * 3) + (sec_r000444_4_1 * 2)) - pub_r000444_12_1) + 9) & 127;
  int stage_v_316_2 = ((((sec_r000444_4_2 * 3) + (sec_r000444_4_2 * 2)) - pub_r000444_12_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_316_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_316_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_316_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_316_2) & 255;
  int stage_v_317_1 = ((((stage_v_261_1 * 3) + (sec_r000444_13_1 * 2)) - pub_r000444_16_1) + 21) & 127;
  int stage_v_317_2 = ((((stage_v_261_2 * 3) + (sec_r000444_13_2 * 2)) - pub_r000444_16_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_317_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_317_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_317_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_317_2) & 255;
  int stage_v_318_1 = ((((stage_v_278_1 * 3) + (sec_r000444_18_1 * 2)) - pub_r000444_12_1) + 6) & 127;
  int stage_v_318_2 = ((((stage_v_278_2 * 3) + (sec_r000444_18_2 * 2)) - pub_r000444_12_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_318_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_318_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_318_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_318_2) & 255;
  int stage_v_319_1 = ((((sec_r000444_6_1 * 3) + (sec_r000444_6_1 * 2)) - pub_r000444_0_1) + 19) & 127;
  int stage_v_319_2 = ((((sec_r000444_6_2 * 3) + (sec_r000444_6_2 * 2)) - pub_r000444_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_319_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_319_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_319_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_319_2) & 255;
  int stage_v_320_1 = ((((stage_v_266_1 * 3) + (sec_r000444_5_1 * 2)) - pub_r000444_1_1) + 35) & 127;
  int stage_v_320_2 = ((((stage_v_266_2 * 3) + (sec_r000444_5_2 * 2)) - pub_r000444_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_320_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_320_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_320_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_320_2) & 255;
  int stage_v_321_1 = ((((sec_r000444_16_1 * 3) + (sec_r000444_16_1 * 2)) - pub_r000444_6_1) + 18) & 127;
  int stage_v_321_2 = ((((sec_r000444_16_2 * 3) + (sec_r000444_16_2 * 2)) - pub_r000444_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_321_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_321_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_321_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_321_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000444_4_1 != sec_r000444_4_2);
  __CPROVER_assume(pub_r000444_4_1 == pub_r000444_4_2);
  __CPROVER_assume(sec_r000444_7_1 != sec_r000444_7_2);
  __CPROVER_assume(sec_r000444_2_1 != sec_r000444_2_2);
  __CPROVER_assume(pub_r000444_17_1 == pub_r000444_17_2);
  __CPROVER_assume(sec_r000444_1_1 != sec_r000444_1_2);
  __CPROVER_assume(sec_r000444_18_1 != sec_r000444_18_2);
  __CPROVER_assume(sec_r000444_17_1 != sec_r000444_17_2);
  __CPROVER_assume(sec_r000444_6_1 != sec_r000444_6_2);
  __CPROVER_assume(sec_r000444_10_1 != sec_r000444_10_2);
  __CPROVER_assume(pub_r000444_3_1 == pub_r000444_3_2);
  __CPROVER_assume(pub_r000444_6_1 == pub_r000444_6_2);
  __CPROVER_assume(sec_r000444_0_1 != sec_r000444_0_2);
  __CPROVER_assume(pub_r000444_8_1 == pub_r000444_8_2);
  __CPROVER_assume(sec_r000444_5_1 != sec_r000444_5_2);
  __CPROVER_assume(pub_r000444_9_1 == pub_r000444_9_2);
  __CPROVER_assume(pub_r000444_21_1 == pub_r000444_21_2);
  __CPROVER_assume(pub_r000444_14_1 == pub_r000444_14_2);
  __CPROVER_assume(pub_r000444_5_1 == pub_r000444_5_2);
  __CPROVER_assume(sec_r000444_11_1 != sec_r000444_11_2);
  __CPROVER_assume(sec_r000444_12_1 != sec_r000444_12_2);
  __CPROVER_assume(sec_r000444_15_1 != sec_r000444_15_2);
  __CPROVER_assume(pub_r000444_19_1 == pub_r000444_19_2);
  __CPROVER_assume(sec_r000444_8_1 != sec_r000444_8_2);
  __CPROVER_assume(pub_r000444_0_1 == pub_r000444_0_2);
  __CPROVER_assume(sec_r000444_9_1 != sec_r000444_9_2);
  __CPROVER_assume(sec_r000444_13_1 != sec_r000444_13_2);
  __CPROVER_assume(pub_r000444_16_1 == pub_r000444_16_2);
  __CPROVER_assume(pub_r000444_12_1 == pub_r000444_12_2);
  __CPROVER_assume(sec_r000444_3_1 != sec_r000444_3_2);
  __CPROVER_assume(sec_r000444_16_1 != sec_r000444_16_2);
  __CPROVER_assume(pub_r000444_15_1 == pub_r000444_15_2);
  __CPROVER_assume(pub_r000444_2_1 == pub_r000444_2_2);
  __CPROVER_assume(pub_r000444_7_1 == pub_r000444_7_2);
  __CPROVER_assume(pub_r000444_18_1 == pub_r000444_18_2);
  __CPROVER_assume(pub_r000444_13_1 == pub_r000444_13_2);
  __CPROVER_assume(pub_r000444_10_1 == pub_r000444_10_2);
  __CPROVER_assume(pub_r000444_20_1 == pub_r000444_20_2);
  __CPROVER_assume(sec_r000444_14_1 != sec_r000444_14_2);
  __CPROVER_assume(pub_r000444_1_1 == pub_r000444_1_2);
  __CPROVER_assume(pub_r000444_11_1 == pub_r000444_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
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
}


