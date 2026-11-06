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
struct Vector3D_R000126_2613_0
{
  short norm_sq;
  int pitch;
  int heading;
  int coord_x;
  int coord_y;
  short coord_z;
  int buffer[3];
};
struct EventLog_R000126_2613_1
{
  int code;
  int signature;
  short facility;
  unsigned char timestamp;
  int severity;
  unsigned char seq;
  int buffer[3];
};
struct DeviceConfig_R000126_2613_2
{
  short stop_bits;
  int baud_rate;
  int id;
  int port;
  unsigned char parity;
  short timeout;
  int buffer[3];
};
struct MatrixBlock_R000126_2613_3
{
  short dim;
  int density;
  short stride;
  int buffer[3];
};
union TelemetryField_R000126_2613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000126_2613_1
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
void fn_R000126_2613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000126_2613_1 st_1 = {0};
  struct EventLog_R000126_2613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_97_1 = local_arr_1[aux_1 % 3];
  int margin_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_97_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_97_1 == margin_97_2);
}

int fn_R000126_2613_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000126_2613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int margin_97 = local_arr[aux % 3];
  acc = (acc + (margin_97 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000126_2613_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000126_2613_3 st_1 = {0};
  struct MatrixBlock_R000126_2613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_62_1 = local_arr_1[aux_1 % 3];
  int scale_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_62_2 * 2)) & 127;
  int bound_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_12_1 > 19)
  {
    acc_1 = ((acc_1 + (bound_12_1 * 2)) + 5) & 127;
    aux_1 ^= bound_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_12_2 > 19)
  {
    acc_2 = ((acc_2 + (bound_12_2 * 2)) + 5) & 127;
    aux_2 ^= bound_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_62_1 == scale_62_2);
  assert(bound_12_1 == bound_12_2);
}

int fn_R000126_2613_1(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000126_2613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int scale_62 = local_arr[aux % 3];
  acc = (acc + (scale_62 * 2)) & 127;
  int bound_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_12 > 19)
  {
    acc = ((acc + (bound_12 * 2)) + 5) & 127;
    aux ^= bound_12 & 15;
  }
  else
  {
    acc = ((acc - bound_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000126_2613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000126_2613_1 st_1 = {0};
  struct EventLog_R000126_2613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int tally_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_14_1)
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

  switch (tally_14_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_92_1 > 20)
  {
    acc_1 = ((acc_1 + (margin_92_1 * 2)) + 5) & 127;
    aux_1 ^= margin_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_92_2 > 20)
  {
    acc_2 = ((acc_2 + (margin_92_2 * 2)) + 5) & 127;
    aux_2 ^= margin_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_92_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_14_1 == tally_14_2);
  assert(margin_92_1 == margin_92_2);
}

int fn_R000126_2613_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000126_2613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int tally_14 = (aux + st.buffer[1]) & 3;
  switch (tally_14)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_92 > 20)
  {
    acc = ((acc + (margin_92 * 2)) + 5) & 127;
    aux ^= margin_92 & 15;
  }
  else
  {
    acc = ((acc - margin_92) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000126_2613_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000126_2613_0 st_1 = {0};
  struct Vector3D_R000126_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_10_1 = local_arr_1[aux_1 % 3];
  int coefficient_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_10_2 * 2)) & 127;
  int delta_32_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_32_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_32_1 > 19)
  {
    acc_1 = ((acc_1 + (delta_32_1 * 2)) + 5) & 127;
    aux_1 ^= delta_32_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_32_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_32_2 > 19)
  {
    acc_2 = ((acc_2 + (delta_32_2 * 2)) + 5) & 127;
    aux_2 ^= delta_32_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_32_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_81_1)
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

  switch (factor_81_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_10_1 == coefficient_10_2);
  assert(delta_32_1 == delta_32_2);
  assert(factor_81_1 == factor_81_2);
}

int fn_R000126_2613_3(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000126_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int coefficient_10 = local_arr[aux % 3];
  acc = (acc + (coefficient_10 * 2)) & 127;
  int delta_32 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_32 > 19)
  {
    acc = ((acc + (delta_32 * 2)) + 5) & 127;
    aux ^= delta_32 & 15;
  }
  else
  {
    acc = ((acc - delta_32) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_81 = (aux + st.buffer[1]) & 3;
  switch (factor_81)
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

void fn_R000126_2613_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000126_2613_2 st_1 = {0};
  struct DeviceConfig_R000126_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_74_1)
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

  switch (stride_74_2)
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

  int bound_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_27_1 > 27)
  {
    acc_1 = ((acc_1 + (bound_27_1 * 2)) + 5) & 127;
    aux_1 ^= bound_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_27_2 > 27)
  {
    acc_2 = ((acc_2 + (bound_27_2 * 2)) + 5) & 127;
    aux_2 ^= bound_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_27_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_74_1 == stride_74_2);
  assert(bound_27_1 == bound_27_2);
}

int fn_R000126_2613_4(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000126_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_74 = (aux + st.buffer[1]) & 3;
  switch (stride_74)
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

  int bound_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_27 > 27)
  {
    acc = ((acc + (bound_27 * 2)) + 5) & 127;
    aux ^= bound_27 & 15;
  }
  else
  {
    acc = ((acc - bound_27) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000126_2613_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000126_2613_0 st_1 = {0};
  struct Vector3D_R000126_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int cursor_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_76_1) & 63;
  aux_2 = (aux_2 + cursor_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_76_1 == cursor_76_2);
}

int fn_R000126_2613_5(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000126_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int cursor_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_76) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000126_2613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000126_2613_0 st_1 = {0};
  struct Vector3D_R000126_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_97_1 = local_arr_1[aux_1 % 3];
  int checksum_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_97_2 * 2)) & 127;
  int quotient_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_44_1) & 63;
  aux_2 = (aux_2 + quotient_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_97_1 == checksum_97_2);
  assert(quotient_44_1 == quotient_44_2);
}

int fn_R000126_2613_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000126_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int checksum_97 = local_arr[aux % 3];
  acc = (acc + (checksum_97 * 2)) & 127;
  int quotient_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_44) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000126_2613_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000126_2613_1 st_1 = {0};
  struct EventLog_R000126_2613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_12_1 = local_arr_1[aux_1 % 3];
  int tally_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_12_2 * 2)) & 127;
  int threshold_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_81_1) & 63;
  aux_2 = (aux_2 + threshold_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_39_1)
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

  switch (threshold_39_2)
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
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_12_1 == tally_12_2);
  assert(threshold_81_1 == threshold_81_2);
  assert(threshold_39_1 == threshold_39_2);
}

int fn_R000126_2613_7(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000126_2613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_12 = local_arr[aux % 3];
  acc = (acc + (tally_12 * 2)) & 127;
  int threshold_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_81) & 63;
  acc ^= aux;
  int threshold_39 = (aux + st.buffer[1]) & 3;
  switch (threshold_39)
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

void fn_R000126_2613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000126_2613_2 st_1 = {0};
  struct DeviceConfig_R000126_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int margin_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_79_1) & 63;
  aux_2 = (aux_2 + margin_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_61_1 > 24)
  {
    acc_1 = ((acc_1 + (factor_61_1 * 2)) + 5) & 127;
    aux_1 ^= factor_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_61_2 > 24)
  {
    acc_2 = ((acc_2 + (factor_61_2 * 2)) + 5) & 127;
    aux_2 ^= factor_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_61_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_79_1 == margin_79_2);
  assert(factor_61_1 == factor_61_2);
}

int fn_R000126_2613_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000126_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int margin_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_79) & 63;
  acc ^= aux;
  int factor_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_61 > 24)
  {
    acc = ((acc + (factor_61 * 2)) + 5) & 127;
    aux ^= factor_61 & 15;
  }
  else
  {
    acc = ((acc - factor_61) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000126_2613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000126_2613_0 st_1 = {0};
  struct Vector3D_R000126_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int threshold_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_45_1) & 63;
  aux_2 = (aux_2 + threshold_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_42_1 > 19)
  {
    acc_1 = ((acc_1 + (tally_42_1 * 2)) + 5) & 127;
    aux_1 ^= tally_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_42_2 > 19)
  {
    acc_2 = ((acc_2 + (tally_42_2 * 2)) + 5) & 127;
    aux_2 ^= tally_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_42_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_45_1 == threshold_45_2);
  assert(tally_42_1 == tally_42_2);
}

int fn_R000126_2613_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000126_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int threshold_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_45) & 63;
  acc ^= aux;
  int tally_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_42 > 19)
  {
    acc = ((acc + (tally_42 * 2)) + 5) & 127;
    aux ^= tally_42 & 15;
  }
  else
  {
    acc = ((acc - tally_42) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000126_2613_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000126_2613_3 st_1 = {0};
  struct MatrixBlock_R000126_2613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_79_1 > 47)
  {
    acc_1 = ((acc_1 + (tracker_79_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_79_2 > 47)
  {
    acc_2 = ((acc_2 + (tracker_79_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_22_1)
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

  switch (segment_22_2)
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

  int coefficient_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_27_1) & 63;
  aux_2 = (aux_2 + coefficient_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_79_1 == tracker_79_2);
  assert(segment_22_1 == segment_22_2);
  assert(coefficient_27_1 == coefficient_27_2);
}

int fn_R000126_2613_10(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000126_2613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_79 > 47)
  {
    acc = ((acc + (tracker_79 * 2)) + 5) & 127;
    aux ^= tracker_79 & 15;
  }
  else
  {
    acc = ((acc - tracker_79) + 11) & 127;
    aux += 3;
  }
  int segment_22 = (aux + st.buffer[1]) & 3;
  switch (segment_22)
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

  int coefficient_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_27) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000126_2613_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000126_2613_3 st_1 = {0};
  struct MatrixBlock_R000126_2613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int bound_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_44_1) & 63;
  aux_2 = (aux_2 + bound_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_59_1)
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

  switch (checksum_59_2)
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

  int damping_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_62_1 > 29)
  {
    acc_1 = ((acc_1 + (damping_62_1 * 2)) + 5) & 127;
    aux_1 ^= damping_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_62_2 > 29)
  {
    acc_2 = ((acc_2 + (damping_62_2 * 2)) + 5) & 127;
    aux_2 ^= damping_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_32_1 = local_arr_1[aux_1 % 3];
  int index_reg_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_44_1 == bound_44_2);
  assert(checksum_59_1 == checksum_59_2);
  assert(damping_62_1 == damping_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_32_1 == index_reg_32_2);
}

int fn_R000126_2613_11(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000126_2613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int bound_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_44) & 63;
  acc ^= aux;
  int checksum_59 = (aux + st.buffer[1]) & 3;
  switch (checksum_59)
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

  int damping_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_62 > 29)
  {
    acc = ((acc + (damping_62 * 2)) + 5) & 127;
    aux ^= damping_62 & 15;
  }
  else
  {
    acc = ((acc - damping_62) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_32 = local_arr[aux % 3];
  acc = (acc + (index_reg_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000126_2613_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000126_2613_0 st_1 = {0};
  struct Vector3D_R000126_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_99_1 = local_arr_1[aux_1 % 3];
  int cursor_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_99_2 * 2)) & 127;
  int sample_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_60_1 > 50)
  {
    acc_1 = ((acc_1 + (sample_60_1 * 2)) + 5) & 127;
    aux_1 ^= sample_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_60_2 > 50)
  {
    acc_2 = ((acc_2 + (sample_60_2 * 2)) + 5) & 127;
    aux_2 ^= sample_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_60_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_23_1) & 63;
  aux_2 = (aux_2 + accumulator_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_99_1 == cursor_99_2);
  assert(sample_60_1 == sample_60_2);
  assert(accumulator_23_1 == accumulator_23_2);
}

int fn_R000126_2613_12(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000126_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int cursor_99 = local_arr[aux % 3];
  acc = (acc + (cursor_99 * 2)) & 127;
  int sample_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_60 > 50)
  {
    acc = ((acc + (sample_60 * 2)) + 5) & 127;
    aux ^= sample_60 & 15;
  }
  else
  {
    acc = ((acc - sample_60) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_23) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000126_2613_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000126_2613_1 st_1 = {0};
  struct EventLog_R000126_2613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_90_1 = local_arr_1[aux_1 % 3];
  int checksum_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_90_2 * 2)) & 127;
  int vector_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_79_1) & 63;
  aux_2 = (aux_2 + vector_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_10_1 > 42)
  {
    acc_1 = ((acc_1 + (residue_10_1 * 2)) + 5) & 127;
    aux_1 ^= residue_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_10_2 > 42)
  {
    acc_2 = ((acc_2 + (residue_10_2 * 2)) + 5) & 127;
    aux_2 ^= residue_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_70_1)
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

  switch (tracker_70_2)
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
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_90_1 == checksum_90_2);
  assert(vector_79_1 == vector_79_2);
  assert(residue_10_1 == residue_10_2);
  assert(tracker_70_1 == tracker_70_2);
}

int fn_R000126_2613_13(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000126_2613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int checksum_90 = local_arr[aux % 3];
  acc = (acc + (checksum_90 * 2)) & 127;
  int vector_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_79) & 63;
  acc ^= aux;
  int residue_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_10 > 42)
  {
    acc = ((acc + (residue_10 * 2)) + 5) & 127;
    aux ^= residue_10 & 15;
  }
  else
  {
    acc = ((acc - residue_10) + 11) & 127;
    aux += 3;
  }
  int tracker_70 = (aux + st.buffer[1]) & 3;
  switch (tracker_70)
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

void fn_R000126_2613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000126_2613_3 st_1 = {0};
  struct MatrixBlock_R000126_2613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_89_1 = local_arr_1[aux_1 % 3];
  int bound_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_89_2 * 2)) & 127;
  int delta_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_43_1 > 30)
  {
    acc_1 = ((acc_1 + (delta_43_1 * 2)) + 5) & 127;
    aux_1 ^= delta_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_43_2 > 30)
  {
    acc_2 = ((acc_2 + (delta_43_2 * 2)) + 5) & 127;
    aux_2 ^= delta_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_41_1)
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

  switch (quotient_41_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_89_1 == bound_89_2);
  assert(delta_43_1 == delta_43_2);
  assert(quotient_41_1 == quotient_41_2);
}

int fn_R000126_2613_14(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000126_2613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int bound_89 = local_arr[aux % 3];
  acc = (acc + (bound_89 * 2)) & 127;
  int delta_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_43 > 30)
  {
    acc = ((acc + (delta_43 * 2)) + 5) & 127;
    aux ^= delta_43 & 15;
  }
  else
  {
    acc = ((acc - delta_43) + 11) & 127;
    aux += 3;
  }
  int quotient_41 = (aux + st.buffer[1]) & 3;
  switch (quotient_41)
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
  return (acc + aux) & 255;
}

void fn_R000126_2613_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000126_2613_2 st_1 = {0};
  struct DeviceConfig_R000126_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_68_1 = local_arr_1[aux_1 % 3];
  int factor_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_68_2 * 2)) & 127;
  int accumulator_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_71_1) & 63;
  aux_2 = (aux_2 + accumulator_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_48_1 > 35)
  {
    acc_1 = ((acc_1 + (pivot_48_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_48_2 > 35)
  {
    acc_2 = ((acc_2 + (pivot_48_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_48_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_68_1 == factor_68_2);
  assert(accumulator_71_1 == accumulator_71_2);
  assert(pivot_48_1 == pivot_48_2);
}

int fn_R000126_2613_15(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000126_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int factor_68 = local_arr[aux % 3];
  acc = (acc + (factor_68 * 2)) & 127;
  int accumulator_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_71) & 63;
  acc ^= aux;
  int pivot_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_48 > 35)
  {
    acc = ((acc + (pivot_48 * 2)) + 5) & 127;
    aux ^= pivot_48 & 15;
  }
  else
  {
    acc = ((acc - pivot_48) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000126_2613_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000126_2613_2 st_1 = {0};
  struct DeviceConfig_R000126_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int quotient_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_55_1 > 32)
  {
    acc_1 = ((acc_1 + (quotient_55_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_55_2 > 32)
  {
    acc_2 = ((acc_2 + (quotient_55_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_55_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_62_1)
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

  switch (residue_62_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_55_1 == quotient_55_2);
  assert(residue_62_1 == residue_62_2);
}

int fn_R000126_2613_16(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000126_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int quotient_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_55 > 32)
  {
    acc = ((acc + (quotient_55 * 2)) + 5) & 127;
    aux ^= quotient_55 & 15;
  }
  else
  {
    acc = ((acc - quotient_55) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_62 = (aux + st.buffer[1]) & 3;
  switch (residue_62)
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

void fn_R000126_2613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000126_2613_0 st_1 = {0};
  struct Vector3D_R000126_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int pivot_53_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_53_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_53_1) & 63;
  aux_2 = (aux_2 + pivot_53_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_39_1 = local_arr_1[aux_1 % 3];
  int mask_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_39_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_53_1 == pivot_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_39_1 == mask_39_2);
}

int fn_R000126_2613_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000126_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int pivot_53 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_53) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int mask_39 = local_arr[aux % 3];
  acc = (acc + (mask_39 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000126_2613_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000126_2613_2 st_1 = {0};
  struct DeviceConfig_R000126_2613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int offset_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_58_1 > 31)
  {
    acc_1 = ((acc_1 + (offset_58_1 * 2)) + 5) & 127;
    aux_1 ^= offset_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_58_2 > 31)
  {
    acc_2 = ((acc_2 + (offset_58_2 * 2)) + 5) & 127;
    aux_2 ^= offset_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_58_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.timeout == st_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_58_1 == offset_58_2);
}

int fn_R000126_2613_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000126_2613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int offset_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_58 > 31)
  {
    acc = ((acc + (offset_58 * 2)) + 5) & 127;
    aux ^= offset_58 & 15;
  }
  else
  {
    acc = ((acc - offset_58) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000126_2613_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000126_2613_0 st_1 = {0};
  struct Vector3D_R000126_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_84_1 = local_arr_1[aux_1 % 3];
  int phase_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_84_2 * 2)) & 127;
  int index_reg_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_64_1)
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

  switch (index_reg_64_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_84_1 == phase_84_2);
  assert(index_reg_64_1 == index_reg_64_2);
}

int fn_R000126_2613_19(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000126_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int phase_84 = local_arr[aux % 3];
  acc = (acc + (phase_84 * 2)) & 127;
  int index_reg_64 = (aux + st.buffer[1]) & 3;
  switch (index_reg_64)
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

void fn_R000126_2613_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000126_2613_3 st_1 = {0};
  struct MatrixBlock_R000126_2613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int factor_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_19_1) & 63;
  aux_2 = (aux_2 + factor_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_11_1)
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

  switch (quotient_11_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.stride == st_2.stride);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_19_1 == factor_19_2);
  assert(quotient_11_1 == quotient_11_2);
}

int fn_R000126_2613_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000126_2613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int factor_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_19) & 63;
  acc ^= aux;
  int quotient_11 = (aux + st.buffer[1]) & 3;
  switch (quotient_11)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000126_2613_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000126_2613_0 st_1 = {0};
  struct Vector3D_R000126_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int stride_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_78_1 > 36)
  {
    acc_1 = ((acc_1 + (stride_78_1 * 2)) + 5) & 127;
    aux_1 ^= stride_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_78_2 > 36)
  {
    acc_2 = ((acc_2 + (stride_78_2 * 2)) + 5) & 127;
    aux_2 ^= stride_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_30_1) & 63;
  aux_2 = (aux_2 + scale_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_42_1)
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

  switch (mask_42_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_78_1 == stride_78_2);
  assert(scale_30_1 == scale_30_2);
  assert(mask_42_1 == mask_42_2);
}

int fn_R000126_2613_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000126_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int stride_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_78 > 36)
  {
    acc = ((acc + (stride_78 * 2)) + 5) & 127;
    aux ^= stride_78 & 15;
  }
  else
  {
    acc = ((acc - stride_78) + 11) & 127;
    aux += 3;
  }
  int scale_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_30) & 63;
  acc ^= aux;
  int mask_42 = (aux + st.buffer[1]) & 3;
  switch (mask_42)
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

void fn_R000126_2613_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000126_2613_1 st_1 = {0};
  struct EventLog_R000126_2613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int vector_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_22_1) & 63;
  aux_2 = (aux_2 + vector_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_22_1 == vector_22_2);
}

int fn_R000126_2613_22(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000126_2613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int vector_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_22) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000126_2613_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000126_2613_0 st_1 = {0};
  struct Vector3D_R000126_2613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int damping_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_18_1) & 63;
  aux_2 = (aux_2 + damping_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_40_1)
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

  switch (sample_40_2)
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

  int scale_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_16_1 > 34)
  {
    acc_1 = ((acc_1 + (scale_16_1 * 2)) + 5) & 127;
    aux_1 ^= scale_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_16_2 > 34)
  {
    acc_2 = ((acc_2 + (scale_16_2 * 2)) + 5) & 127;
    aux_2 ^= scale_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_16_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_18_1 == damping_18_2);
  assert(sample_40_1 == sample_40_2);
  assert(scale_16_1 == scale_16_2);
}

int fn_R000126_2613_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000126_2613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int damping_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_18) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_40 = (aux + st.buffer[1]) & 3;
  switch (sample_40)
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

  int scale_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_16 > 34)
  {
    acc = ((acc + (scale_16 * 2)) + 5) & 127;
    aux ^= scale_16 & 15;
  }
  else
  {
    acc = ((acc - scale_16) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000126_0_1;
  int sec_r000126_0_2;
  int sec_r000126_1_1;
  int sec_r000126_1_2;
  int sec_r000126_2_1;
  int sec_r000126_2_2;
  int sec_r000126_3_1;
  int sec_r000126_3_2;
  int sec_r000126_4_1;
  int sec_r000126_4_2;
  int sec_r000126_5_1;
  int sec_r000126_5_2;
  int sec_r000126_6_1;
  int sec_r000126_6_2;
  int sec_r000126_7_1;
  int sec_r000126_7_2;
  int sec_r000126_8_1;
  int sec_r000126_8_2;
  int sec_r000126_9_1;
  int sec_r000126_9_2;
  int sec_r000126_10_1;
  int sec_r000126_10_2;
  int sec_r000126_11_1;
  int sec_r000126_11_2;
  int sec_r000126_12_1;
  int sec_r000126_12_2;
  int sec_r000126_13_1;
  int sec_r000126_13_2;
  int sec_r000126_14_1;
  int sec_r000126_14_2;
  int sec_r000126_15_1;
  int sec_r000126_15_2;
  int sec_r000126_16_1;
  int sec_r000126_16_2;
  int sec_r000126_17_1;
  int sec_r000126_17_2;
  int sec_r000126_18_1;
  int sec_r000126_18_2;
  int sec_r000126_19_1;
  int sec_r000126_19_2;
  int sec_r000126_20_1;
  int sec_r000126_20_2;
  int sec_r000126_21_1;
  int sec_r000126_21_2;
  int pub_r000126_0_1;
  int pub_r000126_0_2;
  int pub_r000126_1_1;
  int pub_r000126_1_2;
  int pub_r000126_2_1;
  int pub_r000126_2_2;
  int pub_r000126_3_1;
  int pub_r000126_3_2;
  int pub_r000126_4_1;
  int pub_r000126_4_2;
  int pub_r000126_5_1;
  int pub_r000126_5_2;
  int pub_r000126_6_1;
  int pub_r000126_6_2;
  int pub_r000126_7_1;
  int pub_r000126_7_2;
  int pub_r000126_8_1;
  int pub_r000126_8_2;
  int pub_r000126_9_1;
  int pub_r000126_9_2;
  int pub_r000126_10_1;
  int pub_r000126_10_2;
  int pub_r000126_11_1;
  int pub_r000126_11_2;
  int pub_r000126_12_1;
  int pub_r000126_12_2;
  int pub_r000126_13_1;
  int pub_r000126_13_2;
  int pub_r000126_14_1;
  int pub_r000126_14_2;
  int pub_r000126_15_1;
  int pub_r000126_15_2;
  int pub_r000126_16_1;
  int pub_r000126_16_2;
  int pub_r000126_17_1;
  int pub_r000126_17_2;
  int pub_r000126_18_1;
  int pub_r000126_18_2;
  int pub_r000126_19_1;
  int pub_r000126_19_2;
  int pub_r000126_20_1;
  int pub_r000126_20_2;
  int pub_r000126_21_1;
  int pub_r000126_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000126_0_1 >= (-100)) && (pub_r000126_0_1 <= 100));
  __CPROVER_assume((pub_r000126_0_2 >= (-100)) && (pub_r000126_0_2 <= 100));
  __CPROVER_assume((pub_r000126_1_1 >= (-100)) && (pub_r000126_1_1 <= 100));
  __CPROVER_assume((pub_r000126_1_2 >= (-100)) && (pub_r000126_1_2 <= 100));
  __CPROVER_assume((pub_r000126_2_1 >= (-100)) && (pub_r000126_2_1 <= 100));
  __CPROVER_assume((pub_r000126_2_2 >= (-100)) && (pub_r000126_2_2 <= 100));
  __CPROVER_assume((pub_r000126_3_1 >= (-100)) && (pub_r000126_3_1 <= 100));
  __CPROVER_assume((pub_r000126_3_2 >= (-100)) && (pub_r000126_3_2 <= 100));
  __CPROVER_assume((pub_r000126_4_1 >= (-100)) && (pub_r000126_4_1 <= 100));
  __CPROVER_assume((pub_r000126_4_2 >= (-100)) && (pub_r000126_4_2 <= 100));
  __CPROVER_assume((pub_r000126_5_1 >= (-100)) && (pub_r000126_5_1 <= 100));
  __CPROVER_assume((pub_r000126_5_2 >= (-100)) && (pub_r000126_5_2 <= 100));
  __CPROVER_assume((pub_r000126_6_1 >= (-100)) && (pub_r000126_6_1 <= 100));
  __CPROVER_assume((pub_r000126_6_2 >= (-100)) && (pub_r000126_6_2 <= 100));
  __CPROVER_assume((pub_r000126_7_1 >= (-100)) && (pub_r000126_7_1 <= 100));
  __CPROVER_assume((pub_r000126_7_2 >= (-100)) && (pub_r000126_7_2 <= 100));
  __CPROVER_assume((pub_r000126_8_1 >= (-100)) && (pub_r000126_8_1 <= 100));
  __CPROVER_assume((pub_r000126_8_2 >= (-100)) && (pub_r000126_8_2 <= 100));
  __CPROVER_assume((pub_r000126_9_1 >= (-100)) && (pub_r000126_9_1 <= 100));
  __CPROVER_assume((pub_r000126_9_2 >= (-100)) && (pub_r000126_9_2 <= 100));
  __CPROVER_assume((pub_r000126_10_1 >= (-100)) && (pub_r000126_10_1 <= 100));
  __CPROVER_assume((pub_r000126_10_2 >= (-100)) && (pub_r000126_10_2 <= 100));
  __CPROVER_assume((pub_r000126_11_1 >= (-100)) && (pub_r000126_11_1 <= 100));
  __CPROVER_assume((pub_r000126_11_2 >= (-100)) && (pub_r000126_11_2 <= 100));
  __CPROVER_assume((pub_r000126_12_1 >= (-100)) && (pub_r000126_12_1 <= 100));
  __CPROVER_assume((pub_r000126_12_2 >= (-100)) && (pub_r000126_12_2 <= 100));
  __CPROVER_assume((pub_r000126_13_1 >= (-100)) && (pub_r000126_13_1 <= 100));
  __CPROVER_assume((pub_r000126_13_2 >= (-100)) && (pub_r000126_13_2 <= 100));
  __CPROVER_assume((pub_r000126_14_1 >= (-100)) && (pub_r000126_14_1 <= 100));
  __CPROVER_assume((pub_r000126_14_2 >= (-100)) && (pub_r000126_14_2 <= 100));
  __CPROVER_assume((pub_r000126_15_1 >= (-100)) && (pub_r000126_15_1 <= 100));
  __CPROVER_assume((pub_r000126_15_2 >= (-100)) && (pub_r000126_15_2 <= 100));
  __CPROVER_assume((pub_r000126_16_1 >= (-100)) && (pub_r000126_16_1 <= 100));
  __CPROVER_assume((pub_r000126_16_2 >= (-100)) && (pub_r000126_16_2 <= 100));
  __CPROVER_assume((pub_r000126_17_1 >= (-100)) && (pub_r000126_17_1 <= 100));
  __CPROVER_assume((pub_r000126_17_2 >= (-100)) && (pub_r000126_17_2 <= 100));
  __CPROVER_assume((pub_r000126_18_1 >= (-100)) && (pub_r000126_18_1 <= 100));
  __CPROVER_assume((pub_r000126_18_2 >= (-100)) && (pub_r000126_18_2 <= 100));
  __CPROVER_assume((pub_r000126_19_1 >= (-100)) && (pub_r000126_19_1 <= 100));
  __CPROVER_assume((pub_r000126_19_2 >= (-100)) && (pub_r000126_19_2 <= 100));
  __CPROVER_assume((pub_r000126_20_1 >= (-100)) && (pub_r000126_20_1 <= 100));
  __CPROVER_assume((pub_r000126_20_2 >= (-100)) && (pub_r000126_20_2 <= 100));
  __CPROVER_assume((pub_r000126_21_1 >= (-100)) && (pub_r000126_21_1 <= 100));
  __CPROVER_assume((pub_r000126_21_2 >= (-100)) && (pub_r000126_21_2 <= 100));
  __CPROVER_assume((sec_r000126_0_1 >= 0) && (sec_r000126_0_1 <= 255));
  __CPROVER_assume((sec_r000126_0_2 >= 0) && (sec_r000126_0_2 <= 255));
  __CPROVER_assume((sec_r000126_1_1 >= 0) && (sec_r000126_1_1 <= 255));
  __CPROVER_assume((sec_r000126_1_2 >= 0) && (sec_r000126_1_2 <= 255));
  __CPROVER_assume((sec_r000126_2_1 >= 0) && (sec_r000126_2_1 <= 255));
  __CPROVER_assume((sec_r000126_2_2 >= 0) && (sec_r000126_2_2 <= 255));
  __CPROVER_assume((sec_r000126_3_1 >= 0) && (sec_r000126_3_1 <= 255));
  __CPROVER_assume((sec_r000126_3_2 >= 0) && (sec_r000126_3_2 <= 255));
  __CPROVER_assume((sec_r000126_4_1 >= 0) && (sec_r000126_4_1 <= 255));
  __CPROVER_assume((sec_r000126_4_2 >= 0) && (sec_r000126_4_2 <= 255));
  __CPROVER_assume((sec_r000126_5_1 >= 0) && (sec_r000126_5_1 <= 255));
  __CPROVER_assume((sec_r000126_5_2 >= 0) && (sec_r000126_5_2 <= 255));
  __CPROVER_assume((sec_r000126_6_1 >= 0) && (sec_r000126_6_1 <= 255));
  __CPROVER_assume((sec_r000126_6_2 >= 0) && (sec_r000126_6_2 <= 255));
  __CPROVER_assume((sec_r000126_7_1 >= 0) && (sec_r000126_7_1 <= 255));
  __CPROVER_assume((sec_r000126_7_2 >= 0) && (sec_r000126_7_2 <= 255));
  __CPROVER_assume((sec_r000126_8_1 >= 0) && (sec_r000126_8_1 <= 255));
  __CPROVER_assume((sec_r000126_8_2 >= 0) && (sec_r000126_8_2 <= 255));
  __CPROVER_assume((sec_r000126_9_1 >= 0) && (sec_r000126_9_1 <= 255));
  __CPROVER_assume((sec_r000126_9_2 >= 0) && (sec_r000126_9_2 <= 255));
  __CPROVER_assume((sec_r000126_10_1 >= 0) && (sec_r000126_10_1 <= 255));
  __CPROVER_assume((sec_r000126_10_2 >= 0) && (sec_r000126_10_2 <= 255));
  __CPROVER_assume((sec_r000126_11_1 >= 0) && (sec_r000126_11_1 <= 255));
  __CPROVER_assume((sec_r000126_11_2 >= 0) && (sec_r000126_11_2 <= 255));
  __CPROVER_assume((sec_r000126_12_1 >= 0) && (sec_r000126_12_1 <= 255));
  __CPROVER_assume((sec_r000126_12_2 >= 0) && (sec_r000126_12_2 <= 255));
  __CPROVER_assume((sec_r000126_13_1 >= 0) && (sec_r000126_13_1 <= 255));
  __CPROVER_assume((sec_r000126_13_2 >= 0) && (sec_r000126_13_2 <= 255));
  __CPROVER_assume((sec_r000126_14_1 >= 0) && (sec_r000126_14_1 <= 255));
  __CPROVER_assume((sec_r000126_14_2 >= 0) && (sec_r000126_14_2 <= 255));
  __CPROVER_assume((sec_r000126_15_1 >= 0) && (sec_r000126_15_1 <= 255));
  __CPROVER_assume((sec_r000126_15_2 >= 0) && (sec_r000126_15_2 <= 255));
  __CPROVER_assume((sec_r000126_16_1 >= 0) && (sec_r000126_16_1 <= 255));
  __CPROVER_assume((sec_r000126_16_2 >= 0) && (sec_r000126_16_2 <= 255));
  __CPROVER_assume((sec_r000126_17_1 >= 0) && (sec_r000126_17_1 <= 255));
  __CPROVER_assume((sec_r000126_17_2 >= 0) && (sec_r000126_17_2 <= 255));
  __CPROVER_assume((sec_r000126_18_1 >= 0) && (sec_r000126_18_1 <= 255));
  __CPROVER_assume((sec_r000126_18_2 >= 0) && (sec_r000126_18_2 <= 255));
  __CPROVER_assume((sec_r000126_19_1 >= 0) && (sec_r000126_19_1 <= 255));
  __CPROVER_assume((sec_r000126_19_2 >= 0) && (sec_r000126_19_2 <= 255));
  __CPROVER_assume((sec_r000126_20_1 >= 0) && (sec_r000126_20_1 <= 255));
  __CPROVER_assume((sec_r000126_20_2 >= 0) && (sec_r000126_20_2 <= 255));
  __CPROVER_assume((sec_r000126_21_1 >= 0) && (sec_r000126_21_1 <= 255));
  __CPROVER_assume((sec_r000126_21_2 >= 0) && (sec_r000126_21_2 <= 255));
  struct Vector3D_R000126_2613_0 st_var_0_1 = {0};
  struct Vector3D_R000126_2613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000126_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000126_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000126_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000126_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000126_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000126_0_2 + 7) & 15;
  struct EventLog_R000126_2613_1 st_var_1_1 = {0};
  struct EventLog_R000126_2613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000126_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000126_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000126_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000126_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000126_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000126_0_2 + 9) & 15;
  struct DeviceConfig_R000126_2613_2 st_var_2_1 = {0};
  struct DeviceConfig_R000126_2613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000126_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000126_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000126_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000126_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000126_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000126_0_2 + 11) & 15;
  struct MatrixBlock_R000126_2613_3 st_var_3_1 = {0};
  struct MatrixBlock_R000126_2613_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000126_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000126_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000126_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000126_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000126_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000126_0_2 + 13) & 15;
  union TelemetryField_R000126_2613_0 u_var_1;
  union TelemetryField_R000126_2613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 26)
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
  if (stage_v_0_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 26)
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
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 49)
    {
      chk_sum_1 ^= stage_v_1_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_1_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 49)
    {
      chk_sum_2 ^= stage_v_1_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_2_1 = (st_var_2_1.buffer[0] ^ 5) & 3;
  int stage_v_2_2 = (st_var_2_2.buffer[0] ^ 5) & 3;
  switch (stage_v_2_1)
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

  switch (stage_v_2_2)
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
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 6) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 6) & 15;
  int stage_v_5_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_5_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  chk_sum_1 ^= stage_v_5_1;
  chk_sum_2 ^= stage_v_5_2;
  int stage_v_6_1 = (st_var_2_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_2_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  int stage_v_7_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (12 & 31);
  int stage_v_7_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (12 & 31);
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= (stage_v_7_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_7_2 << 1) & 127;
  int stage_v_8_1 = ((st_var_0_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_0_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 27)
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
  if (stage_v_8_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 27)
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
  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 11) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 12) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= stage_v_11_1;
  chk_sum_2 ^= stage_v_11_2;
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (st_var_0_1.buffer[0] ^ 19) & 3;
  int stage_v_16_2 = (st_var_0_2.buffer[0] ^ 19) & 3;
  switch (stage_v_16_1)
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

  switch (stage_v_16_2)
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

  int stage_v_17_1 = ((st_var_1_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_1_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 48)
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
  if (stage_v_17_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 48)
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
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (st_var_0_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_0_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 8) & 255;
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

  switch (stage_v_20_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 8) & 255;
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

  int stage_v_21_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_21_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 23) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 23) & 15;
  int stage_v_22_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_22_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= stage_v_22_1;
  chk_sum_2 ^= stage_v_22_2;
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
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_25_1 = ((stage_v_25_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_25_2 = ((stage_v_25_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (31 & 31);
  int stage_v_26_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (31 & 31);
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= (stage_v_26_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_26_2 << 1) & 127;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 28) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 28) & 15;
  int stage_v_27_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_27_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= stage_v_27_1;
  chk_sum_2 ^= stage_v_27_2;
  int stage_v_28_1 = (st_var_0_1.buffer[0] ^ 31) & 3;
  int stage_v_28_2 = (st_var_0_2.buffer[0] ^ 31) & 3;
  switch (stage_v_28_1)
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

  switch (stage_v_28_2)
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

  int stage_v_29_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (34 & 31);
  int stage_v_29_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (34 & 31);
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= (stage_v_29_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_29_2 << 1) & 127;
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
  int stage_v_31_1 = ((st_var_3_1.buffer[1] * 2) + 100) & 63;
  int stage_v_31_2 = ((st_var_3_2.buffer[1] * 2) + 100) & 63;
  if (stage_v_31_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_31_1) - 5) & 255;
    if (stage_v_31_1 > 38)
    {
      chk_sum_1 ^= stage_v_31_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_31_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_31_2) - 5) & 255;
    if (stage_v_31_2 > 38)
    {
      chk_sum_2 ^= stage_v_31_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_32_1 = ((st_var_0_1.buffer[2] * 2) + 103) & 63;
  int stage_v_32_2 = ((st_var_0_2.buffer[2] * 2) + 103) & 63;
  if (stage_v_32_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_32_1) - 5) & 255;
    if (stage_v_32_1 > 33)
    {
      chk_sum_1 ^= stage_v_32_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_32_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_32_2) - 5) & 255;
    if (stage_v_32_2 > 33)
    {
      chk_sum_2 ^= stage_v_32_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 34) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  int stage_v_34_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (39 & 31);
  int stage_v_34_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (39 & 31);
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= (stage_v_34_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_34_2 << 1) & 127;
  int stage_v_35_1 = (st_var_3_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_3_2.buffer[0] ^ 38) & 3;
  switch (stage_v_35_1)
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

  switch (stage_v_35_2)
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

  int stage_v_36_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (41 & 31);
  int stage_v_36_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (41 & 31);
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= (stage_v_36_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_36_2 << 1) & 127;
  int stage_v_37_1 = (st_var_1_1.buffer[0] ^ 40) & 3;
  int stage_v_37_2 = (st_var_1_2.buffer[0] ^ 40) & 3;
  switch (stage_v_37_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 2) & 255;
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

  switch (stage_v_37_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 2) & 255;
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

  int stage_v_38_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (43 & 31);
  int stage_v_38_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (43 & 31);
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= (stage_v_38_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_38_2 << 1) & 127;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_40_1 = ((stage_v_40_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_40_2 = ((stage_v_40_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 42) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 42) & 15;
  int stage_v_41_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_41_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= stage_v_41_1;
  chk_sum_2 ^= stage_v_41_2;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_42_1 = ((stage_v_42_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_42_2 = ((stage_v_42_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (48 & 31);
  int stage_v_43_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (48 & 31);
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= (stage_v_43_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_43_2 << 1) & 127;
  int stage_v_44_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (49 & 31);
  int stage_v_44_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (49 & 31);
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= (stage_v_44_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_44_2 << 1) & 127;
  int stage_v_45_1 = table_1[1];
  int stage_v_45_2 = table_2[1];
  table_1[1] = (table_1[2] + 91) & 63;
  table_2[1] = (table_2[2] + 91) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_46_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_47_1 = (st_var_3_1.buffer[0] ^ 50) & 3;
  int stage_v_47_2 = (st_var_3_2.buffer[0] ^ 50) & 3;
  switch (stage_v_47_1)
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

  switch (stage_v_47_2)
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

  int stage_v_48_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_48_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_48_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_48_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_49_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_49_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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

  int stage_v_52_1 = ((st_var_0_1.buffer[1] * 2) + 163) & 63;
  int stage_v_52_2 = ((st_var_0_2.buffer[1] * 2) + 163) & 63;
  if (stage_v_52_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_52_1) - 5) & 255;
    if (stage_v_52_1 > 53)
    {
      chk_sum_1 ^= stage_v_52_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_52_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_52_2) - 5) & 255;
    if (stage_v_52_2 > 53)
    {
      chk_sum_2 ^= stage_v_52_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_54_1 = ((stage_v_54_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_54_2 = ((stage_v_54_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((st_var_3_1.buffer[1] * 2) + 172) & 63;
  int stage_v_55_2 = ((st_var_3_2.buffer[1] * 2) + 172) & 63;
  if (stage_v_55_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_55_1) - 5) & 255;
    if (stage_v_55_1 > 39)
    {
      chk_sum_1 ^= stage_v_55_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_55_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_55_2) - 5) & 255;
    if (stage_v_55_2 > 39)
    {
      chk_sum_2 ^= stage_v_55_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_56_1 = ((stage_v_56_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_56_2 = ((stage_v_56_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_57_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_57_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_57_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_58_1 = (st_var_2_1.buffer[0] ^ 61) & 3;
  int stage_v_58_2 = (st_var_2_2.buffer[0] ^ 61) & 3;
  switch (stage_v_58_1)
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

  switch (stage_v_58_2)
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

  int stage_v_59_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (64 & 31);
  int stage_v_59_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (64 & 31);
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= (stage_v_59_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_59_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 61) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 61) & 15;
  int stage_v_60_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_60_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= stage_v_60_1;
  chk_sum_2 ^= stage_v_60_2;
  int stage_v_61_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (66 & 31);
  int stage_v_61_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (66 & 31);
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= (stage_v_61_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_61_2 << 1) & 127;
  int stage_v_62_1 = table_1[2];
  int stage_v_62_2 = table_2[2];
  table_1[2] = (table_1[3] + 125) & 63;
  table_2[2] = (table_2[3] + 125) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_63_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_64_1 = table_1[0];
  int stage_v_64_2 = table_2[0];
  table_1[0] = (table_1[1] + 129) & 63;
  table_2[0] = (table_2[1] + 129) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_65_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_65_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_65_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_66_1 = ((st_var_2_1.buffer[0] * 2) + 205) & 63;
  int stage_v_66_2 = ((st_var_2_2.buffer[0] * 2) + 205) & 63;
  if (stage_v_66_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_66_1) - 5) & 255;
    if (stage_v_66_1 > 33)
    {
      chk_sum_1 ^= stage_v_66_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_66_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_66_2) - 5) & 255;
    if (stage_v_66_2 > 33)
    {
      chk_sum_2 ^= stage_v_66_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_67_1 = ((st_var_3_1.buffer[1] * 2) + 208) & 63;
  int stage_v_67_2 = ((st_var_3_2.buffer[1] * 2) + 208) & 63;
  if (stage_v_67_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_67_1) - 5) & 255;
    if (stage_v_67_1 > 30)
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
  if (stage_v_67_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_67_2) - 5) & 255;
    if (stage_v_67_2 > 30)
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
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_69_1 = ((stage_v_69_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_69_2 = ((stage_v_69_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_70_1 = ((stage_v_70_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_70_2 = ((stage_v_70_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = table_1[3];
  int stage_v_71_2 = table_2[3];
  table_1[3] = (table_1[0] + 143) & 63;
  table_2[3] = (table_2[0] + 143) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = (st_var_0_1.buffer[0] ^ 75) & 3;
  int stage_v_72_2 = (st_var_0_2.buffer[0] ^ 75) & 3;
  switch (stage_v_72_1)
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

  switch (stage_v_72_2)
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

  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_73_1 = ((stage_v_73_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_73_2 = ((stage_v_73_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (79 & 31);
  int stage_v_74_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (79 & 31);
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  chk_sum_1 ^= (stage_v_74_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_74_2 << 1) & 127;
  int stage_v_75_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_75_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_76_1 = ((stage_v_76_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_76_2 = ((stage_v_76_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_77_1 = ((stage_v_77_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = table_1[2];
  int stage_v_78_2 = table_2[2];
  table_1[2] = (table_1[3] + 157) & 63;
  table_2[2] = (table_2[3] + 157) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((st_var_3_1.buffer[1] * 2) + 244) & 63;
  int stage_v_79_2 = ((st_var_3_2.buffer[1] * 2) + 244) & 63;
  if (stage_v_79_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_79_1) - 5) & 255;
    if (stage_v_79_1 > 34)
    {
      chk_sum_1 ^= stage_v_79_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_79_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_79_2) - 5) & 255;
    if (stage_v_79_2 > 34)
    {
      chk_sum_2 ^= stage_v_79_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_80_1 = ((stage_v_80_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_80_2 = ((stage_v_80_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = table_1[1];
  int stage_v_81_2 = table_2[1];
  table_1[1] = (table_1[2] + 163) & 63;
  table_2[1] = (table_2[2] + 163) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_82_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_82_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_82_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_83_1 = ((stage_v_83_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_83_2 = ((stage_v_83_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (89 & 31);
  int stage_v_84_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (89 & 31);
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  chk_sum_1 ^= (stage_v_84_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_84_2 << 1) & 127;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_85_1 = ((stage_v_85_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_85_2 = ((stage_v_85_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = (st_var_2_1.buffer[0] ^ 89) & 3;
  int stage_v_86_2 = (st_var_2_2.buffer[0] ^ 89) & 3;
  switch (stage_v_86_1)
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

  switch (stage_v_86_2)
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

  int stage_v_87_1 = table_1[3];
  int stage_v_87_2 = table_2[3];
  table_1[3] = (table_1[0] + 175) & 63;
  table_2[3] = (table_2[0] + 175) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (93 & 31);
  int stage_v_88_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (93 & 31);
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= (stage_v_88_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_88_2 << 1) & 127;
  int stage_v_89_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (94 & 31);
  int stage_v_89_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (94 & 31);
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  chk_sum_1 ^= (stage_v_89_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_89_2 << 1) & 127;
  int stage_v_90_1 = table_1[2];
  int stage_v_90_2 = table_2[2];
  table_1[2] = (table_1[3] + 181) & 63;
  table_2[2] = (table_2[3] + 181) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = table_1[3];
  int stage_v_91_2 = table_2[3];
  table_1[3] = (table_1[0] + 183) & 63;
  table_2[3] = (table_2[0] + 183) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((sec_r000126_19_1 & 63) > 52)
  {
    stage_v_92_1 = ((pub_r000126_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  }
  else
  {
    stage_v_92_1 = ((pub_r000126_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
  }
  if ((sec_r000126_19_2 & 63) > 52)
  {
    stage_v_92_2 = ((pub_r000126_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  }
  else
  {
    stage_v_92_2 = ((pub_r000126_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((sec_r000126_21_1 & 63) > 38)
  {
    stage_v_93_1 = ((pub_r000126_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  }
  else
  {
    stage_v_93_1 = ((pub_r000126_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 9) & 255;
  }
  if ((sec_r000126_21_2 & 63) > 38)
  {
    stage_v_93_2 = ((pub_r000126_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  }
  else
  {
    stage_v_93_2 = ((pub_r000126_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000126_21_1 & 63) > 15)
  {
    stage_v_94_1 = ((pub_r000126_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  }
  else
  {
    stage_v_94_1 = ((pub_r000126_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 9) & 255;
  }
  if ((sec_r000126_21_2 & 63) > 15)
  {
    stage_v_94_2 = ((pub_r000126_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  }
  else
  {
    stage_v_94_2 = ((pub_r000126_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_94_1 & 63) > 39)
  {
    stage_v_95_1 = ((pub_r000126_20_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  }
  else
  {
    stage_v_95_1 = ((pub_r000126_20_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 9) & 255;
  }
  if ((stage_v_94_2 & 63) > 39)
  {
    stage_v_95_2 = ((pub_r000126_20_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  }
  else
  {
    stage_v_95_2 = ((pub_r000126_20_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_93_1 & 63) > 41)
  {
    stage_v_96_1 = ((pub_r000126_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  }
  else
  {
    stage_v_96_1 = ((pub_r000126_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
  }
  if ((stage_v_93_2 & 63) > 41)
  {
    stage_v_96_2 = ((pub_r000126_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  }
  else
  {
    stage_v_96_2 = ((pub_r000126_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000126_18_1 & 63) > 32)
  {
    stage_v_97_1 = ((pub_r000126_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  }
  else
  {
    stage_v_97_1 = ((pub_r000126_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 9) & 255;
  }
  if ((sec_r000126_18_2 & 63) > 32)
  {
    stage_v_97_2 = ((pub_r000126_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  }
  else
  {
    stage_v_97_2 = ((pub_r000126_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000126_9_1 & 63) > 42)
  {
    stage_v_98_1 = ((pub_r000126_20_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  }
  else
  {
    stage_v_98_1 = ((pub_r000126_20_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
  }
  if ((sec_r000126_9_2 & 63) > 42)
  {
    stage_v_98_2 = ((pub_r000126_20_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  }
  else
  {
    stage_v_98_2 = ((pub_r000126_20_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000126_7_1 & 63) > 25)
  {
    stage_v_99_1 = ((pub_r000126_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  }
  else
  {
    stage_v_99_1 = ((pub_r000126_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
  }
  if ((sec_r000126_7_2 & 63) > 25)
  {
    stage_v_99_2 = ((pub_r000126_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  }
  else
  {
    stage_v_99_2 = ((pub_r000126_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_93_1 & 63) > 36)
  {
    stage_v_100_1 = ((pub_r000126_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  }
  else
  {
    stage_v_100_1 = ((pub_r000126_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 9) & 255;
  }
  if ((stage_v_93_2 & 63) > 36)
  {
    stage_v_100_2 = ((pub_r000126_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  }
  else
  {
    stage_v_100_2 = ((pub_r000126_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((sec_r000126_4_1 & 63) > 59)
  {
    stage_v_101_1 = ((pub_r000126_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  }
  else
  {
    stage_v_101_1 = ((pub_r000126_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 9) & 255;
  }
  if ((sec_r000126_4_2 & 63) > 59)
  {
    stage_v_101_2 = ((pub_r000126_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  }
  else
  {
    stage_v_101_2 = ((pub_r000126_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_95_1 & 63) > 32)
  {
    stage_v_102_1 = ((pub_r000126_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  }
  else
  {
    stage_v_102_1 = ((pub_r000126_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 9) & 255;
  }
  if ((stage_v_95_2 & 63) > 32)
  {
    stage_v_102_2 = ((pub_r000126_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  }
  else
  {
    stage_v_102_2 = ((pub_r000126_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000126_5_1 & 63) > 18)
  {
    stage_v_103_1 = ((pub_r000126_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  }
  else
  {
    stage_v_103_1 = ((pub_r000126_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 9) & 255;
  }
  if ((sec_r000126_5_2 & 63) > 18)
  {
    stage_v_103_2 = ((pub_r000126_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  }
  else
  {
    stage_v_103_2 = ((pub_r000126_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_92_1 & 63) > 35)
  {
    stage_v_104_1 = ((pub_r000126_20_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  }
  else
  {
    stage_v_104_1 = ((pub_r000126_20_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
  }
  if ((stage_v_92_2 & 63) > 35)
  {
    stage_v_104_2 = ((pub_r000126_20_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  }
  else
  {
    stage_v_104_2 = ((pub_r000126_20_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000126_3_1 & 63) > 47)
  {
    stage_v_105_1 = ((pub_r000126_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  }
  else
  {
    stage_v_105_1 = ((pub_r000126_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 9) & 255;
  }
  if ((sec_r000126_3_2 & 63) > 47)
  {
    stage_v_105_2 = ((pub_r000126_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  }
  else
  {
    stage_v_105_2 = ((pub_r000126_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_96_1 & 63) > 15)
  {
    stage_v_106_1 = ((pub_r000126_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  }
  else
  {
    stage_v_106_1 = ((pub_r000126_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 9) & 255;
  }
  if ((stage_v_96_2 & 63) > 15)
  {
    stage_v_106_2 = ((pub_r000126_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  }
  else
  {
    stage_v_106_2 = ((pub_r000126_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000126_1_1 & 63) > 22)
  {
    stage_v_107_1 = ((pub_r000126_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  }
  else
  {
    stage_v_107_1 = ((pub_r000126_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 9) & 255;
  }
  if ((sec_r000126_1_2 & 63) > 22)
  {
    stage_v_107_2 = ((pub_r000126_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  }
  else
  {
    stage_v_107_2 = ((pub_r000126_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_101_1 & 63) > 28)
  {
    stage_v_108_1 = ((pub_r000126_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  }
  else
  {
    stage_v_108_1 = ((pub_r000126_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
  }
  if ((stage_v_101_2 & 63) > 28)
  {
    stage_v_108_2 = ((pub_r000126_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  }
  else
  {
    stage_v_108_2 = ((pub_r000126_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_92_1 & 63) > 32)
  {
    stage_v_109_1 = ((pub_r000126_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  }
  else
  {
    stage_v_109_1 = ((pub_r000126_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 9) & 255;
  }
  if ((stage_v_92_2 & 63) > 32)
  {
    stage_v_109_2 = ((pub_r000126_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  }
  else
  {
    stage_v_109_2 = ((pub_r000126_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000126_0_1 & 63) > 22)
  {
    stage_v_110_1 = ((pub_r000126_20_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  }
  else
  {
    stage_v_110_1 = ((pub_r000126_20_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 9) & 255;
  }
  if ((sec_r000126_0_2 & 63) > 22)
  {
    stage_v_110_2 = ((pub_r000126_20_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  }
  else
  {
    stage_v_110_2 = ((pub_r000126_20_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_104_1 & 63) > 24)
  {
    stage_v_111_1 = ((pub_r000126_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  }
  else
  {
    stage_v_111_1 = ((pub_r000126_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 9) & 255;
  }
  if ((stage_v_104_2 & 63) > 24)
  {
    stage_v_111_2 = ((pub_r000126_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  }
  else
  {
    stage_v_111_2 = ((pub_r000126_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_96_1 & 63) > 15)
  {
    stage_v_112_1 = ((pub_r000126_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  }
  else
  {
    stage_v_112_1 = ((pub_r000126_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 9) & 255;
  }
  if ((stage_v_96_2 & 63) > 15)
  {
    stage_v_112_2 = ((pub_r000126_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  }
  else
  {
    stage_v_112_2 = ((pub_r000126_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_99_1 & 63) > 43)
  {
    stage_v_113_1 = ((pub_r000126_21_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  }
  else
  {
    stage_v_113_1 = ((pub_r000126_21_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 9) & 255;
  }
  if ((stage_v_99_2 & 63) > 43)
  {
    stage_v_113_2 = ((pub_r000126_21_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  }
  else
  {
    stage_v_113_2 = ((pub_r000126_21_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_100_1 & 63) > 36)
  {
    stage_v_114_1 = ((pub_r000126_19_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  }
  else
  {
    stage_v_114_1 = ((pub_r000126_19_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 9) & 255;
  }
  if ((stage_v_100_2 & 63) > 36)
  {
    stage_v_114_2 = ((pub_r000126_19_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  }
  else
  {
    stage_v_114_2 = ((pub_r000126_19_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_97_1 & 63) > 57)
  {
    stage_v_115_1 = ((pub_r000126_5_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  }
  else
  {
    stage_v_115_1 = ((pub_r000126_5_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 9) & 255;
  }
  if ((stage_v_97_2 & 63) > 57)
  {
    stage_v_115_2 = ((pub_r000126_5_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  }
  else
  {
    stage_v_115_2 = ((pub_r000126_5_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_102_1 & 63) > 59)
  {
    stage_v_116_1 = ((pub_r000126_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  }
  else
  {
    stage_v_116_1 = ((pub_r000126_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 9) & 255;
  }
  if ((stage_v_102_2 & 63) > 59)
  {
    stage_v_116_2 = ((pub_r000126_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  }
  else
  {
    stage_v_116_2 = ((pub_r000126_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000126_18_1 & 63) > 32)
  {
    stage_v_117_1 = ((pub_r000126_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  }
  else
  {
    stage_v_117_1 = ((pub_r000126_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 9) & 255;
  }
  if ((sec_r000126_18_2 & 63) > 32)
  {
    stage_v_117_2 = ((pub_r000126_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  }
  else
  {
    stage_v_117_2 = ((pub_r000126_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000126_14_1 & 63) > 16)
  {
    stage_v_118_1 = ((pub_r000126_20_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  }
  else
  {
    stage_v_118_1 = ((pub_r000126_20_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 9) & 255;
  }
  if ((sec_r000126_14_2 & 63) > 16)
  {
    stage_v_118_2 = ((pub_r000126_20_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  }
  else
  {
    stage_v_118_2 = ((pub_r000126_20_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_100_1 & 63) > 55)
  {
    stage_v_119_1 = ((pub_r000126_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  }
  else
  {
    stage_v_119_1 = ((pub_r000126_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
  }
  if ((stage_v_100_2 & 63) > 55)
  {
    stage_v_119_2 = ((pub_r000126_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  }
  else
  {
    stage_v_119_2 = ((pub_r000126_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000126_1_1 & 63) > 34)
  {
    stage_v_120_1 = ((pub_r000126_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  }
  else
  {
    stage_v_120_1 = ((pub_r000126_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
  }
  if ((sec_r000126_1_2 & 63) > 34)
  {
    stage_v_120_2 = ((pub_r000126_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  }
  else
  {
    stage_v_120_2 = ((pub_r000126_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000126_15_1 & 63) > 40)
  {
    stage_v_121_1 = ((pub_r000126_13_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  }
  else
  {
    stage_v_121_1 = ((pub_r000126_13_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 9) & 255;
  }
  if ((sec_r000126_15_2 & 63) > 40)
  {
    stage_v_121_2 = ((pub_r000126_13_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  }
  else
  {
    stage_v_121_2 = ((pub_r000126_13_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_100_1 & 63) > 48)
  {
    stage_v_122_1 = ((pub_r000126_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  }
  else
  {
    stage_v_122_1 = ((pub_r000126_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
  }
  if ((stage_v_100_2 & 63) > 48)
  {
    stage_v_122_2 = ((pub_r000126_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  }
  else
  {
    stage_v_122_2 = ((pub_r000126_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_98_1 & 63) > 37)
  {
    stage_v_123_1 = ((pub_r000126_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  }
  else
  {
    stage_v_123_1 = ((pub_r000126_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
  }
  if ((stage_v_98_2 & 63) > 37)
  {
    stage_v_123_2 = ((pub_r000126_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  }
  else
  {
    stage_v_123_2 = ((pub_r000126_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((stage_v_111_1 & 63) > 24)
  {
    stage_v_124_1 = ((pub_r000126_1_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  }
  else
  {
    stage_v_124_1 = ((pub_r000126_1_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
  }
  if ((stage_v_111_2 & 63) > 24)
  {
    stage_v_124_2 = ((pub_r000126_1_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  }
  else
  {
    stage_v_124_2 = ((pub_r000126_1_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_104_1 & 63) > 33)
  {
    stage_v_125_1 = ((pub_r000126_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  }
  else
  {
    stage_v_125_1 = ((pub_r000126_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 9) & 255;
  }
  if ((stage_v_104_2 & 63) > 33)
  {
    stage_v_125_2 = ((pub_r000126_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  }
  else
  {
    stage_v_125_2 = ((pub_r000126_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_95_1 & 63) > 19)
  {
    stage_v_126_1 = ((pub_r000126_16_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  }
  else
  {
    stage_v_126_1 = ((pub_r000126_16_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 9) & 255;
  }
  if ((stage_v_95_2 & 63) > 19)
  {
    stage_v_126_2 = ((pub_r000126_16_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  }
  else
  {
    stage_v_126_2 = ((pub_r000126_16_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_116_1 & 63) > 21)
  {
    stage_v_127_1 = ((pub_r000126_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  }
  else
  {
    stage_v_127_1 = ((pub_r000126_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 9) & 255;
  }
  if ((stage_v_116_2 & 63) > 21)
  {
    stage_v_127_2 = ((pub_r000126_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  }
  else
  {
    stage_v_127_2 = ((pub_r000126_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((sec_r000126_8_1 & 63) > 25)
  {
    stage_v_128_1 = ((pub_r000126_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  }
  else
  {
    stage_v_128_1 = ((pub_r000126_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 9) & 255;
  }
  if ((sec_r000126_8_2 & 63) > 25)
  {
    stage_v_128_2 = ((pub_r000126_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  }
  else
  {
    stage_v_128_2 = ((pub_r000126_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_117_1 & 63) > 41)
  {
    stage_v_129_1 = ((pub_r000126_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  }
  else
  {
    stage_v_129_1 = ((pub_r000126_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
  }
  if ((stage_v_117_2 & 63) > 41)
  {
    stage_v_129_2 = ((pub_r000126_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  }
  else
  {
    stage_v_129_2 = ((pub_r000126_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_98_1 & 63) > 52)
  {
    stage_v_130_1 = ((pub_r000126_20_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  }
  else
  {
    stage_v_130_1 = ((pub_r000126_20_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 9) & 255;
  }
  if ((stage_v_98_2 & 63) > 52)
  {
    stage_v_130_2 = ((pub_r000126_20_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  }
  else
  {
    stage_v_130_2 = ((pub_r000126_20_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((stage_v_117_1 & 63) > 17)
  {
    stage_v_131_1 = ((pub_r000126_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  }
  else
  {
    stage_v_131_1 = ((pub_r000126_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 9) & 255;
  }
  if ((stage_v_117_2 & 63) > 17)
  {
    stage_v_131_2 = ((pub_r000126_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  }
  else
  {
    stage_v_131_2 = ((pub_r000126_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_93_1 & 63) > 59)
  {
    stage_v_132_1 = ((pub_r000126_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  }
  else
  {
    stage_v_132_1 = ((pub_r000126_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
  }
  if ((stage_v_93_2 & 63) > 59)
  {
    stage_v_132_2 = ((pub_r000126_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  }
  else
  {
    stage_v_132_2 = ((pub_r000126_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_130_1 & 63) > 28)
  {
    stage_v_133_1 = ((pub_r000126_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  }
  else
  {
    stage_v_133_1 = ((pub_r000126_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
  }
  if ((stage_v_130_2 & 63) > 28)
  {
    stage_v_133_2 = ((pub_r000126_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  }
  else
  {
    stage_v_133_2 = ((pub_r000126_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((sec_r000126_1_1 & 63) > 44)
  {
    stage_v_134_1 = ((pub_r000126_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  }
  else
  {
    stage_v_134_1 = ((pub_r000126_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 9) & 255;
  }
  if ((sec_r000126_1_2 & 63) > 44)
  {
    stage_v_134_2 = ((pub_r000126_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  }
  else
  {
    stage_v_134_2 = ((pub_r000126_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_133_1 & 63) > 39)
  {
    stage_v_135_1 = ((pub_r000126_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  }
  else
  {
    stage_v_135_1 = ((pub_r000126_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 9) & 255;
  }
  if ((stage_v_133_2 & 63) > 39)
  {
    stage_v_135_2 = ((pub_r000126_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  }
  else
  {
    stage_v_135_2 = ((pub_r000126_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  if ((sec_r000126_1_1 & 63) > 26)
  {
    stage_v_136_1 = ((pub_r000126_11_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  }
  else
  {
    stage_v_136_1 = ((pub_r000126_11_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
  }
  if ((sec_r000126_1_2 & 63) > 26)
  {
    stage_v_136_2 = ((pub_r000126_11_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  }
  else
  {
    stage_v_136_2 = ((pub_r000126_11_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = 0;
  int stage_v_137_2 = 0;
  if ((stage_v_132_1 & 63) > 47)
  {
    stage_v_137_1 = ((pub_r000126_4_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  }
  else
  {
    stage_v_137_1 = ((pub_r000126_4_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
  }
  if ((stage_v_132_2 & 63) > 47)
  {
    stage_v_137_2 = ((pub_r000126_4_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  }
  else
  {
    stage_v_137_2 = ((pub_r000126_4_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  if ((stage_v_105_1 & 63) > 41)
  {
    stage_v_138_1 = ((pub_r000126_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  }
  else
  {
    stage_v_138_1 = ((pub_r000126_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
  }
  if ((stage_v_105_2 & 63) > 41)
  {
    stage_v_138_2 = ((pub_r000126_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  }
  else
  {
    stage_v_138_2 = ((pub_r000126_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  if ((stage_v_102_1 & 63) > 35)
  {
    stage_v_139_1 = ((pub_r000126_17_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  }
  else
  {
    stage_v_139_1 = ((pub_r000126_17_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
  }
  if ((stage_v_102_2 & 63) > 35)
  {
    stage_v_139_2 = ((pub_r000126_17_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  }
  else
  {
    stage_v_139_2 = ((pub_r000126_17_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  if ((stage_v_112_1 & 63) > 52)
  {
    stage_v_140_1 = ((pub_r000126_20_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  }
  else
  {
    stage_v_140_1 = ((pub_r000126_20_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
  }
  if ((stage_v_112_2 & 63) > 52)
  {
    stage_v_140_2 = ((pub_r000126_20_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  }
  else
  {
    stage_v_140_2 = ((pub_r000126_20_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  if ((stage_v_123_1 & 63) > 23)
  {
    stage_v_141_1 = ((pub_r000126_18_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  }
  else
  {
    stage_v_141_1 = ((pub_r000126_18_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 9) & 255;
  }
  if ((stage_v_123_2 & 63) > 23)
  {
    stage_v_141_2 = ((pub_r000126_18_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  }
  else
  {
    stage_v_141_2 = ((pub_r000126_18_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = 0;
  int stage_v_142_2 = 0;
  if ((stage_v_119_1 & 63) > 50)
  {
    stage_v_142_1 = ((pub_r000126_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  }
  else
  {
    stage_v_142_1 = ((pub_r000126_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 9) & 255;
  }
  if ((stage_v_119_2 & 63) > 50)
  {
    stage_v_142_2 = ((pub_r000126_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  }
  else
  {
    stage_v_142_2 = ((pub_r000126_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = 0;
  int stage_v_143_2 = 0;
  if ((stage_v_94_1 & 63) > 53)
  {
    stage_v_143_1 = ((pub_r000126_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  }
  else
  {
    stage_v_143_1 = ((pub_r000126_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 9) & 255;
  }
  if ((stage_v_94_2 & 63) > 53)
  {
    stage_v_143_2 = ((pub_r000126_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  }
  else
  {
    stage_v_143_2 = ((pub_r000126_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  if ((sec_r000126_2_1 & 63) > 32)
  {
    stage_v_144_1 = ((pub_r000126_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  }
  else
  {
    stage_v_144_1 = ((pub_r000126_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
  }
  if ((sec_r000126_2_2 & 63) > 32)
  {
    stage_v_144_2 = ((pub_r000126_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  }
  else
  {
    stage_v_144_2 = ((pub_r000126_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  if ((stage_v_94_1 & 63) > 28)
  {
    stage_v_145_1 = ((pub_r000126_2_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  }
  else
  {
    stage_v_145_1 = ((pub_r000126_2_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
  }
  if ((stage_v_94_2 & 63) > 28)
  {
    stage_v_145_2 = ((pub_r000126_2_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  }
  else
  {
    stage_v_145_2 = ((pub_r000126_2_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  if ((stage_v_106_1 & 63) > 45)
  {
    stage_v_146_1 = ((pub_r000126_12_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  }
  else
  {
    stage_v_146_1 = ((pub_r000126_12_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 9) & 255;
  }
  if ((stage_v_106_2 & 63) > 45)
  {
    stage_v_146_2 = ((pub_r000126_12_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  }
  else
  {
    stage_v_146_2 = ((pub_r000126_12_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  if ((sec_r000126_6_1 & 63) > 15)
  {
    stage_v_147_1 = ((pub_r000126_15_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  }
  else
  {
    stage_v_147_1 = ((pub_r000126_15_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 9) & 255;
  }
  if ((sec_r000126_6_2 & 63) > 15)
  {
    stage_v_147_2 = ((pub_r000126_15_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  }
  else
  {
    stage_v_147_2 = ((pub_r000126_15_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  if ((sec_r000126_19_1 & 63) > 42)
  {
    stage_v_148_1 = ((pub_r000126_3_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  }
  else
  {
    stage_v_148_1 = ((pub_r000126_3_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 9) & 255;
  }
  if ((sec_r000126_19_2 & 63) > 42)
  {
    stage_v_148_2 = ((pub_r000126_3_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  }
  else
  {
    stage_v_148_2 = ((pub_r000126_3_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  if ((sec_r000126_3_1 & 63) > 27)
  {
    stage_v_149_1 = ((pub_r000126_0_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  }
  else
  {
    stage_v_149_1 = ((pub_r000126_0_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
  }
  if ((sec_r000126_3_2 & 63) > 27)
  {
    stage_v_149_2 = ((pub_r000126_0_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  }
  else
  {
    stage_v_149_2 = ((pub_r000126_0_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  if ((stage_v_126_1 & 63) > 30)
  {
    stage_v_150_1 = ((pub_r000126_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  }
  else
  {
    stage_v_150_1 = ((pub_r000126_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
  }
  if ((stage_v_126_2 & 63) > 30)
  {
    stage_v_150_2 = ((pub_r000126_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  }
  else
  {
    stage_v_150_2 = ((pub_r000126_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = 0;
  int stage_v_151_2 = 0;
  if ((stage_v_149_1 & 63) > 48)
  {
    stage_v_151_1 = ((pub_r000126_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  }
  else
  {
    stage_v_151_1 = ((pub_r000126_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 9) & 255;
  }
  if ((stage_v_149_2 & 63) > 48)
  {
    stage_v_151_2 = ((pub_r000126_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  }
  else
  {
    stage_v_151_2 = ((pub_r000126_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  if ((stage_v_112_1 & 63) > 44)
  {
    stage_v_152_1 = ((pub_r000126_10_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  }
  else
  {
    stage_v_152_1 = ((pub_r000126_10_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 9) & 255;
  }
  if ((stage_v_112_2 & 63) > 44)
  {
    stage_v_152_2 = ((pub_r000126_10_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  }
  else
  {
    stage_v_152_2 = ((pub_r000126_10_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  if ((stage_v_104_1 & 63) > 58)
  {
    stage_v_153_1 = ((pub_r000126_6_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  }
  else
  {
    stage_v_153_1 = ((pub_r000126_6_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 9) & 255;
  }
  if ((stage_v_104_2 & 63) > 58)
  {
    stage_v_153_2 = ((pub_r000126_6_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  }
  else
  {
    stage_v_153_2 = ((pub_r000126_6_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = 0;
  int stage_v_154_2 = 0;
  if ((stage_v_129_1 & 63) > 19)
  {
    stage_v_154_1 = ((pub_r000126_9_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  }
  else
  {
    stage_v_154_1 = ((pub_r000126_9_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 9) & 255;
  }
  if ((stage_v_129_2 & 63) > 19)
  {
    stage_v_154_2 = ((pub_r000126_9_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  }
  else
  {
    stage_v_154_2 = ((pub_r000126_9_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  if ((sec_r000126_7_1 & 63) > 31)
  {
    stage_v_155_1 = ((pub_r000126_14_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  }
  else
  {
    stage_v_155_1 = ((pub_r000126_14_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 9) & 255;
  }
  if ((sec_r000126_7_2 & 63) > 31)
  {
    stage_v_155_2 = ((pub_r000126_14_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  }
  else
  {
    stage_v_155_2 = ((pub_r000126_14_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  if ((stage_v_128_1 & 63) > 34)
  {
    stage_v_156_1 = ((pub_r000126_21_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  }
  else
  {
    stage_v_156_1 = ((pub_r000126_21_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 9) & 255;
  }
  if ((stage_v_128_2 & 63) > 34)
  {
    stage_v_156_2 = ((pub_r000126_21_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  }
  else
  {
    stage_v_156_2 = ((pub_r000126_21_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  if ((stage_v_127_1 & 63) > 50)
  {
    stage_v_157_1 = ((pub_r000126_19_1 * 2) + 15) & 127;
    out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  }
  else
  {
    stage_v_157_1 = ((pub_r000126_19_1 * 3) + 23) & 127;
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 9) & 255;
  }
  if ((stage_v_127_2 & 63) > 50)
  {
    stage_v_157_2 = ((pub_r000126_19_2 * 2) + 15) & 127;
    out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  }
  else
  {
    stage_v_157_2 = ((pub_r000126_19_2 * 3) + 23) & 127;
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 9) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000126_19_1 == pub_r000126_19_2);
  __CPROVER_assume(sec_r000126_13_1 != sec_r000126_13_2);
  __CPROVER_assume(sec_r000126_3_1 != sec_r000126_3_2);
  __CPROVER_assume(pub_r000126_3_1 == pub_r000126_3_2);
  __CPROVER_assume(sec_r000126_9_1 != sec_r000126_9_2);
  __CPROVER_assume(pub_r000126_4_1 == pub_r000126_4_2);
  __CPROVER_assume(pub_r000126_9_1 == pub_r000126_9_2);
  __CPROVER_assume(pub_r000126_11_1 == pub_r000126_11_2);
  __CPROVER_assume(sec_r000126_0_1 != sec_r000126_0_2);
  __CPROVER_assume(sec_r000126_17_1 != sec_r000126_17_2);
  __CPROVER_assume(pub_r000126_10_1 == pub_r000126_10_2);
  __CPROVER_assume(pub_r000126_13_1 == pub_r000126_13_2);
  __CPROVER_assume(sec_r000126_2_1 != sec_r000126_2_2);
  __CPROVER_assume(sec_r000126_16_1 != sec_r000126_16_2);
  __CPROVER_assume(sec_r000126_8_1 != sec_r000126_8_2);
  __CPROVER_assume(sec_r000126_6_1 != sec_r000126_6_2);
  __CPROVER_assume(sec_r000126_1_1 != sec_r000126_1_2);
  __CPROVER_assume(pub_r000126_21_1 == pub_r000126_21_2);
  __CPROVER_assume(sec_r000126_14_1 != sec_r000126_14_2);
  __CPROVER_assume(pub_r000126_14_1 == pub_r000126_14_2);
  __CPROVER_assume(sec_r000126_5_1 != sec_r000126_5_2);
  __CPROVER_assume(sec_r000126_21_1 != sec_r000126_21_2);
  __CPROVER_assume(pub_r000126_16_1 == pub_r000126_16_2);
  __CPROVER_assume(sec_r000126_12_1 != sec_r000126_12_2);
  __CPROVER_assume(pub_r000126_0_1 == pub_r000126_0_2);
  __CPROVER_assume(sec_r000126_4_1 != sec_r000126_4_2);
  __CPROVER_assume(sec_r000126_11_1 != sec_r000126_11_2);
  __CPROVER_assume(pub_r000126_6_1 == pub_r000126_6_2);
  __CPROVER_assume(pub_r000126_1_1 == pub_r000126_1_2);
  __CPROVER_assume(sec_r000126_10_1 != sec_r000126_10_2);
  __CPROVER_assume(pub_r000126_7_1 == pub_r000126_7_2);
  __CPROVER_assume(pub_r000126_8_1 == pub_r000126_8_2);
  __CPROVER_assume(sec_r000126_15_1 != sec_r000126_15_2);
  __CPROVER_assume(pub_r000126_20_1 == pub_r000126_20_2);
  __CPROVER_assume(sec_r000126_18_1 != sec_r000126_18_2);
  __CPROVER_assume(pub_r000126_17_1 == pub_r000126_17_2);
  __CPROVER_assume(pub_r000126_12_1 == pub_r000126_12_2);
  __CPROVER_assume(pub_r000126_2_1 == pub_r000126_2_2);
  __CPROVER_assume(sec_r000126_19_1 != sec_r000126_19_2);
  __CPROVER_assume(sec_r000126_20_1 != sec_r000126_20_2);
  __CPROVER_assume(pub_r000126_5_1 == pub_r000126_5_2);
  __CPROVER_assume(pub_r000126_15_1 == pub_r000126_15_2);
  __CPROVER_assume(sec_r000126_7_1 != sec_r000126_7_2);
  __CPROVER_assume(pub_r000126_18_1 == pub_r000126_18_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.stop_bits == st_var_2_2.stop_bits);
  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  assert(st_var_2_1.id == st_var_2_2.id);
  assert(st_var_2_1.port == st_var_2_2.port);
  assert(st_var_2_1.parity == st_var_2_2.parity);
  assert(st_var_2_1.timeout == st_var_2_2.timeout);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.dim == st_var_3_2.dim);
  assert(st_var_3_1.density == st_var_3_2.density);
  assert(st_var_3_1.stride == st_var_3_2.stride);
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
}


