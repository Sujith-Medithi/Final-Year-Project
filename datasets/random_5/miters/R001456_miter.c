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
struct MatrixBlock_R001456_5613_0
{
  int dim;
  int scale;
  short density;
  int buffer[3];
};
struct Vector3D_R001456_5613_1
{
  int heading;
  int coord_x;
  unsigned char norm_sq;
  int pitch;
  int buffer[3];
};
struct AudioFrame_R001456_5613_2
{
  int rms;
  int peak;
  int sample_rate;
  unsigned char envelope;
  unsigned char gain;
  int buffer[3];
};
union RegisterBank_R001456_5613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R001456_5613_1
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
void fn_R001456_5613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001456_5613_1 st_1 = {0};
  struct Vector3D_R001456_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_62_1 = local_arr_1[aux_1 % 3];
  int quotient_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_62_2 * 2)) & 127;
  int damping_90_1 = 0;
  int damping_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_90_1 = ((damping_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_90_2 = ((damping_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_90_1) & 127;
    acc_2 = (acc_2 + damping_90_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_49_1) & 63;
  aux_2 = (aux_2 + factor_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_62_1 == quotient_62_2);
  assert(damping_90_1 == damping_90_2);
  assert(factor_49_1 == factor_49_2);
}

int fn_R001456_5613_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001456_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int quotient_62 = local_arr[aux % 3];
  acc = (acc + (quotient_62 * 2)) & 127;
  int damping_90 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_90 = ((damping_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_90) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_49) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001456_5613_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001456_5613_2 st_1 = {0};
  struct AudioFrame_R001456_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int metric_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_28_1) & 63;
  aux_2 = (aux_2 + metric_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_54_1)
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

  switch (stride_54_2)
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

  int tally_17_1 = 0;
  int tally_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_17_1 = ((tally_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_17_2 = ((tally_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_17_1) & 127;
    acc_2 = (acc_2 + tally_17_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_28_1 == metric_28_2);
  assert(stride_54_1 == stride_54_2);
  assert(tally_17_1 == tally_17_2);
}

int fn_R001456_5613_1(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001456_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int metric_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_28) & 63;
  acc ^= aux;
  int stride_54 = (aux + st.buffer[1]) & 3;
  switch (stride_54)
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

  int tally_17 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_17 = ((tally_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_17) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001456_5613_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001456_5613_1 st_1 = {0};
  struct Vector3D_R001456_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_46_1 = local_arr_1[aux_1 % 3];
  int accumulator_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_46_2 * 2)) & 127;
  int offset_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_14_1) & 63;
  aux_2 = (aux_2 + offset_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_31_1)
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

  switch (metric_31_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_46_1 == accumulator_46_2);
  assert(offset_14_1 == offset_14_2);
  assert(metric_31_1 == metric_31_2);
}

int fn_R001456_5613_2(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001456_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int accumulator_46 = local_arr[aux % 3];
  acc = (acc + (accumulator_46 * 2)) & 127;
  int offset_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_14) & 63;
  acc ^= aux;
  int metric_31 = (aux + st.buffer[1]) & 3;
  switch (metric_31)
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

void fn_R001456_5613_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001456_5613_0 st_1 = {0};
  struct MatrixBlock_R001456_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int quotient_92_1 = 0;
  int quotient_92_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_92_1 = ((quotient_92_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_92_2 = ((quotient_92_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_92_1) & 127;
    acc_2 = (acc_2 + quotient_92_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_19_1 = local_arr_1[aux_1 % 3];
  int anchor_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_19_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_92_1 == quotient_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_19_1 == anchor_19_2);
}

int fn_R001456_5613_3(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001456_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int quotient_92 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_92 = ((quotient_92 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_92) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int anchor_19 = local_arr[aux % 3];
  acc = (acc + (anchor_19 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001456_5613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001456_5613_2 st_1 = {0};
  struct AudioFrame_R001456_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int tally_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_54_1 > 31)
  {
    acc_1 = ((acc_1 + (tally_54_1 * 2)) + 5) & 127;
    aux_1 ^= tally_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_54_2 > 31)
  {
    acc_2 = ((acc_2 + (tally_54_2 * 2)) + 5) & 127;
    aux_2 ^= tally_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_54_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_67_1)
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

  switch (tally_67_2)
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

  int anchor_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_12_1) & 63;
  aux_2 = (aux_2 + anchor_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_54_1 == tally_54_2);
  assert(tally_67_1 == tally_67_2);
  assert(anchor_12_1 == anchor_12_2);
}

int fn_R001456_5613_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001456_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int tally_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_54 > 31)
  {
    acc = ((acc + (tally_54 * 2)) + 5) & 127;
    aux ^= tally_54 & 15;
  }
  else
  {
    acc = ((acc - tally_54) + 11) & 127;
    aux += 3;
  }
  int tally_67 = (aux + st.buffer[1]) & 3;
  switch (tally_67)
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

  int anchor_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_12) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001456_5613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001456_5613_2 st_1 = {0};
  struct AudioFrame_R001456_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int sample_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_25_1 > 39)
  {
    acc_1 = ((acc_1 + (sample_25_1 * 2)) + 5) & 127;
    aux_1 ^= sample_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_25_2 > 39)
  {
    acc_2 = ((acc_2 + (sample_25_2 * 2)) + 5) & 127;
    aux_2 ^= sample_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_25_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_99_1 = 0;
  int phase_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_99_1 = ((phase_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_99_2 = ((phase_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_99_1) & 127;
    acc_2 = (acc_2 + phase_99_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_25_1 == sample_25_2);
  assert(phase_99_1 == phase_99_2);
}

int fn_R001456_5613_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001456_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int sample_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_25 > 39)
  {
    acc = ((acc + (sample_25 * 2)) + 5) & 127;
    aux ^= sample_25 & 15;
  }
  else
  {
    acc = ((acc - sample_25) + 11) & 127;
    aux += 3;
  }
  int phase_99 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_99 = ((phase_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_99) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001456_5613_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001456_5613_1 st_1 = {0};
  struct Vector3D_R001456_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int delta_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_90_1 > 49)
  {
    acc_1 = ((acc_1 + (delta_90_1 * 2)) + 5) & 127;
    aux_1 ^= delta_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_90_2 > 49)
  {
    acc_2 = ((acc_2 + (delta_90_2 * 2)) + 5) & 127;
    aux_2 ^= delta_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_90_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_82_1)
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

  switch (quotient_82_2)
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

  int tracker_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_26_1) & 63;
  aux_2 = (aux_2 + tracker_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_55_1 = 0;
  int offset_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_55_1 = ((offset_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_55_2 = ((offset_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_55_1) & 127;
    acc_2 = (acc_2 + offset_55_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_90_1 == delta_90_2);
  assert(quotient_82_1 == quotient_82_2);
  assert(tracker_26_1 == tracker_26_2);
  assert(offset_55_1 == offset_55_2);
}

int fn_R001456_5613_6(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001456_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int delta_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_90 > 49)
  {
    acc = ((acc + (delta_90 * 2)) + 5) & 127;
    aux ^= delta_90 & 15;
  }
  else
  {
    acc = ((acc - delta_90) + 11) & 127;
    aux += 3;
  }
  int quotient_82 = (aux + st.buffer[1]) & 3;
  switch (quotient_82)
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

  int tracker_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_26) & 63;
  acc ^= aux;
  int offset_55 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_55 = ((offset_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_55) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001456_5613_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001456_5613_1 st_1 = {0};
  struct Vector3D_R001456_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int index_reg_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_71_1 > 44)
  {
    acc_1 = ((acc_1 + (index_reg_71_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_71_2 > 44)
  {
    acc_2 = ((acc_2 + (index_reg_71_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_38_1 = local_arr_1[aux_1 % 3];
  int segment_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_38_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_71_1 == index_reg_71_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_38_1 == segment_38_2);
}

int fn_R001456_5613_7(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001456_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int index_reg_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_71 > 44)
  {
    acc = ((acc + (index_reg_71 * 2)) + 5) & 127;
    aux ^= index_reg_71 & 15;
  }
  else
  {
    acc = ((acc - index_reg_71) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int segment_38 = local_arr[aux % 3];
  acc = (acc + (segment_38 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001456_5613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001456_5613_0 st_1 = {0};
  struct MatrixBlock_R001456_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int tracker_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_92_1) & 63;
  aux_2 = (aux_2 + tracker_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_92_1 = 0;
  int factor_92_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_92_1 = ((factor_92_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_92_2 = ((factor_92_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_92_1) & 127;
    acc_2 = (acc_2 + factor_92_2) & 127;
  }

  int mask_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_63_1 > 39)
  {
    acc_1 = ((acc_1 + (mask_63_1 * 2)) + 5) & 127;
    aux_1 ^= mask_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_63_2 > 39)
  {
    acc_2 = ((acc_2 + (mask_63_2 * 2)) + 5) & 127;
    aux_2 ^= mask_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_63_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_92_1 == tracker_92_2);
  assert(factor_92_1 == factor_92_2);
  assert(mask_63_1 == mask_63_2);
}

int fn_R001456_5613_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001456_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int tracker_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_92) & 63;
  acc ^= aux;
  int factor_92 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_92 = ((factor_92 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_92) & 127;
  }

  int mask_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_63 > 39)
  {
    acc = ((acc + (mask_63 * 2)) + 5) & 127;
    aux ^= mask_63 & 15;
  }
  else
  {
    acc = ((acc - mask_63) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001456_5613_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001456_5613_1 st_1 = {0};
  struct Vector3D_R001456_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int segment_97_1 = 0;
  int segment_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_97_1 = ((segment_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_97_2 = ((segment_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_97_1) & 127;
    acc_2 = (acc_2 + segment_97_2) & 127;
  }

  int window_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_99_1 > 49)
  {
    acc_1 = ((acc_1 + (window_99_1 * 2)) + 5) & 127;
    aux_1 ^= window_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_99_2 > 49)
  {
    acc_2 = ((acc_2 + (window_99_2 * 2)) + 5) & 127;
    aux_2 ^= window_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_98_1)
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

  switch (factor_98_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_97_1 == segment_97_2);
  assert(window_99_1 == window_99_2);
  assert(factor_98_1 == factor_98_2);
}

int fn_R001456_5613_9(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001456_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int segment_97 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_97 = ((segment_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_97) & 127;
  }

  int window_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_99 > 49)
  {
    acc = ((acc + (window_99 * 2)) + 5) & 127;
    aux ^= window_99 & 15;
  }
  else
  {
    acc = ((acc - window_99) + 11) & 127;
    aux += 3;
  }
  int factor_98 = (aux + st.buffer[1]) & 3;
  switch (factor_98)
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

void fn_R001456_5613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001456_5613_0 st_1 = {0};
  struct MatrixBlock_R001456_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_83_1 = local_arr_1[aux_1 % 3];
  int tracker_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_83_2 * 2)) & 127;
  int sample_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_27_1) & 63;
  aux_2 = (aux_2 + sample_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_56_1 > 50)
  {
    acc_1 = ((acc_1 + (scale_56_1 * 2)) + 5) & 127;
    aux_1 ^= scale_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_56_2 > 50)
  {
    acc_2 = ((acc_2 + (scale_56_2 * 2)) + 5) & 127;
    aux_2 ^= scale_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_83_1 == tracker_83_2);
  assert(sample_27_1 == sample_27_2);
  assert(scale_56_1 == scale_56_2);
}

int fn_R001456_5613_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001456_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int tracker_83 = local_arr[aux % 3];
  acc = (acc + (tracker_83 * 2)) & 127;
  int sample_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_27) & 63;
  acc ^= aux;
  int scale_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_56 > 50)
  {
    acc = ((acc + (scale_56 * 2)) + 5) & 127;
    aux ^= scale_56 & 15;
  }
  else
  {
    acc = ((acc - scale_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001456_5613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001456_5613_0 st_1 = {0};
  struct MatrixBlock_R001456_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int sample_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_55_1 > 45)
  {
    acc_1 = ((acc_1 + (sample_55_1 * 2)) + 5) & 127;
    aux_1 ^= sample_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_55_2 > 45)
  {
    acc_2 = ((acc_2 + (sample_55_2 * 2)) + 5) & 127;
    aux_2 ^= sample_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_36_1)
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

  switch (cursor_36_2)
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

  int quantum_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_91_1) & 63;
  aux_2 = (aux_2 + quantum_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_55_1 == sample_55_2);
  assert(cursor_36_1 == cursor_36_2);
  assert(quantum_91_1 == quantum_91_2);
}

int fn_R001456_5613_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001456_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int sample_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_55 > 45)
  {
    acc = ((acc + (sample_55 * 2)) + 5) & 127;
    aux ^= sample_55 & 15;
  }
  else
  {
    acc = ((acc - sample_55) + 11) & 127;
    aux += 3;
  }
  int cursor_36 = (aux + st.buffer[1]) & 3;
  switch (cursor_36)
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

  int quantum_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_91) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001456_5613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001456_5613_0 st_1 = {0};
  struct MatrixBlock_R001456_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int anchor_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_97_1 > 46)
  {
    acc_1 = ((acc_1 + (anchor_97_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_97_2 > 46)
  {
    acc_2 = ((acc_2 + (anchor_97_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_77_1 = 0;
  int sample_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_77_1 = ((sample_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_77_2 = ((sample_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_77_1) & 127;
    acc_2 = (acc_2 + sample_77_2) & 127;
  }

  int weight_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_28_1)
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

  switch (weight_28_2)
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

  int mask_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_40_1) & 63;
  aux_2 = (aux_2 + mask_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_97_1 == anchor_97_2);
  assert(sample_77_1 == sample_77_2);
  assert(weight_28_1 == weight_28_2);
  assert(mask_40_1 == mask_40_2);
}

int fn_R001456_5613_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001456_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int anchor_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_97 > 46)
  {
    acc = ((acc + (anchor_97 * 2)) + 5) & 127;
    aux ^= anchor_97 & 15;
  }
  else
  {
    acc = ((acc - anchor_97) + 11) & 127;
    aux += 3;
  }
  int sample_77 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_77 = ((sample_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_77) & 127;
  }

  int weight_28 = (aux + st.buffer[1]) & 3;
  switch (weight_28)
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

  int mask_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_40) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001456_5613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001456_5613_1 st_1 = {0};
  struct Vector3D_R001456_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_93_1 > 21)
  {
    acc_1 = ((acc_1 + (pivot_93_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_93_2 > 21)
  {
    acc_2 = ((acc_2 + (pivot_93_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_93_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_93_1 == pivot_93_2);
}

int fn_R001456_5613_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001456_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_93 > 21)
  {
    acc = ((acc + (pivot_93 * 2)) + 5) & 127;
    aux ^= pivot_93 & 15;
  }
  else
  {
    acc = ((acc - pivot_93) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001456_5613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001456_5613_2 st_1 = {0};
  struct AudioFrame_R001456_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int parity_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_87_1 > 36)
  {
    acc_1 = ((acc_1 + (parity_87_1 * 2)) + 5) & 127;
    aux_1 ^= parity_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_87_2 > 36)
  {
    acc_2 = ((acc_2 + (parity_87_2 * 2)) + 5) & 127;
    aux_2 ^= parity_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_87_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_87_1) & 63;
  aux_2 = (aux_2 + window_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_85_1 = local_arr_1[aux_1 % 3];
  int bound_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_85_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_87_1 == parity_87_2);
  assert(window_87_1 == window_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_85_1 == bound_85_2);
}

int fn_R001456_5613_14(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001456_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int parity_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_87 > 36)
  {
    acc = ((acc + (parity_87 * 2)) + 5) & 127;
    aux ^= parity_87 & 15;
  }
  else
  {
    acc = ((acc - parity_87) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_87) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_85 = local_arr[aux % 3];
  acc = (acc + (bound_85 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001456_5613_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001456_5613_0 st_1 = {0};
  struct MatrixBlock_R001456_5613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_70_1 = local_arr_1[aux_1 % 3];
  int mask_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_70_2 * 2)) & 127;
  int checksum_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_60_1) & 63;
  aux_2 = (aux_2 + checksum_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_60_1 > 15)
  {
    acc_1 = ((acc_1 + (index_reg_60_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_60_2 > 15)
  {
    acc_2 = ((acc_2 + (index_reg_60_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_60_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_70_1 == mask_70_2);
  assert(checksum_60_1 == checksum_60_2);
  assert(index_reg_60_1 == index_reg_60_2);
}

int fn_R001456_5613_15(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001456_5613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_70 = local_arr[aux % 3];
  acc = (acc + (mask_70 * 2)) & 127;
  int checksum_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_60) & 63;
  acc ^= aux;
  int index_reg_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_60 > 15)
  {
    acc = ((acc + (index_reg_60 * 2)) + 5) & 127;
    aux ^= index_reg_60 & 15;
  }
  else
  {
    acc = ((acc - index_reg_60) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001456_5613_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001456_5613_1 st_1 = {0};
  struct Vector3D_R001456_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_84_1 = local_arr_1[aux_1 % 3];
  int vector_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_84_2 * 2)) & 127;
  int pivot_86_1 = 0;
  int pivot_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_86_1 = ((pivot_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_86_2 = ((pivot_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_86_1) & 127;
    acc_2 = (acc_2 + pivot_86_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_41_1) & 63;
  aux_2 = (aux_2 + window_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_84_1 == vector_84_2);
  assert(pivot_86_1 == pivot_86_2);
  assert(window_41_1 == window_41_2);
}

int fn_R001456_5613_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001456_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int vector_84 = local_arr[aux % 3];
  acc = (acc + (vector_84 * 2)) & 127;
  int pivot_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_86 = ((pivot_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_86) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_41) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001456_5613_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001456_5613_2 st_1 = {0};
  struct AudioFrame_R001456_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int pivot_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_75_1 > 46)
  {
    acc_1 = ((acc_1 + (pivot_75_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_75_2 > 46)
  {
    acc_2 = ((acc_2 + (pivot_75_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_64_1 = local_arr_1[aux_1 % 3];
  int margin_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_64_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_75_1 == pivot_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_64_1 == margin_64_2);
}

int fn_R001456_5613_17(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001456_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int pivot_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_75 > 46)
  {
    acc = ((acc + (pivot_75 * 2)) + 5) & 127;
    aux ^= pivot_75 & 15;
  }
  else
  {
    acc = ((acc - pivot_75) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int margin_64 = local_arr[aux % 3];
  acc = (acc + (margin_64 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001456_5613_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001456_5613_2 st_1 = {0};
  struct AudioFrame_R001456_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int parity_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_75_1)
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

  switch (parity_75_2)
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
  int tracker_30_1 = local_arr_1[aux_1 % 3];
  int tracker_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_30_2 * 2)) & 127;
  int segment_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_41_1) & 63;
  aux_2 = (aux_2 + segment_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_75_1 == parity_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_30_1 == tracker_30_2);
  assert(segment_41_1 == segment_41_2);
}

int fn_R001456_5613_18(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001456_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int parity_75 = (aux + st.buffer[1]) & 3;
  switch (parity_75)
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
  int tracker_30 = local_arr[aux % 3];
  acc = (acc + (tracker_30 * 2)) & 127;
  int segment_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_41) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001456_5613_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001456_5613_1 st_1 = {0};
  struct Vector3D_R001456_5613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int metric_32_1 = 0;
  int metric_32_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_32_1 = ((metric_32_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_32_2 = ((metric_32_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_32_1) & 127;
    acc_2 = (acc_2 + metric_32_2) & 127;
  }

  int checksum_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_10_1 > 22)
  {
    acc_1 = ((acc_1 + (checksum_10_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_10_2 > 22)
  {
    acc_2 = ((acc_2 + (checksum_10_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_10_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_32_1 == metric_32_2);
  assert(checksum_10_1 == checksum_10_2);
}

int fn_R001456_5613_19(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001456_5613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int metric_32 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_32 = ((metric_32 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_32) & 127;
  }

  int checksum_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_10 > 22)
  {
    acc = ((acc + (checksum_10 * 2)) + 5) & 127;
    aux ^= checksum_10 & 15;
  }
  else
  {
    acc = ((acc - checksum_10) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001456_5613_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001456_5613_2 st_1 = {0};
  struct AudioFrame_R001456_5613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_64_1 = local_arr_1[aux_1 % 3];
  int threshold_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_64_2 * 2)) & 127;
  int vector_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_67_1) & 63;
  aux_2 = (aux_2 + vector_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_63_1)
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

  switch (window_63_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_64_1 == threshold_64_2);
  assert(vector_67_1 == vector_67_2);
  assert(window_63_1 == window_63_2);
}

int fn_R001456_5613_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001456_5613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int threshold_64 = local_arr[aux % 3];
  acc = (acc + (threshold_64 * 2)) & 127;
  int vector_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_67) & 63;
  acc ^= aux;
  int window_63 = (aux + st.buffer[1]) & 3;
  switch (window_63)
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

void main()
{
  int sec_r001456_0_1;
  int sec_r001456_0_2;
  int sec_r001456_1_1;
  int sec_r001456_1_2;
  int sec_r001456_2_1;
  int sec_r001456_2_2;
  int sec_r001456_3_1;
  int sec_r001456_3_2;
  int sec_r001456_4_1;
  int sec_r001456_4_2;
  int sec_r001456_5_1;
  int sec_r001456_5_2;
  int sec_r001456_6_1;
  int sec_r001456_6_2;
  int sec_r001456_7_1;
  int sec_r001456_7_2;
  int sec_r001456_8_1;
  int sec_r001456_8_2;
  int sec_r001456_9_1;
  int sec_r001456_9_2;
  int sec_r001456_10_1;
  int sec_r001456_10_2;
  int sec_r001456_11_1;
  int sec_r001456_11_2;
  int sec_r001456_12_1;
  int sec_r001456_12_2;
  int sec_r001456_13_1;
  int sec_r001456_13_2;
  int sec_r001456_14_1;
  int sec_r001456_14_2;
  int sec_r001456_15_1;
  int sec_r001456_15_2;
  int sec_r001456_16_1;
  int sec_r001456_16_2;
  int sec_r001456_17_1;
  int sec_r001456_17_2;
  int sec_r001456_18_1;
  int sec_r001456_18_2;
  int sec_r001456_19_1;
  int sec_r001456_19_2;
  int sec_r001456_20_1;
  int sec_r001456_20_2;
  int sec_r001456_21_1;
  int sec_r001456_21_2;
  int sec_r001456_22_1;
  int sec_r001456_22_2;
  int pub_r001456_0_1;
  int pub_r001456_0_2;
  int pub_r001456_1_1;
  int pub_r001456_1_2;
  int pub_r001456_2_1;
  int pub_r001456_2_2;
  int pub_r001456_3_1;
  int pub_r001456_3_2;
  int pub_r001456_4_1;
  int pub_r001456_4_2;
  int pub_r001456_5_1;
  int pub_r001456_5_2;
  int pub_r001456_6_1;
  int pub_r001456_6_2;
  int pub_r001456_7_1;
  int pub_r001456_7_2;
  int pub_r001456_8_1;
  int pub_r001456_8_2;
  int pub_r001456_9_1;
  int pub_r001456_9_2;
  int pub_r001456_10_1;
  int pub_r001456_10_2;
  int pub_r001456_11_1;
  int pub_r001456_11_2;
  int pub_r001456_12_1;
  int pub_r001456_12_2;
  int pub_r001456_13_1;
  int pub_r001456_13_2;
  int pub_r001456_14_1;
  int pub_r001456_14_2;
  int pub_r001456_15_1;
  int pub_r001456_15_2;
  int pub_r001456_16_1;
  int pub_r001456_16_2;
  int pub_r001456_17_1;
  int pub_r001456_17_2;
  int pub_r001456_18_1;
  int pub_r001456_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001456_0_1 >= (-100)) && (pub_r001456_0_1 <= 100));
  __CPROVER_assume((pub_r001456_0_2 >= (-100)) && (pub_r001456_0_2 <= 100));
  __CPROVER_assume((pub_r001456_1_1 >= (-100)) && (pub_r001456_1_1 <= 100));
  __CPROVER_assume((pub_r001456_1_2 >= (-100)) && (pub_r001456_1_2 <= 100));
  __CPROVER_assume((pub_r001456_2_1 >= (-100)) && (pub_r001456_2_1 <= 100));
  __CPROVER_assume((pub_r001456_2_2 >= (-100)) && (pub_r001456_2_2 <= 100));
  __CPROVER_assume((pub_r001456_3_1 >= (-100)) && (pub_r001456_3_1 <= 100));
  __CPROVER_assume((pub_r001456_3_2 >= (-100)) && (pub_r001456_3_2 <= 100));
  __CPROVER_assume((pub_r001456_4_1 >= (-100)) && (pub_r001456_4_1 <= 100));
  __CPROVER_assume((pub_r001456_4_2 >= (-100)) && (pub_r001456_4_2 <= 100));
  __CPROVER_assume((pub_r001456_5_1 >= (-100)) && (pub_r001456_5_1 <= 100));
  __CPROVER_assume((pub_r001456_5_2 >= (-100)) && (pub_r001456_5_2 <= 100));
  __CPROVER_assume((pub_r001456_6_1 >= (-100)) && (pub_r001456_6_1 <= 100));
  __CPROVER_assume((pub_r001456_6_2 >= (-100)) && (pub_r001456_6_2 <= 100));
  __CPROVER_assume((pub_r001456_7_1 >= (-100)) && (pub_r001456_7_1 <= 100));
  __CPROVER_assume((pub_r001456_7_2 >= (-100)) && (pub_r001456_7_2 <= 100));
  __CPROVER_assume((pub_r001456_8_1 >= (-100)) && (pub_r001456_8_1 <= 100));
  __CPROVER_assume((pub_r001456_8_2 >= (-100)) && (pub_r001456_8_2 <= 100));
  __CPROVER_assume((pub_r001456_9_1 >= (-100)) && (pub_r001456_9_1 <= 100));
  __CPROVER_assume((pub_r001456_9_2 >= (-100)) && (pub_r001456_9_2 <= 100));
  __CPROVER_assume((pub_r001456_10_1 >= (-100)) && (pub_r001456_10_1 <= 100));
  __CPROVER_assume((pub_r001456_10_2 >= (-100)) && (pub_r001456_10_2 <= 100));
  __CPROVER_assume((pub_r001456_11_1 >= (-100)) && (pub_r001456_11_1 <= 100));
  __CPROVER_assume((pub_r001456_11_2 >= (-100)) && (pub_r001456_11_2 <= 100));
  __CPROVER_assume((pub_r001456_12_1 >= (-100)) && (pub_r001456_12_1 <= 100));
  __CPROVER_assume((pub_r001456_12_2 >= (-100)) && (pub_r001456_12_2 <= 100));
  __CPROVER_assume((pub_r001456_13_1 >= (-100)) && (pub_r001456_13_1 <= 100));
  __CPROVER_assume((pub_r001456_13_2 >= (-100)) && (pub_r001456_13_2 <= 100));
  __CPROVER_assume((pub_r001456_14_1 >= (-100)) && (pub_r001456_14_1 <= 100));
  __CPROVER_assume((pub_r001456_14_2 >= (-100)) && (pub_r001456_14_2 <= 100));
  __CPROVER_assume((pub_r001456_15_1 >= (-100)) && (pub_r001456_15_1 <= 100));
  __CPROVER_assume((pub_r001456_15_2 >= (-100)) && (pub_r001456_15_2 <= 100));
  __CPROVER_assume((pub_r001456_16_1 >= (-100)) && (pub_r001456_16_1 <= 100));
  __CPROVER_assume((pub_r001456_16_2 >= (-100)) && (pub_r001456_16_2 <= 100));
  __CPROVER_assume((pub_r001456_17_1 >= (-100)) && (pub_r001456_17_1 <= 100));
  __CPROVER_assume((pub_r001456_17_2 >= (-100)) && (pub_r001456_17_2 <= 100));
  __CPROVER_assume((pub_r001456_18_1 >= (-100)) && (pub_r001456_18_1 <= 100));
  __CPROVER_assume((pub_r001456_18_2 >= (-100)) && (pub_r001456_18_2 <= 100));
  __CPROVER_assume((sec_r001456_0_1 >= 0) && (sec_r001456_0_1 <= 255));
  __CPROVER_assume((sec_r001456_0_2 >= 0) && (sec_r001456_0_2 <= 255));
  __CPROVER_assume((sec_r001456_1_1 >= 0) && (sec_r001456_1_1 <= 255));
  __CPROVER_assume((sec_r001456_1_2 >= 0) && (sec_r001456_1_2 <= 255));
  __CPROVER_assume((sec_r001456_2_1 >= 0) && (sec_r001456_2_1 <= 255));
  __CPROVER_assume((sec_r001456_2_2 >= 0) && (sec_r001456_2_2 <= 255));
  __CPROVER_assume((sec_r001456_3_1 >= 0) && (sec_r001456_3_1 <= 255));
  __CPROVER_assume((sec_r001456_3_2 >= 0) && (sec_r001456_3_2 <= 255));
  __CPROVER_assume((sec_r001456_4_1 >= 0) && (sec_r001456_4_1 <= 255));
  __CPROVER_assume((sec_r001456_4_2 >= 0) && (sec_r001456_4_2 <= 255));
  __CPROVER_assume((sec_r001456_5_1 >= 0) && (sec_r001456_5_1 <= 255));
  __CPROVER_assume((sec_r001456_5_2 >= 0) && (sec_r001456_5_2 <= 255));
  __CPROVER_assume((sec_r001456_6_1 >= 0) && (sec_r001456_6_1 <= 255));
  __CPROVER_assume((sec_r001456_6_2 >= 0) && (sec_r001456_6_2 <= 255));
  __CPROVER_assume((sec_r001456_7_1 >= 0) && (sec_r001456_7_1 <= 255));
  __CPROVER_assume((sec_r001456_7_2 >= 0) && (sec_r001456_7_2 <= 255));
  __CPROVER_assume((sec_r001456_8_1 >= 0) && (sec_r001456_8_1 <= 255));
  __CPROVER_assume((sec_r001456_8_2 >= 0) && (sec_r001456_8_2 <= 255));
  __CPROVER_assume((sec_r001456_9_1 >= 0) && (sec_r001456_9_1 <= 255));
  __CPROVER_assume((sec_r001456_9_2 >= 0) && (sec_r001456_9_2 <= 255));
  __CPROVER_assume((sec_r001456_10_1 >= 0) && (sec_r001456_10_1 <= 255));
  __CPROVER_assume((sec_r001456_10_2 >= 0) && (sec_r001456_10_2 <= 255));
  __CPROVER_assume((sec_r001456_11_1 >= 0) && (sec_r001456_11_1 <= 255));
  __CPROVER_assume((sec_r001456_11_2 >= 0) && (sec_r001456_11_2 <= 255));
  __CPROVER_assume((sec_r001456_12_1 >= 0) && (sec_r001456_12_1 <= 255));
  __CPROVER_assume((sec_r001456_12_2 >= 0) && (sec_r001456_12_2 <= 255));
  __CPROVER_assume((sec_r001456_13_1 >= 0) && (sec_r001456_13_1 <= 255));
  __CPROVER_assume((sec_r001456_13_2 >= 0) && (sec_r001456_13_2 <= 255));
  __CPROVER_assume((sec_r001456_14_1 >= 0) && (sec_r001456_14_1 <= 255));
  __CPROVER_assume((sec_r001456_14_2 >= 0) && (sec_r001456_14_2 <= 255));
  __CPROVER_assume((sec_r001456_15_1 >= 0) && (sec_r001456_15_1 <= 255));
  __CPROVER_assume((sec_r001456_15_2 >= 0) && (sec_r001456_15_2 <= 255));
  __CPROVER_assume((sec_r001456_16_1 >= 0) && (sec_r001456_16_1 <= 255));
  __CPROVER_assume((sec_r001456_16_2 >= 0) && (sec_r001456_16_2 <= 255));
  __CPROVER_assume((sec_r001456_17_1 >= 0) && (sec_r001456_17_1 <= 255));
  __CPROVER_assume((sec_r001456_17_2 >= 0) && (sec_r001456_17_2 <= 255));
  __CPROVER_assume((sec_r001456_18_1 >= 0) && (sec_r001456_18_1 <= 255));
  __CPROVER_assume((sec_r001456_18_2 >= 0) && (sec_r001456_18_2 <= 255));
  __CPROVER_assume((sec_r001456_19_1 >= 0) && (sec_r001456_19_1 <= 255));
  __CPROVER_assume((sec_r001456_19_2 >= 0) && (sec_r001456_19_2 <= 255));
  __CPROVER_assume((sec_r001456_20_1 >= 0) && (sec_r001456_20_1 <= 255));
  __CPROVER_assume((sec_r001456_20_2 >= 0) && (sec_r001456_20_2 <= 255));
  __CPROVER_assume((sec_r001456_21_1 >= 0) && (sec_r001456_21_1 <= 255));
  __CPROVER_assume((sec_r001456_21_2 >= 0) && (sec_r001456_21_2 <= 255));
  __CPROVER_assume((sec_r001456_22_1 >= 0) && (sec_r001456_22_1 <= 255));
  __CPROVER_assume((sec_r001456_22_2 >= 0) && (sec_r001456_22_2 <= 255));
  struct MatrixBlock_R001456_5613_0 st_var_0_1 = {0};
  struct MatrixBlock_R001456_5613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001456_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001456_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001456_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001456_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001456_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001456_0_2 + 7) & 15;
  struct Vector3D_R001456_5613_1 st_var_1_1 = {0};
  struct Vector3D_R001456_5613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001456_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001456_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001456_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001456_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001456_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001456_0_2 + 9) & 15;
  struct AudioFrame_R001456_5613_2 st_var_2_1 = {0};
  struct AudioFrame_R001456_5613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001456_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001456_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001456_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001456_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001456_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001456_0_2 + 11) & 15;
  union RegisterBank_R001456_5613_0 u_var_1;
  union RegisterBank_R001456_5613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001456_5613_0(sec_r001456_0_1, pub_r001456_1_1, pub_r001456_2_1, pub_r001456_3_1, pub_r001456_4_1);
  int helper_flow_0_2 = fn_R001456_5613_0(sec_r001456_0_2, pub_r001456_1_2, pub_r001456_2_2, pub_r001456_3_2, pub_r001456_4_2);
  fn_R001456_5613_0_2(sec_r001456_0_1, pub_r001456_1_1, pub_r001456_2_1, pub_r001456_3_1, pub_r001456_4_1, sec_r001456_0_2, pub_r001456_1_2, pub_r001456_2_2, pub_r001456_3_2, pub_r001456_4_2);
  int helper_flow_1_1 = fn_R001456_5613_1(sec_r001456_1_1, sec_r001456_2_1);
  int helper_flow_1_2 = fn_R001456_5613_1(sec_r001456_1_2, sec_r001456_2_2);
  fn_R001456_5613_1_2(sec_r001456_1_1, sec_r001456_2_1, sec_r001456_1_2, sec_r001456_2_2);
  int helper_flow_2_1 = fn_R001456_5613_2(sec_r001456_2_1, pub_r001456_3_1);
  int helper_flow_2_2 = fn_R001456_5613_2(sec_r001456_2_2, pub_r001456_3_2);
  fn_R001456_5613_2_2(sec_r001456_2_1, pub_r001456_3_1, sec_r001456_2_2, pub_r001456_3_2);
  int helper_flow_3_1 = fn_R001456_5613_3(sec_r001456_3_1, sec_r001456_4_1, pub_r001456_5_1);
  int helper_flow_3_2 = fn_R001456_5613_3(sec_r001456_3_2, sec_r001456_4_2, pub_r001456_5_2);
  fn_R001456_5613_3_2(sec_r001456_3_1, sec_r001456_4_1, pub_r001456_5_1, sec_r001456_3_2, sec_r001456_4_2, pub_r001456_5_2);
  int helper_flow_4_1 = fn_R001456_5613_4(sec_r001456_4_1, sec_r001456_5_1, pub_r001456_6_1, pub_r001456_7_1);
  int helper_flow_4_2 = fn_R001456_5613_4(sec_r001456_4_2, sec_r001456_5_2, pub_r001456_6_2, pub_r001456_7_2);
  fn_R001456_5613_4_2(sec_r001456_4_1, sec_r001456_5_1, pub_r001456_6_1, pub_r001456_7_1, sec_r001456_4_2, sec_r001456_5_2, pub_r001456_6_2, pub_r001456_7_2);
  int helper_flow_5_1 = fn_R001456_5613_5(sec_r001456_5_1, pub_r001456_6_1, pub_r001456_7_1, pub_r001456_8_1);
  int helper_flow_5_2 = fn_R001456_5613_5(sec_r001456_5_2, pub_r001456_6_2, pub_r001456_7_2, pub_r001456_8_2);
  fn_R001456_5613_5_2(sec_r001456_5_1, pub_r001456_6_1, pub_r001456_7_1, pub_r001456_8_1, sec_r001456_5_2, pub_r001456_6_2, pub_r001456_7_2, pub_r001456_8_2);
  int helper_flow_6_1 = fn_R001456_5613_6(sec_r001456_6_1, sec_r001456_7_1);
  int helper_flow_6_2 = fn_R001456_5613_6(sec_r001456_6_2, sec_r001456_7_2);
  fn_R001456_5613_6_2(sec_r001456_6_1, sec_r001456_7_1, sec_r001456_6_2, sec_r001456_7_2);
  int helper_flow_7_1 = fn_R001456_5613_7(sec_r001456_7_1, sec_r001456_8_1, pub_r001456_9_1);
  int helper_flow_7_2 = fn_R001456_5613_7(sec_r001456_7_2, sec_r001456_8_2, pub_r001456_9_2);
  fn_R001456_5613_7_2(sec_r001456_7_1, sec_r001456_8_1, pub_r001456_9_1, sec_r001456_7_2, sec_r001456_8_2, pub_r001456_9_2);
  int helper_flow_8_1 = fn_R001456_5613_8(sec_r001456_8_1, sec_r001456_9_1, pub_r001456_10_1, pub_r001456_11_1);
  int helper_flow_8_2 = fn_R001456_5613_8(sec_r001456_8_2, sec_r001456_9_2, pub_r001456_10_2, pub_r001456_11_2);
  fn_R001456_5613_8_2(sec_r001456_8_1, sec_r001456_9_1, pub_r001456_10_1, pub_r001456_11_1, sec_r001456_8_2, sec_r001456_9_2, pub_r001456_10_2, pub_r001456_11_2);
  int stage_v_0_1 = ((helper_flow_1_1 + (pub_r001456_11_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((helper_flow_1_2 + (pub_r001456_11_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((sec_r001456_12_1 + (pub_r001456_13_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((sec_r001456_12_2 + (pub_r001456_13_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((sec_r001456_13_1 + (pub_r001456_18_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((sec_r001456_13_2 + (pub_r001456_18_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((pub_r001456_8_1 * 2) + 13) & 63;
  int stage_v_3_2 = ((pub_r001456_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((sec_r001456_5_1 + (pub_r001456_6_1 * 2)) + 17) & 127;
  int stage_v_4_2 = ((sec_r001456_5_2 + (pub_r001456_6_2 * 2)) + 17) & 127;
  if (stage_v_4_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_4_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_4_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_4_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_5_1 = ((sec_r001456_10_1 + (pub_r001456_17_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((sec_r001456_10_2 + (pub_r001456_17_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((stage_v_5_1 + (pub_r001456_3_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((stage_v_5_2 + (pub_r001456_3_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((stage_v_0_1 + (pub_r001456_7_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((stage_v_0_2 + (pub_r001456_7_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((helper_flow_1_1 + (pub_r001456_15_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((helper_flow_1_2 + (pub_r001456_15_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((stage_v_1_1 + (pub_r001456_12_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((stage_v_1_2 + (pub_r001456_12_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((helper_flow_1_1 + (pub_r001456_8_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((helper_flow_1_2 + (pub_r001456_8_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((stage_v_9_1 + (pub_r001456_9_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((stage_v_9_2 + (pub_r001456_9_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((sec_r001456_20_1 + (pub_r001456_9_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((sec_r001456_20_2 + (pub_r001456_9_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((helper_flow_4_1 + (pub_r001456_5_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((helper_flow_4_2 + (pub_r001456_5_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((pub_r001456_15_1 * 2) + 8) & 63;
  int stage_v_14_2 = ((pub_r001456_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((sec_r001456_15_1 + (pub_r001456_5_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((sec_r001456_15_2 + (pub_r001456_5_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((pub_r001456_1_1 * 2) + 35) & 63;
  int stage_v_16_2 = ((pub_r001456_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((sec_r001456_5_1 + (pub_r001456_15_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001456_5_2 + (pub_r001456_15_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((stage_v_17_1 + (pub_r001456_9_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((stage_v_17_2 + (pub_r001456_9_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((sec_r001456_10_1 + (pub_r001456_15_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((sec_r001456_10_2 + (pub_r001456_15_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((pub_r001456_7_1 * 2) + 12) & 63;
  int stage_v_20_2 = ((pub_r001456_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001456_0_1 * 2) + 46) & 63;
  int stage_v_21_2 = ((pub_r001456_0_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((helper_flow_8_1 + (pub_r001456_7_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((helper_flow_8_2 + (pub_r001456_7_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((pub_r001456_8_1 * 2) + 32) & 63;
  int stage_v_23_2 = ((pub_r001456_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((sec_r001456_11_1 + (pub_r001456_14_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((sec_r001456_11_2 + (pub_r001456_14_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((sec_r001456_17_1 + (pub_r001456_12_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((sec_r001456_17_2 + (pub_r001456_12_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((sec_r001456_5_1 + (pub_r001456_18_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((sec_r001456_5_2 + (pub_r001456_18_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((sec_r001456_13_1 + (pub_r001456_10_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((sec_r001456_13_2 + (pub_r001456_10_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((sec_r001456_3_1 + (pub_r001456_2_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((sec_r001456_3_2 + (pub_r001456_2_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((pub_r001456_15_1 * 2) + 39) & 63;
  int stage_v_29_2 = ((pub_r001456_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001456_5_1 * 2) + 42) & 63;
  int stage_v_30_2 = ((pub_r001456_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((stage_v_11_1 + (pub_r001456_13_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((stage_v_11_2 + (pub_r001456_13_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((stage_v_5_1 + (pub_r001456_12_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((stage_v_5_2 + (pub_r001456_12_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((pub_r001456_11_1 * 2) + 24) & 63;
  int stage_v_33_2 = ((pub_r001456_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((stage_v_26_1 + (pub_r001456_16_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((stage_v_26_2 + (pub_r001456_16_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((pub_r001456_12_1 * 2) + 25) & 63;
  int stage_v_35_2 = ((pub_r001456_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001456_15_1 * 2) + 40) & 63;
  int stage_v_36_2 = ((pub_r001456_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001456_7_1 * 2) + 31) & 63;
  int stage_v_37_2 = ((pub_r001456_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((sec_r001456_7_1 + (pub_r001456_0_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((sec_r001456_7_2 + (pub_r001456_0_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((pub_r001456_9_1 * 2) + 43) & 63;
  int stage_v_39_2 = ((pub_r001456_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((stage_v_12_1 + (pub_r001456_9_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((stage_v_12_2 + (pub_r001456_9_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((stage_v_4_1 + (pub_r001456_2_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((stage_v_4_2 + (pub_r001456_2_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((pub_r001456_10_1 * 2) + 38) & 63;
  int stage_v_42_2 = ((pub_r001456_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001456_4_1 * 2) + 39) & 63;
  int stage_v_43_2 = ((pub_r001456_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001456_7_1 * 2) + 41) & 63;
  int stage_v_44_2 = ((pub_r001456_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((helper_flow_6_1 + (pub_r001456_0_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((helper_flow_6_2 + (pub_r001456_0_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((pub_r001456_16_1 * 2) + 11) & 63;
  int stage_v_46_2 = ((pub_r001456_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((sec_r001456_18_1 + (pub_r001456_4_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((sec_r001456_18_2 + (pub_r001456_4_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((pub_r001456_0_1 * 2) + 48) & 63;
  int stage_v_48_2 = ((pub_r001456_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001456_4_1 * 2) + 50) & 63;
  int stage_v_49_2 = ((pub_r001456_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((stage_v_41_1 + (pub_r001456_16_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((stage_v_41_2 + (pub_r001456_16_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((stage_v_18_1 + (pub_r001456_9_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((stage_v_18_2 + (pub_r001456_9_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((pub_r001456_6_1 * 2) + 50) & 63;
  int stage_v_52_2 = ((pub_r001456_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001456_18_1 * 2) + 6) & 63;
  int stage_v_53_2 = ((pub_r001456_18_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001456_5_1 * 2) + 19) & 63;
  int stage_v_54_2 = ((pub_r001456_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((stage_v_51_1 + (pub_r001456_8_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((stage_v_51_2 + (pub_r001456_8_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((pub_r001456_6_1 * 2) + 41) & 63;
  int stage_v_56_2 = ((pub_r001456_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((sec_r001456_16_1 + (pub_r001456_12_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((sec_r001456_16_2 + (pub_r001456_12_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((pub_r001456_5_1 * 2) + 46) & 63;
  int stage_v_58_2 = ((pub_r001456_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((sec_r001456_17_1 + (pub_r001456_18_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((sec_r001456_17_2 + (pub_r001456_18_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((stage_v_15_1 + (pub_r001456_2_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((stage_v_15_2 + (pub_r001456_2_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((stage_v_11_1 + (pub_r001456_4_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((stage_v_11_2 + (pub_r001456_4_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((pub_r001456_12_1 * 2) + 34) & 63;
  int stage_v_62_2 = ((pub_r001456_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((sec_r001456_20_1 + (pub_r001456_11_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((sec_r001456_20_2 + (pub_r001456_11_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((sec_r001456_5_1 + (pub_r001456_3_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((sec_r001456_5_2 + (pub_r001456_3_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((pub_r001456_9_1 * 2) + 5) & 63;
  int stage_v_65_2 = ((pub_r001456_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001456_17_1 * 2) + 36) & 63;
  int stage_v_66_2 = ((pub_r001456_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001456_5_1 * 2) + 20) & 63;
  int stage_v_67_2 = ((pub_r001456_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((stage_v_40_1 + (pub_r001456_17_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((stage_v_40_2 + (pub_r001456_17_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((pub_r001456_12_1 * 2) + 33) & 63;
  int stage_v_69_2 = ((pub_r001456_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((stage_v_22_1 + (pub_r001456_6_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((stage_v_22_2 + (pub_r001456_6_2 * 2)) + 215) & 127;
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
  int stage_v_71_1 = ((helper_flow_8_1 + (pub_r001456_0_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((helper_flow_8_2 + (pub_r001456_0_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((sec_r001456_5_1 + (pub_r001456_5_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((sec_r001456_5_2 + (pub_r001456_5_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((stage_v_5_1 + (pub_r001456_11_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_5_2 + (pub_r001456_11_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((stage_v_19_1 + (pub_r001456_5_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((stage_v_19_2 + (pub_r001456_5_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((pub_r001456_1_1 * 2) + 40) & 63;
  int stage_v_75_2 = ((pub_r001456_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001456_12_1 * 2) + 30) & 63;
  int stage_v_76_2 = ((pub_r001456_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001456_0_1 * 2) + 23) & 63;
  int stage_v_77_2 = ((pub_r001456_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((sec_r001456_8_1 + (pub_r001456_10_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((sec_r001456_8_2 + (pub_r001456_10_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((stage_v_8_1 + (pub_r001456_11_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((stage_v_8_2 + (pub_r001456_11_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((sec_r001456_16_1 + (pub_r001456_5_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((sec_r001456_16_2 + (pub_r001456_5_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((pub_r001456_7_1 * 2) + 30) & 63;
  int stage_v_81_2 = ((pub_r001456_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((stage_v_80_1 + (pub_r001456_14_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((stage_v_80_2 + (pub_r001456_14_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((stage_v_8_1 + (pub_r001456_11_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((stage_v_8_2 + (pub_r001456_11_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((stage_v_22_1 + (pub_r001456_0_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((stage_v_22_2 + (pub_r001456_0_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((stage_v_22_1 + (pub_r001456_9_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((stage_v_22_2 + (pub_r001456_9_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((stage_v_26_1 + (pub_r001456_12_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_26_2 + (pub_r001456_12_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((stage_v_51_1 + (pub_r001456_16_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_51_2 + (pub_r001456_16_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((stage_v_60_1 + (pub_r001456_2_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((stage_v_60_2 + (pub_r001456_2_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((stage_v_79_1 + (pub_r001456_9_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((stage_v_79_2 + (pub_r001456_9_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((pub_r001456_1_1 * 2) + 13) & 63;
  int stage_v_90_2 = ((pub_r001456_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((stage_v_79_1 + (pub_r001456_0_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_79_2 + (pub_r001456_0_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((sec_r001456_5_1 + (pub_r001456_18_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((sec_r001456_5_2 + (pub_r001456_18_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((pub_r001456_8_1 * 2) + 7) & 63;
  int stage_v_93_2 = ((pub_r001456_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001456_4_1 * 2) + 36) & 63;
  int stage_v_94_2 = ((pub_r001456_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001456_7_1 * 2) + 9) & 63;
  int stage_v_95_2 = ((pub_r001456_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((stage_v_11_1 + (pub_r001456_13_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((stage_v_11_2 + (pub_r001456_13_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((sec_r001456_12_1 + (pub_r001456_3_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((sec_r001456_12_2 + (pub_r001456_3_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((stage_v_70_1 + (pub_r001456_16_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_70_2 + (pub_r001456_16_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((pub_r001456_12_1 * 2) + 42) & 63;
  int stage_v_99_2 = ((pub_r001456_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001456_16_1 * 2) + 10) & 63;
  int stage_v_100_2 = ((pub_r001456_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001456_8_1 * 2) + 38) & 63;
  int stage_v_101_2 = ((pub_r001456_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001456_18_1 * 2) + 6) & 63;
  int stage_v_102_2 = ((pub_r001456_18_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((stage_v_89_1 + (pub_r001456_3_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_89_2 + (pub_r001456_3_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((stage_v_1_1 + (pub_r001456_8_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((stage_v_1_2 + (pub_r001456_8_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((stage_v_96_1 + (pub_r001456_5_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_96_2 + (pub_r001456_5_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((stage_v_4_1 + (pub_r001456_18_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_4_2 + (pub_r001456_18_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((sec_r001456_1_1 + (pub_r001456_17_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((sec_r001456_1_2 + (pub_r001456_17_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((stage_v_27_1 + (pub_r001456_6_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((stage_v_27_2 + (pub_r001456_6_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((sec_r001456_21_1 + (pub_r001456_12_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((sec_r001456_21_2 + (pub_r001456_12_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((stage_v_98_1 + (pub_r001456_5_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((stage_v_98_2 + (pub_r001456_5_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((sec_r001456_7_1 + (pub_r001456_1_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((sec_r001456_7_2 + (pub_r001456_1_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((sec_r001456_3_1 + (pub_r001456_17_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((sec_r001456_3_2 + (pub_r001456_17_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((pub_r001456_12_1 * 2) + 39) & 63;
  int stage_v_113_2 = ((pub_r001456_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001456_17_1 * 2) + 14) & 63;
  int stage_v_114_2 = ((pub_r001456_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((stage_v_110_1 + (pub_r001456_14_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_110_2 + (pub_r001456_14_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((stage_v_97_1 + (pub_r001456_18_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_97_2 + (pub_r001456_18_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((stage_v_34_1 + (pub_r001456_15_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((stage_v_34_2 + (pub_r001456_15_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((helper_flow_7_1 + (pub_r001456_16_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((helper_flow_7_2 + (pub_r001456_16_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((pub_r001456_0_1 * 2) + 37) & 63;
  int stage_v_119_2 = ((pub_r001456_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((helper_flow_7_1 + (pub_r001456_10_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((helper_flow_7_2 + (pub_r001456_10_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((stage_v_38_1 + (pub_r001456_15_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_38_2 + (pub_r001456_15_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((pub_r001456_11_1 * 2) + 39) & 63;
  int stage_v_122_2 = ((pub_r001456_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((stage_v_27_1 + (pub_r001456_1_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_27_2 + (pub_r001456_1_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((sec_r001456_19_1 + (pub_r001456_12_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((sec_r001456_19_2 + (pub_r001456_12_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((pub_r001456_0_1 * 2) + 43) & 63;
  int stage_v_125_2 = ((pub_r001456_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001456_6_1 * 2) + 34) & 63;
  int stage_v_126_2 = ((pub_r001456_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001456_17_1 * 2) + 47) & 63;
  int stage_v_127_2 = ((pub_r001456_17_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((stage_v_108_1 + (pub_r001456_8_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((stage_v_108_2 + (pub_r001456_8_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((stage_v_8_1 + (pub_r001456_16_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((stage_v_8_2 + (pub_r001456_16_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((stage_v_26_1 + (pub_r001456_2_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_26_2 + (pub_r001456_2_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((pub_r001456_16_1 * 2) + 11) & 63;
  int stage_v_131_2 = ((pub_r001456_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((stage_v_82_1 + (pub_r001456_16_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_82_2 + (pub_r001456_16_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((pub_r001456_0_1 * 2) + 11) & 63;
  int stage_v_133_2 = ((pub_r001456_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((stage_v_98_1 + (pub_r001456_6_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_98_2 + (pub_r001456_6_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((pub_r001456_7_1 * 2) + 43) & 63;
  int stage_v_135_2 = ((pub_r001456_7_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((stage_v_130_1 + (pub_r001456_7_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_130_2 + (pub_r001456_7_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((stage_v_51_1 + (pub_r001456_5_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_51_2 + (pub_r001456_5_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((helper_flow_2_1 + (pub_r001456_17_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((helper_flow_2_2 + (pub_r001456_17_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((sec_r001456_18_1 + (pub_r001456_14_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((sec_r001456_18_2 + (pub_r001456_14_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((stage_v_41_1 + (pub_r001456_1_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_41_2 + (pub_r001456_1_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((pub_r001456_8_1 * 2) + 22) & 63;
  int stage_v_141_2 = ((pub_r001456_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001456_18_1 * 2) + 45) & 63;
  int stage_v_142_2 = ((pub_r001456_18_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((stage_v_0_1 + (pub_r001456_12_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_0_2 + (pub_r001456_12_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((stage_v_121_1 + (pub_r001456_12_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((stage_v_121_2 + (pub_r001456_12_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((stage_v_6_1 + (pub_r001456_5_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_6_2 + (pub_r001456_5_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((pub_r001456_15_1 * 2) + 44) & 63;
  int stage_v_146_2 = ((pub_r001456_15_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((stage_v_136_1 + (pub_r001456_5_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_136_2 + (pub_r001456_5_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((stage_v_124_1 + (pub_r001456_13_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_124_2 + (pub_r001456_13_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((pub_r001456_0_1 * 2) + 30) & 63;
  int stage_v_149_2 = ((pub_r001456_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001456_11_1 * 2) + 19) & 63;
  int stage_v_150_2 = ((pub_r001456_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((stage_v_143_1 + (pub_r001456_16_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_143_2 + (pub_r001456_16_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((pub_r001456_18_1 * 2) + 31) & 63;
  int stage_v_152_2 = ((pub_r001456_18_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001456_6_1 * 2) + 19) & 63;
  int stage_v_153_2 = ((pub_r001456_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((stage_v_129_1 + (pub_r001456_6_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((stage_v_129_2 + (pub_r001456_6_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((stage_v_82_1 + (pub_r001456_9_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_82_2 + (pub_r001456_9_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((stage_v_74_1 + (pub_r001456_8_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((stage_v_74_2 + (pub_r001456_8_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((stage_v_31_1 + (pub_r001456_0_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_31_2 + (pub_r001456_0_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((pub_r001456_9_1 * 2) + 10) & 63;
  int stage_v_158_2 = ((pub_r001456_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001456_7_1 * 2) + 21) & 63;
  int stage_v_159_2 = ((pub_r001456_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((helper_flow_6_1 + (pub_r001456_4_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((helper_flow_6_2 + (pub_r001456_4_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((stage_v_97_1 + (pub_r001456_4_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_97_2 + (pub_r001456_4_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((sec_r001456_18_1 + (pub_r001456_4_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((sec_r001456_18_2 + (pub_r001456_4_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((stage_v_121_1 + (pub_r001456_6_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_121_2 + (pub_r001456_6_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((stage_v_27_1 + (pub_r001456_18_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_27_2 + (pub_r001456_18_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((pub_r001456_6_1 * 2) + 27) & 63;
  int stage_v_165_2 = ((pub_r001456_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001456_18_1 * 2) + 44) & 63;
  int stage_v_166_2 = ((pub_r001456_18_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((helper_flow_3_1 + (pub_r001456_12_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((helper_flow_3_2 + (pub_r001456_12_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((pub_r001456_14_1 * 2) + 11) & 63;
  int stage_v_168_2 = ((pub_r001456_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((stage_v_51_1 + (pub_r001456_18_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_51_2 + (pub_r001456_18_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((pub_r001456_0_1 * 2) + 42) & 63;
  int stage_v_170_2 = ((pub_r001456_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((stage_v_74_1 + (pub_r001456_7_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((stage_v_74_2 + (pub_r001456_7_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((helper_flow_2_1 + (pub_r001456_15_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((helper_flow_2_2 + (pub_r001456_15_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((pub_r001456_15_1 * 2) + 7) & 63;
  int stage_v_173_2 = ((pub_r001456_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001456_4_1 * 2) + 5) & 63;
  int stage_v_174_2 = ((pub_r001456_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((stage_v_1_1 + (pub_r001456_3_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_1_2 + (pub_r001456_3_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((stage_v_116_1 + (pub_r001456_8_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((stage_v_116_2 + (pub_r001456_8_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((pub_r001456_12_1 * 2) + 7) & 63;
  int stage_v_177_2 = ((pub_r001456_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001456_1_1 * 2) + 49) & 63;
  int stage_v_178_2 = ((pub_r001456_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((stage_v_55_1 + (pub_r001456_9_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((stage_v_55_2 + (pub_r001456_9_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((stage_v_17_1 + (pub_r001456_0_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_17_2 + (pub_r001456_0_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((pub_r001456_17_1 * 2) + 18) & 63;
  int stage_v_181_2 = ((pub_r001456_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((stage_v_70_1 + (pub_r001456_4_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_70_2 + (pub_r001456_4_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((pub_r001456_0_1 * 2) + 29) & 63;
  int stage_v_183_2 = ((pub_r001456_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((stage_v_55_1 + (pub_r001456_14_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_55_2 + (pub_r001456_14_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((pub_r001456_7_1 * 2) + 35) & 63;
  int stage_v_185_2 = ((pub_r001456_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001456_11_1 * 2) + 5) & 63;
  int stage_v_186_2 = ((pub_r001456_11_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001456_3_1 * 2) + 36) & 63;
  int stage_v_187_2 = ((pub_r001456_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001456_18_1 * 2) + 15) & 63;
  int stage_v_188_2 = ((pub_r001456_18_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((stage_v_71_1 + (pub_r001456_6_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_71_2 + (pub_r001456_6_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((stage_v_106_1 + (pub_r001456_1_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((stage_v_106_2 + (pub_r001456_1_2 * 2)) + 575) & 127;
  if (stage_v_190_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_190_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_190_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_190_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_191_1 = ((stage_v_12_1 + (pub_r001456_3_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((stage_v_12_2 + (pub_r001456_3_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((stage_v_34_1 + (pub_r001456_1_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_34_2 + (pub_r001456_1_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((pub_r001456_3_1 * 2) + 28) & 63;
  int stage_v_193_2 = ((pub_r001456_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((pub_r001456_7_1 * 2) + 36) & 63;
  int stage_v_194_2 = ((pub_r001456_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((stage_v_70_1 + (pub_r001456_17_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_70_2 + (pub_r001456_17_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((stage_v_41_1 + (pub_r001456_14_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((stage_v_41_2 + (pub_r001456_14_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((stage_v_59_1 + (pub_r001456_12_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_59_2 + (pub_r001456_12_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((pub_r001456_6_1 * 2) + 36) & 63;
  int stage_v_198_2 = ((pub_r001456_6_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((stage_v_124_1 + (pub_r001456_14_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_124_2 + (pub_r001456_14_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((pub_r001456_12_1 * 2) + 25) & 63;
  int stage_v_200_2 = ((pub_r001456_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((stage_v_28_1 + (pub_r001456_16_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_28_2 + (pub_r001456_16_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((stage_v_40_1 + (pub_r001456_17_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_40_2 + (pub_r001456_17_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((sec_r001456_6_1 + (pub_r001456_18_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((sec_r001456_6_2 + (pub_r001456_18_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((stage_v_15_1 + (pub_r001456_1_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_15_2 + (pub_r001456_1_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((pub_r001456_8_1 * 2) + 20) & 63;
  int stage_v_205_2 = ((pub_r001456_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001456_12_1 * 2) + 49) & 63;
  int stage_v_206_2 = ((pub_r001456_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((stage_v_196_1 + (pub_r001456_3_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((stage_v_196_2 + (pub_r001456_3_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((stage_v_18_1 + (pub_r001456_1_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_18_2 + (pub_r001456_1_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((sec_r001456_16_1 + (pub_r001456_4_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((sec_r001456_16_2 + (pub_r001456_4_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001456_13_1 != sec_r001456_13_2);
  __CPROVER_assume(pub_r001456_5_1 == pub_r001456_5_2);
  __CPROVER_assume(sec_r001456_7_1 != sec_r001456_7_2);
  __CPROVER_assume(sec_r001456_8_1 != sec_r001456_8_2);
  __CPROVER_assume(sec_r001456_12_1 != sec_r001456_12_2);
  __CPROVER_assume(sec_r001456_20_1 != sec_r001456_20_2);
  __CPROVER_assume(sec_r001456_14_1 != sec_r001456_14_2);
  __CPROVER_assume(sec_r001456_11_1 != sec_r001456_11_2);
  __CPROVER_assume(pub_r001456_7_1 == pub_r001456_7_2);
  __CPROVER_assume(sec_r001456_22_1 != sec_r001456_22_2);
  __CPROVER_assume(pub_r001456_9_1 == pub_r001456_9_2);
  __CPROVER_assume(sec_r001456_0_1 != sec_r001456_0_2);
  __CPROVER_assume(pub_r001456_10_1 == pub_r001456_10_2);
  __CPROVER_assume(sec_r001456_3_1 != sec_r001456_3_2);
  __CPROVER_assume(pub_r001456_16_1 == pub_r001456_16_2);
  __CPROVER_assume(pub_r001456_15_1 == pub_r001456_15_2);
  __CPROVER_assume(pub_r001456_1_1 == pub_r001456_1_2);
  __CPROVER_assume(pub_r001456_4_1 == pub_r001456_4_2);
  __CPROVER_assume(pub_r001456_17_1 == pub_r001456_17_2);
  __CPROVER_assume(sec_r001456_16_1 != sec_r001456_16_2);
  __CPROVER_assume(pub_r001456_3_1 == pub_r001456_3_2);
  __CPROVER_assume(pub_r001456_8_1 == pub_r001456_8_2);
  __CPROVER_assume(pub_r001456_2_1 == pub_r001456_2_2);
  __CPROVER_assume(pub_r001456_18_1 == pub_r001456_18_2);
  __CPROVER_assume(sec_r001456_6_1 != sec_r001456_6_2);
  __CPROVER_assume(sec_r001456_17_1 != sec_r001456_17_2);
  __CPROVER_assume(sec_r001456_5_1 != sec_r001456_5_2);
  __CPROVER_assume(sec_r001456_19_1 != sec_r001456_19_2);
  __CPROVER_assume(sec_r001456_4_1 != sec_r001456_4_2);
  __CPROVER_assume(sec_r001456_18_1 != sec_r001456_18_2);
  __CPROVER_assume(pub_r001456_13_1 == pub_r001456_13_2);
  __CPROVER_assume(sec_r001456_10_1 != sec_r001456_10_2);
  __CPROVER_assume(pub_r001456_0_1 == pub_r001456_0_2);
  __CPROVER_assume(pub_r001456_6_1 == pub_r001456_6_2);
  __CPROVER_assume(pub_r001456_11_1 == pub_r001456_11_2);
  __CPROVER_assume(sec_r001456_1_1 != sec_r001456_1_2);
  __CPROVER_assume(pub_r001456_14_1 == pub_r001456_14_2);
  __CPROVER_assume(sec_r001456_2_1 != sec_r001456_2_2);
  __CPROVER_assume(sec_r001456_15_1 != sec_r001456_15_2);
  __CPROVER_assume(sec_r001456_21_1 != sec_r001456_21_2);
  __CPROVER_assume(sec_r001456_9_1 != sec_r001456_9_2);
  __CPROVER_assume(pub_r001456_12_1 == pub_r001456_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.density == st_var_0_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.rms == st_var_2_2.rms);
  assert(st_var_2_1.peak == st_var_2_2.peak);
  assert(st_var_2_1.sample_rate == st_var_2_2.sample_rate);
  assert(st_var_2_1.envelope == st_var_2_2.envelope);
  assert(st_var_2_1.gain == st_var_2_2.gain);
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
}


