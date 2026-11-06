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
struct Vector3D_R000094_9413_0
{
  int coord_z;
  int coord_y;
  int norm_sq;
  unsigned char coord_x;
  int heading;
  unsigned char pitch;
  int buffer[3];
};
struct AudioFrame_R000094_9413_1
{
  int sample_rate;
  short envelope;
  int peak;
  int rms;
  short channels;
  int buffer[3];
};
struct EventLog_R000094_9413_2
{
  unsigned char severity;
  short facility;
  unsigned char seq;
  int code;
  int buffer[3];
};
struct DeviceConfig_R000094_9413_3
{
  int timeout;
  short id;
  short baud_rate;
  unsigned char parity;
  int buffer[3];
};
union TelemetryField_R000094_9413_0
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
void fn_R000094_9413_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000094_9413_0 st_1 = {0};
  struct Vector3D_R000094_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int stride_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_98_1)
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

  switch (stride_98_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_98_1 == stride_98_2);
}

int fn_R000094_9413_0(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000094_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int stride_98 = (aux + st.buffer[1]) & 3;
  switch (stride_98)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000094_9413_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000094_9413_0 st_1 = {0};
  struct Vector3D_R000094_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_70_1 = local_arr_1[aux_1 % 3];
  int mask_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_70_2 * 2)) & 127;
  int bound_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_88_1)
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

  switch (bound_88_2)
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

  int metric_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_45_1) & 63;
  aux_2 = (aux_2 + metric_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
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

  assert(mask_70_1 == mask_70_2);
  assert(bound_88_1 == bound_88_2);
  assert(metric_45_1 == metric_45_2);
}

int fn_R000094_9413_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000094_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int mask_70 = local_arr[aux % 3];
  acc = (acc + (mask_70 * 2)) & 127;
  int bound_88 = (aux + st.buffer[1]) & 3;
  switch (bound_88)
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

  int metric_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_45) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000094_9413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000094_9413_1 st_1 = {0};
  struct AudioFrame_R000094_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int coefficient_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_62_1)
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

  switch (coefficient_62_2)
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

  int sample_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_24_1) & 63;
  aux_2 = (aux_2 + sample_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_93_1 = local_arr_1[aux_1 % 3];
  int offset_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_93_2 * 2)) & 127;
  int anchor_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_10_1 > 28)
  {
    acc_1 = ((acc_1 + (anchor_10_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_10_2 > 28)
  {
    acc_2 = ((acc_2 + (anchor_10_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_10_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_62_1 == coefficient_62_2);
  assert(sample_24_1 == sample_24_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_93_1 == offset_93_2);
  assert(anchor_10_1 == anchor_10_2);
}

int fn_R000094_9413_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000094_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int coefficient_62 = (aux + st.buffer[1]) & 3;
  switch (coefficient_62)
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

  int sample_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_24) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_93 = local_arr[aux % 3];
  acc = (acc + (offset_93 * 2)) & 127;
  int anchor_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_10 > 28)
  {
    acc = ((acc + (anchor_10 * 2)) + 5) & 127;
    aux ^= anchor_10 & 15;
  }
  else
  {
    acc = ((acc - anchor_10) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000094_9413_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000094_9413_1 st_1 = {0};
  struct AudioFrame_R000094_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int bound_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_14_1)
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

  switch (bound_14_2)
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
  int delta_51_1 = local_arr_1[aux_1 % 3];
  int delta_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_14_1 == bound_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_51_1 == delta_51_2);
}

int fn_R000094_9413_3(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000094_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int bound_14 = (aux + st.buffer[1]) & 3;
  switch (bound_14)
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
  int delta_51 = local_arr[aux % 3];
  acc = (acc + (delta_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000094_9413_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000094_9413_1 st_1 = {0};
  struct AudioFrame_R000094_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_95_1 > 29)
  {
    acc_1 = ((acc_1 + (quantum_95_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_95_2 > 29)
  {
    acc_2 = ((acc_2 + (quantum_95_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_53_1) & 63;
  aux_2 = (aux_2 + quotient_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_35_1)
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

  switch (threshold_35_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_95_1 == quantum_95_2);
  assert(quotient_53_1 == quotient_53_2);
  assert(threshold_35_1 == threshold_35_2);
}

int fn_R000094_9413_4(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000094_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_95 > 29)
  {
    acc = ((acc + (quantum_95 * 2)) + 5) & 127;
    aux ^= quantum_95 & 15;
  }
  else
  {
    acc = ((acc - quantum_95) + 11) & 127;
    aux += 3;
  }
  int quotient_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_53) & 63;
  acc ^= aux;
  int threshold_35 = (aux + st.buffer[1]) & 3;
  switch (threshold_35)
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

void fn_R000094_9413_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000094_9413_1 st_1 = {0};
  struct AudioFrame_R000094_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int margin_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_17_1) & 63;
  aux_2 = (aux_2 + margin_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_84_1 = local_arr_1[aux_1 % 3];
  int scale_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_84_2 * 2)) & 127;
  int margin_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_73_1)
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

  switch (margin_73_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_17_1 == margin_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_84_1 == scale_84_2);
  assert(margin_73_1 == margin_73_2);
}

int fn_R000094_9413_5(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000094_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int margin_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_17) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_84 = local_arr[aux % 3];
  acc = (acc + (scale_84 * 2)) & 127;
  int margin_73 = (aux + st.buffer[1]) & 3;
  switch (margin_73)
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

void fn_R000094_9413_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000094_9413_0 st_1 = {0};
  struct Vector3D_R000094_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_90_1 = local_arr_1[aux_1 % 3];
  int quotient_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
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

  assert(quotient_90_1 == quotient_90_2);
}

int fn_R000094_9413_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000094_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quotient_90 = local_arr[aux % 3];
  acc = (acc + (quotient_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000094_9413_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000094_9413_0 st_1 = {0};
  struct Vector3D_R000094_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int residue_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_54_1) & 63;
  aux_2 = (aux_2 + residue_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_44_1)
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

  switch (vector_44_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_54_1 == residue_54_2);
  assert(vector_44_1 == vector_44_2);
}

int fn_R000094_9413_7(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000094_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int residue_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_54) & 63;
  acc ^= aux;
  int vector_44 = (aux + st.buffer[1]) & 3;
  switch (vector_44)
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

void fn_R000094_9413_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000094_9413_2 st_1 = {0};
  struct EventLog_R000094_9413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int sample_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_29_1)
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

  switch (sample_29_2)
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
  int mask_96_1 = local_arr_1[aux_1 % 3];
  int mask_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_96_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_29_1 == sample_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_96_1 == mask_96_2);
}

int fn_R000094_9413_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000094_9413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int sample_29 = (aux + st.buffer[1]) & 3;
  switch (sample_29)
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
  int mask_96 = local_arr[aux % 3];
  acc = (acc + (mask_96 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000094_9413_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000094_9413_1 st_1 = {0};
  struct AudioFrame_R000094_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int weight_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_15_1 > 24)
  {
    acc_1 = ((acc_1 + (weight_15_1 * 2)) + 5) & 127;
    aux_1 ^= weight_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_15_2 > 24)
  {
    acc_2 = ((acc_2 + (weight_15_2 * 2)) + 5) & 127;
    aux_2 ^= weight_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_15_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_50_1)
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

  switch (delta_50_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_15_1 == weight_15_2);
  assert(delta_50_1 == delta_50_2);
}

int fn_R000094_9413_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000094_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int weight_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_15 > 24)
  {
    acc = ((acc + (weight_15 * 2)) + 5) & 127;
    aux ^= weight_15 & 15;
  }
  else
  {
    acc = ((acc - weight_15) + 11) & 127;
    aux += 3;
  }
  int delta_50 = (aux + st.buffer[1]) & 3;
  switch (delta_50)
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

void fn_R000094_9413_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000094_9413_3 st_1 = {0};
  struct DeviceConfig_R000094_9413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_20_1)
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

  switch (tracker_20_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_20_1 == tracker_20_2);
}

int fn_R000094_9413_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000094_9413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_20 = (aux + st.buffer[1]) & 3;
  switch (tracker_20)
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

void fn_R000094_9413_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000094_9413_2 st_1 = {0};
  struct EventLog_R000094_9413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_61_1 = local_arr_1[aux_1 % 3];
  int coefficient_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_61_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_21_1 > 36)
  {
    acc_1 = ((acc_1 + (mask_21_1 * 2)) + 5) & 127;
    aux_1 ^= mask_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_21_2 > 36)
  {
    acc_2 = ((acc_2 + (mask_21_2 * 2)) + 5) & 127;
    aux_2 ^= mask_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_21_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_61_1 == coefficient_61_2);
  assert(mask_21_1 == mask_21_2);
}

int fn_R000094_9413_11(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000094_9413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int coefficient_61 = local_arr[aux % 3];
  acc = (acc + (coefficient_61 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_21 > 36)
  {
    acc = ((acc + (mask_21 * 2)) + 5) & 127;
    aux ^= mask_21 & 15;
  }
  else
  {
    acc = ((acc - mask_21) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000094_9413_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000094_9413_0 st_1 = {0};
  struct Vector3D_R000094_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int sample_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_27_1) & 63;
  aux_2 = (aux_2 + sample_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_68_1 > 44)
  {
    acc_1 = ((acc_1 + (residue_68_1 * 2)) + 5) & 127;
    aux_1 ^= residue_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_68_2 > 44)
  {
    acc_2 = ((acc_2 + (residue_68_2 * 2)) + 5) & 127;
    aux_2 ^= residue_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_69_1 = local_arr_1[aux_1 % 3];
  int window_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_69_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_27_1 == sample_27_2);
  assert(residue_68_1 == residue_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_69_1 == window_69_2);
}

int fn_R000094_9413_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000094_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int sample_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_27) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_68 > 44)
  {
    acc = ((acc + (residue_68 * 2)) + 5) & 127;
    aux ^= residue_68 & 15;
  }
  else
  {
    acc = ((acc - residue_68) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_69 = local_arr[aux % 3];
  acc = (acc + (window_69 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000094_9413_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000094_9413_3 st_1 = {0};
  struct DeviceConfig_R000094_9413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int vector_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_32_1)
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

  switch (vector_32_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_35_1 > 31)
  {
    acc_1 = ((acc_1 + (window_35_1 * 2)) + 5) & 127;
    aux_1 ^= window_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_35_2 > 31)
  {
    acc_2 = ((acc_2 + (window_35_2 * 2)) + 5) & 127;
    aux_2 ^= window_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_35_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_32_1 == vector_32_2);
  assert(window_35_1 == window_35_2);
}

int fn_R000094_9413_13(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000094_9413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int vector_32 = (aux + st.buffer[1]) & 3;
  switch (vector_32)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_35 > 31)
  {
    acc = ((acc + (window_35 * 2)) + 5) & 127;
    aux ^= window_35 & 15;
  }
  else
  {
    acc = ((acc - window_35) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000094_9413_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000094_9413_0 st_1 = {0};
  struct Vector3D_R000094_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int damping_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_40_1) & 63;
  aux_2 = (aux_2 + damping_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_48_1 > 48)
  {
    acc_1 = ((acc_1 + (vector_48_1 * 2)) + 5) & 127;
    aux_1 ^= vector_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_48_2 > 48)
  {
    acc_2 = ((acc_2 + (vector_48_2 * 2)) + 5) & 127;
    aux_2 ^= vector_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_48_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_83_1 = local_arr_1[aux_1 % 3];
  int weight_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_83_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_40_1 == damping_40_2);
  assert(vector_48_1 == vector_48_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_83_1 == weight_83_2);
}

int fn_R000094_9413_14(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000094_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int damping_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_40) & 63;
  acc ^= aux;
  int vector_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_48 > 48)
  {
    acc = ((acc + (vector_48 * 2)) + 5) & 127;
    aux ^= vector_48 & 15;
  }
  else
  {
    acc = ((acc - vector_48) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int weight_83 = local_arr[aux % 3];
  acc = (acc + (weight_83 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000094_9413_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000094_9413_2 st_1 = {0};
  struct EventLog_R000094_9413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int parity_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_16_1 > 13)
  {
    acc_1 = ((acc_1 + (parity_16_1 * 2)) + 5) & 127;
    aux_1 ^= parity_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_16_2 > 13)
  {
    acc_2 = ((acc_2 + (parity_16_2 * 2)) + 5) & 127;
    aux_2 ^= parity_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_16_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_46_1)
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

  switch (quantum_46_2)
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
  int quotient_80_1 = local_arr_1[aux_1 % 3];
  int quotient_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_80_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_16_1 == parity_16_2);
  assert(quantum_46_1 == quantum_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_80_1 == quotient_80_2);
}

int fn_R000094_9413_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000094_9413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int parity_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_16 > 13)
  {
    acc = ((acc + (parity_16 * 2)) + 5) & 127;
    aux ^= parity_16 & 15;
  }
  else
  {
    acc = ((acc - parity_16) + 11) & 127;
    aux += 3;
  }
  int quantum_46 = (aux + st.buffer[1]) & 3;
  switch (quantum_46)
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
  int quotient_80 = local_arr[aux % 3];
  acc = (acc + (quotient_80 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000094_9413_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000094_9413_0 st_1 = {0};
  struct Vector3D_R000094_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int segment_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_76_1 > 23)
  {
    acc_1 = ((acc_1 + (segment_76_1 * 2)) + 5) & 127;
    aux_1 ^= segment_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_76_2 > 23)
  {
    acc_2 = ((acc_2 + (segment_76_2 * 2)) + 5) & 127;
    aux_2 ^= segment_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_76_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_76_1 == segment_76_2);
}

int fn_R000094_9413_16(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000094_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int segment_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_76 > 23)
  {
    acc = ((acc + (segment_76 * 2)) + 5) & 127;
    aux ^= segment_76 & 15;
  }
  else
  {
    acc = ((acc - segment_76) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000094_9413_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000094_9413_0 st_1 = {0};
  struct Vector3D_R000094_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_94_1 = local_arr_1[aux_1 % 3];
  int segment_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_94_2 * 2)) & 127;
  int scale_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_93_1 > 37)
  {
    acc_1 = ((acc_1 + (scale_93_1 * 2)) + 5) & 127;
    aux_1 ^= scale_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_93_2 > 37)
  {
    acc_2 = ((acc_2 + (scale_93_2 * 2)) + 5) & 127;
    aux_2 ^= scale_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_93_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_56_1) & 63;
  aux_2 = (aux_2 + quantum_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
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

  assert(segment_94_1 == segment_94_2);
  assert(scale_93_1 == scale_93_2);
  assert(quantum_56_1 == quantum_56_2);
}

int fn_R000094_9413_17(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000094_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int segment_94 = local_arr[aux % 3];
  acc = (acc + (segment_94 * 2)) & 127;
  int scale_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_93 > 37)
  {
    acc = ((acc + (scale_93 * 2)) + 5) & 127;
    aux ^= scale_93 & 15;
  }
  else
  {
    acc = ((acc - scale_93) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_56) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000094_9413_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000094_9413_2 st_1 = {0};
  struct EventLog_R000094_9413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int window_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_79_1)
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

  switch (window_79_2)
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

  int quantum_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_65_1 > 37)
  {
    acc_1 = ((acc_1 + (quantum_65_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_65_2 > 37)
  {
    acc_2 = ((acc_2 + (quantum_65_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_65_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_32_1 = local_arr_1[aux_1 % 3];
  int factor_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_79_1 == window_79_2);
  assert(quantum_65_1 == quantum_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_32_1 == factor_32_2);
}

int fn_R000094_9413_18(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000094_9413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int window_79 = (aux + st.buffer[1]) & 3;
  switch (window_79)
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

  int quantum_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_65 > 37)
  {
    acc = ((acc + (quantum_65 * 2)) + 5) & 127;
    aux ^= quantum_65 & 15;
  }
  else
  {
    acc = ((acc - quantum_65) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int factor_32 = local_arr[aux % 3];
  acc = (acc + (factor_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000094_9413_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000094_9413_2 st_1 = {0};
  struct EventLog_R000094_9413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int coefficient_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_69_1 > 20)
  {
    acc_1 = ((acc_1 + (coefficient_69_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_69_2 > 20)
  {
    acc_2 = ((acc_2 + (coefficient_69_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_97_1) & 63;
  aux_2 = (aux_2 + vector_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_69_1 == coefficient_69_2);
  assert(vector_97_1 == vector_97_2);
}

int fn_R000094_9413_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000094_9413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int coefficient_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_69 > 20)
  {
    acc = ((acc + (coefficient_69 * 2)) + 5) & 127;
    aux ^= coefficient_69 & 15;
  }
  else
  {
    acc = ((acc - coefficient_69) + 11) & 127;
    aux += 3;
  }
  int vector_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000094_0_1;
  int sec_r000094_0_2;
  int sec_r000094_1_1;
  int sec_r000094_1_2;
  int sec_r000094_2_1;
  int sec_r000094_2_2;
  int sec_r000094_3_1;
  int sec_r000094_3_2;
  int sec_r000094_4_1;
  int sec_r000094_4_2;
  int sec_r000094_5_1;
  int sec_r000094_5_2;
  int sec_r000094_6_1;
  int sec_r000094_6_2;
  int sec_r000094_7_1;
  int sec_r000094_7_2;
  int sec_r000094_8_1;
  int sec_r000094_8_2;
  int sec_r000094_9_1;
  int sec_r000094_9_2;
  int sec_r000094_10_1;
  int sec_r000094_10_2;
  int sec_r000094_11_1;
  int sec_r000094_11_2;
  int sec_r000094_12_1;
  int sec_r000094_12_2;
  int sec_r000094_13_1;
  int sec_r000094_13_2;
  int sec_r000094_14_1;
  int sec_r000094_14_2;
  int sec_r000094_15_1;
  int sec_r000094_15_2;
  int sec_r000094_16_1;
  int sec_r000094_16_2;
  int sec_r000094_17_1;
  int sec_r000094_17_2;
  int sec_r000094_18_1;
  int sec_r000094_18_2;
  int sec_r000094_19_1;
  int sec_r000094_19_2;
  int sec_r000094_20_1;
  int sec_r000094_20_2;
  int sec_r000094_21_1;
  int sec_r000094_21_2;
  int pub_r000094_0_1;
  int pub_r000094_0_2;
  int pub_r000094_1_1;
  int pub_r000094_1_2;
  int pub_r000094_2_1;
  int pub_r000094_2_2;
  int pub_r000094_3_1;
  int pub_r000094_3_2;
  int pub_r000094_4_1;
  int pub_r000094_4_2;
  int pub_r000094_5_1;
  int pub_r000094_5_2;
  int pub_r000094_6_1;
  int pub_r000094_6_2;
  int pub_r000094_7_1;
  int pub_r000094_7_2;
  int pub_r000094_8_1;
  int pub_r000094_8_2;
  int pub_r000094_9_1;
  int pub_r000094_9_2;
  int pub_r000094_10_1;
  int pub_r000094_10_2;
  int pub_r000094_11_1;
  int pub_r000094_11_2;
  int pub_r000094_12_1;
  int pub_r000094_12_2;
  int pub_r000094_13_1;
  int pub_r000094_13_2;
  int pub_r000094_14_1;
  int pub_r000094_14_2;
  int pub_r000094_15_1;
  int pub_r000094_15_2;
  int pub_r000094_16_1;
  int pub_r000094_16_2;
  int pub_r000094_17_1;
  int pub_r000094_17_2;
  int pub_r000094_18_1;
  int pub_r000094_18_2;
  int pub_r000094_19_1;
  int pub_r000094_19_2;
  int pub_r000094_20_1;
  int pub_r000094_20_2;
  int pub_r000094_21_1;
  int pub_r000094_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000094_0_1 >= (-100)) && (pub_r000094_0_1 <= 100));
  __CPROVER_assume((pub_r000094_0_2 >= (-100)) && (pub_r000094_0_2 <= 100));
  __CPROVER_assume((pub_r000094_1_1 >= (-100)) && (pub_r000094_1_1 <= 100));
  __CPROVER_assume((pub_r000094_1_2 >= (-100)) && (pub_r000094_1_2 <= 100));
  __CPROVER_assume((pub_r000094_2_1 >= (-100)) && (pub_r000094_2_1 <= 100));
  __CPROVER_assume((pub_r000094_2_2 >= (-100)) && (pub_r000094_2_2 <= 100));
  __CPROVER_assume((pub_r000094_3_1 >= (-100)) && (pub_r000094_3_1 <= 100));
  __CPROVER_assume((pub_r000094_3_2 >= (-100)) && (pub_r000094_3_2 <= 100));
  __CPROVER_assume((pub_r000094_4_1 >= (-100)) && (pub_r000094_4_1 <= 100));
  __CPROVER_assume((pub_r000094_4_2 >= (-100)) && (pub_r000094_4_2 <= 100));
  __CPROVER_assume((pub_r000094_5_1 >= (-100)) && (pub_r000094_5_1 <= 100));
  __CPROVER_assume((pub_r000094_5_2 >= (-100)) && (pub_r000094_5_2 <= 100));
  __CPROVER_assume((pub_r000094_6_1 >= (-100)) && (pub_r000094_6_1 <= 100));
  __CPROVER_assume((pub_r000094_6_2 >= (-100)) && (pub_r000094_6_2 <= 100));
  __CPROVER_assume((pub_r000094_7_1 >= (-100)) && (pub_r000094_7_1 <= 100));
  __CPROVER_assume((pub_r000094_7_2 >= (-100)) && (pub_r000094_7_2 <= 100));
  __CPROVER_assume((pub_r000094_8_1 >= (-100)) && (pub_r000094_8_1 <= 100));
  __CPROVER_assume((pub_r000094_8_2 >= (-100)) && (pub_r000094_8_2 <= 100));
  __CPROVER_assume((pub_r000094_9_1 >= (-100)) && (pub_r000094_9_1 <= 100));
  __CPROVER_assume((pub_r000094_9_2 >= (-100)) && (pub_r000094_9_2 <= 100));
  __CPROVER_assume((pub_r000094_10_1 >= (-100)) && (pub_r000094_10_1 <= 100));
  __CPROVER_assume((pub_r000094_10_2 >= (-100)) && (pub_r000094_10_2 <= 100));
  __CPROVER_assume((pub_r000094_11_1 >= (-100)) && (pub_r000094_11_1 <= 100));
  __CPROVER_assume((pub_r000094_11_2 >= (-100)) && (pub_r000094_11_2 <= 100));
  __CPROVER_assume((pub_r000094_12_1 >= (-100)) && (pub_r000094_12_1 <= 100));
  __CPROVER_assume((pub_r000094_12_2 >= (-100)) && (pub_r000094_12_2 <= 100));
  __CPROVER_assume((pub_r000094_13_1 >= (-100)) && (pub_r000094_13_1 <= 100));
  __CPROVER_assume((pub_r000094_13_2 >= (-100)) && (pub_r000094_13_2 <= 100));
  __CPROVER_assume((pub_r000094_14_1 >= (-100)) && (pub_r000094_14_1 <= 100));
  __CPROVER_assume((pub_r000094_14_2 >= (-100)) && (pub_r000094_14_2 <= 100));
  __CPROVER_assume((pub_r000094_15_1 >= (-100)) && (pub_r000094_15_1 <= 100));
  __CPROVER_assume((pub_r000094_15_2 >= (-100)) && (pub_r000094_15_2 <= 100));
  __CPROVER_assume((pub_r000094_16_1 >= (-100)) && (pub_r000094_16_1 <= 100));
  __CPROVER_assume((pub_r000094_16_2 >= (-100)) && (pub_r000094_16_2 <= 100));
  __CPROVER_assume((pub_r000094_17_1 >= (-100)) && (pub_r000094_17_1 <= 100));
  __CPROVER_assume((pub_r000094_17_2 >= (-100)) && (pub_r000094_17_2 <= 100));
  __CPROVER_assume((pub_r000094_18_1 >= (-100)) && (pub_r000094_18_1 <= 100));
  __CPROVER_assume((pub_r000094_18_2 >= (-100)) && (pub_r000094_18_2 <= 100));
  __CPROVER_assume((pub_r000094_19_1 >= (-100)) && (pub_r000094_19_1 <= 100));
  __CPROVER_assume((pub_r000094_19_2 >= (-100)) && (pub_r000094_19_2 <= 100));
  __CPROVER_assume((pub_r000094_20_1 >= (-100)) && (pub_r000094_20_1 <= 100));
  __CPROVER_assume((pub_r000094_20_2 >= (-100)) && (pub_r000094_20_2 <= 100));
  __CPROVER_assume((pub_r000094_21_1 >= (-100)) && (pub_r000094_21_1 <= 100));
  __CPROVER_assume((pub_r000094_21_2 >= (-100)) && (pub_r000094_21_2 <= 100));
  __CPROVER_assume((sec_r000094_0_1 >= 0) && (sec_r000094_0_1 <= 255));
  __CPROVER_assume((sec_r000094_0_2 >= 0) && (sec_r000094_0_2 <= 255));
  __CPROVER_assume((sec_r000094_1_1 >= 0) && (sec_r000094_1_1 <= 255));
  __CPROVER_assume((sec_r000094_1_2 >= 0) && (sec_r000094_1_2 <= 255));
  __CPROVER_assume((sec_r000094_2_1 >= 0) && (sec_r000094_2_1 <= 255));
  __CPROVER_assume((sec_r000094_2_2 >= 0) && (sec_r000094_2_2 <= 255));
  __CPROVER_assume((sec_r000094_3_1 >= 0) && (sec_r000094_3_1 <= 255));
  __CPROVER_assume((sec_r000094_3_2 >= 0) && (sec_r000094_3_2 <= 255));
  __CPROVER_assume((sec_r000094_4_1 >= 0) && (sec_r000094_4_1 <= 255));
  __CPROVER_assume((sec_r000094_4_2 >= 0) && (sec_r000094_4_2 <= 255));
  __CPROVER_assume((sec_r000094_5_1 >= 0) && (sec_r000094_5_1 <= 255));
  __CPROVER_assume((sec_r000094_5_2 >= 0) && (sec_r000094_5_2 <= 255));
  __CPROVER_assume((sec_r000094_6_1 >= 0) && (sec_r000094_6_1 <= 255));
  __CPROVER_assume((sec_r000094_6_2 >= 0) && (sec_r000094_6_2 <= 255));
  __CPROVER_assume((sec_r000094_7_1 >= 0) && (sec_r000094_7_1 <= 255));
  __CPROVER_assume((sec_r000094_7_2 >= 0) && (sec_r000094_7_2 <= 255));
  __CPROVER_assume((sec_r000094_8_1 >= 0) && (sec_r000094_8_1 <= 255));
  __CPROVER_assume((sec_r000094_8_2 >= 0) && (sec_r000094_8_2 <= 255));
  __CPROVER_assume((sec_r000094_9_1 >= 0) && (sec_r000094_9_1 <= 255));
  __CPROVER_assume((sec_r000094_9_2 >= 0) && (sec_r000094_9_2 <= 255));
  __CPROVER_assume((sec_r000094_10_1 >= 0) && (sec_r000094_10_1 <= 255));
  __CPROVER_assume((sec_r000094_10_2 >= 0) && (sec_r000094_10_2 <= 255));
  __CPROVER_assume((sec_r000094_11_1 >= 0) && (sec_r000094_11_1 <= 255));
  __CPROVER_assume((sec_r000094_11_2 >= 0) && (sec_r000094_11_2 <= 255));
  __CPROVER_assume((sec_r000094_12_1 >= 0) && (sec_r000094_12_1 <= 255));
  __CPROVER_assume((sec_r000094_12_2 >= 0) && (sec_r000094_12_2 <= 255));
  __CPROVER_assume((sec_r000094_13_1 >= 0) && (sec_r000094_13_1 <= 255));
  __CPROVER_assume((sec_r000094_13_2 >= 0) && (sec_r000094_13_2 <= 255));
  __CPROVER_assume((sec_r000094_14_1 >= 0) && (sec_r000094_14_1 <= 255));
  __CPROVER_assume((sec_r000094_14_2 >= 0) && (sec_r000094_14_2 <= 255));
  __CPROVER_assume((sec_r000094_15_1 >= 0) && (sec_r000094_15_1 <= 255));
  __CPROVER_assume((sec_r000094_15_2 >= 0) && (sec_r000094_15_2 <= 255));
  __CPROVER_assume((sec_r000094_16_1 >= 0) && (sec_r000094_16_1 <= 255));
  __CPROVER_assume((sec_r000094_16_2 >= 0) && (sec_r000094_16_2 <= 255));
  __CPROVER_assume((sec_r000094_17_1 >= 0) && (sec_r000094_17_1 <= 255));
  __CPROVER_assume((sec_r000094_17_2 >= 0) && (sec_r000094_17_2 <= 255));
  __CPROVER_assume((sec_r000094_18_1 >= 0) && (sec_r000094_18_1 <= 255));
  __CPROVER_assume((sec_r000094_18_2 >= 0) && (sec_r000094_18_2 <= 255));
  __CPROVER_assume((sec_r000094_19_1 >= 0) && (sec_r000094_19_1 <= 255));
  __CPROVER_assume((sec_r000094_19_2 >= 0) && (sec_r000094_19_2 <= 255));
  __CPROVER_assume((sec_r000094_20_1 >= 0) && (sec_r000094_20_1 <= 255));
  __CPROVER_assume((sec_r000094_20_2 >= 0) && (sec_r000094_20_2 <= 255));
  __CPROVER_assume((sec_r000094_21_1 >= 0) && (sec_r000094_21_1 <= 255));
  __CPROVER_assume((sec_r000094_21_2 >= 0) && (sec_r000094_21_2 <= 255));
  struct Vector3D_R000094_9413_0 st_var_0_1 = {0};
  struct Vector3D_R000094_9413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000094_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000094_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000094_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000094_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000094_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000094_0_2 + 7) & 15;
  struct AudioFrame_R000094_9413_1 st_var_1_1 = {0};
  struct AudioFrame_R000094_9413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000094_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000094_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000094_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000094_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000094_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000094_0_2 + 9) & 15;
  struct EventLog_R000094_9413_2 st_var_2_1 = {0};
  struct EventLog_R000094_9413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000094_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000094_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000094_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000094_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000094_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000094_0_2 + 11) & 15;
  struct DeviceConfig_R000094_9413_3 st_var_3_1 = {0};
  struct DeviceConfig_R000094_9413_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000094_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000094_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000094_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000094_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000094_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000094_0_2 + 13) & 15;
  union TelemetryField_R000094_9413_0 u_var_1;
  union TelemetryField_R000094_9413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 4) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
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
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = (st_var_0_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_0_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  int stage_v_9_1 = table_1[1];
  int stage_v_9_2 = table_2[1];
  table_1[1] = (table_1[2] + 19) & 63;
  table_2[1] = (table_2[2] + 19) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = ((st_var_2_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_2_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 25)
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
  if (stage_v_10_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 25)
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
  int stage_v_11_1 = ((st_var_3_1.buffer[2] * 2) + 40) & 63;
  int stage_v_11_2 = ((st_var_3_2.buffer[2] * 2) + 40) & 63;
  if (stage_v_11_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_11_1) - 5) & 255;
    if (stage_v_11_1 > 31)
    {
      chk_sum_1 ^= stage_v_11_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_11_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_11_2) - 5) & 255;
    if (stage_v_11_2 > 31)
    {
      chk_sum_2 ^= stage_v_11_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_12_1 = (st_var_0_1.buffer[0] ^ 15) & 3;
  int stage_v_12_2 = (st_var_0_2.buffer[0] ^ 15) & 3;
  switch (stage_v_12_1)
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

  switch (stage_v_12_2)
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

  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
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

  switch (stage_v_13_2)
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

  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = ((st_var_3_1.buffer[0] * 2) + 52) & 63;
  int stage_v_15_2 = ((st_var_3_2.buffer[0] * 2) + 52) & 63;
  if (stage_v_15_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_15_1) - 5) & 255;
    if (stage_v_15_1 > 52)
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
  if (stage_v_15_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_15_2) - 5) & 255;
    if (stage_v_15_2 > 52)
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
  int stage_v_17_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (22 & 31);
  int stage_v_17_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (22 & 31);
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= (stage_v_17_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_17_2 << 1) & 127;
  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_19_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 21) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 21) & 15;
  int stage_v_20_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_20_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= stage_v_20_1;
  chk_sum_2 ^= stage_v_20_2;
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
  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 24) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (29 & 31);
  int stage_v_24_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (29 & 31);
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= (stage_v_24_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_24_2 << 1) & 127;
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
  int stage_v_27_1 = ((st_var_3_1.buffer[0] * 2) + 88) & 63;
  int stage_v_27_2 = ((st_var_3_2.buffer[0] * 2) + 88) & 63;
  if (stage_v_27_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_27_1) - 5) & 255;
    if (stage_v_27_1 > 49)
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
  if (stage_v_27_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_27_2) - 5) & 255;
    if (stage_v_27_2 > 49)
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
  int stage_v_31_1 = (st_var_3_1.buffer[0] ^ 34) & 3;
  int stage_v_31_2 = (st_var_3_2.buffer[0] ^ 34) & 3;
  switch (stage_v_31_1)
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

  switch (stage_v_31_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 33) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 33) & 15;
  int stage_v_32_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_32_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= stage_v_32_1;
  chk_sum_2 ^= stage_v_32_2;
  int stage_v_33_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (38 & 31);
  int stage_v_33_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (38 & 31);
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= (stage_v_33_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_33_2 << 1) & 127;
  int stage_v_34_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (39 & 31);
  int stage_v_34_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (39 & 31);
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= (stage_v_34_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_34_2 << 1) & 127;
  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_36_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_36_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 45)
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
  if (stage_v_37_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 45)
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
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 41) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = ((st_var_1_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_1_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 50)
    {
      chk_sum_1 ^= stage_v_41_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_41_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 50)
    {
      chk_sum_2 ^= stage_v_41_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_42_1 = ((st_var_2_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_2_2.buffer[0] * 2) + 133) & 63;
  if (stage_v_42_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 50)
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
  if (stage_v_42_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 50)
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
  int stage_v_43_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (48 & 31);
  int stage_v_43_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (48 & 31);
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= (stage_v_43_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_43_2 << 1) & 127;
  int stage_v_44_1 = ((((sec_r000094_18_1 * 3) + (sec_r000094_18_1 * 2)) - pub_r000094_10_1) + 10) & 127;
  int stage_v_44_2 = ((((sec_r000094_18_2 * 3) + (sec_r000094_18_2 * 2)) - pub_r000094_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_44_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_44_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((((stage_v_44_1 * 3) + (sec_r000094_16_1 * 2)) - pub_r000094_15_1) + 24) & 127;
  int stage_v_45_2 = ((((stage_v_44_2 * 3) + (sec_r000094_16_2 * 2)) - pub_r000094_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_45_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_45_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((((stage_v_44_1 * 3) + (sec_r000094_8_1 * 2)) - pub_r000094_0_1) + 27) & 127;
  int stage_v_46_2 = ((((stage_v_44_2 * 3) + (sec_r000094_8_2 * 2)) - pub_r000094_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_46_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_46_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((((stage_v_44_1 * 3) + (sec_r000094_10_1 * 2)) - pub_r000094_20_1) + 29) & 127;
  int stage_v_47_2 = ((((stage_v_44_2 * 3) + (sec_r000094_10_2 * 2)) - pub_r000094_20_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_47_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_47_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = ((((stage_v_46_1 * 3) + (sec_r000094_2_1 * 2)) - pub_r000094_3_1) + 19) & 127;
  int stage_v_48_2 = ((((stage_v_46_2 * 3) + (sec_r000094_2_2 * 2)) - pub_r000094_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_48_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_48_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((((sec_r000094_21_1 * 3) + (sec_r000094_21_1 * 2)) - pub_r000094_12_1) + 6) & 127;
  int stage_v_49_2 = ((((sec_r000094_21_2 * 3) + (sec_r000094_21_2 * 2)) - pub_r000094_12_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_49_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_49_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = ((((stage_v_47_1 * 3) + (sec_r000094_20_1 * 2)) - pub_r000094_9_1) + 12) & 127;
  int stage_v_50_2 = ((((stage_v_47_2 * 3) + (sec_r000094_20_2 * 2)) - pub_r000094_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_50_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_50_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = ((((stage_v_50_1 * 3) + (sec_r000094_3_1 * 2)) - pub_r000094_18_1) + 20) & 127;
  int stage_v_51_2 = ((((stage_v_50_2 * 3) + (sec_r000094_3_2 * 2)) - pub_r000094_18_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_51_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_51_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((((stage_v_46_1 * 3) + (sec_r000094_1_1 * 2)) - pub_r000094_2_1) + 5) & 127;
  int stage_v_52_2 = ((((stage_v_46_2 * 3) + (sec_r000094_1_2 * 2)) - pub_r000094_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_52_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_52_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((((stage_v_48_1 * 3) + (sec_r000094_6_1 * 2)) - pub_r000094_2_1) + 30) & 127;
  int stage_v_53_2 = ((((stage_v_48_2 * 3) + (sec_r000094_6_2 * 2)) - pub_r000094_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_53_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_53_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((((stage_v_47_1 * 3) + (sec_r000094_4_1 * 2)) - pub_r000094_20_1) + 22) & 127;
  int stage_v_54_2 = ((((stage_v_47_2 * 3) + (sec_r000094_4_2 * 2)) - pub_r000094_20_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_54_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_54_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((((stage_v_48_1 * 3) + (sec_r000094_16_1 * 2)) - pub_r000094_11_1) + 5) & 127;
  int stage_v_55_2 = ((((stage_v_48_2 * 3) + (sec_r000094_16_2 * 2)) - pub_r000094_11_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_55_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_55_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((((stage_v_51_1 * 3) + (sec_r000094_20_1 * 2)) - pub_r000094_10_1) + 6) & 127;
  int stage_v_56_2 = ((((stage_v_51_2 * 3) + (sec_r000094_20_2 * 2)) - pub_r000094_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_56_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_56_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((((stage_v_52_1 * 3) + (sec_r000094_20_1 * 2)) - pub_r000094_10_1) + 22) & 127;
  int stage_v_57_2 = ((((stage_v_52_2 * 3) + (sec_r000094_20_2 * 2)) - pub_r000094_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_57_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_57_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((((stage_v_53_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_0_1) + 6) & 127;
  int stage_v_58_2 = ((((stage_v_53_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_0_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_58_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_58_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((((sec_r000094_15_1 * 3) + (sec_r000094_15_1 * 2)) - pub_r000094_10_1) + 8) & 127;
  int stage_v_59_2 = ((((sec_r000094_15_2 * 3) + (sec_r000094_15_2 * 2)) - pub_r000094_10_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_59_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_59_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((((sec_r000094_13_1 * 3) + (sec_r000094_13_1 * 2)) - pub_r000094_20_1) + 26) & 127;
  int stage_v_60_2 = ((((sec_r000094_13_2 * 3) + (sec_r000094_13_2 * 2)) - pub_r000094_20_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_60_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_60_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((((sec_r000094_8_1 * 3) + (sec_r000094_8_1 * 2)) - pub_r000094_17_1) + 23) & 127;
  int stage_v_61_2 = ((((sec_r000094_8_2 * 3) + (sec_r000094_8_2 * 2)) - pub_r000094_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_61_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_61_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((((stage_v_59_1 * 3) + (sec_r000094_9_1 * 2)) - pub_r000094_18_1) + 37) & 127;
  int stage_v_62_2 = ((((stage_v_59_2 * 3) + (sec_r000094_9_2 * 2)) - pub_r000094_18_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_62_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_62_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((((stage_v_56_1 * 3) + (sec_r000094_19_1 * 2)) - pub_r000094_9_1) + 33) & 127;
  int stage_v_63_2 = ((((stage_v_56_2 * 3) + (sec_r000094_19_2 * 2)) - pub_r000094_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_63_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_63_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((((stage_v_60_1 * 3) + (sec_r000094_15_1 * 2)) - pub_r000094_11_1) + 29) & 127;
  int stage_v_64_2 = ((((stage_v_60_2 * 3) + (sec_r000094_15_2 * 2)) - pub_r000094_11_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_64_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_64_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((((sec_r000094_5_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_8_1) + 18) & 127;
  int stage_v_65_2 = ((((sec_r000094_5_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_8_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_65_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_65_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((((stage_v_45_1 * 3) + (sec_r000094_19_1 * 2)) - pub_r000094_2_1) + 30) & 127;
  int stage_v_66_2 = ((((stage_v_45_2 * 3) + (sec_r000094_19_2 * 2)) - pub_r000094_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_66_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_66_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((((stage_v_50_1 * 3) + (sec_r000094_14_1 * 2)) - pub_r000094_14_1) + 23) & 127;
  int stage_v_67_2 = ((((stage_v_50_2 * 3) + (sec_r000094_14_2 * 2)) - pub_r000094_14_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_67_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_67_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = ((((sec_r000094_13_1 * 3) + (sec_r000094_13_1 * 2)) - pub_r000094_20_1) + 25) & 127;
  int stage_v_68_2 = ((((sec_r000094_13_2 * 3) + (sec_r000094_13_2 * 2)) - pub_r000094_20_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_68_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_68_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = ((((sec_r000094_19_1 * 3) + (sec_r000094_19_1 * 2)) - pub_r000094_16_1) + 8) & 127;
  int stage_v_69_2 = ((((sec_r000094_19_2 * 3) + (sec_r000094_19_2 * 2)) - pub_r000094_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_69_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_69_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((((stage_v_49_1 * 3) + (sec_r000094_3_1 * 2)) - pub_r000094_3_1) + 5) & 127;
  int stage_v_70_2 = ((((stage_v_49_2 * 3) + (sec_r000094_3_2 * 2)) - pub_r000094_3_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_70_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_70_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((((stage_v_51_1 * 3) + (sec_r000094_7_1 * 2)) - pub_r000094_20_1) + 14) & 127;
  int stage_v_71_2 = ((((stage_v_51_2 * 3) + (sec_r000094_7_2 * 2)) - pub_r000094_20_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_71_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_71_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((((stage_v_66_1 * 3) + (sec_r000094_9_1 * 2)) - pub_r000094_17_1) + 21) & 127;
  int stage_v_72_2 = ((((stage_v_66_2 * 3) + (sec_r000094_9_2 * 2)) - pub_r000094_17_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_72_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_72_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = ((((stage_v_55_1 * 3) + (sec_r000094_15_1 * 2)) - pub_r000094_1_1) + 24) & 127;
  int stage_v_73_2 = ((((stage_v_55_2 * 3) + (sec_r000094_15_2 * 2)) - pub_r000094_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_73_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_73_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((((sec_r000094_13_1 * 3) + (sec_r000094_13_1 * 2)) - pub_r000094_1_1) + 17) & 127;
  int stage_v_74_2 = ((((sec_r000094_13_2 * 3) + (sec_r000094_13_2 * 2)) - pub_r000094_1_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_74_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_74_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((((stage_v_69_1 * 3) + (sec_r000094_15_1 * 2)) - pub_r000094_18_1) + 31) & 127;
  int stage_v_75_2 = ((((stage_v_69_2 * 3) + (sec_r000094_15_2 * 2)) - pub_r000094_18_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_75_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_75_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((((stage_v_61_1 * 3) + (sec_r000094_21_1 * 2)) - pub_r000094_21_1) + 7) & 127;
  int stage_v_76_2 = ((((stage_v_61_2 * 3) + (sec_r000094_21_2 * 2)) - pub_r000094_21_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_76_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_76_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((((stage_v_56_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_5_1) + 10) & 127;
  int stage_v_77_2 = ((((stage_v_56_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_5_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_77_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_77_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((((stage_v_74_1 * 3) + (sec_r000094_14_1 * 2)) - pub_r000094_12_1) + 25) & 127;
  int stage_v_78_2 = ((((stage_v_74_2 * 3) + (sec_r000094_14_2 * 2)) - pub_r000094_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_78_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_78_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((((sec_r000094_10_1 * 3) + (sec_r000094_10_1 * 2)) - pub_r000094_10_1) + 36) & 127;
  int stage_v_79_2 = ((((sec_r000094_10_2 * 3) + (sec_r000094_10_2 * 2)) - pub_r000094_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_79_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_79_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((((stage_v_44_1 * 3) + (sec_r000094_11_1 * 2)) - pub_r000094_9_1) + 26) & 127;
  int stage_v_80_2 = ((((stage_v_44_2 * 3) + (sec_r000094_11_2 * 2)) - pub_r000094_9_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_80_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_80_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((((stage_v_69_1 * 3) + (sec_r000094_16_1 * 2)) - pub_r000094_5_1) + 18) & 127;
  int stage_v_81_2 = ((((stage_v_69_2 * 3) + (sec_r000094_16_2 * 2)) - pub_r000094_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_81_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_81_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((((sec_r000094_19_1 * 3) + (sec_r000094_19_1 * 2)) - pub_r000094_10_1) + 7) & 127;
  int stage_v_82_2 = ((((sec_r000094_19_2 * 3) + (sec_r000094_19_2 * 2)) - pub_r000094_10_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_82_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_82_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((((stage_v_57_1 * 3) + (sec_r000094_16_1 * 2)) - pub_r000094_18_1) + 26) & 127;
  int stage_v_83_2 = ((((stage_v_57_2 * 3) + (sec_r000094_16_2 * 2)) - pub_r000094_18_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((((stage_v_58_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_10_1) + 25) & 127;
  int stage_v_84_2 = ((((stage_v_58_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((((stage_v_83_1 * 3) + (sec_r000094_6_1 * 2)) - pub_r000094_10_1) + 17) & 127;
  int stage_v_85_2 = ((((stage_v_83_2 * 3) + (sec_r000094_6_2 * 2)) - pub_r000094_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((((stage_v_78_1 * 3) + (sec_r000094_7_1 * 2)) - pub_r000094_5_1) + 17) & 127;
  int stage_v_86_2 = ((((stage_v_78_2 * 3) + (sec_r000094_7_2 * 2)) - pub_r000094_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_86_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_86_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((((stage_v_61_1 * 3) + (sec_r000094_7_1 * 2)) - pub_r000094_10_1) + 15) & 127;
  int stage_v_87_2 = ((((stage_v_61_2 * 3) + (sec_r000094_7_2 * 2)) - pub_r000094_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((((stage_v_47_1 * 3) + (sec_r000094_21_1 * 2)) - pub_r000094_13_1) + 15) & 127;
  int stage_v_88_2 = ((((stage_v_47_2 * 3) + (sec_r000094_21_2 * 2)) - pub_r000094_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((((stage_v_75_1 * 3) + (sec_r000094_13_1 * 2)) - pub_r000094_18_1) + 5) & 127;
  int stage_v_89_2 = ((((stage_v_75_2 * 3) + (sec_r000094_13_2 * 2)) - pub_r000094_18_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((((stage_v_53_1 * 3) + (sec_r000094_11_1 * 2)) - pub_r000094_8_1) + 22) & 127;
  int stage_v_90_2 = ((((stage_v_53_2 * 3) + (sec_r000094_11_2 * 2)) - pub_r000094_8_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((((sec_r000094_15_1 * 3) + (sec_r000094_15_1 * 2)) - pub_r000094_8_1) + 18) & 127;
  int stage_v_91_2 = ((((sec_r000094_15_2 * 3) + (sec_r000094_15_2 * 2)) - pub_r000094_8_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_91_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_91_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((((sec_r000094_17_1 * 3) + (sec_r000094_17_1 * 2)) - pub_r000094_19_1) + 36) & 127;
  int stage_v_92_2 = ((((sec_r000094_17_2 * 3) + (sec_r000094_17_2 * 2)) - pub_r000094_19_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_92_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_92_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((((stage_v_59_1 * 3) + (sec_r000094_3_1 * 2)) - pub_r000094_2_1) + 6) & 127;
  int stage_v_93_2 = ((((stage_v_59_2 * 3) + (sec_r000094_3_2 * 2)) - pub_r000094_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_93_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_93_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((((sec_r000094_12_1 * 3) + (sec_r000094_12_1 * 2)) - pub_r000094_8_1) + 13) & 127;
  int stage_v_94_2 = ((((sec_r000094_12_2 * 3) + (sec_r000094_12_2 * 2)) - pub_r000094_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_94_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_94_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((((stage_v_69_1 * 3) + (sec_r000094_7_1 * 2)) - pub_r000094_17_1) + 11) & 127;
  int stage_v_95_2 = ((((stage_v_69_2 * 3) + (sec_r000094_7_2 * 2)) - pub_r000094_17_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((((sec_r000094_15_1 * 3) + (sec_r000094_15_1 * 2)) - pub_r000094_0_1) + 21) & 127;
  int stage_v_96_2 = ((((sec_r000094_15_2 * 3) + (sec_r000094_15_2 * 2)) - pub_r000094_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((((stage_v_86_1 * 3) + (sec_r000094_21_1 * 2)) - pub_r000094_8_1) + 5) & 127;
  int stage_v_97_2 = ((((stage_v_86_2 * 3) + (sec_r000094_21_2 * 2)) - pub_r000094_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_97_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_97_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((((stage_v_93_1 * 3) + (sec_r000094_21_1 * 2)) - pub_r000094_6_1) + 7) & 127;
  int stage_v_98_2 = ((((stage_v_93_2 * 3) + (sec_r000094_21_2 * 2)) - pub_r000094_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((((stage_v_67_1 * 3) + (sec_r000094_11_1 * 2)) - pub_r000094_8_1) + 11) & 127;
  int stage_v_99_2 = ((((stage_v_67_2 * 3) + (sec_r000094_11_2 * 2)) - pub_r000094_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_99_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_99_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((((sec_r000094_21_1 * 3) + (sec_r000094_21_1 * 2)) - pub_r000094_12_1) + 29) & 127;
  int stage_v_100_2 = ((((sec_r000094_21_2 * 3) + (sec_r000094_21_2 * 2)) - pub_r000094_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_100_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_100_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((((sec_r000094_5_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_11_1) + 36) & 127;
  int stage_v_101_2 = ((((sec_r000094_5_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_11_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_101_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_101_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((((stage_v_52_1 * 3) + (sec_r000094_12_1 * 2)) - pub_r000094_14_1) + 13) & 127;
  int stage_v_102_2 = ((((stage_v_52_2 * 3) + (sec_r000094_12_2 * 2)) - pub_r000094_14_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((((sec_r000094_3_1 * 3) + (sec_r000094_3_1 * 2)) - pub_r000094_14_1) + 22) & 127;
  int stage_v_103_2 = ((((sec_r000094_3_2 * 3) + (sec_r000094_3_2 * 2)) - pub_r000094_14_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_103_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_103_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((((stage_v_64_1 * 3) + (sec_r000094_11_1 * 2)) - pub_r000094_5_1) + 34) & 127;
  int stage_v_104_2 = ((((stage_v_64_2 * 3) + (sec_r000094_11_2 * 2)) - pub_r000094_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((((stage_v_77_1 * 3) + (sec_r000094_15_1 * 2)) - pub_r000094_20_1) + 24) & 127;
  int stage_v_105_2 = ((((stage_v_77_2 * 3) + (sec_r000094_15_2 * 2)) - pub_r000094_20_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_105_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_105_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((((stage_v_44_1 * 3) + (sec_r000094_21_1 * 2)) - pub_r000094_20_1) + 34) & 127;
  int stage_v_106_2 = ((((stage_v_44_2 * 3) + (sec_r000094_21_2 * 2)) - pub_r000094_20_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((((sec_r000094_15_1 * 3) + (sec_r000094_15_1 * 2)) - pub_r000094_3_1) + 19) & 127;
  int stage_v_107_2 = ((((sec_r000094_15_2 * 3) + (sec_r000094_15_2 * 2)) - pub_r000094_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_107_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_107_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((((stage_v_94_1 * 3) + (sec_r000094_4_1 * 2)) - pub_r000094_14_1) + 3) & 127;
  int stage_v_108_2 = ((((stage_v_94_2 * 3) + (sec_r000094_4_2 * 2)) - pub_r000094_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((((stage_v_48_1 * 3) + (sec_r000094_6_1 * 2)) - pub_r000094_3_1) + 34) & 127;
  int stage_v_109_2 = ((((stage_v_48_2 * 3) + (sec_r000094_6_2 * 2)) - pub_r000094_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((((sec_r000094_8_1 * 3) + (sec_r000094_8_1 * 2)) - pub_r000094_17_1) + 34) & 127;
  int stage_v_110_2 = ((((sec_r000094_8_2 * 3) + (sec_r000094_8_2 * 2)) - pub_r000094_17_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_110_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_110_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((((stage_v_53_1 * 3) + (sec_r000094_1_1 * 2)) - pub_r000094_19_1) + 7) & 127;
  int stage_v_111_2 = ((((stage_v_53_2 * 3) + (sec_r000094_1_2 * 2)) - pub_r000094_19_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((((stage_v_77_1 * 3) + (sec_r000094_7_1 * 2)) - pub_r000094_20_1) + 6) & 127;
  int stage_v_112_2 = ((((stage_v_77_2 * 3) + (sec_r000094_7_2 * 2)) - pub_r000094_20_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((((stage_v_91_1 * 3) + (sec_r000094_14_1 * 2)) - pub_r000094_6_1) + 3) & 127;
  int stage_v_113_2 = ((((stage_v_91_2 * 3) + (sec_r000094_14_2 * 2)) - pub_r000094_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((((stage_v_62_1 * 3) + (sec_r000094_4_1 * 2)) - pub_r000094_5_1) + 29) & 127;
  int stage_v_114_2 = ((((stage_v_62_2 * 3) + (sec_r000094_4_2 * 2)) - pub_r000094_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((((stage_v_82_1 * 3) + (sec_r000094_10_1 * 2)) - pub_r000094_17_1) + 8) & 127;
  int stage_v_115_2 = ((((stage_v_82_2 * 3) + (sec_r000094_10_2 * 2)) - pub_r000094_17_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((((stage_v_44_1 * 3) + (sec_r000094_1_1 * 2)) - pub_r000094_8_1) + 22) & 127;
  int stage_v_116_2 = ((((stage_v_44_2 * 3) + (sec_r000094_1_2 * 2)) - pub_r000094_8_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((((stage_v_57_1 * 3) + (sec_r000094_11_1 * 2)) - pub_r000094_2_1) + 36) & 127;
  int stage_v_117_2 = ((((stage_v_57_2 * 3) + (sec_r000094_11_2 * 2)) - pub_r000094_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((((stage_v_75_1 * 3) + (sec_r000094_18_1 * 2)) - pub_r000094_9_1) + 27) & 127;
  int stage_v_118_2 = ((((stage_v_75_2 * 3) + (sec_r000094_18_2 * 2)) - pub_r000094_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((((sec_r000094_13_1 * 3) + (sec_r000094_13_1 * 2)) - pub_r000094_1_1) + 9) & 127;
  int stage_v_119_2 = ((((sec_r000094_13_2 * 3) + (sec_r000094_13_2 * 2)) - pub_r000094_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((((stage_v_110_1 * 3) + (sec_r000094_16_1 * 2)) - pub_r000094_16_1) + 23) & 127;
  int stage_v_120_2 = ((((stage_v_110_2 * 3) + (sec_r000094_16_2 * 2)) - pub_r000094_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((((stage_v_47_1 * 3) + (sec_r000094_0_1 * 2)) - pub_r000094_17_1) + 7) & 127;
  int stage_v_121_2 = ((((stage_v_47_2 * 3) + (sec_r000094_0_2 * 2)) - pub_r000094_17_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((((sec_r000094_16_1 * 3) + (sec_r000094_16_1 * 2)) - pub_r000094_1_1) + 18) & 127;
  int stage_v_122_2 = ((((sec_r000094_16_2 * 3) + (sec_r000094_16_2 * 2)) - pub_r000094_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((((sec_r000094_14_1 * 3) + (sec_r000094_14_1 * 2)) - pub_r000094_15_1) + 37) & 127;
  int stage_v_123_2 = ((((sec_r000094_14_2 * 3) + (sec_r000094_14_2 * 2)) - pub_r000094_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((((sec_r000094_1_1 * 3) + (sec_r000094_1_1 * 2)) - pub_r000094_5_1) + 13) & 127;
  int stage_v_124_2 = ((((sec_r000094_1_2 * 3) + (sec_r000094_1_2 * 2)) - pub_r000094_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((((sec_r000094_8_1 * 3) + (sec_r000094_8_1 * 2)) - pub_r000094_0_1) + 22) & 127;
  int stage_v_125_2 = ((((sec_r000094_8_2 * 3) + (sec_r000094_8_2 * 2)) - pub_r000094_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((((sec_r000094_8_1 * 3) + (sec_r000094_8_1 * 2)) - pub_r000094_14_1) + 4) & 127;
  int stage_v_126_2 = ((((sec_r000094_8_2 * 3) + (sec_r000094_8_2 * 2)) - pub_r000094_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((((stage_v_55_1 * 3) + (sec_r000094_15_1 * 2)) - pub_r000094_11_1) + 21) & 127;
  int stage_v_127_2 = ((((stage_v_55_2 * 3) + (sec_r000094_15_2 * 2)) - pub_r000094_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((((sec_r000094_1_1 * 3) + (sec_r000094_1_1 * 2)) - pub_r000094_9_1) + 17) & 127;
  int stage_v_128_2 = ((((sec_r000094_1_2 * 3) + (sec_r000094_1_2 * 2)) - pub_r000094_9_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((((stage_v_117_1 * 3) + (sec_r000094_20_1 * 2)) - pub_r000094_9_1) + 9) & 127;
  int stage_v_129_2 = ((((stage_v_117_2 * 3) + (sec_r000094_20_2 * 2)) - pub_r000094_9_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((((stage_v_78_1 * 3) + (sec_r000094_1_1 * 2)) - pub_r000094_6_1) + 36) & 127;
  int stage_v_130_2 = ((((stage_v_78_2 * 3) + (sec_r000094_1_2 * 2)) - pub_r000094_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((((stage_v_89_1 * 3) + (sec_r000094_6_1 * 2)) - pub_r000094_15_1) + 5) & 127;
  int stage_v_131_2 = ((((stage_v_89_2 * 3) + (sec_r000094_6_2 * 2)) - pub_r000094_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_131_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_131_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((((sec_r000094_0_1 * 3) + (sec_r000094_0_1 * 2)) - pub_r000094_7_1) + 23) & 127;
  int stage_v_132_2 = ((((sec_r000094_0_2 * 3) + (sec_r000094_0_2 * 2)) - pub_r000094_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((((stage_v_74_1 * 3) + (sec_r000094_0_1 * 2)) - pub_r000094_16_1) + 22) & 127;
  int stage_v_133_2 = ((((stage_v_74_2 * 3) + (sec_r000094_0_2 * 2)) - pub_r000094_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((((stage_v_110_1 * 3) + (sec_r000094_18_1 * 2)) - pub_r000094_11_1) + 26) & 127;
  int stage_v_134_2 = ((((stage_v_110_2 * 3) + (sec_r000094_18_2 * 2)) - pub_r000094_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_134_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_134_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((((stage_v_98_1 * 3) + (sec_r000094_20_1 * 2)) - pub_r000094_15_1) + 18) & 127;
  int stage_v_135_2 = ((((stage_v_98_2 * 3) + (sec_r000094_20_2 * 2)) - pub_r000094_15_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_135_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_135_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((((stage_v_68_1 * 3) + (sec_r000094_11_1 * 2)) - pub_r000094_11_1) + 27) & 127;
  int stage_v_136_2 = ((((stage_v_68_2 * 3) + (sec_r000094_11_2 * 2)) - pub_r000094_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((((sec_r000094_4_1 * 3) + (sec_r000094_4_1 * 2)) - pub_r000094_14_1) + 12) & 127;
  int stage_v_137_2 = ((((sec_r000094_4_2 * 3) + (sec_r000094_4_2 * 2)) - pub_r000094_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((((stage_v_71_1 * 3) + (sec_r000094_11_1 * 2)) - pub_r000094_10_1) + 15) & 127;
  int stage_v_138_2 = ((((stage_v_71_2 * 3) + (sec_r000094_11_2 * 2)) - pub_r000094_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((((stage_v_89_1 * 3) + (sec_r000094_8_1 * 2)) - pub_r000094_11_1) + 11) & 127;
  int stage_v_139_2 = ((((stage_v_89_2 * 3) + (sec_r000094_8_2 * 2)) - pub_r000094_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((((stage_v_115_1 * 3) + (sec_r000094_2_1 * 2)) - pub_r000094_13_1) + 8) & 127;
  int stage_v_140_2 = ((((stage_v_115_2 * 3) + (sec_r000094_2_2 * 2)) - pub_r000094_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((((sec_r000094_5_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_14_1) + 8) & 127;
  int stage_v_141_2 = ((((sec_r000094_5_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((((stage_v_123_1 * 3) + (sec_r000094_6_1 * 2)) - pub_r000094_12_1) + 18) & 127;
  int stage_v_142_2 = ((((stage_v_123_2 * 3) + (sec_r000094_6_2 * 2)) - pub_r000094_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((((stage_v_69_1 * 3) + (sec_r000094_1_1 * 2)) - pub_r000094_4_1) + 22) & 127;
  int stage_v_143_2 = ((((stage_v_69_2 * 3) + (sec_r000094_1_2 * 2)) - pub_r000094_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((((sec_r000094_5_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_0_1) + 21) & 127;
  int stage_v_144_2 = ((((sec_r000094_5_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((((stage_v_137_1 * 3) + (sec_r000094_20_1 * 2)) - pub_r000094_18_1) + 32) & 127;
  int stage_v_145_2 = ((((stage_v_137_2 * 3) + (sec_r000094_20_2 * 2)) - pub_r000094_18_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((((stage_v_88_1 * 3) + (sec_r000094_7_1 * 2)) - pub_r000094_4_1) + 27) & 127;
  int stage_v_146_2 = ((((stage_v_88_2 * 3) + (sec_r000094_7_2 * 2)) - pub_r000094_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((((sec_r000094_8_1 * 3) + (sec_r000094_8_1 * 2)) - pub_r000094_17_1) + 27) & 127;
  int stage_v_147_2 = ((((sec_r000094_8_2 * 3) + (sec_r000094_8_2 * 2)) - pub_r000094_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((((stage_v_128_1 * 3) + (sec_r000094_6_1 * 2)) - pub_r000094_17_1) + 32) & 127;
  int stage_v_148_2 = ((((stage_v_128_2 * 3) + (sec_r000094_6_2 * 2)) - pub_r000094_17_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((((sec_r000094_21_1 * 3) + (sec_r000094_21_1 * 2)) - pub_r000094_13_1) + 27) & 127;
  int stage_v_149_2 = ((((sec_r000094_21_2 * 3) + (sec_r000094_21_2 * 2)) - pub_r000094_13_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((((sec_r000094_18_1 * 3) + (sec_r000094_18_1 * 2)) - pub_r000094_3_1) + 6) & 127;
  int stage_v_150_2 = ((((sec_r000094_18_2 * 3) + (sec_r000094_18_2 * 2)) - pub_r000094_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((((stage_v_50_1 * 3) + (sec_r000094_10_1 * 2)) - pub_r000094_15_1) + 30) & 127;
  int stage_v_151_2 = ((((stage_v_50_2 * 3) + (sec_r000094_10_2 * 2)) - pub_r000094_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((((stage_v_131_1 * 3) + (sec_r000094_20_1 * 2)) - pub_r000094_19_1) + 15) & 127;
  int stage_v_152_2 = ((((stage_v_131_2 * 3) + (sec_r000094_20_2 * 2)) - pub_r000094_19_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((((stage_v_51_1 * 3) + (sec_r000094_19_1 * 2)) - pub_r000094_0_1) + 7) & 127;
  int stage_v_153_2 = ((((stage_v_51_2 * 3) + (sec_r000094_19_2 * 2)) - pub_r000094_0_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((((sec_r000094_14_1 * 3) + (sec_r000094_14_1 * 2)) - pub_r000094_2_1) + 31) & 127;
  int stage_v_154_2 = ((((sec_r000094_14_2 * 3) + (sec_r000094_14_2 * 2)) - pub_r000094_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((((stage_v_108_1 * 3) + (sec_r000094_0_1 * 2)) - pub_r000094_3_1) + 30) & 127;
  int stage_v_155_2 = ((((stage_v_108_2 * 3) + (sec_r000094_0_2 * 2)) - pub_r000094_3_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((((stage_v_93_1 * 3) + (sec_r000094_9_1 * 2)) - pub_r000094_8_1) + 12) & 127;
  int stage_v_156_2 = ((((stage_v_93_2 * 3) + (sec_r000094_9_2 * 2)) - pub_r000094_8_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_156_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_156_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((((stage_v_45_1 * 3) + (sec_r000094_16_1 * 2)) - pub_r000094_5_1) + 17) & 127;
  int stage_v_157_2 = ((((stage_v_45_2 * 3) + (sec_r000094_16_2 * 2)) - pub_r000094_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((((stage_v_157_1 * 3) + (sec_r000094_4_1 * 2)) - pub_r000094_3_1) + 6) & 127;
  int stage_v_158_2 = ((((stage_v_157_2 * 3) + (sec_r000094_4_2 * 2)) - pub_r000094_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((((stage_v_85_1 * 3) + (sec_r000094_21_1 * 2)) - pub_r000094_5_1) + 3) & 127;
  int stage_v_159_2 = ((((stage_v_85_2 * 3) + (sec_r000094_21_2 * 2)) - pub_r000094_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((((sec_r000094_15_1 * 3) + (sec_r000094_15_1 * 2)) - pub_r000094_5_1) + 10) & 127;
  int stage_v_160_2 = ((((sec_r000094_15_2 * 3) + (sec_r000094_15_2 * 2)) - pub_r000094_5_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_160_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_160_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((((stage_v_125_1 * 3) + (sec_r000094_13_1 * 2)) - pub_r000094_17_1) + 23) & 127;
  int stage_v_161_2 = ((((stage_v_125_2 * 3) + (sec_r000094_13_2 * 2)) - pub_r000094_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((((stage_v_119_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_7_1) + 28) & 127;
  int stage_v_162_2 = ((((stage_v_119_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_7_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((((stage_v_117_1 * 3) + (sec_r000094_6_1 * 2)) - pub_r000094_21_1) + 30) & 127;
  int stage_v_163_2 = ((((stage_v_117_2 * 3) + (sec_r000094_6_2 * 2)) - pub_r000094_21_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((((stage_v_146_1 * 3) + (sec_r000094_18_1 * 2)) - pub_r000094_10_1) + 27) & 127;
  int stage_v_164_2 = ((((stage_v_146_2 * 3) + (sec_r000094_18_2 * 2)) - pub_r000094_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((((stage_v_73_1 * 3) + (sec_r000094_11_1 * 2)) - pub_r000094_5_1) + 20) & 127;
  int stage_v_165_2 = ((((stage_v_73_2 * 3) + (sec_r000094_11_2 * 2)) - pub_r000094_5_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((((sec_r000094_11_1 * 3) + (sec_r000094_11_1 * 2)) - pub_r000094_14_1) + 17) & 127;
  int stage_v_166_2 = ((((sec_r000094_11_2 * 3) + (sec_r000094_11_2 * 2)) - pub_r000094_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((((stage_v_47_1 * 3) + (sec_r000094_19_1 * 2)) - pub_r000094_0_1) + 21) & 127;
  int stage_v_167_2 = ((((stage_v_47_2 * 3) + (sec_r000094_19_2 * 2)) - pub_r000094_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((((stage_v_87_1 * 3) + (sec_r000094_18_1 * 2)) - pub_r000094_9_1) + 17) & 127;
  int stage_v_168_2 = ((((stage_v_87_2 * 3) + (sec_r000094_18_2 * 2)) - pub_r000094_9_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((((stage_v_100_1 * 3) + (sec_r000094_13_1 * 2)) - pub_r000094_0_1) + 4) & 127;
  int stage_v_169_2 = ((((stage_v_100_2 * 3) + (sec_r000094_13_2 * 2)) - pub_r000094_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((((stage_v_108_1 * 3) + (sec_r000094_15_1 * 2)) - pub_r000094_18_1) + 11) & 127;
  int stage_v_170_2 = ((((stage_v_108_2 * 3) + (sec_r000094_15_2 * 2)) - pub_r000094_18_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((((stage_v_125_1 * 3) + (sec_r000094_9_1 * 2)) - pub_r000094_11_1) + 19) & 127;
  int stage_v_171_2 = ((((stage_v_125_2 * 3) + (sec_r000094_9_2 * 2)) - pub_r000094_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((((stage_v_91_1 * 3) + (sec_r000094_7_1 * 2)) - pub_r000094_14_1) + 4) & 127;
  int stage_v_172_2 = ((((stage_v_91_2 * 3) + (sec_r000094_7_2 * 2)) - pub_r000094_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((((stage_v_81_1 * 3) + (sec_r000094_18_1 * 2)) - pub_r000094_10_1) + 24) & 127;
  int stage_v_173_2 = ((((stage_v_81_2 * 3) + (sec_r000094_18_2 * 2)) - pub_r000094_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((((stage_v_61_1 * 3) + (sec_r000094_17_1 * 2)) - pub_r000094_1_1) + 19) & 127;
  int stage_v_174_2 = ((((stage_v_61_2 * 3) + (sec_r000094_17_2 * 2)) - pub_r000094_1_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_174_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_174_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((((stage_v_144_1 * 3) + (sec_r000094_21_1 * 2)) - pub_r000094_17_1) + 5) & 127;
  int stage_v_175_2 = ((((stage_v_144_2 * 3) + (sec_r000094_21_2 * 2)) - pub_r000094_17_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_175_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_175_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((((stage_v_153_1 * 3) + (sec_r000094_9_1 * 2)) - pub_r000094_5_1) + 36) & 127;
  int stage_v_176_2 = ((((stage_v_153_2 * 3) + (sec_r000094_9_2 * 2)) - pub_r000094_5_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_176_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_176_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((((sec_r000094_5_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_3_1) + 21) & 127;
  int stage_v_177_2 = ((((sec_r000094_5_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_177_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_177_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((((stage_v_160_1 * 3) + (sec_r000094_2_1 * 2)) - pub_r000094_2_1) + 8) & 127;
  int stage_v_178_2 = ((((stage_v_160_2 * 3) + (sec_r000094_2_2 * 2)) - pub_r000094_2_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_178_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_178_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((((sec_r000094_8_1 * 3) + (sec_r000094_8_1 * 2)) - pub_r000094_3_1) + 4) & 127;
  int stage_v_179_2 = ((((sec_r000094_8_2 * 3) + (sec_r000094_8_2 * 2)) - pub_r000094_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((((stage_v_140_1 * 3) + (sec_r000094_0_1 * 2)) - pub_r000094_6_1) + 29) & 127;
  int stage_v_180_2 = ((((stage_v_140_2 * 3) + (sec_r000094_0_2 * 2)) - pub_r000094_6_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_180_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_180_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((((stage_v_177_1 * 3) + (sec_r000094_21_1 * 2)) - pub_r000094_21_1) + 30) & 127;
  int stage_v_181_2 = ((((stage_v_177_2 * 3) + (sec_r000094_21_2 * 2)) - pub_r000094_21_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_181_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_181_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((((stage_v_172_1 * 3) + (sec_r000094_4_1 * 2)) - pub_r000094_7_1) + 28) & 127;
  int stage_v_182_2 = ((((stage_v_172_2 * 3) + (sec_r000094_4_2 * 2)) - pub_r000094_7_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_182_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_182_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((((stage_v_180_1 * 3) + (sec_r000094_19_1 * 2)) - pub_r000094_7_1) + 31) & 127;
  int stage_v_183_2 = ((((stage_v_180_2 * 3) + (sec_r000094_19_2 * 2)) - pub_r000094_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((((sec_r000094_8_1 * 3) + (sec_r000094_8_1 * 2)) - pub_r000094_8_1) + 22) & 127;
  int stage_v_184_2 = ((((sec_r000094_8_2 * 3) + (sec_r000094_8_2 * 2)) - pub_r000094_8_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_184_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_184_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((((stage_v_162_1 * 3) + (sec_r000094_12_1 * 2)) - pub_r000094_20_1) + 3) & 127;
  int stage_v_185_2 = ((((stage_v_162_2 * 3) + (sec_r000094_12_2 * 2)) - pub_r000094_20_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_185_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_185_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((((stage_v_139_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_20_1) + 37) & 127;
  int stage_v_186_2 = ((((stage_v_139_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_20_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_186_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_186_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((((stage_v_85_1 * 3) + (sec_r000094_15_1 * 2)) - pub_r000094_3_1) + 16) & 127;
  int stage_v_187_2 = ((((stage_v_85_2 * 3) + (sec_r000094_15_2 * 2)) - pub_r000094_3_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_187_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_187_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((((sec_r000094_3_1 * 3) + (sec_r000094_3_1 * 2)) - pub_r000094_13_1) + 6) & 127;
  int stage_v_188_2 = ((((sec_r000094_3_2 * 3) + (sec_r000094_3_2 * 2)) - pub_r000094_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_188_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_188_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((((sec_r000094_11_1 * 3) + (sec_r000094_11_1 * 2)) - pub_r000094_4_1) + 6) & 127;
  int stage_v_189_2 = ((((sec_r000094_11_2 * 3) + (sec_r000094_11_2 * 2)) - pub_r000094_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_189_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_189_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((((stage_v_138_1 * 3) + (sec_r000094_14_1 * 2)) - pub_r000094_8_1) + 6) & 127;
  int stage_v_190_2 = ((((stage_v_138_2 * 3) + (sec_r000094_14_2 * 2)) - pub_r000094_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_190_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_190_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((((stage_v_116_1 * 3) + (sec_r000094_20_1 * 2)) - pub_r000094_13_1) + 6) & 127;
  int stage_v_191_2 = ((((stage_v_116_2 * 3) + (sec_r000094_20_2 * 2)) - pub_r000094_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((((sec_r000094_2_1 * 3) + (sec_r000094_2_1 * 2)) - pub_r000094_5_1) + 3) & 127;
  int stage_v_192_2 = ((((sec_r000094_2_2 * 3) + (sec_r000094_2_2 * 2)) - pub_r000094_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_192_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_192_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((((sec_r000094_9_1 * 3) + (sec_r000094_9_1 * 2)) - pub_r000094_2_1) + 19) & 127;
  int stage_v_193_2 = ((((sec_r000094_9_2 * 3) + (sec_r000094_9_2 * 2)) - pub_r000094_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_193_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_193_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((((stage_v_136_1 * 3) + (sec_r000094_0_1 * 2)) - pub_r000094_14_1) + 16) & 127;
  int stage_v_194_2 = ((((stage_v_136_2 * 3) + (sec_r000094_0_2 * 2)) - pub_r000094_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_194_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_194_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((((stage_v_71_1 * 3) + (sec_r000094_14_1 * 2)) - pub_r000094_7_1) + 31) & 127;
  int stage_v_195_2 = ((((stage_v_71_2 * 3) + (sec_r000094_14_2 * 2)) - pub_r000094_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_195_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_195_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((((stage_v_148_1 * 3) + (sec_r000094_12_1 * 2)) - pub_r000094_21_1) + 15) & 127;
  int stage_v_196_2 = ((((stage_v_148_2 * 3) + (sec_r000094_12_2 * 2)) - pub_r000094_21_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_196_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_196_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((((stage_v_121_1 * 3) + (sec_r000094_4_1 * 2)) - pub_r000094_13_1) + 6) & 127;
  int stage_v_197_2 = ((((stage_v_121_2 * 3) + (sec_r000094_4_2 * 2)) - pub_r000094_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_197_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_197_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((((stage_v_48_1 * 3) + (sec_r000094_15_1 * 2)) - pub_r000094_18_1) + 19) & 127;
  int stage_v_198_2 = ((((stage_v_48_2 * 3) + (sec_r000094_15_2 * 2)) - pub_r000094_18_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_198_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_198_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((((stage_v_163_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_13_1) + 26) & 127;
  int stage_v_199_2 = ((((stage_v_163_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_199_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_199_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((((sec_r000094_21_1 * 3) + (sec_r000094_21_1 * 2)) - pub_r000094_11_1) + 30) & 127;
  int stage_v_200_2 = ((((sec_r000094_21_2 * 3) + (sec_r000094_21_2 * 2)) - pub_r000094_11_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_200_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_200_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((((sec_r000094_9_1 * 3) + (sec_r000094_9_1 * 2)) - pub_r000094_20_1) + 35) & 127;
  int stage_v_201_2 = ((((sec_r000094_9_2 * 3) + (sec_r000094_9_2 * 2)) - pub_r000094_20_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_201_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_201_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((((stage_v_182_1 * 3) + (sec_r000094_11_1 * 2)) - pub_r000094_0_1) + 33) & 127;
  int stage_v_202_2 = ((((stage_v_182_2 * 3) + (sec_r000094_11_2 * 2)) - pub_r000094_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_202_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_202_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((((stage_v_199_1 * 3) + (sec_r000094_6_1 * 2)) - pub_r000094_14_1) + 6) & 127;
  int stage_v_203_2 = ((((stage_v_199_2 * 3) + (sec_r000094_6_2 * 2)) - pub_r000094_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_203_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_203_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((((stage_v_156_1 * 3) + (sec_r000094_1_1 * 2)) - pub_r000094_8_1) + 26) & 127;
  int stage_v_204_2 = ((((stage_v_156_2 * 3) + (sec_r000094_1_2 * 2)) - pub_r000094_8_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_204_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_204_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((((stage_v_98_1 * 3) + (sec_r000094_18_1 * 2)) - pub_r000094_15_1) + 8) & 127;
  int stage_v_205_2 = ((((stage_v_98_2 * 3) + (sec_r000094_18_2 * 2)) - pub_r000094_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_205_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_205_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((((stage_v_149_1 * 3) + (sec_r000094_12_1 * 2)) - pub_r000094_20_1) + 11) & 127;
  int stage_v_206_2 = ((((stage_v_149_2 * 3) + (sec_r000094_12_2 * 2)) - pub_r000094_20_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_206_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_206_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((((stage_v_59_1 * 3) + (sec_r000094_10_1 * 2)) - pub_r000094_6_1) + 8) & 127;
  int stage_v_207_2 = ((((stage_v_59_2 * 3) + (sec_r000094_10_2 * 2)) - pub_r000094_6_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_207_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_207_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((((stage_v_75_1 * 3) + (sec_r000094_11_1 * 2)) - pub_r000094_14_1) + 32) & 127;
  int stage_v_208_2 = ((((stage_v_75_2 * 3) + (sec_r000094_11_2 * 2)) - pub_r000094_14_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_208_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_208_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((((stage_v_200_1 * 3) + (sec_r000094_12_1 * 2)) - pub_r000094_13_1) + 25) & 127;
  int stage_v_209_2 = ((((stage_v_200_2 * 3) + (sec_r000094_12_2 * 2)) - pub_r000094_13_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_209_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_209_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((((sec_r000094_13_1 * 3) + (sec_r000094_13_1 * 2)) - pub_r000094_8_1) + 21) & 127;
  int stage_v_210_2 = ((((sec_r000094_13_2 * 3) + (sec_r000094_13_2 * 2)) - pub_r000094_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_210_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_210_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((((stage_v_112_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_19_1) + 33) & 127;
  int stage_v_211_2 = ((((stage_v_112_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_19_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_211_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_211_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((((stage_v_117_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_0_1) + 19) & 127;
  int stage_v_212_2 = ((((stage_v_117_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_212_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_212_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((((sec_r000094_0_1 * 3) + (sec_r000094_0_1 * 2)) - pub_r000094_19_1) + 9) & 127;
  int stage_v_213_2 = ((((sec_r000094_0_2 * 3) + (sec_r000094_0_2 * 2)) - pub_r000094_19_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_213_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_213_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((((sec_r000094_15_1 * 3) + (sec_r000094_15_1 * 2)) - pub_r000094_15_1) + 8) & 127;
  int stage_v_214_2 = ((((sec_r000094_15_2 * 3) + (sec_r000094_15_2 * 2)) - pub_r000094_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_214_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_214_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((((sec_r000094_17_1 * 3) + (sec_r000094_17_1 * 2)) - pub_r000094_0_1) + 15) & 127;
  int stage_v_215_2 = ((((sec_r000094_17_2 * 3) + (sec_r000094_17_2 * 2)) - pub_r000094_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_215_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_215_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((((stage_v_184_1 * 3) + (sec_r000094_17_1 * 2)) - pub_r000094_12_1) + 36) & 127;
  int stage_v_216_2 = ((((stage_v_184_2 * 3) + (sec_r000094_17_2 * 2)) - pub_r000094_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_216_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_216_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((((stage_v_162_1 * 3) + (sec_r000094_21_1 * 2)) - pub_r000094_14_1) + 18) & 127;
  int stage_v_217_2 = ((((stage_v_162_2 * 3) + (sec_r000094_21_2 * 2)) - pub_r000094_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_217_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_217_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((((sec_r000094_5_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_9_1) + 30) & 127;
  int stage_v_218_2 = ((((sec_r000094_5_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_9_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_218_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_218_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((((stage_v_122_1 * 3) + (sec_r000094_1_1 * 2)) - pub_r000094_16_1) + 10) & 127;
  int stage_v_219_2 = ((((stage_v_122_2 * 3) + (sec_r000094_1_2 * 2)) - pub_r000094_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_219_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_219_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((((sec_r000094_3_1 * 3) + (sec_r000094_3_1 * 2)) - pub_r000094_15_1) + 16) & 127;
  int stage_v_220_2 = ((((sec_r000094_3_2 * 3) + (sec_r000094_3_2 * 2)) - pub_r000094_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_220_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_220_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((((stage_v_53_1 * 3) + (sec_r000094_19_1 * 2)) - pub_r000094_8_1) + 37) & 127;
  int stage_v_221_2 = ((((stage_v_53_2 * 3) + (sec_r000094_19_2 * 2)) - pub_r000094_8_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_221_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_221_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((((stage_v_152_1 * 3) + (sec_r000094_13_1 * 2)) - pub_r000094_17_1) + 21) & 127;
  int stage_v_222_2 = ((((stage_v_152_2 * 3) + (sec_r000094_13_2 * 2)) - pub_r000094_17_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_222_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_222_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((((stage_v_121_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_0_1) + 31) & 127;
  int stage_v_223_2 = ((((stage_v_121_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_223_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_223_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((((sec_r000094_5_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_10_1) + 20) & 127;
  int stage_v_224_2 = ((((sec_r000094_5_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_224_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_224_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((((sec_r000094_18_1 * 3) + (sec_r000094_18_1 * 2)) - pub_r000094_13_1) + 35) & 127;
  int stage_v_225_2 = ((((sec_r000094_18_2 * 3) + (sec_r000094_18_2 * 2)) - pub_r000094_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_225_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_225_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((((sec_r000094_1_1 * 3) + (sec_r000094_1_1 * 2)) - pub_r000094_6_1) + 14) & 127;
  int stage_v_226_2 = ((((sec_r000094_1_2 * 3) + (sec_r000094_1_2 * 2)) - pub_r000094_6_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_226_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_226_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((((stage_v_65_1 * 3) + (sec_r000094_20_1 * 2)) - pub_r000094_7_1) + 31) & 127;
  int stage_v_227_2 = ((((stage_v_65_2 * 3) + (sec_r000094_20_2 * 2)) - pub_r000094_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_227_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_227_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((((sec_r000094_14_1 * 3) + (sec_r000094_14_1 * 2)) - pub_r000094_4_1) + 4) & 127;
  int stage_v_228_2 = ((((sec_r000094_14_2 * 3) + (sec_r000094_14_2 * 2)) - pub_r000094_4_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_228_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_228_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((((sec_r000094_3_1 * 3) + (sec_r000094_3_1 * 2)) - pub_r000094_9_1) + 36) & 127;
  int stage_v_229_2 = ((((sec_r000094_3_2 * 3) + (sec_r000094_3_2 * 2)) - pub_r000094_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_229_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_229_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((((stage_v_76_1 * 3) + (sec_r000094_16_1 * 2)) - pub_r000094_1_1) + 8) & 127;
  int stage_v_230_2 = ((((stage_v_76_2 * 3) + (sec_r000094_16_2 * 2)) - pub_r000094_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_230_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_230_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((((stage_v_56_1 * 3) + (sec_r000094_10_1 * 2)) - pub_r000094_21_1) + 3) & 127;
  int stage_v_231_2 = ((((stage_v_56_2 * 3) + (sec_r000094_10_2 * 2)) - pub_r000094_21_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_231_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_231_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((((stage_v_101_1 * 3) + (sec_r000094_15_1 * 2)) - pub_r000094_6_1) + 21) & 127;
  int stage_v_232_2 = ((((stage_v_101_2 * 3) + (sec_r000094_15_2 * 2)) - pub_r000094_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_232_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_232_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((((stage_v_194_1 * 3) + (sec_r000094_8_1 * 2)) - pub_r000094_19_1) + 11) & 127;
  int stage_v_233_2 = ((((stage_v_194_2 * 3) + (sec_r000094_8_2 * 2)) - pub_r000094_19_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_233_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_233_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((((stage_v_63_1 * 3) + (sec_r000094_2_1 * 2)) - pub_r000094_18_1) + 24) & 127;
  int stage_v_234_2 = ((((stage_v_63_2 * 3) + (sec_r000094_2_2 * 2)) - pub_r000094_18_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_234_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_234_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((((sec_r000094_1_1 * 3) + (sec_r000094_1_1 * 2)) - pub_r000094_11_1) + 34) & 127;
  int stage_v_235_2 = ((((sec_r000094_1_2 * 3) + (sec_r000094_1_2 * 2)) - pub_r000094_11_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_235_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_235_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((((sec_r000094_4_1 * 3) + (sec_r000094_4_1 * 2)) - pub_r000094_4_1) + 31) & 127;
  int stage_v_236_2 = ((((sec_r000094_4_2 * 3) + (sec_r000094_4_2 * 2)) - pub_r000094_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_236_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_236_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((((stage_v_55_1 * 3) + (sec_r000094_7_1 * 2)) - pub_r000094_1_1) + 25) & 127;
  int stage_v_237_2 = ((((stage_v_55_2 * 3) + (sec_r000094_7_2 * 2)) - pub_r000094_1_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_237_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_237_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((((sec_r000094_0_1 * 3) + (sec_r000094_0_1 * 2)) - pub_r000094_1_1) + 34) & 127;
  int stage_v_238_2 = ((((sec_r000094_0_2 * 3) + (sec_r000094_0_2 * 2)) - pub_r000094_1_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_238_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_238_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((((stage_v_59_1 * 3) + (sec_r000094_12_1 * 2)) - pub_r000094_8_1) + 31) & 127;
  int stage_v_239_2 = ((((stage_v_59_2 * 3) + (sec_r000094_12_2 * 2)) - pub_r000094_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_239_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_239_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((((stage_v_135_1 * 3) + (sec_r000094_8_1 * 2)) - pub_r000094_21_1) + 12) & 127;
  int stage_v_240_2 = ((((stage_v_135_2 * 3) + (sec_r000094_8_2 * 2)) - pub_r000094_21_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_240_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_240_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((((sec_r000094_5_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_5_1) + 9) & 127;
  int stage_v_241_2 = ((((sec_r000094_5_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_5_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_241_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_241_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((((stage_v_151_1 * 3) + (sec_r000094_6_1 * 2)) - pub_r000094_11_1) + 18) & 127;
  int stage_v_242_2 = ((((stage_v_151_2 * 3) + (sec_r000094_6_2 * 2)) - pub_r000094_11_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_242_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_242_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((((stage_v_224_1 * 3) + (sec_r000094_3_1 * 2)) - pub_r000094_2_1) + 27) & 127;
  int stage_v_243_2 = ((((stage_v_224_2 * 3) + (sec_r000094_3_2 * 2)) - pub_r000094_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_243_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_243_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((((stage_v_207_1 * 3) + (sec_r000094_9_1 * 2)) - pub_r000094_21_1) + 26) & 127;
  int stage_v_244_2 = ((((stage_v_207_2 * 3) + (sec_r000094_9_2 * 2)) - pub_r000094_21_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_244_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_244_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((((stage_v_223_1 * 3) + (sec_r000094_11_1 * 2)) - pub_r000094_17_1) + 29) & 127;
  int stage_v_245_2 = ((((stage_v_223_2 * 3) + (sec_r000094_11_2 * 2)) - pub_r000094_17_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_245_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_245_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((((stage_v_234_1 * 3) + (sec_r000094_11_1 * 2)) - pub_r000094_6_1) + 7) & 127;
  int stage_v_246_2 = ((((stage_v_234_2 * 3) + (sec_r000094_11_2 * 2)) - pub_r000094_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_246_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_246_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((((stage_v_228_1 * 3) + (sec_r000094_13_1 * 2)) - pub_r000094_13_1) + 19) & 127;
  int stage_v_247_2 = ((((stage_v_228_2 * 3) + (sec_r000094_13_2 * 2)) - pub_r000094_13_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_247_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_247_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((((stage_v_217_1 * 3) + (sec_r000094_9_1 * 2)) - pub_r000094_20_1) + 20) & 127;
  int stage_v_248_2 = ((((stage_v_217_2 * 3) + (sec_r000094_9_2 * 2)) - pub_r000094_20_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_248_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_248_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((((sec_r000094_19_1 * 3) + (sec_r000094_19_1 * 2)) - pub_r000094_6_1) + 16) & 127;
  int stage_v_249_2 = ((((sec_r000094_19_2 * 3) + (sec_r000094_19_2 * 2)) - pub_r000094_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_249_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_249_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((((stage_v_82_1 * 3) + (sec_r000094_18_1 * 2)) - pub_r000094_13_1) + 8) & 127;
  int stage_v_250_2 = ((((stage_v_82_2 * 3) + (sec_r000094_18_2 * 2)) - pub_r000094_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_250_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_250_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((((sec_r000094_20_1 * 3) + (sec_r000094_20_1 * 2)) - pub_r000094_17_1) + 22) & 127;
  int stage_v_251_2 = ((((sec_r000094_20_2 * 3) + (sec_r000094_20_2 * 2)) - pub_r000094_17_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_251_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_251_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((((stage_v_51_1 * 3) + (sec_r000094_20_1 * 2)) - pub_r000094_4_1) + 27) & 127;
  int stage_v_252_2 = ((((stage_v_51_2 * 3) + (sec_r000094_20_2 * 2)) - pub_r000094_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_252_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_252_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((((stage_v_193_1 * 3) + (sec_r000094_13_1 * 2)) - pub_r000094_11_1) + 21) & 127;
  int stage_v_253_2 = ((((stage_v_193_2 * 3) + (sec_r000094_13_2 * 2)) - pub_r000094_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_253_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_253_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((((stage_v_209_1 * 3) + (sec_r000094_12_1 * 2)) - pub_r000094_4_1) + 21) & 127;
  int stage_v_254_2 = ((((stage_v_209_2 * 3) + (sec_r000094_12_2 * 2)) - pub_r000094_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_254_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_254_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((((sec_r000094_10_1 * 3) + (sec_r000094_10_1 * 2)) - pub_r000094_5_1) + 29) & 127;
  int stage_v_255_2 = ((((sec_r000094_10_2 * 3) + (sec_r000094_10_2 * 2)) - pub_r000094_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_255_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_255_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((((sec_r000094_10_1 * 3) + (sec_r000094_10_1 * 2)) - pub_r000094_15_1) + 7) & 127;
  int stage_v_256_2 = ((((sec_r000094_10_2 * 3) + (sec_r000094_10_2 * 2)) - pub_r000094_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_256_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_256_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((((sec_r000094_8_1 * 3) + (sec_r000094_8_1 * 2)) - pub_r000094_2_1) + 31) & 127;
  int stage_v_257_2 = ((((sec_r000094_8_2 * 3) + (sec_r000094_8_2 * 2)) - pub_r000094_2_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_257_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_257_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((((stage_v_233_1 * 3) + (sec_r000094_3_1 * 2)) - pub_r000094_2_1) + 17) & 127;
  int stage_v_258_2 = ((((stage_v_233_2 * 3) + (sec_r000094_3_2 * 2)) - pub_r000094_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_258_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_258_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((((stage_v_147_1 * 3) + (sec_r000094_8_1 * 2)) - pub_r000094_9_1) + 7) & 127;
  int stage_v_259_2 = ((((stage_v_147_2 * 3) + (sec_r000094_8_2 * 2)) - pub_r000094_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_259_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_259_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((((sec_r000094_21_1 * 3) + (sec_r000094_21_1 * 2)) - pub_r000094_7_1) + 21) & 127;
  int stage_v_260_2 = ((((sec_r000094_21_2 * 3) + (sec_r000094_21_2 * 2)) - pub_r000094_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_260_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_260_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((((stage_v_219_1 * 3) + (sec_r000094_18_1 * 2)) - pub_r000094_6_1) + 27) & 127;
  int stage_v_261_2 = ((((stage_v_219_2 * 3) + (sec_r000094_18_2 * 2)) - pub_r000094_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_261_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_261_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((((stage_v_105_1 * 3) + (sec_r000094_18_1 * 2)) - pub_r000094_6_1) + 34) & 127;
  int stage_v_262_2 = ((((stage_v_105_2 * 3) + (sec_r000094_18_2 * 2)) - pub_r000094_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_262_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_262_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((((sec_r000094_21_1 * 3) + (sec_r000094_21_1 * 2)) - pub_r000094_21_1) + 6) & 127;
  int stage_v_263_2 = ((((sec_r000094_21_2 * 3) + (sec_r000094_21_2 * 2)) - pub_r000094_21_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_263_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_263_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((((stage_v_51_1 * 3) + (sec_r000094_6_1 * 2)) - pub_r000094_9_1) + 34) & 127;
  int stage_v_264_2 = ((((stage_v_51_2 * 3) + (sec_r000094_6_2 * 2)) - pub_r000094_9_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_264_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_264_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((((stage_v_48_1 * 3) + (sec_r000094_4_1 * 2)) - pub_r000094_16_1) + 15) & 127;
  int stage_v_265_2 = ((((stage_v_48_2 * 3) + (sec_r000094_4_2 * 2)) - pub_r000094_16_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_265_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_265_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((((sec_r000094_2_1 * 3) + (sec_r000094_2_1 * 2)) - pub_r000094_16_1) + 11) & 127;
  int stage_v_266_2 = ((((sec_r000094_2_2 * 3) + (sec_r000094_2_2 * 2)) - pub_r000094_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_266_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_266_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((((sec_r000094_8_1 * 3) + (sec_r000094_8_1 * 2)) - pub_r000094_0_1) + 26) & 127;
  int stage_v_267_2 = ((((sec_r000094_8_2 * 3) + (sec_r000094_8_2 * 2)) - pub_r000094_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_267_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_267_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((((stage_v_263_1 * 3) + (sec_r000094_10_1 * 2)) - pub_r000094_5_1) + 21) & 127;
  int stage_v_268_2 = ((((stage_v_263_2 * 3) + (sec_r000094_10_2 * 2)) - pub_r000094_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_268_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_268_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((((sec_r000094_1_1 * 3) + (sec_r000094_1_1 * 2)) - pub_r000094_19_1) + 5) & 127;
  int stage_v_269_2 = ((((sec_r000094_1_2 * 3) + (sec_r000094_1_2 * 2)) - pub_r000094_19_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_269_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_269_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((((stage_v_144_1 * 3) + (sec_r000094_12_1 * 2)) - pub_r000094_17_1) + 24) & 127;
  int stage_v_270_2 = ((((stage_v_144_2 * 3) + (sec_r000094_12_2 * 2)) - pub_r000094_17_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_270_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_270_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((((stage_v_97_1 * 3) + (sec_r000094_20_1 * 2)) - pub_r000094_14_1) + 35) & 127;
  int stage_v_271_2 = ((((stage_v_97_2 * 3) + (sec_r000094_20_2 * 2)) - pub_r000094_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_271_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_271_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((((stage_v_65_1 * 3) + (sec_r000094_12_1 * 2)) - pub_r000094_20_1) + 30) & 127;
  int stage_v_272_2 = ((((stage_v_65_2 * 3) + (sec_r000094_12_2 * 2)) - pub_r000094_20_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_272_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_272_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((((sec_r000094_15_1 * 3) + (sec_r000094_15_1 * 2)) - pub_r000094_16_1) + 26) & 127;
  int stage_v_273_2 = ((((sec_r000094_15_2 * 3) + (sec_r000094_15_2 * 2)) - pub_r000094_16_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_273_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_273_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((((stage_v_241_1 * 3) + (sec_r000094_20_1 * 2)) - pub_r000094_13_1) + 4) & 127;
  int stage_v_274_2 = ((((stage_v_241_2 * 3) + (sec_r000094_20_2 * 2)) - pub_r000094_13_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_274_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_274_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((((stage_v_168_1 * 3) + (sec_r000094_13_1 * 2)) - pub_r000094_5_1) + 32) & 127;
  int stage_v_275_2 = ((((stage_v_168_2 * 3) + (sec_r000094_13_2 * 2)) - pub_r000094_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_275_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_275_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((((sec_r000094_17_1 * 3) + (sec_r000094_17_1 * 2)) - pub_r000094_11_1) + 13) & 127;
  int stage_v_276_2 = ((((sec_r000094_17_2 * 3) + (sec_r000094_17_2 * 2)) - pub_r000094_11_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_276_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_276_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((((stage_v_127_1 * 3) + (sec_r000094_1_1 * 2)) - pub_r000094_17_1) + 20) & 127;
  int stage_v_277_2 = ((((stage_v_127_2 * 3) + (sec_r000094_1_2 * 2)) - pub_r000094_17_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_277_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_277_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((((stage_v_48_1 * 3) + (sec_r000094_20_1 * 2)) - pub_r000094_3_1) + 4) & 127;
  int stage_v_278_2 = ((((stage_v_48_2 * 3) + (sec_r000094_20_2 * 2)) - pub_r000094_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_278_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_278_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((((stage_v_221_1 * 3) + (sec_r000094_21_1 * 2)) - pub_r000094_18_1) + 25) & 127;
  int stage_v_279_2 = ((((stage_v_221_2 * 3) + (sec_r000094_21_2 * 2)) - pub_r000094_18_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_279_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_279_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((((stage_v_85_1 * 3) + (sec_r000094_16_1 * 2)) - pub_r000094_19_1) + 6) & 127;
  int stage_v_280_2 = ((((stage_v_85_2 * 3) + (sec_r000094_16_2 * 2)) - pub_r000094_19_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_280_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_280_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((((stage_v_224_1 * 3) + (sec_r000094_18_1 * 2)) - pub_r000094_14_1) + 17) & 127;
  int stage_v_281_2 = ((((stage_v_224_2 * 3) + (sec_r000094_18_2 * 2)) - pub_r000094_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_281_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_281_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((((sec_r000094_4_1 * 3) + (sec_r000094_4_1 * 2)) - pub_r000094_2_1) + 36) & 127;
  int stage_v_282_2 = ((((sec_r000094_4_2 * 3) + (sec_r000094_4_2 * 2)) - pub_r000094_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_282_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_282_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((((sec_r000094_1_1 * 3) + (sec_r000094_1_1 * 2)) - pub_r000094_10_1) + 13) & 127;
  int stage_v_283_2 = ((((sec_r000094_1_2 * 3) + (sec_r000094_1_2 * 2)) - pub_r000094_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_283_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_283_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((((stage_v_44_1 * 3) + (sec_r000094_1_1 * 2)) - pub_r000094_7_1) + 32) & 127;
  int stage_v_284_2 = ((((stage_v_44_2 * 3) + (sec_r000094_1_2 * 2)) - pub_r000094_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_284_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_284_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((((sec_r000094_12_1 * 3) + (sec_r000094_12_1 * 2)) - pub_r000094_10_1) + 22) & 127;
  int stage_v_285_2 = ((((sec_r000094_12_2 * 3) + (sec_r000094_12_2 * 2)) - pub_r000094_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_285_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_285_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((((stage_v_64_1 * 3) + (sec_r000094_10_1 * 2)) - pub_r000094_11_1) + 26) & 127;
  int stage_v_286_2 = ((((stage_v_64_2 * 3) + (sec_r000094_10_2 * 2)) - pub_r000094_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_286_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_286_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((((sec_r000094_17_1 * 3) + (sec_r000094_17_1 * 2)) - pub_r000094_5_1) + 11) & 127;
  int stage_v_287_2 = ((((sec_r000094_17_2 * 3) + (sec_r000094_17_2 * 2)) - pub_r000094_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_287_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_287_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((((stage_v_165_1 * 3) + (sec_r000094_11_1 * 2)) - pub_r000094_13_1) + 7) & 127;
  int stage_v_288_2 = ((((stage_v_165_2 * 3) + (sec_r000094_11_2 * 2)) - pub_r000094_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_288_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_288_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((((sec_r000094_6_1 * 3) + (sec_r000094_6_1 * 2)) - pub_r000094_19_1) + 10) & 127;
  int stage_v_289_2 = ((((sec_r000094_6_2 * 3) + (sec_r000094_6_2 * 2)) - pub_r000094_19_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_289_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_289_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((((sec_r000094_11_1 * 3) + (sec_r000094_11_1 * 2)) - pub_r000094_10_1) + 21) & 127;
  int stage_v_290_2 = ((((sec_r000094_11_2 * 3) + (sec_r000094_11_2 * 2)) - pub_r000094_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_290_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_290_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((((stage_v_189_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_12_1) + 36) & 127;
  int stage_v_291_2 = ((((stage_v_189_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_291_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_291_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((((stage_v_289_1 * 3) + (sec_r000094_17_1 * 2)) - pub_r000094_6_1) + 33) & 127;
  int stage_v_292_2 = ((((stage_v_289_2 * 3) + (sec_r000094_17_2 * 2)) - pub_r000094_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_292_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_292_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((((sec_r000094_19_1 * 3) + (sec_r000094_19_1 * 2)) - pub_r000094_11_1) + 28) & 127;
  int stage_v_293_2 = ((((sec_r000094_19_2 * 3) + (sec_r000094_19_2 * 2)) - pub_r000094_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_293_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_293_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((((stage_v_92_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_15_1) + 36) & 127;
  int stage_v_294_2 = ((((stage_v_92_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_294_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_294_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((((stage_v_56_1 * 3) + (sec_r000094_12_1 * 2)) - pub_r000094_1_1) + 11) & 127;
  int stage_v_295_2 = ((((stage_v_56_2 * 3) + (sec_r000094_12_2 * 2)) - pub_r000094_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_295_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_295_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((((sec_r000094_14_1 * 3) + (sec_r000094_14_1 * 2)) - pub_r000094_8_1) + 9) & 127;
  int stage_v_296_2 = ((((sec_r000094_14_2 * 3) + (sec_r000094_14_2 * 2)) - pub_r000094_8_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_296_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_296_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((((stage_v_180_1 * 3) + (sec_r000094_13_1 * 2)) - pub_r000094_16_1) + 35) & 127;
  int stage_v_297_2 = ((((stage_v_180_2 * 3) + (sec_r000094_13_2 * 2)) - pub_r000094_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_297_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_297_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int stage_v_298_1 = ((((stage_v_232_1 * 3) + (sec_r000094_3_1 * 2)) - pub_r000094_7_1) + 24) & 127;
  int stage_v_298_2 = ((((stage_v_232_2 * 3) + (sec_r000094_3_2 * 2)) - pub_r000094_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_298_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_298_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int stage_v_299_1 = ((((stage_v_158_1 * 3) + (sec_r000094_7_1 * 2)) - pub_r000094_12_1) + 23) & 127;
  int stage_v_299_2 = ((((stage_v_158_2 * 3) + (sec_r000094_7_2 * 2)) - pub_r000094_12_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_299_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_299_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int stage_v_300_1 = ((((stage_v_235_1 * 3) + (sec_r000094_0_1 * 2)) - pub_r000094_10_1) + 21) & 127;
  int stage_v_300_2 = ((((stage_v_235_2 * 3) + (sec_r000094_0_2 * 2)) - pub_r000094_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_300_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_300_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int stage_v_301_1 = ((((stage_v_242_1 * 3) + (sec_r000094_3_1 * 2)) - pub_r000094_6_1) + 4) & 127;
  int stage_v_301_2 = ((((stage_v_242_2 * 3) + (sec_r000094_3_2 * 2)) - pub_r000094_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_301_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_301_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int stage_v_302_1 = ((((sec_r000094_10_1 * 3) + (sec_r000094_10_1 * 2)) - pub_r000094_12_1) + 14) & 127;
  int stage_v_302_2 = ((((sec_r000094_10_2 * 3) + (sec_r000094_10_2 * 2)) - pub_r000094_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_302_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_302_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int stage_v_303_1 = ((((stage_v_225_1 * 3) + (sec_r000094_15_1 * 2)) - pub_r000094_16_1) + 24) & 127;
  int stage_v_303_2 = ((((stage_v_225_2 * 3) + (sec_r000094_15_2 * 2)) - pub_r000094_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_303_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_303_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int stage_v_304_1 = ((((stage_v_52_1 * 3) + (sec_r000094_14_1 * 2)) - pub_r000094_18_1) + 5) & 127;
  int stage_v_304_2 = ((((stage_v_52_2 * 3) + (sec_r000094_14_2 * 2)) - pub_r000094_18_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_304_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_304_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int stage_v_305_1 = ((((stage_v_70_1 * 3) + (sec_r000094_0_1 * 2)) - pub_r000094_6_1) + 13) & 127;
  int stage_v_305_2 = ((((stage_v_70_2 * 3) + (sec_r000094_0_2 * 2)) - pub_r000094_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_305_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_305_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  int stage_v_306_1 = ((((sec_r000094_4_1 * 3) + (sec_r000094_4_1 * 2)) - pub_r000094_3_1) + 9) & 127;
  int stage_v_306_2 = ((((sec_r000094_4_2 * 3) + (sec_r000094_4_2 * 2)) - pub_r000094_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_306_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_306_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_306_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_306_2) & 255;
  int stage_v_307_1 = ((((stage_v_219_1 * 3) + (sec_r000094_12_1 * 2)) - pub_r000094_20_1) + 34) & 127;
  int stage_v_307_2 = ((((stage_v_219_2 * 3) + (sec_r000094_12_2 * 2)) - pub_r000094_20_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_307_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_307_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_307_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_307_2) & 255;
  int stage_v_308_1 = ((((sec_r000094_8_1 * 3) + (sec_r000094_8_1 * 2)) - pub_r000094_7_1) + 15) & 127;
  int stage_v_308_2 = ((((sec_r000094_8_2 * 3) + (sec_r000094_8_2 * 2)) - pub_r000094_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_308_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_308_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_308_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_308_2) & 255;
  int stage_v_309_1 = ((((stage_v_131_1 * 3) + (sec_r000094_14_1 * 2)) - pub_r000094_14_1) + 37) & 127;
  int stage_v_309_2 = ((((stage_v_131_2 * 3) + (sec_r000094_14_2 * 2)) - pub_r000094_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_309_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_309_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_309_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_309_2) & 255;
  int stage_v_310_1 = ((((stage_v_79_1 * 3) + (sec_r000094_14_1 * 2)) - pub_r000094_17_1) + 35) & 127;
  int stage_v_310_2 = ((((stage_v_79_2 * 3) + (sec_r000094_14_2 * 2)) - pub_r000094_17_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_310_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_310_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_310_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_310_2) & 255;
  int stage_v_311_1 = ((((stage_v_210_1 * 3) + (sec_r000094_16_1 * 2)) - pub_r000094_0_1) + 31) & 127;
  int stage_v_311_2 = ((((stage_v_210_2 * 3) + (sec_r000094_16_2 * 2)) - pub_r000094_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_311_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_311_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_311_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_311_2) & 255;
  int stage_v_312_1 = ((((sec_r000094_20_1 * 3) + (sec_r000094_20_1 * 2)) - pub_r000094_2_1) + 32) & 127;
  int stage_v_312_2 = ((((sec_r000094_20_2 * 3) + (sec_r000094_20_2 * 2)) - pub_r000094_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_312_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_312_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_312_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_312_2) & 255;
  int stage_v_313_1 = ((((sec_r000094_18_1 * 3) + (sec_r000094_18_1 * 2)) - pub_r000094_13_1) + 5) & 127;
  int stage_v_313_2 = ((((sec_r000094_18_2 * 3) + (sec_r000094_18_2 * 2)) - pub_r000094_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_313_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_313_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_313_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_313_2) & 255;
  int stage_v_314_1 = ((((stage_v_185_1 * 3) + (sec_r000094_16_1 * 2)) - pub_r000094_8_1) + 4) & 127;
  int stage_v_314_2 = ((((stage_v_185_2 * 3) + (sec_r000094_16_2 * 2)) - pub_r000094_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_314_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_314_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_314_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_314_2) & 255;
  int stage_v_315_1 = ((((stage_v_193_1 * 3) + (sec_r000094_12_1 * 2)) - pub_r000094_12_1) + 24) & 127;
  int stage_v_315_2 = ((((stage_v_193_2 * 3) + (sec_r000094_12_2 * 2)) - pub_r000094_12_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_315_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_315_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_315_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_315_2) & 255;
  int stage_v_316_1 = ((((stage_v_200_1 * 3) + (sec_r000094_7_1 * 2)) - pub_r000094_10_1) + 14) & 127;
  int stage_v_316_2 = ((((stage_v_200_2 * 3) + (sec_r000094_7_2 * 2)) - pub_r000094_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_316_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_316_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_316_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_316_2) & 255;
  int stage_v_317_1 = ((((sec_r000094_14_1 * 3) + (sec_r000094_14_1 * 2)) - pub_r000094_18_1) + 30) & 127;
  int stage_v_317_2 = ((((sec_r000094_14_2 * 3) + (sec_r000094_14_2 * 2)) - pub_r000094_18_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_317_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_317_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_317_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_317_2) & 255;
  int stage_v_318_1 = ((((sec_r000094_20_1 * 3) + (sec_r000094_20_1 * 2)) - pub_r000094_14_1) + 30) & 127;
  int stage_v_318_2 = ((((sec_r000094_20_2 * 3) + (sec_r000094_20_2 * 2)) - pub_r000094_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_318_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_318_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_318_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_318_2) & 255;
  int stage_v_319_1 = ((((stage_v_63_1 * 3) + (sec_r000094_14_1 * 2)) - pub_r000094_11_1) + 33) & 127;
  int stage_v_319_2 = ((((stage_v_63_2 * 3) + (sec_r000094_14_2 * 2)) - pub_r000094_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_319_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_319_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_319_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_319_2) & 255;
  int stage_v_320_1 = ((((stage_v_103_1 * 3) + (sec_r000094_7_1 * 2)) - pub_r000094_8_1) + 20) & 127;
  int stage_v_320_2 = ((((stage_v_103_2 * 3) + (sec_r000094_7_2 * 2)) - pub_r000094_8_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_320_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_320_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_320_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_320_2) & 255;
  int stage_v_321_1 = ((((stage_v_144_1 * 3) + (sec_r000094_0_1 * 2)) - pub_r000094_3_1) + 17) & 127;
  int stage_v_321_2 = ((((stage_v_144_2 * 3) + (sec_r000094_0_2 * 2)) - pub_r000094_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_321_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_321_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_321_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_321_2) & 255;
  int stage_v_322_1 = ((((stage_v_119_1 * 3) + (sec_r000094_5_1 * 2)) - pub_r000094_4_1) + 28) & 127;
  int stage_v_322_2 = ((((stage_v_119_2 * 3) + (sec_r000094_5_2 * 2)) - pub_r000094_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_322_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_322_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_322_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_322_2) & 255;
  int stage_v_323_1 = ((((stage_v_128_1 * 3) + (sec_r000094_0_1 * 2)) - pub_r000094_0_1) + 26) & 127;
  int stage_v_323_2 = ((((stage_v_128_2 * 3) + (sec_r000094_0_2 * 2)) - pub_r000094_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_323_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_323_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_323_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_323_2) & 255;
  int stage_v_324_1 = ((((stage_v_60_1 * 3) + (sec_r000094_7_1 * 2)) - pub_r000094_3_1) + 36) & 127;
  int stage_v_324_2 = ((((stage_v_60_2 * 3) + (sec_r000094_7_2 * 2)) - pub_r000094_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_324_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_324_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_324_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_324_2) & 255;
  int stage_v_325_1 = ((((stage_v_140_1 * 3) + (sec_r000094_3_1 * 2)) - pub_r000094_14_1) + 32) & 127;
  int stage_v_325_2 = ((((stage_v_140_2 * 3) + (sec_r000094_3_2 * 2)) - pub_r000094_14_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_325_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_325_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_325_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_325_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000094_5_1 != sec_r000094_5_2);
  __CPROVER_assume(pub_r000094_12_1 == pub_r000094_12_2);
  __CPROVER_assume(sec_r000094_1_1 != sec_r000094_1_2);
  __CPROVER_assume(sec_r000094_18_1 != sec_r000094_18_2);
  __CPROVER_assume(pub_r000094_5_1 == pub_r000094_5_2);
  __CPROVER_assume(sec_r000094_21_1 != sec_r000094_21_2);
  __CPROVER_assume(pub_r000094_0_1 == pub_r000094_0_2);
  __CPROVER_assume(pub_r000094_1_1 == pub_r000094_1_2);
  __CPROVER_assume(pub_r000094_10_1 == pub_r000094_10_2);
  __CPROVER_assume(sec_r000094_16_1 != sec_r000094_16_2);
  __CPROVER_assume(pub_r000094_3_1 == pub_r000094_3_2);
  __CPROVER_assume(pub_r000094_13_1 == pub_r000094_13_2);
  __CPROVER_assume(sec_r000094_10_1 != sec_r000094_10_2);
  __CPROVER_assume(sec_r000094_7_1 != sec_r000094_7_2);
  __CPROVER_assume(pub_r000094_14_1 == pub_r000094_14_2);
  __CPROVER_assume(sec_r000094_2_1 != sec_r000094_2_2);
  __CPROVER_assume(sec_r000094_13_1 != sec_r000094_13_2);
  __CPROVER_assume(pub_r000094_4_1 == pub_r000094_4_2);
  __CPROVER_assume(pub_r000094_16_1 == pub_r000094_16_2);
  __CPROVER_assume(sec_r000094_0_1 != sec_r000094_0_2);
  __CPROVER_assume(pub_r000094_20_1 == pub_r000094_20_2);
  __CPROVER_assume(sec_r000094_9_1 != sec_r000094_9_2);
  __CPROVER_assume(sec_r000094_8_1 != sec_r000094_8_2);
  __CPROVER_assume(pub_r000094_19_1 == pub_r000094_19_2);
  __CPROVER_assume(sec_r000094_20_1 != sec_r000094_20_2);
  __CPROVER_assume(pub_r000094_15_1 == pub_r000094_15_2);
  __CPROVER_assume(sec_r000094_17_1 != sec_r000094_17_2);
  __CPROVER_assume(sec_r000094_19_1 != sec_r000094_19_2);
  __CPROVER_assume(sec_r000094_15_1 != sec_r000094_15_2);
  __CPROVER_assume(pub_r000094_6_1 == pub_r000094_6_2);
  __CPROVER_assume(pub_r000094_17_1 == pub_r000094_17_2);
  __CPROVER_assume(pub_r000094_11_1 == pub_r000094_11_2);
  __CPROVER_assume(pub_r000094_18_1 == pub_r000094_18_2);
  __CPROVER_assume(sec_r000094_6_1 != sec_r000094_6_2);
  __CPROVER_assume(sec_r000094_12_1 != sec_r000094_12_2);
  __CPROVER_assume(pub_r000094_21_1 == pub_r000094_21_2);
  __CPROVER_assume(pub_r000094_2_1 == pub_r000094_2_2);
  __CPROVER_assume(pub_r000094_9_1 == pub_r000094_9_2);
  __CPROVER_assume(sec_r000094_3_1 != sec_r000094_3_2);
  __CPROVER_assume(sec_r000094_11_1 != sec_r000094_11_2);
  __CPROVER_assume(sec_r000094_4_1 != sec_r000094_4_2);
  __CPROVER_assume(sec_r000094_14_1 != sec_r000094_14_2);
  __CPROVER_assume(pub_r000094_7_1 == pub_r000094_7_2);
  __CPROVER_assume(pub_r000094_8_1 == pub_r000094_8_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.severity == st_var_2_2.severity);
  assert(st_var_2_1.facility == st_var_2_2.facility);
  assert(st_var_2_1.seq == st_var_2_2.seq);
  assert(st_var_2_1.code == st_var_2_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.timeout == st_var_3_2.timeout);
  assert(st_var_3_1.id == st_var_3_2.id);
  assert(st_var_3_1.baud_rate == st_var_3_2.baud_rate);
  assert(st_var_3_1.parity == st_var_3_2.parity);
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
}


