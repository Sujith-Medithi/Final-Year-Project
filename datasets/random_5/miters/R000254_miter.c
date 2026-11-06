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
struct EventLog_R000254_5413_0
{
  short facility;
  int seq;
  int signature;
  unsigned char code;
  int timestamp;
  int severity;
  int buffer[3];
};
struct MatrixBlock_R000254_5413_1
{
  unsigned char dim;
  int scale;
  int determinant;
  unsigned char density;
  int trace;
  unsigned char stride;
  int buffer[3];
};
struct Vector3D_R000254_5413_2
{
  int heading;
  int coord_y;
  int coord_x;
  short pitch;
  int norm_sq;
  unsigned char coord_z;
  int buffer[3];
};
struct FilterState_R000254_5413_3
{
  int prev_out;
  int gain_db;
  int damping;
  int cutoff;
  short mode;
  int prev_in;
  int buffer[3];
};
union TelemetryField_R000254_5413_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000254_5413_1
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
void fn_R000254_5413_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000254_5413_2 st_1 = {0};
  struct Vector3D_R000254_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_96_1 = local_arr_1[aux_1 % 3];
  int tracker_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_96_2 * 2)) & 127;
  int threshold_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_78_1 > 36)
  {
    acc_1 = ((acc_1 + (threshold_78_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_78_2 > 36)
  {
    acc_2 = ((acc_2 + (threshold_78_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_78_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_96_1 == tracker_96_2);
  assert(threshold_78_1 == threshold_78_2);
}

int fn_R000254_5413_0(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000254_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int tracker_96 = local_arr[aux % 3];
  acc = (acc + (tracker_96 * 2)) & 127;
  int threshold_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_78 > 36)
  {
    acc = ((acc + (threshold_78 * 2)) + 5) & 127;
    aux ^= threshold_78 & 15;
  }
  else
  {
    acc = ((acc - threshold_78) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000254_5413_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000254_5413_3 st_1 = {0};
  struct FilterState_R000254_5413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int coefficient_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_20_1) & 63;
  aux_2 = (aux_2 + coefficient_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_19_1)
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

  switch (mask_19_2)
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
  int residue_74_1 = local_arr_1[aux_1 % 3];
  int residue_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_74_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_20_1 == coefficient_20_2);
  assert(mask_19_1 == mask_19_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_74_1 == residue_74_2);
}

int fn_R000254_5413_1(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000254_5413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int coefficient_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_20) & 63;
  acc ^= aux;
  int mask_19 = (aux + st.buffer[1]) & 3;
  switch (mask_19)
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
  int residue_74 = local_arr[aux % 3];
  acc = (acc + (residue_74 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000254_5413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000254_5413_1 st_1 = {0};
  struct MatrixBlock_R000254_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int stride_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_62_1 > 40)
  {
    acc_1 = ((acc_1 + (stride_62_1 * 2)) + 5) & 127;
    aux_1 ^= stride_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_62_2 > 40)
  {
    acc_2 = ((acc_2 + (stride_62_2 * 2)) + 5) & 127;
    aux_2 ^= stride_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_53_1)
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

  switch (parity_53_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_62_1 == stride_62_2);
  assert(parity_53_1 == parity_53_2);
}

int fn_R000254_5413_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000254_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int stride_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_62 > 40)
  {
    acc = ((acc + (stride_62 * 2)) + 5) & 127;
    aux ^= stride_62 & 15;
  }
  else
  {
    acc = ((acc - stride_62) + 11) & 127;
    aux += 3;
  }
  int parity_53 = (aux + st.buffer[1]) & 3;
  switch (parity_53)
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

void fn_R000254_5413_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000254_5413_2 st_1 = {0};
  struct Vector3D_R000254_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int delta_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_15_1)
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

  switch (delta_15_2)
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

  int checksum_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_30_1) & 63;
  aux_2 = (aux_2 + checksum_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_11_1 = local_arr_1[aux_1 % 3];
  int scale_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_11_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_15_1 == delta_15_2);
  assert(checksum_30_1 == checksum_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_11_1 == scale_11_2);
}

int fn_R000254_5413_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000254_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int delta_15 = (aux + st.buffer[1]) & 3;
  switch (delta_15)
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

  int checksum_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_30) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_11 = local_arr[aux % 3];
  acc = (acc + (scale_11 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000254_5413_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000254_5413_3 st_1 = {0};
  struct FilterState_R000254_5413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int tracker_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_73_1)
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

  switch (tracker_73_2)
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
  int checksum_93_1 = local_arr_1[aux_1 % 3];
  int checksum_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_93_2 * 2)) & 127;
  int metric_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_61_1) & 63;
  aux_2 = (aux_2 + metric_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_73_1 == tracker_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_93_1 == checksum_93_2);
  assert(metric_61_1 == metric_61_2);
}

int fn_R000254_5413_4(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000254_5413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int tracker_73 = (aux + st.buffer[1]) & 3;
  switch (tracker_73)
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
  int checksum_93 = local_arr[aux % 3];
  acc = (acc + (checksum_93 * 2)) & 127;
  int metric_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_61) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000254_5413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000254_5413_3 st_1 = {0};
  struct FilterState_R000254_5413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_75_1 = local_arr_1[aux_1 % 3];
  int phase_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_75_2 * 2)) & 127;
  int parity_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_94_1)
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

  switch (parity_94_2)
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

  int phase_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_84_1 > 40)
  {
    acc_1 = ((acc_1 + (phase_84_1 * 2)) + 5) & 127;
    aux_1 ^= phase_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_84_2 > 40)
  {
    acc_2 = ((acc_2 + (phase_84_2 * 2)) + 5) & 127;
    aux_2 ^= phase_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_84_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_75_1 == phase_75_2);
  assert(parity_94_1 == parity_94_2);
  assert(phase_84_1 == phase_84_2);
}

int fn_R000254_5413_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000254_5413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int phase_75 = local_arr[aux % 3];
  acc = (acc + (phase_75 * 2)) & 127;
  int parity_94 = (aux + st.buffer[1]) & 3;
  switch (parity_94)
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

  int phase_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_84 > 40)
  {
    acc = ((acc + (phase_84 * 2)) + 5) & 127;
    aux ^= phase_84 & 15;
  }
  else
  {
    acc = ((acc - phase_84) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000254_5413_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000254_5413_2 st_1 = {0};
  struct Vector3D_R000254_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int damping_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_88_1) & 63;
  aux_2 = (aux_2 + damping_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_68_1 > 32)
  {
    acc_1 = ((acc_1 + (cursor_68_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_68_2 > 32)
  {
    acc_2 = ((acc_2 + (cursor_68_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_68_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_88_1 == damping_88_2);
  assert(cursor_68_1 == cursor_68_2);
}

int fn_R000254_5413_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000254_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int damping_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_88) & 63;
  acc ^= aux;
  int cursor_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_68 > 32)
  {
    acc = ((acc + (cursor_68 * 2)) + 5) & 127;
    aux ^= cursor_68 & 15;
  }
  else
  {
    acc = ((acc - cursor_68) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000254_5413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000254_5413_0 st_1 = {0};
  struct EventLog_R000254_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int tally_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_66_1) & 63;
  aux_2 = (aux_2 + tally_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_30_1)
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

  switch (phase_30_2)
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

  int residue_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_67_1 > 40)
  {
    acc_1 = ((acc_1 + (residue_67_1 * 2)) + 5) & 127;
    aux_1 ^= residue_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_67_2 > 40)
  {
    acc_2 = ((acc_2 + (residue_67_2 * 2)) + 5) & 127;
    aux_2 ^= residue_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_67_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_66_1 == tally_66_2);
  assert(phase_30_1 == phase_30_2);
  assert(residue_67_1 == residue_67_2);
}

int fn_R000254_5413_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000254_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int tally_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_66) & 63;
  acc ^= aux;
  int phase_30 = (aux + st.buffer[1]) & 3;
  switch (phase_30)
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

  int residue_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_67 > 40)
  {
    acc = ((acc + (residue_67 * 2)) + 5) & 127;
    aux ^= residue_67 & 15;
  }
  else
  {
    acc = ((acc - residue_67) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000254_5413_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000254_5413_3 st_1 = {0};
  struct FilterState_R000254_5413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int segment_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_65_1 > 23)
  {
    acc_1 = ((acc_1 + (segment_65_1 * 2)) + 5) & 127;
    aux_1 ^= segment_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_65_2 > 23)
  {
    acc_2 = ((acc_2 + (segment_65_2 * 2)) + 5) & 127;
    aux_2 ^= segment_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_65_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_60_1)
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

  switch (bound_60_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_77_1) & 63;
  aux_2 = (aux_2 + quotient_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_65_1 == segment_65_2);
  assert(bound_60_1 == bound_60_2);
  assert(quotient_77_1 == quotient_77_2);
}

int fn_R000254_5413_8(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000254_5413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int segment_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_65 > 23)
  {
    acc = ((acc + (segment_65 * 2)) + 5) & 127;
    aux ^= segment_65 & 15;
  }
  else
  {
    acc = ((acc - segment_65) + 11) & 127;
    aux += 3;
  }
  int bound_60 = (aux + st.buffer[1]) & 3;
  switch (bound_60)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_77) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000254_5413_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000254_5413_3 st_1 = {0};
  struct FilterState_R000254_5413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int weight_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_28_1 > 33)
  {
    acc_1 = ((acc_1 + (weight_28_1 * 2)) + 5) & 127;
    aux_1 ^= weight_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_28_2 > 33)
  {
    acc_2 = ((acc_2 + (weight_28_2 * 2)) + 5) & 127;
    aux_2 ^= weight_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_28_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_13_1) & 63;
  aux_2 = (aux_2 + phase_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_28_1 == weight_28_2);
  assert(phase_13_1 == phase_13_2);
}

int fn_R000254_5413_9(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000254_5413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int weight_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_28 > 33)
  {
    acc = ((acc + (weight_28 * 2)) + 5) & 127;
    aux ^= weight_28 & 15;
  }
  else
  {
    acc = ((acc - weight_28) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_13) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000254_5413_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000254_5413_1 st_1 = {0};
  struct MatrixBlock_R000254_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int margin_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_99_1)
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

  switch (margin_99_2)
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
  int index_reg_84_1 = local_arr_1[aux_1 % 3];
  int index_reg_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_84_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_99_1 == margin_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_84_1 == index_reg_84_2);
}

int fn_R000254_5413_10(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000254_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int margin_99 = (aux + st.buffer[1]) & 3;
  switch (margin_99)
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
  int index_reg_84 = local_arr[aux % 3];
  acc = (acc + (index_reg_84 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000254_5413_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000254_5413_0 st_1 = {0};
  struct EventLog_R000254_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_96_1 = local_arr_1[aux_1 % 3];
  int delta_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_96_2 * 2)) & 127;
  int quantum_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_15_1) & 63;
  aux_2 = (aux_2 + quantum_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_96_1 == delta_96_2);
  assert(quantum_15_1 == quantum_15_2);
}

int fn_R000254_5413_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000254_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int delta_96 = local_arr[aux % 3];
  acc = (acc + (delta_96 * 2)) & 127;
  int quantum_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_15) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000254_5413_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000254_5413_3 st_1 = {0};
  struct FilterState_R000254_5413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_51_1) & 63;
  aux_2 = (aux_2 + stride_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_73_1)
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

  switch (checksum_73_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_51_1 == stride_51_2);
  assert(checksum_73_1 == checksum_73_2);
}

int fn_R000254_5413_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000254_5413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_51) & 63;
  acc ^= aux;
  int checksum_73 = (aux + st.buffer[1]) & 3;
  switch (checksum_73)
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

void fn_R000254_5413_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000254_5413_3 st_1 = {0};
  struct FilterState_R000254_5413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_89_1 = local_arr_1[aux_1 % 3];
  int parity_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_89_2 * 2)) & 127;
  int phase_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_27_1 > 28)
  {
    acc_1 = ((acc_1 + (phase_27_1 * 2)) + 5) & 127;
    aux_1 ^= phase_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_27_2 > 28)
  {
    acc_2 = ((acc_2 + (phase_27_2 * 2)) + 5) & 127;
    aux_2 ^= phase_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_58_1) & 63;
  aux_2 = (aux_2 + phase_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_89_1 == parity_89_2);
  assert(phase_27_1 == phase_27_2);
  assert(phase_58_1 == phase_58_2);
}

int fn_R000254_5413_13(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000254_5413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int parity_89 = local_arr[aux % 3];
  acc = (acc + (parity_89 * 2)) & 127;
  int phase_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_27 > 28)
  {
    acc = ((acc + (phase_27 * 2)) + 5) & 127;
    aux ^= phase_27 & 15;
  }
  else
  {
    acc = ((acc - phase_27) + 11) & 127;
    aux += 3;
  }
  int phase_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_58) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000254_5413_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000254_5413_0 st_1 = {0};
  struct EventLog_R000254_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int bound_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_31_1 > 15)
  {
    acc_1 = ((acc_1 + (bound_31_1 * 2)) + 5) & 127;
    aux_1 ^= bound_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_31_2 > 15)
  {
    acc_2 = ((acc_2 + (bound_31_2 * 2)) + 5) & 127;
    aux_2 ^= bound_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_16_1 = local_arr_1[aux_1 % 3];
  int bound_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_16_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_31_1 == bound_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_16_1 == bound_16_2);
}

int fn_R000254_5413_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000254_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int bound_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_31 > 15)
  {
    acc = ((acc + (bound_31 * 2)) + 5) & 127;
    aux ^= bound_31 & 15;
  }
  else
  {
    acc = ((acc - bound_31) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_16 = local_arr[aux % 3];
  acc = (acc + (bound_16 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000254_5413_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000254_5413_2 st_1 = {0};
  struct Vector3D_R000254_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_50_1 = local_arr_1[aux_1 % 3];
  int cursor_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_50_2 * 2)) & 127;
  int index_reg_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_57_1 > 38)
  {
    acc_1 = ((acc_1 + (index_reg_57_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_57_2 > 38)
  {
    acc_2 = ((acc_2 + (index_reg_57_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_57_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_50_1 == cursor_50_2);
  assert(index_reg_57_1 == index_reg_57_2);
}

int fn_R000254_5413_15(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000254_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int cursor_50 = local_arr[aux % 3];
  acc = (acc + (cursor_50 * 2)) & 127;
  int index_reg_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_57 > 38)
  {
    acc = ((acc + (index_reg_57 * 2)) + 5) & 127;
    aux ^= index_reg_57 & 15;
  }
  else
  {
    acc = ((acc - index_reg_57) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000254_5413_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000254_5413_1 st_1 = {0};
  struct MatrixBlock_R000254_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int threshold_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_53_1)
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

  switch (threshold_53_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_53_1 > 45)
  {
    acc_1 = ((acc_1 + (quotient_53_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_53_2 > 45)
  {
    acc_2 = ((acc_2 + (quotient_53_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_53_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_53_1 == threshold_53_2);
  assert(quotient_53_1 == quotient_53_2);
}

int fn_R000254_5413_16(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000254_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int threshold_53 = (aux + st.buffer[1]) & 3;
  switch (threshold_53)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_53 > 45)
  {
    acc = ((acc + (quotient_53 * 2)) + 5) & 127;
    aux ^= quotient_53 & 15;
  }
  else
  {
    acc = ((acc - quotient_53) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000254_5413_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000254_5413_1 st_1 = {0};
  struct MatrixBlock_R000254_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_81_1 = local_arr_1[aux_1 % 3];
  int stride_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_81_2 * 2)) & 127;
  int segment_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_34_1 > 34)
  {
    acc_1 = ((acc_1 + (segment_34_1 * 2)) + 5) & 127;
    aux_1 ^= segment_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_34_2 > 34)
  {
    acc_2 = ((acc_2 + (segment_34_2 * 2)) + 5) & 127;
    aux_2 ^= segment_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_34_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_81_1 == stride_81_2);
  assert(segment_34_1 == segment_34_2);
}

int fn_R000254_5413_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000254_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int stride_81 = local_arr[aux % 3];
  acc = (acc + (stride_81 * 2)) & 127;
  int segment_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_34 > 34)
  {
    acc = ((acc + (segment_34 * 2)) + 5) & 127;
    aux ^= segment_34 & 15;
  }
  else
  {
    acc = ((acc - segment_34) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000254_5413_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000254_5413_1 st_1 = {0};
  struct MatrixBlock_R000254_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int window_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_92_1)
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

  switch (window_92_2)
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
  int factor_32_1 = local_arr_1[aux_1 % 3];
  int factor_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_32_2 * 2)) & 127;
  int sample_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_19_1 > 45)
  {
    acc_1 = ((acc_1 + (sample_19_1 * 2)) + 5) & 127;
    aux_1 ^= sample_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_19_2 > 45)
  {
    acc_2 = ((acc_2 + (sample_19_2 * 2)) + 5) & 127;
    aux_2 ^= sample_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_19_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_92_1 == window_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_32_1 == factor_32_2);
  assert(sample_19_1 == sample_19_2);
}

int fn_R000254_5413_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000254_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int window_92 = (aux + st.buffer[1]) & 3;
  switch (window_92)
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
  int factor_32 = local_arr[aux % 3];
  acc = (acc + (factor_32 * 2)) & 127;
  int sample_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_19 > 45)
  {
    acc = ((acc + (sample_19 * 2)) + 5) & 127;
    aux ^= sample_19 & 15;
  }
  else
  {
    acc = ((acc - sample_19) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000254_5413_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000254_5413_0 st_1 = {0};
  struct EventLog_R000254_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int cursor_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_80_1 > 38)
  {
    acc_1 = ((acc_1 + (cursor_80_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_80_2 > 38)
  {
    acc_2 = ((acc_2 + (cursor_80_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_80_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_87_1)
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

  switch (quantum_87_2)
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_74_1 = local_arr_1[aux_1 % 3];
  int delta_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_74_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_80_1 == cursor_80_2);
  assert(quantum_87_1 == quantum_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_74_1 == delta_74_2);
}

int fn_R000254_5413_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000254_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int cursor_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_80 > 38)
  {
    acc = ((acc + (cursor_80 * 2)) + 5) & 127;
    aux ^= cursor_80 & 15;
  }
  else
  {
    acc = ((acc - cursor_80) + 11) & 127;
    aux += 3;
  }
  int quantum_87 = (aux + st.buffer[1]) & 3;
  switch (quantum_87)
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
  int local_arr[3] = {4, 9, 15};
  int delta_74 = local_arr[aux % 3];
  acc = (acc + (delta_74 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000254_5413_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000254_5413_0 st_1 = {0};
  struct EventLog_R000254_5413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_82_1 = local_arr_1[aux_1 % 3];
  int offset_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_82_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_82_1 == offset_82_2);
}

int fn_R000254_5413_20(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000254_5413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int offset_82 = local_arr[aux % 3];
  acc = (acc + (offset_82 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000254_5413_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000254_5413_1 st_1 = {0};
  struct MatrixBlock_R000254_5413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int weight_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_75_1) & 63;
  aux_2 = (aux_2 + weight_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_35_1 > 16)
  {
    acc_1 = ((acc_1 + (sample_35_1 * 2)) + 5) & 127;
    aux_1 ^= sample_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_35_2 > 16)
  {
    acc_2 = ((acc_2 + (sample_35_2 * 2)) + 5) & 127;
    aux_2 ^= sample_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_35_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_75_1 == weight_75_2);
  assert(sample_35_1 == sample_35_2);
}

int fn_R000254_5413_21(int p0, int p1, int p2)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000254_5413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int weight_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_75) & 63;
  acc ^= aux;
  int sample_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_35 > 16)
  {
    acc = ((acc + (sample_35 * 2)) + 5) & 127;
    aux ^= sample_35 & 15;
  }
  else
  {
    acc = ((acc - sample_35) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000254_5413_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000254_5413_2 st_1 = {0};
  struct Vector3D_R000254_5413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int damping_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_22_1 > 28)
  {
    acc_1 = ((acc_1 + (damping_22_1 * 2)) + 5) & 127;
    aux_1 ^= damping_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_22_2 > 28)
  {
    acc_2 = ((acc_2 + (damping_22_2 * 2)) + 5) & 127;
    aux_2 ^= damping_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_22_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_51_1)
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

  switch (coefficient_51_2)
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
  int accumulator_11_1 = local_arr_1[aux_1 % 3];
  int accumulator_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_11_2 * 2)) & 127;
  int factor_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_24_1) & 63;
  aux_2 = (aux_2 + factor_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_22_1 == damping_22_2);
  assert(coefficient_51_1 == coefficient_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_11_1 == accumulator_11_2);
  assert(factor_24_1 == factor_24_2);
}

int fn_R000254_5413_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000254_5413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int damping_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_22 > 28)
  {
    acc = ((acc + (damping_22 * 2)) + 5) & 127;
    aux ^= damping_22 & 15;
  }
  else
  {
    acc = ((acc - damping_22) + 11) & 127;
    aux += 3;
  }
  int coefficient_51 = (aux + st.buffer[1]) & 3;
  switch (coefficient_51)
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
  int accumulator_11 = local_arr[aux % 3];
  acc = (acc + (accumulator_11 * 2)) & 127;
  int factor_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_24) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000254_0_1;
  int sec_r000254_0_2;
  int sec_r000254_1_1;
  int sec_r000254_1_2;
  int sec_r000254_2_1;
  int sec_r000254_2_2;
  int sec_r000254_3_1;
  int sec_r000254_3_2;
  int sec_r000254_4_1;
  int sec_r000254_4_2;
  int sec_r000254_5_1;
  int sec_r000254_5_2;
  int sec_r000254_6_1;
  int sec_r000254_6_2;
  int sec_r000254_7_1;
  int sec_r000254_7_2;
  int sec_r000254_8_1;
  int sec_r000254_8_2;
  int sec_r000254_9_1;
  int sec_r000254_9_2;
  int sec_r000254_10_1;
  int sec_r000254_10_2;
  int sec_r000254_11_1;
  int sec_r000254_11_2;
  int sec_r000254_12_1;
  int sec_r000254_12_2;
  int sec_r000254_13_1;
  int sec_r000254_13_2;
  int sec_r000254_14_1;
  int sec_r000254_14_2;
  int sec_r000254_15_1;
  int sec_r000254_15_2;
  int sec_r000254_16_1;
  int sec_r000254_16_2;
  int sec_r000254_17_1;
  int sec_r000254_17_2;
  int sec_r000254_18_1;
  int sec_r000254_18_2;
  int sec_r000254_19_1;
  int sec_r000254_19_2;
  int sec_r000254_20_1;
  int sec_r000254_20_2;
  int sec_r000254_21_1;
  int sec_r000254_21_2;
  int sec_r000254_22_1;
  int sec_r000254_22_2;
  int pub_r000254_0_1;
  int pub_r000254_0_2;
  int pub_r000254_1_1;
  int pub_r000254_1_2;
  int pub_r000254_2_1;
  int pub_r000254_2_2;
  int pub_r000254_3_1;
  int pub_r000254_3_2;
  int pub_r000254_4_1;
  int pub_r000254_4_2;
  int pub_r000254_5_1;
  int pub_r000254_5_2;
  int pub_r000254_6_1;
  int pub_r000254_6_2;
  int pub_r000254_7_1;
  int pub_r000254_7_2;
  int pub_r000254_8_1;
  int pub_r000254_8_2;
  int pub_r000254_9_1;
  int pub_r000254_9_2;
  int pub_r000254_10_1;
  int pub_r000254_10_2;
  int pub_r000254_11_1;
  int pub_r000254_11_2;
  int pub_r000254_12_1;
  int pub_r000254_12_2;
  int pub_r000254_13_1;
  int pub_r000254_13_2;
  int pub_r000254_14_1;
  int pub_r000254_14_2;
  int pub_r000254_15_1;
  int pub_r000254_15_2;
  int pub_r000254_16_1;
  int pub_r000254_16_2;
  int pub_r000254_17_1;
  int pub_r000254_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000254_0_1 >= (-100)) && (pub_r000254_0_1 <= 100));
  __CPROVER_assume((pub_r000254_0_2 >= (-100)) && (pub_r000254_0_2 <= 100));
  __CPROVER_assume((pub_r000254_1_1 >= (-100)) && (pub_r000254_1_1 <= 100));
  __CPROVER_assume((pub_r000254_1_2 >= (-100)) && (pub_r000254_1_2 <= 100));
  __CPROVER_assume((pub_r000254_2_1 >= (-100)) && (pub_r000254_2_1 <= 100));
  __CPROVER_assume((pub_r000254_2_2 >= (-100)) && (pub_r000254_2_2 <= 100));
  __CPROVER_assume((pub_r000254_3_1 >= (-100)) && (pub_r000254_3_1 <= 100));
  __CPROVER_assume((pub_r000254_3_2 >= (-100)) && (pub_r000254_3_2 <= 100));
  __CPROVER_assume((pub_r000254_4_1 >= (-100)) && (pub_r000254_4_1 <= 100));
  __CPROVER_assume((pub_r000254_4_2 >= (-100)) && (pub_r000254_4_2 <= 100));
  __CPROVER_assume((pub_r000254_5_1 >= (-100)) && (pub_r000254_5_1 <= 100));
  __CPROVER_assume((pub_r000254_5_2 >= (-100)) && (pub_r000254_5_2 <= 100));
  __CPROVER_assume((pub_r000254_6_1 >= (-100)) && (pub_r000254_6_1 <= 100));
  __CPROVER_assume((pub_r000254_6_2 >= (-100)) && (pub_r000254_6_2 <= 100));
  __CPROVER_assume((pub_r000254_7_1 >= (-100)) && (pub_r000254_7_1 <= 100));
  __CPROVER_assume((pub_r000254_7_2 >= (-100)) && (pub_r000254_7_2 <= 100));
  __CPROVER_assume((pub_r000254_8_1 >= (-100)) && (pub_r000254_8_1 <= 100));
  __CPROVER_assume((pub_r000254_8_2 >= (-100)) && (pub_r000254_8_2 <= 100));
  __CPROVER_assume((pub_r000254_9_1 >= (-100)) && (pub_r000254_9_1 <= 100));
  __CPROVER_assume((pub_r000254_9_2 >= (-100)) && (pub_r000254_9_2 <= 100));
  __CPROVER_assume((pub_r000254_10_1 >= (-100)) && (pub_r000254_10_1 <= 100));
  __CPROVER_assume((pub_r000254_10_2 >= (-100)) && (pub_r000254_10_2 <= 100));
  __CPROVER_assume((pub_r000254_11_1 >= (-100)) && (pub_r000254_11_1 <= 100));
  __CPROVER_assume((pub_r000254_11_2 >= (-100)) && (pub_r000254_11_2 <= 100));
  __CPROVER_assume((pub_r000254_12_1 >= (-100)) && (pub_r000254_12_1 <= 100));
  __CPROVER_assume((pub_r000254_12_2 >= (-100)) && (pub_r000254_12_2 <= 100));
  __CPROVER_assume((pub_r000254_13_1 >= (-100)) && (pub_r000254_13_1 <= 100));
  __CPROVER_assume((pub_r000254_13_2 >= (-100)) && (pub_r000254_13_2 <= 100));
  __CPROVER_assume((pub_r000254_14_1 >= (-100)) && (pub_r000254_14_1 <= 100));
  __CPROVER_assume((pub_r000254_14_2 >= (-100)) && (pub_r000254_14_2 <= 100));
  __CPROVER_assume((pub_r000254_15_1 >= (-100)) && (pub_r000254_15_1 <= 100));
  __CPROVER_assume((pub_r000254_15_2 >= (-100)) && (pub_r000254_15_2 <= 100));
  __CPROVER_assume((pub_r000254_16_1 >= (-100)) && (pub_r000254_16_1 <= 100));
  __CPROVER_assume((pub_r000254_16_2 >= (-100)) && (pub_r000254_16_2 <= 100));
  __CPROVER_assume((pub_r000254_17_1 >= (-100)) && (pub_r000254_17_1 <= 100));
  __CPROVER_assume((pub_r000254_17_2 >= (-100)) && (pub_r000254_17_2 <= 100));
  __CPROVER_assume((sec_r000254_0_1 >= 0) && (sec_r000254_0_1 <= 255));
  __CPROVER_assume((sec_r000254_0_2 >= 0) && (sec_r000254_0_2 <= 255));
  __CPROVER_assume((sec_r000254_1_1 >= 0) && (sec_r000254_1_1 <= 255));
  __CPROVER_assume((sec_r000254_1_2 >= 0) && (sec_r000254_1_2 <= 255));
  __CPROVER_assume((sec_r000254_2_1 >= 0) && (sec_r000254_2_1 <= 255));
  __CPROVER_assume((sec_r000254_2_2 >= 0) && (sec_r000254_2_2 <= 255));
  __CPROVER_assume((sec_r000254_3_1 >= 0) && (sec_r000254_3_1 <= 255));
  __CPROVER_assume((sec_r000254_3_2 >= 0) && (sec_r000254_3_2 <= 255));
  __CPROVER_assume((sec_r000254_4_1 >= 0) && (sec_r000254_4_1 <= 255));
  __CPROVER_assume((sec_r000254_4_2 >= 0) && (sec_r000254_4_2 <= 255));
  __CPROVER_assume((sec_r000254_5_1 >= 0) && (sec_r000254_5_1 <= 255));
  __CPROVER_assume((sec_r000254_5_2 >= 0) && (sec_r000254_5_2 <= 255));
  __CPROVER_assume((sec_r000254_6_1 >= 0) && (sec_r000254_6_1 <= 255));
  __CPROVER_assume((sec_r000254_6_2 >= 0) && (sec_r000254_6_2 <= 255));
  __CPROVER_assume((sec_r000254_7_1 >= 0) && (sec_r000254_7_1 <= 255));
  __CPROVER_assume((sec_r000254_7_2 >= 0) && (sec_r000254_7_2 <= 255));
  __CPROVER_assume((sec_r000254_8_1 >= 0) && (sec_r000254_8_1 <= 255));
  __CPROVER_assume((sec_r000254_8_2 >= 0) && (sec_r000254_8_2 <= 255));
  __CPROVER_assume((sec_r000254_9_1 >= 0) && (sec_r000254_9_1 <= 255));
  __CPROVER_assume((sec_r000254_9_2 >= 0) && (sec_r000254_9_2 <= 255));
  __CPROVER_assume((sec_r000254_10_1 >= 0) && (sec_r000254_10_1 <= 255));
  __CPROVER_assume((sec_r000254_10_2 >= 0) && (sec_r000254_10_2 <= 255));
  __CPROVER_assume((sec_r000254_11_1 >= 0) && (sec_r000254_11_1 <= 255));
  __CPROVER_assume((sec_r000254_11_2 >= 0) && (sec_r000254_11_2 <= 255));
  __CPROVER_assume((sec_r000254_12_1 >= 0) && (sec_r000254_12_1 <= 255));
  __CPROVER_assume((sec_r000254_12_2 >= 0) && (sec_r000254_12_2 <= 255));
  __CPROVER_assume((sec_r000254_13_1 >= 0) && (sec_r000254_13_1 <= 255));
  __CPROVER_assume((sec_r000254_13_2 >= 0) && (sec_r000254_13_2 <= 255));
  __CPROVER_assume((sec_r000254_14_1 >= 0) && (sec_r000254_14_1 <= 255));
  __CPROVER_assume((sec_r000254_14_2 >= 0) && (sec_r000254_14_2 <= 255));
  __CPROVER_assume((sec_r000254_15_1 >= 0) && (sec_r000254_15_1 <= 255));
  __CPROVER_assume((sec_r000254_15_2 >= 0) && (sec_r000254_15_2 <= 255));
  __CPROVER_assume((sec_r000254_16_1 >= 0) && (sec_r000254_16_1 <= 255));
  __CPROVER_assume((sec_r000254_16_2 >= 0) && (sec_r000254_16_2 <= 255));
  __CPROVER_assume((sec_r000254_17_1 >= 0) && (sec_r000254_17_1 <= 255));
  __CPROVER_assume((sec_r000254_17_2 >= 0) && (sec_r000254_17_2 <= 255));
  __CPROVER_assume((sec_r000254_18_1 >= 0) && (sec_r000254_18_1 <= 255));
  __CPROVER_assume((sec_r000254_18_2 >= 0) && (sec_r000254_18_2 <= 255));
  __CPROVER_assume((sec_r000254_19_1 >= 0) && (sec_r000254_19_1 <= 255));
  __CPROVER_assume((sec_r000254_19_2 >= 0) && (sec_r000254_19_2 <= 255));
  __CPROVER_assume((sec_r000254_20_1 >= 0) && (sec_r000254_20_1 <= 255));
  __CPROVER_assume((sec_r000254_20_2 >= 0) && (sec_r000254_20_2 <= 255));
  __CPROVER_assume((sec_r000254_21_1 >= 0) && (sec_r000254_21_1 <= 255));
  __CPROVER_assume((sec_r000254_21_2 >= 0) && (sec_r000254_21_2 <= 255));
  __CPROVER_assume((sec_r000254_22_1 >= 0) && (sec_r000254_22_1 <= 255));
  __CPROVER_assume((sec_r000254_22_2 >= 0) && (sec_r000254_22_2 <= 255));
  struct EventLog_R000254_5413_0 st_var_0_1 = {0};
  struct EventLog_R000254_5413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000254_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000254_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000254_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000254_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000254_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000254_0_2 + 7) & 15;
  struct MatrixBlock_R000254_5413_1 st_var_1_1 = {0};
  struct MatrixBlock_R000254_5413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000254_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000254_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000254_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000254_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000254_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000254_0_2 + 9) & 15;
  struct Vector3D_R000254_5413_2 st_var_2_1 = {0};
  struct Vector3D_R000254_5413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000254_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000254_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000254_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000254_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000254_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000254_0_2 + 11) & 15;
  struct FilterState_R000254_5413_3 st_var_3_1 = {0};
  struct FilterState_R000254_5413_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000254_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000254_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000254_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000254_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000254_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000254_0_2 + 13) & 15;
  union TelemetryField_R000254_5413_0 u_var_1;
  union TelemetryField_R000254_5413_0 u_var_2;
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
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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

  int stage_v_3_1 = table_1[3];
  int stage_v_3_2 = table_2[3];
  table_1[3] = (table_1[0] + 7) & 63;
  table_2[3] = (table_2[0] + 7) & 63;
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
  int stage_v_5_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_5_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_5_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_5_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_6_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_6_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_6_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_6_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_7_1 = ((st_var_3_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_3_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 31)
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
  if (stage_v_7_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 31)
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
  int stage_v_8_1 = ((st_var_0_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_0_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 41)
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
  if (stage_v_8_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 41)
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
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 10) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_10_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_10_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_10_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = table_1[0];
  int stage_v_16_2 = table_2[0];
  table_1[0] = (table_1[1] + 33) & 63;
  table_2[0] = (table_2[1] + 33) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (22 & 31);
  int stage_v_17_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (22 & 31);
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= (stage_v_17_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_17_2 << 1) & 127;
  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 21) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 21) & 15;
  int stage_v_20_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_20_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= stage_v_20_1;
  chk_sum_2 ^= stage_v_20_2;
  int stage_v_21_1 = ((st_var_1_1.buffer[0] * 2) + 70) & 63;
  int stage_v_21_2 = ((st_var_1_2.buffer[0] * 2) + 70) & 63;
  if (stage_v_21_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_21_1) - 5) & 255;
    if (stage_v_21_1 > 43)
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
  if (stage_v_21_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_21_2) - 5) & 255;
    if (stage_v_21_2 > 43)
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
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 23) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 23) & 15;
  int stage_v_22_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_22_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= stage_v_22_1;
  chk_sum_2 ^= stage_v_22_2;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 25) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 25) & 15;
  int stage_v_24_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_24_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= stage_v_24_1;
  chk_sum_2 ^= stage_v_24_2;
  int stage_v_25_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_25_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 28) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 28) & 15;
  int stage_v_27_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_27_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= stage_v_27_1;
  chk_sum_2 ^= stage_v_27_2;
  int stage_v_28_1 = ((st_var_0_1.buffer[1] * 2) + 91) & 63;
  int stage_v_28_2 = ((st_var_0_2.buffer[1] * 2) + 91) & 63;
  if (stage_v_28_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_28_1) - 5) & 255;
    if (stage_v_28_1 > 46)
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
  if (stage_v_28_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_28_2) - 5) & 255;
    if (stage_v_28_2 > 46)
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
  int stage_v_30_1 = (st_var_2_1.buffer[0] ^ 33) & 3;
  int stage_v_30_2 = (st_var_2_2.buffer[0] ^ 33) & 3;
  switch (stage_v_30_1)
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

  switch (stage_v_30_2)
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

  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 32) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 32) & 15;
  int stage_v_31_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_31_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= stage_v_31_1;
  chk_sum_2 ^= stage_v_31_2;
  int stage_v_32_1 = (st_var_0_1.buffer[0] ^ 35) & 3;
  int stage_v_32_2 = (st_var_0_2.buffer[0] ^ 35) & 3;
  switch (stage_v_32_1)
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

  switch (stage_v_32_2)
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

  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 34) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_34_1 = ((stage_v_34_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_34_2 = ((stage_v_34_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (40 & 31);
  int stage_v_35_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (40 & 31);
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= (stage_v_35_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_35_2 << 1) & 127;
  int stage_v_36_1 = table_1[0];
  int stage_v_36_2 = table_2[0];
  table_1[0] = (table_1[1] + 73) & 63;
  table_2[0] = (table_2[1] + 73) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((st_var_1_1.buffer[1] * 2) + 118) & 63;
  int stage_v_37_2 = ((st_var_1_2.buffer[1] * 2) + 118) & 63;
  if (stage_v_37_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_37_1) - 5) & 255;
    if (stage_v_37_1 > 44)
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
  if (stage_v_37_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_37_2) - 5) & 255;
    if (stage_v_37_2 > 44)
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
  int stage_v_39_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_39_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_39_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_39_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_40_1 = table_1[0];
  int stage_v_40_2 = table_2[0];
  table_1[0] = (table_1[1] + 81) & 63;
  table_2[0] = (table_2[1] + 81) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_42_1 = (st_var_2_1.buffer[0] ^ 45) & 3;
  int stage_v_42_2 = (st_var_2_2.buffer[0] ^ 45) & 3;
  switch (stage_v_42_1)
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

  switch (stage_v_42_2)
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

  int stage_v_43_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (48 & 31);
  int stage_v_43_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (48 & 31);
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= (stage_v_43_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_43_2 << 1) & 127;
  int stage_v_44_1 = ((st_var_0_1.buffer[2] * 2) + 139) & 63;
  int stage_v_44_2 = ((st_var_0_2.buffer[2] * 2) + 139) & 63;
  if (stage_v_44_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_44_1) - 5) & 255;
    if (stage_v_44_1 > 52)
    {
      chk_sum_1 ^= stage_v_44_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_44_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_44_2) - 5) & 255;
    if (stage_v_44_2 > 52)
    {
      chk_sum_2 ^= stage_v_44_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_45_1 = (st_var_1_1.buffer[0] ^ 48) & 3;
  int stage_v_45_2 = (st_var_1_2.buffer[0] ^ 48) & 3;
  switch (stage_v_45_1)
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

  switch (stage_v_45_2)
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

  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
  int stage_v_47_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (52 & 31);
  int stage_v_47_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (52 & 31);
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= (stage_v_47_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_47_2 << 1) & 127;
  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  int stage_v_49_1 = ((st_var_1_1.buffer[1] * 2) + 154) & 63;
  int stage_v_49_2 = ((st_var_1_2.buffer[1] * 2) + 154) & 63;
  if (stage_v_49_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 52)
    {
      chk_sum_1 ^= stage_v_49_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_49_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 52)
    {
      chk_sum_2 ^= stage_v_49_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_50_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (55 & 31);
  int stage_v_50_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (55 & 31);
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= (stage_v_50_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_50_2 << 1) & 127;
  int stage_v_51_1 = (st_var_3_1.buffer[0] ^ 54) & 3;
  int stage_v_51_2 = (st_var_3_2.buffer[0] ^ 54) & 3;
  switch (stage_v_51_1)
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

  switch (stage_v_51_2)
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

  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_52_1 = ((stage_v_52_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = table_1[2];
  int stage_v_54_2 = table_2[2];
  table_1[2] = (table_1[3] + 109) & 63;
  table_2[2] = (table_2[3] + 109) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = table_1[3];
  int stage_v_55_2 = table_2[3];
  table_1[3] = (table_1[0] + 111) & 63;
  table_2[3] = (table_2[0] + 111) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 57) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 57) & 15;
  int stage_v_56_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_56_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= stage_v_56_1;
  chk_sum_2 ^= stage_v_56_2;
  int stage_v_57_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (62 & 31);
  int stage_v_57_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (62 & 31);
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= (stage_v_57_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_57_2 << 1) & 127;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 59) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 59) & 15;
  int stage_v_58_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_58_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= stage_v_58_1;
  chk_sum_2 ^= stage_v_58_2;
  int stage_v_59_1 = table_1[3];
  int stage_v_59_2 = table_2[3];
  table_1[3] = (table_1[0] + 119) & 63;
  table_2[3] = (table_2[0] + 119) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = ((st_var_0_1.buffer[0] * 2) + 187) & 63;
  int stage_v_60_2 = ((st_var_0_2.buffer[0] * 2) + 187) & 63;
  if (stage_v_60_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_60_1) - 5) & 255;
    if (stage_v_60_1 > 25)
    {
      chk_sum_1 ^= stage_v_60_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_60_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_60_2) - 5) & 255;
    if (stage_v_60_2 > 25)
    {
      chk_sum_2 ^= stage_v_60_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_61_1 = table_1[1];
  int stage_v_61_2 = table_2[1];
  table_1[1] = (table_1[2] + 123) & 63;
  table_2[1] = (table_2[2] + 123) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((st_var_2_1.buffer[2] * 2) + 193) & 63;
  int stage_v_62_2 = ((st_var_2_2.buffer[2] * 2) + 193) & 63;
  if (stage_v_62_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_62_1) - 5) & 255;
    if (stage_v_62_1 > 27)
    {
      chk_sum_1 ^= stage_v_62_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_62_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_62_2) - 5) & 255;
    if (stage_v_62_2 > 27)
    {
      chk_sum_2 ^= stage_v_62_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 64) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 64) & 15;
  int stage_v_63_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_63_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= stage_v_63_1;
  chk_sum_2 ^= stage_v_63_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 65) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 65) & 15;
  int stage_v_64_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_64_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= stage_v_64_1;
  chk_sum_2 ^= stage_v_64_2;
  int stage_v_65_1 = table_1[1];
  int stage_v_65_2 = table_2[1];
  table_1[1] = (table_1[2] + 131) & 63;
  table_2[1] = (table_2[2] + 131) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = table_1[2];
  int stage_v_66_2 = table_2[2];
  table_1[2] = (table_1[3] + 133) & 63;
  table_2[2] = (table_2[3] + 133) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((st_var_3_1.buffer[1] * 2) + 208) & 63;
  int stage_v_67_2 = ((st_var_3_2.buffer[1] * 2) + 208) & 63;
  if (stage_v_67_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_67_1) - 5) & 255;
    if (stage_v_67_1 > 54)
    {
      chk_sum_1 ^= stage_v_67_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_67_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_67_2) - 5) & 255;
    if (stage_v_67_2 > 54)
    {
      chk_sum_2 ^= stage_v_67_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_68_1 = (st_var_0_1.buffer[0] ^ 71) & 3;
  int stage_v_68_2 = (st_var_0_2.buffer[0] ^ 71) & 3;
  switch (stage_v_68_1)
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

  switch (stage_v_68_2)
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

  int stage_v_69_1 = (st_var_1_1.buffer[0] ^ 72) & 3;
  int stage_v_69_2 = (st_var_1_2.buffer[0] ^ 72) & 3;
  switch (stage_v_69_1)
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

  switch (stage_v_69_2)
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

  int stage_v_70_1 = (st_var_2_1.buffer[0] ^ 73) & 3;
  int stage_v_70_2 = (st_var_2_2.buffer[0] ^ 73) & 3;
  switch (stage_v_70_1)
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

  switch (stage_v_70_2)
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

  int stage_v_71_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_71_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_72_1 = ((stage_v_72_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_72_2 = ((stage_v_72_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = table_1[1];
  int stage_v_73_2 = table_2[1];
  table_1[1] = (table_1[2] + 147) & 63;
  table_2[1] = (table_2[2] + 147) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_74_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_74_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_74_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 76) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 76) & 15;
  int stage_v_75_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_75_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  chk_sum_1 ^= stage_v_75_1;
  chk_sum_2 ^= stage_v_75_2;
  int stage_v_76_1 = table_1[0];
  int stage_v_76_2 = table_2[0];
  table_1[0] = (table_1[1] + 153) & 63;
  table_2[0] = (table_2[1] + 153) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((st_var_1_1.buffer[2] * 2) + 238) & 63;
  int stage_v_77_2 = ((st_var_1_2.buffer[2] * 2) + 238) & 63;
  if (stage_v_77_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_77_1) - 5) & 255;
    if (stage_v_77_1 > 53)
    {
      chk_sum_1 ^= stage_v_77_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_77_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_77_2) - 5) & 255;
    if (stage_v_77_2 > 53)
    {
      chk_sum_2 ^= stage_v_77_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_78_1 = ((st_var_2_1.buffer[0] * 2) + 241) & 63;
  int stage_v_78_2 = ((st_var_2_2.buffer[0] * 2) + 241) & 63;
  if (stage_v_78_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_78_1) - 5) & 255;
    if (stage_v_78_1 > 25)
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
  if (stage_v_78_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_78_2) - 5) & 255;
    if (stage_v_78_2 > 25)
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
  int stage_v_79_1 = ((((sec_r000254_21_1 * 3) + (sec_r000254_21_1 * 2)) - pub_r000254_5_1) + 34) & 127;
  int stage_v_79_2 = ((((sec_r000254_21_2 * 3) + (sec_r000254_21_2 * 2)) - pub_r000254_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_79_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_79_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((((stage_v_79_1 * 3) + (sec_r000254_10_1 * 2)) - pub_r000254_17_1) + 30) & 127;
  int stage_v_80_2 = ((((stage_v_79_2 * 3) + (sec_r000254_10_2 * 2)) - pub_r000254_17_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_80_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_80_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((((stage_v_80_1 * 3) + (sec_r000254_3_1 * 2)) - pub_r000254_6_1) + 16) & 127;
  int stage_v_81_2 = ((((stage_v_80_2 * 3) + (sec_r000254_3_2 * 2)) - pub_r000254_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_81_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_81_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((((sec_r000254_0_1 * 3) + (sec_r000254_0_1 * 2)) - pub_r000254_0_1) + 9) & 127;
  int stage_v_82_2 = ((((sec_r000254_0_2 * 3) + (sec_r000254_0_2 * 2)) - pub_r000254_0_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_82_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_82_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((((stage_v_82_1 * 3) + (sec_r000254_18_1 * 2)) - pub_r000254_4_1) + 30) & 127;
  int stage_v_83_2 = ((((stage_v_82_2 * 3) + (sec_r000254_18_2 * 2)) - pub_r000254_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((((stage_v_79_1 * 3) + (sec_r000254_8_1 * 2)) - pub_r000254_12_1) + 14) & 127;
  int stage_v_84_2 = ((((stage_v_79_2 * 3) + (sec_r000254_8_2 * 2)) - pub_r000254_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((((stage_v_82_1 * 3) + (sec_r000254_22_1 * 2)) - pub_r000254_0_1) + 24) & 127;
  int stage_v_85_2 = ((((stage_v_82_2 * 3) + (sec_r000254_22_2 * 2)) - pub_r000254_0_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((((sec_r000254_21_1 * 3) + (sec_r000254_21_1 * 2)) - pub_r000254_5_1) + 21) & 127;
  int stage_v_86_2 = ((((sec_r000254_21_2 * 3) + (sec_r000254_21_2 * 2)) - pub_r000254_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_86_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_86_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((((stage_v_83_1 * 3) + (sec_r000254_5_1 * 2)) - pub_r000254_1_1) + 17) & 127;
  int stage_v_87_2 = ((((stage_v_83_2 * 3) + (sec_r000254_5_2 * 2)) - pub_r000254_1_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((((sec_r000254_14_1 * 3) + (sec_r000254_14_1 * 2)) - pub_r000254_7_1) + 14) & 127;
  int stage_v_88_2 = ((((sec_r000254_14_2 * 3) + (sec_r000254_14_2 * 2)) - pub_r000254_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((((stage_v_81_1 * 3) + (sec_r000254_9_1 * 2)) - pub_r000254_13_1) + 31) & 127;
  int stage_v_89_2 = ((((stage_v_81_2 * 3) + (sec_r000254_9_2 * 2)) - pub_r000254_13_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((((stage_v_88_1 * 3) + (sec_r000254_20_1 * 2)) - pub_r000254_14_1) + 24) & 127;
  int stage_v_90_2 = ((((stage_v_88_2 * 3) + (sec_r000254_20_2 * 2)) - pub_r000254_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((((sec_r000254_2_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_16_1) + 19) & 127;
  int stage_v_91_2 = ((((sec_r000254_2_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_91_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_91_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((((sec_r000254_17_1 * 3) + (sec_r000254_17_1 * 2)) - pub_r000254_7_1) + 6) & 127;
  int stage_v_92_2 = ((((sec_r000254_17_2 * 3) + (sec_r000254_17_2 * 2)) - pub_r000254_7_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_92_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_92_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((((stage_v_88_1 * 3) + (sec_r000254_20_1 * 2)) - pub_r000254_7_1) + 5) & 127;
  int stage_v_93_2 = ((((stage_v_88_2 * 3) + (sec_r000254_20_2 * 2)) - pub_r000254_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_93_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_93_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((((sec_r000254_17_1 * 3) + (sec_r000254_17_1 * 2)) - pub_r000254_17_1) + 23) & 127;
  int stage_v_94_2 = ((((sec_r000254_17_2 * 3) + (sec_r000254_17_2 * 2)) - pub_r000254_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_94_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_94_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((((stage_v_81_1 * 3) + (sec_r000254_3_1 * 2)) - pub_r000254_8_1) + 32) & 127;
  int stage_v_95_2 = ((((stage_v_81_2 * 3) + (sec_r000254_3_2 * 2)) - pub_r000254_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((((stage_v_83_1 * 3) + (sec_r000254_4_1 * 2)) - pub_r000254_6_1) + 34) & 127;
  int stage_v_96_2 = ((((stage_v_83_2 * 3) + (sec_r000254_4_2 * 2)) - pub_r000254_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((((stage_v_93_1 * 3) + (sec_r000254_16_1 * 2)) - pub_r000254_7_1) + 9) & 127;
  int stage_v_97_2 = ((((stage_v_93_2 * 3) + (sec_r000254_16_2 * 2)) - pub_r000254_7_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_97_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_97_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((((stage_v_95_1 * 3) + (sec_r000254_14_1 * 2)) - pub_r000254_16_1) + 31) & 127;
  int stage_v_98_2 = ((((stage_v_95_2 * 3) + (sec_r000254_14_2 * 2)) - pub_r000254_16_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((((stage_v_80_1 * 3) + (sec_r000254_11_1 * 2)) - pub_r000254_1_1) + 33) & 127;
  int stage_v_99_2 = ((((stage_v_80_2 * 3) + (sec_r000254_11_2 * 2)) - pub_r000254_1_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_99_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_99_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((((sec_r000254_4_1 * 3) + (sec_r000254_4_1 * 2)) - pub_r000254_15_1) + 14) & 127;
  int stage_v_100_2 = ((((sec_r000254_4_2 * 3) + (sec_r000254_4_2 * 2)) - pub_r000254_15_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_100_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_100_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((((stage_v_92_1 * 3) + (sec_r000254_7_1 * 2)) - pub_r000254_8_1) + 18) & 127;
  int stage_v_101_2 = ((((stage_v_92_2 * 3) + (sec_r000254_7_2 * 2)) - pub_r000254_8_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_101_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_101_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((((sec_r000254_17_1 * 3) + (sec_r000254_17_1 * 2)) - pub_r000254_9_1) + 31) & 127;
  int stage_v_102_2 = ((((sec_r000254_17_2 * 3) + (sec_r000254_17_2 * 2)) - pub_r000254_9_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((((stage_v_85_1 * 3) + (sec_r000254_4_1 * 2)) - pub_r000254_4_1) + 28) & 127;
  int stage_v_103_2 = ((((stage_v_85_2 * 3) + (sec_r000254_4_2 * 2)) - pub_r000254_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_103_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_103_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((((stage_v_79_1 * 3) + (sec_r000254_16_1 * 2)) - pub_r000254_11_1) + 4) & 127;
  int stage_v_104_2 = ((((stage_v_79_2 * 3) + (sec_r000254_16_2 * 2)) - pub_r000254_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((((stage_v_100_1 * 3) + (sec_r000254_3_1 * 2)) - pub_r000254_2_1) + 16) & 127;
  int stage_v_105_2 = ((((stage_v_100_2 * 3) + (sec_r000254_3_2 * 2)) - pub_r000254_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_105_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_105_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((((stage_v_83_1 * 3) + (sec_r000254_22_1 * 2)) - pub_r000254_4_1) + 10) & 127;
  int stage_v_106_2 = ((((stage_v_83_2 * 3) + (sec_r000254_22_2 * 2)) - pub_r000254_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((((stage_v_87_1 * 3) + (sec_r000254_8_1 * 2)) - pub_r000254_1_1) + 3) & 127;
  int stage_v_107_2 = ((((stage_v_87_2 * 3) + (sec_r000254_8_2 * 2)) - pub_r000254_1_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_107_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_107_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((((stage_v_84_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_17_1) + 21) & 127;
  int stage_v_108_2 = ((((stage_v_84_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_17_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((((stage_v_97_1 * 3) + (sec_r000254_14_1 * 2)) - pub_r000254_6_1) + 15) & 127;
  int stage_v_109_2 = ((((stage_v_97_2 * 3) + (sec_r000254_14_2 * 2)) - pub_r000254_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((((sec_r000254_11_1 * 3) + (sec_r000254_11_1 * 2)) - pub_r000254_0_1) + 15) & 127;
  int stage_v_110_2 = ((((sec_r000254_11_2 * 3) + (sec_r000254_11_2 * 2)) - pub_r000254_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_110_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_110_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((((stage_v_82_1 * 3) + (sec_r000254_6_1 * 2)) - pub_r000254_15_1) + 13) & 127;
  int stage_v_111_2 = ((((stage_v_82_2 * 3) + (sec_r000254_6_2 * 2)) - pub_r000254_15_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((((stage_v_83_1 * 3) + (sec_r000254_10_1 * 2)) - pub_r000254_0_1) + 29) & 127;
  int stage_v_112_2 = ((((stage_v_83_2 * 3) + (sec_r000254_10_2 * 2)) - pub_r000254_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((((stage_v_112_1 * 3) + (sec_r000254_22_1 * 2)) - pub_r000254_7_1) + 27) & 127;
  int stage_v_113_2 = ((((stage_v_112_2 * 3) + (sec_r000254_22_2 * 2)) - pub_r000254_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((((sec_r000254_14_1 * 3) + (sec_r000254_14_1 * 2)) - pub_r000254_7_1) + 26) & 127;
  int stage_v_114_2 = ((((sec_r000254_14_2 * 3) + (sec_r000254_14_2 * 2)) - pub_r000254_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((((stage_v_81_1 * 3) + (sec_r000254_22_1 * 2)) - pub_r000254_6_1) + 25) & 127;
  int stage_v_115_2 = ((((stage_v_81_2 * 3) + (sec_r000254_22_2 * 2)) - pub_r000254_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((((stage_v_113_1 * 3) + (sec_r000254_21_1 * 2)) - pub_r000254_6_1) + 5) & 127;
  int stage_v_116_2 = ((((stage_v_113_2 * 3) + (sec_r000254_21_2 * 2)) - pub_r000254_6_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((((sec_r000254_17_1 * 3) + (sec_r000254_17_1 * 2)) - pub_r000254_17_1) + 36) & 127;
  int stage_v_117_2 = ((((sec_r000254_17_2 * 3) + (sec_r000254_17_2 * 2)) - pub_r000254_17_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((((sec_r000254_4_1 * 3) + (sec_r000254_4_1 * 2)) - pub_r000254_6_1) + 8) & 127;
  int stage_v_118_2 = ((((sec_r000254_4_2 * 3) + (sec_r000254_4_2 * 2)) - pub_r000254_6_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((((sec_r000254_22_1 * 3) + (sec_r000254_22_1 * 2)) - pub_r000254_11_1) + 34) & 127;
  int stage_v_119_2 = ((((sec_r000254_22_2 * 3) + (sec_r000254_22_2 * 2)) - pub_r000254_11_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((((sec_r000254_7_1 * 3) + (sec_r000254_7_1 * 2)) - pub_r000254_10_1) + 22) & 127;
  int stage_v_120_2 = ((((sec_r000254_7_2 * 3) + (sec_r000254_7_2 * 2)) - pub_r000254_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((((stage_v_81_1 * 3) + (sec_r000254_14_1 * 2)) - pub_r000254_11_1) + 33) & 127;
  int stage_v_121_2 = ((((stage_v_81_2 * 3) + (sec_r000254_14_2 * 2)) - pub_r000254_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((((stage_v_101_1 * 3) + (sec_r000254_11_1 * 2)) - pub_r000254_7_1) + 5) & 127;
  int stage_v_122_2 = ((((stage_v_101_2 * 3) + (sec_r000254_11_2 * 2)) - pub_r000254_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((((sec_r000254_16_1 * 3) + (sec_r000254_16_1 * 2)) - pub_r000254_12_1) + 25) & 127;
  int stage_v_123_2 = ((((sec_r000254_16_2 * 3) + (sec_r000254_16_2 * 2)) - pub_r000254_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((((sec_r000254_8_1 * 3) + (sec_r000254_8_1 * 2)) - pub_r000254_8_1) + 35) & 127;
  int stage_v_124_2 = ((((sec_r000254_8_2 * 3) + (sec_r000254_8_2 * 2)) - pub_r000254_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((((stage_v_118_1 * 3) + (sec_r000254_1_1 * 2)) - pub_r000254_17_1) + 9) & 127;
  int stage_v_125_2 = ((((stage_v_118_2 * 3) + (sec_r000254_1_2 * 2)) - pub_r000254_17_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((((stage_v_105_1 * 3) + (sec_r000254_11_1 * 2)) - pub_r000254_0_1) + 11) & 127;
  int stage_v_126_2 = ((((stage_v_105_2 * 3) + (sec_r000254_11_2 * 2)) - pub_r000254_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((((stage_v_98_1 * 3) + (sec_r000254_19_1 * 2)) - pub_r000254_7_1) + 7) & 127;
  int stage_v_127_2 = ((((stage_v_98_2 * 3) + (sec_r000254_19_2 * 2)) - pub_r000254_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((((stage_v_79_1 * 3) + (sec_r000254_9_1 * 2)) - pub_r000254_10_1) + 8) & 127;
  int stage_v_128_2 = ((((stage_v_79_2 * 3) + (sec_r000254_9_2 * 2)) - pub_r000254_10_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((((sec_r000254_18_1 * 3) + (sec_r000254_18_1 * 2)) - pub_r000254_1_1) + 27) & 127;
  int stage_v_129_2 = ((((sec_r000254_18_2 * 3) + (sec_r000254_18_2 * 2)) - pub_r000254_1_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((((stage_v_118_1 * 3) + (sec_r000254_14_1 * 2)) - pub_r000254_6_1) + 13) & 127;
  int stage_v_130_2 = ((((stage_v_118_2 * 3) + (sec_r000254_14_2 * 2)) - pub_r000254_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((((stage_v_98_1 * 3) + (sec_r000254_14_1 * 2)) - pub_r000254_17_1) + 19) & 127;
  int stage_v_131_2 = ((((stage_v_98_2 * 3) + (sec_r000254_14_2 * 2)) - pub_r000254_17_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_131_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_131_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((((sec_r000254_2_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_5_1) + 23) & 127;
  int stage_v_132_2 = ((((sec_r000254_2_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((((sec_r000254_0_1 * 3) + (sec_r000254_0_1 * 2)) - pub_r000254_16_1) + 30) & 127;
  int stage_v_133_2 = ((((sec_r000254_0_2 * 3) + (sec_r000254_0_2 * 2)) - pub_r000254_16_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((((stage_v_97_1 * 3) + (sec_r000254_4_1 * 2)) - pub_r000254_8_1) + 31) & 127;
  int stage_v_134_2 = ((((stage_v_97_2 * 3) + (sec_r000254_4_2 * 2)) - pub_r000254_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_134_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_134_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((((stage_v_108_1 * 3) + (sec_r000254_0_1 * 2)) - pub_r000254_15_1) + 14) & 127;
  int stage_v_135_2 = ((((stage_v_108_2 * 3) + (sec_r000254_0_2 * 2)) - pub_r000254_15_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_135_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_135_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((((stage_v_106_1 * 3) + (sec_r000254_21_1 * 2)) - pub_r000254_4_1) + 33) & 127;
  int stage_v_136_2 = ((((stage_v_106_2 * 3) + (sec_r000254_21_2 * 2)) - pub_r000254_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((((stage_v_99_1 * 3) + (sec_r000254_9_1 * 2)) - pub_r000254_10_1) + 34) & 127;
  int stage_v_137_2 = ((((stage_v_99_2 * 3) + (sec_r000254_9_2 * 2)) - pub_r000254_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((((stage_v_94_1 * 3) + (sec_r000254_12_1 * 2)) - pub_r000254_8_1) + 13) & 127;
  int stage_v_138_2 = ((((stage_v_94_2 * 3) + (sec_r000254_12_2 * 2)) - pub_r000254_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((((stage_v_105_1 * 3) + (sec_r000254_20_1 * 2)) - pub_r000254_9_1) + 17) & 127;
  int stage_v_139_2 = ((((stage_v_105_2 * 3) + (sec_r000254_20_2 * 2)) - pub_r000254_9_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((((stage_v_105_1 * 3) + (sec_r000254_13_1 * 2)) - pub_r000254_5_1) + 4) & 127;
  int stage_v_140_2 = ((((stage_v_105_2 * 3) + (sec_r000254_13_2 * 2)) - pub_r000254_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((((sec_r000254_19_1 * 3) + (sec_r000254_19_1 * 2)) - pub_r000254_11_1) + 26) & 127;
  int stage_v_141_2 = ((((sec_r000254_19_2 * 3) + (sec_r000254_19_2 * 2)) - pub_r000254_11_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((((sec_r000254_4_1 * 3) + (sec_r000254_4_1 * 2)) - pub_r000254_2_1) + 7) & 127;
  int stage_v_142_2 = ((((sec_r000254_4_2 * 3) + (sec_r000254_4_2 * 2)) - pub_r000254_2_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((((sec_r000254_7_1 * 3) + (sec_r000254_7_1 * 2)) - pub_r000254_16_1) + 18) & 127;
  int stage_v_143_2 = ((((sec_r000254_7_2 * 3) + (sec_r000254_7_2 * 2)) - pub_r000254_16_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((((stage_v_134_1 * 3) + (sec_r000254_0_1 * 2)) - pub_r000254_5_1) + 36) & 127;
  int stage_v_144_2 = ((((stage_v_134_2 * 3) + (sec_r000254_0_2 * 2)) - pub_r000254_5_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((((stage_v_132_1 * 3) + (sec_r000254_20_1 * 2)) - pub_r000254_5_1) + 32) & 127;
  int stage_v_145_2 = ((((stage_v_132_2 * 3) + (sec_r000254_20_2 * 2)) - pub_r000254_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((((sec_r000254_2_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_1_1) + 10) & 127;
  int stage_v_146_2 = ((((sec_r000254_2_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((((sec_r000254_9_1 * 3) + (sec_r000254_9_1 * 2)) - pub_r000254_15_1) + 21) & 127;
  int stage_v_147_2 = ((((sec_r000254_9_2 * 3) + (sec_r000254_9_2 * 2)) - pub_r000254_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((((sec_r000254_1_1 * 3) + (sec_r000254_1_1 * 2)) - pub_r000254_15_1) + 37) & 127;
  int stage_v_148_2 = ((((sec_r000254_1_2 * 3) + (sec_r000254_1_2 * 2)) - pub_r000254_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((((stage_v_145_1 * 3) + (sec_r000254_3_1 * 2)) - pub_r000254_12_1) + 25) & 127;
  int stage_v_149_2 = ((((stage_v_145_2 * 3) + (sec_r000254_3_2 * 2)) - pub_r000254_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((((stage_v_96_1 * 3) + (sec_r000254_11_1 * 2)) - pub_r000254_16_1) + 23) & 127;
  int stage_v_150_2 = ((((stage_v_96_2 * 3) + (sec_r000254_11_2 * 2)) - pub_r000254_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((((stage_v_93_1 * 3) + (sec_r000254_4_1 * 2)) - pub_r000254_15_1) + 36) & 127;
  int stage_v_151_2 = ((((stage_v_93_2 * 3) + (sec_r000254_4_2 * 2)) - pub_r000254_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((((stage_v_115_1 * 3) + (sec_r000254_17_1 * 2)) - pub_r000254_4_1) + 27) & 127;
  int stage_v_152_2 = ((((stage_v_115_2 * 3) + (sec_r000254_17_2 * 2)) - pub_r000254_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((((stage_v_139_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_14_1) + 34) & 127;
  int stage_v_153_2 = ((((stage_v_139_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_14_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((((stage_v_153_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_8_1) + 17) & 127;
  int stage_v_154_2 = ((((stage_v_153_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((((stage_v_109_1 * 3) + (sec_r000254_18_1 * 2)) - pub_r000254_11_1) + 12) & 127;
  int stage_v_155_2 = ((((stage_v_109_2 * 3) + (sec_r000254_18_2 * 2)) - pub_r000254_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((((stage_v_151_1 * 3) + (sec_r000254_13_1 * 2)) - pub_r000254_12_1) + 31) & 127;
  int stage_v_156_2 = ((((stage_v_151_2 * 3) + (sec_r000254_13_2 * 2)) - pub_r000254_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_156_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_156_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((((stage_v_132_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_17_1) + 10) & 127;
  int stage_v_157_2 = ((((stage_v_132_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_17_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((((stage_v_151_1 * 3) + (sec_r000254_11_1 * 2)) - pub_r000254_7_1) + 28) & 127;
  int stage_v_158_2 = ((((stage_v_151_2 * 3) + (sec_r000254_11_2 * 2)) - pub_r000254_7_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((((stage_v_107_1 * 3) + (sec_r000254_18_1 * 2)) - pub_r000254_10_1) + 11) & 127;
  int stage_v_159_2 = ((((stage_v_107_2 * 3) + (sec_r000254_18_2 * 2)) - pub_r000254_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((((sec_r000254_11_1 * 3) + (sec_r000254_11_1 * 2)) - pub_r000254_9_1) + 24) & 127;
  int stage_v_160_2 = ((((sec_r000254_11_2 * 3) + (sec_r000254_11_2 * 2)) - pub_r000254_9_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_160_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_160_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((((stage_v_135_1 * 3) + (sec_r000254_5_1 * 2)) - pub_r000254_1_1) + 8) & 127;
  int stage_v_161_2 = ((((stage_v_135_2 * 3) + (sec_r000254_5_2 * 2)) - pub_r000254_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((((stage_v_96_1 * 3) + (sec_r000254_21_1 * 2)) - pub_r000254_10_1) + 16) & 127;
  int stage_v_162_2 = ((((stage_v_96_2 * 3) + (sec_r000254_21_2 * 2)) - pub_r000254_10_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((((sec_r000254_17_1 * 3) + (sec_r000254_17_1 * 2)) - pub_r000254_0_1) + 13) & 127;
  int stage_v_163_2 = ((((sec_r000254_17_2 * 3) + (sec_r000254_17_2 * 2)) - pub_r000254_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((((stage_v_95_1 * 3) + (sec_r000254_10_1 * 2)) - pub_r000254_3_1) + 20) & 127;
  int stage_v_164_2 = ((((stage_v_95_2 * 3) + (sec_r000254_10_2 * 2)) - pub_r000254_3_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((((sec_r000254_11_1 * 3) + (sec_r000254_11_1 * 2)) - pub_r000254_5_1) + 27) & 127;
  int stage_v_165_2 = ((((sec_r000254_11_2 * 3) + (sec_r000254_11_2 * 2)) - pub_r000254_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((((stage_v_82_1 * 3) + (sec_r000254_18_1 * 2)) - pub_r000254_3_1) + 25) & 127;
  int stage_v_166_2 = ((((stage_v_82_2 * 3) + (sec_r000254_18_2 * 2)) - pub_r000254_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((((stage_v_161_1 * 3) + (sec_r000254_7_1 * 2)) - pub_r000254_16_1) + 9) & 127;
  int stage_v_167_2 = ((((stage_v_161_2 * 3) + (sec_r000254_7_2 * 2)) - pub_r000254_16_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((((sec_r000254_6_1 * 3) + (sec_r000254_6_1 * 2)) - pub_r000254_9_1) + 20) & 127;
  int stage_v_168_2 = ((((sec_r000254_6_2 * 3) + (sec_r000254_6_2 * 2)) - pub_r000254_9_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((((sec_r000254_17_1 * 3) + (sec_r000254_17_1 * 2)) - pub_r000254_10_1) + 16) & 127;
  int stage_v_169_2 = ((((sec_r000254_17_2 * 3) + (sec_r000254_17_2 * 2)) - pub_r000254_10_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((((stage_v_81_1 * 3) + (sec_r000254_12_1 * 2)) - pub_r000254_5_1) + 27) & 127;
  int stage_v_170_2 = ((((stage_v_81_2 * 3) + (sec_r000254_12_2 * 2)) - pub_r000254_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((((sec_r000254_5_1 * 3) + (sec_r000254_5_1 * 2)) - pub_r000254_11_1) + 13) & 127;
  int stage_v_171_2 = ((((sec_r000254_5_2 * 3) + (sec_r000254_5_2 * 2)) - pub_r000254_11_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((((sec_r000254_12_1 * 3) + (sec_r000254_12_1 * 2)) - pub_r000254_13_1) + 28) & 127;
  int stage_v_172_2 = ((((sec_r000254_12_2 * 3) + (sec_r000254_12_2 * 2)) - pub_r000254_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((((stage_v_115_1 * 3) + (sec_r000254_1_1 * 2)) - pub_r000254_10_1) + 30) & 127;
  int stage_v_173_2 = ((((stage_v_115_2 * 3) + (sec_r000254_1_2 * 2)) - pub_r000254_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((((stage_v_113_1 * 3) + (sec_r000254_1_1 * 2)) - pub_r000254_4_1) + 14) & 127;
  int stage_v_174_2 = ((((stage_v_113_2 * 3) + (sec_r000254_1_2 * 2)) - pub_r000254_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_174_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_174_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((((sec_r000254_10_1 * 3) + (sec_r000254_10_1 * 2)) - pub_r000254_3_1) + 22) & 127;
  int stage_v_175_2 = ((((sec_r000254_10_2 * 3) + (sec_r000254_10_2 * 2)) - pub_r000254_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_175_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_175_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((((stage_v_171_1 * 3) + (sec_r000254_21_1 * 2)) - pub_r000254_8_1) + 28) & 127;
  int stage_v_176_2 = ((((stage_v_171_2 * 3) + (sec_r000254_21_2 * 2)) - pub_r000254_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_176_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_176_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((((stage_v_118_1 * 3) + (sec_r000254_0_1 * 2)) - pub_r000254_9_1) + 28) & 127;
  int stage_v_177_2 = ((((stage_v_118_2 * 3) + (sec_r000254_0_2 * 2)) - pub_r000254_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_177_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_177_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((((stage_v_91_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_7_1) + 29) & 127;
  int stage_v_178_2 = ((((stage_v_91_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_7_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_178_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_178_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((((sec_r000254_6_1 * 3) + (sec_r000254_6_1 * 2)) - pub_r000254_10_1) + 34) & 127;
  int stage_v_179_2 = ((((sec_r000254_6_2 * 3) + (sec_r000254_6_2 * 2)) - pub_r000254_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((((stage_v_121_1 * 3) + (sec_r000254_15_1 * 2)) - pub_r000254_3_1) + 37) & 127;
  int stage_v_180_2 = ((((stage_v_121_2 * 3) + (sec_r000254_15_2 * 2)) - pub_r000254_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_180_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_180_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((((stage_v_135_1 * 3) + (sec_r000254_3_1 * 2)) - pub_r000254_12_1) + 12) & 127;
  int stage_v_181_2 = ((((stage_v_135_2 * 3) + (sec_r000254_3_2 * 2)) - pub_r000254_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_181_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_181_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((((stage_v_89_1 * 3) + (sec_r000254_14_1 * 2)) - pub_r000254_6_1) + 12) & 127;
  int stage_v_182_2 = ((((stage_v_89_2 * 3) + (sec_r000254_14_2 * 2)) - pub_r000254_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_182_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_182_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((((stage_v_131_1 * 3) + (sec_r000254_14_1 * 2)) - pub_r000254_5_1) + 11) & 127;
  int stage_v_183_2 = ((((stage_v_131_2 * 3) + (sec_r000254_14_2 * 2)) - pub_r000254_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((((stage_v_97_1 * 3) + (sec_r000254_8_1 * 2)) - pub_r000254_2_1) + 17) & 127;
  int stage_v_184_2 = ((((stage_v_97_2 * 3) + (sec_r000254_8_2 * 2)) - pub_r000254_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_184_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_184_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((((stage_v_121_1 * 3) + (sec_r000254_17_1 * 2)) - pub_r000254_1_1) + 27) & 127;
  int stage_v_185_2 = ((((stage_v_121_2 * 3) + (sec_r000254_17_2 * 2)) - pub_r000254_1_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_185_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_185_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((((sec_r000254_4_1 * 3) + (sec_r000254_4_1 * 2)) - pub_r000254_17_1) + 30) & 127;
  int stage_v_186_2 = ((((sec_r000254_4_2 * 3) + (sec_r000254_4_2 * 2)) - pub_r000254_17_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_186_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_186_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((((stage_v_147_1 * 3) + (sec_r000254_7_1 * 2)) - pub_r000254_0_1) + 6) & 127;
  int stage_v_187_2 = ((((stage_v_147_2 * 3) + (sec_r000254_7_2 * 2)) - pub_r000254_0_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_187_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_187_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((((stage_v_138_1 * 3) + (sec_r000254_21_1 * 2)) - pub_r000254_10_1) + 9) & 127;
  int stage_v_188_2 = ((((stage_v_138_2 * 3) + (sec_r000254_21_2 * 2)) - pub_r000254_10_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_188_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_188_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((((stage_v_179_1 * 3) + (sec_r000254_16_1 * 2)) - pub_r000254_4_1) + 3) & 127;
  int stage_v_189_2 = ((((stage_v_179_2 * 3) + (sec_r000254_16_2 * 2)) - pub_r000254_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_189_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_189_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((((sec_r000254_2_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_8_1) + 32) & 127;
  int stage_v_190_2 = ((((sec_r000254_2_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_190_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_190_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((((stage_v_84_1 * 3) + (sec_r000254_14_1 * 2)) - pub_r000254_3_1) + 28) & 127;
  int stage_v_191_2 = ((((stage_v_84_2 * 3) + (sec_r000254_14_2 * 2)) - pub_r000254_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((((sec_r000254_11_1 * 3) + (sec_r000254_11_1 * 2)) - pub_r000254_2_1) + 3) & 127;
  int stage_v_192_2 = ((((sec_r000254_11_2 * 3) + (sec_r000254_11_2 * 2)) - pub_r000254_2_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_192_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_192_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((((stage_v_188_1 * 3) + (sec_r000254_21_1 * 2)) - pub_r000254_11_1) + 31) & 127;
  int stage_v_193_2 = ((((stage_v_188_2 * 3) + (sec_r000254_21_2 * 2)) - pub_r000254_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_193_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_193_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((((sec_r000254_2_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_14_1) + 8) & 127;
  int stage_v_194_2 = ((((sec_r000254_2_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_194_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_194_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((((stage_v_145_1 * 3) + (sec_r000254_11_1 * 2)) - pub_r000254_5_1) + 21) & 127;
  int stage_v_195_2 = ((((stage_v_145_2 * 3) + (sec_r000254_11_2 * 2)) - pub_r000254_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_195_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_195_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((((sec_r000254_16_1 * 3) + (sec_r000254_16_1 * 2)) - pub_r000254_2_1) + 18) & 127;
  int stage_v_196_2 = ((((sec_r000254_16_2 * 3) + (sec_r000254_16_2 * 2)) - pub_r000254_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_196_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_196_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((((stage_v_165_1 * 3) + (sec_r000254_18_1 * 2)) - pub_r000254_9_1) + 17) & 127;
  int stage_v_197_2 = ((((stage_v_165_2 * 3) + (sec_r000254_18_2 * 2)) - pub_r000254_9_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_197_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_197_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((((sec_r000254_1_1 * 3) + (sec_r000254_1_1 * 2)) - pub_r000254_13_1) + 22) & 127;
  int stage_v_198_2 = ((((sec_r000254_1_2 * 3) + (sec_r000254_1_2 * 2)) - pub_r000254_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_198_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_198_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((((stage_v_122_1 * 3) + (sec_r000254_20_1 * 2)) - pub_r000254_6_1) + 32) & 127;
  int stage_v_199_2 = ((((stage_v_122_2 * 3) + (sec_r000254_20_2 * 2)) - pub_r000254_6_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_199_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_199_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((((sec_r000254_0_1 * 3) + (sec_r000254_0_1 * 2)) - pub_r000254_14_1) + 7) & 127;
  int stage_v_200_2 = ((((sec_r000254_0_2 * 3) + (sec_r000254_0_2 * 2)) - pub_r000254_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_200_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_200_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((((stage_v_189_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_14_1) + 25) & 127;
  int stage_v_201_2 = ((((stage_v_189_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_201_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_201_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((((sec_r000254_2_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_14_1) + 11) & 127;
  int stage_v_202_2 = ((((sec_r000254_2_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_202_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_202_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((((stage_v_153_1 * 3) + (sec_r000254_7_1 * 2)) - pub_r000254_12_1) + 15) & 127;
  int stage_v_203_2 = ((((stage_v_153_2 * 3) + (sec_r000254_7_2 * 2)) - pub_r000254_12_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_203_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_203_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((((stage_v_134_1 * 3) + (sec_r000254_3_1 * 2)) - pub_r000254_10_1) + 35) & 127;
  int stage_v_204_2 = ((((stage_v_134_2 * 3) + (sec_r000254_3_2 * 2)) - pub_r000254_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_204_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_204_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((((stage_v_166_1 * 3) + (sec_r000254_15_1 * 2)) - pub_r000254_8_1) + 13) & 127;
  int stage_v_205_2 = ((((stage_v_166_2 * 3) + (sec_r000254_15_2 * 2)) - pub_r000254_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_205_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_205_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((((stage_v_132_1 * 3) + (sec_r000254_13_1 * 2)) - pub_r000254_16_1) + 11) & 127;
  int stage_v_206_2 = ((((stage_v_132_2 * 3) + (sec_r000254_13_2 * 2)) - pub_r000254_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_206_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_206_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((((sec_r000254_13_1 * 3) + (sec_r000254_13_1 * 2)) - pub_r000254_3_1) + 4) & 127;
  int stage_v_207_2 = ((((sec_r000254_13_2 * 3) + (sec_r000254_13_2 * 2)) - pub_r000254_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_207_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_207_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((((sec_r000254_2_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_1_1) + 20) & 127;
  int stage_v_208_2 = ((((sec_r000254_2_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_208_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_208_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((((stage_v_153_1 * 3) + (sec_r000254_14_1 * 2)) - pub_r000254_8_1) + 10) & 127;
  int stage_v_209_2 = ((((stage_v_153_2 * 3) + (sec_r000254_14_2 * 2)) - pub_r000254_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_209_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_209_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((((stage_v_202_1 * 3) + (sec_r000254_1_1 * 2)) - pub_r000254_0_1) + 16) & 127;
  int stage_v_210_2 = ((((stage_v_202_2 * 3) + (sec_r000254_1_2 * 2)) - pub_r000254_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_210_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_210_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((((stage_v_166_1 * 3) + (sec_r000254_9_1 * 2)) - pub_r000254_4_1) + 21) & 127;
  int stage_v_211_2 = ((((stage_v_166_2 * 3) + (sec_r000254_9_2 * 2)) - pub_r000254_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_211_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_211_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((((stage_v_172_1 * 3) + (sec_r000254_8_1 * 2)) - pub_r000254_4_1) + 6) & 127;
  int stage_v_212_2 = ((((stage_v_172_2 * 3) + (sec_r000254_8_2 * 2)) - pub_r000254_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_212_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_212_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((((sec_r000254_9_1 * 3) + (sec_r000254_9_1 * 2)) - pub_r000254_10_1) + 9) & 127;
  int stage_v_213_2 = ((((sec_r000254_9_2 * 3) + (sec_r000254_9_2 * 2)) - pub_r000254_10_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_213_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_213_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((((stage_v_153_1 * 3) + (sec_r000254_4_1 * 2)) - pub_r000254_9_1) + 20) & 127;
  int stage_v_214_2 = ((((stage_v_153_2 * 3) + (sec_r000254_4_2 * 2)) - pub_r000254_9_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_214_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_214_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((((stage_v_144_1 * 3) + (sec_r000254_12_1 * 2)) - pub_r000254_0_1) + 35) & 127;
  int stage_v_215_2 = ((((stage_v_144_2 * 3) + (sec_r000254_12_2 * 2)) - pub_r000254_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_215_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_215_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((((stage_v_118_1 * 3) + (sec_r000254_0_1 * 2)) - pub_r000254_5_1) + 32) & 127;
  int stage_v_216_2 = ((((stage_v_118_2 * 3) + (sec_r000254_0_2 * 2)) - pub_r000254_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_216_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_216_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((((sec_r000254_10_1 * 3) + (sec_r000254_10_1 * 2)) - pub_r000254_9_1) + 37) & 127;
  int stage_v_217_2 = ((((sec_r000254_10_2 * 3) + (sec_r000254_10_2 * 2)) - pub_r000254_9_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_217_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_217_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((((sec_r000254_1_1 * 3) + (sec_r000254_1_1 * 2)) - pub_r000254_11_1) + 10) & 127;
  int stage_v_218_2 = ((((sec_r000254_1_2 * 3) + (sec_r000254_1_2 * 2)) - pub_r000254_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_218_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_218_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((((stage_v_165_1 * 3) + (sec_r000254_21_1 * 2)) - pub_r000254_4_1) + 30) & 127;
  int stage_v_219_2 = ((((stage_v_165_2 * 3) + (sec_r000254_21_2 * 2)) - pub_r000254_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_219_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_219_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((((stage_v_105_1 * 3) + (sec_r000254_0_1 * 2)) - pub_r000254_13_1) + 23) & 127;
  int stage_v_220_2 = ((((stage_v_105_2 * 3) + (sec_r000254_0_2 * 2)) - pub_r000254_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_220_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_220_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((((stage_v_132_1 * 3) + (sec_r000254_11_1 * 2)) - pub_r000254_5_1) + 3) & 127;
  int stage_v_221_2 = ((((stage_v_132_2 * 3) + (sec_r000254_11_2 * 2)) - pub_r000254_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_221_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_221_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((((stage_v_195_1 * 3) + (sec_r000254_22_1 * 2)) - pub_r000254_11_1) + 3) & 127;
  int stage_v_222_2 = ((((stage_v_195_2 * 3) + (sec_r000254_22_2 * 2)) - pub_r000254_11_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_222_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_222_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((((sec_r000254_0_1 * 3) + (sec_r000254_0_1 * 2)) - pub_r000254_5_1) + 30) & 127;
  int stage_v_223_2 = ((((sec_r000254_0_2 * 3) + (sec_r000254_0_2 * 2)) - pub_r000254_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_223_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_223_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((((stage_v_100_1 * 3) + (sec_r000254_8_1 * 2)) - pub_r000254_3_1) + 36) & 127;
  int stage_v_224_2 = ((((stage_v_100_2 * 3) + (sec_r000254_8_2 * 2)) - pub_r000254_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_224_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_224_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((((stage_v_96_1 * 3) + (sec_r000254_15_1 * 2)) - pub_r000254_2_1) + 33) & 127;
  int stage_v_225_2 = ((((stage_v_96_2 * 3) + (sec_r000254_15_2 * 2)) - pub_r000254_2_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_225_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_225_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((((stage_v_96_1 * 3) + (sec_r000254_22_1 * 2)) - pub_r000254_14_1) + 36) & 127;
  int stage_v_226_2 = ((((stage_v_96_2 * 3) + (sec_r000254_22_2 * 2)) - pub_r000254_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_226_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_226_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((((stage_v_122_1 * 3) + (sec_r000254_18_1 * 2)) - pub_r000254_16_1) + 8) & 127;
  int stage_v_227_2 = ((((stage_v_122_2 * 3) + (sec_r000254_18_2 * 2)) - pub_r000254_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_227_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_227_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((((stage_v_120_1 * 3) + (sec_r000254_21_1 * 2)) - pub_r000254_1_1) + 10) & 127;
  int stage_v_228_2 = ((((stage_v_120_2 * 3) + (sec_r000254_21_2 * 2)) - pub_r000254_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_228_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_228_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((((sec_r000254_8_1 * 3) + (sec_r000254_8_1 * 2)) - pub_r000254_4_1) + 24) & 127;
  int stage_v_229_2 = ((((sec_r000254_8_2 * 3) + (sec_r000254_8_2 * 2)) - pub_r000254_4_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_229_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_229_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((((sec_r000254_11_1 * 3) + (sec_r000254_11_1 * 2)) - pub_r000254_14_1) + 9) & 127;
  int stage_v_230_2 = ((((sec_r000254_11_2 * 3) + (sec_r000254_11_2 * 2)) - pub_r000254_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_230_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_230_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((((sec_r000254_7_1 * 3) + (sec_r000254_7_1 * 2)) - pub_r000254_7_1) + 15) & 127;
  int stage_v_231_2 = ((((sec_r000254_7_2 * 3) + (sec_r000254_7_2 * 2)) - pub_r000254_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_231_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_231_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((((sec_r000254_22_1 * 3) + (sec_r000254_22_1 * 2)) - pub_r000254_4_1) + 28) & 127;
  int stage_v_232_2 = ((((sec_r000254_22_2 * 3) + (sec_r000254_22_2 * 2)) - pub_r000254_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_232_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_232_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((((stage_v_150_1 * 3) + (sec_r000254_21_1 * 2)) - pub_r000254_17_1) + 15) & 127;
  int stage_v_233_2 = ((((stage_v_150_2 * 3) + (sec_r000254_21_2 * 2)) - pub_r000254_17_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_233_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_233_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((((sec_r000254_17_1 * 3) + (sec_r000254_17_1 * 2)) - pub_r000254_17_1) + 10) & 127;
  int stage_v_234_2 = ((((sec_r000254_17_2 * 3) + (sec_r000254_17_2 * 2)) - pub_r000254_17_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_234_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_234_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((((sec_r000254_10_1 * 3) + (sec_r000254_10_1 * 2)) - pub_r000254_12_1) + 5) & 127;
  int stage_v_235_2 = ((((sec_r000254_10_2 * 3) + (sec_r000254_10_2 * 2)) - pub_r000254_12_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_235_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_235_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((((sec_r000254_16_1 * 3) + (sec_r000254_16_1 * 2)) - pub_r000254_13_1) + 8) & 127;
  int stage_v_236_2 = ((((sec_r000254_16_2 * 3) + (sec_r000254_16_2 * 2)) - pub_r000254_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_236_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_236_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((((stage_v_235_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_0_1) + 13) & 127;
  int stage_v_237_2 = ((((stage_v_235_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_237_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_237_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((((stage_v_149_1 * 3) + (sec_r000254_9_1 * 2)) - pub_r000254_8_1) + 20) & 127;
  int stage_v_238_2 = ((((stage_v_149_2 * 3) + (sec_r000254_9_2 * 2)) - pub_r000254_8_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_238_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_238_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((((stage_v_211_1 * 3) + (sec_r000254_5_1 * 2)) - pub_r000254_10_1) + 36) & 127;
  int stage_v_239_2 = ((((stage_v_211_2 * 3) + (sec_r000254_5_2 * 2)) - pub_r000254_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_239_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_239_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((((stage_v_204_1 * 3) + (sec_r000254_13_1 * 2)) - pub_r000254_14_1) + 13) & 127;
  int stage_v_240_2 = ((((stage_v_204_2 * 3) + (sec_r000254_13_2 * 2)) - pub_r000254_14_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_240_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_240_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((((stage_v_99_1 * 3) + (sec_r000254_6_1 * 2)) - pub_r000254_5_1) + 34) & 127;
  int stage_v_241_2 = ((((stage_v_99_2 * 3) + (sec_r000254_6_2 * 2)) - pub_r000254_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_241_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_241_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((((stage_v_90_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_15_1) + 27) & 127;
  int stage_v_242_2 = ((((stage_v_90_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_15_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_242_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_242_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((((stage_v_225_1 * 3) + (sec_r000254_3_1 * 2)) - pub_r000254_2_1) + 21) & 127;
  int stage_v_243_2 = ((((stage_v_225_2 * 3) + (sec_r000254_3_2 * 2)) - pub_r000254_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_243_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_243_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((((stage_v_88_1 * 3) + (sec_r000254_7_1 * 2)) - pub_r000254_6_1) + 26) & 127;
  int stage_v_244_2 = ((((stage_v_88_2 * 3) + (sec_r000254_7_2 * 2)) - pub_r000254_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_244_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_244_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((((stage_v_123_1 * 3) + (sec_r000254_7_1 * 2)) - pub_r000254_2_1) + 5) & 127;
  int stage_v_245_2 = ((((stage_v_123_2 * 3) + (sec_r000254_7_2 * 2)) - pub_r000254_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_245_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_245_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((((sec_r000254_1_1 * 3) + (sec_r000254_1_1 * 2)) - pub_r000254_2_1) + 11) & 127;
  int stage_v_246_2 = ((((sec_r000254_1_2 * 3) + (sec_r000254_1_2 * 2)) - pub_r000254_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_246_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_246_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((((stage_v_205_1 * 3) + (sec_r000254_7_1 * 2)) - pub_r000254_5_1) + 3) & 127;
  int stage_v_247_2 = ((((stage_v_205_2 * 3) + (sec_r000254_7_2 * 2)) - pub_r000254_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_247_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_247_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((((stage_v_156_1 * 3) + (sec_r000254_18_1 * 2)) - pub_r000254_14_1) + 26) & 127;
  int stage_v_248_2 = ((((stage_v_156_2 * 3) + (sec_r000254_18_2 * 2)) - pub_r000254_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_248_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_248_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((((stage_v_150_1 * 3) + (sec_r000254_4_1 * 2)) - pub_r000254_7_1) + 25) & 127;
  int stage_v_249_2 = ((((stage_v_150_2 * 3) + (sec_r000254_4_2 * 2)) - pub_r000254_7_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_249_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_249_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((((stage_v_86_1 * 3) + (sec_r000254_19_1 * 2)) - pub_r000254_0_1) + 9) & 127;
  int stage_v_250_2 = ((((stage_v_86_2 * 3) + (sec_r000254_19_2 * 2)) - pub_r000254_0_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_250_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_250_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((((stage_v_241_1 * 3) + (sec_r000254_18_1 * 2)) - pub_r000254_11_1) + 37) & 127;
  int stage_v_251_2 = ((((stage_v_241_2 * 3) + (sec_r000254_18_2 * 2)) - pub_r000254_11_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_251_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_251_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((((stage_v_89_1 * 3) + (sec_r000254_0_1 * 2)) - pub_r000254_12_1) + 27) & 127;
  int stage_v_252_2 = ((((stage_v_89_2 * 3) + (sec_r000254_0_2 * 2)) - pub_r000254_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_252_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_252_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((((sec_r000254_1_1 * 3) + (sec_r000254_1_1 * 2)) - pub_r000254_9_1) + 18) & 127;
  int stage_v_253_2 = ((((sec_r000254_1_2 * 3) + (sec_r000254_1_2 * 2)) - pub_r000254_9_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_253_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_253_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((((stage_v_209_1 * 3) + (sec_r000254_9_1 * 2)) - pub_r000254_12_1) + 13) & 127;
  int stage_v_254_2 = ((((stage_v_209_2 * 3) + (sec_r000254_9_2 * 2)) - pub_r000254_12_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_254_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_254_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((((sec_r000254_8_1 * 3) + (sec_r000254_8_1 * 2)) - pub_r000254_17_1) + 21) & 127;
  int stage_v_255_2 = ((((sec_r000254_8_2 * 3) + (sec_r000254_8_2 * 2)) - pub_r000254_17_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_255_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_255_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((((stage_v_145_1 * 3) + (sec_r000254_13_1 * 2)) - pub_r000254_13_1) + 33) & 127;
  int stage_v_256_2 = ((((stage_v_145_2 * 3) + (sec_r000254_13_2 * 2)) - pub_r000254_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_256_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_256_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((((stage_v_98_1 * 3) + (sec_r000254_16_1 * 2)) - pub_r000254_6_1) + 17) & 127;
  int stage_v_257_2 = ((((stage_v_98_2 * 3) + (sec_r000254_16_2 * 2)) - pub_r000254_6_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_257_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_257_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((((stage_v_114_1 * 3) + (sec_r000254_1_1 * 2)) - pub_r000254_2_1) + 33) & 127;
  int stage_v_258_2 = ((((stage_v_114_2 * 3) + (sec_r000254_1_2 * 2)) - pub_r000254_2_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_258_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_258_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((((stage_v_240_1 * 3) + (sec_r000254_7_1 * 2)) - pub_r000254_14_1) + 17) & 127;
  int stage_v_259_2 = ((((stage_v_240_2 * 3) + (sec_r000254_7_2 * 2)) - pub_r000254_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_259_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_259_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((((sec_r000254_8_1 * 3) + (sec_r000254_8_1 * 2)) - pub_r000254_5_1) + 27) & 127;
  int stage_v_260_2 = ((((sec_r000254_8_2 * 3) + (sec_r000254_8_2 * 2)) - pub_r000254_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_260_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_260_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((((stage_v_122_1 * 3) + (sec_r000254_19_1 * 2)) - pub_r000254_6_1) + 17) & 127;
  int stage_v_261_2 = ((((stage_v_122_2 * 3) + (sec_r000254_19_2 * 2)) - pub_r000254_6_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_261_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_261_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((((stage_v_125_1 * 3) + (sec_r000254_14_1 * 2)) - pub_r000254_6_1) + 5) & 127;
  int stage_v_262_2 = ((((stage_v_125_2 * 3) + (sec_r000254_14_2 * 2)) - pub_r000254_6_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_262_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_262_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((((stage_v_185_1 * 3) + (sec_r000254_11_1 * 2)) - pub_r000254_1_1) + 23) & 127;
  int stage_v_263_2 = ((((stage_v_185_2 * 3) + (sec_r000254_11_2 * 2)) - pub_r000254_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_263_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_263_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((((stage_v_117_1 * 3) + (sec_r000254_11_1 * 2)) - pub_r000254_1_1) + 4) & 127;
  int stage_v_264_2 = ((((stage_v_117_2 * 3) + (sec_r000254_11_2 * 2)) - pub_r000254_1_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_264_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_264_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((((stage_v_205_1 * 3) + (sec_r000254_18_1 * 2)) - pub_r000254_17_1) + 15) & 127;
  int stage_v_265_2 = ((((stage_v_205_2 * 3) + (sec_r000254_18_2 * 2)) - pub_r000254_17_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_265_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_265_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((((sec_r000254_10_1 * 3) + (sec_r000254_10_1 * 2)) - pub_r000254_3_1) + 17) & 127;
  int stage_v_266_2 = ((((sec_r000254_10_2 * 3) + (sec_r000254_10_2 * 2)) - pub_r000254_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_266_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_266_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((((stage_v_114_1 * 3) + (sec_r000254_0_1 * 2)) - pub_r000254_7_1) + 23) & 127;
  int stage_v_267_2 = ((((stage_v_114_2 * 3) + (sec_r000254_0_2 * 2)) - pub_r000254_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_267_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_267_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((((stage_v_95_1 * 3) + (sec_r000254_21_1 * 2)) - pub_r000254_11_1) + 6) & 127;
  int stage_v_268_2 = ((((stage_v_95_2 * 3) + (sec_r000254_21_2 * 2)) - pub_r000254_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_268_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_268_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((((stage_v_155_1 * 3) + (sec_r000254_13_1 * 2)) - pub_r000254_13_1) + 16) & 127;
  int stage_v_269_2 = ((((stage_v_155_2 * 3) + (sec_r000254_13_2 * 2)) - pub_r000254_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_269_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_269_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((((stage_v_193_1 * 3) + (sec_r000254_12_1 * 2)) - pub_r000254_17_1) + 18) & 127;
  int stage_v_270_2 = ((((stage_v_193_2 * 3) + (sec_r000254_12_2 * 2)) - pub_r000254_17_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_270_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_270_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((((sec_r000254_4_1 * 3) + (sec_r000254_4_1 * 2)) - pub_r000254_1_1) + 29) & 127;
  int stage_v_271_2 = ((((sec_r000254_4_2 * 3) + (sec_r000254_4_2 * 2)) - pub_r000254_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_271_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_271_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((((stage_v_250_1 * 3) + (sec_r000254_6_1 * 2)) - pub_r000254_13_1) + 18) & 127;
  int stage_v_272_2 = ((((stage_v_250_2 * 3) + (sec_r000254_6_2 * 2)) - pub_r000254_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_272_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_272_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((((stage_v_90_1 * 3) + (sec_r000254_14_1 * 2)) - pub_r000254_8_1) + 28) & 127;
  int stage_v_273_2 = ((((stage_v_90_2 * 3) + (sec_r000254_14_2 * 2)) - pub_r000254_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_273_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_273_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((((sec_r000254_21_1 * 3) + (sec_r000254_21_1 * 2)) - pub_r000254_15_1) + 15) & 127;
  int stage_v_274_2 = ((((sec_r000254_21_2 * 3) + (sec_r000254_21_2 * 2)) - pub_r000254_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_274_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_274_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((((stage_v_182_1 * 3) + (sec_r000254_3_1 * 2)) - pub_r000254_15_1) + 21) & 127;
  int stage_v_275_2 = ((((stage_v_182_2 * 3) + (sec_r000254_3_2 * 2)) - pub_r000254_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_275_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_275_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((((stage_v_166_1 * 3) + (sec_r000254_16_1 * 2)) - pub_r000254_11_1) + 4) & 127;
  int stage_v_276_2 = ((((stage_v_166_2 * 3) + (sec_r000254_16_2 * 2)) - pub_r000254_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_276_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_276_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((((sec_r000254_7_1 * 3) + (sec_r000254_7_1 * 2)) - pub_r000254_16_1) + 25) & 127;
  int stage_v_277_2 = ((((sec_r000254_7_2 * 3) + (sec_r000254_7_2 * 2)) - pub_r000254_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_277_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_277_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((((stage_v_263_1 * 3) + (sec_r000254_14_1 * 2)) - pub_r000254_3_1) + 22) & 127;
  int stage_v_278_2 = ((((stage_v_263_2 * 3) + (sec_r000254_14_2 * 2)) - pub_r000254_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_278_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_278_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((((sec_r000254_3_1 * 3) + (sec_r000254_3_1 * 2)) - pub_r000254_14_1) + 3) & 127;
  int stage_v_279_2 = ((((sec_r000254_3_2 * 3) + (sec_r000254_3_2 * 2)) - pub_r000254_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_279_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_279_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((((stage_v_93_1 * 3) + (sec_r000254_22_1 * 2)) - pub_r000254_8_1) + 3) & 127;
  int stage_v_280_2 = ((((stage_v_93_2 * 3) + (sec_r000254_22_2 * 2)) - pub_r000254_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_280_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_280_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((((stage_v_166_1 * 3) + (sec_r000254_9_1 * 2)) - pub_r000254_6_1) + 22) & 127;
  int stage_v_281_2 = ((((stage_v_166_2 * 3) + (sec_r000254_9_2 * 2)) - pub_r000254_6_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_281_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_281_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((((sec_r000254_10_1 * 3) + (sec_r000254_10_1 * 2)) - pub_r000254_5_1) + 33) & 127;
  int stage_v_282_2 = ((((sec_r000254_10_2 * 3) + (sec_r000254_10_2 * 2)) - pub_r000254_5_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_282_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_282_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((((stage_v_126_1 * 3) + (sec_r000254_14_1 * 2)) - pub_r000254_14_1) + 21) & 127;
  int stage_v_283_2 = ((((stage_v_126_2 * 3) + (sec_r000254_14_2 * 2)) - pub_r000254_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_283_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_283_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((((sec_r000254_15_1 * 3) + (sec_r000254_15_1 * 2)) - pub_r000254_17_1) + 36) & 127;
  int stage_v_284_2 = ((((sec_r000254_15_2 * 3) + (sec_r000254_15_2 * 2)) - pub_r000254_17_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_284_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_284_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((((stage_v_223_1 * 3) + (sec_r000254_16_1 * 2)) - pub_r000254_7_1) + 15) & 127;
  int stage_v_285_2 = ((((stage_v_223_2 * 3) + (sec_r000254_16_2 * 2)) - pub_r000254_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_285_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_285_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((((stage_v_110_1 * 3) + (sec_r000254_15_1 * 2)) - pub_r000254_2_1) + 11) & 127;
  int stage_v_286_2 = ((((stage_v_110_2 * 3) + (sec_r000254_15_2 * 2)) - pub_r000254_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_286_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_286_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((((stage_v_115_1 * 3) + (sec_r000254_7_1 * 2)) - pub_r000254_2_1) + 19) & 127;
  int stage_v_287_2 = ((((stage_v_115_2 * 3) + (sec_r000254_7_2 * 2)) - pub_r000254_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_287_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_287_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((((stage_v_159_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_10_1) + 11) & 127;
  int stage_v_288_2 = ((((stage_v_159_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_288_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_288_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((((sec_r000254_5_1 * 3) + (sec_r000254_5_1 * 2)) - pub_r000254_15_1) + 16) & 127;
  int stage_v_289_2 = ((((sec_r000254_5_2 * 3) + (sec_r000254_5_2 * 2)) - pub_r000254_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_289_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_289_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((((stage_v_161_1 * 3) + (sec_r000254_22_1 * 2)) - pub_r000254_3_1) + 15) & 127;
  int stage_v_290_2 = ((((stage_v_161_2 * 3) + (sec_r000254_22_2 * 2)) - pub_r000254_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_290_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_290_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((((sec_r000254_9_1 * 3) + (sec_r000254_9_1 * 2)) - pub_r000254_1_1) + 15) & 127;
  int stage_v_291_2 = ((((sec_r000254_9_2 * 3) + (sec_r000254_9_2 * 2)) - pub_r000254_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_291_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_291_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((((stage_v_147_1 * 3) + (sec_r000254_8_1 * 2)) - pub_r000254_9_1) + 7) & 127;
  int stage_v_292_2 = ((((stage_v_147_2 * 3) + (sec_r000254_8_2 * 2)) - pub_r000254_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_292_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_292_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((((sec_r000254_8_1 * 3) + (sec_r000254_8_1 * 2)) - pub_r000254_11_1) + 27) & 127;
  int stage_v_293_2 = ((((sec_r000254_8_2 * 3) + (sec_r000254_8_2 * 2)) - pub_r000254_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_293_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_293_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((((stage_v_282_1 * 3) + (sec_r000254_19_1 * 2)) - pub_r000254_9_1) + 10) & 127;
  int stage_v_294_2 = ((((stage_v_282_2 * 3) + (sec_r000254_19_2 * 2)) - pub_r000254_9_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_294_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_294_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((((sec_r000254_3_1 * 3) + (sec_r000254_3_1 * 2)) - pub_r000254_16_1) + 16) & 127;
  int stage_v_295_2 = ((((sec_r000254_3_2 * 3) + (sec_r000254_3_2 * 2)) - pub_r000254_16_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_295_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_295_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((((stage_v_237_1 * 3) + (sec_r000254_1_1 * 2)) - pub_r000254_13_1) + 11) & 127;
  int stage_v_296_2 = ((((stage_v_237_2 * 3) + (sec_r000254_1_2 * 2)) - pub_r000254_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_296_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_296_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((((stage_v_276_1 * 3) + (sec_r000254_5_1 * 2)) - pub_r000254_0_1) + 34) & 127;
  int stage_v_297_2 = ((((stage_v_276_2 * 3) + (sec_r000254_5_2 * 2)) - pub_r000254_0_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_297_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_297_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int stage_v_298_1 = ((((stage_v_150_1 * 3) + (sec_r000254_16_1 * 2)) - pub_r000254_10_1) + 3) & 127;
  int stage_v_298_2 = ((((stage_v_150_2 * 3) + (sec_r000254_16_2 * 2)) - pub_r000254_10_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_298_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_298_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int stage_v_299_1 = ((((stage_v_274_1 * 3) + (sec_r000254_16_1 * 2)) - pub_r000254_0_1) + 8) & 127;
  int stage_v_299_2 = ((((stage_v_274_2 * 3) + (sec_r000254_16_2 * 2)) - pub_r000254_0_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_299_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_299_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int stage_v_300_1 = ((((stage_v_100_1 * 3) + (sec_r000254_8_1 * 2)) - pub_r000254_14_1) + 29) & 127;
  int stage_v_300_2 = ((((stage_v_100_2 * 3) + (sec_r000254_8_2 * 2)) - pub_r000254_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_300_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_300_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int stage_v_301_1 = ((((sec_r000254_10_1 * 3) + (sec_r000254_10_1 * 2)) - pub_r000254_7_1) + 34) & 127;
  int stage_v_301_2 = ((((sec_r000254_10_2 * 3) + (sec_r000254_10_2 * 2)) - pub_r000254_7_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_301_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_301_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int stage_v_302_1 = ((((stage_v_234_1 * 3) + (sec_r000254_15_1 * 2)) - pub_r000254_15_1) + 8) & 127;
  int stage_v_302_2 = ((((stage_v_234_2 * 3) + (sec_r000254_15_2 * 2)) - pub_r000254_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_302_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_302_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int stage_v_303_1 = ((((stage_v_294_1 * 3) + (sec_r000254_17_1 * 2)) - pub_r000254_10_1) + 24) & 127;
  int stage_v_303_2 = ((((stage_v_294_2 * 3) + (sec_r000254_17_2 * 2)) - pub_r000254_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_303_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_303_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int stage_v_304_1 = ((((stage_v_266_1 * 3) + (sec_r000254_21_1 * 2)) - pub_r000254_7_1) + 34) & 127;
  int stage_v_304_2 = ((((stage_v_266_2 * 3) + (sec_r000254_21_2 * 2)) - pub_r000254_7_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_304_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_304_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int stage_v_305_1 = ((((stage_v_155_1 * 3) + (sec_r000254_11_1 * 2)) - pub_r000254_3_1) + 27) & 127;
  int stage_v_305_2 = ((((stage_v_155_2 * 3) + (sec_r000254_11_2 * 2)) - pub_r000254_3_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_305_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_305_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  int stage_v_306_1 = ((((stage_v_147_1 * 3) + (sec_r000254_12_1 * 2)) - pub_r000254_14_1) + 30) & 127;
  int stage_v_306_2 = ((((stage_v_147_2 * 3) + (sec_r000254_12_2 * 2)) - pub_r000254_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_306_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_306_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_306_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_306_2) & 255;
  int stage_v_307_1 = ((((stage_v_170_1 * 3) + (sec_r000254_3_1 * 2)) - pub_r000254_6_1) + 23) & 127;
  int stage_v_307_2 = ((((stage_v_170_2 * 3) + (sec_r000254_3_2 * 2)) - pub_r000254_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_307_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_307_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_307_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_307_2) & 255;
  int stage_v_308_1 = ((((stage_v_200_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_11_1) + 6) & 127;
  int stage_v_308_2 = ((((stage_v_200_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_308_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_308_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_308_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_308_2) & 255;
  int stage_v_309_1 = ((((stage_v_104_1 * 3) + (sec_r000254_10_1 * 2)) - pub_r000254_0_1) + 30) & 127;
  int stage_v_309_2 = ((((stage_v_104_2 * 3) + (sec_r000254_10_2 * 2)) - pub_r000254_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_309_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_309_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_309_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_309_2) & 255;
  int stage_v_310_1 = ((((sec_r000254_12_1 * 3) + (sec_r000254_12_1 * 2)) - pub_r000254_3_1) + 17) & 127;
  int stage_v_310_2 = ((((sec_r000254_12_2 * 3) + (sec_r000254_12_2 * 2)) - pub_r000254_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_310_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_310_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_310_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_310_2) & 255;
  int stage_v_311_1 = ((((stage_v_101_1 * 3) + (sec_r000254_19_1 * 2)) - pub_r000254_3_1) + 33) & 127;
  int stage_v_311_2 = ((((stage_v_101_2 * 3) + (sec_r000254_19_2 * 2)) - pub_r000254_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_311_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_311_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_311_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_311_2) & 255;
  int stage_v_312_1 = ((((stage_v_276_1 * 3) + (sec_r000254_18_1 * 2)) - pub_r000254_17_1) + 25) & 127;
  int stage_v_312_2 = ((((stage_v_276_2 * 3) + (sec_r000254_18_2 * 2)) - pub_r000254_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_312_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_312_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_312_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_312_2) & 255;
  int stage_v_313_1 = ((((stage_v_266_1 * 3) + (sec_r000254_19_1 * 2)) - pub_r000254_12_1) + 25) & 127;
  int stage_v_313_2 = ((((stage_v_266_2 * 3) + (sec_r000254_19_2 * 2)) - pub_r000254_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_313_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_313_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_313_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_313_2) & 255;
  int stage_v_314_1 = ((((stage_v_208_1 * 3) + (sec_r000254_7_1 * 2)) - pub_r000254_0_1) + 16) & 127;
  int stage_v_314_2 = ((((stage_v_208_2 * 3) + (sec_r000254_7_2 * 2)) - pub_r000254_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_314_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_314_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_314_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_314_2) & 255;
  int stage_v_315_1 = ((((stage_v_144_1 * 3) + (sec_r000254_3_1 * 2)) - pub_r000254_15_1) + 16) & 127;
  int stage_v_315_2 = ((((stage_v_144_2 * 3) + (sec_r000254_3_2 * 2)) - pub_r000254_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_315_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_315_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_315_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_315_2) & 255;
  int stage_v_316_1 = ((((sec_r000254_6_1 * 3) + (sec_r000254_6_1 * 2)) - pub_r000254_11_1) + 14) & 127;
  int stage_v_316_2 = ((((sec_r000254_6_2 * 3) + (sec_r000254_6_2 * 2)) - pub_r000254_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_316_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_316_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_316_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_316_2) & 255;
  int stage_v_317_1 = ((((stage_v_165_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_5_1) + 34) & 127;
  int stage_v_317_2 = ((((stage_v_165_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_317_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_317_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_317_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_317_2) & 255;
  int stage_v_318_1 = ((((stage_v_110_1 * 3) + (sec_r000254_5_1 * 2)) - pub_r000254_3_1) + 18) & 127;
  int stage_v_318_2 = ((((stage_v_110_2 * 3) + (sec_r000254_5_2 * 2)) - pub_r000254_3_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_318_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_318_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_318_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_318_2) & 255;
  int stage_v_319_1 = ((((stage_v_188_1 * 3) + (sec_r000254_12_1 * 2)) - pub_r000254_13_1) + 23) & 127;
  int stage_v_319_2 = ((((stage_v_188_2 * 3) + (sec_r000254_12_2 * 2)) - pub_r000254_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_319_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_319_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_319_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_319_2) & 255;
  int stage_v_320_1 = ((((sec_r000254_11_1 * 3) + (sec_r000254_11_1 * 2)) - pub_r000254_15_1) + 11) & 127;
  int stage_v_320_2 = ((((sec_r000254_11_2 * 3) + (sec_r000254_11_2 * 2)) - pub_r000254_15_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_320_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_320_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_320_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_320_2) & 255;
  int stage_v_321_1 = ((((sec_r000254_5_1 * 3) + (sec_r000254_5_1 * 2)) - pub_r000254_2_1) + 30) & 127;
  int stage_v_321_2 = ((((sec_r000254_5_2 * 3) + (sec_r000254_5_2 * 2)) - pub_r000254_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_321_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_321_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_321_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_321_2) & 255;
  int stage_v_322_1 = ((((sec_r000254_22_1 * 3) + (sec_r000254_22_1 * 2)) - pub_r000254_3_1) + 31) & 127;
  int stage_v_322_2 = ((((sec_r000254_22_2 * 3) + (sec_r000254_22_2 * 2)) - pub_r000254_3_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_322_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_322_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_322_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_322_2) & 255;
  int stage_v_323_1 = ((((stage_v_253_1 * 3) + (sec_r000254_11_1 * 2)) - pub_r000254_6_1) + 33) & 127;
  int stage_v_323_2 = ((((stage_v_253_2 * 3) + (sec_r000254_11_2 * 2)) - pub_r000254_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_323_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_323_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_323_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_323_2) & 255;
  int stage_v_324_1 = ((((stage_v_220_1 * 3) + (sec_r000254_0_1 * 2)) - pub_r000254_17_1) + 21) & 127;
  int stage_v_324_2 = ((((stage_v_220_2 * 3) + (sec_r000254_0_2 * 2)) - pub_r000254_17_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_324_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_324_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_324_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_324_2) & 255;
  int stage_v_325_1 = ((((sec_r000254_13_1 * 3) + (sec_r000254_13_1 * 2)) - pub_r000254_0_1) + 3) & 127;
  int stage_v_325_2 = ((((sec_r000254_13_2 * 3) + (sec_r000254_13_2 * 2)) - pub_r000254_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_325_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_325_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_325_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_325_2) & 255;
  int stage_v_326_1 = ((((stage_v_177_1 * 3) + (sec_r000254_6_1 * 2)) - pub_r000254_17_1) + 22) & 127;
  int stage_v_326_2 = ((((stage_v_177_2 * 3) + (sec_r000254_6_2 * 2)) - pub_r000254_17_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_326_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_326_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_326_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_326_2) & 255;
  int stage_v_327_1 = ((((stage_v_288_1 * 3) + (sec_r000254_9_1 * 2)) - pub_r000254_7_1) + 19) & 127;
  int stage_v_327_2 = ((((stage_v_288_2 * 3) + (sec_r000254_9_2 * 2)) - pub_r000254_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_327_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_327_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_327_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_327_2) & 255;
  int stage_v_328_1 = ((((sec_r000254_2_1 * 3) + (sec_r000254_2_1 * 2)) - pub_r000254_13_1) + 30) & 127;
  int stage_v_328_2 = ((((sec_r000254_2_2 * 3) + (sec_r000254_2_2 * 2)) - pub_r000254_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_328_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_328_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_328_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_328_2) & 255;
  int stage_v_329_1 = ((((stage_v_261_1 * 3) + (sec_r000254_11_1 * 2)) - pub_r000254_2_1) + 13) & 127;
  int stage_v_329_2 = ((((stage_v_261_2 * 3) + (sec_r000254_11_2 * 2)) - pub_r000254_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_329_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_329_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_329_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_329_2) & 255;
  int stage_v_330_1 = ((((stage_v_251_1 * 3) + (sec_r000254_15_1 * 2)) - pub_r000254_6_1) + 13) & 127;
  int stage_v_330_2 = ((((stage_v_251_2 * 3) + (sec_r000254_15_2 * 2)) - pub_r000254_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_330_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_330_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_330_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_330_2) & 255;
  int stage_v_331_1 = ((((sec_r000254_12_1 * 3) + (sec_r000254_12_1 * 2)) - pub_r000254_15_1) + 19) & 127;
  int stage_v_331_2 = ((((sec_r000254_12_2 * 3) + (sec_r000254_12_2 * 2)) - pub_r000254_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_331_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_331_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_331_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_331_2) & 255;
  int stage_v_332_1 = ((((sec_r000254_7_1 * 3) + (sec_r000254_7_1 * 2)) - pub_r000254_12_1) + 25) & 127;
  int stage_v_332_2 = ((((sec_r000254_7_2 * 3) + (sec_r000254_7_2 * 2)) - pub_r000254_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_332_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_332_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_332_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_332_2) & 255;
  int stage_v_333_1 = ((((stage_v_246_1 * 3) + (sec_r000254_16_1 * 2)) - pub_r000254_5_1) + 23) & 127;
  int stage_v_333_2 = ((((stage_v_246_2 * 3) + (sec_r000254_16_2 * 2)) - pub_r000254_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_333_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_333_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_333_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_333_2) & 255;
  int stage_v_334_1 = ((((stage_v_301_1 * 3) + (sec_r000254_14_1 * 2)) - pub_r000254_8_1) + 15) & 127;
  int stage_v_334_2 = ((((stage_v_301_2 * 3) + (sec_r000254_14_2 * 2)) - pub_r000254_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_334_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_334_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_334_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_334_2) & 255;
  int stage_v_335_1 = ((((stage_v_291_1 * 3) + (sec_r000254_12_1 * 2)) - pub_r000254_13_1) + 9) & 127;
  int stage_v_335_2 = ((((stage_v_291_2 * 3) + (sec_r000254_12_2 * 2)) - pub_r000254_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_335_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_335_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_335_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_335_2) & 255;
  int stage_v_336_1 = ((((stage_v_206_1 * 3) + (sec_r000254_8_1 * 2)) - pub_r000254_5_1) + 31) & 127;
  int stage_v_336_2 = ((((stage_v_206_2 * 3) + (sec_r000254_8_2 * 2)) - pub_r000254_5_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_336_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_336_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_336_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_336_2) & 255;
  int stage_v_337_1 = ((((stage_v_297_1 * 3) + (sec_r000254_0_1 * 2)) - pub_r000254_14_1) + 6) & 127;
  int stage_v_337_2 = ((((stage_v_297_2 * 3) + (sec_r000254_0_2 * 2)) - pub_r000254_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_337_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_337_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_337_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_337_2) & 255;
  int stage_v_338_1 = ((((sec_r000254_4_1 * 3) + (sec_r000254_4_1 * 2)) - pub_r000254_4_1) + 9) & 127;
  int stage_v_338_2 = ((((sec_r000254_4_2 * 3) + (sec_r000254_4_2 * 2)) - pub_r000254_4_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_338_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_338_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_338_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_338_2) & 255;
  int stage_v_339_1 = ((((stage_v_201_1 * 3) + (sec_r000254_18_1 * 2)) - pub_r000254_4_1) + 6) & 127;
  int stage_v_339_2 = ((((stage_v_201_2 * 3) + (sec_r000254_18_2 * 2)) - pub_r000254_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_339_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_339_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_339_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_339_2) & 255;
  int stage_v_340_1 = ((((stage_v_83_1 * 3) + (sec_r000254_0_1 * 2)) - pub_r000254_12_1) + 17) & 127;
  int stage_v_340_2 = ((((stage_v_83_2 * 3) + (sec_r000254_0_2 * 2)) - pub_r000254_12_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_340_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_340_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_340_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_340_2) & 255;
  int stage_v_341_1 = ((((stage_v_85_1 * 3) + (sec_r000254_4_1 * 2)) - pub_r000254_3_1) + 29) & 127;
  int stage_v_341_2 = ((((stage_v_85_2 * 3) + (sec_r000254_4_2 * 2)) - pub_r000254_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_341_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_341_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_341_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_341_2) & 255;
  int stage_v_342_1 = ((((sec_r000254_10_1 * 3) + (sec_r000254_10_1 * 2)) - pub_r000254_14_1) + 17) & 127;
  int stage_v_342_2 = ((((sec_r000254_10_2 * 3) + (sec_r000254_10_2 * 2)) - pub_r000254_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_342_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_342_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_342_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_342_2) & 255;
  int stage_v_343_1 = ((((sec_r000254_5_1 * 3) + (sec_r000254_5_1 * 2)) - pub_r000254_1_1) + 35) & 127;
  int stage_v_343_2 = ((((sec_r000254_5_2 * 3) + (sec_r000254_5_2 * 2)) - pub_r000254_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_343_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_343_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_343_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_343_2) & 255;
  int stage_v_344_1 = ((((sec_r000254_9_1 * 3) + (sec_r000254_9_1 * 2)) - pub_r000254_9_1) + 9) & 127;
  int stage_v_344_2 = ((((sec_r000254_9_2 * 3) + (sec_r000254_9_2 * 2)) - pub_r000254_9_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_344_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_344_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_344_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_344_2) & 255;
  int stage_v_345_1 = ((((sec_r000254_14_1 * 3) + (sec_r000254_14_1 * 2)) - pub_r000254_9_1) + 33) & 127;
  int stage_v_345_2 = ((((sec_r000254_14_2 * 3) + (sec_r000254_14_2 * 2)) - pub_r000254_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_345_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_345_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_345_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_345_2) & 255;
  int stage_v_346_1 = ((((sec_r000254_19_1 * 3) + (sec_r000254_19_1 * 2)) - pub_r000254_14_1) + 13) & 127;
  int stage_v_346_2 = ((((sec_r000254_19_2 * 3) + (sec_r000254_19_2 * 2)) - pub_r000254_14_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_346_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_346_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_346_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_346_2) & 255;
  int stage_v_347_1 = ((((stage_v_310_1 * 3) + (sec_r000254_14_1 * 2)) - pub_r000254_15_1) + 18) & 127;
  int stage_v_347_2 = ((((stage_v_310_2 * 3) + (sec_r000254_14_2 * 2)) - pub_r000254_15_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_347_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_347_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_347_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_347_2) & 255;
  int stage_v_348_1 = ((((stage_v_333_1 * 3) + (sec_r000254_7_1 * 2)) - pub_r000254_11_1) + 32) & 127;
  int stage_v_348_2 = ((((stage_v_333_2 * 3) + (sec_r000254_7_2 * 2)) - pub_r000254_11_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_348_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_348_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_348_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_348_2) & 255;
  int stage_v_349_1 = ((((stage_v_182_1 * 3) + (sec_r000254_1_1 * 2)) - pub_r000254_2_1) + 3) & 127;
  int stage_v_349_2 = ((((stage_v_182_2 * 3) + (sec_r000254_1_2 * 2)) - pub_r000254_2_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_349_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_349_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_349_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_349_2) & 255;
  int stage_v_350_1 = ((((stage_v_317_1 * 3) + (sec_r000254_1_1 * 2)) - pub_r000254_16_1) + 28) & 127;
  int stage_v_350_2 = ((((stage_v_317_2 * 3) + (sec_r000254_1_2 * 2)) - pub_r000254_16_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_350_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_350_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_350_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_350_2) & 255;
  int stage_v_351_1 = ((((sec_r000254_3_1 * 3) + (sec_r000254_3_1 * 2)) - pub_r000254_9_1) + 16) & 127;
  int stage_v_351_2 = ((((sec_r000254_3_2 * 3) + (sec_r000254_3_2 * 2)) - pub_r000254_9_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_351_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_351_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_351_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_351_2) & 255;
  int stage_v_352_1 = ((((stage_v_91_1 * 3) + (sec_r000254_17_1 * 2)) - pub_r000254_10_1) + 23) & 127;
  int stage_v_352_2 = ((((stage_v_91_2 * 3) + (sec_r000254_17_2 * 2)) - pub_r000254_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_352_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_352_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_352_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_352_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000254_7_1 == pub_r000254_7_2);
  __CPROVER_assume(pub_r000254_16_1 == pub_r000254_16_2);
  __CPROVER_assume(pub_r000254_15_1 == pub_r000254_15_2);
  __CPROVER_assume(sec_r000254_9_1 != sec_r000254_9_2);
  __CPROVER_assume(sec_r000254_14_1 != sec_r000254_14_2);
  __CPROVER_assume(sec_r000254_20_1 != sec_r000254_20_2);
  __CPROVER_assume(sec_r000254_12_1 != sec_r000254_12_2);
  __CPROVER_assume(sec_r000254_4_1 != sec_r000254_4_2);
  __CPROVER_assume(sec_r000254_21_1 != sec_r000254_21_2);
  __CPROVER_assume(sec_r000254_3_1 != sec_r000254_3_2);
  __CPROVER_assume(sec_r000254_7_1 != sec_r000254_7_2);
  __CPROVER_assume(pub_r000254_11_1 == pub_r000254_11_2);
  __CPROVER_assume(sec_r000254_18_1 != sec_r000254_18_2);
  __CPROVER_assume(pub_r000254_6_1 == pub_r000254_6_2);
  __CPROVER_assume(pub_r000254_1_1 == pub_r000254_1_2);
  __CPROVER_assume(sec_r000254_11_1 != sec_r000254_11_2);
  __CPROVER_assume(pub_r000254_4_1 == pub_r000254_4_2);
  __CPROVER_assume(sec_r000254_10_1 != sec_r000254_10_2);
  __CPROVER_assume(pub_r000254_14_1 == pub_r000254_14_2);
  __CPROVER_assume(sec_r000254_5_1 != sec_r000254_5_2);
  __CPROVER_assume(sec_r000254_16_1 != sec_r000254_16_2);
  __CPROVER_assume(sec_r000254_0_1 != sec_r000254_0_2);
  __CPROVER_assume(sec_r000254_8_1 != sec_r000254_8_2);
  __CPROVER_assume(pub_r000254_10_1 == pub_r000254_10_2);
  __CPROVER_assume(pub_r000254_8_1 == pub_r000254_8_2);
  __CPROVER_assume(pub_r000254_9_1 == pub_r000254_9_2);
  __CPROVER_assume(pub_r000254_3_1 == pub_r000254_3_2);
  __CPROVER_assume(sec_r000254_17_1 != sec_r000254_17_2);
  __CPROVER_assume(sec_r000254_15_1 != sec_r000254_15_2);
  __CPROVER_assume(sec_r000254_2_1 != sec_r000254_2_2);
  __CPROVER_assume(sec_r000254_13_1 != sec_r000254_13_2);
  __CPROVER_assume(sec_r000254_22_1 != sec_r000254_22_2);
  __CPROVER_assume(pub_r000254_5_1 == pub_r000254_5_2);
  __CPROVER_assume(sec_r000254_1_1 != sec_r000254_1_2);
  __CPROVER_assume(sec_r000254_6_1 != sec_r000254_6_2);
  __CPROVER_assume(pub_r000254_12_1 == pub_r000254_12_2);
  __CPROVER_assume(pub_r000254_2_1 == pub_r000254_2_2);
  __CPROVER_assume(pub_r000254_13_1 == pub_r000254_13_2);
  __CPROVER_assume(sec_r000254_19_1 != sec_r000254_19_2);
  __CPROVER_assume(pub_r000254_0_1 == pub_r000254_0_2);
  __CPROVER_assume(pub_r000254_17_1 == pub_r000254_17_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.dim == st_var_1_2.dim);
  assert(st_var_1_1.scale == st_var_1_2.scale);
  assert(st_var_1_1.determinant == st_var_1_2.determinant);
  assert(st_var_1_1.density == st_var_1_2.density);
  assert(st_var_1_1.trace == st_var_1_2.trace);
  assert(st_var_1_1.stride == st_var_1_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.pitch == st_var_2_2.pitch);
  assert(st_var_2_1.norm_sq == st_var_2_2.norm_sq);
  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.prev_out == st_var_3_2.prev_out);
  assert(st_var_3_1.gain_db == st_var_3_2.gain_db);
  assert(st_var_3_1.damping == st_var_3_2.damping);
  assert(st_var_3_1.cutoff == st_var_3_2.cutoff);
  assert(st_var_3_1.mode == st_var_3_2.mode);
  assert(st_var_3_1.prev_in == st_var_3_2.prev_in);
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
}


