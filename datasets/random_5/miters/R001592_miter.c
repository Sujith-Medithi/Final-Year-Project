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
struct Vector3D_R001592_9213_0
{
  int coord_x;
  int pitch;
  short coord_y;
  int heading;
  unsigned char coord_z;
  unsigned char norm_sq;
  int buffer[3];
};
struct StreamBuffer_R001592_9213_1
{
  int watermark;
  unsigned char capacity;
  int tail;
  unsigned char state;
  int head;
  int buffer[3];
};
struct EventLog_R001592_9213_2
{
  int timestamp;
  unsigned char signature;
  short code;
  int severity;
  int buffer[3];
};
struct AudioFrame_R001592_9213_3
{
  unsigned char rms;
  int sample_rate;
  int peak;
  int gain;
  int channels;
  short envelope;
  int buffer[3];
};
union TelemetryField_R001592_9213_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001592_9213_1
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
void fn_R001592_9213_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001592_9213_3 st_1 = {0};
  struct AudioFrame_R001592_9213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int quotient_98_1 = 0;
  int quotient_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_98_1 = ((quotient_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_98_2 = ((quotient_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_98_1) & 127;
    acc_2 = (acc_2 + quotient_98_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_54_1 = local_arr_1[aux_1 % 3];
  int sample_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_54_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_98_1 == quotient_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_54_1 == sample_54_2);
}

int fn_R001592_9213_0(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001592_9213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int quotient_98 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_98 = ((quotient_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_98) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_54 = local_arr[aux % 3];
  acc = (acc + (sample_54 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001592_9213_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001592_9213_3 st_1 = {0};
  struct AudioFrame_R001592_9213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int bound_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_38_1 > 41)
  {
    acc_1 = ((acc_1 + (bound_38_1 * 2)) + 5) & 127;
    aux_1 ^= bound_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_38_2 > 41)
  {
    acc_2 = ((acc_2 + (bound_38_2 * 2)) + 5) & 127;
    aux_2 ^= bound_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_81_1 = local_arr_1[aux_1 % 3];
  int offset_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_81_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_38_1 == bound_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_81_1 == offset_81_2);
}

int fn_R001592_9213_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001592_9213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int bound_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_38 > 41)
  {
    acc = ((acc + (bound_38 * 2)) + 5) & 127;
    aux ^= bound_38 & 15;
  }
  else
  {
    acc = ((acc - bound_38) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int offset_81 = local_arr[aux % 3];
  acc = (acc + (offset_81 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001592_9213_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001592_9213_0 st_1 = {0};
  struct Vector3D_R001592_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_56_1 = local_arr_1[aux_1 % 3];
  int mask_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_56_2 * 2)) & 127;
  int segment_40_1 = 0;
  int segment_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_40_1 = ((segment_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_40_2 = ((segment_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_40_1) & 127;
    acc_2 = (acc_2 + segment_40_2) & 127;
  }

  int quantum_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_10_1)
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

  switch (quantum_10_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_56_1 == mask_56_2);
  assert(segment_40_1 == segment_40_2);
  assert(quantum_10_1 == quantum_10_2);
}

int fn_R001592_9213_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001592_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int mask_56 = local_arr[aux % 3];
  acc = (acc + (mask_56 * 2)) & 127;
  int segment_40 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_40 = ((segment_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_40) & 127;
  }

  int quantum_10 = (aux + st.buffer[1]) & 3;
  switch (quantum_10)
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

void fn_R001592_9213_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001592_9213_3 st_1 = {0};
  struct AudioFrame_R001592_9213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_43_1 = 0;
  int factor_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_43_1 = ((factor_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_43_2 = ((factor_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_43_1) & 127;
    acc_2 = (acc_2 + factor_43_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_43_1 == factor_43_2);
}

int fn_R001592_9213_3(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001592_9213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_43 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_43 = ((factor_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_43) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001592_9213_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001592_9213_3 st_1 = {0};
  struct AudioFrame_R001592_9213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_75_1)
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

  switch (delta_75_2)
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
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_75_1 == delta_75_2);
}

int fn_R001592_9213_4(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001592_9213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_75 = (aux + st.buffer[1]) & 3;
  switch (delta_75)
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

void fn_R001592_9213_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001592_9213_1 st_1 = {0};
  struct StreamBuffer_R001592_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int bound_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_43_1) & 63;
  aux_2 = (aux_2 + bound_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_73_1 = 0;
  int damping_73_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_73_1 = ((damping_73_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_73_2 = ((damping_73_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_73_1) & 127;
    acc_2 = (acc_2 + damping_73_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_20_1 = local_arr_1[aux_1 % 3];
  int checksum_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_20_2 * 2)) & 127;
  int quotient_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_93_1 > 20)
  {
    acc_1 = ((acc_1 + (quotient_93_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_93_2 > 20)
  {
    acc_2 = ((acc_2 + (quotient_93_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_93_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_43_1 == bound_43_2);
  assert(damping_73_1 == damping_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_20_1 == checksum_20_2);
  assert(quotient_93_1 == quotient_93_2);
}

int fn_R001592_9213_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001592_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int bound_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_43) & 63;
  acc ^= aux;
  int damping_73 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_73 = ((damping_73 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_73) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int checksum_20 = local_arr[aux % 3];
  acc = (acc + (checksum_20 * 2)) & 127;
  int quotient_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_93 > 20)
  {
    acc = ((acc + (quotient_93 * 2)) + 5) & 127;
    aux ^= quotient_93 & 15;
  }
  else
  {
    acc = ((acc - quotient_93) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001592_9213_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001592_9213_3 st_1 = {0};
  struct AudioFrame_R001592_9213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int delta_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_89_1) & 63;
  aux_2 = (aux_2 + delta_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_47_1 = local_arr_1[aux_1 % 3];
  int metric_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_47_2 * 2)) & 127;
  int sample_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_80_1)
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

  switch (sample_80_2)
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_89_1 == delta_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_47_1 == metric_47_2);
  assert(sample_80_1 == sample_80_2);
}

int fn_R001592_9213_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001592_9213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int delta_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_89) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int metric_47 = local_arr[aux % 3];
  acc = (acc + (metric_47 * 2)) & 127;
  int sample_80 = (aux + st.buffer[1]) & 3;
  switch (sample_80)
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

void fn_R001592_9213_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001592_9213_0 st_1 = {0};
  struct Vector3D_R001592_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_32_1 = local_arr_1[aux_1 % 3];
  int sample_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_32_2 * 2)) & 127;
  int weight_38_1 = 0;
  int weight_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_38_1 = ((weight_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_38_2 = ((weight_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_38_1) & 127;
    acc_2 = (acc_2 + weight_38_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_32_1 == sample_32_2);
  assert(weight_38_1 == weight_38_2);
}

int fn_R001592_9213_7(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001592_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int sample_32 = local_arr[aux % 3];
  acc = (acc + (sample_32 * 2)) & 127;
  int weight_38 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_38 = ((weight_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_38) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001592_9213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001592_9213_0 st_1 = {0};
  struct Vector3D_R001592_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_35_1 = local_arr_1[aux_1 % 3];
  int tracker_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_35_2 * 2)) & 127;
  int scale_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_34_1 > 11)
  {
    acc_1 = ((acc_1 + (scale_34_1 * 2)) + 5) & 127;
    aux_1 ^= scale_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_34_2 > 11)
  {
    acc_2 = ((acc_2 + (scale_34_2 * 2)) + 5) & 127;
    aux_2 ^= scale_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_34_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_71_1) & 63;
  aux_2 = (aux_2 + tracker_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_35_1 == tracker_35_2);
  assert(scale_34_1 == scale_34_2);
  assert(tracker_71_1 == tracker_71_2);
}

int fn_R001592_9213_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001592_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int tracker_35 = local_arr[aux % 3];
  acc = (acc + (tracker_35 * 2)) & 127;
  int scale_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_34 > 11)
  {
    acc = ((acc + (scale_34 * 2)) + 5) & 127;
    aux ^= scale_34 & 15;
  }
  else
  {
    acc = ((acc - scale_34) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_71) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001592_9213_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001592_9213_2 st_1 = {0};
  struct EventLog_R001592_9213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int vector_37_1 = 0;
  int vector_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_37_1 = ((vector_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_37_2 = ((vector_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_37_1) & 127;
    acc_2 = (acc_2 + vector_37_2) & 127;
  }

  int accumulator_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_71_1)
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

  switch (accumulator_71_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_37_1 == vector_37_2);
  assert(accumulator_71_1 == accumulator_71_2);
}

int fn_R001592_9213_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001592_9213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int vector_37 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_37 = ((vector_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_37) & 127;
  }

  int accumulator_71 = (aux + st.buffer[1]) & 3;
  switch (accumulator_71)
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

void fn_R001592_9213_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001592_9213_1 st_1 = {0};
  struct StreamBuffer_R001592_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_13_1 = 0;
  int cursor_13_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_13_1 = ((cursor_13_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_13_2 = ((cursor_13_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_13_1) & 127;
    acc_2 = (acc_2 + cursor_13_2) & 127;
  }

  int stride_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_80_1 > 16)
  {
    acc_1 = ((acc_1 + (stride_80_1 * 2)) + 5) & 127;
    aux_1 ^= stride_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_80_2 > 16)
  {
    acc_2 = ((acc_2 + (stride_80_2 * 2)) + 5) & 127;
    aux_2 ^= stride_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_80_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_13_1 == cursor_13_2);
  assert(stride_80_1 == stride_80_2);
}

int fn_R001592_9213_10(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001592_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_13 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_13 = ((cursor_13 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_13) & 127;
  }

  int stride_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_80 > 16)
  {
    acc = ((acc + (stride_80 * 2)) + 5) & 127;
    aux ^= stride_80 & 15;
  }
  else
  {
    acc = ((acc - stride_80) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001592_9213_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001592_9213_0 st_1 = {0};
  struct Vector3D_R001592_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int delta_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_96_1) & 63;
  aux_2 = (aux_2 + delta_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_81_1 = 0;
  int scale_81_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_81_1 = ((scale_81_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_81_2 = ((scale_81_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_81_1) & 127;
    acc_2 = (acc_2 + scale_81_2) & 127;
  }

  int anchor_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_78_1)
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

  switch (anchor_78_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_96_1 == delta_96_2);
  assert(scale_81_1 == scale_81_2);
  assert(anchor_78_1 == anchor_78_2);
}

int fn_R001592_9213_11(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001592_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int delta_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_96) & 63;
  acc ^= aux;
  int scale_81 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_81 = ((scale_81 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_81) & 127;
  }

  int anchor_78 = (aux + st.buffer[1]) & 3;
  switch (anchor_78)
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

void fn_R001592_9213_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001592_9213_0 st_1 = {0};
  struct Vector3D_R001592_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_57_1 = local_arr_1[aux_1 % 3];
  int quotient_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_57_2 * 2)) & 127;
  int scale_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_92_1)
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

  switch (scale_92_2)
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

  int mask_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_43_1) & 63;
  aux_2 = (aux_2 + mask_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_57_1 == quotient_57_2);
  assert(scale_92_1 == scale_92_2);
  assert(mask_43_1 == mask_43_2);
}

int fn_R001592_9213_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001592_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int quotient_57 = local_arr[aux % 3];
  acc = (acc + (quotient_57 * 2)) & 127;
  int scale_92 = (aux + st.buffer[1]) & 3;
  switch (scale_92)
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

  int mask_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_43) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001592_9213_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001592_9213_3 st_1 = {0};
  struct AudioFrame_R001592_9213_3 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_67_1 = local_arr_1[aux_1 % 3];
  int stride_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_67_2 * 2)) & 127;
  int mask_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_82_1 > 47)
  {
    acc_1 = ((acc_1 + (mask_82_1 * 2)) + 5) & 127;
    aux_1 ^= mask_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_82_2 > 47)
  {
    acc_2 = ((acc_2 + (mask_82_2 * 2)) + 5) & 127;
    aux_2 ^= mask_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_82_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_67_1 == stride_67_2);
  assert(mask_82_1 == mask_82_2);
}

int fn_R001592_9213_13(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001592_9213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int stride_67 = local_arr[aux % 3];
  acc = (acc + (stride_67 * 2)) & 127;
  int mask_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_82 > 47)
  {
    acc = ((acc + (mask_82 * 2)) + 5) & 127;
    aux ^= mask_82 & 15;
  }
  else
  {
    acc = ((acc - mask_82) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001592_9213_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001592_9213_0 st_1 = {0};
  struct Vector3D_R001592_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int threshold_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_38_1)
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

  switch (threshold_38_2)
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

  int pivot_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_21_1) & 63;
  aux_2 = (aux_2 + pivot_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_38_1 == threshold_38_2);
  assert(pivot_21_1 == pivot_21_2);
}

int fn_R001592_9213_14(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001592_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int threshold_38 = (aux + st.buffer[1]) & 3;
  switch (threshold_38)
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

  int pivot_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_21) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001592_9213_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001592_9213_2 st_1 = {0};
  struct EventLog_R001592_9213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int bound_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_51_1)
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

  switch (bound_51_2)
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

  int threshold_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_33_1) & 63;
  aux_2 = (aux_2 + threshold_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_51_1 == bound_51_2);
  assert(threshold_33_1 == threshold_33_2);
}

int fn_R001592_9213_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001592_9213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int bound_51 = (aux + st.buffer[1]) & 3;
  switch (bound_51)
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

  int threshold_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_33) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001592_9213_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001592_9213_3 st_1 = {0};
  struct AudioFrame_R001592_9213_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int pivot_78_1 = 0;
  int pivot_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_78_1 = ((pivot_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_78_2 = ((pivot_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_78_1) & 127;
    acc_2 = (acc_2 + pivot_78_2) & 127;
  }

  int sample_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_61_1 > 32)
  {
    acc_1 = ((acc_1 + (sample_61_1 * 2)) + 5) & 127;
    aux_1 ^= sample_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_61_2 > 32)
  {
    acc_2 = ((acc_2 + (sample_61_2 * 2)) + 5) & 127;
    aux_2 ^= sample_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_61_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_26_1)
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

  switch (quantum_26_2)
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_78_1 == pivot_78_2);
  assert(sample_61_1 == sample_61_2);
  assert(quantum_26_1 == quantum_26_2);
}

int fn_R001592_9213_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001592_9213_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int pivot_78 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_78 = ((pivot_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_78) & 127;
  }

  int sample_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_61 > 32)
  {
    acc = ((acc + (sample_61 * 2)) + 5) & 127;
    aux ^= sample_61 & 15;
  }
  else
  {
    acc = ((acc - sample_61) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_26 = (aux + st.buffer[1]) & 3;
  switch (quantum_26)
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

void fn_R001592_9213_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001592_9213_2 st_1 = {0};
  struct EventLog_R001592_9213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_64_1 = 0;
  int stride_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_64_1 = ((stride_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_64_2 = ((stride_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_64_1) & 127;
    acc_2 = (acc_2 + stride_64_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_64_1 == stride_64_2);
}

int fn_R001592_9213_17(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001592_9213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_64 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_64 = ((stride_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_64) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001592_9213_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001592_9213_1 st_1 = {0};
  struct StreamBuffer_R001592_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int residue_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_71_1)
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

  switch (residue_71_2)
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

  int index_reg_55_1 = 0;
  int index_reg_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_55_1 = ((index_reg_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_55_2 = ((index_reg_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_55_1) & 127;
    acc_2 = (acc_2 + index_reg_55_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_70_1 = local_arr_1[aux_1 % 3];
  int sample_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_70_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_71_1 == residue_71_2);
  assert(index_reg_55_1 == index_reg_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_70_1 == sample_70_2);
}

int fn_R001592_9213_18(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001592_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int residue_71 = (aux + st.buffer[1]) & 3;
  switch (residue_71)
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

  int index_reg_55 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_55 = ((index_reg_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_55) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int sample_70 = local_arr[aux % 3];
  acc = (acc + (sample_70 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001592_0_1;
  int sec_r001592_0_2;
  int sec_r001592_1_1;
  int sec_r001592_1_2;
  int sec_r001592_2_1;
  int sec_r001592_2_2;
  int sec_r001592_3_1;
  int sec_r001592_3_2;
  int sec_r001592_4_1;
  int sec_r001592_4_2;
  int sec_r001592_5_1;
  int sec_r001592_5_2;
  int sec_r001592_6_1;
  int sec_r001592_6_2;
  int sec_r001592_7_1;
  int sec_r001592_7_2;
  int sec_r001592_8_1;
  int sec_r001592_8_2;
  int sec_r001592_9_1;
  int sec_r001592_9_2;
  int sec_r001592_10_1;
  int sec_r001592_10_2;
  int sec_r001592_11_1;
  int sec_r001592_11_2;
  int sec_r001592_12_1;
  int sec_r001592_12_2;
  int sec_r001592_13_1;
  int sec_r001592_13_2;
  int sec_r001592_14_1;
  int sec_r001592_14_2;
  int sec_r001592_15_1;
  int sec_r001592_15_2;
  int sec_r001592_16_1;
  int sec_r001592_16_2;
  int sec_r001592_17_1;
  int sec_r001592_17_2;
  int sec_r001592_18_1;
  int sec_r001592_18_2;
  int sec_r001592_19_1;
  int sec_r001592_19_2;
  int sec_r001592_20_1;
  int sec_r001592_20_2;
  int sec_r001592_21_1;
  int sec_r001592_21_2;
  int sec_r001592_22_1;
  int sec_r001592_22_2;
  int pub_r001592_0_1;
  int pub_r001592_0_2;
  int pub_r001592_1_1;
  int pub_r001592_1_2;
  int pub_r001592_2_1;
  int pub_r001592_2_2;
  int pub_r001592_3_1;
  int pub_r001592_3_2;
  int pub_r001592_4_1;
  int pub_r001592_4_2;
  int pub_r001592_5_1;
  int pub_r001592_5_2;
  int pub_r001592_6_1;
  int pub_r001592_6_2;
  int pub_r001592_7_1;
  int pub_r001592_7_2;
  int pub_r001592_8_1;
  int pub_r001592_8_2;
  int pub_r001592_9_1;
  int pub_r001592_9_2;
  int pub_r001592_10_1;
  int pub_r001592_10_2;
  int pub_r001592_11_1;
  int pub_r001592_11_2;
  int pub_r001592_12_1;
  int pub_r001592_12_2;
  int pub_r001592_13_1;
  int pub_r001592_13_2;
  int pub_r001592_14_1;
  int pub_r001592_14_2;
  int pub_r001592_15_1;
  int pub_r001592_15_2;
  int pub_r001592_16_1;
  int pub_r001592_16_2;
  int pub_r001592_17_1;
  int pub_r001592_17_2;
  int pub_r001592_18_1;
  int pub_r001592_18_2;
  int pub_r001592_19_1;
  int pub_r001592_19_2;
  int pub_r001592_20_1;
  int pub_r001592_20_2;
  int pub_r001592_21_1;
  int pub_r001592_21_2;
  int pub_r001592_22_1;
  int pub_r001592_22_2;
  int pub_r001592_23_1;
  int pub_r001592_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001592_0_1 >= (-100)) && (pub_r001592_0_1 <= 100));
  __CPROVER_assume((pub_r001592_0_2 >= (-100)) && (pub_r001592_0_2 <= 100));
  __CPROVER_assume((pub_r001592_1_1 >= (-100)) && (pub_r001592_1_1 <= 100));
  __CPROVER_assume((pub_r001592_1_2 >= (-100)) && (pub_r001592_1_2 <= 100));
  __CPROVER_assume((pub_r001592_2_1 >= (-100)) && (pub_r001592_2_1 <= 100));
  __CPROVER_assume((pub_r001592_2_2 >= (-100)) && (pub_r001592_2_2 <= 100));
  __CPROVER_assume((pub_r001592_3_1 >= (-100)) && (pub_r001592_3_1 <= 100));
  __CPROVER_assume((pub_r001592_3_2 >= (-100)) && (pub_r001592_3_2 <= 100));
  __CPROVER_assume((pub_r001592_4_1 >= (-100)) && (pub_r001592_4_1 <= 100));
  __CPROVER_assume((pub_r001592_4_2 >= (-100)) && (pub_r001592_4_2 <= 100));
  __CPROVER_assume((pub_r001592_5_1 >= (-100)) && (pub_r001592_5_1 <= 100));
  __CPROVER_assume((pub_r001592_5_2 >= (-100)) && (pub_r001592_5_2 <= 100));
  __CPROVER_assume((pub_r001592_6_1 >= (-100)) && (pub_r001592_6_1 <= 100));
  __CPROVER_assume((pub_r001592_6_2 >= (-100)) && (pub_r001592_6_2 <= 100));
  __CPROVER_assume((pub_r001592_7_1 >= (-100)) && (pub_r001592_7_1 <= 100));
  __CPROVER_assume((pub_r001592_7_2 >= (-100)) && (pub_r001592_7_2 <= 100));
  __CPROVER_assume((pub_r001592_8_1 >= (-100)) && (pub_r001592_8_1 <= 100));
  __CPROVER_assume((pub_r001592_8_2 >= (-100)) && (pub_r001592_8_2 <= 100));
  __CPROVER_assume((pub_r001592_9_1 >= (-100)) && (pub_r001592_9_1 <= 100));
  __CPROVER_assume((pub_r001592_9_2 >= (-100)) && (pub_r001592_9_2 <= 100));
  __CPROVER_assume((pub_r001592_10_1 >= (-100)) && (pub_r001592_10_1 <= 100));
  __CPROVER_assume((pub_r001592_10_2 >= (-100)) && (pub_r001592_10_2 <= 100));
  __CPROVER_assume((pub_r001592_11_1 >= (-100)) && (pub_r001592_11_1 <= 100));
  __CPROVER_assume((pub_r001592_11_2 >= (-100)) && (pub_r001592_11_2 <= 100));
  __CPROVER_assume((pub_r001592_12_1 >= (-100)) && (pub_r001592_12_1 <= 100));
  __CPROVER_assume((pub_r001592_12_2 >= (-100)) && (pub_r001592_12_2 <= 100));
  __CPROVER_assume((pub_r001592_13_1 >= (-100)) && (pub_r001592_13_1 <= 100));
  __CPROVER_assume((pub_r001592_13_2 >= (-100)) && (pub_r001592_13_2 <= 100));
  __CPROVER_assume((pub_r001592_14_1 >= (-100)) && (pub_r001592_14_1 <= 100));
  __CPROVER_assume((pub_r001592_14_2 >= (-100)) && (pub_r001592_14_2 <= 100));
  __CPROVER_assume((pub_r001592_15_1 >= (-100)) && (pub_r001592_15_1 <= 100));
  __CPROVER_assume((pub_r001592_15_2 >= (-100)) && (pub_r001592_15_2 <= 100));
  __CPROVER_assume((pub_r001592_16_1 >= (-100)) && (pub_r001592_16_1 <= 100));
  __CPROVER_assume((pub_r001592_16_2 >= (-100)) && (pub_r001592_16_2 <= 100));
  __CPROVER_assume((pub_r001592_17_1 >= (-100)) && (pub_r001592_17_1 <= 100));
  __CPROVER_assume((pub_r001592_17_2 >= (-100)) && (pub_r001592_17_2 <= 100));
  __CPROVER_assume((pub_r001592_18_1 >= (-100)) && (pub_r001592_18_1 <= 100));
  __CPROVER_assume((pub_r001592_18_2 >= (-100)) && (pub_r001592_18_2 <= 100));
  __CPROVER_assume((pub_r001592_19_1 >= (-100)) && (pub_r001592_19_1 <= 100));
  __CPROVER_assume((pub_r001592_19_2 >= (-100)) && (pub_r001592_19_2 <= 100));
  __CPROVER_assume((pub_r001592_20_1 >= (-100)) && (pub_r001592_20_1 <= 100));
  __CPROVER_assume((pub_r001592_20_2 >= (-100)) && (pub_r001592_20_2 <= 100));
  __CPROVER_assume((pub_r001592_21_1 >= (-100)) && (pub_r001592_21_1 <= 100));
  __CPROVER_assume((pub_r001592_21_2 >= (-100)) && (pub_r001592_21_2 <= 100));
  __CPROVER_assume((pub_r001592_22_1 >= (-100)) && (pub_r001592_22_1 <= 100));
  __CPROVER_assume((pub_r001592_22_2 >= (-100)) && (pub_r001592_22_2 <= 100));
  __CPROVER_assume((pub_r001592_23_1 >= (-100)) && (pub_r001592_23_1 <= 100));
  __CPROVER_assume((pub_r001592_23_2 >= (-100)) && (pub_r001592_23_2 <= 100));
  __CPROVER_assume((sec_r001592_0_1 >= 0) && (sec_r001592_0_1 <= 255));
  __CPROVER_assume((sec_r001592_0_2 >= 0) && (sec_r001592_0_2 <= 255));
  __CPROVER_assume((sec_r001592_1_1 >= 0) && (sec_r001592_1_1 <= 255));
  __CPROVER_assume((sec_r001592_1_2 >= 0) && (sec_r001592_1_2 <= 255));
  __CPROVER_assume((sec_r001592_2_1 >= 0) && (sec_r001592_2_1 <= 255));
  __CPROVER_assume((sec_r001592_2_2 >= 0) && (sec_r001592_2_2 <= 255));
  __CPROVER_assume((sec_r001592_3_1 >= 0) && (sec_r001592_3_1 <= 255));
  __CPROVER_assume((sec_r001592_3_2 >= 0) && (sec_r001592_3_2 <= 255));
  __CPROVER_assume((sec_r001592_4_1 >= 0) && (sec_r001592_4_1 <= 255));
  __CPROVER_assume((sec_r001592_4_2 >= 0) && (sec_r001592_4_2 <= 255));
  __CPROVER_assume((sec_r001592_5_1 >= 0) && (sec_r001592_5_1 <= 255));
  __CPROVER_assume((sec_r001592_5_2 >= 0) && (sec_r001592_5_2 <= 255));
  __CPROVER_assume((sec_r001592_6_1 >= 0) && (sec_r001592_6_1 <= 255));
  __CPROVER_assume((sec_r001592_6_2 >= 0) && (sec_r001592_6_2 <= 255));
  __CPROVER_assume((sec_r001592_7_1 >= 0) && (sec_r001592_7_1 <= 255));
  __CPROVER_assume((sec_r001592_7_2 >= 0) && (sec_r001592_7_2 <= 255));
  __CPROVER_assume((sec_r001592_8_1 >= 0) && (sec_r001592_8_1 <= 255));
  __CPROVER_assume((sec_r001592_8_2 >= 0) && (sec_r001592_8_2 <= 255));
  __CPROVER_assume((sec_r001592_9_1 >= 0) && (sec_r001592_9_1 <= 255));
  __CPROVER_assume((sec_r001592_9_2 >= 0) && (sec_r001592_9_2 <= 255));
  __CPROVER_assume((sec_r001592_10_1 >= 0) && (sec_r001592_10_1 <= 255));
  __CPROVER_assume((sec_r001592_10_2 >= 0) && (sec_r001592_10_2 <= 255));
  __CPROVER_assume((sec_r001592_11_1 >= 0) && (sec_r001592_11_1 <= 255));
  __CPROVER_assume((sec_r001592_11_2 >= 0) && (sec_r001592_11_2 <= 255));
  __CPROVER_assume((sec_r001592_12_1 >= 0) && (sec_r001592_12_1 <= 255));
  __CPROVER_assume((sec_r001592_12_2 >= 0) && (sec_r001592_12_2 <= 255));
  __CPROVER_assume((sec_r001592_13_1 >= 0) && (sec_r001592_13_1 <= 255));
  __CPROVER_assume((sec_r001592_13_2 >= 0) && (sec_r001592_13_2 <= 255));
  __CPROVER_assume((sec_r001592_14_1 >= 0) && (sec_r001592_14_1 <= 255));
  __CPROVER_assume((sec_r001592_14_2 >= 0) && (sec_r001592_14_2 <= 255));
  __CPROVER_assume((sec_r001592_15_1 >= 0) && (sec_r001592_15_1 <= 255));
  __CPROVER_assume((sec_r001592_15_2 >= 0) && (sec_r001592_15_2 <= 255));
  __CPROVER_assume((sec_r001592_16_1 >= 0) && (sec_r001592_16_1 <= 255));
  __CPROVER_assume((sec_r001592_16_2 >= 0) && (sec_r001592_16_2 <= 255));
  __CPROVER_assume((sec_r001592_17_1 >= 0) && (sec_r001592_17_1 <= 255));
  __CPROVER_assume((sec_r001592_17_2 >= 0) && (sec_r001592_17_2 <= 255));
  __CPROVER_assume((sec_r001592_18_1 >= 0) && (sec_r001592_18_1 <= 255));
  __CPROVER_assume((sec_r001592_18_2 >= 0) && (sec_r001592_18_2 <= 255));
  __CPROVER_assume((sec_r001592_19_1 >= 0) && (sec_r001592_19_1 <= 255));
  __CPROVER_assume((sec_r001592_19_2 >= 0) && (sec_r001592_19_2 <= 255));
  __CPROVER_assume((sec_r001592_20_1 >= 0) && (sec_r001592_20_1 <= 255));
  __CPROVER_assume((sec_r001592_20_2 >= 0) && (sec_r001592_20_2 <= 255));
  __CPROVER_assume((sec_r001592_21_1 >= 0) && (sec_r001592_21_1 <= 255));
  __CPROVER_assume((sec_r001592_21_2 >= 0) && (sec_r001592_21_2 <= 255));
  __CPROVER_assume((sec_r001592_22_1 >= 0) && (sec_r001592_22_1 <= 255));
  __CPROVER_assume((sec_r001592_22_2 >= 0) && (sec_r001592_22_2 <= 255));
  struct Vector3D_R001592_9213_0 st_var_0_1 = {0};
  struct Vector3D_R001592_9213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001592_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001592_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001592_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001592_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001592_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001592_0_2 + 7) & 15;
  struct StreamBuffer_R001592_9213_1 st_var_1_1 = {0};
  struct StreamBuffer_R001592_9213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001592_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001592_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001592_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001592_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001592_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001592_0_2 + 9) & 15;
  struct EventLog_R001592_9213_2 st_var_2_1 = {0};
  struct EventLog_R001592_9213_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001592_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001592_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001592_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001592_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001592_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001592_0_2 + 11) & 15;
  struct AudioFrame_R001592_9213_3 st_var_3_1 = {0};
  struct AudioFrame_R001592_9213_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001592_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001592_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001592_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001592_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001592_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001592_0_2 + 13) & 15;
  union TelemetryField_R001592_9213_0 u_var_1;
  union TelemetryField_R001592_9213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001592_9213_0(sec_r001592_0_1, sec_r001592_1_1, pub_r001592_2_1);
  int helper_flow_0_2 = fn_R001592_9213_0(sec_r001592_0_2, sec_r001592_1_2, pub_r001592_2_2);
  fn_R001592_9213_0_2(sec_r001592_0_1, sec_r001592_1_1, pub_r001592_2_1, sec_r001592_0_2, sec_r001592_1_2, pub_r001592_2_2);
  int helper_flow_1_1 = fn_R001592_9213_1(sec_r001592_1_1, sec_r001592_2_1, pub_r001592_3_1, pub_r001592_4_1, pub_r001592_5_1);
  int helper_flow_1_2 = fn_R001592_9213_1(sec_r001592_1_2, sec_r001592_2_2, pub_r001592_3_2, pub_r001592_4_2, pub_r001592_5_2);
  fn_R001592_9213_1_2(sec_r001592_1_1, sec_r001592_2_1, pub_r001592_3_1, pub_r001592_4_1, pub_r001592_5_1, sec_r001592_1_2, sec_r001592_2_2, pub_r001592_3_2, pub_r001592_4_2, pub_r001592_5_2);
  int helper_flow_2_1 = fn_R001592_9213_2(sec_r001592_2_1, pub_r001592_3_1, pub_r001592_4_1, pub_r001592_5_1);
  int helper_flow_2_2 = fn_R001592_9213_2(sec_r001592_2_2, pub_r001592_3_2, pub_r001592_4_2, pub_r001592_5_2);
  fn_R001592_9213_2_2(sec_r001592_2_1, pub_r001592_3_1, pub_r001592_4_1, pub_r001592_5_1, sec_r001592_2_2, pub_r001592_3_2, pub_r001592_4_2, pub_r001592_5_2);
  int stage_v_0_1 = ((pub_r001592_18_1 * 2) + 11) & 63;
  int stage_v_0_2 = ((pub_r001592_18_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001592_7_1 * 2) + 24) & 63;
  int stage_v_1_2 = ((pub_r001592_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001592_20_1 * 2) + 12) & 63;
  int stage_v_2_2 = ((pub_r001592_20_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001592_21_1 * 2) + 35) & 63;
  int stage_v_3_2 = ((pub_r001592_21_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (((sec_r001592_21_1 * 3) + pub_r001592_1_1) + 8) & 127;
  int stage_v_4_2 = (((sec_r001592_21_2 * 3) + pub_r001592_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = ((pub_r001592_3_1 * 2) + 27) & 63;
  int stage_v_5_2 = ((pub_r001592_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001592_4_1 * 2) + 19) & 63;
  int stage_v_6_2 = ((pub_r001592_4_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((helper_flow_0_1 * 3) + pub_r001592_14_1) + 26) & 127;
  int stage_v_7_2 = (((helper_flow_0_2 * 3) + pub_r001592_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = (((sec_r001592_8_1 * 3) + pub_r001592_8_1) + 42) & 127;
  int stage_v_8_2 = (((sec_r001592_8_2 * 3) + pub_r001592_8_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = ((pub_r001592_12_1 * 2) + 39) & 63;
  int stage_v_9_2 = ((pub_r001592_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((sec_r001592_16_1 * 3) + pub_r001592_21_1) + 18) & 127;
  int stage_v_10_2 = (((sec_r001592_16_2 * 3) + pub_r001592_21_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = ((pub_r001592_16_1 * 2) + 21) & 63;
  int stage_v_11_2 = ((pub_r001592_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001592_10_1 * 2) + 23) & 63;
  int stage_v_12_2 = ((pub_r001592_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001592_11_1 * 2) + 33) & 63;
  int stage_v_13_2 = ((pub_r001592_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001592_2_1 * 2) + 22) & 63;
  int stage_v_14_2 = ((pub_r001592_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001592_5_1 * 2) + 37) & 63;
  int stage_v_15_2 = ((pub_r001592_5_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((sec_r001592_9_1 * 3) + pub_r001592_10_1) + 25) & 127;
  int stage_v_16_2 = (((sec_r001592_9_2 * 3) + pub_r001592_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = ((pub_r001592_19_1 * 2) + 50) & 63;
  int stage_v_17_2 = ((pub_r001592_19_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001592_20_1 * 2) + 45) & 63;
  int stage_v_18_2 = ((pub_r001592_20_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (((sec_r001592_6_1 * 3) + pub_r001592_14_1) + 29) & 127;
  int stage_v_19_2 = (((sec_r001592_6_2 * 3) + pub_r001592_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = ((pub_r001592_18_1 * 2) + 47) & 63;
  int stage_v_20_2 = ((pub_r001592_18_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001592_10_1 * 2) + 29) & 63;
  int stage_v_21_2 = ((pub_r001592_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = (((sec_r001592_15_1 * 3) + pub_r001592_0_1) + 34) & 127;
  int stage_v_22_2 = (((sec_r001592_15_2 * 3) + pub_r001592_0_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = ((pub_r001592_15_1 * 2) + 12) & 63;
  int stage_v_23_2 = ((pub_r001592_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (((sec_r001592_20_1 * 3) + pub_r001592_3_1) + 4) & 127;
  int stage_v_24_2 = (((sec_r001592_20_2 * 3) + pub_r001592_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = ((pub_r001592_14_1 * 2) + 46) & 63;
  int stage_v_25_2 = ((pub_r001592_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (((helper_flow_1_1 * 3) + pub_r001592_13_1) + 17) & 127;
  int stage_v_26_2 = (((helper_flow_1_2 * 3) + pub_r001592_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = ((pub_r001592_12_1 * 2) + 9) & 63;
  int stage_v_27_2 = ((pub_r001592_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((stage_v_7_1 * 3) + pub_r001592_12_1) + 28) & 127;
  int stage_v_28_2 = (((stage_v_7_2 * 3) + pub_r001592_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = ((pub_r001592_9_1 * 2) + 22) & 63;
  int stage_v_29_2 = ((pub_r001592_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001592_17_1 * 2) + 45) & 63;
  int stage_v_30_2 = ((pub_r001592_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = (((sec_r001592_4_1 * 3) + pub_r001592_16_1) + 11) & 127;
  int stage_v_31_2 = (((sec_r001592_4_2 * 3) + pub_r001592_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = ((pub_r001592_23_1 * 2) + 9) & 63;
  int stage_v_32_2 = ((pub_r001592_23_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001592_21_1 * 2) + 45) & 63;
  int stage_v_33_2 = ((pub_r001592_21_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001592_6_1 * 2) + 23) & 63;
  int stage_v_34_2 = ((pub_r001592_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = (((sec_r001592_7_1 * 3) + pub_r001592_10_1) + 18) & 127;
  int stage_v_35_2 = (((sec_r001592_7_2 * 3) + pub_r001592_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_35_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_35_2 * 2)) & 255;
  int stage_v_36_1 = ((pub_r001592_8_1 * 2) + 43) & 63;
  int stage_v_36_2 = ((pub_r001592_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (((sec_r001592_20_1 * 3) + pub_r001592_23_1) + 24) & 127;
  int stage_v_37_2 = (((sec_r001592_20_2 * 3) + pub_r001592_23_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = ((pub_r001592_9_1 * 2) + 6) & 63;
  int stage_v_38_2 = ((pub_r001592_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001592_8_1 * 2) + 6) & 63;
  int stage_v_39_2 = ((pub_r001592_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001592_0_1 * 2) + 28) & 63;
  int stage_v_40_2 = ((pub_r001592_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001592_10_1 * 2) + 43) & 63;
  int stage_v_41_2 = ((pub_r001592_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001592_5_1 * 2) + 35) & 63;
  int stage_v_42_2 = ((pub_r001592_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001592_9_1 * 2) + 38) & 63;
  int stage_v_43_2 = ((pub_r001592_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001592_22_1 * 2) + 12) & 63;
  int stage_v_44_2 = ((pub_r001592_22_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001592_11_1 * 2) + 33) & 63;
  int stage_v_45_2 = ((pub_r001592_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001592_23_1 * 2) + 27) & 63;
  int stage_v_46_2 = ((pub_r001592_23_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (((sec_r001592_3_1 * 3) + pub_r001592_11_1) + 8) & 127;
  int stage_v_47_2 = (((sec_r001592_3_2 * 3) + pub_r001592_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = ((pub_r001592_17_1 * 2) + 29) & 63;
  int stage_v_48_2 = ((pub_r001592_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((helper_flow_1_1 * 3) + pub_r001592_15_1) + 9) & 127;
  int stage_v_49_2 = (((helper_flow_1_2 * 3) + pub_r001592_15_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = (((sec_r001592_8_1 * 3) + pub_r001592_23_1) + 12) & 127;
  int stage_v_50_2 = (((sec_r001592_8_2 * 3) + pub_r001592_23_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = ((pub_r001592_1_1 * 2) + 40) & 63;
  int stage_v_51_2 = ((pub_r001592_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001592_21_1 * 2) + 37) & 63;
  int stage_v_52_2 = ((pub_r001592_21_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (((sec_r001592_6_1 * 3) + pub_r001592_6_1) + 39) & 127;
  int stage_v_53_2 = (((sec_r001592_6_2 * 3) + pub_r001592_6_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = ((pub_r001592_14_1 * 2) + 44) & 63;
  int stage_v_54_2 = ((pub_r001592_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001592_12_1 * 2) + 49) & 63;
  int stage_v_55_2 = ((pub_r001592_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = (((stage_v_24_1 * 3) + pub_r001592_13_1) + 16) & 127;
  int stage_v_56_2 = (((stage_v_24_2 * 3) + pub_r001592_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = ((pub_r001592_9_1 * 2) + 23) & 63;
  int stage_v_57_2 = ((pub_r001592_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001592_13_1 * 2) + 49) & 63;
  int stage_v_58_2 = ((pub_r001592_13_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = (((helper_flow_0_1 * 3) + pub_r001592_18_1) + 39) & 127;
  int stage_v_59_2 = (((helper_flow_0_2 * 3) + pub_r001592_18_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = (((sec_r001592_19_1 * 3) + pub_r001592_23_1) + 22) & 127;
  int stage_v_60_2 = (((sec_r001592_19_2 * 3) + pub_r001592_23_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = (((stage_v_28_1 * 3) + pub_r001592_1_1) + 13) & 127;
  int stage_v_61_2 = (((stage_v_28_2 * 3) + pub_r001592_1_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001592_8_1 * 2) + 8) & 63;
  int stage_v_62_2 = ((pub_r001592_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((sec_r001592_8_1 * 3) + pub_r001592_22_1) + 42) & 127;
  int stage_v_63_2 = (((sec_r001592_8_2 * 3) + pub_r001592_22_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((sec_r001592_2_1 * 3) + pub_r001592_20_1) + 45) & 127;
  int stage_v_64_2 = (((sec_r001592_2_2 * 3) + pub_r001592_20_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = ((pub_r001592_16_1 * 2) + 31) & 63;
  int stage_v_65_2 = ((pub_r001592_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001592_19_1 * 2) + 25) & 63;
  int stage_v_66_2 = ((pub_r001592_19_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (((sec_r001592_10_1 * 3) + pub_r001592_1_1) + 28) & 127;
  int stage_v_67_2 = (((sec_r001592_10_2 * 3) + pub_r001592_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = (((sec_r001592_4_1 * 3) + pub_r001592_17_1) + 5) & 127;
  int stage_v_68_2 = (((sec_r001592_4_2 * 3) + pub_r001592_17_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = ((pub_r001592_9_1 * 2) + 13) & 63;
  int stage_v_69_2 = ((pub_r001592_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001592_8_1 * 2) + 39) & 63;
  int stage_v_70_2 = ((pub_r001592_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001592_2_1 * 2) + 47) & 63;
  int stage_v_71_2 = ((pub_r001592_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((stage_v_31_1 * 3) + pub_r001592_12_1) + 27) & 127;
  int stage_v_72_2 = (((stage_v_31_2 * 3) + pub_r001592_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = ((pub_r001592_21_1 * 2) + 34) & 63;
  int stage_v_73_2 = ((pub_r001592_21_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001592_9_1 * 2) + 49) & 63;
  int stage_v_74_2 = ((pub_r001592_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (((sec_r001592_2_1 * 3) + pub_r001592_9_1) + 8) & 127;
  int stage_v_75_2 = (((sec_r001592_2_2 * 3) + pub_r001592_9_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = (((stage_v_61_1 * 3) + pub_r001592_1_1) + 11) & 127;
  int stage_v_76_2 = (((stage_v_61_2 * 3) + pub_r001592_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = ((pub_r001592_20_1 * 2) + 40) & 63;
  int stage_v_77_2 = ((pub_r001592_20_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001592_2_1 * 2) + 24) & 63;
  int stage_v_78_2 = ((pub_r001592_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001592_6_1 * 2) + 20) & 63;
  int stage_v_79_2 = ((pub_r001592_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (((sec_r001592_12_1 * 3) + pub_r001592_4_1) + 5) & 127;
  int stage_v_80_2 = (((sec_r001592_12_2 * 3) + pub_r001592_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_80_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_80_2 * 2)) & 255;
  int stage_v_81_1 = ((pub_r001592_17_1 * 2) + 43) & 63;
  int stage_v_81_2 = ((pub_r001592_17_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = (((sec_r001592_21_1 * 3) + pub_r001592_4_1) + 41) & 127;
  int stage_v_82_2 = (((sec_r001592_21_2 * 3) + pub_r001592_4_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = (((helper_flow_0_1 * 3) + pub_r001592_15_1) + 23) & 127;
  int stage_v_83_2 = (((helper_flow_0_2 * 3) + pub_r001592_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = ((pub_r001592_1_1 * 2) + 27) & 63;
  int stage_v_84_2 = ((pub_r001592_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001592_17_1 * 2) + 33) & 63;
  int stage_v_85_2 = ((pub_r001592_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (((sec_r001592_6_1 * 3) + pub_r001592_22_1) + 33) & 127;
  int stage_v_86_2 = (((sec_r001592_6_2 * 3) + pub_r001592_22_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = (((sec_r001592_0_1 * 3) + pub_r001592_9_1) + 11) & 127;
  int stage_v_87_2 = (((sec_r001592_0_2 * 3) + pub_r001592_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = ((pub_r001592_3_1 * 2) + 27) & 63;
  int stage_v_88_2 = ((pub_r001592_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (((stage_v_47_1 * 3) + pub_r001592_22_1) + 25) & 127;
  int stage_v_89_2 = (((stage_v_47_2 * 3) + pub_r001592_22_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = (((helper_flow_2_1 * 3) + pub_r001592_9_1) + 23) & 127;
  int stage_v_90_2 = (((helper_flow_2_2 * 3) + pub_r001592_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = ((pub_r001592_21_1 * 2) + 38) & 63;
  int stage_v_91_2 = ((pub_r001592_21_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001592_21_1 * 2) + 31) & 63;
  int stage_v_92_2 = ((pub_r001592_21_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001592_21_1 * 2) + 14) & 63;
  int stage_v_93_2 = ((pub_r001592_21_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001592_4_1 * 2) + 11) & 63;
  int stage_v_94_2 = ((pub_r001592_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001592_6_1 * 2) + 33) & 63;
  int stage_v_95_2 = ((pub_r001592_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001592_13_1 * 2) + 14) & 63;
  int stage_v_96_2 = ((pub_r001592_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001592_21_1 * 2) + 46) & 63;
  int stage_v_97_2 = ((pub_r001592_21_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001592_21_1 * 2) + 38) & 63;
  int stage_v_98_2 = ((pub_r001592_21_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001592_7_1 * 2) + 24) & 63;
  int stage_v_99_2 = ((pub_r001592_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001592_13_1 * 2) + 37) & 63;
  int stage_v_100_2 = ((pub_r001592_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_82_1 * 3) + pub_r001592_3_1) + 41) & 127;
  int stage_v_101_2 = (((stage_v_82_2 * 3) + pub_r001592_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = ((pub_r001592_21_1 * 2) + 48) & 63;
  int stage_v_102_2 = ((pub_r001592_21_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001592_11_1 * 2) + 6) & 63;
  int stage_v_103_2 = ((pub_r001592_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((pub_r001592_1_1 * 2) + 34) & 63;
  int stage_v_104_2 = ((pub_r001592_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001592_23_1 * 2) + 44) & 63;
  int stage_v_105_2 = ((pub_r001592_23_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (((stage_v_26_1 * 3) + pub_r001592_23_1) + 30) & 127;
  int stage_v_106_2 = (((stage_v_26_2 * 3) + pub_r001592_23_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = ((pub_r001592_23_1 * 2) + 38) & 63;
  int stage_v_107_2 = ((pub_r001592_23_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (((stage_v_80_1 * 3) + pub_r001592_20_1) + 10) & 127;
  int stage_v_108_2 = (((stage_v_80_2 * 3) + pub_r001592_20_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = ((pub_r001592_0_1 * 2) + 31) & 63;
  int stage_v_109_2 = ((pub_r001592_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001592_13_1 * 2) + 26) & 63;
  int stage_v_110_2 = ((pub_r001592_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001592_6_1 * 2) + 33) & 63;
  int stage_v_111_2 = ((pub_r001592_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (((sec_r001592_19_1 * 3) + pub_r001592_21_1) + 8) & 127;
  int stage_v_112_2 = (((sec_r001592_19_2 * 3) + pub_r001592_21_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = ((pub_r001592_14_1 * 2) + 47) & 63;
  int stage_v_113_2 = ((pub_r001592_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (((stage_v_59_1 * 3) + pub_r001592_13_1) + 34) & 127;
  int stage_v_114_2 = (((stage_v_59_2 * 3) + pub_r001592_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = (((stage_v_64_1 * 3) + pub_r001592_5_1) + 35) & 127;
  int stage_v_115_2 = (((stage_v_64_2 * 3) + pub_r001592_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = ((pub_r001592_4_1 * 2) + 48) & 63;
  int stage_v_116_2 = ((pub_r001592_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001592_18_1 * 2) + 43) & 63;
  int stage_v_117_2 = ((pub_r001592_18_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001592_14_1 * 2) + 26) & 63;
  int stage_v_118_2 = ((pub_r001592_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (((sec_r001592_19_1 * 3) + pub_r001592_17_1) + 26) & 127;
  int stage_v_119_2 = (((sec_r001592_19_2 * 3) + pub_r001592_17_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = (((stage_v_86_1 * 3) + pub_r001592_16_1) + 39) & 127;
  int stage_v_120_2 = (((stage_v_86_2 * 3) + pub_r001592_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = ((pub_r001592_8_1 * 2) + 25) & 63;
  int stage_v_121_2 = ((pub_r001592_8_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001592_5_1 * 2) + 35) & 63;
  int stage_v_122_2 = ((pub_r001592_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001592_19_1 * 2) + 37) & 63;
  int stage_v_123_2 = ((pub_r001592_19_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001592_5_1 * 2) + 34) & 63;
  int stage_v_124_2 = ((pub_r001592_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001592_2_1 * 2) + 50) & 63;
  int stage_v_125_2 = ((pub_r001592_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001592_5_1 * 2) + 14) & 63;
  int stage_v_126_2 = ((pub_r001592_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001592_3_1 * 2) + 19) & 63;
  int stage_v_127_2 = ((pub_r001592_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001592_6_1 * 2) + 25) & 63;
  int stage_v_128_2 = ((pub_r001592_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001592_4_1 * 2) + 11) & 63;
  int stage_v_129_2 = ((pub_r001592_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = (((stage_v_24_1 * 3) + pub_r001592_4_1) + 37) & 127;
  int stage_v_130_2 = (((stage_v_24_2 * 3) + pub_r001592_4_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = ((pub_r001592_8_1 * 2) + 29) & 63;
  int stage_v_131_2 = ((pub_r001592_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001592_21_1 * 2) + 21) & 63;
  int stage_v_132_2 = ((pub_r001592_21_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((sec_r001592_16_1 * 3) + pub_r001592_13_1) + 17) & 127;
  int stage_v_133_2 = (((sec_r001592_16_2 * 3) + pub_r001592_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((stage_v_49_1 * 3) + pub_r001592_6_1) + 31) & 127;
  int stage_v_134_2 = (((stage_v_49_2 * 3) + pub_r001592_6_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = (((sec_r001592_17_1 * 3) + pub_r001592_17_1) + 14) & 127;
  int stage_v_135_2 = (((sec_r001592_17_2 * 3) + pub_r001592_17_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = ((pub_r001592_9_1 * 2) + 43) & 63;
  int stage_v_136_2 = ((pub_r001592_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = (((stage_v_130_1 * 3) + pub_r001592_13_1) + 9) & 127;
  int stage_v_137_2 = (((stage_v_130_2 * 3) + pub_r001592_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = (((stage_v_134_1 * 3) + pub_r001592_2_1) + 15) & 127;
  int stage_v_138_2 = (((stage_v_134_2 * 3) + pub_r001592_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = ((pub_r001592_12_1 * 2) + 6) & 63;
  int stage_v_139_2 = ((pub_r001592_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001592_6_1 * 2) + 27) & 63;
  int stage_v_140_2 = ((pub_r001592_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001592_7_1 * 2) + 48) & 63;
  int stage_v_141_2 = ((pub_r001592_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001592_16_1 * 2) + 46) & 63;
  int stage_v_142_2 = ((pub_r001592_16_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = (((sec_r001592_1_1 * 3) + pub_r001592_23_1) + 18) & 127;
  int stage_v_143_2 = (((sec_r001592_1_2 * 3) + pub_r001592_23_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = (((stage_v_101_1 * 3) + pub_r001592_20_1) + 40) & 127;
  int stage_v_144_2 = (((stage_v_101_2 * 3) + pub_r001592_20_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = ((pub_r001592_15_1 * 2) + 26) & 63;
  int stage_v_145_2 = ((pub_r001592_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001592_16_1 * 2) + 13) & 63;
  int stage_v_146_2 = ((pub_r001592_16_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001592_8_1 * 2) + 30) & 63;
  int stage_v_147_2 = ((pub_r001592_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_24_1 * 3) + pub_r001592_0_1) + 20) & 127;
  int stage_v_148_2 = (((stage_v_24_2 * 3) + pub_r001592_0_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = ((pub_r001592_0_1 * 2) + 34) & 63;
  int stage_v_149_2 = ((pub_r001592_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001592_4_1 * 2) + 37) & 63;
  int stage_v_150_2 = ((pub_r001592_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001592_6_1 * 2) + 44) & 63;
  int stage_v_151_2 = ((pub_r001592_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001592_16_1 * 2) + 33) & 63;
  int stage_v_152_2 = ((pub_r001592_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (((stage_v_89_1 * 3) + pub_r001592_1_1) + 40) & 127;
  int stage_v_153_2 = (((stage_v_89_2 * 3) + pub_r001592_1_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = ((pub_r001592_20_1 * 2) + 50) & 63;
  int stage_v_154_2 = ((pub_r001592_20_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = (((sec_r001592_5_1 * 3) + pub_r001592_7_1) + 20) & 127;
  int stage_v_155_2 = (((sec_r001592_5_2 * 3) + pub_r001592_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = ((pub_r001592_5_1 * 2) + 31) & 63;
  int stage_v_156_2 = ((pub_r001592_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001592_9_1 * 2) + 50) & 63;
  int stage_v_157_2 = ((pub_r001592_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001592_17_1 * 2) + 50) & 63;
  int stage_v_158_2 = ((pub_r001592_17_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001592_12_1 * 2) + 27) & 63;
  int stage_v_159_2 = ((pub_r001592_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = (((stage_v_137_1 * 3) + pub_r001592_7_1) + 7) & 127;
  int stage_v_160_2 = (((stage_v_137_2 * 3) + pub_r001592_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = ((pub_r001592_0_1 * 2) + 29) & 63;
  int stage_v_161_2 = ((pub_r001592_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001592_23_1 * 2) + 28) & 63;
  int stage_v_162_2 = ((pub_r001592_23_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001592_10_1 * 2) + 17) & 63;
  int stage_v_163_2 = ((pub_r001592_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (((stage_v_4_1 * 3) + pub_r001592_12_1) + 17) & 127;
  int stage_v_164_2 = (((stage_v_4_2 * 3) + pub_r001592_12_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = ((pub_r001592_16_1 * 2) + 10) & 63;
  int stage_v_165_2 = ((pub_r001592_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = (((stage_v_114_1 * 3) + pub_r001592_19_1) + 3) & 127;
  int stage_v_166_2 = (((stage_v_114_2 * 3) + pub_r001592_19_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = ((pub_r001592_14_1 * 2) + 29) & 63;
  int stage_v_167_2 = ((pub_r001592_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = (((stage_v_143_1 * 3) + pub_r001592_13_1) + 23) & 127;
  int stage_v_168_2 = (((stage_v_143_2 * 3) + pub_r001592_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = ((pub_r001592_20_1 * 2) + 9) & 63;
  int stage_v_169_2 = ((pub_r001592_20_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001592_23_1 * 2) + 47) & 63;
  int stage_v_170_2 = ((pub_r001592_23_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = (((stage_v_155_1 * 3) + pub_r001592_16_1) + 41) & 127;
  int stage_v_171_2 = (((stage_v_155_2 * 3) + pub_r001592_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = ((pub_r001592_22_1 * 2) + 36) & 63;
  int stage_v_172_2 = ((pub_r001592_22_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001592_1_1 * 2) + 30) & 63;
  int stage_v_173_2 = ((pub_r001592_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001592_3_1 * 2) + 7) & 63;
  int stage_v_174_2 = ((pub_r001592_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((sec_r001592_3_1 * 3) + pub_r001592_21_1) + 44) & 127;
  int stage_v_175_2 = (((sec_r001592_3_2 * 3) + pub_r001592_21_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = (((sec_r001592_19_1 * 3) + pub_r001592_21_1) + 7) & 127;
  int stage_v_176_2 = (((sec_r001592_19_2 * 3) + pub_r001592_21_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = (((sec_r001592_13_1 * 3) + pub_r001592_12_1) + 8) & 127;
  int stage_v_177_2 = (((sec_r001592_13_2 * 3) + pub_r001592_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = ((pub_r001592_6_1 * 2) + 48) & 63;
  int stage_v_178_2 = ((pub_r001592_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001592_15_1 * 2) + 16) & 63;
  int stage_v_179_2 = ((pub_r001592_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((stage_v_114_1 * 3) + pub_r001592_3_1) + 15) & 127;
  int stage_v_180_2 = (((stage_v_114_2 * 3) + pub_r001592_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = ((pub_r001592_5_1 * 2) + 50) & 63;
  int stage_v_181_2 = ((pub_r001592_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((sec_r001592_1_1 * 3) + pub_r001592_5_1) + 35) & 127;
  int stage_v_182_2 = (((sec_r001592_1_2 * 3) + pub_r001592_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = ((pub_r001592_0_1 * 2) + 41) & 63;
  int stage_v_183_2 = ((pub_r001592_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001592_23_1 * 2) + 35) & 63;
  int stage_v_184_2 = ((pub_r001592_23_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((stage_v_176_1 * 3) + pub_r001592_14_1) + 9) & 127;
  int stage_v_185_2 = (((stage_v_176_2 * 3) + pub_r001592_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = (((stage_v_87_1 * 3) + pub_r001592_19_1) + 44) & 127;
  int stage_v_186_2 = (((stage_v_87_2 * 3) + pub_r001592_19_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = ((pub_r001592_0_1 * 2) + 40) & 63;
  int stage_v_187_2 = ((pub_r001592_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001592_12_1 * 2) + 45) & 63;
  int stage_v_188_2 = ((pub_r001592_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001592_14_1 * 2) + 45) & 63;
  int stage_v_189_2 = ((pub_r001592_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((sec_r001592_12_1 * 3) + pub_r001592_3_1) + 5) & 127;
  int stage_v_190_2 = (((sec_r001592_12_2 * 3) + pub_r001592_3_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = (((stage_v_153_1 * 3) + pub_r001592_8_1) + 27) & 127;
  int stage_v_191_2 = (((stage_v_153_2 * 3) + pub_r001592_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = (((stage_v_4_1 * 3) + pub_r001592_17_1) + 34) & 127;
  int stage_v_192_2 = (((stage_v_4_2 * 3) + pub_r001592_17_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = (((stage_v_28_1 * 3) + pub_r001592_22_1) + 31) & 127;
  int stage_v_193_2 = (((stage_v_28_2 * 3) + pub_r001592_22_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = ((pub_r001592_18_1 * 2) + 33) & 63;
  int stage_v_194_2 = ((pub_r001592_18_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = (((stage_v_185_1 * 3) + pub_r001592_8_1) + 32) & 127;
  int stage_v_195_2 = (((stage_v_185_2 * 3) + pub_r001592_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = (((sec_r001592_16_1 * 3) + pub_r001592_3_1) + 3) & 127;
  int stage_v_196_2 = (((sec_r001592_16_2 * 3) + pub_r001592_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = ((pub_r001592_13_1 * 2) + 7) & 63;
  int stage_v_197_2 = ((pub_r001592_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001592_21_1 * 2) + 10) & 63;
  int stage_v_198_2 = ((pub_r001592_21_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (((stage_v_31_1 * 3) + pub_r001592_13_1) + 4) & 127;
  int stage_v_199_2 = (((stage_v_31_2 * 3) + pub_r001592_13_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = ((pub_r001592_9_1 * 2) + 26) & 63;
  int stage_v_200_2 = ((pub_r001592_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = (((stage_v_134_1 * 3) + pub_r001592_13_1) + 30) & 127;
  int stage_v_201_2 = (((stage_v_134_2 * 3) + pub_r001592_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = (((stage_v_16_1 * 3) + pub_r001592_17_1) + 26) & 127;
  int stage_v_202_2 = (((stage_v_16_2 * 3) + pub_r001592_17_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = ((pub_r001592_5_1 * 2) + 34) & 63;
  int stage_v_203_2 = ((pub_r001592_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((helper_flow_0_1 * 3) + pub_r001592_8_1) + 28) & 127;
  int stage_v_204_2 = (((helper_flow_0_2 * 3) + pub_r001592_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = ((pub_r001592_8_1 * 2) + 34) & 63;
  int stage_v_205_2 = ((pub_r001592_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001592_17_1 * 2) + 12) & 63;
  int stage_v_206_2 = ((pub_r001592_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001592_18_1 * 2) + 12) & 63;
  int stage_v_207_2 = ((pub_r001592_18_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = (((stage_v_106_1 * 3) + pub_r001592_10_1) + 10) & 127;
  int stage_v_208_2 = (((stage_v_106_2 * 3) + pub_r001592_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_208_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_208_2 * 2)) & 255;
  int stage_v_209_1 = ((pub_r001592_1_1 * 2) + 26) & 63;
  int stage_v_209_2 = ((pub_r001592_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001592_9_1 * 2) + 30) & 63;
  int stage_v_210_2 = ((pub_r001592_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001592_23_1 * 2) + 19) & 63;
  int stage_v_211_2 = ((pub_r001592_23_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((pub_r001592_20_1 * 2) + 46) & 63;
  int stage_v_212_2 = ((pub_r001592_20_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = (((stage_v_143_1 * 3) + pub_r001592_8_1) + 6) & 127;
  int stage_v_213_2 = (((stage_v_143_2 * 3) + pub_r001592_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = ((pub_r001592_19_1 * 2) + 20) & 63;
  int stage_v_214_2 = ((pub_r001592_19_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((stage_v_112_1 * 3) + pub_r001592_6_1) + 27) & 127;
  int stage_v_215_2 = (((stage_v_112_2 * 3) + pub_r001592_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((stage_v_130_1 * 3) + pub_r001592_10_1) + 28) & 127;
  int stage_v_216_2 = (((stage_v_130_2 * 3) + pub_r001592_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = (((sec_r001592_19_1 * 3) + pub_r001592_0_1) + 21) & 127;
  int stage_v_217_2 = (((sec_r001592_19_2 * 3) + pub_r001592_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = ((pub_r001592_4_1 * 2) + 30) & 63;
  int stage_v_218_2 = ((pub_r001592_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001592_20_1 * 2) + 43) & 63;
  int stage_v_219_2 = ((pub_r001592_20_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((pub_r001592_0_1 * 2) + 27) & 63;
  int stage_v_220_2 = ((pub_r001592_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = (((stage_v_90_1 * 3) + pub_r001592_8_1) + 7) & 127;
  int stage_v_221_2 = (((stage_v_90_2 * 3) + pub_r001592_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = ((pub_r001592_21_1 * 2) + 26) & 63;
  int stage_v_222_2 = ((pub_r001592_21_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = (((sec_r001592_22_1 * 3) + pub_r001592_14_1) + 23) & 127;
  int stage_v_223_2 = (((sec_r001592_22_2 * 3) + pub_r001592_14_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = (((stage_v_160_1 * 3) + pub_r001592_10_1) + 37) & 127;
  int stage_v_224_2 = (((stage_v_160_2 * 3) + pub_r001592_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = ((pub_r001592_11_1 * 2) + 35) & 63;
  int stage_v_225_2 = ((pub_r001592_11_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = (((stage_v_208_1 * 3) + pub_r001592_14_1) + 30) & 127;
  int stage_v_226_2 = (((stage_v_208_2 * 3) + pub_r001592_14_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = (((stage_v_226_1 * 3) + pub_r001592_13_1) + 6) & 127;
  int stage_v_227_2 = (((stage_v_226_2 * 3) + pub_r001592_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = ((pub_r001592_19_1 * 2) + 25) & 63;
  int stage_v_228_2 = ((pub_r001592_19_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001592_23_1 * 2) + 35) & 63;
  int stage_v_229_2 = ((pub_r001592_23_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = (((stage_v_138_1 * 3) + pub_r001592_0_1) + 4) & 127;
  int stage_v_230_2 = (((stage_v_138_2 * 3) + pub_r001592_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = ((pub_r001592_6_1 * 2) + 19) & 63;
  int stage_v_231_2 = ((pub_r001592_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001592_9_1 * 2) + 11) & 63;
  int stage_v_232_2 = ((pub_r001592_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001592_3_1 * 2) + 15) & 63;
  int stage_v_233_2 = ((pub_r001592_3_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = (((stage_v_217_1 * 3) + pub_r001592_11_1) + 24) & 127;
  int stage_v_234_2 = (((stage_v_217_2 * 3) + pub_r001592_11_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = ((pub_r001592_23_1 * 2) + 30) & 63;
  int stage_v_235_2 = ((pub_r001592_23_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = (((stage_v_8_1 * 3) + pub_r001592_3_1) + 21) & 127;
  int stage_v_236_2 = (((stage_v_8_2 * 3) + pub_r001592_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = (((stage_v_60_1 * 3) + pub_r001592_0_1) + 41) & 127;
  int stage_v_237_2 = (((stage_v_60_2 * 3) + pub_r001592_0_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_237_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_237_2 * 2)) & 255;
  int stage_v_238_1 = ((pub_r001592_17_1 * 2) + 22) & 63;
  int stage_v_238_2 = ((pub_r001592_17_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001592_11_1 * 2) + 13) & 63;
  int stage_v_239_2 = ((pub_r001592_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = (((sec_r001592_6_1 * 3) + pub_r001592_12_1) + 22) & 127;
  int stage_v_240_2 = (((sec_r001592_6_2 * 3) + pub_r001592_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = ((pub_r001592_14_1 * 2) + 29) & 63;
  int stage_v_241_2 = ((pub_r001592_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = (((sec_r001592_10_1 * 3) + pub_r001592_5_1) + 23) & 127;
  int stage_v_242_2 = (((sec_r001592_10_2 * 3) + pub_r001592_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = (((sec_r001592_13_1 * 3) + pub_r001592_21_1) + 3) & 127;
  int stage_v_243_2 = (((sec_r001592_13_2 * 3) + pub_r001592_21_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = ((pub_r001592_20_1 * 2) + 22) & 63;
  int stage_v_244_2 = ((pub_r001592_20_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001592_21_1 * 2) + 42) & 63;
  int stage_v_245_2 = ((pub_r001592_21_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001592_14_1 * 2) + 27) & 63;
  int stage_v_246_2 = ((pub_r001592_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001592_1_1 * 2) + 23) & 63;
  int stage_v_247_2 = ((pub_r001592_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001592_7_1 * 2) + 15) & 63;
  int stage_v_248_2 = ((pub_r001592_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((pub_r001592_0_1 * 2) + 33) & 63;
  int stage_v_249_2 = ((pub_r001592_0_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001592_23_1 * 2) + 47) & 63;
  int stage_v_250_2 = ((pub_r001592_23_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001592_22_1 * 2) + 42) & 63;
  int stage_v_251_2 = ((pub_r001592_22_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = (((sec_r001592_11_1 * 3) + pub_r001592_19_1) + 27) & 127;
  int stage_v_252_2 = (((sec_r001592_11_2 * 3) + pub_r001592_19_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = ((pub_r001592_11_1 * 2) + 39) & 63;
  int stage_v_253_2 = ((pub_r001592_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = (((stage_v_138_1 * 3) + pub_r001592_7_1) + 38) & 127;
  int stage_v_254_2 = (((stage_v_138_2 * 3) + pub_r001592_7_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = (((stage_v_230_1 * 3) + pub_r001592_22_1) + 13) & 127;
  int stage_v_255_2 = (((stage_v_230_2 * 3) + pub_r001592_22_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = (((sec_r001592_8_1 * 3) + pub_r001592_13_1) + 6) & 127;
  int stage_v_256_2 = (((sec_r001592_8_2 * 3) + pub_r001592_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = ((pub_r001592_3_1 * 2) + 48) & 63;
  int stage_v_257_2 = ((pub_r001592_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((pub_r001592_10_1 * 2) + 7) & 63;
  int stage_v_258_2 = ((pub_r001592_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((pub_r001592_8_1 * 2) + 20) & 63;
  int stage_v_259_2 = ((pub_r001592_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001592_7_1 * 2) + 31) & 63;
  int stage_v_260_2 = ((pub_r001592_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = (((stage_v_208_1 * 3) + pub_r001592_22_1) + 13) & 127;
  int stage_v_261_2 = (((stage_v_208_2 * 3) + pub_r001592_22_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = ((pub_r001592_17_1 * 2) + 21) & 63;
  int stage_v_262_2 = ((pub_r001592_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001592_20_1 * 2) + 24) & 63;
  int stage_v_263_2 = ((pub_r001592_20_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((pub_r001592_12_1 * 2) + 41) & 63;
  int stage_v_264_2 = ((pub_r001592_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((pub_r001592_1_1 * 2) + 19) & 63;
  int stage_v_265_2 = ((pub_r001592_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = ((pub_r001592_21_1 * 2) + 41) & 63;
  int stage_v_266_2 = ((pub_r001592_21_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((pub_r001592_6_1 * 2) + 21) & 63;
  int stage_v_267_2 = ((pub_r001592_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = (((stage_v_90_1 * 3) + pub_r001592_8_1) + 23) & 127;
  int stage_v_268_2 = (((stage_v_90_2 * 3) + pub_r001592_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = ((pub_r001592_7_1 * 2) + 6) & 63;
  int stage_v_269_2 = ((pub_r001592_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = (((sec_r001592_7_1 * 3) + pub_r001592_13_1) + 42) & 127;
  int stage_v_270_2 = (((sec_r001592_7_2 * 3) + pub_r001592_13_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = (((sec_r001592_0_1 * 3) + pub_r001592_6_1) + 24) & 127;
  int stage_v_271_2 = (((sec_r001592_0_2 * 3) + pub_r001592_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = ((pub_r001592_14_1 * 2) + 33) & 63;
  int stage_v_272_2 = ((pub_r001592_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = (((stage_v_199_1 * 3) + pub_r001592_23_1) + 33) & 127;
  int stage_v_273_2 = (((stage_v_199_2 * 3) + pub_r001592_23_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = ((pub_r001592_1_1 * 2) + 14) & 63;
  int stage_v_274_2 = ((pub_r001592_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((pub_r001592_16_1 * 2) + 27) & 63;
  int stage_v_275_2 = ((pub_r001592_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = (((stage_v_8_1 * 3) + pub_r001592_17_1) + 43) & 127;
  int stage_v_276_2 = (((stage_v_8_2 * 3) + pub_r001592_17_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = ((pub_r001592_10_1 * 2) + 46) & 63;
  int stage_v_277_2 = ((pub_r001592_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = (((stage_v_226_1 * 3) + pub_r001592_22_1) + 3) & 127;
  int stage_v_278_2 = (((stage_v_226_2 * 3) + pub_r001592_22_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = ((pub_r001592_19_1 * 2) + 36) & 63;
  int stage_v_279_2 = ((pub_r001592_19_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001592_4_1 * 2) + 34) & 63;
  int stage_v_280_2 = ((pub_r001592_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((pub_r001592_23_1 * 2) + 8) & 63;
  int stage_v_281_2 = ((pub_r001592_23_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = (((stage_v_83_1 * 3) + pub_r001592_7_1) + 42) & 127;
  int stage_v_282_2 = (((stage_v_83_2 * 3) + pub_r001592_7_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = (((stage_v_86_1 * 3) + pub_r001592_9_1) + 31) & 127;
  int stage_v_283_2 = (((stage_v_86_2 * 3) + pub_r001592_9_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = (((sec_r001592_7_1 * 3) + pub_r001592_0_1) + 21) & 127;
  int stage_v_284_2 = (((sec_r001592_7_2 * 3) + pub_r001592_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = ((pub_r001592_12_1 * 2) + 32) & 63;
  int stage_v_285_2 = ((pub_r001592_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = (((stage_v_254_1 * 3) + pub_r001592_11_1) + 38) & 127;
  int stage_v_286_2 = (((stage_v_254_2 * 3) + pub_r001592_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = ((pub_r001592_4_1 * 2) + 49) & 63;
  int stage_v_287_2 = ((pub_r001592_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = (((stage_v_37_1 * 3) + pub_r001592_7_1) + 32) & 127;
  int stage_v_288_2 = (((stage_v_37_2 * 3) + pub_r001592_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = ((pub_r001592_20_1 * 2) + 23) & 63;
  int stage_v_289_2 = ((pub_r001592_20_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((pub_r001592_11_1 * 2) + 42) & 63;
  int stage_v_290_2 = ((pub_r001592_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = (((stage_v_64_1 * 3) + pub_r001592_10_1) + 23) & 127;
  int stage_v_291_2 = (((stage_v_64_2 * 3) + pub_r001592_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = ((pub_r001592_20_1 * 2) + 22) & 63;
  int stage_v_292_2 = ((pub_r001592_20_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001592_3_1 * 2) + 44) & 63;
  int stage_v_293_2 = ((pub_r001592_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001592_9_1 * 2) + 35) & 63;
  int stage_v_294_2 = ((pub_r001592_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = (((stage_v_80_1 * 3) + pub_r001592_3_1) + 29) & 127;
  int stage_v_295_2 = (((stage_v_80_2 * 3) + pub_r001592_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = ((pub_r001592_9_1 * 2) + 6) & 63;
  int stage_v_296_2 = ((pub_r001592_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001592_16_1 * 2) + 42) & 63;
  int stage_v_297_2 = ((pub_r001592_16_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001592_23_1 * 2) + 45) & 63;
  int stage_v_298_2 = ((pub_r001592_23_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((pub_r001592_8_1 * 2) + 31) & 63;
  int stage_v_299_2 = ((pub_r001592_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((pub_r001592_7_1 * 2) + 22) & 63;
  int stage_v_300_2 = ((pub_r001592_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001592_12_1 * 2) + 44) & 63;
  int stage_v_301_2 = ((pub_r001592_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001592_14_1 * 2) + 16) & 63;
  int stage_v_302_2 = ((pub_r001592_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = (((stage_v_144_1 * 3) + pub_r001592_11_1) + 22) & 127;
  int stage_v_303_2 = (((stage_v_144_2 * 3) + pub_r001592_11_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = (((stage_v_64_1 * 3) + pub_r001592_19_1) + 16) & 127;
  int stage_v_304_2 = (((stage_v_64_2 * 3) + pub_r001592_19_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = (((stage_v_283_1 * 3) + pub_r001592_0_1) + 27) & 127;
  int stage_v_305_2 = (((stage_v_283_2 * 3) + pub_r001592_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_305_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_305_2 * 2)) & 255;
  int stage_v_306_1 = ((pub_r001592_11_1 * 2) + 34) & 63;
  int stage_v_306_2 = ((pub_r001592_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001592_21_1 * 2) + 42) & 63;
  int stage_v_307_2 = ((pub_r001592_21_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001592_17_1 * 2) + 7) & 63;
  int stage_v_308_2 = ((pub_r001592_17_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((pub_r001592_12_1 * 2) + 20) & 63;
  int stage_v_309_2 = ((pub_r001592_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = (((stage_v_202_1 * 3) + pub_r001592_3_1) + 12) & 127;
  int stage_v_310_2 = (((stage_v_202_2 * 3) + pub_r001592_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = ((pub_r001592_15_1 * 2) + 38) & 63;
  int stage_v_311_2 = ((pub_r001592_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = ((pub_r001592_19_1 * 2) + 38) & 63;
  int stage_v_312_2 = ((pub_r001592_19_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = (((stage_v_286_1 * 3) + pub_r001592_16_1) + 15) & 127;
  int stage_v_313_2 = (((stage_v_286_2 * 3) + pub_r001592_16_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = ((pub_r001592_7_1 * 2) + 16) & 63;
  int stage_v_314_2 = ((pub_r001592_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001592_20_1 * 2) + 49) & 63;
  int stage_v_315_2 = ((pub_r001592_20_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = (((stage_v_166_1 * 3) + pub_r001592_17_1) + 30) & 127;
  int stage_v_316_2 = (((stage_v_166_2 * 3) + pub_r001592_17_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = ((pub_r001592_20_1 * 2) + 46) & 63;
  int stage_v_317_2 = ((pub_r001592_20_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = (((stage_v_234_1 * 3) + pub_r001592_21_1) + 13) & 127;
  int stage_v_318_2 = (((stage_v_234_2 * 3) + pub_r001592_21_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = ((pub_r001592_11_1 * 2) + 24) & 63;
  int stage_v_319_2 = ((pub_r001592_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((pub_r001592_2_1 * 2) + 25) & 63;
  int stage_v_320_2 = ((pub_r001592_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = ((pub_r001592_16_1 * 2) + 22) & 63;
  int stage_v_321_2 = ((pub_r001592_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001592_8_1 * 2) + 20) & 63;
  int stage_v_322_2 = ((pub_r001592_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = (((stage_v_202_1 * 3) + pub_r001592_3_1) + 33) & 127;
  int stage_v_323_2 = (((stage_v_202_2 * 3) + pub_r001592_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_323_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_323_2 * 2)) & 255;
  int stage_v_324_1 = ((pub_r001592_16_1 * 2) + 15) & 63;
  int stage_v_324_2 = ((pub_r001592_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((pub_r001592_7_1 * 2) + 28) & 63;
  int stage_v_325_2 = ((pub_r001592_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = (((sec_r001592_0_1 * 3) + pub_r001592_13_1) + 8) & 127;
  int stage_v_326_2 = (((sec_r001592_0_2 * 3) + pub_r001592_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = (((stage_v_291_1 * 3) + pub_r001592_23_1) + 24) & 127;
  int stage_v_327_2 = (((stage_v_291_2 * 3) + pub_r001592_23_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = ((pub_r001592_7_1 * 2) + 39) & 63;
  int stage_v_328_2 = ((pub_r001592_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = (((stage_v_115_1 * 3) + pub_r001592_11_1) + 24) & 127;
  int stage_v_329_2 = (((stage_v_115_2 * 3) + pub_r001592_11_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = ((pub_r001592_17_1 * 2) + 44) & 63;
  int stage_v_330_2 = ((pub_r001592_17_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001592_9_1 * 2) + 15) & 63;
  int stage_v_331_2 = ((pub_r001592_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = (((sec_r001592_8_1 * 3) + pub_r001592_17_1) + 42) & 127;
  int stage_v_332_2 = (((sec_r001592_8_2 * 3) + pub_r001592_17_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = ((pub_r001592_4_1 * 2) + 36) & 63;
  int stage_v_333_2 = ((pub_r001592_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((pub_r001592_17_1 * 2) + 50) & 63;
  int stage_v_334_2 = ((pub_r001592_17_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = (((sec_r001592_6_1 * 3) + pub_r001592_19_1) + 27) & 127;
  int stage_v_335_2 = (((sec_r001592_6_2 * 3) + pub_r001592_19_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = (((stage_v_63_1 * 3) + pub_r001592_16_1) + 6) & 127;
  int stage_v_336_2 = (((stage_v_63_2 * 3) + pub_r001592_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = ((pub_r001592_6_1 * 2) + 42) & 63;
  int stage_v_337_2 = ((pub_r001592_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = (((stage_v_144_1 * 3) + pub_r001592_9_1) + 42) & 127;
  int stage_v_338_2 = (((stage_v_144_2 * 3) + pub_r001592_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = ((pub_r001592_17_1 * 2) + 27) & 63;
  int stage_v_339_2 = ((pub_r001592_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = (((stage_v_286_1 * 3) + pub_r001592_19_1) + 10) & 127;
  int stage_v_340_2 = (((stage_v_286_2 * 3) + pub_r001592_19_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = ((pub_r001592_10_1 * 2) + 50) & 63;
  int stage_v_341_2 = ((pub_r001592_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((pub_r001592_18_1 * 2) + 48) & 63;
  int stage_v_342_2 = ((pub_r001592_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = (((stage_v_310_1 * 3) + pub_r001592_9_1) + 45) & 127;
  int stage_v_343_2 = (((stage_v_310_2 * 3) + pub_r001592_9_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = ((pub_r001592_10_1 * 2) + 31) & 63;
  int stage_v_344_2 = ((pub_r001592_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = ((pub_r001592_1_1 * 2) + 17) & 63;
  int stage_v_345_2 = ((pub_r001592_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((pub_r001592_12_1 * 2) + 14) & 63;
  int stage_v_346_2 = ((pub_r001592_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = (((stage_v_130_1 * 3) + pub_r001592_8_1) + 6) & 127;
  int stage_v_347_2 = (((stage_v_130_2 * 3) + pub_r001592_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = ((pub_r001592_10_1 * 2) + 44) & 63;
  int stage_v_348_2 = ((pub_r001592_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = ((pub_r001592_6_1 * 2) + 18) & 63;
  int stage_v_349_2 = ((pub_r001592_6_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = ((pub_r001592_9_1 * 2) + 15) & 63;
  int stage_v_350_2 = ((pub_r001592_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = ((pub_r001592_7_1 * 2) + 23) & 63;
  int stage_v_351_2 = ((pub_r001592_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((pub_r001592_15_1 * 2) + 24) & 63;
  int stage_v_352_2 = ((pub_r001592_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((pub_r001592_10_1 * 2) + 22) & 63;
  int stage_v_353_2 = ((pub_r001592_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = (((stage_v_288_1 * 3) + pub_r001592_23_1) + 11) & 127;
  int stage_v_354_2 = (((stage_v_288_2 * 3) + pub_r001592_23_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = (((stage_v_224_1 * 3) + pub_r001592_12_1) + 5) & 127;
  int stage_v_355_2 = (((stage_v_224_2 * 3) + pub_r001592_12_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = (((stage_v_216_1 * 3) + pub_r001592_11_1) + 20) & 127;
  int stage_v_356_2 = (((stage_v_216_2 * 3) + pub_r001592_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = ((pub_r001592_7_1 * 2) + 17) & 63;
  int stage_v_357_2 = ((pub_r001592_7_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001592_8_1 * 2) + 41) & 63;
  int stage_v_358_2 = ((pub_r001592_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = (((stage_v_254_1 * 3) + pub_r001592_9_1) + 10) & 127;
  int stage_v_359_2 = (((stage_v_254_2 * 3) + pub_r001592_9_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = ((pub_r001592_17_1 * 2) + 21) & 63;
  int stage_v_360_2 = ((pub_r001592_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = ((pub_r001592_16_1 * 2) + 12) & 63;
  int stage_v_361_2 = ((pub_r001592_16_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001592_16_1 * 2) + 33) & 63;
  int stage_v_362_2 = ((pub_r001592_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((pub_r001592_23_1 * 2) + 49) & 63;
  int stage_v_363_2 = ((pub_r001592_23_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = (((stage_v_83_1 * 3) + pub_r001592_4_1) + 35) & 127;
  int stage_v_364_2 = (((stage_v_83_2 * 3) + pub_r001592_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = (((stage_v_49_1 * 3) + pub_r001592_18_1) + 38) & 127;
  int stage_v_365_2 = (((stage_v_49_2 * 3) + pub_r001592_18_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = (((stage_v_359_1 * 3) + pub_r001592_7_1) + 6) & 127;
  int stage_v_366_2 = (((stage_v_359_2 * 3) + pub_r001592_7_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = ((pub_r001592_21_1 * 2) + 50) & 63;
  int stage_v_367_2 = ((pub_r001592_21_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((pub_r001592_9_1 * 2) + 23) & 63;
  int stage_v_368_2 = ((pub_r001592_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = (((stage_v_153_1 * 3) + pub_r001592_0_1) + 37) & 127;
  int stage_v_369_2 = (((stage_v_153_2 * 3) + pub_r001592_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = ((pub_r001592_20_1 * 2) + 19) & 63;
  int stage_v_370_2 = ((pub_r001592_20_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = (((stage_v_171_1 * 3) + pub_r001592_21_1) + 42) & 127;
  int stage_v_371_2 = (((stage_v_171_2 * 3) + pub_r001592_21_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = ((pub_r001592_2_1 * 2) + 23) & 63;
  int stage_v_372_2 = ((pub_r001592_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = (((stage_v_256_1 * 3) + pub_r001592_20_1) + 29) & 127;
  int stage_v_373_2 = (((stage_v_256_2 * 3) + pub_r001592_20_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = (((stage_v_19_1 * 3) + pub_r001592_22_1) + 22) & 127;
  int stage_v_374_2 = (((stage_v_19_2 * 3) + pub_r001592_22_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_201_1 * 3) + pub_r001592_1_1) + 9) & 127;
  int stage_v_375_2 = (((stage_v_201_2 * 3) + pub_r001592_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = (((stage_v_332_1 * 3) + pub_r001592_9_1) + 4) & 127;
  int stage_v_376_2 = (((stage_v_332_2 * 3) + pub_r001592_9_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = ((pub_r001592_2_1 * 2) + 24) & 63;
  int stage_v_377_2 = ((pub_r001592_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = (((stage_v_236_1 * 3) + pub_r001592_12_1) + 21) & 127;
  int stage_v_378_2 = (((stage_v_236_2 * 3) + pub_r001592_12_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = ((pub_r001592_14_1 * 2) + 41) & 63;
  int stage_v_379_2 = ((pub_r001592_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = (((sec_r001592_10_1 * 3) + pub_r001592_17_1) + 42) & 127;
  int stage_v_380_2 = (((sec_r001592_10_2 * 3) + pub_r001592_17_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = (((stage_v_273_1 * 3) + pub_r001592_23_1) + 22) & 127;
  int stage_v_381_2 = (((stage_v_273_2 * 3) + pub_r001592_23_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = (((stage_v_7_1 * 3) + pub_r001592_12_1) + 27) & 127;
  int stage_v_382_2 = (((stage_v_7_2 * 3) + pub_r001592_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = ((pub_r001592_12_1 * 2) + 45) & 63;
  int stage_v_383_2 = ((pub_r001592_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001592_15_1 * 2) + 38) & 63;
  int stage_v_384_2 = ((pub_r001592_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((pub_r001592_14_1 * 2) + 40) & 63;
  int stage_v_385_2 = ((pub_r001592_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001592_9_1 * 2) + 5) & 63;
  int stage_v_386_2 = ((pub_r001592_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((pub_r001592_2_1 * 2) + 39) & 63;
  int stage_v_387_2 = ((pub_r001592_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = (((stage_v_106_1 * 3) + pub_r001592_7_1) + 21) & 127;
  int stage_v_388_2 = (((stage_v_106_2 * 3) + pub_r001592_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_388_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_388_2 * 2)) & 255;
  int stage_v_389_1 = (((stage_v_354_1 * 3) + pub_r001592_5_1) + 15) & 127;
  int stage_v_389_2 = (((stage_v_354_2 * 3) + pub_r001592_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = (((stage_v_108_1 * 3) + pub_r001592_10_1) + 8) & 127;
  int stage_v_390_2 = (((stage_v_108_2 * 3) + pub_r001592_10_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = (((stage_v_196_1 * 3) + pub_r001592_4_1) + 44) & 127;
  int stage_v_391_2 = (((stage_v_196_2 * 3) + pub_r001592_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = ((pub_r001592_6_1 * 2) + 34) & 63;
  int stage_v_392_2 = ((pub_r001592_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((pub_r001592_5_1 * 2) + 8) & 63;
  int stage_v_393_2 = ((pub_r001592_5_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((pub_r001592_15_1 * 2) + 36) & 63;
  int stage_v_394_2 = ((pub_r001592_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((pub_r001592_15_1 * 2) + 13) & 63;
  int stage_v_395_2 = ((pub_r001592_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = (((stage_v_120_1 * 3) + pub_r001592_16_1) + 43) & 127;
  int stage_v_396_2 = (((stage_v_120_2 * 3) + pub_r001592_16_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = ((pub_r001592_3_1 * 2) + 16) & 63;
  int stage_v_397_2 = ((pub_r001592_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((pub_r001592_20_1 * 2) + 41) & 63;
  int stage_v_398_2 = ((pub_r001592_20_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = (((stage_v_80_1 * 3) + pub_r001592_18_1) + 27) & 127;
  int stage_v_399_2 = (((stage_v_80_2 * 3) + pub_r001592_18_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_399_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_399_2 * 2)) & 255;
  int stage_v_400_1 = (((stage_v_396_1 * 3) + pub_r001592_18_1) + 33) & 127;
  int stage_v_400_2 = (((stage_v_396_2 * 3) + pub_r001592_18_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_400_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_400_2 * 2)) & 255;
  int stage_v_401_1 = (((stage_v_371_1 * 3) + pub_r001592_13_1) + 37) & 127;
  int stage_v_401_2 = (((stage_v_371_2 * 3) + pub_r001592_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_401_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_401_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_401_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_401_2 * 2)) & 255;
  int stage_v_402_1 = ((pub_r001592_10_1 * 2) + 8) & 63;
  int stage_v_402_2 = ((pub_r001592_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = (((stage_v_305_1 * 3) + pub_r001592_9_1) + 28) & 127;
  int stage_v_403_2 = (((stage_v_305_2 * 3) + pub_r001592_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_403_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_403_2 * 2)) & 255;
  int stage_v_404_1 = (((stage_v_242_1 * 3) + pub_r001592_20_1) + 12) & 127;
  int stage_v_404_2 = (((stage_v_242_2 * 3) + pub_r001592_20_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = ((pub_r001592_9_1 * 2) + 10) & 63;
  int stage_v_405_2 = ((pub_r001592_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = ((pub_r001592_6_1 * 2) + 22) & 63;
  int stage_v_406_2 = ((pub_r001592_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = ((pub_r001592_0_1 * 2) + 41) & 63;
  int stage_v_407_2 = ((pub_r001592_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = ((pub_r001592_18_1 * 2) + 48) & 63;
  int stage_v_408_2 = ((pub_r001592_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = ((pub_r001592_17_1 * 2) + 41) & 63;
  int stage_v_409_2 = ((pub_r001592_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = ((pub_r001592_7_1 * 2) + 15) & 63;
  int stage_v_410_2 = ((pub_r001592_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = (((sec_r001592_16_1 * 3) + pub_r001592_13_1) + 7) & 127;
  int stage_v_411_2 = (((sec_r001592_16_2 * 3) + pub_r001592_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_411_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_411_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_411_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_411_2 * 2)) & 255;
  int stage_v_412_1 = ((pub_r001592_7_1 * 2) + 40) & 63;
  int stage_v_412_2 = ((pub_r001592_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = (((stage_v_261_1 * 3) + pub_r001592_22_1) + 35) & 127;
  int stage_v_413_2 = (((stage_v_261_2 * 3) + pub_r001592_22_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_413_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_413_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_413_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_413_2 * 2)) & 255;
  int stage_v_414_1 = (((stage_v_347_1 * 3) + pub_r001592_23_1) + 38) & 127;
  int stage_v_414_2 = (((stage_v_347_2 * 3) + pub_r001592_23_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_414_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_414_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_414_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_414_2 * 2)) & 255;
  int stage_v_415_1 = ((pub_r001592_11_1 * 2) + 11) & 63;
  int stage_v_415_2 = ((pub_r001592_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = ((pub_r001592_11_1 * 2) + 46) & 63;
  int stage_v_416_2 = ((pub_r001592_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = ((pub_r001592_3_1 * 2) + 43) & 63;
  int stage_v_417_2 = ((pub_r001592_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((pub_r001592_1_1 * 2) + 42) & 63;
  int stage_v_418_2 = ((pub_r001592_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = (((stage_v_236_1 * 3) + pub_r001592_5_1) + 19) & 127;
  int stage_v_419_2 = (((stage_v_236_2 * 3) + pub_r001592_5_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_419_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_419_2 * 2)) & 255;
  int stage_v_420_1 = ((pub_r001592_5_1 * 2) + 29) & 63;
  int stage_v_420_2 = ((pub_r001592_5_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = ((pub_r001592_6_1 * 2) + 49) & 63;
  int stage_v_421_2 = ((pub_r001592_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = ((pub_r001592_6_1 * 2) + 30) & 63;
  int stage_v_422_2 = ((pub_r001592_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = ((pub_r001592_16_1 * 2) + 26) & 63;
  int stage_v_423_2 = ((pub_r001592_16_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001592_1_1 * 2) + 15) & 63;
  int stage_v_424_2 = ((pub_r001592_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((pub_r001592_14_1 * 2) + 21) & 63;
  int stage_v_425_2 = ((pub_r001592_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = (((stage_v_223_1 * 3) + pub_r001592_13_1) + 30) & 127;
  int stage_v_426_2 = (((stage_v_223_2 * 3) + pub_r001592_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_426_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_426_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_426_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_426_2 * 2)) & 255;
  int stage_v_427_1 = (((stage_v_224_1 * 3) + pub_r001592_20_1) + 22) & 127;
  int stage_v_427_2 = (((stage_v_224_2 * 3) + pub_r001592_20_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_427_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_427_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_427_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_427_2 * 2)) & 255;
  int stage_v_428_1 = ((pub_r001592_19_1 * 2) + 37) & 63;
  int stage_v_428_2 = ((pub_r001592_19_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = (((stage_v_378_1 * 3) + pub_r001592_21_1) + 16) & 127;
  int stage_v_429_2 = (((stage_v_378_2 * 3) + pub_r001592_21_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_429_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_429_2 * 2)) & 255;
  int stage_v_430_1 = ((pub_r001592_19_1 * 2) + 47) & 63;
  int stage_v_430_2 = ((pub_r001592_19_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_430_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_430_2) & 127;
  int stage_v_431_1 = (((stage_v_166_1 * 3) + pub_r001592_4_1) + 3) & 127;
  int stage_v_431_2 = (((stage_v_166_2 * 3) + pub_r001592_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_431_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_431_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_431_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_431_2 * 2)) & 255;
  int stage_v_432_1 = ((pub_r001592_4_1 * 2) + 40) & 63;
  int stage_v_432_2 = ((pub_r001592_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = (((stage_v_37_1 * 3) + pub_r001592_1_1) + 11) & 127;
  int stage_v_433_2 = (((stage_v_37_2 * 3) + pub_r001592_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_433_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_433_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_433_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_433_2 * 2)) & 255;
  int stage_v_434_1 = ((pub_r001592_7_1 * 2) + 18) & 63;
  int stage_v_434_2 = ((pub_r001592_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = (((sec_r001592_12_1 * 3) + pub_r001592_8_1) + 38) & 127;
  int stage_v_435_2 = (((sec_r001592_12_2 * 3) + pub_r001592_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_435_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_435_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_435_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_435_2 * 2)) & 255;
  int stage_v_436_1 = ((pub_r001592_13_1 * 2) + 20) & 63;
  int stage_v_436_2 = ((pub_r001592_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = (((stage_v_7_1 * 3) + pub_r001592_6_1) + 17) & 127;
  int stage_v_437_2 = (((stage_v_7_2 * 3) + pub_r001592_6_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_437_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_437_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_437_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_437_2 * 2)) & 255;
  int stage_v_438_1 = ((pub_r001592_8_1 * 2) + 32) & 63;
  int stage_v_438_2 = ((pub_r001592_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = ((pub_r001592_0_1 * 2) + 16) & 63;
  int stage_v_439_2 = ((pub_r001592_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = ((pub_r001592_0_1 * 2) + 17) & 63;
  int stage_v_440_2 = ((pub_r001592_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((pub_r001592_13_1 * 2) + 41) & 63;
  int stage_v_441_2 = ((pub_r001592_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = (((stage_v_47_1 * 3) + pub_r001592_3_1) + 4) & 127;
  int stage_v_442_2 = (((stage_v_47_2 * 3) + pub_r001592_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_442_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_442_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_442_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_442_2 * 2)) & 255;
  int stage_v_443_1 = ((pub_r001592_10_1 * 2) + 39) & 63;
  int stage_v_443_2 = ((pub_r001592_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((pub_r001592_20_1 * 2) + 17) & 63;
  int stage_v_444_2 = ((pub_r001592_20_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = ((pub_r001592_8_1 * 2) + 5) & 63;
  int stage_v_445_2 = ((pub_r001592_8_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = ((pub_r001592_22_1 * 2) + 9) & 63;
  int stage_v_446_2 = ((pub_r001592_22_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_446_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_446_2) & 127;
  int stage_v_447_1 = ((pub_r001592_21_1 * 2) + 10) & 63;
  int stage_v_447_2 = ((pub_r001592_21_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_447_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_447_2) & 127;
  int stage_v_448_1 = ((pub_r001592_4_1 * 2) + 19) & 63;
  int stage_v_448_2 = ((pub_r001592_4_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = (((stage_v_186_1 * 3) + pub_r001592_15_1) + 23) & 127;
  int stage_v_449_2 = (((stage_v_186_2 * 3) + pub_r001592_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_449_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_449_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_449_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_449_2 * 2)) & 255;
  int stage_v_450_1 = ((pub_r001592_22_1 * 2) + 31) & 63;
  int stage_v_450_2 = ((pub_r001592_22_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_450_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_450_2) & 127;
  int stage_v_451_1 = ((pub_r001592_6_1 * 2) + 16) & 63;
  int stage_v_451_2 = ((pub_r001592_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_451_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_451_2) & 127;
  int stage_v_452_1 = ((pub_r001592_12_1 * 2) + 26) & 63;
  int stage_v_452_2 = ((pub_r001592_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = ((pub_r001592_4_1 * 2) + 47) & 63;
  int stage_v_453_2 = ((pub_r001592_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = ((pub_r001592_13_1 * 2) + 45) & 63;
  int stage_v_454_2 = ((pub_r001592_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_454_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_454_2) & 127;
  int stage_v_455_1 = ((pub_r001592_21_1 * 2) + 5) & 63;
  int stage_v_455_2 = ((pub_r001592_21_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_455_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_455_2) & 127;
  int stage_v_456_1 = ((pub_r001592_13_1 * 2) + 44) & 63;
  int stage_v_456_2 = ((pub_r001592_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_456_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_456_2) & 127;
  int stage_v_457_1 = ((pub_r001592_18_1 * 2) + 47) & 63;
  int stage_v_457_2 = ((pub_r001592_18_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_457_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_457_2) & 127;
  int stage_v_458_1 = (((stage_v_80_1 * 3) + pub_r001592_7_1) + 26) & 127;
  int stage_v_458_2 = (((stage_v_80_2 * 3) + pub_r001592_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_458_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_458_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_458_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_458_2 * 2)) & 255;
  int stage_v_459_1 = (((stage_v_388_1 * 3) + pub_r001592_22_1) + 4) & 127;
  int stage_v_459_2 = (((stage_v_388_2 * 3) + pub_r001592_22_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_459_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_459_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_459_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_459_2 * 2)) & 255;
  int stage_v_460_1 = (((stage_v_115_1 * 3) + pub_r001592_9_1) + 29) & 127;
  int stage_v_460_2 = (((stage_v_115_2 * 3) + pub_r001592_9_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_460_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_460_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_460_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_460_2 * 2)) & 255;
  int stage_v_461_1 = ((pub_r001592_5_1 * 2) + 33) & 63;
  int stage_v_461_2 = ((pub_r001592_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = (((sec_r001592_19_1 * 3) + pub_r001592_3_1) + 16) & 127;
  int stage_v_462_2 = (((sec_r001592_19_2 * 3) + pub_r001592_3_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_462_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_462_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_462_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_462_2 * 2)) & 255;
  int stage_v_463_1 = (((stage_v_138_1 * 3) + pub_r001592_4_1) + 25) & 127;
  int stage_v_463_2 = (((stage_v_138_2 * 3) + pub_r001592_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_463_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_463_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_463_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_463_2 * 2)) & 255;
  int stage_v_464_1 = ((pub_r001592_1_1 * 2) + 13) & 63;
  int stage_v_464_2 = ((pub_r001592_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_464_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_464_2) & 127;
  int stage_v_465_1 = (((stage_v_355_1 * 3) + pub_r001592_15_1) + 22) & 127;
  int stage_v_465_2 = (((stage_v_355_2 * 3) + pub_r001592_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_465_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_465_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_465_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_465_2 * 2)) & 255;
  int stage_v_466_1 = (((stage_v_201_1 * 3) + pub_r001592_2_1) + 44) & 127;
  int stage_v_466_2 = (((stage_v_201_2 * 3) + pub_r001592_2_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_466_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_466_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_466_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_466_2 * 2)) & 255;
  int stage_v_467_1 = (((stage_v_153_1 * 3) + pub_r001592_12_1) + 24) & 127;
  int stage_v_467_2 = (((stage_v_153_2 * 3) + pub_r001592_12_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_467_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_467_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_467_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_467_2 * 2)) & 255;
  int stage_v_468_1 = ((pub_r001592_0_1 * 2) + 18) & 63;
  int stage_v_468_2 = ((pub_r001592_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_468_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_468_2) & 127;
  int stage_v_469_1 = ((pub_r001592_20_1 * 2) + 10) & 63;
  int stage_v_469_2 = ((pub_r001592_20_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_469_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_469_2) & 127;
  int stage_v_470_1 = ((pub_r001592_4_1 * 2) + 12) & 63;
  int stage_v_470_2 = ((pub_r001592_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_470_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_470_2) & 127;
  int stage_v_471_1 = (((stage_v_411_1 * 3) + pub_r001592_7_1) + 26) & 127;
  int stage_v_471_2 = (((stage_v_411_2 * 3) + pub_r001592_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_471_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_471_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_471_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_471_2 * 2)) & 255;
  int stage_v_472_1 = ((pub_r001592_11_1 * 2) + 13) & 63;
  int stage_v_472_2 = ((pub_r001592_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_472_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_472_2) & 127;
  int stage_v_473_1 = ((pub_r001592_15_1 * 2) + 45) & 63;
  int stage_v_473_2 = ((pub_r001592_15_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_473_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_473_2) & 127;
  int stage_v_474_1 = (((stage_v_463_1 * 3) + pub_r001592_16_1) + 16) & 127;
  int stage_v_474_2 = (((stage_v_463_2 * 3) + pub_r001592_16_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_474_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_474_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_474_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_474_2 * 2)) & 255;
  int stage_v_475_1 = (((stage_v_388_1 * 3) + pub_r001592_22_1) + 36) & 127;
  int stage_v_475_2 = (((stage_v_388_2 * 3) + pub_r001592_22_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_475_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_475_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_475_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_475_2 * 2)) & 255;
  int stage_v_476_1 = ((pub_r001592_20_1 * 2) + 47) & 63;
  int stage_v_476_2 = ((pub_r001592_20_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_476_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_476_2) & 127;
  int stage_v_477_1 = ((pub_r001592_1_1 * 2) + 35) & 63;
  int stage_v_477_2 = ((pub_r001592_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_477_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_477_2) & 127;
  int stage_v_478_1 = (((stage_v_338_1 * 3) + pub_r001592_10_1) + 36) & 127;
  int stage_v_478_2 = (((stage_v_338_2 * 3) + pub_r001592_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_478_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_478_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_478_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_478_2 * 2)) & 255;
  int stage_v_479_1 = (((sec_r001592_3_1 * 3) + pub_r001592_5_1) + 27) & 127;
  int stage_v_479_2 = (((sec_r001592_3_2 * 3) + pub_r001592_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_479_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_479_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_479_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_479_2 * 2)) & 255;
  int stage_v_480_1 = ((pub_r001592_12_1 * 2) + 14) & 63;
  int stage_v_480_2 = ((pub_r001592_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_480_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_480_2) & 127;
  int stage_v_481_1 = ((pub_r001592_15_1 * 2) + 25) & 63;
  int stage_v_481_2 = ((pub_r001592_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_481_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_481_2) & 127;
  int stage_v_482_1 = ((pub_r001592_14_1 * 2) + 8) & 63;
  int stage_v_482_2 = ((pub_r001592_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_482_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_482_2) & 127;
  int stage_v_483_1 = ((pub_r001592_11_1 * 2) + 50) & 63;
  int stage_v_483_2 = ((pub_r001592_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_483_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_483_2) & 127;
  int stage_v_484_1 = (((stage_v_411_1 * 3) + pub_r001592_10_1) + 29) & 127;
  int stage_v_484_2 = (((stage_v_411_2 * 3) + pub_r001592_10_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_484_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_484_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_484_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_484_2 * 2)) & 255;
  int stage_v_485_1 = ((pub_r001592_23_1 * 2) + 21) & 63;
  int stage_v_485_2 = ((pub_r001592_23_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_485_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_485_2) & 127;
  int stage_v_486_1 = ((pub_r001592_5_1 * 2) + 15) & 63;
  int stage_v_486_2 = ((pub_r001592_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_486_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_486_2) & 127;
  int stage_v_487_1 = (((stage_v_316_1 * 3) + pub_r001592_3_1) + 4) & 127;
  int stage_v_487_2 = (((stage_v_316_2 * 3) + pub_r001592_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_487_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_487_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_487_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_487_2 * 2)) & 255;
  int stage_v_488_1 = (((stage_v_224_1 * 3) + pub_r001592_2_1) + 5) & 127;
  int stage_v_488_2 = (((stage_v_224_2 * 3) + pub_r001592_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_488_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_488_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_488_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_488_2 * 2)) & 255;
  int stage_v_489_1 = ((pub_r001592_0_1 * 2) + 37) & 63;
  int stage_v_489_2 = ((pub_r001592_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_489_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_489_2) & 127;
  int stage_v_490_1 = (((stage_v_143_1 * 3) + pub_r001592_17_1) + 5) & 127;
  int stage_v_490_2 = (((stage_v_143_2 * 3) + pub_r001592_17_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_490_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_490_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_490_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_490_2 * 2)) & 255;
  int stage_v_491_1 = ((pub_r001592_2_1 * 2) + 36) & 63;
  int stage_v_491_2 = ((pub_r001592_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_491_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_491_2) & 127;
  int stage_v_492_1 = (((stage_v_134_1 * 3) + pub_r001592_2_1) + 3) & 127;
  int stage_v_492_2 = (((stage_v_134_2 * 3) + pub_r001592_2_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_492_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_492_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_492_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_492_2 * 2)) & 255;
  int stage_v_493_1 = (((stage_v_191_1 * 3) + pub_r001592_23_1) + 13) & 127;
  int stage_v_493_2 = (((stage_v_191_2 * 3) + pub_r001592_23_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_493_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_493_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_493_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_493_2 * 2)) & 255;
  int stage_v_494_1 = (((stage_v_291_1 * 3) + pub_r001592_3_1) + 8) & 127;
  int stage_v_494_2 = (((stage_v_291_2 * 3) + pub_r001592_3_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_494_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_494_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_494_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_494_2 * 2)) & 255;
  int stage_v_495_1 = ((pub_r001592_13_1 * 2) + 21) & 63;
  int stage_v_495_2 = ((pub_r001592_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_495_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_495_2) & 127;
  int stage_v_496_1 = (((sec_r001592_14_1 * 3) + pub_r001592_0_1) + 23) & 127;
  int stage_v_496_2 = (((sec_r001592_14_2 * 3) + pub_r001592_0_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_496_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_496_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_496_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_496_2 * 2)) & 255;
  int stage_v_497_1 = ((pub_r001592_23_1 * 2) + 10) & 63;
  int stage_v_497_2 = ((pub_r001592_23_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_497_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_497_2) & 127;
  int stage_v_498_1 = ((pub_r001592_3_1 * 2) + 30) & 63;
  int stage_v_498_2 = ((pub_r001592_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_498_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_498_2) & 127;
  int stage_v_499_1 = ((pub_r001592_8_1 * 2) + 33) & 63;
  int stage_v_499_2 = ((pub_r001592_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_499_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_499_2) & 127;
  int stage_v_500_1 = (((stage_v_236_1 * 3) + pub_r001592_12_1) + 21) & 127;
  int stage_v_500_2 = (((stage_v_236_2 * 3) + pub_r001592_12_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_500_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_500_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_500_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_500_2 * 2)) & 255;
  int stage_v_501_1 = (((sec_r001592_17_1 * 3) + pub_r001592_23_1) + 15) & 127;
  int stage_v_501_2 = (((sec_r001592_17_2 * 3) + pub_r001592_23_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_501_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_501_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_501_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_501_2 * 2)) & 255;
  int stage_v_502_1 = ((pub_r001592_20_1 * 2) + 43) & 63;
  int stage_v_502_2 = ((pub_r001592_20_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_502_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_502_2) & 127;
  int stage_v_503_1 = ((pub_r001592_8_1 * 2) + 31) & 63;
  int stage_v_503_2 = ((pub_r001592_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_503_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_503_2) & 127;
  int stage_v_504_1 = ((pub_r001592_0_1 * 2) + 42) & 63;
  int stage_v_504_2 = ((pub_r001592_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_504_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_504_2) & 127;
  int stage_v_505_1 = ((pub_r001592_16_1 * 2) + 18) & 63;
  int stage_v_505_2 = ((pub_r001592_16_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_505_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_505_2) & 127;
  int stage_v_506_1 = (((stage_v_153_1 * 3) + pub_r001592_7_1) + 35) & 127;
  int stage_v_506_2 = (((stage_v_153_2 * 3) + pub_r001592_7_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_506_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_506_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_506_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_506_2 * 2)) & 255;
  int stage_v_507_1 = (((stage_v_4_1 * 3) + pub_r001592_13_1) + 20) & 127;
  int stage_v_507_2 = (((stage_v_4_2 * 3) + pub_r001592_13_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_507_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_507_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_507_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_507_2 * 2)) & 255;
  int stage_v_508_1 = (((stage_v_354_1 * 3) + pub_r001592_10_1) + 21) & 127;
  int stage_v_508_2 = (((stage_v_354_2 * 3) + pub_r001592_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_508_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_508_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_508_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_508_2 * 2)) & 255;
  int stage_v_509_1 = (((stage_v_242_1 * 3) + pub_r001592_14_1) + 41) & 127;
  int stage_v_509_2 = (((stage_v_242_2 * 3) + pub_r001592_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_509_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_509_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_509_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_509_2 * 2)) & 255;
  int stage_v_510_1 = ((pub_r001592_18_1 * 2) + 45) & 63;
  int stage_v_510_2 = ((pub_r001592_18_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_510_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_510_2) & 127;
  int stage_v_511_1 = ((pub_r001592_21_1 * 2) + 24) & 63;
  int stage_v_511_2 = ((pub_r001592_21_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_511_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_511_2) & 127;
  int stage_v_512_1 = ((pub_r001592_22_1 * 2) + 25) & 63;
  int stage_v_512_2 = ((pub_r001592_22_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_512_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_512_2) & 127;
  int stage_v_513_1 = (((stage_v_61_1 * 3) + pub_r001592_4_1) + 26) & 127;
  int stage_v_513_2 = (((stage_v_61_2 * 3) + pub_r001592_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_513_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_513_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_513_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_513_2 * 2)) & 255;
  int stage_v_514_1 = ((pub_r001592_9_1 * 2) + 27) & 63;
  int stage_v_514_2 = ((pub_r001592_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_514_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_514_2) & 127;
  int stage_v_515_1 = (((stage_v_223_1 * 3) + pub_r001592_14_1) + 37) & 127;
  int stage_v_515_2 = (((stage_v_223_2 * 3) + pub_r001592_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_515_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_515_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_515_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_515_2 * 2)) & 255;
  int stage_v_516_1 = ((pub_r001592_17_1 * 2) + 7) & 63;
  int stage_v_516_2 = ((pub_r001592_17_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_516_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_516_2) & 127;
  int stage_v_517_1 = ((pub_r001592_8_1 * 2) + 27) & 63;
  int stage_v_517_2 = ((pub_r001592_8_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_517_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_517_2) & 127;
  int stage_v_518_1 = (((sec_r001592_3_1 * 3) + pub_r001592_15_1) + 23) & 127;
  int stage_v_518_2 = (((sec_r001592_3_2 * 3) + pub_r001592_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_518_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_518_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_518_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_518_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001592_8_1 != sec_r001592_8_2);
  __CPROVER_assume(sec_r001592_4_1 != sec_r001592_4_2);
  __CPROVER_assume(pub_r001592_11_1 == pub_r001592_11_2);
  __CPROVER_assume(sec_r001592_12_1 != sec_r001592_12_2);
  __CPROVER_assume(sec_r001592_19_1 != sec_r001592_19_2);
  __CPROVER_assume(sec_r001592_1_1 != sec_r001592_1_2);
  __CPROVER_assume(pub_r001592_21_1 == pub_r001592_21_2);
  __CPROVER_assume(sec_r001592_15_1 != sec_r001592_15_2);
  __CPROVER_assume(pub_r001592_9_1 == pub_r001592_9_2);
  __CPROVER_assume(pub_r001592_16_1 == pub_r001592_16_2);
  __CPROVER_assume(pub_r001592_18_1 == pub_r001592_18_2);
  __CPROVER_assume(sec_r001592_17_1 != sec_r001592_17_2);
  __CPROVER_assume(sec_r001592_10_1 != sec_r001592_10_2);
  __CPROVER_assume(sec_r001592_18_1 != sec_r001592_18_2);
  __CPROVER_assume(pub_r001592_12_1 == pub_r001592_12_2);
  __CPROVER_assume(pub_r001592_5_1 == pub_r001592_5_2);
  __CPROVER_assume(pub_r001592_7_1 == pub_r001592_7_2);
  __CPROVER_assume(sec_r001592_6_1 != sec_r001592_6_2);
  __CPROVER_assume(pub_r001592_23_1 == pub_r001592_23_2);
  __CPROVER_assume(sec_r001592_11_1 != sec_r001592_11_2);
  __CPROVER_assume(sec_r001592_5_1 != sec_r001592_5_2);
  __CPROVER_assume(sec_r001592_21_1 != sec_r001592_21_2);
  __CPROVER_assume(pub_r001592_4_1 == pub_r001592_4_2);
  __CPROVER_assume(pub_r001592_13_1 == pub_r001592_13_2);
  __CPROVER_assume(pub_r001592_10_1 == pub_r001592_10_2);
  __CPROVER_assume(pub_r001592_8_1 == pub_r001592_8_2);
  __CPROVER_assume(pub_r001592_17_1 == pub_r001592_17_2);
  __CPROVER_assume(pub_r001592_15_1 == pub_r001592_15_2);
  __CPROVER_assume(sec_r001592_22_1 != sec_r001592_22_2);
  __CPROVER_assume(pub_r001592_6_1 == pub_r001592_6_2);
  __CPROVER_assume(sec_r001592_20_1 != sec_r001592_20_2);
  __CPROVER_assume(pub_r001592_14_1 == pub_r001592_14_2);
  __CPROVER_assume(sec_r001592_13_1 != sec_r001592_13_2);
  __CPROVER_assume(pub_r001592_19_1 == pub_r001592_19_2);
  __CPROVER_assume(pub_r001592_0_1 == pub_r001592_0_2);
  __CPROVER_assume(pub_r001592_3_1 == pub_r001592_3_2);
  __CPROVER_assume(pub_r001592_1_1 == pub_r001592_1_2);
  __CPROVER_assume(sec_r001592_0_1 != sec_r001592_0_2);
  __CPROVER_assume(pub_r001592_22_1 == pub_r001592_22_2);
  __CPROVER_assume(sec_r001592_16_1 != sec_r001592_16_2);
  __CPROVER_assume(pub_r001592_2_1 == pub_r001592_2_2);
  __CPROVER_assume(sec_r001592_7_1 != sec_r001592_7_2);
  __CPROVER_assume(pub_r001592_20_1 == pub_r001592_20_2);
  __CPROVER_assume(sec_r001592_9_1 != sec_r001592_9_2);
  __CPROVER_assume(sec_r001592_14_1 != sec_r001592_14_2);
  __CPROVER_assume(sec_r001592_2_1 != sec_r001592_2_2);
  __CPROVER_assume(sec_r001592_3_1 != sec_r001592_3_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.head == st_var_1_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.timestamp == st_var_2_2.timestamp);
  assert(st_var_2_1.signature == st_var_2_2.signature);
  assert(st_var_2_1.code == st_var_2_2.code);
  assert(st_var_2_1.severity == st_var_2_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.rms == st_var_3_2.rms);
  assert(st_var_3_1.sample_rate == st_var_3_2.sample_rate);
  assert(st_var_3_1.peak == st_var_3_2.peak);
  assert(st_var_3_1.gain == st_var_3_2.gain);
  assert(st_var_3_1.channels == st_var_3_2.channels);
  assert(st_var_3_1.envelope == st_var_3_2.envelope);
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
  assert(stage_v_437_1 == stage_v_437_2);
  assert(stage_v_438_1 == stage_v_438_2);
  assert(stage_v_439_1 == stage_v_439_2);
  assert(stage_v_440_1 == stage_v_440_2);
  assert(stage_v_441_1 == stage_v_441_2);
  assert(stage_v_442_1 == stage_v_442_2);
  assert(stage_v_443_1 == stage_v_443_2);
  assert(stage_v_444_1 == stage_v_444_2);
  assert(stage_v_445_1 == stage_v_445_2);
  assert(stage_v_446_1 == stage_v_446_2);
  assert(stage_v_447_1 == stage_v_447_2);
  assert(stage_v_448_1 == stage_v_448_2);
  assert(stage_v_449_1 == stage_v_449_2);
  assert(stage_v_450_1 == stage_v_450_2);
  assert(stage_v_451_1 == stage_v_451_2);
  assert(stage_v_452_1 == stage_v_452_2);
  assert(stage_v_453_1 == stage_v_453_2);
  assert(stage_v_454_1 == stage_v_454_2);
  assert(stage_v_455_1 == stage_v_455_2);
  assert(stage_v_456_1 == stage_v_456_2);
  assert(stage_v_457_1 == stage_v_457_2);
  assert(stage_v_458_1 == stage_v_458_2);
  assert(stage_v_459_1 == stage_v_459_2);
  assert(stage_v_460_1 == stage_v_460_2);
  assert(stage_v_461_1 == stage_v_461_2);
  assert(stage_v_462_1 == stage_v_462_2);
  assert(stage_v_463_1 == stage_v_463_2);
  assert(stage_v_464_1 == stage_v_464_2);
  assert(stage_v_465_1 == stage_v_465_2);
  assert(stage_v_466_1 == stage_v_466_2);
  assert(stage_v_467_1 == stage_v_467_2);
  assert(stage_v_468_1 == stage_v_468_2);
  assert(stage_v_469_1 == stage_v_469_2);
  assert(stage_v_470_1 == stage_v_470_2);
  assert(stage_v_471_1 == stage_v_471_2);
  assert(stage_v_472_1 == stage_v_472_2);
  assert(stage_v_473_1 == stage_v_473_2);
  assert(stage_v_474_1 == stage_v_474_2);
  assert(stage_v_475_1 == stage_v_475_2);
  assert(stage_v_476_1 == stage_v_476_2);
  assert(stage_v_477_1 == stage_v_477_2);
  assert(stage_v_478_1 == stage_v_478_2);
  assert(stage_v_479_1 == stage_v_479_2);
  assert(stage_v_480_1 == stage_v_480_2);
  assert(stage_v_481_1 == stage_v_481_2);
  assert(stage_v_482_1 == stage_v_482_2);
  assert(stage_v_483_1 == stage_v_483_2);
  assert(stage_v_484_1 == stage_v_484_2);
  assert(stage_v_485_1 == stage_v_485_2);
  assert(stage_v_486_1 == stage_v_486_2);
  assert(stage_v_487_1 == stage_v_487_2);
  assert(stage_v_488_1 == stage_v_488_2);
  assert(stage_v_489_1 == stage_v_489_2);
  assert(stage_v_490_1 == stage_v_490_2);
  assert(stage_v_491_1 == stage_v_491_2);
  assert(stage_v_492_1 == stage_v_492_2);
  assert(stage_v_493_1 == stage_v_493_2);
  assert(stage_v_494_1 == stage_v_494_2);
  assert(stage_v_495_1 == stage_v_495_2);
  assert(stage_v_496_1 == stage_v_496_2);
  assert(stage_v_497_1 == stage_v_497_2);
  assert(stage_v_498_1 == stage_v_498_2);
  assert(stage_v_499_1 == stage_v_499_2);
  assert(stage_v_500_1 == stage_v_500_2);
  assert(stage_v_501_1 == stage_v_501_2);
  assert(stage_v_502_1 == stage_v_502_2);
  assert(stage_v_503_1 == stage_v_503_2);
  assert(stage_v_504_1 == stage_v_504_2);
  assert(stage_v_505_1 == stage_v_505_2);
  assert(stage_v_506_1 == stage_v_506_2);
  assert(stage_v_507_1 == stage_v_507_2);
  assert(stage_v_508_1 == stage_v_508_2);
  assert(stage_v_509_1 == stage_v_509_2);
  assert(stage_v_510_1 == stage_v_510_2);
  assert(stage_v_511_1 == stage_v_511_2);
  assert(stage_v_512_1 == stage_v_512_2);
  assert(stage_v_513_1 == stage_v_513_2);
  assert(stage_v_514_1 == stage_v_514_2);
  assert(stage_v_515_1 == stage_v_515_2);
  assert(stage_v_516_1 == stage_v_516_2);
  assert(stage_v_517_1 == stage_v_517_2);
  assert(stage_v_518_1 == stage_v_518_2);
}


