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
struct SensorNode_R001350_5013_0
{
  short reading;
  short threshold;
  int gain;
  int calib;
  int offset;
  int buffer[3];
};
struct Vector3D_R001350_5013_1
{
  int pitch;
  int coord_z;
  unsigned char coord_x;
  int coord_y;
  int heading;
  int buffer[3];
};
struct AudioFrame_R001350_5013_2
{
  unsigned char gain;
  int peak;
  int rms;
  int buffer[3];
};
union RegisterBank_R001350_5013_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R001350_5013_1
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
void fn_R001350_5013_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001350_5013_1 st_1 = {0};
  struct Vector3D_R001350_5013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int accumulator_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_25_1) & 63;
  aux_2 = (aux_2 + accumulator_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_21_1 = local_arr_1[aux_1 % 3];
  int accumulator_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_25_1 == accumulator_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_21_1 == accumulator_21_2);
}

int fn_R001350_5013_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001350_5013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int accumulator_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_25) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_21 = local_arr[aux % 3];
  acc = (acc + (accumulator_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001350_5013_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001350_5013_0 st_1 = {0};
  struct SensorNode_R001350_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int phase_64_1 = 0;
  int phase_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_64_1 = ((phase_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_64_2 = ((phase_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_64_1) & 127;
    acc_2 = (acc_2 + phase_64_2) & 127;
  }

  int phase_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_29_1 > 18)
  {
    acc_1 = ((acc_1 + (phase_29_1 * 2)) + 5) & 127;
    aux_1 ^= phase_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_29_2 > 18)
  {
    acc_2 = ((acc_2 + (phase_29_2 * 2)) + 5) & 127;
    aux_2 ^= phase_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_99_1) & 63;
  aux_2 = (aux_2 + accumulator_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_64_1 == phase_64_2);
  assert(phase_29_1 == phase_29_2);
  assert(accumulator_99_1 == accumulator_99_2);
}

int fn_R001350_5013_1(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001350_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int phase_64 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_64 = ((phase_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_64) & 127;
  }

  int phase_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_29 > 18)
  {
    acc = ((acc + (phase_29 * 2)) + 5) & 127;
    aux ^= phase_29 & 15;
  }
  else
  {
    acc = ((acc - phase_29) + 11) & 127;
    aux += 3;
  }
  int accumulator_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001350_5013_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001350_5013_2 st_1 = {0};
  struct AudioFrame_R001350_5013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_10_1 = local_arr_1[aux_1 % 3];
  int anchor_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_10_2 * 2)) & 127;
  int quotient_24_1 = 0;
  int quotient_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_24_1 = ((quotient_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_24_2 = ((quotient_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_24_1) & 127;
    acc_2 = (acc_2 + quotient_24_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_10_1 == anchor_10_2);
  assert(quotient_24_1 == quotient_24_2);
}

int fn_R001350_5013_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001350_5013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int anchor_10 = local_arr[aux % 3];
  acc = (acc + (anchor_10 * 2)) & 127;
  int quotient_24 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_24 = ((quotient_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_24) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001350_5013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001350_5013_2 st_1 = {0};
  struct AudioFrame_R001350_5013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_51_1 = 0;
  int stride_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_51_1 = ((stride_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_51_2 = ((stride_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_51_1) & 127;
    acc_2 = (acc_2 + stride_51_2) & 127;
  }

  int coefficient_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_38_1) & 63;
  aux_2 = (aux_2 + coefficient_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_51_1 == stride_51_2);
  assert(coefficient_38_1 == coefficient_38_2);
}

int fn_R001350_5013_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001350_5013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_51 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_51 = ((stride_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_51) & 127;
  }

  int coefficient_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_38) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001350_5013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001350_5013_2 st_1 = {0};
  struct AudioFrame_R001350_5013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int metric_35_1 = 0;
  int metric_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_35_1 = ((metric_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_35_2 = ((metric_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_35_1) & 127;
    acc_2 = (acc_2 + metric_35_2) & 127;
  }

  int tracker_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_72_1 > 49)
  {
    acc_1 = ((acc_1 + (tracker_72_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_72_2 > 49)
  {
    acc_2 = ((acc_2 + (tracker_72_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_72_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_35_1 == metric_35_2);
  assert(tracker_72_1 == tracker_72_2);
}

int fn_R001350_5013_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001350_5013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int metric_35 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_35 = ((metric_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_35) & 127;
  }

  int tracker_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_72 > 49)
  {
    acc = ((acc + (tracker_72 * 2)) + 5) & 127;
    aux ^= tracker_72 & 15;
  }
  else
  {
    acc = ((acc - tracker_72) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001350_5013_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001350_5013_1 st_1 = {0};
  struct Vector3D_R001350_5013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_90_1 = local_arr_1[aux_1 % 3];
  int stride_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_90_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_30_1)
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

  switch (window_30_2)
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
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_90_1 == stride_90_2);
  assert(window_30_1 == window_30_2);
}

int fn_R001350_5013_5(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001350_5013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int stride_90 = local_arr[aux % 3];
  acc = (acc + (stride_90 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_30 = (aux + st.buffer[1]) & 3;
  switch (window_30)
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

void fn_R001350_5013_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001350_5013_0 st_1 = {0};
  struct SensorNode_R001350_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int parity_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_38_1 > 13)
  {
    acc_1 = ((acc_1 + (parity_38_1 * 2)) + 5) & 127;
    aux_1 ^= parity_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_38_2 > 13)
  {
    acc_2 = ((acc_2 + (parity_38_2 * 2)) + 5) & 127;
    aux_2 ^= parity_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_92_1)
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

  switch (phase_92_2)
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
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_38_1 == parity_38_2);
  assert(phase_92_1 == phase_92_2);
}

int fn_R001350_5013_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001350_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int parity_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_38 > 13)
  {
    acc = ((acc + (parity_38 * 2)) + 5) & 127;
    aux ^= parity_38 & 15;
  }
  else
  {
    acc = ((acc - parity_38) + 11) & 127;
    aux += 3;
  }
  int phase_92 = (aux + st.buffer[1]) & 3;
  switch (phase_92)
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

void fn_R001350_5013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001350_5013_2 st_1 = {0};
  struct AudioFrame_R001350_5013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_57_1 = 0;
  int parity_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_57_1 = ((parity_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_57_2 = ((parity_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_57_1) & 127;
    acc_2 = (acc_2 + parity_57_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_57_1 == parity_57_2);
}

int fn_R001350_5013_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001350_5013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_57 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_57 = ((parity_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_57) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001350_5013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001350_5013_0 st_1 = {0};
  struct SensorNode_R001350_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_40_1 > 48)
  {
    acc_1 = ((acc_1 + (window_40_1 * 2)) + 5) & 127;
    aux_1 ^= window_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_40_2 > 48)
  {
    acc_2 = ((acc_2 + (window_40_2 * 2)) + 5) & 127;
    aux_2 ^= window_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_67_1 = local_arr_1[aux_1 % 3];
  int phase_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_67_2 * 2)) & 127;
  int cursor_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_19_1) & 63;
  aux_2 = (aux_2 + cursor_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_40_1 == window_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_67_1 == phase_67_2);
  assert(cursor_19_1 == cursor_19_2);
}

int fn_R001350_5013_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001350_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_40 > 48)
  {
    acc = ((acc + (window_40 * 2)) + 5) & 127;
    aux ^= window_40 & 15;
  }
  else
  {
    acc = ((acc - window_40) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int phase_67 = local_arr[aux % 3];
  acc = (acc + (phase_67 * 2)) & 127;
  int cursor_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_19) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001350_5013_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001350_5013_0 st_1 = {0};
  struct SensorNode_R001350_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int quantum_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_80_1) & 63;
  aux_2 = (aux_2 + quantum_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_46_1 = local_arr_1[aux_1 % 3];
  int offset_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_46_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_80_1 == quantum_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_46_1 == offset_46_2);
}

int fn_R001350_5013_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001350_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int quantum_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_80) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_46 = local_arr[aux % 3];
  acc = (acc + (offset_46 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001350_5013_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001350_5013_0 st_1 = {0};
  struct SensorNode_R001350_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int accumulator_22_1 = 0;
  int accumulator_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_22_1 = ((accumulator_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_22_2 = ((accumulator_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_22_1) & 127;
    acc_2 = (acc_2 + accumulator_22_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_89_1 > 16)
  {
    acc_1 = ((acc_1 + (metric_89_1 * 2)) + 5) & 127;
    aux_1 ^= metric_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_89_2 > 16)
  {
    acc_2 = ((acc_2 + (metric_89_2 * 2)) + 5) & 127;
    aux_2 ^= metric_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_66_1 = local_arr_1[aux_1 % 3];
  int margin_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_66_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_22_1 == accumulator_22_2);
  assert(metric_89_1 == metric_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_66_1 == margin_66_2);
}

int fn_R001350_5013_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001350_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int accumulator_22 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_22 = ((accumulator_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_22) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_89 > 16)
  {
    acc = ((acc + (metric_89 * 2)) + 5) & 127;
    aux ^= metric_89 & 15;
  }
  else
  {
    acc = ((acc - metric_89) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int margin_66 = local_arr[aux % 3];
  acc = (acc + (margin_66 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001350_5013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001350_5013_1 st_1 = {0};
  struct Vector3D_R001350_5013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_58_1 = local_arr_1[aux_1 % 3];
  int scale_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_58_2 * 2)) & 127;
  int metric_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_48_1)
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

  switch (metric_48_2)
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

  int stride_35_1 = 0;
  int stride_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_35_1 = ((stride_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_35_2 = ((stride_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_35_1) & 127;
    acc_2 = (acc_2 + stride_35_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_58_1 == scale_58_2);
  assert(metric_48_1 == metric_48_2);
  assert(stride_35_1 == stride_35_2);
}

int fn_R001350_5013_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001350_5013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int scale_58 = local_arr[aux % 3];
  acc = (acc + (scale_58 * 2)) & 127;
  int metric_48 = (aux + st.buffer[1]) & 3;
  switch (metric_48)
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

  int stride_35 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_35 = ((stride_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_35) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001350_5013_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001350_5013_0 st_1 = {0};
  struct SensorNode_R001350_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int residue_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_72_1) & 63;
  aux_2 = (aux_2 + residue_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_39_1 = 0;
  int factor_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_39_1 = ((factor_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_39_2 = ((factor_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_39_1) & 127;
    acc_2 = (acc_2 + factor_39_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_19_1 > 19)
  {
    acc_1 = ((acc_1 + (metric_19_1 * 2)) + 5) & 127;
    aux_1 ^= metric_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_19_2 > 19)
  {
    acc_2 = ((acc_2 + (metric_19_2 * 2)) + 5) & 127;
    aux_2 ^= metric_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_19_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_72_1 == residue_72_2);
  assert(factor_39_1 == factor_39_2);
  assert(metric_19_1 == metric_19_2);
}

int fn_R001350_5013_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001350_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int residue_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_72) & 63;
  acc ^= aux;
  int factor_39 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_39 = ((factor_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_39) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_19 > 19)
  {
    acc = ((acc + (metric_19 * 2)) + 5) & 127;
    aux ^= metric_19 & 15;
  }
  else
  {
    acc = ((acc - metric_19) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001350_5013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001350_5013_1 st_1 = {0};
  struct Vector3D_R001350_5013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_92_1 > 40)
  {
    acc_1 = ((acc_1 + (pivot_92_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_92_2 > 40)
  {
    acc_2 = ((acc_2 + (pivot_92_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_76_1 = local_arr_1[aux_1 % 3];
  int coefficient_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_76_2 * 2)) & 127;
  int segment_17_1 = 0;
  int segment_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_17_1 = ((segment_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_17_2 = ((segment_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_17_1) & 127;
    acc_2 = (acc_2 + segment_17_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_92_1 == pivot_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_76_1 == coefficient_76_2);
  assert(segment_17_1 == segment_17_2);
}

int fn_R001350_5013_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001350_5013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_92 > 40)
  {
    acc = ((acc + (pivot_92 * 2)) + 5) & 127;
    aux ^= pivot_92 & 15;
  }
  else
  {
    acc = ((acc - pivot_92) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int coefficient_76 = local_arr[aux % 3];
  acc = (acc + (coefficient_76 * 2)) & 127;
  int segment_17 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_17 = ((segment_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_17) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001350_5013_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001350_5013_0 st_1 = {0};
  struct SensorNode_R001350_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_36_1 = local_arr_1[aux_1 % 3];
  int tracker_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_36_2 * 2)) & 127;
  int tracker_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_48_1) & 63;
  aux_2 = (aux_2 + tracker_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_38_1 = 0;
  int threshold_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_38_1 = ((threshold_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_38_2 = ((threshold_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_38_1) & 127;
    acc_2 = (acc_2 + threshold_38_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_36_1 == tracker_36_2);
  assert(tracker_48_1 == tracker_48_2);
  assert(threshold_38_1 == threshold_38_2);
}

int fn_R001350_5013_14(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001350_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int tracker_36 = local_arr[aux % 3];
  acc = (acc + (tracker_36 * 2)) & 127;
  int tracker_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_48) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_38 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_38 = ((threshold_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_38) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001350_5013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001350_5013_1 st_1 = {0};
  struct Vector3D_R001350_5013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_19_1)
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

  switch (window_19_2)
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

  int coefficient_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_69_1) & 63;
  aux_2 = (aux_2 + coefficient_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_19_1 == window_19_2);
  assert(coefficient_69_1 == coefficient_69_2);
}

int fn_R001350_5013_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001350_5013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_19 = (aux + st.buffer[1]) & 3;
  switch (window_19)
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

  int coefficient_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_69) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001350_5013_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001350_5013_2 st_1 = {0};
  struct AudioFrame_R001350_5013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_46_1 = 0;
  int metric_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_46_1 = ((metric_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_46_2 = ((metric_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_46_1) & 127;
    acc_2 = (acc_2 + metric_46_2) & 127;
  }

  int parity_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_22_1 > 20)
  {
    acc_1 = ((acc_1 + (parity_22_1 * 2)) + 5) & 127;
    aux_1 ^= parity_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_22_2 > 20)
  {
    acc_2 = ((acc_2 + (parity_22_2 * 2)) + 5) & 127;
    aux_2 ^= parity_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_22_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_40_1)
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

  switch (margin_40_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_46_1 == metric_46_2);
  assert(parity_22_1 == parity_22_2);
  assert(margin_40_1 == margin_40_2);
}

int fn_R001350_5013_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001350_5013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_46 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_46 = ((metric_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_46) & 127;
  }

  int parity_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_22 > 20)
  {
    acc = ((acc + (parity_22 * 2)) + 5) & 127;
    aux ^= parity_22 & 15;
  }
  else
  {
    acc = ((acc - parity_22) + 11) & 127;
    aux += 3;
  }
  int margin_40 = (aux + st.buffer[1]) & 3;
  switch (margin_40)
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

void fn_R001350_5013_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001350_5013_0 st_1 = {0};
  struct SensorNode_R001350_5013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int parity_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_63_1)
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

  switch (parity_63_2)
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

  int residue_94_1 = 0;
  int residue_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_94_1 = ((residue_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_94_2 = ((residue_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_94_1) & 127;
    acc_2 = (acc_2 + residue_94_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_63_1 == parity_63_2);
  assert(residue_94_1 == residue_94_2);
}

int fn_R001350_5013_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001350_5013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int parity_63 = (aux + st.buffer[1]) & 3;
  switch (parity_63)
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

  int residue_94 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_94 = ((residue_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_94) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001350_0_1;
  int sec_r001350_0_2;
  int sec_r001350_1_1;
  int sec_r001350_1_2;
  int sec_r001350_2_1;
  int sec_r001350_2_2;
  int sec_r001350_3_1;
  int sec_r001350_3_2;
  int sec_r001350_4_1;
  int sec_r001350_4_2;
  int sec_r001350_5_1;
  int sec_r001350_5_2;
  int sec_r001350_6_1;
  int sec_r001350_6_2;
  int sec_r001350_7_1;
  int sec_r001350_7_2;
  int sec_r001350_8_1;
  int sec_r001350_8_2;
  int sec_r001350_9_1;
  int sec_r001350_9_2;
  int sec_r001350_10_1;
  int sec_r001350_10_2;
  int sec_r001350_11_1;
  int sec_r001350_11_2;
  int sec_r001350_12_1;
  int sec_r001350_12_2;
  int sec_r001350_13_1;
  int sec_r001350_13_2;
  int sec_r001350_14_1;
  int sec_r001350_14_2;
  int sec_r001350_15_1;
  int sec_r001350_15_2;
  int sec_r001350_16_1;
  int sec_r001350_16_2;
  int sec_r001350_17_1;
  int sec_r001350_17_2;
  int sec_r001350_18_1;
  int sec_r001350_18_2;
  int sec_r001350_19_1;
  int sec_r001350_19_2;
  int pub_r001350_0_1;
  int pub_r001350_0_2;
  int pub_r001350_1_1;
  int pub_r001350_1_2;
  int pub_r001350_2_1;
  int pub_r001350_2_2;
  int pub_r001350_3_1;
  int pub_r001350_3_2;
  int pub_r001350_4_1;
  int pub_r001350_4_2;
  int pub_r001350_5_1;
  int pub_r001350_5_2;
  int pub_r001350_6_1;
  int pub_r001350_6_2;
  int pub_r001350_7_1;
  int pub_r001350_7_2;
  int pub_r001350_8_1;
  int pub_r001350_8_2;
  int pub_r001350_9_1;
  int pub_r001350_9_2;
  int pub_r001350_10_1;
  int pub_r001350_10_2;
  int pub_r001350_11_1;
  int pub_r001350_11_2;
  int pub_r001350_12_1;
  int pub_r001350_12_2;
  int pub_r001350_13_1;
  int pub_r001350_13_2;
  int pub_r001350_14_1;
  int pub_r001350_14_2;
  int pub_r001350_15_1;
  int pub_r001350_15_2;
  int pub_r001350_16_1;
  int pub_r001350_16_2;
  int pub_r001350_17_1;
  int pub_r001350_17_2;
  int pub_r001350_18_1;
  int pub_r001350_18_2;
  int pub_r001350_19_1;
  int pub_r001350_19_2;
  int pub_r001350_20_1;
  int pub_r001350_20_2;
  int pub_r001350_21_1;
  int pub_r001350_21_2;
  int pub_r001350_22_1;
  int pub_r001350_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001350_0_1 >= (-100)) && (pub_r001350_0_1 <= 100));
  __CPROVER_assume((pub_r001350_0_2 >= (-100)) && (pub_r001350_0_2 <= 100));
  __CPROVER_assume((pub_r001350_1_1 >= (-100)) && (pub_r001350_1_1 <= 100));
  __CPROVER_assume((pub_r001350_1_2 >= (-100)) && (pub_r001350_1_2 <= 100));
  __CPROVER_assume((pub_r001350_2_1 >= (-100)) && (pub_r001350_2_1 <= 100));
  __CPROVER_assume((pub_r001350_2_2 >= (-100)) && (pub_r001350_2_2 <= 100));
  __CPROVER_assume((pub_r001350_3_1 >= (-100)) && (pub_r001350_3_1 <= 100));
  __CPROVER_assume((pub_r001350_3_2 >= (-100)) && (pub_r001350_3_2 <= 100));
  __CPROVER_assume((pub_r001350_4_1 >= (-100)) && (pub_r001350_4_1 <= 100));
  __CPROVER_assume((pub_r001350_4_2 >= (-100)) && (pub_r001350_4_2 <= 100));
  __CPROVER_assume((pub_r001350_5_1 >= (-100)) && (pub_r001350_5_1 <= 100));
  __CPROVER_assume((pub_r001350_5_2 >= (-100)) && (pub_r001350_5_2 <= 100));
  __CPROVER_assume((pub_r001350_6_1 >= (-100)) && (pub_r001350_6_1 <= 100));
  __CPROVER_assume((pub_r001350_6_2 >= (-100)) && (pub_r001350_6_2 <= 100));
  __CPROVER_assume((pub_r001350_7_1 >= (-100)) && (pub_r001350_7_1 <= 100));
  __CPROVER_assume((pub_r001350_7_2 >= (-100)) && (pub_r001350_7_2 <= 100));
  __CPROVER_assume((pub_r001350_8_1 >= (-100)) && (pub_r001350_8_1 <= 100));
  __CPROVER_assume((pub_r001350_8_2 >= (-100)) && (pub_r001350_8_2 <= 100));
  __CPROVER_assume((pub_r001350_9_1 >= (-100)) && (pub_r001350_9_1 <= 100));
  __CPROVER_assume((pub_r001350_9_2 >= (-100)) && (pub_r001350_9_2 <= 100));
  __CPROVER_assume((pub_r001350_10_1 >= (-100)) && (pub_r001350_10_1 <= 100));
  __CPROVER_assume((pub_r001350_10_2 >= (-100)) && (pub_r001350_10_2 <= 100));
  __CPROVER_assume((pub_r001350_11_1 >= (-100)) && (pub_r001350_11_1 <= 100));
  __CPROVER_assume((pub_r001350_11_2 >= (-100)) && (pub_r001350_11_2 <= 100));
  __CPROVER_assume((pub_r001350_12_1 >= (-100)) && (pub_r001350_12_1 <= 100));
  __CPROVER_assume((pub_r001350_12_2 >= (-100)) && (pub_r001350_12_2 <= 100));
  __CPROVER_assume((pub_r001350_13_1 >= (-100)) && (pub_r001350_13_1 <= 100));
  __CPROVER_assume((pub_r001350_13_2 >= (-100)) && (pub_r001350_13_2 <= 100));
  __CPROVER_assume((pub_r001350_14_1 >= (-100)) && (pub_r001350_14_1 <= 100));
  __CPROVER_assume((pub_r001350_14_2 >= (-100)) && (pub_r001350_14_2 <= 100));
  __CPROVER_assume((pub_r001350_15_1 >= (-100)) && (pub_r001350_15_1 <= 100));
  __CPROVER_assume((pub_r001350_15_2 >= (-100)) && (pub_r001350_15_2 <= 100));
  __CPROVER_assume((pub_r001350_16_1 >= (-100)) && (pub_r001350_16_1 <= 100));
  __CPROVER_assume((pub_r001350_16_2 >= (-100)) && (pub_r001350_16_2 <= 100));
  __CPROVER_assume((pub_r001350_17_1 >= (-100)) && (pub_r001350_17_1 <= 100));
  __CPROVER_assume((pub_r001350_17_2 >= (-100)) && (pub_r001350_17_2 <= 100));
  __CPROVER_assume((pub_r001350_18_1 >= (-100)) && (pub_r001350_18_1 <= 100));
  __CPROVER_assume((pub_r001350_18_2 >= (-100)) && (pub_r001350_18_2 <= 100));
  __CPROVER_assume((pub_r001350_19_1 >= (-100)) && (pub_r001350_19_1 <= 100));
  __CPROVER_assume((pub_r001350_19_2 >= (-100)) && (pub_r001350_19_2 <= 100));
  __CPROVER_assume((pub_r001350_20_1 >= (-100)) && (pub_r001350_20_1 <= 100));
  __CPROVER_assume((pub_r001350_20_2 >= (-100)) && (pub_r001350_20_2 <= 100));
  __CPROVER_assume((pub_r001350_21_1 >= (-100)) && (pub_r001350_21_1 <= 100));
  __CPROVER_assume((pub_r001350_21_2 >= (-100)) && (pub_r001350_21_2 <= 100));
  __CPROVER_assume((pub_r001350_22_1 >= (-100)) && (pub_r001350_22_1 <= 100));
  __CPROVER_assume((pub_r001350_22_2 >= (-100)) && (pub_r001350_22_2 <= 100));
  __CPROVER_assume((sec_r001350_0_1 >= 0) && (sec_r001350_0_1 <= 255));
  __CPROVER_assume((sec_r001350_0_2 >= 0) && (sec_r001350_0_2 <= 255));
  __CPROVER_assume((sec_r001350_1_1 >= 0) && (sec_r001350_1_1 <= 255));
  __CPROVER_assume((sec_r001350_1_2 >= 0) && (sec_r001350_1_2 <= 255));
  __CPROVER_assume((sec_r001350_2_1 >= 0) && (sec_r001350_2_1 <= 255));
  __CPROVER_assume((sec_r001350_2_2 >= 0) && (sec_r001350_2_2 <= 255));
  __CPROVER_assume((sec_r001350_3_1 >= 0) && (sec_r001350_3_1 <= 255));
  __CPROVER_assume((sec_r001350_3_2 >= 0) && (sec_r001350_3_2 <= 255));
  __CPROVER_assume((sec_r001350_4_1 >= 0) && (sec_r001350_4_1 <= 255));
  __CPROVER_assume((sec_r001350_4_2 >= 0) && (sec_r001350_4_2 <= 255));
  __CPROVER_assume((sec_r001350_5_1 >= 0) && (sec_r001350_5_1 <= 255));
  __CPROVER_assume((sec_r001350_5_2 >= 0) && (sec_r001350_5_2 <= 255));
  __CPROVER_assume((sec_r001350_6_1 >= 0) && (sec_r001350_6_1 <= 255));
  __CPROVER_assume((sec_r001350_6_2 >= 0) && (sec_r001350_6_2 <= 255));
  __CPROVER_assume((sec_r001350_7_1 >= 0) && (sec_r001350_7_1 <= 255));
  __CPROVER_assume((sec_r001350_7_2 >= 0) && (sec_r001350_7_2 <= 255));
  __CPROVER_assume((sec_r001350_8_1 >= 0) && (sec_r001350_8_1 <= 255));
  __CPROVER_assume((sec_r001350_8_2 >= 0) && (sec_r001350_8_2 <= 255));
  __CPROVER_assume((sec_r001350_9_1 >= 0) && (sec_r001350_9_1 <= 255));
  __CPROVER_assume((sec_r001350_9_2 >= 0) && (sec_r001350_9_2 <= 255));
  __CPROVER_assume((sec_r001350_10_1 >= 0) && (sec_r001350_10_1 <= 255));
  __CPROVER_assume((sec_r001350_10_2 >= 0) && (sec_r001350_10_2 <= 255));
  __CPROVER_assume((sec_r001350_11_1 >= 0) && (sec_r001350_11_1 <= 255));
  __CPROVER_assume((sec_r001350_11_2 >= 0) && (sec_r001350_11_2 <= 255));
  __CPROVER_assume((sec_r001350_12_1 >= 0) && (sec_r001350_12_1 <= 255));
  __CPROVER_assume((sec_r001350_12_2 >= 0) && (sec_r001350_12_2 <= 255));
  __CPROVER_assume((sec_r001350_13_1 >= 0) && (sec_r001350_13_1 <= 255));
  __CPROVER_assume((sec_r001350_13_2 >= 0) && (sec_r001350_13_2 <= 255));
  __CPROVER_assume((sec_r001350_14_1 >= 0) && (sec_r001350_14_1 <= 255));
  __CPROVER_assume((sec_r001350_14_2 >= 0) && (sec_r001350_14_2 <= 255));
  __CPROVER_assume((sec_r001350_15_1 >= 0) && (sec_r001350_15_1 <= 255));
  __CPROVER_assume((sec_r001350_15_2 >= 0) && (sec_r001350_15_2 <= 255));
  __CPROVER_assume((sec_r001350_16_1 >= 0) && (sec_r001350_16_1 <= 255));
  __CPROVER_assume((sec_r001350_16_2 >= 0) && (sec_r001350_16_2 <= 255));
  __CPROVER_assume((sec_r001350_17_1 >= 0) && (sec_r001350_17_1 <= 255));
  __CPROVER_assume((sec_r001350_17_2 >= 0) && (sec_r001350_17_2 <= 255));
  __CPROVER_assume((sec_r001350_18_1 >= 0) && (sec_r001350_18_1 <= 255));
  __CPROVER_assume((sec_r001350_18_2 >= 0) && (sec_r001350_18_2 <= 255));
  __CPROVER_assume((sec_r001350_19_1 >= 0) && (sec_r001350_19_1 <= 255));
  __CPROVER_assume((sec_r001350_19_2 >= 0) && (sec_r001350_19_2 <= 255));
  struct SensorNode_R001350_5013_0 st_var_0_1 = {0};
  struct SensorNode_R001350_5013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001350_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001350_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001350_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001350_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001350_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001350_0_2 + 7) & 15;
  struct Vector3D_R001350_5013_1 st_var_1_1 = {0};
  struct Vector3D_R001350_5013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001350_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001350_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001350_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001350_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001350_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001350_0_2 + 9) & 15;
  struct AudioFrame_R001350_5013_2 st_var_2_1 = {0};
  struct AudioFrame_R001350_5013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001350_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001350_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001350_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001350_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001350_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001350_0_2 + 11) & 15;
  union RegisterBank_R001350_5013_0 u_var_1;
  union RegisterBank_R001350_5013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001350_5013_0(sec_r001350_0_1, pub_r001350_1_1, pub_r001350_2_1, pub_r001350_3_1);
  int helper_flow_0_2 = fn_R001350_5013_0(sec_r001350_0_2, pub_r001350_1_2, pub_r001350_2_2, pub_r001350_3_2);
  fn_R001350_5013_0_2(sec_r001350_0_1, pub_r001350_1_1, pub_r001350_2_1, pub_r001350_3_1, sec_r001350_0_2, pub_r001350_1_2, pub_r001350_2_2, pub_r001350_3_2);
  int helper_flow_1_1 = fn_R001350_5013_1(sec_r001350_1_1, pub_r001350_2_1, pub_r001350_3_1);
  int helper_flow_1_2 = fn_R001350_5013_1(sec_r001350_1_2, pub_r001350_2_2, pub_r001350_3_2);
  fn_R001350_5013_1_2(sec_r001350_1_1, pub_r001350_2_1, pub_r001350_3_1, sec_r001350_1_2, pub_r001350_2_2, pub_r001350_3_2);
  int helper_flow_2_1 = fn_R001350_5013_2(sec_r001350_2_1, pub_r001350_3_1, pub_r001350_4_1, pub_r001350_5_1, pub_r001350_6_1);
  int helper_flow_2_2 = fn_R001350_5013_2(sec_r001350_2_2, pub_r001350_3_2, pub_r001350_4_2, pub_r001350_5_2, pub_r001350_6_2);
  fn_R001350_5013_2_2(sec_r001350_2_1, pub_r001350_3_1, pub_r001350_4_1, pub_r001350_5_1, pub_r001350_6_1, sec_r001350_2_2, pub_r001350_3_2, pub_r001350_4_2, pub_r001350_5_2, pub_r001350_6_2);
  int helper_flow_3_1 = fn_R001350_5013_3(sec_r001350_3_1, sec_r001350_4_1, pub_r001350_5_1, pub_r001350_6_1, pub_r001350_7_1);
  int helper_flow_3_2 = fn_R001350_5013_3(sec_r001350_3_2, sec_r001350_4_2, pub_r001350_5_2, pub_r001350_6_2, pub_r001350_7_2);
  fn_R001350_5013_3_2(sec_r001350_3_1, sec_r001350_4_1, pub_r001350_5_1, pub_r001350_6_1, pub_r001350_7_1, sec_r001350_3_2, sec_r001350_4_2, pub_r001350_5_2, pub_r001350_6_2, pub_r001350_7_2);
  int helper_flow_4_1 = fn_R001350_5013_4(sec_r001350_4_1, pub_r001350_5_1, pub_r001350_6_1, pub_r001350_7_1);
  int helper_flow_4_2 = fn_R001350_5013_4(sec_r001350_4_2, pub_r001350_5_2, pub_r001350_6_2, pub_r001350_7_2);
  fn_R001350_5013_4_2(sec_r001350_4_1, pub_r001350_5_1, pub_r001350_6_1, pub_r001350_7_1, sec_r001350_4_2, pub_r001350_5_2, pub_r001350_6_2, pub_r001350_7_2);
  int helper_flow_5_1 = fn_R001350_5013_5(sec_r001350_5_1, sec_r001350_6_1, pub_r001350_7_1);
  int helper_flow_5_2 = fn_R001350_5013_5(sec_r001350_5_2, sec_r001350_6_2, pub_r001350_7_2);
  fn_R001350_5013_5_2(sec_r001350_5_1, sec_r001350_6_1, pub_r001350_7_1, sec_r001350_5_2, sec_r001350_6_2, pub_r001350_7_2);
  int helper_flow_6_1 = fn_R001350_5013_6(sec_r001350_6_1, sec_r001350_7_1, pub_r001350_8_1, pub_r001350_9_1);
  int helper_flow_6_2 = fn_R001350_5013_6(sec_r001350_6_2, sec_r001350_7_2, pub_r001350_8_2, pub_r001350_9_2);
  fn_R001350_5013_6_2(sec_r001350_6_1, sec_r001350_7_1, pub_r001350_8_1, pub_r001350_9_1, sec_r001350_6_2, sec_r001350_7_2, pub_r001350_8_2, pub_r001350_9_2);
  int helper_flow_7_1 = fn_R001350_5013_7(sec_r001350_7_1, pub_r001350_8_1, pub_r001350_9_1, pub_r001350_10_1, pub_r001350_11_1);
  int helper_flow_7_2 = fn_R001350_5013_7(sec_r001350_7_2, pub_r001350_8_2, pub_r001350_9_2, pub_r001350_10_2, pub_r001350_11_2);
  fn_R001350_5013_7_2(sec_r001350_7_1, pub_r001350_8_1, pub_r001350_9_1, pub_r001350_10_1, pub_r001350_11_1, sec_r001350_7_2, pub_r001350_8_2, pub_r001350_9_2, pub_r001350_10_2, pub_r001350_11_2);
  int helper_flow_8_1 = fn_R001350_5013_8(sec_r001350_8_1, sec_r001350_9_1, pub_r001350_10_1, pub_r001350_11_1);
  int helper_flow_8_2 = fn_R001350_5013_8(sec_r001350_8_2, sec_r001350_9_2, pub_r001350_10_2, pub_r001350_11_2);
  fn_R001350_5013_8_2(sec_r001350_8_1, sec_r001350_9_1, pub_r001350_10_1, pub_r001350_11_1, sec_r001350_8_2, sec_r001350_9_2, pub_r001350_10_2, pub_r001350_11_2);
  int helper_flow_9_1 = fn_R001350_5013_9(sec_r001350_9_1, sec_r001350_10_1, pub_r001350_11_1, pub_r001350_12_1, pub_r001350_13_1);
  int helper_flow_9_2 = fn_R001350_5013_9(sec_r001350_9_2, sec_r001350_10_2, pub_r001350_11_2, pub_r001350_12_2, pub_r001350_13_2);
  fn_R001350_5013_9_2(sec_r001350_9_1, sec_r001350_10_1, pub_r001350_11_1, pub_r001350_12_1, pub_r001350_13_1, sec_r001350_9_2, sec_r001350_10_2, pub_r001350_11_2, pub_r001350_12_2, pub_r001350_13_2);
  int helper_flow_10_1 = fn_R001350_5013_10(sec_r001350_10_1, sec_r001350_11_1, pub_r001350_12_1, pub_r001350_13_1, pub_r001350_14_1);
  int helper_flow_10_2 = fn_R001350_5013_10(sec_r001350_10_2, sec_r001350_11_2, pub_r001350_12_2, pub_r001350_13_2, pub_r001350_14_2);
  fn_R001350_5013_10_2(sec_r001350_10_1, sec_r001350_11_1, pub_r001350_12_1, pub_r001350_13_1, pub_r001350_14_1, sec_r001350_10_2, sec_r001350_11_2, pub_r001350_12_2, pub_r001350_13_2, pub_r001350_14_2);
  int helper_flow_11_1 = fn_R001350_5013_11(sec_r001350_11_1, sec_r001350_12_1, pub_r001350_13_1, pub_r001350_14_1);
  int helper_flow_11_2 = fn_R001350_5013_11(sec_r001350_11_2, sec_r001350_12_2, pub_r001350_13_2, pub_r001350_14_2);
  fn_R001350_5013_11_2(sec_r001350_11_1, sec_r001350_12_1, pub_r001350_13_1, pub_r001350_14_1, sec_r001350_11_2, sec_r001350_12_2, pub_r001350_13_2, pub_r001350_14_2);
  int helper_flow_12_1 = fn_R001350_5013_12(sec_r001350_12_1, pub_r001350_13_1, pub_r001350_14_1, pub_r001350_15_1, pub_r001350_16_1);
  int helper_flow_12_2 = fn_R001350_5013_12(sec_r001350_12_2, pub_r001350_13_2, pub_r001350_14_2, pub_r001350_15_2, pub_r001350_16_2);
  fn_R001350_5013_12_2(sec_r001350_12_1, pub_r001350_13_1, pub_r001350_14_1, pub_r001350_15_1, pub_r001350_16_1, sec_r001350_12_2, pub_r001350_13_2, pub_r001350_14_2, pub_r001350_15_2, pub_r001350_16_2);
  int helper_flow_13_1 = fn_R001350_5013_13(sec_r001350_13_1, pub_r001350_14_1, pub_r001350_15_1, pub_r001350_16_1);
  int helper_flow_13_2 = fn_R001350_5013_13(sec_r001350_13_2, pub_r001350_14_2, pub_r001350_15_2, pub_r001350_16_2);
  fn_R001350_5013_13_2(sec_r001350_13_1, pub_r001350_14_1, pub_r001350_15_1, pub_r001350_16_1, sec_r001350_13_2, pub_r001350_14_2, pub_r001350_15_2, pub_r001350_16_2);
  int stage_v_0_1 = ((pub_r001350_22_1 * 2) + 28) & 63;
  int stage_v_0_2 = ((pub_r001350_22_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001350_6_1) & 127;
  int stage_v_1_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001350_6_2) & 127;
  if (stage_v_1_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (((sec_r001350_15_1 ^ 0x2A) * 2) + pub_r001350_13_1) & 127;
  int stage_v_2_2 = (((sec_r001350_15_2 ^ 0x2A) * 2) + pub_r001350_13_2) & 127;
  if (stage_v_2_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001350_19_1) & 127;
  int stage_v_3_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001350_19_2) & 127;
  if (stage_v_3_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((pub_r001350_14_1 * 2) + 29) & 63;
  int stage_v_4_2 = ((pub_r001350_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001350_13_1 * 2) + 43) & 63;
  int stage_v_5_2 = ((pub_r001350_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (((sec_r001350_3_1 ^ 0x2A) * 2) + pub_r001350_0_1) & 127;
  int stage_v_6_2 = (((sec_r001350_3_2 ^ 0x2A) * 2) + pub_r001350_0_2) & 127;
  if (stage_v_6_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (((sec_r001350_13_1 ^ 0x2A) * 2) + pub_r001350_9_1) & 127;
  int stage_v_7_2 = (((sec_r001350_13_2 ^ 0x2A) * 2) + pub_r001350_9_2) & 127;
  if (stage_v_7_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001350_18_1) & 127;
  int stage_v_8_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001350_18_2) & 127;
  if (stage_v_8_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001350_13_1) & 127;
  int stage_v_9_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001350_13_2) & 127;
  if (stage_v_9_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001350_1_1) & 127;
  int stage_v_10_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001350_1_2) & 127;
  if (stage_v_10_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001350_10_1) & 127;
  int stage_v_11_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001350_10_2) & 127;
  if (stage_v_11_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((pub_r001350_2_1 * 2) + 11) & 63;
  int stage_v_12_2 = ((pub_r001350_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001350_22_1) & 127;
  int stage_v_13_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001350_22_2) & 127;
  if (stage_v_13_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001350_11_1) & 127;
  int stage_v_14_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001350_11_2) & 127;
  if (stage_v_14_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = (((sec_r001350_3_1 ^ 0x2A) * 2) + pub_r001350_12_1) & 127;
  int stage_v_15_2 = (((sec_r001350_3_2 ^ 0x2A) * 2) + pub_r001350_12_2) & 127;
  if (stage_v_15_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (((sec_r001350_2_1 ^ 0x2A) * 2) + pub_r001350_13_1) & 127;
  int stage_v_16_2 = (((sec_r001350_2_2 ^ 0x2A) * 2) + pub_r001350_13_2) & 127;
  if (stage_v_16_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001350_12_1) & 127;
  int stage_v_17_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001350_12_2) & 127;
  if (stage_v_17_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001350_9_1) & 127;
  int stage_v_18_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001350_9_2) & 127;
  if (stage_v_18_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001350_21_1) & 127;
  int stage_v_19_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001350_21_2) & 127;
  if (stage_v_19_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001350_9_1) & 127;
  int stage_v_20_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001350_9_2) & 127;
  if (stage_v_20_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((sec_r001350_1_1 ^ 0x2A) * 2) + pub_r001350_9_1) & 127;
  int stage_v_21_2 = (((sec_r001350_1_2 ^ 0x2A) * 2) + pub_r001350_9_2) & 127;
  if (stage_v_21_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001350_15_1) & 127;
  int stage_v_22_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001350_15_2) & 127;
  if (stage_v_22_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001350_13_1) & 127;
  int stage_v_23_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001350_13_2) & 127;
  if (stage_v_23_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((sec_r001350_19_1 ^ 0x2A) * 2) + pub_r001350_9_1) & 127;
  int stage_v_24_2 = (((sec_r001350_19_2 ^ 0x2A) * 2) + pub_r001350_9_2) & 127;
  if (stage_v_24_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((pub_r001350_16_1 * 2) + 21) & 63;
  int stage_v_25_2 = ((pub_r001350_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001350_2_1) & 127;
  int stage_v_26_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001350_2_2) & 127;
  if (stage_v_26_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001350_4_1) & 127;
  int stage_v_27_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001350_4_2) & 127;
  if (stage_v_27_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = ((pub_r001350_8_1 * 2) + 41) & 63;
  int stage_v_28_2 = ((pub_r001350_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001350_8_1 * 2) + 39) & 63;
  int stage_v_29_2 = ((pub_r001350_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001350_2_1) & 127;
  int stage_v_30_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001350_2_2) & 127;
  if (stage_v_30_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = ((pub_r001350_1_1 * 2) + 39) & 63;
  int stage_v_31_2 = ((pub_r001350_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001350_6_1 * 2) + 35) & 63;
  int stage_v_32_2 = ((pub_r001350_6_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001350_8_1) & 127;
  int stage_v_33_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001350_8_2) & 127;
  if (stage_v_33_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001350_15_1) & 127;
  int stage_v_34_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001350_15_2) & 127;
  if (stage_v_34_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001350_3_1) & 127;
  int stage_v_35_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001350_3_2) & 127;
  if (stage_v_35_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((pub_r001350_12_1 * 2) + 47) & 63;
  int stage_v_36_2 = ((pub_r001350_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (((sec_r001350_15_1 ^ 0x2A) * 2) + pub_r001350_12_1) & 127;
  int stage_v_37_2 = (((sec_r001350_15_2 ^ 0x2A) * 2) + pub_r001350_12_2) & 127;
  if (stage_v_37_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((pub_r001350_21_1 * 2) + 40) & 63;
  int stage_v_38_2 = ((pub_r001350_21_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = (((sec_r001350_18_1 ^ 0x2A) * 2) + pub_r001350_9_1) & 127;
  int stage_v_39_2 = (((sec_r001350_18_2 ^ 0x2A) * 2) + pub_r001350_9_2) & 127;
  if (stage_v_39_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = (((sec_r001350_8_1 ^ 0x2A) * 2) + pub_r001350_18_1) & 127;
  int stage_v_40_2 = (((sec_r001350_8_2 ^ 0x2A) * 2) + pub_r001350_18_2) & 127;
  if (stage_v_40_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001350_3_1) & 127;
  int stage_v_41_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001350_3_2) & 127;
  if (stage_v_41_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((pub_r001350_19_1 * 2) + 27) & 63;
  int stage_v_42_2 = ((pub_r001350_19_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001350_18_1) & 127;
  int stage_v_43_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001350_18_2) & 127;
  if (stage_v_43_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (((helper_flow_12_1 ^ 0x2A) * 2) + pub_r001350_0_1) & 127;
  int stage_v_44_2 = (((helper_flow_12_2 ^ 0x2A) * 2) + pub_r001350_0_2) & 127;
  if (stage_v_44_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001350_5_1) & 127;
  int stage_v_45_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001350_5_2) & 127;
  if (stage_v_45_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((pub_r001350_4_1 * 2) + 23) & 63;
  int stage_v_46_2 = ((pub_r001350_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (((sec_r001350_19_1 ^ 0x2A) * 2) + pub_r001350_14_1) & 127;
  int stage_v_47_2 = (((sec_r001350_19_2 ^ 0x2A) * 2) + pub_r001350_14_2) & 127;
  if (stage_v_47_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001350_19_1) & 127;
  int stage_v_48_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001350_19_2) & 127;
  if (stage_v_48_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (((sec_r001350_17_1 ^ 0x2A) * 2) + pub_r001350_0_1) & 127;
  int stage_v_49_2 = (((sec_r001350_17_2 ^ 0x2A) * 2) + pub_r001350_0_2) & 127;
  if (stage_v_49_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (((sec_r001350_12_1 ^ 0x2A) * 2) + pub_r001350_10_1) & 127;
  int stage_v_50_2 = (((sec_r001350_12_2 ^ 0x2A) * 2) + pub_r001350_10_2) & 127;
  if (stage_v_50_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (((sec_r001350_6_1 ^ 0x2A) * 2) + pub_r001350_0_1) & 127;
  int stage_v_51_2 = (((sec_r001350_6_2 ^ 0x2A) * 2) + pub_r001350_0_2) & 127;
  if (stage_v_51_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((pub_r001350_21_1 * 2) + 15) & 63;
  int stage_v_52_2 = ((pub_r001350_21_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (((sec_r001350_8_1 ^ 0x2A) * 2) + pub_r001350_18_1) & 127;
  int stage_v_53_2 = (((sec_r001350_8_2 ^ 0x2A) * 2) + pub_r001350_18_2) & 127;
  if (stage_v_53_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001350_17_1) & 127;
  int stage_v_54_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001350_17_2) & 127;
  if (stage_v_54_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (((helper_flow_13_1 ^ 0x2A) * 2) + pub_r001350_21_1) & 127;
  int stage_v_55_2 = (((helper_flow_13_2 ^ 0x2A) * 2) + pub_r001350_21_2) & 127;
  if (stage_v_55_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((pub_r001350_20_1 * 2) + 15) & 63;
  int stage_v_56_2 = ((pub_r001350_20_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001350_7_1 * 2) + 34) & 63;
  int stage_v_57_2 = ((pub_r001350_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001350_2_1) & 127;
  int stage_v_58_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001350_2_2) & 127;
  if (stage_v_58_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001350_19_1) & 127;
  int stage_v_59_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001350_19_2) & 127;
  if (stage_v_59_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001350_10_1) & 127;
  int stage_v_60_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001350_10_2) & 127;
  if (stage_v_60_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001350_2_1) & 127;
  int stage_v_61_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001350_2_2) & 127;
  if (stage_v_61_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001350_6_1) & 127;
  int stage_v_62_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001350_6_2) & 127;
  if (stage_v_62_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001350_11_1) & 127;
  int stage_v_63_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001350_11_2) & 127;
  if (stage_v_63_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((sec_r001350_13_1 ^ 0x2A) * 2) + pub_r001350_13_1) & 127;
  int stage_v_64_2 = (((sec_r001350_13_2 ^ 0x2A) * 2) + pub_r001350_13_2) & 127;
  if (stage_v_64_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((pub_r001350_12_1 * 2) + 36) & 63;
  int stage_v_65_2 = ((pub_r001350_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((sec_r001350_9_1 ^ 0x2A) * 2) + pub_r001350_14_1) & 127;
  int stage_v_66_2 = (((sec_r001350_9_2 ^ 0x2A) * 2) + pub_r001350_14_2) & 127;
  if (stage_v_66_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((pub_r001350_15_1 * 2) + 49) & 63;
  int stage_v_67_2 = ((pub_r001350_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001350_3_1 * 2) + 11) & 63;
  int stage_v_68_2 = ((pub_r001350_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001350_7_1) & 127;
  int stage_v_69_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001350_7_2) & 127;
  if (stage_v_69_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001350_12_1) & 127;
  int stage_v_70_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001350_12_2) & 127;
  if (stage_v_70_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((pub_r001350_10_1 * 2) + 47) & 63;
  int stage_v_71_2 = ((pub_r001350_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001350_17_1 * 2) + 49) & 63;
  int stage_v_72_2 = ((pub_r001350_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001350_19_1) & 127;
  int stage_v_73_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001350_19_2) & 127;
  if (stage_v_73_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((sec_r001350_9_1 ^ 0x2A) * 2) + pub_r001350_0_1) & 127;
  int stage_v_74_2 = (((sec_r001350_9_2 ^ 0x2A) * 2) + pub_r001350_0_2) & 127;
  if (stage_v_74_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = ((pub_r001350_8_1 * 2) + 16) & 63;
  int stage_v_75_2 = ((pub_r001350_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001350_3_1 * 2) + 5) & 63;
  int stage_v_76_2 = ((pub_r001350_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001350_12_1 * 2) + 16) & 63;
  int stage_v_77_2 = ((pub_r001350_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001350_14_1 * 2) + 44) & 63;
  int stage_v_78_2 = ((pub_r001350_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001350_9_1 * 2) + 25) & 63;
  int stage_v_79_2 = ((pub_r001350_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (((helper_flow_12_1 ^ 0x2A) * 2) + pub_r001350_3_1) & 127;
  int stage_v_80_2 = (((helper_flow_12_2 ^ 0x2A) * 2) + pub_r001350_3_2) & 127;
  if (stage_v_80_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((pub_r001350_18_1 * 2) + 46) & 63;
  int stage_v_81_2 = ((pub_r001350_18_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001350_22_1) & 127;
  int stage_v_82_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001350_22_2) & 127;
  if (stage_v_82_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (((sec_r001350_3_1 ^ 0x2A) * 2) + pub_r001350_7_1) & 127;
  int stage_v_83_2 = (((sec_r001350_3_2 ^ 0x2A) * 2) + pub_r001350_7_2) & 127;
  if (stage_v_83_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (((stage_v_33_1 ^ 0x2A) * 2) + pub_r001350_1_1) & 127;
  int stage_v_84_2 = (((stage_v_33_2 ^ 0x2A) * 2) + pub_r001350_1_2) & 127;
  if (stage_v_84_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001350_14_1) & 127;
  int stage_v_85_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001350_14_2) & 127;
  if (stage_v_85_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = (((sec_r001350_9_1 ^ 0x2A) * 2) + pub_r001350_16_1) & 127;
  int stage_v_86_2 = (((sec_r001350_9_2 ^ 0x2A) * 2) + pub_r001350_16_2) & 127;
  if (stage_v_86_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001350_6_1) & 127;
  int stage_v_87_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001350_6_2) & 127;
  if (stage_v_87_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001350_2_1) & 127;
  int stage_v_88_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001350_2_2) & 127;
  if (stage_v_88_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((pub_r001350_12_1 * 2) + 17) & 63;
  int stage_v_89_2 = ((pub_r001350_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((helper_flow_12_1 ^ 0x2A) * 2) + pub_r001350_12_1) & 127;
  int stage_v_90_2 = (((helper_flow_12_2 ^ 0x2A) * 2) + pub_r001350_12_2) & 127;
  if (stage_v_90_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001350_18_1) & 127;
  int stage_v_91_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001350_18_2) & 127;
  if (stage_v_91_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001350_17_1) & 127;
  int stage_v_92_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001350_17_2) & 127;
  if (stage_v_92_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001350_21_1) & 127;
  int stage_v_93_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001350_21_2) & 127;
  if (stage_v_93_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001350_16_1) & 127;
  int stage_v_94_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001350_16_2) & 127;
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
  int stage_v_95_1 = ((pub_r001350_1_1 * 2) + 10) & 63;
  int stage_v_95_2 = ((pub_r001350_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((sec_r001350_10_1 ^ 0x2A) * 2) + pub_r001350_14_1) & 127;
  int stage_v_96_2 = (((sec_r001350_10_2 ^ 0x2A) * 2) + pub_r001350_14_2) & 127;
  if (stage_v_96_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (((sec_r001350_13_1 ^ 0x2A) * 2) + pub_r001350_20_1) & 127;
  int stage_v_97_2 = (((sec_r001350_13_2 ^ 0x2A) * 2) + pub_r001350_20_2) & 127;
  if (stage_v_97_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001350_14_1) & 127;
  int stage_v_98_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001350_14_2) & 127;
  if (stage_v_98_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((pub_r001350_1_1 * 2) + 45) & 63;
  int stage_v_99_2 = ((pub_r001350_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001350_9_1) & 127;
  int stage_v_100_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001350_9_2) & 127;
  if (stage_v_100_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001350_2_1) & 127;
  int stage_v_101_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001350_2_2) & 127;
  if (stage_v_101_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((pub_r001350_0_1 * 2) + 19) & 63;
  int stage_v_102_2 = ((pub_r001350_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001350_20_1) & 127;
  int stage_v_103_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001350_20_2) & 127;
  if (stage_v_103_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001350_12_1) & 127;
  int stage_v_104_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001350_12_2) & 127;
  if (stage_v_104_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((pub_r001350_9_1 * 2) + 7) & 63;
  int stage_v_105_2 = ((pub_r001350_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001350_17_1) & 127;
  int stage_v_106_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001350_17_2) & 127;
  if (stage_v_106_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001350_12_1) & 127;
  int stage_v_107_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001350_12_2) & 127;
  if (stage_v_107_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((pub_r001350_15_1 * 2) + 25) & 63;
  int stage_v_108_2 = ((pub_r001350_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001350_6_1) & 127;
  int stage_v_109_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001350_6_2) & 127;
  if (stage_v_109_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = (((stage_v_80_1 ^ 0x2A) * 2) + pub_r001350_1_1) & 127;
  int stage_v_110_2 = (((stage_v_80_2 ^ 0x2A) * 2) + pub_r001350_1_2) & 127;
  if (stage_v_110_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (((stage_v_73_1 ^ 0x2A) * 2) + pub_r001350_10_1) & 127;
  int stage_v_111_2 = (((stage_v_73_2 ^ 0x2A) * 2) + pub_r001350_10_2) & 127;
  if (stage_v_111_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = (((stage_v_69_1 ^ 0x2A) * 2) + pub_r001350_17_1) & 127;
  int stage_v_112_2 = (((stage_v_69_2 ^ 0x2A) * 2) + pub_r001350_17_2) & 127;
  if (stage_v_112_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (((sec_r001350_7_1 ^ 0x2A) * 2) + pub_r001350_17_1) & 127;
  int stage_v_113_2 = (((sec_r001350_7_2 ^ 0x2A) * 2) + pub_r001350_17_2) & 127;
  if (stage_v_113_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001350_2_1) & 127;
  int stage_v_114_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001350_2_2) & 127;
  if (stage_v_114_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((pub_r001350_6_1 * 2) + 18) & 63;
  int stage_v_115_2 = ((pub_r001350_6_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001350_15_1) & 127;
  int stage_v_116_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001350_15_2) & 127;
  if (stage_v_116_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((pub_r001350_19_1 * 2) + 47) & 63;
  int stage_v_117_2 = ((pub_r001350_19_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001350_14_1) & 127;
  int stage_v_118_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001350_14_2) & 127;
  if (stage_v_118_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001350_10_1) & 127;
  int stage_v_119_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001350_10_2) & 127;
  if (stage_v_119_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((pub_r001350_22_1 * 2) + 44) & 63;
  int stage_v_120_2 = ((pub_r001350_22_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001350_11_1 * 2) + 49) & 63;
  int stage_v_121_2 = ((pub_r001350_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (((stage_v_90_1 ^ 0x2A) * 2) + pub_r001350_17_1) & 127;
  int stage_v_122_2 = (((stage_v_90_2 ^ 0x2A) * 2) + pub_r001350_17_2) & 127;
  if (stage_v_122_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((stage_v_107_1 ^ 0x2A) * 2) + pub_r001350_8_1) & 127;
  int stage_v_123_2 = (((stage_v_107_2 ^ 0x2A) * 2) + pub_r001350_8_2) & 127;
  if (stage_v_123_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (((sec_r001350_5_1 ^ 0x2A) * 2) + pub_r001350_22_1) & 127;
  int stage_v_124_2 = (((sec_r001350_5_2 ^ 0x2A) * 2) + pub_r001350_22_2) & 127;
  if (stage_v_124_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((pub_r001350_5_1 * 2) + 40) & 63;
  int stage_v_125_2 = ((pub_r001350_5_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((stage_v_100_1 ^ 0x2A) * 2) + pub_r001350_2_1) & 127;
  int stage_v_126_2 = (((stage_v_100_2 ^ 0x2A) * 2) + pub_r001350_2_2) & 127;
  if (stage_v_126_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((pub_r001350_9_1 * 2) + 49) & 63;
  int stage_v_127_2 = ((pub_r001350_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = (((sec_r001350_3_1 ^ 0x2A) * 2) + pub_r001350_5_1) & 127;
  int stage_v_128_2 = (((sec_r001350_3_2 ^ 0x2A) * 2) + pub_r001350_5_2) & 127;
  if (stage_v_128_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001350_11_1) & 127;
  int stage_v_129_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001350_11_2) & 127;
  if (stage_v_129_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001350_6_1) & 127;
  int stage_v_130_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001350_6_2) & 127;
  if (stage_v_130_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = (((sec_r001350_16_1 ^ 0x2A) * 2) + pub_r001350_14_1) & 127;
  int stage_v_131_2 = (((sec_r001350_16_2 ^ 0x2A) * 2) + pub_r001350_14_2) & 127;
  if (stage_v_131_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (((stage_v_15_1 ^ 0x2A) * 2) + pub_r001350_11_1) & 127;
  int stage_v_132_2 = (((stage_v_15_2 ^ 0x2A) * 2) + pub_r001350_11_2) & 127;
  if (stage_v_132_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((pub_r001350_9_1 * 2) + 47) & 63;
  int stage_v_133_2 = ((pub_r001350_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = (((stage_v_110_1 ^ 0x2A) * 2) + pub_r001350_19_1) & 127;
  int stage_v_134_2 = (((stage_v_110_2 ^ 0x2A) * 2) + pub_r001350_19_2) & 127;
  if (stage_v_134_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((pub_r001350_13_1 * 2) + 40) & 63;
  int stage_v_135_2 = ((pub_r001350_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001350_10_1) & 127;
  int stage_v_136_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001350_10_2) & 127;
  if (stage_v_136_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((pub_r001350_6_1 * 2) + 31) & 63;
  int stage_v_137_2 = ((pub_r001350_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001350_21_1) & 127;
  int stage_v_138_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001350_21_2) & 127;
  if (stage_v_138_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (((sec_r001350_7_1 ^ 0x2A) * 2) + pub_r001350_21_1) & 127;
  int stage_v_139_2 = (((sec_r001350_7_2 ^ 0x2A) * 2) + pub_r001350_21_2) & 127;
  if (stage_v_139_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001350_13_1) & 127;
  int stage_v_140_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001350_13_2) & 127;
  if (stage_v_140_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001350_15_1) & 127;
  int stage_v_141_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001350_15_2) & 127;
  if (stage_v_141_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((pub_r001350_7_1 * 2) + 35) & 63;
  int stage_v_142_2 = ((pub_r001350_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001350_13_1) & 127;
  int stage_v_143_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001350_13_2) & 127;
  if (stage_v_143_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001350_20_1) & 127;
  int stage_v_144_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001350_20_2) & 127;
  if (stage_v_144_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (((sec_r001350_18_1 ^ 0x2A) * 2) + pub_r001350_8_1) & 127;
  int stage_v_145_2 = (((sec_r001350_18_2 ^ 0x2A) * 2) + pub_r001350_8_2) & 127;
  if (stage_v_145_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (((sec_r001350_8_1 ^ 0x2A) * 2) + pub_r001350_11_1) & 127;
  int stage_v_146_2 = (((sec_r001350_8_2 ^ 0x2A) * 2) + pub_r001350_11_2) & 127;
  if (stage_v_146_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001350_22_1) & 127;
  int stage_v_147_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001350_22_2) & 127;
  if (stage_v_147_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001350_20_1) & 127;
  int stage_v_148_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001350_20_2) & 127;
  if (stage_v_148_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001350_10_1) & 127;
  int stage_v_149_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001350_10_2) & 127;
  if (stage_v_149_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (((sec_r001350_2_1 ^ 0x2A) * 2) + pub_r001350_4_1) & 127;
  int stage_v_150_2 = (((sec_r001350_2_2 ^ 0x2A) * 2) + pub_r001350_4_2) & 127;
  if (stage_v_150_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = (((sec_r001350_14_1 ^ 0x2A) * 2) + pub_r001350_13_1) & 127;
  int stage_v_151_2 = (((sec_r001350_14_2 ^ 0x2A) * 2) + pub_r001350_13_2) & 127;
  if (stage_v_151_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001350_8_1) & 127;
  int stage_v_152_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001350_8_2) & 127;
  if (stage_v_152_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001350_0_1) & 127;
  int stage_v_153_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001350_0_2) & 127;
  if (stage_v_153_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001350_7_1) & 127;
  int stage_v_154_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001350_7_2) & 127;
  if (stage_v_154_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001350_9_1) & 127;
  int stage_v_155_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001350_9_2) & 127;
  if (stage_v_155_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((stage_v_155_1 ^ 0x2A) * 2) + pub_r001350_10_1) & 127;
  int stage_v_156_2 = (((stage_v_155_2 ^ 0x2A) * 2) + pub_r001350_10_2) & 127;
  if (stage_v_156_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001350_14_1) & 127;
  int stage_v_157_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001350_14_2) & 127;
  if (stage_v_157_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (((stage_v_122_1 ^ 0x2A) * 2) + pub_r001350_8_1) & 127;
  int stage_v_158_2 = (((stage_v_122_2 ^ 0x2A) * 2) + pub_r001350_8_2) & 127;
  if (stage_v_158_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001350_7_1) & 127;
  int stage_v_159_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001350_7_2) & 127;
  if (stage_v_159_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001350_4_1) & 127;
  int stage_v_160_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001350_4_2) & 127;
  if (stage_v_160_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001350_15_1) & 127;
  int stage_v_161_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001350_15_2) & 127;
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
  int stage_v_162_1 = ((pub_r001350_1_1 * 2) + 16) & 63;
  int stage_v_162_2 = ((pub_r001350_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (((stage_v_161_1 ^ 0x2A) * 2) + pub_r001350_20_1) & 127;
  int stage_v_163_2 = (((stage_v_161_2 ^ 0x2A) * 2) + pub_r001350_20_2) & 127;
  if (stage_v_163_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001350_0_1) & 127;
  int stage_v_164_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001350_0_2) & 127;
  if (stage_v_164_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((pub_r001350_1_1 * 2) + 12) & 63;
  int stage_v_165_2 = ((pub_r001350_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001350_17_1 * 2) + 37) & 63;
  int stage_v_166_2 = ((pub_r001350_17_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((sec_r001350_10_1 ^ 0x2A) * 2) + pub_r001350_6_1) & 127;
  int stage_v_167_2 = (((sec_r001350_10_2 ^ 0x2A) * 2) + pub_r001350_6_2) & 127;
  if (stage_v_167_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((stage_v_164_1 ^ 0x2A) * 2) + pub_r001350_16_1) & 127;
  int stage_v_168_2 = (((stage_v_164_2 ^ 0x2A) * 2) + pub_r001350_16_2) & 127;
  if (stage_v_168_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001350_9_1) & 127;
  int stage_v_169_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001350_9_2) & 127;
  if (stage_v_169_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((stage_v_149_1 ^ 0x2A) * 2) + pub_r001350_10_1) & 127;
  int stage_v_170_2 = (((stage_v_149_2 ^ 0x2A) * 2) + pub_r001350_10_2) & 127;
  if (stage_v_170_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (((stage_v_169_1 ^ 0x2A) * 2) + pub_r001350_11_1) & 127;
  int stage_v_171_2 = (((stage_v_169_2 ^ 0x2A) * 2) + pub_r001350_11_2) & 127;
  if (stage_v_171_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((pub_r001350_0_1 * 2) + 17) & 63;
  int stage_v_172_2 = ((pub_r001350_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001350_18_1) & 127;
  int stage_v_173_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001350_18_2) & 127;
  if (stage_v_173_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001350_15_1) & 127;
  int stage_v_174_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001350_15_2) & 127;
  if (stage_v_174_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((pub_r001350_4_1 * 2) + 49) & 63;
  int stage_v_175_2 = ((pub_r001350_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001350_14_1) & 127;
  int stage_v_176_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001350_14_2) & 127;
  if (stage_v_176_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((pub_r001350_18_1 * 2) + 19) & 63;
  int stage_v_177_2 = ((pub_r001350_18_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001350_6_1) & 127;
  int stage_v_178_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001350_6_2) & 127;
  if (stage_v_178_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001350_1_1) & 127;
  int stage_v_179_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001350_1_2) & 127;
  if (stage_v_179_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001350_10_1) & 127;
  int stage_v_180_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001350_10_2) & 127;
  if (stage_v_180_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001350_11_1) & 127;
  int stage_v_181_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001350_11_2) & 127;
  if (stage_v_181_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((pub_r001350_9_1 * 2) + 9) & 63;
  int stage_v_182_2 = ((pub_r001350_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001350_1_1) & 127;
  int stage_v_183_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001350_1_2) & 127;
  if (stage_v_183_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = (((stage_v_140_1 ^ 0x2A) * 2) + pub_r001350_17_1) & 127;
  int stage_v_184_2 = (((stage_v_140_2 ^ 0x2A) * 2) + pub_r001350_17_2) & 127;
  if (stage_v_184_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001350_16_1) & 127;
  int stage_v_185_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001350_16_2) & 127;
  if (stage_v_185_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001350_3_1) & 127;
  int stage_v_186_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001350_3_2) & 127;
  if (stage_v_186_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001350_17_1) & 127;
  int stage_v_187_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001350_17_2) & 127;
  if (stage_v_187_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = (((stage_v_128_1 ^ 0x2A) * 2) + pub_r001350_14_1) & 127;
  int stage_v_188_2 = (((stage_v_128_2 ^ 0x2A) * 2) + pub_r001350_14_2) & 127;
  if (stage_v_188_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001350_17_1) & 127;
  int stage_v_189_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001350_17_2) & 127;
  if (stage_v_189_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((stage_v_126_1 ^ 0x2A) * 2) + pub_r001350_6_1) & 127;
  int stage_v_190_2 = (((stage_v_126_2 ^ 0x2A) * 2) + pub_r001350_6_2) & 127;
  if (stage_v_190_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = (((stage_v_153_1 ^ 0x2A) * 2) + pub_r001350_16_1) & 127;
  int stage_v_191_2 = (((stage_v_153_2 ^ 0x2A) * 2) + pub_r001350_16_2) & 127;
  if (stage_v_191_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001350_14_1) & 127;
  int stage_v_192_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001350_14_2) & 127;
  if (stage_v_192_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((pub_r001350_8_1 * 2) + 38) & 63;
  int stage_v_193_2 = ((pub_r001350_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001350_8_1) & 127;
  int stage_v_194_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001350_8_2) & 127;
  if (stage_v_194_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = (((stage_v_101_1 ^ 0x2A) * 2) + pub_r001350_7_1) & 127;
  int stage_v_195_2 = (((stage_v_101_2 ^ 0x2A) * 2) + pub_r001350_7_2) & 127;
  if (stage_v_195_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = (((sec_r001350_0_1 ^ 0x2A) * 2) + pub_r001350_14_1) & 127;
  int stage_v_196_2 = (((sec_r001350_0_2 ^ 0x2A) * 2) + pub_r001350_14_2) & 127;
  if (stage_v_196_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((pub_r001350_17_1 * 2) + 36) & 63;
  int stage_v_197_2 = ((pub_r001350_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001350_19_1) & 127;
  int stage_v_198_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001350_19_2) & 127;
  if (stage_v_198_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001350_5_1) & 127;
  int stage_v_199_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001350_5_2) & 127;
  if (stage_v_199_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = (((stage_v_167_1 ^ 0x2A) * 2) + pub_r001350_3_1) & 127;
  int stage_v_200_2 = (((stage_v_167_2 ^ 0x2A) * 2) + pub_r001350_3_2) & 127;
  if (stage_v_200_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((pub_r001350_15_1 * 2) + 24) & 63;
  int stage_v_201_2 = ((pub_r001350_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001350_1_1) & 127;
  int stage_v_202_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001350_1_2) & 127;
  if (stage_v_202_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((pub_r001350_3_1 * 2) + 11) & 63;
  int stage_v_203_2 = ((pub_r001350_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001350_14_1) & 127;
  int stage_v_204_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001350_14_2) & 127;
  if (stage_v_204_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((pub_r001350_4_1 * 2) + 12) & 63;
  int stage_v_205_2 = ((pub_r001350_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001350_16_1 * 2) + 21) & 63;
  int stage_v_206_2 = ((pub_r001350_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (((stage_v_171_1 ^ 0x2A) * 2) + pub_r001350_22_1) & 127;
  int stage_v_207_2 = (((stage_v_171_2 ^ 0x2A) * 2) + pub_r001350_22_2) & 127;
  if (stage_v_207_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = (((stage_v_185_1 ^ 0x2A) * 2) + pub_r001350_1_1) & 127;
  int stage_v_208_2 = (((stage_v_185_2 ^ 0x2A) * 2) + pub_r001350_1_2) & 127;
  if (stage_v_208_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = (((stage_v_80_1 ^ 0x2A) * 2) + pub_r001350_19_1) & 127;
  int stage_v_209_2 = (((stage_v_80_2 ^ 0x2A) * 2) + pub_r001350_19_2) & 127;
  if (stage_v_209_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = (((stage_v_86_1 ^ 0x2A) * 2) + pub_r001350_0_1) & 127;
  int stage_v_210_2 = (((stage_v_86_2 ^ 0x2A) * 2) + pub_r001350_0_2) & 127;
  if (stage_v_210_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
  }
  if (stage_v_210_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = (((stage_v_171_1 ^ 0x2A) * 2) + pub_r001350_14_1) & 127;
  int stage_v_211_2 = (((stage_v_171_2 ^ 0x2A) * 2) + pub_r001350_14_2) & 127;
  if (stage_v_211_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((pub_r001350_13_1 * 2) + 11) & 63;
  int stage_v_212_2 = ((pub_r001350_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001350_16_1 * 2) + 29) & 63;
  int stage_v_213_2 = ((pub_r001350_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001350_3_1 * 2) + 39) & 63;
  int stage_v_214_2 = ((pub_r001350_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((stage_v_202_1 ^ 0x2A) * 2) + pub_r001350_6_1) & 127;
  int stage_v_215_2 = (((stage_v_202_2 ^ 0x2A) * 2) + pub_r001350_6_2) & 127;
  if (stage_v_215_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
  }
  if (stage_v_215_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((pub_r001350_22_1 * 2) + 35) & 63;
  int stage_v_216_2 = ((pub_r001350_22_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((sec_r001350_17_1 ^ 0x2A) * 2) + pub_r001350_16_1) & 127;
  int stage_v_217_2 = (((sec_r001350_17_2 ^ 0x2A) * 2) + pub_r001350_16_2) & 127;
  if (stage_v_217_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001350_11_1) & 127;
  int stage_v_218_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001350_11_2) & 127;
  if (stage_v_218_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = (((stage_v_111_1 ^ 0x2A) * 2) + pub_r001350_12_1) & 127;
  int stage_v_219_2 = (((stage_v_111_2 ^ 0x2A) * 2) + pub_r001350_12_2) & 127;
  if (stage_v_219_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((pub_r001350_11_1 * 2) + 5) & 63;
  int stage_v_220_2 = ((pub_r001350_11_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001350_19_1) & 127;
  int stage_v_221_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001350_19_2) & 127;
  if (stage_v_221_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((pub_r001350_1_1 * 2) + 38) & 63;
  int stage_v_222_2 = ((pub_r001350_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = (((stage_v_210_1 ^ 0x2A) * 2) + pub_r001350_2_1) & 127;
  int stage_v_223_2 = (((stage_v_210_2 ^ 0x2A) * 2) + pub_r001350_2_2) & 127;
  if (stage_v_223_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = (((stage_v_173_1 ^ 0x2A) * 2) + pub_r001350_11_1) & 127;
  int stage_v_224_2 = (((stage_v_173_2 ^ 0x2A) * 2) + pub_r001350_11_2) & 127;
  if (stage_v_224_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
  }
  if (stage_v_224_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((pub_r001350_0_1 * 2) + 38) & 63;
  int stage_v_225_2 = ((pub_r001350_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = (((stage_v_27_1 ^ 0x2A) * 2) + pub_r001350_18_1) & 127;
  int stage_v_226_2 = (((stage_v_27_2 ^ 0x2A) * 2) + pub_r001350_18_2) & 127;
  if (stage_v_226_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
  }
  if (stage_v_226_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001350_11_1) & 127;
  int stage_v_227_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001350_11_2) & 127;
  if (stage_v_227_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
  }
  if (stage_v_227_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = (((stage_v_153_1 ^ 0x2A) * 2) + pub_r001350_11_1) & 127;
  int stage_v_228_2 = (((stage_v_153_2 ^ 0x2A) * 2) + pub_r001350_11_2) & 127;
  if (stage_v_228_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
  }
  if (stage_v_228_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((pub_r001350_10_1 * 2) + 45) & 63;
  int stage_v_229_2 = ((pub_r001350_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = (((stage_v_219_1 ^ 0x2A) * 2) + pub_r001350_6_1) & 127;
  int stage_v_230_2 = (((stage_v_219_2 ^ 0x2A) * 2) + pub_r001350_6_2) & 127;
  if (stage_v_230_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
  }
  if (stage_v_230_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001350_12_1) & 127;
  int stage_v_231_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001350_12_2) & 127;
  if (stage_v_231_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
  }
  if (stage_v_231_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = (((stage_v_123_1 ^ 0x2A) * 2) + pub_r001350_11_1) & 127;
  int stage_v_232_2 = (((stage_v_123_2 ^ 0x2A) * 2) + pub_r001350_11_2) & 127;
  if (stage_v_232_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
  }
  if (stage_v_232_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = (((stage_v_168_1 ^ 0x2A) * 2) + pub_r001350_18_1) & 127;
  int stage_v_233_2 = (((stage_v_168_2 ^ 0x2A) * 2) + pub_r001350_18_2) & 127;
  if (stage_v_233_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
  }
  if (stage_v_233_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001350_4_1) & 127;
  int stage_v_234_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001350_4_2) & 127;
  if (stage_v_234_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
  }
  if (stage_v_234_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = (((stage_v_100_1 ^ 0x2A) * 2) + pub_r001350_15_1) & 127;
  int stage_v_235_2 = (((stage_v_100_2 ^ 0x2A) * 2) + pub_r001350_15_2) & 127;
  if (stage_v_235_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
  }
  if (stage_v_235_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001350_18_1) & 127;
  int stage_v_236_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001350_18_2) & 127;
  if (stage_v_236_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
  }
  if (stage_v_236_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001350_7_1) & 127;
  int stage_v_237_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001350_7_2) & 127;
  if (stage_v_237_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
  }
  if (stage_v_237_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = (((stage_v_180_1 ^ 0x2A) * 2) + pub_r001350_22_1) & 127;
  int stage_v_238_2 = (((stage_v_180_2 ^ 0x2A) * 2) + pub_r001350_22_2) & 127;
  if (stage_v_238_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_238_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_238_1) + 13) & 255;
  }
  if (stage_v_238_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_238_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_238_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = (((stage_v_154_1 ^ 0x2A) * 2) + pub_r001350_13_1) & 127;
  int stage_v_239_2 = (((stage_v_154_2 ^ 0x2A) * 2) + pub_r001350_13_2) & 127;
  if (stage_v_239_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_239_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_239_1) + 13) & 255;
  }
  if (stage_v_239_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_239_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_239_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = (((stage_v_170_1 ^ 0x2A) * 2) + pub_r001350_22_1) & 127;
  int stage_v_240_2 = (((stage_v_170_2 ^ 0x2A) * 2) + pub_r001350_22_2) & 127;
  if (stage_v_240_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
  }
  if (stage_v_240_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001350_16_1) & 127;
  int stage_v_241_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001350_16_2) & 127;
  if (stage_v_241_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_241_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_241_1) + 13) & 255;
  }
  if (stage_v_241_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_241_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_241_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = (((stage_v_106_1 ^ 0x2A) * 2) + pub_r001350_22_1) & 127;
  int stage_v_242_2 = (((stage_v_106_2 ^ 0x2A) * 2) + pub_r001350_22_2) & 127;
  if (stage_v_242_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_242_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_242_1) + 13) & 255;
  }
  if (stage_v_242_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_242_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_242_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((pub_r001350_12_1 * 2) + 40) & 63;
  int stage_v_243_2 = ((pub_r001350_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((pub_r001350_7_1 * 2) + 12) & 63;
  int stage_v_244_2 = ((pub_r001350_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001350_12_1 * 2) + 50) & 63;
  int stage_v_245_2 = ((pub_r001350_12_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = (((stage_v_188_1 ^ 0x2A) * 2) + pub_r001350_7_1) & 127;
  int stage_v_246_2 = (((stage_v_188_2 ^ 0x2A) * 2) + pub_r001350_7_2) & 127;
  if (stage_v_246_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_246_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_246_1) + 13) & 255;
  }
  if (stage_v_246_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_246_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_246_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = (((stage_v_88_1 ^ 0x2A) * 2) + pub_r001350_16_1) & 127;
  int stage_v_247_2 = (((stage_v_88_2 ^ 0x2A) * 2) + pub_r001350_16_2) & 127;
  if (stage_v_247_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_247_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_247_1) + 13) & 255;
  }
  if (stage_v_247_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_247_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_247_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001350_13_1) & 127;
  int stage_v_248_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001350_13_2) & 127;
  if (stage_v_248_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_248_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_248_1) + 13) & 255;
  }
  if (stage_v_248_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_248_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_248_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001350_4_1) & 127;
  int stage_v_249_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001350_4_2) & 127;
  if (stage_v_249_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_249_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_249_1) + 13) & 255;
  }
  if (stage_v_249_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_249_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_249_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = (((stage_v_186_1 ^ 0x2A) * 2) + pub_r001350_16_1) & 127;
  int stage_v_250_2 = (((stage_v_186_2 ^ 0x2A) * 2) + pub_r001350_16_2) & 127;
  if (stage_v_250_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_250_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_250_1) + 13) & 255;
  }
  if (stage_v_250_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_250_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_250_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001350_8_1 != sec_r001350_8_2);
  __CPROVER_assume(sec_r001350_6_1 != sec_r001350_6_2);
  __CPROVER_assume(sec_r001350_16_1 != sec_r001350_16_2);
  __CPROVER_assume(pub_r001350_1_1 == pub_r001350_1_2);
  __CPROVER_assume(pub_r001350_9_1 == pub_r001350_9_2);
  __CPROVER_assume(sec_r001350_19_1 != sec_r001350_19_2);
  __CPROVER_assume(pub_r001350_2_1 == pub_r001350_2_2);
  __CPROVER_assume(sec_r001350_13_1 != sec_r001350_13_2);
  __CPROVER_assume(pub_r001350_7_1 == pub_r001350_7_2);
  __CPROVER_assume(pub_r001350_13_1 == pub_r001350_13_2);
  __CPROVER_assume(sec_r001350_1_1 != sec_r001350_1_2);
  __CPROVER_assume(pub_r001350_15_1 == pub_r001350_15_2);
  __CPROVER_assume(sec_r001350_10_1 != sec_r001350_10_2);
  __CPROVER_assume(pub_r001350_17_1 == pub_r001350_17_2);
  __CPROVER_assume(pub_r001350_12_1 == pub_r001350_12_2);
  __CPROVER_assume(pub_r001350_19_1 == pub_r001350_19_2);
  __CPROVER_assume(sec_r001350_14_1 != sec_r001350_14_2);
  __CPROVER_assume(pub_r001350_14_1 == pub_r001350_14_2);
  __CPROVER_assume(sec_r001350_7_1 != sec_r001350_7_2);
  __CPROVER_assume(pub_r001350_10_1 == pub_r001350_10_2);
  __CPROVER_assume(sec_r001350_17_1 != sec_r001350_17_2);
  __CPROVER_assume(pub_r001350_18_1 == pub_r001350_18_2);
  __CPROVER_assume(pub_r001350_21_1 == pub_r001350_21_2);
  __CPROVER_assume(pub_r001350_22_1 == pub_r001350_22_2);
  __CPROVER_assume(sec_r001350_5_1 != sec_r001350_5_2);
  __CPROVER_assume(sec_r001350_18_1 != sec_r001350_18_2);
  __CPROVER_assume(pub_r001350_16_1 == pub_r001350_16_2);
  __CPROVER_assume(sec_r001350_9_1 != sec_r001350_9_2);
  __CPROVER_assume(sec_r001350_11_1 != sec_r001350_11_2);
  __CPROVER_assume(pub_r001350_4_1 == pub_r001350_4_2);
  __CPROVER_assume(sec_r001350_15_1 != sec_r001350_15_2);
  __CPROVER_assume(sec_r001350_12_1 != sec_r001350_12_2);
  __CPROVER_assume(pub_r001350_6_1 == pub_r001350_6_2);
  __CPROVER_assume(pub_r001350_11_1 == pub_r001350_11_2);
  __CPROVER_assume(sec_r001350_3_1 != sec_r001350_3_2);
  __CPROVER_assume(sec_r001350_2_1 != sec_r001350_2_2);
  __CPROVER_assume(pub_r001350_8_1 == pub_r001350_8_2);
  __CPROVER_assume(pub_r001350_3_1 == pub_r001350_3_2);
  __CPROVER_assume(pub_r001350_5_1 == pub_r001350_5_2);
  __CPROVER_assume(pub_r001350_0_1 == pub_r001350_0_2);
  __CPROVER_assume(pub_r001350_20_1 == pub_r001350_20_2);
  __CPROVER_assume(sec_r001350_4_1 != sec_r001350_4_2);
  __CPROVER_assume(sec_r001350_0_1 != sec_r001350_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.peak == st_var_2_2.peak);
  assert(st_var_2_1.rms == st_var_2_2.rms);
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
  assert(helper_flow_11_1 == helper_flow_11_2);
  assert(helper_flow_12_1 == helper_flow_12_2);
  assert(helper_flow_13_1 == helper_flow_13_2);
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
}


