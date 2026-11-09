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
struct Vector3D_R001796_9613_0
{
  unsigned char heading;
  unsigned char norm_sq;
  int coord_x;
  int pitch;
  int buffer[3];
};
struct AudioFrame_R001796_9613_1
{
  short rms;
  int sample_rate;
  int channels;
  short envelope;
  int buffer[3];
};
struct DeviceConfig_R001796_9613_2
{
  unsigned char baud_rate;
  int id;
  int parity;
  int stop_bits;
  int port;
  short timeout;
  int buffer[3];
};
struct SensorNode_R001796_9613_3
{
  int status;
  short reading;
  short calib;
  int offset;
  int gain;
  int buffer[3];
};
union ColorPixel_R001796_9613_0
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
void fn_R001796_9613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001796_9613_2 st_1 = {0};
  struct DeviceConfig_R001796_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int vector_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_88_1) & 63;
  aux_2 = (aux_2 + vector_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_14_1 = local_arr_1[aux_1 % 3];
  int index_reg_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_14_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_79_1)
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

  switch (scale_79_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_88_1 == vector_88_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_14_1 == index_reg_14_2);
  assert(scale_79_1 == scale_79_2);
}

int fn_R001796_9613_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001796_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int vector_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_88) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_14 = local_arr[aux % 3];
  acc = (acc + (index_reg_14 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_79 = (aux + st.buffer[1]) & 3;
  switch (scale_79)
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

void fn_R001796_9613_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001796_9613_3 st_1 = {0};
  struct SensorNode_R001796_9613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int damping_12_1 = 0;
  int damping_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_12_1 = ((damping_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_12_2 = ((damping_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_12_1) & 127;
    acc_2 = (acc_2 + damping_12_2) & 127;
  }

  int residue_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_79_1) & 63;
  aux_2 = (aux_2 + residue_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_12_1 == damping_12_2);
  assert(residue_79_1 == residue_79_2);
}

int fn_R001796_9613_1(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001796_9613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int damping_12 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_12 = ((damping_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_12) & 127;
  }

  int residue_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_79) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001796_9613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001796_9613_2 st_1 = {0};
  struct DeviceConfig_R001796_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int pivot_54_1 = 0;
  int pivot_54_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_54_1 = ((pivot_54_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_54_2 = ((pivot_54_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_54_1) & 127;
    acc_2 = (acc_2 + pivot_54_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_54_1 == pivot_54_2);
}

int fn_R001796_9613_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001796_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int pivot_54 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_54 = ((pivot_54 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_54) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001796_9613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001796_9613_0 st_1 = {0};
  struct Vector3D_R001796_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int margin_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_84_1 > 10)
  {
    acc_1 = ((acc_1 + (margin_84_1 * 2)) + 5) & 127;
    aux_1 ^= margin_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_84_2 > 10)
  {
    acc_2 = ((acc_2 + (margin_84_2 * 2)) + 5) & 127;
    aux_2 ^= margin_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_82_1)
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

  switch (damping_82_2)
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
  int scale_21_1 = local_arr_1[aux_1 % 3];
  int scale_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_21_2 * 2)) & 127;
  int index_reg_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_48_1) & 63;
  aux_2 = (aux_2 + index_reg_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_84_1 == margin_84_2);
  assert(damping_82_1 == damping_82_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_21_1 == scale_21_2);
  assert(index_reg_48_1 == index_reg_48_2);
}

int fn_R001796_9613_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001796_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int margin_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_84 > 10)
  {
    acc = ((acc + (margin_84 * 2)) + 5) & 127;
    aux ^= margin_84 & 15;
  }
  else
  {
    acc = ((acc - margin_84) + 11) & 127;
    aux += 3;
  }
  int damping_82 = (aux + st.buffer[1]) & 3;
  switch (damping_82)
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
  int scale_21 = local_arr[aux % 3];
  acc = (acc + (scale_21 * 2)) & 127;
  int index_reg_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_48) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001796_9613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001796_9613_0 st_1 = {0};
  struct Vector3D_R001796_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int checksum_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_61_1 > 25)
  {
    acc_1 = ((acc_1 + (checksum_61_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_61_2 > 25)
  {
    acc_2 = ((acc_2 + (checksum_61_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_79_1 = local_arr_1[aux_1 % 3];
  int metric_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_79_2 * 2)) & 127;
  int threshold_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_91_1)
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

  switch (threshold_91_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_61_1 == checksum_61_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_79_1 == metric_79_2);
  assert(threshold_91_1 == threshold_91_2);
}

int fn_R001796_9613_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001796_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int checksum_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_61 > 25)
  {
    acc = ((acc + (checksum_61 * 2)) + 5) & 127;
    aux ^= checksum_61 & 15;
  }
  else
  {
    acc = ((acc - checksum_61) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_79 = local_arr[aux % 3];
  acc = (acc + (metric_79 * 2)) & 127;
  int threshold_91 = (aux + st.buffer[1]) & 3;
  switch (threshold_91)
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

void fn_R001796_9613_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001796_9613_3 st_1 = {0};
  struct SensorNode_R001796_9613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int phase_20_1 = 0;
  int phase_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_20_1 = ((phase_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_20_2 = ((phase_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_20_1) & 127;
    acc_2 = (acc_2 + phase_20_2) & 127;
  }

  int segment_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_46_1) & 63;
  aux_2 = (aux_2 + segment_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_97_1 > 37)
  {
    acc_1 = ((acc_1 + (anchor_97_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_97_2 > 37)
  {
    acc_2 = ((acc_2 + (anchor_97_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_51_1)
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

  switch (cursor_51_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_20_1 == phase_20_2);
  assert(segment_46_1 == segment_46_2);
  assert(anchor_97_1 == anchor_97_2);
  assert(cursor_51_1 == cursor_51_2);
}

int fn_R001796_9613_5(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001796_9613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int phase_20 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_20 = ((phase_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_20) & 127;
  }

  int segment_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_46) & 63;
  acc ^= aux;
  int anchor_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_97 > 37)
  {
    acc = ((acc + (anchor_97 * 2)) + 5) & 127;
    aux ^= anchor_97 & 15;
  }
  else
  {
    acc = ((acc - anchor_97) + 11) & 127;
    aux += 3;
  }
  int cursor_51 = (aux + st.buffer[1]) & 3;
  switch (cursor_51)
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

void fn_R001796_9613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001796_9613_3 st_1 = {0};
  struct SensorNode_R001796_9613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int parity_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_52_1) & 63;
  aux_2 = (aux_2 + parity_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_95_1)
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

  switch (metric_95_2)
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
  int bound_66_1 = local_arr_1[aux_1 % 3];
  int bound_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_66_2 * 2)) & 127;
  int accumulator_90_1 = 0;
  int accumulator_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_90_1 = ((accumulator_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_90_2 = ((accumulator_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_90_1) & 127;
    acc_2 = (acc_2 + accumulator_90_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_52_1 == parity_52_2);
  assert(metric_95_1 == metric_95_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_66_1 == bound_66_2);
  assert(accumulator_90_1 == accumulator_90_2);
}

int fn_R001796_9613_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001796_9613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int parity_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_52) & 63;
  acc ^= aux;
  int metric_95 = (aux + st.buffer[1]) & 3;
  switch (metric_95)
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
  int bound_66 = local_arr[aux % 3];
  acc = (acc + (bound_66 * 2)) & 127;
  int accumulator_90 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_90 = ((accumulator_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_90) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001796_9613_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001796_9613_0 st_1 = {0};
  struct Vector3D_R001796_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_65_1 = local_arr_1[aux_1 % 3];
  int parity_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_65_2 * 2)) & 127;
  int sample_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_72_1)
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

  switch (sample_72_2)
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

  int residue_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_50_1 > 23)
  {
    acc_1 = ((acc_1 + (residue_50_1 * 2)) + 5) & 127;
    aux_1 ^= residue_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_50_2 > 23)
  {
    acc_2 = ((acc_2 + (residue_50_2 * 2)) + 5) & 127;
    aux_2 ^= residue_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_50_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_65_1 == parity_65_2);
  assert(sample_72_1 == sample_72_2);
  assert(residue_50_1 == residue_50_2);
}

int fn_R001796_9613_7(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001796_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int parity_65 = local_arr[aux % 3];
  acc = (acc + (parity_65 * 2)) & 127;
  int sample_72 = (aux + st.buffer[1]) & 3;
  switch (sample_72)
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

  int residue_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_50 > 23)
  {
    acc = ((acc + (residue_50 * 2)) + 5) & 127;
    aux ^= residue_50 & 15;
  }
  else
  {
    acc = ((acc - residue_50) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001796_9613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001796_9613_2 st_1 = {0};
  struct DeviceConfig_R001796_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_50_1) & 63;
  aux_2 = (aux_2 + pivot_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_50_1 == pivot_50_2);
}

int fn_R001796_9613_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001796_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_50) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001796_9613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001796_9613_1 st_1 = {0};
  struct AudioFrame_R001796_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int vector_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_33_1 > 33)
  {
    acc_1 = ((acc_1 + (vector_33_1 * 2)) + 5) & 127;
    aux_1 ^= vector_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_33_2 > 33)
  {
    acc_2 = ((acc_2 + (vector_33_2 * 2)) + 5) & 127;
    aux_2 ^= vector_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_33_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_48_1)
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

  switch (pivot_48_2)
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
  int offset_57_1 = local_arr_1[aux_1 % 3];
  int offset_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_57_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_33_1 == vector_33_2);
  assert(pivot_48_1 == pivot_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_57_1 == offset_57_2);
}

int fn_R001796_9613_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001796_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int vector_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_33 > 33)
  {
    acc = ((acc + (vector_33 * 2)) + 5) & 127;
    aux ^= vector_33 & 15;
  }
  else
  {
    acc = ((acc - vector_33) + 11) & 127;
    aux += 3;
  }
  int pivot_48 = (aux + st.buffer[1]) & 3;
  switch (pivot_48)
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
  int offset_57 = local_arr[aux % 3];
  acc = (acc + (offset_57 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001796_9613_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001796_9613_0 st_1 = {0};
  struct Vector3D_R001796_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int anchor_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_11_1)
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

  switch (anchor_11_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_41_1 = 0;
  int metric_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_41_1 = ((metric_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_41_2 = ((metric_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_41_1) & 127;
    acc_2 = (acc_2 + metric_41_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_11_1 == anchor_11_2);
  assert(metric_41_1 == metric_41_2);
}

int fn_R001796_9613_10(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001796_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int anchor_11 = (aux + st.buffer[1]) & 3;
  switch (anchor_11)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_41 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_41 = ((metric_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_41) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001796_9613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001796_9613_3 st_1 = {0};
  struct SensorNode_R001796_9613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int factor_58_1 = 0;
  int factor_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_58_1 = ((factor_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_58_2 = ((factor_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_58_1) & 127;
    acc_2 = (acc_2 + factor_58_2) & 127;
  }

  int delta_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_24_1)
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

  switch (delta_24_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_58_1 == factor_58_2);
  assert(delta_24_1 == delta_24_2);
}

int fn_R001796_9613_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001796_9613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int factor_58 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_58 = ((factor_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_58) & 127;
  }

  int delta_24 = (aux + st.buffer[1]) & 3;
  switch (delta_24)
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

void fn_R001796_9613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001796_9613_0 st_1 = {0};
  struct Vector3D_R001796_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int sample_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_18_1) & 63;
  aux_2 = (aux_2 + sample_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_79_1)
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

  switch (threshold_79_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_18_1 == sample_18_2);
  assert(threshold_79_1 == threshold_79_2);
}

int fn_R001796_9613_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001796_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int sample_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_18) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_79 = (aux + st.buffer[1]) & 3;
  switch (threshold_79)
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

void fn_R001796_9613_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001796_9613_1 st_1 = {0};
  struct AudioFrame_R001796_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_65_1 = 0;
  int coefficient_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_65_1 = ((coefficient_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_65_2 = ((coefficient_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_65_1) & 127;
    acc_2 = (acc_2 + coefficient_65_2) & 127;
  }

  int phase_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_74_1 > 11)
  {
    acc_1 = ((acc_1 + (phase_74_1 * 2)) + 5) & 127;
    aux_1 ^= phase_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_74_2 > 11)
  {
    acc_2 = ((acc_2 + (phase_74_2 * 2)) + 5) & 127;
    aux_2 ^= phase_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_74_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_65_1 == coefficient_65_2);
  assert(phase_74_1 == phase_74_2);
}

int fn_R001796_9613_13(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001796_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_65 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_65 = ((coefficient_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_65) & 127;
  }

  int phase_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_74 > 11)
  {
    acc = ((acc + (phase_74 * 2)) + 5) & 127;
    aux ^= phase_74 & 15;
  }
  else
  {
    acc = ((acc - phase_74) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001796_9613_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001796_9613_1 st_1 = {0};
  struct AudioFrame_R001796_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int anchor_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_38_1)
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

  switch (anchor_38_2)
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

  int phase_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_73_1 > 29)
  {
    acc_1 = ((acc_1 + (phase_73_1 * 2)) + 5) & 127;
    aux_1 ^= phase_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_73_2 > 29)
  {
    acc_2 = ((acc_2 + (phase_73_2 * 2)) + 5) & 127;
    aux_2 ^= phase_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_73_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_38_1 == anchor_38_2);
  assert(phase_73_1 == phase_73_2);
}

int fn_R001796_9613_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001796_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int anchor_38 = (aux + st.buffer[1]) & 3;
  switch (anchor_38)
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

  int phase_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_73 > 29)
  {
    acc = ((acc + (phase_73 * 2)) + 5) & 127;
    aux ^= phase_73 & 15;
  }
  else
  {
    acc = ((acc - phase_73) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001796_9613_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001796_9613_0 st_1 = {0};
  struct Vector3D_R001796_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_86_1)
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

  switch (scale_86_2)
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

  int margin_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_90_1) & 63;
  aux_2 = (aux_2 + margin_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_86_1 == scale_86_2);
  assert(margin_90_1 == margin_90_2);
}

int fn_R001796_9613_15(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001796_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_86 = (aux + st.buffer[1]) & 3;
  switch (scale_86)
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

  int margin_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_90) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001796_9613_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001796_9613_2 st_1 = {0};
  struct DeviceConfig_R001796_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int tally_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_48_1) & 63;
  aux_2 = (aux_2 + tally_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_74_1 > 40)
  {
    acc_1 = ((acc_1 + (coefficient_74_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_74_2 > 40)
  {
    acc_2 = ((acc_2 + (coefficient_74_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_74_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_68_1)
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

  switch (quotient_68_2)
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

  int delta_97_1 = 0;
  int delta_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_97_1 = ((delta_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_97_2 = ((delta_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_97_1) & 127;
    acc_2 = (acc_2 + delta_97_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_48_1 == tally_48_2);
  assert(coefficient_74_1 == coefficient_74_2);
  assert(quotient_68_1 == quotient_68_2);
  assert(delta_97_1 == delta_97_2);
}

int fn_R001796_9613_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001796_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int tally_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_48) & 63;
  acc ^= aux;
  int coefficient_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_74 > 40)
  {
    acc = ((acc + (coefficient_74 * 2)) + 5) & 127;
    aux ^= coefficient_74 & 15;
  }
  else
  {
    acc = ((acc - coefficient_74) + 11) & 127;
    aux += 3;
  }
  int quotient_68 = (aux + st.buffer[1]) & 3;
  switch (quotient_68)
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

  int delta_97 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_97 = ((delta_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_97) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001796_9613_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001796_9613_1 st_1 = {0};
  struct AudioFrame_R001796_9613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int stride_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_66_1 > 35)
  {
    acc_1 = ((acc_1 + (stride_66_1 * 2)) + 5) & 127;
    aux_1 ^= stride_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_66_2 > 35)
  {
    acc_2 = ((acc_2 + (stride_66_2 * 2)) + 5) & 127;
    aux_2 ^= stride_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_66_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_25_1)
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

  switch (weight_25_2)
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
  int margin_38_1 = local_arr_1[aux_1 % 3];
  int margin_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_38_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_66_1 == stride_66_2);
  assert(weight_25_1 == weight_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_38_1 == margin_38_2);
}

int fn_R001796_9613_17(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001796_9613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int stride_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_66 > 35)
  {
    acc = ((acc + (stride_66 * 2)) + 5) & 127;
    aux ^= stride_66 & 15;
  }
  else
  {
    acc = ((acc - stride_66) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_25 = (aux + st.buffer[1]) & 3;
  switch (weight_25)
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
  int margin_38 = local_arr[aux % 3];
  acc = (acc + (margin_38 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001796_9613_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001796_9613_2 st_1 = {0};
  struct DeviceConfig_R001796_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int segment_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_17_1)
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

  switch (segment_17_2)
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
  int pivot_17_1 = local_arr_1[aux_1 % 3];
  int pivot_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_17_2 * 2)) & 127;
  int tally_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_26_1 > 42)
  {
    acc_1 = ((acc_1 + (tally_26_1 * 2)) + 5) & 127;
    aux_1 ^= tally_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_26_2 > 42)
  {
    acc_2 = ((acc_2 + (tally_26_2 * 2)) + 5) & 127;
    aux_2 ^= tally_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_49_1 = 0;
  int quotient_49_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_49_1 = ((quotient_49_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_49_2 = ((quotient_49_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_49_1) & 127;
    acc_2 = (acc_2 + quotient_49_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_17_1 == segment_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_17_1 == pivot_17_2);
  assert(tally_26_1 == tally_26_2);
  assert(quotient_49_1 == quotient_49_2);
}

int fn_R001796_9613_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001796_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int segment_17 = (aux + st.buffer[1]) & 3;
  switch (segment_17)
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
  int pivot_17 = local_arr[aux % 3];
  acc = (acc + (pivot_17 * 2)) & 127;
  int tally_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_26 > 42)
  {
    acc = ((acc + (tally_26 * 2)) + 5) & 127;
    aux ^= tally_26 & 15;
  }
  else
  {
    acc = ((acc - tally_26) + 11) & 127;
    aux += 3;
  }
  int quotient_49 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_49 = ((quotient_49 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_49) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001796_9613_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001796_9613_0 st_1 = {0};
  struct Vector3D_R001796_9613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int bound_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_90_1)
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

  switch (bound_90_2)
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

  int residue_73_1 = 0;
  int residue_73_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_73_1 = ((residue_73_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_73_2 = ((residue_73_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_73_1) & 127;
    acc_2 = (acc_2 + residue_73_2) & 127;
  }

  int accumulator_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_30_1 > 14)
  {
    acc_1 = ((acc_1 + (accumulator_30_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_30_2 > 14)
  {
    acc_2 = ((acc_2 + (accumulator_30_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_30_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_22_1 = local_arr_1[aux_1 % 3];
  int mask_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_22_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_90_1 == bound_90_2);
  assert(residue_73_1 == residue_73_2);
  assert(accumulator_30_1 == accumulator_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_22_1 == mask_22_2);
}

int fn_R001796_9613_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001796_9613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int bound_90 = (aux + st.buffer[1]) & 3;
  switch (bound_90)
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

  int residue_73 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_73 = ((residue_73 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_73) & 127;
  }

  int accumulator_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_30 > 14)
  {
    acc = ((acc + (accumulator_30 * 2)) + 5) & 127;
    aux ^= accumulator_30 & 15;
  }
  else
  {
    acc = ((acc - accumulator_30) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_22 = local_arr[aux % 3];
  acc = (acc + (mask_22 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001796_9613_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001796_9613_3 st_1 = {0};
  struct SensorNode_R001796_9613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int cursor_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_73_1)
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

  switch (cursor_73_2)
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
  int anchor_80_1 = local_arr_1[aux_1 % 3];
  int anchor_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_80_2 * 2)) & 127;
  int scale_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_98_1 > 11)
  {
    acc_1 = ((acc_1 + (scale_98_1 * 2)) + 5) & 127;
    aux_1 ^= scale_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_98_2 > 11)
  {
    acc_2 = ((acc_2 + (scale_98_2 * 2)) + 5) & 127;
    aux_2 ^= scale_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_98_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_73_1 == cursor_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_80_1 == anchor_80_2);
  assert(scale_98_1 == scale_98_2);
}

int fn_R001796_9613_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001796_9613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int cursor_73 = (aux + st.buffer[1]) & 3;
  switch (cursor_73)
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
  int anchor_80 = local_arr[aux % 3];
  acc = (acc + (anchor_80 * 2)) & 127;
  int scale_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_98 > 11)
  {
    acc = ((acc + (scale_98 * 2)) + 5) & 127;
    aux ^= scale_98 & 15;
  }
  else
  {
    acc = ((acc - scale_98) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001796_9613_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001796_9613_2 st_1 = {0};
  struct DeviceConfig_R001796_9613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_43_1) & 63;
  aux_2 = (aux_2 + stride_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_43_1 == stride_43_2);
}

int fn_R001796_9613_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001796_9613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_43) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001796_0_1;
  int sec_r001796_0_2;
  int sec_r001796_1_1;
  int sec_r001796_1_2;
  int sec_r001796_2_1;
  int sec_r001796_2_2;
  int sec_r001796_3_1;
  int sec_r001796_3_2;
  int sec_r001796_4_1;
  int sec_r001796_4_2;
  int sec_r001796_5_1;
  int sec_r001796_5_2;
  int sec_r001796_6_1;
  int sec_r001796_6_2;
  int sec_r001796_7_1;
  int sec_r001796_7_2;
  int sec_r001796_8_1;
  int sec_r001796_8_2;
  int sec_r001796_9_1;
  int sec_r001796_9_2;
  int sec_r001796_10_1;
  int sec_r001796_10_2;
  int sec_r001796_11_1;
  int sec_r001796_11_2;
  int sec_r001796_12_1;
  int sec_r001796_12_2;
  int sec_r001796_13_1;
  int sec_r001796_13_2;
  int sec_r001796_14_1;
  int sec_r001796_14_2;
  int sec_r001796_15_1;
  int sec_r001796_15_2;
  int sec_r001796_16_1;
  int sec_r001796_16_2;
  int sec_r001796_17_1;
  int sec_r001796_17_2;
  int sec_r001796_18_1;
  int sec_r001796_18_2;
  int pub_r001796_0_1;
  int pub_r001796_0_2;
  int pub_r001796_1_1;
  int pub_r001796_1_2;
  int pub_r001796_2_1;
  int pub_r001796_2_2;
  int pub_r001796_3_1;
  int pub_r001796_3_2;
  int pub_r001796_4_1;
  int pub_r001796_4_2;
  int pub_r001796_5_1;
  int pub_r001796_5_2;
  int pub_r001796_6_1;
  int pub_r001796_6_2;
  int pub_r001796_7_1;
  int pub_r001796_7_2;
  int pub_r001796_8_1;
  int pub_r001796_8_2;
  int pub_r001796_9_1;
  int pub_r001796_9_2;
  int pub_r001796_10_1;
  int pub_r001796_10_2;
  int pub_r001796_11_1;
  int pub_r001796_11_2;
  int pub_r001796_12_1;
  int pub_r001796_12_2;
  int pub_r001796_13_1;
  int pub_r001796_13_2;
  int pub_r001796_14_1;
  int pub_r001796_14_2;
  int pub_r001796_15_1;
  int pub_r001796_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001796_0_1 >= (-100)) && (pub_r001796_0_1 <= 100));
  __CPROVER_assume((pub_r001796_0_2 >= (-100)) && (pub_r001796_0_2 <= 100));
  __CPROVER_assume((pub_r001796_1_1 >= (-100)) && (pub_r001796_1_1 <= 100));
  __CPROVER_assume((pub_r001796_1_2 >= (-100)) && (pub_r001796_1_2 <= 100));
  __CPROVER_assume((pub_r001796_2_1 >= (-100)) && (pub_r001796_2_1 <= 100));
  __CPROVER_assume((pub_r001796_2_2 >= (-100)) && (pub_r001796_2_2 <= 100));
  __CPROVER_assume((pub_r001796_3_1 >= (-100)) && (pub_r001796_3_1 <= 100));
  __CPROVER_assume((pub_r001796_3_2 >= (-100)) && (pub_r001796_3_2 <= 100));
  __CPROVER_assume((pub_r001796_4_1 >= (-100)) && (pub_r001796_4_1 <= 100));
  __CPROVER_assume((pub_r001796_4_2 >= (-100)) && (pub_r001796_4_2 <= 100));
  __CPROVER_assume((pub_r001796_5_1 >= (-100)) && (pub_r001796_5_1 <= 100));
  __CPROVER_assume((pub_r001796_5_2 >= (-100)) && (pub_r001796_5_2 <= 100));
  __CPROVER_assume((pub_r001796_6_1 >= (-100)) && (pub_r001796_6_1 <= 100));
  __CPROVER_assume((pub_r001796_6_2 >= (-100)) && (pub_r001796_6_2 <= 100));
  __CPROVER_assume((pub_r001796_7_1 >= (-100)) && (pub_r001796_7_1 <= 100));
  __CPROVER_assume((pub_r001796_7_2 >= (-100)) && (pub_r001796_7_2 <= 100));
  __CPROVER_assume((pub_r001796_8_1 >= (-100)) && (pub_r001796_8_1 <= 100));
  __CPROVER_assume((pub_r001796_8_2 >= (-100)) && (pub_r001796_8_2 <= 100));
  __CPROVER_assume((pub_r001796_9_1 >= (-100)) && (pub_r001796_9_1 <= 100));
  __CPROVER_assume((pub_r001796_9_2 >= (-100)) && (pub_r001796_9_2 <= 100));
  __CPROVER_assume((pub_r001796_10_1 >= (-100)) && (pub_r001796_10_1 <= 100));
  __CPROVER_assume((pub_r001796_10_2 >= (-100)) && (pub_r001796_10_2 <= 100));
  __CPROVER_assume((pub_r001796_11_1 >= (-100)) && (pub_r001796_11_1 <= 100));
  __CPROVER_assume((pub_r001796_11_2 >= (-100)) && (pub_r001796_11_2 <= 100));
  __CPROVER_assume((pub_r001796_12_1 >= (-100)) && (pub_r001796_12_1 <= 100));
  __CPROVER_assume((pub_r001796_12_2 >= (-100)) && (pub_r001796_12_2 <= 100));
  __CPROVER_assume((pub_r001796_13_1 >= (-100)) && (pub_r001796_13_1 <= 100));
  __CPROVER_assume((pub_r001796_13_2 >= (-100)) && (pub_r001796_13_2 <= 100));
  __CPROVER_assume((pub_r001796_14_1 >= (-100)) && (pub_r001796_14_1 <= 100));
  __CPROVER_assume((pub_r001796_14_2 >= (-100)) && (pub_r001796_14_2 <= 100));
  __CPROVER_assume((pub_r001796_15_1 >= (-100)) && (pub_r001796_15_1 <= 100));
  __CPROVER_assume((pub_r001796_15_2 >= (-100)) && (pub_r001796_15_2 <= 100));
  __CPROVER_assume((sec_r001796_0_1 >= 0) && (sec_r001796_0_1 <= 255));
  __CPROVER_assume((sec_r001796_0_2 >= 0) && (sec_r001796_0_2 <= 255));
  __CPROVER_assume((sec_r001796_1_1 >= 0) && (sec_r001796_1_1 <= 255));
  __CPROVER_assume((sec_r001796_1_2 >= 0) && (sec_r001796_1_2 <= 255));
  __CPROVER_assume((sec_r001796_2_1 >= 0) && (sec_r001796_2_1 <= 255));
  __CPROVER_assume((sec_r001796_2_2 >= 0) && (sec_r001796_2_2 <= 255));
  __CPROVER_assume((sec_r001796_3_1 >= 0) && (sec_r001796_3_1 <= 255));
  __CPROVER_assume((sec_r001796_3_2 >= 0) && (sec_r001796_3_2 <= 255));
  __CPROVER_assume((sec_r001796_4_1 >= 0) && (sec_r001796_4_1 <= 255));
  __CPROVER_assume((sec_r001796_4_2 >= 0) && (sec_r001796_4_2 <= 255));
  __CPROVER_assume((sec_r001796_5_1 >= 0) && (sec_r001796_5_1 <= 255));
  __CPROVER_assume((sec_r001796_5_2 >= 0) && (sec_r001796_5_2 <= 255));
  __CPROVER_assume((sec_r001796_6_1 >= 0) && (sec_r001796_6_1 <= 255));
  __CPROVER_assume((sec_r001796_6_2 >= 0) && (sec_r001796_6_2 <= 255));
  __CPROVER_assume((sec_r001796_7_1 >= 0) && (sec_r001796_7_1 <= 255));
  __CPROVER_assume((sec_r001796_7_2 >= 0) && (sec_r001796_7_2 <= 255));
  __CPROVER_assume((sec_r001796_8_1 >= 0) && (sec_r001796_8_1 <= 255));
  __CPROVER_assume((sec_r001796_8_2 >= 0) && (sec_r001796_8_2 <= 255));
  __CPROVER_assume((sec_r001796_9_1 >= 0) && (sec_r001796_9_1 <= 255));
  __CPROVER_assume((sec_r001796_9_2 >= 0) && (sec_r001796_9_2 <= 255));
  __CPROVER_assume((sec_r001796_10_1 >= 0) && (sec_r001796_10_1 <= 255));
  __CPROVER_assume((sec_r001796_10_2 >= 0) && (sec_r001796_10_2 <= 255));
  __CPROVER_assume((sec_r001796_11_1 >= 0) && (sec_r001796_11_1 <= 255));
  __CPROVER_assume((sec_r001796_11_2 >= 0) && (sec_r001796_11_2 <= 255));
  __CPROVER_assume((sec_r001796_12_1 >= 0) && (sec_r001796_12_1 <= 255));
  __CPROVER_assume((sec_r001796_12_2 >= 0) && (sec_r001796_12_2 <= 255));
  __CPROVER_assume((sec_r001796_13_1 >= 0) && (sec_r001796_13_1 <= 255));
  __CPROVER_assume((sec_r001796_13_2 >= 0) && (sec_r001796_13_2 <= 255));
  __CPROVER_assume((sec_r001796_14_1 >= 0) && (sec_r001796_14_1 <= 255));
  __CPROVER_assume((sec_r001796_14_2 >= 0) && (sec_r001796_14_2 <= 255));
  __CPROVER_assume((sec_r001796_15_1 >= 0) && (sec_r001796_15_1 <= 255));
  __CPROVER_assume((sec_r001796_15_2 >= 0) && (sec_r001796_15_2 <= 255));
  __CPROVER_assume((sec_r001796_16_1 >= 0) && (sec_r001796_16_1 <= 255));
  __CPROVER_assume((sec_r001796_16_2 >= 0) && (sec_r001796_16_2 <= 255));
  __CPROVER_assume((sec_r001796_17_1 >= 0) && (sec_r001796_17_1 <= 255));
  __CPROVER_assume((sec_r001796_17_2 >= 0) && (sec_r001796_17_2 <= 255));
  __CPROVER_assume((sec_r001796_18_1 >= 0) && (sec_r001796_18_1 <= 255));
  __CPROVER_assume((sec_r001796_18_2 >= 0) && (sec_r001796_18_2 <= 255));
  struct Vector3D_R001796_9613_0 st_var_0_1 = {0};
  struct Vector3D_R001796_9613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001796_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001796_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001796_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001796_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001796_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001796_0_2 + 7) & 15;
  struct AudioFrame_R001796_9613_1 st_var_1_1 = {0};
  struct AudioFrame_R001796_9613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001796_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001796_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001796_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001796_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001796_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001796_0_2 + 9) & 15;
  struct DeviceConfig_R001796_9613_2 st_var_2_1 = {0};
  struct DeviceConfig_R001796_9613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001796_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001796_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001796_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001796_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001796_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001796_0_2 + 11) & 15;
  struct SensorNode_R001796_9613_3 st_var_3_1 = {0};
  struct SensorNode_R001796_9613_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001796_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001796_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001796_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001796_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001796_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001796_0_2 + 13) & 15;
  union ColorPixel_R001796_9613_0 u_var_1;
  union ColorPixel_R001796_9613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001796_9613_0(sec_r001796_0_1, sec_r001796_1_1, pub_r001796_2_1, pub_r001796_3_1, pub_r001796_4_1);
  int helper_flow_0_2 = fn_R001796_9613_0(sec_r001796_0_2, sec_r001796_1_2, pub_r001796_2_2, pub_r001796_3_2, pub_r001796_4_2);
  fn_R001796_9613_0_2(sec_r001796_0_1, sec_r001796_1_1, pub_r001796_2_1, pub_r001796_3_1, pub_r001796_4_1, sec_r001796_0_2, sec_r001796_1_2, pub_r001796_2_2, pub_r001796_3_2, pub_r001796_4_2);
  int helper_flow_1_1 = fn_R001796_9613_1(sec_r001796_1_1, pub_r001796_2_1, pub_r001796_3_1);
  int helper_flow_1_2 = fn_R001796_9613_1(sec_r001796_1_2, pub_r001796_2_2, pub_r001796_3_2);
  fn_R001796_9613_1_2(sec_r001796_1_1, pub_r001796_2_1, pub_r001796_3_1, sec_r001796_1_2, pub_r001796_2_2, pub_r001796_3_2);
  int helper_flow_2_1 = fn_R001796_9613_2(sec_r001796_2_1, sec_r001796_3_1, pub_r001796_4_1, pub_r001796_5_1);
  int helper_flow_2_2 = fn_R001796_9613_2(sec_r001796_2_2, sec_r001796_3_2, pub_r001796_4_2, pub_r001796_5_2);
  fn_R001796_9613_2_2(sec_r001796_2_1, sec_r001796_3_1, pub_r001796_4_1, pub_r001796_5_1, sec_r001796_2_2, sec_r001796_3_2, pub_r001796_4_2, pub_r001796_5_2);
  int helper_flow_3_1 = fn_R001796_9613_3(sec_r001796_3_1, pub_r001796_4_1, pub_r001796_5_1, pub_r001796_6_1, pub_r001796_7_1);
  int helper_flow_3_2 = fn_R001796_9613_3(sec_r001796_3_2, pub_r001796_4_2, pub_r001796_5_2, pub_r001796_6_2, pub_r001796_7_2);
  fn_R001796_9613_3_2(sec_r001796_3_1, pub_r001796_4_1, pub_r001796_5_1, pub_r001796_6_1, pub_r001796_7_1, sec_r001796_3_2, pub_r001796_4_2, pub_r001796_5_2, pub_r001796_6_2, pub_r001796_7_2);
  int helper_flow_4_1 = fn_R001796_9613_4(sec_r001796_4_1, pub_r001796_5_1, pub_r001796_6_1, pub_r001796_7_1);
  int helper_flow_4_2 = fn_R001796_9613_4(sec_r001796_4_2, pub_r001796_5_2, pub_r001796_6_2, pub_r001796_7_2);
  fn_R001796_9613_4_2(sec_r001796_4_1, pub_r001796_5_1, pub_r001796_6_1, pub_r001796_7_1, sec_r001796_4_2, pub_r001796_5_2, pub_r001796_6_2, pub_r001796_7_2);
  int helper_flow_5_1 = fn_R001796_9613_5(sec_r001796_5_1, pub_r001796_6_1);
  int helper_flow_5_2 = fn_R001796_9613_5(sec_r001796_5_2, pub_r001796_6_2);
  fn_R001796_9613_5_2(sec_r001796_5_1, pub_r001796_6_1, sec_r001796_5_2, pub_r001796_6_2);
  int helper_flow_6_1 = fn_R001796_9613_6(sec_r001796_6_1, sec_r001796_7_1, pub_r001796_8_1, pub_r001796_9_1, pub_r001796_10_1);
  int helper_flow_6_2 = fn_R001796_9613_6(sec_r001796_6_2, sec_r001796_7_2, pub_r001796_8_2, pub_r001796_9_2, pub_r001796_10_2);
  fn_R001796_9613_6_2(sec_r001796_6_1, sec_r001796_7_1, pub_r001796_8_1, pub_r001796_9_1, pub_r001796_10_1, sec_r001796_6_2, sec_r001796_7_2, pub_r001796_8_2, pub_r001796_9_2, pub_r001796_10_2);
  int helper_flow_7_1 = fn_R001796_9613_7(sec_r001796_7_1, sec_r001796_8_1);
  int helper_flow_7_2 = fn_R001796_9613_7(sec_r001796_7_2, sec_r001796_8_2);
  fn_R001796_9613_7_2(sec_r001796_7_1, sec_r001796_8_1, sec_r001796_7_2, sec_r001796_8_2);
  int helper_flow_8_1 = fn_R001796_9613_8(sec_r001796_8_1, pub_r001796_9_1, pub_r001796_10_1, pub_r001796_11_1, pub_r001796_12_1);
  int helper_flow_8_2 = fn_R001796_9613_8(sec_r001796_8_2, pub_r001796_9_2, pub_r001796_10_2, pub_r001796_11_2, pub_r001796_12_2);
  fn_R001796_9613_8_2(sec_r001796_8_1, pub_r001796_9_1, pub_r001796_10_1, pub_r001796_11_1, pub_r001796_12_1, sec_r001796_8_2, pub_r001796_9_2, pub_r001796_10_2, pub_r001796_11_2, pub_r001796_12_2);
  int stage_v_0_1 = ((pub_r001796_4_1 * 2) + 5) & 63;
  int stage_v_0_2 = ((pub_r001796_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001796_0_1 * 2) + 22) & 63;
  int stage_v_1_2 = ((pub_r001796_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((helper_flow_7_1 + (pub_r001796_1_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((helper_flow_7_2 + (pub_r001796_1_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((sec_r001796_15_1 + (pub_r001796_9_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((sec_r001796_15_2 + (pub_r001796_9_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((helper_flow_7_1 + (pub_r001796_10_1 * 2)) + 17) & 127;
  int stage_v_4_2 = ((helper_flow_7_2 + (pub_r001796_10_2 * 2)) + 17) & 127;
  if (stage_v_4_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_4_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_4_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_4_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_5_1 = ((helper_flow_5_1 + (pub_r001796_12_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((helper_flow_5_2 + (pub_r001796_12_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((pub_r001796_15_1 * 2) + 20) & 63;
  int stage_v_6_2 = ((pub_r001796_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001796_12_1 * 2) + 10) & 63;
  int stage_v_7_2 = ((pub_r001796_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((sec_r001796_10_1 + (pub_r001796_15_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((sec_r001796_10_2 + (pub_r001796_15_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((pub_r001796_14_1 * 2) + 40) & 63;
  int stage_v_9_2 = ((pub_r001796_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((sec_r001796_16_1 + (pub_r001796_7_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((sec_r001796_16_2 + (pub_r001796_7_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((pub_r001796_9_1 * 2) + 43) & 63;
  int stage_v_11_2 = ((pub_r001796_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((sec_r001796_1_1 + (pub_r001796_5_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((sec_r001796_1_2 + (pub_r001796_5_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((stage_v_5_1 + (pub_r001796_9_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((stage_v_5_2 + (pub_r001796_9_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((pub_r001796_11_1 * 2) + 37) & 63;
  int stage_v_14_2 = ((pub_r001796_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((helper_flow_0_1 + (pub_r001796_0_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((helper_flow_0_2 + (pub_r001796_0_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((pub_r001796_13_1 * 2) + 8) & 63;
  int stage_v_16_2 = ((pub_r001796_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((stage_v_10_1 + (pub_r001796_0_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((stage_v_10_2 + (pub_r001796_0_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((pub_r001796_0_1 * 2) + 40) & 63;
  int stage_v_18_2 = ((pub_r001796_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001796_15_1 * 2) + 15) & 63;
  int stage_v_19_2 = ((pub_r001796_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((helper_flow_0_1 + (pub_r001796_12_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((helper_flow_0_2 + (pub_r001796_12_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((sec_r001796_6_1 + (pub_r001796_0_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((sec_r001796_6_2 + (pub_r001796_0_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((stage_v_8_1 + (pub_r001796_0_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((stage_v_8_2 + (pub_r001796_0_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((stage_v_15_1 + (pub_r001796_4_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((stage_v_15_2 + (pub_r001796_4_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((stage_v_23_1 + (pub_r001796_3_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((stage_v_23_2 + (pub_r001796_3_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((pub_r001796_11_1 * 2) + 24) & 63;
  int stage_v_25_2 = ((pub_r001796_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((helper_flow_6_1 + (pub_r001796_3_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((helper_flow_6_2 + (pub_r001796_3_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((sec_r001796_3_1 + (pub_r001796_5_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((sec_r001796_3_2 + (pub_r001796_5_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((sec_r001796_14_1 + (pub_r001796_1_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((sec_r001796_14_2 + (pub_r001796_1_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((sec_r001796_2_1 + (pub_r001796_13_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((sec_r001796_2_2 + (pub_r001796_13_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((pub_r001796_5_1 * 2) + 47) & 63;
  int stage_v_30_2 = ((pub_r001796_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((stage_v_27_1 + (pub_r001796_13_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((stage_v_27_2 + (pub_r001796_13_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((sec_r001796_5_1 + (pub_r001796_5_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((sec_r001796_5_2 + (pub_r001796_5_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((sec_r001796_17_1 + (pub_r001796_6_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((sec_r001796_17_2 + (pub_r001796_6_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((stage_v_3_1 + (pub_r001796_8_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((stage_v_3_2 + (pub_r001796_8_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((pub_r001796_14_1 * 2) + 38) & 63;
  int stage_v_35_2 = ((pub_r001796_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((sec_r001796_0_1 + (pub_r001796_3_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((sec_r001796_0_2 + (pub_r001796_3_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((stage_v_31_1 + (pub_r001796_15_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((stage_v_31_2 + (pub_r001796_15_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((stage_v_26_1 + (pub_r001796_7_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((stage_v_26_2 + (pub_r001796_7_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((pub_r001796_3_1 * 2) + 5) & 63;
  int stage_v_39_2 = ((pub_r001796_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((sec_r001796_15_1 + (pub_r001796_2_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((sec_r001796_15_2 + (pub_r001796_2_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((stage_v_27_1 + (pub_r001796_3_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((stage_v_27_2 + (pub_r001796_3_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((helper_flow_5_1 + (pub_r001796_11_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((helper_flow_5_2 + (pub_r001796_11_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((stage_v_42_1 + (pub_r001796_14_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((stage_v_42_2 + (pub_r001796_14_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((sec_r001796_8_1 + (pub_r001796_12_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((sec_r001796_8_2 + (pub_r001796_12_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((stage_v_40_1 + (pub_r001796_0_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((stage_v_40_2 + (pub_r001796_0_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((pub_r001796_12_1 * 2) + 5) & 63;
  int stage_v_46_2 = ((pub_r001796_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((stage_v_32_1 + (pub_r001796_11_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((stage_v_32_2 + (pub_r001796_11_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((sec_r001796_1_1 + (pub_r001796_1_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((sec_r001796_1_2 + (pub_r001796_1_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((sec_r001796_1_1 + (pub_r001796_14_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((sec_r001796_1_2 + (pub_r001796_14_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((stage_v_23_1 + (pub_r001796_15_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((stage_v_23_2 + (pub_r001796_15_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((pub_r001796_12_1 * 2) + 45) & 63;
  int stage_v_51_2 = ((pub_r001796_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001796_12_1 * 2) + 42) & 63;
  int stage_v_52_2 = ((pub_r001796_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001796_5_1 * 2) + 22) & 63;
  int stage_v_53_2 = ((pub_r001796_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((sec_r001796_8_1 + (pub_r001796_10_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((sec_r001796_8_2 + (pub_r001796_10_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((stage_v_41_1 + (pub_r001796_4_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((stage_v_41_2 + (pub_r001796_4_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((stage_v_50_1 + (pub_r001796_11_1 * 2)) + 173) & 127;
  int stage_v_56_2 = ((stage_v_50_2 + (pub_r001796_11_2 * 2)) + 173) & 127;
  if (stage_v_56_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_56_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_56_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_56_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_57_1 = ((stage_v_32_1 + (pub_r001796_3_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((stage_v_32_2 + (pub_r001796_3_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((pub_r001796_1_1 * 2) + 48) & 63;
  int stage_v_58_2 = ((pub_r001796_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((stage_v_8_1 + (pub_r001796_7_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((stage_v_8_2 + (pub_r001796_7_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((stage_v_33_1 + (pub_r001796_14_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((stage_v_33_2 + (pub_r001796_14_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((stage_v_44_1 + (pub_r001796_9_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((stage_v_44_2 + (pub_r001796_9_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((stage_v_32_1 + (pub_r001796_7_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((stage_v_32_2 + (pub_r001796_7_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((pub_r001796_4_1 * 2) + 16) & 63;
  int stage_v_63_2 = ((pub_r001796_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((helper_flow_8_1 + (pub_r001796_12_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((helper_flow_8_2 + (pub_r001796_12_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((pub_r001796_7_1 * 2) + 16) & 63;
  int stage_v_65_2 = ((pub_r001796_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((sec_r001796_14_1 + (pub_r001796_2_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((sec_r001796_14_2 + (pub_r001796_2_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((pub_r001796_14_1 * 2) + 32) & 63;
  int stage_v_67_2 = ((pub_r001796_14_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001796_1_1 * 2) + 39) & 63;
  int stage_v_68_2 = ((pub_r001796_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((stage_v_12_1 + (pub_r001796_1_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((stage_v_12_2 + (pub_r001796_1_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((sec_r001796_0_1 + (pub_r001796_11_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((sec_r001796_0_2 + (pub_r001796_11_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((stage_v_10_1 + (pub_r001796_9_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_10_2 + (pub_r001796_9_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((pub_r001796_2_1 * 2) + 11) & 63;
  int stage_v_72_2 = ((pub_r001796_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((stage_v_48_1 + (pub_r001796_9_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_48_2 + (pub_r001796_9_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((stage_v_27_1 + (pub_r001796_14_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((stage_v_27_2 + (pub_r001796_14_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((stage_v_42_1 + (pub_r001796_1_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((stage_v_42_2 + (pub_r001796_1_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((pub_r001796_13_1 * 2) + 16) & 63;
  int stage_v_76_2 = ((pub_r001796_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001796_4_1 * 2) + 44) & 63;
  int stage_v_77_2 = ((pub_r001796_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((stage_v_17_1 + (pub_r001796_5_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_17_2 + (pub_r001796_5_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((pub_r001796_8_1 * 2) + 50) & 63;
  int stage_v_79_2 = ((pub_r001796_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((sec_r001796_4_1 + (pub_r001796_1_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((sec_r001796_4_2 + (pub_r001796_1_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((pub_r001796_6_1 * 2) + 6) & 63;
  int stage_v_81_2 = ((pub_r001796_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001796_5_1 * 2) + 39) & 63;
  int stage_v_82_2 = ((pub_r001796_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((sec_r001796_6_1 + (pub_r001796_8_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((sec_r001796_6_2 + (pub_r001796_8_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((stage_v_80_1 + (pub_r001796_5_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((stage_v_80_2 + (pub_r001796_5_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((sec_r001796_8_1 + (pub_r001796_2_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((sec_r001796_8_2 + (pub_r001796_2_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((pub_r001796_0_1 * 2) + 31) & 63;
  int stage_v_86_2 = ((pub_r001796_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((stage_v_44_1 + (pub_r001796_6_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_44_2 + (pub_r001796_6_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((stage_v_47_1 + (pub_r001796_13_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((stage_v_47_2 + (pub_r001796_13_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((sec_r001796_1_1 + (pub_r001796_9_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((sec_r001796_1_2 + (pub_r001796_9_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((stage_v_80_1 + (pub_r001796_12_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((stage_v_80_2 + (pub_r001796_12_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((pub_r001796_9_1 * 2) + 38) & 63;
  int stage_v_91_2 = ((pub_r001796_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001796_13_1 * 2) + 21) & 63;
  int stage_v_92_2 = ((pub_r001796_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((stage_v_15_1 + (pub_r001796_11_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((stage_v_15_2 + (pub_r001796_11_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((stage_v_45_1 + (pub_r001796_11_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_45_2 + (pub_r001796_11_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((pub_r001796_11_1 * 2) + 29) & 63;
  int stage_v_95_2 = ((pub_r001796_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001796_10_1 * 2) + 32) & 63;
  int stage_v_96_2 = ((pub_r001796_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((stage_v_10_1 + (pub_r001796_10_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((stage_v_10_2 + (pub_r001796_10_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((stage_v_49_1 + (pub_r001796_13_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_49_2 + (pub_r001796_13_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((sec_r001796_10_1 + (pub_r001796_15_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((sec_r001796_10_2 + (pub_r001796_15_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((stage_v_13_1 + (pub_r001796_7_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((stage_v_13_2 + (pub_r001796_7_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((sec_r001796_2_1 + (pub_r001796_5_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((sec_r001796_2_2 + (pub_r001796_5_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((pub_r001796_4_1 * 2) + 15) & 63;
  int stage_v_102_2 = ((pub_r001796_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((stage_v_97_1 + (pub_r001796_12_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_97_2 + (pub_r001796_12_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((stage_v_57_1 + (pub_r001796_2_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((stage_v_57_2 + (pub_r001796_2_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((stage_v_32_1 + (pub_r001796_8_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_32_2 + (pub_r001796_8_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((stage_v_99_1 + (pub_r001796_4_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_99_2 + (pub_r001796_4_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((stage_v_4_1 + (pub_r001796_3_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_4_2 + (pub_r001796_3_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((pub_r001796_6_1 * 2) + 31) & 63;
  int stage_v_108_2 = ((pub_r001796_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001796_15_1 * 2) + 19) & 63;
  int stage_v_109_2 = ((pub_r001796_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001796_10_1 * 2) + 9) & 63;
  int stage_v_110_2 = ((pub_r001796_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001796_0_1 * 2) + 28) & 63;
  int stage_v_111_2 = ((pub_r001796_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001796_13_1 * 2) + 18) & 63;
  int stage_v_112_2 = ((pub_r001796_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((stage_v_97_1 + (pub_r001796_10_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((stage_v_97_2 + (pub_r001796_10_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((pub_r001796_1_1 * 2) + 36) & 63;
  int stage_v_114_2 = ((pub_r001796_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((stage_v_85_1 + (pub_r001796_9_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_85_2 + (pub_r001796_9_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((stage_v_38_1 + (pub_r001796_13_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_38_2 + (pub_r001796_13_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((pub_r001796_12_1 * 2) + 16) & 63;
  int stage_v_117_2 = ((pub_r001796_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((stage_v_104_1 + (pub_r001796_1_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_104_2 + (pub_r001796_1_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((stage_v_62_1 + (pub_r001796_2_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((stage_v_62_2 + (pub_r001796_2_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((stage_v_24_1 + (pub_r001796_2_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((stage_v_24_2 + (pub_r001796_2_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((pub_r001796_4_1 * 2) + 28) & 63;
  int stage_v_121_2 = ((pub_r001796_4_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((helper_flow_3_1 + (pub_r001796_6_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((helper_flow_3_2 + (pub_r001796_6_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((stage_v_74_1 + (pub_r001796_2_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_74_2 + (pub_r001796_2_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((pub_r001796_3_1 * 2) + 23) & 63;
  int stage_v_124_2 = ((pub_r001796_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((stage_v_101_1 + (pub_r001796_7_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_101_2 + (pub_r001796_7_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((stage_v_80_1 + (pub_r001796_6_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_80_2 + (pub_r001796_6_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((stage_v_115_1 + (pub_r001796_1_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((stage_v_115_2 + (pub_r001796_1_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((pub_r001796_9_1 * 2) + 26) & 63;
  int stage_v_128_2 = ((pub_r001796_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((stage_v_41_1 + (pub_r001796_15_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((stage_v_41_2 + (pub_r001796_15_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((stage_v_43_1 + (pub_r001796_10_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_43_2 + (pub_r001796_10_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((helper_flow_6_1 + (pub_r001796_9_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((helper_flow_6_2 + (pub_r001796_9_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((pub_r001796_5_1 * 2) + 34) & 63;
  int stage_v_132_2 = ((pub_r001796_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001796_8_1 * 2) + 43) & 63;
  int stage_v_133_2 = ((pub_r001796_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001796_0_1 * 2) + 35) & 63;
  int stage_v_134_2 = ((pub_r001796_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((stage_v_23_1 + (pub_r001796_4_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_23_2 + (pub_r001796_4_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((stage_v_42_1 + (pub_r001796_12_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_42_2 + (pub_r001796_12_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((stage_v_74_1 + (pub_r001796_12_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_74_2 + (pub_r001796_12_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((pub_r001796_12_1 * 2) + 34) & 63;
  int stage_v_138_2 = ((pub_r001796_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((stage_v_28_1 + (pub_r001796_11_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((stage_v_28_2 + (pub_r001796_11_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((stage_v_120_1 + (pub_r001796_1_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_120_2 + (pub_r001796_1_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((stage_v_84_1 + (pub_r001796_0_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((stage_v_84_2 + (pub_r001796_0_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((pub_r001796_15_1 * 2) + 34) & 63;
  int stage_v_142_2 = ((pub_r001796_15_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((stage_v_140_1 + (pub_r001796_14_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_140_2 + (pub_r001796_14_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((pub_r001796_8_1 * 2) + 13) & 63;
  int stage_v_144_2 = ((pub_r001796_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001796_10_1 * 2) + 49) & 63;
  int stage_v_145_2 = ((pub_r001796_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((sec_r001796_5_1 + (pub_r001796_3_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((sec_r001796_5_2 + (pub_r001796_3_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((stage_v_31_1 + (pub_r001796_12_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_31_2 + (pub_r001796_12_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((sec_r001796_18_1 + (pub_r001796_11_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((sec_r001796_18_2 + (pub_r001796_11_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((sec_r001796_18_1 + (pub_r001796_11_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((sec_r001796_18_2 + (pub_r001796_11_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((stage_v_148_1 + (pub_r001796_4_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_148_2 + (pub_r001796_4_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((stage_v_57_1 + (pub_r001796_7_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_57_2 + (pub_r001796_7_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((sec_r001796_17_1 + (pub_r001796_9_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((sec_r001796_17_2 + (pub_r001796_9_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((stage_v_135_1 + (pub_r001796_5_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_135_2 + (pub_r001796_5_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((pub_r001796_7_1 * 2) + 7) & 63;
  int stage_v_154_2 = ((pub_r001796_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((stage_v_64_1 + (pub_r001796_3_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_64_2 + (pub_r001796_3_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((pub_r001796_9_1 * 2) + 19) & 63;
  int stage_v_156_2 = ((pub_r001796_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001796_1_1 * 2) + 47) & 63;
  int stage_v_157_2 = ((pub_r001796_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((sec_r001796_5_1 + (pub_r001796_15_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((sec_r001796_5_2 + (pub_r001796_15_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((pub_r001796_8_1 * 2) + 29) & 63;
  int stage_v_159_2 = ((pub_r001796_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001796_11_1 * 2) + 41) & 63;
  int stage_v_160_2 = ((pub_r001796_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((stage_v_146_1 + (pub_r001796_10_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_146_2 + (pub_r001796_10_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((stage_v_54_1 + (pub_r001796_14_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((stage_v_54_2 + (pub_r001796_14_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((stage_v_119_1 + (pub_r001796_3_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_119_2 + (pub_r001796_3_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((stage_v_28_1 + (pub_r001796_8_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_28_2 + (pub_r001796_8_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((helper_flow_4_1 + (pub_r001796_4_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((helper_flow_4_2 + (pub_r001796_4_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((stage_v_130_1 + (pub_r001796_13_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_130_2 + (pub_r001796_13_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((pub_r001796_13_1 * 2) + 25) & 63;
  int stage_v_167_2 = ((pub_r001796_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((stage_v_131_1 + (pub_r001796_4_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_131_2 + (pub_r001796_4_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((pub_r001796_4_1 * 2) + 36) & 63;
  int stage_v_169_2 = ((pub_r001796_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001796_3_1 * 2) + 27) & 63;
  int stage_v_170_2 = ((pub_r001796_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((stage_v_161_1 + (pub_r001796_15_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((stage_v_161_2 + (pub_r001796_15_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((pub_r001796_5_1 * 2) + 26) & 63;
  int stage_v_172_2 = ((pub_r001796_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001796_4_1 * 2) + 34) & 63;
  int stage_v_173_2 = ((pub_r001796_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((stage_v_100_1 + (pub_r001796_11_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_100_2 + (pub_r001796_11_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((pub_r001796_8_1 * 2) + 33) & 63;
  int stage_v_175_2 = ((pub_r001796_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((stage_v_147_1 + (pub_r001796_4_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((stage_v_147_2 + (pub_r001796_4_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((pub_r001796_4_1 * 2) + 39) & 63;
  int stage_v_177_2 = ((pub_r001796_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((stage_v_47_1 + (pub_r001796_7_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_47_2 + (pub_r001796_7_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((stage_v_73_1 + (pub_r001796_9_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((stage_v_73_2 + (pub_r001796_9_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((pub_r001796_4_1 * 2) + 43) & 63;
  int stage_v_180_2 = ((pub_r001796_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((stage_v_47_1 + (pub_r001796_10_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_47_2 + (pub_r001796_10_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((stage_v_103_1 + (pub_r001796_11_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_103_2 + (pub_r001796_11_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((stage_v_62_1 + (pub_r001796_13_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_62_2 + (pub_r001796_13_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((stage_v_50_1 + (pub_r001796_1_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_50_2 + (pub_r001796_1_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((pub_r001796_12_1 * 2) + 14) & 63;
  int stage_v_185_2 = ((pub_r001796_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((stage_v_99_1 + (pub_r001796_5_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((stage_v_99_2 + (pub_r001796_5_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((pub_r001796_11_1 * 2) + 16) & 63;
  int stage_v_187_2 = ((pub_r001796_11_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((sec_r001796_3_1 + (pub_r001796_6_1 * 2)) + 569) & 127;
  int stage_v_188_2 = ((sec_r001796_3_2 + (pub_r001796_6_2 * 2)) + 569) & 127;
  if (stage_v_188_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_188_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_188_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_188_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_189_1 = ((sec_r001796_0_1 + (pub_r001796_15_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((sec_r001796_0_2 + (pub_r001796_15_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((pub_r001796_8_1 * 2) + 29) & 63;
  int stage_v_190_2 = ((pub_r001796_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((sec_r001796_16_1 + (pub_r001796_7_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((sec_r001796_16_2 + (pub_r001796_7_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((stage_v_41_1 + (pub_r001796_10_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_41_2 + (pub_r001796_10_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((stage_v_98_1 + (pub_r001796_15_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_98_2 + (pub_r001796_15_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((stage_v_38_1 + (pub_r001796_9_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_38_2 + (pub_r001796_9_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((pub_r001796_0_1 * 2) + 42) & 63;
  int stage_v_195_2 = ((pub_r001796_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001796_5_1 * 2) + 46) & 63;
  int stage_v_196_2 = ((pub_r001796_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((sec_r001796_8_1 + (pub_r001796_14_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((sec_r001796_8_2 + (pub_r001796_14_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((stage_v_12_1 + (pub_r001796_14_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((stage_v_12_2 + (pub_r001796_14_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((stage_v_74_1 + (pub_r001796_7_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_74_2 + (pub_r001796_7_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((stage_v_44_1 + (pub_r001796_5_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_44_2 + (pub_r001796_5_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((stage_v_64_1 + (pub_r001796_12_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_64_2 + (pub_r001796_12_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((sec_r001796_3_1 + (pub_r001796_8_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((sec_r001796_3_2 + (pub_r001796_8_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((stage_v_106_1 + (pub_r001796_0_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((stage_v_106_2 + (pub_r001796_0_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((pub_r001796_3_1 * 2) + 9) & 63;
  int stage_v_204_2 = ((pub_r001796_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((stage_v_24_1 + (pub_r001796_6_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_24_2 + (pub_r001796_6_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((sec_r001796_9_1 + (pub_r001796_14_1 * 2)) + 623) & 127;
  int stage_v_206_2 = ((sec_r001796_9_2 + (pub_r001796_14_2 * 2)) + 623) & 127;
  if (stage_v_206_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_206_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_206_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_206_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_207_1 = ((stage_v_120_1 + (pub_r001796_9_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((stage_v_120_2 + (pub_r001796_9_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((stage_v_48_1 + (pub_r001796_0_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_48_2 + (pub_r001796_0_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((pub_r001796_10_1 * 2) + 13) & 63;
  int stage_v_209_2 = ((pub_r001796_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001796_15_1 * 2) + 13) & 63;
  int stage_v_210_2 = ((pub_r001796_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001796_1_1 * 2) + 39) & 63;
  int stage_v_211_2 = ((pub_r001796_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((pub_r001796_2_1 * 2) + 31) & 63;
  int stage_v_212_2 = ((pub_r001796_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001796_1_1 * 2) + 31) & 63;
  int stage_v_213_2 = ((pub_r001796_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((sec_r001796_8_1 + (pub_r001796_13_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((sec_r001796_8_2 + (pub_r001796_13_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((stage_v_150_1 + (pub_r001796_7_1 * 2)) + 650) & 127;
  int stage_v_215_2 = ((stage_v_150_2 + (pub_r001796_7_2 * 2)) + 650) & 127;
  if (stage_v_215_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_215_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_215_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_215_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_216_1 = ((stage_v_163_1 + (pub_r001796_10_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((stage_v_163_2 + (pub_r001796_10_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_217_1 = ((stage_v_27_1 + (pub_r001796_1_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((stage_v_27_2 + (pub_r001796_1_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((pub_r001796_2_1 * 2) + 41) & 63;
  int stage_v_218_2 = ((pub_r001796_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((stage_v_176_1 + (pub_r001796_6_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((stage_v_176_2 + (pub_r001796_6_2 * 2)) + 662) & 127;
  if (stage_v_219_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_219_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_219_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_219_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_220_1 = ((stage_v_45_1 + (pub_r001796_13_1 * 2)) + 665) & 127;
  int stage_v_220_2 = ((stage_v_45_2 + (pub_r001796_13_2 * 2)) + 665) & 127;
  if (stage_v_220_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_220_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_220_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_220_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_221_1 = ((stage_v_10_1 + (pub_r001796_12_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((stage_v_10_2 + (pub_r001796_12_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((pub_r001796_15_1 * 2) + 26) & 63;
  int stage_v_222_2 = ((pub_r001796_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((sec_r001796_18_1 + (pub_r001796_7_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((sec_r001796_18_2 + (pub_r001796_7_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((pub_r001796_13_1 * 2) + 30) & 63;
  int stage_v_224_2 = ((pub_r001796_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((stage_v_21_1 + (pub_r001796_11_1 * 2)) + 680) & 127;
  int stage_v_225_2 = ((stage_v_21_2 + (pub_r001796_11_2 * 2)) + 680) & 127;
  if (stage_v_225_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_225_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_225_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_225_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_226_1 = ((stage_v_34_1 + (pub_r001796_10_1 * 2)) + 683) & 127;
  int stage_v_226_2 = ((stage_v_34_2 + (pub_r001796_10_2 * 2)) + 683) & 127;
  if (stage_v_226_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_226_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_226_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_226_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_227_1 = ((stage_v_220_1 + (pub_r001796_13_1 * 2)) + 686) & 127;
  int stage_v_227_2 = ((stage_v_220_2 + (pub_r001796_13_2 * 2)) + 686) & 127;
  if (stage_v_227_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_227_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_227_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_227_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_228_1 = ((pub_r001796_2_1 * 2) + 39) & 63;
  int stage_v_228_2 = ((pub_r001796_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((sec_r001796_1_1 + (pub_r001796_7_1 * 2)) + 692) & 127;
  int stage_v_229_2 = ((sec_r001796_1_2 + (pub_r001796_7_2 * 2)) + 692) & 127;
  if (stage_v_229_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_229_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_229_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_229_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_230_1 = ((pub_r001796_3_1 * 2) + 23) & 63;
  int stage_v_230_2 = ((pub_r001796_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((stage_v_192_1 + (pub_r001796_7_1 * 2)) + 698) & 127;
  int stage_v_231_2 = ((stage_v_192_2 + (pub_r001796_7_2 * 2)) + 698) & 127;
  if (stage_v_231_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_231_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_231_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_231_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_232_1 = ((helper_flow_0_1 + (pub_r001796_4_1 * 2)) + 701) & 127;
  int stage_v_232_2 = ((helper_flow_0_2 + (pub_r001796_4_2 * 2)) + 701) & 127;
  if (stage_v_232_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_232_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_232_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_232_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001796_6_1 == pub_r001796_6_2);
  __CPROVER_assume(pub_r001796_8_1 == pub_r001796_8_2);
  __CPROVER_assume(pub_r001796_10_1 == pub_r001796_10_2);
  __CPROVER_assume(pub_r001796_9_1 == pub_r001796_9_2);
  __CPROVER_assume(sec_r001796_14_1 != sec_r001796_14_2);
  __CPROVER_assume(sec_r001796_5_1 != sec_r001796_5_2);
  __CPROVER_assume(sec_r001796_3_1 != sec_r001796_3_2);
  __CPROVER_assume(sec_r001796_12_1 != sec_r001796_12_2);
  __CPROVER_assume(pub_r001796_7_1 == pub_r001796_7_2);
  __CPROVER_assume(sec_r001796_13_1 != sec_r001796_13_2);
  __CPROVER_assume(sec_r001796_11_1 != sec_r001796_11_2);
  __CPROVER_assume(sec_r001796_16_1 != sec_r001796_16_2);
  __CPROVER_assume(sec_r001796_1_1 != sec_r001796_1_2);
  __CPROVER_assume(sec_r001796_0_1 != sec_r001796_0_2);
  __CPROVER_assume(sec_r001796_18_1 != sec_r001796_18_2);
  __CPROVER_assume(sec_r001796_17_1 != sec_r001796_17_2);
  __CPROVER_assume(sec_r001796_6_1 != sec_r001796_6_2);
  __CPROVER_assume(sec_r001796_7_1 != sec_r001796_7_2);
  __CPROVER_assume(pub_r001796_14_1 == pub_r001796_14_2);
  __CPROVER_assume(sec_r001796_4_1 != sec_r001796_4_2);
  __CPROVER_assume(pub_r001796_15_1 == pub_r001796_15_2);
  __CPROVER_assume(sec_r001796_9_1 != sec_r001796_9_2);
  __CPROVER_assume(pub_r001796_1_1 == pub_r001796_1_2);
  __CPROVER_assume(pub_r001796_0_1 == pub_r001796_0_2);
  __CPROVER_assume(pub_r001796_5_1 == pub_r001796_5_2);
  __CPROVER_assume(pub_r001796_3_1 == pub_r001796_3_2);
  __CPROVER_assume(sec_r001796_15_1 != sec_r001796_15_2);
  __CPROVER_assume(pub_r001796_11_1 == pub_r001796_11_2);
  __CPROVER_assume(pub_r001796_12_1 == pub_r001796_12_2);
  __CPROVER_assume(pub_r001796_13_1 == pub_r001796_13_2);
  __CPROVER_assume(pub_r001796_2_1 == pub_r001796_2_2);
  __CPROVER_assume(sec_r001796_8_1 != sec_r001796_8_2);
  __CPROVER_assume(sec_r001796_2_1 != sec_r001796_2_2);
  __CPROVER_assume(pub_r001796_4_1 == pub_r001796_4_2);
  __CPROVER_assume(sec_r001796_10_1 != sec_r001796_10_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  assert(st_var_2_1.id == st_var_2_2.id);
  assert(st_var_2_1.parity == st_var_2_2.parity);
  assert(st_var_2_1.stop_bits == st_var_2_2.stop_bits);
  assert(st_var_2_1.port == st_var_2_2.port);
  assert(st_var_2_1.timeout == st_var_2_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.status == st_var_3_2.status);
  assert(st_var_3_1.reading == st_var_3_2.reading);
  assert(st_var_3_1.calib == st_var_3_2.calib);
  assert(st_var_3_1.offset == st_var_3_2.offset);
  assert(st_var_3_1.gain == st_var_3_2.gain);
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
}


