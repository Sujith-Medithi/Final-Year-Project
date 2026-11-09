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
struct DeviceConfig_R001373_7313_0
{
  int stop_bits;
  int id;
  unsigned char timeout;
  int baud_rate;
  int port;
  int parity;
  int buffer[3];
};
struct SensorNode_R001373_7313_1
{
  short status;
  short offset;
  int calib;
  int buffer[3];
};
union RegisterBank_R001373_7313_0
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
void fn_R001373_7313_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001373_7313_0 st_1 = {0};
  struct DeviceConfig_R001373_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_26_1 = local_arr_1[aux_1 % 3];
  int sample_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_26_2 * 2)) & 127;
  int cursor_84_1 = 0;
  int cursor_84_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_84_1 = ((cursor_84_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_84_2 = ((cursor_84_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_84_1) & 127;
    acc_2 = (acc_2 + cursor_84_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_26_1 == sample_26_2);
  assert(cursor_84_1 == cursor_84_2);
}

int fn_R001373_7313_0(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001373_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int sample_26 = local_arr[aux % 3];
  acc = (acc + (sample_26 * 2)) & 127;
  int cursor_84 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_84 = ((cursor_84 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_84) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001373_7313_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st_1 = {0};
  struct SensorNode_R001373_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int factor_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_14_1 > 10)
  {
    acc_1 = ((acc_1 + (factor_14_1 * 2)) + 5) & 127;
    aux_1 ^= factor_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_14_2 > 10)
  {
    acc_2 = ((acc_2 + (factor_14_2 * 2)) + 5) & 127;
    aux_2 ^= factor_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_14_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_14_1 == factor_14_2);
}

int fn_R001373_7313_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int factor_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_14 > 10)
  {
    acc = ((acc + (factor_14 * 2)) + 5) & 127;
    aux ^= factor_14 & 15;
  }
  else
  {
    acc = ((acc - factor_14) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001373_7313_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st_1 = {0};
  struct SensorNode_R001373_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_26_1)
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

  switch (cursor_26_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_26_1 == cursor_26_2);
}

int fn_R001373_7313_2(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_26 = (aux + st.buffer[1]) & 3;
  switch (cursor_26)
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

void fn_R001373_7313_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st_1 = {0};
  struct SensorNode_R001373_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int damping_21_1 = 0;
  int damping_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_21_1 = ((damping_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_21_2 = ((damping_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_21_1) & 127;
    acc_2 = (acc_2 + damping_21_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_51_1 = local_arr_1[aux_1 % 3];
  int mask_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_21_1 == damping_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_51_1 == mask_51_2);
}

int fn_R001373_7313_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int damping_21 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_21 = ((damping_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_21) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int mask_51 = local_arr[aux % 3];
  acc = (acc + (mask_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001373_7313_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001373_7313_0 st_1 = {0};
  struct DeviceConfig_R001373_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int segment_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_56_1)
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

  switch (segment_56_2)
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

  int scale_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_81_1) & 63;
  aux_2 = (aux_2 + scale_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_56_1 == segment_56_2);
  assert(scale_81_1 == scale_81_2);
}

int fn_R001373_7313_4(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001373_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int segment_56 = (aux + st.buffer[1]) & 3;
  switch (segment_56)
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

  int scale_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_81) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001373_7313_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st_1 = {0};
  struct SensorNode_R001373_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_66_1) & 63;
  aux_2 = (aux_2 + vector_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_97_1 = 0;
  int coefficient_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_97_1 = ((coefficient_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_97_2 = ((coefficient_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_97_1) & 127;
    acc_2 = (acc_2 + coefficient_97_2) & 127;
  }

  int cursor_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_65_1)
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

  switch (cursor_65_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_66_1 == vector_66_2);
  assert(coefficient_97_1 == coefficient_97_2);
  assert(cursor_65_1 == cursor_65_2);
}

int fn_R001373_7313_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_66) & 63;
  acc ^= aux;
  int coefficient_97 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_97 = ((coefficient_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_97) & 127;
  }

  int cursor_65 = (aux + st.buffer[1]) & 3;
  switch (cursor_65)
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

void fn_R001373_7313_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st_1 = {0};
  struct SensorNode_R001373_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int quotient_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_91_1) & 63;
  aux_2 = (aux_2 + quotient_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_55_1)
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

  switch (tracker_55_2)
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
  int segment_46_1 = local_arr_1[aux_1 % 3];
  int segment_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_46_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_91_1 == quotient_91_2);
  assert(tracker_55_1 == tracker_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_46_1 == segment_46_2);
}

int fn_R001373_7313_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int quotient_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_91) & 63;
  acc ^= aux;
  int tracker_55 = (aux + st.buffer[1]) & 3;
  switch (tracker_55)
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
  int segment_46 = local_arr[aux % 3];
  acc = (acc + (segment_46 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001373_7313_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001373_7313_0 st_1 = {0};
  struct DeviceConfig_R001373_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int residue_66_1 = 0;
  int residue_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_66_1 = ((residue_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_66_2 = ((residue_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_66_1) & 127;
    acc_2 = (acc_2 + residue_66_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_81_1 = local_arr_1[aux_1 % 3];
  int sample_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_81_2 * 2)) & 127;
  int index_reg_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_22_1) & 63;
  aux_2 = (aux_2 + index_reg_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_66_1 == residue_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_81_1 == sample_81_2);
  assert(index_reg_22_1 == index_reg_22_2);
}

int fn_R001373_7313_7(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001373_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int residue_66 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_66 = ((residue_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_66) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int sample_81 = local_arr[aux % 3];
  acc = (acc + (sample_81 * 2)) & 127;
  int index_reg_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_22) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001373_7313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001373_7313_0 st_1 = {0};
  struct DeviceConfig_R001373_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_41_1 = local_arr_1[aux_1 % 3];
  int bound_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_41_2 * 2)) & 127;
  int phase_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_98_1 > 44)
  {
    acc_1 = ((acc_1 + (phase_98_1 * 2)) + 5) & 127;
    aux_1 ^= phase_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_98_2 > 44)
  {
    acc_2 = ((acc_2 + (phase_98_2 * 2)) + 5) & 127;
    aux_2 ^= phase_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_67_1 = 0;
  int damping_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_67_1 = ((damping_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_67_2 = ((damping_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_67_1) & 127;
    acc_2 = (acc_2 + damping_67_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_41_1 == bound_41_2);
  assert(phase_98_1 == phase_98_2);
  assert(damping_67_1 == damping_67_2);
}

int fn_R001373_7313_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001373_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int bound_41 = local_arr[aux % 3];
  acc = (acc + (bound_41 * 2)) & 127;
  int phase_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_98 > 44)
  {
    acc = ((acc + (phase_98 * 2)) + 5) & 127;
    aux ^= phase_98 & 15;
  }
  else
  {
    acc = ((acc - phase_98) + 11) & 127;
    aux += 3;
  }
  int damping_67 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_67 = ((damping_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_67) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001373_7313_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001373_7313_0 st_1 = {0};
  struct DeviceConfig_R001373_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int damping_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_84_1)
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

  switch (damping_84_2)
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
  int scale_93_1 = local_arr_1[aux_1 % 3];
  int scale_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_93_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_59_1 > 38)
  {
    acc_1 = ((acc_1 + (index_reg_59_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_59_2 > 38)
  {
    acc_2 = ((acc_2 + (index_reg_59_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_84_1 == damping_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_93_1 == scale_93_2);
  assert(index_reg_59_1 == index_reg_59_2);
}

int fn_R001373_7313_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001373_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int damping_84 = (aux + st.buffer[1]) & 3;
  switch (damping_84)
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
  int scale_93 = local_arr[aux % 3];
  acc = (acc + (scale_93 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_59 > 38)
  {
    acc = ((acc + (index_reg_59 * 2)) + 5) & 127;
    aux ^= index_reg_59 & 15;
  }
  else
  {
    acc = ((acc - index_reg_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001373_7313_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st_1 = {0};
  struct SensorNode_R001373_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int quotient_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_19_1)
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

  switch (quotient_19_2)
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

  int delta_22_1 = 0;
  int delta_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_22_1 = ((delta_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_22_2 = ((delta_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_22_1) & 127;
    acc_2 = (acc_2 + delta_22_2) & 127;
  }

  int damping_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_43_1) & 63;
  aux_2 = (aux_2 + damping_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_76_1 > 37)
  {
    acc_1 = ((acc_1 + (offset_76_1 * 2)) + 5) & 127;
    aux_1 ^= offset_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_76_2 > 37)
  {
    acc_2 = ((acc_2 + (offset_76_2 * 2)) + 5) & 127;
    aux_2 ^= offset_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_76_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_19_1 == quotient_19_2);
  assert(delta_22_1 == delta_22_2);
  assert(damping_43_1 == damping_43_2);
  assert(offset_76_1 == offset_76_2);
}

int fn_R001373_7313_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int quotient_19 = (aux + st.buffer[1]) & 3;
  switch (quotient_19)
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

  int delta_22 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_22 = ((delta_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_22) & 127;
  }

  int damping_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_43) & 63;
  acc ^= aux;
  int offset_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_76 > 37)
  {
    acc = ((acc + (offset_76 * 2)) + 5) & 127;
    aux ^= offset_76 & 15;
  }
  else
  {
    acc = ((acc - offset_76) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001373_7313_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001373_7313_0 st_1 = {0};
  struct DeviceConfig_R001373_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int segment_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_39_1 > 48)
  {
    acc_1 = ((acc_1 + (segment_39_1 * 2)) + 5) & 127;
    aux_1 ^= segment_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_39_2 > 48)
  {
    acc_2 = ((acc_2 + (segment_39_2 * 2)) + 5) & 127;
    aux_2 ^= segment_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_39_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_31_1)
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

  switch (delta_31_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_39_1 == segment_39_2);
  assert(delta_31_1 == delta_31_2);
}

int fn_R001373_7313_11(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001373_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int segment_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_39 > 48)
  {
    acc = ((acc + (segment_39 * 2)) + 5) & 127;
    aux ^= segment_39 & 15;
  }
  else
  {
    acc = ((acc - segment_39) + 11) & 127;
    aux += 3;
  }
  int delta_31 = (aux + st.buffer[1]) & 3;
  switch (delta_31)
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

void fn_R001373_7313_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st_1 = {0};
  struct SensorNode_R001373_7313_1 st_2 = {0};
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
  int pivot_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_10_1) & 63;
  aux_2 = (aux_2 + pivot_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_11_1 = local_arr_1[aux_1 % 3];
  int vector_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_11_2 * 2)) & 127;
  int threshold_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_89_1 > 41)
  {
    acc_1 = ((acc_1 + (threshold_89_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_89_2 > 41)
  {
    acc_2 = ((acc_2 + (threshold_89_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_89_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_10_1 == pivot_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_11_1 == vector_11_2);
  assert(threshold_89_1 == threshold_89_2);
}

int fn_R001373_7313_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_10) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int vector_11 = local_arr[aux % 3];
  acc = (acc + (vector_11 * 2)) & 127;
  int threshold_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_89 > 41)
  {
    acc = ((acc + (threshold_89 * 2)) + 5) & 127;
    aux ^= threshold_89 & 15;
  }
  else
  {
    acc = ((acc - threshold_89) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001373_7313_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001373_7313_0 st_1 = {0};
  struct DeviceConfig_R001373_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_41_1 = local_arr_1[aux_1 % 3];
  int offset_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_41_2 * 2)) & 127;
  int sample_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_48_1) & 63;
  aux_2 = (aux_2 + sample_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_41_1 == offset_41_2);
  assert(sample_48_1 == sample_48_2);
}

int fn_R001373_7313_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001373_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int offset_41 = local_arr[aux % 3];
  acc = (acc + (offset_41 * 2)) & 127;
  int sample_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_48) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001373_7313_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st_1 = {0};
  struct SensorNode_R001373_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int pivot_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_61_1 > 28)
  {
    acc_1 = ((acc_1 + (pivot_61_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_61_2 > 28)
  {
    acc_2 = ((acc_2 + (pivot_61_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_43_1 = local_arr_1[aux_1 % 3];
  int segment_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_43_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_61_1 == pivot_61_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_43_1 == segment_43_2);
}

int fn_R001373_7313_14(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int pivot_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_61 > 28)
  {
    acc = ((acc + (pivot_61 * 2)) + 5) & 127;
    aux ^= pivot_61 & 15;
  }
  else
  {
    acc = ((acc - pivot_61) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int segment_43 = local_arr[aux % 3];
  acc = (acc + (segment_43 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001373_7313_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st_1 = {0};
  struct SensorNode_R001373_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int offset_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_38_1)
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

  switch (offset_38_2)
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
  int vector_85_1 = local_arr_1[aux_1 % 3];
  int vector_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_85_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_38_1 == offset_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_85_1 == vector_85_2);
}

int fn_R001373_7313_15(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int offset_38 = (aux + st.buffer[1]) & 3;
  switch (offset_38)
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
  int vector_85 = local_arr[aux % 3];
  acc = (acc + (vector_85 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001373_7313_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st_1 = {0};
  struct SensorNode_R001373_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int segment_87_1 = 0;
  int segment_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_87_1 = ((segment_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_87_2 = ((segment_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_87_1) & 127;
    acc_2 = (acc_2 + segment_87_2) & 127;
  }

  int residue_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_95_1 > 36)
  {
    acc_1 = ((acc_1 + (residue_95_1 * 2)) + 5) & 127;
    aux_1 ^= residue_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_95_2 > 36)
  {
    acc_2 = ((acc_2 + (residue_95_2 * 2)) + 5) & 127;
    aux_2 ^= residue_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_57_1)
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

  switch (parity_57_2)
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

  int cursor_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_56_1) & 63;
  aux_2 = (aux_2 + cursor_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_87_1 == segment_87_2);
  assert(residue_95_1 == residue_95_2);
  assert(parity_57_1 == parity_57_2);
  assert(cursor_56_1 == cursor_56_2);
}

int fn_R001373_7313_16(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int segment_87 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_87 = ((segment_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_87) & 127;
  }

  int residue_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_95 > 36)
  {
    acc = ((acc + (residue_95 * 2)) + 5) & 127;
    aux ^= residue_95 & 15;
  }
  else
  {
    acc = ((acc - residue_95) + 11) & 127;
    aux += 3;
  }
  int parity_57 = (aux + st.buffer[1]) & 3;
  switch (parity_57)
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

  int cursor_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_56) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001373_7313_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001373_7313_0 st_1 = {0};
  struct DeviceConfig_R001373_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_99_1 > 49)
  {
    acc_1 = ((acc_1 + (factor_99_1 * 2)) + 5) & 127;
    aux_1 ^= factor_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_99_2 > 49)
  {
    acc_2 = ((acc_2 + (factor_99_2 * 2)) + 5) & 127;
    aux_2 ^= factor_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_99_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_99_1 == factor_99_2);
}

int fn_R001373_7313_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001373_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_99 > 49)
  {
    acc = ((acc + (factor_99 * 2)) + 5) & 127;
    aux ^= factor_99 & 15;
  }
  else
  {
    acc = ((acc - factor_99) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001373_7313_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st_1 = {0};
  struct SensorNode_R001373_7313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int offset_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_74_1) & 63;
  aux_2 = (aux_2 + offset_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_38_1)
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

  switch (factor_38_2)
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

  int segment_39_1 = 0;
  int segment_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_39_1 = ((segment_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_39_2 = ((segment_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_39_1) & 127;
    acc_2 = (acc_2 + segment_39_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_74_1 == offset_74_2);
  assert(factor_38_1 == factor_38_2);
  assert(segment_39_1 == segment_39_2);
}

int fn_R001373_7313_18(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001373_7313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int offset_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_74) & 63;
  acc ^= aux;
  int factor_38 = (aux + st.buffer[1]) & 3;
  switch (factor_38)
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

  int segment_39 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_39 = ((segment_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_39) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001373_7313_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001373_7313_0 st_1 = {0};
  struct DeviceConfig_R001373_7313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_92_1 = 0;
  int residue_92_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_92_1 = ((residue_92_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_92_2 = ((residue_92_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_92_1) & 127;
    acc_2 = (acc_2 + residue_92_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_92_1 == residue_92_2);
}

int fn_R001373_7313_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001373_7313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_92 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_92 = ((residue_92 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_92) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001373_0_1;
  int sec_r001373_0_2;
  int sec_r001373_1_1;
  int sec_r001373_1_2;
  int sec_r001373_2_1;
  int sec_r001373_2_2;
  int sec_r001373_3_1;
  int sec_r001373_3_2;
  int sec_r001373_4_1;
  int sec_r001373_4_2;
  int sec_r001373_5_1;
  int sec_r001373_5_2;
  int sec_r001373_6_1;
  int sec_r001373_6_2;
  int sec_r001373_7_1;
  int sec_r001373_7_2;
  int sec_r001373_8_1;
  int sec_r001373_8_2;
  int sec_r001373_9_1;
  int sec_r001373_9_2;
  int sec_r001373_10_1;
  int sec_r001373_10_2;
  int sec_r001373_11_1;
  int sec_r001373_11_2;
  int sec_r001373_12_1;
  int sec_r001373_12_2;
  int sec_r001373_13_1;
  int sec_r001373_13_2;
  int sec_r001373_14_1;
  int sec_r001373_14_2;
  int sec_r001373_15_1;
  int sec_r001373_15_2;
  int sec_r001373_16_1;
  int sec_r001373_16_2;
  int sec_r001373_17_1;
  int sec_r001373_17_2;
  int sec_r001373_18_1;
  int sec_r001373_18_2;
  int sec_r001373_19_1;
  int sec_r001373_19_2;
  int pub_r001373_0_1;
  int pub_r001373_0_2;
  int pub_r001373_1_1;
  int pub_r001373_1_2;
  int pub_r001373_2_1;
  int pub_r001373_2_2;
  int pub_r001373_3_1;
  int pub_r001373_3_2;
  int pub_r001373_4_1;
  int pub_r001373_4_2;
  int pub_r001373_5_1;
  int pub_r001373_5_2;
  int pub_r001373_6_1;
  int pub_r001373_6_2;
  int pub_r001373_7_1;
  int pub_r001373_7_2;
  int pub_r001373_8_1;
  int pub_r001373_8_2;
  int pub_r001373_9_1;
  int pub_r001373_9_2;
  int pub_r001373_10_1;
  int pub_r001373_10_2;
  int pub_r001373_11_1;
  int pub_r001373_11_2;
  int pub_r001373_12_1;
  int pub_r001373_12_2;
  int pub_r001373_13_1;
  int pub_r001373_13_2;
  int pub_r001373_14_1;
  int pub_r001373_14_2;
  int pub_r001373_15_1;
  int pub_r001373_15_2;
  int pub_r001373_16_1;
  int pub_r001373_16_2;
  int pub_r001373_17_1;
  int pub_r001373_17_2;
  int pub_r001373_18_1;
  int pub_r001373_18_2;
  int pub_r001373_19_1;
  int pub_r001373_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001373_0_1 >= (-100)) && (pub_r001373_0_1 <= 100));
  __CPROVER_assume((pub_r001373_0_2 >= (-100)) && (pub_r001373_0_2 <= 100));
  __CPROVER_assume((pub_r001373_1_1 >= (-100)) && (pub_r001373_1_1 <= 100));
  __CPROVER_assume((pub_r001373_1_2 >= (-100)) && (pub_r001373_1_2 <= 100));
  __CPROVER_assume((pub_r001373_2_1 >= (-100)) && (pub_r001373_2_1 <= 100));
  __CPROVER_assume((pub_r001373_2_2 >= (-100)) && (pub_r001373_2_2 <= 100));
  __CPROVER_assume((pub_r001373_3_1 >= (-100)) && (pub_r001373_3_1 <= 100));
  __CPROVER_assume((pub_r001373_3_2 >= (-100)) && (pub_r001373_3_2 <= 100));
  __CPROVER_assume((pub_r001373_4_1 >= (-100)) && (pub_r001373_4_1 <= 100));
  __CPROVER_assume((pub_r001373_4_2 >= (-100)) && (pub_r001373_4_2 <= 100));
  __CPROVER_assume((pub_r001373_5_1 >= (-100)) && (pub_r001373_5_1 <= 100));
  __CPROVER_assume((pub_r001373_5_2 >= (-100)) && (pub_r001373_5_2 <= 100));
  __CPROVER_assume((pub_r001373_6_1 >= (-100)) && (pub_r001373_6_1 <= 100));
  __CPROVER_assume((pub_r001373_6_2 >= (-100)) && (pub_r001373_6_2 <= 100));
  __CPROVER_assume((pub_r001373_7_1 >= (-100)) && (pub_r001373_7_1 <= 100));
  __CPROVER_assume((pub_r001373_7_2 >= (-100)) && (pub_r001373_7_2 <= 100));
  __CPROVER_assume((pub_r001373_8_1 >= (-100)) && (pub_r001373_8_1 <= 100));
  __CPROVER_assume((pub_r001373_8_2 >= (-100)) && (pub_r001373_8_2 <= 100));
  __CPROVER_assume((pub_r001373_9_1 >= (-100)) && (pub_r001373_9_1 <= 100));
  __CPROVER_assume((pub_r001373_9_2 >= (-100)) && (pub_r001373_9_2 <= 100));
  __CPROVER_assume((pub_r001373_10_1 >= (-100)) && (pub_r001373_10_1 <= 100));
  __CPROVER_assume((pub_r001373_10_2 >= (-100)) && (pub_r001373_10_2 <= 100));
  __CPROVER_assume((pub_r001373_11_1 >= (-100)) && (pub_r001373_11_1 <= 100));
  __CPROVER_assume((pub_r001373_11_2 >= (-100)) && (pub_r001373_11_2 <= 100));
  __CPROVER_assume((pub_r001373_12_1 >= (-100)) && (pub_r001373_12_1 <= 100));
  __CPROVER_assume((pub_r001373_12_2 >= (-100)) && (pub_r001373_12_2 <= 100));
  __CPROVER_assume((pub_r001373_13_1 >= (-100)) && (pub_r001373_13_1 <= 100));
  __CPROVER_assume((pub_r001373_13_2 >= (-100)) && (pub_r001373_13_2 <= 100));
  __CPROVER_assume((pub_r001373_14_1 >= (-100)) && (pub_r001373_14_1 <= 100));
  __CPROVER_assume((pub_r001373_14_2 >= (-100)) && (pub_r001373_14_2 <= 100));
  __CPROVER_assume((pub_r001373_15_1 >= (-100)) && (pub_r001373_15_1 <= 100));
  __CPROVER_assume((pub_r001373_15_2 >= (-100)) && (pub_r001373_15_2 <= 100));
  __CPROVER_assume((pub_r001373_16_1 >= (-100)) && (pub_r001373_16_1 <= 100));
  __CPROVER_assume((pub_r001373_16_2 >= (-100)) && (pub_r001373_16_2 <= 100));
  __CPROVER_assume((pub_r001373_17_1 >= (-100)) && (pub_r001373_17_1 <= 100));
  __CPROVER_assume((pub_r001373_17_2 >= (-100)) && (pub_r001373_17_2 <= 100));
  __CPROVER_assume((pub_r001373_18_1 >= (-100)) && (pub_r001373_18_1 <= 100));
  __CPROVER_assume((pub_r001373_18_2 >= (-100)) && (pub_r001373_18_2 <= 100));
  __CPROVER_assume((pub_r001373_19_1 >= (-100)) && (pub_r001373_19_1 <= 100));
  __CPROVER_assume((pub_r001373_19_2 >= (-100)) && (pub_r001373_19_2 <= 100));
  __CPROVER_assume((sec_r001373_0_1 >= 0) && (sec_r001373_0_1 <= 255));
  __CPROVER_assume((sec_r001373_0_2 >= 0) && (sec_r001373_0_2 <= 255));
  __CPROVER_assume((sec_r001373_1_1 >= 0) && (sec_r001373_1_1 <= 255));
  __CPROVER_assume((sec_r001373_1_2 >= 0) && (sec_r001373_1_2 <= 255));
  __CPROVER_assume((sec_r001373_2_1 >= 0) && (sec_r001373_2_1 <= 255));
  __CPROVER_assume((sec_r001373_2_2 >= 0) && (sec_r001373_2_2 <= 255));
  __CPROVER_assume((sec_r001373_3_1 >= 0) && (sec_r001373_3_1 <= 255));
  __CPROVER_assume((sec_r001373_3_2 >= 0) && (sec_r001373_3_2 <= 255));
  __CPROVER_assume((sec_r001373_4_1 >= 0) && (sec_r001373_4_1 <= 255));
  __CPROVER_assume((sec_r001373_4_2 >= 0) && (sec_r001373_4_2 <= 255));
  __CPROVER_assume((sec_r001373_5_1 >= 0) && (sec_r001373_5_1 <= 255));
  __CPROVER_assume((sec_r001373_5_2 >= 0) && (sec_r001373_5_2 <= 255));
  __CPROVER_assume((sec_r001373_6_1 >= 0) && (sec_r001373_6_1 <= 255));
  __CPROVER_assume((sec_r001373_6_2 >= 0) && (sec_r001373_6_2 <= 255));
  __CPROVER_assume((sec_r001373_7_1 >= 0) && (sec_r001373_7_1 <= 255));
  __CPROVER_assume((sec_r001373_7_2 >= 0) && (sec_r001373_7_2 <= 255));
  __CPROVER_assume((sec_r001373_8_1 >= 0) && (sec_r001373_8_1 <= 255));
  __CPROVER_assume((sec_r001373_8_2 >= 0) && (sec_r001373_8_2 <= 255));
  __CPROVER_assume((sec_r001373_9_1 >= 0) && (sec_r001373_9_1 <= 255));
  __CPROVER_assume((sec_r001373_9_2 >= 0) && (sec_r001373_9_2 <= 255));
  __CPROVER_assume((sec_r001373_10_1 >= 0) && (sec_r001373_10_1 <= 255));
  __CPROVER_assume((sec_r001373_10_2 >= 0) && (sec_r001373_10_2 <= 255));
  __CPROVER_assume((sec_r001373_11_1 >= 0) && (sec_r001373_11_1 <= 255));
  __CPROVER_assume((sec_r001373_11_2 >= 0) && (sec_r001373_11_2 <= 255));
  __CPROVER_assume((sec_r001373_12_1 >= 0) && (sec_r001373_12_1 <= 255));
  __CPROVER_assume((sec_r001373_12_2 >= 0) && (sec_r001373_12_2 <= 255));
  __CPROVER_assume((sec_r001373_13_1 >= 0) && (sec_r001373_13_1 <= 255));
  __CPROVER_assume((sec_r001373_13_2 >= 0) && (sec_r001373_13_2 <= 255));
  __CPROVER_assume((sec_r001373_14_1 >= 0) && (sec_r001373_14_1 <= 255));
  __CPROVER_assume((sec_r001373_14_2 >= 0) && (sec_r001373_14_2 <= 255));
  __CPROVER_assume((sec_r001373_15_1 >= 0) && (sec_r001373_15_1 <= 255));
  __CPROVER_assume((sec_r001373_15_2 >= 0) && (sec_r001373_15_2 <= 255));
  __CPROVER_assume((sec_r001373_16_1 >= 0) && (sec_r001373_16_1 <= 255));
  __CPROVER_assume((sec_r001373_16_2 >= 0) && (sec_r001373_16_2 <= 255));
  __CPROVER_assume((sec_r001373_17_1 >= 0) && (sec_r001373_17_1 <= 255));
  __CPROVER_assume((sec_r001373_17_2 >= 0) && (sec_r001373_17_2 <= 255));
  __CPROVER_assume((sec_r001373_18_1 >= 0) && (sec_r001373_18_1 <= 255));
  __CPROVER_assume((sec_r001373_18_2 >= 0) && (sec_r001373_18_2 <= 255));
  __CPROVER_assume((sec_r001373_19_1 >= 0) && (sec_r001373_19_1 <= 255));
  __CPROVER_assume((sec_r001373_19_2 >= 0) && (sec_r001373_19_2 <= 255));
  struct DeviceConfig_R001373_7313_0 st_var_0_1 = {0};
  struct DeviceConfig_R001373_7313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001373_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001373_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001373_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001373_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001373_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001373_0_2 + 7) & 15;
  struct SensorNode_R001373_7313_1 st_var_1_1 = {0};
  struct SensorNode_R001373_7313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001373_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001373_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001373_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001373_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001373_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001373_0_2 + 9) & 15;
  union RegisterBank_R001373_7313_0 u_var_1;
  union RegisterBank_R001373_7313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001373_7313_0(sec_r001373_0_1, pub_r001373_1_1);
  int helper_flow_0_2 = fn_R001373_7313_0(sec_r001373_0_2, pub_r001373_1_2);
  fn_R001373_7313_0_2(sec_r001373_0_1, pub_r001373_1_1, sec_r001373_0_2, pub_r001373_1_2);
  int helper_flow_1_1 = fn_R001373_7313_1(sec_r001373_1_1, pub_r001373_2_1, pub_r001373_3_1, pub_r001373_4_1);
  int helper_flow_1_2 = fn_R001373_7313_1(sec_r001373_1_2, pub_r001373_2_2, pub_r001373_3_2, pub_r001373_4_2);
  fn_R001373_7313_1_2(sec_r001373_1_1, pub_r001373_2_1, pub_r001373_3_1, pub_r001373_4_1, sec_r001373_1_2, pub_r001373_2_2, pub_r001373_3_2, pub_r001373_4_2);
  int helper_flow_2_1 = fn_R001373_7313_2(sec_r001373_2_1, sec_r001373_3_1, pub_r001373_4_1);
  int helper_flow_2_2 = fn_R001373_7313_2(sec_r001373_2_2, sec_r001373_3_2, pub_r001373_4_2);
  fn_R001373_7313_2_2(sec_r001373_2_1, sec_r001373_3_1, pub_r001373_4_1, sec_r001373_2_2, sec_r001373_3_2, pub_r001373_4_2);
  int helper_flow_3_1 = fn_R001373_7313_3(sec_r001373_3_1, pub_r001373_4_1, pub_r001373_5_1, pub_r001373_6_1, pub_r001373_7_1);
  int helper_flow_3_2 = fn_R001373_7313_3(sec_r001373_3_2, pub_r001373_4_2, pub_r001373_5_2, pub_r001373_6_2, pub_r001373_7_2);
  fn_R001373_7313_3_2(sec_r001373_3_1, pub_r001373_4_1, pub_r001373_5_1, pub_r001373_6_1, pub_r001373_7_1, sec_r001373_3_2, pub_r001373_4_2, pub_r001373_5_2, pub_r001373_6_2, pub_r001373_7_2);
  int helper_flow_4_1 = fn_R001373_7313_4(sec_r001373_4_1, sec_r001373_5_1, pub_r001373_6_1);
  int helper_flow_4_2 = fn_R001373_7313_4(sec_r001373_4_2, sec_r001373_5_2, pub_r001373_6_2);
  fn_R001373_7313_4_2(sec_r001373_4_1, sec_r001373_5_1, pub_r001373_6_1, sec_r001373_4_2, sec_r001373_5_2, pub_r001373_6_2);
  int stage_v_0_1 = ((pub_r001373_4_1 * 2) + 30) & 63;
  int stage_v_0_2 = ((pub_r001373_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (((sec_r001373_10_1 * 3) + pub_r001373_10_1) + 28) & 127;
  int stage_v_1_2 = (((sec_r001373_10_2 * 3) + pub_r001373_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = (((sec_r001373_17_1 * 3) + pub_r001373_8_1) + 42) & 127;
  int stage_v_2_2 = (((sec_r001373_17_2 * 3) + pub_r001373_8_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = ((pub_r001373_11_1 * 2) + 48) & 63;
  int stage_v_3_2 = ((pub_r001373_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (((stage_v_1_1 * 3) + pub_r001373_17_1) + 25) & 127;
  int stage_v_4_2 = (((stage_v_1_2 * 3) + pub_r001373_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = ((pub_r001373_4_1 * 2) + 33) & 63;
  int stage_v_5_2 = ((pub_r001373_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001373_9_1 * 2) + 39) & 63;
  int stage_v_6_2 = ((pub_r001373_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001373_4_1 * 2) + 15) & 63;
  int stage_v_7_2 = ((pub_r001373_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (((sec_r001373_5_1 * 3) + pub_r001373_12_1) + 5) & 127;
  int stage_v_8_2 = (((sec_r001373_5_2 * 3) + pub_r001373_12_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = (((sec_r001373_15_1 * 3) + pub_r001373_12_1) + 41) & 127;
  int stage_v_9_2 = (((sec_r001373_15_2 * 3) + pub_r001373_12_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = (((stage_v_9_1 * 3) + pub_r001373_4_1) + 19) & 127;
  int stage_v_10_2 = (((stage_v_9_2 * 3) + pub_r001373_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = ((pub_r001373_18_1 * 2) + 50) & 63;
  int stage_v_11_2 = ((pub_r001373_18_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001373_5_1 * 2) + 47) & 63;
  int stage_v_12_2 = ((pub_r001373_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001373_11_1 * 2) + 38) & 63;
  int stage_v_13_2 = ((pub_r001373_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((stage_v_8_1 * 3) + pub_r001373_15_1) + 36) & 127;
  int stage_v_14_2 = (((stage_v_8_2 * 3) + pub_r001373_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = (((stage_v_2_1 * 3) + pub_r001373_5_1) + 22) & 127;
  int stage_v_15_2 = (((stage_v_2_2 * 3) + pub_r001373_5_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = ((pub_r001373_8_1 * 2) + 20) & 63;
  int stage_v_16_2 = ((pub_r001373_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (((sec_r001373_18_1 * 3) + pub_r001373_7_1) + 18) & 127;
  int stage_v_17_2 = (((sec_r001373_18_2 * 3) + pub_r001373_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = ((pub_r001373_2_1 * 2) + 27) & 63;
  int stage_v_18_2 = ((pub_r001373_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (((stage_v_1_1 * 3) + pub_r001373_17_1) + 29) & 127;
  int stage_v_19_2 = (((stage_v_1_2 * 3) + pub_r001373_17_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = ((pub_r001373_1_1 * 2) + 20) & 63;
  int stage_v_20_2 = ((pub_r001373_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001373_15_1 * 2) + 39) & 63;
  int stage_v_21_2 = ((pub_r001373_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = (((stage_v_2_1 * 3) + pub_r001373_18_1) + 44) & 127;
  int stage_v_22_2 = (((stage_v_2_2 * 3) + pub_r001373_18_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = ((pub_r001373_0_1 * 2) + 39) & 63;
  int stage_v_23_2 = ((pub_r001373_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001373_4_1 * 2) + 34) & 63;
  int stage_v_24_2 = ((pub_r001373_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001373_6_1 * 2) + 48) & 63;
  int stage_v_25_2 = ((pub_r001373_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001373_17_1 * 2) + 9) & 63;
  int stage_v_26_2 = ((pub_r001373_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001373_19_1 * 2) + 33) & 63;
  int stage_v_27_2 = ((pub_r001373_19_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((sec_r001373_14_1 * 3) + pub_r001373_5_1) + 11) & 127;
  int stage_v_28_2 = (((sec_r001373_14_2 * 3) + pub_r001373_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = ((pub_r001373_0_1 * 2) + 8) & 63;
  int stage_v_29_2 = ((pub_r001373_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((sec_r001373_5_1 * 3) + pub_r001373_18_1) + 44) & 127;
  int stage_v_30_2 = (((sec_r001373_5_2 * 3) + pub_r001373_18_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = (((stage_v_9_1 * 3) + pub_r001373_2_1) + 15) & 127;
  int stage_v_31_2 = (((stage_v_9_2 * 3) + pub_r001373_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = (((sec_r001373_18_1 * 3) + pub_r001373_19_1) + 34) & 127;
  int stage_v_32_2 = (((sec_r001373_18_2 * 3) + pub_r001373_19_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = ((pub_r001373_8_1 * 2) + 35) & 63;
  int stage_v_33_2 = ((pub_r001373_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (((sec_r001373_10_1 * 3) + pub_r001373_18_1) + 43) & 127;
  int stage_v_34_2 = (((sec_r001373_10_2 * 3) + pub_r001373_18_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = (((stage_v_8_1 * 3) + pub_r001373_10_1) + 5) & 127;
  int stage_v_35_2 = (((stage_v_8_2 * 3) + pub_r001373_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_35_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_35_2 * 2)) & 255;
  int stage_v_36_1 = ((pub_r001373_18_1 * 2) + 24) & 63;
  int stage_v_36_2 = ((pub_r001373_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (((sec_r001373_18_1 * 3) + pub_r001373_9_1) + 4) & 127;
  int stage_v_37_2 = (((sec_r001373_18_2 * 3) + pub_r001373_9_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = ((pub_r001373_17_1 * 2) + 5) & 63;
  int stage_v_38_2 = ((pub_r001373_17_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001373_12_1 * 2) + 6) & 63;
  int stage_v_39_2 = ((pub_r001373_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001373_0_1 * 2) + 24) & 63;
  int stage_v_40_2 = ((pub_r001373_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001373_13_1 * 2) + 49) & 63;
  int stage_v_41_2 = ((pub_r001373_13_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001373_13_1 * 2) + 9) & 63;
  int stage_v_42_2 = ((pub_r001373_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((sec_r001373_14_1 * 3) + pub_r001373_14_1) + 27) & 127;
  int stage_v_43_2 = (((sec_r001373_14_2 * 3) + pub_r001373_14_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = ((pub_r001373_17_1 * 2) + 48) & 63;
  int stage_v_44_2 = ((pub_r001373_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001373_9_1 * 2) + 31) & 63;
  int stage_v_45_2 = ((pub_r001373_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((sec_r001373_1_1 * 3) + pub_r001373_1_1) + 37) & 127;
  int stage_v_46_2 = (((sec_r001373_1_2 * 3) + pub_r001373_1_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = (((sec_r001373_6_1 * 3) + pub_r001373_3_1) + 21) & 127;
  int stage_v_47_2 = (((sec_r001373_6_2 * 3) + pub_r001373_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = (((stage_v_43_1 * 3) + pub_r001373_5_1) + 21) & 127;
  int stage_v_48_2 = (((stage_v_43_2 * 3) + pub_r001373_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = ((pub_r001373_4_1 * 2) + 7) & 63;
  int stage_v_49_2 = ((pub_r001373_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (((sec_r001373_15_1 * 3) + pub_r001373_2_1) + 42) & 127;
  int stage_v_50_2 = (((sec_r001373_15_2 * 3) + pub_r001373_2_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = ((pub_r001373_3_1 * 2) + 34) & 63;
  int stage_v_51_2 = ((pub_r001373_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((stage_v_1_1 * 3) + pub_r001373_12_1) + 25) & 127;
  int stage_v_52_2 = (((stage_v_1_2 * 3) + pub_r001373_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = (((stage_v_22_1 * 3) + pub_r001373_3_1) + 6) & 127;
  int stage_v_53_2 = (((stage_v_22_2 * 3) + pub_r001373_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = ((pub_r001373_13_1 * 2) + 29) & 63;
  int stage_v_54_2 = ((pub_r001373_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001373_9_1 * 2) + 30) & 63;
  int stage_v_55_2 = ((pub_r001373_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001373_2_1 * 2) + 43) & 63;
  int stage_v_56_2 = ((pub_r001373_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001373_9_1 * 2) + 11) & 63;
  int stage_v_57_2 = ((pub_r001373_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001373_19_1 * 2) + 9) & 63;
  int stage_v_58_2 = ((pub_r001373_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001373_11_1 * 2) + 41) & 63;
  int stage_v_59_2 = ((pub_r001373_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((stage_v_43_1 * 3) + pub_r001373_19_1) + 25) & 127;
  int stage_v_60_2 = (((stage_v_43_2 * 3) + pub_r001373_19_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = ((pub_r001373_12_1 * 2) + 33) & 63;
  int stage_v_61_2 = ((pub_r001373_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001373_16_1 * 2) + 26) & 63;
  int stage_v_62_2 = ((pub_r001373_16_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001373_10_1 * 2) + 28) & 63;
  int stage_v_63_2 = ((pub_r001373_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001373_8_1 * 2) + 24) & 63;
  int stage_v_64_2 = ((pub_r001373_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = (((sec_r001373_19_1 * 3) + pub_r001373_2_1) + 12) & 127;
  int stage_v_65_2 = (((sec_r001373_19_2 * 3) + pub_r001373_2_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = ((pub_r001373_13_1 * 2) + 25) & 63;
  int stage_v_66_2 = ((pub_r001373_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001373_15_1 * 2) + 13) & 63;
  int stage_v_67_2 = ((pub_r001373_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = (((stage_v_37_1 * 3) + pub_r001373_15_1) + 27) & 127;
  int stage_v_68_2 = (((stage_v_37_2 * 3) + pub_r001373_15_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = (((helper_flow_3_1 * 3) + pub_r001373_7_1) + 25) & 127;
  int stage_v_69_2 = (((helper_flow_3_2 * 3) + pub_r001373_7_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = ((pub_r001373_9_1 * 2) + 14) & 63;
  int stage_v_70_2 = ((pub_r001373_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = (((stage_v_65_1 * 3) + pub_r001373_10_1) + 37) & 127;
  int stage_v_71_2 = (((stage_v_65_2 * 3) + pub_r001373_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = ((pub_r001373_7_1 * 2) + 30) & 63;
  int stage_v_72_2 = ((pub_r001373_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001373_17_1 * 2) + 46) & 63;
  int stage_v_73_2 = ((pub_r001373_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001373_13_1 * 2) + 7) & 63;
  int stage_v_74_2 = ((pub_r001373_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (((sec_r001373_4_1 * 3) + pub_r001373_6_1) + 4) & 127;
  int stage_v_75_2 = (((sec_r001373_4_2 * 3) + pub_r001373_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = ((pub_r001373_9_1 * 2) + 28) & 63;
  int stage_v_76_2 = ((pub_r001373_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((sec_r001373_2_1 * 3) + pub_r001373_17_1) + 23) & 127;
  int stage_v_77_2 = (((sec_r001373_2_2 * 3) + pub_r001373_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = ((pub_r001373_3_1 * 2) + 13) & 63;
  int stage_v_78_2 = ((pub_r001373_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (((stage_v_4_1 * 3) + pub_r001373_12_1) + 6) & 127;
  int stage_v_79_2 = (((stage_v_4_2 * 3) + pub_r001373_12_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = ((pub_r001373_2_1 * 2) + 30) & 63;
  int stage_v_80_2 = ((pub_r001373_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001373_17_1 * 2) + 33) & 63;
  int stage_v_81_2 = ((pub_r001373_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001373_13_1 * 2) + 10) & 63;
  int stage_v_82_2 = ((pub_r001373_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (((sec_r001373_15_1 * 3) + pub_r001373_15_1) + 17) & 127;
  int stage_v_83_2 = (((sec_r001373_15_2 * 3) + pub_r001373_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = (((stage_v_28_1 * 3) + pub_r001373_8_1) + 25) & 127;
  int stage_v_84_2 = (((stage_v_28_2 * 3) + pub_r001373_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = (((stage_v_52_1 * 3) + pub_r001373_15_1) + 7) & 127;
  int stage_v_85_2 = (((stage_v_52_2 * 3) + pub_r001373_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = (((stage_v_10_1 * 3) + pub_r001373_2_1) + 27) & 127;
  int stage_v_86_2 = (((stage_v_10_2 * 3) + pub_r001373_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = ((pub_r001373_3_1 * 2) + 11) & 63;
  int stage_v_87_2 = ((pub_r001373_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((stage_v_2_1 * 3) + pub_r001373_17_1) + 29) & 127;
  int stage_v_88_2 = (((stage_v_2_2 * 3) + pub_r001373_17_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = (((stage_v_53_1 * 3) + pub_r001373_4_1) + 14) & 127;
  int stage_v_89_2 = (((stage_v_53_2 * 3) + pub_r001373_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = (((stage_v_47_1 * 3) + pub_r001373_7_1) + 37) & 127;
  int stage_v_90_2 = (((stage_v_47_2 * 3) + pub_r001373_7_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = ((pub_r001373_4_1 * 2) + 26) & 63;
  int stage_v_91_2 = ((pub_r001373_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_8_1 * 3) + pub_r001373_15_1) + 42) & 127;
  int stage_v_92_2 = (((stage_v_8_2 * 3) + pub_r001373_15_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = (((stage_v_35_1 * 3) + pub_r001373_2_1) + 18) & 127;
  int stage_v_93_2 = (((stage_v_35_2 * 3) + pub_r001373_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = (((sec_r001373_6_1 * 3) + pub_r001373_14_1) + 36) & 127;
  int stage_v_94_2 = (((sec_r001373_6_2 * 3) + pub_r001373_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = (((stage_v_69_1 * 3) + pub_r001373_7_1) + 31) & 127;
  int stage_v_95_2 = (((stage_v_69_2 * 3) + pub_r001373_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = (((stage_v_10_1 * 3) + pub_r001373_17_1) + 15) & 127;
  int stage_v_96_2 = (((stage_v_10_2 * 3) + pub_r001373_17_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = ((pub_r001373_3_1 * 2) + 6) & 63;
  int stage_v_97_2 = ((pub_r001373_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001373_3_1 * 2) + 34) & 63;
  int stage_v_98_2 = ((pub_r001373_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = (((stage_v_84_1 * 3) + pub_r001373_7_1) + 41) & 127;
  int stage_v_99_2 = (((stage_v_84_2 * 3) + pub_r001373_7_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = ((pub_r001373_3_1 * 2) + 43) & 63;
  int stage_v_100_2 = ((pub_r001373_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_96_1 * 3) + pub_r001373_7_1) + 25) & 127;
  int stage_v_101_2 = (((stage_v_96_2 * 3) + pub_r001373_7_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = (((helper_flow_2_1 * 3) + pub_r001373_15_1) + 3) & 127;
  int stage_v_102_2 = (((helper_flow_2_2 * 3) + pub_r001373_15_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = ((pub_r001373_14_1 * 2) + 46) & 63;
  int stage_v_103_2 = ((pub_r001373_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((stage_v_101_1 * 3) + pub_r001373_0_1) + 15) & 127;
  int stage_v_104_2 = (((stage_v_101_2 * 3) + pub_r001373_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = ((pub_r001373_13_1 * 2) + 47) & 63;
  int stage_v_105_2 = ((pub_r001373_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (((stage_v_32_1 * 3) + pub_r001373_6_1) + 34) & 127;
  int stage_v_106_2 = (((stage_v_32_2 * 3) + pub_r001373_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = ((pub_r001373_13_1 * 2) + 26) & 63;
  int stage_v_107_2 = ((pub_r001373_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (((stage_v_65_1 * 3) + pub_r001373_9_1) + 26) & 127;
  int stage_v_108_2 = (((stage_v_65_2 * 3) + pub_r001373_9_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = ((pub_r001373_8_1 * 2) + 34) & 63;
  int stage_v_109_2 = ((pub_r001373_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (((stage_v_34_1 * 3) + pub_r001373_17_1) + 32) & 127;
  int stage_v_110_2 = (((stage_v_34_2 * 3) + pub_r001373_17_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = ((pub_r001373_0_1 * 2) + 47) & 63;
  int stage_v_111_2 = ((pub_r001373_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (((stage_v_9_1 * 3) + pub_r001373_8_1) + 35) & 127;
  int stage_v_112_2 = (((stage_v_9_2 * 3) + pub_r001373_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = ((pub_r001373_14_1 * 2) + 18) & 63;
  int stage_v_113_2 = ((pub_r001373_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001373_18_1 * 2) + 28) & 63;
  int stage_v_114_2 = ((pub_r001373_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001373_14_1 * 2) + 32) & 63;
  int stage_v_115_2 = ((pub_r001373_14_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001373_5_1 * 2) + 26) & 63;
  int stage_v_116_2 = ((pub_r001373_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (((sec_r001373_17_1 * 3) + pub_r001373_6_1) + 3) & 127;
  int stage_v_117_2 = (((sec_r001373_17_2 * 3) + pub_r001373_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = (((sec_r001373_14_1 * 3) + pub_r001373_14_1) + 6) & 127;
  int stage_v_118_2 = (((sec_r001373_14_2 * 3) + pub_r001373_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = ((pub_r001373_16_1 * 2) + 24) & 63;
  int stage_v_119_2 = ((pub_r001373_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((stage_v_9_1 * 3) + pub_r001373_11_1) + 6) & 127;
  int stage_v_120_2 = (((stage_v_9_2 * 3) + pub_r001373_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = ((pub_r001373_2_1 * 2) + 15) & 63;
  int stage_v_121_2 = ((pub_r001373_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001373_5_1 * 2) + 15) & 63;
  int stage_v_122_2 = ((pub_r001373_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (((sec_r001373_1_1 * 3) + pub_r001373_4_1) + 11) & 127;
  int stage_v_123_2 = (((sec_r001373_1_2 * 3) + pub_r001373_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = (((stage_v_90_1 * 3) + pub_r001373_17_1) + 44) & 127;
  int stage_v_124_2 = (((stage_v_90_2 * 3) + pub_r001373_17_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = ((pub_r001373_11_1 * 2) + 35) & 63;
  int stage_v_125_2 = ((pub_r001373_11_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((sec_r001373_0_1 * 3) + pub_r001373_0_1) + 3) & 127;
  int stage_v_126_2 = (((sec_r001373_0_2 * 3) + pub_r001373_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = ((pub_r001373_2_1 * 2) + 50) & 63;
  int stage_v_127_2 = ((pub_r001373_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001373_3_1 * 2) + 27) & 63;
  int stage_v_128_2 = ((pub_r001373_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001373_10_1 * 2) + 50) & 63;
  int stage_v_129_2 = ((pub_r001373_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001373_14_1 * 2) + 15) & 63;
  int stage_v_130_2 = ((pub_r001373_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001373_0_1 * 2) + 40) & 63;
  int stage_v_131_2 = ((pub_r001373_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (((stage_v_88_1 * 3) + pub_r001373_16_1) + 8) & 127;
  int stage_v_132_2 = (((stage_v_88_2 * 3) + pub_r001373_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = (((stage_v_71_1 * 3) + pub_r001373_5_1) + 42) & 127;
  int stage_v_133_2 = (((stage_v_71_2 * 3) + pub_r001373_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = ((pub_r001373_3_1 * 2) + 49) & 63;
  int stage_v_134_2 = ((pub_r001373_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (((stage_v_15_1 * 3) + pub_r001373_5_1) + 23) & 127;
  int stage_v_135_2 = (((stage_v_15_2 * 3) + pub_r001373_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = (((stage_v_93_1 * 3) + pub_r001373_19_1) + 38) & 127;
  int stage_v_136_2 = (((stage_v_93_2 * 3) + pub_r001373_19_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = (((stage_v_46_1 * 3) + pub_r001373_3_1) + 6) & 127;
  int stage_v_137_2 = (((stage_v_46_2 * 3) + pub_r001373_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = ((pub_r001373_0_1 * 2) + 12) & 63;
  int stage_v_138_2 = ((pub_r001373_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001373_8_1 * 2) + 16) & 63;
  int stage_v_139_2 = ((pub_r001373_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001373_2_1 * 2) + 18) & 63;
  int stage_v_140_2 = ((pub_r001373_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001373_3_1 * 2) + 13) & 63;
  int stage_v_141_2 = ((pub_r001373_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (((stage_v_135_1 * 3) + pub_r001373_9_1) + 36) & 127;
  int stage_v_142_2 = (((stage_v_135_2 * 3) + pub_r001373_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = ((pub_r001373_15_1 * 2) + 9) & 63;
  int stage_v_143_2 = ((pub_r001373_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (((stage_v_142_1 * 3) + pub_r001373_7_1) + 38) & 127;
  int stage_v_144_2 = (((stage_v_142_2 * 3) + pub_r001373_7_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = (((stage_v_69_1 * 3) + pub_r001373_3_1) + 25) & 127;
  int stage_v_145_2 = (((stage_v_69_2 * 3) + pub_r001373_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = ((pub_r001373_4_1 * 2) + 11) & 63;
  int stage_v_146_2 = ((pub_r001373_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001373_10_1 * 2) + 44) & 63;
  int stage_v_147_2 = ((pub_r001373_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_96_1 * 3) + pub_r001373_9_1) + 45) & 127;
  int stage_v_148_2 = (((stage_v_96_2 * 3) + pub_r001373_9_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = (((sec_r001373_7_1 * 3) + pub_r001373_7_1) + 39) & 127;
  int stage_v_149_2 = (((sec_r001373_7_2 * 3) + pub_r001373_7_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = ((pub_r001373_1_1 * 2) + 16) & 63;
  int stage_v_150_2 = ((pub_r001373_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = (((stage_v_89_1 * 3) + pub_r001373_16_1) + 14) & 127;
  int stage_v_151_2 = (((stage_v_89_2 * 3) + pub_r001373_16_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = (((stage_v_19_1 * 3) + pub_r001373_15_1) + 32) & 127;
  int stage_v_152_2 = (((stage_v_19_2 * 3) + pub_r001373_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = ((pub_r001373_4_1 * 2) + 41) & 63;
  int stage_v_153_2 = ((pub_r001373_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((helper_flow_3_1 * 3) + pub_r001373_1_1) + 18) & 127;
  int stage_v_154_2 = (((helper_flow_3_2 * 3) + pub_r001373_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = (((stage_v_101_1 * 3) + pub_r001373_7_1) + 16) & 127;
  int stage_v_155_2 = (((stage_v_101_2 * 3) + pub_r001373_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = (((stage_v_1_1 * 3) + pub_r001373_2_1) + 4) & 127;
  int stage_v_156_2 = (((stage_v_1_2 * 3) + pub_r001373_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((stage_v_132_1 * 3) + pub_r001373_16_1) + 41) & 127;
  int stage_v_157_2 = (((stage_v_132_2 * 3) + pub_r001373_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = (((stage_v_144_1 * 3) + pub_r001373_4_1) + 23) & 127;
  int stage_v_158_2 = (((stage_v_144_2 * 3) + pub_r001373_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = (((stage_v_102_1 * 3) + pub_r001373_14_1) + 17) & 127;
  int stage_v_159_2 = (((stage_v_102_2 * 3) + pub_r001373_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = (((stage_v_104_1 * 3) + pub_r001373_18_1) + 32) & 127;
  int stage_v_160_2 = (((stage_v_104_2 * 3) + pub_r001373_18_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = (((sec_r001373_16_1 * 3) + pub_r001373_19_1) + 30) & 127;
  int stage_v_161_2 = (((sec_r001373_16_2 * 3) + pub_r001373_19_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = ((pub_r001373_16_1 * 2) + 12) & 63;
  int stage_v_162_2 = ((pub_r001373_16_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001373_18_1 * 2) + 30) & 63;
  int stage_v_163_2 = ((pub_r001373_18_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (((stage_v_48_1 * 3) + pub_r001373_13_1) + 37) & 127;
  int stage_v_164_2 = (((stage_v_48_2 * 3) + pub_r001373_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = ((pub_r001373_14_1 * 2) + 23) & 63;
  int stage_v_165_2 = ((pub_r001373_14_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001373_4_1 * 2) + 35) & 63;
  int stage_v_166_2 = ((pub_r001373_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((stage_v_14_1 * 3) + pub_r001373_1_1) + 34) & 127;
  int stage_v_167_2 = (((stage_v_14_2 * 3) + pub_r001373_1_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = (((stage_v_48_1 * 3) + pub_r001373_2_1) + 27) & 127;
  int stage_v_168_2 = (((stage_v_48_2 * 3) + pub_r001373_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = (((stage_v_83_1 * 3) + pub_r001373_16_1) + 25) & 127;
  int stage_v_169_2 = (((stage_v_83_2 * 3) + pub_r001373_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = (((sec_r001373_1_1 * 3) + pub_r001373_0_1) + 42) & 127;
  int stage_v_170_2 = (((sec_r001373_1_2 * 3) + pub_r001373_0_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = (((stage_v_30_1 * 3) + pub_r001373_8_1) + 13) & 127;
  int stage_v_171_2 = (((stage_v_30_2 * 3) + pub_r001373_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = ((pub_r001373_13_1 * 2) + 44) & 63;
  int stage_v_172_2 = ((pub_r001373_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (((stage_v_126_1 * 3) + pub_r001373_19_1) + 13) & 127;
  int stage_v_173_2 = (((stage_v_126_2 * 3) + pub_r001373_19_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = ((pub_r001373_19_1 * 2) + 41) & 63;
  int stage_v_174_2 = ((pub_r001373_19_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((stage_v_94_1 * 3) + pub_r001373_11_1) + 23) & 127;
  int stage_v_175_2 = (((stage_v_94_2 * 3) + pub_r001373_11_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = (((sec_r001373_1_1 * 3) + pub_r001373_4_1) + 39) & 127;
  int stage_v_176_2 = (((sec_r001373_1_2 * 3) + pub_r001373_4_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = (((helper_flow_3_1 * 3) + pub_r001373_16_1) + 15) & 127;
  int stage_v_177_2 = (((helper_flow_3_2 * 3) + pub_r001373_16_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = (((sec_r001373_1_1 * 3) + pub_r001373_9_1) + 8) & 127;
  int stage_v_178_2 = (((sec_r001373_1_2 * 3) + pub_r001373_9_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = ((pub_r001373_5_1 * 2) + 20) & 63;
  int stage_v_179_2 = ((pub_r001373_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001373_16_1 * 2) + 22) & 63;
  int stage_v_180_2 = ((pub_r001373_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001373_10_1 * 2) + 7) & 63;
  int stage_v_181_2 = ((pub_r001373_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((stage_v_154_1 * 3) + pub_r001373_8_1) + 8) & 127;
  int stage_v_182_2 = (((stage_v_154_2 * 3) + pub_r001373_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = ((pub_r001373_9_1 * 2) + 5) & 63;
  int stage_v_183_2 = ((pub_r001373_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (((stage_v_35_1 * 3) + pub_r001373_2_1) + 39) & 127;
  int stage_v_184_2 = (((stage_v_35_2 * 3) + pub_r001373_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = (((stage_v_92_1 * 3) + pub_r001373_1_1) + 13) & 127;
  int stage_v_185_2 = (((stage_v_92_2 * 3) + pub_r001373_1_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = ((pub_r001373_19_1 * 2) + 37) & 63;
  int stage_v_186_2 = ((pub_r001373_19_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001373_6_1 * 2) + 17) & 63;
  int stage_v_187_2 = ((pub_r001373_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001373_7_1 * 2) + 28) & 63;
  int stage_v_188_2 = ((pub_r001373_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001373_6_1 * 2) + 9) & 63;
  int stage_v_189_2 = ((pub_r001373_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((sec_r001373_11_1 * 3) + pub_r001373_5_1) + 19) & 127;
  int stage_v_190_2 = (((sec_r001373_11_2 * 3) + pub_r001373_5_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = (((stage_v_17_1 * 3) + pub_r001373_6_1) + 15) & 127;
  int stage_v_191_2 = (((stage_v_17_2 * 3) + pub_r001373_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = (((stage_v_169_1 * 3) + pub_r001373_10_1) + 15) & 127;
  int stage_v_192_2 = (((stage_v_169_2 * 3) + pub_r001373_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = ((pub_r001373_0_1 * 2) + 26) & 63;
  int stage_v_193_2 = ((pub_r001373_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = (((stage_v_102_1 * 3) + pub_r001373_6_1) + 31) & 127;
  int stage_v_194_2 = (((stage_v_102_2 * 3) + pub_r001373_6_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = (((stage_v_149_1 * 3) + pub_r001373_8_1) + 41) & 127;
  int stage_v_195_2 = (((stage_v_149_2 * 3) + pub_r001373_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = (((stage_v_65_1 * 3) + pub_r001373_7_1) + 20) & 127;
  int stage_v_196_2 = (((stage_v_65_2 * 3) + pub_r001373_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = ((pub_r001373_12_1 * 2) + 11) & 63;
  int stage_v_197_2 = ((pub_r001373_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((stage_v_191_1 * 3) + pub_r001373_3_1) + 17) & 127;
  int stage_v_198_2 = (((stage_v_191_2 * 3) + pub_r001373_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = ((pub_r001373_19_1 * 2) + 30) & 63;
  int stage_v_199_2 = ((pub_r001373_19_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = (((stage_v_118_1 * 3) + pub_r001373_10_1) + 4) & 127;
  int stage_v_200_2 = (((stage_v_118_2 * 3) + pub_r001373_10_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = ((pub_r001373_16_1 * 2) + 31) & 63;
  int stage_v_201_2 = ((pub_r001373_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((stage_v_10_1 * 3) + pub_r001373_11_1) + 29) & 127;
  int stage_v_202_2 = (((stage_v_10_2 * 3) + pub_r001373_11_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = (((stage_v_194_1 * 3) + pub_r001373_11_1) + 37) & 127;
  int stage_v_203_2 = (((stage_v_194_2 * 3) + pub_r001373_11_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = (((stage_v_8_1 * 3) + pub_r001373_13_1) + 31) & 127;
  int stage_v_204_2 = (((stage_v_8_2 * 3) + pub_r001373_13_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = (((stage_v_135_1 * 3) + pub_r001373_5_1) + 35) & 127;
  int stage_v_205_2 = (((stage_v_135_2 * 3) + pub_r001373_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = ((pub_r001373_18_1 * 2) + 31) & 63;
  int stage_v_206_2 = ((pub_r001373_18_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001373_7_1 * 2) + 50) & 63;
  int stage_v_207_2 = ((pub_r001373_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001373_3_1 * 2) + 39) & 63;
  int stage_v_208_2 = ((pub_r001373_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = (((stage_v_133_1 * 3) + pub_r001373_13_1) + 3) & 127;
  int stage_v_209_2 = (((stage_v_133_2 * 3) + pub_r001373_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = ((pub_r001373_17_1 * 2) + 42) & 63;
  int stage_v_210_2 = ((pub_r001373_17_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001373_18_1 * 2) + 50) & 63;
  int stage_v_211_2 = ((pub_r001373_18_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = (((stage_v_1_1 * 3) + pub_r001373_11_1) + 9) & 127;
  int stage_v_212_2 = (((stage_v_1_2 * 3) + pub_r001373_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = (((helper_flow_0_1 * 3) + pub_r001373_6_1) + 22) & 127;
  int stage_v_213_2 = (((helper_flow_0_2 * 3) + pub_r001373_6_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = ((pub_r001373_5_1 * 2) + 18) & 63;
  int stage_v_214_2 = ((pub_r001373_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((stage_v_34_1 * 3) + pub_r001373_0_1) + 13) & 127;
  int stage_v_215_2 = (((stage_v_34_2 * 3) + pub_r001373_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = ((pub_r001373_10_1 * 2) + 43) & 63;
  int stage_v_216_2 = ((pub_r001373_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001373_8_1 * 2) + 35) & 63;
  int stage_v_217_2 = ((pub_r001373_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001373_14_1 * 2) + 31) & 63;
  int stage_v_218_2 = ((pub_r001373_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = (((stage_v_133_1 * 3) + pub_r001373_7_1) + 5) & 127;
  int stage_v_219_2 = (((stage_v_133_2 * 3) + pub_r001373_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = ((pub_r001373_11_1 * 2) + 34) & 63;
  int stage_v_220_2 = ((pub_r001373_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = (((helper_flow_4_1 * 3) + pub_r001373_4_1) + 11) & 127;
  int stage_v_221_2 = (((helper_flow_4_2 * 3) + pub_r001373_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = ((pub_r001373_11_1 * 2) + 10) & 63;
  int stage_v_222_2 = ((pub_r001373_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = (((stage_v_132_1 * 3) + pub_r001373_16_1) + 5) & 127;
  int stage_v_223_2 = (((stage_v_132_2 * 3) + pub_r001373_16_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = (((stage_v_68_1 * 3) + pub_r001373_15_1) + 45) & 127;
  int stage_v_224_2 = (((stage_v_68_2 * 3) + pub_r001373_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = ((pub_r001373_0_1 * 2) + 7) & 63;
  int stage_v_225_2 = ((pub_r001373_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001373_18_1 * 2) + 13) & 63;
  int stage_v_226_2 = ((pub_r001373_18_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = (((sec_r001373_3_1 * 3) + pub_r001373_9_1) + 32) & 127;
  int stage_v_227_2 = (((sec_r001373_3_2 * 3) + pub_r001373_9_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = (((stage_v_175_1 * 3) + pub_r001373_19_1) + 16) & 127;
  int stage_v_228_2 = (((stage_v_175_2 * 3) + pub_r001373_19_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = ((pub_r001373_3_1 * 2) + 47) & 63;
  int stage_v_229_2 = ((pub_r001373_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001373_8_1 * 2) + 37) & 63;
  int stage_v_230_2 = ((pub_r001373_8_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = (((stage_v_173_1 * 3) + pub_r001373_16_1) + 3) & 127;
  int stage_v_231_2 = (((stage_v_173_2 * 3) + pub_r001373_16_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = (((stage_v_142_1 * 3) + pub_r001373_2_1) + 17) & 127;
  int stage_v_232_2 = (((stage_v_142_2 * 3) + pub_r001373_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = ((pub_r001373_15_1 * 2) + 8) & 63;
  int stage_v_233_2 = ((pub_r001373_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = (((stage_v_126_1 * 3) + pub_r001373_3_1) + 30) & 127;
  int stage_v_234_2 = (((stage_v_126_2 * 3) + pub_r001373_3_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = (((stage_v_176_1 * 3) + pub_r001373_15_1) + 21) & 127;
  int stage_v_235_2 = (((stage_v_176_2 * 3) + pub_r001373_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = (((stage_v_65_1 * 3) + pub_r001373_11_1) + 33) & 127;
  int stage_v_236_2 = (((stage_v_65_2 * 3) + pub_r001373_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = (((stage_v_205_1 * 3) + pub_r001373_1_1) + 37) & 127;
  int stage_v_237_2 = (((stage_v_205_2 * 3) + pub_r001373_1_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_237_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_237_2 * 2)) & 255;
  int stage_v_238_1 = (((stage_v_10_1 * 3) + pub_r001373_17_1) + 23) & 127;
  int stage_v_238_2 = (((stage_v_10_2 * 3) + pub_r001373_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = ((pub_r001373_2_1 * 2) + 43) & 63;
  int stage_v_239_2 = ((pub_r001373_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = (((stage_v_236_1 * 3) + pub_r001373_18_1) + 34) & 127;
  int stage_v_240_2 = (((stage_v_236_2 * 3) + pub_r001373_18_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = (((stage_v_136_1 * 3) + pub_r001373_0_1) + 7) & 127;
  int stage_v_241_2 = (((stage_v_136_2 * 3) + pub_r001373_0_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = (((stage_v_86_1 * 3) + pub_r001373_15_1) + 23) & 127;
  int stage_v_242_2 = (((stage_v_86_2 * 3) + pub_r001373_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = (((stage_v_43_1 * 3) + pub_r001373_11_1) + 38) & 127;
  int stage_v_243_2 = (((stage_v_43_2 * 3) + pub_r001373_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = (((stage_v_192_1 * 3) + pub_r001373_17_1) + 18) & 127;
  int stage_v_244_2 = (((stage_v_192_2 * 3) + pub_r001373_17_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = (((stage_v_175_1 * 3) + pub_r001373_3_1) + 38) & 127;
  int stage_v_245_2 = (((stage_v_175_2 * 3) + pub_r001373_3_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = (((helper_flow_3_1 * 3) + pub_r001373_5_1) + 20) & 127;
  int stage_v_246_2 = (((helper_flow_3_2 * 3) + pub_r001373_5_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = ((pub_r001373_12_1 * 2) + 23) & 63;
  int stage_v_247_2 = ((pub_r001373_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = (((stage_v_185_1 * 3) + pub_r001373_13_1) + 10) & 127;
  int stage_v_248_2 = (((stage_v_185_2 * 3) + pub_r001373_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = ((pub_r001373_12_1 * 2) + 17) & 63;
  int stage_v_249_2 = ((pub_r001373_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001373_18_1 * 2) + 24) & 63;
  int stage_v_250_2 = ((pub_r001373_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001373_2_1 * 2) + 31) & 63;
  int stage_v_251_2 = ((pub_r001373_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((pub_r001373_9_1 * 2) + 7) & 63;
  int stage_v_252_2 = ((pub_r001373_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = (((stage_v_243_1 * 3) + pub_r001373_8_1) + 23) & 127;
  int stage_v_253_2 = (((stage_v_243_2 * 3) + pub_r001373_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = ((pub_r001373_5_1 * 2) + 15) & 63;
  int stage_v_254_2 = ((pub_r001373_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = (((sec_r001373_5_1 * 3) + pub_r001373_11_1) + 18) & 127;
  int stage_v_255_2 = (((sec_r001373_5_2 * 3) + pub_r001373_11_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = ((pub_r001373_17_1 * 2) + 14) & 63;
  int stage_v_256_2 = ((pub_r001373_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001373_8_1 * 2) + 11) & 63;
  int stage_v_257_2 = ((pub_r001373_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((sec_r001373_13_1 * 3) + pub_r001373_11_1) + 29) & 127;
  int stage_v_258_2 = (((sec_r001373_13_2 * 3) + pub_r001373_11_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = ((pub_r001373_0_1 * 2) + 28) & 63;
  int stage_v_259_2 = ((pub_r001373_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001373_10_1 * 2) + 20) & 63;
  int stage_v_260_2 = ((pub_r001373_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = (((stage_v_75_1 * 3) + pub_r001373_7_1) + 30) & 127;
  int stage_v_261_2 = (((stage_v_75_2 * 3) + pub_r001373_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = (((stage_v_242_1 * 3) + pub_r001373_14_1) + 31) & 127;
  int stage_v_262_2 = (((stage_v_242_2 * 3) + pub_r001373_14_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_262_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_262_2 * 2)) & 255;
  int stage_v_263_1 = ((pub_r001373_11_1 * 2) + 15) & 63;
  int stage_v_263_2 = ((pub_r001373_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = (((stage_v_198_1 * 3) + pub_r001373_5_1) + 7) & 127;
  int stage_v_264_2 = (((stage_v_198_2 * 3) + pub_r001373_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = (((stage_v_209_1 * 3) + pub_r001373_2_1) + 35) & 127;
  int stage_v_265_2 = (((stage_v_209_2 * 3) + pub_r001373_2_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = (((stage_v_83_1 * 3) + pub_r001373_10_1) + 19) & 127;
  int stage_v_266_2 = (((stage_v_83_2 * 3) + pub_r001373_10_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = ((pub_r001373_9_1 * 2) + 42) & 63;
  int stage_v_267_2 = ((pub_r001373_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = (((stage_v_234_1 * 3) + pub_r001373_19_1) + 10) & 127;
  int stage_v_268_2 = (((stage_v_234_2 * 3) + pub_r001373_19_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = (((stage_v_246_1 * 3) + pub_r001373_14_1) + 10) & 127;
  int stage_v_269_2 = (((stage_v_246_2 * 3) + pub_r001373_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = (((stage_v_205_1 * 3) + pub_r001373_13_1) + 31) & 127;
  int stage_v_270_2 = (((stage_v_205_2 * 3) + pub_r001373_13_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = (((stage_v_190_1 * 3) + pub_r001373_7_1) + 30) & 127;
  int stage_v_271_2 = (((stage_v_190_2 * 3) + pub_r001373_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = (((stage_v_236_1 * 3) + pub_r001373_4_1) + 28) & 127;
  int stage_v_272_2 = (((stage_v_236_2 * 3) + pub_r001373_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = (((stage_v_137_1 * 3) + pub_r001373_14_1) + 11) & 127;
  int stage_v_273_2 = (((stage_v_137_2 * 3) + pub_r001373_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = (((stage_v_99_1 * 3) + pub_r001373_7_1) + 18) & 127;
  int stage_v_274_2 = (((stage_v_99_2 * 3) + pub_r001373_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = (((stage_v_142_1 * 3) + pub_r001373_10_1) + 35) & 127;
  int stage_v_275_2 = (((stage_v_142_2 * 3) + pub_r001373_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = ((pub_r001373_9_1 * 2) + 47) & 63;
  int stage_v_276_2 = ((pub_r001373_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = (((stage_v_124_1 * 3) + pub_r001373_9_1) + 6) & 127;
  int stage_v_277_2 = (((stage_v_124_2 * 3) + pub_r001373_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = ((pub_r001373_14_1 * 2) + 17) & 63;
  int stage_v_278_2 = ((pub_r001373_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((pub_r001373_16_1 * 2) + 25) & 63;
  int stage_v_279_2 = ((pub_r001373_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001373_4_1 * 2) + 16) & 63;
  int stage_v_280_2 = ((pub_r001373_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((pub_r001373_10_1 * 2) + 40) & 63;
  int stage_v_281_2 = ((pub_r001373_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = (((stage_v_268_1 * 3) + pub_r001373_13_1) + 30) & 127;
  int stage_v_282_2 = (((stage_v_268_2 * 3) + pub_r001373_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = (((stage_v_255_1 * 3) + pub_r001373_11_1) + 7) & 127;
  int stage_v_283_2 = (((stage_v_255_2 * 3) + pub_r001373_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = ((pub_r001373_11_1 * 2) + 12) & 63;
  int stage_v_284_2 = ((pub_r001373_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = (((stage_v_84_1 * 3) + pub_r001373_6_1) + 7) & 127;
  int stage_v_285_2 = (((stage_v_84_2 * 3) + pub_r001373_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = ((pub_r001373_9_1 * 2) + 22) & 63;
  int stage_v_286_2 = ((pub_r001373_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((pub_r001373_14_1 * 2) + 8) & 63;
  int stage_v_287_2 = ((pub_r001373_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((pub_r001373_4_1 * 2) + 33) & 63;
  int stage_v_288_2 = ((pub_r001373_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((pub_r001373_17_1 * 2) + 33) & 63;
  int stage_v_289_2 = ((pub_r001373_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((pub_r001373_9_1 * 2) + 27) & 63;
  int stage_v_290_2 = ((pub_r001373_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = ((pub_r001373_2_1 * 2) + 16) & 63;
  int stage_v_291_2 = ((pub_r001373_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((pub_r001373_19_1 * 2) + 41) & 63;
  int stage_v_292_2 = ((pub_r001373_19_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001373_13_1 * 2) + 15) & 63;
  int stage_v_293_2 = ((pub_r001373_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = (((stage_v_9_1 * 3) + pub_r001373_16_1) + 38) & 127;
  int stage_v_294_2 = (((stage_v_9_2 * 3) + pub_r001373_16_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = ((pub_r001373_7_1 * 2) + 13) & 63;
  int stage_v_295_2 = ((pub_r001373_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = (((stage_v_50_1 * 3) + pub_r001373_1_1) + 39) & 127;
  int stage_v_296_2 = (((stage_v_50_2 * 3) + pub_r001373_1_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = (((helper_flow_2_1 * 3) + pub_r001373_0_1) + 16) & 127;
  int stage_v_297_2 = (((helper_flow_2_2 * 3) + pub_r001373_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = (((sec_r001373_18_1 * 3) + pub_r001373_8_1) + 21) & 127;
  int stage_v_298_2 = (((sec_r001373_18_2 * 3) + pub_r001373_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = ((pub_r001373_8_1 * 2) + 9) & 63;
  int stage_v_299_2 = ((pub_r001373_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((pub_r001373_7_1 * 2) + 32) & 63;
  int stage_v_300_2 = ((pub_r001373_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001373_14_1 * 2) + 37) & 63;
  int stage_v_301_2 = ((pub_r001373_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001373_17_1 * 2) + 40) & 63;
  int stage_v_302_2 = ((pub_r001373_17_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = (((stage_v_243_1 * 3) + pub_r001373_15_1) + 36) & 127;
  int stage_v_303_2 = (((stage_v_243_2 * 3) + pub_r001373_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = (((stage_v_28_1 * 3) + pub_r001373_13_1) + 3) & 127;
  int stage_v_304_2 = (((stage_v_28_2 * 3) + pub_r001373_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = ((pub_r001373_14_1 * 2) + 9) & 63;
  int stage_v_305_2 = ((pub_r001373_14_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001373_3_1 * 2) + 30) & 63;
  int stage_v_306_2 = ((pub_r001373_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = (((stage_v_170_1 * 3) + pub_r001373_4_1) + 15) & 127;
  int stage_v_307_2 = (((stage_v_170_2 * 3) + pub_r001373_4_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = (((stage_v_152_1 * 3) + pub_r001373_4_1) + 30) & 127;
  int stage_v_308_2 = (((stage_v_152_2 * 3) + pub_r001373_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = ((pub_r001373_5_1 * 2) + 10) & 63;
  int stage_v_309_2 = ((pub_r001373_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001373_7_1 * 2) + 13) & 63;
  int stage_v_310_2 = ((pub_r001373_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((pub_r001373_10_1 * 2) + 33) & 63;
  int stage_v_311_2 = ((pub_r001373_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = (((stage_v_185_1 * 3) + pub_r001373_3_1) + 25) & 127;
  int stage_v_312_2 = (((stage_v_185_2 * 3) + pub_r001373_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = ((pub_r001373_18_1 * 2) + 28) & 63;
  int stage_v_313_2 = ((pub_r001373_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = (((stage_v_135_1 * 3) + pub_r001373_12_1) + 12) & 127;
  int stage_v_314_2 = (((stage_v_135_2 * 3) + pub_r001373_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = ((pub_r001373_4_1 * 2) + 34) & 63;
  int stage_v_315_2 = ((pub_r001373_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = (((sec_r001373_5_1 * 3) + pub_r001373_19_1) + 41) & 127;
  int stage_v_316_2 = (((sec_r001373_5_2 * 3) + pub_r001373_19_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = ((pub_r001373_8_1 * 2) + 31) & 63;
  int stage_v_317_2 = ((pub_r001373_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = (((stage_v_90_1 * 3) + pub_r001373_3_1) + 6) & 127;
  int stage_v_318_2 = (((stage_v_90_2 * 3) + pub_r001373_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = ((pub_r001373_15_1 * 2) + 43) & 63;
  int stage_v_319_2 = ((pub_r001373_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((pub_r001373_10_1 * 2) + 34) & 63;
  int stage_v_320_2 = ((pub_r001373_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = (((sec_r001373_6_1 * 3) + pub_r001373_16_1) + 13) & 127;
  int stage_v_321_2 = (((sec_r001373_6_2 * 3) + pub_r001373_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = (((stage_v_30_1 * 3) + pub_r001373_19_1) + 22) & 127;
  int stage_v_322_2 = (((stage_v_30_2 * 3) + pub_r001373_19_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = ((pub_r001373_4_1 * 2) + 7) & 63;
  int stage_v_323_2 = ((pub_r001373_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = (((stage_v_156_1 * 3) + pub_r001373_2_1) + 4) & 127;
  int stage_v_324_2 = (((stage_v_156_2 * 3) + pub_r001373_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = ((pub_r001373_6_1 * 2) + 50) & 63;
  int stage_v_325_2 = ((pub_r001373_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = (((stage_v_312_1 * 3) + pub_r001373_2_1) + 41) & 127;
  int stage_v_326_2 = (((stage_v_312_2 * 3) + pub_r001373_2_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = ((pub_r001373_16_1 * 2) + 34) & 63;
  int stage_v_327_2 = ((pub_r001373_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((pub_r001373_13_1 * 2) + 39) & 63;
  int stage_v_328_2 = ((pub_r001373_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001373_13_1 * 2) + 23) & 63;
  int stage_v_329_2 = ((pub_r001373_13_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001373_2_1 * 2) + 50) & 63;
  int stage_v_330_2 = ((pub_r001373_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001373_12_1 * 2) + 30) & 63;
  int stage_v_331_2 = ((pub_r001373_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = (((stage_v_275_1 * 3) + pub_r001373_10_1) + 31) & 127;
  int stage_v_332_2 = (((stage_v_275_2 * 3) + pub_r001373_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = (((stage_v_94_1 * 3) + pub_r001373_12_1) + 36) & 127;
  int stage_v_333_2 = (((stage_v_94_2 * 3) + pub_r001373_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = ((pub_r001373_13_1 * 2) + 35) & 63;
  int stage_v_334_2 = ((pub_r001373_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((pub_r001373_12_1 * 2) + 27) & 63;
  int stage_v_335_2 = ((pub_r001373_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((pub_r001373_17_1 * 2) + 27) & 63;
  int stage_v_336_2 = ((pub_r001373_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = (((stage_v_86_1 * 3) + pub_r001373_8_1) + 7) & 127;
  int stage_v_337_2 = (((stage_v_86_2 * 3) + pub_r001373_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = ((pub_r001373_10_1 * 2) + 29) & 63;
  int stage_v_338_2 = ((pub_r001373_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = ((pub_r001373_1_1 * 2) + 9) & 63;
  int stage_v_339_2 = ((pub_r001373_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((pub_r001373_8_1 * 2) + 44) & 63;
  int stage_v_340_2 = ((pub_r001373_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = (((stage_v_173_1 * 3) + pub_r001373_17_1) + 3) & 127;
  int stage_v_341_2 = (((stage_v_173_2 * 3) + pub_r001373_17_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = ((pub_r001373_14_1 * 2) + 22) & 63;
  int stage_v_342_2 = ((pub_r001373_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = (((stage_v_34_1 * 3) + pub_r001373_11_1) + 34) & 127;
  int stage_v_343_2 = (((stage_v_34_2 * 3) + pub_r001373_11_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = (((stage_v_88_1 * 3) + pub_r001373_14_1) + 40) & 127;
  int stage_v_344_2 = (((stage_v_88_2 * 3) + pub_r001373_14_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = (((stage_v_282_1 * 3) + pub_r001373_7_1) + 4) & 127;
  int stage_v_345_2 = (((stage_v_282_2 * 3) + pub_r001373_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = ((pub_r001373_1_1 * 2) + 45) & 63;
  int stage_v_346_2 = ((pub_r001373_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((pub_r001373_18_1 * 2) + 27) & 63;
  int stage_v_347_2 = ((pub_r001373_18_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = (((stage_v_89_1 * 3) + pub_r001373_3_1) + 14) & 127;
  int stage_v_348_2 = (((stage_v_89_2 * 3) + pub_r001373_3_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = (((stage_v_221_1 * 3) + pub_r001373_7_1) + 10) & 127;
  int stage_v_349_2 = (((stage_v_221_2 * 3) + pub_r001373_7_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = ((pub_r001373_4_1 * 2) + 14) & 63;
  int stage_v_350_2 = ((pub_r001373_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = (((stage_v_168_1 * 3) + pub_r001373_5_1) + 5) & 127;
  int stage_v_351_2 = (((stage_v_168_2 * 3) + pub_r001373_5_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = (((stage_v_269_1 * 3) + pub_r001373_10_1) + 43) & 127;
  int stage_v_352_2 = (((stage_v_269_2 * 3) + pub_r001373_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = (((stage_v_136_1 * 3) + pub_r001373_4_1) + 28) & 127;
  int stage_v_353_2 = (((stage_v_136_2 * 3) + pub_r001373_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = ((pub_r001373_6_1 * 2) + 8) & 63;
  int stage_v_354_2 = ((pub_r001373_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = (((helper_flow_4_1 * 3) + pub_r001373_12_1) + 45) & 127;
  int stage_v_355_2 = (((helper_flow_4_2 * 3) + pub_r001373_12_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = (((stage_v_303_1 * 3) + pub_r001373_8_1) + 34) & 127;
  int stage_v_356_2 = (((stage_v_303_2 * 3) + pub_r001373_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = ((pub_r001373_1_1 * 2) + 32) & 63;
  int stage_v_357_2 = ((pub_r001373_1_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = (((stage_v_158_1 * 3) + pub_r001373_19_1) + 35) & 127;
  int stage_v_358_2 = (((stage_v_158_2 * 3) + pub_r001373_19_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = ((pub_r001373_2_1 * 2) + 48) & 63;
  int stage_v_359_2 = ((pub_r001373_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = (((stage_v_34_1 * 3) + pub_r001373_19_1) + 28) & 127;
  int stage_v_360_2 = (((stage_v_34_2 * 3) + pub_r001373_19_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = (((stage_v_307_1 * 3) + pub_r001373_13_1) + 20) & 127;
  int stage_v_361_2 = (((stage_v_307_2 * 3) + pub_r001373_13_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = (((stage_v_209_1 * 3) + pub_r001373_6_1) + 35) & 127;
  int stage_v_362_2 = (((stage_v_209_2 * 3) + pub_r001373_6_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_362_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_362_2 * 2)) & 255;
  int stage_v_363_1 = (((stage_v_232_1 * 3) + pub_r001373_3_1) + 8) & 127;
  int stage_v_363_2 = (((stage_v_232_2 * 3) + pub_r001373_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = (((stage_v_196_1 * 3) + pub_r001373_14_1) + 27) & 127;
  int stage_v_364_2 = (((stage_v_196_2 * 3) + pub_r001373_14_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = (((stage_v_145_1 * 3) + pub_r001373_0_1) + 35) & 127;
  int stage_v_365_2 = (((stage_v_145_2 * 3) + pub_r001373_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = ((pub_r001373_5_1 * 2) + 39) & 63;
  int stage_v_366_2 = ((pub_r001373_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = ((pub_r001373_4_1 * 2) + 45) & 63;
  int stage_v_367_2 = ((pub_r001373_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((pub_r001373_14_1 * 2) + 34) & 63;
  int stage_v_368_2 = ((pub_r001373_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001373_3_1 * 2) + 41) & 63;
  int stage_v_369_2 = ((pub_r001373_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = (((stage_v_255_1 * 3) + pub_r001373_4_1) + 28) & 127;
  int stage_v_370_2 = (((stage_v_255_2 * 3) + pub_r001373_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = (((stage_v_190_1 * 3) + pub_r001373_18_1) + 45) & 127;
  int stage_v_371_2 = (((stage_v_190_2 * 3) + pub_r001373_18_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = (((stage_v_272_1 * 3) + pub_r001373_9_1) + 41) & 127;
  int stage_v_372_2 = (((stage_v_272_2 * 3) + pub_r001373_9_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_372_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_372_2 * 2)) & 255;
  int stage_v_373_1 = (((stage_v_4_1 * 3) + pub_r001373_15_1) + 6) & 127;
  int stage_v_373_2 = (((stage_v_4_2 * 3) + pub_r001373_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = (((stage_v_275_1 * 3) + pub_r001373_6_1) + 11) & 127;
  int stage_v_374_2 = (((stage_v_275_2 * 3) + pub_r001373_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = ((pub_r001373_1_1 * 2) + 37) & 63;
  int stage_v_375_2 = ((pub_r001373_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((pub_r001373_5_1 * 2) + 42) & 63;
  int stage_v_376_2 = ((pub_r001373_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = (((stage_v_231_1 * 3) + pub_r001373_6_1) + 4) & 127;
  int stage_v_377_2 = (((stage_v_231_2 * 3) + pub_r001373_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = (((stage_v_243_1 * 3) + pub_r001373_11_1) + 19) & 127;
  int stage_v_378_2 = (((stage_v_243_2 * 3) + pub_r001373_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = ((pub_r001373_13_1 * 2) + 45) & 63;
  int stage_v_379_2 = ((pub_r001373_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = ((pub_r001373_6_1 * 2) + 46) & 63;
  int stage_v_380_2 = ((pub_r001373_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = (((stage_v_326_1 * 3) + pub_r001373_12_1) + 7) & 127;
  int stage_v_381_2 = (((stage_v_326_2 * 3) + pub_r001373_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = (((stage_v_348_1 * 3) + pub_r001373_0_1) + 36) & 127;
  int stage_v_382_2 = (((stage_v_348_2 * 3) + pub_r001373_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = (((stage_v_314_1 * 3) + pub_r001373_6_1) + 42) & 127;
  int stage_v_383_2 = (((stage_v_314_2 * 3) + pub_r001373_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = (((stage_v_303_1 * 3) + pub_r001373_16_1) + 24) & 127;
  int stage_v_384_2 = (((stage_v_303_2 * 3) + pub_r001373_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = ((pub_r001373_3_1 * 2) + 8) & 63;
  int stage_v_385_2 = ((pub_r001373_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001373_14_1 * 2) + 49) & 63;
  int stage_v_386_2 = ((pub_r001373_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((pub_r001373_15_1 * 2) + 27) & 63;
  int stage_v_387_2 = ((pub_r001373_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = ((pub_r001373_6_1 * 2) + 9) & 63;
  int stage_v_388_2 = ((pub_r001373_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = (((stage_v_356_1 * 3) + pub_r001373_11_1) + 4) & 127;
  int stage_v_389_2 = (((stage_v_356_2 * 3) + pub_r001373_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = ((pub_r001373_2_1 * 2) + 23) & 63;
  int stage_v_390_2 = ((pub_r001373_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = (((stage_v_248_1 * 3) + pub_r001373_11_1) + 10) & 127;
  int stage_v_391_2 = (((stage_v_248_2 * 3) + pub_r001373_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = ((pub_r001373_12_1 * 2) + 15) & 63;
  int stage_v_392_2 = ((pub_r001373_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((pub_r001373_10_1 * 2) + 12) & 63;
  int stage_v_393_2 = ((pub_r001373_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((pub_r001373_5_1 * 2) + 27) & 63;
  int stage_v_394_2 = ((pub_r001373_5_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((pub_r001373_8_1 * 2) + 20) & 63;
  int stage_v_395_2 = ((pub_r001373_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = (((stage_v_28_1 * 3) + pub_r001373_15_1) + 22) & 127;
  int stage_v_396_2 = (((stage_v_28_2 * 3) + pub_r001373_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = (((stage_v_240_1 * 3) + pub_r001373_8_1) + 28) & 127;
  int stage_v_397_2 = (((stage_v_240_2 * 3) + pub_r001373_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_397_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_397_2 * 2)) & 255;
  int stage_v_398_1 = (((stage_v_53_1 * 3) + pub_r001373_2_1) + 24) & 127;
  int stage_v_398_2 = (((stage_v_53_2 * 3) + pub_r001373_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = (((stage_v_297_1 * 3) + pub_r001373_3_1) + 40) & 127;
  int stage_v_399_2 = (((stage_v_297_2 * 3) + pub_r001373_3_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_399_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_399_2 * 2)) & 255;
  int stage_v_400_1 = (((sec_r001373_5_1 * 3) + pub_r001373_2_1) + 13) & 127;
  int stage_v_400_2 = (((sec_r001373_5_2 * 3) + pub_r001373_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_400_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_400_2 * 2)) & 255;
  int stage_v_401_1 = (((stage_v_191_1 * 3) + pub_r001373_6_1) + 24) & 127;
  int stage_v_401_2 = (((stage_v_191_2 * 3) + pub_r001373_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_401_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_401_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_401_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_401_2 * 2)) & 255;
  int stage_v_402_1 = (((stage_v_248_1 * 3) + pub_r001373_17_1) + 13) & 127;
  int stage_v_402_2 = (((stage_v_248_2 * 3) + pub_r001373_17_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_402_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_402_2 * 2)) & 255;
  int stage_v_403_1 = ((pub_r001373_9_1 * 2) + 47) & 63;
  int stage_v_403_2 = ((pub_r001373_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = ((pub_r001373_14_1 * 2) + 30) & 63;
  int stage_v_404_2 = ((pub_r001373_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = (((stage_v_227_1 * 3) + pub_r001373_10_1) + 11) & 127;
  int stage_v_405_2 = (((stage_v_227_2 * 3) + pub_r001373_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = (((stage_v_364_1 * 3) + pub_r001373_8_1) + 31) & 127;
  int stage_v_406_2 = (((stage_v_364_2 * 3) + pub_r001373_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_406_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_406_2 * 2)) & 255;
  int stage_v_407_1 = ((pub_r001373_6_1 * 2) + 50) & 63;
  int stage_v_407_2 = ((pub_r001373_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = (((stage_v_318_1 * 3) + pub_r001373_14_1) + 16) & 127;
  int stage_v_408_2 = (((stage_v_318_2 * 3) + pub_r001373_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = (((stage_v_159_1 * 3) + pub_r001373_6_1) + 3) & 127;
  int stage_v_409_2 = (((stage_v_159_2 * 3) + pub_r001373_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_409_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_409_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_409_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_409_2 * 2)) & 255;
  int stage_v_410_1 = ((pub_r001373_19_1 * 2) + 9) & 63;
  int stage_v_410_2 = ((pub_r001373_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((pub_r001373_13_1 * 2) + 37) & 63;
  int stage_v_411_2 = ((pub_r001373_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = (((stage_v_102_1 * 3) + pub_r001373_14_1) + 25) & 127;
  int stage_v_412_2 = (((stage_v_102_2 * 3) + pub_r001373_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_412_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_412_2 * 2)) & 255;
  int stage_v_413_1 = (((stage_v_365_1 * 3) + pub_r001373_0_1) + 26) & 127;
  int stage_v_413_2 = (((stage_v_365_2 * 3) + pub_r001373_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_413_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_413_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_413_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_413_2 * 2)) & 255;
  int stage_v_414_1 = (((sec_r001373_1_1 * 3) + pub_r001373_13_1) + 37) & 127;
  int stage_v_414_2 = (((sec_r001373_1_2 * 3) + pub_r001373_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_414_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_414_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_414_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_414_2 * 2)) & 255;
  int stage_v_415_1 = ((pub_r001373_14_1 * 2) + 10) & 63;
  int stage_v_415_2 = ((pub_r001373_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = (((stage_v_356_1 * 3) + pub_r001373_1_1) + 24) & 127;
  int stage_v_416_2 = (((stage_v_356_2 * 3) + pub_r001373_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_416_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_416_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_416_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_416_2 * 2)) & 255;
  int stage_v_417_1 = (((stage_v_283_1 * 3) + pub_r001373_2_1) + 34) & 127;
  int stage_v_417_2 = (((stage_v_283_2 * 3) + pub_r001373_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = (((stage_v_384_1 * 3) + pub_r001373_1_1) + 39) & 127;
  int stage_v_418_2 = (((stage_v_384_2 * 3) + pub_r001373_1_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_418_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_418_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_418_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_418_2 * 2)) & 255;
  int stage_v_419_1 = (((stage_v_356_1 * 3) + pub_r001373_11_1) + 23) & 127;
  int stage_v_419_2 = (((stage_v_356_2 * 3) + pub_r001373_11_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_419_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_419_2 * 2)) & 255;
  int stage_v_420_1 = ((pub_r001373_19_1 * 2) + 14) & 63;
  int stage_v_420_2 = ((pub_r001373_19_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = ((pub_r001373_13_1 * 2) + 50) & 63;
  int stage_v_421_2 = ((pub_r001373_13_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = ((pub_r001373_2_1 * 2) + 25) & 63;
  int stage_v_422_2 = ((pub_r001373_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = ((pub_r001373_1_1 * 2) + 8) & 63;
  int stage_v_423_2 = ((pub_r001373_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = (((stage_v_89_1 * 3) + pub_r001373_5_1) + 37) & 127;
  int stage_v_424_2 = (((stage_v_89_2 * 3) + pub_r001373_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_424_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_424_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_424_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_424_2 * 2)) & 255;
  int stage_v_425_1 = ((pub_r001373_14_1 * 2) + 38) & 63;
  int stage_v_425_2 = ((pub_r001373_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = ((pub_r001373_5_1 * 2) + 14) & 63;
  int stage_v_426_2 = ((pub_r001373_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = (((stage_v_198_1 * 3) + pub_r001373_6_1) + 28) & 127;
  int stage_v_427_2 = (((stage_v_198_2 * 3) + pub_r001373_6_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_427_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_427_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_427_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_427_2 * 2)) & 255;
  int stage_v_428_1 = ((pub_r001373_1_1 * 2) + 9) & 63;
  int stage_v_428_2 = ((pub_r001373_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = (((stage_v_182_1 * 3) + pub_r001373_8_1) + 10) & 127;
  int stage_v_429_2 = (((stage_v_182_2 * 3) + pub_r001373_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_429_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_429_2 * 2)) & 255;
  int stage_v_430_1 = ((pub_r001373_19_1 * 2) + 13) & 63;
  int stage_v_430_2 = ((pub_r001373_19_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_430_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_430_2) & 127;
  int stage_v_431_1 = (((stage_v_408_1 * 3) + pub_r001373_1_1) + 11) & 127;
  int stage_v_431_2 = (((stage_v_408_2 * 3) + pub_r001373_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_431_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_431_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_431_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_431_2 * 2)) & 255;
  int stage_v_432_1 = ((pub_r001373_3_1 * 2) + 29) & 63;
  int stage_v_432_2 = ((pub_r001373_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = (((stage_v_89_1 * 3) + pub_r001373_17_1) + 11) & 127;
  int stage_v_433_2 = (((stage_v_89_2 * 3) + pub_r001373_17_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_433_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_433_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_433_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_433_2 * 2)) & 255;
  int stage_v_434_1 = ((pub_r001373_19_1 * 2) + 36) & 63;
  int stage_v_434_2 = ((pub_r001373_19_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = ((pub_r001373_12_1 * 2) + 22) & 63;
  int stage_v_435_2 = ((pub_r001373_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = (((stage_v_35_1 * 3) + pub_r001373_12_1) + 25) & 127;
  int stage_v_436_2 = (((stage_v_35_2 * 3) + pub_r001373_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_436_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_436_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_436_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_436_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001373_1_1 == pub_r001373_1_2);
  __CPROVER_assume(sec_r001373_16_1 != sec_r001373_16_2);
  __CPROVER_assume(pub_r001373_8_1 == pub_r001373_8_2);
  __CPROVER_assume(pub_r001373_16_1 == pub_r001373_16_2);
  __CPROVER_assume(sec_r001373_19_1 != sec_r001373_19_2);
  __CPROVER_assume(sec_r001373_5_1 != sec_r001373_5_2);
  __CPROVER_assume(pub_r001373_3_1 == pub_r001373_3_2);
  __CPROVER_assume(sec_r001373_6_1 != sec_r001373_6_2);
  __CPROVER_assume(sec_r001373_18_1 != sec_r001373_18_2);
  __CPROVER_assume(pub_r001373_2_1 == pub_r001373_2_2);
  __CPROVER_assume(sec_r001373_1_1 != sec_r001373_1_2);
  __CPROVER_assume(pub_r001373_6_1 == pub_r001373_6_2);
  __CPROVER_assume(sec_r001373_13_1 != sec_r001373_13_2);
  __CPROVER_assume(pub_r001373_14_1 == pub_r001373_14_2);
  __CPROVER_assume(pub_r001373_0_1 == pub_r001373_0_2);
  __CPROVER_assume(sec_r001373_7_1 != sec_r001373_7_2);
  __CPROVER_assume(sec_r001373_4_1 != sec_r001373_4_2);
  __CPROVER_assume(pub_r001373_13_1 == pub_r001373_13_2);
  __CPROVER_assume(pub_r001373_7_1 == pub_r001373_7_2);
  __CPROVER_assume(pub_r001373_12_1 == pub_r001373_12_2);
  __CPROVER_assume(sec_r001373_3_1 != sec_r001373_3_2);
  __CPROVER_assume(sec_r001373_9_1 != sec_r001373_9_2);
  __CPROVER_assume(pub_r001373_4_1 == pub_r001373_4_2);
  __CPROVER_assume(pub_r001373_11_1 == pub_r001373_11_2);
  __CPROVER_assume(pub_r001373_5_1 == pub_r001373_5_2);
  __CPROVER_assume(pub_r001373_17_1 == pub_r001373_17_2);
  __CPROVER_assume(pub_r001373_9_1 == pub_r001373_9_2);
  __CPROVER_assume(sec_r001373_11_1 != sec_r001373_11_2);
  __CPROVER_assume(sec_r001373_0_1 != sec_r001373_0_2);
  __CPROVER_assume(sec_r001373_8_1 != sec_r001373_8_2);
  __CPROVER_assume(sec_r001373_12_1 != sec_r001373_12_2);
  __CPROVER_assume(sec_r001373_2_1 != sec_r001373_2_2);
  __CPROVER_assume(pub_r001373_10_1 == pub_r001373_10_2);
  __CPROVER_assume(pub_r001373_18_1 == pub_r001373_18_2);
  __CPROVER_assume(pub_r001373_15_1 == pub_r001373_15_2);
  __CPROVER_assume(sec_r001373_17_1 != sec_r001373_17_2);
  __CPROVER_assume(sec_r001373_10_1 != sec_r001373_10_2);
  __CPROVER_assume(sec_r001373_14_1 != sec_r001373_14_2);
  __CPROVER_assume(pub_r001373_19_1 == pub_r001373_19_2);
  __CPROVER_assume(sec_r001373_15_1 != sec_r001373_15_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.calib == st_var_1_2.calib);
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
  assert(stage_v_405_1 == stage_v_405_2);
  assert(stage_v_406_1 == stage_v_406_2);
  assert(stage_v_407_1 == stage_v_407_2);
  assert(stage_v_408_1 == stage_v_408_2);
  assert(stage_v_409_1 == stage_v_409_2);
  assert(stage_v_410_1 == stage_v_410_2);
  assert(stage_v_411_1 == stage_v_411_2);
  assert(stage_v_412_1 == stage_v_412_2);
  assert(stage_v_413_1 == stage_v_413_2);
  assert(stage_v_414_1 == stage_v_414_2);
  assert(stage_v_415_1 == stage_v_415_2);
  assert(stage_v_416_1 == stage_v_416_2);
  assert(stage_v_417_1 == stage_v_417_2);
  assert(stage_v_418_1 == stage_v_418_2);
  assert(stage_v_419_1 == stage_v_419_2);
  assert(stage_v_420_1 == stage_v_420_2);
  assert(stage_v_421_1 == stage_v_421_2);
  assert(stage_v_422_1 == stage_v_422_2);
  assert(stage_v_423_1 == stage_v_423_2);
  assert(stage_v_424_1 == stage_v_424_2);
  assert(stage_v_425_1 == stage_v_425_2);
  assert(stage_v_426_1 == stage_v_426_2);
  assert(stage_v_427_1 == stage_v_427_2);
  assert(stage_v_428_1 == stage_v_428_2);
  assert(stage_v_429_1 == stage_v_429_2);
  assert(stage_v_430_1 == stage_v_430_2);
  assert(stage_v_431_1 == stage_v_431_2);
  assert(stage_v_432_1 == stage_v_432_2);
  assert(stage_v_433_1 == stage_v_433_2);
  assert(stage_v_434_1 == stage_v_434_2);
  assert(stage_v_435_1 == stage_v_435_2);
  assert(stage_v_436_1 == stage_v_436_2);
}


