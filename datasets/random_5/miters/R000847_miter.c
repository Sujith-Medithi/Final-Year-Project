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
struct Vector3D_R000847_4713_0
{
  int heading;
  short coord_z;
  unsigned char coord_x;
  int norm_sq;
  unsigned char coord_y;
  int pitch;
  int buffer[3];
};
struct Transaction_R000847_4713_1
{
  int fee;
  short status;
  int balance;
  int buffer[3];
};
struct DeviceConfig_R000847_4713_2
{
  unsigned char stop_bits;
  unsigned char parity;
  unsigned char baud_rate;
  int buffer[3];
};
union TelemetryField_R000847_4713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000847_4713_1
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
void fn_R000847_4713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000847_4713_1 st_1 = {0};
  struct Transaction_R000847_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int tracker_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_24_1) & 63;
  aux_2 = (aux_2 + tracker_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_15_1 = local_arr_1[aux_1 % 3];
  int segment_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_15_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_70_1 > 48)
  {
    acc_1 = ((acc_1 + (vector_70_1 * 2)) + 5) & 127;
    aux_1 ^= vector_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_70_2 > 48)
  {
    acc_2 = ((acc_2 + (vector_70_2 * 2)) + 5) & 127;
    aux_2 ^= vector_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_70_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_24_1 == tracker_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_15_1 == segment_15_2);
  assert(vector_70_1 == vector_70_2);
}

int fn_R000847_4713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000847_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int tracker_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_24) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_15 = local_arr[aux % 3];
  acc = (acc + (segment_15 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_70 > 48)
  {
    acc = ((acc + (vector_70 * 2)) + 5) & 127;
    aux ^= vector_70 & 15;
  }
  else
  {
    acc = ((acc - vector_70) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000847_4713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000847_4713_2 st_1 = {0};
  struct DeviceConfig_R000847_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int offset_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_92_1) & 63;
  aux_2 = (aux_2 + offset_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_92_1 == offset_92_2);
}

int fn_R000847_4713_1(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000847_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int offset_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_92) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000847_4713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000847_4713_0 st_1 = {0};
  struct Vector3D_R000847_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int window_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_94_1) & 63;
  aux_2 = (aux_2 + window_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_41_1)
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

  switch (segment_41_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_72_1 > 14)
  {
    acc_1 = ((acc_1 + (factor_72_1 * 2)) + 5) & 127;
    aux_1 ^= factor_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_72_2 > 14)
  {
    acc_2 = ((acc_2 + (factor_72_2 * 2)) + 5) & 127;
    aux_2 ^= factor_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_72_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_94_1 == window_94_2);
  assert(segment_41_1 == segment_41_2);
  assert(factor_72_1 == factor_72_2);
}

int fn_R000847_4713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000847_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int window_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_94) & 63;
  acc ^= aux;
  int segment_41 = (aux + st.buffer[1]) & 3;
  switch (segment_41)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_72 > 14)
  {
    acc = ((acc + (factor_72 * 2)) + 5) & 127;
    aux ^= factor_72 & 15;
  }
  else
  {
    acc = ((acc - factor_72) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000847_4713_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000847_4713_2 st_1 = {0};
  struct DeviceConfig_R000847_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int offset_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_74_1)
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

  switch (offset_74_2)
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
  int offset_42_1 = local_arr_1[aux_1 % 3];
  int offset_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_42_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_74_1 == offset_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_42_1 == offset_42_2);
}

int fn_R000847_4713_3(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000847_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int offset_74 = (aux + st.buffer[1]) & 3;
  switch (offset_74)
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
  int offset_42 = local_arr[aux % 3];
  acc = (acc + (offset_42 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000847_4713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000847_4713_0 st_1 = {0};
  struct Vector3D_R000847_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_93_1 = local_arr_1[aux_1 % 3];
  int coefficient_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_93_2 * 2)) & 127;
  int mask_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_61_1)
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

  switch (mask_61_2)
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

  int coefficient_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_88_1) & 63;
  aux_2 = (aux_2 + coefficient_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_93_1 == coefficient_93_2);
  assert(mask_61_1 == mask_61_2);
  assert(coefficient_88_1 == coefficient_88_2);
}

int fn_R000847_4713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000847_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int coefficient_93 = local_arr[aux % 3];
  acc = (acc + (coefficient_93 * 2)) & 127;
  int mask_61 = (aux + st.buffer[1]) & 3;
  switch (mask_61)
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

  int coefficient_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_88) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000847_4713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000847_4713_1 st_1 = {0};
  struct Transaction_R000847_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_99_1 > 45)
  {
    acc_1 = ((acc_1 + (bound_99_1 * 2)) + 5) & 127;
    aux_1 ^= bound_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_99_2 > 45)
  {
    acc_2 = ((acc_2 + (bound_99_2 * 2)) + 5) & 127;
    aux_2 ^= bound_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_99_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_99_1 == bound_99_2);
}

int fn_R000847_4713_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000847_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_99 > 45)
  {
    acc = ((acc + (bound_99 * 2)) + 5) & 127;
    aux ^= bound_99 & 15;
  }
  else
  {
    acc = ((acc - bound_99) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000847_4713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000847_4713_1 st_1 = {0};
  struct Transaction_R000847_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int segment_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_67_1) & 63;
  aux_2 = (aux_2 + segment_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_50_1 > 25)
  {
    acc_1 = ((acc_1 + (sample_50_1 * 2)) + 5) & 127;
    aux_1 ^= sample_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_50_2 > 25)
  {
    acc_2 = ((acc_2 + (sample_50_2 * 2)) + 5) & 127;
    aux_2 ^= sample_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_50_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_67_1 == segment_67_2);
  assert(sample_50_1 == sample_50_2);
}

int fn_R000847_4713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000847_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int segment_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_67) & 63;
  acc ^= aux;
  int sample_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_50 > 25)
  {
    acc = ((acc + (sample_50 * 2)) + 5) & 127;
    aux ^= sample_50 & 15;
  }
  else
  {
    acc = ((acc - sample_50) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000847_4713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000847_4713_0 st_1 = {0};
  struct Vector3D_R000847_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int offset_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_83_1) & 63;
  aux_2 = (aux_2 + offset_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_10_1 > 23)
  {
    acc_1 = ((acc_1 + (bound_10_1 * 2)) + 5) & 127;
    aux_1 ^= bound_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_10_2 > 23)
  {
    acc_2 = ((acc_2 + (bound_10_2 * 2)) + 5) & 127;
    aux_2 ^= bound_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_93_1)
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

  switch (metric_93_2)
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
  int coefficient_99_1 = local_arr_1[aux_1 % 3];
  int coefficient_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_99_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_83_1 == offset_83_2);
  assert(bound_10_1 == bound_10_2);
  assert(metric_93_1 == metric_93_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_99_1 == coefficient_99_2);
}

int fn_R000847_4713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000847_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int offset_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_83) & 63;
  acc ^= aux;
  int bound_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_10 > 23)
  {
    acc = ((acc + (bound_10 * 2)) + 5) & 127;
    aux ^= bound_10 & 15;
  }
  else
  {
    acc = ((acc - bound_10) + 11) & 127;
    aux += 3;
  }
  int metric_93 = (aux + st.buffer[1]) & 3;
  switch (metric_93)
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
  int coefficient_99 = local_arr[aux % 3];
  acc = (acc + (coefficient_99 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000847_4713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000847_4713_0 st_1 = {0};
  struct Vector3D_R000847_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int quotient_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_68_1)
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

  switch (quotient_68_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_68_1 == quotient_68_2);
}

int fn_R000847_4713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000847_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int quotient_68 = (aux + st.buffer[1]) & 3;
  switch (quotient_68)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000847_4713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000847_4713_1 st_1 = {0};
  struct Transaction_R000847_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int bound_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_13_1) & 63;
  aux_2 = (aux_2 + bound_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_81_1 = local_arr_1[aux_1 % 3];
  int metric_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_81_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_13_1 == bound_13_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_81_1 == metric_81_2);
}

int fn_R000847_4713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000847_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int bound_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_13) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int metric_81 = local_arr[aux % 3];
  acc = (acc + (metric_81 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000847_4713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000847_4713_1 st_1 = {0};
  struct Transaction_R000847_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_68_1 = local_arr_1[aux_1 % 3];
  int metric_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_68_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_68_1 == metric_68_2);
}

int fn_R000847_4713_10(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000847_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int metric_68 = local_arr[aux % 3];
  acc = (acc + (metric_68 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000847_4713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000847_4713_2 st_1 = {0};
  struct DeviceConfig_R000847_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int pivot_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_62_1 > 15)
  {
    acc_1 = ((acc_1 + (pivot_62_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_62_2 > 15)
  {
    acc_2 = ((acc_2 + (pivot_62_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_25_1) & 63;
  aux_2 = (aux_2 + tracker_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_98_1 = local_arr_1[aux_1 % 3];
  int margin_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_98_2 * 2)) & 127;
  int metric_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_30_1)
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

  switch (metric_30_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_62_1 == pivot_62_2);
  assert(tracker_25_1 == tracker_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_98_1 == margin_98_2);
  assert(metric_30_1 == metric_30_2);
}

int fn_R000847_4713_11(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000847_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int pivot_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_62 > 15)
  {
    acc = ((acc + (pivot_62 * 2)) + 5) & 127;
    aux ^= pivot_62 & 15;
  }
  else
  {
    acc = ((acc - pivot_62) + 11) & 127;
    aux += 3;
  }
  int tracker_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_25) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_98 = local_arr[aux % 3];
  acc = (acc + (margin_98 * 2)) & 127;
  int metric_30 = (aux + st.buffer[1]) & 3;
  switch (metric_30)
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

void fn_R000847_4713_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000847_4713_0 st_1 = {0};
  struct Vector3D_R000847_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int index_reg_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_45_1)
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

  switch (index_reg_45_2)
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

  int tally_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_74_1) & 63;
  aux_2 = (aux_2 + tally_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_45_1 == index_reg_45_2);
  assert(tally_74_1 == tally_74_2);
}

int fn_R000847_4713_12(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000847_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int index_reg_45 = (aux + st.buffer[1]) & 3;
  switch (index_reg_45)
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

  int tally_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_74) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000847_4713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000847_4713_2 st_1 = {0};
  struct DeviceConfig_R000847_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int factor_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_33_1 > 28)
  {
    acc_1 = ((acc_1 + (factor_33_1 * 2)) + 5) & 127;
    aux_1 ^= factor_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_33_2 > 28)
  {
    acc_2 = ((acc_2 + (factor_33_2 * 2)) + 5) & 127;
    aux_2 ^= factor_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_33_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_33_1 == factor_33_2);
}

int fn_R000847_4713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000847_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int factor_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_33 > 28)
  {
    acc = ((acc + (factor_33 * 2)) + 5) & 127;
    aux ^= factor_33 & 15;
  }
  else
  {
    acc = ((acc - factor_33) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000847_4713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000847_4713_1 st_1 = {0};
  struct Transaction_R000847_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int phase_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_36_1)
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

  switch (phase_36_2)
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

  int accumulator_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_92_1) & 63;
  aux_2 = (aux_2 + accumulator_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_36_1 == phase_36_2);
  assert(accumulator_92_1 == accumulator_92_2);
}

int fn_R000847_4713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000847_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int phase_36 = (aux + st.buffer[1]) & 3;
  switch (phase_36)
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

  int accumulator_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_92) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000847_4713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000847_4713_2 st_1 = {0};
  struct DeviceConfig_R000847_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_24_1)
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

  switch (checksum_24_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_24_1 == checksum_24_2);
}

int fn_R000847_4713_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000847_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_24 = (aux + st.buffer[1]) & 3;
  switch (checksum_24)
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

void fn_R000847_4713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000847_4713_0 st_1 = {0};
  struct Vector3D_R000847_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int coefficient_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_79_1)
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

  switch (coefficient_79_2)
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

  int stride_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_51_1) & 63;
  aux_2 = (aux_2 + stride_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_79_1 == coefficient_79_2);
  assert(stride_51_1 == stride_51_2);
}

int fn_R000847_4713_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000847_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int coefficient_79 = (aux + st.buffer[1]) & 3;
  switch (coefficient_79)
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

  int stride_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_51) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000847_4713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000847_4713_2 st_1 = {0};
  struct DeviceConfig_R000847_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_77_1 = local_arr_1[aux_1 % 3];
  int coefficient_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_77_2 * 2)) & 127;
  int offset_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_43_1) & 63;
  aux_2 = (aux_2 + offset_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
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

  assert(coefficient_77_1 == coefficient_77_2);
  assert(offset_43_1 == offset_43_2);
}

int fn_R000847_4713_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000847_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int coefficient_77 = local_arr[aux % 3];
  acc = (acc + (coefficient_77 * 2)) & 127;
  int offset_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_43) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000847_0_1;
  int sec_r000847_0_2;
  int sec_r000847_1_1;
  int sec_r000847_1_2;
  int sec_r000847_2_1;
  int sec_r000847_2_2;
  int sec_r000847_3_1;
  int sec_r000847_3_2;
  int sec_r000847_4_1;
  int sec_r000847_4_2;
  int sec_r000847_5_1;
  int sec_r000847_5_2;
  int sec_r000847_6_1;
  int sec_r000847_6_2;
  int sec_r000847_7_1;
  int sec_r000847_7_2;
  int sec_r000847_8_1;
  int sec_r000847_8_2;
  int sec_r000847_9_1;
  int sec_r000847_9_2;
  int sec_r000847_10_1;
  int sec_r000847_10_2;
  int sec_r000847_11_1;
  int sec_r000847_11_2;
  int sec_r000847_12_1;
  int sec_r000847_12_2;
  int sec_r000847_13_1;
  int sec_r000847_13_2;
  int sec_r000847_14_1;
  int sec_r000847_14_2;
  int sec_r000847_15_1;
  int sec_r000847_15_2;
  int sec_r000847_16_1;
  int sec_r000847_16_2;
  int sec_r000847_17_1;
  int sec_r000847_17_2;
  int sec_r000847_18_1;
  int sec_r000847_18_2;
  int sec_r000847_19_1;
  int sec_r000847_19_2;
  int sec_r000847_20_1;
  int sec_r000847_20_2;
  int pub_r000847_0_1;
  int pub_r000847_0_2;
  int pub_r000847_1_1;
  int pub_r000847_1_2;
  int pub_r000847_2_1;
  int pub_r000847_2_2;
  int pub_r000847_3_1;
  int pub_r000847_3_2;
  int pub_r000847_4_1;
  int pub_r000847_4_2;
  int pub_r000847_5_1;
  int pub_r000847_5_2;
  int pub_r000847_6_1;
  int pub_r000847_6_2;
  int pub_r000847_7_1;
  int pub_r000847_7_2;
  int pub_r000847_8_1;
  int pub_r000847_8_2;
  int pub_r000847_9_1;
  int pub_r000847_9_2;
  int pub_r000847_10_1;
  int pub_r000847_10_2;
  int pub_r000847_11_1;
  int pub_r000847_11_2;
  int pub_r000847_12_1;
  int pub_r000847_12_2;
  int pub_r000847_13_1;
  int pub_r000847_13_2;
  int pub_r000847_14_1;
  int pub_r000847_14_2;
  int pub_r000847_15_1;
  int pub_r000847_15_2;
  int pub_r000847_16_1;
  int pub_r000847_16_2;
  int pub_r000847_17_1;
  int pub_r000847_17_2;
  int pub_r000847_18_1;
  int pub_r000847_18_2;
  int pub_r000847_19_1;
  int pub_r000847_19_2;
  int pub_r000847_20_1;
  int pub_r000847_20_2;
  int pub_r000847_21_1;
  int pub_r000847_21_2;
  int pub_r000847_22_1;
  int pub_r000847_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000847_0_1 >= (-100)) && (pub_r000847_0_1 <= 100));
  __CPROVER_assume((pub_r000847_0_2 >= (-100)) && (pub_r000847_0_2 <= 100));
  __CPROVER_assume((pub_r000847_1_1 >= (-100)) && (pub_r000847_1_1 <= 100));
  __CPROVER_assume((pub_r000847_1_2 >= (-100)) && (pub_r000847_1_2 <= 100));
  __CPROVER_assume((pub_r000847_2_1 >= (-100)) && (pub_r000847_2_1 <= 100));
  __CPROVER_assume((pub_r000847_2_2 >= (-100)) && (pub_r000847_2_2 <= 100));
  __CPROVER_assume((pub_r000847_3_1 >= (-100)) && (pub_r000847_3_1 <= 100));
  __CPROVER_assume((pub_r000847_3_2 >= (-100)) && (pub_r000847_3_2 <= 100));
  __CPROVER_assume((pub_r000847_4_1 >= (-100)) && (pub_r000847_4_1 <= 100));
  __CPROVER_assume((pub_r000847_4_2 >= (-100)) && (pub_r000847_4_2 <= 100));
  __CPROVER_assume((pub_r000847_5_1 >= (-100)) && (pub_r000847_5_1 <= 100));
  __CPROVER_assume((pub_r000847_5_2 >= (-100)) && (pub_r000847_5_2 <= 100));
  __CPROVER_assume((pub_r000847_6_1 >= (-100)) && (pub_r000847_6_1 <= 100));
  __CPROVER_assume((pub_r000847_6_2 >= (-100)) && (pub_r000847_6_2 <= 100));
  __CPROVER_assume((pub_r000847_7_1 >= (-100)) && (pub_r000847_7_1 <= 100));
  __CPROVER_assume((pub_r000847_7_2 >= (-100)) && (pub_r000847_7_2 <= 100));
  __CPROVER_assume((pub_r000847_8_1 >= (-100)) && (pub_r000847_8_1 <= 100));
  __CPROVER_assume((pub_r000847_8_2 >= (-100)) && (pub_r000847_8_2 <= 100));
  __CPROVER_assume((pub_r000847_9_1 >= (-100)) && (pub_r000847_9_1 <= 100));
  __CPROVER_assume((pub_r000847_9_2 >= (-100)) && (pub_r000847_9_2 <= 100));
  __CPROVER_assume((pub_r000847_10_1 >= (-100)) && (pub_r000847_10_1 <= 100));
  __CPROVER_assume((pub_r000847_10_2 >= (-100)) && (pub_r000847_10_2 <= 100));
  __CPROVER_assume((pub_r000847_11_1 >= (-100)) && (pub_r000847_11_1 <= 100));
  __CPROVER_assume((pub_r000847_11_2 >= (-100)) && (pub_r000847_11_2 <= 100));
  __CPROVER_assume((pub_r000847_12_1 >= (-100)) && (pub_r000847_12_1 <= 100));
  __CPROVER_assume((pub_r000847_12_2 >= (-100)) && (pub_r000847_12_2 <= 100));
  __CPROVER_assume((pub_r000847_13_1 >= (-100)) && (pub_r000847_13_1 <= 100));
  __CPROVER_assume((pub_r000847_13_2 >= (-100)) && (pub_r000847_13_2 <= 100));
  __CPROVER_assume((pub_r000847_14_1 >= (-100)) && (pub_r000847_14_1 <= 100));
  __CPROVER_assume((pub_r000847_14_2 >= (-100)) && (pub_r000847_14_2 <= 100));
  __CPROVER_assume((pub_r000847_15_1 >= (-100)) && (pub_r000847_15_1 <= 100));
  __CPROVER_assume((pub_r000847_15_2 >= (-100)) && (pub_r000847_15_2 <= 100));
  __CPROVER_assume((pub_r000847_16_1 >= (-100)) && (pub_r000847_16_1 <= 100));
  __CPROVER_assume((pub_r000847_16_2 >= (-100)) && (pub_r000847_16_2 <= 100));
  __CPROVER_assume((pub_r000847_17_1 >= (-100)) && (pub_r000847_17_1 <= 100));
  __CPROVER_assume((pub_r000847_17_2 >= (-100)) && (pub_r000847_17_2 <= 100));
  __CPROVER_assume((pub_r000847_18_1 >= (-100)) && (pub_r000847_18_1 <= 100));
  __CPROVER_assume((pub_r000847_18_2 >= (-100)) && (pub_r000847_18_2 <= 100));
  __CPROVER_assume((pub_r000847_19_1 >= (-100)) && (pub_r000847_19_1 <= 100));
  __CPROVER_assume((pub_r000847_19_2 >= (-100)) && (pub_r000847_19_2 <= 100));
  __CPROVER_assume((pub_r000847_20_1 >= (-100)) && (pub_r000847_20_1 <= 100));
  __CPROVER_assume((pub_r000847_20_2 >= (-100)) && (pub_r000847_20_2 <= 100));
  __CPROVER_assume((pub_r000847_21_1 >= (-100)) && (pub_r000847_21_1 <= 100));
  __CPROVER_assume((pub_r000847_21_2 >= (-100)) && (pub_r000847_21_2 <= 100));
  __CPROVER_assume((pub_r000847_22_1 >= (-100)) && (pub_r000847_22_1 <= 100));
  __CPROVER_assume((pub_r000847_22_2 >= (-100)) && (pub_r000847_22_2 <= 100));
  __CPROVER_assume((sec_r000847_0_1 >= 0) && (sec_r000847_0_1 <= 255));
  __CPROVER_assume((sec_r000847_0_2 >= 0) && (sec_r000847_0_2 <= 255));
  __CPROVER_assume((sec_r000847_1_1 >= 0) && (sec_r000847_1_1 <= 255));
  __CPROVER_assume((sec_r000847_1_2 >= 0) && (sec_r000847_1_2 <= 255));
  __CPROVER_assume((sec_r000847_2_1 >= 0) && (sec_r000847_2_1 <= 255));
  __CPROVER_assume((sec_r000847_2_2 >= 0) && (sec_r000847_2_2 <= 255));
  __CPROVER_assume((sec_r000847_3_1 >= 0) && (sec_r000847_3_1 <= 255));
  __CPROVER_assume((sec_r000847_3_2 >= 0) && (sec_r000847_3_2 <= 255));
  __CPROVER_assume((sec_r000847_4_1 >= 0) && (sec_r000847_4_1 <= 255));
  __CPROVER_assume((sec_r000847_4_2 >= 0) && (sec_r000847_4_2 <= 255));
  __CPROVER_assume((sec_r000847_5_1 >= 0) && (sec_r000847_5_1 <= 255));
  __CPROVER_assume((sec_r000847_5_2 >= 0) && (sec_r000847_5_2 <= 255));
  __CPROVER_assume((sec_r000847_6_1 >= 0) && (sec_r000847_6_1 <= 255));
  __CPROVER_assume((sec_r000847_6_2 >= 0) && (sec_r000847_6_2 <= 255));
  __CPROVER_assume((sec_r000847_7_1 >= 0) && (sec_r000847_7_1 <= 255));
  __CPROVER_assume((sec_r000847_7_2 >= 0) && (sec_r000847_7_2 <= 255));
  __CPROVER_assume((sec_r000847_8_1 >= 0) && (sec_r000847_8_1 <= 255));
  __CPROVER_assume((sec_r000847_8_2 >= 0) && (sec_r000847_8_2 <= 255));
  __CPROVER_assume((sec_r000847_9_1 >= 0) && (sec_r000847_9_1 <= 255));
  __CPROVER_assume((sec_r000847_9_2 >= 0) && (sec_r000847_9_2 <= 255));
  __CPROVER_assume((sec_r000847_10_1 >= 0) && (sec_r000847_10_1 <= 255));
  __CPROVER_assume((sec_r000847_10_2 >= 0) && (sec_r000847_10_2 <= 255));
  __CPROVER_assume((sec_r000847_11_1 >= 0) && (sec_r000847_11_1 <= 255));
  __CPROVER_assume((sec_r000847_11_2 >= 0) && (sec_r000847_11_2 <= 255));
  __CPROVER_assume((sec_r000847_12_1 >= 0) && (sec_r000847_12_1 <= 255));
  __CPROVER_assume((sec_r000847_12_2 >= 0) && (sec_r000847_12_2 <= 255));
  __CPROVER_assume((sec_r000847_13_1 >= 0) && (sec_r000847_13_1 <= 255));
  __CPROVER_assume((sec_r000847_13_2 >= 0) && (sec_r000847_13_2 <= 255));
  __CPROVER_assume((sec_r000847_14_1 >= 0) && (sec_r000847_14_1 <= 255));
  __CPROVER_assume((sec_r000847_14_2 >= 0) && (sec_r000847_14_2 <= 255));
  __CPROVER_assume((sec_r000847_15_1 >= 0) && (sec_r000847_15_1 <= 255));
  __CPROVER_assume((sec_r000847_15_2 >= 0) && (sec_r000847_15_2 <= 255));
  __CPROVER_assume((sec_r000847_16_1 >= 0) && (sec_r000847_16_1 <= 255));
  __CPROVER_assume((sec_r000847_16_2 >= 0) && (sec_r000847_16_2 <= 255));
  __CPROVER_assume((sec_r000847_17_1 >= 0) && (sec_r000847_17_1 <= 255));
  __CPROVER_assume((sec_r000847_17_2 >= 0) && (sec_r000847_17_2 <= 255));
  __CPROVER_assume((sec_r000847_18_1 >= 0) && (sec_r000847_18_1 <= 255));
  __CPROVER_assume((sec_r000847_18_2 >= 0) && (sec_r000847_18_2 <= 255));
  __CPROVER_assume((sec_r000847_19_1 >= 0) && (sec_r000847_19_1 <= 255));
  __CPROVER_assume((sec_r000847_19_2 >= 0) && (sec_r000847_19_2 <= 255));
  __CPROVER_assume((sec_r000847_20_1 >= 0) && (sec_r000847_20_1 <= 255));
  __CPROVER_assume((sec_r000847_20_2 >= 0) && (sec_r000847_20_2 <= 255));
  struct Vector3D_R000847_4713_0 st_var_0_1 = {0};
  struct Vector3D_R000847_4713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000847_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000847_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000847_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000847_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000847_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000847_0_2 + 7) & 15;
  struct Transaction_R000847_4713_1 st_var_1_1 = {0};
  struct Transaction_R000847_4713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000847_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000847_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000847_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000847_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000847_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000847_0_2 + 9) & 15;
  struct DeviceConfig_R000847_4713_2 st_var_2_1 = {0};
  struct DeviceConfig_R000847_4713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000847_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000847_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000847_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000847_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000847_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000847_0_2 + 11) & 15;
  union TelemetryField_R000847_4713_0 u_var_1;
  union TelemetryField_R000847_4713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 45)
    {
      chk_sum_1 ^= stage_v_1_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_1_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 45)
    {
      chk_sum_2 ^= stage_v_1_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = (st_var_0_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_0_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (st_var_2_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_2_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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

  int stage_v_6_1 = ((st_var_0_1.buffer[0] * 2) + 25) & 63;
  int stage_v_6_2 = ((st_var_0_2.buffer[0] * 2) + 25) & 63;
  if (stage_v_6_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_6_1) - 5) & 255;
    if (stage_v_6_1 > 43)
    {
      chk_sum_1 ^= stage_v_6_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_6_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_6_2) - 5) & 255;
    if (stage_v_6_2 > 43)
    {
      chk_sum_2 ^= stage_v_6_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_7_1 = ((st_var_1_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_1_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 55)
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
  if (stage_v_7_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 55)
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
  if (stage_v_8_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 47)
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
  if (stage_v_8_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 47)
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
  int stage_v_9_1 = (st_var_0_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_0_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 13) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 13) & 15;
  int stage_v_12_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_12_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= stage_v_12_1;
  chk_sum_2 ^= stage_v_12_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 14) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 14) & 15;
  int stage_v_13_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_13_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= stage_v_13_1;
  chk_sum_2 ^= stage_v_13_2;
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
  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_16_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (21 & 31);
  int stage_v_16_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (21 & 31);
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= (stage_v_16_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_16_2 << 1) & 127;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 20) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 20) & 15;
  int stage_v_19_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_19_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= stage_v_19_1;
  chk_sum_2 ^= stage_v_19_2;
  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  int stage_v_21_1 = ((st_var_0_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_0_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 28)
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
  if (stage_v_21_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 28)
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
  int stage_v_22_1 = table_1[2];
  int stage_v_22_2 = table_2[2];
  table_1[2] = (table_1[3] + 45) & 63;
  table_2[2] = (table_2[3] + 45) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_23_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_23_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_23_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_24_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_24_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_25_1 = table_1[1];
  int stage_v_25_2 = table_2[1];
  table_1[1] = (table_1[2] + 51) & 63;
  table_2[1] = (table_2[2] + 51) & 63;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((st_var_0_1.buffer[0] * 2) + 88) & 63;
  int stage_v_27_2 = ((st_var_0_2.buffer[0] * 2) + 88) & 63;
  if (stage_v_27_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_27_1) - 5) & 255;
    if (stage_v_27_1 > 31)
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
  if (stage_v_27_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_27_2) - 5) & 255;
    if (stage_v_27_2 > 31)
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
  int stage_v_28_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_28_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_29_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_29_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_29_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_29_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  int stage_v_32_1 = (st_var_2_1.buffer[0] ^ 35) & 3;
  int stage_v_32_2 = (st_var_2_2.buffer[0] ^ 35) & 3;
  switch (stage_v_32_1)
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

  switch (stage_v_32_2)
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

  int stage_v_33_1 = (st_var_0_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_0_2.buffer[0] ^ 36) & 3;
  switch (stage_v_33_1)
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

  switch (stage_v_33_2)
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

  int stage_v_34_1 = table_1[2];
  int stage_v_34_2 = table_2[2];
  table_1[2] = (table_1[3] + 69) & 63;
  table_2[2] = (table_2[3] + 69) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_36_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (41 & 31);
  int stage_v_36_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (41 & 31);
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= (stage_v_36_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_36_2 << 1) & 127;
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 46)
    {
      chk_sum_1 ^= stage_v_37_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_37_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 46)
    {
      chk_sum_2 ^= stage_v_37_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_38_1 = table_1[2];
  int stage_v_38_2 = table_2[2];
  table_1[2] = (table_1[3] + 77) & 63;
  table_2[2] = (table_2[3] + 77) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((sec_r000847_4_1 & 1) != 0)
  {
    if ((sec_r000847_11_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000847_11_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000847_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000847_11_1 + 7) & 127;
  }
  if ((sec_r000847_4_2 & 1) != 0)
  {
    if ((sec_r000847_11_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000847_11_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000847_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000847_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((sec_r000847_1_1 & 1) != 0)
  {
    if ((sec_r000847_16_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000847_5_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000847_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000847_5_1 + 7) & 127;
  }
  if ((sec_r000847_1_2 & 1) != 0)
  {
    if ((sec_r000847_16_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000847_5_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000847_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000847_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((sec_r000847_4_1 & 1) != 0)
  {
    if ((sec_r000847_16_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000847_8_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000847_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000847_8_1 + 7) & 127;
  }
  if ((sec_r000847_4_2 & 1) != 0)
  {
    if ((sec_r000847_16_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000847_8_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000847_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000847_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000847_8_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000847_9_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000847_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000847_9_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000847_8_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000847_9_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000847_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000847_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((sec_r000847_1_1 & 1) != 0)
  {
    if ((sec_r000847_11_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000847_19_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000847_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000847_19_1 + 7) & 127;
  }
  if ((sec_r000847_1_2 & 1) != 0)
  {
    if ((sec_r000847_11_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000847_19_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000847_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000847_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000847_19_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000847_2_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000847_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000847_2_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000847_19_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000847_2_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000847_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000847_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000847_10_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000847_18_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000847_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000847_18_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000847_10_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000847_18_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000847_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000847_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((sec_r000847_3_1 & 1) != 0)
  {
    if ((sec_r000847_12_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000847_0_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000847_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000847_0_1 + 7) & 127;
  }
  if ((sec_r000847_3_2 & 1) != 0)
  {
    if ((sec_r000847_12_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000847_0_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000847_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000847_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000847_13_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000847_16_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000847_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000847_16_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000847_13_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000847_16_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000847_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000847_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000847_14_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000847_7_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000847_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000847_7_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000847_14_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000847_7_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000847_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000847_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000847_9_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000847_9_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000847_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000847_9_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000847_9_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000847_9_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000847_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000847_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000847_8_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000847_10_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000847_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000847_10_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000847_8_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000847_10_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000847_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000847_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((sec_r000847_16_1 & 1) != 0)
  {
    if ((sec_r000847_17_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000847_3_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000847_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000847_3_1 + 7) & 127;
  }
  if ((sec_r000847_16_2 & 1) != 0)
  {
    if ((sec_r000847_17_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000847_3_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000847_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000847_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000847_8_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000847_5_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000847_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000847_5_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000847_8_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000847_5_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000847_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000847_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000847_17_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000847_10_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000847_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000847_10_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000847_17_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000847_10_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000847_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000847_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((sec_r000847_6_1 & 1) != 0)
  {
    if ((sec_r000847_4_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000847_0_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000847_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000847_0_1 + 7) & 127;
  }
  if ((sec_r000847_6_2 & 1) != 0)
  {
    if ((sec_r000847_4_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000847_0_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000847_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000847_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000847_10_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000847_6_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000847_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000847_6_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000847_10_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000847_6_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000847_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000847_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000847_8_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000847_9_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000847_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000847_9_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000847_8_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000847_9_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000847_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000847_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000847_19_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000847_19_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000847_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000847_19_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000847_19_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000847_19_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000847_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000847_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((sec_r000847_5_1 & 1) != 0)
  {
    if ((sec_r000847_7_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000847_18_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000847_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000847_18_1 + 7) & 127;
  }
  if ((sec_r000847_5_2 & 1) != 0)
  {
    if ((sec_r000847_7_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000847_18_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000847_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000847_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000847_0_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000847_0_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000847_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000847_0_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000847_0_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000847_0_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000847_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000847_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000847_3_1 & 1) != 0)
  {
    if ((sec_r000847_19_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000847_20_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000847_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000847_20_1 + 7) & 127;
  }
  if ((sec_r000847_3_2 & 1) != 0)
  {
    if ((sec_r000847_19_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000847_20_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000847_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000847_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000847_18_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000847_10_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000847_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000847_10_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000847_18_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000847_10_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000847_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000847_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000847_1_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000847_0_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000847_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000847_0_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000847_1_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000847_0_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000847_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000847_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000847_13_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000847_3_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000847_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000847_3_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000847_13_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000847_3_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000847_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000847_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000847_7_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000847_0_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000847_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000847_0_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000847_7_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000847_0_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000847_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000847_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000847_4_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000847_11_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000847_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000847_11_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000847_4_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000847_11_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000847_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000847_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000847_7_1 & 1) != 0)
  {
    if ((sec_r000847_8_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000847_8_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000847_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000847_8_1 + 7) & 127;
  }
  if ((sec_r000847_7_2 & 1) != 0)
  {
    if ((sec_r000847_8_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000847_8_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000847_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000847_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000847_11_1 & 1) != 0)
  {
    if ((sec_r000847_9_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000847_15_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000847_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000847_15_1 + 7) & 127;
  }
  if ((sec_r000847_11_2 & 1) != 0)
  {
    if ((sec_r000847_9_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000847_15_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000847_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000847_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000847_20_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000847_18_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000847_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000847_18_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000847_20_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000847_18_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000847_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000847_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((sec_r000847_3_1 & 1) != 0)
  {
    if ((sec_r000847_13_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000847_15_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000847_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000847_15_1 + 7) & 127;
  }
  if ((sec_r000847_3_2 & 1) != 0)
  {
    if ((sec_r000847_13_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000847_15_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000847_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000847_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((sec_r000847_3_1 & 1) != 0)
  {
    if ((sec_r000847_14_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000847_2_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000847_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000847_2_1 + 7) & 127;
  }
  if ((sec_r000847_3_2 & 1) != 0)
  {
    if ((sec_r000847_14_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000847_2_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000847_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000847_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000847_18_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000847_13_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000847_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000847_13_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000847_18_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000847_13_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000847_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000847_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000847_10_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000847_10_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000847_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000847_10_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000847_10_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000847_10_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000847_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000847_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000847_9_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000847_3_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000847_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000847_3_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000847_9_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000847_3_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000847_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000847_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((sec_r000847_9_1 & 1) != 0)
  {
    if ((sec_r000847_8_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000847_13_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000847_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000847_13_1 + 7) & 127;
  }
  if ((sec_r000847_9_2 & 1) != 0)
  {
    if ((sec_r000847_8_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000847_13_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000847_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000847_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000847_7_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000847_3_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000847_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000847_3_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000847_7_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000847_3_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000847_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000847_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000847_17_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000847_11_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000847_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000847_11_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000847_17_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000847_11_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000847_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000847_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000847_1_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000847_6_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000847_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000847_6_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000847_1_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000847_6_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000847_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000847_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((sec_r000847_5_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000847_8_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000847_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000847_8_1 + 7) & 127;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((sec_r000847_5_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000847_8_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000847_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000847_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000847_8_1 & 1) != 0)
  {
    if ((sec_r000847_8_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000847_18_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000847_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000847_18_1 + 7) & 127;
  }
  if ((sec_r000847_8_2 & 1) != 0)
  {
    if ((sec_r000847_8_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000847_18_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000847_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000847_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000847_13_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000847_0_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000847_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000847_0_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000847_13_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000847_0_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000847_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000847_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000847_3_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000847_9_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000847_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000847_9_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000847_3_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000847_9_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000847_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000847_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000847_6_1 & 1) != 0)
  {
    if ((sec_r000847_3_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000847_21_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000847_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000847_21_1 + 7) & 127;
  }
  if ((sec_r000847_6_2 & 1) != 0)
  {
    if ((sec_r000847_3_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000847_21_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000847_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000847_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000847_7_1 & 1) != 0)
  {
    if ((sec_r000847_7_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000847_0_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000847_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000847_0_1 + 7) & 127;
  }
  if ((sec_r000847_7_2 & 1) != 0)
  {
    if ((sec_r000847_7_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000847_0_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000847_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000847_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000847_15_1 & 1) != 0)
  {
    if ((sec_r000847_1_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000847_0_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000847_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000847_0_1 + 7) & 127;
  }
  if ((sec_r000847_15_2 & 1) != 0)
  {
    if ((sec_r000847_1_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000847_0_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000847_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000847_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000847_5_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000847_10_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000847_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000847_10_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000847_5_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000847_10_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000847_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000847_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000847_14_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000847_7_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000847_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000847_7_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000847_14_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000847_7_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000847_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000847_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000847_16_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000847_7_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000847_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000847_7_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000847_16_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000847_7_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000847_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000847_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000847_15_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000847_8_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000847_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000847_8_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000847_15_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000847_8_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000847_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000847_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000847_16_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000847_3_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000847_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000847_3_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000847_16_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000847_3_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000847_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000847_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000847_17_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000847_8_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000847_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000847_8_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000847_17_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000847_8_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000847_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000847_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000847_0_1 & 1) != 0)
  {
    if ((sec_r000847_6_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000847_19_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000847_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000847_19_1 + 7) & 127;
  }
  if ((sec_r000847_0_2 & 1) != 0)
  {
    if ((sec_r000847_6_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000847_19_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000847_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000847_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000847_10_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000847_2_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000847_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000847_2_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000847_10_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000847_2_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000847_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000847_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000847_15_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000847_8_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000847_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000847_8_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000847_15_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000847_8_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000847_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000847_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000847_16_1 & 1) != 0)
  {
    if ((sec_r000847_13_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000847_10_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000847_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000847_10_1 + 7) & 127;
  }
  if ((sec_r000847_16_2 & 1) != 0)
  {
    if ((sec_r000847_13_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000847_10_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000847_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000847_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000847_13_1 & 1) != 0)
  {
    if ((sec_r000847_14_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000847_5_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000847_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000847_5_1 + 7) & 127;
  }
  if ((sec_r000847_13_2 & 1) != 0)
  {
    if ((sec_r000847_14_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000847_5_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000847_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000847_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000847_1_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000847_12_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000847_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000847_12_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000847_1_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000847_12_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000847_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000847_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000847_16_1 & 1) != 0)
  {
    if ((sec_r000847_2_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000847_19_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000847_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000847_19_1 + 7) & 127;
  }
  if ((sec_r000847_16_2 & 1) != 0)
  {
    if ((sec_r000847_2_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000847_19_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000847_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000847_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000847_3_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000847_3_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000847_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000847_3_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000847_3_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000847_3_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000847_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000847_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000847_9_1 & 1) != 0)
  {
    if ((sec_r000847_7_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000847_10_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000847_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000847_10_1 + 7) & 127;
  }
  if ((sec_r000847_9_2 & 1) != 0)
  {
    if ((sec_r000847_7_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000847_10_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000847_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000847_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000847_6_1 & 1) != 0)
  {
    if ((sec_r000847_12_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000847_6_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000847_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000847_6_1 + 7) & 127;
  }
  if ((sec_r000847_6_2 & 1) != 0)
  {
    if ((sec_r000847_12_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000847_6_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000847_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000847_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000847_20_1 & 1) != 0)
  {
    if ((sec_r000847_3_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000847_12_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000847_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000847_12_1 + 7) & 127;
  }
  if ((sec_r000847_20_2 & 1) != 0)
  {
    if ((sec_r000847_3_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000847_12_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000847_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000847_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000847_15_1 & 1) != 0)
  {
    if ((sec_r000847_19_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000847_20_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000847_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000847_20_1 + 7) & 127;
  }
  if ((sec_r000847_15_2 & 1) != 0)
  {
    if ((sec_r000847_19_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000847_20_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000847_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000847_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000847_7_1 & 1) != 0)
  {
    if ((sec_r000847_3_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000847_12_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000847_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000847_12_1 + 7) & 127;
  }
  if ((sec_r000847_7_2 & 1) != 0)
  {
    if ((sec_r000847_3_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000847_12_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000847_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000847_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000847_16_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000847_22_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000847_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000847_22_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000847_16_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000847_22_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000847_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000847_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000847_14_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000847_5_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000847_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000847_5_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000847_14_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000847_5_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000847_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000847_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000847_11_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000847_13_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000847_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000847_13_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000847_11_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000847_13_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000847_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000847_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000847_19_1 & 1) != 0)
  {
    if ((sec_r000847_16_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000847_16_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000847_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000847_16_1 + 7) & 127;
  }
  if ((sec_r000847_19_2 & 1) != 0)
  {
    if ((sec_r000847_16_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000847_16_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000847_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000847_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000847_7_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000847_22_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000847_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000847_22_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000847_7_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000847_22_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000847_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000847_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000847_2_1 & 1) != 0)
  {
    if ((sec_r000847_19_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000847_3_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000847_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000847_3_1 + 7) & 127;
  }
  if ((sec_r000847_2_2 & 1) != 0)
  {
    if ((sec_r000847_19_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000847_3_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000847_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000847_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000847_19_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000847_4_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000847_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000847_4_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000847_19_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000847_4_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000847_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000847_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000847_10_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000847_5_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000847_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000847_5_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000847_10_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000847_5_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000847_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000847_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000847_10_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000847_5_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000847_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000847_5_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000847_10_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000847_5_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000847_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000847_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000847_6_1 & 1) != 0)
  {
    if ((sec_r000847_18_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000847_21_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000847_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000847_21_1 + 7) & 127;
  }
  if ((sec_r000847_6_2 & 1) != 0)
  {
    if ((sec_r000847_18_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000847_21_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000847_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000847_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000847_6_1 & 1) != 0)
  {
    if ((sec_r000847_5_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000847_11_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000847_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000847_11_1 + 7) & 127;
  }
  if ((sec_r000847_6_2 & 1) != 0)
  {
    if ((sec_r000847_5_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000847_11_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000847_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000847_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000847_6_1 & 1) != 0)
  {
    if ((sec_r000847_16_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000847_12_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000847_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000847_12_1 + 7) & 127;
  }
  if ((sec_r000847_6_2 & 1) != 0)
  {
    if ((sec_r000847_16_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000847_12_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000847_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000847_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000847_14_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000847_12_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000847_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000847_12_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000847_14_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000847_12_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000847_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000847_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000847_16_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000847_10_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000847_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000847_10_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000847_16_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000847_10_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000847_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000847_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000847_7_1 & 1) != 0)
  {
    if ((sec_r000847_8_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000847_11_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000847_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000847_11_1 + 7) & 127;
  }
  if ((sec_r000847_7_2 & 1) != 0)
  {
    if ((sec_r000847_8_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000847_11_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000847_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000847_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000847_13_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000847_16_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000847_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000847_16_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000847_13_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000847_16_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000847_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000847_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000847_13_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000847_11_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000847_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000847_11_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000847_13_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000847_11_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000847_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000847_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000847_3_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000847_17_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000847_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000847_17_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000847_3_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000847_17_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000847_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000847_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000847_12_1 & 1) != 0)
  {
    if ((sec_r000847_6_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000847_16_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000847_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000847_16_1 + 7) & 127;
  }
  if ((sec_r000847_12_2 & 1) != 0)
  {
    if ((sec_r000847_6_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000847_16_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000847_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000847_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000847_3_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000847_8_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000847_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000847_8_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000847_3_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000847_8_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000847_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000847_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000847_0_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000847_14_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000847_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000847_14_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000847_0_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000847_14_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000847_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000847_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000847_20_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000847_15_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000847_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000847_15_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000847_20_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000847_15_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000847_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000847_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000847_1_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000847_14_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000847_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000847_14_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000847_1_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000847_14_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000847_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000847_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((sec_r000847_1_1 & 1) != 0)
  {
    if ((sec_r000847_9_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000847_19_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000847_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000847_19_1 + 7) & 127;
  }
  if ((sec_r000847_1_2 & 1) != 0)
  {
    if ((sec_r000847_9_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000847_19_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000847_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000847_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000847_0_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000847_0_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000847_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000847_0_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000847_0_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000847_0_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000847_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000847_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000847_3_1 & 1) != 0)
  {
    if ((sec_r000847_3_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000847_19_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000847_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000847_19_1 + 7) & 127;
  }
  if ((sec_r000847_3_2 & 1) != 0)
  {
    if ((sec_r000847_3_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000847_19_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000847_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000847_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((sec_r000847_7_1 & 1) != 0)
  {
    if ((sec_r000847_1_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000847_20_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000847_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000847_20_1 + 7) & 127;
  }
  if ((sec_r000847_7_2 & 1) != 0)
  {
    if ((sec_r000847_1_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000847_20_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000847_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000847_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000847_19_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000847_9_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000847_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000847_9_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000847_19_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000847_9_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000847_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000847_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000847_7_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000847_6_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000847_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000847_6_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000847_7_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000847_6_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000847_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000847_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000847_0_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000847_1_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000847_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000847_1_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000847_0_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000847_1_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000847_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000847_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000847_0_1 & 1) != 0)
  {
    if ((sec_r000847_6_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000847_14_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000847_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000847_14_1 + 7) & 127;
  }
  if ((sec_r000847_0_2 & 1) != 0)
  {
    if ((sec_r000847_6_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000847_14_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000847_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000847_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((sec_r000847_15_1 & 1) != 0)
  {
    if ((sec_r000847_11_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000847_22_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000847_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000847_22_1 + 7) & 127;
  }
  if ((sec_r000847_15_2 & 1) != 0)
  {
    if ((sec_r000847_11_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000847_22_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000847_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000847_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000847_5_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000847_6_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000847_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000847_6_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000847_5_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000847_6_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000847_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000847_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((sec_r000847_20_1 & 1) != 0)
  {
    if ((sec_r000847_13_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000847_10_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000847_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000847_10_1 + 7) & 127;
  }
  if ((sec_r000847_20_2 & 1) != 0)
  {
    if ((sec_r000847_13_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000847_10_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000847_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000847_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_137_1 & 1) != 0)
  {
    if ((sec_r000847_6_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000847_21_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000847_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000847_21_1 + 7) & 127;
  }
  if ((stage_v_137_2 & 1) != 0)
  {
    if ((sec_r000847_6_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000847_21_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000847_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000847_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000847_1_1 != sec_r000847_1_2);
  __CPROVER_assume(sec_r000847_20_1 != sec_r000847_20_2);
  __CPROVER_assume(pub_r000847_3_1 == pub_r000847_3_2);
  __CPROVER_assume(pub_r000847_6_1 == pub_r000847_6_2);
  __CPROVER_assume(pub_r000847_10_1 == pub_r000847_10_2);
  __CPROVER_assume(sec_r000847_6_1 != sec_r000847_6_2);
  __CPROVER_assume(sec_r000847_16_1 != sec_r000847_16_2);
  __CPROVER_assume(pub_r000847_19_1 == pub_r000847_19_2);
  __CPROVER_assume(pub_r000847_0_1 == pub_r000847_0_2);
  __CPROVER_assume(pub_r000847_7_1 == pub_r000847_7_2);
  __CPROVER_assume(pub_r000847_14_1 == pub_r000847_14_2);
  __CPROVER_assume(pub_r000847_11_1 == pub_r000847_11_2);
  __CPROVER_assume(sec_r000847_10_1 != sec_r000847_10_2);
  __CPROVER_assume(pub_r000847_8_1 == pub_r000847_8_2);
  __CPROVER_assume(sec_r000847_3_1 != sec_r000847_3_2);
  __CPROVER_assume(pub_r000847_20_1 == pub_r000847_20_2);
  __CPROVER_assume(pub_r000847_15_1 == pub_r000847_15_2);
  __CPROVER_assume(pub_r000847_18_1 == pub_r000847_18_2);
  __CPROVER_assume(sec_r000847_9_1 != sec_r000847_9_2);
  __CPROVER_assume(sec_r000847_5_1 != sec_r000847_5_2);
  __CPROVER_assume(sec_r000847_8_1 != sec_r000847_8_2);
  __CPROVER_assume(sec_r000847_7_1 != sec_r000847_7_2);
  __CPROVER_assume(pub_r000847_13_1 == pub_r000847_13_2);
  __CPROVER_assume(sec_r000847_15_1 != sec_r000847_15_2);
  __CPROVER_assume(sec_r000847_17_1 != sec_r000847_17_2);
  __CPROVER_assume(pub_r000847_9_1 == pub_r000847_9_2);
  __CPROVER_assume(sec_r000847_2_1 != sec_r000847_2_2);
  __CPROVER_assume(sec_r000847_4_1 != sec_r000847_4_2);
  __CPROVER_assume(sec_r000847_13_1 != sec_r000847_13_2);
  __CPROVER_assume(sec_r000847_12_1 != sec_r000847_12_2);
  __CPROVER_assume(sec_r000847_11_1 != sec_r000847_11_2);
  __CPROVER_assume(pub_r000847_5_1 == pub_r000847_5_2);
  __CPROVER_assume(pub_r000847_17_1 == pub_r000847_17_2);
  __CPROVER_assume(pub_r000847_2_1 == pub_r000847_2_2);
  __CPROVER_assume(pub_r000847_4_1 == pub_r000847_4_2);
  __CPROVER_assume(sec_r000847_14_1 != sec_r000847_14_2);
  __CPROVER_assume(sec_r000847_0_1 != sec_r000847_0_2);
  __CPROVER_assume(sec_r000847_19_1 != sec_r000847_19_2);
  __CPROVER_assume(pub_r000847_21_1 == pub_r000847_21_2);
  __CPROVER_assume(pub_r000847_22_1 == pub_r000847_22_2);
  __CPROVER_assume(sec_r000847_18_1 != sec_r000847_18_2);
  __CPROVER_assume(pub_r000847_16_1 == pub_r000847_16_2);
  __CPROVER_assume(pub_r000847_1_1 == pub_r000847_1_2);
  __CPROVER_assume(pub_r000847_12_1 == pub_r000847_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.fee == st_var_1_2.fee);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.balance == st_var_1_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.stop_bits == st_var_2_2.stop_bits);
  assert(st_var_2_1.parity == st_var_2_2.parity);
  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
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
}


