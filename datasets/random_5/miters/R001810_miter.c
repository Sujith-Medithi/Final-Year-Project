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
struct DeviceConfig_R001810_1013_0
{
  unsigned char id;
  int stop_bits;
  short parity;
  unsigned char timeout;
  short port;
  int buffer[3];
};
struct SensorNode_R001810_1013_1
{
  short reading;
  short offset;
  unsigned char gain;
  int buffer[3];
};
union TelemetryField_R001810_1013_0
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
void fn_R001810_1013_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st_1 = {0};
  struct DeviceConfig_R001810_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int quantum_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_88_1)
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

  switch (quantum_88_2)
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

  int quantum_59_1 = 0;
  int quantum_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_59_1 = ((quantum_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_59_2 = ((quantum_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_59_1) & 127;
    acc_2 = (acc_2 + quantum_59_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_88_1 == quantum_88_2);
  assert(quantum_59_1 == quantum_59_2);
}

int fn_R001810_1013_0(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int quantum_88 = (aux + st.buffer[1]) & 3;
  switch (quantum_88)
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

  int quantum_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_59 = ((quantum_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_59) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001810_1013_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001810_1013_1 st_1 = {0};
  struct SensorNode_R001810_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int vector_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_31_1 > 37)
  {
    acc_1 = ((acc_1 + (vector_31_1 * 2)) + 5) & 127;
    aux_1 ^= vector_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_31_2 > 37)
  {
    acc_2 = ((acc_2 + (vector_31_2 * 2)) + 5) & 127;
    aux_2 ^= vector_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_16_1) & 63;
  aux_2 = (aux_2 + anchor_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_31_1 == vector_31_2);
  assert(anchor_16_1 == anchor_16_2);
}

int fn_R001810_1013_1(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001810_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int vector_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_31 > 37)
  {
    acc = ((acc + (vector_31 * 2)) + 5) & 127;
    aux ^= vector_31 & 15;
  }
  else
  {
    acc = ((acc - vector_31) + 11) & 127;
    aux += 3;
  }
  int anchor_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_16) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001810_1013_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001810_1013_1 st_1 = {0};
  struct SensorNode_R001810_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int checksum_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_35_1 > 12)
  {
    acc_1 = ((acc_1 + (checksum_35_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_35_2 > 12)
  {
    acc_2 = ((acc_2 + (checksum_35_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_35_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_52_1 = 0;
  int accumulator_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_52_1 = ((accumulator_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_52_2 = ((accumulator_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_52_1) & 127;
    acc_2 = (acc_2 + accumulator_52_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_35_1 == checksum_35_2);
  assert(accumulator_52_1 == accumulator_52_2);
}

int fn_R001810_1013_2(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001810_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int checksum_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_35 > 12)
  {
    acc = ((acc + (checksum_35 * 2)) + 5) & 127;
    aux ^= checksum_35 & 15;
  }
  else
  {
    acc = ((acc - checksum_35) + 11) & 127;
    aux += 3;
  }
  int accumulator_52 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_52 = ((accumulator_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_52) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001810_1013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st_1 = {0};
  struct DeviceConfig_R001810_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_47_1 = local_arr_1[aux_1 % 3];
  int delta_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_47_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_47_1 == delta_47_2);
}

int fn_R001810_1013_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int delta_47 = local_arr[aux % 3];
  acc = (acc + (delta_47 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001810_1013_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001810_1013_1 st_1 = {0};
  struct SensorNode_R001810_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int pivot_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_15_1 > 30)
  {
    acc_1 = ((acc_1 + (pivot_15_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_15_2 > 30)
  {
    acc_2 = ((acc_2 + (pivot_15_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_15_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_57_1 = local_arr_1[aux_1 % 3];
  int pivot_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_57_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_15_1 == pivot_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_57_1 == pivot_57_2);
}

int fn_R001810_1013_4(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001810_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int pivot_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_15 > 30)
  {
    acc = ((acc + (pivot_15 * 2)) + 5) & 127;
    aux ^= pivot_15 & 15;
  }
  else
  {
    acc = ((acc - pivot_15) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int pivot_57 = local_arr[aux % 3];
  acc = (acc + (pivot_57 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001810_1013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001810_1013_1 st_1 = {0};
  struct SensorNode_R001810_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int accumulator_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_38_1) & 63;
  aux_2 = (aux_2 + accumulator_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_21_1 = 0;
  int delta_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_21_1 = ((delta_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_21_2 = ((delta_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_21_1) & 127;
    acc_2 = (acc_2 + delta_21_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_38_1 == accumulator_38_2);
  assert(delta_21_1 == delta_21_2);
}

int fn_R001810_1013_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001810_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int accumulator_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_38) & 63;
  acc ^= aux;
  int delta_21 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_21 = ((delta_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_21) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001810_1013_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001810_1013_1 st_1 = {0};
  struct SensorNode_R001810_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int stride_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_44_1 > 40)
  {
    acc_1 = ((acc_1 + (stride_44_1 * 2)) + 5) & 127;
    aux_1 ^= stride_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_44_2 > 40)
  {
    acc_2 = ((acc_2 + (stride_44_2 * 2)) + 5) & 127;
    aux_2 ^= stride_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_44_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_66_1)
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

  switch (quantum_66_2)
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

  int window_67_1 = 0;
  int window_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_67_1 = ((window_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_67_2 = ((window_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_67_1) & 127;
    acc_2 = (acc_2 + window_67_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_44_1 == stride_44_2);
  assert(quantum_66_1 == quantum_66_2);
  assert(window_67_1 == window_67_2);
}

int fn_R001810_1013_6(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001810_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int stride_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_44 > 40)
  {
    acc = ((acc + (stride_44 * 2)) + 5) & 127;
    aux ^= stride_44 & 15;
  }
  else
  {
    acc = ((acc - stride_44) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_66 = (aux + st.buffer[1]) & 3;
  switch (quantum_66)
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

  int window_67 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_67 = ((window_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_67) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001810_1013_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st_1 = {0};
  struct DeviceConfig_R001810_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int weight_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_53_1)
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

  switch (weight_53_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_78_1 > 38)
  {
    acc_1 = ((acc_1 + (coefficient_78_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_78_2 > 38)
  {
    acc_2 = ((acc_2 + (coefficient_78_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_78_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_53_1 == weight_53_2);
  assert(coefficient_78_1 == coefficient_78_2);
}

int fn_R001810_1013_7(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int weight_53 = (aux + st.buffer[1]) & 3;
  switch (weight_53)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_78 > 38)
  {
    acc = ((acc + (coefficient_78 * 2)) + 5) & 127;
    aux ^= coefficient_78 & 15;
  }
  else
  {
    acc = ((acc - coefficient_78) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001810_1013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st_1 = {0};
  struct DeviceConfig_R001810_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int tally_72_1 = 0;
  int tally_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_72_1 = ((tally_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_72_2 = ((tally_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_72_1) & 127;
    acc_2 = (acc_2 + tally_72_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_76_1 = local_arr_1[aux_1 % 3];
  int coefficient_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_76_2 * 2)) & 127;
  int sample_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_15_1 > 50)
  {
    acc_1 = ((acc_1 + (sample_15_1 * 2)) + 5) & 127;
    aux_1 ^= sample_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_15_2 > 50)
  {
    acc_2 = ((acc_2 + (sample_15_2 * 2)) + 5) & 127;
    aux_2 ^= sample_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_15_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_72_1 == tally_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_76_1 == coefficient_76_2);
  assert(sample_15_1 == sample_15_2);
}

int fn_R001810_1013_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int tally_72 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_72 = ((tally_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_72) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int coefficient_76 = local_arr[aux % 3];
  acc = (acc + (coefficient_76 * 2)) & 127;
  int sample_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_15 > 50)
  {
    acc = ((acc + (sample_15 * 2)) + 5) & 127;
    aux ^= sample_15 & 15;
  }
  else
  {
    acc = ((acc - sample_15) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001810_1013_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st_1 = {0};
  struct DeviceConfig_R001810_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int parity_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_46_1) & 63;
  aux_2 = (aux_2 + parity_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_73_1)
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

  switch (anchor_73_2)
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

  int index_reg_28_1 = 0;
  int index_reg_28_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_28_1 = ((index_reg_28_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_28_2 = ((index_reg_28_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_28_1) & 127;
    acc_2 = (acc_2 + index_reg_28_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_46_1 == parity_46_2);
  assert(anchor_73_1 == anchor_73_2);
  assert(index_reg_28_1 == index_reg_28_2);
}

int fn_R001810_1013_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int parity_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_46) & 63;
  acc ^= aux;
  int anchor_73 = (aux + st.buffer[1]) & 3;
  switch (anchor_73)
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

  int index_reg_28 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_28 = ((index_reg_28 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_28) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001810_1013_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001810_1013_1 st_1 = {0};
  struct SensorNode_R001810_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_90_1 = local_arr_1[aux_1 % 3];
  int cursor_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_90_2 * 2)) & 127;
  int weight_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_50_1) & 63;
  aux_2 = (aux_2 + weight_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_10_1 > 45)
  {
    acc_1 = ((acc_1 + (metric_10_1 * 2)) + 5) & 127;
    aux_1 ^= metric_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_10_2 > 45)
  {
    acc_2 = ((acc_2 + (metric_10_2 * 2)) + 5) & 127;
    aux_2 ^= metric_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_87_1 = 0;
  int stride_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_87_1 = ((stride_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_87_2 = ((stride_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_87_1) & 127;
    acc_2 = (acc_2 + stride_87_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_90_1 == cursor_90_2);
  assert(weight_50_1 == weight_50_2);
  assert(metric_10_1 == metric_10_2);
  assert(stride_87_1 == stride_87_2);
}

int fn_R001810_1013_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001810_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int cursor_90 = local_arr[aux % 3];
  acc = (acc + (cursor_90 * 2)) & 127;
  int weight_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_50) & 63;
  acc ^= aux;
  int metric_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_10 > 45)
  {
    acc = ((acc + (metric_10 * 2)) + 5) & 127;
    aux ^= metric_10 & 15;
  }
  else
  {
    acc = ((acc - metric_10) + 11) & 127;
    aux += 3;
  }
  int stride_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_87 = ((stride_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_87) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001810_1013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st_1 = {0};
  struct DeviceConfig_R001810_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int checksum_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_45_1 > 27)
  {
    acc_1 = ((acc_1 + (checksum_45_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_45_2 > 27)
  {
    acc_2 = ((acc_2 + (checksum_45_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_66_1)
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

  switch (window_66_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_45_1 == checksum_45_2);
  assert(window_66_1 == window_66_2);
}

int fn_R001810_1013_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int checksum_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_45 > 27)
  {
    acc = ((acc + (checksum_45 * 2)) + 5) & 127;
    aux ^= checksum_45 & 15;
  }
  else
  {
    acc = ((acc - checksum_45) + 11) & 127;
    aux += 3;
  }
  int window_66 = (aux + st.buffer[1]) & 3;
  switch (window_66)
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

void fn_R001810_1013_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001810_1013_1 st_1 = {0};
  struct SensorNode_R001810_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int phase_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_43_1 > 39)
  {
    acc_1 = ((acc_1 + (phase_43_1 * 2)) + 5) & 127;
    aux_1 ^= phase_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_43_2 > 39)
  {
    acc_2 = ((acc_2 + (phase_43_2 * 2)) + 5) & 127;
    aux_2 ^= phase_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_43_1)
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

  switch (anchor_43_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_43_1 == phase_43_2);
  assert(anchor_43_1 == anchor_43_2);
}

int fn_R001810_1013_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001810_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int phase_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_43 > 39)
  {
    acc = ((acc + (phase_43 * 2)) + 5) & 127;
    aux ^= phase_43 & 15;
  }
  else
  {
    acc = ((acc - phase_43) + 11) & 127;
    aux += 3;
  }
  int anchor_43 = (aux + st.buffer[1]) & 3;
  switch (anchor_43)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001810_1013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001810_1013_1 st_1 = {0};
  struct SensorNode_R001810_1013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_54_1 = 0;
  int quantum_54_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_54_1 = ((quantum_54_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_54_2 = ((quantum_54_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_54_1) & 127;
    acc_2 = (acc_2 + quantum_54_2) & 127;
  }

  int bound_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_99_1) & 63;
  aux_2 = (aux_2 + bound_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_44_1)
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

  switch (stride_44_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_54_1 == quantum_54_2);
  assert(bound_99_1 == bound_99_2);
  assert(stride_44_1 == stride_44_2);
}

int fn_R001810_1013_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001810_1013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_54 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_54 = ((quantum_54 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_54) & 127;
  }

  int bound_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_99) & 63;
  acc ^= aux;
  int stride_44 = (aux + st.buffer[1]) & 3;
  switch (stride_44)
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

void fn_R001810_1013_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st_1 = {0};
  struct DeviceConfig_R001810_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_66_1 = local_arr_1[aux_1 % 3];
  int segment_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_66_2 * 2)) & 127;
  int weight_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_66_1)
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

  switch (weight_66_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_66_1 == segment_66_2);
  assert(weight_66_1 == weight_66_2);
}

int fn_R001810_1013_14(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int segment_66 = local_arr[aux % 3];
  acc = (acc + (segment_66 * 2)) & 127;
  int weight_66 = (aux + st.buffer[1]) & 3;
  switch (weight_66)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001810_1013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st_1 = {0};
  struct DeviceConfig_R001810_1013_0 st_2 = {0};
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
  int anchor_67_1 = 0;
  int anchor_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_67_1 = ((anchor_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_67_2 = ((anchor_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_67_1) & 127;
    acc_2 = (acc_2 + anchor_67_2) & 127;
  }

  int window_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_33_1 > 39)
  {
    acc_1 = ((acc_1 + (window_33_1 * 2)) + 5) & 127;
    aux_1 ^= window_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_33_2 > 39)
  {
    acc_2 = ((acc_2 + (window_33_2 * 2)) + 5) & 127;
    aux_2 ^= window_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_33_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_67_1 == anchor_67_2);
  assert(window_33_1 == window_33_2);
}

int fn_R001810_1013_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_67 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_67 = ((anchor_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_67) & 127;
  }

  int window_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_33 > 39)
  {
    acc = ((acc + (window_33 * 2)) + 5) & 127;
    aux ^= window_33 & 15;
  }
  else
  {
    acc = ((acc - window_33) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001810_1013_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st_1 = {0};
  struct DeviceConfig_R001810_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int tracker_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_56_1)
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

  switch (tracker_56_2)
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
  int pivot_67_1 = local_arr_1[aux_1 % 3];
  int pivot_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_67_2 * 2)) & 127;
  int metric_77_1 = 0;
  int metric_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_77_1 = ((metric_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_77_2 = ((metric_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_77_1) & 127;
    acc_2 = (acc_2 + metric_77_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_56_1 == tracker_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_67_1 == pivot_67_2);
  assert(metric_77_1 == metric_77_2);
}

int fn_R001810_1013_16(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int tracker_56 = (aux + st.buffer[1]) & 3;
  switch (tracker_56)
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
  int pivot_67 = local_arr[aux % 3];
  acc = (acc + (pivot_67 * 2)) & 127;
  int metric_77 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_77 = ((metric_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_77) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001810_1013_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st_1 = {0};
  struct DeviceConfig_R001810_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_84_1 = 0;
  int checksum_84_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_84_1 = ((checksum_84_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_84_2 = ((checksum_84_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_84_1) & 127;
    acc_2 = (acc_2 + checksum_84_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_36_1 = local_arr_1[aux_1 % 3];
  int tracker_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_36_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_84_1 == checksum_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_36_1 == tracker_36_2);
}

int fn_R001810_1013_17(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_84 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_84 = ((checksum_84 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_84) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tracker_36 = local_arr[aux % 3];
  acc = (acc + (tracker_36 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001810_1013_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st_1 = {0};
  struct DeviceConfig_R001810_1013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int cursor_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_24_1) & 63;
  aux_2 = (aux_2 + cursor_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_54_1 = 0;
  int weight_54_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_54_1 = ((weight_54_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_54_2 = ((weight_54_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_54_1) & 127;
    acc_2 = (acc_2 + weight_54_2) & 127;
  }

  int phase_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_55_1)
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

  switch (phase_55_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_24_1 == cursor_24_2);
  assert(weight_54_1 == weight_54_2);
  assert(phase_55_1 == phase_55_2);
}

int fn_R001810_1013_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001810_1013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int cursor_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_24) & 63;
  acc ^= aux;
  int weight_54 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_54 = ((weight_54 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_54) & 127;
  }

  int phase_55 = (aux + st.buffer[1]) & 3;
  switch (phase_55)
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

void main()
{
  int sec_r001810_0_1;
  int sec_r001810_0_2;
  int sec_r001810_1_1;
  int sec_r001810_1_2;
  int sec_r001810_2_1;
  int sec_r001810_2_2;
  int sec_r001810_3_1;
  int sec_r001810_3_2;
  int sec_r001810_4_1;
  int sec_r001810_4_2;
  int sec_r001810_5_1;
  int sec_r001810_5_2;
  int sec_r001810_6_1;
  int sec_r001810_6_2;
  int sec_r001810_7_1;
  int sec_r001810_7_2;
  int sec_r001810_8_1;
  int sec_r001810_8_2;
  int sec_r001810_9_1;
  int sec_r001810_9_2;
  int sec_r001810_10_1;
  int sec_r001810_10_2;
  int sec_r001810_11_1;
  int sec_r001810_11_2;
  int sec_r001810_12_1;
  int sec_r001810_12_2;
  int sec_r001810_13_1;
  int sec_r001810_13_2;
  int sec_r001810_14_1;
  int sec_r001810_14_2;
  int sec_r001810_15_1;
  int sec_r001810_15_2;
  int sec_r001810_16_1;
  int sec_r001810_16_2;
  int pub_r001810_0_1;
  int pub_r001810_0_2;
  int pub_r001810_1_1;
  int pub_r001810_1_2;
  int pub_r001810_2_1;
  int pub_r001810_2_2;
  int pub_r001810_3_1;
  int pub_r001810_3_2;
  int pub_r001810_4_1;
  int pub_r001810_4_2;
  int pub_r001810_5_1;
  int pub_r001810_5_2;
  int pub_r001810_6_1;
  int pub_r001810_6_2;
  int pub_r001810_7_1;
  int pub_r001810_7_2;
  int pub_r001810_8_1;
  int pub_r001810_8_2;
  int pub_r001810_9_1;
  int pub_r001810_9_2;
  int pub_r001810_10_1;
  int pub_r001810_10_2;
  int pub_r001810_11_1;
  int pub_r001810_11_2;
  int pub_r001810_12_1;
  int pub_r001810_12_2;
  int pub_r001810_13_1;
  int pub_r001810_13_2;
  int pub_r001810_14_1;
  int pub_r001810_14_2;
  int pub_r001810_15_1;
  int pub_r001810_15_2;
  int pub_r001810_16_1;
  int pub_r001810_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001810_0_1 >= (-100)) && (pub_r001810_0_1 <= 100));
  __CPROVER_assume((pub_r001810_0_2 >= (-100)) && (pub_r001810_0_2 <= 100));
  __CPROVER_assume((pub_r001810_1_1 >= (-100)) && (pub_r001810_1_1 <= 100));
  __CPROVER_assume((pub_r001810_1_2 >= (-100)) && (pub_r001810_1_2 <= 100));
  __CPROVER_assume((pub_r001810_2_1 >= (-100)) && (pub_r001810_2_1 <= 100));
  __CPROVER_assume((pub_r001810_2_2 >= (-100)) && (pub_r001810_2_2 <= 100));
  __CPROVER_assume((pub_r001810_3_1 >= (-100)) && (pub_r001810_3_1 <= 100));
  __CPROVER_assume((pub_r001810_3_2 >= (-100)) && (pub_r001810_3_2 <= 100));
  __CPROVER_assume((pub_r001810_4_1 >= (-100)) && (pub_r001810_4_1 <= 100));
  __CPROVER_assume((pub_r001810_4_2 >= (-100)) && (pub_r001810_4_2 <= 100));
  __CPROVER_assume((pub_r001810_5_1 >= (-100)) && (pub_r001810_5_1 <= 100));
  __CPROVER_assume((pub_r001810_5_2 >= (-100)) && (pub_r001810_5_2 <= 100));
  __CPROVER_assume((pub_r001810_6_1 >= (-100)) && (pub_r001810_6_1 <= 100));
  __CPROVER_assume((pub_r001810_6_2 >= (-100)) && (pub_r001810_6_2 <= 100));
  __CPROVER_assume((pub_r001810_7_1 >= (-100)) && (pub_r001810_7_1 <= 100));
  __CPROVER_assume((pub_r001810_7_2 >= (-100)) && (pub_r001810_7_2 <= 100));
  __CPROVER_assume((pub_r001810_8_1 >= (-100)) && (pub_r001810_8_1 <= 100));
  __CPROVER_assume((pub_r001810_8_2 >= (-100)) && (pub_r001810_8_2 <= 100));
  __CPROVER_assume((pub_r001810_9_1 >= (-100)) && (pub_r001810_9_1 <= 100));
  __CPROVER_assume((pub_r001810_9_2 >= (-100)) && (pub_r001810_9_2 <= 100));
  __CPROVER_assume((pub_r001810_10_1 >= (-100)) && (pub_r001810_10_1 <= 100));
  __CPROVER_assume((pub_r001810_10_2 >= (-100)) && (pub_r001810_10_2 <= 100));
  __CPROVER_assume((pub_r001810_11_1 >= (-100)) && (pub_r001810_11_1 <= 100));
  __CPROVER_assume((pub_r001810_11_2 >= (-100)) && (pub_r001810_11_2 <= 100));
  __CPROVER_assume((pub_r001810_12_1 >= (-100)) && (pub_r001810_12_1 <= 100));
  __CPROVER_assume((pub_r001810_12_2 >= (-100)) && (pub_r001810_12_2 <= 100));
  __CPROVER_assume((pub_r001810_13_1 >= (-100)) && (pub_r001810_13_1 <= 100));
  __CPROVER_assume((pub_r001810_13_2 >= (-100)) && (pub_r001810_13_2 <= 100));
  __CPROVER_assume((pub_r001810_14_1 >= (-100)) && (pub_r001810_14_1 <= 100));
  __CPROVER_assume((pub_r001810_14_2 >= (-100)) && (pub_r001810_14_2 <= 100));
  __CPROVER_assume((pub_r001810_15_1 >= (-100)) && (pub_r001810_15_1 <= 100));
  __CPROVER_assume((pub_r001810_15_2 >= (-100)) && (pub_r001810_15_2 <= 100));
  __CPROVER_assume((pub_r001810_16_1 >= (-100)) && (pub_r001810_16_1 <= 100));
  __CPROVER_assume((pub_r001810_16_2 >= (-100)) && (pub_r001810_16_2 <= 100));
  __CPROVER_assume((sec_r001810_0_1 >= 0) && (sec_r001810_0_1 <= 255));
  __CPROVER_assume((sec_r001810_0_2 >= 0) && (sec_r001810_0_2 <= 255));
  __CPROVER_assume((sec_r001810_1_1 >= 0) && (sec_r001810_1_1 <= 255));
  __CPROVER_assume((sec_r001810_1_2 >= 0) && (sec_r001810_1_2 <= 255));
  __CPROVER_assume((sec_r001810_2_1 >= 0) && (sec_r001810_2_1 <= 255));
  __CPROVER_assume((sec_r001810_2_2 >= 0) && (sec_r001810_2_2 <= 255));
  __CPROVER_assume((sec_r001810_3_1 >= 0) && (sec_r001810_3_1 <= 255));
  __CPROVER_assume((sec_r001810_3_2 >= 0) && (sec_r001810_3_2 <= 255));
  __CPROVER_assume((sec_r001810_4_1 >= 0) && (sec_r001810_4_1 <= 255));
  __CPROVER_assume((sec_r001810_4_2 >= 0) && (sec_r001810_4_2 <= 255));
  __CPROVER_assume((sec_r001810_5_1 >= 0) && (sec_r001810_5_1 <= 255));
  __CPROVER_assume((sec_r001810_5_2 >= 0) && (sec_r001810_5_2 <= 255));
  __CPROVER_assume((sec_r001810_6_1 >= 0) && (sec_r001810_6_1 <= 255));
  __CPROVER_assume((sec_r001810_6_2 >= 0) && (sec_r001810_6_2 <= 255));
  __CPROVER_assume((sec_r001810_7_1 >= 0) && (sec_r001810_7_1 <= 255));
  __CPROVER_assume((sec_r001810_7_2 >= 0) && (sec_r001810_7_2 <= 255));
  __CPROVER_assume((sec_r001810_8_1 >= 0) && (sec_r001810_8_1 <= 255));
  __CPROVER_assume((sec_r001810_8_2 >= 0) && (sec_r001810_8_2 <= 255));
  __CPROVER_assume((sec_r001810_9_1 >= 0) && (sec_r001810_9_1 <= 255));
  __CPROVER_assume((sec_r001810_9_2 >= 0) && (sec_r001810_9_2 <= 255));
  __CPROVER_assume((sec_r001810_10_1 >= 0) && (sec_r001810_10_1 <= 255));
  __CPROVER_assume((sec_r001810_10_2 >= 0) && (sec_r001810_10_2 <= 255));
  __CPROVER_assume((sec_r001810_11_1 >= 0) && (sec_r001810_11_1 <= 255));
  __CPROVER_assume((sec_r001810_11_2 >= 0) && (sec_r001810_11_2 <= 255));
  __CPROVER_assume((sec_r001810_12_1 >= 0) && (sec_r001810_12_1 <= 255));
  __CPROVER_assume((sec_r001810_12_2 >= 0) && (sec_r001810_12_2 <= 255));
  __CPROVER_assume((sec_r001810_13_1 >= 0) && (sec_r001810_13_1 <= 255));
  __CPROVER_assume((sec_r001810_13_2 >= 0) && (sec_r001810_13_2 <= 255));
  __CPROVER_assume((sec_r001810_14_1 >= 0) && (sec_r001810_14_1 <= 255));
  __CPROVER_assume((sec_r001810_14_2 >= 0) && (sec_r001810_14_2 <= 255));
  __CPROVER_assume((sec_r001810_15_1 >= 0) && (sec_r001810_15_1 <= 255));
  __CPROVER_assume((sec_r001810_15_2 >= 0) && (sec_r001810_15_2 <= 255));
  __CPROVER_assume((sec_r001810_16_1 >= 0) && (sec_r001810_16_1 <= 255));
  __CPROVER_assume((sec_r001810_16_2 >= 0) && (sec_r001810_16_2 <= 255));
  struct DeviceConfig_R001810_1013_0 st_var_0_1 = {0};
  struct DeviceConfig_R001810_1013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001810_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001810_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001810_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001810_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001810_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001810_0_2 + 7) & 15;
  struct SensorNode_R001810_1013_1 st_var_1_1 = {0};
  struct SensorNode_R001810_1013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001810_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001810_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001810_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001810_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001810_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001810_0_2 + 9) & 15;
  union TelemetryField_R001810_1013_0 u_var_1;
  union TelemetryField_R001810_1013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001810_1013_0(sec_r001810_0_1, pub_r001810_1_1);
  int helper_flow_0_2 = fn_R001810_1013_0(sec_r001810_0_2, pub_r001810_1_2);
  fn_R001810_1013_0_2(sec_r001810_0_1, pub_r001810_1_1, sec_r001810_0_2, pub_r001810_1_2);
  int helper_flow_1_1 = fn_R001810_1013_1(sec_r001810_1_1, pub_r001810_2_1);
  int helper_flow_1_2 = fn_R001810_1013_1(sec_r001810_1_2, pub_r001810_2_2);
  fn_R001810_1013_1_2(sec_r001810_1_1, pub_r001810_2_1, sec_r001810_1_2, pub_r001810_2_2);
  int helper_flow_2_1 = fn_R001810_1013_2(sec_r001810_2_1, pub_r001810_3_1, pub_r001810_4_1);
  int helper_flow_2_2 = fn_R001810_1013_2(sec_r001810_2_2, pub_r001810_3_2, pub_r001810_4_2);
  fn_R001810_1013_2_2(sec_r001810_2_1, pub_r001810_3_1, pub_r001810_4_1, sec_r001810_2_2, pub_r001810_3_2, pub_r001810_4_2);
  int helper_flow_3_1 = fn_R001810_1013_3(sec_r001810_3_1, pub_r001810_4_1, pub_r001810_5_1, pub_r001810_6_1);
  int helper_flow_3_2 = fn_R001810_1013_3(sec_r001810_3_2, pub_r001810_4_2, pub_r001810_5_2, pub_r001810_6_2);
  fn_R001810_1013_3_2(sec_r001810_3_1, pub_r001810_4_1, pub_r001810_5_1, pub_r001810_6_1, sec_r001810_3_2, pub_r001810_4_2, pub_r001810_5_2, pub_r001810_6_2);
  int helper_flow_4_1 = fn_R001810_1013_4(sec_r001810_4_1, sec_r001810_5_1, pub_r001810_6_1);
  int helper_flow_4_2 = fn_R001810_1013_4(sec_r001810_4_2, sec_r001810_5_2, pub_r001810_6_2);
  fn_R001810_1013_4_2(sec_r001810_4_1, sec_r001810_5_1, pub_r001810_6_1, sec_r001810_4_2, sec_r001810_5_2, pub_r001810_6_2);
  int helper_flow_5_1 = fn_R001810_1013_5(sec_r001810_5_1, pub_r001810_6_1, pub_r001810_7_1, pub_r001810_8_1);
  int helper_flow_5_2 = fn_R001810_1013_5(sec_r001810_5_2, pub_r001810_6_2, pub_r001810_7_2, pub_r001810_8_2);
  fn_R001810_1013_5_2(sec_r001810_5_1, pub_r001810_6_1, pub_r001810_7_1, pub_r001810_8_1, sec_r001810_5_2, pub_r001810_6_2, pub_r001810_7_2, pub_r001810_8_2);
  int helper_flow_6_1 = fn_R001810_1013_6(sec_r001810_6_1, sec_r001810_7_1, pub_r001810_8_1);
  int helper_flow_6_2 = fn_R001810_1013_6(sec_r001810_6_2, sec_r001810_7_2, pub_r001810_8_2);
  fn_R001810_1013_6_2(sec_r001810_6_1, sec_r001810_7_1, pub_r001810_8_1, sec_r001810_6_2, sec_r001810_7_2, pub_r001810_8_2);
  int helper_flow_7_1 = fn_R001810_1013_7(sec_r001810_7_1, sec_r001810_8_1);
  int helper_flow_7_2 = fn_R001810_1013_7(sec_r001810_7_2, sec_r001810_8_2);
  fn_R001810_1013_7_2(sec_r001810_7_1, sec_r001810_8_1, sec_r001810_7_2, sec_r001810_8_2);
  int helper_flow_8_1 = fn_R001810_1013_8(sec_r001810_8_1, pub_r001810_9_1, pub_r001810_10_1, pub_r001810_11_1, pub_r001810_12_1);
  int helper_flow_8_2 = fn_R001810_1013_8(sec_r001810_8_2, pub_r001810_9_2, pub_r001810_10_2, pub_r001810_11_2, pub_r001810_12_2);
  fn_R001810_1013_8_2(sec_r001810_8_1, pub_r001810_9_1, pub_r001810_10_1, pub_r001810_11_1, pub_r001810_12_1, sec_r001810_8_2, pub_r001810_9_2, pub_r001810_10_2, pub_r001810_11_2, pub_r001810_12_2);
  int helper_flow_9_1 = fn_R001810_1013_9(sec_r001810_9_1, sec_r001810_10_1, pub_r001810_11_1, pub_r001810_12_1, pub_r001810_13_1);
  int helper_flow_9_2 = fn_R001810_1013_9(sec_r001810_9_2, sec_r001810_10_2, pub_r001810_11_2, pub_r001810_12_2, pub_r001810_13_2);
  fn_R001810_1013_9_2(sec_r001810_9_1, sec_r001810_10_1, pub_r001810_11_1, pub_r001810_12_1, pub_r001810_13_1, sec_r001810_9_2, sec_r001810_10_2, pub_r001810_11_2, pub_r001810_12_2, pub_r001810_13_2);
  int helper_flow_10_1 = fn_R001810_1013_10(sec_r001810_10_1, sec_r001810_11_1, pub_r001810_12_1, pub_r001810_13_1, pub_r001810_14_1);
  int helper_flow_10_2 = fn_R001810_1013_10(sec_r001810_10_2, sec_r001810_11_2, pub_r001810_12_2, pub_r001810_13_2, pub_r001810_14_2);
  fn_R001810_1013_10_2(sec_r001810_10_1, sec_r001810_11_1, pub_r001810_12_1, pub_r001810_13_1, pub_r001810_14_1, sec_r001810_10_2, sec_r001810_11_2, pub_r001810_12_2, pub_r001810_13_2, pub_r001810_14_2);
  int helper_flow_11_1 = fn_R001810_1013_11(sec_r001810_11_1, pub_r001810_12_1, pub_r001810_13_1, pub_r001810_14_1, pub_r001810_15_1);
  int helper_flow_11_2 = fn_R001810_1013_11(sec_r001810_11_2, pub_r001810_12_2, pub_r001810_13_2, pub_r001810_14_2, pub_r001810_15_2);
  fn_R001810_1013_11_2(sec_r001810_11_1, pub_r001810_12_1, pub_r001810_13_1, pub_r001810_14_1, pub_r001810_15_1, sec_r001810_11_2, pub_r001810_12_2, pub_r001810_13_2, pub_r001810_14_2, pub_r001810_15_2);
  int helper_flow_12_1 = fn_R001810_1013_12(sec_r001810_12_1, sec_r001810_13_1, pub_r001810_14_1, pub_r001810_15_1, pub_r001810_16_1);
  int helper_flow_12_2 = fn_R001810_1013_12(sec_r001810_12_2, sec_r001810_13_2, pub_r001810_14_2, pub_r001810_15_2, pub_r001810_16_2);
  fn_R001810_1013_12_2(sec_r001810_12_1, sec_r001810_13_1, pub_r001810_14_1, pub_r001810_15_1, pub_r001810_16_1, sec_r001810_12_2, sec_r001810_13_2, pub_r001810_14_2, pub_r001810_15_2, pub_r001810_16_2);
  int stage_v_0_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001810_0_1) & 127;
  int stage_v_0_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001810_0_2) & 127;
  if (stage_v_0_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001810_2_1) & 127;
  int stage_v_1_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001810_2_2) & 127;
  if (stage_v_1_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (((sec_r001810_11_1 ^ 0x2A) * 2) + pub_r001810_4_1) & 127;
  int stage_v_2_2 = (((sec_r001810_11_2 ^ 0x2A) * 2) + pub_r001810_4_2) & 127;
  if (stage_v_2_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((sec_r001810_11_1 ^ 0x2A) * 2) + pub_r001810_6_1) & 127;
  int stage_v_3_2 = (((sec_r001810_11_2 ^ 0x2A) * 2) + pub_r001810_6_2) & 127;
  if (stage_v_3_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((pub_r001810_9_1 * 2) + 18) & 63;
  int stage_v_4_2 = ((pub_r001810_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001810_16_1 * 2) + 44) & 63;
  int stage_v_5_2 = ((pub_r001810_16_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001810_6_1) & 127;
  int stage_v_6_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001810_6_2) & 127;
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
  int stage_v_7_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001810_14_1) & 127;
  int stage_v_7_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001810_14_2) & 127;
  if (stage_v_7_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((sec_r001810_15_1 ^ 0x2A) * 2) + pub_r001810_1_1) & 127;
  int stage_v_8_2 = (((sec_r001810_15_2 ^ 0x2A) * 2) + pub_r001810_1_2) & 127;
  if (stage_v_8_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = ((pub_r001810_10_1 * 2) + 10) & 63;
  int stage_v_9_2 = ((pub_r001810_10_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((sec_r001810_12_1 ^ 0x2A) * 2) + pub_r001810_9_1) & 127;
  int stage_v_10_2 = (((sec_r001810_12_2 ^ 0x2A) * 2) + pub_r001810_9_2) & 127;
  if (stage_v_10_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = ((pub_r001810_9_1 * 2) + 31) & 63;
  int stage_v_11_2 = ((pub_r001810_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001810_11_1) & 127;
  int stage_v_12_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001810_11_2) & 127;
  if (stage_v_12_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001810_13_1) & 127;
  int stage_v_13_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001810_13_2) & 127;
  if (stage_v_13_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001810_8_1) & 127;
  int stage_v_14_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001810_8_2) & 127;
  if (stage_v_14_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((pub_r001810_1_1 * 2) + 18) & 63;
  int stage_v_15_2 = ((pub_r001810_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001810_1_1) & 127;
  int stage_v_16_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001810_1_2) & 127;
  if (stage_v_16_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((sec_r001810_12_1 ^ 0x2A) * 2) + pub_r001810_0_1) & 127;
  int stage_v_17_2 = (((sec_r001810_12_2 ^ 0x2A) * 2) + pub_r001810_0_2) & 127;
  if (stage_v_17_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (((sec_r001810_8_1 ^ 0x2A) * 2) + pub_r001810_6_1) & 127;
  int stage_v_18_2 = (((sec_r001810_8_2 ^ 0x2A) * 2) + pub_r001810_6_2) & 127;
  if (stage_v_18_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001810_4_1) & 127;
  int stage_v_19_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001810_4_2) & 127;
  if (stage_v_19_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((sec_r001810_2_1 ^ 0x2A) * 2) + pub_r001810_14_1) & 127;
  int stage_v_20_2 = (((sec_r001810_2_2 ^ 0x2A) * 2) + pub_r001810_14_2) & 127;
  if (stage_v_20_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((sec_r001810_12_1 ^ 0x2A) * 2) + pub_r001810_10_1) & 127;
  int stage_v_21_2 = (((sec_r001810_12_2 ^ 0x2A) * 2) + pub_r001810_10_2) & 127;
  if (stage_v_21_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = ((pub_r001810_1_1 * 2) + 27) & 63;
  int stage_v_22_2 = ((pub_r001810_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001810_13_1 * 2) + 48) & 63;
  int stage_v_23_2 = ((pub_r001810_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (((sec_r001810_16_1 ^ 0x2A) * 2) + pub_r001810_2_1) & 127;
  int stage_v_24_2 = (((sec_r001810_16_2 ^ 0x2A) * 2) + pub_r001810_2_2) & 127;
  if (stage_v_24_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (((helper_flow_12_1 ^ 0x2A) * 2) + pub_r001810_12_1) & 127;
  int stage_v_25_2 = (((helper_flow_12_2 ^ 0x2A) * 2) + pub_r001810_12_2) & 127;
  if (stage_v_25_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001810_1_1) & 127;
  int stage_v_26_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001810_1_2) & 127;
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
  int stage_v_27_1 = (((sec_r001810_12_1 ^ 0x2A) * 2) + pub_r001810_13_1) & 127;
  int stage_v_27_2 = (((sec_r001810_12_2 ^ 0x2A) * 2) + pub_r001810_13_2) & 127;
  if (stage_v_27_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001810_14_1) & 127;
  int stage_v_28_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001810_14_2) & 127;
  if (stage_v_28_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = ((pub_r001810_15_1 * 2) + 42) & 63;
  int stage_v_29_2 = ((pub_r001810_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001810_6_1) & 127;
  int stage_v_30_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001810_6_2) & 127;
  if (stage_v_30_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((pub_r001810_8_1 * 2) + 22) & 63;
  int stage_v_31_2 = ((pub_r001810_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001810_3_1) & 127;
  int stage_v_32_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001810_3_2) & 127;
  if (stage_v_32_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001810_6_1) & 127;
  int stage_v_33_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001810_6_2) & 127;
  if (stage_v_33_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (((sec_r001810_11_1 ^ 0x2A) * 2) + pub_r001810_12_1) & 127;
  int stage_v_34_2 = (((sec_r001810_11_2 ^ 0x2A) * 2) + pub_r001810_12_2) & 127;
  if (stage_v_34_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001810_3_1) & 127;
  int stage_v_35_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001810_3_2) & 127;
  if (stage_v_35_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001810_12_1) & 127;
  int stage_v_36_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001810_12_2) & 127;
  if (stage_v_36_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((sec_r001810_7_1 ^ 0x2A) * 2) + pub_r001810_8_1) & 127;
  int stage_v_37_2 = (((sec_r001810_7_2 ^ 0x2A) * 2) + pub_r001810_8_2) & 127;
  if (stage_v_37_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (((sec_r001810_13_1 ^ 0x2A) * 2) + pub_r001810_0_1) & 127;
  int stage_v_38_2 = (((sec_r001810_13_2 ^ 0x2A) * 2) + pub_r001810_0_2) & 127;
  if (stage_v_38_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001810_8_1) & 127;
  int stage_v_39_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001810_8_2) & 127;
  if (stage_v_39_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((pub_r001810_6_1 * 2) + 43) & 63;
  int stage_v_40_2 = ((pub_r001810_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001810_7_1 * 2) + 41) & 63;
  int stage_v_41_2 = ((pub_r001810_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001810_2_1 * 2) + 36) & 63;
  int stage_v_42_2 = ((pub_r001810_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001810_4_1) & 127;
  int stage_v_43_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001810_4_2) & 127;
  if (stage_v_43_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001810_3_1) & 127;
  int stage_v_44_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001810_3_2) & 127;
  if (stage_v_44_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001810_10_1) & 127;
  int stage_v_45_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001810_10_2) & 127;
  if (stage_v_45_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (((sec_r001810_6_1 ^ 0x2A) * 2) + pub_r001810_7_1) & 127;
  int stage_v_46_2 = (((sec_r001810_6_2 ^ 0x2A) * 2) + pub_r001810_7_2) & 127;
  if (stage_v_46_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (((sec_r001810_5_1 ^ 0x2A) * 2) + pub_r001810_2_1) & 127;
  int stage_v_47_2 = (((sec_r001810_5_2 ^ 0x2A) * 2) + pub_r001810_2_2) & 127;
  if (stage_v_47_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((pub_r001810_2_1 * 2) + 32) & 63;
  int stage_v_48_2 = ((pub_r001810_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001810_14_1 * 2) + 46) & 63;
  int stage_v_49_2 = ((pub_r001810_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001810_3_1 * 2) + 33) & 63;
  int stage_v_50_2 = ((pub_r001810_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (((sec_r001810_5_1 ^ 0x2A) * 2) + pub_r001810_9_1) & 127;
  int stage_v_51_2 = (((sec_r001810_5_2 ^ 0x2A) * 2) + pub_r001810_9_2) & 127;
  if (stage_v_51_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((pub_r001810_3_1 * 2) + 34) & 63;
  int stage_v_52_2 = ((pub_r001810_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001810_1_1) & 127;
  int stage_v_53_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001810_1_2) & 127;
  if (stage_v_53_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001810_13_1) & 127;
  int stage_v_54_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001810_13_2) & 127;
  if (stage_v_54_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((pub_r001810_9_1 * 2) + 12) & 63;
  int stage_v_55_2 = ((pub_r001810_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001810_16_1) & 127;
  int stage_v_56_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001810_16_2) & 127;
  if (stage_v_56_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((sec_r001810_0_1 ^ 0x2A) * 2) + pub_r001810_2_1) & 127;
  int stage_v_57_2 = (((sec_r001810_0_2 ^ 0x2A) * 2) + pub_r001810_2_2) & 127;
  if (stage_v_57_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001810_0_1) & 127;
  int stage_v_58_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001810_0_2) & 127;
  if (stage_v_58_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001810_5_1) & 127;
  int stage_v_59_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001810_5_2) & 127;
  if (stage_v_59_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((pub_r001810_12_1 * 2) + 39) & 63;
  int stage_v_60_2 = ((pub_r001810_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001810_4_1) & 127;
  int stage_v_61_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001810_4_2) & 127;
  if (stage_v_61_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001810_13_1) & 127;
  int stage_v_62_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001810_13_2) & 127;
  if (stage_v_62_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((pub_r001810_3_1 * 2) + 40) & 63;
  int stage_v_63_2 = ((pub_r001810_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001810_2_1) & 127;
  int stage_v_64_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001810_2_2) & 127;
  if (stage_v_64_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001810_4_1) & 127;
  int stage_v_65_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001810_4_2) & 127;
  if (stage_v_65_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((pub_r001810_2_1 * 2) + 17) & 63;
  int stage_v_66_2 = ((pub_r001810_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001810_3_1 * 2) + 49) & 63;
  int stage_v_67_2 = ((pub_r001810_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = (((sec_r001810_6_1 ^ 0x2A) * 2) + pub_r001810_16_1) & 127;
  int stage_v_68_2 = (((sec_r001810_6_2 ^ 0x2A) * 2) + pub_r001810_16_2) & 127;
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
  int stage_v_69_1 = ((pub_r001810_12_1 * 2) + 31) & 63;
  int stage_v_69_2 = ((pub_r001810_12_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001810_12_1 * 2) + 48) & 63;
  int stage_v_70_2 = ((pub_r001810_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001810_14_1) & 127;
  int stage_v_71_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001810_14_2) & 127;
  if (stage_v_71_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((pub_r001810_14_1 * 2) + 36) & 63;
  int stage_v_72_2 = ((pub_r001810_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001810_0_1) & 127;
  int stage_v_73_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001810_0_2) & 127;
  if (stage_v_73_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((stage_v_68_1 ^ 0x2A) * 2) + pub_r001810_5_1) & 127;
  int stage_v_74_2 = (((stage_v_68_2 ^ 0x2A) * 2) + pub_r001810_5_2) & 127;
  if (stage_v_74_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001810_4_1) & 127;
  int stage_v_75_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001810_4_2) & 127;
  if (stage_v_75_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001810_8_1) & 127;
  int stage_v_76_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001810_8_2) & 127;
  if (stage_v_76_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001810_9_1) & 127;
  int stage_v_77_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001810_9_2) & 127;
  if (stage_v_77_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001810_14_1) & 127;
  int stage_v_78_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001810_14_2) & 127;
  if (stage_v_78_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001810_0_1) & 127;
  int stage_v_79_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001810_0_2) & 127;
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
  int stage_v_80_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001810_3_1) & 127;
  int stage_v_80_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001810_3_2) & 127;
  if (stage_v_80_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001810_2_1) & 127;
  int stage_v_81_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001810_2_2) & 127;
  if (stage_v_81_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001810_8_1) & 127;
  int stage_v_82_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001810_8_2) & 127;
  if (stage_v_82_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((pub_r001810_10_1 * 2) + 33) & 63;
  int stage_v_83_2 = ((pub_r001810_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((sec_r001810_12_1 ^ 0x2A) * 2) + pub_r001810_10_1) & 127;
  int stage_v_84_2 = (((sec_r001810_12_2 ^ 0x2A) * 2) + pub_r001810_10_2) & 127;
  if (stage_v_84_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001810_16_1) & 127;
  int stage_v_85_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001810_16_2) & 127;
  if (stage_v_85_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((pub_r001810_8_1 * 2) + 5) & 63;
  int stage_v_86_2 = ((pub_r001810_8_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001810_2_1) & 127;
  int stage_v_87_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001810_2_2) & 127;
  if (stage_v_87_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001810_8_1) & 127;
  int stage_v_88_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001810_8_2) & 127;
  if (stage_v_88_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001810_15_1) & 127;
  int stage_v_89_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001810_15_2) & 127;
  if (stage_v_89_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((pub_r001810_6_1 * 2) + 14) & 63;
  int stage_v_90_2 = ((pub_r001810_6_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001810_16_1 * 2) + 47) & 63;
  int stage_v_91_2 = ((pub_r001810_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001810_16_1) & 127;
  int stage_v_92_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001810_16_2) & 127;
  if (stage_v_92_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((sec_r001810_11_1 ^ 0x2A) * 2) + pub_r001810_6_1) & 127;
  int stage_v_93_2 = (((sec_r001810_11_2 ^ 0x2A) * 2) + pub_r001810_6_2) & 127;
  if (stage_v_93_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001810_15_1) & 127;
  int stage_v_94_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001810_15_2) & 127;
  if (stage_v_94_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001810_7_1) & 127;
  int stage_v_95_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001810_7_2) & 127;
  if (stage_v_95_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001810_7_1) & 127;
  int stage_v_96_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001810_7_2) & 127;
  if (stage_v_96_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001810_11_1) & 127;
  int stage_v_97_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001810_11_2) & 127;
  if (stage_v_97_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (((sec_r001810_5_1 ^ 0x2A) * 2) + pub_r001810_10_1) & 127;
  int stage_v_98_2 = (((sec_r001810_5_2 ^ 0x2A) * 2) + pub_r001810_10_2) & 127;
  if (stage_v_98_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((stage_v_97_1 ^ 0x2A) * 2) + pub_r001810_8_1) & 127;
  int stage_v_99_2 = (((stage_v_97_2 ^ 0x2A) * 2) + pub_r001810_8_2) & 127;
  if (stage_v_99_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (((sec_r001810_15_1 ^ 0x2A) * 2) + pub_r001810_12_1) & 127;
  int stage_v_100_2 = (((sec_r001810_15_2 ^ 0x2A) * 2) + pub_r001810_12_2) & 127;
  if (stage_v_100_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = (((sec_r001810_1_1 ^ 0x2A) * 2) + pub_r001810_3_1) & 127;
  int stage_v_101_2 = (((sec_r001810_1_2 ^ 0x2A) * 2) + pub_r001810_3_2) & 127;
  if (stage_v_101_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = (((sec_r001810_10_1 ^ 0x2A) * 2) + pub_r001810_0_1) & 127;
  int stage_v_102_2 = (((sec_r001810_10_2 ^ 0x2A) * 2) + pub_r001810_0_2) & 127;
  if (stage_v_102_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((stage_v_68_1 ^ 0x2A) * 2) + pub_r001810_4_1) & 127;
  int stage_v_103_2 = (((stage_v_68_2 ^ 0x2A) * 2) + pub_r001810_4_2) & 127;
  if (stage_v_103_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((sec_r001810_5_1 ^ 0x2A) * 2) + pub_r001810_13_1) & 127;
  int stage_v_104_2 = (((sec_r001810_5_2 ^ 0x2A) * 2) + pub_r001810_13_2) & 127;
  if (stage_v_104_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001810_11_1) & 127;
  int stage_v_105_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001810_11_2) & 127;
  if (stage_v_105_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((pub_r001810_5_1 * 2) + 38) & 63;
  int stage_v_106_2 = ((pub_r001810_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001810_0_1) & 127;
  int stage_v_107_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001810_0_2) & 127;
  if (stage_v_107_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001810_2_1) & 127;
  int stage_v_108_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001810_2_2) & 127;
  if (stage_v_108_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001810_1_1) & 127;
  int stage_v_109_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001810_1_2) & 127;
  if (stage_v_109_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001810_6_1) & 127;
  int stage_v_110_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001810_6_2) & 127;
  if (stage_v_110_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001810_11_1) & 127;
  int stage_v_111_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001810_11_2) & 127;
  if (stage_v_111_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001810_10_1) & 127;
  int stage_v_112_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001810_10_2) & 127;
  if (stage_v_112_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((pub_r001810_7_1 * 2) + 17) & 63;
  int stage_v_113_2 = ((pub_r001810_7_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001810_14_1) & 127;
  int stage_v_114_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001810_14_2) & 127;
  if (stage_v_114_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = (((stage_v_111_1 ^ 0x2A) * 2) + pub_r001810_2_1) & 127;
  int stage_v_115_2 = (((stage_v_111_2 ^ 0x2A) * 2) + pub_r001810_2_2) & 127;
  if (stage_v_115_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (((stage_v_105_1 ^ 0x2A) * 2) + pub_r001810_14_1) & 127;
  int stage_v_116_2 = (((stage_v_105_2 ^ 0x2A) * 2) + pub_r001810_14_2) & 127;
  if (stage_v_116_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001810_12_1) & 127;
  int stage_v_117_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001810_12_2) & 127;
  if (stage_v_117_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001810_9_1) & 127;
  int stage_v_118_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001810_9_2) & 127;
  if (stage_v_118_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((pub_r001810_7_1 * 2) + 21) & 63;
  int stage_v_119_2 = ((pub_r001810_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001810_14_1) & 127;
  int stage_v_120_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001810_14_2) & 127;
  if (stage_v_120_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((pub_r001810_3_1 * 2) + 14) & 63;
  int stage_v_121_2 = ((pub_r001810_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001810_13_1) & 127;
  int stage_v_122_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001810_13_2) & 127;
  if (stage_v_122_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001810_1_1) & 127;
  int stage_v_123_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001810_1_2) & 127;
  if (stage_v_123_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((pub_r001810_2_1 * 2) + 22) & 63;
  int stage_v_124_2 = ((pub_r001810_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = (((sec_r001810_16_1 ^ 0x2A) * 2) + pub_r001810_13_1) & 127;
  int stage_v_125_2 = (((sec_r001810_16_2 ^ 0x2A) * 2) + pub_r001810_13_2) & 127;
  if (stage_v_125_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((pub_r001810_16_1 * 2) + 17) & 63;
  int stage_v_126_2 = ((pub_r001810_16_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001810_13_1) & 127;
  int stage_v_127_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001810_13_2) & 127;
  if (stage_v_127_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001810_3_1) & 127;
  int stage_v_128_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001810_3_2) & 127;
  if (stage_v_128_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001810_2_1) & 127;
  int stage_v_129_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001810_2_2) & 127;
  if (stage_v_129_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((stage_v_97_1 ^ 0x2A) * 2) + pub_r001810_3_1) & 127;
  int stage_v_130_2 = (((stage_v_97_2 ^ 0x2A) * 2) + pub_r001810_3_2) & 127;
  if (stage_v_130_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001810_8_1) & 127;
  int stage_v_131_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001810_8_2) & 127;
  if (stage_v_131_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001810_1_1) & 127;
  int stage_v_132_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001810_1_2) & 127;
  if (stage_v_132_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((pub_r001810_10_1 * 2) + 43) & 63;
  int stage_v_133_2 = ((pub_r001810_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001810_15_1) & 127;
  int stage_v_134_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001810_15_2) & 127;
  if (stage_v_134_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001810_7_1) & 127;
  int stage_v_135_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001810_7_2) & 127;
  if (stage_v_135_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001810_6_1) & 127;
  int stage_v_136_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001810_6_2) & 127;
  if (stage_v_136_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((pub_r001810_6_1 * 2) + 40) & 63;
  int stage_v_137_2 = ((pub_r001810_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((stage_v_129_1 ^ 0x2A) * 2) + pub_r001810_5_1) & 127;
  int stage_v_138_2 = (((stage_v_129_2 ^ 0x2A) * 2) + pub_r001810_5_2) & 127;
  if (stage_v_138_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001810_12_1) & 127;
  int stage_v_139_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001810_12_2) & 127;
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
  int stage_v_140_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001810_9_1) & 127;
  int stage_v_140_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001810_9_2) & 127;
  if (stage_v_140_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((sec_r001810_10_1 ^ 0x2A) * 2) + pub_r001810_3_1) & 127;
  int stage_v_141_2 = (((sec_r001810_10_2 ^ 0x2A) * 2) + pub_r001810_3_2) & 127;
  if (stage_v_141_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (((sec_r001810_13_1 ^ 0x2A) * 2) + pub_r001810_9_1) & 127;
  int stage_v_142_2 = (((sec_r001810_13_2 ^ 0x2A) * 2) + pub_r001810_9_2) & 127;
  if (stage_v_142_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001810_11_1) & 127;
  int stage_v_143_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001810_11_2) & 127;
  if (stage_v_143_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001810_4_1) & 127;
  int stage_v_144_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001810_4_2) & 127;
  if (stage_v_144_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001810_8_1) & 127;
  int stage_v_145_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001810_8_2) & 127;
  if (stage_v_145_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001810_2_1) & 127;
  int stage_v_146_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001810_2_2) & 127;
  if (stage_v_146_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = (((stage_v_109_1 ^ 0x2A) * 2) + pub_r001810_15_1) & 127;
  int stage_v_147_2 = (((stage_v_109_2 ^ 0x2A) * 2) + pub_r001810_15_2) & 127;
  if (stage_v_147_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((pub_r001810_14_1 * 2) + 45) & 63;
  int stage_v_148_2 = ((pub_r001810_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001810_4_1 * 2) + 18) & 63;
  int stage_v_149_2 = ((pub_r001810_4_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001810_3_1) & 127;
  int stage_v_150_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001810_3_2) & 127;
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
  int stage_v_151_1 = (((stage_v_147_1 ^ 0x2A) * 2) + pub_r001810_13_1) & 127;
  int stage_v_151_2 = (((stage_v_147_2 ^ 0x2A) * 2) + pub_r001810_13_2) & 127;
  if (stage_v_151_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((pub_r001810_6_1 * 2) + 35) & 63;
  int stage_v_152_2 = ((pub_r001810_6_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001810_3_1 * 2) + 8) & 63;
  int stage_v_153_2 = ((pub_r001810_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((stage_v_120_1 ^ 0x2A) * 2) + pub_r001810_14_1) & 127;
  int stage_v_154_2 = (((stage_v_120_2 ^ 0x2A) * 2) + pub_r001810_14_2) & 127;
  if (stage_v_154_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001810_12_1) & 127;
  int stage_v_155_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001810_12_2) & 127;
  if (stage_v_155_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((stage_v_117_1 ^ 0x2A) * 2) + pub_r001810_11_1) & 127;
  int stage_v_156_2 = (((stage_v_117_2 ^ 0x2A) * 2) + pub_r001810_11_2) & 127;
  if (stage_v_156_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001810_4_1) & 127;
  int stage_v_157_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001810_4_2) & 127;
  if (stage_v_157_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001810_6_1) & 127;
  int stage_v_158_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001810_6_2) & 127;
  if (stage_v_158_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001810_16_1) & 127;
  int stage_v_159_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001810_16_2) & 127;
  if (stage_v_159_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = (((stage_v_145_1 ^ 0x2A) * 2) + pub_r001810_7_1) & 127;
  int stage_v_160_2 = (((stage_v_145_2 ^ 0x2A) * 2) + pub_r001810_7_2) & 127;
  if (stage_v_160_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001810_11_1) & 127;
  int stage_v_161_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001810_11_2) & 127;
  if (stage_v_161_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (((stage_v_142_1 ^ 0x2A) * 2) + pub_r001810_2_1) & 127;
  int stage_v_162_2 = (((stage_v_142_2 ^ 0x2A) * 2) + pub_r001810_2_2) & 127;
  if (stage_v_162_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001810_13_1) & 127;
  int stage_v_163_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001810_13_2) & 127;
  if (stage_v_163_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = (((stage_v_117_1 ^ 0x2A) * 2) + pub_r001810_9_1) & 127;
  int stage_v_164_2 = (((stage_v_117_2 ^ 0x2A) * 2) + pub_r001810_9_2) & 127;
  if (stage_v_164_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (((stage_v_123_1 ^ 0x2A) * 2) + pub_r001810_0_1) & 127;
  int stage_v_165_2 = (((stage_v_123_2 ^ 0x2A) * 2) + pub_r001810_0_2) & 127;
  if (stage_v_165_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001810_15_1) & 127;
  int stage_v_166_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001810_15_2) & 127;
  if (stage_v_166_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((stage_v_112_1 ^ 0x2A) * 2) + pub_r001810_14_1) & 127;
  int stage_v_167_2 = (((stage_v_112_2 ^ 0x2A) * 2) + pub_r001810_14_2) & 127;
  if (stage_v_167_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((stage_v_154_1 ^ 0x2A) * 2) + pub_r001810_12_1) & 127;
  int stage_v_168_2 = (((stage_v_154_2 ^ 0x2A) * 2) + pub_r001810_12_2) & 127;
  if (stage_v_168_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001810_13_1) & 127;
  int stage_v_169_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001810_13_2) & 127;
  if (stage_v_169_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((stage_v_76_1 ^ 0x2A) * 2) + pub_r001810_0_1) & 127;
  int stage_v_170_2 = (((stage_v_76_2 ^ 0x2A) * 2) + pub_r001810_0_2) & 127;
  if (stage_v_170_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (((stage_v_88_1 ^ 0x2A) * 2) + pub_r001810_6_1) & 127;
  int stage_v_171_2 = (((stage_v_88_2 ^ 0x2A) * 2) + pub_r001810_6_2) & 127;
  if (stage_v_171_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = (((sec_r001810_0_1 ^ 0x2A) * 2) + pub_r001810_15_1) & 127;
  int stage_v_172_2 = (((sec_r001810_0_2 ^ 0x2A) * 2) + pub_r001810_15_2) & 127;
  if (stage_v_172_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (((stage_v_160_1 ^ 0x2A) * 2) + pub_r001810_15_1) & 127;
  int stage_v_173_2 = (((stage_v_160_2 ^ 0x2A) * 2) + pub_r001810_15_2) & 127;
  if (stage_v_173_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((pub_r001810_1_1 * 2) + 22) & 63;
  int stage_v_174_2 = ((pub_r001810_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001810_2_1) & 127;
  int stage_v_175_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001810_2_2) & 127;
  if (stage_v_175_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = (((stage_v_132_1 ^ 0x2A) * 2) + pub_r001810_7_1) & 127;
  int stage_v_176_2 = (((stage_v_132_2 ^ 0x2A) * 2) + pub_r001810_7_2) & 127;
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
  int stage_v_177_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001810_6_1) & 127;
  int stage_v_177_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001810_6_2) & 127;
  if (stage_v_177_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001810_11_1) & 127;
  int stage_v_178_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001810_11_2) & 127;
  if (stage_v_178_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((pub_r001810_4_1 * 2) + 45) & 63;
  int stage_v_179_2 = ((pub_r001810_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001810_6_1 * 2) + 33) & 63;
  int stage_v_180_2 = ((pub_r001810_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001810_2_1 * 2) + 6) & 63;
  int stage_v_181_2 = ((pub_r001810_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001810_15_1) & 127;
  int stage_v_182_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001810_15_2) & 127;
  if (stage_v_182_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((pub_r001810_6_1 * 2) + 45) & 63;
  int stage_v_183_2 = ((pub_r001810_6_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001810_3_1 * 2) + 6) & 63;
  int stage_v_184_2 = ((pub_r001810_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((stage_v_120_1 ^ 0x2A) * 2) + pub_r001810_13_1) & 127;
  int stage_v_185_2 = (((stage_v_120_2 ^ 0x2A) * 2) + pub_r001810_13_2) & 127;
  if (stage_v_185_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = (((stage_v_175_1 ^ 0x2A) * 2) + pub_r001810_12_1) & 127;
  int stage_v_186_2 = (((stage_v_175_2 ^ 0x2A) * 2) + pub_r001810_12_2) & 127;
  if (stage_v_186_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((pub_r001810_1_1 * 2) + 28) & 63;
  int stage_v_187_2 = ((pub_r001810_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001810_3_1) & 127;
  int stage_v_188_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001810_3_2) & 127;
  if (stage_v_188_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = (((stage_v_162_1 ^ 0x2A) * 2) + pub_r001810_4_1) & 127;
  int stage_v_189_2 = (((stage_v_162_2 ^ 0x2A) * 2) + pub_r001810_4_2) & 127;
  if (stage_v_189_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001810_8_1) & 127;
  int stage_v_190_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001810_8_2) & 127;
  if (stage_v_190_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = (((stage_v_188_1 ^ 0x2A) * 2) + pub_r001810_2_1) & 127;
  int stage_v_191_2 = (((stage_v_188_2 ^ 0x2A) * 2) + pub_r001810_2_2) & 127;
  if (stage_v_191_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((sec_r001810_16_1 ^ 0x2A) * 2) + pub_r001810_2_1) & 127;
  int stage_v_192_2 = (((sec_r001810_16_2 ^ 0x2A) * 2) + pub_r001810_2_2) & 127;
  if (stage_v_192_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001810_6_1) & 127;
  int stage_v_193_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001810_6_2) & 127;
  if (stage_v_193_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((stage_v_164_1 ^ 0x2A) * 2) + pub_r001810_1_1) & 127;
  int stage_v_194_2 = (((stage_v_164_2 ^ 0x2A) * 2) + pub_r001810_1_2) & 127;
  if (stage_v_194_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = (((stage_v_177_1 ^ 0x2A) * 2) + pub_r001810_1_1) & 127;
  int stage_v_195_2 = (((stage_v_177_2 ^ 0x2A) * 2) + pub_r001810_1_2) & 127;
  if (stage_v_195_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001810_6_1) & 127;
  int stage_v_196_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001810_6_2) & 127;
  if (stage_v_196_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = (((stage_v_105_1 ^ 0x2A) * 2) + pub_r001810_0_1) & 127;
  int stage_v_197_2 = (((stage_v_105_2 ^ 0x2A) * 2) + pub_r001810_0_2) & 127;
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
  int stage_v_198_1 = (((stage_v_145_1 ^ 0x2A) * 2) + pub_r001810_6_1) & 127;
  int stage_v_198_2 = (((stage_v_145_2 ^ 0x2A) * 2) + pub_r001810_6_2) & 127;
  if (stage_v_198_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((pub_r001810_11_1 * 2) + 20) & 63;
  int stage_v_199_2 = ((pub_r001810_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001810_3_1) & 127;
  int stage_v_200_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001810_3_2) & 127;
  if (stage_v_200_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((pub_r001810_12_1 * 2) + 42) & 63;
  int stage_v_201_2 = ((pub_r001810_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001810_16_1 * 2) + 39) & 63;
  int stage_v_202_2 = ((pub_r001810_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (((stage_v_114_1 ^ 0x2A) * 2) + pub_r001810_11_1) & 127;
  int stage_v_203_2 = (((stage_v_114_2 ^ 0x2A) * 2) + pub_r001810_11_2) & 127;
  if (stage_v_203_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = (((sec_r001810_0_1 ^ 0x2A) * 2) + pub_r001810_9_1) & 127;
  int stage_v_204_2 = (((sec_r001810_0_2 ^ 0x2A) * 2) + pub_r001810_9_2) & 127;
  if (stage_v_204_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((pub_r001810_14_1 * 2) + 42) & 63;
  int stage_v_205_2 = ((pub_r001810_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001810_14_1) & 127;
  int stage_v_206_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001810_14_2) & 127;
  if (stage_v_206_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = (((stage_v_186_1 ^ 0x2A) * 2) + pub_r001810_16_1) & 127;
  int stage_v_207_2 = (((stage_v_186_2 ^ 0x2A) * 2) + pub_r001810_16_2) & 127;
  if (stage_v_207_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001810_8_1) & 127;
  int stage_v_208_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001810_8_2) & 127;
  if (stage_v_208_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = (((stage_v_188_1 ^ 0x2A) * 2) + pub_r001810_5_1) & 127;
  int stage_v_209_2 = (((stage_v_188_2 ^ 0x2A) * 2) + pub_r001810_5_2) & 127;
  if (stage_v_209_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((pub_r001810_7_1 * 2) + 43) & 63;
  int stage_v_210_2 = ((pub_r001810_7_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((stage_v_123_1 ^ 0x2A) * 2) + pub_r001810_1_1) & 127;
  int stage_v_211_2 = (((stage_v_123_2 ^ 0x2A) * 2) + pub_r001810_1_2) & 127;
  if (stage_v_211_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((pub_r001810_3_1 * 2) + 12) & 63;
  int stage_v_212_2 = ((pub_r001810_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001810_6_1 * 2) + 42) & 63;
  int stage_v_213_2 = ((pub_r001810_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = (((stage_v_117_1 ^ 0x2A) * 2) + pub_r001810_0_1) & 127;
  int stage_v_214_2 = (((stage_v_117_2 ^ 0x2A) * 2) + pub_r001810_0_2) & 127;
  if (stage_v_214_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = (((helper_flow_12_1 ^ 0x2A) * 2) + pub_r001810_13_1) & 127;
  int stage_v_215_2 = (((helper_flow_12_2 ^ 0x2A) * 2) + pub_r001810_13_2) & 127;
  if (stage_v_215_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
  }
  if (stage_v_215_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001810_2_1 == pub_r001810_2_2);
  __CPROVER_assume(pub_r001810_16_1 == pub_r001810_16_2);
  __CPROVER_assume(sec_r001810_16_1 != sec_r001810_16_2);
  __CPROVER_assume(sec_r001810_10_1 != sec_r001810_10_2);
  __CPROVER_assume(sec_r001810_4_1 != sec_r001810_4_2);
  __CPROVER_assume(sec_r001810_1_1 != sec_r001810_1_2);
  __CPROVER_assume(pub_r001810_3_1 == pub_r001810_3_2);
  __CPROVER_assume(pub_r001810_6_1 == pub_r001810_6_2);
  __CPROVER_assume(sec_r001810_5_1 != sec_r001810_5_2);
  __CPROVER_assume(sec_r001810_6_1 != sec_r001810_6_2);
  __CPROVER_assume(pub_r001810_5_1 == pub_r001810_5_2);
  __CPROVER_assume(sec_r001810_13_1 != sec_r001810_13_2);
  __CPROVER_assume(sec_r001810_15_1 != sec_r001810_15_2);
  __CPROVER_assume(sec_r001810_7_1 != sec_r001810_7_2);
  __CPROVER_assume(sec_r001810_2_1 != sec_r001810_2_2);
  __CPROVER_assume(pub_r001810_1_1 == pub_r001810_1_2);
  __CPROVER_assume(pub_r001810_4_1 == pub_r001810_4_2);
  __CPROVER_assume(pub_r001810_13_1 == pub_r001810_13_2);
  __CPROVER_assume(pub_r001810_12_1 == pub_r001810_12_2);
  __CPROVER_assume(sec_r001810_8_1 != sec_r001810_8_2);
  __CPROVER_assume(pub_r001810_10_1 == pub_r001810_10_2);
  __CPROVER_assume(pub_r001810_0_1 == pub_r001810_0_2);
  __CPROVER_assume(pub_r001810_15_1 == pub_r001810_15_2);
  __CPROVER_assume(sec_r001810_9_1 != sec_r001810_9_2);
  __CPROVER_assume(sec_r001810_3_1 != sec_r001810_3_2);
  __CPROVER_assume(sec_r001810_14_1 != sec_r001810_14_2);
  __CPROVER_assume(pub_r001810_7_1 == pub_r001810_7_2);
  __CPROVER_assume(pub_r001810_8_1 == pub_r001810_8_2);
  __CPROVER_assume(pub_r001810_14_1 == pub_r001810_14_2);
  __CPROVER_assume(pub_r001810_9_1 == pub_r001810_9_2);
  __CPROVER_assume(sec_r001810_12_1 != sec_r001810_12_2);
  __CPROVER_assume(sec_r001810_0_1 != sec_r001810_0_2);
  __CPROVER_assume(pub_r001810_11_1 == pub_r001810_11_2);
  __CPROVER_assume(sec_r001810_11_1 != sec_r001810_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.port == st_var_0_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.gain == st_var_1_2.gain);
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
  assert(helper_flow_7_1 == helper_flow_7_2);
  assert(helper_flow_8_1 == helper_flow_8_2);
  assert(helper_flow_9_1 == helper_flow_9_2);
  assert(helper_flow_10_1 == helper_flow_10_2);
  assert(helper_flow_11_1 == helper_flow_11_2);
  assert(helper_flow_12_1 == helper_flow_12_2);
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
}


