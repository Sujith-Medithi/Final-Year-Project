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
struct DeviceConfig_R001940_4013_0
{
  unsigned char id;
  short timeout;
  unsigned char port;
  int parity;
  int buffer[3];
};
struct Vector3D_R001940_4013_1
{
  int pitch;
  int coord_y;
  int norm_sq;
  short coord_z;
  int coord_x;
  int buffer[3];
};
struct EventLog_R001940_4013_2
{
  unsigned char seq;
  short severity;
  unsigned char code;
  int timestamp;
  short signature;
  int buffer[3];
};
union ColorPixel_R001940_4013_0
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
void fn_R001940_4013_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001940_4013_0 st_1 = {0};
  struct DeviceConfig_R001940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int margin_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_56_1) & 63;
  aux_2 = (aux_2 + margin_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_55_1 = local_arr_1[aux_1 % 3];
  int sample_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_55_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_56_1 == margin_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_55_1 == sample_55_2);
}

int fn_R001940_4013_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int margin_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_56) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_55 = local_arr[aux % 3];
  acc = (acc + (sample_55 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001940_4013_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001940_4013_0 st_1 = {0};
  struct DeviceConfig_R001940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_51_1)
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

  switch (tracker_51_2)
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
  int tracker_90_1 = local_arr_1[aux_1 % 3];
  int tracker_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_90_2 * 2)) & 127;
  int delta_30_1 = 0;
  int delta_30_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_30_1 = ((delta_30_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_30_2 = ((delta_30_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_30_1) & 127;
    acc_2 = (acc_2 + delta_30_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_51_1 == tracker_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_90_1 == tracker_90_2);
  assert(delta_30_1 == delta_30_2);
}

int fn_R001940_4013_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_51 = (aux + st.buffer[1]) & 3;
  switch (tracker_51)
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
  int tracker_90 = local_arr[aux % 3];
  acc = (acc + (tracker_90 * 2)) & 127;
  int delta_30 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_30 = ((delta_30 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_30) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001940_4013_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001940_4013_2 st_1 = {0};
  struct EventLog_R001940_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_50_1 = local_arr_1[aux_1 % 3];
  int mask_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_50_2 * 2)) & 127;
  int quantum_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_54_1 > 12)
  {
    acc_1 = ((acc_1 + (quantum_54_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_54_2 > 12)
  {
    acc_2 = ((acc_2 + (quantum_54_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_54_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_50_1 == mask_50_2);
  assert(quantum_54_1 == quantum_54_2);
}

int fn_R001940_4013_2(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001940_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int mask_50 = local_arr[aux % 3];
  acc = (acc + (mask_50 * 2)) & 127;
  int quantum_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_54 > 12)
  {
    acc = ((acc + (quantum_54 * 2)) + 5) & 127;
    aux ^= quantum_54 & 15;
  }
  else
  {
    acc = ((acc - quantum_54) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001940_4013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001940_4013_1 st_1 = {0};
  struct Vector3D_R001940_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int delta_64_1 = 0;
  int delta_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_64_1 = ((delta_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_64_2 = ((delta_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_64_1) & 127;
    acc_2 = (acc_2 + delta_64_2) & 127;
  }

  int scale_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_68_1) & 63;
  aux_2 = (aux_2 + scale_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_72_1 = local_arr_1[aux_1 % 3];
  int tally_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_72_2 * 2)) & 127;
  int metric_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_78_1 > 42)
  {
    acc_1 = ((acc_1 + (metric_78_1 * 2)) + 5) & 127;
    aux_1 ^= metric_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_78_2 > 42)
  {
    acc_2 = ((acc_2 + (metric_78_2 * 2)) + 5) & 127;
    aux_2 ^= metric_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_78_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_64_1 == delta_64_2);
  assert(scale_68_1 == scale_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_72_1 == tally_72_2);
  assert(metric_78_1 == metric_78_2);
}

int fn_R001940_4013_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001940_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int delta_64 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_64 = ((delta_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_64) & 127;
  }

  int scale_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_68) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tally_72 = local_arr[aux % 3];
  acc = (acc + (tally_72 * 2)) & 127;
  int metric_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_78 > 42)
  {
    acc = ((acc + (metric_78 * 2)) + 5) & 127;
    aux ^= metric_78 & 15;
  }
  else
  {
    acc = ((acc - metric_78) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001940_4013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001940_4013_1 st_1 = {0};
  struct Vector3D_R001940_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int bound_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_21_1)
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

  switch (bound_21_2)
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

  int checksum_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_45_1) & 63;
  aux_2 = (aux_2 + checksum_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_85_1 > 47)
  {
    acc_1 = ((acc_1 + (vector_85_1 * 2)) + 5) & 127;
    aux_1 ^= vector_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_85_2 > 47)
  {
    acc_2 = ((acc_2 + (vector_85_2 * 2)) + 5) & 127;
    aux_2 ^= vector_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_85_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_21_1 == bound_21_2);
  assert(checksum_45_1 == checksum_45_2);
  assert(vector_85_1 == vector_85_2);
}

int fn_R001940_4013_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001940_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int bound_21 = (aux + st.buffer[1]) & 3;
  switch (bound_21)
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

  int checksum_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_45) & 63;
  acc ^= aux;
  int vector_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_85 > 47)
  {
    acc = ((acc + (vector_85 * 2)) + 5) & 127;
    aux ^= vector_85 & 15;
  }
  else
  {
    acc = ((acc - vector_85) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001940_4013_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001940_4013_2 st_1 = {0};
  struct EventLog_R001940_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int metric_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_30_1)
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

  switch (metric_30_2)
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
  int parity_33_1 = local_arr_1[aux_1 % 3];
  int parity_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_33_2 * 2)) & 127;
  int offset_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_78_1) & 63;
  aux_2 = (aux_2 + offset_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_30_1 == metric_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_33_1 == parity_33_2);
  assert(offset_78_1 == offset_78_2);
}

int fn_R001940_4013_5(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001940_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int metric_30 = (aux + st.buffer[1]) & 3;
  switch (metric_30)
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
  int parity_33 = local_arr[aux % 3];
  acc = (acc + (parity_33 * 2)) & 127;
  int offset_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_78) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001940_4013_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001940_4013_0 st_1 = {0};
  struct DeviceConfig_R001940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int accumulator_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_83_1 > 50)
  {
    acc_1 = ((acc_1 + (accumulator_83_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_83_2 > 50)
  {
    acc_2 = ((acc_2 + (accumulator_83_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_83_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_88_1 = 0;
  int delta_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_88_1 = ((delta_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_88_2 = ((delta_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_88_1) & 127;
    acc_2 = (acc_2 + delta_88_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_83_1 == accumulator_83_2);
  assert(delta_88_1 == delta_88_2);
}

int fn_R001940_4013_6(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int accumulator_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_83 > 50)
  {
    acc = ((acc + (accumulator_83 * 2)) + 5) & 127;
    aux ^= accumulator_83 & 15;
  }
  else
  {
    acc = ((acc - accumulator_83) + 11) & 127;
    aux += 3;
  }
  int delta_88 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_88 = ((delta_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_88) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001940_4013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001940_4013_1 st_1 = {0};
  struct Vector3D_R001940_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int cursor_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_55_1)
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

  switch (cursor_55_2)
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
  int tally_56_1 = 0;
  int tally_56_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_56_1 = ((tally_56_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_56_2 = ((tally_56_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_56_1) & 127;
    acc_2 = (acc_2 + tally_56_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_55_1 == cursor_55_2);
  assert(tally_56_1 == tally_56_2);
}

int fn_R001940_4013_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001940_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int cursor_55 = (aux + st.buffer[1]) & 3;
  switch (cursor_55)
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
  int tally_56 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_56 = ((tally_56 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_56) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001940_4013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001940_4013_2 st_1 = {0};
  struct EventLog_R001940_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int parity_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_10_1) & 63;
  aux_2 = (aux_2 + parity_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_15_1)
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

  switch (window_15_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_10_1 == parity_10_2);
  assert(window_15_1 == window_15_2);
}

int fn_R001940_4013_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001940_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int parity_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_10) & 63;
  acc ^= aux;
  int window_15 = (aux + st.buffer[1]) & 3;
  switch (window_15)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001940_4013_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001940_4013_2 st_1 = {0};
  struct EventLog_R001940_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int pivot_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_34_1) & 63;
  aux_2 = (aux_2 + pivot_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_10_1 = 0;
  int scale_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_10_1 = ((scale_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_10_2 = ((scale_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_10_1) & 127;
    acc_2 = (acc_2 + scale_10_2) & 127;
  }

  int tracker_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_93_1 > 15)
  {
    acc_1 = ((acc_1 + (tracker_93_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_93_2 > 15)
  {
    acc_2 = ((acc_2 + (tracker_93_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_93_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_43_1)
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

  switch (offset_43_2)
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
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_34_1 == pivot_34_2);
  assert(scale_10_1 == scale_10_2);
  assert(tracker_93_1 == tracker_93_2);
  assert(offset_43_1 == offset_43_2);
}

int fn_R001940_4013_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001940_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int pivot_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_34) & 63;
  acc ^= aux;
  int scale_10 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_10 = ((scale_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_10) & 127;
  }

  int tracker_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_93 > 15)
  {
    acc = ((acc + (tracker_93 * 2)) + 5) & 127;
    aux ^= tracker_93 & 15;
  }
  else
  {
    acc = ((acc - tracker_93) + 11) & 127;
    aux += 3;
  }
  int offset_43 = (aux + st.buffer[1]) & 3;
  switch (offset_43)
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

void fn_R001940_4013_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001940_4013_1 st_1 = {0};
  struct Vector3D_R001940_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int quotient_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_73_1) & 63;
  aux_2 = (aux_2 + quotient_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_92_1 = local_arr_1[aux_1 % 3];
  int window_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_92_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_73_1 == quotient_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_92_1 == window_92_2);
}

int fn_R001940_4013_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001940_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int quotient_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_73) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_92 = local_arr[aux % 3];
  acc = (acc + (window_92 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001940_4013_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001940_4013_0 st_1 = {0};
  struct DeviceConfig_R001940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int weight_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_18_1) & 63;
  aux_2 = (aux_2 + weight_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_14_1 = local_arr_1[aux_1 % 3];
  int residue_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_14_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_18_1 == weight_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_14_1 == residue_14_2);
}

int fn_R001940_4013_11(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int weight_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_18) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int residue_14 = local_arr[aux % 3];
  acc = (acc + (residue_14 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001940_4013_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001940_4013_1 st_1 = {0};
  struct Vector3D_R001940_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int damping_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_36_1 > 18)
  {
    acc_1 = ((acc_1 + (damping_36_1 * 2)) + 5) & 127;
    aux_1 ^= damping_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_36_2 > 18)
  {
    acc_2 = ((acc_2 + (damping_36_2 * 2)) + 5) & 127;
    aux_2 ^= damping_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_86_1 = local_arr_1[aux_1 % 3];
  int bound_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_86_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_36_1 == damping_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_86_1 == bound_86_2);
}

int fn_R001940_4013_12(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001940_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int damping_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_36 > 18)
  {
    acc = ((acc + (damping_36 * 2)) + 5) & 127;
    aux ^= damping_36 & 15;
  }
  else
  {
    acc = ((acc - damping_36) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_86 = local_arr[aux % 3];
  acc = (acc + (bound_86 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001940_4013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001940_4013_1 st_1 = {0};
  struct Vector3D_R001940_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_19_1)
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

  switch (pivot_19_2)
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

  int sample_87_1 = 0;
  int sample_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_87_1 = ((sample_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_87_2 = ((sample_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_87_1) & 127;
    acc_2 = (acc_2 + sample_87_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_19_1 == pivot_19_2);
  assert(sample_87_1 == sample_87_2);
}

int fn_R001940_4013_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001940_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_19 = (aux + st.buffer[1]) & 3;
  switch (pivot_19)
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

  int sample_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_87 = ((sample_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_87) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001940_4013_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001940_4013_2 st_1 = {0};
  struct EventLog_R001940_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int accumulator_21_1 = 0;
  int accumulator_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_21_1 = ((accumulator_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_21_2 = ((accumulator_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_21_1) & 127;
    acc_2 = (acc_2 + accumulator_21_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_21_1 == accumulator_21_2);
}

int fn_R001940_4013_14(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001940_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int accumulator_21 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_21 = ((accumulator_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_21) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001940_4013_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001940_4013_0 st_1 = {0};
  struct DeviceConfig_R001940_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int coefficient_92_1 = 0;
  int coefficient_92_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_92_1 = ((coefficient_92_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_92_2 = ((coefficient_92_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_92_1) & 127;
    acc_2 = (acc_2 + coefficient_92_2) & 127;
  }

  int tracker_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_67_1)
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

  switch (tracker_67_2)
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

  int pivot_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_29_1) & 63;
  aux_2 = (aux_2 + pivot_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_60_1 > 36)
  {
    acc_1 = ((acc_1 + (tracker_60_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_60_2 > 36)
  {
    acc_2 = ((acc_2 + (tracker_60_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_60_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_92_1 == coefficient_92_2);
  assert(tracker_67_1 == tracker_67_2);
  assert(pivot_29_1 == pivot_29_2);
  assert(tracker_60_1 == tracker_60_2);
}

int fn_R001940_4013_15(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001940_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int coefficient_92 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_92 = ((coefficient_92 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_92) & 127;
  }

  int tracker_67 = (aux + st.buffer[1]) & 3;
  switch (tracker_67)
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

  int pivot_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_29) & 63;
  acc ^= aux;
  int tracker_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_60 > 36)
  {
    acc = ((acc + (tracker_60 * 2)) + 5) & 127;
    aux ^= tracker_60 & 15;
  }
  else
  {
    acc = ((acc - tracker_60) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001940_0_1;
  int sec_r001940_0_2;
  int sec_r001940_1_1;
  int sec_r001940_1_2;
  int sec_r001940_2_1;
  int sec_r001940_2_2;
  int sec_r001940_3_1;
  int sec_r001940_3_2;
  int sec_r001940_4_1;
  int sec_r001940_4_2;
  int sec_r001940_5_1;
  int sec_r001940_5_2;
  int sec_r001940_6_1;
  int sec_r001940_6_2;
  int sec_r001940_7_1;
  int sec_r001940_7_2;
  int sec_r001940_8_1;
  int sec_r001940_8_2;
  int sec_r001940_9_1;
  int sec_r001940_9_2;
  int sec_r001940_10_1;
  int sec_r001940_10_2;
  int sec_r001940_11_1;
  int sec_r001940_11_2;
  int sec_r001940_12_1;
  int sec_r001940_12_2;
  int sec_r001940_13_1;
  int sec_r001940_13_2;
  int sec_r001940_14_1;
  int sec_r001940_14_2;
  int sec_r001940_15_1;
  int sec_r001940_15_2;
  int sec_r001940_16_1;
  int sec_r001940_16_2;
  int sec_r001940_17_1;
  int sec_r001940_17_2;
  int sec_r001940_18_1;
  int sec_r001940_18_2;
  int sec_r001940_19_1;
  int sec_r001940_19_2;
  int sec_r001940_20_1;
  int sec_r001940_20_2;
  int sec_r001940_21_1;
  int sec_r001940_21_2;
  int sec_r001940_22_1;
  int sec_r001940_22_2;
  int pub_r001940_0_1;
  int pub_r001940_0_2;
  int pub_r001940_1_1;
  int pub_r001940_1_2;
  int pub_r001940_2_1;
  int pub_r001940_2_2;
  int pub_r001940_3_1;
  int pub_r001940_3_2;
  int pub_r001940_4_1;
  int pub_r001940_4_2;
  int pub_r001940_5_1;
  int pub_r001940_5_2;
  int pub_r001940_6_1;
  int pub_r001940_6_2;
  int pub_r001940_7_1;
  int pub_r001940_7_2;
  int pub_r001940_8_1;
  int pub_r001940_8_2;
  int pub_r001940_9_1;
  int pub_r001940_9_2;
  int pub_r001940_10_1;
  int pub_r001940_10_2;
  int pub_r001940_11_1;
  int pub_r001940_11_2;
  int pub_r001940_12_1;
  int pub_r001940_12_2;
  int pub_r001940_13_1;
  int pub_r001940_13_2;
  int pub_r001940_14_1;
  int pub_r001940_14_2;
  int pub_r001940_15_1;
  int pub_r001940_15_2;
  int pub_r001940_16_1;
  int pub_r001940_16_2;
  int pub_r001940_17_1;
  int pub_r001940_17_2;
  int pub_r001940_18_1;
  int pub_r001940_18_2;
  int pub_r001940_19_1;
  int pub_r001940_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001940_0_1 >= (-100)) && (pub_r001940_0_1 <= 100));
  __CPROVER_assume((pub_r001940_0_2 >= (-100)) && (pub_r001940_0_2 <= 100));
  __CPROVER_assume((pub_r001940_1_1 >= (-100)) && (pub_r001940_1_1 <= 100));
  __CPROVER_assume((pub_r001940_1_2 >= (-100)) && (pub_r001940_1_2 <= 100));
  __CPROVER_assume((pub_r001940_2_1 >= (-100)) && (pub_r001940_2_1 <= 100));
  __CPROVER_assume((pub_r001940_2_2 >= (-100)) && (pub_r001940_2_2 <= 100));
  __CPROVER_assume((pub_r001940_3_1 >= (-100)) && (pub_r001940_3_1 <= 100));
  __CPROVER_assume((pub_r001940_3_2 >= (-100)) && (pub_r001940_3_2 <= 100));
  __CPROVER_assume((pub_r001940_4_1 >= (-100)) && (pub_r001940_4_1 <= 100));
  __CPROVER_assume((pub_r001940_4_2 >= (-100)) && (pub_r001940_4_2 <= 100));
  __CPROVER_assume((pub_r001940_5_1 >= (-100)) && (pub_r001940_5_1 <= 100));
  __CPROVER_assume((pub_r001940_5_2 >= (-100)) && (pub_r001940_5_2 <= 100));
  __CPROVER_assume((pub_r001940_6_1 >= (-100)) && (pub_r001940_6_1 <= 100));
  __CPROVER_assume((pub_r001940_6_2 >= (-100)) && (pub_r001940_6_2 <= 100));
  __CPROVER_assume((pub_r001940_7_1 >= (-100)) && (pub_r001940_7_1 <= 100));
  __CPROVER_assume((pub_r001940_7_2 >= (-100)) && (pub_r001940_7_2 <= 100));
  __CPROVER_assume((pub_r001940_8_1 >= (-100)) && (pub_r001940_8_1 <= 100));
  __CPROVER_assume((pub_r001940_8_2 >= (-100)) && (pub_r001940_8_2 <= 100));
  __CPROVER_assume((pub_r001940_9_1 >= (-100)) && (pub_r001940_9_1 <= 100));
  __CPROVER_assume((pub_r001940_9_2 >= (-100)) && (pub_r001940_9_2 <= 100));
  __CPROVER_assume((pub_r001940_10_1 >= (-100)) && (pub_r001940_10_1 <= 100));
  __CPROVER_assume((pub_r001940_10_2 >= (-100)) && (pub_r001940_10_2 <= 100));
  __CPROVER_assume((pub_r001940_11_1 >= (-100)) && (pub_r001940_11_1 <= 100));
  __CPROVER_assume((pub_r001940_11_2 >= (-100)) && (pub_r001940_11_2 <= 100));
  __CPROVER_assume((pub_r001940_12_1 >= (-100)) && (pub_r001940_12_1 <= 100));
  __CPROVER_assume((pub_r001940_12_2 >= (-100)) && (pub_r001940_12_2 <= 100));
  __CPROVER_assume((pub_r001940_13_1 >= (-100)) && (pub_r001940_13_1 <= 100));
  __CPROVER_assume((pub_r001940_13_2 >= (-100)) && (pub_r001940_13_2 <= 100));
  __CPROVER_assume((pub_r001940_14_1 >= (-100)) && (pub_r001940_14_1 <= 100));
  __CPROVER_assume((pub_r001940_14_2 >= (-100)) && (pub_r001940_14_2 <= 100));
  __CPROVER_assume((pub_r001940_15_1 >= (-100)) && (pub_r001940_15_1 <= 100));
  __CPROVER_assume((pub_r001940_15_2 >= (-100)) && (pub_r001940_15_2 <= 100));
  __CPROVER_assume((pub_r001940_16_1 >= (-100)) && (pub_r001940_16_1 <= 100));
  __CPROVER_assume((pub_r001940_16_2 >= (-100)) && (pub_r001940_16_2 <= 100));
  __CPROVER_assume((pub_r001940_17_1 >= (-100)) && (pub_r001940_17_1 <= 100));
  __CPROVER_assume((pub_r001940_17_2 >= (-100)) && (pub_r001940_17_2 <= 100));
  __CPROVER_assume((pub_r001940_18_1 >= (-100)) && (pub_r001940_18_1 <= 100));
  __CPROVER_assume((pub_r001940_18_2 >= (-100)) && (pub_r001940_18_2 <= 100));
  __CPROVER_assume((pub_r001940_19_1 >= (-100)) && (pub_r001940_19_1 <= 100));
  __CPROVER_assume((pub_r001940_19_2 >= (-100)) && (pub_r001940_19_2 <= 100));
  __CPROVER_assume((sec_r001940_0_1 >= 0) && (sec_r001940_0_1 <= 255));
  __CPROVER_assume((sec_r001940_0_2 >= 0) && (sec_r001940_0_2 <= 255));
  __CPROVER_assume((sec_r001940_1_1 >= 0) && (sec_r001940_1_1 <= 255));
  __CPROVER_assume((sec_r001940_1_2 >= 0) && (sec_r001940_1_2 <= 255));
  __CPROVER_assume((sec_r001940_2_1 >= 0) && (sec_r001940_2_1 <= 255));
  __CPROVER_assume((sec_r001940_2_2 >= 0) && (sec_r001940_2_2 <= 255));
  __CPROVER_assume((sec_r001940_3_1 >= 0) && (sec_r001940_3_1 <= 255));
  __CPROVER_assume((sec_r001940_3_2 >= 0) && (sec_r001940_3_2 <= 255));
  __CPROVER_assume((sec_r001940_4_1 >= 0) && (sec_r001940_4_1 <= 255));
  __CPROVER_assume((sec_r001940_4_2 >= 0) && (sec_r001940_4_2 <= 255));
  __CPROVER_assume((sec_r001940_5_1 >= 0) && (sec_r001940_5_1 <= 255));
  __CPROVER_assume((sec_r001940_5_2 >= 0) && (sec_r001940_5_2 <= 255));
  __CPROVER_assume((sec_r001940_6_1 >= 0) && (sec_r001940_6_1 <= 255));
  __CPROVER_assume((sec_r001940_6_2 >= 0) && (sec_r001940_6_2 <= 255));
  __CPROVER_assume((sec_r001940_7_1 >= 0) && (sec_r001940_7_1 <= 255));
  __CPROVER_assume((sec_r001940_7_2 >= 0) && (sec_r001940_7_2 <= 255));
  __CPROVER_assume((sec_r001940_8_1 >= 0) && (sec_r001940_8_1 <= 255));
  __CPROVER_assume((sec_r001940_8_2 >= 0) && (sec_r001940_8_2 <= 255));
  __CPROVER_assume((sec_r001940_9_1 >= 0) && (sec_r001940_9_1 <= 255));
  __CPROVER_assume((sec_r001940_9_2 >= 0) && (sec_r001940_9_2 <= 255));
  __CPROVER_assume((sec_r001940_10_1 >= 0) && (sec_r001940_10_1 <= 255));
  __CPROVER_assume((sec_r001940_10_2 >= 0) && (sec_r001940_10_2 <= 255));
  __CPROVER_assume((sec_r001940_11_1 >= 0) && (sec_r001940_11_1 <= 255));
  __CPROVER_assume((sec_r001940_11_2 >= 0) && (sec_r001940_11_2 <= 255));
  __CPROVER_assume((sec_r001940_12_1 >= 0) && (sec_r001940_12_1 <= 255));
  __CPROVER_assume((sec_r001940_12_2 >= 0) && (sec_r001940_12_2 <= 255));
  __CPROVER_assume((sec_r001940_13_1 >= 0) && (sec_r001940_13_1 <= 255));
  __CPROVER_assume((sec_r001940_13_2 >= 0) && (sec_r001940_13_2 <= 255));
  __CPROVER_assume((sec_r001940_14_1 >= 0) && (sec_r001940_14_1 <= 255));
  __CPROVER_assume((sec_r001940_14_2 >= 0) && (sec_r001940_14_2 <= 255));
  __CPROVER_assume((sec_r001940_15_1 >= 0) && (sec_r001940_15_1 <= 255));
  __CPROVER_assume((sec_r001940_15_2 >= 0) && (sec_r001940_15_2 <= 255));
  __CPROVER_assume((sec_r001940_16_1 >= 0) && (sec_r001940_16_1 <= 255));
  __CPROVER_assume((sec_r001940_16_2 >= 0) && (sec_r001940_16_2 <= 255));
  __CPROVER_assume((sec_r001940_17_1 >= 0) && (sec_r001940_17_1 <= 255));
  __CPROVER_assume((sec_r001940_17_2 >= 0) && (sec_r001940_17_2 <= 255));
  __CPROVER_assume((sec_r001940_18_1 >= 0) && (sec_r001940_18_1 <= 255));
  __CPROVER_assume((sec_r001940_18_2 >= 0) && (sec_r001940_18_2 <= 255));
  __CPROVER_assume((sec_r001940_19_1 >= 0) && (sec_r001940_19_1 <= 255));
  __CPROVER_assume((sec_r001940_19_2 >= 0) && (sec_r001940_19_2 <= 255));
  __CPROVER_assume((sec_r001940_20_1 >= 0) && (sec_r001940_20_1 <= 255));
  __CPROVER_assume((sec_r001940_20_2 >= 0) && (sec_r001940_20_2 <= 255));
  __CPROVER_assume((sec_r001940_21_1 >= 0) && (sec_r001940_21_1 <= 255));
  __CPROVER_assume((sec_r001940_21_2 >= 0) && (sec_r001940_21_2 <= 255));
  __CPROVER_assume((sec_r001940_22_1 >= 0) && (sec_r001940_22_1 <= 255));
  __CPROVER_assume((sec_r001940_22_2 >= 0) && (sec_r001940_22_2 <= 255));
  struct DeviceConfig_R001940_4013_0 st_var_0_1 = {0};
  struct DeviceConfig_R001940_4013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001940_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001940_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001940_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001940_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001940_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001940_0_2 + 7) & 15;
  struct Vector3D_R001940_4013_1 st_var_1_1 = {0};
  struct Vector3D_R001940_4013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001940_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001940_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001940_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001940_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001940_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001940_0_2 + 9) & 15;
  struct EventLog_R001940_4013_2 st_var_2_1 = {0};
  struct EventLog_R001940_4013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001940_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001940_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001940_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001940_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001940_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001940_0_2 + 11) & 15;
  union ColorPixel_R001940_4013_0 u_var_1;
  union ColorPixel_R001940_4013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001940_4013_0(sec_r001940_0_1, pub_r001940_1_1, pub_r001940_2_1, pub_r001940_3_1);
  int helper_flow_0_2 = fn_R001940_4013_0(sec_r001940_0_2, pub_r001940_1_2, pub_r001940_2_2, pub_r001940_3_2);
  fn_R001940_4013_0_2(sec_r001940_0_1, pub_r001940_1_1, pub_r001940_2_1, pub_r001940_3_1, sec_r001940_0_2, pub_r001940_1_2, pub_r001940_2_2, pub_r001940_3_2);
  int helper_flow_1_1 = fn_R001940_4013_1(sec_r001940_1_1, pub_r001940_2_1, pub_r001940_3_1, pub_r001940_4_1);
  int helper_flow_1_2 = fn_R001940_4013_1(sec_r001940_1_2, pub_r001940_2_2, pub_r001940_3_2, pub_r001940_4_2);
  fn_R001940_4013_1_2(sec_r001940_1_1, pub_r001940_2_1, pub_r001940_3_1, pub_r001940_4_1, sec_r001940_1_2, pub_r001940_2_2, pub_r001940_3_2, pub_r001940_4_2);
  int helper_flow_2_1 = fn_R001940_4013_2(sec_r001940_2_1, pub_r001940_3_1, pub_r001940_4_1);
  int helper_flow_2_2 = fn_R001940_4013_2(sec_r001940_2_2, pub_r001940_3_2, pub_r001940_4_2);
  fn_R001940_4013_2_2(sec_r001940_2_1, pub_r001940_3_1, pub_r001940_4_1, sec_r001940_2_2, pub_r001940_3_2, pub_r001940_4_2);
  int helper_flow_3_1 = fn_R001940_4013_3(sec_r001940_3_1, sec_r001940_4_1, pub_r001940_5_1, pub_r001940_6_1, pub_r001940_7_1);
  int helper_flow_3_2 = fn_R001940_4013_3(sec_r001940_3_2, sec_r001940_4_2, pub_r001940_5_2, pub_r001940_6_2, pub_r001940_7_2);
  fn_R001940_4013_3_2(sec_r001940_3_1, sec_r001940_4_1, pub_r001940_5_1, pub_r001940_6_1, pub_r001940_7_1, sec_r001940_3_2, sec_r001940_4_2, pub_r001940_5_2, pub_r001940_6_2, pub_r001940_7_2);
  int helper_flow_4_1 = fn_R001940_4013_4(sec_r001940_4_1, sec_r001940_5_1, pub_r001940_6_1, pub_r001940_7_1, pub_r001940_8_1);
  int helper_flow_4_2 = fn_R001940_4013_4(sec_r001940_4_2, sec_r001940_5_2, pub_r001940_6_2, pub_r001940_7_2, pub_r001940_8_2);
  fn_R001940_4013_4_2(sec_r001940_4_1, sec_r001940_5_1, pub_r001940_6_1, pub_r001940_7_1, pub_r001940_8_1, sec_r001940_4_2, sec_r001940_5_2, pub_r001940_6_2, pub_r001940_7_2, pub_r001940_8_2);
  int helper_flow_5_1 = fn_R001940_4013_5(sec_r001940_5_1, pub_r001940_6_1, pub_r001940_7_1);
  int helper_flow_5_2 = fn_R001940_4013_5(sec_r001940_5_2, pub_r001940_6_2, pub_r001940_7_2);
  fn_R001940_4013_5_2(sec_r001940_5_1, pub_r001940_6_1, pub_r001940_7_1, sec_r001940_5_2, pub_r001940_6_2, pub_r001940_7_2);
  int helper_flow_6_1 = fn_R001940_4013_6(sec_r001940_6_1, pub_r001940_7_1);
  int helper_flow_6_2 = fn_R001940_4013_6(sec_r001940_6_2, pub_r001940_7_2);
  fn_R001940_4013_6_2(sec_r001940_6_1, pub_r001940_7_1, sec_r001940_6_2, pub_r001940_7_2);
  int helper_flow_7_1 = fn_R001940_4013_7(sec_r001940_7_1, sec_r001940_8_1, pub_r001940_9_1, pub_r001940_10_1);
  int helper_flow_7_2 = fn_R001940_4013_7(sec_r001940_7_2, sec_r001940_8_2, pub_r001940_9_2, pub_r001940_10_2);
  fn_R001940_4013_7_2(sec_r001940_7_1, sec_r001940_8_1, pub_r001940_9_1, pub_r001940_10_1, sec_r001940_7_2, sec_r001940_8_2, pub_r001940_9_2, pub_r001940_10_2);
  int helper_flow_8_1 = fn_R001940_4013_8(sec_r001940_8_1, pub_r001940_9_1, pub_r001940_10_1, pub_r001940_11_1, pub_r001940_12_1);
  int helper_flow_8_2 = fn_R001940_4013_8(sec_r001940_8_2, pub_r001940_9_2, pub_r001940_10_2, pub_r001940_11_2, pub_r001940_12_2);
  fn_R001940_4013_8_2(sec_r001940_8_1, pub_r001940_9_1, pub_r001940_10_1, pub_r001940_11_1, pub_r001940_12_1, sec_r001940_8_2, pub_r001940_9_2, pub_r001940_10_2, pub_r001940_11_2, pub_r001940_12_2);
  int helper_flow_9_1 = fn_R001940_4013_9(sec_r001940_9_1, pub_r001940_10_1, pub_r001940_11_1, pub_r001940_12_1, pub_r001940_13_1);
  int helper_flow_9_2 = fn_R001940_4013_9(sec_r001940_9_2, pub_r001940_10_2, pub_r001940_11_2, pub_r001940_12_2, pub_r001940_13_2);
  fn_R001940_4013_9_2(sec_r001940_9_1, pub_r001940_10_1, pub_r001940_11_1, pub_r001940_12_1, pub_r001940_13_1, sec_r001940_9_2, pub_r001940_10_2, pub_r001940_11_2, pub_r001940_12_2, pub_r001940_13_2);
  int helper_flow_10_1 = fn_R001940_4013_10(sec_r001940_10_1, pub_r001940_11_1, pub_r001940_12_1, pub_r001940_13_1);
  int helper_flow_10_2 = fn_R001940_4013_10(sec_r001940_10_2, pub_r001940_11_2, pub_r001940_12_2, pub_r001940_13_2);
  fn_R001940_4013_10_2(sec_r001940_10_1, pub_r001940_11_1, pub_r001940_12_1, pub_r001940_13_1, sec_r001940_10_2, pub_r001940_11_2, pub_r001940_12_2, pub_r001940_13_2);
  int stage_v_0_1 = (((sec_r001940_20_1 ^ 0x2A) * 2) + pub_r001940_9_1) & 127;
  int stage_v_0_2 = (((sec_r001940_20_2 ^ 0x2A) * 2) + pub_r001940_9_2) & 127;
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
  int stage_v_1_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001940_9_1) & 127;
  int stage_v_1_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001940_9_2) & 127;
  if (stage_v_1_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001940_16_1) & 127;
  int stage_v_2_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001940_16_2) & 127;
  if (stage_v_2_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((sec_r001940_15_1 ^ 0x2A) * 2) + pub_r001940_9_1) & 127;
  int stage_v_3_2 = (((sec_r001940_15_2 ^ 0x2A) * 2) + pub_r001940_9_2) & 127;
  if (stage_v_3_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001940_3_1) & 127;
  int stage_v_4_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001940_3_2) & 127;
  if (stage_v_4_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001940_0_1) & 127;
  int stage_v_5_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001940_0_2) & 127;
  if (stage_v_5_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = ((pub_r001940_10_1 * 2) + 46) & 63;
  int stage_v_6_2 = ((pub_r001940_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((sec_r001940_9_1 ^ 0x2A) * 2) + pub_r001940_3_1) & 127;
  int stage_v_7_2 = (((sec_r001940_9_2 ^ 0x2A) * 2) + pub_r001940_3_2) & 127;
  if (stage_v_7_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((sec_r001940_18_1 ^ 0x2A) * 2) + pub_r001940_2_1) & 127;
  int stage_v_8_2 = (((sec_r001940_18_2 ^ 0x2A) * 2) + pub_r001940_2_2) & 127;
  if (stage_v_8_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001940_5_1) & 127;
  int stage_v_9_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001940_5_2) & 127;
  if (stage_v_9_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (((sec_r001940_7_1 ^ 0x2A) * 2) + pub_r001940_8_1) & 127;
  int stage_v_10_2 = (((sec_r001940_7_2 ^ 0x2A) * 2) + pub_r001940_8_2) & 127;
  if (stage_v_10_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = ((pub_r001940_2_1 * 2) + 28) & 63;
  int stage_v_11_2 = ((pub_r001940_2_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (((sec_r001940_1_1 ^ 0x2A) * 2) + pub_r001940_16_1) & 127;
  int stage_v_12_2 = (((sec_r001940_1_2 ^ 0x2A) * 2) + pub_r001940_16_2) & 127;
  if (stage_v_12_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((pub_r001940_0_1 * 2) + 7) & 63;
  int stage_v_13_2 = ((pub_r001940_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001940_12_1 * 2) + 16) & 63;
  int stage_v_14_2 = ((pub_r001940_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (((sec_r001940_19_1 ^ 0x2A) * 2) + pub_r001940_1_1) & 127;
  int stage_v_15_2 = (((sec_r001940_19_2 ^ 0x2A) * 2) + pub_r001940_1_2) & 127;
  if (stage_v_15_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001940_8_1) & 127;
  int stage_v_16_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001940_8_2) & 127;
  if (stage_v_16_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((sec_r001940_19_1 ^ 0x2A) * 2) + pub_r001940_15_1) & 127;
  int stage_v_17_2 = (((sec_r001940_19_2 ^ 0x2A) * 2) + pub_r001940_15_2) & 127;
  if (stage_v_17_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001940_5_1) & 127;
  int stage_v_18_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001940_5_2) & 127;
  if (stage_v_18_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((sec_r001940_17_1 ^ 0x2A) * 2) + pub_r001940_1_1) & 127;
  int stage_v_19_2 = (((sec_r001940_17_2 ^ 0x2A) * 2) + pub_r001940_1_2) & 127;
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
  int stage_v_20_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001940_17_1) & 127;
  int stage_v_20_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001940_17_2) & 127;
  if (stage_v_20_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = ((pub_r001940_16_1 * 2) + 45) & 63;
  int stage_v_21_2 = ((pub_r001940_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = (((sec_r001940_14_1 ^ 0x2A) * 2) + pub_r001940_8_1) & 127;
  int stage_v_22_2 = (((sec_r001940_14_2 ^ 0x2A) * 2) + pub_r001940_8_2) & 127;
  if (stage_v_22_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001940_4_1) & 127;
  int stage_v_23_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001940_4_2) & 127;
  if (stage_v_23_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001940_14_1) & 127;
  int stage_v_24_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001940_14_2) & 127;
  if (stage_v_24_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001940_19_1) & 127;
  int stage_v_25_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001940_19_2) & 127;
  if (stage_v_25_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (((sec_r001940_12_1 ^ 0x2A) * 2) + pub_r001940_16_1) & 127;
  int stage_v_26_2 = (((sec_r001940_12_2 ^ 0x2A) * 2) + pub_r001940_16_2) & 127;
  if (stage_v_26_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (((sec_r001940_19_1 ^ 0x2A) * 2) + pub_r001940_10_1) & 127;
  int stage_v_27_2 = (((sec_r001940_19_2 ^ 0x2A) * 2) + pub_r001940_10_2) & 127;
  if (stage_v_27_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((pub_r001940_15_1 * 2) + 42) & 63;
  int stage_v_28_2 = ((pub_r001940_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001940_15_1 * 2) + 34) & 63;
  int stage_v_29_2 = ((pub_r001940_15_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((sec_r001940_2_1 ^ 0x2A) * 2) + pub_r001940_18_1) & 127;
  int stage_v_30_2 = (((sec_r001940_2_2 ^ 0x2A) * 2) + pub_r001940_18_2) & 127;
  if (stage_v_30_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (((sec_r001940_14_1 ^ 0x2A) * 2) + pub_r001940_12_1) & 127;
  int stage_v_31_2 = (((sec_r001940_14_2 ^ 0x2A) * 2) + pub_r001940_12_2) & 127;
  if (stage_v_31_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001940_5_1) & 127;
  int stage_v_32_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001940_5_2) & 127;
  if (stage_v_32_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((pub_r001940_10_1 * 2) + 15) & 63;
  int stage_v_33_2 = ((pub_r001940_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001940_4_1) & 127;
  int stage_v_34_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001940_4_2) & 127;
  if (stage_v_34_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (((sec_r001940_12_1 ^ 0x2A) * 2) + pub_r001940_9_1) & 127;
  int stage_v_35_2 = (((sec_r001940_12_2 ^ 0x2A) * 2) + pub_r001940_9_2) & 127;
  if (stage_v_35_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (((sec_r001940_17_1 ^ 0x2A) * 2) + pub_r001940_9_1) & 127;
  int stage_v_36_2 = (((sec_r001940_17_2 ^ 0x2A) * 2) + pub_r001940_9_2) & 127;
  if (stage_v_36_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001940_5_1) & 127;
  int stage_v_37_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001940_5_2) & 127;
  if (stage_v_37_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (((sec_r001940_18_1 ^ 0x2A) * 2) + pub_r001940_5_1) & 127;
  int stage_v_38_2 = (((sec_r001940_18_2 ^ 0x2A) * 2) + pub_r001940_5_2) & 127;
  if (stage_v_38_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001940_16_1) & 127;
  int stage_v_39_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001940_16_2) & 127;
  if (stage_v_39_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((pub_r001940_14_1 * 2) + 17) & 63;
  int stage_v_40_2 = ((pub_r001940_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001940_13_1 * 2) + 42) & 63;
  int stage_v_41_2 = ((pub_r001940_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (((sec_r001940_21_1 ^ 0x2A) * 2) + pub_r001940_6_1) & 127;
  int stage_v_42_2 = (((sec_r001940_21_2 ^ 0x2A) * 2) + pub_r001940_6_2) & 127;
  if (stage_v_42_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001940_7_1) & 127;
  int stage_v_43_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001940_7_2) & 127;
  if (stage_v_43_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001940_11_1) & 127;
  int stage_v_44_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001940_11_2) & 127;
  if (stage_v_44_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((pub_r001940_0_1 * 2) + 37) & 63;
  int stage_v_45_2 = ((pub_r001940_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001940_2_1) & 127;
  int stage_v_46_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001940_2_2) & 127;
  if (stage_v_46_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001940_2_1) & 127;
  int stage_v_47_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001940_2_2) & 127;
  if (stage_v_47_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001940_10_1) & 127;
  int stage_v_48_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001940_10_2) & 127;
  if (stage_v_48_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (((sec_r001940_14_1 ^ 0x2A) * 2) + pub_r001940_7_1) & 127;
  int stage_v_49_2 = (((sec_r001940_14_2 ^ 0x2A) * 2) + pub_r001940_7_2) & 127;
  if (stage_v_49_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (((sec_r001940_17_1 ^ 0x2A) * 2) + pub_r001940_0_1) & 127;
  int stage_v_50_2 = (((sec_r001940_17_2 ^ 0x2A) * 2) + pub_r001940_0_2) & 127;
  if (stage_v_50_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (((sec_r001940_6_1 ^ 0x2A) * 2) + pub_r001940_11_1) & 127;
  int stage_v_51_2 = (((sec_r001940_6_2 ^ 0x2A) * 2) + pub_r001940_11_2) & 127;
  if (stage_v_51_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001940_6_1) & 127;
  int stage_v_52_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001940_6_2) & 127;
  if (stage_v_52_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((pub_r001940_17_1 * 2) + 23) & 63;
  int stage_v_53_2 = ((pub_r001940_17_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (((sec_r001940_5_1 ^ 0x2A) * 2) + pub_r001940_1_1) & 127;
  int stage_v_54_2 = (((sec_r001940_5_2 ^ 0x2A) * 2) + pub_r001940_1_2) & 127;
  if (stage_v_54_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001940_11_1) & 127;
  int stage_v_55_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001940_11_2) & 127;
  if (stage_v_55_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001940_1_1) & 127;
  int stage_v_56_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001940_1_2) & 127;
  if (stage_v_56_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((pub_r001940_15_1 * 2) + 43) & 63;
  int stage_v_57_2 = ((pub_r001940_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001940_3_1) & 127;
  int stage_v_58_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001940_3_2) & 127;
  if (stage_v_58_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001940_18_1) & 127;
  int stage_v_59_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001940_18_2) & 127;
  if (stage_v_59_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001940_14_1) & 127;
  int stage_v_60_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001940_14_2) & 127;
  if (stage_v_60_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((pub_r001940_5_1 * 2) + 14) & 63;
  int stage_v_61_2 = ((pub_r001940_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001940_16_1 * 2) + 45) & 63;
  int stage_v_62_2 = ((pub_r001940_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((sec_r001940_11_1 ^ 0x2A) * 2) + pub_r001940_14_1) & 127;
  int stage_v_63_2 = (((sec_r001940_11_2 ^ 0x2A) * 2) + pub_r001940_14_2) & 127;
  if (stage_v_63_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001940_17_1) & 127;
  int stage_v_64_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001940_17_2) & 127;
  if (stage_v_64_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((sec_r001940_3_1 ^ 0x2A) * 2) + pub_r001940_0_1) & 127;
  int stage_v_65_2 = (((sec_r001940_3_2 ^ 0x2A) * 2) + pub_r001940_0_2) & 127;
  if (stage_v_65_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((pub_r001940_15_1 * 2) + 8) & 63;
  int stage_v_66_2 = ((pub_r001940_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (((sec_r001940_9_1 ^ 0x2A) * 2) + pub_r001940_12_1) & 127;
  int stage_v_67_2 = (((sec_r001940_9_2 ^ 0x2A) * 2) + pub_r001940_12_2) & 127;
  if (stage_v_67_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001940_4_1) & 127;
  int stage_v_68_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001940_4_2) & 127;
  if (stage_v_68_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001940_4_1) & 127;
  int stage_v_69_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001940_4_2) & 127;
  if (stage_v_69_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (((sec_r001940_12_1 ^ 0x2A) * 2) + pub_r001940_4_1) & 127;
  int stage_v_70_2 = (((sec_r001940_12_2 ^ 0x2A) * 2) + pub_r001940_4_2) & 127;
  if (stage_v_70_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001940_10_1) & 127;
  int stage_v_71_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001940_10_2) & 127;
  if (stage_v_71_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001940_2_1) & 127;
  int stage_v_72_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001940_2_2) & 127;
  if (stage_v_72_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = (((sec_r001940_3_1 ^ 0x2A) * 2) + pub_r001940_10_1) & 127;
  int stage_v_73_2 = (((sec_r001940_3_2 ^ 0x2A) * 2) + pub_r001940_10_2) & 127;
  if (stage_v_73_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((pub_r001940_14_1 * 2) + 38) & 63;
  int stage_v_74_2 = ((pub_r001940_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001940_12_1) & 127;
  int stage_v_75_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001940_12_2) & 127;
  if (stage_v_75_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (((sec_r001940_22_1 ^ 0x2A) * 2) + pub_r001940_6_1) & 127;
  int stage_v_76_2 = (((sec_r001940_22_2 ^ 0x2A) * 2) + pub_r001940_6_2) & 127;
  if (stage_v_76_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((pub_r001940_0_1 * 2) + 22) & 63;
  int stage_v_77_2 = ((pub_r001940_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = (((sec_r001940_6_1 ^ 0x2A) * 2) + pub_r001940_2_1) & 127;
  int stage_v_78_2 = (((sec_r001940_6_2 ^ 0x2A) * 2) + pub_r001940_2_2) & 127;
  if (stage_v_78_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((sec_r001940_12_1 ^ 0x2A) * 2) + pub_r001940_15_1) & 127;
  int stage_v_79_2 = (((sec_r001940_12_2 ^ 0x2A) * 2) + pub_r001940_15_2) & 127;
  if (stage_v_79_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((pub_r001940_18_1 * 2) + 31) & 63;
  int stage_v_80_2 = ((pub_r001940_18_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001940_6_1) & 127;
  int stage_v_81_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001940_6_2) & 127;
  if (stage_v_81_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001940_8_1) & 127;
  int stage_v_82_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001940_8_2) & 127;
  if (stage_v_82_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001940_15_1) & 127;
  int stage_v_83_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001940_15_2) & 127;
  if (stage_v_83_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((pub_r001940_17_1 * 2) + 39) & 63;
  int stage_v_84_2 = ((pub_r001940_17_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = (((sec_r001940_5_1 ^ 0x2A) * 2) + pub_r001940_3_1) & 127;
  int stage_v_85_2 = (((sec_r001940_5_2 ^ 0x2A) * 2) + pub_r001940_3_2) & 127;
  if (stage_v_85_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = (((sec_r001940_19_1 ^ 0x2A) * 2) + pub_r001940_0_1) & 127;
  int stage_v_86_2 = (((sec_r001940_19_2 ^ 0x2A) * 2) + pub_r001940_0_2) & 127;
  if (stage_v_86_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((pub_r001940_18_1 * 2) + 20) & 63;
  int stage_v_87_2 = ((pub_r001940_18_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001940_12_1) & 127;
  int stage_v_88_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001940_12_2) & 127;
  if (stage_v_88_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((pub_r001940_8_1 * 2) + 36) & 63;
  int stage_v_89_2 = ((pub_r001940_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((sec_r001940_2_1 ^ 0x2A) * 2) + pub_r001940_14_1) & 127;
  int stage_v_90_2 = (((sec_r001940_2_2 ^ 0x2A) * 2) + pub_r001940_14_2) & 127;
  if (stage_v_90_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((pub_r001940_10_1 * 2) + 45) & 63;
  int stage_v_91_2 = ((pub_r001940_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001940_7_1) & 127;
  int stage_v_92_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001940_7_2) & 127;
  if (stage_v_92_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((stage_v_42_1 ^ 0x2A) * 2) + pub_r001940_11_1) & 127;
  int stage_v_93_2 = (((stage_v_42_2 ^ 0x2A) * 2) + pub_r001940_11_2) & 127;
  if (stage_v_93_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((sec_r001940_8_1 ^ 0x2A) * 2) + pub_r001940_12_1) & 127;
  int stage_v_94_2 = (((sec_r001940_8_2 ^ 0x2A) * 2) + pub_r001940_12_2) & 127;
  if (stage_v_94_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = (((stage_v_76_1 ^ 0x2A) * 2) + pub_r001940_10_1) & 127;
  int stage_v_95_2 = (((stage_v_76_2 ^ 0x2A) * 2) + pub_r001940_10_2) & 127;
  if (stage_v_95_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((pub_r001940_2_1 * 2) + 37) & 63;
  int stage_v_96_2 = ((pub_r001940_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001940_6_1) & 127;
  int stage_v_97_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001940_6_2) & 127;
  if (stage_v_97_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (((stage_v_68_1 ^ 0x2A) * 2) + pub_r001940_4_1) & 127;
  int stage_v_98_2 = (((stage_v_68_2 ^ 0x2A) * 2) + pub_r001940_4_2) & 127;
  if (stage_v_98_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((pub_r001940_12_1 * 2) + 10) & 63;
  int stage_v_99_2 = ((pub_r001940_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001940_6_1 * 2) + 19) & 63;
  int stage_v_100_2 = ((pub_r001940_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001940_1_1) & 127;
  int stage_v_101_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001940_1_2) & 127;
  if (stage_v_101_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001940_10_1) & 127;
  int stage_v_102_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001940_10_2) & 127;
  if (stage_v_102_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001940_18_1) & 127;
  int stage_v_103_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001940_18_2) & 127;
  if (stage_v_103_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((stage_v_101_1 ^ 0x2A) * 2) + pub_r001940_16_1) & 127;
  int stage_v_104_2 = (((stage_v_101_2 ^ 0x2A) * 2) + pub_r001940_16_2) & 127;
  if (stage_v_104_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((pub_r001940_6_1 * 2) + 15) & 63;
  int stage_v_105_2 = ((pub_r001940_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001940_16_1 * 2) + 33) & 63;
  int stage_v_106_2 = ((pub_r001940_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001940_17_1 * 2) + 37) & 63;
  int stage_v_107_2 = ((pub_r001940_17_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001940_18_1 * 2) + 22) & 63;
  int stage_v_108_2 = ((pub_r001940_18_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (((stage_v_42_1 ^ 0x2A) * 2) + pub_r001940_4_1) & 127;
  int stage_v_109_2 = (((stage_v_42_2 ^ 0x2A) * 2) + pub_r001940_4_2) & 127;
  if (stage_v_109_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((pub_r001940_9_1 * 2) + 45) & 63;
  int stage_v_110_2 = ((pub_r001940_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (((stage_v_104_1 ^ 0x2A) * 2) + pub_r001940_16_1) & 127;
  int stage_v_111_2 = (((stage_v_104_2 ^ 0x2A) * 2) + pub_r001940_16_2) & 127;
  if (stage_v_111_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = (((stage_v_72_1 ^ 0x2A) * 2) + pub_r001940_19_1) & 127;
  int stage_v_112_2 = (((stage_v_72_2 ^ 0x2A) * 2) + pub_r001940_19_2) & 127;
  if (stage_v_112_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001940_4_1) & 127;
  int stage_v_113_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001940_4_2) & 127;
  if (stage_v_113_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (((stage_v_111_1 ^ 0x2A) * 2) + pub_r001940_8_1) & 127;
  int stage_v_114_2 = (((stage_v_111_2 ^ 0x2A) * 2) + pub_r001940_8_2) & 127;
  if (stage_v_114_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = (((sec_r001940_20_1 ^ 0x2A) * 2) + pub_r001940_4_1) & 127;
  int stage_v_115_2 = (((sec_r001940_20_2 ^ 0x2A) * 2) + pub_r001940_4_2) & 127;
  if (stage_v_115_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001940_6_1) & 127;
  int stage_v_116_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001940_6_2) & 127;
  if (stage_v_116_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((pub_r001940_14_1 * 2) + 44) & 63;
  int stage_v_117_2 = ((pub_r001940_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((stage_v_79_1 ^ 0x2A) * 2) + pub_r001940_4_1) & 127;
  int stage_v_118_2 = (((stage_v_79_2 ^ 0x2A) * 2) + pub_r001940_4_2) & 127;
  if (stage_v_118_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((pub_r001940_2_1 * 2) + 35) & 63;
  int stage_v_119_2 = ((pub_r001940_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001940_18_1 * 2) + 7) & 63;
  int stage_v_120_2 = ((pub_r001940_18_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = (((stage_v_109_1 ^ 0x2A) * 2) + pub_r001940_11_1) & 127;
  int stage_v_121_2 = (((stage_v_109_2 ^ 0x2A) * 2) + pub_r001940_11_2) & 127;
  if (stage_v_121_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (((stage_v_116_1 ^ 0x2A) * 2) + pub_r001940_18_1) & 127;
  int stage_v_122_2 = (((stage_v_116_2 ^ 0x2A) * 2) + pub_r001940_18_2) & 127;
  if (stage_v_122_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001940_1_1) & 127;
  int stage_v_123_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001940_1_2) & 127;
  if (stage_v_123_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001940_1_1) & 127;
  int stage_v_124_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001940_1_2) & 127;
  if (stage_v_124_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((pub_r001940_3_1 * 2) + 20) & 63;
  int stage_v_125_2 = ((pub_r001940_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((sec_r001940_7_1 ^ 0x2A) * 2) + pub_r001940_3_1) & 127;
  int stage_v_126_2 = (((sec_r001940_7_2 ^ 0x2A) * 2) + pub_r001940_3_2) & 127;
  if (stage_v_126_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001940_6_1) & 127;
  int stage_v_127_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001940_6_2) & 127;
  if (stage_v_127_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((stage_v_86_1 ^ 0x2A) * 2) + pub_r001940_12_1) & 127;
  int stage_v_128_2 = (((stage_v_86_2 ^ 0x2A) * 2) + pub_r001940_12_2) & 127;
  if (stage_v_128_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001940_9_1) & 127;
  int stage_v_129_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001940_9_2) & 127;
  if (stage_v_129_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((stage_v_69_1 ^ 0x2A) * 2) + pub_r001940_6_1) & 127;
  int stage_v_130_2 = (((stage_v_69_2 ^ 0x2A) * 2) + pub_r001940_6_2) & 127;
  if (stage_v_130_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = (((sec_r001940_5_1 ^ 0x2A) * 2) + pub_r001940_14_1) & 127;
  int stage_v_131_2 = (((sec_r001940_5_2 ^ 0x2A) * 2) + pub_r001940_14_2) & 127;
  if (stage_v_131_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001940_13_1) & 127;
  int stage_v_132_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001940_13_2) & 127;
  if (stage_v_132_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001940_4_1) & 127;
  int stage_v_133_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001940_4_2) & 127;
  if (stage_v_133_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001940_9_1) & 127;
  int stage_v_134_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001940_9_2) & 127;
  if (stage_v_134_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((pub_r001940_6_1 * 2) + 13) & 63;
  int stage_v_135_2 = ((pub_r001940_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((stage_v_101_1 ^ 0x2A) * 2) + pub_r001940_9_1) & 127;
  int stage_v_136_2 = (((stage_v_101_2 ^ 0x2A) * 2) + pub_r001940_9_2) & 127;
  if (stage_v_136_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((pub_r001940_1_1 * 2) + 22) & 63;
  int stage_v_137_2 = ((pub_r001940_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((stage_v_132_1 ^ 0x2A) * 2) + pub_r001940_12_1) & 127;
  int stage_v_138_2 = (((stage_v_132_2 ^ 0x2A) * 2) + pub_r001940_12_2) & 127;
  if (stage_v_138_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (((stage_v_126_1 ^ 0x2A) * 2) + pub_r001940_6_1) & 127;
  int stage_v_139_2 = (((stage_v_126_2 ^ 0x2A) * 2) + pub_r001940_6_2) & 127;
  if (stage_v_139_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((stage_v_134_1 ^ 0x2A) * 2) + pub_r001940_7_1) & 127;
  int stage_v_140_2 = (((stage_v_134_2 ^ 0x2A) * 2) + pub_r001940_7_2) & 127;
  if (stage_v_140_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((pub_r001940_13_1 * 2) + 46) & 63;
  int stage_v_141_2 = ((pub_r001940_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (((stage_v_114_1 ^ 0x2A) * 2) + pub_r001940_3_1) & 127;
  int stage_v_142_2 = (((stage_v_114_2 ^ 0x2A) * 2) + pub_r001940_3_2) & 127;
  if (stage_v_142_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((stage_v_111_1 ^ 0x2A) * 2) + pub_r001940_3_1) & 127;
  int stage_v_143_2 = (((stage_v_111_2 ^ 0x2A) * 2) + pub_r001940_3_2) & 127;
  if (stage_v_143_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001940_12_1) & 127;
  int stage_v_144_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001940_12_2) & 127;
  if (stage_v_144_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001940_1_1) & 127;
  int stage_v_145_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001940_1_2) & 127;
  if (stage_v_145_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001940_11_1) & 127;
  int stage_v_146_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001940_11_2) & 127;
  if (stage_v_146_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001940_12_1) & 127;
  int stage_v_147_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001940_12_2) & 127;
  if (stage_v_147_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001940_8_1) & 127;
  int stage_v_148_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001940_8_2) & 127;
  if (stage_v_148_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001940_19_1) & 127;
  int stage_v_149_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001940_19_2) & 127;
  if (stage_v_149_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (((stage_v_72_1 ^ 0x2A) * 2) + pub_r001940_10_1) & 127;
  int stage_v_150_2 = (((stage_v_72_2 ^ 0x2A) * 2) + pub_r001940_10_2) & 127;
  if (stage_v_150_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = (((stage_v_90_1 ^ 0x2A) * 2) + pub_r001940_10_1) & 127;
  int stage_v_151_2 = (((stage_v_90_2 ^ 0x2A) * 2) + pub_r001940_10_2) & 127;
  if (stage_v_151_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((pub_r001940_18_1 * 2) + 12) & 63;
  int stage_v_152_2 = ((pub_r001940_18_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001940_7_1 * 2) + 23) & 63;
  int stage_v_153_2 = ((pub_r001940_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((sec_r001940_18_1 ^ 0x2A) * 2) + pub_r001940_18_1) & 127;
  int stage_v_154_2 = (((sec_r001940_18_2 ^ 0x2A) * 2) + pub_r001940_18_2) & 127;
  if (stage_v_154_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (((stage_v_127_1 ^ 0x2A) * 2) + pub_r001940_10_1) & 127;
  int stage_v_155_2 = (((stage_v_127_2 ^ 0x2A) * 2) + pub_r001940_10_2) & 127;
  if (stage_v_155_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((stage_v_144_1 ^ 0x2A) * 2) + pub_r001940_2_1) & 127;
  int stage_v_156_2 = (((stage_v_144_2 ^ 0x2A) * 2) + pub_r001940_2_2) & 127;
  if (stage_v_156_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001940_18_1) & 127;
  int stage_v_157_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001940_18_2) & 127;
  if (stage_v_157_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((pub_r001940_8_1 * 2) + 11) & 63;
  int stage_v_158_2 = ((pub_r001940_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (((stage_v_50_1 ^ 0x2A) * 2) + pub_r001940_11_1) & 127;
  int stage_v_159_2 = (((stage_v_50_2 ^ 0x2A) * 2) + pub_r001940_11_2) & 127;
  if (stage_v_159_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = (((stage_v_88_1 ^ 0x2A) * 2) + pub_r001940_16_1) & 127;
  int stage_v_160_2 = (((stage_v_88_2 ^ 0x2A) * 2) + pub_r001940_16_2) & 127;
  if (stage_v_160_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = (((sec_r001940_0_1 ^ 0x2A) * 2) + pub_r001940_9_1) & 127;
  int stage_v_161_2 = (((sec_r001940_0_2 ^ 0x2A) * 2) + pub_r001940_9_2) & 127;
  if (stage_v_161_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001940_0_1) & 127;
  int stage_v_162_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001940_0_2) & 127;
  if (stage_v_162_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (((stage_v_63_1 ^ 0x2A) * 2) + pub_r001940_16_1) & 127;
  int stage_v_163_2 = (((stage_v_63_2 ^ 0x2A) * 2) + pub_r001940_16_2) & 127;
  if (stage_v_163_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((pub_r001940_17_1 * 2) + 24) & 63;
  int stage_v_164_2 = ((pub_r001940_17_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001940_14_1) & 127;
  int stage_v_165_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001940_14_2) & 127;
  if (stage_v_165_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (((sec_r001940_19_1 ^ 0x2A) * 2) + pub_r001940_15_1) & 127;
  int stage_v_166_2 = (((sec_r001940_19_2 ^ 0x2A) * 2) + pub_r001940_15_2) & 127;
  if (stage_v_166_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((stage_v_154_1 ^ 0x2A) * 2) + pub_r001940_6_1) & 127;
  int stage_v_167_2 = (((stage_v_154_2 ^ 0x2A) * 2) + pub_r001940_6_2) & 127;
  if (stage_v_167_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((sec_r001940_6_1 ^ 0x2A) * 2) + pub_r001940_19_1) & 127;
  int stage_v_168_2 = (((sec_r001940_6_2 ^ 0x2A) * 2) + pub_r001940_19_2) & 127;
  if (stage_v_168_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((pub_r001940_4_1 * 2) + 42) & 63;
  int stage_v_169_2 = ((pub_r001940_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001940_9_1) & 127;
  int stage_v_170_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001940_9_2) & 127;
  if (stage_v_170_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001940_7_1) & 127;
  int stage_v_171_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001940_7_2) & 127;
  if (stage_v_171_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001940_15_1) & 127;
  int stage_v_172_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001940_15_2) & 127;
  if (stage_v_172_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (((stage_v_81_1 ^ 0x2A) * 2) + pub_r001940_2_1) & 127;
  int stage_v_173_2 = (((stage_v_81_2 ^ 0x2A) * 2) + pub_r001940_2_2) & 127;
  if (stage_v_173_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = (((sec_r001940_3_1 ^ 0x2A) * 2) + pub_r001940_4_1) & 127;
  int stage_v_174_2 = (((sec_r001940_3_2 ^ 0x2A) * 2) + pub_r001940_4_2) & 127;
  if (stage_v_174_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001940_11_1) & 127;
  int stage_v_175_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001940_11_2) & 127;
  if (stage_v_175_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = (((sec_r001940_2_1 ^ 0x2A) * 2) + pub_r001940_10_1) & 127;
  int stage_v_176_2 = (((sec_r001940_2_2 ^ 0x2A) * 2) + pub_r001940_10_2) & 127;
  if (stage_v_176_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = (((sec_r001940_13_1 ^ 0x2A) * 2) + pub_r001940_6_1) & 127;
  int stage_v_177_2 = (((sec_r001940_13_2 ^ 0x2A) * 2) + pub_r001940_6_2) & 127;
  if (stage_v_177_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (((stage_v_145_1 ^ 0x2A) * 2) + pub_r001940_12_1) & 127;
  int stage_v_178_2 = (((stage_v_145_2 ^ 0x2A) * 2) + pub_r001940_12_2) & 127;
  if (stage_v_178_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((pub_r001940_14_1 * 2) + 40) & 63;
  int stage_v_179_2 = ((pub_r001940_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001940_16_1) & 127;
  int stage_v_180_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001940_16_2) & 127;
  if (stage_v_180_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((pub_r001940_11_1 * 2) + 39) & 63;
  int stage_v_181_2 = ((pub_r001940_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001940_7_1) & 127;
  int stage_v_182_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001940_7_2) & 127;
  if (stage_v_182_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((pub_r001940_13_1 * 2) + 45) & 63;
  int stage_v_183_2 = ((pub_r001940_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (((sec_r001940_17_1 ^ 0x2A) * 2) + pub_r001940_5_1) & 127;
  int stage_v_184_2 = (((sec_r001940_17_2 ^ 0x2A) * 2) + pub_r001940_5_2) & 127;
  if (stage_v_184_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((pub_r001940_1_1 * 2) + 47) & 63;
  int stage_v_185_2 = ((pub_r001940_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_156_1 ^ 0x2A) * 2) + pub_r001940_10_1) & 127;
  int stage_v_186_2 = (((stage_v_156_2 ^ 0x2A) * 2) + pub_r001940_10_2) & 127;
  if (stage_v_186_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = (((stage_v_166_1 ^ 0x2A) * 2) + pub_r001940_12_1) & 127;
  int stage_v_187_2 = (((stage_v_166_2 ^ 0x2A) * 2) + pub_r001940_12_2) & 127;
  if (stage_v_187_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = (((stage_v_116_1 ^ 0x2A) * 2) + pub_r001940_10_1) & 127;
  int stage_v_188_2 = (((stage_v_116_2 ^ 0x2A) * 2) + pub_r001940_10_2) & 127;
  if (stage_v_188_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001940_7_1) & 127;
  int stage_v_189_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001940_7_2) & 127;
  if (stage_v_189_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001940_2_1) & 127;
  int stage_v_190_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001940_2_2) & 127;
  if (stage_v_190_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001940_4_1) & 127;
  int stage_v_191_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001940_4_2) & 127;
  if (stage_v_191_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((stage_v_176_1 ^ 0x2A) * 2) + pub_r001940_11_1) & 127;
  int stage_v_192_2 = (((stage_v_176_2 ^ 0x2A) * 2) + pub_r001940_11_2) & 127;
  if (stage_v_192_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((pub_r001940_3_1 * 2) + 50) & 63;
  int stage_v_193_2 = ((pub_r001940_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001940_1_1) & 127;
  int stage_v_194_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001940_1_2) & 127;
  if (stage_v_194_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = (((sec_r001940_17_1 ^ 0x2A) * 2) + pub_r001940_19_1) & 127;
  int stage_v_195_2 = (((sec_r001940_17_2 ^ 0x2A) * 2) + pub_r001940_19_2) & 127;
  if (stage_v_195_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = (((sec_r001940_19_1 ^ 0x2A) * 2) + pub_r001940_19_1) & 127;
  int stage_v_196_2 = (((sec_r001940_19_2 ^ 0x2A) * 2) + pub_r001940_19_2) & 127;
  if (stage_v_196_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001940_4_1) & 127;
  int stage_v_197_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001940_4_2) & 127;
  if (stage_v_197_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((pub_r001940_13_1 * 2) + 36) & 63;
  int stage_v_198_2 = ((pub_r001940_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (((stage_v_160_1 ^ 0x2A) * 2) + pub_r001940_18_1) & 127;
  int stage_v_199_2 = (((stage_v_160_2 ^ 0x2A) * 2) + pub_r001940_18_2) & 127;
  if (stage_v_199_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((pub_r001940_17_1 * 2) + 50) & 63;
  int stage_v_200_2 = ((pub_r001940_17_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = (((sec_r001940_20_1 ^ 0x2A) * 2) + pub_r001940_1_1) & 127;
  int stage_v_201_2 = (((sec_r001940_20_2 ^ 0x2A) * 2) + pub_r001940_1_2) & 127;
  if (stage_v_201_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((pub_r001940_17_1 * 2) + 6) & 63;
  int stage_v_202_2 = ((pub_r001940_17_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001940_17_1) & 127;
  int stage_v_203_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001940_17_2) & 127;
  if (stage_v_203_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001940_3_1) & 127;
  int stage_v_204_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001940_3_2) & 127;
  if (stage_v_204_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((pub_r001940_12_1 * 2) + 13) & 63;
  int stage_v_205_2 = ((pub_r001940_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = (((sec_r001940_10_1 ^ 0x2A) * 2) + pub_r001940_2_1) & 127;
  int stage_v_206_2 = (((sec_r001940_10_2 ^ 0x2A) * 2) + pub_r001940_2_2) & 127;
  if (stage_v_206_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = (((stage_v_186_1 ^ 0x2A) * 2) + pub_r001940_19_1) & 127;
  int stage_v_207_2 = (((stage_v_186_2 ^ 0x2A) * 2) + pub_r001940_19_2) & 127;
  if (stage_v_207_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = (((sec_r001940_11_1 ^ 0x2A) * 2) + pub_r001940_6_1) & 127;
  int stage_v_208_2 = (((sec_r001940_11_2 ^ 0x2A) * 2) + pub_r001940_6_2) & 127;
  if (stage_v_208_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = (((stage_v_90_1 ^ 0x2A) * 2) + pub_r001940_4_1) & 127;
  int stage_v_209_2 = (((stage_v_90_2 ^ 0x2A) * 2) + pub_r001940_4_2) & 127;
  if (stage_v_209_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((pub_r001940_14_1 * 2) + 45) & 63;
  int stage_v_210_2 = ((pub_r001940_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001940_3_1 * 2) + 47) & 63;
  int stage_v_211_2 = ((pub_r001940_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = (((stage_v_124_1 ^ 0x2A) * 2) + pub_r001940_4_1) & 127;
  int stage_v_212_2 = (((stage_v_124_2 ^ 0x2A) * 2) + pub_r001940_4_2) & 127;
  if (stage_v_212_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
  }
  if (stage_v_212_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((pub_r001940_2_1 * 2) + 30) & 63;
  int stage_v_213_2 = ((pub_r001940_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = (((stage_v_157_1 ^ 0x2A) * 2) + pub_r001940_11_1) & 127;
  int stage_v_214_2 = (((stage_v_157_2 ^ 0x2A) * 2) + pub_r001940_11_2) & 127;
  if (stage_v_214_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((pub_r001940_5_1 * 2) + 32) & 63;
  int stage_v_215_2 = ((pub_r001940_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001940_6_1) & 127;
  int stage_v_216_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001940_6_2) & 127;
  if (stage_v_216_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
  }
  if (stage_v_216_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = (((stage_v_90_1 ^ 0x2A) * 2) + pub_r001940_11_1) & 127;
  int stage_v_217_2 = (((stage_v_90_2 ^ 0x2A) * 2) + pub_r001940_11_2) & 127;
  if (stage_v_217_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001940_7_1) & 127;
  int stage_v_218_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001940_7_2) & 127;
  if (stage_v_218_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001940_8_1) & 127;
  int stage_v_219_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001940_8_2) & 127;
  if (stage_v_219_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((pub_r001940_13_1 * 2) + 6) & 63;
  int stage_v_220_2 = ((pub_r001940_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001940_18_1 * 2) + 40) & 63;
  int stage_v_221_2 = ((pub_r001940_18_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = (((stage_v_81_1 ^ 0x2A) * 2) + pub_r001940_3_1) & 127;
  int stage_v_222_2 = (((stage_v_81_2 ^ 0x2A) * 2) + pub_r001940_3_2) & 127;
  if (stage_v_222_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
  }
  if (stage_v_222_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = (((sec_r001940_4_1 ^ 0x2A) * 2) + pub_r001940_11_1) & 127;
  int stage_v_223_2 = (((sec_r001940_4_2 ^ 0x2A) * 2) + pub_r001940_11_2) & 127;
  if (stage_v_223_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001940_7_1 == pub_r001940_7_2);
  __CPROVER_assume(sec_r001940_7_1 != sec_r001940_7_2);
  __CPROVER_assume(pub_r001940_9_1 == pub_r001940_9_2);
  __CPROVER_assume(pub_r001940_4_1 == pub_r001940_4_2);
  __CPROVER_assume(pub_r001940_15_1 == pub_r001940_15_2);
  __CPROVER_assume(pub_r001940_18_1 == pub_r001940_18_2);
  __CPROVER_assume(pub_r001940_6_1 == pub_r001940_6_2);
  __CPROVER_assume(sec_r001940_19_1 != sec_r001940_19_2);
  __CPROVER_assume(sec_r001940_13_1 != sec_r001940_13_2);
  __CPROVER_assume(sec_r001940_1_1 != sec_r001940_1_2);
  __CPROVER_assume(sec_r001940_22_1 != sec_r001940_22_2);
  __CPROVER_assume(pub_r001940_14_1 == pub_r001940_14_2);
  __CPROVER_assume(sec_r001940_18_1 != sec_r001940_18_2);
  __CPROVER_assume(pub_r001940_10_1 == pub_r001940_10_2);
  __CPROVER_assume(pub_r001940_0_1 == pub_r001940_0_2);
  __CPROVER_assume(pub_r001940_16_1 == pub_r001940_16_2);
  __CPROVER_assume(sec_r001940_15_1 != sec_r001940_15_2);
  __CPROVER_assume(pub_r001940_17_1 == pub_r001940_17_2);
  __CPROVER_assume(sec_r001940_0_1 != sec_r001940_0_2);
  __CPROVER_assume(sec_r001940_16_1 != sec_r001940_16_2);
  __CPROVER_assume(pub_r001940_2_1 == pub_r001940_2_2);
  __CPROVER_assume(sec_r001940_5_1 != sec_r001940_5_2);
  __CPROVER_assume(sec_r001940_10_1 != sec_r001940_10_2);
  __CPROVER_assume(pub_r001940_12_1 == pub_r001940_12_2);
  __CPROVER_assume(sec_r001940_3_1 != sec_r001940_3_2);
  __CPROVER_assume(sec_r001940_6_1 != sec_r001940_6_2);
  __CPROVER_assume(sec_r001940_17_1 != sec_r001940_17_2);
  __CPROVER_assume(pub_r001940_5_1 == pub_r001940_5_2);
  __CPROVER_assume(sec_r001940_12_1 != sec_r001940_12_2);
  __CPROVER_assume(pub_r001940_13_1 == pub_r001940_13_2);
  __CPROVER_assume(sec_r001940_9_1 != sec_r001940_9_2);
  __CPROVER_assume(pub_r001940_1_1 == pub_r001940_1_2);
  __CPROVER_assume(pub_r001940_19_1 == pub_r001940_19_2);
  __CPROVER_assume(pub_r001940_8_1 == pub_r001940_8_2);
  __CPROVER_assume(sec_r001940_4_1 != sec_r001940_4_2);
  __CPROVER_assume(sec_r001940_20_1 != sec_r001940_20_2);
  __CPROVER_assume(sec_r001940_21_1 != sec_r001940_21_2);
  __CPROVER_assume(pub_r001940_3_1 == pub_r001940_3_2);
  __CPROVER_assume(sec_r001940_2_1 != sec_r001940_2_2);
  __CPROVER_assume(sec_r001940_11_1 != sec_r001940_11_2);
  __CPROVER_assume(sec_r001940_14_1 != sec_r001940_14_2);
  __CPROVER_assume(sec_r001940_8_1 != sec_r001940_8_2);
  __CPROVER_assume(pub_r001940_11_1 == pub_r001940_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.seq == st_var_2_2.seq);
  assert(st_var_2_1.severity == st_var_2_2.severity);
  assert(st_var_2_1.code == st_var_2_2.code);
  assert(st_var_2_1.timestamp == st_var_2_2.timestamp);
  assert(st_var_2_1.signature == st_var_2_2.signature);
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
}


