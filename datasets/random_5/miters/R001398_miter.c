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
struct SensorNode_R001398_9813_0
{
  int calib;
  short gain;
  int threshold;
  int reading;
  int status;
  int buffer[3];
};
struct FilterState_R001398_9813_1
{
  short mode;
  int prev_out;
  int damping;
  short prev_in;
  int buffer[3];
};
struct DeviceConfig_R001398_9813_2
{
  short id;
  unsigned char baud_rate;
  short timeout;
  int buffer[3];
};
struct Vector3D_R001398_9813_3
{
  short pitch;
  int heading;
  unsigned char coord_z;
  int coord_y;
  int coord_x;
  unsigned char norm_sq;
  int buffer[3];
};
union PacketPayload_R001398_9813_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R001398_9813_1
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
void fn_R001398_9813_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001398_9813_1 st_1 = {0};
  struct FilterState_R001398_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_26_1 > 22)
  {
    acc_1 = ((acc_1 + (tracker_26_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_26_2 > 22)
  {
    acc_2 = ((acc_2 + (tracker_26_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_49_1 = 0;
  int offset_49_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_49_1 = ((offset_49_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_49_2 = ((offset_49_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_49_1) & 127;
    acc_2 = (acc_2 + offset_49_2) & 127;
  }

  int coefficient_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_13_1) & 63;
  aux_2 = (aux_2 + coefficient_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_26_1 == tracker_26_2);
  assert(offset_49_1 == offset_49_2);
  assert(coefficient_13_1 == coefficient_13_2);
}

int fn_R001398_9813_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001398_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_26 > 22)
  {
    acc = ((acc + (tracker_26 * 2)) + 5) & 127;
    aux ^= tracker_26 & 15;
  }
  else
  {
    acc = ((acc - tracker_26) + 11) & 127;
    aux += 3;
  }
  int offset_49 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_49 = ((offset_49 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_49) & 127;
  }

  int coefficient_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_13) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001398_9813_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001398_9813_2 st_1 = {0};
  struct DeviceConfig_R001398_9813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int window_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_58_1) & 63;
  aux_2 = (aux_2 + window_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_53_1 > 13)
  {
    acc_1 = ((acc_1 + (quantum_53_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_53_2 > 13)
  {
    acc_2 = ((acc_2 + (quantum_53_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_53_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_58_1 == window_58_2);
  assert(quantum_53_1 == quantum_53_2);
}

int fn_R001398_9813_1(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001398_9813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int window_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_58) & 63;
  acc ^= aux;
  int quantum_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_53 > 13)
  {
    acc = ((acc + (quantum_53 * 2)) + 5) & 127;
    aux ^= quantum_53 & 15;
  }
  else
  {
    acc = ((acc - quantum_53) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001398_9813_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001398_9813_3 st_1 = {0};
  struct Vector3D_R001398_9813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int factor_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_34_1)
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

  switch (factor_34_2)
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

  int quantum_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_38_1 > 50)
  {
    acc_1 = ((acc_1 + (quantum_38_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_38_2 > 50)
  {
    acc_2 = ((acc_2 + (quantum_38_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_66_1 = local_arr_1[aux_1 % 3];
  int metric_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_66_2 * 2)) & 127;
  int stride_28_1 = 0;
  int stride_28_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_28_1 = ((stride_28_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_28_2 = ((stride_28_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_28_1) & 127;
    acc_2 = (acc_2 + stride_28_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_34_1 == factor_34_2);
  assert(quantum_38_1 == quantum_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_66_1 == metric_66_2);
  assert(stride_28_1 == stride_28_2);
}

int fn_R001398_9813_2(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001398_9813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int factor_34 = (aux + st.buffer[1]) & 3;
  switch (factor_34)
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

  int quantum_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_38 > 50)
  {
    acc = ((acc + (quantum_38 * 2)) + 5) & 127;
    aux ^= quantum_38 & 15;
  }
  else
  {
    acc = ((acc - quantum_38) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_66 = local_arr[aux % 3];
  acc = (acc + (metric_66 * 2)) & 127;
  int stride_28 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_28 = ((stride_28 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_28) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001398_9813_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001398_9813_1 st_1 = {0};
  struct FilterState_R001398_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_89_1)
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

  switch (tally_89_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_89_1 == tally_89_2);
}

int fn_R001398_9813_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001398_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_89 = (aux + st.buffer[1]) & 3;
  switch (tally_89)
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

void fn_R001398_9813_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001398_9813_0 st_1 = {0};
  struct SensorNode_R001398_9813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_65_1 = local_arr_1[aux_1 % 3];
  int mask_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_65_2 * 2)) & 127;
  int parity_75_1 = 0;
  int parity_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_75_1 = ((parity_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_75_2 = ((parity_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_75_1) & 127;
    acc_2 = (acc_2 + parity_75_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_65_1 == mask_65_2);
  assert(parity_75_1 == parity_75_2);
}

int fn_R001398_9813_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001398_9813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int mask_65 = local_arr[aux % 3];
  acc = (acc + (mask_65 * 2)) & 127;
  int parity_75 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_75 = ((parity_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_75) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001398_9813_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001398_9813_2 st_1 = {0};
  struct DeviceConfig_R001398_9813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int checksum_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_60_1) & 63;
  aux_2 = (aux_2 + checksum_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_33_1 = local_arr_1[aux_1 % 3];
  int sample_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_33_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_60_1 == checksum_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_33_1 == sample_33_2);
}

int fn_R001398_9813_5(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001398_9813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int checksum_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_60) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_33 = local_arr[aux % 3];
  acc = (acc + (sample_33 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001398_9813_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001398_9813_3 st_1 = {0};
  struct Vector3D_R001398_9813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_36_1 = local_arr_1[aux_1 % 3];
  int damping_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_36_2 * 2)) & 127;
  int residue_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_54_1)
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

  switch (residue_54_2)
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

  int factor_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_55_1) & 63;
  aux_2 = (aux_2 + factor_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_73_1 > 26)
  {
    acc_1 = ((acc_1 + (threshold_73_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_73_2 > 26)
  {
    acc_2 = ((acc_2 + (threshold_73_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_73_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_36_1 == damping_36_2);
  assert(residue_54_1 == residue_54_2);
  assert(factor_55_1 == factor_55_2);
  assert(threshold_73_1 == threshold_73_2);
}

int fn_R001398_9813_6(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001398_9813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int damping_36 = local_arr[aux % 3];
  acc = (acc + (damping_36 * 2)) & 127;
  int residue_54 = (aux + st.buffer[1]) & 3;
  switch (residue_54)
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

  int factor_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_55) & 63;
  acc ^= aux;
  int threshold_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_73 > 26)
  {
    acc = ((acc + (threshold_73 * 2)) + 5) & 127;
    aux ^= threshold_73 & 15;
  }
  else
  {
    acc = ((acc - threshold_73) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001398_9813_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001398_9813_3 st_1 = {0};
  struct Vector3D_R001398_9813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int coefficient_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_81_1 > 43)
  {
    acc_1 = ((acc_1 + (coefficient_81_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_81_2 > 43)
  {
    acc_2 = ((acc_2 + (coefficient_81_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_81_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_14_1) & 63;
  aux_2 = (aux_2 + scale_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_72_1 = 0;
  int anchor_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_72_1 = ((anchor_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_72_2 = ((anchor_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_72_1) & 127;
    acc_2 = (acc_2 + anchor_72_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_81_1 == coefficient_81_2);
  assert(scale_14_1 == scale_14_2);
  assert(anchor_72_1 == anchor_72_2);
}

int fn_R001398_9813_7(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001398_9813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int coefficient_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_81 > 43)
  {
    acc = ((acc + (coefficient_81 * 2)) + 5) & 127;
    aux ^= coefficient_81 & 15;
  }
  else
  {
    acc = ((acc - coefficient_81) + 11) & 127;
    aux += 3;
  }
  int scale_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_14) & 63;
  acc ^= aux;
  int anchor_72 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_72 = ((anchor_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_72) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001398_9813_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001398_9813_2 st_1 = {0};
  struct DeviceConfig_R001398_9813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int sample_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_30_1 > 23)
  {
    acc_1 = ((acc_1 + (sample_30_1 * 2)) + 5) & 127;
    aux_1 ^= sample_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_30_2 > 23)
  {
    acc_2 = ((acc_2 + (sample_30_2 * 2)) + 5) & 127;
    aux_2 ^= sample_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_30_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_99_1 = 0;
  int index_reg_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_99_1 = ((index_reg_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_99_2 = ((index_reg_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_99_1) & 127;
    acc_2 = (acc_2 + index_reg_99_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_30_1 = local_arr_1[aux_1 % 3];
  int anchor_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_30_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_30_1 == sample_30_2);
  assert(index_reg_99_1 == index_reg_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_30_1 == anchor_30_2);
}

int fn_R001398_9813_8(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001398_9813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int sample_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_30 > 23)
  {
    acc = ((acc + (sample_30 * 2)) + 5) & 127;
    aux ^= sample_30 & 15;
  }
  else
  {
    acc = ((acc - sample_30) + 11) & 127;
    aux += 3;
  }
  int index_reg_99 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_99 = ((index_reg_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_99) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int anchor_30 = local_arr[aux % 3];
  acc = (acc + (anchor_30 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001398_9813_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001398_9813_0 st_1 = {0};
  struct SensorNode_R001398_9813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_72_1 = local_arr_1[aux_1 % 3];
  int parity_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_72_2 * 2)) & 127;
  int metric_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_97_1)
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

  switch (metric_97_2)
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

  int factor_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_71_1 > 10)
  {
    acc_1 = ((acc_1 + (factor_71_1 * 2)) + 5) & 127;
    aux_1 ^= factor_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_71_2 > 10)
  {
    acc_2 = ((acc_2 + (factor_71_2 * 2)) + 5) & 127;
    aux_2 ^= factor_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_71_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_72_1 == parity_72_2);
  assert(metric_97_1 == metric_97_2);
  assert(factor_71_1 == factor_71_2);
}

int fn_R001398_9813_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001398_9813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int parity_72 = local_arr[aux % 3];
  acc = (acc + (parity_72 * 2)) & 127;
  int metric_97 = (aux + st.buffer[1]) & 3;
  switch (metric_97)
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

  int factor_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_71 > 10)
  {
    acc = ((acc + (factor_71 * 2)) + 5) & 127;
    aux ^= factor_71 & 15;
  }
  else
  {
    acc = ((acc - factor_71) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001398_9813_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001398_9813_1 st_1 = {0};
  struct FilterState_R001398_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int cursor_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_50_1) & 63;
  aux_2 = (aux_2 + cursor_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_72_1 > 32)
  {
    acc_1 = ((acc_1 + (residue_72_1 * 2)) + 5) & 127;
    aux_1 ^= residue_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_72_2 > 32)
  {
    acc_2 = ((acc_2 + (residue_72_2 * 2)) + 5) & 127;
    aux_2 ^= residue_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_46_1 = 0;
  int phase_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_46_1 = ((phase_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_46_2 = ((phase_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_46_1) & 127;
    acc_2 = (acc_2 + phase_46_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_50_1 == cursor_50_2);
  assert(residue_72_1 == residue_72_2);
  assert(phase_46_1 == phase_46_2);
}

int fn_R001398_9813_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001398_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int cursor_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_50) & 63;
  acc ^= aux;
  int residue_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_72 > 32)
  {
    acc = ((acc + (residue_72 * 2)) + 5) & 127;
    aux ^= residue_72 & 15;
  }
  else
  {
    acc = ((acc - residue_72) + 11) & 127;
    aux += 3;
  }
  int phase_46 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_46 = ((phase_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_46) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001398_9813_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001398_9813_0 st_1 = {0};
  struct SensorNode_R001398_9813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_57_1 = local_arr_1[aux_1 % 3];
  int index_reg_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_57_2 * 2)) & 127;
  int index_reg_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_80_1)
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

  switch (index_reg_80_2)
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

  int pivot_50_1 = 0;
  int pivot_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_50_1 = ((pivot_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_50_2 = ((pivot_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_50_1) & 127;
    acc_2 = (acc_2 + pivot_50_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_57_1 == index_reg_57_2);
  assert(index_reg_80_1 == index_reg_80_2);
  assert(pivot_50_1 == pivot_50_2);
}

int fn_R001398_9813_11(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001398_9813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int index_reg_57 = local_arr[aux % 3];
  acc = (acc + (index_reg_57 * 2)) & 127;
  int index_reg_80 = (aux + st.buffer[1]) & 3;
  switch (index_reg_80)
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

  int pivot_50 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_50 = ((pivot_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_50) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001398_9813_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001398_9813_2 st_1 = {0};
  struct DeviceConfig_R001398_9813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_29_1 = local_arr_1[aux_1 % 3];
  int segment_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_29_2 * 2)) & 127;
  int sample_26_1 = 0;
  int sample_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_26_1 = ((sample_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_26_2 = ((sample_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_26_1) & 127;
    acc_2 = (acc_2 + sample_26_2) & 127;
  }

  int stride_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_17_1) & 63;
  aux_2 = (aux_2 + stride_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_28_1)
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

  switch (anchor_28_2)
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
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_29_1 == segment_29_2);
  assert(sample_26_1 == sample_26_2);
  assert(stride_17_1 == stride_17_2);
  assert(anchor_28_1 == anchor_28_2);
}

int fn_R001398_9813_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001398_9813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int segment_29 = local_arr[aux % 3];
  acc = (acc + (segment_29 * 2)) & 127;
  int sample_26 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_26 = ((sample_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_26) & 127;
  }

  int stride_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_17) & 63;
  acc ^= aux;
  int anchor_28 = (aux + st.buffer[1]) & 3;
  switch (anchor_28)
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

void fn_R001398_9813_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001398_9813_3 st_1 = {0};
  struct Vector3D_R001398_9813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int index_reg_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_97_1)
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

  switch (index_reg_97_2)
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

  int threshold_68_1 = 0;
  int threshold_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_68_1 = ((threshold_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_68_2 = ((threshold_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_68_1) & 127;
    acc_2 = (acc_2 + threshold_68_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_97_1 == index_reg_97_2);
  assert(threshold_68_1 == threshold_68_2);
}

int fn_R001398_9813_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001398_9813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int index_reg_97 = (aux + st.buffer[1]) & 3;
  switch (index_reg_97)
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

  int threshold_68 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_68 = ((threshold_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_68) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001398_9813_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001398_9813_1 st_1 = {0};
  struct FilterState_R001398_9813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int delta_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_82_1) & 63;
  aux_2 = (aux_2 + delta_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_37_1 = 0;
  int bound_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_37_1 = ((bound_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_37_2 = ((bound_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_37_1) & 127;
    acc_2 = (acc_2 + bound_37_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_97_1 = local_arr_1[aux_1 % 3];
  int weight_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_97_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_82_1 == delta_82_2);
  assert(bound_37_1 == bound_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_97_1 == weight_97_2);
}

int fn_R001398_9813_14(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001398_9813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int delta_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_82) & 63;
  acc ^= aux;
  int bound_37 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_37 = ((bound_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_37) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int weight_97 = local_arr[aux % 3];
  acc = (acc + (weight_97 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001398_9813_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001398_9813_2 st_1 = {0};
  struct DeviceConfig_R001398_9813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int metric_43_1 = 0;
  int metric_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_43_1 = ((metric_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_43_2 = ((metric_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_43_1) & 127;
    acc_2 = (acc_2 + metric_43_2) & 127;
  }

  int delta_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_43_1 > 38)
  {
    acc_1 = ((acc_1 + (delta_43_1 * 2)) + 5) & 127;
    aux_1 ^= delta_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_43_2 > 38)
  {
    acc_2 = ((acc_2 + (delta_43_2 * 2)) + 5) & 127;
    aux_2 ^= delta_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_54_1)
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

  switch (margin_54_2)
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

  int quantum_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_47_1) & 63;
  aux_2 = (aux_2 + quantum_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_43_1 == metric_43_2);
  assert(delta_43_1 == delta_43_2);
  assert(margin_54_1 == margin_54_2);
  assert(quantum_47_1 == quantum_47_2);
}

int fn_R001398_9813_15(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001398_9813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int metric_43 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_43 = ((metric_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_43) & 127;
  }

  int delta_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_43 > 38)
  {
    acc = ((acc + (delta_43 * 2)) + 5) & 127;
    aux ^= delta_43 & 15;
  }
  else
  {
    acc = ((acc - delta_43) + 11) & 127;
    aux += 3;
  }
  int margin_54 = (aux + st.buffer[1]) & 3;
  switch (margin_54)
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

  int quantum_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_47) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001398_9813_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001398_9813_0 st_1 = {0};
  struct SensorNode_R001398_9813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int accumulator_32_1 = 0;
  int accumulator_32_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_32_1 = ((accumulator_32_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_32_2 = ((accumulator_32_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_32_1) & 127;
    acc_2 = (acc_2 + accumulator_32_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_32_1 == accumulator_32_2);
}

int fn_R001398_9813_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001398_9813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int accumulator_32 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_32 = ((accumulator_32 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_32) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001398_9813_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001398_9813_3 st_1 = {0};
  struct Vector3D_R001398_9813_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_72_1 = local_arr_1[aux_1 % 3];
  int quantum_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_72_2 * 2)) & 127;
  int offset_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_53_1 > 46)
  {
    acc_1 = ((acc_1 + (offset_53_1 * 2)) + 5) & 127;
    aux_1 ^= offset_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_53_2 > 46)
  {
    acc_2 = ((acc_2 + (offset_53_2 * 2)) + 5) & 127;
    aux_2 ^= offset_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_53_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_72_1 == quantum_72_2);
  assert(offset_53_1 == offset_53_2);
}

int fn_R001398_9813_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001398_9813_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int quantum_72 = local_arr[aux % 3];
  acc = (acc + (quantum_72 * 2)) & 127;
  int offset_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_53 > 46)
  {
    acc = ((acc + (offset_53 * 2)) + 5) & 127;
    aux ^= offset_53 & 15;
  }
  else
  {
    acc = ((acc - offset_53) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001398_0_1;
  int sec_r001398_0_2;
  int sec_r001398_1_1;
  int sec_r001398_1_2;
  int sec_r001398_2_1;
  int sec_r001398_2_2;
  int sec_r001398_3_1;
  int sec_r001398_3_2;
  int sec_r001398_4_1;
  int sec_r001398_4_2;
  int sec_r001398_5_1;
  int sec_r001398_5_2;
  int sec_r001398_6_1;
  int sec_r001398_6_2;
  int sec_r001398_7_1;
  int sec_r001398_7_2;
  int sec_r001398_8_1;
  int sec_r001398_8_2;
  int sec_r001398_9_1;
  int sec_r001398_9_2;
  int sec_r001398_10_1;
  int sec_r001398_10_2;
  int sec_r001398_11_1;
  int sec_r001398_11_2;
  int sec_r001398_12_1;
  int sec_r001398_12_2;
  int sec_r001398_13_1;
  int sec_r001398_13_2;
  int sec_r001398_14_1;
  int sec_r001398_14_2;
  int sec_r001398_15_1;
  int sec_r001398_15_2;
  int sec_r001398_16_1;
  int sec_r001398_16_2;
  int sec_r001398_17_1;
  int sec_r001398_17_2;
  int sec_r001398_18_1;
  int sec_r001398_18_2;
  int sec_r001398_19_1;
  int sec_r001398_19_2;
  int pub_r001398_0_1;
  int pub_r001398_0_2;
  int pub_r001398_1_1;
  int pub_r001398_1_2;
  int pub_r001398_2_1;
  int pub_r001398_2_2;
  int pub_r001398_3_1;
  int pub_r001398_3_2;
  int pub_r001398_4_1;
  int pub_r001398_4_2;
  int pub_r001398_5_1;
  int pub_r001398_5_2;
  int pub_r001398_6_1;
  int pub_r001398_6_2;
  int pub_r001398_7_1;
  int pub_r001398_7_2;
  int pub_r001398_8_1;
  int pub_r001398_8_2;
  int pub_r001398_9_1;
  int pub_r001398_9_2;
  int pub_r001398_10_1;
  int pub_r001398_10_2;
  int pub_r001398_11_1;
  int pub_r001398_11_2;
  int pub_r001398_12_1;
  int pub_r001398_12_2;
  int pub_r001398_13_1;
  int pub_r001398_13_2;
  int pub_r001398_14_1;
  int pub_r001398_14_2;
  int pub_r001398_15_1;
  int pub_r001398_15_2;
  int pub_r001398_16_1;
  int pub_r001398_16_2;
  int pub_r001398_17_1;
  int pub_r001398_17_2;
  int pub_r001398_18_1;
  int pub_r001398_18_2;
  int pub_r001398_19_1;
  int pub_r001398_19_2;
  int pub_r001398_20_1;
  int pub_r001398_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001398_0_1 >= (-100)) && (pub_r001398_0_1 <= 100));
  __CPROVER_assume((pub_r001398_0_2 >= (-100)) && (pub_r001398_0_2 <= 100));
  __CPROVER_assume((pub_r001398_1_1 >= (-100)) && (pub_r001398_1_1 <= 100));
  __CPROVER_assume((pub_r001398_1_2 >= (-100)) && (pub_r001398_1_2 <= 100));
  __CPROVER_assume((pub_r001398_2_1 >= (-100)) && (pub_r001398_2_1 <= 100));
  __CPROVER_assume((pub_r001398_2_2 >= (-100)) && (pub_r001398_2_2 <= 100));
  __CPROVER_assume((pub_r001398_3_1 >= (-100)) && (pub_r001398_3_1 <= 100));
  __CPROVER_assume((pub_r001398_3_2 >= (-100)) && (pub_r001398_3_2 <= 100));
  __CPROVER_assume((pub_r001398_4_1 >= (-100)) && (pub_r001398_4_1 <= 100));
  __CPROVER_assume((pub_r001398_4_2 >= (-100)) && (pub_r001398_4_2 <= 100));
  __CPROVER_assume((pub_r001398_5_1 >= (-100)) && (pub_r001398_5_1 <= 100));
  __CPROVER_assume((pub_r001398_5_2 >= (-100)) && (pub_r001398_5_2 <= 100));
  __CPROVER_assume((pub_r001398_6_1 >= (-100)) && (pub_r001398_6_1 <= 100));
  __CPROVER_assume((pub_r001398_6_2 >= (-100)) && (pub_r001398_6_2 <= 100));
  __CPROVER_assume((pub_r001398_7_1 >= (-100)) && (pub_r001398_7_1 <= 100));
  __CPROVER_assume((pub_r001398_7_2 >= (-100)) && (pub_r001398_7_2 <= 100));
  __CPROVER_assume((pub_r001398_8_1 >= (-100)) && (pub_r001398_8_1 <= 100));
  __CPROVER_assume((pub_r001398_8_2 >= (-100)) && (pub_r001398_8_2 <= 100));
  __CPROVER_assume((pub_r001398_9_1 >= (-100)) && (pub_r001398_9_1 <= 100));
  __CPROVER_assume((pub_r001398_9_2 >= (-100)) && (pub_r001398_9_2 <= 100));
  __CPROVER_assume((pub_r001398_10_1 >= (-100)) && (pub_r001398_10_1 <= 100));
  __CPROVER_assume((pub_r001398_10_2 >= (-100)) && (pub_r001398_10_2 <= 100));
  __CPROVER_assume((pub_r001398_11_1 >= (-100)) && (pub_r001398_11_1 <= 100));
  __CPROVER_assume((pub_r001398_11_2 >= (-100)) && (pub_r001398_11_2 <= 100));
  __CPROVER_assume((pub_r001398_12_1 >= (-100)) && (pub_r001398_12_1 <= 100));
  __CPROVER_assume((pub_r001398_12_2 >= (-100)) && (pub_r001398_12_2 <= 100));
  __CPROVER_assume((pub_r001398_13_1 >= (-100)) && (pub_r001398_13_1 <= 100));
  __CPROVER_assume((pub_r001398_13_2 >= (-100)) && (pub_r001398_13_2 <= 100));
  __CPROVER_assume((pub_r001398_14_1 >= (-100)) && (pub_r001398_14_1 <= 100));
  __CPROVER_assume((pub_r001398_14_2 >= (-100)) && (pub_r001398_14_2 <= 100));
  __CPROVER_assume((pub_r001398_15_1 >= (-100)) && (pub_r001398_15_1 <= 100));
  __CPROVER_assume((pub_r001398_15_2 >= (-100)) && (pub_r001398_15_2 <= 100));
  __CPROVER_assume((pub_r001398_16_1 >= (-100)) && (pub_r001398_16_1 <= 100));
  __CPROVER_assume((pub_r001398_16_2 >= (-100)) && (pub_r001398_16_2 <= 100));
  __CPROVER_assume((pub_r001398_17_1 >= (-100)) && (pub_r001398_17_1 <= 100));
  __CPROVER_assume((pub_r001398_17_2 >= (-100)) && (pub_r001398_17_2 <= 100));
  __CPROVER_assume((pub_r001398_18_1 >= (-100)) && (pub_r001398_18_1 <= 100));
  __CPROVER_assume((pub_r001398_18_2 >= (-100)) && (pub_r001398_18_2 <= 100));
  __CPROVER_assume((pub_r001398_19_1 >= (-100)) && (pub_r001398_19_1 <= 100));
  __CPROVER_assume((pub_r001398_19_2 >= (-100)) && (pub_r001398_19_2 <= 100));
  __CPROVER_assume((pub_r001398_20_1 >= (-100)) && (pub_r001398_20_1 <= 100));
  __CPROVER_assume((pub_r001398_20_2 >= (-100)) && (pub_r001398_20_2 <= 100));
  __CPROVER_assume((sec_r001398_0_1 >= 0) && (sec_r001398_0_1 <= 255));
  __CPROVER_assume((sec_r001398_0_2 >= 0) && (sec_r001398_0_2 <= 255));
  __CPROVER_assume((sec_r001398_1_1 >= 0) && (sec_r001398_1_1 <= 255));
  __CPROVER_assume((sec_r001398_1_2 >= 0) && (sec_r001398_1_2 <= 255));
  __CPROVER_assume((sec_r001398_2_1 >= 0) && (sec_r001398_2_1 <= 255));
  __CPROVER_assume((sec_r001398_2_2 >= 0) && (sec_r001398_2_2 <= 255));
  __CPROVER_assume((sec_r001398_3_1 >= 0) && (sec_r001398_3_1 <= 255));
  __CPROVER_assume((sec_r001398_3_2 >= 0) && (sec_r001398_3_2 <= 255));
  __CPROVER_assume((sec_r001398_4_1 >= 0) && (sec_r001398_4_1 <= 255));
  __CPROVER_assume((sec_r001398_4_2 >= 0) && (sec_r001398_4_2 <= 255));
  __CPROVER_assume((sec_r001398_5_1 >= 0) && (sec_r001398_5_1 <= 255));
  __CPROVER_assume((sec_r001398_5_2 >= 0) && (sec_r001398_5_2 <= 255));
  __CPROVER_assume((sec_r001398_6_1 >= 0) && (sec_r001398_6_1 <= 255));
  __CPROVER_assume((sec_r001398_6_2 >= 0) && (sec_r001398_6_2 <= 255));
  __CPROVER_assume((sec_r001398_7_1 >= 0) && (sec_r001398_7_1 <= 255));
  __CPROVER_assume((sec_r001398_7_2 >= 0) && (sec_r001398_7_2 <= 255));
  __CPROVER_assume((sec_r001398_8_1 >= 0) && (sec_r001398_8_1 <= 255));
  __CPROVER_assume((sec_r001398_8_2 >= 0) && (sec_r001398_8_2 <= 255));
  __CPROVER_assume((sec_r001398_9_1 >= 0) && (sec_r001398_9_1 <= 255));
  __CPROVER_assume((sec_r001398_9_2 >= 0) && (sec_r001398_9_2 <= 255));
  __CPROVER_assume((sec_r001398_10_1 >= 0) && (sec_r001398_10_1 <= 255));
  __CPROVER_assume((sec_r001398_10_2 >= 0) && (sec_r001398_10_2 <= 255));
  __CPROVER_assume((sec_r001398_11_1 >= 0) && (sec_r001398_11_1 <= 255));
  __CPROVER_assume((sec_r001398_11_2 >= 0) && (sec_r001398_11_2 <= 255));
  __CPROVER_assume((sec_r001398_12_1 >= 0) && (sec_r001398_12_1 <= 255));
  __CPROVER_assume((sec_r001398_12_2 >= 0) && (sec_r001398_12_2 <= 255));
  __CPROVER_assume((sec_r001398_13_1 >= 0) && (sec_r001398_13_1 <= 255));
  __CPROVER_assume((sec_r001398_13_2 >= 0) && (sec_r001398_13_2 <= 255));
  __CPROVER_assume((sec_r001398_14_1 >= 0) && (sec_r001398_14_1 <= 255));
  __CPROVER_assume((sec_r001398_14_2 >= 0) && (sec_r001398_14_2 <= 255));
  __CPROVER_assume((sec_r001398_15_1 >= 0) && (sec_r001398_15_1 <= 255));
  __CPROVER_assume((sec_r001398_15_2 >= 0) && (sec_r001398_15_2 <= 255));
  __CPROVER_assume((sec_r001398_16_1 >= 0) && (sec_r001398_16_1 <= 255));
  __CPROVER_assume((sec_r001398_16_2 >= 0) && (sec_r001398_16_2 <= 255));
  __CPROVER_assume((sec_r001398_17_1 >= 0) && (sec_r001398_17_1 <= 255));
  __CPROVER_assume((sec_r001398_17_2 >= 0) && (sec_r001398_17_2 <= 255));
  __CPROVER_assume((sec_r001398_18_1 >= 0) && (sec_r001398_18_1 <= 255));
  __CPROVER_assume((sec_r001398_18_2 >= 0) && (sec_r001398_18_2 <= 255));
  __CPROVER_assume((sec_r001398_19_1 >= 0) && (sec_r001398_19_1 <= 255));
  __CPROVER_assume((sec_r001398_19_2 >= 0) && (sec_r001398_19_2 <= 255));
  struct SensorNode_R001398_9813_0 st_var_0_1 = {0};
  struct SensorNode_R001398_9813_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001398_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001398_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001398_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001398_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001398_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001398_0_2 + 7) & 15;
  struct FilterState_R001398_9813_1 st_var_1_1 = {0};
  struct FilterState_R001398_9813_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001398_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001398_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001398_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001398_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001398_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001398_0_2 + 9) & 15;
  struct DeviceConfig_R001398_9813_2 st_var_2_1 = {0};
  struct DeviceConfig_R001398_9813_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001398_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001398_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001398_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001398_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001398_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001398_0_2 + 11) & 15;
  struct Vector3D_R001398_9813_3 st_var_3_1 = {0};
  struct Vector3D_R001398_9813_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001398_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001398_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001398_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001398_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001398_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001398_0_2 + 13) & 15;
  union PacketPayload_R001398_9813_0 u_var_1;
  union PacketPayload_R001398_9813_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001398_9813_0(sec_r001398_0_1, sec_r001398_1_1, pub_r001398_2_1, pub_r001398_3_1);
  int helper_flow_0_2 = fn_R001398_9813_0(sec_r001398_0_2, sec_r001398_1_2, pub_r001398_2_2, pub_r001398_3_2);
  fn_R001398_9813_0_2(sec_r001398_0_1, sec_r001398_1_1, pub_r001398_2_1, pub_r001398_3_1, sec_r001398_0_2, sec_r001398_1_2, pub_r001398_2_2, pub_r001398_3_2);
  int helper_flow_1_1 = fn_R001398_9813_1(sec_r001398_1_1, sec_r001398_2_1);
  int helper_flow_1_2 = fn_R001398_9813_1(sec_r001398_1_2, sec_r001398_2_2);
  fn_R001398_9813_1_2(sec_r001398_1_1, sec_r001398_2_1, sec_r001398_1_2, sec_r001398_2_2);
  int helper_flow_2_1 = fn_R001398_9813_2(sec_r001398_2_1, sec_r001398_3_1);
  int helper_flow_2_2 = fn_R001398_9813_2(sec_r001398_2_2, sec_r001398_3_2);
  fn_R001398_9813_2_2(sec_r001398_2_1, sec_r001398_3_1, sec_r001398_2_2, sec_r001398_3_2);
  int helper_flow_3_1 = fn_R001398_9813_3(sec_r001398_3_1, sec_r001398_4_1, pub_r001398_5_1, pub_r001398_6_1);
  int helper_flow_3_2 = fn_R001398_9813_3(sec_r001398_3_2, sec_r001398_4_2, pub_r001398_5_2, pub_r001398_6_2);
  fn_R001398_9813_3_2(sec_r001398_3_1, sec_r001398_4_1, pub_r001398_5_1, pub_r001398_6_1, sec_r001398_3_2, sec_r001398_4_2, pub_r001398_5_2, pub_r001398_6_2);
  int helper_flow_4_1 = fn_R001398_9813_4(sec_r001398_4_1, pub_r001398_5_1, pub_r001398_6_1, pub_r001398_7_1, pub_r001398_8_1);
  int helper_flow_4_2 = fn_R001398_9813_4(sec_r001398_4_2, pub_r001398_5_2, pub_r001398_6_2, pub_r001398_7_2, pub_r001398_8_2);
  fn_R001398_9813_4_2(sec_r001398_4_1, pub_r001398_5_1, pub_r001398_6_1, pub_r001398_7_1, pub_r001398_8_1, sec_r001398_4_2, pub_r001398_5_2, pub_r001398_6_2, pub_r001398_7_2, pub_r001398_8_2);
  int helper_flow_5_1 = fn_R001398_9813_5(sec_r001398_5_1, pub_r001398_6_1, pub_r001398_7_1);
  int helper_flow_5_2 = fn_R001398_9813_5(sec_r001398_5_2, pub_r001398_6_2, pub_r001398_7_2);
  fn_R001398_9813_5_2(sec_r001398_5_1, pub_r001398_6_1, pub_r001398_7_1, sec_r001398_5_2, pub_r001398_6_2, pub_r001398_7_2);
  int helper_flow_6_1 = fn_R001398_9813_6(sec_r001398_6_1, sec_r001398_7_1, pub_r001398_8_1);
  int helper_flow_6_2 = fn_R001398_9813_6(sec_r001398_6_2, sec_r001398_7_2, pub_r001398_8_2);
  fn_R001398_9813_6_2(sec_r001398_6_1, sec_r001398_7_1, pub_r001398_8_1, sec_r001398_6_2, sec_r001398_7_2, pub_r001398_8_2);
  int helper_flow_7_1 = fn_R001398_9813_7(sec_r001398_7_1, sec_r001398_8_1, pub_r001398_9_1);
  int helper_flow_7_2 = fn_R001398_9813_7(sec_r001398_7_2, sec_r001398_8_2, pub_r001398_9_2);
  fn_R001398_9813_7_2(sec_r001398_7_1, sec_r001398_8_1, pub_r001398_9_1, sec_r001398_7_2, sec_r001398_8_2, pub_r001398_9_2);
  int helper_flow_8_1 = fn_R001398_9813_8(sec_r001398_8_1, sec_r001398_9_1);
  int helper_flow_8_2 = fn_R001398_9813_8(sec_r001398_8_2, sec_r001398_9_2);
  fn_R001398_9813_8_2(sec_r001398_8_1, sec_r001398_9_1, sec_r001398_8_2, sec_r001398_9_2);
  int helper_flow_9_1 = fn_R001398_9813_9(sec_r001398_9_1, sec_r001398_10_1, pub_r001398_11_1, pub_r001398_12_1, pub_r001398_13_1);
  int helper_flow_9_2 = fn_R001398_9813_9(sec_r001398_9_2, sec_r001398_10_2, pub_r001398_11_2, pub_r001398_12_2, pub_r001398_13_2);
  fn_R001398_9813_9_2(sec_r001398_9_1, sec_r001398_10_1, pub_r001398_11_1, pub_r001398_12_1, pub_r001398_13_1, sec_r001398_9_2, sec_r001398_10_2, pub_r001398_11_2, pub_r001398_12_2, pub_r001398_13_2);
  int helper_flow_10_1 = fn_R001398_9813_10(sec_r001398_10_1, sec_r001398_11_1, pub_r001398_12_1, pub_r001398_13_1);
  int helper_flow_10_2 = fn_R001398_9813_10(sec_r001398_10_2, sec_r001398_11_2, pub_r001398_12_2, pub_r001398_13_2);
  fn_R001398_9813_10_2(sec_r001398_10_1, sec_r001398_11_1, pub_r001398_12_1, pub_r001398_13_1, sec_r001398_10_2, sec_r001398_11_2, pub_r001398_12_2, pub_r001398_13_2);
  int stage_v_0_1 = ((pub_r001398_18_1 * 2) + 14) & 63;
  int stage_v_0_2 = ((pub_r001398_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001398_19_1 * 2) + 21) & 63;
  int stage_v_1_2 = ((pub_r001398_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = 0;
  int stage_v_2_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_2_1 = ((stage_v_2_1 + (it_1 * 3)) + (sec_r001398_12_1 & 15)) & 63;
    stage_v_2_2 = ((stage_v_2_2 + (it_2 * 3)) + (sec_r001398_12_2 & 15)) & 63;
    if ((sec_r001398_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_2_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_2_1) + 7) & 255;
    }
    if ((sec_r001398_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_2_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_2_2) + 7) & 255;
    }
  }

  int stage_v_3_1 = ((pub_r001398_1_1 * 2) + 19) & 63;
  int stage_v_3_2 = ((pub_r001398_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = 0;
  int stage_v_4_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_4_1 = ((stage_v_4_1 + (it_1 * 3)) + (sec_r001398_3_1 & 15)) & 63;
    stage_v_4_2 = ((stage_v_4_2 + (it_2 * 3)) + (sec_r001398_3_2 & 15)) & 63;
    if ((sec_r001398_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_4_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_4_1) + 7) & 255;
    }
    if ((sec_r001398_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_4_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_4_2) + 7) & 255;
    }
  }

  int stage_v_5_1 = ((pub_r001398_5_1 * 2) + 18) & 63;
  int stage_v_5_2 = ((pub_r001398_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001398_8_1 * 2) + 14) & 63;
  int stage_v_6_2 = ((pub_r001398_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001398_17_1 * 2) + 36) & 63;
  int stage_v_7_2 = ((pub_r001398_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001398_12_1 * 2) + 45) & 63;
  int stage_v_8_2 = ((pub_r001398_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_9_1 = ((stage_v_9_1 + (it_1 * 3)) + (sec_r001398_1_1 & 15)) & 63;
    stage_v_9_2 = ((stage_v_9_2 + (it_2 * 3)) + (sec_r001398_1_2 & 15)) & 63;
    if ((sec_r001398_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_9_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_9_1) + 7) & 255;
    }
    if ((sec_r001398_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_9_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_9_2) + 7) & 255;
    }
  }

  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (it_1 * 3)) + (helper_flow_10_1 & 15)) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (it_2 * 3)) + (helper_flow_10_2 & 15)) & 63;
    if ((helper_flow_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_10_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_10_1) + 7) & 255;
    }
    if ((helper_flow_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_10_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_10_2) + 7) & 255;
    }
  }

  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (it_1 * 3)) + (sec_r001398_8_1 & 15)) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (it_2 * 3)) + (sec_r001398_8_2 & 15)) & 63;
    if ((sec_r001398_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_11_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_11_1) + 7) & 255;
    }
    if ((sec_r001398_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_11_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_11_2) + 7) & 255;
    }
  }

  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (it_1 * 3)) + (helper_flow_9_1 & 15)) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (it_2 * 3)) + (helper_flow_9_2 & 15)) & 63;
    if ((helper_flow_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_12_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_12_1) + 7) & 255;
    }
    if ((helper_flow_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_12_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_12_2) + 7) & 255;
    }
  }

  int stage_v_13_1 = ((pub_r001398_18_1 * 2) + 50) & 63;
  int stage_v_13_2 = ((pub_r001398_18_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (it_1 * 3)) + (sec_r001398_2_1 & 15)) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (it_2 * 3)) + (sec_r001398_2_2 & 15)) & 63;
    if ((sec_r001398_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_14_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_14_1) + 7) & 255;
    }
    if ((sec_r001398_2_2 & 1) != 0)
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
    stage_v_15_1 = ((stage_v_15_1 + (it_1 * 3)) + (sec_r001398_17_1 & 15)) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (it_2 * 3)) + (sec_r001398_17_2 & 15)) & 63;
    if ((sec_r001398_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_15_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_15_1) + 7) & 255;
    }
    if ((sec_r001398_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_15_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_15_2) + 7) & 255;
    }
  }

  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (it_1 * 3)) + (sec_r001398_3_1 & 15)) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (it_2 * 3)) + (sec_r001398_3_2 & 15)) & 63;
    if ((sec_r001398_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_16_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_16_1) + 7) & 255;
    }
    if ((sec_r001398_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_16_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_16_2) + 7) & 255;
    }
  }

  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_17_1 = ((stage_v_17_1 + (it_1 * 3)) + (stage_v_2_1 & 15)) & 63;
    stage_v_17_2 = ((stage_v_17_2 + (it_2 * 3)) + (stage_v_2_2 & 15)) & 63;
    if ((stage_v_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_17_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_17_1) + 7) & 255;
    }
    if ((stage_v_2_2 & 1) != 0)
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
    stage_v_18_1 = ((stage_v_18_1 + (it_1 * 3)) + (helper_flow_4_1 & 15)) & 63;
    stage_v_18_2 = ((stage_v_18_2 + (it_2 * 3)) + (helper_flow_4_2 & 15)) & 63;
    if ((helper_flow_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_18_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_18_1) + 7) & 255;
    }
    if ((helper_flow_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_18_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_18_2) + 7) & 255;
    }
  }

  int stage_v_19_1 = ((pub_r001398_10_1 * 2) + 16) & 63;
  int stage_v_19_2 = ((pub_r001398_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (it_1 * 3)) + (stage_v_12_1 & 15)) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (it_2 * 3)) + (stage_v_12_2 & 15)) & 63;
    if ((stage_v_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_20_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_20_1) + 7) & 255;
    }
    if ((stage_v_12_2 & 1) != 0)
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
    stage_v_21_1 = ((stage_v_21_1 + (it_1 * 3)) + (stage_v_12_1 & 15)) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (it_2 * 3)) + (stage_v_12_2 & 15)) & 63;
    if ((stage_v_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_21_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_21_1) + 7) & 255;
    }
    if ((stage_v_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_21_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_21_2) + 7) & 255;
    }
  }

  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (it_1 * 3)) + (sec_r001398_2_1 & 15)) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (it_2 * 3)) + (sec_r001398_2_2 & 15)) & 63;
    if ((sec_r001398_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_22_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_22_1) + 7) & 255;
    }
    if ((sec_r001398_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_22_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_22_2) + 7) & 255;
    }
  }

  int stage_v_23_1 = ((pub_r001398_1_1 * 2) + 5) & 63;
  int stage_v_23_2 = ((pub_r001398_1_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001398_7_1 * 2) + 13) & 63;
  int stage_v_24_2 = ((pub_r001398_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_25_1 = ((stage_v_25_1 + (it_1 * 3)) + (helper_flow_8_1 & 15)) & 63;
    stage_v_25_2 = ((stage_v_25_2 + (it_2 * 3)) + (helper_flow_8_2 & 15)) & 63;
    if ((helper_flow_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_25_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_25_1) + 7) & 255;
    }
    if ((helper_flow_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_25_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_25_2) + 7) & 255;
    }
  }

  int stage_v_26_1 = ((pub_r001398_16_1 * 2) + 37) & 63;
  int stage_v_26_2 = ((pub_r001398_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (it_1 * 3)) + (sec_r001398_9_1 & 15)) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (it_2 * 3)) + (sec_r001398_9_2 & 15)) & 63;
    if ((sec_r001398_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_27_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_27_1) + 7) & 255;
    }
    if ((sec_r001398_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_27_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_27_2) + 7) & 255;
    }
  }

  int stage_v_28_1 = ((pub_r001398_6_1 * 2) + 36) & 63;
  int stage_v_28_2 = ((pub_r001398_6_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_29_1 = ((stage_v_29_1 + (it_1 * 3)) + (helper_flow_1_1 & 15)) & 63;
    stage_v_29_2 = ((stage_v_29_2 + (it_2 * 3)) + (helper_flow_1_2 & 15)) & 63;
    if ((helper_flow_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_29_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_29_1) + 7) & 255;
    }
    if ((helper_flow_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_29_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_29_2) + 7) & 255;
    }
  }

  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_30_1 = ((stage_v_30_1 + (it_1 * 3)) + (stage_v_22_1 & 15)) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (it_2 * 3)) + (stage_v_22_2 & 15)) & 63;
    if ((stage_v_22_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_30_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_30_1) + 7) & 255;
    }
    if ((stage_v_22_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_30_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_30_2) + 7) & 255;
    }
  }

  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_31_1 = ((stage_v_31_1 + (it_1 * 3)) + (stage_v_9_1 & 15)) & 63;
    stage_v_31_2 = ((stage_v_31_2 + (it_2 * 3)) + (stage_v_9_2 & 15)) & 63;
    if ((stage_v_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_31_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_31_1) + 7) & 255;
    }
    if ((stage_v_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_31_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_31_2) + 7) & 255;
    }
  }

  int stage_v_32_1 = ((pub_r001398_4_1 * 2) + 34) & 63;
  int stage_v_32_2 = ((pub_r001398_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001398_17_1 * 2) + 11) & 63;
  int stage_v_33_2 = ((pub_r001398_17_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_34_1 = ((stage_v_34_1 + (it_1 * 3)) + (stage_v_12_1 & 15)) & 63;
    stage_v_34_2 = ((stage_v_34_2 + (it_2 * 3)) + (stage_v_12_2 & 15)) & 63;
    if ((stage_v_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_34_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_34_1) + 7) & 255;
    }
    if ((stage_v_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_34_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_34_2) + 7) & 255;
    }
  }

  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (it_1 * 3)) + (helper_flow_3_1 & 15)) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (it_2 * 3)) + (helper_flow_3_2 & 15)) & 63;
    if ((helper_flow_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_35_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_35_1) + 7) & 255;
    }
    if ((helper_flow_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_35_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_35_2) + 7) & 255;
    }
  }

  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (it_1 * 3)) + (stage_v_2_1 & 15)) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (it_2 * 3)) + (stage_v_2_2 & 15)) & 63;
    if ((stage_v_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_36_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_36_1) + 7) & 255;
    }
    if ((stage_v_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_36_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_36_2) + 7) & 255;
    }
  }

  int stage_v_37_1 = ((pub_r001398_17_1 * 2) + 7) & 63;
  int stage_v_37_2 = ((pub_r001398_17_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (it_1 * 3)) + (stage_v_16_1 & 15)) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (it_2 * 3)) + (stage_v_16_2 & 15)) & 63;
    if ((stage_v_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_38_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_38_1) + 7) & 255;
    }
    if ((stage_v_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_38_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_38_2) + 7) & 255;
    }
  }

  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (it_1 * 3)) + (sec_r001398_9_1 & 15)) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (it_2 * 3)) + (sec_r001398_9_2 & 15)) & 63;
    if ((sec_r001398_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_39_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_39_1) + 7) & 255;
    }
    if ((sec_r001398_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_39_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_39_2) + 7) & 255;
    }
  }

  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_40_1 = ((stage_v_40_1 + (it_1 * 3)) + (stage_v_39_1 & 15)) & 63;
    stage_v_40_2 = ((stage_v_40_2 + (it_2 * 3)) + (stage_v_39_2 & 15)) & 63;
    if ((stage_v_39_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_40_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_40_1) + 7) & 255;
    }
    if ((stage_v_39_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_40_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_40_2) + 7) & 255;
    }
  }

  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_41_1 = ((stage_v_41_1 + (it_1 * 3)) + (stage_v_27_1 & 15)) & 63;
    stage_v_41_2 = ((stage_v_41_2 + (it_2 * 3)) + (stage_v_27_2 & 15)) & 63;
    if ((stage_v_27_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_41_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_41_1) + 7) & 255;
    }
    if ((stage_v_27_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_41_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_41_2) + 7) & 255;
    }
  }

  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_42_1 = ((stage_v_42_1 + (it_1 * 3)) + (stage_v_41_1 & 15)) & 63;
    stage_v_42_2 = ((stage_v_42_2 + (it_2 * 3)) + (stage_v_41_2 & 15)) & 63;
    if ((stage_v_41_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_42_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_42_1) + 7) & 255;
    }
    if ((stage_v_41_2 & 1) != 0)
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
    stage_v_43_1 = ((stage_v_43_1 + (it_1 * 3)) + (helper_flow_5_1 & 15)) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (it_2 * 3)) + (helper_flow_5_2 & 15)) & 63;
    if ((helper_flow_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_43_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_43_1) + 7) & 255;
    }
    if ((helper_flow_5_2 & 1) != 0)
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
    stage_v_44_1 = ((stage_v_44_1 + (it_1 * 3)) + (helper_flow_10_1 & 15)) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (it_2 * 3)) + (helper_flow_10_2 & 15)) & 63;
    if ((helper_flow_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_44_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_44_1) + 7) & 255;
    }
    if ((helper_flow_10_2 & 1) != 0)
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
    stage_v_45_1 = ((stage_v_45_1 + (it_1 * 3)) + (helper_flow_10_1 & 15)) & 63;
    stage_v_45_2 = ((stage_v_45_2 + (it_2 * 3)) + (helper_flow_10_2 & 15)) & 63;
    if ((helper_flow_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_45_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_45_1) + 7) & 255;
    }
    if ((helper_flow_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_45_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_45_2) + 7) & 255;
    }
  }

  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_46_1 = ((stage_v_46_1 + (it_1 * 3)) + (sec_r001398_9_1 & 15)) & 63;
    stage_v_46_2 = ((stage_v_46_2 + (it_2 * 3)) + (sec_r001398_9_2 & 15)) & 63;
    if ((sec_r001398_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_46_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_46_1) + 7) & 255;
    }
    if ((sec_r001398_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_46_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_46_2) + 7) & 255;
    }
  }

  int stage_v_47_1 = ((pub_r001398_19_1 * 2) + 39) & 63;
  int stage_v_47_2 = ((pub_r001398_19_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (it_1 * 3)) + (stage_v_25_1 & 15)) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (it_2 * 3)) + (stage_v_25_2 & 15)) & 63;
    if ((stage_v_25_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_48_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_48_1) + 7) & 255;
    }
    if ((stage_v_25_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_48_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_48_2) + 7) & 255;
    }
  }

  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_49_1 = ((stage_v_49_1 + (it_1 * 3)) + (stage_v_43_1 & 15)) & 63;
    stage_v_49_2 = ((stage_v_49_2 + (it_2 * 3)) + (stage_v_43_2 & 15)) & 63;
    if ((stage_v_43_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_49_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_49_1) + 7) & 255;
    }
    if ((stage_v_43_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_49_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_49_2) + 7) & 255;
    }
  }

  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_50_1 = ((stage_v_50_1 + (it_1 * 3)) + (helper_flow_1_1 & 15)) & 63;
    stage_v_50_2 = ((stage_v_50_2 + (it_2 * 3)) + (helper_flow_1_2 & 15)) & 63;
    if ((helper_flow_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_50_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_50_1) + 7) & 255;
    }
    if ((helper_flow_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_50_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_50_2) + 7) & 255;
    }
  }

  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_51_1 = ((stage_v_51_1 + (it_1 * 3)) + (stage_v_44_1 & 15)) & 63;
    stage_v_51_2 = ((stage_v_51_2 + (it_2 * 3)) + (stage_v_44_2 & 15)) & 63;
    if ((stage_v_44_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_51_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_51_1) + 7) & 255;
    }
    if ((stage_v_44_2 & 1) != 0)
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
    stage_v_52_1 = ((stage_v_52_1 + (it_1 * 3)) + (stage_v_29_1 & 15)) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (it_2 * 3)) + (stage_v_29_2 & 15)) & 63;
    if ((stage_v_29_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_52_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_52_1) + 7) & 255;
    }
    if ((stage_v_29_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_52_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_52_2) + 7) & 255;
    }
  }

  int stage_v_53_1 = ((pub_r001398_15_1 * 2) + 18) & 63;
  int stage_v_53_2 = ((pub_r001398_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_54_1 = ((stage_v_54_1 + (it_1 * 3)) + (sec_r001398_4_1 & 15)) & 63;
    stage_v_54_2 = ((stage_v_54_2 + (it_2 * 3)) + (sec_r001398_4_2 & 15)) & 63;
    if ((sec_r001398_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_54_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_54_1) + 7) & 255;
    }
    if ((sec_r001398_4_2 & 1) != 0)
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
    stage_v_55_1 = ((stage_v_55_1 + (it_1 * 3)) + (stage_v_43_1 & 15)) & 63;
    stage_v_55_2 = ((stage_v_55_2 + (it_2 * 3)) + (stage_v_43_2 & 15)) & 63;
    if ((stage_v_43_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_55_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_55_1) + 7) & 255;
    }
    if ((stage_v_43_2 & 1) != 0)
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
    stage_v_56_1 = ((stage_v_56_1 + (it_1 * 3)) + (stage_v_42_1 & 15)) & 63;
    stage_v_56_2 = ((stage_v_56_2 + (it_2 * 3)) + (stage_v_42_2 & 15)) & 63;
    if ((stage_v_42_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_56_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_56_1) + 7) & 255;
    }
    if ((stage_v_42_2 & 1) != 0)
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
    stage_v_57_1 = ((stage_v_57_1 + (it_1 * 3)) + (helper_flow_3_1 & 15)) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (it_2 * 3)) + (helper_flow_3_2 & 15)) & 63;
    if ((helper_flow_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_57_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_57_1) + 7) & 255;
    }
    if ((helper_flow_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_57_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_57_2) + 7) & 255;
    }
  }

  int stage_v_58_1 = ((pub_r001398_18_1 * 2) + 48) & 63;
  int stage_v_58_2 = ((pub_r001398_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_59_1 = ((stage_v_59_1 + (it_1 * 3)) + (helper_flow_1_1 & 15)) & 63;
    stage_v_59_2 = ((stage_v_59_2 + (it_2 * 3)) + (helper_flow_1_2 & 15)) & 63;
    if ((helper_flow_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_59_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_59_1) + 7) & 255;
    }
    if ((helper_flow_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_59_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_59_2) + 7) & 255;
    }
  }

  int stage_v_60_1 = ((pub_r001398_8_1 * 2) + 8) & 63;
  int stage_v_60_2 = ((pub_r001398_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_61_1 = ((stage_v_61_1 + (it_1 * 3)) + (stage_v_22_1 & 15)) & 63;
    stage_v_61_2 = ((stage_v_61_2 + (it_2 * 3)) + (stage_v_22_2 & 15)) & 63;
    if ((stage_v_22_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_61_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_61_1) + 7) & 255;
    }
    if ((stage_v_22_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_61_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_61_2) + 7) & 255;
    }
  }

  int stage_v_62_1 = ((pub_r001398_9_1 * 2) + 15) & 63;
  int stage_v_62_2 = ((pub_r001398_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_63_1 = ((stage_v_63_1 + (it_1 * 3)) + (sec_r001398_16_1 & 15)) & 63;
    stage_v_63_2 = ((stage_v_63_2 + (it_2 * 3)) + (sec_r001398_16_2 & 15)) & 63;
    if ((sec_r001398_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_63_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_63_1) + 7) & 255;
    }
    if ((sec_r001398_16_2 & 1) != 0)
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
    stage_v_64_1 = ((stage_v_64_1 + (it_1 * 3)) + (stage_v_18_1 & 15)) & 63;
    stage_v_64_2 = ((stage_v_64_2 + (it_2 * 3)) + (stage_v_18_2 & 15)) & 63;
    if ((stage_v_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_64_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_64_1) + 7) & 255;
    }
    if ((stage_v_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_64_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_64_2) + 7) & 255;
    }
  }

  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_65_1 = ((stage_v_65_1 + (it_1 * 3)) + (stage_v_63_1 & 15)) & 63;
    stage_v_65_2 = ((stage_v_65_2 + (it_2 * 3)) + (stage_v_63_2 & 15)) & 63;
    if ((stage_v_63_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_65_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_65_1) + 7) & 255;
    }
    if ((stage_v_63_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_65_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_65_2) + 7) & 255;
    }
  }

  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_66_1 = ((stage_v_66_1 + (it_1 * 3)) + (helper_flow_7_1 & 15)) & 63;
    stage_v_66_2 = ((stage_v_66_2 + (it_2 * 3)) + (helper_flow_7_2 & 15)) & 63;
    if ((helper_flow_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_66_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_66_1) + 7) & 255;
    }
    if ((helper_flow_7_2 & 1) != 0)
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
    stage_v_67_1 = ((stage_v_67_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_67_2 = ((stage_v_67_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_67_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_67_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_67_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_67_2) + 7) & 255;
    }
  }

  int stage_v_68_1 = ((pub_r001398_1_1 * 2) + 28) & 63;
  int stage_v_68_2 = ((pub_r001398_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_69_1 = ((stage_v_69_1 + (it_1 * 3)) + (stage_v_50_1 & 15)) & 63;
    stage_v_69_2 = ((stage_v_69_2 + (it_2 * 3)) + (stage_v_50_2 & 15)) & 63;
    if ((stage_v_50_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_69_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_69_1) + 7) & 255;
    }
    if ((stage_v_50_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_69_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_69_2) + 7) & 255;
    }
  }

  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_70_1 = ((stage_v_70_1 + (it_1 * 3)) + (stage_v_9_1 & 15)) & 63;
    stage_v_70_2 = ((stage_v_70_2 + (it_2 * 3)) + (stage_v_9_2 & 15)) & 63;
    if ((stage_v_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_70_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_70_1) + 7) & 255;
    }
    if ((stage_v_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_70_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_70_2) + 7) & 255;
    }
  }

  int stage_v_71_1 = ((pub_r001398_8_1 * 2) + 19) & 63;
  int stage_v_71_2 = ((pub_r001398_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_72_1 = ((stage_v_72_1 + (it_1 * 3)) + (sec_r001398_18_1 & 15)) & 63;
    stage_v_72_2 = ((stage_v_72_2 + (it_2 * 3)) + (sec_r001398_18_2 & 15)) & 63;
    if ((sec_r001398_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_72_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_72_1) + 7) & 255;
    }
    if ((sec_r001398_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_72_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_72_2) + 7) & 255;
    }
  }

  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_73_1 = ((stage_v_73_1 + (it_1 * 3)) + (sec_r001398_16_1 & 15)) & 63;
    stage_v_73_2 = ((stage_v_73_2 + (it_2 * 3)) + (sec_r001398_16_2 & 15)) & 63;
    if ((sec_r001398_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_73_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_73_1) + 7) & 255;
    }
    if ((sec_r001398_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_73_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_73_2) + 7) & 255;
    }
  }

  int stage_v_74_1 = ((pub_r001398_0_1 * 2) + 9) & 63;
  int stage_v_74_2 = ((pub_r001398_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_75_1 = ((stage_v_75_1 + (it_1 * 3)) + (sec_r001398_7_1 & 15)) & 63;
    stage_v_75_2 = ((stage_v_75_2 + (it_2 * 3)) + (sec_r001398_7_2 & 15)) & 63;
    if ((sec_r001398_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_75_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_75_1) + 7) & 255;
    }
    if ((sec_r001398_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_75_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_75_2) + 7) & 255;
    }
  }

  int stage_v_76_1 = ((pub_r001398_10_1 * 2) + 6) & 63;
  int stage_v_76_2 = ((pub_r001398_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_77_1 = ((stage_v_77_1 + (it_1 * 3)) + (stage_v_27_1 & 15)) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (it_2 * 3)) + (stage_v_27_2 & 15)) & 63;
    if ((stage_v_27_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_77_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_77_1) + 7) & 255;
    }
    if ((stage_v_27_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_77_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_77_2) + 7) & 255;
    }
  }

  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_78_1 = ((stage_v_78_1 + (it_1 * 3)) + (sec_r001398_9_1 & 15)) & 63;
    stage_v_78_2 = ((stage_v_78_2 + (it_2 * 3)) + (sec_r001398_9_2 & 15)) & 63;
    if ((sec_r001398_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_78_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_78_1) + 7) & 255;
    }
    if ((sec_r001398_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_78_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_78_2) + 7) & 255;
    }
  }

  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_79_1 = ((stage_v_79_1 + (it_1 * 3)) + (helper_flow_10_1 & 15)) & 63;
    stage_v_79_2 = ((stage_v_79_2 + (it_2 * 3)) + (helper_flow_10_2 & 15)) & 63;
    if ((helper_flow_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_79_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_79_1) + 7) & 255;
    }
    if ((helper_flow_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_79_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_79_2) + 7) & 255;
    }
  }

  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_80_1 = ((stage_v_80_1 + (it_1 * 3)) + (stage_v_73_1 & 15)) & 63;
    stage_v_80_2 = ((stage_v_80_2 + (it_2 * 3)) + (stage_v_73_2 & 15)) & 63;
    if ((stage_v_73_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_80_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_80_1) + 7) & 255;
    }
    if ((stage_v_73_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_80_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_80_2) + 7) & 255;
    }
  }

  int stage_v_81_1 = ((pub_r001398_8_1 * 2) + 9) & 63;
  int stage_v_81_2 = ((pub_r001398_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_82_1 = ((stage_v_82_1 + (it_1 * 3)) + (sec_r001398_10_1 & 15)) & 63;
    stage_v_82_2 = ((stage_v_82_2 + (it_2 * 3)) + (sec_r001398_10_2 & 15)) & 63;
    if ((sec_r001398_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_82_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_82_1) + 7) & 255;
    }
    if ((sec_r001398_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_82_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_82_2) + 7) & 255;
    }
  }

  int stage_v_83_1 = ((pub_r001398_2_1 * 2) + 30) & 63;
  int stage_v_83_2 = ((pub_r001398_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001398_3_1 * 2) + 12) & 63;
  int stage_v_84_2 = ((pub_r001398_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_85_1 = ((stage_v_85_1 + (it_1 * 3)) + (sec_r001398_18_1 & 15)) & 63;
    stage_v_85_2 = ((stage_v_85_2 + (it_2 * 3)) + (sec_r001398_18_2 & 15)) & 63;
    if ((sec_r001398_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_85_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_85_1) + 7) & 255;
    }
    if ((sec_r001398_18_2 & 1) != 0)
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
    stage_v_86_1 = ((stage_v_86_1 + (it_1 * 3)) + (helper_flow_2_1 & 15)) & 63;
    stage_v_86_2 = ((stage_v_86_2 + (it_2 * 3)) + (helper_flow_2_2 & 15)) & 63;
    if ((helper_flow_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_86_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_86_1) + 7) & 255;
    }
    if ((helper_flow_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_86_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_86_2) + 7) & 255;
    }
  }

  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_87_1 = ((stage_v_87_1 + (it_1 * 3)) + (sec_r001398_16_1 & 15)) & 63;
    stage_v_87_2 = ((stage_v_87_2 + (it_2 * 3)) + (sec_r001398_16_2 & 15)) & 63;
    if ((sec_r001398_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_87_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_87_1) + 7) & 255;
    }
    if ((sec_r001398_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_87_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_87_2) + 7) & 255;
    }
  }

  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_88_1 = ((stage_v_88_1 + (it_1 * 3)) + (helper_flow_0_1 & 15)) & 63;
    stage_v_88_2 = ((stage_v_88_2 + (it_2 * 3)) + (helper_flow_0_2 & 15)) & 63;
    if ((helper_flow_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_88_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_88_1) + 7) & 255;
    }
    if ((helper_flow_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_88_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_88_2) + 7) & 255;
    }
  }

  int stage_v_89_1 = ((pub_r001398_19_1 * 2) + 16) & 63;
  int stage_v_89_2 = ((pub_r001398_19_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_90_1 = ((stage_v_90_1 + (it_1 * 3)) + (stage_v_17_1 & 15)) & 63;
    stage_v_90_2 = ((stage_v_90_2 + (it_2 * 3)) + (stage_v_17_2 & 15)) & 63;
    if ((stage_v_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_90_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_90_1) + 7) & 255;
    }
    if ((stage_v_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_90_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_90_2) + 7) & 255;
    }
  }

  int stage_v_91_1 = ((pub_r001398_4_1 * 2) + 13) & 63;
  int stage_v_91_2 = ((pub_r001398_4_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001398_20_1 * 2) + 16) & 63;
  int stage_v_92_2 = ((pub_r001398_20_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001398_4_1 * 2) + 42) & 63;
  int stage_v_93_2 = ((pub_r001398_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_94_1 = ((stage_v_94_1 + (it_1 * 3)) + (stage_v_18_1 & 15)) & 63;
    stage_v_94_2 = ((stage_v_94_2 + (it_2 * 3)) + (stage_v_18_2 & 15)) & 63;
    if ((stage_v_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_94_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_94_1) + 7) & 255;
    }
    if ((stage_v_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_94_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_94_2) + 7) & 255;
    }
  }

  int stage_v_95_1 = ((pub_r001398_13_1 * 2) + 40) & 63;
  int stage_v_95_2 = ((pub_r001398_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_96_1 = ((stage_v_96_1 + (it_1 * 3)) + (helper_flow_4_1 & 15)) & 63;
    stage_v_96_2 = ((stage_v_96_2 + (it_2 * 3)) + (helper_flow_4_2 & 15)) & 63;
    if ((helper_flow_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_96_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_96_1) + 7) & 255;
    }
    if ((helper_flow_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_96_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_96_2) + 7) & 255;
    }
  }

  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_97_1 = ((stage_v_97_1 + (it_1 * 3)) + (stage_v_78_1 & 15)) & 63;
    stage_v_97_2 = ((stage_v_97_2 + (it_2 * 3)) + (stage_v_78_2 & 15)) & 63;
    if ((stage_v_78_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_97_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_97_1) + 7) & 255;
    }
    if ((stage_v_78_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_97_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_97_2) + 7) & 255;
    }
  }

  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_98_1 = ((stage_v_98_1 + (it_1 * 3)) + (sec_r001398_17_1 & 15)) & 63;
    stage_v_98_2 = ((stage_v_98_2 + (it_2 * 3)) + (sec_r001398_17_2 & 15)) & 63;
    if ((sec_r001398_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_98_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_98_1) + 7) & 255;
    }
    if ((sec_r001398_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_98_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_98_2) + 7) & 255;
    }
  }

  int stage_v_99_1 = ((pub_r001398_8_1 * 2) + 19) & 63;
  int stage_v_99_2 = ((pub_r001398_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_100_1 = ((stage_v_100_1 + (it_1 * 3)) + (stage_v_17_1 & 15)) & 63;
    stage_v_100_2 = ((stage_v_100_2 + (it_2 * 3)) + (stage_v_17_2 & 15)) & 63;
    if ((stage_v_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_100_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_100_1) + 7) & 255;
    }
    if ((stage_v_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_100_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_100_2) + 7) & 255;
    }
  }

  int stage_v_101_1 = ((pub_r001398_17_1 * 2) + 39) & 63;
  int stage_v_101_2 = ((pub_r001398_17_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001398_14_1 * 2) + 28) & 63;
  int stage_v_102_2 = ((pub_r001398_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_103_1 = ((stage_v_103_1 + (it_1 * 3)) + (stage_v_94_1 & 15)) & 63;
    stage_v_103_2 = ((stage_v_103_2 + (it_2 * 3)) + (stage_v_94_2 & 15)) & 63;
    if ((stage_v_94_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_103_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_103_1) + 7) & 255;
    }
    if ((stage_v_94_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_103_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_103_2) + 7) & 255;
    }
  }

  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_104_1 = ((stage_v_104_1 + (it_1 * 3)) + (sec_r001398_4_1 & 15)) & 63;
    stage_v_104_2 = ((stage_v_104_2 + (it_2 * 3)) + (sec_r001398_4_2 & 15)) & 63;
    if ((sec_r001398_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_104_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_104_1) + 7) & 255;
    }
    if ((sec_r001398_4_2 & 1) != 0)
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
    stage_v_105_1 = ((stage_v_105_1 + (it_1 * 3)) + (sec_r001398_19_1 & 15)) & 63;
    stage_v_105_2 = ((stage_v_105_2 + (it_2 * 3)) + (sec_r001398_19_2 & 15)) & 63;
    if ((sec_r001398_19_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_105_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_105_1) + 7) & 255;
    }
    if ((sec_r001398_19_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_105_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_105_2) + 7) & 255;
    }
  }

  int stage_v_106_1 = ((pub_r001398_6_1 * 2) + 23) & 63;
  int stage_v_106_2 = ((pub_r001398_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_107_1 = ((stage_v_107_1 + (it_1 * 3)) + (stage_v_14_1 & 15)) & 63;
    stage_v_107_2 = ((stage_v_107_2 + (it_2 * 3)) + (stage_v_14_2 & 15)) & 63;
    if ((stage_v_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_107_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_107_1) + 7) & 255;
    }
    if ((stage_v_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_107_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_107_2) + 7) & 255;
    }
  }

  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_108_1 = ((stage_v_108_1 + (it_1 * 3)) + (stage_v_51_1 & 15)) & 63;
    stage_v_108_2 = ((stage_v_108_2 + (it_2 * 3)) + (stage_v_51_2 & 15)) & 63;
    if ((stage_v_51_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_108_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_108_1) + 7) & 255;
    }
    if ((stage_v_51_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_108_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_108_2) + 7) & 255;
    }
  }

  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_109_1 = ((stage_v_109_1 + (it_1 * 3)) + (stage_v_77_1 & 15)) & 63;
    stage_v_109_2 = ((stage_v_109_2 + (it_2 * 3)) + (stage_v_77_2 & 15)) & 63;
    if ((stage_v_77_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_109_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_109_1) + 7) & 255;
    }
    if ((stage_v_77_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_109_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_109_2) + 7) & 255;
    }
  }

  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_110_1 = ((stage_v_110_1 + (it_1 * 3)) + (stage_v_15_1 & 15)) & 63;
    stage_v_110_2 = ((stage_v_110_2 + (it_2 * 3)) + (stage_v_15_2 & 15)) & 63;
    if ((stage_v_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_110_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_110_1) + 7) & 255;
    }
    if ((stage_v_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_110_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_110_2) + 7) & 255;
    }
  }

  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_111_1 = ((stage_v_111_1 + (it_1 * 3)) + (sec_r001398_4_1 & 15)) & 63;
    stage_v_111_2 = ((stage_v_111_2 + (it_2 * 3)) + (sec_r001398_4_2 & 15)) & 63;
    if ((sec_r001398_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_111_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_111_1) + 7) & 255;
    }
    if ((sec_r001398_4_2 & 1) != 0)
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
    stage_v_112_1 = ((stage_v_112_1 + (it_1 * 3)) + (stage_v_105_1 & 15)) & 63;
    stage_v_112_2 = ((stage_v_112_2 + (it_2 * 3)) + (stage_v_105_2 & 15)) & 63;
    if ((stage_v_105_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_112_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_112_1) + 7) & 255;
    }
    if ((stage_v_105_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_112_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_112_2) + 7) & 255;
    }
  }

  int stage_v_113_1 = ((pub_r001398_10_1 * 2) + 48) & 63;
  int stage_v_113_2 = ((pub_r001398_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_114_1 = ((stage_v_114_1 + (it_1 * 3)) + (stage_v_20_1 & 15)) & 63;
    stage_v_114_2 = ((stage_v_114_2 + (it_2 * 3)) + (stage_v_20_2 & 15)) & 63;
    if ((stage_v_20_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_114_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_114_1) + 7) & 255;
    }
    if ((stage_v_20_2 & 1) != 0)
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
    stage_v_115_1 = ((stage_v_115_1 + (it_1 * 3)) + (sec_r001398_2_1 & 15)) & 63;
    stage_v_115_2 = ((stage_v_115_2 + (it_2 * 3)) + (sec_r001398_2_2 & 15)) & 63;
    if ((sec_r001398_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_115_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_115_1) + 7) & 255;
    }
    if ((sec_r001398_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_115_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_115_2) + 7) & 255;
    }
  }

  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_116_1 = ((stage_v_116_1 + (it_1 * 3)) + (sec_r001398_15_1 & 15)) & 63;
    stage_v_116_2 = ((stage_v_116_2 + (it_2 * 3)) + (sec_r001398_15_2 & 15)) & 63;
    if ((sec_r001398_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_116_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_116_1) + 7) & 255;
    }
    if ((sec_r001398_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_116_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_116_2) + 7) & 255;
    }
  }

  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_117_1 = ((stage_v_117_1 + (it_1 * 3)) + (stage_v_107_1 & 15)) & 63;
    stage_v_117_2 = ((stage_v_117_2 + (it_2 * 3)) + (stage_v_107_2 & 15)) & 63;
    if ((stage_v_107_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_117_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_117_1) + 7) & 255;
    }
    if ((stage_v_107_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_117_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_117_2) + 7) & 255;
    }
  }

  int stage_v_118_1 = ((pub_r001398_3_1 * 2) + 22) & 63;
  int stage_v_118_2 = ((pub_r001398_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_119_1 = ((stage_v_119_1 + (it_1 * 3)) + (sec_r001398_2_1 & 15)) & 63;
    stage_v_119_2 = ((stage_v_119_2 + (it_2 * 3)) + (sec_r001398_2_2 & 15)) & 63;
    if ((sec_r001398_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_119_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_119_1) + 7) & 255;
    }
    if ((sec_r001398_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_119_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_119_2) + 7) & 255;
    }
  }

  int stage_v_120_1 = ((pub_r001398_14_1 * 2) + 13) & 63;
  int stage_v_120_2 = ((pub_r001398_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001398_0_1 * 2) + 8) & 63;
  int stage_v_121_2 = ((pub_r001398_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001398_6_1 * 2) + 29) & 63;
  int stage_v_122_2 = ((pub_r001398_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_123_1 = ((stage_v_123_1 + (it_1 * 3)) + (sec_r001398_13_1 & 15)) & 63;
    stage_v_123_2 = ((stage_v_123_2 + (it_2 * 3)) + (sec_r001398_13_2 & 15)) & 63;
    if ((sec_r001398_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_123_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_123_1) + 7) & 255;
    }
    if ((sec_r001398_13_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_123_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_123_2) + 7) & 255;
    }
  }

  int stage_v_124_1 = ((pub_r001398_2_1 * 2) + 11) & 63;
  int stage_v_124_2 = ((pub_r001398_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_125_1 = ((stage_v_125_1 + (it_1 * 3)) + (sec_r001398_3_1 & 15)) & 63;
    stage_v_125_2 = ((stage_v_125_2 + (it_2 * 3)) + (sec_r001398_3_2 & 15)) & 63;
    if ((sec_r001398_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_125_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_125_1) + 7) & 255;
    }
    if ((sec_r001398_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_125_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_125_2) + 7) & 255;
    }
  }

  int stage_v_126_1 = ((pub_r001398_16_1 * 2) + 45) & 63;
  int stage_v_126_2 = ((pub_r001398_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_127_1 = ((stage_v_127_1 + (it_1 * 3)) + (stage_v_45_1 & 15)) & 63;
    stage_v_127_2 = ((stage_v_127_2 + (it_2 * 3)) + (stage_v_45_2 & 15)) & 63;
    if ((stage_v_45_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_127_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_127_1) + 7) & 255;
    }
    if ((stage_v_45_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_127_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_127_2) + 7) & 255;
    }
  }

  int stage_v_128_1 = ((pub_r001398_19_1 * 2) + 14) & 63;
  int stage_v_128_2 = ((pub_r001398_19_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_129_1 = ((stage_v_129_1 + (it_1 * 3)) + (stage_v_4_1 & 15)) & 63;
    stage_v_129_2 = ((stage_v_129_2 + (it_2 * 3)) + (stage_v_4_2 & 15)) & 63;
    if ((stage_v_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_129_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_129_1) + 7) & 255;
    }
    if ((stage_v_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_129_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_129_2) + 7) & 255;
    }
  }

  int stage_v_130_1 = ((pub_r001398_1_1 * 2) + 45) & 63;
  int stage_v_130_2 = ((pub_r001398_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_131_1 = ((stage_v_131_1 + (it_1 * 3)) + (sec_r001398_4_1 & 15)) & 63;
    stage_v_131_2 = ((stage_v_131_2 + (it_2 * 3)) + (sec_r001398_4_2 & 15)) & 63;
    if ((sec_r001398_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_131_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_131_1) + 7) & 255;
    }
    if ((sec_r001398_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_131_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_131_2) + 7) & 255;
    }
  }

  int stage_v_132_1 = ((pub_r001398_1_1 * 2) + 47) & 63;
  int stage_v_132_2 = ((pub_r001398_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_133_1 = ((stage_v_133_1 + (it_1 * 3)) + (sec_r001398_14_1 & 15)) & 63;
    stage_v_133_2 = ((stage_v_133_2 + (it_2 * 3)) + (sec_r001398_14_2 & 15)) & 63;
    if ((sec_r001398_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_133_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_133_1) + 7) & 255;
    }
    if ((sec_r001398_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_133_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_133_2) + 7) & 255;
    }
  }

  int stage_v_134_1 = ((pub_r001398_8_1 * 2) + 24) & 63;
  int stage_v_134_2 = ((pub_r001398_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_135_1 = ((stage_v_135_1 + (it_1 * 3)) + (stage_v_14_1 & 15)) & 63;
    stage_v_135_2 = ((stage_v_135_2 + (it_2 * 3)) + (stage_v_14_2 & 15)) & 63;
    if ((stage_v_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_135_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_135_1) + 7) & 255;
    }
    if ((stage_v_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_135_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_135_2) + 7) & 255;
    }
  }

  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_136_1 = ((stage_v_136_1 + (it_1 * 3)) + (sec_r001398_10_1 & 15)) & 63;
    stage_v_136_2 = ((stage_v_136_2 + (it_2 * 3)) + (sec_r001398_10_2 & 15)) & 63;
    if ((sec_r001398_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_136_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_136_1) + 7) & 255;
    }
    if ((sec_r001398_10_2 & 1) != 0)
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
    stage_v_137_1 = ((stage_v_137_1 + (it_1 * 3)) + (stage_v_55_1 & 15)) & 63;
    stage_v_137_2 = ((stage_v_137_2 + (it_2 * 3)) + (stage_v_55_2 & 15)) & 63;
    if ((stage_v_55_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_137_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_137_1) + 7) & 255;
    }
    if ((stage_v_55_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_137_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_137_2) + 7) & 255;
    }
  }

  int stage_v_138_1 = ((pub_r001398_7_1 * 2) + 39) & 63;
  int stage_v_138_2 = ((pub_r001398_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_139_1 = ((stage_v_139_1 + (it_1 * 3)) + (stage_v_116_1 & 15)) & 63;
    stage_v_139_2 = ((stage_v_139_2 + (it_2 * 3)) + (stage_v_116_2 & 15)) & 63;
    if ((stage_v_116_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_139_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_139_1) + 7) & 255;
    }
    if ((stage_v_116_2 & 1) != 0)
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
    stage_v_140_1 = ((stage_v_140_1 + (it_1 * 3)) + (sec_r001398_11_1 & 15)) & 63;
    stage_v_140_2 = ((stage_v_140_2 + (it_2 * 3)) + (sec_r001398_11_2 & 15)) & 63;
    if ((sec_r001398_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_140_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_140_1) + 7) & 255;
    }
    if ((sec_r001398_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_140_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_140_2) + 7) & 255;
    }
  }

  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_141_1 = ((stage_v_141_1 + (it_1 * 3)) + (stage_v_82_1 & 15)) & 63;
    stage_v_141_2 = ((stage_v_141_2 + (it_2 * 3)) + (stage_v_82_2 & 15)) & 63;
    if ((stage_v_82_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_141_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_141_1) + 7) & 255;
    }
    if ((stage_v_82_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_141_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_141_2) + 7) & 255;
    }
  }

  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_142_1 = ((stage_v_142_1 + (it_1 * 3)) + (stage_v_116_1 & 15)) & 63;
    stage_v_142_2 = ((stage_v_142_2 + (it_2 * 3)) + (stage_v_116_2 & 15)) & 63;
    if ((stage_v_116_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_142_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_142_1) + 7) & 255;
    }
    if ((stage_v_116_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_142_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_142_2) + 7) & 255;
    }
  }

  int stage_v_143_1 = ((pub_r001398_15_1 * 2) + 47) & 63;
  int stage_v_143_2 = ((pub_r001398_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_144_1 = ((stage_v_144_1 + (it_1 * 3)) + (stage_v_73_1 & 15)) & 63;
    stage_v_144_2 = ((stage_v_144_2 + (it_2 * 3)) + (stage_v_73_2 & 15)) & 63;
    if ((stage_v_73_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_144_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_144_1) + 7) & 255;
    }
    if ((stage_v_73_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_144_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_144_2) + 7) & 255;
    }
  }

  int stage_v_145_1 = ((pub_r001398_3_1 * 2) + 25) & 63;
  int stage_v_145_2 = ((pub_r001398_3_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_146_1 = ((stage_v_146_1 + (it_1 * 3)) + (stage_v_73_1 & 15)) & 63;
    stage_v_146_2 = ((stage_v_146_2 + (it_2 * 3)) + (stage_v_73_2 & 15)) & 63;
    if ((stage_v_73_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_146_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_146_1) + 7) & 255;
    }
    if ((stage_v_73_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_146_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_146_2) + 7) & 255;
    }
  }

  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_147_1 = ((stage_v_147_1 + (it_1 * 3)) + (stage_v_140_1 & 15)) & 63;
    stage_v_147_2 = ((stage_v_147_2 + (it_2 * 3)) + (stage_v_140_2 & 15)) & 63;
    if ((stage_v_140_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_147_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_147_1) + 7) & 255;
    }
    if ((stage_v_140_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_147_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_147_2) + 7) & 255;
    }
  }

  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_148_1 = ((stage_v_148_1 + (it_1 * 3)) + (stage_v_112_1 & 15)) & 63;
    stage_v_148_2 = ((stage_v_148_2 + (it_2 * 3)) + (stage_v_112_2 & 15)) & 63;
    if ((stage_v_112_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_148_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_148_1) + 7) & 255;
    }
    if ((stage_v_112_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_148_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_148_2) + 7) & 255;
    }
  }

  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_149_1 = ((stage_v_149_1 + (it_1 * 3)) + (stage_v_30_1 & 15)) & 63;
    stage_v_149_2 = ((stage_v_149_2 + (it_2 * 3)) + (stage_v_30_2 & 15)) & 63;
    if ((stage_v_30_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_149_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_149_1) + 7) & 255;
    }
    if ((stage_v_30_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_149_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_149_2) + 7) & 255;
    }
  }

  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_150_1 = ((stage_v_150_1 + (it_1 * 3)) + (stage_v_45_1 & 15)) & 63;
    stage_v_150_2 = ((stage_v_150_2 + (it_2 * 3)) + (stage_v_45_2 & 15)) & 63;
    if ((stage_v_45_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_150_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_150_1) + 7) & 255;
    }
    if ((stage_v_45_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_150_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_150_2) + 7) & 255;
    }
  }

  int stage_v_151_1 = ((pub_r001398_18_1 * 2) + 13) & 63;
  int stage_v_151_2 = ((pub_r001398_18_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_152_1 = ((stage_v_152_1 + (it_1 * 3)) + (stage_v_96_1 & 15)) & 63;
    stage_v_152_2 = ((stage_v_152_2 + (it_2 * 3)) + (stage_v_96_2 & 15)) & 63;
    if ((stage_v_96_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_152_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_152_1) + 7) & 255;
    }
    if ((stage_v_96_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_152_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_152_2) + 7) & 255;
    }
  }

  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_153_1 = ((stage_v_153_1 + (it_1 * 3)) + (stage_v_22_1 & 15)) & 63;
    stage_v_153_2 = ((stage_v_153_2 + (it_2 * 3)) + (stage_v_22_2 & 15)) & 63;
    if ((stage_v_22_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_153_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_153_1) + 7) & 255;
    }
    if ((stage_v_22_2 & 1) != 0)
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
    stage_v_154_1 = ((stage_v_154_1 + (it_1 * 3)) + (stage_v_117_1 & 15)) & 63;
    stage_v_154_2 = ((stage_v_154_2 + (it_2 * 3)) + (stage_v_117_2 & 15)) & 63;
    if ((stage_v_117_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_154_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_154_1) + 7) & 255;
    }
    if ((stage_v_117_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_154_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_154_2) + 7) & 255;
    }
  }

  int stage_v_155_1 = ((pub_r001398_2_1 * 2) + 33) & 63;
  int stage_v_155_2 = ((pub_r001398_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_156_1 = ((stage_v_156_1 + (it_1 * 3)) + (sec_r001398_13_1 & 15)) & 63;
    stage_v_156_2 = ((stage_v_156_2 + (it_2 * 3)) + (sec_r001398_13_2 & 15)) & 63;
    if ((sec_r001398_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_156_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_156_1) + 7) & 255;
    }
    if ((sec_r001398_13_2 & 1) != 0)
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
    stage_v_157_1 = ((stage_v_157_1 + (it_1 * 3)) + (stage_v_139_1 & 15)) & 63;
    stage_v_157_2 = ((stage_v_157_2 + (it_2 * 3)) + (stage_v_139_2 & 15)) & 63;
    if ((stage_v_139_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_157_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_157_1) + 7) & 255;
    }
    if ((stage_v_139_2 & 1) != 0)
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
    stage_v_158_1 = ((stage_v_158_1 + (it_1 * 3)) + (sec_r001398_16_1 & 15)) & 63;
    stage_v_158_2 = ((stage_v_158_2 + (it_2 * 3)) + (sec_r001398_16_2 & 15)) & 63;
    if ((sec_r001398_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_158_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_158_1) + 7) & 255;
    }
    if ((sec_r001398_16_2 & 1) != 0)
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
    stage_v_159_1 = ((stage_v_159_1 + (it_1 * 3)) + (sec_r001398_14_1 & 15)) & 63;
    stage_v_159_2 = ((stage_v_159_2 + (it_2 * 3)) + (sec_r001398_14_2 & 15)) & 63;
    if ((sec_r001398_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_159_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_159_1) + 7) & 255;
    }
    if ((sec_r001398_14_2 & 1) != 0)
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
    stage_v_160_1 = ((stage_v_160_1 + (it_1 * 3)) + (stage_v_11_1 & 15)) & 63;
    stage_v_160_2 = ((stage_v_160_2 + (it_2 * 3)) + (stage_v_11_2 & 15)) & 63;
    if ((stage_v_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_160_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_160_1) + 7) & 255;
    }
    if ((stage_v_11_2 & 1) != 0)
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
    stage_v_161_1 = ((stage_v_161_1 + (it_1 * 3)) + (stage_v_75_1 & 15)) & 63;
    stage_v_161_2 = ((stage_v_161_2 + (it_2 * 3)) + (stage_v_75_2 & 15)) & 63;
    if ((stage_v_75_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_161_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_161_1) + 7) & 255;
    }
    if ((stage_v_75_2 & 1) != 0)
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
    stage_v_162_1 = ((stage_v_162_1 + (it_1 * 3)) + (sec_r001398_13_1 & 15)) & 63;
    stage_v_162_2 = ((stage_v_162_2 + (it_2 * 3)) + (sec_r001398_13_2 & 15)) & 63;
    if ((sec_r001398_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_162_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_162_1) + 7) & 255;
    }
    if ((sec_r001398_13_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_162_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_162_2) + 7) & 255;
    }
  }

  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_163_1 = ((stage_v_163_1 + (it_1 * 3)) + (stage_v_61_1 & 15)) & 63;
    stage_v_163_2 = ((stage_v_163_2 + (it_2 * 3)) + (stage_v_61_2 & 15)) & 63;
    if ((stage_v_61_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_163_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_163_1) + 7) & 255;
    }
    if ((stage_v_61_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_163_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_163_2) + 7) & 255;
    }
  }

  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_164_1 = ((stage_v_164_1 + (it_1 * 3)) + (helper_flow_10_1 & 15)) & 63;
    stage_v_164_2 = ((stage_v_164_2 + (it_2 * 3)) + (helper_flow_10_2 & 15)) & 63;
    if ((helper_flow_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_164_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_164_1) + 7) & 255;
    }
    if ((helper_flow_10_2 & 1) != 0)
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
    stage_v_165_1 = ((stage_v_165_1 + (it_1 * 3)) + (stage_v_54_1 & 15)) & 63;
    stage_v_165_2 = ((stage_v_165_2 + (it_2 * 3)) + (stage_v_54_2 & 15)) & 63;
    if ((stage_v_54_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_165_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_165_1) + 7) & 255;
    }
    if ((stage_v_54_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_165_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_165_2) + 7) & 255;
    }
  }

  int stage_v_166_1 = ((pub_r001398_4_1 * 2) + 9) & 63;
  int stage_v_166_2 = ((pub_r001398_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_167_1 = ((stage_v_167_1 + (it_1 * 3)) + (helper_flow_9_1 & 15)) & 63;
    stage_v_167_2 = ((stage_v_167_2 + (it_2 * 3)) + (helper_flow_9_2 & 15)) & 63;
    if ((helper_flow_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_167_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_167_1) + 7) & 255;
    }
    if ((helper_flow_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_167_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_167_2) + 7) & 255;
    }
  }

  int stage_v_168_1 = ((pub_r001398_13_1 * 2) + 5) & 63;
  int stage_v_168_2 = ((pub_r001398_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = 0;
  int stage_v_169_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_169_1 = ((stage_v_169_1 + (it_1 * 3)) + (stage_v_115_1 & 15)) & 63;
    stage_v_169_2 = ((stage_v_169_2 + (it_2 * 3)) + (stage_v_115_2 & 15)) & 63;
    if ((stage_v_115_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_169_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_169_1) + 7) & 255;
    }
    if ((stage_v_115_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_169_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_169_2) + 7) & 255;
    }
  }

  int stage_v_170_1 = ((pub_r001398_17_1 * 2) + 46) & 63;
  int stage_v_170_2 = ((pub_r001398_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001398_5_1 * 2) + 10) & 63;
  int stage_v_171_2 = ((pub_r001398_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = 0;
  int stage_v_172_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_172_1 = ((stage_v_172_1 + (it_1 * 3)) + (stage_v_2_1 & 15)) & 63;
    stage_v_172_2 = ((stage_v_172_2 + (it_2 * 3)) + (stage_v_2_2 & 15)) & 63;
    if ((stage_v_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_172_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_172_1) + 7) & 255;
    }
    if ((stage_v_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_172_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_172_2) + 7) & 255;
    }
  }

  int stage_v_173_1 = ((pub_r001398_18_1 * 2) + 17) & 63;
  int stage_v_173_2 = ((pub_r001398_18_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = 0;
  int stage_v_174_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_174_1 = ((stage_v_174_1 + (it_1 * 3)) + (sec_r001398_10_1 & 15)) & 63;
    stage_v_174_2 = ((stage_v_174_2 + (it_2 * 3)) + (sec_r001398_10_2 & 15)) & 63;
    if ((sec_r001398_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_174_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_174_1) + 7) & 255;
    }
    if ((sec_r001398_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_174_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_174_2) + 7) & 255;
    }
  }

  int stage_v_175_1 = ((pub_r001398_7_1 * 2) + 19) & 63;
  int stage_v_175_2 = ((pub_r001398_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001398_5_1 * 2) + 23) & 63;
  int stage_v_176_2 = ((pub_r001398_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = 0;
  int stage_v_177_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_177_1 = ((stage_v_177_1 + (it_1 * 3)) + (stage_v_12_1 & 15)) & 63;
    stage_v_177_2 = ((stage_v_177_2 + (it_2 * 3)) + (stage_v_12_2 & 15)) & 63;
    if ((stage_v_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_177_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_177_1) + 7) & 255;
    }
    if ((stage_v_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_177_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_177_2) + 7) & 255;
    }
  }

  int stage_v_178_1 = ((pub_r001398_10_1 * 2) + 10) & 63;
  int stage_v_178_2 = ((pub_r001398_10_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = 0;
  int stage_v_179_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_179_1 = ((stage_v_179_1 + (it_1 * 3)) + (stage_v_66_1 & 15)) & 63;
    stage_v_179_2 = ((stage_v_179_2 + (it_2 * 3)) + (stage_v_66_2 & 15)) & 63;
    if ((stage_v_66_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_179_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_179_1) + 7) & 255;
    }
    if ((stage_v_66_2 & 1) != 0)
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
    stage_v_180_1 = ((stage_v_180_1 + (it_1 * 3)) + (stage_v_153_1 & 15)) & 63;
    stage_v_180_2 = ((stage_v_180_2 + (it_2 * 3)) + (stage_v_153_2 & 15)) & 63;
    if ((stage_v_153_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_180_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_180_1) + 7) & 255;
    }
    if ((stage_v_153_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_180_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_180_2) + 7) & 255;
    }
  }

  int stage_v_181_1 = ((pub_r001398_10_1 * 2) + 50) & 63;
  int stage_v_181_2 = ((pub_r001398_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = 0;
  int stage_v_182_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_182_1 = ((stage_v_182_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_182_2 = ((stage_v_182_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_182_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_182_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_182_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_182_2) + 7) & 255;
    }
  }

  int stage_v_183_1 = ((pub_r001398_9_1 * 2) + 22) & 63;
  int stage_v_183_2 = ((pub_r001398_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = 0;
  int stage_v_184_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_184_1 = ((stage_v_184_1 + (it_1 * 3)) + (stage_v_144_1 & 15)) & 63;
    stage_v_184_2 = ((stage_v_184_2 + (it_2 * 3)) + (stage_v_144_2 & 15)) & 63;
    if ((stage_v_144_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_184_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_184_1) + 7) & 255;
    }
    if ((stage_v_144_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_184_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_184_2) + 7) & 255;
    }
  }

  int stage_v_185_1 = 0;
  int stage_v_185_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_185_1 = ((stage_v_185_1 + (it_1 * 3)) + (stage_v_180_1 & 15)) & 63;
    stage_v_185_2 = ((stage_v_185_2 + (it_2 * 3)) + (stage_v_180_2 & 15)) & 63;
    if ((stage_v_180_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_185_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_185_1) + 7) & 255;
    }
    if ((stage_v_180_2 & 1) != 0)
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
    stage_v_186_1 = ((stage_v_186_1 + (it_1 * 3)) + (sec_r001398_3_1 & 15)) & 63;
    stage_v_186_2 = ((stage_v_186_2 + (it_2 * 3)) + (sec_r001398_3_2 & 15)) & 63;
    if ((sec_r001398_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_186_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_186_1) + 7) & 255;
    }
    if ((sec_r001398_3_2 & 1) != 0)
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
    stage_v_187_1 = ((stage_v_187_1 + (it_1 * 3)) + (sec_r001398_10_1 & 15)) & 63;
    stage_v_187_2 = ((stage_v_187_2 + (it_2 * 3)) + (sec_r001398_10_2 & 15)) & 63;
    if ((sec_r001398_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_187_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_187_1) + 7) & 255;
    }
    if ((sec_r001398_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_187_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_187_2) + 7) & 255;
    }
  }

  int stage_v_188_1 = ((pub_r001398_20_1 * 2) + 31) & 63;
  int stage_v_188_2 = ((pub_r001398_20_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = 0;
  int stage_v_189_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_189_1 = ((stage_v_189_1 + (it_1 * 3)) + (stage_v_131_1 & 15)) & 63;
    stage_v_189_2 = ((stage_v_189_2 + (it_2 * 3)) + (stage_v_131_2 & 15)) & 63;
    if ((stage_v_131_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_189_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_189_1) + 7) & 255;
    }
    if ((stage_v_131_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_189_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_189_2) + 7) & 255;
    }
  }

  int stage_v_190_1 = ((pub_r001398_14_1 * 2) + 46) & 63;
  int stage_v_190_2 = ((pub_r001398_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001398_1_1 * 2) + 25) & 63;
  int stage_v_191_2 = ((pub_r001398_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001398_16_1 * 2) + 15) & 63;
  int stage_v_192_2 = ((pub_r001398_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = 0;
  int stage_v_193_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_193_1 = ((stage_v_193_1 + (it_1 * 3)) + (helper_flow_2_1 & 15)) & 63;
    stage_v_193_2 = ((stage_v_193_2 + (it_2 * 3)) + (helper_flow_2_2 & 15)) & 63;
    if ((helper_flow_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_193_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_193_1) + 7) & 255;
    }
    if ((helper_flow_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_193_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_193_2) + 7) & 255;
    }
  }

  int stage_v_194_1 = ((pub_r001398_12_1 * 2) + 35) & 63;
  int stage_v_194_2 = ((pub_r001398_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = 0;
  int stage_v_195_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_195_1 = ((stage_v_195_1 + (it_1 * 3)) + (stage_v_161_1 & 15)) & 63;
    stage_v_195_2 = ((stage_v_195_2 + (it_2 * 3)) + (stage_v_161_2 & 15)) & 63;
    if ((stage_v_161_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_195_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_195_1) + 7) & 255;
    }
    if ((stage_v_161_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_195_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_195_2) + 7) & 255;
    }
  }

  int stage_v_196_1 = 0;
  int stage_v_196_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_196_1 = ((stage_v_196_1 + (it_1 * 3)) + (stage_v_149_1 & 15)) & 63;
    stage_v_196_2 = ((stage_v_196_2 + (it_2 * 3)) + (stage_v_149_2 & 15)) & 63;
    if ((stage_v_149_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_196_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_196_1) + 7) & 255;
    }
    if ((stage_v_149_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_196_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_196_2) + 7) & 255;
    }
  }

  int stage_v_197_1 = ((pub_r001398_2_1 * 2) + 47) & 63;
  int stage_v_197_2 = ((pub_r001398_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = 0;
  int stage_v_198_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_198_1 = ((stage_v_198_1 + (it_1 * 3)) + (stage_v_177_1 & 15)) & 63;
    stage_v_198_2 = ((stage_v_198_2 + (it_2 * 3)) + (stage_v_177_2 & 15)) & 63;
    if ((stage_v_177_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_198_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_198_1) + 7) & 255;
    }
    if ((stage_v_177_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_198_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_198_2) + 7) & 255;
    }
  }

  int stage_v_199_1 = 0;
  int stage_v_199_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_199_1 = ((stage_v_199_1 + (it_1 * 3)) + (stage_v_44_1 & 15)) & 63;
    stage_v_199_2 = ((stage_v_199_2 + (it_2 * 3)) + (stage_v_44_2 & 15)) & 63;
    if ((stage_v_44_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_199_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_199_1) + 7) & 255;
    }
    if ((stage_v_44_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_199_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_199_2) + 7) & 255;
    }
  }

  int stage_v_200_1 = 0;
  int stage_v_200_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_200_1 = ((stage_v_200_1 + (it_1 * 3)) + (stage_v_177_1 & 15)) & 63;
    stage_v_200_2 = ((stage_v_200_2 + (it_2 * 3)) + (stage_v_177_2 & 15)) & 63;
    if ((stage_v_177_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_200_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_200_1) + 7) & 255;
    }
    if ((stage_v_177_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_200_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_200_2) + 7) & 255;
    }
  }

  int stage_v_201_1 = 0;
  int stage_v_201_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_201_1 = ((stage_v_201_1 + (it_1 * 3)) + (stage_v_18_1 & 15)) & 63;
    stage_v_201_2 = ((stage_v_201_2 + (it_2 * 3)) + (stage_v_18_2 & 15)) & 63;
    if ((stage_v_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_201_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_201_1) + 7) & 255;
    }
    if ((stage_v_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_201_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_201_2) + 7) & 255;
    }
  }

  int stage_v_202_1 = 0;
  int stage_v_202_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_202_1 = ((stage_v_202_1 + (it_1 * 3)) + (stage_v_64_1 & 15)) & 63;
    stage_v_202_2 = ((stage_v_202_2 + (it_2 * 3)) + (stage_v_64_2 & 15)) & 63;
    if ((stage_v_64_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_202_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_202_1) + 7) & 255;
    }
    if ((stage_v_64_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_202_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_202_2) + 7) & 255;
    }
  }

  int stage_v_203_1 = 0;
  int stage_v_203_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_203_1 = ((stage_v_203_1 + (it_1 * 3)) + (stage_v_108_1 & 15)) & 63;
    stage_v_203_2 = ((stage_v_203_2 + (it_2 * 3)) + (stage_v_108_2 & 15)) & 63;
    if ((stage_v_108_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_203_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_203_1) + 7) & 255;
    }
    if ((stage_v_108_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_203_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_203_2) + 7) & 255;
    }
  }

  int stage_v_204_1 = 0;
  int stage_v_204_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_204_1 = ((stage_v_204_1 + (it_1 * 3)) + (sec_r001398_0_1 & 15)) & 63;
    stage_v_204_2 = ((stage_v_204_2 + (it_2 * 3)) + (sec_r001398_0_2 & 15)) & 63;
    if ((sec_r001398_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_204_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_204_1) + 7) & 255;
    }
    if ((sec_r001398_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_204_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_204_2) + 7) & 255;
    }
  }

  int stage_v_205_1 = ((pub_r001398_17_1 * 2) + 39) & 63;
  int stage_v_205_2 = ((pub_r001398_17_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001398_3_1 * 2) + 7) & 63;
  int stage_v_206_2 = ((pub_r001398_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = 0;
  int stage_v_207_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_207_1 = ((stage_v_207_1 + (it_1 * 3)) + (stage_v_82_1 & 15)) & 63;
    stage_v_207_2 = ((stage_v_207_2 + (it_2 * 3)) + (stage_v_82_2 & 15)) & 63;
    if ((stage_v_82_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_207_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_207_1) + 7) & 255;
    }
    if ((stage_v_82_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_207_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_207_2) + 7) & 255;
    }
  }

  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001398_1_1 == pub_r001398_1_2);
  __CPROVER_assume(sec_r001398_14_1 != sec_r001398_14_2);
  __CPROVER_assume(sec_r001398_6_1 != sec_r001398_6_2);
  __CPROVER_assume(pub_r001398_9_1 == pub_r001398_9_2);
  __CPROVER_assume(sec_r001398_4_1 != sec_r001398_4_2);
  __CPROVER_assume(pub_r001398_0_1 == pub_r001398_0_2);
  __CPROVER_assume(sec_r001398_9_1 != sec_r001398_9_2);
  __CPROVER_assume(sec_r001398_19_1 != sec_r001398_19_2);
  __CPROVER_assume(pub_r001398_2_1 == pub_r001398_2_2);
  __CPROVER_assume(sec_r001398_3_1 != sec_r001398_3_2);
  __CPROVER_assume(pub_r001398_5_1 == pub_r001398_5_2);
  __CPROVER_assume(pub_r001398_10_1 == pub_r001398_10_2);
  __CPROVER_assume(pub_r001398_4_1 == pub_r001398_4_2);
  __CPROVER_assume(pub_r001398_15_1 == pub_r001398_15_2);
  __CPROVER_assume(pub_r001398_20_1 == pub_r001398_20_2);
  __CPROVER_assume(pub_r001398_14_1 == pub_r001398_14_2);
  __CPROVER_assume(pub_r001398_19_1 == pub_r001398_19_2);
  __CPROVER_assume(sec_r001398_2_1 != sec_r001398_2_2);
  __CPROVER_assume(sec_r001398_5_1 != sec_r001398_5_2);
  __CPROVER_assume(sec_r001398_18_1 != sec_r001398_18_2);
  __CPROVER_assume(sec_r001398_13_1 != sec_r001398_13_2);
  __CPROVER_assume(pub_r001398_18_1 == pub_r001398_18_2);
  __CPROVER_assume(pub_r001398_3_1 == pub_r001398_3_2);
  __CPROVER_assume(pub_r001398_13_1 == pub_r001398_13_2);
  __CPROVER_assume(pub_r001398_16_1 == pub_r001398_16_2);
  __CPROVER_assume(sec_r001398_7_1 != sec_r001398_7_2);
  __CPROVER_assume(sec_r001398_1_1 != sec_r001398_1_2);
  __CPROVER_assume(sec_r001398_16_1 != sec_r001398_16_2);
  __CPROVER_assume(sec_r001398_15_1 != sec_r001398_15_2);
  __CPROVER_assume(pub_r001398_8_1 == pub_r001398_8_2);
  __CPROVER_assume(pub_r001398_7_1 == pub_r001398_7_2);
  __CPROVER_assume(sec_r001398_12_1 != sec_r001398_12_2);
  __CPROVER_assume(pub_r001398_17_1 == pub_r001398_17_2);
  __CPROVER_assume(sec_r001398_11_1 != sec_r001398_11_2);
  __CPROVER_assume(sec_r001398_10_1 != sec_r001398_10_2);
  __CPROVER_assume(sec_r001398_0_1 != sec_r001398_0_2);
  __CPROVER_assume(pub_r001398_6_1 == pub_r001398_6_2);
  __CPROVER_assume(sec_r001398_8_1 != sec_r001398_8_2);
  __CPROVER_assume(sec_r001398_17_1 != sec_r001398_17_2);
  __CPROVER_assume(pub_r001398_11_1 == pub_r001398_11_2);
  __CPROVER_assume(pub_r001398_12_1 == pub_r001398_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  assert(st_var_0_1.status == st_var_0_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.mode == st_var_1_2.mode);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.id == st_var_2_2.id);
  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  assert(st_var_2_1.timeout == st_var_2_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.pitch == st_var_3_2.pitch);
  assert(st_var_3_1.heading == st_var_3_2.heading);
  assert(st_var_3_1.coord_z == st_var_3_2.coord_z);
  assert(st_var_3_1.coord_y == st_var_3_2.coord_y);
  assert(st_var_3_1.coord_x == st_var_3_2.coord_x);
  assert(st_var_3_1.norm_sq == st_var_3_2.norm_sq);
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
}


