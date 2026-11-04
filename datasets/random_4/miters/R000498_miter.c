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
struct SensorNode_R000498_9813_0
{
  unsigned char threshold;
  int status;
  short offset;
  short calib;
  unsigned char reading;
  int buffer[3];
};
struct DeviceConfig_R000498_9813_1
{
  int baud_rate;
  int stop_bits;
  int port;
  int parity;
  int id;
  short timeout;
  int buffer[3];
};
union ColorPixel_R000498_9813_0
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
void fn_R000498_9813_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st_1 = {0};
  struct DeviceConfig_R000498_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int delta_44_1 = 0;
  int delta_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_44_1 = ((delta_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_44_2 = ((delta_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_44_1) & 127;
    acc_2 = (acc_2 + delta_44_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_87_1)
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

  switch (damping_87_2)
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
  int cursor_45_1 = local_arr_1[aux_1 % 3];
  int cursor_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_45_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_44_1 == delta_44_2);
  assert(damping_87_1 == damping_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_45_1 == cursor_45_2);
}

int fn_R000498_9813_0(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int delta_44 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_44 = ((delta_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_44) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_87 = (aux + st.buffer[1]) & 3;
  switch (damping_87)
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
  int cursor_45 = local_arr[aux % 3];
  acc = (acc + (cursor_45 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000498_9813_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000498_9813_0 st_1 = {0};
  struct SensorNode_R000498_9813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_62_1 = local_arr_1[aux_1 % 3];
  int bound_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_62_2 * 2)) & 127;
  int scale_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_50_1)
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

  switch (scale_50_2)
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

  int delta_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_60_1) & 63;
  aux_2 = (aux_2 + delta_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_33_1 = 0;
  int phase_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_33_1 = ((phase_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_33_2 = ((phase_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_33_1) & 127;
    acc_2 = (acc_2 + phase_33_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_62_1 == bound_62_2);
  assert(scale_50_1 == scale_50_2);
  assert(delta_60_1 == delta_60_2);
  assert(phase_33_1 == phase_33_2);
}

int fn_R000498_9813_1(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000498_9813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int bound_62 = local_arr[aux % 3];
  acc = (acc + (bound_62 * 2)) & 127;
  int scale_50 = (aux + st.buffer[1]) & 3;
  switch (scale_50)
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

  int delta_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_60) & 63;
  acc ^= aux;
  int phase_33 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_33 = ((phase_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_33) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000498_9813_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000498_9813_0 st_1 = {0};
  struct SensorNode_R000498_9813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int parity_95_1 = 0;
  int parity_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_95_1 = ((parity_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_95_2 = ((parity_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_95_1) & 127;
    acc_2 = (acc_2 + parity_95_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_95_1 == parity_95_2);
}

int fn_R000498_9813_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000498_9813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int parity_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_95 = ((parity_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_95) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000498_9813_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000498_9813_0 st_1 = {0};
  struct SensorNode_R000498_9813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int parity_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_72_1 > 16)
  {
    acc_1 = ((acc_1 + (parity_72_1 * 2)) + 5) & 127;
    aux_1 ^= parity_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_72_2 > 16)
  {
    acc_2 = ((acc_2 + (parity_72_2 * 2)) + 5) & 127;
    aux_2 ^= parity_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_58_1)
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

  switch (threshold_58_2)
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

  int delta_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_75_1) & 63;
  aux_2 = (aux_2 + delta_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_72_1 == parity_72_2);
  assert(threshold_58_1 == threshold_58_2);
  assert(delta_75_1 == delta_75_2);
}

int fn_R000498_9813_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000498_9813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int parity_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_72 > 16)
  {
    acc = ((acc + (parity_72 * 2)) + 5) & 127;
    aux ^= parity_72 & 15;
  }
  else
  {
    acc = ((acc - parity_72) + 11) & 127;
    aux += 3;
  }
  int threshold_58 = (aux + st.buffer[1]) & 3;
  switch (threshold_58)
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

  int delta_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_75) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000498_9813_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st_1 = {0};
  struct DeviceConfig_R000498_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int damping_58_1 = 0;
  int damping_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_58_1 = ((damping_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_58_2 = ((damping_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_58_1) & 127;
    acc_2 = (acc_2 + damping_58_2) & 127;
  }

  int offset_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_75_1 > 17)
  {
    acc_1 = ((acc_1 + (offset_75_1 * 2)) + 5) & 127;
    aux_1 ^= offset_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_75_2 > 17)
  {
    acc_2 = ((acc_2 + (offset_75_2 * 2)) + 5) & 127;
    aux_2 ^= offset_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_25_1 = local_arr_1[aux_1 % 3];
  int parity_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_25_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_58_1 == damping_58_2);
  assert(offset_75_1 == offset_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_25_1 == parity_25_2);
}

int fn_R000498_9813_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int damping_58 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_58 = ((damping_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_58) & 127;
  }

  int offset_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_75 > 17)
  {
    acc = ((acc + (offset_75 * 2)) + 5) & 127;
    aux ^= offset_75 & 15;
  }
  else
  {
    acc = ((acc - offset_75) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int parity_25 = local_arr[aux % 3];
  acc = (acc + (parity_25 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000498_9813_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000498_9813_0 st_1 = {0};
  struct SensorNode_R000498_9813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int residue_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_82_1)
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

  switch (residue_82_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_82_1 == residue_82_2);
}

int fn_R000498_9813_5(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000498_9813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int residue_82 = (aux + st.buffer[1]) & 3;
  switch (residue_82)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000498_9813_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st_1 = {0};
  struct DeviceConfig_R000498_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int sample_48_1 = 0;
  int sample_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_48_1 = ((sample_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_48_2 = ((sample_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_48_1) & 127;
    acc_2 = (acc_2 + sample_48_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_13_1 = local_arr_1[aux_1 % 3];
  int stride_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_13_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_48_1 == sample_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_13_1 == stride_13_2);
}

int fn_R000498_9813_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int sample_48 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_48 = ((sample_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_48) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int stride_13 = local_arr[aux % 3];
  acc = (acc + (stride_13 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000498_9813_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000498_9813_0 st_1 = {0};
  struct SensorNode_R000498_9813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int damping_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_99_1 > 13)
  {
    acc_1 = ((acc_1 + (damping_99_1 * 2)) + 5) & 127;
    aux_1 ^= damping_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_99_2 > 13)
  {
    acc_2 = ((acc_2 + (damping_99_2 * 2)) + 5) & 127;
    aux_2 ^= damping_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_62_1 = 0;
  int factor_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_62_1 = ((factor_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_62_2 = ((factor_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_62_1) & 127;
    acc_2 = (acc_2 + factor_62_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_99_1 == damping_99_2);
  assert(factor_62_1 == factor_62_2);
}

int fn_R000498_9813_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000498_9813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int damping_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_99 > 13)
  {
    acc = ((acc + (damping_99 * 2)) + 5) & 127;
    aux ^= damping_99 & 15;
  }
  else
  {
    acc = ((acc - damping_99) + 11) & 127;
    aux += 3;
  }
  int factor_62 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_62 = ((factor_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_62) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000498_9813_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st_1 = {0};
  struct DeviceConfig_R000498_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_54_1 = local_arr_1[aux_1 % 3];
  int coefficient_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_54_2 * 2)) & 127;
  int vector_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_20_1 > 37)
  {
    acc_1 = ((acc_1 + (vector_20_1 * 2)) + 5) & 127;
    aux_1 ^= vector_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_20_2 > 37)
  {
    acc_2 = ((acc_2 + (vector_20_2 * 2)) + 5) & 127;
    aux_2 ^= vector_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_20_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_53_1 = 0;
  int residue_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_53_1 = ((residue_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_53_2 = ((residue_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_53_1) & 127;
    acc_2 = (acc_2 + residue_53_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_54_1 == coefficient_54_2);
  assert(vector_20_1 == vector_20_2);
  assert(residue_53_1 == residue_53_2);
}

int fn_R000498_9813_8(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int coefficient_54 = local_arr[aux % 3];
  acc = (acc + (coefficient_54 * 2)) & 127;
  int vector_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_20 > 37)
  {
    acc = ((acc + (vector_20 * 2)) + 5) & 127;
    aux ^= vector_20 & 15;
  }
  else
  {
    acc = ((acc - vector_20) + 11) & 127;
    aux += 3;
  }
  int residue_53 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_53 = ((residue_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_53) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000498_9813_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st_1 = {0};
  struct DeviceConfig_R000498_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_70_1 > 11)
  {
    acc_1 = ((acc_1 + (pivot_70_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_70_2 > 11)
  {
    acc_2 = ((acc_2 + (pivot_70_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_43_1)
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

  switch (cursor_43_2)
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

  int sample_49_1 = 0;
  int sample_49_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_49_1 = ((sample_49_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_49_2 = ((sample_49_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_49_1) & 127;
    acc_2 = (acc_2 + sample_49_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_70_1 == pivot_70_2);
  assert(cursor_43_1 == cursor_43_2);
  assert(sample_49_1 == sample_49_2);
}

int fn_R000498_9813_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_70 > 11)
  {
    acc = ((acc + (pivot_70 * 2)) + 5) & 127;
    aux ^= pivot_70 & 15;
  }
  else
  {
    acc = ((acc - pivot_70) + 11) & 127;
    aux += 3;
  }
  int cursor_43 = (aux + st.buffer[1]) & 3;
  switch (cursor_43)
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

  int sample_49 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_49 = ((sample_49 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_49) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000498_9813_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st_1 = {0};
  struct DeviceConfig_R000498_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int margin_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_88_1 > 17)
  {
    acc_1 = ((acc_1 + (margin_88_1 * 2)) + 5) & 127;
    aux_1 ^= margin_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_88_2 > 17)
  {
    acc_2 = ((acc_2 + (margin_88_2 * 2)) + 5) & 127;
    aux_2 ^= margin_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_88_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_87_1) & 63;
  aux_2 = (aux_2 + stride_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_25_1 = local_arr_1[aux_1 % 3];
  int quotient_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_25_2 * 2)) & 127;
  int quotient_97_1 = 0;
  int quotient_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_97_1 = ((quotient_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_97_2 = ((quotient_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_97_1) & 127;
    acc_2 = (acc_2 + quotient_97_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_88_1 == margin_88_2);
  assert(stride_87_1 == stride_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_25_1 == quotient_25_2);
  assert(quotient_97_1 == quotient_97_2);
}

int fn_R000498_9813_10(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int margin_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_88 > 17)
  {
    acc = ((acc + (margin_88 * 2)) + 5) & 127;
    aux ^= margin_88 & 15;
  }
  else
  {
    acc = ((acc - margin_88) + 11) & 127;
    aux += 3;
  }
  int stride_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_87) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_25 = local_arr[aux % 3];
  acc = (acc + (quotient_25 * 2)) & 127;
  int quotient_97 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_97 = ((quotient_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_97) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000498_9813_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st_1 = {0};
  struct DeviceConfig_R000498_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int quotient_25_1 = 0;
  int quotient_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_25_1 = ((quotient_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_25_2 = ((quotient_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_25_1) & 127;
    acc_2 = (acc_2 + quotient_25_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_60_1 = local_arr_1[aux_1 % 3];
  int cursor_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_60_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_26_1) & 63;
  aux_2 = (aux_2 + tracker_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_25_1 == quotient_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_60_1 == cursor_60_2);
  assert(tracker_26_1 == tracker_26_2);
}

int fn_R000498_9813_11(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int quotient_25 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_25 = ((quotient_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_25) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int cursor_60 = local_arr[aux % 3];
  acc = (acc + (cursor_60 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_26) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000498_9813_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000498_9813_0 st_1 = {0};
  struct SensorNode_R000498_9813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_51_1) & 63;
  aux_2 = (aux_2 + index_reg_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_91_1 = local_arr_1[aux_1 % 3];
  int mask_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_91_2 * 2)) & 127;
  int threshold_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_67_1 > 21)
  {
    acc_1 = ((acc_1 + (threshold_67_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_67_2 > 21)
  {
    acc_2 = ((acc_2 + (threshold_67_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_67_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_51_1 == index_reg_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_91_1 == mask_91_2);
  assert(threshold_67_1 == threshold_67_2);
}

int fn_R000498_9813_12(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000498_9813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_51) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int mask_91 = local_arr[aux % 3];
  acc = (acc + (mask_91 * 2)) & 127;
  int threshold_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_67 > 21)
  {
    acc = ((acc + (threshold_67 * 2)) + 5) & 127;
    aux ^= threshold_67 & 15;
  }
  else
  {
    acc = ((acc - threshold_67) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000498_9813_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st_1 = {0};
  struct DeviceConfig_R000498_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int metric_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_22_1 > 16)
  {
    acc_1 = ((acc_1 + (metric_22_1 * 2)) + 5) & 127;
    aux_1 ^= metric_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_22_2 > 16)
  {
    acc_2 = ((acc_2 + (metric_22_2 * 2)) + 5) & 127;
    aux_2 ^= metric_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_22_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_20_1) & 63;
  aux_2 = (aux_2 + mask_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_34_1)
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

  switch (threshold_34_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_22_1 == metric_22_2);
  assert(mask_20_1 == mask_20_2);
  assert(threshold_34_1 == threshold_34_2);
}

int fn_R000498_9813_13(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int metric_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_22 > 16)
  {
    acc = ((acc + (metric_22 * 2)) + 5) & 127;
    aux ^= metric_22 & 15;
  }
  else
  {
    acc = ((acc - metric_22) + 11) & 127;
    aux += 3;
  }
  int mask_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_20) & 63;
  acc ^= aux;
  int threshold_34 = (aux + st.buffer[1]) & 3;
  switch (threshold_34)
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

void fn_R000498_9813_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st_1 = {0};
  struct DeviceConfig_R000498_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int tracker_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_66_1)
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

  switch (tracker_66_2)
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

  int coefficient_22_1 = 0;
  int coefficient_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_22_1 = ((coefficient_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_22_2 = ((coefficient_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_22_1) & 127;
    acc_2 = (acc_2 + coefficient_22_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_46_1 = local_arr_1[aux_1 % 3];
  int phase_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_46_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_66_1 == tracker_66_2);
  assert(coefficient_22_1 == coefficient_22_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_46_1 == phase_46_2);
}

int fn_R000498_9813_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int tracker_66 = (aux + st.buffer[1]) & 3;
  switch (tracker_66)
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

  int coefficient_22 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_22 = ((coefficient_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_22) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int phase_46 = local_arr[aux % 3];
  acc = (acc + (phase_46 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000498_9813_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st_1 = {0};
  struct DeviceConfig_R000498_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int delta_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_11_1 > 41)
  {
    acc_1 = ((acc_1 + (delta_11_1 * 2)) + 5) & 127;
    aux_1 ^= delta_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_11_2 > 41)
  {
    acc_2 = ((acc_2 + (delta_11_2 * 2)) + 5) & 127;
    aux_2 ^= delta_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_11_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_11_1 == delta_11_2);
}

int fn_R000498_9813_15(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000498_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int delta_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_11 > 41)
  {
    acc = ((acc + (delta_11 * 2)) + 5) & 127;
    aux ^= delta_11 & 15;
  }
  else
  {
    acc = ((acc - delta_11) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000498_9813_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000498_9813_0 st_1 = {0};
  struct SensorNode_R000498_9813_0 st_2 = {0};
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
  int scale_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_82_1 > 13)
  {
    acc_1 = ((acc_1 + (scale_82_1 * 2)) + 5) & 127;
    aux_1 ^= scale_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_82_2 > 13)
  {
    acc_2 = ((acc_2 + (scale_82_2 * 2)) + 5) & 127;
    aux_2 ^= scale_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_82_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_82_1 == scale_82_2);
}

int fn_R000498_9813_16(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000498_9813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_82 > 13)
  {
    acc = ((acc + (scale_82 * 2)) + 5) & 127;
    aux ^= scale_82 & 15;
  }
  else
  {
    acc = ((acc - scale_82) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000498_0_1;
  int sec_r000498_0_2;
  int sec_r000498_1_1;
  int sec_r000498_1_2;
  int sec_r000498_2_1;
  int sec_r000498_2_2;
  int sec_r000498_3_1;
  int sec_r000498_3_2;
  int sec_r000498_4_1;
  int sec_r000498_4_2;
  int sec_r000498_5_1;
  int sec_r000498_5_2;
  int sec_r000498_6_1;
  int sec_r000498_6_2;
  int sec_r000498_7_1;
  int sec_r000498_7_2;
  int sec_r000498_8_1;
  int sec_r000498_8_2;
  int sec_r000498_9_1;
  int sec_r000498_9_2;
  int sec_r000498_10_1;
  int sec_r000498_10_2;
  int sec_r000498_11_1;
  int sec_r000498_11_2;
  int sec_r000498_12_1;
  int sec_r000498_12_2;
  int sec_r000498_13_1;
  int sec_r000498_13_2;
  int sec_r000498_14_1;
  int sec_r000498_14_2;
  int sec_r000498_15_1;
  int sec_r000498_15_2;
  int pub_r000498_0_1;
  int pub_r000498_0_2;
  int pub_r000498_1_1;
  int pub_r000498_1_2;
  int pub_r000498_2_1;
  int pub_r000498_2_2;
  int pub_r000498_3_1;
  int pub_r000498_3_2;
  int pub_r000498_4_1;
  int pub_r000498_4_2;
  int pub_r000498_5_1;
  int pub_r000498_5_2;
  int pub_r000498_6_1;
  int pub_r000498_6_2;
  int pub_r000498_7_1;
  int pub_r000498_7_2;
  int pub_r000498_8_1;
  int pub_r000498_8_2;
  int pub_r000498_9_1;
  int pub_r000498_9_2;
  int pub_r000498_10_1;
  int pub_r000498_10_2;
  int pub_r000498_11_1;
  int pub_r000498_11_2;
  int pub_r000498_12_1;
  int pub_r000498_12_2;
  int pub_r000498_13_1;
  int pub_r000498_13_2;
  int pub_r000498_14_1;
  int pub_r000498_14_2;
  int pub_r000498_15_1;
  int pub_r000498_15_2;
  int pub_r000498_16_1;
  int pub_r000498_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000498_0_1 >= (-100)) && (pub_r000498_0_1 <= 100));
  __CPROVER_assume((pub_r000498_0_2 >= (-100)) && (pub_r000498_0_2 <= 100));
  __CPROVER_assume((pub_r000498_1_1 >= (-100)) && (pub_r000498_1_1 <= 100));
  __CPROVER_assume((pub_r000498_1_2 >= (-100)) && (pub_r000498_1_2 <= 100));
  __CPROVER_assume((pub_r000498_2_1 >= (-100)) && (pub_r000498_2_1 <= 100));
  __CPROVER_assume((pub_r000498_2_2 >= (-100)) && (pub_r000498_2_2 <= 100));
  __CPROVER_assume((pub_r000498_3_1 >= (-100)) && (pub_r000498_3_1 <= 100));
  __CPROVER_assume((pub_r000498_3_2 >= (-100)) && (pub_r000498_3_2 <= 100));
  __CPROVER_assume((pub_r000498_4_1 >= (-100)) && (pub_r000498_4_1 <= 100));
  __CPROVER_assume((pub_r000498_4_2 >= (-100)) && (pub_r000498_4_2 <= 100));
  __CPROVER_assume((pub_r000498_5_1 >= (-100)) && (pub_r000498_5_1 <= 100));
  __CPROVER_assume((pub_r000498_5_2 >= (-100)) && (pub_r000498_5_2 <= 100));
  __CPROVER_assume((pub_r000498_6_1 >= (-100)) && (pub_r000498_6_1 <= 100));
  __CPROVER_assume((pub_r000498_6_2 >= (-100)) && (pub_r000498_6_2 <= 100));
  __CPROVER_assume((pub_r000498_7_1 >= (-100)) && (pub_r000498_7_1 <= 100));
  __CPROVER_assume((pub_r000498_7_2 >= (-100)) && (pub_r000498_7_2 <= 100));
  __CPROVER_assume((pub_r000498_8_1 >= (-100)) && (pub_r000498_8_1 <= 100));
  __CPROVER_assume((pub_r000498_8_2 >= (-100)) && (pub_r000498_8_2 <= 100));
  __CPROVER_assume((pub_r000498_9_1 >= (-100)) && (pub_r000498_9_1 <= 100));
  __CPROVER_assume((pub_r000498_9_2 >= (-100)) && (pub_r000498_9_2 <= 100));
  __CPROVER_assume((pub_r000498_10_1 >= (-100)) && (pub_r000498_10_1 <= 100));
  __CPROVER_assume((pub_r000498_10_2 >= (-100)) && (pub_r000498_10_2 <= 100));
  __CPROVER_assume((pub_r000498_11_1 >= (-100)) && (pub_r000498_11_1 <= 100));
  __CPROVER_assume((pub_r000498_11_2 >= (-100)) && (pub_r000498_11_2 <= 100));
  __CPROVER_assume((pub_r000498_12_1 >= (-100)) && (pub_r000498_12_1 <= 100));
  __CPROVER_assume((pub_r000498_12_2 >= (-100)) && (pub_r000498_12_2 <= 100));
  __CPROVER_assume((pub_r000498_13_1 >= (-100)) && (pub_r000498_13_1 <= 100));
  __CPROVER_assume((pub_r000498_13_2 >= (-100)) && (pub_r000498_13_2 <= 100));
  __CPROVER_assume((pub_r000498_14_1 >= (-100)) && (pub_r000498_14_1 <= 100));
  __CPROVER_assume((pub_r000498_14_2 >= (-100)) && (pub_r000498_14_2 <= 100));
  __CPROVER_assume((pub_r000498_15_1 >= (-100)) && (pub_r000498_15_1 <= 100));
  __CPROVER_assume((pub_r000498_15_2 >= (-100)) && (pub_r000498_15_2 <= 100));
  __CPROVER_assume((pub_r000498_16_1 >= (-100)) && (pub_r000498_16_1 <= 100));
  __CPROVER_assume((pub_r000498_16_2 >= (-100)) && (pub_r000498_16_2 <= 100));
  __CPROVER_assume((sec_r000498_0_1 >= 0) && (sec_r000498_0_1 <= 255));
  __CPROVER_assume((sec_r000498_0_2 >= 0) && (sec_r000498_0_2 <= 255));
  __CPROVER_assume((sec_r000498_1_1 >= 0) && (sec_r000498_1_1 <= 255));
  __CPROVER_assume((sec_r000498_1_2 >= 0) && (sec_r000498_1_2 <= 255));
  __CPROVER_assume((sec_r000498_2_1 >= 0) && (sec_r000498_2_1 <= 255));
  __CPROVER_assume((sec_r000498_2_2 >= 0) && (sec_r000498_2_2 <= 255));
  __CPROVER_assume((sec_r000498_3_1 >= 0) && (sec_r000498_3_1 <= 255));
  __CPROVER_assume((sec_r000498_3_2 >= 0) && (sec_r000498_3_2 <= 255));
  __CPROVER_assume((sec_r000498_4_1 >= 0) && (sec_r000498_4_1 <= 255));
  __CPROVER_assume((sec_r000498_4_2 >= 0) && (sec_r000498_4_2 <= 255));
  __CPROVER_assume((sec_r000498_5_1 >= 0) && (sec_r000498_5_1 <= 255));
  __CPROVER_assume((sec_r000498_5_2 >= 0) && (sec_r000498_5_2 <= 255));
  __CPROVER_assume((sec_r000498_6_1 >= 0) && (sec_r000498_6_1 <= 255));
  __CPROVER_assume((sec_r000498_6_2 >= 0) && (sec_r000498_6_2 <= 255));
  __CPROVER_assume((sec_r000498_7_1 >= 0) && (sec_r000498_7_1 <= 255));
  __CPROVER_assume((sec_r000498_7_2 >= 0) && (sec_r000498_7_2 <= 255));
  __CPROVER_assume((sec_r000498_8_1 >= 0) && (sec_r000498_8_1 <= 255));
  __CPROVER_assume((sec_r000498_8_2 >= 0) && (sec_r000498_8_2 <= 255));
  __CPROVER_assume((sec_r000498_9_1 >= 0) && (sec_r000498_9_1 <= 255));
  __CPROVER_assume((sec_r000498_9_2 >= 0) && (sec_r000498_9_2 <= 255));
  __CPROVER_assume((sec_r000498_10_1 >= 0) && (sec_r000498_10_1 <= 255));
  __CPROVER_assume((sec_r000498_10_2 >= 0) && (sec_r000498_10_2 <= 255));
  __CPROVER_assume((sec_r000498_11_1 >= 0) && (sec_r000498_11_1 <= 255));
  __CPROVER_assume((sec_r000498_11_2 >= 0) && (sec_r000498_11_2 <= 255));
  __CPROVER_assume((sec_r000498_12_1 >= 0) && (sec_r000498_12_1 <= 255));
  __CPROVER_assume((sec_r000498_12_2 >= 0) && (sec_r000498_12_2 <= 255));
  __CPROVER_assume((sec_r000498_13_1 >= 0) && (sec_r000498_13_1 <= 255));
  __CPROVER_assume((sec_r000498_13_2 >= 0) && (sec_r000498_13_2 <= 255));
  __CPROVER_assume((sec_r000498_14_1 >= 0) && (sec_r000498_14_1 <= 255));
  __CPROVER_assume((sec_r000498_14_2 >= 0) && (sec_r000498_14_2 <= 255));
  __CPROVER_assume((sec_r000498_15_1 >= 0) && (sec_r000498_15_1 <= 255));
  __CPROVER_assume((sec_r000498_15_2 >= 0) && (sec_r000498_15_2 <= 255));
  struct SensorNode_R000498_9813_0 st_var_0_1 = {0};
  struct SensorNode_R000498_9813_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000498_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000498_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000498_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000498_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000498_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000498_0_2 + 7) & 15;
  struct DeviceConfig_R000498_9813_1 st_var_1_1 = {0};
  struct DeviceConfig_R000498_9813_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000498_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000498_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000498_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000498_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000498_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000498_0_2 + 9) & 15;
  union ColorPixel_R000498_9813_0 u_var_1;
  union ColorPixel_R000498_9813_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 49)
    {
      chk_sum_1 ^= stage_v_0_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_0_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 49)
    {
      chk_sum_2 ^= stage_v_0_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = (st_var_1_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_1_2.buffer[0] ^ 6) & 3;
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

  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
  int stage_v_5_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (10 & 31);
  int stage_v_5_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (10 & 31);
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= (stage_v_5_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_5_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 7) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (st_var_0_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_0_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  int stage_v_10_1 = ((st_var_0_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_0_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 26)
    {
      chk_sum_1 ^= stage_v_10_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_10_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 26)
    {
      chk_sum_2 ^= stage_v_10_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_11_1 = (st_var_1_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_1_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 13) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 13) & 15;
  int stage_v_12_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_12_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= stage_v_12_1;
  chk_sum_2 ^= stage_v_12_2;
  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
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

  switch (stage_v_13_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 15) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 15) & 15;
  int stage_v_14_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_14_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= stage_v_14_1;
  chk_sum_2 ^= stage_v_14_2;
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = ((st_var_0_1.buffer[1] * 2) + 55) & 63;
  int stage_v_16_2 = ((st_var_0_2.buffer[1] * 2) + 55) & 63;
  if (stage_v_16_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_16_1) - 5) & 255;
    if (stage_v_16_1 > 44)
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
  if (stage_v_16_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_16_2) - 5) & 255;
    if (stage_v_16_2 > 44)
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
  int stage_v_17_1 = (st_var_1_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_1_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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

  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_20_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_21_1 = ((st_var_1_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_1_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 46)
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
  if (stage_v_21_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 46)
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
  int stage_v_23_1 = ((st_var_1_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_1_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 50)
    {
      chk_sum_1 ^= stage_v_23_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_23_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 50)
    {
      chk_sum_2 ^= stage_v_23_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_25_1 = ((stage_v_25_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_25_2 = ((stage_v_25_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = ((st_var_0_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_0_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 36)
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
  if (stage_v_26_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 36)
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
  int stage_v_27_1 = table_1[3];
  int stage_v_27_2 = table_2[3];
  table_1[3] = (table_1[0] + 55) & 63;
  table_2[3] = (table_2[0] + 55) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 29) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 29) & 15;
  int stage_v_28_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_28_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= stage_v_28_1;
  chk_sum_2 ^= stage_v_28_2;
  int stage_v_29_1 = (st_var_1_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_1_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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

  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
  int stage_v_31_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (36 & 31);
  int stage_v_31_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (36 & 31);
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= (stage_v_31_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_31_2 << 1) & 127;
  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 34) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  int stage_v_34_1 = table_1[2];
  int stage_v_34_2 = table_2[2];
  table_1[2] = (table_1[3] + 69) & 63;
  table_2[2] = (table_2[3] + 69) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (st_var_1_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_1_2.buffer[0] ^ 38) & 3;
  switch (stage_v_35_1)
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

  switch (stage_v_35_2)
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

  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  int stage_v_38_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (43 & 31);
  int stage_v_38_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (43 & 31);
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= (stage_v_38_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_38_2 << 1) & 127;
  int stage_v_39_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (44 & 31);
  int stage_v_39_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (44 & 31);
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= (stage_v_39_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_39_2 << 1) & 127;
  int stage_v_40_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (45 & 31);
  int stage_v_40_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (45 & 31);
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= (stage_v_40_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_40_2 << 1) & 127;
  int stage_v_41_1 = (st_var_1_1.buffer[0] ^ 44) & 3;
  int stage_v_41_2 = (st_var_1_2.buffer[0] ^ 44) & 3;
  switch (stage_v_41_1)
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

  switch (stage_v_41_2)
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

  int stage_v_42_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_42_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 44) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 44) & 15;
  int stage_v_43_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_43_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= stage_v_43_1;
  chk_sum_2 ^= stage_v_43_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 45) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 45) & 15;
  int stage_v_44_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_44_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= stage_v_44_1;
  chk_sum_2 ^= stage_v_44_2;
  int stage_v_45_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (50 & 31);
  int stage_v_45_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (50 & 31);
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= (stage_v_45_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_45_2 << 1) & 127;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_46_1 = ((stage_v_46_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_46_2 = ((stage_v_46_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((st_var_1_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_1_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 51)
    {
      chk_sum_1 ^= stage_v_47_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_47_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 51)
    {
      chk_sum_2 ^= stage_v_47_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 50) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 50) & 15;
  int stage_v_49_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_49_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= stage_v_49_1;
  chk_sum_2 ^= stage_v_49_2;
  int stage_v_50_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_50_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_50_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_50_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_51_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_51_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_51_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_51_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_52_1 = ((st_var_0_1.buffer[1] * 2) + 163) & 63;
  int stage_v_52_2 = ((st_var_0_2.buffer[1] * 2) + 163) & 63;
  if (stage_v_52_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_52_1) - 5) & 255;
    if (stage_v_52_1 > 39)
    {
      chk_sum_1 ^= stage_v_52_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_52_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_52_2) - 5) & 255;
    if (stage_v_52_2 > 39)
    {
      chk_sum_2 ^= stage_v_52_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_54_1 = ((stage_v_54_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_54_2 = ((stage_v_54_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 56) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 56) & 15;
  int stage_v_55_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_55_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= stage_v_55_1;
  chk_sum_2 ^= stage_v_55_2;
  int stage_v_56_1 = table_1[0];
  int stage_v_56_2 = table_2[0];
  table_1[0] = (table_1[1] + 113) & 63;
  table_2[0] = (table_2[1] + 113) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = table_1[1];
  int stage_v_57_2 = table_2[1];
  table_1[1] = (table_1[2] + 115) & 63;
  table_2[1] = (table_2[2] + 115) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (st_var_0_1.buffer[0] ^ 61) & 3;
  int stage_v_58_2 = (st_var_0_2.buffer[0] ^ 61) & 3;
  switch (stage_v_58_1)
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

  switch (stage_v_58_2)
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

  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 60) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 60) & 15;
  int stage_v_59_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_59_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= stage_v_59_1;
  chk_sum_2 ^= stage_v_59_2;
  int stage_v_60_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_60_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_60_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_60_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_61_1 = table_1[1];
  int stage_v_61_2 = table_2[1];
  table_1[1] = (table_1[2] + 123) & 63;
  table_2[1] = (table_2[2] + 123) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (st_var_0_1.buffer[0] ^ 65) & 3;
  int stage_v_62_2 = (st_var_0_2.buffer[0] ^ 65) & 3;
  switch (stage_v_62_1)
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

  switch (stage_v_62_2)
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

  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_63_1 = ((stage_v_63_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_63_2 = ((stage_v_63_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_64_1 = ((stage_v_64_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_64_2 = ((stage_v_64_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((st_var_1_1.buffer[2] * 2) + 202) & 63;
  int stage_v_65_2 = ((st_var_1_2.buffer[2] * 2) + 202) & 63;
  if (stage_v_65_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_65_1) - 5) & 255;
    if (stage_v_65_1 > 44)
    {
      chk_sum_1 ^= stage_v_65_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_65_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_65_2) - 5) & 255;
    if (stage_v_65_2 > 44)
    {
      chk_sum_2 ^= stage_v_65_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 67) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 67) & 15;
  int stage_v_66_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_66_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= stage_v_66_1;
  chk_sum_2 ^= stage_v_66_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 68) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 68) & 15;
  int stage_v_67_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_67_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= stage_v_67_1;
  chk_sum_2 ^= stage_v_67_2;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 70) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 70) & 15;
  int stage_v_69_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_69_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= stage_v_69_1;
  chk_sum_2 ^= stage_v_69_2;
  int stage_v_70_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (75 & 31);
  int stage_v_70_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (75 & 31);
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  chk_sum_1 ^= (stage_v_70_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_70_2 << 1) & 127;
  int stage_v_71_1 = ((st_var_1_1.buffer[2] * 2) + 220) & 63;
  int stage_v_71_2 = ((st_var_1_2.buffer[2] * 2) + 220) & 63;
  if (stage_v_71_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_71_1) - 5) & 255;
    if (stage_v_71_1 > 27)
    {
      chk_sum_1 ^= stage_v_71_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_71_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_71_2) - 5) & 255;
    if (stage_v_71_2 > 27)
    {
      chk_sum_2 ^= stage_v_71_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_72_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (77 & 31);
  int stage_v_72_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (77 & 31);
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  chk_sum_1 ^= (stage_v_72_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_72_2 << 1) & 127;
  int stage_v_73_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (78 & 31);
  int stage_v_73_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (78 & 31);
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= (stage_v_73_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_73_2 << 1) & 127;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_74_1 = ((stage_v_74_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_74_2 = ((stage_v_74_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((st_var_1_1.buffer[0] * 2) + 232) & 63;
  int stage_v_75_2 = ((st_var_1_2.buffer[0] * 2) + 232) & 63;
  if (stage_v_75_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_75_1) - 5) & 255;
    if (stage_v_75_1 > 27)
    {
      chk_sum_1 ^= stage_v_75_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_75_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_75_2) - 5) & 255;
    if (stage_v_75_2 > 27)
    {
      chk_sum_2 ^= stage_v_75_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_76_1 = ((stage_v_76_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_76_2 = ((stage_v_76_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = table_1[1];
  int stage_v_77_2 = table_2[1];
  table_1[1] = (table_1[2] + 155) & 63;
  table_2[1] = (table_2[2] + 155) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((st_var_0_1.buffer[0] * 2) + 241) & 63;
  int stage_v_78_2 = ((st_var_0_2.buffer[0] * 2) + 241) & 63;
  if (stage_v_78_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_78_1) - 5) & 255;
    if (stage_v_78_1 > 41)
    {
      chk_sum_1 ^= stage_v_78_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_78_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_78_2) - 5) & 255;
    if (stage_v_78_2 > 41)
    {
      chk_sum_2 ^= stage_v_78_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_79_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_79_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_79_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_79_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_80_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (85 & 31);
  int stage_v_80_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (85 & 31);
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= (stage_v_80_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_80_2 << 1) & 127;
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
  int stage_v_82_1 = table_1[2];
  int stage_v_82_2 = table_2[2];
  table_1[2] = (table_1[3] + 165) & 63;
  table_2[2] = (table_2[3] + 165) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = table_1[3];
  int stage_v_83_2 = table_2[3];
  table_1[3] = (table_1[0] + 167) & 63;
  table_2[3] = (table_2[0] + 167) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = table_1[0];
  int stage_v_84_2 = table_2[0];
  table_1[0] = (table_1[1] + 169) & 63;
  table_2[0] = (table_2[1] + 169) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = table_1[1];
  int stage_v_85_2 = table_2[1];
  table_1[1] = (table_1[2] + 171) & 63;
  table_2[1] = (table_2[2] + 171) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_86_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_86_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_86_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_87_1 = table_1[3];
  int stage_v_87_2 = table_2[3];
  table_1[3] = (table_1[0] + 175) & 63;
  table_2[3] = (table_2[0] + 175) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_88_1 = ((stage_v_88_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_88_2 = ((stage_v_88_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 90) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 90) & 15;
  int stage_v_89_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_89_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  chk_sum_1 ^= stage_v_89_1;
  chk_sum_2 ^= stage_v_89_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 91) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 91) & 15;
  int stage_v_90_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_90_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  chk_sum_1 ^= stage_v_90_1;
  chk_sum_2 ^= stage_v_90_2;
  int stage_v_91_1 = (st_var_1_1.buffer[0] ^ 94) & 3;
  int stage_v_91_2 = (st_var_1_2.buffer[0] ^ 94) & 3;
  switch (stage_v_91_1)
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

  switch (stage_v_91_2)
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

  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_92_1 = ((stage_v_92_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_92_2 = ((stage_v_92_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (st_var_1_1.buffer[0] ^ 96) & 3;
  int stage_v_93_2 = (st_var_1_2.buffer[0] ^ 96) & 3;
  switch (stage_v_93_1)
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

  switch (stage_v_93_2)
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

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 95) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 95) & 15;
  int stage_v_94_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_94_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  chk_sum_1 ^= stage_v_94_1;
  chk_sum_2 ^= stage_v_94_2;
  int stage_v_95_1 = table_1[3];
  int stage_v_95_2 = table_2[3];
  table_1[3] = (table_1[0] + 191) & 63;
  table_2[3] = (table_2[0] + 191) & 63;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = table_1[0];
  int stage_v_96_2 = table_2[0];
  table_1[0] = (table_1[1] + 193) & 63;
  table_2[0] = (table_2[1] + 193) & 63;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((st_var_1_1.buffer[1] * 2) + 298) & 63;
  int stage_v_97_2 = ((st_var_1_2.buffer[1] * 2) + 298) & 63;
  if (stage_v_97_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_97_1) - 5) & 255;
    if (stage_v_97_1 > 44)
    {
      chk_sum_1 ^= stage_v_97_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_97_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_97_2) - 5) & 255;
    if (stage_v_97_2 > 44)
    {
      chk_sum_2 ^= stage_v_97_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_98_1 = ((st_var_0_1.buffer[2] * 2) + 301) & 63;
  int stage_v_98_2 = ((st_var_0_2.buffer[2] * 2) + 301) & 63;
  if (stage_v_98_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_98_1) - 5) & 255;
    if (stage_v_98_1 > 33)
    {
      chk_sum_1 ^= stage_v_98_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_98_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_98_2) - 5) & 255;
    if (stage_v_98_2 > 33)
    {
      chk_sum_2 ^= stage_v_98_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_99_1 = (st_var_1_1.buffer[0] ^ 102) & 3;
  int stage_v_99_2 = (st_var_1_2.buffer[0] ^ 102) & 3;
  switch (stage_v_99_1)
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

  switch (stage_v_99_2)
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

  int stage_v_100_1 = table_1[0];
  int stage_v_100_2 = table_2[0];
  table_1[0] = (table_1[1] + 201) & 63;
  table_2[0] = (table_2[1] + 201) & 63;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = table_1[1];
  int stage_v_101_2 = table_2[1];
  table_1[1] = (table_1[2] + 203) & 63;
  table_2[1] = (table_2[2] + 203) & 63;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((st_var_0_1.buffer[0] * 2) + 313) & 63;
  int stage_v_102_2 = ((st_var_0_2.buffer[0] * 2) + 313) & 63;
  if (stage_v_102_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_102_1) - 5) & 255;
    if (stage_v_102_1 > 30)
    {
      chk_sum_1 ^= stage_v_102_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_102_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_102_2) - 5) & 255;
    if (stage_v_102_2 > 30)
    {
      chk_sum_2 ^= stage_v_102_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_103_1 = ((stage_v_103_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_103_2 = ((stage_v_103_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = table_1[0];
  int stage_v_104_2 = table_2[0];
  table_1[0] = (table_1[1] + 209) & 63;
  table_2[0] = (table_2[1] + 209) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = table_1[1];
  int stage_v_105_2 = table_2[1];
  table_1[1] = (table_1[2] + 211) & 63;
  table_2[1] = (table_2[2] + 211) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_106_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_106_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_106_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_107_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_107_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_107_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_107_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_108_1 = table_1[0];
  int stage_v_108_2 = table_2[0];
  table_1[0] = (table_1[1] + 217) & 63;
  table_2[0] = (table_2[1] + 217) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_109_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_109_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_109_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_110_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_110_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_110_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_110_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_111_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_111_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_111_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_111_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_112_1 = ((stage_v_112_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_112_2 = ((stage_v_112_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 114) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 114) & 15;
  int stage_v_113_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_113_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  chk_sum_1 ^= stage_v_113_1;
  chk_sum_2 ^= stage_v_113_2;
  int stage_v_114_1 = table_1[2];
  int stage_v_114_2 = table_2[2];
  table_1[2] = (table_1[3] + 229) & 63;
  table_2[2] = (table_2[3] + 229) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_115_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_115_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_115_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_116_1 = ((st_var_0_1.buffer[2] * 2) + 355) & 63;
  int stage_v_116_2 = ((st_var_0_2.buffer[2] * 2) + 355) & 63;
  if (stage_v_116_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_116_1) - 5) & 255;
    if (stage_v_116_1 > 25)
    {
      chk_sum_1 ^= stage_v_116_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_116_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_116_2) - 5) & 255;
    if (stage_v_116_2 > 25)
    {
      chk_sum_2 ^= stage_v_116_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_117_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_117_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_117_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_117_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_118_1 = ((stage_v_118_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_118_2 = ((stage_v_118_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (124 & 31);
  int stage_v_119_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (124 & 31);
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  chk_sum_1 ^= (stage_v_119_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_119_2 << 1) & 127;
  int stage_v_120_1 = ((st_var_0_1.buffer[0] * 2) + 367) & 63;
  int stage_v_120_2 = ((st_var_0_2.buffer[0] * 2) + 367) & 63;
  if (stage_v_120_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_120_1) - 5) & 255;
    if (stage_v_120_1 > 44)
    {
      chk_sum_1 ^= stage_v_120_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_120_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_120_2) - 5) & 255;
    if (stage_v_120_2 > 44)
    {
      chk_sum_2 ^= stage_v_120_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_121_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_121_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_121_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_121_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_122_1 = ((st_var_0_1.buffer[2] * 2) + 373) & 63;
  int stage_v_122_2 = ((st_var_0_2.buffer[2] * 2) + 373) & 63;
  if (stage_v_122_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_122_1) - 5) & 255;
    if (stage_v_122_1 > 45)
    {
      chk_sum_1 ^= stage_v_122_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_122_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_122_2) - 5) & 255;
    if (stage_v_122_2 > 45)
    {
      chk_sum_2 ^= stage_v_122_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_123_1 = ((st_var_1_1.buffer[0] * 2) + 376) & 63;
  int stage_v_123_2 = ((st_var_1_2.buffer[0] * 2) + 376) & 63;
  if (stage_v_123_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_123_1) - 5) & 255;
    if (stage_v_123_1 > 48)
    {
      chk_sum_1 ^= stage_v_123_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_123_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_123_2) - 5) & 255;
    if (stage_v_123_2 > 48)
    {
      chk_sum_2 ^= stage_v_123_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_124_1 = ((st_var_0_1.buffer[1] * 2) + 379) & 63;
  int stage_v_124_2 = ((st_var_0_2.buffer[1] * 2) + 379) & 63;
  if (stage_v_124_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_124_1) - 5) & 255;
    if (stage_v_124_1 > 44)
    {
      chk_sum_1 ^= stage_v_124_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_124_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_124_2) - 5) & 255;
    if (stage_v_124_2 > 44)
    {
      chk_sum_2 ^= stage_v_124_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 126) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 126) & 15;
  int stage_v_125_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_125_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  chk_sum_1 ^= stage_v_125_1;
  chk_sum_2 ^= stage_v_125_2;
  int stage_v_126_1 = ((st_var_0_1.buffer[0] * 2) + 385) & 63;
  int stage_v_126_2 = ((st_var_0_2.buffer[0] * 2) + 385) & 63;
  if (stage_v_126_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_126_1) - 5) & 255;
    if (stage_v_126_1 > 43)
    {
      chk_sum_1 ^= stage_v_126_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_126_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_126_2) - 5) & 255;
    if (stage_v_126_2 > 43)
    {
      chk_sum_2 ^= stage_v_126_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_127_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (132 & 31);
  int stage_v_127_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (132 & 31);
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  chk_sum_1 ^= (stage_v_127_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_127_2 << 1) & 127;
  int stage_v_128_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_128_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_128_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_128_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_129_1 = ((st_var_1_1.buffer[0] * 2) + 394) & 63;
  int stage_v_129_2 = ((st_var_1_2.buffer[0] * 2) + 394) & 63;
  if (stage_v_129_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_129_1) - 5) & 255;
    if (stage_v_129_1 > 41)
    {
      chk_sum_1 ^= stage_v_129_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_129_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_129_2) - 5) & 255;
    if (stage_v_129_2 > 41)
    {
      chk_sum_2 ^= stage_v_129_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 131) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 131) & 15;
  int stage_v_130_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_130_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  chk_sum_1 ^= stage_v_130_1;
  chk_sum_2 ^= stage_v_130_2;
  int stage_v_131_1 = (st_var_1_1.buffer[0] ^ 134) & 3;
  int stage_v_131_2 = (st_var_1_2.buffer[0] ^ 134) & 3;
  switch (stage_v_131_1)
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

  switch (stage_v_131_2)
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

  int stage_v_132_1 = ((st_var_0_1.buffer[0] * 2) + 403) & 63;
  int stage_v_132_2 = ((st_var_0_2.buffer[0] * 2) + 403) & 63;
  if (stage_v_132_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_132_1) - 5) & 255;
    if (stage_v_132_1 > 46)
    {
      chk_sum_1 ^= stage_v_132_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_132_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_132_2) - 5) & 255;
    if (stage_v_132_2 > 46)
    {
      chk_sum_2 ^= stage_v_132_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_133_1 = ((st_var_1_1.buffer[1] * 2) + 406) & 63;
  int stage_v_133_2 = ((st_var_1_2.buffer[1] * 2) + 406) & 63;
  if (stage_v_133_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_133_1) - 5) & 255;
    if (stage_v_133_1 > 49)
    {
      chk_sum_1 ^= stage_v_133_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_133_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_133_2) - 5) & 255;
    if (stage_v_133_2 > 49)
    {
      chk_sum_2 ^= stage_v_133_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_134_1 = table_1[2];
  int stage_v_134_2 = table_2[2];
  table_1[2] = (table_1[3] + 269) & 63;
  table_2[2] = (table_2[3] + 269) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (140 & 31);
  int stage_v_135_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (140 & 31);
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  chk_sum_1 ^= (stage_v_135_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_135_2 << 1) & 127;
  int stage_v_136_1 = (st_var_0_1.buffer[0] ^ 139) & 3;
  int stage_v_136_2 = (st_var_0_2.buffer[0] ^ 139) & 3;
  switch (stage_v_136_1)
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

  switch (stage_v_136_2)
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

  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 138) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 138) & 15;
  int stage_v_137_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_137_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  chk_sum_1 ^= stage_v_137_1;
  chk_sum_2 ^= stage_v_137_2;
  int stage_v_138_1 = ((st_var_0_1.buffer[0] * 2) + 421) & 63;
  int stage_v_138_2 = ((st_var_0_2.buffer[0] * 2) + 421) & 63;
  if (stage_v_138_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_138_1) - 5) & 255;
    if (stage_v_138_1 > 38)
    {
      chk_sum_1 ^= stage_v_138_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_138_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_138_2) - 5) & 255;
    if (stage_v_138_2 > 38)
    {
      chk_sum_2 ^= stage_v_138_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_139_1 = ((st_var_1_1.buffer[1] * 2) + 424) & 63;
  int stage_v_139_2 = ((st_var_1_2.buffer[1] * 2) + 424) & 63;
  if (stage_v_139_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_139_1) - 5) & 255;
    if (stage_v_139_1 > 30)
    {
      chk_sum_1 ^= stage_v_139_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_139_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_139_2) - 5) & 255;
    if (stage_v_139_2 > 30)
    {
      chk_sum_2 ^= stage_v_139_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_140_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_140_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_140_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_140_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_141_1 = (st_var_1_1.buffer[0] ^ 144) & 3;
  int stage_v_141_2 = (st_var_1_2.buffer[0] ^ 144) & 3;
  switch (stage_v_141_1)
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

  switch (stage_v_141_2)
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

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 143) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 143) & 15;
  int stage_v_142_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_142_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  chk_sum_1 ^= stage_v_142_1;
  chk_sum_2 ^= stage_v_142_2;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 144) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 144) & 15;
  int stage_v_143_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_143_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  chk_sum_1 ^= stage_v_143_1;
  chk_sum_2 ^= stage_v_143_2;
  int stage_v_144_1 = table_1[0];
  int stage_v_144_2 = table_2[0];
  table_1[0] = (table_1[1] + 289) & 63;
  table_2[0] = (table_2[1] + 289) & 63;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 146) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 146) & 15;
  int stage_v_145_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_145_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  chk_sum_1 ^= stage_v_145_1;
  chk_sum_2 ^= stage_v_145_2;
  int stage_v_146_1 = (st_var_0_1.buffer[0] ^ 149) & 3;
  int stage_v_146_2 = (st_var_0_2.buffer[0] ^ 149) & 3;
  switch (stage_v_146_1)
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

  switch (stage_v_146_2)
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

  int stage_v_147_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (152 & 31);
  int stage_v_147_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (152 & 31);
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  chk_sum_1 ^= (stage_v_147_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_147_2 << 1) & 127;
  int stage_v_148_1 = (st_var_0_1.buffer[0] ^ 151) & 3;
  int stage_v_148_2 = (st_var_0_2.buffer[0] ^ 151) & 3;
  switch (stage_v_148_1)
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

  switch (stage_v_148_2)
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

  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 150) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 150) & 15;
  int stage_v_149_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_149_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  chk_sum_1 ^= stage_v_149_1;
  chk_sum_2 ^= stage_v_149_2;
  int stage_v_150_1 = table_1[2];
  int stage_v_150_2 = table_2[2];
  table_1[2] = (table_1[3] + 301) & 63;
  table_2[2] = (table_2[3] + 301) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_151_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_151_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_151_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_152_1 = (st_var_0_1.buffer[0] ^ 155) & 3;
  int stage_v_152_2 = (st_var_0_2.buffer[0] ^ 155) & 3;
  switch (stage_v_152_1)
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

  switch (stage_v_152_2)
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

  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 154) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 154) & 15;
  int stage_v_153_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_153_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  chk_sum_1 ^= stage_v_153_1;
  chk_sum_2 ^= stage_v_153_2;
  int stage_v_154_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_154_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_154_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_154_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_155_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_155_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_155_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_155_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_156_1 = ((st_var_0_1.buffer[0] * 2) + 475) & 63;
  int stage_v_156_2 = ((st_var_0_2.buffer[0] * 2) + 475) & 63;
  if (stage_v_156_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_156_1) - 5) & 255;
    if (stage_v_156_1 > 40)
    {
      chk_sum_1 ^= stage_v_156_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_156_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_156_2) - 5) & 255;
    if (stage_v_156_2 > 40)
    {
      chk_sum_2 ^= stage_v_156_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_157_1 = (st_var_1_1.buffer[0] ^ 160) & 3;
  int stage_v_157_2 = (st_var_1_2.buffer[0] ^ 160) & 3;
  switch (stage_v_157_1)
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

  switch (stage_v_157_2)
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

  int stage_v_158_1 = ((st_var_0_1.buffer[2] * 2) + 481) & 63;
  int stage_v_158_2 = ((st_var_0_2.buffer[2] * 2) + 481) & 63;
  if (stage_v_158_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_158_1) - 5) & 255;
    if (stage_v_158_1 > 53)
    {
      chk_sum_1 ^= stage_v_158_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_158_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_158_2) - 5) & 255;
    if (stage_v_158_2 > 53)
    {
      chk_sum_2 ^= stage_v_158_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_159_1 = (st_var_1_1.buffer[0] ^ 162) & 3;
  int stage_v_159_2 = (st_var_1_2.buffer[0] ^ 162) & 3;
  switch (stage_v_159_1)
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

  switch (stage_v_159_2)
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

  int stage_v_160_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (165 & 31);
  int stage_v_160_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (165 & 31);
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  chk_sum_1 ^= (stage_v_160_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_160_2 << 1) & 127;
  int stage_v_161_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (166 & 31);
  int stage_v_161_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (166 & 31);
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  chk_sum_1 ^= (stage_v_161_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_161_2 << 1) & 127;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_162_1 = ((stage_v_162_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_162_2 = ((stage_v_162_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((st_var_1_1.buffer[1] * 2) + 496) & 63;
  int stage_v_163_2 = ((st_var_1_2.buffer[1] * 2) + 496) & 63;
  if (stage_v_163_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_163_1) - 5) & 255;
    if (stage_v_163_1 > 27)
    {
      chk_sum_1 ^= stage_v_163_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_163_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_163_2) - 5) & 255;
    if (stage_v_163_2 > 27)
    {
      chk_sum_2 ^= stage_v_163_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_164_1 = (st_var_0_1.buffer[0] ^ 167) & 3;
  int stage_v_164_2 = (st_var_0_2.buffer[0] ^ 167) & 3;
  switch (stage_v_164_1)
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

  switch (stage_v_164_2)
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

  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 166) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 166) & 15;
  int stage_v_165_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_165_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  chk_sum_1 ^= stage_v_165_1;
  chk_sum_2 ^= stage_v_165_2;
  int stage_v_166_1 = ((st_var_0_1.buffer[1] * 2) + 505) & 63;
  int stage_v_166_2 = ((st_var_0_2.buffer[1] * 2) + 505) & 63;
  if (stage_v_166_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_166_1) - 5) & 255;
    if (stage_v_166_1 > 52)
    {
      chk_sum_1 ^= stage_v_166_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_166_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_166_2) - 5) & 255;
    if (stage_v_166_2 > 52)
    {
      chk_sum_2 ^= stage_v_166_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_167_1 = ((stage_v_167_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_167_2 = ((stage_v_167_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int b_w0_1 = (sec_r000498_4_1 ^ 0x5A) & 63;
  int b_w0_2 = (sec_r000498_4_2 ^ 0x5A) & 63;
  int b_w1_1 = ((b_w0_1 << 2) ^ (sec_r000498_2_1 >> 2)) & 63;
  int b_w1_2 = ((b_w0_2 << 2) ^ (sec_r000498_2_2 >> 2)) & 63;
  int b_w2_1 = ((b_w1_1 << 2) ^ (sec_r000498_11_1 >> 2)) & 63;
  int b_w2_2 = ((b_w1_2 << 2) ^ (sec_r000498_11_2 >> 2)) & 63;
  int b_w3_1 = ((b_w2_1 << 2) & (sec_r000498_4_1 >> 2)) & 63;
  int b_w3_2 = ((b_w2_2 << 2) & (sec_r000498_4_2 >> 2)) & 63;
  int b_w4_1 = ((b_w3_1 << 2) & (sec_r000498_2_1 >> 2)) & 63;
  int b_w4_2 = ((b_w3_2 << 2) & (sec_r000498_2_2 >> 2)) & 63;
  int b_w5_1 = ((b_w4_1 << 1) & (sec_r000498_11_1 >> 1)) & 63;
  int b_w5_2 = ((b_w4_2 << 1) & (sec_r000498_11_2 >> 1)) & 63;
  out_sink_1 += b_w5_1 & 63;
  out_sink_2 += b_w5_2 & 63;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000498_6_1 == pub_r000498_6_2);
  __CPROVER_assume(sec_r000498_15_1 != sec_r000498_15_2);
  __CPROVER_assume(pub_r000498_4_1 == pub_r000498_4_2);
  __CPROVER_assume(pub_r000498_8_1 == pub_r000498_8_2);
  __CPROVER_assume(sec_r000498_7_1 != sec_r000498_7_2);
  __CPROVER_assume(pub_r000498_7_1 == pub_r000498_7_2);
  __CPROVER_assume(pub_r000498_9_1 == pub_r000498_9_2);
  __CPROVER_assume(pub_r000498_16_1 == pub_r000498_16_2);
  __CPROVER_assume(sec_r000498_5_1 != sec_r000498_5_2);
  __CPROVER_assume(pub_r000498_2_1 == pub_r000498_2_2);
  __CPROVER_assume(sec_r000498_6_1 != sec_r000498_6_2);
  __CPROVER_assume(sec_r000498_11_1 != sec_r000498_11_2);
  __CPROVER_assume(pub_r000498_5_1 == pub_r000498_5_2);
  __CPROVER_assume(sec_r000498_12_1 != sec_r000498_12_2);
  __CPROVER_assume(sec_r000498_1_1 != sec_r000498_1_2);
  __CPROVER_assume(pub_r000498_12_1 == pub_r000498_12_2);
  __CPROVER_assume(sec_r000498_8_1 != sec_r000498_8_2);
  __CPROVER_assume(pub_r000498_3_1 == pub_r000498_3_2);
  __CPROVER_assume(sec_r000498_2_1 != sec_r000498_2_2);
  __CPROVER_assume(pub_r000498_0_1 == pub_r000498_0_2);
  __CPROVER_assume(pub_r000498_1_1 == pub_r000498_1_2);
  __CPROVER_assume(sec_r000498_4_1 != sec_r000498_4_2);
  __CPROVER_assume(pub_r000498_11_1 == pub_r000498_11_2);
  __CPROVER_assume(pub_r000498_10_1 == pub_r000498_10_2);
  __CPROVER_assume(sec_r000498_13_1 != sec_r000498_13_2);
  __CPROVER_assume(sec_r000498_0_1 != sec_r000498_0_2);
  __CPROVER_assume(pub_r000498_14_1 == pub_r000498_14_2);
  __CPROVER_assume(sec_r000498_3_1 != sec_r000498_3_2);
  __CPROVER_assume(pub_r000498_13_1 == pub_r000498_13_2);
  __CPROVER_assume(sec_r000498_9_1 != sec_r000498_9_2);
  __CPROVER_assume(sec_r000498_10_1 != sec_r000498_10_2);
  __CPROVER_assume(sec_r000498_14_1 != sec_r000498_14_2);
  __CPROVER_assume(pub_r000498_15_1 == pub_r000498_15_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.stop_bits == st_var_1_2.stop_bits);
  assert(st_var_1_1.port == st_var_1_2.port);
  assert(st_var_1_1.parity == st_var_1_2.parity);
  assert(st_var_1_1.id == st_var_1_2.id);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
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
  assert(b_w0_1 == b_w0_2);
  assert(b_w1_1 == b_w1_2);
  assert(b_w2_1 == b_w2_2);
  assert(b_w3_1 == b_w3_2);
  assert(b_w4_1 == b_w4_2);
  assert(b_w5_1 == b_w5_2);
}


