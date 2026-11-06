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
struct DeviceConfig_R000393_9313_0
{
  int timeout;
  int id;
  int stop_bits;
  short parity;
  int buffer[3];
};
struct FilterState_R000393_9313_1
{
  short prev_in;
  int mode;
  short prev_out;
  int buffer[3];
};
struct SensorNode_R000393_9313_2
{
  short threshold;
  int calib;
  int gain;
  unsigned char reading;
  unsigned char offset;
  int buffer[3];
};
union RegisterBank_R000393_9313_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000393_9313_1
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
void fn_R000393_9313_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000393_9313_0 st_1 = {0};
  struct DeviceConfig_R000393_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_94_1)
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

  switch (tracker_94_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_42_1 = local_arr_1[aux_1 % 3];
  int anchor_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_42_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_94_1 == tracker_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_42_1 == anchor_42_2);
}

int fn_R000393_9313_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000393_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_94 = (aux + st.buffer[1]) & 3;
  switch (tracker_94)
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

  int local_arr[3] = {4, 9, 15};
  int anchor_42 = local_arr[aux % 3];
  acc = (acc + (anchor_42 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000393_9313_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000393_9313_0 st_1 = {0};
  struct DeviceConfig_R000393_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int bound_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_24_1 > 23)
  {
    acc_1 = ((acc_1 + (bound_24_1 * 2)) + 5) & 127;
    aux_1 ^= bound_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_24_2 > 23)
  {
    acc_2 = ((acc_2 + (bound_24_2 * 2)) + 5) & 127;
    aux_2 ^= bound_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_24_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_24_1 == bound_24_2);
}

int fn_R000393_9313_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000393_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int bound_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_24 > 23)
  {
    acc = ((acc + (bound_24 * 2)) + 5) & 127;
    aux ^= bound_24 & 15;
  }
  else
  {
    acc = ((acc - bound_24) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000393_9313_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000393_9313_0 st_1 = {0};
  struct DeviceConfig_R000393_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int quantum_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_14_1 > 18)
  {
    acc_1 = ((acc_1 + (quantum_14_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_14_2 > 18)
  {
    acc_2 = ((acc_2 + (quantum_14_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_32_1 = local_arr_1[aux_1 % 3];
  int residue_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_32_2 * 2)) & 127;
  int quotient_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_63_1)
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

  switch (quotient_63_2)
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
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_14_1 == quantum_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_32_1 == residue_32_2);
  assert(quotient_63_1 == quotient_63_2);
}

int fn_R000393_9313_2(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000393_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int quantum_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_14 > 18)
  {
    acc = ((acc + (quantum_14 * 2)) + 5) & 127;
    aux ^= quantum_14 & 15;
  }
  else
  {
    acc = ((acc - quantum_14) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int residue_32 = local_arr[aux % 3];
  acc = (acc + (residue_32 * 2)) & 127;
  int quotient_63 = (aux + st.buffer[1]) & 3;
  switch (quotient_63)
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

void fn_R000393_9313_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000393_9313_1 st_1 = {0};
  struct FilterState_R000393_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_25_1 = local_arr_1[aux_1 % 3];
  int bound_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_25_2 * 2)) & 127;
  int window_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_58_1)
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

  switch (window_58_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_25_1 == bound_25_2);
  assert(window_58_1 == window_58_2);
}

int fn_R000393_9313_3(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000393_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int bound_25 = local_arr[aux % 3];
  acc = (acc + (bound_25 * 2)) & 127;
  int window_58 = (aux + st.buffer[1]) & 3;
  switch (window_58)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000393_9313_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000393_9313_1 st_1 = {0};
  struct FilterState_R000393_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int scale_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_73_1)
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

  switch (scale_73_2)
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
  int coefficient_92_1 = local_arr_1[aux_1 % 3];
  int coefficient_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_92_2 * 2)) & 127;
  int pivot_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_37_1) & 63;
  aux_2 = (aux_2 + pivot_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_73_1 == scale_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_92_1 == coefficient_92_2);
  assert(pivot_37_1 == pivot_37_2);
}

int fn_R000393_9313_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000393_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int scale_73 = (aux + st.buffer[1]) & 3;
  switch (scale_73)
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
  int coefficient_92 = local_arr[aux % 3];
  acc = (acc + (coefficient_92 * 2)) & 127;
  int pivot_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_37) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000393_9313_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000393_9313_1 st_1 = {0};
  struct FilterState_R000393_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int weight_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_41_1) & 63;
  aux_2 = (aux_2 + weight_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_53_1)
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

  switch (pivot_53_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_81_1 = local_arr_1[aux_1 % 3];
  int vector_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_81_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_41_1 == weight_41_2);
  assert(pivot_53_1 == pivot_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_81_1 == vector_81_2);
}

int fn_R000393_9313_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000393_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int weight_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_41) & 63;
  acc ^= aux;
  int pivot_53 = (aux + st.buffer[1]) & 3;
  switch (pivot_53)
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

  int local_arr[3] = {4, 9, 15};
  int vector_81 = local_arr[aux % 3];
  acc = (acc + (vector_81 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000393_9313_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000393_9313_2 st_1 = {0};
  struct SensorNode_R000393_9313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int segment_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_11_1 > 36)
  {
    acc_1 = ((acc_1 + (segment_11_1 * 2)) + 5) & 127;
    aux_1 ^= segment_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_11_2 > 36)
  {
    acc_2 = ((acc_2 + (segment_11_2 * 2)) + 5) & 127;
    aux_2 ^= segment_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_29_1) & 63;
  aux_2 = (aux_2 + phase_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_11_1 == segment_11_2);
  assert(phase_29_1 == phase_29_2);
}

int fn_R000393_9313_6(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000393_9313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int segment_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_11 > 36)
  {
    acc = ((acc + (segment_11 * 2)) + 5) & 127;
    aux ^= segment_11 & 15;
  }
  else
  {
    acc = ((acc - segment_11) + 11) & 127;
    aux += 3;
  }
  int phase_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_29) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000393_9313_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000393_9313_2 st_1 = {0};
  struct SensorNode_R000393_9313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_49_1 = local_arr_1[aux_1 % 3];
  int parity_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_49_2 * 2)) & 127;
  int offset_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_74_1 > 32)
  {
    acc_1 = ((acc_1 + (offset_74_1 * 2)) + 5) & 127;
    aux_1 ^= offset_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_74_2 > 32)
  {
    acc_2 = ((acc_2 + (offset_74_2 * 2)) + 5) & 127;
    aux_2 ^= offset_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_74_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_61_1)
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

  switch (index_reg_61_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_49_1 == parity_49_2);
  assert(offset_74_1 == offset_74_2);
  assert(index_reg_61_1 == index_reg_61_2);
}

int fn_R000393_9313_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000393_9313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int parity_49 = local_arr[aux % 3];
  acc = (acc + (parity_49 * 2)) & 127;
  int offset_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_74 > 32)
  {
    acc = ((acc + (offset_74 * 2)) + 5) & 127;
    aux ^= offset_74 & 15;
  }
  else
  {
    acc = ((acc - offset_74) + 11) & 127;
    aux += 3;
  }
  int index_reg_61 = (aux + st.buffer[1]) & 3;
  switch (index_reg_61)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000393_9313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000393_9313_2 st_1 = {0};
  struct SensorNode_R000393_9313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int weight_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_93_1)
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

  switch (weight_93_2)
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

  int anchor_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_24_1 > 17)
  {
    acc_1 = ((acc_1 + (anchor_24_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_24_2 > 17)
  {
    acc_2 = ((acc_2 + (anchor_24_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_24_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_75_1) & 63;
  aux_2 = (aux_2 + phase_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_93_1 == weight_93_2);
  assert(anchor_24_1 == anchor_24_2);
  assert(phase_75_1 == phase_75_2);
}

int fn_R000393_9313_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000393_9313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int weight_93 = (aux + st.buffer[1]) & 3;
  switch (weight_93)
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

  int anchor_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_24 > 17)
  {
    acc = ((acc + (anchor_24 * 2)) + 5) & 127;
    aux ^= anchor_24 & 15;
  }
  else
  {
    acc = ((acc - anchor_24) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_75) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000393_9313_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000393_9313_1 st_1 = {0};
  struct FilterState_R000393_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int index_reg_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_94_1) & 63;
  aux_2 = (aux_2 + index_reg_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_59_1)
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

  switch (anchor_59_2)
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

  int cursor_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_37_1 > 36)
  {
    acc_1 = ((acc_1 + (cursor_37_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_37_2 > 36)
  {
    acc_2 = ((acc_2 + (cursor_37_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_37_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_94_1 == index_reg_94_2);
  assert(anchor_59_1 == anchor_59_2);
  assert(cursor_37_1 == cursor_37_2);
}

int fn_R000393_9313_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000393_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int index_reg_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_94) & 63;
  acc ^= aux;
  int anchor_59 = (aux + st.buffer[1]) & 3;
  switch (anchor_59)
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

  int cursor_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_37 > 36)
  {
    acc = ((acc + (cursor_37 * 2)) + 5) & 127;
    aux ^= cursor_37 & 15;
  }
  else
  {
    acc = ((acc - cursor_37) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000393_9313_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000393_9313_0 st_1 = {0};
  struct DeviceConfig_R000393_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_44_1 > 33)
  {
    acc_1 = ((acc_1 + (tracker_44_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_44_2 > 33)
  {
    acc_2 = ((acc_2 + (tracker_44_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_24_1)
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

  switch (weight_24_2)
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
  int tracker_43_1 = local_arr_1[aux_1 % 3];
  int tracker_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_43_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_44_1 == tracker_44_2);
  assert(weight_24_1 == weight_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_43_1 == tracker_43_2);
}

int fn_R000393_9313_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000393_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_44 > 33)
  {
    acc = ((acc + (tracker_44 * 2)) + 5) & 127;
    aux ^= tracker_44 & 15;
  }
  else
  {
    acc = ((acc - tracker_44) + 11) & 127;
    aux += 3;
  }
  int weight_24 = (aux + st.buffer[1]) & 3;
  switch (weight_24)
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
  int tracker_43 = local_arr[aux % 3];
  acc = (acc + (tracker_43 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000393_9313_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000393_9313_1 st_1 = {0};
  struct FilterState_R000393_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_94_1 = local_arr_1[aux_1 % 3];
  int mask_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_94_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_94_1 == mask_94_2);
}

int fn_R000393_9313_11(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000393_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int mask_94 = local_arr[aux % 3];
  acc = (acc + (mask_94 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000393_9313_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000393_9313_0 st_1 = {0};
  struct DeviceConfig_R000393_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int delta_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_29_1)
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

  switch (delta_29_2)
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

  int window_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_98_1 > 25)
  {
    acc_1 = ((acc_1 + (window_98_1 * 2)) + 5) & 127;
    aux_1 ^= window_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_98_2 > 25)
  {
    acc_2 = ((acc_2 + (window_98_2 * 2)) + 5) & 127;
    aux_2 ^= window_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_98_1) & 63;
  aux_2 = (aux_2 + tally_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_53_1 = local_arr_1[aux_1 % 3];
  int offset_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_53_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_29_1 == delta_29_2);
  assert(window_98_1 == window_98_2);
  assert(tally_98_1 == tally_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_53_1 == offset_53_2);
}

int fn_R000393_9313_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000393_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int delta_29 = (aux + st.buffer[1]) & 3;
  switch (delta_29)
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

  int window_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_98 > 25)
  {
    acc = ((acc + (window_98 * 2)) + 5) & 127;
    aux ^= window_98 & 15;
  }
  else
  {
    acc = ((acc - window_98) + 11) & 127;
    aux += 3;
  }
  int tally_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_98) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_53 = local_arr[aux % 3];
  acc = (acc + (offset_53 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000393_9313_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000393_9313_2 st_1 = {0};
  struct SensorNode_R000393_9313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_42_1)
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

  switch (bound_42_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_57_1 = local_arr_1[aux_1 % 3];
  int scale_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_57_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_42_1 == bound_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_57_1 == scale_57_2);
}

int fn_R000393_9313_13(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000393_9313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_42 = (aux + st.buffer[1]) & 3;
  switch (bound_42)
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

  int local_arr[3] = {4, 9, 15};
  int scale_57 = local_arr[aux % 3];
  acc = (acc + (scale_57 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000393_9313_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000393_9313_1 st_1 = {0};
  struct FilterState_R000393_9313_1 st_2 = {0};
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
  int sample_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_75_1) & 63;
  aux_2 = (aux_2 + sample_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_88_1 = local_arr_1[aux_1 % 3];
  int coefficient_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_88_2 * 2)) & 127;
  int phase_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_23_1 > 48)
  {
    acc_1 = ((acc_1 + (phase_23_1 * 2)) + 5) & 127;
    aux_1 ^= phase_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_23_2 > 48)
  {
    acc_2 = ((acc_2 + (phase_23_2 * 2)) + 5) & 127;
    aux_2 ^= phase_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_23_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_75_1 == sample_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_88_1 == coefficient_88_2);
  assert(phase_23_1 == phase_23_2);
}

int fn_R000393_9313_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000393_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_75) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int coefficient_88 = local_arr[aux % 3];
  acc = (acc + (coefficient_88 * 2)) & 127;
  int phase_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_23 > 48)
  {
    acc = ((acc + (phase_23 * 2)) + 5) & 127;
    aux ^= phase_23 & 15;
  }
  else
  {
    acc = ((acc - phase_23) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000393_9313_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000393_9313_1 st_1 = {0};
  struct FilterState_R000393_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int sample_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_17_1) & 63;
  aux_2 = (aux_2 + sample_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_75_1 = local_arr_1[aux_1 % 3];
  int checksum_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_75_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_17_1 == sample_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_75_1 == checksum_75_2);
}

int fn_R000393_9313_15(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000393_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int sample_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_17) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int checksum_75 = local_arr[aux % 3];
  acc = (acc + (checksum_75 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000393_9313_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000393_9313_0 st_1 = {0};
  struct DeviceConfig_R000393_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int weight_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_32_1)
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

  switch (weight_32_2)
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
  int coefficient_67_1 = local_arr_1[aux_1 % 3];
  int coefficient_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_67_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_32_1 == weight_32_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_67_1 == coefficient_67_2);
}

int fn_R000393_9313_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000393_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int weight_32 = (aux + st.buffer[1]) & 3;
  switch (weight_32)
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
  int coefficient_67 = local_arr[aux % 3];
  acc = (acc + (coefficient_67 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000393_9313_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000393_9313_2 st_1 = {0};
  struct SensorNode_R000393_9313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int threshold_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_33_1 > 36)
  {
    acc_1 = ((acc_1 + (threshold_33_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_33_2 > 36)
  {
    acc_2 = ((acc_2 + (threshold_33_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_33_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_54_1) & 63;
  aux_2 = (aux_2 + margin_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_38_1)
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

  switch (offset_38_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_33_1 == threshold_33_2);
  assert(margin_54_1 == margin_54_2);
  assert(offset_38_1 == offset_38_2);
}

int fn_R000393_9313_17(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000393_9313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int threshold_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_33 > 36)
  {
    acc = ((acc + (threshold_33 * 2)) + 5) & 127;
    aux ^= threshold_33 & 15;
  }
  else
  {
    acc = ((acc - threshold_33) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_54) & 63;
  acc ^= aux;
  int offset_38 = (aux + st.buffer[1]) & 3;
  switch (offset_38)
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

void fn_R000393_9313_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000393_9313_2 st_1 = {0};
  struct SensorNode_R000393_9313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int factor_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_71_1)
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

  switch (factor_71_2)
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

  int index_reg_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_61_1 > 47)
  {
    acc_1 = ((acc_1 + (index_reg_61_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_61_2 > 47)
  {
    acc_2 = ((acc_2 + (index_reg_61_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_61_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_71_1 == factor_71_2);
  assert(index_reg_61_1 == index_reg_61_2);
}

int fn_R000393_9313_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000393_9313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int factor_71 = (aux + st.buffer[1]) & 3;
  switch (factor_71)
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

  int index_reg_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_61 > 47)
  {
    acc = ((acc + (index_reg_61 * 2)) + 5) & 127;
    aux ^= index_reg_61 & 15;
  }
  else
  {
    acc = ((acc - index_reg_61) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000393_9313_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000393_9313_1 st_1 = {0};
  struct FilterState_R000393_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int damping_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_92_1 > 46)
  {
    acc_1 = ((acc_1 + (damping_92_1 * 2)) + 5) & 127;
    aux_1 ^= damping_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_92_2 > 46)
  {
    acc_2 = ((acc_2 + (damping_92_2 * 2)) + 5) & 127;
    aux_2 ^= damping_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_16_1 = local_arr_1[aux_1 % 3];
  int window_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_16_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_92_1 == damping_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_16_1 == window_16_2);
}

int fn_R000393_9313_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000393_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int damping_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_92 > 46)
  {
    acc = ((acc + (damping_92 * 2)) + 5) & 127;
    aux ^= damping_92 & 15;
  }
  else
  {
    acc = ((acc - damping_92) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_16 = local_arr[aux % 3];
  acc = (acc + (window_16 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000393_9313_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000393_9313_2 st_1 = {0};
  struct SensorNode_R000393_9313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int factor_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_45_1)
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

  switch (factor_45_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_71_1 = local_arr_1[aux_1 % 3];
  int damping_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_71_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_45_1 == factor_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_71_1 == damping_71_2);
}

int fn_R000393_9313_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000393_9313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int factor_45 = (aux + st.buffer[1]) & 3;
  switch (factor_45)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int damping_71 = local_arr[aux % 3];
  acc = (acc + (damping_71 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000393_9313_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000393_9313_0 st_1 = {0};
  struct DeviceConfig_R000393_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int checksum_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_48_1)
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

  switch (checksum_48_2)
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
  int sample_58_1 = local_arr_1[aux_1 % 3];
  int sample_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_58_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_48_1 == checksum_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_58_1 == sample_58_2);
}

int fn_R000393_9313_21(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000393_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int checksum_48 = (aux + st.buffer[1]) & 3;
  switch (checksum_48)
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
  int sample_58 = local_arr[aux % 3];
  acc = (acc + (sample_58 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000393_0_1;
  int sec_r000393_0_2;
  int sec_r000393_1_1;
  int sec_r000393_1_2;
  int sec_r000393_2_1;
  int sec_r000393_2_2;
  int sec_r000393_3_1;
  int sec_r000393_3_2;
  int sec_r000393_4_1;
  int sec_r000393_4_2;
  int sec_r000393_5_1;
  int sec_r000393_5_2;
  int sec_r000393_6_1;
  int sec_r000393_6_2;
  int sec_r000393_7_1;
  int sec_r000393_7_2;
  int sec_r000393_8_1;
  int sec_r000393_8_2;
  int sec_r000393_9_1;
  int sec_r000393_9_2;
  int sec_r000393_10_1;
  int sec_r000393_10_2;
  int sec_r000393_11_1;
  int sec_r000393_11_2;
  int sec_r000393_12_1;
  int sec_r000393_12_2;
  int sec_r000393_13_1;
  int sec_r000393_13_2;
  int sec_r000393_14_1;
  int sec_r000393_14_2;
  int sec_r000393_15_1;
  int sec_r000393_15_2;
  int pub_r000393_0_1;
  int pub_r000393_0_2;
  int pub_r000393_1_1;
  int pub_r000393_1_2;
  int pub_r000393_2_1;
  int pub_r000393_2_2;
  int pub_r000393_3_1;
  int pub_r000393_3_2;
  int pub_r000393_4_1;
  int pub_r000393_4_2;
  int pub_r000393_5_1;
  int pub_r000393_5_2;
  int pub_r000393_6_1;
  int pub_r000393_6_2;
  int pub_r000393_7_1;
  int pub_r000393_7_2;
  int pub_r000393_8_1;
  int pub_r000393_8_2;
  int pub_r000393_9_1;
  int pub_r000393_9_2;
  int pub_r000393_10_1;
  int pub_r000393_10_2;
  int pub_r000393_11_1;
  int pub_r000393_11_2;
  int pub_r000393_12_1;
  int pub_r000393_12_2;
  int pub_r000393_13_1;
  int pub_r000393_13_2;
  int pub_r000393_14_1;
  int pub_r000393_14_2;
  int pub_r000393_15_1;
  int pub_r000393_15_2;
  int pub_r000393_16_1;
  int pub_r000393_16_2;
  int pub_r000393_17_1;
  int pub_r000393_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000393_0_1 >= (-100)) && (pub_r000393_0_1 <= 100));
  __CPROVER_assume((pub_r000393_0_2 >= (-100)) && (pub_r000393_0_2 <= 100));
  __CPROVER_assume((pub_r000393_1_1 >= (-100)) && (pub_r000393_1_1 <= 100));
  __CPROVER_assume((pub_r000393_1_2 >= (-100)) && (pub_r000393_1_2 <= 100));
  __CPROVER_assume((pub_r000393_2_1 >= (-100)) && (pub_r000393_2_1 <= 100));
  __CPROVER_assume((pub_r000393_2_2 >= (-100)) && (pub_r000393_2_2 <= 100));
  __CPROVER_assume((pub_r000393_3_1 >= (-100)) && (pub_r000393_3_1 <= 100));
  __CPROVER_assume((pub_r000393_3_2 >= (-100)) && (pub_r000393_3_2 <= 100));
  __CPROVER_assume((pub_r000393_4_1 >= (-100)) && (pub_r000393_4_1 <= 100));
  __CPROVER_assume((pub_r000393_4_2 >= (-100)) && (pub_r000393_4_2 <= 100));
  __CPROVER_assume((pub_r000393_5_1 >= (-100)) && (pub_r000393_5_1 <= 100));
  __CPROVER_assume((pub_r000393_5_2 >= (-100)) && (pub_r000393_5_2 <= 100));
  __CPROVER_assume((pub_r000393_6_1 >= (-100)) && (pub_r000393_6_1 <= 100));
  __CPROVER_assume((pub_r000393_6_2 >= (-100)) && (pub_r000393_6_2 <= 100));
  __CPROVER_assume((pub_r000393_7_1 >= (-100)) && (pub_r000393_7_1 <= 100));
  __CPROVER_assume((pub_r000393_7_2 >= (-100)) && (pub_r000393_7_2 <= 100));
  __CPROVER_assume((pub_r000393_8_1 >= (-100)) && (pub_r000393_8_1 <= 100));
  __CPROVER_assume((pub_r000393_8_2 >= (-100)) && (pub_r000393_8_2 <= 100));
  __CPROVER_assume((pub_r000393_9_1 >= (-100)) && (pub_r000393_9_1 <= 100));
  __CPROVER_assume((pub_r000393_9_2 >= (-100)) && (pub_r000393_9_2 <= 100));
  __CPROVER_assume((pub_r000393_10_1 >= (-100)) && (pub_r000393_10_1 <= 100));
  __CPROVER_assume((pub_r000393_10_2 >= (-100)) && (pub_r000393_10_2 <= 100));
  __CPROVER_assume((pub_r000393_11_1 >= (-100)) && (pub_r000393_11_1 <= 100));
  __CPROVER_assume((pub_r000393_11_2 >= (-100)) && (pub_r000393_11_2 <= 100));
  __CPROVER_assume((pub_r000393_12_1 >= (-100)) && (pub_r000393_12_1 <= 100));
  __CPROVER_assume((pub_r000393_12_2 >= (-100)) && (pub_r000393_12_2 <= 100));
  __CPROVER_assume((pub_r000393_13_1 >= (-100)) && (pub_r000393_13_1 <= 100));
  __CPROVER_assume((pub_r000393_13_2 >= (-100)) && (pub_r000393_13_2 <= 100));
  __CPROVER_assume((pub_r000393_14_1 >= (-100)) && (pub_r000393_14_1 <= 100));
  __CPROVER_assume((pub_r000393_14_2 >= (-100)) && (pub_r000393_14_2 <= 100));
  __CPROVER_assume((pub_r000393_15_1 >= (-100)) && (pub_r000393_15_1 <= 100));
  __CPROVER_assume((pub_r000393_15_2 >= (-100)) && (pub_r000393_15_2 <= 100));
  __CPROVER_assume((pub_r000393_16_1 >= (-100)) && (pub_r000393_16_1 <= 100));
  __CPROVER_assume((pub_r000393_16_2 >= (-100)) && (pub_r000393_16_2 <= 100));
  __CPROVER_assume((pub_r000393_17_1 >= (-100)) && (pub_r000393_17_1 <= 100));
  __CPROVER_assume((pub_r000393_17_2 >= (-100)) && (pub_r000393_17_2 <= 100));
  __CPROVER_assume((sec_r000393_0_1 >= 0) && (sec_r000393_0_1 <= 255));
  __CPROVER_assume((sec_r000393_0_2 >= 0) && (sec_r000393_0_2 <= 255));
  __CPROVER_assume((sec_r000393_1_1 >= 0) && (sec_r000393_1_1 <= 255));
  __CPROVER_assume((sec_r000393_1_2 >= 0) && (sec_r000393_1_2 <= 255));
  __CPROVER_assume((sec_r000393_2_1 >= 0) && (sec_r000393_2_1 <= 255));
  __CPROVER_assume((sec_r000393_2_2 >= 0) && (sec_r000393_2_2 <= 255));
  __CPROVER_assume((sec_r000393_3_1 >= 0) && (sec_r000393_3_1 <= 255));
  __CPROVER_assume((sec_r000393_3_2 >= 0) && (sec_r000393_3_2 <= 255));
  __CPROVER_assume((sec_r000393_4_1 >= 0) && (sec_r000393_4_1 <= 255));
  __CPROVER_assume((sec_r000393_4_2 >= 0) && (sec_r000393_4_2 <= 255));
  __CPROVER_assume((sec_r000393_5_1 >= 0) && (sec_r000393_5_1 <= 255));
  __CPROVER_assume((sec_r000393_5_2 >= 0) && (sec_r000393_5_2 <= 255));
  __CPROVER_assume((sec_r000393_6_1 >= 0) && (sec_r000393_6_1 <= 255));
  __CPROVER_assume((sec_r000393_6_2 >= 0) && (sec_r000393_6_2 <= 255));
  __CPROVER_assume((sec_r000393_7_1 >= 0) && (sec_r000393_7_1 <= 255));
  __CPROVER_assume((sec_r000393_7_2 >= 0) && (sec_r000393_7_2 <= 255));
  __CPROVER_assume((sec_r000393_8_1 >= 0) && (sec_r000393_8_1 <= 255));
  __CPROVER_assume((sec_r000393_8_2 >= 0) && (sec_r000393_8_2 <= 255));
  __CPROVER_assume((sec_r000393_9_1 >= 0) && (sec_r000393_9_1 <= 255));
  __CPROVER_assume((sec_r000393_9_2 >= 0) && (sec_r000393_9_2 <= 255));
  __CPROVER_assume((sec_r000393_10_1 >= 0) && (sec_r000393_10_1 <= 255));
  __CPROVER_assume((sec_r000393_10_2 >= 0) && (sec_r000393_10_2 <= 255));
  __CPROVER_assume((sec_r000393_11_1 >= 0) && (sec_r000393_11_1 <= 255));
  __CPROVER_assume((sec_r000393_11_2 >= 0) && (sec_r000393_11_2 <= 255));
  __CPROVER_assume((sec_r000393_12_1 >= 0) && (sec_r000393_12_1 <= 255));
  __CPROVER_assume((sec_r000393_12_2 >= 0) && (sec_r000393_12_2 <= 255));
  __CPROVER_assume((sec_r000393_13_1 >= 0) && (sec_r000393_13_1 <= 255));
  __CPROVER_assume((sec_r000393_13_2 >= 0) && (sec_r000393_13_2 <= 255));
  __CPROVER_assume((sec_r000393_14_1 >= 0) && (sec_r000393_14_1 <= 255));
  __CPROVER_assume((sec_r000393_14_2 >= 0) && (sec_r000393_14_2 <= 255));
  __CPROVER_assume((sec_r000393_15_1 >= 0) && (sec_r000393_15_1 <= 255));
  __CPROVER_assume((sec_r000393_15_2 >= 0) && (sec_r000393_15_2 <= 255));
  struct DeviceConfig_R000393_9313_0 st_var_0_1 = {0};
  struct DeviceConfig_R000393_9313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000393_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000393_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000393_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000393_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000393_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000393_0_2 + 7) & 15;
  struct FilterState_R000393_9313_1 st_var_1_1 = {0};
  struct FilterState_R000393_9313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000393_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000393_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000393_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000393_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000393_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000393_0_2 + 9) & 15;
  struct SensorNode_R000393_9313_2 st_var_2_1 = {0};
  struct SensorNode_R000393_9313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000393_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000393_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000393_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000393_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000393_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000393_0_2 + 11) & 15;
  union RegisterBank_R000393_9313_0 u_var_1;
  union RegisterBank_R000393_9313_0 u_var_2;
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 2) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 2) & 15;
  int stage_v_1_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_1_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= stage_v_1_1;
  chk_sum_2 ^= stage_v_1_2;
  int stage_v_2_1 = ((st_var_2_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_2_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 33)
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
  if (stage_v_2_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 33)
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
  int stage_v_5_1 = (st_var_2_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_2_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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

  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
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
  int stage_v_8_1 = (st_var_2_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_2_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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
  int stage_v_11_1 = (st_var_2_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_2_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 13) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 13) & 15;
  int stage_v_12_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_12_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= stage_v_12_1;
  chk_sum_2 ^= stage_v_12_2;
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 16) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
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
  int stage_v_17_1 = (st_var_2_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_2_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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

  int stage_v_18_1 = (st_var_0_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_0_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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

  int stage_v_19_1 = ((st_var_1_1.buffer[1] * 2) + 64) & 63;
  int stage_v_19_2 = ((st_var_1_2.buffer[1] * 2) + 64) & 63;
  if (stage_v_19_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_19_1) - 5) & 255;
    if (stage_v_19_1 > 53)
    {
      chk_sum_1 ^= stage_v_19_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_19_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_19_2) - 5) & 255;
    if (stage_v_19_2 > 53)
    {
      chk_sum_2 ^= stage_v_19_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_20_1 = ((st_var_2_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_2_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 27)
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
  if (stage_v_20_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 27)
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
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_21_1 = ((stage_v_21_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 23) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 23) & 15;
  int stage_v_22_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_22_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= stage_v_22_1;
  chk_sum_2 ^= stage_v_22_2;
  int stage_v_23_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (28 & 31);
  int stage_v_23_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (28 & 31);
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= (stage_v_23_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_23_2 << 1) & 127;
  int stage_v_24_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (29 & 31);
  int stage_v_24_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (29 & 31);
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= (stage_v_24_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_24_2 << 1) & 127;
  int stage_v_25_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_25_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_26_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_26_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_26_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_26_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_28_1 = ((st_var_1_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_1_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 27)
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
  if (stage_v_28_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 27)
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
  int stage_v_31_1 = table_1[3];
  int stage_v_31_2 = table_2[3];
  table_1[3] = (table_1[0] + 63) & 63;
  table_2[3] = (table_2[0] + 63) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((st_var_2_1.buffer[2] * 2) + 103) & 63;
  int stage_v_32_2 = ((st_var_2_2.buffer[2] * 2) + 103) & 63;
  if (stage_v_32_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_32_1) - 5) & 255;
    if (stage_v_32_1 > 46)
    {
      chk_sum_1 ^= stage_v_32_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_32_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_32_2) - 5) & 255;
    if (stage_v_32_2 > 46)
    {
      chk_sum_2 ^= stage_v_32_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_33_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_33_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_33_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_33_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_34_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_34_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_35_1 = table_1[3];
  int stage_v_35_2 = table_2[3];
  table_1[3] = (table_1[0] + 71) & 63;
  table_2[3] = (table_2[0] + 71) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
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
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 40) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
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
  int stage_v_42_1 = ((st_var_0_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_0_2.buffer[0] * 2) + 133) & 63;
  if (stage_v_42_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 37)
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
  if (stage_v_42_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 37)
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
  int stage_v_43_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_43_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_43_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_43_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 45) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 45) & 15;
  int stage_v_44_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_44_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= stage_v_44_1;
  chk_sum_2 ^= stage_v_44_2;
  int stage_v_45_1 = table_1[1];
  int stage_v_45_2 = table_2[1];
  table_1[1] = (table_1[2] + 91) & 63;
  table_2[1] = (table_2[2] + 91) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = table_1[2];
  int stage_v_46_2 = table_2[2];
  table_1[2] = (table_1[3] + 93) & 63;
  table_2[2] = (table_2[3] + 93) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (st_var_2_1.buffer[0] ^ 50) & 3;
  int stage_v_47_2 = (st_var_2_2.buffer[0] ^ 50) & 3;
  switch (stage_v_47_1)
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

  switch (stage_v_47_2)
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

  int stage_v_48_1 = ((st_var_0_1.buffer[0] * 2) + 151) & 63;
  int stage_v_48_2 = ((st_var_0_2.buffer[0] * 2) + 151) & 63;
  if (stage_v_48_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_48_1) - 5) & 255;
    if (stage_v_48_1 > 35)
    {
      chk_sum_1 ^= stage_v_48_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_48_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_48_2) - 5) & 255;
    if (stage_v_48_2 > 35)
    {
      chk_sum_2 ^= stage_v_48_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_49_1 = (st_var_1_1.buffer[0] ^ 52) & 3;
  int stage_v_49_2 = (st_var_1_2.buffer[0] ^ 52) & 3;
  switch (stage_v_49_1)
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

  switch (stage_v_49_2)
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

  int stage_v_50_1 = ((st_var_2_1.buffer[2] * 2) + 157) & 63;
  int stage_v_50_2 = ((st_var_2_2.buffer[2] * 2) + 157) & 63;
  if (stage_v_50_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_50_1) - 5) & 255;
    if (stage_v_50_1 > 25)
    {
      chk_sum_1 ^= stage_v_50_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_50_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_50_2) - 5) & 255;
    if (stage_v_50_2 > 25)
    {
      chk_sum_2 ^= stage_v_50_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int sub_step_51_1 = ((sec_r000393_6_1 + pub_r000393_11_1) + 18) & 127;
  int sub_step_51_2 = ((sec_r000393_6_2 + pub_r000393_11_2) + 18) & 127;
  int stage_v_51_1 = ((sub_step_51_1 * 2) + pub_r000393_8_1) & 127;
  int stage_v_51_2 = ((sub_step_51_2 * 2) + pub_r000393_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_51_1 & 15;
  st_var_0_2.buffer[0] = stage_v_51_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int sub_step_52_1 = ((stage_v_51_1 + pub_r000393_8_1) + 14) & 127;
  int sub_step_52_2 = ((stage_v_51_2 + pub_r000393_8_2) + 14) & 127;
  int stage_v_52_1 = ((sub_step_52_1 * 2) + pub_r000393_7_1) & 127;
  int stage_v_52_2 = ((sub_step_52_2 * 2) + pub_r000393_7_2) & 127;
  st_var_1_1.buffer[1] = stage_v_52_1 & 15;
  st_var_1_2.buffer[1] = stage_v_52_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int sub_step_53_1 = ((sec_r000393_5_1 + pub_r000393_14_1) + 25) & 127;
  int sub_step_53_2 = ((sec_r000393_5_2 + pub_r000393_14_2) + 25) & 127;
  int stage_v_53_1 = ((sub_step_53_1 * 2) + pub_r000393_12_1) & 127;
  int stage_v_53_2 = ((sub_step_53_2 * 2) + pub_r000393_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_53_1 & 15;
  st_var_2_2.buffer[2] = stage_v_53_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int sub_step_54_1 = ((sec_r000393_1_1 + pub_r000393_7_1) + 6) & 127;
  int sub_step_54_2 = ((sec_r000393_1_2 + pub_r000393_7_2) + 6) & 127;
  int stage_v_54_1 = ((sub_step_54_1 * 2) + pub_r000393_0_1) & 127;
  int stage_v_54_2 = ((sub_step_54_2 * 2) + pub_r000393_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_54_1 & 15;
  st_var_0_2.buffer[0] = stage_v_54_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int sub_step_55_1 = ((sub_step_51_1 + pub_r000393_15_1) + 13) & 127;
  int sub_step_55_2 = ((sub_step_51_2 + pub_r000393_15_2) + 13) & 127;
  int stage_v_55_1 = ((sub_step_55_1 * 2) + pub_r000393_2_1) & 127;
  int stage_v_55_2 = ((sub_step_55_2 * 2) + pub_r000393_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_55_1 & 15;
  st_var_1_2.buffer[1] = stage_v_55_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int sub_step_56_1 = ((sub_step_53_1 + pub_r000393_5_1) + 33) & 127;
  int sub_step_56_2 = ((sub_step_53_2 + pub_r000393_5_2) + 33) & 127;
  int stage_v_56_1 = ((sub_step_56_1 * 2) + pub_r000393_1_1) & 127;
  int stage_v_56_2 = ((sub_step_56_2 * 2) + pub_r000393_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_56_1 & 15;
  st_var_2_2.buffer[2] = stage_v_56_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int sub_step_57_1 = ((stage_v_53_1 + pub_r000393_0_1) + 35) & 127;
  int sub_step_57_2 = ((stage_v_53_2 + pub_r000393_0_2) + 35) & 127;
  int stage_v_57_1 = ((sub_step_57_1 * 2) + pub_r000393_15_1) & 127;
  int stage_v_57_2 = ((sub_step_57_2 * 2) + pub_r000393_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_57_1 & 15;
  st_var_0_2.buffer[0] = stage_v_57_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int sub_step_58_1 = ((sub_step_51_1 + pub_r000393_5_1) + 31) & 127;
  int sub_step_58_2 = ((sub_step_51_2 + pub_r000393_5_2) + 31) & 127;
  int stage_v_58_1 = ((sub_step_58_1 * 2) + pub_r000393_3_1) & 127;
  int stage_v_58_2 = ((sub_step_58_2 * 2) + pub_r000393_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_58_1 & 15;
  st_var_1_2.buffer[1] = stage_v_58_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int sub_step_59_1 = ((sec_r000393_12_1 + pub_r000393_17_1) + 24) & 127;
  int sub_step_59_2 = ((sec_r000393_12_2 + pub_r000393_17_2) + 24) & 127;
  int stage_v_59_1 = ((sub_step_59_1 * 2) + pub_r000393_16_1) & 127;
  int stage_v_59_2 = ((sub_step_59_2 * 2) + pub_r000393_16_2) & 127;
  st_var_2_1.buffer[2] = stage_v_59_1 & 15;
  st_var_2_2.buffer[2] = stage_v_59_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int sub_step_60_1 = ((stage_v_52_1 + pub_r000393_17_1) + 15) & 127;
  int sub_step_60_2 = ((stage_v_52_2 + pub_r000393_17_2) + 15) & 127;
  int stage_v_60_1 = ((sub_step_60_1 * 2) + pub_r000393_17_1) & 127;
  int stage_v_60_2 = ((sub_step_60_2 * 2) + pub_r000393_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_60_1 & 15;
  st_var_0_2.buffer[0] = stage_v_60_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int sub_step_61_1 = ((sub_step_59_1 + pub_r000393_9_1) + 24) & 127;
  int sub_step_61_2 = ((sub_step_59_2 + pub_r000393_9_2) + 24) & 127;
  int stage_v_61_1 = ((sub_step_61_1 * 2) + pub_r000393_17_1) & 127;
  int stage_v_61_2 = ((sub_step_61_2 * 2) + pub_r000393_17_2) & 127;
  st_var_1_1.buffer[1] = stage_v_61_1 & 15;
  st_var_1_2.buffer[1] = stage_v_61_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int sub_step_62_1 = ((sub_step_61_1 + pub_r000393_8_1) + 18) & 127;
  int sub_step_62_2 = ((sub_step_61_2 + pub_r000393_8_2) + 18) & 127;
  int stage_v_62_1 = ((sub_step_62_1 * 2) + pub_r000393_13_1) & 127;
  int stage_v_62_2 = ((sub_step_62_2 * 2) + pub_r000393_13_2) & 127;
  st_var_2_1.buffer[2] = stage_v_62_1 & 15;
  st_var_2_2.buffer[2] = stage_v_62_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int sub_step_63_1 = ((stage_v_56_1 + pub_r000393_5_1) + 11) & 127;
  int sub_step_63_2 = ((stage_v_56_2 + pub_r000393_5_2) + 11) & 127;
  int stage_v_63_1 = ((sub_step_63_1 * 2) + pub_r000393_17_1) & 127;
  int stage_v_63_2 = ((sub_step_63_2 * 2) + pub_r000393_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_63_1 & 15;
  st_var_0_2.buffer[0] = stage_v_63_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int sub_step_64_1 = ((sub_step_56_1 + pub_r000393_5_1) + 17) & 127;
  int sub_step_64_2 = ((sub_step_56_2 + pub_r000393_5_2) + 17) & 127;
  int stage_v_64_1 = ((sub_step_64_1 * 2) + pub_r000393_10_1) & 127;
  int stage_v_64_2 = ((sub_step_64_2 * 2) + pub_r000393_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_64_1 & 15;
  st_var_1_2.buffer[1] = stage_v_64_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int sub_step_65_1 = ((sec_r000393_5_1 + pub_r000393_17_1) + 9) & 127;
  int sub_step_65_2 = ((sec_r000393_5_2 + pub_r000393_17_2) + 9) & 127;
  int stage_v_65_1 = ((sub_step_65_1 * 2) + pub_r000393_5_1) & 127;
  int stage_v_65_2 = ((sub_step_65_2 * 2) + pub_r000393_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_65_1 & 15;
  st_var_2_2.buffer[2] = stage_v_65_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int sub_step_66_1 = ((stage_v_53_1 + pub_r000393_9_1) + 9) & 127;
  int sub_step_66_2 = ((stage_v_53_2 + pub_r000393_9_2) + 9) & 127;
  int stage_v_66_1 = ((sub_step_66_1 * 2) + pub_r000393_2_1) & 127;
  int stage_v_66_2 = ((sub_step_66_2 * 2) + pub_r000393_2_2) & 127;
  st_var_0_1.buffer[0] = stage_v_66_1 & 15;
  st_var_0_2.buffer[0] = stage_v_66_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int sub_step_67_1 = ((stage_v_52_1 + pub_r000393_15_1) + 18) & 127;
  int sub_step_67_2 = ((stage_v_52_2 + pub_r000393_15_2) + 18) & 127;
  int stage_v_67_1 = ((sub_step_67_1 * 2) + pub_r000393_6_1) & 127;
  int stage_v_67_2 = ((sub_step_67_2 * 2) + pub_r000393_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_67_1 & 15;
  st_var_1_2.buffer[1] = stage_v_67_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int sub_step_68_1 = ((sub_step_64_1 + pub_r000393_3_1) + 10) & 127;
  int sub_step_68_2 = ((sub_step_64_2 + pub_r000393_3_2) + 10) & 127;
  int stage_v_68_1 = ((sub_step_68_1 * 2) + pub_r000393_11_1) & 127;
  int stage_v_68_2 = ((sub_step_68_2 * 2) + pub_r000393_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_68_1 & 15;
  st_var_2_2.buffer[2] = stage_v_68_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int sub_step_69_1 = ((stage_v_57_1 + pub_r000393_9_1) + 13) & 127;
  int sub_step_69_2 = ((stage_v_57_2 + pub_r000393_9_2) + 13) & 127;
  int stage_v_69_1 = ((sub_step_69_1 * 2) + pub_r000393_1_1) & 127;
  int stage_v_69_2 = ((sub_step_69_2 * 2) + pub_r000393_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_69_1 & 15;
  st_var_0_2.buffer[0] = stage_v_69_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int sub_step_70_1 = ((sub_step_60_1 + pub_r000393_6_1) + 18) & 127;
  int sub_step_70_2 = ((sub_step_60_2 + pub_r000393_6_2) + 18) & 127;
  int stage_v_70_1 = ((sub_step_70_1 * 2) + pub_r000393_15_1) & 127;
  int stage_v_70_2 = ((sub_step_70_2 * 2) + pub_r000393_15_2) & 127;
  st_var_1_1.buffer[1] = stage_v_70_1 & 15;
  st_var_1_2.buffer[1] = stage_v_70_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int sub_step_71_1 = ((sec_r000393_6_1 + pub_r000393_11_1) + 28) & 127;
  int sub_step_71_2 = ((sec_r000393_6_2 + pub_r000393_11_2) + 28) & 127;
  int stage_v_71_1 = ((sub_step_71_1 * 2) + pub_r000393_7_1) & 127;
  int stage_v_71_2 = ((sub_step_71_2 * 2) + pub_r000393_7_2) & 127;
  st_var_2_1.buffer[2] = stage_v_71_1 & 15;
  st_var_2_2.buffer[2] = stage_v_71_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int sub_step_72_1 = ((sec_r000393_6_1 + pub_r000393_6_1) + 14) & 127;
  int sub_step_72_2 = ((sec_r000393_6_2 + pub_r000393_6_2) + 14) & 127;
  int stage_v_72_1 = ((sub_step_72_1 * 2) + pub_r000393_7_1) & 127;
  int stage_v_72_2 = ((sub_step_72_2 * 2) + pub_r000393_7_2) & 127;
  st_var_0_1.buffer[0] = stage_v_72_1 & 15;
  st_var_0_2.buffer[0] = stage_v_72_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int sub_step_73_1 = ((sec_r000393_2_1 + pub_r000393_17_1) + 29) & 127;
  int sub_step_73_2 = ((sec_r000393_2_2 + pub_r000393_17_2) + 29) & 127;
  int stage_v_73_1 = ((sub_step_73_1 * 2) + pub_r000393_1_1) & 127;
  int stage_v_73_2 = ((sub_step_73_2 * 2) + pub_r000393_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_73_1 & 15;
  st_var_1_2.buffer[1] = stage_v_73_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int sub_step_74_1 = ((sec_r000393_2_1 + pub_r000393_11_1) + 17) & 127;
  int sub_step_74_2 = ((sec_r000393_2_2 + pub_r000393_11_2) + 17) & 127;
  int stage_v_74_1 = ((sub_step_74_1 * 2) + pub_r000393_12_1) & 127;
  int stage_v_74_2 = ((sub_step_74_2 * 2) + pub_r000393_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_74_1 & 15;
  st_var_2_2.buffer[2] = stage_v_74_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int sub_step_75_1 = ((sec_r000393_6_1 + pub_r000393_10_1) + 14) & 127;
  int sub_step_75_2 = ((sec_r000393_6_2 + pub_r000393_10_2) + 14) & 127;
  int stage_v_75_1 = ((sub_step_75_1 * 2) + pub_r000393_7_1) & 127;
  int stage_v_75_2 = ((sub_step_75_2 * 2) + pub_r000393_7_2) & 127;
  st_var_0_1.buffer[0] = stage_v_75_1 & 15;
  st_var_0_2.buffer[0] = stage_v_75_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int sub_step_76_1 = ((stage_v_66_1 + pub_r000393_1_1) + 20) & 127;
  int sub_step_76_2 = ((stage_v_66_2 + pub_r000393_1_2) + 20) & 127;
  int stage_v_76_1 = ((sub_step_76_1 * 2) + pub_r000393_14_1) & 127;
  int stage_v_76_2 = ((sub_step_76_2 * 2) + pub_r000393_14_2) & 127;
  st_var_1_1.buffer[1] = stage_v_76_1 & 15;
  st_var_1_2.buffer[1] = stage_v_76_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int sub_step_77_1 = ((stage_v_65_1 + pub_r000393_9_1) + 10) & 127;
  int sub_step_77_2 = ((stage_v_65_2 + pub_r000393_9_2) + 10) & 127;
  int stage_v_77_1 = ((sub_step_77_1 * 2) + pub_r000393_4_1) & 127;
  int stage_v_77_2 = ((sub_step_77_2 * 2) + pub_r000393_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_77_1 & 15;
  st_var_2_2.buffer[2] = stage_v_77_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int sub_step_78_1 = ((stage_v_55_1 + pub_r000393_2_1) + 19) & 127;
  int sub_step_78_2 = ((stage_v_55_2 + pub_r000393_2_2) + 19) & 127;
  int stage_v_78_1 = ((sub_step_78_1 * 2) + pub_r000393_12_1) & 127;
  int stage_v_78_2 = ((sub_step_78_2 * 2) + pub_r000393_12_2) & 127;
  st_var_0_1.buffer[0] = stage_v_78_1 & 15;
  st_var_0_2.buffer[0] = stage_v_78_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int sub_step_79_1 = ((sub_step_54_1 + pub_r000393_3_1) + 7) & 127;
  int sub_step_79_2 = ((sub_step_54_2 + pub_r000393_3_2) + 7) & 127;
  int stage_v_79_1 = ((sub_step_79_1 * 2) + pub_r000393_0_1) & 127;
  int stage_v_79_2 = ((sub_step_79_2 * 2) + pub_r000393_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_79_1 & 15;
  st_var_1_2.buffer[1] = stage_v_79_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int sub_step_80_1 = ((sec_r000393_15_1 + pub_r000393_7_1) + 30) & 127;
  int sub_step_80_2 = ((sec_r000393_15_2 + pub_r000393_7_2) + 30) & 127;
  int stage_v_80_1 = ((sub_step_80_1 * 2) + pub_r000393_4_1) & 127;
  int stage_v_80_2 = ((sub_step_80_2 * 2) + pub_r000393_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_80_1 & 15;
  st_var_2_2.buffer[2] = stage_v_80_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int sub_step_81_1 = ((sec_r000393_8_1 + pub_r000393_5_1) + 26) & 127;
  int sub_step_81_2 = ((sec_r000393_8_2 + pub_r000393_5_2) + 26) & 127;
  int stage_v_81_1 = ((sub_step_81_1 * 2) + pub_r000393_6_1) & 127;
  int stage_v_81_2 = ((sub_step_81_2 * 2) + pub_r000393_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_81_1 & 15;
  st_var_0_2.buffer[0] = stage_v_81_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int sub_step_82_1 = ((sec_r000393_10_1 + pub_r000393_15_1) + 26) & 127;
  int sub_step_82_2 = ((sec_r000393_10_2 + pub_r000393_15_2) + 26) & 127;
  int stage_v_82_1 = ((sub_step_82_1 * 2) + pub_r000393_8_1) & 127;
  int stage_v_82_2 = ((sub_step_82_2 * 2) + pub_r000393_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_82_1 & 15;
  st_var_1_2.buffer[1] = stage_v_82_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int sub_step_83_1 = ((sec_r000393_4_1 + pub_r000393_6_1) + 34) & 127;
  int sub_step_83_2 = ((sec_r000393_4_2 + pub_r000393_6_2) + 34) & 127;
  int stage_v_83_1 = ((sub_step_83_1 * 2) + pub_r000393_11_1) & 127;
  int stage_v_83_2 = ((sub_step_83_2 * 2) + pub_r000393_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_83_1 & 15;
  st_var_2_2.buffer[2] = stage_v_83_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int sub_step_84_1 = ((stage_v_65_1 + pub_r000393_11_1) + 24) & 127;
  int sub_step_84_2 = ((stage_v_65_2 + pub_r000393_11_2) + 24) & 127;
  int stage_v_84_1 = ((sub_step_84_1 * 2) + pub_r000393_13_1) & 127;
  int stage_v_84_2 = ((sub_step_84_2 * 2) + pub_r000393_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_84_1 & 15;
  st_var_0_2.buffer[0] = stage_v_84_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int sub_step_85_1 = ((sub_step_83_1 + pub_r000393_0_1) + 32) & 127;
  int sub_step_85_2 = ((sub_step_83_2 + pub_r000393_0_2) + 32) & 127;
  int stage_v_85_1 = ((sub_step_85_1 * 2) + pub_r000393_0_1) & 127;
  int stage_v_85_2 = ((sub_step_85_2 * 2) + pub_r000393_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_85_1 & 15;
  st_var_1_2.buffer[1] = stage_v_85_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int sub_step_86_1 = ((stage_v_53_1 + pub_r000393_3_1) + 21) & 127;
  int sub_step_86_2 = ((stage_v_53_2 + pub_r000393_3_2) + 21) & 127;
  int stage_v_86_1 = ((sub_step_86_1 * 2) + pub_r000393_11_1) & 127;
  int stage_v_86_2 = ((sub_step_86_2 * 2) + pub_r000393_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_86_1 & 15;
  st_var_2_2.buffer[2] = stage_v_86_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int sub_step_87_1 = ((stage_v_59_1 + pub_r000393_9_1) + 23) & 127;
  int sub_step_87_2 = ((stage_v_59_2 + pub_r000393_9_2) + 23) & 127;
  int stage_v_87_1 = ((sub_step_87_1 * 2) + pub_r000393_1_1) & 127;
  int stage_v_87_2 = ((sub_step_87_2 * 2) + pub_r000393_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_87_1 & 15;
  st_var_0_2.buffer[0] = stage_v_87_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int sub_step_88_1 = ((sec_r000393_6_1 + pub_r000393_7_1) + 17) & 127;
  int sub_step_88_2 = ((sec_r000393_6_2 + pub_r000393_7_2) + 17) & 127;
  int stage_v_88_1 = ((sub_step_88_1 * 2) + pub_r000393_5_1) & 127;
  int stage_v_88_2 = ((sub_step_88_2 * 2) + pub_r000393_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_88_1 & 15;
  st_var_1_2.buffer[1] = stage_v_88_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int sub_step_89_1 = ((sub_step_59_1 + pub_r000393_12_1) + 8) & 127;
  int sub_step_89_2 = ((sub_step_59_2 + pub_r000393_12_2) + 8) & 127;
  int stage_v_89_1 = ((sub_step_89_1 * 2) + pub_r000393_16_1) & 127;
  int stage_v_89_2 = ((sub_step_89_2 * 2) + pub_r000393_16_2) & 127;
  st_var_2_1.buffer[2] = stage_v_89_1 & 15;
  st_var_2_2.buffer[2] = stage_v_89_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int sub_step_90_1 = ((sec_r000393_14_1 + pub_r000393_12_1) + 33) & 127;
  int sub_step_90_2 = ((sec_r000393_14_2 + pub_r000393_12_2) + 33) & 127;
  int stage_v_90_1 = ((sub_step_90_1 * 2) + pub_r000393_13_1) & 127;
  int stage_v_90_2 = ((sub_step_90_2 * 2) + pub_r000393_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_90_1 & 15;
  st_var_0_2.buffer[0] = stage_v_90_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int sub_step_91_1 = ((stage_v_52_1 + pub_r000393_2_1) + 22) & 127;
  int sub_step_91_2 = ((stage_v_52_2 + pub_r000393_2_2) + 22) & 127;
  int stage_v_91_1 = ((sub_step_91_1 * 2) + pub_r000393_11_1) & 127;
  int stage_v_91_2 = ((sub_step_91_2 * 2) + pub_r000393_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_91_1 & 15;
  st_var_1_2.buffer[1] = stage_v_91_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int sub_step_92_1 = ((sec_r000393_11_1 + pub_r000393_11_1) + 34) & 127;
  int sub_step_92_2 = ((sec_r000393_11_2 + pub_r000393_11_2) + 34) & 127;
  int stage_v_92_1 = ((sub_step_92_1 * 2) + pub_r000393_6_1) & 127;
  int stage_v_92_2 = ((sub_step_92_2 * 2) + pub_r000393_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_92_1 & 15;
  st_var_2_2.buffer[2] = stage_v_92_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int sub_step_93_1 = ((stage_v_52_1 + pub_r000393_1_1) + 6) & 127;
  int sub_step_93_2 = ((stage_v_52_2 + pub_r000393_1_2) + 6) & 127;
  int stage_v_93_1 = ((sub_step_93_1 * 2) + pub_r000393_16_1) & 127;
  int stage_v_93_2 = ((sub_step_93_2 * 2) + pub_r000393_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_93_1 & 15;
  st_var_0_2.buffer[0] = stage_v_93_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int sub_step_94_1 = ((stage_v_88_1 + pub_r000393_3_1) + 33) & 127;
  int sub_step_94_2 = ((stage_v_88_2 + pub_r000393_3_2) + 33) & 127;
  int stage_v_94_1 = ((sub_step_94_1 * 2) + pub_r000393_5_1) & 127;
  int stage_v_94_2 = ((sub_step_94_2 * 2) + pub_r000393_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_94_1 & 15;
  st_var_1_2.buffer[1] = stage_v_94_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int sub_step_95_1 = ((sec_r000393_6_1 + pub_r000393_14_1) + 18) & 127;
  int sub_step_95_2 = ((sec_r000393_6_2 + pub_r000393_14_2) + 18) & 127;
  int stage_v_95_1 = ((sub_step_95_1 * 2) + pub_r000393_4_1) & 127;
  int stage_v_95_2 = ((sub_step_95_2 * 2) + pub_r000393_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_95_1 & 15;
  st_var_2_2.buffer[2] = stage_v_95_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int sub_step_96_1 = ((sub_step_64_1 + pub_r000393_9_1) + 10) & 127;
  int sub_step_96_2 = ((sub_step_64_2 + pub_r000393_9_2) + 10) & 127;
  int stage_v_96_1 = ((sub_step_96_1 * 2) + pub_r000393_5_1) & 127;
  int stage_v_96_2 = ((sub_step_96_2 * 2) + pub_r000393_5_2) & 127;
  st_var_0_1.buffer[0] = stage_v_96_1 & 15;
  st_var_0_2.buffer[0] = stage_v_96_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int sub_step_97_1 = ((sub_step_87_1 + pub_r000393_13_1) + 6) & 127;
  int sub_step_97_2 = ((sub_step_87_2 + pub_r000393_13_2) + 6) & 127;
  int stage_v_97_1 = ((sub_step_97_1 * 2) + pub_r000393_11_1) & 127;
  int stage_v_97_2 = ((sub_step_97_2 * 2) + pub_r000393_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_97_1 & 15;
  st_var_1_2.buffer[1] = stage_v_97_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int sub_step_98_1 = ((sec_r000393_9_1 + pub_r000393_13_1) + 5) & 127;
  int sub_step_98_2 = ((sec_r000393_9_2 + pub_r000393_13_2) + 5) & 127;
  int stage_v_98_1 = ((sub_step_98_1 * 2) + pub_r000393_7_1) & 127;
  int stage_v_98_2 = ((sub_step_98_2 * 2) + pub_r000393_7_2) & 127;
  st_var_2_1.buffer[2] = stage_v_98_1 & 15;
  st_var_2_2.buffer[2] = stage_v_98_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int sub_step_99_1 = ((stage_v_79_1 + pub_r000393_5_1) + 32) & 127;
  int sub_step_99_2 = ((stage_v_79_2 + pub_r000393_5_2) + 32) & 127;
  int stage_v_99_1 = ((sub_step_99_1 * 2) + pub_r000393_4_1) & 127;
  int stage_v_99_2 = ((sub_step_99_2 * 2) + pub_r000393_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_99_1 & 15;
  st_var_0_2.buffer[0] = stage_v_99_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int sub_step_100_1 = ((stage_v_53_1 + pub_r000393_6_1) + 8) & 127;
  int sub_step_100_2 = ((stage_v_53_2 + pub_r000393_6_2) + 8) & 127;
  int stage_v_100_1 = ((sub_step_100_1 * 2) + pub_r000393_13_1) & 127;
  int stage_v_100_2 = ((sub_step_100_2 * 2) + pub_r000393_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_100_1 & 15;
  st_var_1_2.buffer[1] = stage_v_100_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int sub_step_101_1 = ((sub_step_94_1 + pub_r000393_8_1) + 31) & 127;
  int sub_step_101_2 = ((sub_step_94_2 + pub_r000393_8_2) + 31) & 127;
  int stage_v_101_1 = ((sub_step_101_1 * 2) + pub_r000393_11_1) & 127;
  int stage_v_101_2 = ((sub_step_101_2 * 2) + pub_r000393_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_101_1 & 15;
  st_var_2_2.buffer[2] = stage_v_101_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int sub_step_102_1 = ((stage_v_87_1 + pub_r000393_1_1) + 7) & 127;
  int sub_step_102_2 = ((stage_v_87_2 + pub_r000393_1_2) + 7) & 127;
  int stage_v_102_1 = ((sub_step_102_1 * 2) + pub_r000393_6_1) & 127;
  int stage_v_102_2 = ((sub_step_102_2 * 2) + pub_r000393_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_102_1 & 15;
  st_var_0_2.buffer[0] = stage_v_102_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int sub_step_103_1 = ((stage_v_56_1 + pub_r000393_7_1) + 24) & 127;
  int sub_step_103_2 = ((stage_v_56_2 + pub_r000393_7_2) + 24) & 127;
  int stage_v_103_1 = ((sub_step_103_1 * 2) + pub_r000393_7_1) & 127;
  int stage_v_103_2 = ((sub_step_103_2 * 2) + pub_r000393_7_2) & 127;
  st_var_1_1.buffer[1] = stage_v_103_1 & 15;
  st_var_1_2.buffer[1] = stage_v_103_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int sub_step_104_1 = ((sub_step_63_1 + pub_r000393_7_1) + 11) & 127;
  int sub_step_104_2 = ((sub_step_63_2 + pub_r000393_7_2) + 11) & 127;
  int stage_v_104_1 = ((sub_step_104_1 * 2) + pub_r000393_16_1) & 127;
  int stage_v_104_2 = ((sub_step_104_2 * 2) + pub_r000393_16_2) & 127;
  st_var_2_1.buffer[2] = stage_v_104_1 & 15;
  st_var_2_2.buffer[2] = stage_v_104_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int sub_step_105_1 = ((stage_v_75_1 + pub_r000393_0_1) + 29) & 127;
  int sub_step_105_2 = ((stage_v_75_2 + pub_r000393_0_2) + 29) & 127;
  int stage_v_105_1 = ((sub_step_105_1 * 2) + pub_r000393_10_1) & 127;
  int stage_v_105_2 = ((sub_step_105_2 * 2) + pub_r000393_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_105_1 & 15;
  st_var_0_2.buffer[0] = stage_v_105_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int sub_step_106_1 = ((sec_r000393_5_1 + pub_r000393_10_1) + 22) & 127;
  int sub_step_106_2 = ((sec_r000393_5_2 + pub_r000393_10_2) + 22) & 127;
  int stage_v_106_1 = ((sub_step_106_1 * 2) + pub_r000393_10_1) & 127;
  int stage_v_106_2 = ((sub_step_106_2 * 2) + pub_r000393_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_106_1 & 15;
  st_var_1_2.buffer[1] = stage_v_106_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int sub_step_107_1 = ((sec_r000393_11_1 + pub_r000393_1_1) + 24) & 127;
  int sub_step_107_2 = ((sec_r000393_11_2 + pub_r000393_1_2) + 24) & 127;
  int stage_v_107_1 = ((sub_step_107_1 * 2) + pub_r000393_12_1) & 127;
  int stage_v_107_2 = ((sub_step_107_2 * 2) + pub_r000393_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_107_1 & 15;
  st_var_2_2.buffer[2] = stage_v_107_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int sub_step_108_1 = ((stage_v_79_1 + pub_r000393_9_1) + 19) & 127;
  int sub_step_108_2 = ((stage_v_79_2 + pub_r000393_9_2) + 19) & 127;
  int stage_v_108_1 = ((sub_step_108_1 * 2) + pub_r000393_0_1) & 127;
  int stage_v_108_2 = ((sub_step_108_2 * 2) + pub_r000393_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_108_1 & 15;
  st_var_0_2.buffer[0] = stage_v_108_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int sub_step_109_1 = ((sec_r000393_12_1 + pub_r000393_11_1) + 14) & 127;
  int sub_step_109_2 = ((sec_r000393_12_2 + pub_r000393_11_2) + 14) & 127;
  int stage_v_109_1 = ((sub_step_109_1 * 2) + pub_r000393_11_1) & 127;
  int stage_v_109_2 = ((sub_step_109_2 * 2) + pub_r000393_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_109_1 & 15;
  st_var_1_2.buffer[1] = stage_v_109_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int sub_step_110_1 = ((sub_step_107_1 + pub_r000393_2_1) + 14) & 127;
  int sub_step_110_2 = ((sub_step_107_2 + pub_r000393_2_2) + 14) & 127;
  int stage_v_110_1 = ((sub_step_110_1 * 2) + pub_r000393_12_1) & 127;
  int stage_v_110_2 = ((sub_step_110_2 * 2) + pub_r000393_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_110_1 & 15;
  st_var_2_2.buffer[2] = stage_v_110_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int sub_step_111_1 = ((sub_step_66_1 + pub_r000393_0_1) + 34) & 127;
  int sub_step_111_2 = ((sub_step_66_2 + pub_r000393_0_2) + 34) & 127;
  int stage_v_111_1 = ((sub_step_111_1 * 2) + pub_r000393_6_1) & 127;
  int stage_v_111_2 = ((sub_step_111_2 * 2) + pub_r000393_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_111_1 & 15;
  st_var_0_2.buffer[0] = stage_v_111_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int sub_step_112_1 = ((sec_r000393_6_1 + pub_r000393_7_1) + 7) & 127;
  int sub_step_112_2 = ((sec_r000393_6_2 + pub_r000393_7_2) + 7) & 127;
  int stage_v_112_1 = ((sub_step_112_1 * 2) + pub_r000393_10_1) & 127;
  int stage_v_112_2 = ((sub_step_112_2 * 2) + pub_r000393_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_112_1 & 15;
  st_var_1_2.buffer[1] = stage_v_112_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int sub_step_113_1 = ((sub_step_62_1 + pub_r000393_0_1) + 17) & 127;
  int sub_step_113_2 = ((sub_step_62_2 + pub_r000393_0_2) + 17) & 127;
  int stage_v_113_1 = ((sub_step_113_1 * 2) + pub_r000393_4_1) & 127;
  int stage_v_113_2 = ((sub_step_113_2 * 2) + pub_r000393_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_113_1 & 15;
  st_var_2_2.buffer[2] = stage_v_113_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int sub_step_114_1 = ((sec_r000393_0_1 + pub_r000393_6_1) + 27) & 127;
  int sub_step_114_2 = ((sec_r000393_0_2 + pub_r000393_6_2) + 27) & 127;
  int stage_v_114_1 = ((sub_step_114_1 * 2) + pub_r000393_7_1) & 127;
  int stage_v_114_2 = ((sub_step_114_2 * 2) + pub_r000393_7_2) & 127;
  st_var_0_1.buffer[0] = stage_v_114_1 & 15;
  st_var_0_2.buffer[0] = stage_v_114_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int sub_step_115_1 = ((stage_v_80_1 + pub_r000393_6_1) + 29) & 127;
  int sub_step_115_2 = ((stage_v_80_2 + pub_r000393_6_2) + 29) & 127;
  int stage_v_115_1 = ((sub_step_115_1 * 2) + pub_r000393_2_1) & 127;
  int stage_v_115_2 = ((sub_step_115_2 * 2) + pub_r000393_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_115_1 & 15;
  st_var_1_2.buffer[1] = stage_v_115_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int sub_step_116_1 = ((sec_r000393_10_1 + pub_r000393_3_1) + 9) & 127;
  int sub_step_116_2 = ((sec_r000393_10_2 + pub_r000393_3_2) + 9) & 127;
  int stage_v_116_1 = ((sub_step_116_1 * 2) + pub_r000393_12_1) & 127;
  int stage_v_116_2 = ((sub_step_116_2 * 2) + pub_r000393_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_116_1 & 15;
  st_var_2_2.buffer[2] = stage_v_116_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int sub_step_117_1 = ((stage_v_51_1 + pub_r000393_12_1) + 9) & 127;
  int sub_step_117_2 = ((stage_v_51_2 + pub_r000393_12_2) + 9) & 127;
  int stage_v_117_1 = ((sub_step_117_1 * 2) + pub_r000393_1_1) & 127;
  int stage_v_117_2 = ((sub_step_117_2 * 2) + pub_r000393_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_117_1 & 15;
  st_var_0_2.buffer[0] = stage_v_117_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int sub_step_118_1 = ((sec_r000393_13_1 + pub_r000393_11_1) + 35) & 127;
  int sub_step_118_2 = ((sec_r000393_13_2 + pub_r000393_11_2) + 35) & 127;
  int stage_v_118_1 = ((sub_step_118_1 * 2) + pub_r000393_12_1) & 127;
  int stage_v_118_2 = ((sub_step_118_2 * 2) + pub_r000393_12_2) & 127;
  st_var_1_1.buffer[1] = stage_v_118_1 & 15;
  st_var_1_2.buffer[1] = stage_v_118_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int sub_step_119_1 = ((stage_v_90_1 + pub_r000393_13_1) + 35) & 127;
  int sub_step_119_2 = ((stage_v_90_2 + pub_r000393_13_2) + 35) & 127;
  int stage_v_119_1 = ((sub_step_119_1 * 2) + pub_r000393_8_1) & 127;
  int stage_v_119_2 = ((sub_step_119_2 * 2) + pub_r000393_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_119_1 & 15;
  st_var_2_2.buffer[2] = stage_v_119_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int sub_step_120_1 = ((sec_r000393_14_1 + pub_r000393_16_1) + 30) & 127;
  int sub_step_120_2 = ((sec_r000393_14_2 + pub_r000393_16_2) + 30) & 127;
  int stage_v_120_1 = ((sub_step_120_1 * 2) + pub_r000393_16_1) & 127;
  int stage_v_120_2 = ((sub_step_120_2 * 2) + pub_r000393_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_120_1 & 15;
  st_var_0_2.buffer[0] = stage_v_120_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int sub_step_121_1 = ((sub_step_105_1 + pub_r000393_12_1) + 19) & 127;
  int sub_step_121_2 = ((sub_step_105_2 + pub_r000393_12_2) + 19) & 127;
  int stage_v_121_1 = ((sub_step_121_1 * 2) + pub_r000393_14_1) & 127;
  int stage_v_121_2 = ((sub_step_121_2 * 2) + pub_r000393_14_2) & 127;
  st_var_1_1.buffer[1] = stage_v_121_1 & 15;
  st_var_1_2.buffer[1] = stage_v_121_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int sub_step_122_1 = ((stage_v_89_1 + pub_r000393_6_1) + 29) & 127;
  int sub_step_122_2 = ((stage_v_89_2 + pub_r000393_6_2) + 29) & 127;
  int stage_v_122_1 = ((sub_step_122_1 * 2) + pub_r000393_8_1) & 127;
  int stage_v_122_2 = ((sub_step_122_2 * 2) + pub_r000393_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_122_1 & 15;
  st_var_2_2.buffer[2] = stage_v_122_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int sub_step_123_1 = ((sec_r000393_9_1 + pub_r000393_6_1) + 12) & 127;
  int sub_step_123_2 = ((sec_r000393_9_2 + pub_r000393_6_2) + 12) & 127;
  int stage_v_123_1 = ((sub_step_123_1 * 2) + pub_r000393_10_1) & 127;
  int stage_v_123_2 = ((sub_step_123_2 * 2) + pub_r000393_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_123_1 & 15;
  st_var_0_2.buffer[0] = stage_v_123_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int sub_step_124_1 = ((stage_v_81_1 + pub_r000393_3_1) + 25) & 127;
  int sub_step_124_2 = ((stage_v_81_2 + pub_r000393_3_2) + 25) & 127;
  int stage_v_124_1 = ((sub_step_124_1 * 2) + pub_r000393_8_1) & 127;
  int stage_v_124_2 = ((sub_step_124_2 * 2) + pub_r000393_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_124_1 & 15;
  st_var_1_2.buffer[1] = stage_v_124_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int sub_step_125_1 = ((sub_step_56_1 + pub_r000393_7_1) + 14) & 127;
  int sub_step_125_2 = ((sub_step_56_2 + pub_r000393_7_2) + 14) & 127;
  int stage_v_125_1 = ((sub_step_125_1 * 2) + pub_r000393_9_1) & 127;
  int stage_v_125_2 = ((sub_step_125_2 * 2) + pub_r000393_9_2) & 127;
  st_var_2_1.buffer[2] = stage_v_125_1 & 15;
  st_var_2_2.buffer[2] = stage_v_125_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int sub_step_126_1 = ((sub_step_121_1 + pub_r000393_4_1) + 5) & 127;
  int sub_step_126_2 = ((sub_step_121_2 + pub_r000393_4_2) + 5) & 127;
  int stage_v_126_1 = ((sub_step_126_1 * 2) + pub_r000393_4_1) & 127;
  int stage_v_126_2 = ((sub_step_126_2 * 2) + pub_r000393_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_126_1 & 15;
  st_var_0_2.buffer[0] = stage_v_126_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int sub_step_127_1 = ((stage_v_67_1 + pub_r000393_0_1) + 7) & 127;
  int sub_step_127_2 = ((stage_v_67_2 + pub_r000393_0_2) + 7) & 127;
  int stage_v_127_1 = ((sub_step_127_1 * 2) + pub_r000393_5_1) & 127;
  int stage_v_127_2 = ((sub_step_127_2 * 2) + pub_r000393_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_127_1 & 15;
  st_var_1_2.buffer[1] = stage_v_127_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int sub_step_128_1 = ((stage_v_127_1 + pub_r000393_5_1) + 33) & 127;
  int sub_step_128_2 = ((stage_v_127_2 + pub_r000393_5_2) + 33) & 127;
  int stage_v_128_1 = ((sub_step_128_1 * 2) + pub_r000393_4_1) & 127;
  int stage_v_128_2 = ((sub_step_128_2 * 2) + pub_r000393_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_128_1 & 15;
  st_var_2_2.buffer[2] = stage_v_128_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int sub_step_129_1 = ((sub_step_98_1 + pub_r000393_1_1) + 35) & 127;
  int sub_step_129_2 = ((sub_step_98_2 + pub_r000393_1_2) + 35) & 127;
  int stage_v_129_1 = ((sub_step_129_1 * 2) + pub_r000393_11_1) & 127;
  int stage_v_129_2 = ((sub_step_129_2 * 2) + pub_r000393_11_2) & 127;
  st_var_0_1.buffer[0] = stage_v_129_1 & 15;
  st_var_0_2.buffer[0] = stage_v_129_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int sub_step_130_1 = ((sub_step_114_1 + pub_r000393_0_1) + 24) & 127;
  int sub_step_130_2 = ((sub_step_114_2 + pub_r000393_0_2) + 24) & 127;
  int stage_v_130_1 = ((sub_step_130_1 * 2) + pub_r000393_10_1) & 127;
  int stage_v_130_2 = ((sub_step_130_2 * 2) + pub_r000393_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_130_1 & 15;
  st_var_1_2.buffer[1] = stage_v_130_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int sub_step_131_1 = ((sub_step_64_1 + pub_r000393_11_1) + 6) & 127;
  int sub_step_131_2 = ((sub_step_64_2 + pub_r000393_11_2) + 6) & 127;
  int stage_v_131_1 = ((sub_step_131_1 * 2) + pub_r000393_6_1) & 127;
  int stage_v_131_2 = ((sub_step_131_2 * 2) + pub_r000393_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_131_1 & 15;
  st_var_2_2.buffer[2] = stage_v_131_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int sub_step_132_1 = ((stage_v_111_1 + pub_r000393_17_1) + 22) & 127;
  int sub_step_132_2 = ((stage_v_111_2 + pub_r000393_17_2) + 22) & 127;
  int stage_v_132_1 = ((sub_step_132_1 * 2) + pub_r000393_5_1) & 127;
  int stage_v_132_2 = ((sub_step_132_2 * 2) + pub_r000393_5_2) & 127;
  st_var_0_1.buffer[0] = stage_v_132_1 & 15;
  st_var_0_2.buffer[0] = stage_v_132_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int sub_step_133_1 = ((sec_r000393_12_1 + pub_r000393_10_1) + 19) & 127;
  int sub_step_133_2 = ((sec_r000393_12_2 + pub_r000393_10_2) + 19) & 127;
  int stage_v_133_1 = ((sub_step_133_1 * 2) + pub_r000393_17_1) & 127;
  int stage_v_133_2 = ((sub_step_133_2 * 2) + pub_r000393_17_2) & 127;
  st_var_1_1.buffer[1] = stage_v_133_1 & 15;
  st_var_1_2.buffer[1] = stage_v_133_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int sub_step_134_1 = ((sub_step_126_1 + pub_r000393_13_1) + 26) & 127;
  int sub_step_134_2 = ((sub_step_126_2 + pub_r000393_13_2) + 26) & 127;
  int stage_v_134_1 = ((sub_step_134_1 * 2) + pub_r000393_6_1) & 127;
  int stage_v_134_2 = ((sub_step_134_2 * 2) + pub_r000393_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_134_1 & 15;
  st_var_2_2.buffer[2] = stage_v_134_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int sub_step_135_1 = ((sub_step_68_1 + pub_r000393_3_1) + 32) & 127;
  int sub_step_135_2 = ((sub_step_68_2 + pub_r000393_3_2) + 32) & 127;
  int stage_v_135_1 = ((sub_step_135_1 * 2) + pub_r000393_17_1) & 127;
  int stage_v_135_2 = ((sub_step_135_2 * 2) + pub_r000393_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_135_1 & 15;
  st_var_0_2.buffer[0] = stage_v_135_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int sub_step_136_1 = ((sub_step_118_1 + pub_r000393_16_1) + 21) & 127;
  int sub_step_136_2 = ((sub_step_118_2 + pub_r000393_16_2) + 21) & 127;
  int stage_v_136_1 = ((sub_step_136_1 * 2) + pub_r000393_10_1) & 127;
  int stage_v_136_2 = ((sub_step_136_2 * 2) + pub_r000393_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_136_1 & 15;
  st_var_1_2.buffer[1] = stage_v_136_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int sub_step_137_1 = ((sub_step_88_1 + pub_r000393_1_1) + 7) & 127;
  int sub_step_137_2 = ((sub_step_88_2 + pub_r000393_1_2) + 7) & 127;
  int stage_v_137_1 = ((sub_step_137_1 * 2) + pub_r000393_1_1) & 127;
  int stage_v_137_2 = ((sub_step_137_2 * 2) + pub_r000393_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_137_1 & 15;
  st_var_2_2.buffer[2] = stage_v_137_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int sub_step_138_1 = ((sec_r000393_11_1 + pub_r000393_10_1) + 27) & 127;
  int sub_step_138_2 = ((sec_r000393_11_2 + pub_r000393_10_2) + 27) & 127;
  int stage_v_138_1 = ((sub_step_138_1 * 2) + pub_r000393_1_1) & 127;
  int stage_v_138_2 = ((sub_step_138_2 * 2) + pub_r000393_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_138_1 & 15;
  st_var_0_2.buffer[0] = stage_v_138_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int sub_step_139_1 = ((stage_v_115_1 + pub_r000393_14_1) + 11) & 127;
  int sub_step_139_2 = ((stage_v_115_2 + pub_r000393_14_2) + 11) & 127;
  int stage_v_139_1 = ((sub_step_139_1 * 2) + pub_r000393_16_1) & 127;
  int stage_v_139_2 = ((sub_step_139_2 * 2) + pub_r000393_16_2) & 127;
  st_var_1_1.buffer[1] = stage_v_139_1 & 15;
  st_var_1_2.buffer[1] = stage_v_139_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int sub_step_140_1 = ((sub_step_66_1 + pub_r000393_17_1) + 28) & 127;
  int sub_step_140_2 = ((sub_step_66_2 + pub_r000393_17_2) + 28) & 127;
  int stage_v_140_1 = ((sub_step_140_1 * 2) + pub_r000393_11_1) & 127;
  int stage_v_140_2 = ((sub_step_140_2 * 2) + pub_r000393_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_140_1 & 15;
  st_var_2_2.buffer[2] = stage_v_140_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int sub_step_141_1 = ((sub_step_93_1 + pub_r000393_9_1) + 27) & 127;
  int sub_step_141_2 = ((sub_step_93_2 + pub_r000393_9_2) + 27) & 127;
  int stage_v_141_1 = ((sub_step_141_1 * 2) + pub_r000393_15_1) & 127;
  int stage_v_141_2 = ((sub_step_141_2 * 2) + pub_r000393_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_141_1 & 15;
  st_var_0_2.buffer[0] = stage_v_141_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int sub_step_142_1 = ((sub_step_96_1 + pub_r000393_5_1) + 15) & 127;
  int sub_step_142_2 = ((sub_step_96_2 + pub_r000393_5_2) + 15) & 127;
  int stage_v_142_1 = ((sub_step_142_1 * 2) + pub_r000393_6_1) & 127;
  int stage_v_142_2 = ((sub_step_142_2 * 2) + pub_r000393_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_142_1 & 15;
  st_var_1_2.buffer[1] = stage_v_142_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int sub_step_143_1 = ((sub_step_127_1 + pub_r000393_0_1) + 14) & 127;
  int sub_step_143_2 = ((sub_step_127_2 + pub_r000393_0_2) + 14) & 127;
  int stage_v_143_1 = ((sub_step_143_1 * 2) + pub_r000393_16_1) & 127;
  int stage_v_143_2 = ((sub_step_143_2 * 2) + pub_r000393_16_2) & 127;
  st_var_2_1.buffer[2] = stage_v_143_1 & 15;
  st_var_2_2.buffer[2] = stage_v_143_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int sub_step_144_1 = ((stage_v_128_1 + pub_r000393_4_1) + 17) & 127;
  int sub_step_144_2 = ((stage_v_128_2 + pub_r000393_4_2) + 17) & 127;
  int stage_v_144_1 = ((sub_step_144_1 * 2) + pub_r000393_3_1) & 127;
  int stage_v_144_2 = ((sub_step_144_2 * 2) + pub_r000393_3_2) & 127;
  st_var_0_1.buffer[0] = stage_v_144_1 & 15;
  st_var_0_2.buffer[0] = stage_v_144_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int sub_step_145_1 = ((sub_step_84_1 + pub_r000393_8_1) + 18) & 127;
  int sub_step_145_2 = ((sub_step_84_2 + pub_r000393_8_2) + 18) & 127;
  int stage_v_145_1 = ((sub_step_145_1 * 2) + pub_r000393_14_1) & 127;
  int stage_v_145_2 = ((sub_step_145_2 * 2) + pub_r000393_14_2) & 127;
  st_var_1_1.buffer[1] = stage_v_145_1 & 15;
  st_var_1_2.buffer[1] = stage_v_145_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int sub_step_146_1 = ((stage_v_61_1 + pub_r000393_12_1) + 24) & 127;
  int sub_step_146_2 = ((stage_v_61_2 + pub_r000393_12_2) + 24) & 127;
  int stage_v_146_1 = ((sub_step_146_1 * 2) + pub_r000393_1_1) & 127;
  int stage_v_146_2 = ((sub_step_146_2 * 2) + pub_r000393_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_146_1 & 15;
  st_var_2_2.buffer[2] = stage_v_146_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int sub_step_147_1 = ((sub_step_64_1 + pub_r000393_17_1) + 16) & 127;
  int sub_step_147_2 = ((sub_step_64_2 + pub_r000393_17_2) + 16) & 127;
  int stage_v_147_1 = ((sub_step_147_1 * 2) + pub_r000393_6_1) & 127;
  int stage_v_147_2 = ((sub_step_147_2 * 2) + pub_r000393_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_147_1 & 15;
  st_var_0_2.buffer[0] = stage_v_147_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int sub_step_148_1 = ((sub_step_103_1 + pub_r000393_5_1) + 23) & 127;
  int sub_step_148_2 = ((sub_step_103_2 + pub_r000393_5_2) + 23) & 127;
  int stage_v_148_1 = ((sub_step_148_1 * 2) + pub_r000393_1_1) & 127;
  int stage_v_148_2 = ((sub_step_148_2 * 2) + pub_r000393_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_148_1 & 15;
  st_var_1_2.buffer[1] = stage_v_148_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int sub_step_149_1 = ((sub_step_82_1 + pub_r000393_1_1) + 22) & 127;
  int sub_step_149_2 = ((sub_step_82_2 + pub_r000393_1_2) + 22) & 127;
  int stage_v_149_1 = ((sub_step_149_1 * 2) + pub_r000393_1_1) & 127;
  int stage_v_149_2 = ((sub_step_149_2 * 2) + pub_r000393_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_149_1 & 15;
  st_var_2_2.buffer[2] = stage_v_149_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int sub_step_150_1 = ((sec_r000393_2_1 + pub_r000393_6_1) + 18) & 127;
  int sub_step_150_2 = ((sec_r000393_2_2 + pub_r000393_6_2) + 18) & 127;
  int stage_v_150_1 = ((sub_step_150_1 * 2) + pub_r000393_11_1) & 127;
  int stage_v_150_2 = ((sub_step_150_2 * 2) + pub_r000393_11_2) & 127;
  st_var_0_1.buffer[0] = stage_v_150_1 & 15;
  st_var_0_2.buffer[0] = stage_v_150_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int sub_step_151_1 = ((sec_r000393_5_1 + pub_r000393_2_1) + 24) & 127;
  int sub_step_151_2 = ((sec_r000393_5_2 + pub_r000393_2_2) + 24) & 127;
  int stage_v_151_1 = ((sub_step_151_1 * 2) + pub_r000393_9_1) & 127;
  int stage_v_151_2 = ((sub_step_151_2 * 2) + pub_r000393_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_151_1 & 15;
  st_var_1_2.buffer[1] = stage_v_151_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int sub_step_152_1 = ((stage_v_61_1 + pub_r000393_0_1) + 29) & 127;
  int sub_step_152_2 = ((stage_v_61_2 + pub_r000393_0_2) + 29) & 127;
  int stage_v_152_1 = ((sub_step_152_1 * 2) + pub_r000393_4_1) & 127;
  int stage_v_152_2 = ((sub_step_152_2 * 2) + pub_r000393_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_152_1 & 15;
  st_var_2_2.buffer[2] = stage_v_152_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int sub_step_153_1 = ((sub_step_65_1 + pub_r000393_11_1) + 13) & 127;
  int sub_step_153_2 = ((sub_step_65_2 + pub_r000393_11_2) + 13) & 127;
  int stage_v_153_1 = ((sub_step_153_1 * 2) + pub_r000393_3_1) & 127;
  int stage_v_153_2 = ((sub_step_153_2 * 2) + pub_r000393_3_2) & 127;
  st_var_0_1.buffer[0] = stage_v_153_1 & 15;
  st_var_0_2.buffer[0] = stage_v_153_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int sub_step_154_1 = ((sub_step_53_1 + pub_r000393_14_1) + 29) & 127;
  int sub_step_154_2 = ((sub_step_53_2 + pub_r000393_14_2) + 29) & 127;
  int stage_v_154_1 = ((sub_step_154_1 * 2) + pub_r000393_0_1) & 127;
  int stage_v_154_2 = ((sub_step_154_2 * 2) + pub_r000393_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_154_1 & 15;
  st_var_1_2.buffer[1] = stage_v_154_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int sub_step_155_1 = ((sec_r000393_14_1 + pub_r000393_15_1) + 15) & 127;
  int sub_step_155_2 = ((sec_r000393_14_2 + pub_r000393_15_2) + 15) & 127;
  int stage_v_155_1 = ((sub_step_155_1 * 2) + pub_r000393_5_1) & 127;
  int stage_v_155_2 = ((sub_step_155_2 * 2) + pub_r000393_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_155_1 & 15;
  st_var_2_2.buffer[2] = stage_v_155_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int sub_step_156_1 = ((stage_v_103_1 + pub_r000393_3_1) + 19) & 127;
  int sub_step_156_2 = ((stage_v_103_2 + pub_r000393_3_2) + 19) & 127;
  int stage_v_156_1 = ((sub_step_156_1 * 2) + pub_r000393_17_1) & 127;
  int stage_v_156_2 = ((sub_step_156_2 * 2) + pub_r000393_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_156_1 & 15;
  st_var_0_2.buffer[0] = stage_v_156_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int sub_step_157_1 = ((stage_v_126_1 + pub_r000393_8_1) + 13) & 127;
  int sub_step_157_2 = ((stage_v_126_2 + pub_r000393_8_2) + 13) & 127;
  int stage_v_157_1 = ((sub_step_157_1 * 2) + pub_r000393_15_1) & 127;
  int stage_v_157_2 = ((sub_step_157_2 * 2) + pub_r000393_15_2) & 127;
  st_var_1_1.buffer[1] = stage_v_157_1 & 15;
  st_var_1_2.buffer[1] = stage_v_157_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int sub_step_158_1 = ((stage_v_89_1 + pub_r000393_13_1) + 9) & 127;
  int sub_step_158_2 = ((stage_v_89_2 + pub_r000393_13_2) + 9) & 127;
  int stage_v_158_1 = ((sub_step_158_1 * 2) + pub_r000393_3_1) & 127;
  int stage_v_158_2 = ((sub_step_158_2 * 2) + pub_r000393_3_2) & 127;
  st_var_2_1.buffer[2] = stage_v_158_1 & 15;
  st_var_2_2.buffer[2] = stage_v_158_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int sub_step_159_1 = ((stage_v_123_1 + pub_r000393_16_1) + 32) & 127;
  int sub_step_159_2 = ((stage_v_123_2 + pub_r000393_16_2) + 32) & 127;
  int stage_v_159_1 = ((sub_step_159_1 * 2) + pub_r000393_15_1) & 127;
  int stage_v_159_2 = ((sub_step_159_2 * 2) + pub_r000393_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_159_1 & 15;
  st_var_0_2.buffer[0] = stage_v_159_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int sub_step_160_1 = ((sec_r000393_2_1 + pub_r000393_4_1) + 8) & 127;
  int sub_step_160_2 = ((sec_r000393_2_2 + pub_r000393_4_2) + 8) & 127;
  int stage_v_160_1 = ((sub_step_160_1 * 2) + pub_r000393_0_1) & 127;
  int stage_v_160_2 = ((sub_step_160_2 * 2) + pub_r000393_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_160_1 & 15;
  st_var_1_2.buffer[1] = stage_v_160_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int sub_step_161_1 = ((sec_r000393_2_1 + pub_r000393_13_1) + 17) & 127;
  int sub_step_161_2 = ((sec_r000393_2_2 + pub_r000393_13_2) + 17) & 127;
  int stage_v_161_1 = ((sub_step_161_1 * 2) + pub_r000393_9_1) & 127;
  int stage_v_161_2 = ((sub_step_161_2 * 2) + pub_r000393_9_2) & 127;
  st_var_2_1.buffer[2] = stage_v_161_1 & 15;
  st_var_2_2.buffer[2] = stage_v_161_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int sub_step_162_1 = ((sub_step_84_1 + pub_r000393_3_1) + 19) & 127;
  int sub_step_162_2 = ((sub_step_84_2 + pub_r000393_3_2) + 19) & 127;
  int stage_v_162_1 = ((sub_step_162_1 * 2) + pub_r000393_12_1) & 127;
  int stage_v_162_2 = ((sub_step_162_2 * 2) + pub_r000393_12_2) & 127;
  st_var_0_1.buffer[0] = stage_v_162_1 & 15;
  st_var_0_2.buffer[0] = stage_v_162_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int sub_step_163_1 = ((stage_v_53_1 + pub_r000393_2_1) + 11) & 127;
  int sub_step_163_2 = ((stage_v_53_2 + pub_r000393_2_2) + 11) & 127;
  int stage_v_163_1 = ((sub_step_163_1 * 2) + pub_r000393_5_1) & 127;
  int stage_v_163_2 = ((sub_step_163_2 * 2) + pub_r000393_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_163_1 & 15;
  st_var_1_2.buffer[1] = stage_v_163_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int sub_step_164_1 = ((sec_r000393_4_1 + pub_r000393_13_1) + 30) & 127;
  int sub_step_164_2 = ((sec_r000393_4_2 + pub_r000393_13_2) + 30) & 127;
  int stage_v_164_1 = ((sub_step_164_1 * 2) + pub_r000393_12_1) & 127;
  int stage_v_164_2 = ((sub_step_164_2 * 2) + pub_r000393_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_164_1 & 15;
  st_var_2_2.buffer[2] = stage_v_164_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int sub_step_165_1 = ((stage_v_149_1 + pub_r000393_16_1) + 9) & 127;
  int sub_step_165_2 = ((stage_v_149_2 + pub_r000393_16_2) + 9) & 127;
  int stage_v_165_1 = ((sub_step_165_1 * 2) + pub_r000393_9_1) & 127;
  int stage_v_165_2 = ((sub_step_165_2 * 2) + pub_r000393_9_2) & 127;
  st_var_0_1.buffer[0] = stage_v_165_1 & 15;
  st_var_0_2.buffer[0] = stage_v_165_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int sub_step_166_1 = ((sec_r000393_1_1 + pub_r000393_11_1) + 6) & 127;
  int sub_step_166_2 = ((sec_r000393_1_2 + pub_r000393_11_2) + 6) & 127;
  int stage_v_166_1 = ((sub_step_166_1 * 2) + pub_r000393_12_1) & 127;
  int stage_v_166_2 = ((sub_step_166_2 * 2) + pub_r000393_12_2) & 127;
  st_var_1_1.buffer[1] = stage_v_166_1 & 15;
  st_var_1_2.buffer[1] = stage_v_166_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int sub_step_167_1 = ((sub_step_63_1 + pub_r000393_11_1) + 32) & 127;
  int sub_step_167_2 = ((sub_step_63_2 + pub_r000393_11_2) + 32) & 127;
  int stage_v_167_1 = ((sub_step_167_1 * 2) + pub_r000393_3_1) & 127;
  int stage_v_167_2 = ((sub_step_167_2 * 2) + pub_r000393_3_2) & 127;
  st_var_2_1.buffer[2] = stage_v_167_1 & 15;
  st_var_2_2.buffer[2] = stage_v_167_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int sub_step_168_1 = ((sub_step_129_1 + pub_r000393_6_1) + 5) & 127;
  int sub_step_168_2 = ((sub_step_129_2 + pub_r000393_6_2) + 5) & 127;
  int stage_v_168_1 = ((sub_step_168_1 * 2) + pub_r000393_9_1) & 127;
  int stage_v_168_2 = ((sub_step_168_2 * 2) + pub_r000393_9_2) & 127;
  st_var_0_1.buffer[0] = stage_v_168_1 & 15;
  st_var_0_2.buffer[0] = stage_v_168_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int sub_step_169_1 = ((sec_r000393_5_1 + pub_r000393_4_1) + 9) & 127;
  int sub_step_169_2 = ((sec_r000393_5_2 + pub_r000393_4_2) + 9) & 127;
  int stage_v_169_1 = ((sub_step_169_1 * 2) + pub_r000393_9_1) & 127;
  int stage_v_169_2 = ((sub_step_169_2 * 2) + pub_r000393_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_169_1 & 15;
  st_var_1_2.buffer[1] = stage_v_169_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int sub_step_170_1 = ((sub_step_57_1 + pub_r000393_17_1) + 8) & 127;
  int sub_step_170_2 = ((sub_step_57_2 + pub_r000393_17_2) + 8) & 127;
  int stage_v_170_1 = ((sub_step_170_1 * 2) + pub_r000393_0_1) & 127;
  int stage_v_170_2 = ((sub_step_170_2 * 2) + pub_r000393_0_2) & 127;
  st_var_2_1.buffer[2] = stage_v_170_1 & 15;
  st_var_2_2.buffer[2] = stage_v_170_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int sub_step_171_1 = ((stage_v_65_1 + pub_r000393_4_1) + 18) & 127;
  int sub_step_171_2 = ((stage_v_65_2 + pub_r000393_4_2) + 18) & 127;
  int stage_v_171_1 = ((sub_step_171_1 * 2) + pub_r000393_13_1) & 127;
  int stage_v_171_2 = ((sub_step_171_2 * 2) + pub_r000393_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_171_1 & 15;
  st_var_0_2.buffer[0] = stage_v_171_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int sub_step_172_1 = ((sec_r000393_0_1 + pub_r000393_12_1) + 22) & 127;
  int sub_step_172_2 = ((sec_r000393_0_2 + pub_r000393_12_2) + 22) & 127;
  int stage_v_172_1 = ((sub_step_172_1 * 2) + pub_r000393_7_1) & 127;
  int stage_v_172_2 = ((sub_step_172_2 * 2) + pub_r000393_7_2) & 127;
  st_var_1_1.buffer[1] = stage_v_172_1 & 15;
  st_var_1_2.buffer[1] = stage_v_172_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int sub_step_173_1 = ((sec_r000393_9_1 + pub_r000393_3_1) + 12) & 127;
  int sub_step_173_2 = ((sec_r000393_9_2 + pub_r000393_3_2) + 12) & 127;
  int stage_v_173_1 = ((sub_step_173_1 * 2) + pub_r000393_8_1) & 127;
  int stage_v_173_2 = ((sub_step_173_2 * 2) + pub_r000393_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_173_1 & 15;
  st_var_2_2.buffer[2] = stage_v_173_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int sub_step_174_1 = ((sub_step_62_1 + pub_r000393_13_1) + 19) & 127;
  int sub_step_174_2 = ((sub_step_62_2 + pub_r000393_13_2) + 19) & 127;
  int stage_v_174_1 = ((sub_step_174_1 * 2) + pub_r000393_7_1) & 127;
  int stage_v_174_2 = ((sub_step_174_2 * 2) + pub_r000393_7_2) & 127;
  st_var_0_1.buffer[0] = stage_v_174_1 & 15;
  st_var_0_2.buffer[0] = stage_v_174_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int sub_step_175_1 = ((sub_step_120_1 + pub_r000393_6_1) + 8) & 127;
  int sub_step_175_2 = ((sub_step_120_2 + pub_r000393_6_2) + 8) & 127;
  int stage_v_175_1 = ((sub_step_175_1 * 2) + pub_r000393_4_1) & 127;
  int stage_v_175_2 = ((sub_step_175_2 * 2) + pub_r000393_4_2) & 127;
  st_var_1_1.buffer[1] = stage_v_175_1 & 15;
  st_var_1_2.buffer[1] = stage_v_175_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int sub_step_176_1 = ((sec_r000393_2_1 + pub_r000393_0_1) + 30) & 127;
  int sub_step_176_2 = ((sec_r000393_2_2 + pub_r000393_0_2) + 30) & 127;
  int stage_v_176_1 = ((sub_step_176_1 * 2) + pub_r000393_7_1) & 127;
  int stage_v_176_2 = ((sub_step_176_2 * 2) + pub_r000393_7_2) & 127;
  st_var_2_1.buffer[2] = stage_v_176_1 & 15;
  st_var_2_2.buffer[2] = stage_v_176_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int sub_step_177_1 = ((stage_v_64_1 + pub_r000393_0_1) + 17) & 127;
  int sub_step_177_2 = ((stage_v_64_2 + pub_r000393_0_2) + 17) & 127;
  int stage_v_177_1 = ((sub_step_177_1 * 2) + pub_r000393_4_1) & 127;
  int stage_v_177_2 = ((sub_step_177_2 * 2) + pub_r000393_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_177_1 & 15;
  st_var_0_2.buffer[0] = stage_v_177_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int sub_step_178_1 = ((sec_r000393_4_1 + pub_r000393_10_1) + 21) & 127;
  int sub_step_178_2 = ((sec_r000393_4_2 + pub_r000393_10_2) + 21) & 127;
  int stage_v_178_1 = ((sub_step_178_1 * 2) + pub_r000393_16_1) & 127;
  int stage_v_178_2 = ((sub_step_178_2 * 2) + pub_r000393_16_2) & 127;
  st_var_1_1.buffer[1] = stage_v_178_1 & 15;
  st_var_1_2.buffer[1] = stage_v_178_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int sub_step_179_1 = ((stage_v_141_1 + pub_r000393_16_1) + 33) & 127;
  int sub_step_179_2 = ((stage_v_141_2 + pub_r000393_16_2) + 33) & 127;
  int stage_v_179_1 = ((sub_step_179_1 * 2) + pub_r000393_4_1) & 127;
  int stage_v_179_2 = ((sub_step_179_2 * 2) + pub_r000393_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_179_1 & 15;
  st_var_2_2.buffer[2] = stage_v_179_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int sub_step_180_1 = ((sec_r000393_10_1 + pub_r000393_2_1) + 16) & 127;
  int sub_step_180_2 = ((sec_r000393_10_2 + pub_r000393_2_2) + 16) & 127;
  int stage_v_180_1 = ((sub_step_180_1 * 2) + pub_r000393_0_1) & 127;
  int stage_v_180_2 = ((sub_step_180_2 * 2) + pub_r000393_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_180_1 & 15;
  st_var_0_2.buffer[0] = stage_v_180_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int sub_step_181_1 = ((sub_step_134_1 + pub_r000393_13_1) + 8) & 127;
  int sub_step_181_2 = ((sub_step_134_2 + pub_r000393_13_2) + 8) & 127;
  int stage_v_181_1 = ((sub_step_181_1 * 2) + pub_r000393_8_1) & 127;
  int stage_v_181_2 = ((sub_step_181_2 * 2) + pub_r000393_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_181_1 & 15;
  st_var_1_2.buffer[1] = stage_v_181_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int sub_step_182_1 = ((stage_v_108_1 + pub_r000393_3_1) + 14) & 127;
  int sub_step_182_2 = ((stage_v_108_2 + pub_r000393_3_2) + 14) & 127;
  int stage_v_182_1 = ((sub_step_182_1 * 2) + pub_r000393_9_1) & 127;
  int stage_v_182_2 = ((sub_step_182_2 * 2) + pub_r000393_9_2) & 127;
  st_var_2_1.buffer[2] = stage_v_182_1 & 15;
  st_var_2_2.buffer[2] = stage_v_182_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int sub_step_183_1 = ((sub_step_92_1 + pub_r000393_11_1) + 7) & 127;
  int sub_step_183_2 = ((sub_step_92_2 + pub_r000393_11_2) + 7) & 127;
  int stage_v_183_1 = ((sub_step_183_1 * 2) + pub_r000393_6_1) & 127;
  int stage_v_183_2 = ((sub_step_183_2 * 2) + pub_r000393_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_183_1 & 15;
  st_var_0_2.buffer[0] = stage_v_183_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int sub_step_184_1 = ((sub_step_112_1 + pub_r000393_13_1) + 23) & 127;
  int sub_step_184_2 = ((sub_step_112_2 + pub_r000393_13_2) + 23) & 127;
  int stage_v_184_1 = ((sub_step_184_1 * 2) + pub_r000393_10_1) & 127;
  int stage_v_184_2 = ((sub_step_184_2 * 2) + pub_r000393_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_184_1 & 15;
  st_var_1_2.buffer[1] = stage_v_184_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int sub_step_185_1 = ((sec_r000393_11_1 + pub_r000393_3_1) + 30) & 127;
  int sub_step_185_2 = ((sec_r000393_11_2 + pub_r000393_3_2) + 30) & 127;
  int stage_v_185_1 = ((sub_step_185_1 * 2) + pub_r000393_3_1) & 127;
  int stage_v_185_2 = ((sub_step_185_2 * 2) + pub_r000393_3_2) & 127;
  st_var_2_1.buffer[2] = stage_v_185_1 & 15;
  st_var_2_2.buffer[2] = stage_v_185_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int sub_step_186_1 = ((sec_r000393_10_1 + pub_r000393_4_1) + 28) & 127;
  int sub_step_186_2 = ((sec_r000393_10_2 + pub_r000393_4_2) + 28) & 127;
  int stage_v_186_1 = ((sub_step_186_1 * 2) + pub_r000393_16_1) & 127;
  int stage_v_186_2 = ((sub_step_186_2 * 2) + pub_r000393_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_186_1 & 15;
  st_var_0_2.buffer[0] = stage_v_186_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int sub_step_187_1 = ((sub_step_74_1 + pub_r000393_4_1) + 8) & 127;
  int sub_step_187_2 = ((sub_step_74_2 + pub_r000393_4_2) + 8) & 127;
  int stage_v_187_1 = ((sub_step_187_1 * 2) + pub_r000393_9_1) & 127;
  int stage_v_187_2 = ((sub_step_187_2 * 2) + pub_r000393_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_187_1 & 15;
  st_var_1_2.buffer[1] = stage_v_187_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int sub_step_188_1 = ((sub_step_119_1 + pub_r000393_11_1) + 20) & 127;
  int sub_step_188_2 = ((sub_step_119_2 + pub_r000393_11_2) + 20) & 127;
  int stage_v_188_1 = ((sub_step_188_1 * 2) + pub_r000393_13_1) & 127;
  int stage_v_188_2 = ((sub_step_188_2 * 2) + pub_r000393_13_2) & 127;
  st_var_2_1.buffer[2] = stage_v_188_1 & 15;
  st_var_2_2.buffer[2] = stage_v_188_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int sub_step_189_1 = ((sec_r000393_9_1 + pub_r000393_2_1) + 9) & 127;
  int sub_step_189_2 = ((sec_r000393_9_2 + pub_r000393_2_2) + 9) & 127;
  int stage_v_189_1 = ((sub_step_189_1 * 2) + pub_r000393_1_1) & 127;
  int stage_v_189_2 = ((sub_step_189_2 * 2) + pub_r000393_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_189_1 & 15;
  st_var_0_2.buffer[0] = stage_v_189_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int sub_step_190_1 = ((stage_v_56_1 + pub_r000393_7_1) + 25) & 127;
  int sub_step_190_2 = ((stage_v_56_2 + pub_r000393_7_2) + 25) & 127;
  int stage_v_190_1 = ((sub_step_190_1 * 2) + pub_r000393_14_1) & 127;
  int stage_v_190_2 = ((sub_step_190_2 * 2) + pub_r000393_14_2) & 127;
  st_var_1_1.buffer[1] = stage_v_190_1 & 15;
  st_var_1_2.buffer[1] = stage_v_190_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int sub_step_191_1 = ((stage_v_93_1 + pub_r000393_1_1) + 33) & 127;
  int sub_step_191_2 = ((stage_v_93_2 + pub_r000393_1_2) + 33) & 127;
  int stage_v_191_1 = ((sub_step_191_1 * 2) + pub_r000393_10_1) & 127;
  int stage_v_191_2 = ((sub_step_191_2 * 2) + pub_r000393_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_191_1 & 15;
  st_var_2_2.buffer[2] = stage_v_191_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int sub_step_192_1 = ((sub_step_121_1 + pub_r000393_14_1) + 7) & 127;
  int sub_step_192_2 = ((sub_step_121_2 + pub_r000393_14_2) + 7) & 127;
  int stage_v_192_1 = ((sub_step_192_1 * 2) + pub_r000393_13_1) & 127;
  int stage_v_192_2 = ((sub_step_192_2 * 2) + pub_r000393_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_192_1 & 15;
  st_var_0_2.buffer[0] = stage_v_192_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int sub_step_193_1 = ((sec_r000393_5_1 + pub_r000393_5_1) + 26) & 127;
  int sub_step_193_2 = ((sec_r000393_5_2 + pub_r000393_5_2) + 26) & 127;
  int stage_v_193_1 = ((sub_step_193_1 * 2) + pub_r000393_11_1) & 127;
  int stage_v_193_2 = ((sub_step_193_2 * 2) + pub_r000393_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_193_1 & 15;
  st_var_1_2.buffer[1] = stage_v_193_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int sub_step_194_1 = ((stage_v_81_1 + pub_r000393_1_1) + 5) & 127;
  int sub_step_194_2 = ((stage_v_81_2 + pub_r000393_1_2) + 5) & 127;
  int stage_v_194_1 = ((sub_step_194_1 * 2) + pub_r000393_4_1) & 127;
  int stage_v_194_2 = ((sub_step_194_2 * 2) + pub_r000393_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_194_1 & 15;
  st_var_2_2.buffer[2] = stage_v_194_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int sub_step_195_1 = ((sec_r000393_9_1 + pub_r000393_15_1) + 24) & 127;
  int sub_step_195_2 = ((sec_r000393_9_2 + pub_r000393_15_2) + 24) & 127;
  int stage_v_195_1 = ((sub_step_195_1 * 2) + pub_r000393_4_1) & 127;
  int stage_v_195_2 = ((sub_step_195_2 * 2) + pub_r000393_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_195_1 & 15;
  st_var_0_2.buffer[0] = stage_v_195_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int sub_step_196_1 = ((sec_r000393_10_1 + pub_r000393_1_1) + 19) & 127;
  int sub_step_196_2 = ((sec_r000393_10_2 + pub_r000393_1_2) + 19) & 127;
  int stage_v_196_1 = ((sub_step_196_1 * 2) + pub_r000393_1_1) & 127;
  int stage_v_196_2 = ((sub_step_196_2 * 2) + pub_r000393_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_196_1 & 15;
  st_var_1_2.buffer[1] = stage_v_196_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int sub_step_197_1 = ((sub_step_82_1 + pub_r000393_5_1) + 22) & 127;
  int sub_step_197_2 = ((sub_step_82_2 + pub_r000393_5_2) + 22) & 127;
  int stage_v_197_1 = ((sub_step_197_1 * 2) + pub_r000393_1_1) & 127;
  int stage_v_197_2 = ((sub_step_197_2 * 2) + pub_r000393_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_197_1 & 15;
  st_var_2_2.buffer[2] = stage_v_197_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int sub_step_198_1 = ((sec_r000393_11_1 + pub_r000393_0_1) + 6) & 127;
  int sub_step_198_2 = ((sec_r000393_11_2 + pub_r000393_0_2) + 6) & 127;
  int stage_v_198_1 = ((sub_step_198_1 * 2) + pub_r000393_15_1) & 127;
  int stage_v_198_2 = ((sub_step_198_2 * 2) + pub_r000393_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_198_1 & 15;
  st_var_0_2.buffer[0] = stage_v_198_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int sub_step_199_1 = ((stage_v_131_1 + pub_r000393_7_1) + 12) & 127;
  int sub_step_199_2 = ((stage_v_131_2 + pub_r000393_7_2) + 12) & 127;
  int stage_v_199_1 = ((sub_step_199_1 * 2) + pub_r000393_13_1) & 127;
  int stage_v_199_2 = ((sub_step_199_2 * 2) + pub_r000393_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_199_1 & 15;
  st_var_1_2.buffer[1] = stage_v_199_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int sub_step_200_1 = ((sub_step_65_1 + pub_r000393_0_1) + 6) & 127;
  int sub_step_200_2 = ((sub_step_65_2 + pub_r000393_0_2) + 6) & 127;
  int stage_v_200_1 = ((sub_step_200_1 * 2) + pub_r000393_1_1) & 127;
  int stage_v_200_2 = ((sub_step_200_2 * 2) + pub_r000393_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_200_1 & 15;
  st_var_2_2.buffer[2] = stage_v_200_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int sub_step_201_1 = ((sec_r000393_13_1 + pub_r000393_0_1) + 27) & 127;
  int sub_step_201_2 = ((sec_r000393_13_2 + pub_r000393_0_2) + 27) & 127;
  int stage_v_201_1 = ((sub_step_201_1 * 2) + pub_r000393_4_1) & 127;
  int stage_v_201_2 = ((sub_step_201_2 * 2) + pub_r000393_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_201_1 & 15;
  st_var_0_2.buffer[0] = stage_v_201_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int sub_step_202_1 = ((sec_r000393_7_1 + pub_r000393_12_1) + 18) & 127;
  int sub_step_202_2 = ((sec_r000393_7_2 + pub_r000393_12_2) + 18) & 127;
  int stage_v_202_1 = ((sub_step_202_1 * 2) + pub_r000393_3_1) & 127;
  int stage_v_202_2 = ((sub_step_202_2 * 2) + pub_r000393_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_202_1 & 15;
  st_var_1_2.buffer[1] = stage_v_202_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int sub_step_203_1 = ((stage_v_51_1 + pub_r000393_2_1) + 14) & 127;
  int sub_step_203_2 = ((stage_v_51_2 + pub_r000393_2_2) + 14) & 127;
  int stage_v_203_1 = ((sub_step_203_1 * 2) + pub_r000393_17_1) & 127;
  int stage_v_203_2 = ((sub_step_203_2 * 2) + pub_r000393_17_2) & 127;
  st_var_2_1.buffer[2] = stage_v_203_1 & 15;
  st_var_2_2.buffer[2] = stage_v_203_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int sub_step_204_1 = ((sec_r000393_4_1 + pub_r000393_9_1) + 26) & 127;
  int sub_step_204_2 = ((sec_r000393_4_2 + pub_r000393_9_2) + 26) & 127;
  int stage_v_204_1 = ((sub_step_204_1 * 2) + pub_r000393_4_1) & 127;
  int stage_v_204_2 = ((sub_step_204_2 * 2) + pub_r000393_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_204_1 & 15;
  st_var_0_2.buffer[0] = stage_v_204_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int sub_step_205_1 = ((sec_r000393_5_1 + pub_r000393_17_1) + 22) & 127;
  int sub_step_205_2 = ((sec_r000393_5_2 + pub_r000393_17_2) + 22) & 127;
  int stage_v_205_1 = ((sub_step_205_1 * 2) + pub_r000393_9_1) & 127;
  int stage_v_205_2 = ((sub_step_205_2 * 2) + pub_r000393_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_205_1 & 15;
  st_var_1_2.buffer[1] = stage_v_205_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int sub_step_206_1 = ((stage_v_66_1 + pub_r000393_15_1) + 31) & 127;
  int sub_step_206_2 = ((stage_v_66_2 + pub_r000393_15_2) + 31) & 127;
  int stage_v_206_1 = ((sub_step_206_1 * 2) + pub_r000393_16_1) & 127;
  int stage_v_206_2 = ((sub_step_206_2 * 2) + pub_r000393_16_2) & 127;
  st_var_2_1.buffer[2] = stage_v_206_1 & 15;
  st_var_2_2.buffer[2] = stage_v_206_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int sub_step_207_1 = ((stage_v_157_1 + pub_r000393_8_1) + 32) & 127;
  int sub_step_207_2 = ((stage_v_157_2 + pub_r000393_8_2) + 32) & 127;
  int stage_v_207_1 = ((sub_step_207_1 * 2) + pub_r000393_16_1) & 127;
  int stage_v_207_2 = ((sub_step_207_2 * 2) + pub_r000393_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_207_1 & 15;
  st_var_0_2.buffer[0] = stage_v_207_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int sub_step_208_1 = ((sub_step_184_1 + pub_r000393_2_1) + 19) & 127;
  int sub_step_208_2 = ((sub_step_184_2 + pub_r000393_2_2) + 19) & 127;
  int stage_v_208_1 = ((sub_step_208_1 * 2) + pub_r000393_1_1) & 127;
  int stage_v_208_2 = ((sub_step_208_2 * 2) + pub_r000393_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_208_1 & 15;
  st_var_1_2.buffer[1] = stage_v_208_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int sub_step_209_1 = ((stage_v_147_1 + pub_r000393_1_1) + 22) & 127;
  int sub_step_209_2 = ((stage_v_147_2 + pub_r000393_1_2) + 22) & 127;
  int stage_v_209_1 = ((sub_step_209_1 * 2) + pub_r000393_3_1) & 127;
  int stage_v_209_2 = ((sub_step_209_2 * 2) + pub_r000393_3_2) & 127;
  st_var_2_1.buffer[2] = stage_v_209_1 & 15;
  st_var_2_2.buffer[2] = stage_v_209_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int sub_step_210_1 = ((stage_v_112_1 + pub_r000393_8_1) + 13) & 127;
  int sub_step_210_2 = ((stage_v_112_2 + pub_r000393_8_2) + 13) & 127;
  int stage_v_210_1 = ((sub_step_210_1 * 2) + pub_r000393_9_1) & 127;
  int stage_v_210_2 = ((sub_step_210_2 * 2) + pub_r000393_9_2) & 127;
  st_var_0_1.buffer[0] = stage_v_210_1 & 15;
  st_var_0_2.buffer[0] = stage_v_210_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int sub_step_211_1 = ((sub_step_152_1 + pub_r000393_13_1) + 9) & 127;
  int sub_step_211_2 = ((sub_step_152_2 + pub_r000393_13_2) + 9) & 127;
  int stage_v_211_1 = ((sub_step_211_1 * 2) + pub_r000393_5_1) & 127;
  int stage_v_211_2 = ((sub_step_211_2 * 2) + pub_r000393_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_211_1 & 15;
  st_var_1_2.buffer[1] = stage_v_211_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int sub_step_212_1 = ((sub_step_76_1 + pub_r000393_5_1) + 26) & 127;
  int sub_step_212_2 = ((sub_step_76_2 + pub_r000393_5_2) + 26) & 127;
  int stage_v_212_1 = ((sub_step_212_1 * 2) + pub_r000393_10_1) & 127;
  int stage_v_212_2 = ((sub_step_212_2 * 2) + pub_r000393_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_212_1 & 15;
  st_var_2_2.buffer[2] = stage_v_212_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int sub_step_213_1 = ((stage_v_162_1 + pub_r000393_2_1) + 30) & 127;
  int sub_step_213_2 = ((stage_v_162_2 + pub_r000393_2_2) + 30) & 127;
  int stage_v_213_1 = ((sub_step_213_1 * 2) + pub_r000393_17_1) & 127;
  int stage_v_213_2 = ((sub_step_213_2 * 2) + pub_r000393_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_213_1 & 15;
  st_var_0_2.buffer[0] = stage_v_213_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int sub_step_214_1 = ((stage_v_130_1 + pub_r000393_6_1) + 11) & 127;
  int sub_step_214_2 = ((stage_v_130_2 + pub_r000393_6_2) + 11) & 127;
  int stage_v_214_1 = ((sub_step_214_1 * 2) + pub_r000393_7_1) & 127;
  int stage_v_214_2 = ((sub_step_214_2 * 2) + pub_r000393_7_2) & 127;
  st_var_1_1.buffer[1] = stage_v_214_1 & 15;
  st_var_1_2.buffer[1] = stage_v_214_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int sub_step_215_1 = ((sec_r000393_5_1 + pub_r000393_7_1) + 6) & 127;
  int sub_step_215_2 = ((sec_r000393_5_2 + pub_r000393_7_2) + 6) & 127;
  int stage_v_215_1 = ((sub_step_215_1 * 2) + pub_r000393_10_1) & 127;
  int stage_v_215_2 = ((sub_step_215_2 * 2) + pub_r000393_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_215_1 & 15;
  st_var_2_2.buffer[2] = stage_v_215_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int sub_step_216_1 = ((sec_r000393_0_1 + pub_r000393_8_1) + 8) & 127;
  int sub_step_216_2 = ((sec_r000393_0_2 + pub_r000393_8_2) + 8) & 127;
  int stage_v_216_1 = ((sub_step_216_1 * 2) + pub_r000393_4_1) & 127;
  int stage_v_216_2 = ((sub_step_216_2 * 2) + pub_r000393_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_216_1 & 15;
  st_var_0_2.buffer[0] = stage_v_216_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int sub_step_217_1 = ((sec_r000393_2_1 + pub_r000393_3_1) + 22) & 127;
  int sub_step_217_2 = ((sec_r000393_2_2 + pub_r000393_3_2) + 22) & 127;
  int stage_v_217_1 = ((sub_step_217_1 * 2) + pub_r000393_11_1) & 127;
  int stage_v_217_2 = ((sub_step_217_2 * 2) + pub_r000393_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_217_1 & 15;
  st_var_1_2.buffer[1] = stage_v_217_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int sub_step_218_1 = ((stage_v_168_1 + pub_r000393_13_1) + 26) & 127;
  int sub_step_218_2 = ((stage_v_168_2 + pub_r000393_13_2) + 26) & 127;
  int stage_v_218_1 = ((sub_step_218_1 * 2) + pub_r000393_5_1) & 127;
  int stage_v_218_2 = ((sub_step_218_2 * 2) + pub_r000393_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_218_1 & 15;
  st_var_2_2.buffer[2] = stage_v_218_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int sub_step_219_1 = ((sub_step_193_1 + pub_r000393_11_1) + 22) & 127;
  int sub_step_219_2 = ((sub_step_193_2 + pub_r000393_11_2) + 22) & 127;
  int stage_v_219_1 = ((sub_step_219_1 * 2) + pub_r000393_1_1) & 127;
  int stage_v_219_2 = ((sub_step_219_2 * 2) + pub_r000393_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_219_1 & 15;
  st_var_0_2.buffer[0] = stage_v_219_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int sub_step_220_1 = ((stage_v_74_1 + pub_r000393_5_1) + 21) & 127;
  int sub_step_220_2 = ((stage_v_74_2 + pub_r000393_5_2) + 21) & 127;
  int stage_v_220_1 = ((sub_step_220_1 * 2) + pub_r000393_10_1) & 127;
  int stage_v_220_2 = ((sub_step_220_2 * 2) + pub_r000393_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_220_1 & 15;
  st_var_1_2.buffer[1] = stage_v_220_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int sub_step_221_1 = ((stage_v_209_1 + pub_r000393_1_1) + 32) & 127;
  int sub_step_221_2 = ((stage_v_209_2 + pub_r000393_1_2) + 32) & 127;
  int stage_v_221_1 = ((sub_step_221_1 * 2) + pub_r000393_16_1) & 127;
  int stage_v_221_2 = ((sub_step_221_2 * 2) + pub_r000393_16_2) & 127;
  st_var_2_1.buffer[2] = stage_v_221_1 & 15;
  st_var_2_2.buffer[2] = stage_v_221_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int sub_step_222_1 = ((stage_v_192_1 + pub_r000393_3_1) + 25) & 127;
  int sub_step_222_2 = ((stage_v_192_2 + pub_r000393_3_2) + 25) & 127;
  int stage_v_222_1 = ((sub_step_222_1 * 2) + pub_r000393_1_1) & 127;
  int stage_v_222_2 = ((sub_step_222_2 * 2) + pub_r000393_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_222_1 & 15;
  st_var_0_2.buffer[0] = stage_v_222_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int sub_step_223_1 = ((sub_step_177_1 + pub_r000393_2_1) + 16) & 127;
  int sub_step_223_2 = ((sub_step_177_2 + pub_r000393_2_2) + 16) & 127;
  int stage_v_223_1 = ((sub_step_223_1 * 2) + pub_r000393_4_1) & 127;
  int stage_v_223_2 = ((sub_step_223_2 * 2) + pub_r000393_4_2) & 127;
  st_var_1_1.buffer[1] = stage_v_223_1 & 15;
  st_var_1_2.buffer[1] = stage_v_223_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int sub_step_224_1 = ((stage_v_56_1 + pub_r000393_0_1) + 10) & 127;
  int sub_step_224_2 = ((stage_v_56_2 + pub_r000393_0_2) + 10) & 127;
  int stage_v_224_1 = ((sub_step_224_1 * 2) + pub_r000393_11_1) & 127;
  int stage_v_224_2 = ((sub_step_224_2 * 2) + pub_r000393_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_224_1 & 15;
  st_var_2_2.buffer[2] = stage_v_224_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int sub_step_225_1 = ((sec_r000393_12_1 + pub_r000393_10_1) + 6) & 127;
  int sub_step_225_2 = ((sec_r000393_12_2 + pub_r000393_10_2) + 6) & 127;
  int stage_v_225_1 = ((sub_step_225_1 * 2) + pub_r000393_7_1) & 127;
  int stage_v_225_2 = ((sub_step_225_2 * 2) + pub_r000393_7_2) & 127;
  st_var_0_1.buffer[0] = stage_v_225_1 & 15;
  st_var_0_2.buffer[0] = stage_v_225_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int sub_step_226_1 = ((sub_step_153_1 + pub_r000393_11_1) + 27) & 127;
  int sub_step_226_2 = ((sub_step_153_2 + pub_r000393_11_2) + 27) & 127;
  int stage_v_226_1 = ((sub_step_226_1 * 2) + pub_r000393_12_1) & 127;
  int stage_v_226_2 = ((sub_step_226_2 * 2) + pub_r000393_12_2) & 127;
  st_var_1_1.buffer[1] = stage_v_226_1 & 15;
  st_var_1_2.buffer[1] = stage_v_226_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int sub_step_227_1 = ((sec_r000393_7_1 + pub_r000393_15_1) + 33) & 127;
  int sub_step_227_2 = ((sec_r000393_7_2 + pub_r000393_15_2) + 33) & 127;
  int stage_v_227_1 = ((sub_step_227_1 * 2) + pub_r000393_5_1) & 127;
  int stage_v_227_2 = ((sub_step_227_2 * 2) + pub_r000393_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_227_1 & 15;
  st_var_2_2.buffer[2] = stage_v_227_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int sub_step_228_1 = ((sub_step_118_1 + pub_r000393_16_1) + 11) & 127;
  int sub_step_228_2 = ((sub_step_118_2 + pub_r000393_16_2) + 11) & 127;
  int stage_v_228_1 = ((sub_step_228_1 * 2) + pub_r000393_1_1) & 127;
  int stage_v_228_2 = ((sub_step_228_2 * 2) + pub_r000393_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_228_1 & 15;
  st_var_0_2.buffer[0] = stage_v_228_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int sub_step_229_1 = ((stage_v_72_1 + pub_r000393_6_1) + 9) & 127;
  int sub_step_229_2 = ((stage_v_72_2 + pub_r000393_6_2) + 9) & 127;
  int stage_v_229_1 = ((sub_step_229_1 * 2) + pub_r000393_16_1) & 127;
  int stage_v_229_2 = ((sub_step_229_2 * 2) + pub_r000393_16_2) & 127;
  st_var_1_1.buffer[1] = stage_v_229_1 & 15;
  st_var_1_2.buffer[1] = stage_v_229_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int sub_step_230_1 = ((sub_step_202_1 + pub_r000393_3_1) + 25) & 127;
  int sub_step_230_2 = ((sub_step_202_2 + pub_r000393_3_2) + 25) & 127;
  int stage_v_230_1 = ((sub_step_230_1 * 2) + pub_r000393_13_1) & 127;
  int stage_v_230_2 = ((sub_step_230_2 * 2) + pub_r000393_13_2) & 127;
  st_var_2_1.buffer[2] = stage_v_230_1 & 15;
  st_var_2_2.buffer[2] = stage_v_230_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int sub_step_231_1 = ((stage_v_161_1 + pub_r000393_13_1) + 28) & 127;
  int sub_step_231_2 = ((stage_v_161_2 + pub_r000393_13_2) + 28) & 127;
  int stage_v_231_1 = ((sub_step_231_1 * 2) + pub_r000393_11_1) & 127;
  int stage_v_231_2 = ((sub_step_231_2 * 2) + pub_r000393_11_2) & 127;
  st_var_0_1.buffer[0] = stage_v_231_1 & 15;
  st_var_0_2.buffer[0] = stage_v_231_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int sub_step_232_1 = ((stage_v_223_1 + pub_r000393_9_1) + 18) & 127;
  int sub_step_232_2 = ((stage_v_223_2 + pub_r000393_9_2) + 18) & 127;
  int stage_v_232_1 = ((sub_step_232_1 * 2) + pub_r000393_16_1) & 127;
  int stage_v_232_2 = ((sub_step_232_2 * 2) + pub_r000393_16_2) & 127;
  st_var_1_1.buffer[1] = stage_v_232_1 & 15;
  st_var_1_2.buffer[1] = stage_v_232_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int sub_step_233_1 = ((sec_r000393_1_1 + pub_r000393_3_1) + 23) & 127;
  int sub_step_233_2 = ((sec_r000393_1_2 + pub_r000393_3_2) + 23) & 127;
  int stage_v_233_1 = ((sub_step_233_1 * 2) + pub_r000393_6_1) & 127;
  int stage_v_233_2 = ((sub_step_233_2 * 2) + pub_r000393_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_233_1 & 15;
  st_var_2_2.buffer[2] = stage_v_233_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int sub_step_234_1 = ((sub_step_170_1 + pub_r000393_1_1) + 26) & 127;
  int sub_step_234_2 = ((sub_step_170_2 + pub_r000393_1_2) + 26) & 127;
  int stage_v_234_1 = ((sub_step_234_1 * 2) + pub_r000393_16_1) & 127;
  int stage_v_234_2 = ((sub_step_234_2 * 2) + pub_r000393_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_234_1 & 15;
  st_var_0_2.buffer[0] = stage_v_234_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int sub_step_235_1 = ((sub_step_189_1 + pub_r000393_16_1) + 31) & 127;
  int sub_step_235_2 = ((sub_step_189_2 + pub_r000393_16_2) + 31) & 127;
  int stage_v_235_1 = ((sub_step_235_1 * 2) + pub_r000393_9_1) & 127;
  int stage_v_235_2 = ((sub_step_235_2 * 2) + pub_r000393_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_235_1 & 15;
  st_var_1_2.buffer[1] = stage_v_235_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int sub_step_236_1 = ((sec_r000393_12_1 + pub_r000393_12_1) + 13) & 127;
  int sub_step_236_2 = ((sec_r000393_12_2 + pub_r000393_12_2) + 13) & 127;
  int stage_v_236_1 = ((sub_step_236_1 * 2) + pub_r000393_10_1) & 127;
  int stage_v_236_2 = ((sub_step_236_2 * 2) + pub_r000393_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_236_1 & 15;
  st_var_2_2.buffer[2] = stage_v_236_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int sub_step_237_1 = ((sub_step_159_1 + pub_r000393_9_1) + 13) & 127;
  int sub_step_237_2 = ((sub_step_159_2 + pub_r000393_9_2) + 13) & 127;
  int stage_v_237_1 = ((sub_step_237_1 * 2) + pub_r000393_16_1) & 127;
  int stage_v_237_2 = ((sub_step_237_2 * 2) + pub_r000393_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_237_1 & 15;
  st_var_0_2.buffer[0] = stage_v_237_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int sub_step_238_1 = ((sub_step_79_1 + pub_r000393_14_1) + 5) & 127;
  int sub_step_238_2 = ((sub_step_79_2 + pub_r000393_14_2) + 5) & 127;
  int stage_v_238_1 = ((sub_step_238_1 * 2) + pub_r000393_2_1) & 127;
  int stage_v_238_2 = ((sub_step_238_2 * 2) + pub_r000393_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_238_1 & 15;
  st_var_1_2.buffer[1] = stage_v_238_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int sub_step_239_1 = ((stage_v_148_1 + pub_r000393_10_1) + 31) & 127;
  int sub_step_239_2 = ((stage_v_148_2 + pub_r000393_10_2) + 31) & 127;
  int stage_v_239_1 = ((sub_step_239_1 * 2) + pub_r000393_2_1) & 127;
  int stage_v_239_2 = ((sub_step_239_2 * 2) + pub_r000393_2_2) & 127;
  st_var_2_1.buffer[2] = stage_v_239_1 & 15;
  st_var_2_2.buffer[2] = stage_v_239_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int sub_step_240_1 = ((stage_v_137_1 + pub_r000393_16_1) + 30) & 127;
  int sub_step_240_2 = ((stage_v_137_2 + pub_r000393_16_2) + 30) & 127;
  int stage_v_240_1 = ((sub_step_240_1 * 2) + pub_r000393_10_1) & 127;
  int stage_v_240_2 = ((sub_step_240_2 * 2) + pub_r000393_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_240_1 & 15;
  st_var_0_2.buffer[0] = stage_v_240_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int sub_step_241_1 = ((sec_r000393_13_1 + pub_r000393_10_1) + 9) & 127;
  int sub_step_241_2 = ((sec_r000393_13_2 + pub_r000393_10_2) + 9) & 127;
  int stage_v_241_1 = ((sub_step_241_1 * 2) + pub_r000393_8_1) & 127;
  int stage_v_241_2 = ((sub_step_241_2 * 2) + pub_r000393_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_241_1 & 15;
  st_var_1_2.buffer[1] = stage_v_241_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int sub_step_242_1 = ((sec_r000393_2_1 + pub_r000393_1_1) + 8) & 127;
  int sub_step_242_2 = ((sec_r000393_2_2 + pub_r000393_1_2) + 8) & 127;
  int stage_v_242_1 = ((sub_step_242_1 * 2) + pub_r000393_5_1) & 127;
  int stage_v_242_2 = ((sub_step_242_2 * 2) + pub_r000393_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_242_1 & 15;
  st_var_2_2.buffer[2] = stage_v_242_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int sub_step_243_1 = ((sec_r000393_1_1 + pub_r000393_5_1) + 21) & 127;
  int sub_step_243_2 = ((sec_r000393_1_2 + pub_r000393_5_2) + 21) & 127;
  int stage_v_243_1 = ((sub_step_243_1 * 2) + pub_r000393_0_1) & 127;
  int stage_v_243_2 = ((sub_step_243_2 * 2) + pub_r000393_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_243_1 & 15;
  st_var_0_2.buffer[0] = stage_v_243_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int sub_step_244_1 = ((sec_r000393_6_1 + pub_r000393_6_1) + 12) & 127;
  int sub_step_244_2 = ((sec_r000393_6_2 + pub_r000393_6_2) + 12) & 127;
  int stage_v_244_1 = ((sub_step_244_1 * 2) + pub_r000393_15_1) & 127;
  int stage_v_244_2 = ((sub_step_244_2 * 2) + pub_r000393_15_2) & 127;
  st_var_1_1.buffer[1] = stage_v_244_1 & 15;
  st_var_1_2.buffer[1] = stage_v_244_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int sub_step_245_1 = ((sec_r000393_14_1 + pub_r000393_17_1) + 33) & 127;
  int sub_step_245_2 = ((sec_r000393_14_2 + pub_r000393_17_2) + 33) & 127;
  int stage_v_245_1 = ((sub_step_245_1 * 2) + pub_r000393_8_1) & 127;
  int stage_v_245_2 = ((sub_step_245_2 * 2) + pub_r000393_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_245_1 & 15;
  st_var_2_2.buffer[2] = stage_v_245_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int sub_step_246_1 = ((sub_step_141_1 + pub_r000393_15_1) + 31) & 127;
  int sub_step_246_2 = ((sub_step_141_2 + pub_r000393_15_2) + 31) & 127;
  int stage_v_246_1 = ((sub_step_246_1 * 2) + pub_r000393_6_1) & 127;
  int stage_v_246_2 = ((sub_step_246_2 * 2) + pub_r000393_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_246_1 & 15;
  st_var_0_2.buffer[0] = stage_v_246_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int sub_step_247_1 = ((sec_r000393_1_1 + pub_r000393_0_1) + 22) & 127;
  int sub_step_247_2 = ((sec_r000393_1_2 + pub_r000393_0_2) + 22) & 127;
  int stage_v_247_1 = ((sub_step_247_1 * 2) + pub_r000393_15_1) & 127;
  int stage_v_247_2 = ((sub_step_247_2 * 2) + pub_r000393_15_2) & 127;
  st_var_1_1.buffer[1] = stage_v_247_1 & 15;
  st_var_1_2.buffer[1] = stage_v_247_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int sub_step_248_1 = ((sub_step_92_1 + pub_r000393_13_1) + 7) & 127;
  int sub_step_248_2 = ((sub_step_92_2 + pub_r000393_13_2) + 7) & 127;
  int stage_v_248_1 = ((sub_step_248_1 * 2) + pub_r000393_11_1) & 127;
  int stage_v_248_2 = ((sub_step_248_2 * 2) + pub_r000393_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_248_1 & 15;
  st_var_2_2.buffer[2] = stage_v_248_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000393_13_1 == pub_r000393_13_2);
  __CPROVER_assume(sec_r000393_8_1 != sec_r000393_8_2);
  __CPROVER_assume(sec_r000393_15_1 != sec_r000393_15_2);
  __CPROVER_assume(sec_r000393_14_1 != sec_r000393_14_2);
  __CPROVER_assume(pub_r000393_1_1 == pub_r000393_1_2);
  __CPROVER_assume(pub_r000393_6_1 == pub_r000393_6_2);
  __CPROVER_assume(pub_r000393_12_1 == pub_r000393_12_2);
  __CPROVER_assume(pub_r000393_3_1 == pub_r000393_3_2);
  __CPROVER_assume(pub_r000393_4_1 == pub_r000393_4_2);
  __CPROVER_assume(pub_r000393_14_1 == pub_r000393_14_2);
  __CPROVER_assume(pub_r000393_17_1 == pub_r000393_17_2);
  __CPROVER_assume(sec_r000393_0_1 != sec_r000393_0_2);
  __CPROVER_assume(sec_r000393_4_1 != sec_r000393_4_2);
  __CPROVER_assume(pub_r000393_2_1 == pub_r000393_2_2);
  __CPROVER_assume(sec_r000393_3_1 != sec_r000393_3_2);
  __CPROVER_assume(sec_r000393_10_1 != sec_r000393_10_2);
  __CPROVER_assume(pub_r000393_11_1 == pub_r000393_11_2);
  __CPROVER_assume(sec_r000393_11_1 != sec_r000393_11_2);
  __CPROVER_assume(sec_r000393_12_1 != sec_r000393_12_2);
  __CPROVER_assume(pub_r000393_5_1 == pub_r000393_5_2);
  __CPROVER_assume(sec_r000393_1_1 != sec_r000393_1_2);
  __CPROVER_assume(sec_r000393_5_1 != sec_r000393_5_2);
  __CPROVER_assume(pub_r000393_16_1 == pub_r000393_16_2);
  __CPROVER_assume(sec_r000393_2_1 != sec_r000393_2_2);
  __CPROVER_assume(sec_r000393_13_1 != sec_r000393_13_2);
  __CPROVER_assume(pub_r000393_9_1 == pub_r000393_9_2);
  __CPROVER_assume(sec_r000393_9_1 != sec_r000393_9_2);
  __CPROVER_assume(pub_r000393_0_1 == pub_r000393_0_2);
  __CPROVER_assume(sec_r000393_7_1 != sec_r000393_7_2);
  __CPROVER_assume(pub_r000393_15_1 == pub_r000393_15_2);
  __CPROVER_assume(sec_r000393_6_1 != sec_r000393_6_2);
  __CPROVER_assume(pub_r000393_7_1 == pub_r000393_7_2);
  __CPROVER_assume(pub_r000393_8_1 == pub_r000393_8_2);
  __CPROVER_assume(pub_r000393_10_1 == pub_r000393_10_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  assert(st_var_1_1.mode == st_var_1_2.mode);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.threshold == st_var_2_2.threshold);
  assert(st_var_2_1.calib == st_var_2_2.calib);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.reading == st_var_2_2.reading);
  assert(st_var_2_1.offset == st_var_2_2.offset);
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
  assert(sub_step_51_1 == sub_step_51_2);
  assert(stage_v_51_1 == stage_v_51_2);
  assert(sub_step_52_1 == sub_step_52_2);
  assert(stage_v_52_1 == stage_v_52_2);
  assert(sub_step_53_1 == sub_step_53_2);
  assert(stage_v_53_1 == stage_v_53_2);
  assert(sub_step_54_1 == sub_step_54_2);
  assert(stage_v_54_1 == stage_v_54_2);
  assert(sub_step_55_1 == sub_step_55_2);
  assert(stage_v_55_1 == stage_v_55_2);
  assert(sub_step_56_1 == sub_step_56_2);
  assert(stage_v_56_1 == stage_v_56_2);
  assert(sub_step_57_1 == sub_step_57_2);
  assert(stage_v_57_1 == stage_v_57_2);
  assert(sub_step_58_1 == sub_step_58_2);
  assert(stage_v_58_1 == stage_v_58_2);
  assert(sub_step_59_1 == sub_step_59_2);
  assert(stage_v_59_1 == stage_v_59_2);
  assert(sub_step_60_1 == sub_step_60_2);
  assert(stage_v_60_1 == stage_v_60_2);
  assert(sub_step_61_1 == sub_step_61_2);
  assert(stage_v_61_1 == stage_v_61_2);
  assert(sub_step_62_1 == sub_step_62_2);
  assert(stage_v_62_1 == stage_v_62_2);
  assert(sub_step_63_1 == sub_step_63_2);
  assert(stage_v_63_1 == stage_v_63_2);
  assert(sub_step_64_1 == sub_step_64_2);
  assert(stage_v_64_1 == stage_v_64_2);
  assert(sub_step_65_1 == sub_step_65_2);
  assert(stage_v_65_1 == stage_v_65_2);
  assert(sub_step_66_1 == sub_step_66_2);
  assert(stage_v_66_1 == stage_v_66_2);
  assert(sub_step_67_1 == sub_step_67_2);
  assert(stage_v_67_1 == stage_v_67_2);
  assert(sub_step_68_1 == sub_step_68_2);
  assert(stage_v_68_1 == stage_v_68_2);
  assert(sub_step_69_1 == sub_step_69_2);
  assert(stage_v_69_1 == stage_v_69_2);
  assert(sub_step_70_1 == sub_step_70_2);
  assert(stage_v_70_1 == stage_v_70_2);
  assert(sub_step_71_1 == sub_step_71_2);
  assert(stage_v_71_1 == stage_v_71_2);
  assert(sub_step_72_1 == sub_step_72_2);
  assert(stage_v_72_1 == stage_v_72_2);
  assert(sub_step_73_1 == sub_step_73_2);
  assert(stage_v_73_1 == stage_v_73_2);
  assert(sub_step_74_1 == sub_step_74_2);
  assert(stage_v_74_1 == stage_v_74_2);
  assert(sub_step_75_1 == sub_step_75_2);
  assert(stage_v_75_1 == stage_v_75_2);
  assert(sub_step_76_1 == sub_step_76_2);
  assert(stage_v_76_1 == stage_v_76_2);
  assert(sub_step_77_1 == sub_step_77_2);
  assert(stage_v_77_1 == stage_v_77_2);
  assert(sub_step_78_1 == sub_step_78_2);
  assert(stage_v_78_1 == stage_v_78_2);
  assert(sub_step_79_1 == sub_step_79_2);
  assert(stage_v_79_1 == stage_v_79_2);
  assert(sub_step_80_1 == sub_step_80_2);
  assert(stage_v_80_1 == stage_v_80_2);
  assert(sub_step_81_1 == sub_step_81_2);
  assert(stage_v_81_1 == stage_v_81_2);
  assert(sub_step_82_1 == sub_step_82_2);
  assert(stage_v_82_1 == stage_v_82_2);
  assert(sub_step_83_1 == sub_step_83_2);
  assert(stage_v_83_1 == stage_v_83_2);
  assert(sub_step_84_1 == sub_step_84_2);
  assert(stage_v_84_1 == stage_v_84_2);
  assert(sub_step_85_1 == sub_step_85_2);
  assert(stage_v_85_1 == stage_v_85_2);
  assert(sub_step_86_1 == sub_step_86_2);
  assert(stage_v_86_1 == stage_v_86_2);
  assert(sub_step_87_1 == sub_step_87_2);
  assert(stage_v_87_1 == stage_v_87_2);
  assert(sub_step_88_1 == sub_step_88_2);
  assert(stage_v_88_1 == stage_v_88_2);
  assert(sub_step_89_1 == sub_step_89_2);
  assert(stage_v_89_1 == stage_v_89_2);
  assert(sub_step_90_1 == sub_step_90_2);
  assert(stage_v_90_1 == stage_v_90_2);
  assert(sub_step_91_1 == sub_step_91_2);
  assert(stage_v_91_1 == stage_v_91_2);
  assert(sub_step_92_1 == sub_step_92_2);
  assert(stage_v_92_1 == stage_v_92_2);
  assert(sub_step_93_1 == sub_step_93_2);
  assert(stage_v_93_1 == stage_v_93_2);
  assert(sub_step_94_1 == sub_step_94_2);
  assert(stage_v_94_1 == stage_v_94_2);
  assert(sub_step_95_1 == sub_step_95_2);
  assert(stage_v_95_1 == stage_v_95_2);
  assert(sub_step_96_1 == sub_step_96_2);
  assert(stage_v_96_1 == stage_v_96_2);
  assert(sub_step_97_1 == sub_step_97_2);
  assert(stage_v_97_1 == stage_v_97_2);
  assert(sub_step_98_1 == sub_step_98_2);
  assert(stage_v_98_1 == stage_v_98_2);
  assert(sub_step_99_1 == sub_step_99_2);
  assert(stage_v_99_1 == stage_v_99_2);
  assert(sub_step_100_1 == sub_step_100_2);
  assert(stage_v_100_1 == stage_v_100_2);
  assert(sub_step_101_1 == sub_step_101_2);
  assert(stage_v_101_1 == stage_v_101_2);
  assert(sub_step_102_1 == sub_step_102_2);
  assert(stage_v_102_1 == stage_v_102_2);
  assert(sub_step_103_1 == sub_step_103_2);
  assert(stage_v_103_1 == stage_v_103_2);
  assert(sub_step_104_1 == sub_step_104_2);
  assert(stage_v_104_1 == stage_v_104_2);
  assert(sub_step_105_1 == sub_step_105_2);
  assert(stage_v_105_1 == stage_v_105_2);
  assert(sub_step_106_1 == sub_step_106_2);
  assert(stage_v_106_1 == stage_v_106_2);
  assert(sub_step_107_1 == sub_step_107_2);
  assert(stage_v_107_1 == stage_v_107_2);
  assert(sub_step_108_1 == sub_step_108_2);
  assert(stage_v_108_1 == stage_v_108_2);
  assert(sub_step_109_1 == sub_step_109_2);
  assert(stage_v_109_1 == stage_v_109_2);
  assert(sub_step_110_1 == sub_step_110_2);
  assert(stage_v_110_1 == stage_v_110_2);
  assert(sub_step_111_1 == sub_step_111_2);
  assert(stage_v_111_1 == stage_v_111_2);
  assert(sub_step_112_1 == sub_step_112_2);
  assert(stage_v_112_1 == stage_v_112_2);
  assert(sub_step_113_1 == sub_step_113_2);
  assert(stage_v_113_1 == stage_v_113_2);
  assert(sub_step_114_1 == sub_step_114_2);
  assert(stage_v_114_1 == stage_v_114_2);
  assert(sub_step_115_1 == sub_step_115_2);
  assert(stage_v_115_1 == stage_v_115_2);
  assert(sub_step_116_1 == sub_step_116_2);
  assert(stage_v_116_1 == stage_v_116_2);
  assert(sub_step_117_1 == sub_step_117_2);
  assert(stage_v_117_1 == stage_v_117_2);
  assert(sub_step_118_1 == sub_step_118_2);
  assert(stage_v_118_1 == stage_v_118_2);
  assert(sub_step_119_1 == sub_step_119_2);
  assert(stage_v_119_1 == stage_v_119_2);
  assert(sub_step_120_1 == sub_step_120_2);
  assert(stage_v_120_1 == stage_v_120_2);
  assert(sub_step_121_1 == sub_step_121_2);
  assert(stage_v_121_1 == stage_v_121_2);
  assert(sub_step_122_1 == sub_step_122_2);
  assert(stage_v_122_1 == stage_v_122_2);
  assert(sub_step_123_1 == sub_step_123_2);
  assert(stage_v_123_1 == stage_v_123_2);
  assert(sub_step_124_1 == sub_step_124_2);
  assert(stage_v_124_1 == stage_v_124_2);
  assert(sub_step_125_1 == sub_step_125_2);
  assert(stage_v_125_1 == stage_v_125_2);
  assert(sub_step_126_1 == sub_step_126_2);
  assert(stage_v_126_1 == stage_v_126_2);
  assert(sub_step_127_1 == sub_step_127_2);
  assert(stage_v_127_1 == stage_v_127_2);
  assert(sub_step_128_1 == sub_step_128_2);
  assert(stage_v_128_1 == stage_v_128_2);
  assert(sub_step_129_1 == sub_step_129_2);
  assert(stage_v_129_1 == stage_v_129_2);
  assert(sub_step_130_1 == sub_step_130_2);
  assert(stage_v_130_1 == stage_v_130_2);
  assert(sub_step_131_1 == sub_step_131_2);
  assert(stage_v_131_1 == stage_v_131_2);
  assert(sub_step_132_1 == sub_step_132_2);
  assert(stage_v_132_1 == stage_v_132_2);
  assert(sub_step_133_1 == sub_step_133_2);
  assert(stage_v_133_1 == stage_v_133_2);
  assert(sub_step_134_1 == sub_step_134_2);
  assert(stage_v_134_1 == stage_v_134_2);
  assert(sub_step_135_1 == sub_step_135_2);
  assert(stage_v_135_1 == stage_v_135_2);
  assert(sub_step_136_1 == sub_step_136_2);
  assert(stage_v_136_1 == stage_v_136_2);
  assert(sub_step_137_1 == sub_step_137_2);
  assert(stage_v_137_1 == stage_v_137_2);
  assert(sub_step_138_1 == sub_step_138_2);
  assert(stage_v_138_1 == stage_v_138_2);
  assert(sub_step_139_1 == sub_step_139_2);
  assert(stage_v_139_1 == stage_v_139_2);
  assert(sub_step_140_1 == sub_step_140_2);
  assert(stage_v_140_1 == stage_v_140_2);
  assert(sub_step_141_1 == sub_step_141_2);
  assert(stage_v_141_1 == stage_v_141_2);
  assert(sub_step_142_1 == sub_step_142_2);
  assert(stage_v_142_1 == stage_v_142_2);
  assert(sub_step_143_1 == sub_step_143_2);
  assert(stage_v_143_1 == stage_v_143_2);
  assert(sub_step_144_1 == sub_step_144_2);
  assert(stage_v_144_1 == stage_v_144_2);
  assert(sub_step_145_1 == sub_step_145_2);
  assert(stage_v_145_1 == stage_v_145_2);
  assert(sub_step_146_1 == sub_step_146_2);
  assert(stage_v_146_1 == stage_v_146_2);
  assert(sub_step_147_1 == sub_step_147_2);
  assert(stage_v_147_1 == stage_v_147_2);
  assert(sub_step_148_1 == sub_step_148_2);
  assert(stage_v_148_1 == stage_v_148_2);
  assert(sub_step_149_1 == sub_step_149_2);
  assert(stage_v_149_1 == stage_v_149_2);
  assert(sub_step_150_1 == sub_step_150_2);
  assert(stage_v_150_1 == stage_v_150_2);
  assert(sub_step_151_1 == sub_step_151_2);
  assert(stage_v_151_1 == stage_v_151_2);
  assert(sub_step_152_1 == sub_step_152_2);
  assert(stage_v_152_1 == stage_v_152_2);
  assert(sub_step_153_1 == sub_step_153_2);
  assert(stage_v_153_1 == stage_v_153_2);
  assert(sub_step_154_1 == sub_step_154_2);
  assert(stage_v_154_1 == stage_v_154_2);
  assert(sub_step_155_1 == sub_step_155_2);
  assert(stage_v_155_1 == stage_v_155_2);
  assert(sub_step_156_1 == sub_step_156_2);
  assert(stage_v_156_1 == stage_v_156_2);
  assert(sub_step_157_1 == sub_step_157_2);
  assert(stage_v_157_1 == stage_v_157_2);
  assert(sub_step_158_1 == sub_step_158_2);
  assert(stage_v_158_1 == stage_v_158_2);
  assert(sub_step_159_1 == sub_step_159_2);
  assert(stage_v_159_1 == stage_v_159_2);
  assert(sub_step_160_1 == sub_step_160_2);
  assert(stage_v_160_1 == stage_v_160_2);
  assert(sub_step_161_1 == sub_step_161_2);
  assert(stage_v_161_1 == stage_v_161_2);
  assert(sub_step_162_1 == sub_step_162_2);
  assert(stage_v_162_1 == stage_v_162_2);
  assert(sub_step_163_1 == sub_step_163_2);
  assert(stage_v_163_1 == stage_v_163_2);
  assert(sub_step_164_1 == sub_step_164_2);
  assert(stage_v_164_1 == stage_v_164_2);
  assert(sub_step_165_1 == sub_step_165_2);
  assert(stage_v_165_1 == stage_v_165_2);
  assert(sub_step_166_1 == sub_step_166_2);
  assert(stage_v_166_1 == stage_v_166_2);
  assert(sub_step_167_1 == sub_step_167_2);
  assert(stage_v_167_1 == stage_v_167_2);
  assert(sub_step_168_1 == sub_step_168_2);
  assert(stage_v_168_1 == stage_v_168_2);
  assert(sub_step_169_1 == sub_step_169_2);
  assert(stage_v_169_1 == stage_v_169_2);
  assert(sub_step_170_1 == sub_step_170_2);
  assert(stage_v_170_1 == stage_v_170_2);
  assert(sub_step_171_1 == sub_step_171_2);
  assert(stage_v_171_1 == stage_v_171_2);
  assert(sub_step_172_1 == sub_step_172_2);
  assert(stage_v_172_1 == stage_v_172_2);
  assert(sub_step_173_1 == sub_step_173_2);
  assert(stage_v_173_1 == stage_v_173_2);
  assert(sub_step_174_1 == sub_step_174_2);
  assert(stage_v_174_1 == stage_v_174_2);
  assert(sub_step_175_1 == sub_step_175_2);
  assert(stage_v_175_1 == stage_v_175_2);
  assert(sub_step_176_1 == sub_step_176_2);
  assert(stage_v_176_1 == stage_v_176_2);
  assert(sub_step_177_1 == sub_step_177_2);
  assert(stage_v_177_1 == stage_v_177_2);
  assert(sub_step_178_1 == sub_step_178_2);
  assert(stage_v_178_1 == stage_v_178_2);
  assert(sub_step_179_1 == sub_step_179_2);
  assert(stage_v_179_1 == stage_v_179_2);
  assert(sub_step_180_1 == sub_step_180_2);
  assert(stage_v_180_1 == stage_v_180_2);
  assert(sub_step_181_1 == sub_step_181_2);
  assert(stage_v_181_1 == stage_v_181_2);
  assert(sub_step_182_1 == sub_step_182_2);
  assert(stage_v_182_1 == stage_v_182_2);
  assert(sub_step_183_1 == sub_step_183_2);
  assert(stage_v_183_1 == stage_v_183_2);
  assert(sub_step_184_1 == sub_step_184_2);
  assert(stage_v_184_1 == stage_v_184_2);
  assert(sub_step_185_1 == sub_step_185_2);
  assert(stage_v_185_1 == stage_v_185_2);
  assert(sub_step_186_1 == sub_step_186_2);
  assert(stage_v_186_1 == stage_v_186_2);
  assert(sub_step_187_1 == sub_step_187_2);
  assert(stage_v_187_1 == stage_v_187_2);
  assert(sub_step_188_1 == sub_step_188_2);
  assert(stage_v_188_1 == stage_v_188_2);
  assert(sub_step_189_1 == sub_step_189_2);
  assert(stage_v_189_1 == stage_v_189_2);
  assert(sub_step_190_1 == sub_step_190_2);
  assert(stage_v_190_1 == stage_v_190_2);
  assert(sub_step_191_1 == sub_step_191_2);
  assert(stage_v_191_1 == stage_v_191_2);
  assert(sub_step_192_1 == sub_step_192_2);
  assert(stage_v_192_1 == stage_v_192_2);
  assert(sub_step_193_1 == sub_step_193_2);
  assert(stage_v_193_1 == stage_v_193_2);
  assert(sub_step_194_1 == sub_step_194_2);
  assert(stage_v_194_1 == stage_v_194_2);
  assert(sub_step_195_1 == sub_step_195_2);
  assert(stage_v_195_1 == stage_v_195_2);
  assert(sub_step_196_1 == sub_step_196_2);
  assert(stage_v_196_1 == stage_v_196_2);
  assert(sub_step_197_1 == sub_step_197_2);
  assert(stage_v_197_1 == stage_v_197_2);
  assert(sub_step_198_1 == sub_step_198_2);
  assert(stage_v_198_1 == stage_v_198_2);
  assert(sub_step_199_1 == sub_step_199_2);
  assert(stage_v_199_1 == stage_v_199_2);
  assert(sub_step_200_1 == sub_step_200_2);
  assert(stage_v_200_1 == stage_v_200_2);
  assert(sub_step_201_1 == sub_step_201_2);
  assert(stage_v_201_1 == stage_v_201_2);
  assert(sub_step_202_1 == sub_step_202_2);
  assert(stage_v_202_1 == stage_v_202_2);
  assert(sub_step_203_1 == sub_step_203_2);
  assert(stage_v_203_1 == stage_v_203_2);
  assert(sub_step_204_1 == sub_step_204_2);
  assert(stage_v_204_1 == stage_v_204_2);
  assert(sub_step_205_1 == sub_step_205_2);
  assert(stage_v_205_1 == stage_v_205_2);
  assert(sub_step_206_1 == sub_step_206_2);
  assert(stage_v_206_1 == stage_v_206_2);
  assert(sub_step_207_1 == sub_step_207_2);
  assert(stage_v_207_1 == stage_v_207_2);
  assert(sub_step_208_1 == sub_step_208_2);
  assert(stage_v_208_1 == stage_v_208_2);
  assert(sub_step_209_1 == sub_step_209_2);
  assert(stage_v_209_1 == stage_v_209_2);
  assert(sub_step_210_1 == sub_step_210_2);
  assert(stage_v_210_1 == stage_v_210_2);
  assert(sub_step_211_1 == sub_step_211_2);
  assert(stage_v_211_1 == stage_v_211_2);
  assert(sub_step_212_1 == sub_step_212_2);
  assert(stage_v_212_1 == stage_v_212_2);
  assert(sub_step_213_1 == sub_step_213_2);
  assert(stage_v_213_1 == stage_v_213_2);
  assert(sub_step_214_1 == sub_step_214_2);
  assert(stage_v_214_1 == stage_v_214_2);
  assert(sub_step_215_1 == sub_step_215_2);
  assert(stage_v_215_1 == stage_v_215_2);
  assert(sub_step_216_1 == sub_step_216_2);
  assert(stage_v_216_1 == stage_v_216_2);
  assert(sub_step_217_1 == sub_step_217_2);
  assert(stage_v_217_1 == stage_v_217_2);
  assert(sub_step_218_1 == sub_step_218_2);
  assert(stage_v_218_1 == stage_v_218_2);
  assert(sub_step_219_1 == sub_step_219_2);
  assert(stage_v_219_1 == stage_v_219_2);
  assert(sub_step_220_1 == sub_step_220_2);
  assert(stage_v_220_1 == stage_v_220_2);
  assert(sub_step_221_1 == sub_step_221_2);
  assert(stage_v_221_1 == stage_v_221_2);
  assert(sub_step_222_1 == sub_step_222_2);
  assert(stage_v_222_1 == stage_v_222_2);
  assert(sub_step_223_1 == sub_step_223_2);
  assert(stage_v_223_1 == stage_v_223_2);
  assert(sub_step_224_1 == sub_step_224_2);
  assert(stage_v_224_1 == stage_v_224_2);
  assert(sub_step_225_1 == sub_step_225_2);
  assert(stage_v_225_1 == stage_v_225_2);
  assert(sub_step_226_1 == sub_step_226_2);
  assert(stage_v_226_1 == stage_v_226_2);
  assert(sub_step_227_1 == sub_step_227_2);
  assert(stage_v_227_1 == stage_v_227_2);
  assert(sub_step_228_1 == sub_step_228_2);
  assert(stage_v_228_1 == stage_v_228_2);
  assert(sub_step_229_1 == sub_step_229_2);
  assert(stage_v_229_1 == stage_v_229_2);
  assert(sub_step_230_1 == sub_step_230_2);
  assert(stage_v_230_1 == stage_v_230_2);
  assert(sub_step_231_1 == sub_step_231_2);
  assert(stage_v_231_1 == stage_v_231_2);
  assert(sub_step_232_1 == sub_step_232_2);
  assert(stage_v_232_1 == stage_v_232_2);
  assert(sub_step_233_1 == sub_step_233_2);
  assert(stage_v_233_1 == stage_v_233_2);
  assert(sub_step_234_1 == sub_step_234_2);
  assert(stage_v_234_1 == stage_v_234_2);
  assert(sub_step_235_1 == sub_step_235_2);
  assert(stage_v_235_1 == stage_v_235_2);
  assert(sub_step_236_1 == sub_step_236_2);
  assert(stage_v_236_1 == stage_v_236_2);
  assert(sub_step_237_1 == sub_step_237_2);
  assert(stage_v_237_1 == stage_v_237_2);
  assert(sub_step_238_1 == sub_step_238_2);
  assert(stage_v_238_1 == stage_v_238_2);
  assert(sub_step_239_1 == sub_step_239_2);
  assert(stage_v_239_1 == stage_v_239_2);
  assert(sub_step_240_1 == sub_step_240_2);
  assert(stage_v_240_1 == stage_v_240_2);
  assert(sub_step_241_1 == sub_step_241_2);
  assert(stage_v_241_1 == stage_v_241_2);
  assert(sub_step_242_1 == sub_step_242_2);
  assert(stage_v_242_1 == stage_v_242_2);
  assert(sub_step_243_1 == sub_step_243_2);
  assert(stage_v_243_1 == stage_v_243_2);
  assert(sub_step_244_1 == sub_step_244_2);
  assert(stage_v_244_1 == stage_v_244_2);
  assert(sub_step_245_1 == sub_step_245_2);
  assert(stage_v_245_1 == stage_v_245_2);
  assert(sub_step_246_1 == sub_step_246_2);
  assert(stage_v_246_1 == stage_v_246_2);
  assert(sub_step_247_1 == sub_step_247_2);
  assert(stage_v_247_1 == stage_v_247_2);
  assert(sub_step_248_1 == sub_step_248_2);
  assert(stage_v_248_1 == stage_v_248_2);
}


