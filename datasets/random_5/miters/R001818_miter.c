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
struct AudioFrame_R001818_1813_0
{
  int rms;
  int sample_rate;
  short peak;
  unsigned char gain;
  int envelope;
  int buffer[3];
};
struct Vector3D_R001818_1813_1
{
  unsigned char norm_sq;
  int pitch;
  int heading;
  short coord_z;
  short coord_y;
  int coord_x;
  int buffer[3];
};
union PacketPayload_R001818_1813_0
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
void fn_R001818_1813_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001818_1813_0 st_1 = {0};
  struct AudioFrame_R001818_1813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int stride_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_80_1 > 40)
  {
    acc_1 = ((acc_1 + (stride_80_1 * 2)) + 5) & 127;
    aux_1 ^= stride_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_80_2 > 40)
  {
    acc_2 = ((acc_2 + (stride_80_2 * 2)) + 5) & 127;
    aux_2 ^= stride_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_80_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_92_1) & 63;
  aux_2 = (aux_2 + threshold_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_57_1)
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

  switch (factor_57_2)
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_80_1 == stride_80_2);
  assert(threshold_92_1 == threshold_92_2);
  assert(factor_57_1 == factor_57_2);
}

int fn_R001818_1813_0(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001818_1813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int stride_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_80 > 40)
  {
    acc = ((acc + (stride_80 * 2)) + 5) & 127;
    aux ^= stride_80 & 15;
  }
  else
  {
    acc = ((acc - stride_80) + 11) & 127;
    aux += 3;
  }
  int threshold_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_92) & 63;
  acc ^= aux;
  int factor_57 = (aux + st.buffer[1]) & 3;
  switch (factor_57)
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

void fn_R001818_1813_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st_1 = {0};
  struct Vector3D_R001818_1813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_63_1 = local_arr_1[aux_1 % 3];
  int parity_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_63_2 * 2)) & 127;
  int quotient_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_93_1) & 63;
  aux_2 = (aux_2 + quotient_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_63_1 == parity_63_2);
  assert(quotient_93_1 == quotient_93_2);
}

int fn_R001818_1813_1(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int parity_63 = local_arr[aux % 3];
  acc = (acc + (parity_63 * 2)) & 127;
  int quotient_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_93) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001818_1813_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st_1 = {0};
  struct Vector3D_R001818_1813_1 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_66_1 = local_arr_1[aux_1 % 3];
  int accumulator_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_66_2 * 2)) & 127;
  int offset_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_32_1)
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

  switch (offset_32_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_66_1 == accumulator_66_2);
  assert(offset_32_1 == offset_32_2);
}

int fn_R001818_1813_2(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_66 = local_arr[aux % 3];
  acc = (acc + (accumulator_66 * 2)) & 127;
  int offset_32 = (aux + st.buffer[1]) & 3;
  switch (offset_32)
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

void fn_R001818_1813_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st_1 = {0};
  struct Vector3D_R001818_1813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int tracker_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_15_1)
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

  switch (tracker_15_2)
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
  int scale_89_1 = local_arr_1[aux_1 % 3];
  int scale_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_89_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_15_1 == tracker_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_89_1 == scale_89_2);
}

int fn_R001818_1813_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int tracker_15 = (aux + st.buffer[1]) & 3;
  switch (tracker_15)
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
  int scale_89 = local_arr[aux % 3];
  acc = (acc + (scale_89 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001818_1813_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st_1 = {0};
  struct Vector3D_R001818_1813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_67_1 = local_arr_1[aux_1 % 3];
  int offset_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_67_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_67_1 == offset_67_2);
}

int fn_R001818_1813_4(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int offset_67 = local_arr[aux % 3];
  acc = (acc + (offset_67 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001818_1813_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st_1 = {0};
  struct Vector3D_R001818_1813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int metric_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_52_1) & 63;
  aux_2 = (aux_2 + metric_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_38_1 > 43)
  {
    acc_1 = ((acc_1 + (delta_38_1 * 2)) + 5) & 127;
    aux_1 ^= delta_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_38_2 > 43)
  {
    acc_2 = ((acc_2 + (delta_38_2 * 2)) + 5) & 127;
    aux_2 ^= delta_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_86_1 = 0;
  int factor_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_86_1 = ((factor_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_86_2 = ((factor_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_86_1) & 127;
    acc_2 = (acc_2 + factor_86_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_52_1 == metric_52_2);
  assert(delta_38_1 == delta_38_2);
  assert(factor_86_1 == factor_86_2);
}

int fn_R001818_1813_5(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int metric_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_52) & 63;
  acc ^= aux;
  int delta_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_38 > 43)
  {
    acc = ((acc + (delta_38 * 2)) + 5) & 127;
    aux ^= delta_38 & 15;
  }
  else
  {
    acc = ((acc - delta_38) + 11) & 127;
    aux += 3;
  }
  int factor_86 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_86 = ((factor_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_86) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001818_1813_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001818_1813_0 st_1 = {0};
  struct AudioFrame_R001818_1813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_38_1 = local_arr_1[aux_1 % 3];
  int damping_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_38_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_38_1 == damping_38_2);
}

int fn_R001818_1813_6(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001818_1813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int damping_38 = local_arr[aux % 3];
  acc = (acc + (damping_38 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001818_1813_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001818_1813_0 st_1 = {0};
  struct AudioFrame_R001818_1813_0 st_2 = {0};
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
  int tracker_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_83_1)
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

  switch (tracker_83_2)
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
  int phase_90_1 = local_arr_1[aux_1 % 3];
  int phase_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_90_2 * 2)) & 127;
  int pivot_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_79_1 > 18)
  {
    acc_1 = ((acc_1 + (pivot_79_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_79_2 > 18)
  {
    acc_2 = ((acc_2 + (pivot_79_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_79_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_83_1 == tracker_83_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_90_1 == phase_90_2);
  assert(pivot_79_1 == pivot_79_2);
}

int fn_R001818_1813_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001818_1813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_83 = (aux + st.buffer[1]) & 3;
  switch (tracker_83)
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
  int phase_90 = local_arr[aux % 3];
  acc = (acc + (phase_90 * 2)) & 127;
  int pivot_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_79 > 18)
  {
    acc = ((acc + (pivot_79 * 2)) + 5) & 127;
    aux ^= pivot_79 & 15;
  }
  else
  {
    acc = ((acc - pivot_79) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001818_1813_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st_1 = {0};
  struct Vector3D_R001818_1813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int accumulator_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_43_1 > 10)
  {
    acc_1 = ((acc_1 + (accumulator_43_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_43_2 > 10)
  {
    acc_2 = ((acc_2 + (accumulator_43_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_72_1 = 0;
  int mask_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_72_1 = ((mask_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_72_2 = ((mask_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_72_1) & 127;
    acc_2 = (acc_2 + mask_72_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_30_1) & 63;
  aux_2 = (aux_2 + anchor_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_43_1 == accumulator_43_2);
  assert(mask_72_1 == mask_72_2);
  assert(anchor_30_1 == anchor_30_2);
}

int fn_R001818_1813_8(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int accumulator_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_43 > 10)
  {
    acc = ((acc + (accumulator_43 * 2)) + 5) & 127;
    aux ^= accumulator_43 & 15;
  }
  else
  {
    acc = ((acc - accumulator_43) + 11) & 127;
    aux += 3;
  }
  int mask_72 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_72 = ((mask_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_72) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_30) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001818_1813_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st_1 = {0};
  struct Vector3D_R001818_1813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_71_1 = local_arr_1[aux_1 % 3];
  int bound_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_71_2 * 2)) & 127;
  int phase_60_1 = 0;
  int phase_60_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_60_1 = ((phase_60_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_60_2 = ((phase_60_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_60_1) & 127;
    acc_2 = (acc_2 + phase_60_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_71_1 == bound_71_2);
  assert(phase_60_1 == phase_60_2);
}

int fn_R001818_1813_9(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int bound_71 = local_arr[aux % 3];
  acc = (acc + (bound_71 * 2)) & 127;
  int phase_60 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_60 = ((phase_60 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_60) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001818_1813_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st_1 = {0};
  struct Vector3D_R001818_1813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int damping_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_23_1 > 33)
  {
    acc_1 = ((acc_1 + (damping_23_1 * 2)) + 5) & 127;
    aux_1 ^= damping_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_23_2 > 33)
  {
    acc_2 = ((acc_2 + (damping_23_2 * 2)) + 5) & 127;
    aux_2 ^= damping_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_23_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_47_1 = local_arr_1[aux_1 % 3];
  int margin_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_47_2 * 2)) & 127;
  int tracker_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_68_1) & 63;
  aux_2 = (aux_2 + tracker_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_23_1 == damping_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_47_1 == margin_47_2);
  assert(tracker_68_1 == tracker_68_2);
}

int fn_R001818_1813_10(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int damping_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_23 > 33)
  {
    acc = ((acc + (damping_23 * 2)) + 5) & 127;
    aux ^= damping_23 & 15;
  }
  else
  {
    acc = ((acc - damping_23) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int margin_47 = local_arr[aux % 3];
  acc = (acc + (margin_47 * 2)) & 127;
  int tracker_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_68) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001818_1813_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st_1 = {0};
  struct Vector3D_R001818_1813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int index_reg_96_1 = 0;
  int index_reg_96_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_96_1 = ((index_reg_96_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_96_2 = ((index_reg_96_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_96_1) & 127;
    acc_2 = (acc_2 + index_reg_96_2) & 127;
  }

  int cursor_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_54_1 > 38)
  {
    acc_1 = ((acc_1 + (cursor_54_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_54_2 > 38)
  {
    acc_2 = ((acc_2 + (cursor_54_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_16_1 = local_arr_1[aux_1 % 3];
  int delta_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_16_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_96_1 == index_reg_96_2);
  assert(cursor_54_1 == cursor_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_16_1 == delta_16_2);
}

int fn_R001818_1813_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int index_reg_96 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_96 = ((index_reg_96 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_96) & 127;
  }

  int cursor_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_54 > 38)
  {
    acc = ((acc + (cursor_54 * 2)) + 5) & 127;
    aux ^= cursor_54 & 15;
  }
  else
  {
    acc = ((acc - cursor_54) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int delta_16 = local_arr[aux % 3];
  acc = (acc + (delta_16 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001818_1813_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001818_1813_0 st_1 = {0};
  struct AudioFrame_R001818_1813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int weight_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_47_1) & 63;
  aux_2 = (aux_2 + weight_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_79_1 = 0;
  int pivot_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_79_1 = ((pivot_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_79_2 = ((pivot_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_79_1) & 127;
    acc_2 = (acc_2 + pivot_79_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_90_1 = local_arr_1[aux_1 % 3];
  int window_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_90_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_47_1 == weight_47_2);
  assert(pivot_79_1 == pivot_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_90_1 == window_90_2);
}

int fn_R001818_1813_12(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001818_1813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int weight_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_47) & 63;
  acc ^= aux;
  int pivot_79 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_79 = ((pivot_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_79) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int window_90 = local_arr[aux % 3];
  acc = (acc + (window_90 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001818_1813_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001818_1813_0 st_1 = {0};
  struct AudioFrame_R001818_1813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int margin_42_1 = 0;
  int margin_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_42_1 = ((margin_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_42_2 = ((margin_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_42_1) & 127;
    acc_2 = (acc_2 + margin_42_2) & 127;
  }

  int sample_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_93_1) & 63;
  aux_2 = (aux_2 + sample_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_42_1 == margin_42_2);
  assert(sample_93_1 == sample_93_2);
}

int fn_R001818_1813_13(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001818_1813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int margin_42 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_42 = ((margin_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_42) & 127;
  }

  int sample_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_93) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001818_1813_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001818_1813_0 st_1 = {0};
  struct AudioFrame_R001818_1813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int mask_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_92_1)
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

  switch (mask_92_2)
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

  int phase_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_57_1) & 63;
  aux_2 = (aux_2 + phase_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_92_1 == mask_92_2);
  assert(phase_57_1 == phase_57_2);
}

int fn_R001818_1813_14(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001818_1813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int mask_92 = (aux + st.buffer[1]) & 3;
  switch (mask_92)
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

  int phase_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_57) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001818_1813_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st_1 = {0};
  struct Vector3D_R001818_1813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_49_1 = local_arr_1[aux_1 % 3];
  int margin_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_49_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_49_1 == margin_49_2);
}

int fn_R001818_1813_15(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int margin_49 = local_arr[aux % 3];
  acc = (acc + (margin_49 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001818_1813_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001818_1813_0 st_1 = {0};
  struct AudioFrame_R001818_1813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_94_1 = local_arr_1[aux_1 % 3];
  int segment_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_94_2 * 2)) & 127;
  int damping_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_69_1)
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

  switch (damping_69_2)
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

  int vector_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_76_1) & 63;
  aux_2 = (aux_2 + vector_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_94_1 == segment_94_2);
  assert(damping_69_1 == damping_69_2);
  assert(vector_76_1 == vector_76_2);
}

int fn_R001818_1813_16(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001818_1813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int segment_94 = local_arr[aux % 3];
  acc = (acc + (segment_94 * 2)) & 127;
  int damping_69 = (aux + st.buffer[1]) & 3;
  switch (damping_69)
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

  int vector_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_76) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001818_1813_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001818_1813_0 st_1 = {0};
  struct AudioFrame_R001818_1813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_58_1 = 0;
  int quotient_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_58_1 = ((quotient_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_58_2 = ((quotient_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_58_1) & 127;
    acc_2 = (acc_2 + quotient_58_2) & 127;
  }

  int margin_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_73_1) & 63;
  aux_2 = (aux_2 + margin_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_41_1)
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

  switch (metric_41_2)
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_58_1 == quotient_58_2);
  assert(margin_73_1 == margin_73_2);
  assert(metric_41_1 == metric_41_2);
}

int fn_R001818_1813_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001818_1813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_58 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_58 = ((quotient_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_58) & 127;
  }

  int margin_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_73) & 63;
  acc ^= aux;
  int metric_41 = (aux + st.buffer[1]) & 3;
  switch (metric_41)
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

void fn_R001818_1813_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st_1 = {0};
  struct Vector3D_R001818_1813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int parity_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_30_1 > 49)
  {
    acc_1 = ((acc_1 + (parity_30_1 * 2)) + 5) & 127;
    aux_1 ^= parity_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_30_2 > 49)
  {
    acc_2 = ((acc_2 + (parity_30_2 * 2)) + 5) & 127;
    aux_2 ^= parity_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_30_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_43_1 = 0;
  int bound_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_43_1 = ((bound_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_43_2 = ((bound_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_43_1) & 127;
    acc_2 = (acc_2 + bound_43_2) & 127;
  }

  int delta_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_57_1) & 63;
  aux_2 = (aux_2 + delta_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_30_1 == parity_30_2);
  assert(bound_43_1 == bound_43_2);
  assert(delta_57_1 == delta_57_2);
}

int fn_R001818_1813_18(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int parity_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_30 > 49)
  {
    acc = ((acc + (parity_30 * 2)) + 5) & 127;
    aux ^= parity_30 & 15;
  }
  else
  {
    acc = ((acc - parity_30) + 11) & 127;
    aux += 3;
  }
  int bound_43 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_43 = ((bound_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_43) & 127;
  }

  int delta_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_57) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001818_1813_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st_1 = {0};
  struct Vector3D_R001818_1813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int metric_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_61_1)
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

  switch (metric_61_2)
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

  int metric_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_96_1) & 63;
  aux_2 = (aux_2 + metric_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_59_1 = local_arr_1[aux_1 % 3];
  int tracker_59_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_59_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_59_2 * 2)) & 127;
  int bound_26_1 = 0;
  int bound_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_26_1 = ((bound_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_26_2 = ((bound_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_26_1) & 127;
    acc_2 = (acc_2 + bound_26_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_61_1 == metric_61_2);
  assert(metric_96_1 == metric_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_59_1 == tracker_59_2);
  assert(bound_26_1 == bound_26_2);
}

int fn_R001818_1813_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001818_1813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int metric_61 = (aux + st.buffer[1]) & 3;
  switch (metric_61)
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

  int metric_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_96) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_59 = local_arr[aux % 3];
  acc = (acc + (tracker_59 * 2)) & 127;
  int bound_26 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_26 = ((bound_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_26) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001818_0_1;
  int sec_r001818_0_2;
  int sec_r001818_1_1;
  int sec_r001818_1_2;
  int sec_r001818_2_1;
  int sec_r001818_2_2;
  int sec_r001818_3_1;
  int sec_r001818_3_2;
  int sec_r001818_4_1;
  int sec_r001818_4_2;
  int sec_r001818_5_1;
  int sec_r001818_5_2;
  int sec_r001818_6_1;
  int sec_r001818_6_2;
  int sec_r001818_7_1;
  int sec_r001818_7_2;
  int sec_r001818_8_1;
  int sec_r001818_8_2;
  int sec_r001818_9_1;
  int sec_r001818_9_2;
  int sec_r001818_10_1;
  int sec_r001818_10_2;
  int sec_r001818_11_1;
  int sec_r001818_11_2;
  int sec_r001818_12_1;
  int sec_r001818_12_2;
  int sec_r001818_13_1;
  int sec_r001818_13_2;
  int sec_r001818_14_1;
  int sec_r001818_14_2;
  int sec_r001818_15_1;
  int sec_r001818_15_2;
  int sec_r001818_16_1;
  int sec_r001818_16_2;
  int sec_r001818_17_1;
  int sec_r001818_17_2;
  int sec_r001818_18_1;
  int sec_r001818_18_2;
  int sec_r001818_19_1;
  int sec_r001818_19_2;
  int pub_r001818_0_1;
  int pub_r001818_0_2;
  int pub_r001818_1_1;
  int pub_r001818_1_2;
  int pub_r001818_2_1;
  int pub_r001818_2_2;
  int pub_r001818_3_1;
  int pub_r001818_3_2;
  int pub_r001818_4_1;
  int pub_r001818_4_2;
  int pub_r001818_5_1;
  int pub_r001818_5_2;
  int pub_r001818_6_1;
  int pub_r001818_6_2;
  int pub_r001818_7_1;
  int pub_r001818_7_2;
  int pub_r001818_8_1;
  int pub_r001818_8_2;
  int pub_r001818_9_1;
  int pub_r001818_9_2;
  int pub_r001818_10_1;
  int pub_r001818_10_2;
  int pub_r001818_11_1;
  int pub_r001818_11_2;
  int pub_r001818_12_1;
  int pub_r001818_12_2;
  int pub_r001818_13_1;
  int pub_r001818_13_2;
  int pub_r001818_14_1;
  int pub_r001818_14_2;
  int pub_r001818_15_1;
  int pub_r001818_15_2;
  int pub_r001818_16_1;
  int pub_r001818_16_2;
  int pub_r001818_17_1;
  int pub_r001818_17_2;
  int pub_r001818_18_1;
  int pub_r001818_18_2;
  int pub_r001818_19_1;
  int pub_r001818_19_2;
  int pub_r001818_20_1;
  int pub_r001818_20_2;
  int pub_r001818_21_1;
  int pub_r001818_21_2;
  int pub_r001818_22_1;
  int pub_r001818_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001818_0_1 >= (-100)) && (pub_r001818_0_1 <= 100));
  __CPROVER_assume((pub_r001818_0_2 >= (-100)) && (pub_r001818_0_2 <= 100));
  __CPROVER_assume((pub_r001818_1_1 >= (-100)) && (pub_r001818_1_1 <= 100));
  __CPROVER_assume((pub_r001818_1_2 >= (-100)) && (pub_r001818_1_2 <= 100));
  __CPROVER_assume((pub_r001818_2_1 >= (-100)) && (pub_r001818_2_1 <= 100));
  __CPROVER_assume((pub_r001818_2_2 >= (-100)) && (pub_r001818_2_2 <= 100));
  __CPROVER_assume((pub_r001818_3_1 >= (-100)) && (pub_r001818_3_1 <= 100));
  __CPROVER_assume((pub_r001818_3_2 >= (-100)) && (pub_r001818_3_2 <= 100));
  __CPROVER_assume((pub_r001818_4_1 >= (-100)) && (pub_r001818_4_1 <= 100));
  __CPROVER_assume((pub_r001818_4_2 >= (-100)) && (pub_r001818_4_2 <= 100));
  __CPROVER_assume((pub_r001818_5_1 >= (-100)) && (pub_r001818_5_1 <= 100));
  __CPROVER_assume((pub_r001818_5_2 >= (-100)) && (pub_r001818_5_2 <= 100));
  __CPROVER_assume((pub_r001818_6_1 >= (-100)) && (pub_r001818_6_1 <= 100));
  __CPROVER_assume((pub_r001818_6_2 >= (-100)) && (pub_r001818_6_2 <= 100));
  __CPROVER_assume((pub_r001818_7_1 >= (-100)) && (pub_r001818_7_1 <= 100));
  __CPROVER_assume((pub_r001818_7_2 >= (-100)) && (pub_r001818_7_2 <= 100));
  __CPROVER_assume((pub_r001818_8_1 >= (-100)) && (pub_r001818_8_1 <= 100));
  __CPROVER_assume((pub_r001818_8_2 >= (-100)) && (pub_r001818_8_2 <= 100));
  __CPROVER_assume((pub_r001818_9_1 >= (-100)) && (pub_r001818_9_1 <= 100));
  __CPROVER_assume((pub_r001818_9_2 >= (-100)) && (pub_r001818_9_2 <= 100));
  __CPROVER_assume((pub_r001818_10_1 >= (-100)) && (pub_r001818_10_1 <= 100));
  __CPROVER_assume((pub_r001818_10_2 >= (-100)) && (pub_r001818_10_2 <= 100));
  __CPROVER_assume((pub_r001818_11_1 >= (-100)) && (pub_r001818_11_1 <= 100));
  __CPROVER_assume((pub_r001818_11_2 >= (-100)) && (pub_r001818_11_2 <= 100));
  __CPROVER_assume((pub_r001818_12_1 >= (-100)) && (pub_r001818_12_1 <= 100));
  __CPROVER_assume((pub_r001818_12_2 >= (-100)) && (pub_r001818_12_2 <= 100));
  __CPROVER_assume((pub_r001818_13_1 >= (-100)) && (pub_r001818_13_1 <= 100));
  __CPROVER_assume((pub_r001818_13_2 >= (-100)) && (pub_r001818_13_2 <= 100));
  __CPROVER_assume((pub_r001818_14_1 >= (-100)) && (pub_r001818_14_1 <= 100));
  __CPROVER_assume((pub_r001818_14_2 >= (-100)) && (pub_r001818_14_2 <= 100));
  __CPROVER_assume((pub_r001818_15_1 >= (-100)) && (pub_r001818_15_1 <= 100));
  __CPROVER_assume((pub_r001818_15_2 >= (-100)) && (pub_r001818_15_2 <= 100));
  __CPROVER_assume((pub_r001818_16_1 >= (-100)) && (pub_r001818_16_1 <= 100));
  __CPROVER_assume((pub_r001818_16_2 >= (-100)) && (pub_r001818_16_2 <= 100));
  __CPROVER_assume((pub_r001818_17_1 >= (-100)) && (pub_r001818_17_1 <= 100));
  __CPROVER_assume((pub_r001818_17_2 >= (-100)) && (pub_r001818_17_2 <= 100));
  __CPROVER_assume((pub_r001818_18_1 >= (-100)) && (pub_r001818_18_1 <= 100));
  __CPROVER_assume((pub_r001818_18_2 >= (-100)) && (pub_r001818_18_2 <= 100));
  __CPROVER_assume((pub_r001818_19_1 >= (-100)) && (pub_r001818_19_1 <= 100));
  __CPROVER_assume((pub_r001818_19_2 >= (-100)) && (pub_r001818_19_2 <= 100));
  __CPROVER_assume((pub_r001818_20_1 >= (-100)) && (pub_r001818_20_1 <= 100));
  __CPROVER_assume((pub_r001818_20_2 >= (-100)) && (pub_r001818_20_2 <= 100));
  __CPROVER_assume((pub_r001818_21_1 >= (-100)) && (pub_r001818_21_1 <= 100));
  __CPROVER_assume((pub_r001818_21_2 >= (-100)) && (pub_r001818_21_2 <= 100));
  __CPROVER_assume((pub_r001818_22_1 >= (-100)) && (pub_r001818_22_1 <= 100));
  __CPROVER_assume((pub_r001818_22_2 >= (-100)) && (pub_r001818_22_2 <= 100));
  __CPROVER_assume((sec_r001818_0_1 >= 0) && (sec_r001818_0_1 <= 255));
  __CPROVER_assume((sec_r001818_0_2 >= 0) && (sec_r001818_0_2 <= 255));
  __CPROVER_assume((sec_r001818_1_1 >= 0) && (sec_r001818_1_1 <= 255));
  __CPROVER_assume((sec_r001818_1_2 >= 0) && (sec_r001818_1_2 <= 255));
  __CPROVER_assume((sec_r001818_2_1 >= 0) && (sec_r001818_2_1 <= 255));
  __CPROVER_assume((sec_r001818_2_2 >= 0) && (sec_r001818_2_2 <= 255));
  __CPROVER_assume((sec_r001818_3_1 >= 0) && (sec_r001818_3_1 <= 255));
  __CPROVER_assume((sec_r001818_3_2 >= 0) && (sec_r001818_3_2 <= 255));
  __CPROVER_assume((sec_r001818_4_1 >= 0) && (sec_r001818_4_1 <= 255));
  __CPROVER_assume((sec_r001818_4_2 >= 0) && (sec_r001818_4_2 <= 255));
  __CPROVER_assume((sec_r001818_5_1 >= 0) && (sec_r001818_5_1 <= 255));
  __CPROVER_assume((sec_r001818_5_2 >= 0) && (sec_r001818_5_2 <= 255));
  __CPROVER_assume((sec_r001818_6_1 >= 0) && (sec_r001818_6_1 <= 255));
  __CPROVER_assume((sec_r001818_6_2 >= 0) && (sec_r001818_6_2 <= 255));
  __CPROVER_assume((sec_r001818_7_1 >= 0) && (sec_r001818_7_1 <= 255));
  __CPROVER_assume((sec_r001818_7_2 >= 0) && (sec_r001818_7_2 <= 255));
  __CPROVER_assume((sec_r001818_8_1 >= 0) && (sec_r001818_8_1 <= 255));
  __CPROVER_assume((sec_r001818_8_2 >= 0) && (sec_r001818_8_2 <= 255));
  __CPROVER_assume((sec_r001818_9_1 >= 0) && (sec_r001818_9_1 <= 255));
  __CPROVER_assume((sec_r001818_9_2 >= 0) && (sec_r001818_9_2 <= 255));
  __CPROVER_assume((sec_r001818_10_1 >= 0) && (sec_r001818_10_1 <= 255));
  __CPROVER_assume((sec_r001818_10_2 >= 0) && (sec_r001818_10_2 <= 255));
  __CPROVER_assume((sec_r001818_11_1 >= 0) && (sec_r001818_11_1 <= 255));
  __CPROVER_assume((sec_r001818_11_2 >= 0) && (sec_r001818_11_2 <= 255));
  __CPROVER_assume((sec_r001818_12_1 >= 0) && (sec_r001818_12_1 <= 255));
  __CPROVER_assume((sec_r001818_12_2 >= 0) && (sec_r001818_12_2 <= 255));
  __CPROVER_assume((sec_r001818_13_1 >= 0) && (sec_r001818_13_1 <= 255));
  __CPROVER_assume((sec_r001818_13_2 >= 0) && (sec_r001818_13_2 <= 255));
  __CPROVER_assume((sec_r001818_14_1 >= 0) && (sec_r001818_14_1 <= 255));
  __CPROVER_assume((sec_r001818_14_2 >= 0) && (sec_r001818_14_2 <= 255));
  __CPROVER_assume((sec_r001818_15_1 >= 0) && (sec_r001818_15_1 <= 255));
  __CPROVER_assume((sec_r001818_15_2 >= 0) && (sec_r001818_15_2 <= 255));
  __CPROVER_assume((sec_r001818_16_1 >= 0) && (sec_r001818_16_1 <= 255));
  __CPROVER_assume((sec_r001818_16_2 >= 0) && (sec_r001818_16_2 <= 255));
  __CPROVER_assume((sec_r001818_17_1 >= 0) && (sec_r001818_17_1 <= 255));
  __CPROVER_assume((sec_r001818_17_2 >= 0) && (sec_r001818_17_2 <= 255));
  __CPROVER_assume((sec_r001818_18_1 >= 0) && (sec_r001818_18_1 <= 255));
  __CPROVER_assume((sec_r001818_18_2 >= 0) && (sec_r001818_18_2 <= 255));
  __CPROVER_assume((sec_r001818_19_1 >= 0) && (sec_r001818_19_1 <= 255));
  __CPROVER_assume((sec_r001818_19_2 >= 0) && (sec_r001818_19_2 <= 255));
  struct AudioFrame_R001818_1813_0 st_var_0_1 = {0};
  struct AudioFrame_R001818_1813_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001818_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001818_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001818_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001818_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001818_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001818_0_2 + 7) & 15;
  struct Vector3D_R001818_1813_1 st_var_1_1 = {0};
  struct Vector3D_R001818_1813_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001818_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001818_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001818_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001818_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001818_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001818_0_2 + 9) & 15;
  union PacketPayload_R001818_1813_0 u_var_1;
  union PacketPayload_R001818_1813_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001818_1813_0(sec_r001818_0_1, pub_r001818_1_1);
  int helper_flow_0_2 = fn_R001818_1813_0(sec_r001818_0_2, pub_r001818_1_2);
  fn_R001818_1813_0_2(sec_r001818_0_1, pub_r001818_1_1, sec_r001818_0_2, pub_r001818_1_2);
  int helper_flow_1_1 = fn_R001818_1813_1(sec_r001818_1_1, sec_r001818_2_1);
  int helper_flow_1_2 = fn_R001818_1813_1(sec_r001818_1_2, sec_r001818_2_2);
  fn_R001818_1813_1_2(sec_r001818_1_1, sec_r001818_2_1, sec_r001818_1_2, sec_r001818_2_2);
  int helper_flow_2_1 = fn_R001818_1813_2(sec_r001818_2_1, pub_r001818_3_1, pub_r001818_4_1);
  int helper_flow_2_2 = fn_R001818_1813_2(sec_r001818_2_2, pub_r001818_3_2, pub_r001818_4_2);
  fn_R001818_1813_2_2(sec_r001818_2_1, pub_r001818_3_1, pub_r001818_4_1, sec_r001818_2_2, pub_r001818_3_2, pub_r001818_4_2);
  int helper_flow_3_1 = fn_R001818_1813_3(sec_r001818_3_1, pub_r001818_4_1, pub_r001818_5_1, pub_r001818_6_1);
  int helper_flow_3_2 = fn_R001818_1813_3(sec_r001818_3_2, pub_r001818_4_2, pub_r001818_5_2, pub_r001818_6_2);
  fn_R001818_1813_3_2(sec_r001818_3_1, pub_r001818_4_1, pub_r001818_5_1, pub_r001818_6_1, sec_r001818_3_2, pub_r001818_4_2, pub_r001818_5_2, pub_r001818_6_2);
  int helper_flow_4_1 = fn_R001818_1813_4(sec_r001818_4_1, sec_r001818_5_1);
  int helper_flow_4_2 = fn_R001818_1813_4(sec_r001818_4_2, sec_r001818_5_2);
  fn_R001818_1813_4_2(sec_r001818_4_1, sec_r001818_5_1, sec_r001818_4_2, sec_r001818_5_2);
  int helper_flow_5_1 = fn_R001818_1813_5(sec_r001818_5_1, pub_r001818_6_1);
  int helper_flow_5_2 = fn_R001818_1813_5(sec_r001818_5_2, pub_r001818_6_2);
  fn_R001818_1813_5_2(sec_r001818_5_1, pub_r001818_6_1, sec_r001818_5_2, pub_r001818_6_2);
  int helper_flow_6_1 = fn_R001818_1813_6(sec_r001818_6_1, sec_r001818_7_1, pub_r001818_8_1);
  int helper_flow_6_2 = fn_R001818_1813_6(sec_r001818_6_2, sec_r001818_7_2, pub_r001818_8_2);
  fn_R001818_1813_6_2(sec_r001818_6_1, sec_r001818_7_1, pub_r001818_8_1, sec_r001818_6_2, sec_r001818_7_2, pub_r001818_8_2);
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (it_1 * 3)) + (sec_r001818_12_1 & 15)) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (it_2 * 3)) + (sec_r001818_12_2 & 15)) & 63;
    if ((sec_r001818_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_0_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_0_1) + 7) & 255;
    }
    if ((sec_r001818_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_0_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_0_2) + 7) & 255;
    }
  }

  int stage_v_1_1 = 0;
  int stage_v_1_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_1_1 = ((stage_v_1_1 + (it_1 * 3)) + (sec_r001818_2_1 & 15)) & 63;
    stage_v_1_2 = ((stage_v_1_2 + (it_2 * 3)) + (sec_r001818_2_2 & 15)) & 63;
    if ((sec_r001818_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_1_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_1_1) + 7) & 255;
    }
    if ((sec_r001818_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_1_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_1_2) + 7) & 255;
    }
  }

  int stage_v_2_1 = ((pub_r001818_11_1 * 2) + 24) & 63;
  int stage_v_2_2 = ((pub_r001818_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = 0;
  int stage_v_3_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_3_1 = ((stage_v_3_1 + (it_1 * 3)) + (sec_r001818_2_1 & 15)) & 63;
    stage_v_3_2 = ((stage_v_3_2 + (it_2 * 3)) + (sec_r001818_2_2 & 15)) & 63;
    if ((sec_r001818_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_3_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_3_1) + 7) & 255;
    }
    if ((sec_r001818_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_3_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_3_2) + 7) & 255;
    }
  }

  int stage_v_4_1 = 0;
  int stage_v_4_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_4_1 = ((stage_v_4_1 + (it_1 * 3)) + (helper_flow_1_1 & 15)) & 63;
    stage_v_4_2 = ((stage_v_4_2 + (it_2 * 3)) + (helper_flow_1_2 & 15)) & 63;
    if ((helper_flow_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_4_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_4_1) + 7) & 255;
    }
    if ((helper_flow_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_4_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_4_2) + 7) & 255;
    }
  }

  int stage_v_5_1 = ((pub_r001818_16_1 * 2) + 16) & 63;
  int stage_v_5_2 = ((pub_r001818_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_6_1 = ((stage_v_6_1 + (it_1 * 3)) + (sec_r001818_17_1 & 15)) & 63;
    stage_v_6_2 = ((stage_v_6_2 + (it_2 * 3)) + (sec_r001818_17_2 & 15)) & 63;
    if ((sec_r001818_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_6_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_6_1) + 7) & 255;
    }
    if ((sec_r001818_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_6_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_6_2) + 7) & 255;
    }
  }

  int stage_v_7_1 = 0;
  int stage_v_7_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_7_1 = ((stage_v_7_1 + (it_1 * 3)) + (helper_flow_2_1 & 15)) & 63;
    stage_v_7_2 = ((stage_v_7_2 + (it_2 * 3)) + (helper_flow_2_2 & 15)) & 63;
    if ((helper_flow_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_7_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_7_1) + 7) & 255;
    }
    if ((helper_flow_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_7_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_7_2) + 7) & 255;
    }
  }

  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (it_1 * 3)) + (sec_r001818_19_1 & 15)) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (it_2 * 3)) + (sec_r001818_19_2 & 15)) & 63;
    if ((sec_r001818_19_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_8_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_8_1) + 7) & 255;
    }
    if ((sec_r001818_19_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_8_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_8_2) + 7) & 255;
    }
  }

  int stage_v_9_1 = ((pub_r001818_14_1 * 2) + 43) & 63;
  int stage_v_9_2 = ((pub_r001818_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (it_1 * 3)) + (sec_r001818_11_1 & 15)) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (it_2 * 3)) + (sec_r001818_11_2 & 15)) & 63;
    if ((sec_r001818_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_10_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_10_1) + 7) & 255;
    }
    if ((sec_r001818_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_10_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_10_2) + 7) & 255;
    }
  }

  int stage_v_11_1 = ((pub_r001818_15_1 * 2) + 28) & 63;
  int stage_v_11_2 = ((pub_r001818_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (it_1 * 3)) + (sec_r001818_18_1 & 15)) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (it_2 * 3)) + (sec_r001818_18_2 & 15)) & 63;
    if ((sec_r001818_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_12_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_12_1) + 7) & 255;
    }
    if ((sec_r001818_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_12_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_12_2) + 7) & 255;
    }
  }

  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (it_1 * 3)) + (sec_r001818_14_1 & 15)) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (it_2 * 3)) + (sec_r001818_14_2 & 15)) & 63;
    if ((sec_r001818_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_13_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_13_1) + 7) & 255;
    }
    if ((sec_r001818_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_13_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_13_2) + 7) & 255;
    }
  }

  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (it_1 * 3)) + (stage_v_4_1 & 15)) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (it_2 * 3)) + (stage_v_4_2 & 15)) & 63;
    if ((stage_v_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_14_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_14_1) + 7) & 255;
    }
    if ((stage_v_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_14_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_14_2) + 7) & 255;
    }
  }

  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (it_1 * 3)) + (stage_v_4_1 & 15)) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (it_2 * 3)) + (stage_v_4_2 & 15)) & 63;
    if ((stage_v_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_15_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_15_1) + 7) & 255;
    }
    if ((stage_v_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_15_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_15_2) + 7) & 255;
    }
  }

  int stage_v_16_1 = ((pub_r001818_22_1 * 2) + 26) & 63;
  int stage_v_16_2 = ((pub_r001818_22_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_17_1 = ((stage_v_17_1 + (it_1 * 3)) + (sec_r001818_2_1 & 15)) & 63;
    stage_v_17_2 = ((stage_v_17_2 + (it_2 * 3)) + (sec_r001818_2_2 & 15)) & 63;
    if ((sec_r001818_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_17_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_17_1) + 7) & 255;
    }
    if ((sec_r001818_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_17_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_17_2) + 7) & 255;
    }
  }

  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_18_1 = ((stage_v_18_1 + (it_1 * 3)) + (sec_r001818_9_1 & 15)) & 63;
    stage_v_18_2 = ((stage_v_18_2 + (it_2 * 3)) + (sec_r001818_9_2 & 15)) & 63;
    if ((sec_r001818_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_18_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_18_1) + 7) & 255;
    }
    if ((sec_r001818_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_18_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_18_2) + 7) & 255;
    }
  }

  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (it_1 * 3)) + (sec_r001818_1_1 & 15)) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (it_2 * 3)) + (sec_r001818_1_2 & 15)) & 63;
    if ((sec_r001818_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_19_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_19_1) + 7) & 255;
    }
    if ((sec_r001818_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_19_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_19_2) + 7) & 255;
    }
  }

  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (it_1 * 3)) + (sec_r001818_14_1 & 15)) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (it_2 * 3)) + (sec_r001818_14_2 & 15)) & 63;
    if ((sec_r001818_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_20_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_20_1) + 7) & 255;
    }
    if ((sec_r001818_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_20_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_20_2) + 7) & 255;
    }
  }

  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_21_1 = ((stage_v_21_1 + (it_1 * 3)) + (stage_v_3_1 & 15)) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (it_2 * 3)) + (stage_v_3_2 & 15)) & 63;
    if ((stage_v_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_21_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_21_1) + 7) & 255;
    }
    if ((stage_v_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_21_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_21_2) + 7) & 255;
    }
  }

  int stage_v_22_1 = ((pub_r001818_18_1 * 2) + 43) & 63;
  int stage_v_22_2 = ((pub_r001818_18_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (it_1 * 3)) + (sec_r001818_12_1 & 15)) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (it_2 * 3)) + (sec_r001818_12_2 & 15)) & 63;
    if ((sec_r001818_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_23_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_23_1) + 7) & 255;
    }
    if ((sec_r001818_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_23_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_23_2) + 7) & 255;
    }
  }

  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (it_1 * 3)) + (helper_flow_4_1 & 15)) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (it_2 * 3)) + (helper_flow_4_2 & 15)) & 63;
    if ((helper_flow_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_24_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_24_1) + 7) & 255;
    }
    if ((helper_flow_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_24_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_24_2) + 7) & 255;
    }
  }

  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_25_1 = ((stage_v_25_1 + (it_1 * 3)) + (sec_r001818_0_1 & 15)) & 63;
    stage_v_25_2 = ((stage_v_25_2 + (it_2 * 3)) + (sec_r001818_0_2 & 15)) & 63;
    if ((sec_r001818_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_25_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_25_1) + 7) & 255;
    }
    if ((sec_r001818_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_25_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_25_2) + 7) & 255;
    }
  }

  int stage_v_26_1 = ((pub_r001818_14_1 * 2) + 39) & 63;
  int stage_v_26_2 = ((pub_r001818_14_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001818_16_1 * 2) + 22) & 63;
  int stage_v_27_2 = ((pub_r001818_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_28_1 = ((stage_v_28_1 + (it_1 * 3)) + (sec_r001818_4_1 & 15)) & 63;
    stage_v_28_2 = ((stage_v_28_2 + (it_2 * 3)) + (sec_r001818_4_2 & 15)) & 63;
    if ((sec_r001818_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_28_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_28_1) + 7) & 255;
    }
    if ((sec_r001818_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_28_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_28_2) + 7) & 255;
    }
  }

  int stage_v_29_1 = ((pub_r001818_16_1 * 2) + 21) & 63;
  int stage_v_29_2 = ((pub_r001818_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_30_1 = ((stage_v_30_1 + (it_1 * 3)) + (sec_r001818_5_1 & 15)) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (it_2 * 3)) + (sec_r001818_5_2 & 15)) & 63;
    if ((sec_r001818_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_30_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_30_1) + 7) & 255;
    }
    if ((sec_r001818_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_30_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_30_2) + 7) & 255;
    }
  }

  int stage_v_31_1 = ((pub_r001818_2_1 * 2) + 32) & 63;
  int stage_v_31_2 = ((pub_r001818_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_32_1 = ((stage_v_32_1 + (it_1 * 3)) + (helper_flow_4_1 & 15)) & 63;
    stage_v_32_2 = ((stage_v_32_2 + (it_2 * 3)) + (helper_flow_4_2 & 15)) & 63;
    if ((helper_flow_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_32_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_32_1) + 7) & 255;
    }
    if ((helper_flow_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_32_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_32_2) + 7) & 255;
    }
  }

  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_33_1 = ((stage_v_33_1 + (it_1 * 3)) + (sec_r001818_8_1 & 15)) & 63;
    stage_v_33_2 = ((stage_v_33_2 + (it_2 * 3)) + (sec_r001818_8_2 & 15)) & 63;
    if ((sec_r001818_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_33_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_33_1) + 7) & 255;
    }
    if ((sec_r001818_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_33_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_33_2) + 7) & 255;
    }
  }

  int stage_v_34_1 = ((pub_r001818_3_1 * 2) + 7) & 63;
  int stage_v_34_2 = ((pub_r001818_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001818_8_1 * 2) + 17) & 63;
  int stage_v_35_2 = ((pub_r001818_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (it_1 * 3)) + (sec_r001818_8_1 & 15)) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (it_2 * 3)) + (sec_r001818_8_2 & 15)) & 63;
    if ((sec_r001818_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_36_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_36_1) + 7) & 255;
    }
    if ((sec_r001818_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_36_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_36_2) + 7) & 255;
    }
  }

  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_37_1 = ((stage_v_37_1 + (it_1 * 3)) + (sec_r001818_18_1 & 15)) & 63;
    stage_v_37_2 = ((stage_v_37_2 + (it_2 * 3)) + (sec_r001818_18_2 & 15)) & 63;
    if ((sec_r001818_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_37_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_37_1) + 7) & 255;
    }
    if ((sec_r001818_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_37_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_37_2) + 7) & 255;
    }
  }

  int stage_v_38_1 = ((pub_r001818_4_1 * 2) + 12) & 63;
  int stage_v_38_2 = ((pub_r001818_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001818_13_1 * 2) + 7) & 63;
  int stage_v_39_2 = ((pub_r001818_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_40_1 = ((stage_v_40_1 + (it_1 * 3)) + (stage_v_23_1 & 15)) & 63;
    stage_v_40_2 = ((stage_v_40_2 + (it_2 * 3)) + (stage_v_23_2 & 15)) & 63;
    if ((stage_v_23_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_40_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_40_1) + 7) & 255;
    }
    if ((stage_v_23_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_40_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_40_2) + 7) & 255;
    }
  }

  int stage_v_41_1 = ((pub_r001818_16_1 * 2) + 36) & 63;
  int stage_v_41_2 = ((pub_r001818_16_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_42_1 = ((stage_v_42_1 + (it_1 * 3)) + (stage_v_37_1 & 15)) & 63;
    stage_v_42_2 = ((stage_v_42_2 + (it_2 * 3)) + (stage_v_37_2 & 15)) & 63;
    if ((stage_v_37_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_42_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_42_1) + 7) & 255;
    }
    if ((stage_v_37_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_42_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_42_2) + 7) & 255;
    }
  }

  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (it_1 * 3)) + (stage_v_40_1 & 15)) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (it_2 * 3)) + (stage_v_40_2 & 15)) & 63;
    if ((stage_v_40_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_43_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_43_1) + 7) & 255;
    }
    if ((stage_v_40_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_43_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_43_2) + 7) & 255;
    }
  }

  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_44_1 = ((stage_v_44_1 + (it_1 * 3)) + (sec_r001818_8_1 & 15)) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (it_2 * 3)) + (sec_r001818_8_2 & 15)) & 63;
    if ((sec_r001818_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_44_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_44_1) + 7) & 255;
    }
    if ((sec_r001818_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_44_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_44_2) + 7) & 255;
    }
  }

  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_45_1 = ((stage_v_45_1 + (it_1 * 3)) + (stage_v_10_1 & 15)) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (it_2 * 3)) + (stage_v_10_2 & 15)) & 63;
    if ((stage_v_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_45_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_45_1) + 7) & 255;
    }
    if ((stage_v_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_45_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_45_2) + 7) & 255;
    }
  }

  int stage_v_46_1 = ((pub_r001818_12_1 * 2) + 21) & 63;
  int stage_v_46_2 = ((pub_r001818_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001818_17_1 * 2) + 41) & 63;
  int stage_v_47_2 = ((pub_r001818_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (it_1 * 3)) + (sec_r001818_4_1 & 15)) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (it_2 * 3)) + (sec_r001818_4_2 & 15)) & 63;
    if ((sec_r001818_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_48_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_48_1) + 7) & 255;
    }
    if ((sec_r001818_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_48_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_48_2) + 7) & 255;
    }
  }

  int stage_v_49_1 = ((pub_r001818_3_1 * 2) + 23) & 63;
  int stage_v_49_2 = ((pub_r001818_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001818_15_1 * 2) + 34) & 63;
  int stage_v_50_2 = ((pub_r001818_15_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_51_1 = ((stage_v_51_1 + (it_1 * 3)) + (helper_flow_3_1 & 15)) & 63;
    stage_v_51_2 = ((stage_v_51_2 + (it_2 * 3)) + (helper_flow_3_2 & 15)) & 63;
    if ((helper_flow_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_51_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_51_1) + 7) & 255;
    }
    if ((helper_flow_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_51_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_51_2) + 7) & 255;
    }
  }

  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_52_1 = ((stage_v_52_1 + (it_1 * 3)) + (stage_v_21_1 & 15)) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (it_2 * 3)) + (stage_v_21_2 & 15)) & 63;
    if ((stage_v_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_52_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_52_1) + 7) & 255;
    }
    if ((stage_v_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_52_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_52_2) + 7) & 255;
    }
  }

  int stage_v_53_1 = ((pub_r001818_20_1 * 2) + 33) & 63;
  int stage_v_53_2 = ((pub_r001818_20_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_54_1 = ((stage_v_54_1 + (it_1 * 3)) + (sec_r001818_3_1 & 15)) & 63;
    stage_v_54_2 = ((stage_v_54_2 + (it_2 * 3)) + (sec_r001818_3_2 & 15)) & 63;
    if ((sec_r001818_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_54_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_54_1) + 7) & 255;
    }
    if ((sec_r001818_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_54_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_54_2) + 7) & 255;
    }
  }

  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_55_1 = ((stage_v_55_1 + (it_1 * 3)) + (sec_r001818_10_1 & 15)) & 63;
    stage_v_55_2 = ((stage_v_55_2 + (it_2 * 3)) + (sec_r001818_10_2 & 15)) & 63;
    if ((sec_r001818_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_55_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_55_1) + 7) & 255;
    }
    if ((sec_r001818_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_55_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_55_2) + 7) & 255;
    }
  }

  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_56_1 = ((stage_v_56_1 + (it_1 * 3)) + (sec_r001818_0_1 & 15)) & 63;
    stage_v_56_2 = ((stage_v_56_2 + (it_2 * 3)) + (sec_r001818_0_2 & 15)) & 63;
    if ((sec_r001818_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_56_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_56_1) + 7) & 255;
    }
    if ((sec_r001818_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_56_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_56_2) + 7) & 255;
    }
  }

  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_57_1 = ((stage_v_57_1 + (it_1 * 3)) + (helper_flow_0_1 & 15)) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (it_2 * 3)) + (helper_flow_0_2 & 15)) & 63;
    if ((helper_flow_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_57_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_57_1) + 7) & 255;
    }
    if ((helper_flow_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_57_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_57_2) + 7) & 255;
    }
  }

  int stage_v_58_1 = ((pub_r001818_2_1 * 2) + 13) & 63;
  int stage_v_58_2 = ((pub_r001818_2_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_59_1 = ((stage_v_59_1 + (it_1 * 3)) + (stage_v_23_1 & 15)) & 63;
    stage_v_59_2 = ((stage_v_59_2 + (it_2 * 3)) + (stage_v_23_2 & 15)) & 63;
    if ((stage_v_23_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_59_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_59_1) + 7) & 255;
    }
    if ((stage_v_23_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_59_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_59_2) + 7) & 255;
    }
  }

  int stage_v_60_1 = ((pub_r001818_1_1 * 2) + 9) & 63;
  int stage_v_60_2 = ((pub_r001818_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001818_12_1 * 2) + 13) & 63;
  int stage_v_61_2 = ((pub_r001818_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_62_1 = ((stage_v_62_1 + (it_1 * 3)) + (stage_v_59_1 & 15)) & 63;
    stage_v_62_2 = ((stage_v_62_2 + (it_2 * 3)) + (stage_v_59_2 & 15)) & 63;
    if ((stage_v_59_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_62_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_62_1) + 7) & 255;
    }
    if ((stage_v_59_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_62_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_62_2) + 7) & 255;
    }
  }

  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_63_1 = ((stage_v_63_1 + (it_1 * 3)) + (stage_v_48_1 & 15)) & 63;
    stage_v_63_2 = ((stage_v_63_2 + (it_2 * 3)) + (stage_v_48_2 & 15)) & 63;
    if ((stage_v_48_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_63_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_63_1) + 7) & 255;
    }
    if ((stage_v_48_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_63_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_63_2) + 7) & 255;
    }
  }

  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_64_1 = ((stage_v_64_1 + (it_1 * 3)) + (helper_flow_2_1 & 15)) & 63;
    stage_v_64_2 = ((stage_v_64_2 + (it_2 * 3)) + (helper_flow_2_2 & 15)) & 63;
    if ((helper_flow_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_64_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_64_1) + 7) & 255;
    }
    if ((helper_flow_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_64_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_64_2) + 7) & 255;
    }
  }

  int stage_v_65_1 = ((pub_r001818_11_1 * 2) + 25) & 63;
  int stage_v_65_2 = ((pub_r001818_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_66_1 = ((stage_v_66_1 + (it_1 * 3)) + (sec_r001818_18_1 & 15)) & 63;
    stage_v_66_2 = ((stage_v_66_2 + (it_2 * 3)) + (sec_r001818_18_2 & 15)) & 63;
    if ((sec_r001818_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_66_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_66_1) + 7) & 255;
    }
    if ((sec_r001818_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_66_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_66_2) + 7) & 255;
    }
  }

  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_67_1 = ((stage_v_67_1 + (it_1 * 3)) + (stage_v_44_1 & 15)) & 63;
    stage_v_67_2 = ((stage_v_67_2 + (it_2 * 3)) + (stage_v_44_2 & 15)) & 63;
    if ((stage_v_44_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_67_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_67_1) + 7) & 255;
    }
    if ((stage_v_44_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_67_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_67_2) + 7) & 255;
    }
  }

  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (it_1 * 3)) + (stage_v_36_1 & 15)) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (it_2 * 3)) + (stage_v_36_2 & 15)) & 63;
    if ((stage_v_36_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_68_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_68_1) + 7) & 255;
    }
    if ((stage_v_36_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_68_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_68_2) + 7) & 255;
    }
  }

  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_69_1 = ((stage_v_69_1 + (it_1 * 3)) + (sec_r001818_12_1 & 15)) & 63;
    stage_v_69_2 = ((stage_v_69_2 + (it_2 * 3)) + (sec_r001818_12_2 & 15)) & 63;
    if ((sec_r001818_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_69_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_69_1) + 7) & 255;
    }
    if ((sec_r001818_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_69_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_69_2) + 7) & 255;
    }
  }

  int stage_v_70_1 = ((pub_r001818_0_1 * 2) + 12) & 63;
  int stage_v_70_2 = ((pub_r001818_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_71_1 = ((stage_v_71_1 + (it_1 * 3)) + (sec_r001818_8_1 & 15)) & 63;
    stage_v_71_2 = ((stage_v_71_2 + (it_2 * 3)) + (sec_r001818_8_2 & 15)) & 63;
    if ((sec_r001818_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_71_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_71_1) + 7) & 255;
    }
    if ((sec_r001818_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_71_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_71_2) + 7) & 255;
    }
  }

  int stage_v_72_1 = ((pub_r001818_5_1 * 2) + 42) & 63;
  int stage_v_72_2 = ((pub_r001818_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_73_1 = ((stage_v_73_1 + (it_1 * 3)) + (helper_flow_1_1 & 15)) & 63;
    stage_v_73_2 = ((stage_v_73_2 + (it_2 * 3)) + (helper_flow_1_2 & 15)) & 63;
    if ((helper_flow_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_73_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_73_1) + 7) & 255;
    }
    if ((helper_flow_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_73_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_73_2) + 7) & 255;
    }
  }

  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_74_1 = ((stage_v_74_1 + (it_1 * 3)) + (stage_v_0_1 & 15)) & 63;
    stage_v_74_2 = ((stage_v_74_2 + (it_2 * 3)) + (stage_v_0_2 & 15)) & 63;
    if ((stage_v_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_74_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_74_1) + 7) & 255;
    }
    if ((stage_v_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_74_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_74_2) + 7) & 255;
    }
  }

  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_75_1 = ((stage_v_75_1 + (it_1 * 3)) + (stage_v_30_1 & 15)) & 63;
    stage_v_75_2 = ((stage_v_75_2 + (it_2 * 3)) + (stage_v_30_2 & 15)) & 63;
    if ((stage_v_30_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_75_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_75_1) + 7) & 255;
    }
    if ((stage_v_30_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_75_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_75_2) + 7) & 255;
    }
  }

  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_76_1 = ((stage_v_76_1 + (it_1 * 3)) + (stage_v_21_1 & 15)) & 63;
    stage_v_76_2 = ((stage_v_76_2 + (it_2 * 3)) + (stage_v_21_2 & 15)) & 63;
    if ((stage_v_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_76_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_76_1) + 7) & 255;
    }
    if ((stage_v_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_76_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_76_2) + 7) & 255;
    }
  }

  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_77_1 = ((stage_v_77_1 + (it_1 * 3)) + (stage_v_48_1 & 15)) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (it_2 * 3)) + (stage_v_48_2 & 15)) & 63;
    if ((stage_v_48_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_77_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_77_1) + 7) & 255;
    }
    if ((stage_v_48_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_77_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_77_2) + 7) & 255;
    }
  }

  int stage_v_78_1 = ((pub_r001818_8_1 * 2) + 23) & 63;
  int stage_v_78_2 = ((pub_r001818_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001818_10_1 * 2) + 37) & 63;
  int stage_v_79_2 = ((pub_r001818_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_80_1 = ((stage_v_80_1 + (it_1 * 3)) + (stage_v_71_1 & 15)) & 63;
    stage_v_80_2 = ((stage_v_80_2 + (it_2 * 3)) + (stage_v_71_2 & 15)) & 63;
    if ((stage_v_71_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_80_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_80_1) + 7) & 255;
    }
    if ((stage_v_71_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_80_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_80_2) + 7) & 255;
    }
  }

  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_81_1 = ((stage_v_81_1 + (it_1 * 3)) + (sec_r001818_4_1 & 15)) & 63;
    stage_v_81_2 = ((stage_v_81_2 + (it_2 * 3)) + (sec_r001818_4_2 & 15)) & 63;
    if ((sec_r001818_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_81_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_81_1) + 7) & 255;
    }
    if ((sec_r001818_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_81_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_81_2) + 7) & 255;
    }
  }

  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_82_1 = ((stage_v_82_1 + (it_1 * 3)) + (stage_v_52_1 & 15)) & 63;
    stage_v_82_2 = ((stage_v_82_2 + (it_2 * 3)) + (stage_v_52_2 & 15)) & 63;
    if ((stage_v_52_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_82_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_82_1) + 7) & 255;
    }
    if ((stage_v_52_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_82_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_82_2) + 7) & 255;
    }
  }

  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_83_1 = ((stage_v_83_1 + (it_1 * 3)) + (stage_v_13_1 & 15)) & 63;
    stage_v_83_2 = ((stage_v_83_2 + (it_2 * 3)) + (stage_v_13_2 & 15)) & 63;
    if ((stage_v_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_83_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_83_1) + 7) & 255;
    }
    if ((stage_v_13_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_83_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_83_2) + 7) & 255;
    }
  }

  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_84_1 = ((stage_v_84_1 + (it_1 * 3)) + (sec_r001818_12_1 & 15)) & 63;
    stage_v_84_2 = ((stage_v_84_2 + (it_2 * 3)) + (sec_r001818_12_2 & 15)) & 63;
    if ((sec_r001818_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_84_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_84_1) + 7) & 255;
    }
    if ((sec_r001818_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_84_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_84_2) + 7) & 255;
    }
  }

  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_85_1 = ((stage_v_85_1 + (it_1 * 3)) + (stage_v_8_1 & 15)) & 63;
    stage_v_85_2 = ((stage_v_85_2 + (it_2 * 3)) + (stage_v_8_2 & 15)) & 63;
    if ((stage_v_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_85_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_85_1) + 7) & 255;
    }
    if ((stage_v_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_85_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_85_2) + 7) & 255;
    }
  }

  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_86_1 = ((stage_v_86_1 + (it_1 * 3)) + (stage_v_63_1 & 15)) & 63;
    stage_v_86_2 = ((stage_v_86_2 + (it_2 * 3)) + (stage_v_63_2 & 15)) & 63;
    if ((stage_v_63_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_86_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_86_1) + 7) & 255;
    }
    if ((stage_v_63_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_86_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_86_2) + 7) & 255;
    }
  }

  int stage_v_87_1 = ((pub_r001818_3_1 * 2) + 5) & 63;
  int stage_v_87_2 = ((pub_r001818_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_88_1 = ((stage_v_88_1 + (it_1 * 3)) + (helper_flow_1_1 & 15)) & 63;
    stage_v_88_2 = ((stage_v_88_2 + (it_2 * 3)) + (helper_flow_1_2 & 15)) & 63;
    if ((helper_flow_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_88_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_88_1) + 7) & 255;
    }
    if ((helper_flow_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_88_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_88_2) + 7) & 255;
    }
  }

  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_89_1 = ((stage_v_89_1 + (it_1 * 3)) + (sec_r001818_5_1 & 15)) & 63;
    stage_v_89_2 = ((stage_v_89_2 + (it_2 * 3)) + (sec_r001818_5_2 & 15)) & 63;
    if ((sec_r001818_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_89_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_89_1) + 7) & 255;
    }
    if ((sec_r001818_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_89_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_89_2) + 7) & 255;
    }
  }

  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_90_1 = ((stage_v_90_1 + (it_1 * 3)) + (stage_v_7_1 & 15)) & 63;
    stage_v_90_2 = ((stage_v_90_2 + (it_2 * 3)) + (stage_v_7_2 & 15)) & 63;
    if ((stage_v_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_90_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_90_1) + 7) & 255;
    }
    if ((stage_v_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_90_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_90_2) + 7) & 255;
    }
  }

  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_91_1 = ((stage_v_91_1 + (it_1 * 3)) + (stage_v_17_1 & 15)) & 63;
    stage_v_91_2 = ((stage_v_91_2 + (it_2 * 3)) + (stage_v_17_2 & 15)) & 63;
    if ((stage_v_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_91_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_91_1) + 7) & 255;
    }
    if ((stage_v_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_91_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_91_2) + 7) & 255;
    }
  }

  int stage_v_92_1 = ((pub_r001818_22_1 * 2) + 26) & 63;
  int stage_v_92_2 = ((pub_r001818_22_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001818_15_1 * 2) + 22) & 63;
  int stage_v_93_2 = ((pub_r001818_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001818_3_1 * 2) + 5) & 63;
  int stage_v_94_2 = ((pub_r001818_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_95_1 = ((stage_v_95_1 + (it_1 * 3)) + (stage_v_42_1 & 15)) & 63;
    stage_v_95_2 = ((stage_v_95_2 + (it_2 * 3)) + (stage_v_42_2 & 15)) & 63;
    if ((stage_v_42_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_95_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_95_1) + 7) & 255;
    }
    if ((stage_v_42_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_95_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_95_2) + 7) & 255;
    }
  }

  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_96_1 = ((stage_v_96_1 + (it_1 * 3)) + (stage_v_43_1 & 15)) & 63;
    stage_v_96_2 = ((stage_v_96_2 + (it_2 * 3)) + (stage_v_43_2 & 15)) & 63;
    if ((stage_v_43_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_96_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_96_1) + 7) & 255;
    }
    if ((stage_v_43_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_96_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_96_2) + 7) & 255;
    }
  }

  int stage_v_97_1 = ((pub_r001818_14_1 * 2) + 5) & 63;
  int stage_v_97_2 = ((pub_r001818_14_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_98_1 = ((stage_v_98_1 + (it_1 * 3)) + (stage_v_84_1 & 15)) & 63;
    stage_v_98_2 = ((stage_v_98_2 + (it_2 * 3)) + (stage_v_84_2 & 15)) & 63;
    if ((stage_v_84_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_98_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_98_1) + 7) & 255;
    }
    if ((stage_v_84_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_98_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_98_2) + 7) & 255;
    }
  }

  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_99_1 = ((stage_v_99_1 + (it_1 * 3)) + (stage_v_82_1 & 15)) & 63;
    stage_v_99_2 = ((stage_v_99_2 + (it_2 * 3)) + (stage_v_82_2 & 15)) & 63;
    if ((stage_v_82_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_99_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_99_1) + 7) & 255;
    }
    if ((stage_v_82_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_99_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_99_2) + 7) & 255;
    }
  }

  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_100_1 = ((stage_v_100_1 + (it_1 * 3)) + (stage_v_14_1 & 15)) & 63;
    stage_v_100_2 = ((stage_v_100_2 + (it_2 * 3)) + (stage_v_14_2 & 15)) & 63;
    if ((stage_v_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_100_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_100_1) + 7) & 255;
    }
    if ((stage_v_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_100_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_100_2) + 7) & 255;
    }
  }

  int stage_v_101_1 = ((pub_r001818_5_1 * 2) + 14) & 63;
  int stage_v_101_2 = ((pub_r001818_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_102_1 = ((stage_v_102_1 + (it_1 * 3)) + (stage_v_7_1 & 15)) & 63;
    stage_v_102_2 = ((stage_v_102_2 + (it_2 * 3)) + (stage_v_7_2 & 15)) & 63;
    if ((stage_v_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_102_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_102_1) + 7) & 255;
    }
    if ((stage_v_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_102_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_102_2) + 7) & 255;
    }
  }

  int stage_v_103_1 = ((pub_r001818_3_1 * 2) + 16) & 63;
  int stage_v_103_2 = ((pub_r001818_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_104_1 = ((stage_v_104_1 + (it_1 * 3)) + (stage_v_10_1 & 15)) & 63;
    stage_v_104_2 = ((stage_v_104_2 + (it_2 * 3)) + (stage_v_10_2 & 15)) & 63;
    if ((stage_v_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_104_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_104_1) + 7) & 255;
    }
    if ((stage_v_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_104_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_104_2) + 7) & 255;
    }
  }

  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_105_1 = ((stage_v_105_1 + (it_1 * 3)) + (stage_v_36_1 & 15)) & 63;
    stage_v_105_2 = ((stage_v_105_2 + (it_2 * 3)) + (stage_v_36_2 & 15)) & 63;
    if ((stage_v_36_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_105_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_105_1) + 7) & 255;
    }
    if ((stage_v_36_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_105_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_105_2) + 7) & 255;
    }
  }

  int stage_v_106_1 = ((pub_r001818_15_1 * 2) + 23) & 63;
  int stage_v_106_2 = ((pub_r001818_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_107_1 = ((stage_v_107_1 + (it_1 * 3)) + (stage_v_105_1 & 15)) & 63;
    stage_v_107_2 = ((stage_v_107_2 + (it_2 * 3)) + (stage_v_105_2 & 15)) & 63;
    if ((stage_v_105_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_107_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_107_1) + 7) & 255;
    }
    if ((stage_v_105_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_107_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_107_2) + 7) & 255;
    }
  }

  int stage_v_108_1 = ((pub_r001818_17_1 * 2) + 27) & 63;
  int stage_v_108_2 = ((pub_r001818_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001818_11_1 * 2) + 10) & 63;
  int stage_v_109_2 = ((pub_r001818_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001818_8_1 * 2) + 31) & 63;
  int stage_v_110_2 = ((pub_r001818_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_111_1 = ((stage_v_111_1 + (it_1 * 3)) + (stage_v_69_1 & 15)) & 63;
    stage_v_111_2 = ((stage_v_111_2 + (it_2 * 3)) + (stage_v_69_2 & 15)) & 63;
    if ((stage_v_69_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_111_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_111_1) + 7) & 255;
    }
    if ((stage_v_69_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_111_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_111_2) + 7) & 255;
    }
  }

  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_112_1 = ((stage_v_112_1 + (it_1 * 3)) + (stage_v_4_1 & 15)) & 63;
    stage_v_112_2 = ((stage_v_112_2 + (it_2 * 3)) + (stage_v_4_2 & 15)) & 63;
    if ((stage_v_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_112_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_112_1) + 7) & 255;
    }
    if ((stage_v_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_112_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_112_2) + 7) & 255;
    }
  }

  int stage_v_113_1 = ((pub_r001818_1_1 * 2) + 7) & 63;
  int stage_v_113_2 = ((pub_r001818_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_114_1 = ((stage_v_114_1 + (it_1 * 3)) + (stage_v_89_1 & 15)) & 63;
    stage_v_114_2 = ((stage_v_114_2 + (it_2 * 3)) + (stage_v_89_2 & 15)) & 63;
    if ((stage_v_89_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_114_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_114_1) + 7) & 255;
    }
    if ((stage_v_89_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_114_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_114_2) + 7) & 255;
    }
  }

  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_115_1 = ((stage_v_115_1 + (it_1 * 3)) + (stage_v_40_1 & 15)) & 63;
    stage_v_115_2 = ((stage_v_115_2 + (it_2 * 3)) + (stage_v_40_2 & 15)) & 63;
    if ((stage_v_40_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_115_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_115_1) + 7) & 255;
    }
    if ((stage_v_40_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_115_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_115_2) + 7) & 255;
    }
  }

  int stage_v_116_1 = ((pub_r001818_7_1 * 2) + 45) & 63;
  int stage_v_116_2 = ((pub_r001818_7_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001818_17_1 * 2) + 34) & 63;
  int stage_v_117_2 = ((pub_r001818_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_118_1 = ((stage_v_118_1 + (it_1 * 3)) + (stage_v_76_1 & 15)) & 63;
    stage_v_118_2 = ((stage_v_118_2 + (it_2 * 3)) + (stage_v_76_2 & 15)) & 63;
    if ((stage_v_76_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_118_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_118_1) + 7) & 255;
    }
    if ((stage_v_76_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_118_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_118_2) + 7) & 255;
    }
  }

  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_119_1 = ((stage_v_119_1 + (it_1 * 3)) + (stage_v_104_1 & 15)) & 63;
    stage_v_119_2 = ((stage_v_119_2 + (it_2 * 3)) + (stage_v_104_2 & 15)) & 63;
    if ((stage_v_104_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_119_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_119_1) + 7) & 255;
    }
    if ((stage_v_104_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_119_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_119_2) + 7) & 255;
    }
  }

  int stage_v_120_1 = ((pub_r001818_19_1 * 2) + 25) & 63;
  int stage_v_120_2 = ((pub_r001818_19_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_121_1 = ((stage_v_121_1 + (it_1 * 3)) + (stage_v_68_1 & 15)) & 63;
    stage_v_121_2 = ((stage_v_121_2 + (it_2 * 3)) + (stage_v_68_2 & 15)) & 63;
    if ((stage_v_68_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_121_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_121_1) + 7) & 255;
    }
    if ((stage_v_68_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_121_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_121_2) + 7) & 255;
    }
  }

  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_122_1 = ((stage_v_122_1 + (it_1 * 3)) + (stage_v_104_1 & 15)) & 63;
    stage_v_122_2 = ((stage_v_122_2 + (it_2 * 3)) + (stage_v_104_2 & 15)) & 63;
    if ((stage_v_104_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_122_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_122_1) + 7) & 255;
    }
    if ((stage_v_104_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_122_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_122_2) + 7) & 255;
    }
  }

  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_123_1 = ((stage_v_123_1 + (it_1 * 3)) + (stage_v_82_1 & 15)) & 63;
    stage_v_123_2 = ((stage_v_123_2 + (it_2 * 3)) + (stage_v_82_2 & 15)) & 63;
    if ((stage_v_82_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_123_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_123_1) + 7) & 255;
    }
    if ((stage_v_82_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_123_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_123_2) + 7) & 255;
    }
  }

  int stage_v_124_1 = ((pub_r001818_5_1 * 2) + 50) & 63;
  int stage_v_124_2 = ((pub_r001818_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_125_1 = ((stage_v_125_1 + (it_1 * 3)) + (sec_r001818_14_1 & 15)) & 63;
    stage_v_125_2 = ((stage_v_125_2 + (it_2 * 3)) + (sec_r001818_14_2 & 15)) & 63;
    if ((sec_r001818_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_125_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_125_1) + 7) & 255;
    }
    if ((sec_r001818_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_125_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_125_2) + 7) & 255;
    }
  }

  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_126_1 = ((stage_v_126_1 + (it_1 * 3)) + (sec_r001818_10_1 & 15)) & 63;
    stage_v_126_2 = ((stage_v_126_2 + (it_2 * 3)) + (sec_r001818_10_2 & 15)) & 63;
    if ((sec_r001818_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_126_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_126_1) + 7) & 255;
    }
    if ((sec_r001818_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_126_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_126_2) + 7) & 255;
    }
  }

  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_127_1 = ((stage_v_127_1 + (it_1 * 3)) + (sec_r001818_16_1 & 15)) & 63;
    stage_v_127_2 = ((stage_v_127_2 + (it_2 * 3)) + (sec_r001818_16_2 & 15)) & 63;
    if ((sec_r001818_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_127_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_127_1) + 7) & 255;
    }
    if ((sec_r001818_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_127_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_127_2) + 7) & 255;
    }
  }

  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_128_1 = ((stage_v_128_1 + (it_1 * 3)) + (stage_v_54_1 & 15)) & 63;
    stage_v_128_2 = ((stage_v_128_2 + (it_2 * 3)) + (stage_v_54_2 & 15)) & 63;
    if ((stage_v_54_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_128_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_128_1) + 7) & 255;
    }
    if ((stage_v_54_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_128_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_128_2) + 7) & 255;
    }
  }

  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_129_1 = ((stage_v_129_1 + (it_1 * 3)) + (sec_r001818_3_1 & 15)) & 63;
    stage_v_129_2 = ((stage_v_129_2 + (it_2 * 3)) + (sec_r001818_3_2 & 15)) & 63;
    if ((sec_r001818_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_129_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_129_1) + 7) & 255;
    }
    if ((sec_r001818_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_129_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_129_2) + 7) & 255;
    }
  }

  int stage_v_130_1 = ((pub_r001818_2_1 * 2) + 32) & 63;
  int stage_v_130_2 = ((pub_r001818_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_131_1 = ((stage_v_131_1 + (it_1 * 3)) + (stage_v_1_1 & 15)) & 63;
    stage_v_131_2 = ((stage_v_131_2 + (it_2 * 3)) + (stage_v_1_2 & 15)) & 63;
    if ((stage_v_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_131_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_131_1) + 7) & 255;
    }
    if ((stage_v_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_131_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_131_2) + 7) & 255;
    }
  }

  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_132_1 = ((stage_v_132_1 + (it_1 * 3)) + (stage_v_122_1 & 15)) & 63;
    stage_v_132_2 = ((stage_v_132_2 + (it_2 * 3)) + (stage_v_122_2 & 15)) & 63;
    if ((stage_v_122_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_132_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_132_1) + 7) & 255;
    }
    if ((stage_v_122_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_132_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_132_2) + 7) & 255;
    }
  }

  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_133_1 = ((stage_v_133_1 + (it_1 * 3)) + (stage_v_8_1 & 15)) & 63;
    stage_v_133_2 = ((stage_v_133_2 + (it_2 * 3)) + (stage_v_8_2 & 15)) & 63;
    if ((stage_v_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_133_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_133_1) + 7) & 255;
    }
    if ((stage_v_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_133_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_133_2) + 7) & 255;
    }
  }

  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_134_1 = ((stage_v_134_1 + (it_1 * 3)) + (sec_r001818_2_1 & 15)) & 63;
    stage_v_134_2 = ((stage_v_134_2 + (it_2 * 3)) + (sec_r001818_2_2 & 15)) & 63;
    if ((sec_r001818_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_134_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_134_1) + 7) & 255;
    }
    if ((sec_r001818_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_134_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_134_2) + 7) & 255;
    }
  }

  int stage_v_135_1 = ((pub_r001818_17_1 * 2) + 49) & 63;
  int stage_v_135_2 = ((pub_r001818_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_136_1 = ((stage_v_136_1 + (it_1 * 3)) + (stage_v_104_1 & 15)) & 63;
    stage_v_136_2 = ((stage_v_136_2 + (it_2 * 3)) + (stage_v_104_2 & 15)) & 63;
    if ((stage_v_104_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_136_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_136_1) + 7) & 255;
    }
    if ((stage_v_104_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_136_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_136_2) + 7) & 255;
    }
  }

  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_137_1 = ((stage_v_137_1 + (it_1 * 3)) + (stage_v_74_1 & 15)) & 63;
    stage_v_137_2 = ((stage_v_137_2 + (it_2 * 3)) + (stage_v_74_2 & 15)) & 63;
    if ((stage_v_74_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_137_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_137_1) + 7) & 255;
    }
    if ((stage_v_74_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_137_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_137_2) + 7) & 255;
    }
  }

  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_138_1 = ((stage_v_138_1 + (it_1 * 3)) + (stage_v_55_1 & 15)) & 63;
    stage_v_138_2 = ((stage_v_138_2 + (it_2 * 3)) + (stage_v_55_2 & 15)) & 63;
    if ((stage_v_55_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_138_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_138_1) + 7) & 255;
    }
    if ((stage_v_55_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_138_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_138_2) + 7) & 255;
    }
  }

  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_139_1 = ((stage_v_139_1 + (it_1 * 3)) + (stage_v_80_1 & 15)) & 63;
    stage_v_139_2 = ((stage_v_139_2 + (it_2 * 3)) + (stage_v_80_2 & 15)) & 63;
    if ((stage_v_80_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_139_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_139_1) + 7) & 255;
    }
    if ((stage_v_80_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_139_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_139_2) + 7) & 255;
    }
  }

  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_140_1 = ((stage_v_140_1 + (it_1 * 3)) + (stage_v_20_1 & 15)) & 63;
    stage_v_140_2 = ((stage_v_140_2 + (it_2 * 3)) + (stage_v_20_2 & 15)) & 63;
    if ((stage_v_20_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_140_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_140_1) + 7) & 255;
    }
    if ((stage_v_20_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_140_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_140_2) + 7) & 255;
    }
  }

  int stage_v_141_1 = ((pub_r001818_16_1 * 2) + 31) & 63;
  int stage_v_141_2 = ((pub_r001818_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001818_14_1 * 2) + 24) & 63;
  int stage_v_142_2 = ((pub_r001818_14_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_143_1 = ((stage_v_143_1 + (it_1 * 3)) + (stage_v_91_1 & 15)) & 63;
    stage_v_143_2 = ((stage_v_143_2 + (it_2 * 3)) + (stage_v_91_2 & 15)) & 63;
    if ((stage_v_91_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_143_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_143_1) + 7) & 255;
    }
    if ((stage_v_91_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_143_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_143_2) + 7) & 255;
    }
  }

  int stage_v_144_1 = ((pub_r001818_13_1 * 2) + 17) & 63;
  int stage_v_144_2 = ((pub_r001818_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_145_1 = ((stage_v_145_1 + (it_1 * 3)) + (stage_v_45_1 & 15)) & 63;
    stage_v_145_2 = ((stage_v_145_2 + (it_2 * 3)) + (stage_v_45_2 & 15)) & 63;
    if ((stage_v_45_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_145_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_145_1) + 7) & 255;
    }
    if ((stage_v_45_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_145_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_145_2) + 7) & 255;
    }
  }

  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_146_1 = ((stage_v_146_1 + (it_1 * 3)) + (stage_v_81_1 & 15)) & 63;
    stage_v_146_2 = ((stage_v_146_2 + (it_2 * 3)) + (stage_v_81_2 & 15)) & 63;
    if ((stage_v_81_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_146_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_146_1) + 7) & 255;
    }
    if ((stage_v_81_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_146_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_146_2) + 7) & 255;
    }
  }

  int stage_v_147_1 = ((pub_r001818_4_1 * 2) + 12) & 63;
  int stage_v_147_2 = ((pub_r001818_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001818_17_1 * 2) + 18) & 63;
  int stage_v_148_2 = ((pub_r001818_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001818_13_1 * 2) + 23) & 63;
  int stage_v_149_2 = ((pub_r001818_13_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001818_17_1 * 2) + 21) & 63;
  int stage_v_150_2 = ((pub_r001818_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001818_19_1 * 2) + 48) & 63;
  int stage_v_151_2 = ((pub_r001818_19_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001818_3_1 * 2) + 30) & 63;
  int stage_v_152_2 = ((pub_r001818_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_153_1 = ((stage_v_153_1 + (it_1 * 3)) + (stage_v_91_1 & 15)) & 63;
    stage_v_153_2 = ((stage_v_153_2 + (it_2 * 3)) + (stage_v_91_2 & 15)) & 63;
    if ((stage_v_91_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_153_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_153_1) + 7) & 255;
    }
    if ((stage_v_91_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_153_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_153_2) + 7) & 255;
    }
  }

  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_154_1 = ((stage_v_154_1 + (it_1 * 3)) + (stage_v_44_1 & 15)) & 63;
    stage_v_154_2 = ((stage_v_154_2 + (it_2 * 3)) + (stage_v_44_2 & 15)) & 63;
    if ((stage_v_44_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_154_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_154_1) + 7) & 255;
    }
    if ((stage_v_44_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_154_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_154_2) + 7) & 255;
    }
  }

  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_155_1 = ((stage_v_155_1 + (it_1 * 3)) + (stage_v_1_1 & 15)) & 63;
    stage_v_155_2 = ((stage_v_155_2 + (it_2 * 3)) + (stage_v_1_2 & 15)) & 63;
    if ((stage_v_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_155_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_155_1) + 7) & 255;
    }
    if ((stage_v_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_155_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_155_2) + 7) & 255;
    }
  }

  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_156_1 = ((stage_v_156_1 + (it_1 * 3)) + (helper_flow_5_1 & 15)) & 63;
    stage_v_156_2 = ((stage_v_156_2 + (it_2 * 3)) + (helper_flow_5_2 & 15)) & 63;
    if ((helper_flow_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_156_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_156_1) + 7) & 255;
    }
    if ((helper_flow_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_156_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_156_2) + 7) & 255;
    }
  }

  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_157_1 = ((stage_v_157_1 + (it_1 * 3)) + (stage_v_13_1 & 15)) & 63;
    stage_v_157_2 = ((stage_v_157_2 + (it_2 * 3)) + (stage_v_13_2 & 15)) & 63;
    if ((stage_v_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_157_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_157_1) + 7) & 255;
    }
    if ((stage_v_13_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_157_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_157_2) + 7) & 255;
    }
  }

  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_158_1 = ((stage_v_158_1 + (it_1 * 3)) + (stage_v_112_1 & 15)) & 63;
    stage_v_158_2 = ((stage_v_158_2 + (it_2 * 3)) + (stage_v_112_2 & 15)) & 63;
    if ((stage_v_112_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_158_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_158_1) + 7) & 255;
    }
    if ((stage_v_112_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_158_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_158_2) + 7) & 255;
    }
  }

  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_159_1 = ((stage_v_159_1 + (it_1 * 3)) + (stage_v_80_1 & 15)) & 63;
    stage_v_159_2 = ((stage_v_159_2 + (it_2 * 3)) + (stage_v_80_2 & 15)) & 63;
    if ((stage_v_80_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_159_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_159_1) + 7) & 255;
    }
    if ((stage_v_80_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_159_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_159_2) + 7) & 255;
    }
  }

  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_160_1 = ((stage_v_160_1 + (it_1 * 3)) + (stage_v_96_1 & 15)) & 63;
    stage_v_160_2 = ((stage_v_160_2 + (it_2 * 3)) + (stage_v_96_2 & 15)) & 63;
    if ((stage_v_96_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_160_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_160_1) + 7) & 255;
    }
    if ((stage_v_96_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_160_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_160_2) + 7) & 255;
    }
  }

  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_161_1 = ((stage_v_161_1 + (it_1 * 3)) + (stage_v_155_1 & 15)) & 63;
    stage_v_161_2 = ((stage_v_161_2 + (it_2 * 3)) + (stage_v_155_2 & 15)) & 63;
    if ((stage_v_155_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_161_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_161_1) + 7) & 255;
    }
    if ((stage_v_155_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_161_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_161_2) + 7) & 255;
    }
  }

  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_162_1 = ((stage_v_162_1 + (it_1 * 3)) + (stage_v_112_1 & 15)) & 63;
    stage_v_162_2 = ((stage_v_162_2 + (it_2 * 3)) + (stage_v_112_2 & 15)) & 63;
    if ((stage_v_112_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_162_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_162_1) + 7) & 255;
    }
    if ((stage_v_112_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_162_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_162_2) + 7) & 255;
    }
  }

  int stage_v_163_1 = ((pub_r001818_22_1 * 2) + 37) & 63;
  int stage_v_163_2 = ((pub_r001818_22_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_164_1 = ((stage_v_164_1 + (it_1 * 3)) + (helper_flow_0_1 & 15)) & 63;
    stage_v_164_2 = ((stage_v_164_2 + (it_2 * 3)) + (helper_flow_0_2 & 15)) & 63;
    if ((helper_flow_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_164_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_164_1) + 7) & 255;
    }
    if ((helper_flow_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_164_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_164_2) + 7) & 255;
    }
  }

  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_165_1 = ((stage_v_165_1 + (it_1 * 3)) + (stage_v_12_1 & 15)) & 63;
    stage_v_165_2 = ((stage_v_165_2 + (it_2 * 3)) + (stage_v_12_2 & 15)) & 63;
    if ((stage_v_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_165_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_165_1) + 7) & 255;
    }
    if ((stage_v_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_165_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_165_2) + 7) & 255;
    }
  }

  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_166_1 = ((stage_v_166_1 + (it_1 * 3)) + (sec_r001818_4_1 & 15)) & 63;
    stage_v_166_2 = ((stage_v_166_2 + (it_2 * 3)) + (sec_r001818_4_2 & 15)) & 63;
    if ((sec_r001818_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_166_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_166_1) + 7) & 255;
    }
    if ((sec_r001818_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_166_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_166_2) + 7) & 255;
    }
  }

  int stage_v_167_1 = ((pub_r001818_4_1 * 2) + 44) & 63;
  int stage_v_167_2 = ((pub_r001818_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = 0;
  int stage_v_168_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_168_1 = ((stage_v_168_1 + (it_1 * 3)) + (stage_v_80_1 & 15)) & 63;
    stage_v_168_2 = ((stage_v_168_2 + (it_2 * 3)) + (stage_v_80_2 & 15)) & 63;
    if ((stage_v_80_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_168_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_168_1) + 7) & 255;
    }
    if ((stage_v_80_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_168_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_168_2) + 7) & 255;
    }
  }

  int stage_v_169_1 = ((pub_r001818_1_1 * 2) + 16) & 63;
  int stage_v_169_2 = ((pub_r001818_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001818_15_1 * 2) + 44) & 63;
  int stage_v_170_2 = ((pub_r001818_15_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = 0;
  int stage_v_171_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_171_1 = ((stage_v_171_1 + (it_1 * 3)) + (stage_v_18_1 & 15)) & 63;
    stage_v_171_2 = ((stage_v_171_2 + (it_2 * 3)) + (stage_v_18_2 & 15)) & 63;
    if ((stage_v_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_171_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_171_1) + 7) & 255;
    }
    if ((stage_v_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_171_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_171_2) + 7) & 255;
    }
  }

  int stage_v_172_1 = 0;
  int stage_v_172_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_172_1 = ((stage_v_172_1 + (it_1 * 3)) + (sec_r001818_10_1 & 15)) & 63;
    stage_v_172_2 = ((stage_v_172_2 + (it_2 * 3)) + (sec_r001818_10_2 & 15)) & 63;
    if ((sec_r001818_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_172_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_172_1) + 7) & 255;
    }
    if ((sec_r001818_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_172_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_172_2) + 7) & 255;
    }
  }

  int stage_v_173_1 = ((pub_r001818_5_1 * 2) + 8) & 63;
  int stage_v_173_2 = ((pub_r001818_5_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001818_14_1 * 2) + 22) & 63;
  int stage_v_174_2 = ((pub_r001818_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = 0;
  int stage_v_175_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_175_1 = ((stage_v_175_1 + (it_1 * 3)) + (stage_v_143_1 & 15)) & 63;
    stage_v_175_2 = ((stage_v_175_2 + (it_2 * 3)) + (stage_v_143_2 & 15)) & 63;
    if ((stage_v_143_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_175_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_175_1) + 7) & 255;
    }
    if ((stage_v_143_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_175_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_175_2) + 7) & 255;
    }
  }

  int stage_v_176_1 = ((pub_r001818_19_1 * 2) + 34) & 63;
  int stage_v_176_2 = ((pub_r001818_19_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = 0;
  int stage_v_177_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_177_1 = ((stage_v_177_1 + (it_1 * 3)) + (stage_v_90_1 & 15)) & 63;
    stage_v_177_2 = ((stage_v_177_2 + (it_2 * 3)) + (stage_v_90_2 & 15)) & 63;
    if ((stage_v_90_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_177_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_177_1) + 7) & 255;
    }
    if ((stage_v_90_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_177_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_177_2) + 7) & 255;
    }
  }

  int stage_v_178_1 = 0;
  int stage_v_178_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_178_1 = ((stage_v_178_1 + (it_1 * 3)) + (stage_v_100_1 & 15)) & 63;
    stage_v_178_2 = ((stage_v_178_2 + (it_2 * 3)) + (stage_v_100_2 & 15)) & 63;
    if ((stage_v_100_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_178_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_178_1) + 7) & 255;
    }
    if ((stage_v_100_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_178_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_178_2) + 7) & 255;
    }
  }

  int stage_v_179_1 = 0;
  int stage_v_179_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_179_1 = ((stage_v_179_1 + (it_1 * 3)) + (helper_flow_1_1 & 15)) & 63;
    stage_v_179_2 = ((stage_v_179_2 + (it_2 * 3)) + (helper_flow_1_2 & 15)) & 63;
    if ((helper_flow_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_179_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_179_1) + 7) & 255;
    }
    if ((helper_flow_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_179_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_179_2) + 7) & 255;
    }
  }

  int stage_v_180_1 = 0;
  int stage_v_180_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_180_1 = ((stage_v_180_1 + (it_1 * 3)) + (stage_v_156_1 & 15)) & 63;
    stage_v_180_2 = ((stage_v_180_2 + (it_2 * 3)) + (stage_v_156_2 & 15)) & 63;
    if ((stage_v_156_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_180_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_180_1) + 7) & 255;
    }
    if ((stage_v_156_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_180_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_180_2) + 7) & 255;
    }
  }

  int stage_v_181_1 = 0;
  int stage_v_181_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_181_1 = ((stage_v_181_1 + (it_1 * 3)) + (stage_v_114_1 & 15)) & 63;
    stage_v_181_2 = ((stage_v_181_2 + (it_2 * 3)) + (stage_v_114_2 & 15)) & 63;
    if ((stage_v_114_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_181_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_181_1) + 7) & 255;
    }
    if ((stage_v_114_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_181_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_181_2) + 7) & 255;
    }
  }

  int stage_v_182_1 = ((pub_r001818_21_1 * 2) + 27) & 63;
  int stage_v_182_2 = ((pub_r001818_21_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001818_9_1 * 2) + 20) & 63;
  int stage_v_183_2 = ((pub_r001818_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001818_13_1 * 2) + 23) & 63;
  int stage_v_184_2 = ((pub_r001818_13_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = 0;
  int stage_v_185_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_185_1 = ((stage_v_185_1 + (it_1 * 3)) + (stage_v_73_1 & 15)) & 63;
    stage_v_185_2 = ((stage_v_185_2 + (it_2 * 3)) + (stage_v_73_2 & 15)) & 63;
    if ((stage_v_73_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_185_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_185_1) + 7) & 255;
    }
    if ((stage_v_73_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_185_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_185_2) + 7) & 255;
    }
  }

  int stage_v_186_1 = 0;
  int stage_v_186_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_186_1 = ((stage_v_186_1 + (it_1 * 3)) + (stage_v_172_1 & 15)) & 63;
    stage_v_186_2 = ((stage_v_186_2 + (it_2 * 3)) + (stage_v_172_2 & 15)) & 63;
    if ((stage_v_172_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_186_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_186_1) + 7) & 255;
    }
    if ((stage_v_172_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_186_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_186_2) + 7) & 255;
    }
  }

  int stage_v_187_1 = 0;
  int stage_v_187_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_187_1 = ((stage_v_187_1 + (it_1 * 3)) + (stage_v_158_1 & 15)) & 63;
    stage_v_187_2 = ((stage_v_187_2 + (it_2 * 3)) + (stage_v_158_2 & 15)) & 63;
    if ((stage_v_158_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_187_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_187_1) + 7) & 255;
    }
    if ((stage_v_158_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_187_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_187_2) + 7) & 255;
    }
  }

  int stage_v_188_1 = 0;
  int stage_v_188_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_188_1 = ((stage_v_188_1 + (it_1 * 3)) + (stage_v_4_1 & 15)) & 63;
    stage_v_188_2 = ((stage_v_188_2 + (it_2 * 3)) + (stage_v_4_2 & 15)) & 63;
    if ((stage_v_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_188_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_188_1) + 7) & 255;
    }
    if ((stage_v_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_188_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_188_2) + 7) & 255;
    }
  }

  int stage_v_189_1 = ((pub_r001818_18_1 * 2) + 14) & 63;
  int stage_v_189_2 = ((pub_r001818_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = 0;
  int stage_v_190_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_190_1 = ((stage_v_190_1 + (it_1 * 3)) + (stage_v_42_1 & 15)) & 63;
    stage_v_190_2 = ((stage_v_190_2 + (it_2 * 3)) + (stage_v_42_2 & 15)) & 63;
    if ((stage_v_42_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_190_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_190_1) + 7) & 255;
    }
    if ((stage_v_42_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_190_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_190_2) + 7) & 255;
    }
  }

  int stage_v_191_1 = 0;
  int stage_v_191_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_191_1 = ((stage_v_191_1 + (it_1 * 3)) + (stage_v_89_1 & 15)) & 63;
    stage_v_191_2 = ((stage_v_191_2 + (it_2 * 3)) + (stage_v_89_2 & 15)) & 63;
    if ((stage_v_89_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_191_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_191_1) + 7) & 255;
    }
    if ((stage_v_89_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_191_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_191_2) + 7) & 255;
    }
  }

  int stage_v_192_1 = 0;
  int stage_v_192_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_192_1 = ((stage_v_192_1 + (it_1 * 3)) + (stage_v_102_1 & 15)) & 63;
    stage_v_192_2 = ((stage_v_192_2 + (it_2 * 3)) + (stage_v_102_2 & 15)) & 63;
    if ((stage_v_102_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_192_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_192_1) + 7) & 255;
    }
    if ((stage_v_102_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_192_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_192_2) + 7) & 255;
    }
  }

  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001818_14_1 != sec_r001818_14_2);
  __CPROVER_assume(pub_r001818_6_1 == pub_r001818_6_2);
  __CPROVER_assume(pub_r001818_8_1 == pub_r001818_8_2);
  __CPROVER_assume(sec_r001818_10_1 != sec_r001818_10_2);
  __CPROVER_assume(sec_r001818_9_1 != sec_r001818_9_2);
  __CPROVER_assume(pub_r001818_20_1 == pub_r001818_20_2);
  __CPROVER_assume(sec_r001818_5_1 != sec_r001818_5_2);
  __CPROVER_assume(pub_r001818_10_1 == pub_r001818_10_2);
  __CPROVER_assume(pub_r001818_22_1 == pub_r001818_22_2);
  __CPROVER_assume(sec_r001818_2_1 != sec_r001818_2_2);
  __CPROVER_assume(pub_r001818_9_1 == pub_r001818_9_2);
  __CPROVER_assume(sec_r001818_16_1 != sec_r001818_16_2);
  __CPROVER_assume(pub_r001818_1_1 == pub_r001818_1_2);
  __CPROVER_assume(sec_r001818_17_1 != sec_r001818_17_2);
  __CPROVER_assume(sec_r001818_4_1 != sec_r001818_4_2);
  __CPROVER_assume(sec_r001818_8_1 != sec_r001818_8_2);
  __CPROVER_assume(sec_r001818_6_1 != sec_r001818_6_2);
  __CPROVER_assume(sec_r001818_11_1 != sec_r001818_11_2);
  __CPROVER_assume(pub_r001818_3_1 == pub_r001818_3_2);
  __CPROVER_assume(pub_r001818_7_1 == pub_r001818_7_2);
  __CPROVER_assume(pub_r001818_2_1 == pub_r001818_2_2);
  __CPROVER_assume(sec_r001818_18_1 != sec_r001818_18_2);
  __CPROVER_assume(sec_r001818_19_1 != sec_r001818_19_2);
  __CPROVER_assume(pub_r001818_13_1 == pub_r001818_13_2);
  __CPROVER_assume(pub_r001818_19_1 == pub_r001818_19_2);
  __CPROVER_assume(sec_r001818_13_1 != sec_r001818_13_2);
  __CPROVER_assume(sec_r001818_12_1 != sec_r001818_12_2);
  __CPROVER_assume(pub_r001818_16_1 == pub_r001818_16_2);
  __CPROVER_assume(pub_r001818_14_1 == pub_r001818_14_2);
  __CPROVER_assume(pub_r001818_0_1 == pub_r001818_0_2);
  __CPROVER_assume(pub_r001818_12_1 == pub_r001818_12_2);
  __CPROVER_assume(sec_r001818_1_1 != sec_r001818_1_2);
  __CPROVER_assume(pub_r001818_4_1 == pub_r001818_4_2);
  __CPROVER_assume(pub_r001818_18_1 == pub_r001818_18_2);
  __CPROVER_assume(sec_r001818_3_1 != sec_r001818_3_2);
  __CPROVER_assume(sec_r001818_15_1 != sec_r001818_15_2);
  __CPROVER_assume(pub_r001818_21_1 == pub_r001818_21_2);
  __CPROVER_assume(pub_r001818_15_1 == pub_r001818_15_2);
  __CPROVER_assume(sec_r001818_0_1 != sec_r001818_0_2);
  __CPROVER_assume(pub_r001818_5_1 == pub_r001818_5_2);
  __CPROVER_assume(sec_r001818_7_1 != sec_r001818_7_2);
  __CPROVER_assume(pub_r001818_17_1 == pub_r001818_17_2);
  __CPROVER_assume(pub_r001818_11_1 == pub_r001818_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
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
}


