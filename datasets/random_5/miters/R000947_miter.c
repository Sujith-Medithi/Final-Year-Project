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
struct SensorNode_R000947_4713_0
{
  int reading;
  int status;
  int offset;
  int threshold;
  int gain;
  int buffer[3];
};
struct Vector3D_R000947_4713_1
{
  unsigned char coord_x;
  int coord_z;
  short coord_y;
  short heading;
  unsigned char pitch;
  int buffer[3];
};
struct DeviceConfig_R000947_4713_2
{
  int baud_rate;
  short stop_bits;
  unsigned char parity;
  int buffer[3];
};
union ColorPixel_R000947_4713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000947_4713_1
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
void fn_R000947_4713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000947_4713_2 st_1 = {0};
  struct DeviceConfig_R000947_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int parity_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_60_1)
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

  switch (parity_60_2)
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
  int bound_40_1 = local_arr_1[aux_1 % 3];
  int bound_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_40_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_60_1 == parity_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_40_1 == bound_40_2);
}

int fn_R000947_4713_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000947_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int parity_60 = (aux + st.buffer[1]) & 3;
  switch (parity_60)
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
  int bound_40 = local_arr[aux % 3];
  acc = (acc + (bound_40 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000947_4713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000947_4713_0 st_1 = {0};
  struct SensorNode_R000947_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int damping_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_21_1 > 24)
  {
    acc_1 = ((acc_1 + (damping_21_1 * 2)) + 5) & 127;
    aux_1 ^= damping_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_21_2 > 24)
  {
    acc_2 = ((acc_2 + (damping_21_2 * 2)) + 5) & 127;
    aux_2 ^= damping_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_21_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_76_1 = local_arr_1[aux_1 % 3];
  int weight_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_76_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_21_1 == damping_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_76_1 == weight_76_2);
}

int fn_R000947_4713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000947_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int damping_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_21 > 24)
  {
    acc = ((acc + (damping_21 * 2)) + 5) & 127;
    aux ^= damping_21 & 15;
  }
  else
  {
    acc = ((acc - damping_21) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int weight_76 = local_arr[aux % 3];
  acc = (acc + (weight_76 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000947_4713_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000947_4713_0 st_1 = {0};
  struct SensorNode_R000947_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_76_1)
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

  switch (mask_76_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_76_1 == mask_76_2);
}

int fn_R000947_4713_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000947_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_76 = (aux + st.buffer[1]) & 3;
  switch (mask_76)
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

void fn_R000947_4713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000947_4713_0 st_1 = {0};
  struct SensorNode_R000947_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int factor_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_36_1 > 28)
  {
    acc_1 = ((acc_1 + (factor_36_1 * 2)) + 5) & 127;
    aux_1 ^= factor_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_36_2 > 28)
  {
    acc_2 = ((acc_2 + (factor_36_2 * 2)) + 5) & 127;
    aux_2 ^= factor_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_79_1) & 63;
  aux_2 = (aux_2 + delta_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_86_1)
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

  switch (parity_86_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_36_1 == factor_36_2);
  assert(delta_79_1 == delta_79_2);
  assert(parity_86_1 == parity_86_2);
}

int fn_R000947_4713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000947_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int factor_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_36 > 28)
  {
    acc = ((acc + (factor_36 * 2)) + 5) & 127;
    aux ^= factor_36 & 15;
  }
  else
  {
    acc = ((acc - factor_36) + 11) & 127;
    aux += 3;
  }
  int delta_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_79) & 63;
  acc ^= aux;
  int parity_86 = (aux + st.buffer[1]) & 3;
  switch (parity_86)
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

void fn_R000947_4713_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000947_4713_2 st_1 = {0};
  struct DeviceConfig_R000947_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_58_1 = local_arr_1[aux_1 % 3];
  int threshold_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_58_2 * 2)) & 127;
  int coefficient_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_83_1)
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

  switch (coefficient_83_2)
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

  int margin_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_25_1 > 27)
  {
    acc_1 = ((acc_1 + (margin_25_1 * 2)) + 5) & 127;
    aux_1 ^= margin_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_25_2 > 27)
  {
    acc_2 = ((acc_2 + (margin_25_2 * 2)) + 5) & 127;
    aux_2 ^= margin_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_25_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_58_1 == threshold_58_2);
  assert(coefficient_83_1 == coefficient_83_2);
  assert(margin_25_1 == margin_25_2);
}

int fn_R000947_4713_4(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000947_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int threshold_58 = local_arr[aux % 3];
  acc = (acc + (threshold_58 * 2)) & 127;
  int coefficient_83 = (aux + st.buffer[1]) & 3;
  switch (coefficient_83)
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

  int margin_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_25 > 27)
  {
    acc = ((acc + (margin_25 * 2)) + 5) & 127;
    aux ^= margin_25 & 15;
  }
  else
  {
    acc = ((acc - margin_25) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000947_4713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000947_4713_2 st_1 = {0};
  struct DeviceConfig_R000947_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_27_1 = local_arr_1[aux_1 % 3];
  int threshold_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_27_2 * 2)) & 127;
  int tracker_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_87_1) & 63;
  aux_2 = (aux_2 + tracker_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_75_1)
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

  switch (index_reg_75_2)
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

  int cursor_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_40_1 > 40)
  {
    acc_1 = ((acc_1 + (cursor_40_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_40_2 > 40)
  {
    acc_2 = ((acc_2 + (cursor_40_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_40_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_27_1 == threshold_27_2);
  assert(tracker_87_1 == tracker_87_2);
  assert(index_reg_75_1 == index_reg_75_2);
  assert(cursor_40_1 == cursor_40_2);
}

int fn_R000947_4713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000947_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int threshold_27 = local_arr[aux % 3];
  acc = (acc + (threshold_27 * 2)) & 127;
  int tracker_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_87) & 63;
  acc ^= aux;
  int index_reg_75 = (aux + st.buffer[1]) & 3;
  switch (index_reg_75)
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

  int cursor_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_40 > 40)
  {
    acc = ((acc + (cursor_40 * 2)) + 5) & 127;
    aux ^= cursor_40 & 15;
  }
  else
  {
    acc = ((acc - cursor_40) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000947_4713_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000947_4713_1 st_1 = {0};
  struct Vector3D_R000947_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_73_1 = local_arr_1[aux_1 % 3];
  int offset_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_73_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_73_1 == offset_73_2);
}

int fn_R000947_4713_6(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000947_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int offset_73 = local_arr[aux % 3];
  acc = (acc + (offset_73 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000947_4713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000947_4713_2 st_1 = {0};
  struct DeviceConfig_R000947_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int pivot_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_47_1) & 63;
  aux_2 = (aux_2 + pivot_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_99_1)
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

  switch (damping_99_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_47_1 == pivot_47_2);
  assert(damping_99_1 == damping_99_2);
}

int fn_R000947_4713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000947_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int pivot_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_47) & 63;
  acc ^= aux;
  int damping_99 = (aux + st.buffer[1]) & 3;
  switch (damping_99)
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

void fn_R000947_4713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000947_4713_1 st_1 = {0};
  struct Vector3D_R000947_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int scale_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_84_1 > 48)
  {
    acc_1 = ((acc_1 + (scale_84_1 * 2)) + 5) & 127;
    aux_1 ^= scale_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_84_2 > 48)
  {
    acc_2 = ((acc_2 + (scale_84_2 * 2)) + 5) & 127;
    aux_2 ^= scale_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_32_1 = local_arr_1[aux_1 % 3];
  int mask_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_32_2 * 2)) & 127;
  int anchor_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_73_1)
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

  switch (anchor_73_2)
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

  int offset_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_38_1) & 63;
  aux_2 = (aux_2 + offset_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_84_1 == scale_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_32_1 == mask_32_2);
  assert(anchor_73_1 == anchor_73_2);
  assert(offset_38_1 == offset_38_2);
}

int fn_R000947_4713_8(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000947_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int scale_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_84 > 48)
  {
    acc = ((acc + (scale_84 * 2)) + 5) & 127;
    aux ^= scale_84 & 15;
  }
  else
  {
    acc = ((acc - scale_84) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_32 = local_arr[aux % 3];
  acc = (acc + (mask_32 * 2)) & 127;
  int anchor_73 = (aux + st.buffer[1]) & 3;
  switch (anchor_73)
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

  int offset_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_38) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000947_4713_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000947_4713_2 st_1 = {0};
  struct DeviceConfig_R000947_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int checksum_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_80_1 > 18)
  {
    acc_1 = ((acc_1 + (checksum_80_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_80_2 > 18)
  {
    acc_2 = ((acc_2 + (checksum_80_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_80_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_45_1 = local_arr_1[aux_1 % 3];
  int quantum_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_45_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_80_1 == checksum_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_45_1 == quantum_45_2);
}

int fn_R000947_4713_9(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000947_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int checksum_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_80 > 18)
  {
    acc = ((acc + (checksum_80 * 2)) + 5) & 127;
    aux ^= checksum_80 & 15;
  }
  else
  {
    acc = ((acc - checksum_80) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_45 = local_arr[aux % 3];
  acc = (acc + (quantum_45 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000947_4713_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000947_4713_1 st_1 = {0};
  struct Vector3D_R000947_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_54_1 = local_arr_1[aux_1 % 3];
  int damping_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_54_2 * 2)) & 127;
  int scale_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_88_1 > 48)
  {
    acc_1 = ((acc_1 + (scale_88_1 * 2)) + 5) & 127;
    aux_1 ^= scale_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_88_2 > 48)
  {
    acc_2 = ((acc_2 + (scale_88_2 * 2)) + 5) & 127;
    aux_2 ^= scale_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_88_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_54_1 == damping_54_2);
  assert(scale_88_1 == scale_88_2);
}

int fn_R000947_4713_10(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000947_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int damping_54 = local_arr[aux % 3];
  acc = (acc + (damping_54 * 2)) & 127;
  int scale_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_88 > 48)
  {
    acc = ((acc + (scale_88 * 2)) + 5) & 127;
    aux ^= scale_88 & 15;
  }
  else
  {
    acc = ((acc - scale_88) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000947_4713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000947_4713_0 st_1 = {0};
  struct SensorNode_R000947_4713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int mask_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_63_1) & 63;
  aux_2 = (aux_2 + mask_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_45_1 = local_arr_1[aux_1 % 3];
  int vector_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_45_2 * 2)) & 127;
  int checksum_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_74_1 > 19)
  {
    acc_1 = ((acc_1 + (checksum_74_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_74_2 > 19)
  {
    acc_2 = ((acc_2 + (checksum_74_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_74_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_63_1 == mask_63_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_45_1 == vector_45_2);
  assert(checksum_74_1 == checksum_74_2);
}

int fn_R000947_4713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000947_4713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int mask_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_63) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int vector_45 = local_arr[aux % 3];
  acc = (acc + (vector_45 * 2)) & 127;
  int checksum_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_74 > 19)
  {
    acc = ((acc + (checksum_74 * 2)) + 5) & 127;
    aux ^= checksum_74 & 15;
  }
  else
  {
    acc = ((acc - checksum_74) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000947_4713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000947_4713_2 st_1 = {0};
  struct DeviceConfig_R000947_4713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_44_1)
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

  switch (margin_44_2)
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
  int margin_86_1 = local_arr_1[aux_1 % 3];
  int margin_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_86_2 * 2)) & 127;
  int offset_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_57_1) & 63;
  aux_2 = (aux_2 + offset_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_44_1 == margin_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_86_1 == margin_86_2);
  assert(offset_57_1 == offset_57_2);
}

int fn_R000947_4713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000947_4713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_44 = (aux + st.buffer[1]) & 3;
  switch (margin_44)
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
  int margin_86 = local_arr[aux % 3];
  acc = (acc + (margin_86 * 2)) & 127;
  int offset_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_57) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000947_4713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000947_4713_1 st_1 = {0};
  struct Vector3D_R000947_4713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int mask_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_57_1) & 63;
  aux_2 = (aux_2 + mask_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_79_1 = local_arr_1[aux_1 % 3];
  int coefficient_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_79_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_57_1 == mask_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_79_1 == coefficient_79_2);
}

int fn_R000947_4713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000947_4713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int mask_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_57) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int coefficient_79 = local_arr[aux % 3];
  acc = (acc + (coefficient_79 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000947_0_1;
  int sec_r000947_0_2;
  int sec_r000947_1_1;
  int sec_r000947_1_2;
  int sec_r000947_2_1;
  int sec_r000947_2_2;
  int sec_r000947_3_1;
  int sec_r000947_3_2;
  int sec_r000947_4_1;
  int sec_r000947_4_2;
  int sec_r000947_5_1;
  int sec_r000947_5_2;
  int sec_r000947_6_1;
  int sec_r000947_6_2;
  int sec_r000947_7_1;
  int sec_r000947_7_2;
  int sec_r000947_8_1;
  int sec_r000947_8_2;
  int sec_r000947_9_1;
  int sec_r000947_9_2;
  int sec_r000947_10_1;
  int sec_r000947_10_2;
  int sec_r000947_11_1;
  int sec_r000947_11_2;
  int sec_r000947_12_1;
  int sec_r000947_12_2;
  int sec_r000947_13_1;
  int sec_r000947_13_2;
  int sec_r000947_14_1;
  int sec_r000947_14_2;
  int sec_r000947_15_1;
  int sec_r000947_15_2;
  int sec_r000947_16_1;
  int sec_r000947_16_2;
  int sec_r000947_17_1;
  int sec_r000947_17_2;
  int sec_r000947_18_1;
  int sec_r000947_18_2;
  int sec_r000947_19_1;
  int sec_r000947_19_2;
  int sec_r000947_20_1;
  int sec_r000947_20_2;
  int sec_r000947_21_1;
  int sec_r000947_21_2;
  int sec_r000947_22_1;
  int sec_r000947_22_2;
  int pub_r000947_0_1;
  int pub_r000947_0_2;
  int pub_r000947_1_1;
  int pub_r000947_1_2;
  int pub_r000947_2_1;
  int pub_r000947_2_2;
  int pub_r000947_3_1;
  int pub_r000947_3_2;
  int pub_r000947_4_1;
  int pub_r000947_4_2;
  int pub_r000947_5_1;
  int pub_r000947_5_2;
  int pub_r000947_6_1;
  int pub_r000947_6_2;
  int pub_r000947_7_1;
  int pub_r000947_7_2;
  int pub_r000947_8_1;
  int pub_r000947_8_2;
  int pub_r000947_9_1;
  int pub_r000947_9_2;
  int pub_r000947_10_1;
  int pub_r000947_10_2;
  int pub_r000947_11_1;
  int pub_r000947_11_2;
  int pub_r000947_12_1;
  int pub_r000947_12_2;
  int pub_r000947_13_1;
  int pub_r000947_13_2;
  int pub_r000947_14_1;
  int pub_r000947_14_2;
  int pub_r000947_15_1;
  int pub_r000947_15_2;
  int pub_r000947_16_1;
  int pub_r000947_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000947_0_1 >= (-100)) && (pub_r000947_0_1 <= 100));
  __CPROVER_assume((pub_r000947_0_2 >= (-100)) && (pub_r000947_0_2 <= 100));
  __CPROVER_assume((pub_r000947_1_1 >= (-100)) && (pub_r000947_1_1 <= 100));
  __CPROVER_assume((pub_r000947_1_2 >= (-100)) && (pub_r000947_1_2 <= 100));
  __CPROVER_assume((pub_r000947_2_1 >= (-100)) && (pub_r000947_2_1 <= 100));
  __CPROVER_assume((pub_r000947_2_2 >= (-100)) && (pub_r000947_2_2 <= 100));
  __CPROVER_assume((pub_r000947_3_1 >= (-100)) && (pub_r000947_3_1 <= 100));
  __CPROVER_assume((pub_r000947_3_2 >= (-100)) && (pub_r000947_3_2 <= 100));
  __CPROVER_assume((pub_r000947_4_1 >= (-100)) && (pub_r000947_4_1 <= 100));
  __CPROVER_assume((pub_r000947_4_2 >= (-100)) && (pub_r000947_4_2 <= 100));
  __CPROVER_assume((pub_r000947_5_1 >= (-100)) && (pub_r000947_5_1 <= 100));
  __CPROVER_assume((pub_r000947_5_2 >= (-100)) && (pub_r000947_5_2 <= 100));
  __CPROVER_assume((pub_r000947_6_1 >= (-100)) && (pub_r000947_6_1 <= 100));
  __CPROVER_assume((pub_r000947_6_2 >= (-100)) && (pub_r000947_6_2 <= 100));
  __CPROVER_assume((pub_r000947_7_1 >= (-100)) && (pub_r000947_7_1 <= 100));
  __CPROVER_assume((pub_r000947_7_2 >= (-100)) && (pub_r000947_7_2 <= 100));
  __CPROVER_assume((pub_r000947_8_1 >= (-100)) && (pub_r000947_8_1 <= 100));
  __CPROVER_assume((pub_r000947_8_2 >= (-100)) && (pub_r000947_8_2 <= 100));
  __CPROVER_assume((pub_r000947_9_1 >= (-100)) && (pub_r000947_9_1 <= 100));
  __CPROVER_assume((pub_r000947_9_2 >= (-100)) && (pub_r000947_9_2 <= 100));
  __CPROVER_assume((pub_r000947_10_1 >= (-100)) && (pub_r000947_10_1 <= 100));
  __CPROVER_assume((pub_r000947_10_2 >= (-100)) && (pub_r000947_10_2 <= 100));
  __CPROVER_assume((pub_r000947_11_1 >= (-100)) && (pub_r000947_11_1 <= 100));
  __CPROVER_assume((pub_r000947_11_2 >= (-100)) && (pub_r000947_11_2 <= 100));
  __CPROVER_assume((pub_r000947_12_1 >= (-100)) && (pub_r000947_12_1 <= 100));
  __CPROVER_assume((pub_r000947_12_2 >= (-100)) && (pub_r000947_12_2 <= 100));
  __CPROVER_assume((pub_r000947_13_1 >= (-100)) && (pub_r000947_13_1 <= 100));
  __CPROVER_assume((pub_r000947_13_2 >= (-100)) && (pub_r000947_13_2 <= 100));
  __CPROVER_assume((pub_r000947_14_1 >= (-100)) && (pub_r000947_14_1 <= 100));
  __CPROVER_assume((pub_r000947_14_2 >= (-100)) && (pub_r000947_14_2 <= 100));
  __CPROVER_assume((pub_r000947_15_1 >= (-100)) && (pub_r000947_15_1 <= 100));
  __CPROVER_assume((pub_r000947_15_2 >= (-100)) && (pub_r000947_15_2 <= 100));
  __CPROVER_assume((pub_r000947_16_1 >= (-100)) && (pub_r000947_16_1 <= 100));
  __CPROVER_assume((pub_r000947_16_2 >= (-100)) && (pub_r000947_16_2 <= 100));
  __CPROVER_assume((sec_r000947_0_1 >= 0) && (sec_r000947_0_1 <= 255));
  __CPROVER_assume((sec_r000947_0_2 >= 0) && (sec_r000947_0_2 <= 255));
  __CPROVER_assume((sec_r000947_1_1 >= 0) && (sec_r000947_1_1 <= 255));
  __CPROVER_assume((sec_r000947_1_2 >= 0) && (sec_r000947_1_2 <= 255));
  __CPROVER_assume((sec_r000947_2_1 >= 0) && (sec_r000947_2_1 <= 255));
  __CPROVER_assume((sec_r000947_2_2 >= 0) && (sec_r000947_2_2 <= 255));
  __CPROVER_assume((sec_r000947_3_1 >= 0) && (sec_r000947_3_1 <= 255));
  __CPROVER_assume((sec_r000947_3_2 >= 0) && (sec_r000947_3_2 <= 255));
  __CPROVER_assume((sec_r000947_4_1 >= 0) && (sec_r000947_4_1 <= 255));
  __CPROVER_assume((sec_r000947_4_2 >= 0) && (sec_r000947_4_2 <= 255));
  __CPROVER_assume((sec_r000947_5_1 >= 0) && (sec_r000947_5_1 <= 255));
  __CPROVER_assume((sec_r000947_5_2 >= 0) && (sec_r000947_5_2 <= 255));
  __CPROVER_assume((sec_r000947_6_1 >= 0) && (sec_r000947_6_1 <= 255));
  __CPROVER_assume((sec_r000947_6_2 >= 0) && (sec_r000947_6_2 <= 255));
  __CPROVER_assume((sec_r000947_7_1 >= 0) && (sec_r000947_7_1 <= 255));
  __CPROVER_assume((sec_r000947_7_2 >= 0) && (sec_r000947_7_2 <= 255));
  __CPROVER_assume((sec_r000947_8_1 >= 0) && (sec_r000947_8_1 <= 255));
  __CPROVER_assume((sec_r000947_8_2 >= 0) && (sec_r000947_8_2 <= 255));
  __CPROVER_assume((sec_r000947_9_1 >= 0) && (sec_r000947_9_1 <= 255));
  __CPROVER_assume((sec_r000947_9_2 >= 0) && (sec_r000947_9_2 <= 255));
  __CPROVER_assume((sec_r000947_10_1 >= 0) && (sec_r000947_10_1 <= 255));
  __CPROVER_assume((sec_r000947_10_2 >= 0) && (sec_r000947_10_2 <= 255));
  __CPROVER_assume((sec_r000947_11_1 >= 0) && (sec_r000947_11_1 <= 255));
  __CPROVER_assume((sec_r000947_11_2 >= 0) && (sec_r000947_11_2 <= 255));
  __CPROVER_assume((sec_r000947_12_1 >= 0) && (sec_r000947_12_1 <= 255));
  __CPROVER_assume((sec_r000947_12_2 >= 0) && (sec_r000947_12_2 <= 255));
  __CPROVER_assume((sec_r000947_13_1 >= 0) && (sec_r000947_13_1 <= 255));
  __CPROVER_assume((sec_r000947_13_2 >= 0) && (sec_r000947_13_2 <= 255));
  __CPROVER_assume((sec_r000947_14_1 >= 0) && (sec_r000947_14_1 <= 255));
  __CPROVER_assume((sec_r000947_14_2 >= 0) && (sec_r000947_14_2 <= 255));
  __CPROVER_assume((sec_r000947_15_1 >= 0) && (sec_r000947_15_1 <= 255));
  __CPROVER_assume((sec_r000947_15_2 >= 0) && (sec_r000947_15_2 <= 255));
  __CPROVER_assume((sec_r000947_16_1 >= 0) && (sec_r000947_16_1 <= 255));
  __CPROVER_assume((sec_r000947_16_2 >= 0) && (sec_r000947_16_2 <= 255));
  __CPROVER_assume((sec_r000947_17_1 >= 0) && (sec_r000947_17_1 <= 255));
  __CPROVER_assume((sec_r000947_17_2 >= 0) && (sec_r000947_17_2 <= 255));
  __CPROVER_assume((sec_r000947_18_1 >= 0) && (sec_r000947_18_1 <= 255));
  __CPROVER_assume((sec_r000947_18_2 >= 0) && (sec_r000947_18_2 <= 255));
  __CPROVER_assume((sec_r000947_19_1 >= 0) && (sec_r000947_19_1 <= 255));
  __CPROVER_assume((sec_r000947_19_2 >= 0) && (sec_r000947_19_2 <= 255));
  __CPROVER_assume((sec_r000947_20_1 >= 0) && (sec_r000947_20_1 <= 255));
  __CPROVER_assume((sec_r000947_20_2 >= 0) && (sec_r000947_20_2 <= 255));
  __CPROVER_assume((sec_r000947_21_1 >= 0) && (sec_r000947_21_1 <= 255));
  __CPROVER_assume((sec_r000947_21_2 >= 0) && (sec_r000947_21_2 <= 255));
  __CPROVER_assume((sec_r000947_22_1 >= 0) && (sec_r000947_22_1 <= 255));
  __CPROVER_assume((sec_r000947_22_2 >= 0) && (sec_r000947_22_2 <= 255));
  struct SensorNode_R000947_4713_0 st_var_0_1 = {0};
  struct SensorNode_R000947_4713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000947_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000947_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000947_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000947_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000947_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000947_0_2 + 7) & 15;
  struct Vector3D_R000947_4713_1 st_var_1_1 = {0};
  struct Vector3D_R000947_4713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000947_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000947_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000947_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000947_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000947_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000947_0_2 + 9) & 15;
  struct DeviceConfig_R000947_4713_2 st_var_2_1 = {0};
  struct DeviceConfig_R000947_4713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000947_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000947_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000947_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000947_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000947_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000947_0_2 + 11) & 15;
  union ColorPixel_R000947_4713_0 u_var_1;
  union ColorPixel_R000947_4713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 38)
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
  if (stage_v_0_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 38)
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
  int stage_v_4_1 = ((st_var_1_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_1_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 31)
    {
      chk_sum_1 ^= stage_v_4_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_4_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 31)
    {
      chk_sum_2 ^= stage_v_4_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 6) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
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
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
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
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = table_1[0];
  int stage_v_12_2 = table_2[0];
  table_1[0] = (table_1[1] + 25) & 63;
  table_2[0] = (table_2[1] + 25) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
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
  int stage_v_15_1 = (st_var_0_1.buffer[0] ^ 18) & 3;
  int stage_v_15_2 = (st_var_0_2.buffer[0] ^ 18) & 3;
  switch (stage_v_15_1)
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

  switch (stage_v_15_2)
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

  int stage_v_16_1 = ((st_var_1_1.buffer[1] * 2) + 55) & 63;
  int stage_v_16_2 = ((st_var_1_2.buffer[1] * 2) + 55) & 63;
  if (stage_v_16_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_16_1) - 5) & 255;
    if (stage_v_16_1 > 50)
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
  if (stage_v_16_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_16_2) - 5) & 255;
    if (stage_v_16_2 > 50)
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
  if (stage_v_17_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 37)
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
  if (stage_v_17_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 37)
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
  int stage_v_19_1 = (st_var_1_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_1_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  int stage_v_21_1 = ((st_var_0_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_0_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 45)
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
  if (stage_v_21_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 45)
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
  if ((sec_r000947_14_1 & 1) != 0)
  {
    if ((sec_r000947_18_1 & 2) != 0)
    {
      stage_v_22_1 = (pub_r000947_8_1 + 31) & 127;
    }
    else
    {
      stage_v_22_1 = (pub_r000947_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_22_1 = (pub_r000947_8_1 + 7) & 127;
  }
  if ((sec_r000947_14_2 & 1) != 0)
  {
    if ((sec_r000947_18_2 & 2) != 0)
    {
      stage_v_22_2 = (pub_r000947_8_2 + 31) & 127;
    }
    else
    {
      stage_v_22_2 = (pub_r000947_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_22_2 = (pub_r000947_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  if ((sec_r000947_17_1 & 1) != 0)
  {
    if ((sec_r000947_6_1 & 2) != 0)
    {
      stage_v_23_1 = (pub_r000947_7_1 + 31) & 127;
    }
    else
    {
      stage_v_23_1 = (pub_r000947_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_23_1 = (pub_r000947_7_1 + 7) & 127;
  }
  if ((sec_r000947_17_2 & 1) != 0)
  {
    if ((sec_r000947_6_2 & 2) != 0)
    {
      stage_v_23_2 = (pub_r000947_7_2 + 31) & 127;
    }
    else
    {
      stage_v_23_2 = (pub_r000947_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_23_2 = (pub_r000947_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  if ((sec_r000947_1_1 & 1) != 0)
  {
    if ((sec_r000947_11_1 & 2) != 0)
    {
      stage_v_24_1 = (pub_r000947_10_1 + 31) & 127;
    }
    else
    {
      stage_v_24_1 = (pub_r000947_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_24_1 = (pub_r000947_10_1 + 7) & 127;
  }
  if ((sec_r000947_1_2 & 1) != 0)
  {
    if ((sec_r000947_11_2 & 2) != 0)
    {
      stage_v_24_2 = (pub_r000947_10_2 + 31) & 127;
    }
    else
    {
      stage_v_24_2 = (pub_r000947_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_24_2 = (pub_r000947_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r000947_15_1 & 2) != 0)
    {
      stage_v_25_1 = (pub_r000947_6_1 + 31) & 127;
    }
    else
    {
      stage_v_25_1 = (pub_r000947_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_1 = (pub_r000947_6_1 + 7) & 127;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r000947_15_2 & 2) != 0)
    {
      stage_v_25_2 = (pub_r000947_6_2 + 31) & 127;
    }
    else
    {
      stage_v_25_2 = (pub_r000947_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_2 = (pub_r000947_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  if ((sec_r000947_8_1 & 1) != 0)
  {
    if ((sec_r000947_22_1 & 2) != 0)
    {
      stage_v_26_1 = (pub_r000947_9_1 + 31) & 127;
    }
    else
    {
      stage_v_26_1 = (pub_r000947_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_1 = (pub_r000947_9_1 + 7) & 127;
  }
  if ((sec_r000947_8_2 & 1) != 0)
  {
    if ((sec_r000947_22_2 & 2) != 0)
    {
      stage_v_26_2 = (pub_r000947_9_2 + 31) & 127;
    }
    else
    {
      stage_v_26_2 = (pub_r000947_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_2 = (pub_r000947_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  if ((sec_r000947_3_1 & 1) != 0)
  {
    if ((sec_r000947_12_1 & 2) != 0)
    {
      stage_v_27_1 = (pub_r000947_5_1 + 31) & 127;
    }
    else
    {
      stage_v_27_1 = (pub_r000947_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_1 = (pub_r000947_5_1 + 7) & 127;
  }
  if ((sec_r000947_3_2 & 1) != 0)
  {
    if ((sec_r000947_12_2 & 2) != 0)
    {
      stage_v_27_2 = (pub_r000947_5_2 + 31) & 127;
    }
    else
    {
      stage_v_27_2 = (pub_r000947_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_2 = (pub_r000947_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  if ((sec_r000947_9_1 & 1) != 0)
  {
    if ((sec_r000947_22_1 & 2) != 0)
    {
      stage_v_28_1 = (pub_r000947_1_1 + 31) & 127;
    }
    else
    {
      stage_v_28_1 = (pub_r000947_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_1 = (pub_r000947_1_1 + 7) & 127;
  }
  if ((sec_r000947_9_2 & 1) != 0)
  {
    if ((sec_r000947_22_2 & 2) != 0)
    {
      stage_v_28_2 = (pub_r000947_1_2 + 31) & 127;
    }
    else
    {
      stage_v_28_2 = (pub_r000947_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_2 = (pub_r000947_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  if ((sec_r000947_18_1 & 1) != 0)
  {
    if ((sec_r000947_11_1 & 2) != 0)
    {
      stage_v_29_1 = (pub_r000947_11_1 + 31) & 127;
    }
    else
    {
      stage_v_29_1 = (pub_r000947_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_1 = (pub_r000947_11_1 + 7) & 127;
  }
  if ((sec_r000947_18_2 & 1) != 0)
  {
    if ((sec_r000947_11_2 & 2) != 0)
    {
      stage_v_29_2 = (pub_r000947_11_2 + 31) & 127;
    }
    else
    {
      stage_v_29_2 = (pub_r000947_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_2 = (pub_r000947_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  if ((sec_r000947_15_1 & 1) != 0)
  {
    if ((sec_r000947_10_1 & 2) != 0)
    {
      stage_v_30_1 = (pub_r000947_16_1 + 31) & 127;
    }
    else
    {
      stage_v_30_1 = (pub_r000947_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_1 = (pub_r000947_16_1 + 7) & 127;
  }
  if ((sec_r000947_15_2 & 1) != 0)
  {
    if ((sec_r000947_10_2 & 2) != 0)
    {
      stage_v_30_2 = (pub_r000947_16_2 + 31) & 127;
    }
    else
    {
      stage_v_30_2 = (pub_r000947_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_2 = (pub_r000947_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  if ((sec_r000947_12_1 & 1) != 0)
  {
    if ((sec_r000947_5_1 & 2) != 0)
    {
      stage_v_31_1 = (pub_r000947_15_1 + 31) & 127;
    }
    else
    {
      stage_v_31_1 = (pub_r000947_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_1 = (pub_r000947_15_1 + 7) & 127;
  }
  if ((sec_r000947_12_2 & 1) != 0)
  {
    if ((sec_r000947_5_2 & 2) != 0)
    {
      stage_v_31_2 = (pub_r000947_15_2 + 31) & 127;
    }
    else
    {
      stage_v_31_2 = (pub_r000947_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_2 = (pub_r000947_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000947_17_1 & 2) != 0)
    {
      stage_v_32_1 = (pub_r000947_5_1 + 31) & 127;
    }
    else
    {
      stage_v_32_1 = (pub_r000947_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_1 = (pub_r000947_5_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000947_17_2 & 2) != 0)
    {
      stage_v_32_2 = (pub_r000947_5_2 + 31) & 127;
    }
    else
    {
      stage_v_32_2 = (pub_r000947_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_2 = (pub_r000947_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000947_8_1 & 2) != 0)
    {
      stage_v_33_1 = (pub_r000947_2_1 + 31) & 127;
    }
    else
    {
      stage_v_33_1 = (pub_r000947_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_1 = (pub_r000947_2_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000947_8_2 & 2) != 0)
    {
      stage_v_33_2 = (pub_r000947_2_2 + 31) & 127;
    }
    else
    {
      stage_v_33_2 = (pub_r000947_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_2 = (pub_r000947_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((sec_r000947_3_1 & 2) != 0)
    {
      stage_v_34_1 = (pub_r000947_4_1 + 31) & 127;
    }
    else
    {
      stage_v_34_1 = (pub_r000947_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_1 = (pub_r000947_4_1 + 7) & 127;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((sec_r000947_3_2 & 2) != 0)
    {
      stage_v_34_2 = (pub_r000947_4_2 + 31) & 127;
    }
    else
    {
      stage_v_34_2 = (pub_r000947_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_2 = (pub_r000947_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((sec_r000947_20_1 & 1) != 0)
  {
    if ((sec_r000947_16_1 & 2) != 0)
    {
      stage_v_35_1 = (pub_r000947_0_1 + 31) & 127;
    }
    else
    {
      stage_v_35_1 = (pub_r000947_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_1 = (pub_r000947_0_1 + 7) & 127;
  }
  if ((sec_r000947_20_2 & 1) != 0)
  {
    if ((sec_r000947_16_2 & 2) != 0)
    {
      stage_v_35_2 = (pub_r000947_0_2 + 31) & 127;
    }
    else
    {
      stage_v_35_2 = (pub_r000947_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_2 = (pub_r000947_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000947_6_1 & 2) != 0)
    {
      stage_v_36_1 = (pub_r000947_10_1 + 31) & 127;
    }
    else
    {
      stage_v_36_1 = (pub_r000947_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_1 = (pub_r000947_10_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000947_6_2 & 2) != 0)
    {
      stage_v_36_2 = (pub_r000947_10_2 + 31) & 127;
    }
    else
    {
      stage_v_36_2 = (pub_r000947_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_2 = (pub_r000947_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000947_21_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000947_9_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000947_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000947_9_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000947_21_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000947_9_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000947_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000947_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000947_1_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000947_3_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000947_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000947_3_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000947_1_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000947_3_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000947_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000947_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000947_14_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000947_2_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000947_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000947_2_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000947_14_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000947_2_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000947_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000947_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000947_21_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000947_2_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000947_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000947_2_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000947_21_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000947_2_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000947_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000947_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r000947_11_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000947_4_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000947_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000947_4_1 + 7) & 127;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r000947_11_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000947_4_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000947_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000947_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000947_8_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000947_9_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000947_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000947_9_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000947_8_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000947_9_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000947_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000947_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((sec_r000947_11_1 & 1) != 0)
  {
    if ((sec_r000947_4_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000947_16_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000947_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000947_16_1 + 7) & 127;
  }
  if ((sec_r000947_11_2 & 1) != 0)
  {
    if ((sec_r000947_4_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000947_16_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000947_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000947_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000947_1_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000947_3_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000947_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000947_3_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000947_1_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000947_3_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000947_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000947_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000947_21_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000947_11_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000947_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000947_11_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000947_21_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000947_11_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000947_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000947_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((sec_r000947_10_1 & 1) != 0)
  {
    if ((sec_r000947_20_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000947_3_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000947_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000947_3_1 + 7) & 127;
  }
  if ((sec_r000947_10_2 & 1) != 0)
  {
    if ((sec_r000947_20_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000947_3_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000947_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000947_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000947_7_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000947_3_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000947_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000947_3_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000947_7_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000947_3_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000947_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000947_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((sec_r000947_8_1 & 1) != 0)
  {
    if ((sec_r000947_17_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000947_8_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000947_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000947_8_1 + 7) & 127;
  }
  if ((sec_r000947_8_2 & 1) != 0)
  {
    if ((sec_r000947_17_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000947_8_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000947_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000947_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r000947_10_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000947_5_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000947_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000947_5_1 + 7) & 127;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r000947_10_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000947_5_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000947_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000947_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000947_1_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000947_6_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000947_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000947_6_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000947_1_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000947_6_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000947_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000947_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000947_22_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000947_6_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000947_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000947_6_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000947_22_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000947_6_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000947_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000947_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000947_5_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000947_4_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000947_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000947_4_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000947_5_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000947_4_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000947_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000947_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000947_21_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000947_5_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000947_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000947_5_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000947_21_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000947_5_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000947_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000947_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((sec_r000947_11_1 & 1) != 0)
  {
    if ((sec_r000947_16_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000947_10_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000947_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000947_10_1 + 7) & 127;
  }
  if ((sec_r000947_11_2 & 1) != 0)
  {
    if ((sec_r000947_16_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000947_10_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000947_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000947_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000947_14_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000947_2_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000947_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000947_2_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000947_14_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000947_2_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000947_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000947_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000947_16_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000947_3_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000947_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000947_3_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000947_16_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000947_3_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000947_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000947_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000947_21_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000947_4_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000947_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000947_4_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000947_21_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000947_4_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000947_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000947_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((sec_r000947_22_1 & 1) != 0)
  {
    if ((sec_r000947_16_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000947_7_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000947_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000947_7_1 + 7) & 127;
  }
  if ((sec_r000947_22_2 & 1) != 0)
  {
    if ((sec_r000947_16_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000947_7_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000947_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000947_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000947_0_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000947_4_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000947_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000947_4_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000947_0_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000947_4_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000947_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000947_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000947_17_1 & 1) != 0)
  {
    if ((sec_r000947_22_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000947_12_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000947_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000947_12_1 + 7) & 127;
  }
  if ((sec_r000947_17_2 & 1) != 0)
  {
    if ((sec_r000947_22_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000947_12_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000947_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000947_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((sec_r000947_6_1 & 1) != 0)
  {
    if ((sec_r000947_0_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000947_5_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000947_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000947_5_1 + 7) & 127;
  }
  if ((sec_r000947_6_2 & 1) != 0)
  {
    if ((sec_r000947_0_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000947_5_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000947_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000947_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((sec_r000947_5_1 & 1) != 0)
  {
    if ((sec_r000947_4_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000947_12_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000947_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000947_12_1 + 7) & 127;
  }
  if ((sec_r000947_5_2 & 1) != 0)
  {
    if ((sec_r000947_4_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000947_12_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000947_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000947_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000947_11_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000947_13_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000947_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000947_13_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000947_11_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000947_13_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000947_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000947_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000947_18_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000947_13_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000947_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000947_13_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000947_18_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000947_13_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000947_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000947_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r000947_22_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000947_0_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000947_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000947_0_1 + 7) & 127;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r000947_22_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000947_0_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000947_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000947_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000947_14_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000947_0_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000947_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000947_0_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000947_14_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000947_0_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000947_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000947_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000947_1_1 & 1) != 0)
  {
    if ((sec_r000947_15_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000947_14_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000947_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000947_14_1 + 7) & 127;
  }
  if ((sec_r000947_1_2 & 1) != 0)
  {
    if ((sec_r000947_15_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000947_14_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000947_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000947_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r000947_7_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000947_8_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000947_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000947_8_1 + 7) & 127;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r000947_7_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000947_8_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000947_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000947_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000947_6_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000947_3_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000947_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000947_3_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000947_6_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000947_3_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000947_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000947_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r000947_5_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000947_14_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000947_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000947_14_1 + 7) & 127;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r000947_5_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000947_14_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000947_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000947_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((sec_r000947_8_1 & 1) != 0)
  {
    if ((sec_r000947_22_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000947_12_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000947_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000947_12_1 + 7) & 127;
  }
  if ((sec_r000947_8_2 & 1) != 0)
  {
    if ((sec_r000947_22_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000947_12_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000947_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000947_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r000947_12_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000947_1_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000947_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000947_1_1 + 7) & 127;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r000947_12_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000947_1_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000947_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000947_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000947_9_1 & 1) != 0)
  {
    if ((sec_r000947_22_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000947_10_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000947_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000947_10_1 + 7) & 127;
  }
  if ((sec_r000947_9_2 & 1) != 0)
  {
    if ((sec_r000947_22_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000947_10_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000947_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000947_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r000947_22_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000947_6_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000947_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000947_6_1 + 7) & 127;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r000947_22_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000947_6_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000947_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000947_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000947_7_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000947_5_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000947_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000947_5_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000947_7_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000947_5_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000947_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000947_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000947_17_1 & 1) != 0)
  {
    if ((sec_r000947_19_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000947_3_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000947_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000947_3_1 + 7) & 127;
  }
  if ((sec_r000947_17_2 & 1) != 0)
  {
    if ((sec_r000947_19_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000947_3_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000947_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000947_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000947_21_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000947_5_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000947_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000947_5_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000947_21_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000947_5_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000947_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000947_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000947_11_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000947_8_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000947_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000947_8_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000947_11_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000947_8_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000947_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000947_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000947_3_1 & 1) != 0)
  {
    if ((sec_r000947_21_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000947_15_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000947_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000947_15_1 + 7) & 127;
  }
  if ((sec_r000947_3_2 & 1) != 0)
  {
    if ((sec_r000947_21_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000947_15_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000947_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000947_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r000947_15_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000947_10_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000947_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000947_10_1 + 7) & 127;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r000947_15_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000947_10_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000947_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000947_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000947_14_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000947_2_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000947_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000947_2_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000947_14_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000947_2_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000947_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000947_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000947_5_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000947_11_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000947_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000947_11_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000947_5_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000947_11_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000947_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000947_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000947_1_1 & 1) != 0)
  {
    if ((sec_r000947_5_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000947_0_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000947_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000947_0_1 + 7) & 127;
  }
  if ((sec_r000947_1_2 & 1) != 0)
  {
    if ((sec_r000947_5_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000947_0_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000947_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000947_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000947_3_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000947_10_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000947_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000947_10_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000947_3_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000947_10_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000947_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000947_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000947_19_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000947_2_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000947_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000947_2_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000947_19_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000947_2_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000947_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000947_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000947_16_1 & 1) != 0)
  {
    if ((sec_r000947_8_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000947_0_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000947_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000947_0_1 + 7) & 127;
  }
  if ((sec_r000947_16_2 & 1) != 0)
  {
    if ((sec_r000947_8_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000947_0_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000947_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000947_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000947_7_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000947_1_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000947_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000947_1_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000947_7_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000947_1_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000947_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000947_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000947_0_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000947_2_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000947_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000947_2_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000947_0_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000947_2_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000947_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000947_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000947_3_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000947_14_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000947_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000947_14_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000947_3_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000947_14_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000947_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000947_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000947_6_1 & 1) != 0)
  {
    if ((sec_r000947_7_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000947_1_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000947_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000947_1_1 + 7) & 127;
  }
  if ((sec_r000947_6_2 & 1) != 0)
  {
    if ((sec_r000947_7_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000947_1_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000947_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000947_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000947_17_1 & 1) != 0)
  {
    if ((sec_r000947_22_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000947_16_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000947_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000947_16_1 + 7) & 127;
  }
  if ((sec_r000947_17_2 & 1) != 0)
  {
    if ((sec_r000947_22_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000947_16_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000947_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000947_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000947_19_1 & 1) != 0)
  {
    if ((sec_r000947_6_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000947_0_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000947_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000947_0_1 + 7) & 127;
  }
  if ((sec_r000947_19_2 & 1) != 0)
  {
    if ((sec_r000947_6_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000947_0_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000947_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000947_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000947_22_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000947_9_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000947_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000947_9_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000947_22_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000947_9_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000947_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000947_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000947_11_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000947_2_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000947_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000947_2_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000947_11_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000947_2_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000947_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000947_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000947_0_1 & 1) != 0)
  {
    if ((sec_r000947_15_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000947_8_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000947_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000947_8_1 + 7) & 127;
  }
  if ((sec_r000947_0_2 & 1) != 0)
  {
    if ((sec_r000947_15_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000947_8_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000947_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000947_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000947_9_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000947_14_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000947_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000947_14_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000947_9_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000947_14_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000947_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000947_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000947_10_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000947_0_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000947_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000947_0_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000947_10_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000947_0_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000947_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000947_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000947_1_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000947_5_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000947_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000947_5_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000947_1_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000947_5_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000947_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000947_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000947_6_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000947_6_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000947_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000947_6_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000947_6_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000947_6_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000947_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000947_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000947_4_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000947_14_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000947_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000947_14_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000947_4_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000947_14_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000947_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000947_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000947_6_1 & 1) != 0)
  {
    if ((sec_r000947_4_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000947_2_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000947_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000947_2_1 + 7) & 127;
  }
  if ((sec_r000947_6_2 & 1) != 0)
  {
    if ((sec_r000947_4_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000947_2_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000947_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000947_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000947_11_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000947_1_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000947_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000947_1_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000947_11_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000947_1_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000947_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000947_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000947_20_1 & 1) != 0)
  {
    if ((sec_r000947_13_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000947_9_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000947_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000947_9_1 + 7) & 127;
  }
  if ((sec_r000947_20_2 & 1) != 0)
  {
    if ((sec_r000947_13_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000947_9_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000947_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000947_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000947_9_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000947_15_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000947_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000947_15_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000947_9_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000947_15_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000947_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000947_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000947_8_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000947_14_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000947_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000947_14_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000947_8_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000947_14_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000947_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000947_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r000947_9_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000947_6_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000947_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000947_6_1 + 7) & 127;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r000947_9_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000947_6_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000947_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000947_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000947_1_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000947_12_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000947_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000947_12_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000947_1_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000947_12_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000947_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000947_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000947_22_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000947_14_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000947_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000947_14_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000947_22_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000947_14_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000947_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000947_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000947_20_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000947_5_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000947_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000947_5_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000947_20_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000947_5_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000947_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000947_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000947_11_1 & 1) != 0)
  {
    if ((sec_r000947_4_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000947_5_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000947_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000947_5_1 + 7) & 127;
  }
  if ((sec_r000947_11_2 & 1) != 0)
  {
    if ((sec_r000947_4_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000947_5_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000947_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000947_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((sec_r000947_9_1 & 1) != 0)
  {
    if ((sec_r000947_15_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000947_8_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000947_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000947_8_1 + 7) & 127;
  }
  if ((sec_r000947_9_2 & 1) != 0)
  {
    if ((sec_r000947_15_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000947_8_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000947_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000947_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000947_14_1 & 1) != 0)
  {
    if ((sec_r000947_12_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000947_4_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000947_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000947_4_1 + 7) & 127;
  }
  if ((sec_r000947_14_2 & 1) != 0)
  {
    if ((sec_r000947_12_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000947_4_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000947_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000947_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000947_6_1 & 1) != 0)
  {
    if ((sec_r000947_7_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000947_16_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000947_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000947_16_1 + 7) & 127;
  }
  if ((sec_r000947_6_2 & 1) != 0)
  {
    if ((sec_r000947_7_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000947_16_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000947_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000947_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((sec_r000947_18_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000947_14_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000947_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000947_14_1 + 7) & 127;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((sec_r000947_18_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000947_14_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000947_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000947_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000947_22_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000947_2_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000947_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000947_2_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000947_22_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000947_2_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000947_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000947_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000947_12_1 & 1) != 0)
  {
    if ((sec_r000947_18_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000947_4_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000947_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000947_4_1 + 7) & 127;
  }
  if ((sec_r000947_12_2 & 1) != 0)
  {
    if ((sec_r000947_18_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000947_4_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000947_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000947_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000947_0_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000947_3_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000947_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000947_3_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000947_0_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000947_3_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000947_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000947_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000947_4_1 & 1) != 0)
  {
    if ((sec_r000947_1_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000947_9_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000947_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000947_9_1 + 7) & 127;
  }
  if ((sec_r000947_4_2 & 1) != 0)
  {
    if ((sec_r000947_1_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000947_9_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000947_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000947_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000947_11_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000947_2_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000947_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000947_2_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000947_11_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000947_2_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000947_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000947_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r000947_22_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000947_14_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000947_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000947_14_1 + 7) & 127;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r000947_22_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000947_14_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000947_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000947_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000947_15_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000947_8_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000947_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000947_8_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000947_15_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000947_8_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000947_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000947_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000947_1_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000947_6_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000947_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000947_6_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000947_1_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000947_6_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000947_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000947_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000947_6_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000947_3_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000947_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000947_3_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000947_6_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000947_3_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000947_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000947_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000947_11_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000947_2_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000947_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000947_2_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000947_11_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000947_2_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000947_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000947_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000947_0_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000947_3_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000947_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000947_3_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000947_0_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000947_3_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000947_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000947_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000947_2_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000947_13_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000947_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000947_13_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000947_2_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000947_13_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000947_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000947_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000947_10_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000947_1_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000947_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000947_1_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000947_10_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000947_1_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000947_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000947_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000947_18_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000947_2_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000947_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000947_2_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000947_18_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000947_2_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000947_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000947_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000947_7_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000947_7_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000947_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000947_7_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000947_7_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000947_7_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000947_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000947_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000947_21_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000947_1_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000947_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000947_1_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000947_21_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000947_1_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000947_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000947_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_70_1 & 1) != 0)
  {
    if ((sec_r000947_3_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000947_9_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000947_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000947_9_1 + 7) & 127;
  }
  if ((stage_v_70_2 & 1) != 0)
  {
    if ((sec_r000947_3_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000947_9_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000947_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000947_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((sec_r000947_16_1 & 1) != 0)
  {
    if ((sec_r000947_15_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000947_2_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000947_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000947_2_1 + 7) & 127;
  }
  if ((sec_r000947_16_2 & 1) != 0)
  {
    if ((sec_r000947_15_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000947_2_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000947_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000947_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000947_20_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000947_15_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000947_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000947_15_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000947_20_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000947_15_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000947_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000947_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r000947_14_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000947_12_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000947_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000947_12_1 + 7) & 127;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((sec_r000947_14_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000947_12_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000947_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000947_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000947_16_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000947_6_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000947_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000947_6_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000947_16_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000947_6_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000947_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000947_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000947_1_1 & 1) != 0)
  {
    if ((sec_r000947_18_1 & 2) != 0)
    {
      stage_v_136_1 = (pub_r000947_12_1 + 31) & 127;
    }
    else
    {
      stage_v_136_1 = (pub_r000947_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_1 = (pub_r000947_12_1 + 7) & 127;
  }
  if ((sec_r000947_1_2 & 1) != 0)
  {
    if ((sec_r000947_18_2 & 2) != 0)
    {
      stage_v_136_2 = (pub_r000947_12_2 + 31) & 127;
    }
    else
    {
      stage_v_136_2 = (pub_r000947_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_136_2 = (pub_r000947_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000947_3_1 & 2) != 0)
    {
      stage_v_137_1 = (pub_r000947_1_1 + 31) & 127;
    }
    else
    {
      stage_v_137_1 = (pub_r000947_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_1 = (pub_r000947_1_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000947_3_2 & 2) != 0)
    {
      stage_v_137_2 = (pub_r000947_1_2 + 31) & 127;
    }
    else
    {
      stage_v_137_2 = (pub_r000947_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_137_2 = (pub_r000947_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((sec_r000947_21_1 & 1) != 0)
  {
    if ((sec_r000947_6_1 & 2) != 0)
    {
      stage_v_138_1 = (pub_r000947_7_1 + 31) & 127;
    }
    else
    {
      stage_v_138_1 = (pub_r000947_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_1 = (pub_r000947_7_1 + 7) & 127;
  }
  if ((sec_r000947_21_2 & 1) != 0)
  {
    if ((sec_r000947_6_2 & 2) != 0)
    {
      stage_v_138_2 = (pub_r000947_7_2 + 31) & 127;
    }
    else
    {
      stage_v_138_2 = (pub_r000947_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_138_2 = (pub_r000947_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000947_15_1 & 2) != 0)
    {
      stage_v_139_1 = (pub_r000947_15_1 + 31) & 127;
    }
    else
    {
      stage_v_139_1 = (pub_r000947_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_1 = (pub_r000947_15_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000947_15_2 & 2) != 0)
    {
      stage_v_139_2 = (pub_r000947_15_2 + 31) & 127;
    }
    else
    {
      stage_v_139_2 = (pub_r000947_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_139_2 = (pub_r000947_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((sec_r000947_3_1 & 1) != 0)
  {
    if ((sec_r000947_1_1 & 2) != 0)
    {
      stage_v_140_1 = (pub_r000947_2_1 + 31) & 127;
    }
    else
    {
      stage_v_140_1 = (pub_r000947_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_1 = (pub_r000947_2_1 + 7) & 127;
  }
  if ((sec_r000947_3_2 & 1) != 0)
  {
    if ((sec_r000947_1_2 & 2) != 0)
    {
      stage_v_140_2 = (pub_r000947_2_2 + 31) & 127;
    }
    else
    {
      stage_v_140_2 = (pub_r000947_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_140_2 = (pub_r000947_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((sec_r000947_11_1 & 1) != 0)
  {
    if ((sec_r000947_1_1 & 2) != 0)
    {
      stage_v_141_1 = (pub_r000947_4_1 + 31) & 127;
    }
    else
    {
      stage_v_141_1 = (pub_r000947_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_1 = (pub_r000947_4_1 + 7) & 127;
  }
  if ((sec_r000947_11_2 & 1) != 0)
  {
    if ((sec_r000947_1_2 & 2) != 0)
    {
      stage_v_141_2 = (pub_r000947_4_2 + 31) & 127;
    }
    else
    {
      stage_v_141_2 = (pub_r000947_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_141_2 = (pub_r000947_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000947_9_1 & 2) != 0)
    {
      stage_v_142_1 = (pub_r000947_4_1 + 31) & 127;
    }
    else
    {
      stage_v_142_1 = (pub_r000947_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_1 = (pub_r000947_4_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000947_9_2 & 2) != 0)
    {
      stage_v_142_2 = (pub_r000947_4_2 + 31) & 127;
    }
    else
    {
      stage_v_142_2 = (pub_r000947_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_142_2 = (pub_r000947_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_103_1 & 1) != 0)
  {
    if ((sec_r000947_1_1 & 2) != 0)
    {
      stage_v_143_1 = (pub_r000947_4_1 + 31) & 127;
    }
    else
    {
      stage_v_143_1 = (pub_r000947_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_1 = (pub_r000947_4_1 + 7) & 127;
  }
  if ((stage_v_103_2 & 1) != 0)
  {
    if ((sec_r000947_1_2 & 2) != 0)
    {
      stage_v_143_2 = (pub_r000947_4_2 + 31) & 127;
    }
    else
    {
      stage_v_143_2 = (pub_r000947_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_143_2 = (pub_r000947_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((sec_r000947_18_1 & 1) != 0)
  {
    if ((sec_r000947_15_1 & 2) != 0)
    {
      stage_v_144_1 = (pub_r000947_10_1 + 31) & 127;
    }
    else
    {
      stage_v_144_1 = (pub_r000947_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_1 = (pub_r000947_10_1 + 7) & 127;
  }
  if ((sec_r000947_18_2 & 1) != 0)
  {
    if ((sec_r000947_15_2 & 2) != 0)
    {
      stage_v_144_2 = (pub_r000947_10_2 + 31) & 127;
    }
    else
    {
      stage_v_144_2 = (pub_r000947_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_144_2 = (pub_r000947_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((sec_r000947_17_1 & 1) != 0)
  {
    if ((sec_r000947_20_1 & 2) != 0)
    {
      stage_v_145_1 = (pub_r000947_1_1 + 31) & 127;
    }
    else
    {
      stage_v_145_1 = (pub_r000947_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_1 = (pub_r000947_1_1 + 7) & 127;
  }
  if ((sec_r000947_17_2 & 1) != 0)
  {
    if ((sec_r000947_20_2 & 2) != 0)
    {
      stage_v_145_2 = (pub_r000947_1_2 + 31) & 127;
    }
    else
    {
      stage_v_145_2 = (pub_r000947_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_145_2 = (pub_r000947_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((sec_r000947_4_1 & 2) != 0)
    {
      stage_v_146_1 = (pub_r000947_15_1 + 31) & 127;
    }
    else
    {
      stage_v_146_1 = (pub_r000947_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_1 = (pub_r000947_15_1 + 7) & 127;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((sec_r000947_4_2 & 2) != 0)
    {
      stage_v_146_2 = (pub_r000947_15_2 + 31) & 127;
    }
    else
    {
      stage_v_146_2 = (pub_r000947_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_146_2 = (pub_r000947_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((stage_v_66_1 & 1) != 0)
  {
    if ((sec_r000947_14_1 & 2) != 0)
    {
      stage_v_147_1 = (pub_r000947_14_1 + 31) & 127;
    }
    else
    {
      stage_v_147_1 = (pub_r000947_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_1 = (pub_r000947_14_1 + 7) & 127;
  }
  if ((stage_v_66_2 & 1) != 0)
  {
    if ((sec_r000947_14_2 & 2) != 0)
    {
      stage_v_147_2 = (pub_r000947_14_2 + 31) & 127;
    }
    else
    {
      stage_v_147_2 = (pub_r000947_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_147_2 = (pub_r000947_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((sec_r000947_18_1 & 2) != 0)
    {
      stage_v_148_1 = (pub_r000947_11_1 + 31) & 127;
    }
    else
    {
      stage_v_148_1 = (pub_r000947_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_1 = (pub_r000947_11_1 + 7) & 127;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((sec_r000947_18_2 & 2) != 0)
    {
      stage_v_148_2 = (pub_r000947_11_2 + 31) & 127;
    }
    else
    {
      stage_v_148_2 = (pub_r000947_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_148_2 = (pub_r000947_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((sec_r000947_11_1 & 1) != 0)
  {
    if ((sec_r000947_15_1 & 2) != 0)
    {
      stage_v_149_1 = (pub_r000947_4_1 + 31) & 127;
    }
    else
    {
      stage_v_149_1 = (pub_r000947_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_1 = (pub_r000947_4_1 + 7) & 127;
  }
  if ((sec_r000947_11_2 & 1) != 0)
  {
    if ((sec_r000947_15_2 & 2) != 0)
    {
      stage_v_149_2 = (pub_r000947_4_2 + 31) & 127;
    }
    else
    {
      stage_v_149_2 = (pub_r000947_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_149_2 = (pub_r000947_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000947_18_1 & 2) != 0)
    {
      stage_v_150_1 = (pub_r000947_15_1 + 31) & 127;
    }
    else
    {
      stage_v_150_1 = (pub_r000947_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_1 = (pub_r000947_15_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000947_18_2 & 2) != 0)
    {
      stage_v_150_2 = (pub_r000947_15_2 + 31) & 127;
    }
    else
    {
      stage_v_150_2 = (pub_r000947_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_150_2 = (pub_r000947_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000947_10_1 & 2) != 0)
    {
      stage_v_151_1 = (pub_r000947_3_1 + 31) & 127;
    }
    else
    {
      stage_v_151_1 = (pub_r000947_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_1 = (pub_r000947_3_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000947_10_2 & 2) != 0)
    {
      stage_v_151_2 = (pub_r000947_3_2 + 31) & 127;
    }
    else
    {
      stage_v_151_2 = (pub_r000947_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_151_2 = (pub_r000947_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_118_1 & 1) != 0)
  {
    if ((sec_r000947_2_1 & 2) != 0)
    {
      stage_v_152_1 = (pub_r000947_4_1 + 31) & 127;
    }
    else
    {
      stage_v_152_1 = (pub_r000947_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_1 = (pub_r000947_4_1 + 7) & 127;
  }
  if ((stage_v_118_2 & 1) != 0)
  {
    if ((sec_r000947_2_2 & 2) != 0)
    {
      stage_v_152_2 = (pub_r000947_4_2 + 31) & 127;
    }
    else
    {
      stage_v_152_2 = (pub_r000947_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_152_2 = (pub_r000947_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000947_8_1 & 2) != 0)
    {
      stage_v_153_1 = (pub_r000947_1_1 + 31) & 127;
    }
    else
    {
      stage_v_153_1 = (pub_r000947_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_1 = (pub_r000947_1_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000947_8_2 & 2) != 0)
    {
      stage_v_153_2 = (pub_r000947_1_2 + 31) & 127;
    }
    else
    {
      stage_v_153_2 = (pub_r000947_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_153_2 = (pub_r000947_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000947_8_1 & 2) != 0)
    {
      stage_v_154_1 = (pub_r000947_0_1 + 31) & 127;
    }
    else
    {
      stage_v_154_1 = (pub_r000947_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_1 = (pub_r000947_0_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000947_8_2 & 2) != 0)
    {
      stage_v_154_2 = (pub_r000947_0_2 + 31) & 127;
    }
    else
    {
      stage_v_154_2 = (pub_r000947_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_154_2 = (pub_r000947_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000947_6_1 & 2) != 0)
    {
      stage_v_155_1 = (pub_r000947_5_1 + 31) & 127;
    }
    else
    {
      stage_v_155_1 = (pub_r000947_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_1 = (pub_r000947_5_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000947_6_2 & 2) != 0)
    {
      stage_v_155_2 = (pub_r000947_5_2 + 31) & 127;
    }
    else
    {
      stage_v_155_2 = (pub_r000947_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_155_2 = (pub_r000947_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000947_0_1 != sec_r000947_0_2);
  __CPROVER_assume(sec_r000947_7_1 != sec_r000947_7_2);
  __CPROVER_assume(sec_r000947_6_1 != sec_r000947_6_2);
  __CPROVER_assume(pub_r000947_6_1 == pub_r000947_6_2);
  __CPROVER_assume(pub_r000947_2_1 == pub_r000947_2_2);
  __CPROVER_assume(pub_r000947_1_1 == pub_r000947_1_2);
  __CPROVER_assume(sec_r000947_18_1 != sec_r000947_18_2);
  __CPROVER_assume(sec_r000947_9_1 != sec_r000947_9_2);
  __CPROVER_assume(sec_r000947_2_1 != sec_r000947_2_2);
  __CPROVER_assume(sec_r000947_21_1 != sec_r000947_21_2);
  __CPROVER_assume(sec_r000947_4_1 != sec_r000947_4_2);
  __CPROVER_assume(sec_r000947_11_1 != sec_r000947_11_2);
  __CPROVER_assume(sec_r000947_13_1 != sec_r000947_13_2);
  __CPROVER_assume(pub_r000947_12_1 == pub_r000947_12_2);
  __CPROVER_assume(sec_r000947_8_1 != sec_r000947_8_2);
  __CPROVER_assume(sec_r000947_20_1 != sec_r000947_20_2);
  __CPROVER_assume(pub_r000947_10_1 == pub_r000947_10_2);
  __CPROVER_assume(sec_r000947_22_1 != sec_r000947_22_2);
  __CPROVER_assume(pub_r000947_11_1 == pub_r000947_11_2);
  __CPROVER_assume(pub_r000947_3_1 == pub_r000947_3_2);
  __CPROVER_assume(pub_r000947_13_1 == pub_r000947_13_2);
  __CPROVER_assume(pub_r000947_7_1 == pub_r000947_7_2);
  __CPROVER_assume(sec_r000947_1_1 != sec_r000947_1_2);
  __CPROVER_assume(pub_r000947_15_1 == pub_r000947_15_2);
  __CPROVER_assume(pub_r000947_0_1 == pub_r000947_0_2);
  __CPROVER_assume(pub_r000947_16_1 == pub_r000947_16_2);
  __CPROVER_assume(pub_r000947_5_1 == pub_r000947_5_2);
  __CPROVER_assume(sec_r000947_19_1 != sec_r000947_19_2);
  __CPROVER_assume(sec_r000947_14_1 != sec_r000947_14_2);
  __CPROVER_assume(pub_r000947_4_1 == pub_r000947_4_2);
  __CPROVER_assume(sec_r000947_5_1 != sec_r000947_5_2);
  __CPROVER_assume(pub_r000947_9_1 == pub_r000947_9_2);
  __CPROVER_assume(pub_r000947_14_1 == pub_r000947_14_2);
  __CPROVER_assume(sec_r000947_12_1 != sec_r000947_12_2);
  __CPROVER_assume(sec_r000947_15_1 != sec_r000947_15_2);
  __CPROVER_assume(sec_r000947_3_1 != sec_r000947_3_2);
  __CPROVER_assume(pub_r000947_8_1 == pub_r000947_8_2);
  __CPROVER_assume(sec_r000947_17_1 != sec_r000947_17_2);
  __CPROVER_assume(sec_r000947_16_1 != sec_r000947_16_2);
  __CPROVER_assume(sec_r000947_10_1 != sec_r000947_10_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  assert(st_var_2_1.stop_bits == st_var_2_2.stop_bits);
  assert(st_var_2_1.parity == st_var_2_2.parity);
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
}


